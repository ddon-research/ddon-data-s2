// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rAreaInfoStage.h"
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

const MtDTI& rAreaInfoStage::getDTI() const {
    return rAreaInfoStage::DTI;
}

MT_CTSTR rAreaInfoStage::getExt() const {
    return "ars";
}

rAreaInfoStage::~rAreaInfoStage() {
    if (mAreaInfoStage.mLength != 0) {
        u32 v0_0 = mAreaInfoStage.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAreaInfoStage.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAreaInfoStage.mpArray[i0_3];
                v1_0 = mAreaInfoStage.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAreaInfoStage.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAreaInfoStage.mpArray));
    }
    mAreaInfoStage.mpArray = nullptr;
    mAreaInfoStage.mBufsiz = 0;
    mAreaInfoStage.mLength = 0;
}

void rAreaInfoStage::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaInfoStage", static_cast<MtObject*>(&mAreaInfoStage), 0u, 0u);
}

bool rAreaInfoStage::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x535241u);
    (&w)->writeU32(2u);
    (&w)->writeU32(mAreaInfoStage.mLength);
    if (mAreaInfoStage.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t3 = mAreaInfoStage.getBuffer()[static_cast<int>(i0_3)];
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 8));
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 12));
            if ((i0_3 + 1u) < mAreaInfoStage.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

bool rAreaInfoStage::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x535241) {
        if ((&r)->readU32() == 2) {
            nDDOIO::readMtArray(r, mAreaInfoStage);
            return true;
        }
    }
    return false;
}

inline rAreaInfoStage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaInfoStage::MyDTI rAreaInfoStage::DTI("rAreaInfoStage", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rAreaInfoStage::MyDTI::newInstance() const {
    return new (16u) rAreaInfoStage;
}

const MtDTI& rAreaInfoStage::cAreaInfoStage::getDTI() const {
    return rAreaInfoStage::cAreaInfoStage::DTI;
}

rAreaInfoStage::cAreaInfoStage::~cAreaInfoStage() {
}

void rAreaInfoStage::cAreaInfoStage::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAreaId", &mAreaId, 0u, 0u);
}

inline rAreaInfoStage::cAreaInfoStage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaInfoStage::cAreaInfoStage::MyDTI rAreaInfoStage::cAreaInfoStage::DTI("rAreaInfoStage::cAreaInfoStage", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rAreaInfoStage::cAreaInfoStage::MyDTI::newInstance() const {
    return new (16u) rAreaInfoStage::cAreaInfoStage;
}

template MtTypedArray<rAreaInfoStage::cAreaInfoStage>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rAreaInfoStage::cAreaInfoStage>&);

