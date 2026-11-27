// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rTutorialList.h"
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

const MtDTI& rTutorialList::getDTI() const {
    return rTutorialList::DTI;
}

MT_CTSTR rTutorialList::getExt() const {
    return "tlt";
}

rTutorialList::~rTutorialList() {
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

void rTutorialList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mArray", static_cast<MtObject*>(&mArray), 0u, 0u);
}

bool rTutorialList::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x544C54u);
    (&w)->writeU32(5u);
    (&w)->writeU32(mArray.mLength);
    if (mArray.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t3 = mArray.getBuffer()[static_cast<int>(i0_3)];
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 8));
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 12));
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 16));
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 20));
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t3) + 24));
            if ((i0_3 + 1u) < mArray.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

bool rTutorialList::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x544C54) {
        if ((&r)->readU32() == 5) {
            nDDOIO::readMtArray(r, mArray);
            return true;
        }
    }
    return false;
}

inline rTutorialList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTutorialList::MyDTI rTutorialList::DTI("rTutorialList", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rTutorialList::MyDTI::newInstance() const {
    return new (16u) rTutorialList;
}

const MtDTI& rTutorialList::cTutorialNode::getDTI() const {
    return rTutorialList::cTutorialNode::DTI;
}

rTutorialList::cTutorialNode::~cTutorialNode() {
}

void rTutorialList::cTutorialNode::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSortNo", &mSortNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTitleGmdIdx", &mTitleGmdIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCategory", &mCategory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOpenQuestId", &mOpenQuestId, 0u, 0u);
}

inline rTutorialList::cTutorialNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTutorialList::cTutorialNode::MyDTI rTutorialList::cTutorialNode::DTI("rTutorialList::cTutorialNode", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rTutorialList::cTutorialNode::MyDTI::newInstance() const {
    return new (16u) rTutorialList::cTutorialNode;
}

template MtTypedArray<rTutorialList::cTutorialNode>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rTutorialList::cTutorialNode>&);

