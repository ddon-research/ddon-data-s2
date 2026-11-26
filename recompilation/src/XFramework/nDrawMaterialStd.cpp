// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDrawMaterialStd.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cDraw.h"
#include "nDraw.h"
#include "nDrawMaterial.h"
#include "nDrawResource.h"
#include "nDrawScene.h"
#include "sRender.h"
#include "sScene.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void nDraw::MaterialStd::usage() {
}

const MtDTI& nDraw::MaterialStd::getDTI() const {
    return nDraw::MaterialStd::DTI;
}

inline void* nDraw::MaterialStd::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nDraw::MaterialStd::DTI)->memAlloc(sz, align, ::nDraw::MaterialStd::DTI.mID);
}

inline void nDraw::MaterialStd::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nDraw::MaterialStd::DTI)->memFree(p_addr);
}

nDraw::MaterialStd::MaterialStd() : nDraw::Material(0x25FCFB26u) {
}

void nDraw::MaterialStd::createProperty(MtPropertyList& s) {
    this->::nDraw::Material::createProperty(s);
}

MtUI* nDraw::MaterialStd::createUI(MtProperty& prop) {
    return this->::nDraw::Material::createUI(prop);
}

u32 nDraw::MaterialStd::setDrawState(cDraw* pdraw, nDraw::PASS_TYPE overrideDrawPass) {
    u32 pass_num = this->::nDraw::Material::setDrawState(pdraw, overrideDrawPass);
    if (pass_num != 0) {
        u32 t0 = setDeferredLightingState(pdraw, pass_num);
        if ((mTangent & 1u) != 0) {
            if ((((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pdraw) + 560)) & 30ul) ^ 12ul) == 0) {
                if ((::sRender::mpInstance)->mTangentRendering) {
                    nDraw::Scene* scene = pdraw->mContext.pscene;
                    if (scene != nullptr) {
                        return t0 + ((scene->mAttributes >> 20) & 1u);
                    } else {
                        return t0;
                    }
                } else {
                    return t0;
                }
            } else {
                return t0;
            }
        } else {
            return t0;
        }
    } else {
        if ((((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pdraw) + 560)) & 0x400000000000001Eul) ^ 0x400000000000000Cul) == 0) {
            (::sScene::mpInstance)->::sScene::setFogState(pdraw, 0u);
            setTechniqueState(pdraw, 3u);
            return 1;
        } else {
            return 0;
        }
    }
}

__attribute__((weak)) bool nDraw::MaterialStd::beginDraw(cDraw* pdraw, u32 pass) {
    DDON_STUB("nDraw::MaterialStd::beginDraw")
    return {};
}

__attribute__((weak)) void nDraw::MaterialStd::endDraw(cDraw* pdraw, u32 pass) {
    DDON_STUB("nDraw::MaterialStd::endDraw")
    /* stub */
}

nDraw::MaterialStd::~MaterialStd() {
}

__attribute__((weak)) u32 nDraw::MaterialStd::setDeferredLightingState(cDraw* pdraw, u32 pass) {
    DDON_STUB("nDraw::MaterialStd::setDeferredLightingState")
    return {};
}

inline nDraw::MaterialStd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::MaterialStd::MyDTI nDraw::MaterialStd::DTI("nDraw::MaterialStd", &::nDraw::Material::DTI, 208ul, 0u, 0u);

MtObject* nDraw::MaterialStd::MyDTI::newInstance() const {
    return new (16u) ::nDraw::MaterialStd;
}

