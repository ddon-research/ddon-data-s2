// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rHumanEnemyPreset.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cHumanEnemyPreset::getDTI() const {
    return cHumanEnemyPreset::DTI;
}

inline cHumanEnemyPreset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanEnemyPreset::MyDTI cHumanEnemyPreset::DTI("cHumanEnemyPreset", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cHumanEnemyPreset::MyDTI::newInstance() const {
    return new (16u) cHumanEnemyPreset;
}

const MtDTI& rHumanEnemyPreset::getDTI() const {
    return rHumanEnemyPreset::DTI;
}

bool rHumanEnemyPreset::loadData(MtDataReader& r, cHumanEnemyPreset* pData) {
    nDDOIO::readData(r, pData->mId);
    nDDOIO::readData(r, pData->mCustomSkillListId);
    nDDOIO::readData(r, pData->mEquipListId);
    nDDOIO::readData(r, pData->mEditType);
    nDDOIO::readData(r, pData->mIsDisableMontageRandam);
    pData->mIsDisableBeginBattleVoice = r.readU8() != 0;
    pData->mIsOriginalCustomSkillArc = r.readU8() != 0;
    return true;
}

MT_CTSTR rHumanEnemyPreset::getExt() const {
    return "hmpre";
}

u32 rHumanEnemyPreset::getDataVersion() const {
    return 7;
}

inline rHumanEnemyPreset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rHumanEnemyPreset::MyDTI rHumanEnemyPreset::DTI("rHumanEnemyPreset", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rHumanEnemyPreset::MyDTI::newInstance() const {
    return new (16u) rHumanEnemyPreset;
}

template cHumanEnemyPreset* rTbl2<cHumanEnemyPreset>::getData(unsigned int);

template bool rTbl2<cHumanEnemyPreset>::load(MtStream&);

template bool rTbl2<cHumanEnemyPreset>::loadCore(MtDataReader&);

template const cHumanEnemyPreset* rTbl2<cHumanEnemyPreset>::getData(unsigned int) const;

template unsigned int rTbl2<cHumanEnemyPreset>::getDataNum() const;

template rTbl2<cHumanEnemyPreset>::~rTbl2();

