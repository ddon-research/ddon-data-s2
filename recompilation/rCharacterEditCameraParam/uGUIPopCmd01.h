#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
#include "uGUIPopBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtSize;
class MtString;
class MtVector3;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class rGUI;
class uGUIBase;

// Declarations
class uGUIPopCmd01;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopCmd01 : public uGUIPopBase
{
public:
    enum EXEC_MODE
    {
        EXEC_MODE_DEFAULT = 0,
        EXEC_MODE_SYSTEM_MENU = 1,
    };
    enum POP_END_TYPE
    {
        POP_END_TYPE_NONE = 0,
        POP_END_TYPE_CANCEL = 1,
        POP_END_TYPE_DECIDE = 2,
        POP_END_TYPE_MAX = 3,
    };
    enum
    {
        INPUTEVENT_CANCEL = 66,
        INPUTEVENT_DECIDE = 67,
        INPUTEVENT_MOVE = 68,
    };
public:
    class MyDTI;
    class cData;
    class cItem;
    struct stEventFunc;
public:
    using END_FUNC = void(MtObject::*)(u32);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cData
    {
    public:
        cGUIObjMessage* mpOBJ_msg_fix_cmndname_m_cmndname;  // offset: 0x0
    };
public:
    class cItem : public uGUIBase::cSupportBase
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
        void setEnable(bool b);
        void load(uGUIPopCmd01* pPopUnit, cControl* pCtrl, u32 idx);
    public:
        cGUIInstAnimation* mpINST_selected_box00;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_cmnd_box_m_cmnd_name;  // offset: 0x20
        cGUIObjPolygon* mpOBJ_msg_cmd_box_mouseover;  // offset: 0x28
        uGUIBase::cDupliInstance<cGUIInstNull*> mpINST_Null_cmnd_list00;  // offset: 0x30
        uGUIPopBase::DATA_FUNC mpFunc;  // offset: 0x58
        uGUIBase* mpFuncUnit;  // offset: 0x68
        MtString mTitle;  // offset: 0x70
        MtObject* mpParam;  // offset: 0x78
        uGUIPopBase::MODE mMode;  // offset: 0x80
        s32 mErrMsgIdx;  // offset: 0x84
        uGUIPopCmd01* mpParentUnit;  // offset: 0x88
        static MyDTI DTI;
    };
public:
    struct stEventFunc
    {
    public:
        stEventFunc();
    public:
        MtObject* mpObj;  // offset: 0x0
        uGUIPopCmd01::END_FUNC mpFunc;  // offset: 0x8
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
    uGUIPopCmd01(bool isChatSubMenu);
    virtual ~uGUIPopCmd01();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void deleteDuplicateAll();  // vtable slot 67
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void addItemSystemMenu(u32 msgId, uGUIPopBase::MODE mode, s32 errMsg);
    virtual MtSize getWindowSize();  // vtable slot 97
    void setMode(EXEC_MODE mode);
    void setAutoKill(bool);
    bool getAutoKill();
    u32 getItemNum();
    cItem* getItem(u32 idx);
    void setCursorIndex(u32);
    s32 getCursorIndex();
    void initPopEndType();
    POP_END_TYPE getPopEndType();
    bool isPopEndTypeCancel();
    bool isPopEndTypeDecide();
    void setSMenuObj(MtObject* pObj, u32 idx);
    uGUIBase::cVerticalList* getCtrl();
    void setPosReserve(const MtVector3& vPos);
    void setUpside(bool flag);
    void setReserveCursorIndex(s32 idx);
protected:
    virtual s32 getSMenuCursorY();  // vtable slot 72
private:
    bool posSetup();
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateAutoKill();
    void updateExit();
    void executeWindow(bool execCtrl);
    void updateWindowSize();
    void _addItem(uGUIBase* pUnit, MT_CTSTR title, uGUIPopBase::DATA_FUNC pFunc, MtObject* pParam, uGUIPopBase::MODE mode, s32 errMsg);
    void _addItem2(MT_CTSTR title, uGUIPopBase::MODE mode, s32 errMsg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlMove(cControl::Message* msg);
    u32 evCtrlClick(cControl::Message* msg);
    void evDecide();
    void evCancel();
    void evMove();
private:
    rGUI* mpGUIRes;  // offset: 0x988
    MtObject* mpSMenuObj;  // offset: 0x990
    uGUIBase::cAdjustableWindow mWindow;  // offset: 0x998
    uGUIBase::cReferenceUIVlCursor mRefCursor;  // offset: 0xa40
    uGUIBase::cReferenceUITooltip mToolTip;  // offset: 0xaf0
    cData mData;  // offset: 0xc60
    MtTypedArray<cItem> mItems;  // offset: 0xc68
    u32 mItemNum;  // offset: 0xc88
    uGUIBase::cVerticalList* mpCtrl;  // offset: 0xc90
    bool mIsAutoKill;  // offset: 0xc98
    bool mIsUpside;  // offset: 0xc99
    bool mPosInit;  // offset: 0xc9a
    EXEC_MODE mExecMode;  // offset: 0xc9c
    POP_END_TYPE mPopEndType;  // offset: 0xca0
    stEventFunc mEndEvent;  // offset: 0xca8
    MtVector3 mPosReserve;  // offset: 0xcc0
    MtVector3 mPosPointer;  // offset: 0xcd0
    s32 mReserveCursorIdx;  // offset: 0xce0
    s32 mPosSetWaitTimer;  // offset: 0xce4
public:
    static MyDTI DTI;
};
