#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class CDataMailInfo;
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector4;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
class rGUI;

// Declarations
class uGUIMail;

// Type aliases from DWARF
using CMailInfo = CDataMailInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uGUIMail : public uGUIsMenuBase
{
public:
    enum MAIL_TAB
    {
        TAB_UNREAD = 0,
        TAB_USER = 1,
        TAB_SYSTEM = 2,
        TAB_MAX = 3,
    };
    enum
    {
        PROC_MAIN_INIT = 0,
        PROC_MAIN = 1,
        PROC_SUBMENU = 2,
        PROC_RECEIVE = 3,
        PROC_CREATE = 4,
        PROC_DETAIL = 5,
        PROC_DETAIL_CREATE = 6,
        PROC_DELETE = 7,
    };
    enum MAIL_DEF
    {
        MAIL_SMENU_UPDATE = 0,
        MAIL_SMENU_CREATE_GET = 1,
        MAIL_GMD_IDX_0 = 0,
    };
    enum BTN_CURSOR
    {
        BTN_RECEIVE = 0,
        BTN_CREATE = 1,
        BTN_MAX = 2,
    };
    enum GUIDE_BIT
    {
        GUIDE_DELETE = 1,
        GUIDE_SUBMENU = 2,
        GUIDE_BIT_MAX = 2,
    };
    enum V_CURSOR
    {
        V_CURSOR_BTN = 0,
        V_CURSOR_LIST = 1,
        V_CURSOR_MAX = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_ADJUST_TAB = 69,
        INPUTEVENT_ADJUST_BTN = 70,
        INPUTEVENT_ADJUST_CURSOR_BTN = 71,
        INPUTEVENT_CLICK_SCROLL = 72,
    };
public:
    class MyDTI;
    struct stGUIMailInst;
    struct stGUIMailObj;
    class cTabData;
    class cMailData;
    struct stListInstData;
    class cScrollDispList;
    class cScrollItemList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stGUIMailInst
    {
    public:
        cGUIInstNull* null;  // offset: 0x0
        cGUIInstNull* null_all;  // offset: 0x8
        cGUIInstNull* null_list;  // offset: 0x10
        cGUIInstAnimation* msg_tab;  // offset: 0x18
        cGUIInstAnimation* msg_mail;  // offset: 0x20
        cGUIInstAnimation* msg_btn;  // offset: 0x28
        cGUIInstAnimation* icon_address;  // offset: 0x30
        cGUIInstAnimation* loadicon;  // offset: 0x38
        cGUIInstAnimation* msg_txt;  // offset: 0x40
    };
public:
    struct stGUIMailObj
    {
    public:
        cGUIObjMessage* msg_receive;  // offset: 0x0
        cGUIObjMessage* msg_receive_num;  // offset: 0x8
        cGUIObjTexture* icon_light;  // offset: 0x10
        cGUIObjMessage* msg_m_txt;  // offset: 0x18
    };
public:
    class cMailData : public MtObject
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
        cMailData();
    public:
        u64 mIdx;  // offset: 0x8
        u64 mSenderDate;  // offset: 0x10
        u8 mStatus;  // offset: 0x18
        u8 mItemStatus;  // offset: 0x19
    private:
        uGUIMail::stListInstData* mpInstData;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    struct stListInstData
    {
    public:
        using cStr = uGUIBase::cExGUIMessageObj<64>;
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x0
        cGUIInstAnimation* mpInst_list;  // offset: 0x28
        cGUIInstAnimation* mpInst_fix_icon;  // offset: 0x30
        cGUIObjMessage* mpObj_sender;  // offset: 0x38
        cGUIObjMessage* mpObj_title;  // offset: 0x40
        cGUIObjMessage* mpObj_time;  // offset: 0x48
        cGUIObjTexture* mpTex_mail;  // offset: 0x50
        cGUIObjTexture* mpTex_gift;  // offset: 0x58
        cGUIObjTexture* mpTex_iconbase;  // offset: 0x60
        cStr mSender;  // offset: 0x68
        cStr mTitle;  // offset: 0xd0
        cStr mTime;  // offset: 0x138
    };
public:
    class cScrollDispList : public uGUIBase::cScrollListItemBase
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
        cScrollDispList();
        virtual ~cScrollDispList() {}
    public:
        uGUIMail::cMailData* mpMailData;  // offset: 0x58
        uGUIMail::MAIL_TAB mTabType;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    class cScrollItemList : public uGUIBase::cScrollListInfoBase
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
        cScrollItemList();
        cScrollItemList(f32 Top, f32 Bottom, u32 index);
        virtual ~cScrollItemList() {}
    public:
        u32 mIndex;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    class cTabData : public MtObject
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
        cTabData();
        virtual ~cTabData();
        void init(uGUIMail* pOwner, uGUIMail::MAIL_TAB tabType);
        void move();
        u32 getDispDataNum();
        uGUIMail::cMailData* getMailData(u32 idx);
        u32 getListCount();
        u32 getListCountMax();
        void setData(uGUIMail::cMailData* pMailData, u32 cursorIndex);
    public:
        nDDOUtility::cArray<uGUIMail::cMailData, 10> mDataArray;  // offset: 0x8
        uGUIMail* mpOwner;  // offset: 0x198
        uGUIMail::MAIL_TAB mTabType;  // offset: 0x1a0
        uGUIBase::cScrollList mScrollList;  // offset: 0x1b0
        uGUIMail::cScrollDispList mScrollDispList[10];  // offset: 0x460
        uGUIBase::cVerticalList* mpMailListCtrl;  // offset: 0x870
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
    uGUIMail();
    virtual ~uGUIMail();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    MtVector4 getDetailSetPosition();
    void requestListUpdate();
    void requestDispUpdate();
    static f32 getMailIconFrame(CMailInfo* pMailInfo);
protected:
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    virtual s32 getSMenuTab();  // vtable slot 74
private:
    void setupListInfo();
    void setListInfoTab(cTabData* pTabData);
    void initScrollList(cTabData* pTabData);
    void updateScrollList(cTabData* pTabData, bool oldPosUse);
    void updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem);
    bool evScrollMsgEvent(cControl::Message* msg);
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    void updateDisp();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void evCancel();
    void evSmenuCancel();
    void evAdjCursor();
    void evAdjTab();
    void evAdjBtn();
    void setCurrentTab(s32 tabNo);
    void setControlPoint(s32 point);
    void setBtnCursor(s32 point);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlChkout(cControl::Message* msg);
    u32 evCtrlTopbtn(cControl::Message* msg);
    u32 evCtrlAdjCursor(cControl::Message* msg);
    u32 evCtrlAdjTab(cControl::Message* msg);
    u32 evCtrlAdjBtn(cControl::Message* msg);
    u32 evCtrlBtnClick(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x958
    stGUIMailInst mInst;  // offset: 0x960
    stGUIMailObj mObj;  // offset: 0x9a8
    u32 mProc;  // offset: 0x9c8
    nDDOUtility::cArray<cTabData, 3> mTabData;  // offset: 0x9d0
    nDDOUtility::cArray<stListInstData, 10> mListData;  // offset: 0x2350
    cControl* mpCtrl;  // offset: 0x3390
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x3398
    uGUIBase::cHorizontalList* mpBtnCtrl;  // offset: 0x33a0
    uGUIBase::cReferenceUITab mTab;  // offset: 0x33b0
    uGUIBase::cReferenceUIButton2 mBtn;  // offset: 0x3460
    uGUIBase::cReferenceUIIconButton mReceiveBtn;  // offset: 0x35f0
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x3668
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x3700
    MtColor mDefNumColor;  // offset: 0x3758
    bool mReqListUpdate;  // offset: 0x375c
    bool mReqDispUpdate;  // offset: 0x375d
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[2];  // offset: 0x3760
public:
    static MyDTI DTI;
private:
    static const u32 EQUIP_LEFT_NUM = 8;
    static const u32 DISP_LIST_NUM = 10;
};

