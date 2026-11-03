#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "nGUIItem.h"
#include "sItemManager.h"
#include "uGUIBase.h"
#include "uGUIUseItemBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cOmControl;
namespace nGUIItem { class cItem; }
namespace nGUIItem { class cItemList; }
class rGUI;

// Declarations
class uGUIPick01;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPick01 : public uGUIUseItemBase
{
public:
    enum PR
    {
        PR_ITEM = 0,
        PR_PICK = 1,
        PR_MAX = 2,
    };
    enum
    {
        CF_PICKALL = 0,
        CF_ITEM = 1,
    };
    enum
    {
        PICK_TYPE_GATHER = 0,
        PICK_TYPE_DROP = 1,
        PICK_TYPE_PAWN = 2,
    };
    enum
    {
        MENU_TAG_NO_USE = 0,
        MENU_TAG_USE_ITEM00 = 1,
        MENU_TAG_USE_ITEM01 = 2,
        MENU_TAG_USE_ITEM02 = 3,
        MENU_TAG_USE_ITEM03 = 4,
        MENU_TAG_USE_ITEM04 = 5,
        MENU_TAG_USE_ITEM05 = 6,
        MENU_TAG_USE_ITEM06 = 7,
        MENU_TAG_USE_ITEM07 = 8,
        MENU_TAG_USE_ITEM08 = 9,
    };
    enum SW
    {
        SW_ITEM = 0,
        SW_PICK = 1,
    };
    enum
    {
        INPUT_EVENT_DECIDE = 66,
        INPUT_EVENT_CANCEL = 67,
        INPUT_EVENT_BASE_END = 68,
    };
public:
    class MyDTI;
    class cGUIUseItem;
    class cGUIItem;
    struct guiInst;
    struct guiObj;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGUIUseItem : public MtObject
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
        cGUIUseItem();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpInstMsg;  // offset: 0x30
        cGUIObjMessage* mpObjMsgItem;  // offset: 0x38
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x40
        cGUIObjPolygon* mpMouseover;  // offset: 0x48
        s32 mItemNum;  // offset: 0x50
        u32 mItemId;  // offset: 0x54
        static MyDTI DTI;
    };
public:
    class cGUIItem : public MtObject
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
        cGUIItem();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    struct guiInst
    {
    public:
        cGUIInstNull* Null;  // offset: 0x0
        cGUIInstNull* Null_all;  // offset: 0x8
        cGUIInstAnimation* window;  // offset: 0x10
        cGUIInstAnimation* window_frame;  // offset: 0x18
        cGUIInstAnimation* msg_top;  // offset: 0x20
        cGUIInstAnimation* item_frame00;  // offset: 0x28
        cGUIInstNull* Null_itemlist;  // offset: 0x30
        cGUIInstNull* Null_item;  // offset: 0x38
        cGUIInstAnimation* item_icon;  // offset: 0x40
        cGUIInstAnimation* fix_iconbase;  // offset: 0x48
        cGUIInstAnimation* fix_iconinfo;  // offset: 0x50
        cGUIInstAnimation* msg_btn00;  // offset: 0x58
        cGUIInstAnimation* fix_toggle;  // offset: 0x60
        cGUIInstNull* Null_detail;  // offset: 0x68
        cGUIInstAnimation* close_btn;  // offset: 0x70
        cGUIInstAnimation* mouse_collision;  // offset: 0x78
        cGUIInstNull* Null_pick;  // offset: 0x80
        cGUIInstNull* Null_menu;  // offset: 0x88
        cGUIInstAnimation* fix_window;  // offset: 0x90
        cGUIInstAnimation* fix_window_frame;  // offset: 0x98
        cGUIInstAnimation* msg_title;  // offset: 0xa0
        cGUIInstNull* Null_listall;  // offset: 0xa8
        cGUIInstAnimation* cursor;  // offset: 0xb0
        cGUIInstAnimation* msg_list;  // offset: 0xb8
        cGUIInstNull* Null_list;  // offset: 0xc0
        cGUIInstAnimation* msg_nouse;  // offset: 0xc8
        cGUIInstNull* Null_message;  // offset: 0xd0
        cGUIInstAnimation* msg_charges;  // offset: 0xd8
    };
