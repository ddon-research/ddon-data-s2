// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cAreaExt.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cArea.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAreaExt::getDTI() const {
    return cAreaExt::DTI;
}

cAreaExt::cAreaExt() {
}

__attribute__((weak)) void cAreaExt::init() {
}

void cAreaExt::final() {
    this->cArea::final();
}

inline cAreaExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAreaExt::MyDTI cAreaExt::DTI("cAreaExt", &::cArea::DTI, 48ul, 0u, 0u);

MtObject* cAreaExt::MyDTI::newInstance() const {
    return new (16u) cAreaExt;
}

