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
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUICaplinkFilter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUICaplinkFilter : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_SET = 1,
        FLOW_REQ = 2,
        FLOW_FILTER = 3,
        FLOW_END = 4,
    };
    enum
    {
        MODE_FILTER = 0,
        MODE_SET = 1,
    };
    enum
    {
        REQ_RET_NONE = 0,
        REQ_RET_DONE = 1,
    };
    enum
    {
        BUTTON_YES = 0,
        BUTTON_NO = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        CATE_ATTR = 0,
        CATE_NONE_TAG = 1,
        CATE_TAG = 2,
        CATE_NONE_CONTENT = 3,
        CATE_CONTENT = 4,
        CATE_NUM = 5,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_MOUSE_CLICK = 69,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    class cListItem;
    struct stCategory;
    class cListInfo;
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
        s32 mParam_list_y;  // offset: 0x0
        s32 mParam_section_y;  // offset: 0x4
        s32 mParam_btn_x;  // offset: 0x8
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
        cGUIObjMessage* mpObjMsg;  // offset: 0x58
        uGUIBase::cReferenceUICheckbox mCheck;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    struct stCategory
    {
    public:
        stCategory();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
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
        virtual void addMouseTouchList(cControl* pCtrl, s32 pos);  // vtable slot 6
    public:
        u32 mIndex;  // offset: 0x28
        u32 mCate;  // offset: 0x2c
        bool mIsCheck;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        uGUIBase::cScrollList mListCtrl;  // offset: 0x10
        uGUICaplinkFilter::cListItem mList[20];  // offset: 0x2c0
        uGUICaplinkFilter::stCategory mCate[5];  // offset: 0x1080
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x10f8
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x1418
        static const u32 list_num = 20;
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
    uGUICaplinkFilter();
    virtual ~uGUICaplinkFilter();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setFriendMode(MT_CTSTR unique_id);
    u32 getReqRet();
private:
    void setFlowId(u32 flow_id, bool isInit);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupList();
    void setupCategory(s32& pos, u8 category);
    void addList(s32& pos, u8 category, u32 index, bool isCheck, bool isTop);
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    cListInfo* getListInfo(u32 index);
    cListInfo* getListInfo();
    cListInfo* getButtonInfo();
    void setupReq();
    void updateReq();
    void applyFilter();
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mFlowId;  // offset: 0x8d0
    u32 mMode;  // offset: 0x8d4
    u32 mReqRet;  // offset: 0x8d8
    MtString mUniqueId;  // offset: 0x8e0
    u16 mFreeTag;  // offset: 0x8e8
    stVariable mVar;  // offset: 0x8ec
    stMain mMain;  // offset: 0x900
    cControl* mpDecideCtrl;  // offset: 0x1db0
    cControl* mpCancelCtrl;  // offset: 0x1db8
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0x1dc0
    cControl* mpButtonCtrl;  // offset: 0x1dc8
public:
    static MyDTI DTI;
};
