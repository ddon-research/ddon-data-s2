// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEnemyReactResEx.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cEnemyReactRes>::allocData(unsigned int);
#endif

const MtDTI& cEnemyReactRes::getDTI() const {
    return cEnemyReactRes::DTI;
}

inline void* cEnemyReactRes::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cEnemyReactRes::DTI)->memAlloc(sz, align, cEnemyReactRes::DTI.getID());
}

inline void cEnemyReactRes::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cEnemyReactRes::DTI)->memFree(p_addr);
}

inline cEnemyReactRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEnemyReactRes::MyDTI cEnemyReactRes::DTI("cEnemyReactRes", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cEnemyReactRes::MyDTI::newInstance() const {
    return new (16u) cEnemyReactRes;
}

const MtDTI& rEnemyReactResEx::getDTI() const {
    return rEnemyReactResEx::DTI;
}

inline void rEnemyReactResEx::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEnemyReactResEx::DTI)->memFree(p_addr);
}

rEnemyReactResEx::~rEnemyReactResEx() {
}

bool rEnemyReactResEx::loadData(MtDataReader& r, cEnemyReactRes* pData) {
    nDDOIO::readData(r, pData->mCountStart);
    nDDOIO::readData(r, pData->mCountEnd);
    nDDOIO::readData(r, pData->mPercent);
    nDDOIO::readData(r, pData->mParam0);
    nDDOIO::readData(r, pData->mParam1);
    return true;
}

MT_CTSTR rEnemyReactResEx::getExt() const {
    return "era";
}

u32 rEnemyReactResEx::getDataVersion() const {
    return 6;
}

__attribute__((weak)) bool rEnemyReactResEx::loadCore(MtDataReader& r) {
    nDDOIO::readData(r, this->mOverallConditionsType);
    nDDOIO::readData(r, this->mOverallConditions0);
    nDDOIO::readData(r, this->mOverallConditions1);
    nDDOIO::readData(r, this->mOverallConditionsReverse);
    nDDOIO::readData(r, this->mOverallConditionsBitMode);
    for (u32 i = 0; i < REACT_WHERE_NUM; ++i) {
        nDDOIO::readData(r, this->mWhereType[i]);
        nDDOIO::readData(r, this->mWhereNo[i]);
    }
    nDDOIO::readData(r, this->mWhereNoRev);
    nDDOIO::readData(r, this->mPlayTypeGuard);
    nDDOIO::readData(r, this->mPlayTypeNamed);
    nDDOIO::readData(r, this->mPlayTypeAnger);
    nDDOIO::readData(r, this->mPlayTypeNanteki);
    nDDOIO::readData(r, this->mPlayTypeYojinoboriAttack);
    nDDOIO::readData(r, this->mPlayTypeHP);
    nDDOIO::readData(r, this->mPlayTypeHPParam[0]);
    nDDOIO::readData(r, this->mPlayTypeHPParam[1]);
    nDDOIO::readData(r, this->mPlayTypeHPParamReverse);
    nDDOIO::readData(r, this->mPlayTypeUseSeq);
    nDDOIO::readData(r, this->mPlayTypeUseSeqWorkNo);
    nDDOIO::readData(r, this->mPlayTypeSeqNo);
    nDDOIO::readData(r, this->mPlayTypeSeqWorkNo);
    for (u32 i = 0; i < 12u; ++i) {
        nDDOIO::readData(r, this->mCountType[i]);
    }
    nDDOIO::readData(r, this->mResetTypeBlow);
    nDDOIO::readData(r, this->mResetTypeBlowCount);
    nDDOIO::readData(r, this->mResetTypeShrink);
    nDDOIO::readData(r, this->mResetTypeShrinkCount);
    nDDOIO::readData(r, this->mResetTypeDown);
    nDDOIO::readData(r, this->mResetTypeDownCount);
    nDDOIO::readData(r, this->mResetType);
    nDDOIO::readData(r, this->mFResetParam);
    nDDOIO::readData(r, this->mUResetParam);
    nDDOIO::readData(r, this->mResultThinkTable);
    nDDOIO::readData(r, this->mResultThinkTableNo);
    nDDOIO::readData(r, this->mResultThinkTableActionGet);
    nDDOIO::readData(r, this->mResultAction);
    nDDOIO::readData(r, this->mResultActionNo);
    nDDOIO::readData(r, this->mOverallConditionsBit);
    return this->rTbl2<cEnemyReactRes>::loadCore(r);
}

inline rEnemyReactResEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEnemyReactResEx::MyDTI rEnemyReactResEx::DTI("rEnemyReactResEx", &::rTbl2Base::DTI, 328ul, 0u, 0u);

__attribute__((weak)) MtObject* rEnemyReactResEx::MyDTI::newInstance() const {
    return new (16u) rEnemyReactResEx;
}

template cEnemyReactRes* rTbl2<cEnemyReactRes>::getData(unsigned int);

template bool rTbl2<cEnemyReactRes>::load(MtStream&);

template bool rTbl2<cEnemyReactRes>::loadCore(MtDataReader&);

template const cEnemyReactRes* rTbl2<cEnemyReactRes>::getData(unsigned int) const;

template unsigned int rTbl2<cEnemyReactRes>::getDataNum() const;

template rTbl2<cEnemyReactRes>::~rTbl2();

