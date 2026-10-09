#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "cZoneCategoryEffectExt.h"
#include "cZoneListener.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtVector3;
namespace nZone { class cLayoutElement; }

// Declarations
class cZoneListenerEffect;
class cZoneListenerEffectColor;
class cZoneListenerEffectEFL;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneListenerEffect : public cZoneListener
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
    cZoneListenerEffect();
    virtual ~cZoneListenerEffect();
    virtual MtVector3 myPos();  // vtable slot 7
    bool isHit();
    void setCheckPos(const MtVector3&);
    void resetParam();
protected:
    bool mbHited;  // offset: 0x2b
    MtVector3 mCheckPos;  // offset: 0x30
public:
    static MyDTI DTI;
};

class cZoneListenerEffectColor : public cZoneListenerEffect
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
    cZoneListenerEffectColor();
    virtual ~cZoneListenerEffectColor();
    virtual void notified(const nZone::cLayoutElement& e);  // vtable slot 6
    const MtColor& getColor() const;
    f32 getColorBlend() const;
    f32 getIntensity() const;
    f32 getIntensityBlend() const;
    const MtColor& getShadowColor() const;
    f32 getShadowColorBlend() const;
    f32 getShadowIntensity() const;
    f32 getShadowIntensityBlend() const;
    f32 getEnvMapPowerScale() const;
    bool getUseSkyColor() const;
    bool getUseShadowColor() const;
    bool getUseMixColor() const;
    u32 getCorrectType() const;
    void setCorrectType(u32 type);
    bool getUsePointLightSupplement();
private:
    u32 mCorrectType;  // offset: 0x40
    MtColor mColor;  // offset: 0x44
    f32 mColorBlend;  // offset: 0x48
    f32 mIntensity;  // offset: 0x4c
    f32 mIntensityBlend;  // offset: 0x50
    MtColor mShadowColor;  // offset: 0x54
    f32 mShadowColorBlend;  // offset: 0x58
    f32 mShadowIntensity;  // offset: 0x5c
    f32 mShadowIntensityBlend;  // offset: 0x60
    f32 mEnvMapPowerScale;  // offset: 0x64
    bool mUseSkyColor;  // offset: 0x68
    bool mUseShadowColor;  // offset: 0x69
    bool mUseMixColor;  // offset: 0x6a
    bool mUsePointLightSupplement;  // offset: 0x6b
public:
    static MyDTI DTI;
};

class cZoneListenerEffectEFL : public cZoneListener
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
    cZoneListenerEffectEFL();
    virtual ~cZoneListenerEffectEFL();
    virtual void notified(const nZone::cLayoutElement& e);  // vtable slot 6
    virtual MtVector3 myPos();  // vtable slot 7
    void resetParam();
    bool isHit() const;
    s32 getLayoutIndex() const;
    const nZone::cLayoutElement* getLayoutElement() const;
    void setCheckPos(const MtVector3&);
    cZCEFLControl::cResourceSet* getResourceSet(u32 no);
private:
    const nZone::cLayoutElement* mpElement;  // offset: 0x30
    MtVector3 mCheckPos;  // offset: 0x40
    cZCEFLControl::cResourceSet* mpResourceSet[32];  // offset: 0x50
public:
    static MyDTI DTI;
};
