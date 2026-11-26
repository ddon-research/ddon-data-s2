// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundEQ.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "cResource.h"
#include "sSound.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rSoundEQ::getDTI() const {
    return rSoundEQ::DTI;
}

inline void rSoundEQ::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSoundEQ::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rSoundEQ::~rSoundEQ() {
    deleteAllData();
    memFree(mpIdToIndexTbl);
}

MT_CTSTR rSoundEQ::getExt() const {
    return "equr";
}

void rSoundEQ::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

__attribute__((weak)) bool rSoundEQ::load(MtStream& in) {
    u32 fillSize = in.getLength();
    if (fillSize == 0) {
        return false;
    }
    u8* pTempBuffer = static_cast<u8*>(MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memAlloc(fillSize, 16, rSoundEQ::DTI.getID()));
    if (pTempBuffer == nullptr) {
        return false;
    }
    u32 readSize = in.read(pTempBuffer, fillSize);
    if (readSize != fillSize) {
        MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(pTempBuffer);
        return false;
    }
    HEADER* pHeader = reinterpret_cast<HEADER*>(pTempBuffer);
    if (pHeader->Magic != NativeFileMagic || pHeader->Version != NativeFileVersion) {
        MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(pTempBuffer);
        return false;
    }
    mHeader = *pHeader;
    deleteAllData();
    u32* pData = reinterpret_cast<u32*>(pTempBuffer + sizeof(HEADER));
    for (u32 i = 0; i < pHeader->ArrayNum; i++) {
        cEQData* pEQ = new(16) cEQData();
        addData(pEQ);
        u32 id = *pData++;
        u32 category = *pData++;
        sSound::EQParameter* pEQParam = reinterpret_cast<sSound::EQParameter*>(pData);
        pEQ->copy(pEQParam, id, category, MtString("NONE"));
        pData = reinterpret_cast<u32*>(pEQParam + 1);
    }
    MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(pTempBuffer);
    createIdToIndexTbl();
    return true;
}

rSoundEQ::cEQData* rSoundEQ::getEQDataFromId(s32 id) {
    if (mpIdToIndexTbl != nullptr) {
        if (id < static_cast<int>(mIdToIndexTblNum)) {
            if (mpIdToIndexTbl[id] != 0xFFFF) {
                if (mpIdToIndexTbl[id] < mSoundEQ.mLength) {
                    return static_cast<cEQData*>(mSoundEQ.mpArray[mpIdToIndexTbl[id]]);
                }
            }
        }
        return nullptr;
    }
    if (mSoundEQ.mLength == 0) {
        return nullptr;
    }
    u32 i = 0;
    do {
        if (i < mSoundEQ.mLength) {
            if (mSoundEQ.mpArray[static_cast<int>(i)] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mSoundEQ.mpArray[static_cast<int>(i)]) + 8)) == static_cast<unsigned int>(id)) {
                    return static_cast<cEQData*>(mSoundEQ.mpArray[static_cast<int>(i)]);
                }
            }
        }
        i += 1u;
    } while (i < mSoundEQ.mLength);
    return nullptr;
}

__attribute__((weak)) void rSoundEQ::createIdToIndexTbl() {
    u32 eqNum = getEQDataNum();
    u32 maxId = 0;
    for (u32 i = 0; i < eqNum; i++) {
        cEQData* pEQData = getEQData(i);
        if (pEQData != nullptr) {
            u32 eqId = pEQData->getEQId();
            if (eqId != 0xFFFFFFFFu && maxId < eqId) {
                maxId = eqId;
            }
        }
    }
    mIdToIndexTblNum = static_cast<u16>(maxId + 1);
    memFree(mpIdToIndexTbl);
    mpIdToIndexTbl = static_cast<u16*>(memAlloc(mIdToIndexTblNum * sizeof(u16), 16));
    if (mpIdToIndexTbl != nullptr) {
        memset(mpIdToIndexTbl, 0xFF, mIdToIndexTblNum * sizeof(u16));
        for (u32 i = 0; i < eqNum; i++) {
            cEQData* pEQData = getEQData(i);
            if (pEQData != nullptr) {
                u32 eqId = pEQData->getEQId();
                if (eqId != 0xFFFFFFFFu) {
                    mpIdToIndexTbl[eqId] = static_cast<u16>(i);
                }
            }
        }
    }
}

inline rSoundEQ::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundEQ::MyDTI rSoundEQ::DTI("rSoundEQ", &::cResource::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundEQ::MyDTI::newInstance() const {
    return new(16) rSoundEQ();
}

const MtDTI& rSoundEQ::cEQData::getDTI() const {
    return rSoundEQ::cEQData::DTI;
}

inline void rSoundEQ::cEQData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSoundEQ::cEQData::DTI)->memFree(p_addr);
}

rSoundEQ::cEQData::~cEQData() {
}

void rSoundEQ::cEQData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCategory", &mCategory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnable", &mEQData.mEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowType", &mEQData.mLowType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHighType", &mEQData.mHighType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowFreq", &mEQData.mLowFreq, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowGain", &mEQData.mLowGain, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowQ", &mEQData.mLowQ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMidLowFreq", &mEQData.mMidLowFreq, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMidLowGain", &mEQData.mMidLowGain, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMidLowQ", &mEQData.mMidLowQ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMidHighFreq", &mEQData.mMidHighFreq, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMidHighGain", &mEQData.mMidHighGain, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMidHighQ", &mEQData.mMidHighQ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHighFreq", &mEQData.mHighFreq, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHighGain", &mEQData.mHighGain, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHighQ", &mEQData.mHighQ, 0u, 0u);
}

MtUI* rSoundEQ::cEQData::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void rSoundEQ::cEQData::copy(sSound::EQParameter* p_src, u32 id, u32 category, const MtString& com) {
    if (p_src == nullptr) {
        return;
    }
    mId = id;
    mCategory = category;
    mEQData = *p_src;
}

inline rSoundEQ::cEQData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundEQ::cEQData::MyDTI rSoundEQ::cEQData::DTI("rSoundEQ::cEQData", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundEQ::cEQData::MyDTI::newInstance() const {
    return new(16) cEQData();
}

template MtTypedArray<rSoundEQ::cEQData>::~MtTypedArray();

