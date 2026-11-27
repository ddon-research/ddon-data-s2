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
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\263\343\203\263\343\202\271\343\203\210\343\201\231\343\202\213", &mIsConst, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\216\264\343\201\276\343\202\214\345\201\264\343\201\256\343\202\271\343\202\257\343\203\255\343\203\274\343\203\253\345\275\223\343\201\237\343\202\212\343\202\222\346\212\234\343\201\213\343\201\252\343\201\204", &mRevAdjust, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\263\343\203\263\343\202\271\343\203\210\346\231\202\343\202\271\343\202\261\343\203\274\343\203\253\350\250\210\347\256\227OFF", &mConstScaleOff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConstJointNo", &mConstJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\216\264\343\201\277\343\203\253\343\203\274\343\203\227\346\231\202\351\226\223", &mLoopTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\254\343\203\220\343\202\254\343\203\201\343\203\243\347\202\271\346\225\260", &mLeverGachaPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\271\343\203\254\343\203\274\343\203\226\345\201\264\343\201\247\350\267\235\351\233\242\343\203\201\343\202\247\343\203\203\343\202\257\343\201\231\343\202\213", &mIsCheckSlaveDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\271\343\203\254\343\203\274\343\203\226\345\201\264\343\201\247\343\201\256\343\203\201\343\202\247\343\203\203\343\202\257\350\267\235\351\233\242", &mCheckSlaveDist, 0u, 0u);
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

