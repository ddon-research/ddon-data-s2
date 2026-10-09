#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class rGUI;
class rGUIMessage;
class uGUIAnnounce;
class uGUIRetrySelect;
class uGUISystemMsg;

// Declarations
class uGUIRetry;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class uGUIRetry : public uGUIBase
{
public:
    enum
    {
        DIALOG_DECIDE = 0,
        DIALOG_CANCEL = 1,
        DIALOG_NONE = 2,
    };
    enum
    {
        TYPE_DOWN = 0,
        TYPE_REVIVE_PAWN = 1,
        TYPE_REVIVE_PLAYER = 2,
        TYPE_REVIVE_LOST_PAWN = 3,
    };
public:
    class MyDTI;
    struct stItem;
    struct stCount;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stItem
    {
    public:
        stItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimIcon;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimText;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimNum;  // offset: 0x18
        cGUIObjMessage* mpObjMsgText;  // offset: 0x20
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x28
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x30
        bool isEnable;  // offset: 0x38
    };
public:
    struct stCount
    {
    public:
        stCount();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
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
    uGUIRetry();
    virtual ~uGUIRetry();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void initDown();
    void initDownDialog();
    void restartDown();
    void initDialog(MT_CTSTR text, MT_CTSTR analyze);
    void updateDialog();
    void initRevive(u32 type);
    void initReviveDialog();
    void restartRevive();
    void hideRevive();
    void setTimer(s32 timer);
    void setText(u32 index, MT_CTSTR text, MT_CTSTR analyze, bool isDispIcon);
    void setNum(u32 index, u64 num);
    void setEnable(u32 index, bool isEnable);
    void setListSelect(s32 pos);
    u32 getListSelect();
    u32 getConfirmSelect();
    bool isDecide();
    bool isCancel();
    void resetDecideFlag();
    void reqDecideAnim();
private:
    void updateInit();
    void updateExit();
    void updateList();
    void updateConfirm();
    void updateCountDown();
    void updateHide();
    u32 evCtrlListDecide(cControl::Message* msg);
    u32 evCtrlListCancel(cControl::Message* msg);
    u32 evCtrlListMove(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    void setWindowSize(u32 list_num);
    void clearItem();
    void adjustCursor();
    bool isOpenCommunicationShortCut();
    u32 getNeedGPNum();
    bool isHaveTicket();
    void setInstPosY(cGUIInstNull* pInst, f32 pos);
    void setInstFrame(cGUIInstAnimation* pInst, f32 frame);
    void setInstPrio(cGUIInstAnimation* pInst, u32 prio);
    bool isInstVisible(cGUIInstance* pInst);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    MT_CTSTR getDlgMsg(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    cGUIInstNull* mpInstNull;  // offset: 0x8d8
    cGUIInstNull* mpInstNullList;  // offset: 0x8e0
    cGUIInstNull* mpInstNullCount;  // offset: 0x8e8
    cGUIInstAnimation* mpInstAnimWindow;  // offset: 0x8f0
    cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x8f8
    stItem mItem[5];  // offset: 0x900
    stCount mCount[2];  // offset: 0xa40
    uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0xa60
    uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0xbc0
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0xc70
    f32 mListBasePos;  // offset: 0xc78
    u32 mType;  // offset: 0xc7c
    u32 mTimerIndex;  // offset: 0xc80
    s32 mTimer;  // offset: 0xc84
    uGUIAnnounce* mpGUIAnnounce;  // offset: 0xc88
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xc90
    uGUIRetrySelect* mpGUISelect;  // offset: 0xc98
    u32 mDialogResult;  // offset: 0xca0
    bool mIsDecide;  // offset: 0xca4
    bool mIsCancel;  // offset: 0xca5
public:
    static MyDTI DTI;
private:
    static const u32 SELECT_MAX = 5;
    static const u32 COUNT_NUM = 2;
};
