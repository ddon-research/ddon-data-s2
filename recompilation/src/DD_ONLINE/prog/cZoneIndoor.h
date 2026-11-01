#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "uSoundTrigger.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cCommonSkyFogData;
class cWeatherFogInfo;

// Declarations
class cIndoorSkyFogParam;
class cZoneIndoorGrassOff;
class cZoneIndoorLight;
class cZoneIndoorWindCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cIndoorSkyFogParam : public MtObject
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
    cIndoorSkyFogParam();
    virtual ~cIndoorSkyFogParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setWeatherId(s32 set);
    void setIntensity(f32 set);
    void setDensity(f32 set);
    void setStart(f32 set);
    void setEnd(f32 set);
    s32 getWeatherId();
    f32 getIntensity();
    f32 getDensity();
    f32 getStart();
    f32 getEnd();
    u32 getId();
    void setupFromCopy(const cIndoorSkyFogParam* pData);
    void setupFromCopy(cIndoorSkyFogParam* pData, f32 density);
    void setupFromCopy(cWeatherFogInfo* pData, f32 density, f32 intensity);
    void setupFromCopy(cCommonSkyFogData* pData);
    void setupFromLerp(cIndoorSkyFogParam* pStart, cIndoorSkyFogParam* pEnd, f32 rate);
    void updateWeatherFogInfo(cWeatherFogInfo* pStart, f32 rate);
    bool isSameData(cIndoorSkyFogParam* pData);
private:
    s32 mWeatherId;  // offset: 0x8
    f32 mIntensity;  // offset: 0xc
    f32 mDensity;  // offset: 0x10
    f32 mStart;  // offset: 0x14
    f32 mEnd;  // offset: 0x18
    u32 mId;  // offset: 0x1c
public:
    static MyDTI DTI;
};

class cZoneIndoorGrassOff : public nSoundTrigger::cCategory
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
    cZoneIndoorGrassOff();
public:
    static MyDTI DTI;
};

class cZoneIndoorLight : public nSoundTrigger::cCategory
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
    cZoneIndoorLight();
    virtual ~cZoneIndoorLight();
    f32 getLightInfiniteRate() const;
    f32 getLightHemiRateDay() const;
    f32 getLightHemiRateDayRev() const;
    f32 getLightHemiRateNight() const;
    f32 getLightHemiRateNightRev() const;
    f32 getLightSubRateDay() const;
    f32 getLightSubRateNight() const;
    bool isUseSkyFogParam();
    f32 getSkyColorFogUseFrame();
    const cIndoorSkyFogParam* getDayFogParam(u32 WeatherId);
    const cIndoorSkyFogParam* getNightFogParam(u32 WeatherId);
    const cIndoorSkyFogParam* getFogParam(MtTypedArray<cIndoorSkyFogParam> pObj, s32 WeatherId);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    f32 mLightInfiniteRate;  // offset: 0x1c
    f32 mLightHemiRateDay;  // offset: 0x20
    f32 mLightHemiRateDayRev;  // offset: 0x24
    f32 mLightHemiRateNight;  // offset: 0x28
    f32 mLightHemiRateNightRev;  // offset: 0x2c
    f32 mLightSubRateDay;  // offset: 0x30
    f32 mLightSubRateNight;  // offset: 0x34
    bool mUseSkyFogParam;  // offset: 0x38
    f32 mSkyColorFogUseFrame;  // offset: 0x3c
    MtTypedArray<cIndoorSkyFogParam> mDayFogParamArray;  // offset: 0x40
    MtTypedArray<cIndoorSkyFogParam> mNightFogParamArray;  // offset: 0x60
public:
    static MyDTI DTI;
};

class cZoneIndoorWindCtrl : public nSoundTrigger::cCategory
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
    cZoneIndoorWindCtrl();
public:
    static MyDTI DTI;
};

inline f32 cIndoorSkyFogParam::getIntensity() {
    return this->mIntensity;
}

inline f32 cIndoorSkyFogParam::getDensity() {
    return this->mDensity;
}

inline f32 cIndoorSkyFogParam::getStart() {
    return this->mStart;
}

inline f32 cIndoorSkyFogParam::getEnd() {
    return this->mEnd;
}

inline u32 cIndoorSkyFogParam::getId() {
    return this->mId;
}

inline cZoneIndoorGrassOff::cZoneIndoorGrassOff() {
}

inline f32 cZoneIndoorLight::getLightInfiniteRate() const {
    return this->mLightInfiniteRate;
}

inline f32 cZoneIndoorLight::getLightHemiRateDay() const {
    return this->mLightHemiRateDay;
}

inline f32 cZoneIndoorLight::getLightHemiRateDayRev() const {
    return this->mLightHemiRateDayRev;
}

inline f32 cZoneIndoorLight::getLightHemiRateNight() const {
    return this->mLightHemiRateNight;
}

inline f32 cZoneIndoorLight::getLightHemiRateNightRev() const {
    return this->mLightHemiRateNightRev;
}

inline f32 cZoneIndoorLight::getLightSubRateDay() const {
    return this->mLightSubRateDay;
}

inline f32 cZoneIndoorLight::getLightSubRateNight() const {
    return this->mLightSubRateNight;
}

inline bool cZoneIndoorLight::isUseSkyFogParam() {
    return this->mUseSkyFogParam;
}

inline f32 cZoneIndoorLight::getSkyColorFogUseFrame() {
    return this->mSkyColorFogUseFrame;
}

inline cZoneIndoorWindCtrl::cZoneIndoorWindCtrl() {
}
