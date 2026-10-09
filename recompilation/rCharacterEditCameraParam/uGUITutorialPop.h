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
class cArcLoaderBase;
class cGUIInstance;
class cGUIObjTextureRef;
class cGUIObject;
class rGUI;
class rGUIMessage;
class rTexture;

// Declarations
class uGUITutorialPop;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUITutorialPop : public uGUIBase
{
public:
    enum
    {
        INPUTEVENT_EXIT = 66,
        INPUTEVENT_MOVE = 67,
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
    uGUITutorialPop();
    virtual ~uGUITutorialPop();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setGuideNo(u32 uNo);
    u32 getGuideNo();
private:
    void updateInit();
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void evPageExit();
    void evPageMove();
    u32 evHLPageExit(cControl::Message* msg);
    u32 evHLPageMove(cControl::Message* msg);
    void updateDisp();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGUIMsg;  // offset: 0x8d0
    MtString mTagName;  // offset: 0x8d8
    u32 mGuideNo;  // offset: 0x8e0
    u32 mPageNo;  // offset: 0x8e4
    u32 mImgNo;  // offset: 0x8e8
    bool mIsCreateGuideRequest;  // offset: 0x8ec
    uGUIBase::cReferenceUINumPager mPager;  // offset: 0x8f0
    uGUIBase::cReferenceUIButton mButton;  // offset: 0x998
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0xb28
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xb80
    cGUIInstance* mpInstLoading;  // offset: 0xc18
    cGUIObject* mpObjMsg;  // offset: 0xc20
    cGUIObjTextureRef* mpObjTexImg;  // offset: 0xc28
    uGUIBase::cHorizontalList* mpHLPage;  // offset: 0xc30
    TICKET mImgArcTicket;  // offset: 0xc38
    rTexture* mpTexImg;  // offset: 0xc40
public:
    static MyDTI DTI;
};
