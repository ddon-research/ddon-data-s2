#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cCharacterData.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "cGUIPageList.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class CDataCharacterListElement;
class CDataClientPartyListInfo;
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class cContextInstHm;
class cControl;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjChildAnimationRoot;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObject;
class cPartyMemberInfo;
class cPawnListParam;
namespace nCharacterData { struct stCharacterName; }
class rGUI;

// Declarations
class uGUIPartyList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIPartyList : public uGUIBase
{
public:
    enum MODE
    {
        MODE_PARTY_MEMBER_INIT = 0,
        MODE_PARTY_MEMBER_LIST = 1,
        MODE_PARTY_MEMBER_AND_REQUEST = 2,
        MODE_PARTY_REQUEST_SHORTCUT = 3,
        MODE_MAIN_PAWN_WAIT = 4,
        MODE_MAIN_PAWN_NONE = 5,
        MODE_MAIN_PAWN_LIST = 6,
        MODE_SUPPORT_PAWN_WAIT = 7,
        MODE_SUPPORT_PAWN_NONE = 8,
        MODE_SUPPORT_PAWN_LIST = 9,
        MODE_PARTY_SEARCH_WAIT = 10,
        MODE_PARTY_SEARCH_NONE = 11,
        MODE_PARTY_SEARCH_LIST = 12,
        MODE_PARTY_SEARCH_SIMPLE = 13,
        MODE_PLAYER_SEARCH_WAIT = 14,
        MODE_PLAYER_SEARCH_NONE = 15,
        MODE_PLAYER_SEARCH_LIST = 16,
        MODE_NUM = 17,
    };
    enum TAB_ID
    {
        TAB_PARTY_MEMBER = 0,
        TAB_MAIN_PAWN = 1,
        TAB_SUPPORT_PAWN = 2,
        TAB_PARTY_SEARCH = 3,
        TAB_PLAYER_SEARCH = 4,
        TAB_NUM = 5,
    };
    enum DISP_MODE
    {
        DISP_MODE_DEFAULT = 0,
        DISP_MODE_COMMENT = 1,
        DISP_MODE_NUM = 2,
    };
    enum CONTROL_ID
    {
        CONTROL_PARTY_MEMBER = 0,
        CONTROL_PARTY_MEMBER_LIST = 1,
        CONTROL_MAIN_PAWN_LIST = 2,
        CONTROL_SUPPORT_PAWN_LIST = 3,
        CONTROL_PARTY_SEARCH = 4,
        CONTROL_PARTY_SEARCH_LIST = 5,
        CONTROL_PARTY_SEARCH_PAGE = 6,
        CONTROL_PARTY_SEARCH_BUTTON = 7,
        CONTROL_PLAYER_SEARCH = 8,
        CONTROL_PLAYER_SEARCH_LIST = 9,
        CONTROL_PLAYER_SEARCH_PAGE = 10,
    };
    enum CONTROL_LAYOUT
    {
        CONTROL_LAYOUT_LIST = 0,
        CONTROL_LAYOUT_BUTTON = 1,
        CONTROL_LAYOUT_NUM = 2,
    };
    enum PAGER_ID
    {
        PAGER_PARTY_SEARCH = 0,
        PAGER_PLAYER_SEARCH = 1,
        PAGER_NUM = 2,
    };
    enum BUTTON_ID
    {
        BUTTON_LEAVE = 0,
        BUTTON_SEARCH = 0,
        BUTTON_REQUEST = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        INPUTEVENT_TAB_MOVE = 66,
        INPUTEVENT_MOVE = 67,
        INPUTEVENT_DISP_CHANGE = 68,
        INPUTEVENT_MOUSE_LCLICK = 69,
    };
    enum TITLE_ID
    {
        TITLE_NAME = 0,
        TITLE_JOB = 1,
        TITLE_LOBBY = 2,
        TITLE_UNION = 3,
        TITLE_LOCATION = 4,
        TITLE_NUM = 5,
    };
public:
    class MyDTI;
    class cTitle;
    struct DATA;
    class cPlayerInfo;
    class cGUIPageListPartyMember;
    class cGUIPageListCommon;
    class cGUIPageListMainPawn;
    class cGUIPageListSupportPawn;
    class cGUIPageListPartySearch;
    class cGUIPageListPlayerSearch;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTitle : public uGUIBase::cSupportBase
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
        cTitle();
        void setup(uGUIBase* pBase, u32 instID, u32 objID, MT_CTSTR str);
        void setName(MT_CTSTR str);
    public:
        cGUIObjChildAnimationRoot* mpObjInst;  // offset: 0x18
        cGUIObjMessage* mpMsg;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    struct DATA
    {
    public:
        cGUIInstAnimation* mpINST_window;  // offset: 0x0
        cGUIInstNull* mpINST_Null;  // offset: 0x8
        cGUIInstAnimation* mpINST_msg_list;  // offset: 0x10
        cGUIInstAnimation* mpINST_msg_list_matchinng;  // offset: 0x18
        cGUIInstAnimation* mpINST_mask;  // offset: 0x20
        cGUIInstNull* mpINST_Null_scroll;  // offset: 0x28
        cGUIInstAnimation* mpINST_cursor;  // offset: 0x30
        cGUIInstAnimation* mpINST_scr_bar;  // offset: 0x38
        cGUIInstAnimation* mpINST_msg_num;  // offset: 0x40
        cGUIInstAnimation* mpINST_msg_serch;  // offset: 0x48
        cGUIInstAnimation* mpINST_msg_select;  // offset: 0x50
        cGUIInstNull* mpINST_Null_all;  // offset: 0x58
        cGUIInstNull* mpINST_Null_tab;  // offset: 0x60
        cGUIInstNull* mpINST_Null_list;  // offset: 0x68
        cGUIInstAnimation* mpINST_fix_job;  // offset: 0x70
        cGUIObjMessage* mpOBJ_msg_list_m_name;  // offset: 0x78
        cGUIObjMessage* mpOBJ_msg_list_m_lv;  // offset: 0x80
        cGUIObjMessage* mpOBJ_msg_list_m_loby;  // offset: 0x88
        cGUIObjMessage* mpOBJ_msg_list_m_location;  // offset: 0x90
        cGUIObjMessage* mpOBJ_msg_list_m_union;  // offset: 0x98
        cGUIObjMessage* mpOBJ_msg_list_m_object;  // offset: 0xa0
        cGUIObjMessage* mpOBJ_msg_list_m_pawn_name;  // offset: 0xa8
        cGUIObjMessage* mpOBJ_msg_list_m_craft;  // offset: 0xb0
        cGUIObjMessage* mpOBJ_msg_list_m_point;  // offset: 0xb8
        cGUIObjMessage* mpOBJ_msg_list_m_limit_battle;  // offset: 0xc0
        cGUIObjMessage* mpOBJ_msg_list_m_limit_craft;  // offset: 0xc8
        cGUIObjMessage* mpOBJ_msg_num_m_num;  // offset: 0xd0
        cGUIObjMessage* mpOBJ_msg_num_m_sort;  // offset: 0xd8
        cGUIObjMessage* mpOBJ_msg_serch_m_serch;  // offset: 0xe0
        cGUIObjMessage* mpOBJ_msg_info_m_info;  // offset: 0xe8
        cGUIObjMessage* mpOBJ_msg_matching_m_time;  // offset: 0xf0
        cGUIObjChildAnimationRoot* mpOBJ_msg_list_fix_icon00;  // offset: 0xf8
    };
public:
    class cPlayerInfo
    {
    public:
        using cStrB = uGUIBase::cExGUIMessageObj<64>;
        using cStrS = uGUIBase::cExGUIMessageObj<16>;
        using cStrComment = uGUIBase::cExGUIMessageObj<1024>;
    public:
        cPlayerInfo();
        void setAttr(u32 attr);
        void setStringColorAll(const MtColor& color);
        void setOnlineStatus(const cContextInstHm* pContext);
        void setOnlineStatus(u32 onlineStatus);
        void setPawnIcon();
        void setJob(u32 jobId);
        void setPawn(const cPawnListParam& pawnListParam, uGUIBase* pGUI);
        void setPlayer(cPartyMemberInfo* partyMemberInfo, s32 dispMode, MT_CTSTR joiningText);
        void setPlayer(const cContextInstHm* context, s32 dispMode);
        void setPlayer(uGUIPartyList* owner, const CDataClientPartyListInfo& partyListInfo, s32 dispMode, MT_CTSTR invitingText);
        void setPlayer(uGUIPartyList* owner, const CDataCharacterListElement& characterListElement, s32 dispMode, MT_CTSTR invitingText);
        void setPlayer(uGUIPartyList* owner, u32 characterId, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanName, u32 jobId, u32 jobLv, MT_CTSTR comment, u32 onlineStatus, u32 serverId, u32 lobbyId, u32 partyMemberNum, s32 dispMode, MT_CTSTR invitingText);
        void setEmpty();
    private:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x0
        u32 mAttr;  // offset: 0x28
        cStrB mMsgName;  // offset: 0x30
        cStrS mMsgLv;  // offset: 0x98
        cStrS mMsgLobby;  // offset: 0xd0
        cStrS mMsgUnion;  // offset: 0x108
        cStrS mMsgLocation;  // offset: 0x140
        cStrS mMsgObject;  // offset: 0x178
        cStrS mMsgPawn;  // offset: 0x1b0
        cStrS mMsgCraft;  // offset: 0x1e8
        cStrS mMsgPoint;  // offset: 0x220
        cStrS mMsgLimitBattle;  // offset: 0x258
        cStrS mMsgLimitCraft;  // offset: 0x290
        cStrComment mMsgComment;  // offset: 0x2c8
        cStrS mMsgParty;  // offset: 0x6f0
        cGUIInstAnimation* mpINST_msg_list;  // offset: 0x728
        cGUIInstAnimation* mpINST_fix_job;  // offset: 0x730
        cGUIInstAnimation* mpINST_favorite;  // offset: 0x738
        cGUIInstAnimation* mpINST_comment;  // offset: 0x740
        uGUIBase::cReferenceUIIconOnlineStatus mOnlineStatus;  // offset: 0x748
        cGUIObjTexture* mpOBJ_PartyIcon;  // offset: 0x798
        cGUIObjChildAnimationRoot* mpOBJ_msg_list_fix_icon00;  // offset: 0x7a0
        cGUIObjPolygon* mpOBJ_msg_list_mouseover;  // offset: 0x7a8
    };
public:
    class cGUIPageListCommon : public cGUIPageList
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
        cGUIPageListCommon();
        virtual ~cGUIPageListCommon();
        virtual s32 getPageItemNum() const;  // vtable slot 8
        virtual void getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const;  // vtable slot 10
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
        virtual void callbackHideItem(s32 dispItemIndex);  // vtable slot 21
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListMainPawn : public uGUIPartyList::cGUIPageListCommon
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
        cGUIPageListMainPawn();
        virtual ~cGUIPageListMainPawn() {}
        virtual s32 getItemNum() const;  // vtable slot 7
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListSupportPawn : public uGUIPartyList::cGUIPageListCommon
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
        cGUIPageListSupportPawn();
        virtual ~cGUIPageListSupportPawn() {}
        virtual s32 getItemNum() const;  // vtable slot 7
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListPartySearch : public uGUIPartyList::cGUIPageListCommon
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
        cGUIPageListPartySearch();
        virtual ~cGUIPageListPartySearch() {}
        virtual s32 getItemNum() const;  // vtable slot 7
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListPlayerSearch : public uGUIPartyList::cGUIPageListCommon
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
        cGUIPageListPlayerSearch();
        virtual ~cGUIPageListPlayerSearch() {}
        virtual s32 getItemNum() const;  // vtable slot 7
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListPartyMember : public uGUIPartyList::cGUIPageListCommon
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
        cGUIPageListPartyMember();
        virtual ~cGUIPageListPartyMember() {}
        virtual s32 getItemNum() const;  // vtable slot 7
        virtual f32 getCursorPosY(s32 dispItemIndex) const;  // vtable slot 9
        virtual void getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const;  // vtable slot 10
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    private:
        bool isInviteCursorPos(s32 dispItemIndex) const;
    public:
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
    s32 getPartySearchMenuNum() const;
    s32 getPartySearchMenuContent(s32 index) const;
    static s32 GetPartySearchPageMax();
    static s32 GetPartyListLength();
    static s32 GetPartyListSortCount();
    static s32 GetPlayerListLength();
    static s32 GetPlayerListSortCount();
    static s32 GetPartyManagerRno(s32 tabId);
    static bool IsInitPartyManagerTab(s32 tabId);
    static bool IsEnableSimplePartyReq(s32 tabId);
    static u32 GetPartySearchRno();
    static u32 GetPlayerSearchRno();
    static bool Show(uGUIBase* base);
    static bool IsShortCutWait(uGUIBase* base);
    static void SetSearchSettingParty(uGUIBase* base, cCharacterData::stSearchFilterSetting& settingParty);
    static void ResetSearchSettingParty(uGUIBase* base);
    static void SetSearchSettingPlayer(uGUIBase* base, cCharacterData::stSearchFilterSetting& settingPlayer);
    static void ResetSearchSettingPlayer(uGUIBase* base);
    uGUIPartyList();
    virtual ~uGUIPartyList();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void clearDisp();
    cPlayerInfo* getInfo(u32);
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    virtual s32 getSMenuTab();  // vtable slot 74
private:
    void updateInit();
    void updateWait();
    void updateExit();
    bool setupListVisible(s32 num);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlTabMove(cControl::Message* msg);
    void evTabMove();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlDispChange(cControl::Message* msg);
    void evDispChange();
    u32 evCtrlButtonMove(cControl::Message* msg);
    u32 evCtrlButtonClick(cControl::Message* msg);
    void setupPlayerInfo(cPlayerInfo& playerInfo, cGUIInstNull* instNull, u32 ID_INST_msg_list, u32 ID_INST_fix_job, u32 ID_INST_fix_icon_online, u32 ID_INST_comment, u32 ID_INST_favorite);
    bool setPointerPosFromFocusReferenceUI();
    void setTitleText(MODE mode, u32 dispMode);
    bool show();
    bool isShortCutWait();
    MODE getModeFromTabId(s32 tabId) const;
    void setMode(MODE mode);
    bool updateMode(s32 tabId);
    u32 updateControlItemNum(bool isUpdateMode);
    void initMode();
    void updatePartySearchConditionMessage(bool isClear);
    void updatePlayerSearchConditionMessage(bool isClear);
private:
    nDDOUtility::cArray<cTitle, 5> mTitles;  // offset: 0x8c8
    DATA mData;  // offset: 0x990
    nDDOUtility::cArray<cPlayerInfo, 14> mPlayerInfos;  // offset: 0xa90
    cPlayerInfo mMatchingPlayerInfo;  // offset: 0x7630
    s32 mVisibleNum;  // offset: 0x7de0
    rGUI* mpGUIRes;  // offset: 0x7de8
    cGUIInstNull* mpINST_Null;  // offset: 0x7df0
    cGUIInstAnimation* mpINST_msg_numpager;  // offset: 0x7df8
    s32 mTabNo;  // offset: 0x7e00
    s32 mDispMode;  // offset: 0x7e04
    bool mIsDispUpdate;  // offset: 0x7e08
    bool mIsSetup;  // offset: 0x7e09
    u8 mShortCutWaitFrame;  // offset: 0x7e0a
    nDDOUtility::cArray<MtObject*, 5> mpSMenuObjs;  // offset: 0x7e10
    uGUIBase::cReferenceUIScrollBar mScrbar;  // offset: 0x7e38
    uGUIBase::cReferenceUITab mTab;  // offset: 0x7ee0
    uGUIBase::cAdjustableWindow mWindow;  // offset: 0x7f90
    nDDOUtility::cArray<uGUIBase::cReferenceUINumPager, 2> mNumPagers;  // offset: 0x8030
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mButtons;  // offset: 0x8180
    uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x84a0
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x8550
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x85e8
    s32 mPawnTabNo;  // offset: 0x8640
    s32 mCurrentPos;  // offset: 0x8644
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x8648
    cControl* mpButtonCtrl;  // offset: 0x8650
    cControl* mpButtonYBtnCtrl;  // offset: 0x8658
    cGUIControlMgr mControls;  // offset: 0x8660
    MODE mMode;  // offset: 0x8b10
    MODE mModeOld;  // offset: 0x8b14
    MT_CHAR mCommentBuffer[1024];  // offset: 0x8b18
    u32 mSettingPartyPlayPurpose1;  // offset: 0x8f18
    u32 mSettingPartyPlayStyle;  // offset: 0x8f1c
    nCharacterData::stCharacterName mSettingPlayerName;  // offset: 0x8f20
    cGUIPageListPartyMember mPageListPartyMember;  // offset: 0x8f38
    cGUIPageListMainPawn mPageListMainPawn;  // offset: 0x8f80
    cGUIPageListSupportPawn mPageListSupportPawn;  // offset: 0x8fc8
    cGUIPageListPartySearch mPageListPartySearch;  // offset: 0x9010
    cGUIPageListPlayerSearch mPageListPlayerSearch;  // offset: 0x9058
public:
    static MyDTI DTI;
    static const u32 PLAYER_INFO_NUM = 14;
    static const u32 COMMENT_BUFFER_SIZE = 1024;
};

