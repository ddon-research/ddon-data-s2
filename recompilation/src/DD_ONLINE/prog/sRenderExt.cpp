// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sRenderExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/nDrawScene.h"
#include "../../XFramework/sApp.h"
#include "../../XFramework/sRender.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sRenderExt::getDTI() const {
    return sRenderExt::DTI;
}

void* sRenderExt::operator new(size_t sz, u32 align) {
    return sRenderExt::getAllocator()->memAlloc(sz, align, sRenderExt::DTI.getID());
}

sRenderExt::~sRenderExt() {
}

void sRenderExt::createProperty(MtPropertyList& s) {
    this->sRender::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsEnablePrioAttrExpand", &mIsEnablePrioAttrExpand, 0u, 0u);
}

void sRenderExt::move() {
    this->sRender::move();
}

__attribute__((weak)) void sRenderExt::rsxSyncBackEnd(cDraw* pDraw) {
}

bool sRenderExt::isEnablePrioAttrExpand() {
    return mIsEnablePrioAttrExpand;
}

void sRenderExt::setupEnablePrioAttrExpand() {
    mIsEnablePrioAttrExpand = true;
}

bool sRenderExt::isPossibleDrawFromDrawBuffer() {
    return true;
}

inline sRenderExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sRenderExt::MyDTI sRenderExt::DTI("sRenderExt", &::sRender::DTI, 0x112CCF8ul, 0u, 0u);

__attribute__((weak)) MtObject* sRenderExt::MyDTI::newInstance() const {
    DDON_STUB("sRenderExt::MyDTI::newInstance")
    return nullptr;
}

