// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCameraGameTps.h"
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
#include "../../XFramework/cUnit.h"
#include "cpCharacterEdit.h"
#include "../../generated/shared/nCameraGame.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "../../XFramework/sMain.h"
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

const MtDTI& cCamExParamTps::getDTI() const {
    return cCamExParamTps::DTI;
}

void* cCamExParamTps::operator new(size_t sz, u32 align) {
    return cCamExParamTps::getAllocator()->memAlloc(sz, align, cCamExParamTps::DTI.getID());
}

inline void cCamExParamTps::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamTps::DTI)->memFree(p_addr);
}

void cCamExParamTps::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsResetAngle", &mIsResetAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ctrlSpeed", &ctrlSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isUseLimit", &isUseLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "limitDeg", &limitDeg, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isFollowAngle", &isFollowAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isNoHeightCorrect", &isNoHeightCorrect, 0u, 0u);
}

cCamExParamTps::~cCamExParamTps() {
}

__attribute__((weak)) cCamImpBase* cCamExParamTps::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamTps::createCamImpInstance")
    return nullptr;
}

__attribute__((weak)) void cCamExParamTps::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamTps::copy")
    /* stub */
}

inline cCamExParamTps::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamTps::MyDTI cCamExParamTps::DTI("cCamExParamTps", &::cCamExParam::DTI, 496ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamTps::MyDTI::newInstance() const {
    return new (16u) cCamExParamTps;
}

const MtDTI& cCamExParamTps2::getDTI() const {
    return cCamExParamTps2::DTI;
}

void* cCamExParamTps2::operator new(size_t sz, u32 align) {
    return cCamExParamTps2::getAllocator()->memAlloc(sz, align, cCamExParamTps2::DTI.getID());
}

inline void cCamExParamTps2::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamTps2::DTI)->memFree(p_addr);
}

void cCamExParamTps2::createProperty(MtPropertyList& s) {
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
    s << MtProperty(static_cast<MtObject*>(this), "ctrlSpeed", &ctrlSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isUseLimit", &isUseLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "limitDeg", &limitDeg, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isFollowAngle", &isFollowAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isNoHeightCorrect", &isNoHeightCorrect, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnableLargeCorrect", &mEnableLargeCorrect, 0u, 0u);
}

cCamExParamTps2::~cCamExParamTps2() {
}

__attribute__((weak)) cCamImpBase* cCamExParamTps2::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamTps2::createCamImpInstance")
    return nullptr;
}

__attribute__((weak)) void cCamExParamTps2::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamTps2::copy")
    /* stub */
}

inline cCamExParamTps2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamTps2::MyDTI cCamExParamTps2::DTI("cCamExParamTps2", &::cCamExParamTps::DTI, 496ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamTps2::MyDTI::newInstance() const {
    return new (16u) cCamExParamTps2;
}

const MtDTI& cCamImpTps::getDTI() const {
    return cCamImpTps::DTI;
}

cCamImpTps::~cCamImpTps() {
}

__attribute__((weak)) void cCamImpTps::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) void cCamImpTps::recoilMove(f32& ang, f32& value, bool& isMove, f32& scale, f32& frame, f32 frameMax) {
    DDON_STUB("cCamImpTps::recoilMove")
    /* stub */
}

__attribute__((weak)) void cCamImpTps::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpTps::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpTps::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpTps::ctrlSub")
    /* stub */
}

__attribute__((weak)) void cCamImpTps::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpTps::moveSub")
    /* stub */
}

__attribute__((weak)) void cCamImpTps::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
}

void cCamImpTps::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    mpC->dodgeScroll();
}

__attribute__((weak)) void cCamImpTps::finalSub() {
    DDON_STUB("cCamImpTps::finalSub")
    /* stub */
}

nCameraGame::CAMERA_TYPE cCamImpTps::getType() const {
    return nCameraGame::TYPE_TPS;
}

inline cCamImpTps::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpTps::MyDTI cCamImpTps::DTI("cCamImpTps", &::cCamImpBase::DTI, 264ul, 0u, 0u);

alignas(4) unsigned char cCamImpTps_maxSpeedCurveX_bytes[64] __asm__("_ZN10cCamImpTps14maxSpeedCurveXE") = {0x00, 0x00, 0x00, 0x00, 0x44, 0x6f, 0x89, 0x3e, 0xa6, 0x64, 0x25, 0x3f, 0x89, 0x0b, 0x5c, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd2, 0x3a, 0x5a, 0x3e, 0x55, 0x32, 0x04, 0x3f, 0x2a, 0x8d, 0x54, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f};

MtObject* cCamImpTps::MyDTI::newInstance() const {
    return new (16u) cCamImpTps;
}

