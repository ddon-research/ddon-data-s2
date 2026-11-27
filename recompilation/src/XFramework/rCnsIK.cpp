// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCnsIK.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "cResource.h"
#include "rConstraint.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rCnsIK::usage() {
}

const MtDTI& rCnsIK::getDTI() const {
    return rCnsIK::DTI;
}

rCnsIK::rCnsIK() {
    setAttribute(16u);
    mUseScale = true;
    mDir = 4;
    mUp = 2;
    mFitDir = 1;
    mFitUp = 2;
    mEffectorLimitEnable = false;
    mEffPitchMin = -90.0f;
    mEffPitchMax = 90.0f;
    mEffRotMin = -180.0f;
    mEffRotMax = 180.0f;
    mEffDistMin = 0.0f;
    mEffDistMax = 100.0f;
    mJointLimitEnable = false;
    mCollisionEnable = false;
    mHeelOffset = 10.0f;
    mHeelHeight = 0.0f;
    mFit = true;
    mGroundDistAdapt = false;
    mCheckGroundLengthUpper = 100.0f;
    mCheckGroundLengthLower = 30.0f;
    mGroundLevel = -100000000.0f;
    mEffLimitMode = 0;
    mJointLimitMode = 0;
    mCollisionMode = 0;
    mEffectorBehavior = 0;
    mMotionFitDist = 100.0f;
    mMotionFitDisable = false;
    mJointNum = 3;
    mLimitCoord = 0;
    mLimitCoordOffset = MtVector3::Zero;
    mEffectorTargetModel = false;
    mEffectorTargetJointNo = 0;
    mEffectorTargetModelEnable = false;
    mUpVectorTargetModel = false;
    mUpVectorTargetJointNo = 0;
    mUpVectorTargetModelEnable = false;
    mEffectorControl = 0;
    mOffsetMat = MtMatrix::Identity;
    mTransScale = MtFloat3::Zero;
    mCenterRefJntNo = -1;
    mCenterPosOffset = MtFloat3::Zero;
}

__attribute__((noinline)) rCnsIK::~rCnsIK() {
}

MT_CTSTR rCnsIK::getExt() const {
    return "ik";
}

MtUI* rCnsIK::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

void rCnsIK::createProperty(MtPropertyList& s) {
    this->rConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mUseScale", &mUseScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNum", &mJointNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJoint", static_cast<MtObject*>(&mJoint[0]), 32u, 16u);
    s << MtProperty(static_cast<MtObject*>(this), "mDir", &mDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUp", &mUp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFitDir", &mFitDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFitUp", &mFitUp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorLimitEnable", &mEffectorLimitEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffPitchMin", &mEffPitchMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffPitchMax", &mEffPitchMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffRotMin", &mEffRotMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffRotMax", &mEffRotMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffDistMin", &mEffDistMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffDistMax", &mEffDistMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointLimitEnable", &mJointLimitEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCollisionEnable", &mCollisionEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeelOffset", &mHeelOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeelHeight", &mHeelHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFit", &mFit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckGroundLengthUpper", &mCheckGroundLengthUpper, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCheckGroundLengthLower", &mCheckGroundLengthLower, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroundLevel", &mGroundLevel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroundDistAdapt", &mGroundDistAdapt, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffLimitMode", &mEffLimitMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointLimitMode", &mJointLimitMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCollisionMode", &mCollisionMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorBehavior", &mEffectorBehavior, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLimitCoord", &mLimitCoord, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLimitCoordOffset", &mLimitCoordOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorTargetModel", &mEffectorTargetModel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorTargetJointNo", &mEffectorTargetJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorTargetModelEnable", &mEffectorTargetModelEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpVectorTargetModel", &mUpVectorTargetModel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpVectorTargetJointNo", &mUpVectorTargetJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpVectorTargetModelEnable", &mUpVectorTargetModelEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorControl", &mEffectorControl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetMat", &mOffsetMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCenterRefJntNo", &mCenterRefJntNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCenterPosOffset", &mCenterPosOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTransScale", &mTransScale, 0u, 0u);
}

__attribute__((weak)) void rCnsIK::copyUnitProperty(uConstraint* pSrcUnit) {
}

bool rCnsIK::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(4), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rCnsIK::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(4), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rCnsIK::DTI));
}

inline rCnsIK::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCnsIK::MyDTI rCnsIK::DTI("rCnsIK", &::rConstraint::DTI, 896ul, 0u, 0u);

__attribute__((weak)) MtObject* rCnsIK::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(rCnsIK::DTI)->memAlloc(sizeof(rCnsIK), 16u, rCnsIK::DTI.getID())) rCnsIK;
}

const MtDTI& rCnsIK::JointInfo::getDTI() const {
    return rCnsIK::JointInfo::DTI;
}

rCnsIK::JointInfo::~JointInfo() {
}

void rCnsIK::JointInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mJntNo", &mJntNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotMin", &mRotMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotMax", &mRotMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReverse", &mReverse, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffset", &mOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScaleOffset", &mScaleOffset, 0u, 0u);
}

inline rCnsIK::JointInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCnsIK::JointInfo::MyDTI rCnsIK::JointInfo::DTI("rCnsIK::JointInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rCnsIK::JointInfo::MyDTI::newInstance() const {
    return new (16u) rCnsIK::JointInfo;
}

