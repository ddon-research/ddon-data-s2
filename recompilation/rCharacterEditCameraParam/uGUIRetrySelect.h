#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class rGUIMessage;
class uGUIRetry;

// Declarations
class uGUIRetrySelect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIRetrySelect : public uGUIBase
{
    // inferred: uGUIRetry::kill names uGUIRetrySelect::mpListCtrl
    friend class uGUIRetry;
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_WAIT = 1,
        FLOW_SELECT = 2,
        FLOW_FINISH = 3,
        FLOW_END = 4,
    };
    enum
    {
        CLICK_LEFT = 0,
        CLICK_RIGHT = 1,
        CLICK_CENTER = 2,
        CLICK_NUM = 3,
    };
    enum
    {
        SEL_STOCK = 0,
        SEL_GOLD_STONE = 1,
        SEL_PENALTY = 2,
        SEL_MAX = 3,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_ADJUST_CURSOR = 67,
    };
public:
    class MyDTI;
    struct stObjects;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stObjects
    {
    public:
        stObjects();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimImage;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimBase;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimArrow;  // offset: 0x18
        cGUIInstAnimation* mpInstAnimText;  // offset: 0x20
        cGUIInstAnimation* mpInstAnimAnnounce;  // offset: 0x28
        cGUIObjMessage* mpObjMsgAnnounce;  // offset: 0x30
        cGUIObjMessage* mpObjMsgExp;  // offset: 0x38
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x40
        cGUIObjMessage* mpObjMsgPlace;  // offset: 0x48
        cGUIObjMessage* mpObjMsgGoldStoneNum;  // offset: 0x50
        cGUIObjMessage* mpObjMsgReviveNum;  // offset: 0x58
        cGUIObjTexture* mpObjTexArrowL;  // offset: 0x60
        cGUIObjTexture* mpObjTexArrowR;  // offset: 0x68
        cGUIObjPolygon* mpObjPolyMouseCollisionLeft;  // offset: 0x70
        cGUIObjPolygon* mpObjPolyMouseCollisionRight;  // offset: 0x78
        cGUIObjPolygon* mpObjPolyMouseCollisionCenter;  // offset: 0x80
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
    uGUIRetrySelect();
    virtual ~uGUIRetrySelect();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void begin();
    void restart();
    void finish();
    void cancel();
    void hide();
    void wait();
    void setEnable(u32, bool);
    bool isDecide();
    s32 getSelectPos();
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateInit();
    void updateMove();
    void updateFinish();
    void updateExit();
    void setupSelect();
    void updateText();
    void setupFinish();
    void setFocus();
    void setDecide();
    void turnLeft();
    void turnRight();
    void setObjSeq(u32 seq_id);
    void eventDecide();
    void eventAdjustCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    cGUIInstNull* mpInstNull;  // offset: 0x8d8
    u32 mFlowId;  // offset: 0x8e0
    stObjects mObj;  // offset: 0x8e8
    bool mIsBegin;  // offset: 0x970
    bool mIsDecide;  // offset: 0x971
    bool mIsEnable[3];  // offset: 0x972
    bool mIsUpdateText;  // offset: 0x975
    cControl* mpDecideCtrl;  // offset: 0x978
    cControl* mpMouseCtrl;  // offset: 0x980
    uGUIBase::cHorizontalList* mpListCtrl;  // offset: 0x988
    MtStringEx<128> mTempStr;  // offset: 0x990
public:
    static MyDTI DTI;
};
