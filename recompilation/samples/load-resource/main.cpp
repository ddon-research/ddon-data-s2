// load-resource: loads one resource file of the game with the reconstructed
// library, the way the engine does, through the load/save library's API
// (library/include/ddon/resource.h).
//
//   load-resource <root class> <file> [options]
//   load-resource <root class> --list <file of paths> [options]
//
// The library opens the file as an MtStream, creates the resource class
// through its MtDTI (the class registry's descriptor), and calls the
// resource's own virtual `load`. Every byte it interprets is interpreted by
// the reconstructed `load`, never by code here.

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

#include "ddon/resource.h"

namespace {

struct Options {
    ddon::LoadOptions load;
    const char* save_path = nullptr;
    const char* list = nullptr;
    // The file a trap names: the one loading when it happened.
    const char* current = nullptr;
};

Options g_options;

int usage(const char* program) {
    std::fprintf(stderr,
                 "usage: %s <root class> <file> [--data <rom>] [--game-path <path>]\n"
                 "       [--inner in-place|placeholder|isolate] [--save <out>]\n"
                 "   or: %s <root class> --list <file of paths> [--data <rom>] [--inner ...]\n"
                 "roots:",
                 program, program);
    for (const char* const* root = ddon::roots(); *root != nullptr; ++root) {
        std::fprintf(stderr, " %s", *root);
    }
    std::fprintf(stderr, "\n");
    return 2;
}

// A function the reconstruction lacks was reached (cmake/traps.cmake writes
// one for each): nothing can unwind, so the program ends here, naming it.
[[noreturn]] void on_trap(const char* name) {
    std::fflush(stdout);
    std::fprintf(stderr, "load-resource: %s: the load reached %s, which the reconstruction lacks\n",
                 g_options.current != nullptr ? g_options.current : "(no file)", name);
    std::_Exit(3);
}

bool read_file(const char* path, std::vector<unsigned char>& bytes) {
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        return false;
    }
    bytes.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
    return true;
}

bool write_file(const char* path, const std::vector<unsigned char>& bytes) {
    std::ofstream out(path, std::ios::binary);
    out.write(reinterpret_cast<const char*>(bytes.data()),
              static_cast<std::streamsize>(bytes.size()));
    return static_cast<bool>(out);
}

// The save's bytes against the file's.
std::string compare(const std::vector<unsigned char>& file,
                    const std::vector<unsigned char>& saved) {
    std::size_t n = file.size() < saved.size() ? file.size() : saved.size();
    for (std::size_t at = 0; at < n; ++at) {
        if (file[at] != saved[at]) {
            char text[64];
            std::snprintf(text, sizeof text, "first difference at 0x%zx", at);
            return text;
        }
    }
    if (file.size() != saved.size()) {
        char text[96];
        std::snprintf(text, sizeof text, "%zu bytes, the file %zu", saved.size(), file.size());
        return text;
    }
    return "round trip ok";
}

const char* route_name(ddon::SaveRoute route) {
    return route == ddon::SaveRoute::own ? "own" : "derived";
}

// One file loaded, with what it reached; with `--save`, saved and compared.
// Returns 0 for a whole load (and a round trip, when saving), else 1.
int run_one(const char* root, const char* path, const ddon::LoadOptions& load,
            const char* save_path) {
    g_options.current = path;
    ddon::LoadResult result = ddon::load_file(root, path, load);
    std::printf("%s: %s, read %u of %u bytes\n", root, ddon::status_name(result.status),
                static_cast<unsigned>(result.consumed), static_cast<unsigned>(result.size));
    for (const std::string& stub : result.stubs) {
        std::printf("  stub reached: %s\n", stub.c_str());
    }
    for (const ddon::InnerRequest& inner : result.inner) {
        std::printf("  inner %s %s (%s, mode %u): %s\n", inner.class_name.c_str(),
                    inner.path.c_str(), inner.via.c_str(), inner.mode, inner.outcome.c_str());
    }
    if (result.status != ddon::Status::ok) {
        return 1;
    }
    int code = 0;
    if (save_path != nullptr) {
        ddon::SaveResult saved = ddon::save(result.resource);
        std::printf("save (%s): %s, %zu bytes", route_name(saved.route),
                    ddon::status_name(saved.status), saved.bytes.size());
        for (const std::string& stub : saved.stubs) {
            std::printf("\n  stub reached: %s", stub.c_str());
        }
        if (saved.status == ddon::Status::ok) {
            std::vector<unsigned char> file;
            std::string verdict =
                read_file(path, file) ? compare(file, saved.bytes) : "the file is unreadable";
            bool written = write_file(save_path, saved.bytes);
            std::printf(" to %s: %s%s\n", save_path, verdict.c_str(),
                        written ? "" : " (could not write it)");
            code = verdict == "round trip ok" && written ? 0 : 1;
        } else {
            std::printf("\n");
            code = 1;
        }
    }
    unsigned left = ddon::destroy(std::move(result.resource));
    if (left != 0) {
        std::printf("  %u inner resources left after destroy\n", left);
    }
    return code;
}

