#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "uBaseModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;

// Declarations
class uSkyCloudModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uSkyCloudModel : public uBaseModel
{
public:
    enum COLOR_TYPE_ENUM
    {
        COLOR_TYPE_DIFFUSE = 0,
        COLOR_TYPE_VERTEX = 1,
        COLOR_TYPE_MAX = 2,
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
    uSkyCloudModel();
    virtual ~uSkyCloudModel();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void setup();  // vtable slot 6
    virtual void setCommonState(cDraw* pdraw);  // vtable slot 32
    void setColorType(u32 type);
    void setSunColorScale(f32 scale);
    void setSaturationScale(f32 scale);
    void setIntensityScale(f32 scale);
    void setFogMulRate(f32 rate);
    void setFogAddRate(f32 rate);
    void setWeatherID(s32 weatherID);
    void setViewType(u32 viewType);
    virtual u32 getAddTransparentDrawPriority();  // vtable slot 31
private:
    s32 mWeatherID;  // offset: 0x11b0
    bool mDayOnly;  // offset: 0x11b4
    u32 mViewType;  // offset: 0x11b8
    u32 mType;  // offset: 0x11bc
    f32 mSunColorHeight;  // offset: 0x11c0
    f32 mSunColorScale;  // offset: 0x11c4
    f32 mSaturationScale;  // offset: 0x11c8
    f32 mIntensityScale;  // offset: 0x11cc
    f32 mAmbColorHeight;  // offset: 0x11d0
    f32 mAmbColorScale;  // offset: 0x11d4
    MtVector3 mSunDir;  // offset: 0x11e0
    MtVector3 mSunColor;  // offset: 0x11f0
    MtVector3 mAmbColor;  // offset: 0x1200
    f32 mFogMulRate;  // offset: 0x1210
    f32 mFogAddRate;  // offset: 0x1214
public:
    static MyDTI DTI;
};
