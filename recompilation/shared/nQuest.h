#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "MtTime.h"
#include "nMarker.h"

// Forward declarations
class CDataQuestCommand;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtTime;
class MtUI;
class MtVector3;
class cContextInstHm;
class cQuestTask;
namespace nMarker { class cMarkerInfo; }
class rGUIMessage;

// Declarations
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class QUEST_ID; }
namespace nQuest { class cQuestInfoBase; }
namespace nQuest { class cOrderCondition; }
namespace nQuest { class cRepeatBonus; }
namespace nQuest { class cRewardData; }
namespace nQuest { class cFixRewardData; }
namespace nQuest { class cDeliverRequestItemInfo; }
namespace nQuest { class cQuestDeliverRequestInfo; }
namespace nQuest { class cDeliveredItemInfo; }
namespace nQuest { class cQuestDeliveredInfo; }
namespace nQuest { class cQuestMarker; }
namespace nQuest { class cCycleContentsPersonalRankInfo; }
namespace nQuest { class cCycleContentsInfo; }
namespace nQuest { class cGUINewspaperSetQuestMonsterInfo; }
namespace nQuest { class cGUINewspaperSetQuestItemInfo; }
namespace nQuest { class cGUINewspaperSetQuestInfo; }
namespace nQuest { class cGUINewspaperRecommededQuestInfo; }
namespace nQuest { class cGUINewspaperSetQuestOpenDateInfo; }
namespace nQuest { class cCycleContentsResultPointInfo; }
namespace nQuest { class cCycleContentsResultRewardInfo; }
namespace nQuest { class cCycleContentsResultInfo; }
namespace nQuest { class cCycleContentsRankingInfo; }
namespace nQuest { class cCycleContentsRankingRewardInfo; }
namespace nQuest { class cCycleContentsBorderRewardInfo; }
namespace nQuest { class cQuestCommand; }
namespace nQuest { class cTalkData; }
namespace nQuest { class cDeliverTargetInfo; }
namespace nQuest { class cGUIListData; }
namespace nQuest { class cGUIInfoData; }
namespace nQuest { class cGUIBoardData; }
namespace nQuest { class cGUIDeliveryData; }
namespace nQuest { class cGUIEventBoardData; }
namespace nQuest { class cGUIAreaMasterData; }
namespace nQuest { class cGUIActiveData; }
namespace nQuest { class cCycleContentsSituationInfo; }
namespace nQuest { class cEndContentsGroupQuestInfo; }
namespace nQuest { class cTargetEnemyInfo; }
namespace nQuest { class cScheduleInfo; }
namespace nQuest { class cPartyBonusInfo; }
namespace nQuest { class cGUINewspaperSetQuestInfoList; }
namespace nQuest { class TargetEnemyInfoArray; }
namespace nQuest { class QuestCommandList; }

namespace nQuest {
    enum ACTIVE_QUEST_TYPE
    {
        ACTIVE_QUEST_TYPE_MYSELF = 0,
        ACTIVE_QUEST_TYPE_PARTY = 1,
        ACTIVE_QUEST_TYPE_NUM = 2,
    };
}  // namespace nQuest

namespace nQuest {
    enum CYCLE_CONTENTS_CATEGORY
    {
        CYCLE_CONTENTS_CATEGORY_NONE = 0,
        CYCLE_CONTENTS_CATEGORY_FORT_DEFENSE = 1,
        CYCLE_CONTENTS_CATEGORY_RAID_BOSS = 3,
    };
}  // namespace nQuest

namespace nQuest {
    enum CYCLE_CONTENTS_NOTICE_TYPE
    {
        CYCLE_CONTENTS_NOTICE_TYPE_NONE = 0,
        CYCLE_CONTENTS_NOTICE_TYPE_PREPARATION = 1,
        CYCLE_CONTENTS_NOTICE_TYPE_HOLDING = 2,
        CYCLE_CONTENTS_NOTICE_TYPE_RANKING = 3,
        CYCLE_CONTENTS_NOTICE_TYPE_RECEIVING = 4,
        CYCLE_CONTENTS_NOTICE_TYPE_THROUGHOUT = 5,
        CYCLE_CONTENTS_NOTICE_TYPE_CONTENTS_01 = 6,
        CYCLE_CONTENTS_NOTICE_TYPE_CONTENTS_02 = 7,
        CYCLE_CONTENTS_NOTICE_TYPE_CONTENTS_03 = 8,
        CYCLE_CONTENTS_NOTICE_TYPE_CONTENTS_04 = 9,
        CYCLE_CONTENTS_NOTICE_TYPE_CONTENTS_05 = 10,
        CYCLE_CONTENTS_NOTICE_TYPE_CONTENTS_06 = 11,
        CYCLE_CONTENTS_NOTICE_TYPE_CONTENTS_07 = 12,
    };
}  // namespace nQuest

namespace nQuest {
    enum CYCLE_CONTENTS_PERIOD
    {
        CYCLE_CONTENTS_PERIOD_NONE = 0,
        CYCLE_CONTENTS_PERIOD_PREPARATION = 1,
        CYCLE_CONTENTS_PERIOD_HOLDING = 2,
        CYCLE_CONTENTS_PERIOD_RANKING = 3,
        CYCLE_CONTENTS_PERIOD_RECEIVING = 4,
    };
}  // namespace nQuest

namespace nQuest {
    enum CYCLE_CONTENTS_SUB_CATEGORY
    {
        CYCLE_CONTENTS_SUB_CATEGORY_NONE = 0,
        CYCLE_CONTENTS_SUB_CATEGORY_FORT_DEFENSE_NORMAL = 1001,
        CYCLE_CONTENTS_SUB_CATEGORY_FORT_DEFENSE_NEST = 1002,
        CYCLE_CONTENTS_SUB_CATEGORY_FORT_DEFENSE_BORD = 1003,
        CYCLE_CONTENTS_SUB_CATEGORY_FORT_DEFENSE_SHRINE = 1004,
        CYCLE_CONTENTS_SUB_CATEGORY_RAID_FOREST = 3002,
        CYCLE_CONTENTS_SUB_CATEGORY_RAID_GOLD_DRAGON = 3003,
        CYCLE_CONTENTS_SUB_CATEGORY_RAID_ZULU = 3004,
        CYCLE_CONTENTS_SUB_CATEGORY_RAID_FOREST_GOLD = 3005,
        CYCLE_CONTENTS_SUB_CATEGORY_RAID_ZULU_SECOND = 3006,
    };
}  // namespace nQuest

namespace nQuest {
    enum CYCLE_CONTENTS_TYPE
    {
        CYCLE_CONTENTS_TYPE_NONE = 0,
        CYCLE_CONTENTS_TYPE_FORT_DEFENSE = 1,
        CYCLE_CONTENTS_TYPE_DRAGON_NEST = 2,
        CYCLE_CONTENTS_TYPE_RAID_FOREST = 3,
        CYCLE_CONTENTS_TYPE_RAID_GOLD_DRAGON = 4,
        CYCLE_CONTENTS_TYPE_RAID_ZULU = 5,
        CYCLE_CONTENTS_TYPE_BORD_TUNNEL = 6,
        CYCLE_CONTENTS_TYPE_RAID_ZULU_SECOND = 7,
        CYCLE_CONTENTS_TYPE_SHRINE = 8,
        CYCLE_CONTENTS_TYPE_NUM_ALL = 9,
    };
}  // namespace nQuest

namespace nQuest {
    enum END_CONTENTS_GROUP
    {
        END_CONTENTS_GROUP_01 = 1,
        END_CONTENTS_GROUP_02 = 2,
        END_CONTENTS_GROUP_TIME_ATTACK = 3,
        END_CONTENTS_GROUP_CLAN_DUNGEON = 4,
        END_CONTENTS_GROUP_NUM = 4,
    };
}  // namespace nQuest

namespace nQuest {
    enum E_CYCLE_CONTENTS_REWARD_TYPE
    {
        CYCLE_CONTENTS_REWARD_TYPE_UNKNOWN = 0,
        CYCLE_CONTENTS_REWARD_TYPE_BORDER = 1,
        CYCLE_CONTENTS_REWARD_TYPE_RANKING = 2,
        CYCLE_CONTENTS_REWARD_TYPE_NUM = 3,
    };
}  // namespace nQuest

namespace nQuest {
    enum FUNCTION_TYPE
    {
        FUNCTION_TYPE_PRT = 0,
        FUNCTION_TYPE_MEMORY_POOL = 1,
        FUNCTION_TYPE_MARKER = 2,
        FUNCTION_TYPE_ACTIVE_QUEST = 3,
        FUNCTION_TYPE_RESOURCE = 4,
        FUNCTION_TYPE_RESOURCE_LOAD = 5,
        FUNCTION_TYPE_SV_REQUEST = 6,
        FUNCTION_TYPE_SV_NOTICE = 7,
        FUNCTION_TYPE_DELIVER = 8,
        FUNCTION_TYPE_AREA_RELEASE = 9,
        FUNCTION_TYPE_PARTY = 10,
        FUNCTION_TYPE_EVENT = 11,
        FUNCTION_TYPE_PHASE = 12,
        FUNCTION_TYPE_NUM = 13,
    };
}  // namespace nQuest

