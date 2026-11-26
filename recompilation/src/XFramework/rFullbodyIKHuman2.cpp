// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rFullbodyIKHuman2.h"

#include "uFullbodyIKHuman2.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "cResource.h"
#include "uFullbodyIKHuman2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rFullbodyIKHuman2::usage() {
}

const MtDTI& rFullbodyIKHuman2::getDTI() const {
    return rFullbodyIKHuman2::DTI;
}

inline void rFullbodyIKHuman2::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFullbodyIKHuman2::DTI)->memFree(p_addr);
}

rFullbodyIKHuman2::rFullbodyIKHuman2() {
    setAttribute(18u);
    mPri = 10000;
    mIteration = 30;
    mUpperBodyRotRate = 0.2f;
    mUpperBodyTransRate = 0.1f;
    mUpperBodySyncRate = 0.5f;
    mLowerBodyRotRate = 0.2f;
    mLowerBodyTransRate = 0.1f;
    mLowerBodySyncRate = 0.5f;
    mHeadLookAtRate = 0.8f;
    mUpperBodyLookAtRate = 0.02f;
    mLowerBodyLookAtRate = 0.002f;
    mWaistHeightLimit = 30.0f;
    mRCollarRotBlend = 0.5f;
    mLCollarRotBlend = 0.5f;
    mRCollarUpBlend = 1.0f;
    mRCollarDownBlend = 0.3f;
    mRCollarFrontBlend = 0.5f;
    mRCollarBackBlend = 0.5f;
    mLCollarUpBlend = 1.0f;
    mLCollarDownBlend = 0.3f;
    mLCollarFrontBlend = 0.5f;
    mLCollarBackBlend = 0.5f;
    mSpineUpperRotRate = 0.0f;
    mSpine0RotRate = 4.0f;
    mSpine1RotRate = 3.0f;
    mSpine2RotRate = 2.0f;
    mSpine3RotRate = 1.0f;
    mSpine4RotRate = 0.0f;
    for (s32 i = 0; i < 27; ++i) {
        mJointAssign[i].mFBIKJntNo = uFullbodyIKHuman2::getFBIKJointNoFromIndex(static_cast<uFullbodyIKHuman2::FBIK_JOINT_IDX>(i));
    }
    mJointAssign[uFullbodyIKHuman2::IDX_RIGHT_HAND].mRotate = true;
    mJointAssign[uFullbodyIKHuman2::IDX_LEFT_HAND].mRotate = true;
    mJointAssign[uFullbodyIKHuman2::IDX_RIGHT_FOOT].mRotate = true;
    mJointAssign[uFullbodyIKHuman2::IDX_LEFT_FOOT].mRotate = true;
}

MT_CTSTR rFullbodyIKHuman2::getExt() const {
    return "fbik_human2";
}

void rFullbodyIKHuman2::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPri", &mPri, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIteration", &mIteration, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperBodyRotRate", &mUpperBodyRotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperBodyTransRate", &mUpperBodyTransRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperBodySyncRate", &mUpperBodySyncRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerBodyRotRate", &mLowerBodyRotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerBodyTransRate", &mLowerBodyTransRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerBodySyncRate", &mLowerBodySyncRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeadLookAtRate", &mHeadLookAtRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperBodyLookAtRate", &mUpperBodyLookAtRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerBodyLookAtRate", &mLowerBodyLookAtRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaistHeightLimit", &mWaistHeightLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarRotBlend", &mRCollarRotBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarRotBlend", &mLCollarRotBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarUpBlend", &mRCollarUpBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarDownBlend", &mRCollarDownBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarFrontBlend", &mRCollarFrontBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarBackBlend", &mRCollarBackBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarUpBlend", &mLCollarUpBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarDownBlend", &mLCollarDownBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarFrontBlend", &mLCollarFrontBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarBackBlend", &mLCollarBackBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpineUpperRotRate", &mSpineUpperRotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine0RotRate", &mSpine0RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine1RotRate", &mSpine1RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine2RotRate", &mSpine2RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine3RotRate", &mSpine3RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine4RotRate", &mSpine4RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASS, "JointAssign", reinterpret_cast<MT_MFUNC>(&::rFullbodyIKHuman2::getAssignedJoint), reinterpret_cast<MT_MFUNC>(&::rFullbodyIKHuman2::setAssignedJoint), 160u, reinterpret_cast<MT_MFUNC>(&::rFullbodyIKHuman2::getAssignedJointNum), reinterpret_cast<MT_MFUNC>(&::rFullbodyIKHuman2::setAssignedJointNum));
}

MtUI* rFullbodyIKHuman2::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

static auto ddon_emit_0x01b5b790 __attribute__((used)) = &rFullbodyIKHuman2::getAssignedJointNum;

__attribute__((weak)) void rFullbodyIKHuman2::setAssignedJointNum(u32 Num) {
}

rFullbodyIKHuman2::JointAssign* rFullbodyIKHuman2::getAssignedJoint(u32 idx) {
    return &mJointAssign[idx];
}

void rFullbodyIKHuman2::setAssignedJoint(rFullbodyIKHuman2::JointAssign* pJointAssign, u32 idx) {
    mJointAssign[idx].mFBIKJntNo = pJointAssign->mFBIKJntNo;
    mJointAssign[idx].mTargetJntNo = pJointAssign->mTargetJntNo;
}

rFullbodyIKHuman2::~rFullbodyIKHuman2() {
}

bool rFullbodyIKHuman2::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(0), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rFullbodyIKHuman2::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(0), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rFullbodyIKHuman2::DTI));
}

inline rFullbodyIKHuman2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFullbodyIKHuman2::MyDTI rFullbodyIKHuman2::DTI("rFullbodyIKHuman2", &::cResource::DTI, 1520ul, 0u, 0u);

__attribute__((weak)) MtObject* rFullbodyIKHuman2::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(rFullbodyIKHuman2::DTI)->memAlloc(sizeof(rFullbodyIKHuman2), 16u, rFullbodyIKHuman2::DTI.getID())) rFullbodyIKHuman2;
}

const MtDTI& rFullbodyIKHuman2::JointAssign::getDTI() const {
    return rFullbodyIKHuman2::JointAssign::DTI;
}

inline void* rFullbodyIKHuman2::JointAssign::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rFullbodyIKHuman2::JointAssign::DTI)->memAlloc(sz, align, rFullbodyIKHuman2::JointAssign::DTI.mID);
}

inline void rFullbodyIKHuman2::JointAssign::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFullbodyIKHuman2::JointAssign::DTI)->memFree(p_addr);
}

inline rFullbodyIKHuman2::JointAssign::JointAssign() {
    mFBIKJntNo = 255;
    mTargetJntNo = 255;
    mRotate = false;
    mEffOffset.x = MtVector3::Zero.x;
    mEffOffset.y = MtVector3::Zero.y;
    mEffOffset.z = MtVector3::Zero.z;
    mEffOffset.pad_ = 0.0f;
}

void rFullbodyIKHuman2::JointAssign::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mFBIKJntNo", &mFBIKJntNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetJntNo", &mTargetJntNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffOffset", &mEffOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotate", &mRotate, 0u, 0u);
}

MtUI* rFullbodyIKHuman2::JointAssign::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rFullbodyIKHuman2::JointAssign::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFullbodyIKHuman2::JointAssign::MyDTI rFullbodyIKHuman2::JointAssign::DTI("rFullbodyIKHuman2::JointAssign", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rFullbodyIKHuman2::JointAssign::MyDTI::newInstance() const {
    return new (16u) rFullbodyIKHuman2::JointAssign;
}

