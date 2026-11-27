// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rDmVecWeightParam.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cDmVecWeightParam::getDTI() const {
    return cDmVecWeightParam::DTI;
}

void cDmVecWeightParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\351\207\215\351\207\217", &mWeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "XZ\351\200\237\345\272\246\350\243\234\346\255\243", &mWeightAdjSpeedXZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Y\351\200\237\345\272\246\350\243\234\346\255\243", &mWeightAdjSpeedY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "XZ\345\212\240\351\200\237\345\272\246\350\243\234\346\255\243", &mWeightAdjAccXZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Y\345\212\240\351\200\237\345\272\246\350\243\234\346\255\243", &mWeightAdjAccY, 0u, 0u);
}

inline cDmVecWeightParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDmVecWeightParam::MyDTI cDmVecWeightParam::DTI("cDmVecWeightParam", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cDmVecWeightParam::MyDTI::newInstance() const {
    return new (16u) cDmVecWeightParam;
}

const MtDTI& rDmVecWeightParam::getDTI() const {
    return rDmVecWeightParam::DTI;
}

bool rDmVecWeightParam::loadData(MtDataReader& in, cDmVecWeightParam* pData) {
    nDDOIO::readData(in, pData->mWeight);
    nDDOIO::readData(in, pData->mWeightAdjSpeedXZ);
    nDDOIO::readData(in, pData->mWeightAdjSpeedY);
    nDDOIO::readData(in, pData->mWeightAdjAccXZ);
    nDDOIO::readData(in, pData->mWeightAdjAccY);
    return true;
}

MT_CTSTR rDmVecWeightParam::getExt() const {
    return "dvw";
}

u32 rDmVecWeightParam::getDataVersion() const {
    return 1;
}

inline rDmVecWeightParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDmVecWeightParam::MyDTI rDmVecWeightParam::DTI("rDmVecWeightParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rDmVecWeightParam::MyDTI::newInstance() const {
    return new (16u) rDmVecWeightParam;
}

template cDmVecWeightParam* rTbl2<cDmVecWeightParam>::getData(unsigned int);

template bool rTbl2<cDmVecWeightParam>::load(MtStream&);

template bool rTbl2<cDmVecWeightParam>::loadCore(MtDataReader&);

template const cDmVecWeightParam* rTbl2<cDmVecWeightParam>::getData(unsigned int) const;

template unsigned int rTbl2<cDmVecWeightParam>::getDataNum() const;

template rTbl2<cDmVecWeightParam>::~rTbl2();

