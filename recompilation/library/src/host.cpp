// The library's default host: every function the
// seam `runtime.h` declares, for a program that loads resources through the
// API (`resource.h`) rather than a test runner's, which supplies
// the same seam with its own forks, sanitizers and records.
// None of these reads a byte of a file the root loads: they hand the engine
// memory, record what the running entry reached, and open an inner
// resource's file.

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <memory>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "isolate.h"
#include "session.h"

namespace {

ddon::TrapHandler g_trap_handler = nullptr;
ddon::session::Entry* g_entry = nullptr;
bool g_set_up = false;
// Built on first use: a static initializer of another unit may reach a stub
// before this unit's own initializers run.
std::vector<std::string>& setup_stubs_list() {
    static std::vector<std::string> list;
    return list;
}
// The resources the manager's table holds: built for a request, less those a
// last release destroyed.
unsigned g_inner_alive = 0;

void add_once(std::vector<std::string>& list, const char* name) {
    if (std::find(list.begin(), list.end(), name) == list.end()) {
        list.emplace_back(name);
    }
}

}  // namespace

namespace ddon {

void set_trap_handler(TrapHandler handler) { g_trap_handler = handler; }

namespace session {

void set_up() {
    if (!g_set_up) {
        g_set_up = true;
        ddon_fixtures_init();
    }
}

void begin(Entry& entry) {
    if (g_entry != nullptr) {
        ddon_trap("ddon: a second load, save or destroy while one runs");
    }
    g_entry = &entry;
}

void end() { g_entry = nullptr; }

unsigned inner_alive() { return g_inner_alive; }

const std::vector<std::string>& stubs_before_any_entry() { return setup_stubs_list(); }

}  // namespace session
}  // namespace ddon

// A body the reconstruction refused was reached: the running entry's stub,
// or, before any, the set-up's (static initializers, the fixtures' engine
// bases).
extern "C" void ddon_stub_hit(const char* name) {
    add_once(g_entry != nullptr ? *g_entry->stubs : setup_stubs_list(), name);
}

// A body the bundle lacks, or a request the host has no answer for: nothing
// can unwind under -fno-exceptions, so the process ends through the handler.
extern "C" [[noreturn]] void ddon_trap(const char* name) {
    if (ddon::isolate::in_child()) {
        // An isolated inner load's trap is that load's wall, not the
        // caller's end.
        ddon::isolate::wall(name);
        std::_Exit(3);
    }
    if (g_trap_handler != nullptr) {
        g_trap_handler(name);
    }
    std::fprintf(stderr, "ddon: the load reached %s, which the reconstruction lacks\n", name);
    std::fflush(stdout);
    std::_Exit(3);
}

// The engine's heap, as the host's: each block keeps the pointer malloc
// returned and its size just before it, so no platform's aligned allocator or
// usable-size query is needed. New memory is filled with 0xbe, so a
// member no constructor sets reads as 0xbebebebe rather
// than as a plausible zero.
namespace {
struct Block {
    void* base;
    std::size_t size;
};

Block block_of(void* memory) {
    Block block{};
    std::memcpy(&block, static_cast<char*>(memory) - sizeof(Block), sizeof block);
    return block;
}
}  // namespace

// The library's loads keep no notes of their input (rArchive's host writer
// runs in the test runner only): no bytes.
const unsigned char* ddon_input_bytes(const MtStream*, std::size_t, std::size_t) { return nullptr; }

void ddon_note_kept_entry(const char*, std::size_t) {}

void* ddon_host_alloc(std::size_t size, std::size_t align) {
    if (align < alignof(Block)) {
        align = alignof(Block);
    }
    char* base = static_cast<char*>(std::malloc(size + align + sizeof(Block)));
    if (base == nullptr) {
        return nullptr;
    }
    std::uintptr_t start = reinterpret_cast<std::uintptr_t>(base) + sizeof(Block);
    char* memory = reinterpret_cast<char*>((start + align - 1) / align * align);
    Block block{base, size};
    std::memcpy(memory - sizeof(Block), &block, sizeof block);
    std::memset(memory, 0xbe, size);
    return memory;
}

void ddon_host_free(void* memory) {
    if (memory != nullptr) {
        std::free(block_of(memory).base);
    }
}

void* ddon_own_alloc(std::size_t size, std::size_t align) { return ddon_host_alloc(size, align); }

std::size_t ddon_host_size(void* memory) { return memory != nullptr ? block_of(memory).size : 0; }

// The library keeps nothing a load overwrites: a derived save that needs it refuses.
void ddon_keep_overwritten(const void*, unsigned) {}
bool ddon_overwritten(const void*, unsigned*) { return false; }
void ddon_keep_property(unsigned, unsigned, const char*, unsigned, bool) {}
void ddon_keep_value(const MtStream*, unsigned, unsigned, unsigned, unsigned) {}
bool ddon_put_back_skipped(MtStream&, const DdonPutBack&, unsigned) { return false; }

