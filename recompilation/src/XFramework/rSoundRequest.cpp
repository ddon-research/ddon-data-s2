// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundRequest.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemoryAllocator.h"
#include "cResource.h"
#include "rSoundBank.h"
#include "sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* rSoundRequest::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memAlloc(sz, align, rSoundRequest::DTI.mID);
}

__attribute__((weak)) void rSoundRequest::usage() {
}

const MtDTI& rSoundRequest::getDTI() const {
    return rSoundRequest::DTI;
}

inline void rSoundRequest::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rSoundRequest::~rSoundRequest() {
    MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memFree(mpReqNoToIndexTbl);
    freeMemory();
}

__attribute__((weak)) bool rSoundRequest::load(MtStream& in) {
    DDON_STUB("rSoundRequest::load")
    return {};
}

__attribute__((weak)) bool rSoundRequest::save(MtStream& out) {
    DDON_STUB("rSoundRequest::save")
    return {};
}

MT_CTSTR rSoundRequest::getExt() const {
    return "srqr";
}

rSoundRequest::Element* rSoundRequest::getElement(u32 reqNo) const {
    if (mpReqNoToIndexTbl != nullptr) {
        if (reqNo < mReqNoToIndexTblNum) {
            if (mpReqNoToIndexTbl[reqNo] != 0xFFFF) {
                return &mpElement[mpReqNoToIndexTbl[reqNo]];
            }
        }
        return nullptr;
    }
    if (mElementNum == 0) {
        return nullptr;
    }
    u32 i = 0;
    Element* p2 = mpElement;
    do {
        if (p2->mReqNo == reqNo) {
            return p2;
        }
        i += 1u;
        p2 += static_cast<int>(1);
    } while (i < mElementNum);
    return nullptr;
}

__attribute__((weak)) void rSoundRequest::freeMemory() {
    if (mpRawData != nullptr) {
        for (u32 i = 0; i < mElementNum; i++) {
            if (mpElement[i].mpBank != nullptr) {
                mpElement[i].mpBank->release();
                mpElement[i].mpBank = nullptr;
            }
        }
        MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memFree(mpRawData);
    } else {
        for (u32 i = 0; i < mBankList.mLength; i++) {
            rSoundBank* pBnk = static_cast<rSoundBank*>(mBankList.mpArray[i]);
            if (pBnk != nullptr) {
                pBnk->release();
            }
        }
        if (mBankList.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(mBankList.mpArray);
        }
        mBankList.mpArray = nullptr;
        mBankList.mBufsiz = 0;
        mBankList.mLength = 0;
        for (u32 i = 0; i < mElementNum; i++) {
            if (mpElement[i].mpBank != nullptr) {
                mpElement[i].mpBank->release();
                mpElement[i].mpBank = nullptr;
            }
        }
        MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memFree(mpElement);
        MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memFree(mpSpeakerSets);
        MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memFree(mpSpeakers);
        MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memFree(mpDirectionalCurves);
        MtMemoryAllocator::getAllocator(rSoundRequest::DTI)->memFree(mpDirectionalCurveElements);
    }
    mpRawData = nullptr;
    mpElement = nullptr;
    mElementNum = 0;
    mpSpeakerSets = nullptr;
    mpSpeakers = nullptr;
    mpDirectionalCurves = nullptr;
    mpDirectionalCurveElements = nullptr;
    mDirectionalCurveNum = 0;
    mDirectionalCurveElementNum = 0;
    mSpeakerSetNum = 0;
    mSpeakerNum = 0;
}

__attribute__((weak)) void rSoundRequest::setup() {
    DDON_STUB("rSoundRequest::setup")
    /* stub */
}

__attribute__((weak)) bool rSoundRequest::createReqNoToIndexTbl() {
    DDON_STUB("rSoundRequest::createReqNoToIndexTbl")
    return {};
}

inline rSoundRequest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundRequest::MyDTI rSoundRequest::DTI("rSoundRequest", &::cResource::DTI, 232ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundRequest::MyDTI::newInstance() const {
    return new (16u) rSoundRequest;
}

template MtTypedArray<rSoundBank>::~MtTypedArray();

