// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpCatchCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cCharParamEnemy.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cDelegate.h"
#include "cHitNode.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpActionSelect.h"
#include "cpComponent.h"
#include "cpHpDamageCtrl.h"
#include "cpInput.h"
#include "cpInvincibleCtrl.h"
#include "cpObjCollision.h"
#include "cpScrCollision.h"
#include "cpStateManager.h"
#include "../../generated/shared/nCatch.h"
#include "../../generated/shared/nDDOMath.h"
#include "rAttackParam.h"
#include "rCatchInfoParam.h"
#include "rCaughtInfoParam.h"
#include "rCharParamEnemy.h"
#include "rHumanEnemyParam.h"
#include "sContextManager.h"
#include "../../XFramework/sMain.h"
#include "sSetManager.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#include "uHumanEnemy.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const f32 beardownTimerTbl[3][3] = {
    {0x1p+3f, 0x1.4p+3f, 0x1.4p+2f},
    {0x1.8p+3f, 0x1.ep+3f, 0x1.2p+3f},
    {0x1.8p+1f, 0x1p+2f, 0x1p+1f},
};

const MtDTI& cCatchInfo::getDTI() const {
    return cCatchInfo::DTI;
}

cCatchInfo::~cCatchInfo() {
}

inline cCatchInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCatchInfo::MyDTI cCatchInfo::DTI("cCatchInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cCatchInfo::MyDTI::newInstance() const {
    return new (16u) cCatchInfo;
}

const MtDTI& cCaughtInfo::getDTI() const {
    return cCaughtInfo::DTI;
}

cCaughtInfo::~cCaughtInfo() {
}

inline cCaughtInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCaughtInfo::MyDTI cCaughtInfo::DTI("cCaughtInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cCaughtInfo::MyDTI::newInstance() const {
    return new (16u) cCaughtInfo;
}

const MtDTI& cpCatchCtrl::getDTI() const {
    return cpCatchCtrl::DTI;
}

void* cpCatchCtrl::operator new(size_t sz, u32 align) {
    return cpCatchCtrl::getAllocator()->memAlloc(sz, align, cpCatchCtrl::DTI.getID());
}

cpCatchCtrl::cpCatchCtrl() {
    DDON_STUB("cpCatchCtrl::cpCatchCtrl")
    /* stub */
}

cpCatchCtrl::~cpCatchCtrl() {
    DDON_STUB("cpCatchCtrl::~cpCatchCtrl")
    /* stub */
}

void cpCatchCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

__attribute__((weak)) void cpCatchCtrl::setResource(rCatchInfoParam* pRes) {
    DDON_STUB("cpCatchCtrl::setResource")
    /* stub */
}

__attribute__((weak)) void cpCatchCtrl::setResource(rCaughtInfoParam* pRes) {
    DDON_STUB("cpCatchCtrl::setResource")
    /* stub */
}

__attribute__((weak)) void cpCatchCtrl::setup() {
    DDON_STUB("cpCatchCtrl::setup")
    /* stub */
}

void cpCatchCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

void cpCatchCtrl::setupContextCatchCtrl(bool recvFlag) {
    uDDOModel* t0 = mpModel;
    u8 catchType = cContextInterface::getCatchType(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter);
    mCatchType = catchType & 127;
    u8 t1 = cContextInterface::getCatchType(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter);
    if (static_cast<signed char>(catchType) > -1) {
        mCatchInfo.mCatchType = t1 & 127;
        mCatchInfo.mCatchUid = cContextInterface::getCatchTargetUID(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter);
        mCatchInfo.mJointNo = cContextInterface::getCatchJointNo(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter);
        MtVector3 frame72(cContextInterface::getCatchHitPos(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter));
        mCatchInfo.mHitPos.x = frame72.x;
        mCatchInfo.mHitPos.y = frame72.y;
        mCatchInfo.mHitPos.z = frame72.z;
        mCatchInfo.mHitPos.pad_ = 0.0f;
    } else {
        mCaughtInfo.mCatchType = t1 & 127;
        mCaughtInfo.mCatchUid = cContextInterface::getCatchTargetUID(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter);
        mCaughtInfo.mJointNo = cContextInterface::getCatchJointNo(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter);
    }
}

__attribute__((weak)) void cpCatchCtrl::callbackCatchHit(cHitInfo* pHitInfo) {
    DDON_STUB("cpCatchCtrl::callbackCatchHit")
    /* stub */
}

__attribute__((weak)) bool cpCatchCtrl::isCatch(u8 catchType) {
    DDON_STUB("cpCatchCtrl::isCatch")
    return {};
}

__attribute__((weak)) f32 cpCatchCtrl::getCatchLoopTimer() {
    DDON_STUB("cpCatchCtrl::getCatchLoopTimer")
    return {};
}

