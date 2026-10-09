#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIEventSkip;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIEventSkip : public uGUIBase
{
public:
    enum SKIP_MODE
    {
        EVENT_SKIP_MODE = 0,
        GENERAL_SKIP_MODE = 1,
        SKIP_MODE_NUM = 2,
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
    uGUIEventSkip(SKIP_MODE mode);
    virtual ~uGUIEventSkip();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setDisp(bool flg);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateAlpha();
    void updateEventMode();
    void updateGeneralMode();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGUIMsgGuide;  // offset: 0x8d0
    cGUIInstAnimation* mpInstSkip;  // offset: 0x8d8
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x8e0
    f32 mAlpha;  // offset: 0x978
    f32 mTimeFade;  // offset: 0x97c
    bool mIsDisp;  // offset: 0x980
    SKIP_MODE mMode;  // offset: 0x984
public:
    static MyDTI DTI;
private:
    static const u32 SEC_FADE = 5;
};
