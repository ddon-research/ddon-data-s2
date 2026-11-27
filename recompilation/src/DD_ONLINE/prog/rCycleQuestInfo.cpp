// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCycleQuestInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rCycleQuestInfo::getDTI() const {
    return rCycleQuestInfo::DTI;
}

MT_CTSTR rCycleQuestInfo::getExt() const {
    return "cqi";
}

rCycleQuestInfo::~rCycleQuestInfo() {
    if (mCycleQuestInfo.mLength != 0) {
        u32 v0_0 = mCycleQuestInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCycleQuestInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mCycleQuestInfo.mpArray[i0_3];
                v1_0 = mCycleQuestInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCycleQuestInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCycleQuestInfo.mpArray));
    }
    mCycleQuestInfo.mpArray = nullptr;
    mCycleQuestInfo.mBufsiz = 0;
    mCycleQuestInfo.mLength = 0;
}

void rCycleQuestInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCycleQuestInfo", static_cast<MtObject*>(&mCycleQuestInfo), 0u, 0u);
}

bool rCycleQuestInfo::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x495143u);
    (&w)->writeU32(2u);
    (&w)->writeU32(mCycleQuestInfo.mLength);
    if (mCycleQuestInfo.mLength == 0) {
        return true;
    }
    unsigned int i3 = 0;
    do {
        static_cast<rCycleQuestInfo::cCycleQuestInfo*>(mCycleQuestInfo.getBuffer()[static_cast<int>(i3)])->save(w);
        i3 += 1u;
    } while (i3 < mCycleQuestInfo.mLength);
    return true;
}

bool rCycleQuestInfo::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x495143) {
        if ((&r)->readU32() == 2) {
            nDDOIO::readMtArray(r, mCycleQuestInfo);
            return true;
        }
    }
    return false;
}

inline rCycleQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCycleQuestInfo::MyDTI rCycleQuestInfo::DTI("rCycleQuestInfo", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rCycleQuestInfo::MyDTI::newInstance() const {
    return new (16u) rCycleQuestInfo;
}

const MtDTI& rCycleQuestInfo::cCycleQuestInfo::getDTI() const {
    return rCycleQuestInfo::cCycleQuestInfo::DTI;
}

rCycleQuestInfo::cCycleQuestInfo::~cCycleQuestInfo() {
    if (mSituationInfo.mLength != 0) {
        u32 v0_0 = mSituationInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSituationInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSituationInfo.mpArray[i0_3];
                v1_0 = mSituationInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSituationInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSituationInfo.mpArray));
    }
    mSituationInfo.mpArray = nullptr;
    mSituationInfo.mBufsiz = 0;
    mSituationInfo.mLength = 0;
}

void rCycleQuestInfo::cCycleQuestInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCycleNo", &mCycleNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCycleSubNo", &mCycleSubNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mContentNameIdx", &mContentNameIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mContentInfoIdx", &mContentInfoIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGatherInfoIdx", &mGatherInfoIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSituationInfo", static_cast<MtObject*>(&mSituationInfo), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGatherNpcId", &mGatherNpcId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGatherStageNo", &mGatherStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGatherStartPos", &mGatherStartPos, 0u, 0u);
}

__attribute__((weak)) bool rCycleQuestInfo::cCycleQuestInfo::save(MtDataWriter& w) {
    w.writeU32(mCycleNo);
    w.writeU32(mCycleSubNo);
    w.writeU32(mContentNameIdx);
    w.writeU32(mContentInfoIdx);
    w.writeU32(mGatherInfoIdx);
    w.writeU32(mSituationInfo.mLength);
    if (mSituationInfo.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t0 = mSituationInfo.getBuffer()[static_cast<int>(i0_3)];
            w.writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 8));
            w.writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 12));
            w.writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 16));
            w.writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 20));
            if ((i0_3 + 1u) < mSituationInfo.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    w.writeU32(mGatherNpcId);
    w.writeU32(mGatherStageNo);
    w.writeU32(mGatherStartPos);
    return true;
}

inline rCycleQuestInfo::cCycleQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCycleQuestInfo::cCycleQuestInfo::MyDTI rCycleQuestInfo::cCycleQuestInfo::DTI("rCycleQuestInfo::cCycleQuestInfo", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* rCycleQuestInfo::cCycleQuestInfo::MyDTI::newInstance() const {
    return new (16u) rCycleQuestInfo::cCycleQuestInfo;
}

const MtDTI& rCycleQuestInfo::cCycleQuestSituationInfo::getDTI() const {
    return rCycleQuestInfo::cCycleQuestSituationInfo::DTI;
}

rCycleQuestInfo::cCycleQuestSituationInfo::~cCycleQuestSituationInfo() {
}

void rCycleQuestInfo::cCycleQuestSituationInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSituationNo", &mSituationNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSituationNameIdx", &mSituationNameIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSituationStateIdx", &mSituationStateIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSituationDetailIdx", &mSituationDetailIdx, 0u, 0u);
}

inline rCycleQuestInfo::cCycleQuestSituationInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCycleQuestInfo::cCycleQuestSituationInfo::MyDTI rCycleQuestInfo::cCycleQuestSituationInfo::DTI("rCycleQuestInfo::cCycleQuestSituationInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rCycleQuestInfo::cCycleQuestSituationInfo::MyDTI::newInstance() const {
    return new (16u) rCycleQuestInfo::cCycleQuestSituationInfo;
}

template MtTypedArray<rCycleQuestInfo::cCycleQuestInfo>::~MtTypedArray();

template MtTypedArray<rCycleQuestInfo::cCycleQuestSituationInfo>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rCycleQuestInfo::cCycleQuestInfo>&);

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rCycleQuestInfo::cCycleQuestSituationInfo>&);

