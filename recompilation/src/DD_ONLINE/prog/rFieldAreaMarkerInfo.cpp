// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rFieldAreaMarkerInfo.h"
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

const MtDTI& rFieldAreaMarkerInfo::getDTI() const {
    return rFieldAreaMarkerInfo::DTI;
}

inline void* rFieldAreaMarkerInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rFieldAreaMarkerInfo::DTI)->memAlloc(sz, align, rFieldAreaMarkerInfo::DTI.getID());
}

inline void rFieldAreaMarkerInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFieldAreaMarkerInfo::DTI)->memFree(p_addr);
}

MT_CTSTR rFieldAreaMarkerInfo::getFileResId(u32 type) {
    static const MT_CTSTR suffix[4] = {
        "RES_ID_NPC",
        "RES_ID_SCE",
        "RES_ID_ECT",
        "RES_ID_OM",
    };
    if (type > 3u) {
        return "";
    } else {
        return suffix[type];
    }
}

const rFieldAreaMarkerInfo::MarkerInfoArray& rFieldAreaMarkerInfo::getMarkerInfoList() const {
    return mMarkerInfoList;
}

MT_CTSTR rFieldAreaMarkerInfo::getExt() const {
    return "fmi";
}

inline rFieldAreaMarkerInfo::rFieldAreaMarkerInfo() {
    mFieldAreaId = 0;
    setAttribute(22u);
}

rFieldAreaMarkerInfo::~rFieldAreaMarkerInfo() {
    if (mMarkerInfoList.mLength != 0) {
        u32 v0_0 = mMarkerInfoList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMarkerInfoList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMarkerInfoList.mpArray[i0_3];
                v1_0 = mMarkerInfoList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMarkerInfoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMarkerInfoList.mpArray));
    }
    mMarkerInfoList.mpArray = nullptr;
    mMarkerInfoList.mBufsiz = 0;
    mMarkerInfoList.mLength = 0;
}

bool rFieldAreaMarkerInfo::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x494D46) {
        if ((&r)->readU32() == 1) {
            mFieldAreaId = (&r)->readU32();
            nDDOIO::readMtArray(r, mMarkerInfoList);
            return true;
        }
    }
    return false;
}

__attribute__((weak)) bool rFieldAreaMarkerInfo::save(MtStream& out) {
        MtDataWriter w(out, 4096, 4096);
        nDDOIO::writeData(w, 0x494D46u);
        nDDOIO::writeData(w, 1u);
        nDDOIO::writeData(w, mFieldAreaId);
        (&w)->writeU32(mMarkerInfoList.size());
        for (u32 t1 = 0; t1 < mMarkerInfoList.size(); ++t1) {
            static_cast<cMarkerInfo*>(mMarkerInfoList.mpArray[(s32)t1])->save(w);
        }
        return true;
}

inline rFieldAreaMarkerInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFieldAreaMarkerInfo::MyDTI rFieldAreaMarkerInfo::DTI("rFieldAreaMarkerInfo", &::cResource::DTI, 152ul, 0u, 0u);

MtObject* rFieldAreaMarkerInfo::MyDTI::newInstance() const {
    return new (16u) rFieldAreaMarkerInfo;
}

const MtDTI& rFieldAreaMarkerInfo::cMarkerInfo::getDTI() const {
    return rFieldAreaMarkerInfo::cMarkerInfo::DTI;
}

void* rFieldAreaMarkerInfo::cMarkerInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rFieldAreaMarkerInfo::cMarkerInfo::DTI)->memAlloc(sz, align, rFieldAreaMarkerInfo::cMarkerInfo::DTI.getID());
}

inline void rFieldAreaMarkerInfo::cMarkerInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rFieldAreaMarkerInfo::cMarkerInfo::DTI)->memFree(p_addr);
}

rFieldAreaMarkerInfo::cMarkerInfo::~cMarkerInfo() {
}

void rFieldAreaMarkerInfo::cMarkerInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUniqueId", &mUniqueId, 0u, 0u);
}

void rFieldAreaMarkerInfo::cMarkerInfo::load(MtDataReader& r) {
    mPos = r.readV3();
    nDDOIO::readData(r, mStageNo);
    nDDOIO::readData(r, mGroupNo);
    nDDOIO::readData(r, mUniqueId);
}

void rFieldAreaMarkerInfo::cMarkerInfo::save(MtDataWriter& w) {
    MtFloat3 frame56;
    frame56.x = mPos.x;
    frame56.y = mPos.y;
    frame56.z = mPos.z;
    w.writeV3(frame56);
    w.writeS32(mStageNo);
    w.writeU32(mGroupNo);
    w.writeU32(mUniqueId);
}

inline rFieldAreaMarkerInfo::cMarkerInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rFieldAreaMarkerInfo::cMarkerInfo::MyDTI rFieldAreaMarkerInfo::cMarkerInfo::DTI("rFieldAreaMarkerInfo::cMarkerInfo", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rFieldAreaMarkerInfo::cMarkerInfo::MyDTI::newInstance() const {
    return new (16u) rFieldAreaMarkerInfo::cMarkerInfo;
}

template MtTypedArray<rFieldAreaMarkerInfo::cMarkerInfo>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rFieldAreaMarkerInfo::cMarkerInfo>&);

