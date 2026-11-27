// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rRegionStatusParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rRegionBreakInfo.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cChildRegionStatusParam>::allocData(unsigned int);
extern template __attribute__((noinline)) void rTbl2<cChildRegionStatusParamList>::allocData(unsigned int);
extern template __attribute__((noinline)) void rTbl2<cParentRegionStatusParam>::allocData(unsigned int);
#endif

const MtDTI& cChildRegionStatusParam::getDTI() const {
    return cChildRegionStatusParam::DTI;
}

inline cChildRegionStatusParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cChildRegionStatusParam::MyDTI cChildRegionStatusParam::DTI("cChildRegionStatusParam", &::MtObject::DTI, 352ul, 0u, 0u);

MtObject* cChildRegionStatusParam::MyDTI::newInstance() const {
    return new (16u) cChildRegionStatusParam;
}

const MtDTI& cChildRegionStatusParamList::getDTI() const {
    return cChildRegionStatusParamList::DTI;
}

cChildRegionStatusParamList::~cChildRegionStatusParamList() {
    if (mpChildRegion == nullptr) {
        return;
    }
    mpChildRegion->release();
    mpChildRegion = nullptr;
}

inline cChildRegionStatusParamList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cChildRegionStatusParamList::MyDTI cChildRegionStatusParamList::DTI("cChildRegionStatusParamList", &::MtObject::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* cChildRegionStatusParamList::MyDTI::newInstance() const {
    return new (16u) cChildRegionStatusParamList;
}

const MtDTI& cParentRegionStatusParam::getDTI() const {
    return cParentRegionStatusParam::DTI;
}

cParentRegionStatusParam::~cParentRegionStatusParam() {
    if (mpBreakInfo == nullptr) {
        return;
    }
    mpBreakInfo->release();
    mpBreakInfo = nullptr;
}

inline cParentRegionStatusParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cParentRegionStatusParam::MyDTI cParentRegionStatusParam::DTI("cParentRegionStatusParam", &::MtObject::DTI, 128ul, 0u, 0u);

__attribute__((weak)) MtObject* cParentRegionStatusParam::MyDTI::newInstance() const {
    return new (16u) cParentRegionStatusParam;
}

const MtDTI& rChildRegionStatusParam::getDTI() const {
    return rChildRegionStatusParam::DTI;
}

__attribute__((weak)) bool rChildRegionStatusParam::loadData(MtDataReader& in, cChildRegionStatusParam* pData) {
    nDDOIO::readData(in, pData->mNo);
    for (u32 i = 0u; i < 2u; i++) {
        nDDOIO::readData(in, pData->mParentNo[i]);
    }
    for (u32 i = 0u; i < 4u; i++) {
        nDDOIO::readData(in, pData->mAttackTolerance[i]);
    }
    for (u32 i = 1u; i < 7u; i++) {
        nDDOIO::readData(in, pData->mMagicTolerance[i]);
    }
    nDDOIO::readData(in, pData->mShrinkAdj);
    nDDOIO::readData(in, pData->mBlowAdj);
    nDDOIO::readData(in, pData->mDownAdj);
    nDDOIO::readData(in, pData->mOcdAdj);
    nDDOIO::readData(in, pData->mRageShrinkAdj);
    for (u32 i = 0u; i < 4u; i++) {
        nDDOIO::readData(in, pData->mShrinkDamageRatePhys[i]);
    }
    for (u32 i = 0u; i < 7u; i++) {
        nDDOIO::readData(in, pData->mShrinkDamageRateMagic[i]);
    }
    for (u32 i = 0u; i < 4u; i++) {
        nDDOIO::readData(in, pData->mBlowDamageRatePhys[i]);
    }
    for (u32 i = 0u; i < 7u; i++) {
        nDDOIO::readData(in, pData->mBlowDamageRateMagic[i]);
    }
    for (u32 i = 0u; i < 4u; i++) {
        nDDOIO::readData(in, pData->mDownDamageRatePhys[i]);
    }
    for (u32 i = 0u; i < 7u; i++) {
        nDDOIO::readData(in, pData->mDownDamageRateMagic[i]);
    }
    for (u32 i = 0u; i < 4u; i++) {
        nDDOIO::readData(in, pData->mShakeAdjPhys[i]);
    }
    for (u32 i = 0u; i < 7u; i++) {
        nDDOIO::readData(in, pData->mShakeAdjMagic[i]);
    }
    nDDOIO::readData(in, pData->mShakeAdjShake);
    nDDOIO::readData(in, pData->mHitStopAdj);
    nDDOIO::readData(in, pData->mHitSlowAdj);
    nDDOIO::readData(in, pData->mHitStopDefenceAttr);
    nDDOIO::readData(in, pData->mSurface);
    nDDOIO::readData(in, pData->mIsClimbBonus);
    nDDOIO::readData(in, pData->mIsDownWeakRegion);
    nDDOIO::readData(in, pData->mCorePointType);
    nDDOIO::readData(in, pData->mCorePointID);
    nDDOIO::readData(in, pData->mCoreJointNo);
    pData->mCoreJointOffset = in.readV3();
    nDDOIO::readData(in, pData->mCoreEpvIndex);
    nDDOIO::readData(in, pData->mCoreEpvElementNo);
    for (u32 i = 0u; i < 4u; i++) {
        nDDOIO::readData(in, pData->mAttackReactionType[i]);
    }
    nDDOIO::readData(in, pData->mIsElementWeakRegion[1]);
    nDDOIO::readData(in, pData->mIsElementWeakRegion[2]);
    nDDOIO::readData(in, pData->mIsElementWeakRegion[3]);
    nDDOIO::readData(in, pData->mIsElementWeakRegion[4]);
    nDDOIO::readData(in, pData->mIsElementWeakRegion[5]);
    nDDOIO::readData(in, pData->mIsElementWeakRegion[6]);
    return true;
}

MT_CTSTR rChildRegionStatusParam::getExt() const {
    return "crs";
}

u32 rChildRegionStatusParam::getDataVersion() const {
    return 65;
}

inline rChildRegionStatusParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rChildRegionStatusParam::MyDTI rChildRegionStatusParam::DTI("rChildRegionStatusParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rChildRegionStatusParam::MyDTI::newInstance() const {
    return new (16u) rChildRegionStatusParam;
}

const MtDTI& rChildRegionStatusParamList::getDTI() const {
    return rChildRegionStatusParamList::DTI;
}

__attribute__((weak)) bool rChildRegionStatusParamList::loadData(MtDataReader& in, cChildRegionStatusParamList* pData) {
    if (pData->mpChildRegion != nullptr && pData->mpChildRegion->loadRoot(in)) {
        nDDOIO::readData(in, pData->mStatusNo);
        nDDOIO::readData(in, pData->mStatusType);
        nDDOIO::readData(in, pData->mStatusPrio);
        return true;
    }
    return false;
}

MT_CTSTR rChildRegionStatusParamList::getExt() const {
    return "rsl";
}

u32 rChildRegionStatusParamList::getDataVersion() const {
    return 65;
}

inline rChildRegionStatusParamList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rChildRegionStatusParamList::MyDTI rChildRegionStatusParamList::DTI("rChildRegionStatusParamList", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rChildRegionStatusParamList::MyDTI::newInstance() const {
    return new (16u) rChildRegionStatusParamList;
}

const MtDTI& rParentRegionStatusParam::getDTI() const {
    return rParentRegionStatusParam::DTI;
}

__attribute__((weak)) bool rParentRegionStatusParam::loadData(MtDataReader& in, cParentRegionStatusParam* pData) {
    nDDOIO::readData(in, pData->mNo);
    nDDOIO::readData(in, pData->mRegionCategory);
    nDDOIO::readData(in, pData->mIsReGenerate);
    nDDOIO::readData(in, pData->mRegenerateProprirty);
    nDDOIO::readData(in, pData->mHPForEdit[0]);
    nDDOIO::readData(in, pData->mHPForEdit[1]);
    nDDOIO::readData(in, pData->mHPForEdit[2]);
    nDDOIO::readData(in, pData->mHPForEdit[3]);
    nDDOIO::readData(in, pData->mHPForEdit[4]);
    pData->mHpMax = pData->getHpMaxFromHpEdit();
    nDDOIO::readData(in, pData->mShPMax);
    nDDOIO::readData(in, pData->mShPSpeed);
    nDDOIO::readData(in, pData->mShPResetTimerMax);
    nDDOIO::readData(in, pData->mBlPMax);
    nDDOIO::readData(in, pData->mBlPSpeed);
    nDDOIO::readData(in, pData->mBlResetTimerMax);
    nDDOIO::readData(in, pData->mDownPMax);
    nDDOIO::readData(in, pData->mDownPSpeed);
    nDDOIO::readData(in, pData->mDownPResetTimerMax);
    nDDOIO::readData(in, pData->mShakePMax);
    nDDOIO::readData(in, pData->mShakePSpeed);
    nDDOIO::readData(in, pData->mShakeResetTimerMax);
    nDDOIO::readData(in, pData->mRageShrinkMax);
    nDDOIO::readData(in, pData->mIsDamageToMain);
    nDDOIO::readData(in, pData->mBreakReactionNo);
    bool ret = false;
    if (pData->mpBreakInfo != nullptr) {
        ret = pData->mpBreakInfo->loadRoot(in);
    }
    return ret;
}

MT_CTSTR rParentRegionStatusParam::getExt() const {
    return "prs";
}

u32 rParentRegionStatusParam::getDataVersion() const {
    return 65;
}

inline rParentRegionStatusParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rParentRegionStatusParam::MyDTI rParentRegionStatusParam::DTI("rParentRegionStatusParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rParentRegionStatusParam::MyDTI::newInstance() const {
    return new (16u) rParentRegionStatusParam;
}

template cChildRegionStatusParam* rTbl2<cChildRegionStatusParam>::getData(unsigned int);

template cChildRegionStatusParamList* rTbl2<cChildRegionStatusParamList>::getData(unsigned int);

template cParentRegionStatusParam* rTbl2<cParentRegionStatusParam>::getData(unsigned int);

template bool rTbl2<cChildRegionStatusParam>::load(MtStream&);

template bool rTbl2<cChildRegionStatusParamList>::load(MtStream&);

template bool rTbl2<cParentRegionStatusParam>::load(MtStream&);

template bool rTbl2<cChildRegionStatusParam>::loadCore(MtDataReader&);

template bool rTbl2<cChildRegionStatusParamList>::loadCore(MtDataReader&);

template bool rTbl2<cParentRegionStatusParam>::loadCore(MtDataReader&);

template const cChildRegionStatusParam* rTbl2<cChildRegionStatusParam>::getData(unsigned int) const;

template const cChildRegionStatusParamList* rTbl2<cChildRegionStatusParamList>::getData(unsigned int) const;

template const cParentRegionStatusParam* rTbl2<cParentRegionStatusParam>::getData(unsigned int) const;

template unsigned int rTbl2<cChildRegionStatusParam>::getDataNum() const;

template unsigned int rTbl2<cChildRegionStatusParamList>::getDataNum() const;

template unsigned int rTbl2<cParentRegionStatusParam>::getDataNum() const;

template rTbl2<cChildRegionStatusParam>::~rTbl2();

template rTbl2<cChildRegionStatusParamList>::~rTbl2();

template rTbl2<cParentRegionStatusParam>::~rTbl2();

