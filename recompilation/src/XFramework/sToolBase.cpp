// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sToolBase.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtPrimitive2D.h"
#include "cSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sToolBase::getDTI() const {
    return sToolBase::DTI;
}

sToolBase::sToolBase(u32 buf_size) {
    sToolBase::mpInstance = this;
}

sToolBase::~sToolBase() {
    sToolBase::mpInstance = nullptr;
}

inline sToolBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sToolBase::MyDTI sToolBase::DTI("sToolBase", &::cSystem::DTI, 24ul, 0u, 0u);

sToolBase* sToolBase::mpInstance;

__attribute__((weak)) MtObject* sToolBase::MyDTI::newInstance() const {
    DDON_STUB("sToolBase::MyDTI::newInstance")
    return nullptr;
}

