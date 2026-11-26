// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "nNetworkService.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetContext.h"
#include "../MT/MtNetCore.h"
#include "../MT/MtNetObject.h"
#include "../MT/MtNetSession.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "nNetworkRanking.h"
#include "nNetworkSessionDriver.h"
#include "nNetworkStorage.h"
#include "sNetwork.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nNetwork::Context::getDTI() const {
    return nNetwork::Context::DTI;
}

inline void nNetwork::Context::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::Context::DTI)->memFree(p_addr);
}

nNetwork::Context::Context() {
    DDON_STUB("nNetwork::Context::Context")
    /* stub */
}

nNetwork::Context::~Context() {
}

void nNetwork::Context::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "Bootup", static_cast<MT_MFUNC>(&::nNetwork::Context::bootup), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Shutdown", static_cast<MT_MFUNC>(&::nNetwork::Context::shutdown), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mState", &mState, 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mService", &mService, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOption", &mOption, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mUserIndex", &mUserIndex, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mReqLevel", &mReqLevel, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mServiceError.mNo", &mServiceError.mNo, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mServiceError.mCause", &mServiceError.mCause, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mServiceError.mNative", &mServiceError.mNative, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mIsFriendListChange", &mIsFriendListChange, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mIsSignInChange", &mIsSignInChange, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mInviteState", &mInviteState, 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpContext", reinterpret_cast<MtObject* *>(&mpContext), 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpFriendList", reinterpret_cast<MtObject* *>(&mpFriendList), 3u, 0u);
}

MtUI* nNetwork::Context::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) void nNetwork::Context::move() {
    DDON_STUB("nNetwork::Context::move")
    /* stub */
}

void nNetwork::Context::reset() {
    if (mpContext != nullptr) {
        delete mpContext;
        mpContext = nullptr;
    }
    ::memset(static_cast<void*>(&mInviteSessionInfo), 0, 532ul);
    mServiceError.mNative = 0;
    mServiceError.mNo = 0;
    mServiceError.mCause = 0;
    mpFriendList = nullptr;
    mStart = false;
    mFinal = false;
    mIsFriendListChange = false;
    mIsSignInChange = false;
    mInviteState = 0;
    mReqStart = 0;
    mReqFinal = 0;
    if (mState == 0) {
        return;
    }
    mState = 0;
    (::sNetwork::mpInstance)->::sNetwork::notifyServiceStateChange(mUserIndex, 0, static_cast<const MtNetError*>(nullptr));
}

__attribute__((weak)) void nNetwork::Context::bootup() {
    DDON_STUB("nNetwork::Context::bootup")
    /* stub */
}

void nNetwork::Context::shutdown() {
    if (mState == 0) {
        return;
    }
    if (mState != 5) {
        if (mpContext != nullptr) {
            mpContext->isFatal();
        }
        mState = 5;
        (::sNetwork::mpInstance)->::sNetwork::notifyServiceStateChange(mUserIndex, 5, static_cast<const MtNetError*>(nullptr));
    }
}

__attribute__((weak)) void nNetwork::Context::tryFinal() {
    DDON_STUB("nNetwork::Context::tryFinal")
    /* stub */
}

__attribute__((weak)) void nNetwork::Context::updateServiceState(s32 level, MtNetError* net_err) {
    DDON_STUB("nNetwork::Context::updateServiceState")
    /* stub */
}

__attribute__((weak)) void nNetwork::Context::onNtcDestruct() {
}

__attribute__((weak)) void nNetwork::Context::onNtcSignInChange(s32 sign_in_level, MtNetError* net_err) {
    DDON_STUB("nNetwork::Context::onNtcSignInChange")
    /* stub */
}

void nNetwork::Context::onNtcFriendListChange(MtNetFriendList* friend_list) {
    mIsFriendListChange = true;
    mpFriendList = friend_list;
}

void nNetwork::Context::onNtcInviteAccept() {
    mInviteState = 1;
}

void nNetwork::Context::onNtcInviteAcceptSucceed(MtNetSessionInfo* info) {
    mInviteState = 2;
    ::memcpy(static_cast<void*>(&mInviteSessionInfo), static_cast<const void*>(info), 520ul);
}

__attribute__((weak)) void nNetwork::Context::onNtcInviteAcceptFail(MtNetError* net_err) {
    DDON_STUB("nNetwork::Context::onNtcInviteAcceptFail")
    /* stub */
}

void nNetwork::Context::onAnsStartSucceed(u32 req_seq, s32 sign_in_level) {
    mReqStart = 0;
    mStart = true;
    updateServiceState(sign_in_level, static_cast<MtNetError*>(nullptr));
}

__attribute__((weak)) void nNetwork::Context::onAnsStartFail(u32 req_seq, MtNetError* net_err) {
    DDON_STUB("nNetwork::Context::onAnsStartFail")
    /* stub */
}

void nNetwork::Context::onAnsFinalize(u32 req_seq) {
    mFinal = false;
}

inline nNetwork::Context::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::Context::MyDTI nNetwork::Context::DTI("nNetwork::Context", &::MtObject::DTI, 632ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::Context::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::Context::MyDTI::newInstance")
    return nullptr;
}

