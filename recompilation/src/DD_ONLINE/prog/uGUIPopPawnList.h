#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cCharacterData.h"
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

// Declarations
class uGUIPopPawnList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnTalkMotGroupArray = nDDOUtility::cArray<unsigned short, 44>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopPawnList : public uGUIBase
{
public:
    enum PR
    {
        PR_MAIN = 0,
        PR_PULLDOWN = 1,
        PR_PULLDOWN_END = 2,
        PR_STOP = 3,
        PR_NUM = 4,
    };
    enum PULLDOWN_ID
    {
        PULLDOWN_ID_PARTY = 0,
        PULLDOWN_ID_QUEST_SUCCESS = 1,
        PULLDOWN_ID_JOB_LVUP = 2,
        PULLDOWN_ID_PLAYER_DEAD = 3,
        PULLDOWN_ID_WAIT_LOBBY = 4,
        PULLDOWN_ID_WAIT_STAGE = 5,
        PULLDOWN_ID_BATTLE_END = 6,
        PULLDOWN_NUM = 7,
    };
    enum GMD_INDEX
    {
        GMD_DEFAULT = 0,
        GMD_PAWN_EMOTION_NAME = 1,
    };
    enum CONTROL_ID
    {
        CONTROL_V = 0,
        CONTROL_BUTTON = 1,
        CONTROL_NUM = 2,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
    enum POS_V
    {
        POS_V_PULLDOWN_START = 0,
        POS_V_PULLDOWN_END = 6,
        POS_V_BUTTON = 7,
        POS_V_NUM = 8,
    };
    enum BUTTON_ID
    {
        BUTTON_ID_DECIDE = 0,
        BUTTON_ID_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_MOVE = 66,
        INPUTEVENT_DECIDE = 67,
    };
public:
    class MyDTI;
    struct Pulldown;
    struct DATA;
public:
    using Pulldowns = nDDOUtility::cArray<uGUIPopPawnList::Pulldown, 7>;
    using Buttons = nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Pulldown
    {
    public:
        struct Vars;
    public:
        struct Vars
        {
        public:
            cGUIInstAnimation* mpINST_msg_pulldown;  // offset: 0x0
            cGUIInstAnimation* mpINST_mask_pulldown;  // offset: 0x8
            cGUIInstNull* mpINST_Null_pull_scroll;  // offset: 0x10
            cGUIInstNull* mpINST_Null_scroll01;  // offset: 0x18
            cGUIInstAnimation* mpINST_scr_bar;  // offset: 0x20
            cGUIInstAnimation* mpINST_window;  // offset: 0x28
            cGUIInstAnimation* mpINST_cursor;  // offset: 0x30
            cGUIInstAnimation* mpINST_mask_pulldownlist;  // offset: 0x38
            cGUIInstNull* mpINST_Nullscroll01;  // offset: 0x40
            cGUIInstNull* mpINST_Null_list;  // offset: 0x48
            cGUIInstAnimation* mpINST_msg_list;  // offset: 0x50
            cGUIObjMessage* mpOBJ_msg_fix_reaction_m_reaction;  // offset: 0x58
            u32 mMotionGroupNum;  // offset: 0x60
        };
    public:
        Pulldown();
        ~Pulldown();
        void setup(f32 yOffset, uGUIBase* guiBase, cGUIInstNull* pINST_Null, cGUIInstNull* pINST_duplicated);
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x0
        Vars mVars;  // offset: 0x28
        cAIPawnTalkMotGroupArray mMotionGroupArray;  // offset: 0x90
        uGUIBase::cReferenceUIPullDown mPulldown;  // offset: 0xf0
        static const s32 VISIBLE_SIZE = 7;
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null_all;  // offset: 0x0
        cGUIInstNull* mpINST_Null_pulldown;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_title_m_title01;  // offset: 0x10
        cGUIObjMessage* mpOBJ_msg_pawn_m_pawn;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_pawn_m_character;  // offset: 0x20
        cGUIObjMessage* mpOBJ_msg_pawn_m_character00;  // offset: 0x28
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
    uGUIPopPawnList();
    virtual ~uGUIPopPawnList();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void show();
private:
    void updateInit();
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void setupControls();
    void updateFocus();
    u32 evCtrlMoveFocus(cControl::Message* msg);
    void evMoveFocus();
    u32 evCtrlDecide(cControl::Message* msg);
    void evDecide();
    u32 evCtrlCancel(cControl::Message* msg);
    cCharacterData::stPawnData& refPawnData();
    void initPulldownData(s32 pulldownId);
    MT_CTSTR getPawnMotionGroupName(u32 pawnMotionGroupId) const;
    void applySetting();
    void setupInstancesAndObjects();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    PR mProc;  // offset: 0x8d0
    cGUIControlMgr mControlMgr;  // offset: 0x8d8
    PULLDOWN_ID mPulldownId;  // offset: 0xd88
    cCharacterData::stPawnData mDummyPawnData;  // offset: 0xd90
    Pulldowns mPulldowns;  // offset: 0x2700
    Buttons mButtons;  // offset: 0x5800
    DATA mData;  // offset: 0x5b20
public:
    static MyDTI DTI;
};

inline void* uGUIPopPawnList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIPopPawnList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPopPawnList::DTI)->memFree(p_addr);
}
