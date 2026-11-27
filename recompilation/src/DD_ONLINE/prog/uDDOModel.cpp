// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uDDOModel.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cArcLoader.h"
#include "cBlowShrinkDmInfo.h"
#include "cComponentManager.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cDDMaterialCtrl.h"
#include "cDamageMsg.h"
#include "cDelegate.h"
#include "cGeneralPoint.h"
#include "cGuardInfo.h"
#include "cHitInfoAfter.h"
#include "cHitInfoAfterLocal.h"
#include "cHitNode.h"
#include "cNetGameServer.h"
#include "cOcdCustomReqInfo.h"
#include "cOcdDamageInfo.h"
#include "cParentRegionStatus.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpAISensor.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpActionSelect.h"
#include "cpCatchCtrl.h"
#include "cpChargeCtrl.h"
#include "cpCheckWallCliff.h"
#include "cpComponent.h"
#include "cpDDMrlMgr.h"
#include "cpEffectProvider.h"
#include "cpEffectStatusManager.h"
#include "cpEquip.h"
#include "cpHpDamageCtrl.h"
#include "cpHugeble.h"
#include "cpInput.h"
#include "cpInvincibleCtrl.h"
#include "cpKeepAtkAdjust.h"
#include "cpLayout.h"
#include "cpLockOn.h"
#include "cpLockOnTargetManager.h"
#include "cpModelConst.h"
#include "cpMotionHistory.h"
#include "cpMotionSe.h"
#include "cpNpc.h"
#include "cpObjCollision.h"
#include "cpOcdCtrl.h"
#include "cpPartsCtrl.h"
#include "cpPathFinding.h"
#include "cpPawnThink.h"
#include "cpPivotCtrl.h"
#include "cpRegionStatusCtrl.h"
#include "cpRootComponent.h"
#include "cpRotateCtrl.h"
#include "cpSafePos.h"
#include "cpScrCollision.h"
#include "cpSequenceCtrl.h"
#include "cpShlShotCtrl.h"
#include "cpSlave.h"
#include "cpSoftBody.h"
#include "cpStateManager.h"
#include "cpStatusChange.h"
#include "cpTalk.h"
#include "cpWallExitCtrl.h"
#include "cpWorkRate.h"
#include "ctl_storageArray.h"
#include "../../generated/shared/nAction.h"
#include "../../generated/shared/nCatch.h"
#include "../../generated/shared/nDDOModel.h"
#include "nDDOUtility.h"
#include "nLayout.h"
#include "nObjCollision.h"
#include "nObjCondition.h"
#include "rAttackParam.h"
#include "rCollNode.h"
#include "../../XFramework/rMotionList.h"
#include "rObjCollision.h"
#include "rShlParamList.h"
#include "sAIPawnNotice.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sControlManager.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sGeneralPoint.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sObjCollision.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sSetManager.h"
#include "uArmor.h"
#include "../../XFramework/uBaseModel.h"
#include "uControl.h"
#include "uControlEnemy.h"
#include "uControlNpc.h"
#include "../../XFramework/uCoord.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#include "uShlBase.h"
#include "../../XFramework/uSimSoftBody.h"
#include "uWeapon.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uDDOModel::getDTI() const {
    return uDDOModel::DTI;
}

uDDOModel::uDDOModel() {
    DDON_STUB("uDDOModel::uDDOModel")
    /* stub */
}

__attribute__((noinline)) uDDOModel::~uDDOModel() {
    DDON_STUB("uDDOModel::~uDDOModel")
    /* stub */
}

__attribute__((weak)) void uDDOModel::setup() {
    DDON_STUB("uDDOModel::setup")
    /* stub */
}

__attribute__((weak)) void uDDOModel::move() {
    DDON_STUB("uDDOModel::move")
    /* stub */
}

void uDDOModel::sync() {
    if (mIsMaster) {
        cContextInterface::setShlDelte(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter, mShlDeleteBit);
    }
    mShlDeleteBit = 0;
    mComponentMgr.sync();
    if (getHpDamageCtrlPtr() != nullptr) {
        getHpDamageCtrlPtr()->checkCalcDamage();
    }
    if (mTouchRelReqArray.elems[0].mpRelease != nullptr) {
        releaseTouchTarget(mTouchRelReqArray.elems[0].mpRelease, mTouchRelReqArray.elems[0].mTouchReleaseType);
        mTouchRelReqArray.elems[0].mpRelease = nullptr;
        mTouchRelReqArray.elems[0].mTouchReleaseType = nDDOModel::TOUCH_RELEASE_NONE;
    }
    if (mTouchRelReqArray.elems[1].mpRelease != nullptr) {
        releaseTouchTarget(mTouchRelReqArray.elems[1].mpRelease, mTouchRelReqArray.elems[1].mTouchReleaseType);
        mTouchRelReqArray.elems[1].mpRelease = nullptr;
        mTouchRelReqArray.elems[1].mTouchReleaseType = nDDOModel::TOUCH_RELEASE_NONE;
    }
    if (mTouchRelReqArray.elems[2].mpRelease != nullptr) {
        releaseTouchTarget(mTouchRelReqArray.elems[2].mpRelease, mTouchRelReqArray.elems[2].mTouchReleaseType);
        mTouchRelReqArray.elems[2].mpRelease = nullptr;
        mTouchRelReqArray.elems[2].mTouchReleaseType = nDDOModel::TOUCH_RELEASE_NONE;
    }
    if (mTouchRelReqArray.elems[3].mpRelease != nullptr) {
        releaseTouchTarget(mTouchRelReqArray.elems[3].mpRelease, mTouchRelReqArray.elems[3].mTouchReleaseType);
        mTouchRelReqArray.elems[3].mpRelease = nullptr;
        mTouchRelReqArray.elems[3].mTouchReleaseType = nDDOModel::TOUCH_RELEASE_NONE;
    }
    if (mTouchRelReqArray.elems[4].mpRelease != nullptr) {
        releaseTouchTarget(mTouchRelReqArray.elems[4].mpRelease, mTouchRelReqArray.elems[4].mTouchReleaseType);
        mTouchRelReqArray.elems[4].mpRelease = nullptr;
        mTouchRelReqArray.elems[4].mTouchReleaseType = nDDOModel::TOUCH_RELEASE_NONE;
    }
    if (mTouchRelReqArray.elems[5].mpRelease != nullptr) {
        releaseTouchTarget(mTouchRelReqArray.elems[5].mpRelease, mTouchRelReqArray.elems[5].mTouchReleaseType);
        mTouchRelReqArray.elems[5].mpRelease = nullptr;
        mTouchRelReqArray.elems[5].mTouchReleaseType = nDDOModel::TOUCH_RELEASE_NONE;
    }
    if (mTouchRelReqArray.elems[6].mpRelease != nullptr) {
        releaseTouchTarget(mTouchRelReqArray.elems[6].mpRelease, mTouchRelReqArray.elems[6].mTouchReleaseType);
        mTouchRelReqArray.elems[6].mpRelease = nullptr;
        mTouchRelReqArray.elems[6].mTouchReleaseType = nDDOModel::TOUCH_RELEASE_NONE;
    }
    if (mTouchRelReqArray.elems[7].mpRelease != nullptr) {
        releaseTouchTarget(mTouchRelReqArray.elems[7].mpRelease, mTouchRelReqArray.elems[7].mTouchReleaseType);
        mTouchRelReqArray.elems[7].mpRelease = nullptr;
        mTouchRelReqArray.elems[7].mTouchReleaseType = nDDOModel::TOUCH_RELEASE_NONE;
    }
}

__attribute__((weak)) void uDDOModel::moveAfter() {
    DDON_STUB("uDDOModel::moveAfter")
    /* stub */
}

__attribute__((weak)) void uDDOModel::draw(cDraw* pDraw) {
    DDON_STUB("uDDOModel::draw")
    /* stub */
}

void uDDOModel::kill() {
    if (mpCtrl != nullptr) {
        if (mpCtrl->isEnable()) {
            mpCtrl->sendMasterParam();
            sSetManager* t0 = sSetManager::getInstance();
            t0->setReleaseMaster(cContextInterface::getUniqueId(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter));
            mComponentMgr.kill();
            if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
                if ((mBeFlag - 1u) <= 1u) {
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
                }
            }
        } else {
            mComponentMgr.kill();
            if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
                if ((mBeFlag - 1u) <= 1u) {
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
                }
            }
        }
    } else {
        mComponentMgr.kill();
        if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
            if ((mBeFlag - 1u) <= 1u) {
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
            }
        }
    }
}

void uDDOModel::setModel(rModel* pmod) {
    this->uModel::setModel(pmod);
    mIsResetDDMrlCtrl = true;
}

__attribute__((weak)) void uDDOModel::createComponent() {
    DDON_STUB("uDDOModel::createComponent")
    /* stub */
}

