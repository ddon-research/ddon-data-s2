#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Community.h"
#include "EntryBoard.h"
#include "Job.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtNetObject.h"
#include "Party.h"
#include "nHuman.h"

// Forward declarations
class CDataClanParam;
class CDataClanScoutEntryParam;
class CDataCommunityCharacterBaseInfo;
class CDataEntryItem;
class CDataEntryItemParam;
class CDataEntryMemberData;
class CDataEntryRecruitData;
class MtAllocator;
class MtDTI;
struct MtNetError;
class MtObject;
class MtPropertyList;

// Declarations
class CDataClientPartyListInfo;
namespace nNet { struct stClanEmblem; }
namespace nNet { class cProgress; }
namespace nNet { class cResult; }
namespace nNet { struct stEntryBoardItemInfo; }
namespace nNet { struct stPawnFeedback; }
namespace nNet { struct stFeedbackData; }

namespace nNet {
    enum CLAN_DAY
    {
        CLAN_DAY_NONE = 0,
        CLAN_DAY_NOTHING = 0,
        CLAN_DAY_EVERYDAY = 2,
        CLAN_DAY_WEEKDAY = 4,
        CLAN_DAY_WEEKEND = 8,
        CLAN_DAY_HOLIDAY = 16,
        CLAN_DAY_DEFAULT = 2,
        CLAN_DAY_MAX = 5,
    };
}  // namespace nNet

namespace nNet {
    enum CLAN_EMBLEM_BASE
    {
        CLAN_EMBLEM_BASE_NONE = 0,
        CLAN_EMBLEM_BASE_DEFAULT = 1,
        CLAN_EMBLEM_BASE_MAX = 20,
    };
}  // namespace nNet

namespace nNet {
    enum CLAN_EMBLEM_COLOR
    {
        CLAN_EMBLEM_COLOR_NONE = 0,
        CLAN_EMBLEM_MAIN_COLOR_DEFAULT = 1,
        CLAN_EMBLEM_SUB_COLOR_DEFAULT = 2,
        CLAN_EMBLEM_COLOR_MAX = 128,
    };
}  // namespace nNet

namespace nNet {
    enum CLAN_EMBLEM_MARK
    {
        CLAN_EMBLEM_MARK_NONE = 0,
        CLAN_EMBLEM_MARK_DEFAULT = 1,
        CLAN_EMBLEM_MARK_MAX = 20,
    };
}  // namespace nNet

namespace nNet {
    enum CLAN_FEATURE
    {
        CLAN_FEATURE_NONE = 0,
        CLAN_FEATURE_NOTHING = 0,
        CLAN_FEATURE_DEFAULT = 2,
        CLAN_FEATURE_MAX = 23,
    };
}  // namespace nNet

namespace nNet {
    enum CLAN_HOUR
    {
        CLAN_HOUR_NONE = 0,
        CLAN_HOUR_NOTHING = 0,
        CLAN_HOUR_ANYTIME = 2,
        CLAN_HOUR_MORNING = 4,
        CLAN_HOUR_DAYTIME = 8,
        CLAN_HOUR_NIGHT = 16,
        CLAN_HOUR_DEFAULT = 2,
        CLAN_HOUR_MAX = 5,
    };
}  // namespace nNet

namespace nNet {
    enum CLAN_MOTTO
    {
        CLAN_MOTTO_NONE = 0,
        CLAN_MOTTO_NOTHING = 0,
        CLAN_MOTTO_DEFAULT = 2,
        CLAN_MOTTO_MAX = 7,
    };
}  // namespace nNet

namespace nNet {
    enum FEEDBACK_TYPE
    {
        FEEDBACK_EDIT = 0,
        FEEDBACK_BATTLE = 1,
        FEEDBACK_CRAFT = 2,
        FEEDBACK_MAX = 3,
    };
}  // namespace nNet

namespace nNet {
    enum PAWN_SHARE_RANGE
    {
        PAWN_SHARE_RANGE_INVALID = 0,
        PAWN_SHARE_RANGE_ANYONE = 1,
        PAWN_SHARE_RANGE_FRIEND_ONLY = 2,
        PAWN_SHARE_RANGE_CRAN_ONLY = 3,
        PAWN_SHARE_RANGE_FRIEND_CRAN_ONLY = 4,
        PAWN_SHARE_RANGE_NOBODY = 5,
    };
}  // namespace nNet

