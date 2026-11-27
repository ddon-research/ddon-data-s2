// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlJob06CS12.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cEfcHandle.h"
#include "../../XFramework/cUnit.h"
#include "cpVibration.h"
#include "rEffectProvider.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob06CS12::getDTI() const {
    return cShlParamJob06CS12::DTI;
}

inline void cShlParamJob06CS12::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamJob06CS12::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob06CS12::getShlDTI() const {
    return uShlJob06CS12::DTI;
}

void cShlParamJob06CS12::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "effectSize", &effectSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "attackTimingFrame", &attackTimingFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "finishTimingFrame", &finishTimingFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shotEffectElementNo", &shotEffectElementNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "attackEffectElementNo", &attackEffectElementNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "endEffectElementNo", &endEffectElementNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scrEffectElementNo", &scrEffectElementNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shotSoundElementNo", &shotSoundElementNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "attackSoundElementNo", &attackSoundElementNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "attack2SoundElementNo", &attack2SoundElementNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "endSoundElementNo", &endSoundElementNo, 0u, 0u);
}

cShlParamJob06CS12::~cShlParamJob06CS12() {
}

void cShlParamJob06CS12::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamJob06CS12* pParam = static_cast<const cShlParamJob06CS12*>(pParamBase);
    finishTimingFrame = pParam->finishTimingFrame;
    attackTimingFrame = pParam->attackTimingFrame;
    shotEffectElementNo = pParam->shotEffectElementNo;
    attackEffectElementNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 364);
    endEffectElementNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 368);
    scrEffectElementNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 372);
    shotSoundElementNo = pParam->shotSoundElementNo;
    attackSoundElementNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 380);
    attack2SoundElementNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 384);
    endSoundElementNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(pParamBase) + 388);
    effectSize = pParam->effectSize;
}

inline cShlParamJob06CS12::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob06CS12::MyDTI cShlParamJob06CS12::DTI("cShlParamJob06CS12", &::cShlParamBase::DTI, 400ul, 0u, 0u);

MtObject* cShlParamJob06CS12::MyDTI::newInstance() const {
    return new (16u) cShlParamJob06CS12;
}

const MtDTI& uShlJob06CS12::getDTI() const {
    return uShlJob06CS12::DTI;
}

uShlJob06CS12::~uShlJob06CS12() {
}

void uShlJob06CS12::setup() {
    const cShlParamBase* j0;
    this->uShlBase::setup();
    const cShlParamBase* t0 = getShlParamBase();
    if (static_cast<int>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(t0) + 360)) > -1) {
        mShotEfcHnd = requestShotEffect(mPos, static_cast<s32>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(t0) + 360)));
        j0 = getShlParamBase();
    } else {
        j0 = t0;
    }
    requestShotSound(static_cast<s32>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(j0) + 376)));
}

__attribute__((weak)) void uShlJob06CS12::updateSub() {
    DDON_STUB("uShlJob06CS12::updateSub")
    /* stub */
}

void uShlJob06CS12::kill() {
    if (mShotEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mShotEfcHnd, 1u);
        mShotEfcHnd = nullptr;
    }
    if (mAttackEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mAttackEfcHnd, 1u);
        mAttackEfcHnd = nullptr;
    }
    if (mEndEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mEndEfcHnd, 1u);
        mEndEfcHnd = nullptr;
    }
    if (mScrEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mScrEfcHnd, 1u);
        mScrEfcHnd = nullptr;
    }
    this->uShlBase::kill();
}

void uShlJob06CS12::updatePtr() {
    this->uShlBase::updatePtr();
}

void uShlJob06CS12::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mShotEfcHnd == nullptr) {
        if (mAttackEfcHnd == nullptr) {
            if (mEndEfcHnd != nullptr) {
                if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mEndEfcHnd)) {
                    mEndEfcHnd->mpOwner = nullptr;
                    mEndEfcHnd = nullptr;
                }
            }
        } else {
            if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mAttackEfcHnd)) {
                if (mEndEfcHnd != nullptr) {
                    if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mEndEfcHnd)) {
                        mEndEfcHnd->mpOwner = nullptr;
                        mEndEfcHnd = nullptr;
                    }
                }
            } else {
                mAttackEfcHnd->mpOwner = nullptr;
                mAttackEfcHnd = nullptr;
                if (mEndEfcHnd != nullptr) {
                    if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mEndEfcHnd)) {
                        mEndEfcHnd->mpOwner = nullptr;
                        mEndEfcHnd = nullptr;
                    }
                }
            }
        }
    } else {
        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mShotEfcHnd)) {
            mShotEfcHnd->mpOwner = nullptr;
            mShotEfcHnd = nullptr;
        }
        if (mAttackEfcHnd != nullptr) {
            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mAttackEfcHnd)) {
                mAttackEfcHnd->mpOwner = nullptr;
                mAttackEfcHnd = nullptr;
            }
        }
        if (mEndEfcHnd != nullptr) {
            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mEndEfcHnd)) {
                mEndEfcHnd->mpOwner = nullptr;
                mEndEfcHnd = nullptr;
            }
        }
    }
    if (mScrEfcHnd != nullptr) {
        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mScrEfcHnd)) {
            mScrEfcHnd->mpOwner = nullptr;
            mScrEfcHnd = nullptr;
        }
    }
}

__attribute__((weak)) cEfcHandle* uShlJob06CS12::requestShotEffect(const MtVector3& pos, s32 no) {
    DDON_STUB("uShlJob06CS12::requestShotEffect")
    return nullptr;
}

__attribute__((weak)) cEfcHandle* uShlJob06CS12::requestLandEffect(const MtVector3& pos, s32 no) {
    DDON_STUB("uShlJob06CS12::requestLandEffect")
    return nullptr;
}

__attribute__((weak)) void uShlJob06CS12::requestShotSound(s32 no) {
    DDON_STUB("uShlJob06CS12::requestShotSound")
    /* stub */
}

__attribute__((weak)) void uShlJob06CS12::requestLoopSound(s32 no) {
    DDON_STUB("uShlJob06CS12::requestLoopSound")
    /* stub */
}

inline uShlJob06CS12::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob06CS12::MyDTI uShlJob06CS12::DTI("uShlJob06CS12", &::uShlBase::DTI, 10992ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlJob06CS12::MyDTI::newInstance() const {
    DDON_STUB("uShlJob06CS12::MyDTI::newInstance")
    return nullptr;
}

