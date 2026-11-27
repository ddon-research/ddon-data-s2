// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <kernel.h>
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

void nWin32Detour::waitForSingleObject(nWin32Detour::eventFlag& cs) {
    sceKernelWaitEventFlag(cs.mEventFlag, 1ul, 17u, static_cast<uint64_t*>(nullptr), static_cast<SceKernelUseconds*>(nullptr));
}

void nWin32Detour::setEvent(nWin32Detour::eventFlag& cs) {
    sceKernelSetEventFlag(cs.mEventFlag, 1ul);
}

nWin32Detour::eventFlag::eventFlag() {
    DDON_STUB("nWin32Detour::eventFlag::eventFlag")
    /* stub */
}

nWin32Detour::eventFlag::~eventFlag() {
    ::sceKernelDeleteEventFlag(mEventFlag);
}

