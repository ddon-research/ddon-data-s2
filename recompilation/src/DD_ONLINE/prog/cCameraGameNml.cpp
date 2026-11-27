// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCameraGameNml.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cCamInterporate.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "cpCharacterEdit.h"
#include "../../generated/shared/nCameraGame.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "sGame.h"
#include "sInputManager.h"
#include "sPlayerManager.h"
#include "sWorkRate.h"
#include "../../XFramework/uCamera.h"
#include "uCameraBase.h"
#include "uCameraGame.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCamExParamNml::getDTI() const {
    return cCamExParamNml::DTI;
}

void* cCamExParamNml::operator new(size_t sz, u32 align) {
    return cCamExParamNml::getAllocator()->memAlloc(sz, align, cCamExParamNml::DTI.getID());
}

inline void cCamExParamNml::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamNml::DTI)->memFree(p_addr);
}

void cCamExParamNml::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsResetAngle", &mIsResetAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsTargetFlipX", &mIsTargetFlipX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsTargetOwner", &mIsTargetOwner, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableLargeCorrect", &mDisableLargeCorrect, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecRate", &mMoveVecRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecInterRate", &mMoveVecInterRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecCtrlStopFrame", &mMoveVecCtrlStopFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecRateV", &mMoveVecRateV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecInterRateV", &mMoveVecInterRateV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecCtrlStopFrameV", &mMoveVecCtrlStopFrameV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVOffset", &mMoveVecVOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVOffsetTwn", &mMoveVecVOffsetTwn, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVOffsetDgn", &mMoveVecVOffsetDgn, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVScaleUp", &mMoveVecVScaleUp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVScaleDown", &mMoveVecVScaleDown, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCtrlSpeedRateX", &mCtrlSpeedRateX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetMarginRateH", &mTargetMarginRateH, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetMarginRateV", &mTargetMarginRateV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetOffsetH", &mTargetOffsetH, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetOffsetV", &mTargetOffsetV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetInterRateX", &mTargetInterRateX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetInterRateY", &mTargetInterRateY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateXOffsetUp", &mRotateXOffsetUp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateXOffsetUpY", &mRotateXOffsetUpY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateXOffsetDown", &mRotateXOffsetDown, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateXOffsetDownY", &mRotateXOffsetDownY, 0u, 0u);
}

cCamExParamNml::~cCamExParamNml() {
}

__attribute__((weak)) void cCamExParamNml::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamNml::copy")
    /* stub */
}

__attribute__((weak)) cCamImpBase* cCamExParamNml::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamNml::createCamImpInstance")
    return nullptr;
}

inline cCamExParamNml::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamNml::MyDTI cCamExParamNml::DTI("cCamExParamNml", &::cCamExParam::DTI, 576ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamNml::MyDTI::newInstance() const {
    return new (16u) cCamExParamNml;
}

const MtDTI& cCamExParamNml2::getDTI() const {
    return cCamExParamNml2::DTI;
}

void* cCamExParamNml2::operator new(size_t sz, u32 align) {
    return cCamExParamNml2::getAllocator()->memAlloc(sz, align, cCamExParamNml2::DTI.getID());
}

inline void cCamExParamNml2::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamNml2::DTI)->memFree(p_addr);
}

void cCamExParamNml2::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsResetAngle", &mIsResetAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsResetAngleDetail", &mIsResetAngleDetail, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResetDetailAngX", &mResetDetailAngX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResetDetailAngY", &mResetDetailAngY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsTargetFlipX", &mIsTargetFlipX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsTargetOwner", &mIsTargetOwner, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableLargeCorrect", &mDisableLargeCorrect, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecRate", &mMoveVecRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecInterRate", &mMoveVecInterRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecCtrlStopFrame", &mMoveVecCtrlStopFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecRateV", &mMoveVecRateV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecInterRateV", &mMoveVecInterRateV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecCtrlStopFrameV", &mMoveVecCtrlStopFrameV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVOffset", &mMoveVecVOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVOffsetTwn", &mMoveVecVOffsetTwn, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVOffsetDgn", &mMoveVecVOffsetDgn, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVScaleUp", &mMoveVecVScaleUp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveVecVScaleDown", &mMoveVecVScaleDown, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCtrlSpeedRateX", &mCtrlSpeedRateX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetMarginRateH", &mTargetMarginRateH, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetMarginRateV", &mTargetMarginRateV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetOffsetH", &mTargetOffsetH, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetOffsetV", &mTargetOffsetV, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetInterRateX", &mTargetInterRateX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetInterRateY", &mTargetInterRateY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateXOffsetUp", &mRotateXOffsetUp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateXOffsetUpY", &mRotateXOffsetUpY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateXOffsetDown", &mRotateXOffsetDown, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotateXOffsetDownY", &mRotateXOffsetDownY, 0u, 0u);
}

cCamExParamNml2::~cCamExParamNml2() {
}

__attribute__((weak)) void cCamExParamNml2::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamNml2::copy")
    /* stub */
}

__attribute__((weak)) cCamImpBase* cCamExParamNml2::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamNml2::createCamImpInstance")
    return nullptr;
}

inline cCamExParamNml2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamNml2::MyDTI cCamExParamNml2::DTI("cCamExParamNml2", &::cCamExParamNml::DTI, 576ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamNml2::MyDTI::newInstance() const {
    return new (16u) cCamExParamNml2;
}

const MtDTI& cCamImpNml::getDTI() const {
    return cCamImpNml::DTI;
}

void* cCamImpNml::operator new(size_t sz, u32 align) {
    return cCamImpNml::getAllocator()->memAlloc(sz, align, cCamImpNml::DTI.getID());
}

cCamImpNml::cCamImpNml() {
    DDON_STUB("cCamImpNml::cCamImpNml")
    /* stub */
}

cCamImpNml::~cCamImpNml() {
    DDON_STUB("cCamImpNml::~cCamImpNml")
    /* stub */
}

void cCamImpNml::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    camOld.x = offset.x + camOld.x;
    camOld.y = offset.y + camOld.y;
    camOld.z = offset.z + camOld.z;
}

__attribute__((weak)) void cCamImpNml::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpNml::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpNml::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpNml::ctrlSub")
    /* stub */
}

__attribute__((weak)) void cCamImpNml::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpNml::moveSub")
    /* stub */
}

__attribute__((weak)) void cCamImpNml::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
}

void cCamImpNml::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    mpC->dodgeScroll();
}

void cCamImpNml::finalSub() {
    if (mIsKeepAngle) {
        return;
    }
    mpC->mAngX = mInitAngX;
}

nCameraGame::CAMERA_TYPE cCamImpNml::getType() const {
    return nCameraGame::TYPE_NML;
}

inline cCamImpNml::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpNml::MyDTI cCamImpNml::DTI("cCamImpNml", &::cCamImpBase::DTI, 496ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamImpNml::MyDTI::newInstance() const {
    DDON_STUB("cCamImpNml::MyDTI::newInstance")
    return nullptr;
}

