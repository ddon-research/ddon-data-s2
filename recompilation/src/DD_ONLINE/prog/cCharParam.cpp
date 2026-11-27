// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCharParam.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCharParam::getDTI() const {
    return cCharParam::DTI;
}

cCharParam::cCharParam() {
    mVersion = 48;
}

__attribute__((weak)) void cCharParam::createProperty(MtPropertyList& s) {
}

MtUI* cCharParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cCharParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCharParam::MyDTI cCharParam::DTI("cCharParam", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCharParam::MyDTI::newInstance() const {
    return new (16u) cCharParam;
}

