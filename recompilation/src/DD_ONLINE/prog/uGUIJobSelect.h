#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "../../generated/shared/nHuman.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
struct MT_ENUM;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class rGUI;
class rGUIMessage;
class uGUISystemMsg;

// Declarations
class uGUIJobSelect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIJobSelect : public uGUIsMenuBase
{
public:
    enum PR
    {
        PR_SELECT = 0,
        PR_WARNING = 1,
        PR_END = 2,
        PR_MAX = 3,
    };
    enum EDIT_DIALOG_ROUTINE
    {
        EDIT_DIALOG_INIT = 0,
        EDIT_DIALOG_WAIT = 1,
        EDIT_DIALOG_END = 2,
    };
    enum EDIT_GMD_SECOND_TYPE
    {
        EDIT_GMD_TYPE_SECOND_SKILL = 0,
        EDIT_GMD_TYPE_SECOND_WEAPON_CATEGORY = 1,
        EDIT_GMD_TYPE_SECOND_NUM = 2,
    };
    enum EDIT_GMD_TYPE
    {
        EDIT_GMD_TYPE_JOB_INFO = 0,
        EDIT_GMD_TYPE_JOB = 1,
        EDIT_GMD_TYPE_HELP = 2,
        EDIT_GMD_TYPE_DIALOG = 3,
        EDIT_GMD_TYPE_NUM = 4,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_DECEIDE_JOB = 67,
        INPUTEVENT_SELECT_JOB = 68,
        INPUTEVENT_CANCEL_JOB = 69,
    };
public:
    class MyDTI;
    class cItem;
    struct DATA;
    class cJobInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cItem : public MtObject
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
        cItem();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        uGUIBase::cReferenceUIIconJob mJob;  // offset: 0x30
        cGUIInstAnimation* mpInstAnim;  // offset: 0x88
        cGUIObjMessage* mpMsg;  // offset: 0x90
        cGUIObjPolygon* mpObjJobMouseOver;  // offset: 0x98
        static MyDTI DTI;
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null;  // offset: 0x0
        cGUIInstAnimation* mpINST_msg_info;  // offset: 0x8
    };
public:
    class cJobInfo : public MtObject
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
        cJobInfo();
        cJobInfo(u32 jobID, u32 gmdIdx);
    public:
        u32 mJobID;  // offset: 0x8
        u32 mJobNameGmdIdx;  // offset: 0xc
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
    uGUIJobSelect();
    virtual ~uGUIJobSelect();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void move();  // vtable slot 9
    bool setProc(PR proc, bool force);
    bool isFlowAnimEnd();
    nHuman::JOB_ENUM getSelectJob();
    MT_CTSTR getJobName(s32 idx);
    nHuman::JOB_ENUM getJobIdx(s32 idx);
    s32 getJobLocalIdx(s32 idx);
    s32 getListNum();
private:
    MT_CTSTR getGMDMain(u32);
    MT_CTSTR getGMDHelp(u32);
    MT_CTSTR getGMDDlg(u32);
    void setupInstObj();
    void setupCtrl();
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    u32 evCtrlVMove(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    void evInputDecideJob();
    void evInputSelectJob();
    void evInputCancelJob();
    bool manageEnv();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void moveDialog();
    bool loadGMDSecond(MT_CTSTR searchName, EDIT_GMD_SECOND_TYPE type);
    void releaseGMDSecond();
    MT_CTSTR getGMDMsgSecond(u32 enumID, EDIT_GMD_SECOND_TYPE type);
public:
    MtTypedArray<cItem> mItemArray;  // offset: 0x958
private:
    DATA mData;  // offset: 0x978
    rGUI* mpGUIRes;  // offset: 0x988
    PR mProc;  // offset: 0x990
    cGUIObjMessage* mpOBJ_msg_info_m_arms00;  // offset: 0x998
    cGUIObjMessage* mpOBJ_msg_info_m_arms01;  // offset: 0x9a0
    cGUIObjMessage* mpOBJ_msg_info_m_caption;  // offset: 0x9a8
    cGUIObjMessage* mpOBJ_msg_info_m_header0;  // offset: 0x9b0
    cGUIObjMessage* mpOBJ_msg_info_m_name0;  // offset: 0x9b8
    cGUIObjMessage* mpOBJ_msg_info_m_top;  // offset: 0x9c0
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x9c8
    EDIT_DIALOG_ROUTINE mEditDialogRno;  // offset: 0x9d0
    uGUIBase::cReferenceUIVlCursor mRefCursor;  // offset: 0x9e0
    cControl* mpButtonCtrl;  // offset: 0xa90
    uGUIBase::cVerticalList* mpCtrlV;  // offset: 0xa98
    nDDOUtility::cArray<rGUIMessage*, 2> mpGUIMsgsSecond;  // offset: 0xaa0
public:
    static MyDTI DTI;
    static const MT_ENUM JOB_MT_ENUM[];
    static const s32 JOB_ID_LIST[];
};

inline void* uGUIJobSelect::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUIJobSelect::evInputDecideJob() {
    this->mEditDialogRno = static_cast<uGUIJobSelect::EDIT_DIALOG_ROUTINE>(0);
}

inline void* uGUIJobSelect::cItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIJobSelect::cJobInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIJobSelect::cJobInfo::cJobInfo() {
    this->mJobID = 0;
    this->mJobNameGmdIdx = 0;
}
