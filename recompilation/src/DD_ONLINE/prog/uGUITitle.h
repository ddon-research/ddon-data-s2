#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class aTitle;
class cGUIInstAnimation;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class cOpeningMovie;
class rGUI;
class rGUIMessage;
class rSoundRequest;
class rSoundStreamRequest;

// Declarations
class uGUITitle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUITitle : public uGUIBase
{
    friend class aTitle;
public:
    enum
    {
        RNO_NONE = 0,
        RNO_MOVIE_INIT = 1,
        RNO_MOVIE_START = 2,
        RNO_MOVIE_START_WAIT = 3,
        RNO_MOVIE_CONTINUE = 4,
        RNO_MOVIE_WEATHER_WAIT = 5,
        RNO_MOVIE_END = 6,
        RNO_CREDIT_INIT = 7,
        RNO_CREDIT_WAIT = 8,
        RNO_CREDIT_END = 9,
    };
    enum
    {
        SEL_NONE = 0,
        SEL_START = 1,
        SEL_OPENING_MOVIE = 2,
        SEL_CREDITS = 3,
        SEL_CONFIG = 4,
        SEL_EXIT = 5,
        SEL_NUM = 6,
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
    uGUITitle();
    virtual ~uGUITitle();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    bool isEffectOff();
private:
    void updateInit();
    void updateIn();
    void updateWait();
    void updateOut();
    void updateMovie();
    void updateCredit();
    void updateExit();
    void updateGameExit();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlMove(cControl::Message* msg);
    void updateDisp();
    void createMenu();
    void setSequenceIdWithTexRect(s32 index, u32 seqId);
protected:
    virtual void adjustScale() {}  // vtable slot 84
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstance* mpInstNull;  // offset: 0x8d0
    cGUIInstance* mpInstScr;  // offset: 0x8d8
    cGUIInstAnimation* mpInstAnimFixLogo;  // offset: 0x8e0
    cGUIInstAnimation* mpInstAnimLogoBack;  // offset: 0x8e8
    cGUIObjPolygon* mpObjWindows[3];  // offset: 0x8f0
    cGUIObjMessage* mpObjMsg;  // offset: 0x908
    cGUIInstance* mpInstMenu[6];  // offset: 0x910
    u32 mMenuTag[6];  // offset: 0x940
    s32 mMenuNum;  // offset: 0x958
    rGUIMessage* mpGMDRes;  // offset: 0x960
    uGUIBase::cVerticalList* mpCtrl;  // offset: 0x968
    rSoundStreamRequest* mpSoundRes;  // offset: 0x970
    rSoundRequest* mpSeRes;  // offset: 0x978
    f32 mPosYCursorInit;  // offset: 0x980
    f32 mPosYCursorTgt;  // offset: 0x984
    s32 mDistCursor;  // offset: 0x988
    uGUIBase* mpGUIMenuChild;  // offset: 0x990
    cOpeningMovie* mpOpeningMovie;  // offset: 0x998
    f32 mAlpha;  // offset: 0x9a0
    uGUIBase::cAdjustableWindow mVersionCell;  // offset: 0x9a8
    u8 mRno;  // offset: 0xa48
    bool mIsEffectOff;  // offset: 0xa49
public:
    static MyDTI DTI;
};

inline void* uGUITitle::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUITitle::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUITitle::DTI);
}

inline void uGUITitle::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUITitle::DTI)->memFree(p_addr);
}
