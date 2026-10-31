#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
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
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;

// Declarations
class uGUIEntryBoardInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIEntryBoardInfo : public uGUIsMenuBase
{
public:
    enum CURSOR_STATE
    {
        CURSOR_UNFOCUS = 0,
        CURSOR_FOCUS = 1,
        CURSOR_SELECT = 2,
        CURSOR_STATE_NUM = 3,
    };
    enum PR
    {
        PR_VIEW = 0,
        PR_SELECT = 1,
        PR_POPUP = 2,
        PR_MAX = 3,
    };
    enum DISP_STATE
    {
        DISP_PLAYER = 0,
        DISP_UNLIMITED_RECRUIT = 1,
        DISP_LIMITED_RECRUIT = 2,
        DISP_STATE_NUM = 3,
    };
    enum EBI_GUIDE_BIT
    {
        EBI_RETURN = 1,
        EBI_BIT_MAX = 1,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_CHANGE_WINDOW = 69,
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
        cGUIObjNull* mpNullPointer;  // offset: 0x30
        cGUIObjMessage* mpMsgLv;  // offset: 0x38
        cGUIObjMessage* mpMsgNum;  // offset: 0x40
        cGUIObjMessage* mpMsgName;  // offset: 0x48
        cGUIObjMessage* mpMsgTxt;  // offset: 0x50
        cGUIObjMessage* mpMsgJob;  // offset: 0x58
        cGUIObjPolygon* mpMouseOver;  // offset: 0x60
        cGUIInstAnimation* mpInstAnim;  // offset: 0x68
        cGUIInstAnimation* mpInstIconOnline;  // offset: 0x70
        cGUIInstAnimation* mpInstLeaderIcon;  // offset: 0x78
        uGUIBase::cDupliInstAnim mIconJob;  // offset: 0x80
        uGUIBase::cReferenceUIIconJob mRefIconJob[10];  // offset: 0xa8
        uGUIEntryBoardInfo::CURSOR_STATE mCursorState;  // offset: 0x418
        u32 mCharacterId;  // offset: 0x41c
        bool mbValid;  // offset: 0x420
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
        cGUIInstNull* Null_member;  // offset: 0x20
        cGUIInstAnimation* msg_info;  // offset: 0x28
        cGUIInstAnimation* msg_option;  // offset: 0x30
        cGUIInstAnimation* msg_guide;  // offset: 0x38
        cGUIInstNull* Null_list;  // offset: 0x40
        cGUIInstAnimation* msg_list;  // offset: 0x48
        cGUIInstAnimation* fix_job;  // offset: 0x50
        cGUIInstAnimation* fix_icon_online;  // offset: 0x58
        cGUIInstNull* Null_job;  // offset: 0x60
        cGUIInstAnimation* fix_job0[3];  // offset: 0x68
    };
public:
    struct guiObj
    {
    public:
        cGUIObjMessage* msg_top_m_top00;  // offset: 0x0
        cGUIObjMessage* msg_option_m_header;  // offset: 0x8
        cGUIObjMessage* msg_option_m_option00;  // offset: 0x10
        cGUIObjMessage* msg_option_m_option01;  // offset: 0x18
        cGUIObjMessage* msg_option_m_option02;  // offset: 0x20
        cGUIObjMessage* msg_option_m_option03;  // offset: 0x28
        cGUIObjMessage* msg_option_m_setting00;  // offset: 0x30
        cGUIObjMessage* msg_option_m_setting01;  // offset: 0x38
        cGUIObjMessage* msg_option_m_setting02;  // offset: 0x40
        cGUIObjMessage* msg_option_m_setting03;  // offset: 0x48
        cGUIObjMessage* msg_info_m_txt01;  // offset: 0x50
        cGUIObjMessage* msg_info_m_time;  // offset: 0x58
        cGUIObjMessage* msg_info_m_ir;  // offset: 0x60
        cGUIObjMessage* msg_info_m_ir01;  // offset: 0x68
        cGUIObjMessage* msg_info_m_txt02;  // offset: 0x70
        cGUIObjMessage* msg_info_m_txt03;  // offset: 0x78
        cGUIObjMessage* msg_info_m_txt;  // offset: 0x80
        cGUIObjMessage* msg_info_m_member;  // offset: 0x88
        cGUIObjMessage* msg_info_m_txt0;  // offset: 0x90
        cGUIObjMessage* msg_info_m_lowest;  // offset: 0x98
        cGUIObjTexture* msg_info_m_time_icon;  // offset: 0xa0
        cGUIObjMessage* m_option04;  // offset: 0xa8
        cGUIObjMessage* m_option05;  // offset: 0xb0
        cGUIObjMessage* m_option06;  // offset: 0xb8
        cGUIObjMessage* m_setting04;  // offset: 0xc0
        cGUIObjMessage* m_setting05;  // offset: 0xc8
        cGUIObjMessage* m_setting06;  // offset: 0xd0
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
    uGUIEntryBoardInfo();
    virtual ~uGUIEntryBoardInfo();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    bool setProc(PR proc, bool force);
    PR getProc();
    void updateMember();
    void updatePartyMember();
    bool isReqChangeWindow();
    void reqCancel();
    void setExecuteCtrl(bool flag);
protected:
    virtual void updatePtr();  // vtable slot 17
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    void updateTime(bool time_update);
    void updateItemRank();
    void changePlayerSeq(u8 index, bool mySelf, bool leader, CURSOR_STATE state);
    void changeDispList(u8 index, DISP_STATE state);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void evDecide();
    void evCancel();
    void evAdjustCursor();
    void evChangeWindow();
    u32 evCtrlClick(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlClickWindow(cControl::Message* msg);
public:
    MtTypedArray<cData> mDataArray;  // offset: 0x958
protected:
    guiInst mDataInst;  // offset: 0x978
    guiObj mDataObj;  // offset: 0x9f8
    rGUI* mpGUIRes;  // offset: 0xad0
    PR mProc;  // offset: 0xad8
    s32 mMemberNum;  // offset: 0xadc
    bool mFirst;  // offset: 0xae0
    bool mReqChangeWindow;  // offset: 0xae1
    bool mReqCancel;  // offset: 0xae2
    bool mIsExecuteCtrl;  // offset: 0xae3
    cControl* mpButtonCtrl;  // offset: 0xae8
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0xaf0
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xaf8
    nDDOUtility::cArray<uGUIBase::cReferenceUIIconJob, 3> mRefIconJob2;  // offset: 0xb90
    nDDOUtility::cArray<uGUIBase::cDupliInstance<cGUIInstAnimation*>, 2> mIconJob2;  // offset: 0xc98
    nDDOUtility::cArray<uGUIBase::cDupliInstance<cGUIInstNull*>, 2> mInst2;  // offset: 0xce8
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0xd38
public:
    static MyDTI DTI;
};

inline void uGUIEntryBoardInfo::reqCancel() {
    this->mReqCancel = true;
}

inline void uGUIEntryBoardInfo::evChangeWindow() {
    this->mReqChangeWindow = true;
}
