// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShadow.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollision.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtRandom.h"
#include "cDraw.h"
#include "cLightVolume.h"
#include "cUnit.h"
#include "nDrawRasterizerState.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "sScene.h"
#include "sShadow.h"
#include "sUnit.h"
#include "uFilter.h"
#include "uLight.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uPointShadow::getDTI() const {
    return uPointShadow::DTI;
}

uPointShadow::uPointShadow() {
    DDON_STUB("uPointShadow::uPointShadow")
    /* stub */
}

uPointShadow::~uPointShadow() {
    if (mSharedTexture.mRenderTarget != nullptr) {
        mSharedTexture.mRenderTarget->release();
        mSharedTexture.mRenderTarget = nullptr;
    }
    if (mSharedTexture.mDepthStencil != nullptr) {
        mSharedTexture.mDepthStencil->release();
        mSharedTexture.mDepthStencil = nullptr;
    }
    if ((sShadow::mpInstance) == nullptr) {
        return;
    }
    (sShadow::mpInstance)->sShadow::detach(static_cast<uShadow*>(this));
}

__attribute__((weak)) void uPointShadow::moveAfter() {
    DDON_STUB("uPointShadow::moveAfter")
    /* stub */
}

void uPointShadow::createProperty(MtPropertyList& s) {
    createCommonProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowDistanceBias", &mShadowDistanceBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightPos", &mLightPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetLightEnable", &mTargetLightEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTargetLight", reinterpret_cast<MtObject* *>(&mpTargetLight), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "NearClipDistance", reinterpret_cast<MT_MFUNC>(&::uShadow::getNearClipDistance), reinterpret_cast<MT_MFUNC>(&::uShadow::setNearClipDistance), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "LimitRangeEnable", reinterpret_cast<MT_MFUNC>(&::uShadow::isLimitRangeEnable), reinterpret_cast<MT_MFUNC>(&::uShadow::setLimitRangeEnable), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mRangeOBB", &mRangeOBB, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRangeOBB.extent", &mRangeOBB.extent, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRangeOBB.coord", &mRangeOBB.coord, 0u, 0u);
}

MtUI* uPointShadow::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

__attribute__((weak)) void uPointShadow::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uPointShadow::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) bool uPointShadow::isShadowed(const MtSphere& boundary) const {
    DDON_STUB("uPointShadow::isShadowed")
    return {};
}

bool uPointShadow::getLimitRangeOBB(MtOBB* obb) const {
    if (mLimitRangeEnable) {
        if (obb != nullptr) {
            obb->extent.x = mRangeOBB.extent.x;
            obb->extent.y = mRangeOBB.extent.y;
            obb->extent.z = mRangeOBB.extent.z;
            obb->extent.pad_ = 0.0f;
            obb->coord.m[0].x = mRangeOBB.coord.m[0].x;
            obb->coord.m[0].y = mRangeOBB.coord.m[0].y;
            obb->coord.m[0].z = mRangeOBB.coord.m[0].z;
            obb->coord.m[0].w = mRangeOBB.coord.m[0].w;
            obb->coord.m[1].x = mRangeOBB.coord.m[1].x;
            obb->coord.m[1].y = mRangeOBB.coord.m[1].y;
            obb->coord.m[1].z = mRangeOBB.coord.m[1].z;
            obb->coord.m[1].w = mRangeOBB.coord.m[1].w;
            obb->coord.m[2].x = mRangeOBB.coord.m[2].x;
            obb->coord.m[2].y = mRangeOBB.coord.m[2].y;
            obb->coord.m[2].z = mRangeOBB.coord.m[2].z;
            obb->coord.m[2].w = mRangeOBB.coord.m[2].w;
            obb->coord.m[3].x = mRangeOBB.coord.m[3].x;
            obb->coord.m[3].y = mRangeOBB.coord.m[3].y;
            obb->coord.m[3].z = mRangeOBB.coord.m[3].z;
            obb->coord.m[3].w = mRangeOBB.coord.m[3].w;
            return true;
        }
    }
    return false;
}

