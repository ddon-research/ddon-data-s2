// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cHumanActionClimb.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtPrimitive3D.h"
#include "cAction.h"
#include "cContextPlayerInfo.h"
#include "cHitGeom.h"
#include "cHumanAction.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpActionSelect.h"
#include "cpComponent.h"
#include "cpInput.h"
#include "cpObjCollision.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cHumanActEnemyClimb::getDTI() const {
    return cHumanActEnemyClimb::DTI;
}

void cHumanActEnemyClimb::init() {
    this->cHumanActBase::init();
    mNotFoundNodeTime = 0.0f;
    if ((mpHuman->getActMgrPtr()->getActionNo() & 0xFFFFFFFEu) != 36) {
        mpHuman->setEnemyClimbPivot(mClimbPivotOffset);
    }
    mUpdateFollowCapsule = false;
    mUpDown = 0;
    mRightLeft = 0;
    mPhaseClimbVert = 0;
    mIsEnd = 0;
    mIsVertical = true;
    mCapMissingTimer = 0.0f;
    mMoveDir.x = MtVector3::Zero.x;
    mMoveDir.y = MtVector3::Zero.y;
    mMoveDir.z = MtVector3::Zero.z;
    mMoveDir.pad_ = 0.0f;
    mKeepDir = false;
    mpHuman->setDDOMotion(MOT_BASE, 603u, true, 0u, -1.0f, 0.0f, 1.0f);
    mpHuman->setDDOMotion(MOT_BLEND1, 603u, true, 0u, -1.0f, 0.0f, 1.0f);
    mpHuman->setMotionBlendRate(0u, 1.0f);
    mpHuman->setMotionBlendRate(1u, 0.0f);
    mpHuman->setDrawingSword(false);
}

__attribute__((weak)) void cHumanActEnemyClimb::move() {
    DDON_STUB("cHumanActEnemyClimb::move")
    /* stub */
}

void cHumanActEnemyClimb::final() {
    this->cHumanActBase::final();
    mpHuman->setMotionBlendRate(0u, 1.0f);
    mpHuman->setMotionBlendRate(1u, 0.0f);
    mpHuman->setDDOMotion(MOT_BLEND1, 0xFFFFu, true, 0u, -1.0f, 0.0f, 1.0f);
    uDDOModel* t1 = mpModel;
    MtVector3 frame56(mpHuman->getAngle());
    t1->setFinalAngleY(frame56.y, -1.0f);
    mpHuman->setPivotActive(false);
}

__attribute__((weak)) void cHumanActEnemyClimb::moveAfter() {
    DDON_STUB("cHumanActEnemyClimb::moveAfter")
    /* stub */
}

bool cHumanActEnemyClimb::checkEscape() {
    return this->cHumanActEnemyClimbBase::checkEscape();
}

