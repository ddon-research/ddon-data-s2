// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rAchievement.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "cUIObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAchievementData::getDTI() const {
    return cAchievementData::DTI;
}

inline cAchievementData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAchievementData::MyDTI cAchievementData::DTI("cAchievementData", &::cUIResource::DTI, 24ul, 0u, 0u);

MtObject* cAchievementData::MyDTI::newInstance() const {
    return new (16u) cAchievementData;
}

const MtDTI& cAchievementHeaderData::getDTI() const {
    return cAchievementHeaderData::DTI;
}

inline cAchievementHeaderData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAchievementHeaderData::MyDTI cAchievementHeaderData::DTI("cAchievementHeaderData", &::cUIResource::DTI, 16ul, 0u, 0u);

MtObject* cAchievementHeaderData::MyDTI::newInstance() const {
    return new (16u) cAchievementHeaderData;
}

const MtDTI& rAchievement::getDTI() const {
    return rAchievement::DTI;
}

bool rAchievement::loadData(MtDataReader& in, cAchievementData* pData) {
    nDDOIO::readData(in, pData->mID);
    nDDOIO::readData(in, pData->mTargetNum);
    nDDOIO::readData(in, pData->mMessageIndex);
    nDDOIO::readData(in, pData->mCategory);
    pData->mTrophy = in.readU8();
    return true;
}

MT_CTSTR rAchievement::getExt() const {
    return "acv";
}

u32 rAchievement::getDataVersion() const {
    return 2;
}

inline rAchievement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAchievement::MyDTI rAchievement::DTI("rAchievement", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rAchievement::MyDTI::newInstance() const {
    return new (16u) rAchievement;
}

const MtDTI& rAchievementHeader::getDTI() const {
    return rAchievementHeader::DTI;
}

bool rAchievementHeader::loadData(MtDataReader& in, cAchievementHeaderData* pData) {
    nDDOIO::readData(in, pData->mNum);
    return true;
}

MT_CTSTR rAchievementHeader::getExt() const {
    return "ach";
}

u32 rAchievementHeader::getDataVersion() const {
    return 3;
}

inline rAchievementHeader::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAchievementHeader::MyDTI rAchievementHeader::DTI("rAchievementHeader", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rAchievementHeader::MyDTI::newInstance() const {
    return new (16u) rAchievementHeader;
}

template cAchievementData* rTbl2<cAchievementData>::getData(unsigned int);

template cAchievementHeaderData* rTbl2<cAchievementHeaderData>::getData(unsigned int);

template bool rTbl2<cAchievementData>::load(MtStream&);

template bool rTbl2<cAchievementHeaderData>::load(MtStream&);

template bool rTbl2<cAchievementData>::loadCore(MtDataReader&);

template bool rTbl2<cAchievementHeaderData>::loadCore(MtDataReader&);

template const cAchievementData* rTbl2<cAchievementData>::getData(unsigned int) const;

template const cAchievementHeaderData* rTbl2<cAchievementHeaderData>::getData(unsigned int) const;

template unsigned int rTbl2<cAchievementData>::getDataNum() const;

template unsigned int rTbl2<cAchievementHeaderData>::getDataNum() const;

template rTbl2<cAchievementData>::~rTbl2();

template rTbl2<cAchievementHeaderData>::~rTbl2();

