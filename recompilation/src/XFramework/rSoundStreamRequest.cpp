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

#include "rSoundSpeakerSet.h"
#include <string.h>
#include "sSound.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* rSoundStreamRequest::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memAlloc(sz, align, rSoundStreamRequest::DTI.mID);
}

inline rSoundStreamRequest::SoundSource::SoundSource() {
    mSampleNum = 0;
    mChannelNum = 0;
    mStreamLength = 0;
    mLoopStart = 0;
    mLoopEnd = 0;
    mReadType = 0;
    mReadMode = 0;
    mDTIID = rSoundSourceStreamAT9::DTI.mID;
    mFormat = 0;
    mSourceIndex = 0xFFFFFFFF;
    mpResourcePath = nullptr;
    mpSource = nullptr;
    mpStreamSourcePackage = nullptr;
}

inline void* rSoundStreamRequest::SoundSource::operator new[](size_t size) {
    return MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memAlloc(size, 16u, rSoundStreamRequest::DTI.mID);
}

inline u32 rSoundStreamRequest::SoundSource::getSampleNum() const {
    return mSampleNum;
}

inline u32 rSoundStreamRequest::SoundSource::getSampleRate() const {
    return mSampleRate;
}

inline u32 rSoundStreamRequest::SoundSource::getLength() const {
    return mStreamLength;
}

inline u32 rSoundStreamRequest::SoundSource::getReadType() const {
    return mReadType;
}

inline u32 rSoundStreamRequest::SoundSource::getResourceDTI() const {
    return mDTIID;
}

inline u32 rSoundStreamRequest::SoundSource::getResourceFormat() const {
    return mFormat;
}

inline rSoundSource* rSoundStreamRequest::SoundSource::getSource() const {
    return mpSource;
}

inline void rSoundStreamRequest::SoundSource::setReadType(u32 type, u32 mode) {
    mReadType = type;
    mReadMode = mode;
}

inline void rSoundStreamRequest::SoundSource::setSourceIndex(u32 sourceIndex) {
    mSourceIndex = sourceIndex;
}

inline void rSoundStreamRequest::SoundSource::setResourceDTI(u32 id) {
    mDTIID = id;
}

inline void rSoundStreamRequest::SoundSource::setStreamSourcePackage(rSoundStreamSourcePackage* pStreamSourcePackage) {
    if (mpStreamSourcePackage == nullptr) {
        mpStreamSourcePackage = pStreamSourcePackage;
        mpStreamSourcePackage->addRef();
    }
}

inline bool rSoundStreamRequest::SoundSource::setPath(MT_CTSTR path) {
    if (strlen(path) >= 1023) {
        return false;
    }
    mpResourcePath = path;
    return true;
}

inline void rSoundStreamRequest::SoundSource::makeStreamInfo(rSoundStreamRequest::StreamInfo* pinfo) {
    if (pinfo != nullptr) {
        mStreamLength = pinfo->mStreamLength;
        mSampleNum = pinfo->mSampleNum;
        mChannelNum = pinfo->mChannelNum;
        mSampleRate = pinfo->mSampleRate;
        mLoopStart = pinfo->mLoopStart;
        mLoopEnd = pinfo->mLoopEnd;
        mFormat = pinfo->mFormat;
    } else if (mpSource != nullptr) {
        rSoundSource::Descriptor desc = mpSource->getDescriptor();
        mStreamLength = desc.mStreamSize;
        mSampleNum = desc.mSamples;
        mChannelNum = desc.mChannels;
        mSampleRate = desc.mSampleRate;
        mLoopStart = desc.mLoopStart;
        mLoopEnd = desc.mLoopEnd;
        mFormat = mpSource->getFormat();
    }
}

