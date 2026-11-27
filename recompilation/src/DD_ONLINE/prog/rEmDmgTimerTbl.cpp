// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmDmgTimerTbl.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmDmgTimerTbl::getDTI() const {
    return cEmDmgTimerTbl::DTI;
}

inline cEmDmgTimerTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmDmgTimerTbl::MyDTI cEmDmgTimerTbl::DTI("cEmDmgTimerTbl", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cEmDmgTimerTbl::MyDTI::newInstance() const {
    return new (16u) cEmDmgTimerTbl;
}

const MtDTI& rEmDmgTimerTbl::getDTI() const {
    return rEmDmgTimerTbl::DTI;
}

bool rEmDmgTimerTbl::loadData(MtDataReader& r, cEmDmgTimerTbl* pData) {
    nDDOIO::readData(r, pData->mType);
    nDDOIO::readData(r, pData->mTimer);
    return true;
}

MT_CTSTR rEmDmgTimerTbl::getExt() const {
    return "dtt";
}

u32 rEmDmgTimerTbl::getDataVersion() const {
    return 2;
}

inline rEmDmgTimerTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmDmgTimerTbl::MyDTI rEmDmgTimerTbl::DTI("rEmDmgTimerTbl", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEmDmgTimerTbl::MyDTI::newInstance() const {
    return new (16u) rEmDmgTimerTbl;
}

template cEmDmgTimerTbl* rTbl2<cEmDmgTimerTbl>::getData(unsigned int);

template bool rTbl2<cEmDmgTimerTbl>::load(MtStream&);

template bool rTbl2<cEmDmgTimerTbl>::loadCore(MtDataReader&);

template const cEmDmgTimerTbl* rTbl2<cEmDmgTimerTbl>::getData(unsigned int) const;

template unsigned int rTbl2<cEmDmgTimerTbl>::getDataNum() const;

template rTbl2<cEmDmgTimerTbl>::~rTbl2();

