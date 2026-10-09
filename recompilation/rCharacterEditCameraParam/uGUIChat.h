#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/nDDOUtility.h"
#include "sChat.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtRectF;
class MtSize;
class MtSizeF;
class MtString;
class cControl;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
namespace nInputTextKeyboardHook { struct Keycode; }
class rGUI;
class sGUIExt;
class uGUICommunityList;

// Declarations
class uGUIChat;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIChat : public uGUIBase
{
    // inferred: sGUIExt::setChatForbid names uGUIChat::mIsForbid
    friend class sGUIExt;
public:
    enum GMD_ID
    {
        GMD_ID_DEFAULT = 0,
        GMD_ID_FILTER_NAME = 1,
    };
    enum
    {
        UPDF_NONE = 0,
        UPDF_LOG_RESET = 1,
        UPDF_LOG_RESIZE = 2,
        UPDF_LOG_ADD = 4,
        UPDF_FILTER = 8,
        UPDF_FORM = 16,
        UPDF_LOG = 7,
        UPDF_ALL = 31,
    };
    enum
    {
        TELL_RNO_COMMUNITY_OPEN_WAIT = 0,
        TELL_RNO_MOVE = 1,
    };
    enum
    {
        REQNACT_NONE = 0,
        REQNACT_DISPON = 1,
        REQNACT_DISPOFF = 2,
    };
    enum
    {
        MENU_IF_LOG = 0,
        MENU_IF_ADDRESS = 1,
        MENU_IF_INPUT = 2,
        MENU_IF_FILTER = 3,
        MENU_IF_MAX = 4,
    };
    enum
    {
        RNO_CHADD_INIT = 0,
        RNO_CHADD_SETNAME = 1,
        RNO_CHADD_SETNAMEWAIT = 2,
        RNO_CHADD_SETFILTER = 3,
    };
    enum
    {
        INPUTEVENT_START_DISABLE = 66,
        INPUTEVENT_START_ENABLE = 67,
        INPUTEVENT_MENU_MOVE = 68,
        INPUTEVENT_MENU_MOVE_SEND_REQ = 69,
        INPUTEVENT_MENU_DECIDE = 70,
        INPUTEVENT_MENU_CANCEL = 71,
        INPUTEVENT_MENU_TOP_BTN = 72,
        INPUTEVENT_MENU_CHANGE_WINDOW_SIZE = 73,
        INPUTEVENT_MENU_TO_LOG = 74,
        INPUTEVENT_MENU_SPECIAL_KEY_MOVE_ADDRESS = 75,
        INPUTEVENT_FILTER_MOVE = 76,
        INPUTEVENT_FILTER_DECIDE = 77,
        INPUTEVENT_LOG_MOVE = 78,
        INPUTEVENT_LOG_CANCEL = 79,
        INPUTEVENT_LOG_DECIDE = 80,
        INPUTEVENT_ADD_CHANNEL_VL_MOVE = 81,
        INPUTEVENT_ADD_CHANNEL_VL_CANCEL = 82,
        INPUTEVENT_ADD_CHANNEL_VL_DECIDE = 83,
        INPUTEVENT_YN_MOVE = 84,
        INPUTEVENT_ADDRESS_MOVE = 85,
        INPUTEVENT_ADDRESS_CANCEL = 86,
        INPUTEVENT_ADDRESS_DECIDE = 87,
        INPUTEVENT_FILTER_SUB_CMD_MOVE = 88,
        INPUTEVENT_FILTER_SUB_CMD_CANCEL = 89,
        INPUTEVENT_FILTER_SUB_CMD_DECIDE = 90,
        INPUTEVENT_YN_DEL_MOVE = 91,
        INPUTEVENT_YN_DEL_DECIDE = 92,
        INPUTEVENT_YN_DEL_CANCEL = 93,
        INPUTEVENT_FORM_DECIDE = 94,
        INPUTEVENT_FORM_CANCEL = 95,
    };
    enum
    {
        BGID_NONE = 0,
        BGID_VIEWLOG = 1,
        BGID_MENU = 2,
        BGID_INPUT = 3,
        BGID_MAX = 4,
    };
public:
    class MyDTI;
    class cWindow;
    class cPopWndwChSubCmd;
    class cPopWndwAddress;
    class cPopWndwYoN;
    class cPopWndwAddCh;
    class cCheckList;
    struct stChatLogWork;
    struct LogSubMenuParam;
    class cLogItem;
    struct LogCursorInfo;
    class cLogInfo;
    class cLogInfoStack;
    class cLogList;
public:
    using cRecordString = MtStringEx<256>;
    using LogItems = nDDOUtility::cArray<uGUIChat::cLogItem, 29>;
    using LogInfos = nDDOUtility::cArray<uGUIChat::cLogInfo, 300>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cWindow : public MtObject
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
        cWindow();
        // Address: 0x01aed140 - 0x01aed141 (1 bytes)
        virtual ~cWindow() {}
        void setup(uGUIChat* pParentGUI);
        void setWindowSizeH(bool isLarge, bool isLogMode);
        f32 getWindowSizeH() const;
        f32 getWindowSizeH(bool isLarge) const;
        void addMouseTouchList(cControl* pCtrl, s32 pos);
        void orMouseTouchListFlg(cControl* pCtrl, u32 uFlag);
        void clearMouseTouchListFlg(cControl* pCtrl, u32 uFlag);
    private:
        uGUIChat* mpParentGUI;  // offset: 0x8
        cGUIInstance* mpInstWndw;  // offset: 0x10
        cGUIObjTexture* mpObjWndwL;  // offset: 0x18
        cGUIObjTexture* mpObjWndwC;  // offset: 0x20
        cGUIObjTexture* mpObjWndwR;  // offset: 0x28
        cGUIObjTexture* mpObjWndwLT;  // offset: 0x30
        cGUIObjTexture* mpObjWndwCT;  // offset: 0x38
        cGUIObjTexture* mpObjWndwRT;  // offset: 0x40
        cGUIObjPolygon* mpOBJ_window00_mouseover;  // offset: 0x48
        cGUIInstance* mpInstMask;  // offset: 0x50
        cGUIObjPolygon* mpObjMaskT;  // offset: 0x58
        cGUIObjPolygon* mpObjMaskC;  // offset: 0x60
        f32 mDefaultWindowHeightCenter;  // offset: 0x68
        f32 mDefaultWindowHeightTop;  // offset: 0x6c
        f32 mDefaultMaskHeightCenter;  // offset: 0x70
        f32 mDefaultMaskHeightTop;  // offset: 0x74
        f32 mLargeWindowHeightCenter;  // offset: 0x78
        f32 mLargeWindowHeightTop;  // offset: 0x7c
        f32 mLargeMaskHeightCenter;  // offset: 0x80
        f32 mLargeMaskHeightTop;  // offset: 0x84
        u32 mMouseTouchListIndex;  // offset: 0x88
        bool mIsLarge;  // offset: 0x8c
    public:
        static MyDTI DTI;
        static const u32 DIST_SIZE = 11;
    };
