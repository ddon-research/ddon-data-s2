#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObject;
class rGUI;

// Declarations
class uGUIGainInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGainInfo : public uGUIBase
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
    uGUIGainInfo();
    virtual ~uGUIGainInfo();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    bool isEndAnimation();
    void setSleep(bool bSleep);
    bool isSleep();
    void setType(u32 uType);
    u32 getType();
    void setData0(s32 sData);
    s32 getData0();
    void setData1(s32 sData);
    s32 getData1();
private:
    void updateSleep();
    void updateInit();
    void updateIn();
    void updateWait();
    void updateOut();
    void updateExit();
    void setInstNullOffsetY(cGUIInstNull* pInstNull, f32 offsetY);
    void setTextFrame(cGUIObject* pObjText, u32 frame);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpInstNullAll;  // offset: 0x8d0
    cGUIInstNull* mpInstNullBonus;  // offset: 0x8d8
    cGUIInstAnimation* mpInstAnimText0;  // offset: 0x8e0
    cGUIInstAnimation* mpInstAnimText1;  // offset: 0x8e8
    cGUIObjMessage* mpObjMsgText0;  // offset: 0x8f0
    cGUIObjMessage* mpObjMsgText1;  // offset: 0x8f8
    u32 mType;  // offset: 0x900
    s32 mData0;  // offset: 0x904
    s32 mData1;  // offset: 0x908
    f32 mWait;  // offset: 0x90c
    f32 mWaitMax;  // offset: 0x910
    f32 mNullBonusPosY;  // offset: 0x914
    bool mIsSleep;  // offset: 0x918
public:
    static MyDTI DTI;
};
