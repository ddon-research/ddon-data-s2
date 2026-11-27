// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCamInterporate.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOMath.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCamInterAll::getDTI() const {
    return cCamInterAll::DTI;
}

void cCamInterAll::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsEnd", &mIsEnd, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInterFrameNow", &mInterFrameNow, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInterFrame", &mInterFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInterC", static_cast<MtObject*>(&mInterC), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInterT", static_cast<MtObject*>(&mInterT), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInterU", static_cast<MtObject*>(&mInterU), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInterF", &mInterF, 0u, 0u);
}

void cCamInterAll::initializeAll(const MtVector3& eye, const MtVector3& look, const MtVector3& up, f32 fov, f32 frame, f32 startSpring) {
    if (0.0f >= frame) {
    } else {
        mInterC.mNow.x = eye.x;
        mInterC.mNow.y = eye.y;
        mInterC.mNow.z = eye.z;
        mInterC.mNow.pad_ = 0.0f;
        mInterC.mVelocity.x = MtVector3::Zero.x;
        mInterC.mVelocity.y = MtVector3::Zero.y;
        mInterC.mVelocity.z = MtVector3::Zero.z;
        mInterC.mVelocity.pad_ = 0.0f;
        mInterC.mSpring = startSpring;
        mInterT.mNow.x = look.x;
        mInterT.mNow.y = look.y;
        mInterT.mNow.z = look.z;
        mInterT.mNow.pad_ = 0.0f;
        mInterT.mVelocity.x = MtVector3::Zero.x;
        mInterT.mVelocity.y = MtVector3::Zero.y;
        mInterT.mVelocity.z = MtVector3::Zero.z;
        mInterT.mVelocity.pad_ = 0.0f;
        mInterT.mSpring = mInterC.mSpring;
        mInterU.mNow.x = up.x;
        mInterU.mNow.y = up.y;
        mInterU.mNow.z = up.z;
        mInterU.mNow.pad_ = 0.0f;
        mInterU.mVelocity.x = MtVector3::Zero.x;
        mInterU.mVelocity.y = MtVector3::Zero.y;
        mInterU.mVelocity.z = MtVector3::Zero.z;
        mInterU.mVelocity.pad_ = 0.0f;
        mInterU.mSpring = mInterT.mSpring;
        mInterF.mNow = fov;
        mInterF.mVelocity = 0.0f;
        mInterF.mSpring = mInterU.mSpring;
        mInterFrameNow = 0.0f;
        mInterFrame = frame;
        mIsEnd = false;
        mInitC.x = eye.x;
        mInitC.y = eye.y;
        mInitC.z = eye.z;
        mInitC.pad_ = 0.0f;
        mInitT.x = look.x;
        mInitT.y = look.y;
        mInitT.z = look.z;
        mInitT.pad_ = 0.0f;
        mInitU.x = up.x;
        mInitU.y = up.y;
        mInitU.z = up.z;
        mInitU.pad_ = 0.0f;
        mInitF = mInterF.mNow;
    }
}

__attribute__((weak)) bool cCamInterAll::interporateAllXR(const MtVector3& eye, const MtVector3& look, const MtVector3& lookCenter, const MtVector3& up, f32 fov, f32 time) {
    DDON_STUB("cCamInterAll::interporateAllXR")
    return {};
}

__attribute__((weak)) bool cCamInterAll::interporateAllXX(const MtVector3& eye, const MtVector3& look, const MtVector3& up, f32 fov, f32 time) {
    DDON_STUB("cCamInterAll::interporateAllXX")
    return {};
}

