#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetSession.h"
#include "MtObject.h"
#include "nNetworkMember.h"
#include "nNetworkRoute.h"
#include "nNetworkUtil.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtNetSession;
struct MtNetSessionInfo;
class MtNetUniqueId;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nNetwork { class Member; }
namespace nNetwork { class Route; }
namespace nNetwork { class SearchResultListPtr; }
namespace nNetwork { class SessionDriver; }
namespace nNetwork { class SessionInfoPtr; }

// Declarations
namespace nNetwork { class SessionDatabase; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nNetwork {
    class SessionDatabase : public ::MtObject
    {
        // inferred: nNetwork::SessionDriver::onNtcDrop names nNetwork::SessionDatabase::mAttribute
        friend class nNetwork::SessionDriver;
    public:
        enum
        {
            SESSION_ONLINE = 1,
            SESSION_LOCK = 2,
            SESSION_START = 4,
            SESSION_MATCH = 8,
            SESSION_TERMINATE = 16,
        };
    public:
        class MyDTI;
        struct KeyHistory;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct KeyHistory
        {
        public:
            void init(u32 key);
            void add(u32 key);
            bool test(u32 key) const;
        public:
            u32 mKey[128];  // offset: 0x0
            u32 mHead;  // offset: 0x200
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
        SessionDatabase();
        virtual ~SessionDatabase();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        s32 getSearchResultNum() const;
        const MtNetSession::SearchResult* getSearchResult(u32 index) const;
        const MtNetSession::Ping* getPing(s32) const;
        const MtNetSessionInfo& getSessionInfo() const;
        bool isOnline() const;
        s32 getHostIndex() const;
        s32 getSelfIndex() const;
        const MtNetSession::Member& getMember(s32) const;
        MT_CTSTR getName(s32) const;
        bool isValid(s32 member_index) const;
        bool isHost(s32) const;
        bool isHost() const;
        bool isMySelf(s32 member_index) const;
        bool isNewbie(s32) const;
        bool isMute(s32 member_index) const;
        bool isRestrict(s32 member_index) const;
        u32 getMuteList() const;
        bool isTalking(s32 member_index) const;
        u32 getTalkingList() const;
        bool isGroupMember(s32 member_index, s32 group_index) const;
        u32 getGroupMemberList(u32 group_index) const;
        u32 getGroup(s32 member_index) const;
        u32 getTag(s32 member_index) const;
        u32 getId(s32 member_index) const;
        const u8* getMemberConfig(s32 member_index) const;
        u32 getRtt(s32) const;
        u32 getIqr(s32) const;
        f32 getLossRate(s32) const;
        u32 getQueueDelay(s32) const;
        u32 getBroadcastSendRate() const;
        u32 getBroadcastRecvRate() const;
        s32 getRouteIndex(s32 member_index) const;
        s32 getMemberIndex(s32 route_index) const;
        const nNetwork::Route& getRoute(s32 route_index) const;
        s32 findRoute(const MtNetUniqueId& uniq_id) const;
        s32 findRoute(u32 key) const;
        s32 findDirect(s32 peer_id) const;
        u32 getSelfKey() const;
        bool testKeyHistory(u32 key) const;
        const u8* getSelfConfig() const;
        u32 getAttr() const;
        bool isLock() const;
        bool isStart() const;
        bool isSessionMatch() const;
        bool isSessionTerminate() const;
        bool isEntry(s32 member_index) const;
        bool isEntry() const;
        bool isMatch(s32 member_index) const;
        bool isMatch() const;
        bool isTerminate(s32 member_index) const;
        bool isTerminate() const;
        void setSelfData(s32 member_index, MtNetSession::Member* member);
        void setMemberData(s32 member_index, MtNetSession::Member* member);
        void deleteMemberData(s32 member_index, MtNetSession::Member* member);
        void deleteMemberDataAll();
        void changeHostIndex(s32 member_index, MtNetSession::Member* member);
        void setSearchResult(MtNetSession::SearchResultList* result);
        void clearSearchResult();
        void setBinary(s32 session_index, MtNetSessionInfo::Binary* binary);
        void setPing(s32 session_index, MtNetSession::Ping* ping);
        void updateSessionInfo(MtNetSession* ps, bool update_binary, bool update_slot);
        void setSelfKey(u32 key);
        void setSelfConfig(const void* conf);
        void recSendBroadcast(u32 length);
        void recRecvBroadcast(u32 length);
        void updateBroadcast(u32 delta);
        void setAttr(u32);
        void setOnline(bool f);
        void setLock(bool f);
        void setStart(bool f);
        void setSessionMatch(bool f);
        void setSessionTerminate(bool f);
        void setMatch(s32 member_index, bool f);
        void setTerminate(s32 member_index, bool f);
        void setEntry(s32 member_index, bool f);
        void setMute(s32 member_index, bool f);
        void setTalking(s32 member_index, bool f);
        void setRestrict(s32, bool);
        void setGroup(s32, u32);
        void setGroupMember(s32 member_index, s32 group_index, bool f);
        void setGroupMemberList(s32 group_index, s32* list, u32 num);
        void setTag(s32 member_index, u32 tag);
        u32 incTag();
        void addKeyHistory(u32 key);
        void setMemberConfig(s32 member_index, const u8* conf);
    private:
        MtNetSession::SearchResultList mSearchResultList;  // offset: 0x8
        nNetwork::SearchResultListPtr mSearchResultListPtr;  // offset: 0x5410
        MtNetSessionInfo mSessionInfo;  // offset: 0x6e20
        nNetwork::SessionInfoPtr mSessionInfoPtr;  // offset: 0x7028
        nNetwork::Member mMemberList[16];  // offset: 0x70d8
        nNetwork::Route mRouteList[16];  // offset: 0x81d8
        s32 mHostIndex;  // offset: 0xb858
        s32 mSelfIndex;  // offset: 0xb85c
        u32 mAttribute;  // offset: 0xb860
        u32 mSelfKey;  // offset: 0xb864
        u8 mConfig[64];  // offset: 0xb868
        KeyHistory mKeyHistory;  // offset: 0xb8a8
        nNetwork::Route::Rate mSendBroadcast;  // offset: 0xbaac
        nNetwork::Route::Rate mRecvBroadcast;  // offset: 0xbb04
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork
