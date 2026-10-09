#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/rTexture.h"
#include "../shared/res_ptr.h"
#include "uSky.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cDraw;
class rTexture;

// Declarations
class uSkyExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uSkyExt : public uSky
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
    uSkyExt(u32 depth_x, u32 depth_y);
    virtual ~uSkyExt();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    void setBaseSunColor(const MtVector3& color);
    void setStarTexture(rTexture* pRes);
    void setStarIntensity(f32 starIntensity);
    void setStarSize(f32 starSize);
    void setStarrySkyIntensity(f32 starrySkyIntensity);
    void setStarTwinkleAmplitude(f32 starTwinkleAmplitude);
    void setStarCount(u32 cnt);
    virtual MtVector3 getBaseSunColor() const;  // vtable slot 24
    void setMoonTexture(rTexture*);
    void onMoon();
private:
    void updateWeather();
    virtual void drawSun(cDraw* pdraw);  // vtable slot 25
    virtual void drawMoon(cDraw* pdraw);  // vtable slot 26
    virtual MtVector3 getSunDirforMoon();  // vtable slot 27
public:
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    MtVector3 getMoonDirection();
    void setMoonEnable(bool b);
private:
    MtVector3 mBaseSunColor;  // offset: 0x500
    res_ptr<rTexture> mpMoonTextureEx;  // offset: 0x510
    f32 mRotX;  // offset: 0x518
    f32 mRotZ;  // offset: 0x51c
    f32 mMoonScale;  // offset: 0x520
    MtVector3 mSunDirforMoon;  // offset: 0x530
public:
    static MyDTI DTI;
};
