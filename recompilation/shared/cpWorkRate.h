#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class uDDOModel;

// Declarations
class cpWorkRate;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpWorkRate : public cpComponent
{
public:
    enum RATE_INDEX
    {
        RATE_HIT_STOP = 0,
        RATE_SLOW = 1,
        RATE2 = 2,
        RATE3 = 3,
        ASSASSIN_FINISH = 4,
        RATE_OCD_SLOW = 5,
        RATE_OCD_STOP = 6,
        STATUS_CHEANGE = 7,
        STAMINA_GUARD_BREAK = 8,
        RATE_OCD_EROSION = 9,
        RATE_RAGE_SHRINK = 10,
        RATE_NUM = 11,
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
    cpWorkRate();
    virtual ~cpWorkRate();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void update();
    void reUpdateRate();
    void setSpeed(f32 spd, RATE_INDEX Idx);
    void setTypeBit(u32 typeBit);
    u32 getTypeBit() const;
    f32 getHitStopSlowRate() const;
    f32 getCollisionCacheRate() const;
    f32 getSpeedAll() const;
private:
    f32 getSpeed(RATE_INDEX Idx) const;
private:
    uDDOModel* mpModel;  // offset: 0x50
    f32 mSpeed[11];  // offset: 0x58
    u32 mTypeBit;  // offset: 0x84
    f32 mRate;  // offset: 0x88
public:
    static MyDTI DTI;
};
