// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_kernel.h>
#include <_pthread.h>
#include <content_export.h>
#include <kernel.h>
#include <libsysmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sRender.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPerformance.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#include "../MT/MtThread.h"
#include "../MT/MtType.h"
#include "../generated/shared/basegfxcontext.h"
#include "cDraw.h"
#include "cSystem.h"
#include "../generated/shared/depthrendertarget.h"
#include "../generated/shared/lwgfxcontext.h"
#include "nDraw.h"
#include "nDrawBuffer.h"
#include "nDrawIndexBuffer.h"
#include "nDrawResource.h"
#include "nDrawSamplerState.h"
#include "nDrawScene.h"
#include "nDrawTexture.h"
#include "nDrawVertexBuffer.h"
#include "nPrim.h"
#include "nSyncPoint.h"
#include "../generated/shared/regs.h"
#include "../generated/shared/rendertarget.h"
#include "sApp.h"
#include "sCamera.h"
#include "sMain.h"
#include "sScene.h"
#include "sShader2.h"
#include "sToolBase.h"
#include "sUnit.h"
#include "../generated/shared/sampler.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sRender::getDTI() const {
    return sRender::DTI;
}

sRender::sRender(u32 rendermode_flags, u32 cmdbufsize, u32 ringbufsize, u32 tempvertexbufsize, u32 tempindexbufsize, nDraw::HDR_TYPE hdrtype, nDraw::ANTIALIAS_TYPE aatype, u32 scene_flags) {
    DDON_STUB("sRender::sRender")
    /* stub */
}

__attribute__((noinline)) sRender::~sRender() {
    DDON_STUB("sRender::~sRender")
    /* stub */
}

__attribute__((weak)) void sRender::begin() {
    DDON_STUB("sRender::begin")
    /* stub */
}

__attribute__((weak)) void sRender::end() {
    DDON_STUB("sRender::end")
    /* stub */
}

__attribute__((weak)) void sRender::wait() {
    DDON_STUB("sRender::wait")
    /* stub */
}

__attribute__((weak)) void sRender::sync() {
    DDON_STUB("sRender::sync")
    /* stub */
}

__attribute__((weak)) void sRender::setup() {
}

__attribute__((weak)) void sRender::reset() {
    DDON_STUB("sRender::reset")
    /* stub */
}

__attribute__((weak)) void sRender::move() {
    DDON_STUB("sRender::move")
    /* stub */
}

void sRender::beforeMove() {
    (sUnit::mpInstance)->sUnit::resetDrawCommandCacheCount();
    (sUnit::mpInstance)->sUnit::updateDrawCommandCache();
}

