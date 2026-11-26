// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "sNetwork.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetContext.h"
#include "../MT/MtNetCore.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtNetObject.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#include "cSystem.h"
#include "nNetworkAchievement.h"
#include "nNetworkCallback.h"
#include "nNetworkQueue.h"
#include "nNetworkRanking.h"
#include "nNetworkService.h"
#include "nNetworkSession.h"
#include "nNetworkSharedMemory2.h"
#include "nNetworkStorage.h"
#include "nNetworkVoiceChat.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sNetwork::getDTI() const {
    return sNetwork::DTI;
}

inline void sNetwork::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(sNetwork::DTI)->memFree(p_addr);
}

sNetwork::sNetwork(MtNetCore::InitParam* param) {
    DDON_STUB("sNetwork::sNetwork")
    /* stub */
}

sNetwork::~sNetwork() {
    this->sNetwork::reset();
    if (mpCore != nullptr) {
        delete mpCore;
        mpCore = nullptr;
    }
    sNetwork::mpInstance = nullptr;
}

__attribute__((weak)) void sNetwork::reset() {
    if ((sMain::mpInstance)->mExit) {
        MtNetCore::onGuideAppShutdown();
    }
    if (mpVoiceChat != nullptr) {
        shutdownVoiceChat();
    }
    if (mpRanking != nullptr) {
        shutdownRanking();
    }
    if (mpSession[0] != nullptr) {
        shutdownSession();
    }
    if (mpAchievement != nullptr) {
        delete mpAchievement;
        mpAchievement = nullptr;
    }
    if (mpStorage != nullptr) {
        shutdownStorage();
    }
    mContext[0].reset();
    mContext[1].reset();
    mContext[2].reset();
    mContext[3].reset();
    mUnresponsiveLimit = 20000;
    mLogTimer = 0;
    mMuteListChange = false;
    mSuspend = false;
    forceSingleService(21, 0);
}

__attribute__((weak)) void sNetwork::move() {
    DDON_STUB("sNetwork::move")
    /* stub */
}

void sNetwork::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "LogLevel", reinterpret_cast<MT_MFUNC>(&::sNetwork::getLogLevel), reinterpret_cast<MT_MFUNC>(&::sNetwork::setLogLevel), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mUnresponsiveLimit", &mUnresponsiveLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMuteListChange", &mMuteListChange, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCore", reinterpret_cast<MtObject* *>(&mpCore), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mContext", static_cast<MtObject*>(&mContext[0]), 34u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSession", reinterpret_cast<MtObject* *>(&mpSession[0]), 34u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRanking", reinterpret_cast<MtObject* *>(&mpRanking), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpStorage", reinterpret_cast<MtObject* *>(&mpStorage), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpVoiceChat", reinterpret_cast<MtObject* *>(&mpVoiceChat), 2u, 0u);
}

MtUI* sNetwork::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) u32 sNetwork::getServiceUserIndex() const {
    DDON_STUB("sNetwork::getServiceUserIndex")
    return {};
}

__attribute__((weak)) bool sNetwork::isServiceStart() const {
    DDON_STUB("sNetwork::isServiceStart")
    return {};
}

s32 sNetwork::getServiceState(u32 user_index, s32 service) const {
    s32 v5_3;
    if (mpCore == nullptr) {
        v5_3 = 7;
    } else {
        if (mpCore->isFatal()) {
            v5_3 = 7;
        } else {
            s32 index;
            if (service == 0) {
                for (unsigned int i2_0 = 0;;) {
                    if (mContext[i2_0].mUserIndex == user_index) {
                        if (mContext[i2_0].mState != 0) {
                            index = i2_0;
                            break;
                        }
                    }
                    if ((i2_0 + 1u) <= 3u) {
                        i2_0 = i2_0 + 1u;
                    } else {
                        v5_3 = 0;
                        return v5_3;
                    }
                }
            } else {
                for (unsigned int i0_0 = 0;;) {
                    if (mContext[i0_0].mUserIndex == user_index) {
                        if (mContext[i0_0].mService == service) {
                            if (mContext[i0_0].mState != 0) {
                                index = i0_0;
                                break;
                            }
                        }
                    }
                    if ((i0_0 + 1u) <= 3u) {
                        i0_0 = i0_0 + 1u;
                    } else {
                        v5_3 = 0;
                        return v5_3;
                    }
                }
            }
            if (index <= -1) {
                v5_3 = 0;
            } else {
                v5_3 = mContext[index].mState;
            }
        }
    }
    return v5_3;
}

