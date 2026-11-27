// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmBaseInfoSv.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmBaseInfoSv::getDTI() const {
    return cEmBaseInfoSv::DTI;
}

inline cEmBaseInfoSv::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmBaseInfoSv::MyDTI cEmBaseInfoSv::DTI("cEmBaseInfoSv", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cEmBaseInfoSv::MyDTI::newInstance() const {
    return new (16u) cEmBaseInfoSv;
}

const MtDTI& rEmBaseInfoSv::getDTI() const {
    return rEmBaseInfoSv::DTI;
}

bool rEmBaseInfoSv::loadData(MtDataReader& r, cEmBaseInfoSv* pData) {
    nDDOIO::readData(r, pData->mEnemyID);
    nDDOIO::readData(r, pData->mEmCategory);
    return true;
}

MT_CTSTR rEmBaseInfoSv::getExt() const {
    return "ebi_sv";
}

u32 rEmBaseInfoSv::getDataVersion() const {
    return 8;
}

inline rEmBaseInfoSv::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmBaseInfoSv::MyDTI rEmBaseInfoSv::DTI("rEmBaseInfoSv", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEmBaseInfoSv::MyDTI::newInstance() const {
    return new (16u) rEmBaseInfoSv;
}

template cEmBaseInfoSv* rTbl2<cEmBaseInfoSv>::getData(unsigned int);

template bool rTbl2<cEmBaseInfoSv>::load(MtStream&);

template bool rTbl2<cEmBaseInfoSv>::loadCore(MtDataReader&);

template const cEmBaseInfoSv* rTbl2<cEmBaseInfoSv>::getData(unsigned int) const;

template unsigned int rTbl2<cEmBaseInfoSv>::getDataNum() const;

template rTbl2<cEmBaseInfoSv>::~rTbl2();

