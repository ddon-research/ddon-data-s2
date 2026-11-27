// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rMotionFilter.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cMotionFilter::getDTI() const {
    return cMotionFilter::DTI;
}

inline cMotionFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMotionFilter::MyDTI cMotionFilter::DTI("cMotionFilter", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cMotionFilter::MyDTI::newInstance() const {
    return new (16u) cMotionFilter;
}

const MtDTI& rMotionFilter::getDTI() const {
    return rMotionFilter::DTI;
}

bool rMotionFilter::loadData(MtDataReader& r, cMotionFilter* pData) {
    nDDOIO::readData(r, pData->mMin);
    nDDOIO::readData(r, pData->mMiddle);
    nDDOIO::readData(r, pData->mMax);
    return true;
}

MT_CTSTR rMotionFilter::getExt() const {
    return "mot_filter";
}

u32 rMotionFilter::getDataVersion() const {
    return 2;
}

inline rMotionFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMotionFilter::MyDTI rMotionFilter::DTI("rMotionFilter", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rMotionFilter::MyDTI::newInstance() const {
    return new (16u) rMotionFilter;
}

template cMotionFilter* rTbl2<cMotionFilter>::getData(unsigned int);

template bool rTbl2<cMotionFilter>::load(MtStream&);

template bool rTbl2<cMotionFilter>::loadCore(MtDataReader&);

template const cMotionFilter* rTbl2<cMotionFilter>::getData(unsigned int) const;

template unsigned int rTbl2<cMotionFilter>::getDataNum() const;

template rTbl2<cMotionFilter>::~rTbl2();

