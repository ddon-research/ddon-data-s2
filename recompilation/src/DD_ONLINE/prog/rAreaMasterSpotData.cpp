// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rAreaMasterSpotData.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "cUIObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cAreaMasterSpotDetailData>::allocData(unsigned int);
#endif

const MtDTI& cAreaMasterRankData::getDTI() const {
    return cAreaMasterRankData::DTI;
}

inline cAreaMasterRankData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAreaMasterRankData::MyDTI cAreaMasterRankData::DTI("cAreaMasterRankData", &::cUIResource::DTI, 24ul, 0u, 0u);

MtObject* cAreaMasterRankData::MyDTI::newInstance() const {
    return new (16u) cAreaMasterRankData;
}

const MtDTI& cAreaMasterSpotData::getDTI() const {
    return cAreaMasterSpotData::DTI;
}

inline cAreaMasterSpotData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAreaMasterSpotData::MyDTI cAreaMasterSpotData::DTI("cAreaMasterSpotData", &::cUIResource::DTI, 48ul, 0u, 0u);

MtObject* cAreaMasterSpotData::MyDTI::newInstance() const {
    return new (16u) cAreaMasterSpotData;
}

const MtDTI& cAreaMasterSpotDetailData::getDTI() const {
    return cAreaMasterSpotDetailData::DTI;
}

inline cAreaMasterSpotDetailData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAreaMasterSpotDetailData::MyDTI cAreaMasterSpotDetailData::DTI("cAreaMasterSpotDetailData", &::cUIResource::DTI, 80ul, 0u, 0u);

MtObject* cAreaMasterSpotDetailData::MyDTI::newInstance() const {
    return new (16u) cAreaMasterSpotDetailData;
}

const MtDTI& cSpotEnemyData::getDTI() const {
    return cSpotEnemyData::DTI;
}

inline cSpotEnemyData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSpotEnemyData::MyDTI cSpotEnemyData::DTI("cSpotEnemyData", &::cUIResource::DTI, 24ul, 0u, 0u);

MtObject* cSpotEnemyData::MyDTI::newInstance() const {
    return new (16u) cSpotEnemyData;
}

const MtDTI& cSpotItemData::getDTI() const {
    return cSpotItemData::DTI;
}

inline cSpotItemData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSpotItemData::MyDTI cSpotItemData::DTI("cSpotItemData", &::cUIResource::DTI, 16ul, 0u, 0u);

MtObject* cSpotItemData::MyDTI::newInstance() const {
    return new (16u) cSpotItemData;
}

const MtDTI& rAreaMasterRankData::getDTI() const {
    return rAreaMasterRankData::DTI;
}

bool rAreaMasterRankData::loadData(MtDataReader& r, cAreaMasterRankData* pData) {
    nDDOIO::readData(r, pData->mMsgGroupSerial);
    nDDOIO::readData(r, pData->mPoint);
    nDDOIO::readData(r, pData->mBonusType);
    return true;
}

MT_CTSTR rAreaMasterRankData::getExt() const {
    return "amr";
}

u32 rAreaMasterRankData::getDataVersion() const {
    return 4;
}

inline rAreaMasterRankData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaMasterRankData::MyDTI rAreaMasterRankData::DTI("rAreaMasterRankData", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rAreaMasterRankData::MyDTI::newInstance() const {
    return new (16u) rAreaMasterRankData;
}

const MtDTI& rAreaMasterSpotData::getDTI() const {
    return rAreaMasterSpotData::DTI;
}

__attribute__((weak)) bool rAreaMasterSpotData::loadData(MtDataReader& r, cAreaMasterSpotData* pData) {
    nDDOIO::readData(r, pData->mSpotId);
    nDDOIO::readData(r, pData->mCategoryNo);
    nDDOIO::readData(r, pData->mMessageId);
    nDDOIO::readData(r, pData->mStageNoMap);
    nDDOIO::readData(r, pData->mPosX);
    nDDOIO::readData(r, pData->mPosY);
    nDDOIO::readData(r, pData->mPosZ);
    nDDOIO::readData(r, pData->mImageId);
    nDDOIO::readData(r, pData->mRecommendLevel);
    nDDOIO::readData(r, pData->mKeyType);
    nDDOIO::readData(r, pData->mMaskType);
    nDDOIO::readData(r, pData->mPosHide);
    return true;
}

MT_CTSTR rAreaMasterSpotData::getExt() const {
    return "ams";
}

u32 rAreaMasterSpotData::getDataVersion() const {
    return 7;
}

inline rAreaMasterSpotData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaMasterSpotData::MyDTI rAreaMasterSpotData::DTI("rAreaMasterSpotData", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rAreaMasterSpotData::MyDTI::newInstance() const {
    return new (16u) rAreaMasterSpotData;
}

const MtDTI& rAreaMasterSpotDetailData::getDTI() const {
    return rAreaMasterSpotDetailData::DTI;
}

bool rAreaMasterSpotDetailData::loadData(MtDataReader& r, cAreaMasterSpotDetailData* pData) {
    nDDOIO::readData(r, pData->mSpotId);
    nDDOIO::readMtArray(r, pData->mItemArray);
    nDDOIO::readMtArray(r, pData->mEnemyArray);
    return true;
}

MT_CTSTR rAreaMasterSpotDetailData::getExt() const {
    return "amsd";
}

u32 rAreaMasterSpotDetailData::getDataVersion() const {
    return 4;
}

inline rAreaMasterSpotDetailData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaMasterSpotDetailData::MyDTI rAreaMasterSpotDetailData::DTI("rAreaMasterSpotDetailData", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rAreaMasterSpotDetailData::MyDTI::newInstance() const {
    return new (16u) rAreaMasterSpotDetailData;
}

template MtTypedArray<cSpotEnemyData>::~MtTypedArray();

template MtTypedArray<cSpotItemData>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<cSpotItemData>&);

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<cSpotEnemyData>&);

template cAreaMasterRankData* rTbl2<cAreaMasterRankData>::getData(unsigned int);

template cAreaMasterSpotData* rTbl2<cAreaMasterSpotData>::getData(unsigned int);

template cAreaMasterSpotDetailData* rTbl2<cAreaMasterSpotDetailData>::getData(unsigned int);

template bool rTbl2<cAreaMasterRankData>::load(MtStream&);

template bool rTbl2<cAreaMasterSpotData>::load(MtStream&);

template bool rTbl2<cAreaMasterSpotDetailData>::load(MtStream&);

template bool rTbl2<cAreaMasterRankData>::loadCore(MtDataReader&);

template bool rTbl2<cAreaMasterSpotData>::loadCore(MtDataReader&);

template bool rTbl2<cAreaMasterSpotDetailData>::loadCore(MtDataReader&);

template const cAreaMasterRankData* rTbl2<cAreaMasterRankData>::getData(unsigned int) const;

template const cAreaMasterSpotData* rTbl2<cAreaMasterSpotData>::getData(unsigned int) const;

template const cAreaMasterSpotDetailData* rTbl2<cAreaMasterSpotDetailData>::getData(unsigned int) const;

template unsigned int rTbl2<cAreaMasterRankData>::getDataNum() const;

template unsigned int rTbl2<cAreaMasterSpotData>::getDataNum() const;

template unsigned int rTbl2<cAreaMasterSpotDetailData>::getDataNum() const;

template rTbl2<cAreaMasterRankData>::~rTbl2();

template rTbl2<cAreaMasterSpotData>::~rTbl2();

template rTbl2<cAreaMasterSpotDetailData>::~rTbl2();

