// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkContentInvite.h"
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

void nCaplink::ContentInviteAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ContentInviteReqCtx::getDTI() const {
    return nCaplink::ContentInviteReqCtx::DTI;
}

void* nCaplink::ContentInviteReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContentInviteReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ContentInviteReqCtx::DTI.mID);
}

nCaplink::ContentInviteReqCtx::ContentInviteReqCtx(MT_CTSTR unique_id, MT_CTSTR content_id, MT_CTSTR message) {
    DDON_STUB("nCaplink::ContentInviteReqCtx::ContentInviteReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteReqCtx::update() {
    DDON_STUB("nCaplink::ContentInviteReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteReqCtx::request() {
    DDON_STUB("nCaplink::ContentInviteReqCtx::request")
    /* stub */
}

inline nCaplink::ContentInviteReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ContentInviteReqCtx::MyDTI nCaplink::ContentInviteReqCtx::DTI("ContentInviteReqCtx", &::nCaplink::HttpRequestContext::DTI, 128ul, 0u, 0u);

MtObject* nCaplink::ContentInviteReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ContentInviteReqCtx;
}

void nCaplink::ContentInviteReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ContentInviteReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ContentInviteReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ContentInviteReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ContentInviteReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ContentInviteReqCtx::JsonParser::number(f64 value) {
}

