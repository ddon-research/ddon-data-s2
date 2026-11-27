// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmDamageDirInfo.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmDamageDirInfo::getDTI() const {
    return cEmDamageDirInfo::DTI;
}

void cEmDamageDirInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\346\225\265\343\202\253\343\203\206\343\202\264\343\203\252\343\203\274", &mEmCategory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\252\343\202\242\343\202\257\343\202\267\343\203\247\343\203\263\343\202\277\343\202\244\343\203\227", &mDmReactionType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\226\271\345\220\221\345\210\244\345\256\232\343\202\277\343\202\244\343\203\227", &mDirJudgeType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\226\271\345\220\221\350\243\234\346\255\243\343\201\231\343\202\213", &mIsAdjustDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\351\207\215\351\207\217\350\243\234\346\255\243(XZ\350\273\270\346\226\271\345\220\221\351\200\237\345\272\246)", &mIsWeightSpeedXZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\351\207\215\351\207\217\350\243\234\346\255\243(XZ\350\273\270\346\226\271\345\220\221\346\270\233\351\200\237)", &mIsWeightSpeedY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\351\207\215\351\207\217\350\243\234\346\255\243(Y\350\273\270\346\226\271\345\220\221\351\200\237\345\272\246)", &mIsWeightAccXZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\351\207\215\351\207\217\350\243\234\346\255\243(Y\350\273\270\346\226\271\345\220\221\346\270\233\351\200\237)", &mIsWeightAccY, 0u, 0u);
}

inline cEmDamageDirInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmDamageDirInfo::MyDTI cEmDamageDirInfo::DTI("cEmDamageDirInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cEmDamageDirInfo::MyDTI::newInstance() const {
    return new (16u) cEmDamageDirInfo;
}

const MtDTI& rEmDamageDirInfo::getDTI() const {
    return rEmDamageDirInfo::DTI;
}

__attribute__((weak)) bool rEmDamageDirInfo::loadData(MtDataReader& in, cEmDamageDirInfo* pData) {
    nDDOIO::readData(in, pData->mEmCategory);
    nDDOIO::readData(in, pData->mDmReactionType);
    nDDOIO::readData(in, pData->mDirJudgeType);
    nDDOIO::readData(in, pData->mIsAdjustDir);
    nDDOIO::readData(in, pData->mIsWeightSpeedXZ);
    nDDOIO::readData(in, pData->mIsWeightSpeedY);
    nDDOIO::readData(in, pData->mIsWeightAccXZ);
    nDDOIO::readData(in, pData->mIsWeightAccY);
    return true;
}

MT_CTSTR rEmDamageDirInfo::getExt() const {
    return "edv";
}

u32 rEmDamageDirInfo::getDataVersion() const {
    return 2;
}

inline rEmDamageDirInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmDamageDirInfo::MyDTI rEmDamageDirInfo::DTI("rEmDamageDirInfo", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEmDamageDirInfo::MyDTI::newInstance() const {
    return new (16u) rEmDamageDirInfo;
}

template cEmDamageDirInfo* rTbl2<cEmDamageDirInfo>::getData(unsigned int);

template bool rTbl2<cEmDamageDirInfo>::load(MtStream&);

template bool rTbl2<cEmDamageDirInfo>::loadCore(MtDataReader&);

template const cEmDamageDirInfo* rTbl2<cEmDamageDirInfo>::getData(unsigned int) const;

template unsigned int rTbl2<cEmDamageDirInfo>::getDataNum() const;

template rTbl2<cEmDamageDirInfo>::~rTbl2();