nCatch::BEARDOWN_EFFECTIVE cpCatchCtrl::getBeardownEffective() {
    if (mpModel != nullptr) {
        if (mpModel->isEnable()) {
            if ((mpModel->mUnitId & 2u) != 0) {
                if (static_cast<uEnemy*>(mpModel)->getCharaParamEnemy() != nullptr) {
                    if (static_cast<uEnemy*>(mpModel)->getCharaParamEnemy()->getCharParamEnemy() != nullptr) {
                        return static_cast<nCatch::BEARDOWN_EFFECTIVE>(static_cast<uEnemy*>(mpModel)->getCharaParamEnemy()->getCharParamEnemy()->mBeardownEffective);
                    }
                }
            }
        }
    }
    return nCatch::BEARDOWN_EFFECTIVE_NOTHING;
}

__attribute__((weak)) void cpCatchCtrl::setBeardownEffectiveTimer() {
    DDON_STUB("cpCatchCtrl::setBeardownEffectiveTimer")
    /* stub */
}

void cpCatchCtrl::updateBeardownEffectiveTimer() {
    if (mCaughtInfo.mCatchType != 1) {
        return;
    }
    mBeardownEffectiveTimer = mBeardownEffectiveTimer - sMain::getInstance()->mDeltaTime;
    if (0.0f > mBeardownEffectiveTimer) {
        mBeardownEffectiveTimer = 0.0f;
    }
}

__attribute__((weak)) void cpCatchCtrl::setLeverGachaPoint() {
    DDON_STUB("cpCatchCtrl::setLeverGachaPoint")
    /* stub */
}

__attribute__((weak)) void cpCatchCtrl::updateLeverGacha() {
    DDON_STUB("cpCatchCtrl::updateLeverGacha")
    /* stub */
}

bool cpCatchCtrl::checkCatch(u8 catchType, u32 uniqId) {
    return mCaughtInfo.mCatchUid == uniqId;
}

__attribute__((weak)) void cpCatchCtrl::setCatch(u8 catchType, u32 uniqId) {
    DDON_STUB("cpCatchCtrl::setCatch")
    /* stub */
}

void cpCatchCtrl::setFailed() {
    mCatchType = 0;
    mCatchInfo.mCatchType = 0;
    mCatchInfo.mReleaseType = 0;
    mCatchInfo.mCatchUid = 0;
    mCatchInfo.mJointNo = 0xFF;
    mCatchInfo.mHitPos.x = MtVector3::Zero.x;
    mCatchInfo.mHitPos.y = MtVector3::Zero.y;
    mCatchInfo.mHitPos.z = MtVector3::Zero.z;
    mCatchInfo.mHitPos.pad_ = 0.0f;
    uDDOModel* t0 = mpModel;
    cContextInterface::setIsCatchHit(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter);
    cContextInterface::setCatchType(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCatchInfo.mCatchType);
    cContextInterface::setCatchTargetUID(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCatchInfo.getCatchUid());
    cContextInterface::setCatchJointNo(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCatchInfo.mJointNo);
}

__attribute__((weak)) u32 cpCatchCtrl::getActNoRelease() {
    DDON_STUB("cpCatchCtrl::getActNoRelease")
    return {};
}

__attribute__((weak)) bool cpCatchCtrl::checkCancel() {
    DDON_STUB("cpCatchCtrl::checkCancel")
    return {};
}

__attribute__((weak)) void cpCatchCtrl::setCancel() {
    DDON_STUB("cpCatchCtrl::setCancel")
    /* stub */
}

__attribute__((weak)) void cpCatchCtrl::forceCancel() {
    if (mCatchInfo.mCatchType == 0) {
        return;
    }
    mpModel->setTarget(static_cast<uDDOModel*>(nullptr));
    mCatchType = 0;
    mCatchInfo.mCatchType = 0;
    mCatchInfo.mReleaseType = 0;
    mCatchInfo.mCatchUid = 0;
    mCatchInfo.mJointNo = 0xFF;
    mCatchInfo.mHitPos.x = MtVector3::Zero.x;
    mCatchInfo.mHitPos.y = MtVector3::Zero.y;
    mCatchInfo.mHitPos.z = MtVector3::Zero.z;
    mCatchInfo.mHitPos.pad_ = 0.0f;
    uDDOModel* t0 = mpModel;
    cContextInterface::setCatchType(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, static_cast<u8>(0));
    cContextInterface::setCatchTargetUID(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCatchInfo.getCatchUid());
    cContextInterface::setCatchJointNo(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCatchInfo.mJointNo);
}

__attribute__((weak)) bool cpCatchCtrl::checkClutched(u8 catchType, uDDOModel& Catcher, MtVector3& hitPos) {
    DDON_STUB("cpCatchCtrl::checkClutched")
    return {};
}

