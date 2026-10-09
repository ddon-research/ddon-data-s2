#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetBuffer.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtNetRequest.h"
#include "np_common.h"

// Forward declarations
struct MtNetAddress;
class MtNetContext;
struct MtNetError;
struct MtNetP2pConnectInfo;
class MtNetRequest;
class MtNetRequestController;
class MtNetUniqueId;
struct SceNpInvitationId;
struct SceNpSessionId;

// Declarations
class MtNetSession;
struct MtNetSessionInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_STR = MT_CHAR*;
using __uint64_t = long unsigned int;
using uint64_t = __uint64_t;
using SceNpMatching2LobbyId = uint64_t;
using SceNpMatching2RoomId = uint64_t;
using __uint16_t = unsigned short;
using uint16_t = __uint16_t;
using SceNpMatching2ServerId = uint16_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpMatching2WorldId = uint32_t;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

struct MtNetSessionInfo
{
public:
    enum
    {
        SEARCH_KEY_TYPE_NONE = 0,
        SEARCH_KEY_TYPE_INT32 = 1,
    };
public:
    struct SearchKeyList;
    struct SearchKey;
    struct Binary;
    struct SlotNum;
    struct General;
public:
    struct SearchKey
    {
    public:
        s32 mType;  // offset: 0x0
        union
        {
        public:
            u32 mInt32;  // offset: 0x0
        };  // offset: 0x4
    };
public:
    struct Binary
    {
    public:
        u8 mBuffer[256];  // offset: 0x0
        s32 mDataLength;  // offset: 0x100
    };
public:
    struct SlotNum
    {
    public:
        s32 mTotalUse;  // offset: 0x0
        s32 mTotalMax;  // offset: 0x4
        s32 mPrivateUse;  // offset: 0x8
        s32 mPrivateMax;  // offset: 0xc
        s32 mPublicUse;  // offset: 0x10
        s32 mPublicMax;  // offset: 0x14
    };
public:
    struct General
    {
    public:
        u32 mNonce;  // offset: 0x0
        MtNetAddress mAddress;  // offset: 0x4
    };
public:
    struct SearchKeyList
    {
    public:
        u32 mAttribute;  // offset: 0x0
        u32 mGameType;  // offset: 0x4
        u32 mGameMode;  // offset: 0x8
        s32 mNum;  // offset: 0xc
        MtNetSessionInfo::SearchKey mSearchKey[8];  // offset: 0x10
    };
public:
    SearchKeyList mSearchKeyList;  // offset: 0x0
    Binary mBinary;  // offset: 0x50
    SlotNum mSlotNum;  // offset: 0x154
    General mGeneral;  // offset: 0x16c
    SceNpMatching2ServerId mNpServerId;  // offset: 0x178
    SceNpMatching2WorldId mNpWorldId;  // offset: 0x17c
    SceNpMatching2LobbyId mNpLobbyId;  // offset: 0x180
    SceNpMatching2RoomId mNpRoomId;  // offset: 0x188
    SceNpSessionId mNpSessionId;  // offset: 0x190
    SceNpInvitationId mNpInvitationId;  // offset: 0x1c0
    u16 mP2pPort;  // offset: 0x200
    bool mIsByWeb;  // offset: 0x202
    bool mIsPrivate;  // offset: 0x203
    static const s32 MAX_NUM_SEARCH_KEY = 8;
    static const s32 MAX_SIZE_BUF_BINARY = 256;
};

