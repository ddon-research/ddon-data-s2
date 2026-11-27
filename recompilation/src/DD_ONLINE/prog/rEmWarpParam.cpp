// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmWarpParam.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmWarpParam::getDTI() const {
    return cEmWarpParam::DTI;
}

inline cEmWarpParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmWarpParam::MyDTI cEmWarpParam::DTI("cEmWarpParam", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cEmWarpParam::MyDTI::newInstance() const {
    return new (16u) cEmWarpParam;
}

const MtDTI& rEmWarpParam::getDTI() const {
    return rEmWarpParam::DTI;
}

bool rEmWarpParam::loadData(MtDataReader& r, cEmWarpParam* pData) {
    pData->mWarpDist[0] = r.readF32();
    pData->mWarpDist[1] = r.readF32();
    pData->mWarpDist[2] = r.readF32();
    nDDOIO::readData(r, pData->mGroundCheckDist);
    nDDOIO::readData(r, pData->mIsGroundCheckExtend);
    return true;
}

MT_CTSTR rEmWarpParam::getExt() const {
    return "ewp";
}

u32 rEmWarpParam::getDataVersion() const {
    return 3;
}

inline rEmWarpParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmWarpParam::MyDTI rEmWarpParam::DTI("rEmWarpParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEmWarpParam::MyDTI::newInstance() const {
    return new (16u) rEmWarpParam;
}

template cEmWarpParam* rTbl2<cEmWarpParam>::getData(unsigned int);

template bool rTbl2<cEmWarpParam>::load(MtStream&);

template bool rTbl2<cEmWarpParam>::loadCore(MtDataReader&);

template const cEmWarpParam* rTbl2<cEmWarpParam>::getData(unsigned int) const;

template unsigned int rTbl2<cEmWarpParam>::getDataNum() const;

template rTbl2<cEmWarpParam>::~rTbl2();

