// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundOptData.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSoundOptData::getDTI() const {
    return cSoundOptData::DTI;
}

void cSoundOptData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "大項目", &mCategory, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mItem", &mItem, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "チャンネル1", &mChannel[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "チャンネル2", &mChannel[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "チャンネル3", &mChannel[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "チャンネル4", &mChannel[3], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "チャンネル5", &mChannel[4], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "チャンネル6", &mChannel[5], 0u, 0u);
}

s32 cSoundOptData::getChannel(u32 index) {
    if (index <= 5u) {
        return mChannel[index];
    } else {
        return -1;
    }
}

inline cSoundOptData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundOptData::MyDTI cSoundOptData::DTI("cSoundOptData", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cSoundOptData::MyDTI::newInstance() const {
    return new (16u) cSoundOptData;
}

const MtDTI& rSoundOptData::getDTI() const {
    return rSoundOptData::DTI;
}

bool rSoundOptData::loadData(MtDataReader& in, cSoundOptData* pData) {
    nDDOIO::readData(in, pData->mCategory);
    nDDOIO::readData(in, pData->mItem);
    nDDOIO::readData(in, pData->mChannel[0]);
    nDDOIO::readData(in, pData->mChannel[1]);
    nDDOIO::readData(in, pData->mChannel[2]);
    nDDOIO::readData(in, pData->mChannel[3]);
    nDDOIO::readData(in, pData->mChannel[4]);
    nDDOIO::readData(in, pData->mChannel[5]);
    return true;
}

MT_CTSTR rSoundOptData::getExt() const {
    return "sot";
}

u32 rSoundOptData::getDataVersion() const {
    return 1;
}

inline rSoundOptData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundOptData::MyDTI rSoundOptData::DTI("rSoundOptData", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rSoundOptData::MyDTI::newInstance() const {
    return new (16u) rSoundOptData;
}

template cSoundOptData* rTbl2<cSoundOptData>::getData(unsigned int);

template bool rTbl2<cSoundOptData>::load(MtStream&);

template bool rTbl2<cSoundOptData>::loadCore(MtDataReader&);

template const cSoundOptData* rTbl2<cSoundOptData>::getData(unsigned int) const;

template unsigned int rTbl2<cSoundOptData>::getDataNum() const;

template rTbl2<cSoundOptData>::~rTbl2();