class MtNetSession : public MtNetObject, public MtNetRequestController::Listener
{
public:
    enum
    {
        PHASE_AUTO_FINALIZE_NONE = 0,
        PHASE_AUTO_FINALIZE_DROP = 1,
        PHASE_AUTO_FINALIZE_WAIT = 2,
        PHASE_AUTO_FINALIZE_END = 3,
    };
    enum
    {
        SEARCH_OPTION_NONE = 0,
        SEARCH_OPTION_GET_BINARY = 1,
        SEARCH_OPTION_GET_PING = 2,
    };
    enum
    {
        FILTER_ATTR_NONE = 0,
        FILTER_ATTR_WAN = 1,
        FILTER_ATTR_LAN = 2,
        FILTER_ATTR_VACANT = 4,
    };
public:
    class Listener;
    struct Member;
    struct SearchResultList;
    struct SearchResult;
    struct Ping;
    struct MemberList;
    struct SearchKeyFilterList;
    struct SearchKeyFilter;
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual void onNtcDestruct();  // vtable slot 2
        virtual void onNtcFinalize();  // vtable slot 3
        virtual void onNtcDrop(MtNetError* net_err);  // vtable slot 4
        virtual void onNtcMemberJoin(s32 index, MtNetSession::Member* member);  // vtable slot 5
        virtual void onNtcMemberLeave(s32 index, MtNetSession::Member* member);  // vtable slot 6
        virtual void onNtcHostChange(s32 index, MtNetSession::Member* member);  // vtable slot 7
        virtual void onNtcLockChange(bool is_lock);  // vtable slot 8
        virtual void onNtcGetSearchResult(MtNetSession::SearchResultList* result);  // vtable slot 9
        virtual void onNtcGetBinary(s32 search_index, MtNetSessionInfo::Binary* binary);  // vtable slot 10
        virtual void onNtcGetPing(s32 search_index, MtNetSession::Ping* ping);  // vtable slot 11
        virtual void onReqP2pConnect(u32* req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info);  // vtable slot 12
        virtual void onReqP2pConnect(u32* req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info, s32* connect_id);  // vtable slot 13
        virtual void onNtcP2pSend(s32 connect_id, const void* data_ptr, s32 data_size);  // vtable slot 14
        virtual void onNtcP2pRemove(s32 connect_id);  // vtable slot 15
        virtual void onAnsCreateSucceed(u32 req_seq, s32 index, MtNetSession::Member* member, MtNetSessionInfo* info);  // vtable slot 16
        virtual void onAnsCreateFail(u32 req_seq, MtNetError* net_err);  // vtable slot 17
        virtual void onAnsSearchSucceed(u32 req_seq);  // vtable slot 18
        virtual void onAnsSearchFail(u32 req_seq, MtNetError* net_err);  // vtable slot 19
        virtual void onAnsJoinSucceed(u32 req_seq, s32 index, MtNetSession::Member* member, MtNetSessionInfo* info);  // vtable slot 20
        virtual void onAnsJoinFail(u32 req_seq, MtNetError* net_err);  // vtable slot 21
        virtual void onAnsFinalize(u32 req_seq);  // vtable slot 22
        virtual void onAnsLockSucceed(u32 req_seq, bool is_lock);  // vtable slot 23
        virtual void onAnsLockFail(u32 req_seq, MtNetError* net_err);  // vtable slot 24
        virtual void onAnsInvite(u32 req_seq);  // vtable slot 25
        virtual void onAnsStart(u32 req_seq);  // vtable slot 26
        virtual void onAnsEnd(u32 req_seq);  // vtable slot 27
    };
public:
    struct Member
    {
    public:
        bool mIsValid;  // offset: 0x0
        MtNetUniqueId mUniqueId;  // offset: 0x8
        MT_CHAR mName[32];  // offset: 0x80
        bool mIsOmittedName;  // offset: 0xa0
        bool mIsHost;  // offset: 0xa1
        bool mIsPrivate;  // offset: 0xa2
    };
public:
    struct SearchResult
    {
    public:
        MtNetSessionInfo mSessionInfo;  // offset: 0x0
        MT_CHAR mName[32];  // offset: 0x208
        MtNetUniqueId mUniqueId;  // offset: 0x228
    };
public:
    struct Ping
    {
    public:
        MtNetTime::Total mRtt;  // offset: 0x0
    };
public:
    struct MemberList
    {
    public:
        s32 mValidNum;  // offset: 0x0
        MtNetSession::Member mMember[16];  // offset: 0x8
    };
