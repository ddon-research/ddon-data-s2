// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rDungeonMarker.h"
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

const MtDTI& rDungeonMarker::getDTI() const {
    return rDungeonMarker::DTI;
}

inline void* rDungeonMarker::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rDungeonMarker::DTI)->memAlloc(sz, align, rDungeonMarker::DTI.getID());
}

inline void rDungeonMarker::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rDungeonMarker::DTI)->memFree(p_addr);
}

u32 rDungeonMarker::getWarpPosNum(s32 groupNo, u32 targetStageNo, s32 targetGroupNo) const {
    if (mWarpInfoList.mLength != 0) {
        u32 i = 0;
        do {
            if (groupNo == static_cast<int>(static_cast<short>(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mWarpInfoList.mpArray[i]) + 40)))) {
                if ((*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mWarpInfoList.mpArray[i]) + 42)) == targetStageNo) {
                    if (targetGroupNo == static_cast<int>(static_cast<short>(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mWarpInfoList.mpArray[i]) + 44)))) {
                        return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mWarpInfoList.mpArray[i]) + 16);
                    }
                }
            }
            i += 1u;
        } while (i < mWarpInfoList.mLength);
    }
    return 0;
}

__attribute__((weak)) const MtVector3& rDungeonMarker::getWarpPos(s32 groupNo, u32 targetStageNo, s32 targetGroupNo, u32 index) const {
    DDON_STUB("rDungeonMarker::getWarpPos")
    __builtin_unreachable();
}

MT_CTSTR rDungeonMarker::getExt() const {
    return "dmi";
}

inline rDungeonMarker::rDungeonMarker() {
    mWarpStageNo = 0;
    setAttribute(22u);
}

__attribute__((noinline)) rDungeonMarker::~rDungeonMarker() {
    if (mWarpInfoList.mLength != 0) {
        u32 v0_0 = mWarpInfoList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mWarpInfoList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mWarpInfoList.mpArray[i0_3];
                v1_0 = mWarpInfoList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mWarpInfoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mWarpInfoList.mpArray));
    }
    mWarpInfoList.mpArray = nullptr;
    mWarpInfoList.mBufsiz = 0;
    mWarpInfoList.mLength = 0;
    if (mPositionList.mLength != 0) {
        u32 v3_0 = mPositionList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mPositionList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mPositionList.mpArray[i3_3];
                v4_0 = mPositionList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPositionList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPositionList.mpArray));
    }
    mPositionList.mpArray = nullptr;
    mPositionList.mBufsiz = 0;
    mPositionList.mLength = 0;
}

void rDungeonMarker::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mWarpStageNo", &mWarpStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWarpInfoList", static_cast<MtObject*>(&mWarpInfoList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPositionList", static_cast<MtObject*>(&mPositionList), 0u, 0u);
}

bool rDungeonMarker::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x494D44) {
        if ((&r)->readU32() == 1) {
            mWarpStageNo = (&r)->readU16();
            nDDOIO::readMtArray(r, mWarpInfoList);
            nDDOIO::readMtArray(r, mPositionList);
            return true;
        }
    }
    return false;
}

__attribute__((weak)) bool rDungeonMarker::save(MtStream& out) {
        MtDataWriter w(out, 4096, 4096);
        (&w)->writeU32(0x494D44);
        (&w)->writeU32(1);
        (&w)->writeU16(mWarpStageNo);
        nDDOIO::writeMtArray(w, mWarpInfoList);
        (&w)->writeU32(mPositionList.mLength);
        if (mPositionList.mLength != 0) {
            MtFloat3 t2;
            u32 t1 = 0;
            do {
                t2.x = static_cast<cPosition*>(mPositionList.mpArray[(s32)t1])->mPos.x;
                t2.y = static_cast<cPosition*>(mPositionList.mpArray[(s32)t1])->mPos.y;
                t2.z = static_cast<cPosition*>(mPositionList.mpArray[(s32)t1])->mPos.z;
                w.writeV3(t2);
                ++t1;
            } while (t1 < mPositionList.mLength);
        }
        return true;
}

inline rDungeonMarker::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDungeonMarker::MyDTI rDungeonMarker::DTI("rDungeonMarker", &::cResource::DTI, 184ul, 0u, 0u);

MtObject* rDungeonMarker::MyDTI::newInstance() const {
    return new (16u) rDungeonMarker;
}

