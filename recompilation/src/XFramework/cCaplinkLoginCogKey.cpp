// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkLoginCogKey.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void nCaplink::LoginCogKeyAns::init() {
    DDON_STUB("nCaplink::LoginCogKeyAns::init")
    /* stub */
}

const MtDTI& nCaplink::LoginCogKeyReqCtx::getDTI() const {
    return nCaplink::LoginCogKeyReqCtx::DTI;
}

void* nCaplink::LoginCogKeyReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::LoginCogKeyReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::LoginCogKeyReqCtx::DTI.mID);
}

nCaplink::LoginCogKeyReqCtx::LoginCogKeyReqCtx(MT_CTSTR content_user_id, s32 platform_id) {
    DDON_STUB("nCaplink::LoginCogKeyReqCtx::LoginCogKeyReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::LoginCogKeyReqCtx::update() {
    DDON_STUB("nCaplink::LoginCogKeyReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::LoginCogKeyReqCtx::reqCommonKey() {
    DDON_STUB("nCaplink::LoginCogKeyReqCtx::reqCommonKey")
    /* stub */
}

__attribute__((weak)) void nCaplink::LoginCogKeyReqCtx::reqReauth() {
    DDON_STUB("nCaplink::LoginCogKeyReqCtx::reqReauth")
    /* stub */
}

inline nCaplink::LoginCogKeyReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::LoginCogKeyReqCtx::MyDTI nCaplink::LoginCogKeyReqCtx::DTI("LoginCogKeyReqCtx", &::nCaplink::HttpRequestContext::DTI, 144ul, 0u, 0u);

MtObject* nCaplink::LoginCogKeyReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::LoginCogKeyReqCtx;
}

void nCaplink::LoginCogKeyReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "temp_key") != 0) {
        if (::strcmp(chars, "common_key") != 0) {
            if (::strcmp(chars, "unique_id") != 0) {
                if (::strcmp(chars, "nickname") != 0) {
                    if (::strcmp(chars, "key") != 0) {
                        if (::strcmp(chars, "message") != 0) {
                            if (::strcmp(chars, "code") != 0) {
                                int t0 = ::strcmp(chars, "detail_message");
                                mCode = false;
                                mbNickname = false;
                                mbMessage = false;
                                mbTempKey = false;
                                mbCommonKey = false;
                                mbKey = false;
                                mbUniqueId = false;
                                if (t0 == 0) {
                                    mDetailMessage = true;
                                } else {
                                    mDetailMessage = false;
                                }
                            } else {
                                mbNickname = false;
                                mbMessage = false;
                                mbTempKey = false;
                                mbCommonKey = false;
                                mbKey = false;
                                mbUniqueId = false;
                                mCode = true;
                                mDetailMessage = false;
                            }
                        } else {
                            mbNickname = false;
                            mbTempKey = false;
                            mbCommonKey = false;
                            mbKey = false;
                            mbUniqueId = false;
                            mbMessage = true;
                            mCode = false;
                            mDetailMessage = false;
                        }
                    } else {
                        mbTempKey = false;
                        mbCommonKey = false;
                        mbKey = true;
                        mDetailMessage = false;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbMessage = false;
                        mCode = false;
                    }
                } else {
                    mbTempKey = false;
                    mbCommonKey = false;
                    mbKey = false;
                    mbUniqueId = false;
                    mbNickname = true;
                    mbMessage = false;
                    mCode = false;
                    mDetailMessage = false;
                }
            } else {
                mbTempKey = false;
                mbCommonKey = false;
                mbKey = false;
                mbUniqueId = true;
                mbNickname = false;
                mbMessage = false;
                mCode = false;
                mDetailMessage = false;
            }
        } else {
            mbTempKey = false;
            mbCommonKey = true;
            mCode = false;
            mDetailMessage = false;
            mbKey = false;
            mbUniqueId = false;
            mbNickname = false;
            mbMessage = false;
        }
    } else {
        mbTempKey = true;
        mDetailMessage = false;
        mbMessage = false;
        mCode = false;
        mbCommonKey = false;
        mbKey = false;
        mbUniqueId = false;
        mbNickname = false;
    }
}

__attribute__((weak)) void nCaplink::LoginCogKeyReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::LoginCogKeyReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::LoginCogKeyReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::LoginCogKeyReqCtx::JsonParser::number(s64 value) {
    if (!mCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::LoginCogKeyReqCtx::JsonParser::number(f64 value) {
}

