// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cCaplinkNotifyDeviceSettingModify.h"
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

void nCaplink::NotifyDeviceSettingModifyAns::init() {
    this->::nCaplink::ContextListener::init();
}

const MtDTI& nCaplink::NotifyDeviceSettingModifyReqCtx::getDTI() const {
    return nCaplink::NotifyDeviceSettingModifyReqCtx::DTI;
}

void* nCaplink::NotifyDeviceSettingModifyReqCtx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyDeviceSettingModifyReqCtx::DTI)->memAlloc(sz, align, ::nCaplink::NotifyDeviceSettingModifyReqCtx::DTI.mID);
}

nCaplink::NotifyDeviceSettingModifyReqCtx::NotifyDeviceSettingModifyReqCtx(s8 all, s8 profile, s8 fri, s8 timeline, s8 chat, s8 game) : nCaplink::HttpRequestContext(75) {
    mAll = all;
    mProfile = profile;
    mFriend = fri;
    mTimeline = timeline;
    mChat = chat;
    mGame = game;
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingModifyReqCtx::update() {
    DDON_STUB("nCaplink::NotifyDeviceSettingModifyReqCtx::update")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingModifyReqCtx::request() {
    DDON_STUB("nCaplink::NotifyDeviceSettingModifyReqCtx::request")
    /* stub */
}

inline nCaplink::NotifyDeviceSettingModifyReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCaplink::NotifyDeviceSettingModifyReqCtx::MyDTI nCaplink::NotifyDeviceSettingModifyReqCtx::DTI("NotifyDeviceSettingModifyReqCtx", &::nCaplink::HttpRequestContext::DTI, 112ul, 0u, 0u);

MtObject* nCaplink::NotifyDeviceSettingModifyReqCtx::MyDTI::newInstance() const {
    return new (16u) ::nCaplink::NotifyDeviceSettingModifyReqCtx;
}

void nCaplink::NotifyDeviceSettingModifyReqCtx::JsonParser::fieldName(MT_CTSTR chars, const u32 length) {
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

__attribute__((weak)) void nCaplink::NotifyDeviceSettingModifyReqCtx::JsonParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("nCaplink::NotifyDeviceSettingModifyReqCtx::JsonParser::string")
    /* stub */
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingModifyReqCtx::JsonParser::number(u64 value) {
}

void nCaplink::NotifyDeviceSettingModifyReqCtx::JsonParser::number(s64 value) {
    if (!mbCode) {
        return;
    }
    mpParent->mCode = static_cast<s32>(static_cast<unsigned int>(value));
}

__attribute__((weak)) void nCaplink::NotifyDeviceSettingModifyReqCtx::JsonParser::number(f64 value) {
}