MtUI* sRender::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sRender::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "RenderFps", reinterpret_cast<MT_MFUNC>(&::sRender::getRenderFps), reinterpret_cast<MT_MFUNC>(&::sRender::setRenderFps), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "PresentInterval", reinterpret_cast<MT_MFUNC>(&::sRender::getPresentInterval), reinterpret_cast<MT_MFUNC>(&::sRender::setPresentInterval), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "PresentThreshold", reinterpret_cast<MT_MFUNC>(&::sRender::getPresentThreshold), reinterpret_cast<MT_MFUNC>(&::sRender::setPresentThreshold), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mPresentRect", &mPresentRect, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ScaleMode", reinterpret_cast<MT_MFUNC>(&::sRender::getScaleMode), reinterpret_cast<MT_MFUNC>(&::sRender::setScaleMode), 384u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Gamma", reinterpret_cast<MT_MFUNC>(&::sRender::getDACGamma), reinterpret_cast<MT_MFUNC>(&::sRender::setDACGamma), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mSRGBEnable", &mSRGBEnable, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisplaySize", &mDisplaySize, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBackBufferSize", &mBackBufferSize, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrameSkip", &mFrameSkip, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScreenSize", &mScreenSize, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "HDREmphasis", reinterpret_cast<MT_MFUNC>(&::sRender::getHDREmphasis), reinterpret_cast<MT_MFUNC>(&::sRender::setHDREmphasis), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "HalfLambertBlendCoeff", reinterpret_cast<MT_MFUNC>(&::sRender::getHalfLambertBlendCoeff), reinterpret_cast<MT_MFUNC>(&::sRender::setHalfLambertBlendCoeff), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "SceneAttribute", reinterpret_cast<MT_MFUNC>(&::sRender::getSceneAttribute), reinterpret_cast<MT_MFUNC>(&::sRender::setSceneAttribute), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDeferredLightingHybridLighting", &mDeferredLightingHybridLighting, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDeferredLightingForcedForwardRendering", &mDeferredLightingForcedForwardRendering, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "DeferredLightingNormalType", reinterpret_cast<MT_MFUNC>(&::sRender::getDeferredLightingNormalEncodeType), reinterpret_cast<MT_MFUNC>(&::sRender::setDeferredLightingNormalEncodeType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "DeferredLightingTransparentType", reinterpret_cast<MT_MFUNC>(&::sRender::getDeferredLightingTransparentType), reinterpret_cast<MT_MFUNC>(&::sRender::setDeferredLightingTransparentType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDeferredLightingDiffuseLuminanceThreshold", &mDeferredLightingDiffuseLuminanceThreshold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDeferredLightingFadeOutLighting", &mDeferredLightingFadeOutLighting, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "DeferredLightingFadeOutLightinDistance", reinterpret_cast<MT_MFUNC>(&::sRender::getDeferredLightingFadeOutLightingDistance), reinterpret_cast<MT_MFUNC>(&::sRender::setDeferredLightingFadeOutLightingDistance), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDeferredLightingLodThreshold", &mDeferredLightingLodThreshold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTangentRendering", &mTangentRendering, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDraw", static_cast<MtObject*>(&mDraw), 2050u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDrawBufferPt", &mDrawBufferPt, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDrawBufferSize", &mDrawBufferSize, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTempVertexBufPt", &mTempVertexBufPt, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTempVertexBufSize", &mTempVertexBufSize, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTempIndexBufPt", &mTempIndexBufPt, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTempIndexBufSize", &mTempIndexBufSize, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDynamicTrans", &mDynamicTrans, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParallelTrans", &mParallelTrans, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParallelRendering", &mParallelRendering, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableRendering", &mDisableRendering, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConnectDrawCall", &mConnectDrawCall, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParallelExecuteNum", &mParallelExecuteNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPersRate", &mPersRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSkinningBorder", &mSkinningBorder, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSkinningBorderEx", &mSkinningBorderEx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFeatureLevel", reinterpret_cast<s32*>(&mFeatureLevel), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMipLODBias", &mMipLODBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPrimaryScene", reinterpret_cast<MtObject* *>(&mpPrimaryScene), 2055u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpFrameCacheBuffer", reinterpret_cast<MtObject* *>(&mpFrameCacheBuffer), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Begin Cache", static_cast<MT_MFUNC>(&::sRender::beginFrameCache), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "End Cache", static_cast<MT_MFUNC>(&::sRender::endFrameCache), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "AmbientOcclusion", &mIsDrawFilterArray[0], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Bloom", &mIsDrawFilterArray[1], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Blur", &mIsDrawFilterArray[2], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Bokeh", &mIsDrawFilterArray[3], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ChromaticAberration", &mIsDrawFilterArray[4], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ColorCorrect", &mIsDrawFilterArray[5], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CrossFade", &mIsDrawFilterArray[6], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DOF", &mIsDrawFilterArray[7], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "EdgeAntiAliasing", &mIsDrawFilterArray[8], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "FishEye", &mIsDrawFilterArray[9], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "GodRays", &mIsDrawFilterArray[10], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "HAZE", &mIsDrawFilterArray[11], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ImagePlane", &mIsDrawFilterArray[12], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "MotionBlur", &mIsDrawFilterArray[13], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Outline", &mIsDrawFilterArray[14], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "RadialBlur", &mIsDrawFilterArray[15], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "TangentBlur", &mIsDrawFilterArray[16], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "TVNoise", &mIsDrawFilterArray[17], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ToneMapControl", &mIsDrawFilterArray[18], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "VolumeNoise", &mIsDrawFilterArray[19], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ColorFog", &mIsDrawFogArray[0], 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "LightScatteringFog", &mIsDrawFogArray[1], 2u, 0u);
}

