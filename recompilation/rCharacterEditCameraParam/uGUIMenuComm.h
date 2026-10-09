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
class rTblMenuComm;

// Declarations
class uGUIMenuComm;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMenuComm : public uGUIBase
{
public:
    enum
    {
        FLOW_MYPHRASE = 0,
        FLOW_TMPPHRASE = 1,
        FLOW_EMOTION = 2,
        FLOW_NUM = 3,
    };
    enum
    {
        FLOWSUB_CTGR = 0,
        FLOWSUB_MSG = 1,
        FLOWSUB_CTGR_EDIT = 2,
        FLOWSUB_CTGR_EDIT_INPUT = 3,
        FLOWSUB_MSG_EDIT = 4,
        FLOWSUB_MSG_EDIT_INPUT = 5,
        FLOWSUB_MSG_EDIT_PD00 = 6,
        FLOWSUB_MSG_EDIT_PD01 = 7,
        FLOWSUB_NUM = 8,
    };
    enum
    {
        MSG_EDIT_MSG = 0,
        MSG_EDIT_EMOTCTGR = 1,
        MSG_EDIT_EMOTMSG = 2,
        MSG_EDIT_FINISH = 3,
        MSG_EDIT_MAX = 4,
        MSG_EDIT_CHAT_DISP = 5,
    };
    enum
    {
        INPUTEVENT_TAB_MOVE = 66,
        INPUTEVENT_END = 67,
        INPUTEVENT_CTGR_DECIDE = 68,
        INPUTEVENT_CTGR_SUBMENU = 69,
        INPUTEVENT_CTGR_MOVE = 70,
        INPUTEVENT_CTGR_CLICK = 71,
        INPUTEVENT_MSG_CANCEL = 72,
        INPUTEVENT_MSG_DECIDE = 73,
        INPUTEVENT_MSG_SUBMENU = 74,
        INPUTEVENT_MSG_MOVE = 75,
        INPUTEVENT_EDIT_CANCEL = 76,
        INPUTEVENT_EDIT_DECIDE = 77,
        INPUTEVENT_EDIT_MOVE = 78,
    };
public:
    class MyDTI;
    struct stEditWork;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stEditWork
    {
    public:
        MT_CHAR mMsg[256];  // offset: 0x0
        u32 mPosCtgr;  // offset: 0x100
        u32 mPosMsg;  // offset: 0x104
        bool mCheck;  // offset: 0x108
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
    uGUIMenuComm();
    virtual ~uGUIMenuComm();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setVarFlow(u32 uValue);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateWaitMyPhrase();
    void updateWaitTmpPhrase();
    void updateWaitEmotion();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void evEnd();  // vtable slot 48
    void evTabMove();
    void evCtgrMove();
    void evCtgrDecide();
    void evCtgrSubMenu();
    void evMsgCancel();
    void evMsgDecide();
    void evMsgSubMenu();
    void evMsgReqEmotion();
    void evEditMove();
    void evEditCancel();
    void evEditDecide();
    void evEditBtnDecide();
    u32 evCtrlEnd(cControl::Message* msg);
    u32 evCtrlHLTabMove(cControl::Message* msg);
    u32 evCtrlVLCtgrMove(cControl::Message* msg);
    u32 evCtrlVLCtgrDecide(cControl::Message* msg);
    u32 evCtrlVLCtgrMouseDecide(cControl::Message* msg);
    u32 evCtrlVLCtgrMouseSelect(cControl::Message* msg);
    u32 evCtrlVLCtgrSubMenu(cControl::Message* msg);
    u32 evCtrlMsgCancel(cControl::Message* msg);
    u32 evCtrlMsgDecide(cControl::Message* msg);
    u32 evCtrlMsgSubMenu(cControl::Message* msg);
    u32 evCtrlVLMsgReqEmotion(cControl::Message* msg);
    u32 evCtrlVLEditMove(cControl::Message* msg);
    u32 evCtrlVLEditCancel(cControl::Message* msg);
    u32 evCtrlVLEditDecide(cControl::Message* msg);
    u32 evCtrlVLEditLClick(cControl::Message* msg);
    u32 evCtrlHLEditMove(cControl::Message* msg);
    void reqEmotion(u32 uNo, bool bEmotToChat);
    void updateCtgrList();
    void updateMsgList();
    void updateDisp();
    void initScrollList();
    void updateScrollList(u32 listNum);
    void updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void setScrollPos();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGUIMsgGuide;  // offset: 0x8d0
    rTblMenuComm* mpTblMenuCommTmpMessage;  // offset: 0x8d8
    rTblMenuComm* mpTblMenuCommEmotion;  // offset: 0x8e0
    cGUIInstance* mpInstListParent;  // offset: 0x8e8
    cGUIInstance* mpInstList[12];  // offset: 0x8f0
    cGUIInstance* mpInstListAnm[12];  // offset: 0x950
    uGUIBase::cReferenceUIIconSCM mIconSCM[15];  // offset: 0x9b0
    cGUIInstance* mpInstListMsgParent;  // offset: 0xe60
    cGUIInstance* mpInstListMsg[15];  // offset: 0xe68
    cGUIInstance* mpInstListMsgAnm[15];  // offset: 0xee0
    cGUIInstance* mpInstNullCtgrEdit;  // offset: 0xf58
    cGUIInstance* mpInstCtgrEditWndwFrm;  // offset: 0xf60
    cGUIInstance* mpInstNullMsgEdit;  // offset: 0xf68
    cGUIInstance* mpInstMsgEditWndwFrm;  // offset: 0xf70
    cGUIInstance* mpInstNullPopCmd;  // offset: 0xf78
    cGUIObject* mpObjMsgInfoCtgr00;  // offset: 0xf80
    cGUIObject* mpObjMsgInfoCtgr01;  // offset: 0xf88
    cGUIObject* mpObjMsgList[12];  // offset: 0xf90
    cGUIObjMessage* mpObjMsgListMsg00[15];  // offset: 0xff0
    cGUIObjMessage* mpObjMsgListMsg01[15];  // offset: 0x1068
    cGUIObjMessage* mpObjMsgListMsg02[15];  // offset: 0x10e0
    uGUIBase::cReferenceUIIconComm mIconComm00[15];  // offset: 0x1158
    uGUIBase::cReferenceUIIconComm mIconComm01[15];  // offset: 0x1608
    cGUIObject* mpObjMsgCtgrEditHeader;  // offset: 0x1ab8
    cGUIObject* mpObjMsgMsgEditHeader;  // offset: 0x1ac0
    cGUIObject* mpObjMsgMsgEditTitle00;  // offset: 0x1ac8
    cGUIObject* mpObjMsgMsgEditTitle01;  // offset: 0x1ad0
    uGUIBase::cReferenceUIIconComm mIconCommEdit00;  // offset: 0x1ad8
    uGUIBase::cReferenceUIIconComm mIconCommEdit01;  // offset: 0x1b28
    uGUIBase::cReferenceUIVlCursor mCsrCtgr;  // offset: 0x1b80
    uGUIBase::cReferenceUITab mTab;  // offset: 0x1c30
    uGUIBase::cReferenceUIScrollBar mScrollBar;  // offset: 0x1ce0
    uGUIBase::cReferenceUITextBox mTextBoxEditCtgr;  // offset: 0x1d88
    uGUIBase::cReferenceUITextBox mTextBoxEditMsg;  // offset: 0x1ef0
    uGUIBase::cReferenceUIButton mBtnEditCtgr00;  // offset: 0x2058
    uGUIBase::cReferenceUIButton mBtnEditCtgr01;  // offset: 0x21e8
    uGUIBase::cReferenceUIButton mBtnEditMsg00;  // offset: 0x2378
    uGUIBase::cReferenceUIButton mBtnEditMsg01;  // offset: 0x2508
    uGUIBase::cReferenceUIPullDown mPullDownEmotCtgr;  // offset: 0x26a0
    uGUIBase::cReferenceUIPullDown mPullDownEmot;  // offset: 0x2cb0
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x32c0
    uGUIBase::cReferenceUICloseBtn mCloseBtnCtgrWndw;  // offset: 0x3318
    uGUIBase::cReferenceUICloseBtn mCloseBtnMsgWndw;  // offset: 0x3370
    uGUIBase::cReferenceUIWndwDrag mDragBarCtgrWndw;  // offset: 0x33d0
    uGUIBase::cReferenceUIWndwDrag mDragBarMsgWndw;  // offset: 0x3450
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x34d0
    uGUIBase::cMaskScroll mMsgMaskScr;  // offset: 0x3568
    uGUIBase::cHorizontalList* mpCtrlHLTab;  // offset: 0x35a0
    uGUIBase::cVerticalList* mpCtrlVLCtgr;  // offset: 0x35a8
    cControl* mpCtrlMsg;  // offset: 0x35b0
    uGUIBase::cVerticalList* mpCtrlVLEdit;  // offset: 0x35b8
    uGUIBase::cHorizontalList* mpCtrlHLEdit;  // offset: 0x35c0
    u32 mVarFlow;  // offset: 0x35c8
    u32 mFlowSubNext;  // offset: 0x35cc
    u32 mFlowSubOld;  // offset: 0x35d0
    f32 mMsgListMaskW;  // offset: 0x35d4
    bool mIsSCCEditOld;  // offset: 0x35d8
    bool mIsChangeMessageSet;  // offset: 0x35d9
    uGUIBase::cScrollList mScrollList;  // offset: 0x35e0
    uGUIBase::cScrollListItemBase mScrollDispList[15];  // offset: 0x3890
    stEditWork mEditCtgr;  // offset: 0x3db8
    stEditWork mEditMsg;  // offset: 0x3ec4
public:
    static MyDTI DTI;
    static const u32 CATEGORYVISIBLE_NUM = 12;
    static const u32 MSGLIST_MAX = 13;
    static const u32 MSGLISTVISIBLE_NUM = 15;
    static const u32 BTNGUIDE_NUM = 4;
    static const u32 MSG_CTGR_MAX = 10;
    static const u32 MSG_LENGTH_MAX = 22;
};
