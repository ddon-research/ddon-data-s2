// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rHumanEnemyEquip.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cHumanEnemyEquip::getDTI() const {
    return cHumanEnemyEquip::DTI;
}

inline cHumanEnemyEquip::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHumanEnemyEquip::MyDTI cHumanEnemyEquip::DTI("cHumanEnemyEquip", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* cHumanEnemyEquip::MyDTI::newInstance() const {
    return new (16u) cHumanEnemyEquip;
}

const MtDTI& rHumanEnemyEquip::getDTI() const {
    return rHumanEnemyEquip::DTI;
}

bool rHumanEnemyEquip::loadData(MtDataReader& r, cHumanEnemyEquip* pData) {
    nDDOIO::readData(r, pData->mId);
    nDDOIO::readData(r, pData->mMainWeaponId);
    nDDOIO::readData(r, pData->mSubWeaponId);
    nDDOIO::readData(r, pData->mWearTopId);
    nDDOIO::readData(r, pData->mWearBottomId);
    nDDOIO::readData(r, pData->mHeadId);
    nDDOIO::readData(r, pData->mArmorId);
    nDDOIO::readData(r, pData->mHandId);
    nDDOIO::readData(r, pData->mLegId);
    nDDOIO::readData(r, pData->mAccessoryId);
    nDDOIO::readData(r, pData->mJewelry);
    return true;
}

MT_CTSTR rHumanEnemyEquip::getExt() const {
    return "hmeq";
}

u32 rHumanEnemyEquip::getDataVersion() const {
    return 3;
}

inline rHumanEnemyEquip::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rHumanEnemyEquip::MyDTI rHumanEnemyEquip::DTI("rHumanEnemyEquip", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rHumanEnemyEquip::MyDTI::newInstance() const {
    return new (16u) rHumanEnemyEquip;
}

template cHumanEnemyEquip* rTbl2<cHumanEnemyEquip>::getData(unsigned int);

template bool rTbl2<cHumanEnemyEquip>::load(MtStream&);

template bool rTbl2<cHumanEnemyEquip>::loadCore(MtDataReader&);

template const cHumanEnemyEquip* rTbl2<cHumanEnemyEquip>::getData(unsigned int) const;

template unsigned int rTbl2<cHumanEnemyEquip>::getDataNum() const;

template rTbl2<cHumanEnemyEquip>::~rTbl2();

