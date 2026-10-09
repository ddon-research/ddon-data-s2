#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtNetRequest.h"

// Forward declarations
struct MtNetAddress;
class MtNetContext;
struct MtNetError;
struct MtNetPort;
class MtNetRequest;
class MtNetRequestController;

// Declarations
class MtNetP2p;
struct MtNetP2pConnectInfo;

// Type aliases from DWARF
using __uint16_t = unsigned short;
using uint16_t = __uint16_t;
using SceNpMatching2ContextId = uint16_t;
using __uint64_t = long unsigned int;
using uint64_t = __uint64_t;
using SceNpMatching2RoomId = uint64_t;
using SceNpMatching2RoomMemberId = uint16_t;
using s32 = int;
using u32 = unsigned int;

class MtNetP2p : public MtNetObject, public MtNetRequestController::Listener
{
public:
    enum
    {
        PHASE_AUTO_FINALIZE_NONE = 0,
        PHASE_AUTO_FINALIZE_DROP = 1,
        PHASE_AUTO_FINALIZE_WAIT = 2,
        PHASE_AUTO_FINALIZE_END = 3,
    };
public:
    class Listener;
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual void onNtcDestruct();  // vtable slot 2
        virtual void onNtcFinalize();  // vtable slot 3
        virtual void onNtcDrop(MtNetError* net_err);  // vtable slot 4
        virtual void onNtcPeerDrop(s32 peer_id, MtNetError* net_err);  // vtable slot 5
        virtual void onNtcPeerReceive(s32 peer_id, const void* data_ptr, s32 data_size);  // vtable slot 6
        virtual void onAnsPeerConnectSucceed(u32 req_seq, s32 peer_id);  // vtable slot 7
        virtual void onAnsPeerConnectFail(u32 req_seq, MtNetError* net_err);  // vtable slot 8
    };
public:
    MtNetP2p(MtNetContext* context);
    virtual ~MtNetP2p();
    void addListener(Listener* listener);
    void removeListener(Listener* listener);
    virtual void move() = 0;  // vtable slot 11
    virtual bool isPeerEnable(s32) = 0;  // vtable slot 12
    virtual s32 sendPeer(s32, const void*, s32) = 0;  // vtable slot 13
    virtual void disconnectPeer(s32) = 0;  // vtable slot 14
    void reqPeerConnect(u32* req_seq, const MtNetP2pConnectInfo* info);
    void abortRequest(u32 req_seq);
protected:
    void beginDestruct();
    void beginMove();
    void endMove();
    void cbNtcPeerDrop(s32 peer_id, MtNetError* net_err);
    void cbNtcPeerReceive(s32 peer_id, const void* data_ptr, s32 data_size);
    void cbAnsPeerConnectSucceed(MtNetRequest* req, s32 peer_id);
    void cbAnsPeerConnectFail(MtNetRequest* req, MtNetError* net_err);
    virtual s32 movePeerConnect(MtNetRequest*) = 0;  // vtable slot 15
private:
    virtual bool canMoveRequest(MtNetRequest* req);  // vtable slot 16
    virtual s32 startRequest(MtNetRequest* req);  // vtable slot 17
    virtual s32 moveRequest(MtNetRequest* req);  // vtable slot 18
    virtual void endRequest(MtNetRequest* req);  // vtable slot 19
    virtual void startFailRequest(MtNetRequest* req);  // vtable slot 20
    s32 startEmpty(MtNetRequest* req);
    void endEmpty(MtNetRequest* req);
protected:
    MtNetContext* mpContext;  // offset: 0x30
    MtNetRequestController mRequestController;  // offset: 0x38
    bool mIsDestructor;  // offset: 0xb0
private:
    Listener* mpListener;  // offset: 0xb8
    s32 mPhaseAutoFinalize;  // offset: 0xc0
public:
    static const s32 MAX_NUM_PEER = 16;
    static const s32 PEER_BROADCAST = -1;
protected:
    static const s32 REQUEST_ID_PEER_CONNECT = 513;
};

struct MtNetP2pConnectInfo
{
public:
    MtNetAddress mAddress;  // offset: 0x0
    MtNetPort mPortP2p;  // offset: 0x6
    SceNpMatching2ContextId mNpMatchingCtxId;  // offset: 0x8
    SceNpMatching2RoomId mNpMatchingRoomId;  // offset: 0x10
    SceNpMatching2RoomMemberId mNpMatchingRoomMemberId;  // offset: 0x18
    u32 mMtNetSessionNonce;  // offset: 0x1c
};
