// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGeometry2Base.h"
#include "../MT/MtDTI.h"
#include "cUnit.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGeometry2Base::getDTI() const {
    return uGeometry2Base::DTI;
}

uGeometry2Base::uGeometry2Base() {
}

uGeometry2Base::~uGeometry2Base() {
}

inline uGeometry2Base::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGeometry2Base::MyDTI uGeometry2Base::DTI("uGeometry2Base", &::cUnit::DTI, 72ul, 0u, 1u);

MtObject* uGeometry2Base::MyDTI::newInstance() const {
    return nullptr;
}

