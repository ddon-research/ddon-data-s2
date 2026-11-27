// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cOcdGoodStatusHuman.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cOcdBase.h"
#include "cOcdGoodStatus.h"
#include "../../generated/shared/nDDOGame.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uShlCondition.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOcdElementCover::getDTI() const {
    return cOcdElementCover::DTI;
}

cOcdElementCover::~cOcdElementCover() {
}

void cOcdElementCover::init(bool initFlag) {
    this->cOcdGoodStatusBase::init(initFlag);
    cContextPlayerInfo* t0 = cContextInterface::getContextPlayerInfo(mpModel->mContextInterface.mpContextInstance);
    if (t0 != nullptr) {
        t0->calcStatus(255u);
    }
    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(static_cast<sSoundExt*>(sSound::getInstance())->getGameBuffResource(), 915u, static_cast<MtObject*>(mpModel), static_cast<const uCoord*>(mpModel), 2);
}

void cOcdElementCover::final() {
    this->cOcdGoodStatusBase::final();
    cContextPlayerInfo* t0 = cContextInterface::getContextPlayerInfo(mpModel->mContextInterface.mpContextInstance);
    if (t0 == nullptr) {
        return;
    }
    t0->calcStatus(255u);
}

nDDOGame::ELEMENT_TYPE cOcdElementCover::getElemnentType() const {
    if ((mpModel->mUnitId & 16u) != 0) {
        if (mpModel != nullptr) {
            return cContextInterface::getElementCoverType(mpModel->mContextInterface.mpContextInstance);
        }
    }
    return nDDOGame::ELEMENT_TYPE_START_ELEMENT;
}

f32 cOcdElementCover::getAdjsutRate() const {
    if ((mpModel->mUnitId & 16u) != 0) {
        if (mpModel != nullptr) {
            return cContextInterface::getElementCoverRate(mpModel->mContextInterface.mpContextInstance);
        }
    }
    return 0.0f;
}

f32 cOcdElementCover::getAdjustDamageRate() const {
    if ((mpModel->mUnitId & 16u) != 0) {
        if (mpModel != nullptr) {
            return cContextInterface::getElementCoverDamageRate(mpModel->mContextInterface.mpContextInstance);
        }
    }
    return 0.0f;
}

void cOcdElementCover::callbackHitShlCondition_Catch(const cShlConditionInfo* pShlInfo) {
    this->cOcdBase::callbackHitShlCondition_Catch(pShlInfo);
    if (pShlInfo == nullptr) {
        return;
    }
    uDDOModel* t0 = mpModel;
    if ((t0->mUnitId & 16u) == 0) {
        return;
    }
    if (t0 == nullptr) {
        return;
    }
    cContextInterface::setElementCoverType(t0->mContextInterface.mpContextInstance, pShlInfo->mElementType);
    cContextInterface::setElementCoverRate(t0->mContextInterface.mpContextInstance, pShlInfo->mAdjustParam0);
    cContextInterface::setElementCoverDamageRate(t0->mContextInterface.mpContextInstance, pShlInfo->mAdjustParam1);
}

MtObject* cOcdElementCover::MyDTI::newInstance() const {
    return new (16u) cOcdElementCover;
}

