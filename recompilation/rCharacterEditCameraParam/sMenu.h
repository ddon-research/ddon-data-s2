#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "cMenuBase.h"
#include "cMenuBaseClan.h"
#include "cMenuEntryBoard.h"
#include "../shared/cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cMenuActiveList;
class cMenuApplyClan;
class cMenuApplyFriend;
class cMenuApproveClan;
class cMenuApproveFriend;
class cMenuApproveInvitedClan;
class cMenuAreaMaster;
class cMenuAreaMasterHistory;
class cMenuAreaMasterQuestInfo;
class cMenuAreaMasterRankUp;
class cMenuAreaMasterSpotInfo;
class cMenuAreaMasterSupplies;
class cMenuBaggageMenu;
class cMenuBase;
class cMenuBazaarBuy;
class cMenuBazaarMenu;
class cMenuBlackList;
class cMenuBreakupParty;
class cMenuCancelApplyClan;
class cMenuCancelClanScoutEntry;
class cMenuCancelFriend;
class cMenuCancelInviteClan;
class cMenuChangeServer;
class cMenuCharacterList;
class cMenuClanApplyList;
class cMenuClanApplyManager;
class cMenuClanApproveDirectInvite;
class cMenuClanAuthority;
class cMenuClanChangeMaster;
class cMenuClanDirectInvite;
class cMenuClanDirectInvitedList;
class cMenuClanExpelMember;
class cMenuClanHistory;
class cMenuClanInfoDisp;
class cMenuClanInfoManager;
class cMenuClanInviteList;
class cMenuClanInvitedList;
class cMenuClanJoinReqList;
class cMenuClanList;
class cMenuClanMemberList;
class cMenuClanScoutEntry;
class cMenuClanScoutEntryList;
class cMenuClanSetMemberRank;
class cMenuContentsExecutor;
class cMenuCraftColorFrame;
class cMenuCraftColorItem;
class cMenuCraftCreateItem;
class cMenuCraftElementFrame;
class cMenuCraftElementItem;
class cMenuCraftGoldStoneDialog;
class cMenuCraftItemSelect;
class cMenuCraftMenu;
class cMenuCraftMyPawnList;
class cMenuCraftPoint;
class cMenuCraftProcessMenu;
class cMenuCraftRecipeList;
class cMenuCraftSupportFrame;
class cMenuCraftSupportList;
class cMenuCraftTask;
class cMenuCraftUpGradeItem;
class cMenuCraftUpGradeList;
class cMenuCreateClan;
class cMenuCreateEntryBoardItem;
class cMenuCreateGameSession;
class cMenuCustomize;
class cMenuDispStatus;
class cMenuEditBlackList;
class cMenuEditClan;
class cMenuEditClanComment;
class cMenuEditClanDay;
class cMenuEditClanEmblem;
class cMenuEditClanEntryComment;
class cMenuEditClanFeature;
class cMenuEditClanHour;
class cMenuEditClanMessage;
class cMenuEditClanMotto;
class cMenuEditCommentEntryBoardItem;
class cMenuEditFavoritePawn;
class cMenuEntryBoardInvite;
class cMenuEntryBoardItem;
class cMenuEntryBoardItemList;
class cMenuEntryBoardMember;
class cMenuEntryBoardRecruit;
class cMenuEntryGameSession;
class cMenuExtendEntryBoardItem;
class cMenuFavoriteFriend;
class cMenuFirstOption;
class cMenuFriendList;
class cMenuGetAreaMasterInfo;
class cMenuGetBlackList;
class cMenuGetCharacterName;
class cMenuGetClanBaseInfo;
class cMenuGetClanDetail;
class cMenuGetCraftRecipeToServer;
class cMenuGetEntryBoardItem;
class cMenuGetFriendList;
class cMenuGetItemBaggageListToServer;
class cMenuGetItemListToServer;
class cMenuGetMailList;
class cMenuGetMatchingProfile;
class cMenuGetMyClan;
class cMenuGetMyScoutEntry;
class cMenuGetOrbGainExtendParam;
class cMenuGetPawnName;
class cMenuGetRecentList;
class cMenuGroupChatMemberList;
class cMenuInvite;
class cMenuInviteClan;
class cMenuInviteEntryBoardItem;
class cMenuInviteGroupChat;
class cMenuJoinEntryBoardItem;
class cMenuJoinGameSession;
class cMenuJoinPartyFlow;
class cMenuKeyConfig;
class cMenuKeyConfigCopyCategory;
class cMenuKeyConfigRenameCategory;
class cMenuKeyConfigSubMenuCategoryList;
class cMenuKeyConfigSubMenuKeyList;
class cMenuKeyJobLink;
class cMenuKickGroupChat;
class cMenuLeaveEntryBoardItem;
class cMenuLeaveGroupChat;
class cMenuLeaveOnTheWay;
class cMenuLostPawnList;
class cMenuLostPawnRevive;
class cMenuMail;
class cMenuMailCreate;
class cMenuMailDelete;
class cMenuMailDeleteMulti;
class cMenuMailDetail;
class cMenuMailGetItem;
class cMenuMailGetItemAll;
class cMenuMailToList;
class cMenuMatchingProfile;
class cMenuMyPawnList;
class cMenuOnlineShop;
class cMenuPartyList;
class cMenuPartyListMemberInfo;
class cMenuPartyManager;
class cMenuPartyMemberList;
class cMenuPartyReq;
class cMenuPawnDelete;
class cMenuPawnFeedback;
class cMenuPawnHistory;
class cMenuPawnManageMenu;
class cMenuPawnManager;
class cMenuPawnPoint;
class cMenuPawnRental;
class cMenuPawnReqList;
class cMenuPawnReqMenu;
class cMenuPawnReturn;
class cMenuPawnRevive;
class cMenuPawnSearch;
class cMenuPawnSetPartner;
class cMenuPawnShareRange;
class cMenuPlDeadMenu;
class cMenuQuickMatch;
class cMenuQuickMatchCancel;
class cMenuQuickMatchRetry;
class cMenuQuickMatchSelect;
class cMenuQuitClan;
class cMenuReadyCheck;
class cMenuReadyEntryBoardItem;
class cMenuRecentList;
class cMenuRecreateEntryBoardItem;
class cMenuReleasePassEntryBoardItem;
class cMenuRemoveFriend;
class cMenuRentalPawnList;
class cMenuResetCraftPoint;
class cMenuSearchFilter;
class cMenuServerList;
class cMenuSetClanName;
class cMenuSetClanNickName;
class cMenuSetJob;
class cMenuSetLevel;
class cMenuSetLimitPreset;
class cMenuSimplePartyReq;
class cMenuStartEntryBoardItem;
class cMenuStartGameSession;
class cMenuSubMenu;
class cMenuTraining;
class cMenuTreasuresLot;
class cMenuTreasuresLotAnnounce;
class cMenuUILargeSetting;
class cMenuUpdateCommunityList;
namespace nMenu { struct MENU_PARTS; }

