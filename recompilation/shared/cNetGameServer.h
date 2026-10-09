#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Character.h"
#include "CharacterCommon.h"
#include "CharacterParam.h"
#include "ChatMsgType.h"
#include "Clan.h"
#include "Common.h"
#include "Community.h"
#include "Craft.h"
#include "EntryBoard.h"
#include "Error.h"
#include "Item.h"
#include "JobMaster.h"
#include "Lobby.h"
#include "Mail.h"
#include "MtCipher.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtObject.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "MtType.h"
#include "Party.h"
#include "Pawn.h"
#include "Quest.h"
#include "QuickParty.h"
#include "Search.h"
#include "Server.h"
#include "Stage.h"
#include "cCharacterData.h"
#include "cEditParam.h"
#include "cSeedServerConnection.h"
#include "nNet.h"
#include "sNetworkExt.h"

// Forward declarations
class CDataAchieveCategoryStatus;
class CDataAchieveRewardCommon;
class CDataArisenProfile;
class CDataBorderRewardRecord;
class CDataC2SChangeCharacterEquipInfo;
class CDataChangeEquipJobItem;
class CDataCharacterInfo;
class CDataCharacterJobData;
class CDataCharacterLevelParam;
class CDataCharacterListElement;
class CDataCharacterListInfo;
class CDataCharacterMsgSet;
class CDataCharacterSearchParam;
class CDataCharacterSearchParameter;
class CDataCheatInfo;
class CDataClanHistoryElement;
class CDataClanJoinRequest;
class CDataClanMemberInfo;
class CDataClanParam;
class CDataClanScoutEntryInviteInfo;
class CDataClanScoutEntryParam;
class CDataClanScoutEntrySearchResult;
class CDataClanSearchParam;
class CDataClanSearchResult;
class CDataClanUserParam;
class CDataClientPartyListInfo;
class CDataCommonU32;
class CDataCommonU64;
class CDataCommonU8;
class CDataCommunicationShortCut;
class CDataCommunityCharacterBaseInfo;
class CDataContextBase;
class CDataContextPawnInfo;
class CDataContextPlayerInfo;
class CDataContextResist;
class CDataContextSetAdditional;
class CDataContextSetBase;
class CDataContextSetInfo;
class CDataCraftColorant;
class CDataCraftElement;
class CDataCraftMaterial;
class CDataCraftSupportPawnID;
class CDataCycleContentsStateList;
class CDataDLCLineupBought;
class CDataDLCLineupHistory;
class CDataDebugEnemySetPresetReq;
class CDataEditInfo;
class CDataEntryBoardItemSearchParameter;
class CDataEntryItem;
class CDataEntryItemParam;
class CDataEntryMemberData;
class CDataEntryRecruitData;
class CDataEntryRecruitJob;
class CDataEquipElementParam;
class CDataEquipJobItem;
class CDataFriendInfo;
class CDataFurnitureLayoutData;
class CDataGameItemStorage;
class CDataGameServerListInfo;
class CDataGatheringItemElement;
class CDataGatheringItemGetRequest;
class CDataGetDispelItem;
class CDataGetRewardBoxItem;
class CDataHistoryElement;
class CDataItemList;
class CDataItemSort;
class CDataItemStorageIndicateNum;
class CDataItemUIDList;
class CDataJobChangeInfo;
class CDataJobExpMode;
class CDataJobOrbTreeStatus;
class CDataLightQuestList;
class CDataLoadingInfoSchedule;
class CDataLobbyInfo;
class CDataLobbyMemberInfo;
class CDataLostPawnList;
class CDataLotQuestList;
class CDataMailAttachmentList;
class CDataMailInfo;
class CDataMainQuestList;
class CDataMasterInfo;
class CDataMatchingProfile;
class CDataMoveItemUIDFromTo;
class CDataOmData;
class CDataOrbGainExtendParam;
class CDataOrbPageStatus;
class CDataOrderConditionInfo;
class CDataPartnerPawnReward;
class CDataPartyListInfo;
class CDataPartyMember;
class CDataPartyMemberMinimum;
class CDataPartyQuestProgressInfo;
class CDataPartySearchParameter;
class CDataPawnFeedback;
class CDataPawnHistory;
class CDataPawnHp;
class CDataPawnInfo;
class CDataPawnList;
class CDataPawnListData;
class CDataPawnReaction;
class CDataPawnSearchParameter;
class CDataQuestContentsSituationInfo;
class CDataQuestPointDetail;
class CDataQuestProcessState;
class CDataQuickMatchSearchParameter;
class CDataQuickPartyMatching;
class CDataRaidBossUploadInfo;
class CDataRankingRewardRecord;
class CDataRegisterdPawnList;
class CDataRentedPawnList;
class CDataRewardBoxRecord;
class CDataS2CCharacterEquipInfo;
class CDataScreenShotCategory;
class CDataSelectItemInfo;
class CDataSetQuestList;
class CDataShortCut;
class CDataStageInfo;
class CDataStageLayoutID;
class CDataStatusInfo;
class CDataStorageItemUIDList;
class CDataTimeLimitedQuestList;
class CDataTutorialQuestList;
class CDataUseSupportPoint;
class CDataWorldInfo;
class CDataWorldManageQuestList;
class CPacket;
struct MT_ENUM;
class MtAllocator;
class MtCipher;
class MtCriticalSection;
class MtDTI;
class MtMemoryStream;
struct MtNetError;
class MtObject;
class MtString;
class cCharacterData;
class cContextInstHm;
class cContextInstance;
class cContextInterface;
class cEditParam;
class cGameTimeWeatherMoonInfo;
class cMenuBlackList;
class cMenuCancelClanScoutEntry;
class cMenuExtendEntryBoardItem;
class cMenuFriendList;
class cMenuGetClanBaseInfo;
class cMenuGetCraftRecipeToServer;
class cMenuGetMyClan;
class cMenuGetMyScoutEntry;
class cMenuLeaveGroupChat;
class cMenuMail;
class cMenuPartyList;
class cMenuPawnHistory;
class cMenuPawnSearch;
class cMenuQuickMatchRetry;
class cMenuSimplePartyReq;
namespace nJobParam { class cHumanBaseInfo; }
namespace nJobParam { class cJobInfo; }
namespace nNet { struct stPawnFeedback; }
namespace nSessionManager { class cNetSessionManager; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ACHIEVEMENT_REWARD_RECEIVE_RES; }
namespace nUserSession { class CPacket_S2C_ADD_BLACK_LIST_RES; }
namespace nUserSession { class CPacket_S2C_AREA_CHANGE_RES; }
namespace nUserSession { class CPacket_S2C_AREA_RANK_UP_RES; }
namespace nUserSession { class CPacket_S2C_BOX_GACHA_BUY_RES; }
namespace nUserSession { class CPacket_S2C_BOX_GACHA_DRAW_INFO_RES; }
namespace nUserSession { class CPacket_S2C_BOX_GACHA_LIST_RES; }
namespace nUserSession { class CPacket_S2C_BOX_GACHA_RESET_RES; }
namespace nUserSession { class CPacket_S2C_CANCEL_CRAFT_RES; }
namespace nUserSession { class CPacket_S2C_CANCEL_PRIORITY_QUEST_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_CAP_TO_GP_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_CHARACTER_EQUIP_JOB_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_CHARACTER_EQUIP_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_CHARACTER_STORAGE_EQUIP_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_JOB_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_PAWN_EQUIP_JOB_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_PAWN_EQUIP_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_PAWN_JOB_RES; }
namespace nUserSession { class CPacket_S2C_CHANGE_PAWN_STORAGE_EQUIP_RES; }
namespace nUserSession { class CPacket_S2C_CHARACTER_SEARCH_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_BASE_GET_INFO_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_HISTORY_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_INFO_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_MEMBER_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_MY_INFO_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SEARCH_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SHOP_GET_BUFF_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_COMMUNITY_CHARACTER_STATUS_UPDATE_NTC; }
namespace nUserSession { class CPacket_S2C_CRAFT_EXP_UP_NOTICE; }
namespace nUserSession { class CPacket_S2C_CRAFT_RANK_UP_NOTICE; }
namespace nUserSession { class CPacket_S2C_CRAFT_SKILL_ANALYZE_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_GET_QUEST_FLAG_RES; }
namespace nUserSession { class CPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES; }
namespace nUserSession { class CPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE; }
namespace nUserSession { class CPacket_S2C_DELIVER_ITEM_NOTICE; }
namespace nUserSession { class CPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_CHANGE_MEMBER_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_INFO_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE; }
namespace nUserSession { class CPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE; }
namespace nUserSession { class CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_FINISH_CRAFT_NOTICE; }
namespace nUserSession { class CPacket_S2C_FORT_DEFENSE_PLAY_START_NOTICE; }
namespace nUserSession { class CPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE; }
namespace nUserSession { class CPacket_S2C_GACHA_BUY_RES; }
namespace nUserSession { class CPacket_S2C_GACHA_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ABILITY_COST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_BONUS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_MASTER_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_SUPPLY_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_AREA_WARP_POINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_BLACK_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CHARACTER_EQUIP_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_COMMUNICATION_SHORTCUT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CRAFT_IR_COLLECTION_VALUE_LIST_RES; }
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
namespace nUserSession { class CPacket_S2C_GET_CYCLE_CONTENTS_SITUATION_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_CYCLE_CONTENTS_STATE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_DISPEL_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES; }
namespace nUserSession { class CPacket_S2C_GET_DROP_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_END_CONTENTS_GROUP_RES; }
namespace nUserSession { class CPacket_S2C_GET_FAVORITE_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_FRIEND_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_GAME_SETTING_RES; }
namespace nUserSession { class CPacket_S2C_GET_GATHERING_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_GATHERING_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_GET_GP_DETAIL_RES; }
namespace nUserSession { class CPacket_S2C_GET_GP_PERIOD_RES; }
namespace nUserSession { class CPacket_S2C_GET_ITEM_SORTDATA_BIN_RES; }
namespace nUserSession { class CPacket_S2C_GET_ITEM_STORAGE_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_JOB_CHANGE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEARNED_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LEGEND_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LIGHT_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LOST_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_LOT_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_MAIN_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_MATCHING_PROFILE_RES; }
namespace nUserSession { class CPacket_S2C_GET_MESSAGE_SET_RES; }
namespace nUserSession { class CPacket_S2C_GET_MYPAWN_DATA_RES; }
namespace nUserSession { class CPacket_S2C_GET_MYPAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_NORA_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_OFFICIAL_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PARTY_PAWN_DATA_RES; }
namespace nUserSession { class CPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_ABILITY_COST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_EQUIP_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_HISTORY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_PROFILE_NOTICE; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES; }
namespace nUserSession { class CPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES; }
namespace nUserSession { class CPacket_S2C_GET_POST_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PRESET_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_PRIORITY_QUEST_RES; }
namespace nUserSession { class CPacket_S2C_GET_QUEST_COMPLETE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES; }
namespace nUserSession { class CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES; }
namespace nUserSession { class CPacket_S2C_GET_RECENT_CHARACTER_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_REGISTERED_PAWN_DATA_RES; }
namespace nUserSession { class CPacket_S2C_GET_REGISTERED_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RELEASE_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_RENTED_PAWN_DATA_RES; }
namespace nUserSession { class CPacket_S2C_GET_RENTED_PAWN_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_REWARD_BOX_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_GET_REWARD_BOX_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES; }
namespace nUserSession { class CPacket_S2C_GET_SERVER_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_ABILITY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SET_SKILL_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SHOP_GOODS_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SHORTCUT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_SPOT_INFO_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_STAGE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_STAY_PRICE_RES; }
namespace nUserSession { class CPacket_S2C_GET_STORAGE_ITEM_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_WARP_POINT_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GP_COURSE_GET_VALID_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_DISPLAY_BUY_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES; }
namespace nUserSession { class CPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_BREAKUP_GROUP_NTC; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_GET_MEMBER_LIST_RES; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_NTC; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_KICK_CHARACTER_NTC; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_LEAVE_CHARACTER_NTC; }
namespace nUserSession { class CPacket_S2C_GROUP_CHAT_LEAVE_CHARACTER_RES; }
namespace nUserSession { class CPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES; }
namespace nUserSession { class CPacket_S2C_JOIN_PARTY_PAWN_NOTICE; }
namespace nUserSession { class CPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES; }
namespace nUserSession { class CPacket_S2C_LOADING_GET_INFO_RES; }
namespace nUserSession { class CPacket_S2C_LOBBY_JOIN_RES; }
namespace nUserSession { class CPacket_S2C_LOBBY_LEAVE_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_DELETE_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_GET_LIST_DATA_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_GET_TEXT_RES; }
namespace nUserSession { class CPacket_S2C_MAIL_SEND_NTC; }
namespace nUserSession { class CPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES; }
namespace nUserSession { class CPacket_S2C_PARTNER_PAWN_SET_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_BREAKUP_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_BREAKUP_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_CHANGE_HOST_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_CHANGE_LEADER_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_CREATE_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_CANCEL_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_CHARACTER_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_ENTRY_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_FAIL_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_INVITE_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_JOIN_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_LEAVE_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_LEAVE_RES; }
namespace nUserSession { class CPacket_S2C_PARTY_MEMBER_KICK_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_MEMBER_LOST_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_MEMBER_SESSION_STATUS_NTC; }
namespace nUserSession { class CPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE; }
namespace nUserSession { class CPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE; }
namespace nUserSession { class CPacket_S2C_PARTY_SEARCH_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_DUNGEON_REWARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_INFO_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_LIKABILITY_RELEASED_REWARD_LIST_GET_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_LIKABILITY_REWARD_LIST_GET_RES; }
namespace nUserSession { class CPacket_S2C_PAWN_LOST_RES; }
namespace nUserSession { class CPacket_S2C_PING_RES; }
namespace nUserSession { class CPacket_S2C_PLAY_ENTRY_CANCEL_NOTICE; }
namespace nUserSession { class CPacket_S2C_PLAY_ENTRY_NOTICE; }
namespace nUserSession { class CPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES; }
namespace nUserSession { class CPacket_S2C_QUEST_CANCEL_RES; }
namespace nUserSession { class CPacket_S2C_QUEST_COMPLETE_NOTICE; }
namespace nUserSession { class CPacket_S2C_QUEST_ORDER_RES; }
namespace nUserSession { class CPacket_S2C_QUEST_PROGRESS_RES; }
namespace nUserSession { class CPacket_S2C_RAID_BOSS_PLAY_START_NOTICE; }
namespace nUserSession { class CPacket_S2C_RAID_BOSS_POINT_NOTICE; }
namespace nUserSession { class CPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES; }
namespace nUserSession { class CPacket_S2C_RANDOM_STAGE_GET_INFO_RES; }
namespace nUserSession { class CPacket_S2C_RANKING_BOARD_LIST_RES; }
namespace nUserSession { class CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES; }
namespace nUserSession { class CPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES; }
namespace nUserSession { class CPacket_S2C_RANKING_DATA_RANK_RES; }
namespace nUserSession { class CPacket_S2C_REMOVE_BLACK_LIST_RES; }
namespace nUserSession { class CPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES; }
namespace nUserSession { class CPacket_S2C_RESET_CRAFTPOINT_RES; }
namespace nUserSession { class CPacket_S2C_RESET_JOBPOINT_RES; }
namespace nUserSession { class CPacket_S2C_SEND_TELL_MSG_RES; }
namespace nUserSession { class CPacket_S2C_SESSION_STATUS_NTC; }
namespace nUserSession { class CPacket_S2C_SET_ITEM_SORTDATA_BIN_RES; }
namespace nUserSession { class CPacket_S2C_SET_PRIORITY_QUEST_RES; }
namespace nUserSession { class CPacket_S2C_STAMP_BONUS_CHECK_RES; }
namespace nUserSession { class CPacket_S2C_STAMP_BONUS_GET_LIST_RES; }
namespace nUserSession { class CPacket_S2C_START_CRAFT_RES; }
namespace nUserSession { class CPacket_S2C_START_EQUIP_GRADE_UP_RES; }
namespace nUserSession { class CPacket_S2C_STAY_INN_RES; }
namespace nUserSession { class CPacket_S2C_STAY_PENALTY_HEAL_INN_RES; }
namespace nUserSession { class CPacket_S2C_SUPPORT_POINT_GET_RATE_RES; }
namespace nUserSession { class CPacket_S2C_SUPPORT_POINT_USE_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_DELETE_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_GET_ALL_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_GET_ITEM_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_GET_LIST_DATA_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES; }
namespace nUserSession { class CPacket_S2C_SYSTEM_MAIL_SEND_NTC; }
namespace nUserSession { class CPacket_S2C_TIME_GAIN_QUEST_PLAY_START_NOTICE; }
namespace nUserSession { class CPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_PAWN_REACTION_LIST_NOTICE; }
namespace nUserSession { class CPacket_S2C_UPDATE_PAWN_REACTION_LIST_RES; }
namespace nUserSession { class CPacket_S2C_UPDATE_RENTAL_PAWN_ADVENTURE_COUNT_NOTICE; }
namespace nUserSession { class CPacket_S2C_USER_LIST_LEAVE_NTC; }
namespace nUserSession { class CPacket_S2C_USE_BAG_ITEM_NOTICE; }
namespace nUserSession { class CPacket_S2C_WEATHER_FORECAST_GET_RES; }
class sContextManager;
class sCraftManager;
class sGame;
class sNetworkExt;
class uGUILoginBonus;
class uGUIRimWarp;

// Declarations
class cCompleteQuest;
class cEditSalonInfo;
class cNetGameServer;
class cPartyMemberInfo;
class cPawnListParam;
class cPawnVoiceData;
class cSeedGameSvConnection;

// Type aliases from DWARF
using AchieveCategoryStatusVec = MtTypedArray<CDataAchieveCategoryStatus>;
using AchieveRewardCommonVec = MtTypedArray<CDataAchieveRewardCommon>;
using BOOL = int;
using BorderRewardRecordVec = MtTypedArray<CDataBorderRewardRecord>;
using C2SChangeCharacterEquipInfoVec = MtTypedArray<CDataC2SChangeCharacterEquipInfo>;
using CArisenProfile = CDataArisenProfile;
using CCharacterInfo = CDataCharacterInfo;
using CCharacterJobData = CDataCharacterJobData;
using CCharacterListElement = CDataCharacterListElement;
using CCharacterSearchParam = CDataCharacterSearchParam;
using CCharacterSearchParameter = CDataCharacterSearchParameter;
using CCheatInfo = CDataCheatInfo;
using CClanMemberInfo = CDataClanMemberInfo;
using CClanParam = CDataClanParam;
using CClanScoutEntryInviteInfo = CDataClanScoutEntryInviteInfo;
using CClanScoutEntryParam = CDataClanScoutEntryParam;
using CClanSearchParam = CDataClanSearchParam;
using CClanUserParam = CDataClanUserParam;
using CClientPartyListInfo = CDataClientPartyListInfo;
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CContextBase = CDataContextBase;
using CContextPawnInfo = CDataContextPawnInfo;
using CContextPlayerInfo = CDataContextPlayerInfo;
using CContextResist = CDataContextResist;
using CContextSetAdditional = CDataContextSetAdditional;
using CContextSetBase = CDataContextSetBase;
using CContextSetInfo = CDataContextSetInfo;
using CEditInfo = CDataEditInfo;
using CEntryBoardItemSearchParameter = CDataEntryBoardItemSearchParameter;
using CEntryItem = CDataEntryItem;
using CEntryItemParam = CDataEntryItemParam;
using CFriendInfo = CDataFriendInfo;
using CGameServerListInfo = CDataGameServerListInfo;
using CLoadingInfoSchedule = CDataLoadingInfoSchedule;
using CLobbyInfo = CDataLobbyInfo;
using CLobbyMemberInfo = CDataLobbyMemberInfo;
using CMailAttachmentList = CDataMailAttachmentList;
using CMailInfo = CDataMailInfo;
using CMatchingProfile = CDataMatchingProfile;
using COmData = CDataOmData;
using COrbGainExtendParam = CDataOrbGainExtendParam;
using CPartyListInfo = CDataPartyListInfo;
using CPartyMember = CDataPartyMember;
using CPartyMemberMinimum = CDataPartyMemberMinimum;
using CPartyQuestProgressInfo = CDataPartyQuestProgressInfo;
using CPartySearchParameter = CDataPartySearchParameter;
using CPawnInfo = CDataPawnInfo;
using CPawnListData = CDataPawnListData;
using CPawnSearchParameter = CDataPawnSearchParameter;
using CQuestPointDetail = CDataQuestPointDetail;
using CQuickMatchSearchParameter = CDataQuickMatchSearchParameter;
using CQuickPartyMatching = CDataQuickPartyMatching;
using CRaidBossUploadInfo = CDataRaidBossUploadInfo;
using CStageLayoutID = CDataStageLayoutID;
using CStatusInfo = CDataStatusInfo;
using CWorldInfo = CDataWorldInfo;
using ChangeEquipJobItemVec = MtTypedArray<CDataChangeEquipJobItem>;
using CharacterListElementVec = MtTypedArray<CDataCharacterListElement>;
using CharacterListInfoVec = MtTypedArray<CDataCharacterListInfo>;
using CharacterMsgSetVec = MtTypedArray<CDataCharacterMsgSet>;
using ClanHistoryElementVec = MtTypedArray<CDataClanHistoryElement>;
using ClanJoinRequestVec = MtTypedArray<CDataClanJoinRequest>;
using ClanMemberInfoVec = MtTypedArray<CDataClanMemberInfo>;
using ClanScoutEntryInviteInfoVec = MtTypedArray<CDataClanScoutEntryInviteInfo>;
using ClanScoutEntrySearchResultVec = MtTypedArray<CDataClanScoutEntrySearchResult>;
using ClanSearchResultVec = MtTypedArray<CDataClanSearchResult>;
using ClientPartyListInfoVec = MtTypedArray<CDataClientPartyListInfo>;
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using CommonU8Vec = MtTypedArray<CDataCommonU8>;
using CommunicationShortCutVec = MtTypedArray<CDataCommunicationShortCut>;
using CommunityCharacterBaseInfoVec = MtTypedArray<CDataCommunityCharacterBaseInfo>;
using CraftColorantVec = MtTypedArray<CDataCraftColorant>;
using CraftElementVec = MtTypedArray<CDataCraftElement>;
using CraftMaterialVec = MtTypedArray<CDataCraftMaterial>;
using CraftSupportPawnIDVec = MtTypedArray<CDataCraftSupportPawnID>;
using CycleContentsStateListVec = MtTypedArray<CDataCycleContentsStateList>;
using DLCLineupBoughtVec = MtTypedArray<CDataDLCLineupBought>;
using DLCLineupHistoryVec = MtTypedArray<CDataDLCLineupHistory>;
using DebugEnemySetPresetReqVec = MtTypedArray<CDataDebugEnemySetPresetReq>;
using EntryItemVec = MtTypedArray<CDataEntryItem>;
using EntryMemberDataVec = MtTypedArray<CDataEntryMemberData>;
using EntryRecruitDataVec = MtTypedArray<CDataEntryRecruitData>;
using EntryRecruitJobVec = MtTypedArray<CDataEntryRecruitJob>;
using EquipElementParamVec = MtTypedArray<CDataEquipElementParam>;
using EquipJobItemVec = MtTypedArray<CDataEquipJobItem>;
using FriendInfoVec = MtTypedArray<CDataFriendInfo>;
using FurnitureLayoutDataVec = MtTypedArray<CDataFurnitureLayoutData>;
using GatheringItemElementVec = MtTypedArray<CDataGatheringItemElement>;
using GatheringItemGetRequestVec = MtTypedArray<CDataGatheringItemGetRequest>;
using GetDispelItemVec = MtTypedArray<CDataGetDispelItem>;
using GetRewardBoxItemVec = MtTypedArray<CDataGetRewardBoxItem>;
using HistoryElementVec = MtTypedArray<CDataHistoryElement>;
using ItemListVec = MtTypedArray<CDataItemList>;
using ItemStorageIndicateNumVec = MtTypedArray<CDataItemStorageIndicateNum>;
using ItemUIDListVec = MtTypedArray<CDataItemUIDList>;
using JobChangeInfoVec = MtTypedArray<CDataJobChangeInfo>;
using JobOrbTreeStatusVec = MtTypedArray<CDataJobOrbTreeStatus>;
using LightQuestListVec = MtTypedArray<CDataLightQuestList>;
using LobbyMemberInfoVec = MtTypedArray<CDataLobbyMemberInfo>;
using LostPawnListVec = MtTypedArray<CDataLostPawnList>;
using LotQuestListVec = MtTypedArray<CDataLotQuestList>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MailInfoVec = MtTypedArray<CDataMailInfo>;
using MainQuestListVec = MtTypedArray<CDataMainQuestList>;
using MoveItemUIDFromToVec = MtTypedArray<CDataMoveItemUIDFromTo>;
using OrbPageStatusVec = MtTypedArray<CDataOrbPageStatus>;
using OrderConditionInfoVec = MtTypedArray<CDataOrderConditionInfo>;
using PartyListInfoVec = MtTypedArray<CDataPartyListInfo>;
using PartyMemberVec = MtTypedArray<CDataPartyMember>;
using PawnHistoryVec = MtTypedArray<CDataPawnHistory>;
using PawnHpVec = MtTypedArray<CDataPawnHp>;
using PawnListVec = MtTypedArray<CDataPawnList>;
using PawnReactionVec = MtTypedArray<CDataPawnReaction>;
using QuestContentsSituationInfoVec = MtTypedArray<CDataQuestContentsSituationInfo>;
using QuestProcessStateVec = MtTypedArray<CDataQuestProcessState>;
using RankingRewardRecordVec = MtTypedArray<CDataRankingRewardRecord>;
using RegisterdPawnListVec = MtTypedArray<CDataRegisterdPawnList>;
using RentedPawnListVec = MtTypedArray<CDataRentedPawnList>;
using RewardBoxRecordVec = MtTypedArray<CDataRewardBoxRecord>;
using S2CCharacterEquipInfoVec = MtTypedArray<CDataS2CCharacterEquipInfo>;
using SelectItemInfoVec = MtTypedArray<CDataSelectItemInfo>;
using SetQuestListVec = MtTypedArray<CDataSetQuestList>;
using ShortCutVec = MtTypedArray<CDataShortCut>;
using StageInfoVec = MtTypedArray<CDataStageInfo>;
using StorageItemUIDListVec = MtTypedArray<CDataStorageItemUIDList>;
using TimeLimitedQuestListVec = MtTypedArray<CDataTimeLimitedQuestList>;
using TutorialQuestListVec = MtTypedArray<CDataTutorialQuestList>;
using UseSupportPointVec = MtTypedArray<CDataUseSupportPoint>;
using WorldManageQuestListVec = MtTypedArray<CDataWorldManageQuestList>;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using b8 = bool;
using cCompleteQuestList = MtTypedArray<cCompleteQuest>;
using cPartyMemberInfoVec = MtTypedArray<cPartyMemberInfo>;
using cPawnListVec = MtTypedArray<cPawnListParam>;
using cPawnVoiceList = MtTypedArray<cPawnVoiceData>;
using f32 = float;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cCompleteQuest : public MtObject
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
    explicit cCompleteQuest();
public:
    u32 m_unScheduleId;  // offset: 0x8
    static MyDTI DTI;
};

class cEditSalonInfo : public MtObject
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
    cEditSalonInfo();
    void clear();
    void setEditPrice(s32 price);
    s32 getEditPrice() const;
private:
    s32 mEditPrice;  // offset: 0x8
public:
    static MyDTI DTI;
};

class cPartyMemberInfo : public MtObject
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
    explicit cPartyMemberInfo();
    bool isConnect();
    bool isSync(nNetSv::PARTY_SYNC_FLAG);
    void setIsSync(nNetSv::PARTY_SYNC_FLAG, bool);
public:
    CCharacterListElement m_CharacterListElement;  // offset: 0x8
    u32 m_unPawnId;  // offset: 0x70
    u32 m_nMemberIndex;  // offset: 0x74
    u8 m_ucMemberType;  // offset: 0x78
    u8 m_ucSessionStatus;  // offset: 0x79
    u8 m_ucJoinState;  // offset: 0x7a
    bool m_bIsLeader;  // offset: 0x7b
    bool m_bIsPawn;  // offset: 0x7c
    bool m_bIsPlayEntry;  // offset: 0x7d
    bool m_bIsInviteEntry;  // offset: 0x7e
    bool mIsConnect;  // offset: 0x7f
    bool mIsSync[8];  // offset: 0x80
    static MyDTI DTI;
};

class cPawnListParam : public MtObject
{
public:
    enum PAWN_STATE
    {
        PAWN_STATE_NONE = 0,
        PAWN_STATE_LOST = 1,
        PAWN_STATE_CRAFT = 2,
        PAWN_STATE_EXPEDITION_SALLY = 3,
        PAWN_STATE_EXPEDITION_RETURN = 4,
        PAWN_STATE_PARTY = 5,
        PAWN_STATE_REGISTERD = 6,
        PAWN_STATE_MAX = 7,
    };
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
    explicit cPawnListParam();
    explicit cPawnListParam(const s32, const u32, const char*, const u8, const u8, const u8, const u8, const u8, const u32, const u64, const CPawnListData&, nUserSession::CPacket_S2C_GET_MYPAWN_DATA_RES*, nUserSession::CPacket_S2C_GET_REGISTERED_PAWN_DATA_RES*, nUserSession::CPacket_S2C_GET_RENTED_PAWN_DATA_RES*);
    virtual ~cPawnListParam();
    u8 getState() const;
    void setState(u8 State);
public:
    s32 m_nPawnId;  // offset: 0x8
    u32 m_unSlotNo;  // offset: 0xc
    MtString m_wstrName;  // offset: 0x10
    u8 m_ucSex;  // offset: 0x18
protected:
    u8 m_ucState;  // offset: 0x19
public:
    u8 m_ucShareRange;  // offset: 0x1a
    u8 m_ucCraftCount;  // offset: 0x1b
    u8 m_ucAdventureCount;  // offset: 0x1c
    u32 m_unRentalCost;  // offset: 0x20
    u64 m_ullUpdated;  // offset: 0x28
    CPawnListData m_PawnListData;  // offset: 0x30
    nUserSession::CPacket_S2C_GET_MYPAWN_DATA_RES* mpMyCacheData;  // offset: 0x78
    nUserSession::CPacket_S2C_GET_REGISTERED_PAWN_DATA_RES* mpRegisterdCacheData;  // offset: 0x80
    nUserSession::CPacket_S2C_GET_RENTED_PAWN_DATA_RES* mpRentedCacheData;  // offset: 0x88
    static MyDTI DTI;
};

class cPawnVoiceData : public MtObject
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
    cPawnVoiceData();
public:
    u32 mVoiceType;  // offset: 0x8
    u32 mVoiceID;  // offset: 0xc
    bool mIsValid;  // offset: 0x10
    bool mIsGp;  // offset: 0x11
    bool mIsPitchChange;  // offset: 0x12
    static MyDTI DTI;
};

