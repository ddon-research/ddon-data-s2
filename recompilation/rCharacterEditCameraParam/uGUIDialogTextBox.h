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
class MtString;
class rGUI;

// Declarations
class uGUIDialogTextBox;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIDialogTextBox : public uGUIBase
{
public:
    enum POS_V
    {
        POS_V_TEXTBOX = 0,
        POS_V_BUTTON = 1,
        POS_V_NUM = 2,
    };
    enum BUTTON_ID
    {
        BUTTON_DECIDE = 0,
        BUTTON_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        RNO0_NONE = 0,
        RNO0_WAIT_INPUT = 1,
    };
    enum
    {
        INPUTEVENT_MOVE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_DECIDE = 68,
    };
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
    uGUIDialogTextBox();
    virtual ~uGUIDialogTextBox();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void setTitle(MT_CTSTR msg);
    void setTitleAnalyze(bool isAnalyze);
    void setMsg(MT_CTSTR msg);
    MT_CTSTR getMsg();
    void setMsgMax(u32 uMax);
    void setKIType(s32 sType);
    bool isCancel();
    void setCheckNGWord();
private:
    void updateInit();
    void updateWait();
    void updateExit();
    u32 evCtrlMove(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    void evMove();
    void evCancel();
    void evDecide();
    void updateDisp();
    void endInput();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    uGUIBase::cReferenceUITextBox mTextBox;  // offset: 0x8d0
    uGUIBase::cReferenceUIButton mBtnY;  // offset: 0xa38
    uGUIBase::cReferenceUIButton mBtnN;  // offset: 0xbc8
    MtStringEx<128> mTitle;  // offset: 0xd58
    MtString mMsg;  // offset: 0xde0
    u32 mMsgMax;  // offset: 0xde8
    s32 mKIType;  // offset: 0xdec
    uGUIBase::cVerticalList* mpVL;  // offset: 0xdf0
    uGUIBase::cHorizontalList* mpHL;  // offset: 0xdf8
    bool mIsCancel;  // offset: 0xe00
    bool mIsTitleAnalyze;  // offset: 0xe01
    bool mCheckNGWord;  // offset: 0xe02
public:
    static MyDTI DTI;
};
