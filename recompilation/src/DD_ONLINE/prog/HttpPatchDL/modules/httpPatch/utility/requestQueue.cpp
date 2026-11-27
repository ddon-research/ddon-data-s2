// Reconstructed from the game's DWARF debug information.
#include <new>
#include <kernel.h>
#include "requestQueue.h"
#include "../HttpPatchManager.h"
#include "../../../../../../MT/MtCollisionUtil.h"
#include "../../../../../../MT/MtObject.h"
#include "../../../../../../MT/MtString.h"
#include "../../../../../../MT/MtSynchronize.h"
#include "../../../../../../MT/MtThread.h"
#include "../../../xvia/atomic.h"
#include "../httpPatch.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((noinline)) via::Request::~Request() {
    DDON_STUB("via::Request::~Request")
    /* stub */
}

void via::Request::exit() {
    if (mExit) {
        return;
    }
    mExit = true;
    request();
    if (mThreadHandle == nullptr) {
        return;
    }
    mThreadHandle->terminate();
    if (mThreadHandle == nullptr) {
        return;
    }
    delete mThreadHandle;
    mThreadHandle = nullptr;
}

__attribute__((weak)) bool via::Request::resume(MtObject* object, via::Request::RequestCallback callback, MT_CTSTR thread_name, void* argument_ptr) {
    DDON_STUB("via::Request::resume")
    return {};
}

void via::Request::request() {
    ::sceKernelSignalSema(mSemaphore.mHandle, 1);
    ::via::Atomic::inc(&mCount);
}

void via::Request::requestWait() {
    ::sceKernelWaitSema(mSemaphore.mHandle, 1, static_cast<SceKernelUseconds*>(nullptr));
}

__attribute__((weak)) void via::Request::requestLoop(void* param_ptr) {
    DDON_STUB("via::Request::requestLoop")
    /* stub */
}

__attribute__((weak)) bool via::Request::resume(MT_CTSTR thread_name, void* argument_ptr) {
    DDON_STUB("via::Request::resume")
    return {};
}

