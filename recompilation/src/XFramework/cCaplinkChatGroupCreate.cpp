// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkChatGroupCreate.h"
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

__attribute__((weak)) void nCaplink::ChatGroupCreateAns::init() {
    DDON_STUB("nCaplink::ChatGroupCreateAns::init")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupCreateAns::setChatGroupInfo(MT_CTSTR id, MT_CTSTR name, MT_CTSTR owner_unique_id, s32 last_chat_id, s32 member_total, s32 member_limmit, MT_CTSTR update_at) {
    DDON_STUB("nCaplink::ChatGroupCreateAns::setChatGroupInfo")
    /* stub */
}

const MtDTI& nCaplink::ChatGroupCreateReqCtx::getDTI() const {
    return nCaplink::ChatGroupCreateReqCtx::DTI;
}

void* nCaplink::ChatGroupCreateReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ChatGroupCreateReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::ChatGroupCreateReqCtx::DTI.mID);
}

nCaplink::ChatGroupCreateReqCtx::ChatGroupCreateReqCtx(MT_CTSTR group_name, s32 group_skin_id, MT_CTSTR group_message, const MtArray* user_info_list) {
    DDON_STUB("nCaplink::ChatGroupCreateReqCtx::ChatGroupCreateReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupCreateReqCtx::update() {
    DDON_STUB("nCaplink::ChatGroupCreateReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupCreateReqCtx::request() {
    DDON_STUB("nCaplink::ChatGroupCreateReqCtx::request")
    /* stub */
}

inline nCaplink::ChatGroupCreateReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::ChatGroupCreateReqCtx::MyDTI nCaplink::ChatGroupCreateReqCtx::DTI("ChatGroupCreateReqCtx", &::nCaplink::HttpRequestContext::DTI, 216ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::ChatGroupCreateReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::ChatGroupCreateReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::ChatGroupCreateReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "group_id") != 0) {
        if (::strcmp(chars, "group_name") != 0) {
            if (::strcmp(chars, "owner_unique_id") != 0) {
                if (::strcmp(chars, "last_chat_id") != 0) {
                    if (::strcmp(chars, "member_total") != 0) {
                        if (::strcmp(chars, "member_limit") != 0) {
                            if (::strcmp(chars, "updated_at") != 0) {
                                if (::strcmp(chars, "code") != 0) {
                                    int t0 = ::strcmp(chars, "detail_message");
                                    mbGroupId = false;
                                    mbGroupName = false;
                                    mbOwnerUniqueId = false;
                                    mbLastChatId = false;
                                    mbMemberTotal = false;
                                    mbMemberLimit = false;
                                    mbUpdatedAt = false;
                                    mbCode = false;
                                    if (t0 != 0) {
                                        mbDetailMessage = false;
                                    } else {
                                        mbDetailMessage = true;
                                    }
                                } else {
                                    mbUpdatedAt = false;
                                    mbMemberTotal = false;
                                    mbMemberLimit = false;
                                    mbGroupId = false;
                                    mbGroupName = false;
                                    mbOwnerUniqueId = false;
                                    mbLastChatId = false;
                                    mbCode = true;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbMemberTotal = false;
                                mbMemberLimit = false;
                                mbGroupId = false;
                                mbGroupName = false;
                                mbOwnerUniqueId = false;
                                mbLastChatId = false;
                                mbUpdatedAt = true;
                                mbCode = false;
                            }
                        } else {
                            mbMemberTotal = false;
                            mbGroupId = false;
                            mbGroupName = false;
                            mbOwnerUniqueId = false;
                            mbLastChatId = false;
                            mbMemberLimit = true;
                            mbUpdatedAt = false;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbGroupId = false;
                        mbGroupName = false;
                        mbOwnerUniqueId = false;
                        mbLastChatId = false;
                        mbMemberTotal = true;
                        mbMemberLimit = false;
                        mbUpdatedAt = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbGroupId = false;
                    mbGroupName = false;
                    mbOwnerUniqueId = false;
                    mbLastChatId = true;
                    mbDetailMessage = false;
                    mbMemberTotal = false;
                    mbMemberLimit = false;
                    mbUpdatedAt = false;
                    mbCode = false;
                }
            } else {
                mbGroupId = false;
                mbGroupName = false;
                mbOwnerUniqueId = true;
                mbCode = false;
                mbDetailMessage = false;
                mbLastChatId = false;
                mbMemberTotal = false;
                mbMemberLimit = false;
                mbUpdatedAt = false;
            }
        } else {
            mbGroupId = false;
            mbGroupName = true;
            mbDetailMessage = false;
            mbUpdatedAt = false;
            mbCode = false;
            mbOwnerUniqueId = false;
            mbLastChatId = false;
            mbMemberTotal = false;
            mbMemberLimit = false;
        }
    } else {
        mbGroupId = true;
        mbGroupName = false;
        mbOwnerUniqueId = false;
        mbLastChatId = false;
        mbMemberTotal = false;
        mbMemberLimit = false;
        mbUpdatedAt = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::ChatGroupCreateReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::ChatGroupCreateReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::ChatGroupCreateReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::ChatGroupCreateReqCtx::JsonParser::number(s64 value) {
    if (mbLastChatId) {
        mpParent->mLastChatId = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbMemberTotal) {
            mpParent->mMemberTotal = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbMemberLimit) {
                mpParent->mMemberLimit = static_cast<s32>(static_cast<unsigned int>(value));
            } else {
                if (mbCode) {
                    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::ChatGroupCreateReqCtx::JsonParser::number(f64 value) {
}

