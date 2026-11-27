// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCaughtInfoParam.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cCaughtInfoParam>::allocData(unsigned int);
#endif

const MtDTI& cCaughtInfoParam::getDTI() const {
    return cCaughtInfoParam::DTI;
}

void cCaughtInfoParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCatchType", &mCatchType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCaughtActionTblNo", &mCaughtActionTblNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConstOffsetPos", &mConstOffsetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConstOffsetAngle", &mConstOffsetAngle, 0u, 0u);
}

inline cCaughtInfoParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCaughtInfoParam::MyDTI cCaughtInfoParam::DTI("cCaughtInfoParam", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cCaughtInfoParam::MyDTI::newInstance() const {
    return new (16u) cCaughtInfoParam;
}

const MtDTI& rCaughtInfoParam::getDTI() const {
    return rCaughtInfoParam::DTI;
}

bool rCaughtInfoParam::loadData(MtDataReader& in, cCaughtInfoParam* pData) {
    pData->mCatchType = in.readU32();
    pData->mCaughtActionTblNo = in.readU32();
    pData->mConstOffsetPos = in.readV3();
    pData->mConstOffsetAngle = in.readV3();
    return true;
}

MT_CTSTR rCaughtInfoParam::getExt() const {
    return "caip";
}

u32 rCaughtInfoParam::getDataVersion() const {
    return 15;
}

void rCaughtInfoParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpData", static_cast<MtObject*>(mpData), 32u, mDataNum);
}

inline rCaughtInfoParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCaughtInfoParam::MyDTI rCaughtInfoParam::DTI("rCaughtInfoParam", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rCaughtInfoParam::MyDTI::newInstance() const {
    return new (16u) rCaughtInfoParam;
}

template cCaughtInfoParam* rTbl2<cCaughtInfoParam>::getData(unsigned int);

template bool rTbl2<cCaughtInfoParam>::load(MtStream&);

template bool rTbl2<cCaughtInfoParam>::loadCore(MtDataReader&);

template const cCaughtInfoParam* rTbl2<cCaughtInfoParam>::getData(unsigned int) const;

template unsigned int rTbl2<cCaughtInfoParam>::getDataNum() const;

template rTbl2<cCaughtInfoParam>::~rTbl2();

