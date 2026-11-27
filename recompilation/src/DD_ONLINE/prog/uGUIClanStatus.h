#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Clan.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class CDataClanParam;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class rGUIMessage;
class uGUIMenuAreaInfo;

// Declarations
class uGUIClanStatus;
class uGUIClanStatusBase;

// Type aliases from DWARF
using CClanParam = CDataClanParam;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uGUIClanStatusBase : public uGUIBase
{
public:
    enum MEMBER_DISP_MODE
    {
        MEMBER_DISP_MODE_DEFAULT = 0,
        MEMBER_DISP_MODE_LOGIN = 1,
        MEMBER_DISP_MODE_COMMENT = 2,
        MEMBER_DISP_MODE_NUM = 3,
    };
    enum COLUMN_TYPE
    {
        COLUMN_TYPE_NONE = 0,
        COLUMN_TYPE_MEMBER = 1,
        COLUMN_TYPE_HISTORY = 2,
    };
    enum COLUMN_ID
    {
        COLUMN_MEMBER_NAME = 0,
        COLUMN_MEMBER_JOB = 1,
        COLUMN_MEMBER_LOBBY = 2,
        COLUMN_MEMBER_DUMMY = 3,
        COLUMN_MEMBER_DATE = 4,
        COLUMN_MEMBER_PARTY = 5,
        COLUMN_MEMBER_COMMENT = 2,
        COLUMN_HISTORY_DATE = 0,
        COLUMN_HISTORY_DETAIL = 1,
        COLUMN_NUM = 6,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_DISP_CHANGE = 66,
        INPUTEVENT_INHERITANCE_START = 67,
    };
public:
    class MyDTI;
    class cScrollListItemMember;
    struct ColumnParam;
    class cScrollListInfoMember;
public:
    using ScrollListMemberItems = nDDOUtility::cArray<uGUIClanStatusBase::cScrollListItemMember, 17>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cScrollListItemMember : public uGUIBase::cScrollListItemBase
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
        cScrollListItemMember();
        virtual ~cScrollListItemMember() {}
        void setup(uGUIClanStatusBase* owner, cGUIInstNull* instNull);
    public:
        cGUIInstNull* mpINST_Null_list;  // offset: 0x58
        cGUIInstAnimation* mpINST_msg_list;  // offset: 0x60
        cGUIObjMessage* mpOBJ_msg_list_m_name;  // offset: 0x68
        cGUIObjMessage* mpOBJ_msg_list_m_lv;  // offset: 0x70
        cGUIObjMessage* mpOBJ_msg_list_m_lobby;  // offset: 0x78
        cGUIObjMessage* mpOBJ_msg_list_m_date;  // offset: 0x80
        cGUIObjMessage* mpOBJ_msg_list_m_comment;  // offset: 0x88
        cGUIObjMessage* mpOBJ_msg_list_m_party;  // offset: 0x90
        cGUIObjTexture* mpOBJ_msg_list_party_icon;  // offset: 0x98
        cGUIInstAnimation* mpINST_fix_leader;  // offset: 0xa0
        cGUIObjTexture* mpOBJ_fix_leader_f_icon;  // offset: 0xa8
        cGUIInstAnimation* mpINST_comment;  // offset: 0xb0
        uGUIBase::cReferenceUIIconJob mIconJob;  // offset: 0xb8
        uGUIBase::cReferenceUIIconOnlineStatus mIconOnlineStatus;  // offset: 0x110
        static MyDTI DTI;
    };
public:
    struct ColumnParam
    {
    public:
        uGUIClanStatusBase::COLUMN_ID mColumnId;  // offset: 0x0
        u32 mMsgId;  // offset: 0x4
        rGUIMessage* mMsgRes;  // offset: 0x8
    };
public:
    class cScrollListInfoMember : public uGUIBase::cScrollListInfoBase
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
        cScrollListInfoMember();
        virtual ~cScrollListInfoMember() {}
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
    static bool Show(uGUIBase* gui);
    static void UpdateMemberList(uGUIBase* gui);
    uGUIClanStatusBase();
    virtual ~uGUIClanStatusBase();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
