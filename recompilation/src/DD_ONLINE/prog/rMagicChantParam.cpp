// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rMagicChantParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cMagicChantParam::getDTI() const {
    return cMagicChantParam::DTI;
}

inline void cMagicChantParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cMagicChantParam::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cMagicChantParam::createProperty(MtPropertyList& s) {
}

inline cMagicChantParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMagicChantParam::MyDTI cMagicChantParam::DTI("cMagicChantParam", &::MtObject::DTI, 416ul, 0u, 0u);

__attribute__((weak)) MtObject* cMagicChantParam::MyDTI::newInstance() const {
    return new (16u) cMagicChantParam;
}

const MtDTI& rMagicChantParam::getDTI() const {
    return rMagicChantParam::DTI;
}

inline void* rMagicChantParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rMagicChantParam::DTI)->memAlloc(sz, align, rMagicChantParam::DTI.getID());
}

inline void rMagicChantParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rMagicChantParam::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool rMagicChantParam::loadData(MtDataReader& in, cMagicChantParam* pData) {
    f32 time;
    nDDOIO::readData(in, pData->mChantMot);
    nDDOIO::readData(in, time);
    pData->setChantTime(time);
    nDDOIO::readData(in, pData->mEndType);
    nDDOIO::readData(in, pData->mIsChant2);
    nDDOIO::readData(in, pData->mChant2Mot);
    nDDOIO::readData(in, time);
    pData->setChant2Time(time);
    nDDOIO::readData(in, pData->mSetType);
    nDDOIO::readData(in, pData->mIsConst);
    nDDOIO::readData(in, pData->mJointNo);
    nDDOIO::readData(in, pData->mShotOption);
    nDDOIO::readData(in, pData->mShotPosOffset);
    nDDOIO::readData(in, pData->mNoneLockOnPos);
    nDDOIO::readData(in, pData->mNoneLockOnPosNext);
    nDDOIO::readData(in, pData->mShotMot);
    nDDOIO::readData(in, pData->mIsMotLoop);
    nDDOIO::readData(in, pData->mShotLoopingTime);
    nDDOIO::readData(in, pData->mIsUseShotLimitXAngle);
    nDDOIO::readData(in, pData->mShotLimitXAngle);
    nDDOIO::readData(in, pData->mEndMotion);
    nDDOIO::readData(in, pData->mChantCameraNumber);
    nDDOIO::readData(in, pData->mShotCameraNumber);
    nDDOIO::readData(in, pData->mEndCameraNumber);
    nDDOIO::readData(in, pData->mShlBornFrame);
    nDDOIO::readData(in, pData->mShlGroupNumber);
    nDDOIO::readData(in, pData->mShlIndexNumber);
    nDDOIO::readData(in, pData->mShlGroupNumberNext);
    nDDOIO::readData(in, pData->mShlIndexNumberNext);
    nDDOIO::readData(in, pData->mIsCanMove);
    nDDOIO::readData(in, pData->mChantAttribute);
    nDDOIO::readData(in, pData->mIsUseChantCommand);
    nDDOIO::readData(in, pData->mChantCommandLevel);
    nDDOIO::readData(in, pData->mMagocCommandNo);
    nDDOIO::readData(in, pData->mIsUseAutoRock);
    nDDOIO::readData(in, pData->mAutoRockRange);
    nDDOIO::readData(in, pData->mAutoRockAngle);
    nDDOIO::readData(in, pData->mChant2EffectIndex);
    nDDOIO::readData(in, pData->mChant2EffectNumber);
    nDDOIO::readData(in, pData->mChant2EffectFrame);
    nDDOIO::readData(in, pData->mChant2SeFrame);
    nDDOIO::readData(in, pData->mIsSetCustomChantTime);
    for (s16 i = 0; i < 10; ++i) {
        nDDOIO::readData(in, time);
        pData->setCustomChantTime(time, i);
    }
    nDDOIO::readData(in, pData->mIsAimTargetSpot);
    nDDOIO::readData(in, pData->mAimTargetSpotMaxRange);
    nDDOIO::readData(in, pData->mAimTargetSpotMinRange);
    nDDOIO::readData(in, pData->mIsNoChantSe);
    nDDOIO::readData(in, pData->mAddHealHate);
    return true;
}

MT_CTSTR rMagicChantParam::getExt() const {
    return "chant";
}

u32 rMagicChantParam::getDataVersion() const {
    return 17;
}

void rMagicChantParam::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

inline rMagicChantParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMagicChantParam::MyDTI rMagicChantParam::DTI("rMagicChantParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rMagicChantParam::MyDTI::newInstance() const {
    return new (16u) rMagicChantParam;
}

template cMagicChantParam* rTbl2<cMagicChantParam>::getData(unsigned int);

template bool rTbl2<cMagicChantParam>::load(MtStream&);

template bool rTbl2<cMagicChantParam>::loadCore(MtDataReader&);

template const cMagicChantParam* rTbl2<cMagicChantParam>::getData(unsigned int) const;

template unsigned int rTbl2<cMagicChantParam>::getDataNum() const;

template rTbl2<cMagicChantParam>::~rTbl2();

