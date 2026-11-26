// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rTblMenuOption.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rTblMenuOption::getDTI() const {
    return rTblMenuOption::DTI;
}

inline void* rTblMenuOption::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTblMenuOption::DTI)->memAlloc(sz, align, rTblMenuOption::DTI.getID());
}

inline void rTblMenuOption::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTblMenuOption::DTI)->memFree(p_addr);
}

inline rTblMenuOption::rTblMenuOption() {
    setAttribute(18u);
    mCtgr.mAutoDelete = true;
}

rTblMenuOption::~rTblMenuOption() {
    if (mCtgr.mLength != 0) {
        u32 v0_0 = mCtgr.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCtgr.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mCtgr.mpArray[i0_3];
                v1_0 = mCtgr.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCtgr.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCtgr.mpArray));
    }
    mCtgr.mpArray = nullptr;
    mCtgr.mBufsiz = 0;
    mCtgr.mLength = 0;
}

MT_CTSTR rTblMenuOption::getExt() const {
    return "tmo";
}

MT_CTSTR rTblMenuOption::getName() const {
    return "rTblMenuOption";
}

void rTblMenuOption::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCtgr", static_cast<MtObject*>(&mCtgr), 0u, 0u);
}

bool rTblMenuOption::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(4), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rTblMenuOption::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(4), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rTblMenuOption::DTI));
}

void rTblMenuOption::clear() {
    if (mCtgr.mLength != 0) {
        u32 v0_0 = mCtgr.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCtgr.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mCtgr.mpArray[i0_3];
                v1_0 = mCtgr.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCtgr.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCtgr.mpArray));
    }
    mCtgr.mpArray = nullptr;
    mCtgr.mBufsiz = 0;
    mCtgr.mLength = 0;
}

inline rTblMenuOption::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTblMenuOption::MyDTI rTblMenuOption::DTI("rTblMenuOption", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rTblMenuOption::MyDTI::newInstance() const {
    return new (16u) rTblMenuOption;
}

const MtDTI& rTblMenuOption::cCtgr::getDTI() const {
    return rTblMenuOption::cCtgr::DTI;
}

inline void rTblMenuOption::cCtgr::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTblMenuOption::cCtgr::DTI)->memFree(p_addr);
}

rTblMenuOption::cCtgr::~cCtgr() {
    if (mTab.mLength != 0) {
        u32 v0_0 = mTab.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTab.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTab.mpArray[i0_3];
                v1_0 = mTab.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTab.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mTab.mpArray));
    }
    mTab.mpArray = nullptr;
    mTab.mBufsiz = 0;
    mTab.mLength = 0;
}

void rTblMenuOption::cCtgr::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSortId", &mSortId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCtgrId", &mCtgrId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTab", static_cast<MtObject*>(&mTab), 0u, 0u);
}

bool rTblMenuOption::cCtgr::load(MtDataReader& r) {
    return true;
}

bool rTblMenuOption::cCtgr::save(MtDataWriter& w) {
    return true;
}

inline rTblMenuOption::cCtgr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTblMenuOption::cCtgr::MyDTI rTblMenuOption::cCtgr::DTI("rTblMenuOption::cCtgr", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* rTblMenuOption::cCtgr::MyDTI::newInstance() const {
    return new (16u) cCtgr;
}

const MtDTI& rTblMenuOption::cTab::getDTI() const {
    return rTblMenuOption::cTab::DTI;
}

inline void* rTblMenuOption::cTab::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTblMenuOption::cTab::DTI)->memAlloc(sz, align, rTblMenuOption::cTab::DTI.getID());
}

inline void rTblMenuOption::cTab::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTblMenuOption::cTab::DTI)->memFree(p_addr);
}

rTblMenuOption::cTab::~cTab() {
}

void rTblMenuOption::cTab::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSortId", &mSortId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTabId", &mTabId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCaption", static_cast<MtObject*>(&mCaption), 0u, 0u);
}

bool rTblMenuOption::cTab::load(MtDataReader& r) {
    return true;
}

bool rTblMenuOption::cTab::save(MtDataWriter& w) {
    return true;
}