namespace nNet {
    enum QUICK_MATCH_TYPE
    {
        QUICK_MATCH_TYPE_MAIN_QUEST = 0,
        QUICK_MATCH_TYPE_AREA = 1,
        QUICK_MATCH_TYPE_NEWSPAPER = 2,
    };
}  // namespace nNet

namespace nNet {
    enum SESSION_ID
    {
        SESSION_ID_GAME = 0,
        SESSION_ID_NUM = 1,
        SESSION_ID_LOBBY = 1,
        SESSION_ID_ALL = 2,
    };
}  // namespace nNet

namespace nNet {
    enum STATE
    {
        STATE_INIT = 0,
        STATE_RETRY = 1,
        STATE_WAIT = 2,
        STATE_SUCCESS = 3,
        STATE_ERROR = 4,
        STATE_ABORT = 5,
        STATE_END = 6,
        STATE_DEAD = 7,
    };
}  // namespace nNet

namespace nNetSv {
    enum E_CONTENT_TYPE
    {
        CONTENT_TYPE_BEGIN = 1,
        CONTENT_TYPE_NORMAL = 1,
        CONTENT_TYPE_WORLD_QUEST = 2,
        CONTENT_TYPE_CYCLE = 3,
        CONTENT_TYPE_END = 4,
        CONTENT_TYPE_ENTRY_DEBUG = 5,
        CONTENT_TYPE_QUICK_PARTY_MAIN_QUEST = 6,
        CONTENT_TYPE_QUICK_PARTY_AREA = 7,
        CONTENT_TYPE_LARGE = 8,
        CONTENT_TYPE_MAX = 9,
    };
}  // namespace nNetSv

namespace nNetSv {
    enum E_MAIL_TYPE
    {
        MAIL_TYPE_USER = 1,
        MAIL_TYPE_OPERATION = 2,
    };
}  // namespace nNetSv

namespace nNetSv {
    enum PARTY_SYNC_FLAG
    {
        PARTY_SYNC_01 = 1,
        PARTY_SYNC_02 = 2,
        PARTY_SYNC_03 = 3,
        PARTY_SYNC_04 = 4,
        PARTY_SYNC_05 = 5,
        PARTY_SYNC_06 = 6,
        PARTY_SYNC_07 = 7,
        PARTY_SYNC_NUM = 8,
    };
}  // namespace nNetSv

namespace nNetSv {
    enum PLAY_START_TYPE
    {
        PLAY_START_NORMAL = 0,
        PLAY_START_CYCLE_CONTENTS = 1,
    };
}  // namespace nNetSv