inline void* uGUIPartyList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIPartyList::cTitle::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIPartyList::cTitle::cTitle() {
    this->mpMsg = nullptr;
    this->mpObjInst = nullptr;
}

inline void* uGUIPartyList::cGUIPageListPartyMember::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIPartyList::cGUIPageListPartyMember::cGUIPageListPartyMember() {
}

inline void* uGUIPartyList::cGUIPageListCommon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIPartyList::cGUIPageListCommon::cGUIPageListCommon() {
}

inline void* uGUIPartyList::cGUIPageListMainPawn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIPartyList::cGUIPageListMainPawn::cGUIPageListMainPawn() {
}

inline void* uGUIPartyList::cGUIPageListSupportPawn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIPartyList::cGUIPageListSupportPawn::cGUIPageListSupportPawn() {
}

inline void* uGUIPartyList::cGUIPageListPartySearch::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIPartyList::cGUIPageListPartySearch::cGUIPageListPartySearch() {
}

inline void* uGUIPartyList::cGUIPageListPlayerSearch::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIPartyList::cGUIPageListPlayerSearch::cGUIPageListPlayerSearch() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "cMenuBase.h"
#include "cMenuSupport.h"
#include "sMenu.h"

inline void uGUIPartyList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPartyList::DTI)->memFree(p_addr);
}

