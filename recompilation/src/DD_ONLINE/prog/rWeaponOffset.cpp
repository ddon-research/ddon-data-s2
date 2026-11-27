// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rWeaponOffset.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cWeaponOffset::getDTI() const {
    return cWeaponOffset::DTI;
}

inline cWeaponOffset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeaponOffset::MyDTI cWeaponOffset::DTI("cWeaponOffset", &::MtObject::DTI, 208ul, 0u, 0u);

MtObject* cWeaponOffset::MyDTI::newInstance() const {
    return new (16u) cWeaponOffset;
}

const MtDTI& rWeaponOffset::getDTI() const {
    return rWeaponOffset::DTI;
}

bool rWeaponOffset::loadData(MtDataReader& r, cWeaponOffset* pData) {
    pData->mConstType = r.readU32();
    pData->mJntNo = r.readS32();
    pData->mRot = r.readV3();
    pData->mOfs = r.readV3();
    pData->mFat = r.readF32();
    pData->mJntNoHold = r.readS32();
    pData->mRotHold = r.readV3();
    pData->mOfsHold = r.readV3();
    pData->mFatHold = r.readF32();
    pData->mJntNoDamage = r.readS32();
    pData->mRotDamage = r.readV3();
    pData->mOfsDamage = r.readV3();
    pData->mFatDamage = r.readF32();
    pData->mJntNoSpecial = r.readS32();
    pData->mRotSpecial = r.readV3();
    pData->mOfsSpecial = r.readV3();
    nDDOIO::readData(r, pData->mFatSpecial);
    return true;
}

MT_CTSTR rWeaponOffset::getExt() const {
    return "wpn_ofs";
}

u32 rWeaponOffset::getDataVersion() const {
    return 3;
}

inline rWeaponOffset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWeaponOffset::MyDTI rWeaponOffset::DTI("rWeaponOffset", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rWeaponOffset::MyDTI::newInstance() const {
    return new (16u) rWeaponOffset;
}

template cWeaponOffset* rTbl2<cWeaponOffset>::getData(unsigned int);

template bool rTbl2<cWeaponOffset>::load(MtStream&);

template bool rTbl2<cWeaponOffset>::loadCore(MtDataReader&);

template const cWeaponOffset* rTbl2<cWeaponOffset>::getData(unsigned int) const;

template unsigned int rTbl2<cWeaponOffset>::getDataNum() const;

template rTbl2<cWeaponOffset>::~rTbl2();

