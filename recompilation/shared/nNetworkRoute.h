#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetBuffer.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtNetP2p.h"
#include "MtObject.h"
#include "MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
struct MtNetError;
struct MtNetP2pConnectInfo;
class MtNetUniqueId;
class MtPropertyList;
namespace nNetwork { class SessionDatabase; }

// Declarations
namespace nNetwork { class Route; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetwork {
    class Route : public ::MtObject
    {
    public:
        class MyDTI;
        struct Rate;
        struct RTT;
        struct RecvLoss;
        struct SendLoss;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct Rate
        {
        public:
            struct Record;
        public:
            struct Record
            {
            public:
                void clear();
            public:
                u32 mTotal;  // offset: 0x0
                u32 mCount;  // offset: 0x4
            };
        public:
            void clear();
            void update(u32 delta);
            void record(u32 length);
        public:
            Record mRecord[8];  // offset: 0x0
            u32 mTotalLength;  // offset: 0x40
            u32 mTotalCount;  // offset: 0x44
            s32 mWait;  // offset: 0x48
            u32 mHead;  // offset: 0x4c
            u32 mRate;  // offset: 0x50
            u32 mIval;  // offset: 0x54
            static const u32 RECORD_NUM = 8;
            static const u32 UPDATE_IVAL = 250;
        };
    public:
        struct RTT
        {
        public:
            void clear();
            void update();
            void record(u32 rtt);
        public:
            u8 mRttHistory[64];  // offset: 0x0
            u8 mRttHistogram[64];  // offset: 0x40
            u32 mRttQ1;  // offset: 0x80
            u32 mRttQ2;  // offset: 0x84
            u32 mRttQ3;  // offset: 0x88
            u32 mRtt;  // offset: 0x8c
            u32 mIqr;  // offset: 0x90
            u32 mCount;  // offset: 0x94
            static const u32 RTT_NUM = 64;
            static const u32 RTT_LEVEL = 64;
        };
    public:
        struct RecvLoss
        {
        public:
            struct Record;
        public:
            struct Record
            {
            public:
                void clear();
            public:
                u32 mStart;  // offset: 0x0
                u32 mCount;  // offset: 0x4
            };
        public:
            void clear();
            void update();
            void record(u32 seq);
        public:
            Record mRecord[8];  // offset: 0x0
            u32 mTotalCount;  // offset: 0x40
            u32 mStart;  // offset: 0x44
            u32 mLast;  // offset: 0x48
            u32 mBase;  // offset: 0x4c
            u32 mHead;  // offset: 0x50
            f32 mLoss;  // offset: 0x54
            static const u32 RECORD_NUM = 8;
        };
    public:
        struct SendLoss
        {
        public:
            void clear();
            void update();
            void record(f32 loss);
        public:
            f32 mRecord[8];  // offset: 0x0
            f32 mLoss;  // offset: 0x20
            f32 mBase;  // offset: 0x24
            u32 mHead;  // offset: 0x28
            static const u32 RECORD_NUM = 8;
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
        Route();
        virtual ~Route();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void clear();
        void init(u32 req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info);
        void update(u32 delta);
        void setMemberIndex(s32 index);
        s32 getMemberIndex() const;
        void registerPeerId(s32 peer_id);
        s32 getPeerId() const;
        void clearPeerId();
        bool isPeerEnable() const;
        u32 getReqPeer() const;
        u32 getReqSession() const;
        const MtNetUniqueId& getUniqueId() const;
        void setAbort(bool f);
        bool isAbort() const;
        u32 getFatalElapse() const;
        u32 getSendElapse() const;
        u32 getRecvElapse() const;
        u32 getSendRate() const;
        u32 getRecvRate() const;
        void recSendLoss(f32 loss);
        f32 getRecvLoss() const;
        f32 getSendLoss() const;
        f32 getBaseLoss() const;
        void recRtt(u32 rtt);
        u32 getRtt() const;
        u32 getRttQ3() const;
        u32 getIqr() const;
        u32 getQueueDelay() const;
        void recQueueDelay(u32 delay);
        u32 getRecoveryTime() const;
        void recTag(u32);
        u32 getTag() const;
        void setBandwidth(u32 width);
        u32 getBandwidth() const;
        f32 getUtilization() const;
        void setDecLevel(u32 level);
        u32 getDecLevel() const;
        void setDecWait(u32 wait);
        bool isReadyForDecrement() const;
        void setIncWait(u32 wait);
        bool isReadyForIncrement() const;
        void setUtilization(f32 util);
        void setDirectIndex(s32 index);
        s32 getDirectIndex() const;
        void setLinkstateWait(s32 wait);
        bool isReadyForLinkState() const;
        void setHealthCheckWait(s32 wait);
        bool isReadyForHealthCheck() const;
        void setSearchTime(MtNetTime::Total time);
        MtNetTime::Total getSearchTime() const;
        void setConnectTime(MtNetTime::Total time);
        MtNetTime::Total getConnectTime() const;
        void resetPeerSendElapse();
        u32 getPeerSendElapse() const;
        void resetPeerRecvElapse();
        u32 getPeerRecvElapse() const;
        void resetPeerAckElapse();
        u32 getPeerAckElapse() const;
        u32 getPeerElapse() const;
        u32 getRouteKey() const;
        void setRouteKey(u32 key);
        const u8* getInitConfig() const;
        void setInitConfig(const void* bin);
        u32 incSendSequence();
        u32 getRecvSequence() const;
        void setRecvSequence(u32 seq);
        u32 getBroadcastSequence() const;
        void setBroadcastSequence(u32 seq);
        void setPriority(u32 prio);
        u32 getPriority() const;
        s32 getSendWait() const;
        u32 getMtu() const;
        u32 getSendCount() const;
        void activate();
        bool isActive() const;
        bool isUse() const;
        u32 calcCost(u32, u32) const;
        void recSend(u32 length);
        void recRecv(u32 seq, u32 length, u32 hop);
        void ready();
        void recPeerSend(u32 length);
        void calcSendRecv(u32& send, u32& recv);
        void lock();
        void unlock();
        void setFatal(const MtNetError& err);
        bool isFatal() const;
        void getFatal(MtNetError& err) const;
        MtNetP2pConnectInfo* getConnectInfoPtr();
        u32* getReqPeerPtr();
        u32 getForwardNum() const;
        s32 getForward(u32 index) const;
        void clearForward();
        void addForward(u32 forward, u32 ival);
        void setInterval(u32 index, u32 ival);
        void addDetour(s32 route_index, u32 interval, u32 rtt, s32 ttl, const nNetwork::SessionDatabase* pdb);
        void removeDetour(s32 route_index);
        void getBestDetour(u32& cost, u32& interval, s32& route_index);
    private:
        MtNetError mFatal;  // offset: 0x8
        u32 mFatalElapse;  // offset: 0x14
        MtCriticalSection mCS;  // offset: 0x18
        MtNetUniqueId mUniqueId;  // offset: 0x20
        MtNetP2pConnectInfo mConnectInfo;  // offset: 0x98
        u32 mReqSession;  // offset: 0xb8
        u32 mReqPeer;  // offset: 0xbc
        s32 mPeerId;  // offset: 0xc0
        s32 mMemberIndex;  // offset: 0xc4
        u32 mRouteKey;  // offset: 0xc8
        u32 mPeerSendElapse;  // offset: 0xcc
        u32 mPeerRecvElapse;  // offset: 0xd0
        u32 mPeerAckElapse;  // offset: 0xd4
        s32 mLinkStateWait;  // offset: 0xd8
        s32 mHealthCheckWait;  // offset: 0xdc
        MtNetTime::Total mSearchTime;  // offset: 0xe0
        MtNetTime::Total mConnectTime;  // offset: 0xe8
        bool mPeerEnable;  // offset: 0xf0
        bool mActive;  // offset: 0xf1
        bool mReady;  // offset: 0xf2
        bool mAbort;  // offset: 0xf3
        u8 mInitConfig[64];  // offset: 0xf4
        s32 mDirectIndex;  // offset: 0x134
        u32 mRecvHop;  // offset: 0x138
        Rate mSendRate;  // offset: 0x13c
        Rate mRecvRate;  // offset: 0x194
        u32 mSendElapse;  // offset: 0x1ec
        u32 mRecvElapse;  // offset: 0x1f0
        u32 mSendSequence;  // offset: 0x1f4
        u32 mRecvSequence;  // offset: 0x1f8
        u32 mBroadcastSequence;  // offset: 0x1fc
        u32 mTag;  // offset: 0x200
        u32 mSendCount;  // offset: 0x204
        u32 mSendLastSeq;  // offset: 0x208
        u32 mRecvCount;  // offset: 0x20c
        u32 mRecvLastSeq;  // offset: 0x210
        RTT mRtt;  // offset: 0x214
        RecvLoss mRecvLoss;  // offset: 0x2ac
        SendLoss mSendLoss;  // offset: 0x304
        u32 mQueueDelay;  // offset: 0x330
        u32 mQueueDelayNext;  // offset: 0x334
        u32 mBandwidth;  // offset: 0x338
        f32 mUtilization;  // offset: 0x33c
        u32 mPriority;  // offset: 0x340
        u32 mRecoveryTime;  // offset: 0x344
        u32 mMtu;  // offset: 0x348
        s32 mIncWait;  // offset: 0x34c
        s32 mDecWait;  // offset: 0x350
        u32 mDecLevel;  // offset: 0x354
        s32 mSendWait;  // offset: 0x358
        s32 mUpdateWait;  // offset: 0x35c
        u32 mSendTotal;  // offset: 0x360
    public:
        static const u32 MAX_NUM_HOP = 16;
        static const u32 MAX_NUM_DETOUR = 4;
        static const u32 UPDATE_IVAL = 1000;
        static MyDTI DTI;
    };
}  // namespace nNetwork
