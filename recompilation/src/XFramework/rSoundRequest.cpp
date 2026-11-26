// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rSoundRequest.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemoryAllocator.h"
#include "cResource.h"
#include "rSoundBank.h"
#include "rSoundSpeakerSet.h"
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
    freeMemory();
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    u32 size = r.getLength();
    mpRawData = static_cast<u8*>(memAlloc(size, 16u));
    if (mpRawData == nullptr) {
        return false;
    }
    r.read(mpRawData, size);
    ReadHeader* header = reinterpret_cast<ReadHeader*>(mpRawData);
    if (header->Magic != NativeFileMagic) {
        freeMemory();
        return false;
    }
    if (header->Version != NativeFileVersion) {
        freeMemory();
        return false;
    }
    setup();
    return createReqNoToIndexTbl();
}

__attribute__((weak)) bool rSoundRequest::save(MtStream& out) {
    if (mElementNum != 0) {
        MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
        WriteHeader header;
        header.Magic = NativeFileMagic;
        header.Version = NativeFileVersion;
        header.numElement = mElementNum;
        header.padding = 0;
        header.numSpeakerSet = mSpeakerSetNum;
        header.numSpeaker = mSpeakerNum;
        header.numDirectionalCurve = mDirectionalCurveNum;
        header.numDirectionalCurveElement = mDirectionalCurveElementNum;
        w.write(&header, sizeof(header));
        w.writeLabel(mpElement);
        if (mpSpeakerSets != nullptr) {
            w.writeLabel(mpSpeakerSets);
        } else {
            w.writeSPtr(-1);
        }
        if (mpSpeakers != nullptr) {
            w.writeLabel(mpSpeakers);
        } else {
            w.writeSPtr(-1);
        }
        if (mpDirectionalCurves != nullptr) {
            w.writeLabel(mpDirectionalCurves);
        } else {
            w.writeSPtr(-1);
        }
        if (mpDirectionalCurveElements != nullptr) {
            w.writeLabel(mpDirectionalCurveElements);
        } else {
            w.writeSPtr(-1);
        }
        for (u32 i = 0; i < mElementNum; i++) {
            Element elm = mpElement[i];
            elm.mpBank = nullptr;
            elm.mpSpeakerSet = nullptr;
            elm.mpPackage = nullptr;
            w.write(&elm, sizeof(elm));
        }
        w.addLabel(mpElement);
        for (u32 i = 0; i < mBankList.size(); i++) {
            rSoundBank* pBnk = static_cast<rSoundBank*>(mBankList.mpArray[static_cast<s32>(i)]);
            w.writeLabel(pBnk);
        }
        for (u32 i = 0; i < mBankList.size(); i++) {
            rSoundBank* pBnk = static_cast<rSoundBank*>(mBankList.mpArray[static_cast<s32>(i)]);
            w.addLabel(pBnk);
            w.write(pBnk->getPath(), strlen(pBnk->getPath()) + 1);
        }
        w.align(16u);
        if (mpSpeakerSets != nullptr) {
            w.addLabel(mpSpeakerSets);
            rSoundSpeakerSetXml::SpeakerSet* pspk_set = static_cast<rSoundSpeakerSetXml::SpeakerSet*>(mpSpeakerSets);
            for (u32 i = 0; i < mSpeakerSetNum; i++, pspk_set++) {
                w.writeU32(pspk_set->mCoordinate);
                w.writeU32(pspk_set->mSpeakerNum);
                if (pspk_set->mpSpeaker != nullptr) {
                    w.writeSPtr(pspk_set->mpSpeaker - static_cast<rSoundSpeakerSetXml::Speaker*>(mpSpeakers));
                } else {
                    w.writeSPtr(-1);
                }
            }
        }
        if (mpSpeakers != nullptr) {
            w.addLabel(mpSpeakers);
            rSoundSpeakerSetXml::Speaker* pspk = static_cast<rSoundSpeakerSetXml::Speaker*>(mpSpeakers);
            for (u32 i = 0; i < mSpeakerNum; i++, pspk++) {
                w.write(&pspk->mPosition, sizeof(pspk->mPosition));
                w.write(&pspk->mOrientation, sizeof(pspk->mOrientation));
                if (pspk->mpDirectionalCurve != nullptr) {
                    w.writeSPtr(pspk->mpDirectionalCurve - static_cast<rSoundSpeakerSetXml::DirectionalCurve*>(mpDirectionalCurves));
                } else {
                    w.writeSPtr(-1);
                }
            }
        }
        if (mpDirectionalCurves != nullptr) {
            w.addLabel(mpDirectionalCurves);
            rSoundSpeakerSetXml::DirectionalCurve* pcurve = static_cast<rSoundSpeakerSetXml::DirectionalCurve*>(mpDirectionalCurves);
            for (u32 i = 0; i < mDirectionalCurveNum; i++, pcurve++) {
                w.writeU32(pcurve->mElementNum);
                w.writeF32(pcurve->mZeroRadianValue);
                w.writeF32(pcurve->mPiRadianValue);
                if (pcurve->mpElement != nullptr) {
                    w.writeSPtr(pcurve->mpElement - static_cast<rSoundSpeakerSetXml::DirectionalCurveElement*>(mpDirectionalCurveElements));
                } else {
                    w.writeSPtr(-1);
                }
            }
        }
        if (mpDirectionalCurveElements != nullptr) {
            w.addLabel(mpDirectionalCurveElements);
            rSoundSpeakerSetXml::DirectionalCurveElement* pcurve_elm = static_cast<rSoundSpeakerSetXml::DirectionalCurveElement*>(mpDirectionalCurveElements);
            for (u32 i = 0; i < mDirectionalCurveElementNum; i++, pcurve_elm++) {
                w.addLabel(pcurve_elm);
                w.writeF32(pcurve_elm->mAngle);
                w.writeF32(pcurve_elm->mValue);
            }
        }
    }
    return true;
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
    ReadHeader* header = reinterpret_cast<ReadHeader*>(mpRawData);
    mElementNum = header->numElement;
    mpElement = reinterpret_cast<Element*>(header + 1);
    for (u32 i = 0; i < mElementNum; i++) {
        if (mpElement[i].mBankFileNameTableIndex != -1) {
            uintptr_t* pOffsetTable = reinterpret_cast<uintptr_t*>(mpRawData + header->FilePathOffset);
            u8* pPath = mpRawData + pOffsetTable[mpElement[i].mBankFileNameTableIndex];
            mpElement[i].mpBank = static_cast<rSoundBank*>(sResource::getInstance()->create(rSoundBank::DTI, reinterpret_cast<MT_CTSTR>(pPath), 1u));
        }
    }
    mDirectionalCurveElementNum = header->numDirectionalCurveElement;
    mpDirectionalCurveElements = mpRawData + header->DirectionalCurveElementOffset;
    mDirectionalCurveNum = header->numDirectionalCurve;
    mpDirectionalCurves = mpRawData + header->DirectionalCurveOffset;
    rSoundSpeakerSetXml::DirectionalCurve* pcurve = static_cast<rSoundSpeakerSetXml::DirectionalCurve*>(mpDirectionalCurves);
    for (u32 i = 0; i < mDirectionalCurveNum; i++) {
        if (reinterpret_cast<intptr>(pcurve[i].mpElement) != -1) {
            pcurve[i].mpElement = &static_cast<rSoundSpeakerSetXml::DirectionalCurveElement*>(mpDirectionalCurveElements)[reinterpret_cast<intptr>(pcurve[i].mpElement)];
        } else {
            pcurve[i].mpElement = nullptr;
        }
    }
    mSpeakerNum = header->numSpeaker;
    mpSpeakers = mpRawData + header->SpeakerOffset;
    rSoundSpeakerSetXml::Speaker* pspk = static_cast<rSoundSpeakerSetXml::Speaker*>(mpSpeakers);
    for (u32 i = 0; i < mSpeakerNum; i++) {
        if (reinterpret_cast<intptr>(pspk[i].mpDirectionalCurve) != -1) {
            pspk[i].mpDirectionalCurve = &pcurve[reinterpret_cast<intptr>(pspk[i].mpDirectionalCurve)];
        } else {
            pspk[i].mpDirectionalCurve = nullptr;
        }
    }
    mSpeakerSetNum = header->numSpeakerSet;
    mpSpeakerSets = mpRawData + header->SpeakerSetOffset;
    rSoundSpeakerSetXml::SpeakerSet* pspk_set = static_cast<rSoundSpeakerSetXml::SpeakerSet*>(mpSpeakerSets);
    for (u32 i = 0; i < mSpeakerSetNum; i++) {
        if (reinterpret_cast<intptr>(pspk_set[i].mpSpeaker) != -1) {
            pspk_set[i].mpSpeaker = &pspk[reinterpret_cast<intptr>(pspk_set[i].mpSpeaker)];
        } else {
            pspk_set[i].mpSpeaker = nullptr;
        }
    }
    for (u32 i = 0; i < mElementNum; i++) {
        if (mpElement[i].mSpeakerSetIndex == -1) {
            mpElement[i].mpSpeakerSet = nullptr;
        } else {
            mpElement[i].mpSpeakerSet = &pspk_set[mpElement[i].mSpeakerSetIndex];
        }
    }
}

