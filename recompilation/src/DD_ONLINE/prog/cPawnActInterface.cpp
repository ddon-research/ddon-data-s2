// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cPawnActInterface.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtRandom.h"
#include "cAIGrid.h"
#include "../../XFramework/cAIObject.h"
#include "cAITargetInfo.h"
#include "cComponentManager.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cEquipData.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "cHumanActBow.h"
#include "cHumanActId.h"
#include "cHumanAction.h"
#include "cHumanActionClimb.h"
#include "../../XFramework/cUnit.h"
#include "cpAIPawnEmChecker.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpCatchCtrl.h"
#include "cpChargeCtrl.h"
#include "cpComponent.h"
#include "cpCorePointCtrl.h"
#include "cpHugeble.h"
#include "cpInput.h"
#include "cpJob02.h"
#include "cpJob03.h"
#include "cpJob05.h"
#include "cpJob06.h"
#include "cpJob07.h"
#include "cpJob08.h"
#include "cpJob09.h"
#include "cpKeyCommand.h"
#include "cpOcdCtrl.h"
#include "cpPathFinding.h"
#include "cpPawnThink.h"
#include "cpRootComponent.h"
#include "cpScrCollision.h"
#include "cpSequenceCtrl.h"
#include "cpShlShotCtrl.h"
#include "cpjob10.h"
#include "../../generated/shared/nDDOGame.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "nPawn.h"
#include "rAIPawnOrder.h"
#include "rAIPawnSkillParam.h"
#include "rPriorityThink.h"
#include "sAIPawnSys.h"
#include "sAIPawnTalkMgr.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "sGeneralPoint.h"
#include "../../XFramework/sMain.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sSetManager.h"
#include "sShlManager.h"
#include "sWorldOffset.h"
#include "uAimCheck.h"
#include "../../XFramework/uBaseModel.h"
#include "uCharacter.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPawnActInterActArrow::getDTI() const {
    return cPawnActInterActArrow::DTI;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActArrow::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActArrow::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActArrow::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActArrow::updateInter")
    return {};
}

inline cPawnActInterActArrow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActArrow::MyDTI cPawnActInterActArrow::DTI("cPawnActInterActArrow", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActArrow::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActArrow::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActArrowChange::getDTI() const {
    return cPawnActInterActArrowChange::DTI;
}

__attribute__((weak)) bool cPawnActInterActArrowChange::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterActArrowChange::isEnableActInterPre")
    return {};
}

ACTINTER_CODERET cPawnActInterActArrowChange::initInter(cPawnActInterIO& param, uCharacter& owner) {
    if ((owner.uDDOModel::mUnitId & 16u) != 0) {
        param.mFreeU32.elems[0] = 0;
        return ACTINTER_CODERET_END;
    } else {
        return ACTINTER_CODERET_BREAK;
    }
}

ACTINTER_CODERET cPawnActInterActArrowChange::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    return static_cast<ACTINTER_CODERET>(moveArrowChange(param, owner, mArrowActGroup, param.mFreeU32.elems[0]) * 2);
}

void cPawnActInterActArrowChange::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mArrowActGroup);
}

inline cPawnActInterActArrowChange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActArrowChange::MyDTI cPawnActInterActArrowChange::DTI("cPawnActInterActArrowChange", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterActArrowChange::MyDTI::newInstance() const {
    return new (16u) cPawnActInterActArrowChange;
}

const MtDTI& cPawnActInterActBindAnchor::getDTI() const {
    return cPawnActInterActBindAnchor::DTI;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActBindAnchor::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActBindAnchor::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActBindAnchor::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActBindAnchor::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterActBindAnchor::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterActBindAnchor::isEnableActInterPre")
    return {};
}

bool cPawnActInterActBindAnchor::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    if (mType == 0) {
        if (pTarget != nullptr) {
            uDDOModel* t0 = pTarget->getDDOModelOwner();
            if (t0 != nullptr) {
                if ((t0->getCatchCtrlPtr() != nullptr) && ((t0->mObjStatus & 0x40000ul) == 0)) {
                    return t0->getCatchCtrlPtr()->isCatch(static_cast<u8>(10));
                }
            }
            return false;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActBindAnchor::updateContinueCircleShift(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterActBindAnchor::updateContinueCircleShift")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActBindAnchor::updateContinueCircleShiftMaskPoint(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterActBindAnchor::updateContinueCircleShiftMaskPoint")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActBindAnchor::updateContinueBindAnchor(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterActBindAnchor::updateContinueBindAnchor")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActBindAnchor::updateContinueLightingAnchor(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterActBindAnchor::updateContinueLightingAnchor")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActBindAnchor::updateContinueIceSpear(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterActBindAnchor::updateContinueIceSpear")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActBindAnchor::updateContinueAreaSupport(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterActBindAnchor::updateContinueAreaSupport")
    return {};
}

void cPawnActInterActBindAnchor::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mDoActType = r.readU32();
    mDoActNo = r.readU32();
    mDoAutoSituation = r.readU32();
    mDoEndMinFrame = r.readF32();
    cOptFlag* held0 = &mOptFlag;
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(held0), t0 * 4u);
    mType = r.readU32();
    mHoldTime = r.readF32();
    cAIPawnOrderFlag* held1 = &mEnableOrder;
    u32 t1 = r.readU32();
    r.read(static_cast<void*>(held1), t1 * 4u);
    nDDOIO::readData(r, mIsEndDanger);
    nDDOIO::readData(r, mStaminaRateMin);
    nDDOIO::readData(r, mStaminaRateMax);
}

inline cPawnActInterActBindAnchor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActBindAnchor::MyDTI cPawnActInterActBindAnchor::DTI("cPawnActInterActBindAnchor", &::cPawnActInterActNo::DTI, 88ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActBindAnchor::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActBindAnchor::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActChant::getDTI() const {
    return cPawnActInterActChant::DTI;
}

__attribute__((weak)) bool cPawnActInterActChant::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterActChant::isEnableActInterTarget")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActChant::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActChant::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActChant::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActChant::updateInter")
    return {};
}

u32 cPawnActInterActChant::getDoActionNo(cPawnActInterIO& param, uCharacter& owner) const {
    if ((mChantFlag & 4u) != 0) {
        return param.mInParam.mChantNextActNo;
    } else {
        if (mDoActType == 2) {
            return param.mInParam.mActionBase;
        } else {
            if (mDoActType == 1) {
                if (mDoActNo <= 3u) {
                    return param.mUserU32.elems[mDoActNo];
                } else {
                    return 0xFFFFFFFF;
                }
            } else {
                return getDoActionNoCore();
            }
        }
    }
}

void cPawnActInterActChant::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mDoActType = r.readU32();
    mDoActNo = r.readU32();
    mDoAutoSituation = r.readU32();
    mDoEndMinFrame = r.readF32();
    cOptFlag* held0 = &mOptFlag;
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(held0), t0 * 4u);
    nDDOIO::readData(r, mChantFlag);
}

inline cPawnActInterActChant::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActChant::MyDTI cPawnActInterActChant::DTI("cPawnActInterActChant", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActChant::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActChant::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActChargeMove::getDTI() const {
    return cPawnActInterActChargeMove::DTI;
}

bool cPawnActInterActChargeMove::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    if (pTarget != nullptr) {
        return pTarget->getDDOModelOwner() != nullptr;
    } else {
        return false;
    }
}

ACTINTER_CODERET cPawnActInterActChargeMove::initInter(cPawnActInterIO& param, uCharacter& owner) {
    getDoActionNo(param, owner);
    param.mFreeF32.elems[3] = 0.0f;
    param.mFreeF32.elems[4] = 0.0f;
    param.mFreeU32.elems[5] = 2;
    param.mFreeF32.elems[5] = 0.0f;
    param.mFreeU32.elems[4] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActChargeMove::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActChargeMove::updateInter")
    return {};
}

void cPawnActInterActChargeMove::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mDoActType = r.readU32();
    mDoActNo = r.readU32();
    mDoAutoSituation = r.readU32();
    mDoEndMinFrame = r.readF32();
    cOptFlag* held0 = &mOptFlag;
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(held0), t0 * 4u);
    nDDOIO::readData(r, mUseTime);
}

inline cPawnActInterActChargeMove::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActChargeMove::MyDTI cPawnActInterActChargeMove::DTI("cPawnActInterActChargeMove", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActChargeMove::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActChargeMove::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActCircleCancel::getDTI() const {
    return cPawnActInterActCircleCancel::DTI;
}

__attribute__((weak)) bool cPawnActInterActCircleCancel::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterActCircleCancel::isEnableActInterPre")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActCircleCancel::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActCircleCancel::updateInter")
    return {};
}

inline cPawnActInterActCircleCancel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActCircleCancel::MyDTI cPawnActInterActCircleCancel::DTI("cPawnActInterActCircleCancel", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActCircleCancel::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActCircleCancel::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActElementArrow::getDTI() const {
    return cPawnActInterActElementArrow::DTI;
}

__attribute__((weak)) bool cPawnActInterActElementArrow::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterActElementArrow::isEnableActInterTarget")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActElementArrow::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActElementArrow::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActElementArrow::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActElementArrow::updateInter")
    return {};
}

