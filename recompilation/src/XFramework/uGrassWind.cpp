// Reconstructed from the game's DWARF debug information.
#include <new>
#include <math.h>
#include <ymath.h>
#include "uGrassWind.h"
#include "../MT/MtDTI.h"
#include "../MT/MtLogisticMap.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtRandom.h"
#include "cResource.h"
#include "cUnit.h"
#include "rGrassWind.h"
#include "sMain.h"
#include "sScene.h"
#include "uGrassEffect.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uGrassWind::usage() {
}

const MtDTI& uGrassWind::getDTI() const {
    return uGrassWind::DTI;
}

uGrassWind::uGrassWind(f32 Amplification, f32 Frequency, f32 Phase, u32 Priority) : uGrassEffect(Priority) {
    mAmplification = Amplification;
    mFrequency = Frequency;
    mPhase = Phase;
    mElapsedPhase = 0.0f;
    mWindGroup = 1;
    mpResource = nullptr;
    mSpeed = 1.0f;
    (sScene::mpInstance)->sScene::attach(static_cast<cUnit*>(this));
    mType = 0;
}

uGrassWind::~uGrassWind() {
    (sScene::mpInstance)->sScene::detach(static_cast<cUnit*>(this));
    if (mpResource == nullptr) {
        return;
    }
    mpResource->release();
    mpResource = nullptr;
}

__attribute__((weak)) void uGrassWind::createProperty(MtPropertyList& s) {
    this->uGrassEffect::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mAmplification", &mAmplification, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrequency", &mFrequency, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPhase", &mPhase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mElapsedPhase", &mElapsedPhase, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindGroup", &mWindGroup, 2048u, 0u);
}

MtUI* uGrassWind::createUI(MtProperty& prop) {
    return this->uGrassEffect::createUI(prop);
}

__attribute__((weak)) MtVector4 uGrassWind::getInfo() {
    DDON_STUB("uGrassWind::getInfo")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector4 uGrassWind::getInfo2() {
    DDON_STUB("uGrassWind::getInfo2")
    __builtin_unreachable();
}

MtVector3 uGrassWind::getDirection(const MtVector3& pos) {
    return MtVector3::Zero;
}

__attribute__((weak)) MtVector4 uGrassWind::getAngle(const MtVector3& pos, const f32& phase) {
    DDON_STUB("uGrassWind::getAngle")
    __builtin_unreachable();
}

MtVector3 uGrassWind::getForce(const MtVector3& pos) {
    return MtVector3::Zero;
}

sScene::Node* uGrassWind::getSceneNode() {
    return nullptr;
}

__attribute__((weak)) void uGrassWind::getDrawUnitState(u32& type, u32& priority) const {
    DDON_STUB("uGrassWind::getDrawUnitState")
    /* stub */
}

inline uGrassWind::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGrassWind::MyDTI uGrassWind::DTI("uGrassWind", &::uGrassEffect::DTI, 3992ul, 0u, 1u);

MtObject* uGrassWind::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGrassWind::cSwingParameters::getDTI() const {
    return uGrassWind::cSwingParameters::DTI;
}

uGrassWind::cSwingParameters::cSwingParameters() {
    DDON_STUB("uGrassWind::cSwingParameters::cSwingParameters")
    /* stub */
}

uGrassWind::cSwingParameters::~cSwingParameters() {
}

void uGrassWind::cSwingParameters::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mUseInterpolateSpeed", &mUseInterpolateSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInterpolateSpeed", &mInterpolateSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseLogistic", &mUseLogistic, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpdateInterval", &mUpdateInterval, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBias", &mBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mModelAmp", &mModelAmp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mModelPhaseCoeff", &mModelPhaseCoeff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBasePhaseSpeed", &mBasePhaseSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNoiseRate", &mNoiseRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPhaseSpeed", &mPhaseSpeed, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCurrentPhaseSpeed", &mCurrentPhaseSpeed, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBasePhaseSpeed2", &mBasePhaseSpeed2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNoiseRate2", &mNoiseRate2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPhaseSpeed2", &mPhaseSpeed2, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCurrentPhaseSpeed2", &mCurrentPhaseSpeed2, 1u, 0u);
}