// `--list`: each line a file, one result line each; the exit code is the
// worst (a trap still ends the program, naming the file).
int run_list(const char* root, const char* list, const ddon::LoadOptions& load) {
    std::ifstream in(list);
    if (!in) {
        std::fprintf(stderr, "load-resource: cannot read %s\n", list);
        return 2;
    }
    int worst = 0;
    for (std::string line; std::getline(in, line);) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (line.empty()) {
            continue;
        }
        g_options.current = line.c_str();
        ddon::LoadResult result = ddon::load_file(root, line.c_str(), load);
        std::printf("%s\t%s", ddon::status_name(result.status), line.c_str());
        for (const std::string& stub : result.stubs) {
            std::printf("\t%s", stub.c_str());
        }
        std::printf("\n");
        std::fflush(stdout);
        if (result.status != ddon::Status::ok) {
            worst = 1;
        } else {
            ddon::destroy(std::move(result.resource));
        }
    }
    return worst;
}

}  // namespace

int main(int argc, char** argv) {
    if (argc < 3) {
        return usage(argv[0]);
    }
    ddon::set_trap_handler(on_trap);
    const char* root = argv[1];
    const char* file = nullptr;
    // This program's default: the library's own, `isolate`, where the host
    // can fork; `in_place` on Windows, which cannot.
#if defined(_WIN32)
    g_options.load.inner = ddon::InnerLoads::in_place;
#else
    g_options.load.inner = ddon::InnerLoads::isolate;
#endif
    for (int i = 2; i < argc; ++i) {
        const char* arg = argv[i];
        bool has_value = i + 1 < argc;
        if (std::strcmp(arg, "--save") == 0 && has_value) {
            g_options.save_path = argv[++i];
        } else if (std::strcmp(arg, "--data") == 0 && has_value) {
            g_options.load.data_root = argv[++i];
        } else if (std::strcmp(arg, "--game-path") == 0 && has_value) {
            g_options.load.game_path = argv[++i];
        } else if (std::strcmp(arg, "--list") == 0 && has_value) {
            g_options.list = argv[++i];
        } else if (std::strcmp(arg, "--inner") == 0 && has_value) {
            const char* mode = argv[++i];
            if (std::strcmp(mode, "in-place") == 0) {
                g_options.load.inner = ddon::InnerLoads::in_place;
            } else if (std::strcmp(mode, "placeholder") == 0) {
                g_options.load.inner = ddon::InnerLoads::placeholder;
            } else if (std::strcmp(mode, "isolate") == 0) {
                g_options.load.inner = ddon::InnerLoads::isolate;
            } else {
                return usage(argv[0]);
            }
        } else if (file == nullptr && i == 2 && arg[0] != '-') {
            file = arg;
        } else {
            return usage(argv[0]);
        }
    }
    bool known = false;
    for (const char* const* name = ddon::roots(); *name != nullptr; ++name) {
        known |= std::strcmp(*name, root) == 0;
    }
    if (!known) {
        std::fprintf(stderr, "load-resource: no root named %s\n", root);
        return usage(argv[0]);
    }
    for (const std::string& stub : ddon::setup_stubs()) {
        std::printf("set-up reached: %s\n", stub.c_str());
    }
    if (g_options.list != nullptr) {
        return file == nullptr ? run_list(root, g_options.list, g_options.load) : usage(argv[0]);
    }
    if (file == nullptr) {
        return usage(argv[0]);
    }
    return run_one(root, file, g_options.load, g_options.save_path);
}
