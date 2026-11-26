// Reconstructed from the game's DWARF debug information.
#include <new>
#include <math.h>
#include "uCameraBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/uCamera.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCameraInfo::getDTI() const {
    return cCameraInfo::DTI;
}

inline void* cCameraInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cCameraInfo::DTI)->memAlloc(sz, align, cCameraInfo::DTI.getID());
}

inline void cCameraInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCameraInfo::DTI)->memFree(p_addr);
}

inline cCameraInfo::cCameraInfo() {
    mCameraPos.x = MtVector3::Zero.x;
    mCameraPos.y = MtVector3::Zero.y;
    mCameraPos.z = MtVector3::Zero.z;
    mCameraPos.pad_ = 0.0f;
    mTargetPos.x = MtVector3::Zero.x;
    mTargetPos.y = MtVector3::Zero.y;
    mTargetPos.z = MtVector3::Zero.z;
    mTargetPos.pad_ = 0.0f;
    mRoll = 0.0f;
    mFov = 0.0f;
}

__attribute__((weak)) void cCameraInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCameraPos", &mCameraPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos", &mTargetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRoll", &mRoll, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFov", &mFov, 0u, 0u);
}

inline cCameraInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCameraInfo::MyDTI cCameraInfo::DTI("cCameraInfo", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cCameraInfo::MyDTI::newInstance() const {
    return new (16u) cCameraInfo;
}

const MtDTI& cCameraQuake::getDTI() const {
    return cCameraQuake::DTI;
}

inline void cCameraQuake::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCameraQuake::DTI)->memFree(p_addr);
}

