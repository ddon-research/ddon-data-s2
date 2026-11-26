// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rStageMap.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cStageMap>::deleteData();
#endif

const MtDTI& cStageMap::getDTI() const {
    return cStageMap::DTI;
}

inline void cStageMap::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cStageMap::DTI)->memFree(p_addr);
}

cStageMap::~cStageMap() {
    if (mParamList.mLength != 0) {
        u32 v0_0 = mParamList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mParamList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mParamList.mpArray[i0_3];
                v1_0 = mParamList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mParamList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mParamList.mpArray));
    }
    mParamList.mpArray = nullptr;
    mParamList.mBufsiz = 0;
    mParamList.mLength = 0;
}

void cStageMap::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPartsNum", &mPartsNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetY", &mOffsetY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStageFlag", &mStageFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParamList", static_cast<MtObject*>(&mParamList), 0u, 0u);
}

inline cStageMap::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStageMap::MyDTI cStageMap::DTI("cStageMap", &::MtObject::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cStageMap::MyDTI::newInstance() const {
    return new (16u) cStageMap;
}

const MtDTI& cStageMap::cParam::getDTI() const {
    return cStageMap::cParam::DTI;
}

inline void* cStageMap::cParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cStageMap::cParam::DTI)->memAlloc(sz, align, cStageMap::cParam::DTI.getID());
}

inline cStageMap::cParam::cParam() {
    mAreaNo = 0;
    mSize = 0.0f;
    mConnectPos.x = MtVector3::Zero.x;
    mConnectPos.y = MtVector3::Zero.y;
    mConnectPos.z = MtVector3::Zero.z;
    mConnectPos.pad_ = 0.0f;
}

void cStageMap::cParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaNo", &mAreaNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSize", &mSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mModelName", &mModelName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConnectPos", &mConnectPos, 0u, 0u);
}

__attribute__((weak)) bool cStageMap::cParam::load(MtDataReader& r) {
    nDDOIO::readData(r, mAreaNo);
    nDDOIO::readData(r, mSize);
    nDDOIO::readData(r, mModelName);
    nDDOIO::readData(r, mConnectPos);
    return true;
}

inline cStageMap::cParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStageMap::cParam::MyDTI cStageMap::cParam::DTI("cStageMap::cParam", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cStageMap::cParam::MyDTI::newInstance() const {
    return new (16u) cStageMap::cParam;
}

const MtDTI& rStageMap::getDTI() const {
    return rStageMap::DTI;
}

inline void* rStageMap::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStageMap::DTI)->memAlloc(sz, align, rStageMap::DTI.getID());
}

inline void rStageMap::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rStageMap::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool rStageMap::loadData(MtDataReader& in, cStageMap* pData) {
    if (pData == nullptr) {
        return false;
    }
    nDDOIO::readData(in, pData->mStageNo);
    nDDOIO::readData(in, pData->mPartsNum);
    nDDOIO::readData(in, pData->mOffsetY);
    nDDOIO::readData(in, pData->mStageFlag);
    const u32 nArray = in.readU32();
    for (u32 i = 0; i < nArray; i++) {
        cStageMap::cParam* p = new (16u) cStageMap::cParam;
        if (p != nullptr) {
            p->load(in);
            pData->addParam(p);
        }
    }
    return true;
}

MT_CTSTR rStageMap::getExt() const {
    return "smp";
}

u32 rStageMap::getDataVersion() const {
    return 1;
}

bool rStageMap::isField(u32 stageNo) {
    u32 t0 = getDataNum();
    unsigned int i3 = 0;
    if (t0 != 0) {
        do {
            cStageMap* data = getData(i3);
            if (data != nullptr) {
                if (data->mStageNo == stageNo) {
                    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(data) + 16)) & 2) >> 1);
                }
            }
            i3 += 1u;
        } while (i3 < t0);
    }
    return false;
}

bool rStageMap::isPartsStage(u32 stageNo) {
    u32 t0 = getDataNum();
    unsigned int i3 = 0;
    if (t0 != 0) {
        do {
            cStageMap* data = getData(i3);
            if (data != nullptr) {
                if (data->mStageNo == stageNo) {
                    return (data->mStageFlag & 12u) != 0;
                }
            }
            i3 += 1u;
        } while (i3 < t0);
    }
    return false;
}

__attribute__((weak)) u32 rStageMap::getPartsNum(u32 stageNo) {
    DDON_STUB("rStageMap::getPartsNum")
    return {};
}

__attribute__((weak)) f32 rStageMap::getPartsSizeZLength(u32 stageNo, u32 uIdx) {
    DDON_STUB("rStageMap::getPartsSizeZLength")
    return {};
}

__attribute__((weak)) f32 rStageMap::getPartsOffsetY(u32 stageNo, u32 uIdx) {
    DDON_STUB("rStageMap::getPartsOffsetY")
    return {};
}

__attribute__((weak)) MT_CTSTR rStageMap::getPartsFileName(u32 stageNo, u32 uIdx) {
    DDON_STUB("rStageMap::getPartsFileName")
    return {};
}

__attribute__((weak)) MtVector3 rStageMap::getPartsConnectPos(u32 stageNo, u32 uIdx) {
    DDON_STUB("rStageMap::getPartsConnectPos")
    __builtin_unreachable();
}

inline rStageMap::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageMap::MyDTI rStageMap::DTI("rStageMap", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rStageMap::MyDTI::newInstance() const {
    return new (16u) rStageMap;
}

template MtTypedArray<cStageMap::cParam>::~MtTypedArray();

template cStageMap* rTbl2<cStageMap>::getData(unsigned int);

template bool rTbl2<cStageMap>::load(MtStream&);

template bool rTbl2<cStageMap>::loadCore(MtDataReader&);

template const cStageMap* rTbl2<cStageMap>::getData(unsigned int) const;

template unsigned int rTbl2<cStageMap>::getDataNum() const;

template rTbl2<cStageMap>::~rTbl2();