void uDDOModel::setupComponentPtr() {
    mGuardComponent.mpWorkRate = static_cast<cpWorkRate*>(mComponentMgr.getRootComponent()->find(cpWorkRate::DTI, true, true));
    mGuardComponent.mpObjCollision = static_cast<cpObjCollisionBase*>(mComponentMgr.getRootComponent()->find(cpObjCollisionBase::DTI, true, true));
    mGuardComponent.mpScrCollision = static_cast<cpScrCollision*>(mComponentMgr.getRootComponent()->find(cpScrCollision::DTI, true, true));
    mGuardComponent.mpActMgr = static_cast<cpActionManager*>(mComponentMgr.getRootComponent()->find(cpActionManager::DTI, true, true));
    mGuardComponent.mpInput = static_cast<cpInput*>(mComponentMgr.getRootComponent()->find(cpInput::DTI, true, true));
    mGuardComponent.mpActionSelect = static_cast<cpActionSelect*>(mComponentMgr.getRootComponent()->find(cpActionSelect::DTI, true, true));
    mGuardComponent.mpActionRequest = static_cast<cpActionRequest*>(mComponentMgr.getRootComponent()->find(cpActionRequest::DTI, true, true));
    mGuardComponent.mpSequenceCtrl = static_cast<cpSequenceCtrl*>(mComponentMgr.getRootComponent()->find(cpSequenceCtrl::DTI, true, true));
    mGuardComponent.mpHpDamageCtrl = static_cast<cpHpDamageCtrl*>(mComponentMgr.getRootComponent()->find(cpHpDamageCtrl::DTI, true, true));
    mGuardComponent.mpCatchCtrl = static_cast<cpCatchCtrl*>(mComponentMgr.getRootComponent()->find(cpCatchCtrl::DTI, true, true));
    mGuardComponent.mpStateAction = static_cast<cpStateManager*>(mComponentMgr.getRootComponent()->find("StateAction", true));
    mGuardComponent.mpStateLive = static_cast<cpStateManager*>(mComponentMgr.getRootComponent()->find("StateLive", true));
    mGuardComponent.mpLockOn = static_cast<cpLockOn*>(mComponentMgr.getRootComponent()->find(cpLockOn::DTI, true, true));
    mpPivotCtrl = static_cast<cpPivotCtrl*>(mComponentMgr.getRootComponent()->find(cpPivotCtrl::DTI, true, true));
    mpEquip = static_cast<cpEquip*>(mComponentMgr.getRootComponent()->find(cpEquip::DTI, true, true));
    mpMotionHistory = static_cast<cpMotionHistory*>(mComponentMgr.getRootComponent()->find(cpMotionHistory::DTI, true, true));
    mpRotateCtrl = static_cast<cpRotateCtrl*>(mComponentMgr.getRootComponent()->find(cpRotateCtrl::DTI, true, true));
    mGuardComponent.mpChargeCtrl = static_cast<cpChargeCtrl*>(mComponentMgr.getRootComponent()->find(cpChargeCtrl::DTI, true, true));
    mpDDMrlMgr = static_cast<cpDDMrlMgr*>(mComponentMgr.getRootComponent()->find(cpDDMrlMgr::DTI, true, true));
    mGuardComponent.mpShlShotCtrl = static_cast<cpShlShotCtrl*>(mComponentMgr.getRootComponent()->find(cpShlShotCtrl::DTI, true, true));
    mpPartsCtrl = static_cast<cpPartsCtrl*>(mComponentMgr.getRootComponent()->find(cpPartsCtrl::DTI, true, true));
    mGuardComponent.mpRegionStatusCtrl = static_cast<cpRegionStatusCtrl*>(mComponentMgr.getRootComponent()->find(cpRegionStatusCtrl::DTI, true, true));
    mGuardComponent.mpStatusChange = static_cast<cpStatusChange*>(mComponentMgr.getRootComponent()->find(cpStatusChange::DTI, true, true));
    mGuardComponent.mpLayout = static_cast<cpLayout*>(mComponentMgr.getRootComponent()->find(cpLayout::DTI, true, true));
    mpEffectProvider = static_cast<cpEffectProvider*>(mComponentMgr.getRootComponent()->find(cpEffectProvider::DTI, true, true));
    mGuardComponent.mpSlave = static_cast<cpSlave*>(mComponentMgr.getRootComponent()->find(cpSlave::DTI, true, true));
    mpSafePos = static_cast<cpSafePos*>(mComponentMgr.getRootComponent()->find(cpSafePos::DTI, true, true));
    mpHugeble = static_cast<cpHugeble*>(mComponentMgr.getRootComponent()->find(cpHugeble::DTI, true, true));
    mpCheckWallCliff = static_cast<cpCheckWallCliff*>(mComponentMgr.getRootComponent()->find(cpCheckWallCliff::DTI, true, true));
    mGuardComponent.mpLockOnTargetMgr = static_cast<cpLockOnTargetManager*>(mComponentMgr.getRootComponent()->find(cpLockOnTargetManager::DTI, true, true));
    mGuardComponent.mpKeepAtkAdjust = static_cast<cpKeepAtkAdjust*>(mComponentMgr.getRootComponent()->find(cpKeepAtkAdjust::DTI, true, true));
    mpMotionSe = static_cast<cpMotionSe*>(mComponentMgr.getRootComponent()->find(cpMotionSe::DTI, true, true));
    mGuardComponent.mpPathFinding = static_cast<cpPathFinding*>(mComponentMgr.getRootComponent()->find(cpPathFinding::DTI, true, true));
    mGuardComponent.mpPawnThink = static_cast<cpPawnThink*>(mComponentMgr.getRootComponent()->find(cpPawnThink::DTI, true, true));
    mGuardComponent.mpAISensor = static_cast<cpAISensor*>(mComponentMgr.getRootComponent()->find(cpAISensor::DTI, true, true));
    mpEffectStatusManager = static_cast<cpEffectStatusManager*>(mComponentMgr.getRootComponent()->find(cpEffectStatusManager::DTI, true, true));
    mGuardComponent.mpInvincibleCtrl = static_cast<cpInvincibleCtrl*>(mComponentMgr.getRootComponent()->find(cpInvincibleCtrl::DTI, true, true));
    mpSoftBody = static_cast<cpSoftBody*>(mComponentMgr.getRootComponent()->find(cpSoftBody::DTI, true, true));
    mGuardComponent.mpOcdCtrl = static_cast<cpOcdCtrl*>(mComponentMgr.getRootComponent()->find(cpOcdCtrl::DTI, true, true));
    mpModelConst = static_cast<cpModelConst*>(mComponentMgr.getRootComponent()->find(cpModelConst::DTI, true, true));
    mpTalk = static_cast<cpTalk*>(mComponentMgr.getRootComponent()->find(cpTalk::DTI, true, true));
    mpNpc = static_cast<cpNpc*>(mComponentMgr.getRootComponent()->find(cpNpc::DTI, true, true));
    mpWallExitCtrl = static_cast<cpWallExitCtrl*>(mComponentMgr.getRootComponent()->find(cpWallExitCtrl::DTI, true, true));
}

__attribute__((weak)) void uDDOModel::registDelegate() {
    DDON_STUB("uDDOModel::registDelegate")
    /* stub */
}

void uDDOModel::createProperty(MtPropertyList& s) {
    this->uModel::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mComponentMgr", static_cast<MtObject*>(&mComponentMgr), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDDOModelFlag", &mDDOModelFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsMaster", &mIsMaster, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOldPos", &mOldPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVelocity", &mVelocity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAcceleration", &mAcceleration, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVelocity", &mMoveVelocity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mObjStatus", &mObjStatus, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mObjStatusExt", &mObjStatusExt, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCtrl", reinterpret_cast<MtObject* *>(&mpCtrl), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMayaScale", &mMayaScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mForceScale", &mForceScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "callbackPreSetMotion", &callbackPreSetMotion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "callbackSetMotion", &callbackSetMotion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpTarget", reinterpret_cast<MT_MFUNC>(&::uDDOModel::getTarget), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos", &mTargetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUnitId", &this->mUnitId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "updateInput", static_cast<MtObject*>(&updateInput), 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "before", static_cast<MtObject*>(&before), 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "checkAction", static_cast<MtObject*>(&checkAction), 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "update", static_cast<MtObject*>(&update), 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "updateMotion", static_cast<MtObject*>(&updateMotion), 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "callbackAfterUpdateMotion", static_cast<MtObject*>(&callbackAfterUpdateMotion), 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scrAdjust", &scrAdjust, 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "after", static_cast<MtObject*>(&after), 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "updatePosition", static_cast<MtObject*>(&updatePosition), 2052u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTouchType", reinterpret_cast<s32*>(&mTouchType), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTouchTarget", reinterpret_cast<MtObject* *>(&mpTouchTarget), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsNoTouch", &mIsNoTouch, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "シェル削除ビット", &mShlDeleteBit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "自己死亡フラグ", &mIsSelfDead, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetUIJointNo", &mTargetUIJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetUIOffset", &mTargetUIOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CommandCacheReset", static_cast<MT_MFUNC>(&::uDDOModel::requestCommandCacheReset), 10u);
}

void uDDOModel::setupContextParam() {
    setupContextPos(false);
    setupContextAction(false);
    setupContextCondition(false);
    setupContextEnemyClimb(false);
    setupContextTarget(false);
    setupContextStateLive(false);
    setupContextCatchCtrl(false);
    setupContextEnemyStatusChange(false);
    setupContextCorePoint(false);
}

__attribute__((weak)) void uDDOModel::setupContextPos(bool recvFlag) {
    DDON_STUB("uDDOModel::setupContextPos")
    /* stub */
}

