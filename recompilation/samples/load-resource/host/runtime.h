// The deserialization harness's runtime interface (024 T804). A generated
// driver names one root and how to construct, load, save and destroy it;
// the runtime runs it over files, one forked child per file.
#pragma once

#include <cstddef>

class MtStream;

struct DdonRoot {
    const char* name;
    void* (*create)();
    bool (*load)(void* root, MtStream& in);
    // The root's own `save` (024 T984), run after a `load` that returned
    // true, into a fresh output stream whose bytes are compared with the
    // file. Null when the root's virtual `save` is `cResource::save` (the
    // bundle's `load-save.json`, from DWARF): the file reports `no own save`.
    bool (*save)(void* root, MtStream& out);
    void (*destroy)(void* root);
    // The field dump (024 T991), after a `load` that returned true and its
    // save, before destroy: it hands the runtime its JSON through
    // `ddon_dump_append`. Null when the driver has none.
    void (*dump)(void* root);
    // The derived save (031 R11-D, plan-Z3b): a save written by inverting the
    // root's load, never the game's code. Run after `save`, in a child of its
    // own, into a second fresh output stream; its result is recorded apart
    // (`derived_*`) and changes nothing the game's own save or the load
    // reports. Null when the bundle has none for the root.
    bool (*derived_save)(void* root, MtStream& out);
};

// Appends to the file's field dump (024 T991, `dump.h`).
void ddon_dump_append(const char* text, std::size_t size);

// The inner resources (constitution 2.14.0, 031 R12-G, `fixtures.cpp`): a
// request the host's `sResource` answered goes into the file's record as a
// note, `{"class","path","via","mode","outcome"}`; no outcome of the file
// reads it.
void ddon_inner_requested(const char* class_name, const char* path, const char* via, unsigned mode,
                          const char* outcome);
// Counts one instance the host built for a request (loaded or not), and one
// destroyed by its last release.
void ddon_inner_created();
void ddon_inner_released();

// How an inner load's trial ended: its load ran clean and returned true, ran
// clean and returned false, found no file, or met a wall (a stub reached, a
// trap, a crash), whose text `ddon_inner_trial` copies out.
enum class DdonInnerTrial { loaded, refused, no_file, wall };
// Runs `attempt(context)` in a child of its own, as the derived save runs:
// whatever it reaches stays there. `attempt` returns 0 (loaded), 1 (refused)
// or 2 (no file).
DdonInnerTrial ddon_inner_trial(int (*attempt)(void* context), void* context, char* wall,
                                std::size_t size);
// A dependent resource's file (the ELF's `sResource::loadBlocking`, 0x126dfb0:
// `<root>\<path>.<ext>`): `<path>.<ext>` beside the root's own file, under
// its archive's directory, as a read-only stream; null when the corpus holds
// none there. Closed by `ddon_inner_file_close`.
MtStream* ddon_inner_file(const char* path, const char* ext);
void ddon_inner_file_close(MtStream* stream);

// Storage for a root, from the host (not the engine's allocator).
void* ddon_host_alloc(std::size_t size, std::size_t align);
void ddon_host_free(void* memory);
std::size_t ddon_host_size(void* memory);
// The engine's allocators' storage (`fixtures.cpp`), each block known while it
// lives: what the game itself allocated, by its start (031 plan-S53b).
void* ddon_game_alloc(std::size_t size, std::size_t align);
void ddon_game_free(void* memory);
bool ddon_game_allocated(const void* memory);

// A body that does not exist in the bundle was reached: the run of this
// file ends here (generated traps call it).
extern "C" [[noreturn]] void ddon_trap(const char* name);

// Engine services the fixtures provide, set up before any file runs.
void ddon_fixtures_init();

// `place_path` gives a constructed root its file's game path, before `load`
// (031 plan-S49b): a list line is `<file>\t<game path>`; a line with no tab,
// or no `place_path`, gives none.
int ddon_harness_main(int argc, char** argv, const DdonRoot& root,
                      void (*place_path)(void* root, const char* path) = nullptr);
