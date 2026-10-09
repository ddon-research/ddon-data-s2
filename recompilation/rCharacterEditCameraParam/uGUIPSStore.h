#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/MtTime.h"
#include "../shared/cControl.h"
#include "../shared/cGUIControlMgr.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtTime;
class cControl;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class rGUIMessage;
class uGUISystemMsg;

// Declarations
class uGUIPSStore;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIPSStore : public uGUIBase
{
public:
    enum DLC_STATION_FLOW
    {
        LIST_FLOW_STATION = 0,
        LIST_FLOW_HISTORY = 1,
        LIST_FLOW_CATEGORY = 2,
        LIST_FLOW_ITEM_CONFIRM = 3,
    };
    enum
    {
        CATEGORY_MAX = 2,
        STATION_MAX = 50,
        HISTORY_MAX = 50,
        ITEM_SELECT_NONE = -1,
    };
    enum
    {
        DLC_GUIDE_DECIDE = 1,
        DLC_GUIDE_BIT_MAX = 1,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CATEGORY_UD = 68,
        INPUTEVENT_CATEGORY_DECIDE = 69,
        INPUTEVENT_CATEGORY_CANCEL = 70,
        INPUTEVENT_STATION_UD = 71,
        INPUTEVENT_STATION_DECIDE = 72,
        INPUTEVENT_STATION_CANCEL = 73,
        INPUTEVENT_CATE_LCLICK_UD = 74,
        INPUTEVENT_CATE_LCLICK_DECIDE = 75,
        INPUTEVENT_STAT_LCLICK = 76,
        INPUTEVENT_HIST_LCLICK = 77,
    };
    enum
    {
        MGR_ID_CATEGORY_MENU = 0,
    };
    enum
    {
        CONTROL_CATE_CATEGORY = 0,
    };
    enum
    {
        LIST_CURSOR_NUM_STATION = 7,
        LIST_CURSOR_NUM_HISTORY = 15,
    };
    enum
    {
        REQ_FLAG_WAIT = 0,
        REQ_FLAG_STATION_LIST = 1,
        REQ_FLAG_HISTORY_LIST = 2,
        REQ_FLAG_CLEAR = 3,
        REQ_FLAG_ITEM_USE = 4,
        REQ_FLAG_END = 5,
    };
public:
    class MyDTI;
    struct stCategoryItem;
    class cStationListItem;
    class cHistoryListItem;
    class cStationListInfo;
    class cHistoryListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stCategoryItem
    {
    public:
        cGUIInstAnimation* pInst;  // offset: 0x0
        cGUIObjMessage* pMessage;  // offset: 0x8
    };
public:
    class cStationListItem : public uGUIBase::cScrollListItemBase
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
        cStationListItem();
        // Address: 0x01aff560 - 0x01aff561 (1 bytes)
        virtual ~cStationListItem() {}
    public:
        cGUIInstAnimation* mpInstIcon;  // offset: 0x58
        cGUIInstAnimation* mpInstButton;  // offset: 0x60
        cGUIInstAnimation* mpInstList;  // offset: 0x68
        cGUIObjMessage* mpObjContent;  // offset: 0x70
        cGUIObjMessage* mpObjStack;  // offset: 0x78
        s32 mItemIndex;  // offset: 0x80
        static MyDTI DTI;
    };
public:
    class cHistoryListItem : public uGUIBase::cScrollListItemBase
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
        cHistoryListItem();
        // Address: 0x01aff550 - 0x01aff551 (1 bytes)
        virtual ~cHistoryListItem() {}
    public:
        cGUIInstAnimation* mpInstList;  // offset: 0x58
        cGUIObjMessage* mpObjDate;  // offset: 0x60
        cGUIObjMessage* mpObjItemName;  // offset: 0x68
        cGUIObjMessage* mpObjCharacterName;  // offset: 0x70
        static MyDTI DTI;
    };
public:
    class cStationListInfo : public uGUIBase::cScrollListInfoBase
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
        cStationListInfo();
        // Address: 0x01aff820 - 0x01aff821 (1 bytes)
        virtual ~cStationListInfo() {}
    public:
        MT_CTSTR mpItemName;  // offset: 0x28
        u32 mStack;  // offset: 0x30
        f32 mButtonTop;  // offset: 0x34
        s32 mItemBaseIndex;  // offset: 0x38
        cGUIInstAnimation* mpInstButton;  // offset: 0x40
        u32 mItemID;  // offset: 0x48
        static MyDTI DTI;
    };
