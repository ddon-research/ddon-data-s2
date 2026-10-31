#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIPlace;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPlace : public uGUIBase
{
public:
    enum STEP
    {
        STEP_IDLE = 0,
        STEP_DELAY = 1,
        STEP_FADE_IN = 2,
        STEP_WAIT = 3,
        STEP_FADE_OUT = 4,
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
    uGUIPlace();
    virtual ~uGUIPlace();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setDelay(f32);
    void setPlaceName(MT_CTSTR placeName);
    void setStageName(s32 stageNo);
    void setSpotName(u32 spotId);
    bool isDisp() const;
    void startDisp();
private:
    void updateInit();
    void updateWait();
    void updateExit();
    bool updateStepIdle();
    bool updateStepDelay();
    bool updateStepFadeIn();
    bool updateStepWait();
    bool updateStepFadeOut();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpINST_Null;  // offset: 0x8d0
    cGUIInstAnimation* mpINST_msg_place;  // offset: 0x8d8
    cGUIObjMessage* mpOBJ_test_message_Message;  // offset: 0x8e0
    MtStringEx<128> mStr;  // offset: 0x8e8
    f32 mTimer;  // offset: 0x96c
    f32 mDelay;  // offset: 0x970
    bool mIsOn;  // offset: 0x974
    STEP mStep;  // offset: 0x978
public:
    static MyDTI DTI;
};
