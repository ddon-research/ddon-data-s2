#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "nWeather.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
class cDayNightLightParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cDayNightLightParam : public cWeatherObjectRes
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
    cDayNightLightParam();
    // Address: 0x01b22970 - 0x01b22971 (1 bytes)
    virtual ~cDayNightLightParam() {}
    void lerp(const cDayNightLightParam& a, const cDayNightLightParam& b, f32 rate);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    MtVector3 mLightColor;  // offset: 0x10
    MtVector3 mRevColor;  // offset: 0x20
    MtVector3 mLightDir;  // offset: 0x30
    MtFloat2 mLightShadowAtten;  // offset: 0x40
    static MyDTI DTI;
};
