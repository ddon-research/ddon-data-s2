// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "sReward.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSynchronize.h"
#include "Protocol/PacketData/Pawn.h"
#include "cNetGameServer.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sReward::getDTI() const {
    return sReward::DTI;
}

void* sReward::operator new(size_t sz, u32 align) {
    return sReward::getAllocator()->memAlloc(sz, align, sReward::DTI.getID());
}

sReward::sReward() {
    DDON_STUB("sReward::sReward")
    /* stub */
}

__attribute__((noinline)) sReward::~sReward() {
    DDON_STUB("sReward::~sReward")
    /* stub */
}

void sReward::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "AvailableReward", static_cast<MtObject*>(&mAvailableReward), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ReleaseEmote", static_cast<MtObject*>(&mReleaseEmote), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ReleaseTalk", static_cast<MtObject*>(&mReleaseTalk), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ReleaseEdit", static_cast<MtObject*>(&mReleaseEdit), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ReleaseAbility", static_cast<MtObject*>(&mReleaseAbility), 0u, 0u);
}

MtUI* sReward::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sReward::reset() {
    DDON_STUB("sReward::reset")
    /* stub */
}

__attribute__((weak)) void sReward::move() {
    DDON_STUB("sReward::move")
    /* stub */
}

bool sReward::isAvailableReward() {
    return mAvailableReward.mLength != 0;
}

bool sReward::isAvailableRewardEdit() {
    if (mAvailableReward.mLength != 0) {
        u32 i = 0;
        do {
            if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mAvailableReward.mpArray[i]) + 8)) == 1) {
                return true;
            }
            i += 1u;
        } while (i < mAvailableReward.mLength);
    }
    return false;
}

u32 sReward::getAvailableRewardEditNo() {
    if (mAvailableReward.mLength != 0) {
        u32 i = 0;
        do {
            if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mAvailableReward.mpArray[i]) + 8)) == 1) {
                return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mAvailableReward.mpArray[i]) + 16);
            }
            i += 1u;
        } while (i < mAvailableReward.mLength);
    }
    return 0;
}

void sReward::requestGetAvailableList() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if ((mStatusAvailableList - 3u) <= 1u) {
        mStatusAvailableList = 1;
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sReward::requestGetReleaseList() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if ((mStatusReleaseList - 3u) <= 1u) {
        mStatusReleaseList = 1;
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sReward::requestReceiveReward(bool update) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if ((mStatusReceiveReward - 3u) <= 1u) {
        if (update) {
            mStatusReceiveReward = 2;
        } else {
            mStatusReceiveReward = 1;
        }
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sReward::requestAvailableAchieve() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if ((mStatusAvailableAchieve - 3u) <= 1u) {
        mStatusAvailableAchieve = 1;
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

bool sReward::isFinishGetAvailableList() {
    return (mStatusAvailableList - 3u) <= 1u;
}

bool sReward::isFinishGetReleaseList() {
    return (mStatusReleaseList - 3u) <= 1u;
}

bool sReward::isFinishReceiveReward() {
    return (mStatusReceiveReward - 3u) <= 1u;
}

bool sReward::isFinishAvailableAchieve() {
    return (mStatusAvailableAchieve - 3u) <= 1u;
}

u32 sReward::getNextRewardType() {
    if (mAvailableReward.mLength != 0) {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*mAvailableReward.mpArray) + 8);
    } else {
        return 0;
    }
}

u32 sReward::getNextRewardNo() {
    if (mAvailableReward.mLength != 0) {
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*mAvailableReward.mpArray) + 16);
    } else {
        return 0;
    }
}

__attribute__((weak)) u32 sReward::getTalkReleaseLv() {
    DDON_STUB("sReward::getTalkReleaseLv")
    return {};
}

__attribute__((weak)) void sReward::setAvailableReward(const MtTypedArray<CDataPartnerPawnReward>& list) {
    DDON_STUB("sReward::setAvailableReward")
    /* stub */
}

__attribute__((weak)) void sReward::setReleaseReward(const MtTypedArray<CDataPartnerPawnReward>& list) {
    DDON_STUB("sReward::setReleaseReward")
    /* stub */
}

__attribute__((weak)) void sReward::moveReceiveReward() {
    DDON_STUB("sReward::moveReceiveReward")
    /* stub */
}