void uPointShadow::setLimitRangeOBB(const MtOBB& obb) {
    mRangeOBB.extent.x = obb.extent.x;
    mRangeOBB.extent.y = obb.extent.y;
    mRangeOBB.extent.z = obb.extent.z;
    mRangeOBB.extent.pad_ = 0.0f;
    mRangeOBB.coord.m[0].x = obb.coord.m[0].x;
    mRangeOBB.coord.m[0].y = obb.coord.m[0].y;
    mRangeOBB.coord.m[0].z = obb.coord.m[0].z;
    mRangeOBB.coord.m[0].w = obb.coord.m[0].w;
    mRangeOBB.coord.m[1].x = obb.coord.m[1].x;
    mRangeOBB.coord.m[1].y = obb.coord.m[1].y;
    mRangeOBB.coord.m[1].z = obb.coord.m[1].z;
    mRangeOBB.coord.m[1].w = obb.coord.m[1].w;
    mRangeOBB.coord.m[2].x = obb.coord.m[2].x;
    mRangeOBB.coord.m[2].y = obb.coord.m[2].y;
    mRangeOBB.coord.m[2].z = obb.coord.m[2].z;
    mRangeOBB.coord.m[2].w = obb.coord.m[2].w;
    mRangeOBB.coord.m[3].x = obb.coord.m[3].x;
    mRangeOBB.coord.m[3].y = obb.coord.m[3].y;
    mRangeOBB.coord.m[3].z = obb.coord.m[3].z;
    mRangeOBB.coord.m[3].w = obb.coord.m[3].w;
}

__attribute__((weak)) MtSphere uPointShadow::getBoundingSphere() const {
    DDON_STUB("uPointShadow::getBoundingSphere")
    __builtin_unreachable();
}

MtVector3 uPointShadow::getLightPos(uPointLight* pLight) {
    return pLight->mWPos;
}

__attribute__((weak)) void uPointShadow::allocateShadowMap(u32 shadowMapType, u32 mapSize, nDraw::Texture* * depthMap, nDraw::Texture* * tempMap, nDraw::Texture* * depthStencil, bool cache, sShadow::SharedTexture& sharedTexture, u32& rt_offset, u32& ds_offset, bool scratch, u32& rtOffsetScratch, u32& dsOffsetScratch) {
    DDON_STUB("uPointShadow::allocateShadowMap")
    /* stub */
}

__attribute__((weak)) void uPointShadow::drawPoint(cDraw* pdraw) {
    if (mpDepthMap == nullptr) {
        return;
    }
    if (!mDrawEnable) {
        return;
    }
    if (mShadowMapCacheEnable) {
        if (!mValidShadowMapCache) {
            drawCasterPoint(pdraw, mpDepthMapCache, mpDepthStencilCache, true, uShadow::ShadowMap::DrawModeStaticOnly);
        }
        drawCasterPoint(pdraw, mpDepthMap, mpDepthStencil, false, uShadow::ShadowMap::DrawModeDynamicOnly);
    } else {
        drawCasterPoint(pdraw, mpDepthMap, mpDepthStencil, true, uShadow::ShadowMap::DrawModeNormal);
    }
    fillMargin(pdraw);
    if (mShadowMapType == 1) {
        drawCubeBlur(pdraw);
    }
    drawReceiver(pdraw);
}

__attribute__((weak)) void uPointShadow::makeMarginVertices(void* vertices, const MtRect& pos, const MtRect& tex) {
    DDON_STUB("uPointShadow::makeMarginVertices")
    /* stub */
}

__attribute__((weak)) void uPointShadow::fillMargin(cDraw* pdraw) {
    DDON_STUB("uPointShadow::fillMargin")
    /* stub */
}

__attribute__((weak)) void uPointShadow::drawCubeBlur(cDraw* pdraw) {
    DDON_STUB("uPointShadow::drawCubeBlur")
    /* stub */
}

__attribute__((weak)) void uPointShadow::drawCasterPoint(cDraw* pdraw, nDraw::Texture* pDepth, nDraw::Texture* pDepthStencil, bool clear, uShadow::ShadowMap::DrawMode drawMode) {
    DDON_STUB("uPointShadow::drawCasterPoint")
    /* stub */
}

__attribute__((weak)) void uPointShadow::restoreShadowMapFromCache(cDraw* pdraw, const MtRect& srcRect) {
    DDON_STUB("uPointShadow::restoreShadowMapFromCache")
    /* stub */
}

__attribute__((weak)) void uPointShadow::createShadowMap() {
    DDON_STUB("uPointShadow::createShadowMap")
    /* stub */
}

void uPointShadow::releaseShadowMapSub() {
    if (mSharedTexture.mRenderTarget != nullptr) {
        mSharedTexture.mRenderTarget->release();
        mSharedTexture.mRenderTarget = nullptr;
    }
    if (mSharedTexture.mDepthStencil == nullptr) {
        return;
    }
    mSharedTexture.mDepthStencil->release();
    mSharedTexture.mDepthStencil = nullptr;
}

