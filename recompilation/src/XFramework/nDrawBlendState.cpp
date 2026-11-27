// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDrawBlendState.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "nDrawResource.h"
#include "../generated/shared/regs.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nDraw::BlendState::getDTI() const {
    return nDraw::BlendState::DTI;
}

void* nDraw::BlendState::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nDraw::BlendState::DTI)->memAlloc(sz, align, ::nDraw::BlendState::DTI.mID);
}

nDraw::BlendState::BlendState(const nDraw::BLEND_DESC* pdesc) {
    DDON_STUB("nDraw::BlendState::BlendState")
    /* stub */
}

nDraw::BlendState::~BlendState() {
}

inline nDraw::BlendState::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::BlendState::MyDTI nDraw::BlendState::DTI("nDraw::BlendState", &::nDraw::Resource::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::BlendState::MyDTI::newInstance() const {
    DDON_STUB("nDraw::BlendState::MyDTI::newInstance")
    return nullptr;
}

