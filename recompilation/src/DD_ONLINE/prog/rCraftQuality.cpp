// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCraftQuality.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCraftQualityData::getDTI() const {
    return cCraftQualityData::DTI;
}

void cCraftQualityData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "適応アイテムID", &mItemNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "品質ボーナス", &mBonus, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ランク上限", &mRankLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "レベル", &mLv, 0u, 0u);
}

inline cCraftQualityData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCraftQualityData::MyDTI cCraftQualityData::DTI("cCraftQualityData", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cCraftQualityData::MyDTI::newInstance() const {
    return new (16u) cCraftQualityData;
}

const MtDTI& rCraftQuality::getDTI() const {
    return rCraftQuality::DTI;
}

bool rCraftQuality::loadData(MtDataReader& in, cCraftQualityData* pData) {
    nDDOIO::readData(in, pData->mItemNo);
    nDDOIO::readData(in, pData->mBonus);
    nDDOIO::readData(in, pData->mRankLimit);
    nDDOIO::readData(in, pData->mLv);
    return true;
}

MT_CTSTR rCraftQuality::getExt() const {
    return "cqr";
}

u32 rCraftQuality::getDataVersion() const {
    return 1;
}

inline rCraftQuality::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCraftQuality::MyDTI rCraftQuality::DTI("rCraftQuality", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCraftQuality::MyDTI::newInstance() const {
    return new (16u) rCraftQuality;
}

template cCraftQualityData* rTbl2<cCraftQualityData>::getData(unsigned int);

template bool rTbl2<cCraftQualityData>::load(MtStream&);

template bool rTbl2<cCraftQualityData>::loadCore(MtDataReader&);

template const cCraftQualityData* rTbl2<cCraftQualityData>::getData(unsigned int) const;

template unsigned int rTbl2<cCraftQualityData>::getDataNum() const;

template rTbl2<cCraftQualityData>::~rTbl2();

