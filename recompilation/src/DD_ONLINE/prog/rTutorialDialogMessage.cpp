// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rTutorialDialogMessage.h"
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

const MtDTI& rTutorialDialogMessage::getDTI() const {
    return rTutorialDialogMessage::DTI;
}

inline void* rTutorialDialogMessage::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTutorialDialogMessage::DTI)->memAlloc(sz, align, rTutorialDialogMessage::DTI.getID());
}

inline void rTutorialDialogMessage::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTutorialDialogMessage::DTI)->memFree(p_addr);
}

MT_CTSTR rTutorialDialogMessage::getExt() const {
    return "tdm";
}

inline rTutorialDialogMessage::rTutorialDialogMessage() {
    mTitleGmdIdx = 0;
    mCategoryGmdIdx = 0;
    setAttribute(22u);
}

rTutorialDialogMessage::~rTutorialDialogMessage() {
    if (mPageInfo.mLength != 0) {
        u32 v0_0 = mPageInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPageInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPageInfo.mpArray[i0_3];
                v1_0 = mPageInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPageInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPageInfo.mpArray));
    }
    mPageInfo.mpArray = nullptr;
    mPageInfo.mBufsiz = 0;
    mPageInfo.mLength = 0;
}

void rTutorialDialogMessage::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTitleGmdIdx", &mTitleGmdIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCategoryGmdIdx", &mCategoryGmdIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPageInfo", static_cast<MtObject*>(&mPageInfo), 0u, 0u);
}

bool rTutorialDialogMessage::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x4D4454u);
    (&w)->writeU32(2u);
    (&w)->writeU32(mTitleGmdIdx);
    (&w)->writeU32(mCategoryGmdIdx);
    (&w)->writeU32(mPageInfo.mLength);
    if (mPageInfo.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            MtObject* t5 = mPageInfo.getBuffer()[static_cast<int>(i0_3)];
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t5) + 8));
            (&w)->writeU32(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t5) + 12));
            if ((i0_3 + 1u) < mPageInfo.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

bool rTutorialDialogMessage::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x4D4454) {
        if ((&r)->readU32() == 2) {
            mTitleGmdIdx = (&r)->readU32();
            mCategoryGmdIdx = (&r)->readU32();
            nDDOIO::readMtArray(r, mPageInfo);
            return true;
        }
    }
    return false;
}

inline rTutorialDialogMessage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTutorialDialogMessage::MyDTI rTutorialDialogMessage::DTI("rTutorialDialogMessage", &::cResource::DTI, 152ul, 0u, 0u);

MtObject* rTutorialDialogMessage::MyDTI::newInstance() const {
    return new (16u) rTutorialDialogMessage;
}

const MtDTI& rTutorialDialogMessage::cDialogPage::getDTI() const {
    return rTutorialDialogMessage::cDialogPage::DTI;
}

void* rTutorialDialogMessage::cDialogPage::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTutorialDialogMessage::cDialogPage::DTI)->memAlloc(sz, align, rTutorialDialogMessage::cDialogPage::DTI.getID());
}

inline void rTutorialDialogMessage::cDialogPage::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTutorialDialogMessage::cDialogPage::DTI)->memFree(p_addr);
}

rTutorialDialogMessage::cDialogPage::~cDialogPage() {
}

void rTutorialDialogMessage::cDialogPage::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTextGmdIdx", &mTextGmdIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mImageId", &mImageId, 0u, 0u);
}

inline rTutorialDialogMessage::cDialogPage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTutorialDialogMessage::cDialogPage::MyDTI rTutorialDialogMessage::cDialogPage::DTI("rTutorialDialogMessage::cDialogPage", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rTutorialDialogMessage::cDialogPage::MyDTI::newInstance() const {
    return new (16u) rTutorialDialogMessage::cDialogPage;
}

template MtTypedArray<rTutorialDialogMessage::cDialogPage>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rTutorialDialogMessage::cDialogPage>&);