public:
    class cPopWndwChSubCmd : public MtObject
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
        cPopWndwChSubCmd();
        // Address: 0x01aed130 - 0x01aed131 (1 bytes)
        virtual ~cPopWndwChSubCmd() {}
        void setVisible(bool bVisible);
        void setup();
        void addList(MT_CTSTR pMsg);
        void clearList();
        void adjustWindow();
        void update();
    public:
        uGUIChat* mpParentGUI;  // offset: 0x8
        cGUIInstNull* mpInstNull;  // offset: 0x10
        cGUIInstAnimation* mpInstMsg[4];  // offset: 0x18
        cGUIObjMessage* mpObjMsg[4];  // offset: 0x38
        cGUIObjPolygon* mpObjMouseOver[4];  // offset: 0x58
        uGUIBase::cAdjustableWindow mWindow;  // offset: 0x78
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x120
        u32 mListCount;  // offset: 0x1d0
        f32 mCursorWidth;  // offset: 0x1d4
        static MyDTI DTI;
        static const u32 DISPLIST_MAX = 4;
        static const u32 INSTLIST_MAX = 4;
    };
public:
    class cPopWndwAddress : public MtObject
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
        cPopWndwAddress();
        // Address: 0x01aed120 - 0x01aed121 (1 bytes)
        virtual ~cPopWndwAddress() {}
        void setVisible(bool bVisible);
        void setupList(cGUIInstance* pInst, u32 uNum);
        void setMessage(u32 uIdx, MT_CTSTR pMsg);
        void update();
    public:
        uGUIChat* mpParentGUI;  // offset: 0x8
        cGUIInstNull* mpInstNull;  // offset: 0x10
        cGUIInstAnimation* mpInstList[12];  // offset: 0x18
        cGUIObjMessage* mpObjMsgList[12];  // offset: 0x78
        cGUIObjPolygon* mpObjMouseOver[12];  // offset: 0xd8
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x140
        f32 mCursorWidth;  // offset: 0x1f0
        uGUIBase::cAdjustableWindow mWindow;  // offset: 0x1f8
        static MyDTI DTI;
    };
