// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCraftSkillCost.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCraftSkillCostData::getDTI() const {
    return cCraftSkillCostData::DTI;
}

void cCraftSkillCostData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "スキル合計", &mTotal, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "削減率(１人)", &mCostRate1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "削減率(２人)", &mCostRate2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "削減率(３人)", &mCostRate3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "削減率(４人)", &mCostRate4, 0u, 0u);
}

f32 cCraftSkillCostData::getRate(u32 num) {
    switch (num - 1u) {
        case 0:
        {
            return mCostRate1;
        }
        case 1:
        {
            return mCostRate2;
        }
        case 2:
        {
            return mCostRate3;
        }
        case 3:
        {
            return mCostRate4;
        }
        default:
        {
            return 0.0f;
        }
    }
}

inline cCraftSkillCostData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCraftSkillCostData::MyDTI cCraftSkillCostData::DTI("cCraftSkillCostData", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cCraftSkillCostData::MyDTI::newInstance() const {
    return new (16u) cCraftSkillCostData;
}

const MtDTI& rCraftSkillCost::getDTI() const {
    return rCraftSkillCost::DTI;
}

bool rCraftSkillCost::loadData(MtDataReader& in, cCraftSkillCostData* pData) {
    nDDOIO::readData(in, pData->mTotal);
    nDDOIO::readData(in, pData->mCostRate1);
    nDDOIO::readData(in, pData->mCostRate2);
    nDDOIO::readData(in, pData->mCostRate3);
    nDDOIO::readData(in, pData->mCostRate4);
    return true;
}

MT_CTSTR rCraftSkillCost::getExt() const {
    return "ckc";
}

u32 rCraftSkillCost::getDataVersion() const {
    return 2;
}

inline rCraftSkillCost::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCraftSkillCost::MyDTI rCraftSkillCost::DTI("rCraftSkillCost", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCraftSkillCost::MyDTI::newInstance() const {
    return new (16u) rCraftSkillCost;
}

template cCraftSkillCostData* rTbl2<cCraftSkillCostData>::getData(unsigned int);

template bool rTbl2<cCraftSkillCostData>::load(MtStream&);

template bool rTbl2<cCraftSkillCostData>::loadCore(MtDataReader&);

template const cCraftSkillCostData* rTbl2<cCraftSkillCostData>::getData(unsigned int) const;

template unsigned int rTbl2<cCraftSkillCostData>::getDataNum() const;

template rTbl2<cCraftSkillCostData>::~rTbl2();

