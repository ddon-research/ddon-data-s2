// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendAttribute.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::FriendAttributeAns::init() {
    mFriendTotal = 0;
    mFriendLimmit = 0;
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::FriendAttributeReqCtx::getDTI() const {
    return nCaplink::FriendAttributeReqCtx::DTI;
}

void* nCaplink::FriendAttributeReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendAttributeReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendAttributeReqCtx::DTI.mID);
}

nCaplink::FriendAttributeReqCtx::FriendAttributeReqCtx(MT_CTSTR uniqueId, s8 attribute) {
    DDON_STUB("nCaplink::FriendAttributeReqCtx::FriendAttributeReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendAttributeReqCtx::update() {
    DDON_STUB("nCaplink::FriendAttributeReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendAttributeReqCtx::request() {
    DDON_STUB("nCaplink::FriendAttributeReqCtx::request")
    /* stub */
}

inline nCaplink::FriendAttributeReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendAttributeReqCtx::MyDTI nCaplink::FriendAttributeReqCtx::DTI("FriendAttributeReqCtx", &::nCaplink::HttpRequestContext::DTI, 128ul, 0u, 0u);

MtObject* nCaplink::FriendAttributeReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::FriendAttributeReqCtx;
}

void nCaplink::FriendAttributeReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "friend_total") == 0) {
        mbFriendTotal = true;
        mbFriendLimmit = false;
        mbCode = false;
        mbDetailMessage = false;
    }
    if (::strcmp(chars, "friend_limit") == 0) {
        mbFriendTotal = false;
        mbFriendLimmit = true;
        mbCode = false;
        mbDetailMessage = false;
    }
    if (::strcmp(chars, "code") != 0) {
        int t0 = ::strcmp(chars, "detail_message");
        mbFriendTotal = false;
        mbFriendLimmit = false;
        mbCode = false;
        if (t0 != 0) {
            mbDetailMessage = false;
        } else {
            mbDetailMessage = true;
        }
    } else {
        mbFriendTotal = false;
        mbFriendLimmit = false;
        mbCode = true;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::FriendAttributeReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendAttributeReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendAttributeReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendAttributeReqCtx::JsonParser::number(s64 value) {
    if (mbFriendTotal) {
        mpParent->mFriendTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbFriendLimmit) {
            mpParent->mFriendLimmit = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbCode) {
                mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
            }
        }
    }
}

__attribute__((weak)) void nCaplink::FriendAttributeReqCtx::JsonParser::number(f64 value) {
}

