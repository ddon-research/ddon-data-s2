#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetBuffer.h"
#include "MtObject.h"
#include "MtString.h"

// Forward declarations
struct MtNetError;
class MtNetUniqueId;

// Declarations
class MtNetCom;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_WCHAR = wchar_t;
using MT_CWSTR = const MT_WCHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class MtNetCom
{
public:
    enum
    {
        IID_INative = 0,
        IID_IRichPresence = 1,
        IID_IDialog = 2,
        IID_IPlayersHistory = 3,
        IID_ISessionCreateFlags = 4,
        IID_IWindowHandle = 5,
        IID_IRankingBoardMap = 6,
        IID_IInnerString = 7,
        IID_IParty = 8,
        IID_IInvite = 9,
        IID_IParentalLock = 10,
        IID_ITusCommon = 11,
        IID_IPsHome = 12,
        IID_ISessionPort = 13,
        IID_IXSessionHandle = 14,
        IID_IAchievementOption = 15,
        IID_IPsnTicket = 16,
        IID_IPsnProfile = 17,
        IID_IActivity = 18,
        IID_IPsnPresence = 19,
        IID_IDeviceInfo = 20,
        IID_IPsnServiceState = 21,
        IID_IPsnInGameDataMessage = 22,
        IID_IPsnTus = 23,
        IID_IXdpStatsRelatedLeaderboard = 24,
        IID_ICheckPrivilege = 25,
        IID_IPlayersHistoryPS4 = 26,
        IID_IInvitePS4 = 27,
        IID_IParentalLockPS4 = 28,
        IID_IPsnTicketPS4 = 29,
        IID_IPsnProfilePS4 = 30,
        IID_IPsnPresencePS4 = 31,
        IID_IInnerStringPS4 = 32,
        IID_IPsPlusPS4 = 33,
        IID_IPartyPS4 = 34,
        IID_IPsnTusPS4 = 35,
        IID_IEntitlementPS4 = 36,
        IID_IFriendList = 37,
        IID_IProtocolActivation = 38,
        IID_IUpstreamDisconnection = 39,
        IID_IRichPresenceXboxOne = 40,
        IID_ISteamAppAdmin = 41,
    };
public:
    struct IPartyPS4;
    struct INative;
    struct IPsPlusPS4;
    struct IEntitlementPS4;
    class CPlayersHistoryPS4;
    struct IPlayersHistoryPS4;
    class CInvitePS4;
    struct IInvitePS4;
    class CParentalLockPS4;
    struct IParentalLockPS4;
    class CPsnTicketPS4;
    struct IPsnTicketPS4;
    class CPsnProfilePS4;
    struct IPsnProfilePS4;
    class CPsnPresencePS4;
    struct IPsnPresencePS4;
    class CInnerStringPS4;
    struct IInnerStringPS4;
    class CPsPlusPS4;
    class CPartyPS4;
    class CPsnTusPS4;
    struct IPsnTusPS4;
    class CEntitlementPS4;
    struct IRichPresence;
    struct IInnerString;
    class CInnerString;
    class CRichPresence;
    struct IAchievementOption;
    class CAchievementOption;
    struct IFriendList;
    class CFriendList;
public:
    struct INative
    {
    public:
        virtual ~INative() {}
        virtual bool QueryInterface(s32, void* *) = 0;  // vtable slot 2
        virtual s32 AddRef() = 0;  // vtable slot 3
        virtual s32 Release() = 0;  // vtable slot 4
    };
public:
    struct IPsPlusPS4 : public MtNetCom::INative
    {
    public:
        enum FEATURE
        {
            FEATURE_NONE = 0,
            FEATURE_REALTIME_MULTIPLAY = 1,
            FEATURE_ASYNC_MULTIPLAY = 2,
        };
    public:
        virtual bool start(s32, FEATURE) = 0;  // vtable slot 5
        virtual bool get(s32, bool*, bool*) = 0;  // vtable slot 6
        virtual bool stop(s32) = 0;  // vtable slot 7
    };
public:
    struct IEntitlementPS4 : public MtNetCom::INative
    {
    public:
        enum EntitlementType
        {
            Type_None = 0,
            Type_Service = 1,
            Type_Drm = 2,
            Type_Unified = 3,
            Type_Reward = 4,
        };
    public:
        struct EntitlementList;
        struct EntitlementInfo;
        struct EntitlementUseResult;
    public:
        struct EntitlementInfo
        {
        public:
            MtNetCom::IEntitlementPS4::EntitlementType mType;  // offset: 0x0
            bool mIsConsumable;  // offset: 0x4
            MT_CHAR mIdStr[64];  // offset: 0x5
            u64 mActiveTick;  // offset: 0x48
            u64 mInactiveTick;  // offset: 0x50
            u32 mUseCount;  // offset: 0x58
            u32 mUseLimit;  // offset: 0x5c
        };
    public:
        struct EntitlementUseResult
        {
        public:
            u32 mUseLimit;  // offset: 0x0
        };
    public:
        struct EntitlementList
        {
        public:
            s32 mTotal;  // offset: 0x0
            s32 mOffset;  // offset: 0x4
            s32 mRsize;  // offset: 0x8
            s32 mNum;  // offset: 0xc
            MtNetCom::IEntitlementPS4::EntitlementInfo mInfoTbl[100];  // offset: 0x10
        };
    public:
        virtual bool reqGetEntitlementByRange(s32, bool*, s32, s32, u32) = 0;  // vtable slot 5
        virtual bool pollGetEntitlementByRange(s32, s32*, EntitlementList*) = 0;  // vtable slot 6
        virtual bool reqGetEntitlementById(s32, bool*, MT_CTSTR, u32) = 0;  // vtable slot 7
        virtual bool pollGetEntitlementById(s32, s32*, EntitlementInfo*) = 0;  // vtable slot 8
        virtual bool reqSetEntitlement(s32, bool*, s32, MT_CTSTR, u32) = 0;  // vtable slot 9
        virtual bool pollSetEntitlement(s32, s32*, EntitlementUseResult*) = 0;  // vtable slot 10
    public:
        static const s32 MAX_NUM_INFO = 100;
    };
public:
    struct IPlayersHistoryPS4 : public MtNetCom::INative
    {
    public:
        virtual bool add(s32, MtNetUniqueId*, s32, MT_CTSTR) = 0;  // vtable slot 5
    };
public:
    struct IInvitePS4 : public MtNetCom::INative
    {
    public:
        struct SessionParam;
    public:
        struct SessionParam
        {
        public:
            struct Localized;
        public:
            struct Localized
            {
            public:
                MT_CTSTR mpLanguage;  // offset: 0x0
                MT_CTSTR mpName;  // offset: 0x8
                MT_CTSTR mpStatus;  // offset: 0x10
            };
        public:
            MT_CTSTR mpDefaultName;  // offset: 0x0
            MT_CTSTR mpDefaultStatus;  // offset: 0x8
            Localized mLocalized[32];  // offset: 0x10
            void* mpImageData;  // offset: 0x310
            size_t mImageSize;  // offset: 0x318
            MT_CTSTR mpMessageBody;  // offset: 0x320
        };
    public:
        virtual bool setSessionParam(s32, const SessionParam*) = 0;  // vtable slot 5
        virtual bool showReceive(s32, bool*) = 0;  // vtable slot 6
        virtual bool isReceive(s32, bool*) = 0;  // vtable slot 7
        virtual bool abortReceive(s32) = 0;  // vtable slot 8
    };
public:
    struct IParentalLockPS4 : public MtNetCom::INative
    {
    public:
        virtual bool getChatRestricted(s32, s32*) = 0;  // vtable slot 5
        virtual bool getUgcRestricted(s32, s32*) = 0;  // vtable slot 6
    };
public:
    struct IPsnTicketPS4 : public MtNetCom::INative
    {
    public:
        virtual bool getCode(s32, MtStringEx<256>*) = 0;  // vtable slot 5
        virtual bool getIssuer(s32, s32*) = 0;  // vtable slot 6
        virtual bool req(s32, bool*) = 0;  // vtable slot 7
        virtual bool wait(s32, s32*) = 0;  // vtable slot 8
    };
public:
    struct IPsnProfilePS4 : public MtNetCom::INative
    {
    public:
        virtual bool showProfile(s32, bool*, const MtNetUniqueId*) = 0;  // vtable slot 5
        virtual bool isProfile(s32, bool*) = 0;  // vtable slot 6
        virtual bool abortProfile(s32) = 0;  // vtable slot 7
    };
public:
    struct IPsnPresencePS4 : public MtNetCom::INative
    {
    public:
        virtual bool set(s32, MT_CTSTR) = 0;  // vtable slot 5
    };
public:
    struct IInnerStringPS4 : public MtNetCom::INative
    {
    public:
        struct MessageParam;
    public:
        struct MessageParam
        {
        public:
            MT_CTSTR mpPrgContext;  // offset: 0x0
            MT_CTSTR mpNotSignInContext;  // offset: 0x8
        };
    public:
        virtual bool set(s32, MessageParam*) = 0;  // vtable slot 5
    };
public:
    class CPsPlusPS4 : public MtObject, public MtNetCom::IPsPlusPS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CPsPlusPS4();
        virtual bool start(s32 user_index, MtNetCom::IPsPlusPS4::FEATURE com_feature);  // vtable slot 9
        virtual bool get(s32 user_index, bool* is_get, bool* is_auth);  // vtable slot 10
        virtual bool stop(s32 user_index);  // vtable slot 11
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_PsPlusPS4;  // offset: 0x14
    };
