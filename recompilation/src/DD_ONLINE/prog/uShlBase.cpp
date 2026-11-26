// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cComponentManager.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cDelegate.h"
#include "cEfcHandle.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "cHitNode.h"
#include "cObjHitCache.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpComponent.h"
#include "cpJob04.h"
#include "cpJob06.h"
#include "cpLockOn.h"
#include "cpObjCollision.h"
#include "cpShlShotCtrl.h"
#include "cpSlave.h"
#include "cpVibration.h"
#include "cpWorkRate.h"
#include "cpjob10.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "nShlBase.h"
#include "nShlStick.h"
#include "rAttackParam.h"
#include "rCollNode.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "rEffectProvider.h"
#include "../../XFramework/rModel.h"
#include "rObjCollision.h"
#include "rShlParamList.h"
#include "../../XFramework/rSoundRequest.h"
#include "sAIPawnSys.h"
#include "sArchiveManager.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "sControlManager.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sGeneralPoint.h"
#include "sPlayerManager.h"
#include "../../XFramework/sResource.h"
#include "sSetManager.h"
#include "sShlManager.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sWorkRate.h"
#include "uControl.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#include "uShlStick.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamBase::getDTI() const {
    return cShlParamBase::DTI;
}

inline void cShlParamBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamBase::DTI)->memFree(p_addr);
}

MtDTI& cShlParamBase::getShlDTI() const {
    return uShlBase::DTI;
}

cShlParamBase::cShlParamBase() {
    axis = static_cast<nShlBase::SHL_AXIS>(33);
    shlSetType = static_cast<SET_TYPE>(0);
    groundCkHeight = 3e+02f;
    groundOfs = 0.0f;
    isNoUseScale = false;
    rotSpd = MtVector3(0.0f, 0.0f, 0.0f);
    scale = 1.0f;
    initWaitFrame = -1.0f;
    camResType = static_cast<CAM_RES_TYPE>(0);
    cameraNo = -1;
    limitID = static_cast<nShlBase::LIMIT_ID>(-1);
    shlID = static_cast<nShlBase::SHL_ID>(0);
    shlOption = 8192u;
    isTimeDie = false;
    noDamageShlID = static_cast<nShlBase::SHL_ID>(0);
    noHitShlID = static_cast<nShlBase::SHL_ID>(0);
    shlAbilityOption = 0u;
    shlDeleteBit = 0u;
    dieFrame = 1.5e+02f;
    shlNoDie = -1;
    findGroundHeight = 1e+02f;
    dieFramePutTypeEx = 0.0f;
    isBreak = false;
    shlNoBreak = -1;
    dmgShlNo = -1;
    dmgShlInterval = 3e+01f;
    damageAttr = 1u;
    isUseHitGroup = false;
    hitGroup = 0u;
    isAtkFlgKibakuNoHit = false;
    isShotWallCheck = false;
    shotWallJnt = 0;
    changeActToDieFrame = -1.0f;
    seq_0 = -1;
    at_0 = -1;
    shared_uid_0 = -1;
    colTimer_0 = 5e+02f;
    seq_1 = -1;
    at_1 = -1;
    shared_uid_1 = -1;
    colTimer_1 = 1e+03f;
    seq_2 = -1;
    at_2 = -1;
    shared_uid_2 = -1;
    noticeType = static_cast<nShlBase::NOTICE_SHL_ID>(0);
    noticeTime = -1.0f;
    maxHitCount = -1;
    isMaxHitDie = false;
    colCustomId = -1;
    criticalBit = 0;
    epvResType = static_cast<RESOURCE_TYPE>(3);
    epvIndex = 0;
    epvNoCheckIn = -1;
    epvNoHit = -1;
    epvNoFinish = -1;
    epvNoShot = -1;
    epvNoShl = -1;
    epvCheckInterval = 0.0f;
    hitMarkType = static_cast<HIT_MARK_TYPE>(0);
    efOption = 20u;
    padVib = -1;
    padVibHit = -1;
    padVibEnd = -1;
    padVibOption = 0u;
    seResType = static_cast<RESOURCE_TYPE>(3);
    seHitResType = static_cast<RESOURCE_TYPE>(3);
    seNoLoop = -1;
    seNoLoopStop = -1;
    seNoShot = -1;
    seNoHit = -1;
    seLoopJoint = 0;
    seNoFinish = -1;
    seNoCheckIn = -1;
    seCheckInterval = 0.0f;
    seOption = 0u;
    isUseModel = false;
    modelDrawMode = 1u;
    groundCkUnderHeight = 3e+03f;
    pGroupParam = nullptr;
}

