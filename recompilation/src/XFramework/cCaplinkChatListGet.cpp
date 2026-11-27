// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkChatListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void nCaplink::ChatListGetAns::init() {
    DDON_STUB("nCaplink::ChatListGetAns::init")
    /* stub */
}

const MtDTI& nCaplink::ChatListGetReqCtx::getDTI() const {
    return nCaplink::ChatListGetReqCtx::DTI;
}

void* nCaplink::ChatListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatListGetReqCtx::DTI.mID);
}

nCaplink::ChatListGetReqCtx::ChatListGetReqCtx(s32 id_type, MT_CTSTR id, s32 offset_id, s32 count) {
    DDON_STUB("nCaplink::ChatListGetReqCtx::ChatListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatListGetReqCtx::update() {
    DDON_STUB("nCaplink::ChatListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatListGetReqCtx::request() {
    DDON_STUB("nCaplink::ChatListGetReqCtx::request")
    /* stub */
}

inline nCaplink::ChatListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatListGetReqCtx::MyDTI nCaplink::ChatListGetReqCtx::DTI("ChatListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 200ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ChatListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ChatListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ChatListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ChatListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ChatListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::ChatListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::ChatListGetReqCtx::JsonParser::endObject")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatListGetReqCtx::JsonParser::fieldName")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatListGetReqCtx::JsonParser::number(s64 value) {
    if (mbStatus) {
        mpParent->mStatus = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbMemberTotal) {
            mpParent->mMemberTotal = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbMemberLimmit) {
                mpParent->mMemberLimmit = static_cast<s32>(static_cast<unsigned int>(value));
            } else {
                if (mbLastChatId) {
                    mpParent->mLastChatId = static_cast<s32>(static_cast<unsigned int>(value));
                } else {
                    if (mbChatId) {
                        mChatId = static_cast<s32>(static_cast<unsigned int>(value));
                    } else {
                        if (mbChatType) {
                            mChatType = static_cast<s32>(static_cast<unsigned int>(value));
                        } else {
                            if (mbStampId) {
                                mStampId = static_cast<s32>(static_cast<unsigned int>(value));
                            } else {
                                if (mbPlatformId) {
                                    mPlatformId = static_cast<s32>(static_cast<unsigned int>(value));
                                } else {
                                    if (mbCode) {
                                        mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::ChatListGetReqCtx::JsonParser::number(f64 value) {
}

