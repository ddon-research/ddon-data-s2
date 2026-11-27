// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendEntryCancel.h"
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

void nCaplink::FriendEntryCancelAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::FriendEntryCancelReqCtx::getDTI() const {
    return nCaplink::FriendEntryCancelReqCtx::DTI;
}

void* nCaplink::FriendEntryCancelReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendEntryCancelReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendEntryCancelReqCtx::DTI.mID);
}

nCaplink::FriendEntryCancelReqCtx::FriendEntryCancelReqCtx(MT_CTSTR uniqueId) {
    DDON_STUB("nCaplink::FriendEntryCancelReqCtx::FriendEntryCancelReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntryCancelReqCtx::update() {
    DDON_STUB("nCaplink::FriendEntryCancelReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntryCancelReqCtx::request() {
    DDON_STUB("nCaplink::FriendEntryCancelReqCtx::request")
    /* stub */
}

inline nCaplink::FriendEntryCancelReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendEntryCancelReqCtx::MyDTI nCaplink::FriendEntryCancelReqCtx::DTI("FriendEntryCancelReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::FriendEntryCancelReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::FriendEntryCancelReqCtx;
}

void nCaplink::FriendEntryCancelReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "code") != 0) {
        int t0 = ::strcmp(chars, "detail_message");
        mbCode = false;
        if (t0 != 0) {
            mbDetailMessage = false;
        } else {
            mbDetailMessage = true;
        }
    } else {
        mbCode = true;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::FriendEntryCancelReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendEntryCancelReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendEntryCancelReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendEntryCancelReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::FriendEntryCancelReqCtx::JsonParser::number(f64 value) {
}

