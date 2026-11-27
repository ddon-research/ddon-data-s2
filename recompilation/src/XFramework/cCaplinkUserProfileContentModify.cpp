// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkUserProfileContentModify.h"
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

void nCaplink::UserProfileContentModifyAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::UserProfileContentModifyReqCtx::getDTI() const {
    return nCaplink::UserProfileContentModifyReqCtx::DTI;
}

void* nCaplink::UserProfileContentModifyReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::UserProfileContentModifyReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::UserProfileContentModifyReqCtx::DTI.mID);
}

nCaplink::UserProfileContentModifyReqCtx::UserProfileContentModifyReqCtx(MT_CTSTR content_id, MT_CTSTR character_id, MT_CTSTR comment, s8 online_privacy, s8 visible) {
    DDON_STUB("nCaplink::UserProfileContentModifyReqCtx::UserProfileContentModifyReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileContentModifyReqCtx::update() {
    DDON_STUB("nCaplink::UserProfileContentModifyReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileContentModifyReqCtx::request() {
    DDON_STUB("nCaplink::UserProfileContentModifyReqCtx::request")
    /* stub */
}

inline nCaplink::UserProfileContentModifyReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::UserProfileContentModifyReqCtx::MyDTI nCaplink::UserProfileContentModifyReqCtx::DTI("UserProfileContentModifyReqCtx", &::nCaplink::HttpRequestContext::DTI, 136ul, 0u, 0u);

MtObject* nCaplink::UserProfileContentModifyReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::UserProfileContentModifyReqCtx;
}

void nCaplink::UserProfileContentModifyReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::UserProfileContentModifyReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::UserProfileContentModifyReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileContentModifyReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::UserProfileContentModifyReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::UserProfileContentModifyReqCtx::JsonParser::number(f64 value) {
}

