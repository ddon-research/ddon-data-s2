#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cGUIInstAnimation;
class cGUIObjMessage;
class cGUIObjTexture;
class rGUI;
class rGUIMessage;
class rTexture;

// Declarations
class uGUIGPConfirm;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGPConfirm : public uGUIBase
{
public:
    enum
    {
        TYPE_ITEM = 0,
        TYPE_GOLDSTONE = 1,
    };
    enum
    {
        CURSOR_LINE_BROWSER = 0,
        CURSOR_LINE_BUTTON = 1,
        CURSOR_LINE_NUM = 2,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_MOVEBROWSER = 67,
        INPUTEVENT_STOPBROWSER = 68,
        INPUTEVENT_MOVECURSOR = 69,
        INPUTEVENT_BUTTONCLICK = 70,
    };
    enum
    {
        BUTTON_OK = 0,
        BUTTON_NG = 1,
        BUTTON_NUM = 2,
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
    void setItemInfo(MT_CTSTR pCategoryName, MT_CTSTR pItemName, u32 Price, u32 IconId, u32 LineupId);
    void setGoldStoneInfo(u32 GoldStoneNum, u32 Price);
    bool isPushOK();
    uGUIGPConfirm();
    virtual ~uGUIGPConfirm();
private:
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void adjustScale();  // vtable slot 84
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateWait1st();
    void updateWait();
    void initConfirm();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlClose(cControl::Message* pMsg);
    u32 evCtrlDecide(cControl::Message* pMsg);
    u32 evCtrlCursorUD(cControl::Message* pMsg);
    u32 evCtrlCursorLR(cControl::Message* pMsg);
    u32 evCtrlMouseClick(cControl::Message* pMsg);
    void updateCursorDisp();
    void updateBrowserPointer();
    void endBrowser();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    uGUIBase::cVerticalList* mpCtrl;  // offset: 0x8d8
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x8e0
    bool mIsPushOK;  // offset: 0x938
    u32 mType;  // offset: 0x93c
    s32 mCursorX;  // offset: 0x940
    u32 mPrice;  // offset: 0x944
    u32 mIconId;  // offset: 0x948
    u32 mLineupId;  // offset: 0x94c
    uGUIBase::cReferenceUIButton mButtonOK;  // offset: 0x950
    uGUIBase::cReferenceUIButton mButtonNG;  // offset: 0xae0
    MtVector3 mBrowserOfs;  // offset: 0xc70
    bool mIsInitBrowser;  // offset: 0xc80
    rTexture* mpOrgTex;  // offset: 0xc88
    uGUIBase::cTexArcLoader mBrowserArea;  // offset: 0xc90
    bool mIsUsingBrowser;  // offset: 0xd18
    cGUIObjMessage* mpText;  // offset: 0xd20
    cGUIObjMessage* mpGPNum;  // offset: 0xd28
    cGUIObjMessage* mpGPAfterNum;  // offset: 0xd30
    cGUIObjTexture* mpBrowserArea;  // offset: 0xd38
    cGUIInstAnimation* mpLoadIcon;  // offset: 0xd40
public:
    static MyDTI DTI;
};