__attribute__((weak)) void sRender::createMenu(MtPropertyList& s) {
}

void sRender::setAspectType(u32 v) {
    if (mAspectType == v) {
        return;
    }
    mAspectType = v;
}

static auto ddon_emit_0x01ba6a80 __attribute__((used)) = &sRender::getAspectType;

void sRender::setScaleMode(u32 scaleMode) {
    mScaleMode = scaleMode;
}

static auto ddon_emit_0x01ba6ac0 __attribute__((used)) = &sRender::getScaleMode;

static auto ddon_emit_0x01ac9230 __attribute__((used)) = &sRender::getDACGamma;

static auto ddon_emit_0x01ac9240 __attribute__((used)) = &sRender::setDACGamma;

__attribute__((weak)) void sRender::setPresentInterval(u32 interval) {
}

__attribute__((weak)) void sRender::setPresentThreshold(u32 t) {
}

u32 sRender::getPresentInterval() {
    return mPresentInterval;
}

u32 sRender::getPresentThreshold() {
    return mPresentThreshold;
}

__attribute__((weak)) void sRender::setFullScreenMode(bool fullscreen, const MtSize& base_sz, bool force) {
}

static auto ddon_emit_0x01ba6a50 __attribute__((used)) = &sRender::getHDRType;

void sRender::setHDRType(nDraw::HDR_TYPE type) {
    if (mHDRType == type) {
        return;
    }
    mHDRType = type;
    mDeviceReset = mDeviceReset | 64u;
}

nDraw::ANTIALIAS_TYPE sRender::getAntiAliasType() const {
    return mAntiAliasType;
}

void sRender::setAntiAliasType(nDraw::ANTIALIAS_TYPE type) {
    if (mAntiAliasType == type) {
        return;
    }
    mAntiAliasType = type;
    mDeviceReset = mDeviceReset | 128u;
}

static auto ddon_emit_0x01ba6a60 __attribute__((used)) = &sRender::getAntiAliasAltType;

static auto ddon_emit_0x01ba6a70 __attribute__((used)) = &sRender::setAntiAliasAltType;

static auto ddon_emit_0x01ba6b10 __attribute__((used)) = &sRender::getSceneAttribute;

void sRender::setSceneAttribute(u32 v) {
    if (mSceneAttribute == v) {
        return;
    }
    mSceneAttribute = v;
    mDeviceReset = mDeviceReset | 64u;
}

f32 sRender::getHDREmphasis() {
    return mpPrimaryScene->mHDREmphasis;
}

void sRender::setHDREmphasis(f32 v) {
    mpPrimaryScene->mHDREmphasis = v;
}

f32 sRender::getAdjustAspectRate() {
    return 1.0f;
}

static auto ddon_emit_0x01ba6a90 __attribute__((used)) = &sRender::getDeferredLightingLightType;

void sRender::setDeferredLightingLightType(nDraw::DEFERRED_LIGHTING_LIGHT_TYPE type) {
    if (mDeferredLightingLightType == type) {
        return;
    }
    mDeferredLightingLightType = type;
    mDeviceReset = mDeviceReset | 64u;
}

static auto ddon_emit_0x01ba6aa0 __attribute__((used)) = &sRender::getDeferredLightingHDRType;

void sRender::setDeferredLightingHDRType(nDraw::DEFERRED_LIGHTING_HDR_TYPE type) {
    if (mDeferredLightingHDRType == type) {
        return;
    }
    mDeferredLightingHDRType = type;
    mDeviceReset = mDeviceReset | 64u;
}

