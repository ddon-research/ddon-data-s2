// The harness's host stand-in for the PS4 SDK's `<sce_atomic.h>` (026
// P127b): only what the units call, spelled as SDK 2.500's
// `sce_atomic/sce_atomic_orbis.h` does. It is a static inline function
// there, defined by clang's own builtin, so it is defined here the same way.
#pragma once

#include <stdint.h>

static inline int32_t sceAtomicAdd32Relaxed(volatile int32_t* ptr, int32_t value)
{
    return __atomic_fetch_add(ptr, value, __ATOMIC_RELAXED);
}
