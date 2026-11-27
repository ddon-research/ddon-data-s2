// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatGroupMemberListGet.h"
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

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetAns::init() {
    DDON_STUB("nCaplink::ChatGroupMemberListGetAns::init")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetAns::setGroupInfo(MT_CTSTR group_name, s32 group_skin_id, MT_CTSTR owner_unique_id, MT_CTSTR owner_nickname, MT_CTSTR owner_icon) {
    DDON_STUB("nCaplink::ChatGroupMemberListGetAns::setGroupInfo")
    /* stub */
}

const MtDTI& nCaplink::ChatGroupMemberListGetReqCtx::getDTI() const {
    return nCaplink::ChatGroupMemberListGetReqCtx::DTI;
}

void* nCaplink::ChatGroupMemberListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupMemberListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupMemberListGetReqCtx::DTI.mID);
}

nCaplink::ChatGroupMemberListGetReqCtx::ChatGroupMemberListGetReqCtx(MT_CTSTR group_id, s32 offset, s32 count) {
    DDON_STUB("nCaplink::ChatGroupMemberListGetReqCtx::ChatGroupMemberListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupMemberListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupMemberListGetReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupMemberListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupMemberListGetReqCtx::MyDTI nCaplink::ChatGroupMemberListGetReqCtx::DTI("ChatGroupMemberListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 200ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ChatGroupMemberListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ChatGroupMemberListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "group_name") != 0) {
            if (::strcmp(chars, "group_skin_id") != 0) {
                if (::strcmp(chars, "owner_unique_id") != 0) {
                    if (::strcmp(chars, "owner_nickname") != 0) {
                        if (::strcmp(chars, "owner_icon") != 0) {
                            if (::strcmp(chars, "unique_id") != 0) {
                                if (::strcmp(chars, "nickname") != 0) {
                                    if (::strcmp(chars, "icon") != 0) {
                                        if (::strcmp(chars, "code") != 0) {
                                            int t0 = ::strcmp(chars, "detail_message");
                                            mbIcon = false;
                                            mbCode = false;
                                            mbTotal = false;
                                            mbGroupName = false;
                                            mbGroupSkinId = false;
                                            mbOwnerUniqueId = false;
                                            mbOwnerNickname = false;
                                            mbOwnerIcon = false;
                                            mbUniqueId = false;
                                            mbNickname = false;
                                            if (t0 == 0) {
                                                mbDetailMessage = true;
                                            } else {
                                                mbDetailMessage = false;
                                            }
                                        } else {
                                            mbIcon = false;
                                            mbTotal = false;
                                            mbGroupName = false;
                                            mbGroupSkinId = false;
                                            mbOwnerUniqueId = false;
                                            mbOwnerNickname = false;
                                            mbOwnerIcon = false;
                                            mbUniqueId = false;
                                            mbNickname = false;
                                            mbCode = true;
                                            mbDetailMessage = false;
                                        }
                                    } else {
                                        mbTotal = false;
                                        mbGroupName = false;
                                        mbGroupSkinId = false;
                                        mbOwnerUniqueId = false;
                                        mbOwnerNickname = false;
                                        mbOwnerIcon = false;
                                        mbUniqueId = false;
                                        mbNickname = false;
                                        mbIcon = true;
                                        mbCode = false;
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbUniqueId = false;
                                    mbOwnerNickname = false;
                                    mbOwnerIcon = false;
                                    mbTotal = false;
                                    mbGroupName = false;
                                    mbGroupSkinId = false;
                                    mbOwnerUniqueId = false;
                                    mbNickname = true;
                                    mbIcon = false;
                                    mbCode = false;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbOwnerNickname = false;
                                mbOwnerIcon = false;
                                mbTotal = false;
                                mbGroupName = false;
                                mbGroupSkinId = false;
                                mbOwnerUniqueId = false;
                                mbUniqueId = true;
                                mbNickname = false;
                                mbIcon = false;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbOwnerNickname = false;
                            mbTotal = false;
                            mbGroupName = false;
                            mbGroupSkinId = false;
                            mbOwnerUniqueId = false;
                            mbOwnerIcon = true;
                            mbDetailMessage = false;
                            mbUniqueId = false;
                            mbNickname = false;
                            mbIcon = false;
                            mbCode = false;
                        }
                    } else {
                        mbTotal = false;
                        mbGroupName = false;
                        mbGroupSkinId = false;
                        mbOwnerUniqueId = false;
                        mbOwnerNickname = true;
                        mbCode = false;
                        mbDetailMessage = false;
                        mbOwnerIcon = false;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbIcon = false;
                    }
                } else {
                    mbTotal = false;
                    mbGroupName = false;
                    mbGroupSkinId = false;
                    mbOwnerUniqueId = true;
                    mbDetailMessage = false;
                    mbIcon = false;
                    mbCode = false;
                    mbOwnerNickname = false;
                    mbOwnerIcon = false;
                    mbUniqueId = false;
                    mbNickname = false;
                }
            } else {
                mbTotal = false;
                mbGroupName = false;
                mbGroupSkinId = true;
                mbOwnerUniqueId = false;
                mbOwnerNickname = false;
                mbOwnerIcon = false;
                mbUniqueId = false;
                mbNickname = false;
                mbIcon = false;
                mbCode = false;
                mbDetailMessage = false;
            }
        } else {
            mbTotal = false;
            mbGroupName = true;
            mbDetailMessage = false;
            mbGroupSkinId = false;
            mbOwnerUniqueId = false;
            mbOwnerNickname = false;
            mbOwnerIcon = false;
            mbUniqueId = false;
            mbNickname = false;
            mbIcon = false;
            mbCode = false;
        }
    } else {
        mbTotal = true;
        mbCode = false;
        mbDetailMessage = false;
        mbGroupName = false;
        mbGroupSkinId = false;
        mbOwnerUniqueId = false;
        mbOwnerNickname = false;
        mbOwnerIcon = false;
        mbUniqueId = false;
        mbNickname = false;
        mbIcon = false;
    }
}

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbGroupSkinId) {
            mpParent->mGroupSkinId = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbCode) {
                mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
            }
        }
    }
}

__attribute__((weak)) void nCaplink::ChatGroupMemberListGetReqCtx::JsonParser::number(f64 value) {
}

