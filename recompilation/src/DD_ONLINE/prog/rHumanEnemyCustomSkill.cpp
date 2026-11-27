// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rHumanEnemyCustomSkill.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cHumanEnemyCustomSkill::getDTI() const {
    return cHumanEnemyCustomSkill::DTI;
}

inline cHumanEnemyCustomSkill::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanEnemyCustomSkill::MyDTI cHumanEnemyCustomSkill::DTI("cHumanEnemyCustomSkill", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cHumanEnemyCustomSkill::MyDTI::newInstance() const {
    return new (16u) cHumanEnemyCustomSkill;
}

const MtDTI& rHumanEnemyCustomSkill::getDTI() const {
    return rHumanEnemyCustomSkill::DTI;
}

bool rHumanEnemyCustomSkill::loadData(MtDataReader& r, cHumanEnemyCustomSkill* pData) {
    nDDOIO::readData(r, pData->mId);
    nDDOIO::readData(r, pData->mCustomSkill0);
    nDDOIO::readData(r, pData->mCustomSkill1);
    nDDOIO::readData(r, pData->mCustomSkill2);
    nDDOIO::readData(r, pData->mCustomSkill3);
    nDDOIO::readData(r, pData->mCustomLevel0);
    nDDOIO::readData(r, pData->mCustomLevel1);
    nDDOIO::readData(r, pData->mCustomLevel2);
    nDDOIO::readData(r, pData->mCustomLevel3);
    return true;
}

MT_CTSTR rHumanEnemyCustomSkill::getExt() const {
    return "hmcs";
}

u32 rHumanEnemyCustomSkill::getDataVersion() const {
    return 3;
}

inline rHumanEnemyCustomSkill::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rHumanEnemyCustomSkill::MyDTI rHumanEnemyCustomSkill::DTI("rHumanEnemyCustomSkill", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rHumanEnemyCustomSkill::MyDTI::newInstance() const {
    return new (16u) rHumanEnemyCustomSkill;
}

template cHumanEnemyCustomSkill* rTbl2<cHumanEnemyCustomSkill>::getData(unsigned int);

template bool rTbl2<cHumanEnemyCustomSkill>::load(MtStream&);

template bool rTbl2<cHumanEnemyCustomSkill>::loadCore(MtDataReader&);

template const cHumanEnemyCustomSkill* rTbl2<cHumanEnemyCustomSkill>::getData(unsigned int) const;

template unsigned int rTbl2<cHumanEnemyCustomSkill>::getDataNum() const;

template rTbl2<cHumanEnemyCustomSkill>::~rTbl2();