inline cPawnActInterActElementArrow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActElementArrow::MyDTI cPawnActInterActElementArrow::DTI("cPawnActInterActElementArrow", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActElementArrow::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActElementArrow::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActElementChange::getDTI() const {
    return cPawnActInterActElementChange::DTI;
}

__attribute__((weak)) bool cPawnActInterActElementChange::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterActElementChange::isEnableActInterPre")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActElementChange::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActElementChange::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActElementChange::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActElementChange::updateInter")
    return {};
}

void cPawnActInterActElementChange::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mDoActType = r.readU32();
    mDoActNo = r.readU32();
    mDoAutoSituation = r.readU32();
    mDoEndMinFrame = r.readF32();
    cOptFlag* held0 = &mOptFlag;
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(held0), t0 * 4u);
    nDDOIO::readData(r, mElementType);
}

inline cPawnActInterActElementChange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActElementChange::MyDTI cPawnActInterActElementChange::DTI("cPawnActInterActElementChange", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActElementChange::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActElementChange::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActEnchant::getDTI() const {
    return cPawnActInterActEnchant::DTI;
}

__attribute__((weak)) bool cPawnActInterActEnchant::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterActEnchant::isEnableActInterPre")
    return {};
}

bool cPawnActInterActEnchant::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    if ((owner.getPawnThinkPtr() != nullptr) && (owner.getPawnThinkPtr()->mEnemyList.mLength == 0)) {
        return false;
    }
    return true;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActEnchant::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActEnchant::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActEnchant::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActEnchant::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterActEnchant::updateEnchantSelectSubJob05(cPawnActInterIO& param, uHuman& owner, u32& rno, f32& time) {
    DDON_STUB("cPawnActInterActEnchant::updateEnchantSelectSubJob05")
    return {};
}

__attribute__((weak)) bool cPawnActInterActEnchant::updateEnchantSelectSubJob09(cPawnActInterIO& param, uHuman& owner, u32& rno, f32& time) {
    DDON_STUB("cPawnActInterActEnchant::updateEnchantSelectSubJob09")
    return {};
}

__attribute__((weak)) nDDOGame::ELEMENT_TYPE cPawnActInterActEnchant::getUseElementType(cPawnActInterIO& param, uHuman& owner) {
    DDON_STUB("cPawnActInterActEnchant::getUseElementType")
    return {};
}

void cPawnActInterActEnchant::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mDoActType = r.readU32();
    mDoActNo = r.readU32();
    mDoAutoSituation = r.readU32();
    mDoEndMinFrame = r.readF32();
    cOptFlag* held0 = &mOptFlag;
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(held0), t0 * 4u);
    nDDOIO::readData(r, mEnchantType);
    nDDOIO::readData(r, mElementType);
}

inline cPawnActInterActEnchant::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActEnchant::MyDTI cPawnActInterActEnchant::DTI("cPawnActInterActEnchant", &::cPawnActInterActNo::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActEnchant::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActEnchant::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActLight::getDTI() const {
    return cPawnActInterActLight::DTI;
}

__attribute__((weak)) bool cPawnActInterActLight::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterActLight::isEnableActInterTarget")
    return {};
}

ACTINTER_CODERET cPawnActInterActLight::initInter(cPawnActInterIO& param, uCharacter& owner) {
    getDoActionNo(param, owner);
    param.mFreeF32.elems[3] = 0.0f;
    param.mFreeF32.elems[4] = 0.0f;
    param.mFreeU32.elems[5] = 2;
    param.mFreeF32.elems[5] = 0.0f;
    param.mFreeU32.elems[4] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActLight::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActLight::updateInter")
    return {};
}

void cPawnActInterActLight::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mDoActType = r.readU32();
    mDoActNo = r.readU32();
    mDoAutoSituation = r.readU32();
    mDoEndMinFrame = r.readF32();
    cOptFlag* held0 = &mOptFlag;
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(held0), t0 * 4u);
    nDDOIO::readData(r, mUseTime);
}

inline cPawnActInterActLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActLight::MyDTI cPawnActInterActLight::DTI("cPawnActInterActLight", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActLight::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActLight::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActMedalChange::getDTI() const {
    return cPawnActInterActMedalChange::DTI;
}

__attribute__((weak)) bool cPawnActInterActMedalChange::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterActMedalChange::isEnableActInterPre")
    return {};
}

ACTINTER_CODERET cPawnActInterActMedalChange::initInter(cPawnActInterIO& param, uCharacter& owner) {
    if ((owner.uDDOModel::mUnitId & 16u) != 0) {
        param.mFreeU32.elems[0] = 0;
        return ACTINTER_CODERET_END;
    } else {
        return ACTINTER_CODERET_BREAK;
    }
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActMedalChange::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActMedalChange::updateInter")
    return {};
}

void cPawnActInterActMedalChange::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mMedalActGroup);
}

inline cPawnActInterActMedalChange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActMedalChange::MyDTI cPawnActInterActMedalChange::DTI("cPawnActInterActMedalChange", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterActMedalChange::MyDTI::newInstance() const {
    return new (16u) cPawnActInterActMedalChange;
}

const MtDTI& cPawnActInterActNo::getDTI() const {
    return cPawnActInterActNo::DTI;
}

cPawnActInterActNo::~cPawnActInterActNo() {
    DDON_STUB("cPawnActInterActNo::~cPawnActInterActNo")
    /* stub */
}

__attribute__((weak)) bool cPawnActInterActNo::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterActNo::isEnableActInterPre")
    return {};
}

__attribute__((weak)) bool cPawnActInterActNo::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterActNo::isEnableActInterTarget")
    return {};
}

__attribute__((weak)) bool cPawnActInterActNo::isEnableActInterSpecial(uCharacter& owner) const {
    DDON_STUB("cPawnActInterActNo::isEnableActInterSpecial")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActNo::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActNo::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActNo::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActNo::updateInter")
    return {};
}

u32 cPawnActInterActNo::getDoActionNo(cPawnActInterIO& param, uCharacter& owner) const {
    if (mDoActType == 2) {
        return param.mInParam.mActionBase;
    } else {
        if (mDoActType == 1) {
            if (mDoActNo <= 3u) {
                return param.mUserU32.elems[mDoActNo];
            } else {
                return 0xFFFFFFFF;
            }
        } else {
            return getDoActionNoCore();
        }
    }
}

__attribute__((weak)) bool cPawnActInterActNo::isEndCheck(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActNo::isEndCheck")
    return {};
}

__attribute__((weak)) bool cPawnActInterActNo::isComboEndCheck(cPawnActInterIO& param, uCharacter& owner) const {
    DDON_STUB("cPawnActInterActNo::isComboEndCheck")
    return {};
}

__attribute__((weak)) void cPawnActInterActNo::updateMessage(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterActNo::updateMessage")
    /* stub */
}

__attribute__((weak)) u32 cPawnActInterActNo::checkEndCheckSpAttract(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActNo::checkEndCheckSpAttract")
    return {};
}

__attribute__((weak)) u32 cPawnActInterActNo::checkEndCheckSpCatapult(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActNo::checkEndCheckSpCatapult")
    return {};
}

__attribute__((weak)) bool cPawnActInterActNo::endWaitSpCatapult(cPawnActInterIO& param, uCharacter& owner) const {
    DDON_STUB("cPawnActInterActNo::endWaitSpCatapult")
    return {};
}

__attribute__((weak)) bool cPawnActInterActNo::endWaitSpCatapultJump(cPawnActInterIO& param, uCharacter& owner) const {
    DDON_STUB("cPawnActInterActNo::endWaitSpCatapultJump")
    return {};
}

__attribute__((weak)) f32 cPawnActInterActNo::getAddChargeTime(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActNo::getAddChargeTime")
    return {};
}

__attribute__((weak)) bool cPawnActInterActNo::isChageMagWave(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos) {
    DDON_STUB("cPawnActInterActNo::isChageMagWave")
    return {};
}

void cPawnActInterActNo::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mDoActType = r.readU32();
    mDoActNo = r.readU32();
    mDoAutoSituation = r.readU32();
    mDoEndMinFrame = r.readF32();
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(&mOptFlag), t0 * 4u);
}

inline cPawnActInterActNo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActNo::MyDTI cPawnActInterActNo::DTI("cPawnActInterActNo", &::cPawnActInterBase::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActNo::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActNo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActProvoke::getDTI() const {
    return cPawnActInterActProvoke::DTI;
}

ACTINTER_CODERET cPawnActInterActProvoke::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    return ACTINTER_CODERET_END;
}

inline cPawnActInterActProvoke::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActProvoke::MyDTI cPawnActInterActProvoke::DTI("cPawnActInterActProvoke", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActProvoke::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActProvoke::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterActRapid::getDTI() const {
    return cPawnActInterActRapid::DTI;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActRapid::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActRapid::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterActRapid::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterActRapid::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterActRapid::isLoopEnd(cPawnActInterIO& param, uCharacter& owner, bool& check_end) {
    DDON_STUB("cPawnActInterActRapid::isLoopEnd")
    return {};
}

inline cPawnActInterActRapid::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterActRapid::MyDTI cPawnActInterActRapid::DTI("cPawnActInterActRapid", &::cPawnActInterActNo::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterActRapid::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterActRapid::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterAtkHerald::getDTI() const {
    return cPawnActInterAtkHerald::DTI;
}

cPawnActInterAtkHerald::~cPawnActInterAtkHerald() {
}

ACTINTER_CODERET cPawnActInterAtkHerald::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterAtkHerald::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterAtkHerald::updateInter")
    return {};
}

void cPawnActInterAtkHerald::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mDoActNo);
}