inline s32 uGUIPartyList::GetPartyListSortCount() {
    if (::sMenu::getInstance()->::sMenu::checkMoveMenu(static_cast<cMenuBase*>(&::sMenu::getInstance()->mPartyList), false)) {
        if (::sMenu::getInstance()->mPartyList.::cMenuBase::mpList != nullptr) {
            return static_cast<s32>(::sMenu::getInstance()->mPartyList.::cMenuBase::mpList->::cMenuSupportList::getSortListCount());
        }
    }
    return 0;
}

inline s32 uGUIPartyList::GetPlayerListSortCount() {
    if (::sMenu::getInstance()->::sMenu::checkMoveMenu(static_cast<cMenuBase*>(&::sMenu::getInstance()->mCharacterList), false)) {
        if (::sMenu::getInstance()->mCharacterList.::cMenuBase::mpList != nullptr) {
            return static_cast<s32>(::sMenu::getInstance()->mCharacterList.::cMenuBase::mpList->::cMenuSupportList::getSortListCount());
        }
    }
    return 0;
}

inline void* uGUIPartyList::cTitle::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cTitle::DTI)->memAlloc(sz, align, ::uGUIPartyList::cTitle::DTI.::MtDTI::getID());
}

inline void uGUIPartyList::cTitle::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cTitle::DTI)->memFree(p_addr);
}

