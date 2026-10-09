#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtNetSession.h"
#include "MtObject.h"
#include "nNetworkCallback.h"
#include "nNetworkUtil.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtNetError;
struct MtNetP2pConnectInfo;
class MtNetSession;
struct MtNetSessionInfo;
class MtNetUniqueId;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nNetwork { class Connect; }
namespace nNetwork { class SearchFilterListPtr; }
namespace nNetwork { class SearchKeyListPtr; }
namespace nNetwork { class Session; }
namespace nNetwork { class SessionBinaryPtr; }
namespace nNetwork { class SessionInfoPtr; }

// Declarations
namespace nNetwork { class SessionDriver; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nNetwork {
    class SessionDriver : public ::MtObject, public MtNetSession::Listener
    {
        // inferred: nNetwork::Connect::onNtcDrop names nNetwork::Session::mDriver.mpDriver
        friend class nNetwork::Connect;
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
        SessionDriver();
        virtual ~SessionDriver();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void move();
        void setup(nNetwork::Session* parent);
        void setDriver(MtNetSession* ps);
        void removeDriver();
        s32 getState() const;
        bool tryOffline();
        bool tryCreate();
        bool trySearch();
        bool tryJoin();
        bool tryLock();
        bool tryUnlock();
        bool tryStart();
        bool tryEnd();
        bool tryFinal();
        bool tryInvite();
        bool tryAbort();
        void setSearchKeyList(const MtNetSessionInfo::SearchKeyList* list);
        const MtNetSessionInfo::SearchKeyList& getSearchKeyList() const;
        void setBinary(const MtNetSessionInfo::Binary* bin);
        const MtNetSessionInfo::Binary& getBinary() const;
        MtNetSession* getDriver();
    private:
        virtual void onNtcDestruct();  // vtable slot 6
        virtual void onNtcFinalize();  // vtable slot 7
        virtual void onNtcDrop(MtNetError* err);  // vtable slot 8
        virtual void onNtcMemberJoin(s32 index, MtNetSession::Member* member);  // vtable slot 9
        virtual void onNtcMemberLeave(s32 index, MtNetSession::Member* member);  // vtable slot 10
        virtual void onNtcHostChange(s32 index, MtNetSession::Member* member);  // vtable slot 11
        virtual void onNtcLockChange(bool is_lock);  // vtable slot 12
        virtual void onNtcGetSearchResult(MtNetSession::SearchResultList* result);  // vtable slot 13
        virtual void onNtcGetBinary(s32 index, MtNetSessionInfo::Binary* binary);  // vtable slot 14
        virtual void onNtcGetPing(s32 index, MtNetSession::Ping* ping);  // vtable slot 15
        virtual void onReqP2pConnect(u32* req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info);  // vtable slot 16
        virtual void onReqP2pConnect(u32* req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info, s32* connect_id);  // vtable slot 17
        virtual void onNtcP2pSend(s32 route_index, const void* data_ptr, s32 data_size);  // vtable slot 18
        virtual void onNtcP2pRemove(s32 route_index);  // vtable slot 19
        virtual void onAnsCreateSucceed(u32 req_seq, s32 index, MtNetSession::Member* member, MtNetSessionInfo* info);  // vtable slot 20
        virtual void onAnsCreateFail(u32 req_seq, MtNetError* err);  // vtable slot 21
        virtual void onAnsSearchSucceed(u32 req_seq);  // vtable slot 22
        virtual void onAnsSearchFail(u32 req_seq, MtNetError* err);  // vtable slot 23
        virtual void onAnsJoinSucceed(u32 req_seq, s32 index, MtNetSession::Member* member, MtNetSessionInfo* info);  // vtable slot 24
        virtual void onAnsJoinFail(u32 req_seq, MtNetError* err);  // vtable slot 25
        virtual void onAnsFinalize(u32 req_seq);  // vtable slot 26
        virtual void onAnsLockSucceed(u32 req_seq, bool is_lock);  // vtable slot 27
        virtual void onAnsLockFail(u32 req_seq, MtNetError* err);  // vtable slot 28
        virtual void onAnsInvite(u32 req_seq);  // vtable slot 29
        virtual void onAnsStart(u32 req_seq);  // vtable slot 30
        virtual void onAnsEnd(u32 req_seq);  // vtable slot 31
        void abortRequest(u32 req_seq);
        void receiveCore(s32 route_index, const void* pbuf, u32 length);
    private:
        s32 mState;  // offset: 0x10
        bool mDrop;  // offset: 0x14
        bool mFinal;  // offset: 0x15
        bool mCanHost;  // offset: 0x16
        bool mCanHostOld;  // offset: 0x17
        nNetwork::Session* mpParent;  // offset: 0x18
        MtNetSession* mpDriver;  // offset: 0x20
        u32 mCoreSeq;  // offset: 0x28
        u32 mSelfSeq;  // offset: 0x2c
        MtNetSessionInfo::SearchKeyList mKeyList;  // offset: 0x30
        nNetwork::SearchKeyListPtr mKeyListPtr;  // offset: 0x80
        MtNetSessionInfo::Binary mBinary;  // offset: 0x110
        nNetwork::SessionBinaryPtr mBinaryPtr;  // offset: 0x218
        s32 mJoinNumMax;  // offset: 0x228
        s32 mPrivateNumMax;  // offset: 0x22c
        s32 mSearchNumMax;  // offset: 0x230
        s32 mSearchOption;  // offset: 0x234
        MtNetSession::SearchKeyFilterList mKeyFilterList;  // offset: 0x238
        nNetwork::SearchFilterListPtr mKeyFilterListPtr;  // offset: 0x2d0
        MtNetSessionInfo mJoinInfo;  // offset: 0x3e0
        nNetwork::SessionInfoPtr mJoinInfoPtr;  // offset: 0x5e8
        MtNetTime::Total mFinalTime;  // offset: 0x698
        s32 mFinalCount;  // offset: 0x6a0
        nNetwork::Receiver<nNetwork::SessionDriver> mReceiver;  // offset: 0x6a8
    public:
        static MyDTI DTI;
    private:
        static const u32 FINAL_MSEC = 200;
        static const u32 FINAL_FRAME = 10;
    };
}  // namespace nNetwork