inline cPawnActInterAtkHerald::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterAtkHerald::MyDTI cPawnActInterAtkHerald::DTI("cPawnActInterAtkHerald", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterAtkHerald::MyDTI::newInstance() const {
    return new (16u) cPawnActInterAtkHerald;
}

const MtDTI& cPawnActInterAutoMotion::getDTI() const {
    return cPawnActInterAutoMotion::DTI;
}

__attribute__((weak)) bool cPawnActInterAutoMotion::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterAutoMotion::isEnableActInterPre")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterAutoMotion::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterAutoMotion::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterAutoMotion::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterAutoMotion::updateInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterAutoMotion::updateInterPlRange(cPawnActInterIO& param, uCharacter& owner, f32 range) {
    DDON_STUB("cPawnActInterAutoMotion::updateInterPlRange")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterAutoMotion::updateInterArea(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterAutoMotion::updateInterArea")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterAutoMotion::updateInterFindParty(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterAutoMotion::updateInterFindParty")
    return {};
}

__attribute__((weak)) uCharacter* cPawnActInterAutoMotion::lotPartyPlayer(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterAutoMotion::lotPartyPlayer")
    return nullptr;
}

__attribute__((weak)) uCharacter* cPawnActInterAutoMotion::lotPartyFindParty(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterAutoMotion::lotPartyFindParty")
    return nullptr;
}

void cPawnActInterAutoMotion::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mAutoMotSituation);
    nDDOIO::readData(r, mSetEmotion);
}

inline cPawnActInterAutoMotion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterAutoMotion::MyDTI cPawnActInterAutoMotion::DTI("cPawnActInterAutoMotion", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterAutoMotion::MyDTI::newInstance() const {
    return new (16u) cPawnActInterAutoMotion;
}

const MtDTI& cPawnActInterBase::getDTI() const {
    return cPawnActInterBase::DTI;
}

cPawnActInterBase::~cPawnActInterBase() {
}

ACTINTER_CODERET cPawnActInterBase::initInter(cPawnActInterIO& param, uCharacter& owner) {
    return ACTINTER_CODERET_END;
}

ACTINTER_CODERET cPawnActInterBase::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) void cPawnActInterBase::endInter() {
}

void cPawnActInterBase::load(MtDataReader& r) {
    nDDOIO::readData(r, mLifeFrame);
    nDDOIO::readData(r, mDisableNotice);
}

void cPawnActInterBase::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mLifeFrame);
    nDDOIO::writeData(w, mDisableNotice);
}

__attribute__((weak)) void cPawnActInterBase::createProperty(MtPropertyList& s) {
}

bool cPawnActInterBase::isEnableActInterPre(uCharacter& owner) const {
    return true;
}

bool cPawnActInterBase::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    return true;
}

__attribute__((weak)) bool cPawnActInterBase::moveActionGoto(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos, f32 range, f32 speed) {
    DDON_STUB("cPawnActInterBase::moveActionGoto")
    return {};
}

__attribute__((weak)) bool cPawnActInterBase::moveCmnAngle(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos) {
    DDON_STUB("cPawnActInterBase::moveCmnAngle")
    return {};
}

__attribute__((weak)) f32 cPawnActInterBase::calcMoveSpeed(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos) {
    DDON_STUB("cPawnActInterBase::calcMoveSpeed")
    return {};
}

__attribute__((weak)) bool cPawnActInterBase::calcMoveActionGoto(cPawnActInterIO& param, uCharacter& owner, MtVector3* pDstOfsPos, const cPawnEnableArea& area, f32 range, u32 targetIdx, f32 speed) {
    DDON_STUB("cPawnActInterBase::calcMoveActionGoto")
    return {};
}

__attribute__((weak)) bool cPawnActInterBase::isEnableEmClimbContinue(cPawnActInterIO& param, uCharacter& owner) const {
    DDON_STUB("cPawnActInterBase::isEnableEmClimbContinue")
    return {};
}

__attribute__((weak)) bool cPawnActInterBase::isEnableSkillRange(cPawnActInterIO& param, uCharacter& owner, u32 actNo) const {
    DDON_STUB("cPawnActInterBase::isEnableSkillRange")
    return {};
}

__attribute__((weak)) void cPawnActInterBase::getActionBtn(cPawnActInterIO& param, uCharacter& owner, u32 actNo, cpInput::unBtnInfo& dstTrg, cpInput::unBtnInfo& dstOn, bool isReady) {
    DDON_STUB("cPawnActInterBase::getActionBtn")
    /* stub */
}

__attribute__((weak)) void cPawnActInterBase::setResultAngle(cPawnActInterIO& param, uCharacter& owner, f32 angle) {
    DDON_STUB("cPawnActInterBase::setResultAngle")
    /* stub */
}

__attribute__((weak)) void cPawnActInterBase::setResultMove(cPawnActInterIO& param, uCharacter& owner, f32 angle, f32 speed) {
    DDON_STUB("cPawnActInterBase::setResultMove")
    /* stub */
}

__attribute__((weak)) void cPawnActInterBase::setResultMoveInfo(cPawnActInterIO& param, uCharacter& owner, f32 angle, f32 speed) {
    DDON_STUB("cPawnActInterBase::setResultMoveInfo")
    /* stub */
}

__attribute__((weak)) MtVector3 cPawnActInterBase::calcBowNetAimPos(cPawnActInterIO& param, uCharacter& owner, const MtVector3& pos) {
    DDON_STUB("cPawnActInterBase::calcBowNetAimPos")
    __builtin_unreachable();
}

__attribute__((weak)) void cPawnActInterBase::setResultBowNetAimPos(cPawnActInterIO& param, uCharacter& owner, const MtVector3& pos, bool upShot) {
    DDON_STUB("cPawnActInterBase::setResultBowNetAimPos")
    /* stub */
}

__attribute__((weak)) void cPawnActInterBase::setResultMagLockOnTarget(cPawnActInterIO& param, uCharacter& owner, cGeneralPoint* pTarget) {
    DDON_STUB("cPawnActInterBase::setResultMagLockOnTarget")
    /* stub */
}

__attribute__((weak)) bool cPawnActInterBase::moveActionGotoRouteInfoAction(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterBase::moveActionGotoRouteInfoAction")
    return {};
}

__attribute__((weak)) bool cPawnActInterBase::moveActionGotoOmBreak(cPawnActInterIO& param, uCharacter& owner, f32 angle) {
    DDON_STUB("cPawnActInterBase::moveActionGotoOmBreak")
    return {};
}

__attribute__((weak)) bool cPawnActInterBase::moveActionGotoLadder(cPawnActInterIO& param, uCharacter& owner, const stMoveAngleRet& ret) {
    DDON_STUB("cPawnActInterBase::moveActionGotoLadder")
    return {};
}

__attribute__((weak)) f32 cPawnActInterBase::moveActionGotoEscapeLadder(cPawnActInterIO& param, uCharacter& owner, const stMoveAngleRet& ret) {
    DDON_STUB("cPawnActInterBase::moveActionGotoEscapeLadder")
    return {};
}

__attribute__((weak)) bool cPawnActInterBase::moveArrowChange(cPawnActInterIO& param, uCharacter& owner, u32 arrowGroup, u32& localRno) {
    DDON_STUB("cPawnActInterBase::moveArrowChange")
    return {};
}

__attribute__((weak)) void cPawnActInterBase::setResultActNoPos(cPawnActInterIO& param, uCharacter& owner, u32 actNo, const MtVector3& pos, bool isReady, bool isForceOn) {
    DDON_STUB("cPawnActInterBase::setResultActNoPos")
    /* stub */
}

__attribute__((weak)) void cPawnActInterBase::setResultActNoInput(cPawnActInterIO& param, uCharacter& owner, u32 actNo, f32 angle, bool useAngle, bool isReady, bool isForceOn) {
    DDON_STUB("cPawnActInterBase::setResultActNoInput")
    /* stub */
}

