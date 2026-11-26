// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundDirectionalSet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cResource.h"

#include <string.h>
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rSoundDirectionalSet::usage() {
}

const MtDTI& rSoundDirectionalSet::getDTI() const {
    return rSoundDirectionalSet::DTI;
}

inline void* rSoundDirectionalSet::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memAlloc(sz, align, rSoundDirectionalSet::DTI.mID);
}

inline void rSoundDirectionalSet::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memFree(p_addr);
}

rSoundDirectionalSet::~rSoundDirectionalSet() {
    u16* t0 = mpIdToIndexTbl;
    MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memFree(static_cast<void*>(t0));
    void* t1 = mpRawData;
    MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memFree(t1);
}

__attribute__((weak)) bool rSoundDirectionalSet::load(MtStream& in) {
    MtDataReader r(in, 4096);
    u32 size = r.getLength();
    void* pData = MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memAlloc(size, 16, rSoundDirectionalSet::DTI.getID());
    if (pData == nullptr) {
        return false;
    }
    if (r.read(pData, size) != size) {
        MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memFree(pData);
        return false;
    }
    NATIVE_FILE_HEADER* header = static_cast<NATIVE_FILE_HEADER*>(pData);
    if (header->Magic != NativeFileMagic || header->Version != NativeFileVersion) {
        MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memFree(pData);
        return false;
    }
    void* pRawData = mpRawData;
    MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memFree(pRawData);
    mpRawData = pData;
    mListNum = header->ListNum;
    mCurveNum = header->CurveNum;
    mpLists = reinterpret_cast<List*>(header + 1);
    mpCurves = reinterpret_cast<DirectionalCurve*>(mpLists + mListNum);
    for (u32 i = 0; i < mListNum; i++) {
        if (reinterpret_cast<size_t>(mpLists[i].mpCurve) == ~0ul) {
            mpLists[i].mpCurve = nullptr;
        } else {
            mpLists[i].mpCurve = reinterpret_cast<DirectionalCurve*>(reinterpret_cast<size_t>(mpLists[i].mpCurve) + reinterpret_cast<size_t>(mpRawData));
        }
    }
    for (u32 i = 0; i < mCurveNum; i++) {
        if (reinterpret_cast<size_t>(mpCurves[i].mpElementData) == ~0ul) {
            mpCurves[i].mpElementData = nullptr;
        } else {
            mpCurves[i].mpElementData = reinterpret_cast<Element*>(reinterpret_cast<size_t>(mpCurves[i].mpElementData) + reinterpret_cast<size_t>(mpRawData));
        }
    }
    return createIdToIndexTbl();
}

__attribute__((weak)) bool rSoundDirectionalSet::save(MtStream& out) {
    MtDataWriter w(out, 4096, 4096);
    NATIVE_FILE_HEADER header;
    header.Magic = NativeFileMagic;
    header.Version = NativeFileVersion;
    header.ListNum = mListNum;
    header.CurveNum = mCurveNum;
    w.write(&header, sizeof(header));
    for (u32 i = 0; i < mListNum; i++) {
        w.writeU32(mpLists[i].mID);
        w.writeU32(mpLists[i].mPadding);
        if (mpLists[i].mpCurve != nullptr) {
            w.writeLabel(mpLists[i].mpCurve);
        } else {
            w.writeSPtr(-1);
        }
    }
    for (u32 i = 0; i < mCurveNum; i++) {
        DirectionalCurve* pCurve = mpCurves + i;
        w.addLabel(pCurve);
        w.writeU32(pCurve->mElementNum);
        w.writeF32(pCurve->mZeroRadianValue);
        w.writeF32(pCurve->mPiRadianValue);
        w.writeU32(pCurve->mPadding);
        if (pCurve->mpElementData != nullptr) {
            w.writeLabel(pCurve->mpElementData);
        } else {
            w.writeSPtr(-1);
        }
    }
    for (u32 i = 0; i < mCurveNum; i++) {
        DirectionalCurve* pCurve = mpCurves + i;
        if (pCurve->mpElementData != nullptr) {
            w.addLabel(pCurve->mpElementData);
            w.write(pCurve->mpElementData, pCurve->mElementNum * sizeof(Element));
        }
    }
    return true;
}

MT_CTSTR rSoundDirectionalSet::getExt() const {
    return "sdsr";
}

__attribute__((weak)) f32 rSoundDirectionalSet::getIntensity(u32 id, f32 ang) const {
    DDON_STUB("rSoundDirectionalSet::getIntensity")
    return {};
}

__attribute__((weak)) bool rSoundDirectionalSet::createIdToIndexTbl() {
    u32 maxIdNo = 0;
    for (u32 i = 0; i < mListNum; i++) {
        if (mpLists[i].mID > maxIdNo) {
            maxIdNo = mpLists[i].mID;
        }
    }
    mIdToIndexTblNum = maxIdNo + 1;
    void* pTbl = mpIdToIndexTbl;
    MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memFree(pTbl);
    size_t size = mIdToIndexTblNum * sizeof(u16);
    mpIdToIndexTbl = static_cast<u16*>(MtMemoryAllocator::getAllocator(rSoundDirectionalSet::DTI)->memAlloc(size, 16, rSoundDirectionalSet::DTI.getID()));
    if (mpIdToIndexTbl == nullptr) {
        return false;
    }
    memset(mpIdToIndexTbl, 0xFF, mIdToIndexTblNum * sizeof(u16));
    for (u32 i = 0; i < mListNum; i++) {
        if (mpLists[i].mID != 0xFFFF) {
            mpIdToIndexTbl[mpLists[i].mID] = i;
        }
    }
    return true;
}

inline rSoundDirectionalSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundDirectionalSet::MyDTI rSoundDirectionalSet::DTI("rSoundDirectionalSet", &::cResource::DTI, 160ul, 0u, 0u);

MtObject* rSoundDirectionalSet::MyDTI::newInstance() const {
    return new (16u) rSoundDirectionalSet;
}

