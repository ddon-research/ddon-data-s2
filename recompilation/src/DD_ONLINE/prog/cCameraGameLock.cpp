// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCameraGameLock.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cCamInterporate.h"
#include "cpCharacterEdit.h"
#include "../../generated/shared/nCameraGame.h"
#include "../../generated/shared/nDDOMath.h"
#include "nLayout.h"
#include "sEnemyManager.h"
#include "sGame.h"
#include "sNpcManager.h"
#include "sOmManager.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "sPlayerManager.h"
#include "sUnitManager.h"
#include "sWorkRate.h"
#include "../../XFramework/uCamera.h"
#include "uCameraBase.h"
#include "uCameraGame.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCamExParamLock::getDTI() const {
    return cCamExParamLock::DTI;
}

inline MtAllocator* cCamExParamLock::getAllocator() {
    return MtMemoryAllocator::getAllocator(cCamExParamLock::DTI);
}

void* cCamExParamLock::operator new(size_t sz, u32 align) {
    return cCamExParamLock::getAllocator()->memAlloc(sz, align, cCamExParamLock::DTI.getID());
}

inline void cCamExParamLock::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamLock::DTI)->memFree(p_addr);
}

void cCamExParamLock::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetType", reinterpret_cast<s32*>(&mTargetType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetGroup", &mTargetGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetId", &mTargetId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetJoint", &mTargetJoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetOffset", &mTargetOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOptionFlag", &mOptionFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetH", &mOffsetH, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetV", &mOffsetV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMarginH", &mMarginH, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMarginV", &mMarginV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAngLimitX", &mAngLimitX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMarginChangeAngV", &mMarginChangeAngV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMarginHLimit", &mMarginHLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMarginInterTime", &mMarginInterTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLockOnPosMargin", &mLockOnPosMargin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLockOnPosInterRate", &mLockOnPosInterRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isTalkAdjust", &isTalkAdjust, 0u, 0u);
}

cCamExParamLock::~cCamExParamLock() {
}

__attribute__((weak)) cCamImpBase* cCamExParamLock::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamLock::createCamImpInstance")
    return nullptr;
}

__attribute__((weak)) void cCamExParamLock::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamLock::copy")
    /* stub */
}

inline cCamExParamLock::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamLock::MyDTI cCamExParamLock::DTI("cCamExParamLock", &::cCamExParam::DTI, 592ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamLock::MyDTI::newInstance() const {
    return new (16u) cCamExParamLock;
}

const MtDTI& cCamImpLock::getDTI() const {
    return cCamImpLock::DTI;
}

inline void cCamImpLock::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCamImpLock::DTI)->memFree(p_addr);
}

cCamImpLock::~cCamImpLock() {
    DDON_STUB("cCamImpLock::~cCamImpLock")
    /* stub */
}

__attribute__((weak)) void cCamImpLock::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpLock::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpLock::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpLock::ctrlSub")
    /* stub */
}

__attribute__((weak)) void cCamImpLock::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpLock::moveSub")
    /* stub */
}

__attribute__((weak)) void cCamImpLock::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
}

void cCamImpLock::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    mpC->dodgeScroll();
}

__attribute__((weak)) void cCamImpLock::finalSub() {
}

nCameraGame::CAMERA_TYPE cCamImpLock::getType() const {
    return nCameraGame::TYPE_LOCK;
}

__attribute__((weak)) void cCamImpLock::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void cCamImpLock::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("cCamImpLock::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void cCamImpLock::calcTargetPos() {
    DDON_STUB("cCamImpLock::calcTargetPos")
    /* stub */
}

inline cCamImpLock::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpLock::MyDTI cCamImpLock::DTI("cCamImpLock", &::cCamImpBase::DTI, 352ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamImpLock::MyDTI::newInstance() const {
    DDON_STUB("cCamImpLock::MyDTI::newInstance")
    return nullptr;
}

