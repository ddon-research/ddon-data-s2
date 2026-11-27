// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rAreaInfo.h"
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

const MtDTI& rAreaInfo::getDTI() const {
    return rAreaInfo::DTI;
}

MT_CTSTR rAreaInfo::getExt() const {
    return "ari";
}

rAreaInfo::~rAreaInfo() {
    if (mAreaInfo.mLength != 0) {
        u32 v0_0 = mAreaInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAreaInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAreaInfo.mpArray[i0_3];
                v1_0 = mAreaInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAreaInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAreaInfo.mpArray));
    }
    mAreaInfo.mpArray = nullptr;
    mAreaInfo.mBufsiz = 0;
    mAreaInfo.mLength = 0;
}

void rAreaInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaInfo", static_cast<MtObject*>(&mAreaInfo), 0u, 0u);
}

bool rAreaInfo::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x495241u);
    (&w)->writeU32(2u);
    (&w)->writeU32(mAreaInfo.mLength);
    if (mAreaInfo.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t3 = mAreaInfo.getBuffer()[static_cast<int>(i0_3)];
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 8));
            (&w)->writeS32(static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 12)));
            (&w)->writeS32(static_cast<s32>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 16)));
            if ((i0_3 + 1u) < mAreaInfo.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

bool rAreaInfo::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x495241) {
        if ((&r)->readU32() == 2) {
            nDDOIO::readMtArray(r, mAreaInfo);
            return true;
        }
    }
    return false;
}

inline rAreaInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaInfo::MyDTI rAreaInfo::DTI("rAreaInfo", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rAreaInfo::MyDTI::newInstance() const {
    return new (16u) rAreaInfo;
}

const MtDTI& rAreaInfo::cAreaInfo::getDTI() const {
    return rAreaInfo::cAreaInfo::DTI;
}

rAreaInfo::cAreaInfo::~cAreaInfo() {
}

void rAreaInfo::cAreaInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaId", &mAreaId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPosX", &mPosX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPosY", &mPosY, 0u, 0u);
}

inline rAreaInfo::cAreaInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAreaInfo::cAreaInfo::MyDTI rAreaInfo::cAreaInfo::DTI("rAreaInfo::cAreaInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rAreaInfo::cAreaInfo::MyDTI::newInstance() const {
    return new (16u) rAreaInfo::cAreaInfo;
}

template MtTypedArray<rAreaInfo::cAreaInfo>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rAreaInfo::cAreaInfo>&);