// Type aliases from DWARF
using CClanParam = CDataClanParam;
using CClanScoutEntryParam = CDataClanScoutEntryParam;
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CEntryItem = CDataEntryItem;
using CEntryItemParam = CDataEntryItemParam;
using CEntryMemberData = CDataEntryMemberData;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nNet {

    // Forward declarations
    struct stClanEmblem;
    class cProgress;
    class cResult;
    struct stEntryBoardItemInfo;
    struct stPawnFeedback;
    struct stFeedbackData;

    struct stClanEmblem
    {
    public:
        u8 mark;  // offset: 0x0
        u8 base;  // offset: 0x1
        u8 baseMainColor;  // offset: 0x2
        u8 baseSubColor;  // offset: 0x3
    };

    class cResult
    {
    public:
        cResult();
        virtual ~cResult();
        void init();
        void success();
        void error();
        void abort();
        bool isSuccess();
        bool isError();
        bool isAbort();
        MtNetError getError();
        void setError(MtNetError* err);
        void resetError();
    public:
        nNet::STATE mState;  // offset: 0x8
        MtNetError mError;  // offset: 0xc
    };

    struct stEntryBoardItemInfo
    {
    public:
        stEntryBoardItemInfo();
    public:
        u32 memberNum;  // offset: 0x0
        u32 memberNumMin;  // offset: 0x4
        u32 entryId;  // offset: 0x8
        MT_CHAR password[13];  // offset: 0xc
        MT_CHAR comment[109];  // offset: 0x19
        bool pawn;  // offset: 0x86
        bool isPassword;  // offset: 0x87
        u32 jobLevelMin;  // offset: 0x88
        u32 jobLevelMax;  // offset: 0x8c
        bool isJobLevelSetting;  // offset: 0x90
        bool isRecruitSetting;  // offset: 0x91
        bool isItemRankSetting;  // offset: 0x92
        u8 itemRankType;  // offset: 0x93
        u16 itemRankMin;  // offset: 0x94
        u16 requiredItemRank;  // offset: 0x96
        u32 itemRankCheckRoleType;  // offset: 0x98
        MtTypedArray<CDataEntryMemberData> MemberList;  // offset: 0xa0
        MtTypedArray<CDataEntryRecruitData> RecruitList;  // offset: 0xc0
    };

    struct stFeedbackData
    {
    public:
        bool mIsValid;  // offset: 0x0
        u8 mRank;  // offset: 0x1
        u8 mComment;  // offset: 0x2
    };

    class cProgress
    {
    public:
        enum CMD
        {
            CMD_CREATE_GAME = 65536,
            CMD_CREATE_LOBBY = 65537,
            CMD_SEARCH_GAME = 131072,
            CMD_JOIN_GAME = 196608,
            CMD_JOIN_LOBBY = 196609,
            CMD_ENTRY_GAME = 262144,
            CMD_START_GAME = 458752,
            CMD_FINAL_GAME = 589824,
            CMD_FINAL_LOBBY = 589825,
            CMD_ERROR = -1,
        };
        enum CTRL_IDX
        {
            CTRL_IDX_CREATE_SESSION = 0,
            CTRL_IDX_SEARCH_SESSION = 1,
            CTRL_IDX_JOIN_SESSION = 2,
            CTRL_IDX_ENTRY_SESSION = 3,
            CTRL_IDX_START_SESSION = 4,
            CTRL_IDX_END_SESSION = 5,
            CTRL_IDX_FINAL_SESSION_GAME = 6,
            CTRL_IDX_CREATE_LOBBY_SESSION = 7,
            CTRL_IDX_SEARCH_LOBBY = 8,
            CTRL_IDX_JOIN_LOBBY = 9,
            CTRL_IDX_FINAL_LOBBY = 10,
            CTRL_IDX_NONE = 4096,
            CTRL_IDX_ABORT = 4097,
            CTRL_IDX_CANCEL = 4098,
            CTRL_IDX_TIMEOUT = 4099,
            CTRL_IDX_END_DEBUG = 4100,
        };
        enum
        {
            CMD_ORDER_NONE = 0,
            CMD_ORDER_CREATE = 65536,
            CMD_ORDER_SEARCH = 131072,
            CMD_ORDER_JOIN = 196608,
            CMD_ORDER_ENTRY = 262144,
            CMD_ORDER_START = 458752,
            CMD_ORDER_FINAL = 589824,
            CMD_ORDER_MASK = -65536,
            CMD_VALUE_MASK = 255,
        };
    public:
        cProgress();
        virtual ~cProgress();
        void reset();
        void init();
        void setCommand(CMD cmd);
        void setCtrlIdx(CTRL_IDX ctrlIdx);
        void setState(nNet::STATE s);
        nNet::STATE getState();
        bool isProcess();
        CMD getCommand();
        CTRL_IDX getCtrlIdx();
        void setWaitFlag(bool b);
        bool getWaitFlag();
        void setFlag(bool);
        bool getFlag();
        void setValue(u32 v);
        u32 getValue();
        void setCancelFlag(bool b);
        bool getCancelFlag();
    public:
        CMD mCommand;  // offset: 0x8
        nNet::STATE mState;  // offset: 0xc
        CTRL_IDX mCtrlIdx;  // offset: 0x10
        nNet::cResult mResult;  // offset: 0x18
        nNet::cProgress* mpNext;  // offset: 0x30
        f32 mTimer;  // offset: 0x38
        bool mFlag;  // offset: 0x3c
        u32 mValue;  // offset: 0x40
        bool mWaitFlag;  // offset: 0x44
        bool mCancelFlag;  // offset: 0x45
    };

    struct stPawnFeedback
    {
    public:
        nNet::stFeedbackData mFeedbackData[3];  // offset: 0x0
    };

    void clearBaseInfo(CCommunityCharacterBaseInfo& info);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:118
    bool isOnline(u8 onlineStatus);
    void resetClanParam(CClanParam& param);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:176
    void copyClanParam2Emblem(const CClanParam& param, stClanEmblem& emblem);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:197
    void copyEmblem2ClanParam(stClanEmblem& emblem, CClanParam& param);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:208
    void resetClanScoutEntryParam(CClanScoutEntryParam& param);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:232
    void setRollBit(u32& itemRankCheckRoleType, nJob::E_ROLE_TYPE rollType);
    void resetEntryBoardInfo(stEntryBoardItemInfo& info);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:260
    u32 getRollBit(nJob::E_ROLE_TYPE rollType);
    void setEntryBoardMemberNum(stEntryBoardItemInfo& info, u32 num, u32 numMin);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:301
    bool compareEntryBoardMember(stEntryBoardItemInfo& info, stEntryBoardItemInfo& infoCom);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:336
    bool compareEntryBoardMember(stEntryBoardItemInfo& info, stEntryBoardItemInfo& infoCom, u32 index);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:357
    nHuman::ROLE_ENUM getCompareRole(stEntryBoardItemInfo& info, u32 index);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:397
    void setupRecommendEntryBoardMember(stEntryBoardItemInfo& info, u32 num, u32 numMin);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:450
    u32 getRecruitJobBit(MtTypedArray<CDataEntryRecruitData>& RecruitList, u32 no);
    void convBoardItemInfo(stEntryBoardItemInfo& info, const CEntryItem& item, MT_CTSTR password);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:543
    u32 getAllJobbit();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:613
    void convBoardItemInfoToParam(CEntryItemParam& param, stEntryBoardItemInfo& info);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:627
    const CEntryMemberData* getMemberInfo(stEntryBoardItemInfo& info, u32 characterId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:707
    void addMemberBoardItem(stEntryBoardItemInfo& info, const CEntryMemberData& member);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:723
    void removeMemberBoardItem(stEntryBoardItemInfo& info, const CEntryMemberData& member);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:738
    void setBoardItemInfoRecommend(stEntryBoardItemInfo& info);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:778
    void copyEntryBoardItemInfo(stEntryBoardItemInfo& to, const stEntryBoardItemInfo& from);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:818
    void clearRollBit(u32& itemRankCheckRoleType, nJob::E_ROLE_TYPE rollType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:889
    bool checkRollBit(u32 itemRankCheckRoleType, nJob::E_ROLE_TYPE rollType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:897
    void resetPawnFeedback(stPawnFeedback& feedback);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:908
    u32 getClientVersion();
    bool checkClientVersion(u32 ver);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nNet.cpp:951
    bool checkClanMotto(u32 motto, u32 index);
    void setClanMotto(u32& motto, u32 index);
    void clearClanMotto(u32& motto, u32 index);
    bool checkClanDay(u32 day, u32 index);
    void setClanDay(u32& day, u32 index);
    void clearClanDay(u32& day, u32 index);
    bool checkClanHour(u32 hour, u32 index);
    void setClanHour(u32& hour, u32 index);
    void clearClanHour(u32& hour, u32 index);
    bool checkClanFeature(u32 feature, u32 index);
    void setClanFeature(u32& feature, u32 index);
    void clearClanFeature(u32& feature, u32 index);

}  // namespace nNet

class CDataClientPartyListInfo : public CDataPartyListInfo
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
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
    explicit CDataClientPartyListInfo();
    explicit CDataClientPartyListInfo(const CCommunityCharacterBaseInfo&);
    // Address: 0x01a3b630 - 0x01a3b631 (1 bytes)
    virtual void createProperty(MtPropertyList& s) {}  // vtable slot 4
public:
    CCommunityCharacterBaseInfo m_LeaderBaseInfo;  // offset: 0x40
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool nNet::cProgress::getWaitFlag() {
    return this->mWaitFlag;
}

// Inline, no code of its own: checked where it is inlined.
inline bool nNet::cProgress::getCancelFlag() {
    return this->mCancelFlag;
}