void uPointShadow::drawSub(cDraw* pdraw) {
    if (mManagedType != 0) {
        if ((sShadow::mpInstance) != nullptr) {
            (sShadow::mpInstance)->sShadow::issueOcclusionQuery(pdraw, static_cast<const uShadow*>(this));
        }
    }
    drawPoint(pdraw);
}

__attribute__((weak)) void uPointShadow::setupCasterDrawContext(cDraw* pdraw) {
    DDON_STUB("uPointShadow::setupCasterDrawContext")
    /* stub */
}

__attribute__((weak)) bool uPointShadow::getBoundingVolume(cConvexBoundingVolume* * volume) const {
    DDON_STUB("uPointShadow::getBoundingVolume")
    return {};
}

__attribute__((weak)) void uPointShadow::beginBranchCaster(cDraw* pdraw, uShadow::ShadowMap& shadowMap) {
    DDON_STUB("uPointShadow::beginBranchCaster")
    /* stub */
}

__attribute__((weak)) bool uPointShadow::checkValidShadowMapCacheSub() {
    DDON_STUB("uPointShadow::checkValidShadowMapCacheSub")
    return {};
}

void uPointShadow::setupViewIndependentReceiveState(uShadow::ShadowViewIndependentReceiveState& state) const {
    state.FShadowReceive = 0xF2B906EB;
    state.FShadowReceiveRT = 0xF2B906EB;
    state.FShadowMultiReceiveRT = 0x20870790;
    state.FShadowLightFace = 0x2DA0E6D3;
    if (mMappedToLight) {
        if (mManagedType != 0) {
            state.FShadowReceiveAttn = 0x94B586B1;
        } else {
            state.FShadowReceiveAttn = 0x8187A6B0;
        }
    } else {
        if (mManagedType != 0) {
            state.FShadowReceiveAttn = 0x1990D6B4;
        } else {
            state.FShadowReceiveAttn = 0xC6BF76B3;
        }
    }
    if (mShadowMapType == 0) {
        if (mPCFType != 2) {
            if (mPCFType == 1) {
                state.FShadowFilterPoint = 0xF2EB16CF;
            } else {
                if (mPCFType == 0) {
                    state.FShadowFilterPoint = 0xA74106CE;
                } else {
                    state.FShadowFilterPoint = 0x510566BD;
                }
            }
        } else {
            state.FShadowFilterPoint = 0x4AD976D0;
        }
    } else {
        if (mShadowMapType == 1) {
            state.FShadowFilterPoint = 0xCC4116D1;
        } else {
            state.FShadowFilterPoint = 0xA74106CE;
        }
    }
    state.SSShadowVariance = 0x93BBF17B;
}

__attribute__((weak)) void uPointShadow::setupViewDependentReceiveState(cDraw* pdraw, uShadow::ShadowReceiveParam& param, bool enableFrustum) {
    DDON_STUB("uPointShadow::setupViewDependentReceiveState")
    /* stub */
}

inline uPointShadow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uPointShadow::MyDTI uPointShadow::DTI("uPointShadow", &::uShadow::DTI, 752ul, 0u, 0u);

__attribute__((weak)) MtObject* uPointShadow::MyDTI::newInstance() const {
    DDON_STUB("uPointShadow::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uShadow::usage() {
}

const MtDTI& uShadow::getDTI() const {
    return uShadow::DTI;
}

uShadow::uShadow() {
    DDON_STUB("uShadow::uShadow")
    /* stub */
}

__attribute__((noinline)) uShadow::~uShadow() {
    (sScene::mpInstance)->sScene::detach(static_cast<cUnit*>(this));
    if (mpDepthMap != nullptr) {
        mpDepthMap->release();
        mpDepthMap = nullptr;
    }
    if (mpTempMap != nullptr) {
        mpTempMap->release();
        mpTempMap = nullptr;
    }
    if (mpDepthTempMap != nullptr) {
        mpDepthTempMap->release();
        mpDepthTempMap = nullptr;
    }
    if (mpDepthStencil != nullptr) {
        mpDepthStencil->release();
        mpDepthStencil = nullptr;
    }
    if (mpDepthMapCache != nullptr) {
        mpDepthMapCache->release();
        mpDepthMapCache = nullptr;
    }
    if (mpDepthStencilCache != nullptr) {
        mpDepthStencilCache->release();
        mpDepthStencilCache = nullptr;
    }
    releaseShadowMapSub();
    if (mpRasterizerState[0] != nullptr) {
        mpRasterizerState[0]->release();
        mpRasterizerState[0] = nullptr;
    }
    if (mpRasterizerState[1] != nullptr) {
        mpRasterizerState[1]->release();
        mpRasterizerState[1] = nullptr;
    }
    if (mpRasterizerState[2] != nullptr) {
        mpRasterizerState[2]->release();
        mpRasterizerState[2] = nullptr;
    }
    if (mCacheID != 0) {
        (sShadow::mpInstance)->sShadow::freeShadowCacheID(mCacheID);
        mCacheID = 0;
    }
}

void uShadow::setup() {
    this->cUnit::setup();
    mInitialized = true;
    if (mStandBy) {
        return;
    }
    if (mpDepthMap == nullptr) {
        createShadowMap();
    }
}

__attribute__((weak)) void uShadow::draw(cDraw* pdraw) {
    DDON_STUB("uShadow::draw")
    /* stub */
}

void uShadow::kill() {
    if (mCacheID != 0) {
        (sShadow::mpInstance)->sShadow::freeShadowCacheID(mCacheID);
        mCacheID = 0;
    }
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) != 0) {
        return;
    }
    if ((mBeFlag - 1u) <= 1u) {
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
    }
}

