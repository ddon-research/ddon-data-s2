#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cControl.h"
#include "../shared/sCaplinkManager.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUICaplinkMailNotice;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkMailNotice : public uGUIBase
{
public:
    enum CAPMN_FLOW
    {
        FLOW_NONE = 0,
        FLOW_MAIL = 1,
        FLOW_TIME = 2,
        FLOW_END = 3,
    };
    enum CAPMN_BTN
    {
        BTN_OK = 0,
        BTN_CANCEL = 1,
        BTN_NUM = 2,
    };
    enum CAPMN_LIST_NUM
    {
        MAIL_0 = 0,
        MAIL_1 = 1,
        MAIL_2 = 2,
        MAIL_3 = 3,
        MAIL_4 = 4,
        MAIL_NUM = 5,
        TIME_0 = 0,
        TIME_1 = 1,
        TIME_2 = 2,
        TIME_3 = 3,
        TIME_NUM = 4,
        LIST_MAX = 5,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
    };
public:
    class MyDTI;
    struct stTop;
    struct stCheckList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stCheckList
    {
    public:
        stCheckList();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        uGUIBase::cReferenceUICheckbox mCheck;  // offset: 0x18
    };
public:
    struct stTop
    {
    public:
        stTop();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        uGUICaplinkMailNotice::stCheckList mCheckItem[5];  // offset: 0x18
        bool mIsMailFlag[5];  // offset: 0x220
        bool mIsTimeFlag[4];  // offset: 0x225
        uGUIBase::cReferenceUIButton mBtn[2];  // offset: 0x230
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
    uGUICaplinkMailNotice();
    virtual ~uGUICaplinkMailNotice();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    bool isDecide();
    void setProf(const sCaplinkManager::cProfile& prof);
    const sCaplinkManager::cProfile& getProf();
private:
    void setupElement();
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void initMail();
    void initTime();
    void adjustCursor();
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mFlowId;  // offset: 0x8d0
    bool mIsDecide;  // offset: 0x8d4
    cControl* mpDecideCtrl;  // offset: 0x8d8
    cControl* mpCancelCtrl;  // offset: 0x8e0
    uGUIBase::cVerticalList* mpListCtrl;  // offset: 0x8e8
    uGUIBase::cHorizontalList* mpBtnCtrl;  // offset: 0x8f0
    stTop mTop;  // offset: 0x8f8
    sCaplinkManager::cProfile mProf;  // offset: 0xe48
public:
    static MyDTI DTI;
};