public:
    struct IPsnTusPS4 : public MtNetCom::INative
    {
    public:
        virtual bool changeServiceLabel(s32, s32*, u32) = 0;  // vtable slot 5
        virtual bool getLastChangedDate(s32, u64*) = 0;  // vtable slot 6
        virtual bool setCompChangedDate(s32, u64) = 0;  // vtable slot 7
    };
public:
    class CEntitlementPS4 : public MtObject, public MtNetCom::IEntitlementPS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CEntitlementPS4();
        virtual bool reqGetEntitlementByRange(s32 user_index, bool* result, s32 offset, s32 max_count, u32 label);  // vtable slot 9
        virtual bool pollGetEntitlementByRange(s32 user_index, s32* result, MtNetCom::IEntitlementPS4::EntitlementList* list);  // vtable slot 10
        virtual bool reqGetEntitlementById(s32 user_index, bool* result, MT_CTSTR ent_id, u32 label);  // vtable slot 11
        virtual bool pollGetEntitlementById(s32 user_index, s32* result, MtNetCom::IEntitlementPS4::EntitlementInfo* info);  // vtable slot 12
        virtual bool reqSetEntitlement(s32 user_index, bool* result, s32 count, MT_CTSTR ent_id, u32 label);  // vtable slot 13
        virtual bool pollSetEntitlement(s32 user_index, s32* result, MtNetCom::IEntitlementPS4::EntitlementUseResult* use_result);  // vtable slot 14
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_EntitlementPS4;  // offset: 0x14
    };
