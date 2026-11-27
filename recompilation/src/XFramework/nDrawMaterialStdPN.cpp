// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDrawMaterialStdPN.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "nDrawMaterial.h"
#include "nDrawMaterialStd.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void nDraw::MaterialStdPN::usage() {
}

const MtDTI& nDraw::MaterialStdPN::getDTI() const {
    return nDraw::MaterialStdPN::DTI;
}

void nDraw::MaterialStdPN::createProperty(MtPropertyList& s) {
    this->::nDraw::Material::createProperty(s);
}

MtUI* nDraw::MaterialStdPN::createUI(MtProperty& prop) {
    return this->::nDraw::Material::createUI(prop);
}

nDraw::MaterialStdPN::~MaterialStdPN() {
}

inline nDraw::MaterialStdPN::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::MaterialStdPN::MyDTI nDraw::MaterialStdPN::DTI("nDraw::MaterialStdPN", &::nDraw::MaterialStd::DTI, 208ul, 0u, 0u);

MtObject* nDraw::MaterialStdPN::MyDTI::newInstance() const {
    return new (16u) ::nDraw::MaterialStdPN;
}