void uDDOModel::setupContextTarget(bool recvFlag) {
    cContextInstance* t0 = mContextInterface.mpContextInstance;
    cContextCharacter* t1 = mContextInterface.mpContextCharacter;
    u32 uid = cContextInterface::getTargetUid(t0, t1);
    if (uid != 0) {
        sSetManager* t3 = sSetManager::getInstance();
        uDDOModel* p_target = static_cast<uDDOModel*>(t3->getLayoutUnit(uid));
        if ((mpTarget = p_target) != nullptr) {
            u32 t5 = p_target->getUnitParam();
            cContextInstance* t6 = mContextInterface.mpContextInstance;
            cContextCharacter* t7 = mContextInterface.mpContextCharacter;
            cContextInterface::setTargetUid(t6, t7, t5);
            cContextInstance* t11 = mContextInterface.mpContextInstance;
            cContextCharacter* t12 = mContextInterface.mpContextCharacter;
            MtVector3 frame56(cContextInterface::getTargetPos(t11, t12));
            f32 t13 = frame56.x;
            mTargetPos.x = t13;
            f32 t14 = frame56.y;
            mTargetPos.y = t14;
            f32 t15 = frame56.z;
            mTargetPos.z = t15;
            mTargetPos.pad_ = 0.0f;
            cContextInstance* t16 = mContextInterface.mpContextInstance;
            cContextCharacter* t17 = mContextInterface.mpContextCharacter;
        } else {
            cContextInstance* t8 = mContextInterface.mpContextInstance;
            cContextCharacter* t9 = mContextInterface.mpContextCharacter;
            cContextInterface::setTargetUid(t8, t9, 0u);
            cContextInstance* t11 = mContextInterface.mpContextInstance;
            cContextCharacter* t12 = mContextInterface.mpContextCharacter;
            MtVector3 frame56(cContextInterface::getTargetPos(t11, t12));
            f32 t13 = frame56.x;
            mTargetPos.x = t13;
            f32 t14 = frame56.y;
            mTargetPos.y = t14;
            f32 t15 = frame56.z;
            mTargetPos.z = t15;
            mTargetPos.pad_ = 0.0f;
            cContextInstance* t16 = mContextInterface.mpContextInstance;
            cContextCharacter* t17 = mContextInterface.mpContextCharacter;
        }
    } else {
        mpTarget = nullptr;
        cContextInstance* t8 = mContextInterface.mpContextInstance;
        cContextCharacter* t9 = mContextInterface.mpContextCharacter;
        cContextInterface::setTargetUid(t8, t9, 0u);
        cContextInstance* t11 = mContextInterface.mpContextInstance;
        cContextCharacter* t12 = mContextInterface.mpContextCharacter;
        MtVector3 frame56(cContextInterface::getTargetPos(t11, t12));
        f32 t13 = frame56.x;
        mTargetPos.x = t13;
        f32 t14 = frame56.y;
        mTargetPos.y = t14;
        f32 t15 = frame56.z;
        mTargetPos.z = t15;
        mTargetPos.pad_ = 0.0f;
        cContextInstance* t16 = mContextInterface.mpContextInstance;
        cContextCharacter* t17 = mContextInterface.mpContextCharacter;
    }
    cContextInterface::setTargetPos(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter, mTargetPos);
}

void uDDOModel::setupContextStateLive(bool recvFlag) {
    switch (cContextInterface::getStateLive(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter) - 512u) {
        case 0:
        {
            if ((this->mUnitId & 1026u) == 0) {
                callbackRespawn(!recvFlag);
            }
            break;
        }
        case 1:
        {
            callbackInjured(!recvFlag);
            break;
        }
        case 2:
        {
            callbackLost(!recvFlag);
            break;
        }
        case 3:
        {
            callbackLostEnd(!recvFlag);
            break;
        }
        case 4:
        {
            callbackReturnTerritory(!recvFlag);
            break;
        }
        default:
        {
            break;
        }
    }
}

void uDDOModel::setupContextCatchCtrl(bool recvFlag) {
    if (getCatchCtrlPtr() == nullptr) {
        return;
    }
    getCatchCtrlPtr()->setupContextCatchCtrl(recvFlag);
}

__attribute__((weak)) void uDDOModel::changeDrawModelFlag(u32 flag, bool isOn) {
    DDON_STUB("uDDOModel::changeDrawModelFlag")
    /* stub */
}

void uDDOModel::updatePtr() {
    mComponentMgr.updatePtr();
    if (mpTarget != nullptr) {
        if (!mpTarget->isEnable()) {
            mpTarget = nullptr;
        }
    }
    if (mpTouchTarget != nullptr) {
        if (!mpTouchTarget->isEnable()) {
            mpTouchTarget = nullptr;
        }
    }
    if (static_cast<unsigned int>(mTouchedArray.mBufferPt) != 0) {
        size_t v2_0 = mTouchedArray.mBufferPt;
        unsigned int i2_2 = 0;
        unsigned int v3_1;
        size_t v4_0;
        size_t v5_0;
        for (;;) {
            if (mTouchedArray.mBuffer[i2_2] != nullptr) {
                v5_0 = v2_0;
            } else {
                if ((i2_2 + 1u) >= static_cast<unsigned int>(v2_0)) {
                    v4_0 = v2_0;
                } else {
                    v3_1 = i2_2;
                    for (;;) {
                        mTouchedArray.mBuffer[v3_1] = mTouchedArray.mBuffer[v3_1 + 1u];
                        if ((v3_1 + 2u) < static_cast<unsigned int>(mTouchedArray.mBufferPt)) {
                            v3_1 += 1u;
                        } else {
                            v4_0 = mTouchedArray.mBufferPt;
                            break;
                        }
                    }
                }
                mTouchedArray.mBufferPt = v4_0 - 1ul;
                v5_0 = v4_0 - 1ul;
            }
            if ((i2_2 + 1u) < static_cast<unsigned int>(v5_0)) {
                v2_0 = v5_0;
                i2_2 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTouchRelReqArray.elems[0].mpRelease != nullptr) {
        if ((mTouchRelReqArray.elems[0].mpRelease->mBeFlag - 1u) > 1u) {
            mTouchRelReqArray.elems[0].mpRelease = nullptr;
        }
    }
    if (mTouchRelReqArray.elems[1].mpRelease != nullptr) {
        if ((mTouchRelReqArray.elems[1].mpRelease->mBeFlag - 1u) > 1u) {
            mTouchRelReqArray.elems[1].mpRelease = nullptr;
        }
    }
    if (mTouchRelReqArray.elems[2].mpRelease != nullptr) {
        if ((mTouchRelReqArray.elems[2].mpRelease->mBeFlag - 1u) > 1u) {
            mTouchRelReqArray.elems[2].mpRelease = nullptr;
        }
    }
    if (mTouchRelReqArray.elems[3].mpRelease != nullptr) {
        if ((mTouchRelReqArray.elems[3].mpRelease->mBeFlag - 1u) > 1u) {
            mTouchRelReqArray.elems[3].mpRelease = nullptr;
        }
    }
    if (mTouchRelReqArray.elems[4].mpRelease != nullptr) {
        if ((mTouchRelReqArray.elems[4].mpRelease->mBeFlag - 1u) > 1u) {
            mTouchRelReqArray.elems[4].mpRelease = nullptr;
        }
    }
    if (mTouchRelReqArray.elems[5].mpRelease != nullptr) {
        if ((mTouchRelReqArray.elems[5].mpRelease->mBeFlag - 1u) > 1u) {
            mTouchRelReqArray.elems[5].mpRelease = nullptr;
        }
    }
    if (mTouchRelReqArray.elems[6].mpRelease != nullptr) {
        if ((mTouchRelReqArray.elems[6].mpRelease->mBeFlag - 1u) > 1u) {
            mTouchRelReqArray.elems[6].mpRelease = nullptr;
        }
    }
    if (mTouchRelReqArray.elems[7].mpRelease != nullptr) {
        if ((mTouchRelReqArray.elems[7].mpRelease->mBeFlag - 1u) > 1u) {
            mTouchRelReqArray.elems[7].mpRelease = nullptr;
        }
    }
}

void uDDOModel::updateEfcHandle() {
    mComponentMgr.updateEfcHandle();
}

__attribute__((weak)) void uDDOModel::resetPos(const MtVector3& pos) {
    DDON_STUB("uDDOModel::resetPos")
    /* stub */
}

void uDDOModel::setMotionBlendRate(u32 type, f32 blendRate) {
    mMotion[type].mBlend = blendRate;
}

void uDDOModel::setMotionSpeed(u32 type, f32 speed) {
    mMotion[type].mSpeed = speed;
}

void uDDOModel::setMotionFrame(u32 type, f32 frame) {
    mMotion[type].mFrame = frame;
    mMotion[type].mPrevFrame = mMotion[type].mFrame;
}

f32 uDDOModel::getMotionFrame(u32 type) const {
    return mMotion[type].getFrame();
}

u32 uDDOModel::getMotionNo(u32 type) const {
    return mMotion[type].mMotionNo;
}

bool uDDOModel::isExistMotionNo(u32 motNo) {
    if (motNo != 0xFFFF) {
        if (mpMotionList[(motNo >> 8) & 15u] != nullptr) {
            return mpMotionList[(motNo >> 8) & 15u]->rMotionList::getMotionInfo(static_cast<unsigned char>(motNo)) != nullptr;
        }
    }
    return false;
}

nMotion::MOTION_INFO* uDDOModel::getMotionInfo(u32 motNo) const {
    if (motNo != 0xFFFF) {
        if (mpMotionList[(motNo >> 8) & 15u] != nullptr) {
            return mpMotionList[(motNo >> 8) & 15u]->rMotionList::getMotionInfo(static_cast<unsigned char>(motNo));
        }
    }
    return nullptr;
}

__attribute__((weak)) bool uDDOModel::setMotionEx(u32 src, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr) {
    DDON_STUB("uDDOModel::setMotionEx")
    return {};
}

__attribute__((weak)) void uDDOModel::setDDOMotion(MOT_TYPE type, u32 motNo, bool forcible, u32 attr, f32 hokan, f32 frame, f32 speed) {
    DDON_STUB("uDDOModel::setDDOMotion")
    /* stub */
}

f32 uDDOModel::getMotionInterFrame(u32 mot_no) {
    return -1.0f;
}

__attribute__((weak)) void uDDOModel::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uDDOModel::applyWorldOffset")
    /* stub */
}

bool uDDOModel::invalidGroupKill() {
    cpLayout* pCpLayout = getLayoutPtr();
    if (pCpLayout != nullptr) {
        if (pCpLayout->invalidGroupKill()) {
            if ((this->mUnitId & 1154u) != 0) {
                if (mpCtrl != nullptr) {
                    sControlManager::getInstance()->releaseUnit(mpCtrl);
                } else {
                    sControlManager::getInstance()->killUnit(this);
                }
            } else {
                if (((static_cast<unsigned long>(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 8040)) >> 8) & 1ul) != 0) {
                    cOmControl* pCtrl = sOmManager::getInstance()->getOmCtrl(getUnitParam());
                    if (pCtrl != nullptr) {
                        sOmManager::getInstance()->releaseOmCtrl(pCtrl);
                    }
                    return true;
                }
            }
            return true;
        }
    }
    return false;
}

