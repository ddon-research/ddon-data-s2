// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cPrimObj.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPrimObj::getDTI() const {
    return cPrimObj::DTI;
}

inline void* cPrimObj::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cPrimObj::DTI)->memAlloc(sz, align, cPrimObj::DTI.mID);
}

inline void cPrimObj::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cPrimObj::DTI)->memFree(p_addr);
}

MtUI* cPrimObj::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cPrimObj::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrimObj::MyDTI cPrimObj::DTI("cPrimObj", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cPrimObj::MyDTI::newInstance() const {
    return new (16u) cPrimObj;
}

