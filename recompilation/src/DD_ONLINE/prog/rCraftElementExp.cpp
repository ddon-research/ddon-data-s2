// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCraftElementExp.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCraftElementExpData::getDTI() const {
    return cCraftElementExpData::DTI;
}

void cCraftElementExpData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mExp", &mExp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPrice", &mPrice, 0u, 0u);
}

inline cCraftElementExpData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCraftElementExpData::MyDTI cCraftElementExpData::DTI("cCraftElementExpData", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cCraftElementExpData::MyDTI::newInstance() const {
    return new (16u) cCraftElementExpData;
}

const MtDTI& rCraftElementExp::getDTI() const {
    return rCraftElementExp::DTI;
}

bool rCraftElementExp::loadData(MtDataReader& in, cCraftElementExpData* pData) {
    nDDOIO::readData(in, pData->mExp);
    nDDOIO::readData(in, pData->mPrice);
    return true;
}

MT_CTSTR rCraftElementExp::getExt() const {
    return "cee";
}

u32 rCraftElementExp::getDataVersion() const {
    return 1;
}

inline rCraftElementExp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCraftElementExp::MyDTI rCraftElementExp::DTI("rCraftElementExp", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCraftElementExp::MyDTI::newInstance() const {
    return new (16u) rCraftElementExp;
}

template cCraftElementExpData* rTbl2<cCraftElementExpData>::getData(unsigned int);

template bool rTbl2<cCraftElementExpData>::load(MtStream&);

template bool rTbl2<cCraftElementExpData>::loadCore(MtDataReader&);

template const cCraftElementExpData* rTbl2<cCraftElementExpData>::getData(unsigned int) const;

template unsigned int rTbl2<cCraftElementExpData>::getDataNum() const;

template rTbl2<cCraftElementExpData>::~rTbl2();