cContextCharacter* uDDOModel::getContext() {
    if (mpCtrl != nullptr) {
        if (mpCtrl->isEnable()) {
            return mpCtrl->getContext();
        }
    }
    return nullptr;
}

cContextInstance* uDDOModel::getContextInst() {
    if (mpCtrl != nullptr) {
        if (mpCtrl->isEnable()) {
            return mpCtrl->getContextInst();
        }
    }
    return nullptr;
}

uControlNpc* uDDOModel::getCtrlNpc() {
    if (mpCtrl != nullptr) {
        if (mpCtrl->isEnable() && mpCtrl->isNpc()) {
            return static_cast<uControlNpc*>(mpCtrl);
        }
    }
    return nullptr;
}

void uDDOModel::setMaster(bool is_master) {
    mIsMaster = is_master;
}

void uDDOModel::throwMaster(s32 index) {
    if (!mIsMaster) {
        return;
    }
    if (!cContextInterface::getMasterChangeFlag(mContextInterface.mpContextInstance)) {
        return;
    }
    if (mpCtrl != nullptr) {
        if (mpCtrl->isEnable()) {
            mpCtrl->sendMasterParam();
            sSetManager* t0 = sSetManager::getInstance();
            t0->sendThrowMaster(cContextInterface::getUniqueId(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter), index);
        } else {
            sSetManager* t0 = sSetManager::getInstance();
            t0->sendThrowMaster(cContextInterface::getUniqueId(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter), index);
        }
    } else {
        sSetManager* t0 = sSetManager::getInstance();
        t0->sendThrowMaster(cContextInterface::getUniqueId(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter), index);
    }
}

bool uDDOModel::isMaster() const {
    return mIsMaster;
}

uDDOModel* uDDOModel::getTarget() {
    return mpTarget;
}

void uDDOModel::setTarget(uDDOModel* pTarget) {
    mpTarget = pTarget;
    if (pTarget != nullptr) {
        cContextInterface::setTargetUid(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter, pTarget->getUnitParam());
    } else {
        cContextInterface::setTargetUid(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter, 0u);
    }
}

const MtVector3& uDDOModel::getTargetPos() {
    return mTargetPos;
}

void uDDOModel::setTargetPos(const MtVector3& pos) {
    mTargetPos = pos;
    cContextInterface::setTargetPos(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter, mTargetPos);
}

__attribute__((weak)) const MtVector3 uDDOModel::getDefaultTargetPos() {
    DDON_STUB("uDDOModel::getDefaultTargetPos")
    __builtin_unreachable();
}

__attribute__((weak)) void uDDOModel::setShlParamList(rShlParamList* pr) {
    DDON_STUB("uDDOModel::setShlParamList")
    /* stub */
}

__attribute__((weak)) void uDDOModel::setCommonShlParamList(rShlParamList* pr) {
    DDON_STUB("uDDOModel::setCommonShlParamList")
    /* stub */
}

__attribute__((weak)) void uDDOModel::registShlParamList(const rShlParamList* pShlRes) {
    DDON_STUB("uDDOModel::registShlParamList")
    /* stub */
}

void uDDOModel::checkReplaceInfo(cHitInfoAfter& HitInfo) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->checkReplaceInfo(HitInfo);
}

bool uDDOModel::isCtrlPlayer() {
    if (mpCtrl != nullptr) {
        if (mpCtrl->isEnable()) {
            return mpCtrl->isPlayer();
        }
    }
    return false;
}

bool uDDOModel::isCtrlPawn() {
    if (mpCtrl != nullptr) {
        if (mpCtrl->isEnable()) {
            return mpCtrl->isPawn();
        }
    }
    return false;
}

bool uDDOModel::isCtrlEnemy() {
    if (mpCtrl != nullptr) {
        if (mpCtrl->isEnable()) {
            return mpCtrl->isEnemy();
        }
    }
    return false;
}

__attribute__((weak)) void uDDOModel::enableScale(uModel* pModel, bool MayaScale, bool ForceScale) {
    DDON_STUB("uDDOModel::enableScale")
    /* stub */
}

__attribute__((weak)) void uDDOModel::updateMatrix() {
}

void uDDOModel::callbackCreateNode(cHitNode* pHitNode) {
    sAIPawnNotice::getInstance()->reqAddHitNodeNotice(pHitNode);
}

__attribute__((weak)) void uDDOModel::callbackKillNode(cHitNode* pHitNode) {
}

__attribute__((weak)) void uDDOModel::callbackGuard(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackGuard")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackGuarded(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackGuarded")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackGuardTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackGuardTest")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackGuardedTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackGuardedTest")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackAttack(cHitInfo* pHitInfo) {
}

MtVector3 uDDOModel::callbackReplaceHitNormal(const MtVector3& HitNormal) {
    return HitNormal;
}

__attribute__((weak)) void uDDOModel::callbackAttackTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackAttackTest")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackDamageTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackDamageTest")
    /* stub */
}

void uDDOModel::callbackDamage_Register(const cHitInfo* pHitLocalInfo, cDamageMsg* pDmMsg) {
    pDmMsg->makeInfoFromHitNode(pHitLocalInfo);
}

void uDDOModel::callbackDamage(cHitInfo* pHitLocalInfo) {
    if (pHitLocalInfo == nullptr) {
        return;
    }
    sOmManager::getInstance()->setShell(pHitLocalInfo->mHitPos, this);
}

__attribute__((weak)) void uDDOModel::callbackDamageAfter(cHitInfoAfter* pHitInfo) {
    DDON_STUB("uDDOModel::callbackDamageAfter")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackHealAfter(cHitInfoAfter* pHitInfo) {
    DDON_STUB("uDDOModel::callbackHealAfter")
    /* stub */
}

void uDDOModel::callbackDamageAfter_make(cHitInfoAfter* pHitInfo) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->callbackDamageAfter_make(pHitInfo);
}

void uDDOModel::callbackDamageAfter_calc(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->callbackDamageAfter_calc(pHitInfo);
}

void uDDOModel::callbackDamageAfter_apply(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->callbackDamageAfter_apply(pHitInfo);
}

void uDDOModel::callbackHealedAfter_make(cHitInfoAfter* pHitInfo) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->callbackHealedAfter_make(pHitInfo);
}

void uDDOModel::callbackHealedAfter_calc(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->callbackHealedAfter_calc(pHitInfo);
}

bool uDDOModel::callbackHealedAfter_apply(cHitInfoAfter* pHitInfo) {
    return false;
}

bool uDDOModel::callbackHealedAfter_apply_slave(cHitInfoAfter* pHitInfo) {
    return false;
}

void uDDOModel::callbackGuard_make(cHitInfo* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    if (pHitInfo->mpDfdModel == nullptr) {
        return;
    }
    if (pHitInfo->mpGuardInfo == nullptr) {
        return;
    }
    uDDOModel* pAttacker = pHitInfo->getAttackerUnitPtr();
    if (pAttacker == nullptr) {
        return;
    }
    pAttacker->makeGuardAttackInfo(pHitInfo);
    pHitInfo->mpDfdModel->makeGuardDefenceInfo(pHitInfo);
    cpHpDamageCtrl* pHpDamageCtr = getHpDamageCtrlPtr();
    if (pHpDamageCtr == nullptr) {
        return;
    }
    pHpDamageCtr->callbackGuard_make(pHitInfo);
}

