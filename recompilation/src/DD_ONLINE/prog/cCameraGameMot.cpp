// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCameraGameMot.h"
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
#include "../../XFramework/cUnit.h"
#include "cpCharacterEdit.h"
#include "../../generated/shared/nCameraGame.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "../../XFramework/rCameraList.h"
#include "rCameraParamList.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sPlayerManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uCamera.h"
#include "uCameraBase.h"
#include "uCameraGame.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uMotionCamera.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCamExParamMot::getDTI() const {
    return cCamExParamMot::DTI;
}

void* cCamExParamMot::operator new(size_t sz, u32 align) {
    return cCamExParamMot::getAllocator()->memAlloc(sz, align, cCamExParamMot::DTI.getID());
}

inline void cCamExParamMot::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamMot::DTI)->memFree(p_addr);
}

void cCamExParamMot::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCutNo", &mCutNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartFrame", &mStartFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOptionFlag", &mOptionFlag, 0u, 0u);
}

cCamExParamMot::~cCamExParamMot() {
}

__attribute__((weak)) cCamImpBase* cCamExParamMot::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamMot::createCamImpInstance")
    return nullptr;
}

__attribute__((weak)) void cCamExParamMot::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamMot::copy")
    /* stub */
}

inline cCamExParamMot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamMot::MyDTI cCamExParamMot::DTI("cCamExParamMot", &::cCamExParam::DTI, 480ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamMot::MyDTI::newInstance() const {
    DDON_STUB("cCamExParamMot::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamImpMot::getDTI() const {
    return cCamImpMot::DTI;
}

cCamImpMot::~cCamImpMot() {
}

__attribute__((weak)) void cCamImpMot::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("cCamImpMot::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void cCamImpMot::updateInitMat(bool isRotate) {
    DDON_STUB("cCamImpMot::updateInitMat")
    /* stub */
}

__attribute__((weak)) void cCamImpMot::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpMot::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpMot::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
}

__attribute__((weak)) void cCamImpMot::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpMot::moveSub")
    /* stub */
}

void cCamImpMot::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
    uCameraGame* t0 = mpC;
    cameraPos = t0->mIdealPosCam;
    targetPos = t0->mIdealPosTar;
}

void cCamImpMot::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    mpC->dodgeScroll();
}

__attribute__((weak)) void cCamImpMot::finalSub() {
}

nCameraGame::CAMERA_TYPE cCamImpMot::getType() const {
    return nCameraGame::TYPE_MOT;
}

inline cCamImpMot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpMot::MyDTI cCamImpMot::DTI("cCamImpMot", &::cCamImpBase::DTI, 704ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamImpMot::MyDTI::newInstance() const {
    DDON_STUB("cCamImpMot::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamImpMotTar::getDTI() const {
    return cCamImpMotTar::DTI;
}

cCamImpMotTar::~cCamImpMotTar() {
    DDON_STUB("cCamImpMotTar::~cCamImpMotTar")
    /* stub */
}

void cCamImpMotTar::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mInterLockPos.mNow.x = offset.x + mInterLockPos.mNow.x;
    mInterLockPos.mNow.y = offset.y + mInterLockPos.mNow.y;
    mInterLockPos.mNow.z = offset.z + mInterLockPos.mNow.z;
}

__attribute__((weak)) void cCamImpMotTar::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpMotTar::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpMotTar::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
}

__attribute__((weak)) void cCamImpMotTar::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpMotTar::moveSub")
    /* stub */
}

void cCamImpMotTar::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
    uCameraGame* t0 = mpC;
    cameraPos = t0->mIdealPosCam;
    targetPos = t0->mIdealPosTar;
}

void cCamImpMotTar::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    mpC->dodgeScroll();
}

__attribute__((weak)) void cCamImpMotTar::finalSub() {
}

nCameraGame::CAMERA_TYPE cCamImpMotTar::getType() const {
    return nCameraGame::TYPE_MOT_T;
}

inline cCamImpMotTar::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpMotTar::MyDTI cCamImpMotTar::DTI("cCamImpMotTar", &::cCamImpMot::DTI, 832ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamImpMotTar::MyDTI::newInstance() const {
    DDON_STUB("cCamImpMotTar::MyDTI::newInstance")
    return nullptr;
}

