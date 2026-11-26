// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkRoute.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetBuffer.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtNetObject.h"
#include "../MT/MtNetP2p.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nNetwork::Route::getDTI() const {
    return nNetwork::Route::DTI;
}

nNetwork::Route::Route() {
    DDON_STUB("nNetwork::Route::Route")
    /* stub */
}

nNetwork::Route::~Route() {
    DDON_STUB("nNetwork::Route::~Route")
    /* stub */
}

void nNetwork::Route::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mPeerId", &mPeerId, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mMemberIndex", &mMemberIndex, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSendSequence", &mSendSequence, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSendElapse", &mSendElapse, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SendInterval", &mSendRate.mIval, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SendRate", &mSendRate.mRate, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mRecvSequence", &mRecvSequence, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mRecvElapse", &mRecvElapse, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "RecvInterval", &mRecvRate.mIval, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "RecvRate", &mRecvRate.mRate, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "RttQ3", &mRtt.mRttQ3, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Rtt", &mRtt.mRtt, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Iqr", &mRtt.mIqr, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "RecvLoss", &mRecvLoss.mLoss, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "SendLoss", &mSendLoss.mLoss, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "BaseLoss", &mSendLoss.mBase, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mQueueDelay", &mQueueDelay, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mBandwidth", &mBandwidth, 0u, 0u);
}

__attribute__((weak)) void nNetwork::Route::clear() {
    DDON_STUB("nNetwork::Route::clear")
    /* stub */
}

__attribute__((weak)) void nNetwork::Route::init(u32 req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info) {
    DDON_STUB("nNetwork::Route::init")
    /* stub */
}

__attribute__((weak)) void nNetwork::Route::update(u32 delta) {
    DDON_STUB("nNetwork::Route::update")
    /* stub */
}

void nNetwork::Route::registerPeerId(s32 peer_id) {
    mPeerId = peer_id;
    mReqPeer = 0;
    mPeerEnable = true;
    mAbort = false;
    mPeerRecvElapse = 0;
}

void nNetwork::Route::clearPeerId() {
    mPeerId = -1;
    mReqPeer = 0;
    mPeerEnable = false;
    mAbort = false;
}

void nNetwork::Route::recQueueDelay(u32 delay) {
    if (mQueueDelayNext < delay) {
        mQueueDelayNext = delay;
    }
}

void nNetwork::Route::activate() {
    mActive = true;
}

void nNetwork::Route::recSend(u32 length) {
    mSendRate.mTotalLength = length + mSendRate.mTotalLength;
    mSendRate.mTotalCount = mSendRate.mTotalCount + 1u;
    u32 t0 = mSendRate.mHead;
    mSendRate.mRecord[t0].mTotal = length + mSendRate.mRecord[t0].mTotal;
    mSendRate.mRecord[t0].mCount = mSendRate.mRecord[t0].mCount + 1u;
    mSendElapse = 0;
    mPriority = length + mPriority;
    mReady = false;
}

__attribute__((weak)) void nNetwork::Route::recRecv(u32 seq, u32 length, u32 hop) {
    DDON_STUB("nNetwork::Route::recRecv")
    /* stub */
}

void nNetwork::Route::ready() {
    if (mReady) {
        return;
    }
    mReady = true;
    if (mRecoveryTime != 0) {
        mRecoveryTime = (mSendElapse + (mRecoveryTime * 15u)) >> 4;
    } else {
        mRecoveryTime = mSendElapse;
    }
}

__attribute__((weak)) void nNetwork::Route::recPeerSend(u32 length) {
    DDON_STUB("nNetwork::Route::recPeerSend")
    /* stub */
}

__attribute__((weak)) void nNetwork::Route::setFatal(const MtNetError& err) {
    DDON_STUB("nNetwork::Route::setFatal")
    /* stub */
}

inline nNetwork::Route::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::Route::MyDTI nNetwork::Route::DTI("nNetwork::Route", &::MtObject::DTI, 872ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::Route::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::Route::MyDTI::newInstance")
    return nullptr;
}

