// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cEfcHandle.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEfcHandle::getDTI() const {
    return cEfcHandle::DTI;
}

void* cEfcHandle::operator new(size_t sz, u32 align) {
    return cEfcHandle::getAllocator()->memAlloc(sz, align, cEfcHandle::DTI.getID());
}

inline cEfcHandle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEfcHandle::MyDTI cEfcHandle::DTI("cEfcHandle", &::MtObject::DTI, 136ul, 0u, 0u);

MtObject* cEfcHandle::MyDTI::newInstance() const {
    return new (16u) cEfcHandle;
}