void uDDOModel::callbackGuard_calc(cHitInfo* pHitInfo) {
    if (pHitInfo != nullptr) {
        if (pHitInfo->mpAtkModel != nullptr) {
            if (pHitInfo->mpDfdModel != nullptr) {
                if (pHitInfo->mpGuardInfo != nullptr) {
                    cAttackParam* t0 = pHitInfo->getAttackParam();
                    if (t0 != nullptr) {
                        calcGuard(pHitInfo);
                        if ((t0->mGuardFlag2 & 2) != 0) {
                            pHitInfo->mpGuardInfo->mGuardDefenceResultType = 2;
                        } else {
                            if (t0->mGuardAngle == 2) {
                                pHitInfo->mpGuardInfo->mGuardDefenceResultType = 0;
                            }
                        }
                        const cAttackParam* t1 = pHitInfo->getDefendParam();
                        if (t1 != nullptr) {
                            if ((t1->mGuardFlag2 & 4) != 0) {
                                pHitInfo->mpGuardInfo->mIsSuccessNoReaction = true;
                            } else {
                                pHitInfo->mpGuardInfo->mIsSuccessNoReaction = false;
                            }
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void uDDOModel::callbackGuard_apply(cHitInfo* pHitInfo) {
}

void uDDOModel::callbackShrink(cHitInfoAfter* pHitInfo) {
    if (getActMgrPtr() != nullptr) {
        if (getActMgrPtr()->checkPriority(nAction::PRIO_DMG_SHRINK, pHitInfo, false)) {
            if (getActionRequestPtr() != nullptr) {
                getActionRequestPtr()->mShrinkActionReq = getActionRequestPtr()->mShrinkAction;
            }
        }
    } else {
        if (getActionRequestPtr() != nullptr) {
            getActionRequestPtr()->mShrinkActionReq = getActionRequestPtr()->mShrinkAction;
        }
    }
}

void uDDOModel::callbackBlow(cHitInfoAfter* pHitInfo) {
    if (getActMgrPtr() != nullptr) {
        if (getActMgrPtr()->checkPriority(nAction::PRIO_DMG_BLOW, static_cast<cHitInfoAfter*>(nullptr), false)) {
            if (getActionRequestPtr() != nullptr) {
                getActionRequestPtr()->mBlowActionReq = getActionRequestPtr()->mBlowAction;
            }
        }
    } else {
        if (getActionRequestPtr() != nullptr) {
            getActionRequestPtr()->mBlowActionReq = getActionRequestPtr()->mBlowAction;
        }
    }
}

bool uDDOModel::callbackDown(cHitInfoAfter* pHitInfo) {
    return true;
}

bool uDDOModel::callbackShake(cHitInfoAfter* pHitInfo) {
    return true;
}

bool uDDOModel::isEnableStorm(cHitInfoAfter* pHitInfo) {
    return true;
}

bool uDDOModel::isEnableQuake(cHitInfoAfter* pHitInfo) {
    return true;
}

void uDDOModel::callbackHitStopSlow(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    if (pHitInfo->mCommonInfo.mpAtkModel == nullptr) {
        return;
    }
    if (pHitInfo->mCommonInfo.mpDfdModel == nullptr) {
        return;
    }
    if (pHitInfo->mCommonInfo.mpAttackParam == nullptr) {
        return;
    }
    if (pHitInfo->mCommonInfo.mpAttackParam->mHitStopTime > 0.0f) {
        if (pHitInfo->mCommonInfo.mpAttackParam->mHitSlowRate > 0.0f) {
            pHitInfo->mCommonInfo.mHitStopSlowResultType = 2;
        } else {
            pHitInfo->mCommonInfo.mHitStopSlowResultType = 1;
        }
    } else {
        pHitInfo->mCommonInfo.mHitStopSlowResultType = 0;
    }
}

__attribute__((weak)) void uDDOModel::callbackHitStopSlowRecv(cHitInfoAfter* pHitInfo) {
}

__attribute__((weak)) void uDDOModel::callbackAttackEnd(cHitInfoAfter* pHitInfo) {
    DDON_STUB("uDDOModel::callbackAttackEnd")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackCatch(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackCatch")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackCaught(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackCaught")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackCatchTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackCatchTest")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackCaughtTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackCaughtTest")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackCheck(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackCheck")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackChecked(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackChecked")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackCheckTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackCheckTest")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackCheckedTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackCheckedTest")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackHeal(cHitInfo* pHitInfo) {
}

__attribute__((weak)) void uDDOModel::callbackHealed(cHitInfo* pHitInfo) {
}

__attribute__((weak)) void uDDOModel::callbackHealedAfter(cHitInfoAfter* pHitInfo) {
    DDON_STUB("uDDOModel::callbackHealedAfter")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackHealTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackHealTest")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callbackHealedTest(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callbackHealedTest")
    /* stub */
}

void uDDOModel::callbackPush(uDDOModel* pModel, const MtVector3& push) {
    if (pModel == nullptr) {
        return;
    }
    if (getObjCollisionPtr() == nullptr) {
        return;
    }
    if (pModel->getObjCollisionPtr() == nullptr) {
        return;
    }
    getObjCollisionPtr()->mHitFlag.mPushHit = static_cast<unsigned int>(static_cast<unsigned long>(getObjCollisionPtr()->mHitFlag.mPushHit) | (1ul << static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(pModel->getObjCollisionPtr()) + 704)) & 31)));
}

__attribute__((weak)) void uDDOModel::callbackChangePartsBit(BitData bitData) {
}

__attribute__((weak)) void uDDOModel::callbackGuard_Local(cHitInfo* pHitInfo) {
}

u32 uDDOModel::replaceCollisionAttr(u32 attr, const cCollNode* pCollNode) {
    return attr;
}

bool uDDOModel::callbackRegistInterPolateGeom(MtVector3& oldPos, const MtVector3& currentPos, f32 radius, const cHitGeom* pGeom) {
    return false;
}

void uDDOModel::callbackReqOcdEndAction(u32 actNo, nAction::ACT_PRIO priority) {
    if (getActMgrPtr() == nullptr) {
        return;
    }
    if (mGuardComponent.mpActionRequest == nullptr) {
        return;
    }
    if (getHpDamageCtrlPtr() != nullptr) {
        if (!getHpDamageCtrlPtr()->isDead()) {
            if (getActMgrPtr()->checkPriority(priority, static_cast<cHitInfoAfter*>(nullptr), false)) {
                getActionRequestPtr()->mRequestActionReq = actNo;
            }
        }
    } else {
        if (getActMgrPtr()->checkPriority(priority, static_cast<cHitInfoAfter*>(nullptr), false)) {
            getActionRequestPtr()->mRequestActionReq = actNo;
        }
    }
}

bool uDDOModel::isDead() const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->isDead();
    } else {
        return false;
    }
}

__attribute__((weak)) bool uDDOModel::isDead(u32 index) const {
    DDON_STUB("uDDOModel::isDead")
    return {};
}

bool uDDOModel::isDeadDying() {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->isDeadDying();
    } else {
        return false;
    }
}

HP_DATATYPE uDDOModel::getHpRoot() const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->getHpRoot();
    } else {
        return 0;
    }
}

HP_DATATYPE uDDOModel::getHpMaxRoot() const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->getHpMaxRoot();
    } else {
        return 0;
    }
}

HP_DATATYPE uDDOModel::getHp(const u32 index) const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->getHp(index);
    } else {
        return 0;
    }
}

HP_DATATYPE uDDOModel::getHpMax(const u32 index) const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->getHpMax(index);
    } else {
        return 0;
    }
}

bool uDDOModel::isUsedPRegion(u32 index) const {
    if (index <= 9u) {
        if (getHpDamageCtrlPtr() != nullptr) {
            return getHpDamageCtrlPtr()->findParentRegionFromNo(index) != nullptr;
        }
    }
    return false;
}

f32 uDDOModel::getHpRate(u32 index) const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->getHpRate(index);
    } else {
        return 0.0f;
    }
}

void uDDOModel::addDamage(HP_DATATYPE damage, bool isNoDeath, u32 index) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->addDamage(damage, isNoDeath, index);
}

void uDDOModel::requestDie(bool isSelfDead) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->requestDie();
    if (!isSelfDead) {
        return;
    }
    mIsSelfDead = true;
}

f32 uDDOModel::getShP(const u32 index) const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->getShP(index);
    } else {
        return 0.0f;
    }
}

f32 uDDOModel::getBlP(const u32 index) const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->getBlP(index);
    } else {
        return 0.0f;
    }
}

f32 uDDOModel::getBlPMax(const u32 index) const {
    if (getHpDamageCtrlPtr() != nullptr) {
        return getHpDamageCtrlPtr()->getBlPMax(index);
    } else {
        return 0.0f;
    }
}

u32 uDDOModel::getLv() {
    return static_cast<u32>(cContextInterface::getLv(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter));
}

__attribute__((weak)) void uDDOModel::callDamageFuncs(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::callDamageFuncs")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callDamageAfterFuncs(cHitInfoAfter* pHitInfo, bool isApply) {
    DDON_STUB("uDDOModel::callDamageAfterFuncs")
    /* stub */
}

__attribute__((weak)) void uDDOModel::callHealedAfterFuncs(cHitInfoAfter* pHitInfo, bool isApply) {
    DDON_STUB("uDDOModel::callHealedAfterFuncs")
    /* stub */
}

