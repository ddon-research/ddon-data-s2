#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
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
class cStateTransitionFromGameInfo;

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

class cStateTransitionFromGameInfo : public MtObject
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
    cStateTransitionFromGameInfo();
    virtual ~cStateTransitionFromGameInfo() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void init();  // vtable slot 6
    virtual void update();  // vtable slot 7
    virtual void start();  // vtable slot 8
    virtual void reset();  // vtable slot 9
    virtual void startAfterInit() {}  // vtable slot 10
    virtual void forceEnd();  // vtable slot 11
    f32 getPassageFrame();
    void setPassageFrame(f32 set);
private:
    f32 mPassageFrame;  // offset: 0x8
    bool mStartAfterInit;  // offset: 0xc
public:
    static MyDTI DTI;
};

inline void* cDayNightLightParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cStateTransitionFromGameInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cStateTransitionFromGameInfo::cStateTransitionFromGameInfo() {
    this->mPassageFrame = 0.0f;
    this->mStartAfterInit = false;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cDayNightLightParam::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cDayNightLightParam::DTI)->memFree(p_addr);
}

inline void* cStateTransitionFromGameInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cStateTransitionFromGameInfo::DTI)->memAlloc(sz, align, ::cStateTransitionFromGameInfo::DTI.::MtDTI::getID());
}

inline void cStateTransitionFromGameInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cStateTransitionFromGameInfo::DTI)->memFree(p_addr);
}
