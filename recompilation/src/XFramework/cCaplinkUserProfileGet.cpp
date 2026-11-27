// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkUserProfileGet.h"
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
#include "cCaplinkDataDef.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::UserProfileGetAns::init() {
    ::memset(static_cast<void*>(&mUserProfile), 0, 1704ul);
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::UserProfileGetReqCtx::getDTI() const {
    return nCaplink::UserProfileGetReqCtx::DTI;
}

void* nCaplink::UserProfileGetReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::UserProfileGetReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::UserProfileGetReqCtx::DTI.mID);
}

nCaplink::UserProfileGetReqCtx::UserProfileGetReqCtx(MT_CTSTR unique_id) {
    DDON_STUB("nCaplink::UserProfileGetReqCtx::UserProfileGetReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileGetReqCtx::update() {
    DDON_STUB("nCaplink::UserProfileGetReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileGetReqCtx::request() {
    DDON_STUB("nCaplink::UserProfileGetReqCtx::request")
    /* stub */
}

inline nCaplink::UserProfileGetReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::UserProfileGetReqCtx::MyDTI nCaplink::UserProfileGetReqCtx::DTI("UserProfileGetReqCtx", &::nCaplink::HttpRequestContext::DTI, 200ul, 0u, 0u);

MtObject* nCaplink::UserProfileGetReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::UserProfileGetReqCtx;
}

__attribute__((weak)) void nCaplink::UserProfileGetReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::UserProfileGetReqCtx::JsonParser::fieldName")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileGetReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::UserProfileGetReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::UserProfileGetReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::UserProfileGetReqCtx::JsonParser::number(s64 value) {
    if (mbTimelineSkinId) {
        mpParent->mTimelineSkinId = static_cast<s32>(static_cast<unsigned int>(value));
    } else {
        if (mbProfileSkinId) {
            mpParent->mProfileSkinId = static_cast<s32>(static_cast<unsigned int>(value));
        } else {
            if (mbContentTotal) {
                mpParent->mContentTotal = static_cast<s32>(static_cast<unsigned int>(value));
            } else {
                if (mbTimelinePrivacy) {
                    mpParent->mTimelinePrivacy = static_cast<s8>(static_cast<unsigned char>(value));
                } else {
                    if (mbProfilePrivacy) {
                        mpParent->mProfilePrivacy = static_cast<s8>(static_cast<unsigned char>(value));
                    } else {
                        if (mbCaptalkPrivacy) {
                            mpParent->mCaptalkPrivacy = static_cast<s8>(static_cast<unsigned char>(value));
                        } else {
                            if (mbFindSearch) {
                                mpParent->mFindSearch = static_cast<s8>(static_cast<unsigned char>(value));
                            } else {
                                if (mbFriendTotal) {
                                    mpParent->mFriendsTotal = static_cast<s32>(static_cast<unsigned int>(value));
                                } else {
                                    if (mbTagsTotal) {
                                        mpParent->mTagsTotal = static_cast<s32>(static_cast<unsigned int>(value));
                                    } else {
                                        if (mbFriendTagsTotal) {
                                            mpParent->mFriendTagsTotal = static_cast<s32>(static_cast<unsigned int>(value));
                                        } else {
                                            if (mbIgnoresTotal) {
                                                mpParent->mIgnoresTotal = static_cast<s32>(static_cast<unsigned int>(value));
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
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void nCaplink::UserProfileGetReqCtx::JsonParser::number(f64 value) {
}

