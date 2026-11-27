// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCameraGamePhoto.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtString.h"
#include "cpCharacterEdit.h"
#include "../../generated/shared/nCameraGame.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "sInputManager.h"
#include "../../XFramework/sKeyboard.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sMouse.h"
#include "sMouseExt.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "sPlayerManager.h"
#include "../../XFramework/uCamera.h"
#include "uCameraBase.h"
#include "uCameraGame.h"
#include "../../XFramework/uCoord.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCamExParamPhoto::getDTI() const {
    return cCamExParamPhoto::DTI;
}

void* cCamExParamPhoto::operator new(size_t sz, u32 align) {
    return cCamExParamPhoto::getAllocator()->memAlloc(sz, align, cCamExParamPhoto::DTI.getID());
}

inline void cCamExParamPhoto::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamPhoto::DTI)->memFree(p_addr);
}

void cCamExParamPhoto::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
}

cCamExParamPhoto::~cCamExParamPhoto() {
}

void cCamExParamPhoto::copy(const cCamExParam* pParam) {
    this->cCamExParam::copy(pParam);
}

__attribute__((weak)) cCamImpBase* cCamExParamPhoto::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamPhoto::createCamImpInstance")
    return nullptr;
}

inline cCamExParamPhoto::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamPhoto::MyDTI cCamExParamPhoto::DTI("cCamExParamPhoto", &::cCamExParam::DTI, 480ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamPhoto::MyDTI::newInstance() const {
    return new (16u) cCamExParamPhoto;
}

const MtDTI& cCamImpPhoto::getDTI() const {
    return cCamImpPhoto::DTI;
}

cCamImpPhoto::~cCamImpPhoto() {
}

__attribute__((weak)) void cCamImpPhoto::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
}

__attribute__((weak)) void cCamImpPhoto::ctrlPhoto(MtVector3& camPos) {
    DDON_STUB("cCamImpPhoto::ctrlPhoto")
    /* stub */
}

void cCamImpPhoto::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    f32 j0;
    f32 j1;
    f32 j2;
    mpParamPhoto = static_cast<const cCamExParamPhoto*>(getParam());
    const f32 t0 = getParam()->mDistance;
    mPhotoDistance = t0;
    mPhotoDistanceOld = mPhotoDistance;
    f32 t1 = cameraPos.x;
    f32 t2 = cameraPos.y;
    f32 t3 = cameraPos.z;
    if (1.1920929e-7f > ((((t1 - targetPos.x) * (t1 - targetPos.x)) + ((t2 - targetPos.y) * (t2 - targetPos.y))) + ((t3 - targetPos.z) * (t3 - targetPos.z)))) {
        nCameraGame::calcCameraPos(cameraPos, targetPos, angX, angY, t0);
        f32 t4 = cameraPos.x;
        f32 t5 = cameraPos.y;
        f32 t6 = cameraPos.z;
        j0 = t4;
        j1 = t5;
        j2 = t6;
    } else {
        j0 = t1;
        j1 = t2;
        j2 = t3;
    }
    mInitAngX = angX;
    mInitAngY = angY;
    mAngYOld = angY;
    mAngXOld = angX;
    mCamPosOld.x = j0;
    mCamPosOld.y = j1;
    mCamPosOld.z = j2;
    mCamPosOld.pad_ = 0.0f;
    mTarPosOld.x = targetPos.x;
    mTarPosOld.y = targetPos.y;
    mTarPosOld.z = targetPos.z;
    mTarPosOld.pad_ = 0.0f;
    f32 t7 = static_cast<sCameraExt*>(sCamera::getInstance())->getCameraOffsetX();
    mPhotoOffsetXOld = t7;
    mPhotoOffsetX = mPhotoOffsetXOld;
    mPhotoOffsetYOld = 0.0f;
    mPhotoOffsetY = 0.0f;
    moveSub(cameraPos, targetPos, angX, angY);
    nCameraGame::CAMERA_TYPE t8 = mpC->getOldCameraType();
    const f32 t9 = mpParamPhoto->mInterCamRate;
    const f32 t10 = mpParamPhoto->mMarginAdjPow;
    mIsInterporate = true;
    if (static_cast<unsigned int>(t8) <= 1) {
        mpC->initInterSpring(t9, t10);
    } else {
        mpC->initInterParam(t9, t10);
    }
}

__attribute__((weak)) void cCamImpPhoto::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpPhoto::ctrlSub")
    /* stub */
}

__attribute__((weak)) void cCamImpPhoto::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpPhoto::moveSub")
    /* stub */
}

__attribute__((weak)) void cCamImpPhoto::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
}

__attribute__((weak)) void cCamImpPhoto::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    DDON_STUB("cCamImpPhoto::adjustSub")
    /* stub */
}

void cCamImpPhoto::finalSub() {
    if (mIsKeepAngle) {
        return;
    }
    mpC->mAngX = mInitAngX;
}

nCameraGame::CAMERA_TYPE cCamImpPhoto::getType() const {
    return nCameraGame::TYPE_PHOTO;
}

inline cCamImpPhoto::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpPhoto::MyDTI cCamImpPhoto::DTI("cCamImpPhoto", &::cCamImpBase::DTI, 320ul, 0u, 0u);

MtObject* cCamImpPhoto::MyDTI::newInstance() const {
    return new (16u) cCamImpPhoto;
}

