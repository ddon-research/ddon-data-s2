// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uEffect.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cParticleGenerator.h"
#include "cParticleManager.h"
#include "cUnit.h"
#include "rEffectList.h"
#include "sCamera.h"
#include "sCollision.h"
#include "sEffect.h"
#include "sMain.h"
#include "sSound.h"
#include "sUnit.h"
#include "uBaseEffect.h"
#include "uCoord.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uEffect::getDTI() const {
    return uEffect::DTI;
}

__attribute__((weak)) void* uEffect::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uEffect::DTI)->memAlloc(sz, align, uEffect::DTI.mID);
}

inline void uEffect::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uEffect::DTI)->memFree(p_addr);
}

uEffect::uEffect() {
    DDON_STUB("uEffect::uEffect")
    /* stub */
}

uEffect::~uEffect() {
    this->uEffect::releaseGenerator();
}

__attribute__((weak)) void uEffect::move() {
    DDON_STUB("uEffect::move")
    /* stub */
}

__attribute__((weak)) void uEffect::sync() {
    DDON_STUB("uEffect::sync")
    /* stub */
}

__attribute__((weak)) void uEffect::moveAfter() {
    DDON_STUB("uEffect::moveAfter")
    /* stub */
}

__attribute__((weak)) void uEffect::draw(cDraw* pDraw) {
    DDON_STUB("uEffect::draw")
    /* stub */
}

