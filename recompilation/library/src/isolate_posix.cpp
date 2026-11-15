// An inner load's isolation by `fork` (`isolate.h`): the trial's fork and
// the rerun's replay of its verdicts. The harness compiles it inside
// `runtime.cpp`, the library beside `host.cpp`; a Windows build takes
// `isolate_other.cpp` instead.
#if !defined(_WIN32)

#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <utility>
#include <vector>

#include "isolate.h"

namespace {

// One request's verdict, by its key (`key_text`), and its wall's text.
struct Verdict {
    std::string key;
    DdonInnerTrial result;
    std::string wall;
};

// In a trial's child: the pipe to its parent, else -1, and every verdict its
// requests got, in order, encoded for that parent (`encode`).
int g_child_out = -1;
std::string g_child_verdicts;
// The verdicts a clean trial's child sent back, which its rerun takes in
// order, and the rerun depth (`rerun`) whose end discards them; `kNoReplay`
// when none is armed.
constexpr unsigned kNoReplay = ~0u;
std::vector<Verdict> g_replay;
std::size_t g_replayed = 0;
unsigned g_replay_owner = kNoReplay;
unsigned g_rerun_depth = 0;

void disarm() {
    g_replay.clear();
    g_replayed = 0;
    g_replay_owner = kNoReplay;
}

std::string key_text(const DdonInnerKey& key) {
    std::string text = key.class_name ? key.class_name : "";
    text += '\n';
    text += key.path ? key.path : "";
    text += '\n';
    text += key.via ? key.via : "";
    text += '\n' + std::to_string(key.mode);
    return text;
}

// `<result> <key length> <wall length>\n<key><wall>`.
void encode(std::string& out, const Verdict& verdict) {
    out += std::to_string(static_cast<int>(verdict.result)) + " " + std::to_string(verdict.key.size())
           + " " + std::to_string(verdict.wall.size()) + "\n";
    out += verdict.key;
    out += verdict.wall;
}

// The verdicts after a clean child's `T<code>\n`; any text that does not
// parse whole arms none, so every request of the rerun runs its own trial.
std::vector<Verdict> decode(const std::string& text) {
    std::vector<Verdict> verdicts;
    std::size_t at = 0;
    while (at < text.size()) {
        unsigned result = 0;
        unsigned long long key = 0;
        unsigned long long wall = 0;
        int used = 0;
        if (std::sscanf(text.c_str() + at, "%u %llu %llu\n%n", &result, &key, &wall, &used) != 3
            || used <= 0 || result > static_cast<unsigned>(DdonInnerTrial::wall)) {
            return {};
        }
        at += static_cast<std::size_t>(used);
        if (key > text.size() - at || wall > text.size() - at - key) {
            return {};
        }
        verdicts.push_back(Verdict{text.substr(at, key), static_cast<DdonInnerTrial>(result),
                                   text.substr(at + key, wall)});
        at += key + wall;
    }
    return verdicts;
}

std::string copy_wall(const std::string& text, char* wall, std::size_t size) {
    std::size_t n = size ? std::min(text.size(), size - 1) : 0;
    if (size) {
        std::memcpy(wall, text.data(), n);
        wall[n] = 0;
    }
    return text.substr(0, n);
}

void write_all(int fd, const std::string& line) {
    std::size_t done = 0;
    while (done < line.size()) {
        ssize_t n = ::write(fd, line.data() + done, line.size() - done);
        if (n <= 0) {
            break;
        }
        done += static_cast<std::size_t>(n);
    }
}

// The child writes `T<code>` at its end, followed by its requests' verdicts,
// or `W<wall>` at a wall. Nothing the child records reaches the caller but
// that one line. A clean child's verdicts go into `replay`.
DdonInnerTrial forked(int (*attempt)(void* context), void* context, char* wall, std::size_t size,
                      std::vector<Verdict>& replay, ddon::isolate::Host& host) {
    auto copy = [&](const std::string& text) {
        copy_wall(text, wall, size);
        return DdonInnerTrial::wall;
    };
    int fds[2];
    if (::pipe(fds) != 0) {
        return copy("pipe");
    }
    host.before_fork();
    std::fflush(stdout);
    pid_t pid = ::fork();
    if (pid == 0) {
        ::close(fds[0]);
        g_child_out = fds[1];
        host.enter_child(fds[1]);
        g_child_verdicts.clear();
        disarm();
        int code = attempt(context);
        std::string line;
        if (const char* stub = host.first_stub()) {
            line = "Wstub ";
            line += stub;
        } else {
            line = "T" + std::to_string(code);
            if (!g_child_verdicts.empty()) {
                line += '\n' + g_child_verdicts;
            }
        }
        write_all(g_child_out, line);
        std::_Exit(0);
    }
    ::close(fds[1]);
    std::string got;
    char buffer[4096];
    for (ssize_t n; (n = ::read(fds[0], buffer, sizeof buffer)) > 0;) {
        got.append(buffer, static_cast<std::size_t>(n));
    }
    ::close(fds[0]);
    int status = 0;
    ::waitpid(pid, &status, 0);
    host.after_child();
    if (got.size() >= 2 && got[0] == 'T' && got[1] >= '0' && got[1] <= '2'
        && (got.size() == 2 || got[2] == '\n')) {
        if (got[1] == '2') {
            return DdonInnerTrial::no_file;
        }
        if (got.size() > 2) {
            replay = decode(got.substr(3));
        }
        return got[1] == '0' ? DdonInnerTrial::loaded : DdonInnerTrial::refused;
    }
    if (!got.empty() && got[0] == 'W') {
        return copy(got.substr(1));
    }
    return copy(WIFSIGNALED(status) ? "crash: signal " + std::to_string(WTERMSIG(status))
                                    : "crash: exit " + std::to_string(WEXITSTATUS(status)));
}

}  // namespace

