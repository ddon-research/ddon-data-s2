#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "cGUIPageList.h"
#include "cNetGameServer.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObject;
class cGUIPageList;
class cPawnListParam;
class rGUI;
class rSoundRequest;

// Declarations
class uGUIRimStone;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cPawnListVec = MtTypedArray<cPawnListParam>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIRimStone : public uGUIBase
{
public:
    enum MODE
    {
        MODE_INVALID = 0,
        MODE_SELECT_CATEGORY = 1,
        MODE_SEARCH_WAIT_LIST = 2,
        MODE_SEARCH_DISP_LIST_WITH_CONFIG = 3,
        MODE_SEARCH_NO_LIST_WITH_CONFIG = 4,
        MODE_SEARCH_DISP_LIST_NO_CONFIG = 5,
        MODE_SEARCH_NO_LIST_NO_CONFIG = 6,
        MODE_MAIN_WAIT_LIST = 7,
        MODE_MAIN_DISP_LIST = 8,
        MODE_MAIN_NO_LIST = 9,
        MODE_SUPPORT_WAIT_LIST = 10,
        MODE_SUPPORT_DISP_LIST = 11,
        MODE_SUPPORT_NO_LIST = 12,
        MODE_LOST_WAIT_LIST = 13,
        MODE_LOST_DISP_LIST = 14,
        MODE_LOST_NO_LIST = 15,
    };
    enum CATEGORY_FOCUS_TYPE
    {
        CATEGORY_FOCUS_TYPE_NORMAL = 0,
        CATEGORY_FOCUS_TYPE_SELECTED = 1,
        CATEGORY_FOCUS_TYPE_NUM = 2,
    };
    enum CONTROL_ID
    {
        CONTROL_TAB = 0,
        CONTROL_SELECT_CATEGORY = 1,
        CONTROL_SEARCH_PAWN = 2,
        CONTROL_SEARCH_PAWN_LIST = 3,
        CONTROL_SEARCH_PAWN_PAGE = 4,
        CONTROL_MAIN_PAWN_LIST = 5,
        CONTROL_SUPPORT_PAWN_LIST = 6,
        CONTROL_LOST_PAWN_LIST = 7,
        CONTROL_INVALID = 8,
    };
    enum TAB_ID
    {
        TAB_SEARCH = 0,
        TAB_MAIN = 1,
        TAB_SUPPORT = 2,
        TAB_LOST = 3,
        TAB_NUM = 4,
    };
    enum QH_GUIDE_BIT
    {
        RS_DECIDE = 1,
        RS_BIT_MAX = 1,
    };
    enum CATEGORY
    {
        CATEGORY_SEARCH = 0,
        CATEGORY_LEGEND = 1,
        CATEGORY_OFFICIAL = 2,
        CATEGORY_FRIEND = 3,
        CATEGORY_CLAN = 4,
        CATEGORY_FAVORITE = 5,
        CATEGORY_NUM = 6,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_TAB = 0,
        CONTROL_CATEGORY_SELECT_CATEGORY = 1,
        CONTROL_CATEGORY_SEARCH = 2,
        CONTROL_CATEGORY_MAIN = 3,
        CONTROL_CATEGORY_SUPPORT = 4,
        CONTROL_CATEGORY_LOST = 5,
    };
    enum CONTROL_LAYOUT
    {
        CONTROL_LAYOUT_LIST = 0,
        CONTROL_LAYOUT_BUTTON = 1,
        CONTROL_LAYOUT_NUM = 2,
    };
    enum INPUTEVENT_RIMSTONE
    {
        INPUTEVENT_TAB = 66,
        INPUTEVENT_DECIDE = 67,
        INPUTEVENT_CANCEL = 68,
        INPUTEVENT_MOVE_SEARCH_CAT = 69,
        INPUTEVENT_MOVE_SEARCH_LIST = 70,
        INPUTEVENT_MOVE_SEARCH_PAGE = 71,
        INPUTEVENT_MOVE_MAIN_LIST = 72,
        INPUTEVENT_MOVE_SUP_LIST = 73,
    };
public:
    class MyDTI;
    struct DATA;
    struct DispPawn;
    class cGUIPageListSearchCategory;
    class cGUIPageListSearchPawn;
    class cGUIPageListCommon;
    class cGUIPageListMainPawn;
    class cGUIPageListSupportPawn;
    class cGUIPageListLostPawn;
public:
    using PawnNameColors = nDDOUtility::cArray<MtColor, 2>;
    using DispPawns = nDDOUtility::cArray<uGUIRimStone::DispPawn, 10>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null_all;  // offset: 0x0
        cGUIInstNull* mpINST_Null_tab;  // offset: 0x8
        cGUIInstNull* mpINST_Null_pawn;  // offset: 0x10
        cGUIInstNull* mpINST_Null_listmove;  // offset: 0x18
        cGUIInstAnimation* mpINST_msg_btn00;  // offset: 0x20
        cGUIInstAnimation* mpINST_msg_lv;  // offset: 0x28
        cGUIInstAnimation* mpINST_msg_numpager;  // offset: 0x30
        cGUIInstAnimation* mpINST_window01;  // offset: 0x38
        cGUIInstAnimation* mpINST_msg_btn;  // offset: 0x40
        cGUIInstAnimation* mpINST_msg_title;  // offset: 0x48
        cGUIInstAnimation* mpINST_msg_select;  // offset: 0x50
        cGUIInstAnimation* mpINST_msg_list00;  // offset: 0x58
        cGUIInstAnimation* mpINST_mask;  // offset: 0x60
        cGUIInstNull* mpINST_Null_list00;  // offset: 0x68
        cGUIInstAnimation* mpINST_fix_job;  // offset: 0x70
        cGUIInstAnimation* mpINST_msg_num;  // offset: 0x78
        cGUIInstAnimation* mpINST_close_btn;  // offset: 0x80
        cGUIInstAnimation* mpINST_msg_tab;  // offset: 0x88
        cGUIInstAnimation* mpINST_msg_ranklist;  // offset: 0x90
        cGUIInstAnimation* mpINST_ctgry_base;  // offset: 0x98
        cGUIInstAnimation* mpINST_cursor00;  // offset: 0xa0
        cGUIInstAnimation* mpINST_window_frame;  // offset: 0xa8
        cGUIInstAnimation* mpINST_fix_craftlv;  // offset: 0xb0
        cGUIInstAnimation* mpINST_msg_notice;  // offset: 0xb8
        cGUIInstAnimation* mpINST_msg_count;  // offset: 0xc0
        nDDOUtility::cArray<cGUIInstAnimation*, 4> mpINST_cursor01s;  // offset: 0xc8
        cGUIObjTexture* mpOBJ_window_center_center;  // offset: 0xe8
        cGUIObjMessage* mpOBJ_msg_btn_m_btn;  // offset: 0xf0
        cGUIObjMessage* mpOBJ_msg_btn_m_guide;  // offset: 0xf8
        cGUIObjMessage* mpOBJ_msg_select_m_section04;  // offset: 0x100
        cGUIObjMessage* mpOBJ_msg_select_m_section06;  // offset: 0x108
        cGUIObjMessage* mpOBJ_msg_num_m_num;  // offset: 0x110
        cGUIObjMessage* mpOBJ_msg_lv_m_lv;  // offset: 0x118
        cGUIObjMessage* mpOBJ_msg_count_m_num;  // offset: 0x120
        cGUIObjMessage* mpOBJ_msg_count_m_sort;  // offset: 0x128
        cGUIObjMessage* mpOBJ_msg_info_m_info;  // offset: 0x130
        nDDOUtility::cArray<cGUIObjMessage*, 6> mpOBJ_msg_fix_ranklist_m_f_pawns;  // offset: 0x138
        nDDOUtility::cArray<cGUIObjPolygon*, 6> mpOBJ_msg_fix_ranklist_mouseovers;  // offset: 0x168
    };
