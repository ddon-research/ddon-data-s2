#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class rSoundRequest;

// Declarations
class uGUIClanEditBase;
class uGUIClanEditInputName;
class uGUIClanEditInputNameBase;
class uGUIClanEditInputNickname;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIClanEditBase : public uGUIBase
{
public:
    enum BUTTON_INDEX
    {
        BUTTON_DECIDE = 0,
        BUTTON_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_MOVE = 66,
        INPUTEVENT_DECIDE = 67,
    };
public:
    class MyDTI;
    struct DATA;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DATA
    {
    public:
        cGUIInstAnimation* mpINST_window00;  // offset: 0x0
        cGUIInstAnimation* mpINST_window_frame00;  // offset: 0x8
        cGUIInstNull* mpINST_Null;  // offset: 0x10
        cGUIInstNull* mpINST_Null_all;  // offset: 0x18
        cGUIInstAnimation* mpINST_emblemback;  // offset: 0x20
        cGUIInstAnimation* mpINST_msg_edit00;  // offset: 0x28
        cGUIInstAnimation* mpINST_msg_textbox01;  // offset: 0x30
        cGUIInstAnimation* mpINST_msg_textbox00;  // offset: 0x38
        cGUIInstAnimation* mpINST_fix_check;  // offset: 0x40
        cGUIInstAnimation* mpINST_msg_edit01;  // offset: 0x48
        cGUIInstAnimation* mpINST_msg_edit02;  // offset: 0x50
        cGUIInstAnimation* mpINST_msg_edit03;  // offset: 0x58
        cGUIInstAnimation* mpINST_msg_edit04;  // offset: 0x60
        cGUIInstAnimation* mpINST_msg_textbox02;  // offset: 0x68
        cGUIInstNull* mpINST_Null_emblem;  // offset: 0x70
        cGUIInstAnimation* mpINST_checkbox;  // offset: 0x78
        cGUIInstNull* mpINST_Null_checkbox;  // offset: 0x80
        cGUIInstAnimation* mpINST_msg_check;  // offset: 0x88
        cGUIInstAnimation* mpINST_msg_clanname;  // offset: 0x90
        cGUIInstAnimation* mpINST_msg_edit05;  // offset: 0x98
        cGUIInstAnimation* mpINST_msg_textbox03;  // offset: 0xa0
        cGUIInstAnimation* mpINST_msg_btn04;  // offset: 0xa8
        cGUIInstAnimation* mpINST_msg_btn05;  // offset: 0xb0
        cGUIInstAnimation* mpINST_msg_pop;  // offset: 0xb8
        cGUIObjMessage* mpOBJ_msg_edit00_m_section00;  // offset: 0xc0
        cGUIObjMessage* mpOBJ_msg_edit00_m_section01;  // offset: 0xc8
        cGUIObjMessage* mpOBJ_msg_edit01_m_section00;  // offset: 0xd0
        cGUIObjMessage* mpOBJ_msg_edit02_m_section00;  // offset: 0xd8
        cGUIObjMessage* mpOBJ_msg_edit03_m_section00;  // offset: 0xe0
        cGUIObjMessage* mpOBJ_msg_edit04_m_section00;  // offset: 0xe8
        cGUIObjMessage* mpOBJ_msg_edit05_m_section00;  // offset: 0xf0
        cGUIObjMessage* mpOBJ_msg_check_m_keyword;  // offset: 0xf8
        cGUIObjMessage* mpOBJ_msg_clanname_m_keywordedit;  // offset: 0x100
        cGUIObjMessage* mpOBJ_msg_clanname_m_abbreviate;  // offset: 0x108
        cGUIObjMessage* mpOBJ_msg_pop_m_section00;  // offset: 0x110
        cGUIObjMessage* mpOBJ_msg_pop_m_text;  // offset: 0x118
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
    uGUIClanEditBase();
    virtual ~uGUIClanEditBase();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    rSoundRequest* getSoundRes();
protected:
    virtual void initFlow();  // vtable slot 91
    virtual void setupInstances();  // vtable slot 92
    virtual void setupObjects();  // vtable slot 93
    virtual void setupRefrenceUIs();  // vtable slot 94
    virtual void setupButton();  // vtable slot 95
    virtual void setupControls();  // vtable slot 96
    virtual void setupButtonControl(u32 controlId, u32 parentId, s32 movePos, s32 initPos);  // vtable slot 97
    u32 evCtrlMove(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    virtual u32 onEvCtrlMove(cControl::Message* msg);  // vtable slot 98
    virtual u32 onEvCtrlDecide(cControl::Message* msg);  // vtable slot 99
    virtual u32 onEvCtrlCancel(cControl::Message* msg);  // vtable slot 100
    void updateInit();
    void updateWait();
    virtual void onUpdateInit();  // vtable slot 101
    virtual void onUpdateWait();  // vtable slot 102
protected:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rSoundRequest* mpSeRes;  // offset: 0x8d0
    cGUIControlMgr mControlMgr;  // offset: 0x8d8
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mButtons;  // offset: 0xd88
    DATA mData;  // offset: 0x10a8
public:
    static MyDTI DTI;
};

class uGUIClanEditInputNameBase : public uGUIClanEditBase
{
public:
    enum CONTROL_ID
    {
        CONTROL_POS_V = 0,
        CONTROL_BUTTON = 1,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
    enum POS_V
    {
        POS_V_TEXTBOX = 0,
        POS_V_BUTTON = 1,
        POS_V_NUM = 2,
    };
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
    uGUIClanEditInputNameBase();
    virtual ~uGUIClanEditInputNameBase();
protected:
    virtual void initFlow();  // vtable slot 91
    virtual void setupRefrenceUIs();  // vtable slot 94
    virtual void setupControls();  // vtable slot 96
    virtual void setupTextBox();  // vtable slot 103
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual u32 onEvCtrlDecide(cControl::Message* msg);  // vtable slot 99
    void evDecide();
    void updateFocus();
    virtual void onUpdateInit();  // vtable slot 101
    virtual void onUpdateWait();  // vtable slot 102
    virtual void onDecide();  // vtable slot 104
    virtual void setMessage() {}  // vtable slot 105
    virtual void setButtonEnable(s32 buttonId) {}  // vtable slot 106
protected:
    uGUIBase::cReferenceUITextBox mTextBox;  // offset: 0x11c8
public:
    static MyDTI DTI;
};

class uGUIClanEditInputNickname : public uGUIClanEditInputNameBase
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
    uGUIClanEditInputNickname();
    virtual ~uGUIClanEditInputNickname();
    virtual s32 getSMenuCursorY();  // vtable slot 72
protected:
    virtual void setupInstances();  // vtable slot 92
    virtual void setupObjects();  // vtable slot 93
    virtual void setupTextBox();  // vtable slot 103
    virtual void onDecide();  // vtable slot 104
    virtual void setMessage();  // vtable slot 105
    virtual void setButtonEnable(s32 buttonId);  // vtable slot 106
public:
    static MyDTI DTI;
};

class uGUIClanEditInputName : public uGUIClanEditInputNameBase
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
    uGUIClanEditInputName();
    virtual ~uGUIClanEditInputName();
    virtual s32 getSMenuCursorY();  // vtable slot 72
protected:
    virtual void setupInstances();  // vtable slot 92
    virtual void setupObjects();  // vtable slot 93
    virtual void setupTextBox();  // vtable slot 103
    virtual void onDecide();  // vtable slot 104
    virtual void setMessage();  // vtable slot 105
    virtual void setButtonEnable(s32 buttonId);  // vtable slot 106
public:
    static MyDTI DTI;
};

inline void* uGUIClanEditBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIClanEditInputName::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIClanEditInputNameBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIClanEditInputNickname::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIClanEditBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanEditBase::DTI)->memFree(p_addr);
}

inline void uGUIClanEditInputName::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanEditInputName::DTI)->memFree(p_addr);
}

inline void uGUIClanEditInputNameBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanEditInputNameBase::DTI)->memFree(p_addr);
}

inline void uGUIClanEditInputNickname::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIClanEditInputNickname::DTI)->memFree(p_addr);
}
