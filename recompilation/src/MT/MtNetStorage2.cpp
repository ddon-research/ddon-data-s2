// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "MtNetStorage2.h"
#include "MtNetBuffer.h"
#include "MtNetObject.h"
#include "MtNetRequest.h"
#include "MtSynchronize.h"
#include "MtTime.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void MtNetStorage2::addListener(MtNetStorage2::Listener* listener) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        mpListener = listener;
        if (mIsThreadSafe) {
            mLockCount = t0;
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    } else {
        mpListener = listener;
    }
}

void MtNetStorage2::removeListener(MtNetStorage2::Listener* listener) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        mpListener = nullptr;
        if (mIsThreadSafe) {
            mLockCount = t0;
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    } else {
        mpListener = nullptr;
    }
}

__attribute__((weak)) void MtNetStorage2::reqFinalize(u32* req_seq) {
    DDON_STUB("MtNetStorage2::reqFinalize")
    /* stub */
}

void MtNetStorage2::abortRequest(u32 req_seq) {
    mRequestController.abort(req_seq);
}

__attribute__((weak)) void MtNetStorage2::Listener::onNtcDestruct() {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsGetListSucceed(u32 req_seq, MtNetStorageList* storage_list) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsGetListFail(u32 req_seq, MtNetError* net_err) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsUnlinkSucceed(u32 req_seq) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsUnlinkFail(u32 req_seq, MtNetError* net_err) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsOpenSucceed(u32 req_seq) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsOpenFail(u32 req_seq, MtNetError* net_err) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsWriteSucceed(u32 req_seq) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsWriteFail(u32 req_seq, MtNetError* net_err) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsReadSucceed(u32 req_seq, s32 data_size) {
}

__attribute__((weak)) void MtNetStorage2::Listener::onAnsReadFail(u32 req_seq, MtNetError* net_err) {
}

MtNetStorageInfo& MtNetStorageInfo::operator=(const MtNetStorageInfo& info) {
    memcpy(static_cast<void*>(&mFileName[0]), static_cast<const void*>(&info.mFileName[0]), 256ul);
    if (info.mUniqueId.isValid()) {
        mUniqueId = info.mUniqueId;
    }
    mLastModified.mTime = info.mLastModified.mTime;
    mSlotNo = info.mSlotNo;
    return *this;
}

