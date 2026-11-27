// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "MtNetRequest.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtObject.h"
#include "MtProperty.h"
#include "MtPropertyList.h"
#include "MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtNetRequest::~MtNetRequest() {
    if (mpPointer[0] != nullptr) {
        mpPointer[0] = nullptr;
    }
    if (mpPointer[1] != nullptr) {
        mpPointer[1] = nullptr;
    }
    if (mpPointer[2] != nullptr) {
        mpPointer[2] = nullptr;
    }
    if (mpPointer[3] != nullptr) {
        mpPointer[3] = nullptr;
    }
    if (mpPointer[4] != nullptr) {
        mpPointer[4] = nullptr;
    }
    if (mpPointer[5] != nullptr) {
        mpPointer[5] = nullptr;
    }
    if (mpPointer[6] != nullptr) {
        mpPointer[6] = nullptr;
    }
    if (mpPointer[7] != nullptr) {
        mpPointer[7] = nullptr;
    }
}

void MtNetRequest::createProperty(MtPropertyList& s) {
    this->MtNetObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSequence", &mSequence, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStatus", &mStatus, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mArgumentNum", &mArgumentNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPhase", &mPhase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartTime", &mStartTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLimitTime", &mLimitTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsAbort", &mIsAbort, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsNeedAnswer", &mIsNeedAnswer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsFinalize", &mIsFinalize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsReentrant", &mIsReentrant, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsMove", &mIsMove, 0u, 0u);
}

s32 MtNetRequest::getId() const {
    return mId;
}

u32 MtNetRequest::getSequence() const {
    return mSequence;
}

void MtNetRequest::setPhase(s32 phase) {
    mPhase = phase;
}

s32 MtNetRequest::getPhase() const {
    return mPhase;
}

bool MtNetRequest::isAbort(u32 abortPoint) const {
    return mIsAbort;
}

bool MtNetRequest::isNeedAnswer() const {
    return mIsNeedAnswer;
}

void MtNetRequest::clearFatal() {
    this->MtNetObject::clearFatal();
}

void MtNetRequest::setFatal(const MtNetError* err) {
    this->MtNetObject::setFatal(err);
    MtNetError e;
    getFatal(&e);
}

void MtNetRequest::setFatal(s32 no, s32 cause, s32 native) {
    this->MtNetObject::setFatal(no, cause, native);
    MtNetError e;
    getFatal(&e);
}

u32 MtNetRequest::mSequenceValue = 1;

MtNetRequestController::MtNetRequestController() {
    mIsNeedFinalize = false;
    mpReqQueue[7] = nullptr;
    mpReqQueue[6] = nullptr;
    mpReqQueue[5] = nullptr;
    mpReqQueue[4] = nullptr;
    mpReqQueue[3] = nullptr;
    mpReqQueue[2] = nullptr;
    mpReqQueue[1] = nullptr;
    mpReqQueue[0] = nullptr;
    mpListener = nullptr;
}

__attribute__((noinline)) MtNetRequestController::~MtNetRequestController() {
    DDON_STUB("MtNetRequestController::~MtNetRequestController")
    /* stub */
}

void MtNetRequestController::createProperty(MtPropertyList& s) {
    this->MtNetObject::createProperty(s);
}

__attribute__((weak)) void MtNetRequestController::move() {
    DDON_STUB("MtNetRequestController::move")
    /* stub */
}

__attribute__((weak)) void MtNetRequestController::add(u32* req_seq, s32 req_id, u32 attribute, s32 argc, ...) {
    DDON_STUB("MtNetRequestController::add")
    /* stub */
}

__attribute__((weak)) bool MtNetRequestController::isMove(s32 req_id) {
    DDON_STUB("MtNetRequestController::isMove")
    return {};
}

void MtNetRequestController::end(MtNetRequest* req) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            ::abort();
        }
        s32 t0 = mLockCount;
        mLockCount = t0 + 1;
        if (req != nullptr) {
            req->mStatus = 3;
            if (mpListener != nullptr) {
                mpListener->endRequest(req);
            }
            if (req->mIsMove) {
                if (req->mIsFinalize) {
                    mIsNeedFinalize = false;
                } else {
                    mIsNeedFinalize = true;
                }
            }
            if (mIsThreadSafe) {
                mLockCount = mLockCount - 1;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    ::abort();
                }
            }
        } else {
            if (mIsThreadSafe) {
                mLockCount = t0;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    ::abort();
                }
            }
        }
    } else {
        if (req != nullptr) {
            req->mStatus = 3;
            if (mpListener != nullptr) {
                mpListener->endRequest(req);
            }
            if (req->mIsMove) {
                if (req->mIsFinalize) {
                    mIsNeedFinalize = false;
                } else {
                    mIsNeedFinalize = true;
                }
            }
        }
        if (mIsThreadSafe) {
            mLockCount = mLockCount - 1;
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                ::abort();
            }
        }
    }
}

__attribute__((weak)) bool MtNetRequestController::isExist() {
    DDON_STUB("MtNetRequestController::isExist")
    return {};
}

void MtNetRequestController::abort(u32 req_seq) {
    if (mIsThreadSafe) {
        if (scePthreadMutexLock(&mCS.mCSection) == 0) {
            mLockCount = mLockCount + 1;
        } else {
            ::abort();
            return;
        }
    }
    if (mpReqQueue[0] != nullptr) {
        if (mpReqQueue[0]->mSequence == req_seq) {
            mpReqQueue[0]->mIsAbort = true;
        }
    }
    if (mpReqQueue[1] != nullptr) {
        if (mpReqQueue[1]->mSequence == req_seq) {
            mpReqQueue[1]->mIsAbort = true;
        }
    }
    if (mpReqQueue[2] != nullptr) {
        if (mpReqQueue[2]->mSequence == req_seq) {
            mpReqQueue[2]->mIsAbort = true;
        }
    }
    if (mpReqQueue[3] != nullptr) {
        if (mpReqQueue[3]->mSequence == req_seq) {
            mpReqQueue[3]->mIsAbort = true;
        }
    }
    if (mpReqQueue[4] != nullptr) {
        if (mpReqQueue[4]->mSequence == req_seq) {
            mpReqQueue[4]->mIsAbort = true;
        }
    }
    if (mpReqQueue[5] != nullptr) {
        if (mpReqQueue[5]->mSequence == req_seq) {
            mpReqQueue[5]->mIsAbort = true;
        }
    }
    if (mpReqQueue[6] != nullptr) {
        if (mpReqQueue[6]->mSequence == req_seq) {
            mpReqQueue[6]->mIsAbort = true;
        }
    }
    if (mpReqQueue[7] != nullptr) {
        if (mpReqQueue[7]->mSequence == req_seq) {
            mpReqQueue[7]->mIsAbort = true;
        }
    }
    if (!mIsThreadSafe) {
        return;
    }
    mLockCount = mLockCount - 1;
    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
        return;
    }
    ::abort();
}

