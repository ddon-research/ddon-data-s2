#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
class MtVector3;
class rTexture;

// Declarations
class rSky;
class rStarCatalog;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSky : public cResource
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
    rSky();
    virtual ~rSky();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    MtVector3 getRayleighScattering() const;
    f32 getObliquity() const;
    u32 getSpinDirection() const;
    u32 getEclipticLongitude() const;
    f32 getLatitude() const;
    MtVector3 getSunColor() const;
    f32 getSunMultiplier() const;
    f32 getEarthRadius() const;
    f32 getAtmosphereHeight() const;
    f32 getAtmosphereAverageDensityHeight() const;
    f32 getAerosolHeight() const;
    f32 getAerosolAverageDensityHeight() const;
    f32 getSecondaryScattering() const;
    MtVector3 getStarryAmbientColor() const;
    f32 getSunBodySize() const;
    f32 getSunRadius() const;
    f32 getSunDistance() const;
    rTexture* getSunTexture() const;
    MtVector3 getStarrySkyColor(u32 index) const;
    f32 getStarrySkyColorT1() const;
    f32 getStarrySkyColorT2() const;
    f32 getMoonAge() const;
    f32 getMoonFluctuationAmplitude() const;
    f32 getMoonFluctuationPhase() const;
    MtVector3 getMoonColor() const;
    rTexture* getMoonTexture() const;
    f32 getMoonBodySize() const;
    f32 getMoonRadius() const;
    f32 getMoonMultiplier() const;
    f32 getMoonDistance() const;
    f32 getEarthShine() const;
protected:
    MtVector3 mSunColor;  // offset: 0x70
    MtVector3 mStarryAmbientColor;  // offset: 0x80
    MtVector3 mRamda;  // offset: 0x90
    f32 mRayleighScatteringBase;  // offset: 0xa0
    f32 mObliquity;  // offset: 0xa4
    u32 mSpinDirection;  // offset: 0xa8
    u32 mEclipticLongitude;  // offset: 0xac
    f32 mLatitude;  // offset: 0xb0
    f32 mSunMultiplier;  // offset: 0xb4
    f32 mEarthRadius;  // offset: 0xb8
    f32 mAtmosphereHeight;  // offset: 0xbc
    f32 mAtmosphereAverageDensityHeight;  // offset: 0xc0
    f32 mAerosolHeight;  // offset: 0xc4
    f32 mAerosolAverageDensityHeight;  // offset: 0xc8
    f32 mSecondaryScattering;  // offset: 0xcc
    rTexture* mpSunTexture;  // offset: 0xd0
    f32 mSunBodySize;  // offset: 0xd8
    f32 mSunRadius;  // offset: 0xdc
    f32 mSunDistance;  // offset: 0xe0
    MtVector3 mStarrySkyColor[4];  // offset: 0xf0
    f32 mStarrySkyColorT1;  // offset: 0x130
    f32 mStarrySkyColorT2;  // offset: 0x134
    f32 mMoonAge;  // offset: 0x138
    f32 mMoonFluctuationAmplitude;  // offset: 0x13c
    f32 mMoonFluctuationPhase;  // offset: 0x140
    f32 mMoonBodySize;  // offset: 0x144
    f32 mMoonRadius;  // offset: 0x148
    f32 mMoonDistance;  // offset: 0x14c
    f32 mMoonMultiplier;  // offset: 0x150
    rTexture* mpMoonTexture;  // offset: 0x158
    MtVector3 mMoonColor;  // offset: 0x160
    f32 mEarthShine;  // offset: 0x170
public:
    static MyDTI DTI;
protected:
    static const u32 DATA_VERSION = 6;
};

class rStarCatalog : public cResource
{
public:
    class MyDTI;
    struct StarData;
    struct Header;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct StarData
    {
    public:
        f32 mRightAscension;  // offset: 0x0
        f32 mDeclination;  // offset: 0x4
        f32 mTemperature;  // offset: 0x8
        f32 mIntensity;  // offset: 0xc
    };
public:
    struct Header
    {
    public:
        s32 mMagic;  // offset: 0x0
        u32 mVersion;  // offset: 0x4
        u32 mStarNum;  // offset: 0x8
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
    rStarCatalog();
    virtual ~rStarCatalog();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& in);  // vtable slot 12
    u32 getStarNum() const;
    const StarData* getStarData(u32 index) const;
protected:
    u32 mStarNum;  // offset: 0x70
    StarData* mpStarCatalog;  // offset: 0x78
public:
    static MyDTI DTI;
protected:
    static const u32 mVersion = 0;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK12rStarCatalog5MyDTI11newInstanceEv at 0x011e0e70-0x011e0ea4, code DWARF attributes to no inlined copy
inline rStarCatalog::rStarCatalog() {
    this->::cResource::mAttr = static_cast<u32>(16);
    this->mStarNum = static_cast<u32>(0);
    this->mpStarCatalog = static_cast<rStarCatalog::StarData*>(nullptr);
}