namespace nQuest {
    enum LOT_QUEST_TYPE
    {
        LOT_QUESt_TYPE_NONE = 0,
        LOT_QUEST_TYPE_PAWN = 1,
        LOT_QUEST_TYPE_NUM = 2,
    };
}  // namespace nQuest

namespace nQuest {
    enum MARKER_DISP_TYPE
    {
        MARKER_DISP_TYPE_LAYOUT_NPC = 0,
        MARKER_DISP_TYPE_QUEST_NPC = 1,
        MARKER_DISP_TYPE_NPC_UNIT = 2,
        MARKER_DISP_TYPE_ENEMY_ENCOUNT_AREA = 3,
        MARKER_DISP_TYPE_SCENARIO = 4,
        MARKER_DISP_TYPE_QUEST_OM = 5,
        MARKER_DISP_TYPE_STAGE = 6,
        MARKER_DISP_TYPE_PRT = 7,
        MARKER_DISP_TYPE_WHITE_DRAGON = 8,
        MARKER_DISP_TYPE_QUEST_BOARD = 9,
        MARKER_DISP_TYPE_WARP_POINT = 10,
        MARKER_DISP_TYPE_ARCHIBALD = 11,
        MARKER_DISP_TYPE_WAREHOUSE = 12,
        MARKER_DISP_TYPE_ENEMY_ENCOUNT_AREA_GM_MAIN = 13,
        MARKER_DISP_TYPE_ENEMY_ENCOUNT_AREA_GM_SUB = 14,
        MARKER_DISP_TYPE_MYROOM_RIMSTONE = 15,
        MARKER_DISP_TYPE_MYROOM_PARTERPAWN = 16,
        MARKER_DISP_TYPE_LAYOUT_OM = 17,
        MARKER_DISP_TYPE_CLAN_QUEST_BOARD = 18,
        MARKER_DISP_TYPE_PHOTO = 19,
        MARKER_DISP_TYPE_RENTEN = 20,
        MARKER_DISP_TYPE_NUM = 21,
        MARKER_DISP_TYPE_INVALID_VALUE = 21,
    };
}  // namespace nQuest

namespace nQuest {
    enum NOTICE_TYPE
    {
        NOTICE_TYPE_TALK_END = 0,
        NOTICE_TYPE_RELOAD_MASTER_DATA = 1,
        NOTICE_TYPE_ADD_ITEM = 2,
        NOTICE_TYPE_TOUCH_OM = 3,
        NOTICE_TYPE_RELEASE_OM = 4,
        NOTICE_TYPE_CLEAR_SET_QUEST = 5,
        NOTICE_TYPE_ENTRY_PARTY = 6,
        NOTICE_TYPE_LEAVE_PARTY = 7,
        NOTICE_TYPE_DOGMA_ORB = 8,
        NOTICE_TYPE_EV_BOARD_QUEST_ACCEPTED = 9,
        NOTICE_TYPE_TOUCH_EV_BOARD = 10,
        NOTICE_TYPE_OPEN_ENTRY_RAID_BOSS = 11,
        NOTICE_TYPE_OPEN_ENTRY_FORT_DEFENSE = 12,
        NOTICE_TYPE_OPEN_JOB_MASTER = 13,
        NOTICE_TYPE_TOUCH_RIM_STONE = 14,
        NOTICE_TYPE_GET_ACHIEVEMENT = 15,
        NOTICE_TYPE_END_TALK_SPECIAL = 16,
        NOTICE_TYPE_CLEAR_QUEST = 17,
        NOTICE_TYPE_END_TEXT_OM = 18,
        NOTICE_TYPE_SET_SKILL = 19,
        NOTICE_TYPE_OPEN_AREA_MASTER = 20,
        NOTICE_TYPE_OPEN_NEWSPAPER = 21,
        NOTICE_TYPE_OPEN_QUEST_BOARD = 22,
        NOTICE_TYPE_ORDER_LIGHT_QUEST = 23,
        NOTICE_TYPE_ORDER_WORLD_QUEST = 24,
        NOTICE_TYPE_LOST_MAIN_PAWN = 25,
        NOTICE_TYPE_IS_HUGEBLE = 26,
        NOTICE_TYPE_OPEN_AREA_MASTER_SUPPLIES = 27,
        NOTICE_TYPE_OPEN_ENTRY_BOARD = 28,
        NOTICE_TYPE_NOTICE_INTERRUPT_CONTENTS = 29,
        NOTICE_TYPE_OPEN_RETRY_SELECT = 30,
        NOTICE_TYPE_NOTICE_PARTY_INVITE = 31,
        NOTICE_TYPE_KILLED_AREA_BOSS = 32,
        NOTICE_TYPE_PARTY_REWARD = 33,
        NOTICE_TYPE_OPEN_CRAFT_EXAM = 34,
        NOTICE_TYPE_LEVEL_UP_CRAFT = 35,
        NOTICE_TYPE_CLEAR_LIGHT_QUEST = 36,
        NOTICE_TYPE_OPEN_JOB_MASTER_REWARD = 37,
        NOTICE_TYPE_OPEN_WAREHOUSE = 38,
        NOTICE_TYPE_OPEN_REWARD_BOX = 39,
        NOTICE_TYPE_CLAN_SEARCH = 40,
        NOTICE_TYPE_OPEN_AREALIST = 41,
        NOTICE_TYPE_PRESENT_PARTNER_PAWN = 42,
        NOTICE_TYPE_RELEASE_PORTAL = 43,
        NOTICE_TYPE_HAS_APPRAISE_ITEM = 44,
        NOTICE_TYPE_ORDER_PAWN_QUEST = 45,
        NOTICE_TYPE_OPEN_PP_SHOP = 46,
        NOTICE_TYPE_TOUCH_CLAN_BOARD = 47,
        NOTICE_TYPE_ONE_OFF_GHATER = 48,
        NOTICE_TYPE_MAX = 64,
    };
}  // namespace nQuest

namespace nQuest {
    enum ORDER_CONDITION_TYPE
    {
        ORDER_CONDITION_TYPE_NONE = 0,
        ORDER_CONDITION_TYPE_MAX_LEVEL = 1,
        ORDER_CONDITION_TYPE_JOB_LEVEL = 2,
        ORDER_CONDITION_TYPE_SOLO = 3,
        ORDER_CONDITION_TYPE_MAIN_QUEST_CLEAR = 6,
        ORDER_CONDITION_TYPE_TUTORIAL_QUEST_CLEAR = 7,
        ORDER_CONDITION_TYPE_END_QUEST_CLEAR = 8,
        ORDER_CONDITION_TYPE_AREAMASTER_RANK = 9,
        ORDER_CONDITION_TYPE_SOLO_WITH_PAWN = 10,
        ORDER_CONDITION_TYPE_TUTOR_QUEST_GROUP_01 = 11,
        ORDER_CONDITION_TYPE_TUTOR_QUEST_GROUP_02 = 12,
        ORDER_CONDITION_TYPE_PARTNER_PAWN = 14,
        ORDER_CONDITION_TYPE_NUM = 15,
    };
}  // namespace nQuest

namespace nQuest {
    enum QUEST_BOARD_TYPE
    {
        QUEST_BOARD_TYPE_NORMAL = 1,
        QUEST_BOARD_TYPE_CLAN = 2,
        QUEST_BOARD_TYPE_NUM = 3,
    };
}  // namespace nQuest

namespace nQuest {
    enum QUEST_REWARD_TYPE
    {
        QUEST_REWARD_TYPE_UNKNOWN = 0,
        QUEST_REWARD_TYPE_FIXED = 1,
        QUEST_REWARD_TYPE_SELECT = 2,
        QUEST_REWARD_TYPE_UNDISCOVERY = 3,
        QUEST_REWARD_TYPE_RANDOM = 4,
        QUEST_REWARD_TYPE_REPEAT = 5,
        QUEST_REWARD_TYPE_SWITCH = 6,
        QUEST_REWARD_TYPE_BORDER = 7,
        QUEST_REWARD_TYPE_RANKING = 8,
        QUEST_REWARD_TYPE_CHARGE = 9,
        QUEST_REWARD_TYPE_REGION_BREAK = 10,
        QUEST_REWARD_TYPE_FIXED_FIRST = 11,
        QUEST_REWARD_TYPE_FIXED_SECOND = 12,
        QUEST_REWARD_TYPE_FIXED_MEMBER_FIRST = 13,
        QUEST_REWARD_TYPE_PROGRESS_BONUS = 14,
        QUEST_REWARD_TYPE_NUM = 15,
    };
}  // namespace nQuest

namespace nQuest {
    enum QUEST_TEXT_TYPE
    {
        QUEST_TEXT_TYPE_NAME = 0,
        QUEST_TEXT_TYPE_ORDER = 1,
        QUEST_TEXT_TYPE_PURPOSE = 2,
        QUEST_TEXT_TYPE_FIND_INFO = 3,
        QUEST_TEXT_TYPE_FIND_INFO_DETAIL = 4,
        QUEST_TEXT_TYPE_CONTENTS_DETAIL = 5,
        QUEST_TEXT_TYPE_REWARD_NAME = 6,
        QUEST_TEXT_TYPE_GM_INFO = 7,
        QUEST_TEXT_TYPE_SAY_PATTERN = 8,
        QUEST_TEXT_TYPE_NUM = 9,
    };
}  // namespace nQuest

