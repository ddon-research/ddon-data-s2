// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uEffectEmitter.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "rEffectList.h"
#include "sCamera.h"
#include "sEffect.h"
#include "sUnit.h"
#include "uBaseEffect.h"
#include "uEffect.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uEffectEmitter::usage() {
}

const MtDTI& uEffectEmitter::getDTI() const {
    return uEffectEmitter::DTI;
}

uEffectEmitter::~uEffectEmitter() {
    if (mpEffect != nullptr) {
        if ((mpEffect->mBeFlag - 1u) <= 1u) {
            mpEffect->kill();
        }
        mpEffect = nullptr;
    }
    if (mpEffectList == nullptr) {
        return;
    }
    mpEffectList->release();
    mpEffectList = nullptr;
}

void uEffectEmitter::setup() {
    this->cUnit::setup();
    unsigned int t0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16);
    if (mMoveLine < mEffectMoveLine) {
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 84) = (mEffectMoveLine * 0x10000u) | mKillNo;
    } else {
        if (mMoveLine == (sUnit::mpInstance)->getLastMoveLineId()) {
            mEffectMoveLine = (sUnit::mpInstance)->getLastMoveLineId();
        } else {
            mEffectMoveLine = (sUnit::mpInstance)->getNextMoveLineId(mMoveLine);
        }
    }
}

__attribute__((weak)) void uEffectEmitter::move() {
    DDON_STUB("uEffectEmitter::move")
    /* stub */
}

void uEffectEmitter::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mEmitFlag", &mEmitFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mControlFlag", &mControlFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Group", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getGroupFlagBit), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setGroupFlagBit), 160u, reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getFlagBitNum), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setDummyU32));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Material", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getMaterialFlagBit), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setMaterialFlagBit), 160u, reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getFlagBitNum), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setDummyU32));
    s << MtProperty(static_cast<MtObject*>(this), "mpEffectList", "resource", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getEffectList), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setEffectList), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mEffectMoveLine", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getEffectMoveLine), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setEffectMoveLine), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mKillNo", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getKillNo), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setKillNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mEventMode", &mEventMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSyncUpdateMode", &mSyncUpdateMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTimerControlMode", &mTimerControlMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUGInvalidMode", &mUGInvalidMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpParent", reinterpret_cast<MtObject* *>(&mpParent), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCamera", reinterpret_cast<MtObject* *>(&mpCamera), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mParentConstType", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getParentConstType), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setParentConstType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mCameraConstType", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getCameraConstType), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setCameraConstType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mOrder", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getOrder), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setOrder), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mAxisType", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getAxisType), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setAxisType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mRelationType", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getRelationType), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setRelationType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mEndType", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getEndType), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setEndType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLoopFrame", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getLoopFrame), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setLoopFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLifeFrame", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getLifeFrame), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setLifeFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mWaitFrame", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getWaitFrame), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setWaitFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mChainResetFlag", &mChainResetFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectTrans", &mEffectTrans, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mEffectDrawMode", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getEffectDrawMode), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setEffectDrawMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mParentNo", &mParentNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPlaySpeed", &mPlaySpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mChildLoopFrame", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getChildLoopFrame), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setChildLoopFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mChildLifeFrame", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getChildLifeFrame), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setChildLifeFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mChildWaitFrame", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getChildWaitFrame), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setChildWaitFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mTimer", &mTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParticleScale", &mParticleScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParticle3DScale", &mParticle3DScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGeneratorScale", &mGeneratorScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOfs", &mOfs, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuat", &mQuat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mAngle", reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::getAngle), reinterpret_cast<MT_MFUNC>(&::uEffectEmitter::setAngle), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDir", &mDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShowMatrix", &mShowMatrix, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShowSize", &mShowSize, 0u, 0u);
}

MtUI* uEffectEmitter::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uEffectEmitter::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mPos.x = offset.x + mPos.x;
    mPos.y = offset.y + mPos.y;
    mPos.z = offset.z + mPos.z;
}

void uEffectEmitter::kill() {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) == 0) {
        if ((mBeFlag - 1u) <= 1u) {
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
        }
    }
    if (mpEffect != nullptr) {
        if ((mpEffect->mBeFlag - 1u) <= 1u) {
            mpEffect->kill();
        }
        mpEffect = nullptr;
    }
    if (mpEffectList == nullptr) {
        return;
    }
    mpEffectList->release();
    mpEffectList = nullptr;
}

u32 uEffectEmitter::getEffectMoveLine() const {
    return mEffectMoveLine;
}

void uEffectEmitter::setEffectMoveLine(u32 EffectMoveLine) {
    unsigned int t0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16);
    if (mMoveLine < EffectMoveLine) {
        mEffectMoveLine = EffectMoveLine;
    } else {
        if (mMoveLine == (sUnit::mpInstance)->getLastMoveLineId()) {
            mEffectMoveLine = (sUnit::mpInstance)->getLastMoveLineId();
        } else {
            mEffectMoveLine = (sUnit::mpInstance)->getNextMoveLineId(mMoveLine);
        }
    }
}

u32 uEffectEmitter::getKillNo() const {
    return mKillNo;
}

void uEffectEmitter::setKillNo(u32 KillNo) {
    mKillNo = KillNo;
}

