#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "../../generated/shared/nKeyCustom.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cCharacterData;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTextureSet;
class rGUI;
class rGUIMessage;
class uCharacterSelect;
class uEditSaveLoadFlow;
class uGUIAnnounce;
class uGUISystemMsg;

// Declarations
class uGUICharacterSelect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICharacterSelect : public uGUIsMenuBase
{
    friend class uCharacterSelect;
public:
    enum PR
    {
        PR_SLEEP = 0,
        PR_CHARACTER_SELECT = 1,
        PR_DELETE_SELECT_CHARACTER = 2,
        PR_DELETE_INPUT_CODE = 3,
        PR_DELETE_INPUT_CODE1 = 4,
        PR_DELETE_WAIT = 5,
        PR_DELETE_COMPLETE = 6,
        PR_DELETE_COMPLETE2 = 7,
        PR_DELETE_FAILED = 8,
        PR_ANNOUNCE_WAIT = 9,
        PR_SAVE = 10,
        PR_CLAN_MENU = 11,
        PR_MAX = 12,
    };
    enum END_MODE
    {
        END_MODE_NONE = 0,
        END_MODE_SELECT_CHARACTER = 1,
        END_MODE_NEW_CHARACTER = 2,
        END_MODE_DELETE_CHARACTER = 3,
        END_MODE_EXIT_CANCEL = 4,
        END_MODE_MAX = 5,
    };
    enum EDIT_SAVE_LOAD_ROUTINE
    {
        EDIT_SAVE_LOAD_ROUTINE_INIT = 0,
        EDIT_SAVE_LOAD_ROUTINE_WAIT = 1,
        EDIT_SAVE_LOAD_ROUTINE_END = 2,
    };
    enum CLAN_MENU_ROUTINE
    {
        CLAN_MENU_ROUTINE_INIT = 0,
        CLAN_MENU_ROUTINE_WAIT = 1,
        CLAN_MENU_ROUTINE_END = 2,
    };
    enum SW
    {
        SW_nostatus = 0,
        SW_status = 1,
        SW_nostatus_del = 2,
        SW_status_del = 3,
        SW_popdel00 = 4,
        SW_popdel01 = 5,
        SW_popdel02 = 6,
        SW_END = 7,
        SW_NONE = 8,
    };
    enum
    {
        UPDATE_COURCE_DRAW_FIRST_ON_FLAG = 0,
        UPDATE_COURCE_DRAW_ON_FLAG = 1,
        UPDATE_COURCE_MSG_ON_FLAG = 2,
        UPDATE_COURCE_FLAG_MAX = 3,
    };
    enum
    {
        CHANGE_MENU_DEL_SEL_TO_CHAR = 0,
        CHANGE_MENU_CHAR_SEL_TO_DELETE = 1,
    };
    enum
    {
        GMD_RES_CHARACTER_SELECT = 0,
        GMD_RES_POP_PROFILE = 1,
    };
    enum CHSEL_DEF
    {
        HELP_MSG_DECIDE = 0,
        HELP_MSG_CANCEL = 1,
        HELP_MSG_ZOOM = 2,
        HELP_MSG_CAMERAROLL = 3,
        HELP_MSG_SAVE = 4,
        HELP_MSG_CLAN_MENU = 5,
        HELP_MSG_MAX = 6,
    };
    enum
    {
        BONUS_IDX_MAX = 6,
    };
    enum
    {
        INPUT_EVENT_DECIDE = 66,
        INPUT_EVENT_CANCEL = 67,
        INPUT_EVENT_ERROR = 68,
        INPUT_EVENT_NEW_CREATE = 69,
        INPUT_EVENT_CHARACTER_SEL_DEC = 70,
        INPUT_EVENT_DEL_CHARACTER_SEL_DEC = 71,
        INPUT_EVENT_DELETE_INPUT_CODE_DEC = 72,
        INPUT_EVENT_DELETE_COMPLETE = 73,
        INPUT_EVENT_DELETE_CURSOL_MOVE = 74,
        INPUT_EVENT_SELECT = 75,
        INPUT_EVENT_DECIDE_DELETE_BTN = 76,
        INPUT_EVENT_SAVE = 77,
        INPUT_EVENT_CLAN_MENU = 78,
        INPUT_EVENT_PAGE_MOVE = 79,
    };
public:
    class MyDTI;
    class cGUINameList;
    struct DATA;
    class cHorizonInfo;
    class cGUIGPList;
    class cGUIUnderHelpMsg;
public:
    using cFlag = nDDOUtility::cBitSet<3>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGUINameList : public MtObject
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
        cGUINameList();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpAnim;  // offset: 0x30
        cGUIInstAnimation* mpJob;  // offset: 0x38
        cGUIInstNull* mpPointerNull;  // offset: 0x40
        uGUIBase::cExGUIMessageObj64 mName;  // offset: 0x48
        cGUIObjPolygon* mpMouseover;  // offset: 0xb0
        bool mIsNew;  // offset: 0xb8
        bool mIsEnable;  // offset: 0xb9
        static MyDTI DTI;
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null;  // offset: 0x0
        cGUIInstNull* mpINST_Null_all;  // offset: 0x8
        cGUIInstNull* mpINST_Null_charlist00;  // offset: 0x10
        cGUIInstAnimation* mpINST_fix_job00;  // offset: 0x18
        cGUIInstAnimation* mpINST_msg_charlist00;  // offset: 0x20
        cGUIInstAnimation* mpINST_title;  // offset: 0x28
        cGUIInstAnimation* mpINST_msg_fix_status;  // offset: 0x30
        cGUIInstAnimation* mpINST_fix_job_st;  // offset: 0x38
        cGUIInstNull* mpINST_Null_status;  // offset: 0x40
        cGUIInstNull* mpINST_Null_pointer01;  // offset: 0x48
        cGUIInstAnimation* mpINST_msg_delbtn;  // offset: 0x50
        cGUIInstAnimation* mpINST_msg_fix_bonus00;  // offset: 0x58
        cGUIInstNull* mpINST_Null_cog;  // offset: 0x60
        cGUIInstNull* mpINST_Null_bonus;  // offset: 0x68
        cGUIInstAnimation* mpINST_msg_delmsg;  // offset: 0x70
        cGUIInstAnimation* mpINST_window;  // offset: 0x78
        cGUIInstNull* mpINST_Null_pop;  // offset: 0x80
        cGUIInstAnimation* mpINST_msg_pop00;  // offset: 0x88
        cGUIInstAnimation* mpINST_msg_pop01;  // offset: 0x90
        cGUIInstNull* mpINST_Null_cmd00;  // offset: 0x98
        cGUIInstNull* mpINST_Null_cmd01;  // offset: 0xa0
        cGUIInstAnimation* mpINST_msg_pop02;  // offset: 0xa8
        cGUIInstNull* mpINST_Null_input;  // offset: 0xb0
        cGUIInstAnimation* mpINST_curtain;  // offset: 0xb8
        cGUIInstAnimation* mpINST_msg_cntchar;  // offset: 0xc0
        cGUIInstAnimation* mpINST_msg_pop03;  // offset: 0xc8
        cGUIInstAnimation* mpINST_msg_pop04;  // offset: 0xd0
        cGUIInstNull* mpINST_Null_cmd02;  // offset: 0xd8
        cGUIInstNull* mpINST_Null_deleted;  // offset: 0xe0
        cGUIInstAnimation* mpINST_msg_loadicon00;  // offset: 0xe8
        cGUIInstNull* mpINST_Null_wait;  // offset: 0xf0
        cGUIInstAnimation* mpINST_msg_loadicon01;  // offset: 0xf8
        cGUIInstAnimation* mpINST_msg_numpager;  // offset: 0x100
        cGUIObjMessage* mpOBJ_msg_charlist_m_name;  // offset: 0x108
        cGUIObjPolygon* mpOBJ_msg_charlist_mouseover;  // offset: 0x110
        cGUIObjMessage* mpOBJ_msg_charlist_m_new;  // offset: 0x118
        cGUIObjMessage* mpOBJ_msg_fix_status_m_title00;  // offset: 0x120
        cGUIObjMessage* mpOBJ_msg_fix_status_m_job;  // offset: 0x128
        cGUIObjMessage* mpOBJ_msg_fix_status_m_lv;  // offset: 0x130
        cGUIObjMessage* mpOBJ_msg_fix_status_m_num;  // offset: 0x138
        cGUIObjMessage* mpOBJ_msg_fix_status_m_title01;  // offset: 0x140
        cGUIObjMessage* mpOBJ_msg_fix_status_m_purpose00;  // offset: 0x148
        cGUIObjMessage* mpOBJ_msg_fix_status_m_ptxt00;  // offset: 0x150
        cGUIObjMessage* mpOBJ_msg_fix_status_m_purpose01;  // offset: 0x158
        cGUIObjMessage* mpOBJ_msg_fix_status_m_ptxt01;  // offset: 0x160
        cGUIObjMessage* mpOBJ_msg_fix_status_m_style;  // offset: 0x168
        cGUIObjMessage* mpOBJ_msg_fix_status_m_ptxt02;  // offset: 0x170
        cGUIObjMessage* mpOBJ_msg_fix_status_m_party;  // offset: 0x178
        cGUIObjMessage* mpOBJ_msg_fix_status_m_party03;  // offset: 0x180
        cGUIObjMessage* mpOBJ_msg_fix_status_m_title02;  // offset: 0x188
        cGUIObjTextureSet* mpOBJ_msg_fix_status_frame04;  // offset: 0x190
        cGUIObjMessage* mpOBJ_msg_fix_status_m_txt07;  // offset: 0x198
        cGUIObjMessage* mpOBJ_msg_fix_status_m_ptxt04;  // offset: 0x1a0
        cGUIObjMessage* mpOBJ_msg_fix_status_m_clan00;  // offset: 0x1a8
        cGUIObjMessage* mpOBJ_msg_fix_status_m_txt00;  // offset: 0x1b0
        cGUIObjMessage* mpOBJ_msg_fix_status_m_clan01;  // offset: 0x1b8
        cGUIObjMessage* mpOBJ_msg_fix_status_m_txt01;  // offset: 0x1c0
        cGUIObjMessage* mpOBJ_msg_delbtn_m_del;  // offset: 0x1c8
        cGUIObjPolygon* mpOBJ_msg_delbtn_mouseover;  // offset: 0x1d0
        cGUIObjMessage* mpOBJ_msg_delmsg_m_text00;  // offset: 0x1d8
        cGUIObjMessage* mpOBJ_msg_delmsg_m_text01;  // offset: 0x1e0
        cGUIObjMessage* mpOBJ_msg_pop00_m_title;  // offset: 0x1e8
        cGUIObjMessage* mpOBJ_msg_pop01_m_text00;  // offset: 0x1f0
        cGUIObjMessage* mpOBJ_msg_pop01_m_text01;  // offset: 0x1f8
        cGUIObjMessage* mpOBJ_msg_pop01_m_text02;  // offset: 0x200
        cGUIObjMessage* mpOBJ_msg_pop02_m_text;  // offset: 0x208
        cGUIObjMessage* mpOBJ_msg_cntchar_m_cnt;  // offset: 0x210
        cGUIObjMessage* mpOBJ_msg_pop03_m_name;  // offset: 0x218
        cGUIObjMessage* mpOBJ_msg_pop03_m_text;  // offset: 0x220
        cGUIObjMessage* mpOBJ_msg_pop04_m_text;  // offset: 0x228
    };
