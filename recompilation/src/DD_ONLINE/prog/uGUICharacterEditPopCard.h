#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "nNet.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class rGUI;

// Declarations
class uGUICharacterEditPopCard;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICharacterEditPopCard : public uGUIsMenuBase
{
public:
    enum PR
    {
        PR_DEFAULT = 0,
        PR_PULLDOWN = 1,
    };
    enum UNIT_TYPE
    {
        TYPE_PLAYER = 0,
        TYPE_PAWN = 1,
    };
    enum GMD_TYPE
    {
        GMD_TYPE_JOB = 0,
    };
    enum BUTTON_ID
    {
        BUTTON_DECIDE = 0,
        BUTTON_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum VPOS
    {
        VPOS_PULLDOWN = 0,
        VPOS_BUTTONS = 1,
        VPOS_NUM = 2,
    };
    enum MOUSE_ID
    {
        MOUSE_ID_PULLDOWN = 0,
        MOUSE_ID_DECIDE = 1,
        MOUSE_ID_CANCEL = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_PULLDOWN_OPEN = 68,
        INPUTEVENT_DECIDE_BUTTON = 69,
        INPUTEVENT_CANCEL_BUTTON = 70,
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
    uGUICharacterEditPopCard();
    virtual ~uGUICharacterEditPopCard();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void setUnitType(UNIT_TYPE type);
    nNet::PAWN_SHARE_RANGE getShareRange() const;
protected:
    virtual void updateInit();  // vtable slot 93
    virtual void updateWait();  // vtable slot 96
    virtual void updateExit();  // vtable slot 97
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlDecide(cControl::Message* msg);
    void evDecide();
    u32 evCtrlCancel(cControl::Message* msg);
    void evCancel();
    void evInputPutDownOpen();
    void evInputDecideBottun();
    void evInputCancelBottun();
    u32 evCtrlMouseClick(cControl::Message* msg);
    virtual s32 getSMenuCursorY();  // vtable slot 72
protected:
    rGUI* mpGUIRes;  // offset: 0x958
    uGUIBase::cReferenceUIButton mRefButtons[2];  // offset: 0x960
    uGUIBase::cReferenceUIPullDown mRefPulldown;  // offset: 0xc80
    PR mProc;  // offset: 0x1290
    UNIT_TYPE mUnitType;  // offset: 0x1294
    uGUIBase::cVerticalList* mpCtrlV;  // offset: 0x1298
    uGUIBase::cHorizontalList* mpCtrlH;  // offset: 0x12a0
public:
    static MyDTI DTI;
};

inline void* uGUICharacterEditPopCard::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUICharacterEditPopCard::setUnitType(uGUICharacterEditPopCard::UNIT_TYPE type) {
    this->mUnitType = static_cast<uGUICharacterEditPopCard::UNIT_TYPE>(1);
}

inline void uGUICharacterEditPopCard::evInputPutDownOpen() {
    this->mProc = static_cast<uGUICharacterEditPopCard::PR>(1);
    if (this->mRefPulldown.mIsForbid) {
        return;
    }
    if (this->mRefPulldown.mState != static_cast<uGUIBase::cReferenceUIPullDown::STATE>(0)) {
        return;
    }
    this->mRefPulldown.mState = static_cast<uGUIBase::cReferenceUIPullDown::STATE>(1);
}