cShlParamBase::~cShlParamBase() {
}

void cShlParamBase::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "axis", reinterpret_cast<s32*>(&axis), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlSetType", reinterpret_cast<s32*>(&shlSetType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "groundCkHeight", &groundCkHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "groundCkUnderHeight", &groundCkUnderHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "groundOfs", &groundOfs, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "initWaitFrame", &initWaitFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "camResType", reinterpret_cast<s32*>(&camResType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "cameraNo", &cameraNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlID", reinterpret_cast<s32*>(&shlID), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "limitID", reinterpret_cast<s32*>(&limitID), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "rotSpd", &rotSpd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isNoUseScale", &isNoUseScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "scale", &scale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlOption", &shlOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlAbilityOption", &shlAbilityOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isTimeDie", &isTimeDie, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dieFrame", &dieFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNoDie", &shlNoDie, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlDeleteBit", &shlDeleteBit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "noDamageShlID", reinterpret_cast<s32*>(&noDamageShlID), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "noHitShlID", reinterpret_cast<s32*>(&noHitShlID), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dieFramePutTypeEx", &dieFramePutTypeEx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "findGroundHeight", &findGroundHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "changeActToDieFrame", &changeActToDieFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isBreak", &isBreak, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shlNoBreak", &shlNoBreak, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dmgShlNo", &dmgShlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "dmgShlInterval", &dmgShlInterval, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "damageAttr", &damageAttr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isUseHitGroup", &isUseHitGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitGroup", &hitGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isAtkFlgKibakuNoHit", &isAtkFlgKibakuNoHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isShotWallCheck", &isShotWallCheck, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shotWallJnt", &shotWallJnt, 0u, 0u);
    createPropertyCollision(s);
    createPropertyEffect(s);
    createPropertySE(s);
    createPropertyModel(s);
}

void cShlParamBase::createPropertyCollision(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "seq_0", &seq_0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "at_0", &at_0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shared_uid_0", &shared_uid_0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "colTimer_0", &colTimer_0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seq_1", &seq_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "at_1", &at_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shared_uid_1", &shared_uid_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "colTimer_1", &colTimer_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seq_2", &seq_2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "at_2", &at_2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "shared_uid_2", &shared_uid_2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "noticeType", reinterpret_cast<s32*>(&noticeType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "noticeTime", &noticeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "maxHitCount", &maxHitCount, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isMaxHitDie", &isMaxHitDie, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "colCustomId", &colCustomId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "criticalBit", &criticalBit, 0u, 0u);
}

void cShlParamBase::createPropertyEffect(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "epvResType", reinterpret_cast<s32*>(&epvResType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvIndex", &epvIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoShot", &epvNoShot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoShl", &epvNoShl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoHit", &epvNoHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoFinish", &epvNoFinish, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "hitMarkType", reinterpret_cast<s32*>(&hitMarkType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvNoCheckIn", &epvNoCheckIn, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "epvCheckInterval", &epvCheckInterval, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "efOption", &efOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "padVib", &padVib, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "padVibHit", &padVibHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "padVibEnd", &padVibEnd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "padVibOption", &padVibOption, 0u, 0u);
}

void cShlParamBase::createPropertySE(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "seResType", reinterpret_cast<s32*>(&seResType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seHitResType", reinterpret_cast<s32*>(&seHitResType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoShot", &seNoShot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoHit", &seNoHit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoLoop", &seNoLoop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoLoopStop", &seNoLoopStop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seLoopJoint", &seLoopJoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoFinish", &seNoFinish, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seNoCheckIn", &seNoCheckIn, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seCheckInterval", &seCheckInterval, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "seOption", &seOption, 0u, 0u);
}

void cShlParamBase::createPropertyModel(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "isUseModel", &isUseModel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "modelResPath", &modelResPath, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "modelDrawMode", &modelDrawMode, 0u, 0u);
}

__attribute__((weak)) void cShlParamBase::copy(const cShlParamBase* pParam) {
    DDON_STUB("cShlParamBase::copy")
    /* stub */
}

inline cShlParamBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamBase::MyDTI cShlParamBase::DTI("cShlParamBase", &::MtObject::DTI, 352ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamBase::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamBase::DTI)->memAlloc(sizeof(cShlParamBase), 16u, cShlParamBase::DTI.getID())) cShlParamBase;
}

const MtDTI& uShlBase::getDTI() const {
    return uShlBase::DTI;
}