__attribute__((weak)) void sNetwork::getServiceError(u32 user_index, MtNetError* err, s32 service) const {
    DDON_STUB("sNetwork::getServiceError")
    /* stub */
}

void sNetwork::procError(const MtNetError* err) {
    if (err == nullptr) {
        return;
    }
    if (!(sMain::mpInstance)->mExit) {
        handleErrorMessage(*err);
    }
}

void sNetwork::bootupContext(u32 user_index, s32 sign_in_level, s32 service, s32 option) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    unsigned int v3_3;
    unsigned int v3_8;
    if (service != 0) {
        v3_3 = service;
        v3_8 = option;
    } else {
        s32 v0_1 = mContext[0].mService;
        s32 v0_0 = mContext[0].mOption;
        unsigned int i0_4 = 1;
        unsigned int v1_3;
        for (;;) {
            if (mContext[i0_4].mService != v0_1) {
                v1_3 = 0;
                break;
            } else {
                if (mContext[i0_4].mOption != v0_0) {
                    v1_3 = 0;
                    break;
                } else {
                    if ((i0_4 + 1u) <= 3u) {
                        i0_4 += 1u;
                    } else {
                        v1_3 = v0_1;
                        break;
                    }
                }
            }
        }
        for (unsigned int i2_4 = 1;;) {
            if (mContext[i2_4].mService != v0_1) {
                v3_3 = v1_3;
                v3_8 = 0;
                break;
            } else {
                if (mContext[i2_4].mOption != v0_0) {
                    v3_3 = v1_3;
                    v3_8 = 0;
                    break;
                } else {
                    if ((i2_4 + 1u) <= 3u) {
                        i2_4 += 1u;
                    } else {
                        v3_3 = v1_3;
                        v3_8 = v0_0;
                        break;
                    }
                }
            }
        }
    }
    if (sign_in_level != 0) {
        unsigned int i4_0 = 0;
        unsigned int v5_0;
        for (;;) {
            if (mContext[i4_0].mState != 0) {
                v5_0 = i4_0;
                break;
            } else {
                if ((i4_0 + 1u) <= 3u) {
                    i4_0 += 1u;
                } else {
                    v5_0 = i4_0 + 1u;
                    break;
                }
            }
        }
        if (v5_0 == 4) {
            mpCore->reset();
        }
    }
    for (unsigned int i7_0 = 0; i7_0 <= 3u; i7_0 = i7_0 + 1u) {
        if (mContext[i7_0].mState != 0) {
            if (mContext[i7_0].mUserIndex == user_index) {
                if (mContext[i7_0].mService == static_cast<int>(v3_3)) {
                    if (mContext[i7_0].mOption == static_cast<int>(v3_8)) {
                        mContext[i7_0].mReqLevel = sign_in_level;
                        mContext[i7_0].bootup();
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                                return;
                            }
                        }
                    } else {
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                                abort();
                                return;
                            }
                        }
                    }
                    return;
                }
            }
        }
    }
    for (unsigned int i10_0 = 0; i10_0 <= 3u; i10_0 = i10_0 + 1u) {
        if (mContext[i10_0].mState == 0) {
            mContext[i10_0].mUserIndex = user_index;
            mContext[i10_0].mReqLevel = sign_in_level;
            mContext[i10_0].mService = static_cast<s32>(v3_3);
            mContext[i10_0].mOption = static_cast<s32>(v3_8);
            mContext[i10_0].bootup();
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                    return;
                }
            }
            return;
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

__attribute__((weak)) void sNetwork::shutdownContext(u32 user_index, s32 service) {
    DDON_STUB("sNetwork::shutdownContext")
    /* stub */
}

__attribute__((weak)) MtNetContext* sNetwork::getContext() {
    DDON_STUB("sNetwork::getContext")
    return nullptr;
}

__attribute__((weak)) MtNetFriendList* sNetwork::getFriendList() {
    DDON_STUB("sNetwork::getFriendList")
    return nullptr;
}

__attribute__((weak)) MtNetContext* sNetwork::getContext(u32 user_index, s32 service) {
    DDON_STUB("sNetwork::getContext")
    return nullptr;
}