__attribute__((weak)) void uShadow::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShadow::applyWorldOffset")
    /* stub */
}

u64 uShadow::getSystemUnitGroup() const {
    return 2;
}

__attribute__((weak)) void uShadow::setupReceiver(cDraw* pdraw, bool enableFrustum, bool enableLimitRange) {
    DDON_STUB("uShadow::setupReceiver")
    /* stub */
}

bool uShadow::isShadowed(const MtSphere& boundary) const {
    return true;
}

__attribute__((weak)) void uShadow::setShadowReceiveState(cDraw* pdraw, u32 slot) {
    DDON_STUB("uShadow::setShadowReceiveState")
    /* stub */
}

__attribute__((weak)) void uShadow::setNullShadowReceiveState(cDraw* pdraw, u32 slot) {
    DDON_STUB("uShadow::setNullShadowReceiveState")
    /* stub */
}

void uShadow::setShadowDepthBias(f32 b) {
    mShadowDepthBias = b;
}

f32 uShadow::getShadowDistanceScaledDepthBias() const {
    return mShadowDistanceScaledDepthBias;
}

void uShadow::setShadowDistanceScaledDepthBias(f32 b) {
    mShadowDistanceScaledDepthBias = b;
}

f32 uShadow::getShadowSlopeScaledDepthBias() const {
    return mShadowSlopeScaledDepthBias;
}

void uShadow::setShadowSlopeScaledDepthBias(f32 b) {
    if (mShadowSlopeScaledDepthBias == b) {
        return;
    }
    mShadowSlopeScaledDepthBias = b;
    mRasterizerDesc[0].dbias_slope = mShadowSlopeScaledDepthBias;
    if (mpRasterizerState[0] != nullptr) {
        mpRasterizerState[0]->release();
        mpRasterizerState[0] = nullptr;
    }
    mpRasterizerState[0] = new (16u) nDraw::RasterizerState(&mRasterizerDesc[0]);
    mRasterizerDesc[1].dbias_slope = b;
    if (mpRasterizerState[1] != nullptr) {
        mpRasterizerState[1]->release();
        mpRasterizerState[1] = nullptr;
    }
    mpRasterizerState[1] = new (16u) nDraw::RasterizerState(&mRasterizerDesc[1]);
    mRasterizerDesc[2].dbias_slope = b;
    if (mpRasterizerState[2] != nullptr) {
        mpRasterizerState[2]->release();
        mpRasterizerState[2] = nullptr;
    }
    mpRasterizerState[2] = new (16u) nDraw::RasterizerState(&mRasterizerDesc[2]);
}

__attribute__((weak)) void uShadow::setShadowViewDistance(f32 distance) {
    DDON_STUB("uShadow::setShadowViewDistance")
    /* stub */
}

u32 uShadow::getShadowType() const {
    return mShadowType;
}

void uShadow::setShadowMapType(u32 type) {
    if (mShadowMapType != type) {
        mShadowMapType = type;
        if (mpDepthMap != nullptr) {
            mpDepthMap->release();
            mpDepthMap = nullptr;
        }
        if (mpTempMap != nullptr) {
            mpTempMap->release();
            mpTempMap = nullptr;
        }
        if (mpDepthTempMap != nullptr) {
            mpDepthTempMap->release();
            mpDepthTempMap = nullptr;
        }
        if (mpDepthStencil != nullptr) {
            mpDepthStencil->release();
            mpDepthStencil = nullptr;
        }
        if (mpDepthMapCache != nullptr) {
            mpDepthMapCache->release();
            mpDepthMapCache = nullptr;
        }
        if (mpDepthStencilCache != nullptr) {
            mpDepthStencilCache->release();
            mpDepthStencilCache = nullptr;
        }
        releaseShadowMapSub();
        createShadowMap();
    }
}

