#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIArisenCardPopPawn;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIArisenCardPopPawn : public uGUIBase
{
public:
    enum
    {
        BUTTON_OK = 0,
        BUTTON_NG = 1,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_CHANGELINE = 67,
        INPUTEVENT_CHANGEBUTTON = 68,
        INPUTEVENT_OPERATETEXTBOX = 69,
        INPUTEVENT_CLICKEND = 70,
    };
    enum
    {
        LINE_TEXTBOX = 0,
        LINE_BUTTON = 1,
        LINE_NUM = 2,
    };
    enum
    {
        CLICK_OK = 0,
        CLICK_NG = 1,
    };
    enum
    {
        COMMENT_STR_MAX = 72,
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
    u32 isPushOKButton();
    MT_CTSTR getMessage();
    void setInitComment(MT_CTSTR pStr);
    uGUIArisenCardPopPawn();
    virtual ~uGUIArisenCardPopPawn();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateWait();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlDecide(cControl::Message* pMsg);
    u32 evCtrlCursorUD(cControl::Message* pMsg);
    u32 evCtrlCursorLR(cControl::Message* pMsg);
    u32 evCtrlMouseClick(cControl::Message* pMsg);
    void initCommon();
    void updateLineDisp();
    void updateButtonDisp(bool IsFocus);
    void startEditText();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    uGUIBase::cVerticalList* mpCtrl;  // offset: 0x8d8
    u32 mSelectButton;  // offset: 0x8e0
    uGUIBase::cReferenceUIButton mButtonOK;  // offset: 0x8e8
    uGUIBase::cReferenceUIButton mButtonNG;  // offset: 0xa78
    uGUIBase::cReferenceUITextBox mTextBox;  // offset: 0xc08
    bool mIsModeKeyboard;  // offset: 0xd70
    MtString mInitComment;  // offset: 0xd78
public:
    static MyDTI DTI;
};

inline void* uGUIArisenCardPopPawn::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIArisenCardPopPawn::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIArisenCardPopPawn::DTI);
}

inline void uGUIArisenCardPopPawn::startEditText() {
    this->mTextBox.::uGUIBase::cReferenceUITextBox::wakeupKeyboard();
    this->mIsModeKeyboard = true;
    if (this->mpCtrl == nullptr) {
        return;
    }
    this->mpCtrl->::cControl::mCtrlF = this->mpCtrl->::cControl::mCtrlF | 8u;
}
