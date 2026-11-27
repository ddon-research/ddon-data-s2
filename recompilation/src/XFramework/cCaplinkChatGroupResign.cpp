// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatGroupResign.h"
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

void nCaplink::ChatGroupResignAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ChatGroupResignReqCtx::getDTI() const {
    return nCaplink::ChatGroupResignReqCtx::DTI;
}

void* nCaplink::ChatGroupResignReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupResignReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupResignReqCtx::DTI.mID);
}

nCaplink::ChatGroupResignReqCtx::ChatGroupResignReqCtx(MT_CTSTR group_id) {
    DDON_STUB("nCaplink::ChatGroupResignReqCtx::ChatGroupResignReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupResignReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupResignReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupResignReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupResignReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupResignReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupResignReqCtx::MyDTI nCaplink::ChatGroupResignReqCtx::DTI("ChatGroupResignReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::ChatGroupResignReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ChatGroupResignReqCtx;
}

void nCaplink::ChatGroupResignReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ChatGroupResignReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupResignReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupResignReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupResignReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ChatGroupResignReqCtx::JsonParser::number(f64 value) {
}