public:
    class cPopWndwYoN : public MtObject
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
        cPopWndwYoN();
        // Address: 0x01aed110 - 0x01aed111 (1 bytes)
        virtual ~cPopWndwYoN() {}
        void setVisible(bool bVisible);
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        uGUIBase::cReferenceUIButton mBtnDecide;  // offset: 0x18
        uGUIBase::cReferenceUIButton mBtnCancel;  // offset: 0x1a8
        static MyDTI DTI;
    };
public:
    class cPopWndwAddCh : public MtObject
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
        cPopWndwAddCh();
        virtual ~cPopWndwAddCh();
        void setVisible(bool bVisible);
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        uGUIBase::cReferenceUITextBox mTextBox;  // offset: 0x18
        uGUIBase::cReferenceUIButton mBtnDecide;  // offset: 0x180
        uGUIBase::cReferenceUIButton mBtnCancel;  // offset: 0x310
        uGUIBase::cAdjustableWindow mWindow;  // offset: 0x4a0
        static const u32 CHNAME_LENGTH = 8;
        static MyDTI DTI;
    };
public:
    class cCheckList : public uGUIBase::cReferenceUICheckList
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
        cCheckList();
        virtual ~cCheckList();
    protected:
        virtual MtSizeF calcWindowSize(f32 totalWidth, f32 rowHeight, s32 rowNum, MtFloat2& outWindowFrameOffset, MtFloat2& outTitleOffset, MtFloat2& outCheckboxOffset, MtFloat2& outButtonOffset);  // vtable slot 19
        virtual void setWindowSize(uGUIBase::cAdjustableWindow& window, const MtSize& windowSize);  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    struct stChatLogWork
    {
    public:
        void init();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        u32 mMsgQueueAllNum;  // offset: 0x8
        f32 mPosYTgt;  // offset: 0xc
    };
public:
    struct LogSubMenuParam
    {
    public:
        u32 characterId;  // offset: 0x0
        MtString mFirstName;  // offset: 0x8
        MtString mLastName;  // offset: 0x10
        MtString mClanName;  // offset: 0x18
    };
public:
    struct LogCursorInfo
    {
    public:
        f32 x;  // offset: 0x0
        f32 width;  // offset: 0x4
    };
public:
    class cLogInfo : public uGUIBase::cScrollListInfoBase
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
        cLogInfo();
        // Address: 0x01aed3d0 - 0x01aed3d1 (1 bytes)
        virtual ~cLogInfo() {}
        bool isValid() const;
        sChat::stMsgQueue* getMsgQueue() const;
        void setMsgQueue(uGUIChat& owner, sChat::stMsgQueue* msgQueue, f32 topPos);
        f32 getHeight() const;
        s32 getLogId() const;
        void clear();
    private:
        sChat::stMsgQueue* mMsgQueue;  // offset: 0x28
        f32 mMsgHeight;  // offset: 0x30
        s32 mLogId;  // offset: 0x34
    public:
        static MyDTI DTI;
    };
public:
    class cLogInfoStack
    {
    public:
        cLogInfoStack();
        ~cLogInfoStack();
        void push(uGUIChat::cLogInfo* logInfo);
        uGUIChat::cLogInfo* pop();
    private:
        nDDOUtility::cArray<uGUIChat::cLogInfo*, 300> mStack;  // offset: 0x0
        u32 mStackSize;  // offset: 0x960
    };
