// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPushRate.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPushRate::getDTI() const {
    return cPushRate::DTI;
}

void cPushRate::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Small", &mRate[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Middle", &mRate[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Large", &mRate[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "VeryLarge", &mRate[3], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Player", &mRate[4], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NPC", &mRate[5], 0u, 0u);
}

inline cPushRate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPushRate::MyDTI cPushRate::DTI("cPushRate", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cPushRate::MyDTI::newInstance() const {
    return new (16u) cPushRate;
}

const MtDTI& rPushRate::getDTI() const {
    return rPushRate::DTI;
}

bool rPushRate::loadData(MtDataReader& in, cPushRate* pData) {
    pData->mRate[0] = in.readF32();
    pData->mRate[1] = in.readF32();
    pData->mRate[2] = in.readF32();
    pData->mRate[3] = in.readF32();
    pData->mRate[4] = in.readF32();
    pData->mRate[5] = in.readF32();
    return true;
}

MT_CTSTR rPushRate::getExt() const {
    return "push_rate";
}

u32 rPushRate::getDataVersion() const {
    return 256;
}

inline rPushRate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPushRate::MyDTI rPushRate::DTI("rPushRate", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rPushRate::MyDTI::newInstance() const {
    return new (16u) rPushRate;
}

template cPushRate* rTbl2<cPushRate>::getData(unsigned int);

template bool rTbl2<cPushRate>::load(MtStream&);

template bool rTbl2<cPushRate>::loadCore(MtDataReader&);

template const cPushRate* rTbl2<cPushRate>::getData(unsigned int) const;

template unsigned int rTbl2<cPushRate>::getDataNum() const;

template rTbl2<cPushRate>::~rTbl2();

