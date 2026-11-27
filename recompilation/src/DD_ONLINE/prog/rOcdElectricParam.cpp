// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rOcdElectricParam.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOcdElectricParam::getDTI() const {
    return cOcdElectricParam::DTI;
}

inline cOcdElectricParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOcdElectricParam::MyDTI cOcdElectricParam::DTI("cOcdElectricParam", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cOcdElectricParam::MyDTI::newInstance() const {
    return new (16u) cOcdElectricParam;
}

const MtDTI& rOcdElectricParam::getDTI() const {
    return rOcdElectricParam::DTI;
}

bool rOcdElectricParam::loadData(MtDataReader& r, cOcdElectricParam* pData) {
    nDDOIO::readData(r, pData->mJointNo);
    return true;
}

MT_CTSTR rOcdElectricParam::getExt() const {
    return "eoc";
}

u32 rOcdElectricParam::getDataVersion() const {
    return 1;
}

inline rOcdElectricParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOcdElectricParam::MyDTI rOcdElectricParam::DTI("rOcdElectricParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rOcdElectricParam::MyDTI::newInstance() const {
    return new (16u) rOcdElectricParam;
}

template cOcdElectricParam* rTbl2<cOcdElectricParam>::getData(unsigned int);

template bool rTbl2<cOcdElectricParam>::load(MtStream&);

template bool rTbl2<cOcdElectricParam>::loadCore(MtDataReader&);

template const cOcdElectricParam* rTbl2<cOcdElectricParam>::getData(unsigned int) const;

template unsigned int rTbl2<cOcdElectricParam>::getDataNum() const;

template rTbl2<cOcdElectricParam>::~rTbl2();