void uEffect::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mAngle", reinterpret_cast<MT_MFUNC>(&::uCoord::getAngle), reinterpret_cast<MT_MFUNC>(&::uCoord::setAngleZXY), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mScale", &mScale, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuat", &mQuat, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mOrder", reinterpret_cast<MT_MFUNC>(&::uCoord::getOrder), reinterpret_cast<MT_MFUNC>(&::uCoord::setOrder), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mParentNo", &mParentNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpParent", reinterpret_cast<MT_MFUNC>(&::uCoord::getParent), reinterpret_cast<MT_MFUNC>(&::uEffect::setEffectParent), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "SleepMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getSleepMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setSleepMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "SchedulerMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getSchedulerMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setSchedulerMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "EventMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getEventMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setEventMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "TimerControlMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getTimerControlMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setTimerControlMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "UGInvalidMode", reinterpret_cast<MT_MFUNC>(&::uEffect::getUGInvalidMode), reinterpret_cast<MT_MFUNC>(&::uEffect::setUGInvalidMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "ConstUpdateMode", reinterpret_cast<MT_MFUNC>(&::uEffect::getConstUpdateMode), reinterpret_cast<MT_MFUNC>(&::uEffect::setConstUpdateMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "SeStopMode", reinterpret_cast<MT_MFUNC>(&::uEffect::getSeStopMode), reinterpret_cast<MT_MFUNC>(&::uEffect::setSeStopMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "TextureOmitMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getTextureOmitMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setTextureOmitMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "VBInvalidMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getVBInvalidMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setVBInvalidMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "NoFogMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getNoFogMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setNoFogMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "ParentSymmetryMode", reinterpret_cast<MT_MFUNC>(&::uEffect::getParentSymmetryMode), reinterpret_cast<MT_MFUNC>(&::uEffect::setParentSymmetryMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "JointFixMode", reinterpret_cast<MT_MFUNC>(&::uEffect::getJointFixMode), reinterpret_cast<MT_MFUNC>(&::uEffect::setJointFixMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "RestartFlag", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getRestartFlag), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setRestartFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "ChainResetFlag", reinterpret_cast<MT_MFUNC>(&::uEffect::getChainResetFlag), reinterpret_cast<MT_MFUNC>(&::uEffect::setChainResetFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "JointUpdateFlag", reinterpret_cast<MT_MFUNC>(&::uEffect::getJointUpdateFlag), reinterpret_cast<MT_MFUNC>(&::uEffect::setJointUpdateFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDeltaTimeCoef", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getDeltaTimeCoef), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDeltaTimeCoef), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDeltaTimeRate", &mDeltaTimeRate, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTimeInterpolationRate", &mTimeInterpolationRate, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBaseFps", &mBaseFps, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mAxisType", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getAxisType), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setAxisType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mRelationType", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getRelationType), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setRelationType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mEndType", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getEndType), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setEndType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mTimer", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getTimer), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setTimer), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mParticleScale", reinterpret_cast<MT_MFUNC>(&::uEffect::getParticleScale), reinterpret_cast<MT_MFUNC>(&::uEffect::setParticleScale), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mParticle3DScale", reinterpret_cast<MT_MFUNC>(&::uEffect::getParticle3DScale), reinterpret_cast<MT_MFUNC>(&::uEffect::setParticle3DScale), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLoopFrame", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getLoopFrame), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setLoopFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLifeFrame", reinterpret_cast<MT_MFUNC>(&::uEffect::getLifeFrame), reinterpret_cast<MT_MFUNC>(&::uEffect::setLifeFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mWaitFrame", reinterpret_cast<MT_MFUNC>(&::uEffect::getWaitFrame), reinterpret_cast<MT_MFUNC>(&::uEffect::setWaitFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mChildLoopFrame", reinterpret_cast<MT_MFUNC>(&::uEffect::getChildLoopFrame), reinterpret_cast<MT_MFUNC>(&::uEffect::setChildLoopFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mChildLifeFrame", reinterpret_cast<MT_MFUNC>(&::uEffect::getChildLifeFrame), reinterpret_cast<MT_MFUNC>(&::uEffect::setChildLifeFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mChildWaitFrame", reinterpret_cast<MT_MFUNC>(&::uEffect::getChildWaitFrame), reinterpret_cast<MT_MFUNC>(&::uEffect::setChildWaitFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mOfs", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getOfs), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setOfs), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mDir", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getDir), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDir), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mKillNo", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getKillNo), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setKillNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mExclusionTrait", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getExclusionTrait), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setExclusionTrait), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mParticleVolume", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getParticleVolume), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setParticleVolume), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mFilterVolume", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getFilterVolume), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setFilterVolume), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLifeFrameVolume", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getLifeFrameVolume), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setLifeFrameVolume), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mCullingGroup", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getCullingGroup), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setCullingGroup), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLightPriority", reinterpret_cast<MT_MFUNC>(&::uEffect::getLightPriority), reinterpret_cast<MT_MFUNC>(&::uEffect::setLightPriority), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mGravityCoef", &mGravityCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mWaitFrameCoef", reinterpret_cast<MT_MFUNC>(&::uEffect::getWaitFrameCoef), reinterpret_cast<MT_MFUNC>(&::uEffect::setWaitFrameCoef), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mBoundaryType", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getBoundaryType), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setBoundaryType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mTransparency", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getTransparency), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setTransparency), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDrawDepthBias", &mDrawDepthBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Group", reinterpret_cast<MT_MFUNC>(&::uEffect::getGroupFlagBit), reinterpret_cast<MT_MFUNC>(&::uEffect::setGroupFlagBit), 162u, reinterpret_cast<MT_MFUNC>(&::uEffect::getFlagBitNum), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDummyU32));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Material", reinterpret_cast<MT_MFUNC>(&::uEffect::getMaterialFlagBit), reinterpret_cast<MT_MFUNC>(&::uEffect::setMaterialFlagBit), 162u, reinterpret_cast<MT_MFUNC>(&::uEffect::getFlagBitNum), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDummyU32));
    s << MtProperty(static_cast<MtObject*>(this), "mGroupFlag", &mGroupFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaterialFlag", &mMaterialFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpEffectList", "resource", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getEffectList), reinterpret_cast<MT_MFUNC>(&::uEffect::setEffectList), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Finish", static_cast<MT_MFUNC>(&::uEffect::doFinish), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Restart", static_cast<MT_MFUNC>(&::uEffect::doRestart), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Clear", static_cast<MT_MFUNC>(&::uEffect::doClear), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "KeepHoldOff", static_cast<MT_MFUNC>(&::uEffect::doKeepHoldOff), 10u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mGeneratorNum", reinterpret_cast<MT_MFUNC>(&::uEffect::getGeneratorNum), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mGeneratorMoveNum", reinterpret_cast<MT_MFUNC>(&::uEffect::getGeneratorMoveNum), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mJointNum", reinterpret_cast<MT_MFUNC>(&::uEffect::getJointNum), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mJointMoveNum", reinterpret_cast<MT_MFUNC>(&::uEffect::getJointMoveNum), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mGeneratorBuffSize", reinterpret_cast<MT_MFUNC>(&::uEffect::getGeneratorBuffSize), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uEffect::createUI(MtProperty& prop) {
    return this->uBaseEffect::createUI(prop);
}

