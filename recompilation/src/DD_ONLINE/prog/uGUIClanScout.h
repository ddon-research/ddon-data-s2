#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "cGUIPageList.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
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
        virtual ~cGUIPageListScoutEntry();
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

inline uGUIClanScout::cGUIPageListScoutEntry::cGUIPageListScoutEntry() {
}
