// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rFieldAreaAdjoinList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rFieldAreaAdjoinList::getDTI() const {
    return rFieldAreaAdjoinList::DTI;
}

inline void* rFieldAreaAdjoinList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::DTI)->memAlloc(sz, align, rFieldAreaAdjoinList::DTI.getID());
}

inline void rFieldAreaAdjoinList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::DTI)->memFree(p_addr);
}

s16 rFieldAreaAdjoinList::getFieldAreaId() const {
    return mFieldAreaId;
}

rFieldAreaAdjoinList::cAdjoinInfo* rFieldAreaAdjoinList::getNextStageAdjoinInfo(s32 destinationStageNo, u8 priority) const {
    u32 v0_4 = mArrayNum;
    cAdjoinInfo* v3_0;
    if (v0_4 == 0) {
        v3_0 = nullptr;
    } else {
        cAdjoinInfo* v0_3 = mpArray;
        u32 i = 0;
        for (cAdjoinInfo* p0_2 = v0_3;;) {
            if (destinationStageNo == static_cast<int>(p0_2->mDestinationStageNo)) {
                if (p0_2->mPriority == priority) {
                    v3_0 = &v0_3[i];
                    return v3_0;
                }
            }
            if ((i + 1u) < v0_4) {
                i = i + 1u;
                p0_2 += 1;
            } else {
                break;
            }
        }
        v3_0 = nullptr;
    }
    return v3_0;
}

__attribute__((weak)) u32 rFieldAreaAdjoinList::getNextStageAdjoinInfoNum(s32 destinationStageNo) const {
    DDON_STUB("rFieldAreaAdjoinList::getNextStageAdjoinInfoNum")
    return {};
}

MT_CTSTR rFieldAreaAdjoinList::getExt() const {
    return "faa";
}

inline rFieldAreaAdjoinList::rFieldAreaAdjoinList() {
    mpArray = nullptr;
    mArrayNum = 0;
    mFieldAreaId = -1;
    setAttribute(22u);
}

rFieldAreaAdjoinList::~rFieldAreaAdjoinList() {
    if (mpArray == nullptr) {
        return;
    }
    if (mArrayNum == 0) {
        MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::DTI)->memFree(static_cast<void*>(mpArray));
        mpArray = nullptr;
        mArrayNum = 0;
        return;
    }
    mpArray->~cAdjoinInfo();
    if (mArrayNum <= 1u) {
        MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::DTI)->memFree(static_cast<void*>(mpArray));
        mpArray = nullptr;
        mArrayNum = 0;
        return;
    }
    unsigned int i3 = 1;
    do {
        mpArray[i3].~cAdjoinInfo();
        i3 += 1u;
    } while (i3 < mArrayNum);
    MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

__attribute__((weak)) bool rFieldAreaAdjoinList::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    u32 header = r.readU32();
    if (header != 0x414146u) {
        return false;
    }
    u32 dataVersion = r.readU32();
    if (dataVersion != 2u) {
        return false;
    }
    mFieldAreaId = r.readS16();
    u32 nArray = r.readU32();
    void* pArray = MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::DTI)->memAlloc(sizeof(cAdjoinInfo) * nArray, 16u);
    for (u32 i = 0; i < nArray; ++i) {
        cAdjoinInfo* pInfo = new (static_cast<cAdjoinInfo*>(pArray) + i) cAdjoinInfo;
        pInfo->mDestinationStageNo = r.readS16();
        pInfo->mNextStageNo = r.readS16();
        nDDOIO::readMtArray(r, pInfo->mPositions);
        pInfo->mPriority = r.readU8();
    }
    mpArray = static_cast<cAdjoinInfo*>(pArray);
    mArrayNum = nArray;
    return true;
}

__attribute__((weak)) bool rFieldAreaAdjoinList::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    w.writeU32(0x414146u);
    w.writeU32(2u);
    w.writeS16(mFieldAreaId);
    w.writeU32(mArrayNum);
    for (u32 i = 0; i < mArrayNum; ++i) {
        cAdjoinInfo* pInfo = &mpArray[i];
        w.writeS16(pInfo->mDestinationStageNo);
        w.writeS16(pInfo->mNextStageNo);
        nDDOIO::writeMtArray(w, pInfo->mPositions);
        w.writeU8(pInfo->mPriority);
    }
    return true;
}

inline rFieldAreaAdjoinList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFieldAreaAdjoinList::MyDTI rFieldAreaAdjoinList::DTI("rFieldAreaAdjoinList", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rFieldAreaAdjoinList::MyDTI::newInstance() const {
    return new (16u) rFieldAreaAdjoinList;
}

const MtDTI& rFieldAreaAdjoinList::cAdjoinInfo::getDTI() const {
    return rFieldAreaAdjoinList::cAdjoinInfo::DTI;
}

inline void* rFieldAreaAdjoinList::cAdjoinInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::cAdjoinInfo::DTI)->memAlloc(sz, align, rFieldAreaAdjoinList::cAdjoinInfo::DTI.getID());
}

inline void rFieldAreaAdjoinList::cAdjoinInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::cAdjoinInfo::DTI)->memFree(p_addr);
}

rFieldAreaAdjoinList::cAdjoinInfo::~cAdjoinInfo() {
    if (mPositions.mLength != 0) {
        u32 v0_0 = mPositions.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPositions.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPositions.mpArray[i0_3];
                v1_0 = mPositions.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPositions.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPositions.mpArray));
    }
    mPositions.mpArray = nullptr;
    mPositions.mBufsiz = 0;
    mPositions.mLength = 0;
}

void rFieldAreaAdjoinList::cAdjoinInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mDestinationStageNo", &mDestinationStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNextStageNo", &mNextStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPositions", static_cast<MtObject*>(&mPositions), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
}

inline rFieldAreaAdjoinList::cAdjoinInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFieldAreaAdjoinList::cAdjoinInfo::MyDTI rFieldAreaAdjoinList::cAdjoinInfo::DTI("rFieldAreaAdjoinList::cAdjoinInfo", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rFieldAreaAdjoinList::cAdjoinInfo::MyDTI::newInstance() const {
    return new (16u) rFieldAreaAdjoinList::cAdjoinInfo;
}

const MtDTI& rFieldAreaAdjoinList::cAdjoinInfo::cVector3::getDTI() const {
    return rFieldAreaAdjoinList::cAdjoinInfo::cVector3::DTI;
}

inline void rFieldAreaAdjoinList::cAdjoinInfo::cVector3::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFieldAreaAdjoinList::cAdjoinInfo::cVector3::DTI)->memFree(p_addr);
}

void rFieldAreaAdjoinList::cAdjoinInfo::cVector3::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestId", &mQuestId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlagId", &mFlagId, 0u, 0u);
}

inline rFieldAreaAdjoinList::cAdjoinInfo::cVector3::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFieldAreaAdjoinList::cAdjoinInfo::cVector3::MyDTI rFieldAreaAdjoinList::cAdjoinInfo::cVector3::DTI("rFieldAreaAdjoinList::cAdjoinInfo::cVector3", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rFieldAreaAdjoinList::cAdjoinInfo::cVector3::MyDTI::newInstance() const {
    return new (16u) rFieldAreaAdjoinList::cAdjoinInfo::cVector3;
}

template MtTypedArray<rFieldAreaAdjoinList::cAdjoinInfo::cVector3>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rFieldAreaAdjoinList::cAdjoinInfo::cVector3>&);

