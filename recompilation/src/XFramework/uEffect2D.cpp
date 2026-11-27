// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uEffect2D.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cParticle2D.h"
#include "cResource.h"
#include "cUnit.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "nPrim.h"
#include "rEffect2D.h"
#include "sEffect.h"
#include "sMain.h"
#include "sPrimitive.h"
#include "sRender.h"
#include "uCoord.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uEffect2D::getDTI() const {
    return uEffect2D::DTI;
}

void* uEffect2D::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uEffect2D::DTI)->memAlloc(sz, align, uEffect2D::DTI.mID);
}

uEffect2D::uEffect2D() {
    DDON_STUB("uEffect2D::uEffect2D")
    /* stub */
}

__attribute__((noinline)) uEffect2D::~uEffect2D() {
    if (mGenerator != nullptr) {
        MtMemoryAllocator::getAllocator(uEffect2D::DTI)->memFree(static_cast<void*>(mGenerator));
        mGenerator = nullptr;
    }
    mGeneratorNum = 0;
    mGeneratorMoveNum = 0;
    mDrawBuffSize = 0;
    mKillNo = 0;
    mCreateFlag = 0;
    if (mpEffect2D != nullptr) {
        mpEffect2D->release();
        mpEffect2D = nullptr;
    }
    if (mpTempTexture[0] != nullptr) {
        mpTempTexture[0]->release();
        mpTempTexture[0] = nullptr;
    }
    if (mpTempTexture[1] != nullptr) {
        mpTempTexture[1]->release();
        mpTempTexture[1] = nullptr;
    }
    if (mpTempTexture[2] != nullptr) {
        mpTempTexture[2]->release();
        mpTempTexture[2] = nullptr;
    }
    if (mpTempTexture[3] != nullptr) {
        mpTempTexture[3]->release();
        mpTempTexture[3] = nullptr;
    }
    if (mpDepthStencil[0] != nullptr) {
        mpDepthStencil[0]->release();
        mpDepthStencil[0] = nullptr;
    }
    if (mpDepthStencil[1] != nullptr) {
        mpDepthStencil[1]->release();
        mpDepthStencil[1] = nullptr;
    }
    if (mpDepthStencil[2] != nullptr) {
        mpDepthStencil[2]->release();
        mpDepthStencil[2] = nullptr;
    }
    if (mpDepthStencil[3] != nullptr) {
        mpDepthStencil[3]->release();
        mpDepthStencil[3] = nullptr;
    }
}

__attribute__((weak)) void uEffect2D::setup() {
}

__attribute__((weak)) void uEffect2D::move() {
    DDON_STUB("uEffect2D::move")
    /* stub */
}

__attribute__((weak)) void uEffect2D::moveAfter() {
    DDON_STUB("uEffect2D::moveAfter")
    /* stub */
}

void uEffect2D::draw(cDraw* pDraw) {
    if (mpEffect2D == nullptr) {
        return;
    }
    if (getSleepMode()) {
        return;
    }
    if ((mRTFlag & 1u) != 0) {
        if (isSubSceneDraw(pDraw)) {
            drawSubScene(pDraw);
        }
    } else {
        drawScene(pDraw);
    }
}

