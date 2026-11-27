// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rGeometry3.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "../MT/MtStream.h"
#include "cResource.h"
#include "nCollisionNode.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rGeometry3::getDTI() const {
    return rGeometry3::DTI;
}

rGeometry3::~rGeometry3() {
    DDON_STUB("rGeometry3::~rGeometry3")
    /* stub */
}

void rGeometry3::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupArray", static_cast<MtObject*>(&mGroupArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "UniqueIDTable", reinterpret_cast<MT_MFUNC>(&::rGeometry3::getGroupUniqueIDForIO), reinterpret_cast<MT_MFUNC>(&::rGeometry3::setGroupUniqueIDForIO), 161u, reinterpret_cast<MT_MFUNC>(&::rGeometry3::getGroupUniqueIDNumForIO), reinterpret_cast<MT_MFUNC>(&::rGeometry3::setGroupUniqueIDNumForIO));
    s << MtProperty(static_cast<MtObject*>(this), "mFlgEnableMotionSequence", &mFlgEnableMotionSequence, 1u, 0u);
}

void rGeometry3::clear() {
    if (mGroupArray.mLength != 0) {
        u32 v0_0 = mGroupArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mGroupArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mGroupArray.mpArray[i0_3];
                v1_0 = mGroupArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mGroupArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGroupArray.mpArray));
    }
    mGroupArray.mpArray = nullptr;
    mGroupArray.mBufsiz = 0;
    mGroupArray.mLength = 0;
}

bool rGeometry3::load(MtStream& in) {
    u32 FileMagic;
    in.read(static_cast<void*>(&FileMagic), 4u);
    u32 FileVersion;
    in.read(static_cast<void*>(&FileVersion), 4u);
    if (FileMagic == 0x336F6567) {
        if (FileVersion == 0x77CFDF9C) {
            MtSerializer sz(65536);
            return sz.deserializeBinary(in, static_cast<u16>(0), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
        }
    }
    return false;
}

__attribute__((weak)) bool rGeometry3::save(MtStream& out) {
    DDON_STUB("rGeometry3::save")
    return {};
}

MT_CTSTR rGeometry3::getExt() const {
    return "geo3";
}

nCollision::cGeometryJointGroup* rGeometry3::getGeometryGroupFromIndex(u32 TargetIndex) {
    if (TargetIndex < mGroupArray.mLength) {
        return static_cast<nCollision::cGeometryJointGroup*>(mGroupArray.mpArray[TargetIndex]);
    } else {
        return nullptr;
    }
}

nCollision::cGeometryJointGroup* rGeometry3::getGeometryGroupFromID(u32 TargetID) {
    if (TargetID < mUniqueIDNum) {
        if (mpUniqueIDTable[TargetID] < mGroupArray.mLength) {
            return static_cast<nCollision::cGeometryJointGroup*>(mGroupArray.mpArray[mpUniqueIDTable[TargetID]]);
        }
    }
    return nullptr;
}

u32 rGeometry3::getGeometryGroupNum() const {
    return mGroupArray.mLength;
}

u32 rGeometry3::getGroupUniqueIDForIO(u32 UniqueIDIndex) {
    return mpUniqueIDTable[UniqueIDIndex];
}

void rGeometry3::setGroupUniqueIDForIO(u32 UniqueID, u32 UniqueIDIndex) {
    mpUniqueIDTable[UniqueIDIndex] = UniqueID;
}

u32 rGeometry3::getGroupUniqueIDNumForIO() {
    return mUniqueIDNum;
}

void rGeometry3::setGroupUniqueIDNumForIO(u32 UniqueIDNum) {
    u32* t0 = mpUniqueIDTable;
    if (t0 != nullptr) {
        MtMemoryAllocator::getAllocator(rGeometry3::DTI)->memFree(static_cast<void*>(t0));
        mpUniqueIDTable = nullptr;
    }
    mpUniqueIDTable = static_cast<u32*>(MtMemoryAllocator::getAllocator(rGeometry3::DTI)->memAlloc(UniqueIDNum * 4u, 16u));
    mUniqueIDNum = UniqueIDNum;
}

inline rGeometry3::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGeometry3::MyDTI rGeometry3::DTI("rGeometry3", &::cResource::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* rGeometry3::MyDTI::newInstance() const {
    DDON_STUB("rGeometry3::MyDTI::newInstance")
    return nullptr;
}