class cSeedGameSvConnection : public cSeedServerConnection
{
    // inferred: cNetGameServer::sendSetActiveQuest names cSeedGameSvConnection::mGuardData.mIsLoginSuccess
    friend class cNetGameServer;
public:
    class MyDTI;
    struct cGuardData;
public:
    using THISCLASS = cSeedGameSvConnection;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct cGuardData
    {
    public:
        MT_CHAR mSessionKey[64];  // offset: 0x0
        bool mIsLoginWithSessionKey;  // offset: 0x40
        bool mIsLoginSuccess;  // offset: 0x41
    };
private:
    cSeedGameSvConnection();
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cSeedGameSvConnection(cNetGameServer* psvt);
    cSeedGameSvConnection(cNetGameServer*, MT_CTSTR);
    void init();
    virtual ~cSeedGameSvConnection();
    virtual void initialize();  // vtable slot 6
    bool isLoginSuccess() const;
    virtual void disconnect(cSeedServerConnection::eConnStatus aNextStatus);  // vtable slot 7
private:
    cNetGameServer* getManager();
    virtual void onConnected(bool result);  // vtable slot 20
    virtual void onDisconnectedByPeer(s32 aMtNetError);  // vtable slot 21
    virtual void onSocketError(s32 aMtNetError);  // vtable slot 22
    virtual void onHandshakeDone(bool result);  // vtable slot 23
    void setLoginSuccess(bool isSuccess, MT_CTSTR sessionKey);
    void partyPawnContextNoticeCommon(const CContextBase& base, const CContextPlayerInfo& pl, const CContextPawnInfo& pawn, const CEditInfo& edit);
protected:
    virtual u32 getHandShakeSendCommandNo();  // vtable slot 25
    virtual u32 getHandShakeRecvCommandNo();  // vtable slot 26
    virtual u32 getLogoutRecvCommandNo();  // vtable slot 27
    virtual bool isCarryOver(u32 command);  // vtable slot 28
public:
    s64 calcGameTimeMSec(s64 realTime, s64 msec, bool full);
    u32 calcWeather(s64 realTime);
    u32 calcMoonAge(s64 realTime);
    u32 calcWeekDay(s64 realTime);
    const cGameTimeWeatherMoonInfo* getGameTimeWeatherMoonInfo() const;
private:
    void getSessionKeyPrivate(MT_CHAR*) const;
    void setSessionKeyPrivate(const MT_CHAR* NewValue);
    bool isLoginWithSessionKeyPrivate() const;
    void setLoginWithSessionKeyPrivate(bool NewValue);
    bool isLoginSuccessPrivate() const;
    void setLoginSuccessPrivate(bool NewValue);
public:
    MtString getCogSessionKey() const;
    void setCogSessionKey(MT_CTSTR NewValue);
    u32 getCogSessionKeyLength() const;
    u32 getCogSessionKeyCapacity() const;
    void initializeCogSessionKey();
    void releaseCogSessionKey();
protected:
    BOOL OnPacket_S2C_NONE(CPacket* pPacket);
    BOOL OnPacket_S2C_PING_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LOGIN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LOGOUT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LOGIN_ANNOUNCEMENT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MOVE_IN_SERVER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MOVE_OUT_SERVER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CRITICAL_ERROR_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SERVER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_GAME_SETTING_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_WORLD_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REAL_TIME_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DECIDE_CHARACTER_ID_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LOBBY_JOIN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_USER_LIST_JOIN_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_LOBBY_LEAVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_USER_LIST_LEAVE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SESSION_STATUS_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_LOBBY_CHAT_MSG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SEND_TELL_MSG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SEND_TELL_MSG_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_LOBBY_CHAT_MSG_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_LOBBY_DATA_MSG_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_USER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_USER_LIST_MAX_NUM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RESERVE_SERVER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_CREATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_CHARACTER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_CANCEL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_FAIL_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_SUCCESS_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_CANCEL_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_REFUSE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_PREPARE_ACCEPT_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_ENTRY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_ENTRY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_ACCEPT_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_JOIN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_JOIN_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_GET_CONTENT_NUMBER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_LEAVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_LEAVE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_MEMBER_SESSION_STATUS_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_MEMBER_KICK_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_MEMBER_KICK_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_MEMBER_LOST_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_BREAKUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_BREAKUP_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_CHANGE_LEADER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_CHANGE_LEADER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_CHANGE_HOST_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_SEARCH_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_MEMBER_SET_VALUE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_MEMBER_SET_VALUE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_REGISTER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_REGISTER_QUEST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_CANCEL_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_ENTRY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_REGISTER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_REGISTER_QUEST_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_READY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_ENTRY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_QUICK_PARTY_UNREADY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CREATE_MYPAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DELETE_MYPAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MYPAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MYPAWN_DATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REGISTERED_PAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REGISTERED_PAWN_LIST_BY_CHARACTER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REGISTERED_PAWN_DATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RENT_REGISTERED_PAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RENTED_PAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RENTED_PAWN_DATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RETURN_RENTED_PAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PARTY_PAWN_DATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_PROFILE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_HISTORY_INFO_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_TOTAL_SCORE_INFO_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_ORB_DEVOTE_INFO_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_JOIN_PARTY_MYPAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_JOIN_PARTY_RENTED_PAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_JOIN_PARTY_PAWN_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_FAVORITE_PAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_FAVORITE_PAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DELETE_FAVORITE_PAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_OFFICIAL_PAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LEGEND_PAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_LOST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_LOST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LOST_PAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LOST_PAWN_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LOST_PAWN_POINT_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LOST_PAWN_GOLDEN_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LOST_PAWN_WALLET_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RENTAL_PAWN_LOST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RENTAL_PAWN_LOST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_RENTAL_PAWN_ADVENTURE_COUNT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_PAWN_REACTION_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_PAWN_REACTION_LIST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_PAWN_SHARE_RANGE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_HISTORY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_TOTAL_SCORE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_NORA_PAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_BIN_SAVEDATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_CHARACTER_BIN_SAVEDATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_USE_BAG_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_USE_BAG_ITEM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CONSUME_STORAGE_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_USE_JOB_ITEMS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_STORAGE_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_POST_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MOVE_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_EQUIP_BIND_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_ADD_WALLET_POINT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_SUB_WALLET_POINT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_CONTENTS_RELEASE_ELEMENT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_QUEST_UNRELEASED_AREA_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASE_SET_QUEST_AREA_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_ENABLE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CYCLE_CONTENTS_ENABLE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_MASTER_DATA_RELOAD_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LIGHT_QUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SET_QUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SET_QUEST_LIST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MAIN_QUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MAIN_QUEST_LIST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MAIN_QUEST_LIST_END_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LOT_QUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_END_CONTENTS_GROUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_JOIN_LOBBY_QUEST_INFO_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MAIN_QUEST_COMPLETE_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SET_QUEST_INFO_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CYCLE_CONTENTS_NEWS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_BONUS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_ORDER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_ORDER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_PROGRESS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_PROGRESS_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_PROGRESS_WORK_SAVE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LEADER_QUEST_PROGRESS_REQUEST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHECK_QUEST_DISTRIBUTION_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_CANCEL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_CANCEL_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_COMPLETE_FLAG_CLEAR_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_COMPLETE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_QUEST_DETAIL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_QUEST_COMPLETE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PRIORITY_QUEST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CANCEL_PRIORITY_QUEST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PRIORITY_QUEST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PRIORITY_QUEST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_FORT_DEFENSE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_DUNGEON_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_RAID_BOSS_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CYCLE_CONTENTS_END_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CYCLE_CONTENTS_STATE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CYCLE_CONTENTS_SITUATION_INFO_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_ENTRY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_ENTRY_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_ENTRY_CANCEL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_ENTRY_CANCEL_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_START_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_TIME_GAIN_QUEST_PLAY_START_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_START_TIMER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_START_TIMER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_ADD_TIMER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_STOP_TIMER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_RESTART_TIMER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_TIMEUP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_INTERRUPT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_INTERRUPT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_INTERRUPT_ANSWER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_INTERRUPT_RESULT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_FORCE_INTERRUPT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_END_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PLAY_END_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_TIMER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CYCLE_CONTENTS_PLAY_START_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_FORT_DEFENSE_PLAY_START_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_DUNGEON_PLAY_START_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_DUNGEON_BATTLE_SUCCESS_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_DUNGEON_BATTLE_FAIL_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_RAID_BOSS_PLAY_START_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CYCLE_CONTENTS_PLAY_END_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CYCLE_CONTENTS_PLAY_END_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CYCLE_CONTENTS_POINT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CYCLE_CONTENTS_NOW_POINT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RAID_BOSS_POINT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CYCLE_CONTENTS_REWARD_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_DUNGEON_REWARD_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_DUNGEON_REWARD_SELECT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_PHASE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_INFO_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RECV_BINARY_MSG_ALL_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_RECV_BINARY_MSG_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SEND_LEADER_WAIT_ORDER_QUEST_LIST_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_QUEST_LOG_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_STAGE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_AREA_CHANGE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENEMY_BREAK_REGION_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ENEMY_SET_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENEMY_KILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENEMY_DIE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_ENEMY_GROUP_DESTROY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_ENEMY_GROUP_RESET_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENEMY_SUB_GROUP_APPEAR_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GATHERING_ENEMY_APPEAR_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ITEM_SET_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_GATHERING_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_GATHERING_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENEMY_STAGE_BOSS_ANNIHILATE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_DROP_ITEM_SET_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_DROP_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_DROP_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_RAID_BOSS_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RAID_BOSS_INFO_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_RAID_BOSS_DAMAGE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_RAID_BOSS_DEAD_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_POP_DROP_ITEM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENEMY_REPOP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENCOUNTER_PAWN_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_TRANING_ROOM_SET_ENEMY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_OM_INSTANT_KEY_VALUE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_OM_INSTANT_KEY_VALUE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_OM_INSTANT_KEY_VALUE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_Get_OM_INSTANT_KEY_VALUE_ALL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_EXCHANGE_OM_INSTANT_KEY_VALUE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASE_WARP_POINT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_WARP_POINT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RELEASE_WARP_POINT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_WARP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_FAVORITE_WARP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_REGISTER_FAVORITE_WARP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LEADER_WARP_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_WARP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_WARP_POINT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_AREA_WARP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_COMMUNITY_CHARACTER_STATUS_UPDATE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_ONLINE_STATUS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_FRIEND_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_APPLY_FRIEND_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_APPLY_FRIEND_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_APPROVE_FRIEND_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_APPROVE_FRIEND_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_REMOVE_FRIEND_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_REMOVE_FRIEND_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_REGISTER_FAVORITE_FRIEND_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CANCEL_FRIEND_APPLICATION_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CANCEL_FRIEND_APPLICATION_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RECENT_CHARACTER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_BLACK_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ADD_BLACK_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_REMOVE_BLACK_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_SEND_MSG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_SEND_MSG_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_GET_MEMBER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_LEAVE_CHARACTER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_LEAVE_CHARACTER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_KICK_CHARACTER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_KICK_CHARACTER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GROUP_CHAT_BREAKUP_GROUP_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LEARN_NORMAL_SKILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LEARN_SKILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LEARN_ABILITY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LEARN_PAWN_NORMAL_SKILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LEARN_PAWN_SKILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_LEARN_PAWN_ABILITY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LEARNED_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LEARNED_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_SKILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_ABILITY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_OFF_SKILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_OFF_ABILITY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PAWN_SKILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PAWN_ABILITY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_OFF_PAWN_SKILL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_OFF_PAWN_ABILITY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SET_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SET_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CURRENT_SET_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CURRENT_SET_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_CURRENT_SET_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_CURRENT_SET_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RELEASE_SKILL_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RELEASE_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_REGISTER_PRESET_ABILITY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PRESET_ABILITY_NAME_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PRESET_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PRESET_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PAWN_PRESET_ABILITY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ABILITY_COST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_ABILITY_COST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ACQUIREMENT_LEARN_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_NORMAL_SKILL_LEARN_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CUSTOM_SKILL_SET_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_ABILITY_SET_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_NORMAL_SKILL_LEARN_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_CUSTOM_SKILL_SET_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_ABILITY_SET_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PRESET_ABILITY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PRESET_PAWN_ABILITY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SHOP_GOODS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BUY_SHOP_GOODS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SELL_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_STAY_PRICE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_STAY_INN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_STAY_PENALTY_HEAL_INN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_MASTER_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_REWARD_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_AREA_RANK_UP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_SUPPLY_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_SUPPLY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_POINT_DEBUG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_RELEASE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BUY_AREA_QUEST_HINT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SPOT_INFO_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AREA_BASE_INFO_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_AREA_POINT_UP_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_AREA_RANK_UP_READY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_JOB_MASTER_ORDER_PROGRESS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ACTIVATE_JOB_ORDER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_JOB_ORDER_COMPLETE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_ADD_JOB_ORDER_PROGRESS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ALL_ORB_ELEMENT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASE_ORB_ELEMENT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASE_PAWN_ORB_ELEMENT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ORB_GAIN_EXTEND_PARAM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GAIN_CHARACTER_PARAM_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GAIN_PAWN_PARAM_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_EXTEND_ITEM_SLOT_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_EXTEND_EQUIP_SLOT_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_EXTEND_MAIN_PAWN_SLOT_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_EXTEND_SUPPORT_PAWN_SLOT_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_PROFILE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MY_CHARACTER_PROFILE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_STATUS_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_SKILL_INFO_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_HISTORY_INFO_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_ACHIEVEMENT_INFO_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_ORB_DEVOTE_INFO_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_BINARY_STATUS_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_ARISEN_PROFILE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ARISEN_PROFILE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PAWN_PROFILE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_PAWN_PROFILE_COMMENT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_ARISEN_PROFILE_SHARE_RANGE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_RETURN_LOCATION_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ACHIEVEMENT_COMPLETE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ACHIEVEMENT_RECEIVABLE_REWARD_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_ACHIEVEMENT_REWARD_RECEIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_EVENT_ACHIEVEMENT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_EVENT_ACHIEVEMENT_CATEGORY_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_INSTANT_KEY_VALUE_UL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_INSTANT_KEY_VALUE_UL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_INSTANT_KEY_VALUE_STR_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_INSTANT_KEY_VALUE_STR_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_INSTANCE_AREA_RESET_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_GP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_GP_DETAIL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_GP_PERIOD_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CAP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_CAP_TO_GP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_COG_GET_ID_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_DISPLAY_BUY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_GET_ITEM_LINEUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_GET_PAWN_LINEUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_GET_PAWN_VOICE_LINEUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_GET_PICKUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_GET_CAP_CHARGE_URL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_GET_VALID_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_USE_FROM_AVAILABLE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_START_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_EXTEND_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_END_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_GET_VERSION_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_START_PARTY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_COURSE_END_PARTY_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_EDIT_VOICE_GET_BUY_HISTORY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_EDIT_GET_VOICE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_EDIT_GET_GP_PRICE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_CAN_BUY_PAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GP_SHOP_CAN_BUY_PAWN_VOICE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_JOB_EXP_UP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_JOB_LEVEL_UP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_JOB_LEVEL_UP_MEMBER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_JOB_LEVEL_UP_OTHER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_JOB_EXP_UP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_JOB_LEVEL_UP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_JOB_LEVEL_UP_MEMBER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_CHARACTER_JOB_POINT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_PAWN_JOB_POINT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_PLAY_POINT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHARACTER_EQUIP_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_CHARACTER_EQUIP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_CHARACTER_STORAGE_EQUIP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PAWN_EQUIP_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_PAWN_EQUIP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_PAWN_STORAGE_EQUIP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_CHARACTER_EQUIP_JOB_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_PAWN_EQUIP_JOB_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_CHARACTER_EQUIP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_CHARACTER_EQUIP_LOBBY_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_PAWN_EQUIP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_CHARACTER_EQUIP_JOB_ITEM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_PAWN_EQUIP_JOB_ITEM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_HIDE_CHARACTER_HEAD_ARMOR_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_HIDE_PAWN_HEAD_ARMOR_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_HIDE_CHARACTER_LANTERN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_HIDE_PAWN_LANTERN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_EQUIP_HIDE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_EQUIP_PRESET_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_EQUIP_PRESET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_EQUIP_PRESET_NAME_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REWARD_BOX_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REWARD_BOX_LIST_NUM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_REWARD_BOX_LIST_NUM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REWARD_BOX_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DELIVER_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DELIVER_ITEM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_DECIDE_DELIVERY_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_MAIN_QUEST_JUMP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_MAIN_QUEST_JUMP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_QUEST_RESET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_QUEST_RESET_ALL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_CYCLE_CONTENTS_POINT_UPLOAD_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_SET_QUEST_FLAG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_GET_QUEST_FLAG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_QUEST_COMPLETE_NUM_CHANGE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_ENEMY_SET_PRESET_FIX_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_START_CRAFT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_FINISH_CRAFT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_PRODUCT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CANCEL_CRAFT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_START_EQUIP_GRADE_UP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_START_ATTACH_ELEMENT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_START_DETACH_ELEMENT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_START_EQUIP_COLOR_CHANGE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CRAFT_EXP_UP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CRAFT_RANK_UP_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CRAFT_SKILL_UP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LIMIT_BREAK_RECIPE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_EQUIP_GRADE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_EQUIP_ELEMENT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_EQUIP_COLOR_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_OBJECTIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_MATCHING_PROFILE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MATCHING_PROFILE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_MATCHING_PROFILE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_CHARACTER_ITEM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_SHORTCUT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SHORTCUT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_COMMUNICATION_SHORTCUT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_COMMUNICATION_SHORTCUT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_MESSAGE_SET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_MESSAGE_SET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_CAN_CREATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_CREATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_UPDATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_GET_MEMBER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_GET_MY_MEMBER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SEARCH_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_GET_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_REGISTER_JOIN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_CANCEL_JOIN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_CANCEL_JOIN_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_APPROVE_JOIN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_LEAVE_MEMBER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_EXPEL_MEMBER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_JOIN_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_NEGOTIATE_MASTER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SET_MEMBER_RANK_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_GET_MEMBER_NUM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_REGISTER_JOIN_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_JOIN_MEMBER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_JOIN_SELF_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_JOIN_DISAPPROVE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_LEAVE_MEMBER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_NEGOTIATE_MASTER_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SET_MEMBER_RANK_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_UPDATE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SETTING_UPDATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_INVITE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_INVITE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_INVITE_ACCEPT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_QUEST_CLEAR_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_POINT_ADD_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_LEVEL_UP_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_UPDATE_COMMON_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_REGISTER_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_INVITE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_DISAPPROVE_INVITE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_CANCEL_INVITE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_GET_MY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_APPROVE_INVITED_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_GET_MY_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SCOUT_ENTRY_INVITE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_GET_HISTORY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_BASE_GET_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_BASE_RELEASE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SHOP_GET_BUFF_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SHOP_BUY_FUNCTION_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SHOP_BUY_BUFF_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_SHOP_BUY_ITEM_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_BASE_RELEASE_STATE_UPDATE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_RANDOM_STAGE_GET_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_JOB_CHANGE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_JOB_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_JOB_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_PAWN_JOB_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHANGE_PAWN_JOB_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_CREATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_RECREATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_RECREATE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_ENTRY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_CHANGE_MEMBER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_READY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_PARTY_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_FORCE_START_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_INFO_MYSELF_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_INFO_LOCK_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_INFO_CHANGE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_INFO_CHANGE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_INVITE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_ENTRY_BOARD_ITEM_INVITE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LOBBY_PLAYER_CONTEXT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_LOBBY_PLAYER_CONTEXT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PARTY_PLAYER_CONTEXT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PARTY_PLAYER_CONTEXT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ALL_PLAYER_CONTEXT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ALL_PLAYER_CONTEXT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PARTY_MYPAWN_CONTEXT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PARTY_MYPAWN_CONTEXT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PARTY_RENTED_PAWN_CONTEXT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PARTY_RENTED_PAWN_CONTEXT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SET_CONTEXT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_CONTEXT_BASE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_CONTEXT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_MASTER_CHANGE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_MASTER_INFO_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_MASTER_THROW_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MASTER_THROW_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_START_LANTERN_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_FINISH_LANTERN_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_START_LANTERN_OTHER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_FINISH_LANTERN_OTHER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_START_DEATH_PENALTY_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_FINISH_DEATH_PENALTY_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_START_DEATH_PENALTY_OTHER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_FINISH_DEATH_PENALTY_OTHER_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_GET_CHARACTER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_GET_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_GET_ITEM_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_GET_ITEM_HISTORY_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_EXHIBIT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_RE_EXHIBIT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_CANCEL_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_PROCEEDS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_PROCEEDS_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_RECEIVE_PROCEEDS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_GET_ITEM_PRICE_LIMIT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_GET_TAX_PRICE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MAIL_GET_LIST_HEAD_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MAIL_GET_LIST_DATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MAIL_GET_LIST_FOOT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MAIL_GET_TEXT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MAIL_DELETE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MAIL_SEND_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MAIL_SEND_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SYSTEM_MAIL_GET_LIST_HEAD_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SYSTEM_MAIL_GET_LIST_DATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SYSTEM_MAIL_GET_LIST_FOOT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SYSTEM_MAIL_GET_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SYSTEM_MAIL_GET_ALL_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SYSTEM_MAIL_DELETE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SYSTEM_MAIL_SEND_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_RANKING_BOARD_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RANKING_DATA_RANK_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RANKING_DATA_CHARACTER_ID_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DEBUG_COMMAND_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_TIME_UPDATE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_WEATHER_UPDATE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_WEATHER_FORECAST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_POINT_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_GOLDEN_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_PENALTY_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_REVIVE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_POINT_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_GOLDEN_REVIVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_REVIVE_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REVIVE_CHARGEABLE_TIME_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARGE_REVIVE_POINT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_REVIVE_POINT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_REVIVE_POINT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_GACHA_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GACHA_BUY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_UNLOCKED_EDIT_PARTS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_UNLOCKED_PAWN_EDIT_PARTS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_CHARACTER_EDIT_PARAM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_PAWN_EDIT_PARAM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_EDIT_PARAM_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_LOADING_GET_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GAME_SERVER_CERT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_S2C_CLIENT_CHALLENGE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_STAMP_BONUS_GET_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_STAMP_BONUS_CHECK_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_STAMP_BONUS_RECIEVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_STAMP_BONUS_ADD_TOTAL_NUM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_NG_WORD_GET_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_REPORT_SITE_GET_ADDRESS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PHOTO_GET_AUTH_ADDRESS_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_EVENT_CODE_INPUT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_URL_GET_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DLC_GET_BOUGHT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DLC_USE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_DLC_GET_HISTORY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_COG_LOGIN_SKIP_FLAG_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_COG_LOGIN_SKIP_DISABLE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_COG_GET_SESSION_KEY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_COMMUNITY_CHARACTER_STATUS_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GAME_TIME_GET_BASEINFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GAME_TIME_BASEINFO_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_WEATHER_LOOP_SCHEDULE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_MOON_LOOP_SCHEDULE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_EJECTION_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SUPPORT_POINT_GET_RATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SUPPORT_POINT_USE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ITEM_SORTDATA_BIN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_ITEM_SORTDATA_BIN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ITEM_STORAGE_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_DISPEL_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_EXCHANGE_DISPEL_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_NETCAFE_ERROR_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_RESET_JOBPOINT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RESET_CRAFTPOINT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CHEAT_INFO_REQ(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_SETTING_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CRAFT_TIME_SAVE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_NORA_PAWN_DATA_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_IR_COLLECTION_VALUE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CHARACTER_SEARCH_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MY_ROOM_RELEASE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_FURNITURE_LIST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_FURNITURE_LAYOUT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_MY_ROOM_BGM_UPDATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASED_CRAFT_RECIPE_LIST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_OTHER_ROOM_LAYOUT_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTNER_PAWN_SET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASED_EDIT_PARTS_LIST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASED_EMOTION_LIST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASED_PAWN_TALK_LIST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_LIKABILITY_REWARD_LIST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_LIKABILITY_REWARD_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_LIKABILITY_RELEASED_REWARD_LIST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_LIKABILITY_UP_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_RECIPE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_RECIPE_DESIGNATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_GRADEUP_RECIPE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_JOB_ORB_TREE_STATUS_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_RELEASE_JOB_ORB_ELEMENT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CAPLINK_ACHIEVE_REWARD_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_SET_CAPLINK_ACHIEVE_USER_STATE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SWITCH_STORAGE_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_OPEN_UI_NTC(CPacket* pPacket);
    BOOL OnPacket_S2C_SERVER_UI_COMMAND_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_DISPEL_ITEM_SETTING_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BOX_GACHA_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BOX_GACHA_BUY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BOX_GACHA_RESET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_BOX_GACHA_DRAW_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_CRAFT_LOCKED_ELEMENT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_CONCIERGE_UPDATE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_PARTNER_PAWN_LIST_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CLAN_PARTNER_PAWN_DATA_GET_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_CRAFT_SKILL_ANALYZE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_GET_SALLY_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_CHARGE_SALLY_COUNT_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_SALLY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_CHANGE_GOLDEN_SALLY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_CANCEL_SALLY_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_GET_REWARD_DROP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_GET_REWARD_DROP_ITEM_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_PAWN_EXPEDITION_GET_REWARD_DROP_ITEM_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_EXP_MODE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_UPDATE_EXP_MODE_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_GET_PLAY_POINT_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES(CPacket* pPacket);
    BOOL OnPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES(CPacket* pPacket);
    virtual BOOL callOnPacketFunc(u32 index, CPacket* pPacket);  // vtable slot 18
    virtual u32 getOnPacketFuncNum();  // vtable slot 19
public:
    s32 Send_C2S_NONE();
    s32 Send_C2S_PING_REQ(const MtTypedArray<CDataCheatInfo>& in_Info);
    s32 Send_C2S_LOGIN_REQ(const char* in_strSessionKey, u8 in_Platform, u32 in_ClientVersion);
    s32 Send_C2S_LOGOUT_REQ();
    s32 Send_C2S_GET_LOGIN_ANNOUNCEMENT_REQ();
    s32 Send_C2S_MOVE_IN_SERVER_REQ(const char* in_strSessionKey, u8 in_Platform, u32 in_ClientVersion);
    s32 Send_C2S_MOVE_OUT_SERVER_REQ();
    s32 Send_C2S_GET_SERVER_LIST_REQ();
    s32 Send_C2S_GET_GAME_SETTING_REQ();
    s32 Send_C2S_GET_WORLD_INFO_REQ(u32 in_WorldID);
    s32 Send_C2S_SET_WORLD_INFO_REQ(u32 in_WorldID, const CWorldInfo& in_WorldInfo);
    s32 Send_C2S_GET_REAL_TIME_REQ();
    s32 Send_C2S_DECIDE_CHARACTER_ID_REQ(u32 in_CharacterID);
    s32 Send_C2S_LOBBY_JOIN_REQ(u32 in_CharacterID, u32 in_UserListMaxNum);
    s32 Send_C2S_LOBBY_LEAVE_REQ();
    s32 Send_C2S_LOBBY_CHAT_MSG_REQ(u8 in_Type, u32 in_TargetID, const char* in_strMessage);
    s32 Send_C2S_SEND_TELL_MSG_REQ(const CCommunityCharacterBaseInfo& in_CharacterInfo, const char* in_strMessage);
    s32 Send_C2S_LOBBY_DATA_MSG_REQ(u8 in_Type, u32 in_CharacterID, const MtMemoryStream& in_Data);
    s32 Send_C2S_GET_USER_LIST_REQ();
    s32 Send_C2S_USER_LIST_MAX_NUM_REQ(u32 in_MaxNum);
    s32 Send_C2S_RESERVE_SERVER_REQ(u16 in_GameServerUniqueID, u8 in_Type, u8 in_RotationServerID, const MtTypedArray<CDataCommonU32>& in_ReserveInfoList);
    s32 Send_C2S_PARTY_CREATE_REQ();
    s32 Send_C2S_PARTY_INVITE_REQ(u16 in_ServerId, u32 in_PartyId, u32 in_Sequence, u8 in_PartyJoinNum);
    s32 Send_C2S_PARTY_INVITE_CHARACTER_REQ(u32 in_CharacterId);
    s32 Send_C2S_PARTY_INVITE_CANCEL_REQ(u16 in_ServerId, u32 in_PartyId);
    s32 Send_C2S_PARTY_INVITE_REFUSE_REQ();
    s32 Send_C2S_PARTY_INVITE_PREPARE_ACCEPT_REQ();
    s32 Send_C2S_PARTY_INVITE_ENTRY_REQ();
    s32 Send_C2S_PARTY_INVITE_ENTRY_CANCEL_REQ();
    s32 Send_C2S_PARTY_JOIN_REQ(u32 in_PartyId);
    s32 Send_C2S_PARTY_GET_CONTENT_NUMBER_REQ();
    s32 Send_C2S_PARTY_LEAVE_REQ();
    s32 Send_C2S_PARTY_MEMBER_KICK_REQ(u8 in_MemberIndex);
    s32 Send_C2S_PARTY_BREAKUP_REQ();
    s32 Send_C2S_PARTY_CHANGE_LEADER_REQ(u32 in_CharacterID);
    s32 Send_C2S_PARTY_SEARCH_REQ(const CPartySearchParameter& in_SearchParam);
    s32 Send_C2S_PARTY_MEMBER_SET_VALUE_REQ(u8 in_Index, u8 in_Value);
    s32 Send_C2S_QUICK_PARTY_REGISTER_REQ(u32 in_ContentType, u32 in_Num, const CQuickPartyMatching& in_QuickPartyMatching);
    s32 Send_C2S_QUICK_PARTY_REGISTER_QUEST_REQ(u32 in_QuestScheduleId, const CQuickPartyMatching& in_QuickPartyMatching);
    s32 Send_C2S_QUICK_PARTY_CANCEL_NTC();
    s32 Send_C2S_QUICK_PARTY_ENTRY_REQ();
    s32 Send_C2S_QUICK_PARTY_REFUSE_NTC();
    s32 Send_C2S_CREATE_MYPAWN_REQ(u8 in_SlotNo, const CPawnInfo& in_PawnInfo);
    s32 Send_C2S_DELETE_MYPAWN_REQ(u8 in_SlotNo, b8 in_IsKeepEquip);
    s32 Send_C2S_GET_MYPAWN_LIST_REQ();
    s32 Send_C2S_GET_MYPAWN_DATA_REQ(u8 in_SlotNo, s32 in_PawnId);
    s32 Send_C2S_GET_REGISTERED_PAWN_LIST_REQ(const CPawnSearchParameter& in_SearchParam);
    s32 Send_C2S_GET_REGISTERED_PAWN_LIST_BY_CHARACTER_REQ(const MtTypedArray<CDataCommonU32>& in_CharacterIdList);
    s32 Send_C2S_GET_REGISTERED_PAWN_DATA_REQ(s32 in_PawnId);
    s32 Send_C2S_RENT_REGISTERED_PAWN_REQ(u8 in_SlotNo, s32 in_RequestPawnId, u64 in_Updated, u32 in_RentalCost);
    s32 Send_C2S_GET_RENTED_PAWN_LIST_REQ();
    s32 Send_C2S_GET_RENTED_PAWN_DATA_REQ(u8 in_SlotNo, s32 in_PawnId);
    s32 Send_C2S_RETURN_RENTED_PAWN_REQ(u8 in_SlotNo, const MtTypedArray<CDataPawnFeedback>& in_PawnFeedbackList);
    s32 Send_C2S_GET_PARTY_PAWN_DATA_REQ(u32 in_CharacterId, u32 in_PawnId, b8 in_IsPawnProfile);
    s32 Send_C2S_JOIN_PARTY_MYPAWN_REQ(u8 in_SlotNo);
    s32 Send_C2S_JOIN_PARTY_RENTED_PAWN_REQ(u8 in_SlotNo);
    s32 Send_C2S_GET_FAVORITE_PAWN_LIST_REQ();
    s32 Send_C2S_SET_FAVORITE_PAWN_REQ(u32 in_PawnID);
    s32 Send_C2S_DELETE_FAVORITE_PAWN_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_OFFICIAL_PAWN_LIST_REQ();
    s32 Send_C2S_GET_LEGEND_PAWN_LIST_REQ();
    s32 Send_C2S_PAWN_LOST_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_LOST_PAWN_LIST_REQ();
    s32 Send_C2S_LOST_PAWN_REVIVE_REQ(u32 in_PawnID);
    s32 Send_C2S_LOST_PAWN_POINT_REVIVE_REQ(u32 in_PawnId);
    s32 Send_C2S_LOST_PAWN_GOLDEN_REVIVE_REQ(u32 in_PawnId);
    s32 Send_C2S_LOST_PAWN_WALLET_REVIVE_REQ(u32 in_PawnId, u8 in_Type, u32 in_ReviveCost);
    s32 Send_C2S_RENTAL_PAWN_LOST_REQ(u32 in_PawnID);
    s32 Send_C2S_UPDATE_PAWN_REACTION_LIST_REQ(u32 in_PawnID, const MtTypedArray<CDataPawnReaction>& in_PawnReactionList);
    s32 Send_C2S_UPDATE_PAWN_SHARE_RANGE_REQ(u32 in_PawnID, u8 in_ShareRange);
    s32 Send_C2S_GET_PAWN_HISTORY_LIST_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_PAWN_TOTAL_SCORE_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_NORA_PAWN_LIST_REQ();
    s32 Send_C2S_GET_FREE_RENTAL_PAWN_LIST_REQ();
    s32 Send_C2S_GET_CHARACTER_BIN_SAVEDATA_REQ();
    s32 Send_C2S_SET_CHARACTER_BIN_SAVEDATA_REQ(const u8(&in_Bin)[1024]);
    s32 Send_C2S_USE_BAG_ITEM_REQ(const char* in_strUID, u32 in_Num);
    s32 Send_C2S_USE_JOB_ITEMS_REQ(const MtTypedArray<CDataItemUIDList>& in_ItemUIDList);
    s32 Send_C2S_GET_STORAGE_ITEM_LIST_REQ(const MtTypedArray<CDataCommonU8>& in_StorageList);
    s32 Send_C2S_CONSUME_STORAGE_ITEM_REQ(const MtTypedArray<CDataStorageItemUIDList>& in_ConsumeItemList);
    s32 Send_C2S_GET_POST_ITEM_LIST_REQ();
    s32 Send_C2S_MOVE_ITEM_REQ(u8 in_SourceGameStorageType, const MtTypedArray<CDataMoveItemUIDFromTo>& in_ItemUIDList);
    s32 Send_C2S_GET_LIGHT_QUEST_LIST_REQ(u32 in_BaseID);
    s32 Send_C2S_GET_SET_QUEST_LIST_REQ(u32 in_DistributeID);
    s32 Send_C2S_GET_MAIN_QUEST_LIST_REQ();
    s32 Send_C2S_GET_TUTORIAL_QUEST_LIST_REQ(u32 in_StageNo);
    s32 Send_C2S_GET_LOT_QUEST_LIST_REQ(u32 in_LotQuestType);
    s32 Send_C2S_GET_TIME_LIMITED_QUEST_LIST_REQ();
    s32 Send_C2S_GET_WORLD_MANAGE_QUEST_LIST_REQ();
    s32 Send_C2S_GET_END_CONTENTS_GROUP_REQ(u32 in_GroupID);
    s32 Send_C2S_GET_QUEST_SCHEDULE_INFO_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_GET_MAIN_QUEST_COMPLETE_INFO_REQ();
    s32 Send_C2S_GET_RECOMMENDED_QUEST_INFO_LIST_REQ();
    s32 Send_C2S_GET_SET_QUEST_INFO_LIST_REQ(u32 in_DistributeID);
    s32 Send_C2S_GET_CYCLE_CONTENTS_NEWS_LIST_REQ();
    s32 Send_C2S_GET_AREA_BONUS_LIST_REQ();
    s32 Send_C2S_QUEST_ORDER_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_QUEST_PROGRESS_REQ(u32 in_KeyId, u32 in_ProgressCharacterId, u32 in_QuestScheduleId, u16 in_ProcessNo);
    s32 Send_C2S_LEADER_QUEST_PROGRESS_REQUEST_REQ(u32 in_KeyId, u32 in_QuestScheduleId, u16 in_ProcessNo, u16 in_SequenceNo, u16 in_BlockNo);
    s32 Send_C2S_LIGHT_QUEST_GP_COMPLETE_REQ(u32 in_BaseID);
    s32 Send_C2S_CHECK_QUEST_DISTRIBUTION_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_QUEST_CANCEL_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_END_DISTRIBUTION_QUEST_CANCEL_REQ();
    s32 Send_C2S_QUEST_COMPLETE_FLAG_CLEAR_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_GET_QUEST_DETAIL_LIST_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_GET_QUEST_COMPLETE_LIST_REQ(u8 in_QuestType);
    s32 Send_C2S_SET_PRIORITY_QUEST_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_CANCEL_PRIORITY_QUEST_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_GET_PRIORITY_QUEST_REQ();
    s32 Send_C2S_GET_SET_QUEST_OPEN_DATE_LIST_REQ();
    s32 Send_C2S_GET_QUEST_LAYOUT_FLAG_REQ(u32 in_FlagNo);
    s32 Send_C2S_GET_CYCLE_CONTENTS_STATE_LIST_REQ();
    s32 Send_C2S_GET_CYCLE_CONTENTS_SITUATION_INFO_LIST_REQ(u32 in_CycleContentsScheduleId);
    s32 Send_C2S_PLAY_ENTRY_REQ();
    s32 Send_C2S_PLAY_ENTRY_CANCEL_REQ();
    s32 Send_C2S_PLAY_START_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_PLAY_START_TIMER_REQ();
    s32 Send_C2S_PLAY_INTERRUPT_REQ();
    s32 Send_C2S_PLAY_INTERRUPT_ANSWER_REQ(b8 in_IsInterrupt);
    s32 Send_C2S_PLAY_END_REQ();
    s32 Send_C2S_CYCLE_CONTENTS_PLAY_START_REQ(u32 in_CycleContentsScheduleId);
    s32 Send_C2S_CYCLE_CONTENTS_PLAY_END_REQ();
    s32 Send_C2S_GET_CYCLE_CONTENTS_POINT_LIST_REQ(u32 in_CycleContentsScheduleId);
    s32 Send_C2S_GET_CYCLE_CONTENTS_NOW_POINT_LIST_REQ(u32 in_CycleContentsScheduleId);
    s32 Send_C2S_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_REQ(u32 in_CycleContentsScheduleId);
    s32 Send_C2S_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_REQ(u32 in_CycleContentsScheduleId);
    s32 Send_C2S_GET_CYCLE_CONTENTS_REWARD_REQ(u32 in_CycleContentsScheduleId);
    s32 Send_C2S_PAWN_DUNGEON_REWARD_LIST_REQ();
    s32 Send_C2S_PAWN_DUNGEON_REWARD_SELECT_REQ(u8);
    s32 Send_C2S_SEND_BINARY_MSG_ALL_NOTICE(const MtMemoryStream& in_Data);
    s32 Send_C2S_SEND_BINARY_MSG_NOTICE(const MtTypedArray<CDataCommonU32>& in_CharacterIDList, const MtMemoryStream& in_Data);
    s32 Send_C2S_GET_AREA_INFO_LIST_REQ();
    s32 Send_C2S_GET_QUEST_PARTY_BONUS_LIST_REQ();
    s32 Send_C2S_SEND_LEADER_QUEST_ORDER_CONDITION_INFO_REQ(const MtTypedArray<CDataOrderConditionInfo>& in_OrderConditionInfoList);
    s32 Send_C2S_SEND_LEADER_WAIT_ORDER_QUEST_LIST_REQ(const MtTypedArray<CDataCommonU32>& in_QuestScheduleIdList);
    s32 Send_C2S_PRT_READY_SET_RETURN_SESSION(b8 in_IsReturnSession);
    s32 Send_C2S_QUEST_LOG_INFO_REQ();
    s32 Send_C2S_GET_STAGE_LIST_REQ();
    s32 Send_C2S_AREA_CHANGE_REQ(u32 in_StageId, u32 in_JumpType);
    s32 Send_C2S_GET_ENEMY_SET_LIST_REQ(const CStageLayoutID& in_LayoutId, u8 in_SubGroupId);
    s32 Send_C2S_ENEMY_GROUP_ENTRY_NOTICE(const CStageLayoutID& in_LayoutId);
    s32 Send_C2S_ENEMY_GROUP_LEAVE_NOTICE(const CStageLayoutID& in_LayoutId);
    s32 Send_C2S_ENEMY_KILL_REQ(const CStageLayoutID& in_LayoutId, u32 in_SetId, u32 in_InnerId, f64 in_DropPosX, f32 in_DropPosY, f64 in_DropPosZ, b8 in_IsNoBattleReword, u32 in_RegionFlag);
    s32 Send_C2S_ENEMY_BREAK_REGION_NTC(const CStageLayoutID& in_LayoutId, u32 in_SetId, u32 in_RegionNo);
    s32 Send_C2S_GET_ITEM_SET_LIST_REQ(const CStageLayoutID& in_LayoutId);
    s32 Send_C2S_GET_GATHERING_ITEM_LIST_REQ(const CStageLayoutID& in_LayoutId, u32 in_PosId, const char* in_strGatheringItemUID);
    s32 Send_C2S_GET_GATHERING_ITEM_REQ(const CStageLayoutID& in_LayoutId, u32 in_PosId, const MtTypedArray<CDataGatheringItemGetRequest>& in_GatheringItemGetRequestList);
    s32 Send_C2S_GET_DROP_ITEM_SET_LIST_REQ(const CStageLayoutID& in_LayoutId);
    s32 Send_C2S_GET_DROP_ITEM_LIST_REQ(const CStageLayoutID& in_LayoutId, u32 in_Id);
    s32 Send_C2S_GET_DROP_ITEM_REQ(const CStageLayoutID& in_LayoutId, u32 in_Id, const MtTypedArray<CDataGatheringItemGetRequest>& in_GatheringItemGetRequestList);
    s32 Send_C2S_PL_TOUCH_OM_NOTICE(const CStageLayoutID& in_LayoutId, u32 in_PosId);
    s32 Send_C2S_SET_RAID_BOSS_INFO_REQ(const CRaidBossUploadInfo& in_UploadInfo);
    s32 Send_C2S_TRANING_ROOM_GET_ENEMY_LIST_REQ();
    s32 Send_C2S_TRANING_ROOM_SET_ENEMY_REQ(u32 in_ID, u32 in_LV);
    s32 Send_C2S_JOINT_STRUGGLE_PAWN_DEAD_NTC(const CStageLayoutID&);
    s32 Send_C2S_SET_OM_INSTANT_KEY_VALUE_REQ(const COmData& in_Data);
    s32 Send_C2S_GET_OM_INSTANT_KEY_VALUE_REQ(u32 in_Key);
    s32 Send_C2S_GET_OM_INSTANT_KEY_VALUE_ALL_REQ();
    s32 Send_C2S_EXCHANGE_OM_INSTANT_KEY_VALUE_REQ(const COmData& in_Data);
    s32 Send_C2S_RELEASE_WARP_POINT_REQ(u32 in_WarpPointID);
    s32 Send_C2S_GET_RELEASE_WARP_POINT_LIST_REQ();
    s32 Send_C2S_GET_WARP_POINT_LIST_REQ(u32 in_CurrentPointID);
    s32 Send_C2S_WARP_REQ(u32 in_CurrentPointID, u32 in_DestPointID, u32 in_Price);
    s32 Send_C2S_GET_FAVORITE_WARP_POINT_LIST_REQ(u32 in_AreaID);
    s32 Send_C2S_FAVORITE_WARP_REQ(u32 in_SlotNo, u32 in_AreaID, u32 in_Price);
    s32 Send_C2S_REGISTER_FAVORITE_WARP_REQ(u32 in_SlotNo, u32 in_WarpPointID);
    s32 Send_C2S_PARTY_WARP_REQ();
    s32 Send_C2S_GET_AREA_WARP_POINT_LIST_REQ(u32 in_CurrentAreaID);
    s32 Send_C2S_AREA_WARP_REQ(u32 in_CurrentAreaID, u32 in_WarpPointID, u32 in_Price);
    s32 Send_C2S_WARP_END_NTC();
    s32 Send_C2S_SET_ONLINE_STATUS_REQ(u8 in_StatusID, b8 in_IsSaveSetting);
    s32 Send_C2S_EVENT_START_NTC();
    s32 Send_C2S_EVENT_END_NTC();
    s32 Send_C2S_GET_FRIEND_LIST_REQ();
    s32 Send_C2S_APPLY_FRIEND_REQ(u32 in_CharacterID);
    s32 Send_C2S_APPROVE_FRIEND_REQ(u32 in_CharacterID, u8 in_IsApproved);
    s32 Send_C2S_REMOVE_FRIEND_REQ(u32 in_FriendNo);
    s32 Send_C2S_REGISTER_FAVORITE_FRIEND_REQ(u32 in_FriendNo, b8 in_IsFavorite);
    s32 Send_C2S_CANCEL_FRIEND_APPLICATION_REQ(u32 in_CharacterID);
    s32 Send_C2S_GET_RECENT_CHARACTER_LIST_REQ();
    s32 Send_C2S_GET_BLACK_LIST_REQ();
    s32 Send_C2S_ADD_BLACK_LIST_REQ(const CCommunityCharacterBaseInfo& in_CharacterInfo);
    s32 Send_C2S_REMOVE_BLACK_LIST_REQ(u32 in_CharacterId);
    s32 Send_C2S_GROUP_CHAT_GET_MEMBER_LIST_REQ(u64 in_GroupID);
    s32 Send_C2S_GROUP_CHAT_INVITE_CHARACTER_REQ(u64 in_GroupID, u32 in_CharacterID);
    s32 Send_C2S_GROUP_CHAT_LEAVE_CHARACTER_REQ(u64 in_GroupID);
    s32 Send_C2S_GROUP_CHAT_KICK_CHARACTER_REQ(u64 in_GroupID, u32 in_CharacterID);
    s32 Send_C2S_GET_ACQUIRABLE_NORMAL_SKILL_LIST_REQ(u8 in_Job);
    s32 Send_C2S_GET_ACQUIRABLE_SKILL_LIST_REQ(u8 in_Job);
    s32 Send_C2S_GET_ACQUIRABLE_ABILITY_LIST_REQ(u8 in_Job);
    s32 Send_C2S_LEARN_NORMAL_SKILL_REQ(u8 in_Job, u32 in_SkillNo);
    s32 Send_C2S_LEARN_SKILL_REQ(u8 in_Job, u32 in_SkillID, u8 in_SkillLv);
    s32 Send_C2S_LEARN_ABILITY_REQ(u8 in_Job, u32 in_AbilityID, u8 in_AbilityLv);
    s32 Send_C2S_LEARN_PAWN_NORMAL_SKILL_REQ(u32 in_PawnID, u8 in_Job, u32 in_SkillNo);
    s32 Send_C2S_LEARN_PAWN_SKILL_REQ(u32 in_PawnID, u8 in_Job, u32 in_SkillID, u8 in_SkillLv);
    s32 Send_C2S_LEARN_PAWN_ABILITY_REQ(u32 in_PawnID, u32 in_AbilityID, u8 in_AbilityLv);
    s32 Send_C2S_GET_LEARNED_NORMAL_SKILL_LIST_REQ();
    s32 Send_C2S_GET_LEARNED_SKILL_LIST_REQ();
    s32 Send_C2S_GET_LEARNED_ABILITY_LIST_REQ();
    s32 Send_C2S_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_PAWN_LEARNED_SKILL_LIST_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_PAWN_LEARNED_ABILITY_LIST_REQ(u32 in_PawnID);
    s32 Send_C2S_SET_SKILL_REQ(u8 in_Job, u8 in_SlotNo, u32 in_SkillID, u8 in_SkillLv);
    s32 Send_C2S_SET_ABILITY_REQ(u8 in_Job, u8 in_SlotNo, u32 in_AbilityID, u8 in_AbilityLv);
    s32 Send_C2S_SET_PAWN_SKILL_REQ(u32 in_PawnID, u8 in_Job, u8 in_SlotNo, u32 in_SkillID, u8 in_SkillLv);
    s32 Send_C2S_SET_PAWN_ABILITY_REQ(u32 in_PawnID, u8 in_Job, u8 in_SlotNo, u32 in_AbilityID, u8 in_AbilityLv);
    s32 Send_C2S_SET_OFF_SKILL_REQ(u8 in_Job, u8 in_SlotNo);
    s32 Send_C2S_SET_OFF_ABILITY_REQ(u8 in_SlotNo);
    s32 Send_C2S_SET_OFF_PAWN_SKILL_REQ(u32 in_PawnID, u8 in_Job, u8 in_SlotNo);
    s32 Send_C2S_SET_OFF_PAWN_ABILITY_REQ(u32 in_PawnID, u8 in_SlotNo);
    s32 Send_C2S_GET_SET_SKILL_LIST_REQ(u8 in_Job);
    s32 Send_C2S_GET_SET_ABILITY_LIST_REQ();
    s32 Send_C2S_GET_PAWN_SET_SKILL_LIST_REQ(u32 in_PawnID, u8 in_Job);
    s32 Send_C2S_GET_PAWN_SET_ABILITY_LIST_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_CURRENT_SET_SKILL_LIST_REQ();
    s32 Send_C2S_GET_CURRENT_SET_ABILITY_LIST_REQ();
    s32 Send_C2S_GET_PAWN_CURRENT_SET_SKILL_LIST_REQ(u32);
    s32 Send_C2S_GET_PAWN_CURRENT_SET_ABILITY_LIST_REQ(u32);
    s32 Send_C2S_GET_RELEASE_SKILL_LIST_REQ();
    s32 Send_C2S_GET_RELEASE_ABILITY_LIST_REQ();
    s32 Send_C2S_REGISTER_PRESET_ABILITY_REQ(u32 in_PawnID, u8 in_PresetNo);
    s32 Send_C2S_SET_PRESET_ABILITY_NAME_REQ(u8 in_PresetNo, const char* in_strPresetName);
    s32 Send_C2S_GET_PRESET_ABILITY_LIST_REQ();
    s32 Send_C2S_SET_PRESET_ABILITY_LIST_REQ(u32 in_PawnID, u8 in_PresetNo);
    s32 Send_C2S_SET_PAWN_PRESET_ABILITY_LIST_REQ(u32, u8);
    s32 Send_C2S_GET_ABILITY_COST_REQ();
    s32 Send_C2S_GET_PAWN_ABILITY_COST_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_SHOP_GOODS_LIST_REQ(u32 in_ShopID);
    s32 Send_C2S_BUY_SHOP_GOODS_REQ(u32 in_GoodsIndex, u32 in_Num, u8 in_StorageType, u32 in_Price);
    s32 Send_C2S_SELL_ITEM_REQ(const MtTypedArray<CDataStorageItemUIDList>& in_SellItemList);
    s32 Send_C2S_GET_STAY_PRICE_REQ(u32 in_InnID);
    s32 Send_C2S_STAY_INN_REQ(u32 in_InnID, u32 in_Price, u32 in_HpMax, const MtTypedArray<CDataPawnHp>& in_PawnHpMaxList);
    s32 Send_C2S_HP_RECOVERY_COMPLETE_NOTICE();
    s32 Send_C2S_HP_RECOVERY_CHARACTER_COMPLETE_NOTICE();
    s32 Send_C2S_HP_RECOVERY_PAWN_COMPLETE_NOTICE(u32 in_PawnId);
    s32 Send_C2S_GET_PENALTY_HEAL_STAY_PRICE_REQ();
    s32 Send_C2S_STAY_PENALTY_HEAL_INN_REQ(u32 in_Price, u32 in_HpMax, const MtTypedArray<CDataPawnHp>& in_PawnHpMaxList);
    s32 Send_C2S_GET_AREA_MASTER_INFO_REQ(u32 in_AreaID);
    s32 Send_C2S_GET_AREA_REWARD_INFO_REQ(u32);
    s32 Send_C2S_AREA_RANK_UP_REQ(u32 in_AreaID);
    s32 Send_C2S_GET_AREA_SUPPLY_INFO_REQ(u32 in_AreaID);
    s32 Send_C2S_GET_AREA_SUPPLY_REQ(u32 in_AreaID, u8 in_StorageType, const MtTypedArray<CDataSelectItemInfo>& in_SelectItemInfoList);
    s32 Send_C2S_GET_AREA_POINT_DEBUG_REQ(u32 in_AreaID, u32 in_Point);
    s32 Send_C2S_CLEAR_AREA_QUEST_DEBUG_REQ(u32, u8, u16, u32);
    s32 Send_C2S_GET_AREA_RELEASE_LIST_REQ();
    s32 Send_C2S_GET_LEADER_AREA_RELEASE_LIST_REQ();
    s32 Send_C2S_GET_AREA_QUEST_HINT_LIST_REQ(u32 in_AreaID);
    s32 Send_C2S_BUY_AREA_QUEST_HINT_REQ(u32 in_AreaID, u32 in_QuestScheduleID);
    s32 Send_C2S_GET_SPOT_INFO_LIST_REQ(u32 in_AreaID);
    s32 Send_C2S_GET_AREA_BASE_INFO_LIST_REQ();
    s32 Send_C2S_GET_JOB_MASTER_ORDER_PROGRESS_REQ(u8 in_JobID);
    s32 Send_C2S_REPORT_JOB_ORDER_PROGRESS_REQ(u8 in_JobID);
    s32 Send_C2S_ACTIVATE_JOB_ORDER_REQ(u8 in_JobID, u8 in_RewardType, u32 in_RewardNo, u8 in_RewardLv);
    s32 Send_C2S_DEBUG_ADD_JOB_ORDER_PROGRESS_REQ(u8 in_JobID, u8 in_Type, u32 in_ID, u32 in_Rank, u32 in_Num);
    s32 Send_C2S_GET_ALL_ORB_ELEMENT_LIST_REQ(u8 in_UnitType, u8 in_PageNo);
    s32 Send_C2S_GET_RELEASE_ORB_ELEMENT_LIST_REQ();
    s32 Send_C2S_RELEASE_ORB_ELEMENT_REQ(u32 in_ElementID);
    s32 Send_C2S_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_REQ(u32 in_PawnID);
    s32 Send_C2S_RELEASE_PAWN_ORB_ELEMENT_REQ(u32 in_PawnID, u32 in_ElementID);
    s32 Send_C2S_GET_ORB_GAIN_EXTEND_PARAM_REQ();
    s32 Send_C2S_GET_CHARACTER_PROFILE_REQ(u32 in_CharacterID);
    s32 Send_C2S_GET_MY_CHARACTER_PROFILE_REQ();
    s32 Send_C2S_GET_AVAILABLE_BACKGROUND_LIST_REQ();
    s32 Send_C2S_SET_ARISEN_PROFILE_REQ(const CArisenProfile& in_ArisenProfile);
    s32 Send_C2S_GET_ARISEN_PROFILE_REQ();
    s32 Send_C2S_SET_PAWN_PROFILE_REQ(u32 in_PawnId, const CArisenProfile& in_ProfileInfo, const char* in_strComment);
    s32 Send_C2S_SET_PAWN_PROFILE_COMMENT_REQ(u32 in_PawnId, const char* in_strComment);
    s32 Send_C2S_UPDATE_ARISEN_PROFILE_SHARE_RANGE_REQ(u8 in_CharacterShareRange, u8 in_PawnShareRange);
    s32 Send_C2S_UPDATE_LAST_BASE_NTC(u32 in_BaseID);
    s32 Send_C2S_GET_RETURN_LOCATION_REQ();
    s32 Send_C2S_ACHIEVEMENT_GET_PROGRESS_LIST_REQ();
    s32 Send_C2S_ACHIEVEMENT_GET_REWARD_LIST_REQ();
    s32 Send_C2S_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_REQ();
    s32 Send_C2S_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_REQ();
    s32 Send_C2S_ACHIEVEMENT_REWARD_RECEIVE_REQ(const MtTypedArray<CDataAchieveRewardCommon>& in_RewardList);
    s32 Send_C2S_EVENT_ACHIEVEMENT_LIST_REQ(u8);
    s32 Send_C2S_EVENT_ACHIEVEMENT_CATEGORY_LIST_REQ();
    s32 Send_C2S_SET_INSTANT_KEY_VALUE_UL_REQ(u32 in_Key, u32 in_Value);
    s32 Send_C2S_GET_INSTANT_KEY_VALUE_UL_REQ(u32 in_Key);
    s32 Send_C2S_SET_INSTANT_KEY_VALUE_STR_REQ(const char* in_strKey, const char* in_strValue);
    s32 Send_C2S_GET_INSTANT_KEY_VALUE_STR_REQ(const char* in_strKey);
    s32 Send_C2S_GET_GP_REQ();
    s32 Send_C2S_GET_GP_DETAIL_REQ(b8 in_IsAll);
    s32 Send_C2S_GET_GP_PERIOD_REQ();
    s32 Send_C2S_GET_CAP_REQ();
    s32 Send_C2S_GET_CAP_TO_GP_CHANGE_LIST_REQ();
    s32 Send_C2S_CHANGE_CAP_TO_GP_REQ(u32 in_ChangeListID);
    s32 Send_C2S_COG_GET_ID_REQ();
    s32 Send_C2S_GP_SHOP_DISPLAY_GET_TYPE_REQ();
    s32 Send_C2S_GP_SHOP_DISPLAY_GET_LINEUP_REQ(u32 in_DisplayID);
    s32 Send_C2S_GP_SHOP_DISPLAY_BUY_REQ(u32 in_DisplayLineupId);
    s32 Send_C2S_GP_SHOP_GET_COURSE_LINEUP_REQ();
    s32 Send_C2S_GP_SHOP_GET_ITEM_LINEUP_REQ();
    s32 Send_C2S_GP_SHOP_GET_PAWN_LINEUP_REQ();
    s32 Send_C2S_GP_SHOP_GET_PAWN_VOICE_LINEUP_REQ();
    s32 Send_C2S_GP_SHOP_GET_PICKUP_REQ();
    s32 Send_C2S_GP_SHOP_GET_BUY_HISTORY_REQ();
    s32 Send_C2S_GP_SHOP_GET_CAP_CHARGE_URL_REQ();
    s32 Send_C2S_GP_COURSE_GET_AVAILABLE_LIST_REQ();
    s32 Send_C2S_GP_COURSE_GET_VALID_LIST_REQ();
    s32 Send_C2S_GP_COURSE_USE_FROM_AVAILABLE_REQ(u32 in_AvailableId);
    s32 Send_C2S_GP_COURSE_GET_VERSION_REQ();
    s32 Send_C2S_GP_EDIT_VOICE_GET_BUY_HISTORY_REQ();
    s32 Send_C2S_GP_EDIT_GET_VOICE_LIST_REQ();
    s32 Send_C2S_GP_EDIT_GET_GP_PRICE_REQ();
    s32 Send_C2S_GP_SHOP_CAN_BUY_PAWN_REQ(u32 in_LineupId);
    s32 Send_C2S_GP_SHOP_CAN_BUY_PAWN_VOICE_REQ(u32 in_LineupId);
    s32 Send_C2S_GET_CHARACTER_EQUIP_LIST_REQ();
    s32 Send_C2S_CHANGE_CHARACTER_EQUIP_REQ(const MtTypedArray<CDataC2SChangeCharacterEquipInfo>& in_ChangeCharacterEquipList);
    s32 Send_C2S_CHANGE_CHARACTER_STORAGE_EQUIP_REQ(const MtTypedArray<CDataC2SChangeCharacterEquipInfo>& in_ChangeCharacterEquipList);
    s32 Send_C2S_GET_PAWN_EQUIP_LIST_REQ(u32 in_PawnID);
    s32 Send_C2S_CHANGE_PAWN_EQUIP_REQ(u32 in_PawnID, const MtTypedArray<CDataC2SChangeCharacterEquipInfo>& in_ChangeCharacterEquipList);
    s32 Send_C2S_CHANGE_PAWN_STORAGE_EQUIP_REQ(u32 in_PawnID, const MtTypedArray<CDataC2SChangeCharacterEquipInfo>& in_ChangeCharacterEquipList);
    s32 Send_C2S_CHANGE_CHARACTER_EQUIP_JOB_ITEM_REQ(const MtTypedArray<CDataChangeEquipJobItem>& in_ChangeCharacterEquipJobItemList);
    s32 Send_C2S_CHANGE_PAWN_EQUIP_JOB_ITEM_REQ(u32 in_PawnID, const MtTypedArray<CDataChangeEquipJobItem>& in_ChangeCharacterEquipJobItemList);
    s32 Send_C2S_UPDATE_HIDE_CHARACTER_HEAD_ARMOR_REQ(b8 in_Hide);
    s32 Send_C2S_UPDATE_HIDE_PAWN_HEAD_ARMOR_REQ(b8 in_Hide);
    s32 Send_C2S_UPDATE_HIDE_CHARACTER_LANTERN_REQ(b8 in_Hide);
    s32 Send_C2S_UPDATE_HIDE_PAWN_LANTERN_REQ(b8 in_Hide);
    s32 Send_C2S_GET_EQUIP_PRESET_LIST_REQ();
    s32 Send_C2S_UPDATE_EQUIP_PRESET_REQ(u32 in_PresetNo, u32 in_PawnID, u32 in_Type, const char* in_strPresetName);
    s32 Send_C2S_UPDATE_EQUIP_PRESET_NAME_REQ(u32 in_PresetNo, const char* in_strPresetName);
    s32 Send_C2S_GET_REWARD_BOX_LIST_REQ();
    s32 Send_C2S_GET_REWARD_BOX_LIST_NUM_REQ();
    s32 Send_C2S_GET_REWARD_BOX_ITEM_REQ(u32 in_ListNo, const MtTypedArray<CDataGetRewardBoxItem>& in_GetRewardBoxItemList);
    s32 Send_C2S_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_REQ();
    s32 Send_C2S_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_NUM_REQ();
    s32 Send_C2S_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_REQ(u32 in_ListNo, const MtTypedArray<CDataGetRewardBoxItem>& in_GetRewardBoxItemList);
    s32 Send_C2S_DELIVER_ITEM_REQ(u32 in_QuestScheduleId, u16 in_ProcessNo, const MtTypedArray<CDataItemUIDList>& in_ItemUIDList);
    s32 Send_C2S_DECIDE_DELIVERY_ITEM_REQ(u32 in_QuestScheduleId, u16 in_ProcessNo);
    s32 Send_C2S_GET_PARTY_QUEST_PROGRESS_INFO_REQ();
    s32 Send_C2S_DEBUG_QUEST_FORCE_PROGRESS_REQ(u32 in_ProgressCharacterId, u32 in_QuestScheduleId, u16 in_ProcessNo);
    s32 Send_C2S_DEBUG_MAIN_QUEST_JUMP_REQ(u32 in_QuestId);
    s32 Send_C2S_DEBUG_QUEST_RESET_REQ(u32 in_QuestId);
    s32 Send_C2S_DEBUG_QUEST_RESET_ALL_REQ(u8 in_QuestType);
    s32 Send_C2S_DEBUG_CYCLE_CONTENTS_POINT_UPLOAD_REQ(u32 in_CycleContentsScheduleId, s32 in_Point);
    s32 Send_C2S_DEBUG_SET_QUEST_FLAG_REQ(u32 in_FlagNo);
    s32 Send_C2S_DEBUG_GET_QUEST_FLAG_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_DEBUG_GET_QUEST_LAYOUT_FLAG_REQ(u32 in_QuestScheduleId);
    s32 Send_C2S_DEBUG_ENEMY_SET_PRESET_FIX_REQ(const MtTypedArray<CDataDebugEnemySetPresetReq>& in_DebugEnemySetPresetReqList);
    s32 Send_C2S_DEBUG_QUEST_LAYOUT_FLAG_SET(u32 in_FlagNo, b8 in_value);
    s32 Send_C2S_DEBUG_PROB_DROP_CANCEL_SET(b8 in_value);
    s32 Send_C2S_GET_CRAFT_PROGRESS_LIST_REQ();
    s32 Send_C2S_START_CRAFT_REQ(u32 in_RecipeID, const MtTypedArray<CDataCraftMaterial>& in_CraftMaterialList, const char* in_strToppingUID, u32 in_CraftMainPawnID, const MtTypedArray<CDataCraftSupportPawnID>& in_CraftSupportPawnIDList, u32 in_CreateCount);
    s32 Send_C2S_GET_CRAFT_PRODUCT_INFO_REQ(u32 in_CraftMainPawnID, u8 in_DebugFlag);
    s32 Send_C2S_GET_CRAFT_PRODUCT_REQ(u32 in_CraftMainPawnID, u32 in_StorageType, u8 in_DebugFlag);
    s32 Send_C2S_CANCEL_CRAFT_REQ(u32 in_CraftMainPawnID);
    s32 Send_C2S_START_EQUIP_GRADE_UP_REQ(const char* in_strEquipItemUID, const MtTypedArray<CDataCraftMaterial>& in_CraftMaterialList, u32 in_CraftMainPawnID, const MtTypedArray<CDataCraftSupportPawnID>& in_CraftSupportPawnIDList);
    s32 Send_C2S_START_ATTACH_ELEMENT_REQ(const char* in_strEquipItemUID, const MtTypedArray<CDataCraftElement>& in_CraftElementList, u32 in_CraftMainPawnID, const MtTypedArray<CDataCraftSupportPawnID>& in_CraftSupportPawnIDList);
    s32 Send_C2S_START_DETACH_ELEMENT_REQ(const char* in_strEquipItemUID, const MtTypedArray<CDataCraftElement>& in_CraftElementList, u32 in_CraftMainPawnID, const MtTypedArray<CDataCraftSupportPawnID>& in_CraftSupportPawnIDList);
    s32 Send_C2S_START_EQUIP_COLOR_CHANGE_REQ(const char* in_strEquipItemUID, u8 in_Color, const MtTypedArray<CDataCraftColorant>& in_CraftColorantList, u32 in_CraftMainPawnID, const MtTypedArray<CDataCraftSupportPawnID>& in_CraftSupportPawnIDList);
    s32 Send_C2S_CRAFT_SKILL_UP_REQ(u32 in_PawnID, u32 in_SkillType, u32 in_SkillLevel);
    s32 Send_C2S_GET_LIMIT_BREAK_RECIPE_REQ(u32);
    s32 Send_C2S_SET_OBJECTIVE_REQ(u8 in_No, u8 in_Type);
    s32 Send_C2S_GET_OBJECTIVE_REQ(u8, u8);
    s32 Send_C2S_SET_MATCHING_PROFILE_REQ(const CMatchingProfile& in_MatchingProfile);
    s32 Send_C2S_GET_MATCHING_PROFILE_REQ(u32 in_CharacterID);
    s32 Send_C2S_SET_SHORTCUT_LIST_REQ(const MtTypedArray<CDataShortCut>& in_ShortcutList);
    s32 Send_C2S_GET_SHORTCUT_LIST_REQ();
    s32 Send_C2S_SET_COMMUNICATION_SHORTCUT_LIST_REQ(const MtTypedArray<CDataCommunicationShortCut>& in_ShortcutList);
    s32 Send_C2S_GET_COMMUNICATION_SHORTCUT_LIST_REQ();
    s32 Send_C2S_SET_MESSAGE_SET_REQ(const MtTypedArray<CDataCharacterMsgSet>& in_MessageSetList);
    s32 Send_C2S_GET_MESSAGE_SET_REQ();
    s32 Send_C2S_CLAN_CAN_CREATE_REQ();
    s32 Send_C2S_CLAN_CREATE_REQ(const CClanUserParam& in_CreateParam);
    s32 Send_C2S_CLAN_UPDATE_REQ(const CClanUserParam& in_CreateParam);
    s32 Send_C2S_CLAN_GET_MEMBER_LIST_REQ(u32 in_ClanID);
    s32 Send_C2S_CLAN_GET_MY_MEMBER_LIST_REQ();
    s32 Send_C2S_CLAN_SEARCH_REQ(const CClanSearchParam& in_SearchParam);
    s32 Send_C2S_CLAN_GET_INFO_REQ(u32 in_ClanID);
    s32 Send_C2S_CLAN_REGISTER_JOIN_REQ(u32 in_ClanID);
    s32 Send_C2S_CLAN_CANCEL_JOIN_REQ();
    s32 Send_C2S_CLAN_GET_JOIN_REQUESTED_LIST_REQ();
    s32 Send_C2S_CLAN_GET_MY_JOIN_REQUEST_LIST_REQ();
    s32 Send_C2S_CLAN_APPROVE_JOIN_REQ(u32 in_RequestID, b8 in_IsApprove);
    s32 Send_C2S_CLAN_LEAVE_MEMBER_REQ();
    s32 Send_C2S_CLAN_EXPEL_MEMBER_REQ(u32 in_CharacterID);
    s32 Send_C2S_CLAN_NEGOTIATE_MASTER_REQ(u32 in_CharacterID);
    s32 Send_C2S_CLAN_SET_MEMBER_RANK_REQ(u32 in_CharacterID, u32 in_Rank, u32 in_Permission);
    s32 Send_C2S_CLAN_GET_MEMBER_NUM_REQ(u32 in_ClanID);
    s32 Send_C2S_CLAN_SETTING_UPDATE_REQ(b8 in_IsMemberNotice);
    s32 Send_C2S_CLAN_INVITE_REQ(u32 in_CharacterId);
    s32 Send_C2S_CLAN_INVITE_ACCEPT_REQ(u32 in_ClanId);
    s32 Send_C2S_CLAN_SCOUT_ENTRY_REGISTER_REQ(const CClanScoutEntryParam& in_Param);
    s32 Send_C2S_CLAN_SCOUT_ENTRY_CANCEL_REQ();
    s32 Send_C2S_CLAN_SCOUT_ENTRY_GET_MY_REQ();
    s32 Send_C2S_CLAN_SCOUT_ENTRY_SEARCH_REQ();
    s32 Send_C2S_CLAN_SCOUT_ENTRY_INVITE_REQ(u32 in_ScoutEntryID);
    s32 Send_C2S_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_REQ();
    s32 Send_C2S_CLAN_SCOUT_ENTRY_CANCEL_INVITE_REQ(u32 in_InviteID);
    s32 Send_C2S_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_REQ();
    s32 Send_C2S_CLAN_SCOUT_ENTRY_APPROVE_INVITED_REQ(u32 in_InviteID, b8 in_IsApprove);
    s32 Send_C2S_CLAN_GET_MY_INFO_REQ();
    s32 Send_C2S_CLAN_GET_HISTORY_REQ();
    s32 Send_C2S_CLAN_BASE_GET_INFO_REQ();
    s32 Send_C2S_CLAN_BASE_RELEASE_REQ();
    s32 Send_C2S_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_REQ();
    s32 Send_C2S_CLAN_SHOP_GET_BUFF_ITEM_LIST_REQ();
    s32 Send_C2S_CLAN_SHOP_BUY_FUNCTION_ITEM_REQ(u32 in_LineupId);
    s32 Send_C2S_CLAN_SHOP_BUY_BUFF_ITEM_REQ(u32 in_LineupId);
    s32 Send_C2S_RANDOM_STAGE_GET_INFO_REQ(u32);
    s32 Send_C2S_RANDOM_STAGE_CLEAR_INFO_REQ(u32);
    s32 Send_C2S_GET_JOB_CHANGE_LIST_REQ();
    s32 Send_C2S_CHANGE_JOB_REQ(u8 in_JobID);
    s32 Send_C2S_CHANGE_PAWN_JOB_REQ(u32 in_PawnID, u8 in_JobID);
    s32 Send_C2S_ENTRY_BOARD_ITEM_LIST_REQ(u64 in_ID, u32 in_Offset, u32 in_Num, const CEntryBoardItemSearchParameter& in_SearchParam);
    s32 Send_C2S_ENTRY_BOARD_ITEM_CREATE_REQ(u64 in_BoardID, const char* in_strPassword, const CEntryItemParam& in_Param);
    s32 Send_C2S_ENTRY_BOARD_ITEM_RECREATE_REQ(u64 in_BoardID, const char* in_strPassword, const CEntryItemParam& in_Param);
    s32 Send_C2S_ENTRY_BOARD_ITEM_ENTRY_REQ(u64 in_BoardID, u32 in_EntryID, const char* in_strPassword);
    s32 Send_C2S_ENTRY_BOARD_ITEM_LEAVE_REQ();
    s32 Send_C2S_ENTRY_BOARD_ITEM_READY_REQ();
    s32 Send_C2S_ENTRY_BOARD_ITEM_FORCE_START_REQ();
    s32 Send_C2S_ENTRY_BOARD_ITEM_INFO_REQ(u64 in_BoardID, u32 in_EntryID);
    s32 Send_C2S_ENTRY_BOARD_ITEM_INFO_MYSELF_REQ(b8 in_IsNotice);
    s32 Send_C2S_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_REQ();
    s32 Send_C2S_ENTRY_BOARD_ITEM_INFO_LOCK_REQ();
    s32 Send_C2S_ENTRY_BOARD_ITEM_INFO_CHANGE_REQ(const char* in_strPassword, const CEntryItemParam& in_Param);
    s32 Send_C2S_ENTRY_BOARD_ITEM_INVITE_REQ(const MtTypedArray<CDataCommonU32>& in_CharacterIds);
    s32 Send_C2S_GET_LOBBY_PLAYER_CONTEXT_REQ(u32);
    s32 Send_C2S_GET_PARTY_PLAYER_CONTEXT_REQ(u32);
    s32 Send_C2S_GET_ALL_PLAYER_CONTEXT_REQ(u32);
    s32 Send_C2S_GET_PARTY_MYPAWN_CONTEXT_REQ(u32);
    s32 Send_C2S_GET_PARTY_RENTED_PAWN_CONTEXT_REQ(u32);
    s32 Send_C2S_CHARACTER_START_BAD_STATUS_NOTICE(u32 in_StatusID);
    s32 Send_C2S_PAWN_START_BAD_STATUS_NOTICE(u32 in_PawnID, u32 in_StatusID);
    s32 Send_C2S_GET_SET_CONTEXT_REQ(const CContextSetBase& in_ContextBase);
    s32 Send_C2S_SET_CONTEXT_BASE_NOTICE(const CContextSetBase& in_ContextBase);
    s32 Send_C2S_SET_CONTEXT_NOTICE(const CContextSetInfo& in_Context);
    s32 Send_C2S_MASTER_THROW_REQ(const MtTypedArray<CDataMasterInfo>& in_Info);
    s32 Send_C2S_BAZAAR_GET_CHARACTER_LIST_REQ();
    s32 Send_C2S_BAZAAR_GET_ITEM_LIST_REQ(const MtTypedArray<CDataCommonU32>& in_ItemIdList);
    s32 Send_C2S_BAZAAR_GET_ITEM_INFO_REQ(u32 in_ItemId);
    s32 Send_C2S_BAZAAR_GET_ITEM_HISTORY_INFO_REQ(u32 in_ItemId);
    s32 Send_C2S_BAZAAR_EXHIBIT_REQ(u8 in_StorageType, const char* in_strItemUID, u32 in_Num, u32 in_Price, u8 in_Flag);
    s32 Send_C2S_BAZAAR_RE_EXHIBIT_REQ(u64 in_BazaarId, u32 in_Price);
    s32 Send_C2S_BAZAAR_CANCEL_REQ(u64 in_BazaarId);
    s32 Send_C2S_BAZAAR_PROCEEDS_REQ(u64 in_BazaarId, u32 in_ItemId, u16 in_Sequence, const MtTypedArray<CDataItemStorageIndicateNum>& in_ItemStorageIndicateNum);
    s32 Send_C2S_BAZAAR_RECEIVE_PROCEEDS_REQ();
    s32 Send_C2S_BAZAAR_GET_ITEM_PRICE_LIMIT_REQ(u32 in_ItemId);
    s32 Send_C2S_BAZAAR_GET_TAX_PRICE_REQ(u32, u32, u32);
    s32 Send_C2S_BAZAAR_GET_EXHIBIT_POSSIBLE_NUM_REQ();
    s32 Send_C2S_MAIL_GET_LIST_HEAD_REQ();
    s32 Send_C2S_MAIL_GET_LIST_DATA_REQ(u32 in_Offset, u32 in_Num);
    s32 Send_C2S_MAIL_GET_LIST_FOOT_REQ();
    s32 Send_C2S_MAIL_GET_TEXT_REQ(u64 in_Id);
    s32 Send_C2S_MAIL_DELETE_REQ(u64 in_Id);
    s32 Send_C2S_MAIL_SEND_REQ(const MtTypedArray<CDataCommonU32>& in_CharacterIdList, const char* in_strMailText);
    s32 Send_C2S_SYSTEM_MAIL_GET_LIST_HEAD_REQ();
    s32 Send_C2S_SYSTEM_MAIL_GET_LIST_DATA_REQ(u32 in_Offset, u32 in_Num);
    s32 Send_C2S_SYSTEM_MAIL_GET_LIST_FOOT_REQ();
    s32 Send_C2S_SYSTEM_MAIL_GET_TEXT_REQ(u64 in_Id);
    s32 Send_C2S_SYSTEM_MAIL_GET_ITEM_REQ(u64 in_Id, const MtTypedArray<CDataCommonU64>& in_AttachmentIdList);
    s32 Send_C2S_SYSTEM_MAIL_GET_ALL_ITEM_REQ(u64 in_Id);
    s32 Send_C2S_SYSTEM_MAIL_DELETE_REQ(u64 in_Id);
    s32 Send_C2S_RANKING_BOARD_LIST_REQ();
    s32 Send_C2S_RANKING_DATA_RANK_REQ(u32 in_Id, u32 in_Rank, u8 in_Num);
    s32 Send_C2S_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_REQ(u32 in_Id, u32 in_Rank, u8 in_Num);
    s32 Send_C2S_RANKING_DATA_CHARACTER_ID_REQ(u32 in_Id, const MtTypedArray<CDataCommonU32>& in_CharacterIdList);
    s32 Send_C2S_GACHA_LIST_REQ();
    s32 Send_C2S_GACHA_BUY_REQ(u32 in_Id, u32 in_DrawGroupId, u32 in_SettlementId, u32 in_Price);
    s32 Send_C2S_DEBUG_SET_CHARACTER_ID_NTC(u32);
    s32 Send_C2S_DEBUG_SET_CHARACTER_INFO_NTC(u32, const char*, const char*);
    s32 Send_C2S_DEBUG_COMMAND_REQ(const char*);
    s32 Send_C2S_WEATHER_FORECAST_GET_REQ();
    s32 Send_C2S_CHARACTER_DOWN_NOTICE();
    s32 Send_C2S_CHARACTER_DOWN_CANCEL_NOTICE();
    s32 Send_C2S_CHARACTER_DEAD_NOTICE();
    s32 Send_C2S_CHARACTER_POINT_REVIVE_REQ(u32 in_HpMax);
    s32 Send_C2S_CHARACTER_GOLDEN_REVIVE_REQ(u32 in_HpMax);
    s32 Send_C2S_CHARACTER_PENALTY_REVIVE_REQ(u32 in_HpMax);
    s32 Send_C2S_PAWN_DOWN_NOTICE(u32 in_PawnId);
    s32 Send_C2S_PAWN_DOWN_CANCEL_NOTICE(u32 in_PawnId);
    s32 Send_C2S_PAWN_DEAD_NOTICE(u32 in_PawnId);
    s32 Send_C2S_PAWN_POINT_REVIVE_REQ(u32 in_PawnId, u32 in_HpMax);
    s32 Send_C2S_PAWN_GOLDEN_REVIVE_REQ(u32 in_PawnId, u32 in_HpMax);
    s32 Send_C2S_GET_REVIVE_CHARGEABLE_TIME_REQ();
    s32 Send_C2S_CHARGE_REVIVE_POINT_REQ();
    s32 Send_C2S_GET_REVIVE_POINT_REQ();
    s32 Send_C2S_GET_UNLOCKED_EDIT_PARTS_LIST_REQ();
    s32 Send_C2S_GET_UNLOCKED_PAWN_EDIT_PARTS_LIST_REQ();
    s32 Send_C2S_UPDATE_CHARACTER_EDIT_PARAM_REQ(u8 in_UpdateType, const CEditInfo& in_EditInfo);
    s32 Send_C2S_UPDATE_PAWN_EDIT_PARAM_REQ(u8 in_SlotNo, u8 in_UpdateType, const CEditInfo& in_EditInfo);
    s32 Send_C2S_PHOTO_TAKE_NTC();
    s32 Send_C2S_PHOTO_GET_AUTH_ADDRESS_REQ();
    s32 Send_C2S_LOADING_GET_INFO_REQ();
    s32 Send_C2S_CLIENT_CHALLENGE_REQ(u8 in_CommonKeySrcSize, const u8(&in_CommonKeyEnc)[259], u8 in_PasswordSrcSize, u8 in_PasswordEncSize, const u8(&in_PasswordEnc)[62]);
    s32 Send_C2S_STAMP_BONUS_GET_LIST_REQ();
    s32 Send_C2S_STAMP_BONUS_CHECK_REQ();
    s32 Send_C2S_STAMP_BONUS_RECIEVE_REQ(u8 in_BonusType);
    s32 Send_C2S_STAMP_BONUS_ADD_TOTAL_NUM_REQ();
    s32 Send_C2S_NG_WORD_GET_LIST_REQ(u64 in_VersionNo);
    s32 Send_C2S_REPORT_SITE_GET_ADDRESS_REQ();
    s32 Send_C2S_MANAGEMENT_INFO_LIST_REQ(u32);
    s32 Send_C2S_EVENT_CODE_INPUT_REQ(const char* in_strCode);
    s32 Send_C2S_URL_GET_LIST_REQ();
    s32 Send_C2S_DLC_GET_BOUGHT_REQ();
    s32 Send_C2S_DLC_USE_REQ(u32 in_UseDLCLineupID);
    s32 Send_C2S_DLC_GET_HISTORY_REQ();
    s32 Send_C2S_END_RETURN_PREPARE_NOTICE();
    s32 Send_C2S_COG_LOGIN_SKIP_FLAG_REQ();
    s32 Send_C2S_COG_LOGIN_SKIP_DISABLE_REQ();
    s32 Send_C2S_COG_GET_SESSION_KEY_REQ(b8 in_Update);
    s32 Send_C2S_COMMUNITY_CHARACTER_STATUS_GET_REQ(u32 in_Type);
    s32 Send_C2S_GAME_TIME_GET_BASEINFO_REQ();
    s32 Send_C2S_SUPPORT_POINT_GET_RATE_REQ();
    s32 Send_C2S_SUPPORT_POINT_USE_REQ(const MtTypedArray<CDataUseSupportPoint>& in_UsePointList);
    s32 Send_C2S_GET_ITEM_SORTDATA_BIN_REQ(const MtTypedArray<CDataCommonU32>& in_SortList);
    s32 Send_C2S_SET_ITEM_SORTDATA_BIN_REQ(const CDataItemSort& in_SortData);
    s32 Send_C2S_GET_SCREEN_SHOT_CATEGORY_REQ();
    s32 Send_C2S_GET_ITEM_STORAGE_INFO_REQ(const MtTypedArray<CDataGameItemStorage>& in_GameItemStorageList);
    s32 Send_C2S_GET_DISPEL_ITEM_LIST_REQ(u8 in_Category);
    s32 Send_C2S_EXCHANGE_DISPEL_ITEM_REQ(const MtTypedArray<CDataGetDispelItem>& in_GetDispelItemList);
    s32 Send_C2S_RESET_JOBPOINT_REQ(u32 in_SkillID, u8 in_SkillLv, u32 in_AbilityID, u8 in_AbilityLv, u32 in_PawnID);
    s32 Send_C2S_RESET_CRAFTPOINT_REQ(u32 in_PawnID);
    s32 Send_C2S_GET_CHEAT_INFO_RES(s32 in_Result, const MtTypedArray<CDataCheatInfo>& in_Info);
    s32 Send_C2S_GET_CRAFT_SETTING_REQ();
    s32 Send_C2S_CRAFT_TIME_SAVE_REQ(u32 in_PawnID, u8 in_ID, u8 in_Num, b8 in_IsInit);
    s32 Send_C2S_GET_NORA_PAWN_DATA_REQ(u32);
    s32 Send_C2S_GET_CRAFT_IR_COLLECTION_VALUE_LIST_REQ();
    s32 Send_C2S_CHARACTER_SEARCH_REQ(const CCharacterSearchParam& in_SearchParam);
    s32 Send_C2S_MY_ROOM_RELEASE_REQ();
    s32 Send_C2S_FURNITURE_LIST_GET_REQ();
    s32 Send_C2S_FURNITURE_LAYOUT_REQ(const MtTypedArray<CDataFurnitureLayoutData>& in_LayoutList);
    s32 Send_C2S_MY_ROOM_BGM_UPDATE_REQ(u32 in_BgmAcquirementNo);
    s32 Send_C2S_RELEASED_CRAFT_RECIPE_LIST_GET_REQ();
    s32 Send_C2S_OTHER_ROOM_LAYOUT_GET_REQ(u32);
    s32 Send_C2S_PARTNER_PAWN_SET_REQ(u32 in_PawnId);
    s32 Send_C2S_RELEASED_EDIT_PARTS_LIST_GET_REQ();
    s32 Send_C2S_RELEASED_EMOTION_LIST_GET_REQ();
    s32 Send_C2S_RELEASED_PAWN_TALK_LIST_GET_REQ();
    s32 Send_C2S_PAWN_LIKABILITY_REWARD_LIST_GET_REQ();
    s32 Send_C2S_PAWN_LIKABILITY_REWARD_GET_REQ(const MtTypedArray<CDataPartnerPawnReward>& in_RewardUidList, u64 in_UpdateHairUid);
    s32 Send_C2S_PAWN_LIKABILITY_RELEASED_REWARD_LIST_GET_REQ();
    s32 Send_C2S_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_REQ();
    s32 Send_C2S_PRESENT_FOR_PARTNER_PAWN_REQ(const MtTypedArray<CDataItemUIDList>& in_ItemUIDList);
    s32 Send_C2S_GET_CRAFT_RECIPE_REQ(u8 in_Category, u32 in_Offset, s32 in_Num);
    s32 Send_C2S_GET_CRAFT_RECIPE_DESIGNATE_REQ(u8 in_Category, const MtTypedArray<CDataCommonU32>& in_ItemList);
    s32 Send_C2S_GET_CRAFT_GRADEUP_RECIPE_REQ(u8 in_Category, u32 in_Offset, s32 in_Num, const MtTypedArray<CDataCommonU32>& in_ItemList);
    s32 Send_C2S_GET_JOB_ORB_TREE_STATUS_LIST_REQ();
    s32 Send_C2S_GET_ALL_JOB_ORB_ELEMENT_LIST_REQ(u8 in_JobID);
    s32 Send_C2S_RELEASE_JOB_ORB_ELEMENT_REQ(u32 in_ElementID);
    s32 Send_C2S_GET_CAPLINK_ACHIEVE_REWARD_REQ(const char* in_strfilteringContentId, const MtTypedArray<CDataCommonU32>& in_AchievementId);
    s32 Send_C2S_SERVER_UI_COMMAND_REQ(u32 in_Id, u32 in_Command, u32 in_ArgNum1, u32 in_ArgNum2);
    s32 Send_C2S_GET_DISPEL_ITEM_SETTING_REQ();
    s32 Send_C2S_BOX_GACHA_LIST_REQ();
    s32 Send_C2S_BOX_GACHA_BUY_REQ(u32 in_Id, u32 in_DrawId, u32 in_SettlementId, u32 in_Price);
    s32 Send_C2S_BOX_GACHA_RESET_REQ(u32 in_Id);
    s32 Send_C2S_BOX_GACHA_DRAW_INFO_REQ(u32 in_Id);
    s32 Send_C2S_GET_CRAFT_LOCKED_ELEMENT_LIST_REQ();
    s32 Send_C2S_CLAN_CONCIERGE_UPDATE_REQ(u32 in_NpcId, u32 in_Price);
    s32 Send_C2S_CLAN_CONCIERGE_GET_LIST_REQ();
    s32 Send_C2S_CLAN_PARTNER_PAWN_LIST_GET_REQ();
    s32 Send_C2S_CLAN_PARTNER_PAWN_DATA_GET_REQ(u32 in_PawnID);
    s32 Send_C2S_CRAFT_SKILL_ANALYZE_REQ(u8 in_CraftType, u32 in_RecipeId, u32 in_ItemId, u32 in_PawnId, const MtTypedArray<CDataCommonU32>& in_AssistPawnIds, u32 in_CreateCount);
    s32 Send_C2S_PAWN_EXPEDITION_GET_SALLY_INFO_REQ();
    s32 Send_C2S_PAWN_EXPEDITION_GET_MY_SALLY_INFO_REQ();
    s32 Send_C2S_PAWN_EXPEDITION_CHARGE_SALLY_COUNT_REQ(u8 in_Price);
    s32 Send_C2S_PAWN_EXPEDITION_SALLY_REQ(u32 in_AreaId, u32 in_SpotId);
    s32 Send_C2S_PAWN_EXPEDITION_CHANGE_GOLDEN_SALLY_REQ(u8 in_Price);
    s32 Send_C2S_PAWN_EXPEDITION_GET_SALLY_REWARD_REQ();
    s32 Send_C2S_PAWN_EXPEDITION_CANCEL_SALLY_REQ();
    s32 Send_C2S_PAWN_EXPEDITION_GET_REWARD_DROP_REQ();
    s32 Send_C2S_PAWN_EXPEDITION_GET_REWARD_DROP_ITEM_LIST_REQ(u32 in_PawnRewardBoxId);
    s32 Send_C2S_PAWN_EXPEDITION_GET_REWARD_DROP_ITEM_REQ(u32 in_PawnRewardBoxId, const MtTypedArray<CDataGatheringItemGetRequest>& in_GatheringItemGetRequestList);
    s32 Send_C2S_GET_EXP_MODE_REQ();
    s32 Send_C2S_UPDATE_EXP_MODE_REQ(const MtTypedArray<CDataJobExpMode>& in_UpdateExpModeList);
    s32 Send_C2S_GET_PLAY_POINT_LIST_REQ();
    s32 Send_C2S_JOB_VALUE_SHOP_GET_LINEUP_REQ(u8 in_JobId, u8 in_JobValueType);
    s32 Send_C2S_JOB_VALUE_SHOP_BUY_ITEM_REQ(u8 in_JobId, u8 in_JobValueType, u32 in_LineupId, u8 in_Num, u8 in_StorageType, u32 in_Price);
private:
    cNetGameServer* mpManager;  // offset: 0x118
    cGuardData mGuardData;  // offset: 0x120
public:
    nUserSession::CPacket_S2C_GET_SERVER_LIST_RES* mpGetServerListPacket;  // offset: 0x168
    nUserSession::CPacket_S2C_GET_GAME_SETTING_RES* mpGetGameSettingPacket;  // offset: 0x170
    nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST_RES* mpBorderRewardListPacket;  // offset: 0x178
    nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST_RES* mpRankingRewardListPacket;  // offset: 0x180
    nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_REWARD_RES* mpCycleContentsRewardPacket;  // offset: 0x188
    nUserSession::CPacket_S2C_PAWN_DUNGEON_REWARD_LIST_RES* mpPawnDungeonRewardListPacket;  // offset: 0x190
    nUserSession::CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC* mpPartyInviteJoinMemberPacket;  // offset: 0x198
    nUserSession::CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES* mpGetPawnTotalScorePacket;  // offset: 0x1a0
    nUserSession::CPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES* mpGetFreeRentalPawnListPacket;  // offset: 0x1a8
    nUserSession::CPacket_S2C_GET_LIGHT_QUEST_LIST_RES* mpGetLightQuestListPacket;  // offset: 0x1b0
    nUserSession::CPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES* mpLightQuestGpCompletePacket;  // offset: 0x1b8
    nUserSession::CPacket_S2C_GET_SET_QUEST_LIST_RES* mpGetSetQuestListPacket;  // offset: 0x1c0
    nUserSession::CPacket_S2C_GET_MAIN_QUEST_LIST_RES* mpGetMainQuestListPacket;  // offset: 0x1c8
    nUserSession::CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES* mpGetTutorialQuestListPacket;  // offset: 0x1d0
    nUserSession::CPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES* mpGetTimeLimitedQuestListPacket;  // offset: 0x1d8
    nUserSession::CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES* mpGetWorldManageQuestListPacket;  // offset: 0x1e0
    nUserSession::CPacket_S2C_GET_LOT_QUEST_LIST_RES* mpGetLotQuestListPacket;  // offset: 0x1e8
    nUserSession::CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES* mpGetSetQuestInfoListPacket;  // offset: 0x1f0
    nUserSession::CPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES* mpGetRecommendedQuestInfoListPacket;  // offset: 0x1f8
    nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_NEWS_LIST_RES* mpGetCycleContentsNewsListPacket;  // offset: 0x200
    nUserSession::CPacket_S2C_GET_AREA_INFO_LIST_RES* mpGetAreaInfoListPacket;  // offset: 0x208
    nUserSession::CPacket_S2C_GET_AREA_BONUS_LIST_RES* mpGetAreaBonusListPacket;  // offset: 0x210
    nUserSession::CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES* mpGetQuestPartyBonusListPacket;  // offset: 0x218
    nUserSession::CPacket_S2C_GET_END_CONTENTS_GROUP_RES* mpGetEndContentsGroupPacket;  // offset: 0x220
    nUserSession::CPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES* mpGetQuestScheduleInfoPacket;  // offset: 0x228
    nUserSession::CPacket_S2C_QUEST_ORDER_RES* mpQuestOrderPacket;  // offset: 0x230
    nUserSession::CPacket_S2C_QUEST_PROGRESS_RES* mpQuestProgressPacket;  // offset: 0x238
    nUserSession::CPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES* mpEndDistributionQuestCancelPacket;  // offset: 0x240
    nUserSession::CPacket_S2C_GET_PARTY_QUEST_PROGRESS_INFO_RES* mpPartyQuestProgressInfoPacket;  // offset: 0x248
    nUserSession::CPacket_S2C_GET_QUEST_COMPLETE_LIST_RES* mpGetQuestCompleteListPacket;  // offset: 0x250
    nUserSession::CPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES* mpGetSetQuestOpenDateListPacket;  // offset: 0x258
    nUserSession::CPacket_S2C_GET_REWARD_BOX_LIST_RES* mpGetRewardBoxListPacket;  // offset: 0x260
    nUserSession::CPacket_S2C_GET_REWARD_BOX_ITEM_RES* mpGetRewardBoxItemPacket;  // offset: 0x268
    nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES* mpGetCycleContentsRewardListPacket;  // offset: 0x270
    nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES* mpGetCycleContentsRewardItemPacket;  // offset: 0x278
    nUserSession::CPacket_S2C_GET_PRIORITY_QUEST_RES* mpGetPriorityQuestPacket;  // offset: 0x280
    nUserSession::CPacket_S2C_SET_PRIORITY_QUEST_RES* mpSetPriorityQuestPacket;  // offset: 0x288
    nUserSession::CPacket_S2C_CANCEL_PRIORITY_QUEST_RES* mpCancelPriorityQuestPacket;  // offset: 0x290
    nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_POINT_LIST_RES* mpGetCycleContentsPointListPacket;  // offset: 0x298
    nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_NOW_POINT_LIST_RES* mpGetCycleContentsNowPointListPacket;  // offset: 0x2a0
    nUserSession::CPacket_S2C_RAID_BOSS_POINT_NOTICE* mpGetRaidBossPointPacket;  // offset: 0x2a8
    nUserSession::CPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES* mpGetCAPToGPChangeListPacket;  // offset: 0x2b0
    nUserSession::CPacket_S2C_CHANGE_CAP_TO_GP_RES* mpChangeCAPToGPPacket;  // offset: 0x2b8
    nUserSession::CPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES* mpGPShopCourseLineupPacket;  // offset: 0x2c0
    nUserSession::CPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES* mpGPShopCourseAvailableListPacket;  // offset: 0x2c8
    nUserSession::CPacket_S2C_GP_COURSE_GET_VALID_LIST_RES* mpGPShopCourseValidListPacket;  // offset: 0x2d0
    nUserSession::CPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES* mpGPShopBuyHistoryPacket;  // offset: 0x2d8
    nUserSession::CPacket_S2C_GET_GP_DETAIL_RES* mpGPGetDetailHistoryPacket;  // offset: 0x2e0
    nUserSession::CPacket_S2C_GET_GP_PERIOD_RES* mpGPGetPeriodPacket;  // offset: 0x2e8
    nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES* mpGPShopMenuList;  // offset: 0x2f0
    nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES* mpGPShopLineup;  // offset: 0x2f8
    nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_BUY_RES* mpGPShopBuyRecieve;  // offset: 0x300
    nUserSession::CPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES* mpDebugGetQuestLayoutFlagPacket;  // offset: 0x308
    nUserSession::CPacket_S2C_DEBUG_GET_QUEST_FLAG_RES* mpDebugGetQuestFlagPacket;  // offset: 0x310
    nUserSession::CPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES* mpGetCraftProgressListPacket;  // offset: 0x318
    nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES* mpGetCraftProductInfoPacket;  // offset: 0x320
    nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_RES* mpGetCraftProductPacket;  // offset: 0x328
    nUserSession::CPacket_S2C_GET_CRAFT_SETTING_RES* mpGetCraftSettingPacket;  // offset: 0x330
    nUserSession::CPacket_S2C_CRAFT_SKILL_ANALYZE_RES* mpCraftSkillAnalizePacket;  // offset: 0x338
    nUserSession::CPacket_S2C_GET_CRAFT_LOCKED_ELEMENT_LIST_RES* mpGetCraftLockedElementListPacket;  // offset: 0x340
    nUserSession::CPacket_S2C_GET_DROP_ITEM_LIST_RES* mpGetDropItemListPacket;  // offset: 0x348
    nUserSession::CPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES* mpTrainingRoomGetEnemyList;  // offset: 0x350
    nUserSession::CPacket_S2C_GET_WARP_POINT_LIST_RES* mpGetWarpPointListPacket;  // offset: 0x358
    nUserSession::CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES* mpGetFavoriteWarpPointListPacket;  // offset: 0x360
    nUserSession::CPacket_S2C_GET_AREA_WARP_POINT_LIST_RES* mpGetAreaWarpPointListPacket;  // offset: 0x368
    nUserSession::CPacket_S2C_CHARACTER_SEARCH_RES* mpCharacterSearchPacket;  // offset: 0x370
    nUserSession::CPacket_S2C_GET_MATCHING_PROFILE_RES* mpGetMatchingProfilePacket;  // offset: 0x378
    nUserSession::CPacket_S2C_CLAN_GET_MEMBER_LIST_RES* mpClanMemberListPacket;  // offset: 0x380
    nUserSession::CPacket_S2C_CLAN_SEARCH_RES* mpClanSearchListPacket;  // offset: 0x388
    nUserSession::CPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES* mpClanJoinRequestedListPacket;  // offset: 0x390
    nUserSession::CPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES* mpClanApplyListPacket;  // offset: 0x398
    nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES* mpClanScoutEntryListPacket;  // offset: 0x3a0
    nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES* mpClanInviteListPacket;  // offset: 0x3a8
    nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES* mpClanInvitedListPacket;  // offset: 0x3b0
    nUserSession::CPacket_S2C_CLAN_BASE_GET_INFO_RES* mpClanBaseGetInfoResPacket;  // offset: 0x3b8
    nUserSession::CPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES* mpClanConciergeGetListPacket;  // offset: 0x3c0
    nUserSession::CPacket_S2C_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_RES* mpClanShopGetFunctionItemListPacket;  // offset: 0x3c8
    nUserSession::CPacket_S2C_CLAN_SHOP_GET_BUFF_ITEM_LIST_RES* mpClanShopGetBuffItemListPacket;  // offset: 0x3d0
    nUserSession::CPacket_S2C_CLAN_GET_HISTORY_RES* mpClanGetHistoryPacket;  // offset: 0x3d8
    nUserSession::CPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES* mpGetAcquirableNormalSkillListPacket;  // offset: 0x3e0
    nUserSession::CPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES* mpGetAcquirableSkillListPacket;  // offset: 0x3e8
    nUserSession::CPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES* mpGetAcquirableAbilityListPacket;  // offset: 0x3f0
    nUserSession::CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES* mpGetLearnedNormalSkillListPacket;  // offset: 0x3f8
    nUserSession::CPacket_S2C_GET_LEARNED_SKILL_LIST_RES* mpGetLearnedSkillListPacket;  // offset: 0x400
    nUserSession::CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES* mpGetLearnedAbilityListPacket;  // offset: 0x408
    nUserSession::CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES* mpGetPawnLearnedNormalSkillListPacket;  // offset: 0x410
    nUserSession::CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES* mpGetPawnLearnedSkillListPacket;  // offset: 0x418
    nUserSession::CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES* mpGetPawnLearnedAbilityListPacket;  // offset: 0x420
    nUserSession::CPacket_S2C_GET_SET_SKILL_LIST_RES* mpGetSetSkillListPacket;  // offset: 0x428
    nUserSession::CPacket_S2C_GET_SET_ABILITY_LIST_RES* mpGetSetAbilityListPacket;  // offset: 0x430
    nUserSession::CPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES* mpGetPawnSetSkillListPacket;  // offset: 0x438
    nUserSession::CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES* mpGetPawnSetAbilityListPacket;  // offset: 0x440
    nUserSession::CPacket_S2C_GET_RELEASE_SKILL_LIST_RES* mpGetReleaseSkill_ListPacket;  // offset: 0x448
    nUserSession::CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES* mpGetReleaseAbilityListPacket;  // offset: 0x450
    nUserSession::CPacket_S2C_GET_PRESET_ABILITY_LIST_RES* mpGetPresetAbilityListPacket;  // offset: 0x458
    nUserSession::CPacket_S2C_GET_ABILITY_COST_RES* mpGetAbilityCostPacket;  // offset: 0x460
    nUserSession::CPacket_S2C_GET_PAWN_ABILITY_COST_RES* mpGetPawnAbilityCostPacket;  // offset: 0x468
    nUserSession::CPacket_S2C_GET_SHOP_GOODS_LIST_RES* mpGetShopGoodsListPacket;  // offset: 0x470
    nUserSession::CPacket_S2C_GET_STAY_PRICE_RES* mpGetStayPricePacket;  // offset: 0x478
    nUserSession::CPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES* mpGetPenaltyHealStayPricePacket;  // offset: 0x480
    nUserSession::CPacket_S2C_GET_AREA_MASTER_INFO_RES* mpGetAreaMasterInfoPacket;  // offset: 0x488
    nUserSession::CPacket_S2C_AREA_RANK_UP_RES* mpAreaRankUpPacket;  // offset: 0x490
    nUserSession::CPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES* mpGetLeaderAreaReleasePacket;  // offset: 0x498
    nUserSession::CPacket_S2C_GET_AREA_SUPPLY_INFO_RES* mpGetAreaSupplyInfoListPacket;  // offset: 0x4a0
    nUserSession::CPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES* mpGetAreaQuestInfoListPacket;  // offset: 0x4a8
    nUserSession::CPacket_S2C_GET_SPOT_INFO_LIST_RES* mpGetSpotInfoListPacket;  // offset: 0x4b0
    nUserSession::CPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES* mpReportJobOrderProgressPacket;  // offset: 0x4b8
    nUserSession::CPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES* mpGetReleaseOrbElementListPacket;  // offset: 0x4c0
    nUserSession::CPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES* mpGetReleasePawnOrbElementListPacket;  // offset: 0x4c8
    nUserSession::CPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES* mpGetAllJobOrbElementListPacket;  // offset: 0x4d0
    nUserSession::CPacket_S2C_GET_JOB_CHANGE_LIST_RES* mpGetJobChangeListPacket;  // offset: 0x4d8
    nUserSession::CPacket_S2C_CHANGE_JOB_RES* mpChangeJobPacket;  // offset: 0x4e0
    nUserSession::CPacket_S2C_CHANGE_PAWN_JOB_RES* mpChangePawnJobPacket;  // offset: 0x4e8
    nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES* mpEntryBoardItemListPacket;  // offset: 0x4f0
    nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE* mpEntryBoardItemReservePacket;  // offset: 0x4f8
    nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_INFO_RES* mpEntryBoardItemInfoPacket;  // offset: 0x500
    nUserSession::CPacket_S2C_MAIL_GET_TEXT_RES* mpMailGetTextPacket;  // offset: 0x508
    nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES* mpSysMailGetTextPacket;  // offset: 0x510
    nUserSession::CPacket_S2C_RANKING_BOARD_LIST_RES* mpRankingBoardListPacket;  // offset: 0x518
    nUserSession::CPacket_S2C_RANKING_DATA_RANK_RES* mpRankingDataRankPacket;  // offset: 0x520
    nUserSession::CPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES* mpRankingDataRankByQuestScheduleIdPacket;  // offset: 0x528
    nUserSession::CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES* mpRankingDataCharacterIdPacket;  // offset: 0x530
    nUserSession::CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES* mpArisenCardBGListPacket;  // offset: 0x538
    nUserSession::CPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES* mpAchievementGetProgressListPacket;  // offset: 0x540
    nUserSession::CPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES* mpAchievementGetRewardListPacket;  // offset: 0x548
    nUserSession::CPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES* mpAchievementGetFurnitureRewardListPacket;  // offset: 0x550
    nUserSession::CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES* mpAchievementGetReceiveableRewardListPacket;  // offset: 0x558
    nUserSession::CPacket_S2C_ACHIEVEMENT_REWARD_RECEIVE_RES* mpAchievementRewardReceivePacket;  // offset: 0x560
    nUserSession::CPacket_S2C_GACHA_LIST_RES* mpGetGachaListPacket;  // offset: 0x568
    nUserSession::CPacket_S2C_GACHA_BUY_RES* mpGetGachaBuyPacket;  // offset: 0x570
    nUserSession::CPacket_S2C_BOX_GACHA_LIST_RES* mpGetBoxGachaListPacket;  // offset: 0x578
    nUserSession::CPacket_S2C_BOX_GACHA_BUY_RES* mpGetBoxGachaBuyPacket;  // offset: 0x580
    nUserSession::CPacket_S2C_BOX_GACHA_RESET_RES* mpGetBoxGachaResetPacket;  // offset: 0x588
    nUserSession::CPacket_S2C_BOX_GACHA_DRAW_INFO_RES* mpGetBoxGachaDrawInfoPacket;  // offset: 0x590
    nUserSession::CPacket_S2C_LOADING_GET_INFO_RES* mpLoadingInfoSchedules;  // offset: 0x598
    nUserSession::CPacket_S2C_STAMP_BONUS_GET_LIST_RES* mpStampBonusGetListPacket;  // offset: 0x5a0
    nUserSession::CPacket_S2C_STAMP_BONUS_CHECK_RES* mpStampBonusCheckPacket;  // offset: 0x5a8
    DLCLineupBoughtVec* mpDLCLineupBoughts;  // offset: 0x5b0
    DLCLineupHistoryVec* mpDLCLineupHistorys;  // offset: 0x5b8
    s32 mDLCLineupUseResult;  // offset: 0x5c0
    cGameTimeWeatherMoonInfo* mpGameTimeWeatherMoonInfo;  // offset: 0x5c8
    nUserSession::CPacket_S2C_SUPPORT_POINT_GET_RATE_RES* mpSupportPointRate;  // offset: 0x5d0
    nUserSession::CPacket_S2C_SUPPORT_POINT_USE_RES* mpSupportPointUse;  // offset: 0x5d8
    nUserSession::CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES* mpScreenShotCategory;  // offset: 0x5e0
    nUserSession::CPacket_S2C_GET_ITEM_STORAGE_INFO_RES* mpItemStorageInfo;  // offset: 0x5e8
    nUserSession::CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES* mpDispelItemSetting;  // offset: 0x5f0
    nUserSession::CPacket_S2C_GET_DISPEL_ITEM_LIST_RES* mpDispelItemList;  // offset: 0x5f8
    nUserSession::CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES* mpExchangeDispelItem;  // offset: 0x600
    nUserSession::CPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES* mpPlayPointShopLineup;  // offset: 0x608
    nUserSession::CPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES* mpPlayPointShopBuy;  // offset: 0x610
    nUserSession::CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_INFO_RES* mpPawnExpeditionSallyInfo;  // offset: 0x618
    nUserSession::CPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES* mpPawnExpeditionMySallyInfo;  // offset: 0x620
    nUserSession::CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES* mpPawnExpeditionSallyReward;  // offset: 0x628
    nUserSession::CPacket_S2C_WEATHER_FORECAST_GET_RES* mpWeatherForecast;  // offset: 0x630
private:
    MtString mCogSessionKey;  // offset: 0x638
public:
    static MyDTI DTI;
protected:
    static BOOL(THISCLASS::*S2C_OnPacketFuncTbl[])(CPacket*);
    static const u32 mS2C_OnPacketFuncNum;
};

class cNetGameServer : public MtObject
{
    // inferred: cMenuBlackList::initBlackList names cNetGameServer::mBlackList.::MtArray::mLength
    friend class cMenuBlackList;
    // inferred: cMenuCancelClanScoutEntry::moveCancelClanScoutEntry names cNetGameServer::mStatus[297]
    friend class cMenuCancelClanScoutEntry;
    // inferred: cMenuExtendEntryBoardItem::moveExtendEntryBoardItem names cNetGameServer::mStatus[402]
    friend class cMenuExtendEntryBoardItem;
    // inferred: cMenuFriendList::getListType names cNetGameServer::mApplyingFriendList.::MtArray::mLength
    friend class cMenuFriendList;
    // inferred: cMenuGetClanBaseInfo::moveGetClanBaseInfo names cNetGameServer::mStatus[308]
    friend class cMenuGetClanBaseInfo;
    // inferred: cMenuGetCraftRecipeToServer::moveGetCraftRecipeToServer names cNetGameServer::mStatus[528]
    friend class cMenuGetCraftRecipeToServer;
    // inferred: cMenuGetMyClan::moveGetMyClan names cNetGameServer::mStatus[288]
    friend class cMenuGetMyClan;
    // inferred: cMenuGetMyScoutEntry::moveGetMyScoutEntry names cNetGameServer::mStatus[299]
    friend class cMenuGetMyScoutEntry;
    // inferred: cMenuLeaveGroupChat::moveLeaveGroupChat names cNetGameServer::mStatus[444]
    friend class cMenuLeaveGroupChat;
    // inferred: cMenuMail::getListCount names cNetGameServer::mMailList.::MtArray::mLength
    friend class cMenuMail;
    // inferred: cMenuPartyList::initPartyList names cNetGameServer::mPartyListInfoVec.::MtArray::mLength
    friend class cMenuPartyList;
    // inferred: cMenuPawnHistory::exitMenu names cNetGameServer::mPawnHistoryList.::MtArray::mLength
    friend class cMenuPawnHistory;
    // inferred: cMenuPawnSearch::exitMenu names cNetGameServer::mRegisterdPawnList.::MtArray::mLength
    friend class cMenuPawnSearch;
    // inferred: cMenuQuickMatchRetry::moveQuickMatchRetry names cNetGameServer::mQuickPartySetting
    friend class cMenuQuickMatchRetry;
    // inferred: cMenuSimplePartyReq::exitMenu names cNetGameServer::mPartyListInfoVec.::MtArray::mLength
    friend class cMenuSimplePartyReq;
    // inferred: nSessionManager::cNetSessionManager::isPartyLeader names cNetGameServer::mLeaderCharacterId
    friend class nSessionManager::cNetSessionManager;
    // inferred: sContextManager::move names cNetGameServer::mIsResetInstanceArea
    friend class sContextManager;
    // inferred: sCraftManager::getMyPawnNum names cNetGameServer::mMyPawnList.::MtArray::mLength
    friend class sCraftManager;
    // inferred: sGame::isMySelfCharacterId names cNetGameServer::mLobbyCharacterId
    friend class sGame;
    // inferred: sNetworkExt::clearFriendInfo names cNetGameServer::mFriendList.::MtArray::mLength
    friend class sNetworkExt;
    // inferred: uGUILoginBonus::updateExit names cNetGameServer::mStatus[481]
    friend class uGUILoginBonus;
    // inferred: uGUIRimWarp::updateFavoriteList names cNetGameServer::mLeaderCharacterId
    friend class uGUIRimWarp;
public:
    enum SEARCH_TYPE
    {
        SEARCH_TYPE_NONE = 0,
        SEARCH_TYPE_PARTY = 1,
        SEARCH_TYPE_QUICK = 2,
        SEARCH_TYPE_CHARACTER = 3,
        SEARCH_TYPE_PAWN = 4,
        SEARCH_TYPE_CLAN = 5,
        SEARCH_TYPE_ENTRY_BOARD = 6,
    };
    enum PAWN_LIST_TYPE
    {
        LIST_TYPE_MY_PAWN = 0,
        LIST_TYPE_REGISTERD_PAWN = 1,
        LIST_TYPE_RENTED_PAWN = 2,
    };
    enum
    {
        COM_DUMMY = 0,
        COM_DROP = 1,
        COM_LOGIN = 2,
        COM_LOGOUT = 3,
        COM_GET_LOGIN_ANNOUNCE = 4,
        COM_MOVE_IN_SERVER = 5,
        COM_MOVE_OUT_SERVER = 6,
        COM_GET_SERVER_LIST = 7,
        COM_GET_GAME_SETTING = 8,
        COM_GET_WORLD_INFO = 9,
        COM_SET_WORLD_INFO = 10,
        COM_GET_REAL_TIME = 11,
        COM_CREATE_CHAR = 12,
        COM_GET_CHAR_LIST = 13,
        COM_DECIDE_CHAR_ID = 14,
        COM_GET_CHAR_INFO = 15,
        COM_SET_CHAR_INFO = 16,
        COM_DELETE_CHAR = 17,
        COM_GET_CHAR_PROFILE = 18,
        COM_GET_MY_CHAR_PROFILE = 19,
        COM_JOIN_LOBBY = 20,
        COM_LEAVE_LOBBY = 21,
        COM_GET_USER_LIST = 22,
        COM_USER_LIST_MAX_NUM = 23,
        COM_RESERVE_SERVER = 24,
        COM_SEND_CHAT_MSG = 25,
        COM_SEND_TELL_CHAT_MSG = 26,
        COM_SEND_DATA_MSG = 27,
        COM_CREATE_PARTY = 28,
        COM_SEARCH_PARTY = 29,
        COM_PARTY_MEMBER_SET_VALUE = 30,
        COM_INVITE_PARTY = 31,
        COM_INVITE_PARTY_CHAR = 32,
        COM_CANCEL_INVITE_PARTY = 33,
        COM_REFUSE_INVITE_PARTY = 34,
        COM_PREPARE_ACCEPT_INVITE_PARTY = 35,
        COM_JOIN_INVITE_PARTY = 36,
        COM_JOIN_PARTY = 37,
        COM_SET_INVITE_ACCEPT = 38,
        COM_GET_PARTY_CONTENT_NUMBER = 39,
        COM_LEAVE_PARTY = 40,
        COM_KICK_PARTY = 41,
        COM_BREAKUP_PARTY = 42,
        COM_LEADER_CHANGE = 43,
        COM_PLAY_ENTRY = 44,
        COM_PLAY_ENTRY_CANCEL = 45,
        COM_PLAY_START = 46,
        COM_PLAY_END = 47,
        COM_INVITE_ENTRY = 48,
        COM_INVITE_ENTRY_CANCEL = 49,
        COM_GET_AREA_INFO_LIST = 50,
        COM_GET_AREA_BONUS_LIST = 51,
        COM_GET_QUEST_PARTY_BONUS_LIST = 52,
        COM_SEND_LEADER_QUEST_ORDER_CONDITION_INFO = 53,
        COM_SEND_LEADER_WAIT_ORDER_QUEST_LIST = 54,
        COM_QUICK_PARTY_REGISTER = 55,
        COM_QUICK_PARTY_REGISTER_QUEST = 56,
        COM_QUICK_PARTY_ENTRY = 57,
        COM_CREATE_UPDATE_MYPAWN = 58,
        COM_GET_RANDOM_PAWN_EDIT_DATA = 59,
        COM_DELETE_MYPAWN = 60,
        COM_GET_MYPAWN_LIST = 61,
        COM_GET_MYPAWN_DATA = 62,
        COM_REGISTER_MYPAWN = 63,
        COM_GET_REGISTERED_PAWN_LIST = 64,
        COM_GET_REGISTERED_PAWN_LIST_BY_CHARACTER = 65,
        COM_GET_REGISTERED_PAWN_DATA = 66,
        COM_GET_NORA_PAWN_DATA = 67,
        COM_RENT_REGISTERED_PAWN = 68,
        COM_GET_RENTED_PAWN_LIST = 69,
        COM_GET_RENTED_PAWN_DATA = 70,
        COM_RETURN_RENTED_PAWN = 71,
        COM_GET_PARTY_PAWN_DATA = 72,
        COM_JOIN_PARTY_MYPAWN = 73,
        COM_JOIN_PARTY_RENTED_PAWN = 74,
        COM_PAWN_LOST = 75,
        COM_GET_LOST_PAWN_LIST = 76,
        COM_LOST_PAWN_REVIVE = 77,
        COM_LOST_PAWN_POINT_REVIVE = 78,
        COM_LOST_PAWN_GOLDEN_REVIVE = 79,
        COM_LOST_PAWN_WALLET_REVIVE = 80,
        COM_RENTAL_PAWN_LOST = 81,
        COM_GET_FAVORITE_PAWN_LIST = 82,
        COM_SET_FAVORITE_PAWN = 83,
        COM_DELETE_FAVORITE_PAWN = 84,
        COM_GET_OFFICIAL_PAWN_LIST = 85,
        COM_GET_LEGEND_PAWN_LIST = 86,
        COM_GET_NORA_PAWN_LIST = 87,
        COM_GET_FREE_RENTAL_PAWN_LIST = 88,
        COM_UPDATE_PAWN_REACTION_LIST = 89,
        COM_UPDATE_PAWN_SHARE_RANGE = 90,
        COM_GET_PAWN_HISTORY_LIST = 91,
        COM_GET_PAWN_TOTAL_SCORE = 92,
        COM_GET_BAG_ITEM_LIST = 93,
        COM_USE_BAG_ITEM = 94,
        COM_CONSUME_BAG_ITEM = 95,
        COM_USE_JOB_ITEM = 96,
        COM_GET_STORAGE_ITEM_LIST = 97,
        COM_STORE_STORAGE_ITEM = 98,
        COM_LOAD_STORAGE_ITEM = 99,
        COM_CONSUME_STORAGE_ITEM = 100,
        COM_EXCHANGE_SLOT_ITEM = 101,
        COM_SEPARATE_SLOT_ITEM = 102,
        COM_COLLECT_SLOT_ITEM = 103,
        COM_GET_REWARD_ITEM_LIST = 104,
        COM_GET_REWARD_ITEM = 105,
        COM_DEBUG_GET_ITEM = 106,
        COM_DEBUG_ADD_EQUIP_ITEM = 107,
        COM_DEBUG_CONSUME_ITEM = 108,
        COM_GET_GOLD = 109,
        COM_DEBUG_ADD_GOLD = 110,
        COM_DEBUG_SUB_GOLD = 111,
        COM_GET_RIM = 112,
        COM_DEBUG_ADD_RIM = 113,
        COM_DEBUG_SUB_RIM = 114,
        COM_GET_UROCO = 115,
        COM_DEBUG_ADD_UROCO = 116,
        COM_DEBUG_SUB_UROCO = 117,
        COM_GET_LIGHT_QUEST_LIST = 118,
        COM_GET_SET_QUEST_LIST = 119,
        COM_GET_MAIN_QUEST_LIST = 120,
        COM_GET_TUTORIAL_QUEST_LIST = 121,
        COM_GET_TIME_LIMITED_QUEST_LIST = 122,
        COM_GET_WORLD_MANAGE_QUEST_LIST = 123,
        COM_GET_CLAN_QUEST_LIST = 124,
        COM_GET_LOT_QUEST_LIST = 125,
        COM_GET_MAIN_QUEST_COMPLETE_INFO = 126,
        COM_GET_SET_QUEST_INFO_LIST = 127,
        COM_GET_CYCLE_CONTENTS_NEWS_LIST = 128,
        COM_GET_RECOMMENDED_QUEST_INFO_LIST = 129,
        COM_QUEST_ORDER = 130,
        COM_QUEST_PROGRESS = 131,
        COM_QUEST_CANCEL = 132,
        COM_GET_QUEST_DETAIL_LIST = 133,
        COM_QUEST_COMPLETE_FLAG_CLEAR = 134,
        COM_GET_QUEST_COMPLETE_LIST = 135,
        COM_GET_SET_QUEST_OPEN_DATE_LIST = 136,
        COM_GET_QUEST_LAYOUT_FLAG = 137,
        COM_SET_QUEST_FLAG = 138,
        COM_GET_PRIORITY_QUEST = 139,
        COM_SET_PRIORITY_QUEST = 140,
        COM_CANCEL_PRIORITY_QUEST = 141,
        COM_END_DISTRIBUTION_QUEST_CANCEL = 142,
        COM_LEADER_QUEST_PROGRESS_REQUEST = 143,
        COM_LIGHT_QUEST_ALL_COMPLETE = 144,
        COM_DEBUG_QUEST_FORCE_PROGRESS = 145,
        COM_DEBUG_MAIN_QUEST_JUMP = 146,
        COM_DEBUG_QUEST_RESET = 147,
        COM_DEBUG_QUEST_RESET_ALL = 148,
        COM_DEBUG_GET_QUEST_LAYOUT_FLAG = 149,
        COM_DEBUG_CYCLE_CONTENTS_POINT_UPLOAD = 150,
        COM_DEBUG_GET_QUEST_FLAG = 151,
        COM_GET_REWARD_BOX_LIST = 152,
        COM_GET_REWARD_BOX_LIST_NUM = 153,
        COM_GET_REWARD_BOX_ITEM = 154,
        COM_GET_CYCLE_CONTENTS_REWARD_LIST = 155,
        COM_GET_CYCLE_CONTENTS_REWARD_LIST_NUM = 156,
        COM_GET_CYCLE_CONTENTS_REWARD_ITEM = 157,
        COM_DELIVER_ITEM = 158,
        COM_DECIDE_DELIVERY_ITEM = 159,
        COM_GET_PARTY_QUEST_PROGRESS_INFO = 160,
        COM_CHECK_QUEST_DISTRIBUTION = 161,
        COM_SET_RETURN_SESSION_FOR_PRT = 162,
        COM_GET_CYCLE_CONTENTS_STATE_LIST = 163,
        COM_GET_CYCLE_CONTENTS_SITUATION_INFO_LIST = 164,
        COM_CYCLE_CONTENTS_PLAY_START = 165,
        COM_GET_CYCLE_CONTENTS_BORDER_REWARD_LIST = 166,
        COM_GET_CYCLE_CONTENTS_RANKING_REWARD_LIST = 167,
        COM_GET_CYCLE_CONTENTS_REWARD = 168,
        COM_PAWN_DUNGEON_REWARD_LIST = 169,
        COM_PAWN_DUNGEON_REWARD_SELECT = 170,
        COM_PING = 171,
        COM_CREATE_MATCH = 172,
        COM_JOIN_MATCH = 173,
        COM_GET_STAGE_LIST = 174,
        COM_AREA_CHANGE = 175,
        COM_GET_ENEMY_SET_LIST = 176,
        COM_ENEMY_KILL = 177,
        COM_GET_ITEM_SET_LIST = 178,
        COM_GET_GATHERING_ITEM_LIST = 179,
        COM_GET_GATHERING_ITEM = 180,
        COM_DEBUG_ENEMY_SET_PRESET_FIX = 181,
        COM_SET_OM_INSTANT_KEY_VALUE = 182,
        COM_GET_OM_INSTANT_KEY_VALUE = 183,
        COM_GET_OM_INSTANT_KEY_VALUE_ALL = 184,
        COM_EXCHANGE_OM_INSTANT_KEY_VALUE = 185,
        COM_SET_INSTANT_KEY_VALUE_UL = 186,
        COM_GET_INSTANT_KEY_VALUE_UL = 187,
        COM_SET_INSTANT_KEY_VALUE_STR = 188,
        COM_GET_INSTANT_KEY_VALUE_STR = 189,
        COM_GET_DROP_ITEM_SET_LIST = 190,
        COM_GET_DROP_ITEM_LIST = 191,
        COM_GET_DROP_ITEM = 192,
        COM_PL_TOUCH_OM_NOTICE = 193,
        COM_GET_TRAINING_ROOM_ENEMY_LIST = 194,
        COM_SET_TRAINING_ROOM_ENEMY = 195,
        COM_PLAY_START_TIMER = 196,
        COM_PLAY_INTERRUPT = 197,
        COM_PLAY_INTERRUPT_ANSWER = 198,
        COM_CYCLE_CONTENTS_PLAY_END = 199,
        COM_GET_CYCLE_CONTENTS_POINT_LIST = 200,
        COM_GET_CYCLE_CONTENTS_NOW_POINT_LIST = 201,
        COM_GET_END_CONTENTS_GROUP = 202,
        COM_GET_QUEST_SCHEDULE = 203,
        COM_GET_GP = 204,
        COM_GP_GET_DETAIL_HISTORY = 205,
        COM_GET_GP_PERIOD = 206,
        COM_GET_CAP = 207,
        COM_GET_CAP_TO_GP_CHANGE_LIST = 208,
        COM_CHANGE_CAP_TO_GP = 209,
        COM_GET_COG_ID = 210,
        COM_GP_SHOP_GET_COURSE_LINEUP = 211,
        COM_GP_SHOP_GET_ITEM_LINEUP = 212,
        COM_GP_SHOP_GET_PAWN_LINEUP = 213,
        COM_GP_SHOP_BUY_COURSE = 214,
        COM_GP_SHOP_BUY_ITEM = 215,
        COM_GP_SHOP_BUY_PAWN = 216,
        COM_GP_COURSE_GET_AVAILABLE_LIST = 217,
        COM_GP_COURSE_USE_FROM_AVAILABLE = 218,
        COM_GP_COURSE_GET_VALID_LIST = 219,
        COM_GP_SHOP_GET_BUY_HISTORY = 220,
        COM_GET_COG_CAPCHARGE_URL = 221,
        COM_GP_SHOP_GET_MENU_LIST = 222,
        COM_GP_SHOP_GET_LINEUP = 223,
        COM_GP_SHOP_BUY_REQ = 224,
        COM_COG_LOGIN_SKIP_FLAG = 225,
        COM_COG_LOGIN_SKIP_FLAG_OFF = 226,
        COM_GP_GET_COURSE_INFO = 227,
        COM_GP_GET_COURSE_VERSION = 228,
        COM_GP_EDIT_VOICE_GET_BUY_HISTORY_REQ = 229,
        COM_GP_EDIT_GET_VOICE_LIST_REQ = 230,
        COM_GP_EDIT_GET_GP_PRICE_REQ = 231,
        COM_GP_SHOP_CAN_BUY_PAWN = 232,
        COM_GP_SHOP_CAN_BUY_PAWN_VOICE = 233,
        COM_GET_CHARACTER_EQUIP_LIST = 234,
        COM_GET_PAWN_EQUIP_LIST = 235,
        COM_CHANGE_CHARACTER_EQUIP = 236,
        COM_CHANGE_CHARACTER_STORAGE_EQUIP = 237,
        COM_CHANGE_PAWN_EQUIP = 238,
        COM_CHANGE_PAWN_STORAGE_EQUIP = 239,
        COM_CHANGE_CHARACTER_EQUIP_JOB_ITEM = 240,
        COM_CHANGE_PAWN_EQUIP_JOB_ITEM = 241,
        COM_UPDATE_HIDE_CHARACTER_HEAD_ARMOR = 242,
        COM_UPDATE_HIDE_CHARACTER_LANTERN = 243,
        COM_UPDATE_HIDE_PAWN_HEAD_ARMOR = 244,
        COM_UPDATE_HIDE_PAWN_LANTERN = 245,
        COM_GET_EQUIP_PRESET_LIST = 246,
        COM_UPDATE_EQUIP_PRESET = 247,
        COM_UPDATE_EQUIP_PRESET_NAME = 248,
        COM_GET_CRAFT_PROGRESS_LIST = 249,
        COM_GET_CRAFT_PROGRESS = 250,
        COM_START_CRAFT = 251,
        COM_GET_CRAFT_PRODUCT_INFO = 252,
        COM_GET_CRAFT_PRODUCT = 253,
        COM_CANCEL_CRAFT = 254,
        COM_START_EQUIP_GRADE_UP = 255,
        COM_START_ATTACH_ELEMENT = 256,
        COM_START_DETACH_ELEMENT = 257,
        COM_START_EQUIP_COLOR_CHANGE = 258,
        COM_CRAFT_SKILL_UP = 259,
        COM_RELEASE_WARP_POINT = 260,
        COM_GET_WARP_POINT_LIST = 261,
        COM_GET_RELEASE_WARP_POINT_LIST = 262,
        COM_WARP = 263,
        COM_GET_FAVORITE_WARP_POINT_LIST = 264,
        COM_FAVORITE_WARP = 265,
        COM_REGISTER_FAVORITE_WARP = 266,
        COM_PARTY_WARP = 267,
        COM_GET_AREA_WARP_POINT_LIST = 268,
        COM_AREA_WARP = 269,
        COM_SET_OBJECTIVE = 270,
        COM_SET_MATCHING_PROFILE = 271,
        COM_GET_MATCHING_PROFILE = 272,
        COM_CHARACTER_SEARCH = 273,
        COM_SET_SEARCH_FILTER_LIST = 274,
        COM_GET_SEARCH_FILTER_LIST = 275,
        COM_SET_SHORTCUT_LIST = 276,
        COM_GET_SHORTCUT_LIST = 277,
        COM_SET_COMM_SHORTCUT_LIST = 278,
        COM_GET_COMM_SHORTCUT_LIST = 279,
        COM_SET_MESSAGE_SET = 280,
        COM_GET_MESSAGE_SET = 281,
        COM_GET_CLAN_LIST = 282,
        COM_REQ_JOIN_CLAN = 283,
        COM_GET_CLAN_APPLY_LIST = 284,
        COM_CANCEL_JOIN_CLAN = 285,
        COM_GET_CLAN_JOIN_REQ_LIST = 286,
        COM_ALLOW_CLAN = 287,
        COM_GET_MY_CLAN = 288,
        COM_CREATE_CLAN = 288,
        COM_UPDATE_CLAN = 288,
        COM_GET_CLAN_MEMBER_LIST = 289,
        COM_QUIT_CLAN = 290,
        COM_CLAN_EXPEL_MEMBER = 291,
        COM_CLAN_CHANGE_MASTER = 292,
        COM_CLAN_SET_MEMBER_RANK = 293,
        COM_GET_CLAN_INFO = 294,
        COM_GET_CLAN_MEMBER_NUM = 295,
        COM_REQ_CLAN_SCOUT_ENTRY = 296,
        COM_REQ_CLAN_SCOUT_ENTRY_CANCEL = 297,
        COM_SEARCH_CLAN_SCOUT_ENTRY = 298,
        COM_GET_MY_CLAN_SCOUT_ENTRY = 299,
        COM_INVITE_CLAN = 300,
        COM_GET_CLAN_INVITE_LIST = 301,
        COM_CANCEL_INVITE_CLAN = 302,
        COM_GET_CLAN_INVITED = 303,
        COM_ALLOW_INVITED_CLAN = 304,
        COM_CLAN_SETTING_UPDATE = 305,
        COM_CLAN_INVITE_DIRECT = 306,
        COM_CLAN_APPROVE_DIRECT = 307,
        COM_CLAN_BASE_INFO = 308,
        COM_CLAN_GET_HISTORY = 309,
        COM_SET_ONLINE_STATUS = 310,
        COM_GET_FRIEND_LIST = 311,
        COM_APPLY_FRIEND = 312,
        COM_CANCEL_FRIEND = 313,
        COM_APPROVE_FRIEND = 314,
        COM_REMOVE_FRIEND = 315,
        COM_SET_FAVORITE_FRIEND = 316,
        COM_GET_ACQUIRABLE_NORMAL_SKILL_LIST = 317,
        COM_GET_ACQUIRABLE_SKILL_LIST = 318,
        COM_GET_ACQUIRABLE_ABILITY_LIST = 319,
        COM_LEARN_NORMAL_SKILL = 320,
        COM_LEARN_SKILL = 321,
        COM_LEARN_ABILITY = 322,
        COM_LEARN_PAWN_NORMAL_SKILL = 323,
        COM_LEARN_PAWN_SKILL = 324,
        COM_LEARN_PAWN_ABILITY = 325,
        COM_GET_LEARNED_NORMAL_SKILL_LIST = 326,
        COM_GET_LEARNED_SKILL_LIST = 327,
        COM_GET_LEARNED_ABILITY_LIST = 328,
        COM_GET_PAWN_LEARNED_NORMAL_SKILL_LIST = 329,
        COM_GET_PAWN_LEARNED_SKILL_LIST = 330,
        COM_GET_PAWN_LEARNED_ABILITY_LIST = 331,
        COM_SET_SKILL = 332,
        COM_SET_ABILITY = 333,
        COM_SET_PAWN_SKILL = 334,
        COM_SET_PAWN_ABILITY = 335,
        COM_SET_OFF_SKILL = 336,
        COM_SET_OFF_ABILITY = 337,
        COM_SET_OFF_PAWN_SKILL = 338,
        COM_SET_OFF_PAWN_ABILITY = 339,
        COM_GET_SET_SKILL_LIST = 340,
        COM_GET_SET_ABILITY_LIST = 341,
        COM_GET_PAWN_SET_SKILL_LIST = 342,
        COM_GET_PAWN_SET_ABILITY_LIST = 343,
        COM_RELEASE_SKILL = 344,
        COM_RELEASE_ABILITY = 345,
        COM_GET_RELEASE_SKILL_LIST = 346,
        COM_GET_RELEASE_ABILITY_LIST = 347,
        COM_REGISTER_PRESET_ABILITY = 348,
        COM_SET_PRESET_ABILITY_LIST = 349,
        COM_GET_PRESET_ABILITY_LIST = 350,
        COM_SET_PAWN_PRESET_ABILITY_LIST = 351,
        COM_GET_CURRENT_SET_SKILL_LIST = 352,
        COM_GET_CURRENT_SET_ABILITY_LIST = 353,
        COM_GET_ABILITY_SET_COST_MAX = 354,
        COM_GET_PAWN_ABILITY_COST = 355,
        COM_SET_PRESET_ABILITY_NAME = 356,
        COM_GET_SHOP_GOODS_LIST = 357,
        COM_BUY_SHOP_GOODS = 358,
        COM_SHOP_SELL_ITEM = 359,
        COM_GET_STAY_PRICE = 360,
        COM_STAY_INN = 361,
        COM_GET_PENALTY_HEAL_STAY_PRICE = 362,
        COM_STAY_PENALTY_HEAL_INN = 363,
        COM_GET_AREA_MASTER_INFO = 364,
        COM_AREA_RANK_UP = 365,
        COM_ADD_AREA_POINT_DEBUG = 366,
        COM_GET_AREA_RELEASE_LIST = 367,
        COM_GET_LEADER_AREA_RELEASE_LIST = 368,
        COM_GET_AREA_SUPPLY_INFO_LIST = 369,
        COM_RECEIVE_AREA_SUPPLY = 370,
        COM_GET_AREA_QUEST_INFO_LIST = 371,
        COM_BUY_AREA_QUEST_INFO = 372,
        COM_GET_AREA_POINT_LIST = 373,
        COM_GET_SPOT_INFO_LIST = 374,
        COM_JOB_MASTER_ORDER_PROGRESS = 375,
        COM_REPORT_JOB_ORDER_PROGRESS = 376,
        COM_ACTIVATE_JOB_ORDER = 377,
        COM_DEBUG_ADD_JOB_ORDER_PROGRESS = 378,
        COM_GET_ORB_ELEMENT_LIST = 379,
        COM_DEVOTE_ORB = 380,
        COM_GET_RELEASE_ORB_ELEMENT_LIST = 381,
        COM_DEVOTE_PAWN_ORB = 382,
        COM_GET_RELEASE_PAWN_ORB_ELEMENT_LIST = 383,
        COM_GET_ORB_GAIN_EXTEND_PARAM = 384,
        COM_GET_JOB_ORB_TREE_LIST = 385,
        COM_GET_JOB_ORB_TREE_ELEMENT_LIST = 386,
        COM_RELEASE_JOB_ORB_TREE_ELEMENT = 387,
        COM_RANDOM_STAGE_GET_INFO = 388,
        COM_RANDOM_STAGE_CLEAR_INFO = 389,
        COM_GET_URL_LIST = 390,
        COM_GET_JOB_CHANGE_LIST = 391,
        COM_CHANGE_JOB = 392,
        COM_CHANGE_PAWN_JOB = 393,
        COM_CREATE_ENTRY_BOARD_ITEM = 394,
        COM_RECREATE_ENTRY_BOARD_ITEM = 395,
        COM_GET_ENTRY_BOARD_ITEM_LIST = 396,
        COM_JOIN_ENTRY_BOARD_ITEM = 397,
        COM_LEAVE_ENTRY_BOARD_ITEM = 398,
        COM_GET_ENTRY_BOARD_ITEM_INFO = 399,
        COM_READY_ENTRY_BOARD_ITEM = 400,
        COM_FORCE_START_ENTRY_BOARD = 401,
        COM_ENTRY_BOARD_EXTEND_TIMEOUT = 402,
        COM_ENTRY_BOARD_LOCK = 403,
        COM_ENTRY_BOARD_INFO_CHANGE = 404,
        COM_ENTRY_BOARD_INVITE = 405,
        COM_GET_LOBBY_PLAYER_CONTEXT = 406,
        COM_GET_PARTY_PLAYER_CONTEXT = 407,
        COM_GET_ALL_PLAYER_CONTEXT = 408,
        COM_GET_PARTY_MYPAWN_CONTEXT = 409,
        COM_GET_PARTY_RENTED_PAWN_CONTEXT = 410,
        COM_GET_SET_CONTEXT = 411,
        COM_MASTER_THROW = 412,
        COM_GET_MAIL_LIST_HEAD = 413,
        COM_GET_MAIL_LIST_DATA = 414,
        COM_GET_MAIL_LIST_FOOT = 415,
        COM_GET_MAIL_TEXT = 416,
        COM_DELETE_MAIL = 417,
        COM_SEND_MAIL = 418,
        COM_GET_SYS_MAIL_LIST_HEAD = 419,
        COM_GET_SYS_MAIL_LIST_DATA = 420,
        COM_GET_SYS_MAIL_LIST_FOOT = 421,
        COM_GET_SYS_MAIL_TEXT = 422,
        COM_GET_SYS_MAIL_ITEM = 423,
        COM_GET_SYS_MAIL_ITEM_ALL = 424,
        COM_DELETE_SYS_MAIL = 425,
        COM_GET_RANKING_BOARD_LIST = 426,
        COM_GET_RANKING_DATA_RANK = 427,
        COM_GET_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID = 428,
        COM_GET_RANKING_DATA_CHARACTER_ID = 429,
        COM_GET_BAZAAR_CHARACTER_LIST = 430,
        COM_GET_BAZAAR_ITEM_LIST = 431,
        COM_GET_BAZAAR_ITEM_INFO = 432,
        COM_GET_BAZAAR_ITEM_HISTORY_INFO = 433,
        COM_START_BAZAAR_EXHIBIT = 434,
        COM_RESTART_BAZAAR_EXHIBIT = 435,
        COM_CANCEL_BAZAAR = 436,
        COM_PROCEEDS_BAZAAR = 437,
        COM_RECEIVE_BAZAAR_PROCEEDS = 438,
        COM_GET_BAZAAR_ITEM_PRICE_LIMIT = 439,
        COM_GET_BAZAAR_EXHIBIT_POSSIBLE_NUM = 440,
        COM_GROUP_CHAT_MEMBER_LIST = 441,
        COM_GROUP_CHAT_INVITE = 442,
        COM_GROUP_CHAT_KICK = 443,
        COM_GROUP_CHAT_LEAVE = 444,
        COM_GET_RECENT_LIST = 445,
        COM_GET_BLACK_LIST = 446,
        COM_ADD_BLACK_LIST = 447,
        COM_REMOVE_BLACK_LIST = 448,
        COM_GET_RETURN_LOCATION = 449,
        COM_GET_ACHIEVEMENT_PROGRESS = 450,
        COM_GET_ACHIEVEMENT_REWARD = 451,
        COM_CHARACTER_POINT_REVIVE = 452,
        COM_CHARACTER_GOLDEN_REVIVE = 453,
        COM_CHARACTER_PENALTY_REVIVE = 454,
        COM_PAWN_POINT_REVIVE = 455,
        COM_PAWN_GOLDEN_REVIVE = 456,
        COM_GET_REVIVE_CHARGEABLE_TIME = 457,
        COM_CHARGE_REVIVE_POINT = 458,
        COM_GET_REVIVE_POINT = 459,
        COM_QUICK_MATCH_WAIT = 460,
        COM_QUICK_MATCH_CANCEL = 461,
        COM_GET_POST_ITEM_LIST = 462,
        COM_MOVE_ITEM = 463,
        COM_SET_ARISEN_PROFILE = 464,
        COM_SET_PAWN_PROFILE = 465,
        COM_SET_PAWN_PROFILE_COMMENT = 466,
        COM_UPDATE_ARISEN_PROFILE_SHARE_RANGE = 467,
        COM_GET_AVAILABLE_BACKGROUND = 468,
        COM_GET_GACHA_LIST = 469,
        COM_GET_GACHA_BUY = 470,
        COM_GET_BOX_GACHA_LIST = 471,
        COM_GET_BOX_GACHA_BUY = 472,
        COM_GET_BOX_GACHA_RESET = 473,
        COM_GET_BOX_GACHA_DRAW_INFO = 474,
        COM_GET_UNLOCKED_EDIT_PARTS_LIST = 475,
        COM_GET_UNLOCKED_PAWN_EDIT_PARTS_LIST = 476,
        COM_UPDATE_CHARACTER_EDIT_PARAM = 477,
        COM_UPDATE_PAWN_EDIT_PARAM = 478,
        COM_CLIENT_CHALLENGE = 479,
        COM_REQ_LOADING_INFO = 480,
        COM_STAMP_BONUS_GET_LIST = 481,
        COM_STAMP_BONUS_CHECK = 482,
        COM_STAMP_BONUS_RECIEVE = 483,
        COM_STAMP_BONUS_ADD_TOTAL_NUM = 484,
        COM_REPORT_SITE_GET_ADDRESS = 485,
        COM_EVENT_CODE_INPUT = 486,
        COM_URL_GET_LIST = 487,
        COM_REQ_DLC_BOUGHTS = 488,
        COM_REQ_DLC_USE = 489,
        COM_REQ_DLC_HISTORYS = 490,
        COM_REQ_GET_SESSION_KEY = 491,
        COM_NG_WORD_GET_LIST = 492,
        COM_REQ_GET_GAME_TIME_BASEINFO = 493,
        COM_REQ_COMM_STATUS_GET = 494,
        COM_SUPPORT_POINT_GET_RATE_LIST = 495,
        COM_SUPPORT_POINT_USE = 496,
        COM_ITEM_SORTDATA_GET_BIN = 497,
        COM_ITEM_SORTDATA_SET_BIN = 498,
        COM_SCREEN_SHOT_CATEGORY = 499,
        COM_PHOTO_GET_AUTH_ADDRESS = 500,
        COM_GET_ITEM_STORAGE_INFO = 501,
        COM_SERVER_UI_COMMAND = 502,
        COM_GET_DISPEL_ITEM_SETTING = 503,
        COM_GET_DISPEL_ITEM_LIST = 504,
        COM_EXCHANGE_DISPEL_ITEM = 505,
        COM_RESET_JOBPOINT = 506,
        COM_RESET_CRAFTPOINT = 507,
        COM_GET_CRAFT_SETTING = 508,
        COM_CRAFT_TIME_SAVE = 509,
        COM_GET_CRAFT_COLOR_REGULATE_ITEM_LIST = 510,
        COM_GET_CRAFT_IR_COLLECTION_VALUE_LIST = 511,
        COM_MY_ROOM_RELEASE = 512,
        COM_FURNITURE_LIST_GET = 513,
        COM_FURNITURE_LAYOUT = 514,
        COM_FURNITURE_REWARD_RECIPE_LIST_GET = 515,
        COM_FURNITURE_REWARD_RECIPE_GET = 516,
        COM_RELEASED_CRAFT_RECIPE_LIST_GET = 517,
        COM_PARTNER_PAWN_SET_GET = 518,
        COM_RELEASED_EDIT_PARTS_LIST_GET = 519,
        COM_RELEASED_EMOTION_LIST_GET = 520,
        COM_RELEASED_PAWN_TALK_LIST_GET = 521,
        COM_PAWN_LIKABILITY_REWARD_LIST_GET = 522,
        COM_PAWN_LIKABILITY_REWARD_GET = 523,
        COM_PAWN_LIKABILITY_RELEASED_REWARD_LIST_GET = 524,
        COM_PARTNER_PAWN_NEXT_PRESENT_TIME_GET = 525,
        COM_PRESENT_FOR_PARTNER_PAWN = 526,
        COM_GET_CAPLINK_ACHIEVE_REWARD = 527,
        COM_GET_CRAFT_RECIPE = 528,
        COM_GET_CRAFT_RECIPE_DESIGNATE = 529,
        COM_GET_CRAFT_GRADEUP_RECIPE = 530,
        COM_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST = 531,
        COM_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST = 532,
        COM_ACHIEVEMENT_REWARD_RECEIVE = 533,
        COM_GET_EXP_MODE = 534,
        COM_UPDATE_EXP_MODE = 535,
        COM_GET_PLAY_POINT_LIST = 536,
        COM_GET_PLAY_POINT_SHOP_LINEUP = 537,
        COM_PLAY_POINT_SHOP_BUY = 538,
        COM_GET_CRAFT_LOCKED_ELEMENT_LIST = 539,
        COM_CLAN_CONCIERGE_UPDATE = 540,
        COM_GET_CLAN_CONCIERGE_LIST = 541,
        COM_CLAN_PARTNER_PAWN_LIST_GET = 542,
        COM_CLAN_PARTNER_PAWN_DATA_GET = 543,
        COM_CRAFT_SKILL_ANALYZE = 544,
        COM_CLAN_BASE_RELEASE = 545,
        COM_GET_CLAN_SHOP_FUNCTION_ITEM_LIST = 546,
        COM_GET_CLAN_SHOP_BUFF_ITEM_LIST = 547,
        COM_BUY_CLAN_SHOP_FUNCTION_ITEM = 548,
        COM_BUY_CLAN_SHOP_BUFF_ITEM = 549,
        COM_PAWN_EXPEDITION_REWARD_DROP_GET = 550,
        COM_PAWN_EXPEDITION_REWARD_DROP_ITEM_LIST_GET = 551,
        COM_PAWN_EXPEDITION_REWARD_DROP_ITEM_GET = 552,
        COM_MY_ROOM_BGM_UPDATE = 553,
        OCM_GET_WEATHER_FORECAST = 554,
        COM_PAWN_EXPEDITION_GET_SALLY_INFO = 555,
        COM_PAWN_EXPEDITION_GET_MY_SALLY_INFO = 556,
        COM_PAWN_EXPEDITION_CHARGE_SALLY_COUNT = 557,
        COM_PAWN_EXPEDITION_SALLY = 558,
        COM_PAWN_EXPEDITION_CHANGE_GOLDEN_SALLY = 559,
        COM_PAWN_EXPEDITION_GET_SALLY_REWARD = 560,
        COM_PAWN_EXPEDITION_CANCEL_SALLY = 561,
        COM_QUEST_LOG_INFO_GET = 562,
        COM_NUM = 563,
    };
    enum
    {
        FLOW_NOTHING = 0,
        FLOW_PARTY_FINAL = 1,
        FLOW_PARTY_CREATE = 2,
        FLOW_PARTY_JOIN = 3,
        FLOW_PARTY_QUICK_MATCH = 4,
        FLOW_CHANGE_SERVER = 5,
        FLOW_NUM = 6,
    };
    enum AREA_JUMP_TYPE
    {
        AREA_JUMP_TYPE_NONE = 0,
        AREA_JUMP_TYPE_WARP = 1,
    };
    enum REPORT_CHEAT_DATA_TYPE
    {
        REPORT_CHEAT_DATA_TYPE_NONE = 0,
        REPORT_CHEAT_DATA_TYPE_PARAM1 = 1,
        REPORT_CHEAT_DATA_TYPE_PARAM2 = 2,
        REPORT_CHEAT_DATA_TYPE_PARAM3 = 3,
    };
public:
    class MyDTI;
    class cCtrlFlow;
    struct LoginData;
    class cChatLog;
    struct PAWN_MEMBER_MIN_INFO;
    struct stCheatInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCtrlFlow : public MtObject
    {
    public:
        enum
        {
            COMMAND_NONE = 0,
            COMMAND_QMATCH_READY = 1,
            COMMAND_QMATCH_SUCCESS = 2,
            COMMAND_JOIN_START = 3,
            COMMAND_NUM = 4,
        };
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
        cCtrlFlow();
        // Address: 0x019afdd0 - 0x019afdd1 (1 bytes)
        virtual ~cCtrlFlow() {}
        void clear(bool isCallback);
        s32 getCommand();
        void setCommand(s32 comId);
        MtNetError* getError();
        s32 getErrCode();
        void setErrCode(s32 code);
        bool isError();
        bool isSuccess();
        bool isCallback();
    public:
        s32 mRno0;  // offset: 0x8
        s32 mRno1;  // offset: 0xc
        s32 mCommand;  // offset: 0x10
        MtNetError mError;  // offset: 0x14
        bool mIsCallback;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    struct LoginData
    {
    public:
        MT_CHAR mGameSvAddr[32];  // offset: 0x0
        MT_CHAR mSessionKey[64];  // offset: 0x20
        u32 mGameSvPort;  // offset: 0x60
        u32 mSelectServerNo;  // offset: 0x64
        u32 mCurrentServerNo;  // offset: 0x68
        bool mIsReceivedOpenKey;  // offset: 0x6c
        bool mIsReturnPrepare;  // offset: 0x6d
    };
public:
    class cChatLog : public MtObject
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
        cChatLog();
        cChatLog(MT_CTSTR, MT_CTSTR, nChatMsgType::E_CHAT_MSG_TYPE);
    private:
        MtString mName;  // offset: 0x8
        MtString mLog;  // offset: 0x10
        nChatMsgType::E_CHAT_MSG_TYPE mType;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    struct PAWN_MEMBER_MIN_INFO
    {
    public:
        u32 m_ucMemberType;  // offset: 0x0
        u32 m_unSlotNo;  // offset: 0x4
        u32 mPawnId;  // offset: 0x8
        s32 mReserveJob;  // offset: 0xc
    };
public:
    struct stCheatInfo
    {
    public:
        stCheatInfo();
        void init();
    public:
        u32 dataType;  // offset: 0x0
        u8 count;  // offset: 0x4
        u8 id;  // offset: 0x5
        u32 param1;  // offset: 0x8
        u32 param2;  // offset: 0xc
        u32 param3;  // offset: 0x10
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cNetGameServer();
    virtual ~cNetGameServer();
    bool isConnectedGameSvUIHide();
    bool isAfterLoginUIHide();
    void clear();
    void clearAll();
    void move();
    sNetworkExt::NET_STAT getStatus(u32 comId);
    nError::ERROR_CODE getErrorCode(u32 comId);
    bool sendStart(u32 commandId);
    bool sendStartBeforeLogin(u32 commandId);
    bool sendEnd(u32 commandId);
    bool sendEndNoTimeOut(u32 commandId);
    void recvResult(u32 commandId, MT_CTSTR funcStr, MT_CTSTR logStr, s32 error, bool isSuccessLog);
    void reqErrorDialog(u32 comId, s32 errNo);
    void setErrorDialogHandle(u32);
    u32 getErrorDialogHandle();
    bool isDispErrorDialog();
    void setIsNgErrorDialog(u32 comId, bool flag);
    bool isNgErrorDialog(u32 comId);
    void setIsOnceNgErrorDialog(u32 comId, bool flag);
    bool isOnceNgErrorDialog(u32 comId);
    bool isSearchErrorMessage(s32 errNo, MT_CTSTR* pMsg, MT_CTSTR* pMsg2);
    void setCommnadStatusReqToError();
    void debugErrorCheck(s32& err, u32 comId);
    void updateComTimer();
    f32 getComTimer(u32 comId);
    void startComTimer(u32 comId);
    void clearComTimer(u32 comId);
    void clearComTimerAll();
    void clearFlow(s32 flowId, bool isCallback);
    void allClearFlow();
    cCtrlFlow* getFlow(s32 flowId);
    cCtrlFlow& getFlowRef(s32 flowId);
    bool reqFinalParty(bool isCallback);
    bool finalPartyFlow();
    bool reqCreateParty(bool isInviteAccept);
    bool createPartyFlow();
    bool reqJoinInviteParty();
    bool reqJoinParty();
    bool joinPartyFlow();
    void dummyJoinPartyCallBack(void* param);
    bool reqQuickMatchParty(nNet::QUICK_MATCH_TYPE type, CQuickPartyMatching& matching);
    bool quickMatchPartyFlow();
    bool isQuickMatchReady();
    bool isQuickMatchSuccess();
    bool reqChangeServer();
    bool changeServerFlow();
    bool requestLogin();
    sNetworkExt::LOGIN_RET_STAT moveLogin();
    bool isExecLogin();
    void connectServer();
    void disconnect(bool isAbort);
    bool clientChallenge();
    bool login(MT_CTSTR sessionKey);
    bool logout();
    void sendGMMessage();
    bool getLoginAnnouncement();
    bool moveInServer(MT_CTSTR sessionKey);
    bool moveOutServer();
    bool getServerList();
    bool getGameSetting();
    bool reqEndReturnPrepare();
    MT_CTSTR getGameSvConnectStatusStr();
    sNetworkExt::NET_STAT getGameSvConnectStatus();
    bool isConnectServer();
    bool isLogin();
    sNetworkExt::NET_STAT getLoginStatus();
    void setGameSvAddr(MT_CTSTR strAddr);
    void getGameSvAddr(MT_CHAR* output) const;
    void setGameSvPort(u32 port);
    u32 getGameSvPort() const;
    void setSessionKey(MT_CTSTR strKey);
    void getSessionKey(MT_CHAR* output) const;
    bool isEnableSessionKey();
    void setSelectServerNo(u32 serverNo);
    u32 getSelectServerNo();
    void setCurrentServerNo(u32 serverNo);
    u32 getCurrentServerNo();
    CGameServerListInfo* getServerListInfo(u32 serverNo);
    CGameServerListInfo* getServerListInfo();
    u16 getServerUniqueId();
    bool isReturnPrepare();
    void setIsReturnPrepare(bool flag);
    bool isReceivedOpenKey();
    void setIsReceivedOpenKey(bool flag);
    void setPrologueServerInfo(MT_CTSTR addr, u32 port);
    void initPrologueServerInfo();
    MT_CTSTR getPrologueServerAddr() const;
    u16 getPrologueServerPort() const;
    bool isEmptyPrologueServerInfo();
    bool isCOGLogin() const;
    void setCOGLogin(bool IsLogin);
    nUserSession::CPacket_S2C_GET_SERVER_LIST_RES* getGetServerListPacket();
    nUserSession::CPacket_S2C_GET_GAME_SETTING_RES* getGetGameSettingPacket();
    void clearServerListPacket();
private:
    void getGameSvAddrPrivate(MT_CHAR* output) const;
    void setGameSvAddrPrivate(const MT_CHAR* NewValue);
    void getSessionKeyPrivate(MT_CHAR* output) const;
    void setSessionKeyPrivate(const MT_CHAR* NewValue);
    u32 getGameSvPortPrivate() const;
    void setGameSvPortPrivate(u32 NewValue);
    u32 getSelectServerNoPrivate() const;
    void setSelectServerNoPrivate(u32 NewValue);
    u32 getCurrentServerNoPrivate() const;
    void setCurrentServerNoPrivate(u32 NewValue);
    bool isReceivedOpenKeyPrivate() const;
    void setReceivedOpenKeyPrivate(bool NewValue);
    bool isReturnPreparePrivate() const;
    void setReturnPreparePrivate(bool NewValue);
public:
    MtCipher* getCipher();
    void getCommonKey(char* output);
    void clearCommonKey();
    bool sendGetWorldInfo();
    bool sendSetWorldInfo();
    s32 getGetWorldInfoSize();
    const CWorldInfo& getWorldInfo() const;
    const CWorldInfo* getWorldInfoPtr() const;
    bool createCharacter(cCharacterData* pCharData);
    void propCreateCharacter();
    bool getCharacterList();
    void propGetCharacterList();
    bool decideCharacterId(u32 characterId);
    bool sendGetCharacterInfo(cCharacterData* pCharData, s32 id);
    void propSendGetCharacterInfo();
    bool sendSetCharacterInfo(cCharacterData* pCharData);
    void propSendSetCharacterInfo();
    bool deleteCharacter(s32 id);
    void propDeleteCharacter();
    bool getCharacterProfile(u32 characterId, cCharacterData* pCharData, cContextInstHm* pContext);
    bool getCharacterProfileMySelf();
    bool setShortcutList(ShortCutVec& shortcutList);
    bool getShortcutList();
    bool setCommShortcutList(CommunicationShortCutVec& shortcutList);
    bool getCommShortcutList();
    bool setMessageSetList(CharacterMsgSetVec& msgSetList);
    bool getMessageSetList();
    u8 convSexForGame(nCharacter::E_EDIT_BODY_TYPE src) const;
    nCharacter::E_EDIT_BODY_TYPE convSexForServer(u8 src) const;
    CharacterListInfoVec* getCharacterListPtr();
    void setCustomCharacterDataPtr(cCharacterData* pCharData);
    cCharacterData* getCustomCharacterDataPtr();
    void setCharacterList(const CharacterListInfoVec& infos);
    bool isDeathPenaltyWait();
    void setDeathPenaltyWait(bool flag);
    bool setArisenProfile(const CArisenProfile& profile);
    bool setPawnProfile(unsigned int pawnId, const CArisenProfile& profile, const MtString& comment);
    bool setPawnProfileComment(unsigned int pawnId, const MtString& comment);
    bool updateArisenProfileShareRange(unsigned char arisenProfileShareRange, unsigned char pawnProfileShareRange);
    bool getAvailableBackgroundList();
    bool updateCharacterEditInfo(unsigned char type, const cCharacterData::stCharacterEdit& srcEditData, const cEditParam& editParam);
    bool updateCharacterEditInfo(unsigned char type, const CEditInfo& editInfo);
    bool updatePawnEditInfo(unsigned char slotNo, unsigned char type, const cCharacterData::stCharacterEdit& srcEditData, const cEditParam& editParam);
    bool updatePawnEditInfo(unsigned char slotNo, unsigned char type, const CEditInfo& editInfo);
    void updatePawnLvup(cContextInstHm* pDst, const CDataCharacterLevelParam& lvPrm, u32 lv, u32 job, u32 jobPoint);
    bool sendGetRealTime();
    s64 calcGameTimeMSec(s64 realTime, s64 msec);
    u32 getCalcWeather(s64 realTime);
    u32 getCalcMoonAge(s64 realTime);
    bool joinLobbyRequest();
    bool joinLobbyRequest(s32 characterId);
    bool leaveLobbyRequest();
    bool sendGetUserList();
    bool sendUserListMaxNum(u32 maxNum);
    bool sendReserveServer(u16 serverUniqueId, u32 type, const CommonU32Vec& reservationList);
    bool sendChatMessage(u32 type, MT_CTSTR str, u32 characterId);
    bool sendTellChatMessage(MT_CTSTR str, CCommunityCharacterBaseInfo& charInfo);
    void propSendChatMessage(u32);
    bool sendLobbyMessage(s32 msgType, s32 sendMemberType, u32 characterId, u8* data_ptr, u32 data_size);
    const CLobbyInfo* getLobbyInfo();
    void setLobbyInfo(const CLobbyInfo&);
    u32 getCharacterId();
    MT_CTSTR getCharacterName();
    const LobbyMemberInfoVec* getLobbyMembers();
    LobbyMemberInfoVec& getLobbyMembersRef();
    void setLobbyMembers(const LobbyMemberInfoVec& members);
    void addLobbyMember(const CLobbyMemberInfo& member);
    CLobbyMemberInfo* getLobbyMemberFromCharacterId(u32 characterId, u32 pawnId);
    u8 getLobbyMemberSessionStatus(u32 characterId, u32 pawnId);
    bool isLobbyMemberList();
    void clearLobbyMemberList();
    bool isLobbyMemberSessionNormal(u32);
    bool isLobbyMemberSessionLost(u32 characterId);
    void addUserListFromPartyMember(CPartyMember& src);
    void addUserListFromPartyMemberList(PartyMemberVec& vec);
    void removeUserList(u32 characterId, u32 pawnId);
    void removeUserListPartyMemberIndex(u32 memberIndex);
    const MT_ENUM* getCharacterEnumList();
    bool sendSetActiveQuest(u32 ScheduleId);
    bool sendCancelActiveQuest(u32 ScheduleId);
    bool sendGetActiveQuest();
    bool createParty();
    bool createParty(bool isInviteAccept, u8* pSessionBinary);
    bool setObjective(u8 no, u8 type);
    bool setObjective();
    bool setMatchingProfile(CMatchingProfile& matchingProfile);
    bool getMatchingProfile(u32 characterId);
    bool searchParty();
    bool searchCharacter();
    bool reqPartyMemberSetValue(s32 index, bool flag);
    bool inviteParty();
    bool inviteParty(u32 inviteServerNo, u32 invitePartyId, u32 sequenceId, u32 invitePartyNum);
    bool inviteParty(u32 characterId);
    void propInviteParty();
    bool cancelInviteParty();
    bool cancelInviteParty(u32 inviteServerNo, u32 invitePartyId);
    bool refuseInviteParty();
    bool prepareAcceptInviteParty();
    bool joinParty();
    bool joinParty(u32 partyId);
    bool getPartyContentNumber();
    bool leaveParty();
    bool kickParty();
    bool kickParty(s32 memberIndex);
    bool breakupParty();
    bool changePartyLeader();
    bool changePartyLeader(s32 leaderCharacterId);
    bool entryPlay();
    bool entryCancelPlay();
    bool startPlay();
    bool startPlay(u32 questScheduleId);
    bool endPlay();
    bool entryInvite();
    bool entryCancelInvite();
    bool sendBinary(s32 sendMemberType, u32 characterId, u8* data_ptr, u32 data_size);
    bool getQuestLogInfo();
    void copyPartyMemberList(PartyMemberVec* pDst, const PartyMemberVec* pSrc);
    void copyPartyListInfo(CClientPartyListInfo* pDst, const CPartyListInfo* pSrc, bool isDeserialize);
    void setPartyList(const PartyListInfoVec& list);
    ClientPartyListInfoVec& getPartyListRef();
    CClientPartyListInfo* getPartyListInfo(s32 partyId);
    void clearPartyList();
    CCommunityCharacterBaseInfo* getLeaderBaseInfo(const CPartyListInfo* ptr);
    s32 getCharacterIdFromPartyId(s32);
    s32 getPartyIdFromCharacterId(s32);
    void setPartyMemberInfoList(const CPartyMember& info);
    void setPartyMemberInfoList(u32 leaderCharacterId, u32 hostCharacterId, const PartyMemberVec& list, bool isClear);
    void erasePartyMemberInfo(u32 characterId);
    cPartyMemberInfoVec& getPartyMemberInfoListRef();
    cPartyMemberInfo* getPartyMemberInfo(s32 memberIndex);
    cPartyMemberInfo* getPartyMemberInfoFromCharacterId(u32 characterId);
    cPartyMemberInfo* getPartyMemberInfoFromPawnId(u32, u32);
    u32 getPartyMemberCharacterId(u32 memberIndex, bool pawnOK);
    void clearPartyMemberInfoList();
    void savePartyPawnMember(bool saveJob);
    nUserSession::CPacket_S2C_GET_MATCHING_PROFILE_RES* getGetMatchingProfilePacket();
    CMatchingProfile& getMatchingProfileRef();
    void clearGetMatchingProfilePacket();
    nUserSession::CPacket_S2C_CHARACTER_SEARCH_RES* getCharacterSearchPacket();
    CharacterListElementVec& getCharacterSearchListRef();
    void clearCharacterSearchPacket();
    nUserSession::CPacket_S2C_GET_SHORTCUT_LIST_RES* getGetShortcutListPacket();
    ShortCutVec& getShortcutListRef();
    nUserSession::CPacket_S2C_GET_COMMUNICATION_SHORTCUT_LIST_RES* getGetCommunicationShortcutListPacket();
    CommunicationShortCutVec& getCommunicationShortcutListRef();
    nUserSession::CPacket_S2C_GET_MESSAGE_SET_RES* getGetMessageSetPacket();
    CharacterMsgSetVec& getMessageSetRef();
    nUserSession::CPacket_S2C_PARTY_INVITE_JOIN_MEMBER_NTC* getPartyInviteJoinMemberPacket();
    s32 getPartyInviteJoinMemberNum();
    s32 getPartyInviteJoinPlayerMemberNum();
    s32 getPartyInviteJoinPawnMemberNum();
    CPartyMemberMinimum* getPartyInviteJoinMemberFromMemberIndex(s32);
    CPartyMemberMinimum* getPartyInviteJoinMemberFromCharacterId(u32 characterId);
    void deletePartyInviteJoinMember(s32 memberIndex);
    void deleteAllPartyInviteJoinMember();
    void setJoinPartyId(u32 partyId);
    u32 getJoinPartyId();
    void setIsPlayEntry(u32 characterId, bool flag);
    s32 getPlayEntryNum();
    bool isPlayEntry(s32 memberIndex);
    void setIsInviteEntry(u32 characterId, bool flag);
    s32 getInviteEntryNum();
    bool isInviteAcceptNotice();
    void setIsInviteAcceptNotice(bool flag);
    bool isJoinParty();
    void setIsJoinParty(bool flag);
    bool isLeader(u32 characterId);
    bool isLeader();
    void setLeader(u32 characterId);
    u32 getLeaderCharacterId();
    s32 getLeaderMemberIndex();
    void setLeaderFlag(u32 characterId);
    u32 getInviteLeaderCharacterId();
    CClientPartyListInfo& getInvitePartyListInfoRef();
    void setInviteTargetLeaderName(s32 partyId);
    MT_CTSTR getInviteTargetLeaderName();
    bool isValidPartyMember(s32);
    bool isValidPartyCharacter(s32 characterId);
    u32 convertCharacterIdFromMemberIndex(s32 memberIndex);
    s32 convertMemberIndexFromCharacterId(s32 characterId);
    s32 convertMemberIndexFromPawnId(u32 pawnId);
    s32 getSelfIndex();
    void setSelfIndex(s32 memberIndex);
    bool isMySelf(s32 memberIndex);
    bool isMySelfCharacterId(u32 characterId);
    bool isOldPartyMember();
    bool isCheckCreateParty();
    f32 getInvitedTimeOutFrame();
    void initPartyInfo();
    void setIsPartySync(nNetSv::PARTY_SYNC_FLAG id, u32 characterId, bool flag, bool isSend);
    s32 getPartySyncNum(nNetSv::PARTY_SYNC_FLAG id);
    bool isPartySync(nNetSv::PARTY_SYNC_FLAG id, s32 memberIndex);
    bool isPartySyncAll(nNetSv::PARTY_SYNC_FLAG id);
    bool isConnect(s32);
    bool isPawn(const cPartyMemberInfo* pInfo);
    bool isPawn(s32 memberIndex);
    u32 getPartyPlayerMemberNum(nParty::E_JOIN_STATE state);
    u32 getPartyPreparePlayerMemberNum();
    u32 getPartyOnPlayerMemberNum();
    u32 getPartyPawnMemberNum(nParty::E_JOIN_STATE state);
    u32 getPartyPreparePawnMemberNum();
    u32 getPartyOnPawnMemberNum();
    u8 getPartyMemberJoinState(s32);
    bool isPartyMemberJoinPrepare(s32);
    u8 getPartyMemberSessionStatus(s32 memberIndex);
    u8 getPartyMemberSessionStatusFromCharacterId(u32);
    void setPartyMemberSessionStatus(cPartyMemberInfo* pInfo, u8 status, bool isWithPawn);
    void setPartyMemberSessionStatusFromMemberIndex(s32, u8, bool);
    void setPartyMemberSessionStatusFromCharacterId(u32 characterId, u8 status, bool isWithPawn);
    bool isPartyMemberSessionNormal(s32 memberIndex);
    bool isPartyMemberSessionLost(s32 memberIndex);
    bool isPartyMemberSessionLostFromCharacterId(u32);
    void setLostAction(cContextInstHm* pInst);
    void setLostAction(cPartyMemberInfo* pInfo);
    u32 getInvitedStageNo();
    void setInvitedStageNo(u32 stageNo);
    u32 getInvitedPosNo();
    void setInvitedPosNo(u32 posNo);
    u32 getInvitedPosOffset();
    void setInvitedPosOffset(u32 offset);
    u64 getMyPartyContentNumber();
    void setMyPartyContentNumber(u64 number);
    void clearCharacterSearchFilter(CCharacterSearchParameter* pParam);
    void clearSearchFilter(SEARCH_TYPE searchType);
    void clearPartySearchFilter();
    void clearQuickSearchFilter();
    void clearCharacterSearchFilter();
    void clearPawnSearchFilter();
    void clearClanSearchFilter();
    void clearEntryBoardSearchFilter();
    CPartySearchParameter& getPartySearchFilterRef();
    CQuickMatchSearchParameter& getQuickSearchFilterRef();
    CCharacterSearchParam& getCharacterSearchFilterRef();
    CPawnSearchParameter& getPawnSearchFilterRef();
    CClanSearchParam& getClanSearchFilterRef();
    CEntryBoardItemSearchParameter& getEntryBoardSearchFilterRef();
    bool reqQuickPartyRegister(nNet::QUICK_MATCH_TYPE type, CQuickPartyMatching& matching);
    bool reqQuickPartyRegisterQuest(u32 scheduleId, CQuickPartyMatching& matching);
    bool reqQuickPartyCancel();
    bool reqQuickPartyEntry();
    bool reqQuickPartyRefuse();
    void setQuickQuestName(MT_CTSTR name);
    nNet::QUICK_MATCH_TYPE getLastQuickType();
    CQuickPartyMatching& getLastQuickSetting();
    MT_CTSTR getLastQuickQuestName();
    s32 getLastQuickMainPurposeMsgId();
    MT_CTSTR getLastQuickSubPurposeMsg();
    bool createMyPawn();
    bool createMyPawn(s32 slotNo, cCharacterData::stPawnData* pPawnData);
    bool deleteMyPawn();
    bool deleteMyPawn(s32 slotNo, bool isKeepEquip);
    bool getMyPawnList();
    bool getMyPawnData();
    bool getMyPawnData(s32 slotNo, bool isUseCache);
    bool getRegisterdPawnList();
    bool getRegisterdPawnList(u32 characterId);
    bool getOfficialPawnList();
    bool getLegendPawnList();
    bool getNoraPawnList();
    bool getFreeRentalPawnList();
    bool getRegisterdPawnData();
    bool getRegisterdPawnData(s32 pawnId, bool isUseCache);
    bool rentRegisterdPawn();
    bool rentRegisterdPawn(s32 slotNo, s32 pawnId, u64 updated, u32 rentalCost);
    bool getRentedPawnList();
    bool getRentedPawnData();
    bool getRentedPawnData(s32 slotNo, bool isUseCache);
    bool getPartyPawnData(u32 characterId, u32 pawnId);
    bool returnRentedPawn();
    bool returnRentedPawn(s32 slotNo, const nNet::stPawnFeedback& feedback);
    bool joinPartyMyPawn(s32 slotNo);
    bool joinPartyMyPawn();
    bool joinPartyRentedPawn(s32 slotNo);
    bool joinPartyRentedPawn();
    bool pawnLost(u32 pawnId);
    bool pawnLost();
    bool getLostPawnList();
    bool lostPawnRevive(u32 pawnId);
    bool lostPawnRevive();
    bool lostPawnPointRevive(u32 pawnId);
    bool lostPawnPointRevive();
    bool lostPawnGoldenRevive(u32 pawnId);
    bool lostPawnGoldenRevive();
    bool lostPawnWalletRevive(u32 pawnId, nCharacter::E_WALLET_POINT_TYPE type, unsigned int cost);
    bool rentalPawnLost(u32 pawnId);
    bool rentalPawnLost();
    bool getFavoritePawnList();
    bool setFavoritePawn(u32 pawnId);
    bool setFavoritePawn();
    bool deleteFavoritePawn(u32 pawnId);
    bool deleteFavoritePawn();
    bool updatePawnReactionList(u32 pawnId, const PawnReactionVec& list);
    bool updatePawnReactionList();
    bool updatePawnShareRange(u32 pawnId, u8 shareType);
    bool updatePawnShareRange();
    bool getPawnHistoryList(u32 pawnId);
    bool getPawnHistoryList();
    bool getPawnTotalScore(u32 pawnId);
    void copyEditInfo(cContextInstHm* pDst, const CEditInfo& src, bool isPlayer);
    void copyEditInfo(cEditParam* pDst, const CEditInfo& src, bool isPlayer);
    void copyEditInfo(cEditParam* pDst, const cCharacterData::stCharacterEdit& src, bool isPlayer);
    void setPawnListData(CPawnListData* pDst, const CPawnListData& src);
    void setMyPawnList(const PawnListVec& list);
    cPawnListVec& getMyPawnListRef();
    cPawnListParam* getPawnListParamMyPawn(u32 pawnId);
    cPawnListParam* getPawnListParamMyPawnFromSlotNo(u32);
    void setRegisterdPawnList(const RegisterdPawnListVec& list);
    cPawnListVec& getRegisterdPawnListRef();
    void clearRegisterdPawnList();
    void setRentalPawnList(const RentedPawnListVec& list);
    cPawnListVec& getRentalPawnListRef();
    cPawnListParam* getPawnListParamRentalPawn(u32 pawnId);
    cPawnListParam* getPawnListParamRentalPawnFromSlotNo(u32);
    void setLostPawnList(const LostPawnListVec& list);
    cPawnListVec& getLostPawnListRef();
    void setFavoritePawnList(const RegisterdPawnListVec& list);
    void setOfficialPawnList(const RegisterdPawnListVec& list);
    void setLegendPawnList(const RegisterdPawnListVec& list);
    void setNoraPawnList(const RegisterdPawnListVec& list);
    void setPawnHistoryList(const PawnHistoryVec& list);
    PawnHistoryVec& getPawnHistoryListRef();
    void clearPawnHistoryList();
    cCharacterData::stPawnData& getRecvPawnDataRef();
    nUserSession::CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES* getGetPawnTotalScorePacket();
    void clearGetPawnTotalScorePacket();
    nUserSession::CPacket_S2C_GET_FREE_RENTAL_PAWN_LIST_RES* getGetFreeRentalPawnListPacket();
    void clearGetFreeRentalPawnListPacket();
    u32 convertSlotNoToPawnId(PAWN_LIST_TYPE type, u32 slotNo);
    u32 getReqJoinPawnId();
    nUserSession::CPacket_S2C_GET_MYPAWN_DATA_RES* getMyPawnCacheData(u32 pawnId);
    bool setMyPawnCacheData(u32 pawnId, nUserSession::CPacket_S2C_GET_MYPAWN_DATA_RES* pData);
    void setPartnerPawnPersonality(u32 pawnId, u8 personality);
    bool deleteMyPawnCacheData(u32);
    nUserSession::CPacket_S2C_GET_REGISTERED_PAWN_DATA_RES* getRegisterdPawnCacheData(u32 pawnId);
    bool setRegisterdPawnCacheData(u32 pawnId, nUserSession::CPacket_S2C_GET_REGISTERED_PAWN_DATA_RES* pData);
    nUserSession::CPacket_S2C_GET_RENTED_PAWN_DATA_RES* getRentedPawnCacheData(u32 pawnId);
    bool setRentalPawnCacheData(u32 pawnId, nUserSession::CPacket_S2C_GET_RENTED_PAWN_DATA_RES* pData);
private:
    void copyOrbStatus(cCharacterData::stCardDogmaOrb& orb, const OrbPageStatusVec& vec);
    void copyJobOrbStatus(cCharacterData::stCardJobOrbTree& orb, const JobOrbTreeStatusVec& vec);
    void copyHistory(cCharacterData::stCardHistory& history, const HistoryElementVec& vec);
    void copyAchievement(cCharacterData::stCardAchievement& achieve, const AchieveCategoryStatusVec& vec);
    void copyRecvPawnData(cCharacterData::stPawnData* pDstPawnData, const CPawnInfo& srcPawnData, u32 pawnID);
    void copyJobData(nJobParam::cJobInfo& dstData, const CCharacterJobData& srcData);
    void copyRecvHumanBaseInfo(nJobParam::cHumanBaseInfo& dstInfo, const CStatusInfo& srcInfo);
    void updateCharListElement(CCharacterListElement& dst, const CCharacterListElement& src);
public:
    void copySendEditData(CEditInfo* pDstEditData, const cCharacterData::stCharacterEdit& srcEditData);
    void copyRecvEditData(cCharacterData::stCharacterEdit* pDstEditData, const CEditInfo& srcEditData);
    void copyRecvCharacterData(cCharacterData& dst, const CCharacterInfo& src);
    bool useBagItem();
    bool useBagItem(MT_CTSTR UID, u32 num);
    bool useJobItems();
    bool useJobItems(ItemUIDListVec& list);
    bool getStorageItemList(CommonU8Vec& storageList);
    bool consumeStorageItem();
    bool consumeStorageItem(StorageItemUIDListVec& list);
    void clearConsumeStorageItemList();
    bool exchangeSlotItem();
    bool exchangeSlotItem(u8 sourceStorage, MoveItemUIDFromToVec& list);
    bool moveItem();
    bool moveItem(u8 sourceStorage, MoveItemUIDFromToVec& list);
    bool moveItemTest();
    bool getCharacterEquipList();
    bool getPawnEquipList();
    bool getPawnEquipList(unsigned int pawnID);
    bool changeCharacterEquip(C2SChangeCharacterEquipInfoVec& changeCharacterEquipList);
    bool changeCharacterStorageEquip(C2SChangeCharacterEquipInfoVec& changeCharacterEquipList);
    bool changePawnEquip(unsigned int pawnID, C2SChangeCharacterEquipInfoVec& changeCharacterEquipList);
    bool changePawnStorageEquip(unsigned int pawnID, C2SChangeCharacterEquipInfoVec& changeCharacterEquipList);
    bool changeCharacterEquipJobItem(ChangeEquipJobItemVec& equipJobItemList);
    bool changePawnEquipJobItem(unsigned int pawnID, ChangeEquipJobItemVec& equipJobItemList);
    bool updateHideCharacterHeadArmor(bool isHide);
    bool updateHideCharacterLantern(bool isHide);
    bool updateHidePawnHeadArmor(bool isHide);
    bool updateHidePawnLantern(bool isHide);
    bool getEquipPresetList();
    bool updateEquipPreset(unsigned int presetNo, unsigned int pawnID, unsigned char type, MT_CTSTR presetName);
    bool updateEquipPresetName(unsigned int presetNo, MT_CTSTR presetName);
    void setEquipElementParamList(const EquipElementParamVec& srcList, EquipElementParamVec& dstList);
    void setItemList(const ItemListVec& srcList, ItemListVec& dstList);
    void setBagItemList(const ItemListVec& list);
    ItemListVec& getBagItemListRef();
    void setEquipList(const S2CCharacterEquipInfoVec& srcList, S2CCharacterEquipInfoVec& dstList);
    S2CCharacterEquipInfoVec& getEquipListRef();
    S2CCharacterEquipInfoVec& getChangeEquipListRef();
    S2CCharacterEquipInfoVec& getChangePawnEquipListRef();
    u32 getRecvChangePawnEquipPawnId();
    void setEquipJobItemList(const EquipJobItemVec& srcList, EquipJobItemVec& dstList);
    EquipJobItemVec& getEquipJobItemListRef();
    EquipJobItemVec& getChangeEquipJobItemListRef();
    EquipJobItemVec& getChangePawnEquipJobItemListRef();
    u32 getRecvChangePawnEquipJobItemPawnId();
private:
    bool getStorageItemList();
public:
    const cEditParam& getReqEditParam() const;
    u32 getCharEditPawnSlotNo() const;
    const cEditParam& getReqPawnEditParam() const;
    bool getLightQuestList();
    bool getLightQuestList(u32 lightQuestBaseId);
    bool getClanQuestList();
    bool getClanQuestList(u32 clanQuestBaseId);
    bool getSetQuestList();
    bool getSetQuestList(u32 distributeId);
    bool getMainQuestList();
    bool getTutorialQuestList();
    bool getTutorialQuestList(u32 stageNo);
    bool getTimeLimitedQuestList();
    bool getWorldManageQuestList();
    bool getLotQuestList(u8 lotType);
    bool getMainQuestCompleteInfo();
    bool getRecommendedQuestInfoList();
    bool questOrder();
    bool questOrder(u32 questScheduleId);
    bool questProgress();
    bool questProgress(u32 characterId, u32 questScheduleId, u16 processNo, u32 keyId);
    bool questCancel();
    bool questCancel(u32 questScheduleId);
    bool endDistributionQuestCancel();
    bool questCompleteFlagClear(u32 questScheduleId);
    bool getQuestDetailList(u32 questScheduleId);
    bool getQuestCompleteList(u32 questType);
    bool getQuestLayoutFlag(u32 flagNo);
    bool setQuestFlag(u32 flagNo);
    bool getSetQuestOpenDateList();
    bool reqBoardQuestAllComplete(u32 baseId);
    bool debugQuestForceProgress(u32 questScheduleId, u16 processNo);
    bool debugQuestForceProgress();
    bool debugMainQuestJump(u32 questId);
    bool debugMainQuestJump();
    bool debugQuestReset(u32 questId);
    bool debugQuestReset();
    bool debugQuestResetAll(u8 questType);
    bool debugQuestResetAll();
    bool debugGetQuestLayoutFlag(u32 questScheduleId);
    bool cycleContentsPointUpload(u32 cycleContentsScheduleId, s32 point);
    bool cycleContentsPointUpload();
    bool debugGetQuestFlag(u32 questScheduleId);
    bool getBoughtBoxList();
    bool getRewardBoxList();
    bool getRewardBoxListNum();
    bool getRewardBoxItem(u32 listNo, GetRewardBoxItemVec& itemList);
    bool getCycleContentsRewardList();
    bool getCycleContentsRewardListNum();
    bool getCycleContentsRewardItem(u32 listNo, GetRewardBoxItemVec& itemList);
    void clearRewardBoxListPacket();
    void clearCycleContentsRewardListPacket();
    void clearCycleContentsRewardItemPacket();
    bool deliverItem(u32 scheduleId, u16 processNo, ItemUIDListVec& itemUIDList);
    bool decideDeliveryItem(u32 scheduleId, u16 processNo);
    bool getPartyQuestProgressInfo();
    bool leaderQuestProgressRequest(u32 scheduleId, u16 processNo, u16 blockNo);
    bool checkQuestDistribution(u32 scheduleId);
    bool getSetQuestInfoList();
    bool getSetQuestInfoList(u32 distributeId);
    bool getCycleContentsList();
    bool getAreaInfoList();
    bool getAreaBonusList();
    bool getQuestPartyBonusList();
    bool sendLeaderQuestOrderConditionInfo(const OrderConditionInfoVec& orderConditionList);
    bool sendLeaderWaitOrderQuestList(const CommonU32Vec& scheduleIdList);
    bool setReturnSessionForPRT();
    bool setReturnSessionForPRT(bool isReturnSession);
    bool getGachaList(bool box);
    void clearGachaListPacket();
    void clearBoxGachaListPacket();
    bool getGachaBuy(bool box);
    u32 checkGachaBuy();
    void setGachaBuy(const u32 gachaId, const u32 settlementId, const u32 price, const u32 drawNum, s32 drawId);
    void clearGachaBuyPacket();
    void clearBoxGachaBuyPacket();
    bool getBoxGachaItem();
    bool getBoxGachaReset(u32 id);
    void clearBoxGachaResetPacket();
    void clearBoxGachaDrawInfoPacket();
    LightQuestListVec& getLightQuestListRef();
    SetQuestListVec& getSetQuestListRef();
    MainQuestListVec& getMainQuestListRef();
    TutorialQuestListVec& getTutorialQuestListRef();
    TimeLimitedQuestListVec& getTimeLimitedQuestListRef();
    WorldManageQuestListVec& getWorldManageQuestListRef();
    LotQuestListVec& getLotQuestListRef();
    nUserSession::CPacket_S2C_GET_LIGHT_QUEST_LIST_RES* getLightQuestListPacket();
    nUserSession::CPacket_S2C_LIGHT_QUEST_GP_COMPLETE_RES* getLightQuestGpCompletePacket();
    nUserSession::CPacket_S2C_GET_SET_QUEST_LIST_RES* getSetQuestListPacket();
    nUserSession::CPacket_S2C_GET_MAIN_QUEST_LIST_RES* getMainQuestListPacket();
    nUserSession::CPacket_S2C_GET_TUTORIAL_QUEST_LIST_RES* getTutorialQuestListPacket();
    nUserSession::CPacket_S2C_GET_TIME_LIMITED_QUEST_LIST_RES* getTimeLimitedQuestListPacket();
    nUserSession::CPacket_S2C_GET_WORLD_MANAGE_QUEST_LIST_RES* getWorldManageQuestListPacket();
    nUserSession::CPacket_S2C_GET_LOT_QUEST_LIST_RES* getLotQuestListPacket();
    nUserSession::CPacket_S2C_GET_SET_QUEST_INFO_LIST_RES* getSetQuestInfoListPacket();
    nUserSession::CPacket_S2C_GET_RECOMMENDED_QUEST_INFO_LIST_RES* getRecommendedQuestInfoListPacket();
    nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_NEWS_LIST_RES* getCycleContentsNewsListPacket();
    nUserSession::CPacket_S2C_GET_END_CONTENTS_GROUP_RES* getEndContentsGroupPacket();
    nUserSession::CPacket_S2C_GET_QUEST_SCHEDULE_INFO_RES* getQuestScheduleInfoPacket();
    nUserSession::CPacket_S2C_GET_AREA_INFO_LIST_RES* getAreaInfoListPacket();
    nUserSession::CPacket_S2C_GET_AREA_BONUS_LIST_RES* getAreaBonusListPacket();
    nUserSession::CPacket_S2C_GET_QUEST_PARTY_BONUS_LIST_RES* getQuestPartyBonusListPacket();
    nUserSession::CPacket_S2C_PAWN_DUNGEON_REWARD_LIST_RES* pawnDungeonRewardListPacket();
    nUserSession::CPacket_S2C_GACHA_LIST_RES* getGachaListPacket();
    nUserSession::CPacket_S2C_GACHA_BUY_RES* getGachaBuyPacket();
    nUserSession::CPacket_S2C_BOX_GACHA_LIST_RES* getBoxGachaListPacket();
    nUserSession::CPacket_S2C_BOX_GACHA_BUY_RES* getBoxGachaBuyPacket();
    nUserSession::CPacket_S2C_BOX_GACHA_RESET_RES* getBoxGachaResetPacket();
    nUserSession::CPacket_S2C_BOX_GACHA_DRAW_INFO_RES* getBoxGachaDrawInfoPacket();
    void clerLightQuestGpComplete();
    void setQuestProcessStateList(QuestProcessStateVec* ptr);
    QuestProcessStateVec* getQuestProcessStateList();
    void setCompleteQuestList(const u32);
    cCompleteQuestList& getCompleteQuestListRef();
    u32 getRecvProgressQuestScheduleId();
    u32 getRecvCancelQuestScheduleId();
    CPartyQuestProgressInfo& getPartyQuestProgressInfoRef();
    nUserSession::CPacket_S2C_GET_QUEST_COMPLETE_LIST_RES* getGetQuestCompleteListPacket();
    nUserSession::CPacket_S2C_GET_SET_QUEST_OPEN_DATE_LIST_RES* getGetSetQuestOpenDateListPacket();
    RewardBoxRecordVec& getRewardBoxRecordListRef();
    u32 getRecvGetRewardBoxListNum();
    nUserSession::CPacket_S2C_GET_REWARD_BOX_ITEM_RES* getRewardBoxItemPacket();
    nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_LIST_RES* getCycleContentsRewardListPacket();
    nUserSession::CPacket_S2C_GET_NOT_RECV_CYCLE_CONTENTS_REWARD_ITEM_RES* getCycleContentsRewardItemPacket();
    nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_REWARD_RES* getGetCycleContentsRewardPacket();
    nUserSession::CPacket_S2C_END_DISTRIBUTION_QUEST_CANCEL_RES* getEndDistributionQuestCancelPacket();
    nUserSession::CPacket_S2C_GET_PRIORITY_QUEST_RES* getGetPriorityQuestPacket();
    nUserSession::CPacket_S2C_SET_PRIORITY_QUEST_RES* getSetPriorityQuestPacket();
    nUserSession::CPacket_S2C_CANCEL_PRIORITY_QUEST_RES* getCancelPriorityQuestPacket();
    u32 getRequestQuestScheduleId() const;
    void setPlayStartQuestScheduleId(u32 questScheduleId);
    u32 getSetQuestDistributeId() const;
    bool getReqReturnSession() const;
    bool getCycleContentsStateList();
    bool getCycleContentsSituationInfoList();
    bool getCycleContentsSituationInfoList(u32 scheduleId);
    bool playStartCycleContents();
    bool playStartCycleContents(u32 scheduleId);
    bool getCycleContentsBorderRewardList();
    bool getCycleContentsBorderRewardList(u32 scheduleId);
    bool getCycleContentsRankingRewardList();
    bool getCycleContentsRankingRewardList(u32 scheduleId);
    bool getCycleContentsReward();
    bool getCycleContentsReward(u32 scheduleId);
    bool startQuestTime();
    bool contentsPlayInterrupt();
    bool contentsPlayInterruptAnswer();
    bool contentsPlayInterruptAnswer(b8 isInterrupt);
    bool cycleContentsPlayEnd();
    bool getCycleContentsPointList();
    bool getCycleContentsPointList(u32 scheduleId);
    bool getCycleContentsNowPointList();
    bool getCycleContentsNowPointList(u32 scheduleId);
    void setCycleContentsStateList(const CycleContentsStateListVec& list);
    CycleContentsStateListVec& getCycleContentsStateListRef();
    void setQuestContentsSituationInfo(const QuestContentsSituationInfoVec& list);
    QuestContentsSituationInfoVec& getQuestCOntentsSituationInfoRef();
    nUserSession::CPacket_S2C_RAID_BOSS_POINT_NOTICE* getGetRaidBossPointPacket();
    void setPlayStartCycleContentsScheduleId(u32 scheduleId);
    BorderRewardRecordVec& getBorderRewardListRef();
    u32 getBorderRewardResultScore();
    RankingRewardRecordVec& getRankingRewardListRef();
    u32 getRankingRewardResultRank();
    s32 getQuestPlayTimeSec();
    void setQuestPlayTimeSec(s32);
    CQuestPointDetail& getCycleContentsPointListRef();
    CQuestPointDetail& getCycleContentsNowPointListRef();
    b8 getContentsInterruptAnswer();
    bool getEndContentsGroup();
    bool getEndContentsGroup(u32 endContentsGroupId);
    bool getQuestIdFromscheduleId(u32 scheduleId);
    u32 getGachaId() const;
    u32 getGachaSettlementId() const;
    u32 getGachaPrice() const;
    u32 getGachaDrawNum() const;
    void setGachaPrePrice(u64 gp, u64 ticket);
    void chatDispGachaResult();
    bool getStageList();
    bool areaChange();
    bool areaChange(u32 stageNo);
    void setAreaChangeJumpType(u32 type);
    bool getEnemySetList();
    bool getEnemySetList(CDataStageLayoutID SLID, u32 subId);
    bool enemyKilled();
    bool enemyKilled(CDataStageLayoutID SLID, u32 setId, u32 innerId, f64 posX, f32 posY, f64 posZ, bool NoReword, u32 regionFlag);
    bool enemyGroupEnter(CDataStageLayoutID SLID);
    bool enemyGroupLeave(CDataStageLayoutID SLID);
    bool enemyBreakRegion(CDataStageLayoutID SLID, u32 setId, u32 regionNo);
    bool getItemSetList();
    bool getItemSetList(CDataStageLayoutID SLID);
    bool getGatheringItemList();
    bool getGatheringItemList(CDataStageLayoutID SLID, u32 posId, MT_CTSTR UID);
    bool getGatheringItem();
    bool getGatheringItem(CDataStageLayoutID SLID, u32 posId, GatheringItemGetRequestVec& list);
    bool debugEnemySetPresetFix(DebugEnemySetPresetReqVec& debugEnemySetPresetReqList);
    bool debugQuestLayoutFlagSet(u32 flagNo, bool value);
    bool debugProdDropCancelSet(bool value);
    bool sendRaidBossInfo(u32 RaidBossId, cContextInterface& context);
    bool getPawnVoiceListReq();
    const cPawnVoiceList& getPawnVoiceList() const;
    bool getEditSalonInfoReq();
    const cEditSalonInfo& getEditSalonParam() const;
    bool plTouchOmNtc(u32 stageNo, u32 groupNo, s32 setNo);
    void setStageList(const StageInfoVec& list);
    StageInfoVec& getStageListRef();
    u32 getRecvAreaChangeStageNo();
    u32 convertIdToStageNo(u32 id);
    u32 convertStageNoToId(u32 stageNo);
    void setGatheringItemList(CDataStageLayoutID SLID, const u32 posId, const GatheringItemElementVec& list);
    GatheringItemElementVec& getGatheringItemListRef();
    u32 getGatheringItemListStageId();
    u32 getGatheringItemListGroupId();
    u32 getGatheringItemListLayerNo();
    u32 getGatheringItemListPosId();
    void setGatheringItem(CDataStageLayoutID SLID, const u32 posId, const GatheringItemGetRequestVec& list);
    GatheringItemGetRequestVec& getGatheringItemRef();
    u32 getGatheringItemStageId();
    u32 getGatheringItemGroupId();
    u32 getGatheringItemLayerNo();
    u32 getGatheringItemPosId();
    bool setOmInstantKeyValue(COmData& value);
    bool getOmInstantKeyValue(u32 key);
    bool getOmInstantKeyValueAll();
    bool exchangeOmInstantKeyValue(COmData& value);
    bool setInstantKeyValueUL();
    bool setInstantKeyValueUL(u32 key, u32 value);
    bool getInstantKeyValueUL();
    bool getInstantKeyValueUL(u32 key);
    bool setInstantKeyValueStr();
    bool setInstantKeyValueStr(MT_CTSTR key, MT_CTSTR str);
    bool getInstantKeyValueStr();
    bool getInstantKeyValueStr(MT_CTSTR key);
    u32 getInstantValueUL();
    MT_CTSTR getInstantString();
    bool getDropItemSetList(CDataStageLayoutID SLID);
    bool getDropItemList(CDataStageLayoutID SLID, u32 setId);
    bool getDropItem(CDataStageLayoutID SLID, u32 listId, GatheringItemGetRequestVec& requestList);
    nUserSession::CPacket_S2C_GET_DROP_ITEM_LIST_RES* getDropItemListPacket();
    bool getFurnitureList();
    bool setFurnitureLayout(FurnitureLayoutDataVec& vec);
    bool getTrainingRoomEnemyList();
    bool setTrainingRoomEnemy(u32 id, u32 level);
    nUserSession::CPacket_S2C_TRANING_ROOM_GET_ENEMY_LIST_RES* getTrainingRoomGetEnemyList();
    void clearTrainingRoomGetEnemyList();
    bool getCogId();
    bool getGP();
    bool getCAP();
    bool getCAPToGPChangeList();
    bool changeCAPToGP();
    bool changeCAPToGP(u32 listId);
    bool getGPCourseLineup();
    bool getGPItemLineup();
    bool getGPLPawnLineup();
    bool getGPAvailableList();
    bool getGPUseAvailableItem(const u32 in_AvailableId);
    bool getGPValidList();
    bool getGPBuyHistory();
    bool getCAPChargeURL();
    bool getGPCourseInfo();
    bool getGPDetailHistory(bool IsAllHistory);
    bool getGPPeriod();
    bool getGPShopMenuList();
    bool getGPShopLineup(u32 DisplayID);
    bool reqGPShopBuyItem(u32 DisplayLineupID);
    bool getCOGLoginSkipFlag();
    bool getCOGLoginSkipFlagOff();
    bool getGPShopCanBuyPawn(u32 LineupId);
    bool getGPShopCanBuyPawnVoice(u32 LineupId);
    u32 getRecvGetGP();
    u32 getRecvGetCAP();
    bool getRecvCOGLoginSkipFlag();
    bool getRecvGPShopCanBuyPawn();
    bool getRecvGPShopCanBuyPawnVoice();
    nUserSession::CPacket_S2C_GET_CAP_TO_GP_CHANGE_LIST_RES* getGetCAPToGPChangeListPacket();
    nUserSession::CPacket_S2C_CHANGE_CAP_TO_GP_RES* getChangeCAPToGPPacket();
    nUserSession::CPacket_S2C_GP_SHOP_GET_COURSE_LINEUP_RES* getGPShopCourseLineupPacket();
    nUserSession::CPacket_S2C_GP_COURSE_GET_AVAILABLE_LIST_RES* getGPShopCourseAvailableListPacket();
    nUserSession::CPacket_S2C_GP_COURSE_GET_VALID_LIST_RES* getGPShopCourseValidListPacket();
    nUserSession::CPacket_S2C_GP_SHOP_GET_BUY_HISTORY_RES* getGPShopBuyHistoryPacket();
    nUserSession::CPacket_S2C_GET_GP_DETAIL_RES* getGPDetailHistoryPacket();
    nUserSession::CPacket_S2C_GET_GP_PERIOD_RES* getGPPeriodPacket();
    void releaseGPPeriodPacket();
    nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_GET_TYPE_RES* getGPShopMenuListPacket();
    nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_GET_LINEUP_RES* getGPShopLineupPacket();
    nUserSession::CPacket_S2C_GP_SHOP_DISPLAY_BUY_RES* getGPShopBuyRecievePacket();
    nUserSession::CPacket_S2C_DEBUG_GET_QUEST_LAYOUT_FLAG_RES* getDebugGetQuestLayoutFlagPacket();
    nUserSession::CPacket_S2C_DEBUG_GET_QUEST_FLAG_RES* getDebugGetQuestFlagPacket();
    bool getCraftProgressList();
    bool startCraft(u32 recipeId, CraftMaterialVec& craftMaterialList, MT_CTSTR toppingUId, u32 craftMainPawnId, CraftSupportPawnIDVec& craftSupportPawnIdList, u8 createCount);
    bool getCraftProductInfo(u32 craftMainPawnId, u8 debugFlag);
    bool getCraftProduct(u32 craftMainPawnId, u32 storageType, u8 debugFlag);
    bool cancelCraft(u32 craftMainPawnId);
    bool startEquipGradeUp(MT_CTSTR equipItemUId, CraftMaterialVec& craftMaterialList, u32 craftMainPawnId, CraftSupportPawnIDVec& craftSupportPawnIdList);
    bool startAttachElement(MT_CTSTR equipItemUId, CraftElementVec& craftElementList, u32 craftMainPawnId, CraftSupportPawnIDVec& craftSupportPawnIdList);
    bool startDetachElement(MT_CTSTR equipItemUId, CraftElementVec& craftElementList, u32 craftMainPawnId, CraftSupportPawnIDVec& craftSupportPawnIdList);
    bool startEquipColorChange(MT_CTSTR equipItemUId, u8 color, CraftColorantVec& craftColorantList, u32 craftMainPawnId, CraftSupportPawnIDVec& craftSupportPawnIdList);
    bool craftSkillUp(u32 pawnId, u32 skillType, u32 skillLevel);
    bool getCraftSetting();
    bool craftTimeSaving(u32 pawnId, u32 costId, u32 num, bool isInit);
    bool getCraftIrReductionDataList();
    bool getCraftRecipe(nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category, u32 offset, s32 num);
    bool getCraftRecipe(nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category, CommonU32Vec& list);
    bool getCraftGradeupRecipe(nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category, u32 offset, s32 num, CommonU32Vec& list);
    bool getLockedEquipElementList();
    bool reqCraftSkillAnalyze(nCraft::E_CRAFT_TYPE craftType, u32 recipeId, u32 ItemId, u32 pawnId, const CommonU32Vec& assistPawnIds, u32 createCount);
    nUserSession::CPacket_S2C_GET_CRAFT_PROGRESS_LIST_RES* getGetCraftProgressListPacket();
    nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES* getGetCraftProductInfoPacket();
    nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_RES* getGetCraftProductPacket();
    nUserSession::CPacket_S2C_GET_CRAFT_SETTING_RES* getCraftSettingPacket();
    nUserSession::CPacket_S2C_CRAFT_SKILL_ANALYZE_RES* getCraftSkillAnalizePacket();
    nUserSession::CPacket_S2C_GET_CRAFT_LOCKED_ELEMENT_LIST_RES* getCraftLockedElementListPacket();
    void clearCraftProgressListPacket();
    void clearCraftProductInfoPacket();
    void clearCraftProductPacket();
    void clearCraftSettingPacket();
    void clearCraftSkillAnalizePacket();
    void clearCraftLockedElementListPacket();
    bool releaseWarpPoint(u32 pointId);
    bool getWarpPointList(u32 pointId);
    bool getReleaseWarpPointList();
    bool warp(u32 pointId, u32 destPointId, u32 price);
    bool getFavoriteWarpPointList(u32 areaId);
    bool favoriteWarp(u32 slotNo, u32 price, u32 areaId);
    bool registerFavoriteWarp(u32 slotNo, u32 pointId);
    bool partyWarp();
    bool getAreaWarpPointList();
    bool areaWarp(u32 pointId, u32 price);
    bool warpEndNotice();
    nUserSession::CPacket_S2C_GET_WARP_POINT_LIST_RES* getGetWarpPointListPacket();
    nUserSession::CPacket_S2C_GET_FAVORITE_WARP_POINT_LIST_RES* getGetFavoriteWarpPointListPacket();
    nUserSession::CPacket_S2C_GET_AREA_WARP_POINT_LIST_RES* getGetAreaWarpPointListPacket();
    bool getAcquirableNormalSkillList(u8 job);
    bool getAcquirableSkillList(u8 job);
    bool getAcquirableAbilityList(u8 job);
    bool learnNormalSkill(u8 job, u8 type, u32 skillID);
    bool learnSkill(u8 job, u8 type, u32 skillID, u32 skillLv);
    bool learnAbility(u8 job, u8 type, u32 skillID, u32 skillLv);
    bool learnPawnNormalSkill(u32 pawnId, u8 job, u32 skillID);
    bool learnPawnSkill(u32 pawnId, u8 job, u32 skillID, u32 skillLv);
    bool learnPawnAbility(u32 pawnId, u32 abilityId, u32 abilityLv);
    bool getLearnedNormalSkillList();
    bool getLearnedSkillList();
    bool getLearnedAbilityList();
    bool getPawnLearnedNormalSkillList(u32 pawnId);
    bool getPawnLearnedSkillList(u32 pawnId);
    bool getPawnLearnedAbilityList(u32 pawnId);
    bool setSkill(u8 job, u8 slotNo, u8 type, u32 skillID, u32 skillLv);
    bool setAbility(u8 job, u8 slotNo, u8 type, u32 skillID, u32 skillLv);
    bool setPawnSkill(u32 pawnId, u8 job, u8 slotNo, u32 skillID, u32 skillLv);
    bool setPawnAbility(u32 pawnId, u8 slotNo, u32 abilityID, u32 abilityLv);
    bool setOffSkill(u8 job, u8 slotNo);
    bool setOffAbility(u8 slotNo);
    bool setOffPawnSkill(u32 pawnId, u8 job, u8 slotNo);
    bool setOffPawnAbility(u32 pawnId, u8 slotNo);
    bool getSetSkillList(u8 job);
    bool getSetAbilityList();
    bool getPawnSetSkillList(u32 pawnId, u8 job);
    bool getPawnSetAbilityList(u32 pawnId);
    bool getReleaseSkillList();
    bool getReleaseAbilityList();
    bool registerPresetAbility(u8 presetNo);
    bool registerPawnPresetAbility(u32 pawnId, u8 presetNo);
    bool setPresetAbilityName(u8 presetNo, MT_CTSTR presetName);
    bool getPresetAbilityList();
    bool setPresetAbilityList(u8 presetNo);
    bool setPawnPresetAbilityList(u32 pawnId, u8 presetNo);
    bool getCurrentSetSkillList();
    bool getCurrentSetAbilityList();
    bool getAbilitySetCost();
    bool getPawnAbilitySetCost(u32 pawnId);
    nUserSession::CPacket_S2C_GET_ACQUIRABLE_NORMAL_SKILL_LIST_RES* getGetAcquirableNormalSkillListPacket();
    nUserSession::CPacket_S2C_GET_ACQUIRABLE_SKILL_LIST_RES* getGetAcquirableSkillListPacket();
    nUserSession::CPacket_S2C_GET_ACQUIRABLE_ABILITY_LIST_RES* getGetAcquirableAbilityList();
    nUserSession::CPacket_S2C_GET_LEARNED_NORMAL_SKILL_LIST_RES* getGetLearnedNormalSkillListPacket();
    nUserSession::CPacket_S2C_GET_LEARNED_SKILL_LIST_RES* getGetLearnedSkillListPacket();
    nUserSession::CPacket_S2C_GET_LEARNED_ABILITY_LIST_RES* getGetLearnedAbilityList();
    nUserSession::CPacket_S2C_GET_PAWN_LEARNED_NORMAL_SKILL_LIST_RES* getGetPawnLearnedNormalSkillListPacket();
    nUserSession::CPacket_S2C_GET_PAWN_LEARNED_SKILL_LIST_RES* getGetPawnLearnedSkillListPacket();
    nUserSession::CPacket_S2C_GET_PAWN_LEARNED_ABILITY_LIST_RES* getGetPawnLearnedAbilityList();
    nUserSession::CPacket_S2C_GET_SET_SKILL_LIST_RES* getGetSetSkillListPacket();
    nUserSession::CPacket_S2C_GET_SET_ABILITY_LIST_RES* getGetSetAbilityList();
    nUserSession::CPacket_S2C_GET_PAWN_SET_SKILL_LIST_RES* getGetPawnSetSkillListPacket();
    nUserSession::CPacket_S2C_GET_PAWN_SET_ABILITY_LIST_RES* getGetPawnSetAbilityList();
    nUserSession::CPacket_S2C_GET_RELEASE_SKILL_LIST_RES* getGetReleaseSkillListPacket();
    nUserSession::CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES* getGetReleaseAbilityList();
    nUserSession::CPacket_S2C_GET_PRESET_ABILITY_LIST_RES* getPresetAbilityListPacket();
    nUserSession::CPacket_S2C_GET_ABILITY_COST_RES* getAbilityCostPacket();
    nUserSession::CPacket_S2C_GET_PAWN_ABILITY_COST_RES* getPawnAbilityCostPacket();
    bool getShopGoodsList(u32 shopId);
    bool buyShopGoods(u32 goodsIndex, u32 dealNum, u8 storageType, u32 price);
    bool sellItem(StorageItemUIDListVec& list);
    nUserSession::CPacket_S2C_GET_SHOP_GOODS_LIST_RES* getGetShopGoodsListPacket();
    bool getStayPrice(u32 inn_id);
    bool stayInn(u32 inn_id, u32 maxHp, const PawnHpVec& pawnMaxHpList);
    bool getPenaltyHealStayPrice();
    bool stayPenaltyHealInn(u32 maxHp, const PawnHpVec& pawnMaxHpList);
    bool completeHpRecovery();
    bool completeCharacterHpRecovery();
    bool completePawnHpRecovery(u32 pawnId);
    nUserSession::CPacket_S2C_GET_STAY_PRICE_RES* getGetStayPricePacket();
    nUserSession::CPacket_S2C_GET_PENALTY_HEAL_STAY_PRICE_RES* getGetPenaltyHealStayPricePacket();
    bool getAreaMasterInfo(u32 areaID);
    bool getAreaMasterInfo();
    bool areaRankUp(u32 areaID);
    bool areaRankUp();
    bool addAreaPointDebug(u32 areaID, u32 point);
    bool addAreaPointDebug();
    bool getAreaReleaseList();
    bool getLeaderAreaReleaseList();
    bool getAreaSupplyInfoList();
    bool getAreaSupplyInfoList(u32 areaID);
    bool receiveAreaSupply();
    bool receiveAreaSupply(u32 areaID, nItem::E_STORAGE_TYPE storageType, bool isCancel);
    bool receiveAreaSupply(u32 areaID, u8 storageType, SelectItemInfoVec& vec);
    bool getAreaQuestInfoList(u32 areaID);
    bool buyAreaQuestInfo(u32 areaID, u32 questScheduleID);
    bool getAreaPointList();
    bool getSpotInfoList(u32 areaID);
    nUserSession::CPacket_S2C_GET_AREA_MASTER_INFO_RES* getAreaMasterInfoPacket();
    nUserSession::CPacket_S2C_AREA_RANK_UP_RES* getAreaRankUpResPacket();
    nUserSession::CPacket_S2C_GET_LEADER_AREA_RELEASE_LIST_RES* getLeaderAreaReleaseListPacket();
    nUserSession::CPacket_S2C_GET_AREA_SUPPLY_INFO_RES* getAreaSupplyInfoListPacket();
    nUserSession::CPacket_S2C_GET_AREA_QUEST_HINT_LIST_RES* getAreaQuestInfoListPacket();
    nUserSession::CPacket_S2C_GET_SPOT_INFO_LIST_RES* getSpotInfoListPacket();
    bool getJobMasterOrderProgress(u8 JobID);
    bool getJobMasterOrderProgress();
    bool getReportJobOrderProgress(u8 JobID);
    bool getReportJobOrderProgress();
    bool getActivateJobOrder(u8 in_JobID8, u8 in_RewardType8, u32 in_RewardNo32, u8 in_RewardLv8);
    bool getActivateJobOrder();
    bool getDebugAddJobOrderProgress(u8 in_JobID8, u8 in_Type8, u32 in_ID32, u32 in_Rank32, u32 in_Num32);
    bool getDebugAddJobOrderProgress();
    nUserSession::CPacket_S2C_REPORT_JOB_ORDER_PROGRESS_RES* getReportJobOrderProgressPacket();
    void clearReportJobOrderProgressPacket();
    bool getOrbElementList(u8 unitType, u8 pageNo);
    bool getOrbElementList();
    bool devoteOrb(u32 elementID);
    bool devoteOrb();
    bool getReleaseOrbElement();
    bool devotePawnOrb(u32 pawnId, u32 elementID);
    bool devotePawnOrb();
    bool getReleasePawnOrbElement(u32 pawnId);
    bool getOrbGainExtendParam();
    nUserSession::CPacket_S2C_GET_RELEASE_ORB_ELEMENT_LIST_RES* getGetReleaseOrbElementListPacket();
    nUserSession::CPacket_S2C_GET_PAWN_RELEASE_ORB_ELEMENT_LIST_RES* getGetReleasePawnOrbElementListPacket();
    COrbGainExtendParam& getMyOrbGainExtendParam();
    COrbGainExtendParam& getPawnOrbGainExtendParam();
    bool getJobOrbTreeList();
    bool getJobOrbTreeElementList(u8 job_id);
    bool releaseJobOrbTreeElement(u32 element_id);
    nUserSession::CPacket_S2C_GET_ALL_JOB_ORB_ELEMENT_LIST_RES* getGetAllJobOrbElementListPacket();
    void clearGetAllJobOrbElementListPacket();
    bool createClan(CClanParam& clanParam);
    bool updateClan(CClanParam& clanParam);
    bool getClanList();
    bool reqJoinClan(u32 clanId);
    bool getClanApplyList();
    bool cancelJoinClan();
    bool getClanJoinReqList();
    bool allowClan(u32 reqId);
    bool denyClan(u32 reqId);
    bool getMyClan();
    bool getClanBaseInfo();
    bool getClanMemberList(u32 clanId);
    bool getMyClanMemberList();
    bool getOtherClanMemberList(u32 clanId);
    bool quitClan();
    bool expelClanMember(u32 memberId);
    bool changeClanMaster(u32 memberId);
    bool setClanMemberRank(u32 memberId, s32 rank, u32 permission);
    bool getClanInfo(u32 clanId);
    bool getClanMemberNum(u32 clanId);
    bool reqClanScoutEntry(CClanScoutEntryParam& param);
    bool reqClanScoutEntryCancel();
    bool searchClanScoutEntry();
    bool getMyClanScoutEntry();
    bool inviteClan(u32 entryId);
    bool getClanInvitedList();
    bool allowInvitedClan(u32 inviteId);
    bool denyInvitedClan(u32 inviteId);
    bool getClanInviteList();
    bool cancelInviteClan(u32 inviteId);
    bool inviteClanDirect(u32 characterId);
    bool allowInviteClanDirect(u32 clanId);
    bool getClanHistory();
    nUserSession::CPacket_S2C_CLAN_GET_MEMBER_LIST_RES* getClanMemberListPacket();
    nUserSession::CPacket_S2C_CLAN_SEARCH_RES* getClanSearchListPacket();
    nUserSession::CPacket_S2C_CLAN_GET_JOIN_REQUESTED_LIST_RES* getClanJoinRequestedListPacket();
    nUserSession::CPacket_S2C_CLAN_GET_MY_JOIN_REQUEST_LIST_RES* getClanApplyListPacket();
    nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_SEARCH_RES* getClanScoutEntryListPacket();
    nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITE_LIST_RES* getClanInviteListPacket();
    nUserSession::CPacket_S2C_CLAN_SCOUT_ENTRY_GET_INVITED_LIST_RES* getClanInvitedListPacket();
    nUserSession::CPacket_S2C_CLAN_BASE_GET_INFO_RES* getClanBaseGetInfoResPacket();
    nUserSession::CPacket_S2C_CLAN_CONCIERGE_GET_LIST_RES* getClanConciergeGetListPacket();
    nUserSession::CPacket_S2C_CLAN_SHOP_GET_FUNCTION_ITEM_LIST_RES* getClanShopGetFunctionItemListPacket();
    nUserSession::CPacket_S2C_CLAN_SHOP_GET_BUFF_ITEM_LIST_RES* getClanShopGetBuffItemListPacket();
    nUserSession::CPacket_S2C_CLAN_GET_HISTORY_RES* getClanGetHistoryPacket();
    void clearClanMemberListPacket();
    void clearClanSearchListPacket();
    void clearClanJoinRequestedListPacket();
    void clearClanApplyListPacket();
    void clearClanScoutEntryListPacket();
    void clearClanInviteListPacket();
    void clearClanInvitedListPacket();
    void clearClanBaseGetInfoResPacket();
    void clearClanConciergeGetListPacket();
    void clearClanShopGetFunctionItemListPacket();
    void clearClanShopGetBuffItemListPacket();
    void clearClanGetHistoryPacket();
    void setCardClanParam(const CClanParam& clanParam, cCharacterData::stCardClan& clanCard);
    void setMyClanParam(const CClanParam& src);
    void setClanParam(const CClanParam& param);
    void copyClanParam(const CClanParam& src, CClanParam& dst);
    const ClanSearchResultVec& getClanSearchResultListRef();
    const ClanJoinRequestVec& getClanJoinRequestListRef();
    const ClanJoinRequestVec& getClanApplyListRef();
    const ClanMemberInfoVec& getClanMemberInfoListRef();
    const ClanScoutEntrySearchResultVec& getClanScoutEntryListRef();
    const ClanScoutEntryInviteInfoVec& getClanInvitedListRef();
    CClanParam& getMyClanParamRef();
    CClanParam& getClanParamRef();
    const ClanScoutEntryInviteInfoVec& getClanInviteListRef();
    const ClanScoutEntryInviteInfoVec& getClanDirectInvitedListRef();
    const nUserSession::CPacket_S2C_CLAN_BASE_GET_INFO_RES& getClanBaseInfoRef();
    const ClanHistoryElementVec& getClanHistoryListRef();
    void clearClanSearchResultList();
    void clearClanJoinRequestList();
    void clearClanApplyList();
    void clearMyClanMemberInfoList();
    void clearClanMemberInfoList();
    void clearClanScoutEntryList();
    void clearClanInviteList();
    void clearClanInvitedList();
    void clearMyClanParam();
    void clearClanParam();
    void clearClanParam(CClanParam& param);
    void clearClanBaseInfo();
    void clearClanHistoryList();
    void setMyClanMemberList(const ClanMemberInfoVec& src);
    void copyClanMemberList(const ClanMemberInfoVec& src, ClanMemberInfoVec& dst);
    void updateMyClanMemberNum();
    void addClanMemberInfo(const CClanMemberInfo& src, ClanMemberInfoVec& dst);
    void removeClanMemberInfo(u32 characterId, ClanMemberInfoVec& dst);
    bool isClanMemberUpdate();
    void setClanMemberUpdate(bool flag);
    bool updateClanSetting(bool isNtc);
    void clearClanDirectInvitedList();
    bool addClanDirectInvitedInfo(const CClanScoutEntryInviteInfo& src);
    void removeClanDirectInvitedInfo(u32 clanId);
    void clearClanDirectInvitedInfo();
    void setMyClanLevel(u32 clanLevel, u32 nextPoint);
    void setMyTotalClanPoint(u32 totalPoint);
    void setMyMoneyClanPoint(u32 moneyPoint);
    MT_CTSTR getClanShopLineupName(u32 lineup_id);
    ClanMemberInfoVec& getMyClanMemberInfoList();
    u32 getClanApproveReqId();
    bool setOnlineStatus(nCharacter::E_ONLINE_STATUS status, bool isSaveSetting);
    bool eventStartNotice();
    bool eventEndNotice();
    bool getFriendList();
    bool applyFriend(u32 charId);
    bool cancelFriend(u32 charId);
    bool approveFriend(u32 charId, bool isApprove);
    bool removeFriend(u32 friendNo);
    bool setFavoriteFriend(u32 friendNo, bool isFavorite);
    void setFriendList(const FriendInfoVec& list);
    void setApplyingFriendList(const CommunityCharacterBaseInfoVec& list);
    void setApprovingFriendList(const CommunityCharacterBaseInfoVec& list);
    FriendInfoVec& getFriendListRef();
    CharacterListElementVec& getApplyingFriendListRef();
    CharacterListElementVec& getApprovingFriendListRef();
    CFriendInfo* getFriendInfo(u32 friendNo);
    CFriendInfo* getFriendInfoCharId(u32 characterId);
    void clearFriendList();
    bool isFriendUpdate();
    void setFriendUpdate(bool flag);
    bool isFriendApprove();
    u32 getCancelFriendCharId();
    u32 getRemoveFriendNo();
    bool createEntryBoardItem(u64 BoardID, MtString& Password, const CEntryItemParam& Param);
    bool recreateEntryBoardItem();
    bool getEntryBoardItemList(u64 BoardID, u32 Offset, u32 Num);
    bool joinEntryBoardItem(u64 BoardID, u32 EntryID, MT_CTSTR pPassword);
    bool leaveEntryBoardItem();
    bool readyEntryBoardItem();
    bool startEntryBoardItem();
    bool extendEntryBoardItem();
    bool getEntryBoardItemInfo(u64 BoardID, u32 EntryID, bool serverIn);
    bool lockEntryBoardItem();
    bool changeEntryBoardItemInfo(MtString& Password, const CEntryItemParam& Param);
    bool releaseEntryBoardItemPassword();
    bool changeEntryBoardItemComment(MtString& Comment);
    bool inviteEntryBoardItem(const MtTypedArray<CDataCommonU32>& characterIdList);
    void copyEntryMemberList(EntryMemberDataVec& dstList, const EntryMemberDataVec& srcList);
    void copyEntryRecruitList(EntryRecruitDataVec& dstList, const EntryRecruitDataVec& srcList);
    void copyEntryRecruitJob(EntryRecruitJobVec& dstList, const EntryRecruitJobVec& srcList);
    nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_LIST_RES* getEntryBoardItemListPacket();
    nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_RESERVE_NOTICE* getEntryBoardItemReservePacket();
    nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_INFO_RES* getEntryBoardItemInfoPacket();
    void clearEntryBoardItemListPacket();
    void clearEntryBoardItemInfoPacket();
    const EntryItemVec& getEntryItemListRef();
    const CEntryItem& getEntryItemRef();
    MT_CTSTR getEntryPassword();
    void setEntryPassword(MT_CTSTR password);
    u64 getGetInfoBoardId();
    u32 getGetInfoEntryId();
    bool reqGetSetContext(u32 id, u32 uniqueId, s32 stageNo, s32 encountArea, bool isLocal);
    bool reqSetContext(cContextInstance* pInst);
    void createSetContextPacket(CContextSetInfo& packet, cContextInstance* pInst, bool& isAdditional);
    void copySetCreateContext(const CContextSetBase& base, const CContextSetAdditional* pAddi);
    bool reqMasterThrow(MtTypedArray<CDataMasterInfo>* pInfo);
    bool reqMasterThrow(u32 uniqueId, s32 masterIndex);
    void setContextMasterIndex(const MtTypedArray<CDataMasterInfo>& infoRef);
    bool reqGetJobchangeList();
    bool reqChangeJob();
    bool reqChangeJob(u8 job);
    bool reqChangePawnJob();
    bool reqChangePawnJob(u32 pawnID, u8 job);
    nUserSession::CPacket_S2C_GET_JOB_CHANGE_LIST_RES* getGetJobChangeListPacket();
    void setJobchangeList(const JobChangeInfoVec&);
    JobChangeInfoVec& getJobchangeListRef();
    bool sendBadStatusNotice(u32 condition);
    bool sendPawnBadStatusNotice(u32 pawnId, u32 condition);
    bool getMailListHead();
    bool getMailListData(u32 offset, u32 num);
    bool getMailListFoot();
    bool getMailData(u64 mailId);
    bool deleteMail(u64 mailId);
    bool sendMail(const CommonU32Vec& ToList, MT_CTSTR pMessage);
    bool getSysMailListHead();
    bool getSysMailListData(u32 offset, u32 num);
    bool getSysMailListFoot();
    bool getSysMailData(u64 mailId);
    bool getSysMailItem(u64 mailId);
    bool getSysMailItemAll(u64 mailId);
    bool deleteSysMail(u64 mailId);
    void copyMailList(MailInfoVec& dstList, const MailInfoVec& srcList);
    void copyMailInfo(CMailInfo& dstInfo, const CMailInfo& srcInfo);
    void addMailList(MailInfoVec& dstList, const MailInfoVec& srcList);
    void addMailInfo(MailInfoVec& dstList, const CMailInfo& srcInfo);
    MailInfoVec& getMailListRef();
    void clearMailList();
    void clearAddMailList();
    MailInfoVec& getSysMailListRef();
    void clearSysMailList();
    void clearAddSysMailList();
    void mergeMailList();
    CMailInfo* getMailInfo(u64 mailId, s32* pMailType);
    void eraseMailInfo(u64 mailId);
    bool isReceiveMail();
    void setIsReceiveMail(bool flag);
    u32 getUnreadMailNum();
    bool isUnreadMail(CMailInfo* pInfo);
    bool isUnOpenedMail(CMailInfo* pInfo);
    u32 getUnGetItemMailNum();
    bool isUnGetItemMail(CMailInfo* pInfo);
    bool withOptionCourseMail(CMailInfo* pInfo);
    bool isExistNewMail();
    bool isExistNewUserMail();
    bool isExistNewSysMail();
    void clearMailDetail();
    nUserSession::CPacket_S2C_MAIL_GET_TEXT_RES* getUserMailPacket();
    nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES* getSystemMailPacket();
    void clearMailGetTextPacket();
    void clearSysMailGetTextPacket();
    MT_CTSTR getUserMailText();
    MT_CTSTR getSysMailText();
    const CMailAttachmentList& getSysMailAttachment();
    const CMailAttachmentList& getGetAttachmentList();
    const CMailAttachmentList& getUnGetAttachmentList();
    void clearGetAttachmentList();
    void countMailUpdateTimer();
    void resetMailUpdateTimer();
    bool isEnableMailUpdate();
    bool getRankingBoardList();
    bool getRankingDataRank(const u32 id, const u32 rank, const u8 num);
    bool getRankingDataRankByQuestScheduleId(const u32 id, const u32 rank, const u8 num);
    bool getRankingDataCharacterId(const u32 id, const CommonU32Vec& charIdVec);
    nUserSession::CPacket_S2C_RANKING_BOARD_LIST_RES* getRankingBoardListPacket();
    nUserSession::CPacket_S2C_RANKING_DATA_RANK_RES* getRankingDataRankPacket();
    nUserSession::CPacket_S2C_RANKING_DATA_RANK_BY_QUEST_SCHEDULE_ID_RES* getRankingDataRankByQuestScheduleIdPacket();
    nUserSession::CPacket_S2C_RANKING_DATA_CHARACTER_ID_RES* getRankingDataCharacterIdPacket();
    void clearRankingBoardListPacket();
    void clearRankingDataRankPacket();
    void clearRankingDataRankByQuestScheduleIdPacket();
    void clearRankingDataCharacterIdPacket();
    bool getBazaarCharacterInfo();
    bool getBazaarItemList(CommonU32Vec& itemList);
    bool getBazaarItemInfo(u32 itemId);
    bool getBazaarItemHistory(u32 itemId);
    bool startBazaarExhibit(u8 storageType, ItemUIDListVec& itemList, u32 price);
    bool restartBazaarExhibit(u64 bazaarId, u32 price);
    bool cancelBazaarExhibit(u64 bazaarId);
    bool purchaseBazaarItem(u64 bazaarId, u32 itemId, u32 sequenceId, ItemStorageIndicateNumVec& itemList);
    bool getBazaarProceeds();
    bool getBazaarItemPrimLimit(u32 itemId);
    bool getBazaarExhibitPossibleNum();
    bool getGroupChatMemberList();
    bool inviteGroupChat(u32 characterId);
    bool leaveGroupChat();
    bool kickGroupChat(u32 characterId);
    void copyCharacterListElement(CCharacterListElement& dstInfo, const CCharacterListElement& srcInfo);
    void copyGroupChatMemberList(CharacterListElementVec& dstList, const CharacterListElementVec& srcList);
    void addGroupChatMember(CharacterListElementVec& dstList, const CCharacterListElement& srcInfo);
    CharacterListElementVec& getGroupChatMemberListRef();
    void clearGroupChatMemberList();
    CCharacterListElement* getGroupChatMemberInfo(u32 characterId);
    void setGroupChatUpdate(bool flag);
    bool isGroupChatUpdate();
    bool getRecentList();
    void copyRecentList(CharacterListElementVec& dstList, const CharacterListElementVec& srcList);
    void addRecentMember(CharacterListElementVec& dstList, const CCharacterListElement& srcInfo);
    CharacterListElementVec& getRecentListRef();
    void clearRecentList();
    CCharacterListElement* getRecentMemberInfo(u32 characterId);
    void setRecentListStatusUpdate(bool flag);
    bool isRecentListStatusUpdate();
    bool getBlackList();
    bool addBlackList(CCommunityCharacterBaseInfo& info);
    bool removeBlackList(u32 characterId);
    void copyBlackList(CommunityCharacterBaseInfoVec& dstList, const CommunityCharacterBaseInfoVec& srcList);
    void addBlackMember(CommunityCharacterBaseInfoVec& dstList, const CCommunityCharacterBaseInfo& srcInfo);
    CommunityCharacterBaseInfoVec& getBlackListRef();
    void clearBlackList();
    bool reqUpdateCommunityCharacterStatus();
    void setActiveListUpdate(bool flag);
    bool isActiveListUpdate();
    bool updateLastBase(u32 baseId);
    bool getReturnLocation();
    nUserSession::CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES* getArisenCardBGListPacket();
    void clearArisenCardBGListPacket();
    bool getAchievementProgress();
    bool getAchievementReward();
    bool getFurnitureReward();
    bool getAchievementReceivableReward();
    bool achievementReceiveReward(const AchieveRewardCommonVec& reward_list);
    bool sendPhotoTakeNotice();
    bool reqGetCaplinkAchieveReward(const char* filteringContentId, MtTypedArray<CDataCommonU32>& achievementId);
    bool getReqGetCaplinkAchieveRewardResult() const;
    nUserSession::CPacket_S2C_ACHIEVEMENT_GET_PROGRESS_LIST_RES* getAchievementGetProgressListPacket();
    void clearAchievementGetProgressListPacket();
    nUserSession::CPacket_S2C_ACHIEVEMENT_GET_REWARD_LIST_RES* getAchievementGetRewardListPacket();
    void clearAchievementGetRewardListPacket();
    nUserSession::CPacket_S2C_ACHIEVEMENT_GET_FURNITURE_REWARD_LIST_RES* getAchievementGetFurnitureRewardListPacket();
    void clearAchievementGetFurnitureRewardListPacket();
    nUserSession::CPacket_S2C_ACHIEVEMENT_GET_RECEIVABLE_REWARD_LIST_RES* getAchievementGetReceiveableRewardListPacket();
    void clearAchievementGetReceiveableRewardListPacket();
    nUserSession::CPacket_S2C_ACHIEVEMENT_REWARD_RECEIVE_RES* getAchievementRewardReceivePacket();
    void clearAchievementRewardReceivePacket();
    bool sendCharacterDownNotice();
    bool sendCharacterDownCancelNotice();
    bool sendCharacterDeadNotice();
    bool reqCharacterPointRevive(u32 maxHp);
    bool reqCharacterGoldenRevive(u32 maxHp);
    bool reqCharacterPenaltyRevive(u32 maxHp);
    bool sendPawnDownNotice(unsigned int pawnId);
    bool sendPawnDownCancelNotice(unsigned int pawnId);
    bool sendPawnDeadNotice(unsigned int pawnId);
    bool reqPawnPointRevive(unsigned int pawnId, u32 maxHp);
    bool reqPawnGoldenRevive(unsigned int pawnId, u32 maxHp);
    bool reqGetReviveChargeableTime();
    bool reqChargeRevivePoint();
    bool reqGetRevivePoint();
    bool reqLoadingInfo();
    const CLoadingInfoSchedule* getLoadingInfo() const;
    bool getStampBonusList();
    bool checkStampBonus();
    bool recieveStampBonus(u8 stampBonusType);
    bool addStampBonusTotalNum();
    nUserSession::CPacket_S2C_STAMP_BONUS_GET_LIST_RES* getStampBonusGetListPacket();
    nUserSession::CPacket_S2C_STAMP_BONUS_CHECK_RES* getStampBonusCheckPacket();
    void getCogSessionKey(MtString& dst);
    bool getItemStorageInfo(const MtTypedArray<CDataGameItemStorage>& in_GameItemStorageList);
    nUserSession::CPacket_S2C_GET_ITEM_STORAGE_INFO_RES* getItemStorageInfoPacket();
    void clearItemStorageInfo();
    bool getEventCodeInput(MT_CTSTR pCode);
    bool getReportSiteAddress();
    bool getSupportPointRateList();
    bool useSupportPoint();
    bool useSupportPoint(UseSupportPointVec& list);
    nUserSession::CPacket_S2C_SUPPORT_POINT_GET_RATE_RES* getSupportPointRatePacket();
    nUserSession::CPacket_S2C_SUPPORT_POINT_USE_RES* getSupportPointUsePacket();
    void clearSupportPointRarePacket();
    void clearSupportPointUsePacket();
    bool getItemSortData();
    bool getItemSortData(CommonU32Vec& list);
    bool setItemSortData();
    bool setItemSortData(u32 index);
    nUserSession::CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES* getDispelItemSettingPacket();
    nUserSession::CPacket_S2C_GET_DISPEL_ITEM_LIST_RES* getDispelItemListPacket();
    nUserSession::CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES* getExchangeDispelItemPacket();
    void clearDispelItemSettingPacket();
    void clearDispelItemListPacket();
    void clearExchangeDispelItemPacket();
    u64 getNgWordVesionNo() const;
    void setNgWordVesionNo(u64);
    bool ping();
    bool getUrlList();
    bool getNgWordList();
    bool reqClientTimeoutNotice(u32 comId);
    bool getGameTimeBaseInfo();
    bool getPhotoAuthAddressReq();
    nUserSession::CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_INFO_RES* getPawnExpeditionSallyInfoPacket();
    nUserSession::CPacket_S2C_PAWN_EXPEDITION_GET_MY_SALLY_INFO_RES* getPawnExpeditionMySallyInfoPacket();
    nUserSession::CPacket_S2C_PAWN_EXPEDITION_GET_SALLY_REWARD_RES* getPawnExpeditionSallyRewardPacket();
    void clearPawnExpeditionSallyInfoPacket();
    void clearPawnExpeditionMySallyInfoPacket();
    void clearPawnExpeditionSallyRewardPacket();
    void updateRTT();
    s32 getAverageRTT();
    s32 getMaxRTT();
    s32 getSendBps();
    s32 getRecvBps();
    void startInstanceArea();
    bool copyContextParam(cContextInstHm* pContext, const CContextBase* pBase, const CContextPlayerInfo* pPl, const CContextResist* pResist, const CEditInfo* pEdit, bool IsPlayer, bool IsParty);
    bool copyContextParam(cContextInstHm* pContext, const CContextBase* pBase, const CContextPlayerInfo* pPl, const CContextPawnInfo* pPawn, const CContextResist* pResist, const CEditInfo* pEdit, bool IsPlayer, bool IsParty);
    bool isResetInstanceArea();
    void setIsResetInstanceArea(bool flag);
    void setFirstPawnAct(cContextInstHm* pContext);
    bool reqDLCLineupBoughts();
    void clearDLCLineupBoughts();
    bool reqDLCLineupUse(u32 dlcId);
    bool reqDLCLineupHistorys();
    void clearDLCLineupHistorys();
    bool reqGetSessionKey(bool update);
    DLCLineupBoughtVec* getDLCLineupBoughts();
    DLCLineupHistoryVec* getDLCLineupHistorys();
    bool setDLCLineupBoughts(const MtTypedArray<CDataDLCLineupBought>& list);
    bool setDLCLineupHistories(const MtTypedArray<CDataDLCLineupHistory>& list);
    bool reqScreenShotCategory();
    void clearScreenShotCategory();
    MtTypedArray<CDataScreenShotCategory>* getScreenShotCategory();
    bool reqServerUICommand(u32 uiid, u32 command, u32 argNum1, u32 argNum2);
    bool getDispelSetting();
    bool getDispelItemList();
    bool getDispelItemList(u8 category);
    bool exchangeDispelItem(const GetDispelItemVec& list);
    bool resetJobPoint(u32 SkillID, u8 SkillLv, u32 AbilityID, u8 AbilityLv, u32 PawnID);
    bool resetCraftPoint(u32 PawnID);
    bool reportCheat(u8 id);
    bool reportCheat(u8 id, u32 param1);
    bool reportCheat(u8 id, u32 param1, u32 param2);
    bool reportCheat(u8 id, u32 param1, u32 param2, u32 param3);
    bool reportCheat(u32 dataType, u8 id, u32 param1, u32 param2, u32 param3);
    bool addReportCheatQueue(stCheatInfo& info);
    void getReportCheatQueueAll(MtMemoryStream& data);
    void getReportCheatQueueAll(MtTypedArray<CDataCheatInfo>& data);
    bool getReportCheatQueue(CCheatInfo& info, u32 index);
    void clearReportCheatQueue();
    bool sendGetCheatInfoRes();
    bool reqMyRoomRelease();
    bool getPartnerPawnNextPresentTime();
    bool reqPresentForPartnerPawn(ItemUIDListVec& itemUIDList);
    bool setPartnerPawn(u32 pawnId);
    bool getPawnLikabilityRewardList();
    bool getPawnLikabilityReward(MtTypedArray<CDataPartnerPawnReward>& rewardUidList, u64 updateHairUid);
    bool getPawnLikabilityReleasedRewardList();
    bool updateMyRoomBgm(u32 bgmAcquirementNo);
    bool getWeatherForecast();
    nUserSession::CPacket_S2C_WEATHER_FORECAST_GET_RES* getWeatherForecastGetPacket();
    void clearWeatherForecastGetPacket();
    bool reqPlayPointList();
    bool reqUpdateExpMode(MtTypedArray<CDataJobExpMode>& list);
    bool reqPlayPointShopLineup(u8 jobId, u8 jobValueType);
    bool reqPlayPointShopBuy(u8 jobId, u32 lineupId, u8 num, u8 storageType, u32 price);
    nUserSession::CPacket_S2C_JOB_VALUE_SHOP_GET_LINEUP_RES* getPlayPointShopLineup();
    nUserSession::CPacket_S2C_JOB_VALUE_SHOP_BUY_ITEM_RES* getPlayPointShopBuy();
    void clearPlayPointShopLineup();
    void clearPlayPointShopBuy();
    bool reqClanBaseRelease();
    bool updateClanConcierge(u32 npcId, u32 price);
    bool getClanConciergeList();
    bool getClanPartnerPawnList();
    bool getClanPartnerPawnData(u32 pawnId);
    bool getClanShopFunctionItemList();
    bool getClanShopBuffItemList();
    bool buyClanShopFunctionItem(u32 lineup_id);
    bool buyClanShopBuffItem(u32 lineup_id);
    bool getPawnExpeditionRewardDrop();
    bool getPawnExpeditionRewardDropItemList(s32 stageNo, s32 groupId, s32 unitId);
    bool getPawnExpeditionRewardDropItem(s32 stageNo, s32 groupId, s32 unitId, GatheringItemGetRequestVec& itemList);
    bool getPawnExpeditionGetSallyInfo();
    bool getPawnExpeditionGetMySallyInfo();
    bool reqPawnExpeditionChargeSallyCount();
    bool reqPawnExpeditionSally(u32 area_id, u32 spot_id);
    bool reqPawnExpeditionChargeGoldenSally();
    bool getPawnExpeditionGetSallyReward();
    bool reqPawnExpeditionCancelSally();
    void reqSpecialError(s32 errCode, s32 msgNo, bool isLogout, bool isReturnLauncher, bool isDisconnect);
    void reqSpecialFreeMsg(MT_CTSTR pMsg, bool isLogout, bool isReturnLauncher);
    void reqErrorMessage(s32 errCode);
private:
    void reqSpecialErrorCore(s32 msgNo, MT_CTSTR pMsg, MtNetError* pErr, bool isLogout, bool isReturnLauncher, bool isDisconnect);
public:
    void onConnectionClosed(s32 errCode);
    void propOnConnectionClosed();
    void onRecvLobbyJoinNotice(CLobbyMemberInfo& info, bool isPushBack);
    void onRecvLobbyDataMsgResult(s32 code);
    void OnPacket_S2C_LOBBY_JOIN_RES(nUserSession::CPacket_S2C_LOBBY_JOIN_RES& packet);
    void OnPacket_S2C_LOBBY_LEAVE_RES(nUserSession::CPacket_S2C_LOBBY_LEAVE_RES& packet);
    void OnPacket_S2C_USER_LIST_LEAVE_NTC(nUserSession::CPacket_S2C_USER_LIST_LEAVE_NTC& packet);
    void OnPacket_S2C_SESSION_STATUS_NTC(nUserSession::CPacket_S2C_SESSION_STATUS_NTC& packet);
    void OnPacket_S2C_PARTY_CREATE_RES(nUserSession::CPacket_S2C_PARTY_CREATE_RES& packet);
    void OnPacket_S2C_PARTY_SEARCH_RES(nUserSession::CPacket_S2C_PARTY_SEARCH_RES& packet);
    void OnPacket_S2C_PARTY_INVITE_RES(nUserSession::CPacket_S2C_PARTY_INVITE_RES& packet);
    void OnPacket_S2C_PARTY_INVITE_CHARACTER_RES(nUserSession::CPacket_S2C_PARTY_INVITE_CHARACTER_RES& packet);
    void OnPacket_S2C_PARTY_INVITE_NTC(nUserSession::CPacket_S2C_PARTY_INVITE_NTC& packet);
    void OnPacket_S2C_PARTY_INVITE_CANCEL_NTC(nUserSession::CPacket_S2C_PARTY_INVITE_CANCEL_NTC& packet);
    void OnPacket_S2C_PARTY_INVITE_FAIL_NTC(nUserSession::CPacket_S2C_PARTY_INVITE_FAIL_NTC& packet);
    void OnPacket_S2C_PARTY_JOIN_NTC(nUserSession::CPacket_S2C_PARTY_JOIN_NTC& packet);
    void OnPacket_S2C_PARTY_INVITE_ENTRY_NTC(nUserSession::CPacket_S2C_PARTY_INVITE_ENTRY_NTC& packet);
    void OnPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_NTC(nUserSession::CPacket_S2C_PARTY_INVITE_ENTRY_CANCEL_NTC& packet);
    void OnPacket_S2C_PARTY_LEAVE_RES(nUserSession::CPacket_S2C_PARTY_LEAVE_RES& packet);
    void OnPacket_S2C_PARTY_LEAVE_NTC(nUserSession::CPacket_S2C_PARTY_LEAVE_NTC& packet);
    void OnPacket_S2C_PARTY_MEMBER_SESSION_STATUS_NTC(nUserSession::CPacket_S2C_PARTY_MEMBER_SESSION_STATUS_NTC& packet);
    void OnPacket_S2C_PARTY_MEMBER_KICK_NTC(nUserSession::CPacket_S2C_PARTY_MEMBER_KICK_NTC& packet);
    void OnPacket_S2C_PARTY_MEMBER_LOST_NTC(nUserSession::CPacket_S2C_PARTY_MEMBER_LOST_NTC& packet);
    void OnPacket_S2C_PARTY_BREAKUP_RES(nUserSession::CPacket_S2C_PARTY_BREAKUP_RES& packet);
    void OnPacket_S2C_PARTY_BREAKUP_NTC(nUserSession::CPacket_S2C_PARTY_BREAKUP_NTC& packet);
    void OnPacket_S2C_PARTY_CHANGE_LEADER_NTC(nUserSession::CPacket_S2C_PARTY_CHANGE_LEADER_NTC& packet);
    void OnPacket_S2C_PARTY_CHANGE_HOST_NTC(nUserSession::CPacket_S2C_PARTY_CHANGE_HOST_NTC& packet);
    void OnPacket_S2C_PLAY_ENTRY_NOTICE(nUserSession::CPacket_S2C_PLAY_ENTRY_NOTICE& packet);
    void OnPacket_S2C_PLAY_ENTRY_CANCEL_NOTICE(nUserSession::CPacket_S2C_PLAY_ENTRY_CANCEL_NOTICE& packet);
    void OnPacket_S2C_TIME_GAIN_QUEST_PLAY_START_NOTICE(nUserSession::CPacket_S2C_TIME_GAIN_QUEST_PLAY_START_NOTICE& packet);
    void OnPacket_S2C_GET_MYPAWN_LIST_RES(nUserSession::CPacket_S2C_GET_MYPAWN_LIST_RES& packet);
    void OnPacket_S2C_GET_MYPAWN_DATA_RES(nUserSession::CPacket_S2C_GET_MYPAWN_DATA_RES& packet);
    void OnPacket_S2C_GET_REGISTERED_PAWN_LIST_RES(nUserSession::CPacket_S2C_GET_REGISTERED_PAWN_LIST_RES& packet);
    void OnPacket_S2C_GET_REGISTERED_PAWN_DATA_RES(nUserSession::CPacket_S2C_GET_REGISTERED_PAWN_DATA_RES& packet);
    void OnPacket_S2C_GET_RENTED_PAWN_LIST_RES(nUserSession::CPacket_S2C_GET_RENTED_PAWN_LIST_RES& packet);
    void OnPacket_S2C_GET_RENTED_PAWN_DATA_RES(nUserSession::CPacket_S2C_GET_RENTED_PAWN_DATA_RES& packet);
    void OnPacket_S2C_GET_PARTY_PAWN_DATA_RES(nUserSession::CPacket_S2C_GET_PARTY_PAWN_DATA_RES& packet);
    void OnPacket_S2C_GET_PAWN_PROFILE_NOTICE(nUserSession::CPacket_S2C_GET_PAWN_PROFILE_NOTICE& packet);
    void OnPacket_S2C_JOIN_PARTY_PAWN_NOTICE(nUserSession::CPacket_S2C_JOIN_PARTY_PAWN_NOTICE& packet);
    void OnPacket_S2C_GET_FAVORITE_PAWN_LIST_RES(nUserSession::CPacket_S2C_GET_FAVORITE_PAWN_LIST_RES& packet);
    void OnPacket_S2C_GET_OFFICIAL_PAWN_LIST_RES(nUserSession::CPacket_S2C_GET_OFFICIAL_PAWN_LIST_RES& packet);
    void OnPacket_S2C_GET_LEGEND_PAWN_LIST_RES(nUserSession::CPacket_S2C_GET_LEGEND_PAWN_LIST_RES& packet);
    void OnPacket_S2C_GET_NORA_PAWN_LIST_RES(nUserSession::CPacket_S2C_GET_NORA_PAWN_LIST_RES& packet);
    void OnPacket_S2C_PAWN_LOST_RES(nUserSession::CPacket_S2C_PAWN_LOST_RES& packet);
    void OnPacket_S2C_GET_LOST_PAWN_LIST_RES(nUserSession::CPacket_S2C_GET_LOST_PAWN_LIST_RES& packet);
    void OnPacket_S2C_UPDATE_RENTAL_PAWN_ADVENTURE_COUNT_NOTICE(nUserSession::CPacket_S2C_UPDATE_RENTAL_PAWN_ADVENTURE_COUNT_NOTICE& packet);
    void OnPacket_S2C_UPDATE_PAWN_REACTION_LIST_RES(nUserSession::CPacket_S2C_UPDATE_PAWN_REACTION_LIST_RES& packet);
    void OnPacket_S2C_UPDATE_PAWN_REACTION_LIST_NOTICE(nUserSession::CPacket_S2C_UPDATE_PAWN_REACTION_LIST_NOTICE& packet);
    void OnPacket_S2C_GET_PAWN_HISTORY_LIST_RES(nUserSession::CPacket_S2C_GET_PAWN_HISTORY_LIST_RES& packet);
    void OnPacket_S2C_GET_PAWN_TOTAL_SCORE_RES(nUserSession::CPacket_S2C_GET_PAWN_TOTAL_SCORE_RES& packet);
    void OnPacket_S2C_USE_BAG_ITEM_NOTICE(nUserSession::CPacket_S2C_USE_BAG_ITEM_NOTICE& packet);
    void OnPacket_S2C_GET_STORAGE_ITEM_LIST_RES(nUserSession::CPacket_S2C_GET_STORAGE_ITEM_LIST_RES& packet);
    void OnPacket_S2C_QUEST_ORDER_RES(nUserSession::CPacket_S2C_QUEST_ORDER_RES& packet);
    void OnPacket_S2C_QUEST_PROGRESS_RES(nUserSession::CPacket_S2C_QUEST_PROGRESS_RES& packet);
    void OnPacket_S2C_QUEST_CANCEL_RES(nUserSession::CPacket_S2C_QUEST_CANCEL_RES& packet);
    void OnPacket_S2C_QUEST_COMPLETE_NOTICE(nUserSession::CPacket_S2C_QUEST_COMPLETE_NOTICE& packet);
    void OnPacket_S2C_DELIVER_ITEM_NOTICE(nUserSession::CPacket_S2C_DELIVER_ITEM_NOTICE& packet);
    void OnPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE(nUserSession::CPacket_S2C_DECIDE_DELIVERY_ITEM_NOTICE& packet);
    void OnPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE(nUserSession::CPacket_S2C_PARTY_QUEST_COMPLETE_NOTICE& packet);
    void OnPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE(nUserSession::CPacket_S2C_PARTY_QUEST_PROGRESS_NOTICE& packet);
    void OnPacket_S2C_GET_CYCLE_CONTENTS_STATE_LIST_RES(nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_STATE_LIST_RES& packet);
    void OnPacket_S2C_GET_CYCLE_CONTENTS_SITUATION_INFO_LIST_RES(nUserSession::CPacket_S2C_GET_CYCLE_CONTENTS_SITUATION_INFO_LIST_RES& packet);
    void OnPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE(nUserSession::CPacket_S2C_FORT_DEFENSE_WAR_SITUATION_LEVEL_NOTICE& packet);
    void OnPacket_S2C_FORT_DEFENSE_PLAY_START_NOTICE(nUserSession::CPacket_S2C_FORT_DEFENSE_PLAY_START_NOTICE& packet);
    void OnPacket_S2C_RAID_BOSS_PLAY_START_NOTICE(nUserSession::CPacket_S2C_RAID_BOSS_PLAY_START_NOTICE& packet);
    void OnPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES(nUserSession::CPacket_S2C_GET_QUEST_LAYOUT_FLAG_RES& packet);
    void OnPacket_S2C_PING_RES(nUserSession::CPacket_S2C_PING_RES& packet);
    void OnPacket_S2C_GET_STAGE_LIST_RES(nUserSession::CPacket_S2C_GET_STAGE_LIST_RES& packet);
    void OnPacket_S2C_AREA_CHANGE_RES(nUserSession::CPacket_S2C_AREA_CHANGE_RES& packet);
    void OnPacket_S2C_GET_GATHERING_ITEM_LIST_RES(nUserSession::CPacket_S2C_GET_GATHERING_ITEM_LIST_RES& packet);
    void OnPacket_S2C_GET_GATHERING_ITEM_RES(nUserSession::CPacket_S2C_GET_GATHERING_ITEM_RES& packet);
    void OnPacket_S2C_GET_CHARACTER_EQUIP_LIST_RES(nUserSession::CPacket_S2C_GET_CHARACTER_EQUIP_LIST_RES& packet);
    void OnPacket_S2C_GET_PAWN_EQUIP_LIST_RES(nUserSession::CPacket_S2C_GET_PAWN_EQUIP_LIST_RES& packet);
    void OnPacket_S2C_CHANGE_CHARACTER_EQUIP_RES(nUserSession::CPacket_S2C_CHANGE_CHARACTER_EQUIP_RES& packet);
    void OnPacket_S2C_CHANGE_CHARACTER_STORAGE_EQUIP_RES(nUserSession::CPacket_S2C_CHANGE_CHARACTER_STORAGE_EQUIP_RES& packet);
    void OnPacket_S2C_CHANGE_PAWN_EQUIP_RES(nUserSession::CPacket_S2C_CHANGE_PAWN_EQUIP_RES& packet);
    void OnPacket_S2C_CHANGE_PAWN_STORAGE_EQUIP_RES(nUserSession::CPacket_S2C_CHANGE_PAWN_STORAGE_EQUIP_RES& packet);
    void OnPacket_S2C_CHANGE_CHARACTER_EQUIP_JOB_ITEM_RES(nUserSession::CPacket_S2C_CHANGE_CHARACTER_EQUIP_JOB_ITEM_RES& packet);
    void OnPacket_S2C_CHANGE_PAWN_EQUIP_JOB_ITEM_RES(nUserSession::CPacket_S2C_CHANGE_PAWN_EQUIP_JOB_ITEM_RES& packet);
    void OnPacket_S2C_START_CRAFT_RES(nUserSession::CPacket_S2C_START_CRAFT_RES& packet);
    void OnPacket_S2C_FINISH_CRAFT_NOTICE(nUserSession::CPacket_S2C_FINISH_CRAFT_NOTICE& packet);
    void OnPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES(nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_INFO_RES& packet);
    void OnPacket_S2C_GET_CRAFT_PRODUCT_RES(nUserSession::CPacket_S2C_GET_CRAFT_PRODUCT_RES& packet);
    void OnPacket_S2C_CANCEL_CRAFT_RES(nUserSession::CPacket_S2C_CANCEL_CRAFT_RES& packet);
    void OnPacket_S2C_START_EQUIP_GRADE_UP_RES(nUserSession::CPacket_S2C_START_EQUIP_GRADE_UP_RES& packet);
    void OnPacket_S2C_CRAFT_EXP_UP_NOTICE(nUserSession::CPacket_S2C_CRAFT_EXP_UP_NOTICE& packet);
    void OnPacket_S2C_CRAFT_RANK_UP_NOTICE(nUserSession::CPacket_S2C_CRAFT_RANK_UP_NOTICE& packet);
    void OnPacket_S2C_GET_CRAFT_SETTING_RES(nUserSession::CPacket_S2C_GET_CRAFT_SETTING_RES& packet);
    void OnPacket_S2C_GET_CRAFT_IR_COLLECTION_VALUE_LIST_RES(nUserSession::CPacket_S2C_GET_CRAFT_IR_COLLECTION_VALUE_LIST_RES& packet);
    void OnPacket_S2C_CLAN_GET_INFO_RES(nUserSession::CPacket_S2C_CLAN_GET_INFO_RES& packet);
    void OnPacket_S2C_CLAN_GET_MY_INFO_RES(nUserSession::CPacket_S2C_CLAN_GET_MY_INFO_RES& packet);
    void OnPacket_S2C_GET_FRIEND_LIST_RES(nUserSession::CPacket_S2C_GET_FRIEND_LIST_RES& packet);
    void OnPacket_S2C_GET_RELEASE_SKILL_LIST_RES(nUserSession::CPacket_S2C_GET_RELEASE_SKILL_LIST_RES& packet);
    void OnPacket_S2C_GET_RELEASE_ABILITY_LIST_RES(nUserSession::CPacket_S2C_GET_RELEASE_ABILITY_LIST_RES& packet);
    void OnPacket_S2C_STAY_INN_RES(nUserSession::CPacket_S2C_STAY_INN_RES& packet);
    void OnPacket_S2C_STAY_PENALTY_HEAL_INN_RES(nUserSession::CPacket_S2C_STAY_PENALTY_HEAL_INN_RES& packet);
    void OnPacket_S2C_RANDOM_STAGE_GET_INFO_RES(nUserSession::CPacket_S2C_RANDOM_STAGE_GET_INFO_RES& packet);
    void OnPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES(nUserSession::CPacket_S2C_RANDOM_STAGE_CLEAR_INFO_RES& packet);
    void OnPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE(nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_LEAVE_NOTICE& packet);
    void OnPacket_S2C_ENTRY_BOARD_ITEM_CHANGE_MEMBER_NOTICE(nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_CHANGE_MEMBER_NOTICE& packet);
    void OnPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE(nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_READY_NOTICE& packet);
    void OnPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE(nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_UNREADY_NOTICE& packet);
    void OnPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES(nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_EXTEND_TIMEOUT_RES& packet);
    void OnPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE(nUserSession::CPacket_S2C_ENTRY_BOARD_ITEM_TIMEOUT_TIMER_NOTICE& packet);
    void OnPacket_S2C_MAIL_GET_LIST_DATA_RES(nUserSession::CPacket_S2C_MAIL_GET_LIST_DATA_RES& packet);
    void OnPacket_S2C_MAIL_GET_TEXT_RES(nUserSession::CPacket_S2C_MAIL_GET_TEXT_RES& packet);
    void OnPacket_S2C_MAIL_DELETE_RES(nUserSession::CPacket_S2C_MAIL_DELETE_RES& packet);
    void OnPacket_S2C_MAIL_SEND_NTC(nUserSession::CPacket_S2C_MAIL_SEND_NTC& packet);
    void OnPacket_S2C_SYSTEM_MAIL_GET_LIST_DATA_RES(nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_LIST_DATA_RES& packet);
    void OnPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES(nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_TEXT_RES& packet);
    void OnPacket_S2C_SYSTEM_MAIL_GET_ITEM_RES(nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_ITEM_RES& packet);
    void OnPacket_S2C_SYSTEM_MAIL_GET_ALL_ITEM_RES(nUserSession::CPacket_S2C_SYSTEM_MAIL_GET_ALL_ITEM_RES& packet);
    void OnPacket_S2C_SYSTEM_MAIL_DELETE_RES(nUserSession::CPacket_S2C_SYSTEM_MAIL_DELETE_RES& packet);
    void OnPacket_S2C_SYSTEM_MAIL_SEND_NTC(nUserSession::CPacket_S2C_SYSTEM_MAIL_SEND_NTC& packet);
    void OnPacket_S2C_GROUP_CHAT_GET_MEMBER_LIST_RES(nUserSession::CPacket_S2C_GROUP_CHAT_GET_MEMBER_LIST_RES& packet);
    void OnPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES(nUserSession::CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_RES& packet);
    void OnPacket_S2C_GROUP_CHAT_LEAVE_CHARACTER_RES(nUserSession::CPacket_S2C_GROUP_CHAT_LEAVE_CHARACTER_RES& packet);
    void OnPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_NTC(nUserSession::CPacket_S2C_GROUP_CHAT_INVITE_CHARACTER_NTC& packet);
    void OnPacket_S2C_GROUP_CHAT_LEAVE_CHARACTER_NTC(nUserSession::CPacket_S2C_GROUP_CHAT_LEAVE_CHARACTER_NTC& packet);
    void OnPacket_S2C_GROUP_CHAT_KICK_CHARACTER_NTC(nUserSession::CPacket_S2C_GROUP_CHAT_KICK_CHARACTER_NTC& packet);
    void OnPacket_S2C_GROUP_CHAT_BREAKUP_GROUP_NTC(nUserSession::CPacket_S2C_GROUP_CHAT_BREAKUP_GROUP_NTC& packet);
    void OnPacket_S2C_SEND_TELL_MSG_RES(nUserSession::CPacket_S2C_SEND_TELL_MSG_RES& packet);
    void OnPacket_S2C_GET_RECENT_CHARACTER_LIST_RES(nUserSession::CPacket_S2C_GET_RECENT_CHARACTER_LIST_RES& packet);
    void OnPacket_S2C_COMMUNITY_CHARACTER_STATUS_UPDATE_NTC(nUserSession::CPacket_S2C_COMMUNITY_CHARACTER_STATUS_UPDATE_NTC& packet);
    void OnPacket_S2C_GET_BLACK_LIST_RES(nUserSession::CPacket_S2C_GET_BLACK_LIST_RES& packet);
    void OnPacket_S2C_ADD_BLACK_LIST_RES(nUserSession::CPacket_S2C_ADD_BLACK_LIST_RES& packet);
    void OnPacket_S2C_REMOVE_BLACK_LIST_RES(nUserSession::CPacket_S2C_REMOVE_BLACK_LIST_RES& packet);
    void OnPacket_S2C_GET_POST_ITEM_LIST_RES(nUserSession::CPacket_S2C_GET_POST_ITEM_LIST_RES& packet);
    void OnPacket_S2C_LOADING_GET_INFO_RES(nUserSession::CPacket_S2C_LOADING_GET_INFO_RES&);
    void OnPacket_S2C_SUPPORT_POINT_GET_RATE_RES(nUserSession::CPacket_S2C_SUPPORT_POINT_GET_RATE_RES& packet);
    void OnPacket_S2C_SUPPORT_POINT_USE_RES(nUserSession::CPacket_S2C_SUPPORT_POINT_USE_RES& packet);
    void OnPacket_S2C_GET_ITEM_SORTDATA_BIN_RES(nUserSession::CPacket_S2C_GET_ITEM_SORTDATA_BIN_RES& packet);
    void OnPacket_S2C_SET_ITEM_SORTDATA_BIN_RES(nUserSession::CPacket_S2C_SET_ITEM_SORTDATA_BIN_RES& packet);
    void OnPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES(nUserSession::CPacket_S2C_GET_SCREEN_SHOT_CATEGORY_RES& packet);
    void OnPacket_S2C_GET_ITEM_STORAGE_INFO_RES(nUserSession::CPacket_S2C_GET_ITEM_STORAGE_INFO_RES& packet);
    void OnPacket_S2C_GET_DISPEL_ITEM_SETTING_RES(nUserSession::CPacket_S2C_GET_DISPEL_ITEM_SETTING_RES& packet);
    void OnPacket_S2C_GET_DISPEL_ITEM_LIST_RES(nUserSession::CPacket_S2C_GET_DISPEL_ITEM_LIST_RES& packet);
    void OnPacket_S2C_EXCHANGE_DISPEL_ITEM_RES(nUserSession::CPacket_S2C_EXCHANGE_DISPEL_ITEM_RES& packet);
    void OnPacket_S2C_RESET_JOBPOINT_RES(nUserSession::CPacket_S2C_RESET_JOBPOINT_RES& packet);
    void OnPacket_S2C_RESET_CRAFTPOINT_RES(nUserSession::CPacket_S2C_RESET_CRAFTPOINT_RES& packet);
    void OnPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES(nUserSession::CPacket_S2C_PARTNER_PAWN_NEXT_PRESENT_TIME_GET_RES& packet);
    void OnPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES(nUserSession::CPacket_S2C_PRESENT_FOR_PARTNER_PAWN_RES& packet);
    void OnPacket_S2C_PARTNER_PAWN_SET_RES(nUserSession::CPacket_S2C_PARTNER_PAWN_SET_RES& packet);
    void OnPacket_S2C_PAWN_LIKABILITY_REWARD_LIST_GET_RES(nUserSession::CPacket_S2C_PAWN_LIKABILITY_REWARD_LIST_GET_RES& packet);
    void OnPacket_S2C_PAWN_LIKABILITY_RELEASED_REWARD_LIST_GET_RES(nUserSession::CPacket_S2C_PAWN_LIKABILITY_RELEASED_REWARD_LIST_GET_RES& packet);
private:
    sNetworkExt::NET_STAT mStatus[563];  // offset: 0x8
    nError::ERROR_CODE mErrorCode[563];  // offset: 0x8d4
    f32 mComTimer[563];  // offset: 0x11a0
    u32 mErrorDialogHandle;  // offset: 0x1a6c
    bool mIsNgErrorDialog[563];  // offset: 0x1a70
    bool mIsOnceNgErrorDialog[563];  // offset: 0x1ca3
public:
    void* mpJoinPartyJobChangeReq;  // offset: 0x1ed8
private:
    cCtrlFlow mFlow[6];  // offset: 0x1ee0
    s32 mLoginRno;  // offset: 0x1fd0
    bool mIsExecLogin;  // offset: 0x1fd4
public:
    MtString mGMMessage;  // offset: 0x1fd8
private:
    cSeedGameSvConnection* mpConnection;  // offset: 0x1fe0
    LoginData mLoginData;  // offset: 0x1fe8
    MtString mPrologueServerAddr;  // offset: 0x2058
    u16 mProloguePortNo;  // offset: 0x2060
    bool mIsCOGLogin;  // offset: 0x2062
    MtCipher mCipher;  // offset: 0x2068
    u32 mWorldId;  // offset: 0x3dd0
    CWorldInfo mWorldInfo;  // offset: 0x3dd8
    s32 mGetWorldInfoSize;  // offset: 0x3e38
    CharacterListInfoVec mCharacters;  // offset: 0x3e40
    CCharacterInfo mCharacterInfoForCreate;  // offset: 0x3e60
    u32 mUpdateCharacterId;  // offset: 0x4128
    CCharacterInfo mCharacterInfoForUpdate;  // offset: 0x4130
    cCharacterData* mpCustomCharacterData;  // offset: 0x43f8
    cContextInstHm* mpCustomContext;  // offset: 0x4400
    u32 mDeleteCharacterId;  // offset: 0x4408
    bool mDeathPenaltyWait;  // offset: 0x440c
    CLobbyInfo mLobbyInfo;  // offset: 0x4410
    MT_ENUM mCharacterEnumList[255];  // offset: 0x4430
    u32 mLobbyCharacterId;  // offset: 0x5420
    MtString mCharacterName;  // offset: 0x5428
    MtString mChatMsg;  // offset: 0x5430
    LobbyMemberInfoVec mLobbyMembers;  // offset: 0x5438
    MtTypedArray<cChatLog> mChatLog;  // offset: 0x5458
    u32 mTellChatCharacterId;  // offset: 0x5478
    u32 mTellDataCharacterId;  // offset: 0x547c
public:
    u32 mInviteCharacterId;  // offset: 0x5480
private:
    ClientPartyListInfoVec mPartyListInfoVec;  // offset: 0x5488
    cPartyMemberInfoVec mPartyMemberInfoVec;  // offset: 0x54a8
    u64 mPartyContentNumber;  // offset: 0x54c8
    u32 mInvitePartyId;  // offset: 0x54d0
    u32 mInviteSequenceId;  // offset: 0x54d4
    u32 mInvitePartyNum;  // offset: 0x54d8
    u32 mInviteServerNo;  // offset: 0x54dc
    u32 mJoinPartyId;  // offset: 0x54e0
    u32 mRecvPartyId;  // offset: 0x54e4
    u32 mRecvCharacterId;  // offset: 0x54e8
    u32 mLeaderCharacterId;  // offset: 0x54ec
    u32 mLeaderChangeCharacterId;  // offset: 0x54f0
    u32 mOldLeaderCharacterId;  // offset: 0x54f4
    s32 mKickMemberIndex;  // offset: 0x54f8
    s32 mSelfMemberIndex;  // offset: 0x54fc
    f32 mInvitedTimeOutFrame;  // offset: 0x5500
    u32 mInvitedStageNo;  // offset: 0x5504
    u32 mInvitedPosNo;  // offset: 0x5508
    u32 mInvitedPosOffset;  // offset: 0x550c
    bool mIsInviteAccept;  // offset: 0x5510
    bool mIsRecvInFlag;  // offset: 0x5511
    bool mIsJoinParty;  // offset: 0x5512
    bool mIsInviteAcceptNotice;  // offset: 0x5513
    u32 mInviteLeaderCharacterId;  // offset: 0x5514
    MtString mInviteTargetLeaderName;  // offset: 0x5518
    CPartySearchParameter mPartyFilterParam;  // offset: 0x5520
    CQuickMatchSearchParameter mQuickFilterParam;  // offset: 0x5550
    CCharacterSearchParam mCharacterFilterParam;  // offset: 0x5568
    CPawnSearchParameter mPawnFilterParam;  // offset: 0x5580
    CClanSearchParam mClanFilterParam;  // offset: 0x5608
    CEntryBoardItemSearchParameter mEntryBoardFilterParam;  // offset: 0x5638
    CClientPartyListInfo mInvitePartyListInfo;  // offset: 0x5690
    nNet::QUICK_MATCH_TYPE mQuickPartyType;  // offset: 0x5700
    CQuickPartyMatching mQuickPartySetting;  // offset: 0x5708
    MtString mQuickQuestName;  // offset: 0x5720
    s32 mMyPawnSlotNo;  // offset: 0x5728
    cPawnListVec mMyPawnList;  // offset: 0x5730
    s32 mRegisterdPawnId;  // offset: 0x5750
    cPawnListVec mRegisterdPawnList;  // offset: 0x5758
    u64 mRegisterdPawnUpdated;  // offset: 0x5778
    u32 mRegisterdPawnRentalCost;  // offset: 0x5780
    s32 mRentedPawnSlotNo;  // offset: 0x5784
    cPawnListVec mRentedPawnList;  // offset: 0x5788
    cPawnListVec mLostPawnList;  // offset: 0x57a8
    s32 mLostPawnId;  // offset: 0x57c8
    cCharacterData::stPawnData* mpMyPawnData;  // offset: 0x57d0
    cCharacterData::stPawnData mRecvPawnData;  // offset: 0x57d8
    PAWN_MEMBER_MIN_INFO mSavePawnMemberInfo[8];  // offset: 0x7140
    u32 mReqJoinPawnId;  // offset: 0x71c0
    MtString mPawnName;  // offset: 0x71c8
    s32 mFavoritePawnId;  // offset: 0x71d0
    s32 mUpdateReactionPawnId;  // offset: 0x71d4
    PawnReactionVec mUpdatePawnReactionList;  // offset: 0x71d8
    s32 mUpdateShareRangePawnId;  // offset: 0x71f8
    u8 mUpdateShareRangeType;  // offset: 0x71fc
    s32 mGetHistoryListPawnId;  // offset: 0x7200
    PawnHistoryVec mPawnHistoryList;  // offset: 0x7208
    bool mIsKeepEquip;  // offset: 0x7228
    u8 mEquipItemColor;  // offset: 0x7229
    u8 mEquipItemQuality;  // offset: 0x722a
    u32 mEquipItemPoint;  // offset: 0x722c
    u32 mItemNum;  // offset: 0x7230
    MtString mItemUID;  // offset: 0x7238
    CommonU8Vec mItemStorageList;  // offset: 0x7240
    u16 mItemSlotNo;  // offset: 0x7260
    ItemListVec mBagItemList;  // offset: 0x7268
    ItemUIDListVec mGetRewardItemList;  // offset: 0x7288
    ItemUIDListVec mUseItemList;  // offset: 0x72a8
    u8 mSourceGameStorageType;  // offset: 0x72c8
    MoveItemUIDFromToVec mReqMoveSlotItemList;  // offset: 0x72d0
    StorageItemUIDListVec mReqStorageItemList;  // offset: 0x72f0
    u32 mUsedItemCharacterId;  // offset: 0x7310
    u32 mUsedItemId;  // offset: 0x7314
    u32 mUsedItemNum;  // offset: 0x7318
    S2CCharacterEquipInfoVec mRecvEquipList;  // offset: 0x7320
    S2CCharacterEquipInfoVec mRecvChangeEquipList;  // offset: 0x7340
    S2CCharacterEquipInfoVec mRecvChangePawnEquipList;  // offset: 0x7360
    u32 mRecvChangePawnEquipPawnId;  // offset: 0x7380
    u32 mEquipPawnId;  // offset: 0x7384
    EquipJobItemVec mRecvEquipJobItemList;  // offset: 0x7388
    EquipJobItemVec mRecvChangeEquipJobItemList;  // offset: 0x73a8
    EquipJobItemVec mRecvChangePawnEquipJobItemList;  // offset: 0x73c8
    u32 mRecvChangePawnEquipJobItemPawnId;  // offset: 0x73e8
    cEditParam mReqEditData;  // offset: 0x73f0
    u32 mCharEditPawnSlotNo;  // offset: 0x7c40
    cEditParam mReqPawnEditData;  // offset: 0x7c48
    u32 mLightQuestBaseId;  // offset: 0x8498
    u32 mClanQuestBaseId;  // offset: 0x849c
    u32 mSetQuestDistributeId;  // offset: 0x84a0
    u32 mTutorialQuestStageNo;  // offset: 0x84a4
    u32 mQuestScheduleId;  // offset: 0x84a8
    u32 mPlayStartQuestScheduleId;  // offset: 0x84ac
    QuestProcessStateVec* mpQuestProcessStateList;  // offset: 0x84b0
    u32 mRecvProgressQuestScheduleId;  // offset: 0x84b8
    u32 mRecvCancelQuestScheduleId;  // offset: 0x84bc
    cCompleteQuestList mCompleteQuestList;  // offset: 0x84c0
    u32 mRecvGetRewardBoxListNum;  // offset: 0x84e0
    u32 mReqDebugQuestForceProgressScheduleId;  // offset: 0x84e4
    u16 mReqDebugQuestForceProgressProcessNo;  // offset: 0x84e8
    u32 mReqDebugMainQuestJumpQuestId;  // offset: 0x84ec
    u32 mReqDebugQuestResetQuestId;  // offset: 0x84f0
    u8 mReqDebugQuestResetQuestType;  // offset: 0x84f4
    u8 mPawnDungeonRewardNo;  // offset: 0x84f5
    bool mReqReturnSession;  // offset: 0x84f6
    CycleContentsStateListVec mCycleContentsStateList;  // offset: 0x84f8
    u32 mCycleContentsScheduleId;  // offset: 0x8518
    QuestContentsSituationInfoVec mQuestContentsSituationInfo;  // offset: 0x8520
    u32 mBorderRewardResultScore;  // offset: 0x8540
    u32 mRankingRewardResultRank;  // offset: 0x8544
    s64 mCycleContentsPointUpload;  // offset: 0x8548
    s32 mQuestPlayTimeSec;  // offset: 0x8550
    b8 mIsContentsInterruptAnswer;  // offset: 0x8554
    u32 mEndContentsGroupId;  // offset: 0x8558
    u32 mGachaId;  // offset: 0x855c
    u32 mGachaSettlementId;  // offset: 0x8560
    u32 mGachaPrice;  // offset: 0x8564
    u32 mGachaDrawNum;  // offset: 0x8568
    u32 mGachaDrawId;  // offset: 0x856c
    u64 mGachaPrePriceGP;  // offset: 0x8570
    u64 mGachaPrePriceTicket;  // offset: 0x8578
    cPawnVoiceList mPawnVoiceList;  // offset: 0x8580
    cEditSalonInfo mEditSalonParam;  // offset: 0x85a0
    u32 mReqAreaChangeStageNo;  // offset: 0x85b0
    u32 mReqAreaChangeJumpType;  // offset: 0x85b4
    u32 mReqEnemySetStageNo;  // offset: 0x85b8
    u32 mReqEnemySetGroupId;  // offset: 0x85bc
    u32 mReqEnemySetLayerNo;  // offset: 0x85c0
    u32 mReqEnemyKilledStageNo;  // offset: 0x85c4
    u32 mReqEnemyKilledGroupId;  // offset: 0x85c8
    u32 mReqEnemyKilledLayerNo;  // offset: 0x85cc
    u32 mReqEnemyKilledSetId;  // offset: 0x85d0
    u32 mReqEnemyKilledInnerId;  // offset: 0x85d4
    u32 mReqItemSetListStageNo;  // offset: 0x85d8
    u32 mReqItemSetListGroupId;  // offset: 0x85dc
    u32 mReqItemSetListLayerNo;  // offset: 0x85e0
    u32 mReqItemSetListPosId;  // offset: 0x85e4
    u32 mReqGatheringItemListStageNo;  // offset: 0x85e8
    u32 mReqGatheringItemListGroupId;  // offset: 0x85ec
    u32 mReqGatheringItemListLayerNo;  // offset: 0x85f0
    u32 mReqGatheringItemListPosId;  // offset: 0x85f4
    u32 mReqGatheringItemStageNo;  // offset: 0x85f8
    u32 mReqGatheringItemGroupId;  // offset: 0x85fc
    u32 mReqGatheringItemLayerNo;  // offset: 0x8600
    u32 mReqGatheringItemPosId;  // offset: 0x8604
    StageInfoVec mStageList;  // offset: 0x8608
    u32 mRecvAreaChangeStageNo;  // offset: 0x8628
    GatheringItemElementVec mRecvGatheringItemList;  // offset: 0x8630
    u32 mRecvGatheringItemListStageNo;  // offset: 0x8650
    u32 mRecvGatheringItemListGroupId;  // offset: 0x8654
    u32 mRecvGatheringItemListLayerNo;  // offset: 0x8658
    u32 mRecvGatheringItemListPosId;  // offset: 0x865c
    GatheringItemGetRequestVec mRecvGatheringItem;  // offset: 0x8660
    u32 mRecvGatheringItemStageNo;  // offset: 0x8680
    u32 mRecvGatheringItemGroupId;  // offset: 0x8684
    u32 mRecvGatheringItemLayerNo;  // offset: 0x8688
    u32 mRecvGatheringItemPosId;  // offset: 0x868c
    u32 mReqInstantValueKey;  // offset: 0x8690
    u32 mReqInstantValue;  // offset: 0x8694
    MtString mReqInstantStringKey;  // offset: 0x8698
    MtString mReqInstantString;  // offset: 0x86a0
    u32 mRecvInstantValue;  // offset: 0x86a8
    MtString mRecvInstantString;  // offset: 0x86b0
    u32 mReqChangeCAPToGPListId;  // offset: 0x86b8
    u32 mReqBuyPayItemLineupPayItemId;  // offset: 0x86bc
    u32 mReqBuyPayItemLineupPointType;  // offset: 0x86c0
    u32 mReqPayItemBuyHistoryPageNo;  // offset: 0x86c4
    u32 mReqPayItemUnusedListPageNo;  // offset: 0x86c8
    u32 mReqPayItemEnableListPageNo;  // offset: 0x86cc
    u32 mRecvGetGP;  // offset: 0x86d0
    u32 mRecvGetCAP;  // offset: 0x86d4
    bool mCOGLoginSkipFlag;  // offset: 0x86d8
    bool mIsGPShopCanBuyPawn;  // offset: 0x86d9
    bool mIsGPShopCanBuyPawnVoice;  // offset: 0x86da
    u32 mAreaID;  // offset: 0x86dc
    u8 mSupplyStorage;  // offset: 0x86e0
    u32 mAreaPoint;  // offset: 0x86e4
    u32 mBuyQuestScheduleId;  // offset: 0x86e8
    u8 mJobID;  // offset: 0x86ec
    u8 in_RewardType8;  // offset: 0x86ed
    u32 in_RewardNo32;  // offset: 0x86f0
    u8 in_RewardLv8;  // offset: 0x86f4
    u8 in_Type8;  // offset: 0x86f5
    u32 in_ID32;  // offset: 0x86f8
    u32 in_Rank32;  // offset: 0x86fc
    u32 in_Num32;  // offset: 0x8700
    u8 mGainUnitType;  // offset: 0x8704
    u8 mOrbPageNo;  // offset: 0x8705
    u32 mOrbElementID;  // offset: 0x8708
    u32 mOrbPawnID;  // offset: 0x870c
    COrbGainExtendParam mMyExtendParam;  // offset: 0x8710
    COrbGainExtendParam mPawnExtendParam;  // offset: 0x8738
    CClanParam mMyClanParam;  // offset: 0x8760
    CClanParam mClanParam;  // offset: 0x8868
    ClanMemberInfoVec mMyClanMemberList;  // offset: 0x8970
    ClanScoutEntryInviteInfoVec mClanDirectInvitedList;  // offset: 0x8990
    bool mClanMemberUpdate;  // offset: 0x89b0
    u32 mClanApproveReqId;  // offset: 0x89b4
    u8 mOnlineStatusID;  // offset: 0x89b8
    FriendInfoVec mFriendList;  // offset: 0x89c0
    CharacterListElementVec mApplyingFriendList;  // offset: 0x89e0
    CharacterListElementVec mApprovingFriendList;  // offset: 0x8a00
    bool mFriendUpdate;  // offset: 0x8a20
    bool mIsFriendApprove;  // offset: 0x8a21
    u32 mCancelFriendCharacterId;  // offset: 0x8a24
    u32 mRemoveFriendNo;  // offset: 0x8a28
    MT_CHAR mEntryPassword[13];  // offset: 0x8a2c
    u64 mGetInfoBoardId;  // offset: 0x8a40
    u32 mGetInfoEntryId;  // offset: 0x8a48
    u32 mChangeJobPawnId;  // offset: 0x8a4c
    u32 mChangeJob;  // offset: 0x8a50
    JobChangeInfoVec mJobchangeList;  // offset: 0x8a58
    bool mIsReceiveMail;  // offset: 0x8a78
    bool mEnableUpdateSysMail;  // offset: 0x8a79
    f32 mEnableUpdateSysMailTimer;  // offset: 0x8a7c
    MailInfoVec mMailList;  // offset: 0x8a80
    MailInfoVec mAddMailList;  // offset: 0x8aa0
    MailInfoVec mSysMailList;  // offset: 0x8ac0
    MailInfoVec mAddSysMailList;  // offset: 0x8ae0
    CMailAttachmentList mGetAttachmentList;  // offset: 0x8b00
    CMailAttachmentList mUnGetAttachmentList;  // offset: 0x8b88
    CharacterListElementVec mGroupChatMemberList;  // offset: 0x8c10
    bool mGroupChatUpdate;  // offset: 0x8c30
    CharacterListElementVec mRecentList;  // offset: 0x8c38
    bool mRecentListStatusUpdate;  // offset: 0x8c58
    CommunityCharacterBaseInfoVec mBlackList;  // offset: 0x8c60
    bool mActiveListUpdate;  // offset: 0x8c80
    bool mResultReqGetCaplinkAchieveReward;  // offset: 0x8c81
    u64 mNgWordVesionNo;  // offset: 0x8c88
    bool mIsSentClientTimeoutNotice;  // offset: 0x8c90
    MtCriticalSection mCS;  // offset: 0x8c98
    MtCriticalSection mCSCheat;  // offset: 0x8ca0
    MtNetTime::Total mLastSendPingTime;  // offset: 0x8ca8
    MtNetTime::Total mAverageRTT;  // offset: 0x8cb0
    MtNetTime::Total mMaxRTT;  // offset: 0x8cb8
    f32 mConnectTimer;  // offset: 0x8cc0
    bool mIsResetInstanceArea;  // offset: 0x8cc4
    stCheatInfo mReportCheatQueue[10];  // offset: 0x8cc8
    u32 mReportCheatQueueIndex;  // offset: 0x8d90
public:
    static MyDTI DTI;
private:
    static const u32 CLAN_DIRECT_INVITED_MAX = 20;
public:
    static const u32 MAIL_LIST_MAX = 100;
    static const u32 SEND_MAIL_BODY_LENGTH = 256;
    static const u32 SEND_MAIL_TO_LIST_MAX = 10;
    static const u32 MAX_REPORT_CHEAT_QUEUE_NUM = 10;
};

// Inline, no code of its own: checked where it is inlined.
inline cCompleteQuest::cCompleteQuest() {
    this->m_unScheduleId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cEditSalonInfo::cEditSalonInfo() {
    this->mEditPrice = static_cast<s32>(5);
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cNetGameServer::getCharacterId() {
    return this->mLobbyCharacterId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cNetGameServer::getInviteLeaderCharacterId() {
    return this->mInviteLeaderCharacterId;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 cNetGameServer::getSelfIndex() {
    return this->mSelfMemberIndex;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline nNet::QUICK_MATCH_TYPE cNetGameServer::getLastQuickType() {
    return this->mQuickPartyType;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cNetGameServer::getGatheringItemListGroupId() {
    return this->mRecvGatheringItemListGroupId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cNetGameServer::getGatheringItemListLayerNo() {
    return this->mRecvGatheringItemListLayerNo;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cNetGameServer::getGatheringItemListPosId() {
    return this->mRecvGatheringItemListPosId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cNetGameServer::getRecvGetCAP() {
    return this->mRecvGetCAP;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cNetGameServer::getRecvGPShopCanBuyPawn() {
    return this->mIsGPShopCanBuyPawn;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cNetGameServer::getRecvGPShopCanBuyPawnVoice() {
    return this->mIsGPShopCanBuyPawnVoice;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cNetGameServer::isResetInstanceArea() {
    return this->mIsResetInstanceArea;
}

// Inline, no code of its own: checked where it is inlined.
inline cPawnVoiceData::cPawnVoiceData() {
    this->mIsPitchChange = false;
    this->mIsValid = false;
    this->mIsGp = false;
    this->mVoiceType = static_cast<u32>(0);
    this->mVoiceID = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline bool cSeedGameSvConnection::isLoginSuccess() const {
    return this->mGuardData.mIsLoginSuccess;
}