void uEffect2D::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParentNo", &mParentNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpParent", reinterpret_cast<MT_MFUNC>(&::uCoord::getParent), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setEffectParent), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mScreenPos", &mScreenPos, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "SleepMode", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getSleepMode), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setSleepMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "SchedulerMode", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getSchedulerMode), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setSchedulerMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "EventMode", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getEventMode), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setEventMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "TimerControlMode", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getTimerControlMode), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setTimerControlMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "WorldPosMode", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getWorldPosMode), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setWorldPosMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "RestartFlag", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getRestartFlag), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setRestartFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDeltaTimeCoef", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getDeltaTimeCoef), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setDeltaTimeCoef), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mBaseFps", &mBaseFps, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTimeInterpolationRate", &mTimeInterpolationRate, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mEndType", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getEndType), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setEndType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mTimer", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getTimer), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setTimer), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLoopFrame", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getLoopFrame), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setLoopFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLifeFrame", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getLifeFrame), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setLifeFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mWaitFrame", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getWaitFrame), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setWaitFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mKillNo", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getKillNo), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setKillNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mSizeAdjustType", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getSizeAdjustType), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setSizeAdjustType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mEffectScale", &mEffectScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDrawPriority", &mDrawPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAlphaRate", &mAlphaRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Group", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getGroupFlagBit), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setGroupFlagBit), 162u, reinterpret_cast<MT_MFUNC>(&::uEffect2D::getFlagBitNum), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setDummyU32));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Material", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getMaterialFlagBit), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setMaterialFlagBit), 162u, reinterpret_cast<MT_MFUNC>(&::uEffect2D::getFlagBitNum), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setDummyU32));
    s << MtProperty(static_cast<MtObject*>(this), "mGroupFlag", &mGroupFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaterialFlag", &mMaterialFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpEffect2D", "resource", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getEffect2D), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setEffect2D), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Finish", static_cast<MT_MFUNC>(&::uEffect2D::doFinish), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Restart", static_cast<MT_MFUNC>(&::uEffect2D::doRestart), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Clear", static_cast<MT_MFUNC>(&::uEffect2D::doClear), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "KeepHoldOff", static_cast<MT_MFUNC>(&::uEffect2D::doKeepHoldOff), 10u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mGeneratorNum", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getGeneratorNum), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mGeneratorMoveNum", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getGeneratorMoveNum), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mGeneratorBuffSize", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getGeneratorBuffSize), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mRTBaseMapColor", &mRTBaseMapColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRTNormalMapColor", &mRTNormalMapColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mRTMaskMapAlpha", reinterpret_cast<MT_MFUNC>(&::uEffect2D::getRTMaskMapAlpha), reinterpret_cast<MT_MFUNC>(&::uEffect2D::setRTMaskMapAlpha), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uEffect2D::createUI(MtProperty& prop) {
    return this->uCoord::createUI(prop);
}

u64 uEffect2D::getSystemUnitGroup() const {
    return 16;
}

bool uEffect2D::getBoundary(MtSphere* pdst) {
    pdst->pos.x = mPos.x;
    pdst->pos.y = mPos.y;
    pdst->pos.z = mPos.z;
    pdst->r = 100.0f;
    return true;
}

MT_CTSTR uEffect2D::getName() {
    rEffect2D* v0_0 = mpEffect2D;
    unsigned int i0_1;
    unsigned int v0_3;
    if (v0_0 == nullptr) {
        return this->cUnit::getName();
    } else {
        i0_1 = 0;
        v0_3 = 0;
    }
    for (;;) {
        if (v0_0->mPath[i0_1] == 0) {
            break;
        } else {
            if (v0_0->mPath[i0_1] == 92) {
                v0_3 = i0_1 + 1u;
            }
            i0_1 += 1u;
        }
    }
    return &v0_0->mPath[v0_3];
}

__attribute__((weak)) void uEffect2D::updateWorldMatrix() {
    DDON_STUB("uEffect2D::updateWorldMatrix")
    /* stub */
}

__attribute__((weak)) void uEffect2D::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uEffect2D::applyWorldOffset")
    /* stub */
}

void uEffect2D::setEffectParent(uCoord* pParent) {
    if (pParent != nullptr) {
        mpParent = pParent;
        mStatus = mStatus | 512u;
    } else {
        mpParent = nullptr;
    }
}

bool uEffect2D::getSleepMode() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 272)) & 2) >> 1);
}

void uEffect2D::setSleepMode(bool Mode) {
    if (Mode) {
        mStatus = mStatus | 2u;
    } else {
        mStatus = mStatus & 65533u;
    }
}

bool uEffect2D::getSchedulerMode() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 272)) & 4) >> 2);
}

static auto ddon_emit_0x01b66260 __attribute__((used)) = &uEffect2D::setSchedulerMode;

bool uEffect2D::getEventMode() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 272)) & 8) >> 3);
}

static auto ddon_emit_0x01b66290 __attribute__((used)) = &uEffect2D::setEventMode;

bool uEffect2D::getTimerControlMode() const {
    return static_cast<bool>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 273)) & 1);
}

static auto ddon_emit_0x01b662b0 __attribute__((used)) = &uEffect2D::setTimerControlMode;

bool uEffect2D::getWorldPosMode() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 273)) & 2) >> 1);
}