inline cPawnActInterBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterBase::MyDTI cPawnActInterBase::DTI("cPawnActInterBase", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterBase::MyDTI::newInstance() const {
    return new (16u) cPawnActInterBase;
}

const MtDTI& cPawnActInterBreak::getDTI() const {
    return cPawnActInterBreak::DTI;
}

cPawnActInterBreak::cPawnActInterBreak() {
    DDON_STUB("cPawnActInterBreak::cPawnActInterBreak")
    /* stub */
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterBreak::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterBreak::updateInter")
    return {};
}

inline cPawnActInterBreak::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterBreak::MyDTI cPawnActInterBreak::DTI("cPawnActInterBreak", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterBreak::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterBreak::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterCliffClimb::getDTI() const {
    return cPawnActInterCliffClimb::DTI;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterCliffClimb::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterCliffClimb::updateInter")
    return {};
}

inline cPawnActInterCliffClimb::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterCliffClimb::MyDTI cPawnActInterCliffClimb::DTI("cPawnActInterCliffClimb", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterCliffClimb::MyDTI::newInstance() const {
    return new (16u) cPawnActInterCliffClimb;
}

const MtDTI& cPawnActInterClimbBegin::getDTI() const {
    return cPawnActInterClimbBegin::DTI;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterClimbBegin::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterClimbBegin::updateInter")
    return {};
}

inline cPawnActInterClimbBegin::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterClimbBegin::MyDTI cPawnActInterClimbBegin::DTI("cPawnActInterClimbBegin", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterClimbBegin::MyDTI::newInstance() const {
    return new (16u) cPawnActInterClimbBegin;
}

const MtDTI& cPawnActInterCommon::getDTI() const {
    return cPawnActInterCommon::DTI;
}

cPawnActInterCommon::cPawnActInterCommon() {
    DDON_STUB("cPawnActInterCommon::cPawnActInterCommon")
    /* stub */
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterCommon::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterCommon::updateInter")
    return {};
}

void cPawnActInterCommon::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
}

inline cPawnActInterCommon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterCommon::MyDTI cPawnActInterCommon::DTI("cPawnActInterCommon", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterCommon::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterCommon::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterDamage::getDTI() const {
    return cPawnActInterDamage::DTI;
}

cPawnActInterDamage::~cPawnActInterDamage() {
}

ACTINTER_CODERET cPawnActInterDamage::initInter(cPawnActInterIO& param, uCharacter& owner) {
    if (isUseEngetsu(param, owner)) {
        param.mFreeU32.elems[0] = 1;
    } else {
        if (isUseKamae(param, owner)) {
            param.mFreeU32.elems[0] = 2;
        } else {
            if (isUseTaima(param, owner)) {
                param.mFreeU32.elems[0] = 3;
            } else {
                if (isUseGoldBody(param, owner)) {
                    param.mFreeU32.elems[0] = 4;
                    mLifeFrame = 450.0f;
                } else {
                    if (isUseJob10CS02(param, owner)) {
                        param.mFreeU32.elems[0] = 5;
                    } else {
                        param.mFreeU32.elems[0] = 0;
                    }
                }
            }
        }
    }
    param.mFreeF32.elems[0] = sAIPawnSys::getInstance()->getPawnPrmF32("DMG_CN_FRM", 10.0f);
    param.mFreeU32.elems[1] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterDamage::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterDamage::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterDamage::isUseEngetsu(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterDamage::isUseEngetsu")
    return {};
}

__attribute__((weak)) bool cPawnActInterDamage::isUseKamae(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterDamage::isUseKamae")
    return {};
}

bool cPawnActInterDamage::isUseUkemi(cPawnActInterIO& param, uCharacter& owner) {
    if ((owner.mObjStatus & 8ul) != 0) {
        if ((owner.uDDOModel::mUnitId & 16u) != 0) {
            u8 t0 = cContextInterface::getJob(owner.mContextInterface.mpContextInstance);
            if (t0 == 7) {
                unsigned long t1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&owner) + 13376);
                if (t1 != 0) {
                    if (static_cast<unsigned char>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)) + 255) > 9) {
                        return false;
                    } else {
                        u32 t3 = nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)));
                        if (static_cast<int>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((t1 + (static_cast<unsigned long>(t3) * 40)) + (static_cast<unsigned long>(nHuman::getNormalSkillIdArrayIndex(nHuman::GROW_NORMAL_SKILL_ID_03)) * 4)) + 3176)) <= 0) {
                            return false;
                        } else {
                            return true;
                        }
                    }
                } else {
                    return false;
                }
            } else {
                if (t0 == 1) {
                    unsigned long t2 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&owner) + 13376);
                    if (t2 != 0) {
                        if (static_cast<unsigned char>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 40)) + 255) > 9) {
                            return false;
                        } else {
                            u32 t4 = nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 40)));
                            if (static_cast<int>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((t2 + (static_cast<unsigned long>(t4) * 40)) + (static_cast<unsigned long>(nHuman::getNormalSkillIdArrayIndex(nHuman::GROW_NORMAL_SKILL_ID_03)) * 4)) + 3176)) > 0) {
                                return true;
                            } else {
                                return false;
                            }
                        }
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) bool cPawnActInterDamage::isUseTaima(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterDamage::isUseTaima")
    return {};
}

__attribute__((weak)) bool cPawnActInterDamage::isUseGoldBody(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterDamage::isUseGoldBody")
    return {};
}

__attribute__((weak)) void cPawnActInterDamage::updateInterGoldBody(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterDamage::updateInterGoldBody")
    /* stub */
}

__attribute__((weak)) bool cPawnActInterDamage::isUseJob10CS02(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterDamage::isUseJob10CS02")
    return {};
}

inline cPawnActInterDamage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterDamage::MyDTI cPawnActInterDamage::DTI("cPawnActInterDamage", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterDamage::MyDTI::newInstance() const {
    return new (16u) cPawnActInterDamage;
}

const MtDTI& cPawnActInterDisableMgr::getDTI() const {
    return cPawnActInterDisableMgr::DTI;
}

void* cPawnActInterDisableMgr::operator new(size_t sz, u32 align) {
    return cPawnActInterDisableMgr::getAllocator()->memAlloc(sz, align, cPawnActInterDisableMgr::DTI.getID());
}

cPawnActInterDisableMgr::cPawnActInterDisableMgr() {
    DDON_STUB("cPawnActInterDisableMgr::cPawnActInterDisableMgr")
    /* stub */
}

__attribute__((weak)) void cPawnActInterDisableMgr::updatePawnActInterDisableMgr(f32 deltaTime) {
    DDON_STUB("cPawnActInterDisableMgr::updatePawnActInterDisableMgr")
    /* stub */
}

void cPawnActInterDisableMgr::updatePtr() {
    for (u32 i = 0; i != 512; i = i + 32u) {
        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(reinterpret_cast<char*>(this) + i) + 24)) != 0) {
            if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(reinterpret_cast<char*>(this) + i) + 24)) + 16)) & 7u) - 1u) > 1u) {
                *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(reinterpret_cast<char*>(this) + i) + 24) = 0;
            }
        }
    }
}

inline cPawnActInterDisableMgr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterDisableMgr::MyDTI cPawnActInterDisableMgr::DTI("cPawnActInterDisableMgr", &::cAIObject::DTI, 520ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterDisableMgr::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterDisableMgr::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterEnemyClimb::getDTI() const {
    return cPawnActInterEnemyClimb::DTI;
}

cPawnActInterEnemyClimb::~cPawnActInterEnemyClimb() {
}

__attribute__((weak)) bool cPawnActInterEnemyClimb::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterEnemyClimb::isEnableActInterTarget")
    return {};
}

ACTINTER_CODERET cPawnActInterEnemyClimb::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterEnemyClimb::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEnemyClimb::updateInter")
    return {};
}

void cPawnActInterEnemyClimb::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mEnemyStatus);
}

inline cPawnActInterEnemyClimb::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterEnemyClimb::MyDTI cPawnActInterEnemyClimb::DTI("cPawnActInterEnemyClimb", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterEnemyClimb::MyDTI::newInstance() const {
    return new (16u) cPawnActInterEnemyClimb;
}

const MtDTI& cPawnActInterEnemyClimbAttack::getDTI() const {
    return cPawnActInterEnemyClimbAttack::DTI;
}

cPawnActInterEnemyClimbAttack::~cPawnActInterEnemyClimbAttack() {
}

__attribute__((weak)) bool cPawnActInterEnemyClimbAttack::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterEnemyClimbAttack::isEnableActInterTarget")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterEnemyClimbAttack::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEnemyClimbAttack::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterEnemyClimbAttack::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEnemyClimbAttack::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterEnemyClimbAttack::isEndClimbAttack(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEnemyClimbAttack::isEndClimbAttack")
    return {};
}

void cPawnActInterEnemyClimbAttack::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mType);
    nDDOIO::readData(r, mTrgType);
    nDDOIO::readData(r, mClimbTargetOnly);
    mIsUseUpGradeSkill = r.readU8() != 0;
}

inline cPawnActInterEnemyClimbAttack::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterEnemyClimbAttack::MyDTI cPawnActInterEnemyClimbAttack::DTI("cPawnActInterEnemyClimbAttack", &::cPawnActInterBase::DTI, 32ul, 0u, 0u);

MtObject* cPawnActInterEnemyClimbAttack::MyDTI::newInstance() const {
    return new (16u) cPawnActInterEnemyClimbAttack;
}

const MtDTI& cPawnActInterEnemyClimbMove::getDTI() const {
    return cPawnActInterEnemyClimbMove::DTI;
}

cPawnActInterEnemyClimbMove::~cPawnActInterEnemyClimbMove() {
    DDON_STUB("cPawnActInterEnemyClimbMove::~cPawnActInterEnemyClimbMove")
    /* stub */
}

__attribute__((weak)) bool cPawnActInterEnemyClimbMove::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterEnemyClimbMove::isEnableActInterTarget")
    return {};
}

ACTINTER_CODERET cPawnActInterEnemyClimbMove::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeF32.elems[0] = 0.0f;
    param.mFreeF32.elems[1] = 0.0f;
    param.mFreeF32.elems[2] = 0.0f;
    param.mFreeU32.elems[0] = 0;
    param.mFreeRealPos.elems[0].x = 0.0f;
    param.mFreeRealPos.elems[0].y = 0.0f;
    param.mFreeRealPos.elems[0].z = 0.0f;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterEnemyClimbMove::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEnemyClimbMove::updateInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterEnemyClimbMove::updateMoveInfo(cPawnActInterIO& param, uCharacter& owner, const MtVector3& targetPos) {
    DDON_STUB("cPawnActInterEnemyClimbMove::updateMoveInfo")
    return {};
}