__attribute__((weak)) void cpCatchCtrl::setClutched(u8 catchType, u32 uniqId, u8 jointNo) {
    DDON_STUB("cpCatchCtrl::setClutched")
    /* stub */
}

bool cpCatchCtrl::checkCaught() {
    uDDOModel* pCatch = static_cast<uDDOModel*>(sSetManager::getInstance()->getLayoutUnit(mCaughtInfo.getCatchUid()));
    if (pCatch != nullptr) {
        if (pCatch->isEnable()) {
            if (pCatch->getStateActionPtr() != nullptr) {
                s32 state = pCatch->getStateActionPtr()->getStateNo();
                if (state != 262) {
                    if (state == 264) {
                        if (pCatch->getCatchCtrlPtr() != nullptr) {
                            return pCatch->getCatchCtrlPtr()->mCatchInfo.getCatchUid() == mpModel->mUnitParam;
                        }
                    }
                } else {
                    if (pCatch->getCatchCtrlPtr() != nullptr) {
                        return pCatch->getCatchCtrlPtr()->mCatchInfo.getCatchUid() == mpModel->mUnitParam;
                    }
                }
                return false;
            }
        }
    }
    return false;
}

__attribute__((weak)) void cpCatchCtrl::setCaught() {
    DDON_STUB("cpCatchCtrl::setCaught")
    /* stub */
}

__attribute__((weak)) bool cpCatchCtrl::checkEscape() {
    DDON_STUB("cpCatchCtrl::checkEscape")
    return {};
}

__attribute__((weak)) void cpCatchCtrl::setEscape() {
    DDON_STUB("cpCatchCtrl::setEscape")
    /* stub */
}

void cpCatchCtrl::forceEscape() {
    if (mCaughtInfo.mCatchType == 0) {
        return;
    }
    mCaughtInfo.mCatchType = 0;
    mCaughtInfo.mEscapeType = 0;
    mCaughtInfo.mCatchUid = 0;
    mCaughtInfo.mJointNo = 0xFF;
    mCaughtInfo.mHitPos.x = MtVector3::Zero.x;
    mCaughtInfo.mHitPos.y = MtVector3::Zero.y;
    mCaughtInfo.mHitPos.z = MtVector3::Zero.z;
    mCaughtInfo.mHitPos.pad_ = 0.0f;
    mCatchType = 0;
    uDDOModel* t0 = mpModel;
    cContextInterface::setCatchType(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, static_cast<u8>(0));
    cContextInterface::setCatchTargetUID(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCaughtInfo.getCatchUid());
    cContextInterface::setCatchJointNo(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCaughtInfo.mJointNo);
}

void cpCatchCtrl::disconnectEscape() {
    if (mCaughtInfo.mCatchType == 0) {
        return;
    }
    mCaughtInfo.mCatchType = 0;
    mCaughtInfo.mEscapeType = 0;
    mCaughtInfo.mCatchUid = 0;
    mCaughtInfo.mJointNo = 0xFF;
    mCaughtInfo.mHitPos.x = MtVector3::Zero.x;
    mCaughtInfo.mHitPos.y = MtVector3::Zero.y;
    mCaughtInfo.mHitPos.z = MtVector3::Zero.z;
    mCaughtInfo.mHitPos.pad_ = 0.0f;
    mCatchType = 0;
    uDDOModel* t0 = mpModel;
    cContextInterface::setIsCaughtResult(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter);
    cContextInterface::setCatchType(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCaughtInfo.mCatchType);
    cContextInterface::setCatchTargetUID(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCaughtInfo.getCatchUid());
    cContextInterface::setCatchJointNo(t0->mContextInterface.mpContextInstance, t0->mContextInterface.mpContextCharacter, mCaughtInfo.mJointNo);
}

void cpCatchCtrl::setDispCheck() {
    if (mpModel->isMaster()) {
        return;
    }
    if (sContextManager::getInstance()->getContextInstFromUniqueId(mCatchInfo.getCatchUid()) != nullptr) {
        return;
    }
    mpModel->mDDOModelFlag = mpModel->mDDOModelFlag & 0xFFFFFFFEu;
}

__attribute__((weak)) void cpCatchCtrl::setConstrain() {
    DDON_STUB("cpCatchCtrl::setConstrain")
    /* stub */
}

__attribute__((weak)) void cpCatchCtrl::releaseConstrain() {
    DDON_STUB("cpCatchCtrl::releaseConstrain")
    /* stub */
}

__attribute__((weak)) void cpCatchCtrl::throwOm() {
    DDON_STUB("cpCatchCtrl::throwOm")
    /* stub */
}

__attribute__((weak)) void cpCatchCtrl::putOm() {
    DDON_STUB("cpCatchCtrl::putOm")
    /* stub */
}