public:
    struct DispPawn
    {
    public:
        DispPawn();
        ~DispPawn();
        void setup(s32 index, uGUIRimStone* guiRimStone, cGUIInstNull* pINST_Null, cGUIInstance* pINST_duplicated);
        void setParam(uGUIRimStone& guiRimStone, const cPawnListParam& pawnListParam, s32 tabId, s32 category);
        void setIconPosition(cGUIInstNull* pINST_fix_job, cGUIInstNull* pINST_fix_craftlv);
        void setNameColor();
    public:
        uGUIRimStone* mpOwner;  // offset: 0x0
        s32 mIndex;  // offset: 0x8
        uGUIBase::cDupliInstNull mInst;  // offset: 0x10
        cGUIInstAnimation* mpINST_msg_list00;  // offset: 0x38
        cGUIInstAnimation* mpINST_fix_job;  // offset: 0x40
        cGUIInstAnimation* mpINST_fix_craftlv;  // offset: 0x48
        cGUIInstAnimation* mpINST_favorite;  // offset: 0x50
        cGUIInstAnimation* mpINST_fix_icon_online;  // offset: 0x58
        cGUIInstAnimation* mpINST_comment;  // offset: 0x60
        cGUIInstAnimation* mpINST_msg_charges;  // offset: 0x68
        cGUIObjMessage* mpOBJ_msg_list_m_name;  // offset: 0x70
        cGUIObjMessage* mpOBJ_msg_list_m_job;  // offset: 0x78
        cGUIObjMessage* mpOBJ_msg_list_m_craft;  // offset: 0x80
        cGUIObjMessage* mpOBJ_msg_list_m_point;  // offset: 0x88
        cGUIObjMessage* mpOBJ_msg_list_m_cost;  // offset: 0x90
        cGUIObjMessage* mpOBJ_msg_list_m_r;  // offset: 0x98
        cGUIObjMessage* mpOBJ_msg_list_m_limit_battle;  // offset: 0xa0
        cGUIObjMessage* mpOBJ_msg_list_m_limit_craft;  // offset: 0xa8
        cGUIObjMessage* mpOBJ_msg_list_m_num;  // offset: 0xb0
        cGUIObjMessage* mpOBJ_msg_list_m_share;  // offset: 0xb8
        cGUIObjTexture* mpOBJ_msg_list_looks;  // offset: 0xc0
        cGUIObjTexture* mpOBJ_msg_list_battle;  // offset: 0xc8
        cGUIObjTexture* mpOBJ_msg_list_craft;  // offset: 0xd0
        cGUIObjTexture* mpOBJ_msg_list_list;  // offset: 0xd8
        cGUIObjNull* mpOBJ_msg_list_Null_legend;  // offset: 0xe0
        cGUIObjMessage* mpOBJ_msg_list_m_nocost;  // offset: 0xe8
        cGUIObjPolygon* mpOBJ_msg_list_mouseover;  // offset: 0xf0
        uGUIBase::cReferenceUIIconJob mIconJob;  // offset: 0xf8
        uGUIBase::cReferenceUIIconCraftLv mIconCraftLv;  // offset: 0x150
        uGUIBase::cReferenceUIIconOnlineStatus mIconOnlineStatus;  // offset: 0x1a8
        uGUIBase::cReferenceUIChargesInfo mChargesInfo;  // offset: 0x1f8
        MtColor mNameColor;  // offset: 0x350
    };
