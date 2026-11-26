// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rDynamicSbc.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rDynamicSbc::getDTI() const {
    return rDynamicSbc::DTI;
}

inline void* rDynamicSbc::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rDynamicSbc::DTI)->memAlloc(sz, align, rDynamicSbc::DTI.mID);
}

inline void rDynamicSbc::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rDynamicSbc::DTI)->memFree(p_addr);
}

inline rDynamicSbc::rDynamicSbc() {
    mAttr = 18;
    mpMaterialInfo = nullptr;
    mpPartsList = nullptr;
    mPartsNum = 0;
    mJointNum = 0;
    mpJointInfo = nullptr;
    mVertexNum = 0;
    mTriangleNum = 0;
    mpVertexWeight = nullptr;
    mpVertexPos = nullptr;
    mpVertexJointInfo = nullptr;
    mpTriList = nullptr;
    memset(static_cast<void*>(&mJointTable[0]), 255, 256ul);
}

rDynamicSbc::~rDynamicSbc() {
    this->rDynamicSbc::clear();
}

MT_CTSTR rDynamicSbc::getExt() const {
    return "dsc";
}

__attribute__((weak)) bool rDynamicSbc::load(MtStream& in) {
    DDON_STUB("rDynamicSbc::load")
    return {};
}

bool rDynamicSbc::save(MtStream& out) {
    MtDataWriter fout(out, 4096u, 4096u);
    fout.MtDataWriter::writeU32(0x63627364u);
    fout.MtDataWriter::writeU32(0x77CF9370u);
    fout.MtDataWriter::writeU32(mVertexNum);
    fout.MtDataWriter::writeU32(mTriangleNum);
    fout.MtDataWriter::writeU32(mJointNum);
    fout.MtDataWriter::writeU32(mMaterialNum);
    fout.MtDataWriter::writeU32(mPartsNum);
    fout.MtDataWriter::write(static_cast<const void*>(mpVertexJointInfo), mVertexNum * 4u);
    fout.MtDataWriter::write(static_cast<const void*>(mpVertexPos), mVertexNum * 16u);
    fout.MtDataWriter::write(static_cast<const void*>(mpVertexWeight), mVertexNum * 16u);
    fout.MtDataWriter::write(static_cast<const void*>(mpTriList), mTriangleNum * 8u);
    fout.MtDataWriter::write(static_cast<const void*>(mpJointInfo), mJointNum * 80u);
    fout.MtDataWriter::write(static_cast<const void*>(mpMaterialInfo), mMaterialNum * 32u);
    fout.MtDataWriter::write(static_cast<const void*>(&mJointTable[0]), 256u);
    u32 i = 0;
    if (mPartsNum != 0) {
        do {
            fout.MtDataWriter::write(static_cast<const void*>(&mpPartsList[i]), 4u);
            fout.MtDataWriter::write(static_cast<const void*>(&mpPartsList[i].TriangleNum), 4u);
            fout.MtDataWriter::write(static_cast<const void*>(mpPartsList[i].pTriangleIndex), mpPartsList[i].TriangleNum * 4u);
            i += 1u;
        } while (i < mPartsNum);
    }
    return true;
}

__attribute__((weak)) void rDynamicSbc::clear() {
    mVertexNum = 0;
    mTriangleNum = 0;
    mJointNum = 0;
    mMaterialNum = 0;
    if (mpVertexJointInfo != nullptr) {
        MtMemory::mpAllocatorType[12]->memFree(static_cast<void*>(mpVertexJointInfo));
        mpVertexJointInfo = nullptr;
    }
    if (mpTriList != nullptr) {
        MtMemory::mpAllocatorType[12]->memFree(static_cast<void*>(mpTriList));
        mpTriList = nullptr;
    }
    MtVector4* t0 = mpVertexPos;
    if (t0 != nullptr) {
        MtMemoryAllocator::getAllocator(rDynamicSbc::DTI)->memFree(static_cast<void*>(t0));
        mpVertexPos = nullptr;
    }
    MtVector4* t1 = mpVertexWeight;
    if (t1 != nullptr) {
        MtMemoryAllocator::getAllocator(rDynamicSbc::DTI)->memFree(static_cast<void*>(t1));
        mpVertexWeight = nullptr;
    }
    if (mpJointInfo != nullptr) {
        MtMemory::mpAllocatorType[12]->memFree(static_cast<void*>(mpJointInfo));
        mpJointInfo = nullptr;
    }
    if (mpMaterialInfo != nullptr) {
        MtMemory::mpAllocatorType[4]->memFree(static_cast<void*>(mpMaterialInfo));
        mpMaterialInfo = nullptr;
    }
    PartsInfo* v8_4;
    if (mPartsNum == 0) {
        v8_4 = mpPartsList;
    } else {
        u32 v6_0 = mPartsNum;
        unsigned int i6_3 = 0;
        PartsInfo* v6_4 = mpPartsList;
        u32 v7_0;
        PartsInfo* v7_3;
        for (;;) {
            u32* t2 = v6_4[i6_3].pTriangleIndex;
            if (t2 == nullptr) {
                v7_0 = v6_0;
                v7_3 = v6_4;
            } else {
                MtMemoryAllocator::getAllocator(rDynamicSbc::DTI)->memFree(static_cast<void*>(t2));
                PartsInfo* t3 = mpPartsList;
                t3[i6_3].pTriangleIndex = nullptr;
                v7_0 = mPartsNum;
                v7_3 = t3;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
                v6_4 = v7_3;
            } else {
                v8_4 = v7_3;
                break;
            }
        }
    }
    mPartsNum = 0;
    if (v8_4 != nullptr) {
        MtMemory::mpAllocatorType[12]->memFree(static_cast<void*>(v8_4));
        mpPartsList = nullptr;
    }
}

inline rDynamicSbc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rDynamicSbc::MyDTI rDynamicSbc::DTI("rDynamicSbc", &::cResource::DTI, 456ul, 0u, 0u);

MtObject* rDynamicSbc::MyDTI::newInstance() const {
    return new (16u) rDynamicSbc;
}

