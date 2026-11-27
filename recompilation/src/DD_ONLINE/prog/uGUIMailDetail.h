#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cControl.h"
#include "uGUIBase.h"

// Forward declarations
class CDataMailInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector4;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class uGUIMail;
class uGUIPopDetail01;

// Declarations
class uGUIMailDetail;

// Type aliases from DWARF
using CMailInfo = CDataMailInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMailDetail : public uGUIBase
{
public:
    enum
    {
        PROC_MAIN = 0,
        PROC_REPLY = 1,
    };
    enum MAIL_DETAIL_DEF
    {
        MAIL_DETAIL_GMD_IDX_0 = 0,
    };
    enum V_CURSOR
    {
        V_CURSOR_ITEM = 0,
        V_CURSOR_BTN = 1,
        V_CURSOR_MAX = 2,
    };
    enum GUIDE_BIT
    {
        GUIDE_CHANGE_INFO = 1,
        GUIDE_BIT_MAX = 1,
    };
    enum MAILDIALOG_INPUTEVENT
    {
        INPUTEVENT_ADJUST_BUTTON = 66,
        INPUTEVENT_SHORTCUT = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_ADJUST_CURSOR_ITEM = 69,
        INPUTEVENT_ADJUST_CURSOR_BTN = 70,
        INPUTEVENT_BTN_CLICK_ADJ = 71,
        INPUTEVENT_ITEM_OVER = 72,
        INPUTEVENT_ITEM_OUT = 73,
    };
    enum BTN_CURSOR
    {
        BTN_ITEM_GET = 0,
        BTN_REPLY = 1,
        BTN_DELETE = 2,
        BTN_MAX = 3,
    };
public:
    class MyDTI;
    struct stMailDetailInst;
    struct stMailDetailObj;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stMailDetailInst
    {
    public:
        cGUIInstNull* Null;  // offset: 0x0
        cGUIInstNull* Null_all;  // offset: 0x8
        cGUIInstNull* Null_btn;  // offset: 0x10
        cGUIInstAnimation* msg_list;  // offset: 0x18
        cGUIInstAnimation* msg_content;  // offset: 0x20
        cGUIInstAnimation* msg_btn00;  // offset: 0x28
        cGUIInstAnimation* msg_btn01;  // offset: 0x30
        cGUIInstAnimation* msg_btn02;  // offset: 0x38
        cGUIInstAnimation* fix_icon;  // offset: 0x40
    };
public:
    struct stMailDetailObj
    {
    public:
        cGUIObjMessage* msg_tmpl;  // offset: 0x0
        cGUIObjMessage* msg_adrs_name;  // offset: 0x8
        cGUIObjMessage* msg_index;  // offset: 0x10
        cGUIObjMessage* msg_content;  // offset: 0x18
        cGUIObjMessage* msg_date01;  // offset: 0x20
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
    uGUIMailDetail();
    virtual ~uGUIMailDetail();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setMailPtr(uGUIMail*);
    void setMailInfo(CMailInfo*);
    void setDispPosition(const MtVector4& pos);
    void requestDispUpdate();
protected:
    virtual s32 getSMenuCursorY();  // vtable slot 72
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
    void setMailData();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void evCancel();
    void evAdjCursor();
    void evAdjCursorItem();
    void evAdjCursorBtn();
    void evItemOver();
    void evItemOut();
    void setItemCursor(s32 point);
    void setItemDetail(s32 point, bool guidMsg);
    void setBtnCursor(s32 point);
    s32 getBtnType(s32 point);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjCursor(cControl::Message* msg);
    u32 evCtrlAdjCursorItem(cControl::Message* msg);
    u32 evCtrlAdjCursorBtn(cControl::Message* msg);
    u32 evCtrlBtnClick(cControl::Message* msg);
    u32 evCtrlItemClick(cControl::Message* msg);
    u32 evCtrlItemOver(cControl::Message* msg);
    u32 evCtrlItemOut(cControl::Message* msg);
private:
    u32 mProc;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    stMailDetailInst mInst;  // offset: 0x8d8
    stMailDetailObj mObj;  // offset: 0x920
    uGUIPopDetail01* mpDetail;  // offset: 0x948
    uGUIMail* mpParent;  // offset: 0x950
    cControl* mpCtrl;  // offset: 0x958
    uGUIBase::cHorizontalList* mpItemCtrl;  // offset: 0x960
    uGUIBase::cHorizontalList* mpBtnCtrl;  // offset: 0x968
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x970
    uGUIBase::cReferenceUIButton2 mBtnAllGet;  // offset: 0x978
    uGUIBase::cReferenceUIButton mBtnReply;  // offset: 0xb08
    uGUIBase::cReferenceUIButton mBtnDelete;  // offset: 0xc98
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xe28
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0xec0
    uGUIBase::cReferenceUIIconItem mItemIcon[3];  // offset: 0xf20
    CMailInfo* mpMailInfo;  // offset: 0x13a0
    MtVector4 mDispPosition;  // offset: 0x13b0
    bool mIsSystemMail;  // offset: 0x13c0
    bool mReqDispUpdate;  // offset: 0x13c1
    s32 mMouseOverId;  // offset: 0x13c4
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x13c8
public:
    static MyDTI DTI;
private:
    static const u32 ITEM_ICON_NUM = 3;
};

inline void* uGUIMailDetail::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUIMailDetail::requestDispUpdate() {
    this->mReqDispUpdate = true;
}

inline void uGUIMailDetail::evCancel() {
    this->::uGUIBase::mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIMailDetail::updateExit);
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIMailDetail::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIMailDetail::DTI)->memFree(p_addr);
}
