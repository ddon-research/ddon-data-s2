// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatLastId.h"
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

void nCaplink::ChatLastIdAns::init() {
    this->::nCaplink::ContextListener::init();
    mLastChatId = 0;
}

const MtDTI& nCaplink::ChatLastIdReqCtx::getDTI() const {
    return nCaplink::ChatLastIdReqCtx::DTI;
}

void* nCaplink::ChatLastIdReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatLastIdReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatLastIdReqCtx::DTI.mID);
}

nCaplink::ChatLastIdReqCtx::ChatLastIdReqCtx(s8 id_type, MT_CTSTR id) {
    DDON_STUB("nCaplink::ChatLastIdReqCtx::ChatLastIdReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatLastIdReqCtx::update() {
    DDON_STUB("nCaplink::ChatLastIdReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatLastIdReqCtx::request() {
    DDON_STUB("nCaplink::ChatLastIdReqCtx::request")
    /* stub */
}

inline nCaplink::ChatLastIdReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatLastIdReqCtx::MyDTI nCaplink::ChatLastIdReqCtx::DTI("ChatLastIdReqCtx", &::nCaplink::HttpRequestContext::DTI, 128ul, 0u, 0u);

MtObject* nCaplink::ChatLastIdReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::ChatLastIdReqCtx;
}

void nCaplink::ChatLastIdReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "last_chat_id") != 0) {
        if (::strcmp(chars, "code") != 0) {
            int t0 = ::strcmp(chars, "detail_message");
            mbLastChatId = false;
            mbCode = false;
            if (t0 == 0) {
                mbDetailMessage = true;
            } else {
                mbDetailMessage = false;
            }
        } else {
            mbLastChatId = false;
            mbCode = true;
            mbDetailMessage = false;
        }
    } else {
        mbLastChatId = true;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::ChatLastIdReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatLastIdReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatLastIdReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatLastIdReqCtx::JsonParser::number(s64 value) {
    if (mbLastChatId) {
        mpParent->mLastChatId = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbCode) {
            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
        }
    }
}

__attribute__((weak)) void nCaplink::ChatLastIdReqCtx::JsonParser::number(f64 value) {
}

