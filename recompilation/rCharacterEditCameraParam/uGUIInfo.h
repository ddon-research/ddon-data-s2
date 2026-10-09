#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class sGUIExt;
class uGUIGameMenu;

// Declarations
class uGUIInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIInfo : public uGUIBase
{
    // inferred: sGUIExt::clearInfomation calls uGUIInfo::setFlowId
    friend class sGUIExt;
    // inferred: uGUIGameMenu::updateExit names uGUIInfo::mFlowId
    friend class uGUIGameMenu;
public:
    enum
    {
        INFO_RESULT_NONE = 0,
        INFO_RESULT_DECIDE = 1,
        INFO_RESULT_CANCEL = 2,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_ANNOUNCE = 1,
        FLOW_SINGLE = 2,
        FLOW_LIST = 3,
    };
    enum
    {
        ANNOUNCE_NONE = 0,
        ANNOUNCE_IN = 1,
        ANNOUNCE_WAIT = 2,
        ANNOUNCE_OUT = 3,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
    };
public:
    class MyDTI;
    struct stMain;
    class cListItem;
    struct stList;
    class cListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cListItem : public uGUIBase::cScrollListItemBase
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
        cListItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x58
        cGUIInstAnimation* mpInstAnim;  // offset: 0x60
        cGUIObjMessage* mpObjMsg;  // offset: 0x68
        static MyDTI DTI;
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
    public:
        u32 mFlag;  // offset: 0x28
        u32 mID;  // offset: 0x2c
        static MyDTI DTI;
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindow;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimBtn;  // offset: 0x10
        cGUIObjMessage* mpObjMsgBtn;  // offset: 0x18
        uGUIInfo::cListItem mAnnounce;  // offset: 0x20
        uGUIBase::cTextSlider mTextSlider;  // offset: 0x90
        u32 mFlag;  // offset: 0xd0
        static const s32 disp_frame = 150;
        static const s32 scroll_speed = 3;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstAnimation* mpInstAnimSmallIcon;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x8
        uGUIInfo::cListItem mListItem[8];  // offset: 0x10
        uGUIInfo::cListInfo mListInfo[52];  // offset: 0x390
        uGUIBase::cScrollList mListCtrl;  // offset: 0xd50
        u32 mFlag[52];  // offset: 0x1000
        u32 mID[52];  // offset: 0x10d0
        f32 mListBasePos;  // offset: 0x11a0
        s32 mListDist;  // offset: 0x11a4
        static const u32 LIST_MAX = 52;
        static const u32 list_num = 8;
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
    uGUIInfo();
    virtual ~uGUIInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void beginInfoWindow();
    void beginListWindow();
    void endInfoWindow();
    void hide();
    u32 getInfoResult();
    bool isTouchSingle();
    u32 getSelectedFlag();
    u32 getTopInfoFlag();
    u32 getSelectedID();
    u32 getTopInfoID();
    bool isAnyInfo();
    bool isOnlyOneInfo();
    void beginAnnounce(u32 flag, MT_CTSTR msg, MT_CTSTR pAnalyzerMsg0, MT_CTSTR pAnalyzerMsg1, bool isAnalyze);
    bool isEnableAnnounce();
    MtString& getMsg();
    static u32 setFlagList(stList* pList);
private:
    void updateMove();
    void updateExit();
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void initAnnounce();
    void updateAnnounce();
    void checkListUpdate();
    void createList();
    void createFlagList();
    void initSingle();
    void setupListMessage(cGUIObjMessage* pObj, u32 flag, u32 id);
    void initList();
    void adjustListCursor();
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    u32 getFlag(u32 index);
    u32 getID(u32 index);
    void setupBtnGuide();
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message*);
    u32 evCtrlMouse(cControl::Message* msg);
    MT_CTSTR getInfoMsg(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mInfoResult;  // offset: 0x8d0
    u32 mFlowId;  // offset: 0x8d4
    u32 mSubFlowId;  // offset: 0x8d8
    stMain mMain;  // offset: 0x8e0
    stList mList;  // offset: 0x9c0
    cControl* mpButtonCtrl;  // offset: 0x1b70
    cControl* mpMouseCtrl;  // offset: 0x1b78
    f32 mScrollCounter;  // offset: 0x1b80
    uGUIBase::cCalcMovePos mSlideCtrl;  // offset: 0x1b88
    MtString mMsg;  // offset: 0x1ba8
    MtString mAnalyzerMsg[2];  // offset: 0x1bb0
    bool mIsAnalyzeAnnounce;  // offset: 0x1bc0
    MtStringEx<128> mTempStr;  // offset: 0x1bc4
    bool mIsTouchSingle;  // offset: 0x1c48
    uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0x1c4c
public:
    static MyDTI DTI;
};
