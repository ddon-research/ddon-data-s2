// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentAchievementRelationGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::ContentAchievementRelationGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mTotal = 0;
    mCount = 0;
    mAchievementList.mAutoDelete = true;
    if (mAchievementList.mLength != 0) {
        u32 v0_0 = mAchievementList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mAchievementList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mAchievementList.mpArray[i0_3];
                v1_0 = mAchievementList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAchievementList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mAchievementList.mpArray));
    }
    mAchievementList.mpArray = nullptr;
    mAchievementList.mBufsiz = 0;
    mAchievementList.mLength = 0;
}

const MtDTI& nCaplink::ContentAchievementRelationGetReqCtx::getDTI() const {
    return nCaplink::ContentAchievementRelationGetReqCtx::DTI;
}

void* nCaplink::ContentAchievementRelationGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentAchievementRelationGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentAchievementRelationGetReqCtx::DTI.mID);
}

nCaplink::ContentAchievementRelationGetReqCtx::ContentAchievementRelationGetReqCtx(MT_CTSTR filtering_content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count) {
    DDON_STUB("nCaplink::ContentAchievementRelationGetReqCtx::ContentAchievementRelationGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementRelationGetReqCtx::update() {
    DDON_STUB("nCaplink::ContentAchievementRelationGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementRelationGetReqCtx::request() {
    DDON_STUB("nCaplink::ContentAchievementRelationGetReqCtx::request")
    /* stub */
}

inline nCaplink::ContentAchievementRelationGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentAchievementRelationGetReqCtx::MyDTI nCaplink::ContentAchievementRelationGetReqCtx::DTI("ContentAchievementRelationGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 136ul, 0u, 0u);

MtObject* nCaplink::ContentAchievementRelationGetReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ContentAchievementRelationGetReqCtx;
}

nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::~JsonParser() {
    if (mpRelationInfo != nullptr) {
        delete mpRelationInfo;
        mpRelationInfo = nullptr;
    }
    if (mpRewardInfo == nullptr) {
        return;
    }
    delete mpRewardInfo;
    mpRewardInfo = nullptr;
}

void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::beginArray() {
    if (mbRelationArray) {
        mbRewardArray = true;
    } else {
        mbRelationArray = true;
    }
}

void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::endArray() {
    if (mbRewardArray) {
        mbRewardArray = false;
    } else {
        mbRelationArray = false;
    }
}

__attribute__((weak)) void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::beginObject() {
    DDON_STUB("nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::beginObject")
    /* stub */
}

void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::endObject() {
    nCaplink::cAchievementRelationInfo* t0 = mpRelationInfo;
    if (t0 == nullptr) {
        return;
    }
    nCaplink::cAchievementRewardInfo* t1 = mpRewardInfo;
    if (t1 != nullptr) {
        u32 t2 = t0->mRewardData.mLength;
        u32 t3 = t0->mRewardData.mBufsiz;
        if (t2 < t3) {
            t0->mRewardData.mLength = t2 + 1u;
            t0->mRewardData.mpArray[t2] = static_cast<MtObject*>(t1);
            mpRewardInfo = nullptr;
        } else {
            void* t7 = ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memAlloc(static_cast<size_t>(t3 + 32u) * 8, 16u);
            ::memset(t7, 0, static_cast<size_t>(t3 + 32u) * 8);
            ::memcpy(t7, static_cast<const void*>(t0->mRewardData.mpArray), static_cast<size_t>(t0->mRewardData.mLength) * 8);
            ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(t0->mRewardData.mpArray));
            t0->mRewardData.mpArray = static_cast<MtObject* *>(t7);
            t0->mRewardData.mBufsiz = t3 + 32u;
            u32 t8 = t0->mRewardData.mLength;
            t0->mRewardData.mLength = t8 + 1u;
            t0->mRewardData.mpArray[t8] = static_cast<MtObject*>(t1);
            mpRewardInfo = nullptr;
        }
    } else {
        nCaplink::ContentAchievementRelationGetAns* t4 = mpListener;
        u32 t5 = t4->mAchievementList.mLength;
        u32 t6 = t4->mAchievementList.mBufsiz;
        if (t5 < t6) {
            t4->mAchievementList.mLength = t5 + 1u;
            t4->mAchievementList.mpArray[t5] = static_cast<MtObject*>(t0);
            mpRelationInfo = nullptr;
        } else {
            void* t9 = ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memAlloc(static_cast<size_t>(t6 + 32u) * 8, 16u);
            ::memset(t9, 0, static_cast<size_t>(t6 + 32u) * 8);
            ::memcpy(t9, static_cast<const void*>(t4->mAchievementList.mpArray), static_cast<size_t>(t4->mAchievementList.mLength) * 8);
            ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(t4->mAchievementList.mpArray));
            t4->mAchievementList.mpArray = static_cast<MtObject* *>(t9);
            t4->mAchievementList.mBufsiz = t6 + 32u;
            u32 t10 = t4->mAchievementList.mLength;
            t4->mAchievementList.mLength = t10 + 1u;
            t4->mAchievementList.mpArray[t10] = static_cast<MtObject*>(t0);
            mpRelationInfo = nullptr;
        }
    }
}

__attribute__((weak)) void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::fieldName")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::number(s64 value) {
    switch (mFieldName) {
        case 0:
        {
            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
            break;
        }
        case 2:
        {
            mpListener->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
            break;
        }
        case 3:
        {
            mpListener->mCount = static_cast<s32>(static_cast<unsigned int>(value));
            break;
        }
        case 6:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mAchievementId = static_cast<s32>(static_cast<unsigned int>(value));
            }
            break;
        }
        case 9:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mExtended = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 10:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mExtendedCount = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 11:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mCategory = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 12:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mAlive = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 13:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mDifficulty = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 15:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mIndefinite = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 20:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mRewardCount = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 21:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mBit = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 22:
        {
            if (mpRelationInfo != nullptr) {
                mpRelationInfo->mAchievementCount = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 25:
        {
            if (mpRewardInfo != nullptr) {
                mpRewardInfo->mAmount = static_cast<s32>(static_cast<unsigned int>(value));
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void nCaplink::ContentAchievementRelationGetReqCtx::JsonParser::number(f64 value) {
}

template MtTypedArray<nCaplink::cAchievementRewardInfo>::~MtTypedArray();

