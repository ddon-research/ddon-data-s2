// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCraftUpGradeExp.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCraftUpGradeExpData::getDTI() const {
    return cCraftUpGradeExpData::DTI;
}

void cCraftUpGradeExpData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mExpMax", &mExpMax, 0u, 0u);
}

inline cCraftUpGradeExpData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCraftUpGradeExpData::MyDTI cCraftUpGradeExpData::DTI("cCraftUpGradeExpData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCraftUpGradeExpData::MyDTI::newInstance() const {
    return new (16u) cCraftUpGradeExpData;
}

const MtDTI& rCraftUpGradeExp::getDTI() const {
    return rCraftUpGradeExp::DTI;
}

bool rCraftUpGradeExp::loadData(MtDataReader& in, cCraftUpGradeExpData* pData) {
    nDDOIO::readData(in, pData->mExpMax);
    return true;
}

MT_CTSTR rCraftUpGradeExp::getExt() const {
    return "cuex";
}

u32 rCraftUpGradeExp::getDataVersion() const {
    return 1;
}

inline rCraftUpGradeExp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCraftUpGradeExp::MyDTI rCraftUpGradeExp::DTI("rCraftUpGradeExp", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCraftUpGradeExp::MyDTI::newInstance() const {
    return new (16u) rCraftUpGradeExp;
}

template cCraftUpGradeExpData* rTbl2<cCraftUpGradeExpData>::getData(unsigned int);

template bool rTbl2<cCraftUpGradeExpData>::load(MtStream&);

template bool rTbl2<cCraftUpGradeExpData>::loadCore(MtDataReader&);

template const cCraftUpGradeExpData* rTbl2<cCraftUpGradeExpData>::getData(unsigned int) const;

template unsigned int rTbl2<cCraftUpGradeExpData>::getDataNum() const;

template rTbl2<cCraftUpGradeExpData>::~rTbl2();

