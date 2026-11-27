// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendEntrySend.h"
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

void nCaplink::FriendEntrySendAns::init() {
    mTotal = 0;
    mLimmit = 0;
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::FriendEntrySendReqCtx::getDTI() const {
    return nCaplink::FriendEntrySendReqCtx::DTI;
}

void* nCaplink::FriendEntrySendReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendEntrySendReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendEntrySendReqCtx::DTI.mID);
}

nCaplink::FriendEntrySendReqCtx::FriendEntrySendReqCtx(MT_CTSTR uniqueId, MT_CTSTR message, s32 cause) {
    DDON_STUB("nCaplink::FriendEntrySendReqCtx::FriendEntrySendReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntrySendReqCtx::update() {
    DDON_STUB("nCaplink::FriendEntrySendReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntrySendReqCtx::request() {
    DDON_STUB("nCaplink::FriendEntrySendReqCtx::request")
    /* stub */
}

inline nCaplink::FriendEntrySendReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendEntrySendReqCtx::MyDTI nCaplink::FriendEntrySendReqCtx::DTI("FriendEntrySendReqCtx", &::nCaplink::HttpRequestContext::DTI, 136ul, 0u, 0u);

MtObject* nCaplink::FriendEntrySendReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::FriendEntrySendReqCtx;
}

void nCaplink::FriendEntrySendReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") == 0) {
        mbTotal = true;
        mbLimmit = false;
        mbCode = false;
        mbDetailMessage = false;
    }
    if (::strcmp(chars, "limit") == 0) {
        mbTotal = false;
        mbLimmit = true;
        mbCode = false;
        mbDetailMessage = false;
    }
    if (::strcmp(chars, "code") != 0) {
        int t0 = ::strcmp(chars, "detail_message");
        mbTotal = false;
        mbLimmit = false;
        mbCode = false;
        if (t0 != 0) {
            mbDetailMessage = false;
        } else {
            mbDetailMessage = true;
        }
    } else {
        mbTotal = false;
        mbLimmit = false;
        mbCode = true;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::FriendEntrySendReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendEntrySendReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntrySendReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendEntrySendReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbLimmit) {
            mpParent->mLimmit = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbCode) {
                mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
            }
        }
    }
}

__attribute__((weak)) void nCaplink::FriendEntrySendReqCtx::JsonParser::number(f64 value) {
}

