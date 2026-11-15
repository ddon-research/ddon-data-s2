// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundStreamRequest.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemoryAllocator.h"
#include "cResource.h"
#include "rSoundSource.h"
#include "rSoundSourcePS4_h.h"
#include "rSoundStreamSourcePackage.h"
#include "sResource.h"
#include "sSound.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* rSoundStreamRequest::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memAlloc(sz, align, rSoundStreamRequest::DTI.mID);
}

__attribute__((weak)) void rSoundStreamRequest::usage() {
}

const MtDTI& rSoundStreamRequest::getDTI() const {
    return rSoundStreamRequest::DTI;
}

inline void rSoundStreamRequest::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rSoundStreamRequest::~rSoundStreamRequest() {
    MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpReqNoToIndexTbl);
    freeMemory();
    if (mpStreamSourcePackage != nullptr) {
        mpStreamSourcePackage->release();
        mpStreamSourcePackage = nullptr;
    }
}

__attribute__((weak)) bool rSoundStreamRequest::load(MtStream& in) {
    DDON_STUB("rSoundStreamRequest::load")
    return {};
}

__attribute__((weak)) bool rSoundStreamRequest::loadEnd() {
    DDON_STUB("rSoundStreamRequest::loadEnd")
    return {};
}

__attribute__((weak)) bool rSoundStreamRequest::save(MtStream& out) {
    DDON_STUB("rSoundStreamRequest::save")
    return {};
}

MT_CTSTR rSoundStreamRequest::getExt() const {
    return "stqr";
}

rSoundStreamRequest::Element* rSoundStreamRequest::getElement(u32 reqNo) const {
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

__attribute__((weak)) void rSoundStreamRequest::freeMemory() {
    if (mpRawData != nullptr) {
        MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpRawData);
    } else {
        if (mSourceResourceList.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(mSourceResourceList.mpArray);
        }
        mSourceResourceList.mpArray = nullptr;
        mSourceResourceList.mLength = 0;
        mSourceResourceList.mBufsiz = 0;
        MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpElement);
        MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpWave);
        MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpSpeakerSets);
        MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpSpeakers);
        MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpDirectionalCurves);
        MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpDirectionalCurveElements);
    }
    if (mpSoundSource != nullptr) {
        delete[] mpSoundSource;
    }
    mpRawData = nullptr;
    mpElement = nullptr;
    mElementNum = 0;
    mpSoundSource = nullptr;
    mpWave = nullptr;
    mDirectionalCurveElementNum = 0;
    mSpeakerNum = 0;
    mDirectionalCurveNum = 0;
    mpDirectionalCurveElements = nullptr;
    mSpeakerSetNum = 0;
    mpDirectionalCurves = nullptr;
    mpSpeakers = nullptr;
    mpSpeakerSets = nullptr;
    mLoadedSize = 0;
}

__attribute__((weak)) bool rSoundStreamRequest::createReqNoToIndexTbl() {
    DDON_STUB("rSoundStreamRequest::createReqNoToIndexTbl")
    return {};
}

inline rSoundStreamRequest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundStreamRequest::MyDTI rSoundStreamRequest::DTI("rSoundStreamRequest", &::cResource::DTI, 264ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundStreamRequest::MyDTI::newInstance() const {
    return new (16u) rSoundStreamRequest;
}

inline rSoundStreamRequest::SoundSource::~SoundSource() {
    if (mpStreamSourcePackage != nullptr) {
        mpStreamSourcePackage->release();
        mpStreamSourcePackage = nullptr;
    }
    if (mpSource != nullptr) {
        mpSource->release();
        mpSource = nullptr;
    }
}

inline void rSoundStreamRequest::SoundSource::operator delete[](void* ptr) {
    MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(ptr);
}

u32 rSoundStreamRequest::SoundSource::getChannelNum() const {
    return mChannelNum;
}

s32 rSoundStreamRequest::SoundSource::getLoopStart() const {
    return mLoopStart;
}

s32 rSoundStreamRequest::SoundSource::getLoopEnd() const {
    return mLoopEnd;
}

rSoundSource* rSoundStreamRequest::SoundSource::createResource() {
    if (mpStreamSourcePackage != nullptr) {
        if (mpSource != nullptr) {
            if (mpSource->getBuffer() == nullptr) {
                mpSource = mpStreamSourcePackage->setSourceParamFromPackage(mSourceIndex, mpSource);
            }
        } else {
            mpSource = mpStreamSourcePackage->setSourceParamFromPackage(mSourceIndex, static_cast<rSoundSource*>(nullptr));
        }
    } else {
        if (mpSource == nullptr) {
            if (mpResourcePath != nullptr) {
                if ((mpSource = static_cast<rSoundSource*>((sResource::mpInstance)->create(*MtDTI::from(mDTIID), mpResourcePath, mReadMode))) != nullptr) {
                    mpSource;
                    return mpSource;
                }
            }
            return nullptr;
        }
    }
    return mpSource;
}

template MtTypedArray<rSoundSource>::~MtTypedArray();

