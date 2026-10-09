#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtObject.h"
#include "nNetworkQueue.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtNetUniqueId;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
namespace nNetwork { class BlockPool; }
namespace nNetwork { class Connect; }
namespace nNetwork { class PacketReader; }
namespace nNetwork { class PacketWriter; }
namespace nNetwork { class Protocol; }
namespace nNetwork { class Route; }
namespace nNetwork { class Session; }

// Declarations
namespace nNetwork { class Transport; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetwork {
    class Transport : public ::MtObject
    {
        // inferred: nNetwork::Connect::onNtcPeerReceive calls nNetwork::Transport::recvPeer
        friend class nNetwork::Connect;
    public:
        class MyDTI;
        class ForwardQueue;
        struct FrameHeader;
        struct SendEntryList;
        struct SendEntry;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class ForwardQueue : public nNetwork::BlockQueue
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
            ForwardQueue();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void init(nNetwork::BlockPool* pool);
            void clear();
        public:
            void* mBlockList[4];  // offset: 0x40
            s32 mRouteIndex;  // offset: 0x60
            u32 mRouteKey;  // offset: 0x64
            u32 mPriority;  // offset: 0x68
            u32 mInterval;  // offset: 0x6c
            MtNetTime::Total mLastSend;  // offset: 0x70
            static const u32 BLOCK_MAX = 4;
            static MyDTI DTI;
        };
    public:
        struct FrameHeader
        {
        public:
            void clear();
            u32 size() const;
            bool reserve(MtStream& stream);
            bool write(MtStream& stream);
            bool read(MtStream& stream);
            void setRoute(const nNetwork::Route& route, const nNetwork::Session& session);
            void getSrc(MtNetUniqueId& id);
            void setSrc(const MtNetUniqueId& id);
            void getDst(MtNetUniqueId& id);
            void setDst(const MtNetUniqueId& id);
            u32 getSrc() const;
            void setSrc(s32 key);
            u32 getDst() const;
            void setDst(s32 key);
            u32 getRouteKey() const;
            u32 getForwardNum() const;
            s32 getForward(u32 index) const;
            void getForwardRev(s32* forward) const;
            u32 getTTL() const;
            void setTTL(u32 ttl);
            u32 getProtocol() const;
            void setProtocol(u32 p);
            u32 getSequence() const;
            void setSequence(u32 seq);
            u32 getGameDataLength() const;
            void setGameDataLength(u32 length);
            u32 getVoiceDataLength() const;
            void setVoiceDataLength(u32 length);
            bool isAck() const;
            void setAck(bool f);
            bool isSrcUnique() const;
            bool isDstUnique() const;
        private:
            s32 mReservePos;  // offset: 0x0
            u32 mFlag;  // offset: 0x4
            u32 mGame;  // offset: 0x8
            u32 mVoice;  // offset: 0xc
            u32 mSequence;  // offset: 0x10
            u32 mDstKey;  // offset: 0x14
            u32 mDstIdSize;  // offset: 0x18
            u8 mDstIdData[64];  // offset: 0x1c
            u32 mSrcKey;  // offset: 0x5c
            u32 mSrcIdSize;  // offset: 0x60
            u8 mSrcIdData[64];  // offset: 0x64
            u32 mForwardNum;  // offset: 0xa4
            u32 mTTL;  // offset: 0xa8
            s32 mForward[16];  // offset: 0xac
        public:
            static const u32 SIZE_MIN = 8;
        private:
            static const u32 MASK_PROTOCOL = 3;
            static const u32 SRC_TYPE_UNIQUE = 8;
            static const u32 DST_TYPE_UNIQUE = 16;
            static const u32 FLAG_ACK = 32;
            static const u32 GAMEDATA_256 = 64;
            static const u32 VOICEDATA_256 = 128;
        };
    public:
        struct SendEntry
        {
        public:
            void clear();
        public:
            u32 key;  // offset: 0x0
            u32 prio;  // offset: 0x4
            s32 route;  // offset: 0x8
            s32 forward;  // offset: 0xc
        };
    public:
        struct SendEntryList
        {
        public:
            void clear();
            void add(u32 key, u32 prio, s32 route, s32 forward);
        public:
            nNetwork::Transport::SendEntry list[16];  // offset: 0x0
        };
    public:
        Transport();
        virtual ~Transport();
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
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void setup(nNetwork::Session* ps);  // vtable slot 6
        virtual void move();  // vtable slot 7
        void setProtocol(u32 protocol_index, nNetwork::Protocol* pp);
        nNetwork::Protocol* getProtocol(u32 protocol_index);
        void setBandwidthMin(u32);
        u32 getBandwidthMin() const;
        void setBandwidthMax(u32);
        u32 getBandwidthMax() const;
        void setBandwidthStart(u32);
        u32 getBandwidthStart() const;
        void setBandwidthTarget(u32);
        u32 getBandwidthTarget() const;
        void setFastTransfer(bool);
        bool isFastTransfer() const;
        void setIntervalMin(u32);
        u32 getIntervalMin() const;
        void setIntervalMax(u32);
        u32 getIntervalMax() const;
        void getForwardInfo(u32 forward, s32& route_index, u32& route_key, u32& interval) const;
    protected:
        virtual void put(const void* data_ptr, s32 data_size, s32 route_index, u32 option, u32 callback, s32 tag);  // vtable slot 8
        virtual void receive(const void* data_ptr, s32 data_size, s32 peer_id);  // vtable slot 9
        void updateRoute();
        virtual void updateBandwidth(nNetwork::Route& route) const;  // vtable slot 10
        void createRoute(s32 route_index);
        void removeRoute(s32 route_index);
        void sendPeer(s32 peer_id, const void* data_ptr, s32 data_size);
        void recvPeer(s32 peer_id, const void* data_ptr, s32 data_size);
    private:
        void version(u8* ver) const;
        void sendBroadcast();
        void sendUnicast(s32 direct_index);
        bool recvBroadcast(nNetwork::PacketReader& packet, FrameHeader& fh, s32 direct_index);
        bool recvUnicast(nNetwork::PacketReader& packet, FrameHeader& fh, s32 direct_index);
        bool recvForward(nNetwork::PacketReader& packet, FrameHeader& fh, s32 direct_index);
        bool putForward(s32 route_index, FrameHeader& fh, nNetwork::PacketReader& packet);
        bool getForward(s32 forward, nNetwork::PacketWriter& packet);
    protected:
        nNetwork::Session* mpSession;  // offset: 0x8
    private:
        nNetwork::Protocol* mpProtocol[4];  // offset: 0x10
        ForwardQueue mForwardQueue[8];  // offset: 0x30
        bool mFastTransfer;  // offset: 0x3f0
        u32 mBandwidthMin;  // offset: 0x3f4
        u32 mBandwidthMax;  // offset: 0x3f8
        u32 mBandwidthStart;  // offset: 0x3fc
        u32 mBandwidthTarget;  // offset: 0x400
        u32 mIntervalMin;  // offset: 0x404
        u32 mIntervalMax;  // offset: 0x408
        u32 mBroadcastSendSequence;  // offset: 0x40c
        MtNetTime::Total mLastTime;  // offset: 0x410
    public:
        static const u32 MAX_NUM_PROTOCOL = 4;
        static const s32 MAX_NUM_FORWARD = 8;
        static const u32 FORWARD_QUEUE_SIZE = 8;
        static MyDTI DTI;
    };
}  // namespace nNetwork
