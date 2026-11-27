// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rErosionRegionScaleChange.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cErosionRegionScaleChange::getDTI() const {
    return cErosionRegionScaleChange::DTI;
}

inline cErosionRegionScaleChange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cErosionRegionScaleChange::MyDTI cErosionRegionScaleChange::DTI("cErosionRegionScaleChange", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cErosionRegionScaleChange::MyDTI::newInstance() const {
    return new (16u) cErosionRegionScaleChange;
}

const MtDTI& rErosionRegionScaleChange::getDTI() const {
    return rErosionRegionScaleChange::DTI;
}

bool rErosionRegionScaleChange::loadData(MtDataReader& r, cErosionRegionScaleChange* pData) {
    pData->mInitScale = r.readV3();
    nDDOIO::readData(r, pData->mChangeFrame);
    return true;
}

MT_CTSTR rErosionRegionScaleChange::getExt() const {
    return "scl_change";
}

u32 rErosionRegionScaleChange::getDataVersion() const {
    return 1;
}

inline rErosionRegionScaleChange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rErosionRegionScaleChange::MyDTI rErosionRegionScaleChange::DTI("rErosionRegionScaleChange", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rErosionRegionScaleChange::MyDTI::newInstance() const {
    return new (16u) rErosionRegionScaleChange;
}

template cErosionRegionScaleChange* rTbl2<cErosionRegionScaleChange>::getData(unsigned int);

template bool rTbl2<cErosionRegionScaleChange>::load(MtStream&);

template bool rTbl2<cErosionRegionScaleChange>::loadCore(MtDataReader&);

template const cErosionRegionScaleChange* rTbl2<cErosionRegionScaleChange>::getData(unsigned int) const;

template unsigned int rTbl2<cErosionRegionScaleChange>::getDataNum() const;

template rTbl2<cErosionRegionScaleChange>::~rTbl2();

