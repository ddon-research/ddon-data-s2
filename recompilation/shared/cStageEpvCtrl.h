#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cEfcHandle.h"
#include "rEffectProvider.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class cEfcHandle;
class rEffectProvider;

// Declarations
class cStageEpvCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cStageEpvCtrl : public MtObject
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
    cStageEpvCtrl();
    virtual ~cStageEpvCtrl();
    void move();
    void updatePtr();
    void deleteEffect();
    void releaseEpvCtrl();
    void setEffectProvider(rEffectProvider* pRes);
    void setEffectProviderIndex(s32 always, s32 day, s32 night);
    void setOfsPos(const MtVector3& pos);
    rEffectProvider* getEffectProvider();
private:
    void setStageEffect(u32 type);
    void endStageEffect(u32 type, u32 endType);
private:
    res_ptr<rEffectProvider> mpEpv;  // offset: 0x8
    MtTypedArray<cEfcHandle> mStageEfcHandle[4];  // offset: 0x10
    s32 mIndexAlways;  // offset: 0x90
    s32 mIndexDay;  // offset: 0x94
    s32 mIndexNight;  // offset: 0x98
    MtVector3 mOfsPos;  // offset: 0xa0
public:
    static MyDTI DTI;
};
