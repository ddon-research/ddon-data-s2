// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDrawScene.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "nDraw.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "sRender.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nDraw::Scene::getDTI() const {
    return nDraw::Scene::DTI;
}

void* nDraw::Scene::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nDraw::Scene::DTI)->memAlloc(sz, align, ::nDraw::Scene::DTI.mID);
}

inline void nDraw::Scene::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nDraw::Scene::DTI)->memFree(p_addr);
}

nDraw::Scene::Scene(nDraw::SCENE_DESC desc) {
    DDON_STUB("nDraw::Scene::Scene")
    /* stub */
}

void nDraw::Scene::createProperty(MtPropertyList& s) {
    this->::nDraw::Resource::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpRTPostTarget", reinterpret_cast<MtObject* *>(&mpRTPostTarget), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpRTMainTarget", reinterpret_cast<MtObject* *>(&mpRTMainTarget), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpPostTarget", reinterpret_cast<MtObject* *>(&mpPostTarget), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpMainTarget", reinterpret_cast<MtObject* *>(&mpMainTarget), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpHDRTarget", reinterpret_cast<MtObject* *>(&mpHDRTarget), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpLightMask", reinterpret_cast<MtObject* *>(&mpLightMask), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpAmbientMask", reinterpret_cast<MtObject* *>(&mpAmbientMask), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpDepthStencilRO", reinterpret_cast<MtObject* *>(&mpDepthStencilRO), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpStencil", reinterpret_cast<MtObject* *>(&mpStencil), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpBlendTarget", reinterpret_cast<MtObject* *>(&mpBlendTarget), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpMainTargetReduction", reinterpret_cast<MtObject* *>(&mpMainTargetReduction), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpGBuffer", reinterpret_cast<MtObject* *>(&mpGBuffer), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpLightAccumulation0", reinterpret_cast<MtObject* *>(&mpLightAccumulation0), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpLightAccumulation1", reinterpret_cast<MtObject* *>(&mpLightAccumulation1), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpGBufferTrans", reinterpret_cast<MtObject* *>(&mpGBufferTrans), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpDSFBufferTrans", reinterpret_cast<MtObject* *>(&mpDSFBufferTrans), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpLightAccumulationTrans0", reinterpret_cast<MtObject* *>(&mpLightAccumulationTrans0), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpLightAccumulationTrans1", reinterpret_cast<MtObject* *>(&mpLightAccumulationTrans1), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpTempDistortionTex", reinterpret_cast<MtObject* *>(&mpTempDistortionTex), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpBackFaceDepthStencil", reinterpret_cast<MtObject* *>(&mpBackFaceDepthStencil), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpTanBuffer", reinterpret_cast<MtObject* *>(&mpTanBuffer), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mClearColor", &mClearColor, 2u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mHDREmphasis", &mHDREmphasis, 0u, 0u);
}

MtUI* nDraw::Scene::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((noinline)) nDraw::Scene::~Scene() {
    if (mpDepthStencil != nullptr) {
        mpDepthStencil->release();
        mpDepthStencil = nullptr;
    }
    if (mpDepthStencilRO != nullptr) {
        mpDepthStencilRO->release();
        mpDepthStencilRO = nullptr;
    }
    if (mpRTDepthStencil != nullptr) {
        mpRTDepthStencil->release();
        mpRTDepthStencil = nullptr;
    }
    if (mpStencil != nullptr) {
        mpStencil->release();
        mpStencil = nullptr;
    }
    if (mpDepth != nullptr) {
        mpDepth->release();
        mpDepth = nullptr;
    }
    if (mpDepthStencilReduction != nullptr) {
        mpDepthStencilReduction->release();
        mpDepthStencilReduction = nullptr;
    }
    if (mpRTPostTarget != nullptr) {
        mpRTPostTarget->release();
        mpRTPostTarget = nullptr;
    }
    if (mpRTMainTarget != nullptr) {
        mpRTMainTarget->release();
        mpRTMainTarget = nullptr;
    }
    if (mpMainTargetReduction != nullptr) {
        mpMainTargetReduction->release();
        mpMainTargetReduction = nullptr;
    }
    if (mpPostTarget != nullptr) {
        mpPostTarget->release();
        mpPostTarget = nullptr;
    }
    if (mpMainTarget != nullptr) {
        mpMainTarget->release();
        mpMainTarget = nullptr;
    }
    if (mpHDRTarget != nullptr) {
        mpHDRTarget->release();
        mpHDRTarget = nullptr;
    }
    if (mpHDRQTarget != nullptr) {
        mpHDRQTarget->release();
        mpHDRQTarget = nullptr;
    }
    if (mpLightMask != nullptr) {
        mpLightMask->release();
        mpLightMask = nullptr;
    }
    if (mpAmbientMask != nullptr) {
        mpAmbientMask->release();
        mpAmbientMask = nullptr;
    }
    if (mpBlendTarget != nullptr) {
        mpBlendTarget->release();
        mpBlendTarget = nullptr;
    }
    if (mpGBuffer != nullptr) {
        mpGBuffer->release();
        mpGBuffer = nullptr;
    }
    if (mpLightAccumulation0 != nullptr) {
        mpLightAccumulation0->release();
        mpLightAccumulation0 = nullptr;
    }
    if (mpLightAccumulation1 != nullptr) {
        mpLightAccumulation1->release();
        mpLightAccumulation1 = nullptr;
    }
    if (mpLightAccumulationTexture != nullptr) {
        mpLightAccumulationTexture->release();
        mpLightAccumulationTexture = nullptr;
    }
    if (mpGBufferTrans != nullptr) {
        mpGBufferTrans->release();
        mpGBufferTrans = nullptr;
    }
    if (mpDSFBufferTrans != nullptr) {
        mpDSFBufferTrans->release();
        mpDSFBufferTrans = nullptr;
    }
    if (mpLightAccumulationTrans0 != nullptr) {
        mpLightAccumulationTrans0->release();
        mpLightAccumulationTrans0 = nullptr;
    }
    if (mpLightAccumulationTrans1 != nullptr) {
        mpLightAccumulationTrans1->release();
        mpLightAccumulationTrans1 = nullptr;
    }
    if (mpLightAccumulationTransTexture != nullptr) {
        mpLightAccumulationTransTexture->release();
        mpLightAccumulationTransTexture = nullptr;
    }
    if (mpDepthStencilTrans != nullptr) {
        mpDepthStencilTrans->release();
        mpDepthStencilTrans = nullptr;
    }
    if (mpTanBuffer != nullptr) {
        mpTanBuffer->release();
        mpTanBuffer = nullptr;
    }
    if (mpZPrepassDummy != nullptr) {
        mpZPrepassDummy->release();
        mpZPrepassDummy = nullptr;
    }
    if (mpBackFaceDepthStencil != nullptr) {
        mpBackFaceDepthStencil->release();
        mpBackFaceDepthStencil = nullptr;
    }
    if (mpTempDistortionTex != nullptr) {
        mpTempDistortionTex->release();
        mpTempDistortionTex = nullptr;
    }
}

__attribute__((weak)) void nDraw::Scene::getLightAccumulationFormat(nDraw::FORMAT_TYPE& format, u32& miscFlags) {
    DDON_STUB("nDraw::Scene::getLightAccumulationFormat")
    /* stub */
}

inline nDraw::Scene::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::Scene::MyDTI nDraw::Scene::DTI("nDraw::Scene", &::nDraw::Resource::DTI, 1552ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::Scene::MyDTI::newInstance() const {
    DDON_STUB("nDraw::Scene::MyDTI::newInstance")
    return nullptr;
}