void cpCatchCtrl::setThrowOm() {
    if ((mpModel->mUnitId & 256u) == 0) {
        return;
    }
    uBaseModel* t0 = sSetManager::getInstance()->getLayoutUnit(mCaughtInfo.getCatchUid());
    mpModel->getCatchCtrlPtr()->releaseConstrain();
    uDDOModel* t2 = mpModel;
    MtVector3 frame72(cContextInterface::getOmReleasePos(t2->mContextInterface.mpContextInstance, t2->mContextInterface.mpContextCharacter));
    t2->mPos.x = frame72.x;
    t2->mPos.y = frame72.y;
    t2->mPos.z = frame72.z;
    t2->mPos.pad_ = 0.0f;
    uDDOModel* t3 = mpModel;
    f32 t4 = cContextInterface::getOmReleaseAngle(t2->mContextInterface.mpContextInstance, t2->mContextInterface.mpContextCharacter);
    MtVector3 frame88(nDDOMath::calcVelocityXZ(1.0f, t4));
    t3->mVelocity.x = frame88.x;
    t3->mVelocity.y = frame88.y;
    t3->mVelocity.z = frame88.z;
    t3->mVelocity.pad_ = 0.0f;
    uDDOModel* t5 = mpModel;
    MtQuaternion frame104(cContextInterface::getOmReleaseQuat(t2->mContextInterface.mpContextInstance, t2->mContextInterface.mpContextCharacter));
    t5->mQuat.x = frame104.x;
    t5->mQuat.y = frame104.y;
    t5->mQuat.z = frame104.z;
    t5->mQuat.w = frame104.w;
    cpActionManager* pc_act = mpModel->getActMgrPtr();
    pc_act->setAction(3u, false, 0u, 0u, 0u, 0u, 0.0f, 0.0f, 0.0f, 0.0f);
    if (t0 == nullptr) {
        return;
    }
    if (t0->isEnable()) {
        static_cast<uDDOModel*>(t0)->getCatchCtrlPtr()->forceCancel();
    }
}

void cpCatchCtrl::setPutOm() {
    if ((mpModel->mUnitId & 256u) == 0) {
        return;
    }
    uBaseModel* t0 = sSetManager::getInstance()->getLayoutUnit(mCaughtInfo.getCatchUid());
    mpModel->getCatchCtrlPtr()->releaseConstrain();
    uDDOModel* t2 = mpModel;
    MtVector3 frame72(cContextInterface::getOmReleasePos(t2->mContextInterface.mpContextInstance, t2->mContextInterface.mpContextCharacter));
    t2->mPos.x = frame72.x;
    t2->mPos.y = frame72.y;
    t2->mPos.z = frame72.z;
    t2->mPos.pad_ = 0.0f;
    uDDOModel* t3 = mpModel;
    t3->setAngle(cContextInterface::getOmReleaseAngle(t2->mContextInterface.mpContextInstance, t2->mContextInterface.mpContextCharacter));
    cpActionManager* pc_act = mpModel->getActMgrPtr();
    pc_act->setAction(4u, false, 0u, 0u, 0u, 0u, 0.0f, 0.0f, 0.0f, 0.0f);
    if (t0 == nullptr) {
        return;
    }
    if (t0->isEnable()) {
        static_cast<uDDOModel*>(t0)->getCatchCtrlPtr()->forceCancel();
    }
}

__attribute__((weak)) u32 cpCatchCtrl::callbackGetCatchAction() {
    DDON_STUB("cpCatchCtrl::callbackGetCatchAction")
    return {};
}

__attribute__((weak)) bool cpCatchCtrl::catchHitGroupPlayer(cHitInfo* pHitInfo, uDDOModel* pAtk, const cAttackParam* pAtkParam) {
    DDON_STUB("cpCatchCtrl::catchHitGroupPlayer")
    return {};
}

__attribute__((weak)) bool cpCatchCtrl::catchHitGroupOther(cHitInfo* pHitInfo, uDDOModel* pAtk, const cAttackParam* pAtkParam) {
    DDON_STUB("cpCatchCtrl::catchHitGroupOther")
    return {};
}

bool cpCatchCtrl::isOwnerBeaDown() const {
    if (mpModel != nullptr) {
        if (mCatchType == 1) {
            return mpModel->getActionStateNo() == 265;
        }
    }
    return false;
}

inline cpCatchCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpCatchCtrl::MyDTI cpCatchCtrl::DTI("cpCatchCtrl", &::cpComponent::DTI, 240ul, 0u, 0u);

__attribute__((weak)) MtObject* cpCatchCtrl::MyDTI::newInstance() const {
    DDON_STUB("cpCatchCtrl::MyDTI::newInstance")
    return nullptr;
}

