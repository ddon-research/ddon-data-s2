// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundBank.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtRandom.h"
#include "cResource.h"
#include "sResource.h"

#include "rSoundSource.h"
#include "sSound.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* rSoundBank::memAlloc(u32 size, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundBank::DTI)->memAlloc(size, align, rSoundBank::DTI.mID);
}

__attribute__((weak)) void rSoundBank::usage() {
}

const MtDTI& rSoundBank::getDTI() const {
    return rSoundBank::DTI;
}

rSoundBank::~rSoundBank() {
    freeAll();
}

MT_CTSTR rSoundBank::getExt() const {
    return "sbkr";
}

__attribute__((weak)) bool rSoundBank::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    char path[64];
    Header header;
    r.read(&header, sizeof(header));
    if (header.mMagic != 0x524B4253) {
        return false;
    }
    if (header.mVersion != mVersion) {
        return false;
    }
    freeAll();
    mProgramNum = header.mProgramNum;
    mElementNum = header.mElementNum;
    mBusNum = header.mBusNum;
    u32 pos = 0;
    u8* pBuffer = static_cast<u8*>(memAlloc(static_cast<u32>(mProgramNum * sizeof(Program) + mElementNum * sizeof(Element) + mBusNum * sizeof(Bus)), 16u));
    mpProgramArray = reinterpret_cast<Program*>(pBuffer + pos);
    pos += static_cast<u32>(mProgramNum * sizeof(Program));
    mpElementArray = reinterpret_cast<Element*>(pBuffer + pos);
    pos += static_cast<u32>(mElementNum * sizeof(Element));
    mpBusArray = reinterpret_cast<Bus*>(pBuffer + pos);
    for (u32 i = 0; i < mProgramNum; i++) {
        r.read(&mpProgramArray[i], sizeof(Program));
        mpProgramArray[i].mpElements = &mpElementArray[reinterpret_cast<size_t>(mpProgramArray[i].mpElements)];
    }
    for (u32 i = 0; i < mElementNum; i++) {
        r.readString(path, sizeof(path));
        r.read(&mpElementArray[i].mDTIID, sizeof(Element) - offsetof(Element, mDTIID));
        if (path[0] != 0) {
            mpElementArray[i].mpSource = static_cast<rSoundSource*>(sResource::getInstance()->create(*MtDTI::from(mpElementArray[i].mDTIID), path, 1u));
        } else {
            mpElementArray[i].mpSource = nullptr;
        }
    }
    if (mBusNum != 0) {
        r.read(mpBusArray, static_cast<u32>(mBusNum * sizeof(Bus)));
    }
    return true;
}

__attribute__((weak)) bool rSoundBank::loadEnd() {
    for (u32 i = 0; i < mElementNum; i++) {
        if (mpElementArray[i].mpSource != nullptr) {
            if (mpElementArray[i].mpSource->isUsage()) {
                bool result = mpElementArray[i].mpSource->prepareToBuffer();
                if (!result) {
                    freeAll();
                    return false;
                }
            } else {
                mpElementArray[i].mpSource->release();
                mpElementArray[i].mpSource = nullptr;
            }
        }
    }
    return true;
}

__attribute__((weak)) bool rSoundBank::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    Header header;
    header.mMagic = 0x524B4253;
    header.mVersion = mVersion;
    header.mProgramNum = mProgramNum;
    header.mElementNum = mElementNum;
    header.mBusNum = mBusNum;
    w.write(&header, sizeof(header));
    for (u32 i = 0; i < mProgramNum; i++) {
        Program p = mpProgramArray[i];
        p.mpElements = reinterpret_cast<Element*>(mpProgramArray[i].mpElements - mpElementArray);
        w.write(&p, sizeof(p));
    }
    for (u32 i = 0; i < mElementNum; i++) {
        if (mpElementArray[i].mpSource != nullptr) {
            w.writeString(mpElementArray[i].mpSource->getPath());
            if (mpElementArray[i].mpSource->isIntermediate()) {
                const MtDTI* pSuper = mpElementArray[i].mpSource->getDTI().mpParent;
                mpElementArray[i].mDTIID = pSuper != nullptr ? pSuper->mID : 0;
            } else {
                mpElementArray[i].mDTIID = mpElementArray[i].mpSource->getDTI().mID;
            }
            w.writeU32(mpElementArray[i].mDTIID);
        } else {
            mpElementArray[i].mDTIID = 0;
            w.writeU32(mpElementArray[i].mDTIID);
            w.writeU8(0);
        }
        w.write(&mpElementArray[i].mOscillator, sizeof(Element) - offsetof(Element, mOscillator));
    }
    if (mBusNum != 0) {
        w.write(mpBusArray, static_cast<u32>(mBusNum * sizeof(Bus)));
    }
    return true;
}

const rSoundBank::Program* rSoundBank::findProgram(u32 no) const {
    if (mProgramNum != 0) {
        u32 i = 0;
        Program* p2 = mpProgramArray;
        do {
            if (p2->mProgramNumber == no) {
                return p2;
            }
            i += 1u;
            p2 += static_cast<int>(1);
        } while (i < mProgramNum);
    }
    return nullptr;
}

const rSoundBank::Element* rSoundBank::getElement(u32 index) const {
    return &mpElementArray[index];
}

const rSoundBank::Bus* rSoundBank::getBus(u32 no) const {
    if (mBusNum != 0) {
        u32 i = 0;
        do {
            if (mpBusArray[i].mBusNo == no) {
                return &mpBusArray[i];
            }
            i += 1u;
        } while (i < mBusNum);
    }
    return nullptr;
}

__attribute__((weak)) u32 rSoundBank::getElementIndex(const rSoundBank::Element* pElement) const {
    DDON_STUB("rSoundBank::getElementIndex")
    return {};
}

__attribute__((weak)) u32 rSoundBank::enumAdaptedElement(bool(*pfunc)(const rSoundBank::Element*, void*, const u32), void* pArg, u32 prg_num, u32 key, u32 vel) const {
    DDON_STUB("rSoundBank::enumAdaptedElement")
    return {};
}

__attribute__((weak)) void rSoundBank::freeAll() {
    if (mpElementArray != nullptr) {
        for (u32 i = 0; i < mElementNum; i++) {
            if (mpElementArray[i].mpSource != nullptr) {
                mpElementArray[i].mpSource->release();
                mpElementArray[i].mpSource = nullptr;
            }
        }
    }
    const void* pNativeCheck0 = &mpProgramArray[mProgramNum];
    const void* pNativeCheck1 = mpElementArray;
    MtMemoryAllocator::getAllocator(rSoundBank::DTI)->memFree(mpProgramArray);
    if (pNativeCheck0 != pNativeCheck1) {
        MtMemoryAllocator::getAllocator(rSoundBank::DTI)->memFree(mpElementArray);
        MtMemoryAllocator::getAllocator(rSoundBank::DTI)->memFree(mpBusArray);
    }
    mProgramNum = 0;
    mpProgramArray = nullptr;
    mElementNum = 0;
    mpElementArray = nullptr;
    mBusNum = 0;
    mpBusArray = nullptr;
}

inline rSoundBank::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundBank::MyDTI rSoundBank::DTI("rSoundBank", &::cResource::DTI, 160ul, 0u, 0u);

MtObject* rSoundBank::MyDTI::newInstance() const {
    return new (16u) rSoundBank;
}

