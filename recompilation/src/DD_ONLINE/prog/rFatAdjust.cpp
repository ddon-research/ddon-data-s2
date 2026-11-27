// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rFatAdjust.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cFatAdjust>::allocData(unsigned int);
#endif

const MtDTI& cFatAdjust::getDTI() const {
    return cFatAdjust::DTI;
}

inline cFatAdjust::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFatAdjust::MyDTI cFatAdjust::DTI("cFatAdjust", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cFatAdjust::MyDTI::newInstance() const {
    return new (16u) cFatAdjust;
}

const MtDTI& rFatAdjust::getDTI() const {
    return rFatAdjust::DTI;
}

bool rFatAdjust::loadData(MtDataReader& r, cFatAdjust* pData) {
    pData->mThreshold = r.readF32();
    pData->mRot = r.readV3();
    pData->mTrans = r.readV3();
    return true;
}

MT_CTSTR rFatAdjust::getExt() const {
    return "fat_adjust";
}

u32 rFatAdjust::getDataVersion() const {
    return 4;
}

inline rFatAdjust::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFatAdjust::MyDTI rFatAdjust::DTI("rFatAdjust", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rFatAdjust::MyDTI::newInstance() const {
    return new (16u) rFatAdjust;
}

template cFatAdjust* rTbl2<cFatAdjust>::getData(unsigned int);

template bool rTbl2<cFatAdjust>::load(MtStream&);

template bool rTbl2<cFatAdjust>::loadCore(MtDataReader&);

template const cFatAdjust* rTbl2<cFatAdjust>::getData(unsigned int) const;

template unsigned int rTbl2<cFatAdjust>::getDataNum() const;

template rTbl2<cFatAdjust>::~rTbl2();