public:
    struct IRichPresence : public MtNetCom::INative
    {
    public:
        class Handler;
    public:
        class Handler
        {
        public:
            Handler();
            virtual ~Handler() {}
            virtual u32 onUserSignedIn(u32);  // vtable slot 2
        };
    public:
        virtual bool init(Handler*) = 0;  // vtable slot 5
        virtual bool update() = 0;  // vtable slot 6
        virtual bool write(u32, u32) = 0;  // vtable slot 7
        virtual bool setUserContext(u32, u32, u32) = 0;  // vtable slot 8
        virtual bool setUserProperty(u32, u32, u32, const void*) = 0;  // vtable slot 9
    };
public:
    struct IInnerString : public MtNetCom::INative
    {
    public:
        virtual bool setInviteMessage(MT_CTSTR, MT_CTSTR) = 0;  // vtable slot 5
        virtual bool setContentRestrictString(MT_CTSTR) = 0;  // vtable slot 6
        virtual bool setChatRestrictString(MT_CTSTR) = 0;  // vtable slot 7
    };
public:
    class CInnerString : public MtObject, public MtNetCom::IInnerString
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32, void* *);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
    };
public:
    class CRichPresence : public MtObject, public MtNetCom::IRichPresence
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32, void* *);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
    };
public:
    struct IAchievementOption : public MtNetCom::INative
    {
    public:
        virtual bool setVolume(f32) = 0;  // vtable slot 5
        virtual bool getProgress(f32*) = 0;  // vtable slot 6
    };
