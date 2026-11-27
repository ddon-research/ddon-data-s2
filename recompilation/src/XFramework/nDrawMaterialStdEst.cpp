// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDrawMaterialStdEst.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "nDrawMaterial.h"
#include "nDrawMaterialStd.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void nDraw::MaterialStdEst::usage() {
}

const MtDTI& nDraw::MaterialStdEst::getDTI() const {
    return nDraw::MaterialStdEst::DTI;
}

nDraw::MaterialStdEst::MaterialStdEst() {
    mTechnique = 0xC111EB29;
}

void nDraw::MaterialStdEst::createProperty(MtPropertyList& s) {
    this->::nDraw::Material::createProperty(s);
}

MtUI* nDraw::MaterialStdEst::createUI(MtProperty& prop) {
    return this->::nDraw::Material::createUI(prop);
}

nDraw::MaterialStdEst::~MaterialStdEst() {
}

inline nDraw::MaterialStdEst::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::MaterialStdEst::MyDTI nDraw::MaterialStdEst::DTI("nDraw::MaterialStdEst", &::nDraw::MaterialStd::DTI, 208ul, 0u, 0u);

MtObject* nDraw::MaterialStdEst::MyDTI::newInstance() const {
    return new (16u) ::nDraw::MaterialStdEst;
}

