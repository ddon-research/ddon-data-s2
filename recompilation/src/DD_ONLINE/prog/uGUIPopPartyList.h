#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cCharacterData.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cControl;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIPopPartyList;
class uGUIQuickPartyCancel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopPartyList : public uGUIBase
{
public:
    enum PR
    {
        PR_PLAYER_SEARCH = 0,
        PR_QUICK_PARTY_AREA = 1,
        PR_QUICK_PARTY_MAIN = 2,
        PR_QUICK_PARTY_NEWS = 3,
        PR_QUICK_CANCEL = 4,
        PR_NUM = 5,
    };
    enum PPL_GUIDE_BIT
    {
        PPL_INP_NUM = 1,
        PPL_BIT_MAX = 1,
    };
    enum PULLDOWN_ID
    {
        PULLDOWN_ID_PLAYER_SEARCH_PURPOSE_MAIN = 0,
        PULLDOWN_ID_PLAYER_SEARCH_PLAY_STYLE = 1,
        PULLDOWN_NUM = 2,
    };
    enum NUMBOX_ID
    {
        NUMBOX_ID_LEVEL_LOW = 0,
        NUMBOX_ID_LEVEL_HIGH = 1,
        NUMBOX_NUM = 2,
    };
    enum CHECKBOX_ID
    {
        CHECKBOX_ID_BALANCE_JOB = 0,
        CHECKBOX_ID_BALANCE_LEVEL = 1,
        CHECKBOX_ID_JOB_ALL = 1,
        CHECKBOX_ID_LEADER_OK = 2,
        CHECKBOX_NUM = 3,
    };
    enum CONTROL_ID
    {
        CONTROL_V = 0,
        CONTROL_JOB = 1,
        CONTROL_BUTTON = 2,
        CONTROL_NUM = 3,
    };
    enum VL_PR_PLAYER_SEARCH
    {
        VL_PR_PLAYER_SEARCH_PURPOSE_MAIN = 0,
        VL_PR_PLAYER_SEARCH_PLAY_STYLE = 1,
        VL_PR_PLAYER_SEARCH_JOB_ALL = 2,
        VL_PR_PLAYER_SEARCH_JOB = 3,
        VL_PR_PLAYER_SEARCH_LEVEL_LOW = 4,
        VL_PR_PLAYER_SEARCH_LEVEL_HIGH = 5,
        VL_PR_PLAYER_SEARCH_BUTTON = 6,
        VL_PR_PLAYER_SEARCH_NUM = 7,
    };
    enum VL_PR_QUICK_PARTY
    {
        VL_PR_QUICK_PARTY_BALANCE_JOB = 0,
        VL_PR_QUICK_PARTY_BALANCE_LEVEL = 1,
        VL_PR_QUICK_PARTY_LEADER_OK = 2,
        VL_PR_QUICK_PARTY_BUTTON = 3,
        VL_PR_QUICK_PARTY_NUM = 4,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
    enum BUTTON_ID
    {
        BUTTON_ID_LEFT = 0,
        BUTTON_ID_RIGHT = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        INPUTEVENT_MOVE = 66,
        INPUTEVENT_MOVE_NUMBOX_L = 67,
        INPUTEVENT_MOVE_NUMBOX_R = 68,
        INPUTEVENT_DECIDE = 69,
    };
public:
    class MyDTI;
    struct DATA;
    class cJob;
    class cPulldown;
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
        cGUIInstNull* mpINST_Null_all;  // offset: 0x0
        cGUIInstNull* mpINST_Null_pulldown00;  // offset: 0x8
        cGUIInstNull* mpINST_Null_pulldown02;  // offset: 0x10
        cGUIInstNull* mpINST_Null_job;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_title00_m_title;  // offset: 0x20
        cGUIObjMessage* mpOBJ_msg_pulldown00_m_title;  // offset: 0x28
        cGUIObjMessage* mpOBJ_msg_pulldown02_m_title;  // offset: 0x30
        cGUIObjMessage* mpOBJ_msg_setting00_m_setting;  // offset: 0x38
        cGUIObjMessage* mpOBJ_msg_setting01_m_setting;  // offset: 0x40
    };
public:
    class cJob : public MtObject
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
        cJob();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpSelectJob;  // offset: 0x30
        cGUIInstAnimation* mpSelect;  // offset: 0x38
        cGUIInstAnimation* mpFixJob01;  // offset: 0x40
        uGUIBase::cReferenceUIIconButton mRefIconJob;  // offset: 0x48
        static MyDTI DTI;
    };
public:
    class cPulldown
    {
    public:
        cPulldown();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x0
        uGUIBase::cReferenceUIPullDown mPulldown;  // offset: 0x30
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
    uGUIPopPartyList(PR proc);
    virtual ~uGUIPopPartyList();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
protected:
    bool setProc(PR proc, bool force);
    void updateInit();
    void updateWait();
    void executeFocus();
    void updateExit();
    void setupControls();
    void onChangeNumBox(u32 numboxIndex);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlMove(cControl::Message* msg);
    void evMove();
    u32 evCtrlMoveNumBoxL(cControl::Message* msg);
    void evMoveNumBoxL();
    u32 evCtrlMoveNumBoxR(cControl::Message* msg);
    void evMoveNumBoxR();
    u32 evCtrlDecideStart(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    void evDecide();
    u32 evCtrlCancel(cControl::Message* msg);
    cCharacterData::stSearchFilterSetting& refSetting();
    void applyJobSetting(cCharacterData::stSearchFilterSetting& setting);
protected:
    PR mProc;  // offset: 0x8c8
    DATA mData;  // offset: 0x8d0
    MtTypedArray<cJob> mJobArray;  // offset: 0x918
    nDDOUtility::cArray<cPulldown, 2> mPulldowns;  // offset: 0x940
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mRefButtons;  // offset: 0x15c0
    nDDOUtility::cArray<uGUIBase::cReferenceUICheckbox, 3> mRefCheckBoxs;  // offset: 0x18e0
    nDDOUtility::cArray<uGUIBase::cReferenceUINumBox, 2> mRefNumBoxs;  // offset: 0x19d0
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x1c00
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0x1c98
    cControl* mpButtonCtrl;  // offset: 0x1cc0
    rGUI* mpGUIRes;  // offset: 0x1cc8
    cGUIControlMgr mControlMgr;  // offset: 0x1cd0
    cCharacterData::stSearchFilterSetting mSettingDummy;  // offset: 0x2180
public:
    static MyDTI DTI;
};

class uGUIQuickPartyCancel : public uGUIPopPartyList
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
    uGUIQuickPartyCancel();
    virtual ~uGUIQuickPartyCancel();
    virtual void setup();  // vtable slot 6
    void updateInit();
    void updateWait();
    virtual void moveInput();  // vtable slot 87
    virtual s32 getSMenuCursorY();  // vtable slot 72
public:
    static MyDTI DTI;
};

inline void* uGUIPopPartyList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIPopPartyList::cJob::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIQuickPartyCancel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIPopPartyList::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIPopPartyList::DTI);
}

inline void uGUIPopPartyList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPopPartyList::DTI)->memFree(p_addr);
}

inline void uGUIPopPartyList::cJob::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPopPartyList::cJob::DTI)->memFree(p_addr);
}

inline void uGUIQuickPartyCancel::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIQuickPartyCancel::DTI)->memFree(p_addr);
}
