// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentAchievementListGet.h"
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

void nCaplink::ContentAchievementListGetAns::init() {
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

const MtDTI& nCaplink::ContentAchievementListGetReqCtx::getDTI() const {
    return nCaplink::ContentAchievementListGetReqCtx::DTI;
}

void* nCaplink::ContentAchievementListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentAchievementListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentAchievementListGetReqCtx::DTI.mID);
}

nCaplink::ContentAchievementListGetReqCtx::ContentAchievementListGetReqCtx(MT_CTSTR content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count) {
    DDON_STUB("nCaplink::ContentAchievementListGetReqCtx::ContentAchievementListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementListGetReqCtx::update() {
    DDON_STUB("nCaplink::ContentAchievementListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementListGetReqCtx::request() {
    DDON_STUB("nCaplink::ContentAchievementListGetReqCtx::request")
    /* stub */
}

inline nCaplink::ContentAchievementListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentAchievementListGetReqCtx::MyDTI nCaplink::ContentAchievementListGetReqCtx::DTI("ContentAchievementListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 136ul, 0u, 0u);

MtObject* nCaplink::ContentAchievementListGetReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ContentAchievementListGetReqCtx;
}

nCaplink::ContentAchievementListGetReqCtx::JsonParser::~JsonParser() {
    if (mpAddInfo == nullptr) {
        return;
    }
    delete mpAddInfo;
    mpAddInfo = nullptr;
}

void nCaplink::ContentAchievementListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ContentAchievementListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ContentAchievementListGetReqCtx::JsonParser::beginObject() {
    DDON_STUB("nCaplink::ContentAchievementListGetReqCtx::JsonParser::beginObject")
    /* stub */
}

void nCaplink::ContentAchievementListGetReqCtx::JsonParser::endObject() {
    nCaplink::cAchievementListInfo* t0 = mpAddInfo;
    if (t0 == nullptr) {
        return;
    }
    nCaplink::ContentAchievementListGetAns* t1 = mpListener;
    u32 t2 = t1->mAchievementList.mLength;
    u32 t3 = t1->mAchievementList.mBufsiz;
    if (t2 < t3) {
        t1->mAchievementList.mLength = t2 + 1u;
        t1->mAchievementList.mpArray[t2] = static_cast<MtObject*>(t0);
        mpAddInfo = nullptr;
    } else {
        void* t4 = ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memAlloc(static_cast<size_t>(t3 + 32u) * 8, 16u);
        ::memset(t4, 0, static_cast<size_t>(t3 + 32u) * 8);
        ::memcpy(t4, static_cast<const void*>(t1->mAchievementList.mpArray), static_cast<size_t>(t1->mAchievementList.mLength) * 8);
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(t1->mAchievementList.mpArray));
        t1->mAchievementList.mpArray = static_cast<MtObject* *>(t4);
        t1->mAchievementList.mBufsiz = t3 + 32u;
        u32 t5 = t1->mAchievementList.mLength;
        t1->mAchievementList.mLength = t5 + 1u;
        t1->mAchievementList.mpArray[t5] = static_cast<MtObject*>(t0);
        mpAddInfo = nullptr;
    }
}

__attribute__((weak)) void nCaplink::ContentAchievementListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentAchievementListGetReqCtx::JsonParser::fieldName")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentAchievementListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentAchievementListGetReqCtx::JsonParser::number(s64 value) {
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
        case 4:
        {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mId = static_cast<s32>(static_cast<unsigned int>(value));
            }
            break;
        }
        case 7:
        {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mExtended = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 8:
        {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mCategory = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 9:
        {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mAlive = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 10:
        {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mDifficulty = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 12:
        {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mIndefinite = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 15:
        {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mBit = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        case 16:
        {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mCount = static_cast<s8>(static_cast<unsigned char>(value));
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void nCaplink::ContentAchievementListGetReqCtx::JsonParser::number(f64 value) {
}

