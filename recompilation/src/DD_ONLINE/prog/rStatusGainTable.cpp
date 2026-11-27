// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rStatusGainTable.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cStatusGain::getDTI() const {
    return cStatusGain::DTI;
}

void cStatusGain::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "必要オーブ数", &mRequiedDogma, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "上昇差分", &mUpStatusValue, 0u, 0u);
}

inline cStatusGain::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStatusGain::MyDTI cStatusGain::DTI("cStatusGain", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cStatusGain::MyDTI::newInstance() const {
    return new (16u) cStatusGain;
}

const MtDTI& rStatusGainTable::getDTI() const {
    return rStatusGainTable::DTI;
}

bool rStatusGainTable::loadData(MtDataReader& in, cStatusGain* pData) {
    nDDOIO::readData(in, pData->mRequiedDogma);
    nDDOIO::readData(in, pData->mUpStatusValue);
    return true;
}

MT_CTSTR rStatusGainTable::getExt() const {
    return "sg_tbl";
}

u32 rStatusGainTable::getDataVersion() const {
    return 257;
}

inline rStatusGainTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStatusGainTable::MyDTI rStatusGainTable::DTI("rStatusGainTable", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rStatusGainTable::MyDTI::newInstance() const {
    return new (16u) rStatusGainTable;
}

template cStatusGain* rTbl2<cStatusGain>::getData(unsigned int);

template bool rTbl2<cStatusGain>::load(MtStream&);

template bool rTbl2<cStatusGain>::loadCore(MtDataReader&);

template const cStatusGain* rTbl2<cStatusGain>::getData(unsigned int) const;

template unsigned int rTbl2<cStatusGain>::getDataNum() const;

template rTbl2<cStatusGain>::~rTbl2();