public:
    class CAchievementOption : public MtObject, public MtNetCom::IAchievementOption
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32, void* *);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
    };
public:
    struct IFriendList : public MtNetCom::INative
    {
    public:
        struct FriendInfo;
    public:
        struct FriendInfo
        {
        public:
            MtNetUniqueId mUniqueId;  // offset: 0x0
            MT_CHAR mDisplayName[64];  // offset: 0x78
            bool mIsOmittedDisplayName;  // offset: 0xb8
            MT_CHAR mUserName[32];  // offset: 0xb9
            bool mIsOmittedUserName;  // offset: 0xd9
        };
    public:
        virtual bool reqUpdate(s32) = 0;  // vtable slot 5
        virtual bool abortUpdate(s32) = 0;  // vtable slot 6
        virtual bool waitUpdate(s32, MtNetError*) = 0;  // vtable slot 7
        virtual bool reqGetFriendInfo(s32, MtNetUniqueId*, s32, FriendInfo*) = 0;  // vtable slot 8
        virtual bool waitGetFriendInfo(s32, s32*) = 0;  // vtable slot 9
        virtual bool reqGetAreUsersFriends(s32, MtNetUniqueId*, s32) = 0;  // vtable slot 10
        virtual bool waitGetAreUsersFriends(s32, bool*) = 0;  // vtable slot 11
        virtual void setSocialGroupString(MT_CWSTR) = 0;  // vtable slot 12
        virtual bool reqGetSelfRank(s32, s32) = 0;  // vtable slot 13
        virtual bool abortGetSelfRank(s32) = 0;  // vtable slot 14
        virtual bool waitGetSelfRank(s32, s32*, MtNetError*) = 0;  // vtable slot 15
    public:
        static const s32 MAX_SIZE_BUF_DISPLAY_NAME = 64;
        static const s32 MAX_SIZE_BUF_USER_NAME = 32;
    };
public:
    class CFriendList : public MtObject, public MtNetCom::IFriendList
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32, void* *);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
    };
public:
    struct IPartyPS4 : public MtNetCom::INative
    {
    public:
        class PartyInfo;
        class PartyMemberInfo;
    public:
        class PartyMemberInfo
        {
        public:
            PartyMemberInfo();
            void clear();
            MtNetCom::IPartyPS4::PartyMemberInfo& operator=(const MtNetCom::IPartyPS4::PartyMemberInfo& src);
        public:
            MtNetUniqueId mUniqueId;  // offset: 0x0
            u16 mMemberId;  // offset: 0x78
        };
    public:
        class PartyInfo
        {
        public:
            PartyInfo();
            void clear();
            MtNetCom::IPartyPS4::PartyInfo& operator=(const MtNetCom::IPartyPS4::PartyInfo& src);
        public:
            MtNetCom::IPartyPS4::PartyMemberInfo mMember[8];  // offset: 0x0
            s32 mValidNum;  // offset: 0x400
            bool mIsPrivate;  // offset: 0x404
            static const s32 MAX_NUM_MEMBER = 8;
        };
    public:
        virtual bool getInfo(PartyInfo*) = 0;  // vtable slot 5
    };
public:
    class CPlayersHistoryPS4 : public MtObject, public MtNetCom::IPlayersHistoryPS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CPlayersHistoryPS4();
        virtual bool add(s32 user_index, MtNetUniqueId* id_list, s32 id_num, MT_CTSTR explain);  // vtable slot 9
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_PlayersHistoryPS4;  // offset: 0x14
    };