__attribute__((weak)) void uEffect::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uEffect::applyWorldOffset")
    /* stub */
}

void uEffect::setParent(uCoord* pParent, s32 ParentNo) {
    setEffectParent(pParent);
    mParentNo = ParentNo;
}

bool uEffect::getBoundary(MtSphere* pdst) {
    pdst->pos.x = mPos.x;
    pdst->pos.y = mPos.y;
    pdst->pos.z = mPos.z;
    pdst->r = mBoundaryRadius;
    return true;
}

__attribute__((weak)) const MtMatrix& uEffect::getWorldMatrix(s32 ParentNo) const {
    DDON_STUB("uEffect::getWorldMatrix")
    __builtin_unreachable();
}

__attribute__((weak)) void uEffect::setEffectParent(uCoord* pParent) {
    DDON_STUB("uEffect::setEffectParent")
    /* stub */
}

__attribute__((weak)) void uEffect::setEffectList(rEffectList* pEffectList) {
    DDON_STUB("uEffect::setEffectList")
    /* stub */
}

void uEffect::doFinish() {
    if ((mSerialEffectType & 15u) == 1) {
        setSerialEffect(1u);
    }
    for (cParticleManager* pManager = mpManager;;) {
        if (pManager == nullptr) {
            break;
        } else {
            pManager->finish(true);
            pManager = pManager->mpNext;
        }
    }
}

__attribute__((weak)) void uEffect::doRestart() {
    DDON_STUB("uEffect::doRestart")
    /* stub */
}

void uEffect::doClear() {
    releaseGenerator();
    this->uBaseEffect::doClear();
    mSetNo = -1;
    mGroupFlag = 0xFFFFFFFF;
    mMaterialFlag = 0xFFFFFFFF;
    mChildUnitLevel = 0;
}

void uEffect::doKeepHoldOff() {
    if ((mSerialEffectType & 15u) == 2) {
        setSerialEffect(1u);
    }
    for (cParticleManager* pManager = mpManager;;) {
        if (pManager == nullptr) {
            break;
        } else {
            pManager->mKeepHoldFlag = 0;
            pManager->mStatus = pManager->mStatus | 0x40000000u;
            pManager = pManager->mpNext;
        }
    }
}

bool uEffect::getUGInvalidMode() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 274)) & 2) >> 1);
}

static auto ddon_emit_0x01b65a70 __attribute__((used)) = &uEffect::setUGInvalidMode;

bool uEffect::getConstUpdateMode() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 274)) & 4) >> 2);
}

__attribute__((weak)) void uEffect::setConstUpdateMode(bool Mode) {
    DDON_STUB("uEffect::setConstUpdateMode")
    /* stub */
}

bool uEffect::getSeStopMode() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 274)) & 64) >> 6);
}

static auto ddon_emit_0x01b65ab0 __attribute__((used)) = &uEffect::setSeStopMode;

bool uEffect::getParentSymmetryMode() const {
    return static_cast<bool>(static_cast<unsigned long>(*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 274)) >> 7);
}

static auto ddon_emit_0x01b65b70 __attribute__((used)) = &uEffect::setParentSymmetryMode;

