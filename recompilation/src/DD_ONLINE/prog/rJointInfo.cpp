// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rJointInfo.h"
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

const MtDTI& cJointInfo::getDTI() const {
    return cJointInfo::DTI;
}

void cJointInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mJntNo", &mJntNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttr", &mAttr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRadius", &mRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOfsPos", &mOfsPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointInfoID", &mJointInfoID, 0u, 0u);
}

inline cJointInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cJointInfo::MyDTI cJointInfo::DTI("cJointInfo", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cJointInfo::MyDTI::newInstance() const {
    return new (16u) cJointInfo;
}

const MtDTI& rJointInfo::getDTI() const {
    return rJointInfo::DTI;
}

bool rJointInfo::loadData(MtDataReader& in, cJointInfo* pData) {
    pData->mJntNo = in.readU16();
    pData->mAttr = in.readU16();
    pData->mRadius = in.readF32();
    pData->mOfsPos = in.readV3();
    nDDOIO::readData(in, pData->mJointInfoID);
    return true;
}

MT_CTSTR rJointInfo::getExt() const {
    return "jnt_info";
}

u32 rJointInfo::getDataVersion() const {
    return 259;
}

inline rJointInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rJointInfo::MyDTI rJointInfo::DTI("rJointInfo", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rJointInfo::MyDTI::newInstance() const {
    return new (16u) rJointInfo;
}

template cJointInfo* rTbl2<cJointInfo>::getData(unsigned int);

template bool rTbl2<cJointInfo>::load(MtStream&);

template bool rTbl2<cJointInfo>::loadCore(MtDataReader&);

template const cJointInfo* rTbl2<cJointInfo>::getData(unsigned int) const;

template unsigned int rTbl2<cJointInfo>::getDataNum() const;

template rTbl2<cJointInfo>::~rTbl2();