static auto ddon_emit_0x01b662e0 __attribute__((used)) = &uEffect2D::setWorldPosMode;

bool uEffect2D::getRestartFlag() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 272)) & 16) >> 4);
}

void uEffect2D::setRestartFlag(bool Flag) {
    if (Flag) {
        mStatus = mStatus | 16u;
    } else {
        mStatus = mStatus & 65519u;
    }
}

static auto ddon_emit_0x01b66370 __attribute__((used)) = &uEffect2D::getLoopFrame;

__attribute__((weak)) void uEffect2D::setLoopFrame(u32 LoopFrame) {
    DDON_STUB("uEffect2D::setLoopFrame")
    /* stub */
}

static auto ddon_emit_0x01b663c0 __attribute__((used)) = &uEffect2D::getLifeFrame;

__attribute__((weak)) void uEffect2D::setLifeFrame(u32 LifeFrame) {
    DDON_STUB("uEffect2D::setLifeFrame")
    /* stub */
}

static auto ddon_emit_0x01b66430 __attribute__((used)) = &uEffect2D::getWaitFrame;

static auto ddon_emit_0x01b66440 __attribute__((used)) = &uEffect2D::setWaitFrame;

static auto ddon_emit_0x01b66350 __attribute__((used)) = &uEffect2D::getTimer;

static auto ddon_emit_0x01b66360 __attribute__((used)) = &uEffect2D::setTimer;

static auto ddon_emit_0x01b66300 __attribute__((used)) = &uEffect2D::getDeltaTimeCoef;

static auto ddon_emit_0x01b66310 __attribute__((used)) = &uEffect2D::setDeltaTimeCoef;

static auto ddon_emit_0x01b66450 __attribute__((used)) = &uEffect2D::getKillNo;

static auto ddon_emit_0x01b66460 __attribute__((used)) = &uEffect2D::setKillNo;

void uEffect2D::setAlphaRate(f32 AlphaRate) {
    mAlphaRate = AlphaRate;
    if (0.0f > AlphaRate) {
        mAlphaRate = 0.0f;
    } else {
        if (AlphaRate > 1.0f) {
            mAlphaRate = 1.0f;
        }
    }
}

static auto ddon_emit_0x01b66320 __attribute__((used)) = &uEffect2D::getEndType;

static auto ddon_emit_0x01b66330 __attribute__((used)) = &uEffect2D::setEndType;

static auto ddon_emit_0x01b66470 __attribute__((used)) = &uEffect2D::getSizeAdjustType;

static auto ddon_emit_0x01b66480 __attribute__((used)) = &uEffect2D::setSizeAdjustType;

static auto ddon_emit_0x01b66560 __attribute__((used)) = &uEffect2D::getEffect2D;

__attribute__((weak)) void uEffect2D::setEffect2D(rEffect2D* pEffect2D) {
    DDON_STUB("uEffect2D::setEffect2D")
    /* stub */
}

static auto ddon_emit_0x01b664f0 __attribute__((used)) = &uEffect2D::getFlagBitNum;

bool uEffect2D::getGroupFlagBit(u32 No) const {
    return ((static_cast<unsigned long>(mGroupFlag) >> static_cast<unsigned long>(No & 31u)) & 1ul) != 0;
}

__attribute__((weak)) void uEffect2D::setGroupFlagBit(bool Flag, u32 No) {
    DDON_STUB("uEffect2D::setGroupFlagBit")
    /* stub */
}

bool uEffect2D::getMaterialFlagBit(u32 No) const {
    return ((static_cast<unsigned long>(mMaterialFlag) >> static_cast<unsigned long>(No & 31u)) & 1ul) != 0;
}

__attribute__((weak)) void uEffect2D::setMaterialFlagBit(bool Flag, u32 No) {
    DDON_STUB("uEffect2D::setMaterialFlagBit")
    /* stub */
}

static auto ddon_emit_0x01b665a0 __attribute__((used)) = &uEffect2D::getRTMaskMapAlpha;

static auto ddon_emit_0x01b665b0 __attribute__((used)) = &uEffect2D::setRTMaskMapAlpha;

static auto ddon_emit_0x01b66590 __attribute__((used)) = &uEffect2D::getGeneratorBuffSize;