void cCameraQuake::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mState", reinterpret_cast<s32*>(&mTask[0].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mNo", &mTask[0].mNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mTime", &mTask[0].mTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mHeadTime", &mTask[0].mHeadTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mMainTime", &mTask[0].mMainTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mTailTime", &mTask[0].mTailTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mMagnitude", &mTask[0].mMagnitude, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mPos", &mTask[0].mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mRadius", &mTask[0].mRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mSpread", &mTask[0].mSpread, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mDamping", &mTask[0].mDamping, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mPeriod", &mTask[0].mPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mCamera1QuakeTime", &mTask[0].mCamera1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mTarget1QuakeTime", &mTask[0].mTarget1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mRoll1QuakeTime", &mTask[0].mRoll1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mRndDrop", &mTask[0].mRndDrop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mHeadCurve", reinterpret_cast<s32*>(&mTask[0].mHeadCurve), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mTailCurve", reinterpret_cast<s32*>(&mTask[0].mTailCurve), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mRoll", &mTask[0].mRoll, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mBalance", &mTask[0].mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[0].mbAsync", &mTask[0].mbAsync, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mState", reinterpret_cast<s32*>(&mTask[1].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mNo", &mTask[1].mNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mTime", &mTask[1].mTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mHeadTime", &mTask[1].mHeadTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mMainTime", &mTask[1].mMainTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mTailTime", &mTask[1].mTailTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mMagnitude", &mTask[1].mMagnitude, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mPos", &mTask[1].mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mRadius", &mTask[1].mRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mSpread", &mTask[1].mSpread, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mDamping", &mTask[1].mDamping, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mPeriod", &mTask[1].mPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mCamera1QuakeTime", &mTask[1].mCamera1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mTarget1QuakeTime", &mTask[1].mTarget1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mRoll1QuakeTime", &mTask[1].mRoll1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mRndDrop", &mTask[1].mRndDrop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mHeadCurve", reinterpret_cast<s32*>(&mTask[1].mHeadCurve), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mTailCurve", reinterpret_cast<s32*>(&mTask[1].mTailCurve), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mRoll", &mTask[1].mRoll, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mBalance", &mTask[1].mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[1].mbAsync", &mTask[1].mbAsync, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mState", reinterpret_cast<s32*>(&mTask[2].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mNo", &mTask[2].mNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mTime", &mTask[2].mTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mHeadTime", &mTask[2].mHeadTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mMainTime", &mTask[2].mMainTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mTailTime", &mTask[2].mTailTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mMagnitude", &mTask[2].mMagnitude, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mPos", &mTask[2].mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mRadius", &mTask[2].mRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mSpread", &mTask[2].mSpread, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mDamping", &mTask[2].mDamping, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mPeriod", &mTask[2].mPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mCamera1QuakeTime", &mTask[2].mCamera1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mTarget1QuakeTime", &mTask[2].mTarget1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mRoll1QuakeTime", &mTask[2].mRoll1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mRndDrop", &mTask[2].mRndDrop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mHeadCurve", reinterpret_cast<s32*>(&mTask[2].mHeadCurve), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mTailCurve", reinterpret_cast<s32*>(&mTask[2].mTailCurve), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mRoll", &mTask[2].mRoll, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mBalance", &mTask[2].mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[2].mbAsync", &mTask[2].mbAsync, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[3].mState", reinterpret_cast<s32*>(&mTask[3].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[4].mState", reinterpret_cast<s32*>(&mTask[4].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[5].mState", reinterpret_cast<s32*>(&mTask[5].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[6].mState", reinterpret_cast<s32*>(&mTask[6].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[7].mState", reinterpret_cast<s32*>(&mTask[7].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[8].mState", reinterpret_cast<s32*>(&mTask[8].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTask[9].mState", reinterpret_cast<s32*>(&mTask[9].mState), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMagnitude", &mMagnitude, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRollMag", &mRollMag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBalance", &mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mbAsync", &mbAsync, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamera1QuakeTime", &mCamera1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTarget1QuakeTime", &mTarget1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRoll1QuakeTime", &mRoll1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraTimer", &mCameraTimer[0], 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetTimer", &mTargetTimer[0], 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mRollTimer", &mRollTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraAmp", &mCameraAmp[0], 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetAmp", &mTargetAmp[0], 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mRollAmp", &mRollAmp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraCycle", &mCameraCycle[0], 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetCycle", &mTargetCycle[0], 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mRollCycle", &mRollCycle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mbCameraInit", &mbCameraInit[0], 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mbTargetInit", &mbTargetInit[0], 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mbRollInit", &mbRollInit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRndDrop", &mRndDrop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mbQuakeActive", &mbQuakeActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mbSleep", &mbSleep, 0u, 0u);
}

MtUI* cCameraQuake::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cCameraQuake::init() {
    DDON_STUB("cCameraQuake::init")
    /* stub */
}

void cCameraQuake::update(const f32 deltaTime, const f32 deltaSec) {
    scheduler(deltaSec);
    execute(deltaSec);
}

__attribute__((weak)) void cCameraQuake::set(uintptr taskNo, f32 headTime, f32 mainTime, f32 tailTime, const MtVector3& magnitude, const MtVector3& pos, f32 radius, f32 spread, f32 damping, f32 period, f32 cam1QuakeTime, f32 tar1QuakeTime, f32 roll1QuakeTime, f32 randDrop, cCameraQuake::EASE_TYPE headCurve, cCameraQuake::EASE_TYPE tailCurve, f32 roll, f32 balance, bool bAsync) {
    DDON_STUB("cCameraQuake::set")
    /* stub */
}

__attribute__((weak)) void cCameraQuake::del(uintptr taskNo, bool foceDel) {
    DDON_STUB("cCameraQuake::del")
    /* stub */
}

__attribute__((weak)) void cCameraQuake::scheduler(f32 deltaSec) {
    DDON_STUB("cCameraQuake::scheduler")
    /* stub */
}

__attribute__((weak)) void cCameraQuake::execute(f32 deltaSec) {
    DDON_STUB("cCameraQuake::execute")
    /* stub */
}

inline cCameraQuake::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCameraQuake::MyDTI cCameraQuake::DTI("cCameraQuake", &::MtObject::DTI, 2352ul, 0u, 0u);

__attribute__((weak)) MtObject* cCameraQuake::MyDTI::newInstance() const {
    DDON_STUB("cCameraQuake::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCameraSeqInfo::getDTI() const {
    return cCameraSeqInfo::DTI;
}

inline MtAllocator* cCameraSeqInfo::getAllocator() {
    return MtMemoryAllocator::getAllocator(cCameraSeqInfo::DTI);
}

void* cCameraSeqInfo::operator new(size_t sz, u32 align) {
    return cCameraSeqInfo::getAllocator()->memAlloc(sz, align, cCameraSeqInfo::DTI.getID());
}

inline void cCameraSeqInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCameraSeqInfo::DTI)->memFree(p_addr);
}

cCameraSeqInfo::cCameraSeqInfo() {
    mTime = 0.0f;
    mType = static_cast<CAMSEQ_TYPE>(0);
    mRate = 100;
    mQuake = -1;
    mNearBlurLimit = -1.0f;
    mFarBlurLimit = -1.0f;
    mNear = -1.0f;
    mFar = -1.0f;
    mFocal = -1.0f;
    mMotionBlur = false;
    mInvalidAdjust = false;
    mInvAdjCam = false;
    mInvAdjTar = false;
}

__attribute__((weak)) void cCameraSeqInfo::createProperty(MtPropertyList& s) {
    this->cCameraInfo::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mTime", &mTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mType", reinterpret_cast<s32*>(&mType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRate", &mRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuake", &mQuake, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNearBlurLimit", &mNearBlurLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFarBlurLimit", &mFarBlurLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNear", &mNear, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFar", &mFar, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFocal", &mFocal, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMotionBlur", &mMotionBlur, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInvalidAdjust", &mInvalidAdjust, 0u, 0u);
}

MtUI* cCameraSeqInfo::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

cCameraSeqInfo& cCameraSeqInfo::operator=(const cCameraSeqInfo& info) {
    mCameraPos = info.mCameraPos;
    mTargetPos = info.mTargetPos;
    mRoll = info.mRoll;
    mFov = info.mFov;
    mTime = info.mTime;
    mType = info.mType;
    mRate = info.mRate;
    mQuake = info.mQuake;
    mNearBlurLimit = info.mNearBlurLimit;
    mFarBlurLimit = info.mFarBlurLimit;
    mNear = info.mNear;
    mFar = info.mFar;
    mFocal = info.mFocal;
    mMotionBlur = info.mMotionBlur;
    mInvalidAdjust = info.mInvalidAdjust;
    mInvAdjCam = info.mInvAdjCam;
    mInvAdjTar = info.mInvAdjTar;
    return *this;
}

inline cCameraSeqInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCameraSeqInfo::MyDTI cCameraSeqInfo::DTI("cCameraSeqInfo", &::cCameraInfo::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cCameraSeqInfo::MyDTI::newInstance() const {
    return new (16u) cCameraSeqInfo;
}

const MtDTI& cCameraSeqInfo2::getDTI() const {
    return cCameraSeqInfo2::DTI;
}

inline MtAllocator* cCameraSeqInfo2::getAllocator() {
    return MtMemoryAllocator::getAllocator(cCameraSeqInfo2::DTI);
}

void* cCameraSeqInfo2::operator new(size_t sz, u32 align) {
    return cCameraSeqInfo2::getAllocator()->memAlloc(sz, align, cCameraSeqInfo2::DTI.getID());
}

inline void cCameraSeqInfo2::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCameraSeqInfo2::DTI)->memFree(p_addr);
}

cCameraSeqInfo2::cCameraSeqInfo2() {
}

void cCameraSeqInfo2::createProperty(MtPropertyList& s) {
    this->cCameraSeqInfo::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mInvAdjCam", &mInvAdjCam, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInvAdjTar", &mInvAdjTar, 0u, 0u);
}

