// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkConnect.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetBuffer.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtNetP2p.h"
#include "../MT/MtNetSession.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStream.h"
#include "cRemoteCall.h"
#include "nNetworkCallback.h"
#include "nNetworkDatabase.h"
#include "nNetworkRemoteCalls.h"
#include "nNetworkRoute.h"
#include "nNetworkSession.h"
#include "nNetworkTransport.h"
#include "sNetwork.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nNetwork::Connect::getDTI() const {
    return nNetwork::Connect::DTI;
}

void* nNetwork::Connect::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::Connect::DTI)->memAlloc(sz, align, ::nNetwork::Connect::DTI.mID);
}

nNetwork::Connect::Connect() {
    DDON_STUB("nNetwork::Connect::Connect")
    /* stub */
}

nNetwork::Connect::~Connect() {
}

void nNetwork::Connect::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mpP2p", reinterpret_cast<MtObject* *>(&mpP2p), 6u, 0u);
}

MtUI* nNetwork::Connect::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nNetwork::Connect::setup(nNetwork::Session* ps) {
    mpSession = ps;
    mReceiver.mpObject = static_cast<MtObject*>(this);
    mReceiver.mpCallback = &::nNetwork::Connect::recvMessage;
    ps->mCallback.set(2, static_cast<nNetwork::ReceiverBase*>(&mReceiver), false, true);
}

__attribute__((weak)) void nNetwork::Connect::move() {
    DDON_STUB("nNetwork::Connect::move")
    /* stub */
}

void nNetwork::Connect::sendPeer(s32 peer_id, const void* data_ptr, s32 data_size) {
    mpP2p->sendPeer(peer_id, data_ptr, data_size);
}

void nNetwork::Connect::removeDriver() {
    if (mpP2p == nullptr) {
        return;
    }
    delete mpP2p;
    mpP2p = nullptr;
}

__attribute__((weak)) void nNetwork::Connect::createRoute(u32 req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info, s32* connect_id) {
    DDON_STUB("nNetwork::Connect::createRoute")
    /* stub */
}

__attribute__((weak)) void nNetwork::Connect::removeRoute(s32 route_index, MtNetError* net_err) {
    DDON_STUB("nNetwork::Connect::removeRoute")
    /* stub */
}

void nNetwork::Connect::removeRouteAll() {
    removeRoute(0, static_cast<MtNetError*>(nullptr));
    removeRoute(1, static_cast<MtNetError*>(nullptr));
    removeRoute(2, static_cast<MtNetError*>(nullptr));
    removeRoute(3, static_cast<MtNetError*>(nullptr));
    removeRoute(4, static_cast<MtNetError*>(nullptr));
    removeRoute(5, static_cast<MtNetError*>(nullptr));
    removeRoute(6, static_cast<MtNetError*>(nullptr));
    removeRoute(7, static_cast<MtNetError*>(nullptr));
    removeRoute(8, static_cast<MtNetError*>(nullptr));
    removeRoute(9, static_cast<MtNetError*>(nullptr));
    removeRoute(10, static_cast<MtNetError*>(nullptr));
    removeRoute(11, static_cast<MtNetError*>(nullptr));
    removeRoute(12, static_cast<MtNetError*>(nullptr));
    removeRoute(13, static_cast<MtNetError*>(nullptr));
    removeRoute(14, static_cast<MtNetError*>(nullptr));
    removeRoute(15, static_cast<MtNetError*>(nullptr));
}

void nNetwork::Connect::setForward(s32 route_index, s32 forward_index, u32 ival, const s32* forward, u32 num) {
    if (mNeedDetour) {
        if (num <= 15u) {
            mpSession->mpDatabase->mRouteList[route_index].mDirectIndex = mpSession->mpDatabase->mRouteList[forward_index].mDirectIndex;
        }
    }
}

__attribute__((weak)) bool nNetwork::Connect::tryFinal() {
    DDON_STUB("nNetwork::Connect::tryFinal")
    return {};
}

