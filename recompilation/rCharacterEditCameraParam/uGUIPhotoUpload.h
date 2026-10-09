#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class rGUIMessage;
class uGUISystemMsg;

// Declarations
class uGUIPhotoUpload;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPhotoUpload : public uGUIBase
{
public:
    enum PR
    {
        PR_NONE = 0,
        PR_CATE_WAIT = 1,
        PR_INIT = 2,
        PR_EDIT = 3,
        PR_EDIT_COMMENT = 4,
        PR_EDIT_CATEGORY = 5,
        PR_AUTH_ADDR_WAIT = 6,
        PR_UPLOAD_PRE_WAIT = 7,
        PR_UPLOAD_WAIT = 8,
        PR_UPLOAD_SUCCES = 9,
        PR_UPLOAD_FAILED = 10,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR_V = 68,
        INPUTEVENT_ADJUST_CURSOR_H = 69,
        INPUTEVENT_MOUSE = 70,
    };
public:
    class MyDTI;
    struct stMain;
    struct stVariable;
    struct stReference;
    class cCate;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stMain
    {
    public:
        cGUIInstNull* null_window;  // offset: 0x0
        cGUIInstAnimation* msg_title;  // offset: 0x8
        cGUIObjMessage* msg_title_m_txt;  // offset: 0x10
        cGUIInstAnimation* msg_location;  // offset: 0x18
        cGUIObjMessage* msg_location_m_txt00;  // offset: 0x20
        cGUIObjMessage* msg_location_m_txt01;  // offset: 0x28
        cGUIInstAnimation* msg_category;  // offset: 0x30
        cGUIObjMessage* msg_category_m_txt;  // offset: 0x38
        cGUIInstAnimation* msg_comment;  // offset: 0x40
        cGUIObjMessage* msg_comment_m_txt;  // offset: 0x48
        cGUIInstAnimation* msg_textbox;  // offset: 0x50
        cGUIInstAnimation* msg_btn00;  // offset: 0x58
        cGUIInstAnimation* msg_btn01;  // offset: 0x60
        cGUIInstNull* null_pulldown;  // offset: 0x68
        cGUIInstAnimation* msg_pulldown;  // offset: 0x70
        cGUIInstAnimation* mouse_collision;  // offset: 0x78
        cGUIInstNull* null_pop;  // offset: 0x80
        cGUIInstAnimation* mouse_collision01;  // offset: 0x88
        cGUIInstNull* null_pop00;  // offset: 0x90
        cGUIInstAnimation* msg_loadicon;  // offset: 0x98
        cGUIInstAnimation* msg_pop00;  // offset: 0xa0
        cGUIObjMessage* msg_pop00_m_txt00;  // offset: 0xa8
        cGUIObjMessage* msg_pop00_m_txt01;  // offset: 0xb0
        cGUIInstNull* null_pop01;  // offset: 0xb8
        cGUIInstAnimation* msg_btn02;  // offset: 0xc0
        cGUIInstAnimation* msg_pop01;  // offset: 0xc8
        cGUIObjMessage* msg_pop01_m_txt00;  // offset: 0xd0
        cGUIObjMessage* msg_pop01_m_txt01;  // offset: 0xd8
    };
public:
    struct stVariable
    {
    public:
        s32 param_pulldown_x;  // offset: 0x0
        s32 param_textbox_x;  // offset: 0x4
        s32 param_textbox_y;  // offset: 0x8
        s32 param_mouse_collision;  // offset: 0xc
        s32 param_mouse_collision01;  // offset: 0x10
    };
public:
    struct stReference
    {
    public:
        uGUIBase::cReferenceUIButton mBtn00;  // offset: 0x0
        uGUIBase::cReferenceUIButton mBtn01;  // offset: 0x190
        uGUIBase::cReferenceUIButton mBtn02;  // offset: 0x320
        uGUIBase::cReferenceUIPullDown mPulldown;  // offset: 0x4b0
        uGUIBase::cReferenceUITextBox mComment;  // offset: 0xac0
    };
public:
    class cCate : public MtObject
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
        cCate(u32 in);
        // Address: 0x01afae20 - 0x01afae21 (1 bytes)
        virtual ~cCate() {}
    public:
        u32 id;  // offset: 0x8
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
    uGUIPhotoUpload();
    virtual ~uGUIPhotoUpload();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setErrMsg(MT_CTSTR str);
private:
    virtual void updatePtr();  // vtable slot 17
    void updateInit();
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void init();
    void setProc(PR proc);
    void adjustCursor();
    void resetCtrlNum(s32 pos);
    void setupInput();
    void updateInput();
    void setupPulldown();
    void updatePulldown();
    bool setupCategory();
    void updateGetCategoryWait();
    void preUpload();
    void upload();
    void updateGetAuthAddrWait();
    void updatePreUploadWait();
    void updateSendScreenShotWait();
    void evDecide();
    void evCancel();
    void evAdjustCursorV();
    void evAdjustCursorH();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursorV(cControl::Message* msg);
    u32 evCtrlAdjustCursorH(cControl::Message* msg);
    u32 evCtrlMouse(cControl::Message* msg);
    s32 getCtrlPos(cControl*);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    cGUIInstNull* mpInstNull;  // offset: 0x8d8
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x8e0
    cControl* mpButtonCtrl;  // offset: 0x8e8
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x8f0
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x8f8
    stMain mMain;  // offset: 0x900
    stVariable mVariable;  // offset: 0x9e0
    stReference mReference;  // offset: 0xa00
    PR mProc;  // offset: 0x1630
    f32 mTimer;  // offset: 0x1634
    MtTypedArray<cCate> mCateIdArray;  // offset: 0x1638
    MtString mErrMsg;  // offset: 0x1658
public:
    static MyDTI DTI;
};
