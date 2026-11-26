// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rOmKey.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rOmKey::getDTI() const {
    return rOmKey::DTI;
}

inline void* rOmKey::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rOmKey::DTI)->memAlloc(sz, align, rOmKey::DTI.getID());
}

inline void rOmKey::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rOmKey::DTI)->memFree(p_addr);
}

inline rOmKey::rOmKey() {
    setAttribute(22u);
    mOmKey.mAutoDelete = true;
    mItem.mAutoDelete = true;
}

__attribute__((noinline)) rOmKey::~rOmKey() {
    if (mOmKey.mAutoDelete) {
        u32 v3_0;
        if (mOmKey.mLength != 0) {
            u32 v0_0 = mOmKey.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mOmKey.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mOmKey.mpArray[i0_3];
                    v1_0 = mOmKey.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = v1_0;
        } else {
            v3_0 = 0;
        }
        memset(static_cast<void*>(mOmKey.mpArray), 0, static_cast<size_t>(v3_0) * 8);
    }
    mOmKey.mLength = 0;
    if (mItem.mAutoDelete) {
        u32 v8_0;
        if (mItem.mLength != 0) {
            u32 v5_0 = mItem.mLength;
            unsigned int i5_3 = 0;
            u32 v6_0;
            for (;;) {
                if (mItem.mpArray[i5_3] == nullptr) {
                    v6_0 = v5_0;
                } else {
                    delete mItem.mpArray[i5_3];
                    v6_0 = mItem.mLength;
                }
                if ((i5_3 + 1u) < v6_0) {
                    v5_0 = v6_0;
                    i5_3 += 1u;
                } else {
                    break;
                }
            }
            v8_0 = v6_0;
        } else {
            v8_0 = 0;
        }
        memset(static_cast<void*>(mItem.mpArray), 0, static_cast<size_t>(v8_0) * 8);
    }
    mItem.mLength = 0;
}

void rOmKey::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mOmKey", static_cast<MtObject*>(&mOmKey), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mItem", static_cast<MtObject*>(&mItem), 0u, 0u);
}

MtUI* rOmKey::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

MT_CTSTR rOmKey::getExt() const {
    return "omk";
}

bool rOmKey::load(MtStream& in) {
    MtSerializer sz(65536);
    if (sz.deserializeBinary(in, static_cast<u16>(0), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr) {
        mOmKey.mAutoDelete = true;
        mItem.mAutoDelete = true;
        return true;
    } else {
        return false;
    }
}

bool rOmKey::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(0), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr));
}

inline rOmKey::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOmKey::MyDTI rOmKey::DTI("rOmKey", &::cResource::DTI, 176ul, 0u, 0u);

MtObject* rOmKey::MyDTI::newInstance() const {
    return new (16u) rOmKey;
}

const MtDTI& rOmKey::cOmKey::getDTI() const {
    return rOmKey::cOmKey::DTI;
}

inline void* rOmKey::cOmKey::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rOmKey::cOmKey::DTI)->memAlloc(sz, align, rOmKey::cOmKey::DTI.getID());
}

inline void rOmKey::cOmKey::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rOmKey::cOmKey::DTI)->memFree(p_addr);
}

inline rOmKey::cOmKey::cOmKey() {
    mOmID = -1;
    mKeyType = 0;
    mPos = MtVector3::Zero;
    mbHorizontal = false;
}

rOmKey::cOmKey::~cOmKey() {
}

void rOmKey::cOmKey::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mOmID", &mOmID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mKeyType", &mKeyType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mbHorizontal", &mbHorizontal, 0u, 0u);
}

inline rOmKey::cOmKey::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOmKey::cOmKey::MyDTI rOmKey::cOmKey::DTI("rOmKey::cOmKey", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rOmKey::cOmKey::MyDTI::newInstance() const {
    return new (16u) rOmKey::cOmKey;
}

const MtDTI& rOmKey::cItem::getDTI() const {
    return rOmKey::cItem::DTI;
}

inline void* rOmKey::cItem::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rOmKey::cItem::DTI)->memAlloc(sz, align, rOmKey::cItem::DTI.getID());
}

inline void rOmKey::cItem::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rOmKey::cItem::DTI)->memFree(p_addr);
}

rOmKey::cItem::~cItem() {
}

void rOmKey::cItem::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mItemIndex", &mItemIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mColor, 0u, 0u);
}

inline rOmKey::cItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOmKey::cItem::MyDTI rOmKey::cItem::DTI("rOmKey::cItem", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rOmKey::cItem::MyDTI::newInstance() const {
    return new (16u) rOmKey::cItem;
}

template MtTypedArray<rOmKey::cItem>::~MtTypedArray();

template MtTypedArray<rOmKey::cOmKey>::~MtTypedArray();

