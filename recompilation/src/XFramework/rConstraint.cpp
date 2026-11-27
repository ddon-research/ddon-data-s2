// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rConstraint.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "uConstraint.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rConstraint::getDTI() const {
    return rConstraint::DTI;
}

rConstraint::rConstraint() {
    mID = 0;
    mPri = 1000;
}

void rConstraint::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPri", &(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 116)), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mID", &(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 112)), 0u, 0u);
}

void rConstraint::copyUnitProperty(uConstraint* pSrcUnit) {
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 116) = pSrcUnit->mPri;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 112) = pSrcUnit->mID;
}

inline rConstraint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rConstraint::MyDTI rConstraint::DTI("rConstraint", &::cResource::DTI, 120ul, 0u, 1u);

MtObject* rConstraint::MyDTI::newInstance() const {
    return nullptr;
}

