// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPrologueHmStatus.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cPrologueHmStatus::getDTI() const {
    return cPrologueHmStatus::DTI;
}

inline cPrologueHmStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cPrologueHmStatus::MyDTI cPrologueHmStatus::DTI("cPrologueHmStatus", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cPrologueHmStatus::MyDTI::newInstance() const {
    return new (16u) cPrologueHmStatus;
}

const MtDTI& rPrologueHmStatus::getDTI() const {
    return rPrologueHmStatus::DTI;
}

__attribute__((weak)) bool rPrologueHmStatus::loadData(MtDataReader& in, cPrologueHmStatus* pData) {
        nDDOIO::readData(in, pData->mJob);
        nDDOIO::readData(in, pData->mLv);
        nDDOIO::readData(in, pData->mAtk);
        nDDOIO::readData(in, pData->mDef);
        nDDOIO::readData(in, pData->mMAtk);
        nDDOIO::readData(in, pData->mMDef);
        nDDOIO::readData(in, pData->mCustomId1);
        nDDOIO::readData(in, pData->mCustomId1Lv);
        nDDOIO::readData(in, pData->mCustomId2);
        nDDOIO::readData(in, pData->mCustomId2Lv);
        nDDOIO::readData(in, pData->mCustomId3);
        nDDOIO::readData(in, pData->mCustomId3Lv);
        nDDOIO::readData(in, pData->mCustomId4);
        nDDOIO::readData(in, pData->mCustomId4Lv);
        nDDOIO::readData(in, pData->mNormalId1);
        nDDOIO::readData(in, pData->mNormalId2);
        nDDOIO::readData(in, pData->mNormalId3);
        return true;
}

MT_CTSTR rPrologueHmStatus::getExt() const {
    return "phs";
}

u32 rPrologueHmStatus::getDataVersion() const {
    return 0;
}

inline rPrologueHmStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPrologueHmStatus::MyDTI rPrologueHmStatus::DTI("rPrologueHmStatus", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rPrologueHmStatus::MyDTI::newInstance() const {
    return new (16u) rPrologueHmStatus;
}

template cPrologueHmStatus* rTbl2<cPrologueHmStatus>::getData(unsigned int);

template bool rTbl2<cPrologueHmStatus>::load(MtStream&);

template bool rTbl2<cPrologueHmStatus>::loadCore(MtDataReader&);

template const cPrologueHmStatus* rTbl2<cPrologueHmStatus>::getData(unsigned int) const;

template unsigned int rTbl2<cPrologueHmStatus>::getDataNum() const;

template rTbl2<cPrologueHmStatus>::~rTbl2();