public:
    class cGUIPageListSearchCategory : public cGUIPageList
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
        cGUIPageListSearchCategory();
        virtual ~cGUIPageListSearchCategory() {}
        virtual s32 getItemNum() const;  // vtable slot 7
        virtual s32 getPageItemNum() const;  // vtable slot 8
        virtual f32 getCursorPosY(s32 dispItemIndex) const;  // vtable slot 9
        virtual void getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const;  // vtable slot 10
        virtual u32 evCtrlMouseSelect(cControl::Message* msg);  // vtable slot 14
        virtual u32 evCtrlMouseDecide(cControl::Message* msg);  // vtable slot 15
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
        virtual void callbackHideItem(s32 dispItemIndex);  // vtable slot 21
    public:
        static MyDTI DTI;
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
        virtual s32 getTabId() const;  // vtable slot 22
        virtual s32 getCategory() const;  // vtable slot 23
        virtual s32 getPageItemNum() const;  // vtable slot 8
        virtual void getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const;  // vtable slot 10
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
        virtual void callbackHideItem(s32 dispItemIndex);  // vtable slot 21
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListMainPawn : public uGUIRimStone::cGUIPageListCommon
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
        virtual s32 getTabId() const;  // vtable slot 22
        virtual s32 getItemNum() const;  // vtable slot 7
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListSupportPawn : public uGUIRimStone::cGUIPageListCommon
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
        virtual s32 getTabId() const;  // vtable slot 22
        virtual s32 getItemNum() const;  // vtable slot 7
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListLostPawn : public uGUIRimStone::cGUIPageListCommon
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
        cGUIPageListLostPawn();
        virtual ~cGUIPageListLostPawn() {}
        virtual s32 getTabId() const;  // vtable slot 22
        virtual s32 getItemNum() const;  // vtable slot 7
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    class cGUIPageListSearchPawn : public uGUIRimStone::cGUIPageListCommon
    {
        friend class uGUIRimStone;
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
        cGUIPageListSearchPawn();
        virtual ~cGUIPageListSearchPawn() {}
        virtual s32 getTabId() const;  // vtable slot 22
        virtual s32 getCategory() const;  // vtable slot 23
        void setCategory(s32 category);
        virtual s32 getItemNum() const;  // vtable slot 7
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
    private:
        s32 mCategory;  // offset: 0x44
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
    static bool Show(uGUIBase* base);
    static void RequestSearchResultSe(uGUIBase* base);
    uGUIRimStone();
    virtual ~uGUIRimStone();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    bool show();
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    virtual s32 getSMenuCursorYOrder(s32 orderId);  // vtable slot 73
    virtual s32 getSMenuTab();  // vtable slot 74
private:
    void updateInit();
    void updateWait();
    void updateExit();
    bool isPawnFree(const cPawnListParam& pawnListParam) const;
    const cPawnListVec& refSearchPawnList() const;
    const cPawnListVec& refMainPawnList() const;
    const cPawnListVec& refSupportPawnList() const;
    const cPawnListVec& refLostPawnList() const;
    const cPawnListVec& refPawnList(s32 tabId) const;
    s32 getMaxDispNumPerPage(s32 tabId) const;
    s32 getPawnListDispNum(s32 tabId, s32 pageIndex) const;
    void setCategoryFocus(s32 category, CATEGORY_FOCUS_TYPE focusType);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void setupControls();
    void updateControls();
    void updateListControl(cGUIPageList& pageList, CONTROL_ID listControlId, CONTROL_ID layoutControlId);
    CONTROL_ID getListControlId(s32 tabId) const;
    void updateFocus();
    void evTabMove();
    u32 evCtrlTabMove(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    s32 getTabId() const;
    MODE checkMode() const;
    void updateMode();
    void setFlow(MODE mode);
    void updateDisp();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rSoundRequest* mpSeRes;  // offset: 0x8d0
    MODE mMode;  // offset: 0x8d8
    cGUIControlMgr mControlMgr;  // offset: 0x8e0
    DATA mData;  // offset: 0xd90
    s32 mTabNum;  // offset: 0xf28
    uGUIBase::cReferenceUITab mTab;  // offset: 0xf30
    uGUIBase::cReferenceUIButton mButtonSearchConfig;  // offset: 0xfe0
    uGUIBase::cReferenceUINumPager mNumPager;  // offset: 0x1170
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x1218
    uGUIBase::cReferenceUIBtnGuide mButtonGuide;  // offset: 0x1270
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x1308
    uGUIBase::cReferenceUIVlCursor mCursorCategory;  // offset: 0x1330
    nDDOUtility::cArray<uGUIBase::cReferenceUIVlCursor, 4> mCursorPawnLists;  // offset: 0x13e0
    PawnNameColors mPawnNameColors;  // offset: 0x16a0
    DispPawns mDispPawns;  // offset: 0x16a8
    cPawnListVec mDummyPawnList;  // offset: 0x3818
    cPawnListVec mEmptyPawnList;  // offset: 0x3838
    bool mIsSetup;  // offset: 0x3858
    cGUIPageListSearchCategory mPageListSearchCategory;  // offset: 0x3860
    cGUIPageListSearchPawn mPageListSearchPawn;  // offset: 0x38a8
    cGUIPageListMainPawn mPageListMainPawn;  // offset: 0x38f0
    cGUIPageListSupportPawn mPageListSupportPawn;  // offset: 0x3938
    cGUIPageListLostPawn mPageListLostPawn;  // offset: 0x3980
public:
    static MyDTI DTI;
    static const int MAX_PAWN_NUM_PER_PAGE = 10;
};

inline void* uGUIRimStone::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIRimStone::cGUIPageListSearchCategory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIRimStone::cGUIPageListSearchCategory::cGUIPageListSearchCategory() {
}

inline void* uGUIRimStone::cGUIPageListSearchPawn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIRimStone::cGUIPageListSearchPawn::cGUIPageListSearchPawn() {
    this->mCategory = 6;
}

inline void* uGUIRimStone::cGUIPageListCommon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIRimStone::cGUIPageListCommon::cGUIPageListCommon() {
}

inline void* uGUIRimStone::cGUIPageListMainPawn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIRimStone::cGUIPageListMainPawn::cGUIPageListMainPawn() {
}

inline void* uGUIRimStone::cGUIPageListSupportPawn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIRimStone::cGUIPageListSupportPawn::cGUIPageListSupportPawn() {
}

inline void* uGUIRimStone::cGUIPageListLostPawn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIRimStone::cGUIPageListLostPawn::cGUIPageListLostPawn() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIRimStone::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIRimStone::DTI)->memFree(p_addr);
}

