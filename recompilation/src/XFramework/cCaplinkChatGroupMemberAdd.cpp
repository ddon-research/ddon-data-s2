// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatGroupMemberAdd.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::ChatGroupMemberAddAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::ChatGroupMemberAddReqCtx::getDTI() const {
    return nCaplink::ChatGroupMemberAddReqCtx::DTI;
}

void* nCaplink::ChatGroupMemberAddReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupMemberAddReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupMemberAddReqCtx::DTI.mID);
}

nCaplink::ChatGroupMemberAddReqCtx::ChatGroupMemberAddReqCtx(MT_CTSTR group_id, MtArray* user_info_list) {
    DDON_STUB("nCaplink::ChatGroupMemberAddReqCtx::ChatGroupMemberAddReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberAddReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupMemberAddReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberAddReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupMemberAddReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupMemberAddReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupMemberAddReqCtx::MyDTI nCaplink::ChatGroupMemberAddReqCtx::DTI("ChatGroupMemberAddReqCtx", &::nCaplink::HttpRequestContext::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ChatGroupMemberAddReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ChatGroupMemberAddReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ChatGroupMemberAddReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::ChatGroupMemberAddReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupMemberAddReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberAddReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupMemberAddReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::ChatGroupMemberAddReqCtx::JsonParser::number(f64 value) {
}