// Declarations
class sMenu;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class sMenu : public cSystem
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
    sMenu();
    virtual ~sMenu();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    static sMenu* getInstance();
    bool isMaskMenu(const nMenu::MENU_PARTS* pParts, u32 index);
    bool isMaskMenu(const nMenu::MENU_PARTS& Parts);
    bool checkMask(u32 attr);
    bool isCreateFlow();
    bool isJoinFlow();
    bool isReadyWait();
    bool isChangeServer();
    void entryMenu(cMenuBase* pMenu);
    void eraseMenu(cMenuBase* pMenu);
    void updateMenu(cMenuBase* pMenu);
    bool checkMoveMenu(cMenuBase* pMenu, bool checkNowMove);
    cMenuMatchingProfile* getMenuMatchingProfile();
    cMenuGetMatchingProfile* getMenuGetMatchingProfile();
    cMenuPartyManager* getMenuPartyManager();
    cMenuPartyMemberList* getMenuPartyMemberList();
    cMenuSearchFilter* getMenuSearchFilter();
    cMenuSimplePartyReq* getMenuSimplePartyReq();
    cMenuPartyReq* getMenuPartyReq();
    cMenuPartyList* getMenuPartyList();
    cMenuPartyListMemberInfo* getMenuPartyListMemberInfo();
    cMenuCharacterList* getMenuCharacterList();
    cMenuQuickMatchSelect* getMenuQuickMatchSelect();
    cMenuQuickMatch* getMenuQuickMatch();
    cMenuQuickMatchRetry* getMenuQuickMatchRetry();
    cMenuQuickMatchCancel* getMenuQuickMatchCancel();
    cMenuPawnReqMenu* getMenuPawnReqMenu();
    cMenuPawnReqList* getMenuPawnReqList();
    cMenuMyPawnList* getMenuMyPawnList();
    cMenuRentalPawnList* getMenuRentalPawnList();
    cMenuPawnSearch* getMenuPawnSearch();
    cMenuLostPawnList* getMenuLostPawnList();
    cMenuLostPawnRevive* getMenuLostPawnRevive();
    cMenuPawnManageMenu* getMenuPawnManageMenu();
    cMenuPawnManager* getMenuPawnManager();
    cMenuPawnReturn* getMenuPawnReturn();
    cMenuPawnDelete* getMenuPawnDelete();
    cMenuPawnFeedback* getMenuPawnFeedback();
    cMenuPawnHistory* getMenuPawnHistory();
    cMenuPawnShareRange* getMenuPawnShareRange();
    cMenuEditFavoritePawn* getMenuEditFavoritePawn();
    cMenuPawnRental* getMenuPawnRental();
    cMenuCreateGameSession* getMenuCreateGameSession();
    cMenuJoinGameSession* getMenuJoinGameSession();
    cMenuEntryGameSession* getMenuEntryGameSession();
    cMenuStartGameSession* getMenuStartGameSession();
    cMenuJoinPartyFlow* getMenuJoinPartyFlow();
    cMenuBreakupParty* getMenuBreakupParty();
    cMenuPlDeadMenu* getMenuPlDeadMenu();
    cMenuPawnRevive* getMenuPawnRevive();
    cMenuCustomize* getMenuCustomize();
    cMenuPawnPoint* getMenuPawnPoint();
    cMenuCraftMenu* getMenuCraftMenu();
    cMenuCraftProcessMenu* getMenuCraftProcessMenu();
    cMenuCraftMyPawnList* getMenuCraftMyPawnList();
    cMenuCraftRecipeList* getMenuCraftRecipeList();
    cMenuCraftUpGradeList* getMenuCraftUpGradeList();
    cMenuCraftSupportFrame* getMenuCraftSupportFrame();
    cMenuCraftSupportList* getMenuCraftSupportList();
    cMenuCraftCreateItem* getMenuCraftCreateItem();
    cMenuCraftUpGradeItem* getMenuCraftUpGradeItem();
    cMenuCraftElementFrame* getMenuCraftElementList();
    cMenuCraftElementItem* getMenuCraftElementItem();
    cMenuCraftColorFrame* getMenuCraftColorList();
    cMenuCraftColorItem* getMenuCraftColorItem();
    cMenuCraftPoint* getMenuCraftPoint();
    cMenuCraftTask* getMenuCraftTask();
    cMenuCraftItemSelect* getMenuCraftItemSelect();
    cMenuSubMenu* getMenuSubMenu();
    cMenuInvite* getMenuInvite();
    cMenuClanApplyManager* getMenuClanApplyManager();
    cMenuClanInfoManager* getMenuClanInfoManager();
    cMenuCreateClan* getMenuCreateClan();
    cMenuSetClanName* getMenuSetClanName();
    cMenuSetClanNickName* getMenuSetClanNickName();
    cMenuEditClanEmblem* getMenuEditClanEmblem();
    cMenuEditClanMotto* getMenuEditClanMotto();
    cMenuEditClanDay* getMenuEditClanDay();
    cMenuEditClanHour* getMenuEditClanHour();
    cMenuEditClanFeature* getMenuEditClanFeature();
    cMenuEditClanComment* getMenuEditClanComment();
    cMenuEditClanMessage* getMenuEditClanMessage();
    cMenuEditClan* getMenuEditClan();
    cMenuClanInfoDisp* getMenuClanInfoDisp();
    cMenuClanList* getMenuClanList();
    cMenuClanApplyList* getMenuClanApplyList();
    cMenuApplyClan* getMenuApplyClan();
    cMenuCancelApplyClan* getMenuCancelApplyClan();
    cMenuClanJoinReqList* getMenuClanJoinReqList();
    cMenuApproveClan* getMenuApproveClan();
    cMenuGetMyClan* getMenuGetMyClan();
    cMenuGetClanDetail* getMenuGetClanDetail();
    cMenuGetClanBaseInfo* getMenuGetClanBaseInfo();
    cMenuClanMemberList* getMenuClanMemberList();
    cMenuClanHistory* getMenuClanHistory();
    cMenuQuitClan* getMenuQuitClan();
    cMenuClanExpelMember* getMenuClanExpelMember();
    cMenuClanChangeMaster* getMenuClanChangeMaster();
    cMenuClanSetMemberRank* getMenuClanSetMemberRank();
    cMenuClanScoutEntry* getMenuClanScoutEntry();
    cMenuCancelClanScoutEntry* getMenuCancelClanScoutEntry();
    cMenuEditClanEntryComment* getMenuEditClanEntryComment();
    cMenuClanScoutEntryList* getMenuClanScoutEntryList();
    cMenuGetMyScoutEntry* getMenuGetMyScoutEntry();
    cMenuInviteClan* getMenuInviteClan();
    cMenuCancelInviteClan* getMenuCancelInviteClan();
    cMenuClanInvitedList* getMenuClanInvitedList();
    cMenuApproveInvitedClan* getMenuApproveInvitedClan();
    cMenuClanInviteList* getMenuClanInviteList();
    cMenuClanDirectInvitedList* getMenuClanDirectInvitedList();
    cMenuClanDirectInvite* getMenuClanDirectInvite();
    cMenuClanApproveDirectInvite* getMenuClanApproveDirectInvite();
    cMenuClanAuthority* getMenuClanAuthority();
    cMenuGetFriendList* getMenuGetFriendList();
    cMenuFriendList* getMenuFriendList();
    cMenuApplyFriend* getMenuApplyFriend();
    cMenuCancelFriend* getMenuCancelFriend();
    cMenuApproveFriend* getMenuApproveFriend();
    cMenuRemoveFriend* getMenuRemoveFriend();
    cMenuFavoriteFriend* getMenuFavoriteFriend();
    cMenuEntryBoardItem* getMenuEntryBoardItem();
    cMenuCreateEntryBoardItem* getMenuCreateEntryBoardItem();
    cMenuGetEntryBoardItem* getMenuGetEntryBoardItem();
    cMenuJoinEntryBoardItem* getMenuJoinEntryBoardItem();
    cMenuLeaveEntryBoardItem* getMenuLeaveEntryBoardItem();
    cMenuReadyEntryBoardItem* getMenuReadyEntryBoardItem();
    cMenuStartEntryBoardItem* getMenuStartEntryBoardItem();
    cMenuExtendEntryBoardItem* getMenuExtendEntryBoardItem();
    cMenuRecreateEntryBoardItem* getMenuRecreateEntryBoardItem();
    cMenuReleasePassEntryBoardItem* getMenuReleasePassEntryBoardItem();
    cMenuEditCommentEntryBoardItem* getMenuEditCommentEntryBoardItem();
    cMenuEntryBoardItemList* getMenuEntryBoardItemList();
    cMenuSetLevel* getMenuSetLevel();
    cMenuSetLimitPreset* getMenuSetLimitPreset();
    cMenuSetJob* getMenuSetJob();
    cMenuGetCharacterName* getMenuGetCharacterName();
    cMenuGetPawnName* getMenuGetPawnName();
    cMenuEntryBoardRecruit* getMenuEntryBoardRecruit();
    cMenuEntryBoardMember* getMenuEntryBoardMember();
    cMenuEntryBoardInvite* getMenuEntryBoardInvite();
    cMenuContentsExecutor* getMenuContentsExecutor();
    cMenuInviteEntryBoardItem* getMenuInviteEntryBoardItem();
    cMenuAreaMaster* getMenuAreaMaster();
    cMenuAreaMasterRankUp* getMenuAreaMasterRankUp();
    cMenuAreaMasterQuestInfo* getMenuAreaMasterQuestInfo();
    cMenuAreaMasterSpotInfo* getMenuAreaMasterSpotInfo();
    cMenuAreaMasterHistory* getMenuAreaMasterHistory();
    cMenuAreaMasterSupplies* getMenuAreaMasterSupplies();
    cMenuGetAreaMasterInfo* getMenuGetAreaMasterInfo();
    cMenuServerList* getMenuServerList();
    cMenuUpdateCommunityList* getMenuUpdateCommunityList();
    cMenuChangeServer* getMenuChangeServer();
    cMenuReadyCheck* getMenuReadyCheck();
    cMenuMail* getMenuMail();
    cMenuGetMailList* getMenuGetMailList();
    cMenuMailDetail* getMenuMailDetail();
    cMenuMailCreate* getMenuMailCreate();
    cMenuMailToList* getMenuMailToList();
    cMenuMailDelete* getMenuMailDelete();
    cMenuMailDeleteMulti* getMenuMailDeleteMulti();
    cMenuMailGetItem* getMenuMailGetItem();
    cMenuMailGetItemAll* getMenuMailGetItemAll();
    cMenuDispStatus* getMenuDispStatus();
    cMenuGetItemListToServer* getMenuGetItemListToServer();
    cMenuGetOrbGainExtendParam* getMenuGetOrbGainExtendParam();
    cMenuActiveList* getMenuActiveList();
    cMenuGetRecentList* getMenuGetRecentList();
    cMenuRecentList* getMenuRecentList();
    cMenuGetBlackList* getMenuGetBlackList();
    cMenuBlackList* getMenuBlackList();
    cMenuEditBlackList* getMenuEditBlackList();
    cMenuInviteGroupChat* getMenuInviteGroupChat();
    cMenuLeaveGroupChat* getMenuLeaveGroupChat();
    cMenuKickGroupChat* getMenuKickGroupChat();
    cMenuGroupChatMemberList* getMenuGroupChatMemberList();
    cMenuLeaveOnTheWay* getMenuLeaveOnTheWay();
    cMenuBazaarMenu* getMenuBazaarMenu();
    cMenuBazaarBuy* getMenuBazaarBuy();
    cMenuUILargeSetting* getMenuUILargeSetting();
    cMenuFirstOption* getMenuFirstOption();
    cMenuResetCraftPoint* getMenuResetCraftPoint();
    cMenuGetCraftRecipeToServer* getGetCraftRecipeToServer();
    cMenuPawnSetPartner* getMenuPawnSetPartner();
    cMenuGetItemBaggageListToServer* getMenuGetItemBaggageListToServer();
    cMenuBaggageMenu* getMenuBaggageMenu();
    cMenuTreasuresLot* getMenuTreasuresLot();
    cMenuTreasuresLotAnnounce* getMenuTreasuresLotAnnounce();
    cMenuCraftGoldStoneDialog* getMenuCraftGoldStoneDialog();
    cMenuOnlineShop* getMenuOnlineShop();
    cMenuTraining* getMenuTraining();
    cMenuKeyConfig* getMenuKeyConfig();
    cMenuKeyConfigSubMenuKeyList* getMenuKeyConfigSubMenuKeyList();
    cMenuKeyConfigSubMenuCategoryList* getMenuKeyConfigSubMenuCategoryList();
    cMenuKeyConfigRenameCategory* getMenuKeyConfigRenameCategory();
    cMenuKeyConfigCopyCategory* getMenuKeyConfigCopyCategory();
    cMenuKeyJobLink* getMenuKeyJobLink();
