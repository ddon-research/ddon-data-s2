// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rShotReqInfo.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cShotReqInfo>::allocData(unsigned int);
#endif

const MtDTI& cShotReqInfo::getDTI() const {
    return cShotReqInfo::DTI;
}

void cShotReqInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mShotGroup", &mShotGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShotIndex", &mShotIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "対象", &mSetTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNo", &mJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "コンストする", &mIsConst, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetPos", &mOffsetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetDir", &mOffsetDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ロックオンする", &mIsLockOnTarget, 0u, 0u);
}

inline cShotReqInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShotReqInfo::MyDTI cShotReqInfo::DTI("cShotReqInfo", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* cShotReqInfo::MyDTI::newInstance() const {
    return new (16u) cShotReqInfo;
}

const MtDTI& rShotReqInfo::getDTI() const {
    return rShotReqInfo::DTI;
}

bool rShotReqInfo::loadData(MtDataReader& in, cShotReqInfo* pData) {
    nDDOIO::readData(in, pData->mShotGroup);
    nDDOIO::readData(in, pData->mShotIndex);
    nDDOIO::readData(in, pData->mSetTarget);
    nDDOIO::readData(in, pData->mJointNo);
    nDDOIO::readData(in, pData->mIsConst);
    pData->mOffsetPos = in.readV3();
    pData->mOffsetDir = in.readV3();
    nDDOIO::readData(in, pData->mIsLockOnTarget);
    return true;
}

MT_CTSTR rShotReqInfo::getExt() const {
    return "sri";
}

u32 rShotReqInfo::getDataVersion() const {
    return 9;
}

void rShotReqInfo::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

inline rShotReqInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rShotReqInfo::MyDTI rShotReqInfo::DTI("rShotReqInfo", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rShotReqInfo::MyDTI::newInstance() const {
    return new (16u) rShotReqInfo;
}

template cShotReqInfo* rTbl2<cShotReqInfo>::getData(unsigned int);

template bool rTbl2<cShotReqInfo>::load(MtStream&);

template bool rTbl2<cShotReqInfo>::loadCore(MtDataReader&);

template const cShotReqInfo* rTbl2<cShotReqInfo>::getData(unsigned int) const;

template unsigned int rTbl2<cShotReqInfo>::getDataNum() const;

template rTbl2<cShotReqInfo>::~rTbl2();