MtUI* uGrassWind::cSwingParameters::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void uGrassWind::cSwingParameters::update(f32 frequency, f32 phase) {
    DDON_STUB("uGrassWind::cSwingParameters::update")
    /* stub */
}

__attribute__((weak)) MtVector4 uGrassWind::cSwingParameters::getRotationAngle(const MtVector3& pos, const f32 user_phase) {
    DDON_STUB("uGrassWind::cSwingParameters::getRotationAngle")
    __builtin_unreachable();
}

__attribute__((weak)) void uGrassWind::cSwingParameters::updateSpeed() {
    DDON_STUB("uGrassWind::cSwingParameters::updateSpeed")
    /* stub */
}

inline uGrassWind::cSwingParameters::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGrassWind::cSwingParameters::MyDTI uGrassWind::cSwingParameters::DTI("uGrassWind::cSwingParameters", &::MtObject::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* uGrassWind::cSwingParameters::MyDTI::newInstance() const {
    DDON_STUB("uGrassWind::cSwingParameters::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGrassWindDirection::getDTI() const {
    return uGrassWindDirection::DTI;
}

uGrassWindDirection::~uGrassWindDirection() {
    DDON_STUB("uGrassWindDirection::~uGrassWindDirection")
    /* stub */
}

void uGrassWindDirection::createProperty(MtPropertyList& s) {
    this->uGrassWind::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mDirection", &mDirection, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParam", static_cast<MtObject*>(&mParam), 0u, 0u);
}

MtUI* uGrassWindDirection::createUI(MtProperty& prop) {
    return this->uGrassEffect::createUI(prop);
}

void uGrassWindDirection::move() {
    mParam.uGrassWind::cSwingParameters::update(mFrequency, mPhase);
    mElapsedPhase = fmodf(mElapsedPhase + (mParam.mCurrentPhaseSpeed * ((mPhase * mDeltaTime) / (sMain::mpInstance)->mFps)), 6.2831855f);
    play();
}

void uGrassWindDirection::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mElapsedPhase = fmodf(mElapsedPhase - (mFrequency * (((mDirection.x * offset.x) + (mDirection.y * offset.y)) + (mDirection.z * offset.z))), 6.2831855f);
}

void uGrassWindDirection::getAABB(MtAABB& aabb) {
    aabb.maxpos.z = 0.0f;
    aabb.maxpos.pad_ = 0.0f;
    aabb.maxpos.x = 0.0f;
    aabb.maxpos.y = 0.0f;
    aabb.minpos.z = 0.0f;
    aabb.minpos.pad_ = 0.0f;
    aabb.minpos.x = 0.0f;
    aabb.minpos.y = 0.0f;
    aabb.minpos.x = -10000.0f;
    aabb.minpos.y = -10000.0f;
    aabb.minpos.z = -10000.0f;
    aabb.maxpos.x = 10000.0f;
    aabb.maxpos.y = 10000.0f;
    aabb.maxpos.z = 10000.0f;
}

MtVector4 uGrassWindDirection::getInfo() {
    MtVector4 result;
    result.x = mDirection.x;
    result.y = mDirection.y;
    result.z = mDirection.z;
    result.w = 0.0f;
    return result;
}

MtVector3 uGrassWindDirection::getDirection(const MtVector3& pos) {
    MtVector3 result;
    result.x = mDirection.x;
    result.y = mDirection.y;
    result.z = mDirection.z;
    result.pad_ = 0.0f;
    return result;
}

MtVector4 uGrassWindDirection::getAngle(const MtVector3& pos, const f32& phase) {
    return mParam.uGrassWind::cSwingParameters::getRotationAngle(pos, phase);
}

MtVector3 uGrassWindDirection::getForce(const MtVector3& pos) {
    MtVector3 result;
    float t0 = _FSin(mElapsedPhase + (mFrequency * (((mDirection.x * pos.x) + (mDirection.y * pos.y)) + (mDirection.z * pos.z))), 0u, 0);
    f32 t1 = mAmplification;
    f32 t2 = mDirection.y;
    f32 t3 = mDirection.z;
    result.x = mDirection.x * (t1 * (1.0f + t0));
    result.y = t2 * (t1 * (1.0f + t0));
    result.z = t3 * (t1 * (1.0f + t0));
    result.pad_ = 0.0f;
    return result;
}