bool uEffect::getJointFixMode() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 273)) & 64) >> 6);
}

static auto ddon_emit_0x01b65ba0 __attribute__((used)) = &uEffect::setJointFixMode;

bool uEffect::getChainResetFlag() const {
    return static_cast<bool>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 274)) & 1);
}

static auto ddon_emit_0x01b65bd0 __attribute__((used)) = &uEffect::setChainResetFlag;

bool uEffect::getJointUpdateFlag() const {
    return static_cast<bool>(static_cast<unsigned long>(*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 273)) >> 7);
}

static auto ddon_emit_0x01b65c00 __attribute__((used)) = &uEffect::setJointUpdateFlag;

static auto ddon_emit_0x01b659b0 __attribute__((used)) = &uEffect::getParticleScale;

static auto ddon_emit_0x01b659a0 __attribute__((used)) = &uEffect::setParticleScale;

static auto ddon_emit_0x01b65cd0 __attribute__((used)) = &uEffect::getParticle3DScale;

void uEffect::setParticle3DScale(const MtVector3& Particle3DScale) {
    mParticle3DScale.x = Particle3DScale.x;
    mParticle3DScale.y = Particle3DScale.y;
    mParticle3DScale.z = Particle3DScale.z;
    mParticle3DScale.pad_ = 0.0f;
}

static auto ddon_emit_0x01b65d80 __attribute__((used)) = &uEffect::getLifeFrame;

void uEffect::setLifeFrame(u32 LifeFrame) {
    if ((static_cast<unsigned int>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 484)) >> 16) == LifeFrame) {
        return;
    }
    mLifeTimer = LifeFrame;
    mLifeFrame = LifeFrame;
}

static auto ddon_emit_0x01b65dd0 __attribute__((used)) = &uEffect::getWaitFrame;

static auto ddon_emit_0x01b65de0 __attribute__((used)) = &uEffect::setWaitFrame;

static auto ddon_emit_0x01b65df0 __attribute__((used)) = &uEffect::getChildLoopFrame;

static auto ddon_emit_0x01b65e00 __attribute__((used)) = &uEffect::setChildLoopFrame;

static auto ddon_emit_0x01b65e10 __attribute__((used)) = &uEffect::getChildLifeFrame;

static auto ddon_emit_0x01b65e20 __attribute__((used)) = &uEffect::setChildLifeFrame;

static auto ddon_emit_0x01b65e30 __attribute__((used)) = &uEffect::getChildWaitFrame;

static auto ddon_emit_0x01b65e40 __attribute__((used)) = &uEffect::setChildWaitFrame;

static auto ddon_emit_0x01b66030 __attribute__((used)) = &uEffect::getLightPriority;

static auto ddon_emit_0x01b66040 __attribute__((used)) = &uEffect::setLightPriority;

static auto ddon_emit_0x01b66050 __attribute__((used)) = &uEffect::getWaitFrameCoef;

static auto ddon_emit_0x01b66060 __attribute__((used)) = &uEffect::setWaitFrameCoef;

static auto ddon_emit_0x01b66140 __attribute__((used)) = &uEffect::getFlagBitNum;

bool uEffect::getGroupFlagBit(u32 No) const {
    return ((static_cast<unsigned long>(mGroupFlag) >> static_cast<unsigned long>(No & 31u)) & 1ul) != 0;
}

__attribute__((weak)) void uEffect::setGroupFlagBit(bool Flag, u32 No) {
    DDON_STUB("uEffect::setGroupFlagBit")
    /* stub */
}

bool uEffect::getMaterialFlagBit(u32 No) const {
    return ((static_cast<unsigned long>(mMaterialFlag) >> static_cast<unsigned long>(No & 31u)) & 1ul) != 0;
}

__attribute__((weak)) void uEffect::setMaterialFlagBit(bool Flag, u32 No) {
    DDON_STUB("uEffect::setMaterialFlagBit")
    /* stub */
}