rEffectList* uEffectEmitter::getEffectList() {
    return mpEffectList;
}

__attribute__((weak)) void uEffectEmitter::setEffectList(rEffectList* pEffectList) {
    DDON_STUB("uEffectEmitter::setEffectList")
    /* stub */
}

u32 uEffectEmitter::getFlagBitNum() const {
    return 32;
}

bool uEffectEmitter::getGroupFlagBit(u32 No) const {
    return ((static_cast<unsigned long>(mGroupFlag) >> static_cast<unsigned long>(No & 31u)) & 1ul) != 0;
}

__attribute__((weak)) void uEffectEmitter::setGroupFlagBit(bool Flag, u32 No) {
    DDON_STUB("uEffectEmitter::setGroupFlagBit")
    /* stub */
}

bool uEffectEmitter::getMaterialFlagBit(u32 No) const {
    return ((static_cast<unsigned long>(mMaterialFlag) >> static_cast<unsigned long>(No & 31u)) & 1ul) != 0;
}

__attribute__((weak)) void uEffectEmitter::setMaterialFlagBit(bool Flag, u32 No) {
    DDON_STUB("uEffectEmitter::setMaterialFlagBit")
    /* stub */
}

u32 uEffectEmitter::getParentConstType() const {
    return mParentConstType;
}

void uEffectEmitter::setParentConstType(u32 ParentConstType) {
    mParentConstType = ParentConstType;
}

u32 uEffectEmitter::getCameraConstType() const {
    return mCameraConstType;
}

void uEffectEmitter::setCameraConstType(u32 CameraConstType) {
    mCameraConstType = CameraConstType;
}

u32 uEffectEmitter::getEffectDrawMode() const {
    return mEffectDrawMode;
}

void uEffectEmitter::setEffectDrawMode(u32 EffectDrawMode) {
    mEffectDrawMode = EffectDrawMode;
}

u32 uEffectEmitter::getOrder() const {
    return mOrder;
}

void uEffectEmitter::setOrder(u32 Order) {
    mOrder = Order;
}

u32 uEffectEmitter::getAxisType() const {
    return mAxisType;
}

void uEffectEmitter::setAxisType(u32 AxisType) {
    mAxisType = AxisType;
}

u32 uEffectEmitter::getRelationType() const {
    return mRelationType;
}

void uEffectEmitter::setRelationType(u32 RelationType) {
    mRelationType = RelationType;
}

u32 uEffectEmitter::getEndType() const {
    return mEndType;
}

void uEffectEmitter::setEndType(u32 EndType) {
    mEndType = EndType;
}

u32 uEffectEmitter::getLoopFrame() const {
    return mLoopFrame;
}

void uEffectEmitter::setLoopFrame(u32 LoopFrame) {
    mLoopFrame = LoopFrame;
}

u32 uEffectEmitter::getLifeFrame() const {
    return mLifeFrame;
}

void uEffectEmitter::setLifeFrame(u32 LifeFrame) {
    mLifeFrame = LifeFrame;
}

u32 uEffectEmitter::getWaitFrame() const {
    return mWaitFrame;
}

void uEffectEmitter::setWaitFrame(u32 WaitFrame) {
    mWaitFrame = WaitFrame;
}

u32 uEffectEmitter::getChildLoopFrame() const {
    return mChildLoopFrame;
}

void uEffectEmitter::setChildLoopFrame(u32 ChildLoopFrame) {
    mChildLoopFrame = ChildLoopFrame;
}

u32 uEffectEmitter::getChildLifeFrame() const {
    return mChildLifeFrame;
}

void uEffectEmitter::setChildLifeFrame(u32 ChildLifeFrame) {
    mChildLifeFrame = ChildLifeFrame;
}

u32 uEffectEmitter::getChildWaitFrame() const {
    return mChildWaitFrame;
}

void uEffectEmitter::setChildWaitFrame(u32 ChildWaitFrame) {
    mChildWaitFrame = ChildWaitFrame;
}

__attribute__((weak)) MtVector3 uEffectEmitter::getAngle() const {
    DDON_STUB("uEffectEmitter::getAngle")
    __builtin_unreachable();
}

__attribute__((weak)) void uEffectEmitter::setAngle(const MtVector3& Angle) {
    DDON_STUB("uEffectEmitter::setAngle")
    /* stub */
}

__attribute__((weak)) void uEffectEmitter::setDummyU32(u32) {
}

__attribute__((weak)) MtMatrix uEffectEmitter::calcParentMatrix(s32 ParentNo) {
    DDON_STUB("uEffectEmitter::calcParentMatrix")
    __builtin_unreachable();
}

__attribute__((weak)) MtMatrix uEffectEmitter::calcCameraMatrix() {
    DDON_STUB("uEffectEmitter::calcCameraMatrix")
    __builtin_unreachable();
}

inline uEffectEmitter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uEffectEmitter::MyDTI uEffectEmitter::DTI("uEffectEmitter", &::cUnit::DTI, 272ul, 0u, 0u);

__attribute__((weak)) MtObject* uEffectEmitter::MyDTI::newInstance() const {
    DDON_STUB("uEffectEmitter::MyDTI::newInstance")
    return nullptr;
}

