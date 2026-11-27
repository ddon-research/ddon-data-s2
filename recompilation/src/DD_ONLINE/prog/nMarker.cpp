// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nMarker.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nMarker::cMarkerInfo::getDTI() const {
    return nMarker::cMarkerInfo::DTI;
}

void* nMarker::cMarkerInfo::operator new(size_t sz, u32 align) {
    return ::nMarker::cMarkerInfo::getAllocator()->memAlloc(sz, align, ::nMarker::cMarkerInfo::DTI.getID());
}

const nMarker::cMarkerInfo::Vector3Array& nMarker::cMarkerInfo::getPosList() const {
    return mPosList;
}

__attribute__((weak)) nMarker::cMarkerInfo& nMarker::cMarkerInfo::addPosition(const MtVector3& pos) {
    DDON_STUB("nMarker::cMarkerInfo::addPosition")
    __builtin_unreachable();
}

const nMarker::cMarkerInfo::CtrlFlagArray& nMarker::cMarkerInfo::getCtrlFlagList() const {
    return mCtrlFlagList;
}

__attribute__((weak)) nMarker::cMarkerInfo& nMarker::cMarkerInfo::addCtrlFlag(u32 questId, u32 flagNo) {
    DDON_STUB("nMarker::cMarkerInfo::addCtrlFlag")
    __builtin_unreachable();
}

nMarker::cMarkerInfo& nMarker::cMarkerInfo::setPosition(u32 idx, const MtVector3& pos) {
    if (idx < mPosList.mLength) {
        const f32 t0 = pos.y;
        const f32 t1 = pos.z;
        static_cast<nMarker::cMarkerInfo::cVector3*>(mPosList.getBuffer()[static_cast<int>(idx)])->mRealPos.x = pos.x;
        static_cast<nMarker::cMarkerInfo::cVector3*>(mPosList.getBuffer()[static_cast<int>(idx)])->mRealPos.y = t0;
        static_cast<nMarker::cMarkerInfo::cVector3*>(mPosList.getBuffer()[static_cast<int>(idx)])->mRealPos.z = t1;
        static_cast<nMarker::cMarkerInfo::cVector3*>(mPosList.getBuffer()[static_cast<int>(idx)])->mRealPos.pad_ = 0.0f;
        return *this;
    } else {
        return *this;
    }
}

s16 nMarker::cMarkerInfo::getStageNo() const {
    return mStageNo;
}

nMarker::cMarkerInfo& nMarker::cMarkerInfo::setStageNo(s16 stageNo) {
    mStageNo = stageNo;
    return *this;
}

bool nMarker::cMarkerInfo::isAdjoin() const {
    return mIsAdjoin;
}

nMarker::cMarkerInfo& nMarker::cMarkerInfo::setIsAdjoin(bool isAdj) {
    mIsAdjoin = isAdj;
    return *this;
}

nMarker::cMarkerInfo::cMarkerInfo() {
    mStageNo = -1;
    mIsAdjoin = false;
}

__attribute__((noinline)) nMarker::cMarkerInfo::~cMarkerInfo() {
    if (mPosList.mLength != 0) {
        u32 v0_0 = mPosList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPosList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPosList.mpArray[i0_3];
                v1_0 = mPosList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPosList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mPosList.mpArray));
    }
    mPosList.mpArray = nullptr;
    mPosList.mBufsiz = 0;
    mPosList.mLength = 0;
    if (mCtrlFlagList.mLength != 0) {
        u32 v3_0 = mCtrlFlagList.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mCtrlFlagList.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mCtrlFlagList.mpArray[i3_3];
                v4_0 = mCtrlFlagList.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCtrlFlagList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mCtrlFlagList.mpArray));
    }
    mCtrlFlagList.mpArray = nullptr;
    mCtrlFlagList.mBufsiz = 0;
    mCtrlFlagList.mLength = 0;
}

__attribute__((weak)) void nMarker::cMarkerInfo::createProperty(MtPropertyList& s) {
}

