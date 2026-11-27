// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkFriendListGet.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
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

void nCaplink::FriendListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mFriendInfoTbl.mAutoDelete = true;
    if (mFriendInfoTbl.mLength != 0) {
        u32 v0_0 = mFriendInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFriendInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFriendInfoTbl.mpArray[i0_3];
                v1_0 = mFriendInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFriendInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mFriendInfoTbl.mpArray));
    }
    mFriendInfoTbl.mpArray = nullptr;
    mFriendInfoTbl.mBufsiz = 0;
    mFriendInfoTbl.mLength = 0;
    mTotal = 0;
    mLimmit = 0;
}

const MtDTI& nCaplink::FriendListGetReqCtx::getDTI() const {
    return nCaplink::FriendListGetReqCtx::DTI;
}

void* nCaplink::FriendListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::FriendListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::FriendListGetReqCtx::DTI.mID);
}

nCaplink::FriendListGetReqCtx::FriendListGetReqCtx(MT_CTSTR from_datetime, s32 offset, s32 count) {
    DDON_STUB("nCaplink::FriendListGetReqCtx::FriendListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendListGetReqCtx::update() {
    DDON_STUB("nCaplink::FriendListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendListGetReqCtx::request() {
    DDON_STUB("nCaplink::FriendListGetReqCtx::request")
    /* stub */
}

inline nCaplink::FriendListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::FriendListGetReqCtx::MyDTI nCaplink::FriendListGetReqCtx::DTI("FriendListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 168ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::FriendListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::FriendListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::FriendListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::FriendListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::FriendListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::FriendListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::FriendListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::FriendListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "limit") != 0) {
            if (::strcmp(chars, "unique_id") != 0) {
                if (::strcmp(chars, "nickname") != 0) {
                    if (::strcmp(chars, "labelname") != 0) {
                        if (::strcmp(chars, "memo") != 0) {
                            if (::strcmp(chars, "privacy") != 0) {
                                if (::strcmp(chars, "icon") != 0) {
                                    if (::strcmp(chars, "comment") != 0) {
                                        if (::strcmp(chars, "attribute") != 0) {
                                            if (::strcmp(chars, "alive") != 0) {
                                                if (::strcmp(chars, "accord_at") != 0) {
                                                    if (::strcmp(chars, "updated_at") != 0) {
                                                        if (::strcmp(chars, "code") != 0) {
                                                            int t0 = ::strcmp(chars, "detail_message");
                                                            mbUpdatedAt = false;
                                                            mbCode = false;
                                                            mbComment = false;
                                                            mbAttribute = false;
                                                            mbAlive = false;
                                                            mbAccordAt = false;
                                                            mbTotal = false;
                                                            mbLimmit = false;
                                                            mbUniqueId = false;
                                                            mbNickname = false;
                                                            mbLabelname = false;
                                                            mbMemo = false;
                                                            mbPrivacy = false;
                                                            mbIcon = false;
                                                            if (t0 == 0) {
                                                                mbDetailMessage = true;
                                                            } else {
                                                                mbDetailMessage = false;
                                                            }
                                                        } else {
                                                            mbUpdatedAt = false;
                                                            mbComment = false;
                                                            mbAttribute = false;
                                                            mbAlive = false;
                                                            mbAccordAt = false;
                                                            mbTotal = false;
                                                            mbLimmit = false;
                                                            mbUniqueId = false;
                                                            mbNickname = false;
                                                            mbLabelname = false;
                                                            mbMemo = false;
                                                            mbPrivacy = false;
                                                            mbIcon = false;
                                                            mbCode = true;
                                                            mbDetailMessage = false;
                                                        }
                                                    } else {
                                                        mbComment = false;
                                                        mbAttribute = false;
                                                        mbAlive = false;
                                                        mbAccordAt = false;
                                                        mbTotal = false;
                                                        mbLimmit = false;
                                                        mbUniqueId = false;
                                                        mbNickname = false;
                                                        mbLabelname = false;
                                                        mbMemo = false;
                                                        mbPrivacy = false;
                                                        mbIcon = false;
                                                        mbUpdatedAt = true;
                                                        mbCode = false;
                                                        mbDetailMessage = false;
                                                    }
                                                } else {
                                                    mbAlive = false;
                                                    mbComment = false;
                                                    mbAttribute = false;
                                                    mbTotal = false;
                                                    mbLimmit = false;
                                                    mbUniqueId = false;
                                                    mbNickname = false;
                                                    mbLabelname = false;
                                                    mbMemo = false;
                                                    mbPrivacy = false;
                                                    mbIcon = false;
                                                    mbAccordAt = true;
                                                    mbUpdatedAt = false;
                                                    mbCode = false;
                                                    mbDetailMessage = false;
                                                }
                                            } else {
                                                mbComment = false;
                                                mbAttribute = false;
                                                mbTotal = false;
                                                mbLimmit = false;
                                                mbUniqueId = false;
                                                mbNickname = false;
                                                mbLabelname = false;
                                                mbMemo = false;
                                                mbPrivacy = false;
                                                mbIcon = false;
                                                mbAlive = true;
                                                mbAccordAt = false;
                                                mbUpdatedAt = false;
                                                mbCode = false;
                                                mbDetailMessage = false;
                                            }
                                        } else {
                                            mbComment = false;
                                            mbTotal = false;
                                            mbLimmit = false;
                                            mbUniqueId = false;
                                            mbNickname = false;
                                            mbLabelname = false;
                                            mbMemo = false;
                                            mbPrivacy = false;
                                            mbIcon = false;
                                            mbAttribute = true;
                                            mbDetailMessage = false;
                                            mbAlive = false;
                                            mbAccordAt = false;
                                            mbUpdatedAt = false;
                                            mbCode = false;
                                        }
                                    } else {
                                        mbTotal = false;
                                        mbLimmit = false;
                                        mbUniqueId = false;
                                        mbNickname = false;
                                        mbLabelname = false;
                                        mbMemo = false;
                                        mbPrivacy = false;
                                        mbIcon = false;
                                        mbComment = true;
                                        mbCode = false;
                                        mbDetailMessage = false;
                                        mbAttribute = false;
                                        mbAlive = false;
                                        mbAccordAt = false;
                                        mbUpdatedAt = false;
                                    }
                                } else {
                                    mbPrivacy = false;
                                    mbLabelname = false;
                                    mbMemo = false;
                                    mbTotal = false;
                                    mbLimmit = false;
                                    mbUniqueId = false;
                                    mbNickname = false;
                                    mbIcon = true;
                                    mbDetailMessage = false;
                                    mbUpdatedAt = false;
                                    mbCode = false;
                                    mbComment = false;
                                    mbAttribute = false;
                                    mbAlive = false;
                                    mbAccordAt = false;
                                }
                            } else {
                                mbLabelname = false;
                                mbMemo = false;
                                mbTotal = false;
                                mbLimmit = false;
                                mbUniqueId = false;
                                mbNickname = false;
                                mbPrivacy = true;
                                mbIcon = false;
                                mbComment = false;
                                mbAttribute = false;
                                mbAlive = false;
                                mbAccordAt = false;
                                mbUpdatedAt = false;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbLabelname = false;
                            mbTotal = false;
                            mbLimmit = false;
                            mbUniqueId = false;
                            mbNickname = false;
                            mbMemo = true;
                            mbDetailMessage = false;
                            mbPrivacy = false;
                            mbIcon = false;
                            mbComment = false;
                            mbAttribute = false;
                            mbAlive = false;
                            mbAccordAt = false;
                            mbUpdatedAt = false;
                            mbCode = false;
                        }
                    } else {
                        mbTotal = false;
                        mbLimmit = false;
                        mbUniqueId = false;
                        mbNickname = false;
                        mbLabelname = true;
                        mbCode = false;
                        mbDetailMessage = false;
                        mbMemo = false;
                        mbPrivacy = false;
                        mbIcon = false;
                        mbComment = false;
                        mbAttribute = false;
                        mbAlive = false;
                        mbAccordAt = false;
                        mbUpdatedAt = false;
                    }
                } else {
                    mbTotal = false;
                    mbLimmit = false;
                    mbUniqueId = false;
                    mbNickname = true;
                    mbDetailMessage = false;
                    mbUpdatedAt = false;
                    mbCode = false;
                    mbLabelname = false;
                    mbMemo = false;
                    mbPrivacy = false;
                    mbIcon = false;
                    mbComment = false;
                    mbAttribute = false;
                    mbAlive = false;
                    mbAccordAt = false;
                }
            } else {
                mbTotal = false;
                mbLimmit = false;
                mbUniqueId = true;
                mbAccordAt = false;
                mbUpdatedAt = false;
                mbCode = false;
                mbDetailMessage = false;
                mbNickname = false;
                mbLabelname = false;
                mbMemo = false;
                mbPrivacy = false;
                mbIcon = false;
                mbComment = false;
                mbAttribute = false;
                mbAlive = false;
            }
        } else {
            mbTotal = false;
            mbLimmit = true;
            mbDetailMessage = false;
            mbAlive = false;
            mbAccordAt = false;
            mbUpdatedAt = false;
            mbCode = false;
            mbUniqueId = false;
            mbNickname = false;
            mbLabelname = false;
            mbMemo = false;
            mbPrivacy = false;
            mbIcon = false;
            mbComment = false;
            mbAttribute = false;
        }
    } else {
        mbTotal = true;
        mbCode = false;
        mbDetailMessage = false;
        mbAttribute = false;
        mbAlive = false;
        mbAccordAt = false;
        mbUpdatedAt = false;
        mbLimmit = false;
        mbUniqueId = false;
        mbNickname = false;
        mbLabelname = false;
        mbMemo = false;
        mbPrivacy = false;
        mbIcon = false;
        mbComment = false;
    }
}

__attribute__((weak)) void nCaplink::FriendListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::FriendListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::FriendListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::FriendListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbLimmit) {
            mpParent->mLimmit = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbPrivacy) {
                mPrivacy = static_cast<s8>(static_cast<unsigned char>(value));
            } else {
                if (mbAttribute) {
                    mAttribute = static_cast<s8>(static_cast<unsigned char>(value));
                } else {
                    if (mbAlive) {
                        mAlive = static_cast<s8>(static_cast<unsigned char>(value));
                    } else {
                        if (mbCode) {
                            mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::FriendListGetReqCtx::JsonParser::number(f64 value) {
}

