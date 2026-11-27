// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rLandInfo.h"
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

const MtDTI& rLandInfo::getDTI() const {
    return rLandInfo::DTI;
}

MT_CTSTR rLandInfo::getExt() const {
    return "lai";
}

rLandInfo::~rLandInfo() {
    if (mLandInfo.mLength != 0) {
        u32 v0_0 = mLandInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mLandInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mLandInfo.mpArray[i0_3];
                v1_0 = mLandInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mLandInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mLandInfo.mpArray));
    }
    mLandInfo.mpArray = nullptr;
    mLandInfo.mBufsiz = 0;
    mLandInfo.mLength = 0;
}

void rLandInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mLandInfo", static_cast<MtObject*>(&mLandInfo), 0u, 0u);
}

__attribute__((weak)) bool rLandInfo::save(MtStream& out) {
    MtDataWriter w(out, 0x1000u, 0x1000u);
    w.writeU32(0x49414cu);
    w.writeU32(2u);
    w.writeU32(mLandInfo.mLength);
    for (u32 t1 = 0; t1 < mLandInfo.mLength; ++t1) {
        w.writeU32(mLandInfo[t1]->mLandId);
        w.writeU32(mLandInfo[t1]->mAreaArray.mLength);
        for (u32 t2 = 0; t2 < mLandInfo[t1]->mAreaArray.mLength; ++t2) {
            w.writeU32(mLandInfo[t1]->mAreaArray[t2]->mAreaId);
        }
        }
    return true;
}

bool rLandInfo::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x49414C) {
        if ((&r)->readU32() == 2) {
            nDDOIO::readMtArray(r, mLandInfo);
            return true;
        }
    }
    return false;
}

inline rLandInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rLandInfo::MyDTI rLandInfo::DTI("rLandInfo", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rLandInfo::MyDTI::newInstance() const {
    return new (16u) rLandInfo;
}

const MtDTI& rLandInfo::cLandInfo::getDTI() const {
    return rLandInfo::cLandInfo::DTI;
}

rLandInfo::cLandInfo::~cLandInfo() {
    if (mAreaArray.mLength != 0) {
        u32 v0_0 = mAreaArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAreaArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAreaArray.mpArray[i0_3];
                v1_0 = mAreaArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAreaArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAreaArray.mpArray));
    }
    mAreaArray.mpArray = nullptr;
    mAreaArray.mBufsiz = 0;
    mAreaArray.mLength = 0;
}

void rLandInfo::cLandInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mLandId", &mLandId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaArray", static_cast<MtObject*>(&mAreaArray), 0u, 0u);
}

inline rLandInfo::cLandInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rLandInfo::cLandInfo::MyDTI rLandInfo::cLandInfo::DTI("rLandInfo::cLandInfo", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rLandInfo::cLandInfo::MyDTI::newInstance() const {
    return new (16u) rLandInfo::cLandInfo;
}

const MtDTI& rLandInfo::cLandInfo::cLandAreaInfo::getDTI() const {
    return rLandInfo::cLandInfo::cLandAreaInfo::DTI;
}

rLandInfo::cLandInfo::cLandAreaInfo::~cLandAreaInfo() {
}

void rLandInfo::cLandInfo::cLandAreaInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaId", &mAreaId, 0u, 0u);
}

inline rLandInfo::cLandInfo::cLandAreaInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rLandInfo::cLandInfo::cLandAreaInfo::MyDTI rLandInfo::cLandInfo::cLandAreaInfo::DTI("rLandInfo::cLandInfo::cLandAreaInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rLandInfo::cLandInfo::cLandAreaInfo::MyDTI::newInstance() const {
    return new (16u) rLandInfo::cLandInfo::cLandAreaInfo;
}

template MtTypedArray<rLandInfo::cLandInfo::cLandAreaInfo>::~MtTypedArray();

template MtTypedArray<rLandInfo::cLandInfo>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rLandInfo::cLandInfo>&);

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rLandInfo::cLandInfo::cLandAreaInfo>&);

