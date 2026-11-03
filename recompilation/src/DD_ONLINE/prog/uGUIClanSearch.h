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
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObject;
class rGUI;
class rSoundRequest;

// Declarations
class uGUIClanSearch;
class uGUIClanSearchBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIClanSearchBase : public uGUIBase
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
    uGUIClanSearchBase();
    virtual ~uGUIClanSearchBase();
    rSoundRequest* getSoundRes();
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
    rSoundRequest* mpSeRes;  // offset: 0x8d0
    cGUIControlMgr mControlMgr;  // offset: 0x8d8
public:
    static MyDTI DTI;
};

class uGUIClanSearch : public uGUIClanSearchBase
{
public:
    enum CONTROL_ID
    {
        CONTROL_DECIDE = 0,
        CONTROL_SEARCH_CLAN = 1,
        CONTROL_SEARCH_CLAN_LIST = 2,
        CONTROL_SEARCH_CLAN_PAGE = 3,
        CONTROL_INVALID = 4,
    };
    enum CONTROL_LAYOUT
    {
        CONTROL_LAYOUT_LIST = 0,
        CONTROL_LAYOUT_BUTTON = 1,
        CONTROL_LAYOUT_NUM = 2,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
public:
    class MyDTI;
    struct DispClan;
    class cGUIPageListSearchClan;
public:
    using DispClans = nDDOUtility::cArray<uGUIClanSearch::DispClan, 4>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DispClan
    {
    public:
        DispClan();
        ~DispClan();
        void setup(s32 index, uGUIClanSearch* owner, cGUIInstNull* pINST_Null, cGUIInstance* pINST_duplicated);
    public:
        uGUIClanSearch* mpOwner;  // offset: 0x0
        s32 mIndex;  // offset: 0x8
        uGUIBase::cDupliInstNull mInst;  // offset: 0x10
        uGUIBase::cReferenceUIClanEmblem mClanEmblem;  // offset: 0x38
        cGUIInstAnimation* mpINST_msg_clanlist;  // offset: 0x140
        cGUIObjMessage* mpOBJ_msg_clanlist_m_clanlvnum;  // offset: 0x148
        cGUIObjMessage* mpOBJ_msg_clanlist_m_clanname;  // offset: 0x150
        cGUIObjMessage* mpOBJ_msg_clanlist_m_master;  // offset: 0x158
        cGUIObjMessage* mpOBJ_msg_clanlist_m_text00;  // offset: 0x160
        cGUIObjMessage* mpOBJ_msg_clanlist_m_text01;  // offset: 0x168
        cGUIObjMessage* mpOBJ_msg_clanlist_m_keyword00;  // offset: 0x170
        cGUIObjMessage* mpOBJ_msg_clanlist_m_keyword01;  // offset: 0x178
        cGUIObjPolygon* mpOBJ_msg_clanlist_mouseover;  // offset: 0x180
    };
public:
    class cGUIPageListSearchClan : public cGUIPageList
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
        cGUIPageListSearchClan();
        virtual ~cGUIPageListSearchClan();
        virtual s32 getItemNum() const;  // vtable slot 7
        virtual s32 getPageItemNum() const;  // vtable slot 8
        virtual f32 getCursorPosY(s32 dispItemIndex) const;  // vtable slot 9
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
    uGUIClanSearch();
    virtual ~uGUIClanSearch();
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
    DispClans mDispClans;  // offset: 0xd88
    cGUIPageListSearchClan mPageListSearchClan;  // offset: 0x13a8
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x13f0
    uGUIBase::cReferenceUIButton mButton;  // offset: 0x1448
    uGUIBase::cReferenceUINumPager mNumPager;  // offset: 0x15d8
    cGUIInstAnimation* mpINST_cursor;  // offset: 0x1680
    cGUIObjNull* mpOBJ_cursor_Null_pointer;  // offset: 0x1688
    f32 mDefultCursorY;  // offset: 0x1690
    f32 mCursorNextOffsetY;  // offset: 0x1694
    cGUIObjMessage* mpOBJ_msg_txt_m_txt;  // offset: 0x1698
public:
    static MyDTI DTI;
    static const s32 DISP_CLAN_NUM_MAX = 4;
};

inline void* uGUIClanSearch::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIClanSearch::cGUIPageListSearchClan::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIClanSearch::cGUIPageListSearchClan::cGUIPageListSearchClan() {
}

inline void* uGUIClanSearchBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
