#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cZoneListener.h"
#include "uSkyFog.h"
#include "uSkyLight.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cDayNightColorFogParam;
class cDayNightLightParam;
namespace nZone { class cLayoutElement; }
class sWeatherManager;

// Declarations
class cZoneListenerLight;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneListenerLight : public cZoneListener
{
    // inferred: sWeatherManager::getCustomDayNightLight names sWeatherManager::mLightAndFogZoneListener.mDayNightLightParam
    friend class sWeatherManager;
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
    cZoneListenerLight();
    virtual ~cZoneListenerLight();
    virtual void notified(const nZone::cLayoutElement& e);  // vtable slot 6
    void resetHitParam();
    void updateParam();
    s32 getHitZoneID(u32 type) const;
    const cDayNightLightParam& getmDayNightLightParam() const;
    const cDayNightColorFogParam& getDayNightColorFogParam() const;
    void setCheckPos(const MtVector3&);
    virtual MtVector3 myPos();  // vtable slot 7
    void clear();
private:
    MtVector3 mCheckPos;  // offset: 0x30
    s32 mDayNightLighId;  // offset: 0x40
    s32 mDayNightColorFogId;  // offset: 0x44
    cDayNightLightParam mDayNightLightParam;  // offset: 0x50
    cDayNightColorFogParam mDayNightColorFogParam;  // offset: 0xa0
public:
    static MyDTI DTI;
};
