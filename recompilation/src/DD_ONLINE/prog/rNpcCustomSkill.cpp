// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNpcCustomSkill.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cNpcCustomSkill::getDTI() const {
    return cNpcCustomSkill::DTI;
}

void cNpcCustomSkill::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "ThinkId", &mThinkId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CustomSkill1", &mCustomSkill1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Lv1", &mCustomSkillLv1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CustomSkill2", &mCustomSkill2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Lv2", &mCustomSkillLv2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CustomSkill3", &mCustomSkill3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Lv3", &mCustomSkillLv3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CustomSkill4", &mCustomSkill4, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Lv4", &mCustomSkillLv4, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NormalSkill", &mNormalSkillBit, 0u, 0u);
}

inline cNpcCustomSkill::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cNpcCustomSkill::MyDTI cNpcCustomSkill::DTI("cNpcCustomSkill", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cNpcCustomSkill::MyDTI::newInstance() const {
    return new (16u) cNpcCustomSkill;
}

const MtDTI& rNpcCustomSkill::getDTI() const {
    return rNpcCustomSkill::DTI;
}

bool rNpcCustomSkill::loadData(MtDataReader& in, cNpcCustomSkill* pData) {
    nDDOIO::readData(in, pData->mThinkId);
    nDDOIO::readData(in, pData->mCustomSkill1);
    nDDOIO::readData(in, pData->mCustomSkill2);
    nDDOIO::readData(in, pData->mCustomSkill3);
    nDDOIO::readData(in, pData->mCustomSkill4);
    nDDOIO::readData(in, pData->mCustomSkillLv1);
    nDDOIO::readData(in, pData->mCustomSkillLv2);
    nDDOIO::readData(in, pData->mCustomSkillLv3);
    nDDOIO::readData(in, pData->mCustomSkillLv4);
    nDDOIO::readData(in, pData->mNormalSkillBit);
    return true;
}

MT_CTSTR rNpcCustomSkill::getExt() const {
    return "ncs";
}

u32 rNpcCustomSkill::getDataVersion() const {
    return 5;
}

inline rNpcCustomSkill::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNpcCustomSkill::MyDTI rNpcCustomSkill::DTI("rNpcCustomSkill", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rNpcCustomSkill::MyDTI::newInstance() const {
    return new (16u) rNpcCustomSkill;
}

template cNpcCustomSkill* rTbl2<cNpcCustomSkill>::getData(unsigned int);

template bool rTbl2<cNpcCustomSkill>::load(MtStream&);

template bool rTbl2<cNpcCustomSkill>::loadCore(MtDataReader&);

template const cNpcCustomSkill* rTbl2<cNpcCustomSkill>::getData(unsigned int) const;

template unsigned int rTbl2<cNpcCustomSkill>::getDataNum() const;

template rTbl2<cNpcCustomSkill>::~rTbl2();

