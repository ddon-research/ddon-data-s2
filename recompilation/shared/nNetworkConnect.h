#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetP2p.h"
#include "MtObject.h"
#include "nNetworkCallback.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtNetError;
class MtNetP2p;
struct MtNetP2pConnectInfo;
class MtNetUniqueId;
class MtProperty;
class MtPropertyList;
class MtUI;
class cRemoteCall;
namespace nNetwork { class RpcNetSystem_AnsDetour; }
namespace nNetwork { class RpcNetSystem_Config; }
namespace nNetwork { class RpcNetSystem_HealthCheck; }
namespace nNetwork { class RpcNetSystem_LinkState; }
namespace nNetwork { class RpcNetSystem_ReqDetour; }
namespace nNetwork { class RpcNetSystem_RouteKey; }
namespace nNetwork { class RpcNetSystem_RouteKeyAck; }
namespace nNetwork { class RpcNetSystem_TryConnect; }
namespace nNetwork { class Session; }

// Declarations
namespace nNetwork { class Connect; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nNetwork {
    class Connect : public ::MtObject, public MtNetP2p::Listener
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        Connect();
        virtual ~Connect();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void setup(nNetwork::Session* ps);  // vtable slot 6
        virtual void move();  // vtable slot 7
        void sendPeer(s32 peer_id, const void* data_ptr, s32 data_size);
        void setDriver(MtNetP2p* pp2p);
        void removeDriver();
        void startP2pCheck();
        void startDetour();
        void createRoute(u32 req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info, s32* connect_id);
        void removeRoute(s32 route_index, MtNetError* net_err);
        void removeRouteAll();
        void activate(s32 route_index);
        void setForward(s32 route_index, s32 forward_index, u32 ival, const s32* forward, u32 num);
        bool tryFinal();
        bool tryAbort(u32 req_seq);
        void broadcastConfig(const u8* conf);
    protected:
        virtual void sendMessage(s32 index, cRemoteCall& call);  // vtable slot 8
        virtual void recvMessage(s32 index, const void* data_ptr, u32 data_size);  // vtable slot 9
    private:
        virtual void onNtcDestruct();  // vtable slot 10
        virtual void onNtcFinalize();  // vtable slot 11
        virtual void onNtcDrop(MtNetError* net_err);  // vtable slot 12
        virtual void onNtcPeerDrop(s32 peer_id, MtNetError* net_err);  // vtable slot 13
        virtual void onNtcPeerReceive(s32 peer_id, const void* data_ptr, s32 data_size);  // vtable slot 14
        virtual void onAnsPeerConnectSucceed(u32 req_seq, s32 peer_id);  // vtable slot 15
        virtual void onAnsPeerConnectFail(u32 req_seq, MtNetError* net_err);  // vtable slot 16
        void process(s32 src, cRemoteCall* prpc);
        void procLinkState(nNetwork::RpcNetSystem_LinkState& call, s32 route_index);
        void procReqDetour(nNetwork::RpcNetSystem_ReqDetour& call, s32 route_index);
        void procAnsDetour(nNetwork::RpcNetSystem_AnsDetour& call, s32 route_index);
        void procRouteKey(nNetwork::RpcNetSystem_RouteKey& call, s32 route_index);
        void procRouteKeyAck(nNetwork::RpcNetSystem_RouteKeyAck& call, s32 route_index);
        void procTryConnect(nNetwork::RpcNetSystem_TryConnect& call, s32 route_index);
        void procHealthCheck(nNetwork::RpcNetSystem_HealthCheck& call, s32 route_index);
        void procConfig(nNetwork::RpcNetSystem_Config& call, s32 route_index);
    protected:
        nNetwork::Session* mpSession;  // offset: 0x10
        MtNetP2p* mpP2p;  // offset: 0x18
        s32 mReqNum;  // offset: 0x20
    private:
        bool mNeedP2pCheck;  // offset: 0x24
        bool mNeedDetour;  // offset: 0x25
        nNetwork::Receiver<nNetwork::Connect> mReceiver;  // offset: 0x28
    public:
        static MyDTI DTI;
        static const u32 TIMEOUT_BEACON = 1000;
        static const u32 TIMEOUT_LINKSTATE = 3000;
        static const u32 TIMEOUT_SEARCH = 60000;
        static const u32 TIMEOUT_RECONNECT = 60000;
        static const u32 TIMEOUT_ACTIVATE = 60000;
        static const u32 BAD_THRESHOLD_QD = 8000;
        static const u32 BAD_THRESHOLD_NORECV = 4000;
    };
}  // namespace nNetwork