inline void uShlBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlBase::DTI)->memFree(p_addr);
}

const cShlParamBase* uShlBase::getShlParam() const {
    return mpShlParam2;
}

uShlBase::uShlBase() {
    DDON_STUB("uShlBase::uShlBase")
    /* stub */
}

uShlBase::~uShlBase() {
}

__attribute__((weak)) void uShlBase::setup() {
    DDON_STUB("uShlBase::setup")
    /* stub */
}

__attribute__((weak)) void uShlBase::kill() {
    DDON_STUB("uShlBase::kill")
    /* stub */
}

__attribute__((weak)) void uShlBase::updatePtr() {
    DDON_STUB("uShlBase::updatePtr")
    /* stub */
}

void uShlBase::before() {
    mIsCreateDamageShl = false;
}

__attribute__((weak)) void uShlBase::update() {
    DDON_STUB("uShlBase::update")
    /* stub */
}

__attribute__((weak)) void uShlBase::updateSub() {
}

void uShlBase::after() {
    setCollision();
    setNoticeCollision();
}

void uShlBase::sync() {
    this->uDDOModel::sync();
}

void uShlBase::moveAfter() {
    this->uDDOModel::moveAfter();
    if (getShlParamBase()->dmgShlNo > 0) {
        if (mDamageShlIntervalTime > 0.0f) {
            mDamageShlIntervalTime = mDamageShlIntervalTime - mDeltaTime;
        }
        if (mIsCreateDamageShl) {
            mIsCreateDamageShl = false;
            createNextShl(static_cast<u32>(getShlParamBase()->dmgShlNo), 0u, false);
            mDamageShlIntervalTime = getShlParamBase()->dmgShlInterval;
        }
    }
    if (!mIsKillReq) {
        return;
    }
    mIsKillReq = false;
    kill();
}

__attribute__((weak)) void uShlBase::updateEfcHandle() {
    DDON_STUB("uShlBase::updateEfcHandle")
    /* stub */
}

void uShlBase::updateMatrix() {
    updateLocalMatrix();
    updateWorldMatrix();
}

void uShlBase::setMaster(bool is_master) {
    if (mpOwner != nullptr) {
        this->uDDOModel::setMaster(mpOwner->isMaster());
    } else {
        this->uDDOModel::setMaster(false);
    }
}

__attribute__((weak)) void uShlBase::createComponent() {
    DDON_STUB("uShlBase::createComponent")
    /* stub */
}

void uShlBase::setupComponentPtr() {
    this->uDDOModel::setupComponentPtr();
}

__attribute__((weak)) void uShlBase::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlBase::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlBase::callbackAttack(cHitInfo* pHitInfo) {
    DDON_STUB("uShlBase::callbackAttack")
    /* stub */
}

__attribute__((weak)) void uShlBase::callbackAttackTest(cHitInfo* pHitInfo) {
    DDON_STUB("uShlBase::callbackAttackTest")
    /* stub */
}

__attribute__((weak)) void uShlBase::callbackDamage(cHitInfo* pHitInfo) {
    DDON_STUB("uShlBase::callbackDamage")
    /* stub */
}

__attribute__((weak)) void uShlBase::callbackCheck(cHitInfo* pHitInfo) {
    DDON_STUB("uShlBase::callbackCheck")
    /* stub */
}

__attribute__((weak)) void uShlBase::callbackHeal(cHitInfo* pHitInfo) {
    DDON_STUB("uShlBase::callbackHeal")
    /* stub */
}

void uShlBase::callbackGuarded(cHitInfo* pHitInfo) {
    this->uDDOModel::callbackGuarded(pHitInfo);
    mHitResultFlag = mHitResultFlag | 8u;
    mHitPos = pHitInfo->mHitPos;
    mHitEfctFlag = 1;
}

bool uShlBase::callbackRegistInterPolateGeom(MtVector3& oldPos, const MtVector3& currentPos, f32 radius, const cHitGeom* pGeom) {
    return false;
}

void uShlBase::setShotCoord(const MtVector3& pos, const MtVector3& dir) {
    if (getShlParamBase() == nullptr) {
        return;
    }
    mPos.x = pos.x;
    mPos.y = pos.y;
    mPos.z = pos.z;
    mPos.pad_ = 0.0f;
    mShlMoveDir.x = dir.x;
    mShlMoveDir.y = dir.y;
    mShlMoveDir.z = dir.z;
    mShlMoveDir.pad_ = 0.0f;
    mLookPos.x = mPos.x;
    mLookPos.y = mPos.y;
    mLookPos.z = mPos.z;
    mLookPos.pad_ = 0.0f;
    setAngle(dir, MtVector3::AxisY, MtVector3::AxisZ, getShlParamBase()->getShlAxis());
}

