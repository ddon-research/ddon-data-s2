// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uFog.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cResource.h"
#include "cUnit.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "sRender.h"
#include "sScene.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uFog::usage() {
}

const MtDTI& uFog::getDTI() const {
    return uFog::DTI;
}

uFog::uFog() {
    DDON_STUB("uFog::uFog")
    /* stub */
}

__attribute__((noinline)) uFog::~uFog() {
    DDON_STUB("uFog::~uFog")
    /* stub */
}

__attribute__((weak)) void uFog::move() {
    DDON_STUB("uFog::move")
    /* stub */
}

__attribute__((weak)) void uFog::moveAfter() {
    DDON_STUB("uFog::moveAfter")
    /* stub */
}

void uFog::sync() {
    if (mpModel == nullptr) {
        if (mpImplicitSurface != nullptr) {
            if (mpFogFrontDepth == nullptr) {
                mpFogFrontDepth = new (16u) nDraw::Texture(static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh), static_cast<u32>((sRender::mpInstance)->mScreenSize.wh >> 32), 1u, 1u, nDraw::FORMAT_D24_UNORM_S8_UINT, nDraw::USAGE_DEPTHSTENCIL, 130u, static_cast<nDraw::Texture*>(nullptr), 0u, static_cast<void*>(nullptr), nDraw::TEXMEMORY_VRAM);
            }
            if (mUseHighPrecisionModel) {
                if (mpFogBackDepth == nullptr) {
                    mpFogBackDepth = new (16u) nDraw::Texture(static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh), static_cast<u32>((sRender::mpInstance)->mScreenSize.wh >> 32), 1u, 1u, nDraw::FORMAT_D24_UNORM_S8_UINT, nDraw::USAGE_DEPTHSTENCIL, 130u, static_cast<nDraw::Texture*>(nullptr), 0u, static_cast<void*>(nullptr), nDraw::TEXMEMORY_VRAM);
                }
            } else {
                if (mpFogBackDepth != nullptr) {
                    mpFogBackDepth->release();
                    mpFogBackDepth = nullptr;
                    if (mpFogBackDepthSmall != nullptr) {
                        mpFogBackDepthSmall->release();
                        mpFogBackDepthSmall = nullptr;
                    }
                }
            }
        } else {
            if (mpFogFrontDepth != nullptr) {
                mpFogFrontDepth->release();
                mpFogFrontDepth = nullptr;
            }
            if (mpFogBackDepth != nullptr) {
                mpFogBackDepth->release();
                mpFogBackDepth = nullptr;
            }
            if (mpFogFrontDepthSmall != nullptr) {
                mpFogFrontDepthSmall->release();
                mpFogFrontDepthSmall = nullptr;
            }
            if (mpFogBackDepthSmall != nullptr) {
                mpFogBackDepthSmall->release();
                mpFogBackDepthSmall = nullptr;
            }
            if (mpDummy != nullptr) {
                mpDummy->release();
                mpDummy = nullptr;
            }
        }
    } else {
        if (mpFogFrontDepth == nullptr) {
            mpFogFrontDepth = new (16u) nDraw::Texture(static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh), static_cast<u32>((sRender::mpInstance)->mScreenSize.wh >> 32), 1u, 1u, nDraw::FORMAT_D24_UNORM_S8_UINT, nDraw::USAGE_DEPTHSTENCIL, 130u, static_cast<nDraw::Texture*>(nullptr), 0u, static_cast<void*>(nullptr), nDraw::TEXMEMORY_VRAM);
        }
        if (mUseHighPrecisionModel) {
            if (mpFogBackDepth == nullptr) {
                mpFogBackDepth = new (16u) nDraw::Texture(static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh), static_cast<u32>((sRender::mpInstance)->mScreenSize.wh >> 32), 1u, 1u, nDraw::FORMAT_D24_UNORM_S8_UINT, nDraw::USAGE_DEPTHSTENCIL, 130u, static_cast<nDraw::Texture*>(nullptr), 0u, static_cast<void*>(nullptr), nDraw::TEXMEMORY_VRAM);
            }
        } else {
            if (mpFogBackDepth != nullptr) {
                mpFogBackDepth->release();
                mpFogBackDepth = nullptr;
                if (mpFogBackDepthSmall != nullptr) {
                    mpFogBackDepthSmall->release();
                    mpFogBackDepthSmall = nullptr;
                }
            }
        }
    }
}

void uFog::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mRenderType", reinterpret_cast<s32*>(&mRenderType), 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeightType", reinterpret_cast<s32*>(&mHeightType), 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLegacyMode", &mLegacyMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeightStart", &mHeightStart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeightEnd", &mHeightEnd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeightDensity", &mHeightDensity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeightColor", &mHeightColor, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpHeightMap", "resource", static_cast<void*>(&mpHeightMap), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeightSlopeBias", &mHeightSlopeBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUVScale", &mUVScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUVOffset", &mUVOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpImplicitSurface", "resource", static_cast<void*>(&mpImplicitSurface), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpModel", "resource", static_cast<void*>(&mpModel), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScale", &mScale, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuat", &mQuat, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseHighPrecisionModel", &mUseHighPrecisionModel, 0u, 0u);
}

MtUI* uFog::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

u64 uFog::getSystemUnitGroup() const {
    return 8;
}

bool uFog::isValidDrawBySystem() const {
    return true;
}

void uFog::getDrawUnitState(u32& type, u32& priority) const {
    type = 5;
    priority = 0;
}

__attribute__((weak)) void uFog::copyRegion(cDraw* pdraw, const MtRect& dst_rect, const MtRect& src_rect, const MtSize& src_size) {
    DDON_STUB("uFog::copyRegion")
    /* stub */
}

__attribute__((weak)) void uFog::drawDepth(cDraw* pdraw) {
    DDON_STUB("uFog::drawDepth")
    /* stub */
}

__attribute__((weak)) void uFog::drawModel(cDraw* pdraw) {
    DDON_STUB("uFog::drawModel")
    /* stub */
}

__attribute__((weak)) void uFog::drawImplicitSurface(cDraw* pdraw) {
    DDON_STUB("uFog::drawImplicitSurface")
    /* stub */
}

inline uFog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFog::MyDTI uFog::DTI("uFog", &::cUnit::DTI, 448ul, 0u, 1u);

MtObject* uFog::MyDTI::newInstance() const {
    return nullptr;
}

