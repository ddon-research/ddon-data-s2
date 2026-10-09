#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Character.h"
#include "CharacterCommon.h"
#include "CharacterEdit.h"
#include "Common.h"
#include "Item.h"
#include "MtCollection.h"
#include "MtString.h"
#include "Pawn.h"
#include "Quest.h"
#include "QuickParty.h"
#include "Stage.h"
#include "SupportPoint.h"

// Forward declarations
class CDataArisenProfile;
class CDataChangeEquipJobItem;
class CDataCharacterMsgSet;
class CDataCommonU32;
class CDataCommunicationShortCut;
class CDataEditInfo;
class CDataGameItemStorage;
class CDataGatheringItemGetRequest;
class CDataGetRewardBoxItem;
class CDataItemStorageIndicateNum;
class CDataItemUIDList;
class CDataPawnHp;
class CDataPawnReaction;
class CDataQuickPartyMatching;
class CDataShortCut;
class CDataStageLayoutID;
class CDataUseSupportPoint;
class CPacket;
class MtString;

// Declarations
namespace nUserSession { class CPacket_C2S_ACTIVATE_JOB_ORDER_REQ; }
namespace nUserSession { class CPacket_C2S_AREA_WARP_REQ; }
namespace nUserSession { class CPacket_C2S_BAZAAR_GET_ITEM_LIST_REQ; }
namespace nUserSession { class CPacket_C2S_BAZAAR_PROCEEDS_REQ; }
namespace nUserSession { class CPacket_C2S_BOX_GACHA_BUY_REQ; }
namespace nUserSession { class CPacket_C2S_BUY_SHOP_GOODS_REQ; }
namespace nUserSession { class CPacket_C2S_CHANGE_PAWN_EQUIP_JOB_ITEM_REQ; }
namespace nUserSession { class CPacket_C2S_CLAN_SET_MEMBER_RANK_REQ; }
namespace nUserSession { class CPacket_C2S_CRAFT_SKILL_ANALYZE_REQ; }
namespace nUserSession { class CPacket_C2S_CRAFT_SKILL_UP_REQ; }
namespace nUserSession { class CPacket_C2S_CRAFT_TIME_SAVE_REQ; }
namespace nUserSession { class CPacket_C2S_DEBUG_QUEST_FORCE_PROGRESS_REQ; }
namespace nUserSession { class CPacket_C2S_DELIVER_ITEM_REQ; }
namespace nUserSession { class CPacket_C2S_ENEMY_BREAK_REGION_NTC; }
namespace nUserSession { class CPacket_C2S_ENEMY_GROUP_ENTRY_NOTICE; }
namespace nUserSession { class CPacket_C2S_ENEMY_GROUP_LEAVE_NOTICE; }
namespace nUserSession { class CPacket_C2S_ENTRY_BOARD_ITEM_INVITE_REQ; }
namespace nUserSession { class CPacket_C2S_GET_CAPLINK_ACHIEVE_REWARD_REQ; }
namespace nUserSession { class CPacket_C2S_GET_CRAFT_GRADEUP_RECIPE_REQ; }
namespace nUserSession { class CPacket_C2S_GET_CRAFT_PRODUCT_REQ; }
namespace nUserSession { class CPacket_C2S_GET_CRAFT_RECIPE_DESIGNATE_REQ; }
namespace nUserSession { class CPacket_C2S_GET_CRAFT_RECIPE_REQ; }
namespace nUserSession { class CPacket_C2S_GET_DROP_ITEM_LIST_REQ; }
namespace nUserSession { class CPacket_C2S_GET_DROP_ITEM_REQ; }
namespace nUserSession { class CPacket_C2S_GET_ITEM_SORTDATA_BIN_REQ; }
namespace nUserSession { class CPacket_C2S_GET_ITEM_STORAGE_INFO_REQ; }
namespace nUserSession { class CPacket_C2S_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_REQ; }
namespace nUserSession { class CPacket_C2S_GET_PARTY_PAWN_DATA_REQ; }
namespace nUserSession { class CPacket_C2S_GET_REWARD_BOX_ITEM_REQ; }
namespace nUserSession { class CPacket_C2S_JOB_VALUE_SHOP_BUY_ITEM_REQ; }
namespace nUserSession { class CPacket_C2S_LEADER_QUEST_PROGRESS_REQUEST_REQ; }
namespace nUserSession { class CPacket_C2S_LEARN_ABILITY_REQ; }
namespace nUserSession { class CPacket_C2S_LEARN_PAWN_ABILITY_REQ; }
namespace nUserSession { class CPacket_C2S_LEARN_PAWN_NORMAL_SKILL_REQ; }
namespace nUserSession { class CPacket_C2S_LEARN_PAWN_SKILL_REQ; }
namespace nUserSession { class CPacket_C2S_LEARN_SKILL_REQ; }
namespace nUserSession { class CPacket_C2S_LOGIN_REQ; }
namespace nUserSession { class CPacket_C2S_LOST_PAWN_WALLET_REVIVE_REQ; }
namespace nUserSession { class CPacket_C2S_MAIL_SEND_REQ; }
namespace nUserSession { class CPacket_C2S_MOVE_IN_SERVER_REQ; }
namespace nUserSession { class CPacket_C2S_PAWN_EXPEDITION_GET_REWARD_DROP_ITEM_REQ; }
namespace nUserSession { class CPacket_C2S_QUEST_PROGRESS_REQ; }
namespace nUserSession { class CPacket_C2S_QUICK_PARTY_REGISTER_REQ; }
namespace nUserSession { class CPacket_C2S_RANKING_DATA_CHARACTER_ID_REQ; }
namespace nUserSession { class CPacket_C2S_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_REQ; }
namespace nUserSession { class CPacket_C2S_RANKING_DATA_RANK_REQ; }
namespace nUserSession { class CPacket_C2S_RENT_REGISTERED_PAWN_REQ; }
namespace nUserSession { class CPacket_C2S_RESERVE_SERVER_REQ; }
namespace nUserSession { class CPacket_C2S_SEND_LEADER_WAIT_ORDER_QUEST_LIST_REQ; }
namespace nUserSession { class CPacket_C2S_SERVER_UI_COMMAND_REQ; }
namespace nUserSession { class CPacket_C2S_SET_ABILITY_REQ; }
namespace nUserSession { class CPacket_C2S_SET_COMMUNICATION_SHORTCUT_LIST_REQ; }
namespace nUserSession { class CPacket_C2S_SET_MESSAGE_SET_REQ; }
namespace nUserSession { class CPacket_C2S_SET_OFF_PAWN_SKILL_REQ; }
namespace nUserSession { class CPacket_C2S_SET_PAWN_ABILITY_REQ; }
namespace nUserSession { class CPacket_C2S_SET_PAWN_PROFILE_REQ; }
namespace nUserSession { class CPacket_C2S_SET_PAWN_SKILL_REQ; }
namespace nUserSession { class CPacket_C2S_SET_SHORTCUT_LIST_REQ; }
namespace nUserSession { class CPacket_C2S_SET_SKILL_REQ; }
namespace nUserSession { class CPacket_C2S_STAY_INN_REQ; }
namespace nUserSession { class CPacket_C2S_STAY_PENALTY_HEAL_INN_REQ; }
namespace nUserSession { class CPacket_C2S_SUPPORT_POINT_USE_REQ; }
namespace nUserSession { class CPacket_C2S_UPDATE_EQUIP_PRESET_REQ; }
namespace nUserSession { class CPacket_C2S_UPDATE_PAWN_EDIT_PARAM_REQ; }
namespace nUserSession { class CPacket_C2S_UPDATE_PAWN_REACTION_LIST_REQ; }
namespace nUserSession { class CPacket_C2S_WARP_REQ; }