static auto ddon_emit_0x01ba6b20 __attribute__((used)) = &sRender::getDeferredLightingNormalEncodeType;

static auto ddon_emit_0x01ba6b30 __attribute__((used)) = &sRender::setDeferredLightingNormalEncodeType;

static auto ddon_emit_0x01ba6b40 __attribute__((used)) = &sRender::getDeferredLightingTransparentType;

void sRender::setDeferredLightingTransparentType(nDraw::DEFERRED_LIGHTING_TRANSPARENT_TYPE type) {
    if (mDeferredLightingTransparentType == type) {
        return;
    }
    mDeferredLightingTransparentType = type;
    mDeviceReset = mDeviceReset | 64u;
}

static auto ddon_emit_0x01ba6b50 __attribute__((used)) = &sRender::getDeferredLightingFadeOutLightingDistance;

__attribute__((weak)) void sRender::setDeferredLightingFadeOutLightingDistance(f32 distance) {
    DDON_STUB("sRender::setDeferredLightingFadeOutLightingDistance")
    /* stub */
}

static auto ddon_emit_0x01ba6af0 __attribute__((used)) = &sRender::getHalfLambertBlendCoeff;

static auto ddon_emit_0x01ba6b00 __attribute__((used)) = &sRender::setHalfLambertBlendCoeff;

f32 sRender::getRenderFps() {
    if (mRenderTime != 0) {
        return static_cast<float>(1.0 / (1.25e-9 * static_cast<double>(mRenderTime)));
    } else {
        return 0.01f;
    }
}

__attribute__((weak)) void* sRender::allocDrawBuffer(u32 size) {
    DDON_STUB("sRender::allocDrawBuffer")
    return nullptr;
}

void* sRender::allocVertexBuffer(u32 size) {
    s32 t0 = __atomic_fetch_add(&mTempVertexBufPt, static_cast<s32>(size), __ATOMIC_SEQ_CST);
    if ((size + t0) < mTempVertexBufSize) {
        return static_cast<void*>(&mpTempVertexBufTop[t0]);
    } else {
        return nullptr;
    }
}

void* sRender::allocIndexBuffer(u32 size) {
    s32 t0 = __atomic_fetch_add(&mTempIndexBufPt, static_cast<s32>(size), __ATOMIC_SEQ_CST);
    if ((size + t0) < mTempIndexBufSize) {
        return static_cast<void*>(&mpTempIndexBufTop[t0]);
    } else {
        return nullptr;
    }
}

void sRender::beginFrameCache() {
    mFrameCacheState = FRAME_CACHE_SETUP;
}

void sRender::endFrameCache() {
    mFrameCacheState = FRAME_CACHE_NONE;
}

__attribute__((weak)) void sRender::drawFrameCache(cDraw* pdraw, const MtRect* pdrect, const MtRect* psrect) {
    DDON_STUB("sRender::drawFrameCache")
    /* stub */
}

__attribute__((weak)) void sRender::resetDevice() {
    DDON_STUB("sRender::resetDevice")
    /* stub */
}

__attribute__((weak)) bool sRender::isCommandBuffer(void* ptr) {
    DDON_STUB("sRender::isCommandBuffer")
    return {};
}

__attribute__((weak)) void sRender::makeMipMapSubLevel(cDraw* pdraw, nDraw::Texture* ptexture, nDraw::Texture* ptemp, SO_HANDLE func, bool clear_min_level, MtColor clear_color) {
    DDON_STUB("sRender::makeMipMapSubLevel")
    /* stub */
}

__attribute__((weak)) void sRender::copyRegion(cDraw* pdraw, const MtRect& dst_rect, const MtRect& src_rect, const MtSize& src_size, bool duplicateFor3DStereo, bool drawBkBuf) {
    DDON_STUB("sRender::copyRegion")
    /* stub */
}

