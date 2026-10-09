#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/sCaplinkManager.h"
#include "../shared/uGUIBase.h"
#include "uGUICaplinkMenuBase.h"
#include "uGUICaplinkProfile.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cCaplinkProfIconLoader;
class cControl;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstScissorMask;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class uGUICaplinkTalk;

// Declarations
class uGUICaplinkChat;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkChat : public uGUICaplinkMenuBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_INIT = 1,
        FLOW_REQ_SEND = 2,
        FLOW_UPDATE = 3,
        FLOW_LIST = 4,
        FLOW_INPUT = 5,
        FLOW_SUB_MENU = 6,
        FLOW_MEMBER_LIST = 7,
        FLOW_LEAVE = 8,
        FLOW_RENAME = 9,
        FLOW_RESIGN = 10,
        FLOW_DELETE = 11,
        FLOW_REQ_READ = 12,
        FLOW_END = 13,
    };
    enum
    {
        SELECT_INPUT_FORM = 0,
        SELECT_MENU = 1,
        SELECT_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_FORM_DECIDE = 68,
        INPUTEVENT_FORM_CANCEL = 69,
        INPUTEVENT_CLOSE = 70,
        INPUTEVENT_MENU = 71,
        INPUTEVENT_REQUEST_UP = 72,
        INPUTEVENT_REQUEST_DOWN = 73,
        INPUTEVENT_ADJUST_CURSOR = 74,
    };
    enum
    {
        ITEM_TYPE_DATE = 0,
        ITEM_TYPE_SYSTEM = 1,
        ITEM_TYPE_MESSAGE = 2,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stList;
    class cDateItem;
    class cSystemItem;
    class cMessageItem;
    class cDateInfo;
    class cSystemInfo;
    class cMessageInfo;
public:
    using cDate = sCaplinkManager::cDate;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_talk_y;  // offset: 0x0
        s32 mParam_default_size_y;  // offset: 0x4
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNullSubMenu;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimForm;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimMenu;  // offset: 0x10
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x18
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x20
        cGUIObjMessage* mpObjMsgGroupName;  // offset: 0x28
        cGUIObjMessage* mpObjMsgOwnerName;  // offset: 0x30
        cGUIObjMessage* mpObjMsgInput;  // offset: 0x38
        cGUIObjMessage* mpObjMsgInputMode;  // offset: 0x40
        cGUIObjNull* mpObjNullInputMode;  // offset: 0x48
        cGUIObjNull* mpObjNullInputPointer;  // offset: 0x50
        cGUIObjNull* mpObjNullMenuPointer;  // offset: 0x58
        cGUIObjNull* mpObjNullPointer;  // offset: 0x60
        cGUIObjPolygon* mpObjPolyInputCollision;  // offset: 0x68
        cGUIObjPolygon* mpObjPolyMenuCollision;  // offset: 0x70
        cGUIObjPolygon* mpObjPolyInputMask;  // offset: 0x78
        cGUIObjTexture* mpObjTexInputMode;  // offset: 0x80
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x88
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0xe0
    };
public:
    class cDateItem : public uGUIBase::cScrollListItemBase
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
        cDateItem();
    public:
        cGUIObjMessage* mpObjMsgDate;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    class cSystemItem : public uGUIBase::cScrollListItemBase
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
        cSystemItem();
    public:
        cGUIObjMessage* mpObjMsgName;  // offset: 0x58
        cGUIObjMessage* mpObjMsgTime;  // offset: 0x60
        cGUIObjMessage* mpObjMsgText;  // offset: 0x68
        cGUIObjPolygon* mpObjPolyBase;  // offset: 0x70
        static MyDTI DTI;
    };
public:
    class cMessageItem : public uGUIBase::cScrollListItemBase
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
        cMessageItem();
    public:
        cGUIObjMessage* mpObjMsgName;  // offset: 0x58
        cGUIObjMessage* mpObjMsgTime;  // offset: 0x60
        cGUIObjMessage* mpObjMsgText;  // offset: 0x68
        cCaplinkProfIconLoader mProfIcon;  // offset: 0x70
        uGUIBase::cReferenceUIIconFriend mIcon;  // offset: 0x90
        static MyDTI DTI;
    };