public:
    class cLogList
    {
    public:
        cLogList();
        virtual ~cLogList();
        void setup(uGUIChat& owner);
        void moveInput();
        void moveEvent();
        void update(f32 deltaTime);
        void setVisibleCursor(bool isVisibleCursor);
        void clear(uGUIChat::cLogInfoStack& stack);
        void addInfo(uGUIChat::cLogInfo* logInfo);
        void eraseInfo(s32 index);
        void refresh(f32 visibleHeight, s32 pos, f32 scrollPos);
        void setListPos(s32 pos, bool isImmediate);
        s32 getInfoNum() const;
        uGUIChat::cLogInfo* getInfo(s32 index);
        s32 getCurrentPos() const;
        uGUIChat::cLogInfo* getCurrentInfo();
        sChat::stMsgQueue* getCurrentMsgQueue();
        f32 getScrollPos();
        f32 getVisibleHeight() const;
        f32 getTotalHeight();
    private:
        uGUIBase::cScrollList mScrollList;  // offset: 0x10
        cGUIInstNull* mpINST_Null_log_adjust;  // offset: 0x2c0
        cGUIInstNull* mpINST_Null_cursor_log;  // offset: 0x2c8
        f32 mVisibleHeight;  // offset: 0x2d0
    };
public:
    class cLogItem : public uGUIBase::cScrollListItemBase
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
        cLogItem();
        // Address: 0x01aed420 - 0x01aed421 (1 bytes)
        virtual ~cLogItem() {}
        void setup(uGUIChat& owner, cGUIInstNull* inst_null_log_item);
        void show(uGUIChat& owner, uGUIChat::cLogInfo& logInfo);
        void hide();
        const uGUIChat::LogCursorInfo& refCursorInfo() const;
    private:
        cGUIInstNull* mpINST_Null_log_item;  // offset: 0x58
        cGUIInstAnimation* mpINST_msg_log_item;  // offset: 0x60
        cGUIObjMessage* mpOBJ_msg_id_m_id;  // offset: 0x68
        cGUIObjPolygon* mpOBJ_msg_id_mouseover;  // offset: 0x70
        uGUIChat::LogCursorInfo mCursorInfo;  // offset: 0x78
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
private:
    void showLogItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideLogItem(uGUIBase::cScrollListItemBase* pItemBase);
    bool evCtrlLogDecideCheck();
    bool evCtrlScrollList(cControl::Message* msg);
    bool setLog(cGUIObjMessage* objMessage, sChat::stMsgQueue& msgQueue, LogCursorInfo* logCursorInfo);
