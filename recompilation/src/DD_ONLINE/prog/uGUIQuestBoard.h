#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "nGUIExt.h"
#include "uGUIBase.h"
#include "uGUIQuestBoardBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
namespace nQuest { class cGUIBoardData; }
class uGUIQuestInfo;
class uGUISystemMsg;

// Declarations
class uGUIQuestBoard;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIQuestBoard : public uGUIQuestBoardBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_LIST_INIT = 1,
        FLOW_LIST = 2,
        FLOW_ORDER_WAIT = 3,
        FLOW_GP_COMPLETE_WAIT = 4,
        FLOW_INFO = 5,
        FLOW_DIALOG = 6,
        FLOW_ONLINE_SHOP = 7,
        FLOW_END = 8,
    };
    enum QB_GUIDE_BIT
    {
        QB_DECIDE = 1,
        QB_ORDER = 2,
        QB_BIT_MAX = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_SHORTCUT = 68,
        INPUTEVENT_ADJUST_CURSOR = 69,
        INPUTEVENT_ADJUST_TAB = 70,
        INPUTEVENT_GP_DECIDE = 71,
        INPUTEVENT_GP_NOT_SELECT = 72,
        INPUTEVENT_GP_UP = 73,
        INPUTEVENT_GP_DOWN = 74,
    };
public:
    class MyDTI;
    class cListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cListInfo : public uGUIBase::cScrollListInfoBase
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
        cListInfo();
        virtual ~cListInfo();
    public:
        nQuest::cGUIBoardData* mpData;  // offset: 0x28
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
    uGUIQuestBoard();
    virtual ~uGUIQuestBoard();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void setInfoFlow();  // vtable slot 91
private:
    void setFlowId(u32 flow_id);
    void setupWindowActive();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    virtual void updateExit();  // vtable slot 92
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setListSequence(uGUIQuestBoardBase::cListItem* pItem, nQuest::cGUIBoardData* pData, u32 index);
    void updateInit();
    bool isQuestListUpdate();
    void createList();
    bool checkQuestType(u32 scheduleId, u32 type);
    void setupList();
    void setupDetail();
    nQuest::cGUIBoardData* getIndexData();
    void adjustListCursor();
    void adjustTab();
    void decideList();
    void shortcut();
    void updateOrderWait();
    void setupInfo();
    void updateInfo();
    void initGpComplete();
    void setupGpComplete();
    bool isActiveGpComplete();
    void checkEnableFocusGpComplate(u32 inputevent);
    void checkDisableFocusGpComplate(u32 inputevent);
    void enableGpComplete();
    void disableGpComplete();
    void updateDialog();
    void updateOnlineShop();
    void updateGpCompleteWait();
    void eventDecide();
    void eventCancel();
    void eventClose();
    void eventShortCut();
    void eventAdjustCursor();
    void eventAdjustTab();
    void eventGpCompleteDecide();
    void eventGpCompleteNotSelect();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlShortCut(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    bool evCtrlScrl(cControl::Message* msg);
    u32 evCtrlGpCompleteDecide(cControl::Message* msg);
    u32 evCtrlGpCompleteUp(cControl::Message* msg);
    u32 evCtrlGpCompleteDown(cControl::Message* msg);
public:
    void setMode(nGUIExt::QUEST_DISP_MODE mode);
    bool isModeQuestBoard() const;
    bool isModeClanMission() const;
private:
    u32 mFlowId;  // offset: 0x1f74
    bool mIsOrderQuest;  // offset: 0x1f78
    f32 mItemCursorOffset;  // offset: 0x1f7c
    cControl* mpDecideCtrl;  // offset: 0x1f80
    cControl* mpCancelCtrl;  // offset: 0x1f88
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x1f90
    cControl* mpGpCompleteCtrl;  // offset: 0x1f98
    uGUIQuestInfo* mpGUIQuestInfo;  // offset: 0x1fa0
    uGUISystemMsg* mpConfirmDialog;  // offset: 0x1fa8
    uGUISystemMsg* mpGpDialog;  // offset: 0x1fb0
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x1fb8
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[2];  // offset: 0x2050
    bool mIsTutorialQuestClear;  // offset: 0x20a0
    bool mIsGpComplete;  // offset: 0x20a1
    u32 mCompleteGp;  // offset: 0x20a4
    bool mIsFocusGpComplete;  // offset: 0x20a8
    bool mIsListEmpty;  // offset: 0x20a9
    u32 mMode;  // offset: 0x20ac
public:
    static MyDTI DTI;
};

inline void* uGUIQuestBoard::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIQuestBoard::cListInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