inline u32 rSoundSource::getFormat() const {
    return mDescriptor.mFormat;
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
    mSourceNum = header->numStream;
    mElementNum = header->numElement;
    mpElement = reinterpret_cast<Element*>(mpRawData + header->ElementOffset);
    mpSoundSource = new SoundSource[mSourceNum];
    for (u32 i = 0; i < mSourceNum; i++) {
        StreamInfo* pinfo = &reinterpret_cast<StreamInfo*>(mpRawData + header->StreamInfoOffset)[i];
        MT_CHAR* pPath = reinterpret_cast<MT_CHAR*>(mpRawData + pinfo->mPathOffset);
        Element* pElm = nullptr;
        for (u32 j = 0; j < mElementNum; j++) {
            if (mpElement[j].mSrcFileNameTableIndex == static_cast<s32>(i)) {
                pElm = &mpElement[j];
                break;
            }
        }
        if (pElm == nullptr) {
            freeMemory();
            return false;
        }
        u32 mode = 1;
        if (pElm->mReadType == SOUND_STREAM_READ_DISK) {
            mode |= 0x100;
            switch (pElm->mDiskLocation) {
            case 2:
                mode |= 4;
                break;
            case 3:
                mode |= 8;
                break;
            }
        }
        SoundSource*& psource = mpSoundSource;
        psource[i].setSourceIndex(i);
        mpSoundSource[i].setReadType(pElm->mReadType, mode);
        if (sSound::getInstance()->getIsStreamSourcePackage() && !(mode & 4) && !(mode & 8)) {
            if (mpStreamSourcePackage == nullptr) {
                mpStreamSourcePackage = static_cast<rSoundStreamSourcePackage*>(sResource::getInstance()->create(rSoundStreamSourcePackage::DTI, getPath(), 1u));
                if (mpStreamSourcePackage == nullptr) {
                    freeMemory();
                    return false;
                }
            }
            mpSoundSource[i].setStreamSourcePackage(mpStreamSourcePackage);
        }
        if (!mpSoundSource[i].setPath(pPath)) {
            freeMemory();
            return false;
        }
        mpSoundSource[i].makeStreamInfo(pinfo);
        mpSoundSource[i].setResourceDTI(pinfo->mDTIID);
        if (pElm->mReadType == SOUND_STREAM_READ_MEMORY) {
            SoundSource* pcur = &mpSoundSource[i];
            rSoundSource* created = nullptr;
            if (pcur->mpStreamSourcePackage != nullptr) {
                if (pcur->mpSource == nullptr || pcur->mpSource->getBuffer() == nullptr) {
                    pcur->mpSource = pcur->mpStreamSourcePackage->setSourceParamFromPackage(pcur->mSourceIndex, pcur->mpSource);
                }
                created = pcur->mpSource;
            } else if (pcur->mpSource != nullptr) {
                created = pcur->mpSource;
            } else if (pcur->mpResourcePath != nullptr) {
                pcur->mpSource = static_cast<rSoundSource*>(sResource::getInstance()->create(*MtDTI::from(pcur->mDTIID), pcur->mpResourcePath, pcur->mReadMode));
                if (pcur->mpSource != nullptr) {
                    created = pcur->mpSource;
                }
            }
            if (created == nullptr) {
                freeMemory();
                return false;
            }
        }
    }
    for (u32 i = 0; i < mElementNum; i++) {
        if (mpElement[i].mSrcFileNameTableIndex != -1) {
            mpElement[i].mpSource = &mpSoundSource[mpElement[i].mSrcFileNameTableIndex];
        }
    }
    mDirectionalCurveElementNum = header->numDirectionalCurveElement;
    mpDirectionalCurveElements = mpRawData + header->DirectionalCurveElementOffset;
    mDirectionalCurveNum = header->numDirectionalCurve;
    mpDirectionalCurves = mpRawData + header->DirectionalCurveOffset;
    rSoundSpeakerSetXml::DirectionalCurve* pcurve = static_cast<rSoundSpeakerSetXml::DirectionalCurve*>(mpDirectionalCurves);
    for (u32 i = 0; i < mDirectionalCurveNum; i++) {
        if (reinterpret_cast<intptr>(pcurve[i].mpElement) != -1) {
            pcurve[i].mpElement = &static_cast<rSoundSpeakerSetXml::DirectionalCurveElement*>(mpDirectionalCurves)[reinterpret_cast<intptr>(pcurve[i].mpElement)];
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
    return createReqNoToIndexTbl();
}

__attribute__((weak)) bool rSoundStreamRequest::loadEnd() {
    if (mpSoundSource == nullptr) {
        return false;
    }
    for (u32 i = 0; i < mSourceNum; i++) {
        if (mpSoundSource[i].getReadType() == SOUND_STREAM_READ_MEMORY) {
            rSoundSource* pSource = mpSoundSource[i].getSource();
            if (pSource != nullptr) {
                if (pSource->isUsage()) {
                    pSource->prepareToBuffer();
                } else {
                    pSource->release();
                }
            }
        }
    }
    return true;
}

__attribute__((weak)) bool rSoundStreamRequest::save(MtStream& out) {
    if (mElementNum != 0) {
        MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
        WriteHeader header;
        header.Magic = NativeFileMagic;
        header.Version = NativeFileVersion;
        header.numStream = mSourceNum;
        header.numElement = mElementNum;
        header.numSpeakerSet = mSpeakerSetNum;
        header.numSpeaker = mSpeakerNum;
        header.numDirectionalCurve = mDirectionalCurveNum;
        header.numDirectionalCurveElement = mDirectionalCurveElementNum;
        w.write(&header, sizeof(header));
        w.writeUPtr(sizeof(ReadHeader));
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
        for (u32 i = 0; i < mSourceNum; i++) {
            SoundSource* psrc = &mpSoundSource[i];
            w.writeLabel(reinterpret_cast<MT_CTSTR>(reinterpret_cast<size_t>(psrc->getSource()) + 0xC));
            w.writeU32(psrc->getLength());
            w.writeU32(psrc->getSampleNum());
            w.writeU32(psrc->getChannelNum());
            w.writeU32(psrc->getSampleRate());
            w.writeS32(psrc->getLoopStart());
            w.writeS32(psrc->getLoopEnd());
            w.writeU32(psrc->getResourceDTI());
            w.writeU32(psrc->getResourceFormat());
        }
        w.addLabel(mpElement);
        for (u32 i = 0; i < mElementNum; i++) {
            Element elm = mpElement[i];
            elm.mpSpeakerSet = nullptr;
            elm.mpSource = nullptr;
            w.write(&elm, sizeof(elm));
        }
        w.align(16u);
        if (mpSpeakerSets != nullptr) {
            w.addLabel(mpSpeakerSets);
            rSoundSpeakerSetXml::SpeakerSet* pspk_set = static_cast<rSoundSpeakerSetXml::SpeakerSet*>(mpSpeakerSets);
            for (u32 i = 0; i < mSpeakerSetNum; i++, pspk_set++) {
                w.writeU32(pspk_set->mCoordinate);
                w.writeU32(pspk_set->mSpeakerNum);
                if (pspk_set->mpSpeaker != nullptr && mpSpeakers != nullptr) {
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
                if (pspk->mpDirectionalCurve != nullptr && mpDirectionalCurves != nullptr) {
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
                if (pcurve->mpElement != nullptr && mpDirectionalCurveElements != nullptr) {
                    w.writeSPtr(pcurve->mpElement - static_cast<rSoundSpeakerSetXml::DirectionalCurveElement*>(mpDirectionalCurveElements));
                } else {
                    w.writeS32(-1);
                }
            }
        }
        if (mpDirectionalCurveElements != nullptr) {
            w.addLabel(mpDirectionalCurveElements);
            rSoundSpeakerSetXml::DirectionalCurveElement* pcurve_elm = static_cast<rSoundSpeakerSetXml::DirectionalCurveElement*>(mpDirectionalCurveElements);
            for (u32 i = 0; i < mDirectionalCurveElementNum; i++, pcurve_elm++) {
                w.writeF32(pcurve_elm->mAngle);
                w.writeF32(pcurve_elm->mValue);
            }
        }
        for (u32 i = 0; i < mSourceNum; i++) {
            SoundSource* psrc = &mpSoundSource[i];
            if (psrc->getSource() != nullptr) {
                w.addLabel(psrc->getSource()->getPath());
                w.writeString(psrc->getSource()->getPath());
            }
        }
    }
    return true;
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
    u32 maxReqNo = 0;
    for (u32 i = 0; i < mElementNum; i++) {
        if (maxReqNo < mpElement[i].mReqNo) {
            maxReqNo = mpElement[i].mReqNo;
        }
    }
    mReqNoToIndexTblNum = maxReqNo + 1;
    MtMemoryAllocator::getAllocator(rSoundStreamRequest::DTI)->memFree(mpReqNoToIndexTbl);
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