public:
    uGUIChat();
    virtual ~uGUIChat();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void replacePriority(u32 uPrioGrp);  // vtable slot 80
    void bootup();
    void finish();
    void noticeLogReset();
    bool noticeLogAdd(s32 sFiterGrp);
    void updateFilter();
    bool isMenuUI() const;
    bool isMenuUISubMenu();
    void setUpdF(u32);
    void orUpdF(u32 uFlag);
    void xorUpdF(u32);
    void clrUpdF(u32 uFlag);
    bool isUpdF(u32 uFlag);
    u32 getUpdF();
    void reqTellState();
    void reqNActive(bool bDispOff, bool bForbid);
    void setForbid(bool bForbid);
    bool isForbid();
    void setAlpha(f32 fAlpha);
    bool isChatInput() const;
    MtRectF getFormSize() const;
    MT_CTSTR getChatGmdMsg(GMD_ID gmdId, u32 msgId) const;
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateInit();
    void updateHide();
    void updateIn();
    void updateWait();
    void updateWaitMenu();
    void updateWaitInput();
    void updateWaitAddCh();
    void updateWaitAddress();
    void updateWaitAddressCL();
    void updateWaitLog();
    void updateWaitLogSubCmd();
    void updateWaitFilterSubCmd();
    void updateWaitFilterSubCmdDelete();
    void updateOutToHide();
    void updateWaitFrame();
    void updateDisableMenu();
    void updateExit();
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlMenuMoveV(cControl::Message* msg);
    u32 evCtrlMenuMoveH(cControl::Message* msg);
    u32 evCtrlMenuMoveSendRec(cControl::Message* msg);
    u32 evCtrlMenuDecide(cControl::Message* msg);
    u32 evCtrlMenuCancel(cControl::Message* msg);
    u32 evCtrlMenuTopBtn(cControl::Message* msg);
    u32 evCtrlMenuChgWndwSize(cControl::Message* msg);
    u32 evCtrlMenuToLog(cControl::Message* msg);
    u32 evCtrlMenuMouseDecide(cControl::Message* msg);
    u32 evCtrlMenuMouseSelect(cControl::Message* msg);
    u32 evCtrlMenuSpecialKeyMoveAddress(cControl::Message* msg);
    u32 evCtrlMenuSpecialKeyMoveFilter(cControl::Message* msg);
    u32 evCtrlFilterToMenu(cControl::Message* msg);
    u32 evCtrlFilterMove(cControl::Message* msg);
    u32 evCtrlFilterDecide(cControl::Message* msg);
    u32 evCtrlLogCancel(cControl::Message* msg);
    u32 evCtrlLogDecide(cControl::Message* msg);
    u32 evCtrlLogClick(cControl::Message* msg);
    u32 evCtrlAddChVlMove(cControl::Message* msg);
    u32 evCtrlAddChVlCancel(cControl::Message* msg);
    u32 evCtrlAddChVlDecide(cControl::Message* msg);
    u32 evCtrlAddChVlClick(cControl::Message* msg);
    u32 evCtrlYoNMove(cControl::Message* msg);
    u32 evCtrlYoNClick(cControl::Message* msg);
    u32 evCtrlAddressMove(cControl::Message* msg);
    u32 evCtrlAddressCancel(cControl::Message* msg);
    u32 evCtrlAddressDecide(cControl::Message* msg);
    u32 evCtrlAddressClick(cControl::Message* msg);
    u32 evCtrlFilterSubCmdMove(cControl::Message* msg);
    u32 evCtrlFilterSubCmdCancel(cControl::Message* msg);
    u32 evCtrlFilterSubCmdDecide(cControl::Message* msg);
    u32 evCtrlFilterSubCmdClick(cControl::Message* msg);
    u32 evCtrlYoNDelMove(cControl::Message* msg);
    u32 evCtrlYoNDelDecide(cControl::Message* msg);
    u32 evCtrlYoNDelCancel(cControl::Message* msg);
    u32 evCtrlYoNDelClick(cControl::Message* msg);
    u32 evCtrlFormLDecide(cControl::Message* msg);
    u32 evCtrlFormLCancel(cControl::Message* msg);
    void evDisableMenu();
    void updateDisp();
    void setMenuPointerPos(s32 menuPos);
    void execDirectChat();
    bool sendChatMessage();
    u32 getAddressFromChatArea(u32 uChatArea);
    void enableMenu();
    void disableMenu(bool bClearInputForm);
    void setButtonGuide(bool bReset);
    bool startInput(bool bPad, bool bSendMsgAtInputEnd);
    void initCtrlAddress();
    bool isOperable() const;
    void addFormMouseTouchList(cControl* ctrl);
    void syncCtrlFilter(cControl* modifiedCtrl);
    void evFilterDecide();