public:
    struct guiObj
    {
    public:
        cGUIObjMessage* msg_top_m_top00;  // offset: 0x0
        cGUIObjMessage* msg_top_m_top01;  // offset: 0x8
        cGUIObjMessage* msg_title_m_section;  // offset: 0x10
        cGUIObjMessage* msg_itemnum_m_num;  // offset: 0x18
        cGUIObjMessage* msg_nouse_m_txt;  // offset: 0x20
        cGUIObjPolygon* msg_nouse_mouseover;  // offset: 0x28
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
    uGUIPick01();
    virtual ~uGUIPick01();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    bool setProc(PR proc, bool force);
    void setOM(cOmControl* pOmCtrl, u32 pick_type);
    bool isGetAllItem();
    bool isGetItem();
    bool isUseItem();
    virtual void setFlowId(u32 flowId);  // vtable slot 124
private:
    nGUIItem::cItem* getSelectItem();
    virtual void updateInit();  // vtable slot 93
    virtual void updateWait();  // vtable slot 112
    virtual void updateWaitPopup();  // vtable slot 114
    virtual void updateWaitServer();  // vtable slot 116
    void updateWaitOM();
    virtual void updateExit();  // vtable slot 113
    void changeFocusMatrix(s32 focus);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlMoveFocusCtrl(cControl::Message* msg);
    u32 evCtrlMove(cControl::Message* msg);
    u32 evCtrlMouseOver(cControl::Message* msg);
    u32 evCtrlMouseOverBtn(cControl::Message* msg);
    u32 evCtrlMouseDecide(cControl::Message* msg);
public:
    MtTypedArray<cGUIUseItem> mGUIUseItemArray;  // offset: 0xc38
    MtTypedArray<cGUIItem> mGUIItemArray;  // offset: 0xc58
private:
    guiInst mDataInst;  // offset: 0xc78
    guiObj mDataObj;  // offset: 0xd58
    rGUI* mpGUIRes;  // offset: 0xd88
    PR mProc;  // offset: 0xd90
    u32 mCtrlFocus;  // offset: 0xd94
    u32 mCtrlFocusOld;  // offset: 0xd98
    f32 mListY;  // offset: 0xd9c
    s32 mUseItemNum;  // offset: 0xda0
    s32 mMatrixSelPos;  // offset: 0xda4
    uGUIBase::cReferenceUIVlCursor mRefCursor;  // offset: 0xdb0
    uGUIBase::cReferenceUIButton2 mRefButton;  // offset: 0xe60
    uGUIBase::cReferenceUIToggleBtn mRefToggleBtn;  // offset: 0xff0
    uGUIBase::cReferenceUIChargesInfo mRefChargesInfo;  // offset: 0x10a0
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x11f8
    cOmControl* mpOmCtrl;  // offset: 0x1250
    bool mIsGetAllItem;  // offset: 0x1258
    bool mIsGetItem;  // offset: 0x1259
    cControl* mpButtonCtrl;  // offset: 0x1260
    uGUIBase::cHorizontalList* mpDebugCtrl;  // offset: 0x1268
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x1270
    uGUIBase::cVerticalList* mpVCtrlPick;  // offset: 0x1278
    uGUIBase::cMatrix* mpMatCtrl;  // offset: 0x1280
    nGUIItem::cItemList mMyItemList;  // offset: 0x1288
    u32 mUseItemList[8];  // offset: 0x1400
    u32 mMenuTag[9];  // offset: 0x1420
public:
    static MyDTI DTI;
    static const sItemManager::cItemBag::ITEM_CATEGORY CATEGORY_LIST[];
    static const u32 USE_ITEM_LIST_NUM = 8;
};

inline void* uGUIPick01::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIPick01::cGUIUseItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIPick01::cGUIItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
