#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cControl.h"
#include "../shared/nDDOUtility.h"
#include "../shared/uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class CDataEntryItem;
class MtAllocator;
class MtDTI;
class MtObject;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class uGUIEntryBoardInfo;

// Declarations
class uGUIEntryBoard;

// Type aliases from DWARF
using CEntryItem = CDataEntryItem;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIEntryBoard : public uGUIsMenuBase
{
public:
    enum PR
    {
        PR_TEST = 0,
        PR_MAX = 1,
    };
    enum PTS_GUIDE_BIT
    {
        PTS_DECIDE = 1,
        PTS_MEMBER = 2,
        PTS_BIT_MAX = 2,
    };
    enum
    {
        INPUTEVENT_CURSOR = 66,
        INPUTEVENT_PAGE_MOVE = 67,
        INPUTEVENT_TOPBTN = 68,
        INPUTEVENT_CHANGE_WINDOW = 69,
        INPUTEVENT_SELECT_LIST = 70,
    };
public:
    class MyDTI;
    class cData;
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
    class cData : public MtObject
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
        cData();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpInstAnim;  // offset: 0x30
        cGUIObjMessage* msg_fix_list_m_name;  // offset: 0x38
        cGUIObjMessage* msg_fix_list_m_comment;  // offset: 0x40
        cGUIObjMessage* msg_fix_list_m_num;  // offset: 0x48
        cGUIObjTexture* msg_fix_list_f_pass;  // offset: 0x50
        cGUIObjPolygon* msg_fix_list_mouseover;  // offset: 0x58
        uGUIBase::cReferenceUIIconJob mRefIconJob;  // offset: 0x60
        bool mIsEnable;  // offset: 0xb8
        static MyDTI DTI;
    };
public:
    struct guiInst
    {
    public:
        cGUIInstNull* Null;  // offset: 0x0
        cGUIInstNull* Null_all;  // offset: 0x8
        cGUIInstAnimation* window;  // offset: 0x10
        cGUIInstAnimation* msg_top;  // offset: 0x18
        cGUIInstAnimation* msg_header;  // offset: 0x20
        cGUIInstAnimation* window_frame;  // offset: 0x28
        cGUIInstAnimation* msg_fix_list;  // offset: 0x30
        cGUIInstAnimation* close_btn;  // offset: 0x38
        cGUIInstAnimation* mouse_collision;  // offset: 0x40
        cGUIInstAnimation* msg_numpager;  // offset: 0x48
        cGUIInstAnimation* msg_btn00;  // offset: 0x50
        cGUIInstAnimation* msg_btn01;  // offset: 0x58
        cGUIInstAnimation* mask;  // offset: 0x60
        cGUIInstNull* Null_scroll;  // offset: 0x68
        cGUIInstNull* Null_list;  // offset: 0x70
        cGUIInstAnimation* cursor;  // offset: 0x78
        cGUIInstAnimation* fix_job;  // offset: 0x80
    };
public:
    struct guiObj
    {
    public:
        cGUIObjMessage* msg_top_m_top00;  // offset: 0x0
        cGUIObjMessage* msg_top_m_top01;  // offset: 0x8
        cGUIObjMessage* msg_header_m_header00;  // offset: 0x10
        cGUIObjMessage* msg_header_m_header01;  // offset: 0x18
        cGUIObjMessage* msg_header_m_header02;  // offset: 0x20
        cGUIObjMessage* msg_Center_m_00;  // offset: 0x28
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
    uGUIEntryBoard();
    virtual ~uGUIEntryBoard();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    bool isItemEnable(u32 index);
    bool isTopBtn();
private:
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    bool isValidLVItem(s32 min, s32 max);
    bool isValidJOBItem(const CEntryItem& item);
    bool isValidIRItem(const CEntryItem& item);
    void evCursor();
    void evPageMove();
    void evChangeWindow();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlCursor(cControl::Message* msg);
    u32 evCtrlTopBtn(cControl::Message* msg);
    u32 evCtrlClick(cControl::Message* msg);
    u32 evCtrlClickSelect(cControl::Message* msg);
    u32 evCtrlPageMove(cControl::Message* msg);
    u32 evCtrlBtnClick(cControl::Message* msg);
    u32 evCtrlWindowClick(cControl::Message* msg);
    bool eventCheckWindow();
public:
    MtTypedArray<cData> mDataArray;  // offset: 0x958
private:
    guiInst mDataInst;  // offset: 0x978
    guiObj mDataObj;  // offset: 0xa00
    rGUI* mpGUIRes;  // offset: 0xa30
    PR mProc;  // offset: 0xa38
    uGUIEntryBoardInfo* mpInfoUnit;  // offset: 0xa40
    bool mIsTopBtn;  // offset: 0xa48
    bool mIsFirst;  // offset: 0xa49
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mRefButtons;  // offset: 0xa50
    uGUIBase::cReferenceUINumPager mRefNumPager;  // offset: 0xd70
    uGUIBase::cReferenceUIVlCursor mRefCursor;  // offset: 0xe20
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xed0
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0xf68
    cControl* mpButtonCtrl;  // offset: 0xfc0
    cControl* mpButtonOtherCtrl;  // offset: 0xfc8
    cControl* mpWindowCtrl;  // offset: 0xfd0
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0xfd8
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0xfe0
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0xfe8
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[2];  // offset: 0xff0
public:
    static MyDTI DTI;
};
