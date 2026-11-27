#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIEntryBoardRecruit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIEntryBoardRecruit : public uGUIsMenuBase
{
public:
    enum PR
    {
        PR_MAIN = 0,
        PR_MAX = 1,
    };
    enum EBR_GUIDE_BIT
    {
        EBR_INP_NUM = 1,
        EBR_BIT_MAX = 1,
    };
    enum JOB_ROLE
    {
        ROLE_00 = 0,
        ROLE_01 = 1,
        ROLE_02 = 2,
        ROLE_MAX = 3,
    };
    enum
    {
        TYPE_EQUIP_AVG = 0,
        TYPE_MAIN_WEAPON = 1,
        PULL_DOWN_MAX = 2,
    };
    enum
    {
        INPUTEVENT_CURSOR_LEFT = 66,
        INPUTEVENT_CURSOR_RIGHT = 67,
        INPUTEVENT_DECIDE = 68,
        INPUTEVENT_NUMBOX_START = 69,
        INPUTEVENT_NUMBOX_MOVE_L = 70,
        INPUTEVENT_NUMBOX_MOVE_R = 71,
        INPUTEVENT_IR_LEVEL_START = 72,
        INPUTEVENT_IR_LEVEL_L = 73,
        INPUTEVENT_IR_LEVEL_R = 74,
        INPUTEVENT_PULLDOWN_OPEN = 75,
        INPUTEVENT_PULLDOWN_WAIT = 76,
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
        cGUIInstAnimation* mouse_collision;  // offset: 0x0
        cGUIInstAnimation* msg_btn00;  // offset: 0x8
        cGUIInstAnimation* msg_btn01;  // offset: 0x10
        cGUIInstAnimation* msg_numbox00;  // offset: 0x18
        cGUIInstAnimation* msg_numbox01;  // offset: 0x20
        cGUIInstNull* Null_icon_job[7];  // offset: 0x28
        cGUIInstAnimation* fix_job[7];  // offset: 0x60
        cGUIInstAnimation* msg_btn_emphasis;  // offset: 0x98
        cGUIInstAnimation* checkbox02;  // offset: 0xa0
        cGUIInstAnimation* msg_checkbox00;  // offset: 0xa8
        cGUIInstAnimation* checkbox00;  // offset: 0xb0
        cGUIInstAnimation* msg_checkbox01;  // offset: 0xb8
        cGUIInstAnimation* checkbox01;  // offset: 0xc0
        cGUIInstAnimation* msg_textbox00;  // offset: 0xc8
        cGUIInstAnimation* msg_textbox01;  // offset: 0xd0
        cGUIInstAnimation* msg_txt;  // offset: 0xd8
        cGUIInstAnimation* checkbox03;  // offset: 0xe0
        cGUIInstAnimation* msg_numbox;  // offset: 0xe8
        cGUIInstNull* Null_irjob;  // offset: 0xf0
        cGUIInstAnimation* checkbox0;  // offset: 0xf8
        cGUIInstAnimation* checkbox1;  // offset: 0x100
        cGUIInstAnimation* checkbox2;  // offset: 0x108
        cGUIInstAnimation* fix_job2[3];  // offset: 0x110
    };
public:
    struct guiObj
    {
    public:
        cGUIObjMessage* msg_top_m_top00;  // offset: 0x0
        cGUIObjMessage* msg_header_m_header00;  // offset: 0x8
        cGUIObjMessage* msg_checkbox_m_checkbox[3];  // offset: 0x10
        cGUIObjMessage* msg_jobnum_m_txt[7];  // offset: 0x28
        cGUIObjMessage* msg_txt_m_txt;  // offset: 0x60
        cGUIObjMessage* msg_txt_m_txt01;  // offset: 0x68
        cGUIObjMessage* msg_txt_m_txt0;  // offset: 0x70
        cGUIObjMessage* msg_txt_m_txt1;  // offset: 0x78
        cGUIObjMessage* msg_checkbox03;  // offset: 0x80
        cGUIObjMessage* msg_checkbox[3];  // offset: 0x88
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
    uGUIEntryBoardRecruit();
    virtual ~uGUIEntryBoardRecruit();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void iconRefresh();
    void cancelTextBox();
    bool isEndTextBox();
    void hidePopRecruit();
    void setupPopRecruit(s32 recruitNo);
    void updatePopRecruit();
private:
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    bool isMoveCtrl();
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    void setupRecruitMemberNum();
    bool isExistEditTextBox();
    bool isExistEditNumBox();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void itemSizeReset();
    void onChangeLevelMin();
    void onChangeLevelMax();
    void onChangeIrLevel();
    void onCloseTextBox(s32 textboxInputType);
    void itemRankMinSet();
    void evDecide();
    void evCursorLeft();
    void evCursorRight();
    void evNumBoxStart();
    void evNumBoxMoveL();
    void evNumBoxMoveR();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlUpDown(cControl::Message* msg);
    u32 evCtrlCursorLeft(cControl::Message* msg);
    u32 evCtrlCursorRight(cControl::Message* msg);
    u32 evCtrlClick(cControl::Message* msg);
    u32 evCtrlOver(cControl::Message* msg);
    u32 evCtrlOut(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlNumBoxMoveL(cControl::Message* msg);
    u32 evCtrlNumBoxMoveR(cControl::Message* msg);
private:
    guiInst mDataInst;  // offset: 0x958
    guiObj mDataObj;  // offset: 0xa80
    rGUI* mpGUIRes;  // offset: 0xb20
    PR mProc;  // offset: 0xb28
    MtVector3 mPopRecruitOffset;  // offset: 0xb30
    u32 mRecruitNum;  // offset: 0xb40
    s32 mDrawRecruitNo;  // offset: 0xb44
    s32 mSelectRecruitNo;  // offset: 0xb48
    bool mIsJobDecide;  // offset: 0xb4c
    s32 mTextBoxInputType;  // offset: 0xb50
    u32 mItemRankMin;  // offset: 0xb54
    bool mIsPullDown;  // offset: 0xb58
    nDDOUtility::cArray<uGUIBase::cReferenceUINumBox, 2> mRefNumBoxs;  // offset: 0xb60
    nDDOUtility::cArray<uGUIBase::cReferenceUITextBox, 2> mRefTextBoxs;  // offset: 0xd90
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mRefButtons;  // offset: 0x1060
    nDDOUtility::cArray<uGUIBase::cReferenceUICheckbox, 3> mRefCheckBoxs;  // offset: 0x1380
    uGUIBase::cReferenceUIButton2 mRefButton2;  // offset: 0x1470
    nDDOUtility::cArray<uGUIBase::cReferenceUISimpleBtn, 7> mRefJobButton;  // offset: 0x1600
    nDDOUtility::cArray<uGUIBase::cReferenceUIIconJob, 7> mRefIconJob;  // offset: 0x1fd8
    uGUIBase::cReferenceUINumBox mRefNumBox;  // offset: 0x2240
    uGUIBase::cReferenceUICheckbox mRefCheckBox;  // offset: 0x2358
    nDDOUtility::cArray<uGUIBase::cReferenceUICheckbox, 3> mRefCheckBoxs2;  // offset: 0x23a8
    nDDOUtility::cArray<uGUIBase::cReferenceUIIconJob, 3> mRefIconJob2;  // offset: 0x2498
    uGUIBase::cReferenceUIPullDown mRefPullDown;  // offset: 0x25a0
    cControl* mpButtonCtrl;  // offset: 0x2bb0
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x2bb8
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x2bc0
    uGUIBase::cVerticalList* mpClickCtrk;  // offset: 0x2bc8
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x2bd0
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x2c68
public:
    static MyDTI DTI;
    static const u32 RECRUIT_MAX = 7;
};

inline void* uGUIEntryBoardRecruit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "sMenu.h"

inline void uGUIEntryBoardRecruit::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIEntryBoardRecruit::DTI)->memFree(p_addr);
}

inline void uGUIEntryBoardRecruit::hidePopRecruit() {
    (::sMenu::mpInstance)->mMenuEntryBoardItem.mRecruitNo = -1;
    this->mDrawRecruitNo = -1;
    this->mSelectRecruitNo = -1;
}
