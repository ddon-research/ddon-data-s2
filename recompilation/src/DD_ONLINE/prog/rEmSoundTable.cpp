// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmSoundTable.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmSoundTable::getDTI() const {
    return cEmSoundTable::DTI;
}

void cEmSoundTable::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIdx", &mIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDieIsNoCall", &mDieIsNoCall, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSoundResNo", &mSoundResNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSoundNo", &mSoundNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttachFlag", &mAttachFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRequestType", &mRequestType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBoneNo", &mBoneNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetPos", &mOffsetPos, 0u, 0u);
}

inline cEmSoundTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmSoundTable::MyDTI cEmSoundTable::DTI("cEmSoundTable", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cEmSoundTable::MyDTI::newInstance() const {
    return new (16u) cEmSoundTable;
}

const MtDTI& rEmSoundTable::getDTI() const {
    return rEmSoundTable::DTI;
}

bool rEmSoundTable::loadData(MtDataReader& in, cEmSoundTable* pData) {
    nDDOIO::readData(in, pData->mIdx);
    nDDOIO::readData(in, pData->mSoundResNo);
    nDDOIO::readData(in, pData->mSoundNo);
    nDDOIO::readData(in, pData->mAttachFlag);
    pData->mRequestType = in.readU32();
    pData->mBoneNo = in.readS32();
    pData->mOffsetPos = in.readV3();
    nDDOIO::readData(in, pData->mDieIsNoCall);
    return true;
}

MT_CTSTR rEmSoundTable::getExt() const {
    return "esn";
}

u32 rEmSoundTable::getDataVersion() const {
    return 261;
}

inline rEmSoundTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmSoundTable::MyDTI rEmSoundTable::DTI("rEmSoundTable", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEmSoundTable::MyDTI::newInstance() const {
    return new (16u) rEmSoundTable;
}

template cEmSoundTable* rTbl2<cEmSoundTable>::getData(unsigned int);

template bool rTbl2<cEmSoundTable>::load(MtStream&);

template bool rTbl2<cEmSoundTable>::loadCore(MtDataReader&);

template const cEmSoundTable* rTbl2<cEmSoundTable>::getData(unsigned int) const;

template unsigned int rTbl2<cEmSoundTable>::getDataNum() const;

template rTbl2<cEmSoundTable>::~rTbl2();

