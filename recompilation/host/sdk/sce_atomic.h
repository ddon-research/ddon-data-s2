// The harness's host stand-in for the PS4 SDK's `<sce_atomic.h>`: only
// what the units call, spelled as SDK 2.500's
// `sce_atomic/sce_atomic_orbis.h` does. It is a static inline function
// there, defined by clang's own builtin, so it is defined here the same way.
#pragma once

#include <stdint.h>

static inline int32_t sceAtomicAdd32Relaxed(volatile int32_t* ptr, int32_t value)
{
    return __atomic_fetch_add(ptr, value, __ATOMIC_RELAXED);
}

// `sce_atomic/sce_atomic_acqrel.h`'s default (no `_SCE_ATOMIC_DEFAULT_ACQREL`):
// `sceAtomicDecrement32Relaxed`, which is the add of -1. It returns the old
// value, which `MtString::release` compares with 1.
static inline int32_t sceAtomicDecrement32(volatile int32_t* ptr)
{
    return sceAtomicAdd32Relaxed(ptr, -1);
}

// The add of 1, for `MtString`'s copy constructor.
static inline int32_t sceAtomicIncrement32(volatile int32_t* ptr)
{
    return sceAtomicAdd32Relaxed(ptr, 1);
}

static inline int32_t sceAtomicCompareAndSwap32Relaxed(volatile int32_t* ptr, int32_t compare, int32_t swap)
{
    __atomic_compare_exchange_n(ptr, &compare, swap, false, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    return compare;
}

// The default again, for `nDraw::Resource::release`: the old
// value, which equals `compare` when it swapped.
static inline int32_t sceAtomicCompareAndSwap32(volatile int32_t* ptr, int32_t compare, int32_t swap)
{
    return sceAtomicCompareAndSwap32Relaxed(ptr, compare, swap);
}
