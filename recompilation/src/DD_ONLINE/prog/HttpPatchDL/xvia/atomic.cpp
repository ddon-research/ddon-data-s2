// Reconstructed from the game's DWARF debug information.
#include <new>
#include <sce_atomic.h>
#include "atomic.h"
#include "../../../../MT/MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

s32 via::Atomic::inc(volatile s32* addend) {
    return ::sceAtomicAdd32Relaxed(addend, 1) + 1;
}

s32 via::Atomic::dec(volatile s32* addend) {
    return ::sceAtomicAdd32Relaxed(addend, -1) - 1;
}

via_atomic_bool::~via_atomic_bool() {
    DDON_STUB("via_atomic_bool::~via_atomic_bool")
    /* stub */
}

