// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rQuestMarkerInfo.h"
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

const MtDTI& rQuestMarkerInfo::getDTI() const {
    return rQuestMarkerInfo::DTI;
}

MT_CTSTR rQuestMarkerInfo::getExt() const {
    return "qmi";
}

rQuestMarkerInfo::~rQuestMarkerInfo() {
    if (mInfoList.mLength != 0) {
        u32 v0_0 = mInfoList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mInfoList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mInfoList.mpArray[i0_3];
                v1_0 = mInfoList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mInfoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mInfoList.mpArray));
    }
    mInfoList.mpArray = nullptr;
    mInfoList.mBufsiz = 0;
    mInfoList.mLength = 0;
}

void rQuestMarkerInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInfoList", static_cast<MtObject*>(&mInfoList), 0u, 0u);
}

bool rQuestMarkerInfo::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x494D51) {
        if ((&r)->readU32() == 1) {
            mStageNo = (&r)->readU32();
            nDDOIO::readMtArray(r, mInfoList);
            return true;
        }
    }
    return false;
}

__attribute__((weak)) bool rQuestMarkerInfo::save(MtStream& out) {
        MtDataWriter w(out, 4096, 4096);
        (&w)->writeU32(0x494D51);
        (&w)->writeU32(1);
        u32 t2 = mStageNo;
        (&w)->writeU32(t2);
        (&w)->writeU32(mInfoList.mLength);
        for (u32 t1 = 0; t1 < mInfoList.mLength; ++t1) {
            static_cast<cInfo*>(mInfoList.mpArray[(s32)t1])->save(w);
        }
        return true;
}

inline rQuestMarkerInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rQuestMarkerInfo::MyDTI rQuestMarkerInfo::DTI("rQuestMarkerInfo", &::cResource::DTI, 152ul, 0u, 0u);

MtObject* rQuestMarkerInfo::MyDTI::newInstance() const {
    return new (16u) rQuestMarkerInfo;
}

const MtDTI& rQuestMarkerInfo::cInfo::getDTI() const {
    return rQuestMarkerInfo::cInfo::DTI;
}

rQuestMarkerInfo::cInfo::~cInfo() {
}

void rQuestMarkerInfo::cInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUniqueId", &mUniqueId, 0u, 0u);
}

void rQuestMarkerInfo::cInfo::load(MtDataReader& r) {
    mPos = r.readV3();
    nDDOIO::readData(r, mGroupNo);
    nDDOIO::readData(r, mUniqueId);
}

void rQuestMarkerInfo::cInfo::save(MtDataWriter& w) {
    MtFloat3 frame56;
    frame56.x = mPos.x;
    frame56.y = mPos.y;
    frame56.z = mPos.z;
    w.writeV3(frame56);
    w.writeU32(mGroupNo);
    w.writeU32(mUniqueId);
}

inline rQuestMarkerInfo::cInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rQuestMarkerInfo::cInfo::MyDTI rQuestMarkerInfo::cInfo::DTI("rQuestMarkerInfo::cInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rQuestMarkerInfo::cInfo::MyDTI::newInstance() const {
    return new (16u) rQuestMarkerInfo::cInfo;
}

template MtTypedArray<rQuestMarkerInfo::cInfo>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rQuestMarkerInfo::cInfo>&);

