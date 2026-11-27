// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCatchInfoParam.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCatchInfoParam::getDTI() const {
    return cCatchInfoParam::DTI;
}

void cCatchInfoParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCatchType", &mCatchType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCatchActionTblNo", &mCatchActionTblNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "コンストする", &mIsConst, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "掴まれ側のスクロール当たりを抜かない", &mRevAdjust, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "コンスト時スケール計算OFF", &mConstScaleOff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConstJointNo", &mConstJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "掴みループ時間", &mLoopTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "レバガチャ点数", &mLeverGachaPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "スレーブ側で距離チェックする", &mIsCheckSlaveDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "スレーブ側でのチェック距離", &mCheckSlaveDist, 0u, 0u);
}

inline cCatchInfoParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCatchInfoParam::MyDTI cCatchInfoParam::DTI("cCatchInfoParam", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cCatchInfoParam::MyDTI::newInstance() const {
    return new (16u) cCatchInfoParam;
}

const MtDTI& rCatchInfoParam::getDTI() const {
    return rCatchInfoParam::DTI;
}

__attribute__((weak)) bool rCatchInfoParam::loadData(MtDataReader& in, cCatchInfoParam* pData) {
        nDDOIO::readData(in, pData->mCatchType);
        nDDOIO::readData(in, pData->mCatchActionTblNo);
        nDDOIO::readData(in, pData->mIsConst);
        nDDOIO::readData(in, pData->mRevAdjust);
        nDDOIO::readData(in, pData->mConstScaleOff);
        nDDOIO::readData(in, pData->mConstJointNo);
        nDDOIO::readData(in, pData->mLoopTimer);
        nDDOIO::readData(in, pData->mLeverGachaPoint);
        nDDOIO::readData(in, pData->mIsCheckSlaveDist);
        nDDOIO::readData(in, pData->mCheckSlaveDist);
        return true;
}

MT_CTSTR rCatchInfoParam::getExt() const {
    return "cip";
}

u32 rCatchInfoParam::getDataVersion() const {
    return 18;
}

void rCatchInfoParam::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

inline rCatchInfoParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCatchInfoParam::MyDTI rCatchInfoParam::DTI("rCatchInfoParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCatchInfoParam::MyDTI::newInstance() const {
    return new (16u) rCatchInfoParam;
}

template cCatchInfoParam* rTbl2<cCatchInfoParam>::getData(unsigned int);

template bool rTbl2<cCatchInfoParam>::load(MtStream&);

template bool rTbl2<cCatchInfoParam>::loadCore(MtDataReader&);

template const cCatchInfoParam* rTbl2<cCatchInfoParam>::getData(unsigned int) const;

template unsigned int rTbl2<cCatchInfoParam>::getDataNum() const;

template rTbl2<cCatchInfoParam>::~rTbl2();