void uShlBase::setShotCoord(const MtVector3& pos, const MtVector3& dir, const MtMatrix& mat) {
    if (mpShlParam2 == nullptr) {
        return;
    }
    mPos.x = pos.x;
    mPos.y = pos.y;
    mPos.z = pos.z;
    mPos.pad_ = 0.0f;
    mShlMoveDir.x = dir.x;
    mShlMoveDir.y = dir.y;
    mShlMoveDir.z = dir.z;
    mShlMoveDir.pad_ = 0.0f;
    mLookPos.x = mPos.x;
    mLookPos.y = mPos.y;
    mLookPos.z = mPos.z;
    mLookPos.pad_ = 0.0f;
    setAngle(mat);
}

__attribute__((weak)) void uShlBase::setAngle(const MtVector3& main, const MtVector3& up, const MtVector3& up2, nShlBase::SHL_AXIS axis) {
    DDON_STUB("uShlBase::setAngle")
    /* stub */
}

__attribute__((weak)) void uShlBase::setAngle(const MtMatrix& mat) {
    DDON_STUB("uShlBase::setAngle")
    /* stub */
}

const MtVector3& uShlBase::getTargetPos() const {
    return mTargetPos;
}

f32 uShlBase::calcSpeed(f32 spd, f32 accel, f32 max, f32 deltaTime) {
    if (accel > 0.0f) {
        if ((spd + (accel * deltaTime)) > max) {
            return max;
        } else {
            return spd + (accel * deltaTime);
        }
    } else {
        if (0.0f > accel) {
            if (max > (spd + (accel * deltaTime))) {
                return max;
            } else {
                return spd + (accel * deltaTime);
            }
        } else {
            return spd;
        }
    }
}

void uShlBase::inheritParent(uShlBase* pParent) {
    mIsInherit = true;
    if (getObjCollisionPtr() == nullptr) {
        return;
    }
    if (pParent == nullptr) {
        return;
    }
    if (pParent->getObjCollisionPtr() == nullptr) {
        return;
    }
    getObjCollisionPtr()->copySharedUID(pParent->getObjCollisionPtr());
}

__attribute__((weak)) MtVector3 uShlBase::getMatMainDir() const {
    DDON_STUB("uShlBase::getMatMainDir")
    __builtin_unreachable();
}

bool uShlBase::isShlOption(u32 flag) const {
    if (getShlParamBase() != nullptr) {
        return (flag & getShlParamBase()->shlOption) != 0;
    } else {
        return false;
    }
}

__attribute__((weak)) void uShlBase::requestKill() {
    DDON_STUB("uShlBase::requestKill")
    /* stub */
}

__attribute__((weak)) void uShlBase::initSub() {
}

__attribute__((weak)) void uShlBase::setShlEfct() {
    DDON_STUB("uShlBase::setShlEfct")
    /* stub */
}

__attribute__((weak)) void uShlBase::setMuzzle(const MtVector3& dir, const MtVector3& pos, f32 scale) {
    DDON_STUB("uShlBase::setMuzzle")
    /* stub */
}

__attribute__((weak)) void uShlBase::setHitMark(const MtVector3& pos, f32 scale) {
    DDON_STUB("uShlBase::setHitMark")
    /* stub */
}

__attribute__((weak)) void uShlBase::setFinishEfct() {
    DDON_STUB("uShlBase::setFinishEfct")
    /* stub */
}

__attribute__((weak)) void uShlBase::requestShotSE() {
    DDON_STUB("uShlBase::requestShotSE")
    /* stub */
}

__attribute__((weak)) void uShlBase::requestHitSE() {
    DDON_STUB("uShlBase::requestHitSE")
    /* stub */
}

__attribute__((weak)) void uShlBase::requestLoopSE() {
    DDON_STUB("uShlBase::requestLoopSE")
    /* stub */
}

__attribute__((weak)) void uShlBase::requestLoopStopSE() {
    DDON_STUB("uShlBase::requestLoopStopSE")
    /* stub */
}

__attribute__((weak)) void uShlBase::requestCmnCastSE(s32 no) {
}

