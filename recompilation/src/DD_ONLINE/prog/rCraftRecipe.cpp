// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCraftRecipe.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rCraftRecipe::getDTI() const {
    return rCraftRecipe::DTI;
}

rCraftRecipe::~rCraftRecipe() {
}

inline rCraftRecipe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCraftRecipe::MyDTI rCraftRecipe::DTI("rCraftRecipe", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rCraftRecipe::MyDTI::newInstance() const {
    return new (16u) rCraftRecipe;
}

const MtDTI& rCraftRecipe::cCraftRecipe::getDTI() const {
    return rCraftRecipe::cCraftRecipe::DTI;
}

void* rCraftRecipe::cCraftRecipe::operator new(size_t sz, u32 align) {
    return rCraftRecipe::cCraftRecipe::getAllocator()->memAlloc(sz, align, rCraftRecipe::cCraftRecipe::DTI.getID());
}

rCraftRecipe::cCraftRecipe::cCraftRecipe() {
    mRecipeId = 0;
    mItemId = 0;
    mCreateTime = 0;
    mCreateNum = 1;
    mpArrayData = nullptr;
    mIsBaggage = false;
    mRank = 0;
    mNpcAction = rCraftRecipe::NPC_ACTION_NONE;
    mGold = 0;
    mExp = 0;
    mMaterialDataList.mAutoDelete = true;
    mMaterialDataListNum = 0;
}

rCraftRecipe::cCraftRecipe::~cCraftRecipe() {
    releaseWork();
}

__attribute__((weak)) void rCraftRecipe::cCraftRecipe::releaseWork() {
    if (mMaterialDataList.mLength != 0) {
        u32 v0_0 = mMaterialDataList.mLength;
        for (unsigned int i0_3 = 0;;) {
            if (mMaterialDataList.mpArray[i0_3] != nullptr) {
                delete mMaterialDataList.mpArray[i0_3];
                if ((i0_3 + 1u) < mMaterialDataList.mLength) {
                    v0_0 = mMaterialDataList.mLength;
                    i0_3 += 1u;
                } else {
                    break;
                }
            } else {
                if ((i0_3 + 1u) < v0_0) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mMaterialDataList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMaterialDataList.mpArray));
    }
    mMaterialDataList.mpArray = nullptr;
    mMaterialDataList.mBufsiz = 0;
    mMaterialDataList.mLength = 0;
    if (mpArrayData != nullptr) {
        if (mMaterialDataListNum != 0) {
            cMaterialData* v2_0 = mpArrayData;
            for (unsigned int i2_3 = 0;;) {
                v2_0[i2_3].~cMaterialData();
                if ((i2_3 + 1u) >= mMaterialDataListNum) {
                    break;
                } else {
                    v2_0 = mpArrayData;
                    i2_3 += 1u;
                }
            }
        }
        MtMemoryAllocator::getAllocator(rCraftRecipe::cCraftRecipe::DTI)->memFree(static_cast<void*>(mpArrayData));
    }
    mpArrayData = nullptr;
    mMaterialDataListNum = 0;
}

rCraftRecipe::cMaterialData* rCraftRecipe::cCraftRecipe::getMaterialData(u32 index) {
    if (index < mMaterialDataList.mLength) {
        return static_cast<cMaterialData*>(mMaterialDataList.mpArray[index]);
    } else {
        return nullptr;
    }
}

inline rCraftRecipe::cCraftRecipe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCraftRecipe::cCraftRecipe::MyDTI rCraftRecipe::cCraftRecipe::DTI("rCraftRecipe::cCraftRecipe", &::MtObject::DTI, 96ul, 0u, 0u);

MtObject* rCraftRecipe::cCraftRecipe::MyDTI::newInstance() const {
    return new (16u) rCraftRecipe::cCraftRecipe;
}

const MtDTI& rCraftRecipe::cMaterialData::getDTI() const {
    return rCraftRecipe::cMaterialData::DTI;
}

void* rCraftRecipe::cMaterialData::operator new(size_t sz, u32 align) {
    return rCraftRecipe::cMaterialData::getAllocator()->memAlloc(sz, align, rCraftRecipe::cMaterialData::DTI.getID());
}

rCraftRecipe::cMaterialData::cMaterialData() {
    mItemId = 0;
    mNum = 1;
    mIsSp = false;
}

inline rCraftRecipe::cMaterialData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCraftRecipe::cMaterialData::MyDTI rCraftRecipe::cMaterialData::DTI("rCraftRecipe::cMaterialData", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rCraftRecipe::cMaterialData::MyDTI::newInstance() const {
    return new (16u) rCraftRecipe::cMaterialData;
}

template MtTypedArray<rCraftRecipe::cMaterialData>::~MtTypedArray();

