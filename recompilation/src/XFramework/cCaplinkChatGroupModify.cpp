// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatGroupModify.h"
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

void nCaplink::ChatGroupModifyAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ChatGroupModifyReqCtx::getDTI() const {
    return nCaplink::ChatGroupModifyReqCtx::DTI;
}

void* nCaplink::ChatGroupModifyReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupModifyReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupModifyReqCtx::DTI.mID);
}

nCaplink::ChatGroupModifyReqCtx::ChatGroupModifyReqCtx(MT_CTSTR group_id, MT_CTSTR group_name, s32 group_skin_id) {
    DDON_STUB("nCaplink::ChatGroupModifyReqCtx::ChatGroupModifyReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupModifyReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupModifyReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupModifyReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupModifyReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupModifyReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupModifyReqCtx::MyDTI nCaplink::ChatGroupModifyReqCtx::DTI("ChatGroupModifyReqCtx", &::nCaplink::HttpRequestContext::DTI, 128ul, 0u, 0u);

MtObject* nCaplink::ChatGroupModifyReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ChatGroupModifyReqCtx;
}

void nCaplink::ChatGroupModifyReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ChatGroupModifyReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupModifyReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupModifyReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupModifyReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ChatGroupModifyReqCtx::JsonParser::number(f64 value) {
}

