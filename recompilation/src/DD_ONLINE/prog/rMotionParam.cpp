// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rMotionParam.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cMotionParam::getDTI() const {
    return cMotionParam::DTI;
}

inline cMotionParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMotionParam::MyDTI cMotionParam::DTI("cMotionParam", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cMotionParam::MyDTI::newInstance() const {
    return new (16u) cMotionParam;
}

const MtDTI& rMotionParam::getDTI() const {
    return rMotionParam::DTI;
}

bool rMotionParam::loadData(MtDataReader& r, cMotionParam* pData) {
    nDDOIO::readData(r, pData->mInterFrame);
    nDDOIO::readData(r, pData->mIsContinue);
    nDDOIO::readData(r, pData->mIKFlag);
    nDDOIO::readData(r, pData->mIKFlagFSM);
    return true;
}

MT_CTSTR rMotionParam::getExt() const {
    return "motparam";
}

u32 rMotionParam::getDataVersion() const {
    return 21;
}

inline rMotionParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMotionParam::MyDTI rMotionParam::DTI("rMotionParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rMotionParam::MyDTI::newInstance() const {
    return new (16u) rMotionParam;
}

template cMotionParam* rTbl2<cMotionParam>::getData(unsigned int);

template bool rTbl2<cMotionParam>::load(MtStream&);

template bool rTbl2<cMotionParam>::loadCore(MtDataReader&);

template const cMotionParam* rTbl2<cMotionParam>::getData(unsigned int) const;

template unsigned int rTbl2<cMotionParam>::getDataNum() const;

template rTbl2<cMotionParam>::~rTbl2();