s32 sNetwork::getSignInLevel(u32 user_index, s32 service) const {
    unsigned int v3_0;
    if (service == 0) {
        for (unsigned int i2_0 = 0;;) {
            if (mContext[i2_0].mState != 0) {
                if (mContext[i2_0].mUserIndex == user_index) {
                    v3_0 = i2_0;
                    break;
                }
            }
            if ((i2_0 + 1u) > 3u) {
                return 0;
            } else {
                i2_0 = i2_0 + 1u;
            }
        }
    } else {
        for (unsigned int i0_0 = 0;;) {
            if (mContext[i0_0].mState != 0) {
                if (mContext[i0_0].mUserIndex == user_index) {
                    if (mContext[i0_0].mService == service) {
                        v3_0 = i0_0;
                        break;
                    }
                }
            }
            if ((i0_0 + 1u) > 3u) {
                return 0;
            } else {
                i0_0 = i0_0 + 1u;
            }
        }
    }
    if (mContext[v3_0].mpContext != nullptr) {
        return mContext[v3_0].mpContext->getSignInLevel();
    } else {
        return 0;
    }
}

bool sNetwork::isSignInChange(u32 user_index, s32 service) const {
    unsigned int v6_2;
    if (service == 0) {
        for (unsigned int i3_0 = 0; i3_0 <= 3u; i3_0 = i3_0 + 1u) {
            if (mContext[i3_0].mUserIndex == user_index) {
                if (mContext[i3_0].mState != 0) {
                    v6_2 = i3_0;
                    return mContext[static_cast<int>(v6_2)].mIsSignInChange;
                }
            }
        }
        v6_2 = 0xFFFFFFFF;
    } else {
        for (unsigned int i0_0 = 0; i0_0 <= 3u; i0_0 = i0_0 + 1u) {
            if (mContext[i0_0].mUserIndex == user_index) {
                if (mContext[i0_0].mService == service) {
                    if (mContext[i0_0].mState != 0) {
                        v6_2 = i0_0;
                        return mContext[static_cast<int>(v6_2)].mIsSignInChange;
                    }
                }
            }
        }
        v6_2 = 0xFFFFFFFF;
    }
    return mContext[static_cast<int>(v6_2)].mIsSignInChange;
}

void sNetwork::bootupSession() {
    bootupSessionEx(1u, nNetwork::Session::DTI);
}

void sNetwork::shutdownSession() {
    if (mpSession[0] == nullptr) {
        if (mpSession[1] == nullptr) {
            if (mpSession[2] != nullptr) {
                mpSession[2]->nNetwork::Session::removeDriver();
                if (mpSession[2] != nullptr) {
                    delete mpSession[2];
                    mpSession[2] = nullptr;
                }
            }
        } else {
            mpSession[1]->nNetwork::Session::removeDriver();
            if (mpSession[1] == nullptr) {
                if (mpSession[2] != nullptr) {
                    mpSession[2]->nNetwork::Session::removeDriver();
                    if (mpSession[2] != nullptr) {
                        delete mpSession[2];
                        mpSession[2] = nullptr;
                    }
                }
            } else {
                delete mpSession[1];
                mpSession[1] = nullptr;
                if (mpSession[2] != nullptr) {
                    mpSession[2]->nNetwork::Session::removeDriver();
                    if (mpSession[2] != nullptr) {
                        delete mpSession[2];
                        mpSession[2] = nullptr;
                    }
                }
            }
        }
    } else {
        mpSession[0]->nNetwork::Session::removeDriver();
        if (mpSession[0] != nullptr) {
            delete mpSession[0];
            mpSession[0] = nullptr;
        }
        if (mpSession[1] != nullptr) {
            mpSession[1]->nNetwork::Session::removeDriver();
            if (mpSession[1] != nullptr) {
                delete mpSession[1];
                mpSession[1] = nullptr;
            }
        }
        if (mpSession[2] != nullptr) {
            mpSession[2]->nNetwork::Session::removeDriver();
            if (mpSession[2] != nullptr) {
                delete mpSession[2];
                mpSession[2] = nullptr;
            }
        }
    }
    if (mpSession[3] != nullptr) {
        mpSession[3]->nNetwork::Session::removeDriver();
        if (mpSession[3] != nullptr) {
            delete mpSession[3];
            mpSession[3] = nullptr;
        }
    }
    mTransportPool.final();
}

