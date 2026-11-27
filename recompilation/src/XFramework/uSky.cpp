// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSky.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtRandom.h"
#include "cDraw.h"
#include "cResource.h"
#include "cUnit.h"
#include "nDrawIndexBuffer.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "nDrawVertexBuffer.h"
#include "rSky.h"
#include "rTexture.h"
#include "sRender.h"
#include "sResource.h"
#include "sUnit.h"
#include "uFilter.h"
#include "uFog.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uSky::usage() {
}

const MtDTI& uSky::getDTI() const {
    return uSky::DTI;
}

uSky::uSky(u32 depth_map_width, u32 depth_map_height) {
    DDON_STUB("uSky::uSky")
    /* stub */
}

__attribute__((noinline)) uSky::~uSky() {
    if (mpResource != nullptr) {
        mpResource->release();
        mpResource = nullptr;
    }
    if (mpRayleighDepthMap != nullptr) {
        mpRayleighDepthMap->release();
        mpRayleighDepthMap = nullptr;
    }
    if (mpMieDepthMap != nullptr) {
        mpMieDepthMap->release();
        mpMieDepthMap = nullptr;
    }
    if (mpRayleighScatterMap != nullptr) {
        mpRayleighScatterMap->release();
        mpRayleighScatterMap = nullptr;
    }
    if (mpMieScatterMap != nullptr) {
        mpMieScatterMap->release();
        mpMieScatterMap = nullptr;
    }
    if (mpCloudScatterMap != nullptr) {
        mpCloudScatterMap->release();
        mpCloudScatterMap = nullptr;
    }
    if (mpCloudScatterTempMap != nullptr) {
        mpCloudScatterTempMap->release();
        mpCloudScatterTempMap = nullptr;
    }
    if (mpVertex != nullptr) {
        mpVertex->release();
        mpVertex = nullptr;
    }
    if (mpIndex != nullptr) {
        mpIndex->release();
        mpIndex = nullptr;
    }
    if (mpFogUnit != nullptr) {
        if ((mpFogUnit->mBeFlag - 1u) <= 1u) {
            mpFogUnit->kill();
        }
    }
    if (mpStarVertexBuffer != nullptr) {
        mpStarVertexBuffer->release();
        mpStarVertexBuffer = nullptr;
    }
    if (mpStarIndexBuffer != nullptr) {
        mpStarIndexBuffer->release();
        mpStarIndexBuffer = nullptr;
    }
    if (mpStarTexture != nullptr) {
        mpStarTexture->release();
        mpStarTexture = nullptr;
    }
    if (mpStarCatalog != nullptr) {
        mpStarCatalog->release();
        mpStarCatalog = nullptr;
    }
    if (mpStarrySkyColorTexture != nullptr) {
        mpStarrySkyColorTexture->release();
        mpStarrySkyColorTexture = nullptr;
    }
}