inline cCamInterAll::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamInterAll::MyDTI cCamInterAll::DTI("cCamInterAll", &::MtObject::DTI, 320ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamInterAll::MyDTI::newInstance() const {
    DDON_STUB("cCamInterAll::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamInterporateAng::getDTI() const {
    return cCamInterporateAng::DTI;
}

f32 cCamInterporateAng::calcDisplace(const f32& now, const f32& end) {
    return nDDOMath::getRadianDifference(now, end);
}

f32 cCamInterporateAng::calcAccel(const f32& displace, const f32& velocity) {
    const f32 t0 = velocity;
    f32 t1 = mDamping;
    f32 t2 = nDDOMath::clampRadian(-((displace) * mSpring));
    f32 f2 = nDDOMath::clampRadian(t0 * t1);
    return nDDOMath::getRadianDifference(t2, f2);
}

void cCamInterporateAng::updateVelocity(const f32& accel) {
    const f32 t0 = accel;
    float t1 = mVelocity;
    mVelocity = t0 + t1;
    mVelocity = nDDOMath::clampRadian(t0 + t1);
}

void cCamInterporateAng::updatePosition(const f32& velocity) {
    float t0 = mNow;
    mNow = mVelocity + t0;
    mNow = nDDOMath::clampRadian(mVelocity + t0);
}

__attribute__((weak)) MtObject* cCamInterporateAng::MyDTI::newInstance() const {
    DDON_STUB("cCamInterporateAng::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamInterporateAng3Time::getDTI() const {
    return cCamInterporateAng3Time::DTI;
}

MtVector3 cCamInterporateAng3Time::calcDisplace(const MtVector3& now, const MtVector3& end) {
    MtVector3 result;
    result.pad_ = 0.0f;
    result.x = nDDOMath::getRadianDifference(now.x, end.x);
    result.y = nDDOMath::getRadianDifference(now.y, end.y);
    result.z = nDDOMath::getRadianDifference(now.z, end.z);
    return result;
}

__attribute__((weak)) MtVector3 cCamInterporateAng3Time::calcAccel(const MtVector3& displace, const MtVector3& velocity) {
    DDON_STUB("cCamInterporateAng3Time::calcAccel")
    __builtin_unreachable();
}

void cCamInterporateAng3Time::updateVelocity(const MtVector3& accel) {
    const f32 t0 = accel.x;
    f32 t1 = mVelocity.x;
    mVelocity.x = t0 + t1;
    mVelocity.y = accel.y + mVelocity.y;
    mVelocity.z = accel.z + mVelocity.z;
    mVelocity.x = nDDOMath::clampRadian(t0 + t1);
    mVelocity.y = nDDOMath::clampRadian(mVelocity.y);
    mVelocity.z = nDDOMath::clampRadian(mVelocity.z);
}

void cCamInterporateAng3Time::updatePosition(const MtVector3& velocity) {
    f32 t0 = mNow.x;
    mNow.x = mVelocity.x + t0;
    mNow.y = mVelocity.y + mNow.y;
    mNow.z = mVelocity.z + mNow.z;
    mNow.x = nDDOMath::clampRadian(mVelocity.x + t0);
    mNow.y = nDDOMath::clampRadian(mNow.y);
    mNow.z = nDDOMath::clampRadian(mNow.z);
}

__attribute__((weak)) MtObject* cCamInterporateAng3Time::MyDTI::newInstance() const {
    DDON_STUB("cCamInterporateAng3Time::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamInterporateRange::getDTI() const {
    return cCamInterporateRange::DTI;
}

__attribute__((weak)) void cCamInterporateRange::operator delete(void* p_addr) {
    cCamInterporateRange::getAllocator()->memFree(p_addr);
}

__attribute__((weak)) const MtVector3& cCamInterporateRange::interporateTransform(const MtVector3& targetPos, const MtMatrix& m, const MtVector3& vec, f32 rate) {
    DDON_STUB("cCamInterporateRange::interporateTransform")
    __builtin_unreachable();
}

MtObject* cCamInterporateRange::MyDTI::newInstance() const {
    return new (16u) cCamInterporateRange;
}

const MtDTI& cCamInterporateRangeAng::getDTI() const {
    return cCamInterporateRangeAng::DTI;
}

__attribute__((weak)) void cCamInterporateRangeAng::operator delete(void* p_addr) {
    cCamInterporateRangeAng::getAllocator()->memFree(p_addr);
}

__attribute__((weak)) f32 cCamInterporateRangeAng::interporateRangeAng(f32 targetPos, f32 radius, f32 rate) {
    DDON_STUB("cCamInterporateRangeAng::interporateRangeAng")
    return {};
}

inline cCamInterporateRangeAng::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamInterporateRangeAng::MyDTI cCamInterporateRangeAng::DTI("cCamInterporateRangeAng", &::cCamInterporateAng::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamInterporateRangeAng::MyDTI::newInstance() const {
    DDON_STUB("cCamInterporateRangeAng::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamInterporateRangeF32::getDTI() const {
    return cCamInterporateRangeF32::DTI;
}

__attribute__((weak)) MtObject* cCamInterporateRangeF32::MyDTI::newInstance() const {
    DDON_STUB("cCamInterporateRangeF32::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamInterporateVec3::getDTI() const {
    return cCamInterporateVec3::DTI;
}

__attribute__((weak)) void cCamInterporateVec3::operator delete(void* p_addr) {
    cCamInterporateVec3::getAllocator()->memFree(p_addr);
}

__attribute__((weak)) const MtVector3& cCamInterporateVec3::interporateRot(const MtVector3& targetPos, const MtVector3& center, f32 rate) {
    DDON_STUB("cCamInterporateVec3::interporateRot")
    __builtin_unreachable();
}

MtObject* cCamInterporateVec3::MyDTI::newInstance() const {
    return new (16u) cCamInterporateVec3;
}

template const MtDTI& cCamInterporateTime<MtVector3>::getDTI() const;