__attribute__((weak)) bool cPawnActInterEnemyClimbMove::isEnableGoalHangPos(cPawnActInterIO& param, uCharacter& owner, MtVector3& targetPos, f32 range) {
    DDON_STUB("cPawnActInterEnemyClimbMove::isEnableGoalHangPos")
    return {};
}

void cPawnActInterEnemyClimbMove::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(&mOptFlag), t0 * 4u);
}

inline cPawnActInterEnemyClimbMove::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterEnemyClimbMove::MyDTI cPawnActInterEnemyClimbMove::DTI("cPawnActInterEnemyClimbMove", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterEnemyClimbMove::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterEnemyClimbMove::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterEscape::getDTI() const {
    return cPawnActInterEscape::DTI;
}

ACTINTER_CODERET cPawnActInterEscape::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterEscape::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscape::updateInter")
    return {};
}

void cPawnActInterEscape::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mAngle);
}

inline cPawnActInterEscape::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterEscape::MyDTI cPawnActInterEscape::DTI("cPawnActInterEscape", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterEscape::MyDTI::newInstance() const {
    return new (16u) cPawnActInterEscape;
}

const MtDTI& cPawnActInterEscapeNotice::getDTI() const {
    return cPawnActInterEscapeNotice::DTI;
}

cPawnActInterEscapeNotice::~cPawnActInterEscapeNotice() {
}

ACTINTER_CODERET cPawnActInterEscapeNotice::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeF32.elems[0] = 0.0f;
    param.mFreeF32.elems[1] = 0.0f;
    param.mFreeU32.elems[2] = 0;
    param.mFreeU32.elems[3] = 0;
    param.mFreeU32.elems[0] = 0;
    param.mFreeU32.elems[1] = 0;
    param.mFreeRealPos.elems[0] = MtVector3::Zero;
    param.mFreeF32.elems[2] = 0.0f;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterEscapeNotice::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterEscapeNotice::updateTypeJump(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeJump")
    return {};
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeGuard(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeGuard")
    /* stub */
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeBackStep(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeBackStep")
    /* stub */
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeActCommon(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeActCommon")
    /* stub */
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscapeType(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscapeType")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscapeTypeNotice1(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscapeTypeNotice1")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscapeTypeNotice2(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscapeTypeNotice2")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice1Dash(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice1Dash")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice1BackStep(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice1BackStep")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice1CenturionSpike(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice1CenturionSpike")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice1MushinKiri(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice1MushinKiri")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice2Counter(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice2Counter")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice2Atemi(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice2Atemi")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice2GardNormal(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice2GardNormal")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscapeTypeNotice1GuardImpact(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscapeTypeNotice1GuardImpact")
    return {};
}

__attribute__((weak)) bool cPawnActInterEscapeNotice::calcEscapeSafePos(cPawnActInterIO& param, uCharacter& owner, MtVector3& tar_pos, bool check_jump, bool is_dush_now) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscapeSafePos")
    return {};
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeEvasion(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeEvasion")
    /* stub */
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeCenturionSpike(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeCenturionSpike")
    /* stub */
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice2GardCustom(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice2GardCustom")
    return {};
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeKawashiKiri(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeKawashiKiri")
    /* stub */
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice2NormalSp(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice2NormalSp")
    return {};
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice2Taima(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice2Taima")
    return {};
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeGoldBody(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeGoldBody")
    /* stub */
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice2GoldBody(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice2GoldBody")
    return {};
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeShoryutate(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeShoryutate")
    /* stub */
}

__attribute__((weak)) void cPawnActInterEscapeNotice::updateTypeGuardImpact(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterEscapeNotice::updateTypeGuardImpact")
    /* stub */
}

__attribute__((weak)) u32 cPawnActInterEscapeNotice::calcEscaleTypeNotice2DolsTrap(cPawnActInterIO& param, uCharacter& owner, u32 noticeFlag) {
    DDON_STUB("cPawnActInterEscapeNotice::calcEscaleTypeNotice2DolsTrap")
    return {};
}

void cPawnActInterEscapeNotice::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mNoticeFlag);
}

inline cPawnActInterEscapeNotice::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterEscapeNotice::MyDTI cPawnActInterEscapeNotice::DTI("cPawnActInterEscapeNotice", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterEscapeNotice::MyDTI::newInstance() const {
    return new (16u) cPawnActInterEscapeNotice;
}

const MtDTI& cPawnActInterFree::getDTI() const {
    return cPawnActInterFree::DTI;
}

cPawnActInterFree::~cPawnActInterFree() {
}

inline cPawnActInterFree::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterFree::MyDTI cPawnActInterFree::DTI("cPawnActInterFree", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterFree::MyDTI::newInstance() const {
    return new (16u) cPawnActInterFree;
}

const MtDTI& cPawnActInterGuard::getDTI() const {
    return cPawnActInterGuard::DTI;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterGuard::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterGuard::updateInter")
    return {};
}

void cPawnActInterGuard::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    cOptFlag* held0 = &mOptFlag;
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(held0), t0 * 4u);
    nDDOIO::readData(r, mMinGuardTime);
}

inline cPawnActInterGuard::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterGuard::MyDTI cPawnActInterGuard::DTI("cPawnActInterGuard", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterGuard::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterGuard::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterGuardCancel::getDTI() const {
    return cPawnActInterGuardCancel::DTI;
}

ACTINTER_CODERET cPawnActInterGuardCancel::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    param.mFreeU32.elems[1] = calcGcActType(param, owner);
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterGuardCancel::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterGuardCancel::updateInter")
    return {};
}

__attribute__((weak)) u32 cPawnActInterGuardCancel::calcGcActType(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterGuardCancel::calcGcActType")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterGuardCancel::updateTypeGCHate(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterGuardCancel::updateTypeGCHate")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterGuardCancel::updateTypeGCBackStep(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterGuardCancel::updateTypeGCBackStep")
    return {};
}

inline cPawnActInterGuardCancel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterGuardCancel::MyDTI cPawnActInterGuardCancel::DTI("cPawnActInterGuardCancel", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterGuardCancel::MyDTI::newInstance() const {
    return new (16u) cPawnActInterGuardCancel;
}

const MtDTI& cPawnActInterHold::getDTI() const {
    return cPawnActInterHold::DTI;
}

cPawnActInterHold::~cPawnActInterHold() {
}

__attribute__((weak)) bool cPawnActInterHold::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterHold::isEnableActInterTarget")
    return {};
}

ACTINTER_CODERET cPawnActInterHold::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterHold::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterHold::updateInter")
    return {};
}

inline cPawnActInterHold::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterHold::MyDTI cPawnActInterHold::DTI("cPawnActInterHold", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterHold::MyDTI::newInstance() const {
    return new (16u) cPawnActInterHold;
}

const MtDTI& cPawnActInterHoldWait::getDTI() const {
    return cPawnActInterHoldWait::DTI;
}

cPawnActInterHoldWait::~cPawnActInterHoldWait() {
}

__attribute__((weak)) bool cPawnActInterHoldWait::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterHoldWait::isEnableActInterTarget")
    return {};
}

ACTINTER_CODERET cPawnActInterHoldWait::initInter(cPawnActInterIO& param, uCharacter& owner) {
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterHoldWait::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterHoldWait::updateInter")
    return {};
}

inline cPawnActInterHoldWait::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterHoldWait::MyDTI cPawnActInterHoldWait::DTI("cPawnActInterHoldWait", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterHoldWait::MyDTI::newInstance() const {
    return new (16u) cPawnActInterHoldWait;
}

__attribute__((weak)) bool cPawnActInterIO::calcTargetOfsPos(MtVector3* pDstOfsPos, u32 targetIdx) {
    DDON_STUB("cPawnActInterIO::calcTargetOfsPos")
    return {};
}

__attribute__((weak)) cGeneralPoint* cPawnActInterIO::getTargetGeneralPoint(u32 targetIdx) {
    DDON_STUB("cPawnActInterIO::getTargetGeneralPoint")
    return nullptr;
}

cAITargetInfo* cPawnActInterIO::getNearEnemyTargetInfo(const MtVector3& pos, f32 maxLen) {
    if (mInParam.mpEnemyList != nullptr) {
        return mInParam.mpEnemyList->findNear(pos, maxLen);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) bool cPawnActInterIO::checkFunAttack(cAITargetInfo* pTarget, void* pParam) {
    DDON_STUB("cPawnActInterIO::checkFunAttack")
    return {};
}

__attribute__((weak)) bool cPawnActInterIO::checkFunAttackLv(cAITargetInfo* pTarget, void* pParam) {
    DDON_STUB("cPawnActInterIO::checkFunAttackLv")
    return {};
}

const MtDTI& cPawnActInterIfLen::getDTI() const {
    return cPawnActInterIfLen::DTI;
}

cPawnActInterIfLen::~cPawnActInterIfLen() {
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterIfLen::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterIfLen::updateInter")
    return {};
}

void cPawnActInterIfLen::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mEnableArea.load(r);
}

inline cPawnActInterIfLen::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterIfLen::MyDTI cPawnActInterIfLen::DTI("cPawnActInterIfLen", &::cPawnActInterBase::DTI, 48ul, 0u, 0u);

MtObject* cPawnActInterIfLen::MyDTI::newInstance() const {
    return new (16u) cPawnActInterIfLen;
}

const MtDTI& cPawnActInterLantern::getDTI() const {
    return cPawnActInterLantern::DTI;
}

cPawnActInterLantern::~cPawnActInterLantern() {
}

__attribute__((weak)) bool cPawnActInterLantern::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterLantern::isEnableActInterTarget")
    return {};
}

ACTINTER_CODERET cPawnActInterLantern::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    if (mOnLantern) {
        owner.catchAbnormalCondition(12291u, nObjCondition::OCD_REASON_NONE, -1.0f, false);
    } else {
        owner.recoverAbnormalCondition(12291u);
    }
    return ACTINTER_CODERET_END;
}

void cPawnActInterLantern::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mOnLantern);
}

inline cPawnActInterLantern::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterLantern::MyDTI cPawnActInterLantern::DTI("cPawnActInterLantern", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterLantern::MyDTI::newInstance() const {
    return new (16u) cPawnActInterLantern;
}

const MtDTI& cPawnActInterMove::getDTI() const {
    return cPawnActInterMove::DTI;
}

cPawnActInterMove::~cPawnActInterMove() {
    DDON_STUB("cPawnActInterMove::~cPawnActInterMove")
    /* stub */
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMove::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMove::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMove::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMove::updateInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMove::updateInterEx(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMove::updateInterEx")
    return {};
}

__attribute__((weak)) bool cPawnActInterMove::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterMove::isEnableActInterTarget")
    return {};
}

__attribute__((weak)) MtVector3 cPawnActInterMove::calcFollowBattlePos(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMove::calcFollowBattlePos")
    __builtin_unreachable();
}

void cPawnActInterMove::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    mMovePosType = r.readU32();
    mEnableRangeActNo = r.readS32();
    mNearRange = r.readF32();
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(&mOptFlag), t0 * 4u);
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMove::updateInterHikiyose(cPawnActInterIO& param, uCharacter& owner, const MtVector3& tgtPos) {
    DDON_STUB("cPawnActInterMove::updateInterHikiyose")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMove::updateInterWire(cPawnActInterIO& param, uCharacter& owner, const MtVector3& tgtPos) {
    DDON_STUB("cPawnActInterMove::updateInterWire")
    return {};
}

inline cPawnActInterMove::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterMove::MyDTI cPawnActInterMove::DTI("cPawnActInterMove", &::cPawnActInterBase::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterMove::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterMove::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterMoveAlchemyTrap::getDTI() const {
    return cPawnActInterMoveAlchemyTrap::DTI;
}

ACTINTER_CODERET cPawnActInterMoveAlchemyTrap::initInter(cPawnActInterIO& param, uCharacter& owner) {
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMoveAlchemyTrap::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveAlchemyTrap::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterMoveAlchemyTrap::calcMovePos(MtVector3& dst, cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveAlchemyTrap::calcMovePos")
    return {};
}

inline cPawnActInterMoveAlchemyTrap::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterMoveAlchemyTrap::MyDTI cPawnActInterMoveAlchemyTrap::DTI("cPawnActInterMoveAlchemyTrap", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterMoveAlchemyTrap::MyDTI::newInstance() const {
    return new (16u) cPawnActInterMoveAlchemyTrap;
}

const MtDTI& cPawnActInterMoveEnergySpot::getDTI() const {
    return cPawnActInterMoveEnergySpot::DTI;
}

ACTINTER_CODERET cPawnActInterMoveEnergySpot::initInter(cPawnActInterIO& param, uCharacter& owner) {
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMoveEnergySpot::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveEnergySpot::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterMoveEnergySpot::calcMovePos(MtVector3& dst, cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveEnergySpot::calcMovePos")
    return {};
}

inline cPawnActInterMoveEnergySpot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterMoveEnergySpot::MyDTI cPawnActInterMoveEnergySpot::DTI("cPawnActInterMoveEnergySpot", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterMoveEnergySpot::MyDTI::newInstance() const {
    return new (16u) cPawnActInterMoveEnergySpot;
}

const MtDTI& cPawnActInterMoveJump::getDTI() const {
    return cPawnActInterMoveJump::DTI;
}

ACTINTER_CODERET cPawnActInterMoveJump::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    param.mFreeF32.elems[0] = 0.0f;
    param.mFreeU32.elems[1] = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&owner) + 8944)) >> 1) & 1u;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMoveJump::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveJump::updateInter")
    return {};
}

void cPawnActInterMoveJump::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mJumpFlag);
    nDDOIO::readData(r, mHeightCheckLow);
    nDDOIO::readData(r, mHeightCheckHigh);
}

inline cPawnActInterMoveJump::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterMoveJump::MyDTI cPawnActInterMoveJump::DTI("cPawnActInterMoveJump", &::cPawnActInterBase::DTI, 32ul, 0u, 0u);

MtObject* cPawnActInterMoveJump::MyDTI::newInstance() const {
    return new (16u) cPawnActInterMoveJump;
}

const MtDTI& cPawnActInterMoveLightingAnchor::getDTI() const {
    return cPawnActInterMoveLightingAnchor::DTI;
}

ACTINTER_CODERET cPawnActInterMoveLightingAnchor::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeF32.elems[0] = 0.0f;
    param.mFreeRealPos.elems[0] = MtVector3::Zero;
    param.mFreeU32.elems[0] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMoveLightingAnchor::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveLightingAnchor::updateInter")
    return {};
}

__attribute__((weak)) u32 cPawnActInterMoveLightingAnchor::calcMovePos(MtVector3& dst, cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveLightingAnchor::calcMovePos")
    return {};
}

inline cPawnActInterMoveLightingAnchor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterMoveLightingAnchor::MyDTI cPawnActInterMoveLightingAnchor::DTI("cPawnActInterMoveLightingAnchor", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterMoveLightingAnchor::MyDTI::newInstance() const {
    return new (16u) cPawnActInterMoveLightingAnchor;
}

const MtDTI& cPawnActInterMoveReksElement::getDTI() const {
    return cPawnActInterMoveReksElement::DTI;
}

__attribute__((weak)) bool cPawnActInterMoveReksElement::isEnableActInterPre(uCharacter& owner) const {
    DDON_STUB("cPawnActInterMoveReksElement::isEnableActInterPre")
    return {};
}

ACTINTER_CODERET cPawnActInterMoveReksElement::initInter(cPawnActInterIO& param, uCharacter& owner) {
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterMoveReksElement::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveReksElement::updateInter")
    return {};
}

__attribute__((weak)) bool cPawnActInterMoveReksElement::calcMovePos(MtVector3& dst, cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterMoveReksElement::calcMovePos")
    return {};
}

inline cPawnActInterMoveReksElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterMoveReksElement::MyDTI cPawnActInterMoveReksElement::DTI("cPawnActInterMoveReksElement", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterMoveReksElement::MyDTI::newInstance() const {
    return new (16u) cPawnActInterMoveReksElement;
}

const MtDTI& cPawnActInterRecover::getDTI() const {
    return cPawnActInterRecover::DTI;
}

cPawnActInterRecover::~cPawnActInterRecover() {
}

__attribute__((weak)) bool cPawnActInterRecover::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterRecover::isEnableActInterTarget")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterRecover::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterRecover::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterRecover::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterRecover::updateInter")
    return {};
}

void cPawnActInterRecover::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mIsTargetErosion);
}

inline cPawnActInterRecover::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterRecover::MyDTI cPawnActInterRecover::DTI("cPawnActInterRecover", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterRecover::MyDTI::newInstance() const {
    return new (16u) cPawnActInterRecover;
}

const MtDTI& cPawnActInterReload::getDTI() const {
    return cPawnActInterReload::DTI;
}

cPawnActInterReload::~cPawnActInterReload() {
}

bool cPawnActInterReload::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    cpComponent* t0 = owner.mComponentMgr.getRootComponent()->find(cpJob03::DTI, true, true);
    if (t0 != nullptr) {
        if ((owner.uDDOModel::mUnitId & 1152u) != 0) {
            u32 arrow_num = static_cast<cpJob03*>(t0)->getArrowNum();
            if (arrow_num == (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 100))) {
                return false;
            } else {
                return true;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

ACTINTER_CODERET cPawnActInterReload::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    param.mFreeF32.elems[0] = 0.0f;
    u32 t0 = mReloadType;
    float t1 = 15.0f;
    if (t0 != 1) {
        if (t0 == 2) {
            cContextInstance* t2 = owner.mContextInterface.mpContextInstance;
            cContextCharacter* t3 = owner.mContextInterface.mpContextCharacter;
            u32 lv = cContextInterface::getLv(t2, t3);
            if (lv <= 10u) {
                sAIPawnSys* t4 = sAIPawnSys::getInstance();
                float t5 = 0.2f;
                f32 t11 = t4->getPawnPrmF32("RELOAD_RATE_LV10", t5);
                u32 t12 = MtRandom::instance.nrand();
                float t13 = 2.3283064e-10f;
                float t14 = 15.0f;
                if ((t13 * static_cast<float>(t12)) > t11) {
                    float t15 = 24.0f;
                    param.mFreeF32.elems[1] = t15;
                    return ACTINTER_CODERET_END;
                } else {
                    param.mFreeF32.elems[1] = t14;
                    return ACTINTER_CODERET_END;
                }
            } else {
                if (lv <= 20u) {
                    sAIPawnSys* t6 = sAIPawnSys::getInstance();
                    float t7 = 0.35f;
                    f32 t11 = t6->getPawnPrmF32("RELOAD_RATE_LV20", t7);
                    u32 t12 = MtRandom::instance.nrand();
                    float t13 = 2.3283064e-10f;
                    float t14 = 15.0f;
                    if ((t13 * static_cast<float>(t12)) > t11) {
                        float t15 = 24.0f;
                        param.mFreeF32.elems[1] = t15;
                        return ACTINTER_CODERET_END;
                    } else {
                        param.mFreeF32.elems[1] = t14;
                        return ACTINTER_CODERET_END;
                    }
                } else {
                    sAIPawnSys* t8 = sAIPawnSys::getInstance();
                    if (lv <= 30u) {
                        float t9 = 0.5f;
                        f32 t11 = t8->getPawnPrmF32("RELOAD_RATE_LV30", t9);
                        u32 t12 = MtRandom::instance.nrand();
                        float t13 = 2.3283064e-10f;
                        float t14 = 15.0f;
                        if ((t13 * static_cast<float>(t12)) > t11) {
                            float t15 = 24.0f;
                            param.mFreeF32.elems[1] = t15;
                            return ACTINTER_CODERET_END;
                        } else {
                            param.mFreeF32.elems[1] = t14;
                            return ACTINTER_CODERET_END;
                        }
                    } else {
                        float t10 = 0.75f;
                        f32 t11 = t8->getPawnPrmF32("RELOAD_RATE_LVMAX", t10);
                        u32 t12 = MtRandom::instance.nrand();
                        float t13 = 2.3283064e-10f;
                        float t14 = 15.0f;
                        if ((t13 * static_cast<float>(t12)) > t11) {
                            float t15 = 24.0f;
                            param.mFreeF32.elems[1] = t15;
                            return ACTINTER_CODERET_END;
                        } else {
                            param.mFreeF32.elems[1] = t14;
                            return ACTINTER_CODERET_END;
                        }
                    }
                }
            }
        } else {
            float t15 = 24.0f;
            param.mFreeF32.elems[1] = t15;
            return ACTINTER_CODERET_END;
        }
    } else {
        param.mFreeF32.elems[1] = t1;
        return ACTINTER_CODERET_END;
    }
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterReload::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterReload::updateInter")
    return {};
}

void cPawnActInterReload::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mReloadType);
}

inline cPawnActInterReload::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterReload::MyDTI cPawnActInterReload::DTI("cPawnActInterReload", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterReload::MyDTI::newInstance() const {
    return new (16u) cPawnActInterReload;
}

const MtDTI& cPawnActInterRot::getDTI() const {
    return cPawnActInterRot::DTI;
}

cPawnActInterRot::~cPawnActInterRot() {
}

ACTINTER_CODERET cPawnActInterRot::initInter(cPawnActInterIO& param, uCharacter& owner) {
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterRot::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterRot::updateInter")
    return {};
}

inline cPawnActInterRot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterRot::MyDTI cPawnActInterRot::DTI("cPawnActInterRot", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterRot::MyDTI::newInstance() const {
    return new (16u) cPawnActInterRot;
}

const MtDTI& cPawnActInterSearchCorePoint::getDTI() const {
    return cPawnActInterSearchCorePoint::DTI;
}

__attribute__((weak)) bool cPawnActInterSearchCorePoint::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterSearchCorePoint::isEnableActInterTarget")
    return {};
}

ACTINTER_CODERET cPawnActInterSearchCorePoint::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[1] = getActiveCorePointNum(param, owner);
    param.mFreeU32.elems[2] = 0x7FFFFFFF;
    param.mAIRetPawnSituation = 40;
    return ACTINTER_CODERET_END;
}

ACTINTER_CODERET cPawnActInterSearchCorePoint::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    u8 t0 = cContextInterface::getJob(owner.mContextInterface.mpContextInstance);
    if (t0 != 10) {
        if (t0 == 8) {
            return updateInterJob08(param, owner);
        } else {
            if (t0 == 4) {
                return updateInterJob04(param, owner);
            } else {
                return ACTINTER_CODERET_END;
            }
        }
    } else {
        return updateInterJob10(param, owner);
    }
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterSearchCorePoint::updateInterJob04(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchCorePoint::updateInterJob04")
    return {};
}

__attribute__((weak)) bool cPawnActInterSearchCorePoint::isEncActionJob04(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchCorePoint::isEncActionJob04")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterSearchCorePoint::updateInterJob08(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchCorePoint::updateInterJob08")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterSearchCorePoint::updateInterJob10(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchCorePoint::updateInterJob10")
    return {};
}

__attribute__((weak)) u32 cPawnActInterSearchCorePoint::getActiveCorePointNum(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchCorePoint::getActiveCorePointNum")
    return {};
}

void cPawnActInterSearchCorePoint::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    u32 t0 = r.readU32();
    r.read(static_cast<void*>(&mOptFlag), t0 * 4u);
}

inline cPawnActInterSearchCorePoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterSearchCorePoint::MyDTI cPawnActInterSearchCorePoint::DTI("cPawnActInterSearchCorePoint", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterSearchCorePoint::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterSearchCorePoint::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cPawnActInterSearchMaskPoint::getDTI() const {
    return cPawnActInterSearchMaskPoint::DTI;
}

__attribute__((weak)) bool cPawnActInterSearchMaskPoint::isEnableActInterTarget(uCharacter& owner, cGeneralPoint* pTarget, u32 baseActNo, const cPawnEnableArea* pEnableArea, const MtVector3* pEnableAreaPos) const {
    DDON_STUB("cPawnActInterSearchMaskPoint::isEnableActInterTarget")
    return {};
}

ACTINTER_CODERET cPawnActInterSearchMaskPoint::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[1] = getActiveCorePointNum(param, owner);
    param.mFreeU32.elems[2] = 0x7FFFFFFF;
    return ACTINTER_CODERET_END;
}

ACTINTER_CODERET cPawnActInterSearchMaskPoint::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    u8 t0 = cContextInterface::getJob(owner.mContextInterface.mpContextInstance);
    if (t0 != 10) {
        if (t0 == 8) {
            return updateInterJob08(param, owner);
        } else {
            if (t0 == 4) {
                return updateInterJob04(param, owner);
            } else {
                return ACTINTER_CODERET_END;
            }
        }
    } else {
        return updateInterJob10(param, owner);
    }
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterSearchMaskPoint::updateInterJob04(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchMaskPoint::updateInterJob04")
    return {};
}

__attribute__((weak)) bool cPawnActInterSearchMaskPoint::isEncActionJob04(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchMaskPoint::isEncActionJob04")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterSearchMaskPoint::updateInterJob08(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchMaskPoint::updateInterJob08")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterSearchMaskPoint::updateInterJob10(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchMaskPoint::updateInterJob10")
    return {};
}

__attribute__((weak)) u32 cPawnActInterSearchMaskPoint::getActiveCorePointNum(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchMaskPoint::getActiveCorePointNum")
    return {};
}

__attribute__((weak)) u32 cPawnActInterSearchMaskPoint::getActiveCorePointAllNum(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterSearchMaskPoint::getActiveCorePointAllNum")
    return {};
}

void cPawnActInterSearchMaskPoint::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
}

inline cPawnActInterSearchMaskPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterSearchMaskPoint::MyDTI cPawnActInterSearchMaskPoint::DTI("cPawnActInterSearchMaskPoint", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterSearchMaskPoint::MyDTI::newInstance() const {
    return new (16u) cPawnActInterSearchMaskPoint;
}

const MtDTI& cPawnActInterStandOff::getDTI() const {
    return cPawnActInterStandOff::DTI;
}

cPawnActInterStandOff::~cPawnActInterStandOff() {
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterStandOff::initInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterStandOff::initInter")
    return {};
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterStandOff::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterStandOff::updateInter")
    return {};
}

__attribute__((weak)) MtVector3 cPawnActInterStandOff::calcStandOffPos(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterStandOff::calcStandOffPos")
    __builtin_unreachable();
}

void cPawnActInterStandOff::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mStandOffFrame);
}

