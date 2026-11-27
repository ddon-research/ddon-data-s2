// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "MtNetContext.h"
#include "MtNetCore.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtNetRequest.h"
#include "MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtNetContext::MtNetContext(s32 user_index) {
    DDON_STUB("MtNetContext::MtNetContext")
    /* stub */
}

__attribute__((noinline)) MtNetContext::~MtNetContext() {
    DDON_STUB("MtNetContext::~MtNetContext")
    /* stub */
}

void MtNetContext::addDependency(MtNetObject* obj) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
        mLockCount = mLockCount + 1;
    }
    MtNetObject* * p0_0 = &mpDependObject[0];
    for (s32 i = 0; i <= 3; p0_0 += 1, i += 1) {
        if ((*p0_0) == nullptr) {
            *p0_0 = obj;
            break;
        }
    }
    if (mIsThreadSafe) {
        mLockCount = mLockCount - 1;
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

void MtNetContext::removeDependency(MtNetObject* obj) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
        mLockCount = mLockCount + 1;
    }
    MtNetObject* * p0_0 = &mpDependObject[0];
    for (s32 i = 0; i <= 3; p0_0 += 1, i += 1) {
        if (obj == (*p0_0)) {
            *p0_0 = nullptr;
            break;
        }
    }
    if (mIsThreadSafe) {
        mLockCount = mLockCount - 1;
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

void MtNetContext::addListener(MtNetContext::Listener* listener) {
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

__attribute__((weak)) void MtNetContext::reqStart(u32* req_seq, s32 sign_in_level) {
    DDON_STUB("MtNetContext::reqStart")
    /* stub */
}

__attribute__((weak)) void MtNetContext::reqFinalize(u32* req_seq) {
    DDON_STUB("MtNetContext::reqFinalize")
    /* stub */
}

__attribute__((weak)) void MtNetContext::beginDestruct() {
    DDON_STUB("MtNetContext::beginDestruct")
    /* stub */
}

__attribute__((weak)) void MtNetContext::beginMove() {
    DDON_STUB("MtNetContext::beginMove")
    /* stub */
}

__attribute__((weak)) void MtNetContext::endMove() {
}

void MtNetContext::cbNtcSignInChange(s32 sign_in_level, MtNetError* net_err) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        if (mpListener != nullptr) {
            if (!isFatal()) {
                mpListener->onNtcSignInChange(sign_in_level, net_err);
            }
            if (mIsThreadSafe) {
                mLockCount = mLockCount - 1;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (mIsThreadSafe) {
                mLockCount = t0;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    } else {
        if (mpListener != nullptr) {
            if (!isFatal()) {
                mpListener->onNtcSignInChange(sign_in_level, net_err);
            }
        }
        if (mIsThreadSafe) {
            mLockCount = mLockCount - 1;
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
}

void MtNetContext::cbNtcFriendListChange(MtNetFriendList* friend_list) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        if (mpListener != nullptr) {
            if (!isFatal()) {
                mpListener->onNtcFriendListChange(friend_list);
            }
            if (mIsThreadSafe) {
                mLockCount = mLockCount - 1;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (mIsThreadSafe) {
                mLockCount = t0;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    } else {
        if (mpListener != nullptr) {
            if (!isFatal()) {
                mpListener->onNtcFriendListChange(friend_list);
            }
        }
        if (mIsThreadSafe) {
            mLockCount = mLockCount - 1;
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
}

void MtNetContext::cbNtcInviteAccept() {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        if (mpListener != nullptr) {
            if (!isFatal()) {
                mpListener->onNtcInviteAccept();
            }
            if (mIsThreadSafe) {
                mLockCount = mLockCount - 1;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (mIsThreadSafe) {
                mLockCount = t0;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    } else {
        if (mpListener != nullptr) {
            if (!isFatal()) {
                mpListener->onNtcInviteAccept();
            }
        }
        if (mIsThreadSafe) {
            mLockCount = mLockCount - 1;
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
}

__attribute__((weak)) void MtNetContext::cbNtcInviteAcceptSucceed(MtNetSessionInfo* info) {
    DDON_STUB("MtNetContext::cbNtcInviteAcceptSucceed")
    /* stub */
}

__attribute__((weak)) void MtNetContext::cbAnsStartSucceed(MtNetRequest* req, s32 sign_in_level) {
    DDON_STUB("MtNetContext::cbAnsStartSucceed")
    /* stub */
}

__attribute__((weak)) void MtNetContext::cbAnsStartFail(MtNetRequest* req, MtNetError* net_err) {
    DDON_STUB("MtNetContext::cbAnsStartFail")
    /* stub */
}

void MtNetContext::cbAnsFinalize(MtNetRequest* req) {
    if (!req->isNeedAnswer()) {
        return;
    }
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        Listener* t1 = mpListener;
        if (t1 != nullptr) {
            t1->onAnsFinalize(req->getSequence());
            if (mIsThreadSafe) {
                mLockCount = mLockCount - 1;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (mIsThreadSafe) {
                mLockCount = t0;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    } else {
        Listener* t1 = mpListener;
        if (t1 != nullptr) {
            t1->onAnsFinalize(req->getSequence());
        }
        if (mIsThreadSafe) {
            mLockCount = mLockCount - 1;
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
}

bool MtNetContext::canMoveRequest(MtNetRequest* req) {
    s32 t0 = req->getId();
    if (t0 == 258) {
        if (mRequestController.isMove(257)) {
            return false;
        }
    } else {
        if (t0 == 257) {
            if (mRequestController.isMove(258)) {
                return false;
            }
        }
    }
    return true;
}

__attribute__((weak)) s32 MtNetContext::startRequest(MtNetRequest* req) {
    DDON_STUB("MtNetContext::startRequest")
    return {};
}

s32 MtNetContext::moveRequest(MtNetRequest* req) {
    if (req != nullptr) {
        s32 t0 = req->getId();
        if (t0 == 258) {
            return moveFinalize(req);
        } else {
            if (t0 == 257) {
                return moveStart(req);
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }
}

void MtNetContext::endRequest(MtNetRequest* req) {
    if (req == nullptr) {
        return;
    }
    req->getId();
    if (req->getId() == 258) {
        mIsNeedFinalize = false;
    } else {
        mIsNeedFinalize = true;
    }
}

void MtNetContext::startFailRequest(MtNetRequest* req) {
    MtNetError err;
    req->getFatal(&err);
    if (req->getId() != 257) {
        return;
    }
    cbAnsStartFail(req, &err);
}