void uDDOModel::makeDamageAttackInfo(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    pHitInfo->mHpDamageInfo.mAttackBasePhys = cContextInterface::getAttackBasePhys(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mAttackBaseMagic = cContextInterface::getAttackBaseMagic(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mAttackWeaponPhys = cContextInterface::getAttackWepPhys(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mAttackWeaponMagic = cContextInterface::getAttackWepMagic(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
}

void uDDOModel::makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    pHitInfo->mHpDamageInfo.mAttackBasePhys = cContextInterface::getAttackBasePhys(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mAttackBaseMagic = cContextInterface::getAttackBaseMagic(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mAttackWeaponPhys = cContextInterface::getAttackWepPhys(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mAttackWeaponMagic = cContextInterface::getAttackWepMagic(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
}

void uDDOModel::makeDamageDefenceInfo(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    pHitInfo->mHpDamageInfo.mDefenceBasePhys = cContextInterface::getDefenceBasePhys(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mDefenceBaseMagic = cContextInterface::getDefenceBaseMagic(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mDefenceWeaponPhys = cContextInterface::getDefenceWepPhys(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mHpDamageInfo.mDefenceWeaponMagic = cContextInterface::getDefenceWepMagic(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
}

void uDDOModel::makeBlowShrinkAttackInfo(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId) {
    makeBlowShrinkAttackInfoCom(pInfo, pAttacker, pDefender, atkAdjustUniqueId);
}

void uDDOModel::makeBlowShrinkAttackInfoShl(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId) {
    if (pInfo == nullptr) {
        return;
    }
    if (pAttacker == nullptr) {
        return;
    }
    if (pDefender == nullptr) {
        return;
    }
    makeBlowShrinkAttackInfoCom(pInfo, pAttacker, pDefender, atkAdjustUniqueId);
}

__attribute__((weak)) void uDDOModel::makeBlowShrinkAttackInfoCom(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId) {
    if (pInfo == nullptr) {
        return;
    }
    if (pAttacker == nullptr) {
        return;
    }
    if (pDefender == nullptr) {
        return;
    }
    pInfo->mPower = cContextInterface::getPower(pAttacker->mContextInterface.mpContextInstance, pAttacker->mContextInterface.mpContextCharacter);
    pInfo->mShrinkWep = cContextInterface::getShrinkWep(pAttacker->mContextInterface.mpContextInstance, pAttacker->mContextInterface.mpContextCharacter);
    pInfo->mBlowWep = cContextInterface::getBlowWep(pAttacker->mContextInterface.mpContextInstance, pAttacker->mContextInterface.mpContextCharacter);
    pInfo->mDownBase = cContextInterface::getDownBase(pAttacker->mContextInterface.mpContextInstance, pAttacker->mContextInterface.mpContextCharacter);
    pInfo->mDownWep = cContextInterface::getDownWep(pAttacker->mContextInterface.mpContextInstance, pAttacker->mContextInterface.mpContextCharacter);
    pInfo->mShakeBase = cContextInterface::getShakeBase(pAttacker->mContextInterface.mpContextInstance, pAttacker->mContextInterface.mpContextCharacter);
    pInfo->mWeight = cContextInterface::getWeight(pDefender->mContextInterface.mpContextInstance, pDefender->mContextInterface.mpContextCharacter);
}

void uDDOModel::makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    makeOcdAttackInfoCom(pHitInfo);
}

void uDDOModel::makeOcdAttackInfo(cHitInfoAfter* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    makeOcdAttackInfoCom(pHitInfo);
}

__attribute__((weak)) void uDDOModel::makeOcdAttackInfoCom(cHitInfoAfter* pHitInfo) {
    DDON_STUB("uDDOModel::makeOcdAttackInfoCom")
    /* stub */
}

void uDDOModel::addOcdDamageParam(cHitInfoAfter* pHitInfo, u32 OcdUID, f32 endurance) {
    cOcdDamageInfo::stDamageData* pData = pHitInfo->mOcdDamageInfo.getOcdDataFromUID(OcdUID);
    if (pData == nullptr) {
        return;
    }
    pData->mSkillAttack = pData->mSkillAttack + endurance;
}

__attribute__((weak)) void uDDOModel::addDamageMsg(const cDamageMsg& msg) {
    DDON_STUB("uDDOModel::addDamageMsg")
    /* stub */
}

__attribute__((weak)) void uDDOModel::clearDamageMsg() {
    mDamageMsgArray.deleteAll(false);
}

void uDDOModel::makeGuardAttackInfo(cHitInfo* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    if (pHitInfo->mpGuardInfo == nullptr) {
        return;
    }
    uDDOModel* pAttacker = pHitInfo->getAttackerUnitPtr();
    if (pAttacker == nullptr) {
        return;
    }
    uDDOModel* pDefender = pHitInfo->mpDfdModel;
    if (pHitInfo->isAttackerShl()) {
        pAttacker->makeBlowShrinkAttackInfoShl(pHitInfo->mpGuardInfo->mpBlowShrinkInfo, pAttacker, pDefender, pHitInfo->mAtkAdjustUniqueId);
    } else {
        pAttacker->makeBlowShrinkAttackInfo(pHitInfo->mpGuardInfo->mpBlowShrinkInfo, pAttacker, pDefender, pHitInfo->mAtkAdjustUniqueId);
    }
}

void uDDOModel::makeGuardDefenceInfo(cHitInfo* pHitInfo) {
    if (pHitInfo == nullptr) {
        return;
    }
    if (pHitInfo->mpGuardInfo == nullptr) {
        return;
    }
    f32 t0 = cContextInterface::getGuardDefenceBase(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mpGuardInfo->mGuardDefenceBase = t0;
    f32 t1 = cContextInterface::getGuardDefenceWep(mContextInterface.mpContextInstance, mContextInterface.mpContextCharacter);
    pHitInfo->mpGuardInfo->mGuardDefenceWep = t1;
}

__attribute__((weak)) void uDDOModel::calcGuard(cHitInfo* pHitInfo) {
    DDON_STUB("uDDOModel::calcGuard")
    /* stub */
}

__attribute__((weak)) void uDDOModel::applyDamageVisual(cHitInfoAfter* pHitInfo, nObjCollision::CALC_DAMADE_MODE* mode) {
    DDON_STUB("uDDOModel::applyDamageVisual")
    /* stub */
}

__attribute__((weak)) void uDDOModel::applyHealVisual(cHitInfoAfter* pHitInfo, nObjCollision::CALC_DAMADE_MODE* mode) {
    DDON_STUB("uDDOModel::applyHealVisual")
    /* stub */
}

__attribute__((weak)) void uDDOModel::checkHitStopSlow(cHitInfoAfter* pHitInfo) {
    DDON_STUB("uDDOModel::checkHitStopSlow")
    /* stub */
}

void uDDOModel::attackParamReplace(cHitInfo* pHitInfo, s32 offset) const {
    const cAttackParam* pAttackParam = pHitInfo->getAttackParam();
    if (pAttackParam == nullptr) {
        return;
    }
    if ((offset + pAttackParam->mIndex) > -1) {
        const cAttackParam* pNewParam = pHitInfo->getAttackParam(static_cast<u32>(offset + pAttackParam->mIndex));
        if (pNewParam != nullptr) {
            pHitInfo->setAttackParam(pNewParam);
        }
    }
}

bool uDDOModel::checkCalcDamageCancel(cHitInfo* pHitInfo) {
    return false;
}

void uDDOModel::buildComponent() {
    if (mIsCreatedFromNewDDOModel) {
        return;
    }
    mComponentMgr.setOwner(static_cast<MtObject*>(this));
    if (!mIsCreatedFromNewDDOModel) {
        createComponent();
        mComponentMgr.setupComponentPtr();
        setupComponentPtr();
    }
    mIsCreatedFromNewDDOModel = true;
}

__attribute__((weak)) void uDDOModel::releaseTouchTarget(uDDOModel* pRelease, nDDOModel::TOUCH_RELEASE_TYPE type) {
    DDON_STUB("uDDOModel::releaseTouchTarget")
    /* stub */
}

void uDDOModel::setTouch(uDDOModel* pReqOwner, bool isTouchSave) {
    if (pReqOwner == nullptr) {
        return;
    }
    if (!isTouchSave) {
        return;
    }
    pReqOwner->mpTouchTarget = this;
    size_t t0 = mTouchedArray.mBufferPt;
    if (static_cast<unsigned int>(t0) <= 7) {
        mTouchedArray.mBufferPt = t0 + 1ul;
        mTouchedArray.mBuffer[t0] = pReqOwner;
    }
}

__attribute__((weak)) void uDDOModel::requestReleaseTouch(uDDOModel* pRelease, nDDOModel::TOUCH_RELEASE_TYPE type) {
    DDON_STUB("uDDOModel::requestReleaseTouch")
    /* stub */
}

void uDDOModel::clearTouchType(nDDOModel::TOUCH_TYPE type) {
    if (type != nDDOModel::TOUCH_NONE) {
        if (mTouchType == type) {
            mTouchType = nDDOModel::TOUCH_NONE;
        }
    } else {
        mTouchType = nDDOModel::TOUCH_NONE;
    }
}

u32 uDDOModel::getScrFilter() {
    if (getScrCollisionPtr() != nullptr) {
        return getScrCollisionPtr()->getFilter();
    } else {
        if ((this->mUnitId & 32u) != 0) {
            uShlBase* pShl = static_cast<uShlBase*>(this);
            if (pShl->getOwner() != nullptr) {
                if (pShl->getOwner()->getScrCollisionPtr() != nullptr) {
                    return pShl->getOwner()->getScrCollisionPtr()->getFilter();
                }
            }
            return 0x20000000;
        } else {
            return 0x20000000;
        }
    }
}

cGroundAttrInfo* uDDOModel::getGroundInfoScr() {
    return (getScrCollisionPtr() == nullptr) ? static_cast<cGroundAttrInfo*>(nullptr) : (&getScrCollisionPtr()->mGroundAttrInfoScr);
}

cGroundAttrInfo* uDDOModel::getGroundInfoWaterDepth() {
    return (getScrCollisionPtr() == nullptr) ? static_cast<cGroundAttrInfo*>(nullptr) : (&getScrCollisionPtr()->mGroundAttrInfoWaterDepth);
}

bool uDDOModel::isHitLand() const {
    if (getScrCollisionPtr() != nullptr) {
        return getScrCollisionPtr()->isHitLand();
    } else {
        return false;
    }
}

bool uDDOModel::isAttackHit(u32 filter) {
    if (getObjCollisionPtr() != nullptr) {
        return getObjCollisionPtr()->isAttackHitSub(filter, false);
    } else {
        return false;
    }
}

bool uDDOModel::isAttackTestHit(u32 filter) {
    if (getObjCollisionPtr() != nullptr) {
        return getObjCollisionPtr()->isAttackHitSub(filter, true);
    } else {
        return false;
    }
}

void uDDOModel::setPivotActive(bool active) {
    if (mpPivotCtrl == nullptr) {
        return;
    }
    mpPivotCtrl->setActive(active);
}

void uDDOModel::setPivotOffset(const MtVector3& offset) {
    if (mpPivotCtrl == nullptr) {
        return;
    }
    mpPivotCtrl->setPivotOffset(offset);
}

void uDDOModel::setPivotPos(const MtVector3& pos) {
    if (mpPivotCtrl == nullptr) {
        return;
    }
    mpPivotCtrl->setPivotPos(pos);
}

MtVector3 uDDOModel::getPivotPos() {
    if (mpPivotCtrl != nullptr) {
        return mpPivotCtrl->mPivotPos;
    } else {
        return mPos;
    }
}

void uDDOModel::setFinalQuat(const MtQuaternion& FinalQuat, f32 speed) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->setFinalQuat(FinalQuat, speed);
}

void uDDOModel::setFinalQuatByFrame(const MtQuaternion& FinalQuat, f32 frame) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->setFinalQuatByFrame(FinalQuat, frame);
}

void uDDOModel::setFinalAngleY(f32 AngleY, f32 speed) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->setFinalAngleY(AngleY, speed);
}

void uDDOModel::setFinalAngleYByFrame(f32 AngleY, f32 frame) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->setFinalAngleYByFrame(AngleY, frame);
}

void uDDOModel::setFinalDir(const MtVector3& dir, f32 speed) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->setFinalDir(dir, speed);
}

void uDDOModel::setFinalDirByFrame(const MtVector3& dir, f32 frame) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->setFinalDirByFrame(dir, frame);
}

void uDDOModel::setFinalAimPos(const MtVector3& from, const MtVector3& to, f32 speed) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->setFinalAimPos(from, to, speed);
}

void uDDOModel::setFinalAimPosByFrame(const MtVector3& from, const MtVector3& to, f32 frame) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->setFinalAimPosByFrame(from, to, frame);
}

void uDDOModel::setDefaultRotateSpeed(f32 InterSpeed) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->mDefaultInterSpeed = InterSpeed;
}

void uDDOModel::setDefaultRotateFrame(f32 InterFrame) {
    if (mpRotateCtrl == nullptr) {
        return;
    }
    mpRotateCtrl->mDefaultInterFrame = InterFrame;
}

const MtQuaternion& uDDOModel::getFinalQuat() {
    if (mpRotateCtrl != nullptr) {
        return mpRotateCtrl->getFinalQuat();
    } else {
        return mQuat;
    }
}

f32 uDDOModel::getFinalAngleY() {
    if (mpRotateCtrl != nullptr) {
        return mpRotateCtrl->getFinalAngleY();
    } else {
        MtVector3 frame40(getAngle());
        return frame40.y;
    }
}

void uDDOModel::setLayoutId(const nLayout::stLayoutID& layoutID) {
    if (getLayoutPtr() == nullptr) {
        return;
    }
    getLayoutPtr()->mLayoutId.mLayoutID = layoutID.mLayoutID;
}

__attribute__((weak)) const nLayout::stLayoutID uDDOModel::getLayoutId() const {
    DDON_STUB("uDDOModel::getLayoutId")
    __builtin_unreachable();
}

void uDDOModel::setSetNo(s32 no) {
    if (getLayoutPtr() == nullptr) {
        return;
    }
    getLayoutPtr()->mSetNo = no;
}

s32 uDDOModel::getSetNo() const {
    if (getLayoutPtr() != nullptr) {
        return getLayoutPtr()->getSetNo();
    } else {
        return -1;
    }
}

void uDDOModel::setSplitId(const nLayout::stSplitID& splitID) {
    if (getLayoutPtr() == nullptr) {
        return;
    }
    getLayoutPtr()->mSplitId.mSplitID = splitID.mSplitID;
}

void uDDOModel::setGroupParam(const cGroupParam* param) {
    if (getLayoutPtr() == nullptr) {
        return;
    }
    getLayoutPtr()->mpGroupParam = param;
}

const cGroupParam* uDDOModel::getGroupParam() const {
    if (getLayoutPtr() != nullptr) {
        return getLayoutPtr()->getGroupParam();
    } else {
        return nullptr;
    }
}

void uDDOModel::setQuestId(u32 QuestId) {
    if (getLayoutPtr() == nullptr) {
        return;
    }
    getLayoutPtr()->mQuestId = QuestId;
}

u32 uDDOModel::getQuestId() {
    if (getLayoutPtr() != nullptr) {
        return getLayoutPtr()->getQuestId();
    } else {
        return 0;
    }
}

__attribute__((weak)) void uDDOModel::callbackCreateShl(uShlBase* pShl) {
}

bool uDDOModel::chkJointForEditDelete(u32 jntNo) {
    return true;
}

void uDDOModel::requestOutline(u32 outlineType) {
    if (mpDDMrlMgr == nullptr) {
        return;
    }
    mpDDMrlMgr->requestOutline(static_cast<sEffectExt::OUTLINE>(outlineType));
}

void uDDOModel::requestCommandCacheReset() {
    mCommandCacheOffNow = true;
    if (mpEquip != nullptr) {
        uArmor* t0 = mpEquip->getArmor(0u);
        if (t0 != nullptr) {
            t0->mCommandCacheOffNow = true;
        }
        uArmor* t1 = mpEquip->getArmor(1u);
        if (t1 != nullptr) {
            t1->mCommandCacheOffNow = true;
        }
        uArmor* t2 = mpEquip->getArmor(2u);
        if (t2 != nullptr) {
            t2->mCommandCacheOffNow = true;
        }
        uArmor* t3 = mpEquip->getArmor(3u);
        if (t3 != nullptr) {
            t3->mCommandCacheOffNow = true;
        }
        uArmor* t4 = mpEquip->getArmor(4u);
        if (t4 != nullptr) {
            t4->mCommandCacheOffNow = true;
        }
        uArmor* t5 = mpEquip->getArmor(5u);
        if (t5 != nullptr) {
            t5->mCommandCacheOffNow = true;
        }
        uArmor* t6 = mpEquip->getArmor(6u);
        if (t6 != nullptr) {
            t6->mCommandCacheOffNow = true;
        }
        uWeapon* t7 = mpEquip->getWeapon(0u);
        if (t7 != nullptr) {
            t7->mCommandCacheOffNow = true;
        }
        uWeapon* t8 = mpEquip->getWeapon(1u);
        if (t8 != nullptr) {
            t8->mCommandCacheOffNow = true;
        }
        uWeapon* t9 = mpEquip->getWeapon(2u);
        if (t9 != nullptr) {
            t9->mCommandCacheOffNow = true;
        }
        uWeapon* t10 = mpEquip->getWeapon(3u);
        if (t10 != nullptr) {
            t10->mCommandCacheOffNow = true;
        }
        uArmor* t11 = mpEquip->getHair();
        uArmor* v11_9 = mpEquip->getBeard();
        uArmor* v11_10 = mpEquip->getMakeup();
        uArmor* v13_1 = mpEquip->getUnderwear();
        uArmor* v11_12 = mpEquip->getUnderwear2();
        uWeapon* v11_0 = mpEquip->getLantern();
        if (t11 != nullptr) {
            t11->mCommandCacheOffNow = true;
        }
        if (v11_9 != nullptr) {
            v11_9->mCommandCacheOffNow = true;
        }
        if (v11_10 != nullptr) {
            v11_10->mCommandCacheOffNow = true;
        }
        if (v13_1 != nullptr) {
            v13_1->mCommandCacheOffNow = true;
        }
        if (v11_12 != nullptr) {
            v11_12->mCommandCacheOffNow = true;
        }
        if (v11_0 != nullptr) {
            v11_0->mCommandCacheOffNow = true;
        }
    }
}

void uDDOModel::setInterpolateType(u32 interpolateType) {
    if (getSlavePtr() == nullptr) {
        return;
    }
    getSlavePtr()->setInterpolateType(interpolateType);
}

void uDDOModel::moveInterpolate() {
    if (getSlavePtr() == nullptr) {
        return;
    }
    getSlavePtr()->moveInterpolate();
}

void uDDOModel::updateInterpolatePos(const MtVector3& pos, bool forceSet) {
    if (getSlavePtr() == nullptr) {
        return;
    }
    getSlavePtr()->updateInterpolatePos(pos, forceSet);
}

const MtVector3& uDDOModel::getSafePos() {
    return *((mpSafePos == nullptr) ? (&MtVector3::Zero) : (&mpSafePos->mPosHistory[0]));
}

bool uDDOModel::isNowSafePos() {
    if (mpSafePos != nullptr) {
        return mpSafePos->isNowSafePos();
    } else {
        return true;
    }
}

void uDDOModel::countUpSafePosWarpLoop() {
    if (mpSafePos == nullptr) {
        return;
    }
    mpSafePos->mInfiLoopCheckCount = mpSafePos->mInfiLoopCheckCount + 1u;
}

void uDDOModel::initHugeble() {
    if (mpHugeble == nullptr) {
        return;
    }
    mpHugeble->initHugeble();
}

void uDDOModel::setInstantDeath() {
    if (mpHugeble == nullptr) {
        return;
    }
    mpHugeble->mIsInstantDeath = true;
}

bool uDDOModel::isHugebleSafePos() {
    if (mpHugeble != nullptr) {
        return mpHugeble->isSafePos();
    } else {
        return true;
    }
}

void uDDOModel::resetAtkAdjust() {
    if (getKeepAtkAdjustPtr() == nullptr) {
        return;
    }
    getKeepAtkAdjustPtr()->mActive = false;
}

void uDDOModel::setAtkAdjust(f32 atkRate, f32 blowRate, f32 shrinkRate) {
    if (getKeepAtkAdjustPtr() == nullptr) {
        return;
    }
    getKeepAtkAdjustPtr()->setAtkAdjust(atkRate, blowRate, shrinkRate);
}

void uDDOModel::setMgcAdjust(f32 atkRate) {
    if (getKeepAtkAdjustPtr() == nullptr) {
        return;
    }
    getKeepAtkAdjustPtr()->setMgcAdjust(atkRate);
}

f32 uDDOModel::getAtkRate(u16 uniqueId) {
    if (getKeepAtkAdjustPtr() != nullptr) {
        return getKeepAtkAdjustPtr()->getAtkRate(uniqueId);
    } else {
        return 0.0f;
    }
}

f32 uDDOModel::getMgcRate(u16 uniqueId) {
    if (getKeepAtkAdjustPtr() != nullptr) {
        return getKeepAtkAdjustPtr()->getMgcRate(uniqueId);
    } else {
        return 0.0f;
    }
}

f32 uDDOModel::getBlowRate(u16 uniqueId) {
    if (getKeepAtkAdjustPtr() != nullptr) {
        return getKeepAtkAdjustPtr()->getBlowRate(uniqueId);
    } else {
        return 0.0f;
    }
}

f32 uDDOModel::getShrinkRate(u16 uniqueId) {
    if (getKeepAtkAdjustPtr() != nullptr) {
        return getKeepAtkAdjustPtr()->getShrinkRate(uniqueId);
    } else {
        return 0.0f;
    }
}

u16 uDDOModel::getAtkAdjustUniqueId() {
    if (getKeepAtkAdjustPtr() != nullptr) {
        return getKeepAtkAdjustPtr()->getCurrentUniqueId();
    } else {
        return 0;
    }
}

u16 uDDOModel::getNowAtkAdjustUniqueId() {
    if (getKeepAtkAdjustPtr() != nullptr) {
        return getKeepAtkAdjustPtr()->getNowUniqueId();
    } else {
        return 0;
    }
}

void uDDOModel::setNowAtkAdjustUniqueId(u16 uniqueId) {
    if (getKeepAtkAdjustPtr() == nullptr) {
        return;
    }
    getKeepAtkAdjustPtr()->mNowUniqueId = uniqueId;
}

nCatch::CATCH_TYPE uDDOModel::getCatchType() {
    if (getCatchCtrlPtr() != nullptr) {
        return static_cast<nCatch::CATCH_TYPE>(getCatchCtrlPtr()->mCatchType);
    } else {
        return nCatch::CATCH_TYPE_NOTHING;
    }
}

void uDDOModel::clearHitEffectFlag(cHitInfoAfter& HitInfo) {
    HitInfo.mCommonInfo.mpAttackParam->mEffectFlag2 = HitInfo.mCommonInfo.mpAttackParam->mEffectFlag2 | 6;
}

void uDDOModel::clearHitSEFlag(cHitInfoAfter& HitInfo) {
    HitInfo.mCommonInfo.mpAttackParam->mSeFlag2 = HitInfo.mCommonInfo.mpAttackParam->mSeFlag2 | 3;
}

void uDDOModel::clearHitStop(cHitInfoAfter& HitInfo) {
    HitInfo.mCommonInfo.mpAttackParam->mHitStopTime = 0.0f;
    HitInfo.mCommonInfo.mpAttackParam->mHitSlowRate = 0.0f;
}

void uDDOModel::clearPhysAttack(cHitInfoAfter& HitInfo) {
    HitInfo.mCommonInfo.mpAttackParam->mPhysAttack2 = 0;
    HitInfo.mCommonInfo.mpAttackParam->mPhysAttackRate = 0.0f;
    HitInfo.mCommonInfo.mpAttackParam->mWeaponBadStatusRate = 0.0f;
}

void uDDOModel::clearMgcAttack(cHitInfoAfter& HitInfo) {
    HitInfo.mCommonInfo.mpAttackParam->mMgcAttack2 = 0;
    HitInfo.mCommonInfo.mpAttackParam->mMgcAttackRate = 0.0f;
}

void uDDOModel::clearShrinkDamage(cHitInfoAfter& HitInfo) {
    HitInfo.mCommonInfo.mpAttackParam->mShrinkRate = 0.0f;
}

void uDDOModel::clearBlowDamage(cHitInfoAfter& HitInfo) {
    HitInfo.mCommonInfo.mpAttackParam->mBlowRate = 0.0f;
}

void uDDOModel::clearDownDamage(cHitInfoAfter& HitInfo) {
    HitInfo.mCommonInfo.mpAttackParam->mDownRate = 0.0f;
}

void uDDOModel::setAnyFlag(cHitInfoAfter& HitInfo, u64 flag) {
    HitInfo.mCommonInfo.mpAttackParam->mFlag3 = flag;
}

void uDDOModel::addInvType(nObjCollision::UNIT_INV_TYPE type) {
    if (getInvincibleCtrlPtr() == nullptr) {
        return;
    }
    getInvincibleCtrlPtr()->addInvType(type);
}

void uDDOModel::removeInvType(nObjCollision::UNIT_INV_TYPE type) {
    if (getInvincibleCtrlPtr() == nullptr) {
        return;
    }
    getInvincibleCtrlPtr()->removeInvType(type);
}

bool uDDOModel::isInvTypeActive(nObjCollision::UNIT_INV_TYPE type) const {
    if (getInvincibleCtrlPtr() != nullptr) {
        return getInvincibleCtrlPtr()->isInvTypeActive(type);
    } else {
        return false;
    }
}

bool uDDOModel::isDamageAttrActive(u32 attr) const {
    if (getInvincibleCtrlPtr() != nullptr) {
        return getInvincibleCtrlPtr()->isDamageAttrActive(attr);
    } else {
        return false;
    }
}

bool uDDOModel::isDamageAttrOldActive(u32 attr) const {
    if (getInvincibleCtrlPtr() != nullptr) {
        return getInvincibleCtrlPtr()->isDamageAttrOldActive(attr);
    } else {
        return false;
    }
}

bool uDDOModel::isDamageAttrActive_Through(nObjCollision::DAMAGE_ATTR_ENUM attrEnum, nObjCollision::UNIT_INV_THROUGH_TYPE type) const {
    if (getInvincibleCtrlPtr() != nullptr) {
        return getInvincibleCtrlPtr()->isDamageAttrActive_Through(attrEnum, type);
    } else {
        return false;
    }
}

s32 uDDOModel::getActionStateNo() const {
    if (getStateActionPtr() != nullptr) {
        return getStateActionPtr()->getStateNo();
    } else {
        return 256;
    }
}

cState* uDDOModel::getActionState() const {
    if (getStateActionPtr() != nullptr) {
        return getStateActionPtr()->mpCurrentState;
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void uDDOModel::catchAbnormalCondition(u32 condition, f32 activeTime, nObjCondition::OCD_REASON reason, f32 cacheTime, bool isItem, nObjCondition::IMMUNE_BOOST_LV boostLv) {
    DDON_STUB("uDDOModel::catchAbnormalCondition")
    /* stub */
}

__attribute__((weak)) void uDDOModel::catchAbnormalCondition(u32 condition, nObjCondition::OCD_REASON reason, f32 cacheTime, bool isForce) {
    DDON_STUB("uDDOModel::catchAbnormalCondition")
    /* stub */
}

void uDDOModel::recoverAbnormalCondition(u32 condition) {
    if (getOcdCtrlPtr() == nullptr) {
        return;
    }
    getOcdCtrlPtr()->reqOcdCure(condition);
}

bool uDDOModel::isAbnormalConditionActive(u32 condition) const {
    if (getOcdCtrlPtr() != nullptr) {
        return getOcdCtrlPtr()->isOcdActive(condition);
    } else {
        return false;
    }
}

bool uDDOModel::healHp(HP_DATATYPE healHp, bool isWhiteHeal, u32 regionNo) {
    return false;
}

void uDDOModel::registAbsorpReqMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->registAbsorpReqMsg(srcMsg);
}

void uDDOModel::receiveAbsorpReqNetMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->receiveAbsorpReqNetMsg(srcMsg);
}

void uDDOModel::registSoulAbsorpReqMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->registSoulAbsorpReqMsg(srcMsg);
}

void uDDOModel::receiveSoulAbsorpReqNetMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg) {
    if (getHpDamageCtrlPtr() == nullptr) {
        return;
    }
    getHpDamageCtrlPtr()->receiveSoulAbsorpReqNetMsg(srcMsg);
}