inline void* uGUIMail::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUIMail::requestListUpdate() {
    this->mReqListUpdate = true;
}

inline void uGUIMail::requestDispUpdate() {
    this->mReqDispUpdate = true;
}

inline void uGUIMail::evSmenuCancel() {
    this->::uGUIBase::mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMail::updateExit);
}

inline void* uGUIMail::cTabData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIMail::cMailData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIMail::cMailData::cMailData() {
    this->mIdx = 0;
    this->mStatus = 0;
    this->mItemStatus = 0;
    this->mpInstData = nullptr;
}

inline void* uGUIMail::cScrollDispList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIMail::cScrollDispList::cScrollDispList() {
    this->mpMailData = nullptr;
}

inline void* uGUIMail::cScrollItemList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIMail::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIMail::DTI)->memFree(p_addr);
}

inline void uGUIMail::cTabData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIMail::cTabData::DTI)->memFree(p_addr);
}

inline void* uGUIMail::cMailData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIMail::cMailData::DTI)->memAlloc(sz, align, ::uGUIMail::cMailData::DTI.::MtDTI::getID());
}

inline void uGUIMail::cMailData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIMail::cMailData::DTI)->memFree(p_addr);
}

inline void* uGUIMail::cScrollDispList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIMail::cScrollDispList::DTI)->memAlloc(sz, align, ::uGUIMail::cScrollDispList::DTI.::MtDTI::getID());
}

inline void uGUIMail::cScrollDispList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIMail::cScrollDispList::DTI)->memFree(p_addr);
}

inline void uGUIMail::cScrollItemList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIMail::cScrollItemList::DTI)->memFree(p_addr);
}