u32 uShadow::getShadowMapType() const {
    return mShadowMapType;
}

void uShadow::setPCFType(u32 p) {
    if (mPCFType == p) {
        return;
    }
    mPCFType = p;
}

u32 uShadow::getPCFType() const {
    if (mShadowMapType == 0) {
        return mPCFType;
    } else {
        return 0;
    }
}

__attribute__((weak)) void uShadow::setMapSize(u32 size) {
    DDON_STUB("uShadow::setMapSize")
    /* stub */
}

static auto ddon_emit_0x01b642d0 __attribute__((used)) = &uShadow::getMapSize;

static auto ddon_emit_0x01b642e0 __attribute__((used)) = &uShadow::getMapSizeTrue;

void uShadow::setDispersion(f32 d) {
    if (mDispersion == d) {
        return;
    }
    mDispersion = d;
    setBlurParam();
}

f32 uShadow::getDispersion() const {
    return mDispersion;
}

void uShadow::setVSMBlurType(u32 t) {
    if (mVSMBlurType != t) {
        mVSMBlurType = t;
        setBlurParam();
    }
}

u32 uShadow::getVSMBlurType() const {
    return mVSMBlurType;
}

void uShadow::setStandBy(bool s) {
    if (mStandBy != s) {
        mStandBy = s;
        if (s) {
            if (mpDepthMap != nullptr) {
                mpDepthMap->release();
                mpDepthMap = nullptr;
            }
            if (mpTempMap != nullptr) {
                mpTempMap->release();
                mpTempMap = nullptr;
            }
            if (mpDepthTempMap != nullptr) {
                mpDepthTempMap->release();
                mpDepthTempMap = nullptr;
            }
            if (mpDepthStencil != nullptr) {
                mpDepthStencil->release();
                mpDepthStencil = nullptr;
            }
            if (mpDepthMapCache != nullptr) {
                mpDepthMapCache->release();
                mpDepthMapCache = nullptr;
            }
            if (mpDepthStencilCache != nullptr) {
                mpDepthStencilCache->release();
                mpDepthStencilCache = nullptr;
            }
            releaseShadowMapSub();
        } else {
            createShadowMap();
        }
    }
}

bool uShadow::getStandBy() const {
    return mStandBy;
}

static auto ddon_emit_0x01b64350 __attribute__((used)) = &uShadow::isLimitRangeEnable;

static auto ddon_emit_0x01b64360 __attribute__((used)) = &uShadow::setLimitRangeEnable;

bool uShadow::getLimitRangeOBB(MtOBB* obb) const {
    return false;
}

bool uShadow::isMappedTo(uLight* light) const {
    return mMappedToLight && ((light != nullptr) && ((mpTargetLight != nullptr) && (light == mpTargetLight)));
}

static auto ddon_emit_0x01b642f0 __attribute__((used)) = &uShadow::isMappedToLight;

void uShadow::setMappedToLight(bool mappedToLight) {
    if (mMappedToLight == mappedToLight) {
        return;
    }
    mMappedToLight = mappedToLight;
}

void uShadow::setTargetLight(uLight* plight) {
    mpTargetLight = plight;
}

void uShadow::setTargetLightEnable(bool e) {
    mTargetLightEnable = e;
}

void uShadow::setManagedType(u32 type) {
    if (mManagedType != type) {
        if (mpDepthMap != nullptr) {
            mpDepthMap->release();
            mpDepthMap = nullptr;
        }
        if (mpTempMap != nullptr) {
            mpTempMap->release();
            mpTempMap = nullptr;
        }
        if (mpDepthTempMap != nullptr) {
            mpDepthTempMap->release();
            mpDepthTempMap = nullptr;
        }
        if (mpDepthStencil != nullptr) {
            mpDepthStencil->release();
            mpDepthStencil = nullptr;
        }
        if (mpDepthMapCache != nullptr) {
            mpDepthMapCache->release();
            mpDepthMapCache = nullptr;
        }
        if (mpDepthStencilCache != nullptr) {
            mpDepthStencilCache->release();
            mpDepthStencilCache = nullptr;
        }
        releaseShadowMapSub();
        mpTempMap = nullptr;
        mpDepthMap = nullptr;
        mpDepthStencilCache = nullptr;
        mpDepthMapCache = nullptr;
        mpDepthStencil = nullptr;
        if (type == 0) {
            mDrawEnable = true;
        }
        mManagedType = type;
        mCacheCounter = 0;
        mValidShadowMapCache = false;
        createShadowMap();
    }
}