public:
    struct SearchKeyFilter
    {
    public:
        s32 mTarget;  // offset: 0x0
        s32 mOperator;  // offset: 0x4
        MtNetSessionInfo::SearchKey mSearchKey;  // offset: 0x8
    };
public:
    struct SearchResultList
    {
    public:
        s32 mNum;  // offset: 0x0
        MtNetSession::SearchResult mResult[32];  // offset: 0x8
    };
public:
    struct SearchKeyFilterList
    {
    public:
        u32 mProcedureIndex;  // offset: 0x0
        u32 mAttribute;  // offset: 0x4
        u32 mGameType;  // offset: 0x8
        u32 mGameMode;  // offset: 0xc
        s32 mNumUsers;  // offset: 0x10
        s32 mNum;  // offset: 0x14
        MtNetSession::SearchKeyFilter mFilter[8];  // offset: 0x18
    };
public:
    static void clearMember(Member* member);
    static void copyMember(Member* dst, const Member* src);
    static void clearSearchResult(SearchResult* result);
    static void clearSearchResultList(SearchResultList* result_list);
    MtNetSession(MtNetContext* context);
    virtual ~MtNetSession();
    void addListener(Listener* listener);
    void removeListener(Listener* listener);
    virtual void move() = 0;  // vtable slot 11
    virtual bool equals(const MtNetSessionInfo*, const MtNetSessionInfo*) = 0;  // vtable slot 12
    virtual bool isJoin() = 0;  // vtable slot 13
    virtual void setSearchKey(const MtNetSessionInfo::SearchKeyList*) = 0;  // vtable slot 14
    virtual void setBinary(const MtNetSessionInfo::Binary*) = 0;  // vtable slot 15
    virtual void getSearchResult(SearchResultList*) = 0;  // vtable slot 16
    virtual void getInfo(MtNetSessionInfo*) = 0;  // vtable slot 17
    virtual void getMemberList(MemberList*) = 0;  // vtable slot 18
    virtual void getSearchKeyList(MtNetSessionInfo::SearchKeyList*) = 0;  // vtable slot 19
    virtual void getBinary(MtNetSessionInfo::Binary*) = 0;  // vtable slot 20
    virtual void getName(MT_STR, s32) = 0;  // vtable slot 21
    virtual bool isLock() = 0;  // vtable slot 22
    virtual void canHost(bool) = 0;  // vtable slot 23
    void reqCreate(u32* req_seq, const MtNetSessionInfo::SearchKeyList* search_key_list, const MtNetSessionInfo::Binary* binary, s32 total_slot_num, s32 private_slot_num);
    void reqSearch(u32* req_seq, const SearchKeyFilterList* filter_list, s32 search_max, u32 opt_flag);
    void reqJoin(u32* req_seq, MtNetSessionInfo* info);
    void reqFinalize(u32* req_seq);
    void reqLock(u32* req_seq, bool lock_state);
    void reqInvite(u32* req_seq);
    void reqStart(u32* req_seq);
    void reqEnd(u32* req_seq);
    void abortRequest(u32 req_seq);
    virtual void onAnsP2pConnectSucceed(u32, s32) = 0;  // vtable slot 24
    virtual void onAnsP2pConnectFail(u32) = 0;  // vtable slot 25
    virtual void onNtcP2pReceive(s32, const void*, s32) = 0;  // vtable slot 26
    virtual void onNtcP2pDrop(s32, MtNetError*) = 0;  // vtable slot 27
    virtual void onNtcDrop(MtNetError*) = 0;  // vtable slot 28
