#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "nWeather.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cIndoorSkyFogParam;
class cWeatherFogInfo;

// Declarations
class cCommonSkyFogData;
class cDayNightColorFogParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCommonSkyFogData : public MtObject
{
public:
    enum COMMON_SKY_FOG_KIND
    {
        CSFK_NONE = 0,
        CSFK_WEATHER = 1,
        CSFK_INDOOR = 2,
        CSFK_EVENT = 3,
        CSFK_NUM = 4,
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
    cCommonSkyFogData();
    // Address: 0x01ad0190 - 0x01ad0191 (1 bytes)
    virtual ~cCommonSkyFogData() {}
    void setEnable(bool);
    void setColor(MtVector3&);
    void setIntensity(f32);
    void setDensity(f32);
    void setExponentDensity(f32);
    void setStart(f32);
    void setEnd(f32);
    void setSupplementFrame(f32);
    void setKind(u32);
    bool isEnable();
    MtVector3 getColor();
    f32 getIntensity();
    f32 getDensity();
    f32 getExponentDensity();
    f32 getStart();
    f32 getEnd();
    f32 getSupplementFrame();
    u32 getKind();
    void copyData(cCommonSkyFogData* pData);
    bool isSameData(cCommonSkyFogData* pData);
    void init();
    void initFromData(cCommonSkyFogData* pData);
    void initFromData(cIndoorSkyFogParam* pData, MtVector3& color, f32 exdensity, f32 frame, bool enable, u32 kind);
    void initFromData(cWeatherFogInfo* pData, f32 density, f32 frame, u32 kind);
    void updateDataFromLerp(cCommonSkyFogData* pData, f32 rate);
    void updateDataFromLerp(cCommonSkyFogData* pStart, cCommonSkyFogData* pEnd, f32 rate);
private:
    bool mIsEnable;  // offset: 0x8
    MtVector3 mColor;  // offset: 0x10
    f32 mIntensity;  // offset: 0x20
    f32 mDensity;  // offset: 0x24
    f32 mExponentDensity;  // offset: 0x28
    f32 mStart;  // offset: 0x2c
    f32 mEnd;  // offset: 0x30
    f32 mSupplementFrame;  // offset: 0x34
    u32 mKind;  // offset: 0x38
    u32 mId;  // offset: 0x3c
public:
    static MyDTI DTI;
};

class cDayNightColorFogParam : public cWeatherObjectRes
{
public:
    enum DAY_NIGHT_FOG_KIND
    {
        DNFK_NONE = 0,
        DNFK_RESOURCE = 1,
        DNFK_WEATHER = 2,
        DNFK_PARTS = 3,
        DNFK_NUM = 4,
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
    cDayNightColorFogParam();
    // Address: 0x01b22020 - 0x01b22021 (1 bytes)
    virtual ~cDayNightColorFogParam() {}
    void setIsEnable(bool);
    bool isSameData(cDayNightColorFogParam* pData);
    void lerp(const cDayNightColorFogParam& a, const cDayNightColorFogParam& b, f32 rate);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    f32 mHeightStart;  // offset: 0x8
    f32 mHeightEnd;  // offset: 0xc
    f32 mHeightDensity;  // offset: 0x10
    MtVector3 mHeightColor;  // offset: 0x20
    f32 mStart;  // offset: 0x30
    f32 mEnd;  // offset: 0x34
    f32 mDensity;  // offset: 0x38
    MtVector3 mColor;  // offset: 0x40
    f32 mDiffuseBlendFactor;  // offset: 0x50
    bool mIsEnable;  // offset: 0x54
    f32 mSupplementFrame;  // offset: 0x58
    s32 mId;  // offset: 0x5c
    u32 mKind;  // offset: 0x60
    static MyDTI DTI;
};