static auto ddon_emit_0x01b66200 __attribute__((used)) = &uEffect::getGeneratorBuffSize;

static auto ddon_emit_0x01b661c0 __attribute__((used)) = &uEffect::getGeneratorNum;

static auto ddon_emit_0x01b661d0 __attribute__((used)) = &uEffect::getGeneratorMoveNum;

static auto ddon_emit_0x01b661e0 __attribute__((used)) = &uEffect::getJointNum;

static auto ddon_emit_0x01b661f0 __attribute__((used)) = &uEffect::getJointMoveNum;

void uEffect::setResourceParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag) {
    mGroupFlag = GroupFlag;
    mMaterialFlag = MaterialFlag;
    mpParentGenerator = nullptr;
    mSetNo = -1;
    mChildUnitLevel = 0;
    setEffectList(pEffectList);
}

void uEffect::setResourceParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, uEffect* pParentGenerator, s32 SetNo, f32 SetRate) {
    mGroupFlag = GroupFlag;
    mMaterialFlag = MaterialFlag;
    mpParentGenerator = pParentGenerator;
    mSetNo = SetNo;
    mChildSetRate = static_cast<long>(256.0f * SetRate);
    mChildUnitLevel = 0;
    setEffectList(pEffectList);
}

void uEffect::setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtQuaternion& Quat, uCoord* pParent, s32 ParentNo, const MtVector3& Ofs, u32 Order) {
    setQuatParentOfs(Quat, pParent, ParentNo, Ofs, Order);
    mGroupFlag = GroupFlag;
    mMaterialFlag = MaterialFlag;
    mpParentGenerator = nullptr;
    mSetNo = -1;
    mChildUnitLevel = 0;
    setEffectList(pEffectList);
    mAxisType = 6;
}

void uEffect::setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtQuaternion& Quat, const MtVector3& Pos, u32 Order) {
    setQuatPos(Quat, Pos, Order);
    mGroupFlag = GroupFlag;
    mMaterialFlag = MaterialFlag;
    mpParentGenerator = nullptr;
    mSetNo = -1;
    mChildUnitLevel = 0;
    setEffectList(pEffectList);
    mAxisType = 6;
}

void uEffect::setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtMatrix& Wmat, const MtVector3& Ofs, u32 Order) {
    setWmatOfs(Wmat, Ofs, Order);
    mGroupFlag = GroupFlag;
    mMaterialFlag = MaterialFlag;
    mpParentGenerator = nullptr;
    mSetNo = -1;
    mChildUnitLevel = 0;
    setEffectList(pEffectList);
    mAxisType = 6;
}

void uEffect::setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtVector3& Dir, uCoord* pParent, s32 ParentNo, const MtVector3& Ofs, u32 Order, u32 AxisType) {
    setDirParentOfs(Dir, pParent, ParentNo, Ofs, Order, AxisType);
    mGroupFlag = GroupFlag;
    mMaterialFlag = MaterialFlag;
    mpParentGenerator = nullptr;
    mSetNo = -1;
    mChildUnitLevel = 0;
    setEffectList(pEffectList);
}

void uEffect::setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtVector3& Dir, const MtVector3& Pos, u32 Order, u32 AxisType) {
    setDirPos(Dir, Pos, Order, AxisType);
    mGroupFlag = GroupFlag;
    mMaterialFlag = MaterialFlag;
    mpParentGenerator = nullptr;
    mSetNo = -1;
    mChildUnitLevel = 0;
    setEffectList(pEffectList);
}

void uEffect::setChildUnitLevel(uEffect* pEffect) {
    mChildUnitLevel = ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pEffect) + 484)) + 0x100000000000000ul) >> 56;
}

__attribute__((weak)) u32 uEffect::getParticleHitList(MtVector4* pHitList, u32 HitListNum, u32 SkipNum) const {
    DDON_STUB("uEffect::getParticleHitList")
    return {};
}

__attribute__((weak)) void uEffect::setParticleAdhesionDivideMax(u32 Max) {
    DDON_STUB("uEffect::setParticleAdhesionDivideMax")
    /* stub */
}