MtUI* cCameraSeqInfo2::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cCameraSeqInfo2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCameraSeqInfo2::MyDTI cCameraSeqInfo2::DTI("cCameraSeqInfo2", &::cCameraSeqInfo::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cCameraSeqInfo2::MyDTI::newInstance() const {
    return new (16u) cCameraSeqInfo2;
}

const MtDTI& uCameraBase::getDTI() const {
    return uCameraBase::DTI;
}

inline void uCameraBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uCameraBase::DTI)->memFree(p_addr);
}

uCameraBase::uCameraBase() {
    DDON_STUB("uCameraBase::uCameraBase")
    /* stub */
}

uCameraBase::~uCameraBase() {
}

void uCameraBase::createProperty(MtPropertyList& s) {
    this->uCamera::createProperty(s);
}

MtUI* uCameraBase::createUI(MtProperty& prop) {
    return this->uCamera::createUI(prop);
}

MtMatrix uCameraBase::getViewMat() {
    MtMatrix vm;
    vm.setLookAtRH(mCameraPos, mTargetPos, mCameraUp);
    return vm;
}

MtMatrix uCameraBase::getProjMat() {
    MtMatrix pj;
    pj.setPerspectiveFovRH(mNearPlane, mFarPlane, mFov * 0.017453294f, mAspect);
    if (mFovType != FOV_V) {
        f32 t0 = mAspect;
        pj.m[0].x = pj.m[0].x / (1.0f / t0);
        pj.m[1].y = t0 * pj.m[1].y;
        return pj;
    } else {
        return pj;
    }
}

__attribute__((weak)) void uCameraBase::draw(cDraw* pdraw) {
}

void uCameraBase::init() {
    mbInitial = true;
}

void uCameraBase::update(const f32 deltaTime, const f32 deltaSec) {
    calcFrustum(false);
}

f32 uCameraBase::getDeltaTime() {
    return sMain::getInstance()->mDeltaTime;
}

f32 uCameraBase::getDeltaSec() {
    return sMain::getInstance()->mDeltaTime / sMain::getInstance()->mFps;
}

__attribute__((weak)) void uCameraBase::calcAngle(f32& outX, f32& outY, const MtVector3& pos1, const MtVector3& pos2) {
    DDON_STUB("uCameraBase::calcAngle")
    /* stub */
}

__attribute__((weak)) void uCameraBase::calcAngle(f32& outX, f32& outY, const MtVector3& vec) {
    DDON_STUB("uCameraBase::calcAngle")
    /* stub */
}

__attribute__((weak)) f32 uCameraBase::calcAngleX(const MtVector3& vec) {
    DDON_STUB("uCameraBase::calcAngleX")
    return {};
}

f32 uCameraBase::calcAngleY(const MtVector3& vec) {
    return nDDOMath::clampRadian(atan2f(vec.x, vec.z));
}

__attribute__((weak)) void uCameraBase::calcFrustum(bool bDisp) {
    DDON_STUB("uCameraBase::calcFrustum")
    /* stub */
}

__attribute__((weak)) bool uCameraBase::calcCameraUp(const MtVector3& cameraPos, const MtVector3& targetPos, const f32 roll, MtVector3& cameraUp) {
    DDON_STUB("uCameraBase::calcCameraUp")
    return {};
}

inline uCameraBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCameraBase::MyDTI uCameraBase::DTI("uCameraBase", &::uCamera::DTI, 2704ul, 0u, 0u);

__attribute__((weak)) MtObject* uCameraBase::MyDTI::newInstance() const {
    DDON_STUB("uCameraBase::MyDTI::newInstance")
    return nullptr;
}

