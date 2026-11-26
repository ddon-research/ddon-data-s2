// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundCurveSet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rSoundCurveSet::getDTI() const {
    return rSoundCurveSet::DTI;
}

inline void* rSoundCurveSet::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundCurveSet::DTI)->memAlloc(sz, align, rSoundCurveSet::DTI.mID);
}

inline void rSoundCurveSet::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSoundCurveSet::DTI)->memFree(p_addr);
}

rSoundCurveSet::~rSoundCurveSet() {
    void* t0 = mpRawData;
    MtMemoryAllocator::getAllocator(rSoundCurveSet::DTI)->memFree(t0);
}

__attribute__((weak)) bool rSoundCurveSet::load(MtStream& in) {
    MtDataReader r(in, 4096);
    u32 size = r.getLength();
    void* pData = MtMemoryAllocator::getAllocator(rSoundCurveSet::DTI)->memAlloc(size, 16, rSoundCurveSet::DTI.getID());
    if (pData == nullptr) {
        return false;
    }
    if (r.read(pData, size) != size) {
        MtMemoryAllocator::getAllocator(rSoundCurveSet::DTI)->memFree(pData);
        return false;
    }
    NATIVE_FILE_HEADER* header = static_cast<NATIVE_FILE_HEADER*>(pData);
    if (header->Magic != NativeFileMagic || header->Version != NativeFileVersion) {
        MtMemoryAllocator::getAllocator(rSoundCurveSet::DTI)->memFree(pData);
        return false;
    }
    void* pRawData = mpRawData;
    MtMemoryAllocator::getAllocator(rSoundCurveSet::DTI)->memFree(pRawData);
    mpRawData = pData;
    mpLists = reinterpret_cast<List*>(header + 1);
    mpCurveRefs = reinterpret_cast<Curve**>(mpLists + header->ListNum);
    for (u32 i = 0; i < header->CurveNum; i++) {
        mpCurveRefs[i] = reinterpret_cast<Curve*>(reinterpret_cast<size_t>(mpCurveRefs[i]) + reinterpret_cast<size_t>(mpRawData));
    }
    mpCurves = reinterpret_cast<Curve*>(&mpCurveRefs[header->CurveNum]);
    mCurveNum = header->CurveNum;
    mListNum = header->ListNum;
    return true;
}

__attribute__((weak)) bool rSoundCurveSet::save(MtStream& out) {
    MtDataWriter w(out, 4096, 4096);
    NATIVE_FILE_HEADER header;
    header.Magic = NativeFileMagic;
    header.Version = NativeFileVersion;
    header.ListNum = mListNum;
    header.CurveNum = mCurveNum;
    w.write(&header, sizeof(header));
    w.write(mpLists, mListNum * sizeof(List));
    for (u32 i = 0; i < mCurveNum; i++) {
        w.writeLabel(mpCurveRefs[i]);
    }
    for (u32 i = 0; i < mCurveNum; i++) {
        Curve* pCurve = mpCurveRefs[i];
        w.addLabel(pCurve);
        w.write(pCurve, sizeof(Curve));
        f32* pData = reinterpret_cast<f32*>(pCurve + 1);
        for (u32 j = 0; j < pCurve->mElementNum; j++) {
            w.writeF32(*pData++);
            w.writeF32(*pData++);
        }
    }
    return true;
}

MT_CTSTR rSoundCurveSet::getExt() const {
    return "scsr";
}

__attribute__((weak)) f32 rSoundCurveSet::getVolume(u32 index, f32 dist) const {
    DDON_STUB("rSoundCurveSet::getVolume")
    return {};
}

__attribute__((weak)) f32 rSoundCurveSet::getEffectSend(u32 index, f32 dist) const {
    DDON_STUB("rSoundCurveSet::getEffectSend")
    return {};
}

__attribute__((weak)) f32 rSoundCurveSet::getLFE(u32 index, f32 dist) const {
    DDON_STUB("rSoundCurveSet::getLFE")
    return {};
}

inline rSoundCurveSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundCurveSet::MyDTI rSoundCurveSet::DTI("rSoundCurveSet", &::cResource::DTI, 160ul, 0u, 0u);

MtObject* rSoundCurveSet::MyDTI::newInstance() const {
    return new (16u) rSoundCurveSet;
}

