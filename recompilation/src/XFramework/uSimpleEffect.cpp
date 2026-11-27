// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSimpleEffect.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cPrim.h"
#include "cPrimTexHandle.h"
#include "cResource.h"
#include "cUnit.h"
#include "nPrim.h"
#include "rEffectAnim.h"
#include "rEffectList.h"
#include "rVertices.h"
#include "sEffect.h"
#include "sPrimitive.h"
#include "uBaseEffect.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uSimpleEffect::getDTI() const {
    return uSimpleEffect::DTI;
}

void* uSimpleEffect::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uSimpleEffect::DTI)->memAlloc(sz, align, uSimpleEffect::DTI.mID);
}

uSimpleEffect::uSimpleEffect() {
    mpVertices = nullptr;
    mParticleNum = 0;
    mParticleCreateNum = 0;
    mpParticle = nullptr;
    mParticleDeltaTime = 1.0f;
    mParticleBuffSize = 0;
    mCreateFlag = 0;
    mpParticleParam = nullptr;
    mpGeneratorParam = nullptr;
    mpResourceInfo = nullptr;
    mListNo = 0;
    mStartRandCtr = 0;
    mParticleType = 27;
    mDrawPass = 17;
    mInitFlag = 0;
    mOfsInvalidMode = 0;
}

uSimpleEffect::~uSimpleEffect() {
    if (mpParticle != nullptr) {
        for (Particle* v0_5 = mpParticle;;) {
            Particle* t0 = v0_5->mpNext;
            delete v0_5;
            if (t0 != nullptr) {
                v0_5 = t0;
            } else {
                break;
            }
        }
    }
    mpParticle = nullptr;
    mParticleNum = 0;
    mParticleBuffSize = 0;
    if (mpVertices != nullptr) {
        mpVertices->release();
        mpVertices = nullptr;
    }
}

__attribute__((weak)) void uSimpleEffect::move() {
    DDON_STUB("uSimpleEffect::move")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::draw(cDraw* pDraw) {
    DDON_STUB("uSimpleEffect::draw")
    /* stub */
}

void uSimpleEffect::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "SleepMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getSleepMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setSleepMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "SchedulerMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getSchedulerMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setSchedulerMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "EventMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getEventMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setEventMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "TimerControlMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getTimerControlMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setTimerControlMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "TextureOmitMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getTextureOmitMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setTextureOmitMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "VBInvalidMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getVBInvalidMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setVBInvalidMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "NoFogMode", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getNoFogMode), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setNoFogMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "OfsInvalidMode", reinterpret_cast<MT_MFUNC>(&::uSimpleEffect::getOfsInvalidMode), reinterpret_cast<MT_MFUNC>(&::uSimpleEffect::setOfsInvalidMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDeltaTimeCoef", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getDeltaTimeCoef), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setDeltaTimeCoef), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDeltaTimeRate", &mDeltaTimeRate, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTimeInterpolationRate", &mTimeInterpolationRate, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBaseFps", &mBaseFps, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mTimer", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getTimer), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setTimer), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mLoopFrame", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getLoopFrame), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setLoopFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mKillNo", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getKillNo), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setKillNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mCullingGroup", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getCullingGroup), reinterpret_cast<MT_MFUNC>(&::uBaseEffect::setCullingGroup), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpEffectList", "resource", reinterpret_cast<MT_MFUNC>(&::uBaseEffect::getEffectList), reinterpret_cast<MT_MFUNC>(&::uSimpleEffect::setEffectList), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mListNo", reinterpret_cast<MT_MFUNC>(&::uSimpleEffect::getListNo), reinterpret_cast<MT_MFUNC>(&::uSimpleEffect::setListNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpVertices", "resource", reinterpret_cast<MT_MFUNC>(&::uSimpleEffect::getVertices), reinterpret_cast<MT_MFUNC>(&::uSimpleEffect::setVertices), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mParticleNum", &mParticleNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParticleCreateNum", &mParticleCreateNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParticleBuffSize", &mParticleBuffSize, 1u, 0u);
}

MtUI* uSimpleEffect::createUI(MtProperty& prop) {
    return this->uBaseEffect::createUI(prop);
}

