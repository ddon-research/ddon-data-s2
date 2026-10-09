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
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class uGUIAreaMaster;
class uGUIPopCmd01;

// Declarations
class uGUIMenuAreaInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMenuAreaInfo : public uGUIBase
{
public:
    enum
    {
        MODE_GAMEMENU = 0,
        MODE_QUICKPARTY = 1,
        MODE_CLAN = 2,
    };
    enum
    {
        LIST_NORMAL = 0,
        LIST_CLAN = 1,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_SERVER_WAIT = 1,
        FLOW_LIST = 2,
        FLOW_SUBMENU = 3,
        FLOW_SPOT = 4,
        FLOW_HISTORY = 5,
        FLOW_SUPPLIES = 6,
        FLOW_END = 7,
    };
    enum
    {
        CMD_NONE = 0,
        CMD_SPOT = 1,
        CMD_HISTORY = 2,
        CMD_SUPPLIES = 3,
    };
    enum
    {
        REQ_FLAG_GET_AREA_BASE_INFO_LIST = 0,
        REQ_FLAG_NUM = 1,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_CLOSE = 68,
        INPUTEVENT_CHANGE_LIST = 69,
    };
    enum
    {
        ITEMTYPE_HEADER = 1,
        ITEMTYPE_LIST = 2,
    };
public:
    class MyDTI;
    class cListItem;
    class cHeaderItem;
    struct stVariable;
    class cListInfo;
    class cHeaderInfo;
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
        // Address: 0x01af7e70 - 0x01af7e71 (1 bytes)
        virtual ~cListItem() {}
    public:
        cGUIInstAnimation* mpInstAnimIcon;  // offset: 0x58
        cGUIObjMessage* mpObjMsgAreaName;  // offset: 0x60
        cGUIObjMessage* mpObjMsgAreaRank;  // offset: 0x68
        cGUIObjMessage* mpObjMsgAreaRankVal;  // offset: 0x70
        cGUIObjMessage* mpObjMsgNextPt;  // offset: 0x78
        cGUIObjMessage* mpObjMsgNextPtClass;  // offset: 0x80
        cGUIObjMessage* mpObjMsgWeeklyPt;  // offset: 0x88
        cGUIObjMessage* mpObjMsgWeeklyPtClass;  // offset: 0x90
        uGUIBase::cReferenceUICheckbox mCheck;  // offset: 0x98
        static MyDTI DTI;
    };
public:
    class cHeaderItem : public uGUIBase::cScrollListItemBase
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
        cHeaderItem();
        // Address: 0x01af7e60 - 0x01af7e61 (1 bytes)
        virtual ~cHeaderItem() {}
    public:
        cGUIObjMessage* mpObjMsg;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_list_y;  // offset: 0x0
        s32 mParam_cr_list00_y;  // offset: 0x4
        s32 mParam_cr_list00_x;  // offset: 0x8
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
        // Address: 0x01af7f40 - 0x01af7f41 (1 bytes)
        virtual ~cListInfo() {}
    public:
        u32 mAreaId;  // offset: 0x28
        u32 mLandId;  // offset: 0x2c
        u32 mRank;  // offset: 0x30
        u32 mIndex;  // offset: 0x34
        u32 mCurrentPoint;  // offset: 0x38
        u32 mNextPoint;  // offset: 0x3c
        u32 mWeekPoint;  // offset: 0x40
        u32 mClanPoint;  // offset: 0x44
        u32 mClanPointBorder;  // offset: 0x48
        bool mIsCanRankUp;  // offset: 0x4c
        bool mIsSelectEnable;  // offset: 0x4d
        bool mIsReceivedSupplies;  // offset: 0x4e
        static MyDTI DTI;
    };
public:
    class cHeaderInfo : public uGUIBase::cScrollListInfoBase
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
        cHeaderInfo();
        // Address: 0x01af7fd0 - 0x01af7fd1 (1 bytes)
        virtual ~cHeaderInfo() {}
    public:
        u32 mLandId;  // offset: 0x28
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
    uGUIMenuAreaInfo();
    virtual ~uGUIMenuAreaInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setMode(u32 mode);
private:
    void updateWait();
    void updateExit();
    void setFlowId(u32 flow_id);
    void setupList();
    void updateList();
    void setupSectionMessage();
    void setupSubMenu();
    void updateSubMenu();
    void setupAreaMaster(u32 mode);
    void updateAreaMaster();
    bool isRequest(u32 flag);
    void setRequest(u32 flag);
    void clearRequest(u32 flag);
    void requestServer(u32 next_flow_id);
    bool requestAreaBaseInfoList();
    void callbackAreaBaseInfoList();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void evDecide();
    void evCancel();
    void evChangeList();
    void evAdjustCursor(bool isImmediate);
    virtual void evEnd();  // vtable slot 48
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlChangeList(cControl::Message* msg);
    bool evCtrlScrlMouseClick(cControl::Message* msg);
    u32 callbackCmd00(MtObject* pCaller, MtObject* pDummy);
    u32 callbackCmd01(MtObject* pCaller, MtObject* pDummy);
    u32 callbackCmd02(MtObject* pCaller, MtObject* pDummy);
    void initScrollList();
    void updateScrollListDisp(uGUIBase::cScrollListItemBase* pListItem, uGUIBase::cScrollListInfoBase* pListInfo, u32 Index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pListItem);
    void setInstGrayOut(cGUIInstNull* pInst, bool isGrayOut);
    cListInfo* getListInfo(u32 index);
    cListInfo* getListInfo();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mMode;  // offset: 0x8d0
    u32 mListMode;  // offset: 0x8d4
    u32 mFlowId;  // offset: 0x8d8
    u32 mFlowIdNext;  // offset: 0x8dc
    u32 mCmdResult;  // offset: 0x8e0
    u32 mRequestFlag;  // offset: 0x8e4
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x8e8
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x940
    cGUIObjMessage* mpObjMsgSection02;  // offset: 0x9d8
    cGUIObjMessage* mpObjMsgSection03;  // offset: 0x9e0
    uGUIBase::cScrollList mScrollList;  // offset: 0x9f0
    cListItem mList[18];  // offset: 0xca0
    cHeaderItem mHeader[3];  // offset: 0x1cf0
    f32 mCursorOffset;  // offset: 0x1e10
    stVariable mVar;  // offset: 0x1e14
    cControl* mpCtrl;  // offset: 0x1e20
    uGUIPopCmd01* mpGUIPopCmd;  // offset: 0x1e28
    uGUIAreaMaster* mpGUIAreaMaster;  // offset: 0x1e30
    MtStringEx<128> mTempStr;  // offset: 0x1e38
public:
    static MyDTI DTI;
private:
    static const u32 LISTVISIBLE_NUM = 16;
    static const u32 LISTINST_NUM = 18;
    static const u32 HEADER_NUM = 3;
};
