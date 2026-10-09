#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Clan.h"
#include "../shared/Common.h"
#include "../shared/Community.h"
#include "../shared/Craft.h"
#include "../shared/Item.h"
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/SupportPoint.h"
#include "../shared/cCharacterData.h"
#include "../shared/cContextInstance.h"
#include "cMenuSupport.h"
#include "../shared/nCharacterData.h"
#include "../shared/nGUIExt.h"
#include "nGUIKeyConfig.h"
#include "nMenu.h"
#include "nMenuKeyConfig.h"
#include "../shared/nNet.h"
#include "../shared/rItemList.h"
#include "sCraftManager.h"
#include "../shared/sItemManager.h"
#include "../shared/sPadExt.h"
#include "../shared/sUnit.h"

// Forward declarations
class CDataCharacterListElement;
class CDataClanParam;
class CDataClanScoutEntrySearchResult;
class CDataClientPartyListInfo;
class CDataCommonU32;
class CDataCommunityCharacterBaseInfo;
class CDataEntryMemberData;
class CDataGameServerListInfo;
class CDataMailInfo;
class CDataPartyMember;
class CDataUseSupportPoint;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector4;
class cArcLoaderBase;
class cCharacterData;
class cContextInstHm;
class cCursor;
class cMenuDialogFlow;
class cMenuSupport;
class cMenuSupportList;
class cMenuSupportMenu;
class cPawnListParam;
namespace nCharacterData { struct stCharacterName; }
namespace nGUIKeyConfig { struct Key; }
namespace nMenu { struct MENU_PARTS; }
namespace nMenuKeyConfig { class KeyCustomManagers; }
namespace nNet { struct stFeedbackData; }
namespace nNet { struct stPawnFeedback; }
class rSoundRequest;
class sMenu;
class uDDOModel;
class uGUIBase;
class uGUIBoughtBox;
class uGUIDialogTextBox;
class uGUIGPShop;
class uGUIGPShopDialog;
class uGUIItemBaggageEx;
class uGUIKeyConfig;
class uGUIMenuAreaInfo;
class uGUINewspaper;
class uGUIPopCmd01;
class uGUIPopFilter;
class uGUIPopTopSel;
class uGUIRankUp;
class uGUISystemMsg;
class uHuman;
class uPlayer;

// Declarations
class cMenuActiveList;
class cMenuApplyFriend;
class cMenuApproveFriend;
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
class cMenuCancelFriend;
class cMenuChangeServer;
class cMenuCharacterList;
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
class cMenuCreateGameSession;
class cMenuCustomize;
class cMenuDispStatus;
class cMenuEditBlackList;
class cMenuEditFavoritePawn;
class cMenuEntryGameSession;
class cMenuFavoriteFriend;
class cMenuFirstOption;
class cMenuFriendList;
class cMenuGetAreaMasterInfo;
class cMenuGetBlackList;
class cMenuGetCharacterName;
class cMenuGetCraftRecipeToServer;
class cMenuGetFriendList;
class cMenuGetItemBaggageListToServer;
class cMenuGetItemListToServer;
class cMenuGetMailList;
class cMenuGetMatchingProfile;
class cMenuGetOrbGainExtendParam;
class cMenuGetPawnName;
class cMenuGetRecentList;
class cMenuGroupChatMemberList;
class cMenuInvite;
class cMenuInviteGroupChat;
class cMenuJoinGameSession;
class cMenuJoinPartyFlow;
class cMenuKeyConfig;
class cMenuKeyConfigCopyCategory;
class cMenuKeyConfigRenameCategory;
class cMenuKeyConfigSubMenu;
class cMenuKeyConfigSubMenuCategoryList;
class cMenuKeyConfigSubMenuKeyList;
class cMenuKeyJobLink;
class cMenuKickGroupChat;
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
class cMenuReadyCheck;
class cMenuRecentList;
class cMenuRemoveFriend;
class cMenuRentalPawnList;
class cMenuResetCraftPoint;
class cMenuSearchFilter;
class cMenuServerList;
class cMenuSetJob;
class cMenuSetLevel;
class cMenuSetLimitPreset;
class cMenuSimplePartyReq;
class cMenuStartGameSession;
class cMenuSubMenu;
class cMenuTraining;
class cMenuTreasuresLot;
class cMenuTreasuresLotAnnounce;
class cMenuUILargeSetting;
class cMenuUpdateCommunityList;

// Type aliases from DWARF
using CCharacterListElement = CDataCharacterListElement;
using CClanParam = CDataClanParam;
using CClanScoutEntrySearchResult = CDataClanScoutEntrySearchResult;
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CEntryMemberData = CDataEntryMemberData;
using CGameServerListInfo = CDataGameServerListInfo;
using CHAR_NAME = nCharacterData::stCharacterName;
using CMailInfo = CDataMailInfo;
using CharacterListElementVec = MtTypedArray<CDataCharacterListElement>;
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using CommunityCharacterBaseInfoVec = MtTypedArray<CDataCommunityCharacterBaseInfo>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MailInfoVec = MtTypedArray<CDataMailInfo>;
using TICKET = cArcLoaderBase*;
using UseSupportPointVec = MtTypedArray<CDataUseSupportPoint>;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cMenuBase : public MtObject
{
    // inferred: cMenuBlackList::initBlackList names cMenuBase::mpList
    friend class cMenuBlackList;
    // inferred: cMenuCharacterList::initCharacterList names cMenuBase::mpList
    friend class cMenuCharacterList;
    // inferred: cMenuKeyConfig::finalCheckBeforeExit names cMenuBase::mpDialogFlow
    friend class cMenuKeyConfig;
    // inferred: cMenuPartyMemberList::getPartyMemberIndex names cMenuBase::mpList
    friend class cMenuPartyMemberList;
    // inferred: cMenuQuickMatchCancel::moveQuickMatchCancel names cMenuBase::mpMenu
    friend class cMenuQuickMatchCancel;
    // inferred: cMenuQuickMatchRetry::moveQuickMatchRetry names cMenuBase::mpMenu
    friend class cMenuQuickMatchRetry;
    // inferred: cMenuSupportList::releaseList names cMenuBase::mpMenuList
    friend class cMenuSupportList;
    // inferred: cMenuSupportMenu::cMenuSupportMenu names cMenuBase::mpMenuList
    friend class cMenuSupportMenu;
    // inferred: sMenu::updateMenu names cMenuBase::mNowMoveFlag
    friend class sMenu;
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
    cMenuBase();
    virtual ~cMenuBase();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void updatePtr();  // vtable slot 6
    bool isMove();
    uGUIBase* getGUI();
    uGUIBase* getGUI(const MtDTI& dti);
    bool isUpdateCursor();
    bool isUpdateTab();
    bool isUpdateButton();
    u32 getMenuNum();
    s32 getConvertCursorIdx(s32 idx);
    const nMenu::MENU_PARTS& getMenuParts(s32 index);
    bool isEnableMenu(s32 menuId);
    // Address: 0x01972110 - 0x01972111 (1 bytes)
    virtual void setPage(s32 page) {}  // vtable slot 7
    virtual u32 getNextBasePointerPrio();  // vtable slot 8
    void setMenuList(s32* pMenuList);
protected:
    virtual bool isCancel(u32 cancelSe);  // vtable slot 9
    virtual bool isDecide();  // vtable slot 10
    virtual bool isDecideIndex(s32 partsIndex, u32 decideSe, u32 notSelectSe);  // vtable slot 11
    virtual bool isTrgCheck(sPadExt::PAD_BTN_TYPE button, u32 useSe, u32 pad_id);  // vtable slot 12
    virtual bool isOnCheck(sPadExt::PAD_BTN_TYPE button, u32 pad_id);  // vtable slot 13
    bool reqDialog(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4);
    bool reqDialog(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, bool isCancelOff, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4);
    void setDialogSE(u32 reason, u32 seId, rSoundRequest* pRes);
    void setDialogDecideSE(u32 seId, rSoundRequest* pRes);
    static void convertStr(MT_CTSTR pInStr, s32 inLen, char* pOutStr, s32 outLen);
    void clearMenuParts(nMenu::MENU_PARTS* pParts, u32 num);
public:
    s32 updateCursorX(cCursor& cursorClass, s32& cursor, s32 orderId);
    s32 updateCursorY(cCursor& cursorClass, s32& cursor, s32 orderId);
    void updateCursorXY(cCursor& cursorClass, s32& curX, s32& curY);
    void updateCursorTab(s32& tab, s32 max);
protected:
    uGUIBase* registerGUI(const MtDTI& dti, u32 line, u64 group);
    uGUIBase* registerGUI(uGUIBase* guiUnit, u32 line, u64 group);
    void setArgsGUI(MT_CTSTR arg1, MT_CTSTR arg2, MT_CTSTR arg3);
    virtual bool isCancelFromGUI();  // vtable slot 14
    void getCursorXPosFromGUI(s32& cursor, s32 orderId);
    void getCursorYPosFromGUI(s32& cursor, s32 orderId);
    void getCursorTabPosFromGUI(s32& tab);
public:
    bool isUseGUI();
protected:
    bool isGUIWindowActive() const;
    void setGUIWindowActive(bool isActive);
public:
    s32 getMenuRno(s32 index);
    s32 getMenuCursor(s32 index);
protected:
    void initMenu();
    void moveMenu();
public:
    virtual void exitMenu();  // vtable slot 15
    bool isBusy();
    void setNowMove(bool flag);
    bool getNowMove();
    virtual void setRefGUI(uGUIBase* pRefGUI, bool useGUI);  // vtable slot 16
    void setCustomBasePrio(u32 prio);
    void setGUIBasePointerPriority(u32 prio);
    s32 getSortIndex(u32 ListIndex);
    s32 getBaseListIndexFromCursor(s32 cursor);
    s32 getBaseListIndexFromMenuId(s32);
    u32 getSortListCount() const;
    bool isRemakeList();
    void reqRemakeList();
    u32 getPageNum();
    u32 getPageNo();
    s32 getMenuId(s32 index);
    s32 getIndexFromMenuId(s32 menuId);
    s32 getListCursor();
    s32 getBaseListIndexNow();
    // Address: 0x01972120 - 0x01972121 (1 bytes)
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId) {}  // vtable slot 17
    virtual bool checkListFilter(u32 sortListIndex);  // vtable slot 18
protected:
    void setBusy(bool busy);
    cMenuDialogFlow* setupDialogFlow(u32 attr);
    cMenuDialogFlow* resetDialogFlow(u32 attr);
    cMenuDialogFlow* getDialogFlow();
    cMenuDialogFlow::RET moveDialogFlow();
    cMenuSupportMenu* setupSupportMenu(u32 menuMax, bool isSimple, bool isAutoUpdate);
    cMenuSupportMenu* getSupportMenu();
    void updateSupportMenu();
    void moveSupportMenu(s32 cursorOrderId);
    void clearMenuList();
    void createMenuListTbl(const s32* pTbl, u32 menuNum);
    void addMenuList(s32 menuId);
    void convertMenuId(s32 from, s32 to);
    bool isDecideMenu(u32 decideSe, u32 notSelectSe);
    cMenuSupportList* setupSupportList(u32 listMax, u32 pageElemMax, u32 pageMenuMax);
    void createList(u32 length);
    void moveList(u32 length);
    void setListCursor(s32 cursorPos);
    cMenuSupportList* getSupportList();
    void changeMenu(cMenuSupportMenu* pMenu);
protected:
    s32 mMenuRno[6];  // offset: 0x8
    s32 mMenuCursor[7];  // offset: 0x20
    bool mIsUpdateCursor;  // offset: 0x3c
    bool mIsUpdateTab;  // offset: 0x3d
    bool mIsUpdateButton;  // offset: 0x3e
    s32* mpMenuList;  // offset: 0x40
    nMenu::MENU_PARTS* mpMenuParts;  // offset: 0x48
    u32 mMenuNum;  // offset: 0x50
    uGUIBase* mpGUIMenu;  // offset: 0x58
    uGUIBase* mpRefGUI;  // offset: 0x60
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x68
    bool mUseGUIMenu;  // offset: 0x70
private:
    bool mBusyFlag;  // offset: 0x71
    bool mNowMoveFlag;  // offset: 0x72
    u32 mCustomBasePrio;  // offset: 0x74
    cMenuDialogFlow* mpDialogFlow;  // offset: 0x78
    cMenuSupportMenu* mpMenu;  // offset: 0x80
    cMenuSupportList* mpList;  // offset: 0x88
    MtTypedArray<cMenuSupport> mMenuSupportList;  // offset: 0x90
public:
    static MyDTI DTI;
    static const s32 MENU_RNO_NUM = 6;
    static const s32 MENU_CURSOR_NUM = 7;
protected:
    static const u32 DEFAULT_GUI_LINE;
    static const u64 DEFAULT_GUI_GROUP;
};

class cMenuBazaarBuy : public cMenuBase
{
public:
    enum
    {
        MOVE_BAZAAR_BUY_RNO_INIT = 0,
        MOVE_BAZAAR_BUY_RNO_MENU_MOVE = 1,
        MOVE_BAZAAR_BUY_RNO_REQ_LIST = 2,
        MOVE_BAZAAR_BUY_RNO_REQ_WAIT = 3,
        MOVE_BAZAAR_BUY_RNO_REQ_ERROR = 4,
        MOVE_BAZAAR_BUY_RNO_LIST_SELECT = 5,
    };
    enum
    {
        BAZAAR_BUY_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        CURSOR_BAZAAR_BUY_SEARCH_SELECT = 0,
        CURSOR_BAZAAR_BUY_MAIN_CATEGORY = 1,
        CURSOR_BAZAAR_BUY_SUB_CATEGORY = 2,
        CURSOR_BAZAAR_BUY_LIST_SELECT = 3,
        DUMMY_CURSOR_MAX = 4,
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
    cMenuBazaarBuy();
    virtual ~cMenuBazaarBuy();
    void initBazaarBuy();
    nMenu::MENU_RET moveBazaarBuy();
public:
    static MyDTI DTI;
    static const s32 MENU_NUM = 5;
};

class cMenuBazaarMenu : public cMenuBase
{
public:
    enum
    {
        MOVE_BAZAAR_MENU_RNO_INIT = 0,
        MOVE_BAZAAR_MENU_RNO_MOVE = 1,
        MOVE_BAZAAR_MENU_RNO_REQ_BAZAAR_LIST = 2,
        MOVE_BAZAAR_MENU_RNO_REQ_BAZAAR_LIST_WAIT = 3,
        MOVE_BAZAAR_MENU_RNO_MENU_INIT = 4,
        MOVE_BAZAAR_MENU_RNO_MENU_MOVE = 5,
        MOVE_BAZAAR_MENU_RNO_SEARCH_ITEM_INIT = 6,
        MOVE_BAZAAR_MENU_RNO_SEARCH_ITEM_MOVE = 7,
        MOVE_BAZAAR_MENU_RNO_SEARCH_ITEM_LIST_INIT = 8,
        MOVE_BAZAAR_MENU_RNO_BUY_LIST_REQ = 9,
        MOVE_BAZAAR_MENU_RNO_BUY_LIST_WAIT = 10,
        MOVE_BAZAAR_MENU_RNO_BUY_LIST_INIT = 11,
        MOVE_BAZAAR_MENU_RNO_BUY_LIST_MOVE = 12,
        MOVE_BAZAAR_MENU_RNO_BUY_DISTRIBUTION_INIT = 13,
        MOVE_BAZAAR_MENU_RNO_BUY_DISTRIBUTION_MOVE = 14,
        MOVE_BAZAAR_MENU_RNO_BUY_CONFIRM_INIT = 15,
        MOVE_BAZAAR_MENU_RNO_BUY_CONFIRM_MOVE = 16,
        MOVE_BAZAAR_MENU_RNO_BUY_REQ = 17,
        MOVE_BAZAAR_MENU_RNO_BUY_WAIT = 18,
        MOVE_BAZAAR_MENU_RNO_BUY_SUCCESS = 19,
        MOVE_BAZAAR_MENU_RNO_BUY_ERROR = 20,
        MOVE_BAZAAR_MENU_RNO_BUY_MSG_WAIT = 21,
        MOVE_BAZAAR_MENU_RNO_SELECT_STORAGE_INIT = 22,
        MOVE_BAZAAR_MENU_RNO_SELECT_STORAGE_MOVE = 23,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_INIT = 24,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_MOVE = 25,
        MOVE_BAZAAR_MENU_RNO_PRICE_SETTING_REQ = 26,
        MOVE_BAZAAR_MENU_RNO_PRICE_SETTING_WAIT = 27,
        MOVE_BAZAAR_MENU_RNO_PRICE_SETTING_INIT = 28,
        MOVE_BAZAAR_MENU_RNO_PRICE_SETTING_MOVE = 29,
        MOVE_BAZAAR_MENU_RNO_PRICE_SETTING_CONFIRM_INIT = 30,
        MOVE_BAZAAR_MENU_RNO_PRICE_SETTING_CONFIRM_MOVE = 31,
        MOVE_BAZAAR_MENU_RNO_START_EXHIBIT_REQ = 32,
        MOVE_BAZAAR_MENU_RNO_START_EXHIBIT_WAIT = 33,
        MOVE_BAZAAR_MENU_RNO_START_EXHIBIT_SUCCESS = 34,
        MOVE_BAZAAR_MENU_RNO_START_EXHIBIT_ERROR = 35,
        MOVE_BAZAAR_MENU_RNO_START_EXHIBIT_MSG_WAIT = 36,
        MOVE_BAZAAR_MENU_RNO_START_EXHIBIT_AFTER_REQ_BAZAAR_LIST = 37,
        MOVE_BAZAAR_MENU_RNO_START_EXHIBIT_AFTER_REQ_BAZAAR_LIST_WAIT = 38,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANNOT_SELECT_INIT = 39,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANNOT_SELECT_MOVE = 40,
        MOVE_BAZAAR_MENU_RNO_USE_INFO_INIT = 41,
        MOVE_BAZAAR_MENU_RNO_USE_INFO_MOVE = 42,
        MOVE_BAZAAR_MENU_RNO_GET_PROCEEDS_REQ = 43,
        MOVE_BAZAAR_MENU_RNO_GET_PROCEEDS_WAIT = 44,
        MOVE_BAZAAR_MENU_RNO_GET_PROCEEDS_SUCCESS = 45,
        MOVE_BAZAAR_MENU_RNO_GET_PROCEEDS_ERROR = 46,
        MOVE_BAZAAR_MENU_RNO_GET_PROCEEDS_MSG_WAIT = 47,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_COMMAND_SELECT_INIT = 48,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_COMMAND_SELECT_MOVE = 49,
        MOVE_BAZAAR_MENU_RNO_USE_INFO_TO_SELECT_STORAGE_INIT = 50,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_INIT = 51,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_MOVE = 52,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_REQ = 53,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_WAIT = 54,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_SUCCESS = 55,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_ERROR = 56,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_MSG_WAIT = 57,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_LIST = 58,
        MOVE_BAZAAR_MENU_RNO_EXHIBIT_CANCEL_LIST_WAIT = 59,
        MOVE_BAZAAR_MENU_RNO_RE_EXHIBIT_PRICE_SETTING_REQ = 60,
        MOVE_BAZAAR_MENU_RNO_RE_EXHIBIT_PRICE_SETTING_WAIT = 61,
        MOVE_BAZAAR_MENU_RNO_RE_PRICE_SETTING_INIT = 62,
        MOVE_BAZAAR_MENU_RNO_RE_PRICE_SETTING_MOVE = 63,
        MOVE_BAZAAR_MENU_RNO_RE_PRICE_SETTING_CONFIRM_INIT = 64,
        MOVE_BAZAAR_MENU_RNO_RE_PRICE_SETTING_CONFIRM_MOVE = 65,
        MOVE_BAZAAR_MENU_RNO_RE_START_EXHIBIT_REQ = 66,
        MOVE_BAZAAR_MENU_RNO_RE_START_EXHIBIT_WAIT = 67,
        MOVE_BAZAAR_MENU_RNO_RE_START_EXHIBIT_SUCCESS = 68,
        MOVE_BAZAAR_MENU_RNO_RE_START_EXHIBIT_ERROR = 69,
        MOVE_BAZAAR_MENU_RNO_RE_START_EXHIBIT_MSG_WAIT = 70,
        MOVE_BAZAAR_MENU_RNO_SHORTCUT_EXHIBIT = 71,
        MOVE_BAZAAR_MENU_RNO_SHORTCUT_EXHIBIT_WAIT = 72,
    };
    enum
    {
        BAZAAR_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        BAZAAR_MENU_CURSOR_SELECT = 0,
        BAZAAR_DEAL_SHEET_CURSOR_SELECT = 1,
        BAZAAR_DEAL_SHEET_COMMAND_SELECT = 2,
        DUMMY_CURSOR_MAX = 3,
    };
    enum
    {
        BAZAAR_DEAL_SHEET_SALE = 0,
        BAZAAR_DEAL_SHEET_SELECT = 1,
    };
    enum
    {
        BAZAAR_MENU_BUY = 0,
        BAZAAR_MENU_EXHIBIT = 1,
        BAZAAR_MENU_USE_INFO = 2,
        BAZAAR_MENUMAX = 3,
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
    cMenuBazaarMenu();
    virtual ~cMenuBazaarMenu();
    void initBazaarMenu();
    nMenu::MENU_RET moveBazaarMenu();
public:
    static MyDTI DTI;
    static const s32 MENU_NUM = 3;
};

class cMenuBlackList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_LIST = 1,
        RNO_SUB_MENU = 2,
    };
    enum
    {
        BLACK_LIST_RNO_BASE = 0,
        BLACK_LIST_RNO_MAX = 1,
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
    cMenuBlackList();
    virtual ~cMenuBlackList();
    void initBlackList(uGUIBase* pRefGUI);
    nMenu::MENU_RET moveBlackList();
    virtual void exitMenu();  // vtable slot 15
    u32 getBlackListDispNum();
    s32 getRno();
public:
    static MyDTI DTI;
};

class cMenuBreakupParty : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        BREAKUP_PARTY_RNO_BASE = 0,
        BREAKUP_PARTY_RNO_MAX = 1,
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
    cMenuBreakupParty();
    virtual ~cMenuBreakupParty();
    void initBreakupParty();
    nMenu::MENU_RET moveBreakupParty();
    virtual void exitMenu();  // vtable slot 15
private:
    bool callbackCheckCloseDialog();
public:
    static MyDTI DTI;
};

