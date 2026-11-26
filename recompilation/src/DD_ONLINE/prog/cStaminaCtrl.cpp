// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cStaminaCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cContextPlayerInfo.h"
#include "cHumanAction.h"
#include "cpActionManager.h"
#include "cpOcdCtrl.h"
#include "cpSequenceCtrl.h"
#include "nDDOUtility.h"
#include "nJobParam.h"
#include "../../generated/shared/nStamina.h"
#include "rStaminaDecTbl.h"
#include "sAIPawnSys.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sMain.h"
#include "sObjCollision.h"
#include "sSoundManager.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cStaminaCtrl::getDTI() const {
    return cStaminaCtrl::DTI;
}

inline void cStaminaCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cStaminaCtrl::DTI)->memFree(p_addr);
}

cStaminaCtrl::cStaminaCtrl() {
    DDON_STUB("cStaminaCtrl::cStaminaCtrl")
    /* stub */
}

cStaminaCtrl::~cStaminaCtrl() {
}

__attribute__((weak)) void cStaminaCtrl::createProperty(MtPropertyList& proplist) {
}

MtUI* cStaminaCtrl::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cStaminaCtrl::update(uHuman& owner) {
    DDON_STUB("cStaminaCtrl::update")
    /* stub */
}

void cStaminaCtrl::requestExternalUpdate(f32 stamina, nStamina::VALUE_TYPE vType, nStamina::UPDATE_TYPE uType, nStamina::CONTINUATION_TYPE cType, u32 staminaType, cStaminaCtrl::OVERRIDE_PRIO prio) {
    u32 i;
    nStamina::CONTINUATION_TYPE v0_1;
    u32 v0_5;
    f32 v0_8;
    if (mpOwner != nullptr) {
        if (mpOwner->isMaster()) {
            if ((mpOwner->mUnitId & 1024u) == 0) {
                if (mFocusIndex > 15u) {
                    i = 0;
                    v0_1 = cType;
                    v0_5 = staminaType;
                    v0_8 = stamina;
                } else {
                    mRequestFluctuationList.elems[mFocusIndex].mIsRequested = true;
                    mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mStamina = stamina;
                    mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mVType = vType;
                    mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mUType = uType;
                    mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mCType = cType;
                    mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mStaminaType = staminaType;
                    mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mPriority = prio;
                    mFocusIndex = mFocusIndex + 1u;
                    return;
                }
            } else {
                return;
            }
        } else {
            return;
        }
    } else {
        if (mFocusIndex > 15u) {
            i = 0;
            v0_1 = cType;
            v0_5 = staminaType;
            v0_8 = stamina;
        } else {
            mRequestFluctuationList.elems[mFocusIndex].mIsRequested = true;
            mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mStamina = stamina;
            mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mVType = vType;
            mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mUType = uType;
            mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mCType = cType;
            mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mProcParam.mStaminaType = staminaType;
            mRequestFluctuationList.elems[(mFocusIndex <= 15u) ? mFocusIndex : 0u].mPriority = prio;
            mFocusIndex = mFocusIndex + 1u;
            return;
        }
    }
    for (;;) {
        if (static_cast<unsigned int>(prio) >= static_cast<unsigned int>(mRequestFluctuationList.elems[i].mPriority)) {
            mRequestFluctuationList.elems[i].mIsRequested = true;
            mRequestFluctuationList.elems[i].mProcParam.mStamina = v0_8;
            mRequestFluctuationList.elems[i].mProcParam.mVType = vType;
            mRequestFluctuationList.elems[i].mProcParam.mUType = uType;
            mRequestFluctuationList.elems[i].mProcParam.mCType = v0_1;
            mRequestFluctuationList.elems[i].mProcParam.mStaminaType = v0_5;
            mRequestFluctuationList.elems[i].mPriority = prio;
        }
        if (i != 15) {
            i = i + 1u;
        } else {
            break;
        }
    }
}