private:
    cMenuMatchingProfile mMatchingProfile;  // offset: 0x18
    cMenuGetMatchingProfile mGetMatchingProfile;  // offset: 0x200
    cMenuPartyManager mPartyManager;  // offset: 0x2d0
    cMenuPartyMemberList mPartyMemberList;  // offset: 0x388
    cMenuSearchFilter mSearchFilter;  // offset: 0x450
    cMenuSimplePartyReq mSimplePartyReq;  // offset: 0x558
    cMenuPartyReq mPartyReq;  // offset: 0x610
    cMenuPartyList mPartyList;  // offset: 0x6e8
    cMenuPartyListMemberInfo mPartyListMemberInfo;  // offset: 0x8c8
    cMenuCharacterList mCharacterList;  // offset: 0x980
    cMenuQuickMatchSelect mQuickMatchSelect;  // offset: 0xb60
    cMenuQuickMatch mQuickMatch;  // offset: 0xc28
    cMenuQuickMatchRetry mQuickMatchRetry;  // offset: 0xcf0
    cMenuQuickMatchCancel mQuickMatchCancel;  // offset: 0xda0
    cMenuPawnReqMenu mPawnReqMenu;  // offset: 0xe50
    cMenuPawnReqList mPawnReqList;  // offset: 0xf00
    cMenuMyPawnList mMyPawnList;  // offset: 0xfc0
    cMenuRentalPawnList mRentalPawnList;  // offset: 0x10d0
    cMenuPawnSearch mPawnSearch;  // offset: 0x11e0
    cMenuLostPawnList mLostPawnList;  // offset: 0x1568
    cMenuLostPawnRevive mLostPawnRevive;  // offset: 0x1620
    cMenuPawnManageMenu mPawnManageMenu;  // offset: 0x16e0
    cMenuPawnManager mPawnManager;  // offset: 0x1790
    cMenuPawnReturn mPawnReturn;  // offset: 0x1848
    cMenuPawnDelete mPawnDelete;  // offset: 0x1918
    cMenuPawnFeedback mPawnFeedback;  // offset: 0x19d8
    cMenuPawnHistory mPawnHistory;  // offset: 0x1aa0
    cMenuPawnShareRange mPawnShareRange;  // offset: 0x1b58
    cMenuEditFavoritePawn mMenuEditFavoritePawn;  // offset: 0x1c10
    cMenuPawnRental mPawnRental;  // offset: 0x1cd0
    cMenuCreateGameSession mCreateGameSession;  // offset: 0x1d90
    cMenuJoinGameSession mJoinGameSession;  // offset: 0x1e48
    cMenuEntryGameSession mEntryGameSession;  // offset: 0x1f00
    cMenuStartGameSession mStartGameSession;  // offset: 0x1fb8
    cMenuJoinPartyFlow mJoinPartyFlow;  // offset: 0x2070
    cMenuBreakupParty mBreakupParty;  // offset: 0x2120
    cMenuPlDeadMenu mPlDeadMenu;  // offset: 0x21d0
    cMenuPawnRevive mPawnRevive;  // offset: 0x2280
    cMenuCustomize mMenuCustomize;  // offset: 0x2368
    cMenuPawnPoint mMenuPawnPoint;  // offset: 0x3d88
    cMenuCraftMenu mMenuCraftMenu;  // offset: 0x3e60
    cMenuCraftProcessMenu mMenuCraftProcessMenu;  // offset: 0x3f28
    cMenuCraftMyPawnList mMenuCraftMyPawnList;  // offset: 0x3fe0
    cMenuCraftRecipeList mMenuCraftRecipeList;  // offset: 0x4098
    cMenuCraftUpGradeList mMenuCraftUpGradeList;  // offset: 0x4150
    cMenuCraftSupportFrame mMenuCraftSupportFrame;  // offset: 0x4208
    cMenuCraftSupportList mMenuCraftSupportList;  // offset: 0x4320
    cMenuCraftCreateItem mMenuCraftCreateItem;  // offset: 0x43d8
    cMenuCraftUpGradeItem mMenuCraftUpGradeItem;  // offset: 0x4498
    cMenuCraftElementFrame mMenuCraftElementList;  // offset: 0x4550
    cMenuCraftElementItem mMenuCraftElementItem;  // offset: 0x4660
    cMenuCraftColorFrame mMenuCraftColorList;  // offset: 0x4720
    cMenuCraftColorItem mMenuCraftColorItem;  // offset: 0x4800
    cMenuCraftPoint mMenuCraftPoint;  // offset: 0x48b8
    cMenuCraftTask mMenuCraftTask;  // offset: 0x4988
    cMenuCraftItemSelect mMenuCraftItemSelect;  // offset: 0x4a48
    cMenuSubMenu mMenuSubMenu;  // offset: 0x4b08
    cMenuInvite mMenuInvite;  // offset: 0x4d40
    cMenuClanApplyManager mClanApplyManager;  // offset: 0x4e20
    cMenuClanInfoManager mClanInfoManager;  // offset: 0x4ed8
    cMenuCreateClan mMenuCreateClan;  // offset: 0x4f98
    cMenuSetClanName mMenuSetClanName;  // offset: 0x5150
    cMenuSetClanNickName mMenuSetClanNickName;  // offset: 0x5220
    cMenuEditClanEmblem mMenuEditClanEmblem;  // offset: 0x52e0
    cMenuEditClanMotto mMenuEditClanMotto;  // offset: 0x53a0
    cMenuEditClanDay mMenuEditClanDay;  // offset: 0x5460
    cMenuEditClanHour mMenuEditClanHour;  // offset: 0x5520
    cMenuEditClanFeature mMenuEditClanFeature;  // offset: 0x55e0
    cMenuEditClanComment mMenuEditClanComment;  // offset: 0x56a0
    cMenuEditClanMessage mMenuEditClanMessage;  // offset: 0x5838
    cMenuEditClan mMenuEditClan;  // offset: 0x59d0
    cMenuClanInfoDisp mMenuClanInfoDisp;  // offset: 0x5c78
    cMenuClanList mMenuClanList;  // offset: 0x5d30
    cMenuClanApplyList mMenuClanApplyList;  // offset: 0x5f10
    cMenuApplyClan mMenuApplyClan;  // offset: 0x5fc0
    cMenuCancelApplyClan mMenuCancelApplyClan;  // offset: 0x6080
    cMenuClanJoinReqList mMenuClanJoinReqList;  // offset: 0x6140
    cMenuApproveClan mMenuApproveClan;  // offset: 0x61f8
    cMenuGetMyClan mMenuGetMyClan;  // offset: 0x62c0
    cMenuGetClanDetail mMenuGetClanDetail;  // offset: 0x6370
    cMenuGetClanBaseInfo mMenuGetClanBaseInfo;  // offset: 0x6438
    cMenuClanMemberList mMenuClanMemberList;  // offset: 0x64e8
    cMenuClanHistory mMenuClanHistory;  // offset: 0x65c8
    cMenuQuitClan mMenuQuitClan;  // offset: 0x6678
    cMenuClanExpelMember mMenuClanExpelMember;  // offset: 0x6728
    cMenuClanChangeMaster mMenuClanChangeMaster;  // offset: 0x67f0
    cMenuClanSetMemberRank mMenuClanSetMemberRank;  // offset: 0x68b8
    cMenuClanScoutEntry mMenuClanScoutEntry;  // offset: 0x6980
    cMenuCancelClanScoutEntry mMenuCancelClanScoutEntry;  // offset: 0x6a58
    cMenuEditClanEntryComment mMenuEditClanEntryComment;  // offset: 0x6b08
    cMenuClanScoutEntryList mMenuClanScoutEntryList;  // offset: 0x6c08
    cMenuGetMyScoutEntry mMenuGetMyScoutEntry;  // offset: 0x6cb8
    cMenuInviteClan mMenuInviteClan;  // offset: 0x6d68
    cMenuCancelInviteClan mMenuCancelInviteClan;  // offset: 0x6e30
    cMenuClanInvitedList mMenuClanInvitedList;  // offset: 0x6ee8
    cMenuApproveInvitedClan mMenuApproveInvitedClan;  // offset: 0x6f98
    cMenuClanInviteList mMenuClanInviteList;  // offset: 0x7058
    cMenuClanDirectInvitedList mMenuClanDirectInvitedList;  // offset: 0x7108
    cMenuClanDirectInvite mMenuClanDirectInvite;  // offset: 0x71b8
    cMenuClanApproveDirectInvite mMenuClanApproveDirectInvite;  // offset: 0x7280
    cMenuClanAuthority mMenuClanAuthority;  // offset: 0x7340
    cMenuGetFriendList mMenuGetFriendList;  // offset: 0x7418
    cMenuFriendList mMenuFriendList;  // offset: 0x74c8
    cMenuApplyFriend mMenuApplyFriend;  // offset: 0x75a8
    cMenuCancelFriend mMenuCancelFriend;  // offset: 0x7670
    cMenuApproveFriend mMenuApproveFriend;  // offset: 0x7730
    cMenuRemoveFriend mMenuRemoveFriend;  // offset: 0x77f8
    cMenuFavoriteFriend mMenuFavoriteFriend;  // offset: 0x78c0
    cMenuEntryBoardItem mMenuEntryBoardItem;  // offset: 0x7990
    cMenuCreateEntryBoardItem mMenuCreateEntryBoardItem;  // offset: 0x7aa0
    cMenuGetEntryBoardItem mMenuGetEntryBoardItem;  // offset: 0x7c40
    cMenuJoinEntryBoardItem mMenuJoinEntryBoardItem;  // offset: 0x7d08
    cMenuLeaveEntryBoardItem mMenuLeaveEntryBoardItem;  // offset: 0x7dd8
    cMenuReadyEntryBoardItem mMenuReadyEntryBoardItem;  // offset: 0x7e90
    cMenuStartEntryBoardItem mMenuStartEntryBoardItem;  // offset: 0x7f40
    cMenuExtendEntryBoardItem mMenuExtendEntryBoardItem;  // offset: 0x7ff0
    cMenuRecreateEntryBoardItem mMenuRecreateEntryBoardItem;  // offset: 0x80a0
    cMenuReleasePassEntryBoardItem mMenuReleasePassEntryBoardItem;  // offset: 0x8150
    cMenuEditCommentEntryBoardItem mMenuEditCommentEntryBoardItem;  // offset: 0x8200
    cMenuEntryBoardItemList mMenuEntryBoardItemList;  // offset: 0x82c0
    cMenuSetLevel mMenuSetLevel;  // offset: 0x85c0
    cMenuSetLimitPreset mMenuSetLimitPreset;  // offset: 0x86b8
    cMenuSetJob mMenuSetJob;  // offset: 0x87b0
    cMenuGetCharacterName mMenuGetCharacterName;  // offset: 0x8890
    cMenuGetPawnName mMenuGetPawnName;  // offset: 0x8968
    cMenuEntryBoardRecruit mMenuEntryBoardRecruit;  // offset: 0x8a30
    cMenuEntryBoardMember mMenuEntryBoardMember;  // offset: 0x8b18
    cMenuEntryBoardInvite mMenuEntryBoardInvite;  // offset: 0x8c10
    cMenuContentsExecutor mMenuContentsExecutor;  // offset: 0x8ce0
    cMenuInviteEntryBoardItem mMenuInviteEntryBoardItem;  // offset: 0x8da8
    cMenuAreaMaster mMenuAreaMaster;  // offset: 0x8e70
    cMenuAreaMasterRankUp mMenuAreaMasterRankUp;  // offset: 0x8f30
    cMenuAreaMasterQuestInfo mMenuAreaMasterQuestInfo;  // offset: 0x8ff0
    cMenuAreaMasterSpotInfo mMenuAreaMasterSpotInfo;  // offset: 0x90a0
    cMenuAreaMasterHistory mMenuAreaMasterHistory;  // offset: 0x9150
    cMenuAreaMasterSupplies mMenuAreaMasterSupplies;  // offset: 0x9200
    cMenuGetAreaMasterInfo mMenuGetAreaMasterInfo;  // offset: 0x92b0
    cMenuServerList mMenuServerList;  // offset: 0x9378
    cMenuUpdateCommunityList mMenuUpdateCommunityList;  // offset: 0x9c38
    cMenuChangeServer mMenuChangeServer;  // offset: 0x9cf0
    cMenuReadyCheck mReadyCheck;  // offset: 0x9da8
    cMenuMail mMenuMail;  // offset: 0x9e88
    cMenuGetMailList mMenuGetMailList;  // offset: 0xb220
    cMenuMailDetail mMenuMailDetail;  // offset: 0xb2d8
    cMenuMailCreate mMenuMailCreate;  // offset: 0xb3b8
    cMenuMailToList mMenuMailToList;  // offset: 0xb4f8
    cMenuMailDelete mMenuMailDelete;  // offset: 0xb5f8
    cMenuMailDeleteMulti mMenuMailDeleteMulti;  // offset: 0xb6b8
    cMenuMailGetItem mMenuMailGetItem;  // offset: 0xb780
    cMenuMailGetItemAll mMenuMailGetItemAll;  // offset: 0xb838
    cMenuDispStatus mMenuDispStatus;  // offset: 0xb900
    cMenuGetItemListToServer mMenuGetItemListToServer;  // offset: 0x12ec0
    cMenuGetOrbGainExtendParam mMenuGetOrbGainExtendParam;  // offset: 0x12fa0
    cMenuActiveList mMenuActiveList;  // offset: 0x13050
    cMenuGetRecentList mMenuGetRecentList;  // offset: 0x13148
    cMenuRecentList mMenuRecentList;  // offset: 0x131f8
    cMenuGetBlackList mMenuGetBlackList;  // offset: 0x132b8
    cMenuBlackList mMenuBlackList;  // offset: 0x13368
    cMenuEditBlackList mMenuEditBlackList;  // offset: 0x13418
    cMenuInviteGroupChat mMenuInviteGroupChat;  // offset: 0x13500
    cMenuLeaveGroupChat mMenuLeaveGroupChat;  // offset: 0x135c8
    cMenuKickGroupChat mMenuKickGroupChat;  // offset: 0x13678
    cMenuGroupChatMemberList mMenuGroupChatMemberList;  // offset: 0x13740
    cMenuLeaveOnTheWay mMenuLeaveOnTheWay;  // offset: 0x13918
    cMenuBazaarMenu mMenuBazaarMenu;  // offset: 0x139c8
    cMenuBazaarBuy mMenuBazaarBuy;  // offset: 0x13a78
    cMenuUILargeSetting mMenuUILargeSetting;  // offset: 0x13b28
    cMenuFirstOption mMenuFirstOption;  // offset: 0x13be0
    cMenuResetCraftPoint mMenuResetCraftPoint;  // offset: 0x13c90
    cMenuGetCraftRecipeToServer mMenuGetCraftRecipeToServer;  // offset: 0x13d48
    cMenuPawnSetPartner mMenuPawnSetPartner;  // offset: 0x13e68
    cMenuGetItemBaggageListToServer mMenuGetItemBaggageListToServer;  // offset: 0x13f28
    cMenuBaggageMenu mMenuBaggageMenu;  // offset: 0x14008
    cMenuTreasuresLot mMenuTreasuresLot;  // offset: 0x140d0
    cMenuTreasuresLotAnnounce mMenuTreasuresLotAnnounce;  // offset: 0x141b0
    cMenuCraftGoldStoneDialog mMenuCraftGoldStonetDialog;  // offset: 0x14260
    cMenuOnlineShop mMenuOnlineShop;  // offset: 0x14320
    cMenuTraining mMenuTraining;  // offset: 0x143d8
    cMenuKeyConfig mMenuKeyConfig;  // offset: 0x14488
    cMenuKeyConfigSubMenuKeyList mMenuKeyConfigSubMenuKeyList;  // offset: 0x14568
    cMenuKeyConfigSubMenuCategoryList mMenuKeyConfigSubMenuCategoryList;  // offset: 0x14620
    cMenuKeyConfigRenameCategory mMenuKeyConfigRenameCategory;  // offset: 0x146d8
    cMenuKeyConfigCopyCategory mMenuKeyConfigCopyCategory;  // offset: 0x147c0
    cMenuKeyJobLink mMenuKeyJobLink;  // offset: 0x14880
    MtTypedArray<cMenuBase> mMenuArray;  // offset: 0x149a8
public:
    static const nMenu::MENU_PARTS mDefMenuParts;
    static MyDTI DTI;
private:
    static sMenu* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sMenu* sMenu::getInstance() {
    return ::sMenu::mpInstance;
}
