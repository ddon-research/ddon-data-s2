#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "cGUIPageList.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtObject;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObject;
class rGUI;

// Declarations
class uGUIClanScout;
class uGUIClanScoutBase;
class uGUIClanScoutEntry;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIClanScoutBase : public uGUIBase
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
    uGUIClanScoutBase();
    virtual ~uGUIClanScoutBase();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
protected:
    virtual void initFlow();  // vtable slot 91
    virtual void setupInstances();  // vtable slot 92
    virtual void setupObjects();  // vtable slot 93
    virtual void setupRefrenceUIs();  // vtable slot 94
    virtual void setupControls();  // vtable slot 95
    void updateInit();
    void updateWait();
    virtual void onUpdateInit();  // vtable slot 96
    virtual void onUpdateWait();  // vtable slot 97
protected:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIControlMgr mControlMgr;  // offset: 0x8d0
public:
    static MyDTI DTI;
};

class uGUIClanScoutEntry : public uGUIClanScoutBase
{
public:
    enum EDITBUTTON_ID
    {
        EDITBUTTON_MOTTO = 0,
        EDITBUTTON_TIME = 1,
        EDITBUTTON_FEATURE = 2,
        EDITBUTTON_NUM = 3,
    };
    enum POS_V
    {
        POS_V_MOTTO = 0,
        POS_V_TIME = 1,
        POS_V_FEATURE = 2,
        POS_V_COMMENT = 3,
        POS_V_BUTTON = 4,
        POS_V_NUM = 5,
    };
    enum CONTROL_ID
    {
        CONTROL_POS_V = 0,
        CONTROL_BUTTON = 1,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
    enum BUTTON_ID
    {
        BUTTON_DECIDE = 0,
        BUTTON_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_MOVE = 66,
        INPUTEVENT_DECIDE = 67,
    };
    enum CHECKLIST_PAGE
    {
        CHECKLIST_PAGE_MOTTO = 0,
        CHECKLIST_PAGE_FEATURE = 0,
        CHECKLIST_PAGE_DAY = 0,
        CHECKLIST_PAGE_HOUR = 1,
        CHECKLIST_PAGE_MAX = 2,
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
    static EDITBUTTON_ID getEditButtonId(POS_V posV);
    uGUIClanScoutEntry();
    virtual ~uGUIClanScoutEntry();
    virtual s32 getSMenuCursorY();  // vtable slot 72
protected:
    virtual void initFlow();  // vtable slot 91
    virtual void setupInstances();  // vtable slot 92
    virtual void setupObjects();  // vtable slot 93
    virtual void setupRefrenceUIs();  // vtable slot 94
    virtual void setupControls();  // vtable slot 95
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlMove(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    void evDecide();
    void evCheckListDecide();
    void evCheckListCancel();
    void updateFocus();
    void updateKeyword();
    virtual void onUpdateInit();  // vtable slot 96
    virtual void onUpdateWait();  // vtable slot 97
    virtual void onDecide();  // vtable slot 98
protected:
    cGUIInstAnimation* mpINST_window_frame;  // offset: 0xd80
    cGUIInstNull* mpINST_Null_checklist00;  // offset: 0xd88
    uGUIBase::cClanPolicyMessages mClanPolicyMessages;  // offset: 0xd90
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0xde8
    uGUIBase::cReferenceUITextBox mTextBox;  // offset: 0xe40
    uGUIBase::cReferenceUICheckListForClan mCheckList;  // offset: 0xfa8
    nDDOUtility::cArray<MtFloat2, 3> mCheckListPositions;  // offset: 0x1528
    u32 mClanParamDay;  // offset: 0x1540
    nDDOUtility::cArray<uGUIBase::cReferenceUIEditBtn, 3> mEditButtons;  // offset: 0x1548
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mButtons;  // offset: 0x1638
public:
    static MyDTI DTI;
    static const u32 MOTTO_MAX = 2;
    static const u32 DAY_MAX = 1;
    static const u32 HOUR_MAX = 1;
    static const u32 FEATURE_MAX = 4;
};

class uGUIClanScout : public uGUIClanScoutBase
{
public:
    enum CONTROL_ID
    {
        CONTROL_DECIDE = 0,
        CONTROL_SCOUT_ENTRY_LIST = 1,
        CONTROL_SCOUT_ENTRY_PAGE = 2,
        CONTROL_INVALID = 3,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DECIDE = 0,
        CONTROL_CATEGORY_SCOUT_ENTRY = 1,
    };
public:
    class MyDTI;
    struct ScoutEntry;
    class cGUIPageListScoutEntry;
public:
    using ScoutEntrys = nDDOUtility::cArray<uGUIClanScout::ScoutEntry, 10>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct ScoutEntry
    {
    public:
        ScoutEntry();
        ~ScoutEntry();
        void setup(s32 index, uGUIClanScout* owner, cGUIInstNull* pINST_Null, cGUIInstance* pINST_duplicated);
    public:
        uGUIClanScout* mpOwner;  // offset: 0x0
        s32 mIndex;  // offset: 0x8
        uGUIBase::cDupliInstNull mInst;  // offset: 0x10
        cGUIInstAnimation* mpINST_msg_listtop;  // offset: 0x38
        cGUIObjMessage* mpOBJ_msg_listtop_m_name;  // offset: 0x40
        cGUIObjMessage* mpOBJ_msg_listtop_m_comment;  // offset: 0x48
        cGUIObjPolygon* mpOBJ_msg_listtop_mouseover;  // offset: 0x50
    };
public:
    class cGUIPageListScoutEntry : public cGUIPageList
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
        cGUIPageListScoutEntry();
        virtual ~cGUIPageListScoutEntry() {}
        virtual s32 getItemNum() const;  // vtable slot 7
        virtual s32 getPageItemNum() const;  // vtable slot 8
        virtual void getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const;  // vtable slot 10
    protected:
        virtual void callbackShowItem(s32 dispItemIndex, s32 itemIndex);  // vtable slot 20
        virtual void callbackHideItem(s32 dispItemIndex);  // vtable slot 21
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
    static bool IsOperable();
    static bool IsVisible();
    uGUIClanScout();
    virtual ~uGUIClanScout();
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
protected:
    virtual void initFlow();  // vtable slot 91
    virtual void setupInstances();  // vtable slot 92
    virtual void setupObjects();  // vtable slot 93
    virtual void setupRefrenceUIs();  // vtable slot 94
    virtual void setupControls();  // vtable slot 95
    void updateControls();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    void updateFocus();
    virtual void onUpdateInit();  // vtable slot 96
    virtual void onUpdateWait();  // vtable slot 97
    virtual void onDecide();  // vtable slot 98
protected:
    ScoutEntrys mScoutEntrys;  // offset: 0xd80
    cGUIPageListScoutEntry mPageListScoutEntry;  // offset: 0x10f0
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x1138
    uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x1190
    uGUIBase::cReferenceUINumPager mNumPager;  // offset: 0x1240
    f32 mCursorNextOffsetY;  // offset: 0x12e8
    MT_CHAR mCommentBuffer[1024];  // offset: 0x12ec
    cGUIObjMessage* mpOBJ_msg_no_list_m_txt;  // offset: 0x16f0
public:
    static MyDTI DTI;
    static const s32 SCOUT_ENTRY_NUM_MAX = 10;
protected:
    static const u32 COMMENT_BUFFER_SIZE = 1024;
};

inline void* uGUIClanScout::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIClanScout::cGUIPageListScoutEntry::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIClanScout::cGUIPageListScoutEntry::cGUIPageListScoutEntry() {
}

inline void* uGUIClanScoutBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIClanScoutEntry::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
