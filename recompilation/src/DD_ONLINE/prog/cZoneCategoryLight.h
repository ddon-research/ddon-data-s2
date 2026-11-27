#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cZoneContents.h"
#include "uSkyFog.h"
#include "uSkyLight.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cDayNightColorFogParam;
class cDayNightLightParam;

// Declarations
class cZoneCategoryDayNightColorFog;
class cZoneCategoryDayNightHemiSphere;
class cZoneCategoryLight;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneCategoryLight : public cZoneContents
{
public:
    enum
    {
        ZONE_LIGHT_TYPE_NONE = 0,
        ZONE_LIGHT_TYPE_DAYNIGHT_HEMISPHERE = 1,
        ZONE_LIGHT_TYPE_DAYNIGHT_COLORFOG = 2,
        ZONE_LIGHT_TYPE_NUM = 3,
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
    cZoneCategoryLight();
    virtual ~cZoneCategoryLight() {}
    virtual u32 getCategoryType() const;  // vtable slot 10
public:
    static MyDTI DTI;
};

class cZoneCategoryDayNightColorFog : public cZoneCategoryLight
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
    cZoneCategoryDayNightColorFog();
    virtual ~cZoneCategoryDayNightColorFog() {}
    virtual u32 getCategoryType() const;  // vtable slot 10
    cDayNightColorFogParam* getDayParam();
    f32 getDayHeightStart() const;
    f32 getDayHeightEnd() const;
    f32 getDayHeightDensity() const;
    const MtVector3& getDayHeightColor() const;
    f32 getDayStart() const;
    f32 getDayEnd() const;
    f32 getDayDensity() const;
    const MtVector3& getDayColor() const;
    f32 getDayDiffuseBlendFactor() const;
    cDayNightColorFogParam* getNightParam();
    f32 getNightHeightStart() const;
    f32 getNightHeightEnd() const;
    f32 getNightHeightDensity() const;
    const MtVector3& getNightHeightColor() const;
    f32 getNightStart() const;
    f32 getNightEnd() const;
    f32 getNightDensity() const;
    const MtVector3& getNightColor() const;
    f32 getNightDiffuseBlendFactor() const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    cDayNightColorFogParam mDayParam;  // offset: 0x20
    cDayNightColorFogParam mNightParam;  // offset: 0x90
public:
    static MyDTI DTI;
};

class cZoneCategoryDayNightHemiSphere : public cZoneCategoryLight
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
    cZoneCategoryDayNightHemiSphere();
    virtual ~cZoneCategoryDayNightHemiSphere() {}
    virtual u32 getCategoryType() const;  // vtable slot 10
    cDayNightLightParam* getDayParam();
    MtVector3 getDayLightColor() const;
    MtVector3 getDayLightRevColor() const;
    const MtVector3& getDayLightDir() const;
    f32 getDayShadowGroup0Ex() const;
    f32 getDayShadowGroup1Ex() const;
    cDayNightLightParam* getNightParam();
    MtVector3 getNightLightColor() const;
    MtVector3 getNightLightRevColor() const;
    const MtVector3& getNightLightDir() const;
    f32 getNightShadowGroup0Ex() const;
    f32 getNightShadowGroup1Ex() const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    cDayNightLightParam mDayParam;  // offset: 0x20
    cDayNightLightParam mNightParam;  // offset: 0x70
public:
    static MyDTI DTI;
};

inline void* cZoneCategoryDayNightColorFog::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZoneCategoryDayNightHemiSphere::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZoneCategoryLight::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cZoneCategoryDayNightColorFog::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZoneCategoryDayNightColorFog::DTI)->memFree(p_addr);
}

inline void cZoneCategoryDayNightHemiSphere::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZoneCategoryDayNightHemiSphere::DTI)->memFree(p_addr);
}

inline void* cZoneCategoryLight::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZoneCategoryLight::DTI)->memAlloc(sz, align, ::cZoneCategoryLight::DTI.::MtDTI::getID());
}

inline void cZoneCategoryLight::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZoneCategoryLight::DTI)->memFree(p_addr);
}

inline cZoneCategoryLight::cZoneCategoryLight() {
    this->::cZoneContents::setAttribute(32768u, true);
    this->::cZoneContents::setAttribute(0x10000u, true);
}