static auto ddon_emit_0x01b66570 __attribute__((used)) = &uEffect2D::getGeneratorNum;

static auto ddon_emit_0x01b66580 __attribute__((used)) = &uEffect2D::getGeneratorMoveNum;

__attribute__((weak)) void uEffect2D::setDummyU32(u32) {
}

void uEffect2D::setResourceParam(rEffect2D* pEffect2D, u32 GroupFlag, u32 MaterialFlag) {
    mGroupFlag = GroupFlag;
    mMaterialFlag = MaterialFlag;
    setEffect2D(pEffect2D);
}

__attribute__((weak)) void uEffect2D::doFinish() {
    DDON_STUB("uEffect2D::doFinish")
    /* stub */
}

void uEffect2D::doRestart() {
    if (mGeneratorNum == 0) {
        mStatus = (mStatus & 36812u) | 1u;
        mTimeInterpolationRate = 1.0f;
        mIntTimeInterpolationRate = 256;
        mTimer = 0;
        mGeneratorNum = mGeneratorNum;
        mGeneratorMoveNum = mGeneratorNum;
        mLifeTimer = (*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 304)) >> 32;
        return;
    }
    u32 ctr = 0;
    do {
        mGenerator[ctr].restart();
        mGenerator[ctr].closeParticleAll();
        ctr += 1u;
    } while (ctr < mGeneratorNum);
    mStatus = (mStatus & 36812u) | 1u;
    mTimeInterpolationRate = 1.0f;
    mIntTimeInterpolationRate = 256;
    mTimer = 0;
    mGeneratorNum = mGeneratorNum;
    mGeneratorMoveNum = mGeneratorNum;
    mLifeTimer = (*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 304)) >> 32;
}

void uEffect2D::doClear() {
    releaseGenerator();
    mCreateFlag = 0;
    mRTFlag = 0;
    if (mpEffect2D != nullptr) {
        mpEffect2D->release();
        mpEffect2D = nullptr;
    }
    if (mpTempTexture[0] != nullptr) {
        mpTempTexture[0]->release();
        mpTempTexture[0] = nullptr;
    }
    if (mpTempTexture[1] != nullptr) {
        mpTempTexture[1]->release();
        mpTempTexture[1] = nullptr;
    }
    if (mpTempTexture[2] != nullptr) {
        mpTempTexture[2]->release();
        mpTempTexture[2] = nullptr;
    }
    if (mpTempTexture[3] != nullptr) {
        mpTempTexture[3]->release();
        mpTempTexture[3] = nullptr;
    }
    if (mpDepthStencil[0] != nullptr) {
        mpDepthStencil[0]->release();
        mpDepthStencil[0] = nullptr;
    }
    if (mpDepthStencil[1] != nullptr) {
        mpDepthStencil[1]->release();
        mpDepthStencil[1] = nullptr;
    }
    if (mpDepthStencil[2] != nullptr) {
        mpDepthStencil[2]->release();
        mpDepthStencil[2] = nullptr;
    }
    if (mpDepthStencil[3] != nullptr) {
        mpDepthStencil[3]->release();
        mpDepthStencil[3] = nullptr;
    }
    mGroupFlag = 0xFFFFFFFF;
    mMaterialFlag = 0xFFFFFFFF;
}

__attribute__((weak)) void uEffect2D::doKeepHoldOff() {
    DDON_STUB("uEffect2D::doKeepHoldOff")
    /* stub */
}

bool uEffect2D::checkRelation() {
    return true;
}

__attribute__((weak)) bool uEffect2D::initUnitParam() {
    DDON_STUB("uEffect2D::initUnitParam")
    return {};
}

__attribute__((weak)) bool uEffect2D::createGenerator() {
    DDON_STUB("uEffect2D::createGenerator")
    return {};
}

void uEffect2D::releaseGenerator() {
    if (mGenerator != nullptr) {
        MtMemoryAllocator::getAllocator(uEffect2D::DTI)->memFree(static_cast<void*>(mGenerator));
        mGenerator = nullptr;
    }
    mGeneratorNum = 0;
    mGeneratorMoveNum = 0;
    mDrawBuffSize = 0;
    mKillNo = 0;
    mCreateFlag = 0;
}

