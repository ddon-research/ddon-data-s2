// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentInviteRemove.h"
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

void nCaplink::ContentInviteRemoveAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ContentInviteRemoveReqCtx::getDTI() const {
    return nCaplink::ContentInviteRemoveReqCtx::DTI;
}

void* nCaplink::ContentInviteRemoveReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentInviteRemoveReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentInviteRemoveReqCtx::DTI.mID);
}

nCaplink::ContentInviteRemoveReqCtx::ContentInviteRemoveReqCtx(MT_CTSTR unique_id, MT_CTSTR content_id) {
    DDON_STUB("nCaplink::ContentInviteRemoveReqCtx::ContentInviteRemoveReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteRemoveReqCtx::update() {
    DDON_STUB("nCaplink::ContentInviteRemoveReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteRemoveReqCtx::request() {
    DDON_STUB("nCaplink::ContentInviteRemoveReqCtx::request")
    /* stub */
}

inline nCaplink::ContentInviteRemoveReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentInviteRemoveReqCtx::MyDTI nCaplink::ContentInviteRemoveReqCtx::DTI("ContentInviteRemoveReqCtx", &::nCaplink::HttpRequestContext::DTI, 120ul, 0u, 0u);

MtObject* nCaplink::ContentInviteRemoveReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ContentInviteRemoveReqCtx;
}

void nCaplink::ContentInviteRemoveReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ContentInviteRemoveReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentInviteRemoveReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteRemoveReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentInviteRemoveReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ContentInviteRemoveReqCtx::JsonParser::number(f64 value) {
}

