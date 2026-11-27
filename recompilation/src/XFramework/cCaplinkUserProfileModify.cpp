// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkUserProfileModify.h"
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

void nCaplink::UserProfileModifyAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::UserProfileModifyReqCtx::getDTI() const {
    return nCaplink::UserProfileModifyReqCtx::DTI;
}

void* nCaplink::UserProfileModifyReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::UserProfileModifyReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::UserProfileModifyReqCtx::DTI.mID);
}

nCaplink::UserProfileModifyReqCtx::UserProfileModifyReqCtx(MT_CTSTR nickname, s32 icon_id, MT_CTSTR comment, s32 timeline_skin_id, s32 profile_skin_id, s8 timeline_privacy, s8 profile_privacy, s8 captalk_privacy, s8 find_search) {
    DDON_STUB("nCaplink::UserProfileModifyReqCtx::UserProfileModifyReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileModifyReqCtx::update() {
    DDON_STUB("nCaplink::UserProfileModifyReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileModifyReqCtx::request() {
    DDON_STUB("nCaplink::UserProfileModifyReqCtx::request")
    /* stub */
}

inline nCaplink::UserProfileModifyReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::UserProfileModifyReqCtx::MyDTI nCaplink::UserProfileModifyReqCtx::DTI("UserProfileModifyReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

MtObject* nCaplink::UserProfileModifyReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::UserProfileModifyReqCtx;
}

void nCaplink::UserProfileModifyReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::UserProfileModifyReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::UserProfileModifyReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileModifyReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::UserProfileModifyReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::UserProfileModifyReqCtx::JsonParser::number(f64 value) {
}

