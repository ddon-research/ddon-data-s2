// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatGroupMemberReject.h"
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

void nCaplink::ChatGroupMemberRejectAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ChatGroupMemberRejectReqCtx::getDTI() const {
    return nCaplink::ChatGroupMemberRejectReqCtx::DTI;
}

void* nCaplink::ChatGroupMemberRejectReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupMemberRejectReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupMemberRejectReqCtx::DTI.mID);
}

nCaplink::ChatGroupMemberRejectReqCtx::ChatGroupMemberRejectReqCtx(MT_CTSTR group_id, MT_CTSTR unique_id) {
    DDON_STUB("nCaplink::ChatGroupMemberRejectReqCtx::ChatGroupMemberRejectReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberRejectReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupMemberRejectReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberRejectReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupMemberRejectReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupMemberRejectReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupMemberRejectReqCtx::MyDTI nCaplink::ChatGroupMemberRejectReqCtx::DTI("ChatGroupMemberRejectReqCtx", &::nCaplink::HttpRequestContext::DTI, 120ul, 0u, 0u);

MtObject* nCaplink::ChatGroupMemberRejectReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ChatGroupMemberRejectReqCtx;
}

void nCaplink::ChatGroupMemberRejectReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ChatGroupMemberRejectReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupMemberRejectReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberRejectReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupMemberRejectReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ChatGroupMemberRejectReqCtx::JsonParser::number(f64 value) {
}