// Type aliases from DWARF
using CArisenProfile = CDataArisenProfile;
using CEditInfo = CDataEditInfo;
using CQuickPartyMatching = CDataQuickPartyMatching;
using CStageLayoutID = CDataStageLayoutID;
using __uint64_t = long unsigned int;
using b8 = bool;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nUserSession {
    class CPacket_C2S_ACTIVATE_JOB_ORDER_REQ
    {
    public:
        CPacket_C2S_ACTIVATE_JOB_ORDER_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_JobID, u8 in_RewardType, u32 in_RewardNo, u8 in_RewardLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 JobID() const;
        u8 RewardType() const;
        u32 RewardNo() const;
        u8 RewardLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucJobID;  // offset: 0x2
        u8 m_ucRewardType;  // offset: 0x3
        u32 m_unRewardNo;  // offset: 0x4
        u8 m_ucRewardLv;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x9
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_AREA_WARP_REQ
    {
    public:
        CPacket_C2S_AREA_WARP_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_CurrentAreaID, u32 in_WarpPointID, u32 in_Price);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 CurrentAreaID() const;
        u32 WarpPointID() const;
        u32 Price() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unCurrentAreaID;  // offset: 0x4
        u32 m_unWarpPointID;  // offset: 0x8
        u32 m_unPrice;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_BAZAAR_GET_ITEM_LIST_REQ
    {
    public:
        CPacket_C2S_BAZAAR_GET_ITEM_LIST_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataCommonU32>& in_ItemIdList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataCommonU32>& ItemIdList() const;
        MtTypedArray<CDataCommonU32>& ItemIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataCommonU32> m_ItemIdList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_BAZAAR_PROCEEDS_REQ
    {
    public:
        CPacket_C2S_BAZAAR_PROCEEDS_REQ();
        s32 WritePacket(CPacket* pPacket, u64 in_BazaarId, u32 in_ItemId, u16 in_Sequence, const MtTypedArray<CDataItemStorageIndicateNum>& in_ItemStorageIndicateNum);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u64 BazaarId() const;
        u32 ItemId() const;
        u16 Sequence() const;
        const MtTypedArray<CDataItemStorageIndicateNum>& ItemStorageIndicateNum() const;
        MtTypedArray<CDataItemStorageIndicateNum>& ItemStorageIndicateNum();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u64 m_ullBazaarId;  // offset: 0x8
        u32 m_unItemId;  // offset: 0x10
        u16 m_usSequence;  // offset: 0x14
        MtTypedArray<CDataItemStorageIndicateNum> m_ItemStorageIndicateNum;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_BOX_GACHA_BUY_REQ
    {
    public:
        CPacket_C2S_BOX_GACHA_BUY_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_Id, u32 in_DrawId, u32 in_SettlementId, u32 in_Price);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 Id() const;
        u32 DrawId() const;
        u32 SettlementId() const;
        u32 Price() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unId;  // offset: 0x4
        u32 m_unDrawId;  // offset: 0x8
        u32 m_unSettlementId;  // offset: 0xc
        u32 m_unPrice;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_BUY_SHOP_GOODS_REQ
    {
    public:
        CPacket_C2S_BUY_SHOP_GOODS_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_GoodsIndex, u32 in_Num, u8 in_StorageType, u32 in_Price);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 GoodsIndex() const;
        u32 Num() const;
        u8 StorageType() const;
        u32 Price() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unGoodsIndex;  // offset: 0x4
        u32 m_unNum;  // offset: 0x8
        u8 m_ucStorageType;  // offset: 0xc
        u32 m_unPrice;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_CHANGE_PAWN_EQUIP_JOB_ITEM_REQ
    {
    public:
        CPacket_C2S_CHANGE_PAWN_EQUIP_JOB_ITEM_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, const MtTypedArray<CDataChangeEquipJobItem>& in_ChangeCharacterEquipJobItemList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        const MtTypedArray<CDataChangeEquipJobItem>& ChangeCharacterEquipJobItemList() const;
        MtTypedArray<CDataChangeEquipJobItem>& ChangeCharacterEquipJobItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        MtTypedArray<CDataChangeEquipJobItem> m_ChangeCharacterEquipJobItemList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_CLAN_SET_MEMBER_RANK_REQ
    {
    public:
        CPacket_C2S_CLAN_SET_MEMBER_RANK_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_CharacterID, u32 in_Rank, u32 in_Permission);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 CharacterID() const;
        u32 Rank() const;
        u32 Permission() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unCharacterID;  // offset: 0x4
        u32 m_unRank;  // offset: 0x8
        u32 m_unPermission;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_CRAFT_SKILL_ANALYZE_REQ
    {
    public:
        CPacket_C2S_CRAFT_SKILL_ANALYZE_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_CraftType, u32 in_RecipeId, u32 in_ItemId, u32 in_PawnId, const MtTypedArray<CDataCommonU32>& in_AssistPawnIds, u32 in_CreateCount);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 CraftType() const;
        u32 RecipeId() const;
        u32 ItemId() const;
        u32 PawnId() const;
        const MtTypedArray<CDataCommonU32>& AssistPawnIds() const;
        MtTypedArray<CDataCommonU32>& AssistPawnIds();
        u32 CreateCount() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucCraftType;  // offset: 0x2
        u32 m_unRecipeId;  // offset: 0x4
        u32 m_unItemId;  // offset: 0x8
        u32 m_unPawnId;  // offset: 0xc
        MtTypedArray<CDataCommonU32> m_AssistPawnIds;  // offset: 0x10
        u32 m_unCreateCount;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x34
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_CRAFT_SKILL_UP_REQ
    {
    public:
        CPacket_C2S_CRAFT_SKILL_UP_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, u32 in_SkillType, u32 in_SkillLevel);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        u32 SkillType() const;
        u32 SkillLevel() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        u32 m_unSkillType;  // offset: 0x8
        u32 m_unSkillLevel;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_CRAFT_TIME_SAVE_REQ
    {
    public:
        CPacket_C2S_CRAFT_TIME_SAVE_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, u8 in_ID, u8 in_Num, b8 in_IsInit);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        u8 ID() const;
        u8 Num() const;
        b8 IsInit() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        u8 m_ucID;  // offset: 0x8
        u8 m_ucNum;  // offset: 0x9
        b8 m_bIsInit;  // offset: 0xa
        bool m_bIsReceived;  // offset: 0xb
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_DEBUG_QUEST_FORCE_PROGRESS_REQ
    {
    public:
        CPacket_C2S_DEBUG_QUEST_FORCE_PROGRESS_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_ProgressCharacterId, u32 in_QuestScheduleId, u16 in_ProcessNo);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 ProgressCharacterId() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unProgressCharacterId;  // offset: 0x4
        u32 m_unQuestScheduleId;  // offset: 0x8
        u16 m_usProcessNo;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0xe
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_DELIVER_ITEM_REQ
    {
    public:
        CPacket_C2S_DELIVER_ITEM_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_QuestScheduleId, u16 in_ProcessNo, const MtTypedArray<CDataItemUIDList>& in_ItemUIDList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        const MtTypedArray<CDataItemUIDList>& ItemUIDList() const;
        MtTypedArray<CDataItemUIDList>& ItemUIDList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unQuestScheduleId;  // offset: 0x4
        u16 m_usProcessNo;  // offset: 0x8
        MtTypedArray<CDataItemUIDList> m_ItemUIDList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_ENEMY_BREAK_REGION_NTC
    {
    public:
        CPacket_C2S_ENEMY_BREAK_REGION_NTC();
        s32 WritePacket(CPacket* pPacket, const CStageLayoutID& in_LayoutId, u32 in_SetId, u32 in_RegionNo);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const CStageLayoutID& LayoutId() const;
        CStageLayoutID& LayoutId();
        u32 SetId() const;
        u32 RegionNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        CStageLayoutID m_LayoutId;  // offset: 0x8
        u32 m_unSetId;  // offset: 0x20
        u32 m_unRegionNo;  // offset: 0x24
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_ENEMY_GROUP_ENTRY_NOTICE
    {
    public:
        CPacket_C2S_ENEMY_GROUP_ENTRY_NOTICE();
        s32 WritePacket(CPacket* pPacket, const CStageLayoutID& in_LayoutId);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const CStageLayoutID& LayoutId() const;
        CStageLayoutID& LayoutId();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        CStageLayoutID m_LayoutId;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x20
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_ENEMY_GROUP_LEAVE_NOTICE
    {
    public:
        CPacket_C2S_ENEMY_GROUP_LEAVE_NOTICE();
        s32 WritePacket(CPacket* pPacket, const CStageLayoutID& in_LayoutId);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const CStageLayoutID& LayoutId() const;
        CStageLayoutID& LayoutId();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        CStageLayoutID m_LayoutId;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x20
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_ENTRY_BOARD_ITEM_INVITE_REQ
    {
    public:
        CPacket_C2S_ENTRY_BOARD_ITEM_INVITE_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataCommonU32>& in_CharacterIds);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataCommonU32>& CharacterIds() const;
        MtTypedArray<CDataCommonU32>& CharacterIds();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataCommonU32> m_CharacterIds;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_CAPLINK_ACHIEVE_REWARD_REQ
    {
    public:
        CPacket_C2S_GET_CAPLINK_ACHIEVE_REWARD_REQ();
        s32 WritePacket(CPacket* pPacket, const char* in_strfilteringContentId, const MtTypedArray<CDataCommonU32>& in_AchievementId);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const char* filteringContentId() const;
        const MtTypedArray<CDataCommonU32>& AchievementId() const;
        MtTypedArray<CDataCommonU32>& AchievementId();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtString m_wstrfilteringContentId;  // offset: 0x8
        MtTypedArray<CDataCommonU32> m_AchievementId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_CRAFT_GRADEUP_RECIPE_REQ
    {
    public:
        CPacket_C2S_GET_CRAFT_GRADEUP_RECIPE_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_Category, u32 in_Offset, s32 in_Num, const MtTypedArray<CDataCommonU32>& in_ItemList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 Category() const;
        u32 Offset() const;
        s32 Num() const;
        const MtTypedArray<CDataCommonU32>& ItemList() const;
        MtTypedArray<CDataCommonU32>& ItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucCategory;  // offset: 0x2
        u32 m_unOffset;  // offset: 0x4
        s32 m_nNum;  // offset: 0x8
        MtTypedArray<CDataCommonU32> m_ItemList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_CRAFT_PRODUCT_REQ
    {
    public:
        CPacket_C2S_GET_CRAFT_PRODUCT_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_CraftMainPawnID, u32 in_StorageType, u8 in_DebugFlag);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 CraftMainPawnID() const;
        u32 StorageType() const;
        u8 DebugFlag() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unCraftMainPawnID;  // offset: 0x4
        u32 m_unStorageType;  // offset: 0x8
        u8 m_ucDebugFlag;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0xd
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_CRAFT_RECIPE_DESIGNATE_REQ
    {
    public:
        CPacket_C2S_GET_CRAFT_RECIPE_DESIGNATE_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_Category, const MtTypedArray<CDataCommonU32>& in_ItemList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 Category() const;
        const MtTypedArray<CDataCommonU32>& ItemList() const;
        MtTypedArray<CDataCommonU32>& ItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucCategory;  // offset: 0x2
        MtTypedArray<CDataCommonU32> m_ItemList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_CRAFT_RECIPE_REQ
    {
    public:
        CPacket_C2S_GET_CRAFT_RECIPE_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_Category, u32 in_Offset, s32 in_Num);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 Category() const;
        u32 Offset() const;
        s32 Num() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucCategory;  // offset: 0x2
        u32 m_unOffset;  // offset: 0x4
        s32 m_nNum;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xc
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_DROP_ITEM_LIST_REQ
    {
    public:
        CPacket_C2S_GET_DROP_ITEM_LIST_REQ();
        s32 WritePacket(CPacket* pPacket, const CStageLayoutID& in_LayoutId, u32 in_Id);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const CStageLayoutID& LayoutId() const;
        CStageLayoutID& LayoutId();
        u32 Id() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        CStageLayoutID m_LayoutId;  // offset: 0x8
        u32 m_unId;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x24
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_DROP_ITEM_REQ
    {
    public:
        CPacket_C2S_GET_DROP_ITEM_REQ();
        s32 WritePacket(CPacket* pPacket, const CStageLayoutID& in_LayoutId, u32 in_Id, const MtTypedArray<CDataGatheringItemGetRequest>& in_GatheringItemGetRequestList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const CStageLayoutID& LayoutId() const;
        CStageLayoutID& LayoutId();
        u32 Id() const;
        const MtTypedArray<CDataGatheringItemGetRequest>& GatheringItemGetRequestList() const;
        MtTypedArray<CDataGatheringItemGetRequest>& GatheringItemGetRequestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        CStageLayoutID m_LayoutId;  // offset: 0x8
        u32 m_unId;  // offset: 0x20
        MtTypedArray<CDataGatheringItemGetRequest> m_GatheringItemGetRequestList;  // offset: 0x28
        bool m_bIsReceived;  // offset: 0x48
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_ITEM_SORTDATA_BIN_REQ
    {
    public:
        CPacket_C2S_GET_ITEM_SORTDATA_BIN_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataCommonU32>& in_SortList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataCommonU32>& SortList() const;
        MtTypedArray<CDataCommonU32>& SortList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataCommonU32> m_SortList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_ITEM_STORAGE_INFO_REQ
    {
    public:
        CPacket_C2S_GET_ITEM_STORAGE_INFO_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataGameItemStorage>& in_GameItemStorageList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataGameItemStorage>& GameItemStorageList() const;
        MtTypedArray<CDataGameItemStorage>& GameItemStorageList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataGameItemStorage> m_GameItemStorageList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_REQ
    {
    public:
        CPacket_C2S_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_ListNo, const MtTypedArray<CDataGetRewardBoxItem>& in_GetRewardBoxItemList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 ListNo() const;
        const MtTypedArray<CDataGetRewardBoxItem>& GetRewardBoxItemList() const;
        MtTypedArray<CDataGetRewardBoxItem>& GetRewardBoxItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unListNo;  // offset: 0x4
        MtTypedArray<CDataGetRewardBoxItem> m_GetRewardBoxItemList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_PARTY_PAWN_DATA_REQ
    {
    public:
        CPacket_C2S_GET_PARTY_PAWN_DATA_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_CharacterId, u32 in_PawnId, b8 in_IsPawnProfile);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 CharacterId() const;
        u32 PawnId() const;
        b8 IsPawnProfile() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unCharacterId;  // offset: 0x4
        u32 m_unPawnId;  // offset: 0x8
        b8 m_bIsPawnProfile;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0xd
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_GET_REWARD_BOX_ITEM_REQ
    {
    public:
        CPacket_C2S_GET_REWARD_BOX_ITEM_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_ListNo, const MtTypedArray<CDataGetRewardBoxItem>& in_GetRewardBoxItemList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 ListNo() const;
        const MtTypedArray<CDataGetRewardBoxItem>& GetRewardBoxItemList() const;
        MtTypedArray<CDataGetRewardBoxItem>& GetRewardBoxItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unListNo;  // offset: 0x4
        MtTypedArray<CDataGetRewardBoxItem> m_GetRewardBoxItemList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_JOB_VALUE_SHOP_BUY_ITEM_REQ
    {
    public:
        CPacket_C2S_JOB_VALUE_SHOP_BUY_ITEM_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_JobId, u8 in_JobValueType, u32 in_LineupId, u8 in_Num, u8 in_StorageType, u32 in_Price);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 JobId() const;
        u8 JobValueType() const;
        u32 LineupId() const;
        u8 Num() const;
        u8 StorageType() const;
        u32 Price() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucJobId;  // offset: 0x2
        u8 m_ucJobValueType;  // offset: 0x3
        u32 m_unLineupId;  // offset: 0x4
        u8 m_ucNum;  // offset: 0x8
        u8 m_ucStorageType;  // offset: 0x9
        u32 m_unPrice;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_LEADER_QUEST_PROGRESS_REQUEST_REQ
    {
    public:
        CPacket_C2S_LEADER_QUEST_PROGRESS_REQUEST_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_KeyId, u32 in_QuestScheduleId, u16 in_ProcessNo, u16 in_SequenceNo, u16 in_BlockNo);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 KeyId() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        u16 SequenceNo() const;
        u16 BlockNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unKeyId;  // offset: 0x4
        u32 m_unQuestScheduleId;  // offset: 0x8
        u16 m_usProcessNo;  // offset: 0xc
        u16 m_usSequenceNo;  // offset: 0xe
        u16 m_usBlockNo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x12
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_LEARN_ABILITY_REQ
    {
    public:
        CPacket_C2S_LEARN_ABILITY_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_Job, u32 in_AbilityID, u8 in_AbilityLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 Job() const;
        u32 AbilityID() const;
        u8 AbilityLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucJob;  // offset: 0x2
        u32 m_unAbilityID;  // offset: 0x4
        u8 m_ucAbilityLv;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x9
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_LEARN_PAWN_ABILITY_REQ
    {
    public:
        CPacket_C2S_LEARN_PAWN_ABILITY_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, u32 in_AbilityID, u8 in_AbilityLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        u32 AbilityID() const;
        u8 AbilityLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        u32 m_unAbilityID;  // offset: 0x8
        u8 m_ucAbilityLv;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0xd
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_LEARN_PAWN_NORMAL_SKILL_REQ
    {
    public:
        CPacket_C2S_LEARN_PAWN_NORMAL_SKILL_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, u8 in_Job, u32 in_SkillNo);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        u8 Job() const;
        u32 SkillNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        u8 m_ucJob;  // offset: 0x8
        u32 m_unSkillNo;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_LEARN_PAWN_SKILL_REQ
    {
    public:
        CPacket_C2S_LEARN_PAWN_SKILL_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, u8 in_Job, u32 in_SkillID, u8 in_SkillLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        u8 Job() const;
        u32 SkillID() const;
        u8 SkillLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        u8 m_ucJob;  // offset: 0x8
        u32 m_unSkillID;  // offset: 0xc
        u8 m_ucSkillLv;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_LEARN_SKILL_REQ
    {
    public:
        CPacket_C2S_LEARN_SKILL_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_Job, u32 in_SkillID, u8 in_SkillLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 Job() const;
        u32 SkillID() const;
        u8 SkillLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucJob;  // offset: 0x2
        u32 m_unSkillID;  // offset: 0x4
        u8 m_ucSkillLv;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x9
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_LOGIN_REQ
    {
    public:
        CPacket_C2S_LOGIN_REQ();
        s32 WritePacket(CPacket* pPacket, const char* in_strSessionKey, u8 in_Platform, u32 in_ClientVersion);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const char* SessionKey() const;
        u8 Platform() const;
        u32 ClientVersion() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtString m_wstrSessionKey;  // offset: 0x8
        u8 m_ucPlatform;  // offset: 0x10
        u32 m_unClientVersion;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_LOST_PAWN_WALLET_REVIVE_REQ
    {
    public:
        CPacket_C2S_LOST_PAWN_WALLET_REVIVE_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnId, u8 in_Type, u32 in_ReviveCost);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnId() const;
        u8 Type() const;
        u32 ReviveCost() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnId;  // offset: 0x4
        u8 m_ucType;  // offset: 0x8
        u32 m_unReviveCost;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_MAIL_SEND_REQ
    {
    public:
        CPacket_C2S_MAIL_SEND_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataCommonU32>& in_CharacterIdList, const char* in_strMailText);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataCommonU32>& CharacterIdList() const;
        MtTypedArray<CDataCommonU32>& CharacterIdList();
        const char* MailText() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataCommonU32> m_CharacterIdList;  // offset: 0x8
        MtString m_wstrMailText;  // offset: 0x28
        bool m_bIsReceived;  // offset: 0x30
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_MOVE_IN_SERVER_REQ
    {
    public:
        CPacket_C2S_MOVE_IN_SERVER_REQ();
        s32 WritePacket(CPacket* pPacket, const char* in_strSessionKey, u8 in_Platform, u32 in_ClientVersion);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const char* SessionKey() const;
        u8 Platform() const;
        u32 ClientVersion() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtString m_wstrSessionKey;  // offset: 0x8
        u8 m_ucPlatform;  // offset: 0x10
        u32 m_unClientVersion;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_PAWN_EXPEDITION_GET_REWARD_DROP_ITEM_REQ
    {
    public:
        CPacket_C2S_PAWN_EXPEDITION_GET_REWARD_DROP_ITEM_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnRewardBoxId, const MtTypedArray<CDataGatheringItemGetRequest>& in_GatheringItemGetRequestList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnRewardBoxId() const;
        const MtTypedArray<CDataGatheringItemGetRequest>& GatheringItemGetRequestList() const;
        MtTypedArray<CDataGatheringItemGetRequest>& GatheringItemGetRequestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnRewardBoxId;  // offset: 0x4
        MtTypedArray<CDataGatheringItemGetRequest> m_GatheringItemGetRequestList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_QUEST_PROGRESS_REQ
    {
    public:
        CPacket_C2S_QUEST_PROGRESS_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_KeyId, u32 in_ProgressCharacterId, u32 in_QuestScheduleId, u16 in_ProcessNo);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 KeyId() const;
        u32 ProgressCharacterId() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unKeyId;  // offset: 0x4
        u32 m_unProgressCharacterId;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        u16 m_usProcessNo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x12
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_QUICK_PARTY_REGISTER_REQ
    {
    public:
        CPacket_C2S_QUICK_PARTY_REGISTER_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_ContentType, u32 in_Num, const CQuickPartyMatching& in_QuickPartyMatching);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 ContentType() const;
        u32 Num() const;
        const CQuickPartyMatching& QuickPartyMatching() const;
        CQuickPartyMatching& QuickPartyMatching();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unContentType;  // offset: 0x4
        u32 m_unNum;  // offset: 0x8
        CQuickPartyMatching m_QuickPartyMatching;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_RANKING_DATA_CHARACTER_ID_REQ
    {
    public:
        CPacket_C2S_RANKING_DATA_CHARACTER_ID_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_Id, const MtTypedArray<CDataCommonU32>& in_CharacterIdList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 Id() const;
        const MtTypedArray<CDataCommonU32>& CharacterIdList() const;
        MtTypedArray<CDataCommonU32>& CharacterIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unId;  // offset: 0x4
        MtTypedArray<CDataCommonU32> m_CharacterIdList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_REQ
    {
    public:
        CPacket_C2S_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_Id, u32 in_Rank, u8 in_Num);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 Id() const;
        u32 Rank() const;
        u8 Num() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unId;  // offset: 0x4
        u32 m_unRank;  // offset: 0x8
        u8 m_ucNum;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0xd
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_RANKING_DATA_RANK_REQ
    {
    public:
        CPacket_C2S_RANKING_DATA_RANK_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_Id, u32 in_Rank, u8 in_Num);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 Id() const;
        u32 Rank() const;
        u8 Num() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unId;  // offset: 0x4
        u32 m_unRank;  // offset: 0x8
        u8 m_ucNum;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0xd
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_RENT_REGISTERED_PAWN_REQ
    {
    public:
        CPacket_C2S_RENT_REGISTERED_PAWN_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_SlotNo, s32 in_RequestPawnId, u64 in_Updated, u32 in_RentalCost);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 SlotNo() const;
        s32 RequestPawnId() const;
        u64 Updated() const;
        u32 RentalCost() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucSlotNo;  // offset: 0x2
        s32 m_nRequestPawnId;  // offset: 0x4
        u64 m_ullUpdated;  // offset: 0x8
        u32 m_unRentalCost;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_RESERVE_SERVER_REQ
    {
    public:
        CPacket_C2S_RESERVE_SERVER_REQ();
        s32 WritePacket(CPacket* pPacket, u16 in_GameServerUniqueID, u8 in_Type, u8 in_RotationServerID, const MtTypedArray<CDataCommonU32>& in_ReserveInfoList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u16 GameServerUniqueID() const;
        u8 Type() const;
        u8 RotationServerID() const;
        const MtTypedArray<CDataCommonU32>& ReserveInfoList() const;
        MtTypedArray<CDataCommonU32>& ReserveInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u16 m_usGameServerUniqueID;  // offset: 0x2
        u8 m_ucType;  // offset: 0x4
        u8 m_ucRotationServerID;  // offset: 0x5
        MtTypedArray<CDataCommonU32> m_ReserveInfoList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SEND_LEADER_WAIT_ORDER_QUEST_LIST_REQ
    {
    public:
        CPacket_C2S_SEND_LEADER_WAIT_ORDER_QUEST_LIST_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataCommonU32>& in_QuestScheduleIdList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataCommonU32>& QuestScheduleIdList() const;
        MtTypedArray<CDataCommonU32>& QuestScheduleIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataCommonU32> m_QuestScheduleIdList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SERVER_UI_COMMAND_REQ
    {
    public:
        CPacket_C2S_SERVER_UI_COMMAND_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_Id, u32 in_Command, u32 in_ArgNum1, u32 in_ArgNum2);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 Id() const;
        u32 Command() const;
        u32 ArgNum1() const;
        u32 ArgNum2() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unId;  // offset: 0x4
        u32 m_unCommand;  // offset: 0x8
        u32 m_unArgNum1;  // offset: 0xc
        u32 m_unArgNum2;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_ABILITY_REQ
    {
    public:
        CPacket_C2S_SET_ABILITY_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_Job, u8 in_SlotNo, u32 in_AbilityID, u8 in_AbilityLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 Job() const;
        u8 SlotNo() const;
        u32 AbilityID() const;
        u8 AbilityLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucJob;  // offset: 0x2
        u8 m_ucSlotNo;  // offset: 0x3
        u32 m_unAbilityID;  // offset: 0x4
        u8 m_ucAbilityLv;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x9
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_COMMUNICATION_SHORTCUT_LIST_REQ
    {
    public:
        CPacket_C2S_SET_COMMUNICATION_SHORTCUT_LIST_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataCommunicationShortCut>& in_ShortcutList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataCommunicationShortCut>& ShortcutList() const;
        MtTypedArray<CDataCommunicationShortCut>& ShortcutList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataCommunicationShortCut> m_ShortcutList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_MESSAGE_SET_REQ
    {
    public:
        CPacket_C2S_SET_MESSAGE_SET_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataCharacterMsgSet>& in_MessageSetList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataCharacterMsgSet>& MessageSetList() const;
        MtTypedArray<CDataCharacterMsgSet>& MessageSetList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataCharacterMsgSet> m_MessageSetList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_OFF_PAWN_SKILL_REQ
    {
    public:
        CPacket_C2S_SET_OFF_PAWN_SKILL_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, u8 in_Job, u8 in_SlotNo);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        u8 Job() const;
        u8 SlotNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        u8 m_ucJob;  // offset: 0x8
        u8 m_ucSlotNo;  // offset: 0x9
        bool m_bIsReceived;  // offset: 0xa
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_PAWN_ABILITY_REQ
    {
    public:
        CPacket_C2S_SET_PAWN_ABILITY_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, u8 in_Job, u8 in_SlotNo, u32 in_AbilityID, u8 in_AbilityLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        u8 Job() const;
        u8 SlotNo() const;
        u32 AbilityID() const;
        u8 AbilityLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        u8 m_ucJob;  // offset: 0x8
        u8 m_ucSlotNo;  // offset: 0x9
        u32 m_unAbilityID;  // offset: 0xc
        u8 m_ucAbilityLv;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_PAWN_PROFILE_REQ
    {
    public:
        CPacket_C2S_SET_PAWN_PROFILE_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnId, const CArisenProfile& in_ProfileInfo, const char* in_strComment);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnId() const;
        const CArisenProfile& ProfileInfo() const;
        CArisenProfile& ProfileInfo();
        const char* Comment() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnId;  // offset: 0x4
        CArisenProfile m_ProfileInfo;  // offset: 0x8
        MtString m_wstrComment;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x38
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_PAWN_SKILL_REQ
    {
    public:
        CPacket_C2S_SET_PAWN_SKILL_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, u8 in_Job, u8 in_SlotNo, u32 in_SkillID, u8 in_SkillLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        u8 Job() const;
        u8 SlotNo() const;
        u32 SkillID() const;
        u8 SkillLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        u8 m_ucJob;  // offset: 0x8
        u8 m_ucSlotNo;  // offset: 0x9
        u32 m_unSkillID;  // offset: 0xc
        u8 m_ucSkillLv;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_SHORTCUT_LIST_REQ
    {
    public:
        CPacket_C2S_SET_SHORTCUT_LIST_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataShortCut>& in_ShortcutList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataShortCut>& ShortcutList() const;
        MtTypedArray<CDataShortCut>& ShortcutList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataShortCut> m_ShortcutList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SET_SKILL_REQ
    {
    public:
        CPacket_C2S_SET_SKILL_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_Job, u8 in_SlotNo, u32 in_SkillID, u8 in_SkillLv);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 Job() const;
        u8 SlotNo() const;
        u32 SkillID() const;
        u8 SkillLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucJob;  // offset: 0x2
        u8 m_ucSlotNo;  // offset: 0x3
        u32 m_unSkillID;  // offset: 0x4
        u8 m_ucSkillLv;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x9
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_STAY_INN_REQ
    {
    public:
        CPacket_C2S_STAY_INN_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_InnID, u32 in_Price, u32 in_HpMax, const MtTypedArray<CDataPawnHp>& in_PawnHpMaxList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 InnID() const;
        u32 Price() const;
        u32 HpMax() const;
        const MtTypedArray<CDataPawnHp>& PawnHpMaxList() const;
        MtTypedArray<CDataPawnHp>& PawnHpMaxList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unInnID;  // offset: 0x4
        u32 m_unPrice;  // offset: 0x8
        u32 m_unHpMax;  // offset: 0xc
        MtTypedArray<CDataPawnHp> m_PawnHpMaxList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_STAY_PENALTY_HEAL_INN_REQ
    {
    public:
        CPacket_C2S_STAY_PENALTY_HEAL_INN_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_Price, u32 in_HpMax, const MtTypedArray<CDataPawnHp>& in_PawnHpMaxList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 Price() const;
        u32 HpMax() const;
        const MtTypedArray<CDataPawnHp>& PawnHpMaxList() const;
        MtTypedArray<CDataPawnHp>& PawnHpMaxList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPrice;  // offset: 0x4
        u32 m_unHpMax;  // offset: 0x8
        MtTypedArray<CDataPawnHp> m_PawnHpMaxList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_SUPPORT_POINT_USE_REQ
    {
    public:
        CPacket_C2S_SUPPORT_POINT_USE_REQ();
        s32 WritePacket(CPacket* pPacket, const MtTypedArray<CDataUseSupportPoint>& in_UsePointList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        const MtTypedArray<CDataUseSupportPoint>& UsePointList() const;
        MtTypedArray<CDataUseSupportPoint>& UsePointList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        MtTypedArray<CDataUseSupportPoint> m_UsePointList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_UPDATE_EQUIP_PRESET_REQ
    {
    public:
        CPacket_C2S_UPDATE_EQUIP_PRESET_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PresetNo, u32 in_PawnID, u32 in_Type, const char* in_strPresetName);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PresetNo() const;
        u32 PawnID() const;
        u32 Type() const;
        const char* PresetName() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPresetNo;  // offset: 0x4
        u32 m_unPawnID;  // offset: 0x8
        u32 m_unType;  // offset: 0xc
        MtString m_wstrPresetName;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_UPDATE_PAWN_EDIT_PARAM_REQ
    {
    public:
        CPacket_C2S_UPDATE_PAWN_EDIT_PARAM_REQ();
        s32 WritePacket(CPacket* pPacket, u8 in_SlotNo, u8 in_UpdateType, const CEditInfo& in_EditInfo);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u8 SlotNo() const;
        u8 UpdateType() const;
        const CEditInfo& EditInfo() const;
        CEditInfo& EditInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u8 m_ucSlotNo;  // offset: 0x2
        u8 m_ucUpdateType;  // offset: 0x3
        CEditInfo m_EditInfo;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x90
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_UPDATE_PAWN_REACTION_LIST_REQ
    {
    public:
        CPacket_C2S_UPDATE_PAWN_REACTION_LIST_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_PawnID, const MtTypedArray<CDataPawnReaction>& in_PawnReactionList);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 PawnID() const;
        const MtTypedArray<CDataPawnReaction>& PawnReactionList() const;
        MtTypedArray<CDataPawnReaction>& PawnReactionList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unPawnID;  // offset: 0x4
        MtTypedArray<CDataPawnReaction> m_PawnReactionList;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0x28
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_C2S_WARP_REQ
    {
    public:
        CPacket_C2S_WARP_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_CurrentPointID, u32 in_DestPointID, u32 in_Price);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 CurrentPointID() const;
        u32 DestPointID() const;
        u32 Price() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unCurrentPointID;  // offset: 0x4
        u32 m_unDestPointID;  // offset: 0x8
        u32 m_unPrice;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    };
}  // namespace nUserSession