__attribute__((weak)) void uGrassWindDirection::getDrawUnitState(u32& type, u32& priority) const {
    DDON_STUB("uGrassWindDirection::getDrawUnitState")
    /* stub */
}

inline uGrassWindDirection::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGrassWindDirection::MyDTI uGrassWindDirection::DTI("uGrassWindDirection", &::uGrassWind::DTI, 4176ul, 0u, 0u);

__attribute__((weak)) MtObject* uGrassWindDirection::MyDTI::newInstance() const {
    DDON_STUB("uGrassWindDirection::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGrassWindPoint::getDTI() const {
    return uGrassWindPoint::DTI;
}

uGrassWindPoint::~uGrassWindPoint() {
    DDON_STUB("uGrassWindPoint::~uGrassWindPoint")
    /* stub */
}

void uGrassWindPoint::createProperty(MtPropertyList& s) {
    this->uGrassWind::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPoint", &mPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttenuation", &mAttenuation, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpParent", reinterpret_cast<MtObject* *>(&mpParent), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParentNo", &mParentNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParam", static_cast<MtObject*>(&mParam), 0u, 0u);
}

MtUI* uGrassWindPoint::createUI(MtProperty& prop) {
    return this->uGrassEffect::createUI(prop);
}

void uGrassWindPoint::move() {
    mParam.uGrassWind::cSwingParameters::update(mFrequency, mPhase);
    mElapsedPhase = fmodf(mElapsedPhase + (mParam.mCurrentPhaseSpeed * ((mPhase * mDeltaTime) / (sMain::mpInstance)->mFps)), 6.2831855f);
    play();
}

__attribute__((weak)) void uGrassWindPoint::moveAfter() {
    DDON_STUB("uGrassWindPoint::moveAfter")
    /* stub */
}

void uGrassWindPoint::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    if (mpParent != nullptr) {
        return;
    }
    mPoint.x = offset.x + mPoint.x;
    mPoint.y = offset.y + mPoint.y;
    mPoint.z = offset.z + mPoint.z;
}

__attribute__((weak)) bool uGrassWindPoint::getBoundary(MtSphere* sphere) {
    DDON_STUB("uGrassWindPoint::getBoundary")
    return {};
}

void uGrassWindPoint::getAABB(MtAABB& aabb) {
    aabb.minpos.x = mAABB.minpos.x;
    aabb.minpos.y = mAABB.minpos.y;
    aabb.minpos.z = mAABB.minpos.z;
    aabb.minpos.pad_ = 0.0f;
    aabb.maxpos.x = mAABB.maxpos.x;
    aabb.maxpos.y = mAABB.maxpos.y;
    aabb.maxpos.z = mAABB.maxpos.z;
    aabb.maxpos.pad_ = 0.0f;
}

MtVector4 uGrassWindPoint::getInfo() {
    MtVector4 result;
    f32 t0 = mAttenuation;
    result.x = mWorldPos.x;
    result.y = mWorldPos.y;
    result.z = mWorldPos.z;
    result.w = t0;
    return result;
}

__attribute__((weak)) MtVector3 uGrassWindPoint::getDirection(const MtVector3& pos) {
    DDON_STUB("uGrassWindPoint::getDirection")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector4 uGrassWindPoint::getAngle(const MtVector3& pos, const f32& phase) {
    DDON_STUB("uGrassWindPoint::getAngle")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 uGrassWindPoint::getForce(const MtVector3& pos) {
    DDON_STUB("uGrassWindPoint::getForce")
    __builtin_unreachable();
}

sScene::Node* uGrassWindPoint::getSceneNode() {
    return &mNode;
}

inline uGrassWindPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGrassWindPoint::MyDTI uGrassWindPoint::DTI("uGrassWindPoint", &::uGrassWind::DTI, 4288ul, 0u, 0u);

__attribute__((weak)) MtObject* uGrassWindPoint::MyDTI::newInstance() const {
    DDON_STUB("uGrassWindPoint::MyDTI::newInstance")
    return nullptr;
}