public:
    class cDateInfo : public uGUIBase::cScrollListInfoBase
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
        cDateInfo();
    public:
        uGUICaplinkChat::cDate mDate;  // offset: 0x26
        static MyDTI DTI;
    };
public:
    class cSystemInfo : public uGUIBase::cScrollListInfoBase
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
        cSystemInfo();
    public:
        MtString mMessage;  // offset: 0x28
        uGUICaplinkChat::cDate mDate;  // offset: 0x30
        s32 mChatId;  // offset: 0x38
        static MyDTI DTI;
    };
public:
    class cMessageInfo : public uGUIBase::cScrollListInfoBase
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
        cMessageInfo();
    public:
        MtString mMessage;  // offset: 0x28
        uGUICaplinkChat::cDate mDate;  // offset: 0x30
        s32 mChatId;  // offset: 0x38
        u32 mUserIndex;  // offset: 0x3c
        u32 mIconIndex;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstNull* mpInstNullUnread;  // offset: 0x0
        cGUIObjMessage* mpObjMsgUnread;  // offset: 0x8
        cGUIInstScissorMask* mpInstScissorMask;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimLoading;  // offset: 0x18
        uGUIBase::cScrollList mListCtrl;  // offset: 0x20
        uGUICaplinkChat::cDateItem mDate[8];  // offset: 0x2d0
        uGUICaplinkChat::cSystemItem mSystem[10];  // offset: 0x5d0
        uGUICaplinkChat::cMessageItem mMessage[10];  // offset: 0xa80
        static const u32 date_num = 8;
        static const u32 system_num = 10;
        static const u32 message_num = 10;
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
    uGUICaplinkChat();
    virtual ~uGUICaplinkChat();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setData(s32 idType, MT_CTSTR id);
private:
    void setFlowId(u32 flow_id, bool isInit);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupList(bool isAutoScroll);
    s32 calcHeight(cGUIObjMessage* pObj, MT_CTSTR pMsg);
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void setupTimeMessage(cGUIObjMessage* pObj, const cDate& date);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void adjustList();
    void adjustCursor();
    void updateList();
    void setupInput();
    void updateInput();
    void initChatSubMenu();
    void updateChatSubMenu();
    void initMemberList();
    void updateMemberList();
    MT_CTSTR getGroupName();
    void eventDecide();
    void eventCancel();
    void eventFormDecide();
    void eventFormCancel();
    void eventClose();
    void eventMenu();
    void eventRequest(bool isUp);
    void eventAdjustList();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlFormDecide(cControl::Message* msg);
    u32 evCtrlFormCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlMenu(cControl::Message* msg);
    u32 evCtrlRequest(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x978
    u32 mFlowId;  // offset: 0x980
    s32 mIdType;  // offset: 0x984
    MtStringEx<33> mId;  // offset: 0x988
    MtString mMessage;  // offset: 0x9b0
    bool mIsInputEnable;  // offset: 0x9b8
    bool mIsOpenPad;  // offset: 0x9b9
    bool mIsReqForward;  // offset: 0x9ba
    s32 mTopChatId;  // offset: 0x9bc
    s32 mBottomChatId;  // offset: 0x9c0
    s32 mBeginChatId;  // offset: 0x9c4
    stVariable mVar;  // offset: 0x9c8
    stMain mMain;  // offset: 0x9d0
    stList mList;  // offset: 0xb50
    cControl* mpDecideCtrl;  // offset: 0x1e90
    cControl* mpCancelCtrl;  // offset: 0x1e98
    cControl* mpFormCtrl;  // offset: 0x1ea0
    uGUIBase::cHorizontalList* mpMenuCtrl;  // offset: 0x1ea8
    cControl* mpRequestCtrl;  // offset: 0x1eb0
    uGUICaplinkTalk* mpGUICaplinkTalk;  // offset: 0x1eb8
public:
    static MyDTI DTI;
};
