// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDrawMaterialNull.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "nDrawMaterial.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nDraw::MaterialNull::getDTI() const {
    return nDraw::MaterialNull::DTI;
}

void* nDraw::MaterialNull::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nDraw::MaterialNull::DTI)->memAlloc(sz, align, ::nDraw::MaterialNull::DTI.mID);
}

nDraw::MaterialNull::MaterialNull() : nDraw::Material(0x4AF70B19u) {
}

void nDraw::MaterialNull::createProperty(MtPropertyList& s) {
    this->::nDraw::Material::createProperty(s);
}

MtUI* nDraw::MaterialNull::createUI(MtProperty& prop) {
    return this->::nDraw::Material::createUI(prop);
}

nDraw::MaterialNull::~MaterialNull() {
}

__attribute__((weak)) void nDraw::MaterialNull::setState(cDraw* pdraw) {
    DDON_STUB("nDraw::MaterialNull::setState")
    /* stub */
}

inline nDraw::MaterialNull::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::MaterialNull::MyDTI nDraw::MaterialNull::DTI("nDraw::MaterialNull", &::nDraw::Material::DTI, 208ul, 0u, 0u);

MtObject* nDraw::MaterialNull::MyDTI::newInstance() const {
    return new (16u) ::nDraw::MaterialNull;
}

