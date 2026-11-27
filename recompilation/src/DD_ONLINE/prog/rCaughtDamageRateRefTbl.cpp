// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCaughtDamageRateRefTbl.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCaughtDamageRateReference::getDTI() const {
    return cCaughtDamageRateReference::DTI;
}

void cCaughtDamageRateReference::createProperty(MtPropertyList& proplist) {
    proplist << MtProperty(static_cast<MtObject*>(this), "mReferenceIndex", &mReferenceIndex, 0u, 0u);
}

inline cCaughtDamageRateReference::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCaughtDamageRateReference::MyDTI cCaughtDamageRateReference::DTI("cCaughtDamageRateReference", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCaughtDamageRateReference::MyDTI::newInstance() const {
    return new (16u) cCaughtDamageRateReference;
}

const MtDTI& rCaughtDamageRateRefTbl::getDTI() const {
    return rCaughtDamageRateRefTbl::DTI;
}

bool rCaughtDamageRateRefTbl::loadData(MtDataReader& in, cCaughtDamageRateReference* pData) {
    if (pData != nullptr) {
        pData->mReferenceIndex = in.readU32();
        return true;
    } else {
        return false;
    }
}

MT_CTSTR rCaughtDamageRateRefTbl::getExt() const {
    return "cdrr";
}

u32 rCaughtDamageRateRefTbl::getDataVersion() const {
    return 1;
}

inline rCaughtDamageRateRefTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCaughtDamageRateRefTbl::MyDTI rCaughtDamageRateRefTbl::DTI("rCaughtDamageRateRefTbl", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCaughtDamageRateRefTbl::MyDTI::newInstance() const {
    return new (16u) rCaughtDamageRateRefTbl;
}

template cCaughtDamageRateReference* rTbl2<cCaughtDamageRateReference>::getData(unsigned int);

template bool rTbl2<cCaughtDamageRateReference>::load(MtStream&);

template bool rTbl2<cCaughtDamageRateReference>::loadCore(MtDataReader&);

template const cCaughtDamageRateReference* rTbl2<cCaughtDamageRateReference>::getData(unsigned int) const;

template unsigned int rTbl2<cCaughtDamageRateReference>::getDataNum() const;

template rTbl2<cCaughtDamageRateReference>::~rTbl2();