inline rTblMenuOption::cTab::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTblMenuOption::cTab::MyDTI rTblMenuOption::cTab::DTI("rTblMenuOption::cTab", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rTblMenuOption::cTab::MyDTI::newInstance() const {
    return new (16u) rTblMenuOption::cTab;
}

const MtDTI& rTblMenuOption::cCaption::getDTI() const {
    return rTblMenuOption::cCaption::DTI;
}

inline void rTblMenuOption::cCaption::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTblMenuOption::cCaption::DTI)->memFree(p_addr);
}

rTblMenuOption::cCaption::~cCaption() {
    if (mData.mLength != 0) {
        u32 v0_0 = mData.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mData.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mData.mpArray[i0_3];
                v1_0 = mData.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mData.mpArray));
    }
    mData.mpArray = nullptr;
    mData.mBufsiz = 0;
    mData.mLength = 0;
}

void rTblMenuOption::cCaption::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSortId", &mSortId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCaptionId", &mCaptionId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mData", static_cast<MtObject*>(&mData), 0u, 0u);
}

bool rTblMenuOption::cCaption::load(MtDataReader& r) {
    return true;
}

bool rTblMenuOption::cCaption::save(MtDataWriter& w) {
    return true;
}

inline rTblMenuOption::cCaption::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTblMenuOption::cCaption::MyDTI rTblMenuOption::cCaption::DTI("rTblMenuOption::cCaption", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* rTblMenuOption::cCaption::MyDTI::newInstance() const {
    return new (16u) cCaption;
}

const MtDTI& rTblMenuOption::cData::getDTI() const {
    return rTblMenuOption::cData::DTI;
}

inline void* rTblMenuOption::cData::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTblMenuOption::cData::DTI)->memAlloc(sz, align, rTblMenuOption::cData::DTI.getID());
}

inline void rTblMenuOption::cData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTblMenuOption::cData::DTI)->memFree(p_addr);
}

rTblMenuOption::cData::~cData() {
    if (mPulldown.mLength != 0) {
        u32 v0_0 = mPulldown.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mPulldown.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mPulldown.mpArray[i0_3];
                v1_0 = mPulldown.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mPulldown.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mPulldown.mpArray));
    }
    mPulldown.mpArray = nullptr;
    mPulldown.mBufsiz = 0;
    mPulldown.mLength = 0;
}

void rTblMenuOption::cData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSortId", &mSortId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDataId", &mDataId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCtrlType", &mCtrlType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPulldown", static_cast<MtObject*>(&mPulldown), 0u, 0u);
}

bool rTblMenuOption::cData::load(MtDataReader& r) {
    return true;
}

bool rTblMenuOption::cData::save(MtDataWriter& w) {
    return true;
}

inline rTblMenuOption::cData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTblMenuOption::cData::MyDTI rTblMenuOption::cData::DTI("rTblMenuOption::cData", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* rTblMenuOption::cData::MyDTI::newInstance() const {
    return new (16u) rTblMenuOption::cData;
}

const MtDTI& rTblMenuOption::cPulldown::getDTI() const {
    return rTblMenuOption::cPulldown::DTI;
}

inline void* rTblMenuOption::cPulldown::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTblMenuOption::cPulldown::DTI)->memAlloc(sz, align, rTblMenuOption::cPulldown::DTI.getID());
}

inline void rTblMenuOption::cPulldown::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTblMenuOption::cPulldown::DTI)->memFree(p_addr);
}

rTblMenuOption::cPulldown::~cPulldown() {
}

void rTblMenuOption::cPulldown::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSortId", &mSortId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPulldownId", &mPulldownId, 0u, 0u);
}

bool rTblMenuOption::cPulldown::load(MtDataReader& r) {
    return true;
}

bool rTblMenuOption::cPulldown::save(MtDataWriter& w) {
    return true;
}

inline rTblMenuOption::cPulldown::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTblMenuOption::cPulldown::MyDTI rTblMenuOption::cPulldown::DTI("rTblMenuOption::cPulldown", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rTblMenuOption::cPulldown::MyDTI::newInstance() const {
    return new (16u) rTblMenuOption::cPulldown;
}

template MtTypedArray<rTblMenuOption::cCaption>::~MtTypedArray();

template MtTypedArray<rTblMenuOption::cCtgr>::~MtTypedArray();

template MtTypedArray<rTblMenuOption::cData>::~MtTypedArray();

template MtTypedArray<rTblMenuOption::cPulldown>::~MtTypedArray();

template MtTypedArray<rTblMenuOption::cTab>::~MtTypedArray();

