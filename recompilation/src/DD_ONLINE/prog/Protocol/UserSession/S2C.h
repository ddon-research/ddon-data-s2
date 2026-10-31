#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../PacketData/Achievement.h"
#include "../PacketData/AreaMaster.h"
#include "../PacketData/BoxGacha.h"
#include "../PacketData/Character.h"
#include "../PacketData/CharacterCommon.h"
#include "../PacketData/CharacterParam.h"
#include "../PacketData/Clan.h"
#include "../PacketData/Common.h"
#include "../PacketData/Community.h"
#include "../PacketData/Context.h"
#include "../PacketData/Craft.h"
#include "../PacketData/DispelItem.h"
#include "../PacketData/Enemy.h"
#include "../PacketData/EntryBoard.h"
#include "../PacketData/GP.h"
#include "../PacketData/Gacha.h"
#include "../PacketData/Item.h"
#include "../PacketData/JobMaster.h"
#include "../PacketData/JobOrbTree.h"
#include "../PacketData/Loading.h"
#include "../PacketData/Mail.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtString.h"
#include "../PacketData/Party.h"
#include "../PacketData/Pawn.h"
#include "../PacketData/Quest.h"
#include "../PacketData/Ranking.h"
#include "../PacketData/ScreenShot.h"
#include "../PacketData/Server.h"
#include "../PacketData/ServerSetting.h"
#include "../PacketData/ServerUI.h"
#include "../PacketData/Shop.h"
#include "../PacketData/Skill.h"
#include "../PacketData/Stage.h"
#include "../PacketData/StampBonus.h"
#include "../PacketData/SupportPoint.h"
#include "../PacketData/Warp.h"
#include "../PacketData/Weather.h"
#include "../../cPacket.h"

// Forward declarations
class CDataAbilityParam;
class CDataAchieveRewardCommon;
class CDataAchievementFurnitureReward;
class CDataAchievementProgress;
class CDataAchievementRewardProgress;
class CDataAreaBonus;
class CDataAreaInfoList;
class CDataAreaQuestHint;
class CDataAreaRank;
class CDataAreaSpotSet;
class CDataAreaWarpPoint;
class CDataBattleResultInfo;
class CDataBorderRewardRecord;
class CDataBoxGachaInfo;
class CDataBoxGachaItemInfo;
class CDataCAPtoGPChangeElement;
class CDataCharacterLevelParam;
class CDataCharacterListElement;
class CDataClanConciergeInfo;
class CDataClanDungeonInfo;
class CDataClanFunctionInfo;
class CDataClanHistoryElement;
class CDataClanJoinRequest;
class CDataClanMemberInfo;
class CDataClanParam;
class CDataClanPartnerPawnInfo;
class CDataClanScoutEntryInviteInfo;
class CDataClanScoutEntrySearchResult;
class CDataClanSearchResult;
class CDataClanShopBuffItem;
class CDataClanShopConciergeItem;
class CDataClanShopFunctionItem;
class CDataClanShopInfo;
class CDataClanShopLineupName;
class CDataClanValueInfo;
class CDataCommonU32;
class CDataCommunityCharacterBaseInfo;
class CDataContentsPlayEnd;
class CDataContextAcquirementData;
class CDataContextNormalSkillData;
class CDataContextSetBase;
class CDataCraftPawnList;
class CDataCraftProduct;
class CDataCraftProductInfo;
class CDataCraftProgress;
class CDataCraftSkillAnalyzeResult;
class CDataCraftTimeSaveCost;
class CDataCycleContentsExtraReward;
class CDataCycleContentsNews;
class CDataCycleContentsPlayEnd;
class CDataCycleContentsReward;
class CDataCycleContentsRewardRecord;
class CDataDispelBaseItem;
class CDataDispelCategoryInfo;
class CDataDispelResultInfo;
class CDataEncounterPawnInfo;
class CDataEndContentsGroup;
class CDataEntryItem;
class CDataExpiredQuestList;
class CDataFavoriteWarpPoint;
class CDataFortDefenseNoticeData;
class CDataFreeRentalPawnList;
class CDataGPCourseAvailable;
class CDataGPCourseValid;
class CDataGPDetail;
class CDataGPPeriod;
class CDataGPShopBuyHistoryElement;
class CDataGPShopDisplayLineup;
class CDataGPShopDisplayType;
class CDataGPShopLineupElementCourse;
class CDataGachaInfo;
class CDataGachaItemInfo;
class CDataGameItemStorageInfo;
class CDataGameServerListInfo;
class CDataGameSetting;
class CDataGameTime;
class CDataGameTimeBaseInfo;
class CDataGatheringItemElement;
class CDataGoodsParam;
class CDataItemEquipElement;
class CDataItemUpdateResult;
class CDataJobChangeInfo;
class CDataJobOrbDevoteElement;
class CDataJobOrbTreeStatus;
class CDataJobPlayPoint;
class CDataJobValueShopItem;
class CDataLearnedAcquirementParam;
class CDataLightQuestList;
class CDataLightQuestOrderList;
class CDataLoadingInfoSchedules;
class CDataLotQuestList;
class CDataLotQuestOrderList;
class CDataMailInfo;
class CDataMailTextInfo;
class CDataMainQuestList;
class CDataMainQuestOrderList;
class CDataMatchingProfile;
class CDataNormalSkillParam;
class CDataOmData;
class CDataOrbGainExtendParam;
class CDataOrderConditionInfo;
class CDataPartnerPawnData;
class CDataPartyMemberMinimum;
class CDataPartyQuestProgressInfo;
class CDataPawnExpeditionClanSallySpotInfo;
class CDataPawnExpeditionInformation;
class CDataPawnInfo;
class CDataPawnJobChangeInfo;
class CDataPawnTotalScore;
class CDataPresetAbilityParam;
class CDataPriorityQuest;
class CDataPriorityQuestSetting;
class CDataQuestContentsSituationInfo;
class CDataQuestContentsSituationInfoDetail;
class CDataQuestDefine;
class CDataQuestFlag;
class CDataQuestId;
class CDataQuestIdScheduleId;
class CDataQuestLayoutFlag;
class CDataQuestPartyBonusInfo;
class CDataQuestPhaseEvent;
class CDataQuestPointDetail;
class CDataQuestProcessState;
class CDataQuestProgressWork;
class CDataRaidBossNoticeData;
class CDataRankingBoard;
class CDataRankingData;
class CDataRankingRewardRecord;
class CDataRecommendedQuestInfoList;
class CDataReleaseAcquirementParam;
class CDataReleaseAreaInfoSet;
class CDataReleaseElement;
class CDataReleaseOrbElement;
class CDataRewardBoxRecord;
class CDataRewardItemInfo;
class CDataScreenShotCategory;
class CDataSetAcquirementParam;
class CDataSetQuestInfoList;
class CDataSetQuestList;
class CDataSetQuestOpenDate;
class CDataSetQuestOrderList;
class CDataSkillParam;
class CDataSpotInfo;
class CDataStageLayoutID;
class CDataStampBonusDaily;
class CDataStampBonusTotal;
class CDataSupportRate;
class CDataTimeGainQuestPlayStartData;
class CDataTimeLimitedQuestList;
class CDataTimeLimitedQuestOrderList;
class CDataTraningRoomEnemyHeader;
class CDataTutorialQuestList;
class CDataTutorialQuestOrderList;
class CDataUIListCommand;
class CDataUIListElement;
class CDataUpdateWalletPoint;
class CDataUseSupportPointRes;
class CDataWarpPoint;
class CDataWeatherForecast;
class CDataWorldInfo;
class CDataWorldManageQuestList;
class CDataWorldManageQuestOrderList;
class CPacket;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cGatherItemList;
class cMenuCharacterList;
class cMenuEntryBoardItemList;
class cNetGameServer;
class sCraftManager;
class sQuestManagerExt;

// Declarations
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_REWARD_RECEIVE_RES; }
namespace nUserSession { class CPacket_S2C_ACTIVATE_JOB_ORDER_RES; }
namespace nUserSession { class CPacket_S2C_AREA_WARP_RES; }
namespace nUserSession { class CPacket_S2C_BAZAAR_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_BAZAAR_EXHIBIT_RES; }
namespace nUserSession { class CPacket_S2C_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_RES; }
namespace nUserSession { class CPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES; }
namespace nUserSession { class CPacket_S2C_BAZAAR_PROCEEDS_NTC; }
namespace nUserSession { class CPacket_S2C_BAZAAR_PROCEEDS_RES; }
namespace nUserSession { class CPacket_S2C_BAZAAR_RECEIVE_PROCEEDS_RES; }
namespace nUserSession { class CPacket_S2C_BAZAAR_RE_EXHIBIT_RES; }
namespace nUserSession { class CPacket_S2C_BOX_GACHA_BUY_RES; }
namespace nUserSession { class CPacket_S2C_BOX_GACHA_DRAW_INFO_RES; }
namespace nUserSession { class CPacket_S2C_BOX_GACHA_LIST_RES; }
namespace nUserSession { class CPacket_S2C_BOX_GACHA_RESET_RES; }
namespace nUserSession { class CPacket_S2C_BUY_AREA_QUEST_HINT_RES; }
namespace nUserSession { class CPacket_S2C_BUY_SHOP_GOODS_RES; }
namespace nUserSession { class CPacket_S2C_CANCEL_CRAFT_RES; }
namespace nUserSession { class CPacket_S2C_CANCEL_PRIORITY_QUEST_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_CAP_TO_GP_RES; }
namespace nUserSession { class CPacket_S2C_CHARACTER_ADD_WALLET_POINT_NOTICE; }
namespace nUserSession { class CPacket_S2C_CHARACTER_GOLDEN_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_CHARACTER_JOB_EXP_UP_NOTICE; }
namespace nUserSession { class CPacket_S2C_CHARACTER_JOB_LEVEL_UP_NOTICE; }
namespace nUserSession { class CPacket_S2C_CHARACTER_JOB_LEVEL_UP_OTHER_NOTICE; }
namespace nUserSession { class CPacket_S2C_CHARACTER_PENALTY_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_CHARACTER_POINT_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_CHARACTER_REVIVE_NOTICE; }
namespace nUserSession { class CPacket_S2C_CHARACTER_SEARCH_RES; }
namespace nUserSession { class CPacket_S2C_CHARACTER_SUB_WALLET_POINT_NOTICE; }
namespace nUserSession { class CPacket_S2C_CHARGE_REVIVE_POINT_RES; }
namespace nUserSession { class CPacket_S2C_CHECK_QUEST_DISTRIBUTION_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_BASE_GET_INFO_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_BASE_RELEASE_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_BASE_RELEASE_STATE_UPDATE_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_CANCEL_JOIN_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_CANCEL_JOIN_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_CONCIERGE_UPDATE_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_EXPEL_MEMBER_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_HISTORY_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_INFO_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_MEMBER_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_MEMBER_NUM_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_INVITE_ACCEPT_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_INVITE_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_JOIN_NOTICE; }
namespace nUserSession { class CPacket_S2C_CLAN_LEAVE_MEMBER_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_LEVEL_UP_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_NEGOTIATE_MASTER_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_POINT_ADD_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_QUEST_CLEAR_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_REGISTER_JOIN_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_DISAPPROVE_INVITE_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_INVITE_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_REGISTER_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SEARCH_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SETTING_UPDATE_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SET_MEMBER_RANK_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_SET_MEMBER_RANK_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SHOP_GET_BUFF_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_UPDATE_NTC; }
namespace nUserSession { class CPacket_S2C_CLAN_UPDATE_RES; }
namespace nUserSession { class CPacket_S2C_CLIENT_CHALLENGE_RES; }
namespace nUserSession { class CPacket_S2C_COG_LOGIN_SKIP_DISABLE_RES; }
namespace nUserSession { class CPacket_S2C_COG_LOGIN_SKIP_FLAG_RES; }
namespace nUserSession { class CPacket_S2C_COMMUNITY_CHARACTER_STATUS_GET_RES; }
namespace nUserSession { class CPacket_S2C_CONSUME_STORAGE_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_CRAFT_EXP_UP_NOTICE; }
namespace nUserSession { class CPacket_S2C_CRAFT_RANK_UP_NOTICE; }
namespace nUserSession { class CPacket_S2C_CRAFT_SKILL_ANALYZE_RES; }
namespace nUserSession { class CPacket_S2C_CRAFT_SKILL_UP_RES; }
namespace nUserSession { class CPacket_S2C_CRAFT_TIME_SAVE_RES; }
namespace nUserSession { class CPacket_S2C_CREATE_MYPAWN_RES; }
namespace nUserSession { class CPacket_S2C_CYCLE_CONTENTS_ENABLE_NOTICE; }
namespace nUserSession { class CPacket_S2C_CYCLE_CONTENTS_END_NOTICE; }
namespace nUserSession { class CPacket_S2C_CYCLE_CONTENTS_PLAY_END_NOTICE; }
namespace nUserSession { class CPacket_S2C_CYCLE_CONTENTS_PLAY_END_RES; }
namespace nUserSession { class CPacket_S2C_CYCLE_CONTENTS_PLAY_START_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_COMMAND_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_CYCLE_CONTENTS_POINT_UPLOAD_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_ENEMY_SET_PRESET_FIX_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_GET_QUEST_FLAG_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_MAIN_QUEST_JUMP_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_QUEST_RESET_ALL_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_QUEST_RESET_RES; }
namespace nUserSession { class CPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE; }
namespace nUserSession { class CPacket_S2C_DECIDE_DELIVERY_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_DELETE_FAVORITE_PAWN_RES; }
namespace nUserSession { class CPacket_S2C_DELETE_MYPAWN_RES; }
namespace nUserSession { class CPacket_S2C_DELIVER_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_EJECTION_NTC; }
namespace nUserSession { class CPacket_S2C_ENCOUNTER_PAWN_NOTICE; }
namespace nUserSession { class CPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_ENEMY_KILL_RES; }
namespace nUserSession { class CPacket_S2C_ENEMY_STAGE_BOSS_ANNIHILATE_NTC; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_FORCE_START_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_INFO_LOCK_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_INFO_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_INVITE_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_PARTY_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_READY_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE; }
namespace nUserSession { class CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_EXCHANGE_OM_INSTANT_KEY_VALUE_RES; }
namespace nUserSession { class CPacket_S2C_EXTEND_EQUIP_SLOT_NTC; }
namespace nUserSession { class CPacket_S2C_EXTEND_MAIN_PAWN_SLOT_NTC; }
namespace nUserSession { class CPacket_S2C_EXTEND_SUPPORT_PAWN_SLOT_NTC; }
namespace nUserSession { class CPacket_S2C_FAVORITE_WARP_RES; }
namespace nUserSession { class CPacket_S2C_FINISH_CRAFT_NOTICE; }
namespace nUserSession { class CPacket_S2C_FINISH_DEATH_PENALTY_OTHER_NOTICE; }
namespace nUserSession { class CPacket_S2C_FINISH_LANTERN_NOTICE; }
namespace nUserSession { class CPacket_S2C_FINISH_LANTERN_OTHER_NOTICE; }
namespace nUserSession { class CPacket_S2C_FORT_DEFENSE_NOTICE; }
namespace nUserSession { class CPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE; }
namespace nUserSession { class CPacket_S2C_FURNITURE_LAYOUT_RES; }
namespace nUserSession { class CPacket_S2C_GACHA_BUY_RES; }
namespace nUserSession { class CPacket_S2C_GACHA_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GAIN_PAWN_PARAM_NTC; }
namespace nUserSession { class CPacket_S2C_GAME_TIME_BASEINFO_NTC; }
namespace nUserSession { class CPacket_S2C_GET_ABILITY_COST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_BONUS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_POINT_DEBUG_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_SUPPLY_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_SUPPLY_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_WARP_POINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CAPLINK_ACHIEVE_REWARD_RES; }
namespace nUserSession { class CPacket_S2C_GET_CAP_RES; }
namespace nUserSession { class CPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CHARACTER_BINARY_STATUS_NTC; }
namespace nUserSession { class CPacket_S2C_GET_CHEAT_INFO_REQ; }
namespace nUserSession { class CPacket_S2C_GET_CRAFT_LOCKED_ELEMENT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_CRAFT_PRODUCT_RES; }
namespace nUserSession { class CPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CRAFT_SETTING_RES; }
namespace nUserSession { class CPacket_S2C_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CYCLE_CONTENTS_NEWS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CYCLE_CONTENTS_NOW_POINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CYCLE_CONTENTS_POINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CYCLE_CONTENTS_REWARD_RES; }
namespace nUserSession { class CPacket_S2C_GET_DISPEL_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES; }
namespace nUserSession { class CPacket_S2C_GET_DROP_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_END_CONTENTS_GROUP_RES; }
namespace nUserSession { class CPacket_S2C_GET_EXP_MODE_RES; }
namespace nUserSession { class CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_GAME_SETTING_RES; }
namespace nUserSession { class CPacket_S2C_GET_GP_DETAIL_RES; }
namespace nUserSession { class CPacket_S2C_GET_GP_PERIOD_RES; }
namespace nUserSession { class CPacket_S2C_GET_GP_RES; }
namespace nUserSession { class CPacket_S2C_GET_INSTANT_KEY_VALUE_UL_RES; }
namespace nUserSession { class CPacket_S2C_GET_ITEM_STORAGE_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_JOB_CHANGE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEARNED_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LIGHT_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LOGIN_ANNOUNCEMENT_RES; }
namespace nUserSession { class CPacket_S2C_GET_LOT_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_MAIN_QUEST_LIST_END_NOTICE; }
namespace nUserSession { class CPacket_S2C_GET_MAIN_QUEST_LIST_NOTICE; }
namespace nUserSession { class CPacket_S2C_GET_MAIN_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_MATCHING_PROFILE_RES; }
namespace nUserSession { class CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_RES; }
namespace nUserSession { class CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_OM_INSTANT_KEY_VALUE_RES; }
namespace nUserSession { class CPacket_S2C_GET_ORB_GAIN_EXTEND_PARAM_RES; }
namespace nUserSession { class CPacket_S2C_GET_PARTY_PAWN_DATA_RES; }
namespace nUserSession { class CPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_ABILITY_COST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES; }
namespace nUserSession { class CPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES; }
namespace nUserSession { class CPacket_S2C_GET_PRESET_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PRIORITY_QUEST_RES; }
namespace nUserSession { class CPacket_S2C_GET_QUEST_COMPLETE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES; }
namespace nUserSession { class CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_REAL_TIME_RES; }
namespace nUserSession { class CPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RELEASE_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RENTED_PAWN_DATA_RES; }
namespace nUserSession { class CPacket_S2C_GET_REVIVE_CHARGEABLE_TIME_RES; }
namespace nUserSession { class CPacket_S2C_GET_REVIVE_POINT_RES; }
namespace nUserSession { class CPacket_S2C_GET_REWARD_BOX_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_GET_REWARD_BOX_LIST_NUM_RES; }
namespace nUserSession { class CPacket_S2C_GET_REWARD_BOX_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES; }
namespace nUserSession { class CPacket_S2C_GET_SERVER_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_CONTEXT_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_QUEST_LIST_NOTICE; }
namespace nUserSession { class CPacket_S2C_GET_SET_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SHOP_GOODS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SPOT_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_STAY_PRICE_RES; }
namespace nUserSession { class CPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_WARP_POINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_WORLD_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_NOTICE; }
namespace nUserSession { class CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_END_NTC; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_EXTEND_NTC; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_GET_VALID_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_GET_VERSION_RES; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_START_NTC; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_START_PARTY_NTC; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_USE_FROM_AVAILABLE_RES; }
namespace nUserSession { class CPacket_S2C_GP_EDIT_GET_GP_PRICE_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_VOICE_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_DISPLAY_BUY_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_NTC; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_KICK_CHARACTER_RES; }
namespace nUserSession { class CPacket_S2C_INSTANCE_AREA_RESET_NTC; }
namespace nUserSession { class CPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES; }
namespace nUserSession { class CPacket_S2C_JOIN_LOBBY_QUEST_INFO_NOTICE; }
namespace nUserSession { class CPacket_S2C_JOIN_PARTY_MYPAWN_RES; }
namespace nUserSession { class CPacket_S2C_JOIN_PARTY_RENTED_PAWN_RES; }
namespace nUserSession { class CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_NOTICE; }
namespace nUserSession { class CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_RES; }
namespace nUserSession { class CPacket_S2C_LEARN_ABILITY_RES; }
namespace nUserSession { class CPacket_S2C_LEARN_NORMAL_SKILL_RES; }
namespace nUserSession { class CPacket_S2C_LEARN_PAWN_ABILITY_RES; }
namespace nUserSession { class CPacket_S2C_LEARN_PAWN_NORMAL_SKILL_RES; }
namespace nUserSession { class CPacket_S2C_LEARN_PAWN_SKILL_RES; }
namespace nUserSession { class CPacket_S2C_LEARN_SKILL_RES; }
namespace nUserSession { class CPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES; }
namespace nUserSession { class CPacket_S2C_LOADING_GET_INFO_RES; }
namespace nUserSession { class CPacket_S2C_LOBBY_CHAT_MSG_RES; }
namespace nUserSession { class CPacket_S2C_LOBBY_LEAVE_RES; }
namespace nUserSession { class CPacket_S2C_LOGIN_RES; }
namespace nUserSession { class CPacket_S2C_LOST_PAWN_GOLDEN_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_LOST_PAWN_POINT_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_LOST_PAWN_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_LOST_PAWN_WALLET_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_DELETE_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_GET_LIST_FOOT_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_GET_LIST_HEAD_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_GET_TEXT_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_SEND_NTC; }
namespace nUserSession { class CPacket_S2C_MASTER_THROW_RES; }
namespace nUserSession { class CPacket_S2C_MOVE_IN_SERVER_RES; }
namespace nUserSession { class CPacket_S2C_MOVE_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_MY_ROOM_BGM_UPDATE_RES; }
namespace nUserSession { class CPacket_S2C_MY_ROOM_RELEASE_RES; }
namespace nUserSession { class CPacket_S2C_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_NOTICE; }
namespace nUserSession { class CPacket_S2C_OPEN_UI_NTC; }
namespace nUserSession { class CPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES; }
namespace nUserSession { class CPacket_S2C_PARTNER_PAWN_SET_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_BREAKUP_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_BREAKUP_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_CHANGE_HOST_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_CHANGE_LEADER_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_CHANGE_LEADER_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_GET_CONTENT_NUMBER_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_CANCEL_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_ENTRY_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_FAIL_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_REFUSE_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_JOIN_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_LEAVE_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_MEMBER_KICK_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_MEMBER_SET_VALUE_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE; }
namespace nUserSession { class CPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE; }
namespace nUserSession { class CPacket_S2C_PARTY_WARP_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_ABILITY_SET_NTC; }
namespace nUserSession { class CPacket_S2C_PAWN_CUSTOM_SKILL_SET_NTC; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_CANCEL_SALLY_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_CHANGE_GOLDEN_SALLY_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_CHARGE_SALLY_COUNT_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_INFO_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_SALLY_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_GOLDEN_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_JOB_LEVEL_UP_MEMBER_NOTICE; }
namespace nUserSession { class CPacket_S2C_PAWN_JOB_LEVEL_UP_NOTICE; }
namespace nUserSession { class CPacket_S2C_PAWN_LIKABILITY_UP_NTC; }
namespace nUserSession { class CPacket_S2C_PAWN_LOST_NOTICE; }
namespace nUserSession { class CPacket_S2C_PAWN_LOST_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_NORMAL_SKILL_LEARN_NTC; }
namespace nUserSession { class CPacket_S2C_PAWN_POINT_REVIVE_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_REVIVE_NOTICE; }
namespace nUserSession { class CPacket_S2C_PING_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_ADD_TIMER_NOTICE; }
namespace nUserSession { class CPacket_S2C_PLAY_END_NOTICE; }
namespace nUserSession { class CPacket_S2C_PLAY_END_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_ENTRY_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_ENTRY_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_FORCE_INTERRUPT_NOTICE; }
namespace nUserSession { class CPacket_S2C_PLAY_INTERRUPT_ANSWER_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_INTERRUPT_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_INTERRUPT_RESULT_NOTICE; }
namespace nUserSession { class CPacket_S2C_PLAY_RESTART_TIMER_NOTICE; }
namespace nUserSession { class CPacket_S2C_PLAY_START_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_START_TIMER_NOTICE; }
namespace nUserSession { class CPacket_S2C_PLAY_START_TIMER_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_STOP_TIMER_NOTICE; }
namespace nUserSession { class CPacket_S2C_PLAY_TIMEUP_NOTICE; }
namespace nUserSession { class CPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES; }
namespace nUserSession { class CPacket_S2C_QUEST_CANCEL_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_QUEST_COMPLETE_FLAG_CLEAR_RES; }
namespace nUserSession { class CPacket_S2C_QUEST_COMPLETE_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_ENABLE_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_MASTER_DATA_RELOAD_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_ORDER_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_ORDER_RES; }
namespace nUserSession { class CPacket_S2C_QUEST_PHASE_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_PROGRESS_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_PROGRESS_RES; }
namespace nUserSession { class CPacket_S2C_QUEST_PROGRESS_WORK_SAVE_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_TIMER_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_CANCEL_NTC; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_ENTRY_NTC; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_ENTRY_RES; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_READY_NTC; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_REGISTER_NTC; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_NTC; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_RES; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_REGISTER_RES; }
namespace nUserSession { class CPacket_S2C_QUICK_PARTY_UNREADY_NTC; }
namespace nUserSession { class CPacket_S2C_RAID_BOSS_NOTICE; }
namespace nUserSession { class CPacket_S2C_RAID_BOSS_POINT_NOTICE; }
namespace nUserSession { class CPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES; }
namespace nUserSession { class CPacket_S2C_RANKING_BOARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES; }
namespace nUserSession { class CPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES; }
namespace nUserSession { class CPacket_S2C_RANKING_DATA_RANK_RES; }
namespace nUserSession { class CPacket_S2C_REGISTER_FAVORITE_FRIEND_RES; }
namespace nUserSession { class CPacket_S2C_REGISTER_FAVORITE_WARP_RES; }
namespace nUserSession { class CPacket_S2C_REGISTER_PRESET_ABILITY_RES; }
namespace nUserSession { class CPacket_S2C_RELEASE_JOB_ORB_ELEMENT_RES; }
namespace nUserSession { class CPacket_S2C_RELEASE_ORB_ELEMENT_RES; }
namespace nUserSession { class CPacket_S2C_RELEASE_PAWN_ORB_ELEMENT_RES; }
namespace nUserSession { class CPacket_S2C_RELEASE_SET_QUEST_AREA_NOTICE; }
namespace nUserSession { class CPacket_S2C_RENTAL_PAWN_LOST_NOTICE; }
namespace nUserSession { class CPacket_S2C_RENTAL_PAWN_LOST_RES; }
namespace nUserSession { class CPacket_S2C_RENT_REGISTERED_PAWN_RES; }
namespace nUserSession { class CPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES; }
namespace nUserSession { class CPacket_S2C_RESET_JOBPOINT_RES; }
namespace nUserSession { class CPacket_S2C_RETURN_RENTED_PAWN_RES; }
namespace nUserSession { class CPacket_S2C_REWARD_BOX_LIST_NUM_NOTICE; }
namespace nUserSession { class CPacket_S2C_SELL_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_NOTICE; }
namespace nUserSession { class CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_RES; }
namespace nUserSession { class CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_NOTICE; }
namespace nUserSession { class CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_SEND_TELL_MSG_RES; }
namespace nUserSession { class CPacket_S2C_SERVER_UI_COMMAND_RES; }
namespace nUserSession { class CPacket_S2C_SET_ABILITY_RES; }
namespace nUserSession { class CPacket_S2C_SET_ARISEN_PROFILE_RES; }
namespace nUserSession { class CPacket_S2C_SET_CHARACTER_BIN_SAVEDATA_RES; }
namespace nUserSession { class CPacket_S2C_SET_COMMUNICATION_SHORTCUT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_SET_CONTEXT_BASE_NOTICE; }
namespace nUserSession { class CPacket_S2C_SET_FAVORITE_PAWN_RES; }
namespace nUserSession { class CPacket_S2C_SET_ITEM_SORTDATA_BIN_RES; }
namespace nUserSession { class CPacket_S2C_SET_MATCHING_PROFILE_RES; }
namespace nUserSession { class CPacket_S2C_SET_MESSAGE_SET_RES; }
namespace nUserSession { class CPacket_S2C_SET_OBJECTIVE_RES; }
namespace nUserSession { class CPacket_S2C_SET_OFF_ABILITY_RES; }
namespace nUserSession { class CPacket_S2C_SET_OFF_PAWN_ABILITY_RES; }
namespace nUserSession { class CPacket_S2C_SET_OFF_PAWN_SKILL_RES; }
namespace nUserSession { class CPacket_S2C_SET_OFF_SKILL_RES; }
namespace nUserSession { class CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_NOTICE; }
namespace nUserSession { class CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_RES; }
namespace nUserSession { class CPacket_S2C_SET_ONLINE_STATUS_RES; }
namespace nUserSession { class CPacket_S2C_SET_PAWN_ABILITY_RES; }
namespace nUserSession { class CPacket_S2C_SET_PAWN_PROFILE_COMMENT_RES; }
namespace nUserSession { class CPacket_S2C_SET_PAWN_PROFILE_RES; }
namespace nUserSession { class CPacket_S2C_SET_PAWN_SKILL_RES; }
namespace nUserSession { class CPacket_S2C_SET_PRESET_ABILITY_NAME_RES; }
namespace nUserSession { class CPacket_S2C_SET_PRIORITY_QUEST_RES; }
namespace nUserSession { class CPacket_S2C_SET_QUEST_UNRELEASED_AREA_NOTICE; }
namespace nUserSession { class CPacket_S2C_SET_RAID_BOSS_INFO_RES; }
namespace nUserSession { class CPacket_S2C_SET_SHORTCUT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_SET_SKILL_RES; }
namespace nUserSession { class CPacket_S2C_STAMP_BONUS_ADD_TOTAL_NUM_RES; }
namespace nUserSession { class CPacket_S2C_STAMP_BONUS_CHECK_RES; }
namespace nUserSession { class CPacket_S2C_STAMP_BONUS_GET_LIST_RES; }
namespace nUserSession { class CPacket_S2C_STAMP_BONUS_RECIEVE_RES; }
namespace nUserSession { class CPacket_S2C_START_CRAFT_RES; }
namespace nUserSession { class CPacket_S2C_START_DEATH_PENALTY_OTHER_NOTICE; }
namespace nUserSession { class CPacket_S2C_START_LANTERN_NOTICE; }
namespace nUserSession { class CPacket_S2C_START_LANTERN_OTHER_NOTICE; }
namespace nUserSession { class CPacket_S2C_SUPPORT_POINT_GET_RATE_RES; }
namespace nUserSession { class CPacket_S2C_SUPPORT_POINT_USE_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_DELETE_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_GET_LIST_FOOT_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_GET_LIST_HEAD_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_SEND_NTC; }
namespace nUserSession { class CPacket_S2C_TIME_GAIN_QUEST_PLAY_START_NOTICE; }
namespace nUserSession { class CPacket_S2C_TIME_UPDATE_NOTICE; }
namespace nUserSession { class CPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_TRANING_ROOM_SET_ENEMY_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_ARISEN_PROFILE_SHARE_RANGE_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_CHARACTER_EDIT_PARAM_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_CHARACTER_JOB_POINT_NOTICE; }
namespace nUserSession { class CPacket_S2C_UPDATE_EQUIP_COLOR_NOTICE; }
namespace nUserSession { class CPacket_S2C_UPDATE_EQUIP_GRADE_NOTICE; }
namespace nUserSession { class CPacket_S2C_UPDATE_EQUIP_HIDE_NOTICE; }
namespace nUserSession { class CPacket_S2C_UPDATE_EQUIP_PRESET_NAME_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_HIDE_PAWN_HEAD_ARMOR_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_HIDE_PAWN_LANTERN_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_MATCHING_PROFILE_NOTICE; }
namespace nUserSession { class CPacket_S2C_UPDATE_PAWN_SHARE_RANGE_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_PLAY_POINT_NOTICE; }
namespace nUserSession { class CPacket_S2C_UPDATE_RENTAL_PAWN_ADVENTURE_COUNT_NOTICE; }
namespace nUserSession { class CPacket_S2C_UPDATE_REVIVE_POINT_NOTICE; }
namespace nUserSession { class CPacket_S2C_USER_LIST_MAX_NUM_RES; }
namespace nUserSession { class CPacket_S2C_USE_BAG_ITEM_NOTICE; }
namespace nUserSession { class CPacket_S2C_USE_BAG_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_USE_JOB_ITEMS_RES; }
namespace nUserSession { class CPacket_S2C_WARP_RES; }
namespace nUserSession { class CPacket_S2C_WEATHER_FORECAST_GET_RES; }
namespace nUserSession { class CPacket_S2C_WEATHER_UPDATE_NOTICE; }

