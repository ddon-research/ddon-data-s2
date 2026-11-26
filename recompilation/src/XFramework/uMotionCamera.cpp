// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uMotionCamera.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "nMotion.h"
#include "rCameraList.h"
#include "uCamera.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uMotionCamera::usage() {
}

const MtDTI& uMotionCamera::getDTI() const {
    return uMotionCamera::DTI;
}

inline void* uMotionCamera::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uMotionCamera::DTI)->memAlloc(sz, align, uMotionCamera::DTI.mID);
}

inline void uMotionCamera::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uMotionCamera::DTI)->memFree(p_addr);
}

uMotionCamera::uMotionCamera() {
    mpCameraList = nullptr;
    mCut = 0;
    mFrame = 0.0f;
    mSpeed = 1.0f;
    mShowLineOfSight = false;
    mFovType = 0;
    mTrackLink = false;
    mRepeat = false;
    mCutRepeat = false;
    mShowPath = false;
    mOffsetPos.x = MtVector3::Zero.x;
    mOffsetPos.y = MtVector3::Zero.y;
    mOffsetPos.z = MtVector3::Zero.z;
    mOffsetPos.pad_ = 0.0f;
    mTrackPos.x = MtVector3::Zero.x;
    mTrackPos.y = MtVector3::Zero.y;
    mTrackPos.z = MtVector3::Zero.z;
    mTrackPos.pad_ = 0.0f;
    mTrackTarget.x = MtVector3::Zero.x;
    mTrackTarget.y = MtVector3::Zero.y;
    mTrackTarget.z = MtVector3::Zero.z;
    mTrackTarget.pad_ = 0.0f;
    mRoll = 0.0f;
    mZoom = 0.0f;
    mpParent = nullptr;
    mParentNo = -1;
    mPrevCut = 0xFFFFFFFF;
}

uMotionCamera::~uMotionCamera() {
    if (mpCameraList == nullptr) {
        return;
    }
    mpCameraList->release();
    mpCameraList = nullptr;
}

__attribute__((weak)) void uMotionCamera::move() {
    DDON_STUB("uMotionCamera::move")
    /* stub */
}

__attribute__((weak)) void uMotionCamera::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uMotionCamera::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uMotionCamera::setCameraList(rCameraList* pcam) {
    DDON_STUB("uMotionCamera::setCameraList")
    /* stub */
}

static auto ddon_emit_0x01b63880 __attribute__((used)) = &uMotionCamera::getCameraList;

__attribute__((weak)) MtMatrix uMotionCamera::getViewMat() {
    DDON_STUB("uMotionCamera::getViewMat")
    __builtin_unreachable();
}

__attribute__((weak)) MtMatrix uMotionCamera::getProjMat() {
    DDON_STUB("uMotionCamera::getProjMat")
    __builtin_unreachable();
}

MtUI* uMotionCamera::createUI(MtProperty& prop) {
    return this->uCamera::createUI(prop);
}

void uMotionCamera::createProperty(MtPropertyList& s) {
    this->uCamera::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFovType", &mFovType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpParent", reinterpret_cast<MtObject* *>(&mpParent), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParentNo", &mParentNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetPos", &mOffsetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTrackPos", &mTrackPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTrackTarget", &mTrackTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTrackLink", &mTrackLink, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mZoom", &mZoom, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRoll", &mRoll, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCameraList", "resource", reinterpret_cast<MT_MFUNC>(&::uMotionCamera::getCameraList), reinterpret_cast<MT_MFUNC>(&::uMotionCamera::setCameraList), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mCut", &mCut, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrame", &mFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpeed", &mSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRepeat", &mRepeat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCutRepeat", &mCutRepeat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShowPath", &mShowPath, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShowLineOfSight", &mShowLineOfSight, 0u, 0u);
}

__attribute__((weak)) f32 uMotionCamera::getFrameMax() {
    DDON_STUB("uMotionCamera::getFrameMax")
    return {};
}

inline uMotionCamera::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uMotionCamera::MyDTI uMotionCamera::DTI("uMotionCamera", &::uCamera::DTI, 416ul, 0u, 0u);

MtObject* uMotionCamera::MyDTI::newInstance() const {
    return new (16u) uMotionCamera;
}

