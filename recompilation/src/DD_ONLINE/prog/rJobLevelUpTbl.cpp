// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rJobLevelUpTbl.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cIncreaseParam2::getDTI() const {
    return cIncreaseParam2::DTI;
}

void cIncreaseParam2::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mLv", &mLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAtk", &mAtk, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDef", &mDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMAtk", &mMAtk, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMDef", &mMDef, 0u, 0u);
}

inline cIncreaseParam2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cIncreaseParam2::MyDTI cIncreaseParam2::DTI("cIncreaseParam2", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cIncreaseParam2::MyDTI::newInstance() const {
    return new (16u) cIncreaseParam2;
}

const MtDTI& rJobLevelUpTbl2::getDTI() const {
    return rJobLevelUpTbl2::DTI;
}

bool rJobLevelUpTbl2::loadData(MtDataReader& in, cIncreaseParam2* pData) {
    if (pData != nullptr) {
        pData->mLv = in.readU32();
        pData->mAtk = in.readU32();
        pData->mDef = in.readU32();
        pData->mMAtk = in.readU32();
        pData->mMDef = in.readU32();
        return true;
    } else {
        return false;
    }
}

MT_CTSTR rJobLevelUpTbl2::getExt() const {
    return "jlt2";
}

u32 rJobLevelUpTbl2::getDataVersion() const {
    return 1;
}

inline rJobLevelUpTbl2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rJobLevelUpTbl2::MyDTI rJobLevelUpTbl2::DTI("rJobLevelUpTbl2", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rJobLevelUpTbl2::MyDTI::newInstance() const {
    return new (16u) rJobLevelUpTbl2;
}

template cIncreaseParam2* rTbl2<cIncreaseParam2>::getData(unsigned int);

template bool rTbl2<cIncreaseParam2>::load(MtStream&);

template bool rTbl2<cIncreaseParam2>::loadCore(MtDataReader&);

template const cIncreaseParam2* rTbl2<cIncreaseParam2>::getData(unsigned int) const;

template unsigned int rTbl2<cIncreaseParam2>::getDataNum() const;

template rTbl2<cIncreaseParam2>::~rTbl2();