inline void* uGUIRimStone::cGUIPageListSearchCategory::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListSearchCategory::DTI)->memAlloc(sz, align, ::uGUIRimStone::cGUIPageListSearchCategory::DTI.::MtDTI::getID());
}

inline void uGUIRimStone::cGUIPageListSearchCategory::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListSearchCategory::DTI)->memFree(p_addr);
}

inline void* uGUIRimStone::cGUIPageListSearchPawn::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListSearchPawn::DTI)->memAlloc(sz, align, ::uGUIRimStone::cGUIPageListSearchPawn::DTI.::MtDTI::getID());
}

inline void uGUIRimStone::cGUIPageListSearchPawn::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListSearchPawn::DTI)->memFree(p_addr);
}

inline void* uGUIRimStone::cGUIPageListMainPawn::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListMainPawn::DTI)->memAlloc(sz, align, ::uGUIRimStone::cGUIPageListMainPawn::DTI.::MtDTI::getID());
}

inline void uGUIRimStone::cGUIPageListMainPawn::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListMainPawn::DTI)->memFree(p_addr);
}

inline void* uGUIRimStone::cGUIPageListSupportPawn::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListSupportPawn::DTI)->memAlloc(sz, align, ::uGUIRimStone::cGUIPageListSupportPawn::DTI.::MtDTI::getID());
}

inline void uGUIRimStone::cGUIPageListSupportPawn::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListSupportPawn::DTI)->memFree(p_addr);
}

inline void* uGUIRimStone::cGUIPageListLostPawn::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListLostPawn::DTI)->memAlloc(sz, align, ::uGUIRimStone::cGUIPageListLostPawn::DTI.::MtDTI::getID());
}

inline void uGUIRimStone::cGUIPageListLostPawn::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIRimStone::cGUIPageListLostPawn::DTI)->memFree(p_addr);
}