void* sRender::rendering(void* pArg) {
    for (;;) {
        sceKernelWaitSema((sRender::mpInstance)->mRenderEvent, 1, static_cast<SceKernelUseconds*>(nullptr));
        sceKernelCancelSema((sRender::mpInstance)->mRenderEvent, -1, static_cast<int*>(nullptr));
        if ((sRender::mpInstance)->mExit) {
            break;
        } else {
            (sRender::mpInstance)->sRender::beginRendering();
            (sRender::mpInstance)->sRender::execute2(0u);
            (sRender::mpInstance)->sRender::endRendering();
            sceKernelSignalSema((sRender::mpInstance)->mSyncEvent, 1);
        }
    }
    return nullptr;
}

__attribute__((weak)) void sRender::init(u32 rendermode_flags, u32 ringbufsize) {
    DDON_STUB("sRender::init")
    /* stub */
}

__attribute__((weak)) void sRender::updateFrameCache(cDraw* pdraw) {
    DDON_STUB("sRender::updateFrameCache")
    /* stub */
}

__attribute__((weak)) void sRender::execute2(u32 parallelNo) {
    DDON_STUB("sRender::execute2")
    /* stub */
}

__attribute__((weak)) void sRender::beginRendering() {
    DDON_STUB("sRender::beginRendering")
    /* stub */
}

__attribute__((weak)) void sRender::endRendering() {
    DDON_STUB("sRender::endRendering")
    /* stub */
}

void sRender::addProtectResource(nDraw::Resource* pres) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        u32 t0 = mProtectResourceNum;
        mProtectResourceNum = t0 + 1u;
        mpProtectResources[t0] = pres;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    } else {
        u32 t0 = mProtectResourceNum;
        mProtectResourceNum = t0 + 1u;
        mpProtectResources[t0] = pres;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
}

nDraw::Texture* sRender::addScratchTexture(MT_CTSTR pool, MT_CTSTR name, nDraw::Texture* ptex, u32* poffset) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        u32 t0 = mScratchTextureNum;
        mScratchTextureNum = t0 + 1u;
        mpScratchTextures[t0].ptex = ptex;
        ptex->registerScratchTexture();
        mpScratchTextures[t0].pool = pool;
        mpScratchTextures[t0].name = name;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
        if (poffset != nullptr) {
            *poffset = 0;
        }
        return nullptr;
    } else {
        u32 t0 = mScratchTextureNum;
        mScratchTextureNum = t0 + 1u;
        mpScratchTextures[t0].ptex = ptex;
        ptex->registerScratchTexture();
        mpScratchTextures[t0].pool = pool;
        mpScratchTextures[t0].name = name;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
        if (poffset != nullptr) {
            *poffset = 0;
        }
        return nullptr;
    }
}

void sRender::removeScratchTexture(nDraw::Texture* ptex) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    u32 n = mScratchTextureNum;
    if (n == 0) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
        return;
    } else {
        nDraw::Texture* * v0_0 = &mpScratchTextures[0].ptex;
        u32 i = 0;
        SCRATCH_INFO* p1_0;
        u32 v1_1;
        u32 v1_10;
        for (;;) {
            if (ptex != (*v0_0)) {
                if ((i + 1u) < n) {
                    v0_0 += 3;
                    i = i + 1u;
                } else {
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                            return;
                        }
                    }
                    return;
                }
            } else {
                ptex->unregisterScratchTexture();
                if (i >= (n - 1u)) {
                    mScratchTextureNum = mScratchTextureNum - 1u;
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                            return;
                        }
                    }
                    return;
                } else {
                    p1_0 = &mpScratchTextures[i];
                    v1_1 = i + 1u;
                    v1_10 = (n - i) - 1u;
                    break;
                }
            }
        }
        for (;;) {
            p1_0->ptex = mpScratchTextures[v1_1].ptex;
            p1_0->name = mpScratchTextures[v1_1].name;
            p1_0->pool = mpScratchTextures[v1_1].pool;
            if ((v1_10 - 1u) != 0) {
                p1_0 += 1;
                v1_1 += 1u;
                v1_10 += 0xFFFFFFFFu;
            } else {
                break;
            }
        }
        mScratchTextureNum = mScratchTextureNum - 1u;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
        return;
    }
}