void uDDOModel::registShlRequest(const nHuman::stShellRequestMsg& msg) {
    if (getShlShotCtrlPtr() == nullptr) {
        return;
    }
    getShlShotCtrlPtr()->registShellRequestMsg(msg);
}

u32 uDDOModel::getHitLightToModel() {
    return 4;
}

void uDDOModel::setGpCategory(s32 category) {
    if (getLockOnPtr() != nullptr) {
        getLockOnPtr()->setGpCategory(category);
    }
    mGpCategoy = static_cast<u32>(category);
}

__attribute__((weak)) void uDDOModel::getGeneralPointAll(MtTypedArray<cGeneralPoint>& dst) {
    DDON_STUB("uDDOModel::getGeneralPointAll")
    /* stub */
}

__attribute__((weak)) cGeneralPoint* uDDOModel::getGeneralPointFast() {
    DDON_STUB("uDDOModel::getGeneralPointFast")
    return nullptr;
}

void uDDOModel::releaseAsyncArc() {
    if (mAsyncArc.mLength == 0) {
        if (mAsyncArc.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAsyncArc.mpArray));
        }
        mAsyncArc.mpArray = nullptr;
        mAsyncArc.mBufsiz = 0;
        mAsyncArc.mLength = 0;
        return;
    } else {
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            MtObject* t0 = mAsyncArc.getBuffer()[static_cast<int>(i0_3)];
            static_cast<cAsyncArc*>(t0)->releaseArc();
            static_cast<cAsyncArc*>(t0)->cancelArc();
            v1_0 = mAsyncArc.mLength;
            if ((i0_3 + 1u) < v1_0) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
        if (v1_0 == 0) {
            if (mAsyncArc.mpArray != nullptr) {
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAsyncArc.mpArray));
            }
            mAsyncArc.mpArray = nullptr;
            mAsyncArc.mBufsiz = 0;
            mAsyncArc.mLength = 0;
            return;
        } else {
            u32 v2_0 = v1_0;
            unsigned int i2_3 = 0;
            u32 v3_0;
            for (;;) {
                if (mAsyncArc.mpArray[i2_3] == nullptr) {
                    v3_0 = v2_0;
                } else {
                    delete mAsyncArc.mpArray[i2_3];
                    v3_0 = mAsyncArc.mLength;
                }
                if ((i2_3 + 1u) < v3_0) {
                    v2_0 = v3_0;
                    i2_3 += 1u;
                } else {
                    break;
                }
            }
            if (mAsyncArc.mpArray != nullptr) {
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAsyncArc.mpArray));
            }
            mAsyncArc.mpArray = nullptr;
            mAsyncArc.mBufsiz = 0;
            mAsyncArc.mLength = 0;
            return;
        }
    }
}

__attribute__((weak)) void uDDOModel::setArcPtr(rArchive* ptr, ARC_TAGID tag) {
    DDON_STUB("uDDOModel::setArcPtr")
    /* stub */
}

bool uDDOModel::checkCalc(const cAttackParam* pAtkParam) {
    return false;
}

inline uDDOModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uDDOModel::MyDTI uDDOModel::DTI("uDDOModel", &::uModel::DTI, 9328ul, 0u, 0u);

__attribute__((weak)) MtObject* uDDOModel::MyDTI::newInstance() const {
    DDON_STUB("uDDOModel::MyDTI::newInstance")
    return nullptr;
}

void uDDOModel::cOutLineController::setup(uDDOModel* pParent, u32 outlineNo, f32 Timer) {
    mpParent = pParent;
    mOutLineNo = outlineNo;
    mTimer = Timer;
}

template MtTypedArray<cAsyncArc>::~MtTypedArray();

