#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/uGUIBase.h"
#include "uGUISystemMsg.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector2;
class cDraw;
class cGUIInstance;
class cGUIObject;
class rGUI;
class rGUIMessage;

// Declarations
class uGUINpcWindow;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUINpcWindow : public uGUISystemMsg
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
    uGUINpcWindow();
    virtual ~uGUINpcWindow();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void restart();
    void finish();
    virtual void move();  // vtable slot 9
    void setTextFromTextOld();
    void setNpcName(MT_CTSTR name);
    void setNpcGender(u32 uGender);
    void setNpcEnjoymentDisp(bool bDisp);
    void setNpcEnjoyment(u32 uNpcEnj);
    virtual MtVector2 getChoiceWindowPos();  // vtable slot 98
    virtual bool isMessageWait();  // vtable slot 99
    void reqUpdateDisp();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
protected:
    virtual void updateWait();  // vtable slot 92
    virtual void updateDisp(bool bInit);  // vtable slot 91
private:
    void updateInit();
    void updateIn();
    void updateOutStart();
    void updateOut();
    void updateEnd();
    void updateExit();
    void initScrollList();
    void updateScrollList();
    void updateQuestGuide();
    void updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem);
    f32 getGuideMsgPosY();
private:
    rGUI* mpGUIRes;  // offset: 0x2968
    rGUIMessage* mpGUIMsg;  // offset: 0x2970
    cGUIInstance* mpInstNull;  // offset: 0x2978
    cGUIInstance* mpInstWindowFrm;  // offset: 0x2980
    cGUIInstance* mpInstNameNpc;  // offset: 0x2988
    cGUIInstance* mpInstNullChoice;  // offset: 0x2990
    cGUIInstance* mpInstMask;  // offset: 0x2998
    cGUIInstance* mpInstChoiceTitle;  // offset: 0x29a0
    cGUIInstance* mpInstChoiceNpcEnj;  // offset: 0x29a8
    cGUIInstance* mpInstScrBar;  // offset: 0x29b0
    cGUIInstance* mpInstScroll;  // offset: 0x29b8
    cGUIObject* mpObjName;  // offset: 0x29c0
    cGUIObject* mpObjTitle;  // offset: 0x29c8
    cGUIObject* mpObjMsgNpcEnj;  // offset: 0x29d0
    cGUIObject* mpObjNpcEnj;  // offset: 0x29d8
    cGUIObject* mpObjLineNpcEnj;  // offset: 0x29e0
    cGUIObject* mpObjMaskB;  // offset: 0x29e8
    cGUIObject* mpObjMaskC;  // offset: 0x29f0
    cGUIObject* mpObjMaskT;  // offset: 0x29f8
    uGUIBase::cAdjustableWindow mWindowOut;  // offset: 0x2a00
    uGUIBase::cAdjustableWindow mWindowFrm;  // offset: 0x2aa0
    uGUIBase::cReferenceUITooltip mToolTip;  // offset: 0x2b40
    f32 mListOfs;  // offset: 0x2cb0
    MtStringEx<64> mNpcName;  // offset: 0x2cb4
    u32 mNpcGender;  // offset: 0x2cf8
    bool mNpcEnjDisp;  // offset: 0x2cfc
    u32 mNpcEnj;  // offset: 0x2d00
    bool mRequestRestart;  // offset: 0x2d04
    bool mIsMessageWait;  // offset: 0x2d05
    bool mIsMessageWaitTemp;  // offset: 0x2d06
    bool mIsFinish;  // offset: 0x2d07
    bool mIsDraw;  // offset: 0x2d08
    f32 mDistTitle;  // offset: 0x2d0c
    f32 mDistNpcEnj;  // offset: 0x2d10
    bool mReqUpdateDisp;  // offset: 0x2d14
    MT_CHAR mTextOld[2048];  // offset: 0x2d15
    u32 mMTLIdxWindow;  // offset: 0x3518
public:
    static MyDTI DTI;
};