void sReward::resetReleaseReward() {
    if (mReleaseEmote.mLength != 0) {
        u32 v0_0 = mReleaseEmote.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mReleaseEmote.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mReleaseEmote.mpArray[i0_3];
                v1_0 = mReleaseEmote.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mReleaseEmote.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mReleaseEmote.mpArray));
    }
    mReleaseEmote.mpArray = nullptr;
    mReleaseEmote.mBufsiz = 0;
    mReleaseEmote.mLength = 0;
    if (mReleaseTalk.mLength != 0) {
        u32 v3_0 = mReleaseTalk.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mReleaseTalk.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mReleaseTalk.mpArray[i3_3];
                v4_0 = mReleaseTalk.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mReleaseTalk.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mReleaseTalk.mpArray));
    }
    mReleaseTalk.mpArray = nullptr;
    mReleaseTalk.mBufsiz = 0;
    mReleaseTalk.mLength = 0;
    if (mReleaseEdit.mLength != 0) {
        u32 v6_0 = mReleaseEdit.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mReleaseEdit.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mReleaseEdit.mpArray[i6_3];
                v7_0 = mReleaseEdit.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mReleaseEdit.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mReleaseEdit.mpArray));
    }
    mReleaseEdit.mpArray = nullptr;
    mReleaseEdit.mBufsiz = 0;
    mReleaseEdit.mLength = 0;
    if (mReleaseAbility.mLength != 0) {
        u32 v9_0 = mReleaseAbility.mLength;
        unsigned int i9_3 = 0;
        u32 v10_0;
        for (;;) {
            if (mReleaseAbility.mpArray[i9_3] == nullptr) {
                v10_0 = v9_0;
            } else {
                delete mReleaseAbility.mpArray[i9_3];
                v10_0 = mReleaseAbility.mLength;
            }
            if ((i9_3 + 1u) < v10_0) {
                v9_0 = v10_0;
                i9_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mReleaseAbility.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mReleaseAbility.mpArray));
    }
    mReleaseAbility.mpArray = nullptr;
    mReleaseAbility.mBufsiz = 0;
    mReleaseAbility.mLength = 0;
}

inline sReward::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sReward::MyDTI sReward::DTI("sReward", &::cSystem::DTI, 200ul, 0u, 0u);

sReward* sReward::mpInstance;

__attribute__((weak)) MtObject* sReward::MyDTI::newInstance() const {
    DDON_STUB("sReward::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sReward::cAvailableReward::getDTI() const {
    return sReward::cAvailableReward::DTI;
}

sReward::cAvailableReward::~cAvailableReward() {
}

void sReward::cAvailableReward::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mRewardType", &mRewardType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParamTypeId", &mParamTypeId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUid", &mUid, 0u, 0u);
}

inline sReward::cAvailableReward::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sReward::cAvailableReward::MyDTI sReward::cAvailableReward::DTI("sReward::cAvailableReward", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sReward::cAvailableReward::MyDTI::newInstance() const {
    return new (16u) sReward::cAvailableReward;
}

const MtDTI& sReward::cReleaseReward::getDTI() const {
    return sReward::cReleaseReward::DTI;
}

sReward::cReleaseReward::~cReleaseReward() {
}

void sReward::cReleaseReward::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mRewardNo", &mRewardNo, 0u, 0u);
}

inline sReward::cReleaseReward::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sReward::cReleaseReward::MyDTI sReward::cReleaseReward::DTI("sReward::cReleaseReward", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* sReward::cReleaseReward::MyDTI::newInstance() const {
    return new (16u) sReward::cReleaseReward;
}

const MtDTI& sReward::cReleaseRewardEdit::getDTI() const {
    return sReward::cReleaseRewardEdit::DTI;
}

sReward::cReleaseRewardEdit::~cReleaseRewardEdit() {
}

void sReward::cReleaseRewardEdit::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mRewardType", &mRewardType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRewardNo", &mRewardNo, 0u, 0u);
}

inline sReward::cReleaseRewardEdit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sReward::cReleaseRewardEdit::MyDTI sReward::cReleaseRewardEdit::DTI("sReward::cReleaseRewardEdit", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* sReward::cReleaseRewardEdit::MyDTI::newInstance() const {
    return new (16u) sReward::cReleaseRewardEdit;
}

template MtTypedArray<sReward::cAvailableReward>::~MtTypedArray();

template MtTypedArray<sReward::cReleaseReward>::~MtTypedArray();

template MtTypedArray<sReward::cReleaseRewardEdit>::~MtTypedArray();