protected:
    bool show();
    void updateMemberList();
    virtual u32 getMemberListCursorPos();  // vtable slot 91
    virtual void resetMemberListSize(u32 listSize, u32 cursorPos);  // vtable slot 92
    virtual void initMembers();  // vtable slot 93
    virtual void initFlow();  // vtable slot 94
    virtual void setupInstances();  // vtable slot 95
    virtual void setupObjects();  // vtable slot 96
    virtual void setupRefrenceUIs();  // vtable slot 97
    virtual void setupControls();  // vtable slot 98
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlDispChange(cControl::Message* msg);
    void evDispChange();
    void updateInit();
    void updateWait();
    virtual void onUpdateInit();  // vtable slot 99
    virtual void onUpdateWait();  // vtable slot 100
    void setColumnNames(COLUMN_TYPE columnType);
    void setColumnName(const ColumnParam& columnParam);
    void setupScrollListMember();
    void initScrollListMember();
    void prepareScrollListMember();
    void showListItemMember(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItemMember(uGUIBase::cScrollListItemBase* pItemBase);
    void updateDispMember();
protected:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstAnimation* mpINST_scr_bar;  // offset: 0x8d0
    cGUIInstNull* mpINST_Null_list00;  // offset: 0x8d8
    cGUIInstAnimation* mpINST_msg_text;  // offset: 0x8e0
    cGUIObjMessage* mpOBJ_msg_text_m_text;  // offset: 0x8e8
    cGUIObjPolygon* mpOBJ_mask_top;  // offset: 0x8f0
    cGUIObjPolygon* mpOBJ_mask_center;  // offset: 0x8f8
    cGUIObjPolygon* mpOBJ_mask_bottom;  // offset: 0x900
    nDDOUtility::cArray<cGUIObjMessage*, 6> mpOBJ_msg_select_m_sections;  // offset: 0x908
    cGUIControlMgr mControlMgr;  // offset: 0x938
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0xde8
    uGUIBase::cReferenceUIBtnGuide mButtonGuide;  // offset: 0xe40
    uGUIBase::cScrollList mScrollListMember;  // offset: 0xee0
    ScrollListMemberItems mScrollListMemberItems;  // offset: 0x1190
    MEMBER_DISP_MODE mMemberDispMode;  // offset: 0x28f0
    MT_CHAR mCommentBuffer[1024];  // offset: 0x28f4
    bool mIsSetup;  // offset: 0x2cf4
    bool mIsVisibleScrollBar;  // offset: 0x2cf5
    bool mIsMyClan;  // offset: 0x2cf6
    bool mIsMaster;  // offset: 0x2cf7
    bool mIsInitScrollListMember;  // offset: 0x2cf8
public:
    static MyDTI DTI;
protected:
    static const s32 ScrollListMemberDispNumMax = 15;
    static const s32 ScrollListMemberItemNumMax = 17;
    static const u32 COMMENT_BUFFER_SIZE = 1024;
};

class uGUIClanStatus : public uGUIClanStatusBase
{
public:
    enum CONTROL_ID
    {
        CONTROL_TAB = 0,
        CONTROL_BUTTON_COMMON = 1,
        CONTROL_BUTTON_STATUS = 2,
        CONTROL_BUTTON_MEMBER = 3,
        CONTROL_MEMBER = 4,
        CONTROL_HISTORY = 5,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_COMMON = 0,
        CONTROL_CATEGORY_STATUS = 1,
        CONTROL_CATEGORY_MEMBER = 2,
        CONTROL_CATEGORY_HISTORY = 3,
    };
    enum TAB_ID
    {
        TAB_STATUS = 0,
        TAB_MEMBER = 1,
        DEFAULT_TAB_NUM = 2,
        TAB_HISTORY = 2,
        MY_CLAN_TAB_NUM = 3,
        TAB_NUM_MAX = 3,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_CHANGE_TAB = 67,
        INPUTEVENT_EDIT_STATUS = 68,
        INPUTEVENT_AREA_INFO = 69,
    };
public:
    class MyDTI;
    struct Status;
    class cHistoryItem;
    class cHistoryInfo;
    class cHistoryList;
    class cHistoryListItems;
public:
    using HistoryItems = nDDOUtility::cArray<uGUIClanStatus::cHistoryItem, 22>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Status
    {
    public:
        cGUIInstAnimation* mpINST_fix_leader;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg_clanname_m_clanname;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_clanname_m_abbreviate;  // offset: 0x10
        cGUIObjMessage* mpOBJ_msg_clanname_m_master;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_clanname_m_clanlvnum;  // offset: 0x20
        cGUIObjMessage* mpOBJ_msg_clanname_m_clanpoint;  // offset: 0x28
        cGUIObjMessage* mpOBJ_msg_status00_m_member;  // offset: 0x30
        cGUIObjMessage* mpOBJ_msg_status00_m_date;  // offset: 0x38
        cGUIObjMessage* mpOBJ_msg_status00_m_cpnum;  // offset: 0x40
        cGUIObjMessage* mpOBJ_msg_status00_m_title;  // offset: 0x48
        cGUIObjMessage* mpOBJ_msg_status02_m_text00;  // offset: 0x50
        cGUIObjMessage* mpOBJ_msg_status02_m_text01;  // offset: 0x58
        cGUIObjMessage* mpOBJ_msg_status02_m_section01;  // offset: 0x60
    };
public:
    class cHistoryItem : public uGUIBase::cScrollListItemBase
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
        cHistoryItem();
        virtual ~cHistoryItem() {}
        void setup(uGUIClanStatus& owner, cGUIInstNull* inst_null_list);
        void show(uGUIClanStatus::cHistoryInfo& info);
        void hide();
        void setDate(u64 date);
        void setDetail(MT_CTSTR detail);
    private:
        cGUIInstNull* mpINST_Null_list;  // offset: 0x58
        cGUIObjMessage* mpOBJ_msg_list_m_date;  // offset: 0x60
        cGUIObjMessage* mpOBJ_msg_list_m_history;  // offset: 0x68
    public:
        static MyDTI DTI;
    };
