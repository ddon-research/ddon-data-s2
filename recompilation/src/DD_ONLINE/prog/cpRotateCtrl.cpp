// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpRotateCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "../../generated/shared/nDDOMath.h"
#include "sWorkRate.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpRotateCtrl::getDTI() const {
    return cpRotateCtrl::DTI;
}

inline MtAllocator* cpRotateCtrl::getAllocator() {
    return MtMemoryAllocator::getAllocator(cpRotateCtrl::DTI);
}

void* cpRotateCtrl::operator new(size_t sz, u32 align) {
    return cpRotateCtrl::getAllocator()->memAlloc(sz, align, cpRotateCtrl::DTI.getID());
}

inline void cpRotateCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cpRotateCtrl::DTI)->memFree(p_addr);
}

cpRotateCtrl::cpRotateCtrl() {
    DDON_STUB("cpRotateCtrl::cpRotateCtrl")
    /* stub */
}

cpRotateCtrl::~cpRotateCtrl() {
}

void cpRotateCtrl::setup() {
    this->cpComponent::setup();
}

void cpRotateCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

__attribute__((weak)) void cpRotateCtrl::setOwner(MtObject* pOwner) {
    DDON_STUB("cpRotateCtrl::setOwner")
    /* stub */
}

__attribute__((weak)) void cpRotateCtrl::update() {
    DDON_STUB("cpRotateCtrl::update")
    /* stub */
}

void cpRotateCtrl::createProperty(MtPropertyList& s) {
    this->cpComponent::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsBusy", &mIsBusy, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFinalQuat", &mFinalQuat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInterSpeed", &mInterSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDefaultInterSpeed", &mDefaultInterSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDefaultInterFrame", &mDefaultInterFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAngleDiffThreshold", &mAngleDiffThreshold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableReset", &mDisableReset, 0u, 0u);
}

__attribute__((weak)) void cpRotateCtrl::setFinalQuat(const MtQuaternion& FinalQuat, f32 speed) {
    DDON_STUB("cpRotateCtrl::setFinalQuat")
    /* stub */
}

__attribute__((weak)) void cpRotateCtrl::setFinalQuatByFrame(const MtQuaternion& FinalQuat, f32 frame) {
    DDON_STUB("cpRotateCtrl::setFinalQuatByFrame")
    /* stub */
}

void cpRotateCtrl::setFinalAngleY(f32 AngleY, f32 speed) {
    MtQuaternion frame56(nDDOMath::calcQuaternionFromRotationY(AngleY));
    if (mpModel == nullptr) {
        return;
    }
    if (0.0f > speed) {
        mInterSpeed = mDefaultInterSpeed;
    } else {
        mInterSpeed = speed;
    }
    mIsBusy = true;
    mFinalQuat.x = frame56.x;
    mFinalQuat.y = frame56.y;
    mFinalQuat.z = frame56.z;
    mFinalQuat.w = frame56.w;
    mLastQuat.x = mpModel->mQuat.x;
    mLastQuat.y = mpModel->mQuat.y;
    mLastQuat.z = mpModel->mQuat.z;
    mLastQuat.w = mpModel->mQuat.w;
}

void cpRotateCtrl::setFinalAngleYByFrame(f32 AngleY, f32 frame) {
    MtQuaternion frame56(nDDOMath::calcQuaternionFromRotationY(AngleY));
    f32 speed = convertFrameToSpeed(frame56, frame);
    if (mpModel == nullptr) {
        return;
    }
    if (0.0f > speed) {
        mInterSpeed = mDefaultInterSpeed;
    } else {
        mInterSpeed = speed;
    }
    mIsBusy = true;
    mFinalQuat.x = frame56.x;
    mFinalQuat.y = frame56.y;
    mFinalQuat.z = frame56.z;
    mFinalQuat.w = frame56.w;
    mLastQuat.x = mpModel->mQuat.x;
    mLastQuat.y = mpModel->mQuat.y;
    mLastQuat.z = mpModel->mQuat.z;
    mLastQuat.w = mpModel->mQuat.w;
}

__attribute__((weak)) void cpRotateCtrl::setFinalDir(const MtVector3& dir, f32 speed) {
    DDON_STUB("cpRotateCtrl::setFinalDir")
    /* stub */
}

__attribute__((weak)) void cpRotateCtrl::setFinalDirByFrame(const MtVector3& dir, f32 frame) {
    DDON_STUB("cpRotateCtrl::setFinalDirByFrame")
    /* stub */
}

__attribute__((weak)) void cpRotateCtrl::setFinalAimPos(const MtVector3& from, const MtVector3& to, f32 speed) {
    DDON_STUB("cpRotateCtrl::setFinalAimPos")
    /* stub */
}

__attribute__((weak)) void cpRotateCtrl::setFinalAimPosByFrame(const MtVector3& from, const MtVector3& to, f32 frame) {
    DDON_STUB("cpRotateCtrl::setFinalAimPosByFrame")
    /* stub */
}

const MtQuaternion& cpRotateCtrl::getFinalQuat() {
    return mFinalQuat;
}

__attribute__((weak)) f32 cpRotateCtrl::getFinalAngleY() {
    DDON_STUB("cpRotateCtrl::getFinalAngleY")
    return {};
}

__attribute__((weak)) f32 cpRotateCtrl::convertFrameToSpeed(const MtQuaternion& FinalQuat, f32 frame) {
    DDON_STUB("cpRotateCtrl::convertFrameToSpeed")
    return {};
}

inline cpRotateCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpRotateCtrl::MyDTI cpRotateCtrl::DTI("cpRotateCtrl", &::cpComponent::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* cpRotateCtrl::MyDTI::newInstance() const {
    DDON_STUB("cpRotateCtrl::MyDTI::newInstance")
    return nullptr;
}

