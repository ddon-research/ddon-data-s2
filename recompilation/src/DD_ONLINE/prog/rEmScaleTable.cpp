// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmScaleTable.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmScaleTable::getDTI() const {
    return cEmScaleTable::DTI;
}

void cEmScaleTable::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mBoneNo", &mBoneNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrame", &mFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScale", &mScale, 0u, 0u);
}

inline cEmScaleTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmScaleTable::MyDTI cEmScaleTable::DTI("cEmScaleTable", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cEmScaleTable::MyDTI::newInstance() const {
    return new (16u) cEmScaleTable;
}

const MtDTI& rEmScaleTable::getDTI() const {
    return rEmScaleTable::DTI;
}

bool rEmScaleTable::loadData(MtDataReader& in, cEmScaleTable* pData) {
    pData->mBoneNo = in.readU32();
    pData->mFrame = in.readF32();
    pData->mScale = in.readV3();
    return true;
}

MT_CTSTR rEmScaleTable::getExt() const {
    return "esl";
}

u32 rEmScaleTable::getDataVersion() const {
    return 257;
}

inline rEmScaleTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmScaleTable::MyDTI rEmScaleTable::DTI("rEmScaleTable", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEmScaleTable::MyDTI::newInstance() const {
    return new (16u) rEmScaleTable;
}

template cEmScaleTable* rTbl2<cEmScaleTable>::getData(unsigned int);

template bool rTbl2<cEmScaleTable>::load(MtStream&);

template bool rTbl2<cEmScaleTable>::loadCore(MtDataReader&);

template const cEmScaleTable* rTbl2<cEmScaleTable>::getData(unsigned int) const;

template unsigned int rTbl2<cEmScaleTable>::getDataNum() const;

template rTbl2<cEmScaleTable>::~rTbl2();

