// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCamera.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cUnit.h"
#include "sCamera.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCamera::getDTI() const {
    return uCamera::DTI;
}

uCamera::uCamera() {
    mCameraPos.x = 0.0f;
    mCameraPos.y = 200.0f;
    mCameraPos.z = -700.0f;
    mCameraPos.pad_ = 0.0f;
    mTargetPos.x = 0.0f;
    mTargetPos.y = 200.0f;
    mTargetPos.z = 0.0f;
    mTargetPos.pad_ = 0.0f;
    mCameraUp.x = 0.0f;
    mCameraUp.y = 1.0f;
    mCameraUp.z = 0.0f;
    mCameraUp.pad_ = 0.0f;
    mFarPlane = 4000000.0f;
    mNearPlane = 16.0f;
    mAspect = 1.0f;
    mFov = 40.0f;
    mWorldCameraPos.x = 0.0f;
    mWorldCameraPos.y = 200.0f;
    mWorldCameraPos.z = -700.0f;
    mWorldCameraPos.pad_ = 0.0f;
    mWorldTargetPos.x = 0.0f;
    mWorldTargetPos.y = 200.0f;
    mWorldTargetPos.z = 0.0f;
    mWorldTargetPos.pad_ = 0.0f;
}

__attribute__((weak)) void uCamera::move() {
}

__attribute__((weak)) void uCamera::moveAfter() {
    DDON_STUB("uCamera::moveAfter")
    /* stub */
}

void uCamera::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mCameraPos.x = offset.x + mCameraPos.x;
    mCameraPos.y = offset.y + mCameraPos.y;
    mCameraPos.z = offset.z + mCameraPos.z;
    mTargetPos.x = offset.x + mTargetPos.x;
    mTargetPos.y = offset.y + mTargetPos.y;
    mTargetPos.z = offset.z + mTargetPos.z;
}

void uCamera::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraPos", &mCameraPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos", &mTargetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraUp", &mCameraUp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNearPlane", &mNearPlane, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFarPlane", &mFarPlane, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFov", &mFov, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAspect", &mAspect, 0u, 0u);
}

MtUI* uCamera::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

__attribute__((weak)) MtVector3 uCamera::getWorldTargetPos() {
    DDON_STUB("uCamera::getWorldTargetPos")
    __builtin_unreachable();
}

inline uCamera::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCamera::MyDTI uCamera::DTI("uCamera", &::cUnit::DTI, 176ul, 0u, 1u);

MtObject* uCamera::MyDTI::newInstance() const {
    return nullptr;
}