__attribute__((weak)) bool rSoundRequest::createReqNoToIndexTbl() {
    u32 maxReqNo = 0;
    for (u32 i = 0; i < mElementNum; i++) {
        if (maxReqNo < mpElement[i].mReqNo) {
            maxReqNo = mpElement[i].mReqNo;
        }
    }
    mReqNoToIndexTblNum = maxReqNo + 1;
    memFree(mpReqNoToIndexTbl);
    mpReqNoToIndexTbl = static_cast<u16*>(memAlloc(mReqNoToIndexTblNum * sizeof(u16), 16u));
    if (mpReqNoToIndexTbl == nullptr) {
        return false;
    }
    memset(mpReqNoToIndexTbl, 0xFF, mReqNoToIndexTblNum * sizeof(u16));
    for (u32 i = 0; i < mElementNum; i++) {
        if (mpElement[i].mReqNo != 0xFFFF) {
            mpReqNoToIndexTbl[mpElement[i].mReqNo] = i;
        }
    }
    return true;
}

inline rSoundRequest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundRequest::MyDTI rSoundRequest::DTI("rSoundRequest", &::cResource::DTI, 232ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundRequest::MyDTI::newInstance() const {
    return new (16u) rSoundRequest;
}

template MtTypedArray<rSoundBank>::~MtTypedArray();