protected:
    virtual bool onKeyEvent(const nInputTextKeyboardHook::Keycode& keycode);  // vtable slot 90
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstance* mpInstNull_all;  // offset: 0x8d0
    cGUIInstNull* mpInstNull_tab;  // offset: 0x8d8
    cGUIObjPolygon* mpOBJ_tabAddMouseOver;  // offset: 0x8e0
    cGUIInstAnimation* mpInstAnim_form;  // offset: 0x8e8
    cGUIInstNull* mpInstNull_base;  // offset: 0x8f0
    cGUIObjColorAdjust* mpObjMsgAddressColorAdjust;  // offset: 0x8f8
    cGUIObjMessage* mpObjMsgAddress;  // offset: 0x900
    cGUIObjMessage* mpObjMsgSendMsg;  // offset: 0x908
    cGUIObjPolygon* mpObjPolygonSMask;  // offset: 0x910
    cGUIObjNull* mpObjNullPointerPosAddress;  // offset: 0x918
    cGUIObjNull* mpObjNullPointerPosForm;  // offset: 0x920
    cGUIObjNull* mpObjNullPointerPosTabAdd;  // offset: 0x928
    cGUIObjTexture* mpObjTexFormLeft;  // offset: 0x930
    cGUIObjTexture* mpObjTexFormCenter;  // offset: 0x938
    cGUIObjTexture* mpObjTexFormRight;  // offset: 0x940
    cGUIObjNull* mpOBJ_msg_form_Null_changeicon;  // offset: 0x948
    cGUIObjTexture* mpOBJ_msg_form_base00;  // offset: 0x950
    cGUIObjMessage* mpOBJ_msg_form_m_changeicon;  // offset: 0x958
    cGUIObjMessage* mpOBJ_msg_form_m_attention;  // offset: 0x960
    nDDOUtility::cArray<cGUIInstAnimation*, 4> mpINST_indexs;  // offset: 0x968
    cGUIInstNull* mpINST_Null_log_item;  // offset: 0x988
    cGUIInstAnimation* mpINST_msg_log_item;  // offset: 0x990
    cGUIObjMessage* mpOBJ_msg_id_m_id;  // offset: 0x998
    uGUIBase::cReferenceUITab mTab;  // offset: 0x9a0
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xa50
    cWindow mChatWindow;  // offset: 0xae8
    cPopWndwChSubCmd mPopWndwChSubCmd;  // offset: 0xb80
    cPopWndwAddress mPopWndwAddress;  // offset: 0xd60
    cPopWndwYoN mPopWndwYoN;  // offset: 0x1000
    cPopWndwAddCh mPopWndwAddCh;  // offset: 0x1338
    cCheckList mPopWndwAddChFilter;  // offset: 0x1878
    cControl* mpCtrl;  // offset: 0x1db0
    uGUIBase::cVerticalList* mpCtrlMenu;  // offset: 0x1db8
    uGUIBase::cHorizontalList* mpCtrlFilter;  // offset: 0x1dc0
    uGUIBase::cHorizontalList* mpCtrlFilterLR;  // offset: 0x1dc8
    cControl* mpCtrlLog;  // offset: 0x1dd0
    uGUIBase::cVerticalList* mpCtrlAddChVl;  // offset: 0x1dd8
    uGUIBase::cHorizontalList* mpCtrlYoN;  // offset: 0x1de0
    uGUIBase::cVerticalList* mpCtrlAddress;  // offset: 0x1de8
    uGUIBase::cVerticalList* mpCtrlFilterSubCmd;  // offset: 0x1df0
    uGUIBase::cHorizontalList* mpCtrlYoNDel;  // offset: 0x1df8
    cControl* mpCtrlForm;  // offset: 0x1e00
    cControl* mpCtrlSpecialKey;  // offset: 0x1e08
    stChatLogWork mChatLogWork;  // offset: 0x1e10
    bool mBootUp;  // offset: 0x1e20
    bool mBootUpReq;  // offset: 0x1e21
    u32 mUpdF;  // offset: 0x1e24
    u32 mAddressOld;  // offset: 0x1e28
    u32 mBtnGuideId;  // offset: 0x1e2c
    s32 mPosInputForm;  // offset: 0x1e30
    s32 mPosSendMsgRec;  // offset: 0x1e34
    bool mIsMenuUISubMenu;  // offset: 0x1e38
    bool mIsLoadingStateOld;  // offset: 0x1e39
    bool mIsSendMsgAtInputEnd;  // offset: 0x1e3a
    bool mIsEditCh;  // offset: 0x1e3b
    bool mIsReqTellState;  // offset: 0x1e3c
    bool mIsForbid;  // offset: 0x1e3d
    bool mIsDirectInput;  // offset: 0x1e3e
    bool mIsWindowLarge;  // offset: 0x1e3f
    f32 mAlpha;  // offset: 0x1e40
    f32 mFrmCntNoneCtrl;  // offset: 0x1e44
    f32 mFrmNoneCtrl;  // offset: 0x1e48
    f32 mTabW;  // offset: 0x1e4c
    f32 mOfsTabAddCh;  // offset: 0x1e50
    f32 mOfsTabR;  // offset: 0x1e54
    f32 mLogIntervalY;  // offset: 0x1e58
    f32 mLogCursorHeight;  // offset: 0x1e5c
    cRecordString mInputString;  // offset: 0x1e60
    nDDOUtility::cArray<MtStringEx<256>, 9> mSendMsgRec;  // offset: 0x1f64
    uGUICommunityList* mpGUICList;  // offset: 0x2888
    u32 mRnoTell;  // offset: 0x2890
    u32 mRnoWaitChatLogSubCmd;  // offset: 0x2894
    u8 mReqNActive;  // offset: 0x2898
    s32 mWaitFrame;  // offset: 0x289c
    void(uGUIChat::*mpNextFunc)();  // offset: 0x28a0
    u32 mPriorityGroup;  // offset: 0x28b0
    LogSubMenuParam mLogSubMenuParam;  // offset: 0x28b8
    LogItems mLogItems;  // offset: 0x28d8
    LogInfos mLogInfos;  // offset: 0x3758
    cLogInfoStack mLogInfoStack;  // offset: 0x78f8
    cLogList mLogList;  // offset: 0x8260
