#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cControl.h"
#include "cUIObject.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cControl;
class cGUIInstance;
class cGUIObject;
class uGUIBase;

// Declarations
class cGUIControlMgr;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cGUIControlMgr : public cUIObject
{
public:
    enum CONTROL_TYPE
    {
        TYPE_V = 0,
        TYPE_H = 1,
        TYPE_SCROLLLIST = 2,
    };
    enum MOVE_PRIO
    {
        MOVE_PRIO_0 = 0,
        MOVE_PRIO_1 = 1,
        MOVE_PRIO_2 = 2,
        MOVE_PRIO_NUM = 3,
        MOVE_PRIO_DEFAULT = 1,
    };
    enum CONTROL_KIND
    {
        KIND_TAB = 0,
        KIND_VLIST = 1,
        KIND_HLIST = 2,
        KIND_SCROLLLIST = 3,
        KIND_NUM = 4,
    };
    enum
    {
        MGR_ID_0 = 0,
        MGR_ID_1 = 1,
        MGR_ID_2 = 2,
        MGR_ID_3 = 3,
        MGR_ID_4 = 4,
        MGR_ID_5 = 5,
        MGR_ID_6 = 6,
        MGR_ID_7 = 7,
        MGR_ID_8 = 8,
        MGR_ID_9 = 9,
        MGR_ID_10 = 10,
        MGR_ID_11 = 11,
        MGR_ID_12 = 12,
        MGR_ID_13 = 13,
        MGR_ID_14 = 14,
        MGR_ID_15 = 15,
        MGR_MAX = 16,
        MGR_AUTO = 16,
        MGR_NO_EMPTY = 255,
    };
public:
    class MyDTI;
    struct stControl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stControl
    {
    public:
        bool mIsRegist;  // offset: 0x0
        cControl* mpCtrl;  // offset: 0x8
        cGUIControlMgr::CONTROL_TYPE mType;  // offset: 0x10
        u32 mItemNum;  // offset: 0x14
        u32 mCategoryId;  // offset: 0x18
        bool mIsActive;  // offset: 0x1c
        bool(MtObject::*mpMsgEventFunc)(cControl::Message*);  // offset: 0x20
        cGUIControlMgr::MOVE_PRIO mPrio;  // offset: 0x30
        bool mIsTmpStop;  // offset: 0x34
        bool mIsChildActive;  // offset: 0x35
        u8 mParentMgrId;  // offset: 0x36
        u8 mActiveChildMgrId;  // offset: 0x37
        s8 mTopOfs;  // offset: 0x38
        s32 mMovePos;  // offset: 0x3c
        uGUIBase::cScrollList* mpScrollList;  // offset: 0x40
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
    void setup(uGUIBase* pParent);
    void moveInput();
    u32 addControl(CONTROL_KIND Kind, u32 MgrId, u32 CategoryId, u32 ItemNum, u32 InitPos);
    u32 addControl(uGUIBase::cScrollList* pScrollList, u32 MgrId, u32 CategoryId);
    u32 addChildControl(u32 ParentMgrId, s32 MovePos, s32 TopOfs, CONTROL_KIND Kind, u32 MgrId, u32 ItemNum, u32 InitPos);
    u32 addChildControl(u32 ParentMgrId, s32 MovePos, s32 TopOfs, uGUIBase::cScrollList* pScrollList, u32 MgrId);
    void addMouseTouchList(u32 MgrId, cGUIInstance* pInst, cGUIObject* pObj, s32 sPos, cGUIObject* pObjMO, u32 uMOType, u32 uAnmType, s32 sClickVol);
    void addMouseTouchListLight(u32 MgrId, cGUIInstance* pInst, cGUIObject* pObj, s32 sPos, s32 sClickVol);
    void setEventCancelCommon(u32 MgrId);
    void setEventStartCommon(u32 MgrId);
    void setEventDecideCommon(u32 MgrId);
    void setEventTabCommon(u32 MgrId);
    void setEventVListCommon(u32 MgrId);
    void setEventHListCommon(u32 MgrId);
    void setCategoryFocus(u32 CategoryId, bool IsActive);
    bool isCategoryFocus(u32 CategoryId);
    bool isFocus(u32 MgrId);
    void offAllFocus();
    void setFocus(u32 MgrId, bool IsActive);
    bool enablePadControls(u32 MgrId);
    void disablePadControls(u32 CategoryId);
    void enablePadControl(u32 MgrId);
    void disablePadControl(u32 MgrId);
    bool isEnablePadControl(u32 MgrId);
    cControl* getControl(const stControl& Control) const;
    cControl* getControl(u32 MgrId) const;
    s32 getCurrentPos(u32 MgrId) const;
    s32 getOldPos(u32 MgrId) const;
    void setCurrentPos(u32 MgrId, s32 Pos);
    s32 getCurrentChildPos(u32 ParentMgrId) const;
    void resetItemNum(u32 MgrId, u32 ItemNum, u32 ResetPos);
    u32 getItemNum(u32 MgrId);
    void offChildPosTransfar();
    void setPrioritizeEarlyEvent(bool);
    void setMovePos(u32 MgrId, s32 movePos);
    cGUIControlMgr();
    virtual ~cGUIControlMgr();
private:
    u32 addControl(CONTROL_TYPE Type, u32 MgrId, u32 CategoryId, u32 ItemNum, u32 InitPos, MOVE_PRIO MovePrio);
    u32 addControl(CONTROL_KIND Kind, u32 MgrId, u32 CategoryId, u32 ItemNum, u32 InitPos, MOVE_PRIO MovePrio);
    u32 addControl(uGUIBase::cScrollList* pScrollList, u32 MgrId, u32 CategoryId, MOVE_PRIO MovePrio);
    u32 getEmptyControl();
    bool isMove(const stControl& Control);
    bool isControlMove(const stControl& Control);
    void manageChildControl(u32 MgrId);
    u32 getPreMoveChild(const stControl& Control);
    void initStartChild(u32 MgrId);
    void afterExecute(stControl& Control);
    void afterChildExecute(stControl& Control);
    void registOrder(u32 MgrId);
    void releaseOrder(u32 MgrId);
private:
    uGUIBase* mpParent;  // offset: 0x8
    bool mIsPrioritizeEarlyEvent;  // offset: 0x10
    bool mIsChildPosTransfar;  // offset: 0x11
    stControl mControl[16];  // offset: 0x18
    u8 mControlOrder[16];  // offset: 0x498
    u32 mControlNum;  // offset: 0x4a8
public:
    static MyDTI DTI;
private:
    static const CONTROL_TYPE mCTKindTable[4];
};