protected:
    static bool isMatchSession(const MtNetSessionInfo::SearchKeyList* pSearchKeyList, const SearchKeyFilterList* pSearchKeyFilterList);
    static u32 getNonce();
    void beginDestruct();
    void beginMove();
    void endMove();
    void cbNtcMemberJoin(s32 index, Member* member);
    void cbNtcMemberLeave(s32 index, Member* member);
    void cbNtcHostChange(s32 index, Member* member);
    void cbNtcLockChange(bool is_lock);
    void cbNtcGetSearchResult(SearchResultList* result);
    void cbNtcGetBinary(s32 search_index, MtNetSessionInfo::Binary* binary);
    void cbNtcGetPing(s32 search_index, Ping* ping);
    void cbReqP2pConnect(u32* req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info);
    void cbReqP2pConnect(u32* req_seq, const MtNetUniqueId* uniq_id, const MtNetP2pConnectInfo* con_info, s32* connect_id);
    void cbNtcP2pSend(s32 connect_id, const void* data_ptr, s32 data_size);
    void cbNtcP2pRemove(s32 connect_id);
    void cbAnsCreateSucceed(MtNetRequest* req, s32 index, Member* member, MtNetSessionInfo* info);
    void cbAnsCreateFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsSearchSucceed(MtNetRequest* req);
    void cbAnsSearchFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsJoinSucceed(MtNetRequest* req, s32 index, Member* member, MtNetSessionInfo* info);
    void cbAnsJoinFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsFinalize(MtNetRequest* req);
    void cbAnsLockSucceed(MtNetRequest* req, bool is_lock);
    void cbAnsLockFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsInvite(MtNetRequest* req);
    void cbAnsStart(MtNetRequest* req);
    void cbAnsEnd(MtNetRequest* req);
    virtual s32 moveCreate(MtNetRequest*) = 0;  // vtable slot 29
    virtual s32 moveSearch(MtNetRequest*) = 0;  // vtable slot 30
    virtual s32 moveJoin(MtNetRequest*) = 0;  // vtable slot 31
    virtual s32 moveFinalize(MtNetRequest*) = 0;  // vtable slot 32
    virtual s32 moveLock(MtNetRequest*) = 0;  // vtable slot 33
    virtual s32 moveInvite(MtNetRequest*) = 0;  // vtable slot 34
    virtual s32 moveStart(MtNetRequest*) = 0;  // vtable slot 35
    virtual s32 moveEnd(MtNetRequest*) = 0;  // vtable slot 36
    virtual s32 startFinalize(MtNetRequest* req);  // vtable slot 37
private:
    virtual bool canMoveRequest(MtNetRequest* req);  // vtable slot 38
    virtual s32 startRequest(MtNetRequest* req);  // vtable slot 39
    virtual s32 moveRequest(MtNetRequest* req);  // vtable slot 40
    virtual void endRequest(MtNetRequest* req);  // vtable slot 41
    virtual void startFailRequest(MtNetRequest* req);  // vtable slot 42
    s32 startEmpty(MtNetRequest* req);
    void endEmpty(MtNetRequest* req);
protected:
    MtNetContext* mpContext;  // offset: 0x30
    MtNetRequestController mRequestController;  // offset: 0x38
    bool mIsDestructor;  // offset: 0xb0
private:
    Listener* mpListener;  // offset: 0xb8
    s32 mPhaseAutoFinalize;  // offset: 0xc0
    bool mIsNeedFinalize;  // offset: 0xc4
public:
    static const s32 MAX_SIZE_BUF_NAME = 32;
    static const s32 MAX_NUM_SEARCH_KEY_FILTER = 8;
    static const s32 MAX_NUM_SEARCH_RESULT = 32;
    static const s32 MAX_NUM_MEMBER = 16;
    static const s32 MAX_SIZE_BUF_MEMBER_NAME = 32;
    static const u32 INVALID_NONCE = 0;
    static const MtNetTime::Total INVALID_RTT = 65535;
protected:
    static const s32 REQUEST_ID_CREATE = 769;
    static const s32 REQUEST_ID_SEARCH = 770;
    static const s32 REQUEST_ID_JOIN = 771;
    static const s32 REQUEST_ID_FINALIZE = 772;
    static const s32 REQUEST_ID_LOCK = 773;
    static const s32 REQUEST_ID_INVITE = 774;
    static const s32 REQUEST_ID_START = 775;
    static const s32 REQUEST_ID_END = 776;
};
