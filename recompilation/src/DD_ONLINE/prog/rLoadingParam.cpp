// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rLoadingParam.h"
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

const MtDTI& rLoadingParam::getDTI() const {
    return rLoadingParam::DTI;
}

rLoadingParam::~rLoadingParam() {
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

MT_CTSTR rLoadingParam::getExt() const {
    return "ldp";
}

MT_CTSTR rLoadingParam::getName() const {
    return "rLoadingParam";
}

void rLoadingParam::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mArray", static_cast<MtObject*>(&mArray), 0u, 0u);
}

bool rLoadingParam::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(in, static_cast<u16>(4), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr;
}

bool rLoadingParam::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeBinary(out, static_cast<u16>(4), static_cast<MtObject*>(this), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(&rLoadingParam::DTI));
}

void rLoadingParam::clear() {
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

inline rLoadingParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rLoadingParam::MyDTI rLoadingParam::DTI("rLoadingParam", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rLoadingParam::MyDTI::newInstance() const {
    return new (16u) rLoadingParam;
}

const MtDTI& rLoadingParam::cDataList::getDTI() const {
    return rLoadingParam::cDataList::DTI;
}

rLoadingParam::cDataList::~cDataList() {
    if (mList.mLength != 0) {
        u32 v0_0 = mList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mList.mpArray[i0_3];
                v1_0 = mList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mList.mpArray));
    }
    mList.mpArray = nullptr;
    mList.mBufsiz = 0;
    mList.mLength = 0;
}

void rLoadingParam::cDataList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaNo", &mAreaNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mList", static_cast<MtObject*>(&mList), 0u, 0u);
}

bool rLoadingParam::cDataList::load(MtDataReader& r) {
    return true;
}

bool rLoadingParam::cDataList::save(MtDataWriter& w) {
    return true;
}

inline rLoadingParam::cDataList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rLoadingParam::cDataList::MyDTI rLoadingParam::cDataList::DTI("rLoadingParam::cDataList", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* rLoadingParam::cDataList::MyDTI::newInstance() const {
    return new (16u) cDataList;
}

const MtDTI& rLoadingParam::cData::getDTI() const {
    return rLoadingParam::cData::DTI;
}

rLoadingParam::cData::~cData() {
}

void rLoadingParam::cData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mMsgIdx", &mMsgIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mImgId", &mImgId, 0u, 0u);
}

bool rLoadingParam::cData::load(MtDataReader& r) {
    return true;
}

bool rLoadingParam::cData::save(MtDataWriter& w) {
    return true;
}

void rLoadingParam::cData::copy(rLoadingParam::cData* pSrc, bool isXml) {
    if (pSrc == nullptr) {
        return;
    }
    mMsgIdx = pSrc->mMsgIdx;
    mImgId = pSrc->mImgId;
}

inline rLoadingParam::cData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rLoadingParam::cData::MyDTI rLoadingParam::cData::DTI("rLoadingParam::cData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rLoadingParam::cData::MyDTI::newInstance() const {
    return new (16u) rLoadingParam::cData;
}

template MtTypedArray<rLoadingParam::cData>::~MtTypedArray();

template MtTypedArray<rLoadingParam::cDataList>::~MtTypedArray();

