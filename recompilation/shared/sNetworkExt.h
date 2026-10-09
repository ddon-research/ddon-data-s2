#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Clan.h"
#include "Community.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtNetBuffer.h"
#include "MtNetCore.h"
#include "MtNetDevice.h"
#include "MtObject.h"
#include "MtTime.h"
#include "nNet.h"
#include "nNetworkAchievement.h"
#include "nNetworkCallback.h"
#include "np_npid.h"
#include "sNetwork.h"

// Forward declarations
class CDataClanDungeonInfo;
class CDataClanFunctionInfo;
class CDataClanMemberInfo;
class CDataCommonU32;
class CDataCommunityCharacterBaseInfo;
class CDataPawnExpeditionInformation;
class MtAllocator;
class MtDTI;
struct MtNetError;
struct MtNetPhysicalAddress;
class MtNetUniqueId;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtTime;
class MtUI;
struct SceNpId;
class cCharacterData;
class cNetGameServer;
class cNetLoginServer;
class cNetStorage;
namespace nNet { class cProgress; }
namespace nNet { struct stClanEmblem; }
namespace nNet { struct stEntryBoardItemInfo; }
namespace nSessionManager { class cNetSessionManager; }

// Declarations
class sNetworkExt;

// Type aliases from DWARF
using CClanDungeonInfo = CDataClanDungeonInfo;
using CClanFunctionInfo = CDataClanFunctionInfo;
using CClanMemberInfo = CDataClanMemberInfo;
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CPawnExpeditionInformation = CDataPawnExpeditionInformation;
using ClanMemberInfoVec = MtTypedArray<CDataClanMemberInfo>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class sNetworkExt : public sNetwork
{
public:
    enum LOGIN_RNO
    {
        RNO_NET_LOGIN = 0,
        RNO_NET_LOGIN_ERROR = 1,
        RNO_NET_ERROR = 2,
        RNO_NET_LOGIN_NUM = 3,
    };
    enum NET_STAT
    {
        NET_STAT_NONE = 0,
        NET_STAT_REQ = 1,
        NET_STAT_SUCCESS = 2,
        NET_STAT_CANCEL = 3,
        NET_STAT_ERROR = 4,
        NET_NUM = 5,
    };
    enum MATCH_TYPE
    {
        MATCH_TYPE_UNKNOWN = 0,
        MATCH_TYPE_INVITE = 1,
        MATCH_TYPE_QUICK = 2,
        MATCH_TYPE_ENTRYBOARD = 3,
    };
    enum LOGIN_RET_STAT
    {
        LOGIN_STAT_CONTINUE = 0,
        LOGIN_STAT_OK = 1,
        LOGIN_STAT_CANCEL = 2,
    };
    enum
    {
        BIG_CYCLE_STATE_ERROR = 0,
        BIG_CYCLE_STATE_NONE = 1,
        BIG_CYCLE_STATE_NOTIFY = 2,
        BIG_CYCLE_STATE_SEASON1 = 3,
        BIG_CYCLE_STATE_SEASON2 = 4,
        BIG_CYCLE_STATE_RANKING_WAIT = 5,
        BIG_CYCLE_STATE_RESULT = 6,
        BIG_CYCLE_STATE_MAX = 7,
    };
    enum
    {
        TITLE_UPDATE_SUSPEND = 0,
        TITLE_UPDATE_INIT = 1,
        TITLE_UPDATE_REQ = 2,
        TITLE_UPDATE_WAIT = 3,
        TITLE_UPDATE_WAIT2 = 4,
        TITLE_UPDATE_ERROR = 5,
        TITLE_UPDATE_ERROR_WAIT = 6,
        TITLE_UPDATE_EXIT = 7,
    };
    enum AWARD
    {
        AWARD_TOP = 0,
        AWARD_PLAY_START = 0,
        AWARD_CLEAR_BOARD_QUEST = 1,
        AWARD_DELIVER = 2,
        AWARD_CRAFT_CREATE = 3,
        AWARD_EQUIP_UPDATE = 4,
        AWARD_REVIVE = 5,
        AWARD_BAZAAR = 6,
        AWARD_EQUIP_GRADEUP = 7,
        AWARD_GET_MONEY = 8,
        AWARD_JOBLV_FIGHTER = 9,
        AWARD_JOBLV_HUNTER = 10,
        AWARD_JOBLV_PRIEST = 11,
        AWARD_JOBLV_SHIELD_SAGE = 12,
        AWARD_MAX = 13,
    };
    enum
    {
        PHASE_IDLE = 0,
        PHASE_SHOW = 1,
    };
    enum
    {
        AWARD_HIGH_JOBLV_VALUE = 40,
        AWARD_GET_MONEY_VALUE = 500000,
        AWARD_EQUIP_GRADEUP_VAL = 4,
    };
    enum USER_CALLBACK
    {
        CALLBACK_CTRL = 7,
        CALLBACK_GAME = 8,
        CALLBACK_SET_MGR = 9,
        CALLBACK_ITEM_MGR = 10,
        CALLBACK_TOOL = 11,
        CALLBACK_MAX = 15,
        CALLBACK_ERROR = -1,
    };
public:
    class MyDTI;
    class cAchievementListener;
    struct stEntryInvitedInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAchievementListener : public nNetwork::nAchievement::Listener
    {
    public:
        // Address: 0x01ac6e30 - 0x01ac6e31 (1 bytes)
        virtual ~cAchievementListener() {}
        void setParent(sNetworkExt* p);
        virtual void onInitComplete(u64 option, MtNetError* err);  // vtable slot 2
        virtual void onStartComplete(MtNetError* err);  // vtable slot 3
        virtual void onGetInfoComplete(s32 user_index, s32 id, bool is_award, MtNetError* err);  // vtable slot 4
        virtual void onAwardComplete(s32 user_index, s32 id, MtNetError* err);  // vtable slot 5
    private:
        sNetworkExt* mpParent;  // offset: 0x8
    };
public:
    struct stEntryInvitedInfo
    {
    public:
        CCommunityCharacterBaseInfo mHostInfo;  // offset: 0x0
        u64 mEntryBoardId;  // offset: 0x30
        u32 mEntryId;  // offset: 0x38
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
    sNetworkExt(MtNetCore::InitParam* param);
    virtual ~sNetworkExt();
    virtual void reset();  // vtable slot 6
    void moveBefore();
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void init();
    void final();
    void requestLogin();
private:
    bool loginCore();
public:
    LOGIN_RET_STAT moveLogin();
    void setReqShutdownContext(bool b);
    bool isShutdownContextEnable();
    void shutdown();
private:
    void shutdownCore();
public:
    bool isBootupAchievement();
    bool isReadyAchievement();
    void requestGetAchievementInfo(s32 id);
    void requestAward(s32 id);
    bool isProcessingAward();
    void cancelProcessingAward();
    u64 getTrophySize() const;
    void startTrophy();
    f32 getTrophyProgress();
    bool setTrophyVolume(f32 vol);
    void setTrophySize(u64 size);
    nSessionManager::cNetSessionManager* getSessionManager();
    cNetLoginServer* getLoginServer();
    cNetGameServer* getGameServer();
    cNetStorage* getNetStorageWorldInfo();
    cNetStorage* getNetStorageCharInfo();
    bool isEqualMyUniqueId(const MtNetUniqueId*);
    MtNetUniqueId& getMyUniqueId();
    s32 getUserIndex() const;
    void setUserIndex(s32);
    void setReceiveCallbackEx(u32 callback_index, MtObject* pobj, sNetwork::RECEIVE_CALLBACK callback, u32 sessionInstanceIndex);
    void clearReceiveCallbackEx(u32 callback_index, u32 sessionInstanceIndex);
    MT_CHAR* getMacAdrStr(MtNetPhysicalAddress*);
    void clrNotifySync(u32& flag, s32 memberIndex);
    void clrNotifySyncAll(u32& flag);
    void setNotifySync(u32& flag, s32 memberIndex);
    bool isNotifySync(u32& flag, s32 memberIndex);
    bool isNotifySyncAll(u32& flag);
    void clrNotifySyncJoinMember(s32 memberIndex);
private:
    bool signOutCheck();
    bool unlinkCheck(MtNetError& error);
    bool errorCheck();
    void dispDebugInfo();
    bool isSignOut();
    void setIsSignOut(bool flag);
public:
    bool isUnlink();
    void setIsUnlink(bool flag);
    bool isAvailableDialog();
    void setIsAvailableDialog(bool flag);
    bool isToLauncher();
    void setIsToLauncher(bool flag);
    void requestNetworkErrorDialog(s32 errNo);
    void requestNetworkErrorDialog(s32 no, s32 cause, s32 native);
    void reserveNetworkErrorDialog(s32 comId);
    void cancelReserveNetworkErrorDialog(s32 comId);
private:
    void resetErrorDisp();
    void moveErrorDispManager();
    bool setNetworkErrorDialog(s32 level, const MtNetError& err, s32 index);
public:
    bool isDispErrorDialog();
    void closeErrorDisp();
    const MtTime getWorldServerTime() const;
    void setWorldServerTime(MtTime);
    void setWorldServerTime(MtTime time, u16 msec);
    s32 getWorldServerMsec() const;
    t64 getLocalSystemTime() const;
    t64 getWorldServerTimeSec() const;
    void requestGetServerRealTime();
    void updateWorldServerTime();
    s32 getAverageRTT();
    s32 getSendBps();
    s32 getRecvBps();
    bool reqLoadWorldInfo(u32 worldId);
    bool reqSaveWorldInfo(u32 worldId);
    s32 getAFKLogoutTime();
    void setAFKLogoutTime(u32 time);
    s32 getCharacterMaxNum();
    void setCharacterMaxNum(u32 num);
    s32 getCharacterIdFromSlotNo(s32 slotNo);
    bool reqLoadCharInfo(cCharacterData* pCharData, u32 slotNo);
    bool reqLoadCharInfoCharaID(cCharacterData* pCharData, s32 charID);
    bool reqSaveCharInfo(cCharacterData* pCharData, bool isForce);
    void resetSaveCharTime();
    s32 getSlot();
    void setSlot(s32 slot);
    MT_CTSTR getLoginAnnounce();
    void setLoginAnnounce(MT_CTSTR str);
    u32 getMyPawnMaxNum();
    void setMyPawnMaxNum(u32 num);
    u32 getRentedPawnMaxNum();
    void setRentedPawnMaxNum(u32 num);
    u32 calcPeriodicTime(f32 rate);
    u32 getBasePeriodicTime();
    void setBasePeriodicTime(u32);
    void clearMyClanInfo();
    bool isClanEnable();
    void setIsClanEnable(bool flag);
    bool isBelongClan() const;
    bool isClanLeader();
    void setIsApplyClan(bool flag);
    bool isApplyClan();
    void setIsClanScoutEntry(bool flag);
    bool isClanScoutEntry();
    void setIsClanUpdate(bool flag);
    bool isClanUpdate();
    bool isClanInterval();
    bool isClanIntervalMember(const CClanMemberInfo& info);
    bool isClanIntervalTime(u64 lastClanDate);
    u32 getClanIntervalTime();
    void setClanIntervalTime(u32 time);
    void setLastClanLeaveTime(s64 time);
    u64 getClanIntervalRemainTime();
    bool isClanBaseRelease();
    void setClanBaseRelease(bool flag);
    bool isClanPermission(nClan::E_CLAN_PERMISSION permission, const CClanMemberInfo* pInfo);
    u32 getMyClanId();
    MT_CTSTR getMyClanName();
    MT_CTSTR getMyClanNickname();
    MT_CTSTR getMyClanLeaderFirstName();
    MT_CTSTR getMyClanLeaderLastName();
    u32 getMyClanMotto();
    u32 getMyClanDay();
    u32 getMyClanHour();
    u32 getMyClanFeature();
    MT_CTSTR getMyClanComment();
    MT_CTSTR getMyClanMessage();
    const nNet::stClanEmblem* getMyClanEmblem();
    bool isClanMember(u32 characterId);
    const ClanMemberInfoVec& getMyClanMemberListRef();
    CClanMemberInfo* getMyClanMemberInfoFromCharId(u32 characterId);
    void addClanInvitedNum();
    void subClanInvitedNum();
    void setClanInvitedNum(u32 num);
    bool isClanInvited();
    u32 getClanInvitedNum();
    void addClanApprovedNum();
    void subClanApprovedNum();
    void setClanApprovedNum(u32 num);
    bool isClanApproved();
    u32 getClanApprovedNum();
    bool isEnableCreateClan();
    void reqCreateClanDisableAnnounce();
    bool isEnableClanScoutEntry();
    void reqClanScoutEntryDisableAnnounce();
    u32 getClanDirectInvitedNum();
    bool isClanBaseInfoValid() const;
    const CClanFunctionInfo& getClanFunctionInfo() const;
    const CClanDungeonInfo& getClanDungeonInfo() const;
    const CPawnExpeditionInformation& getPawnExpeditionInfo() const;
    u8 getClanPawnSallyState() const;
    const MtTypedArray<CDataCommonU32>& getClanMyPawnList() const;
    const MtTypedArray<CDataCommonU32>& getClanMemberPawnList() const;
    void setClanMemberMax(u32 num);
    u32 getClanMemberMax();
    void clearFriendInfo();
    bool isFriend(u32 characterId);
    void setIsAppliedFriend(bool flag);
    bool isAppliedFriend();
    void setFriendListMax(u32 num);
    u32 getFriendListMax();
    void setGroupChatMemberMax(u32 num);
    u32 getGroupChatMemberMax();
    void setRecentListMax(u32 num);
    u32 getRecentListMax();
    void setBlackListMax(u32 num);
    u32 getBlackListMax();
    void updateCommunityMyInfo();
    void clearAllEntryBoardInfo();
    bool isEntryBoardItem();
    void setIsEntryBoardItem(bool flag);
    bool isEntryLeader();
    u64 getMyEntryBoardId();
    bool enableEntryBoardExtend();
    void setEntryBoardAliveTimer(f32 time);
    f32 getEntryBoardAliveTimer();
    void setIsEntryLeader(bool leader);
    void setEntryBoardId(u64 boardId);
    void setEntryBoardReadyWait(bool wait);
    bool isEntryBoardReadyWait();
    void setEntryBoardReadyWaitAnnounce(bool flag);
    bool isEntryBoardReadyWaitAnnounce();
    void setEntryBoardReadyWaitTimer(f32 time);
    f32 getEntryBoardReadyWaitTimer();
    void setEntryBoardReadyFlag(bool ready);
    bool isEntryBoardReady();
    void setEntryBoardPartyReserve(bool flag);
    bool isEntryBoardPartyReserve();
    void setEntryInviteAnnounce(bool flag);
    bool isEntryInviteAnnounce();
    void setReserveJoinParty(bool reserve, bool isQuick);
    bool isReserveJoinParty();
    bool isQuickPartyJoin();
    void setJoinPartyWait(bool wait);
    bool isJoinPartyWait();
    void setJoinPartyWaitAnnounce(bool wait);
    bool isJoinPartyWaitAnnounce();
    void setReserveJob(s32 job);
    s32 getReserveJob();
    void clearReserveJob();
    void setPawnSlot(u32 idx, s32 slot);
    s32 getPawnSlot(u32 idx);
    void clearPartyMatchType();
    void setPartyMatchType(MATCH_TYPE type);
    MATCH_TYPE getPartyMatchType();
    nNet::stEntryBoardItemInfo& getMyBoardInfo();
    void clearEntryInviteInfoBoardId(u64 boardId, u32 entryId);
    void clearEntryInviteInfoOld();
    void clearEntryInviteInfoAll();
    bool isEmptyEntryInviteInfo(const stEntryInvitedInfo& info) const;
    const stEntryInvitedInfo& getEntryInviteInfo(u32 index) const;
    const stEntryInvitedInfo* getEntryInviteInfoRecent() const;
    const stEntryInvitedInfo& getEntryInviteInfoSave() const;
    stEntryInvitedInfo* getEntryInviteInfo(CCommunityCharacterBaseInfo& hostInfo);
    stEntryInvitedInfo* getEmptyEntryInviteInfo();
    u32 getEntryInviteNum();
    s32 getEntryInviteIdRecent() const;
    void saveEntryInviteInfo(u32 index);
    bool setEntryInvite(CCommunityCharacterBaseInfo& hostInfo, u64 boardId, u32 entryId);
private:
    void clearEntryInviteInfo(stEntryInvitedInfo& info);
    void compactEntryInviteList();
    void copyEntryInviteInfo(stEntryInvitedInfo& dstInfo, const stEntryInvitedInfo& srcInfo);
    void updateEntryBoardAliveTimer();
public:
    void setLeaveOnTheWayBusy(bool busy);
    bool isLeaveOnTheWayBusy();
    void setLeaveOnTheWayAnswer(bool answer);
    bool isLeaveOnTheWayAnswer();
    void setLeaveOnTheWayResult(bool result);
    bool isLeaveOnTheWayResult();
    void setLeaveOnTheWayTimer(f32 timer);
    f32 getLeaveOnTheWayTimer();
    void updateLeaveOnTheWayTimer();
    void setCycleContentsPlayStart(bool IsStart);
    bool isCycleContentsPlayStart() const;
    s32 getBigCycleState();
    void changeBigCycleState(s32 state);
    bool reqTitleUpdateCheck();
    bool moveTitleUpdateCheck();
private:
    MtNetUniqueId mUniqueIdMyself;  // offset: 0xd38
    s32 mUserIndex;  // offset: 0xdb0
    nNet::cProgress mLoginProgress;  // offset: 0xdb8
    f32 mLoginTimer;  // offset: 0xe00
    u32 mLoginDialogHandle;  // offset: 0xe04
    bool mLoginErrorDialog;  // offset: 0xe08
    LOGIN_RNO mLoginRno;  // offset: 0xe0c
    bool mReqShutdownContext;  // offset: 0xe10
    cAchievementListener mAchievementListener;  // offset: 0xe18
    bool mAchievementBootup;  // offset: 0xe28
    bool mAchievementReady;  // offset: 0xe29
    nNet::STATE mAchievementIsAward;  // offset: 0xe2c
    nNet::STATE mAchievementStatus;  // offset: 0xe30
    u64 mAchievementFlag;  // offset: 0xe38
    u64 mTrophySize;  // offset: 0xe40
    f32 mTrophyProgress;  // offset: 0xe48
    bool mStateErrorDialog;  // offset: 0xe4c
    nSessionManager::cNetSessionManager* mpSessionManager;  // offset: 0xe50
    cNetLoginServer* mpLoginServer;  // offset: 0xe58
    cNetGameServer* mpGameServer;  // offset: 0xe60
    cNetStorage* mpNetStorageWorldInfo;  // offset: 0xe68
    cNetStorage* mpNetStorageCharInfo;  // offset: 0xe70
    nNetwork::Receiver<MtObject> mCallbackEntryEx[16];  // offset: 0xe78
    MT_CHAR mMacAdrStr[16];  // offset: 0x10f8
    s32 mOldSignInLevel;  // offset: 0x1108
    bool mIsSignOut;  // offset: 0x110c
    bool mIsUnlink;  // offset: 0x110d
    bool mIsAvailableDialog;  // offset: 0x110e
    bool mIsToLauncher;  // offset: 0x110f
    s32 mErrorDispPhase;  // offset: 0x1110
    u32 mErrorDialogHandle;  // offset: 0x1114
    s32 mReserveErrComId;  // offset: 0x1118
    MtTime mWorldServerTime;  // offset: 0x1120
    t64 mLocalSystemTime;  // offset: 0x1128
    s32 mTotalDeltaTime;  // offset: 0x1130
    MtNetTime::Total mUpdateTime;  // offset: 0x1138
    u32 mAFKLogoutTime;  // offset: 0x1140
    MtTime mSaveCharTime;  // offset: 0x1148
    s32 mSlotNo;  // offset: 0x1150
    MT_CHAR mLoginAnnounce[1024];  // offset: 0x1154
    s32 mCharacterMaxNum;  // offset: 0x1554
    s32 mMyPawnMaxNum;  // offset: 0x1558
    s32 mRentedPawnMaxNum;  // offset: 0x155c
    u32 mBasePeriodicTime;  // offset: 0x1560
    nNet::stClanEmblem mMyClanEmblem;  // offset: 0x1564
    bool mIsClanEnable;  // offset: 0x1568
    bool mIsApplyClan;  // offset: 0x1569
    bool mIsClanScoutEntry;  // offset: 0x156a
    bool mIsClanUpdate;  // offset: 0x156b
    u32 mClanInvitedNum;  // offset: 0x156c
    u32 mClanApprovedNum;  // offset: 0x1570
    u32 mClanIntervalTime;  // offset: 0x1574
    s64 mLastClanLeaveTime;  // offset: 0x1578
    bool mIsClanBaseRelease;  // offset: 0x1580
    nNet::stEntryBoardItemInfo mMyBoardInfo;  // offset: 0x1588
    u64 mEntryBoardId;  // offset: 0x1668
    f32 mEntryBoardAliveTimer;  // offset: 0x1670
    f32 mEntryBoardReadyWaitTimer;  // offset: 0x1674
    bool mIsEntryItemLeader;  // offset: 0x1678
    bool mEntryBoardReadyWait;  // offset: 0x1679
    bool mEntryBoardReadyWaitAnnounce;  // offset: 0x167a
    bool mEntryBoardReady;  // offset: 0x167b
    bool mEntryBoardPartyReserve;  // offset: 0x167c
    bool mIsEntryBoardItem;  // offset: 0x167d
    bool mEntryInviteAnnounce;  // offset: 0x167e
    bool mReserveJoinParty;  // offset: 0x167f
    bool mIsQuickPartyJoin;  // offset: 0x1680
    bool mJoinPartyWait;  // offset: 0x1681
    bool mJoinPartyWaitAnnounce;  // offset: 0x1682
    s32 mReserveJob;  // offset: 0x1684
    MATCH_TYPE mPartyMatchType;  // offset: 0x1688
    s32 mPawnSlot[3];  // offset: 0x168c
    bool mIsAppliedFriend;  // offset: 0x1698
    u32 mFriendListMax;  // offset: 0x169c
    u32 mClanMemberMax;  // offset: 0x16a0
    u32 mRecentListMax;  // offset: 0x16a4
    u32 mBlackListMax;  // offset: 0x16a8
    u32 mGroupChatMemberMax;  // offset: 0x16ac
    stEntryInvitedInfo mEntryInvitedList[5];  // offset: 0x16b0
    stEntryInvitedInfo mSaveEntryInvitedInfo;  // offset: 0x17f0
    bool mLeaveOnTheWayBusy;  // offset: 0x1830
    bool mLeaveOnTheWayAnswer;  // offset: 0x1831
    bool mLeaveOnTheWayResult;  // offset: 0x1832
    f32 mLeaveOnTheWayTimer;  // offset: 0x1834
    bool mIsCycleContentsPlayStart;  // offset: 0x1838
    s32 mBigCycleState;  // offset: 0x183c
    u32 mTitleUpdateRno;  // offset: 0x1840
    s32 mTitleUpdateErrorNo;  // offset: 0x1844
    SceNpId mNpSelfId;  // offset: 0x1848
    s32 mNpAsyncRequestId;  // offset: 0x186c
public:
    static MyDTI DTI;
    static const u32 UPLINK_DIALOG_FRAME = 120;
    static const s32 LOGIN_ANNOUNCE_NUM = 1024;
    static const u32 DEFAULT_BASE_PERIODIC_TIME = 30;
    static const u32 ENTRY_BOARD_EXTEND_TIME = 30;
    static const u32 ENTRY_INVITE_MAX = 5;
    static const u32 PAWN_PARTY_MAX = 3;
};

// Inline, no code of its own: checked where it is inlined.
inline nSessionManager::cNetSessionManager* sNetworkExt::getSessionManager() {
    return this->mpSessionManager;
}

// Inline, no code of its own: checked where it is inlined.
inline cNetLoginServer* sNetworkExt::getLoginServer() {
    return this->mpLoginServer;
}

// Inline, no code of its own: checked where it is inlined.
inline cNetGameServer* sNetworkExt::getGameServer() {
    return this->mpGameServer;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 sNetworkExt::getFriendListMax() {
    return this->mFriendListMax;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 sNetworkExt::getRecentListMax() {
    return this->mRecentListMax;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 sNetworkExt::getBlackListMax() {
    return this->mBlackListMax;
}
