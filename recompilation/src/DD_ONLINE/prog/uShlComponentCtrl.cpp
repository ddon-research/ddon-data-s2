// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlComponentCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cHitNode.h"
#include "cpShlBase.h"
#include "cpShlCollision.h"
#include "cpShlCondition.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamComponentCtrl::getDTI() const {
    return cShlParamComponentCtrl::DTI;
}

MtDTI& cShlParamComponentCtrl::getShlDTI() const {
    return uShlComponentCtrl::DTI;
}

__attribute__((noinline)) cShlParamComponentCtrl::~cShlParamComponentCtrl() {
    for (u32 i = 0; i < mShlComponent.mLength; i++) {
        delete mShlComponent.mpArray[i];
    }
    if (mShlComponent.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mShlComponent.mpArray));
    }
    mShlComponent.mpArray = nullptr;
    mShlComponent.mBufsiz = 0;
    mShlComponent.mLength = 0;
}

void cShlParamComponentCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mShlComponent", static_cast<MtObject*>(&mShlComponent), 0u, 0u);
}

__attribute__((weak)) void cShlParamComponentCtrl::copy(const cShlParamBase* pParam) {
    DDON_STUB("cShlParamComponentCtrl::copy")
    /* stub */
}

inline cShlParamComponentCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamComponentCtrl::MyDTI cShlParamComponentCtrl::DTI("cShlParamComponentCtrl", &::cShlParamBase::DTI, 384ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamComponentCtrl::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamComponentCtrl::DTI)->memAlloc(sizeof(cShlParamComponentCtrl), 16u, cShlParamComponentCtrl::DTI.getID())) cShlParamComponentCtrl;
}

const MtDTI& uShlComponentCtrl::getDTI() const {
    return uShlComponentCtrl::DTI;
}

uShlComponentCtrl::~uShlComponentCtrl() {
    if (mShlComponent.mLength != 0) {
        u32 v0_0 = mShlComponent.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mShlComponent.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mShlComponent.mpArray[i0_3];
                v1_0 = mShlComponent.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mShlComponent.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mShlComponent.mpArray));
    }
    mShlComponent.mpArray = nullptr;
    mShlComponent.mBufsiz = 0;
    mShlComponent.mLength = 0;
}

__attribute__((weak)) void uShlComponentCtrl::initSub() {
    DDON_STUB("uShlComponentCtrl::initSub")
    /* stub */
}

void uShlComponentCtrl::updateSub() {
    u32 i = 0;
    if (mShlComponent.mLength != 0) {
        do {
            static_cast<cpShlBase*>(mShlComponent.getBuffer()[static_cast<int>(i)])->updateSub();
            i += 1u;
        } while (i < mShlComponent.mLength);
    }
}

__attribute__((weak)) void uShlComponentCtrl::setCollisionSub(s32 seqNo, s32 groupNo, s32 atckNo, s32 shared_uid) {
    DDON_STUB("uShlComponentCtrl::setCollisionSub")
    /* stub */
}

__attribute__((weak)) u32 uShlComponentCtrl::getCollisionIndex() const {
    DDON_STUB("uShlComponentCtrl::getCollisionIndex")
    return {};
}

void uShlComponentCtrl::kill() {
    if (mShlComponent.mLength == 0) {
        this->uShlBase::kill();
        return;
    }
    u32 i = 0;
    do {
        static_cast<cpShlBase*>(mShlComponent.getBuffer()[static_cast<int>(i)])->kill();
        i += 1u;
    } while (i < mShlComponent.mLength);
    this->uShlBase::kill();
}

void uShlComponentCtrl::callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo) {
    u32 i = 0;
    if (mShlComponent.mLength != 0) {
        do {
            static_cast<cpShlBase*>(mShlComponent.getBuffer()[static_cast<int>(i)])->callbackReplaceHitInfo_Atk(pHitInfo);
            i += 1u;
        } while (i < mShlComponent.mLength);
    }
}

void uShlComponentCtrl::setEffectEpvTimer(f32 timer) {
    if (mpEfcHandle == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->epvSetTimer(mpEfcHandle, static_cast<unsigned int>(static_cast<long>(timer)));
}

const cShlParamCompCondition* uShlComponentCtrl::getParamCondition() const {
    const cShlParamComponent* v4_0;
    if (mShlComponent.mLength == 0) {
        v4_0 = nullptr;
    } else {
        unsigned int i0_2 = 0;
        const MtDTI* v1_0;
        for (;;) {
            MtObject* v1_9 = mShlComponent.mpArray[i0_2];
            const MtDTI& t0 = v1_9->getDTI();
            MT_CTSTR v1_1 = cpShlCondition::DTI.mName;
            v1_0 = &t0;
            for (;;) {
                if (v1_1 != v1_0->mName) {
                    if (v1_0->mpParent != nullptr) {
                        v1_0 = v1_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v1_9 == nullptr) {
                        break;
                    } else {
                        cpShlCondition* pComp = static_cast<cpShlCondition*>(v1_9);
                        v4_0 = static_cast<cpShlBase*>(v1_9)->getParam();
                        return static_cast<const cShlParamCompCondition*>(v4_0);
                    }
                }
            }
            if ((i0_2 + 1u) < mShlComponent.mLength) {
                i0_2 += 1u;
            } else {
                break;
            }
        }
        v4_0 = nullptr;
    }
    return static_cast<const cShlParamCompCondition*>(v4_0);
}

__attribute__((weak)) const cpShlBase* uShlComponentCtrl::getShlComponent(MtDTI& dti) const {
    DDON_STUB("uShlComponentCtrl::getShlComponent")
    return nullptr;
}

__attribute__((weak)) bool uShlComponentCtrl::hasCondition() const {
    DDON_STUB("uShlComponentCtrl::hasCondition")
    return {};
}

u32 uShlComponentCtrl::getOwnerSkillLv() const {
    unsigned int v4_10;
    if (mShlComponent.mLength == 0) {
        v4_10 = 1;
    } else {
        unsigned int i0_3 = 0;
        const MtDTI* v1_0;
        for (;;) {
            MtObject* v1_9 = mShlComponent.mpArray[i0_3];
            const MtDTI& t0 = v1_9->getDTI();
            MT_CTSTR v1_1 = cpShlCustomCondition::DTI.mName;
            v1_0 = &t0;
            for (;;) {
                if (v1_1 != v1_0->mName) {
                    if (v1_0->mpParent != nullptr) {
                        v1_0 = v1_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    if (v1_9 == nullptr) {
                        break;
                    } else {
                        cpShlCustomCondition* pComp = static_cast<cpShlCustomCondition*>(v1_9);
                        v4_10 = pComp->mOwnerSkillLv;
                        return v4_10;
                    }
                }
            }
            if ((i0_3 + 1u) < mShlComponent.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
        v4_10 = 1;
    }
    return v4_10;
}

void uShlComponentCtrl::requestSe(u32 reqNo, MtObject* thisObj, const MtVector3& postion) {
    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(getSeResource(), reqNo, thisObj, postion);
}

inline uShlComponentCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlComponentCtrl::MyDTI uShlComponentCtrl::DTI("uShlComponentCtrl", &::uShlBase::DTI, 10960ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlComponentCtrl::MyDTI::newInstance() const {
    DDON_STUB("uShlComponentCtrl::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cpShlBase>::~MtTypedArray();