bool uEffect::updateDrawBuffSize(u32 DrawBuffSize) {
    if (mDrawBuffSize < DrawBuffSize) {
        mDrawBuffSize = DrawBuffSize;
        if ((sEffect::mpInstance)->mTempBuffSize < DrawBuffSize) {
            mStatus = mStatus | 0x10000000u;
            return false;
        }
    } else {
        if ((sEffect::mpInstance)->mTempBuffSize < mDrawBuffSize) {
            mStatus = mStatus | 0x10000000u;
            return false;
        }
    }
    return true;
}

__attribute__((weak)) void uEffect::correctColorIntensity(cParticleGenerator* pGenerator, MtColor* pColor, u32 ColorNum, u32* pIntensity) {
}

__attribute__((weak)) f32 uEffect::correctModelEnvMapPower(cParticleGenerator* pGenerator, const MtVector3& Pos, f32 OrgEnvMapPower) {
    DDON_STUB("uEffect::correctModelEnvMapPower")
    return {};
}

__attribute__((weak)) MtVector4 uEffect::correctFilterColor(cParticleGenerator* pGenerator, const MtVector3& Pos, const MtVector4& OrgColor) {
    DDON_STUB("uEffect::correctFilterColor")
    __builtin_unreachable();
}

MtVector3 uEffect::correctLightColor(cParticleGenerator* pGenerator, const MtVector3& Pos, const MtVector3& OrgColor) {
    return OrgColor;
}

u32 uEffect::getSynchroFilterDrawView() const {
    return mDrawView;
}

u32 uEffect::getSynchroLightDrawView() const {
    return mDrawView;
}

u32 uEffect::getParticleCustomPosSize(rEffectList::EFL_PARTICLE_CUSTOM* pCustomParam) const {
    return 0;
}

u32 uEffect::getParticleCustomDrawBuffSize(rEffectList::EFL_PARTICLE_CUSTOM* pCustomParam) const {
    return 0;
}

bool uEffect::moveParticleCustom(cParticleGenerator* pGenerator, cParticle* pParticle) {
    return false;
}

bool uEffect::moveParticleMoveCustom(cParticleGenerator* pGenerator, cParticle* pParticle, cParticleMoveCustom* pParticleMove, bool ConstUpdateMode) {
    return true;
}

bool uEffect::isCreateChildUnit() const {
    return mChildUnitLevel < (sEffect::mpInstance)->mChildUnitLevel;
}

MT_CTSTR uEffect::getEffectListPath() const {
    return (mpEffectList == nullptr) ? "No Resource!" : (&mpEffectList->mPath[0]);
}

__attribute__((weak)) MtVector3 uEffect::calcDir(const MtVector3& Rot, u32 Order, u32 AxisType) {
    DDON_STUB("uEffect::calcDir")
    __builtin_unreachable();
}

__attribute__((weak)) uEffect* uEffect::openEffect() {
    DDON_STUB("uEffect::openEffect")
    return nullptr;
}

void uEffect::restart() {
    this->uBaseEffect::restart();
    mStatus = mStatus | 0x100000u;
    mLifeTimer = (*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 484)) >> 16;
}

__attribute__((weak)) bool uEffect::createGenerator() {
    DDON_STUB("uEffect::createGenerator")
    return {};
}