inline cPawnActInterStandOff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterStandOff::MyDTI cPawnActInterStandOff::DTI("cPawnActInterStandOff", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterStandOff::MyDTI::newInstance() const {
    return new (16u) cPawnActInterStandOff;
}

const MtDTI& cPawnActInterStandOffHmEm::getDTI() const {
    return cPawnActInterStandOffHmEm::DTI;
}

cPawnActInterStandOffHmEm::~cPawnActInterStandOffHmEm() {
}

ACTINTER_CODERET cPawnActInterStandOffHmEm::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    param.mFreeF32.elems[0] = 0.0f;
    param.mFreeF32.elems[1] = 0.0f;
    param.mUserEnableArea.mMinXZ = 0.0f;
    param.mUserEnableArea.mMaxXZ = 300.0f;
    param.mUserEnableArea.mMinY = -300.0f;
    param.mUserEnableArea.mMaxY = 300.0f;
    param.mUserEnableArea.mRadius = 0.0f;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterStandOffHmEm::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterStandOffHmEm::updateInter")
    return {};
}

void cPawnActInterStandOffHmEm::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mRoateR);
    nDDOIO::readData(r, mStandOffFrame);
}

inline cPawnActInterStandOffHmEm::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterStandOffHmEm::MyDTI cPawnActInterStandOffHmEm::DTI("cPawnActInterStandOffHmEm", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterStandOffHmEm::MyDTI::newInstance() const {
    return new (16u) cPawnActInterStandOffHmEm;
}

const MtDTI& cPawnActInterTalkToPl::getDTI() const {
    return cPawnActInterTalkToPl::DTI;
}

ACTINTER_CODERET cPawnActInterTalkToPl::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    if (owner.getActMgrPtr() != nullptr) {
        if (owner.getActMgrPtr()->getActionNo() != 382) {
            param.mAIRetActNoReq = 382;
        }
        return ACTINTER_CODERET_END;
    } else {
        return ACTINTER_CODERET_BREAK;
    }
}