inline void* uGUIPartyList::cGUIPageListPartyMember::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListPartyMember::DTI)->memAlloc(sz, align, ::uGUIPartyList::cGUIPageListPartyMember::DTI.::MtDTI::getID());
}

inline void uGUIPartyList::cGUIPageListPartyMember::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListPartyMember::DTI)->memFree(p_addr);
}

inline void* uGUIPartyList::cGUIPageListMainPawn::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListMainPawn::DTI)->memAlloc(sz, align, ::uGUIPartyList::cGUIPageListMainPawn::DTI.::MtDTI::getID());
}

inline void uGUIPartyList::cGUIPageListMainPawn::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListMainPawn::DTI)->memFree(p_addr);
}

inline void* uGUIPartyList::cGUIPageListSupportPawn::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListSupportPawn::DTI)->memAlloc(sz, align, ::uGUIPartyList::cGUIPageListSupportPawn::DTI.::MtDTI::getID());
}

inline void uGUIPartyList::cGUIPageListSupportPawn::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListSupportPawn::DTI)->memFree(p_addr);
}

inline void* uGUIPartyList::cGUIPageListPartySearch::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListPartySearch::DTI)->memAlloc(sz, align, ::uGUIPartyList::cGUIPageListPartySearch::DTI.::MtDTI::getID());
}

inline void uGUIPartyList::cGUIPageListPartySearch::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListPartySearch::DTI)->memFree(p_addr);
}

inline void* uGUIPartyList::cGUIPageListPlayerSearch::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListPlayerSearch::DTI)->memAlloc(sz, align, ::uGUIPartyList::cGUIPageListPlayerSearch::DTI.::MtDTI::getID());
}

inline void uGUIPartyList::cGUIPageListPlayerSearch::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPartyList::cGUIPageListPlayerSearch::DTI)->memFree(p_addr);
}
