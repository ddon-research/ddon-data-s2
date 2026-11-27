// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkUserProfileContentListGet.h"
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

void nCaplink::UserProfileContentListGetAns::init() {
    this->::nCaplink::ContextListener::init();
    mUserContentTagInfoTbl.mAutoDelete = true;
    if (mUserContentTagInfoTbl.mLength != 0) {
        u32 v0_0 = mUserContentTagInfoTbl.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mUserContentTagInfoTbl.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mUserContentTagInfoTbl.mpArray[i0_3];
                v1_0 = mUserContentTagInfoTbl.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mUserContentTagInfoTbl.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mUserContentTagInfoTbl.mpArray));
    }
    mUserContentTagInfoTbl.mpArray = nullptr;
    mUserContentTagInfoTbl.mBufsiz = 0;
    mUserContentTagInfoTbl.mLength = 0;
    mTotal = 0;
}

const MtDTI& nCaplink::UserProfileContentListGetReqCtx::getDTI() const {
    return nCaplink::UserProfileContentListGetReqCtx::DTI;
}

void* nCaplink::UserProfileContentListGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::UserProfileContentListGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::UserProfileContentListGetReqCtx::DTI.mID);
}

nCaplink::UserProfileContentListGetReqCtx::UserProfileContentListGetReqCtx(MT_CTSTR unique_id, s32 offset, s32 count) {
    DDON_STUB("nCaplink::UserProfileContentListGetReqCtx::UserProfileContentListGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileContentListGetReqCtx::update() {
    DDON_STUB("nCaplink::UserProfileContentListGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileContentListGetReqCtx::request() {
    DDON_STUB("nCaplink::UserProfileContentListGetReqCtx::request")
    /* stub */
}

inline nCaplink::UserProfileContentListGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::UserProfileContentListGetReqCtx::MyDTI nCaplink::UserProfileContentListGetReqCtx::DTI("UserProfileContentListGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::UserProfileContentListGetReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::UserProfileContentListGetReqCtx::MyDTI::newInstance")
    return nullptr;
}

void nCaplink::UserProfileContentListGetReqCtx::JsonParser::beginArray() {
    mbArray = true;
}

void nCaplink::UserProfileContentListGetReqCtx::JsonParser::endArray() {
    mbArray = false;
}

__attribute__((weak)) void nCaplink::UserProfileContentListGetReqCtx::JsonParser::beginObject() {
}

__attribute__((weak)) void nCaplink::UserProfileContentListGetReqCtx::JsonParser::endObject() {
    DDON_STUB("nCaplink::UserProfileContentListGetReqCtx::JsonParser::endObject")
    /* stub */
}

void nCaplink::UserProfileContentListGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    if (::strcmp(chars, "total") != 0) {
        if (::strcmp(chars, "content_id") != 0) {
            if (::strcmp(chars, "character_name") != 0) {
                if (::strcmp(chars, "online") != 0) {
                    if (::strcmp(chars, "comment") != 0) {
                        if (::strcmp(chars, "online_privacy") != 0) {
                            if (::strcmp(chars, "visible") != 0) {
                                if (::strcmp(chars, "code") != 0) {
                                    int t0 = ::strcmp(chars, "detail_message");
                                    mbTotal = false;
                                    mbContentId = false;
                                    mbCharacterName = false;
                                    mbOnline = false;
                                    mbComment = false;
                                    mbOnlinePrivacy = false;
                                    mbVisible = false;
                                    mbCode = false;
                                    if (t0 == 0) {
                                        mbDetailMessage = true;
                                    } else {
                                        mbDetailMessage = false;
                                    }
                                } else {
                                    mbVisible = false;
                                    mbComment = false;
                                    mbOnlinePrivacy = false;
                                    mbTotal = false;
                                    mbContentId = false;
                                    mbCharacterName = false;
                                    mbOnline = false;
                                    mbCode = true;
                                    mbDetailMessage = false;
                                }
                            } else {
                                mbComment = false;
                                mbOnlinePrivacy = false;
                                mbTotal = false;
                                mbContentId = false;
                                mbCharacterName = false;
                                mbOnline = false;
                                mbVisible = true;
                                mbCode = false;
                                mbDetailMessage = false;
                            }
                        } else {
                            mbComment = false;
                            mbTotal = false;
                            mbContentId = false;
                            mbCharacterName = false;
                            mbOnline = false;
                            mbOnlinePrivacy = true;
                            mbVisible = false;
                            mbCode = false;
                            mbDetailMessage = false;
                        }
                    } else {
                        mbTotal = false;
                        mbContentId = false;
                        mbCharacterName = false;
                        mbOnline = false;
                        mbComment = true;
                        mbOnlinePrivacy = false;
                        mbVisible = false;
                        mbCode = false;
                        mbDetailMessage = false;
                    }
                } else {
                    mbTotal = false;
                    mbContentId = false;
                    mbCharacterName = false;
                    mbOnline = true;
                    mbDetailMessage = false;
                    mbComment = false;
                    mbOnlinePrivacy = false;
                    mbVisible = false;
                    mbCode = false;
                }
            } else {
                mbTotal = false;
                mbContentId = false;
                mbCharacterName = true;
                mbCode = false;
                mbDetailMessage = false;
                mbOnline = false;
                mbComment = false;
                mbOnlinePrivacy = false;
                mbVisible = false;
            }
        } else {
            mbTotal = false;
            mbContentId = true;
            mbDetailMessage = false;
            mbVisible = false;
            mbCode = false;
            mbCharacterName = false;
            mbOnline = false;
            mbComment = false;
            mbOnlinePrivacy = false;
        }
    } else {
        mbTotal = true;
        mbContentId = false;
        mbCharacterName = false;
        mbOnline = false;
        mbComment = false;
        mbOnlinePrivacy = false;
        mbVisible = false;
        mbCode = false;
        mbDetailMessage = false;
    }
}

__attribute__((weak)) void nCaplink::UserProfileContentListGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::UserProfileContentListGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileContentListGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::UserProfileContentListGetReqCtx::JsonParser::number(s64 value) {
    if (mbTotal) {
        mpParent->mTotal = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbOnline) {
            mOnline = static_cast<s8>(static_cast<unsigned char>(value));
        } else {
            if (mbOnlinePrivacy) {
                mOnlinePrivacy = static_cast<s8>(static_cast<unsigned char>(value));
            } else {
                if (mbVisible) {
                    mVislble = static_cast<s8>(static_cast<unsigned char>(value));
                } else {
                    if (mbCode) {
                        mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::UserProfileContentListGetReqCtx::JsonParser::number(f64 value) {
}