__attribute__((weak)) void uEffect::releaseGenerator() {
    if (mpManager != nullptr) {
        for (cParticleManager* v0_5 = mpManager;;) {
            cParticleManager* t0 = v0_5->mpNext;
            delete v0_5;
            if (t0 != nullptr) {
                v0_5 = t0;
            } else {
                break;
            }
        }
        mpManager = nullptr;
    }
    if (mJoint != nullptr) {
        if (mJointNum != 0) {
            cEffectJoint* v3_0 = mJoint;
            for (unsigned int i3_3 = 0;;) {
                v3_0[i3_3].freeMemory();
                if ((i3_3 + 1u) >= mJointNum) {
                    break;
                } else {
                    v3_0 = mJoint;
                    i3_3 += 1u;
                }
            }
        }
        MtMemoryAllocator::getAllocator(uEffect::DTI)->memFree(static_cast<void*>(mJoint));
        mpChildUnitBuff = nullptr;
        mJoint = nullptr;
    }
    mGeneratorNum = 0;
    mGeneratorMoveNum = 0;
    mJointNum = 0;
    mJointMoveNum = 0;
    mDrawBuffSize = 0;
    mCreateFlag = 0;
    mKillNo = 0;
}

bool uEffect::updateParentEnable() {
    if (mpParent != nullptr) {
        if ((mpParent->mBeFlag - 1u) > 1u) {
            mpParent = nullptr;
            if (mpRelationParent != nullptr) {
                if ((mpRelationParent->mBeFlag - 1u) > 1u) {
                    mpRelationParent = nullptr;
                }
            }
            if (mpParentGenerator != nullptr) {
                if ((mpParentGenerator->mBeFlag - 1u) > 1u) {
                    mpParentGenerator = nullptr;
                }
            }
            return false;
        }
    }
    if (mpRelationParent != nullptr) {
        if ((mpRelationParent->mBeFlag - 1u) > 1u) {
            mpRelationParent = nullptr;
            if (mpParentGenerator != nullptr) {
                if ((mpParentGenerator->mBeFlag - 1u) > 1u) {
                    mpParentGenerator = nullptr;
                }
            }
            return false;
        }
    }
    if (mpParentGenerator != nullptr) {
        if ((mpParentGenerator->mBeFlag - 1u) > 1u) {
            mpParentGenerator = nullptr;
            return false;
        }
    }
    return true;
}

__attribute__((weak)) bool uEffect::checkEffectList(u32 ListNo) {
    DDON_STUB("uEffect::checkEffectList")
    return {};
}

void uEffect::setupUnitGenerator() {
    mJoint->mUpdateConstWorldOfs.x = MtVector3::Zero.x;
    mJoint->mUpdateConstWorldOfs.y = MtVector3::Zero.y;
    mJoint->mUpdateConstWorldOfs.z = MtVector3::Zero.z;
    mJoint->mUpdateConstWorldOfs.pad_ = 0.0f;
    mpManager->setup();
}

void uEffect::setupUnit() {
    if (mJointNum != 0) {
        cEffectJoint* v0_0 = mJoint;
        for (unsigned int i0_1 = 0;;) {
            v0_0[i0_1].mUpdateConstWorldOfs.x = MtVector3::Zero.x;
            v0_0[i0_1].mUpdateConstWorldOfs.y = MtVector3::Zero.y;
            v0_0[i0_1].mUpdateConstWorldOfs.z = MtVector3::Zero.z;
            v0_0[i0_1].mUpdateConstWorldOfs.pad_ = 0.0f;
            if ((i0_1 + 1u) < mJointNum) {
                i0_1 += 1u;
            } else {
                break;
            }
        }
    }
    for (cParticleManager* pManager = mpManager;;) {
        if (pManager == nullptr) {
            break;
        } else {
            pManager->setup();
            pManager = pManager->mpNext;
        }
    }
}

__attribute__((weak)) void uEffect::moveChildUnit() {
    DDON_STUB("uEffect::moveChildUnit")
    /* stub */
}

__attribute__((weak)) void uEffect::moveJointAfter() {
    DDON_STUB("uEffect::moveJointAfter")
    /* stub */
}

__attribute__((weak)) void uEffect::updateJointWorldMatrix(cEffectJoint* pJoint) {
    DDON_STUB("uEffect::updateJointWorldMatrix")
    /* stub */
}

__attribute__((weak)) const MtMatrix& uEffect::getGeneratorParentWorldMatrix(s32 ParentNo, bool ParentSymmetry) const {
    DDON_STUB("uEffect::getGeneratorParentWorldMatrix")
    __builtin_unreachable();
}