static auto ddon_emit_0x01b64310 __attribute__((used)) = &uShadow::getManagedType;

__attribute__((weak)) MtSphere uShadow::getBoundingSphere() const {
    DDON_STUB("uShadow::getBoundingSphere")
    __builtin_unreachable();
}

void uShadow::setShadowMapCacheEnable(bool enable) {
    if (mShadowMapCacheEnable != enable) {
        if (mpDepthMap != nullptr) {
            mpDepthMap->release();
            mpDepthMap = nullptr;
        }
        if (mpTempMap != nullptr) {
            mpTempMap->release();
            mpTempMap = nullptr;
        }
        if (mpDepthTempMap != nullptr) {
            mpDepthTempMap->release();
            mpDepthTempMap = nullptr;
        }
        if (mpDepthStencil != nullptr) {
            mpDepthStencil->release();
            mpDepthStencil = nullptr;
        }
        if (mpDepthMapCache != nullptr) {
            mpDepthMapCache->release();
            mpDepthMapCache = nullptr;
        }
        if (mpDepthStencilCache != nullptr) {
            mpDepthStencilCache->release();
            mpDepthStencilCache = nullptr;
        }
        releaseShadowMapSub();
        mShadowMapCacheEnable = enable;
        createShadowMap();
    }
}

static auto ddon_emit_0x01b64300 __attribute__((used)) = &uShadow::getShadowMapCacheEnable;

__attribute__((weak)) void uShadow::invalidateShadowMapCache(u32 delayFrame) {
    DDON_STUB("uShadow::invalidateShadowMapCache")
    /* stub */
}

static auto ddon_emit_0x01b643d0 __attribute__((used)) = &uShadow::setNearClipDistance;

static auto ddon_emit_0x01b643c0 __attribute__((used)) = &uShadow::getNearClipDistance;

void uShadow::getDrawUnitState(u32& type, u32& priority) const {
    type = 4;
    priority = 0;
}

__attribute__((weak)) void uShadow::reflectSystemValueUpdateMapSize() {
    DDON_STUB("uShadow::reflectSystemValueUpdateMapSize")
    /* stub */
}

__attribute__((weak)) void uShadow::reflectSystemValueUpdateShadowViewDistance() {
    DDON_STUB("uShadow::reflectSystemValueUpdateShadowViewDistance")
    /* stub */
}