__attribute__((weak)) f32 cStaminaCtrl::calcStaminaTemporarily(uHuman& owner, f32 calcStamina, nStamina::VALUE_TYPE vType, nStamina::UPDATE_TYPE uType, nStamina::CONTINUATION_TYPE cType, u32 staminaType) {
    DDON_STUB("cStaminaCtrl::calcStaminaTemporarily")
    return {};
}

__attribute__((weak)) bool cStaminaCtrl::decreaseStamina(uHuman& owner, f32& stamina, const cStaminaCtrl::stProcParam& procParam, const cContextPlayerInfo& context, f32 decreaseRate) {
    DDON_STUB("cStaminaCtrl::decreaseStamina")
    return {};
}

__attribute__((weak)) bool cStaminaCtrl::recoveryStamina(uHuman& owner, f32& stamina, const cStaminaCtrl::stProcParam& procParam, const cContextPlayerInfo& context, f32 recoveryRate) {
    DDON_STUB("cStaminaCtrl::recoveryStamina")
    return {};
}

void cStaminaCtrl::calcRateFromWeight(uHuman& owner, f32 weight, f32& recoveryRate, f32& decreaseRate) {
    recoveryRate = 1.0f;
    decreaseRate = 1.0f;
    if (owner.getContextPlayerInfo() != nullptr) {
        switch (cContextPlayerInfo::getWeightType(owner.getContextPlayerInfo()->getWeight())) {
            case nHuman::WEIGHT_VERY_LIGHT:
            {
                recoveryRate = owner.getComAdjustParam(13u);
                decreaseRate = owner.getComAdjustParam(7u);
                break;
            }
            case nHuman::WEIGHT_LIGHT:
            {
                recoveryRate = owner.getComAdjustParam(14u);
                decreaseRate = owner.getComAdjustParam(8u);
                break;
            }
            case nHuman::WEIGHT_MIDDLE:
            {
                recoveryRate = owner.getComAdjustParam(15u);
                decreaseRate = owner.getComAdjustParam(9u);
                break;
            }
            case nHuman::WEIGHT_HEAVY:
            {
                recoveryRate = owner.getComAdjustParam(16u);
                decreaseRate = owner.getComAdjustParam(10u);
                break;
            }
            case nHuman::WEIGHT_VERY_HEAVY:
            {
                recoveryRate = owner.getComAdjustParam(17u);
                decreaseRate = owner.getComAdjustParam(11u);
                break;
            }
            case nHuman::WEIGHT_OVER:
            {
                recoveryRate = owner.getComAdjustParam(18u);
                decreaseRate = owner.getComAdjustParam(12u);
                break;
            }
            default:
            {
                recoveryRate = owner.getComAdjustParam(18u);
                decreaseRate = owner.getComAdjustParam(12u);
                break;
            }
        }
    } else {
        recoveryRate = owner.getComAdjustParam(18u);
        decreaseRate = owner.getComAdjustParam(12u);
    }
}

__attribute__((weak)) void cStaminaCtrl::clearRequestParam() {
    DDON_STUB("cStaminaCtrl::clearRequestParam")
    /* stub */
}

void cStaminaCtrl::setJumpSTRecoverSlow() {
    if (mpOwner == nullptr) {
        return;
    }
    if ((mpOwner->mUnitId & 16u) == 0) {
        return;
    }
    mIsJumpRecoverSlow = true;
    mJumpRecoverSlowTime = static_cast<uHuman*>(mpOwner)->getComAdjustParam(143u);
}

inline cStaminaCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStaminaCtrl::MyDTI cStaminaCtrl::DTI("cStaminaCtrl", &::MtObject::DTI, 488ul, 0u, 0u);

__attribute__((weak)) MtObject* cStaminaCtrl::MyDTI::newInstance() const {
    DDON_STUB("cStaminaCtrl::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) bool cStaminaCtrl::stProcParam::convertFromSequence(uHuman& owner, cStaminaCtrl& stmnCtrl, const cContextPlayerInfo& context, u32 SeqIndex) {
    DDON_STUB("cStaminaCtrl::stProcParam::convertFromSequence")
    return {};
}

