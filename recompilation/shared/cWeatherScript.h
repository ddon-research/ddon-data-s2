#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "nDDOUtility.h"
#include "nWeather.h"
#include "rWeatherScript.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cWeatherScriptCmd;
class cWeatherScriptIO;

// Declarations
class cWeatherScript;
class cWeatherScriptCmdCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cWeatherScriptCmdArray = MtTypedArray<cWeatherScriptCmd>;
using cWeatherScriptCmdCtrlArray = MtTypedArray<cWeatherScriptCmdCtrl>;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cWeatherScriptCmdCtrl : public cWeatherObjectSys
{
public:
    enum
    {
        STATUS_WAIT = 0,
        STATUS_UPDATE = 1,
        STATUS_END_WAIT = 2,
        STATUS_END = 3,
        STATUS_NUM = 4,
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
    cWeatherScriptCmdCtrl();
    void setupCtrl(const cWeatherScriptCmd* pCmd, cWeatherScriptIO& io);
    void beginCtrl(cWeatherScriptIO& io);
    void updateCtrl(cWeatherScriptIO& io);
    void endCtrl(cWeatherScriptIO& io);
    bool isEnd();
public:
    const cWeatherScriptCmd* mpCmd;  // offset: 0x8
    u32 mStatus;  // offset: 0x10
    static MyDTI DTI;
};

class cWeatherScript : public cWeatherObjectSys
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
    cWeatherScript();
    virtual ~cWeatherScript();
    void initScript();
    void setupScript(cWeatherScriptCmdArray& resArray, u32 step);
    void updateScript();
    void updatePtr();
    void reqStepScript(u32 step);
    void endScript();
    void releaseScript();
    void setScriptEffectRate(f32 rate);
    void setScriptSoundAddVolume(f32 add);
    cWeatherScriptIO& weatherScriptIO();
    void setScriptMoveEnable(bool b);
private:
    void beginScriptCore(cWeatherScriptCmdCtrlArray& script);
    bool updateScriptCore(cWeatherScriptCmdCtrlArray& script);
    void endScriptCore(cWeatherScriptCmdCtrlArray& script);
private:
    u32 mScriptStepCur;  // offset: 0x8
    u32 mScriptStepReq;  // offset: 0xc
    bool mScriptStepReqOn;  // offset: 0x10
    bool mScriptMoveEnable;  // offset: 0x11
    cWeatherScriptIO mScriptIO;  // offset: 0x18
    f32 mEffectAlphaRate;  // offset: 0x50
    nDDOUtility::cArray<MtTypedArray<cWeatherScriptCmdCtrl>, 4> mScripts;  // offset: 0x58
public:
    static MyDTI DTI;
};