namespace ddon {
namespace isolate {

bool supported() { return true; }

DdonInnerTrial trial(const DdonInnerKey& key, int (*attempt)(void* context), void* context,
                     char* wall, std::size_t size, Host& host) {
    Verdict verdict{key_text(key), DdonInnerTrial::wall, std::string()};
    if (g_replayed < g_replay.size() && g_replay[g_replayed].key == verdict.key) {
        // The rerun asks what its trial's child asked, in order: that
        // child's verdict.
        const Verdict& replayed = g_replay[g_replayed++];
        verdict.result = replayed.result;
        if (verdict.result == DdonInnerTrial::wall) {
            verdict.wall = copy_wall(replayed.wall, wall, size);
        }
    } else {
        // No rerun, or one that no longer asks what its trial asked: from
        // here on every request runs its own trial.
        disarm();
        std::vector<Verdict> replay;
        verdict.result = forked(attempt, context, wall, size, replay, host);
        if (verdict.result == DdonInnerTrial::wall) {
            verdict.wall = copy_wall(std::string(wall), wall, size);
        }
        if (!replay.empty()) {
            g_replay = std::move(replay);
            g_replay_owner = g_rerun_depth;
        }
    }
    if (in_child()) {
        encode(g_child_verdicts, verdict);
    }
    return verdict.result;
}

int rerun(int (*rerun)(void* context), void* context) {
    ++g_rerun_depth;
    int code = rerun(context);
    --g_rerun_depth;
    if (g_replay_owner == g_rerun_depth) {
        // The rerun that took these verdicts ended: none outlives it.
        disarm();
    }
    return code;
}

bool in_child() { return g_child_out >= 0; }

void wall(const char* text) {
    if (in_child()) {
        std::string line = "W";
        line += text;
        write_all(g_child_out, line);
    }
}

}  // namespace isolate
}  // namespace ddon

#endif  // !defined(_WIN32)