void uSimpleEffect::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    this->uBaseEffect::applyWorldOffset(offset, MtVector3::Zero);
    for (Particle* pParticle = mpParticle;;) {
        if (pParticle == nullptr) {
            break;
        } else {
            pParticle->mPos.x = offset.x + pParticle->mPos.x;
            pParticle->mPos.y = offset.y + pParticle->mPos.y;
            pParticle->mPos.z = offset.z + pParticle->mPos.z;
            pParticle = pParticle->mpNext;
        }
    }
}

void uSimpleEffect::setEffectList(rEffectList* pEffectList) {
    mCreateFlag = 0;
    mpParticleParam = nullptr;
    mpGeneratorParam = nullptr;
    mpResourceInfo = nullptr;
    mStartRandCtr = 0;
    mParticleType = 27;
    mDrawPass = 17;
    this->uBaseEffect::setEffectList(pEffectList);
    if (mpEffectList != nullptr) {
        initEFLParam();
    }
    if (mParticleNum == 0) {
        return;
    }
    mInitFlag = 1;
}

static auto ddon_emit_0x01bbd090 __attribute__((used)) = &uSimpleEffect::getListNo;

__attribute__((weak)) void uSimpleEffect::setListNo(u32 No) {
    DDON_STUB("uSimpleEffect::setListNo")
    /* stub */
}

static auto ddon_emit_0x01bbd0a0 __attribute__((used)) = &uSimpleEffect::getVertices;

__attribute__((weak)) void uSimpleEffect::setVertices(rVertices* pVertices) {
    DDON_STUB("uSimpleEffect::setVertices")
    /* stub */
}

static auto ddon_emit_0x01bbd050 __attribute__((used)) = &uSimpleEffect::getOfsInvalidMode;

static auto ddon_emit_0x01bbd060 __attribute__((used)) = &uSimpleEffect::setOfsInvalidMode;

__attribute__((weak)) void uSimpleEffect::moveParticle(uSimpleEffect::Particle* pParticle) {
    DDON_STUB("uSimpleEffect::moveParticle")
    /* stub */
}

__attribute__((weak)) bool uSimpleEffect::initEFLParam() {
    DDON_STUB("uSimpleEffect::initEFLParam")
    return {};
}

__attribute__((weak)) void uSimpleEffect::initDrawParam() {
    DDON_STUB("uSimpleEffect::initDrawParam")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::initParticle(uSimpleEffect::Particle* pParticle) {
    DDON_STUB("uSimpleEffect::initParticle")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleBillboard(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleBillboard")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleBillboardCenter(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleBillboardCenter")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticlePolygon(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticlePolygon")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticlePolygonFix(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticlePolygonFix")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleSizeBillboard(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleSizeBillboard")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleSizeBillboardCenter(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleSizeBillboardCenter")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleCullingBillboard(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleCullingBillboard")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleCullingBillboardCenter(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleCullingBillboardCenter")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleCullingPolygon(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleCullingPolygon")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleCullingPolygonFix(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleCullingPolygonFix")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleCullingSizeBillboard(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleCullingSizeBillboard")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::drawParticleCullingSizeBillboardCenter(cDraw* pDraw, cPrim* pPrim) {
    DDON_STUB("uSimpleEffect::drawParticleCullingSizeBillboardCenter")
    /* stub */
}

__attribute__((weak)) void uSimpleEffect::calcPolygonVertex(nPrim::Vertex* pVertex, uSimpleEffect::Particle* pParticle, rEffectAnim::SEQ_PAT* pSeqPat, const MtMatrix& Wmat) {
    DDON_STUB("uSimpleEffect::calcPolygonVertex")
    /* stub */
}

__attribute__((weak)) uSimpleEffect::Particle* uSimpleEffect::allocateParticle() {
    DDON_STUB("uSimpleEffect::allocateParticle")
    return nullptr;
}

inline uSimpleEffect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSimpleEffect::MyDTI uSimpleEffect::DTI("uSimpleEffect", &::uBaseEffect::DTI, 560ul, 0u, 0u);

MtObject* uSimpleEffect::MyDTI::newInstance() const {
    return new (16u) uSimpleEffect;
}

uSimpleEffect::Particle::~Particle() {
}