__attribute__((weak)) bool uShlBase::isCollisionWall(sCollision::TriangleInfo& info, const MtVector3& pos, const MtVector3& posOld, u32* intercect) {
    DDON_STUB("uShlBase::isCollisionWall")
    return {};
}

__attribute__((weak)) void uShlBase::setCollision() {
    if (mpParent != nullptr) {
        if (mpOwner != nullptr) {
            goto region_cc43fe;
        }
    }
    if (mIsCreateColOnce) {
        getObjCollisionPtr()->killNode(0u, static_cast<u32>(mCreateSeqNo));
    }
    region_cc43fe:;
    if (mpOwner == nullptr) {
        return;
    } else {
        if (getObjCollisionPtr()->mpResource[0] == nullptr) {
            return;
        } else {
            if (!getObjCollisionPtr()->mpResource[0]->cResource::isUsage()) {
                return;
            } else {
                u32 t0 = getCollisionIndex();
                const s32* v2_0;
                const s32* v2_1;
                const s32* v2_2;
                if (t0 != 2) {
                    if (t0 == 1) {
                        v2_0 = &getShlParamBase()->at_1;
                        v2_1 = &getShlParamBase()->seq_1;
                        v2_2 = &getShlParamBase()->shared_uid_1;
                    } else {
                        v2_0 = &getShlParamBase()->at_0;
                        v2_1 = &getShlParamBase()->seq_0;
                        v2_2 = &getShlParamBase()->shared_uid_0;
                    }
                } else {
                    v2_0 = &getShlParamBase()->at_2;
                    v2_1 = &getShlParamBase()->seq_2;
                    v2_2 = &getShlParamBase()->shared_uid_2;
                }
                s32 v3_9 = *v2_1;
                if (v3_9 != -1) {
                    s32 v3_10 = *v2_2;
                    if ((*v2_0) != -1) {
                        if (mpAtkNode != nullptr) {
                            mpAtkNode->setAttackParamFromAttackNo(static_cast<u32>(*v2_0));
                        }
                    }
                    setCollisionSub(v3_9, 0, 0, v3_10);
                }
                return;
            }
        }
    }
}

void uShlBase::setCollisionSub(s32 seqNo, s32 groupNo, s32 attackNo, s32 shared_uid) {
    if (mCreateSeqNo == seqNo) {
        return;
    }
    if (mIsCreateColOnce) {
        getObjCollisionPtr()->killNode(0u, static_cast<u32>(mCreateSeqNo));
    }
    mIsCreateColOnce = true;
    mCreateSeqNo = seqNo;
    mInterPos.x = mOldPos.x;
    mInterPos.y = mOldPos.y;
    mInterPos.z = mOldPos.z;
    mInterPos.pad_ = 0.0f;
    if (shared_uid > -1) {
        mpAtkNode = getObjCollisionPtr()->createNodeFromIndex(0u, seqNo, false, getObjCollisionPtr()->getSharedUID(static_cast<unsigned int>(shared_uid)));
    } else {
        mpAtkNode = getObjCollisionPtr()->createNodeFromIndex(0u, seqNo, false, 0xFFFFFFFFu);
    }
}

__attribute__((weak)) void uShlBase::setNoticeCollision() {
    DDON_STUB("uShlBase::setNoticeCollision")
    /* stub */
}

u32 uShlBase::getCollisionIndex() const {
    if (getShlParamBase()->colTimer_0 > mTimer) {
        return 0;
    } else {
        if (getShlParamBase()->colTimer_1 > mTimer) {
            return 1;
        } else {
            return 2;
        }
    }
}

__attribute__((weak)) f32 uShlBase::homingPos(MtVector3& moveVec, const MtVector3& targetPos, f32 rad) {
    DDON_STUB("uShlBase::homingPos")
    return {};
}

__attribute__((weak)) f32 uShlBase::homingDir(MtVector3& moveVec, const MtVector3& targetVec, f32 rad) {
    DDON_STUB("uShlBase::homingDir")
    return {};
}

void uShlBase::calcMoveVector(MtVector3& vec, s32 joint) {
    f32 t0 = mPos.y;
    f32 t1 = mOldPos.y;
    f32 t2 = mPos.z;
    f32 t3 = mOldPos.z;
    vec.x = mPos.x - mOldPos.x;
    vec.y = t0 - t1;
    vec.z = t2 - t3;
    vec.pad_ = 0.0f;
}

s32 uShlBase::getEpvIndex() const {
    return getShlParamBase()->epvIndex;
}