public:
    class CInvitePS4 : public MtObject, public MtNetCom::IInvitePS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CInvitePS4();
        virtual bool setSessionParam(s32 user_index, const MtNetCom::IInvitePS4::SessionParam* param);  // vtable slot 9
        virtual bool showReceive(s32 user_index, bool* is_start);  // vtable slot 10
        virtual bool isReceive(s32 user_index, bool* is_show);  // vtable slot 11
        virtual bool abortReceive(s32 user_index);  // vtable slot 12
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_InvitePS4;  // offset: 0x14
    };
public:
    class CParentalLockPS4 : public MtObject, public MtNetCom::IParentalLockPS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* * ppRp);
        static void CoUninitialize(MtNetCom::INative* * ppRp);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CParentalLockPS4();
        virtual bool getChatRestricted(s32 user_index, s32* result);  // vtable slot 9
        virtual bool getUgcRestricted(s32 user_index, s32* result);  // vtable slot 10
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_ParentalLockPS4;  // offset: 0x14
    };
public:
    class CPsnTicketPS4 : public MtObject, public MtNetCom::IPsnTicketPS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CPsnTicketPS4();
        virtual bool getCode(s32 user_index, MtStringEx<256>* code);  // vtable slot 9
        virtual bool getIssuer(s32 user_index, s32* issuer);  // vtable slot 10
        virtual bool req(s32 user_index, bool* is_start);  // vtable slot 11
        virtual bool wait(s32 user_index, s32* result);  // vtable slot 12
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_PsnTicketPS4;  // offset: 0x14
    };
public:
    class CPsnProfilePS4 : public MtObject, public MtNetCom::IPsnProfilePS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CPsnProfilePS4();
        virtual bool showProfile(s32 user_index, bool* is_start, const MtNetUniqueId* uniq_id);  // vtable slot 9
        virtual bool isProfile(s32 user_index, bool* is_show);  // vtable slot 10
        virtual bool abortProfile(s32 user_index);  // vtable slot 11
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_PsnProfilePS4;  // offset: 0x14
    };
public:
    class CPsnPresencePS4 : public MtObject, public MtNetCom::IPsnPresencePS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CPsnPresencePS4();
        virtual bool set(s32 user_index, MT_CTSTR message);  // vtable slot 9
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_PsnPresencePS4;  // offset: 0x14
    };
public:
    class CInnerStringPS4 : public MtObject, public MtNetCom::IInnerStringPS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CInnerStringPS4();
        virtual bool set(s32 user_index, MtNetCom::IInnerStringPS4::MessageParam* param);  // vtable slot 9
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_InnerStringPS4;  // offset: 0x14
    };
public:
    class CPartyPS4 : public MtObject, public MtNetCom::IPartyPS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CPartyPS4();
        virtual bool getInfo(MtNetCom::IPartyPS4::PartyInfo* info);  // vtable slot 9
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_PartyPS4;  // offset: 0x14
    };
public:
    class CPsnTusPS4 : public MtObject, public MtNetCom::IPsnTusPS4
    {
    public:
        static bool CoInitialize(MtNetCom::INative* *);
        static void CoUninitialize(MtNetCom::INative* *);
        virtual bool QueryInterface(s32 iid, void* * ppvObj);  // vtable slot 6
        virtual s32 AddRef();  // vtable slot 7
        virtual s32 Release();  // vtable slot 8
        const s32 _dummy_variable_get() const;
    private:
        CPsnTusPS4();
        virtual bool changeServiceLabel(s32 user_index, s32* result, u32 label);  // vtable slot 9
        virtual bool getLastChangedDate(s32 user_index, u64* tick);  // vtable slot 10
        virtual bool setCompChangedDate(s32 user_index, u64 tick);  // vtable slot 11
    private:
        s32 mRefCnt;  // offset: 0x10
        s32 _dummy_variable_PsnTusPS4;  // offset: 0x14
    };
public:
    static bool isIIDEqual(s32 id1, s32 id2);
};
