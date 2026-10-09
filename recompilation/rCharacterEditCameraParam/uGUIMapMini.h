#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
#include "uGUIMap.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector4;
class cControl;
class cDraw;
class cGUIInstAnimation;

// Declarations
class uGUIMapMini;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMapMini : public uGUIMap
{
public:
    enum GUIDE_TYPE
    {
        GUIDE_NONE = 0,
        GUIDE_KBD_S_ON = 1,
        GUIDE_KBD_S_OFF = 2,
        GUIDE_KBD_L = 3,
        GUIDE_KBD_L_NO_LOCK = 4,
        GUIDE_KBD_L_LOCK = 5,
        GUIDE_PAD_S_ON = 6,
        GUIDE_PAD_S_OFF = 7,
        GUIDE_PAD_L = 8,
        GUIDE_PAD_L_ON_NO_LOCK = 9,
        GUIDE_PAD_L_ON_LOCK = 10,
    };
    enum TOP_PTS_GUIDE_BIT
    {
        TOP_PTS_LOCK = 1,
        TOP_PTS_SCAL = 2,
        TOP_PTS_S_LOCK = 4,
        TOP_PTS_FREE = 8,
        TOP_PTS_ZOOM = 16,
        TOP_PTS_MOVE = 32,
        TOP_PTS_BIT_MAX = 6,
    };
    enum BOTTOM_PTS_GUIDE_BIT
    {
        BOTTOM_PTS_CTRL = 1,
        BOTTOM_PTS_BIT_MAX = 1,
    };
    enum
    {
        INPUTEVENT_SET_FREEMARKER = 66,
        INPUTEVENT_CHANGE_FREEMARKER = 67,
        INPUTEVENT_DIRECT_LINK = 68,
        INPUTEVENT_SIZE_MOVE = 69,
        INPUTEVENT_START_BTN = 70,
        INPUTEVENT_LOCK = 71,
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
    uGUIMapMini();
    virtual ~uGUIMapMini();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void draw(cDraw* pDraw);  // vtable slot 12
private:
    void updateInit();
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlSizeMove(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlLock(cControl::Message* msg);
    void evSizeMove();
    void evLock();
    void lockInput();
    void updateBtnGuide();
protected:
    virtual void updateDisp();  // vtable slot 95
    virtual void execPosition();  // vtable slot 92
    virtual void execFooter();  // vtable slot 93
    // Address: 0x01afb930 - 0x01afb931 (1 bytes)
    virtual void execBtnGuaid() {}  // vtable slot 94
private:
    cControl* mpCtrlSize;  // offset: 0x3768
    cControl* mpCtrlStart;  // offset: 0x3770
    uGUIBase::cAdjustableWindow mWndwFrame;  // offset: 0x3778
    cGUIInstAnimation* mpInstBtnGuideBottom;  // offset: 0x3818
    MtVector4 mBtnGuideBottomSmallPos;  // offset: 0x3820
    MtVector4 mBtnGuideBottomLargePos;  // offset: 0x3830
    uGUIBase::cReferenceUIBtnGuide mBtnGuideTop;  // offset: 0x3840
    uGUIBase::cReferenceUIBtnGuide mBtnGuideBottom;  // offset: 0x38d8
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuideTop[6];  // offset: 0x3970
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuideBottom[1];  // offset: 0x3a60
    GUIDE_TYPE mGuideType;  // offset: 0x3a88
    GUIDE_TYPE mGuideTypeOld;  // offset: 0x3a8c
    bool mScaleLock;  // offset: 0x3a90
public:
    static MyDTI DTI;
};
