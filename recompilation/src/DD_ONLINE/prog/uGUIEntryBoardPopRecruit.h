#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIEntryBoardPopRecruit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIEntryBoardPopRecruit : public uGUIsMenuBase
{
public:
    enum PR
    {
        PR_MAIN = 0,
        PR_MAX = 1,
    };
public:
    class MyDTI;
    struct guiInst;
    struct guiObj;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct guiInst
    {
    public:
        cGUIInstNull* Null;  // offset: 0x0
        cGUIInstNull* Null_all;  // offset: 0x8
        cGUIInstNull* Null_select_job;  // offset: 0x10
        cGUIInstAnimation* msg_checkbox03;  // offset: 0x18
        cGUIInstAnimation* checkbox03;  // offset: 0x20
        cGUIInstAnimation* window01;  // offset: 0x28
        cGUIInstNull* Null_checkbox03;  // offset: 0x30
        cGUIInstNull* Null_icon_list01;  // offset: 0x38
        cGUIInstAnimation* fix_job[10];  // offset: 0x40
        cGUIInstAnimation* msg_btn02;  // offset: 0x90
        cGUIInstAnimation* msg_btn03;  // offset: 0x98
    };
public:
    struct guiObj
    {
    public:
        cGUIObjMessage* msg_checkbox_m_checkbox;  // offset: 0x0
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
    uGUIEntryBoardPopRecruit();
    virtual ~uGUIEntryBoardPopRecruit();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setCtrlValid(bool flg);
    void clearCtrl();
private:
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    void calcItemNum();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClick(cControl::Message* msg);
    u32 evCtrlDown(cControl::Message* msg);
private:
    guiInst mDataInst;  // offset: 0x958
    guiObj mDataObj;  // offset: 0x9f8
    rGUI* mpGUIRes;  // offset: 0xa00
    PR mProc;  // offset: 0xa08
    uGUIBase::cReferenceUICheckbox mRefCheckBox;  // offset: 0xa10
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mRefButtons;  // offset: 0xa60
    nDDOUtility::cArray<uGUIBase::cReferenceUIIconButton, 10> mRefIconButtonsPopup;  // offset: 0xd80
    cControl* mpButtonCtrl;  // offset: 0x1230
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x1238
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x1240
    uGUIBase::cHorizontalList* mpLevelCtrl;  // offset: 0x1248
    uGUIBase::cVerticalList* mpClickCtrk;  // offset: 0x1250
    f32 mBtnSize;  // offset: 0x1258
    bool mbCtrlValid;  // offset: 0x125c
    s32 mCheckId;  // offset: 0x1260
    s32 mDecideId;  // offset: 0x1264
    s32 mCancelId;  // offset: 0x1268
public:
    static MyDTI DTI;
    static const s32 JOB_ICON_NUM = 10;
};

inline void* uGUIEntryBoardPopRecruit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* uGUIEntryBoardPopRecruit::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIEntryBoardPopRecruit::DTI)->memAlloc(sz, align, ::uGUIEntryBoardPopRecruit::DTI.::MtDTI::getID());
}

inline void uGUIEntryBoardPopRecruit::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIEntryBoardPopRecruit::DTI)->memFree(p_addr);
}