MtUI* uSky::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uSky::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mTime", &mTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "mHour", reinterpret_cast<MT_MFUNC>(&::uSky::getHour), reinterpret_cast<MT_MFUNC>(&::uSky::setHour), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "mMinute", reinterpret_cast<MT_MFUNC>(&::uSky::getMinute), reinterpret_cast<MT_MFUNC>(&::uSky::setMinute), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "mSecond", reinterpret_cast<MT_MFUNC>(&::uSky::getSecond), reinterpret_cast<MT_MFUNC>(&::uSky::setSecond), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mNorthAxis", &mNorthAxis, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMieScattering", &mMieScattering, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEccentricity", &mEccentricity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMieDensity", &mMieDensity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpResource", "resource", reinterpret_cast<MT_MFUNC>(&::uSky::getResource), reinterpret_cast<MT_MFUNC>(&::uSky::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mSubScenePriority", &mSubScenePriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeightOffset", &mHeightOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCloudiness", &mCloudiness, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCloudHeight", &mCloudHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCloudThickness", &mCloudThickness, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCloudScattering", &mCloudScattering, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCloudEccentricity", &mCloudEccentricity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPreComputeLoopCount", &mPreComputeLoopCount, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLoopCount", &mLoopCount, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mDivX", reinterpret_cast<MT_MFUNC>(&::uSky::getDivX), reinterpret_cast<MT_MFUNC>(&::uSky::setDivX), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mDivY", reinterpret_cast<MT_MFUNC>(&::uSky::getDivY), reinterpret_cast<MT_MFUNC>(&::uSky::setDivY), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mCorrectHorizon", &mCorrectHorizon, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRayleighDepthMap", reinterpret_cast<MtObject* *>(&mpRayleighDepthMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMieDepthMap", reinterpret_cast<MtObject* *>(&mpMieDepthMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRayleighScatterMap", reinterpret_cast<MtObject* *>(&mpRayleighScatterMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMieScatterMap", reinterpret_cast<MtObject* *>(&mpMieScatterMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCloudScatterMap", reinterpret_cast<MtObject* *>(&mpCloudScatterMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "UseFog", reinterpret_cast<MT_MFUNC>(&::uSky::getUseFog), reinterpret_cast<MT_MFUNC>(&::uSky::setUseFog), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "FogUnitLine", reinterpret_cast<MT_MFUNC>(&::uSky::getFogUnitLine), reinterpret_cast<MT_MFUNC>(&::uSky::setFogUnitLine), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mFogSunColorScale", &mFogSunColorScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFogRayleighScale", &mFogRayleighScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFogMieScale", &mFogMieScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mStarNum", reinterpret_cast<MT_MFUNC>(&::uSky::getStarNum), reinterpret_cast<MT_MFUNC>(&::uSky::setStarNum), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpStarTexture", "resource", static_cast<void*>(&mpStarTexture), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mStarRandomSeed", reinterpret_cast<MT_MFUNC>(&::uSky::getStarRandomSeed), reinterpret_cast<MT_MFUNC>(&::uSky::setStarRandomSeed), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpStarCatalog", "resource", reinterpret_cast<MT_MFUNC>(&::uSky::getStarCatalog), reinterpret_cast<MT_MFUNC>(&::uSky::setStarCatalog), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mStarIntensity", &mStarIntensity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStarSize", &mStarSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStarrySkyIntensity", &mStarrySkyIntensity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTwinkleAmplitude", &mTwinkleAmplitude, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpStarrySkyColorTexture", reinterpret_cast<MtObject* *>(&mpStarrySkyColorTexture), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoonEnable", &mMoonEnable, 0u, 0u);
}

void uSky::setup() {
    createBuffer();
    createStar();
    if (mpStarTexture != nullptr) {
        return;
    }
    mpStarTexture = static_cast<rTexture*>((sResource::mpInstance)->create(rTexture::DTI, "sample\\sky\\star", 1u));
}

__attribute__((weak)) void uSky::move() {
    DDON_STUB("uSky::move")
    /* stub */
}

void uSky::draw(cDraw* pdraw) {
    if (mpResource == nullptr) {
        return;
    }
    setConstantBuffer(pdraw);
    uFilter::setSampleCount(pdraw, mPreComputeLoopCount);
    if (mUpdateMap) {
        drawDepthMap(pdraw);
    }
    draw1stPass(pdraw);
    draw2ndPass(pdraw);
    drawStar(pdraw);
    drawSun(pdraw);
    drawMoon(pdraw);
}

static auto ddon_emit_0x01b64e10 __attribute__((used)) = &uSky::getResource;

__attribute__((weak)) void uSky::setResource(rSky* pres) {
    DDON_STUB("uSky::setResource")
    /* stub */
}

void uSky::setNorthAxis(uSky::NORTH_AXIS n) {
    mNorthAxis = static_cast<u32>(n);
}

u32 uSky::getHour() const {
    return static_cast<u32>((static_cast<unsigned long>(mTime) * 0x95217CB1ul) >> 53);
}

__attribute__((weak)) void uSky::setHour(u32 h) {
    DDON_STUB("uSky::setHour")
    /* stub */
}

static auto ddon_emit_0x01b64e50 __attribute__((used)) = &uSky::getMinute;

__attribute__((weak)) void uSky::setMinute(u32 m) {
    DDON_STUB("uSky::setMinute")
    /* stub */
}

static auto ddon_emit_0x01b64e80 __attribute__((used)) = &uSky::getSecond;

__attribute__((weak)) void uSky::setSecond(u32 s) {
    DDON_STUB("uSky::setSecond")
    /* stub */
}

__attribute__((weak)) void uSky::setTime(u32 t) {
    DDON_STUB("uSky::setTime")
    /* stub */
}

void uSky::setMieScattering(const MtVector3& ms) {
    mMieScattering.x = ms.x;
    mMieScattering.y = ms.y;
    mMieScattering.z = ms.z;
    mMieScattering.pad_ = 0.0f;
}

void uSky::setCloudScattering(f32 cs) {
    mCloudScattering = cs;
}

void uSky::setMieDensity(f32 d) {
    mMieDensity = d;
}

void uSky::setCloudiness(f32 c) {
    mCloudiness = c;
}

void uSky::setCloudEccentricity(f32 c) {
    mCloudEccentricity = c;
}

void uSky::setCloudHeight(f32 h) {
    mCloudHeight = h;
}

void uSky::setCloudThickness(f32 t) {
    mCloudThickness = t;
}

__attribute__((weak)) MtVector3 uSky::getSunScatteredColor(f32 h) const {
    DDON_STUB("uSky::getSunScatteredColor")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 uSky::getAmbientColor(f32 h, f32 scale) const {
    DDON_STUB("uSky::getAmbientColor")
    __builtin_unreachable();
}

bool uSky::getUseFog() const {
    return mUseFog;
}

__attribute__((weak)) void uSky::setUseFog(bool u) {
    DDON_STUB("uSky::setUseFog")
    /* stub */
}

u32 uSky::getFogUnitLine() const {
    return mFogUnitLine;
}

__attribute__((weak)) void uSky::setFogUnitLine(u32 l) {
    DDON_STUB("uSky::setFogUnitLine")
    /* stub */
}

rStarCatalog* uSky::getStarCatalog() const {
    return mpStarCatalog;
}

__attribute__((weak)) void uSky::setStarCatalog(rStarCatalog* pres) {
    DDON_STUB("uSky::setStarCatalog")
    /* stub */
}

u32 uSky::getStarRandomSeed() const {
    return mStarRandomSeed;
}

void uSky::setStarRandomSeed(u32 seed) {
    if (mStarRandomSeed != seed) {
        mStarRandomSeed = seed;
        createStar();
    }
}

__attribute__((weak)) MtVector3 uSky::getMoonScatteredColor(f32 h) const {
    DDON_STUB("uSky::getMoonScatteredColor")
    __builtin_unreachable();
}

MtVector3 uSky::getBaseSunColor() const {
    if (mpResource != nullptr) {
        return mpResource->mSunColor;
    } else {
        return MtVector3::Zero;
    }
}

__attribute__((weak)) void uSky::createBuffer() {
    DDON_STUB("uSky::createBuffer")
    /* stub */
}

void uSky::setStarTexture(rTexture* pRes) {
    if (pRes == mpStarTexture) {
        return;
    }
    if (mpStarTexture != nullptr) {
        mpStarTexture->release();
        mpStarTexture = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    mpStarTexture = pRes;
    pRes->addRef();
}

void uSky::setStarIntensity(f32 starIntensity) {
    mStarIntensity = starIntensity;
}

void uSky::setStarSize(f32 starSize) {
    mStarSize = starSize;
}

void uSky::setStarrySkyIntensity(f32 starrySkyIntensity) {
    mStarrySkyIntensity = starrySkyIntensity;
}

void uSky::setStarTwinkleAmplitude(f32 starTwinkleAmplitude) {
    mTwinkleAmplitude = starTwinkleAmplitude;
}

void uSky::setStarCount(u32 cnt) {
    if (mStarNum != cnt) {
        mStarNum = cnt;
        createStar();
    }
}

__attribute__((weak)) void uSky::setConstantBuffer(cDraw* pdraw) {
    DDON_STUB("uSky::setConstantBuffer")
    /* stub */
}

__attribute__((weak)) void uSky::drawDepthMap(cDraw* pdraw) {
    DDON_STUB("uSky::drawDepthMap")
    /* stub */
}

__attribute__((weak)) void uSky::draw1stPass(cDraw* pdraw) {
    DDON_STUB("uSky::draw1stPass")
    /* stub */
}

__attribute__((weak)) void uSky::draw2ndPass(cDraw* pdraw) {
    DDON_STUB("uSky::draw2ndPass")
    /* stub */
}

__attribute__((weak)) void uSky::drawSun(cDraw* pdraw) {
    DDON_STUB("uSky::drawSun")
    /* stub */
}

__attribute__((weak)) void uSky::setupConstantBuffer() {
    DDON_STUB("uSky::setupConstantBuffer")
    /* stub */
}

__attribute__((weak)) void uSky::setupBlurParam(cDraw* pdraw) {
    DDON_STUB("uSky::setupBlurParam")
    /* stub */
}

__attribute__((weak)) MtVector3 uSky::getOutScatter(f32 h, const MtVector3& light_dir) const {
    DDON_STUB("uSky::getOutScatter")
    __builtin_unreachable();
}

u32 uSky::getStarNum() const {
    return mStarNum;
}

void uSky::setStarNum(u32 num) {
    if (mStarNum != num) {
        mStarNum = num;
        createStar();
    }
}

__attribute__((weak)) void uSky::createStar() {
    DDON_STUB("uSky::createStar")
    /* stub */
}

__attribute__((weak)) void uSky::drawStar(cDraw* pdraw) {
    DDON_STUB("uSky::drawStar")
    /* stub */
}

__attribute__((weak)) void uSky::drawMoon(cDraw* pdraw) {
    DDON_STUB("uSky::drawMoon")
    /* stub */
}

MtVector3 uSky::getSunDirforMoon() {
    MtVector3 result;
    result.x = 1.0f;
    result.y = 0.0f;
    result.z = 0.0f;
    result.pad_ = 0.0f;
    return result;
}

u32 uSky::getDivX() const {
    return mDivX;
}

void uSky::setDivX(u32 d) {
    if (mDivX != d) {
        mDivX = d;
        createBuffer();
    }
}

u32 uSky::getDivY() const {
    return mDivY;
}

void uSky::setDivY(u32 d) {
    if (mDivY != d) {
        mDivY = d;
        createBuffer();
    }
}

inline uSky::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSky::MyDTI uSky::DTI("uSky", &::cUnit::DTI, 1280ul, 0u, 0u);

__attribute__((weak)) MtObject* uSky::MyDTI::newInstance() const {
    DDON_STUB("uSky::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uSkyFog::getDTI() const {
    return uSkyFog::DTI;
}

uSkyFog::~uSkyFog() {
}

MtUI* uSkyFog::createUI(MtProperty& prop) {
    return this->uFog::createUI(prop);
}

void uSkyFog::createProperty(MtPropertyList& s) {
    this->uFog::createProperty(s);
}

__attribute__((weak)) void uSkyFog::setState(cDraw* pdraw) {
    DDON_STUB("uSkyFog::setState")
    /* stub */
}

inline uSkyFog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSkyFog::MyDTI uSkyFog::DTI("uSkyFog", &::uFog::DTI, 464ul, 0u, 0u);

__attribute__((weak)) MtObject* uSkyFog::MyDTI::newInstance() const {
    DDON_STUB("uSkyFog::MyDTI::newInstance")
    return nullptr;
}

