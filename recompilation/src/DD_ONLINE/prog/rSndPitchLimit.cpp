// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSndPitchLimit.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSndPitchLimitData::getDTI() const {
    return cSndPitchLimitData::DTI;
}

void cSndPitchLimitData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "タイプ", &mVoiceType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "性別", &mSex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "上限", &mLimitUpper, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "下限", &mLimitDowner, 0u, 0u);
}

inline cSndPitchLimitData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSndPitchLimitData::MyDTI cSndPitchLimitData::DTI("cSndPitchLimitData", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cSndPitchLimitData::MyDTI::newInstance() const {
    return new (16u) cSndPitchLimitData;
}

const MtDTI& rSndPitchLimit::getDTI() const {
    return rSndPitchLimit::DTI;
}

bool rSndPitchLimit::loadData(MtDataReader& in, cSndPitchLimitData* pData) {
    nDDOIO::readData(in, pData->mVoiceType);
    nDDOIO::readData(in, pData->mSex);
    nDDOIO::readData(in, pData->mLimitUpper);
    nDDOIO::readData(in, pData->mLimitDowner);
    return true;
}

MT_CTSTR rSndPitchLimit::getExt() const {
    return "spl";
}

u32 rSndPitchLimit::getDataVersion() const {
    return 1;
}

inline rSndPitchLimit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSndPitchLimit::MyDTI rSndPitchLimit::DTI("rSndPitchLimit", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rSndPitchLimit::MyDTI::newInstance() const {
    return new (16u) rSndPitchLimit;
}

template cSndPitchLimitData* rTbl2<cSndPitchLimitData>::getData(unsigned int);

template bool rTbl2<cSndPitchLimitData>::load(MtStream&);

template bool rTbl2<cSndPitchLimitData>::loadCore(MtDataReader&);

template const cSndPitchLimitData* rTbl2<cSndPitchLimitData>::getData(unsigned int) const;

template unsigned int rTbl2<cSndPitchLimitData>::getDataNum() const;

template rTbl2<cSndPitchLimitData>::~rTbl2();