namespace nQuest {
    enum QUEST_TYPE
    {
        QUEST_TYPE_MAIN = 0,
        QUEST_TYPE_SET = 1,
        QUEST_TYPE_LIGHT = 2,
        QUEST_TYPE_TUTORIAL = 3,
        QUEST_TYPE_TIME_LIMITED = 4,
        QUEST_TYPE_NUM = 5,
        QUEST_TYPE_WORLD_SETTING = 5,
        QUEST_TYPE_CYCLE_01 = 6,
        QUEST_TYPE_CYCLE_04 = 7,
        QUEST_TYPE_END_CONTENTS = 8,
        QUEST_TYPE_CCYCLE_SUB_CATEGORY = 9,
        QUEST_TYPE_PAWN = 10,
        QUEST_TYPE_DEBUG_TOOL = 11,
        QUEST_TYPE_MANAGER_NUM = 12,
    };
}  // namespace nQuest

namespace nQuest {
    enum QUEST_UI_DISP_TYPE
    {
        QUEST_UI_DISP_TYPE_MAIN = 0,
        QUEST_UI_DISP_TYPE_SET = 1,
        QUEST_UI_DISP_TYPE_LIGHT = 2,
        QUEST_UI_DISP_TYPE_TUTORIAL = 3,
        QUEST_UI_DISP_TYPE_PAWN = 4,
        QUEST_UI_DISP_TYPE_NUM = 5,
        QUEST_UI_DISP_TYPE_INVALID = 5,
    };
}  // namespace nQuest

namespace nQuest {
    enum REPEAT_BONUS_TYPE
    {
        REPEAT_BONUS_TYPE_NONE = 0,
        REPEAT_BONUS_TYPE_EXP_UP = 1,
        REPEAT_BONUS_TYPE_AREA_PT_UP = 7,
        REPEAT_BONUS_TYPE_RIM_UP = 8,
        REPEAT_BONUS_TYPE_GOLD_UP = 9,
        REPEAT_BONUS_TYPE_RAND_REWARD_UP = 10,
        REPEAT_BONUS_TYPE_NUM = 11,
    };
}  // namespace nQuest

namespace nQuest {
    enum RET_DISABLE_ORDER_CONDITION_TYPE
    {
        RET_DIS_ORDER_CONDITION_TYPE_NONE = 0,
        RET_DIS_ORDER_CONDITION_TYPE_QUEST_ORDER_MAX = 1,
        RET_DIS_ORDER_CONDITION_TYPE_MAX_LEVEL = 2,
        RET_DIS_ORDER_CONDITION_TYPE_JOB_LEVEL = 4,
        RET_DIS_ORDER_CONDITION_TYPE_SOLO = 8,
        RET_DIS_ORDER_CONDITION_TYPE_MAIN_QUEST_CLEAR = 16,
        RET_DIS_ORDER_CONDITION_TYPE_TUTORIAL_QUEST_CLEAR = 32,
        RET_DIS_ORDER_CONDITION_TYPE_END_QUEST_CLEAR = 64,
        RET_DIS_ORDER_CONDITION_TYPE_AREAMASTER_RANK = 128,
        RET_DIS_ORDER_CONDITION_TYPE_SOLO_WITH_PAWN = 256,
        RET_DIS_ORDER_CONDITION_TYPE_TUTOR_QUEST_GROUP_01 = 512,
        RET_DIS_ORDER_CONDITION_TYPE_TUTOR_QUEST_GROUP_02 = 1024,
        RET_DIS_ORDER_CONDITION_TYPE_OUT_LEADER = 2048,
        RET_DIS_ORDER_CONDITION_TYPE_UNKNOWN = 4096,
        RET_DIS_ORDER_CONDITION_TYPE_CANNOT_PROGRESS_LEADER = 8192,
        RET_DIS_ORDER_CONDITION_TYPE_PARTY_LARGE = 16384,
        RET_DIS_ORDER_CONDITION_TYPE_PARTNER_PAWN = 32768,
        RET_DIS_ORDER_CONDITION_TYPE_WQ_UNRELEASED_AREA = 65536,
    };
}  // namespace nQuest

