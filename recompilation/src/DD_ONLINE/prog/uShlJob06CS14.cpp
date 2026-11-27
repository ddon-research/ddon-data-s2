// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlJob06CS14.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cContextPlayerInfo.h"
#include "cEfcHandle.h"
#include "cHumanActId.h"
#include "cpActionManager.h"
#include "nHumanMsg.h"
#include "rEffectProvider.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob06CS14::getDTI() const {
    return cShlParamJob06CS14::DTI;
}

inline void cShlParamJob06CS14::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamJob06CS14::DTI)->memFree(p_addr);
}

MtDTI& cShlParamJob06CS14::getShlDTI() const {
    return uShlJob06CS14::DTI;
}

void cShlParamJob06CS14::createProperty(MtPropertyList& proplist) {
    this->cShlParamBase::createProperty(proplist);
}

void cShlParamJob06CS14::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
}

inline cShlParamJob06CS14::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob06CS14::MyDTI cShlParamJob06CS14::DTI("cShlParamJob06CS14", &::cShlParamBase::DTI, 352ul, 0u, 0u);

MtObject* cShlParamJob06CS14::MyDTI::newInstance() const {
    return new (16u) cShlParamJob06CS14;
}

const MtDTI& uShlJob06CS14::getDTI() const {
    return uShlJob06CS14::DTI;
}

void uShlJob06CS14::setup() {
    this->uShlBase::setup();
    if (mFirstEfcHnd == nullptr) {
        mFirstEfcHnd = reqAnchorEffect(mPos, 0);
    }
    if (mShotAfterEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mShotAfterEfcHnd, 1u);
        mShotAfterEfcHnd = nullptr;
    }
    if (mChargeEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mChargeEfcHnd, 1u);
        mChargeEfcHnd = nullptr;
    }
    if (mChargeShotEfcHnd == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mChargeShotEfcHnd, 1u);
    mChargeShotEfcHnd = nullptr;
}

__attribute__((weak)) void uShlJob06CS14::updateSub() {
    DDON_STUB("uShlJob06CS14::updateSub")
    /* stub */
}

void uShlJob06CS14::kill() {
    if (mChargeShotEfcHnd == nullptr) {
        if (!mIsChargeShot) {
            reqFinishEfct();
        }
    }
    this->uShlBase::kill();
    if (mFirstEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mFirstEfcHnd, 1u);
        mFirstEfcHnd = nullptr;
    }
    if (mShotAfterEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mShotAfterEfcHnd, 1u);
        mShotAfterEfcHnd = nullptr;
    }
    if (mChargeEfcHnd != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mChargeEfcHnd, 1u);
        mChargeEfcHnd = nullptr;
    }
    if (mChargeShotEfcHnd == nullptr) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mChargeShotEfcHnd, 1u);
    mChargeShotEfcHnd = nullptr;
}

void uShlJob06CS14::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mFirstEfcHnd != nullptr) {
        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mFirstEfcHnd)) {
            mFirstEfcHnd->mpOwner = nullptr;
            mFirstEfcHnd = nullptr;
        }
    }
    if (mShotAfterEfcHnd != nullptr) {
        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mShotAfterEfcHnd)) {
            mShotAfterEfcHnd->mpOwner = nullptr;
            mShotAfterEfcHnd = nullptr;
        }
    }
    if (mChargeShotEfcHnd == nullptr) {
        return;
    }
    if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
        mChargeShotEfcHnd->mpOwner = nullptr;
        mChargeShotEfcHnd = nullptr;
    } else {
        if (mChargeShotEfcHnd != nullptr) {
            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                mChargeShotEfcHnd->mpOwner = nullptr;
                mChargeShotEfcHnd = nullptr;
            }
        }
    }
}

__attribute__((weak)) void uShlJob06CS14::reqFinishEfct() {
    DDON_STUB("uShlJob06CS14::reqFinishEfct")
    /* stub */
}

__attribute__((weak)) cEfcHandle* uShlJob06CS14::reqAnchorEffect(const MtVector3& pos, s32 no) {
    DDON_STUB("uShlJob06CS14::reqAnchorEffect")
    return nullptr;
}

inline uShlJob06CS14::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob06CS14::MyDTI uShlJob06CS14::DTI("uShlJob06CS14", &::uShlBase::DTI, 10976ul, 0u, 0u);

MtObject* uShlJob06CS14::MyDTI::newInstance() const {
    return new (16u) uShlJob06CS14;
}