namespace {
// The game's live allocations, by start: what `sResource`'s
// release of a game-built resource may take.
// Built on first use, as the set-up's stubs: a static initializer may
// allocate.
std::unordered_set<std::uintptr_t>& game_allocations() {
    static std::unordered_set<std::uintptr_t> set;
    return set;
}
}  // namespace

void* ddon_game_alloc(std::size_t size, std::size_t align) {
    void* memory = ddon_host_alloc(size, align);
    if (memory != nullptr) {
        game_allocations().insert(reinterpret_cast<std::uintptr_t>(memory));
    }
    return memory;
}

void ddon_game_free(void* memory) {
    game_allocations().erase(reinterpret_cast<std::uintptr_t>(memory));
    ddon_host_free(memory);
}

bool ddon_game_allocated(const void* memory) {
    return game_allocations().count(reinterpret_cast<std::uintptr_t>(memory)) != 0;
}

std::size_t ddon_game_size(const void* memory) {
    return ddon_game_allocated(memory) ? ddon_host_size(const_cast<void*>(memory)) : 0;
}

// The library has no field dump.
void ddon_dump_append(const char*, std::size_t) {}

void ddon_inner_requested(const char* class_name, const char* path, const char* via, unsigned mode,
                          const char* outcome) {
    if (g_entry == nullptr) {
        return;
    }
    ddon::InnerRequest request;
    request.class_name = class_name != nullptr ? class_name : "";
    request.path = path != nullptr ? path : "";
    request.via = via != nullptr ? via : "";
    request.outcome = outcome != nullptr ? outcome : "";
    request.mode = mode;
    g_entry->inner->push_back(std::move(request));
}

void ddon_inner_created() { ++g_inner_alive; }

void ddon_inner_released() { --g_inner_alive; }

namespace {
// The library's part of an isolated trial (`isolate.h`): no alarm, and the
// child's stubs start empty; a trap in the child is its wall (`ddon_trap`).
class TrialHost final : public ddon::isolate::Host {
public:
    void enter_child(int) override { g_entry->stubs->clear(); }
    const char* first_stub() override {
        return g_entry->stubs->empty() ? nullptr : g_entry->stubs->front().c_str();
    }
};
}  // namespace

// An inner load's trial, by the entry's option. `in_place` runs no trial: the
// fixtures' rerun is the load, in this process, and what it reaches is the
// entry's. `placeholder` loads nothing: the placeholder, its reason
// the option. `isolate` runs it first in a child of its own
// (`isolate_posix.cpp`): a wall there gets the
// placeholder, and a clean one reruns here; `resource.cpp` answers
// `unsupported_option` first where the build cannot isolate.
DdonInnerTrial ddon_inner_trial(const DdonInnerKey& key, int (*attempt)(void*), void* context,
                                char* wall, std::size_t size) {
    if (g_entry != nullptr && g_entry->inner_loads == ddon::InnerLoads::isolate) {
        TrialHost host;
        return ddon::isolate::trial(key, attempt, context, wall, size, host);
    }
    if (g_entry != nullptr && g_entry->inner_loads == ddon::InnerLoads::in_place) {
        return DdonInnerTrial::loaded;
    }
    static const char why[] = "not loaded (option)";
    if (size != 0) {
        std::size_t n = std::min(size - 1, sizeof why - 1);
        std::memcpy(wall, why, n);
        wall[n] = 0;
    }
    return DdonInnerTrial::wall;
}

int ddon_inner_rerun(int (*rerun)(void* context), void* context) {
    return ddon::isolate::rerun(rerun, context);
}

namespace {
// An inner resource's file, read whole: its bytes and the stream over them.
struct InnerFile {
    std::vector<unsigned char> bytes;
    ddon::MemoryStream stream{bytes, false};
};
std::vector<std::unique_ptr<InnerFile>> g_inner_files;
}  // namespace

// `<archive dir>/<path>.<ext>` (the ELF's `sResource::loadBlocking`,
// 0x126dfb0: `<root>\<path>.<ext>`), backslashes as slashes; null when the
// entry has no archive directory or the file is not there.
MtStream* ddon_inner_file(const char* path, const char* ext, bool*) {
    if (g_entry == nullptr || g_entry->archive_dir.empty() || path == nullptr || ext == nullptr ||
        *ext == 0) {
        return nullptr;
    }
    std::string wanted = g_entry->archive_dir + path + "." + ext;
    std::replace(wanted.begin(), wanted.end(), '\\', '/');
    std::ifstream in(wanted, std::ios::binary);
    if (!in) {
        return nullptr;
    }
    auto file = std::make_unique<InnerFile>();
    file->bytes.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
    g_inner_files.push_back(std::move(file));
    return &g_inner_files.back()->stream;
}

// The library translates no file: an archive's entry is read as it is.
bool ddon_entry_translated(const char*) { return false; }
MtStream* ddon_entry_image(const void*, std::size_t, const char*) { return nullptr; }

void ddon_inner_file_close(MtStream* stream) {
    auto at = std::find_if(
        g_inner_files.begin(), g_inner_files.end(),
        [&](const std::unique_ptr<InnerFile>& file) { return &file->stream == stream; });
    if (at != g_inner_files.end()) {
        g_inner_files.erase(at);
    }
}