__attribute__((weak)) void cHumanActEnemyClimb::moveClimbVert() {
    DDON_STUB("cHumanActEnemyClimb::moveClimbVert")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimb::moveBeforSlave() {
    DDON_STUB("cHumanActEnemyClimb::moveBeforSlave")
    /* stub */
}

inline cHumanActEnemyClimb::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActEnemyClimb::MyDTI cHumanActEnemyClimb::DTI("cHumanActEnemyClimb", &::cHumanActEnemyClimbBase::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* cHumanActEnemyClimb::MyDTI::newInstance() const {
    DDON_STUB("cHumanActEnemyClimb::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cHumanActEnemyClimbBase::getDTI() const {
    return cHumanActEnemyClimbBase::DTI;
}

cHumanActEnemyClimbBase::cHumanActEnemyClimbBase() {
    DDON_STUB("cHumanActEnemyClimbBase::cHumanActEnemyClimbBase")
    /* stub */
}

void cHumanActEnemyClimbBase::init() {
    this->cHumanActBase::init();
    mNotFoundNodeTime = 0.0f;
    if ((mpHuman->getActMgrPtr()->getActionNo() & 0xFFFFFFFEu) != 36) {
        mpHuman->setEnemyClimbPivot(mClimbPivotOffset);
    }
}

void cHumanActEnemyClimbBase::final() {
    this->cHumanActBase::final();
}

__attribute__((weak)) bool cHumanActEnemyClimbBase::checkEscape() {
    DDON_STUB("cHumanActEnemyClimbBase::checkEscape")
    return {};
}

__attribute__((weak)) bool cHumanActEnemyClimbBase::findClimbCapsule2(uDDOModel* pObjModel, uHuman::cEnemyClimbInfo* climbInfo, uHuman* pHuman, MtVector3& ret_pos, MtQuaternion& ret_quat, MtVector3& ret_push_pos) {
    DDON_STUB("cHumanActEnemyClimbBase::findClimbCapsule2")
    return {};
}

__attribute__((weak)) bool cHumanActEnemyClimbBase::findClimbCapsuleError() {
    DDON_STUB("cHumanActEnemyClimbBase::findClimbCapsuleError")
    return {};
}

__attribute__((weak)) void cHumanActEnemyClimbBase::calcCapsuleHitPos(const MtCapsule& cap, const MtVector3& pos, MtVector3& hit_pos, MtVector3& normal) {
    DDON_STUB("cHumanActEnemyClimbBase::calcCapsuleHitPos")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimbBase::initFollowCapsule(uHuman::cEnemyClimbInfo* climbInfo, uHuman* pHuman) {
    DDON_STUB("cHumanActEnemyClimbBase::initFollowCapsule")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimbBase::updateFollowCapsule(uHuman::cEnemyClimbInfo* climbInfo, uHuman* pHuman) {
    DDON_STUB("cHumanActEnemyClimbBase::updateFollowCapsule")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimbBase::followCapsule(uHuman::cEnemyClimbInfo* climbInfo, uHuman* pHuman) {
    DDON_STUB("cHumanActEnemyClimbBase::followCapsule")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimbBase::storeClimbInfo(uHuman::cEnemyClimbInfo* pClimbInfo, const cHitGeom* pGeom, uDDOModel* pDDOModel) {
    DDON_STUB("cHumanActEnemyClimbBase::storeClimbInfo")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimbBase::keepHeadUp(f32 rotSpeed) {
    DDON_STUB("cHumanActEnemyClimbBase::keepHeadUp")
    /* stub */
}

void cHumanActEnemyClimbBase::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mpHuman->mEnemyClimbInfo.mStableWMat.m[3].x = offset.x + mpHuman->mEnemyClimbInfo.mStableWMat.m[3].x;
    mpHuman->mEnemyClimbInfo.mStableWMat.m[3].y = offset.y + mpHuman->mEnemyClimbInfo.mStableWMat.m[3].y;
    mpHuman->mEnemyClimbInfo.mStableWMat.m[3].z = offset.z + mpHuman->mEnemyClimbInfo.mStableWMat.m[3].z;
}

__attribute__((weak)) void cHumanActEnemyClimbBase::updateInterpolatePos(MtVector3& pos, f32 deltaTime) {
    DDON_STUB("cHumanActEnemyClimbBase::updateInterpolatePos")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimbBase::updateClimbInterpolatePos(uHuman& human) {
    DDON_STUB("cHumanActEnemyClimbBase::updateClimbInterpolatePos")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimbBase::setInterpolatePos4AtkAct(uHuman& human, f32 length) {
    DDON_STUB("cHumanActEnemyClimbBase::setInterpolatePos4AtkAct")
    /* stub */
}

__attribute__((weak)) void cHumanActEnemyClimbBase::debugDispTargetPos(uHuman& human) {
}

inline cHumanActEnemyClimbBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanActEnemyClimbBase::MyDTI cHumanActEnemyClimbBase::DTI("cHumanActEnemyClimbBase", &::cHumanActBase::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* cHumanActEnemyClimbBase::MyDTI::newInstance() const {
    DDON_STUB("cHumanActEnemyClimbBase::MyDTI::newInstance")
    return nullptr;
}

