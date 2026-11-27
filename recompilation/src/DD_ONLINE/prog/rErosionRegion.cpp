// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rErosionRegion.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nErosionEnemyBase.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cErosionRegionRes>::allocData(unsigned int);
#endif

const MtDTI& cErosionInfoRes::getDTI() const {
    return cErosionInfoRes::DTI;
}

inline cErosionInfoRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cErosionInfoRes::MyDTI cErosionInfoRes::DTI("cErosionInfoRes", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cErosionInfoRes::MyDTI::newInstance() const {
    return new (16u) cErosionInfoRes;
}

const MtDTI& cErosionRegionRes::getDTI() const {
    return cErosionRegionRes::DTI;
}

void cErosionRegionRes::copyParam(const cErosionRegionRes& data) {
    mRegionCategory = data.mRegionCategory;
    mJointNo = data.mJointNo;
    mBreakShlIndex = data.mBreakShlIndex;
    mGenerateShlIndex = data.mGenerateShlIndex;
    mJointNo2 = data.mJointNo2;
    mBreakShlIndex2 = data.mBreakShlIndex2;
    mGenerateShlIndex2 = data.mGenerateShlIndex2;
    mJointNo3 = data.mJointNo3;
    mBreakShlIndex3 = data.mBreakShlIndex3;
    mGenerateShlIndex3 = data.mGenerateShlIndex3;
    mScaleJointNo = data.mScaleJointNo;
    mScaleJointNo2 = data.mScaleJointNo2;
    mScaleChangeType = data.mScaleChangeType;
}

cErosionRegionRes::cErosionRegionRes() {
    mRegionCategory = 1;
    mRegeneratePriority = 0;
    mJointNo = 0;
    mBreakShlIndex = 1;
    mGenerateShlIndex = 11;
    mJointNo2 = -1;
    mBreakShlIndex2 = 0;
    mGenerateShlIndex2 = 0;
    mJointNo3 = -1;
    mBreakShlIndex3 = 0;
    mGenerateShlIndex3 = 0;
    mScaleJointNo = -1;
    mScaleJointNo2 = -1;
    mScaleChangeType = 0;
}

inline cErosionRegionRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cErosionRegionRes::MyDTI cErosionRegionRes::DTI("cErosionRegionRes", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cErosionRegionRes::MyDTI::newInstance() const {
    return new (16u) cErosionRegionRes;
}

const MtDTI& cErosionSmallInfoRes::getDTI() const {
    return cErosionSmallInfoRes::DTI;
}

inline cErosionSmallInfoRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cErosionSmallInfoRes::MyDTI cErosionSmallInfoRes::DTI("cErosionSmallInfoRes", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cErosionSmallInfoRes::MyDTI::newInstance() const {
    return new (16u) cErosionSmallInfoRes;
}

const MtDTI& cErosionSuperInfoRes::getDTI() const {
    return cErosionSuperInfoRes::DTI;
}

void cErosionSuperInfoRes::copyParam(const cErosionSuperInfoRes& data) {
    mCorepointType = data.mCorepointType;
    mAdjustDamageRate = data.mAdjustDamageRate;
    mApearTime = data.mApearTime;
    mRegionCategory = data.mRegionCategory;
}

cErosionSuperInfoRes::cErosionSuperInfoRes() {
    mCorepointType = -1;
    mAdjustDamageRate = 0.05f;
    mApearTime = 0.0f;
    mRegionCategory = 1;
}

inline cErosionSuperInfoRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cErosionSuperInfoRes::MyDTI cErosionSuperInfoRes::DTI("cErosionSuperInfoRes", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cErosionSuperInfoRes::MyDTI::newInstance() const {
    return new (16u) cErosionSuperInfoRes;
}

const MtDTI& rErosionInfoRes::getDTI() const {
    return rErosionInfoRes::DTI;
}

bool rErosionInfoRes::loadData(MtDataReader& r, cErosionInfoRes* pData) {
    pData->mRegenerateTimer[0] = r.readF32();
    pData->mRegenerateTimer[1] = r.readF32();
    pData->mRegenerateTimer[2] = r.readF32();
    pData->mRegenerateTimer[3] = r.readF32();
    pData->mCancelTimer[1] = r.readF32();
    pData->mCancelTimer[2] = r.readF32();
    pData->mCancelTimer[3] = r.readF32();
    pData->mCancelTimer[4] = r.readF32();
    return true;
}

MT_CTSTR rErosionInfoRes::getExt() const {
    return "reg_info";
}

u32 rErosionInfoRes::getDataVersion() const {
    return 2;
}

inline rErosionInfoRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rErosionInfoRes::MyDTI rErosionInfoRes::DTI("rErosionInfoRes", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rErosionInfoRes::MyDTI::newInstance() const {
    return new (16u) rErosionInfoRes;
}

const MtDTI& rErosionRegion::getDTI() const {
    return rErosionRegion::DTI;
}

bool rErosionRegion::loadData(MtDataReader& r, cErosionRegionRes* pData) {
    nDDOIO::readData(r, pData->mRegionCategory);
    nDDOIO::readData(r, pData->mJointNo);
    nDDOIO::readData(r, pData->mBreakShlIndex);
    nDDOIO::readData(r, pData->mGenerateShlIndex);
    nDDOIO::readData(r, pData->mJointNo2);
    nDDOIO::readData(r, pData->mBreakShlIndex2);
    nDDOIO::readData(r, pData->mGenerateShlIndex2);
    nDDOIO::readData(r, pData->mJointNo3);
    nDDOIO::readData(r, pData->mBreakShlIndex3);
    nDDOIO::readData(r, pData->mGenerateShlIndex3);
    nDDOIO::readData(r, pData->mScaleJointNo);
    nDDOIO::readData(r, pData->mScaleJointNo2);
    nDDOIO::readData(r, pData->mScaleChangeType);
    return true;
}

MT_CTSTR rErosionRegion::getExt() const {
    return "reg_ersion";
}

u32 rErosionRegion::getDataVersion() const {
    return 6;
}

inline rErosionRegion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rErosionRegion::MyDTI rErosionRegion::DTI("rErosionRegion", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rErosionRegion::MyDTI::newInstance() const {
    return new (16u) rErosionRegion;
}

const MtDTI& rErosionSmallInfoRes::getDTI() const {
    return rErosionSmallInfoRes::DTI;
}

bool rErosionSmallInfoRes::loadData(MtDataReader& r, cErosionSmallInfoRes* pData) {
    nDDOIO::readData(r, pData->mCancelTimer);
    nDDOIO::readData(r, pData->mCancelWaitTimer);
    nDDOIO::readData(r, pData->mScaleActiveRate);
    nDDOIO::readData(r, pData->mScaleInActiveMax);
    nDDOIO::readData(r, pData->mScaleInActiveMin);
    return true;
}

MT_CTSTR rErosionSmallInfoRes::getExt() const {
    return "eroSmall_info";
}

u32 rErosionSmallInfoRes::getDataVersion() const {
    return 4;
}

inline rErosionSmallInfoRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rErosionSmallInfoRes::MyDTI rErosionSmallInfoRes::DTI("rErosionSmallInfoRes", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rErosionSmallInfoRes::MyDTI::newInstance() const {
    return new (16u) rErosionSmallInfoRes;
}

const MtDTI& rErosionSuperInfoRes::getDTI() const {
    return rErosionSuperInfoRes::DTI;
}

bool rErosionSuperInfoRes::loadData(MtDataReader& r, cErosionSuperInfoRes* pData) {
    nDDOIO::readData(r, pData->mCorepointType);
    nDDOIO::readData(r, pData->mAdjustDamageRate);
    nDDOIO::readData(r, pData->mApearTime);
    nDDOIO::readData(r, pData->mRegionCategory);
    return true;
}

MT_CTSTR rErosionSuperInfoRes::getExt() const {
    return "eroSuper_info";
}

u32 rErosionSuperInfoRes::getDataVersion() const {
    return 4;
}

inline rErosionSuperInfoRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rErosionSuperInfoRes::MyDTI rErosionSuperInfoRes::DTI("rErosionSuperInfoRes", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rErosionSuperInfoRes::MyDTI::newInstance() const {
    return new (16u) rErosionSuperInfoRes;
}

template cErosionInfoRes* rTbl2<cErosionInfoRes>::getData(unsigned int);

template cErosionRegionRes* rTbl2<cErosionRegionRes>::getData(unsigned int);

template cErosionSmallInfoRes* rTbl2<cErosionSmallInfoRes>::getData(unsigned int);

template cErosionSuperInfoRes* rTbl2<cErosionSuperInfoRes>::getData(unsigned int);

template bool rTbl2<cErosionInfoRes>::load(MtStream&);

template bool rTbl2<cErosionRegionRes>::load(MtStream&);

template bool rTbl2<cErosionSmallInfoRes>::load(MtStream&);

template bool rTbl2<cErosionSuperInfoRes>::load(MtStream&);

template bool rTbl2<cErosionInfoRes>::loadCore(MtDataReader&);

template bool rTbl2<cErosionRegionRes>::loadCore(MtDataReader&);

template bool rTbl2<cErosionSmallInfoRes>::loadCore(MtDataReader&);

template bool rTbl2<cErosionSuperInfoRes>::loadCore(MtDataReader&);

template const cErosionInfoRes* rTbl2<cErosionInfoRes>::getData(unsigned int) const;

template const cErosionRegionRes* rTbl2<cErosionRegionRes>::getData(unsigned int) const;

template const cErosionSmallInfoRes* rTbl2<cErosionSmallInfoRes>::getData(unsigned int) const;

template const cErosionSuperInfoRes* rTbl2<cErosionSuperInfoRes>::getData(unsigned int) const;

template unsigned int rTbl2<cErosionInfoRes>::getDataNum() const;

template unsigned int rTbl2<cErosionRegionRes>::getDataNum() const;

template unsigned int rTbl2<cErosionSmallInfoRes>::getDataNum() const;

template unsigned int rTbl2<cErosionSuperInfoRes>::getDataNum() const;

template rTbl2<cErosionInfoRes>::~rTbl2();

template rTbl2<cErosionRegionRes>::~rTbl2();

template rTbl2<cErosionSmallInfoRes>::~rTbl2();

template rTbl2<cErosionSuperInfoRes>::~rTbl2();

