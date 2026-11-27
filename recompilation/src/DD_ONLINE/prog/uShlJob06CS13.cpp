// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlJob06CS13.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cContextPlayerInfo.h"
#include "cEfcHandle.h"
#include "cHumanActId.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpChargeCtrl.h"
#include "nDDOUtility.h"
#include "nHumanMsg.h"
#include "rEffectProvider.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#include "uShlCustomSpline.h"
#include "uShlSpline.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamJob06CS13::getDTI() const {
    return cShlParamJob06CS13::DTI;
}

MtDTI& cShlParamJob06CS13::getShlDTI() const {
    return uShlJob06CS13::DTI;
}

void cShlParamJob06CS13::createProperty(MtPropertyList& proplist) {
    this->cShlParamCustomSpline::createProperty(proplist);
}

__attribute__((weak)) void cShlParamJob06CS13::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamJob06CS13::copy")
    /* stub */
}

inline cShlParamJob06CS13::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamJob06CS13::MyDTI cShlParamJob06CS13::DTI("cShlParamJob06CS13", &::cShlParamCustomSpline::DTI, 560ul, 0u, 0u);

MtObject* cShlParamJob06CS13::MyDTI::newInstance() const {
    return new (16u) cShlParamJob06CS13;
}

const MtDTI& uShlJob06CS13::getDTI() const {
    return uShlJob06CS13::DTI;
}

