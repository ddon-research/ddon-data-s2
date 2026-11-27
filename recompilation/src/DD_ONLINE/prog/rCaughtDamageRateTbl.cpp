// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCaughtDamageRateTbl.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCaughtDamageRate::getDTI() const {
    return cCaughtDamageRate::DTI;
}

void cCaughtDamageRate::createProperty(MtPropertyList& proplist) {
    proplist << MtProperty(static_cast<MtObject*>(this), "mDamageRate", &mDamageRate, 0u, 0u);
}

inline cCaughtDamageRate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCaughtDamageRate::MyDTI cCaughtDamageRate::DTI("cCaughtDamageRate", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCaughtDamageRate::MyDTI::newInstance() const {
    return new (16u) cCaughtDamageRate;
}

const MtDTI& rCaughtDamageRateTbl::getDTI() const {
    return rCaughtDamageRateTbl::DTI;
}

bool rCaughtDamageRateTbl::loadData(MtDataReader& in, cCaughtDamageRate* pData) {
    if (pData != nullptr) {
        pData->mDamageRate = in.readF32();
        return true;
    } else {
        return false;
    }
}

MT_CTSTR rCaughtDamageRateTbl::getExt() const {
    return "cdrt";
}

u32 rCaughtDamageRateTbl::getDataVersion() const {
    return 1;
}

inline rCaughtDamageRateTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCaughtDamageRateTbl::MyDTI rCaughtDamageRateTbl::DTI("rCaughtDamageRateTbl", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCaughtDamageRateTbl::MyDTI::newInstance() const {
    return new (16u) rCaughtDamageRateTbl;
}

template cCaughtDamageRate* rTbl2<cCaughtDamageRate>::getData(unsigned int);

template bool rTbl2<cCaughtDamageRate>::load(MtStream&);

template bool rTbl2<cCaughtDamageRate>::loadCore(MtDataReader&);

template const cCaughtDamageRate* rTbl2<cCaughtDamageRate>::getData(unsigned int) const;

template unsigned int rTbl2<cCaughtDamageRate>::getDataNum() const;

template rTbl2<cCaughtDamageRate>::~rTbl2();