inline cPawnActInterTalkToPl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterTalkToPl::MyDTI cPawnActInterTalkToPl::DTI("cPawnActInterTalkToPl", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterTalkToPl::MyDTI::newInstance() const {
    return new (16u) cPawnActInterTalkToPl;
}

const MtDTI& cPawnActInterWait::getDTI() const {
    return cPawnActInterWait::DTI;
}

cPawnActInterWait::~cPawnActInterWait() {
}

ACTINTER_CODERET cPawnActInterWait::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    return ACTINTER_CODERET_END;
}

__attribute__((weak)) ACTINTER_CODERET cPawnActInterWait::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterWait::updateInter")
    return {};
}

void cPawnActInterWait::load(MtDataReader& r) {
    mLifeFrame = r.readF32();
    mDisableNotice = r.readU32();
    nDDOIO::readData(r, mOrderClear);
    nDDOIO::readData(r, mWaitTime);
}

inline cPawnActInterWait::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterWait::MyDTI cPawnActInterWait::DTI("cPawnActInterWait", &::cPawnActInterBase::DTI, 24ul, 0u, 0u);

MtObject* cPawnActInterWait::MyDTI::newInstance() const {
    return new (16u) cPawnActInterWait;
}

const MtDTI& cPawnActInterWaitFootwork::getDTI() const {
    return cPawnActInterWaitFootwork::DTI;
}