public:
    class cHistoryListInfo : public uGUIBase::cScrollListInfoBase
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
        cHistoryListInfo();
        virtual ~cHistoryListInfo();
    public:
        MtTime mDate;  // offset: 0x28
        MtString mTmpItemName;  // offset: 0x30
        MtString mTmpCharaName;  // offset: 0x38
        MtString mTmpDate;  // offset: 0x40
        MT_CTSTR mpItemName;  // offset: 0x48
        MT_CTSTR mpCharacterName;  // offset: 0x50
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
    uGUIPSStore();
    virtual ~uGUIPSStore();
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateWait();
    void updateGuide();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlCategoryMenuCursorUD(cControl::Message* pMsg);
    u32 evCtrlDecide(cControl::Message* pMsg);
    u32 evCtrlClose(cControl::Message* pMsg);
    u32 evCtrlCateLClick(cControl::Message* pMsg);
    u32 evCtrlListLClick(cControl::Message* pMsg);
    void setupWindow();
    void setupCategoryMenu();
    void setupStationWindow();
    void setupHistoryCommon();
    void setupHistoryWindow();
    void setFlow(s32 categoryMenuCurrentIndex);
    void reloadFlow();
    void setSequence(cGUIInstAnimation* pInst, const u32 id);
    void setEnableKey(cControl* pCtrl, bool flag);
    void adjustCategoryMenuCursor();
    s32 getCurrentMenuIndex();
    void adjustList();
    void initStationScroll();
    void setupStationScrollInfo();
    void updateStationItemDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateStationItemHide(uGUIBase::cScrollListItemBase* pDispItem);
    void adjustStationItem();
    void resetStationItemScrl();
    void setVisibleStation(bool isVisible);
    void useItem();
    void setButtonSequence(const s32 posIndex, const u32 sequenceID);
    void resetButtonSequence();
    void initHistoryScroll();
    void setupHistoryScrollInfo();
    void updateHistoryItemDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateHistoryItemHide(uGUIBase::cScrollListItemBase* pDispItem);
    void adjustHistoryItem();
    void setVisibleHistory(bool isVisible);
    void setNoticeNum();
    void setupItemUseDialog();
    void updateItemUseDialog();
    void psstoreEventCateCursorUD();
    void psstoreEventListCursorUD();
    void psstoreEventListDecide();
    void psstoreEventCateDecide();
    void psstoreEventCancel();
    void psstoreEventClose();
    void psstoreEventCateLClickUD();
    void psstoreEventCateLClick();
    void psstoreEventStatLClick();
    void psstoreEventHistLClick();
    void psstoreEventShiftStation();
    void psstoreEventShiftHistory();
    void psstoreEventShiftList();
    void requestServer(u8 reqFlag);
    void checkRequestList();
    void initStationCallback();
    void initHisotryCallback();
    void initRequestCallback();
    void itemUseCallback();
    bool requestServerStationList();
    bool requestServerHistoryList();
    bool requestServerUseItem();
private:
    bool mIsSetup;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    rGUIMessage* mpGMDRes;  // offset: 0x8d8
    cControl* mpCtrlCancel;  // offset: 0x8e0
    cControl* mpCtrlDecide;  // offset: 0x8e8
    cGUIInstAnimation* mpInstWindow;  // offset: 0x8f0
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x8f8
    cGUIInstNull* mpInstNull;  // offset: 0x950
    DLC_STATION_FLOW mDlcFlow;  // offset: 0x958
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x960
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x9f8
    stCategoryItem mCategoryItem[2];  // offset: 0xa20
    uGUIBase::cReferenceUIVlCursor mCategoryCursor;  // offset: 0xa40
    cGUIControlMgr mCategoryCtrlMgr;  // offset: 0xaf0
    f32 mCategoryCursorOffsetY;  // offset: 0xfa0
    uGUIBase::cScrollList mStationScrlList;  // offset: 0xfb0
    cStationListItem mStationListItem[50];  // offset: 0x1260
    s32 mStationItemNum;  // offset: 0x2cf0
    f32 mStationListOffsetY;  // offset: 0x2cf4
    cGUIObjMessage* mpNoListMessage;  // offset: 0x2cf8
    cGUIInstAnimation* mpStationScrollBar;  // offset: 0x2d00
    bool mIsGetStationItems;  // offset: 0x2d08
    uGUIBase::cScrollList mHistoryScrlList;  // offset: 0x2d10
    cHistoryListItem mHistoryListItem[50];  // offset: 0x2fc0
    s32 mHistoryItemNum;  // offset: 0x4730
    f32 mHistoryListHeaderH;  // offset: 0x4734
    f32 mHistoryListBaseY;  // offset: 0x4738
    f32 mHistoryListOffsetY;  // offset: 0x473c
    cGUIObjMessage* mpHistoryCaption;  // offset: 0x4740
    cGUIInstAnimation* mpHistoryScrollBar;  // offset: 0x4748
    bool mIsGetHistoryItems;  // offset: 0x4750
    uGUISystemMsg* mpGUIDialog;  // offset: 0x4758
    s32 mReqItemPos;  // offset: 0x4760
    cStationListInfo* mpReqItemInfo;  // offset: 0x4768
    MtString mAnnounceStr;  // offset: 0x4770
    MtString mSelectItemName;  // offset: 0x4778
public:
    static MyDTI DTI;
};
