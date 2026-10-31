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
};

// Appends to the file's field dump (024 T991, `dump.h`).
void ddon_dump_append(const char* text, std::size_t size);

// Records one sub-resource placeholder the host's `sResource` constructed
// (constitution 2.7.0, `fixtures.cpp`): the requested class, its path and
// mode go into the file's record.
void ddon_placeholder_created(const char* class_name, const char* path, unsigned mode);
// Records one placeholder destroyed by its last release.
void ddon_placeholder_released();

// Storage for a root, from the host (not the engine's allocator).
void* ddon_host_alloc(std::size_t size, std::size_t align);
void ddon_host_free(void* memory);
std::size_t ddon_host_size(void* memory);

// A body that does not exist in the bundle was reached: the run of this
// file ends here (generated traps call it).
extern "C" [[noreturn]] void ddon_trap(const char* name);

// Engine services the fixtures provide, set up before any file runs.
void ddon_fixtures_init();

int ddon_harness_main(int argc, char** argv, const DdonRoot& root);
