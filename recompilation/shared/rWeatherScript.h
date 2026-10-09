#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cResource.h"
#include "nDDOUtility.h"
#include "nWeather.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class cEfcHandle;
class cResource;

// Declarations
class cWSCParam;
class cWeatherScriptCmd;
class cWeatherScriptCmds;
class cWeatherScriptIO;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cWSCParam : public cWeatherObjectSys
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
    cWSCParam();
    virtual ~cWSCParam();
public:
    res_ptr<cResource> mpRes;  // offset: 0x8
    cEfcHandle* mpEfcHandle;  // offset: 0x10
    const void* mpOwner;  // offset: 0x18
    nDDOUtility::cArray<unsigned int, 4> mFree;  // offset: 0x20
    f32 mFreeF32;  // offset: 0x30
    u32 mEfcEnd;  // offset: 0x34
    static MyDTI DTI;
};

class cWeatherScriptCmd : public cWeatherObjectRes
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
    cWeatherScriptCmd();
    // Address: 0x01abbd10 - 0x01abbd11 (1 bytes)
    virtual ~cWeatherScriptCmd() {}
    virtual void setupCmd(cWeatherScriptIO& io) const;  // vtable slot 6
    virtual bool updateCmd(cWeatherScriptIO& io) const;  // vtable slot 7
    virtual void endCmd(cWeatherScriptIO& io) const;  // vtable slot 8
    bool isUpdateForceEnd() const;
protected:
    bool isEnableStage() const;
public:
    virtual void load(MtDataReader& r);  // vtable slot 9
public:
    f32 mBeginFrame;  // offset: 0x8
    f32 mEndFrame;  // offset: 0xc
    nDDOUtility::cArray<unsigned int, 8> mEnableStageNo;  // offset: 0x10
    nDDOUtility::cArray<unsigned int, 8> mDisableStageNo;  // offset: 0x30
    static MyDTI DTI;
};

class cWeatherScriptCmds : public cWeatherObjectRes
{
public:
    enum
    {
        STEP_STOP = 0,
        STEP_BEGIN = 1,
        STEP_MAIN = 2,
        STEP_END = 3,
        STEP_NUM = 4,
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
    cWeatherScriptCmds();
    virtual ~cWeatherScriptCmds();
    void load(MtDataReader& r);
public:
    nDDOUtility::cArray<MtTypedArray<cWeatherScriptCmd>, 4> mScripts;  // offset: 0x8
    static MyDTI DTI;
};

class cWeatherScriptIO : public cWeatherObjectSys
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
    cWeatherScriptIO();
    virtual ~cWeatherScriptIO();
    void updatePtr();
    cWSCParam* getWSCParam(const void* pOwner);
    void releaseWSCParam(const void* pOwner);
    void releaseWSCParamAll();
public:
    MtTypedArray<cWSCParam> mWSCParams;  // offset: 0x8
    f32 mMoveFrame;  // offset: 0x28
    f32 mReqSoundVolumeAdd;  // offset: 0x2c
    f32 mRetSoundVolumeSub;  // offset: 0x30
    static MyDTI DTI;
};