inline nMarker::cMarkerInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nMarker::cMarkerInfo::MyDTI nMarker::cMarkerInfo::DTI("nMarker::cMarkerInfo", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* nMarker::cMarkerInfo::MyDTI::newInstance() const {
    return new (16u) ::nMarker::cMarkerInfo;
}

const MtDTI& nMarker::cMarkerInfo::cVector3::getDTI() const {
    return nMarker::cMarkerInfo::cVector3::DTI;
}

nMarker::cMarkerInfo::cVector3::operator MtVector3() {
    return mRealPos;
}

nMarker::cMarkerInfo::cVector3::cVector3(const MtVector3& pos) {
    mRealPos.x = pos.x;
    mRealPos.y = pos.y;
    mRealPos.z = pos.z;
    mRealPos.pad_ = 0.0f;
}

__attribute__((weak)) void nMarker::cMarkerInfo::cVector3::createProperty(MtPropertyList& s) {
}

inline nMarker::cMarkerInfo::cVector3::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nMarker::cMarkerInfo::cVector3::MyDTI nMarker::cMarkerInfo::cVector3::DTI("nMarker::cMarkerInfo::cVector3", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* nMarker::cMarkerInfo::cVector3::MyDTI::newInstance() const {
    return new (16u) ::nMarker::cMarkerInfo::cVector3;
}

const MtDTI& nMarker::cMarkerInfo::cCtrlFlag::getDTI() const {
    return nMarker::cMarkerInfo::cCtrlFlag::DTI;
}

u32 nMarker::cMarkerInfo::cCtrlFlag::getQuestId() const {
    return mQuestId;
}

u32 nMarker::cMarkerInfo::cCtrlFlag::getFalgNo() const {
    return mFlagNo;
}

__attribute__((weak)) void nMarker::cMarkerInfo::cCtrlFlag::createProperty(MtPropertyList& s) {
}

inline nMarker::cMarkerInfo::cCtrlFlag::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nMarker::cMarkerInfo::cCtrlFlag::MyDTI nMarker::cMarkerInfo::cCtrlFlag::DTI("nMarker::cMarkerInfo::cCtrlFlag", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* nMarker::cMarkerInfo::cCtrlFlag::MyDTI::newInstance() const {
    return new (16u) ::nMarker::cMarkerInfo::cCtrlFlag;
}

const MtDTI& nMarker::cWarpMarkerInfo::getDTI() const {
    return nMarker::cWarpMarkerInfo::DTI;
}

void* nMarker::cWarpMarkerInfo::operator new(size_t sz, u32 align) {
    return ::nMarker::cWarpMarkerInfo::getAllocator()->memAlloc(sz, align, ::nMarker::cWarpMarkerInfo::DTI.getID());
}

const nMarker::cMarkerInfo::Vector3Array& nMarker::cWarpMarkerInfo::getTargetPosList() const {
    return mTargetPos;
}

__attribute__((weak)) bool nMarker::cWarpMarkerInfo::hasTargetPos(const MtVector3& pos) const {
    DDON_STUB("nMarker::cWarpMarkerInfo::hasTargetPos")
    return {};
}

__attribute__((weak)) nMarker::cWarpMarkerInfo& nMarker::cWarpMarkerInfo::addTargetPos(const MtVector3& pos) {
    DDON_STUB("nMarker::cWarpMarkerInfo::addTargetPos")
    __builtin_unreachable();
}

s32 nMarker::cWarpMarkerInfo::getTargetFloorGroupNo() const {
    return mTargetFloorGroupNo;
}

nMarker::cWarpMarkerInfo& nMarker::cWarpMarkerInfo::setTargetFloorGroupNo(s32 floorGroupNo) {
    mTargetFloorGroupNo = floorGroupNo;
    return *this;
}

nMarker::cWarpMarkerInfo& nMarker::cWarpMarkerInfo::clearPosList() {
    if (mPosList.mLength != 0) {
        u32 v0_0 = mPosList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPosList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPosList.mpArray[i0_3];
                v1_0 = mPosList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPosList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mPosList.mpArray));
    }
    mPosList.mpArray = nullptr;
    mPosList.mBufsiz = 0;
    mPosList.mLength = 0;
    return *this;
}

nMarker::cWarpMarkerInfo::cWarpMarkerInfo() {
    mTargetFloorGroupNo = -1;
    mIsAdjoin = true;
}

nMarker::cWarpMarkerInfo::~cWarpMarkerInfo() {
    if (mTargetPos.mLength != 0) {
        u32 v0_0 = mTargetPos.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTargetPos.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTargetPos.mpArray[i0_3];
                v1_0 = mTargetPos.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTargetPos.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mTargetPos.mpArray));
    }
    mTargetPos.mpArray = nullptr;
    mTargetPos.mBufsiz = 0;
    mTargetPos.mLength = 0;
}

__attribute__((weak)) void nMarker::cWarpMarkerInfo::createProperty(MtPropertyList& s) {
}

inline nMarker::cWarpMarkerInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nMarker::cWarpMarkerInfo::MyDTI nMarker::cWarpMarkerInfo::DTI("nMarker::cWarpMarkerInfo", &::nMarker::cMarkerInfo::DTI, 120ul, 0u, 0u);

MtObject* nMarker::cWarpMarkerInfo::MyDTI::newInstance() const {
    return new (16u) ::nMarker::cWarpMarkerInfo;
}

const MtDTI& nMarker::cWarpMarkerInfoStage::getDTI() const {
    return nMarker::cWarpMarkerInfoStage::DTI;
}

void* nMarker::cWarpMarkerInfoStage::operator new(size_t sz, u32 align) {
    return ::nMarker::cWarpMarkerInfoStage::getAllocator()->memAlloc(sz, align, ::nMarker::cWarpMarkerInfoStage::DTI.getID());
}