const MtDTI& rDungeonMarker::cWarpInfo::getDTI() const {
    return rDungeonMarker::cWarpInfo::DTI;
}

void* rDungeonMarker::cWarpInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rDungeonMarker::cWarpInfo::DTI)->memAlloc(sz, align, rDungeonMarker::cWarpInfo::DTI.getID());
}

inline void rDungeonMarker::cWarpInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rDungeonMarker::cWarpInfo::DTI)->memFree(p_addr);
}

rDungeonMarker::cWarpInfo::~cWarpInfo() {
    if (mPosIndex.mLength != 0) {
        u32 v0_0 = mPosIndex.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPosIndex.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPosIndex.mpArray[i0_3];
                v1_0 = mPosIndex.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPosIndex.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPosIndex.mpArray));
    }
    mPosIndex.mpArray = nullptr;
    mPosIndex.mBufsiz = 0;
    mPosIndex.mLength = 0;
}

void rDungeonMarker::cWarpInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetStageNo", &mTargetStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetGroupNo", &mTargetGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPosIndex", static_cast<MtObject*>(&mPosIndex), 0u, 0u);
}

inline rDungeonMarker::cWarpInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDungeonMarker::cWarpInfo::MyDTI rDungeonMarker::cWarpInfo::DTI("rDungeonMarker::cWarpInfo", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rDungeonMarker::cWarpInfo::MyDTI::newInstance() const {
    return new (16u) rDungeonMarker::cWarpInfo;
}

const MtDTI& rDungeonMarker::cWarpInfo::cIndex::getDTI() const {
    return rDungeonMarker::cWarpInfo::cIndex::DTI;
}

inline void rDungeonMarker::cWarpInfo::cIndex::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rDungeonMarker::cWarpInfo::cIndex::DTI)->memFree(p_addr);
}

void rDungeonMarker::cWarpInfo::cIndex::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 0u, 0u);
}

inline rDungeonMarker::cWarpInfo::cIndex::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDungeonMarker::cWarpInfo::cIndex::MyDTI rDungeonMarker::cWarpInfo::cIndex::DTI("rDungeonMarker::cWarpInfo::cIndex", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rDungeonMarker::cWarpInfo::cIndex::MyDTI::newInstance() const {
    return new (16u) rDungeonMarker::cWarpInfo::cIndex;
}

const MtDTI& rDungeonMarker::cPosition::getDTI() const {
    return rDungeonMarker::cPosition::DTI;
}

void* rDungeonMarker::cPosition::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rDungeonMarker::cPosition::DTI)->memAlloc(sz, align, rDungeonMarker::cPosition::DTI.getID());
}

inline void rDungeonMarker::cPosition::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rDungeonMarker::cPosition::DTI)->memFree(p_addr);
}

rDungeonMarker::cPosition::cPosition() {
    mPos.x = MtVector3::Zero.x;
    mPos.y = MtVector3::Zero.y;
    mPos.z = MtVector3::Zero.z;
    mPos.pad_ = 0.0f;
}

rDungeonMarker::cPosition::~cPosition() {
}

void rDungeonMarker::cPosition::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
}

inline rDungeonMarker::cPosition::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDungeonMarker::cPosition::MyDTI rDungeonMarker::cPosition::DTI("rDungeonMarker::cPosition", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rDungeonMarker::cPosition::MyDTI::newInstance() const {
    return new (16u) rDungeonMarker::cPosition;
}

template MtTypedArray<rDungeonMarker::cPosition>::~MtTypedArray();

template MtTypedArray<rDungeonMarker::cWarpInfo::cIndex>::~MtTypedArray();

template MtTypedArray<rDungeonMarker::cWarpInfo>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rDungeonMarker::cWarpInfo>&);

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rDungeonMarker::cPosition>&);

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rDungeonMarker::cWarpInfo::cIndex>&);

template <typename T>
void nDDOIO::writeMtArray(MtDataWriter& w, MtTypedArray<T>& ar) {
    w.writeU32(ar.size());
    for (u32 i = 0; i < ar.size(); i++) {
        static_cast<T*>(ar.getBuffer()[(s32)i])->save(w);
    }
}

template void nDDOIO::writeMtArray(MtDataWriter&, MtTypedArray<rDungeonMarker::cWarpInfo>&);