// Type aliases from DWARF
using CAreaSpotSet = CDataAreaSpotSet;
using CBattleResultInfo = CDataBattleResultInfo;
using CCharacterLevelParam = CDataCharacterLevelParam;
using CCharacterListElement = CDataCharacterListElement;
using CClanConciergeInfo = CDataClanConciergeInfo;
using CClanDungeonInfo = CDataClanDungeonInfo;
using CClanFunctionInfo = CDataClanFunctionInfo;
using CClanParam = CDataClanParam;
using CClanPartnerPawnInfo = CDataClanPartnerPawnInfo;
using CClanShopInfo = CDataClanShopInfo;
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CContentsPlayEnd = CDataContentsPlayEnd;
using CContextAcquirementData = CDataContextAcquirementData;
using CContextNormalSkillData = CDataContextNormalSkillData;
using CContextSetBase = CDataContextSetBase;
using CCraftProduct = CDataCraftProduct;
using CCraftProductInfo = CDataCraftProductInfo;
using CCycleContentsPlayEnd = CDataCycleContentsPlayEnd;
using CEncounterPawnInfo = CDataEncounterPawnInfo;
using CEndContentsGroup = CDataEndContentsGroup;
using CEntryItem = CDataEntryItem;
using CGameSetting = CDataGameSetting;
using CGameTime = CDataGameTime;
using CGameTimeBaseInfo = CDataGameTimeBaseInfo;
using CJobOrbTreeStatus = CDataJobOrbTreeStatus;
using CMailInfo = CDataMailInfo;
using CMailTextInfo = CDataMailTextInfo;
using CMatchingProfile = CDataMatchingProfile;
using COmData = CDataOmData;
using COrbGainExtendParam = CDataOrbGainExtendParam;
using CPartnerPawnData = CDataPartnerPawnData;
using CPartyQuestProgressInfo = CDataPartyQuestProgressInfo;
using CPawnExpeditionInformation = CDataPawnExpeditionInformation;
using CPawnInfo = CDataPawnInfo;
using CPawnTotalScore = CDataPawnTotalScore;
using CQuestDefine = CDataQuestDefine;
using CQuestPointDetail = CDataQuestPointDetail;
using CStageLayoutID = CDataStageLayoutID;
using CTimeGainQuestPlayStartData = CDataTimeGainQuestPlayStartData;
using CUpdateWalletPoint = CDataUpdateWalletPoint;
using CWorldInfo = CDataWorldInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using b8 = bool;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nUserSession {
    class CPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAchievementFurnitureReward>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAchievementFurnitureReward>& RewardList() const;
        MtTypedArray<CDataAchievementFurnitureReward>& RewardList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAchievementFurnitureReward> m_RewardList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAchievementProgress>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAchievementProgress>& AchievementProgressList() const;
        MtTypedArray<CDataAchievementProgress>& AchievementProgressList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAchievementProgress> m_AchievementProgressList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAchieveRewardCommon>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAchieveRewardCommon>& RewardList() const;
        MtTypedArray<CDataAchieveRewardCommon>& RewardList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAchieveRewardCommon> m_RewardList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAchievementRewardProgress>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAchievementRewardProgress>& BackgroundProgressList() const;
        MtTypedArray<CDataAchievementRewardProgress>& BackgroundProgressList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAchievementRewardProgress> m_BackgroundProgressList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ACHIEVEMENT_REWARD_RECEIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_ACHIEVEMENT_REWARD_RECEIVE_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAchieveRewardCommon>&, const MtTypedArray<CDataAchieveRewardCommon>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAchieveRewardCommon>& RecievedRewardList() const;
        MtTypedArray<CDataAchieveRewardCommon>& RecievedRewardList();
        const MtTypedArray<CDataAchieveRewardCommon>& RewardList() const;
        MtTypedArray<CDataAchieveRewardCommon>& RewardList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAchieveRewardCommon> m_RecievedRewardList;  // offset: 0x10
        MtTypedArray<CDataAchieveRewardCommon> m_RewardList;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ACTIVATE_JOB_ORDER_RES : public ::CPacketDataBase
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
        CPacket_S2C_ACTIVATE_JOB_ORDER_RES();
        s32 WritePacket(CPacket*, s32, u8, u8, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 JobID() const;
        u8 RewardType() const;
        u32 RewardNo() const;
        u8 RewardLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJobID;  // offset: 0x10
        u8 m_ucRewardType;  // offset: 0x11
        u32 m_unRewardNo;  // offset: 0x14
        u8 m_ucRewardLv;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x19
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_AREA_WARP_RES : public ::CPacketDataBase
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
        CPacket_S2C_AREA_WARP_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 WarpPointID() const;
        u32 Rim() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unWarpPointID;  // offset: 0x10
        u32 m_unRim;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BAZAAR_CANCEL_RES : public ::CPacketDataBase
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
        CPacket_S2C_BAZAAR_CANCEL_RES();
        s32 WritePacket(CPacket*, s32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 BazaarId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullBazaarId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BAZAAR_EXHIBIT_RES : public ::CPacketDataBase
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
        CPacket_S2C_BAZAAR_EXHIBIT_RES();
        s32 WritePacket(CPacket*, s32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 BazaarId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullBazaarId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_RES : public ::CPacketDataBase
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
        CPacket_S2C_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Num() const;
        u32 Add() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unNum;  // offset: 0x10
        u32 m_unAdd;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES : public ::CPacketDataBase
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
        CPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES();
        s32 WritePacket(CPacket*, s32, u32, u32, u32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 ItemId() const;
        u32 Low() const;
        u32 High() const;
        u16 Num() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unItemId;  // offset: 0x10
        u32 m_unLow;  // offset: 0x14
        u32 m_unHigh;  // offset: 0x18
        u16 m_usNum;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x1e
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BAZAAR_PROCEEDS_NTC : public ::CPacketDataBase
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
        CPacket_S2C_BAZAAR_PROCEEDS_NTC();
        s32 WritePacket(CPacket*, u64, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u64 BazaarId() const;
        u32 ItemId() const;
        u32 Proceeds() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u64 m_ullBazaarId;  // offset: 0x10
        u32 m_unItemId;  // offset: 0x18
        u32 m_unProceeds;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BAZAAR_PROCEEDS_RES : public ::CPacketDataBase
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
        CPacket_S2C_BAZAAR_PROCEEDS_RES();
        s32 WritePacket(CPacket*, s32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 BazaarId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullBazaarId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BAZAAR_RECEIVE_PROCEEDS_RES : public ::CPacketDataBase
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
        CPacket_S2C_BAZAAR_RECEIVE_PROCEEDS_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Proceeds() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unProceeds;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BAZAAR_RE_EXHIBIT_RES : public ::CPacketDataBase
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
        CPacket_S2C_BAZAAR_RE_EXHIBIT_RES();
        s32 WritePacket(CPacket*, s32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 BazaarId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullBazaarId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BOX_GACHA_BUY_RES : public ::CPacketDataBase
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
        CPacket_S2C_BOX_GACHA_BUY_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataBoxGachaItemInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Id() const;
        const MtTypedArray<CDataBoxGachaItemInfo>& BoxGachaItemList() const;
        MtTypedArray<CDataBoxGachaItemInfo>& BoxGachaItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unId;  // offset: 0x10
        MtTypedArray<CDataBoxGachaItemInfo> m_BoxGachaItemList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BOX_GACHA_DRAW_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_BOX_GACHA_DRAW_INFO_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataBoxGachaItemInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Id() const;
        const MtTypedArray<CDataBoxGachaItemInfo>& BoxGachaItemList() const;
        MtTypedArray<CDataBoxGachaItemInfo>& BoxGachaItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unId;  // offset: 0x10
        MtTypedArray<CDataBoxGachaItemInfo> m_BoxGachaItemList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BOX_GACHA_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_BOX_GACHA_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataBoxGachaInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataBoxGachaInfo>& BoxGachaList() const;
        MtTypedArray<CDataBoxGachaInfo>& BoxGachaList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataBoxGachaInfo> m_BoxGachaList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BOX_GACHA_RESET_RES : public ::CPacketDataBase
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
        CPacket_S2C_BOX_GACHA_RESET_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Id() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BUY_AREA_QUEST_HINT_RES : public ::CPacketDataBase
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
        CPacket_S2C_BUY_AREA_QUEST_HINT_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 UpdateGold() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unUpdateGold;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_BUY_SHOP_GOODS_RES : public ::CPacketDataBase
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
        CPacket_S2C_BUY_SHOP_GOODS_RES();
        s32 WritePacket(CPacket*, s32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 PointType() const;
        u32 Point() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucPointType;  // offset: 0x10
        u32 m_unPoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CANCEL_CRAFT_RES : public ::CPacketDataBase
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
        CPacket_S2C_CANCEL_CRAFT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CANCEL_PRIORITY_QUEST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CANCEL_PRIORITY_QUEST_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 QuestScheduleId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHANGE_CAP_TO_GP_RES : public ::CPacketDataBase
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
        CPacket_S2C_CHANGE_CAP_TO_GP_RES();
        s32 WritePacket(CPacket*, u32, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 ChangeListID() const;
        u32 GP() const;
        u32 CAP() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unChangeListID;  // offset: 0x10
        u32 m_unGP;  // offset: 0x14
        u32 m_unCAP;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_ADD_WALLET_POINT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_ADD_WALLET_POINT_NOTICE();
        s32 WritePacket(CPacket*, const CUpdateWalletPoint&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CUpdateWalletPoint& UpdateWallet() const;
        CUpdateWalletPoint& UpdateWallet();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CUpdateWalletPoint m_UpdateWallet;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_GOLDEN_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_GOLDEN_REVIVE_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 GP() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unGP;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_JOB_EXP_UP_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_JOB_EXP_UP_NOTICE();
        s32 WritePacket(CPacket*, u8, u32, u32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 Job() const;
        u32 AddExp() const;
        u32 ExtraBonusExp() const;
        u32 TotalExp() const;
        u8 Type() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucJob;  // offset: 0xa
        u32 m_unAddExp;  // offset: 0xc
        u32 m_unExtraBonusExp;  // offset: 0x10
        u32 m_unTotalExp;  // offset: 0x14
        u8 m_ucType;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x19
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_JOB_LEVEL_UP_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_JOB_LEVEL_UP_NOTICE();
        s32 WritePacket(CPacket*, u8, u32, u32, u32, const CCharacterLevelParam&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 Job() const;
        u32 Level() const;
        u32 AddJobPoint() const;
        u32 TotalJobPoint() const;
        const CCharacterLevelParam& CharacterLevelParam() const;
        CCharacterLevelParam& CharacterLevelParam();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucJob;  // offset: 0xa
        u32 m_unLevel;  // offset: 0xc
        u32 m_unAddJobPoint;  // offset: 0x10
        u32 m_unTotalJobPoint;  // offset: 0x14
        CCharacterLevelParam m_CharacterLevelParam;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_JOB_LEVEL_UP_OTHER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_JOB_LEVEL_UP_OTHER_NOTICE();
        s32 WritePacket(CPacket*, u32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        u8 Job() const;
        u32 Level() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        u8 m_ucJob;  // offset: 0x10
        u32 m_unLevel;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_PENALTY_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_PENALTY_REVIVE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_POINT_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_POINT_REVIVE_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 RevivePoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucRevivePoint;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_REVIVE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_REVIVE_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_SEARCH_RES : public ::CPacketDataBase
    {
        friend class ::cMenuCharacterList;
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
        CPacket_S2C_CHARACTER_SEARCH_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataCharacterListElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataCharacterListElement>& CharacterList() const;
        MtTypedArray<CDataCharacterListElement>& CharacterList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataCharacterListElement> m_CharacterList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARACTER_SUB_WALLET_POINT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CHARACTER_SUB_WALLET_POINT_NOTICE();
        s32 WritePacket(CPacket*, const CUpdateWalletPoint&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CUpdateWalletPoint& UpdateWallet() const;
        CUpdateWalletPoint& UpdateWallet();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CUpdateWalletPoint m_UpdateWallet;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHARGE_REVIVE_POINT_RES : public ::CPacketDataBase
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
        CPacket_S2C_CHARGE_REVIVE_POINT_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 RevivePoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucRevivePoint;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CHECK_QUEST_DISTRIBUTION_RES : public ::CPacketDataBase
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
        CPacket_S2C_CHECK_QUEST_DISTRIBUTION_RES();
        s32 WritePacket(CPacket*, u32, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        b8 IsDistribution() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        b8 m_bIsDistribution;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_BASE_GET_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_BASE_GET_INFO_RES();
        s32 WritePacket(CPacket*, s32, const CClanFunctionInfo&, const CClanDungeonInfo&, const CPawnExpeditionInformation&, const CClanPartnerPawnInfo&, const CClanConciergeInfo&, const MtTypedArray<CDataClanShopLineupName>&, const MtTypedArray<CDataClanValueInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CClanFunctionInfo& FunctionInfo() const;
        CClanFunctionInfo& FunctionInfo();
        const CClanDungeonInfo& DungeonInfo() const;
        CClanDungeonInfo& DungeonInfo();
        const CPawnExpeditionInformation& PawnExpeditionInfo() const;
        CPawnExpeditionInformation& PawnExpeditionInfo();
        const CClanPartnerPawnInfo& PartnerPawnInfo() const;
        CClanPartnerPawnInfo& PartnerPawnInfo();
        const CClanConciergeInfo& ConciergeInfo() const;
        CClanConciergeInfo& ConciergeInfo();
        const MtTypedArray<CDataClanShopLineupName>& ShopLineupNameList() const;
        MtTypedArray<CDataClanShopLineupName>& ShopLineupNameList();
        const MtTypedArray<CDataClanValueInfo>& ClanValueInfoList() const;
        MtTypedArray<CDataClanValueInfo>& ClanValueInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CClanFunctionInfo m_FunctionInfo;  // offset: 0x10
        CClanDungeonInfo m_DungeonInfo;  // offset: 0x38
        CPawnExpeditionInformation m_PawnExpeditionInfo;  // offset: 0x60
        CClanPartnerPawnInfo m_PartnerPawnInfo;  // offset: 0x70
        CClanConciergeInfo m_ConciergeInfo;  // offset: 0xb8
        MtTypedArray<CDataClanShopLineupName> m_ShopLineupNameList;  // offset: 0xe8
        MtTypedArray<CDataClanValueInfo> m_ClanValueInfoList;  // offset: 0x108
        bool m_bIsReceived;  // offset: 0x128
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_BASE_RELEASE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_BASE_RELEASE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_BASE_RELEASE_STATE_UPDATE_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_BASE_RELEASE_STATE_UPDATE_NTC();
        s32 WritePacket(CPacket*, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 State() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucState;  // offset: 0xa
        bool m_bIsReceived;  // offset: 0xb
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_CANCEL_JOIN_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_CANCEL_JOIN_NTC();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 RequestId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nRequestId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_CANCEL_JOIN_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_CANCEL_JOIN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanShopConciergeItem>&, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanShopConciergeItem>& ConciergeItemList() const;
        MtTypedArray<CDataClanShopConciergeItem>& ConciergeItemList();
        u32 ClanPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanShopConciergeItem> m_ConciergeItemList;  // offset: 0x10
        u32 m_unClanPoint;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x34
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_CONCIERGE_UPDATE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_CONCIERGE_UPDATE_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 NpcId() const;
        u32 ClanPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unNpcId;  // offset: 0x10
        u32 m_unClanPoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_EXPEL_MEMBER_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_EXPEL_MEMBER_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_GET_HISTORY_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_GET_HISTORY_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanHistoryElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanHistoryElement>& ClanHistoryList() const;
        MtTypedArray<CDataClanHistoryElement>& ClanHistoryList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanHistoryElement> m_ClanHistoryList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_GET_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_GET_INFO_RES();
        s32 WritePacket(CPacket*, s32, const CClanParam&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CClanParam& CreateParam() const;
        CClanParam& CreateParam();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CClanParam m_CreateParam;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x118
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanJoinRequest>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanJoinRequest>& JoinReqList() const;
        MtTypedArray<CDataClanJoinRequest>& JoinReqList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanJoinRequest> m_JoinReqList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_GET_MEMBER_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_GET_MEMBER_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanMemberInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanMemberInfo>& MemberList() const;
        MtTypedArray<CDataClanMemberInfo>& MemberList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanMemberInfo> m_MemberList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_GET_MEMBER_NUM_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_GET_MEMBER_NUM_RES();
        s32 WritePacket(CPacket*, s32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u16 MemberNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u16 m_usMemberNum;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x12
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanJoinRequest>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanJoinRequest>& JoinReqList() const;
        MtTypedArray<CDataClanJoinRequest>& JoinReqList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanJoinRequest> m_JoinReqList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_INVITE_ACCEPT_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_INVITE_ACCEPT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_INVITE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_INVITE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_JOIN_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_JOIN_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_LEAVE_MEMBER_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_LEAVE_MEMBER_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_LEVEL_UP_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_LEVEL_UP_NTC();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 ClanLV() const;
        u32 NextClanPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unClanLV;  // offset: 0xc
        u32 m_unNextClanPoint;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_NEGOTIATE_MASTER_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_NEGOTIATE_MASTER_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 MemberID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unMemberID;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_POINT_ADD_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_POINT_ADD_NTC();
        s32 WritePacket(CPacket*, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 ClanPoint() const;
        u32 TotalClanPoint() const;
        u32 MoneyClanPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unClanPoint;  // offset: 0xc
        u32 m_unTotalClanPoint;  // offset: 0x10
        u32 m_unMoneyClanPoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_QUEST_CLEAR_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_QUEST_CLEAR_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_REGISTER_JOIN_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_REGISTER_JOIN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 InviteId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unInviteId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 InviteID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unInviteID;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_DISAPPROVE_INVITE_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_DISAPPROVE_INVITE_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 InviteId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unInviteId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanScoutEntryInviteInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanScoutEntryInviteInfo>& InviteInfo() const;
        MtTypedArray<CDataClanScoutEntryInviteInfo>& InviteInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanScoutEntryInviteInfo> m_InviteInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanScoutEntryInviteInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanScoutEntryInviteInfo>& InviteInfo() const;
        MtTypedArray<CDataClanScoutEntryInviteInfo>& InviteInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanScoutEntryInviteInfo> m_InviteInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_INVITE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_INVITE_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 ScoutEntryID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unScoutEntryID;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_REGISTER_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_REGISTER_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanScoutEntrySearchResult>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanScoutEntrySearchResult>& SearchResult() const;
        MtTypedArray<CDataClanScoutEntrySearchResult>& SearchResult();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanScoutEntrySearchResult> m_SearchResult;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SEARCH_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SEARCH_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanSearchResult>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanSearchResult>& ClanList() const;
        MtTypedArray<CDataClanSearchResult>& ClanList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanSearchResult> m_ClanList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SETTING_UPDATE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SETTING_UPDATE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SET_MEMBER_RANK_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SET_MEMBER_RANK_NTC();
        s32 WritePacket(CPacket*, u32, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 ClanID() const;
        u32 CharacterID() const;
        u32 Rank() const;
        u32 Permission() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unClanID;  // offset: 0xc
        u32 m_unCharacterID;  // offset: 0x10
        u32 m_unRank;  // offset: 0x14
        u32 m_unPermission;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SET_MEMBER_RANK_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SET_MEMBER_RANK_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 MemberID() const;
        u32 Rank() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unMemberID;  // offset: 0x10
        u32 m_unRank;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SHOP_GET_BUFF_ITEM_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SHOP_GET_BUFF_ITEM_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanShopBuffItem>&, u32, const CClanShopInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanShopBuffItem>& BuffItemList() const;
        MtTypedArray<CDataClanShopBuffItem>& BuffItemList();
        u32 ClanPoint() const;
        const CClanShopInfo& ShopInfo() const;
        CClanShopInfo& ShopInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanShopBuffItem> m_BuffItemList;  // offset: 0x10
        u32 m_unClanPoint;  // offset: 0x30
        CClanShopInfo m_ShopInfo;  // offset: 0x38
        bool m_bIsReceived;  // offset: 0x88
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataClanShopFunctionItem>&, u32, const CClanShopInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataClanShopFunctionItem>& FunctionItemList() const;
        MtTypedArray<CDataClanShopFunctionItem>& FunctionItemList();
        u32 ClanPoint() const;
        const CClanShopInfo& ShopInfo() const;
        CClanShopInfo& ShopInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataClanShopFunctionItem> m_FunctionItemList;  // offset: 0x10
        u32 m_unClanPoint;  // offset: 0x30
        CClanShopInfo m_ShopInfo;  // offset: 0x38
        bool m_bIsReceived;  // offset: 0x88
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_UPDATE_NTC : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_UPDATE_NTC();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLAN_UPDATE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLAN_UPDATE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CLIENT_CHALLENGE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CLIENT_CHALLENGE_RES();
        s32 WritePacket(CPacket*, s32, u8, u8, const u8(&)[62]);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 PasswordSrcSize() const;
        u8 PasswordEncSize() const;
        auto PasswordEnc() -> u8(&)[62];
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucPasswordSrcSize;  // offset: 0x10
        u8 m_ucPasswordEncSize;  // offset: 0x11
        u8 m_ucPasswordEnc[62];  // offset: 0x12
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_COG_LOGIN_SKIP_DISABLE_RES : public ::CPacketDataBase
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
        CPacket_S2C_COG_LOGIN_SKIP_DISABLE_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 Flag() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucFlag;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_COG_LOGIN_SKIP_FLAG_RES : public ::CPacketDataBase
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
        CPacket_S2C_COG_LOGIN_SKIP_FLAG_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 Flag() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucFlag;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_COMMUNITY_CHARACTER_STATUS_GET_RES : public ::CPacketDataBase
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
        CPacket_S2C_COMMUNITY_CHARACTER_STATUS_GET_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CONSUME_STORAGE_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_CONSUME_STORAGE_ITEM_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CRAFT_EXP_UP_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CRAFT_EXP_UP_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnID() const;
        u32 AddExp() const;
        u32 ExtraBonusExp() const;
        u32 TotalExp() const;
        u32 CraftRankLimit() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnID;  // offset: 0xc
        u32 m_unAddExp;  // offset: 0x10
        u32 m_unExtraBonusExp;  // offset: 0x14
        u32 m_unTotalExp;  // offset: 0x18
        u32 m_unCraftRankLimit;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CRAFT_RANK_UP_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CRAFT_RANK_UP_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnID() const;
        u32 CraftRank() const;
        u32 AddCraftPoint() const;
        u32 TotalCraftPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnID;  // offset: 0xc
        u32 m_unCraftRank;  // offset: 0x10
        u32 m_unAddCraftPoint;  // offset: 0x14
        u32 m_unTotalCraftPoint;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CRAFT_SKILL_ANALYZE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CRAFT_SKILL_ANALYZE_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataCraftSkillAnalyzeResult>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataCraftSkillAnalyzeResult>& AnalyzeResultList() const;
        MtTypedArray<CDataCraftSkillAnalyzeResult>& AnalyzeResultList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataCraftSkillAnalyzeResult> m_AnalyzeResultList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CRAFT_SKILL_UP_RES : public ::CPacketDataBase
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
        CPacket_S2C_CRAFT_SKILL_UP_RES();
        s32 WritePacket(CPacket*, s32, u32, u32, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u32 SkillType() const;
        u32 SkillLevel() const;
        u32 UseCraftPoint() const;
        u32 RemainCraftPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u32 m_unSkillType;  // offset: 0x14
        u32 m_unSkillLevel;  // offset: 0x18
        u32 m_unUseCraftPoint;  // offset: 0x1c
        u32 m_unRemainCraftPoint;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x24
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CRAFT_TIME_SAVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_CRAFT_TIME_SAVE_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u32 RemainTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u32 m_unRemainTime;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CREATE_MYPAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_CREATE_MYPAWN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CYCLE_CONTENTS_ENABLE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CYCLE_CONTENTS_ENABLE_NOTICE();
        s32 WritePacket(CPacket*, u32, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CycleContentsScheduleId() const;
        b8 IsEnable() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCycleContentsScheduleId;  // offset: 0xc
        b8 m_bIsEnable;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CYCLE_CONTENTS_END_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CYCLE_CONTENTS_END_NOTICE();
        s32 WritePacket(CPacket*, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CycleContentsScheduleId() const;
        u8 Category() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCycleContentsScheduleId;  // offset: 0xc
        u8 m_ucCategory;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CYCLE_CONTENTS_PLAY_END_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_CYCLE_CONTENTS_PLAY_END_NOTICE();
        s32 WritePacket(CPacket*, const CCycleContentsPlayEnd&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CCycleContentsPlayEnd& CycleContentsPlayEnd() const;
        CCycleContentsPlayEnd& CycleContentsPlayEnd();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CCycleContentsPlayEnd m_CycleContentsPlayEnd;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x128
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CYCLE_CONTENTS_PLAY_END_RES : public ::CPacketDataBase
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
        CPacket_S2C_CYCLE_CONTENTS_PLAY_END_RES();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_CYCLE_CONTENTS_PLAY_START_RES : public ::CPacketDataBase
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
        CPacket_S2C_CYCLE_CONTENTS_PLAY_START_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DEBUG_COMMAND_RES : public ::CPacketDataBase
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
        CPacket_S2C_DEBUG_COMMAND_RES();
        s32 WritePacket(CPacket*, s32, const char*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const char* Command() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtString m_wstrCommand;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DEBUG_CYCLE_CONTENTS_POINT_UPLOAD_RES : public ::CPacketDataBase
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
        CPacket_S2C_DEBUG_CYCLE_CONTENTS_POINT_UPLOAD_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DEBUG_ENEMY_SET_PRESET_FIX_RES : public ::CPacketDataBase
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
        CPacket_S2C_DEBUG_ENEMY_SET_PRESET_FIX_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DEBUG_GET_QUEST_FLAG_RES : public ::CPacketDataBase
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
        CPacket_S2C_DEBUG_GET_QUEST_FLAG_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataQuestFlag>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataQuestFlag>& QuestFlagList() const;
        MtTypedArray<CDataQuestFlag>& QuestFlagList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataQuestFlag> m_QuestFlagList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES : public ::CPacketDataBase
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
        CPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataQuestLayoutFlag>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataQuestLayoutFlag>& QuestLayoutFlagList() const;
        MtTypedArray<CDataQuestLayoutFlag>& QuestLayoutFlagList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataQuestLayoutFlag> m_QuestLayoutFlagList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DEBUG_MAIN_QUEST_JUMP_RES : public ::CPacketDataBase
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
        CPacket_S2C_DEBUG_MAIN_QUEST_JUMP_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DEBUG_QUEST_RESET_ALL_RES : public ::CPacketDataBase
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
        CPacket_S2C_DEBUG_QUEST_RESET_ALL_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 QuestType() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucQuestType;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DEBUG_QUEST_RESET_RES : public ::CPacketDataBase
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
        CPacket_S2C_DEBUG_QUEST_RESET_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        u32 ProcessNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        u32 m_unProcessNo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DECIDE_DELIVERY_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_DECIDE_DELIVERY_ITEM_RES();
        s32 WritePacket(CPacket*, s32, u32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        u16 m_usProcessNo;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x16
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DELETE_FAVORITE_PAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_DELETE_FAVORITE_PAWN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DELETE_MYPAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_DELETE_MYPAWN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_DELIVER_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_DELIVER_ITEM_RES();
        s32 WritePacket(CPacket*, s32, u32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        u16 m_usProcessNo;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x16
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_EJECTION_NTC : public ::CPacketDataBase
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
        CPacket_S2C_EJECTION_NTC();
        s32 WritePacket(CPacket*, const char*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const char* Message() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtString m_wstrMessage;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENCOUNTER_PAWN_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_ENCOUNTER_PAWN_NOTICE();
        s32 WritePacket(CPacket*, const CStageLayoutID&, const CEncounterPawnInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CStageLayoutID& LayoutId() const;
        CStageLayoutID& LayoutId();
        const CEncounterPawnInfo& info() const;
        CEncounterPawnInfo& info();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CStageLayoutID m_LayoutId;  // offset: 0x10
        CEncounterPawnInfo m_info;  // offset: 0x28
        bool m_bIsReceived;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES : public ::CPacketDataBase
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
        CPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataExpiredQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataExpiredQuestList>& ExpiredQuestList() const;
        MtTypedArray<CDataExpiredQuestList>& ExpiredQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataExpiredQuestList> m_ExpiredQuestList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENEMY_KILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_ENEMY_KILL_RES();
        s32 WritePacket(CPacket*, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 EnemyID() const;
        u32 KillNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unEnemyID;  // offset: 0x10
        u32 m_unKillNum;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENEMY_STAGE_BOSS_ANNIHILATE_NTC : public ::CPacketDataBase
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
        CPacket_S2C_ENEMY_STAGE_BOSS_ANNIHILATE_NTC();
        s32 WritePacket(CPacket*, const CStageLayoutID&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CStageLayoutID& LayoutId() const;
        CStageLayoutID& LayoutId();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CStageLayoutID m_LayoutId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES();
        s32 WritePacket(CPacket*, s32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u16 TimeOut() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u16 m_usTimeOut;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x12
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_FORCE_START_RES : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_FORCE_START_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_INFO_LOCK_RES : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_INFO_LOCK_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_INFO_RES();
        s32 WritePacket(CPacket*, s32, u64, const CEntryItem&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 BoardID() const;
        const CEntryItem& EntryItemData() const;
        CEntryItem& EntryItemData();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullBoardID;  // offset: 0x10
        CEntryItem m_EntryItemData;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x98
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_INVITE_RES : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_INVITE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 LeaveType() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unLeaveType;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cMenuEntryBoardItemList;
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
        CPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES();
        s32 WritePacket(CPacket*, s32, u64, const MtTypedArray<CDataEntryItem>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 ID() const;
        const MtTypedArray<CDataEntryItem>& EntryItemList() const;
        MtTypedArray<CDataEntryItem>& EntryItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullID;  // offset: 0x10
        MtTypedArray<CDataEntryItem> m_EntryItemList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_PARTY_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_PARTY_NOTICE();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE();
        s32 WritePacket(CPacket*, u32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 MaxMember() const;
        u16 TimeOut() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unMaxMember;  // offset: 0xc
        u16 m_usTimeOut;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x12
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_READY_RES : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_READY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 NowMember() const;
        u32 MaxMember() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unNowMember;  // offset: 0xc
        u32 m_unMaxMember;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE();
        s32 WritePacket(CPacket*, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u16 TimeOut() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u16 m_usTimeOut;  // offset: 0xa
        bool m_bIsReceived;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataDispelResultInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataDispelResultInfo>& DispelItemResultList() const;
        MtTypedArray<CDataDispelResultInfo>& DispelItemResultList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataDispelResultInfo> m_DispelItemResultList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_EXCHANGE_OM_INSTANT_KEY_VALUE_RES : public ::CPacketDataBase
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
        CPacket_S2C_EXCHANGE_OM_INSTANT_KEY_VALUE_RES();
        s32 WritePacket(CPacket*, s32, u32, const COmData&, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 StageId() const;
        const COmData& Value() const;
        COmData& Value();
        u32 ValueOld() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unStageId;  // offset: 0x10
        COmData m_Value;  // offset: 0x18
        u32 m_ulValueOld;  // offset: 0x28
        bool m_bIsReceived;  // offset: 0x2c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_EXTEND_EQUIP_SLOT_NTC : public ::CPacketDataBase
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
        CPacket_S2C_EXTEND_EQUIP_SLOT_NTC();
        s32 WritePacket(CPacket*, u8, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 Slot() const;
        u8 AddNum() const;
        u8 TotalNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucSlot;  // offset: 0xa
        u8 m_ucAddNum;  // offset: 0xb
        u8 m_ucTotalNum;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0xd
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_EXTEND_MAIN_PAWN_SLOT_NTC : public ::CPacketDataBase
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
        CPacket_S2C_EXTEND_MAIN_PAWN_SLOT_NTC();
        s32 WritePacket(CPacket*, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 AddNum() const;
        u8 TotalNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucAddNum;  // offset: 0xa
        u8 m_ucTotalNum;  // offset: 0xb
        bool m_bIsReceived;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_EXTEND_SUPPORT_PAWN_SLOT_NTC : public ::CPacketDataBase
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
        CPacket_S2C_EXTEND_SUPPORT_PAWN_SLOT_NTC();
        s32 WritePacket(CPacket*, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 AddNum() const;
        u8 TotalNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucAddNum;  // offset: 0xa
        u8 m_ucTotalNum;  // offset: 0xb
        bool m_bIsReceived;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_FAVORITE_WARP_RES : public ::CPacketDataBase
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
        CPacket_S2C_FAVORITE_WARP_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 WarpPointID() const;
        u32 rim() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unWarpPointID;  // offset: 0x10
        u32 m_unrim;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_FINISH_CRAFT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_FINISH_CRAFT_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_FINISH_DEATH_PENALTY_OTHER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_FINISH_DEATH_PENALTY_OTHER_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_FINISH_LANTERN_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_FINISH_LANTERN_NOTICE();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_FINISH_LANTERN_OTHER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_FINISH_LANTERN_OTHER_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_FORT_DEFENSE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_FORT_DEFENSE_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataFortDefenseNoticeData>&, const MtTypedArray<CDataQuestContentsSituationInfoDetail>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataFortDefenseNoticeData>& FortDefenseNoticeDataList() const;
        MtTypedArray<CDataFortDefenseNoticeData>& FortDefenseNoticeDataList();
        const MtTypedArray<CDataQuestContentsSituationInfoDetail>& QuestContentsSituationInfoDetailList() const;
        MtTypedArray<CDataQuestContentsSituationInfoDetail>& QuestContentsSituationInfoDetailList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataFortDefenseNoticeData> m_FortDefenseNoticeDataList;  // offset: 0x10
        MtTypedArray<CDataQuestContentsSituationInfoDetail> m_QuestContentsSituationInfoDetailList;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataQuestContentsSituationInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CycleContentsScheduleId() const;
        const MtTypedArray<CDataQuestContentsSituationInfo>& QuestContentsSituationInfoList() const;
        MtTypedArray<CDataQuestContentsSituationInfo>& QuestContentsSituationInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCycleContentsScheduleId;  // offset: 0xc
        MtTypedArray<CDataQuestContentsSituationInfo> m_QuestContentsSituationInfoList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_FURNITURE_LAYOUT_RES : public ::CPacketDataBase
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
        CPacket_S2C_FURNITURE_LAYOUT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GACHA_BUY_RES : public ::CPacketDataBase
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
        CPacket_S2C_GACHA_BUY_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataGachaItemInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Id() const;
        const MtTypedArray<CDataGachaItemInfo>& GachaItemList() const;
        MtTypedArray<CDataGachaItemInfo>& GachaItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unId;  // offset: 0x10
        MtTypedArray<CDataGachaItemInfo> m_GachaItemList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GACHA_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GACHA_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataGachaInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataGachaInfo>& GachaList() const;
        MtTypedArray<CDataGachaInfo>& GachaList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataGachaInfo> m_GachaList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GAIN_PAWN_PARAM_NTC : public ::CPacketDataBase
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
        CPacket_S2C_GAIN_PAWN_PARAM_NTC();
        s32 WritePacket(CPacket*, u32, u32, u32, u32, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnId() const;
        u32 HpMaxGain() const;
        u32 StaminaMaxGain() const;
        u32 AttackGain() const;
        u32 DefenseGain() const;
        u32 MagicAttackGain() const;
        u32 MagicDefenseGain() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnId;  // offset: 0xc
        u32 m_unHpMaxGain;  // offset: 0x10
        u32 m_unStaminaMaxGain;  // offset: 0x14
        u32 m_unAttackGain;  // offset: 0x18
        u32 m_unDefenseGain;  // offset: 0x1c
        u32 m_unMagicAttackGain;  // offset: 0x20
        u32 m_unMagicDefenseGain;  // offset: 0x24
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GAME_TIME_BASEINFO_NTC : public ::CPacketDataBase
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
        CPacket_S2C_GAME_TIME_BASEINFO_NTC();
        s32 WritePacket(CPacket*, const CGameTimeBaseInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CGameTimeBaseInfo& GameTimeBaseInfo() const;
        CGameTimeBaseInfo& GameTimeBaseInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CGameTimeBaseInfo m_GameTimeBaseInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x48
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_ABILITY_COST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_ABILITY_COST_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 CostMax() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unCostMax;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAbilityParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAbilityParam>& AbilityParamList() const;
        MtTypedArray<CDataAbilityParam>& AbilityParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAbilityParam> m_AbilityParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataNormalSkillParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataNormalSkillParam>& NormalSkillParamList() const;
        MtTypedArray<CDataNormalSkillParam>& NormalSkillParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataNormalSkillParam> m_NormalSkillParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataSkillParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataSkillParam>& SkillParamList() const;
        MtTypedArray<CDataSkillParam>& SkillParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataSkillParam> m_SkillParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataJobOrbDevoteElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataJobOrbDevoteElement>& ElementList() const;
        MtTypedArray<CDataJobOrbDevoteElement>& ElementList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataJobOrbDevoteElement> m_ElementList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_AREA_BONUS_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_AREA_BONUS_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAreaBonus>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAreaBonus>& AreaBonusList() const;
        MtTypedArray<CDataAreaBonus>& AreaBonusList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAreaBonus> m_AreaBonusList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_AREA_INFO_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_AREA_INFO_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAreaInfoList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAreaInfoList>& AreaInfoList() const;
        MtTypedArray<CDataAreaInfoList>& AreaInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAreaInfoList> m_AreaInfoList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_AREA_POINT_DEBUG_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_AREA_POINT_DEBUG_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAreaQuestHint>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAreaQuestHint>& AreaQuestHintList() const;
        MtTypedArray<CDataAreaQuestHint>& AreaQuestHintList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAreaQuestHint> m_AreaQuestHintList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_AREA_SUPPLY_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_AREA_SUPPLY_INFO_RES();
        s32 WritePacket(CPacket*, s32, u8, const MtTypedArray<CDataRewardItemInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 SupplyGrade() const;
        const MtTypedArray<CDataRewardItemInfo>& RewardItemInfoList() const;
        MtTypedArray<CDataRewardItemInfo>& RewardItemInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucSupplyGrade;  // offset: 0x10
        MtTypedArray<CDataRewardItemInfo> m_RewardItemInfoList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_AREA_SUPPLY_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_AREA_SUPPLY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_AREA_WARP_POINT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_AREA_WARP_POINT_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataAreaWarpPoint>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataAreaWarpPoint>& AreaWarpPointList() const;
        MtTypedArray<CDataAreaWarpPoint>& AreaWarpPointList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataAreaWarpPoint> m_AreaWarpPointList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataCommonU32>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataCommonU32>& BackgroundIdList() const;
        MtTypedArray<CDataCommonU32>& BackgroundIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataCommonU32> m_BackgroundIdList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CAPLINK_ACHIEVE_REWARD_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_CAPLINK_ACHIEVE_REWARD_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CAP_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_CAP_RES();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 CAP() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unCAP;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataCAPtoGPChangeElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataCAPtoGPChangeElement>& List() const;
        MtTypedArray<CDataCAPtoGPChangeElement>& List();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataCAPtoGPChangeElement> m_List;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CHARACTER_BINARY_STATUS_NTC : public ::CPacketDataBase
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
        CPacket_S2C_GET_CHARACTER_BINARY_STATUS_NTC();
        s32 WritePacket(CPacket*, u32, u32, const u8(&)[512]);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        u32 BinarySize() const;
        auto BinaryData() -> u8(&)[512];
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        u32 m_unBinarySize;  // offset: 0x10
        u8 m_ucBinaryData[512];  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x214
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CHEAT_INFO_REQ : public ::CPacketDataBase
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
        CPacket_S2C_GET_CHEAT_INFO_REQ();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CRAFT_LOCKED_ELEMENT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_CRAFT_LOCKED_ELEMENT_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataItemEquipElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataItemEquipElement>& LockedElementList() const;
        MtTypedArray<CDataItemEquipElement>& LockedElementList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataItemEquipElement> m_LockedElementList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES : public ::CPacketDataBase
    {
        friend class ::sCraftManager;
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
        CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES();
        s32 WritePacket(CPacket*, s32, const CCraftProductInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CCraftProductInfo& CraftProductInfo() const;
        CCraftProductInfo& CraftProductInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CCraftProductInfo m_CraftProductInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CRAFT_PRODUCT_RES : public ::CPacketDataBase
    {
        friend class ::sCraftManager;
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
        CPacket_S2C_GET_CRAFT_PRODUCT_RES();
        s32 WritePacket(CPacket*, s32, const CCraftProduct&, const MtTypedArray<CDataItemUpdateResult>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CCraftProduct& CraftProduct() const;
        CCraftProduct& CraftProduct();
        const MtTypedArray<CDataItemUpdateResult>& UpdateItemList() const;
        MtTypedArray<CDataItemUpdateResult>& UpdateItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CCraftProduct m_CraftProduct;  // offset: 0x10
        MtTypedArray<CDataItemUpdateResult> m_UpdateItemList;  // offset: 0x28
        bool m_bIsReceived;  // offset: 0x48
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES : public ::CPacketDataBase
    {
        friend class ::sCraftManager;
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
        CPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataCraftProgress>&, const MtTypedArray<CDataCraftPawnList>&, const MtTypedArray<CDataCommonU32>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataCraftProgress>& CraftProgressList() const;
        MtTypedArray<CDataCraftProgress>& CraftProgressList();
        const MtTypedArray<CDataCraftPawnList>& CraftMyPawnList() const;
        MtTypedArray<CDataCraftPawnList>& CraftMyPawnList();
        const MtTypedArray<CDataCommonU32>& CreatedReicpeList() const;
        MtTypedArray<CDataCommonU32>& CreatedReicpeList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataCraftProgress> m_CraftProgressList;  // offset: 0x10
        MtTypedArray<CDataCraftPawnList> m_CraftMyPawnList;  // offset: 0x30
        MtTypedArray<CDataCommonU32> m_CreatedReicpeList;  // offset: 0x50
        bool m_bIsReceived;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CRAFT_SETTING_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_CRAFT_SETTING_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataCommonU32>&, const MtTypedArray<CDataCraftTimeSaveCost>&, u32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataCommonU32>& ColorRegulateItemList() const;
        MtTypedArray<CDataCommonU32>& ColorRegulateItemList();
        const MtTypedArray<CDataCraftTimeSaveCost>& TimeSaveCostList() const;
        MtTypedArray<CDataCraftTimeSaveCost>& TimeSaveCostList();
        u32 ReasonableCraftLv() const;
        u32 CraftItemLv() const;
        u8 CreateCountMax() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataCommonU32> m_ColorRegulateItemList;  // offset: 0x10
        MtTypedArray<CDataCraftTimeSaveCost> m_TimeSaveCostList;  // offset: 0x30
        u32 m_unReasonableCraftLv;  // offset: 0x50
        u32 m_unCraftItemLv;  // offset: 0x54
        u8 m_ucCreateCountMax;  // offset: 0x58
        bool m_bIsReceived;  // offset: 0x59
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataBorderRewardRecord>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 CycleContentsScheduleId() const;
        const MtTypedArray<CDataBorderRewardRecord>& BorderRewardRecordList() const;
        MtTypedArray<CDataBorderRewardRecord>& BorderRewardRecordList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unCycleContentsScheduleId;  // offset: 0x10
        MtTypedArray<CDataBorderRewardRecord> m_BorderRewardRecordList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CYCLE_CONTENTS_NEWS_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_CYCLE_CONTENTS_NEWS_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataCycleContentsNews>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataCycleContentsNews>& CycleContentsNewsList() const;
        MtTypedArray<CDataCycleContentsNews>& CycleContentsNewsList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataCycleContentsNews> m_CycleContentsNewsList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CYCLE_CONTENTS_NOW_POINT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_CYCLE_CONTENTS_NOW_POINT_LIST_RES();
        s32 WritePacket(CPacket*, u32, u32, const CQuestPointDetail&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 CycleContentsScheduleId() const;
        const CQuestPointDetail& QuestPointDetail() const;
        CQuestPointDetail& QuestPointDetail();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unCycleContentsScheduleId;  // offset: 0x10
        CQuestPointDetail m_QuestPointDetail;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0xa0
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CYCLE_CONTENTS_POINT_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_CYCLE_CONTENTS_POINT_LIST_RES();
        s32 WritePacket(CPacket*, u32, u32, const CQuestPointDetail&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 CycleContentsScheduleId() const;
        const CQuestPointDetail& QuestPointDetail() const;
        CQuestPointDetail& QuestPointDetail();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unCycleContentsScheduleId;  // offset: 0x10
        CQuestPointDetail m_QuestPointDetail;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0xa0
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataRankingRewardRecord>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 CycleContentsScheduleId() const;
        const MtTypedArray<CDataRankingRewardRecord>& RankingRewardRecordList() const;
        MtTypedArray<CDataRankingRewardRecord>& RankingRewardRecordList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unCycleContentsScheduleId;  // offset: 0x10
        MtTypedArray<CDataRankingRewardRecord> m_RankingRewardRecordList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_CYCLE_CONTENTS_REWARD_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_CYCLE_CONTENTS_REWARD_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataCycleContentsReward>&, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 CycleContentsScheduleId() const;
        const MtTypedArray<CDataCycleContentsReward>& CycleContentsRewardList() const;
        MtTypedArray<CDataCycleContentsReward>& CycleContentsRewardList();
        b8 IsAddRewardBox() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unCycleContentsScheduleId;  // offset: 0x10
        MtTypedArray<CDataCycleContentsReward> m_CycleContentsRewardList;  // offset: 0x18
        b8 m_bIsAddRewardBox;  // offset: 0x38
        bool m_bIsReceived;  // offset: 0x39
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_DISPEL_ITEM_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_DISPEL_ITEM_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataDispelBaseItem>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataDispelBaseItem>& DispelBaseItemList() const;
        MtTypedArray<CDataDispelBaseItem>& DispelBaseItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataDispelBaseItem> m_DispelBaseItemList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataDispelCategoryInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataDispelCategoryInfo>& DispelCategoryInfo() const;
        MtTypedArray<CDataDispelCategoryInfo>& DispelCategoryInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataDispelCategoryInfo> m_DispelCategoryInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_DROP_ITEM_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cGatherItemList;
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
        CPacket_S2C_GET_DROP_ITEM_LIST_RES();
        s32 WritePacket(CPacket*, s32, const CStageLayoutID&, u32, const MtTypedArray<CDataGatheringItemElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CStageLayoutID& LayoutId() const;
        CStageLayoutID& LayoutId();
        u32 Id() const;
        const MtTypedArray<CDataGatheringItemElement>& ItemList() const;
        MtTypedArray<CDataGatheringItemElement>& ItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CStageLayoutID m_LayoutId;  // offset: 0x10
        u32 m_unId;  // offset: 0x28
        MtTypedArray<CDataGatheringItemElement> m_ItemList;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_END_CONTENTS_GROUP_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_END_CONTENTS_GROUP_RES();
        s32 WritePacket(CPacket*, s32, u32, u32, const CEndContentsGroup&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 GroupID() const;
        u32 EndContentsType() const;
        const CEndContentsGroup& EndContentsGroup() const;
        CEndContentsGroup& EndContentsGroup();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unGroupID;  // offset: 0x10
        u32 m_unEndContentsType;  // offset: 0x14
        CEndContentsGroup m_EndContentsGroup;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_EXP_MODE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_EXP_MODE_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 Mode() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucMode;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataFavoriteWarpPoint>&, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataFavoriteWarpPoint>& FavoriteWarpPointList() const;
        MtTypedArray<CDataFavoriteWarpPoint>& FavoriteWarpPointList();
        u32 SlotIDMax() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataFavoriteWarpPoint> m_FavoriteWarpPointList;  // offset: 0x10
        u32 m_unSlotIDMax;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x34
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataFreeRentalPawnList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataFreeRentalPawnList>& FreeRentalPawnList() const;
        MtTypedArray<CDataFreeRentalPawnList>& FreeRentalPawnList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataFreeRentalPawnList> m_FreeRentalPawnList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_GAME_SETTING_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_GAME_SETTING_RES();
        s32 WritePacket(CPacket*, s32, const CGameSetting&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CGameSetting& GameSetting() const;
        CGameSetting& GameSetting();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CGameSetting m_GameSetting;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x150
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_GP_DETAIL_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_GP_DETAIL_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPDetail>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPDetail>& GPList() const;
        MtTypedArray<CDataGPDetail>& GPList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPDetail> m_GPList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_GP_PERIOD_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_GP_PERIOD_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPPeriod>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPPeriod>& GPPeriodList() const;
        MtTypedArray<CDataGPPeriod>& GPPeriodList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPPeriod> m_GPPeriodList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_GP_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_GP_RES();
        s32 WritePacket(CPacket*, u32, u32, s64, u64, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 GP() const;
        s64 UseLimit() const;
        u64 RealTime() const;
        u16 Milliseconds() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unGP;  // offset: 0x10
        s64 m_llUseLimit;  // offset: 0x18
        u64 m_ullRealTime;  // offset: 0x20
        u16 m_usMilliseconds;  // offset: 0x28
        bool m_bIsReceived;  // offset: 0x2a
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_INSTANT_KEY_VALUE_UL_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_INSTANT_KEY_VALUE_UL_RES();
        s32 WritePacket(CPacket*, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 Result() const;
        u32 Value() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucResult;  // offset: 0xa
        u32 m_unValue;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_ITEM_STORAGE_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_ITEM_STORAGE_INFO_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataGameItemStorageInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataGameItemStorageInfo>& GameItemStorageInfoList() const;
        MtTypedArray<CDataGameItemStorageInfo>& GameItemStorageInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataGameItemStorageInfo> m_GameItemStorageInfoList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_JOB_CHANGE_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_JOB_CHANGE_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataJobChangeInfo>&, const MtTypedArray<CDataJobChangeInfo>&, const MtTypedArray<CDataPawnJobChangeInfo>&, const MtTypedArray<CDataJobPlayPoint>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataJobChangeInfo>& JobChangeInfo() const;
        MtTypedArray<CDataJobChangeInfo>& JobChangeInfo();
        const MtTypedArray<CDataJobChangeInfo>& JobReleaseInfo() const;
        MtTypedArray<CDataJobChangeInfo>& JobReleaseInfo();
        const MtTypedArray<CDataPawnJobChangeInfo>& PawnJobChangeInfoList() const;
        MtTypedArray<CDataPawnJobChangeInfo>& PawnJobChangeInfoList();
        const MtTypedArray<CDataJobPlayPoint>& PlayPointList() const;
        MtTypedArray<CDataJobPlayPoint>& PlayPointList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataJobChangeInfo> m_JobChangeInfo;  // offset: 0x10
        MtTypedArray<CDataJobChangeInfo> m_JobReleaseInfo;  // offset: 0x30
        MtTypedArray<CDataPawnJobChangeInfo> m_PawnJobChangeInfoList;  // offset: 0x50
        MtTypedArray<CDataJobPlayPoint> m_PlayPointList;  // offset: 0x70
        bool m_bIsReceived;  // offset: 0x90
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataReleaseAreaInfoSet>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataReleaseAreaInfoSet>& ReleaseAreaInfoSetList() const;
        MtTypedArray<CDataReleaseAreaInfoSet>& ReleaseAreaInfoSetList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataReleaseAreaInfoSet> m_ReleaseAreaInfoSetList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataLearnedAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataLearnedAcquirementParam>& LearnedAcquirementParamList() const;
        MtTypedArray<CDataLearnedAcquirementParam>& LearnedAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataLearnedAcquirementParam> m_LearnedAcquirementParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataNormalSkillParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataNormalSkillParam>& NormalSkillParamList() const;
        MtTypedArray<CDataNormalSkillParam>& NormalSkillParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataNormalSkillParam> m_NormalSkillParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_LEARNED_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_LEARNED_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataLearnedAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataLearnedAcquirementParam>& LearnedAcquirementParamList() const;
        MtTypedArray<CDataLearnedAcquirementParam>& LearnedAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataLearnedAcquirementParam> m_LearnedAcquirementParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_LIGHT_QUEST_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_LIGHT_QUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataLightQuestList>&, u8, u8, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 BaseID() const;
        const MtTypedArray<CDataLightQuestList>& LightQuestList() const;
        MtTypedArray<CDataLightQuestList>& LightQuestList();
        u8 NotCompleteQuestNum() const;
        u8 GpCompletePriceGp() const;
        b8 GpCompleteEnable() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unBaseID;  // offset: 0x10
        MtTypedArray<CDataLightQuestList> m_LightQuestList;  // offset: 0x18
        u8 m_ucNotCompleteQuestNum;  // offset: 0x38
        u8 m_ucGpCompletePriceGp;  // offset: 0x39
        b8 m_bGpCompleteEnable;  // offset: 0x3a
        bool m_bIsReceived;  // offset: 0x3b
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_LOGIN_ANNOUNCEMENT_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_LOGIN_ANNOUNCEMENT_RES();
        s32 WritePacket(CPacket*, s32, const char*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const char* Message() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtString m_wstrMessage;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_LOT_QUEST_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_LOT_QUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataLotQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 LotQuestType() const;
        const MtTypedArray<CDataLotQuestList>& LotQuestList() const;
        MtTypedArray<CDataLotQuestList>& LotQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unLotQuestType;  // offset: 0x10
        MtTypedArray<CDataLotQuestList> m_LotQuestList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_MAIN_QUEST_LIST_END_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_GET_MAIN_QUEST_LIST_END_NOTICE();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_MAIN_QUEST_LIST_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_GET_MAIN_QUEST_LIST_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataMainQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataMainQuestList>& MainQuestList() const;
        MtTypedArray<CDataMainQuestList>& MainQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataMainQuestList> m_MainQuestList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_MAIN_QUEST_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_MAIN_QUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataMainQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataMainQuestList>& MainQuestList() const;
        MtTypedArray<CDataMainQuestList>& MainQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataMainQuestList> m_MainQuestList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_MATCHING_PROFILE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_MATCHING_PROFILE_RES();
        s32 WritePacket(CPacket*, s32, const CMatchingProfile&, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CMatchingProfile& MatchingProfile() const;
        CMatchingProfile& MatchingProfile();
        u8 Job() const;
        u32 Level() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CMatchingProfile m_MatchingProfile;  // offset: 0x10
        u8 m_ucJob;  // offset: 0x48
        u32 m_unLevel;  // offset: 0x4c
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataCycleContentsExtraReward>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataCycleContentsExtraReward>& CycleContentsExtraRewardList() const;
        MtTypedArray<CDataCycleContentsExtraReward>& CycleContentsExtraRewardList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataCycleContentsExtraReward> m_CycleContentsExtraRewardList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 ListNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucListNum;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataRewardBoxRecord>&, const MtTypedArray<CDataCycleContentsRewardRecord>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataRewardBoxRecord>& RewardBoxRecordList() const;
        MtTypedArray<CDataRewardBoxRecord>& RewardBoxRecordList();
        const MtTypedArray<CDataCycleContentsRewardRecord>& CycleContentsRewardRecordList() const;
        MtTypedArray<CDataCycleContentsRewardRecord>& CycleContentsRewardRecordList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataRewardBoxRecord> m_RewardBoxRecordList;  // offset: 0x10
        MtTypedArray<CDataCycleContentsRewardRecord> m_CycleContentsRewardRecordList;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_OM_INSTANT_KEY_VALUE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_OM_INSTANT_KEY_VALUE_RES();
        s32 WritePacket(CPacket*, s32, u32, const COmData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 StageId() const;
        const COmData& Value() const;
        COmData& Value();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unStageId;  // offset: 0x10
        COmData m_Value;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_ORB_GAIN_EXTEND_PARAM_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_ORB_GAIN_EXTEND_PARAM_RES();
        s32 WritePacket(CPacket*, s32, const COrbGainExtendParam&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const COrbGainExtendParam& ExtendParam() const;
        COrbGainExtendParam& ExtendParam();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        COrbGainExtendParam m_ExtendParam;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PARTY_PAWN_DATA_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PARTY_PAWN_DATA_RES();
        s32 WritePacket(CPacket*, s32, u32, u32, const CPawnInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 CharacterId() const;
        u32 PawnId() const;
        const CPawnInfo& PawnInfo() const;
        CPawnInfo& PawnInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unCharacterId;  // offset: 0x10
        u32 m_unPawnId;  // offset: 0x14
        CPawnInfo m_PawnInfo;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x248
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES();
        s32 WritePacket(CPacket*, s32, const CPartyQuestProgressInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CPartyQuestProgressInfo& PartyQuestProgressInfo() const;
        CPartyQuestProgressInfo& PartyQuestProgressInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CPartyQuestProgressInfo m_PartyQuestProgressInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x98
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PAWN_ABILITY_COST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PAWN_ABILITY_COST_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u32 CostMax() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u32 m_unCostMax;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataLearnedAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const MtTypedArray<CDataLearnedAcquirementParam>& LearnedAcquirementParamList() const;
        MtTypedArray<CDataLearnedAcquirementParam>& LearnedAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        MtTypedArray<CDataLearnedAcquirementParam> m_LearnedAcquirementParamList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataNormalSkillParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const MtTypedArray<CDataNormalSkillParam>& NormalSkillParamList() const;
        MtTypedArray<CDataNormalSkillParam>& NormalSkillParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        MtTypedArray<CDataNormalSkillParam> m_NormalSkillParamList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataLearnedAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const MtTypedArray<CDataLearnedAcquirementParam>& LearnedAcquirementParamList() const;
        MtTypedArray<CDataLearnedAcquirementParam>& LearnedAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        MtTypedArray<CDataLearnedAcquirementParam> m_LearnedAcquirementParamList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataReleaseOrbElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const MtTypedArray<CDataReleaseOrbElement>& OrbElementList() const;
        MtTypedArray<CDataReleaseOrbElement>& OrbElementList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        MtTypedArray<CDataReleaseOrbElement> m_OrbElementList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataSetAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const MtTypedArray<CDataSetAcquirementParam>& SetAcquirementParamList() const;
        MtTypedArray<CDataSetAcquirementParam>& SetAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        MtTypedArray<CDataSetAcquirementParam> m_SetAcquirementParamList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataSetAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const MtTypedArray<CDataSetAcquirementParam>& SetAcquirementParamList() const;
        MtTypedArray<CDataSetAcquirementParam>& SetAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        MtTypedArray<CDataSetAcquirementParam> m_SetAcquirementParamList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES();
        s32 WritePacket(CPacket*, s32, u32, const CPawnTotalScore&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const CPawnTotalScore& PawnTotalScore() const;
        CPawnTotalScore& PawnTotalScore();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        CPawnTotalScore m_PawnTotalScore;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES();
        s32 WritePacket(CPacket*, s32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 PointType() const;
        u32 Point() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucPointType;  // offset: 0x10
        u32 m_unPoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PRESET_ABILITY_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PRESET_ABILITY_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataPresetAbilityParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataPresetAbilityParam>& PresetAbilityParamList() const;
        MtTypedArray<CDataPresetAbilityParam>& PresetAbilityParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataPresetAbilityParam> m_PresetAbilityParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_PRIORITY_QUEST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_PRIORITY_QUEST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataPriorityQuestSetting>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataPriorityQuestSetting>& PriorityQuestSettingList() const;
        MtTypedArray<CDataPriorityQuestSetting>& PriorityQuestSettingList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataPriorityQuestSetting> m_PriorityQuestSettingList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_QUEST_COMPLETE_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_QUEST_COMPLETE_LIST_RES();
        s32 WritePacket(CPacket*, s32, u8, const MtTypedArray<CDataQuestId>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 QuestType() const;
        const MtTypedArray<CDataQuestId>& QuestIdList() const;
        MtTypedArray<CDataQuestId>& QuestIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucQuestType;  // offset: 0x10
        MtTypedArray<CDataQuestId> m_QuestIdList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES();
        s32 WritePacket(CPacket*, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        b8 Value() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        b8 m_bValue;  // offset: 0xa
        bool m_bIsReceived;  // offset: 0xb
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataQuestPartyBonusInfo>&, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataQuestPartyBonusInfo>& QuestPartyBonusInfoList() const;
        MtTypedArray<CDataQuestPartyBonusInfo>& QuestPartyBonusInfoList();
        u64 NextReloadTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataQuestPartyBonusInfo> m_QuestPartyBonusInfoList;  // offset: 0x10
        u64 m_ullNextReloadTime;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 QuestId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unQuestId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_REAL_TIME_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_REAL_TIME_RES();
        s32 WritePacket(CPacket*, u64, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u64 RealTime() const;
        u16 Milliseconds() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u64 m_ullRealTime;  // offset: 0x10
        u16 m_usMilliseconds;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1a
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataRecommendedQuestInfoList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataRecommendedQuestInfoList>& RecommendedQuestInfoList() const;
        MtTypedArray<CDataRecommendedQuestInfoList>& RecommendedQuestInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataRecommendedQuestInfoList> m_RecommendedQuestInfoList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataReleaseAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataReleaseAcquirementParam>& ReleaseAcquirementParamList() const;
        MtTypedArray<CDataReleaseAcquirementParam>& ReleaseAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataReleaseAcquirementParam> m_ReleaseAcquirementParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataReleaseOrbElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataReleaseOrbElement>& OrbElementList() const;
        MtTypedArray<CDataReleaseOrbElement>& OrbElementList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataReleaseOrbElement> m_OrbElementList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_RELEASE_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_RELEASE_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataReleaseAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataReleaseAcquirementParam>& ReleaseAcquirementParamList() const;
        MtTypedArray<CDataReleaseAcquirementParam>& ReleaseAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataReleaseAcquirementParam> m_ReleaseAcquirementParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_RENTED_PAWN_DATA_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_RENTED_PAWN_DATA_RES();
        s32 WritePacket(CPacket*, s32, u32, const CPawnInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const CPawnInfo& PawnInfo() const;
        CPawnInfo& PawnInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        CPawnInfo m_PawnInfo;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x248
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_REVIVE_CHARGEABLE_TIME_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_REVIVE_CHARGEABLE_TIME_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 RemainTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unRemainTime;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_REVIVE_POINT_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_REVIVE_POINT_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 RevivePoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucRevivePoint;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_REWARD_BOX_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_REWARD_BOX_ITEM_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_REWARD_BOX_LIST_NUM_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_REWARD_BOX_LIST_NUM_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 ListNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucListNum;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_REWARD_BOX_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_REWARD_BOX_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataRewardBoxRecord>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataRewardBoxRecord>& RewardBoxRecordList() const;
        MtTypedArray<CDataRewardBoxRecord>& RewardBoxRecordList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataRewardBoxRecord> m_RewardBoxRecordList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataScreenShotCategory>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataScreenShotCategory>& CategoryList() const;
        MtTypedArray<CDataScreenShotCategory>& CategoryList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataScreenShotCategory> m_CategoryList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SERVER_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_SERVER_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataGameServerListInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataGameServerListInfo>& ServerList() const;
        MtTypedArray<CDataGameServerListInfo>& ServerList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataGameServerListInfo> m_ServerList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SET_ABILITY_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_SET_ABILITY_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataSetAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataSetAcquirementParam>& SetAcquirementParamList() const;
        MtTypedArray<CDataSetAcquirementParam>& SetAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataSetAcquirementParam> m_SetAcquirementParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SET_CONTEXT_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_SET_CONTEXT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataSetQuestInfoList>&, u16, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 DistributeID() const;
        const MtTypedArray<CDataSetQuestInfoList>& SetQuestInfoList() const;
        MtTypedArray<CDataSetQuestInfoList>& SetQuestInfoList();
        u16 AreaBaseMinLevel() const;
        u16 AreaBaseMaxLevel() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unDistributeID;  // offset: 0x10
        MtTypedArray<CDataSetQuestInfoList> m_SetQuestInfoList;  // offset: 0x18
        u16 m_usAreaBaseMinLevel;  // offset: 0x38
        u16 m_usAreaBaseMaxLevel;  // offset: 0x3a
        bool m_bIsReceived;  // offset: 0x3c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SET_QUEST_LIST_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_GET_SET_QUEST_LIST_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, const MtTypedArray<CDataSetQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 SelectCharacterId() const;
        u32 DistributeId() const;
        const MtTypedArray<CDataSetQuestList>& SetQuestList() const;
        MtTypedArray<CDataSetQuestList>& SetQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unSelectCharacterId;  // offset: 0xc
        u32 m_unDistributeId;  // offset: 0x10
        MtTypedArray<CDataSetQuestList> m_SetQuestList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SET_QUEST_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_SET_QUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataSetQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 DistributeID() const;
        const MtTypedArray<CDataSetQuestList>& SetQuestList() const;
        MtTypedArray<CDataSetQuestList>& SetQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unDistributeID;  // offset: 0x10
        MtTypedArray<CDataSetQuestList> m_SetQuestList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataSetQuestOpenDate>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataSetQuestOpenDate>& SetQuestOpenDateList() const;
        MtTypedArray<CDataSetQuestOpenDate>& SetQuestOpenDateList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataSetQuestOpenDate> m_SetQuestOpenDateList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SET_SKILL_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_SET_SKILL_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataSetAcquirementParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataSetAcquirementParam>& SetAcquirementParamList() const;
        MtTypedArray<CDataSetAcquirementParam>& SetAcquirementParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataSetAcquirementParam> m_SetAcquirementParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SHOP_GOODS_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_SHOP_GOODS_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataGoodsParam>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataGoodsParam>& GoodsParamList() const;
        MtTypedArray<CDataGoodsParam>& GoodsParamList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataGoodsParam> m_GoodsParamList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_SPOT_INFO_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_SPOT_INFO_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataSpotInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataSpotInfo>& SpotInfoList() const;
        MtTypedArray<CDataSpotInfo>& SpotInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataSpotInfo> m_SpotInfoList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_STAY_PRICE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_STAY_PRICE_RES();
        s32 WritePacket(CPacket*, s32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 PointType() const;
        u32 Point() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucPointType;  // offset: 0x10
        u32 m_unPoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataTimeLimitedQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataTimeLimitedQuestList>& TimeLimitedQuestList() const;
        MtTypedArray<CDataTimeLimitedQuestList>& TimeLimitedQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataTimeLimitedQuestList> m_TimeLimitedQuestList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataTutorialQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 StageNo() const;
        const MtTypedArray<CDataTutorialQuestList>& TutorialQuestList() const;
        MtTypedArray<CDataTutorialQuestList>& TutorialQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unStageNo;  // offset: 0x10
        MtTypedArray<CDataTutorialQuestList> m_TutorialQuestList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_WARP_POINT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_WARP_POINT_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataWarpPoint>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataWarpPoint>& WarpPointList() const;
        MtTypedArray<CDataWarpPoint>& WarpPointList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataWarpPoint> m_WarpPointList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_WORLD_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_GET_WORLD_INFO_RES();
        s32 WritePacket(CPacket*, s32, u32, const CWorldInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 WorldID() const;
        const CWorldInfo& WorldInfo() const;
        CWorldInfo& WorldInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unWorldID;  // offset: 0x10
        CWorldInfo m_WorldInfo;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x78
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataWorldManageQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataWorldManageQuestList>& WorldManageQuestList() const;
        MtTypedArray<CDataWorldManageQuestList>& WorldManageQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataWorldManageQuestList> m_WorldManageQuestList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataWorldManageQuestList>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataWorldManageQuestList>& WorldManageQuestList() const;
        MtTypedArray<CDataWorldManageQuestList>& WorldManageQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataWorldManageQuestList> m_WorldManageQuestList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_COURSE_END_NTC : public ::CPacketDataBase
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
        CPacket_S2C_GP_COURSE_END_NTC();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CourseID() const;
        u32 announceType() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCourseID;  // offset: 0xc
        u32 m_unannounceType;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_COURSE_EXTEND_NTC : public ::CPacketDataBase
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
        CPacket_S2C_GP_COURSE_EXTEND_NTC();
        s32 WritePacket(CPacket*, u32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CourseID() const;
        u64 FinishDateTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCourseID;  // offset: 0xc
        u64 m_ullFinishDateTime;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPCourseAvailable>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPCourseAvailable>& Items() const;
        MtTypedArray<CDataGPCourseAvailable>& Items();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPCourseAvailable> m_Items;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_COURSE_GET_VALID_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_COURSE_GET_VALID_LIST_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPCourseValid>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPCourseValid>& Items() const;
        MtTypedArray<CDataGPCourseValid>& Items();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPCourseValid> m_Items;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_COURSE_GET_VERSION_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_COURSE_GET_VERSION_RES();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 Version() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unVersion;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_COURSE_START_NTC : public ::CPacketDataBase
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
        CPacket_S2C_GP_COURSE_START_NTC();
        s32 WritePacket(CPacket*, u32, u64, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CourseID() const;
        u64 FinishDateTime() const;
        u32 announceType() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCourseID;  // offset: 0xc
        u64 m_ullFinishDateTime;  // offset: 0x10
        u32 m_unannounceType;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_COURSE_START_PARTY_NTC : public ::CPacketDataBase
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
        CPacket_S2C_GP_COURSE_START_PARTY_NTC();
        s32 WritePacket(CPacket*, u8, u32, u32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 MemberIndex() const;
        u32 CourseID() const;
        u32 announceType() const;
        u64 FinishDateTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucMemberIndex;  // offset: 0xa
        u32 m_unCourseID;  // offset: 0xc
        u32 m_unannounceType;  // offset: 0x10
        u64 m_ullFinishDateTime;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_COURSE_USE_FROM_AVAILABLE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_COURSE_USE_FROM_AVAILABLE_RES();
        s32 WritePacket(CPacket*, u32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u64 FinishDateTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u64 m_ullFinishDateTime;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_EDIT_GET_GP_PRICE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_EDIT_GET_GP_PRICE_RES();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 Price() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unPrice;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_RES();
        s32 WritePacket(CPacket*, u32, b8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        b8 CanBuy() const;
        u32 LineupId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        b8 m_bCanBuy;  // offset: 0x10
        u32 m_unLineupId;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_VOICE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_VOICE_RES();
        s32 WritePacket(CPacket*, u32, b8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        b8 CanBuy() const;
        u32 LineupId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        b8 m_bCanBuy;  // offset: 0x10
        u32 m_unLineupId;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_SHOP_DISPLAY_BUY_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_SHOP_DISPLAY_BUY_RES();
        s32 WritePacket(CPacket*, u32, u32, const MtTypedArray<CDataCommonU32>&, u32, const char*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u32 LineupId() const;
        const MtTypedArray<CDataCommonU32>& CommonIdList() const;
        MtTypedArray<CDataCommonU32>& CommonIdList();
        u32 Balance() const;
        const char* LineupName() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u32 m_unLineupId;  // offset: 0x10
        MtTypedArray<CDataCommonU32> m_CommonIdList;  // offset: 0x18
        u32 m_unBalance;  // offset: 0x38
        MtString m_wstrLineupName;  // offset: 0x40
        bool m_bIsReceived;  // offset: 0x48
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPShopDisplayLineup>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPShopDisplayLineup>& Items() const;
        MtTypedArray<CDataGPShopDisplayLineup>& Items();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPShopDisplayLineup> m_Items;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPShopDisplayType>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPShopDisplayType>& Items() const;
        MtTypedArray<CDataGPShopDisplayType>& Items();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPShopDisplayType> m_Items;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPShopBuyHistoryElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPShopBuyHistoryElement>& Items() const;
        MtTypedArray<CDataGPShopBuyHistoryElement>& Items();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPShopBuyHistoryElement> m_Items;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES : public ::CPacketDataBase
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
        CPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPShopLineupElementCourse>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPShopLineupElementCourse>& Items() const;
        MtTypedArray<CDataGPShopLineupElementCourse>& Items();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPShopLineupElementCourse> m_Items;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_NTC : public ::CPacketDataBase
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
        CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_NTC();
        s32 WritePacket(CPacket*, u64, const CCommunityCharacterBaseInfo&, const CCharacterListElement&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u64 GroupID() const;
        const CCommunityCharacterBaseInfo& InviterInfo() const;
        CCommunityCharacterBaseInfo& InviterInfo();
        const CCharacterListElement& VisitorInfo() const;
        CCharacterListElement& VisitorInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u64 m_ullGroupID;  // offset: 0x10
        CCommunityCharacterBaseInfo m_InviterInfo;  // offset: 0x18
        CCharacterListElement m_VisitorInfo;  // offset: 0x48
        bool m_bIsReceived;  // offset: 0xb0
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES : public ::CPacketDataBase
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
        CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_GROUP_CHAT_KICK_CHARACTER_RES : public ::CPacketDataBase
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
        CPacket_S2C_GROUP_CHAT_KICK_CHARACTER_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_INSTANCE_AREA_RESET_NTC : public ::CPacketDataBase
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
        CPacket_S2C_INSTANCE_AREA_RESET_NTC();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 JobId() const;
        u8 JobValueType() const;
        u32 Value() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unJobId;  // offset: 0x10
        u8 m_ucJobValueType;  // offset: 0x14
        u32 m_unValue;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES : public ::CPacketDataBase
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
        CPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES();
        s32 WritePacket(CPacket*, s32, u8, u8, const MtTypedArray<CDataJobValueShopItem>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 JobId() const;
        u8 JobValueType() const;
        const MtTypedArray<CDataJobValueShopItem>& JobValueShopItemList() const;
        MtTypedArray<CDataJobValueShopItem>& JobValueShopItemList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJobId;  // offset: 0x10
        u8 m_ucJobValueType;  // offset: 0x11
        MtTypedArray<CDataJobValueShopItem> m_JobValueShopItemList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_JOIN_LOBBY_QUEST_INFO_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_JOIN_LOBBY_QUEST_INFO_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataLightQuestOrderList>&, const MtTypedArray<CDataSetQuestOrderList>&, const MtTypedArray<CDataMainQuestOrderList>&, const MtTypedArray<CDataTutorialQuestOrderList>&, const MtTypedArray<CDataLotQuestOrderList>&, const MtTypedArray<CDataTimeLimitedQuestOrderList>&, const MtTypedArray<CDataWorldManageQuestOrderList>&, const MtTypedArray<CDataExpiredQuestList>&, const MtTypedArray<CDataQuestId>&, const MtTypedArray<CDataQuestId>&, const MtTypedArray<CDataPriorityQuest>&, const MtTypedArray<CDataAreaRank>&, const CQuestDefine&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataLightQuestOrderList>& LightQuestOrderList() const;
        MtTypedArray<CDataLightQuestOrderList>& LightQuestOrderList();
        const MtTypedArray<CDataSetQuestOrderList>& SetQuestOrderList() const;
        MtTypedArray<CDataSetQuestOrderList>& SetQuestOrderList();
        const MtTypedArray<CDataMainQuestOrderList>& MainQuestOrderList() const;
        MtTypedArray<CDataMainQuestOrderList>& MainQuestOrderList();
        const MtTypedArray<CDataTutorialQuestOrderList>& TutorialQuestOrderList() const;
        MtTypedArray<CDataTutorialQuestOrderList>& TutorialQuestOrderList();
        const MtTypedArray<CDataLotQuestOrderList>& LotQuestOrderList() const;
        MtTypedArray<CDataLotQuestOrderList>& LotQuestOrderList();
        const MtTypedArray<CDataTimeLimitedQuestOrderList>& TimeLimitedQuestOrderList() const;
        MtTypedArray<CDataTimeLimitedQuestOrderList>& TimeLimitedQuestOrderList();
        const MtTypedArray<CDataWorldManageQuestOrderList>& WorldManageQuestOrderList() const;
        MtTypedArray<CDataWorldManageQuestOrderList>& WorldManageQuestOrderList();
        const MtTypedArray<CDataExpiredQuestList>& ExpiredQuestList() const;
        MtTypedArray<CDataExpiredQuestList>& ExpiredQuestList();
        const MtTypedArray<CDataQuestId>& MainQuestIdList() const;
        MtTypedArray<CDataQuestId>& MainQuestIdList();
        const MtTypedArray<CDataQuestId>& TutorialQuestIdList() const;
        MtTypedArray<CDataQuestId>& TutorialQuestIdList();
        const MtTypedArray<CDataPriorityQuest>& PriorityQuestList() const;
        MtTypedArray<CDataPriorityQuest>& PriorityQuestList();
        const MtTypedArray<CDataAreaRank>& AreaRankList() const;
        MtTypedArray<CDataAreaRank>& AreaRankList();
        const CQuestDefine& QuestDefine() const;
        CQuestDefine& QuestDefine();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataLightQuestOrderList> m_LightQuestOrderList;  // offset: 0x10
        MtTypedArray<CDataSetQuestOrderList> m_SetQuestOrderList;  // offset: 0x30
        MtTypedArray<CDataMainQuestOrderList> m_MainQuestOrderList;  // offset: 0x50
        MtTypedArray<CDataTutorialQuestOrderList> m_TutorialQuestOrderList;  // offset: 0x70
        MtTypedArray<CDataLotQuestOrderList> m_LotQuestOrderList;  // offset: 0x90
        MtTypedArray<CDataTimeLimitedQuestOrderList> m_TimeLimitedQuestOrderList;  // offset: 0xb0
        MtTypedArray<CDataWorldManageQuestOrderList> m_WorldManageQuestOrderList;  // offset: 0xd0
        MtTypedArray<CDataExpiredQuestList> m_ExpiredQuestList;  // offset: 0xf0
        MtTypedArray<CDataQuestId> m_MainQuestIdList;  // offset: 0x110
        MtTypedArray<CDataQuestId> m_TutorialQuestIdList;  // offset: 0x130
        MtTypedArray<CDataPriorityQuest> m_PriorityQuestList;  // offset: 0x150
        MtTypedArray<CDataAreaRank> m_AreaRankList;  // offset: 0x170
        CQuestDefine m_QuestDefine;  // offset: 0x190
        bool m_bIsReceived;  // offset: 0x1a0
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_JOIN_PARTY_MYPAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_JOIN_PARTY_MYPAWN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_JOIN_PARTY_RENTED_PAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_JOIN_PARTY_RENTED_PAWN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, u16, u16, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 RequestCharacterId() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        u16 SequenceNo() const;
        u16 BlockNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unRequestCharacterId;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        u16 m_usProcessNo;  // offset: 0x14
        u16 m_usSequenceNo;  // offset: 0x16
        u16 m_usBlockNo;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1a
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_RES : public ::CPacketDataBase
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
        CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_RES();
        s32 WritePacket(CPacket*, s32, u8, u32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 QuestProgressResult() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucQuestProgressResult;  // offset: 0x10
        u32 m_unQuestScheduleId;  // offset: 0x14
        u16 m_usProcessNo;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1a
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LEARN_ABILITY_RES : public ::CPacketDataBase
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
        CPacket_S2C_LEARN_ABILITY_RES();
        s32 WritePacket(CPacket*, s32, u8, u32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 Job() const;
        u32 NewJobPoint() const;
        u32 AbilityID() const;
        u8 AbilityLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJob;  // offset: 0x10
        u32 m_unNewJobPoint;  // offset: 0x14
        u32 m_unAbilityID;  // offset: 0x18
        u8 m_ucAbilityLv;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x1d
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LEARN_NORMAL_SKILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_LEARN_NORMAL_SKILL_RES();
        s32 WritePacket(CPacket*, s32, u8, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 Job() const;
        u32 SkillID() const;
        u32 NewJobPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJob;  // offset: 0x10
        u32 m_unSkillID;  // offset: 0x14
        u32 m_unNewJobPoint;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LEARN_PAWN_ABILITY_RES : public ::CPacketDataBase
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
        CPacket_S2C_LEARN_PAWN_ABILITY_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u8 Job() const;
        u32 NewJobPoint() const;
        u32 AbilityID() const;
        u8 AbilityLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucJob;  // offset: 0x14
        u32 m_unNewJobPoint;  // offset: 0x18
        u32 m_unAbilityID;  // offset: 0x1c
        u8 m_ucAbilityLv;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x21
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LEARN_PAWN_NORMAL_SKILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_LEARN_PAWN_NORMAL_SKILL_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u8 Job() const;
        u32 SkillID() const;
        u32 NewJobPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucJob;  // offset: 0x14
        u32 m_unSkillID;  // offset: 0x18
        u32 m_unNewJobPoint;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LEARN_PAWN_SKILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_LEARN_PAWN_SKILL_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u8 Job() const;
        u32 NewJobPoint() const;
        u32 SkillID() const;
        u8 SkillLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucJob;  // offset: 0x14
        u32 m_unNewJobPoint;  // offset: 0x18
        u32 m_unSkillID;  // offset: 0x1c
        u8 m_ucSkillLv;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x21
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LEARN_SKILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_LEARN_SKILL_RES();
        s32 WritePacket(CPacket*, s32, u8, u32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 Job() const;
        u32 NewJobPoint() const;
        u32 SkillID() const;
        u8 SkillLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJob;  // offset: 0x10
        u32 m_unNewJobPoint;  // offset: 0x14
        u32 m_unSkillID;  // offset: 0x18
        u8 m_ucSkillLv;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x1d
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES : public ::CPacketDataBase
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
        CPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataQuestIdScheduleId>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 BaseID() const;
        const MtTypedArray<CDataQuestIdScheduleId>& CompleteQuestList() const;
        MtTypedArray<CDataQuestIdScheduleId>& CompleteQuestList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unBaseID;  // offset: 0x10
        MtTypedArray<CDataQuestIdScheduleId> m_CompleteQuestList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LOADING_GET_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_LOADING_GET_INFO_RES();
        s32 WritePacket(CPacket*, s32, const CDataLoadingInfoSchedules&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CDataLoadingInfoSchedules& Info() const;
        CDataLoadingInfoSchedules& Info();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CDataLoadingInfoSchedules m_Info;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LOBBY_CHAT_MSG_RES : public ::CPacketDataBase
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
        CPacket_S2C_LOBBY_CHAT_MSG_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LOBBY_LEAVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_LOBBY_LEAVE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LOGIN_RES : public ::CPacketDataBase
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
        CPacket_S2C_LOGIN_RES();
        s32 WritePacket(CPacket*, s32, b8, const char*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        b8 IsCogLogin() const;
        const char* OnetimeToken() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        b8 m_bIsCogLogin;  // offset: 0x10
        MtString m_wstrOnetimeToken;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LOST_PAWN_GOLDEN_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_LOST_PAWN_GOLDEN_REVIVE_RES();
        s32 WritePacket(CPacket*, s32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnId() const;
        u8 GP() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnId;  // offset: 0x10
        u8 m_ucGP;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x15
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LOST_PAWN_POINT_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_LOST_PAWN_POINT_REVIVE_RES();
        s32 WritePacket(CPacket*, s32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnId() const;
        u8 RevivePoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnId;  // offset: 0x10
        u8 m_ucRevivePoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x15
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LOST_PAWN_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_LOST_PAWN_REVIVE_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_LOST_PAWN_WALLET_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_LOST_PAWN_WALLET_REVIVE_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnId() const;
        u8 Type() const;
        u32 Value() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnId;  // offset: 0x10
        u8 m_ucType;  // offset: 0x14
        u32 m_unValue;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MAIL_DELETE_RES : public ::CPacketDataBase
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
        CPacket_S2C_MAIL_DELETE_RES();
        s32 WritePacket(CPacket*, s32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 Id() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MAIL_GET_LIST_FOOT_RES : public ::CPacketDataBase
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
        CPacket_S2C_MAIL_GET_LIST_FOOT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MAIL_GET_LIST_HEAD_RES : public ::CPacketDataBase
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
        CPacket_S2C_MAIL_GET_LIST_HEAD_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Num() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unNum;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MAIL_GET_TEXT_RES : public ::CPacketDataBase
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
        CPacket_S2C_MAIL_GET_TEXT_RES();
        s32 WritePacket(CPacket*, s32, u64, const char*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 Id() const;
        const char* MailText() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullId;  // offset: 0x10
        MtString m_wstrMailText;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MAIL_SEND_NTC : public ::CPacketDataBase
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
        CPacket_S2C_MAIL_SEND_NTC();
        s32 WritePacket(CPacket*, const CMailInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CMailInfo& MailInfo() const;
        CMailInfo& MailInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CMailInfo m_MailInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MASTER_THROW_RES : public ::CPacketDataBase
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
        CPacket_S2C_MASTER_THROW_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MOVE_IN_SERVER_RES : public ::CPacketDataBase
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
        CPacket_S2C_MOVE_IN_SERVER_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MOVE_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_MOVE_ITEM_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MY_ROOM_BGM_UPDATE_RES : public ::CPacketDataBase
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
        CPacket_S2C_MY_ROOM_BGM_UPDATE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_MY_ROOM_RELEASE_RES : public ::CPacketDataBase
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
        CPacket_S2C_MY_ROOM_RELEASE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_NOTICE();
        s32 WritePacket(CPacket*, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 ListNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucListNum;  // offset: 0xa
        bool m_bIsReceived;  // offset: 0xb
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_OPEN_UI_NTC : public ::CPacketDataBase
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
        CPacket_S2C_OPEN_UI_NTC();
        s32 WritePacket(CPacket*, u32, u16, const char*, const char*, u32, const MtTypedArray<CDataUIListCommand>&, const MtTypedArray<CDataUIListElement>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Id() const;
        u16 Type() const;
        const char* TitleJP() const;
        const char* TitleEN() const;
        u32 ArgNum1() const;
        const MtTypedArray<CDataUIListCommand>& Commands() const;
        MtTypedArray<CDataUIListCommand>& Commands();
        const MtTypedArray<CDataUIListElement>& Elements() const;
        MtTypedArray<CDataUIListElement>& Elements();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unId;  // offset: 0xc
        u16 m_usType;  // offset: 0x10
        MtString m_wstrTitleJP;  // offset: 0x18
        MtString m_wstrTitleEN;  // offset: 0x20
        u32 m_unArgNum1;  // offset: 0x28
        MtTypedArray<CDataUIListCommand> m_Commands;  // offset: 0x30
        MtTypedArray<CDataUIListElement> m_Elements;  // offset: 0x50
        bool m_bIsReceived;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES();
        s32 WritePacket(CPacket*, s32, u32, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 RemainSec() const;
        b8 IsMax() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unRemainSec;  // offset: 0x10
        b8 m_bIsMax;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x15
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTNER_PAWN_SET_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTNER_PAWN_SET_RES();
        s32 WritePacket(CPacket*, s32, const CPartnerPawnData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CPartnerPawnData& PartnerInfo() const;
        CPartnerPawnData& PartnerInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CPartnerPawnData m_PartnerInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_BREAKUP_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_BREAKUP_NTC();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_BREAKUP_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_BREAKUP_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_CHANGE_HOST_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_CHANGE_HOST_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_CHANGE_LEADER_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_CHANGE_LEADER_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_CHANGE_LEADER_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_CHANGE_LEADER_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_GET_CONTENT_NUMBER_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_GET_CONTENT_NUMBER_RES();
        s32 WritePacket(CPacket*, s32, u32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PartyId() const;
        u64 ContentNumber() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPartyId;  // offset: 0x10
        u64 m_ullContentNumber;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_CANCEL_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_CANCEL_NTC();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_CANCEL_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_CANCEL_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_ENTRY_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_ENTRY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_FAIL_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_FAIL_NTC();
        s32 WritePacket(CPacket*, s32, u16, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u16 ServerId() const;
        u32 PartyId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u16 m_usServerId;  // offset: 0x10
        u32 m_unPartyId;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
        friend class ::sQuestManagerExt;
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
        CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataPartyMemberMinimum>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataPartyMemberMinimum>& MemberMinimum() const;
        MtTypedArray<CDataPartyMemberMinimum>& MemberMinimum();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataPartyMemberMinimum> m_MemberMinimum;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_NTC();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_REFUSE_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_REFUSE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_INVITE_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_INVITE_RES();
        s32 WritePacket(CPacket*, s32, u16, u16, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u16 TimeoutSec() const;
        u16 ServerId() const;
        u32 PartyId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u16 m_usTimeoutSec;  // offset: 0x10
        u16 m_usServerId;  // offset: 0x12
        u32 m_unPartyId;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_JOIN_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_JOIN_RES();
        s32 WritePacket(CPacket*, s32, u8, u64, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 MemberIndex() const;
        u64 ContentNumber() const;
        u32 PartyId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucMemberIndex;  // offset: 0x10
        u64 m_ullContentNumber;  // offset: 0x18
        u32 m_unPartyId;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x24
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_LEAVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_LEAVE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_MEMBER_KICK_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_MEMBER_KICK_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_MEMBER_SET_VALUE_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_MEMBER_SET_VALUE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE();
        s32 WritePacket(CPacket*, u32, u8, u8, u8, u8, u8, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        u8 RandomRewardNum() const;
        u8 ChargeRewardNum() const;
        u8 ProgressBonusNum() const;
        u8 IsRepeatReward() const;
        u8 IsUndiscoverReward() const;
        u8 IsHelpReward() const;
        u8 IsPartyBonus() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        u8 m_ucRandomRewardNum;  // offset: 0x10
        u8 m_ucChargeRewardNum;  // offset: 0x11
        u8 m_ucProgressBonusNum;  // offset: 0x12
        u8 m_ucIsRepeatReward;  // offset: 0x13
        u8 m_ucIsUndiscoverReward;  // offset: 0x14
        u8 m_ucIsHelpReward;  // offset: 0x15
        u8 m_ucIsPartyBonus;  // offset: 0x16
        bool m_bIsReceived;  // offset: 0x17
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE();
        s32 WritePacket(CPacket*, u32, const CPartyQuestProgressInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 ProgressCharacterId() const;
        const CPartyQuestProgressInfo& PartyQuestProgressInfo() const;
        CPartyQuestProgressInfo& PartyQuestProgressInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unProgressCharacterId;  // offset: 0xc
        CPartyQuestProgressInfo m_PartyQuestProgressInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x98
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PARTY_WARP_RES : public ::CPacketDataBase
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
        CPacket_S2C_PARTY_WARP_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_ABILITY_SET_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_ABILITY_SET_NTC();
        s32 WritePacket(CPacket*, u32, const CContextAcquirementData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnId() const;
        const CContextAcquirementData& AbilityData() const;
        CContextAcquirementData& AbilityData();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnId;  // offset: 0xc
        CContextAcquirementData m_AbilityData;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_CUSTOM_SKILL_SET_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_CUSTOM_SKILL_SET_NTC();
        s32 WritePacket(CPacket*, u32, const CContextAcquirementData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnId() const;
        const CContextAcquirementData& CustomSkillData() const;
        CContextAcquirementData& CustomSkillData();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnId;  // offset: 0xc
        CContextAcquirementData m_CustomSkillData;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_EXPEDITION_CANCEL_SALLY_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_EXPEDITION_CANCEL_SALLY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_EXPEDITION_CHANGE_GOLDEN_SALLY_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_EXPEDITION_CHANGE_GOLDEN_SALLY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_EXPEDITION_CHARGE_SALLY_COUNT_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_EXPEDITION_CHARGE_SALLY_COUNT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES();
        s32 WritePacket(CPacket*, s32, const CAreaSpotSet&, b8, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CAreaSpotSet& SallySpotInfo() const;
        CAreaSpotSet& SallySpotInfo();
        b8 IsHotSpot() const;
        u8 SallyType() const;
        u8 SallyCount() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CAreaSpotSet m_SallySpotInfo;  // offset: 0x10
        b8 m_bIsHotSpot;  // offset: 0x20
        u8 m_ucSallyType;  // offset: 0x21
        u8 m_ucSallyCount;  // offset: 0x22
        bool m_bIsReceived;  // offset: 0x23
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_INFO_RES();
        s32 WritePacket(CPacket*, s32, u8, const MtTypedArray<CDataCommonU32>&, const MtTypedArray<CDataAreaSpotSet>&, const MtTypedArray<CDataCommonU32>&, const MtTypedArray<CDataPawnExpeditionClanSallySpotInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 SallyCount() const;
        const MtTypedArray<CDataCommonU32>& AreaIdList() const;
        MtTypedArray<CDataCommonU32>& AreaIdList();
        const MtTypedArray<CDataAreaSpotSet>& HotSpotInfoList() const;
        MtTypedArray<CDataAreaSpotSet>& HotSpotInfoList();
        const MtTypedArray<CDataCommonU32>& ActiveBuffLineupList() const;
        MtTypedArray<CDataCommonU32>& ActiveBuffLineupList();
        const MtTypedArray<CDataPawnExpeditionClanSallySpotInfo>& ClanSallySpotInfoList() const;
        MtTypedArray<CDataPawnExpeditionClanSallySpotInfo>& ClanSallySpotInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucSallyCount;  // offset: 0x10
        MtTypedArray<CDataCommonU32> m_AreaIdList;  // offset: 0x18
        MtTypedArray<CDataAreaSpotSet> m_HotSpotInfoList;  // offset: 0x38
        MtTypedArray<CDataCommonU32> m_ActiveBuffLineupList;  // offset: 0x58
        MtTypedArray<CDataPawnExpeditionClanSallySpotInfo> m_ClanSallySpotInfoList;  // offset: 0x78
        bool m_bIsReceived;  // offset: 0x98
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES();
        s32 WritePacket(CPacket*, s32, const CAreaSpotSet&, u8, const CBattleResultInfo&, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CAreaSpotSet& SallySpotInfo() const;
        CAreaSpotSet& SallySpotInfo();
        u8 SearchSpotType() const;
        const CBattleResultInfo& BattleResult() const;
        CBattleResultInfo& BattleResult();
        b8 IsGoldenSally() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CAreaSpotSet m_SallySpotInfo;  // offset: 0x10
        u8 m_ucSearchSpotType;  // offset: 0x20
        CBattleResultInfo m_BattleResult;  // offset: 0x28
        b8 m_bIsGoldenSally;  // offset: 0x40
        bool m_bIsReceived;  // offset: 0x41
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_EXPEDITION_SALLY_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_EXPEDITION_SALLY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_GOLDEN_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_GOLDEN_REVIVE_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnId() const;
        u32 GP() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnId;  // offset: 0x10
        u32 m_unGP;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_JOB_LEVEL_UP_MEMBER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_JOB_LEVEL_UP_MEMBER_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, u8, u32, const CCharacterLevelParam&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        u32 PawnID() const;
        u8 Job() const;
        u32 Level() const;
        const CCharacterLevelParam& CharacterLevelParam() const;
        CCharacterLevelParam& CharacterLevelParam();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucJob;  // offset: 0x14
        u32 m_unLevel;  // offset: 0x18
        CCharacterLevelParam m_CharacterLevelParam;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_JOB_LEVEL_UP_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_JOB_LEVEL_UP_NOTICE();
        s32 WritePacket(CPacket*, u32, u8, u32, u32, u32, const CCharacterLevelParam&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnID() const;
        u8 Job() const;
        u32 Level() const;
        u32 AddJobPoint() const;
        u32 TotalJobPoint() const;
        const CCharacterLevelParam& CharacterLevelParam() const;
        CCharacterLevelParam& CharacterLevelParam();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnID;  // offset: 0xc
        u8 m_ucJob;  // offset: 0x10
        u32 m_unLevel;  // offset: 0x14
        u32 m_unAddJobPoint;  // offset: 0x18
        u32 m_unTotalJobPoint;  // offset: 0x1c
        CCharacterLevelParam m_CharacterLevelParam;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_LIKABILITY_UP_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_LIKABILITY_UP_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_LOST_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_LOST_NOTICE();
        s32 WritePacket(CPacket*, u32, const char*, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnID() const;
        const char* PawnName() const;
        b8 IsLost() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnID;  // offset: 0xc
        MtString m_wstrPawnName;  // offset: 0x10
        b8 m_bIsLost;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x19
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_LOST_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_LOST_RES();
        s32 WritePacket(CPacket*, s32, u32, const char*, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const char* PawnName() const;
        b8 IsLost() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        MtString m_wstrPawnName;  // offset: 0x18
        b8 m_bIsLost;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x21
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_NORMAL_SKILL_LEARN_NTC : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_NORMAL_SKILL_LEARN_NTC();
        s32 WritePacket(CPacket*, u32, const CContextNormalSkillData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnId() const;
        const CContextNormalSkillData& NormalSkillData() const;
        CContextNormalSkillData& NormalSkillData();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnId;  // offset: 0xc
        CContextNormalSkillData m_NormalSkillData;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_POINT_REVIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_POINT_REVIVE_RES();
        s32 WritePacket(CPacket*, s32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnId() const;
        u8 RevivePoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnId;  // offset: 0x10
        u8 m_ucRevivePoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x15
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PAWN_REVIVE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PAWN_REVIVE_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PING_RES : public ::CPacketDataBase
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
        CPacket_S2C_PING_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_ADD_TIMER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_ADD_TIMER_NOTICE();
        s32 WritePacket(CPacket*, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u64 PlayEndDateTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u64 m_ullPlayEndDateTime;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_END_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_END_NOTICE();
        s32 WritePacket(CPacket*, const CContentsPlayEnd&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CContentsPlayEnd& ContentsPlayEnd() const;
        CContentsPlayEnd& ContentsPlayEnd();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CContentsPlayEnd m_ContentsPlayEnd;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x48
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_END_RES : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_END_RES();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_ENTRY_CANCEL_RES : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_ENTRY_CANCEL_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_ENTRY_RES : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_ENTRY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_FORCE_INTERRUPT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_FORCE_INTERRUPT_NOTICE();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_INTERRUPT_ANSWER_RES : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_INTERRUPT_ANSWER_RES();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_INTERRUPT_RES : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_INTERRUPT_RES();
        s32 WritePacket(CPacket*, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        u8 DeadlineSec() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        u8 m_ucDeadlineSec;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_INTERRUPT_RESULT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_INTERRUPT_RESULT_NOTICE();
        s32 WritePacket(CPacket*, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        b8 IsInterrupt() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        b8 m_bIsInterrupt;  // offset: 0xa
        bool m_bIsReceived;  // offset: 0xb
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_RESTART_TIMER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_RESTART_TIMER_NOTICE();
        s32 WritePacket(CPacket*, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u64 PlayEndDateTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u64 m_ullPlayEndDateTime;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_START_RES : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_START_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_START_TIMER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_START_TIMER_NOTICE();
        s32 WritePacket(CPacket*, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u64 PlayEndDateTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u64 m_ullPlayEndDateTime;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_START_TIMER_RES : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_START_TIMER_RES();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_STOP_TIMER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_STOP_TIMER_NOTICE();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PLAY_TIMEUP_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_PLAY_TIMEUP_NOTICE();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES();
        s32 WritePacket(CPacket*, s32, const CPartnerPawnData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CPartnerPawnData& PartnerInfo() const;
        CPartnerPawnData& PartnerInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CPartnerPawnData m_PartnerInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_CANCEL_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_CANCEL_NOTICE();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        u32 QuestId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        u32 m_unQuestId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_CANCEL_RES : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_CANCEL_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 QuestScheduleId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_COMPLETE_FLAG_CLEAR_RES : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_COMPLETE_FLAG_CLEAR_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 QuestScheduleId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_COMPLETE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_COMPLETE_NOTICE();
        s32 WritePacket(CPacket*, u32, u8, u8, u8, u8, u8, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        u8 RandomRewardNum() const;
        u8 ChargeRewardNum() const;
        u8 ProgressBonusNum() const;
        u8 IsRepeatReward() const;
        u8 IsUndiscoverReward() const;
        u8 IsHelpReward() const;
        u8 IsPartyBonus() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        u8 m_ucRandomRewardNum;  // offset: 0x10
        u8 m_ucChargeRewardNum;  // offset: 0x11
        u8 m_ucProgressBonusNum;  // offset: 0x12
        u8 m_ucIsRepeatReward;  // offset: 0x13
        u8 m_ucIsUndiscoverReward;  // offset: 0x14
        u8 m_ucIsHelpReward;  // offset: 0x15
        u8 m_ucIsPartyBonus;  // offset: 0x16
        bool m_bIsReceived;  // offset: 0x17
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_ENABLE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_ENABLE_NOTICE();
        s32 WritePacket(CPacket*, u32, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        b8 IsEnable() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        b8 m_bIsEnable;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_MASTER_DATA_RELOAD_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_MASTER_DATA_RELOAD_NOTICE();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_ORDER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_ORDER_NOTICE();
        s32 WritePacket(CPacket*, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        u32 QuestId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        u32 m_unQuestId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_ORDER_RES : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_ORDER_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataQuestProcessState>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataQuestProcessState>& QuestProcessStateList() const;
        MtTypedArray<CDataQuestProcessState>& QuestProcessStateList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataQuestProcessState> m_QuestProcessStateList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_PHASE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_PHASE_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, const MtTypedArray<CDataQuestPhaseEvent>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 GroupId() const;
        u32 PhaseId() const;
        const MtTypedArray<CDataQuestPhaseEvent>& EventList() const;
        MtTypedArray<CDataQuestPhaseEvent>& EventList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unGroupId;  // offset: 0xc
        u32 m_unPhaseId;  // offset: 0x10
        MtTypedArray<CDataQuestPhaseEvent> m_EventList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_PROGRESS_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_PROGRESS_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, const MtTypedArray<CDataQuestProcessState>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 ProgressCharacterId() const;
        u32 QuestScheduleId() const;
        const MtTypedArray<CDataQuestProcessState>& QuestProcessStateList() const;
        MtTypedArray<CDataQuestProcessState>& QuestProcessStateList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unProgressCharacterId;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        MtTypedArray<CDataQuestProcessState> m_QuestProcessStateList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_PROGRESS_RES : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_PROGRESS_RES();
        s32 WritePacket(CPacket*, s32, u8, u32, const MtTypedArray<CDataQuestProcessState>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 QuestProgressResult() const;
        u32 QuestScheduleId() const;
        const MtTypedArray<CDataQuestProcessState>& QuestProcessStateList() const;
        MtTypedArray<CDataQuestProcessState>& QuestProcessStateList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucQuestProgressResult;  // offset: 0x10
        u32 m_unQuestScheduleId;  // offset: 0x14
        MtTypedArray<CDataQuestProcessState> m_QuestProcessStateList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_PROGRESS_WORK_SAVE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_PROGRESS_WORK_SAVE_NOTICE();
        s32 WritePacket(CPacket*, u32, u16, u16, u16, const MtTypedArray<CDataQuestProgressWork>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        u16 ProcessNo() const;
        u16 SequenceNo() const;
        u16 BlockNo() const;
        const MtTypedArray<CDataQuestProgressWork>& WorkList() const;
        MtTypedArray<CDataQuestProgressWork>& WorkList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        u16 m_usProcessNo;  // offset: 0x10
        u16 m_usSequenceNo;  // offset: 0x12
        u16 m_usBlockNo;  // offset: 0x14
        MtTypedArray<CDataQuestProgressWork> m_WorkList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUEST_TIMER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_QUEST_TIMER_NOTICE();
        s32 WritePacket(CPacket*, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        u8 TimerNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        u8 m_ucTimerNo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_CANCEL_NTC : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_CANCEL_NTC();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_ENTRY_NTC : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_ENTRY_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_ENTRY_RES : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_ENTRY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_READY_NTC : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_READY_NTC();
        s32 WritePacket(CPacket*, u32, u32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 MaxMember() const;
        u32 PawnNum() const;
        u16 TimeoutSec() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unMaxMember;  // offset: 0xc
        u32 m_unPawnNum;  // offset: 0x10
        u16 m_usTimeoutSec;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x16
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_REGISTER_NTC : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_REGISTER_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PartyId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPartyId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_NTC : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 QuestScheduleId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unQuestScheduleId;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_RES : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 QuestScheduleId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_REGISTER_RES : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_REGISTER_RES();
        s32 WritePacket(CPacket*, s32, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u16 TimeoutSec() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u16 m_usTimeoutSec;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x12
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_QUICK_PARTY_UNREADY_NTC : public ::CPacketDataBase
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
        CPacket_S2C_QUICK_PARTY_UNREADY_NTC();
        s32 WritePacket(CPacket*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        bool m_bIsReceived;  // offset: 0xa
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RAID_BOSS_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_RAID_BOSS_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataRaidBossNoticeData>&, const MtTypedArray<CDataQuestContentsSituationInfoDetail>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataRaidBossNoticeData>& RaidBossNoticeDataList() const;
        MtTypedArray<CDataRaidBossNoticeData>& RaidBossNoticeDataList();
        const MtTypedArray<CDataQuestContentsSituationInfoDetail>& QuestContentsSituationInfoDetailList() const;
        MtTypedArray<CDataQuestContentsSituationInfoDetail>& QuestContentsSituationInfoDetailList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataRaidBossNoticeData> m_RaidBossNoticeDataList;  // offset: 0x10
        MtTypedArray<CDataQuestContentsSituationInfoDetail> m_QuestContentsSituationInfoDetailList;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RAID_BOSS_POINT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_RAID_BOSS_POINT_NOTICE();
        s32 WritePacket(CPacket*, u32, const CQuestPointDetail&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CycleContentsScheduleId() const;
        const CQuestPointDetail& QuestPointDetail() const;
        CQuestPointDetail& QuestPointDetail();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCycleContentsScheduleId;  // offset: 0xc
        CQuestPointDetail m_QuestPointDetail;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x98
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 StageID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unStageID;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RANKING_BOARD_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_RANKING_BOARD_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataRankingBoard>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataRankingBoard>& RankingBoardList() const;
        MtTypedArray<CDataRankingBoard>& RankingBoardList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataRankingBoard> m_RankingBoardList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES : public ::CPacketDataBase
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
        CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataRankingData>&, s64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataRankingData>& RankingData() const;
        MtTypedArray<CDataRankingData>& RankingData();
        s64 Modified() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataRankingData> m_RankingData;  // offset: 0x10
        s64 m_llModified;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES : public ::CPacketDataBase
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
        CPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataRankingData>&, s64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Rank() const;
        const MtTypedArray<CDataRankingData>& RankingData() const;
        MtTypedArray<CDataRankingData>& RankingData();
        s64 Modified() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unRank;  // offset: 0x10
        MtTypedArray<CDataRankingData> m_RankingData;  // offset: 0x18
        s64 m_llModified;  // offset: 0x38
        bool m_bIsReceived;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RANKING_DATA_RANK_RES : public ::CPacketDataBase
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
        CPacket_S2C_RANKING_DATA_RANK_RES();
        s32 WritePacket(CPacket*, s32, u32, const MtTypedArray<CDataRankingData>&, s64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Rank() const;
        const MtTypedArray<CDataRankingData>& RankingData() const;
        MtTypedArray<CDataRankingData>& RankingData();
        s64 Modified() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unRank;  // offset: 0x10
        MtTypedArray<CDataRankingData> m_RankingData;  // offset: 0x18
        s64 m_llModified;  // offset: 0x38
        bool m_bIsReceived;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_REGISTER_FAVORITE_FRIEND_RES : public ::CPacketDataBase
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
        CPacket_S2C_REGISTER_FAVORITE_FRIEND_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_REGISTER_FAVORITE_WARP_RES : public ::CPacketDataBase
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
        CPacket_S2C_REGISTER_FAVORITE_WARP_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 SlotNo() const;
        u32 WarpPointID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unSlotNo;  // offset: 0x10
        u32 m_unWarpPointID;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_REGISTER_PRESET_ABILITY_RES : public ::CPacketDataBase
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
        CPacket_S2C_REGISTER_PRESET_ABILITY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RELEASE_JOB_ORB_ELEMENT_RES : public ::CPacketDataBase
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
        CPacket_S2C_RELEASE_JOB_ORB_ELEMENT_RES();
        s32 WritePacket(CPacket*, s32, u8, u32, const CJobOrbTreeStatus&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 JobID() const;
        u32 RestOrb() const;
        const CJobOrbTreeStatus& TreeStatus() const;
        CJobOrbTreeStatus& TreeStatus();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJobID;  // offset: 0x10
        u32 m_unRestOrb;  // offset: 0x14
        CJobOrbTreeStatus m_TreeStatus;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RELEASE_ORB_ELEMENT_RES : public ::CPacketDataBase
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
        CPacket_S2C_RELEASE_ORB_ELEMENT_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 RestOrb() const;
        u8 GainParamType() const;
        u32 GainParamValue() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unRestOrb;  // offset: 0x10
        u8 m_ucGainParamType;  // offset: 0x14
        u32 m_unGainParamValue;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RELEASE_PAWN_ORB_ELEMENT_RES : public ::CPacketDataBase
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
        CPacket_S2C_RELEASE_PAWN_ORB_ELEMENT_RES();
        s32 WritePacket(CPacket*, s32, u32, u32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u32 RestOrb() const;
        u8 GainParamType() const;
        u32 GainParamValue() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u32 m_unRestOrb;  // offset: 0x14
        u8 m_ucGainParamType;  // offset: 0x18
        u32 m_unGainParamValue;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RELEASE_SET_QUEST_AREA_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_RELEASE_SET_QUEST_AREA_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataCommonU32>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataCommonU32>& AreaIdList() const;
        MtTypedArray<CDataCommonU32>& AreaIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataCommonU32> m_AreaIdList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RENTAL_PAWN_LOST_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_RENTAL_PAWN_LOST_NOTICE();
        s32 WritePacket(CPacket*, u32, const char*, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnID() const;
        const char* PawnName() const;
        u8 AdventureCount() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnID;  // offset: 0xc
        MtString m_wstrPawnName;  // offset: 0x10
        u8 m_ucAdventureCount;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x19
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RENTAL_PAWN_LOST_RES : public ::CPacketDataBase
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
        CPacket_S2C_RENTAL_PAWN_LOST_RES();
        s32 WritePacket(CPacket*, s32, u32, const char*, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        const char* PawnName() const;
        u8 AdventureCount() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        MtString m_wstrPawnName;  // offset: 0x18
        u8 m_ucAdventureCount;  // offset: 0x20
        bool m_bIsReceived;  // offset: 0x21
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RENT_REGISTERED_PAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_RENT_REGISTERED_PAWN_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 TotalRim() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unTotalRim;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES : public ::CPacketDataBase
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
        CPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES();
        s32 WritePacket(CPacket*, s32, u8, const MtTypedArray<CDataReleaseElement>&, const MtTypedArray<CDataCommonU32>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 JobID() const;
        const MtTypedArray<CDataReleaseElement>& ReleaseElementList() const;
        MtTypedArray<CDataReleaseElement>& ReleaseElementList();
        const MtTypedArray<CDataCommonU32>& NewOrderIdList() const;
        MtTypedArray<CDataCommonU32>& NewOrderIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJobID;  // offset: 0x10
        MtTypedArray<CDataReleaseElement> m_ReleaseElementList;  // offset: 0x18
        MtTypedArray<CDataCommonU32> m_NewOrderIdList;  // offset: 0x38
        bool m_bIsReceived;  // offset: 0x58
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RESET_JOBPOINT_RES : public ::CPacketDataBase
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
        CPacket_S2C_RESET_JOBPOINT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_RETURN_RENTED_PAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_RETURN_RENTED_PAWN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_REWARD_BOX_LIST_NUM_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_REWARD_BOX_LIST_NUM_NOTICE();
        s32 WritePacket(CPacket*, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 ListNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucListNum;  // offset: 0xa
        bool m_bIsReceived;  // offset: 0xb
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SELL_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_SELL_ITEM_RES();
        s32 WritePacket(CPacket*, s32, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 PointType() const;
        u32 Point() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucPointType;  // offset: 0x10
        u32 m_unPoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataOrderConditionInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataOrderConditionInfo>& OrderConditionInfoList() const;
        MtTypedArray<CDataOrderConditionInfo>& OrderConditionInfoList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataOrderConditionInfo> m_OrderConditionInfoList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataCommonU32>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataCommonU32>& QuestScheduleIdList() const;
        MtTypedArray<CDataCommonU32>& QuestScheduleIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataCommonU32> m_QuestScheduleIdList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SEND_TELL_MSG_RES : public ::CPacketDataBase
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
        CPacket_S2C_SEND_TELL_MSG_RES();
        s32 WritePacket(CPacket*, s32, const CCommunityCharacterBaseInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CCommunityCharacterBaseInfo& CharacterBaseInfo() const;
        CCommunityCharacterBaseInfo& CharacterBaseInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CCommunityCharacterBaseInfo m_CharacterBaseInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SERVER_UI_COMMAND_RES : public ::CPacketDataBase
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
        CPacket_S2C_SERVER_UI_COMMAND_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_ABILITY_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_ABILITY_RES();
        s32 WritePacket(CPacket*, s32, u8, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 SlotNo() const;
        u32 AbilityID() const;
        u8 AbilityLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucSlotNo;  // offset: 0x10
        u32 m_unAbilityID;  // offset: 0x14
        u8 m_ucAbilityLv;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x19
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_ARISEN_PROFILE_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_ARISEN_PROFILE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_CHARACTER_BIN_SAVEDATA_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_CHARACTER_BIN_SAVEDATA_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_COMMUNICATION_SHORTCUT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_COMMUNICATION_SHORTCUT_LIST_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_CONTEXT_BASE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_SET_CONTEXT_BASE_NOTICE();
        s32 WritePacket(CPacket*, const CContextSetBase&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CContextSetBase& ContextBase() const;
        CContextSetBase& ContextBase();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CContextSetBase m_ContextBase;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_FAVORITE_PAWN_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_FAVORITE_PAWN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_ITEM_SORTDATA_BIN_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_ITEM_SORTDATA_BIN_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_MATCHING_PROFILE_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_MATCHING_PROFILE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_MESSAGE_SET_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_MESSAGE_SET_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_OBJECTIVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_OBJECTIVE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_OFF_ABILITY_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_OFF_ABILITY_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 SlotNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucSlotNo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_OFF_PAWN_ABILITY_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_OFF_PAWN_ABILITY_RES();
        s32 WritePacket(CPacket*, s32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u8 SlotNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucSlotNo;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x15
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_OFF_PAWN_SKILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_OFF_PAWN_SKILL_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u8 Job() const;
        u8 SlotNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucJob;  // offset: 0x14
        u8 m_ucSlotNo;  // offset: 0x15
        bool m_bIsReceived;  // offset: 0x16
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_OFF_SKILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_OFF_SKILL_RES();
        s32 WritePacket(CPacket*, s32, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 Job() const;
        u8 SlotNo() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJob;  // offset: 0x10
        u8 m_ucSlotNo;  // offset: 0x11
        bool m_bIsReceived;  // offset: 0x12
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_NOTICE();
        s32 WritePacket(CPacket*, u32, const COmData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 StageId() const;
        const COmData& Value() const;
        COmData& Value();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unStageId;  // offset: 0xc
        COmData m_Value;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_RES();
        s32 WritePacket(CPacket*, s32, u32, const COmData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 StageId() const;
        const COmData& Value() const;
        COmData& Value();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unStageId;  // offset: 0x10
        COmData m_Value;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_ONLINE_STATUS_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_ONLINE_STATUS_RES();
        s32 WritePacket(CPacket*, s32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 StatusID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucStatusID;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_PAWN_ABILITY_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_PAWN_ABILITY_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u8 SlotNo() const;
        u32 AbilityID() const;
        u8 AbilityLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucSlotNo;  // offset: 0x14
        u32 m_unAbilityID;  // offset: 0x18
        u8 m_ucAbilityLv;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x1d
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_PAWN_PROFILE_COMMENT_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_PAWN_PROFILE_COMMENT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_PAWN_PROFILE_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_PAWN_PROFILE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_PAWN_SKILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_PAWN_SKILL_RES();
        s32 WritePacket(CPacket*, s32, u32, u8, u8, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u8 Job() const;
        u8 SlotNo() const;
        u32 SkillID() const;
        u8 SkillLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucJob;  // offset: 0x14
        u8 m_ucSlotNo;  // offset: 0x15
        u32 m_unSkillID;  // offset: 0x18
        u8 m_ucSkillLv;  // offset: 0x1c
        bool m_bIsReceived;  // offset: 0x1d
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_PRESET_ABILITY_NAME_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_PRESET_ABILITY_NAME_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_PRIORITY_QUEST_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_PRIORITY_QUEST_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 QuestScheduleId() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unQuestScheduleId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_QUEST_UNRELEASED_AREA_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_SET_QUEST_UNRELEASED_AREA_NOTICE();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataCommonU32>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataCommonU32>& AreaIdList() const;
        MtTypedArray<CDataCommonU32>& AreaIdList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataCommonU32> m_AreaIdList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_RAID_BOSS_INFO_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_RAID_BOSS_INFO_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 RaidBossID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unRaidBossID;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_SHORTCUT_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_SHORTCUT_LIST_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SET_SKILL_RES : public ::CPacketDataBase
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
        CPacket_S2C_SET_SKILL_RES();
        s32 WritePacket(CPacket*, s32, u8, u8, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 Job() const;
        u8 SlotNo() const;
        u32 SkillID() const;
        u8 SkillLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucJob;  // offset: 0x10
        u8 m_ucSlotNo;  // offset: 0x11
        u32 m_unSkillID;  // offset: 0x14
        u8 m_ucSkillLv;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x19
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_STAMP_BONUS_ADD_TOTAL_NUM_RES : public ::CPacketDataBase
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
        CPacket_S2C_STAMP_BONUS_ADD_TOTAL_NUM_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_STAMP_BONUS_CHECK_RES : public ::CPacketDataBase
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
        CPacket_S2C_STAMP_BONUS_CHECK_RES();
        s32 WritePacket(CPacket*, s32, u16, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u16 TotalStampNum() const;
        u8 isRecieveBonusDaily() const;
        u8 isRecieveBonusTotal() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u16 m_usTotalStampNum;  // offset: 0x10
        u8 m_ucisRecieveBonusDaily;  // offset: 0x12
        u8 m_ucisRecieveBonusTotal;  // offset: 0x13
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_STAMP_BONUS_GET_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_STAMP_BONUS_GET_LIST_RES();
        s32 WritePacket(CPacket*, s32, u16, const MtTypedArray<CDataStampBonusDaily>&, const MtTypedArray<CDataStampBonusTotal>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u16 TotalStampNum() const;
        const MtTypedArray<CDataStampBonusDaily>& StampBonusDaily() const;
        MtTypedArray<CDataStampBonusDaily>& StampBonusDaily();
        const MtTypedArray<CDataStampBonusTotal>& StampBonusTotal() const;
        MtTypedArray<CDataStampBonusTotal>& StampBonusTotal();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u16 m_usTotalStampNum;  // offset: 0x10
        MtTypedArray<CDataStampBonusDaily> m_StampBonusDaily;  // offset: 0x18
        MtTypedArray<CDataStampBonusTotal> m_StampBonusTotal;  // offset: 0x38
        bool m_bIsReceived;  // offset: 0x58
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_STAMP_BONUS_RECIEVE_RES : public ::CPacketDataBase
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
        CPacket_S2C_STAMP_BONUS_RECIEVE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_START_CRAFT_RES : public ::CPacketDataBase
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
        CPacket_S2C_START_CRAFT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_START_DEATH_PENALTY_OTHER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_START_DEATH_PENALTY_OTHER_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_START_LANTERN_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_START_LANTERN_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 RemainTime() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unRemainTime;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_START_LANTERN_OTHER_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_START_LANTERN_OTHER_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SUPPORT_POINT_GET_RATE_RES : public ::CPacketDataBase
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
        CPacket_S2C_SUPPORT_POINT_GET_RATE_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataSupportRate>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataSupportRate>& SupportRate() const;
        MtTypedArray<CDataSupportRate>& SupportRate();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataSupportRate> m_SupportRate;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SUPPORT_POINT_USE_RES : public ::CPacketDataBase
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
        CPacket_S2C_SUPPORT_POINT_USE_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataUseSupportPointRes>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataUseSupportPointRes>& UsePoint() const;
        MtTypedArray<CDataUseSupportPointRes>& UsePoint();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataUseSupportPointRes> m_UsePoint;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SYSTEM_MAIL_DELETE_RES : public ::CPacketDataBase
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
        CPacket_S2C_SYSTEM_MAIL_DELETE_RES();
        s32 WritePacket(CPacket*, s32, u64);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 Id() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullId;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SYSTEM_MAIL_GET_LIST_FOOT_RES : public ::CPacketDataBase
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
        CPacket_S2C_SYSTEM_MAIL_GET_LIST_FOOT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SYSTEM_MAIL_GET_LIST_HEAD_RES : public ::CPacketDataBase
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
        CPacket_S2C_SYSTEM_MAIL_GET_LIST_HEAD_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 Num() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unNum;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES : public ::CPacketDataBase
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
        CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES();
        s32 WritePacket(CPacket*, s32, u64, const CMailTextInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u64 Id() const;
        const CMailTextInfo& MailTextInfo() const;
        CMailTextInfo& MailTextInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u64 m_ullId;  // offset: 0x10
        CMailTextInfo m_MailTextInfo;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0xb0
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_SYSTEM_MAIL_SEND_NTC : public ::CPacketDataBase
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
        CPacket_S2C_SYSTEM_MAIL_SEND_NTC();
        s32 WritePacket(CPacket*, const CMailInfo&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CMailInfo& MailInfo() const;
        CMailInfo& MailInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CMailInfo m_MailInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_TIME_GAIN_QUEST_PLAY_START_NOTICE : public ::CPacketDataBase
    {
        friend class ::cNetGameServer;
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
        CPacket_S2C_TIME_GAIN_QUEST_PLAY_START_NOTICE();
        s32 WritePacket(CPacket*, const CTimeGainQuestPlayStartData&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CTimeGainQuestPlayStartData& TimeGainQuestPlayStartData() const;
        CTimeGainQuestPlayStartData& TimeGainQuestPlayStartData();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CTimeGainQuestPlayStartData m_TimeGainQuestPlayStartData;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0xb8
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_TIME_UPDATE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_TIME_UPDATE_NOTICE();
        s32 WritePacket(CPacket*, const CGameTime&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CGameTime& GameTime() const;
        CGameTime& GameTime();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CGameTime m_GameTime;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES : public ::CPacketDataBase
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
        CPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataTraningRoomEnemyHeader>&, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataTraningRoomEnemyHeader>& InfoList() const;
        MtTypedArray<CDataTraningRoomEnemyHeader>& InfoList();
        u32 MaxLv() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataTraningRoomEnemyHeader> m_InfoList;  // offset: 0x10
        u32 m_unMaxLv;  // offset: 0x30
        bool m_bIsReceived;  // offset: 0x34
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_TRANING_ROOM_SET_ENEMY_RES : public ::CPacketDataBase
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
        CPacket_S2C_TRANING_ROOM_SET_ENEMY_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_ARISEN_PROFILE_SHARE_RANGE_RES : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_ARISEN_PROFILE_SHARE_RANGE_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_CHARACTER_EDIT_PARAM_RES : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_CHARACTER_EDIT_PARAM_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 GP() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unGP;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_CHARACTER_JOB_POINT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_CHARACTER_JOB_POINT_NOTICE();
        s32 WritePacket(CPacket*, u8, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 Job() const;
        u32 AddJobPoint() const;
        u32 ExtraBonusPoint() const;
        u32 TotalJobPoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucJob;  // offset: 0xa
        u32 m_unAddJobPoint;  // offset: 0xc
        u32 m_unExtraBonusPoint;  // offset: 0x10
        u32 m_unTotalJobPoint;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_EQUIP_COLOR_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_EQUIP_COLOR_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, u8, u8, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterId() const;
        u32 PawnId() const;
        u8 EquipType() const;
        u8 EquipSlot() const;
        u8 Color() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterId;  // offset: 0xc
        u32 m_unPawnId;  // offset: 0x10
        u8 m_ucEquipType;  // offset: 0x14
        u8 m_ucEquipSlot;  // offset: 0x15
        u8 m_ucColor;  // offset: 0x16
        bool m_bIsReceived;  // offset: 0x17
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_EQUIP_GRADE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_EQUIP_GRADE_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, u8, u8, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterId() const;
        u32 PawnId() const;
        u8 EquipType() const;
        u8 EquipSlot() const;
        u32 ItemID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterId;  // offset: 0xc
        u32 m_unPawnId;  // offset: 0x10
        u8 m_ucEquipType;  // offset: 0x14
        u8 m_ucEquipSlot;  // offset: 0x15
        u32 m_unItemID;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_EQUIP_HIDE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_EQUIP_HIDE_NOTICE();
        s32 WritePacket(CPacket*, u32, b8, b8, b8, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        b8 HideHead() const;
        b8 HideLantern() const;
        b8 HidePawnHead() const;
        b8 HidePawnLantern() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        b8 m_bHideHead;  // offset: 0x10
        b8 m_bHideLantern;  // offset: 0x11
        b8 m_bHidePawnHead;  // offset: 0x12
        b8 m_bHidePawnLantern;  // offset: 0x13
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_EQUIP_PRESET_NAME_RES : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_EQUIP_PRESET_NAME_RES();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_HIDE_PAWN_HEAD_ARMOR_RES : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_HIDE_PAWN_HEAD_ARMOR_RES();
        s32 WritePacket(CPacket*, u32, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        b8 Hide() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        b8 m_bHide;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_HIDE_PAWN_LANTERN_RES : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_HIDE_PAWN_LANTERN_RES();
        s32 WritePacket(CPacket*, u32, b8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        b8 Hide() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        b8 m_bHide;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_MATCHING_PROFILE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_MATCHING_PROFILE_NOTICE();
        s32 WritePacket(CPacket*, const CMatchingProfile&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const CMatchingProfile& MatchingProfile() const;
        CMatchingProfile& MatchingProfile();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        CMatchingProfile m_MatchingProfile;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x48
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_PAWN_SHARE_RANGE_RES : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_PAWN_SHARE_RANGE_RES();
        s32 WritePacket(CPacket*, s32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 PawnID() const;
        u8 ShareRange() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unPawnID;  // offset: 0x10
        u8 m_ucShareRange;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x15
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_PLAY_POINT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_PLAY_POINT_NOTICE();
        s32 WritePacket(CPacket*, u8, u32, u32, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u8 Job() const;
        u32 UpdatePoint() const;
        u32 ExtraBonusPoint() const;
        u32 TotalPoint() const;
        u8 Type() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u8 m_ucJob;  // offset: 0xa
        u32 m_unUpdatePoint;  // offset: 0xc
        u32 m_unExtraBonusPoint;  // offset: 0x10
        u32 m_unTotalPoint;  // offset: 0x14
        u8 m_ucType;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x19
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_RENTAL_PAWN_ADVENTURE_COUNT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_RENTAL_PAWN_ADVENTURE_COUNT_NOTICE();
        s32 WritePacket(CPacket*, u32, const char*, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 PawnId() const;
        const char* PawnName() const;
        u8 AdventureCount() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unPawnId;  // offset: 0xc
        MtString m_wstrPawnName;  // offset: 0x10
        u8 m_ucAdventureCount;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x19
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_UPDATE_REVIVE_POINT_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_UPDATE_REVIVE_POINT_NOTICE();
        s32 WritePacket(CPacket*, u32, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterId() const;
        u8 RevivePoint() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterId;  // offset: 0xc
        u8 m_ucRevivePoint;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_USER_LIST_MAX_NUM_RES : public ::CPacketDataBase
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
        CPacket_S2C_USER_LIST_MAX_NUM_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 MaxNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unMaxNum;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_USE_BAG_ITEM_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_USE_BAG_ITEM_NOTICE();
        s32 WritePacket(CPacket*, u32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 CharacterID() const;
        u32 ItemID() const;
        u32 ItemNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unCharacterID;  // offset: 0xc
        u32 m_unItemID;  // offset: 0x10
        u32 m_unItemNum;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_USE_BAG_ITEM_RES : public ::CPacketDataBase
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
        CPacket_S2C_USE_BAG_ITEM_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_USE_JOB_ITEMS_RES : public ::CPacketDataBase
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
        CPacket_S2C_USE_JOB_ITEMS_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_WARP_RES : public ::CPacketDataBase
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
        CPacket_S2C_WARP_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 WarpPointID() const;
        u32 rim() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unWarpPointID;  // offset: 0x10
        u32 m_unrim;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_WEATHER_FORECAST_GET_RES : public ::CPacketDataBase
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
        CPacket_S2C_WEATHER_FORECAST_GET_RES();
        s32 WritePacket(CPacket*, s32, u32, u32, const MtTypedArray<CDataWeatherForecast>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 IntervalGameHour() const;
        u32 GameDayToEarthMin() const;
        const MtTypedArray<CDataWeatherForecast>& ForecastList() const;
        MtTypedArray<CDataWeatherForecast>& ForecastList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unIntervalGameHour;  // offset: 0x10
        u32 m_unGameDayToEarthMin;  // offset: 0x14
        MtTypedArray<CDataWeatherForecast> m_ForecastList;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

namespace nUserSession {
    class CPacket_S2C_WEATHER_UPDATE_NOTICE : public ::CPacketDataBase
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
        CPacket_S2C_WEATHER_UPDATE_NOTICE();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 WeatherID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unWeatherID;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nUserSession

inline nUserSession::CPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES::CPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES::CPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES::CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataAchieveRewardCommon>& nUserSession::CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES::RewardList() const {
    return this->m_RewardList;
}

inline nUserSession::CPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES::CPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataAchieveRewardCommon>& nUserSession::CPacket_S2C_ACHIEVEMENT_REWARD_RECEIVE_RES::RewardList() const {
    return this->m_RewardList;
}

inline nUserSession::CPacket_S2C_ACTIVATE_JOB_ORDER_RES::CPacket_S2C_ACTIVATE_JOB_ORDER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJobID = 0;
    this->m_ucRewardType = 0;
    this->m_unRewardNo = 0;
    this->m_ucRewardLv = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_AREA_WARP_RES::CPacket_S2C_AREA_WARP_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unRim = 0;
    this->m_nResult = 0;
    this->m_unWarpPointID = 0;
}

inline nUserSession::CPacket_S2C_BAZAAR_CANCEL_RES::CPacket_S2C_BAZAAR_CANCEL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullBazaarId = 0;
    this->m_bIsReceived = false;
}

inline s32 nUserSession::CPacket_S2C_BAZAAR_CANCEL_RES::Result() const {
    return this->m_nResult;
}

inline u64 nUserSession::CPacket_S2C_BAZAAR_CANCEL_RES::BazaarId() const {
    return this->m_ullBazaarId;
}

inline nUserSession::CPacket_S2C_BAZAAR_EXHIBIT_RES::CPacket_S2C_BAZAAR_EXHIBIT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullBazaarId = 0;
    this->m_bIsReceived = false;
}

inline s32 nUserSession::CPacket_S2C_BAZAAR_EXHIBIT_RES::Result() const {
    return this->m_nResult;
}

inline u64 nUserSession::CPacket_S2C_BAZAAR_EXHIBIT_RES::BazaarId() const {
    return this->m_ullBazaarId;
}

inline nUserSession::CPacket_S2C_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_RES::CPacket_S2C_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unAdd = 0;
    this->m_nResult = 0;
    this->m_unNum = 0;
}

inline u32 nUserSession::CPacket_S2C_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_RES::Num() const {
    return this->m_unNum;
}

inline u32 nUserSession::CPacket_S2C_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_RES::Add() const {
    return this->m_unAdd;
}

inline nUserSession::CPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES::CPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_usNum = 0;
    this->m_unLow = 0;
    this->m_unHigh = 0;
    this->m_nResult = 0;
    this->m_unItemId = 0;
}

inline u32 nUserSession::CPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES::ItemId() const {
    return this->m_unItemId;
}

inline u32 nUserSession::CPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES::Low() const {
    return this->m_unLow;
}

inline u32 nUserSession::CPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES::High() const {
    return this->m_unHigh;
}

inline nUserSession::CPacket_S2C_BAZAAR_PROCEEDS_NTC::CPacket_S2C_BAZAAR_PROCEEDS_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unItemId = 0;
    this->m_unProceeds = 0;
    this->m_ullBazaarId = 0;
}

inline nUserSession::CPacket_S2C_BAZAAR_PROCEEDS_RES::CPacket_S2C_BAZAAR_PROCEEDS_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullBazaarId = 0;
    this->m_bIsReceived = false;
}

inline s32 nUserSession::CPacket_S2C_BAZAAR_PROCEEDS_RES::Result() const {
    return this->m_nResult;
}

inline nUserSession::CPacket_S2C_BAZAAR_RECEIVE_PROCEEDS_RES::CPacket_S2C_BAZAAR_RECEIVE_PROCEEDS_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unProceeds = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_BAZAAR_RECEIVE_PROCEEDS_RES::Proceeds() const {
    return this->m_unProceeds;
}

inline nUserSession::CPacket_S2C_BAZAAR_RE_EXHIBIT_RES::CPacket_S2C_BAZAAR_RE_EXHIBIT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullBazaarId = 0;
    this->m_bIsReceived = false;
}

inline s32 nUserSession::CPacket_S2C_BAZAAR_RE_EXHIBIT_RES::Result() const {
    return this->m_nResult;
}

inline nUserSession::CPacket_S2C_BOX_GACHA_BUY_RES::CPacket_S2C_BOX_GACHA_BUY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_BOX_GACHA_DRAW_INFO_RES::CPacket_S2C_BOX_GACHA_DRAW_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_BOX_GACHA_LIST_RES::CPacket_S2C_BOX_GACHA_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_BOX_GACHA_RESET_RES::CPacket_S2C_BOX_GACHA_RESET_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_BUY_AREA_QUEST_HINT_RES::CPacket_S2C_BUY_AREA_QUEST_HINT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unUpdateGold = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_BUY_SHOP_GOODS_RES::CPacket_S2C_BUY_SHOP_GOODS_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucPointType = 0;
    this->m_unPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CANCEL_CRAFT_RES::CPacket_S2C_CANCEL_CRAFT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CANCEL_PRIORITY_QUEST_RES::CPacket_S2C_CANCEL_PRIORITY_QUEST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHANGE_CAP_TO_GP_RES::CPacket_S2C_CHANGE_CAP_TO_GP_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unGP = 0;
    this->m_unCAP = 0;
    this->m_unResult = 0;
    this->m_unChangeListID = 0;
}

inline u32 nUserSession::CPacket_S2C_CHANGE_CAP_TO_GP_RES::CAP() const {
    return this->m_unCAP;
}

inline nUserSession::CPacket_S2C_CHARACTER_GOLDEN_REVIVE_RES::CPacket_S2C_CHARACTER_GOLDEN_REVIVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unGP = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHARACTER_JOB_EXP_UP_NOTICE::CPacket_S2C_CHARACTER_JOB_EXP_UP_NOTICE() {
    this->m_usError = 0;
    this->m_ucJob = 0;
    this->m_ucType = 0;
    this->m_bIsReceived = false;
    this->m_unTotalExp = 0;
    this->m_unAddExp = 0;
    this->m_unExtraBonusExp = 0;
}

inline nUserSession::CPacket_S2C_CHARACTER_JOB_LEVEL_UP_NOTICE::CPacket_S2C_CHARACTER_JOB_LEVEL_UP_NOTICE() {
    this->m_usError = 0;
    this->m_ucJob = 0;
    this->m_unLevel = 0;
    this->m_unAddJobPoint = 0;
    this->m_unTotalJobPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHARACTER_JOB_LEVEL_UP_OTHER_NOTICE::CPacket_S2C_CHARACTER_JOB_LEVEL_UP_OTHER_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_ucJob = 0;
    this->m_unLevel = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHARACTER_PENALTY_REVIVE_RES::CPacket_S2C_CHARACTER_PENALTY_REVIVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHARACTER_POINT_REVIVE_RES::CPacket_S2C_CHARACTER_POINT_REVIVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucRevivePoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHARACTER_REVIVE_NOTICE::CPacket_S2C_CHARACTER_REVIVE_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHARACTER_SEARCH_RES::CPacket_S2C_CHARACTER_SEARCH_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHARGE_REVIVE_POINT_RES::CPacket_S2C_CHARGE_REVIVE_POINT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucRevivePoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CHECK_QUEST_DISTRIBUTION_RES::CPacket_S2C_CHECK_QUEST_DISTRIBUTION_RES() {
    this->m_usError = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsDistribution = false;
    this->m_bIsReceived = false;
}

inline const CClanFunctionInfo& nUserSession::CPacket_S2C_CLAN_BASE_GET_INFO_RES::FunctionInfo() const {
    return this->m_FunctionInfo;
}

inline const CPawnExpeditionInformation& nUserSession::CPacket_S2C_CLAN_BASE_GET_INFO_RES::PawnExpeditionInfo() const {
    return this->m_PawnExpeditionInfo;
}

inline bool nUserSession::CPacket_S2C_CLAN_BASE_GET_INFO_RES::isReceived() const {
    return this->m_bIsReceived;
}

inline nUserSession::CPacket_S2C_CLAN_BASE_RELEASE_RES::CPacket_S2C_CLAN_BASE_RELEASE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_BASE_RELEASE_STATE_UPDATE_NTC::CPacket_S2C_CLAN_BASE_RELEASE_STATE_UPDATE_NTC() {
    this->m_usError = 0;
    this->m_ucState = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_CANCEL_JOIN_NTC::CPacket_S2C_CLAN_CANCEL_JOIN_NTC() {
    this->m_usError = 0;
    this->m_nRequestId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_CANCEL_JOIN_RES::CPacket_S2C_CLAN_CANCEL_JOIN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES::CPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unClanPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_CONCIERGE_UPDATE_RES::CPacket_S2C_CLAN_CONCIERGE_UPDATE_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unClanPoint = 0;
    this->m_nResult = 0;
    this->m_unNpcId = 0;
}

inline nUserSession::CPacket_S2C_CLAN_EXPEL_MEMBER_RES::CPacket_S2C_CLAN_EXPEL_MEMBER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_GET_HISTORY_RES::CPacket_S2C_CLAN_GET_HISTORY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES::CPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_GET_MEMBER_LIST_RES::CPacket_S2C_CLAN_GET_MEMBER_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataClanMemberInfo>& nUserSession::CPacket_S2C_CLAN_GET_MEMBER_LIST_RES::MemberList() {
    return this->m_MemberList;
}

inline nUserSession::CPacket_S2C_CLAN_GET_MEMBER_NUM_RES::CPacket_S2C_CLAN_GET_MEMBER_NUM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_usMemberNum = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES::CPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_INVITE_ACCEPT_RES::CPacket_S2C_CLAN_INVITE_ACCEPT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_INVITE_RES::CPacket_S2C_CLAN_INVITE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_JOIN_NOTICE::CPacket_S2C_CLAN_JOIN_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_LEAVE_MEMBER_RES::CPacket_S2C_CLAN_LEAVE_MEMBER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_LEVEL_UP_NTC::CPacket_S2C_CLAN_LEVEL_UP_NTC() {
    this->m_usError = 0;
    this->m_unClanLV = 0;
    this->m_unNextClanPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_NEGOTIATE_MASTER_RES::CPacket_S2C_CLAN_NEGOTIATE_MASTER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unMemberID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_POINT_ADD_NTC::CPacket_S2C_CLAN_POINT_ADD_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unMoneyClanPoint = 0;
    this->m_unClanPoint = 0;
    this->m_unTotalClanPoint = 0;
}

inline nUserSession::CPacket_S2C_CLAN_QUEST_CLEAR_NTC::CPacket_S2C_CLAN_QUEST_CLEAR_NTC() {
    this->m_usError = 0;
    this->m_unQuestId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_REGISTER_JOIN_RES::CPacket_S2C_CLAN_REGISTER_JOIN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_NTC::CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_NTC() {
    this->m_usError = 0;
    this->m_unInviteId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_RES::CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unInviteID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_RES::CPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_DISAPPROVE_INVITE_NTC::CPacket_S2C_CLAN_SCOUT_ENTRY_DISAPPROVE_INVITE_NTC() {
    this->m_usError = 0;
    this->m_unInviteId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES::CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES::CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_INVITE_RES::CPacket_S2C_CLAN_SCOUT_ENTRY_INVITE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unScoutEntryID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_REGISTER_RES::CPacket_S2C_CLAN_SCOUT_ENTRY_REGISTER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES::CPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SEARCH_RES::CPacket_S2C_CLAN_SEARCH_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SETTING_UPDATE_RES::CPacket_S2C_CLAN_SETTING_UPDATE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_SET_MEMBER_RANK_NTC::CPacket_S2C_CLAN_SET_MEMBER_RANK_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unRank = 0;
    this->m_unPermission = 0;
    this->m_unClanID = 0;
    this->m_unCharacterID = 0;
}

inline nUserSession::CPacket_S2C_CLAN_SET_MEMBER_RANK_RES::CPacket_S2C_CLAN_SET_MEMBER_RANK_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unRank = 0;
    this->m_nResult = 0;
    this->m_unMemberID = 0;
}

inline const CClanShopInfo& nUserSession::CPacket_S2C_CLAN_SHOP_GET_BUFF_ITEM_LIST_RES::ShopInfo() const {
    return this->m_ShopInfo;
}

inline const CClanShopInfo& nUserSession::CPacket_S2C_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_RES::ShopInfo() const {
    return this->m_ShopInfo;
}

inline nUserSession::CPacket_S2C_CLAN_UPDATE_NTC::CPacket_S2C_CLAN_UPDATE_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLAN_UPDATE_RES::CPacket_S2C_CLAN_UPDATE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CLIENT_CHALLENGE_RES::CPacket_S2C_CLIENT_CHALLENGE_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_ucPasswordEnc[58] = 0;
    this->m_ucPasswordEnc[59] = 0;
    this->m_ucPasswordEnc[60] = 0;
    this->m_ucPasswordEnc[61] = 0;
    this->m_ucPasswordEnc[50] = 0;
    this->m_ucPasswordEnc[51] = 0;
    this->m_ucPasswordEnc[52] = 0;
    this->m_ucPasswordEnc[53] = 0;
    this->m_ucPasswordEnc[54] = 0;
    this->m_ucPasswordEnc[55] = 0;
    this->m_ucPasswordEnc[56] = 0;
    this->m_ucPasswordEnc[57] = 0;
    this->m_ucPasswordEnc[42] = 0;
    this->m_ucPasswordEnc[43] = 0;
    this->m_ucPasswordEnc[44] = 0;
    this->m_ucPasswordEnc[45] = 0;
    this->m_ucPasswordEnc[46] = 0;
    this->m_ucPasswordEnc[47] = 0;
    this->m_ucPasswordEnc[48] = 0;
    this->m_ucPasswordEnc[49] = 0;
    this->m_ucPasswordEnc[34] = 0;
    this->m_ucPasswordEnc[35] = 0;
    this->m_ucPasswordEnc[36] = 0;
    this->m_ucPasswordEnc[37] = 0;
    this->m_ucPasswordEnc[38] = 0;
    this->m_ucPasswordEnc[39] = 0;
    this->m_ucPasswordEnc[40] = 0;
    this->m_ucPasswordEnc[41] = 0;
    this->m_ucPasswordEnc[26] = 0;
    this->m_ucPasswordEnc[27] = 0;
    this->m_ucPasswordEnc[28] = 0;
    this->m_ucPasswordEnc[29] = 0;
    this->m_ucPasswordEnc[30] = 0;
    this->m_ucPasswordEnc[31] = 0;
    this->m_ucPasswordEnc[32] = 0;
    this->m_ucPasswordEnc[33] = 0;
    this->m_ucPasswordEnc[18] = 0;
    this->m_ucPasswordEnc[19] = 0;
    this->m_ucPasswordEnc[20] = 0;
    this->m_ucPasswordEnc[21] = 0;
    this->m_ucPasswordEnc[22] = 0;
    this->m_ucPasswordEnc[23] = 0;
    this->m_ucPasswordEnc[24] = 0;
    this->m_ucPasswordEnc[25] = 0;
    this->m_ucPasswordEnc[10] = 0;
    this->m_ucPasswordEnc[11] = 0;
    this->m_ucPasswordEnc[12] = 0;
    this->m_ucPasswordEnc[13] = 0;
    this->m_ucPasswordEnc[14] = 0;
    this->m_ucPasswordEnc[15] = 0;
    this->m_ucPasswordEnc[16] = 0;
    this->m_ucPasswordEnc[17] = 0;
    this->m_ucPasswordEnc[2] = 0;
    this->m_ucPasswordEnc[3] = 0;
    this->m_ucPasswordEnc[4] = 0;
    this->m_ucPasswordEnc[5] = 0;
    this->m_ucPasswordEnc[6] = 0;
    this->m_ucPasswordEnc[7] = 0;
    this->m_ucPasswordEnc[8] = 0;
    this->m_ucPasswordEnc[9] = 0;
    this->m_nResult = 0;
    this->m_ucPasswordSrcSize = 0;
    this->m_ucPasswordEncSize = 0;
    this->m_ucPasswordEnc[0] = 0;
    this->m_ucPasswordEnc[1] = 0;
}

inline nUserSession::CPacket_S2C_COG_LOGIN_SKIP_DISABLE_RES::CPacket_S2C_COG_LOGIN_SKIP_DISABLE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucFlag = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_COG_LOGIN_SKIP_FLAG_RES::CPacket_S2C_COG_LOGIN_SKIP_FLAG_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucFlag = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_COMMUNITY_CHARACTER_STATUS_GET_RES::CPacket_S2C_COMMUNITY_CHARACTER_STATUS_GET_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CONSUME_STORAGE_ITEM_RES::CPacket_S2C_CONSUME_STORAGE_ITEM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CRAFT_EXP_UP_NOTICE::CPacket_S2C_CRAFT_EXP_UP_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unCraftRankLimit = 0;
    this->m_unExtraBonusExp = 0;
    this->m_unTotalExp = 0;
    this->m_unPawnID = 0;
    this->m_unAddExp = 0;
}

inline nUserSession::CPacket_S2C_CRAFT_RANK_UP_NOTICE::CPacket_S2C_CRAFT_RANK_UP_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unAddCraftPoint = 0;
    this->m_unTotalCraftPoint = 0;
    this->m_unPawnID = 0;
    this->m_unCraftRank = 0;
}

inline nUserSession::CPacket_S2C_CRAFT_SKILL_ANALYZE_RES::CPacket_S2C_CRAFT_SKILL_ANALYZE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CRAFT_SKILL_UP_RES::CPacket_S2C_CRAFT_SKILL_UP_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unUseCraftPoint = 0;
    this->m_unRemainCraftPoint = 0;
    this->m_unSkillType = 0;
    this->m_unSkillLevel = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
}

inline nUserSession::CPacket_S2C_CRAFT_TIME_SAVE_RES::CPacket_S2C_CRAFT_TIME_SAVE_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unRemainTime = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
}

inline nUserSession::CPacket_S2C_CREATE_MYPAWN_RES::CPacket_S2C_CREATE_MYPAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CYCLE_CONTENTS_ENABLE_NOTICE::CPacket_S2C_CYCLE_CONTENTS_ENABLE_NOTICE() {
    this->m_usError = 0;
    this->m_unCycleContentsScheduleId = 0;
    this->m_bIsEnable = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CYCLE_CONTENTS_END_NOTICE::CPacket_S2C_CYCLE_CONTENTS_END_NOTICE() {
    this->m_usError = 0;
    this->m_unCycleContentsScheduleId = 0;
    this->m_ucCategory = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CYCLE_CONTENTS_PLAY_END_RES::CPacket_S2C_CYCLE_CONTENTS_PLAY_END_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_CYCLE_CONTENTS_PLAY_START_RES::CPacket_S2C_CYCLE_CONTENTS_PLAY_START_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DEBUG_COMMAND_RES::CPacket_S2C_DEBUG_COMMAND_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DEBUG_CYCLE_CONTENTS_POINT_UPLOAD_RES::CPacket_S2C_DEBUG_CYCLE_CONTENTS_POINT_UPLOAD_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DEBUG_ENEMY_SET_PRESET_FIX_RES::CPacket_S2C_DEBUG_ENEMY_SET_PRESET_FIX_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DEBUG_GET_QUEST_FLAG_RES::CPacket_S2C_DEBUG_GET_QUEST_FLAG_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES::CPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DEBUG_MAIN_QUEST_JUMP_RES::CPacket_S2C_DEBUG_MAIN_QUEST_JUMP_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DEBUG_QUEST_RESET_ALL_RES::CPacket_S2C_DEBUG_QUEST_RESET_ALL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucQuestType = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DEBUG_QUEST_RESET_RES::CPacket_S2C_DEBUG_QUEST_RESET_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE::CPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE() {
    this->m_usError = 0;
    this->m_unQuestScheduleId = 0;
    this->m_unProcessNo = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DECIDE_DELIVERY_ITEM_RES::CPacket_S2C_DECIDE_DELIVERY_ITEM_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_usProcessNo = 0;
    this->m_nResult = 0;
    this->m_unQuestScheduleId = 0;
}

inline nUserSession::CPacket_S2C_DELETE_FAVORITE_PAWN_RES::CPacket_S2C_DELETE_FAVORITE_PAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DELETE_MYPAWN_RES::CPacket_S2C_DELETE_MYPAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_DELIVER_ITEM_RES::CPacket_S2C_DELIVER_ITEM_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_usProcessNo = 0;
    this->m_nResult = 0;
    this->m_unQuestScheduleId = 0;
}

inline nUserSession::CPacket_S2C_EJECTION_NTC::CPacket_S2C_EJECTION_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENCOUNTER_PAWN_NOTICE::CPacket_S2C_ENCOUNTER_PAWN_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES::CPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENEMY_KILL_RES::CPacket_S2C_ENEMY_KILL_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unKillNum = 0;
    this->m_unResult = 0;
    this->m_unEnemyID = 0;
}

inline nUserSession::CPacket_S2C_ENEMY_STAGE_BOSS_ANNIHILATE_NTC::CPacket_S2C_ENEMY_STAGE_BOSS_ANNIHILATE_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES::CPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_usTimeOut = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_FORCE_START_RES::CPacket_S2C_ENTRY_BOARD_ITEM_FORCE_START_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_INFO_LOCK_RES::CPacket_S2C_ENTRY_BOARD_ITEM_INFO_LOCK_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline CEntryItem& nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_INFO_RES::EntryItemData() {
    return this->m_EntryItemData;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_INVITE_RES::CPacket_S2C_ENTRY_BOARD_ITEM_INVITE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE::CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE() {
    this->m_usError = 0;
    this->m_unLeaveType = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_RES::CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES::CPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_PARTY_NOTICE::CPacket_S2C_ENTRY_BOARD_ITEM_PARTY_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE::CPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE() {
    this->m_usError = 0;
    this->m_unMaxMember = 0;
    this->m_usTimeOut = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_READY_RES::CPacket_S2C_ENTRY_BOARD_ITEM_READY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE::CPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE() {
    this->m_usError = 0;
    this->m_unNowMember = 0;
    this->m_unMaxMember = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE::CPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE() {
    this->m_usError = 0;
    this->m_usTimeOut = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE::CPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES::CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_EXCHANGE_OM_INSTANT_KEY_VALUE_RES::CPacket_S2C_EXCHANGE_OM_INSTANT_KEY_VALUE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unStageId = 0;
}

inline nUserSession::CPacket_S2C_EXTEND_EQUIP_SLOT_NTC::CPacket_S2C_EXTEND_EQUIP_SLOT_NTC() {
    this->m_ucTotalNum = 0;
    this->m_bIsReceived = false;
    this->m_usError = 0;
    this->m_ucSlot = 0;
    this->m_ucAddNum = 0;
}

inline nUserSession::CPacket_S2C_EXTEND_MAIN_PAWN_SLOT_NTC::CPacket_S2C_EXTEND_MAIN_PAWN_SLOT_NTC() {
    this->m_bIsReceived = false;
    this->m_usError = 0;
    this->m_ucAddNum = 0;
    this->m_ucTotalNum = 0;
}

inline nUserSession::CPacket_S2C_EXTEND_SUPPORT_PAWN_SLOT_NTC::CPacket_S2C_EXTEND_SUPPORT_PAWN_SLOT_NTC() {
    this->m_bIsReceived = false;
    this->m_usError = 0;
    this->m_ucAddNum = 0;
    this->m_ucTotalNum = 0;
}

inline nUserSession::CPacket_S2C_FAVORITE_WARP_RES::CPacket_S2C_FAVORITE_WARP_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unrim = 0;
    this->m_nResult = 0;
    this->m_unWarpPointID = 0;
}

inline nUserSession::CPacket_S2C_FINISH_CRAFT_NOTICE::CPacket_S2C_FINISH_CRAFT_NOTICE() {
    this->m_usError = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_FINISH_DEATH_PENALTY_OTHER_NOTICE::CPacket_S2C_FINISH_DEATH_PENALTY_OTHER_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_FINISH_LANTERN_NOTICE::CPacket_S2C_FINISH_LANTERN_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_FINISH_LANTERN_OTHER_NOTICE::CPacket_S2C_FINISH_LANTERN_OTHER_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_FORT_DEFENSE_NOTICE::CPacket_S2C_FORT_DEFENSE_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE::CPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE() {
    this->m_usError = 0;
    this->m_unCycleContentsScheduleId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_FURNITURE_LAYOUT_RES::CPacket_S2C_FURNITURE_LAYOUT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GACHA_BUY_RES::CPacket_S2C_GACHA_BUY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unId = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_GACHA_BUY_RES::Id() const {
    return this->m_unId;
}

inline nUserSession::CPacket_S2C_GACHA_LIST_RES::CPacket_S2C_GACHA_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GAIN_PAWN_PARAM_NTC::CPacket_S2C_GAIN_PAWN_PARAM_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unMagicDefenseGain = 0;
    this->m_unDefenseGain = 0;
    this->m_unMagicAttackGain = 0;
    this->m_unStaminaMaxGain = 0;
    this->m_unAttackGain = 0;
    this->m_unPawnId = 0;
    this->m_unHpMaxGain = 0;
}

inline nUserSession::CPacket_S2C_GAME_TIME_BASEINFO_NTC::CPacket_S2C_GAME_TIME_BASEINFO_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_GameTimeBaseInfo.m_unOriginalWeek = 0;
    this->m_GameTimeBaseInfo.m_unOriginalMoonAge = 0;
    this->m_GameTimeBaseInfo.m_llOriginalGameTimeSec = 0;
    this->m_GameTimeBaseInfo.m_llOriginalRealTimeSec = 0;
    this->m_GameTimeBaseInfo.m_unGameTimeWeekDay = 0;
    this->m_GameTimeBaseInfo.m_unGameTimeMoonAge = 0;
    this->m_GameTimeBaseInfo.m_unGameTimeMonthDay = 0;
    this->m_GameTimeBaseInfo.m_unGameTimeDayHour = 0;
    this->m_GameTimeBaseInfo.m_unGameTimeOneDayMin = 0;
    this->m_GameTimeBaseInfo.m_unGameTimeYearMonth = 0;
}

inline nUserSession::CPacket_S2C_GET_ABILITY_COST_RES::CPacket_S2C_GET_ABILITY_COST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unCostMax = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_GET_ABILITY_COST_RES::CostMax() const {
    return this->m_unCostMax;
}

inline nUserSession::CPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES::CPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES::CPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES::CPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES::CPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_AREA_BONUS_LIST_RES::CPacket_S2C_GET_AREA_BONUS_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_AREA_INFO_LIST_RES::CPacket_S2C_GET_AREA_INFO_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_AREA_POINT_DEBUG_RES::CPacket_S2C_GET_AREA_POINT_DEBUG_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES::CPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_AREA_SUPPLY_INFO_RES::CPacket_S2C_GET_AREA_SUPPLY_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucSupplyGrade = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_AREA_SUPPLY_RES::CPacket_S2C_GET_AREA_SUPPLY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_AREA_WARP_POINT_LIST_RES::CPacket_S2C_GET_AREA_WARP_POINT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES::CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_CAPLINK_ACHIEVE_REWARD_RES::CPacket_S2C_GET_CAPLINK_ACHIEVE_REWARD_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_CAP_RES::CPacket_S2C_GET_CAP_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_unCAP = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES::CPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_CHEAT_INFO_REQ::CPacket_S2C_GET_CHEAT_INFO_REQ() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_CRAFT_LOCKED_ELEMENT_LIST_RES::CPacket_S2C_GET_CRAFT_LOCKED_ELEMENT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES::CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline CCraftProductInfo& nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES::CraftProductInfo() {
    return this->m_CraftProductInfo;
}

inline nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_RES::CPacket_S2C_GET_CRAFT_PRODUCT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES::CPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataCommonU32>& nUserSession::CPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES::CreatedReicpeList() {
    return this->m_CreatedReicpeList;
}

inline nUserSession::CPacket_S2C_GET_CRAFT_SETTING_RES::CPacket_S2C_GET_CRAFT_SETTING_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucCreateCountMax = 0;
    this->m_bIsReceived = false;
    this->m_unReasonableCraftLv = 0;
    this->m_unCraftItemLv = 0;
}

inline u32 nUserSession::CPacket_S2C_GET_CRAFT_SETTING_RES::CraftItemLv() const {
    return this->m_unCraftItemLv;
}

inline u8 nUserSession::CPacket_S2C_GET_CRAFT_SETTING_RES::CreateCountMax() const {
    return this->m_ucCreateCountMax;
}

inline nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_RES::CPacket_S2C_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unCycleContentsScheduleId = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataBorderRewardRecord>& nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_RES::BorderRewardRecordList() {
    return this->m_BorderRewardRecordList;
}

inline nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_NEWS_LIST_RES::CPacket_S2C_GET_CYCLE_CONTENTS_NEWS_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline CQuestPointDetail& nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_POINT_LIST_RES::QuestPointDetail() {
    return this->m_QuestPointDetail;
}

inline nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_RES::CPacket_S2C_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unCycleContentsScheduleId = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataRankingRewardRecord>& nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_RES::RankingRewardRecordList() {
    return this->m_RankingRewardRecordList;
}

inline nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_REWARD_RES::CPacket_S2C_GET_CYCLE_CONTENTS_REWARD_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unCycleContentsScheduleId = 0;
    this->m_bIsAddRewardBox = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_DISPEL_ITEM_LIST_RES::CPacket_S2C_GET_DISPEL_ITEM_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES::CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_DROP_ITEM_LIST_RES::CPacket_S2C_GET_DROP_ITEM_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unId = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_GET_DROP_ITEM_LIST_RES::Id() const {
    return this->m_unId;
}

inline nUserSession::CPacket_S2C_GET_END_CONTENTS_GROUP_RES::CPacket_S2C_GET_END_CONTENTS_GROUP_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unGroupID = 0;
    this->m_unEndContentsType = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_GET_END_CONTENTS_GROUP_RES::GroupID() const {
    return this->m_unGroupID;
}

inline CEndContentsGroup& nUserSession::CPacket_S2C_GET_END_CONTENTS_GROUP_RES::EndContentsGroup() {
    return this->m_EndContentsGroup;
}

inline nUserSession::CPacket_S2C_GET_EXP_MODE_RES::CPacket_S2C_GET_EXP_MODE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucMode = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES::CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unSlotIDMax = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataFavoriteWarpPoint>& nUserSession::CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES::FavoriteWarpPointList() {
    return this->m_FavoriteWarpPointList;
}

inline u32 nUserSession::CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES::SlotIDMax() const {
    return this->m_unSlotIDMax;
}

inline nUserSession::CPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES::CPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_GP_DETAIL_RES::CPacket_S2C_GET_GP_DETAIL_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_GP_PERIOD_RES::CPacket_S2C_GET_GP_PERIOD_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_GP_RES::CPacket_S2C_GET_GP_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_unGP = 0;
    this->m_bIsReceived = false;
    this->m_usMilliseconds = 0;
    this->m_ullRealTime = 0;
    this->m_llUseLimit = 0;
}

inline nUserSession::CPacket_S2C_GET_INSTANT_KEY_VALUE_UL_RES::CPacket_S2C_GET_INSTANT_KEY_VALUE_UL_RES() {
    this->m_usError = 0;
    this->m_ucResult = 0;
    this->m_unValue = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_ITEM_STORAGE_INFO_RES::CPacket_S2C_GET_ITEM_STORAGE_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataJobChangeInfo>& nUserSession::CPacket_S2C_GET_JOB_CHANGE_LIST_RES::JobChangeInfo() const {
    return this->m_JobChangeInfo;
}

inline const MtTypedArray<CDataJobChangeInfo>& nUserSession::CPacket_S2C_GET_JOB_CHANGE_LIST_RES::JobReleaseInfo() const {
    return this->m_JobReleaseInfo;
}

inline const MtTypedArray<CDataPawnJobChangeInfo>& nUserSession::CPacket_S2C_GET_JOB_CHANGE_LIST_RES::PawnJobChangeInfoList() const {
    return this->m_PawnJobChangeInfoList;
}

inline nUserSession::CPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES::CPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES::CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataLearnedAcquirementParam>& nUserSession::CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES::LearnedAcquirementParamList() const {
    return this->m_LearnedAcquirementParamList;
}

inline nUserSession::CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES::CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataNormalSkillParam>& nUserSession::CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES::NormalSkillParamList() const {
    return this->m_NormalSkillParamList;
}

inline nUserSession::CPacket_S2C_GET_LEARNED_SKILL_LIST_RES::CPacket_S2C_GET_LEARNED_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataLearnedAcquirementParam>& nUserSession::CPacket_S2C_GET_LEARNED_SKILL_LIST_RES::LearnedAcquirementParamList() const {
    return this->m_LearnedAcquirementParamList;
}

inline nUserSession::CPacket_S2C_GET_LIGHT_QUEST_LIST_RES::CPacket_S2C_GET_LIGHT_QUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unBaseID = 0;
    this->m_ucNotCompleteQuestNum = 0;
    this->m_ucGpCompletePriceGp = 0;
    this->m_bGpCompleteEnable = false;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataLightQuestList>& nUserSession::CPacket_S2C_GET_LIGHT_QUEST_LIST_RES::LightQuestList() {
    return this->m_LightQuestList;
}

inline nUserSession::CPacket_S2C_GET_LOGIN_ANNOUNCEMENT_RES::CPacket_S2C_GET_LOGIN_ANNOUNCEMENT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_LOT_QUEST_LIST_RES::CPacket_S2C_GET_LOT_QUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unLotQuestType = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataLotQuestList>& nUserSession::CPacket_S2C_GET_LOT_QUEST_LIST_RES::LotQuestList() {
    return this->m_LotQuestList;
}

inline nUserSession::CPacket_S2C_GET_MAIN_QUEST_LIST_END_NOTICE::CPacket_S2C_GET_MAIN_QUEST_LIST_END_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_MAIN_QUEST_LIST_NOTICE::CPacket_S2C_GET_MAIN_QUEST_LIST_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_MAIN_QUEST_LIST_RES::CPacket_S2C_GET_MAIN_QUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataMainQuestList>& nUserSession::CPacket_S2C_GET_MAIN_QUEST_LIST_RES::MainQuestList() {
    return this->m_MainQuestList;
}

inline nUserSession::CPacket_S2C_GET_MATCHING_PROFILE_RES::CPacket_S2C_GET_MATCHING_PROFILE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJob = 0;
    this->m_unLevel = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_RES::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucListNum = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataRewardBoxRecord>& nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES::RewardBoxRecordList() {
    return this->m_RewardBoxRecordList;
}

inline MtTypedArray<CDataCycleContentsRewardRecord>& nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES::CycleContentsRewardRecordList() {
    return this->m_CycleContentsRewardRecordList;
}

inline nUserSession::CPacket_S2C_GET_OM_INSTANT_KEY_VALUE_RES::CPacket_S2C_GET_OM_INSTANT_KEY_VALUE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unStageId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_ORB_GAIN_EXTEND_PARAM_RES::CPacket_S2C_GET_ORB_GAIN_EXTEND_PARAM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES::CPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline CPartyQuestProgressInfo& nUserSession::CPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES::PartyQuestProgressInfo() {
    return this->m_PartyQuestProgressInfo;
}

inline nUserSession::CPacket_S2C_GET_PAWN_ABILITY_COST_RES::CPacket_S2C_GET_PAWN_ABILITY_COST_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unCostMax = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
}

inline u32 nUserSession::CPacket_S2C_GET_PAWN_ABILITY_COST_RES::CostMax() const {
    return this->m_unCostMax;
}

inline nUserSession::CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES::CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataLearnedAcquirementParam>& nUserSession::CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES::LearnedAcquirementParamList() const {
    return this->m_LearnedAcquirementParamList;
}

inline nUserSession::CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES::CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataNormalSkillParam>& nUserSession::CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES::NormalSkillParamList() const {
    return this->m_NormalSkillParamList;
}

inline nUserSession::CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES::CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataLearnedAcquirementParam>& nUserSession::CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES::LearnedAcquirementParamList() const {
    return this->m_LearnedAcquirementParamList;
}

inline nUserSession::CPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES::CPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES::CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataSetAcquirementParam>& nUserSession::CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES::SetAcquirementParamList() const {
    return this->m_SetAcquirementParamList;
}

inline nUserSession::CPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES::CPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES::CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES::CPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucPointType = 0;
    this->m_unPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_PRESET_ABILITY_LIST_RES::CPacket_S2C_GET_PRESET_ABILITY_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataPresetAbilityParam>& nUserSession::CPacket_S2C_GET_PRESET_ABILITY_LIST_RES::PresetAbilityParamList() const {
    return this->m_PresetAbilityParamList;
}

inline nUserSession::CPacket_S2C_GET_PRIORITY_QUEST_RES::CPacket_S2C_GET_PRIORITY_QUEST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_QUEST_COMPLETE_LIST_RES::CPacket_S2C_GET_QUEST_COMPLETE_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucQuestType = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES::CPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES() {
    this->m_usError = 0;
    this->m_bValue = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES::CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullNextReloadTime = 0;
    this->m_bIsReceived = false;
}

inline u64 nUserSession::CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES::NextReloadTime() const {
    return this->m_ullNextReloadTime;
}

inline nUserSession::CPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES::CPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unQuestId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_REAL_TIME_RES::CPacket_S2C_GET_REAL_TIME_RES() {
    this->m_usError = 0;
    this->m_ullRealTime = 0;
    this->m_usMilliseconds = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES::CPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES::CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES::CPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_RELEASE_SKILL_LIST_RES::CPacket_S2C_GET_RELEASE_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_REVIVE_CHARGEABLE_TIME_RES::CPacket_S2C_GET_REVIVE_CHARGEABLE_TIME_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unRemainTime = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_REVIVE_POINT_RES::CPacket_S2C_GET_REVIVE_POINT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucRevivePoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_REWARD_BOX_ITEM_RES::CPacket_S2C_GET_REWARD_BOX_ITEM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_REWARD_BOX_LIST_NUM_RES::CPacket_S2C_GET_REWARD_BOX_LIST_NUM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucListNum = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_REWARD_BOX_LIST_RES::CPacket_S2C_GET_REWARD_BOX_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataRewardBoxRecord>& nUserSession::CPacket_S2C_GET_REWARD_BOX_LIST_RES::RewardBoxRecordList() {
    return this->m_RewardBoxRecordList;
}

inline nUserSession::CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES::CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataScreenShotCategory>& nUserSession::CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES::CategoryList() {
    return this->m_CategoryList;
}

inline nUserSession::CPacket_S2C_GET_SERVER_LIST_RES::CPacket_S2C_GET_SERVER_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_SET_ABILITY_LIST_RES::CPacket_S2C_GET_SET_ABILITY_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataSetAcquirementParam>& nUserSession::CPacket_S2C_GET_SET_ABILITY_LIST_RES::SetAcquirementParamList() const {
    return this->m_SetAcquirementParamList;
}

inline nUserSession::CPacket_S2C_GET_SET_CONTEXT_RES::CPacket_S2C_GET_SET_CONTEXT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES::CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unDistributeID = 0;
    this->m_usAreaBaseMinLevel = 0;
    this->m_usAreaBaseMaxLevel = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES::DistributeID() const {
    return this->m_unDistributeID;
}

inline nUserSession::CPacket_S2C_GET_SET_QUEST_LIST_NOTICE::CPacket_S2C_GET_SET_QUEST_LIST_NOTICE() {
    this->m_usError = 0;
    this->m_unSelectCharacterId = 0;
    this->m_unDistributeId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_SET_QUEST_LIST_RES::CPacket_S2C_GET_SET_QUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unDistributeID = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_GET_SET_QUEST_LIST_RES::DistributeID() const {
    return this->m_unDistributeID;
}

inline MtTypedArray<CDataSetQuestList>& nUserSession::CPacket_S2C_GET_SET_QUEST_LIST_RES::SetQuestList() {
    return this->m_SetQuestList;
}

inline nUserSession::CPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES::CPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_SET_SKILL_LIST_RES::CPacket_S2C_GET_SET_SKILL_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_SHOP_GOODS_LIST_RES::CPacket_S2C_GET_SHOP_GOODS_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_SPOT_INFO_LIST_RES::CPacket_S2C_GET_SPOT_INFO_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_STAY_PRICE_RES::CPacket_S2C_GET_STAY_PRICE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucPointType = 0;
    this->m_unPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES::CPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES::CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unStageNo = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataTutorialQuestList>& nUserSession::CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES::TutorialQuestList() {
    return this->m_TutorialQuestList;
}

inline nUserSession::CPacket_S2C_GET_WARP_POINT_LIST_RES::CPacket_S2C_GET_WARP_POINT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_NOTICE::CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES::CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataWorldManageQuestList>& nUserSession::CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES::WorldManageQuestList() {
    return this->m_WorldManageQuestList;
}

inline nUserSession::CPacket_S2C_GP_COURSE_END_NTC::CPacket_S2C_GP_COURSE_END_NTC() {
    this->m_usError = 0;
    this->m_unCourseID = 0;
    this->m_unannounceType = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_COURSE_EXTEND_NTC::CPacket_S2C_GP_COURSE_EXTEND_NTC() {
    this->m_usError = 0;
    this->m_unCourseID = 0;
    this->m_ullFinishDateTime = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES::CPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_COURSE_GET_VALID_LIST_RES::CPacket_S2C_GP_COURSE_GET_VALID_LIST_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_COURSE_GET_VERSION_RES::CPacket_S2C_GP_COURSE_GET_VERSION_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_unVersion = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_COURSE_START_PARTY_NTC::CPacket_S2C_GP_COURSE_START_PARTY_NTC() {
    this->m_usError = 0;
    this->m_ucMemberIndex = 0;
    this->m_unCourseID = 0;
    this->m_unannounceType = 0;
    this->m_ullFinishDateTime = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_COURSE_USE_FROM_AVAILABLE_RES::CPacket_S2C_GP_COURSE_USE_FROM_AVAILABLE_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_ullFinishDateTime = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_EDIT_GET_GP_PRICE_RES::CPacket_S2C_GP_EDIT_GET_GP_PRICE_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_unPrice = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_RES::CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bCanBuy = false;
    this->m_unLineupId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_VOICE_RES::CPacket_S2C_GP_SHOP_CAN_BUY_PAWN_VOICE_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bCanBuy = false;
    this->m_unLineupId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_BUY_RES::CPacket_S2C_GP_SHOP_DISPLAY_BUY_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_unLineupId = 0;
    this->m_unBalance = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES::CPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES::CPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES::CPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES::CPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline CCharacterListElement& nUserSession::CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_NTC::VisitorInfo() {
    return this->m_VisitorInfo;
}

inline nUserSession::CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES::CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_GROUP_CHAT_KICK_CHARACTER_RES::CPacket_S2C_GROUP_CHAT_KICK_CHARACTER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_INSTANCE_AREA_RESET_NTC::CPacket_S2C_INSTANCE_AREA_RESET_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES::CPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unJobId = 0;
    this->m_ucJobValueType = 0;
    this->m_unValue = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES::CPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJobId = 0;
    this->m_ucJobValueType = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_JOIN_PARTY_MYPAWN_RES::CPacket_S2C_JOIN_PARTY_MYPAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_JOIN_PARTY_RENTED_PAWN_RES::CPacket_S2C_JOIN_PARTY_RENTED_PAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_NOTICE::CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_usBlockNo = 0;
    this->m_usProcessNo = 0;
    this->m_usSequenceNo = 0;
    this->m_unRequestCharacterId = 0;
    this->m_unQuestScheduleId = 0;
}

inline nUserSession::CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_RES::CPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucQuestProgressResult = 0;
    this->m_unQuestScheduleId = 0;
    this->m_usProcessNo = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LEARN_ABILITY_RES::CPacket_S2C_LEARN_ABILITY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJob = 0;
    this->m_ucAbilityLv = 0;
    this->m_bIsReceived = false;
    this->m_unNewJobPoint = 0;
    this->m_unAbilityID = 0;
}

inline nUserSession::CPacket_S2C_LEARN_NORMAL_SKILL_RES::CPacket_S2C_LEARN_NORMAL_SKILL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJob = 0;
    this->m_unSkillID = 0;
    this->m_unNewJobPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LEARN_PAWN_ABILITY_RES::CPacket_S2C_LEARN_PAWN_ABILITY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_ucJob = 0;
    this->m_ucAbilityLv = 0;
    this->m_bIsReceived = false;
    this->m_unNewJobPoint = 0;
    this->m_unAbilityID = 0;
}

inline nUserSession::CPacket_S2C_LEARN_PAWN_NORMAL_SKILL_RES::CPacket_S2C_LEARN_PAWN_NORMAL_SKILL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_ucJob = 0;
    this->m_unSkillID = 0;
    this->m_unNewJobPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LEARN_PAWN_SKILL_RES::CPacket_S2C_LEARN_PAWN_SKILL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_ucJob = 0;
    this->m_ucSkillLv = 0;
    this->m_bIsReceived = false;
    this->m_unNewJobPoint = 0;
    this->m_unSkillID = 0;
}

inline nUserSession::CPacket_S2C_LEARN_SKILL_RES::CPacket_S2C_LEARN_SKILL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJob = 0;
    this->m_ucSkillLv = 0;
    this->m_bIsReceived = false;
    this->m_unNewJobPoint = 0;
    this->m_unSkillID = 0;
}

inline nUserSession::CPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES::CPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unBaseID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LOADING_GET_INFO_RES::CPacket_S2C_LOADING_GET_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LOBBY_CHAT_MSG_RES::CPacket_S2C_LOBBY_CHAT_MSG_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LOBBY_LEAVE_RES::CPacket_S2C_LOBBY_LEAVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LOGIN_RES::CPacket_S2C_LOGIN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsCogLogin = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LOST_PAWN_GOLDEN_REVIVE_RES::CPacket_S2C_LOST_PAWN_GOLDEN_REVIVE_RES() {
    this->m_usError = 0;
    this->m_ucGP = 0;
    this->m_bIsReceived = false;
    this->m_nResult = 0;
    this->m_unPawnId = 0;
}

inline nUserSession::CPacket_S2C_LOST_PAWN_POINT_REVIVE_RES::CPacket_S2C_LOST_PAWN_POINT_REVIVE_RES() {
    this->m_usError = 0;
    this->m_ucRevivePoint = 0;
    this->m_bIsReceived = false;
    this->m_nResult = 0;
    this->m_unPawnId = 0;
}

inline nUserSession::CPacket_S2C_LOST_PAWN_REVIVE_RES::CPacket_S2C_LOST_PAWN_REVIVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_LOST_PAWN_WALLET_REVIVE_RES::CPacket_S2C_LOST_PAWN_WALLET_REVIVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnId = 0;
    this->m_ucType = 0;
    this->m_unValue = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_MAIL_DELETE_RES::CPacket_S2C_MAIL_DELETE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_MAIL_GET_LIST_FOOT_RES::CPacket_S2C_MAIL_GET_LIST_FOOT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_MAIL_GET_LIST_HEAD_RES::CPacket_S2C_MAIL_GET_LIST_HEAD_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unNum = 0;
    this->m_bIsReceived = false;
}

inline u64 nUserSession::CPacket_S2C_MAIL_GET_TEXT_RES::Id() const {
    return this->m_ullId;
}

inline nUserSession::CPacket_S2C_MASTER_THROW_RES::CPacket_S2C_MASTER_THROW_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_MOVE_IN_SERVER_RES::CPacket_S2C_MOVE_IN_SERVER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_MOVE_ITEM_RES::CPacket_S2C_MOVE_ITEM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_MY_ROOM_BGM_UPDATE_RES::CPacket_S2C_MY_ROOM_BGM_UPDATE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_MY_ROOM_RELEASE_RES::CPacket_S2C_MY_ROOM_RELEASE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_NOTICE::CPacket_S2C_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_NOTICE() {
    this->m_usError = 0;
    this->m_ucListNum = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_OPEN_UI_NTC::Id() const {
    return this->m_unId;
}

inline nUserSession::CPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES::CPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES() {
    this->m_usError = 0;
    this->m_bIsMax = false;
    this->m_bIsReceived = false;
    this->m_nResult = 0;
    this->m_unRemainSec = 0;
}

inline nUserSession::CPacket_S2C_PARTNER_PAWN_SET_RES::CPacket_S2C_PARTNER_PAWN_SET_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_BREAKUP_NTC::CPacket_S2C_PARTY_BREAKUP_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_BREAKUP_RES::CPacket_S2C_PARTY_BREAKUP_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_CHANGE_HOST_NTC::CPacket_S2C_PARTY_CHANGE_HOST_NTC() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_CHANGE_LEADER_NTC::CPacket_S2C_PARTY_CHANGE_LEADER_NTC() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_CHANGE_LEADER_RES::CPacket_S2C_PARTY_CHANGE_LEADER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_GET_CONTENT_NUMBER_RES::CPacket_S2C_PARTY_GET_CONTENT_NUMBER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPartyId = 0;
    this->m_ullContentNumber = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_CANCEL_NTC::CPacket_S2C_PARTY_INVITE_CANCEL_NTC() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_CANCEL_RES::CPacket_S2C_PARTY_INVITE_CANCEL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_RES::CPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_ENTRY_RES::CPacket_S2C_PARTY_INVITE_ENTRY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_FAIL_NTC::CPacket_S2C_PARTY_INVITE_FAIL_NTC() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_usServerId = 0;
    this->m_unPartyId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC::CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_NTC::CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_RES::CPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_REFUSE_RES::CPacket_S2C_PARTY_INVITE_REFUSE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_INVITE_RES::CPacket_S2C_PARTY_INVITE_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unPartyId = 0;
    this->m_nResult = 0;
    this->m_usTimeoutSec = 0;
    this->m_usServerId = 0;
}

inline nUserSession::CPacket_S2C_PARTY_JOIN_RES::CPacket_S2C_PARTY_JOIN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucMemberIndex = 0;
    this->m_ullContentNumber = 0;
    this->m_unPartyId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_LEAVE_RES::CPacket_S2C_PARTY_LEAVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_MEMBER_KICK_RES::CPacket_S2C_PARTY_MEMBER_KICK_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_MEMBER_SET_VALUE_RES::CPacket_S2C_PARTY_MEMBER_SET_VALUE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE::CPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE() {
    this->m_usError = 0;
    this->m_ucIsUndiscoverReward = 0;
    this->m_ucIsHelpReward = 0;
    this->m_ucIsPartyBonus = 0;
    this->m_bIsReceived = false;
    this->m_unQuestScheduleId = 0;
    this->m_ucRandomRewardNum = 0;
    this->m_ucChargeRewardNum = 0;
    this->m_ucProgressBonusNum = 0;
    this->m_ucIsRepeatReward = 0;
}

inline nUserSession::CPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE::CPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE() {
    this->m_usError = 0;
    this->m_unProgressCharacterId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PARTY_WARP_RES::CPacket_S2C_PARTY_WARP_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_ABILITY_SET_NTC::CPacket_S2C_PAWN_ABILITY_SET_NTC() {
    this->m_usError = 0;
    this->m_unPawnId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_CUSTOM_SKILL_SET_NTC::CPacket_S2C_PAWN_CUSTOM_SKILL_SET_NTC() {
    this->m_usError = 0;
    this->m_unPawnId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_EXPEDITION_CANCEL_SALLY_RES::CPacket_S2C_PAWN_EXPEDITION_CANCEL_SALLY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_EXPEDITION_CHANGE_GOLDEN_SALLY_RES::CPacket_S2C_PAWN_EXPEDITION_CHANGE_GOLDEN_SALLY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_EXPEDITION_CHARGE_SALLY_COUNT_RES::CPacket_S2C_PAWN_EXPEDITION_CHARGE_SALLY_COUNT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES::CPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
}

inline nUserSession::CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES::CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucSearchSpotType = 0;
    this->m_bIsGoldenSally = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_EXPEDITION_SALLY_RES::CPacket_S2C_PAWN_EXPEDITION_SALLY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_GOLDEN_REVIVE_RES::CPacket_S2C_PAWN_GOLDEN_REVIVE_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unGP = 0;
    this->m_nResult = 0;
    this->m_unPawnId = 0;
}

inline nUserSession::CPacket_S2C_PAWN_JOB_LEVEL_UP_MEMBER_NOTICE::CPacket_S2C_PAWN_JOB_LEVEL_UP_MEMBER_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_unPawnID = 0;
    this->m_ucJob = 0;
    this->m_unLevel = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_JOB_LEVEL_UP_NOTICE::CPacket_S2C_PAWN_JOB_LEVEL_UP_NOTICE() {
    this->m_usError = 0;
    this->m_unPawnID = 0;
    this->m_ucJob = 0;
    this->m_unLevel = 0;
    this->m_unAddJobPoint = 0;
    this->m_unTotalJobPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_LIKABILITY_UP_NTC::CPacket_S2C_PAWN_LIKABILITY_UP_NTC() {
    this->m_usError = 0;
    this->m_unPawnId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_LOST_RES::CPacket_S2C_PAWN_LOST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_bIsLost = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_NORMAL_SKILL_LEARN_NTC::CPacket_S2C_PAWN_NORMAL_SKILL_LEARN_NTC() {
    this->m_usError = 0;
    this->m_unPawnId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PAWN_POINT_REVIVE_RES::CPacket_S2C_PAWN_POINT_REVIVE_RES() {
    this->m_usError = 0;
    this->m_ucRevivePoint = 0;
    this->m_bIsReceived = false;
    this->m_nResult = 0;
    this->m_unPawnId = 0;
}

inline nUserSession::CPacket_S2C_PAWN_REVIVE_NOTICE::CPacket_S2C_PAWN_REVIVE_NOTICE() {
    this->m_usError = 0;
    this->m_unPawnId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PING_RES::CPacket_S2C_PING_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_ADD_TIMER_NOTICE::CPacket_S2C_PLAY_ADD_TIMER_NOTICE() {
    this->m_usError = 0;
    this->m_ullPlayEndDateTime = 0;
    this->m_bIsReceived = false;
}

inline u64 nUserSession::CPacket_S2C_PLAY_ADD_TIMER_NOTICE::PlayEndDateTime() const {
    return this->m_ullPlayEndDateTime;
}

inline nUserSession::CPacket_S2C_PLAY_END_RES::CPacket_S2C_PLAY_END_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_ENTRY_CANCEL_RES::CPacket_S2C_PLAY_ENTRY_CANCEL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_ENTRY_RES::CPacket_S2C_PLAY_ENTRY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_FORCE_INTERRUPT_NOTICE::CPacket_S2C_PLAY_FORCE_INTERRUPT_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_INTERRUPT_ANSWER_RES::CPacket_S2C_PLAY_INTERRUPT_ANSWER_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_INTERRUPT_RES::CPacket_S2C_PLAY_INTERRUPT_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_ucDeadlineSec = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_INTERRUPT_RESULT_NOTICE::CPacket_S2C_PLAY_INTERRUPT_RESULT_NOTICE() {
    this->m_usError = 0;
    this->m_bIsInterrupt = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_RESTART_TIMER_NOTICE::CPacket_S2C_PLAY_RESTART_TIMER_NOTICE() {
    this->m_usError = 0;
    this->m_ullPlayEndDateTime = 0;
    this->m_bIsReceived = false;
}

inline u64 nUserSession::CPacket_S2C_PLAY_RESTART_TIMER_NOTICE::PlayEndDateTime() const {
    return this->m_ullPlayEndDateTime;
}

inline nUserSession::CPacket_S2C_PLAY_START_RES::CPacket_S2C_PLAY_START_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_START_TIMER_NOTICE::CPacket_S2C_PLAY_START_TIMER_NOTICE() {
    this->m_usError = 0;
    this->m_ullPlayEndDateTime = 0;
    this->m_bIsReceived = false;
}

inline u64 nUserSession::CPacket_S2C_PLAY_START_TIMER_NOTICE::PlayEndDateTime() const {
    return this->m_ullPlayEndDateTime;
}

inline nUserSession::CPacket_S2C_PLAY_START_TIMER_RES::CPacket_S2C_PLAY_START_TIMER_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_STOP_TIMER_NOTICE::CPacket_S2C_PLAY_STOP_TIMER_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PLAY_TIMEUP_NOTICE::CPacket_S2C_PLAY_TIMEUP_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES::CPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUEST_CANCEL_NOTICE::CPacket_S2C_QUEST_CANCEL_NOTICE() {
    this->m_usError = 0;
    this->m_unQuestScheduleId = 0;
    this->m_unQuestId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUEST_CANCEL_RES::CPacket_S2C_QUEST_CANCEL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUEST_COMPLETE_FLAG_CLEAR_RES::CPacket_S2C_QUEST_COMPLETE_FLAG_CLEAR_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUEST_COMPLETE_NOTICE::CPacket_S2C_QUEST_COMPLETE_NOTICE() {
    this->m_usError = 0;
    this->m_ucIsUndiscoverReward = 0;
    this->m_ucIsHelpReward = 0;
    this->m_ucIsPartyBonus = 0;
    this->m_bIsReceived = false;
    this->m_unQuestScheduleId = 0;
    this->m_ucRandomRewardNum = 0;
    this->m_ucChargeRewardNum = 0;
    this->m_ucProgressBonusNum = 0;
    this->m_ucIsRepeatReward = 0;
}

inline nUserSession::CPacket_S2C_QUEST_ENABLE_NOTICE::CPacket_S2C_QUEST_ENABLE_NOTICE() {
    this->m_usError = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsEnable = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUEST_MASTER_DATA_RELOAD_NOTICE::CPacket_S2C_QUEST_MASTER_DATA_RELOAD_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUEST_ORDER_NOTICE::CPacket_S2C_QUEST_ORDER_NOTICE() {
    this->m_usError = 0;
    this->m_unQuestScheduleId = 0;
    this->m_unQuestId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUEST_ORDER_RES::CPacket_S2C_QUEST_ORDER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataQuestProcessState>& nUserSession::CPacket_S2C_QUEST_ORDER_RES::QuestProcessStateList() {
    return this->m_QuestProcessStateList;
}

inline nUserSession::CPacket_S2C_QUEST_PHASE_NOTICE::CPacket_S2C_QUEST_PHASE_NOTICE() {
    this->m_usError = 0;
    this->m_unGroupId = 0;
    this->m_unPhaseId = 0;
    this->m_bIsReceived = false;
}

inline u32 nUserSession::CPacket_S2C_QUEST_PHASE_NOTICE::PhaseId() const {
    return this->m_unPhaseId;
}

inline nUserSession::CPacket_S2C_QUEST_PROGRESS_NOTICE::CPacket_S2C_QUEST_PROGRESS_NOTICE() {
    this->m_usError = 0;
    this->m_unProgressCharacterId = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUEST_PROGRESS_RES::CPacket_S2C_QUEST_PROGRESS_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucQuestProgressResult = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsReceived = false;
}

inline MtTypedArray<CDataQuestProcessState>& nUserSession::CPacket_S2C_QUEST_PROGRESS_RES::QuestProcessStateList() {
    return this->m_QuestProcessStateList;
}

inline nUserSession::CPacket_S2C_QUEST_TIMER_NOTICE::CPacket_S2C_QUEST_TIMER_NOTICE() {
    this->m_usError = 0;
    this->m_unQuestScheduleId = 0;
    this->m_ucTimerNo = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_CANCEL_NTC::CPacket_S2C_QUICK_PARTY_CANCEL_NTC() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_ENTRY_NTC::CPacket_S2C_QUICK_PARTY_ENTRY_NTC() {
    this->m_usError = 0;
    this->m_unCharacterId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_ENTRY_RES::CPacket_S2C_QUICK_PARTY_ENTRY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_READY_NTC::CPacket_S2C_QUICK_PARTY_READY_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_usTimeoutSec = 0;
    this->m_unMaxMember = 0;
    this->m_unPawnNum = 0;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_REGISTER_NTC::CPacket_S2C_QUICK_PARTY_REGISTER_NTC() {
    this->m_usError = 0;
    this->m_unPartyId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_NTC::CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_NTC() {
    this->m_usError = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_RES::CPacket_S2C_QUICK_PARTY_REGISTER_QUEST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_REGISTER_RES::CPacket_S2C_QUICK_PARTY_REGISTER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_usTimeoutSec = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_QUICK_PARTY_UNREADY_NTC::CPacket_S2C_QUICK_PARTY_UNREADY_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RAID_BOSS_NOTICE::CPacket_S2C_RAID_BOSS_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES::CPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unStageID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RANKING_BOARD_LIST_RES::CPacket_S2C_RANKING_BOARD_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES::CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_llModified = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataRankingData>& nUserSession::CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES::RankingData() const {
    return this->m_RankingData;
}

inline s64 nUserSession::CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES::Modified() const {
    return this->m_llModified;
}

inline nUserSession::CPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES::CPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unRank = 0;
    this->m_llModified = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RANKING_DATA_RANK_RES::CPacket_S2C_RANKING_DATA_RANK_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unRank = 0;
    this->m_llModified = 0;
    this->m_bIsReceived = false;
}

inline const MtTypedArray<CDataRankingData>& nUserSession::CPacket_S2C_RANKING_DATA_RANK_RES::RankingData() const {
    return this->m_RankingData;
}

inline s64 nUserSession::CPacket_S2C_RANKING_DATA_RANK_RES::Modified() const {
    return this->m_llModified;
}

inline nUserSession::CPacket_S2C_REGISTER_FAVORITE_FRIEND_RES::CPacket_S2C_REGISTER_FAVORITE_FRIEND_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_REGISTER_FAVORITE_WARP_RES::CPacket_S2C_REGISTER_FAVORITE_WARP_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unWarpPointID = 0;
    this->m_nResult = 0;
    this->m_unSlotNo = 0;
}

inline nUserSession::CPacket_S2C_REGISTER_PRESET_ABILITY_RES::CPacket_S2C_REGISTER_PRESET_ABILITY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RELEASE_JOB_ORB_ELEMENT_RES::CPacket_S2C_RELEASE_JOB_ORB_ELEMENT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJobID = 0;
    this->m_unRestOrb = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RELEASE_ORB_ELEMENT_RES::CPacket_S2C_RELEASE_ORB_ELEMENT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unRestOrb = 0;
    this->m_ucGainParamType = 0;
    this->m_unGainParamValue = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RELEASE_PAWN_ORB_ELEMENT_RES::CPacket_S2C_RELEASE_PAWN_ORB_ELEMENT_RES() {
    this->m_usError = 0;
    this->m_unGainParamValue = 0;
    this->m_bIsReceived = false;
    this->m_ucGainParamType = 0;
    this->m_unRestOrb = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
}

inline nUserSession::CPacket_S2C_RELEASE_SET_QUEST_AREA_NOTICE::CPacket_S2C_RELEASE_SET_QUEST_AREA_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RENTAL_PAWN_LOST_RES::CPacket_S2C_RENTAL_PAWN_LOST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_ucAdventureCount = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RENT_REGISTERED_PAWN_RES::CPacket_S2C_RENT_REGISTERED_PAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unTotalRim = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES::CPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJobID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RESET_JOBPOINT_RES::CPacket_S2C_RESET_JOBPOINT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_RETURN_RENTED_PAWN_RES::CPacket_S2C_RETURN_RENTED_PAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_REWARD_BOX_LIST_NUM_NOTICE::CPacket_S2C_REWARD_BOX_LIST_NUM_NOTICE() {
    this->m_usError = 0;
    this->m_ucListNum = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SELL_ITEM_RES::CPacket_S2C_SELL_ITEM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucPointType = 0;
    this->m_unPoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_NOTICE::CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_RES::CPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_NOTICE::CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_RES::CPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SERVER_UI_COMMAND_RES::CPacket_S2C_SERVER_UI_COMMAND_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_ABILITY_RES::CPacket_S2C_SET_ABILITY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucSlotNo = 0;
    this->m_unAbilityID = 0;
    this->m_ucAbilityLv = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_ARISEN_PROFILE_RES::CPacket_S2C_SET_ARISEN_PROFILE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_CHARACTER_BIN_SAVEDATA_RES::CPacket_S2C_SET_CHARACTER_BIN_SAVEDATA_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_COMMUNICATION_SHORTCUT_LIST_RES::CPacket_S2C_SET_COMMUNICATION_SHORTCUT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_CONTEXT_BASE_NOTICE::CPacket_S2C_SET_CONTEXT_BASE_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_FAVORITE_PAWN_RES::CPacket_S2C_SET_FAVORITE_PAWN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_ITEM_SORTDATA_BIN_RES::CPacket_S2C_SET_ITEM_SORTDATA_BIN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_MATCHING_PROFILE_RES::CPacket_S2C_SET_MATCHING_PROFILE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_MESSAGE_SET_RES::CPacket_S2C_SET_MESSAGE_SET_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_OBJECTIVE_RES::CPacket_S2C_SET_OBJECTIVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_OFF_ABILITY_RES::CPacket_S2C_SET_OFF_ABILITY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucSlotNo = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_OFF_PAWN_ABILITY_RES::CPacket_S2C_SET_OFF_PAWN_ABILITY_RES() {
    this->m_usError = 0;
    this->m_ucSlotNo = 0;
    this->m_bIsReceived = false;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
}

inline nUserSession::CPacket_S2C_SET_OFF_PAWN_SKILL_RES::CPacket_S2C_SET_OFF_PAWN_SKILL_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_ucJob = 0;
    this->m_ucSlotNo = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
}

inline nUserSession::CPacket_S2C_SET_OFF_SKILL_RES::CPacket_S2C_SET_OFF_SKILL_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_ucJob = 0;
    this->m_ucSlotNo = 0;
    this->m_nResult = 0;
}

inline nUserSession::CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_NOTICE::CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_NOTICE() {
    this->m_usError = 0;
    this->m_unStageId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_RES::CPacket_S2C_SET_OM_INSTANT_KEY_VALUE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unStageId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_ONLINE_STATUS_RES::CPacket_S2C_SET_ONLINE_STATUS_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucStatusID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_PAWN_ABILITY_RES::CPacket_S2C_SET_PAWN_ABILITY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
    this->m_ucSlotNo = 0;
    this->m_unAbilityID = 0;
    this->m_ucAbilityLv = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_PAWN_PROFILE_COMMENT_RES::CPacket_S2C_SET_PAWN_PROFILE_COMMENT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_PAWN_PROFILE_RES::CPacket_S2C_SET_PAWN_PROFILE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_PAWN_SKILL_RES::CPacket_S2C_SET_PAWN_SKILL_RES() {
    this->m_usError = 0;
    this->m_unSkillID = 0;
    this->m_ucSkillLv = 0;
    this->m_bIsReceived = false;
    this->m_ucJob = 0;
    this->m_ucSlotNo = 0;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
}

inline nUserSession::CPacket_S2C_SET_PRESET_ABILITY_NAME_RES::CPacket_S2C_SET_PRESET_ABILITY_NAME_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_PRIORITY_QUEST_RES::CPacket_S2C_SET_PRIORITY_QUEST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unQuestScheduleId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_QUEST_UNRELEASED_AREA_NOTICE::CPacket_S2C_SET_QUEST_UNRELEASED_AREA_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_RAID_BOSS_INFO_RES::CPacket_S2C_SET_RAID_BOSS_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unRaidBossID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_SHORTCUT_LIST_RES::CPacket_S2C_SET_SHORTCUT_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SET_SKILL_RES::CPacket_S2C_SET_SKILL_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ucJob = 0;
    this->m_ucSlotNo = 0;
    this->m_unSkillID = 0;
    this->m_ucSkillLv = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_STAMP_BONUS_ADD_TOTAL_NUM_RES::CPacket_S2C_STAMP_BONUS_ADD_TOTAL_NUM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_STAMP_BONUS_CHECK_RES::CPacket_S2C_STAMP_BONUS_CHECK_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_nResult = 0;
    this->m_usTotalStampNum = 0;
    this->m_ucisRecieveBonusDaily = 0;
    this->m_ucisRecieveBonusTotal = 0;
}

inline nUserSession::CPacket_S2C_STAMP_BONUS_GET_LIST_RES::CPacket_S2C_STAMP_BONUS_GET_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_usTotalStampNum = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_STAMP_BONUS_RECIEVE_RES::CPacket_S2C_STAMP_BONUS_RECIEVE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_START_CRAFT_RES::CPacket_S2C_START_CRAFT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_START_DEATH_PENALTY_OTHER_NOTICE::CPacket_S2C_START_DEATH_PENALTY_OTHER_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_START_LANTERN_NOTICE::CPacket_S2C_START_LANTERN_NOTICE() {
    this->m_usError = 0;
    this->m_unRemainTime = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_START_LANTERN_OTHER_NOTICE::CPacket_S2C_START_LANTERN_OTHER_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterID = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SUPPORT_POINT_GET_RATE_RES::CPacket_S2C_SUPPORT_POINT_GET_RATE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SUPPORT_POINT_USE_RES::CPacket_S2C_SUPPORT_POINT_USE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SYSTEM_MAIL_DELETE_RES::CPacket_S2C_SYSTEM_MAIL_DELETE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullId = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_LIST_FOOT_RES::CPacket_S2C_SYSTEM_MAIL_GET_LIST_FOOT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_LIST_HEAD_RES::CPacket_S2C_SYSTEM_MAIL_GET_LIST_HEAD_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unNum = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES::CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_ullId = 0;
    this->m_bIsReceived = false;
}

inline u64 nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES::Id() const {
    return this->m_ullId;
}

inline nUserSession::CPacket_S2C_TIME_UPDATE_NOTICE::CPacket_S2C_TIME_UPDATE_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES::CPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unMaxLv = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_TRANING_ROOM_SET_ENEMY_RES::CPacket_S2C_TRANING_ROOM_SET_ENEMY_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_UPDATE_ARISEN_PROFILE_SHARE_RANGE_RES::CPacket_S2C_UPDATE_ARISEN_PROFILE_SHARE_RANGE_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_UPDATE_CHARACTER_EDIT_PARAM_RES::CPacket_S2C_UPDATE_CHARACTER_EDIT_PARAM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unGP = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_UPDATE_CHARACTER_JOB_POINT_NOTICE::CPacket_S2C_UPDATE_CHARACTER_JOB_POINT_NOTICE() {
    this->m_usError = 0;
    this->m_ucJob = 0;
    this->m_bIsReceived = false;
    this->m_unTotalJobPoint = 0;
    this->m_unAddJobPoint = 0;
    this->m_unExtraBonusPoint = 0;
}

inline nUserSession::CPacket_S2C_UPDATE_EQUIP_COLOR_NOTICE::CPacket_S2C_UPDATE_EQUIP_COLOR_NOTICE() {
    this->m_usError = 0;
    this->m_ucEquipType = 0;
    this->m_ucEquipSlot = 0;
    this->m_ucColor = 0;
    this->m_bIsReceived = false;
    this->m_unCharacterId = 0;
    this->m_unPawnId = 0;
}

inline nUserSession::CPacket_S2C_UPDATE_EQUIP_GRADE_NOTICE::CPacket_S2C_UPDATE_EQUIP_GRADE_NOTICE() {
    this->m_usError = 0;
    this->m_unItemID = 0;
    this->m_bIsReceived = false;
    this->m_ucEquipType = 0;
    this->m_ucEquipSlot = 0;
    this->m_unCharacterId = 0;
    this->m_unPawnId = 0;
}

inline nUserSession::CPacket_S2C_UPDATE_EQUIP_HIDE_NOTICE::CPacket_S2C_UPDATE_EQUIP_HIDE_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unCharacterID = 0;
    this->m_bHideHead = false;
    this->m_bHideLantern = false;
    this->m_bHidePawnHead = false;
    this->m_bHidePawnLantern = false;
}

inline nUserSession::CPacket_S2C_UPDATE_EQUIP_PRESET_NAME_RES::CPacket_S2C_UPDATE_EQUIP_PRESET_NAME_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_UPDATE_HIDE_PAWN_HEAD_ARMOR_RES::CPacket_S2C_UPDATE_HIDE_PAWN_HEAD_ARMOR_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bHide = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_UPDATE_HIDE_PAWN_LANTERN_RES::CPacket_S2C_UPDATE_HIDE_PAWN_LANTERN_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_bHide = false;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_UPDATE_MATCHING_PROFILE_NOTICE::CPacket_S2C_UPDATE_MATCHING_PROFILE_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_UPDATE_PAWN_SHARE_RANGE_RES::CPacket_S2C_UPDATE_PAWN_SHARE_RANGE_RES() {
    this->m_usError = 0;
    this->m_ucShareRange = 0;
    this->m_bIsReceived = false;
    this->m_nResult = 0;
    this->m_unPawnID = 0;
}

inline nUserSession::CPacket_S2C_UPDATE_PLAY_POINT_NOTICE::CPacket_S2C_UPDATE_PLAY_POINT_NOTICE() {
    this->m_usError = 0;
    this->m_ucJob = 0;
    this->m_ucType = 0;
    this->m_bIsReceived = false;
    this->m_unTotalPoint = 0;
    this->m_unUpdatePoint = 0;
    this->m_unExtraBonusPoint = 0;
}

inline nUserSession::CPacket_S2C_UPDATE_REVIVE_POINT_NOTICE::CPacket_S2C_UPDATE_REVIVE_POINT_NOTICE() {
    this->m_usError = 0;
    this->m_unCharacterId = 0;
    this->m_ucRevivePoint = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_USER_LIST_MAX_NUM_RES::CPacket_S2C_USER_LIST_MAX_NUM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unMaxNum = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_USE_BAG_ITEM_NOTICE::CPacket_S2C_USE_BAG_ITEM_NOTICE() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unItemNum = 0;
    this->m_unCharacterID = 0;
    this->m_unItemID = 0;
}

inline nUserSession::CPacket_S2C_USE_BAG_ITEM_RES::CPacket_S2C_USE_BAG_ITEM_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_USE_JOB_ITEMS_RES::CPacket_S2C_USE_JOB_ITEMS_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_WARP_RES::CPacket_S2C_WARP_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unrim = 0;
    this->m_nResult = 0;
    this->m_unWarpPointID = 0;
}

inline nUserSession::CPacket_S2C_WEATHER_FORECAST_GET_RES::CPacket_S2C_WEATHER_FORECAST_GET_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unIntervalGameHour = 0;
    this->m_unGameDayToEarthMin = 0;
    this->m_bIsReceived = false;
}

inline nUserSession::CPacket_S2C_WEATHER_UPDATE_NOTICE::CPacket_S2C_WEATHER_UPDATE_NOTICE() {
    this->m_usError = 0;
    this->m_unWeatherID = 0;
    this->m_bIsReceived = false;
}
