#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "Protocol/PacketData/SupportPoint.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class CDataSupportRate;
class MtAllocator;
class MtDTI;
class MtObject;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
namespace nJobParam { class cJobInfo; }
class rGUI;
class uGUISystemMsg;

// Declarations
class uGUIPopPawnPoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using SupportRateVec = MtTypedArray<CDataSupportRate>;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIPopPawnPoint : public uGUIBase
{
public:
    enum PR
    {
        PR_NONE = 0,
        PR_INIT = 1,
        PR_EDIT = 2,
        PR_EDIT_JOB = 3,
        PR_EDIT_JOBPOINT = 4,
        PR_POINT_WAIT = 5,
    };
    enum EBR_GUIDE_BIT
    {
        EBR_INP_NUM = 1,
        EBR_BIT_MAX = 1,
    };
    enum BTN_TYPE
    {
        OK_BTN = 0,
        CANCEL_BTN = 1,
        BTN_NUM = 2,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_MOVE = 66,
        INPUTEVENT_DECIDE = 67,
        INPUTEVENT_START = 68,
        INPUTEVENT_CANCEL = 69,
        INPUTEVENT_CURSOR_V = 70,
        INPUTEVENT_CURSOR_H = 71,
        INPUTEVENT_NUMBOX_L = 72,
        INPUTEVENT_NUMBOX_R = 73,
        INPUTEVENT_MOUSE = 74,
    };
public:
    class MyDTI;
    struct stMain;
    struct stVariable;
    struct stReference;
    struct stCalcSet;
    struct stPointSet;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stMain
    {
    public:
        cGUIInstNull* inst_null_pulldown;  // offset: 0x0
        cGUIInstAnimation* inst_msg_btn00;  // offset: 0x8
        cGUIInstAnimation* inst_msg_btn01;  // offset: 0x10
        cGUIInstAnimation* inst_msg_numbox[2];  // offset: 0x18
        cGUIInstAnimation* inst_msg_top;  // offset: 0x28
        cGUIInstAnimation* inst_msg_pown;  // offset: 0x30
        cGUIInstAnimation* inst_msg_point;  // offset: 0x38
        cGUIInstAnimation* inst_msg_pulldown;  // offset: 0x40
        cGUIInstAnimation* inst_msg_list;  // offset: 0x48
        cGUIObjMessage* obj_msg_top_m_top;  // offset: 0x50
        cGUIObjMessage* obj_msg_pawn_m_name;  // offset: 0x58
        cGUIObjMessage* obj_msg_point_m_point;  // offset: 0x60
        cGUIObjMessage* obj_msg_point_m_num;  // offset: 0x68
        cGUIObjMessage* obj_msg_point_m_sp;  // offset: 0x70
        cGUIObjMessage* obj_msg_list_m_header;  // offset: 0x78
        cGUIObjMessage* obj_msg_list_m_ratio[2];  // offset: 0x80
        cGUIObjMessage* obj_msg_list_m_equal;  // offset: 0x90
        cGUIObjMessage* obj_msg_list_m_pt;  // offset: 0x98
        cGUIObjMessage* obj_msg_list_m_sp;  // offset: 0xa0
        cGUIObjMessage* obj_msg_list_m_num[2];  // offset: 0xa8
    };
public:
    struct stVariable
    {
    public:
        s32 param_ofst_list;  // offset: 0x0
    };
public:
    struct stReference
    {
    public:
        uGUIBase::cReferenceUIButton mBtn[2];  // offset: 0x0
        uGUIBase::cReferenceUIIconJob mJobIcon;  // offset: 0x320
        uGUIBase::cReferenceUIPullDownSkill mPulldown;  // offset: 0x380
        uGUIBase::cReferenceUINumBox mNumBox[2];  // offset: 0xa10
        uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xc40
        uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0xcd8
    };
public:
    struct stPointSet
    {
    public:
        stPointSet();
    public:
        u32 mNow;  // offset: 0x0
        u32 mOld;  // offset: 0x4
    };
public:
    struct stCalcSet
    {
    public:
        uGUIPopPawnPoint::stPointSet mRate;  // offset: 0x0
        uGUIPopPawnPoint::stPointSet mPoint;  // offset: 0x8
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
    bool checkAdjustPointSet(stPointSet& set);
    uGUIPopPawnPoint();
    virtual ~uGUIPopPawnPoint();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
private:
    virtual void updatePtr();  // vtable slot 17
    void updateInit();
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    void setProc(PR proc);
    void adjustCursor();
    void resetCtrlNum(s32 pos);
    void setupPulldown();
    void updatePulldown();
    void updateNumBox();
    void updatePoint();
    void updatePointDisp();
    const nJobParam::cJobInfo* getJobInfo(u32 job_id);
    bool setupPulldownJob();
    void setupRateData();
    virtual void moveEvent();  // vtable slot 88
    void evDecide();
    void evStart();
    void evCancel();
    void evCursorV();
    void evCursorH();
    void evNumBoxL();
    void evNumBoxR();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursorV(cControl::Message* msg);
    u32 evCtrlAdjustCursorH(cControl::Message* msg);
    u32 evCtrlMouse(cControl::Message* msg);
    u32 evCtrlNumBoxL(cControl::Message* msg);
    u32 evCtrlNumBoxR(cControl::Message* msg);
public:
    void setPawnId(u32 id);
    void settingSupportPointUseInfo();
    u32 getConfirmationMessage(MT_STR in_str, u32* analyze);
    u32 getResultMessage(MT_STR in_str, u32* analyze);
    void resetEdit();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpInstNull;  // offset: 0x8d0
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x8d8
    cControl* mpButtonCtrl;  // offset: 0x8e0
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x8e8
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x8f0
    uGUIBase::cHorizontalList* mpNumBoxCtrl;  // offset: 0x8f8
    stMain mMain;  // offset: 0x900
    stVariable mVariable;  // offset: 0x9b8
    stReference mReference;  // offset: 0x9c0
    stCalcSet mCalcSetPoint[2];  // offset: 0x16c0
    stPointSet mPossessionPoint;  // offset: 0x16e0
    stPointSet mUsePoint;  // offset: 0x16e8
    stPointSet mRemainPoint;  // offset: 0x16f0
    PR mProc;  // offset: 0x16f8
    u32 mPawnId;  // offset: 0x16fc
    nDDOUtility::cArray<unsigned int, 10> mJobArray;  // offset: 0x1700
    u8 mJobId;  // offset: 0x1728
    u32 mPawnPointMax;  // offset: 0x172c
    SupportRateVec mSupportRateVec;  // offset: 0x1730
public:
    static MyDTI DTI;
};

inline void* uGUIPopPawnPoint::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUIPopPawnPoint::setupPulldown() {
    if (this->mReference.mPulldown.::uGUIBase::cReferenceUIPullDown::mIsForbid) {
        return;
    }
    if (this->mReference.mPulldown.::uGUIBase::cReferenceUIPullDown::mState != static_cast<uGUIBase::cReferenceUIPullDown::STATE>(0)) {
        return;
    }
    this->mReference.mPulldown.::uGUIBase::cReferenceUIPullDown::mState = static_cast<uGUIBase::cReferenceUIPullDown::STATE>(1);
}

inline void uGUIPopPawnPoint::evCancel() {
    this->::uGUIBase::mSMENUcancel = true;
}

inline void uGUIPopPawnPoint::setPawnId(u32 id) {
    this->mPawnId = id;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIPopPawnPoint::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPopPawnPoint::DTI)->memFree(p_addr);
}
