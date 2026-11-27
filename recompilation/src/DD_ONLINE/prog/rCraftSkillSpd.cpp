// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCraftSkillSpd.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCraftSkillSpdData::getDTI() const {
    return cCraftSkillSpdData::DTI;
}

void cCraftSkillSpdData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "リーダー時短率", &mSpdRate1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "補助時短率", &mSpdRate2, 0u, 0u);
}

u32 cCraftSkillSpdData::getRate(u32 type) const {
    if (type == 1) {
        return mSpdRate2;
    } else {
        if (type == 0) {
            return mSpdRate1;
        } else {
            return 0;
        }
    }
}

inline cCraftSkillSpdData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCraftSkillSpdData::MyDTI cCraftSkillSpdData::DTI("cCraftSkillSpdData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cCraftSkillSpdData::MyDTI::newInstance() const {
    return new (16u) cCraftSkillSpdData;
}

const MtDTI& rCraftSkillSpd::getDTI() const {
    return rCraftSkillSpd::DTI;
}

bool rCraftSkillSpd::loadData(MtDataReader& in, cCraftSkillSpdData* pData) {
    nDDOIO::readData(in, pData->mSpdRate1);
    nDDOIO::readData(in, pData->mSpdRate2);
    return true;
}

MT_CTSTR rCraftSkillSpd::getExt() const {
    return "cks";
}

u32 rCraftSkillSpd::getDataVersion() const {
    return 3;
}

inline rCraftSkillSpd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCraftSkillSpd::MyDTI rCraftSkillSpd::DTI("rCraftSkillSpd", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCraftSkillSpd::MyDTI::newInstance() const {
    return new (16u) rCraftSkillSpd;
}

template cCraftSkillSpdData* rTbl2<cCraftSkillSpdData>::getData(unsigned int);

template bool rTbl2<cCraftSkillSpdData>::load(MtStream&);

template bool rTbl2<cCraftSkillSpdData>::loadCore(MtDataReader&);

template const cCraftSkillSpdData* rTbl2<cCraftSkillSpdData>::getData(unsigned int) const;

template unsigned int rTbl2<cCraftSkillSpdData>::getDataNum() const;

template rTbl2<cCraftSkillSpdData>::~rTbl2();

