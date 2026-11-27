// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cOcdGoodStatus.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cOcdBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOcdGoodStatusBase::getDTI() const {
    return cOcdGoodStatusBase::DTI;
}

void cOcdGoodStatusBase::init(bool initFlag) {
    this->cOcdBase::init(initFlag);
}

void cOcdGoodStatusBase::final() {
    this->cOcdBase::final();
}

inline cOcdGoodStatusBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOcdGoodStatusBase::MyDTI cOcdGoodStatusBase::DTI("cOcdGoodStatusBase", &::cOcdBase::DTI, 480ul, 0u, 0u);

MtObject* cOcdGoodStatusBase::MyDTI::newInstance() const {
    return new (16u) cOcdGoodStatusBase;
}