__attribute__((weak)) void uShadow::createCommonProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowGroup", &mShadowGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mShadowMapType", reinterpret_cast<MT_MFUNC>(&::uShadow::getShadowMapType), reinterpret_cast<MT_MFUNC>(&::uShadow::setShadowMapType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mMapSize", reinterpret_cast<MT_MFUNC>(&::uShadow::getMapSize), reinterpret_cast<MT_MFUNC>(&::uShadow::setMapSize), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "MapSize(True)", reinterpret_cast<MT_MFUNC>(&::uShadow::getMapSizeTrue), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mShadowViewDistance", &mShadowViewDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowDepthBias", &mShadowDepthBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mShadowSlopeScaledDepthBias", reinterpret_cast<MT_MFUNC>(&::uShadow::getShadowSlopeScaledDepthBias), reinterpret_cast<MT_MFUNC>(&::uShadow::setShadowSlopeScaledDepthBias), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mShadowDistanceScaledDepthBias", &mShadowDistanceScaledDepthBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mShadowSlopeDepthBias", reinterpret_cast<MT_MFUNC>(&::uShadow::getShadowDistanceScaledDepthBias), reinterpret_cast<MT_MFUNC>(&::uShadow::setShadowDistanceScaledDepthBias), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAlphaThreshold", &mAlphaThreshold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBackforwardViewDistance", &mBackforwardViewDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mStandBy", reinterpret_cast<MT_MFUNC>(&::uShadow::getStandBy), reinterpret_cast<MT_MFUNC>(&::uShadow::setStandBy), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mMappedToLight", reinterpret_cast<MT_MFUNC>(&::uShadow::isMappedToLight), reinterpret_cast<MT_MFUNC>(&::uShadow::setMappedToLight), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    if (mShadowType <= 1u) {
        s << MtProperty(static_cast<MtObject*>(this), "mDeferredShadow", &mDeferredShadow, 0u, 0u);
    }
    if ((mShadowType - 3u) <= 1u) {
        s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "ShadowMapCacheEnable", reinterpret_cast<MT_MFUNC>(&::uShadow::getShadowMapCacheEnable), reinterpret_cast<MT_MFUNC>(&::uShadow::setShadowMapCacheEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    }
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mManagedType", reinterpret_cast<MT_MFUNC>(&::uShadow::getManagedType), reinterpret_cast<MT_MFUNC>(&::uShadow::setManagedType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mPriorityBias", &mPriorityBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDrawEnable", &mDrawEnable, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowAttn", &mShadowAttn, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mVSMBlurType", reinterpret_cast<MT_MFUNC>(&::uShadow::getVSMBlurType), reinterpret_cast<MT_MFUNC>(&::uShadow::setVSMBlurType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDispersion", reinterpret_cast<MT_MFUNC>(&::uShadow::getDispersion), reinterpret_cast<MT_MFUNC>(&::uShadow::setDispersion), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mVarianceEpsilon", &mVarianceEpsilon, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPmaxPower", &mPmaxPower, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mPCFType", reinterpret_cast<MT_MFUNC>(&::uShadow::getPCFType), reinterpret_cast<MT_MFUNC>(&::uShadow::setPCFType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mBorderGradation", &mBorderGradation, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDepthMap", reinterpret_cast<MtObject* *>(&mpDepthMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTempMap", reinterpret_cast<MtObject* *>(&mpTempMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDepthTempMap", reinterpret_cast<MtObject* *>(&mpDepthTempMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDepthStencil", reinterpret_cast<MtObject* *>(&mpDepthStencil), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDepthMapCache", reinterpret_cast<MtObject* *>(&mpDepthMapCache), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDepthStencilCache", reinterpret_cast<MtObject* *>(&mpDepthStencilCache), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsPS3Disable", reinterpret_cast<MT_MFUNC>(&::uShadow::getPS3DisableMode), reinterpret_cast<MT_MFUNC>(&::uShadow::setPS3DisableMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsPS4Disable", reinterpret_cast<MT_MFUNC>(&::uShadow::getPS4DisableMode), reinterpret_cast<MT_MFUNC>(&::uShadow::setPS4DisableMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsPCDisable", reinterpret_cast<MT_MFUNC>(&::uShadow::getPCDisableMode), reinterpret_cast<MT_MFUNC>(&::uShadow::setPCDisableMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) void uShadow::setFrustum(cDraw* pdraw, const MtMatrix& view, const MtMatrix& proj, f32 f) {
    DDON_STUB("uShadow::setFrustum")
    /* stub */
}

__attribute__((weak)) void uShadow::drawCaster(cDraw* pdraw, uShadow::ShadowMap& shadowMap) {
    DDON_STUB("uShadow::drawCaster")
    /* stub */
}

__attribute__((weak)) void uShadow::drawInvolvingCaster(cDraw* pdraw, uShadow::ShadowMap& shadowMap, cUnit* * pInvolveArray, u32& arrayNum, MtSphere& involve_sphere, bool first) {
    DDON_STUB("uShadow::drawInvolvingCaster")
    /* stub */
}

__attribute__((weak)) void uShadow::drawReceiver(cDraw* pdraw) {
    DDON_STUB("uShadow::drawReceiver")
    /* stub */
}

__attribute__((weak)) void uShadow::setupBlurConstant(cDraw* pdraw, u32 size, const MtVector4& uv_min, const MtVector4& uv_max) {
    DDON_STUB("uShadow::setupBlurConstant")
    /* stub */
}

__attribute__((weak)) void uShadow::makeMipMapSubLevel(cDraw* pdraw, nDraw::Texture* ptexture, nDraw::Texture* ptemp, SO_HANDLE func, u32 flag) {
    DDON_STUB("uShadow::makeMipMapSubLevel")
    /* stub */
}

__attribute__((weak)) void uShadow::checkValidShadowMapCache() {
    DDON_STUB("uShadow::checkValidShadowMapCache")
    /* stub */
}

__attribute__((weak)) void uShadow::setupReceiverCommonConstant(uShadow::ShadowReceiveParam& param) const {
    DDON_STUB("uShadow::setupReceiverCommonConstant")
    /* stub */
}

__attribute__((weak)) void uShadow::setupLimitRange(cDraw* pdraw, bool enable, SO_HANDLE destHandle) {
    DDON_STUB("uShadow::setupLimitRange")
    /* stub */
}

__attribute__((weak)) void uShadow::setupMultiShadow(cDraw* pdraw) {
    DDON_STUB("uShadow::setupMultiShadow")
    /* stub */
}

__attribute__((weak)) void uShadow::setupCasterDrawContext(cDraw* pdraw) {
    DDON_STUB("uShadow::setupCasterDrawContext")
    /* stub */
}

__attribute__((weak)) void uShadow::drawBlur(cDraw* pdraw, nDraw::Texture* pdepth, const MtRect& rect) {
    DDON_STUB("uShadow::drawBlur")
    /* stub */
}

__attribute__((weak)) void uShadow::setupManaged(u32 viewNum) {
    DDON_STUB("uShadow::setupManaged")
    /* stub */
}

bool uShadow::getBoundingVolume(cConvexBoundingVolume* * volume) const {
    return false;
}

void uShadow::beginBranchCaster(cDraw* pdraw, uShadow::ShadowMap& shadowMap) {
    if (mShadowGroup == 0) {
        pdraw->beginBranch(nDraw::MODE_SHADOW0_CAST, "ShadowCast");
    } else {
        pdraw->beginBranch(nDraw::MODE_SHADOW1_CAST, "ShadowCast");
    }
}

__attribute__((weak)) void uShadow::beginDrawCaster(cDraw* pdraw, nDraw::Texture* pdepth, nDraw::Texture* pDepthStencil, const MtMatrix& vm, const MtMatrix& pm, const MtRect& vp, bool clear) {
    DDON_STUB("uShadow::beginDrawCaster")
    /* stub */
}

bool uShadow::checkValidShadowMapCacheSub() {
    return true;
}

__attribute__((weak)) void uShadow::setBlurParam() {
    DDON_STUB("uShadow::setBlurParam")
    /* stub */
}

__attribute__((weak)) cUnit::cHardwareDispCtrl* uShadow::createHardwareDispCtrl() {
    DDON_STUB("uShadow::createHardwareDispCtrl")
    return nullptr;
}

void uShadow::setPS3DisableMode(bool set) {
    mIsPS3Disable = set;
    if (mpHardwareDispCtrl == nullptr) {
        return;
    }
    if (set) {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag | 1u;
    } else {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag & 0xFFFFFFFEu;
    }
}

void uShadow::setPS4DisableMode(bool set) {
    mIsPS4Disable = set;
    if (mpHardwareDispCtrl == nullptr) {
        return;
    }
    if (set) {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag | 2u;
    } else {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag & 0xFFFFFFFDu;
    }
}

void uShadow::setPCDisableMode(bool set) {
    mIsPCDisable = set;
    if (mpHardwareDispCtrl == nullptr) {
        return;
    }
    if (set) {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag | 4u;
    } else {
        mpHardwareDispCtrl->mFlag = mpHardwareDispCtrl->mFlag & 0xFFFFFFFBu;
    }
}

static auto ddon_emit_0x01b64320 __attribute__((used)) = &uShadow::getPS3DisableMode;

static auto ddon_emit_0x01b64330 __attribute__((used)) = &uShadow::getPS4DisableMode;

static auto ddon_emit_0x01b64340 __attribute__((used)) = &uShadow::getPCDisableMode;

inline uShadow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShadow::MyDTI uShadow::DTI("uShadow", &::cUnit::DTI, 432ul, 0u, 1u);

MtObject* uShadow::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uShadow::cHardwareDispCtrlShadow::getDTI() const {
    return uShadow::cHardwareDispCtrlShadow::DTI;
}

void* uShadow::cHardwareDispCtrlShadow::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShadow::cHardwareDispCtrlShadow::DTI)->memAlloc(sz, align, uShadow::cHardwareDispCtrlShadow::DTI.mID);
}

void uShadow::cHardwareDispCtrlShadow::update() {
    bool t0 = (sScene::mpInstance)->mLightRestrictPS4;
    bool t1 = (sScene::mpInstance)->mLightRestrictPC;
    if ((sScene::mpInstance)->mLightRestrictPS3) {
        mHard = 0;
    }
    if (t0) {
        mHard = 1;
    }
    if (t1) {
        mHard = 2;
    }
    this->cUnit::cHardwareDispCtrl::update();
}

__attribute__((weak)) bool uShadow::cHardwareDispCtrlShadow::isDispOperateHard() {
    DDON_STUB("uShadow::cHardwareDispCtrlShadow::isDispOperateHard")
    return {};
}

inline uShadow::cHardwareDispCtrlShadow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShadow::cHardwareDispCtrlShadow::MyDTI uShadow::cHardwareDispCtrlShadow::DTI("uShadow::cHardwareDispCtrlShadow", &::cUnit::cHardwareDispCtrl::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* uShadow::cHardwareDispCtrlShadow::MyDTI::newInstance() const {
    DDON_STUB("uShadow::cHardwareDispCtrlShadow::MyDTI::newInstance")
    return nullptr;
}