__attribute__((weak)) void uEffect2D::correctColorIntensity(cParticle2DGenerator* pGenerator, MtColor* pColor, u32 ColorNum, u32* pIntensity, const MtFloat2& Pos) {
}

__attribute__((weak)) void uEffect2D::initParticleMoveCustom(cParticle2DGenerator* pGenerator, cParticle2D* pParticle, cParticle2DMoveCustom* pParticleMove, const MtFloat2& Ofs, const MtFloat2& Dir) {
    DDON_STUB("uEffect2D::initParticleMoveCustom")
    /* stub */
}

__attribute__((weak)) bool uEffect2D::moveParticleMoveCustom(cParticle2DGenerator* pGenerator, cParticle2D* pParticle, cParticle2DMoveCustom* pParticleMove) {
    DDON_STUB("uEffect2D::moveParticleMoveCustom")
    return {};
}

__attribute__((weak)) void uEffect2D::drawScene(cDraw* pDraw) {
    s32 intAlphaRate = getDrawAlphaRate(pDraw);
    u8* v0_0;
    cPrim* pPrim;
    unsigned int i0_10;
    if (intAlphaRate != 0) {
        sPrimitive* t1 = sPrimitive::mpInstance;
        u32 t2 = mDrawPass;
        pPrim = t1->getCPrim(pDraw, static_cast<nDraw::PASS_TYPE>(t2), static_cast<cUnit*>(this));
        u32 t4 = mDrawBuffSize;
        if (t4 != 0) {
            sEffect* t5 = sEffect::mpInstance;
            u32 t6 = pDraw->mJobThreadIndex;
            u8* t7 = t5->getTempBuff(t6, t4);
            if (mGeneratorNum != 0) {
                v0_0 = t7;
                i0_10 = 0;
            } else {
                return;
            }
        } else {
            if (mGeneratorNum != 0) {
                v0_0 = nullptr;
                i0_10 = 0;
            } else {
                return;
            }
        }
    } else {
        return;
    }
    for (;;) {
        cParticle2DGenerator* t9 = mGenerator;
        t9[i0_10].draw(pDraw, pPrim, intAlphaRate, 0u, v0_0);
        if ((i0_10 + 1u) < mGeneratorNum) {
            i0_10 += 1u;
        } else {
            break;
        }
    }
}

bool uEffect2D::isSubSceneDraw(cDraw* pDraw) const {
    return static_cast<bool>(((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pDraw) + 560)) & 0x1000000000000ul) >> 48);
}

__attribute__((weak)) void uEffect2D::drawSubScene(cDraw* pDraw) {
    DDON_STUB("uEffect2D::drawSubScene")
    /* stub */
}

__attribute__((weak)) s32 uEffect2D::getDrawAlphaRate(cDraw* pDraw) const {
    DDON_STUB("uEffect2D::getDrawAlphaRate")
    return {};
}

__attribute__((weak)) bool uEffect2D::getParticleTotalSize(u32 ListNo, cEffectValueU32& Value) {
    DDON_STUB("uEffect2D::getParticleTotalSize")
    return {};
}

__attribute__((weak)) u32 uEffect2D::getParticleSize(u32 ParticleType) {
    DDON_STUB("uEffect2D::getParticleSize")
    return {};
}

__attribute__((weak)) u32 uEffect2D::getParticlePosSize(u32 ParticleType, rEffect2D::E2D_PARTICLE_COMMON* pParticleParam) {
    DDON_STUB("uEffect2D::getParticlePosSize")
    return {};
}

__attribute__((weak)) u32 uEffect2D::getParticleLifeSize(u32 LifeType) {
    DDON_STUB("uEffect2D::getParticleLifeSize")
    return {};
}

__attribute__((weak)) u32 uEffect2D::getParticleMoveSize(u32 MoveType) {
    DDON_STUB("uEffect2D::getParticleMoveSize")
    return {};
}

inline uEffect2D::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uEffect2D::MyDTI uEffect2D::DTI("uEffect2D", &::uCoord::DTI, 448ul, 0u, 0u);

__attribute__((weak)) MtObject* uEffect2D::MyDTI::newInstance() const {
    DDON_STUB("uEffect2D::MyDTI::newInstance")
    return nullptr;
}