namespace nQuest {
    enum SV_QUEST_TYPE
    {
        SV_QUEST_TYPE_UNKNOWN = 0,
        SV_QUEST_TYPE_LIGHT = 1,
        SV_QUEST_TYPE_SET = 2,
        SV_QUEST_TYPE_MAIN = 3,
        SV_QUEST_TYPE_TUTORIAL = 4,
        SV_QUEST_TYPE_TIME_LIMITED = 5,
        SV_QUEST_TYPE_CYCLE_CONTENTS = 6,
        SV_QUEST_TYPE_CYCLE_CONTENTS_QUEST = 7,
        SV_QUEST_TYPE_WORLD_MANAGE = 8,
        SV_QUEST_TYPE_TIME_GAIN = 9,
        SV_QUEST_TYPE_NUM = 10,
    };
}  // namespace nQuest

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
namespace nQuest { using CycleContentsPersonalRankInfoArray = MtTypedArray<nQuest::cCycleContentsPersonalRankInfo>; }
namespace nQuest { using CycleContentsResultPointInfoArray = MtTypedArray<nQuest::cCycleContentsResultPointInfo>; }
namespace nQuest { using CycleContentsResultRewardList = MtTypedArray<nQuest::cCycleContentsResultRewardInfo>; }
namespace nQuest { using OrderConditionArray = MtTypedArray<nQuest::cOrderCondition>; }
namespace nQuest { using cGUINewspaperSetQuestItemInfoArray = MtTypedArray<nQuest::cGUINewspaperSetQuestItemInfo>; }
namespace nQuest { using cGUINewspaperSetQuestMonsterInfoArray = MtTypedArray<nQuest::cGUINewspaperSetQuestMonsterInfo>; }
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nQuest {

    enum
    {
        LIGHT_QUEST_TEXT_TARGET_COLOR_R = 230,
        LIGHT_QUEST_TEXT_TARGET_COLOR_G = 190,
        LIGHT_QUEST_TEXT_TARGET_COLOR_B = 30,
        PRICE_TEXT_COLOR_R = 185,
        PRICE_TEXT_COLOR_G = 40,
        PRICE_TEXT_COLOR_B = 40,
        ORDER_DISABLE_COLOR_R = 170,
        ORDER_DISABLE_COLOR_G = 20,
        ORDER_DISABLE_COLOR_B = 20,
    };

    enum
    {
        ORDER_CONDITION_MAX_NUM = 3,
        SELECT_REWARD_MAX_NUM = 5,
        USER_SELECT_REWARD_MAX_NUM = 1,
        FIX_REWARD_MAX_NUM = 8,
        RANDOM_REWARD_TBL_NUM = 3,
        ACTIVE_QUEST_SAVE_NUM = 3,
        CONTENTS_REWARD_MAX_NUM = 7,
        REWARDLIST_MAX_NUM = 100,
    };

    enum
    {
        WAIT_ORDER_MAX_NUM = 5,
    };

    enum
    {
        QUEST_ANNOUNCE_TYPE_ACCEPT = 0,
        QUEST_ANNOUNCE_TYPE_CLEAR = 1,
        QUEST_ANNOUNCE_TYPE_FAILED = 2,
        QUEST_ANNOUNCE_TYPE_UPDATE = 3,
        QUEST_ANNOUNCE_TYPE_DISCOVERED = 4,
        QUEST_ANNOUNCE_TYPE_CAUTION = 5,
        QUEST_ANNOUNCE_TYPE_START = 6,
        QUEST_ANNOUNCE_TYPE_EX_UPDATE = 7,
        QUEST_ANNOUNCE_TYPE_END = 8,
        QUEST_ANNOUNCE_TYPE_STAGE_START = 9,
        QUEST_ANNOUNCE_TYPE_STAGE_CLEAR = 10,
        QUEST_ANNOUNCE_TYPE_CANCEL = 11,
    };

    enum
    {
        LIGHT_QUEST_TARGET_ENEMY = 0,
        LIGHT_QUEST_TARGET_ITEM = 1,
        LIGHT_QUEST_TARGET_ITEM_DELIVERY = 2,
        LIGHT_QUEST_TARGET_NUM = 3,
    };

    enum
    {
        CALL_MESSAGE_TYPE_QUEST = 1,
        MSG_RANDOM_NUM = 4,
    };

    enum
    {
        FSM_BOOT_TYPE_CAMERA = 0,
        FSM_BOOT_TYPE_ORDER = 1,
    };

    // Forward declarations
    class SCHEDULE_ID;
    class QUEST_ID;
    class cQuestInfoBase;
    class cOrderCondition;
    class cRepeatBonus;
    class cRewardData;
    class cFixRewardData;
    class cDeliverRequestItemInfo;
    class cQuestDeliverRequestInfo;
    class cDeliveredItemInfo;
    class cQuestDeliveredInfo;
    class cQuestMarker;
    class cCycleContentsPersonalRankInfo;
    class cCycleContentsInfo;
    class cGUINewspaperSetQuestMonsterInfo;
    class cGUINewspaperSetQuestItemInfo;
    class cGUINewspaperSetQuestInfo;
    class cGUINewspaperRecommededQuestInfo;
    class cGUINewspaperSetQuestOpenDateInfo;
    class cCycleContentsResultPointInfo;
    class cCycleContentsResultRewardInfo;
    class cCycleContentsResultInfo;
    class cCycleContentsRankingInfo;
    class cCycleContentsRankingRewardInfo;
    class cCycleContentsBorderRewardInfo;
    class cQuestCommand;
    class cTalkData;
    class cDeliverTargetInfo;
    class cGUIListData;
    class cGUIInfoData;
    class cGUIBoardData;
    class cGUIDeliveryData;
    class cGUIEventBoardData;
    class cGUIAreaMasterData;
    class cGUIActiveData;
    class cCycleContentsSituationInfo;
    class cEndContentsGroupQuestInfo;
    class cTargetEnemyInfo;
    class cScheduleInfo;
    class cPartyBonusInfo;
    class cGUINewspaperSetQuestInfoList;
    class TargetEnemyInfoArray;
    class QuestCommandList;

    class SCHEDULE_ID : public ::MtObject
    {
    public:
        operator unsigned int() const;
        bool operator==(nQuest::SCHEDULE_ID id) const;
        bool operator!=(nQuest::SCHEDULE_ID id) const;
    protected:
        bool operator==(u32 id) const;
        bool operator!=(u32 id) const;
    public:
        u32 toU32() const;
        SCHEDULE_ID();
        explicit SCHEDULE_ID(u32 scheduleId);
        virtual ~SCHEDULE_ID();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mScheduleId;  // offset: 0x8
    };

    class QUEST_ID : public ::MtObject
    {
        // inferred: nQuest::cQuestMarker::getQuestIdU32 names nQuest::cQuestMarker::mQuestId.mQuestId
        friend class nQuest::cQuestMarker;
    public:
        operator unsigned int() const;
        bool operator==(nQuest::QUEST_ID id) const;
        bool operator!=(nQuest::QUEST_ID id) const;
    protected:
        bool operator==(u32 id) const;
        bool operator!=(u32 id) const;
    public:
        u32 toU32() const;
        QUEST_ID();
        explicit QUEST_ID(u32 questId);
        virtual ~QUEST_ID();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mQuestId;  // offset: 0x8
    };

    class cQuestInfoBase : public ::MtObject
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
    public:
        static MyDTI DTI;
    };

    class cOrderCondition : public nQuest::cQuestInfoBase
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
        nQuest::ORDER_CONDITION_TYPE getConditionType() const;
        u32 getConditionParam1() const;
        u32 getConditionParam2() const;
        MT_CTSTR getConditionParam1Message() const;
        MT_CTSTR getConditionParam2Message() const;
        cOrderCondition();
        cOrderCondition(u8 type, u32 param1, u32 param2);
        virtual ~cOrderCondition();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void updateConditionMessage();
        bool loadConditionInfo();
    protected:
        MtString mConditionParam1Message;  // offset: 0x8
        MtString mConditionParam2Message;  // offset: 0x10
        u32 mConditionParam1;  // offset: 0x18
        u32 mConditionParam2;  // offset: 0x1c
        u8 mConditionType;  // offset: 0x20
        bool mIsMsgCreated;  // offset: 0x21
    public:
        static MyDTI DTI;
    };

    class cRepeatBonus : public nQuest::cQuestInfoBase
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
        cRepeatBonus();
        virtual ~cRepeatBonus();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mType;  // offset: 0x8
        u32 mParam;  // offset: 0xc
        u32 mNum;  // offset: 0x10
        static MyDTI DTI;
    };

    class cRewardData : public nQuest::cQuestInfoBase
    {
        // inferred: nQuest::cFixRewardData::getItemId names nQuest::cRewardData::mItemId
        friend class nQuest::cFixRewardData;
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
        u32 getItemId() const;
        nQuest::cRewardData& setItemId(u32 itemId);
        u32 getItemNum() const;
        nQuest::cRewardData& setItemNum(u32 itemNum);
        cRewardData();
        cRewardData(u32 itemId, u32 itemNum);
        virtual ~cRewardData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mItemId;  // offset: 0x8
        u32 mItemNum;  // offset: 0xc
    public:
        static MyDTI DTI;
    };

    class cFixRewardData : public nQuest::cQuestInfoBase
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
        u32 getItemId(u32 idx) const;
        nQuest::cFixRewardData& setItemId(u32 idx, u32 itemId);
        u32 getItemNum(u32 idx) const;
        nQuest::cFixRewardData& setItemNum(u32 idx, u32 itemNum);
        const nQuest::cRewardData* getRewardData(u32 idx) const;
        nQuest::cFixRewardData& setRewardData(u32 idx, const nQuest::cRewardData& rewardData);
        cFixRewardData();
        virtual ~cFixRewardData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::cRewardData mRewardData[5];  // offset: 0x8
    public:
        static MyDTI DTI;
    };

    class cDeliverRequestItemInfo : public nQuest::cQuestInfoBase
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
        cDeliverRequestItemInfo();
        // Address: 0x01a6dbb0 - 0x01a6dbb1 (1 bytes)
        virtual ~cDeliverRequestItemInfo() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mItemId;  // offset: 0x8
        u16 mNeedItemNum;  // offset: 0xc
        static MyDTI DTI;
    };

    class cQuestDeliverRequestInfo : public nQuest::cQuestInfoBase
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
        cQuestDeliverRequestInfo();
        cQuestDeliverRequestInfo(const nQuest::cQuestDeliverRequestInfo& obj);
        virtual ~cQuestDeliverRequestInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        MtTypedArray<nQuest::cDeliverRequestItemInfo> mItemList;  // offset: 0x8
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
    public:
        static MyDTI DTI;
    };

    class cDeliveredItemInfo : public nQuest::cQuestInfoBase
    {
    public:
        enum
        {
            TYPE_SOLO = 0,
            TYPE_PARTY = 1,
        };
    public:
        class MyDTI;
        class cDeliverCharacterInfo;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cDeliverCharacterInfo : public ::MtObject
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
            cDeliverCharacterInfo();
            // Address: 0x01982190 - 0x01982191 (1 bytes)
            virtual ~cDeliverCharacterInfo() {}
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        public:
            u32 mCharacterId;  // offset: 0x8
            u16 mItemNum;  // offset: 0xc
            static MyDTI DTI;
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
        cDeliveredItemInfo();
        virtual ~cDeliveredItemInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mItemId;  // offset: 0x8
        u16 mNeedItemNum;  // offset: 0xc
        u8 mType;  // offset: 0xe
        MtTypedArray<cDeliverCharacterInfo> mCharacterDeliverInfo;  // offset: 0x10
        static MyDTI DTI;
    };

    class cQuestDeliveredInfo : public nQuest::cQuestInfoBase
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
        cQuestDeliveredInfo();
        virtual ~cQuestDeliveredInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        MtTypedArray<nQuest::cDeliveredItemInfo> mItemList;  // offset: 0x8
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
    public:
        static MyDTI DTI;
    };

    class cQuestMarker : public nQuest::cQuestInfoBase
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
        const nMarker::cMarkerInfo& getMarkerInfo() const;
        const nMarker::cMarkerInfo* getMarkerInfoPtr() const;
        void setPosition(const MtVector3& pos);
        bool isActive() const;
        void setActive(bool active);
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        void setQuestId(nQuest::QUEST_ID questId);
        nQuest::SCHEDULE_ID getScheduleId() const;
        u32 getScheduleIdU32() const;
        void setScheduleId(nQuest::SCHEDULE_ID scheduleId);
        u32 getTargetType() const;
        void setTargetType(u32 targetType);
        nQuest::QUEST_TYPE getQuestType() const;
        bool isOrder() const;
        void setIsOrder(bool isOrder);
        s32 getStageNo() const;
        void setStageNo(s32 stageNo);
        u32 getGroupNo() const;
        void setGroupNo(u32 groupNo);
        s16 getMapGroupNo() const;
        void setMapGroupNo(s16 mapGroupNo);
        void setQuestType(nQuest::QUEST_TYPE questType);
        cQuestMarker();
        virtual ~cQuestMarker();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    private:
        nMarker::cMarkerInfo mMarkerInfo;  // offset: 0x8
        nQuest::QUEST_ID mQuestId;  // offset: 0x58
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x68
        u32 mGroupNo;  // offset: 0x78
        s16 mMapGroupNo;  // offset: 0x7c
        u8 mQuestType;  // offset: 0x7e
        u8 mTargetType;  // offset: 0x7f
        bool mIsActive;  // offset: 0x80
        bool mIsOrder;  // offset: 0x81
    public:
        static MyDTI DTI;
    };

    class cCycleContentsPersonalRankInfo : public nQuest::cQuestInfoBase
    {
    public:
        enum
        {
            CONTENTS_PERSONAL_RANK_TYPE_NONE = 0,
            CONTENTS_PERSONAL_RANK_TYPE_SCORE_TOTAL = 1,
            CONTENTS_PERSONAL_RANK_TYPE_SCORE_ATTACK = 2,
        };
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
        u8 getContentType() const;
        u32 getRanking() const;
        u32 getScore() const;
        MtTime getUpdateTime() const;
        void setContentType(u8);
        void setRanking(u32);
        void setScore(u32);
        void setUpdateTime(MtTime);
        cCycleContentsPersonalRankInfo();
        cCycleContentsPersonalRankInfo(u8 contentType, u32 rank, u32 score, MtTime time);
        // Address: 0x01a6d970 - 0x01a6d971 (1 bytes)
        virtual ~cCycleContentsPersonalRankInfo() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u8 mContentType;  // offset: 0x8
        u32 mRank;  // offset: 0xc
        u32 mScore;  // offset: 0x10
        MtTime mUpdateTime;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class cCycleContentsInfo : public nQuest::cQuestInfoBase
    {
    public:
        enum
        {
            REWARD_ITEM_NUM = 5,
        };
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
        MT_CTSTR getContentsName() const;
        MT_CTSTR getContentsInfoLight() const;
        bool isPlayContents() const;
        u32 getRanking() const;
        u32 getPoint() const;
        u32 getRankPoint() const;
        MT_CTSTR getContentsInfo() const;
        MT_CTSTR getOrderPlace() const;
        MT_CTSTR getPhaseName() const;
        MT_CTSTR getPhaseInfo() const;
        u32 getPhaseChangeTime() const;
        u32 getPhaseImageResId() const;
        const MtTime& getStartTime() const;
        const MtTime& getEndTime() const;
        bool getRankingListUpdateTime(MtTime* time) const;
        u32 getContentsCategory() const;
        u32 getContentsSubCategory() const;
        u32 getRewardItem(u32 idx) const;
        nQuest::SCHEDULE_ID getRankingScheduleId() const;
        nQuest::SCHEDULE_ID getCycleContentsScheduleId() const;
        nQuest::CYCLE_CONTENTS_PERIOD getCycleContentsPeriod() const;
        nQuest::CYCLE_CONTENTS_PERIOD getCycleContentsPeriodRealTime() const;
        bool isCreateRanking() const;
        u32 getItemRankAvg() const;
    private:
        u32 getSituation() const;
    public:
        cCycleContentsInfo();
        virtual ~cCycleContentsInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::CycleContentsPersonalRankInfoArray mContentsRank;  // offset: 0x8
        MtTime mStartTime;  // offset: 0x28
        MtTime mEndTime;  // offset: 0x30
        MtTime mUpdateTime;  // offset: 0x38
        u32 mBaseSituation;  // offset: 0x40
        u32 mPeriod;  // offset: 0x44
        u32 mCycleContentsSubCategory;  // offset: 0x48
        u32 mTotalPoint;  // offset: 0x4c
        u32 mPlayNum;  // offset: 0x50
        u32 mRewardItem[5];  // offset: 0x54
        u32 mItemRankAvg;  // offset: 0x68
        u8 mCycleContentsCategory;  // offset: 0x6c
        bool mIsCreateRanking;  // offset: 0x6d
    public:
        static MyDTI DTI;
    };

    class cGUINewspaperSetQuestMonsterInfo : public nQuest::cQuestInfoBase
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
        u32 getEnemyLv() const;
        u32 getEnemyGroupId() const;
        bool isPartyRecommanded() const;
        cGUINewspaperSetQuestMonsterInfo();
        cGUINewspaperSetQuestMonsterInfo(u32 lv, u32 id, bool isParty);
    protected:
        u32 mEnemyLv;  // offset: 0x8
        u32 mEnemyGroupId;  // offset: 0xc
        bool mIsPartyRecommanded;  // offset: 0x10
    public:
        static MyDTI DTI;
    };

    class cGUINewspaperSetQuestItemInfo : public nQuest::cQuestInfoBase
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
        u32 getItemId() const;
        u32 getItemNum() const;
        cGUINewspaperSetQuestItemInfo();
        cGUINewspaperSetQuestItemInfo(u32 id, u32 num);
    protected:
        u32 mItemId;  // offset: 0x8
        u32 mItemNum;  // offset: 0xc
    public:
        static MyDTI DTI;
    };

    class cGUINewspaperSetQuestInfo : public nQuest::cQuestInfoBase
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
        nQuest::QUEST_ID getQuestId() const;
        nQuest::SCHEDULE_ID getScheduleId() const;
        MT_CTSTR getQuestName() const;
        MT_CTSTR getEyewitnessInfo() const;
        u32 getFixReward(u32 idx) const;
        u32 getSelectReward(u32 idx) const;
        u32 getRandomRewardNum() const;
        u32 getDiscoverRewardItemId() const;
        u32 getDiscoverBonusGold() const;
        u32 getDiscoverBonusRim() const;
        u32 getDiscoverBonusExp() const;
        const MtTime& getEndDistributionDate() const;
        u32 getBaseLevel() const;
        u32 getThumbnailResourceId() const;
        virtual bool isDiscover() const;  // vtable slot 6
        bool isCleared() const;
        s32 getCompleteNum() const;
        bool isPartyBonus() const;
        bool isPopularQuickParty() const;
        bool isPartyRecommanded() const;
        u32 getTargetEnemyListNum() const;
        u32 getTargetEnemyGroupId(u32 idx) const;
        MT_CTSTR getTargetEnemyName(u32 idx) const;
        u32 getTargetEnemyLv(u32 idx) const;
        bool isTargetEnemyParty(u32 idx) const;
        bool hasEnemyInfo(u32 enemyGroupId, u32 enemyLv) const;
        u32 getDeliveryItemListNum() const;
        u32 getDeliveryItemId(u32 idx) const;
        u32 getDeliveryItemNum(u32 idx) const;
        u32 getQuestDiffculty() const;
        cGUINewspaperSetQuestInfo();
        cGUINewspaperSetQuestInfo(u32 scheduleId);
        virtual ~cGUINewspaperSetQuestInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mDiscoverBonusItemId;  // offset: 0x8
        u32 mDiscoverBonusGold;  // offset: 0xc
        u32 mDiscoverBonusRim;  // offset: 0x10
        u32 mDiscoverBonusExp;  // offset: 0x14
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x18
        nQuest::QUEST_ID mQuestId;  // offset: 0x28
        u32 mFixReward[8];  // offset: 0x38
        u32 mSelectReward[5];  // offset: 0x58
        u32 mRandomRewardNum;  // offset: 0x6c
        u32 mBaseLevel;  // offset: 0x70
        u32 mQuestThumbnailResourceId;  // offset: 0x74
        MtTime mEndDistributionDate;  // offset: 0x78
        u32 mCompleteNum;  // offset: 0x80
        bool mIsDiscovery;  // offset: 0x84
        bool mIsPartyBonus;  // offset: 0x85
        u32 mQuickPartyPopularity;  // offset: 0x88
        nQuest::cGUINewspaperSetQuestMonsterInfoArray mTargetEnemyArray;  // offset: 0x90
        nQuest::cGUINewspaperSetQuestItemInfoArray mDeliveryItemArray;  // offset: 0xb0
    public:
        static MyDTI DTI;
    };

    class cGUINewspaperRecommededQuestInfo : public nQuest::cGUINewspaperSetQuestInfo
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
        u32 getAreaId() const;
        cGUINewspaperRecommededQuestInfo();
        cGUINewspaperRecommededQuestInfo(u32 scheduleId);
        virtual ~cGUINewspaperRecommededQuestInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mAreaId;  // offset: 0xd0
    public:
        static MyDTI DTI;
    };

    class cGUINewspaperSetQuestOpenDateInfo : public nQuest::cGUINewspaperSetQuestInfo
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
        const MtTime& getOpenDate() const;
        u32 getAreaId() const;
        virtual bool isDiscover() const;  // vtable slot 6
        cGUINewspaperSetQuestOpenDateInfo();
        cGUINewspaperSetQuestOpenDateInfo(u32 scheduleId);
        virtual ~cGUINewspaperSetQuestOpenDateInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mAreaId;  // offset: 0xd0
        MtTime mOpenDate;  // offset: 0xd8
    public:
        static MyDTI DTI;
    };

    class cCycleContentsResultPointInfo : public nQuest::cQuestInfoBase
    {
    public:
        enum RESULT_POINT_TYPE
        {
            RESULT_POINT_TYPE_NONE = 0,
            RESULT_POINT_TYPE_ENEMY = 1,
            RESULT_POINT_TYPE_EXTRA_BONUS = 2,
            RESULT_POINT_TYPE_BREAK_REGION = 3,
        };
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
        static nQuest::cCycleContentsResultPointInfo* newInstance(RESULT_POINT_TYPE type, u32 param01, u32 param02, u32 point);
        RESULT_POINT_TYPE getType() const;
        u32 getEnemyId() const;
        u32 getEnemyNum() const;
        u32 getExtraBonusNo() const;
        u32 getPoint() const;
        cCycleContentsResultPointInfo();
        virtual ~cCycleContentsResultPointInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u8 mType;  // offset: 0x8
        u32 mParam01;  // offset: 0xc
        u32 mParam02;  // offset: 0x10
        u32 mPoint;  // offset: 0x14
    public:
        static MyDTI DTI;
    };

    class cCycleContentsResultRewardInfo : public nQuest::cQuestInfoBase
    {
    public:
        enum RESULT_REWARD_TYPE
        {
            RESULT_REWARD_TYPE_NONE = 0,
            RESULT_REWARD_TYPE_ITEM = 1,
            RESULT_REWARD_TYPE_REGION_BREAK = 2,
            RESULT_REWARD_TYPE_GOLD = 3,
            RESULT_REWARD_TYPE_RIM = 4,
            RESULT_REWARD_TYPE_JOB_POINT = 5,
            RESULT_REWARD_TYPE_EXP = 6,
            RESULT_REWARD_TYPE_BLOOD_ORB = 7,
            RESULT_REWARD_TYPE_ABILITY = 8,
            RESULT_REWARD_TYPE_EXTRA_JOB_POINT = 9,
            RESULT_REWARD_TYPE_EXTRA_EXP = 10,
            RESULT_REWARD_TYPE_MAX = 11,
        };
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
        static nQuest::cCycleContentsResultRewardInfo* newInstance(RESULT_REWARD_TYPE type, u32 param01);
        static nQuest::cCycleContentsResultRewardInfo* newInstance(RESULT_REWARD_TYPE type, u32 param01, u32 param02);
        RESULT_REWARD_TYPE getType() const;
        u32 getItemId() const;
        u32 getItemNum() const;
        u32 getGold() const;
        u32 getRim() const;
        u32 getJobPoint() const;
        u32 getExp() const;
        u32 getBloodOrb() const;
        u32 getAbilityNo() const;
        cCycleContentsResultRewardInfo();
        virtual ~cCycleContentsResultRewardInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u8 mType;  // offset: 0x8
        u32 mParam01;  // offset: 0xc
        u32 mParam02;  // offset: 0x10
    public:
        static MyDTI DTI;
    };

    class cCycleContentsResultInfo : public nQuest::cQuestInfoBase
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
        MT_CTSTR getCycleContentsName() const;
        MT_CTSTR getSituationName() const;
        u32 getResultPoint() const;
        u32 getResultBonusPoint() const;
        u32 getDieCount() const;
        u32 getPointDownRate() const;
        u32 getResultPointTotal() const;
        u32 getTechnicalScore() const;
        u32 getBestTechnicalScore() const;
        bool isNewRecord() const;
        u32 getTechnicalScoreTimeBonus() const;
        u32 getClearTimeBonusRate() const;
        const nQuest::CycleContentsResultPointInfoArray& getPointList() const;
        const nQuest::CycleContentsResultRewardList& getRewardItemIdList() const;
        bool hasRegionBreakReward() const;
        bool isCreateRanking() const;
        cCycleContentsResultInfo();
        virtual ~cCycleContentsResultInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::CycleContentsResultPointInfoArray mPointList;  // offset: 0x8
        nQuest::CycleContentsResultRewardList mRewardList;  // offset: 0x28
        u32 mResultPoint;  // offset: 0x48
        u32 mResultBonusPoint;  // offset: 0x4c
        u32 mDieCount;  // offset: 0x50
        u32 mPointDownRate;  // offset: 0x54
        u32 mResultPointTotal;  // offset: 0x58
        u32 mTechnicalScore;  // offset: 0x5c
        u32 mTechnicalSocreTimeBonus;  // offset: 0x60
        u32 mBestTechnicalScore;  // offset: 0x64
        u32 mClearTimeBonusRate;  // offset: 0x68
        bool mHasRegionBreakReward;  // offset: 0x6c
        bool mIsNewRecord;  // offset: 0x6d
        bool mIsCreateRanking;  // offset: 0x6e
    public:
        static MyDTI DTI;
    };

    class cCycleContentsRankingInfo : public nQuest::cQuestInfoBase
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
        static nQuest::cCycleContentsRankingInfo* newInstance(u32 rank, s64 point, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanName);
        MT_CTSTR getFirstName() const;
        MT_CTSTR getLastName() const;
        MT_CTSTR getClanName() const;
        u32 getPoint() const;
        u32 getRank() const;
        cCycleContentsRankingInfo();
        virtual ~cCycleContentsRankingInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        MtString mFirstName;  // offset: 0x8
        MtString mLastName;  // offset: 0x10
        MtString mClanName;  // offset: 0x18
        u32 mRank;  // offset: 0x20
        s64 mPoint;  // offset: 0x28
    public:
        static MyDTI DTI;
    };

    class cCycleContentsRankingRewardInfo : public nQuest::cQuestInfoBase
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
        static nQuest::cCycleContentsRankingRewardInfo* newInstance(u32 rank);
        static nQuest::cCycleContentsRankingRewardInfo* newInstance(u32 underRank, u32 overRank);
        static void addReward(nQuest::cCycleContentsRankingRewardInfo* pInfo, nQuest::cCycleContentsResultRewardInfo* pReward);
        u32 getUnderRank() const;
        u32 getOverRank() const;
        const nQuest::CycleContentsResultRewardList& getRewardList() const;
        cCycleContentsRankingRewardInfo();
        virtual ~cCycleContentsRankingRewardInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mUnderRank;  // offset: 0x8
        u32 mOverRank;  // offset: 0xc
        nQuest::CycleContentsResultRewardList mRewardList;  // offset: 0x10
    public:
        static MyDTI DTI;
    };

    class cCycleContentsBorderRewardInfo : public nQuest::cQuestInfoBase
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
        static nQuest::cCycleContentsBorderRewardInfo* newInstance(s32 underPoint);
        static nQuest::cCycleContentsBorderRewardInfo* newInstance(s32 underPoint, s32 overPoint);
        static void addReward(nQuest::cCycleContentsBorderRewardInfo* pInfo, nQuest::cCycleContentsResultRewardInfo* pReward);
        s32 getUnderPoint() const;
        s32 getOverPoint() const;
        const nQuest::CycleContentsResultRewardList& getRewardList() const;
        cCycleContentsBorderRewardInfo();
        virtual ~cCycleContentsBorderRewardInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        s32 mUnderPoint;  // offset: 0x8
        s32 mOverPoint;  // offset: 0xc
        nQuest::CycleContentsResultRewardList mRewardList;  // offset: 0x10
    public:
        static MyDTI DTI;
    };

    class cQuestCommand : public ::MtObject
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
        cQuestCommand();
        virtual ~cQuestCommand();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(const CDataQuestCommand* pSrc);
    public:
        s32 m_nParam01;  // offset: 0x8
        s32 m_nParam02;  // offset: 0xc
        s32 m_nParam03;  // offset: 0x10
        s32 m_nParam04;  // offset: 0x14
        u16 m_usCommand;  // offset: 0x18
        static MyDTI DTI;
    };

    class cTalkData : public ::MtObject
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
        cTalkData();
        virtual ~cTalkData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mGroupSerial;  // offset: 0x8
        u32 mNpcId;  // offset: 0xc
        u32 mNoOrderGroupSerial;  // offset: 0x10
        bool mIsOneOnly;  // offset: 0x14
        bool mIsDispOrderUI;  // offset: 0x15
        static MyDTI DTI;
    };

    class cDeliverTargetInfo : public ::MtObject
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
        u32 getStageNo() const;
        u32 getGroupNo() const;
        u32 getSetNo() const;
        u32 getMsgGroupSerial() const;
        u32 getNpcId() const;
        bool isQuestSet() const;
        cDeliverTargetInfo();
        cDeliverTargetInfo(u32 stageNo, u32 npcId, u32 msgGroupSerial);
        cDeliverTargetInfo(u32 stageNo, u32 groupNo, u32 setNo, u32 msgGroupSerial);
        virtual ~cDeliverTargetInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mStageNo;  // offset: 0x8
        u32 mGroupNo;  // offset: 0xc
        u32 mSetNo;  // offset: 0x10
        u32 mMsgGroupSerial;  // offset: 0x14
        u32 mNpcId;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class cGUIListData : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        MT_CTSTR getQuestName() const;
        nQuest::QUEST_TYPE getQuestType() const;
        u32 getBaseLevel() const;
        u32 getAreaId() const;
        u32 getRewardAreaPoint() const;
        u32 getRewardExp() const;
        u32 getRewardGold() const;
        u32 getRewardRim() const;
        const nQuest::cRewardData* getFixReward(u32 idx) const;
        const nQuest::cFixRewardData* getSelectReward(u32 idx) const;
        const nQuest::cRewardData* getRandomReward(u32 idx) const;
        const MtTime* getEndDistributionData() const;
        u32 getPurpose() const;
        MT_CTSTR getMyPurposeMsg() const;
        MT_CTSTR getLeaderPurposeMsg() const;
        MT_CTSTR getPurposeMsg(u32 idx) const;
        u32 getPurposeNum() const;
        MT_CTSTR getOrderNpcName() const;
        u32 getClearNum() const;
        u32 getOrderConditionNum() const;
        MT_CTSTR getOrderConditionMsg(u32 idx) const;
        nQuest::REPEAT_BONUS_TYPE getRepeatBonusType() const;
        void setupRepeatBonusMsg(rGUIMessage* pGMD);
        MT_CTSTR getRepeatBonusMsg() const;
        u32 getOrderConditionType(u32 Idx) const;
        bool isEnableCancel() const;
        MT_CTSTR getAreaBonusMsg() const;
        bool isAreaBonus() const;
        u32 getAreaBonusRate() const;
        u32 getDiscoverRewardItemId() const;
        u32 getDiscoverBonusGold() const;
        u32 getDiscoverBonusRim() const;
        u32 getDiscoverBonusExp() const;
        bool isPartyBonus() const;
        u32 getPartyBonusRate() const;
        bool hasReceived() const;
        bool isPartyBonusOrb() const;
        u32 getPartyBonusOrbNum() const;
        u32 getRandomRewardNum() const;
        u32 getChargeRewardNum() const;
        bool isProgressBonus() const;
        bool isClanQuest() const;
        u32 getClanPoint() const;
        u32 getClanClearNum() const;
        u16 getClanClearMax() const;
        bool isClanClear() const;
        cGUIListData();
        cGUIListData(nQuest::SCHEDULE_ID scheduleId);
        virtual ~cGUIListData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x8
        MtString mRepeatBonusText;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class cGUIInfoData : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        MT_CTSTR getQuestName() const;
        nQuest::QUEST_TYPE getQuestType() const;
        u32 getBaseLevel() const;
        u32 getAreaId() const;
        u32 getRewardAreaPoint() const;
        u32 getRewardExp() const;
        u32 getRewardGold() const;
        u32 getRewardRim() const;
        const nQuest::cRewardData* getFixReward(u32 idx) const;
        const nQuest::cFixRewardData* getSelectReward(u32 idx) const;
        const nQuest::cRewardData* getRandomReward(u32 idx) const;
        nQuest::REPEAT_BONUS_TYPE getRepeatBonusType() const;
        MT_CTSTR getRepeatBonusMsg(rGUIMessage* pGMD);
        const MtTime* getEndDistributionData() const;
        MT_CTSTR getOrderNpcName() const;
        u32 getOrderConditionNum() const;
        u32 getOrderConditionType(u32 Idx) const;
        MT_CTSTR getOrderConditionMsg(u32 idx) const;
        MT_CTSTR getAreaBonusMsg() const;
        bool isAreaBonus() const;
        u32 getAreaBonusRate() const;
        u32 getDiscoverRewardItemId() const;
        u32 getDiscoverBonusGold() const;
        u32 getDiscoverBonusRim() const;
        u32 getDiscoverBonusExp() const;
        bool isPartyBonus() const;
        u32 getPartyBonusRate() const;
        bool hasReceived() const;
        bool isPartyBonusOrb() const;
        u32 getPartyBonusOrbNum() const;
        u32 getRandomRewardNum() const;
        u32 getChargeRewardNum() const;
        u32 getClearNum() const;
        bool isProgressBonus() const;
        bool isClanQuest() const;
        u32 getClanPoint() const;
        u32 getClanClearNum() const;
        u16 getClanClearMax() const;
        bool isClanClear() const;
        void resetInfoData();
        cGUIInfoData();
        cGUIInfoData(nQuest::SCHEDULE_ID scheduleId);
        virtual ~cGUIInfoData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x8
        MtString mRepeatBonusText;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class cGUIBoardData : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        MT_CTSTR getQuestName() const;
        u32 getBaseLevel() const;
        bool isEnableOrder() const;
        bool isOrder() const;
        bool isCleared() const;
        bool isClanClear() const;
        bool isClanQuest() const;
        u32 getClanPoint() const;
        u32 getClanPointOrigin() const;
        cGUIBoardData();
        cGUIBoardData(nQuest::SCHEDULE_ID scheduleId);
        virtual ~cGUIBoardData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x8
    public:
        static MyDTI DTI;
    };

    class cGUIDeliveryData : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        MT_CTSTR getQuestName() const;
        bool isPreWaitDeliver() const;
        bool checkComplete() const;
        cGUIDeliveryData();
        cGUIDeliveryData(nQuest::SCHEDULE_ID scheduleId, s32 blockNo);
        virtual ~cGUIDeliveryData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x8
        s32 mBlockNo;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class cGUIEventBoardData : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        u32 getQuestIdU32() const;
        MT_CTSTR getQuestName() const;
        u32 getBaseLevel() const;
        bool isOrder() const;
        cGUIEventBoardData();
        cGUIEventBoardData(nQuest::SCHEDULE_ID scheduleId);
        virtual ~cGUIEventBoardData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x8
    public:
        static MyDTI DTI;
    };

    class cGUIAreaMasterData : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        nQuest::QUEST_TYPE getQuestType() const;
        MT_CTSTR getQuestName() const;
        u32 getBaseLevel() const;
        bool isEnableOrder() const;
        u32 getRewardExp() const;
        u32 getRewardGold() const;
        u32 getRewardRim() const;
        u32 getRewardAreaPoint() const;
        const nQuest::cRewardData* getFixReward(u32 idx) const;
        const nQuest::cFixRewardData* getSelectReward(u32 idx) const;
        const nQuest::cRewardData* getRandomReward(u32 idx) const;
        nQuest::REPEAT_BONUS_TYPE getRepeatBonusType() const;
        MT_CTSTR getRepeatBonusMsg(rGUIMessage* pGMD);
        const MtTime* getEndDistributionData() const;
        u32 getDiscoverRewardItemId() const;
        u32 getDiscoverBonusGold() const;
        u32 getDiscoverBonusRim() const;
        u32 getDiscoverBonusExp() const;
        MT_CTSTR getOrderNpcName() const;
        u32 getEnemyNum() const;
        MT_CTSTR getEnemyName(u32 idx) const;
        u32 getEnemyLevel(u32 idx) const;
        u32 getOrderConditionNum() const;
        u32 getOrderConditionType(u32 idx) const;
        MT_CTSTR getOrderConditionMsg(u32 idx) const;
        bool isPartyBonus() const;
        u32 getPartyBonusRate() const;
        bool hasReceived() const;
        bool isPartyBonusOrb() const;
        u32 getPartyBonusOrbNum() const;
        u32 getRandomRewardNum() const;
        u32 getChargeRewardNum() const;
        u32 getClearNum() const;
        bool isProgressBonus() const;
        u32 getDeliveryItemInfoNum() const;
        u32 getDeliveryItemId(u32 idx) const;
        u32 getDeliveryItemNum(u32 idx) const;
        cGUIAreaMasterData();
        cGUIAreaMasterData(nQuest::SCHEDULE_ID scheduleId);
        virtual ~cGUIAreaMasterData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x8
        MtString mRepeatBonusText;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class cGUIActiveData : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        bool isOrder() const;
        cGUIActiveData();
        cGUIActiveData(nQuest::SCHEDULE_ID scheduleId);
        virtual ~cGUIActiveData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x8
    public:
        static MyDTI DTI;
    };

    class cCycleContentsSituationInfo : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        nQuest::QUEST_ID getQuestId() const;
        MT_CTSTR getContentsName() const;
        MT_CTSTR getContentsInfo() const;
        MT_CTSTR getSituationName() const;
        u32 getBaseLevel() const;
        bool isEnableOrder() const;
        nQuest::RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrder() const;
        u32 getOrderConditionNum() const;
        u32 getOrderConditionType(u32 idx) const;
        MT_CTSTR getOrderConditionMsg(u32 idx) const;
        MT_CTSTR getOrderConditionParamMessage(u32 idx, u32 paramIdx) const;
        bool isBigParty() const;
        u32 getRewardItem(u32 idx) const;
        u32 getMaxClearTimeBonusRatio() const;
        u32 getSituationNo() const;
        bool isDistribution() const;
        void setDistribution(bool setDist);
        void addOrderCondition(u8 type, u32 param1, u32 param2);
        void updateOrderConditionInfo();
        void loadOrderConditionInfo();
        cCycleContentsSituationInfo();
        cCycleContentsSituationInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 baseLevel, u8 situationNo, u8 CycleContentsCategory, u32 CycleContentsSubCategory, u32* item, u32 maxClearTimeBonusRatio, bool IsDistribution);
        virtual ~cCycleContentsSituationInfo();
    protected:
        nQuest::OrderConditionArray mOrderConditions;  // offset: 0x8
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
        nQuest::QUEST_ID mQuestId;  // offset: 0x38
        u32 mRewardItem[7];  // offset: 0x48
        u32 mBaseLevel;  // offset: 0x64
        u32 mCycleContentsSubCategory;  // offset: 0x68
        u32 mMaxClearTimeBonusRatio;  // offset: 0x6c
        u8 mSituationNo;  // offset: 0x70
        u8 mCycleContentsCategory;  // offset: 0x71
        bool mIsDistribution;  // offset: 0x72
    public:
        static MyDTI DTI;
    };

    class cEndContentsGroupQuestInfo : public nQuest::cQuestInfoBase
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
        nQuest::SCHEDULE_ID getScheduleId() const;
        nQuest::QUEST_ID getQuestId() const;
        bool isEnableOrder() const;
        nQuest::RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrder() const;
        u32 getOrderConditionNum() const;
        u32 getOrderConditionType(u32 idx) const;
        MT_CTSTR getOrderConditionMsg(u32 idx) const;
        MT_CTSTR getOrderConditionParamMessage(u32 idx, u32 paramIdx) const;
        void addOrderCondition(u8 type, u32 param1, u32 param2);
        void updateOrderConditionInfo();
        void loadOrderConditionInfo();
        cEndContentsGroupQuestInfo();
        cEndContentsGroupQuestInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId);
        virtual ~cEndContentsGroupQuestInfo();
    protected:
        nQuest::OrderConditionArray mOrderConditions;  // offset: 0x8
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
        nQuest::QUEST_ID mQuestId;  // offset: 0x38
    public:
        static MyDTI DTI;
    };

    class cTargetEnemyInfo : public ::MtObject
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
        bool sameInfo(u32 stageNo, u32 groupNo) const;
        u32 getStageNo() const;
        u32 getGroupNo() const;
        cTargetEnemyInfo();
        cTargetEnemyInfo(u32 stageNo, u32 groupNo);
        virtual ~cTargetEnemyInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mStageNo;  // offset: 0x8
        u32 mGroupNo;  // offset: 0xc
    public:
        static MyDTI DTI;
    };

    class cScheduleInfo : public ::MtObject
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
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        nQuest::SCHEDULE_ID getScheduleId() const;
        u32 getScheduleIdU32() const;
        cScheduleInfo();
        cScheduleInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId);
        virtual ~cScheduleInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::QUEST_ID mQuestId;  // offset: 0x8
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class cPartyBonusInfo : public nQuest::cQuestInfoBase
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
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        nQuest::SCHEDULE_ID getScheduleId() const;
        MT_CTSTR getQuestName() const;
        u32 getGoldRaito() const;
        u32 getExpRatio() const;
        u32 getRimRatio() const;
        u32 getAreaPointRatio() const;
        u32 getOrbNum() const;
        bool hasReceived() const;
        void receive();
        cPartyBonusInfo();
        cPartyBonusInfo(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 gold, u32 exp, u32 rim, u32 ap, u32 orb, bool isReceived);
        virtual ~cPartyBonusInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::QUEST_ID mQuestId;  // offset: 0x8
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x18
        u32 mGoldRatio;  // offset: 0x28
        u32 mExpRatio;  // offset: 0x2c
        u32 mRimRatio;  // offset: 0x30
        u32 mAreaPointRatio;  // offset: 0x34
        u32 mOrbNum;  // offset: 0x38
        bool mHasReceived;  // offset: 0x3c
    public:
        static MyDTI DTI;
    };

    class cGUINewspaperSetQuestInfoList : public ::MtTypedArray<nQuest::cGUINewspaperSetQuestInfo>
    {
    public:
        u32 getAreaId() const;
        u32 getUnderBaseLevel() const;
        u32 getOverBaseLevel() const;
        bool isPartyRecommanded(const nQuest::cGUINewspaperSetQuestInfo* pInfo) const;
        cGUINewspaperSetQuestInfoList();
    protected:
        u32 mAreaId;  // offset: 0x20
        u32 mUnderBaseLevel;  // offset: 0x24
        u32 mOverBaseLevel;  // offset: 0x28
    };

    class TargetEnemyInfoArray : public ::MtTypedArray<nQuest::cTargetEnemyInfo>
    {
    public:
        u32 getFlagNo() const;
        void setFlagNo(u32 flagNo);
        bool isValid() const;
        void setIsValid(bool isValid);
        TargetEnemyInfoArray();
        TargetEnemyInfoArray(const nQuest::TargetEnemyInfoArray& obj);
    protected:
        u32 mFlagNo;  // offset: 0x20
        bool mIsValid;  // offset: 0x24
    };

    class QuestCommandList : public ::MtTypedArray<nQuest::cQuestCommand>
    {
    public:
        QuestCommandList();
        QuestCommandList(cQuestTask* pTask, const nQuest::QuestCommandList& obj);
    public:
        bool mIsNotLeaderOnly;  // offset: 0x20
    };

    bool isDisableOrderCondition(u32 result, ORDER_CONDITION_TYPE checkType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:57
    bool isPartyQuest(QUEST_TYPE questType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:98
    bool isSoloQuest(QUEST_TYPE questType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:131
    bool isCycleContents(QUEST_TYPE questType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:160
    bool isContents(QUEST_TYPE questType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:189
    bool isQuestListSet(QUEST_TYPE questType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:219
    u32 getGUIQuestAnnounceTYPE(QUEST_TYPE questType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:254
    QUEST_UI_DISP_TYPE getQuestLogDispType(QUEST_TYPE questType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:292
    QUEST_TYPE getQuestType(QUEST_UI_DISP_TYPE questUIDispType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:324
    u32 getUseOrderConditionTagNum(u32 orderConditionType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:356
    bool isCyclePhaseQuest(CYCLE_CONTENTS_NOTICE_TYPE type);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:557
    MT_CTSTR getTraceTaskInfo(SCHEDULE_ID scheduleId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:9364
    MT_CTSTR getTraceTaskInfo(QUEST_ID questId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:9381
    MT_CTSTR getTraceTaskInfo(cQuestTask* pTask);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:9398
    CYCLE_CONTENTS_TYPE getCycleContentsType(CYCLE_CONTENTS_CATEGORY category);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:392
    CYCLE_CONTENTS_TYPE getCycleContentsType(CYCLE_CONTENTS_CATEGORY category, CYCLE_CONTENTS_SUB_CATEGORY subCategory);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:404
    CYCLE_CONTENTS_CATEGORY getCycleContentsCategory(CYCLE_CONTENTS_TYPE cycleContentsType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:446
    CYCLE_CONTENTS_SUB_CATEGORY getCycleContentsSubCategory(CYCLE_CONTENTS_TYPE cycleContentsType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:481
    MT_CTSTR getQuestTypeName(QUEST_TYPE questType);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:515
    u32 getQuestDispPriority(SCHEDULE_ID scheduleId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:859
    RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrderList(const OrderConditionArray& orderConditionList);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:1147
    RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrderList(const OrderConditionArray& orderConditionList, const cContextInstHm* pCtxt);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:1221
    bool isDispPartyQuest(SCHEDULE_ID ScheduleId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:9423
    bool isDispActiveQuest(SCHEDULE_ID ScheduleId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nQuest.cpp:9448

}  // namespace nQuest

// Inline, no code of its own: checked where it is inlined.
inline nQuest::cDeliveredItemInfo::cDeliverCharacterInfo::cDeliverCharacterInfo() {
    this->mCharacterId = static_cast<u32>(0);
    this->mItemNum = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline u32 nQuest::cCycleContentsInfo::getSituation() const {
    return this->mBaseSituation;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 nQuest::cGUINewspaperSetQuestMonsterInfo::getEnemyLv() const {
    return this->mEnemyLv;
}

// Inline, no code of its own: checked where it is inlined.
inline nQuest::cGUINewspaperSetQuestMonsterInfo::cGUINewspaperSetQuestMonsterInfo() {
    this->mEnemyLv = static_cast<u32>(0);
    this->mEnemyGroupId = static_cast<u32>(0);
    this->mIsPartyRecommanded = false;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 nQuest::cGUINewspaperSetQuestItemInfo::getItemId() const {
    return this->mItemId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 nQuest::cGUINewspaperSetQuestItemInfo::getItemNum() const {
    return this->mItemNum;
}

// Inline, no code of its own: checked where it is inlined.
inline nQuest::cGUINewspaperSetQuestItemInfo::cGUINewspaperSetQuestItemInfo() {
    this->mItemId = static_cast<u32>(0);
    this->mItemNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline nQuest::cCycleContentsResultPointInfo::cCycleContentsResultPointInfo() {
    this->mType = static_cast<u8>(0);
    this->mParam01 = static_cast<u32>(0);
    this->mParam02 = static_cast<u32>(0);
    this->mPoint = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline nQuest::cCycleContentsResultRewardInfo::cCycleContentsResultRewardInfo() {
    this->mType = static_cast<u8>(0);
    this->mParam01 = static_cast<u32>(0);
    this->mParam02 = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline nQuest::cCycleContentsRankingRewardInfo::cCycleContentsRankingRewardInfo() {
    this->mUnderRank = static_cast<u32>(0);
    this->mOverRank = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline nQuest::cCycleContentsBorderRewardInfo::cCycleContentsBorderRewardInfo() {
    this->mUnderPoint = static_cast<s32>(0);
    this->mOverPoint = static_cast<s32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline nQuest::cDeliverTargetInfo::cDeliverTargetInfo() {
    this->mNpcId = static_cast<u32>(0);
    this->mSetNo = static_cast<u32>(0);
    this->mMsgGroupSerial = static_cast<u32>(0);
    this->mStageNo = static_cast<u32>(0);
    this->mGroupNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline nQuest::cTargetEnemyInfo::cTargetEnemyInfo() {
    this->mStageNo = static_cast<u32>(0);
    this->mGroupNo = static_cast<u32>(0);
}
