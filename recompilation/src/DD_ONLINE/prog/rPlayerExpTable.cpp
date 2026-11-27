// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPlayerExpTable.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPlayerExpTable::getDTI() const {
    return cPlayerExpTable::DTI;
}

void cPlayerExpTable::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "必要経験値", &mNeedExp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "得られる職業ポイント", &mGainJobPoint, 0u, 0u);
}

inline cPlayerExpTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPlayerExpTable::MyDTI cPlayerExpTable::DTI("cPlayerExpTable", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cPlayerExpTable::MyDTI::newInstance() const {
    return new (16u) cPlayerExpTable;
}

const MtDTI& rPlayerExpTable::getDTI() const {
    return rPlayerExpTable::DTI;
}

bool rPlayerExpTable::loadData(MtDataReader& in, cPlayerExpTable* pData) {
    nDDOIO::readData(in, pData->mNeedExp);
    nDDOIO::readData(in, pData->mGainJobPoint);
    return true;
}

MT_CTSTR rPlayerExpTable::getExt() const {
    return "exp";
}

u32 rPlayerExpTable::getDataVersion() const {
    return 2;
}

void rPlayerExpTable::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

inline rPlayerExpTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPlayerExpTable::MyDTI rPlayerExpTable::DTI("rPlayerExpTable", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rPlayerExpTable::MyDTI::newInstance() const {
    return new (16u) rPlayerExpTable;
}

template cPlayerExpTable* rTbl2<cPlayerExpTable>::getData(unsigned int);

template bool rTbl2<cPlayerExpTable>::load(MtStream&);

template bool rTbl2<cPlayerExpTable>::loadCore(MtDataReader&);

template const cPlayerExpTable* rTbl2<cPlayerExpTable>::getData(unsigned int) const;

template unsigned int rTbl2<cPlayerExpTable>::getDataNum() const;

template rTbl2<cPlayerExpTable>::~rTbl2();

