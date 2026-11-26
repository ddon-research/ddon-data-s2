// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCollGeom.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cCollGeom>::allocData(unsigned int);
#endif

const MtDTI& cCollGeom::getDTI() const {
    return cCollGeom::DTI;
}

inline void cCollGeom::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCollGeom::DTI)->memFree(p_addr);
}

void cCollGeom::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsUseData", &mIsUseData, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShape", &mShape, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRadius", &mRadius, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mExtent", &mExtent, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJnt0", &mJnt0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJnt1", &mJnt1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffset0", &mOffset0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffset1", &mOffset1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOption", &mOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScaleOption", &mScaleOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRegionNo", &mRegionNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLayer", &mLayer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRangeCheckBaseJnt", &mRangeCheckBaseJnt, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAngle0", &mAngle0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAngle1", &mAngle1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 1u, 0u);
}

inline cCollGeom::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCollGeom::MyDTI cCollGeom::DTI("cCollGeom", &::MtObject::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* cCollGeom::MyDTI::newInstance() const {
    return new (16u) cCollGeom;
}

const MtDTI& rCollGeom::getDTI() const {
    return rCollGeom::DTI;
}

inline MtAllocator* rCollGeom::getAllocator() {
    return MtMemoryAllocator::getAllocator(rCollGeom::DTI);
}

void* rCollGeom::operator new(size_t sz, u32 align) {
    return rCollGeom::getAllocator()->memAlloc(sz, align, rCollGeom::DTI.getID());
}

inline void rCollGeom::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rCollGeom::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool rCollGeom::loadData(MtDataReader& in, cCollGeom* pData) {
    nDDOIO::readData(in, pData->mShape);
    nDDOIO::readData(in, pData->mOption);
    nDDOIO::readData(in, pData->mScaleOption);
    nDDOIO::readData(in, pData->mPriority);
    nDDOIO::readData(in, pData->mLayer);
    nDDOIO::readData(in, pData->mDmy0);
    nDDOIO::readData(in, pData->mIndex);
    nDDOIO::readData(in, pData->mJnt0);
    nDDOIO::readData(in, pData->mJnt1);
    nDDOIO::readData(in, pData->mRegionNo);
    nDDOIO::readData(in, pData->mRangeCheckBaseJnt);
    nDDOIO::readData(in, pData->mRadius);
    pData->mAngle0.x = in.readF32();
    pData->mAngle0.y = in.readF32();
    pData->mAngle1.x = in.readF32();
    pData->mAngle1.y = in.readF32();
    pData->mOffset0 = in.readV3();
    pData->mOffset1 = in.readV3();
    pData->mExtent = in.readV3();
    nDDOIO::readData(in, pData->mIsUseData);
    return true;
}

MT_CTSTR rCollGeom::getExt() const {
    return "coll_geom";
}

u32 rCollGeom::getDataVersion() const {
    return 110;
}

inline rCollGeom::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCollGeom::MyDTI rCollGeom::DTI("rCollGeom", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCollGeom::MyDTI::newInstance() const {
    return new (16u) rCollGeom;
}

template cCollGeom* rTbl2<cCollGeom>::getData(unsigned int);

template bool rTbl2<cCollGeom>::load(MtStream&);

template bool rTbl2<cCollGeom>::loadCore(MtDataReader&);

template const cCollGeom* rTbl2<cCollGeom>::getData(unsigned int) const;

template unsigned int rTbl2<cCollGeom>::getDataNum() const;

template rTbl2<cCollGeom>::~rTbl2();