s16 nMarker::cWarpMarkerInfoStage::getTargetStageNo() const {
    return mTargetStageNo;
}

nMarker::cWarpMarkerInfoStage& nMarker::cWarpMarkerInfoStage::setTargetStageNo(s16 stageNo) {
    mTargetStageNo = stageNo;
    return *this;
}

const nMarker::cWarpMarkerInfoStage::TargetInfoArray& nMarker::cWarpMarkerInfoStage::getTargetInfoList() const {
    return mTargetInfoList;
}

__attribute__((weak)) nMarker::cWarpMarkerInfoStage& nMarker::cWarpMarkerInfoStage::addTargetInfo(const MtVector3& targetPos) {
    DDON_STUB("nMarker::cWarpMarkerInfoStage::addTargetInfo")
    __builtin_unreachable();
}

nMarker::cWarpMarkerInfoStage& nMarker::cWarpMarkerInfoStage::clearPosList() {
    if (mPosList.mLength != 0) {
        u32 v0_0 = mPosList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPosList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPosList.mpArray[i0_3];
                v1_0 = mPosList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPosList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mPosList.mpArray));
    }
    mPosList.mpArray = nullptr;
    mPosList.mBufsiz = 0;
    mPosList.mLength = 0;
    return *this;
}

nMarker::cWarpMarkerInfoStage::cWarpMarkerInfoStage() {
    mTargetStageNo = 0;
}

nMarker::cWarpMarkerInfoStage::~cWarpMarkerInfoStage() {
    if (mTargetInfoList.mLength != 0) {
        u32 v0_0 = mTargetInfoList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTargetInfoList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTargetInfoList.mpArray[i0_3];
                v1_0 = mTargetInfoList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTargetInfoList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mTargetInfoList.mpArray));
    }
    mTargetInfoList.mpArray = nullptr;
    mTargetInfoList.mBufsiz = 0;
    mTargetInfoList.mLength = 0;
}

__attribute__((weak)) void nMarker::cWarpMarkerInfoStage::createProperty(MtPropertyList& s) {
}

inline nMarker::cWarpMarkerInfoStage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nMarker::cWarpMarkerInfoStage::MyDTI nMarker::cWarpMarkerInfoStage::DTI("nMarker::cWarpMarkerInfoStage", &::nMarker::cMarkerInfo::DTI, 120ul, 0u, 0u);

MtObject* nMarker::cWarpMarkerInfoStage::MyDTI::newInstance() const {
    return new (16u) ::nMarker::cWarpMarkerInfoStage;
}

const MtDTI& nMarker::cWarpMarkerInfoStage::cTargetInfo::getDTI() const {
    return nMarker::cWarpMarkerInfoStage::cTargetInfo::DTI;
}

__attribute__((weak)) const MtVector3& nMarker::cWarpMarkerInfoStage::cTargetInfo::getTargetPos() const {
    DDON_STUB("nMarker::cWarpMarkerInfoStage::cTargetInfo::getTargetPos")
    __builtin_unreachable();
}

nMarker::cWarpMarkerInfoStage::cTargetInfo::cTargetInfo(const MtVector3& pos) {
    DDON_STUB("nMarker::cWarpMarkerInfoStage::cTargetInfo::cTargetInfo")
    /* stub */
}

nMarker::cWarpMarkerInfoStage::cTargetInfo::~cTargetInfo() {
    if (mTargetPosList.mLength != 0) {
        u32 v0_0 = mTargetPosList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTargetPosList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTargetPosList.mpArray[i0_3];
                v1_0 = mTargetPosList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTargetPosList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mTargetPosList.mpArray));
    }
    mTargetPosList.mpArray = nullptr;
    mTargetPosList.mBufsiz = 0;
    mTargetPosList.mLength = 0;
}

__attribute__((weak)) void nMarker::cWarpMarkerInfoStage::cTargetInfo::createProperty(MtPropertyList& s) {
}

inline nMarker::cWarpMarkerInfoStage::cTargetInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nMarker::cWarpMarkerInfoStage::cTargetInfo::MyDTI nMarker::cWarpMarkerInfoStage::cTargetInfo::DTI("nMarker::cWarpMarkerInfoStage::cTargetInfo", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* nMarker::cWarpMarkerInfoStage::cTargetInfo::MyDTI::newInstance() const {
    return new (16u) ::nMarker::cWarpMarkerInfoStage::cTargetInfo;
}

template MtTypedArray<nMarker::cMarkerInfo::cCtrlFlag>::~MtTypedArray();

template MtTypedArray<nMarker::cMarkerInfo::cVector3>::~MtTypedArray();

template MtTypedArray<nMarker::cWarpMarkerInfoStage::cTargetInfo>::~MtTypedArray();