void nNetwork::Connect::sendMessage(s32 index, cRemoteCall& call) {
    u8 buffer[1024];
    MtMemoryStream stream(static_cast<void*>(buffer), 1024u, 2u);
    ::cRemoteCall::writeOut(stream, call);
    nNetwork::Session* t2 = mpSession;
    u8* t3 = stream.mBuffer;
    u32 t4 = stream.::MtMemoryStream::getPosition();
    t2->put(static_cast<const void*>(t3), static_cast<s32>(t4), index, 0x30030u, 2u);
}

void nNetwork::Connect::recvMessage(s32 index, const void* data_ptr, u32 data_size) {
    MtMemoryStream stream(const_cast<void*>(data_ptr), data_size, 1u);
    cRemoteCall* prpc = ::cRemoteCall::newInstance(stream);
    if (prpc == nullptr) {
        return;
    }
    process(index, prpc);
    delete prpc;
}

__attribute__((weak)) void nNetwork::Connect::onNtcDestruct() {
}

__attribute__((weak)) void nNetwork::Connect::onNtcFinalize() {
}

void nNetwork::Connect::onNtcDrop(MtNetError* net_err) {
    if (mpSession->mDriver.mpDriver == nullptr) {
        return;
    }
    mpSession->mDriver.mpDriver->onNtcDrop(net_err);
}

__attribute__((weak)) void nNetwork::Connect::onNtcPeerDrop(s32 peer_id, MtNetError* net_err) {
    DDON_STUB("nNetwork::Connect::onNtcPeerDrop")
    /* stub */
}

void nNetwork::Connect::onNtcPeerReceive(s32 peer_id, const void* data_ptr, s32 data_size) {
    mpSession->mpTransport->recvPeer(peer_id, data_ptr, data_size);
}

__attribute__((weak)) void nNetwork::Connect::onAnsPeerConnectSucceed(u32 req_seq, s32 peer_id) {
    DDON_STUB("nNetwork::Connect::onAnsPeerConnectSucceed")
    /* stub */
}

__attribute__((weak)) void nNetwork::Connect::onAnsPeerConnectFail(u32 req_seq, MtNetError* net_err) {
    DDON_STUB("nNetwork::Connect::onAnsPeerConnectFail")
    /* stub */
}

__attribute__((weak)) void nNetwork::Connect::process(s32 src, cRemoteCall* prpc) {
    DDON_STUB("nNetwork::Connect::process")
    /* stub */
}

void nNetwork::Connect::procLinkState(nNetwork::RpcNetSystem_LinkState& call, s32 route_index) {
    if (!mNeedDetour) {
        return;
    }
    const nNetwork::SessionDatabase* pdb = mpSession->mpDatabase;
    if (pdb->mRouteList[route_index].mMemberIndex > -1) {
        pdb->isValid(0);
        pdb->isValid(1);
        pdb->isValid(2);
        pdb->isValid(3);
        pdb->isValid(4);
        pdb->isValid(5);
        pdb->isValid(6);
        pdb->isValid(7);
        pdb->isValid(8);
        pdb->isValid(9);
        pdb->isValid(10);
        pdb->isValid(11);
        pdb->isValid(12);
        pdb->isValid(13);
        pdb->isValid(14);
        pdb->isValid(15);
    }
}

__attribute__((weak)) void nNetwork::Connect::procReqDetour(nNetwork::RpcNetSystem_ReqDetour& call, s32 route_index) {
    DDON_STUB("nNetwork::Connect::procReqDetour")
    /* stub */
}

__attribute__((weak)) void nNetwork::Connect::procAnsDetour(nNetwork::RpcNetSystem_AnsDetour& call, s32 route_index) {
    DDON_STUB("nNetwork::Connect::procAnsDetour")
    /* stub */
}

__attribute__((weak)) void nNetwork::Connect::procRouteKey(nNetwork::RpcNetSystem_RouteKey& call, s32 route_index) {
    DDON_STUB("nNetwork::Connect::procRouteKey")
    /* stub */
}

__attribute__((weak)) void nNetwork::Connect::procConfig(nNetwork::RpcNetSystem_Config& call, s32 route_index) {
    DDON_STUB("nNetwork::Connect::procConfig")
    /* stub */
}

inline nNetwork::Connect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::Connect::MyDTI nNetwork::Connect::DTI("nNetwork::Connect", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::Connect::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::Connect::MyDTI::newInstance")
    return nullptr;
}

