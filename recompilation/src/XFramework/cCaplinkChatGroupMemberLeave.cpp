// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatGroupMemberLeave.h"
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

void nCaplink::ChatGroupMemberLeaveAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ChatGroupMemberLeaveReqCtx::getDTI() const {
    return nCaplink::ChatGroupMemberLeaveReqCtx::DTI;
}

void* nCaplink::ChatGroupMemberLeaveReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupMemberLeaveReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupMemberLeaveReqCtx::DTI.mID);
}

nCaplink::ChatGroupMemberLeaveReqCtx::ChatGroupMemberLeaveReqCtx(MT_CTSTR group_id) {
    DDON_STUB("nCaplink::ChatGroupMemberLeaveReqCtx::ChatGroupMemberLeaveReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberLeaveReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupMemberLeaveReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberLeaveReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupMemberLeaveReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupMemberLeaveReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupMemberLeaveReqCtx::MyDTI nCaplink::ChatGroupMemberLeaveReqCtx::DTI("ChatGroupMemberLeaveReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::ChatGroupMemberLeaveReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ChatGroupMemberLeaveReqCtx;
}

void nCaplink::ChatGroupMemberLeaveReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ChatGroupMemberLeaveReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupMemberLeaveReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberLeaveReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupMemberLeaveReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ChatGroupMemberLeaveReqCtx::JsonParser::number(f64 value) {
}