const nNetwork::SessionDatabase* sNetwork::getSessionDatabase() const {
    if (mpSession[0] != nullptr) {
        return mpSession[0]->mpDatabase;
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void sNetwork::setReceiveCallback(u32 callback_index, MtObject* pobj, sNetwork::RECEIVE_CALLBACK callback) {
    DDON_STUB("sNetwork::setReceiveCallback")
    /* stub */
}

__attribute__((weak)) void sNetwork::clearReceiveCallback(u32 callback_index) {
    DDON_STUB("sNetwork::clearReceiveCallback")
    /* stub */
}

__attribute__((weak)) void sNetwork::bootupSessionEx(u32 session_num, const MtDTI& dti) {
    DDON_STUB("sNetwork::bootupSessionEx")
    /* stub */
}

__attribute__((weak)) void sNetwork::bootupRanking() {
    DDON_STUB("sNetwork::bootupRanking")
    /* stub */
}

void sNetwork::shutdownRanking() {
    if (mpRanking == nullptr) {
        return;
    }
    delete mpRanking;
    mpRanking = nullptr;
}

nNetwork::nRanking::Object* sNetwork::getRanking() {
    return mpRanking;
}

void sNetwork::bootupAchievement() {
    if (mpAchievement != nullptr) {
        return;
    }
    mpAchievement = new (16u) nNetwork::nAchievement::Object;
}

void sNetwork::shutdownAchievement() {
    if (mpAchievement == nullptr) {
        return;
    }
    delete mpAchievement;
    mpAchievement = nullptr;
}

nNetwork::nAchievement::Object* sNetwork::getAchievement() {
    return mpAchievement;
}

void sNetwork::bootupStorage() {
    if (mpStorage != nullptr) {
        return;
    }
    mpStorage = new (16u) nNetwork::Storage;
}

void sNetwork::shutdownStorage() {
    if (mpStorage == nullptr) {
        return;
    }
    delete mpStorage;
    mpStorage = nullptr;
}

nNetwork::Storage* sNetwork::getStorage() {
    return mpStorage;
}

__attribute__((weak)) void sNetwork::bootupVoiceChat() {
    DDON_STUB("sNetwork::bootupVoiceChat")
    /* stub */
}

void sNetwork::shutdownVoiceChat() {
    if (mpVoiceChat == nullptr) {
        return;
    }
    delete mpVoiceChat;
    mpVoiceChat = nullptr;
}

__attribute__((weak)) void sNetwork::bootupSharedMemory(s32 type) {
    DDON_STUB("sNetwork::bootupSharedMemory")
    /* stub */
}

void sNetwork::shutdownSharedMemory(s32 type) {
    if (type <= 1) {
        if (mpSharedMemory[type] != nullptr) {
            mpSharedMemory[type]->nNetwork::nSharedMemory2::Object::final();
            if (mpSharedMemory[type] != nullptr) {
                delete mpSharedMemory[type];
                mpSharedMemory[type] = nullptr;
            }
        }
    }
}

__attribute__((weak)) void sNetwork::onServiceStateChange(u32 user_index, s32 state, const MtNetError* err) {
}

__attribute__((weak)) void sNetwork::handleErrorMessage(const MtNetError& err) {
}

s32 sNetwork::getLogLevel() const {
    return MtNetLog::mInstance.getLevel();
}

void sNetwork::setLogLevel(s32 level) {
    MtNetLog::mInstance.setLevel(level);
}

__attribute__((weak)) void sNetwork::forceSingleService(s32 service, s32 option) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (mContext[0].mState != 0) {
        mContext[0].reset();
    }
    mContext[0].mService = service;
    mContext[0].mOption = option;
    if (mContext[1].mState == 0) {
        mContext[1].mService = mContext[0].mService;
        mContext[1].mOption = mContext[0].mOption;
    } else {
        mContext[1].reset();
        mContext[1].mService = service;
        mContext[1].mOption = option;
    }
    if (mContext[2].mState == 0) {
        mContext[2].mService = mContext[1].mService;
        mContext[2].mOption = mContext[1].mOption;
    } else {
        mContext[2].reset();
        mContext[2].mService = service;
        mContext[2].mOption = option;
    }
    if (mContext[3].mState == 0) {
        mContext[3].mService = mContext[2].mService;
        mContext[3].mOption = mContext[2].mOption;
    } else {
        mContext[3].reset();
        mContext[3].mService = service;
        mContext[3].mOption = option;
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
        return;
    }
    abort();
}

void sNetwork::notifyServiceStateChange(u32 user_index, s32 state, const MtNetError* err) {
    if (mpCore == nullptr) {
        return;
    }
    if (!mpCore->isFatal()) {
        onServiceStateChange(user_index, state, err);
    }
}

inline sNetwork::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sNetwork::MyDTI sNetwork::DTI("sNetwork", &::cSystem::DTI, 3384ul, 0u, 0u);

sNetwork* sNetwork::mpInstance;

__attribute__((weak)) MtObject* sNetwork::MyDTI::newInstance() const {
    DDON_STUB("sNetwork::MyDTI::newInstance")
    return nullptr;
}

