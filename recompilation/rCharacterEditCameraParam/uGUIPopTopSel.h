#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/nDDOUtility.h"
#include "../shared/uGUIBase.h"
#include "uGUIPopBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cContextInstHm;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIPopTopSel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIPopTopSel : public uGUIPopBase
{
public:
    enum CLAN_MENU_ID
    {
        CLAN_MENU_ID_CREATE = 0,
        CLAN_MENU_ID_MANAGE = 1,
        CLAN_MENU_ID_FIND = 2,
        CLAN_MENU_ID_SCOUT_ENTRY = 3,
        CLAN_MENU_ID_SCOUT_ENTRY_CANCEL = 4,
        CLAN_MENU_ID_SCOUT_ENTRY_LIST = 5,
        CLAN_MENU_ID_DEMAND = 6,
        CLAN_MENU_ID_INVITE = 7,
        CLAN_MENU_ID_DIRECT_INVITE = 8,
        CLAN_MENU_ID_DEMAND_LIST = 9,
        CLAN_MENU_ID_INVITE_LIST = 10,
        CLAN_MENU_ID_LEAVE = 11,
        CLAN_MENU_ID_NUM = 12,
        CLAN_MENU_ID_INVALID = -1,
    };
    enum
    {
        MODE_SKILL_1 = 0,
        MODE_SKILL_2 = 1,
        MODE_CRAFT = 2,
        MODE_CLAN_NOT_JOIN = 3,
        MODE_CLAN_JOIN = 4,
        MODE_CLAN_LEADER = 5,
        MODE_CLAN_BASE = 6,
        MODE_PARTY = 7,
        MODE_AREA_MASTER = 8,
        MODE_RIM_STONE = 9,
        MODE_BAZAAR_1 = 10,
        MODE_BAZAAR_2 = 11,
        MODE_ENTRY_BOARD_START = 12,
        MODE_ENTRY_LEADER = 12,
        MODE_ENTRY_MEMBER = 13,
        MODE_ENTRY_LEADER_CLAN = 14,
        MODE_ENTRY_SOLO = 15,
        MODE_DEPARTURE_LEADER = 16,
        MODE_DEPARTURE_MEMBER = 17,
        MODE_ENTRY_BOARD_END = 17,
        MODE_BAGGAGE = 18,
        MODE_GACHA = 19,
        MODE_NUM = 20,
    };
    enum
    {
        SELECT_NONE = 0,
        SELECT_DECIDE = 1,
        SELECT_CANCEL = 2,
        SELECT_CHKOUT = 3,
        SELECT_TOPBTN = 4,
    };
    enum PTS_GUIDE_BIT
    {
        PTS_MEMBER = 1,
        PTS_NEWSP = 2,
        PTS_BIT_MAX = 2,
    };
    enum NUMBER_ICON_INDEX
    {
        NUMBER_ICON_INDEX_DEFAULT = 0,
        NUMBER_ICON_INDEX_DIRECT_INVITED = 1,
        NUMBER_ICON_NUM_MAX = 2,
    };
    enum
    {
        NORMAL_BUTTON_00 = 0,
        NORMAL_BUTTON_01 = 1,
        NORMAL_BUTTON_02 = 2,
        NORMAL_BUTTON_03 = 3,
        NORMAL_BUTTON_04 = 4,
        NORMAL_BUTTON_NUM = 5,
    };
    enum
    {
        BIG_BUTTON_00 = 0,
        BIG_BUTTON_NUM = 1,
    };
    enum
    {
        SMALL_BUTTON_00 = 0,
        SMALL_BUTTON_01 = 1,
        SMALL_BUTTON_02 = 2,
        SMALL_BUTTON_NUM = 3,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CHKOUT = 68,
        INPUTEVENT_TOPBTN = 69,
        INPUTEVENT_ADJUST_CURSOR = 70,
        INPUTEVENT_ADJUST_SELECTOR = 71,
        INPUTEVENT_CHANGE_WINDOW = 72,
    };
    enum
    {
        SKILL_1_TARGET = 0,
        SKILL_1_JOB = 1,
        SKILL_1_SKILL = 2,
        SKILL_1_ABILITY = 3,
        SKILL_1_NUM = 4,
    };
    enum
    {
        DEPARTURE_LEADER_DEPARTURE = 0,
        DEPARTURE_LEADER_REENTRY = 1,
        DEPARTURE_LEADER_NUM = 2,
    };
    enum
    {
        DEPARTURE_MEMBER_DEPARTURE = 0,
        DEPARTURE_MEMBER_NUM = 1,
    };
    enum
    {
        BUTTON_00 = 0,
        BUTTON_01 = 1,
        BUTTON_02 = 2,
        BUTTON_03 = 3,
        BUTTON_04 = 4,
        BUTTON_05 = 5,
        BUTTON_NUM = 6,
    };
    enum
    {
        SKILL_2_TARGET = 0,
        SKILL_2_SKILL = 1,
        SKILL_2_ABILITY = 2,
        SKILL_2_NUM = 3,
    };
    enum
    {
        CRAFT_MAKE = 0,
        CRAFT_UPGRADE = 1,
        CRAFT_SLOT = 2,
        CRAFT_COLOR = 3,
        CRAFT_PROGRESS = 4,
        CRAFT_GROW = 5,
        CRAFT_NUM = 6,
    };
    enum
    {
        CLAN_BASE_SHOP_FUNCTION = 0,
        CLAN_BASE_SHOP_BUFF = 1,
        CLAN_BASE_CHANGE_MANAGER = 2,
        CLAN_BASE_PAWN_EXPEDITION_STATE = 3,
        CLAN_BASE_NUM = 4,
    };
    enum
    {
        PARTY_PARTY_MAKE = 0,
        PARTY_SEARCH_PLAYER = 1,
        PARTY_ADD_PAWN = 2,
        PARTY_QUICK_PARTY = 3,
        PARTY_NUM = 4,
    };
    enum
    {
        AREA_MASTER_QUEST = 0,
        AREA_MASTER_SPOT = 1,
        AREA_MASTER_HISTORY = 2,
        AREA_MASTER_SUPPLIES = 3,
        AREA_MASTER_NUM = 4,
    };
    enum
    {
        RIM_STONE_SEARCH = 0,
        RIM_STONE_MAIN = 1,
        RIM_STONE_SUPPORT = 2,
        RIM_STONE_LOST = 3,
        RIM_STONE_NUM = 4,
    };
    enum
    {
        BAZAAR_1_BUY = 0,
        BAZAAR_1_EXHIBIT = 1,
        BAZAAR_1_INFO = 2,
        BAZAAR_1_NUM = 3,
    };
    enum
    {
        BAZAAR_2_STORAGE = 0,
        BAZAAR_2_BAG = 1,
        BAZAAR_2_NUM = 2,
    };
    enum
    {
        ENTRY_LEADER_READY = 0,
        ENTRY_LEADER_EXTEND = 1,
        ENTRY_LEADER_PASS = 2,
        ENTRY_LEADER_COMMENT = 3,
        ENTRY_LEADER_PARTY = 4,
        ENTRY_LEADER_STOP = 5,
        ENTRY_LEADER_NUM = 6,
    };
    enum
    {
        ENTRY_SOLO_READY = 0,
        ENTRY_SOLO_STOP = 1,
        ENTRY_SOLO_NUM = 2,
    };
    enum
    {
        ENTRY_MEMBER_READY = 0,
        ENTRY_MEMBER_PARTY = 1,
        ENTRY_MEMBER_STOP = 2,
        ENTRY_MEMBER_NUM = 3,
    };
    enum
    {
        BAGGAGE_FREE = 0,
        BAGGAGE_NUM = 1,
    };
    enum
    {
        GACHA_NORMAL = 0,
        GACHA_BOX = 1,
        GACHA_GP = 2,
        GACHA_ITEM = 3,
        GACHA_NUM = 4,
    };
public:
    class MyDTI;
    struct stStatus;
    struct stButton;
    struct stEnable;
    struct stNumberIcon;
    class ClanMenuIds;
public:
    using NumberIconIndexs = nDDOUtility::cArray<int, 2>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stStatus
    {
    public:
        stStatus();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsgJobName;  // offset: 0x10
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x18
        cGUIObjMessage* mpObjMsgLvValue;  // offset: 0x20
        cGUIObjMessage* mpObjMsgJp;  // offset: 0x28
        cGUIObjMessage* mpObjMsgJpValue;  // offset: 0x30
        cGUIObjMessage* mpObjMsgClan00;  // offset: 0x38
        cGUIObjMessage* mpObjMsgClan02;  // offset: 0x40
        cGUIObjMessage* mpObjMsgClan03;  // offset: 0x48
        cGUIObjMessage* mpObjMsgPcNum;  // offset: 0x50
        cGUIObjPolygon* mpOBJ_msg_status_base02;  // offset: 0x58
        cGUIObjMessage* mpOBJ_msg_status_m_clantxt05;  // offset: 0x60
        cGUIObjMessage* mpOBJ_msg_status_m_clanlvvalue;  // offset: 0x68
        cGUIObjMessage* mpOBJ_msg_status_m_clanpoint;  // offset: 0x70
        uGUIBase::cReferenceUIIconJob mJobIcon;  // offset: 0x78
    };
public:
    struct stButton
    {
    public:
        stButton();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
        cGUIObjNull* mpObjNullPointer;  // offset: 0x10
        cGUIObjPolygon* mpObjMouseOver;  // offset: 0x18
    };
public:
    struct stEnable
    {
    public:
        stEnable();
    public:
        bool mIsEnable;  // offset: 0x0
        MT_CTSTR mpMsg;  // offset: 0x8
        MtString mAnalize0;  // offset: 0x10
        MtString mAnalize1;  // offset: 0x18
    };
public:
    struct stNumberIcon
    {
    public:
        stNumberIcon();
        void set(bool isVisible, u32 value);
        void update();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
        u32 mValue;  // offset: 0x10
        bool mIsVisible;  // offset: 0x14
    };
public:
    class ClanMenuIds : public nDDOUtility::cArray<uGUIPopTopSel::CLAN_MENU_ID, 12>
    {
    public:
        ClanMenuIds();
        s32 getIdNum() const;
        void clear();
        s32 add(uGUIPopTopSel::CLAN_MENU_ID clanMenuId);
        s32 getIndex(uGUIPopTopSel::CLAN_MENU_ID clanMenuId) const;
        bool operator!=(const uGUIPopTopSel::ClanMenuIds& other) const;
    private:
        s32 mIdNum;  // offset: 0x30
    public:
        static const s32 INVALID_INDEX = -1;
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    static u32 GetClanMode();
    uGUIPopTopSel(bool exitFuncOn, u32 initFlags);
    virtual ~uGUIPopTopSel();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    void setMode(u32 mode);
    u32 getMode();
    void begin();
    void hide();
    void restart();
    void stay();
    bool isInit() const;
    bool isBegin() const;
    void setEnable(u32 index, bool isEnable);
    void setEnableBtnCtrl(u32 index, bool isEnable);
    bool isEnable(u32 index);
    void setEnableMsg(u32 index, MT_CTSTR pMsg, u32 color_type, MT_CTSTR pAnalyzerMsg0, MT_CTSTR pAnalyzerMsg1);
    bool isDecide();
    bool isCancel();
    bool isChkout();
    bool isTopbtn();
    u32 getSelectResult();
    void clearResult();
    void setDefaultPos(u32);
    u32 getSelectPos() const;
    CLAN_MENU_ID getSelectClanMenuId() const;
    void setCompleteIcon(bool isVisible, u32 value);
    void setNumberIcon(u32 index, bool isVisible, u32 value);
    void setNumberIconY(u32 index, u32 buttonIndex);
    void updateNumberIcon();
    void setExamIcon(bool isVisible);
    void setBazaarIcon(u32 index, u8 type);
    void clearSelector();
    void setSelectorMessage(u32 idx, MT_CTSTR msg);
    u32 getSelectorPos();
    s32 getPawnId();
    void setCmnDenominatorNum(u32 num);
    void setCmnNumeratorNum(u32 num);
    void playEntryFlashAnm();
    void setExecuteCtrl(bool flag);
    void setOpenMenuEntry(bool flg);
    void setFromNewspPaper(bool flg);
    void setFromGameMenu(bool flg);
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void updateInit();  // vtable slot 93
    void updateMove();
    void updateWait();
    void updateExit();
    void initStatus(const cContextInstHm* pContext);
    void initialize();
    void setupSelector();
    void setupStatus(u32 index);
    void setFocus(u32 index, bool isFocus);
    void setPointerPos();
    void btnValidCheck();
    bool isExitEntryBoard();
    void setGuidebtn();
    void requestAnnounce(u32 select);
    void applyClanParam();
    void eventDecide();
    void eventNotSelect();
    void eventCancel();
    void eventChkout();
    void eventTopbtn();
    void eventAdjustCursor();
    void eventAdjustSelector();
    void eventChangeWindow();
    void adjustSelector();
    void adjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlChkout(cControl::Message* msg);
    u32 evCtrlTopbtn(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustSelector(cControl::Message* msg);
    u32 evCtrlClick(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    MT_CTSTR getTitleMsg(u32 index);
    void clearMouseTouchList();
    void addMouseTouchList(u32 listNum);
    virtual s32 getSMenuCursorY();  // vtable slot 72
    s32 getClanMenuIds(ClanMenuIds& clanMenuIds, NumberIconIndexs* numberIconIndexs);
private:
    rGUI* mpGUIRes;  // offset: 0x988
    rGUIMessage* mpGMDRes;  // offset: 0x990
    cGUIInstNull* mpInstNull;  // offset: 0x998
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x9a0
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x9f8
    s32 mPawnId;  // offset: 0xa90
    u32 mMode;  // offset: 0xa94
    u32 mSelectResult;  // offset: 0xa98
    u32 mDefaultPos;  // offset: 0xa9c
    cGUIObjMessage* mpObjMsgTitle;  // offset: 0xaa0
    cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0xaa8
    cGUIObjMessage* mpOBJ_msg_txt00_m_txt;  // offset: 0xab0
    cGUIObjMessage* mpOBJ_msg_txt00_m_num;  // offset: 0xab8
    cGUIInstAnimation* mpInstAnimNumberIcon;  // offset: 0xac0
    cGUIInstAnimation* mpInstAnimExamIcon;  // offset: 0xac8
    cGUIObjTexture* mpObjTexBazaarIcon00;  // offset: 0xad0
    cGUIObjTexture* mpObjTexBazaarIcon01;  // offset: 0xad8
    cGUIInstAnimation* mpInstAnimBtn02_flash;  // offset: 0xae0
    stStatus mStatus;  // offset: 0xae8
    stButton mNormalButton[5];  // offset: 0xbb8
    stButton mSmallButton[3];  // offset: 0xc58
    stButton mBigButton[1];  // offset: 0xcb8
    stButton mButton[6];  // offset: 0xcd8
    stEnable mEnable[6];  // offset: 0xd98
    nDDOUtility::cArray<stNumberIcon, 2> mNumberIcons;  // offset: 0xe58
    uGUIBase::cReferenceUISelector mSelector;  // offset: 0xe88
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0x11e8
    uGUIBase::cHorizontalList* mpSelectorCtrl;  // offset: 0x11f0
    uGUIBase::cHorizontalList* mpSelectorLRCtrl;  // offset: 0x11f8
    bool mIsVisibleExamIcon;  // offset: 0x1200
    bool mIsBegin;  // offset: 0x1201
    bool mIsInitialized;  // offset: 0x1202
    bool mIsInitOnce;  // offset: 0x1203
    bool mIsInitFirst;  // offset: 0x1204
    bool mIsCallOpenSe;  // offset: 0x1205
    bool mIsExecuteCtrl;  // offset: 0x1206
    bool mIsOpenMenuEntry;  // offset: 0x1207
    bool mIsFromNewsPaper;  // offset: 0x1208
    bool mIsFromGameMenu;  // offset: 0x1209
    u32 mCmnDenominatorNum;  // offset: 0x120c
    u32 mCmnNumeratorNum;  // offset: 0x1210
    u32 mBazaarIcon00;  // offset: 0x1214
    u32 mBazaarIcon01;  // offset: 0x1218
    s32 mStayCursorPos;  // offset: 0x121c
    s32 mButtonH;  // offset: 0x1220
    uGUIBase::cReferenceUIClanEmblem mClanEmblem;  // offset: 0x1228
    ClanMenuIds mClanMenuIds;  // offset: 0x1330
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[2];  // offset: 0x1368
public:
    static MyDTI DTI;
};
