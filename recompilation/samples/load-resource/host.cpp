// The host services the library and the fixtures call (runtime.h, and the
// PS4 SDK functions the units call, host/sdk): what the engine and the
// console would give a resource while it loads. None of them reads a byte
// of the file.

#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include "runtime.h"

#include <_kernel.h>
#include <_pthread.h>
#include <net.h>
#include <ymath.h>

// What a root's field dump wrote (main.cpp prints it).
std::string ddon_sample_dump;

void ddon_dump_append(const char* text, std::size_t size) { ddon_sample_dump.append(text, size); }

// A load reached a function the reconstruction does not have (traps.cpp,
// generated at build time, names every one): the load cannot go on.
extern "C" [[noreturn]] void ddon_trap(const char* name) {
    std::fprintf(stderr, "load-resource: the load reached %s, which the reconstruction lacks\n", name);
    std::fflush(stdout);
    std::_Exit(3);
}

// The engine's heap, as the host's: each block keeps its size and the
// pointer malloc returned just before it. New memory is filled with 0xbe,
// as the harness does, so a member no constructor sets reads as 0xbebebebe
// rather than as a plausible zero.
namespace {
struct Block {
    void* base;
    std::size_t size;
};
}  // namespace

void* ddon_host_alloc(std::size_t size, std::size_t align) {
    if (align < alignof(Block)) {
        align = alignof(Block);
    }
    char* base = static_cast<char*>(std::malloc(size + align + sizeof(Block)));
    if (!base) {
        return nullptr;
    }
    std::uintptr_t start = reinterpret_cast<std::uintptr_t>(base) + sizeof(Block);
    char* memory = reinterpret_cast<char*>((start + align - 1) / align * align);
    Block block{base, size};
    std::memcpy(memory - sizeof(Block), &block, sizeof block);
    std::memset(memory, 0xbe, size);
    return memory;
}

static Block block_of(void* memory) {
    Block block{};
    std::memcpy(&block, static_cast<char*>(memory) - sizeof(Block), sizeof block);
    return block;
}

void ddon_host_free(void* memory) {
    if (memory) {
        std::free(block_of(memory).base);
    }
}

std::size_t ddon_host_size(void* memory) { return memory ? block_of(memory).size : 0; }

// A sub-resource the file names (a texture, a model) is another file: the
// fixtures' resource manager hands the load an empty instance of its class
// instead, and says so here.
void ddon_placeholder_created(const char* class_name, const char* path, unsigned mode) {
    std::fprintf(stderr, "load-resource: sub-resource %s %s (mode %u): an empty placeholder\n",
                 class_name ? class_name : "(unknown class)", path ? path : "", mode);
}

void ddon_placeholder_released() {}

// The PS4 SDK's functions the units call. One thread runs, so a mutex never
// waits.
extern "C" int scePthreadMutexLock(pthread_mutex**) { return 0; }
extern "C" int scePthreadMutexUnlock(pthread_mutex**) { return 0; }

// The time-stamp counter as a monotonic clock in nanoseconds.
extern "C" uint64_t sceKernelReadTsc(void) {
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(now).count());
}
extern "C" uint64_t sceKernelGetTscFrequency(void) { return 1000000000u; }

extern "C" int sceNetSocketClose(int) { return 0; }

// The SDK's math primitives, for the arguments the units pass: `_FLog(x, 0)`
// is the natural log and `_FLog(x, 1)` log10; `_FSin(x, 0, 0)` is sin and
// `_FSin(x, 1, 0)` cos.
extern "C" float _FLog(float x, int base) {
    if (base == 0) {
        return std::log(x);
    }
    if (base == 1) {
        return std::log10(x);
    }
    ddon_trap("_FLog(float, int) with a base other than 0 or 1");
}
extern "C" float _FSin(float x, unsigned int qoff, int quads) {
    if (qoff == 0 && quads == 0) {
        return std::sin(x);
    }
    if (qoff == 1 && quads == 0) {
        return std::cos(x);
    }
    ddon_trap("_FSin(float, unsigned int, int) with other than (x, 0, 0) or (x, 1, 0)");
}
