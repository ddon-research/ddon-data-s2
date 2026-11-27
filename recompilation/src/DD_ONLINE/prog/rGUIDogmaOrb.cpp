// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rGUIDogmaOrb.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGUIDogmaOrbRes::getDTI() const {
    return cGUIDogmaOrbRes::DTI;
}

cGUIDogmaOrbRes::~cGUIDogmaOrbRes() {
}

inline cGUIDogmaOrbRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIDogmaOrbRes::MyDTI cGUIDogmaOrbRes::DTI("cGUIDogmaOrbRes", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cGUIDogmaOrbRes::MyDTI::newInstance() const {
    return new (16u) cGUIDogmaOrbRes;
}

const MtDTI& rGUIDogmaOrb::getDTI() const {
    return rGUIDogmaOrb::DTI;
}

bool rGUIDogmaOrb::loadData(MtDataReader& Reader, cGUIDogmaOrbRes* pData) {
    nDDOIO::readData(Reader, pData->mElementId);
    nDDOIO::readData(Reader, pData->mParamType);
    nDDOIO::readData(Reader, pData->mParamId);
    nDDOIO::readData(Reader, pData->mParamValue);
    nDDOIO::readData(Reader, pData->mRequireOrb);
    nDDOIO::readData(Reader, pData->mIconNo);
    return true;
}

MT_CTSTR rGUIDogmaOrb::getExt() const {
    return "dgm";
}

u32 rGUIDogmaOrb::getDataVersion() const {
    return 1;
}

inline rGUIDogmaOrb::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGUIDogmaOrb::MyDTI rGUIDogmaOrb::DTI("rGUIDogmaOrb", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rGUIDogmaOrb::MyDTI::newInstance() const {
    return new (16u) rGUIDogmaOrb;
}

template cGUIDogmaOrbRes* rTbl2<cGUIDogmaOrbRes>::getData(unsigned int);

template bool rTbl2<cGUIDogmaOrbRes>::load(MtStream&);

template bool rTbl2<cGUIDogmaOrbRes>::loadCore(MtDataReader&);

template const cGUIDogmaOrbRes* rTbl2<cGUIDogmaOrbRes>::getData(unsigned int) const;

template unsigned int rTbl2<cGUIDogmaOrbRes>::getDataNum() const;

template rTbl2<cGUIDogmaOrbRes>::~rTbl2();

