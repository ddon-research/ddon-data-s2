// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtCriticalSection::MtCriticalSection() {
    ScePthreadMutexattr attr;
    int ret;
    ret = scePthreadMutexattrInit(&attr);
    if (ret != 0) {
        abort();
    }
    ret = scePthreadMutexattrSettype(&attr, 2);
    if (ret != 0) {
        abort();
    }
    ret = scePthreadMutexInit(&mCSection, &attr, nullptr);
    if (ret != 0) {
        abort();
    }
    ret = scePthreadMutexattrDestroy(&attr);
    if (ret != 0) {
        abort();
    }
}

__attribute__((noinline)) MtCriticalSection::~MtCriticalSection() {
    if (scePthreadMutexDestroy(&mCSection) != 0) {
        abort();
    }
}

nWin32Detour::eventFlag::eventFlag() {
    DDON_STUB("nWin32Detour::eventFlag::eventFlag")
    /* stub */
}

nWin32Detour::eventFlag::~eventFlag() {
    DDON_STUB("nWin32Detour::eventFlag::~eventFlag")
    /* stub */
}

