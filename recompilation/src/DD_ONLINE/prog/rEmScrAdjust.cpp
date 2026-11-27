// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmScrAdjust.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmScrAdjust::getDTI() const {
    return cEmScrAdjust::DTI;
}

inline cEmScrAdjust::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmScrAdjust::MyDTI cEmScrAdjust::DTI("cEmScrAdjust", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cEmScrAdjust::MyDTI::newInstance() const {
    return new (16u) cEmScrAdjust;
}

const MtDTI& rEmScrAdjust::getDTI() const {
    return rEmScrAdjust::DTI;
}

bool rEmScrAdjust::loadData(MtDataReader& r, cEmScrAdjust* pData) {
    nDDOIO::readData(r, pData->mRadius);
    nDDOIO::readData(r, pData->mHeight);
    nDDOIO::readData(r, pData->mFallLimit);
    nDDOIO::readData(r, pData->mNormalCheckRange);
    return true;
}

MT_CTSTR rEmScrAdjust::getExt() const {
    return "em_scr_adj";
}

u32 rEmScrAdjust::getDataVersion() const {
    return 4;
}

inline rEmScrAdjust::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmScrAdjust::MyDTI rEmScrAdjust::DTI("rEmScrAdjust", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEmScrAdjust::MyDTI::newInstance() const {
    return new (16u) rEmScrAdjust;
}

template cEmScrAdjust* rTbl2<cEmScrAdjust>::getData(unsigned int);

template bool rTbl2<cEmScrAdjust>::load(MtStream&);

template bool rTbl2<cEmScrAdjust>::loadCore(MtDataReader&);

template const cEmScrAdjust* rTbl2<cEmScrAdjust>::getData(unsigned int) const;

template unsigned int rTbl2<cEmScrAdjust>::getDataNum() const;

template rTbl2<cEmScrAdjust>::~rTbl2();

