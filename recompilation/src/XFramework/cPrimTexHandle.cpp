// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cPrimTexHandle.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "cPrimObj.h"
#include "sPrimitive.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPrimTexHandle::getDTI() const {
    return cPrimTexHandle::DTI;
}

cPrimTexHandle::cPrimTexHandle() {
    mCurrentIdx = 0;
    mTextureNum = 0;
    mTextureSize = 0;
    mpTexture = nullptr;
}

cPrimTexHandle::~cPrimTexHandle() {
}

__attribute__((weak)) u32 cPrimTexHandle::registerTexHandle(const nPrim::Texture& tex) {
    DDON_STUB("cPrimTexHandle::registerTexHandle")
    return {};
}

void cPrimTexHandle::reserveTexture() {
    mTextureSize = (sPrimitive::mpInstance)->sPrimitive::reserveTex(&mpTexture, &mCurrentIdx, 64u);
    mTextureNum = 0;
}

inline cPrimTexHandle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrimTexHandle::MyDTI cPrimTexHandle::DTI("cPrimTexHandle", &::cPrimObj::DTI, 32ul, 0u, 0u);

MtObject* cPrimTexHandle::MyDTI::newInstance() const {
    return new (16u) cPrimTexHandle;
}