__attribute__((weak)) const MtMatrix& uEffect::getGeneratorSubParentWorldMatrix(s32 ParentNo, bool ParentSymmetry) const {
    DDON_STUB("uEffect::getGeneratorSubParentWorldMatrix")
    __builtin_unreachable();
}

__attribute__((weak)) void uEffect::applyBillboardMatrix(cEffectJoint* pJoint) {
    DDON_STUB("uEffect::applyBillboardMatrix")
    /* stub */
}

__attribute__((weak)) void uEffect::setupGenerator(cParticleGenerator* pGenerator) {
}

__attribute__((weak)) void uEffect::setupNode(cParticleNode* pNode) {
}

__attribute__((weak)) void uEffect::applyGeneratorWorldMatrix(cParticleGenerator* pGenerator) {
}

__attribute__((weak)) void uEffect::applyNodeWorldMatrix(cParticleNode* pNode) {
}

__attribute__((weak)) u32 uEffect::updateParticlePosForce(u32 ForceType, f32 ForceRate, const MtVector3& ForceVec, MtVector3& Pos) {
    DDON_STUB("uEffect::updateParticlePosForce")
    return {};
}

__attribute__((weak)) u32 uEffect::checkCollisionLine(sCollision::TriangleInfo* pTriangleInfo, u32* pPtclFlag, const MtLineSegment& LineSegment, rEffectList::EFL_PARAM_COLL* pCollParam) {
    DDON_STUB("uEffect::checkCollisionLine")
    return {};
}

__attribute__((weak)) u32 uEffect::checkCollsionSphere(sCollision::TriangleInfo* pTriangleInfo, u32* pPtclFlag, MtVector3& Pos, const MtVector3& OldPos, f32 Radius, rEffectList::EFL_PARAM_COLL* pCollParam) {
    DDON_STUB("uEffect::checkCollsionSphere")
    return {};
}

u32 uEffect::setCollBounceReaction(rEffectList::EFL_PARAM_COLL* pCollParam, sCollision::TriangleInfo* pInfo, u32 Attribute) {
    return 0;
}

u32 uEffect::setCollFinishReaction(rEffectList::EFL_PARAM_COLL* pCollParam, sCollision::TriangleInfo* pInfo, u32 Attribute) {
    return 0;
}

u32 uEffect::getCollBounceMaterialFlag(sCollision::TriangleInfo* pTriangleInfo) const {
    return mMaterialFlag;
}

u32 uEffect::getCollFinishMaterialFlag(sCollision::TriangleInfo* pTriangleInfo) const {
    return mMaterialFlag;
}

__attribute__((weak)) void uEffect::requestSoundSe(cParticleManager* pManager) {
    DDON_STUB("uEffect::requestSoundSe")
    /* stub */
}

__attribute__((weak)) void uEffect::stopSoundSe(cParticleManager* pManager) {
    DDON_STUB("uEffect::stopSoundSe")
    /* stub */
}

__attribute__((weak)) bool uEffect::createParticleManager() {
    DDON_STUB("uEffect::createParticleManager")
    return {};
}

__attribute__((weak)) bool uEffect::allocGeneratorBuff() {
    DDON_STUB("uEffect::allocGeneratorBuff")
    return {};
}

__attribute__((weak)) bool uEffect::initJoint() {
    DDON_STUB("uEffect::initJoint")
    return {};
}

__attribute__((weak)) void uEffect::setSerialEffect(u32 LoopFrame) {
    DDON_STUB("uEffect::setSerialEffect")
    /* stub */
}

bool uEffect::isEffectSt() {
    return false;
}

inline uEffect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uEffect::MyDTI uEffect::DTI("uEffect", &::uBaseEffect::DTI, 608ul, 0u, 0u);

__attribute__((weak)) MtObject* uEffect::MyDTI::newInstance() const {
    DDON_STUB("uEffect::MyDTI::newInstance")
    return nullptr;
}