nShlBase::LIMIT_ID uShlBase::getLimitID() const {
    if (getShlParamBase() != nullptr) {
        return getShlParamBase()->limitID;
    } else {
        return nShlBase::LIMIT_ID_NONE;
    }
}

__attribute__((weak)) uShlBase* uShlBase::createNextShl(u32 index, u32 shotSts, bool isNow) {
    DDON_STUB("uShlBase::createNextShl")
    return nullptr;
}

void uShlBase::addShlDamage(cHitInfo* pHitInfo) {
    const cShlParamBase* v0_1 = getShlParamBase();
    u32 v0_0 = v0_1->shlOption;
    if (((v0_0 >> 8) & 4u) != 0) {
        if (pHitInfo->mpAtkModel != nullptr) {
            if ((pHitInfo->mpAtkModel->mUnitId & 32u) != 0) {
                if (static_cast<unsigned int>(v0_1->noDamageShlID) == (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pHitInfo->mpAtkModel) + 9352))) {
                    return;
                }
            }
        }
    }
    if (v0_1->dmgShlNo > 0) {
        if (0.0f >= mDamageShlIntervalTime) {
            mIsCreateDamageShl = true;
        }
    }
    if ((v0_0 & 16u) == 0) {
        executeAddDamage();
        return;
    }
    uDDOModel* v3_3;
    if (pHitInfo->mpAtkModel != nullptr) {
        if ((pHitInfo->mpAtkModel->mUnitId & 32u) == 0) {
            v3_3 = pHitInfo->mpAtkModel;
        } else {
            if (static_cast<uShlBase*>(pHitInfo->mpAtkModel)->getOwner() != nullptr) {
                v3_3 = static_cast<uShlBase*>(pHitInfo->mpAtkModel)->getOwner();
            } else {
                return;
            }
        }
    } else {
        return;
    }
    if (v3_3->isMaster()) {
        executeAddDamage();
        return;
    }
}

void uShlBase::executeAddDamage() {
    mDamage = mDamage + 1.0f;
}

__attribute__((weak)) void uShlBase::requestSE(s32 reqNo, const MtVector3& pos) {
    DDON_STUB("uShlBase::requestSE")
    /* stub */
}

__attribute__((weak)) void uShlBase::requestSE(s32 reqNo, uCoord* pCoord) {
    DDON_STUB("uShlBase::requestSE")
    /* stub */
}

__attribute__((weak)) void uShlBase::requestSE(s32 reqNo, uCoord* pCoord, s32 joint) {
    DDON_STUB("uShlBase::requestSE")
    /* stub */
}

__attribute__((weak)) void uShlBase::requestSE(rSoundRequest* pRes, s32 reqNo, const MtVector3& pos) {
    DDON_STUB("uShlBase::requestSE")
    /* stub */
}

__attribute__((weak)) cEfcHandle* uShlBase::setEffect(s32 epvNo) {
    DDON_STUB("uShlBase::setEffect")
    return nullptr;
}

__attribute__((weak)) cEfcHandle* uShlBase::setEffect(s32 epvNo, const MtVector3& pos) {
    DDON_STUB("uShlBase::setEffect")
    return nullptr;
}

__attribute__((weak)) cEfcHandle* uShlBase::setEffect(s32 epvNo, sEffectExt::EfcParam& param) {
    DDON_STUB("uShlBase::setEffect")
    return nullptr;
}

uDDOModel* uShlBase::getEfctParent() {
    if ((getShlParamBase()->efOption & 1u) != 0) {
        return mpOwner;
    } else {
        return this;
    }
}

__attribute__((weak)) void uShlBase::requestShlVibration(u32 type) {
    DDON_STUB("uShlBase::requestShlVibration")
    /* stub */
}

u32 uShlBase::getHitLightToModel() {
    return 1;
}

bool uShlBase::isOwnerCatch() const {
    return false;
}

__attribute__((weak)) void uShlBase::adjustDirToTarget(const cGeneralPoint* pTarget, const MtVector3& initVec, f32 rate) {
    DDON_STUB("uShlBase::adjustDirToTarget")
    /* stub */
}

__attribute__((weak)) void uShlBase::adjustDirToMove() {
    DDON_STUB("uShlBase::adjustDirToMove")
    /* stub */
}

inline uShlBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlBase::MyDTI uShlBase::DTI("uShlBase", &::uDDOModel::DTI, 10928ul, 0u, 0u);

__attribute__((weak)) MtObject* uShlBase::MyDTI::newInstance() const {
    DDON_STUB("uShlBase::MyDTI::newInstance")
    return nullptr;
}

