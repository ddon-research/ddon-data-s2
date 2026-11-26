// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSituationMsgCtrl.h"
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

const MtDTI& rSituationMsgCtrl::getDTI() const {
    return rSituationMsgCtrl::DTI;
}

inline void* rSituationMsgCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSituationMsgCtrl::DTI)->memAlloc(sz, align, rSituationMsgCtrl::DTI.getID());
}

inline void rSituationMsgCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSituationMsgCtrl::DTI)->memFree(p_addr);
}

MT_CTSTR rSituationMsgCtrl::getExt() const {
    return "smc";
}

inline rSituationMsgCtrl::rSituationMsgCtrl() {
    setAttribute(22u);
}

rSituationMsgCtrl::~rSituationMsgCtrl() {
    if (mArray.mLength != 0) {
        u32 v0_0 = mArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mArray.mpArray[i0_3];
                v1_0 = mArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mArray.mpArray));
    }
    mArray.mpArray = nullptr;
    mArray.mBufsiz = 0;
    mArray.mLength = 0;
}

void rSituationMsgCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mArray", static_cast<MtObject*>(&mArray), 0u, 0u);
}

bool rSituationMsgCtrl::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x434D53) {
        if ((&r)->readU32() == 2) {
            nDDOIO::readMtArray(r, mArray);
            return true;
        }
    }
    return false;
}

bool rSituationMsgCtrl::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x434D53u);
    (&w)->writeU32(2u);
    nDDOIO::writeMtArray(w, mArray);
    return true;
}

inline rSituationMsgCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSituationMsgCtrl::MyDTI rSituationMsgCtrl::DTI("rSituationMsgCtrl", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rSituationMsgCtrl::MyDTI::newInstance() const {
    return new (16u) rSituationMsgCtrl;
}

const MtDTI& rSituationMsgCtrl::cSituationData::getDTI() const {
    return rSituationMsgCtrl::cSituationData::DTI;
}

void* rSituationMsgCtrl::cSituationData::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSituationMsgCtrl::cSituationData::DTI)->memAlloc(sz, align, rSituationMsgCtrl::cSituationData::DTI.getID());
}

inline void rSituationMsgCtrl::cSituationData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSituationMsgCtrl::cSituationData::DTI)->memFree(p_addr);
}

rSituationMsgCtrl::cSituationData::~cSituationData() {
}

void rSituationMsgCtrl::cSituationData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroupSerial", &mGroupSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartQuestId", &mStartQuestId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsStartQuestIdStart", &mIsStartQuestIdStart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndQuestId", &mEndQuestId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsEndQuestIdStart", &mIsEndQuestIdStart, 0u, 0u);
}

bool rSituationMsgCtrl::cSituationData::load(MtDataReader& r) {
    nDDOIO::readData(r, mGroupSerial);
    nDDOIO::readData(r, mStartQuestId);
    nDDOIO::readData(r, mIsStartQuestIdStart);
    nDDOIO::readData(r, mEndQuestId);
    nDDOIO::readData(r, mIsEndQuestIdStart);
    return true;
}

inline rSituationMsgCtrl::cSituationData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSituationMsgCtrl::cSituationData::MyDTI rSituationMsgCtrl::cSituationData::DTI("rSituationMsgCtrl::cSituationData", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rSituationMsgCtrl::cSituationData::MyDTI::newInstance() const {
    return new (16u) rSituationMsgCtrl::cSituationData(0u, 0u, false, 0u, false);
}

template MtTypedArray<rSituationMsgCtrl::cSituationData>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rSituationMsgCtrl::cSituationData>&);

template <typename T>
void nDDOIO::writeMtArray(MtDataWriter& w, MtTypedArray<T>& ar) {
    w.writeU32(ar.size());
    for (u32 i = 0; i < ar.size(); i++) {
        static_cast<T*>(ar.getBuffer()[(s32)i])->save(w);
    }
}

template void nDDOIO::writeMtArray(MtDataWriter&, MtTypedArray<rSituationMsgCtrl::cSituationData>&);