__attribute__((weak)) void sRender::setTargetState(sRender::RENDER_STATE& rs, cDraw::TARGET_STATE* pts) {
    DDON_STUB("sRender::setTargetState")
    /* stub */
}

__attribute__((weak)) void sRender::setDrawState(sRender::RENDER_STATE& rs, cDraw::DRAW_STATE* pds) {
    DDON_STUB("sRender::setDrawState")
    /* stub */
}

__attribute__((weak)) void sRender::setGeomState(sRender::RENDER_STATE& rs, cDraw::GEOM_STATE* pgs, u32 start) {
    DDON_STUB("sRender::setGeomState")
    /* stub */
}

__attribute__((weak)) void sRender::initRenderState(sRender::RENDER_STATE& rs, u32 parallelNo) {
    DDON_STUB("sRender::initRenderState")
    /* stub */
}

__attribute__((weak)) void sRender::setViewports(sRender::RENDER_STATE& rs, u32 num, const MtRect* prects) {
    DDON_STUB("sRender::setViewports")
    /* stub */
}

bool sRender::findWaitAddr(sRender::RENDER_STATE& rs, u32 addr) {
    u32 i = 0;
    unsigned int* p2 = &rs.wait_addr[0];
    do {
        if ((*p2) == addr) {
            return true;
        }
        i += 1u;
        p2 += static_cast<int>(1);
    } while (i <= 3u);
    return false;
}

void sRender::addWaitAddr(sRender::RENDER_STATE& rs, u32 addr) {
    rs.wait_addr[rs.wait_addr_pt] = addr;
    rs.wait_addr_pt = (rs.wait_addr_pt + 1u) & 3u;
}

__attribute__((weak)) void sRender::createDisplayModeInfo() {
    DDON_STUB("sRender::createDisplayModeInfo")
    /* stub */
}

__attribute__((weak)) void sRender::drawBackBuffer(cDraw* pdraw, u32 display_no) {
    DDON_STUB("sRender::drawBackBuffer")
    /* stub */
}

s32 sRender::getResolution() {
    MT_CHAR ss[128];
    sprintf(ss, "%dx%d", mBackBufferSize.w, mBackBufferSize.h);
    unsigned int v1_12;
    if (mResolutionList[0].name == nullptr) {
        v1_12 = 0xFFFFFFFF;
    } else {
        unsigned int i0_3 = 0;
        MT_CTSTR v0_5 = mResolutionList[0].name;
        for (MT_ENUM* p0_11 = &mResolutionList[1];;) {
            if (strcmp(v0_5, ss) != 0) {
                if (p0_11->name != nullptr) {
                    i0_3 = i0_3 + 1u;
                    v0_5 = p0_11->name;
                    p0_11 += 1;
                } else {
                    v1_12 = 0xFFFFFFFF;
                    break;
                }
            } else {
                v1_12 = i0_3;
                break;
            }
        }
    }
    return static_cast<s32>(v1_12);
}

__attribute__((weak)) void sRender::setResolution(s32 v) {
    DDON_STUB("sRender::setResolution")
    /* stub */
}

