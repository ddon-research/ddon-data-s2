#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
#include "uGUIQuestBoardBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cControl;
class rGUIMessage;

// Declarations
class uGUIContentsBoard;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIContentsBoard : public uGUIQuestBoardBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_LIST_INIT = 1,
        FLOW_LIST = 2,
        FLOW_INFO = 3,
        FLOW_END = 4,
    };
    enum CB_GUIDE_BIT
    {
        CB_DECIDE = 1,
        CB_NEWSP = 2,
        CB_BIT_MAX = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CHKOUT = 68,
        INPUTEVENT_ADJUST_CURSOR = 69,
    };
public:
    class MyDTI;
    class cListItemInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cListItemInfo : public uGUIBase::cScrollListInfoBase
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
        cListItemInfo();
    public:
        u32 mLv;  // offset: 0x28
        u32 mScheduleId;  // offset: 0x2c
        u32 mQuestId;  // offset: 0x30
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
    uGUIContentsBoard();
    virtual ~uGUIContentsBoard();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    u32 isInput();
    bool isDecide();
    bool isDecideMouse();
    bool isCancel();
    bool isCallNews();
    void clearCallNews();
    void cancelMissionInfo();
    u32 getQuestID();
    u32 getScheduleID();
    void getMissionInfoPos(MtVector3& pos);
    void setExecuteCtrl(bool flag);
    void setSetupMissionInfo(bool flag);
    void setFromNewspPaper(bool flg);
    void outsideDecide();
private:
    void setFlowId(u32 flow_id);
    void setFlowIdNext(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateInit();
    void updateMove();
    virtual void updateExit();  // vtable slot 92
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void createList();
    void setupList();
    void adjustListCursor();
    void decideList();
    void setupInfo();
    void enableChangeBtn();
    bool isExitContentBoard();
    void eventDecide(bool isMouse);
    void eventCancel();
    void eventClose();
    void eventChkout();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlMouse(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlChkout(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message*);
    void setCtrlFocus(cControl* pCtrl, bool isFocus);
    s32 getCtrlPos(cControl*);
    MT_CTSTR getGMDMsg(u32 id);
private:
    rGUIMessage* mpGMDRes;  // offset: 0x1f78
    cControl* mpDecideCtrl;  // offset: 0x1f80
    cControl* mpCancelCtrl;  // offset: 0x1f88
    cControl* mpChkoutCtrl;  // offset: 0x1f90
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x1f98
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[2];  // offset: 0x2030
    MtVector3 mMissionInfoPos;  // offset: 0x2080
    u32 mFlowId;  // offset: 0x2090
    u32 mFlowIdNext;  // offset: 0x2094
    bool mbCallNews;  // offset: 0x2098
    bool mIsDecide;  // offset: 0x2099
    bool mIsDecideMouse;  // offset: 0x209a
    bool mIsCancel;  // offset: 0x209b
    bool mIsExecuteCtrl;  // offset: 0x209c
    bool mIsSetupMissionInfo;  // offset: 0x209d
    bool mIsFromNewspPaper;  // offset: 0x209e
public:
    static MyDTI DTI;
};
