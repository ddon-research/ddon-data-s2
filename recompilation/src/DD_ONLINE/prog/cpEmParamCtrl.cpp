// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEmParamCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cBlowShrinkInfo.h"
#include "cCharParamEnemy.h"
#include "cContextInterface.h"
#include "cDelegate.h"
#include "cOcdBase.h"
#include "cOcdParamRes.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpEmLvUpCtrl.h"
#include "cpHpDamageCtrl.h"
#include "cpOcdCtrl.h"
#include "../../generated/shared/nEnemy.h"
#include "rCharParamEnemy.h"
#include "rEmLvUpParam.h"
#include "rRegionStatusParam.h"
#include "sObjCollision.h"
#include "sObjCondition.h"
#include "uCharacter.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEmParamCtrl::getDTI() const {
    return cpEmParamCtrl::DTI;
}

void* cpEmParamCtrl::operator new(size_t sz, u32 align) {
    return cpEmParamCtrl::getAllocator()->memAlloc(sz, align, cpEmParamCtrl::DTI.getID());
}

cpEmParamCtrl::cpEmParamCtrl() {
    mpEnemy = nullptr;
}

cpEmParamCtrl::~cpEmParamCtrl() {
}

__attribute__((weak)) void cpEmParamCtrl::setup() {
    DDON_STUB("cpEmParamCtrl::setup")
    /* stub */
}

void cpEmParamCtrl::update() {
    if (mpEnemy == nullptr) {
        return;
    }
    rCharParamEnemy* pEmParam = mpEnemy->getCharaParamEnemy();
    if (pEmParam == nullptr) {
        return;
    }
    if (mpEnemy->mGuardComponent.mpHpDamageCtrl == nullptr) {
        return;
    }
    const cCharParamEnemy* pCharParamEnemy = pEmParam->getCharParamEnemy();
    if (pCharParamEnemy == nullptr) {
        return;
    }
    if (mpEnemy->isStatusRage()) {
        if (mpEnemy->isReturnTerritoryFlag()) {
            mpEnemy->mGuardComponent.mpHpDamageCtrl->mShakeInfo.setCureSpeedRate(nRegionStatus::ENDURANCE_CURE_RATE_RAGE, 0.0f);
        } else {
            mpEnemy->mGuardComponent.mpHpDamageCtrl->mShakeInfo.setCureSpeedRate(nRegionStatus::ENDURANCE_CURE_RATE_RAGE, pCharParamEnemy->mShakeCureRateRage);
        }
    } else {
        mpEnemy->getHpDamageCtrlPtr()->mShakeInfo.setCureSpeedRate(nRegionStatus::ENDURANCE_CURE_RATE_RAGE, 1.0f);
    }
    mpEnemy->mGuardComponent.mpHpDamageCtrl->mShakeInfo.reCalcCureSpeedRate();
}

void cpEmParamCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpEnemy = static_cast<uEnemy*>(pOwner);
}

void cpEmParamCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpEnemy == nullptr) {
        return;
    }
    if (mpEnemy->isEnable()) {
        return;
    }
    mpEnemy = nullptr;
}

__attribute__((weak)) void cpEmParamCtrl::calcSetStatus(cpEmParamCtrl::PARAM_TYPE type, nEnemy::PARAM_RESET_TYPE resetType) {
    DDON_STUB("cpEmParamCtrl::calcSetStatus")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::calcOcdEnduranceMax(u32 OcdUID, nEnemy::PARAM_RESET_TYPE resetType) {
    DDON_STUB("cpEmParamCtrl::calcOcdEnduranceMax")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::callCalcFunc(cpEmParamCtrl::PARAM_TYPE type, cpEmParamCtrl::stTempInfoSet tempInfo, nEnemy::PARAM_RESET_TYPE resetType) {
    DDON_STUB("cpEmParamCtrl::callCalcFunc")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::calcHpMax(cpEmParamCtrl::stTempInfoSet& info, bool reset) {
    DDON_STUB("cpEmParamCtrl::calcHpMax")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::calcShpMax(cpEmParamCtrl::stTempInfoSet& info, bool reset) {
    DDON_STUB("cpEmParamCtrl::calcShpMax")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::calcBlpMax(cpEmParamCtrl::stTempInfoSet& info, bool reset) {
    DDON_STUB("cpEmParamCtrl::calcBlpMax")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::calcDownMax(cpEmParamCtrl::stTempInfoSet& info, bool reset) {
    DDON_STUB("cpEmParamCtrl::calcDownMax")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::calcShakeMax(cpEmParamCtrl::stTempInfoSet& info, bool reset) {
    DDON_STUB("cpEmParamCtrl::calcShakeMax")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::calcOcdEnduranceMax(u32 OcdUID, cpEmParamCtrl::stTempInfoSet& info, bool reset) {
    DDON_STUB("cpEmParamCtrl::calcOcdEnduranceMax")
    /* stub */
}

__attribute__((weak)) void cpEmParamCtrl::calcRageShrinkMax(cpEmParamCtrl::stTempInfoSet& info, bool reset) {
    DDON_STUB("cpEmParamCtrl::calcRageShrinkMax")
    /* stub */
}

inline cpEmParamCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEmParamCtrl::MyDTI cpEmParamCtrl::DTI("cpEmParamCtrl", &::cpComponent::DTI, 88ul, 0u, 0u);

MtObject* cpEmParamCtrl::MyDTI::newInstance() const {
    return new (16u) cpEmParamCtrl;
}

