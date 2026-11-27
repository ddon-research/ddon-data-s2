// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCaplinkNotify.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCharSet.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cCaplink.h"
#include "cCaplinkContext.h"
#include "cHttpClient.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nCaplink::NotifyAns::init() {
    this->::nCaplink::ContextListener::init();
    mContentTotal = 0;
    mContentUpdate = 0;
    mResourcePresetTotal = 0;
    mResourcePresetUpdate = 0;
    mProfileUpdate = 0;
    mStampUpdate = 0;
    mStampTotal = 0;
    mLastPostId = 0;
    mAppNotifyTotal = 0;
    mTagTotal = 0;
    mContentInviteTotal = 0;
    mFriendTagFreeTotal = 0;
    mFriendRequestReceiveTotal = 0;
    mFriendTotal = 0;
    mFriendTagContentTotal = 0;
}

const MtDTI& nCaplink::NotifyReqCtx::getDTI() const {
    return nCaplink::NotifyReqCtx::DTI;
}

void* nCaplink::NotifyReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::NotifyReqCtx::DTI.mID);
}

nCaplink::NotifyReqCtx::NotifyReqCtx() {
    DDON_STUB("nCaplink::NotifyReqCtx::NotifyReqCtx")
    /* stub */
}

nCaplink::NotifyReqCtx::NotifyReqCtx(MT_CTSTR friend_from_datetime, MT_CTSTR friend_tag_content_from_datetime, MT_CTSTR friend_tag_free_from_datetime, MT_CTSTR friend_request_receive_from_datetime, MT_CTSTR tag_from_datetime, MT_CTSTR content_invite_from_datetime, MT_CTSTR stamp_from_datetime, MT_CTSTR content_from_datetime, MT_CTSTR resource_preset_from_datetime, MT_CTSTR profile_from_datetime) {
    DDON_STUB("nCaplink::NotifyReqCtx::NotifyReqCtx")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyReqCtx::update() {
    DDON_STUB("nCaplink::NotifyReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyReqCtx::request() {
    DDON_STUB("nCaplink::NotifyReqCtx::request")
    /* stub */
}

inline nCaplink::NotifyReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::NotifyReqCtx::MyDTI nCaplink::NotifyReqCtx::DTI("NotifyReqCtx", &::nCaplink::HttpRequestContext::DTI, 264ul, 0u, 0u);

__attribute__((weak)) MtObject* nCaplink::NotifyReqCtx::MyDTI::newInstance() const {
    DDON_STUB("nCaplink::NotifyReqCtx::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void nCaplink::NotifyReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::NotifyReqCtx::JsonParser::fieldName")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::NotifyReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyReqCtx::JsonParser::number(u64 value) {
}

__attribute__((weak)) void nCaplink::NotifyReqCtx::JsonParser::number(s64 value) {
    DDON_STUB("nCaplink::NotifyReqCtx::JsonParser::number")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyReqCtx::JsonParser::number(f64 value) {
}