public:
    class cHorizonInfo : public MtObject
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
        cHorizonInfo();
        virtual ~cHorizonInfo() {}
    public:
        s32 mMax;  // offset: 0x8
        s32 mNow;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cGUIGPList : public MtObject
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
        cGUIGPList();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpInstAnm;  // offset: 0x30
        cGUIObjMessage* mpMsgTitle;  // offset: 0x38
        cGUIObjMessage* mpMsgSub;  // offset: 0x40
        cGUIObjMessage* mpMsgLimit;  // offset: 0x48
        static MyDTI DTI;
    };
public:
    class cGUIUnderHelpMsg : public MtObject
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
        cGUIUnderHelpMsg();
    public:
        uGUIBase::cDupliInstAnim mInst;  // offset: 0x8
        cGUIObjMessage* mpMsgKey;  // offset: 0x30
        cGUIObjMessage* mpMsg;  // offset: 0x38
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
    uGUICharacterSelect();
    virtual ~uGUICharacterSelect();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void adjustScale();  // vtable slot 84
    void updateListDraw();
    bool isSafeCharacterData();
    void wakeup();
    void sleep();
    bool isSleep();
    END_MODE getEndMode();
    void setCharacterData(cCharacterData* * p);
    void setCharacterDataNum(s32* p);
    s32 getSelectCharaIndex();
    void setIsWakeup(bool flg);
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
private:
    void updateRight(s32 idx);
    void updateCameraForbit(bool isDisActive);
    void updateBonusCource();
    void updateBonusData();
    void updateSave();
    void updateClanMenu();
    void setProc(PR proc, SW sw);
    cControl* getCurrentVControl(PR proc, bool force);
    cControl* getPastVControl(PR proc, bool force);
    s32 getCurrentVPos(bool force);
    s32 getCurrentVPosOld(bool force);
    void setCurrentVPosZeroAll();
    void setCurrentVPos(s32 idx, PR proc);
    void createNameList(u32 num);
    void createHorizonInfo(u32 num);
    void createAnnounce();
    void adjustControl();
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateError();
    void updateExit();
    u32 evCtrlVMove(cControl::Message* msg);
    u32 evCtrlVMoveEx(cControl::Message* msg);
    u32 evCtrlHMove(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlDecideDeleteButton(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlTopButton(cControl::Message* msg);
    u32 evCtrlPageMove(cControl::Message* msg);
    void evPageMove();
    void initUnderHelp();
    void addUnderHelp(nKeyCustom::KB_CUSTOM type, MT_CTSTR msg);
    void updateUnderHelp();
private:
    MtTypedArray<cGUINameList> mGUINameListArray;  // offset: 0x958
    DATA mData;  // offset: 0x978
    uGUIAnnounce* mpAnnounce;  // offset: 0xba8
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xbb0
    PR mProc;  // offset: 0xbb8
    rGUI* mpGUIRes;  // offset: 0xbc0
    rGUIMessage* mpGmdDialog;  // offset: 0xbc8
    END_MODE mEndMode;  // offset: 0xbd0
    END_MODE mErrMode;  // offset: 0xbd4
    nDDOUtility::cArray<uGUIBase::cVerticalList*, 12> mpVCtrls;  // offset: 0xbd8
    uGUIBase::cVerticalList* mpSubVCtrl;  // offset: 0xc38
    f32 mTimer;  // offset: 0xc40
    MtTypedArray<cHorizonInfo> mHorizonInfos;  // offset: 0xc48
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0xc68
    MtTypedArray<cGUIGPList> mGUIGPListArray;  // offset: 0xc70
    cFlag mUpdateCourceFlag;  // offset: 0xc90
    MtTypedArray<uGUIBase::cReferenceUIChargesInfo> mRefChargesInfo;  // offset: 0xc98
    uGUIBase::cExGUIMessageObj64 mDelBtnName;  // offset: 0xcb8
    s32 mSelectCharaIndex;  // offset: 0xd20
    cCharacterData* * mppCharacterData;  // offset: 0xd28
    s32* mpCharacterDataNum;  // offset: 0xd30
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 3> mRefButtons;  // offset: 0xd38
    uGUIBase::cReferenceUITextBox mRefTextBox;  // offset: 0x11e8
    uGUIBase::cReferenceUIVlCursor mRefCursor;  // offset: 0x1350
    uGUIBase::cReferenceUINumPager mRefNumPager;  // offset: 0x1400
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0x14a8
    s32 mOldPos;  // offset: 0x14b0
    bool mIsLoading;  // offset: 0x14b4
    bool mIsWakeup;  // offset: 0x14b5
    MtStringEx<32> mNeedDelCode;  // offset: 0x14b8
    cFlag mChangeMenuFlag;  // offset: 0x14dc
    s32 mVarGap;  // offset: 0x14e0
    s32 mVarMargin;  // offset: 0x14e4
    uEditSaveLoadFlow* mpSaveLoadFlow;  // offset: 0x14e8
    EDIT_SAVE_LOAD_ROUTINE mSaveLoadRno;  // offset: 0x14f0
    CLAN_MENU_ROUTINE mClanMenuRno;  // offset: 0x14f4
    u32 mSelectBonusPage;  // offset: 0x14f8
    MtTypedArray<cGUIUnderHelpMsg> mGUIUnderHelpMsgArray;  // offset: 0x1500
public:
    static MyDTI DTI;
};

inline void* uGUICharacterSelect::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUICharacterSelect::END_MODE uGUICharacterSelect::getEndMode() {
    return this->mEndMode;
}

inline void uGUICharacterSelect::setCharacterData(cCharacterData* * p) {
    this->mppCharacterData = p;
}

inline void uGUICharacterSelect::setCharacterDataNum(s32* p) {
    this->mpCharacterDataNum = p;
}

inline s32 uGUICharacterSelect::getSelectCharaIndex() {
    return this->mSelectCharaIndex;
}

inline void* uGUICharacterSelect::cGUINameList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharacterSelect::cHorizonInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUICharacterSelect::cHorizonInfo::cHorizonInfo() {
    this->mMax = 1;
    this->mNow = 0;
}

inline void* uGUICharacterSelect::cGUIGPList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharacterSelect::cGUIUnderHelpMsg::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUICharacterSelect::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUICharacterSelect::DTI);
}

inline void uGUICharacterSelect::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUICharacterSelect::DTI)->memFree(p_addr);
}

inline void uGUICharacterSelect::cGUINameList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUICharacterSelect::cGUINameList::DTI)->memFree(p_addr);
}

inline void* uGUICharacterSelect::cHorizonInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUICharacterSelect::cHorizonInfo::DTI)->memAlloc(sz, align, ::uGUICharacterSelect::cHorizonInfo::DTI.::MtDTI::getID());
}

inline void uGUICharacterSelect::cHorizonInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUICharacterSelect::cHorizonInfo::DTI)->memFree(p_addr);
}

inline void uGUICharacterSelect::cGUIGPList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUICharacterSelect::cGUIGPList::DTI)->memFree(p_addr);
}

inline void uGUICharacterSelect::cGUIUnderHelpMsg::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUICharacterSelect::cGUIUnderHelpMsg::DTI)->memFree(p_addr);
}
