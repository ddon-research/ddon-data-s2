// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rLargeCameraParam.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cLargeCameraParam::getDTI() const {
    return cLargeCameraParam::DTI;
}

void cLargeCameraParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "EmId", &mEmId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Range1", &mRange1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Range2", &mRange2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Camera", &mCamera, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Group", &mGroup, 0u, 0u);
}

inline cLargeCameraParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cLargeCameraParam::MyDTI cLargeCameraParam::DTI("cLargeCameraParam", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cLargeCameraParam::MyDTI::newInstance() const {
    return new (16u) cLargeCameraParam;
}

const MtDTI& rLargeCameraParam::getDTI() const {
    return rLargeCameraParam::DTI;
}

bool rLargeCameraParam::loadData(MtDataReader& in, cLargeCameraParam* pData) {
    nDDOIO::readData(in, pData->mEmId);
    nDDOIO::readData(in, pData->mRange1);
    nDDOIO::readData(in, pData->mRange2);
    nDDOIO::readData(in, pData->mCamera);
    nDDOIO::readData(in, pData->mGroup);
    return true;
}

MT_CTSTR rLargeCameraParam::getExt() const {
    return "lcp";
}

u32 rLargeCameraParam::getDataVersion() const {
    return 3;
}

inline rLargeCameraParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rLargeCameraParam::MyDTI rLargeCameraParam::DTI("rLargeCameraParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rLargeCameraParam::MyDTI::newInstance() const {
    return new (16u) rLargeCameraParam;
}

template cLargeCameraParam* rTbl2<cLargeCameraParam>::getData(unsigned int);

template bool rTbl2<cLargeCameraParam>::load(MtStream&);

template bool rTbl2<cLargeCameraParam>::loadCore(MtDataReader&);

template const cLargeCameraParam* rTbl2<cLargeCameraParam>::getData(unsigned int) const;

template unsigned int rTbl2<cLargeCameraParam>::getDataNum() const;

template rTbl2<cLargeCameraParam>::~rTbl2();

