// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uScreenSpace.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cPrim.h"
#include "cPrimTexHandle.h"
#include "cResource.h"
#include "cUnit.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "nPrim.h"
#include "rRenderTargetTexture.h"
#include "sPrimitive.h"
#include "sRender.h"
#include "sUnit.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uScreenSpace::usage() {
}

const MtDTI& uScreenSpace::getDTI() const {
    return uScreenSpace::DTI;
}

void* uScreenSpace::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uScreenSpace::DTI)->memAlloc(sz, align, uScreenSpace::DTI.mID);
}

uScreenSpace::~uScreenSpace() {
    DDON_STUB("uScreenSpace::~uScreenSpace")
    /* stub */
}

void uScreenSpace::setup() {
    if (mpRenderTarget == nullptr) {
        if (mpColorTarget == nullptr) {
            createTexture(mTextureSize);
        }
    }
    this->cUnit::setup();
}

__attribute__((weak)) void uScreenSpace::draw(cDraw* p_draw) {
    DDON_STUB("uScreenSpace::draw")
    /* stub */
}

MtUI* uScreenSpace::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uScreenSpace::createProperty(MtPropertyList& prop_list) {
    this->cUnit::createProperty(prop_list);
    prop_list << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mTextureSize", reinterpret_cast<MT_MFUNC>(&::uScreenSpace::getTextureSize), reinterpret_cast<MT_MFUNC>(&::uScreenSpace::setTextureSize), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    prop_list << MtProperty(static_cast<MtObject*>(this), "mpCamera", reinterpret_cast<MtObject* *>(&mpCamera), 16u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mCameraPos", &mCameraPos, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mCameraUp", &mCameraUp, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mCameraTarget", &mCameraTarget, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mNearPlane", &mNearPlane, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mFarPlane", &mFarPlane, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mFOV", &mFOV, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mSceneDrawMode", &mSceneDrawMode, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mSceneView", &mSceneView, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mClearColor", &mClearColor, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mDepthToAlpha", &mDepthToAlpha, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mFXAA", &mFXAA, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mDistortionEnabled", reinterpret_cast<MT_MFUNC>(&::uScreenSpace::isDistortionEnabled), reinterpret_cast<MT_MFUNC>(&::uScreenSpace::setDistortionEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    prop_list << MtProperty(static_cast<MtObject*>(this), "mpColorTarget", reinterpret_cast<MtObject* *>(&mpColorTarget), 3u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mpDistortionTex", reinterpret_cast<MtObject* *>(&mpDistortionTex), 3u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mpRenderTarget", "resource", reinterpret_cast<MT_MFUNC>(&::uScreenSpace::getRenderTarget), reinterpret_cast<MT_MFUNC>(&::uScreenSpace::setRenderTarget), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    prop_list << MtProperty(static_cast<MtObject*>(this), "mPass", &mPass, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mLayer", &mLayer, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mDraw2D", &mDraw2D, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mAttribute", &mAttribute, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mDepth", &mDepth, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mPointTable", static_cast<MtObject*>(&mPointTable), 0u, 0u);
}

static auto ddon_emit_0x01b63d60 __attribute__((used)) = &uScreenSpace::setTextureSize;

static auto ddon_emit_0x01b63d50 __attribute__((used)) = &uScreenSpace::getTextureSize;

static auto ddon_emit_0x01b63d90 __attribute__((used)) = &uScreenSpace::getRenderTarget;

void uScreenSpace::setRenderTarget(rRenderTargetTexture* p_rt) {
    if (mpRenderTarget != nullptr) {
        mpRenderTarget->release();
        mpRenderTarget = nullptr;
        if (p_rt != nullptr) {
            releaseTexture();
            mpRenderTarget = p_rt;
            p_rt->addRef();
            createDepth(mpRenderTarget);
        } else {
            mpRenderTarget = nullptr;
            createTexture(mTextureSize);
        }
    } else {
        if (p_rt != nullptr) {
            releaseTexture();
            mpRenderTarget = p_rt;
            p_rt->addRef();
            createDepth(mpRenderTarget);
        } else {
            mpRenderTarget = nullptr;
        }
    }
}

static auto ddon_emit_0x01b63d80 __attribute__((used)) = &uScreenSpace::isDistortionEnabled;

void uScreenSpace::setDistortionEnable(bool enable) {
    static const u32 size[6] = {
        128,
        256,
        512,
        1024,
        2048,
        0,
    };
    if (mDistortionEnabled != enable) {
        mDistortionEnabled = enable;
        createDistortion(size[mTextureSize], size[mTextureSize]);
    }
}

__attribute__((weak)) s32 uScreenSpace::createTexture(u32 sz) {
    DDON_STUB("uScreenSpace::createTexture")
    return {};
}

s32 uScreenSpace::releaseTexture() {
    if (mpColorTarget != nullptr) {
        mpColorTarget->release();
        mpColorTarget = nullptr;
    }
    if (mpDepthTarget != nullptr) {
        mpDepthTarget->release();
        mpDepthTarget = nullptr;
    }
    if (mpTempColorTarget != nullptr) {
        mpTempColorTarget->release();
        mpTempColorTarget = nullptr;
    }
    if (mpDistortionTex != nullptr) {
        mpDistortionTex->release();
        mpDistortionTex = nullptr;
    }
    return 0;
}

__attribute__((weak)) s32 uScreenSpace::createDepth(rRenderTargetTexture* p_rt) {
    DDON_STUB("uScreenSpace::createDepth")
    return {};
}

__attribute__((weak)) void uScreenSpace::drawUnit(cDraw* p_draw) {
    DDON_STUB("uScreenSpace::drawUnit")
    /* stub */
}

__attribute__((weak)) s32 uScreenSpace::drawScene(cDraw* p_draw, nDraw::Texture* p_rt, nDraw::Texture* p_ds) {
    DDON_STUB("uScreenSpace::drawScene")
    return {};
}

__attribute__((weak)) void uScreenSpace::createDistortion(u32 width, u32 height) {
    DDON_STUB("uScreenSpace::createDistortion")
    /* stub */
}

inline uScreenSpace::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uScreenSpace::MyDTI uScreenSpace::DTI("uScreenSpace", &::cUnit::DTI, 672ul, 0u, 0u);

__attribute__((weak)) MtObject* uScreenSpace::MyDTI::newInstance() const {
    DDON_STUB("uScreenSpace::MyDTI::newInstance")
    return nullptr;
}