void sRender::endProtect() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    unsigned int v5_3;
    if (mProtectResourceNum == 0) {
        v5_3 = 0;
    } else {
        u32 v0_0 = mProtectResourceNum;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mpProtectResources[i0_3]->mRefFrame >= (nDraw::Resource::mRenderFrame)) {
                v1_0 = v0_0;
            } else {
                if (mpProtectResources[i0_3] != nullptr) {
                    delete mpProtectResources[i0_3];
                }
                mpProtectResources[i0_3] = nullptr;
                v1_0 = mProtectResourceNum;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
        if (v1_0 == 0) {
            v5_3 = 0;
        } else {
            u32 v3_0 = v1_0;
            unsigned int i3_1 = 0;
            unsigned int i3_3 = 0;
            u32 v4_0;
            unsigned int v4_2;
            for (;;) {
                if (mpProtectResources[i3_1] == nullptr) {
                    v4_0 = v3_0;
                    v4_2 = i3_3;
                } else {
                    mpProtectResources[i3_3] = mpProtectResources[i3_1];
                    v4_0 = mProtectResourceNum;
                    v4_2 = i3_3 + 1u;
                }
                if ((i3_1 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_1 += 1u;
                    i3_3 = v4_2;
                } else {
                    v5_3 = v4_2;
                    break;
                }
            }
        }
    }
    mProtectResourceNum = v5_3;
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

__attribute__((weak)) void sRender::setRenderFps(f32) {
}

bool sRender::isPossibleDrawFromDrawBuffer() {
    return true;
}

__attribute__((weak)) s32 sRender::initVideoOut() {
    DDON_STUB("sRender::initVideoOut")
    return {};
}

__attribute__((weak)) u32 sRender::serializeTagsRecursive(u32 cur_index, cDraw::TAG* pdst, u32 dst_num, const cDraw::TAG* psrc, u32 src_num) {
    DDON_STUB("sRender::serializeTagsRecursive")
    return {};
}

void* sRender::renderingSub(void* pArg) {
    const u64 wakeup_bit = 1ul << static_cast<unsigned long>(static_cast<unsigned char>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pArg) + 28)) * 2u) & 63);
    for (const u64 sleep_bit = 1ul << static_cast<unsigned long>(static_cast<unsigned char>(((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pArg) + 28)) * 2u) + 1u) & 63);;) {
        sceKernelWaitEventFlag((sRender::mpInstance)->mParallelExecuteEventFlag, wakeup_bit, 33u, static_cast<uint64_t*>(nullptr), static_cast<SceKernelUseconds*>(nullptr));
        if ((sRender::mpInstance)->mExit) {
            break;
        } else {
            (sRender::mpInstance)->sRender::execute2(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pArg) + 28));
            sceKernelSetEventFlag((sRender::mpInstance)->mParallelExecuteEventFlag, sleep_bit);
        }
    }
    return nullptr;
}

bool sRender::beginScreenShot() {
    if ((sRender::mSSTrigger) != 0) {
        return false;
    } else {
        mpScreenShotTexture = nullptr;
        mJpgBuffer = nullptr;
        mJpgBufferSize = 0;
        mSSState = SS_NONE;
        return true;
    }
}

bool sRender::setScreenShotTrigger() {
    const s32 trigger = __atomic_fetch_add(&(sRender::mSSTrigger), 1, __ATOMIC_SEQ_CST);
    if (trigger != 0) {
        __atomic_fetch_add(&(sRender::mSSTrigger), -1, __ATOMIC_SEQ_CST);
        return false;
    } else {
        nDraw::Texture* t0 = mpScreenShotTexture;
        if (t0 != nullptr) {
            t0->release();
            mpScreenShotTexture = nullptr;
            u32 w = mScreenSize.w;
            u32 h = mScreenSize.h;
            mpScreenShotTexture = new (16u) nDraw::Texture(w, h, 1u, 1u, nDraw::FORMAT_B8G8R8A8_UNORM_SRGB, nDraw::USAGE_RENDERTARGET, 16u, static_cast<nDraw::Texture*>(nullptr), 0u, static_cast<void*>(nullptr), nDraw::TEXMEMORY_VRAM);
        } else {
            u32 w = mScreenSize.w;
            u32 h = mScreenSize.h;
            mpScreenShotTexture = new (16u) nDraw::Texture(w, h, 1u, 1u, nDraw::FORMAT_B8G8R8A8_UNORM_SRGB, nDraw::USAGE_RENDERTARGET, 16u, static_cast<nDraw::Texture*>(nullptr), 0u, static_cast<void*>(nullptr), nDraw::TEXMEMORY_VRAM);
        }
        mSSState = SS_WAITING;
        mSSResult = SCREENSHOT_PROCESSING;
        return true;
    }
}

