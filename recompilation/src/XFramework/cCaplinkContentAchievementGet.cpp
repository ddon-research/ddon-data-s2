// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentAchievementGet.h"
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

void nCaplink::ContentAchievementGetAns::init() {
    this->::nCaplink::ContextListener::init();
    ::memset(static_cast<void*>(&mAchievement[0]), 0, 2732ul);
    mExtended.mAutoDelete = true;
    if (mExtended.mLength != 0) {
        u32 v0_0 = mExtended.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mExtended.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mExtended.mpArray[i0_3];
                v1_0 = mExtended.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mExtended.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mExtended.mpArray));
    }
    mExtended.mpArray = nullptr;
    mExtended.mBufsiz = 0;
    mExtended.mLength = 0;
}

const MtDTI& nCaplink::ContentAchievementGetReqCtx::getDTI() const {
    return nCaplink::ContentAchievementGetReqCtx::DTI;
}

void* nCaplink::ContentAchievementGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentAchievementGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentAchievementGetReqCtx::DTI.mID);
}

nCaplink::ContentAchievementGetReqCtx::ContentAchievementGetReqCtx(MT_CTSTR content_id) {
    DDON_STUB("nCaplink::ContentAchievementGetReqCtx::ContentAchievementGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementGetReqCtx::update() {
    DDON_STUB("nCaplink::ContentAchievementGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementGetReqCtx::request() {
    DDON_STUB("nCaplink::ContentAchievementGetReqCtx::request")
    /* stub */
}

inline nCaplink::ContentAchievementGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentAchievementGetReqCtx::MyDTI nCaplink::ContentAchievementGetReqCtx::DTI("ContentAchievementGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::ContentAchievementGetReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ContentAchievementGetReqCtx;
}

nCaplink::ContentAchievementGetReqCtx::JsonParser::~JsonParser() {
    if (mpAddInfo == nullptr) {
        return;
    }
    delete mpAddInfo;
    mpAddInfo = nullptr;
}

void nCaplink::ContentAchievementGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ContentAchievementGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ContentAchievementGetReqCtx::JsonParser::beginObject() {
    DDON_STUB("nCaplink::ContentAchievementGetReqCtx::JsonParser::beginObject")
    /* stub */
}

void nCaplink::ContentAchievementGetReqCtx::JsonParser::endObject() {
    nCaplink::cAchievementExtendedInfo* t0 = mpAddInfo;
    if (t0 == nullptr) {
        return;
    }
    nCaplink::ContentAchievementGetAns* t1 = mpListener;
    u32 t2 = t1->mExtended.mLength;
    u32 t3 = t1->mExtended.mBufsiz;
    if (t2 < t3) {
        t1->mExtended.mLength = t2 + 1u;
        t1->mExtended.mpArray[t2] = static_cast<MtObject*>(t0);
        mpAddInfo = nullptr;
    } else {
        void* t4 = ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memAlloc(static_cast<size_t>(t3 + 32u) * 8, 16u);
        ::memset(t4, 0, static_cast<size_t>(t3 + 32u) * 8);
        ::memcpy(t4, static_cast<const void*>(t1->mExtended.mpArray), static_cast<size_t>(t1->mExtended.mLength) * 8);
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(t1->mExtended.mpArray));
        t1->mExtended.mpArray = static_cast<MtObject* *>(t4);
        t1->mExtended.mBufsiz = t3 + 32u;
        u32 t5 = t1->mExtended.mLength;
        t1->mExtended.mLength = t5 + 1u;
        t1->mExtended.mpArray[t5] = static_cast<MtObject*>(t0);
        mpAddInfo = nullptr;
    }
}

void nCaplink::ContentAchievementGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    mbCount = false;
    mbCode = false;
    mbDetailMessage = false;
    mbAchievement = false;
    mbId = false;
    if (::strcmp(chars, "code") != 0) {
        if (::strcmp(chars, "detail_message") != 0) {
            if (::strcmp(chars, "achievement") != 0) {
                if (::strcmp(chars, "achievement_id") != 0) {
                    if (::strcmp(chars, "achievement_count") == 0) {
                        mbCount = true;
                    }
                } else {
                    mbId = true;
                }
            } else {
                mbAchievement = true;
            }
        } else {
            mbDetailMessage = true;
        }
    } else {
        mbCode = true;
    }
}

__attribute__((weak)) void nCaplink::ContentAchievementGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentAchievementGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentAchievementGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentAchievementGetReqCtx::JsonParser::number(s64 value) {
    if (mbCode) {
        mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbId) {
            if (mpAddInfo != nullptr) {
                mpAddInfo->mId = static_cast<signed char>(value);
            }
        } else {
            if (mbCount) {
                if (mpAddInfo != nullptr) {
                    mpAddInfo->mCount = static_cast<signed char>(value);
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::ContentAchievementGetReqCtx::JsonParser::number(f64 value) {
}

