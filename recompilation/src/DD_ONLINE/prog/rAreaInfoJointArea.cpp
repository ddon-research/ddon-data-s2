// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rAreaInfoJointArea.h"
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

const MtDTI& rAreaInfoJointArea::getDTI() const {
    return rAreaInfoJointArea::DTI;
}

MT_CTSTR rAreaInfoJointArea::getExt() const {
    return "arj";
}

rAreaInfoJointArea::~rAreaInfoJointArea() {
    if (mAreaInfoJointArea.mLength != 0) {
        u32 v0_0 = mAreaInfoJointArea.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAreaInfoJointArea.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAreaInfoJointArea.mpArray[i0_3];
                v1_0 = mAreaInfoJointArea.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAreaInfoJointArea.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAreaInfoJointArea.mpArray));
    }
    mAreaInfoJointArea.mpArray = nullptr;
    mAreaInfoJointArea.mBufsiz = 0;
    mAreaInfoJointArea.mLength = 0;
}

void rAreaInfoJointArea::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaInfoJointArea", static_cast<MtObject*>(&mAreaInfoJointArea), 0u, 0u);
}

bool rAreaInfoJointArea::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x4A5241u);
    (&w)->writeU32(2u);
    (&w)->writeU32(mAreaInfoJointArea.mLength);
    if (mAreaInfoJointArea.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t3 = mAreaInfoJointArea.getBuffer()[static_cast<int>(i0_3)];
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 12));
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 8));
            if ((i0_3 + 1u) < mAreaInfoJointArea.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

bool rAreaInfoJointArea::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x4A5241) {
        if ((&r)->readU32() == 2) {
            nDDOIO::readMtArray(r, mAreaInfoJointArea);
            return true;
        }
    }
    return false;
}

inline rAreaInfoJointArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaInfoJointArea::MyDTI rAreaInfoJointArea::DTI("rAreaInfoJointArea", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rAreaInfoJointArea::MyDTI::newInstance() const {
    return new (16u) rAreaInfoJointArea;
}

const MtDTI& rAreaInfoJointArea::cAreaInfoJointArea::getDTI() const {
    return rAreaInfoJointArea::cAreaInfoJointArea::DTI;
}

rAreaInfoJointArea::cAreaInfoJointArea::~cAreaInfoJointArea() {
}

void rAreaInfoJointArea::cAreaInfoJointArea::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaId", &mAreaId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMAJAId", &mMAJAId, 0u, 0u);
}

inline rAreaInfoJointArea::cAreaInfoJointArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaInfoJointArea::cAreaInfoJointArea::MyDTI rAreaInfoJointArea::cAreaInfoJointArea::DTI("rAreaInfoJointArea::cAreaInfoJointArea", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rAreaInfoJointArea::cAreaInfoJointArea::MyDTI::newInstance() const {
    return new (16u) rAreaInfoJointArea::cAreaInfoJointArea;
}

template MtTypedArray<rAreaInfoJointArea::cAreaInfoJointArea>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rAreaInfoJointArea::cAreaInfoJointArea>&);

