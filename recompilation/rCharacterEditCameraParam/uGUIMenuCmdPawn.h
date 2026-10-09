#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObject;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIMenuCmdPawn;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMenuCmdPawn : public uGUIBase
{
public:
    enum
    {
        FLOWSUB_CTGR = 0,
        FLOWSUB_MSG = 1,
        FLOWSUB_NUM = 2,
    };
    enum
    {
        INPUTEVENT_MSG_CANCEL = 66,
        INPUTEVENT_MSG_DECIDE = 67,
        INPUTEVENT_END = 68,
        INPUTEVENT_CTGR_MOVE = 69,
        INPUTEVENT_CTGR_DECIDE = 70,
        INPUTEVENT_CTGR_SUBMENU = 71,
        INPUTEVENT_CTGR_CLICK = 72,
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
    uGUIMenuCmdPawn();
    virtual ~uGUIMenuCmdPawn();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
private:
    void updateInit();
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void evEnd();  // vtable slot 48
    void evDecide();
    void evCancel();
    void evCtgrMove();
    void evCtgrDecide();
    void evCtgrSubMenu();
    u32 evCtrlEnd(cControl::Message* msg);
    u32 evCtrlVLCtgrMove(cControl::Message* msg);
    u32 evCtrlVLCtgrDecide(cControl::Message* msg);
    u32 evCtrlVLCtgrSubMenu(cControl::Message* msg);
    u32 evCtrlVLCtgrMouseDecide(cControl::Message* msg);
    u32 evCtrlVLCtgrMouseSelect(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    void updateDisp();
    void initScrollList();
    void updateScrollList();
    void updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void setScrollPos();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGUIMsgGuide;  // offset: 0x8d0
    cGUIInstance* mpInstListParent;  // offset: 0x8d8
    cGUIInstance* mpInstList[12];  // offset: 0x8e0
    cGUIInstance* mpInstListAnm[12];  // offset: 0x940
    cGUIInstance* mpInstListMsgParent;  // offset: 0x9a0
    cGUIInstance* mpInstListMsg[15];  // offset: 0x9a8
    cGUIInstance* mpInstListMsgAnm[15];  // offset: 0xa20
    uGUIBase::cReferenceUIIconSCM mIconSCM[15];  // offset: 0xa98
    cGUIInstance* mpInstNullCtgrEdit;  // offset: 0xf48
    cGUIInstance* mpInstCtgrEditWndwFrm;  // offset: 0xf50
    cGUIInstance* mpInstNullMsgEdit;  // offset: 0xf58
    cGUIInstance* mpInstMsgEditWndwFrm;  // offset: 0xf60
    cGUIObject* mpObjMsgInfoCtgr00;  // offset: 0xf68
    cGUIObject* mpObjMsgInfoCtgr01;  // offset: 0xf70
    cGUIObject* mpObjMsgList[12];  // offset: 0xf78
    cGUIObjMessage* mpObjMsgListMsg00[15];  // offset: 0xfd8
    cGUIObjMessage* mpObjMsgListMsg01[15];  // offset: 0x1050
    cGUIObjMessage* mpObjMsgListMsg02[15];  // offset: 0x10c8
    uGUIBase::cReferenceUIIconComm mIconComm[15];  // offset: 0x1140
    cGUIObject* mpObjMsgCtgrEditHeader;  // offset: 0x15f0
    cGUIObject* mpObjMsgMsgEditHeader;  // offset: 0x15f8
    cGUIObject* mpObjMsgMsgEditTitle00;  // offset: 0x1600
    cGUIObject* mpObjMsgMsgEditTitle01;  // offset: 0x1608
    uGUIBase::cReferenceUIVlCursor mCsrCtgr;  // offset: 0x1610
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x16c0
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x1718
    uGUIBase::cMaskScroll mMsgMaskScr;  // offset: 0x17b0
    uGUIBase::cVerticalList* mpCtrlVLCtgr;  // offset: 0x17e8
    cControl* mpCtrl;  // offset: 0x17f0
    u32 mFlowSubNext;  // offset: 0x17f8
    u32 mFlowSubOld;  // offset: 0x17fc
    f32 mMsgListMaskW;  // offset: 0x1800
    bool mIsSCCEditOld;  // offset: 0x1804
    uGUIBase::cScrollList mScrollList;  // offset: 0x1810
    uGUIBase::cScrollListItemBase mScrollDispList[15];  // offset: 0x1ac0
public:
    static MyDTI DTI;
    static const u32 CATEGORYVISIBLE_NUM = 12;
    static const u32 MSGLIST_MAX = 13;
    static const u32 MSGLISTVISIBLE_NUM = 15;
    static const u32 BTNGUIDE_NUM = 4;
};