void uShlJob06CS13::setup() {
    this->uShlSpline::setup();
    if (mFirstEfcHnd == nullptr) {
        mFirstEfcHnd = reqBarrettEffect(mPos, 0);
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

__attribute__((weak)) void uShlJob06CS13::updateSub() {
    DDON_STUB("uShlJob06CS13::updateSub")
    /* stub */
}

void uShlJob06CS13::kill() {
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

void uShlJob06CS13::updateEfcHandle() {
    this->uShlBase::updateEfcHandle();
    if (mFirstEfcHnd == nullptr) {
        if (mShotAfterEfcHnd == nullptr) {
            if (mChargeEfcHnd == nullptr) {
                if (mChargeShotEfcHnd != nullptr) {
                    if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                        mChargeShotEfcHnd->mpOwner = nullptr;
                        mChargeShotEfcHnd = nullptr;
                    }
                }
            } else {
                if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeEfcHnd)) {
                    if (mChargeShotEfcHnd != nullptr) {
                        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                            mChargeShotEfcHnd->mpOwner = nullptr;
                            mChargeShotEfcHnd = nullptr;
                        }
                    }
                } else {
                    mChargeEfcHnd->mpOwner = nullptr;
                    mChargeEfcHnd = nullptr;
                    if (mChargeShotEfcHnd != nullptr) {
                        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                            mChargeShotEfcHnd->mpOwner = nullptr;
                            mChargeShotEfcHnd = nullptr;
                        }
                    }
                }
            }
        } else {
            if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mShotAfterEfcHnd)) {
                if (mChargeEfcHnd == nullptr) {
                    if (mChargeShotEfcHnd != nullptr) {
                        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                            mChargeShotEfcHnd->mpOwner = nullptr;
                            mChargeShotEfcHnd = nullptr;
                        }
                    }
                } else {
                    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeEfcHnd)) {
                        if (mChargeShotEfcHnd != nullptr) {
                            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                                mChargeShotEfcHnd->mpOwner = nullptr;
                                mChargeShotEfcHnd = nullptr;
                            }
                        }
                    } else {
                        mChargeEfcHnd->mpOwner = nullptr;
                        mChargeEfcHnd = nullptr;
                        if (mChargeShotEfcHnd != nullptr) {
                            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                                mChargeShotEfcHnd->mpOwner = nullptr;
                                mChargeShotEfcHnd = nullptr;
                            }
                        }
                    }
                }
            } else {
                mShotAfterEfcHnd->mpOwner = nullptr;
                mShotAfterEfcHnd = nullptr;
                if (mChargeEfcHnd != nullptr) {
                    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeEfcHnd)) {
                        if (mChargeShotEfcHnd != nullptr) {
                            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                                mChargeShotEfcHnd->mpOwner = nullptr;
                                mChargeShotEfcHnd = nullptr;
                            }
                        }
                    } else {
                        mChargeEfcHnd->mpOwner = nullptr;
                        mChargeEfcHnd = nullptr;
                        if (mChargeShotEfcHnd != nullptr) {
                            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                                mChargeShotEfcHnd->mpOwner = nullptr;
                                mChargeShotEfcHnd = nullptr;
                            }
                        }
                    }
                } else {
                    if (mChargeShotEfcHnd != nullptr) {
                        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                            mChargeShotEfcHnd->mpOwner = nullptr;
                            mChargeShotEfcHnd = nullptr;
                        }
                    }
                }
            }
        }
    } else {
        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mFirstEfcHnd)) {
            mFirstEfcHnd->mpOwner = nullptr;
            mFirstEfcHnd = nullptr;
        }
        if (mShotAfterEfcHnd == nullptr) {
            if (mChargeEfcHnd == nullptr) {
                if (mChargeShotEfcHnd != nullptr) {
                    if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                        mChargeShotEfcHnd->mpOwner = nullptr;
                        mChargeShotEfcHnd = nullptr;
                    }
                }
            } else {
                if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeEfcHnd)) {
                    if (mChargeShotEfcHnd != nullptr) {
                        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                            mChargeShotEfcHnd->mpOwner = nullptr;
                            mChargeShotEfcHnd = nullptr;
                        }
                    }
                } else {
                    mChargeEfcHnd->mpOwner = nullptr;
                    mChargeEfcHnd = nullptr;
                    if (mChargeShotEfcHnd != nullptr) {
                        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                            mChargeShotEfcHnd->mpOwner = nullptr;
                            mChargeShotEfcHnd = nullptr;
                        }
                    }
                }
            }
        } else {
            if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mShotAfterEfcHnd)) {
                mShotAfterEfcHnd->mpOwner = nullptr;
                mShotAfterEfcHnd = nullptr;
            }
            if (mChargeEfcHnd != nullptr) {
                if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeEfcHnd)) {
                    mChargeEfcHnd->mpOwner = nullptr;
                    mChargeEfcHnd = nullptr;
                }
            }
            if (mChargeShotEfcHnd != nullptr) {
                if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mChargeShotEfcHnd)) {
                    mChargeShotEfcHnd->mpOwner = nullptr;
                    mChargeShotEfcHnd = nullptr;
                }
            }
        }
    }
    if (mEndEfcHnd != nullptr) {
        if (static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mEndEfcHnd)) {
            mEndEfcHnd->mpOwner = nullptr;
            mEndEfcHnd = nullptr;
        }
    }
}

__attribute__((weak)) void uShlJob06CS13::movePos() {
    DDON_STUB("uShlJob06CS13::movePos")
    /* stub */
}

__attribute__((weak)) void uShlJob06CS13::reqIceBarrettEfType(uShlJob06CS13::ICE_BARRETT_TYPE type) {
    DDON_STUB("uShlJob06CS13::reqIceBarrettEfType")
    /* stub */
}

__attribute__((weak)) void uShlJob06CS13::reqFinishEfct() {
    DDON_STUB("uShlJob06CS13::reqFinishEfct")
    /* stub */
}

__attribute__((weak)) cEfcHandle* uShlJob06CS13::reqBarrettEffect(const MtVector3& pos, s32 no) {
    DDON_STUB("uShlJob06CS13::reqBarrettEffect")
    return nullptr;
}

inline uShlJob06CS13::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlJob06CS13::MyDTI uShlJob06CS13::DTI("uShlJob06CS13", &::uShlCustomSpline::DTI, 11520ul, 0u, 0u);

MtObject* uShlJob06CS13::MyDTI::newInstance() const {
    return new (16u) uShlJob06CS13;
}

