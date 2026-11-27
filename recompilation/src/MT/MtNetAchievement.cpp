// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "MtNetAchievement.h"
#include "MtNetCore.h"
#include "MtNetMediator.h"
#include "MtNetObject.h"
#include "MtNetRequest.h"
#include "MtSynchronize.h"
#include "MtThread.h"
#include "../generated/shared/np_trophy.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtNetAchievement::MtNetAchievement() {
    DDON_STUB("MtNetAchievement::MtNetAchievement")
    /* stub */
}

__attribute__((noinline)) MtNetAchievement::~MtNetAchievement() {
    DDON_STUB("MtNetAchievement::~MtNetAchievement")
    /* stub */
}

void MtNetAchievement::createProperty(MtPropertyList& s) {
    this->MtNetObject::createProperty(s);
}

void MtNetAchievement::addListener(MtNetAchievement::Listener* listener) {
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

void MtNetAchievement::removeListener(MtNetAchievement::Listener* listener) {
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

void MtNetAchievement::move() {
    mRequestController.move();
    nativeMove();
}

__attribute__((weak)) void MtNetAchievement::reqInit(u32* req_seq) {
    DDON_STUB("MtNetAchievement::reqInit")
    /* stub */
}

__attribute__((weak)) void MtNetAchievement::reqStart(u32* req_seq) {
    DDON_STUB("MtNetAchievement::reqStart")
    /* stub */
}

__attribute__((weak)) void MtNetAchievement::reqAward(u32* req_seq, s32 user_index, s32 id) {
    DDON_STUB("MtNetAchievement::reqAward")
    /* stub */
}

bool MtNetAchievement::canMoveRequest(MtNetRequest* req) {
    switch (static_cast<unsigned int>(req->getId() - 1025)) {
        case 0:
        {
            if (mRequestController.isMove(1026)) {
                return false;
            } else {
                return true;
            }
            break;
        }
        case 1:
        {
            if (mRequestController.isMove(1025)) {
                return false;
            } else {
                return true;
            }
            break;
        }
        case 2:
        {
            if (mRequestController.isMove(1025)) {
                return false;
            } else {
                if (mRequestController.isMove(1026)) {
                    return false;
                } else {
                    if (mRequestController.isMove(1028)) {
                        return false;
                    } else {
                        if (mRequestController.isMove(1029)) {
                            return false;
                        } else {
                            if (mRequestController.isMove(1030)) {
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
            break;
        }
        case 3:
        {
            if (mRequestController.isMove(1025)) {
                return false;
            } else {
                if (mRequestController.isMove(1026)) {
                    return false;
                } else {
                    if (mRequestController.isMove(1027)) {
                        return false;
                    } else {
                        if (mRequestController.isMove(1029)) {
                            return false;
                        } else {
                            if (mRequestController.isMove(1030)) {
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
            break;
        }
        case 4:
        {
            if (mRequestController.isMove(1025)) {
                return false;
            } else {
                if (mRequestController.isMove(1026)) {
                    return false;
                } else {
                    if (mRequestController.isMove(1027)) {
                        return false;
                    } else {
                        if (mRequestController.isMove(1028)) {
                            return false;
                        } else {
                            if (mRequestController.isMove(1030)) {
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
            break;
        }
        case 5:
        {
            if (mRequestController.isMove(1025)) {
                return false;
            } else {
                if (mRequestController.isMove(1026)) {
                    return false;
                } else {
                    if (mRequestController.isMove(1027)) {
                        return false;
                    } else {
                        if (mRequestController.isMove(1028)) {
                            return false;
                        } else {
                            if (mRequestController.isMove(1029)) {
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
            break;
        }
        default:
        {
            return true;
        }
    }
}

__attribute__((weak)) s32 MtNetAchievement::startRequest(MtNetRequest* req) {
    DDON_STUB("MtNetAchievement::startRequest")
    return {};
}

s32 MtNetAchievement::moveRequest(MtNetRequest* req) {
    if (req != nullptr) {
        switch (static_cast<unsigned int>(req->getId() - 1025)) {
            case 0:
            {
                moveInit(req);
                return 1;
            }
            case 1:
            {
                moveStart(req);
                return 1;
            }
            case 2:
            {
                return moveGetInfo(req);
            }
            case 3:
            {
                return moveAward(req);
            }
            case 4:
            {
                return moveGetInfoList(req);
            }
            case 5:
            {
                return moveAwardList(req);
            }
            default:
            {
                return 0;
            }
        }
    } else {
        return 0;
    }
}

void MtNetAchievement::endRequest(MtNetRequest* req) {
    if (req == nullptr) {
        return;
    }
    req->getId();
}

__attribute__((weak)) void MtNetAchievement::startFailRequest(MtNetRequest* req) {
    DDON_STUB("MtNetAchievement::startFailRequest")
    /* stub */
}

__attribute__((weak)) s32 MtNetAchievement::moveInit(MtNetRequest* req) {
    mUserInfoTbl[0].isValid = false;
    mUserInfoTbl[0].isRemove = false;
    mUserInfoTbl[0].isRequest = false;
    mUserInfoTbl[0].sceUserId = -1;
    mUserInfoTbl[0].state = TrophyState_None;
    mUserInfoTbl[0].npContext = -1;
    memset(static_cast<void*>(&mUserInfoTbl[0].unlockNum), 0, 676ul);
    mUserInfoTbl[1].isValid = false;
    mUserInfoTbl[1].isRemove = false;
    mUserInfoTbl[1].isRequest = false;
    mUserInfoTbl[1].sceUserId = -1;
    mUserInfoTbl[1].state = TrophyState_None;
    mUserInfoTbl[1].npContext = -1;
    memset(static_cast<void*>(&mUserInfoTbl[1].unlockNum), 0, 676ul);
    mUserInfoTbl[2].isValid = false;
    mUserInfoTbl[2].isRemove = false;
    mUserInfoTbl[2].isRequest = false;
    mUserInfoTbl[2].sceUserId = -1;
    mUserInfoTbl[2].state = TrophyState_None;
    mUserInfoTbl[2].npContext = -1;
    memset(static_cast<void*>(&mUserInfoTbl[2].unlockNum), 0, 676ul);
    mUserInfoTbl[3].isValid = false;
    mUserInfoTbl[3].isRemove = false;
    mUserInfoTbl[3].isRequest = false;
    mUserInfoTbl[3].sceUserId = -1;
    mUserInfoTbl[3].state = TrophyState_None;
    mUserInfoTbl[3].npContext = -1;
    memset(static_cast<void*>(&mUserInfoTbl[3].unlockNum), 0, 676ul);
    if (req->isNeedAnswer()) {
        if (mIsThreadSafe) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
            }
            s32 t0 = mLockCount;
            mLockCount = t0 + 1;
            Listener* t1 = mpListener;
            if (t1 != nullptr) {
                t1->onAnsInitSucceed(req->getSequence(), 0ul);
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
            return 1;
        } else {
            Listener* t1 = mpListener;
            if (t1 != nullptr) {
                t1->onAnsInitSucceed(req->getSequence(), 0ul);
            }
            if (mIsThreadSafe) {
                mLockCount = mLockCount - 1;
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return 1;
        }
    } else {
        return 1;
    }
}

__attribute__((weak)) s32 MtNetAchievement::moveStart(MtNetRequest* req) {
    DDON_STUB("MtNetAchievement::moveStart")
    return {};
}

__attribute__((weak)) s32 MtNetAchievement::moveGetInfo(MtNetRequest* req) {
    DDON_STUB("MtNetAchievement::moveGetInfo")
    return {};
}

__attribute__((weak)) s32 MtNetAchievement::moveAward(MtNetRequest* req) {
    DDON_STUB("MtNetAchievement::moveAward")
    return {};
}

__attribute__((weak)) s32 MtNetAchievement::moveGetInfoList(MtNetRequest* req) {
    DDON_STUB("MtNetAchievement::moveGetInfoList")
    return {};
}

__attribute__((weak)) s32 MtNetAchievement::moveAwardList(MtNetRequest* req) {
    DDON_STUB("MtNetAchievement::moveAwardList")
    return {};
}

__attribute__((weak)) void MtNetAchievement::nativeMove() {
    DDON_STUB("MtNetAchievement::nativeMove")
    /* stub */
}

__attribute__((weak)) void MtNetAchievement::updateUser(MtNetAchievement::TrophyUserInfo& info) {
    DDON_STUB("MtNetAchievement::updateUser")
    /* stub */
}

MtNetAchievement* MtNetAchievement::mpInstance;

__attribute__((weak)) void MtNetAchievement::cTrophyRegisterContextThread::execute(void* pcontext) {
    DDON_STUB("MtNetAchievement::cTrophyRegisterContextThread::execute")
    /* stub */
}

__attribute__((weak)) void MtNetAchievement::cTrophyWriteThread::execute(void* pcontext) {
    DDON_STUB("MtNetAchievement::cTrophyWriteThread::execute")
    /* stub */
}

__attribute__((weak)) void MtNetAchievement::cTrophyReadThread::execute(void* pcontext) {
    DDON_STUB("MtNetAchievement::cTrophyReadThread::execute")
    /* stub */
}