public:
    class cHistoryInfo : public uGUIBase::cScrollListInfoBase
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
        cHistoryInfo();
        virtual ~cHistoryInfo();
        u64 getDate() const;
        void setDate(u64 date);
        MT_CTSTR getDetail() const;
        void setDetail(MT_CTSTR detail);
    private:
        u64 mDate;  // offset: 0x28
        MtString mDetail;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
public:
    class cHistoryList
    {
        friend class uGUIClanStatus;
    public:
        cHistoryList();
        virtual ~cHistoryList();
        void setup(uGUIClanStatus& owner, uGUIClanStatus::HistoryItems& items);
        f32 getMaskHeight() const;
        f32 getItemSpacing() const;
        f32 getItemMargin() const;
        uGUIBase::cScrollList& refScrollList();
        const uGUIBase::cScrollList& refScrollList() const;
        bool moveEvent();
        void update(f32 deltaTime);
        void reset(s32 currentPos);
    private:
        uGUIBase::cScrollList mScrollList;  // offset: 0x10
        f32 mMaskHeight;  // offset: 0x2c0
        f32 mItemSpacing;  // offset: 0x2c4
        f32 mItemMargin;  // offset: 0x2c8
    };
public:
    class cHistoryListItems
    {
    public:
        cHistoryListItems();
        virtual ~cHistoryListItems() {}
        virtual u32 getItemNum() const = 0;  // vtable slot 2
        virtual u64 getDate(u32) const = 0;  // vtable slot 3
        virtual u8 getHistoryType(u32) const = 0;  // vtable slot 4
        virtual MT_CTSTR getFirstName(u32) const = 0;  // vtable slot 5
        virtual MT_CTSTR getLastName(u32) const = 0;  // vtable slot 6
        virtual u32 getParam1(u32) const = 0;  // vtable slot 7
        virtual u32 getParam2(u32) const = 0;  // vtable slot 8
        virtual u32 getParam3(u32) const = 0;  // vtable slot 9
        virtual MT_CTSTR getFreeText(u32) const = 0;  // vtable slot 10
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    void setHistoryListItems(const cHistoryListItems& historyListItems);
    uGUIClanStatus();
    virtual ~uGUIClanStatus();
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    virtual s32 getSMenuTab();  // vtable slot 74
protected:
    virtual u32 getMemberListCursorPos();  // vtable slot 91
    virtual void resetMemberListSize(u32 listSize, u32 cursorPos);  // vtable slot 92
    virtual void initMembers();  // vtable slot 93
    virtual void setupInstances();  // vtable slot 95
    virtual void setupObjects();  // vtable slot 96
    virtual void setupRefrenceUIs();  // vtable slot 97
    virtual void setupControls();  // vtable slot 98
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlChangeTab(cControl::Message* msg);
    u32 evCtrlEditStatus(cControl::Message* msg);
    u32 evCtrlAreaInfo(cControl::Message* msg);
    void evChangeTab();
    void evEditStatus();
    void evAreaInfo();
    virtual void onUpdateInit();  // vtable slot 99
    virtual void onUpdateWait();  // vtable slot 100
    void updateEdit();
    void updateAreaInfo();
    void updateCommon();
    void updateDispStatus();
    void updateDispHistory();
    s32 getTabNum() const;
    void makeHistoryDetail(MtString& detail, u8 historyType, MT_CTSTR firstName, MT_CTSTR lastName, u32 param1, u32 param2, u32 param3, MT_CTSTR freeText);
    void showHistoryListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideHistoryListItem(uGUIBase::cScrollListItemBase* pItemBase);
protected:
    Status mStatus;  // offset: 0x2d00
    uGUIBase::cReferenceUITab mTab;  // offset: 0x2d70
    uGUIBase::cReferenceUIClanEmblem mClanEmblem;  // offset: 0x2e20
    uGUIBase::cClanPolicyMessages mClanPolicyMessages;  // offset: 0x2f28
    nDDOUtility::cArray<uGUIBase::cReferenceUIBtnGuide::stGuideBtnData, 3> mButtonGuideDatas;  // offset: 0x2f80
    CClanParam mEditClanParam;  // offset: 0x2ff8
    uGUIMenuAreaInfo* mpGUIAreaInfo;  // offset: 0x3100
    cGUIObjMessage* mpOBJ_msg_list_m_history;  // offset: 0x3108
    bool mIsInitScrollListHistory;  // offset: 0x3110
    HistoryItems mHistoryItems;  // offset: 0x3118
    cHistoryList mHistoryList;  // offset: 0x3ac0
public:
    static MyDTI DTI;
protected:
    static const u32 BUTTON_GUIDE_AREA_INFO = 1;
    static const u32 BUTTON_GUIDE_EDIT_STATUS = 2;
    static const u32 BUTTON_GUIDE_BIT_CHANGE_DISP = 4;
    static const u32 MOTTO_MAX = 2;
    static const u32 DAY_MAX = 1;
    static const u32 HOUR_MAX = 1;
    static const u32 FEATURE_MAX = 4;
    static const s32 HISTORY_ITEM_DISP_NUM_MAX = 20;
    static const s32 HISTORY_ITEM_NUM_MAX = 22;
};