class cMenuCancelFriend : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        CANCEL_FRIEND_RNO_BASE = 0,
        CANCEL_FRIEND_RNO_MAX = 1,
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
    cMenuCancelFriend();
    virtual ~cMenuCancelFriend();
    void initCancelFriend(u32 characterId, MtString& charName);
    nMenu::MENU_RET moveCancelFriend();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mCharacterId;  // offset: 0xb0
    MtString mCharName;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuChangeServer : public cMenuBase
{
public:
    enum
    {
        CHANGE_SERVER_CURSOR_LIST = 0,
        CHANGE_SERVER_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_ERROR = 3,
    };
    enum
    {
        CHANGE_SERVER_RNO_BASE = 0,
        CHANGE_SERVER_RNO_MAX = 1,
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
    cMenuChangeServer();
    virtual ~cMenuChangeServer();
    void initChangeServer(u32 serverId);
    nMenu::MENU_RET moveChangeServer();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mServerId;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuCharacterList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_START = 3,
        RNO_LIST = 4,
        RNO_SEARCH_FILTER = 5,
        RNO_SUB_MENU = 6,
        RNO_LIST_ERROR = 7,
    };
    enum
    {
        CHARACTER_LIST_RNO_BASE = 0,
        CHARACTER_LIST_RNO_MAX = 1,
    };
    enum
    {
        CHARACTER_LIST_TOP = 0,
        CHARACTER_LIST_BOTTOM = 14,
        CHARACTER_LIST_SETTING = 14,
        CHARACTER_LIST_MAX = 15,
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
    cMenuCharacterList();
    virtual ~cMenuCharacterList();
    void initCharacterList(uGUIBase* pGUIRefMenu);
    nMenu::MENU_RET moveCharacterList();
    virtual void exitMenu();  // vtable slot 15
    const cCharacterData::stSearchFilterSetting& getSearchSetting();
private:
    cCharacterData::stSearchFilterSetting mSearchSetting;  // offset: 0xb0
    bool mFirst;  // offset: 0x1dc
public:
    static MyDTI DTI;
    static const s32 CHARACTER_LIST_DISP_NUM = 14;
    static const s32 CHARACTER_SORT_LIST_MAX = 256;
};

class cMenuCraftColorFrame : public cMenuBase
{
public:
    enum
    {
        COLOR_DECIDE_PAWN = 0,
        COLOR_DECIDE_SLOT = 1,
    };
    enum
    {
        COLOR_SLOT_NONE = 0,
        COLOR_SLOT_START = 1,
        COLOR_MY_PAWN = 1,
        COLOR_SLOT_1 = 2,
        COLOR_DECIDE = 3,
        COLOR_EQUIP = 4,
        COLOR_NOW = 5,
        COLOR_AFTER = 6,
        COLOR_SLOT_NUM = 7,
    };
    enum
    {
        MOVE_COLOR_MENU_RNO_INIT = 0,
        MOVE_COLOR_MENU_RNO_SELECT = 1,
    };
    enum
    {
        COLOR_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        COLOR_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
    };
public:
    class MyDTI;
    class cMenuCtrl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMenuCtrl : public MtObject
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
    public:
        u32 mTitle;  // offset: 0x8
        bool mIsSelect;  // offset: 0xc
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
    cMenuCraftColorFrame();
    virtual ~cMenuCraftColorFrame();
    void initCraftColorFrame();
    nMenu::MENU_RET moveCraftColorFrame(u32* slotNo);
private:
    cMenuCtrl mMenuTitle[3];  // offset: 0xb0
public:
    static MyDTI DTI;
    static const u32 MENU_DISP_MAX = 3;
};

class cMenuCraftColorItem : public cMenuBase
{
public:
    enum
    {
        MOVE_COLOR_MENU_RNO_INIT = 0,
        MOVE_COLOR_MENU_RNO_SELECT = 1,
        MOVE_COLOR_MENU_RNO_GOLD_CHECK = 2,
        MOVE_COLOR_MENU_RNO_GOLD_CHECK_WAIT = 3,
        MOVE_COLOR_MENU_RNO_KICK_PAWN_CHECK = 4,
        MOVE_COLOR_MENU_RNO_KICK_PAWN_ANNOUNCE = 5,
        MOVE_COLOR_MENU_RNO_KICK_PAWN_ANNOUNCE_WAIT = 6,
        MOVE_COLOR_MENU_RNO_KICK_PAWN_REQ = 7,
        MOVE_COLOR_MENU_RNO_KICK_PAWN_WAIT = 8,
        MOVE_COLOR_MENU_RNO_KICK_ERROR = 9,
        MOVE_COLOR_MENU_RNO_REQ = 10,
        MOVE_COLOR_MENU_RNO_REQ_WAIT = 11,
        MOVE_COLOR_MENU_RNO_REQ_ERROR = 12,
        MOVE_COLOR_MENU_RNO_REQ_SUCCESS = 13,
        MOVE_COLOR_MENU_RNO_REQ_SUCCESS_WAIT = 14,
        MOVE_COLOR_MENU_RNO_RESULT = 15,
        MOVE_COLOR_MENU_RNO_RESULT_WAIT = 16,
        MOVE_COLOR_MENU_RNO_RANKUP_INIT = 17,
        MOVE_COLOR_MENU_RNO_RANKUP_WAIT = 18,
        MOVE_COLOR_MENU_RNO_RANKUP_UI = 19,
        MOVE_COLOR_MENU_RNO_RANKUP_EXAM_UI_WAIT = 20,
        MOVE_COLOR_MENU_RNO_RANKUP_PAWN_LIST_REQ = 21,
        MOVE_COLOR_MENU_RNO_RANKUP_PAWN_LIST_REQ_WAIT = 22,
        MOVE_COLOR_MENU_RNO_END = 23,
    };
    enum
    {
        COLOR_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        COLOR_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
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
    cMenuCraftColorItem();
    virtual ~cMenuCraftColorItem();
    void initCraftColorItem();
    nMenu::MENU_RET moveCraftColorItem();
private:
    u32 mKickPartyCtr;  // offset: 0xb0
    bool mIsEffect;  // offset: 0xb4
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftCreateItem : public cMenuBase
{
public:
    enum
    {
        MOVE_CREATEITEM_MENU_RNO_PARTY_CONFIRM = 0,
        MOVE_CREATEITEM_MENU_RNO_DLG_FLOW = 1,
        MOVE_CREATEITEM_MENU_RNO_KICK_PAWN_REQ = 2,
        MOVE_CREATEITEM_MENU_RNO_KICK_PAWN_WAIT = 3,
        MOVE_CREATEITEM_MENU_RNO_KICK_ERROR = 4,
        MOVE_CREATEITEM_MENU_RNO_CREATE_REQ = 5,
        MOVE_CREATEITEM_MENU_RNO_CREATE_WAIT = 6,
        MOVE_CREATEITEM_MENU_RNO_CREATE_ERROR = 7,
        MOVE_CREATEITEM_MENU_RNO_CREATE_SUCCESS = 8,
        MOVE_CREATEITEM_MENU_RNO_GP_USE_INIT = 9,
        MOVE_CREATEITEM_MENU_RNO_GP_USE = 10,
        MOVE_CREATEITEM_MENU_RNO_TIME_SAVE_REQ = 11,
        MOVE_CREATEITEM_MENU_RNO_TIME_SAVE_WAIT = 12,
        MOVE_CREATEITEM_MENU_RNO_END = 13,
    };
    enum
    {
        CREATEITEM_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        CREATEITEM_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
    };
    enum
    {
        LEAVE_DIALOG = 0,
    };
    enum
    {
        ERROR_TYPE_NONE = 0,
        ERROR_TYPE_MATERIAL = 1,
        ERROR_TYPE_SUPPORT_PAWN = 2,
        ERROR_TYPE_GOLD = 3,
        ERROR_TYPE_NETWORK = 4,
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
    cMenuCraftCreateItem();
    virtual ~cMenuCraftCreateItem();
    void initCraftCreateItem(MOVE_LINE moveLine);
    nMenu::MENU_RET moveCraftCreateItem();
private:
    MOVE_LINE mNextMoveLine;  // offset: 0xb0
    u32 mKickPartyCtr;  // offset: 0xb4
    s32 mCreateStyle;  // offset: 0xb8
    u32 mErrorState;  // offset: 0xbc
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftElementFrame : public cMenuBase
{
public:
    enum
    {
        ELEMENT_DECIDE_PAWN = 0,
        ELEMENT_DECIDE_SLOT_1 = 1,
        ELEMENT_DECIDE_SLOT_2 = 2,
        ELEMENT_DECIDE_SLOT_3 = 3,
        ELEMENT_DECIDE_SLOT_4 = 4,
    };
    enum
    {
        ELEMENT_SLOT_NONE = 0,
        ELEMENT_SLOT_START = 1,
        ELEMENT_MY_PAWN = 1,
        ELEMENT_SLOT_1 = 2,
        ELEMENT_SLOT_2 = 3,
        ELEMENT_SLOT_3 = 4,
        ELEMENT_SLOT_4 = 5,
        ELEMENT_DECIDE = 6,
        ELEMENT_EQUIP = 7,
        ELEMENT_SLOT_NUM = 8,
    };
    enum
    {
        MOVE_ELEMENT_MENU_RNO_INIT = 0,
        MOVE_ELEMENT_MENU_RNO_SELECT = 1,
    };
    enum
    {
        ELEMENT_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        ELEMENT_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
    };
public:
    class MyDTI;
    class cMenuCtrl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMenuCtrl : public MtObject
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
    public:
        u32 mTitle;  // offset: 0x8
        bool mIsSelect;  // offset: 0xc
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
    cMenuCraftElementFrame();
    virtual ~cMenuCraftElementFrame();
    void initCraftElementFrame();
    nMenu::MENU_RET moveCraftElementFrame(u32* slotNo);
private:
    cMenuCtrl mMenuTitle[6];  // offset: 0xb0
public:
    static MyDTI DTI;
    static const u32 ELEMENT_SLOT_MAX = 4;
    static const u32 MENU_DISP_MAX = 6;
};

class cMenuCraftElementItem : public cMenuBase
{
public:
    enum
    {
        ELEMENT_CTRL_TYPE_ATACH = 0,
        ELEMENT_CTRL_TYPE_DETACH = 1,
        ELEMENT_CTRL_TYPE_NUM = 2,
    };
    enum
    {
        MOVE_ELEMENT_MENU_RNO_INIT = 0,
        MOVE_ELEMENT_MENU_RNO_SELECT = 1,
        MOVE_ELEMENT_MENU_RNO_DETACH_INIT = 2,
        MOVE_ELEMENT_MENU_RNO_DETACH_SELECT = 3,
        MOVE_ELEMENT_MENU_RNO_GOLD_CHECK = 4,
        MOVE_ELEMENT_MENU_RNO_GOLD_CHECK_WAIT = 5,
        MOVE_ELEMENT_MENU_RNO_KICK_PAWN_CHECK = 6,
        MOVE_ELEMENT_MENU_RNO_KICK_PAWN_ANNOUNCE = 7,
        MOVE_ELEMENT_MENU_RNO_KICK_PAWN_ANNOUNCE_WAIT = 8,
        MOVE_ELEMENT_MENU_RNO_KICK_PAWN_REQ = 9,
        MOVE_ELEMENT_MENU_RNO_KICK_PAWN_WAIT = 10,
        MOVE_ELEMENT_MENU_RNO_KICK_ERROR = 11,
        MOVE_ELEMENT_MENU_RNO_REQ = 12,
        MOVE_ELEMENT_MENU_RNO_REQ_WAIT = 13,
        MOVE_ELEMENT_MENU_RNO_REQ_ERROR = 14,
        MOVE_ELEMENT_MENU_RNO_REQ_SUCCESS = 15,
        MOVE_ELEMENT_MENU_RNO_REQ_SUCCESS_WAIT = 16,
        MOVE_ELEMENT_MENU_RNO_RESULT = 17,
        MOVE_ELEMENT_MENU_RNO_RESULT_WAIT = 18,
        MOVE_ELEMENT_MENU_RNO_REQ_DETACH = 19,
        MOVE_ELEMENT_MENU_RNO_RANKUP_INIT = 20,
        MOVE_ELEMENT_MENU_RNO_RANKUP_WAIT = 21,
        MOVE_ELEMENT_MENU_RNO_RANKUP_UI = 22,
        MOVE_ELEMENT_MENU_RNO_RANKUP_PAWN_LIST_REQ = 23,
        MOVE_ELEMENT_MENU_RNO_RANKUP_PAWN_LIST_REQ_WAIT = 24,
        MOVE_ELEMENT_MENU_RNO_END = 25,
    };
    enum
    {
        ELEMENT_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        ELEMENT_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
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
    cMenuCraftElementItem();
    virtual ~cMenuCraftElementItem();
    void initCraftElementItem(u32 type, u32 slotNo);
    nMenu::MENU_RET moveCraftElementItem();
private:
    u32 mType;  // offset: 0xb0
    u32 mSlotNo;  // offset: 0xb4
    u32 mKickPartyCtr;  // offset: 0xb8
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftGoldStoneDialog : public cMenuBase
{
public:
    enum
    {
        SELECT_TYPE_NONE = 0,
        SELECT_TYPE_NORAMAL = 1,
        SELECT_TYPE_GP = 2,
    };
    enum
    {
        RNO_DLG_FLOW = 0,
        RNO_ONLINESHOP = 1,
        RNO_ERROR = 2,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
    };
    enum
    {
        CREATE_SELECT_DIALOG = 0,
        NORMAL_SELECT_DIALOG = 1,
        GOLDSTONE_SELECT_DIALOG = 2,
        ONLINE_SHOP_DIALOG = 3,
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
    cMenuCraftGoldStoneDialog();
    virtual ~cMenuCraftGoldStoneDialog();
    void initCraftGoldStoneDialog(u32 type, MOVE_LINE moveLine);
    nMenu::MENU_RET moveCraftGoldStoneDialog(s32* selectType);
private:
    u32 mType;  // offset: 0xb0
    MOVE_LINE mMoveLine;  // offset: 0xb4
    s32 mMenuList[1];  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuCraftItemSelect : public cMenuBase
{
public:
    enum
    {
        ITEM_LIST_TYPE_CREATE = 0,
        ITEM_LIST_TYPE_UPGRADE = 1,
        ITEM_LIST_TYPE_ELEMENT = 2,
        ITEM_LIST_TYPE_COLOR = 3,
        ITEM_LIST_TYPE_NUM = 4,
    };
    enum
    {
        MOVE_SELECT_MENU_RNO_INIT = 0,
        MOVE_SELECT_MENU_RNO_MATERIAL_REQ_WAIT = 1,
        MOVE_SELECT_MENU_RNO_SELECT = 2,
        MOVE_SELECT_MENU_RNO_END = 3,
    };
    enum
    {
        SELECT_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        SELECT_MENU_CURSOR_SELECT = 0,
        SELECT_MENU_LIST_SELECT = 1,
        DUMMY_CURSOR_MAX = 2,
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
    cMenuCraftItemSelect();
    virtual ~cMenuCraftItemSelect();
    void initCraftItemSelect(u32 listType, u32 slotNo);
    nMenu::MENU_RET moveCraftItemSelect();
private:
    u32 mListType;  // offset: 0xb0
    u32 mSlotNo;  // offset: 0xb4
    rItemList::MATERIAL_CATEGORY mReqType;  // offset: 0xb8
    u32 mItemId;  // offset: 0xbc
public:
    static MyDTI DTI;
    static const s32 LIST_DISP_NUM = 5;
};

class cMenuCraftMenu : public cMenuBase
{
public:
    enum CREATE_STATE
    {
        CREATE_STATE_OK = 0,
        CREATE_STATE_PAWN_ERROR = 1,
        CREATE_STATE_MATERIAL_ERROR = 2,
        CREATE_STATE_RANK_ERROR = 3,
        CREATE_STATE_MONEY_ERROR = 4,
        CREATE_STATE_RECIPE_ERROR = 5,
        CREATE_STATE_NUM = 6,
    };
    enum
    {
        MOVE_CRAFT_MENU_RNO_INIT = 0,
        MOVE_CRAFT_MENU_RNO_COLOR_REGULATE_LIST_REQ = 1,
        MOVE_CRAFT_MENU_RNO_COLOR_REGULATE_LIST_WAIT = 2,
        MOVE_CRAFT_MENU_RNO_LIMIT_BREAK_LIST_REQ = 3,
        MOVE_CRAFT_MENU_RNO_LIMIT_BREAK_LIST_WAIT = 4,
        MOVE_CRAFT_MENU_RNO_IR_REDUCTION_DATA_LIST_REQ = 5,
        MOVE_CRAFT_MENU_RNO_IR_REDUCTION_DATA_LIST_WAIT = 6,
        MOVE_CRAFT_MENU_RNO_RECIPE_LIST_REQ = 7,
        MOVE_CRAFT_MENU_RNO_RECIPE_LIST_WAIT = 8,
        MOVE_CRAFT_MENU_RNO_GRADEUP_LIST_REQ = 9,
        MOVE_CRAFT_MENU_RNO_GRADEUP_LIST_WAIT = 10,
        MOVE_CRAFT_MENU_RNO_LOCKED_ELEMENT_LIST_REQ = 11,
        MOVE_CRAFT_MENU_RNO_LOCKED_ELEMENT_LIST_WAIT = 12,
        MOVE_CRAFT_MENU_RNO_BAGGAGE_ITEM_REQ = 13,
        MOVE_CRAFT_MENU_RNO_BAGGAGE_ITEM_WAIT = 14,
        MOVE_CRAFT_MENU_RNO_CRAFT_PROGRESS_INIT = 15,
        MOVE_CRAFT_MENU_RNO_CRAFT_PROGRESS_WAIT = 16,
        MOVE_CRAFT_MENU_RNO_GUI_CREATE_WAIT = 17,
        MOVE_CRAFT_MENU_RNO_MENU_INIT = 18,
        MOVE_CRAFT_MENU_RNO_MENU = 19,
        MOVE_CRAFT_MENU_RNO_PROCESS_MENU_INIT = 20,
        MOVE_CRAFT_MENU_RNO_PROCESS_MENU = 21,
        MOVE_CRAFT_MENU_RNO_MAIN_PAWN_LIST_INIT = 22,
        MOVE_CRAFT_MENU_RNO_MAIN_PAWN_LIST = 23,
        MOVE_CRAFT_MENU_RNO_MAIN_PAWN_LIST_INIT2 = 24,
        MOVE_CRAFT_MENU_RNO_MAIN_PAWN_LIST2 = 25,
        MOVE_CRAFT_MENU_RNO_RECIPE_LIST_INIT = 26,
        MOVE_CRAFT_MENU_RNO_RECIPE_LIST = 27,
        MOVE_CRAFT_MENU_RNO_CREATE_ITEM = 28,
        MOVE_CRAFT_MENU_RNO_UPGRADE_LIST_INIT = 29,
        MOVE_CRAFT_MENU_RNO_UPGRADE_LIST = 30,
        MOVE_CRAFT_MENU_RNO_UPGRADE_ITEM = 31,
        MOVE_CRAFT_MENU_RNO_UPGRADE_CONTINUE = 32,
        MOVE_CRAFT_MENU_RNO_UPGRADE_CONTINUE_WAIT = 33,
        MOVE_CRAFT_MENU_RNO_SUPPORT_FRAME_INIT = 34,
        MOVE_CRAFT_MENU_RNO_SUPPORT_FRAME = 35,
        MOVE_CRAFT_MENU_RNO_SUPPORT_PAWN_LIST_INIT = 36,
        MOVE_CRAFT_MENU_RNO_SUPPORT_PAWN_LIST = 37,
        MOVE_CRAFT_MENU_RNO_ELEMENT_LIST_INIT = 38,
        MOVE_CRAFT_MENU_RNO_ELEMENT_LIST = 39,
        MOVE_CRAFT_MENU_RNO_ELEMENT_ITEM = 40,
        MOVE_CRAFT_MENU_RNO_ELEMENT_DETACH = 41,
        MOVE_CRAFT_MENU_RNO_COLOR_LIST_INIT = 42,
        MOVE_CRAFT_MENU_RNO_COLOR_LIST = 43,
        MOVE_CRAFT_MENU_RNO_COLOR_ITEM = 44,
        MOVE_CRAFT_MENU_RNO_POINT_INIT = 45,
        MOVE_CRAFT_MENU_RNO_POINT = 46,
        MOVE_CRAFT_MENU_RNO_CRAFT_TASK_INIT = 47,
        MOVE_CRAFT_MENU_RNO_CRAFT_TASK = 48,
        MOVE_CRAFT_MENU_RNO_ITEM_SELECT_INIT = 49,
        MOVE_CRAFT_MENU_RNO_ITEM_SELECT = 50,
        MOVE_CRAFT_MENU_RNO_END = 51,
    };
    enum
    {
        CRAFT_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        CRAFT_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
    };
    enum
    {
        CRAFT_MENU_ITEM_CREATE = 0,
        CRAFT_MENU_ITEM_UPGRADE = 1,
        CRAFT_MENU_ELEMENT = 2,
        CRAFT_MENU_COLOR = 3,
        CRAFT_MENU_POINT = 4,
        CRAFT_MENU_CRAFT_TASK = 5,
        CRAFT_MENU_ITEM_PROCESS = 6,
        CRAFT_MENU_MAX = 7,
    };
    enum
    {
        PROCESS_MENU_NONE = 0,
        PROCESS_MENU_ELEMENT = 1,
        PROCESS_MENU_COLOR = 2,
        PROCESS_MENU_MAX = 3,
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
    cMenuCraftMenu();
    virtual ~cMenuCraftMenu();
    void initCraftMenu();
    nMenu::MENU_RET moveCraftMenu();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mPawnSlot;  // offset: 0xb0
    u32 mProcessSlot;  // offset: 0xb4
    u32 mElementSlot;  // offset: 0xb8
    u32 mColorSlot;  // offset: 0xbc
    u32 mRecipeList;  // offset: 0xc0
    MOVE_LINE mNextMoveLine;  // offset: 0xc4
public:
    static MyDTI DTI;
    static const s32 MENU_NUM = 5;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftMyPawnList : public cMenuBase
{
public:
    enum
    {
        PAWNLIST_TYPE_CREATE = 0,
        PAWNLIST_TYPE_UPGRADE = 1,
        PAWNLIST_TYPE_PROCESS = 2,
    };
    enum
    {
        MOVE_PAWNLIST_MENU_RNO_INIT = 0,
        MOVE_PAWNLIST_MENU_RNO_CRAFT_PROGRESS_REQ = 1,
        MOVE_PAWNLIST_MENU_RNO_CRAFT_PROGRESS_WAIT = 2,
        MOVE_PAWNLIST_MENU_RNO_CRAFT_PROGRESS_ERROR = 3,
        MOVE_PAWNLIST_MENU_RNO_REQ = 4,
        MOVE_PAWNLIST_MENU_RNO_SELECT = 5,
    };
    enum
    {
        PAWNLIST_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        PAWNLIST_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
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
    cMenuCraftMyPawnList();
    virtual ~cMenuCraftMyPawnList();
    void initCraftMyPawnList(u32 listType);
    nMenu::MENU_RET moveCraftMyPawnList();
private:
    u32 mSaveSlot;  // offset: 0xb0
    u32 mListType;  // offset: 0xb4
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftPoint : public cMenuBase
{
public:
    enum
    {
        MOVE_POINT_MENU_RNO_INIT = 0,
        MOVE_POINT_MENU_RNO_DETAIL_REQ = 1,
        MOVE_POINT_MENU_RNO_DETAIL_WAIT = 2,
        MOVE_POINT_MENU_RNO_SELECT = 3,
        MOVE_POINT_MENU_RNO_INFO_WAIT = 4,
        MOVE_POINT_MENU_RNO_INFO_SELECT = 5,
        MOVE_POINT_MENU_RNO_REQ = 6,
        MOVE_POINT_MENU_RNO_REQ_WAIT = 7,
        MOVE_POINT_MENU_RNO_END = 8,
    };
    enum
    {
        POINT_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        POINT_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
    };
    enum
    {
        MENU_SKILL_SPEED = 0,
        MENU_SKILL_STR = 1,
        MENU_SKILL_GAIN = 2,
        MENU_SKILL_BURST = 3,
        MENU_SKILL_COST = 4,
        MENU_DECIDE = 5,
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
    cMenuCraftPoint();
    virtual ~cMenuCraftPoint();
    void initCraftPoint();
    nMenu::MENU_RET moveCraftPoint();
private:
    u32 mPointNum;  // offset: 0xb0
    s32 mSkillPoint[5];  // offset: 0xb4
    u32 mSkillReq;  // offset: 0xc8
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 6;
};

class cMenuCraftProcessMenu : public cMenuBase
{
public:
    enum
    {
        LIST_TYPE_ELEMENT = 0,
        LIST_TYPE_COLOR = 1,
        LIST_TYPE_NUM = 2,
    };
    enum
    {
        MENU_RNO_INIT = 0,
        MENU_RNO_SELECT = 1,
    };
    enum
    {
        MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        MENU_CURSOR_SELECT = 0,
        MENU_LIST_SELECT = 1,
        MENU_DISP_LIST_TOP = 2,
        MENU_CURSOR_CATEGORY_SELECT = 3,
        DUMMY_CURSOR_MAX = 4,
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
    cMenuCraftProcessMenu();
    virtual ~cMenuCraftProcessMenu();
    void initCraftProcessMenu(u32 listType);
    nMenu::MENU_RET moveCraftProcessMenu(u32* slotNo);
    u32 getPrice(u32 itemId, u8 priceType);
    cMenuCraftMenu::CREATE_STATE isPrice(u32 itemId, u8 priceType);
private:
    u32 mPawnSlot;  // offset: 0xb0
    u32 mListType;  // offset: 0xb4
public:
    static MyDTI DTI;
    static const s32 LIST_DISP_NUM = 5;
};

class cMenuCraftRecipeList : public cMenuBase
{
public:
    enum
    {
        MOVE_RECIPELIST_MENU_RNO_INIT = 0,
        MOVE_RECIPELIST_MENU_RNO_SELECT = 1,
        MOVE_RECIPELIST_MENU_RNO_SELECT2 = 2,
        MOVE_RECIPELIST_MENU_RNO_BAGGAGE_REQ = 3,
        MOVE_RECIPELIST_MENU_RNO_BAGGAGE_WAIT = 4,
    };
    enum
    {
        RECIPELIST_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        RECIPELIST_MENU_CURSOR_SELECT = 0,
        RECIPELIST_MENU_LIST_SELECT = 1,
        RECIPELIST_MENU_CURSOR_CATEGORY_SELECT = 2,
        DUMMY_CURSOR_MAX = 3,
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
    cMenuCraftRecipeList();
    virtual ~cMenuCraftRecipeList();
    void initCraftRecipeList();
    nMenu::MENU_RET moveCraftRecipeList();
    static cMenuCraftMenu::CREATE_STATE isCreate(u32 recipeId, u32 type, bool isEffect);
    static cMenuCraftMenu::CREATE_STATE isCreateGold(u32 recipeId, u32 type, cMenuCraftMenu::CREATE_STATE state);
    static void errorAnnounce(cMenuCraftMenu::CREATE_STATE state);
private:
    nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE mCategory;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftSupportFrame : public cMenuBase
{
public:
    enum
    {
        CRAFT_SUPPORT_FRAME_TYPE_CREATE = 0,
        CRAFT_SUPPORT_FRAME_TYPE_UPGRADE = 1,
    };
    enum
    {
        MOVE_SUPPORTFRAME_MENU_RNO_INIT = 0,
        MOVE_SUPPORTFRAME_MENU_RNO_SELECT = 1,
    };
    enum
    {
        SUPPORTFRAME_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        SUPPORTFRAME_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
    };
    enum
    {
        MENU_NONE = 0,
        MENU_START = 1,
        MENU_MAIN_PAWN_SLOT = 1,
        MENU_SUPPORT_PAWN_SLOT_1 = 2,
        MENU_SUPPORT_PAWN_SLOT_2 = 3,
        MENU_SUPPORT_PAWN_SLOT_3 = 4,
        MENU_PLUS_MATERIAL = 5,
        MENU_DECIDE = 6,
        MENU_RECIPE = 7,
        MENU_NUM = 8,
    };
    enum
    {
        CRAFT_SUPPORT_DECIDE_MAIN_PAWN = 0,
        CRAFT_SUPPORT_DECIDE_SUPPORT_PAWN_1 = 1,
        CRAFT_SUPPORT_DECIDE_SUPPORT_PAWN_2 = 2,
        CRAFT_SUPPORT_DECIDE_SUPPORT_PAWN_3 = 3,
        CRAFT_SUPPORT_DECIDE_PLUS_MATERIAL = 4,
    };
public:
    class MyDTI;
    class cMenuCtrl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMenuCtrl : public MtObject
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
    public:
        u32 mTitle;  // offset: 0x8
        bool mIsSelect;  // offset: 0xc
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
    cMenuCraftSupportFrame();
    virtual ~cMenuCraftSupportFrame();
    void initCraftSupportFrame(u32 type, u32 cursorPos);
    nMenu::MENU_RET moveCraftSupportFrame(u32* slotNo);
private:
    cMenuCtrl mMenuTitle[6];  // offset: 0xb0
    u32 mListType;  // offset: 0x110
public:
    static MyDTI DTI;
    static const s32 MENU_DISP_MAX = 6;
    static const s32 CRAFT_SUPPORT_FRAME_DISP_NUM = 4;
};

class cMenuCraftSupportList : public cMenuBase
{
public:
    enum
    {
        MOVE_SUPPORTLIST_MENU_RNO_INIT = 0,
        MOVE_SUPPORTLIST_MENU_RNO_REQ = 1,
        MOVE_SUPPORTLIST_MENU_RNO_SELECT = 2,
    };
    enum
    {
        SUPPORTLIST_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        SUPPORTLIST_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
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
    cMenuCraftSupportList();
    virtual ~cMenuCraftSupportList();
    void initCraftSupportList();
    nMenu::MENU_RET moveCraftSupportList(u32* slotNo);
private:
    u32 mSlotNo;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftTask : public cMenuBase
{
public:
    enum
    {
        MOVE_TASK_MENU_RNO_INIT = 0,
        MOVE_TASK_MENU_RNO_CRAFT_PROGRESS_REQ = 1,
        MOVE_TASK_MENU_RNO_CRAFT_PROGRESS_WAIT = 2,
        MOVE_TASK_MENU_RNO_CRAFT_PROGRESS_ERROR = 3,
        MOVE_TASK_MENU_RNO_SELECT_INIT = 4,
        MOVE_TASK_MENU_RNO_SELECT_CONTINUE = 5,
        MOVE_TASK_MENU_RNO_SELECT_MOVE = 6,
        MOVE_TASK_MENU_RNO_PRODUCT_INFO_REQ = 7,
        MOVE_TASK_MENU_RNO_PRODUCT_INFO_WAIT = 8,
        MOVE_TASK_MENU_RNO_PRODUCT_INFO_ERROR = 9,
        MOVE_TASK_MENU_RNO_CREATE_COMPLETE = 10,
        MOVE_TASK_MENU_RNO_CREATE_FAILD = 11,
        MOVE_TASK_MENU_RNO_CREATE_COMPLETE_WAIT = 12,
        MOVE_TASK_MENU_RNO_CREATE_CANCEL_QUE = 13,
        MOVE_TASK_MENU_RNO_CREATE_CANCEL = 14,
        MOVE_TASK_MENU_RNO_CREATE_CANCEL_FAILD = 15,
        MOVE_TASK_MENU_RNO_CREATE_CANCEL_WAIT = 16,
        MOVE_TASK_MENU_RNO_CREATE_CANCEL_SUCCESS_ANOUNCE = 17,
        MOVE_TASK_MENU_RNO_CREATE_CANCEL_ANOUNCE_WAIT = 18,
        MOVE_TASK_MENU_RNO_CREATE_TIME_SAVE_QUE = 19,
        MOVE_TASK_MENU_RNO_CREATE_TIME_SAVE_WAIT = 20,
        MOVE_TASK_MENU_RNO_ONLINESHOP = 21,
        MOVE_TASK_MENU_RNO_GET_ITEM_INIT = 22,
        MOVE_TASK_MENU_RNO_GET_ITEM_SELECT = 23,
        MOVE_TASK_MENU_RNO_GET_ITEM_REQ = 24,
        MOVE_TASK_MENU_RNO_GET_ITEM_REQ_WAIT = 25,
        MOVE_TASK_MENU_RNO_GET_ITEM_REQ_ERROR = 26,
        MOVE_TASK_MENU_RNO_GET_ITEM_REQ_ERROR_WAIT = 27,
        MOVE_TASK_MENU_RNO_GET_ITEM_REQ_SUCCESS = 28,
        MOVE_TASK_MENU_RNO_GET_ITEM_REQ_SUCCESS_ANOUNCE = 29,
        MOVE_TASK_MENU_RNO_GET_ITEM_REQ_SUCCESS_NEXT = 30,
        MOVE_TASK_MENU_RNO_GET_ITEM_FURNITURE_ANNOUNCE_INIT = 31,
        MOVE_TASK_MENU_RNO_GET_ITEM_FURNITURE_ANNOUNCE_WAIT = 32,
        MOVE_TASK_MENU_RNO_GET_ITEM_NOTHING = 33,
        MOVE_TASK_MENU_RNO_RANKUP_INIT = 34,
        MOVE_TASK_MENU_RNO_RANKUP_WAIT = 35,
        MOVE_TASK_MENU_RNO_RANKUP_EXAM_UI_WAIT = 36,
        MOVE_TASK_MENU_RNO_RANKUP_UI_WAIT = 37,
        MOVE_TASK_MENU_RNO_RANKUP_PROGRESS_REQ = 38,
        MOVE_TASK_MENU_RNO_RANKUP_PROGRESS_WAIT = 39,
        MOVE_TASK_MENU_RNO_RANKUP_PROGRESS_REQ_END = 40,
        MOVE_TASK_MENU_RNO_PAWN_DETAIL_INIT = 41,
        MOVE_TASK_MENU_RNO_PAWN_DETAIL_WAIT = 42,
        MOVE_TASK_MENU_RNO_PAWN_LIST_REQ = 43,
        MOVE_TASK_MENU_RNO_PAWN_LIST_REQ_WAIT = 44,
        MOVE_TASK_MENU_RNO_RANKUP_END = 45,
        MOVE_TASK_MENU_RNO_END = 46,
    };
    enum
    {
        TASK_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        TASK_MENU_CURSOR_SELECT = 0,
        BAG_SELECT_CURSOR = 1,
        DUMMY_CURSOR_MAX = 2,
    };
    enum
    {
        CREATE_SELECT_DIALOG = 0,
        GOLDSTONE_SELECT_DIALOG = 1,
        ONLINE_SHOP_DIALOG = 2,
        CREATE_STOP_DIALOG = 3,
        TIMESAVING_SUCCESS_DIALOG = 4,
    };
    enum
    {
        BAG_SELECT_TYPE_PL = 0,
        BAG_SELECT_TYPE_STORAGE = 1,
        BAG_SELECT_TYPE_SELL = 2,
        BAG_SELECT_TYPE_CANCEL = 3,
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
    cMenuCraftTask();
    virtual ~cMenuCraftTask();
    void initCraftTask();
    nMenu::MENU_RET moveCraftTask();
    void setClassUp(bool isClassUp);
    bool isClassUp();
private:
    u32 mSaveIdx;  // offset: 0xb0
    u32 mGetItemIdx;  // offset: 0xb4
    bool mIsClassUp;  // offset: 0xb8
    bool mIsReceiveFurniture;  // offset: 0xb9
    MOVE_LINE mMoveLine;  // offset: 0xbc
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftUpGradeItem : public cMenuBase
{
public:
    enum
    {
        MOVE_UPGRADEITEM_MENU_RNO_INIT = 0,
        MOVE_UPGRADEITEM_MENU_RNO_SELECT = 1,
        MOVE_UPGRADEITEM_MENU_RNO_CREATE_REQ = 2,
        MOVE_UPGRADEITEM_MENU_RNO_CREATE_WAIT = 3,
        MOVE_UPGRADEITEM_MENU_RNO_CREATE_ERROR = 4,
        MOVE_UPGRADEITEM_MENU_RNO_CREATE_SUCCESS = 5,
        MOVE_UPGRADEITEM_MENU_RNO_CREATE_SUCCESS_WAIT = 6,
        MOVE_UPGRADEITEM_MENU_RNO_UPGRADE_RESULT = 7,
        MOVE_UPGRADEITEM_MENU_RNO_UPGRADE_RESULT_WAIT = 8,
        MOVE_UPGRADEITEM_MENU_RNO_RANKUP_INIT = 9,
        MOVE_UPGRADEITEM_MENU_RNO_RANKUP_WAIT = 10,
        MOVE_UPGRADEITEM_MENU_RNO_RANKUP_UI = 11,
        MOVE_UPGRADEITEM_MENU_RNO_RANKUP_PAWN_LIST_REQ = 12,
        MOVE_UPGRADEITEM_MENU_RNO_RANKUP_PAWN_LIST_REQ_WAIT = 13,
        MOVE_UPGRADEITEM_MENU_RNO_END = 14,
    };
    enum
    {
        UPGRADEITEM_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        UPGRADEITEM_MENU_CURSOR_SELECT = 0,
        DUMMY_CURSOR_MAX = 1,
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
    cMenuCraftUpGradeItem();
    virtual ~cMenuCraftUpGradeItem();
    void initCraftUpGradeItem();
    nMenu::MENU_RET moveCraftUpGradeItem();
    bool isGradeUp();
private:
    bool mIsGradeUp;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCraftUpGradeList : public cMenuBase
{
public:
    enum
    {
        MOVE_UPGRADELIST_MENU_RNO_INIT = 0,
        MOVE_UPGRADELIST_MENU_RNO_SELECT = 1,
        MOVE_UPGRADELIST_MENU_RNO_SELECT2 = 2,
        MOVE_UPGRADELIST_MENU_RNO_BAGGAGE_REQ = 3,
        MOVE_UPGRADELIST_MENU_RNO_BAGGAGE_WAIT = 4,
    };
    enum
    {
        UPGRADELIST_MENU_RNO_BASE = 0,
        DUMMY_RNO_MAX = 1,
    };
    enum
    {
        UPGRADELIST_MENU_CURSOR_SELECT = 0,
        UPGRADELIST_MENU_LIST_SELECT = 1,
        UPGRADELIST_MENU_DISP_LIST_TOP = 2,
        UPGRADELIST_MENU_CURSOR_CATEGORY_SELECT = 3,
        DUMMY_CURSOR_MAX = 4,
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
    cMenuCraftUpGradeList();
    virtual ~cMenuCraftUpGradeList();
    void initCraftUpGradeList();
    nMenu::MENU_RET moveCraftUpGradeList();
private:
    nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE mCategory;  // offset: 0xb0
    bool mIsEffect;  // offset: 0xb4
public:
    static MyDTI DTI;
    static const s32 CRAFT_DISP_NUM = 5;
};

class cMenuCreateGameSession : public cMenuBase
{
public:
    enum
    {
        MOVE_CREATE_GAME_INIT = 0,
        MOVE_CREATE_GAME_MOVE = 1,
        MOVE_CREATE_GAME_ERROR = 2,
    };
    enum
    {
        CREATE_GAME_SESSION_RNO_BASE = 0,
        CREATE_GAME_SESSION_RNO_MAX = 1,
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
    cMenuCreateGameSession();
    virtual ~cMenuCreateGameSession();
    void initCreateGameSession(s32 type);
    nMenu::MENU_RET moveCreateGameSession();
private:
    s32 mCreateType;  // offset: 0xb0
    u32 mCreateGameSessionDialogHandle;  // offset: 0xb4
public:
    static MyDTI DTI;
};

class cMenuCustomize : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_LIST_REQ = 1,
        RNO_LIST_WAIT = 2,
        RNO_EDIT = 3,
        RNO_UPDATE_PAWN = 4,
        RNO_END_CANCEL = 5,
        RNO_END = 6,
        RNO_ERROR = 7,
        RNO_NUM = 8,
    };
    enum
    {
        CUSTOMIZE_RNO_BASE = 0,
        CUSTOMIZE_RNO_MAX = 1,
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
    cMenuCustomize();
    virtual ~cMenuCustomize();
    void initCustomize(u32 pawnId, u32 prio);
    nMenu::MENU_RET moveCustomize();
private:
    u32 mPawnId;  // offset: 0xb0
    u32 mSlotNo;  // offset: 0xb4
    cCharacterData::stPawnData mBuff;  // offset: 0xb8
public:
    static MyDTI DTI;
private:
    static const s32 edit_target[];
};

class cMenuDispStatus : public cMenuBase
{
public:
    enum
    {
        DISP_TYPE_STATUS = 0,
        DISP_TYPE_CARD = 1,
        DISP_TYPE_HISTORY = 2,
    };
    enum
    {
        CHAR_TYPE_PLAYER = 0,
        CHAR_TYPE_PAWN = 1,
    };
    enum
    {
        PAWN_TYPE_MAIN = 0,
        PAWN_TYPE_SUPPORT = 1,
        PAWN_TYPE_REGISTERD = 2,
    };
    enum
    {
        DISP_STATUS_CURSOR_SELECT = 0,
        DISP_STATUS_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_PAWN_DATA_WAIT = 2,
        RNO_CHAR_DATA_WAIT = 3,
        RNO_CHAR_DATA_SET = 4,
        RNO_WAIT = 5,
        RNO_DISP = 6,
        RNO_ERROR = 7,
    };
    enum
    {
        DISP_STATUS_RNO_BASE = 0,
        DISP_STATUS_RNO_MAX = 1,
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
    cMenuDispStatus();
    virtual ~cMenuDispStatus();
    void initDispStatus(s32 dispType, const cContextInstHm& context, u32 prio, bool isChatSubMenu);
    void initDispStatus(s32 dispType, s32 charType, s32 masterId, s32 pawnType, u32 prio, bool isChatSubMenu);
    void initParam();
    nMenu::MENU_RET moveDispStatus();
    bool isReqdyData();
    const cCharacterData* getCharData();
    const cCharacterData::stPawnData* getPawnData();
    const cContextInstHm* getContext();
    bool isPlayerInfo();
    u32 getMasterId();
    bool isMyPawn();
    u32 getPawnType();
    u32 getPawnOwnerCharacterId();
private:
    s32 mDispType;  // offset: 0xb0
    s32 mCharType;  // offset: 0xb4
    u32 mMasterId;  // offset: 0xb8
    s32 mPawnType;  // offset: 0xbc
    s32 mPawnOwnerCharacterId;  // offset: 0xc0
    s32 mComId;  // offset: 0xc4
    u32 mBasePointerPrio;  // offset: 0xc8
    bool mIsMyPawn;  // offset: 0xcc
    bool mIsPartyPawn;  // offset: 0xcd
    bool mIsChatSubMenu;  // offset: 0xce
    cContextInstHm mContext;  // offset: 0xd0
    const cContextInstHm* mpRefContext;  // offset: 0x4260
    cCharacterData* mpRefCharData;  // offset: 0x4268
    const cCharacterData::stPawnData* mpRefPawnData;  // offset: 0x4270
    cCharacterData mCharData;  // offset: 0x4278
public:
    static MyDTI DTI;
};

class cMenuEditBlackList : public cMenuBase
{
public:
    enum
    {
        TYPE_ADD = 0,
        TYPE_REMOVE = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_REQ_WAIT = 2,
        RNO_ERROR = 3,
        RNO_RESULT = 4,
    };
    enum
    {
        EDIT_BLACKLIST_RNO_BASE = 0,
        EDIT_BLACKLIST_RNO_MAX = 1,
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
    cMenuEditBlackList();
    virtual ~cMenuEditBlackList();
    void initEditBlackList(u32 type, CCommunityCharacterBaseInfo& baseInfo);
    nMenu::MENU_RET moveEditBlackList();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mType;  // offset: 0xb0
    CCommunityCharacterBaseInfo mBaseInfo;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuEditFavoritePawn : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        EDIT_FAVORITE_PAWN_RNO_BASE = 0,
        EDIT_FAVORITE_PAWN_RNO_MAX = 1,
    };
    enum
    {
        TYPE_ADD = 0,
        TYPE_REMOVE = 1,
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
    cMenuEditFavoritePawn();
    virtual ~cMenuEditFavoritePawn();
    void initEditFavoritePawn(u32 type, u32 pawnId, MtString& pawnName);
    nMenu::MENU_RET moveEditFavoritePawn();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mType;  // offset: 0xb0
    u32 mPawnId;  // offset: 0xb4
    MtString mPawnName;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuEntryGameSession : public cMenuBase
{
public:
    enum
    {
        MOVE_ENTRY_GAME_INIT = 0,
        MOVE_ENTRY_GAME_MOVE = 1,
        MOVE_ENTRY_GAME_ERROR = 2,
    };
    enum
    {
        ENTRY_GAME_SESSION_RNO_BASE = 0,
        ENTRY_GAME_SESSION_RNO_MAX = 1,
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
    cMenuEntryGameSession();
    virtual ~cMenuEntryGameSession();
    void initEntryGameSession(bool flag);
    nMenu::MENU_RET moveEntryGameSession();
private:
    u32 mEntryGameSessionDialogHandle;  // offset: 0xb0
    bool mIsEntry;  // offset: 0xb4
public:
    static MyDTI DTI;
};

class cMenuFavoriteFriend : public cMenuBase
{
public:
    enum
    {
        MOVE_FAVORITE_FRIEND_RNO_DLG_FLOW = 0,
    };
    enum
    {
        FAVORITE_FRIEND_RNO_BASE = 0,
        FAVORITE_FRIEND_RNO_MAX = 1,
    };
    enum
    {
        FAVORITE_FRIEND_TYPE_ON = 0,
        FAVORITE_FRIEND_TYPE_OFF = 1,
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
    cMenuFavoriteFriend();
    virtual ~cMenuFavoriteFriend();
    void initFavoriteFriend(u32 friendNo, MtString& charFirstName, MtString& charLastName, bool nowFavorite);
    nMenu::MENU_RET moveFavoriteFriend();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mType;  // offset: 0xb0
    u32 mFriendNo;  // offset: 0xb4
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuFirstOption : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_MOVE_UI_LARGE_INIT = 1,
        RNO_MOVE_UI_LARGE_WAIT = 2,
        RNO_SELECT_DEVICE = 3,
        RNO_MOVE_OPTION_SELECT = 4,
        RNO_MOVE_CALIBRATION_ANNOUNCE = 5,
        RNO_MOVE_CALIBRATION_ANNOUNCE_WAIT = 6,
        RNO_MOVE_CALIBRATION_INIT = 7,
        RNO_MOVE_CALIBRATION_WAIT = 8,
        RNO_MOVE_OPTION_INIT = 9,
        RNO_MOVE_OPTION_WAIT = 10,
        RNO_SELECT_SAVE = 11,
        RNO_SELECT_SAVE_WAIT = 12,
        RNO_MOVE_SAVE = 13,
        RNO_MOVE_SAVE_WAIT = 14,
        RNO_END = 15,
    };
    enum
    {
        MENU_RNO_MAIN_BASE = 0,
        MENU_RNO_MAX = 1,
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
    cMenuFirstOption();
    virtual ~cMenuFirstOption();
    void initFirstOption();
    nMenu::MENU_RET moveFirstOption();
    virtual void exitMenu();  // vtable slot 15
private:
    void setDisableMenu();
public:
    static MyDTI DTI;
};

class cMenuFriendList : public cMenuBase
{
public:
    enum LIST_TYPE
    {
        LIST_TYPE_APPLYING = 0,
        LIST_TYPE_APPROVING = 1,
        LIST_TYPE_FRIEND = 2,
    };
    enum
    {
        FRIEND_LIST_CURSOR_LIST = 0,
        FRIEND_LIST_CURSOR_LIST_PAGE = 1,
        FRIEND_LIST_CURSOR_MAX = 2,
    };
    enum
    {
        MOVE_FRIEND_LIST_RNO_INIT = 0,
        MOVE_FRIEND_LIST_RNO_REQ = 1,
        MOVE_FRIEND_LIST_RNO_WAIT = 2,
        MOVE_FRIEND_LIST_RNO_LIST = 3,
        MOVE_FRIEND_LIST_RNO_SUB_MENU = 4,
        MOVE_FRIEND_LIST_RNO_LIST_ERROR = 5,
    };
    enum
    {
        FRIEND_LIST_RNO_BASE = 0,
        FRIEND_LIST_RNO_MAX = 1,
    };
    enum
    {
        TYPE_NORMAL = 0,
        TYPE_RET_NAME = 1,
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
    cMenuFriendList();
    virtual ~cMenuFriendList();
    virtual void exitMenu();  // vtable slot 15
    void initFriendList(uGUIBase* pRefGUI, u32 type, nCharacterData::stCharacterName* pDstName, u32* pCharacterId, CommunityCharacterBaseInfoVec* pExcludeList);
    nMenu::MENU_RET moveFriendList();
    u32 getPageNum();
    u32 getListIndex(u32 page, u32 cursor);
    LIST_TYPE getListType(u32 index);
    u32 getSortIndex(u32 index);
    u32 getSortCount();
    bool getRemakeListFlag();
    u32 getFriendListDispNum();
    s32 getRno();
private:
    void createSortList();
    void createMenuList();
private:
    u32 mType;  // offset: 0xb0
    nCharacterData::stCharacterName* mpDstName;  // offset: 0xb8
    u32* mpDstCharacterId;  // offset: 0xc0
    CommunityCharacterBaseInfoVec* mpExcludeList;  // offset: 0xc8
    u32* mpSortList;  // offset: 0xd0
    u32 mSortListCount;  // offset: 0xd8
    bool mIsRemakeList;  // offset: 0xdc
public:
    static MyDTI DTI;
};

class cMenuGetAreaMasterInfo : public cMenuBase
{
public:
    enum
    {
        MOVE_GET_AREA_MASTER_INFO_RNO_INIT = 0,
        MOVE_GET_AREA_MASTER_INFO_RNO_REQ_WAIT = 1,
        MOVE_GET_AREA_MASTER_INFO_RNO_WAIT = 2,
    };
    enum
    {
        GET_AREA_MASTER_INFO_RNO_BASE = 0,
        GET_AREA_MASTER_INFO_RNO_MAX = 1,
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
    cMenuGetAreaMasterInfo();
    virtual ~cMenuGetAreaMasterInfo();
    void initGetAreaMasterInfo();
    nMenu::MENU_RET moveGetAreaMasterInfo();
private:
    u32 mPoint;  // offset: 0xb0
    u32 mRank;  // offset: 0xb4
    u32 mWeek;  // offset: 0xb8
    u32 mLastWeek;  // offset: 0xbc
    u32 mToNextPoint;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuGetBlackList : public cMenuBase
{
public:
    enum
    {
        GET_BLACK_LIST_CURSOR_SELECT = 0,
        GET_BLACK_LIST_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_ERROR = 3,
    };
    enum
    {
        GET_BLACK_LIST_RNO_BASE = 0,
        GET_BLACK_LIST_RNO_MAX = 1,
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
    cMenuGetBlackList();
    virtual ~cMenuGetBlackList();
    void initGetBlackList();
    nMenu::MENU_RET moveGetBlackList();
public:
    static MyDTI DTI;
};

class cMenuGetCharacterName : public cMenuBase
{
public:
    enum
    {
        TYPE_NORMAL = 0,
        TYPE_COMMUNITY = 1,
        TYPE_FRIEND = 2,
        TYPE_CLAN = 3,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
        RNO_INIT_FRIEND = 2,
        RNO_FRIEND = 3,
        RNO_INIT_CLAN = 4,
        RNO_CLAN = 5,
    };
    enum
    {
        GET_CHARACTER_NAME_RNO_BASE = 0,
        GET_CHARACTER_NAME_RNO_MAX = 1,
    };
    enum
    {
        GET_CHARACTER_NAME_CURSOR_SELECT = 0,
        GET_CHARACTER_NAME_CURSOR_MAX = 1,
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
    cMenuGetCharacterName();
    virtual ~cMenuGetCharacterName();
    void initGetCharacterName(u32 type, nCharacterData::stCharacterName& dstName, u32* pCharacterId, CommunityCharacterBaseInfoVec* pExcludeList);
    nMenu::MENU_RET moveGetCharacterName();
private:
    u32 mType;  // offset: 0xb0
    nCharacterData::stCharacterName* mpDstName;  // offset: 0xb8
    u32* mpDstCharacterId;  // offset: 0xc0
    CommunityCharacterBaseInfoVec* mpExcludeList;  // offset: 0xc8
    u32 mHidePointerPrio;  // offset: 0xd0
    u32 mNextPointerPriority;  // offset: 0xd4
public:
    static MyDTI DTI;
};

class cMenuGetCraftRecipeToServer : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
    };
    enum
    {
        GET_CRAFT_RECIPE_RNO_BASE = 0,
        GET_CRAFT_RECIPE_RNO_RNO_MAX = 1,
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
    cMenuGetCraftRecipeToServer();
    virtual ~cMenuGetCraftRecipeToServer();
    void initGetCraftRecipeToServer(sCraftManager::RECIPE_TYPE type, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    nMenu::MENU_RET moveGetCraftRecipeToServer();
    void setRecipeType(sCraftManager::RECIPE_TYPE type, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
private:
    u32 mType;  // offset: 0xb0
    u32 mCategory;  // offset: 0xb4
    bool mIsEnd;  // offset: 0xb8
    s32 mMenuList[8];  // offset: 0xbc
    nMenu::MENU_PARTS mMenuParts[8];  // offset: 0xdc
public:
    static MyDTI DTI;
    static const u32 DISP_LIST_MAX = 5;
};

class cMenuGetFriendList : public cMenuBase
{
public:
    enum
    {
        MOVE_GET_FRIEND_LIST_RNO_INIT = 0,
        MOVE_GET_FRIEND_LIST_RNO_REQ_WAIT = 1,
        MOVE_GET_FRIEND_LIST_RNO_ERROR = 2,
    };
    enum
    {
        GET_FRIEND_LIST_RNO_BASE = 0,
        GET_FRIEND_LIST_RNO_MAX = 1,
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
    cMenuGetFriendList();
    virtual ~cMenuGetFriendList();
    void initGetFriendList();
    nMenu::MENU_RET moveGetFriendList();
public:
    static MyDTI DTI;
};

class cMenuGetItemBaggageListToServer : public cMenuBase
{
public:
    enum
    {
        GET_ITEM_LIST_RNO_BASE = 0,
        GET_ITEM_LIST_RNO_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ_SERVER_SORTDATA = 1,
        RNO_WAIT_SERVER_SORTDATA = 2,
        RNO_REQ_SERVER = 3,
        RNO_WAIT_SERVER = 4,
        RNO_EXIT = 5,
        RNO_ERROR = 6,
    };
    enum
    {
        ITEM_DATA_SERVER_RESULT_REQ = 0,
        ITEM_DATA_SERVER_RESULT_WAIT = 1,
        ITEM_DATA_SERVER_RESULT_SUCCESS = 2,
        ITEM_DATA_SERVER_RESULT_ERROR = 3,
        ITEM_DATA_SERVER_RESULT_NUM = 4,
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
    cMenuGetItemBaggageListToServer();
    virtual ~cMenuGetItemBaggageListToServer();
    void initGetItemBaggageListToServer(sItemManager::STORAGE_FILLTER_TYPE type);
    nMenu::MENU_RET moveGetItemBaggageListToServer();
private:
    void itemListGetCallBack(void* param);
private:
    CommonU32Vec mStorageList;  // offset: 0xb0
    u32 mBagIdx;  // offset: 0xd0
    u32 mBagNum;  // offset: 0xd4
    u32 mServerResult;  // offset: 0xd8
public:
    static MyDTI DTI;
};

class cMenuGetItemListToServer : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ_SERVER_SORTDATA = 1,
        RNO_WAIT_SERVER_SORTDATA = 2,
        RNO_REQ_SERVER = 3,
        RNO_WAIT_SERVER = 4,
        RNO_REQ_ADD_EQUIP = 5,
        RNO_WAIT_ADD_EQUIP = 6,
        RNO_GP_REQ_SERVER = 7,
        RNO_GP_REQ_WAIT_SERVER = 8,
        RNO_EQUIP_REQ_SERVER = 9,
        RNO_EQUIP_WAIT_SERVER = 10,
        RNO_ERROR = 11,
    };
    enum
    {
        GET_ITEM_LIST_RNO_BASE = 0,
        GET_ITEM_LIST_RNO_MAX = 1,
    };
    enum
    {
        ITEM_DATA_SERVER_RESULT_REQ = 0,
        ITEM_DATA_SERVER_RESULT_WAIT = 1,
        ITEM_DATA_SERVER_RESULT_SUCCESS = 2,
        ITEM_DATA_SERVER_RESULT_ERROR = 3,
        ITEM_DATA_SERVER_RESULT_NUM = 4,
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
    cMenuGetItemListToServer();
    virtual ~cMenuGetItemListToServer();
    void initGetItemListToServer();
    nMenu::MENU_RET moveGetItemListToServer();
private:
    void itemListGetCallBack(void* param);
    void goldGetCallBack(void* param);
    void rimGetCallBack(void* param);
    void dogmaGetCallBack(void* param);
private:
    CommonU32Vec mStorageList;  // offset: 0xb0
    u32 mBagIdx;  // offset: 0xd0
    u32 mBagNum;  // offset: 0xd4
    u32 mServerResult;  // offset: 0xd8
public:
    static MyDTI DTI;
};

class cMenuGetMailList : public cMenuBase
{
public:
    enum
    {
        GET_MAIL_LIST_CURSOR_SELECT = 0,
        GET_MAIL_LIST_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT_HEAD = 2,
        RNO_WAIT_DATA = 3,
        RNO_WAIT_FOOT = 4,
        RNO_ERROR = 5,
    };
    enum
    {
        GET_MAIL_LIST_RNO_BASE = 0,
        GET_MAIL_LIST_RNO_MAX = 1,
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
    cMenuGetMailList();
    virtual ~cMenuGetMailList();
    void initGetMailList(bool newMailOnly);
    nMenu::MENU_RET moveGetMailList();
private:
    bool mSystemMailFlag;  // offset: 0xb0
    bool mNewMailOnly;  // offset: 0xb1
    s32 mComId;  // offset: 0xb4
public:
    static MyDTI DTI;
};

class cMenuGetMatchingProfile : public cMenuBase
{
public:
    enum
    {
        MOVE_GET_MATCHING_PROFILE_RNO_INIT = 0,
        MOVE_GET_MATCHING_PROFILE_RNO_WAIT = 1,
        MOVE_GET_MATCHING_PROFILE_RNO_ERROR = 2,
    };
    enum
    {
        GET_MATCHING_PROFILE_RNO_BASE = 0,
        GET_MATCHING_PROFILE_RNO_MAX = 1,
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
    cMenuGetMatchingProfile();
    virtual ~cMenuGetMatchingProfile();
    void initGetMatchingProfile(u32 characterId, cCharacterData::stMatchProfile* pDstProfile, u8* pJob, u32* pLv);
    nMenu::MENU_RET moveGetMatchingProfile();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mCharId;  // offset: 0xb0
    cCharacterData::stMatchProfile* mpMatchProfile;  // offset: 0xb8
    u8* mpJob;  // offset: 0xc0
    u32* mpLv;  // offset: 0xc8
public:
    static MyDTI DTI;
};

class cMenuGetOrbGainExtendParam : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_ERROR = 3,
    };
    enum
    {
        GET_ORB_GAIN_EXTEND_PARAM_RNO_BASE = 0,
        GET_ORB_GAIN_EXTEND_PARAM_RNO_MAX = 1,
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
    cMenuGetOrbGainExtendParam();
    virtual ~cMenuGetOrbGainExtendParam();
    void initGetOrbGainExtendParam();
    nMenu::MENU_RET moveGetOrbGainExtendParam();
public:
    static MyDTI DTI;
};

class cMenuGetPawnName : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
        RNO_MAIN = 2,
        RNO_SUPPORT = 3,
    };
    enum
    {
        GET_PAWN_NAME_RNO_BASE = 0,
        GET_PAWN_NAME_RNO_MAX = 1,
    };
    enum
    {
        GET_PAWN_NAME_CURSOR_SELECT = 0,
        GET_PAWN_NAME_CURSOR_MAX = 1,
    };
    enum
    {
        ERR_UNKNOWN = 0,
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
    cMenuGetPawnName();
    virtual ~cMenuGetPawnName();
    void initGetPawnName(u32 type, MtString& dstName);
    nMenu::MENU_RET moveGetPawnName();
private:
    u32 mType;  // offset: 0xb0
    MtString* mpDstName;  // offset: 0xb8
    s32 mMenuList[2];  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuGetRecentList : public cMenuBase
{
public:
    enum
    {
        GET_RECENT_LIST_CURSOR_SELECT = 0,
        GET_RECENT_LIST_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_ERROR = 3,
    };
    enum
    {
        GET_RECENT_LIST_RNO_BASE = 0,
        GET_RECENT_LIST_RNO_MAX = 1,
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
    cMenuGetRecentList();
    virtual ~cMenuGetRecentList();
    void initGetRecentList();
    nMenu::MENU_RET moveGetRecentList();
public:
    static MyDTI DTI;
};

class cMenuGroupChatMemberList : public cMenuBase
{
public:
    enum
    {
        GROUP_CHAT_MEMBER_LIST_CURSOR_LIST = 0,
        GROUP_CHAT_MEMBER_LIST_CURSOR_LIST_PAGE = 1,
        GROUP_CHAT_MEMBER_LIST_CURSOR_MAX = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_LIST_INIT = 2,
        RNO_LIST = 3,
        RNO_SUB_MENU = 4,
        RNO_LEAVE = 5,
        RNO_INVITE_LIST = 6,
        RNO_INVITE = 7,
    };
    enum
    {
        GROUP_CHAT_MEMBER_LIST_RNO_BASE = 0,
        GROUP_CHAT_MEMBER_LIST_RNO_MAX = 1,
    };
    enum
    {
        GROUP_CHAT_MEMBER_LIST_TOP = 0,
        GROUP_CHAT_MEMBER_LIST_INVITE = 15,
        GROUP_CHAT_MEMBER_LIST_LEAVE = 16,
        GROUP_CHAT_MEMBER_LIST_MAX = 17,
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
    cMenuGroupChatMemberList();
    virtual ~cMenuGroupChatMemberList();
    void initGroupChatMemberList();
    nMenu::MENU_RET moveGroupChatMemberList();
    virtual void updatePtr();  // vtable slot 6
    virtual void exitMenu();  // vtable slot 15
    virtual void setPage(s32 page);  // vtable slot 7
    u32 getPageNum();
    u32 getListIndex(u32 page, u32 cursor);
    u32 getRefIndex(u32 page, u32 cursor);
    CharacterListElementVec& getMemberList();
    u32 getSortIndex(u32 index);
    u32 getPageMemberNum();
    u32 getAllMemberNum();
private:
    void createSortList();
    void createMenuList();
private:
    u32* mpSortList;  // offset: 0xb0
    u32 mSortListCount;  // offset: 0xb8
    CharacterListElementVec mMemberList;  // offset: 0xc0
    CommunityCharacterBaseInfoVec mExcludeList;  // offset: 0xe0
    uGUIBase* mpGUIActiveList;  // offset: 0x100
    s32 mMenuList[17];  // offset: 0x108
    nMenu::MENU_PARTS mMenuParts[17];  // offset: 0x14c
public:
    static MyDTI DTI;
    static const s32 GROUP_CHAT_MEMBER_LIST_DISP_NUM = 15;
};

class cMenuInvite : public cMenuBase
{
public:
    enum
    {
        INVITE_TYPE_PARTY = 0,
        INVITE_TYPE_MY_PAWN = 1,
        INVITE_TYPE_RENTAL_PAWN = 2,
        INVITE_TYPE_PL = 3,
    };
    enum
    {
        MOVE_INVITE_RNO_INIT = 0,
        MOVE_INVITE_RNO_DLG_FLOW = 1,
        MOVE_INVITE_RNO_PARTY_REQ = 2,
    };
    enum
    {
        INVITE_RNO_BASE = 0,
        INVITE_RNO_MAX = 1,
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
    cMenuInvite();
    virtual ~cMenuInvite();
    void initInvite(s32 inviteType, cPawnListParam* pParam);
    void initInvite(s32 inviteType, CDataClientPartyListInfo* pParam);
    void initInvite(s32 inviteType, u32 characterId, CHAR_NAME* pCharacterName);
    void initInviteCore(s32 inviteType, cPawnListParam* pPawnParam, CDataClientPartyListInfo* pPartyParam, u32 characterId, CHAR_NAME* pCharacterName);
    nMenu::MENU_RET moveInvite();
private:
    s32 mInviteType;  // offset: 0xb0
    u32 mCharacterId;  // offset: 0xb4
    cPawnListParam* mpPawnParam;  // offset: 0xb8
    CDataClientPartyListInfo* mpPartyParam;  // offset: 0xc0
    CHAR_NAME mCharacterName;  // offset: 0xc8
public:
    static MyDTI DTI;
};

class cMenuInviteGroupChat : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_REQ_WAIT = 2,
        RNO_ERROR = 3,
        RNO_RESULT = 4,
    };
    enum
    {
        INVITE_GROUP_CHAT_RNO_BASE = 0,
        INVITE_GROUP_CHAT_RNO_MAX = 1,
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
    cMenuInviteGroupChat();
    virtual ~cMenuInviteGroupChat();
    void initInviteGroupChat(u32 charId, MtString& friendFirstName, MtString& friendLastName);
    nMenu::MENU_RET moveInviteGroupChat();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mCharacterId;  // offset: 0xb0
    MtString mFirstName;  // offset: 0xb8
    MtString mLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuJoinGameSession : public cMenuBase
{
public:
    enum
    {
        MOVE_JOIN_GAME_INIT = 0,
        MOVE_JOIN_GAME_MOVE = 1,
        MOVE_JOIN_GAME_ERROR = 2,
    };
    enum
    {
        JOIN_GAME_SESSION_RNO_BASE = 0,
        JOIN_GAME_SESSION_RNO_MAX = 1,
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
    cMenuJoinGameSession();
    virtual ~cMenuJoinGameSession();
    void initJoinGameSession(u32 joinType);
    nMenu::MENU_RET moveJoinGameSession();
private:
    u32 mJoinGameSessionDialogHandle;  // offset: 0xb0
    u32 mJoinType;  // offset: 0xb4
public:
    static MyDTI DTI;
};

class cMenuJoinPartyFlow : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_ENTRY = 1,
        RNO_WAIT = 2,
        RNO_JUMP = 3,
        RNO_DIALOG_WAIT = 4,
        RNO_ERROR = 5,
    };
    enum
    {
        JOIN_PARTY_RNO_BASE = 0,
        JOIN_PARTY_RNO_MAX = 1,
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
    cMenuJoinPartyFlow();
    virtual ~cMenuJoinPartyFlow();
    void initJoinPartyFlow();
    nMenu::MENU_RET moveJoinPartyFlow();
    virtual void exitMenu();  // vtable slot 15
private:
    s32 getRno();
public:
    static MyDTI DTI;
};

class cMenuKeyConfig : public cMenuBase, public nGUIKeyConfig::cInputEventHandler
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SHOW_GUI = 1,
        RNO_WAIT_GUI = 2,
        RNO_CLOSE_GUI = 3,
        RNO_WAIT_DIALOG_INIT = 4,
        RNO_WAIT_DIALOG_EXIT = 5,
        RNO_WAIT_DIALOG_COPY = 6,
        RNO_WAIT_DIALOG_WARNING = 7,
        RNO_WAIT_DIALOG_BLANK_ALL = 8,
        RNO_SUB_MENU_KEY_LIST = 9,
        RNO_SUB_MENU_CATEGORY_LIST = 10,
        RNO_RENAME_CATEGORY = 11,
        RNO_COPY_CATEGORY = 12,
        RNO_ERROR = 13,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
    };
    enum DIALOG_CONFIRM_ITEM_INDEX
    {
        DIALOG_CONFIRM_ITEM_YES = 0,
        DIALOG_CONFIRM_ITEM_NO = 1,
    };
    enum DIALOG_EXIT_ITEM_INDEX
    {
        DIALOG_EXIT_ITEM_RESTORE = 0,
        DIALOG_EXIT_ITEM_CANCEL = 1,
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
    cMenuKeyConfig();
    virtual ~cMenuKeyConfig();
    void init(nMenuKeyConfig::KeyCustomManagers* keyCustomManagers);
    nMenu::MENU_RET move();
    virtual void exitMenu();  // vtable slot 15
private:
    bool showGUI(uGUIKeyConfig& guiKeyConfig);
    void waitGUI(uGUIKeyConfig& guiKeyConfig);
    virtual void onClose(uGUIKeyConfig& guiKeyConfig);  // vtable slot 19
    virtual void onInitialize(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 20
    virtual void onBlankAll(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 21
    virtual void onUndo(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex, nGUIKeyConfig::Key key);  // vtable slot 22
    virtual void onChangeCategory(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 23
    virtual void onChangeKey(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex, nGUIKeyConfig::Key key);  // vtable slot 24
    virtual void onChangeSortType(uGUIKeyConfig& guiKeyConfig, nGUIKeyConfig::SORT_TYPE sortType);  // vtable slot 25
    virtual void onKeyListSubMenu(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex);  // vtable slot 26
    virtual void onCategoryListSubMenu(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 27
    void initializeSetting(uGUIKeyConfig& guiKeyConfig);
    void applySetting(uGUIKeyConfig& guiKeyConfig);
    void copySetting(uGUIKeyConfig& guiKeyConfig);
    void setBlankAll(uGUIKeyConfig& guiKeyConfig);
    void updateCategoryState(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);
    void initializeKeyCustomManager(u32 categoryListIndex);
    void applyKeyCustomManager(u32 categoryListIndex);
    void finalCheckBeforeExit();
private:
    nMenuKeyConfig::KeyCustomManagers* mBaseKeyCustomManagers;  // offset: 0xb8
    nMenuKeyConfig::KeyCustomManagers mKeyCustomManagers;  // offset: 0xc0
    u32 mSrcCopyCategoryListIndex;  // offset: 0xd8
    u32 mDstCopyCategoryListIndex;  // offset: 0xdc
public:
    static MyDTI DTI;
};

class cMenuKeyConfigCopyCategory : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SHOW_GUI = 1,
        RNO_WAIT_GUI = 2,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
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
    cMenuKeyConfigCopyCategory();
    virtual ~cMenuKeyConfigCopyCategory();
    void init(uGUIBase& parent, u32 categoryListIndex, const nMenuKeyConfig::KeyCustomManagers* keyCustomManagers);
    nMenu::MENU_RET move();
    u32 getSelectIndex() const;
protected:
    void initGUI(uGUIBase& parent);
    bool showGUI(uGUISystemMsg& dialog);
    nMenu::MENU_RET waitGUI(uGUISystemMsg& dialog);
protected:
    const nMenuKeyConfig::KeyCustomManagers* mKeyCustomManagers;  // offset: 0xb0
    u32 mCategoryListIndex;  // offset: 0xb8
    u32 mSelectIndex;  // offset: 0xbc
public:
    static MyDTI DTI;
};

class cMenuKeyConfigRenameCategory : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SHOW_GUI = 1,
        RNO_WAIT_GUI = 2,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
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
    cMenuKeyConfigRenameCategory();
    virtual ~cMenuKeyConfigRenameCategory();
    void init(uGUIBase& parent, MT_CTSTR currentName);
    nMenu::MENU_RET move();
    MT_CTSTR getName() const;
protected:
    void initGUI(uGUIBase& parent);
    bool showGUI(uGUIDialogTextBox& dialog);
    nMenu::MENU_RET waitGUI(uGUIDialogTextBox& dialog);
protected:
    MtStringEx<49> mName;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuKeyConfigSubMenu : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SHOW_GUI = 1,
        RNO_WAIT_GUI = 2,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
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
    cMenuKeyConfigSubMenu();
    virtual ~cMenuKeyConfigSubMenu();
    void init(uGUIBase& parent);
    nMenu::MENU_RET move();
protected:
    void initGUI(uGUIBase& parent);
    bool showGUI(uGUIPopCmd01& subMenu);
    nMenu::MENU_RET waitGUI(uGUIPopCmd01& subMenu);
    // Address: 0x01974a90 - 0x01974a91 (1 bytes)
    virtual void onShow(uGUIPopCmd01& subMenu) {}  // vtable slot 19
    // Address: 0x01974aa0 - 0x01974aa1 (1 bytes)
    virtual void onDecide(uGUIPopCmd01& subMenu) {}  // vtable slot 20
public:
    static MyDTI DTI;
};

class cMenuKeyConfigSubMenuCategoryList : public cMenuKeyConfigSubMenu
{
public:
    enum ITEM_INDEX
    {
        ITEM_RENAME = 0,
        ITEM_COPY = 1,
        ITEM_NUM = 2,
        ITEM_INVALID = -1,
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
    cMenuKeyConfigSubMenuCategoryList();
    virtual ~cMenuKeyConfigSubMenuCategoryList();
    void init(uGUIBase& parent);
    ITEM_INDEX getItemIndex() const;
private:
    virtual void onShow(uGUIPopCmd01& subMenu);  // vtable slot 19
    virtual void onDecide(uGUIPopCmd01& subMenu);  // vtable slot 20
private:
    ITEM_INDEX mItemIndex;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuKeyConfigSubMenuKeyList : public cMenuKeyConfigSubMenu
{
public:
    enum ITEM_INDEX
    {
        ITEM_BLANK = 0,
        ITEM_RESTORE = 1,
        ITEM_DEFAULT = 2,
        ITEM_NUM = 3,
        ITEM_INVALID = -1,
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
    cMenuKeyConfigSubMenuKeyList();
    virtual ~cMenuKeyConfigSubMenuKeyList();
    void init(uGUIBase& parent, bool isChangeAllowed, bool isBlankAllowed);
    ITEM_INDEX getItemIndex() const;
private:
    virtual void onShow(uGUIPopCmd01& subMenu);  // vtable slot 19
    virtual void onDecide(uGUIPopCmd01& subMenu);  // vtable slot 20
private:
    bool mIsChangeAllowed;  // offset: 0xb0
    bool mIsBlankAllowed;  // offset: 0xb1
    ITEM_INDEX mItemIndex;  // offset: 0xb4
public:
    static MyDTI DTI;
};

class cMenuKeyJobLink : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SHOW_GUI = 1,
        RNO_WAIT_GUI = 2,
        RNO_WAIT_DIALOG = 3,
        RNO_ERROR = 4,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
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
    cMenuKeyJobLink();
    virtual ~cMenuKeyJobLink();
    void init(MT_CTSTR windowTitle, MT_CTSTR decideButtonTitle, MT_CTSTR pulldownNameFormat, u8(*keyJobLinks)[10], const nMenuKeyConfig::KeyCustomManagers* keyCustomManagers);
    nMenu::MENU_RET move();
    virtual void exitMenu();  // vtable slot 15
private:
    void initGUI();
    bool showGUI(uGUIPopFilter& guiPopFilter);
    bool waitGUI(uGUIPopFilter& guiPopFilter);
private:
    MtString mWindowTitle;  // offset: 0xb0
    MtString mDecideButtonTitle;  // offset: 0xb8
    MtString mPulldownNameFormat;  // offset: 0xc0
    MtString mPulldownNames[10];  // offset: 0xc8
    u8(*mKeyJobLinks)[10];  // offset: 0x118
    const nMenuKeyConfig::KeyCustomManagers* mBaseKeyCustomManagers;  // offset: 0x120
public:
    static MyDTI DTI;
};

class cMenuKickGroupChat : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_REQ_WAIT = 2,
        RNO_ERROR = 3,
        RNO_RESULT = 4,
    };
    enum
    {
        KICK_GROUP_CHAT_RNO_BASE = 0,
        KICK_GROUP_CHAT_RNO_MAX = 1,
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
    cMenuKickGroupChat();
    virtual ~cMenuKickGroupChat();
    void initKickGroupChat(u32 charId, MtString& friendFirstName, MtString& friendLastName);
    nMenu::MENU_RET moveKickGroupChat();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mCharacterId;  // offset: 0xb0
    MtString mFirstName;  // offset: 0xb8
    MtString mLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuLeaveGroupChat : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_REQ_WAIT = 2,
        RNO_ERROR = 3,
        RNO_RESULT = 4,
    };
    enum
    {
        LEAVE_GROUP_CHAT_RNO_BASE = 0,
        LEAVE_GROUP_CHAT_RNO_MAX = 1,
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
    cMenuLeaveGroupChat();
    virtual ~cMenuLeaveGroupChat();
    void initLeaveGroupChat();
    nMenu::MENU_RET moveLeaveGroupChat();
    virtual void exitMenu();  // vtable slot 15
public:
    static MyDTI DTI;
};

class cMenuLeaveOnTheWay : public cMenuBase
{
public:
    enum
    {
        MOVE_LEAVE_ON_THE_WAY_RNO_INIT = 0,
        MOVE_LEAVE_ON_THE_WAY_RNO_PROPOSAL = 1,
        MOVE_LEAVE_ON_THE_WAY_RNO_VOTE = 2,
    };
    enum
    {
        LEAVE_ON_THE_WAY_RNO_BASE = 0,
        LEAVE_ON_THE_WAY_RNO_MAX = 1,
    };
    enum
    {
        GUI_PROPOSAL = 0,
        GUI_VOTE = 1,
        GUI_MAX = 2,
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
    cMenuLeaveOnTheWay();
    virtual ~cMenuLeaveOnTheWay();
    void initLeaveOnTheWay();
    nMenu::MENU_RET moveLeaveOnTheWay();
    virtual void exitMenu();  // vtable slot 15
    void createSelectDialog(u32 type);
public:
    static MyDTI DTI;
};

class cMenuLostPawnList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_SUB_MENU = 4,
        RNO_ERROR = 5,
    };
    enum
    {
        LOST_PAWN_LIST_RNO_BASE = 0,
        LOST_PAWN_LIST_RNO_MAX = 1,
    };
    enum
    {
        LOST_PAWN_LIST_TYPE_LIST = 0,
        LOST_PAWN_LIST_TYPE_REVIVE = 1,
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
    cMenuLostPawnList();
    virtual ~cMenuLostPawnList();
    void initLostPawnList(s32 type);
    nMenu::MENU_RET moveLostPawnList();
private:
    s32 mLostPawnListType;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const s32 LOST_PAWN_DISP_NUM = 10;
    static const s32 LOST_PAWN_LIST_MAX = 256;
};

class cMenuLostPawnRevive : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        LOST_PAWN_REVIVE_RNO_BASE = 0,
        LOST_PAWN_REVIVE_RNO_MAX = 1,
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
    cMenuLostPawnRevive();
    virtual ~cMenuLostPawnRevive();
    void initLostPawnRevive(u32 pawnId, MT_CTSTR pPawnName, u32 useRim);
    nMenu::MENU_RET moveLostPawnRevive();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mPawnId;  // offset: 0xb0
    u32 mUseRim;  // offset: 0xb4
    MtString mPawnName;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuMail : public cMenuBase
{
public:
    enum LIST_TYPE
    {
        LIST_TYPE_INVALID = 0,
        LIST_TYPE_USER = 1,
        LIST_TYPE_SYSTEM = 2,
    };
    enum
    {
        MAIL_CURSOR_UNREAD = 0,
        MAIL_CURSOR_UNREAD_PAGE = 1,
        MAIL_CURSOR_USER = 2,
        MAIL_CURSOR_USER_PAGE = 3,
        MAIL_CURSOR_SYSTEM = 4,
        MAIL_CURSOR_SYSTEM_PAGE = 5,
        MAIL_CURSOR_TAB = 6,
        MAIL_CURSOR_MAX = 7,
    };
    enum
    {
        LIST_TAB_UNREAD = 0,
        LIST_TAB_USER = 1,
        LIST_TAB_SYSTEM = 2,
        LIST_TAB_MAX = 3,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST_UPDATE = 3,
        RNO_LIST = 4,
        RNO_DETAIL_REQ = 5,
        RNO_DETAIL = 6,
        RNO_CREATE = 7,
        RNO_UPDATE = 8,
        RNO_GET_ITEM = 9,
        RNO_SUBMENU = 10,
        RNO_DELETE_MULTI = 11,
        RNO_ERROR = 12,
    };
    enum
    {
        MAIL_RNO_BASE = 0,
        MAIL_RNO_MAX = 1,
    };
    enum
    {
        MAIL_CREATE = 0,
        MAIL_UPDATE = 1,
        MAIL_GET_ITEM = 2,
        MAIL_TOP = 3,
        MAIL_MAX = 203,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        ERR_VERSION = 1,
        ERR_NO_ATTACH_ITEM = 2,
        ERR_NO_SYS_MAIL_MAX = 3,
        ERR_NO_NEW_MAIL = 4,
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
    cMenuMail();
    virtual ~cMenuMail();
    void initMail();
    nMenu::MENU_RET moveMail();
    u32 getPageNum();
    u32 getListIndex(u32 page, u32 cursor);
    void createSortList();
    void createMenuList();
    CMailInfo* getMailInfo(s32 tab, s32 cursor);
    u32 getSortListCount();
    LIST_TYPE getSortMailList(u32 userMailIndex, u32 systemMailIndex);
    u32 getListCount(s32 tabType);
    void requestDispUpdate();
private:
    void deleteCheck();
    void clampCursor();
    void requestListUpdate();
private:
    u64 mSortList[200];  // offset: 0xb0
    LIST_TYPE mListType[200];  // offset: 0x6f0
    u32 mSortListCount;  // offset: 0xa10
    s32 mMenuList[203];  // offset: 0xa14
    nMenu::MENU_PARTS mMenuParts[203];  // offset: 0xd40
public:
    static MyDTI DTI;
    static const s32 MAIL_DISP_NUM = 200;
    static const s32 MAIL_SORT_LIST_MAX = 200;
};

class cMenuMailCreate : public cMenuBase
{
public:
    enum
    {
        CREATE_CURSOR_SELECT = 0,
        CREATE_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
        RNO_TO_LIST = 2,
        RNO_SEND = 3,
        RNO_RESULT = 4,
        RNO_ERROR = 5,
    };
    enum
    {
        CREATE_RNO_BASE = 0,
        CREATE_RNO_MAX = 1,
    };
    enum
    {
        MENU_TO_LIST = 0,
        MENU_BODY = 1,
        MENU_SEND = 2,
        MENU_MAX = 3,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        ERR_NOT_TO_LIST = 1,
        ERR_NOT_BODY = 2,
        ERR_LIST_MAX = 3,
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
    cMenuMailCreate();
    virtual ~cMenuMailCreate();
    virtual void exitMenu();  // vtable slot 15
    void initMailCreate(CCommunityCharacterBaseInfo* pCharacterInfo, u32 prio);
    nMenu::MENU_RET moveMailCreate();
    void addList(u32 characterId, CHAR_NAME& charName);
    void eraseList(u32 index);
    CommunityCharacterBaseInfoVec& getAddressList();
private:
    CommunityCharacterBaseInfoVec mList;  // offset: 0xb0
    CommunityCharacterBaseInfoVec mExcludeList;  // offset: 0xd0
    u32 mAddCharacterId;  // offset: 0xf0
    CHAR_NAME mTmpName;  // offset: 0xf4
    MtString mMessage;  // offset: 0x110
    s32 mMenuList[3];  // offset: 0x118
    nMenu::MENU_PARTS mMenuParts[3];  // offset: 0x124
public:
    static MyDTI DTI;
    static const u32 NO_CHAR_ID = 0;
};

class cMenuMailDelete : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_WAIT = 2,
        RNO_ERROR = 3,
    };
    enum
    {
        MAIL_DELETE_RNO_BASE = 0,
        MAIL_DELETE_RNO_MAX = 1,
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
    cMenuMailDelete();
    virtual ~cMenuMailDelete();
    void initMailDelete(u64 mailId, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveMailDelete();
private:
    u64 mMailId;  // offset: 0xb0
    s32 mComId;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuMailDeleteMulti : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_REQ = 2,
        RNO_WAIT = 3,
        RNO_RESULT_INIT = 4,
        RNO_RESULT = 5,
        RNO_ERROR = 6,
    };
    enum
    {
        MAIL_DELETE_MULTI_RNO_BASE = 0,
        MAIL_DELETE_MULTI_RNO_MAX = 1,
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
    cMenuMailDeleteMulti();
    virtual ~cMenuMailDeleteMulti();
    void initMailDeleteMulti(nNetSv::E_MAIL_TYPE type, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveMailDeleteMulti();
private:
    MailInfoVec& getMailList();
private:
    s32 mComId;  // offset: 0xb0
    u32 mMailNum;  // offset: 0xb4
    u32 mDeleteNum;  // offset: 0xb8
    u32 mMailIndex;  // offset: 0xbc
    nNetSv::E_MAIL_TYPE mMailType;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuMailDetail : public cMenuBase
{
public:
    enum
    {
        DETAIL_CURSOR_SELECT = 0,
        DETAIL_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_BODY_ERROR = 3,
        RNO_MAIN = 4,
        RNO_ITEM = 5,
        RNO_REPLY = 6,
        RNO_DELETE = 7,
    };
    enum
    {
        DETAIL_RNO_BASE = 0,
        DETAIL_RNO_MAX = 1,
    };
    enum
    {
        DETAIL_REPLY = 0,
        DETAIL_ITEM = 1,
        DETAIL_DELETE = 2,
        DETAIL_MAX = 3,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        ERR_NOT_CHARACTER = 1,
        ERR_NOT_COMMUNITY = 2,
        ERR_NOT_ITEM = 3,
        ERR_ITEM_ALREADY = 4,
        ERR_NOT_RECEIVE_ITEM = 5,
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
    cMenuMailDetail();
    virtual ~cMenuMailDetail();
    void initMailDetail(CMailInfo& info, const MtVector4& setPos);
    nMenu::MENU_RET moveMailDetail();
    virtual void exitMenu();  // vtable slot 15
    CMailInfo* getMailInfo();
    void requestDispUpdate();
private:
    CMailInfo* mpMailInfo;  // offset: 0xb0
    s32 mMenuList[3];  // offset: 0xb8
    nMenu::MENU_PARTS mMenuParts[3];  // offset: 0xc4
    s32 mComId;  // offset: 0xdc
public:
    static MyDTI DTI;
    static const u32 NO_CHAR_ID = 0;
};

class cMenuMailGetItem : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_WAIT = 2,
        RNO_RESULT = 3,
        RNO_ERROR = 4,
    };
    enum
    {
        MAIL_GET_ITEM_RNO_BASE = 0,
        MAIL_GET_ITEM_RNO_MAX = 1,
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
    cMenuMailGetItem();
    virtual ~cMenuMailGetItem();
    void initMailGetItem(u64 mailId, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveMailGetItem();
    virtual void exitMenu();  // vtable slot 15
private:
    u64 mMailId;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuMailGetItemAll : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_REQ = 2,
        RNO_WAIT = 3,
        RNO_RESULT_INIT = 4,
        RNO_RESULT = 5,
        RNO_ERROR = 6,
    };
    enum
    {
        MAIL_GET_ITEM_ALL_RNO_BASE = 0,
        MAIL_GET_ITEM_ALL_RNO_MAX = 1,
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
    cMenuMailGetItemAll();
    virtual ~cMenuMailGetItemAll();
    void initMailGetItemAll(uGUIBase* pRefGUI);
    nMenu::MENU_RET moveMailGetItemAll();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mMailIndex;  // offset: 0xb0
    u32 mMailNum;  // offset: 0xb4
    u32 mGetMailNum;  // offset: 0xb8
    bool mExistOptionCourse;  // offset: 0xbc
public:
    static MyDTI DTI;
};

class cMenuMailToList : public cMenuBase
{
public:
    enum
    {
        TO_LIST_CURSOR_SELECT = 0,
        TO_LIST_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_LIST = 1,
        RNO_ADD = 2,
    };
    enum
    {
        TO_LIST_RNO_BASE = 0,
        TO_LIST_RNO_MAX = 1,
    };
    enum
    {
        MENU_LIST_TOP = 0,
        MENU_ADD = 10,
        MENU_MAX = 11,
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
    cMenuMailToList();
    virtual ~cMenuMailToList();
    virtual void exitMenu();  // vtable slot 15
    void initMailToList(CommunityCharacterBaseInfoVec& ToList, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveMailToList();
    void createMenuList();
    void addList(u32 characterId, CHAR_NAME& charName);
    void eraseList(u32 index);
    CommunityCharacterBaseInfoVec* getAddressList();
private:
    CommunityCharacterBaseInfoVec* mpToList;  // offset: 0xb0
    u32 mAddCharacterId;  // offset: 0xb8
    CHAR_NAME mTmpName;  // offset: 0xbc
    s32 mMenuList[11];  // offset: 0xd4
public:
    static MyDTI DTI;
};

class cMenuMatchingProfile : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_MENU = 2,
        RNO_PARTY_REQ_WAIT = 3,
        RNO_DECIDE = 4,
    };
    enum
    {
        MATCHING_PROFILE_RNO_BASE = 0,
        MATCHING_PROFILE_RNO_MAX = 1,
    };
    enum
    {
        MATCHING_PROFILE_MAIN = 0,
        MATCHING_PROFILE_SUB = 1,
        MATCHING_PROFILE_PLAYSTYLE = 2,
        MATCHING_PROFILE_COMMENT = 3,
        MATCHING_PROFILE_PARTY_REQ_WAIT = 4,
        MATCHING_PROFILE_OK = 5,
        MATCHING_PROFILE_CANCEL = 6,
        MATCHING_PROFILE_JOB = 7,
        MATCHING_PROFILE_MAX = 8,
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
    cMenuMatchingProfile();
    virtual ~cMenuMatchingProfile();
    void initMatchingProfile(bool IsCardType, u32 PointerPrio);
    nMenu::MENU_RET moveMatchingProfile();
    virtual void exitMenu();  // vtable slot 15
    cCharacterData::stMatchProfile& getProfile();
    void setEntryJobList();
    s32 getEntryJobList(s32 cursor);
    static s32 getPurposeMainList(s32 cursor);
    static s32 getPurposeSubList(s32);
    static s32 getPlayStyleList(s32 cursor);
    u32 getSettingMenuNum(s32 listType);
    static u32 getSettingListNum(s32 listType);
    static s32 getCursorPosFromParam(s32 listType, s32 param);
    s32 getCursorPosFromParam(s32 listType);
    bool getProfileInviteWait();
    void setProfileInviteWait(bool status);
private:
    s32 mEntryJobList[10];  // offset: 0xb0
    u32 mEntryJobCount;  // offset: 0xd8
    s32 entryJobList[10];  // offset: 0xdc
    cCharacterData::stMatchProfile mProfile;  // offset: 0x104
public:
    static MyDTI DTI;
    static const s32 PLAYSTYLE_DISP_NUM = 12;
private:
    static const s32 purposeMainSetting[];
    static const s32 purposeSubSetting[];
    static const s32 playStyleSetting[];
};

class cMenuMyPawnList : public cMenuBase
{
public:
    enum
    {
        MY_PAWN_LIST_ATTR_NONE = 0,
        MY_PAWN_LIST_ATTR_GET_DETAIL = 1,
        MY_PAWN_LIST_ATTR_MASK_PARTY = 4,
        MY_PAWN_LIST_ATTR_MASK_CRAFT = 8,
        MY_PAWN_LIST_ATTR_MASK_CRAFT_TASK = 16,
        MY_PAWN_LIST_ATTR_IN_MANAGER = 64,
        MY_PAWN_LIST_ATTR_IN_PAWN_MANAGER = 128,
        MY_PAWN_LIST_ATTR_MASK_CRAFT_RANK = 256,
    };
    enum
    {
        MY_PAWN_LIST_TYPE_PARTY = 0,
        MY_PAWN_LIST_TYPE_CRAFT = 1,
        MY_PAWN_LIST_TYPE_CRAFT_UPGRADE = 2,
        MY_PAWN_LIST_TYPE_CRAFT_RECV = 3,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_REQ_WAIT = 4,
        RNO_SUB_MENU = 5,
        RNO_ERROR = 6,
    };
    enum
    {
        MY_PAWN_LIST_RNO_BASE = 0,
        MY_PAWN_LIST_RNO_DETAIL = 1,
        MY_PAWN_LIST_RNO_MAX = 2,
    };
    enum
    {
        RNO_DETAIL_INIT = 0,
        RNO_DETAIL_REQ = 1,
        RNO_DETAIL_WAIT = 2,
        RNO_DETAIL_MOVE = 3,
        RNO_DETAIL_ERROR = 4,
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
    cMenuMyPawnList();
    virtual ~cMenuMyPawnList();
    void initMyPawnList(u32 attr, s32 cursorPos, u32 listType);
    nMenu::MENU_RET moveMyPawnList();
    bool moveMyPawnDetail();
    u32 getPawnSlotNo();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    u32 getListLength();
private:
    u32 mAttr;  // offset: 0xb0
    u32 mListType;  // offset: 0xb4
    s32 mDetailReqNo;  // offset: 0xb8
    nMenu::MENU_PARTS mMenuParts[10];  // offset: 0xbc
public:
    static MyDTI DTI;
    static const s32 DISP_MY_PAWN_LIST_NUM = 10;
};

class cMenuOnlineShop : public cMenuBase
{
public:
    enum
    {
        RNO_ONLINESHOP = 0,
        RNO_ERROR = 1,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
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
    cMenuOnlineShop();
    virtual ~cMenuOnlineShop();
    void initMenuOnlineShop(u32 moveline);
    nMenu::MENU_RET moveMenuOnlineShop();
private:
    u32 mType;  // offset: 0xb0
    s32 mMenuList[1];  // offset: 0xb4
public:
    static MyDTI DTI;
};

class cMenuPartyList : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_START = 1,
        RNO_REQ = 2,
        RNO_WAIT = 3,
        RNO_LIST = 4,
        RNO_SEARCH_FILTER = 5,
        RNO_LIST_ERROR = 6,
        RNO_FAVORITE = 7,
        RNO_SUB_MENU = 8,
        RNO_SIMPLE = 9,
    };
    enum
    {
        PARTY_LIST_RNO_BASE = 0,
        PARTY_LIST_RNO_MAX = 1,
    };
    enum
    {
        PARTY_LIST_TOP = 0,
        PARTY_LIST_BOTTOM = 14,
        PARTY_LIST_SETTING = 14,
        PARTY_LIST_SIMPLE = 15,
        PARTY_LIST_MAX = 16,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        ERR_PROGRESS = 1,
        ERR_PLACE = 2,
        ERR_NO_LEADER = 3,
        ERR_PARTY_LARGE = 4,
        ERR_NO_SPACE = 5,
        ERR_QUICK_PARTY = 6,
        ERR_INVITED = 7,
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
    cMenuPartyList();
    virtual ~cMenuPartyList();
    void initPartyList(uGUIBase* pGUIRefMenu);
    nMenu::MENU_RET movePartyList();
    virtual void exitMenu();  // vtable slot 15
    virtual void updatePtr();  // vtable slot 6
    const cCharacterData::stSearchFilterSetting& getSearchSetting();
    bool isEnableSimplePartyReq();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
    virtual bool checkListFilter(u32 sortListIndex);  // vtable slot 18
    bool isFirst();
    s32 getRno();
private:
    cCharacterData::stSearchFilterSetting mSearchSetting;  // offset: 0xb0
    bool mFirst;  // offset: 0x1dc
public:
    static MyDTI DTI;
    static const s32 PARTY_LIST_DISP_NUM = 14;
    static const s32 PARTY_SORT_LIST_MAX = 256;
};

class cMenuPartyListMemberInfo : public cMenuBase
{
public:
    enum
    {
        PARTY_LIST_MEMBER_INFO_CURSOR_LIST = 0,
        PARTY_LIST_MEMBER_INFO_CURSOR_MAX = 1,
    };
    enum
    {
        MOVE_PARTY_LIST_MEMBER_INFO_RNO_INIT = 0,
        MOVE_PARTY_LIST_MEMBER_INFO_RNO_LIST = 1,
    };
    enum
    {
        PARTY_LIST_MEMBER_INFO_RNO_BASE = 0,
        PARTY_LIST_MEMBER_INFO_RNO_MAX = 1,
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
    cMenuPartyListMemberInfo();
    virtual ~cMenuPartyListMemberInfo();
    void initPartyListMemberInfo(MtTypedArray<CDataPartyMember>* pInfo, u32 prio);
    nMenu::MENU_RET movePartyListMemberInfo();
private:
    MtTypedArray<CDataPartyMember>* mpMemberInfo;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuPartyManager : public cMenuBase
{
public:
    enum PARTY_MANAGER_TAB
    {
        PARTY_MANAGER_TAB_LIST = 0,
        PARTY_MANAGER_TAB_MAIN_PAWN = 1,
        PARTY_MANAGER_TAB_SUPPORT_PAWN = 2,
        PARTY_MANAGER_TAB_PARTY_SEARCH = 3,
        PARTY_MANAGER_TAB_CHARACTER_SEARCH = 4,
        PARTY_MANAGER_TAB_MAX = 5,
    };
    enum
    {
        PARTY_MANAGER_CURSOR_TAB_SELECT = 0,
        PARTY_MANAGER_CURSOR_MAX = 1,
    };
    enum
    {
        MOVE_PARTY_MANAGER_RNO_INIT = 0,
        MOVE_PARTY_MANAGER_RNO_WAIT_GUI = 1,
        MOVE_PARTY_MANAGER_RNO_TAB_SELECT = 2,
    };
    enum
    {
        PARTY_MANAGER_RNO_BASE = 0,
        PARTY_MANAGER_RNO_PARTY_LIST = 1,
        PARTY_MANAGER_RNO_MAIN_PAWN = 2,
        PARTY_MANAGER_RNO_SUPPORT_PAWN = 3,
        PARTY_MANAGER_RNO_PARTY_SEARCH = 4,
        PARTY_MANAGER_RNO_CHARACTER_SEARCH = 5,
        PARTY_MANAGER_RNO_MAX = 6,
    };
    enum
    {
        MOVE_PARTY_MANAGER_TAB_MENU_RNO_INIT = 0,
        MOVE_PARTY_MANAGER_TAB_MENU_RNO_MOVE = 1,
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
    cMenuPartyManager();
    virtual ~cMenuPartyManager();
    void initPartyManager(PARTY_MANAGER_TAB tab, bool isShortCut);
    nMenu::MENU_RET movePartyManager();
    virtual void exitMenu();  // vtable slot 15
    s32 getTabNo();
private:
    bool mIsShortCut;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuPartyMemberList : public cMenuBase
{
public:
    enum PARTY_MEMBER_LIST_TYPE
    {
        PARTY_MEMBER_LIST_TYPE_IN_MANAGER = 0,
    };
    enum
    {
        MOVE_PARTY_MEMBER_LIST_RNO_INIT = 0,
        MOVE_PARTY_MEMBER_LIST_RNO_LIST = 1,
        MOVE_PARTY_MEMBER_LIST_RNO_LEADER_SELECT = 2,
        MOVE_PARTY_MEMBER_LIST_RNO_SUB_MENU = 3,
        MOVE_PARTY_MEMBER_LIST_RNO_LEAVE = 4,
        MOVE_PARTY_MEMBER_LIST_RNO_BREAKUP = 5,
    };
    enum
    {
        PARTY_MEMBER_LIST_RNO_BASE = 0,
        PARTY_MEMBER_LIST_RNO_MAX = 1,
    };
    enum
    {
        MEMBER_TOP = 0,
        MEMBER_END = 7,
        REQ_TOP = 8,
        REQ_END = 15,
        INVITE_TOP = 16,
        INVITE_END = 16,
        LEAVE_PARTY = 17,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        LEAVE_ERR_SOLO = 1,
        LEAVE_ERR_BATTLE = 2,
        LEAVE_ERR_QUICK = 3,
        LEAVE_ERR_CONTENTS = 4,
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
    cMenuPartyMemberList();
    virtual ~cMenuPartyMemberList();
    void initPartyMemberList(s32 type, uGUIBase* pRefGUIUnit, bool isShortCut);
    nMenu::MENU_RET movePartyMemberList();
    s32 getPartyMemberNum() const;
    s32 getReqMemberNum() const;
    s32 getInviteMemberNum() const;
    s32 getAllMembaerNum() const;
    bool isPartyMember(s32 cursorIndex);
    bool isReqMember(s32 cursorIndex);
    s32 getPartyMemberIndex(s32 cursorIndex);
    s32 getReqMemberIndex(s32 cursorIndex);
    virtual void updatePtr();  // vtable slot 6
    s32 getCursorPosMain();
    bool isEnableLeaveParty();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    bool callbackCheckCloseDialog();
private:
    s32 mType;  // offset: 0xb0
    s32 mPartyMemberNum;  // offset: 0xb4
    s32 mReqMemberNum;  // offset: 0xb8
    s32 mInviteMemberNum;  // offset: 0xbc
    bool mIsShortCut;  // offset: 0xc0
public:
    static MyDTI DTI;
private:
    static const s32 MEMBER_LIST_MAX = 16;
};

class cMenuPartyReq : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_PARTY_CREATE = 1,
        RNO_INVITE = 2,
        RNO_INVITE_WAIT = 3,
        RNO_RESULT = 4,
        RNO_ERROR = 5,
    };
    enum
    {
        PARTY_REQ_RNO_BASE = 0,
        PARTY_REQ_RNO_MAX = 1,
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
    cMenuPartyReq();
    virtual ~cMenuPartyReq();
    void initPartyReq(CDataClientPartyListInfo* pInfo, u32 characterId, CHAR_NAME* pCharacterName);
    nMenu::MENU_RET movePartyReq();
private:
    CDataClientPartyListInfo* mpPartyReqInfo;  // offset: 0xb0
    u32 mCharacterId;  // offset: 0xb8
    CHAR_NAME mCharacterName;  // offset: 0xbc
    s32 mComId;  // offset: 0xd4
public:
    static MyDTI DTI;
};

class cMenuPawnDelete : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        PAWN_DELETE_RNO_BASE = 0,
        PAWN_DELETE_RNO_MAX = 1,
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
    cMenuPawnDelete();
    virtual ~cMenuPawnDelete();
    void initPawnDelete(u32 pawnId);
    nMenu::MENU_RET movePawnDelete();
private:
    u32 mPawnId;  // offset: 0xb0
    bool mIsKeepEquip;  // offset: 0xb4
    cPawnListParam* mpPawnParam;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuPawnFeedback : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
        RNO_RANK = 2,
        RNO_COMMENT = 3,
    };
    enum RNO
    {
        PAWN_FEEDBACK_RNO_BASE = 0,
        PAWN_FEEDBACK_RNO_SETTING = 1,
        PAWN_FEEDBACK_RNO_MAX = 2,
    };
    enum
    {
        PAWN_FEEDBACK_RANK = 0,
        PAWN_FEEDBACK_COMMENT = 1,
        PAWN_FEEDBACK_DECIDE = 2,
        PAWN_FEEDBACK_CANCEL = 3,
        PAWN_FEEDBACK_MAX = 4,
    };
    enum
    {
        PAWN_FEEDBACK_CURSOR_SETTING = 0,
        PAWN_FEEDBACK_CURSOR_MAX = 1,
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
    cMenuPawnFeedback();
    virtual ~cMenuPawnFeedback();
    void initPawnFeedback(nNet::FEEDBACK_TYPE type, nNet::stFeedbackData& feedback);
    nMenu::MENU_RET movePawnFeedback();
    virtual void exitMenu();  // vtable slot 15
    nNet::FEEDBACK_TYPE getFeedbackType() const;
    nNet::stFeedbackData* getFeedbackData() const;
private:
    nNet::FEEDBACK_TYPE mType;  // offset: 0xb0
    nNet::stFeedbackData* mpFeedback;  // offset: 0xb8
    nNet::stFeedbackData mFeedback;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuPawnHistory : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_DETAIL = 4,
        RNO_ERROR = 5,
    };
    enum
    {
        PAWN_HISTORY_RNO_BASE = 0,
        PAWN_HISTORY_RNO_MAX = 1,
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
    cMenuPawnHistory();
    virtual ~cMenuPawnHistory();
    void initPawnHistory(u32 pawnId, u32 prio);
    nMenu::MENU_RET movePawnHistory();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mPawnId;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const s32 DISP_PAWN_HISTORY_NUM = 10;
    static const s32 PAWN_HISTORY_MAX = 256;
};

class cMenuPawnManageMenu : public cMenuBase
{
public:
    enum
    {
        MOVE_PAWN_MANAGE_MENU_RNO_INIT = 0,
        MOVE_PAWN_MANAGE_MENU_RNO_MENU = 1,
        MOVE_PAWN_MANAGE_MENU_RNO_MANAGER = 2,
        MOVE_PAWN_MANAGE_MENU_RNO_REVIVE = 3,
    };
    enum
    {
        PAWN_MANAGE_MENU_RNO_BASE = 0,
        PAWN_MANAGE_MENU_RNO_MAX = 1,
    };
    enum
    {
        PAWN_MANAGE_MENU_RENTAL = 0,
        PAWN_MANAGE_MENU_MAIN = 1,
        PAWN_MANAGE_MENU_SUPPORT = 2,
        PAWN_MANAGE_MENU_REVIVE = 3,
        PAWN_MANAGE_MENU_MAX = 4,
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
    cMenuPawnManageMenu();
    virtual ~cMenuPawnManageMenu();
    void initPawnManageMenu();
    nMenu::MENU_RET movePawnManageMenu();
    virtual void exitMenu();  // vtable slot 15
public:
    static MyDTI DTI;
};

class cMenuPawnManager : public cMenuBase
{
public:
    enum
    {
        PAWN_MANAGER_TAB_SEARCH = 0,
        PAWN_MANAGER_TAB_MAIN = 1,
        PAWN_MANAGER_TAB_SUPPORT = 2,
        PAWN_MANAGER_TAB_LOST = 3,
        PAWN_MANAGER_TAB_MAX = 4,
    };
    enum
    {
        PAWN_MANAGER_CURSOR_TAB_SELECT = 0,
        PAWN_MANAGER_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_WAIT_GUI = 2,
        RNO_TAB_SELECT = 3,
    };
    enum
    {
        PAWN_MANAGER_RNO_BASE = 0,
        PAWN_MANAGER_RNO_SEARCH = 1,
        PAWN_MANAGER_RNO_MAIN = 2,
        PAWN_MANAGER_RNO_SUPPORT = 3,
        PAWN_MANAGER_RNO_LOST = 4,
        PAWN_MANAGER_RNO_MAX = 5,
    };
    enum
    {
        TAB_MENU_RNO_INIT = 0,
        TAB_MENU_RNO_MOVE = 1,
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
    cMenuPawnManager();
    virtual ~cMenuPawnManager();
    void initPawnManager(s32 initTab);
    nMenu::MENU_RET movePawnManager();
    u32 getTabNum();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mTabNum;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuPawnPoint : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_RATE_REQ = 1,
        RNO_RATE_WAIT = 2,
        RNO_ACTIVE = 3,
        RNO_ACTIVE_AND_CLEAR = 4,
        RNO_EDIT = 5,
        RNO_CONFIRMATION = 6,
        RNO_CONFIRMATION_WAIT = 7,
        RNO_END_CANCEL = 8,
        RNO_ERROR = 9,
        RNO_NUM = 10,
    };
    enum
    {
        PWAN_POINT_RNO_BASE = 0,
        PWAN_POINT_RNO_MAX = 1,
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
    cMenuPawnPoint();
    virtual ~cMenuPawnPoint();
    void initPawnPoint(u32 pawnId);
    nMenu::MENU_RET movePawnPoint();
    UseSupportPointVec* getUseSupportPointVec();
private:
    u32 mPawnId;  // offset: 0xb0
    UseSupportPointVec mUseSupportPointVec;  // offset: 0xb8
public:
    static MyDTI DTI;
    static const u32 GETPOINT_ARRAYSIZE = 32;
};

class cMenuPawnRental : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
        RNO_EXIT_WAIT = 1,
    };
    enum
    {
        PAWN_RENTAL_RNO_BASE = 0,
        PAWN_RENTAL_RNO_MAX = 1,
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
    cMenuPawnRental();
    virtual ~cMenuPawnRental();
    void initPawnRental(u32 slotNo, cPawnListParam& param);
    nMenu::MENU_RET movePawnRental();
private:
    u32 mSlotNo;  // offset: 0xb0
    cPawnListParam* mpPawnParam;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuPawnReqList : public cMenuBase
{
public:
    enum
    {
        PAWN_REQ_TYPE_MY_PAWN = 0,
        PAWN_REQ_TYPE_RENTAL_PAWN = 1,
    };
    enum
    {
        PAWN_REQ_LIST_CURSOR_LIST = 0,
        PAWN_REQ_LIST_CURSOR_MAX = 1,
    };
    enum
    {
        MOVE_PAWN_REQ_LIST_RNO_INIT = 0,
        MOVE_PAWN_REQ_LIST_RNO_REQ = 1,
        MOVE_PAWN_REQ_LIST_RNO_MY_PAWN = 2,
        MOVE_PAWN_REQ_LIST_RNO_RENTAL_PAWN = 3,
    };
    enum
    {
        PAWN_REQ_LIST_RNO_BASE = 0,
        PAWN_REQ_LIST_RNO_MAX = 1,
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
    cMenuPawnReqList();
    virtual ~cMenuPawnReqList();
    void initPawnReqList(s32 type);
    nMenu::MENU_RET movePawnReqList();
private:
    s32 mPawnReqListType;  // offset: 0xb0
    s32 mPawnReqListType2;  // offset: 0xb4
    s32 mPawnReqWaitState;  // offset: 0xb8
    u32 mSaveSlot;  // offset: 0xbc
public:
    static MyDTI DTI;
    static const s32 DISP_PAWN_REQ_LIST_NUM = 10;
};

class cMenuPawnReqMenu : public cMenuBase
{
public:
    enum
    {
        MOVE_PAWN_REQ_MENU_RNO_INIT = 0,
        MOVE_PAWN_REQ_MENU_RNO_MENU = 1,
        MOVE_PAWN_REQ_MENU_RNO_MY_PAWN = 2,
        MOVE_PAWN_REQ_MENU_RNO_RENTAL_PAWN = 3,
    };
    enum
    {
        PAWN_REQ_MENU_RNO_BASE = 0,
        PAWN_REQ_MENU_RNO_MAX = 1,
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
    cMenuPawnReqMenu();
    virtual ~cMenuPawnReqMenu();
    void initPawnReqMenu();
    nMenu::MENU_RET movePawnReqMenu();
public:
    static MyDTI DTI;
};

class cMenuPawnReturn : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_REQ_DATA = 1,
        RNO_REQ_DATA_WAIT = 2,
        RNO_MENU_INIT = 3,
        RNO_MENU = 4,
        RNO_FEEDBACK = 5,
        RNO_SELECT = 6,
        RNO_ERROR = 7,
    };
    enum
    {
        PAWN_RETURN_RNO_BASE = 0,
        PAWN_RETURN_RNO_MAX = 1,
    };
    enum
    {
        MENU_FEEDBACK_EDIT = 0,
        MENU_FEEDBACK_BATTLE = 1,
        MENU_FEEDBACK_CRAFT = 2,
        MENU_DECIDE = 3,
        MENU_CANCEL = 4,
        MENU_MAX = 5,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        ERR_NO_BATTLE = 1,
        ERR_NO_CRAFT = 2,
        ERR_NO_INPUT = 3,
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
    cMenuPawnReturn();
    virtual ~cMenuPawnReturn();
    void initPawnReturn(u32 pawnId, u32 prio);
    nMenu::MENU_RET movePawnReturn();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    u32 mPawnId;  // offset: 0xb0
    cPawnListParam* mpPawnParam;  // offset: 0xb8
    nNet::stPawnFeedback mPawnFeedback;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuPawnRevive : public cMenuBase
{
public:
    enum
    {
        PAWN_REVIVE_CURSOR_SELECT = 0,
        PAWN_REVIVE_CURSOR_CONFIRM = 1,
        PAWN_REVIVE_CURSOR_MAX = 2,
    };
    enum
    {
        MOVE_PAWN_REVIVE_RNO_INIT = 0,
        MOVE_PAWN_REVIVE_RNO_CREATE_GUI = 1,
        MOVE_PAWN_REVIVE_RNO_MENU = 2,
        MOVE_PAWN_REVIVE_RNO_CONFIRM = 3,
        MOVE_PAWN_REVIVE_RNO_WAIT = 4,
        MOVE_PAWN_REVIVE_RNO_SHOP = 5,
    };
    enum
    {
        PAWN_REVIVE_RNO_BASE = 0,
        PAWN_REVIVE_RNO_MAX = 1,
    };
    enum
    {
        PAWN_REVIVE_MENU_TYPE_PAWN = 0,
        PAWN_REVIVE_MENU_TYPE_PL_DEAD = 1,
        PAWN_REVIVE_MENU_TYPE_LOST_PAWN = 2,
    };
    enum
    {
        PAWN_REVIVE_MENU_STOCK = 0,
        PAWN_REVIVE_MENU_GOLD_STONE = 1,
        PAWN_REVIVE_MENU_PENALTY = 2,
        PAWN_REVIVE_MENU_RIM = 3,
        PAWN_REVIVE_MENU_CANCEL = 4,
        PAWN_REVIVE_MENU_MAX = 5,
    };
    enum
    {
        PAWN_REVIVE_CONFIRM_DECIDE = 0,
        PAWN_REVIVE_CONFIRM_CANCEL = 1,
        PAWN_REVIVE_CONFIRM_MAX = 2,
    };
    enum
    {
        RET_REVIVE_TYPE_PENALTY = 0,
        RET_REVIVE_TYPE_GOLD_STONE = 1,
        RET_REVIVE_TYPE_STOCK = 2,
        RET_REVIVE_TYPE_RIM = 3,
        RET_REVIVE_TYPE_MAX = 4,
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
    cMenuPawnRevive();
    virtual ~cMenuPawnRevive();
    void initPawnRevive(s32 type);
    nMenu::MENU_RET movePawnRevive(uHuman* pHm, s32& retReviveType);
    virtual void exitMenu();  // vtable slot 15
    virtual void updatePtr();  // vtable slot 6
    s32 getMenuList(s32 cursor);
    bool isShop();
    u32 getUseRim();
protected:
    virtual bool isCancel(u32 cancelSe);  // vtable slot 9
    virtual bool isDecide();  // vtable slot 10
private:
    void createMenuList(uPlayer* pPlayer);
    f32 getLostTimer(uHuman* pHm);
    u32 getPawnId(uHuman* pHm);
private:
    sItemManager::stRequest* mpRequest;  // offset: 0xb0
    s32 mType;  // offset: 0xb8
    u32 mKodouIndex;  // offset: 0xbc
    s32 mComStatus;  // offset: 0xc0
    u32 mUseRim;  // offset: 0xc4
    s32 mMenuList[5];  // offset: 0xc8
    bool mIsShop;  // offset: 0xdc
    uGUIBase* mpGUIShop;  // offset: 0xe0
public:
    static MyDTI DTI;
};

class cMenuPawnSearch : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_CATEGORY_SELECT = 1,
        RNO_CHAR_LIST = 2,
        RNO_REQ_REG = 3,
        RNO_WAIT_REG = 4,
        RNO_LIST_REG = 5,
        RNO_SEARCH_FILTER = 6,
        RNO_SUB_MENU = 7,
        RNO_RENTAL_WAIT = 8,
        RNO_ERROR = 9,
    };
    enum
    {
        PAWN_SEARCH_RNO_BASE = 0,
        PAWN_SEARCH_RNO_MAX = 1,
    };
    enum
    {
        SEARCH_CATEGORY_NORMAL = 0,
        SEARCH_CATEGORY_RANKING_M = 1,
        SEARCH_CATEGORY_RANKING_W = 2,
        SEARCH_CATEGORY_LEGEND = 3,
        SEARCH_CATEGORY_OFFICIAL = 4,
        SEARCH_CATEGORY_FRIEND = 5,
        SEARCH_CATEGORY_CLAN = 6,
        SEARCH_CATEGORY_FAVORITE = 7,
        SEARCH_CATEGORY_MAX = 8,
    };
    enum
    {
        SEARCH_LIST_TOP = 0,
        SEARCH_LIST_SETTING = 10,
        SEARCH_LIST_MAX = 11,
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
    cMenuPawnSearch();
    virtual ~cMenuPawnSearch();
    void initPawnSearch();
    nMenu::MENU_RET movePawnSearch();
    virtual void exitMenu();  // vtable slot 15
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
    s32 getCategoryCursor();
private:
    void selectCategory();
private:
    cCharacterData::stSearchFilterSetting mSearchSetting;  // offset: 0xb0
    cCharacterData::stSearchFilterSetting mUserSearchSetting;  // offset: 0x1dc
    u32 mDetailReqNo;  // offset: 0x308
    u32 mPageMax;  // offset: 0x30c
    s32 mComStatus;  // offset: 0x310
    CommunityCharacterBaseInfoVec mList;  // offset: 0x318
    CommunityCharacterBaseInfoVec mExcludeList;  // offset: 0x338
    u32 mCharacterId;  // offset: 0x358
    CHAR_NAME mTmpName;  // offset: 0x35c
    cMenuSupportMenu* mpCategoryMenu;  // offset: 0x378
    cMenuSupportList* mpSearchList;  // offset: 0x380
public:
    static MyDTI DTI;
    static const s32 SEARCH_PAWN_DISP_NUM = 10;
    static const s32 SEARCH_PAWN_NUM_MAX = 256;
};

class cMenuPawnSetPartner : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        PAWN_SET_PARTNER_RNO_BASE = 0,
        PAWN_SET_PARTNER_RNO_MAX = 1,
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
    cMenuPawnSetPartner();
    virtual ~cMenuPawnSetPartner();
    void initPawnSetPartner(u32 pawnId);
    nMenu::MENU_RET movePawnSetPartner();
private:
    u32 mPawnId;  // offset: 0xb0
    cPawnListParam* mpPawnParam;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuPawnShareRange : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
        RNO_WAIT = 2,
        RNO_RESULT = 3,
        RNO_ERROR = 4,
    };
    enum
    {
        PAWN_SHARE_RANGE_RNO_BASE = 0,
        PAWN_SHARE_RANGE_RNO_MAX = 1,
    };
    enum
    {
        ANYONE = 0,
        FRIEND_ONLY = 1,
        CRAN_ONLY = 2,
        FRIEND_CRAN_ONLY = 3,
        NOBODY = 4,
        MENU_MAX = 5,
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
    cMenuPawnShareRange();
    virtual ~cMenuPawnShareRange();
    void initPawnShareRange(u32 pawnId, u32 prio);
    nMenu::MENU_RET movePawnShareRange();
private:
    u32 mPawnId;  // offset: 0xb0
    nNet::PAWN_SHARE_RANGE mRange;  // offset: 0xb4
public:
    static MyDTI DTI;
};

class cMenuPlDeadMenu : public cMenuBase
{
public:
    enum
    {
        PL_DEAD_MENU_CURSOR_SELECT = 0,
        PL_DEAD_MENU_CURSOR_CONFIRM = 1,
        PL_DEAD_MENU_CURSOR_MAX = 2,
    };
    enum
    {
        MOVE_PL_DEAD_MENU_RNO_INIT = 0,
        MOVE_PL_DEAD_MENU_RNO_CREATE_GUI = 1,
        MOVE_PL_DEAD_MENU_RNO_MENU = 2,
        MOVE_PL_DEAD_MENU_RNO_CONFIRM = 3,
    };
    enum
    {
        PL_DEAD_MENU_RNO_BASE = 0,
        PL_DEAD_MENU_RNO_MAX = 1,
    };
    enum
    {
        PL_DEAD_MENU_HELP = 0,
        PL_DEAD_MENU_MAX = 1,
    };
    enum
    {
        PL_DEAD_CONFIRM_DECIDE = 0,
        PL_DEAD_CONFIRM_CANCEL = 1,
        PL_DEAD_CONFIRM_MAX = 2,
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
    cMenuPlDeadMenu();
    virtual ~cMenuPlDeadMenu();
    void initPlDeadMenu();
    nMenu::MENU_RET movePlDeadMenu();
protected:
    virtual bool isCancel(u32 cancelSe);  // vtable slot 9
    virtual bool isDecide();  // vtable slot 10
public:
    static MyDTI DTI;
};

class cMenuQuickMatch : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
        RNO_MATCH = 2,
    };
    enum
    {
        QUICK_MATCH_RNO_BASE = 0,
        QUICK_MATCH_RNO_MAX = 1,
    };
    enum
    {
        QUICK_MATCH_TYPE = 0,
        QUICK_MATCH_JOB = 1,
        QUICK_MATCH_LEVEL = 2,
        QUICK_MATCH_LEADER_OK = 3,
        QUICK_MATCH_DECIDE = 4,
        QUICK_MATCH_CANCEL = 5,
        QUICK_MATCH_MAX = 6,
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
    cMenuQuickMatch();
    virtual ~cMenuQuickMatch();
    void initQuickMatch(nNet::QUICK_MATCH_TYPE type, u32 id1, u32 id2, MT_CTSTR pName, uGUIBase* pParentGUI);
    nMenu::MENU_RET moveQuickMatch();
    virtual void exitMenu();  // vtable slot 15
    MT_CTSTR getNewsQuestName();
    void setSpotId(u32);
    u32 getSpotId();
    void setJobBalance(bool);
    bool getJobBalance() const;
    void setLevelBalance(bool);
    bool getLevelBalance() const;
    void setLeaderOK(bool);
    bool getLeaderOK() const;
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    bool checkLevelBalance();
    bool checkJobBalance();
private:
    nNet::QUICK_MATCH_TYPE mType;  // offset: 0xb0
    u32 mId1;  // offset: 0xb4
    u32 mId2;  // offset: 0xb8
    bool mJob;  // offset: 0xbc
    bool mLevel;  // offset: 0xbd
    bool mLeaderOK;  // offset: 0xbe
    MtString mName;  // offset: 0xc0
public:
    static MyDTI DTI;
    static const s32 LEVEL_BALANCE = 4;
};

class cMenuQuickMatchCancel : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
    };
    enum
    {
        QUICK_MATCH_CANCEL_RNO_BASE = 0,
        QUICK_MATCH_CANCEL_RNO_MAX = 1,
    };
    enum
    {
        QUICK_MATCH_CANCEL_INFO_NAME = 0,
        QUICK_MATCH_CANCEL_INFO_MAIN_PURPOSE = 1,
        QUICK_MATCH_CANCEL_INFO_SUB_PURPOSE = 2,
        QUICK_MATCH_CANCEL_INFO_PAWN = 3,
        QUICK_MATCH_CANCEL_INFO_TIMER = 4,
        QUICK_MATCH_CANCEL_RETURN = 5,
        QUICK_MATCH_CANCEL_DECIDE = 6,
        QUICK_MATCH_CANCEL_MAX = 7,
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
    cMenuQuickMatchCancel();
    virtual ~cMenuQuickMatchCancel();
    void initQuickMatchCancel(uGUIBase* pParentGUI);
    nMenu::MENU_RET moveQuickMatchCancel();
public:
    static MyDTI DTI;
};

class cMenuQuickMatchRetry : public cMenuBase
{
public:
    enum
    {
        MOVE_QUICK_MATCH_RETRY_RNO_INIT = 0,
        MOVE_QUICK_MATCH_RETRY_RNO_MENU = 1,
    };
    enum
    {
        QUICK_MATCH_RETRY_RNO_BASE = 0,
        QUICK_MATCH_RETRY_RNO_MAX = 1,
    };
    enum
    {
        QUICK_MATCH_RETRY_RETRY = 0,
        QUICK_MATCH_RETRY_CANCEL = 1,
        QUICK_MATCH_RETRY_MAX = 2,
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
    cMenuQuickMatchRetry();
    virtual ~cMenuQuickMatchRetry();
    void initQuickMatchRetry();
    nMenu::MENU_RET moveQuickMatchRetry();
public:
    static MyDTI DTI;
};

class cMenuQuickMatchSelect : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_MATCH = 2,
        RNO_CANCEL = 3,
        RNO_NEWS = 4,
        RNO_AREALIST = 5,
    };
    enum
    {
        QUICK_MATCH_SELECT_RNO_BASE = 0,
        QUICK_MATCH_SELECT_RNO_MAX = 1,
    };
    enum
    {
        MENU_MAIN_QUEST = 0,
        MENU_NEWS = 1,
        MENU_AREA = 2,
        MENU_RETURN = 3,
        MENU_MAX = 4,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        ERR_NO_MAIN_QUEST = 1,
        ERR_SOLO_MAIN_QUEST = 2,
        ERR_NEWS_OPEN = 3,
    };
    enum
    {
        TYPE_GAME_MENU = 0,
        TYPE_NPC = 1,
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
    cMenuQuickMatchSelect();
    virtual ~cMenuQuickMatchSelect();
    virtual void exitMenu();  // vtable slot 15
    void initQuickMatchSelect(s32 type);
    nMenu::MENU_RET moveQuickMatchSelect();
    virtual void updatePtr();  // vtable slot 6
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    void setDisableMenu();
private:
    u32 mType;  // offset: 0xb0
    u32 mLastChoice;  // offset: 0xb4
    uGUINewspaper* mpGUINews;  // offset: 0xb8
    uGUIMenuAreaInfo* mpGUIAreaInfo;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuReadyCheck : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_NONE = 1,
        RNO_SELECT = 2,
        RNO_ENTRY_WAIT = 3,
        RNO_ENTRY = 4,
        RNO_ENTRY_BOARD = 5,
        RNO_WAIT = 6,
        RNO_JUMP = 7,
        RNO_RETRY = 8,
        RNO_ERROR = 9,
    };
    enum
    {
        READY_CHECK_RNO_BASE = 0,
        READY_CHECK_RNO_MAX = 1,
    };
    enum
    {
        READY_CHECK_CURSOR_SELECT = 0,
        READY_CHECK_CURSOR_MAX = 1,
    };
    enum
    {
        MENU_READY = 0,
        MENU_CANCEL = 1,
        MENU_RETURN = 2,
        MENU_MAX = 3,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        ERR_UNABLE_READY = 1,
    };
    enum
    {
        CHECK_TYPE_PARTY_INVITED = 0,
        CHECK_TYPE_QUICK_PARTY = 1,
        CHECK_TYPE_ENTRY_BOARD = 2,
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
    cMenuReadyCheck();
    virtual ~cMenuReadyCheck();
    virtual void exitMenu();  // vtable slot 15
    void initReadyCheck(u32 type);
    nMenu::MENU_RET moveReadyCheck();
    bool isReadyWait();
private:
    nMenu::MENU_RET moveReadyCheckCore();
    void setDisableMenu();
    bool isEntryWithPawn();
    void initEntryFlow();
private:
    u32 mType;  // offset: 0xb0
    s32 mMenuList[3];  // offset: 0xb4
    nMenu::MENU_PARTS mMenuParts[3];  // offset: 0xc0
    f32 mTimer;  // offset: 0xd8
public:
    static MyDTI DTI;
};

class cMenuRecentList : public cMenuBase
{
public:
    enum
    {
        RECENT_LIST_CURSOR_LIST = 0,
        RECENT_LIST_CURSOR_LIST_PAGE = 1,
        RECENT_LIST_CURSOR_MAX = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_LIST = 1,
        RNO_SUB_MENU = 2,
    };
    enum
    {
        RECENT_LIST_RNO_BASE = 0,
        RECENT_LIST_RNO_MAX = 1,
    };
    enum
    {
        RECENT_LIST_TOP = 0,
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
    cMenuRecentList();
    virtual ~cMenuRecentList();
    void initRecentList(uGUIBase* pRefGUI);
    nMenu::MENU_RET moveRecentList();
    virtual void exitMenu();  // vtable slot 15
    u32 getPageNum();
    u32 getListIndex(u32 page, u32 cursor);
    u32 getSortIndex(u32 ListIndex);
    u32 getSortCount();
    bool getRemakeListFlag();
    u32 getRecentListDispNum();
    s32 getRno();
private:
    void createSortList();
    void createMenuList();
private:
    u32* mpSortList;  // offset: 0xb0
    u32 mSortListCount;  // offset: 0xb8
    bool mIsRemakeList;  // offset: 0xbc
public:
    static MyDTI DTI;
};

class cMenuRemoveFriend : public cMenuBase
{
public:
    enum
    {
        MOVE_REMOVE_FRIEND_RNO_DLG_FLOW = 0,
    };
    enum
    {
        REMOVE_FRIEND_RNO_BASE = 0,
        REMOVE_FRIEND_RNO_MAX = 1,
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
    cMenuRemoveFriend();
    virtual ~cMenuRemoveFriend();
    void initRemoveFriend(u32 friendNo, MtString& charFirstName, MtString& charLastName);
    nMenu::MENU_RET moveRemoveFriend();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mFriendNo;  // offset: 0xb0
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuRentalPawnList : public cMenuBase
{
public:
    enum
    {
        RENTAL_PAWN_LIST_DISP_ONLY = 0,
        RENTAL_PAWN_LIST_GET_DETAIL = 1,
        RENTAL_PAWN_LIST_IN_MANAGER = 2,
        RENTAL_PAWN_LIST_IN_PAWN_MANAGER = 3,
    };
    enum
    {
        RENTAL_PAWN_LIST_ATTR_NONE = 0,
        RENTAL_PAWN_LIST_ATTR_IN_PARTY = 1,
        RENTAL_PAWN_LIST_ATTR_IN_CRAFT = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_REQ_WAIT = 4,
        RNO_FAVORITE = 5,
        RNO_SUB_MENU = 6,
        RNO_ERROR = 7,
    };
    enum
    {
        RENTAL_PAWN_LIST_RNO_BASE = 0,
        RENTAL_PAWN_LIST_RNO_DETAIL = 1,
        RENTAL_PAWN_LIST_RNO_MAX = 2,
    };
    enum
    {
        RNO_DETAIL_INIT = 0,
        RNO_DETAIL_REQ = 1,
        RNO_DETAIL_WAIT = 2,
        RNO_DETAIL_MOVE = 3,
        RNO_DETAIL_ERROR = 4,
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
    cMenuRentalPawnList();
    virtual ~cMenuRentalPawnList();
    void initRentalPawnList(s32 listType, s32 cursorPos, s32 listAttr);
    nMenu::MENU_RET moveRentalPawnList();
    bool moveRentalPawnDetail();
    u32 getPawnSlotNo();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    s32 mListType;  // offset: 0xb0
    s32 mListAttr;  // offset: 0xb4
    s32 mDetailReqNo;  // offset: 0xb8
    nMenu::MENU_PARTS mMenuParts[10];  // offset: 0xbc
public:
    static MyDTI DTI;
    static const s32 DISP_RENTAL_PAWN_LIST_NUM = 10;
};

class cMenuResetCraftPoint : public cMenuBase
{
public:
    enum
    {
        RNO_DLG_FLOW = 0,
    };
    enum
    {
        RESET_CRAFT_POINT_RNO_BASE = 0,
        RESET_CRAFT_POINT_RNO_MAX = 1,
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
    cMenuResetCraftPoint();
    virtual ~cMenuResetCraftPoint();
    void initResetCraftPoint(u32 PawnId);
    nMenu::MENU_RET moveResetCraftPoint();
private:
    u32 mPawnId;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuSearchFilter : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
        RNO_SETTING_NAME = 2,
        RNO_CLAN_NAME = 3,
        RNO_CLAN_LEVEL = 4,
        RNO_CLAN_MEMBER_NUM = 5,
        RNO_CLAN_MOTTO = 6,
        RNO_CLAN_DAY = 7,
        RNO_CLAN_HOUR = 8,
        RNO_CLAN_FEATURE = 9,
        RNO_CHARACTER_NAME_LIST = 10,
        RNO_CHARACTER_NAME = 11,
        RNO_PAWN_NAME = 12,
        RNO_SETTING_INIT = 13,
    };
    enum RNO
    {
        SEARCH_FILTER_RNO_BASE = 0,
        SEARCH_FILTER_RNO_MAX = 1,
    };
    enum
    {
        SEARCH_TAB_NONE = 0,
        SEARCH_TAB_FRIEND = 1,
        SEARCH_TAB_STATUS = 2,
    };
    enum
    {
        SEARCH_FILTER_SEX = 0,
        SEARCH_FILTER_JOB = 1,
        SEARCH_FILTER_RANK = 2,
        SEARCH_FILTER_RANK_MIN = 3,
        SEARCH_FILTER_RANK_MAX = 4,
        SEARCH_FILTER_RANK_SETTING = 5,
        SEARCH_FILTER_SKILL = 6,
        SEARCH_FILTER_PURPOSE1 = 7,
        SEARCH_FILTER_PURPOSE2 = 8,
        SEARCH_FILTER_PLAYSTYLE = 9,
        SEARCH_FILTER_MEMBER_NUM = 10,
        SEARCH_FILTER_PAWN_NUM = 11,
        SEARCH_FILTER_ACHIVEMENT = 12,
        SEARCH_FILTER_CRAFT_RANK = 13,
        SEARCH_FILTER_CRAFT_SKILL_PHARMACY = 14,
        SEARCH_FILTER_CRAFT_SKILL_FORGING = 15,
        SEARCH_FILTER_CRAFT_SKILL_SEWING = 16,
        SEARCH_FILTER_CRAFT_SKILL_CHASING = 17,
        SEARCH_FILTER_CRAFT_SKILL_HERMETIC = 18,
        SEARCH_FILTER_QUICK_PARTY_NUM = 19,
        SEARCH_FILTER_QUICK_PAWN_OK = 20,
        SEARCH_FILTER_QUICK_PARTY_BALANCE = 21,
        SEARCH_FILTER_QUICK_LEVEL_BALANCE = 22,
        SEARCH_FILTER_SETTING_NAME = 23,
        SEARCH_FILTER_CLAN_NAME_TYPE = 24,
        SEARCH_FILTER_CLAN_NAME = 25,
        SEARCH_FILTER_CLAN_LEVEL = 26,
        SEARCH_FILTER_CLAN_MEMBER_NUM = 27,
        SEARCH_FILTER_CLAN_MOTTO = 28,
        SEARCH_FILTER_CLAN_DAY = 29,
        SEARCH_FILTER_CLAN_HOUR = 30,
        SEARCH_FILTER_CLAN_FEATURE = 31,
        SEARCH_FILTER_CHARACTER_NAME_LIST = 32,
        SEARCH_FILTER_FRIEND = 33,
        SEARCH_FILTER_CLAN_MEMBER = 34,
        SEARCH_FILTER_PARTY = 35,
        SEARCH_FILTER_GROUP = 36,
        SEARCH_FILTER_PASSWORD_NG = 37,
        SEARCH_FILTER_ITEM_RANK = 38,
        SEARCH_FILTER_ITEM_RANK_MIN = 39,
        SEARCH_FILTER_ITEM_RANK_MAX = 40,
        SEARCH_FILTER_INIT = 41,
        SEARCH_FILTER_OK = 42,
        SEARCH_FILTER_CANCEL = 43,
        SEARCH_FILTER_MAX = 44,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        ERR_NO_NAME = 1,
    };
    enum
    {
        SEARCH_FILTER_TYPE_PARTY_REQ = 0,
        SEARCH_FILTER_TYPE_PAWN_RENTAL = 1,
        SEARCH_FILTER_TYPE_QUICK = 2,
        SEARCH_FILTER_TYPE_CHAR = 3,
        SEARCH_FILTER_TYPE_CLAN = 4,
        SEARCH_FILTER_TYPE_ENTRY_BOARD = 5,
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
    cMenuSearchFilter();
    virtual ~cMenuSearchFilter();
    void initSearchFilter(s32 type, cCharacterData::stSearchFilterSetting& setting, uGUIBase* pParentGUI, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveSearchFilter();
    virtual void exitMenu();  // vtable slot 15
    void initSetting();
    bool isSkillAll();
    bool isJobAll();
    cCharacterData::stSearchFilterSetting* getSetting();
    void initExcludeList();
    void deleteExcludeList();
    void setSearchTab(u32 tab);
    u32 getSearchTab();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    s32 mType;  // offset: 0xb0
    cCharacterData::stSearchFilterSetting* mpSetting;  // offset: 0xb8
    bool mSkillAll;  // offset: 0xc0
    s32 mSettingTmp;  // offset: 0xc4
    s32 mQuickPatyNumTmp;  // offset: 0xc8
    u32 mSearchTab;  // offset: 0xcc
    nCharacterData::stCharacterName mCharacterName;  // offset: 0xd0
    CommunityCharacterBaseInfoVec mExcludeList;  // offset: 0xe8
public:
    static MyDTI DTI;
};

class cMenuServerList : public cMenuBase
{
public:
    enum
    {
        SERVER_LIST_CURSOR_LIST = 0,
        SERVER_LIST_CURSOR_LIST_PAGE = 1,
        SERVER_LIST_CURSOR_MAX = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ = 1,
        RNO_WAIT = 2,
        RNO_LIST = 3,
        RNO_REQ_COMMU = 4,
        RNO_WAIT_COMMU = 5,
        RNO_CHANGE_SERVER = 6,
        RNO_FADE_WAIT = 7,
        RNO_LIST_ERROR = 8,
    };
    enum
    {
        SERVER_LIST_RNO_BASE = 0,
        SERVER_LIST_RNO_MAX = 1,
    };
    enum
    {
        SERVER_LIST_TOP = 0,
        SERVER_LIST_MAX = 256,
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
    cMenuServerList();
    virtual ~cMenuServerList();
    void initServerList();
    nMenu::MENU_RET moveServerList();
    virtual void exitMenu();  // vtable slot 15
    u32 getPageNum();
    u32 getListIndex(u32 page, u32 cursor);
    s32 getServerIndex(u32 i);
    CGameServerListInfo* getServerInfo(s32 cursorPos);
    CGameServerListInfo* getSelectServerInfo();
    s32 getServerId(s32 cursorPos);
    s32 getSelectServerId();
    MT_CTSTR getServerName(s32 cursorPos);
    MT_CTSTR getSelectServerName();
    bool isListRefresh();
    bool isGetCommunityList();
    bool isChangeServer();
private:
    void createSortList();
    void createMenuList();
private:
    u32 mSortList[256];  // offset: 0xb0
    u32 mSortListCount;  // offset: 0x4b0
    f32 mTimer;  // offset: 0x4b4
    s32 mMenuList[256];  // offset: 0x4b8
    bool mIsListRefresh;  // offset: 0x8b8
    bool mIsGetCommunityList;  // offset: 0x8b9
public:
    static MyDTI DTI;
    static const s32 SERVER_LIST_DISP_NUM = 256;
    static const s32 SERVER_SORT_LIST_MAX = 256;
};

class cMenuSetJob : public cMenuBase
{
public:
    enum
    {
        MOVE_SET_JOB_RNO_INIT = 0,
        MOVE_SET_JOB_RNO_MENU = 1,
    };
    enum
    {
        SET_JOB_RNO_BASE = 0,
        SET_JOB_RNO_MAX = 1,
    };
    enum
    {
        SET_JOB_ON_OFF = 0,
        SET_JOB_ALL = 1,
        SET_JOB_TOP = 2,
        SET_JOB_END = 11,
        SET_JOB_DECIDE = 12,
        SET_JOB_CANCEL = 13,
        SET_JOB_MAX = 14,
    };
    enum
    {
        SET_ATTR_MULTI_SELECT = 1,
        SET_ATTR_ON_OFF = 2,
        SET_ATTR_DISP_ONLY = 4,
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
    cMenuSetJob();
    virtual ~cMenuSetJob();
    void initSetJob(u32 attr, u32& dstJob, bool* pSetting, u32 setNum, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveSetJob();
    virtual void exitMenu();  // vtable slot 15
    u32 getJobId(s32 setJobIndex);
    void setJobBit(u32& dstJob, u32 jobId);
    void clearJobBit(u32& dstJob, u32 jobId);
    void flipJobBit(u32& dstJob, u32 jobId);
    bool checkJobBit(u32 job, u32 jobId);
    u32 getJob();
    bool isJobAll();
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    void setCursor(s32);
    s32 getRno();
private:
    u32 mAttr;  // offset: 0xb0
    u32* mpDstJob;  // offset: 0xb8
    u32 mJob;  // offset: 0xc0
    bool* mpDstSetting;  // offset: 0xc8
    bool mSetting;  // offset: 0xd0
    u32 mSetNum;  // offset: 0xd4
    bool mJobAll;  // offset: 0xd8
public:
    static MyDTI DTI;
};

class cMenuSetLevel : public cMenuBase
{
public:
    enum SET
    {
        SET_NONE = 0,
        SET_MIN_DIRECT = 1,
        SET_MAX_DIRECT = 2,
    };
    enum
    {
        MOVE_SET_LEVEL_RNO_INIT = 0,
        MOVE_SET_LEVEL_RNO_MENU = 1,
        MOVE_SET_LEVEL_SETUP_MIN = 2,
        MOVE_SET_LEVEL_SETUP_MAX = 3,
        MOVE_SET_LEVEL_RNO_MIN = 4,
        MOVE_SET_LEVEL_RNO_MAX = 5,
    };
    enum
    {
        SET_LEVEL_RNO_BASE = 0,
        SET_LEVEL_RNO_MAX = 1,
    };
    enum
    {
        SET_ATTR_JOBLEVEL = 1,
        SET_ATTR_CRAFTLEVEL = 2,
        SET_ATTR_CRAFTSKILL = 4,
        SET_ATTR_BASE_NOWLEVEL = 8,
        SET_ATTR_DEF_SET_AUTO = 16,
        SET_ATTR_ON_OFF = 32,
        SET_ATTR_NO_MAX = 64,
    };
    enum
    {
        SET_LEVEL_ON_OFF = 0,
        SET_LEVEL_MIN_LV = 1,
        SET_LEVEL_MAX_LV = 2,
        SET_LEVEL_DECIDE = 3,
        SET_LEVEL_CANCEL = 4,
        SET_LEVEL_MAX = 5,
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
    cMenuSetLevel();
    virtual ~cMenuSetLevel();
    void initSetLevel(u32 attr, u32* dstLevelMin, u32* dstLevelMax, bool* pSetting, u32 baseLevel, SET set, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveSetLevel();
    virtual void exitMenu();  // vtable slot 15
    u32 getMin();
    u32 getMax();
    s32 getSettingTmp();
    s32 getLevelCursorMin();
    s32 getLevelCursorMax();
    u32 getLimitLevel();
private:
    void setCursor(s32);
    s32 getRno();
private:
    u32 mAttr;  // offset: 0xb0
    bool* mpDstSetting;  // offset: 0xb8
    u32* mpDstLevelMin;  // offset: 0xc0
    u32* mpDstLevelMax;  // offset: 0xc8
    bool mSetting;  // offset: 0xd0
    u32 mMin;  // offset: 0xd4
    u32 mMax;  // offset: 0xd8
    u32 mBase;  // offset: 0xdc
    u32 mLimitLevel;  // offset: 0xe0
    s32 mSettingTmp;  // offset: 0xe4
    s32 mLevelCursorMin;  // offset: 0xe8
    s32 mLevelCursorMax;  // offset: 0xec
    SET mSet;  // offset: 0xf0
public:
    static MyDTI DTI;
};

class cMenuSetLimitPreset : public cMenuBase
{
public:
    enum
    {
        TYPE_CLAN_LEVEL = 0,
        TYPE_CLAN_MEMBER = 1,
    };
    enum
    {
        ATTR_NONE = 0,
        ATTR_OFF = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_MENU = 1,
    };
    enum
    {
        SET_LIMIT_RNO_BASE = 0,
        SET_LIMIT_RNO_MAX = 1,
    };
    enum
    {
        SET_LIMIT_OFF = 0,
        SET_LIMIT_DECIDE = 1,
        SET_LIMIT_CANCEL = 2,
        SET_LIMIT_PRESET_TOP = 3,
        SET_LIMIT_MAX = 15,
    };
public:
    class MyDTI;
    struct stPreset;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stPreset
    {
    public:
        u32 min;  // offset: 0x0
        u32 max;  // offset: 0x4
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cMenuSetLimitPreset();
    virtual ~cMenuSetLimitPreset();
    void initSetLimitPreset(u32 type, u32 attr, u32* dstLevelMin, u32* dstLevelMax, bool* pSetting);
    nMenu::MENU_RET moveSetLimitPreset();
    virtual void exitMenu();  // vtable slot 15
    u32 getLevelArrayNum();
    u32 getMemberArrayNum();
private:
    void setCursor(s32);
    s32 getRno();
private:
    u32 mType;  // offset: 0xb0
    u32 mAttr;  // offset: 0xb4
    bool* mpDstSetting;  // offset: 0xb8
    u32* mpDstLevelMin;  // offset: 0xc0
    u32* mpDstLevelMax;  // offset: 0xc8
    bool mSetting;  // offset: 0xd0
    u32 mMin;  // offset: 0xd4
    u32 mMax;  // offset: 0xd8
    u32 mPresetNum;  // offset: 0xdc
    const stPreset* mpPresetTbl;  // offset: 0xe0
    s32 mSettingTmp;  // offset: 0xe8
    s32 mLevelCursorMin;  // offset: 0xec
    s32 mLevelCursorMax;  // offset: 0xf0
public:
    static MyDTI DTI;
    static const u32 PRESET_NUM_MAX = 12;
    static const stPreset clanLevelPresetTbl[];
    static const stPreset clanMemberPresetTbl[];
};

class cMenuSimplePartyReq : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_FILTER = 1,
        RNO_REQ = 2,
        RNO_WAIT = 3,
        RNO_INVITE = 4,
        RNO_NOT_FOUND = 5,
        RNO_RETRY = 6,
        RNO_CONFIRM = 7,
        RNO_ERROR = 8,
    };
    enum
    {
        PARTY_REQ_RNO_BASE = 0,
        PARTY_REQ_RNO_MAX = 1,
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
    cMenuSimplePartyReq();
    virtual ~cMenuSimplePartyReq();
    void initSimplePartyReq(cCharacterData::stSearchFilterSetting& setting, uGUIBase* pRefGUI);
    nMenu::MENU_RET moveSimplePartyReq();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 selectReqParty();
private:
    cCharacterData::stSearchFilterSetting* mpSearchSetting;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuStartGameSession : public cMenuBase
{
public:
    enum
    {
        MOVE_START_GAME_INIT = 0,
        MOVE_START_GAME_MOVE = 1,
        MOVE_START_GAME_ERROR = 2,
    };
    enum
    {
        START_GAME_SESSION_RNO_BASE = 0,
        START_GAME_SESSION_RNO_MAX = 1,
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
    cMenuStartGameSession();
    virtual ~cMenuStartGameSession();
    void initStartGameSession(nNetSv::PLAY_START_TYPE type);
    nMenu::MENU_RET moveStartGameSession();
private:
    u32 mStartGameSessionDialogHandle;  // offset: 0xb0
    u32 mStartType;  // offset: 0xb4
public:
    static MyDTI DTI;
};

class cMenuSubMenu : public cMenuBase
{
public:
    enum
    {
        SUB_MENU_MASTER_TYPE_AUTO = 0,
        SUB_MENU_MASTER_TYPE_PL = 1,
        SUB_MENU_MASTER_TYPE_MY_PAWN = 2,
        SUB_MENU_MASTER_TYPE_RENTAL_PAWN = 3,
        SUB_MENU_MASTER_TYPE_PARTY = 4,
        SUB_MENU_MASTER_TYPE_CLAN = 5,
        SUB_MENU_MASTER_TYPE_CLAN_REQ_ID = 6,
        SUB_MENU_MASTER_TYPE_CLAN_SCOUT_ENTRY = 7,
        SUB_MENU_MASTER_TYPE_CLAN_INVITED = 8,
        SUB_MENU_MASTER_TYPE_CLAN_INVITE = 9,
        SUB_MENU_MASTER_TYPE_SEARCH_PAWN = 10,
        SUB_MENU_MASTER_TYPE_LEGEND_PAWN = 11,
        SUB_MENU_MASTER_TYPE_OFFICIAL_PAWN = 12,
        SUB_MENU_MASTER_TYPE_FAVORITE_PAWN = 13,
        SUB_MENU_MASTER_TYPE_MAIL = 14,
    };
    enum
    {
        SUB_MENU_TYPE_PARTY_MEMBER_MYSELF = 0,
        SUB_MENU_TYPE_PARTY_MEMBER = 1,
        SUB_MENU_TYPE_PARTY_MEMBER_PREPARE = 2,
        SUB_MENU_TYPE_PARTY_IN_PL = 3,
        SUB_MENU_TYPE_PARTY_IN_PAWN = 4,
        SUB_MENU_TYPE_REQ_LIST = 5,
        SUB_MENU_TYPE_INVITE = 6,
        SUB_MENU_TYPE_CLAN = 7,
        SUB_MENU_TYPE_CLAN_APPLY_LIST = 8,
        SUB_MENU_TYPE_CLAN_JOIN_REQ_LIST = 9,
        SUB_MENU_TYPE_CLAN_MY_MEMBER_LIST = 10,
        SUB_MENU_TYPE_CLAN_MEMBER_LIST = 11,
        SUB_MENU_TYPE_CLAN_SCOUT_LIST = 12,
        SUB_MENU_TYPE_CLAN_INVITED_LIST = 13,
        SUB_MENU_TYPE_CLAN_INVITE_LIST = 14,
        SUB_MENU_TYPE_CLAN_DIRECT_INVITED_LIST = 15,
        SUB_MENU_TYPE_FRIEND = 16,
        SUB_MENU_TYPE_FRIEND_APPLYING_LIST = 17,
        SUB_MENU_TYPE_FRIEND_APPLIED_LIST = 18,
        SUB_MENU_TYPE_PAWN_SEARCH_LIST = 19,
        SUB_MENU_TYPE_MAIN_PAWN = 20,
        SUB_MENU_TYPE_SUPPORT_PAWN = 21,
        SUB_MENU_TYPE_ENTRY_MEMBER = 22,
        SUB_MENU_TYPE_GROUP_CHAT = 23,
        SUB_MENU_TYPE_TOUCH_PL = 24,
        SUB_MENU_TYPE_TOUCH_PAWN = 25,
        SUB_MENU_TYPE_BLACK_LIST = 26,
        SUB_MENU_TYPE_RECENT_LIST = 27,
        SUB_MENU_TYPE_CHAT_LOG = 28,
        SUB_MENU_TYPE_MAIL = 29,
        SUB_MENU_TYPE_LOST_PAWN = 30,
        SUB_MENU_TYPE_CHARACTER_LIST = 31,
        SUB_MENU_TYPE_MAX = 32,
    };
    enum
    {
        SUB_MENU_STATUS = 0,
        SUB_MENU_TELL = 1,
        SUB_MENU_FRIEND = 2,
        SUB_MENU_KICK = 3,
        SUB_MENU_LEADER = 4,
        SUB_MENU_CANCEL_INVITE = 5,
        SUB_MENU_INVITE = 6,
        SUB_MENU_PARTY_DETAIL = 7,
        SUB_MENU_PARTY_JOIN = 8,
        SUB_MENU_PARTY_DECLINE = 9,
        SUB_MENU_APPLY_CLAN = 10,
        SUB_MENU_CANCEL_APPLY_CLAN = 11,
        SUB_MENU_ALLOW_APPLY_CLAN = 12,
        SUB_MENU_DENY_APPLY_CLAN = 13,
        SUB_MENU_CLAN_DETAIL = 14,
        SUB_MENU_CLAN_INVITE = 15,
        SUB_MENU_CANCEL_CLAN_INVITE = 16,
        SUB_MENU_ALLOW_INVITE_CLAN = 17,
        SUB_MENU_DENY_INVITE_CLAN = 18,
        SUB_MENU_EXPEL_CLAN_MEMBER = 19,
        SUB_MENU_CHANGE_CLAN_MASTER = 20,
        SUB_MENU_SET_CLAN_SUB_MASTER = 21,
        SUB_MENU_RESET_CLAN_SUB_MASTER = 22,
        SUB_MENU_CLAN_DIRECT_INVITE = 23,
        SUB_MENU_ALLOW_INVITE_CLAN_DIRECT = 24,
        SUB_MENU_DENY_INVITE_CLAN_DIRECT = 25,
        SUB_MENU_CANCEL_FRIEND = 26,
        SUB_MENU_ALLOW_APPLY_FRIEND = 27,
        SUB_MENU_DENY_APPLY_FRIEND = 28,
        SUB_MENU_REMOVE_FRIEND = 29,
        SUB_MENU_FAVORITE_FRIEND = 30,
        SUB_MENU_FAVORITE_PAWN = 31,
        SUB_MENU_FAVORITE_OFF = 32,
        SUB_MENU_RENTAL_PAWN = 33,
        SUB_MENU_CUSTOMIZE_PAWN = 34,
        SUB_MENU_PAWN_DELETE = 35,
        SUB_MENU_PAWN_REG_SETTING = 36,
        SUB_MENU_PAWN_HISTORY = 37,
        SUB_MENU_PAWN_RETURN = 38,
        SUB_MENU_CARD = 39,
        SUB_MENU_GROUP_CHAT = 40,
        SUB_MENU_GROUP_CHAT_KICK = 41,
        SUB_MENU_AUTORUN = 42,
        SUB_MENU_ADD_BLACKLIST = 43,
        SUB_MENU_REMOVE_BLACKLIST = 44,
        SUB_MENU_DELETE_MAIL = 45,
        SUB_MENU_PARTY_BREAKUP = 46,
        SUB_MENU_LOST_PAWN_REVIVE = 47,
        SUB_MENU_PAWN_TALK = 48,
        SUB_MENU_PAWN_POINT = 49,
        SUB_MENU_INVITE_ENTRY = 50,
        SUB_MENU_PAWN_CRAFT_RESET = 51,
        SUB_MENU_PAWN_SET_PARTNER = 52,
        SUB_MENU_CLAN_AUTHORITY = 53,
        SUB_MENU_MAX = 54,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_MENU = 2,
        RNO_STATUS = 3,
        RNO_TELL = 4,
        RNO_FRIEND = 5,
        RNO_KICK = 6,
        RNO_LEADER = 7,
        RNO_INVITE = 8,
        RNO_PARTY_DETAIL = 9,
        RNO_JOIN_WAIT = 10,
        RNO_JOIN = 11,
        RNO_APPLY_CLAN = 12,
        RNO_CANCEL_APPLY_CLAN = 13,
        RNO_ALLOW_APPLY_CLAN = 14,
        RNO_DENY_APPLY_CLAN = 15,
        RNO_CLAN_DETAIL = 16,
        RNO_CLAN_INVITE = 17,
        RNO_CANCEL_CLAN_INVITE = 18,
        RNO_ALLOW_INVITE_CLAN = 19,
        RNO_DENY_INVITE_CLAN = 20,
        RNO_EXPEL_CLAN_MEMBER = 21,
        RNO_CHANGE_CLAN_MASTER = 22,
        RNO_SET_CLAN_MEMBER_RANK = 23,
        RNO_CLAN_DIRECT_INVITE = 24,
        RNO_ALLOW_INVITE_CLAN_DIRECT = 25,
        RNO_DENY_INVITE_CLAN_DIRECT = 26,
        RNO_CANCEL_FRIEND = 27,
        RNO_ALLOW_APPLY_FRIEND = 28,
        RNO_DENY_APPLY_FRIEND = 29,
        RNO_REMOVE_FRIEND = 30,
        RNO_FAVORITE_FRIEND = 31,
        RNO_RENTAL_PAWN = 32,
        RNO_CUSTOMIZE_PAWN = 33,
        RNO_PAWN_DELETE = 34,
        RNO_PAWN_REG_SETTING = 35,
        RNO_PAWN_HISTORY = 36,
        RNO_PAWN_RETURN = 37,
        RNO_CARD = 38,
        RNO_GROUP_CHAT = 39,
        RNO_GROUP_CHAT_KICK = 40,
        RNO_ADD_BLACKLIST = 41,
        RNO_REMOVE_BLACKLIST = 42,
        RNO_FAVORITE_PAWN = 43,
        RNO_FAVORITE_PAWN_OFF = 44,
        RNO_DELETE_MAIL = 45,
        RNO_PARTY_BREAKUP = 46,
        RNO_LOST_PAWN_REVIVE = 47,
        RNO_PAWN_TALK = 48,
        RNO_PAWN_POINT = 49,
        RNO_INVITE_ENTRY = 50,
        RNO_PAWN_CRAFT_RESET = 51,
        RNO_PAWN_SET_PARTNER = 52,
        RNO_CLAN_AUTHORITY = 53,
    };
    enum
    {
        SUB_MENU_RNO_BASE = 0,
        SUB_MENU_RNO_SUB = 1,
        SUB_MENU_RNO_MAX = 2,
    };
    enum
    {
        MOVE_SUB_MENU_SUB_RNO_CLAN_DETAIL_GET = 0,
        MOVE_SUB_MENU_SUB_RNO_CLAN_DETAIL_DISP = 1,
    };
    enum
    {
        ERR_UNKNOWN = 0,
        KICK_ERR_NOT_OWNER_PAWN = 1,
        KICK_ERR_NOT_PARTY = 2,
        KICK_ERR_NOT_LEADER = 3,
        KICK_ERR_MYSELF = 4,
        KICK_ERR_EXIST_SUPPORT_PAWN = 5,
        KICK_ERR_QUICK_PARTY = 6,
        KICK_ERR_CONTENTS = 7,
        KICK_ERR_PAWN_OTHER = 8,
        CHANGE_LEADER_ERR_NOT_PL = 9,
        CHANGE_LEADER_ERR_NOT_PARTY = 10,
        CHANGE_LEADER_ERR_AREA = 11,
        CHANGE_LEADER_ERR_PERMISSION = 12,
        CHANGE_LEADER_ERR_ALREADY = 13,
        CHANGE_LEADER_ERR_QUICK = 14,
        INVITE_PARTY_ERR_NOT_ONLINE = 15,
        INVITE_PARTY_ERR_LOST_PAWN = 16,
        INVITE_PARTY_ERR_ALREADY_PAWN = 17,
        INVITE_PARTY_ERR_CRAFT_PAWN = 18,
        INVITE_PARTY_ERR_SALLY_PAWN = 19,
        INVITE_PARTY_ERR_ADVENTURE_NUM = 20,
        INVITE_PARTY_ERR_NO_MAIN_PAWN = 21,
        INVITE_PARTY_ERR_NOT_LEADER = 22,
        INVITE_PARTY_ERR_PLACE = 23,
        INVITE_PARTY_ERR_ALREADY_PL = 24,
        INVITE_PARTY_ERR_INVITED = 25,
        INVITE_PARTY_ERR_MYSELF = 26,
        INVITE_PARTY_ERR_PROGRESS_PL = 27,
        INVITE_PARTY_ERR_PROGRESS_PAWN = 28,
        INVITE_PARTY_ERR_QUICK_PARTY = 29,
        INVITE_PARTY_ERR_PARTY_LARGE = 30,
        INVITE_PARTY_ERR_FULL = 31,
        INVITE_PARTY_ERR_PRT = 32,
        JOIN_PARTY_ERR_UNABLE_READY = 33,
        APPLY_CLAN_ERR_ALREADY_JOIN = 34,
        PAWN_RENTAL_ERR_RIM = 35,
        PAWN_RENTAL_ERR_NO_SPACE = 36,
        PAWN_DELETE_ERR_PARTY = 37,
        PAWN_DELETE_ERR_CRAFT = 38,
        PAWN_DELETE_ERR_LAST_ONE = 39,
        PAWN_DELETE_ERR_PARTNER = 40,
        PAWN_RETURN_ERR_PARTY = 41,
        PAWN_RETURN_ERR_CRAFT = 42,
        CARD_ERR_NOT_ONLINE = 43,
        CARD_ERR_ALREADY_OPEN = 44,
        CARD_ERR_AREA_CHANGE = 45,
        GROUP_CHAT_ERR_NOT_ONLINE = 46,
        GROUP_CHAT_ERR_ALREDY_MEMBER = 47,
        GROUP_CHAT_ERR_NOT_PLAYER = 48,
        GROUP_CHAT_ERR_MYSELF = 49,
        GROUP_CHAT_KICK_ERR_MYSELF = 50,
        CLAN_ERR_PERMISSION = 51,
        EXPEL_CLAN_ERR_MYSELF = 52,
        CHANGE_CLAN_MASTER_ERR_MYSELF = 53,
        CHANGE_CLAN_MASTER_ERR_INTERVAL = 54,
        SET_CLAN_MEMBER_RANK_ERR_MYSELF = 55,
        SET_CLAN_MEMBER_RANK_ERR_INTERVAL = 56,
        CLAN_DIRECT_INVITE_ERR_ALREADY = 57,
        CLAN_DIRECT_INVITE_ERR_OFFLINE = 58,
        FRIEND_ERR_MYSELF = 59,
        FRIEND_ERR_PAWN = 60,
        FRIEND_ERR_OFFLINE = 61,
        TELL_ERR_NOT_ONLINE = 62,
        TELL_ERR_MYSELF = 63,
        TELL_ERR_PAWN = 64,
        AUTORUN_ERR_PAWN = 65,
        AUTORUN_ERR_MYSELF = 66,
        AUTORUN_ERR_NO_PARTY = 67,
        AUTORUN_ERR_NO_UNIT = 68,
        AUTORUN_ERR_OTHER = 69,
        MAIL_ERR_NOT_RECEIVE_ITEM = 70,
        BREAKUP_ERR_NOT_LEADER = 71,
        BREAKUP_ERR_QUICK_PARTY = 72,
        BREAKUP_ERR_CONTENTS = 73,
        BREAKUP_ERR_SOLO = 74,
        BREAKUP_ERR_BATTLE = 75,
        LOST_PAWN_REVIVE_ERR_RIM = 76,
        PAWN_TALK_ERR_NOT_OWNER = 77,
        PAWN_TALK_ERR_FAR = 78,
        PAWN_TALK_ERR_BATTLE = 79,
        PAWN_TALK_ERR_OTHER = 80,
        INVITE_ENTRY_ERR_OFFLINE = 81,
        INVITE_ENTRY_ERR_NOT_ENTRY = 82,
        INVITE_ENTRY_ERR_PAWN = 83,
        INVITE_ENTRY_ERR_MYSELF = 84,
        INVITE_ENTRY_ERR_SOLO = 85,
        INVITE_ENTRY_ERR_CLAN = 86,
        PAWN_CRAFT_RESET_ERR_PARTY = 87,
        PAWN_CRAFT_RESET_ERR_CRAFT = 88,
        PAWN_CRAFT_RESET_NO_RIGHT = 89,
        PAWN_CRAFT_RESET_NO_RESET = 90,
        PAWN_SET_PARTNER_ERR_NOT_MYROOM = 91,
        PAWN_SET_PARTNER_ERR_ALREADY_PARTNER = 92,
        PAWN_SET_PARTNER_ERR_REWARD_AVAILABLE = 93,
        PAWN_SET_PARTNER_ERR_QUEST_ORDER = 94,
        PAWN_SET_PARTNER_ERR_PAWN_EXPEDITION = 95,
        AUTHORITY_ERR_MYSELF = 96,
        AUTHORITY_ERR_INTERVAL = 97,
        CLAN_APPLY_ERR_ALREADY = 98,
        ERR_MAX = 99,
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
    cMenuSubMenu();
    virtual ~cMenuSubMenu();
    void initSubMenu(s32 menuType, u32 masterId, s32 masterType, MT_CTSTR pName, MT_CTSTR pLastName, MT_CTSTR pClanName);
    void initSubMenu(s32 menuType, u32 masterId, s32 masterType, u32 mSubId);
    void initSubMenu(s32 menuType, u32 masterId, s32 masterType, cPawnListParam* pPawnParam, bool posFix);
    void initSubMenu(s32 menuType, u32 masterId, s32 masterType, CDataClientPartyListInfo* pPartyParam);
    void initSubMenu(s32 menuType, u32 masterId, s32 masterType, CEntryMemberData* pEntryMember);
    void initSubMenu(s32 menuType, CClanScoutEntrySearchResult* pScoutEntryParam);
    void initSubMenuCore(s32 menuType, u32 masterId, s32 masterType, cPawnListParam* pPawnParam, CDataClientPartyListInfo* pPartyParam, MT_CTSTR pName, MT_CTSTR pLastName, MT_CTSTR pClanName, CEntryMemberData* pEntryMember, CClanScoutEntrySearchResult* pScoutEntryParam, u32 subId, bool posFix);
    nMenu::MENU_RET moveSubMenu();
    virtual void exitMenu();  // vtable slot 15
    s32 getMenuType() const;
    void setBasePointerPrio(cMenuBase* pMenuBase);
    void setBasePointerPrio(u32 prio);
    void setBasePointerPrio(uGUIBase* pParentGUI);
    void setupGUIMenu();
    void setCursorMenu(s32 menu);
    s32 getCursorPosMain();
    bool isReqCancelForce() const;
    void setReqCancelForce(bool bReq);
    void createBaseInfo(CCommunityCharacterBaseInfo& baseInfo);
    virtual void checkMenuPartsParam(cMenuSupportMenu* pMenu, nMenu::MENU_PARTS* pParts, s32 menuId);  // vtable slot 17
private:
    void setListElement(const CCharacterListElement& elem);
    void setBaseInfo(const CCommunityCharacterBaseInfo& info);
    void setContextInfo(const cContextInstHm& context);
    void initJoinFlow();
    void createMenuList();
    void convertInviteToKick();
    const cContextInstHm* searchContext(u32 charId, u32 pawnId, bool partyOnly);
    uDDOModel* searchUnit(u32 charId, u32 pawnId);
    bool isOnline();
private:
    s32 mMenuType;  // offset: 0xb0
    s32 mMasterType;  // offset: 0xb4
    u32 mMasterId;  // offset: 0xb8
    u32 mSubId;  // offset: 0xbc
    cPawnListParam* mpPawnParam;  // offset: 0xc0
    CDataClientPartyListInfo* mpPartyParam;  // offset: 0xc8
    u8 mJob;  // offset: 0xd0
    u32 mLv;  // offset: 0xd4
    MtString mName;  // offset: 0xd8
    CClanParam mClanParam;  // offset: 0xe0
    u32 mCharacterId;  // offset: 0x1e8
    u32 mPawnId;  // offset: 0x1ec
    u32 mClanId;  // offset: 0x1f0
    CHAR_NAME mCharacterName;  // offset: 0x1f4
    MtString mClanNickname;  // offset: 0x210
    u32 mUseRim;  // offset: 0x218
    u8 mOnlineStatus;  // offset: 0x21c
    u32 mBasePointerPrio;  // offset: 0x220
    u32 mMemberNum;  // offset: 0x224
    s32 mInitCursor;  // offset: 0x228
    f32 mTimer;  // offset: 0x22c
    s32 mWaitTimer;  // offset: 0x230
    bool mIsFavorite;  // offset: 0x234
    bool mPosFix;  // offset: 0x235
    bool mIsSingletonMenu;  // offset: 0x236
    bool mIsReqCancelForce;  // offset: 0x237
public:
    static MyDTI DTI;
};

class cMenuTraining : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_LIST_WAIT = 1,
        RNO_WAIT = 2,
        RNO_SET_WAIT = 3,
    };
    enum
    {
        RNO_BASE = 0,
        RNO_MAX = 1,
    };
    enum
    {
        FILTER_ID = 0,
        FILTER_LEVEL = 1,
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
    cMenuTraining();
    virtual ~cMenuTraining();
    void initMenuTraining(u32 moveline);
    nMenu::MENU_RET moveMenuTraining();
public:
    static MyDTI DTI;
};

class cMenuTreasuresLot : public cMenuBase
{
public:
    enum
    {
        RNO_LIST_GET = 0,
        RNO_LOT_SELECT = 1,
        RNO_GP_SHOP = 2,
        RNO_BOUGHT_BOX = 3,
        RNO_LOT_DRAW = 4,
        RNO_ANNOUNCE = 5,
        RNO_RESULT = 6,
        RNO_DIALOG = 7,
        RNO_END_PERFORMANCE = 8,
        RNO_RESTART = 9,
        RNO_LOT_MENU_SETLECT = 10,
        RNO_RESET = 11,
        RNO_RESET_WAIT = 12,
        RNO_SHOP = 13,
    };
    enum
    {
        TREASURESLOT_RNO_BASE = 0,
        TREASURESLOT_RNO_MAX = 1,
    };
    enum
    {
        TYPE_MENU = 0,
        TYPE_NPC = 1,
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
    cMenuTreasuresLot();
    virtual ~cMenuTreasuresLot();
    void initTreasuresLotMenu(u32 type, u32 moveLine);
    nMenu::MENU_RET moveTreasuresLotMenu();
    virtual void updatePtr();  // vtable slot 6
    virtual void exitMenu();  // vtable slot 15
protected:
    bool isInit();
    void setRno(s32 rno, bool isInit);
private:
    uGUIGPShopDialog* mpGUIGPShopDialog;  // offset: 0xb0
    uGUIBoughtBox* mpGUIBoughtBox;  // offset: 0xb8
    uGUIPopTopSel* mpGUITopSel;  // offset: 0xc0
    uGUIGPShop* mpGUIGPShop;  // offset: 0xc8
    u32 mType;  // offset: 0xd0
    u32 mMoveLine;  // offset: 0xd4
    bool mCheckDraw;  // offset: 0xd8
    bool mIsInit;  // offset: 0xd9
    bool mBox;  // offset: 0xda
public:
    static MyDTI DTI;
};

class cMenuTreasuresLotAnnounce : public cMenuBase
{
public:
    enum
    {
        RNO_MOVE = 0,
    };
    enum
    {
        TREASURESLOT_ANNOUNCE_RNO_BASE = 0,
        TREASURESLOT_ANNOUNCE_RNO_MAX = 1,
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
    cMenuTreasuresLotAnnounce();
    virtual ~cMenuTreasuresLotAnnounce();
    void initTreasuresLotAnnounce(u32 moveLine, bool box);
    nMenu::MENU_RET moveTreasuresLotAnnounce();
    virtual void exitMenu();  // vtable slot 15
public:
    static MyDTI DTI;
};

class cMenuUILargeSetting : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_SAVE = 2,
        RNO_SAVE_WAIT = 3,
        RNO_END = 4,
    };
    enum
    {
        UI_LARGE_SETTING_RNO_MAIN_BASE = 0,
        UI_LARGE_SETTING_RNO_MAX = 1,
    };
    enum
    {
        FIRST_DIALOG = 0,
        CHECK_DIALOG = 1,
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
    cMenuUILargeSetting();
    virtual ~cMenuUILargeSetting();
    void init();
    nMenu::MENU_RET move();
private:
    bool isLarge;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuUpdateCommunityList : public cMenuBase
{
public:
    enum
    {
        UPDATE_COMMUNITY_LIST_CURSOR_LIST = 0,
        UPDATE_COMMUNITY_LIST_CURSOR_MAX = 1,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_REQ_FRIEND = 1,
        RNO_WAIT_FRIEND = 2,
        RNO_WAIT_CLAN = 3,
        RNO_WAIT_CLAN_SCOUT_ENTRY = 4,
        RNO_WAIT_CLAN_INVITED = 5,
        RNO_WAIT_CLAN_APPLY = 6,
        RNO_WAIT_CLAN_MEMBER = 7,
        RNO_WAIT_CLAN_APPROVED_LIST = 8,
        RNO_REQ_RECENT_LIST = 9,
        RNO_WAIT_RECENT_LIST = 10,
        RNO_WAIT_BLACK_LIST = 11,
        RNO_ERROR = 12,
    };
    enum
    {
        UPDATE_COMMUNITY_LIST_RNO_BASE = 0,
        UPDATE_COMMUNITY_LIST_RNO_MAX = 1,
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
    cMenuUpdateCommunityList();
    virtual ~cMenuUpdateCommunityList();
    void initUpdateCommunityList(bool isGetRecentList);
    nMenu::MENU_RET moveUpdateCommunityList();
    virtual void exitMenu();  // vtable slot 15
private:
    bool mIsGetRecentList;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cMenuActiveList : public cMenuBase
{
public:
    enum LIST_TYPE
    {
        LIST_TYPE_INVALID = 0,
        LIST_TYPE_FRIEND = 1,
        LIST_TYPE_CLAN = 2,
    };
    enum
    {
        ACTIVE_LIST_CURSOR_LIST = 0,
        ACTIVE_LIST_CURSOR_LIST_PAGE = 1,
        ACTIVE_LIST_CURSOR_MAX = 2,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_WAIT = 1,
        RNO_LIST = 2,
        RNO_SUB_MENU = 3,
    };
    enum
    {
        ACTIVE_LIST_RNO_BASE = 0,
        ACTIVE_LIST_RNO_MAX = 1,
    };
    enum
    {
        ACTIVE_LIST_TOP = 0,
    };
    enum
    {
        TYPE_NORMAL = 0,
        TYPE_TELL = 1,
        TYPE_RET_NAME = 2,
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
    cMenuActiveList();
    virtual ~cMenuActiveList();
    void initActiveList(uGUIBase* pRefGUI, s32 type, nCharacterData::stCharacterName* pDstName, u32* pCharacterId, CommunityCharacterBaseInfoVec* pExcludeList);
    nMenu::MENU_RET moveActiveList();
    virtual void exitMenu();  // vtable slot 15
    u32 getPageNum();
    u32 getListIndex(u32 page, u32 cursor);
    u32 getListType(u32 index);
    u32 getSortIndex(u32 index);
    u32 getSortCount();
    void createSortList(bool clearOnly);
    bool getRemakeListFlag();
    u32 getActiveListDispNum();
    s32 getRno();
private:
    void createMenuList();
    bool isExclude(u32 characterId);
    void updateSortList();
    void removeMember(u32 index);
private:
    s32 mType;  // offset: 0xb0
    u32* mpSortList;  // offset: 0xb8
    u32* mpSortCharId;  // offset: 0xc0
    LIST_TYPE* mpListType;  // offset: 0xc8
    u32 mSortListCount;  // offset: 0xd0
    nCharacterData::stCharacterName* mpDstName;  // offset: 0xd8
    u32* mpDstCharacterId;  // offset: 0xe0
    CommunityCharacterBaseInfoVec* mpExcludeList;  // offset: 0xe8
    f32 mWaitTimer;  // offset: 0xf0
    bool mIsRemakeList;  // offset: 0xf4
public:
    static MyDTI DTI;
};

class cMenuApplyFriend : public cMenuBase
{
public:
    enum
    {
        MOVE_APPLY_FRIEND_RNO_DLG_FLOW = 0,
    };
    enum
    {
        APPLY_FRIEND_RNO_BASE = 0,
        APPLY_FRIEND_RNO_MAX = 1,
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
    cMenuApplyFriend();
    virtual ~cMenuApplyFriend();
    void initApplyFriend(u32 charId, MtString& friendFirstName, MtString& friendLastName);
    nMenu::MENU_RET moveApplyFriend();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mCharacterId;  // offset: 0xb0
    MtString mFriendFirstName;  // offset: 0xb8
    MtString mFriendLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuApproveFriend : public cMenuBase
{
public:
    enum
    {
        APPROVE_FRIEND_TYPE_ALLOW = 0,
        APPROVE_FRIEND_TYPE_DENY = 1,
    };
    enum
    {
        MOVE_APPROVE_FRIEND_RNO_DLG_FLOW = 0,
    };
    enum
    {
        APPROVE_FRIEND_RNO_BASE = 0,
        APPROVE_FRIEND_RNO_MAX = 1,
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
    cMenuApproveFriend();
    virtual ~cMenuApproveFriend();
    void initApproveFriend(u32 type, u32 reqId, MtString& charFirstName, MtString& charLastName);
    nMenu::MENU_RET moveApproveFriend();
    virtual void exitMenu();  // vtable slot 15
private:
    u32 mType;  // offset: 0xb0
    u32 mReqId;  // offset: 0xb4
    MtString mCharFirstName;  // offset: 0xb8
    MtString mCharLastName;  // offset: 0xc0
public:
    static MyDTI DTI;
};

class cMenuAreaMaster : public cMenuBase
{
public:
    enum
    {
        MOVE_AREA_MASTER_RNO_INIT = 0,
        MOVE_AREA_MASTER_RNO_MENU = 1,
        MOVE_AREA_MASTER_RNO_RANK_UP = 2,
        MOVE_AREA_MASTER_RNO_QUEST_INFO = 3,
        MOVE_AREA_MASTER_RNO_SPOT_INFO = 4,
        MOVE_AREA_MASTER_RNO_HISTORY = 5,
        MOVE_AREA_MASTER_RNO_SUPPLIES = 6,
    };
    enum
    {
        AREA_MASTER_RNO_BASE = 0,
        AREA_MASTER_RNO_MAX = 1,
    };
    enum
    {
        AREA_MASTER_QUEST_INFO = 0,
        AREA_MASTER_SPOT_INFO = 1,
        AREA_MASTER_HISTORY = 2,
        AREA_MASTER_SUPPLIES = 3,
        AREA_MASTER_MAX = 4,
    };
    enum
    {
        AREA_MASTER_CURSOR_SELECT = 0,
        AREA_MASTER_CURSOR_MAX = 1,
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
    cMenuAreaMaster();
    virtual ~cMenuAreaMaster();
    void initAreaMaster();
    nMenu::MENU_RET moveAreaMaster();
    virtual void exitMenu();  // vtable slot 15
    s32 getSuppliesTalkMsgNo();
    void resetSuppliesTalkMsgNo();
private:
    s32 mSuppliesTalkMsgNo;  // offset: 0xb0
    TICKET mArcTicket;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuAreaMasterHistory : public cMenuBase
{
public:
    enum
    {
        MOVE_AREA_MASTER_HISTORY_RNO_INIT = 0,
        MOVE_AREA_MASTER_HISTORY_RNO_MENU = 1,
    };
    enum
    {
        AREA_MASTER_HISTORY_RNO_BASE = 0,
        AREA_MASTER_HISTORY_RNO_MAX = 1,
    };
    enum
    {
        AREA_MASTER_HISTORY_RETURN = 0,
        AREA_MASTER_HISTORY_MAX = 1,
    };
    enum
    {
        AREA_MASTER_HISTORY_CURSOR_SELECT = 0,
        AREA_MASTER_HISTORY_CURSOR_MAX = 1,
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
    cMenuAreaMasterHistory();
    virtual ~cMenuAreaMasterHistory();
    void initAreaMasterHistory();
    nMenu::MENU_RET moveAreaMasterHistory();
public:
    static MyDTI DTI;
};

class cMenuAreaMasterQuestInfo : public cMenuBase
{
public:
    enum
    {
        MOVE_AREA_MASTER_QUEST_INFO_RNO_INIT = 0,
        MOVE_AREA_MASTER_QUEST_INFO_RNO_MENU = 1,
    };
    enum
    {
        AREA_MASTER_QUEST_INFO_RNO_BASE = 0,
        AREA_MASTER_QUEST_INFO_RNO_MAX = 1,
    };
    enum
    {
        AREA_MASTER_QUEST_INFO_RETURN = 0,
        AREA_MASTER_QUEST_INFO_MAX = 1,
    };
    enum
    {
        AREA_MASTER_QUEST_INFO_CURSOR_SELECT = 0,
        AREA_MASTER_QUEST_INFO_CURSOR_MAX = 1,
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
    cMenuAreaMasterQuestInfo();
    virtual ~cMenuAreaMasterQuestInfo();
    void initAreaMasterQuestInfo();
    nMenu::MENU_RET moveAreaMasterQuestInfo();
public:
    static MyDTI DTI;
};

class cMenuAreaMasterRankUp : public cMenuBase
{
public:
    enum
    {
        MOVE_AREA_MASTER_RANK_UP_RNO_INIT = 0,
        MOVE_AREA_MASTER_RANK_UP_RNO_REQ_WAIT = 1,
        MOVE_AREA_MASTER_RANK_UP_RNO_RANK_UP = 2,
        MOVE_AREA_MASTER_RANK_UP_RNO_RANK_UP_WAIT = 3,
        MOVE_AREA_MASTER_RANK_UP_RNO_RANK_UP_MESS = 4,
        MOVE_AREA_MASTER_RANK_UP_RNO_REWARD = 5,
        MOVE_AREA_MASTER_RANK_UP_RNO_RANK_ERROR = 6,
    };
    enum
    {
        AREA_MASTER_RANK_UP_RNO_BASE = 0,
        AREA_MASTER_RANK_UP_RNO_MAX = 1,
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
    cMenuAreaMasterRankUp();
    virtual ~cMenuAreaMasterRankUp();
    void initAreaMasterRankUp();
    nMenu::MENU_RET moveAreaMasterRankUp();
    virtual void updatePtr();  // vtable slot 6
    virtual void exitMenu();  // vtable slot 15
    s32 getRequestMessage() const;
    void resetRequestMessage();
private:
    u32 mRank;  // offset: 0xb0
    s32 mRequestMessage;  // offset: 0xb4
    uGUIRankUp* mpGUIRankUp;  // offset: 0xb8
public:
    static MyDTI DTI;
};

class cMenuAreaMasterSpotInfo : public cMenuBase
{
public:
    enum
    {
        MOVE_AREA_MASTER_SPOT_INFO_RNO_INIT = 0,
        MOVE_AREA_MASTER_SPOT_INFO_RNO_MENU = 1,
    };
    enum
    {
        AREA_MASTER_SPOT_INFO_RNO_BASE = 0,
        AREA_MASTER_SPOT_INFO_RNO_MAX = 1,
    };
    enum
    {
        AREA_MASTER_SPOT_INFO_RETURN = 0,
        AREA_MASTER_SPOT_INFO_MAX = 1,
    };
    enum
    {
        AREA_MASTER_SPOT_INFO_CURSOR_SELECT = 0,
        AREA_MASTER_SPOT_INFO_CURSOR_MAX = 1,
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
    cMenuAreaMasterSpotInfo();
    virtual ~cMenuAreaMasterSpotInfo();
    void initAreaMasterSpotInfo();
    nMenu::MENU_RET moveAreaMasterSpotInfo();
public:
    static MyDTI DTI;
};

class cMenuAreaMasterSupplies : public cMenuBase
{
public:
    enum
    {
        MOVE_AREA_MASTER_SUPPLIES_RNO_INIT = 0,
        MOVE_AREA_MASTER_SUPPLIES_RNO_MENU = 1,
    };
    enum
    {
        AREA_MASTER_SUPPLIES_RNO_BASE = 0,
        AREA_MASTER_SUPPLIES_RNO_MAX = 1,
    };
    enum
    {
        AREA_MASTER_SUPPLIES_RETURN = 0,
        AREA_MASTER_SUPPLIES_MAX = 1,
    };
    enum
    {
        AREA_MASTER_SUPPLIES_CURSOR_SELECT = 0,
        AREA_MASTER_SUPPLIES_CURSOR_MAX = 1,
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
    cMenuAreaMasterSupplies();
    virtual ~cMenuAreaMasterSupplies();
    void initAreaMasterSupplies();
    nMenu::MENU_RET moveAreaMasterSupplies();
public:
    static MyDTI DTI;
};

class cMenuBaggageMenu : public cMenuBase
{
public:
    enum
    {
        RNO_INIT = 0,
        RNO_LIST = 1,
        RNO_SERVER = 2,
        RNO_BAGGAGE_INIT = 3,
        RNO_BAGGAGE = 4,
        RNO_ERROR = 5,
    };
    enum
    {
        BAGGAGE_RNO_BASE = 0,
        BAGGAGE_RNO_SERVER = 1,
        BAGGAGE_RNO_MAX = 2,
    };
    enum
    {
        BAGGAGE_NONE = 0,
        BAGGAGE_LIST_TOP = 1,
        BAGGAGE_FREE = 1,
        BAGGAGE_RENTAL_1 = 2,
        BAGGAGE_MAX = 3,
    };
    enum
    {
        RNO_1_ITEM_LIST_REQ = 0,
        RNO_1_ITEM_LIST_WAIT = 1,
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
    cMenuBaggageMenu();
    virtual ~cMenuBaggageMenu();
    void initBaggageMenu();
    nMenu::MENU_RET moveBaggageMenu();
    virtual void exitMenu();  // vtable slot 15
private:
    uGUIItemBaggageEx* mpGUIItemBaggage;  // offset: 0xb0
    uGUIGPShop* mpGUIGPShop;  // offset: 0xb8
    nItem::E_STORAGE_TYPE mLeftStorage;  // offset: 0xc0
    nItem::E_STORAGE_TYPE mRightStorage;  // offset: 0xc4
public:
    static MyDTI DTI;
    static const u32 DISP_LIST_MAX = 5;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cMenuMail::getSortListCount() {
    return this->mSortListCount;
}