sRender::SCREENSHOT_RESULT sRender::screenShotResult() {
    return mSSResult;
}

u32 sRender::getJpgSize() {
    if (mSSState == SS_SUCCESS) {
        return mJpgBufferSize;
    } else {
        return 0;
    }
}

u32 sRender::outputJpg(void* pout) {
    if (mSSState == SS_SUCCESS) {
        memcpy(pout, mJpgBuffer, mJpgBufferSize);
        return mJpgBufferSize;
    } else {
        return 0;
    }
}

bool sRender::endScreenShot() {
    if (mJpgBuffer != nullptr) {
        MtMemory::mpAllocatorType[7]->memFree(mJpgBuffer);
        mJpgBuffer = nullptr;
        mJpgBufferSize = 0;
    }
    mSSState = SS_NONE;
    return true;
}

void sRender::destroyPhotoExport() {
    if (mpExportThread != nullptr) {
        for (PhotoExportThread* v0_4 = mpExportThread;;) {
            if (v0_4->getStatus() == MtThread::TERMINATED) {
                break;
            } else {
                sceKernelUsleep(1000u);
                v0_4 = mpExportThread;
            }
        }
        if (mpExportThread != nullptr) {
            delete mpExportThread;
            mpExportThread = nullptr;
        }
    }
    sceContentExportTerm();
    sceSysmoduleUnloadModule(static_cast<uint16_t>(139));
    sceSysmoduleUnloadModule(static_cast<uint16_t>(166));
}

__attribute__((weak)) void sRender::setPhotoExportTriggerFromMemory(void* pdata, u32 size) {
    DDON_STUB("sRender::setPhotoExportTriggerFromMemory")
    /* stub */
}

sRender::EXPORT_RESULT sRender::photoExportResult() {
    if ((mpExportThread != nullptr) && (mpExportThread->getStatus() != MtThread::TERMINATED)) {
        return EXPORT_PROCESSED;
    }
    return static_cast<EXPORT_RESULT>(mExportParam.success);
}

void sRender::setPhotoExportParam(MT_CTSTR photo_title, MT_CTSTR game_title, MT_CTSTR comment) {
    memset(static_cast<void*>(&mPhotoExportPhotoTitle[0]), 0, 3072ul);
    memcpy(static_cast<void*>(&mPhotoExportPhotoTitle[0]), static_cast<const void*>(photo_title), 1023ul);
    memcpy(static_cast<void*>(&mPhotoExportGameTitle[0]), static_cast<const void*>(game_title), 1023ul);
    memcpy(static_cast<void*>(&mPhotoExportComment[0]), static_cast<const void*>(comment), 1023ul);
}

__attribute__((weak)) void sRender::finishScreenShot() {
    DDON_STUB("sRender::finishScreenShot")
    /* stub */
}

void sRender::setRenderDetailControl(bool b) {
    if (!b) {
        mRenderDetail = 0;
    }
    mRenderDetailControlEnable = b;
}

__attribute__((weak)) void sRender::setShaderStateOptimizeZero(sRender::RENDER_STATE& rs, cDraw::SHADER_STATE* pss) {
    DDON_STUB("sRender::setShaderStateOptimizeZero")
    /* stub */
}

inline sRender::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sRender::MyDTI sRender::DTI("sRender", &::cSystem::DTI, 0x112CCF0ul, 0u, 0u);

sRender* sRender::mpInstance;

s32 sRender::mSSTrigger;

__attribute__((weak)) MtObject* sRender::MyDTI::newInstance() const {
    DDON_STUB("sRender::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void sRender::PhotoExportThread::execute(void* pcontext) {
    DDON_STUB("sRender::PhotoExportThread::execute")
    /* stub */
}

