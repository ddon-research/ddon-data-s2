// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cBlendState.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cBlendState::getDTI() const {
    return cBlendState::DTI;
}

cBlendState::cBlendState() {
    DDON_STUB("cBlendState::cBlendState")
    /* stub */
}

cBlendState::~cBlendState() {
}

inline cBlendState::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cBlendState::MyDTI cBlendState::DTI("cBlendState", &::MtObject::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* cBlendState::MyDTI::newInstance() const {
    DDON_STUB("cBlendState::MyDTI::newInstance")
    return nullptr;
}