inline void* uGUIClanStatus::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIClanStatus::cHistoryItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIClanStatus::cHistoryItem::cHistoryItem() {
    this->mpOBJ_msg_list_m_history = nullptr;
    this->mpOBJ_msg_list_m_date = nullptr;
    this->mpINST_Null_list = nullptr;
}

inline void* uGUIClanStatus::cHistoryInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u64 uGUIClanStatus::cHistoryInfo::getDate() const {
    return this->mDate;
}

inline uGUIClanStatus::cHistoryListItems::cHistoryListItems() {
}

inline void* uGUIClanStatusBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIClanStatusBase::cScrollListItemMember::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIClanStatusBase::cScrollListItemMember::cScrollListItemMember() : mpINST_comment(static_cast<cGUIInstAnimation*>(nullptr)), mpOBJ_fix_leader_f_icon(static_cast<cGUIObjTexture*>(nullptr)), mpINST_fix_leader(static_cast<cGUIInstAnimation*>(nullptr)), mpOBJ_msg_list_party_icon(static_cast<cGUIObjTexture*>(nullptr)), mpOBJ_msg_list_m_party(static_cast<cGUIObjMessage*>(nullptr)), mpOBJ_msg_list_m_comment(static_cast<cGUIObjMessage*>(nullptr)), mpOBJ_msg_list_m_date(static_cast<cGUIObjMessage*>(nullptr)), mpOBJ_msg_list_m_lobby(static_cast<cGUIObjMessage*>(nullptr)), mpOBJ_msg_list_m_lv(static_cast<cGUIObjMessage*>(nullptr)), mpOBJ_msg_list_m_name(static_cast<cGUIObjMessage*>(nullptr)), mpINST_msg_list(static_cast<cGUIInstAnimation*>(nullptr)), mpINST_Null_list(static_cast<cGUIInstNull*>(nullptr)) {
}

inline void* uGUIClanStatusBase::cScrollListInfoMember::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIClanStatus::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanStatus::DTI)->memFree(p_addr);
}

inline void* uGUIClanStatus::cHistoryItem::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIClanStatus::cHistoryItem::DTI)->memAlloc(sz, align, ::uGUIClanStatus::cHistoryItem::DTI.::MtDTI::getID());
}

inline void uGUIClanStatus::cHistoryItem::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanStatus::cHistoryItem::DTI)->memFree(p_addr);
}

inline void uGUIClanStatusBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanStatusBase::DTI)->memFree(p_addr);
}

inline void* uGUIClanStatusBase::cScrollListItemMember::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIClanStatusBase::cScrollListItemMember::DTI)->memAlloc(sz, align, ::uGUIClanStatusBase::cScrollListItemMember::DTI.::MtDTI::getID());
}

inline void uGUIClanStatusBase::cScrollListItemMember::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanStatusBase::cScrollListItemMember::DTI)->memFree(p_addr);
}

inline void uGUIClanStatusBase::cScrollListInfoMember::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanStatusBase::cScrollListInfoMember::DTI)->memFree(p_addr);
}
