// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rQuestTextData.h"
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

const MtDTI& rQuestTextData::getDTI() const {
    return rQuestTextData::DTI;
}

MT_CTSTR rQuestTextData::getExt() const {
    return "qtd";
}

rQuestTextData::~rQuestTextData() {
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

void rQuestTextData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mArray", static_cast<MtObject*>(&mArray), 0u, 0u);
}

bool rQuestTextData::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x445451u);
    (&w)->writeU32(2u);
    (&w)->writeU32(mArray.mLength);
    if (mArray.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t3 = mArray.getBuffer()[static_cast<int>(i0_3)];
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 8));
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 12));
            if ((i0_3 + 1u) < mArray.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

bool rQuestTextData::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x445451) {
        if ((&r)->readU32() == 2) {
            nDDOIO::readMtArray(r, mArray);
            return true;
        }
    }
    return false;
}

inline rQuestTextData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rQuestTextData::MyDTI rQuestTextData::DTI("rQuestTextData", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rQuestTextData::MyDTI::newInstance() const {
    return new (16u) rQuestTextData;
}

const MtDTI& rQuestTextData::cTextData::getDTI() const {
    return rQuestTextData::cTextData::DTI;
}

rQuestTextData::cTextData::~cTextData() {
}

void rQuestTextData::cTextData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgGmdIdx", &mMsgGmdIdx, 0u, 0u);
}

inline rQuestTextData::cTextData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rQuestTextData::cTextData::MyDTI rQuestTextData::cTextData::DTI("rQuestTextData::cTextData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rQuestTextData::cTextData::MyDTI::newInstance() const {
    return new (16u) rQuestTextData::cTextData;
}

template MtTypedArray<rQuestTextData::cTextData>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rQuestTextData::cTextData>&);

