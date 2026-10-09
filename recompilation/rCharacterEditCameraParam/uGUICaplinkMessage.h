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
class MtString;
class cControl;
class cDraw;
class cGUIInstAnimation;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUICaplinkMessage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkMessage : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_SELECT = 1,
        FLOW_INPUT = 2,
        FLOW_END = 3,
    };
    enum
    {
        BUTTON_YES = 0,
        BUTTON_NO = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        SELECT_TEXTBOX = 0,
        SELECT_BUTTON = 1,
        SELECT_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stData;
    struct stMain;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_text00_x;  // offset: 0x0
        s32 mParam_text00_y;  // offset: 0x4
        s32 mParam_btn_x;  // offset: 0x8
    };
public:
    struct stData
    {
    public:
        stData();
    public:
        MtString mTitle;  // offset: 0x0
        MtString mMessage;  // offset: 0x8
        MtString mText;  // offset: 0x10
        MtString mYes;  // offset: 0x18
        MtString mNo;  // offset: 0x20
        bool mIsInputMode;  // offset: 0x28
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstAnimation* mpInstAnimText;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgMessage;  // offset: 0x10
        cGUIObjMessage* mpObjMsgText;  // offset: 0x18
        uGUIBase::cReferenceUITextBox mTextBox;  // offset: 0x20
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x188
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
    uGUICaplinkMessage();
    virtual ~uGUICaplinkMessage();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setData(MT_CTSTR title, MT_CTSTR msg, MT_CTSTR text, MT_CTSTR decide, MT_CTSTR cancel, bool isInput);
    MT_CTSTR getMessage();
    bool isDecide();
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupSelect();
    void adjustSelectCursor();
    void setupInput();
    void updateInput();
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
    stVariable mVar;  // offset: 0x8d4
    stData mData;  // offset: 0x8e0
    stMain mMain;  // offset: 0x910
    bool mIsDecide;  // offset: 0xdb8
    cControl* mpDecideCtrl;  // offset: 0xdc0
    cControl* mpCancelCtrl;  // offset: 0xdc8
    uGUIBase::cVerticalList* mpUDCtrl;  // offset: 0xdd0
    uGUIBase::cHorizontalList* mpButtonCtrl;  // offset: 0xdd8
public:
    static MyDTI DTI;
};