public:
    static MyDTI DTI;
    static const u32 FRM_IN = 2;
    static const u32 FRM_TOHIDEWITHNONECTRL = 600;
    static const u32 LOG_MAX = 100;
    static const u32 LOGCTRL_MAX = 27;
    static const u32 LOGDISP_MAX = 29;
    static const s32 SENDMSGRECORD_NUM = 9;
};

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIChat::isMenuUISubMenu() {
    return this->mIsMenuUISubMenu;
}

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIChat::isForbid() {
    return this->mIsForbid;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIChat::cWindow::cWindow() {
    this->mLargeMaskHeightCenter = 0.0f;
    this->mLargeMaskHeightTop = 0.0f;
    this->mLargeWindowHeightCenter = 0.0f;
    this->mLargeWindowHeightTop = 0.0f;
    this->mDefaultMaskHeightCenter = 0.0f;
    this->mDefaultMaskHeightTop = 0.0f;
    this->mDefaultWindowHeightCenter = 0.0f;
    this->mDefaultWindowHeightTop = 0.0f;
    this->mpObjMaskC = static_cast<cGUIObjPolygon*>(nullptr);
    this->mpObjMaskT = static_cast<cGUIObjPolygon*>(nullptr);
    this->mpInstMask = static_cast<cGUIInstance*>(nullptr);
    this->mpOBJ_window00_mouseover = static_cast<cGUIObjPolygon*>(nullptr);
    this->mpObjWndwRT = static_cast<cGUIObjTexture*>(nullptr);
    this->mpObjWndwCT = static_cast<cGUIObjTexture*>(nullptr);
    this->mpObjWndwLT = static_cast<cGUIObjTexture*>(nullptr);
    this->mpObjWndwR = static_cast<cGUIObjTexture*>(nullptr);
    this->mpObjWndwC = static_cast<cGUIObjTexture*>(nullptr);
    this->mpObjWndwL = static_cast<cGUIObjTexture*>(nullptr);
    this->mpInstWndw = static_cast<cGUIInstance*>(nullptr);
    this->mpParentGUI = static_cast<uGUIChat*>(nullptr);
    this->mMouseTouchListIndex = static_cast<u32>(4294967295);
    this->mIsLarge = false;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIChat::cPopWndwChSubCmd::cPopWndwChSubCmd() {
    this->mListCount = static_cast<u32>(0);
    this->mCursorWidth = 0.0f;
    this->mpObjMouseOver[3] = static_cast<cGUIObjPolygon*>(nullptr);
    this->mpObjMouseOver[2] = static_cast<cGUIObjPolygon*>(nullptr);
    this->mpObjMouseOver[1] = static_cast<cGUIObjPolygon*>(nullptr);
    this->mpObjMouseOver[0] = static_cast<cGUIObjPolygon*>(nullptr);
    this->mpObjMsg[3] = static_cast<cGUIObjMessage*>(nullptr);
    this->mpObjMsg[2] = static_cast<cGUIObjMessage*>(nullptr);
    this->mpObjMsg[1] = static_cast<cGUIObjMessage*>(nullptr);
    this->mpObjMsg[0] = static_cast<cGUIObjMessage*>(nullptr);
    this->mpInstMsg[3] = static_cast<cGUIInstAnimation*>(nullptr);
    this->mpInstMsg[2] = static_cast<cGUIInstAnimation*>(nullptr);
    this->mpInstMsg[1] = static_cast<cGUIInstAnimation*>(nullptr);
    this->mpInstMsg[0] = static_cast<cGUIInstAnimation*>(nullptr);
    this->mpInstNull = static_cast<cGUIInstNull*>(nullptr);
    this->mpParentGUI = static_cast<uGUIChat*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIChat::cPopWndwYoN::cPopWndwYoN() {
    this->mpObjMsg = static_cast<cGUIObjMessage*>(nullptr);
    this->mpInstNull = static_cast<cGUIInstNull*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIChat::cPopWndwAddCh::cPopWndwAddCh() {
    this->mpObjMsg = static_cast<cGUIObjMessage*>(nullptr);
    this->mpInstNull = static_cast<cGUIInstNull*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIChat::cCheckList::cCheckList() {
}