cPawnActInterWaitFootwork::cPawnActInterWaitFootwork() {
}

ACTINTER_CODERET cPawnActInterWaitFootwork::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    if ((owner.uDDOModel::mUnitId & 16u) != 0) {
        if (static_cast<uHuman*>(&owner)->isFootWork()) {
            return ACTINTER_CODERET_END;
        } else {
            return ACTINTER_CODERET_CONTINUE;
        }
    } else {
        return ACTINTER_CODERET_END;
    }
}

inline cPawnActInterWaitFootwork::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterWaitFootwork::MyDTI cPawnActInterWaitFootwork::DTI("cPawnActInterWaitFootwork", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterWaitFootwork::MyDTI::newInstance() const {
    return new (16u) cPawnActInterWaitFootwork;
}

const MtDTI& cPawnActInterWarp::getDTI() const {
    return cPawnActInterWarp::DTI;
}

cPawnActInterWarp::~cPawnActInterWarp() {
}

ACTINTER_CODERET cPawnActInterWarp::initInter(cPawnActInterIO& param, uCharacter& owner) {
    param.mFreeU32.elems[0] = 0;
    param.mFreeF32.elems[0] = 0.0f;
    return ACTINTER_CODERET_END;
}

ACTINTER_CODERET cPawnActInterWarp::updateInter(cPawnActInterIO& param, uCharacter& owner) {
    if (param.mFreeU32.elems[0] == 1) {
        MtVector3 target_pos;
        if (param.calcTargetOfsPos(&target_pos, 0u)) {
            param.mAIRetReqWarp = true;
            MtVector3 frame56(sWorldOffset::getInstance()->getRealPos(target_pos));
            param.mAIRetWarpRealPos.x = frame56.x;
            param.mAIRetWarpRealPos.y = frame56.y;
            param.mAIRetWarpRealPos.z = frame56.z;
            param.mAIRetWarpRealPos.pad_ = 0.0f;
            return ACTINTER_CODERET_END;
        } else {
            return ACTINTER_CODERET_BREAK;
        }
    } else {
        if (param.mFreeU32.elems[0] == 0) {
            param.mFreeF32.elems[0] = owner.getDeltaTime() + param.mFreeF32.elems[0];
            if (param.mFreeF32.elems[0] > 5.0f) {
                param.mFreeU32.elems[0] = 1;
            }
            return ACTINTER_CODERET_CONTINUE;
        } else {
            return ACTINTER_CODERET_BREAK;
        }
    }
}

inline cPawnActInterWarp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterWarp::MyDTI cPawnActInterWarp::DTI("cPawnActInterWarp", &::cPawnActInterBase::DTI, 16ul, 0u, 0u);

MtObject* cPawnActInterWarp::MyDTI::newInstance() const {
    return new (16u) cPawnActInterWarp;
}

const MtDTI& cPawnActInterface::getDTI() const {
    return cPawnActInterface::DTI;
}

cPawnActInterface::cPawnActInterface() {
    DDON_STUB("cPawnActInterface::cPawnActInterface")
    /* stub */
}

cPawnActInterface::~cPawnActInterface() {
}

__attribute__((weak)) void cPawnActInterface::updateActInterface(uCharacter& owner) {
    DDON_STUB("cPawnActInterface::updateActInterface")
    /* stub */
}

__attribute__((weak)) void cPawnActInterface::updateActInterfaceAfter(uCharacter& owner) {
    DDON_STUB("cPawnActInterface::updateActInterfaceAfter")
    /* stub */
}

__attribute__((weak)) void cPawnActInterface::resetActInter() {
    DDON_STUB("cPawnActInterface::resetActInter")
    /* stub */
}

void cPawnActInterface::addPawnActInterPre(cPawnActInterBase* pCode) {
    if (pCode == nullptr) {
        return;
    }
    u32 t0 = mActIntersPre.mLength;
    u32 t1 = mActIntersPre.mBufsiz;
    if (t0 < t1) {
        mActIntersPre.mLength = t0 + 1u;
        mActIntersPre.mpArray[t0] = static_cast<MtObject*>(pCode);
    } else {
        void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
        memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
        memcpy(t2, static_cast<const void*>(mActIntersPre.mpArray), static_cast<size_t>(mActIntersPre.mLength) * 8);
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mActIntersPre.mpArray));
        mActIntersPre.mpArray = static_cast<MtObject* *>(t2);
        mActIntersPre.mBufsiz = t1 + 32u;
        u32 t3 = mActIntersPre.mLength;
        mActIntersPre.mLength = t3 + 1u;
        mActIntersPre.mpArray[t3] = static_cast<MtObject*>(pCode);
    }
}

void cPawnActInterface::addPawnActInter(cPawnActInterBase* pCode) {
    if (pCode == nullptr) {
        return;
    }
    u32 t0 = mActIntersMain.mLength;
    u32 t1 = mActIntersMain.mBufsiz;
    if (t0 < t1) {
        mActIntersMain.mLength = t0 + 1u;
        mActIntersMain.mpArray[t0] = static_cast<MtObject*>(pCode);
    } else {
        void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
        memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
        memcpy(t2, static_cast<const void*>(mActIntersMain.mpArray), static_cast<size_t>(mActIntersMain.mLength) * 8);
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mActIntersMain.mpArray));
        mActIntersMain.mpArray = static_cast<MtObject* *>(t2);
        mActIntersMain.mBufsiz = t1 + 32u;
        u32 t3 = mActIntersMain.mLength;
        mActIntersMain.mLength = t3 + 1u;
        mActIntersMain.mpArray[t3] = static_cast<MtObject*>(pCode);
    }
}

__attribute__((weak)) void cPawnActInterface::reqBreakActInter() {
    DDON_STUB("cPawnActInterface::reqBreakActInter")
    /* stub */
}

__attribute__((weak)) void cPawnActInterface::updateActInterfacePre(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterface::updateActInterfacePre")
    /* stub */
}

__attribute__((weak)) void cPawnActInterface::updateActInterfaceCore(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterface::updateActInterfaceCore")
    /* stub */
}

__attribute__((weak)) void cPawnActInterface::updateAutoWeaponMode(cPawnActInterIO& param, uCharacter& owner) {
    DDON_STUB("cPawnActInterface::updateAutoWeaponMode")
    /* stub */
}

cPawnActInterBase* cPawnActInterface::getActiveActInter() {
    if (mActInterStep < mActIntersMain.mLength) {
        return static_cast<cPawnActInterBase*>(mActIntersMain.mpArray[mActInterStep]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) bool cPawnActInterface::isEnableRequestAction(cPawnActInterIO& param, uCharacter& owner, u32 actNo) {
    DDON_STUB("cPawnActInterface::isEnableRequestAction")
    return {};
}

__attribute__((weak)) void cPawnActInterface::disableActIter() {
    DDON_STUB("cPawnActInterface::disableActIter")
    /* stub */
}

__attribute__((weak)) void cPawnActInterface::updateAfterInput(uCharacter& owner) {
    DDON_STUB("cPawnActInterface::updateAfterInput")
    /* stub */
}

inline cPawnActInterface::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPawnActInterface::MyDTI cPawnActInterface::DTI("cPawnActInterface", &::cAIObject::DTI, 1216ul, 0u, 0u);

__attribute__((weak)) MtObject* cPawnActInterface::MyDTI::newInstance() const {
    DDON_STUB("cPawnActInterface::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cGeneralPoint>::~MtTypedArray();

template MtTypedArray<cPawnActInterBase>::~MtTypedArray();

