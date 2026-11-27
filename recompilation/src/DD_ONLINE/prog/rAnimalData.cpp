// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rAnimalData.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cAnimalData>::allocData(unsigned int);
#endif

const MtDTI& cAnimalData::getDTI() const {
    return cAnimalData::DTI;
}

cAnimalData::~cAnimalData() {
}

void cAnimalData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAngle", &mAngle, 0u, 0u);
}

inline cAnimalData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAnimalData::MyDTI cAnimalData::DTI("cAnimalData", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cAnimalData::MyDTI::newInstance() const {
    return new (16u) cAnimalData;
}

const MtDTI& rAnimalData::getDTI() const {
    return rAnimalData::DTI;
}

bool rAnimalData::loadData(MtDataReader& in, cAnimalData* pData) {
    if (pData != nullptr) {
        pData->mPos = in.readV3();
        pData->mAngle = in.readV3();
        return true;
    } else {
        return false;
    }
}

MT_CTSTR rAnimalData::getExt() const {
    return "aml";
}

u32 rAnimalData::getDataVersion() const {
    return 0;
}

inline rAnimalData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAnimalData::MyDTI rAnimalData::DTI("rAnimalData", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rAnimalData::MyDTI::newInstance() const {
    return new (16u) rAnimalData;
}

template cAnimalData* rTbl2<cAnimalData>::getData(unsigned int);

template bool rTbl2<cAnimalData>::load(MtStream&);

template bool rTbl2<cAnimalData>::loadCore(MtDataReader&);

template const cAnimalData* rTbl2<cAnimalData>::getData(unsigned int) const;

template unsigned int rTbl2<cAnimalData>::getDataNum() const;

template rTbl2<cAnimalData>::~rTbl2();

