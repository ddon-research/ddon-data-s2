#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIPopProfile;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopProfile : public uGUIsMenuBase
{
public:
    enum
    {
        PULLDOWN_JOB = 0,
        PULLDOWN_MAIN_PURPOSE = 1,
        PULLDOWN_PLAYSTYLE = 2,
        PULLDOWN_MAX = 3,
    };
    enum
    {
        MGR_ID_V = 0,
        MGR_ID_H = 1,
    };
    enum
    {
        CONTROL_CATEGORY_V = 0,
        CONTROL_CATEGORY_H = 1,
    };
    enum
    {
        ITEM_JOB = 0,
        ITEM_MAIN_PURPOSE = 1,
        ITEM_PLAYSTYLE = 2,
        ITEM_WAIT = 3,
        ITEM_COMMENT = 4,
        ITEM_SELECT = 5,
        ITEM_MAX = 6,
    };
    enum
    {
        INPUTEVENT_UPDATEDISP = 66,
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
        cGUIInstAnimation* mpINST_scr_bar;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg_coment_m_title;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_on_m_title;  // offset: 0x10
        cGUIObjMessage* mpOBJ_msg_num_m_num;  // offset: 0x18
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
    uGUIPopProfile();
    virtual ~uGUIPopProfile();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
private:
    void updateDispWait();
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    bool isActivePullDownMenu();
    void updateDecide();
    void updateCursor();
    void manageHControl();
    u32 evCtrlMouseClick(cControl::Message* pMsg);
    bool decideWait();
    bool decideSelect();
    bool cancelSelect();
    bool msgEventFunc(cControl::Message* msg);
private:
    DATA mData;  // offset: 0x958
    rGUI* mpGUIRes;  // offset: 0x978
    bool mIsActiveKeyboard;  // offset: 0x980
    uGUIBase::cReferenceUIScrollBar mPullScrBar;  // offset: 0x988
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mRefButtons;  // offset: 0xa30
    uGUIBase::cReferenceUITextBox mRefTextbox;  // offset: 0xd50
    nDDOUtility::cArray<uGUIBase::cReferenceUIRadioButton, 2> mRefRadioButtons;  // offset: 0xeb8
    cGUIControlMgr mControls;  // offset: 0x1098
public:
    static MyDTI DTI;
};

inline void* uGUIPopProfile::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIPopProfile::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPopProfile::DTI)->memFree(p_addr);
}
