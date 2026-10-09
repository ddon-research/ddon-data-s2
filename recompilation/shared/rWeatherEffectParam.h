#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtColor.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtColorHLS;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtStream;

// Declarations
class cEffectCorrectParam;
class rWeatherEffectParam;
struct stEffectColorParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

struct stEffectColorParam
{
public:
    MtColor Color;  // offset: 0x0
    f32 ColorBlend;  // offset: 0x4
    f32 Intensity;  // offset: 0x8
    f32 IntensityBlend;  // offset: 0xc
    f32 EnvMapPowerScale;  // offset: 0x10
    MtColor ShadowColor;  // offset: 0x14
    f32 ShadowColorBlend;  // offset: 0x18
    f32 ShadowIntensity;  // offset: 0x1c
    f32 ShadowIntensityBlend;  // offset: 0x20
};

class cEffectCorrectParam : public MtObject
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
    cEffectCorrectParam();
    virtual ~cEffectCorrectParam();
    void copy(const cEffectCorrectParam&);
    void setEffectColorParam(const stEffectColorParam& src);
    void load(MtDataReader& r);
    void save(MtDataWriter& w);
    const stEffectColorParam& getEffectColorParam() const;
    void setTime(u32);
    u32 getTime() const;
    const MtColor& getColor() const;
    void setColor(const MtColor&);
    void setColorHLS(const MtColorHLS&);
    f32 getColorBlend() const;
    void setColorBlend(f32);
    f32 getIntensity() const;
    void setIntensity(f32);
    f32 getIntensityBlend() const;
    void setIntensityBlend(f32);
    f32 getEnvMapPowerScale() const;
    void setEnvMapPowerScale(f32);
    const MtColor& getShadowColor() const;
    void setShadowColor(const MtColor&);
    void setShadowColorHLS(const MtColorHLS&);
    f32 getShadowColorBlend() const;
    void setShadowColorBlend(f32);
    f32 getShadowIntensity() const;
    void setShadowIntensity(f32);
    f32 getShadowIntensityBlend() const;
    void setShadowIntensityBlend(f32);
    static void lerpEffectColorParam(stEffectColorParam* pDst, const stEffectColorParam& a, const stEffectColorParam& b, f32 rate);
    static void lerpEffectColorParam(stEffectColorParam* pDst, const cEffectCorrectParam& a, const cEffectCorrectParam& b, f32 rate);
    static void lerpEffectColorParam(stEffectColorParam*, const stEffectColorParam&, const cEffectCorrectParam&, f32);
    static void lerpEffectColorParam(stEffectColorParam*, const cEffectCorrectParam&, const stEffectColorParam&, f32);
public:
    u32 mTime;  // offset: 0x8
    stEffectColorParam mEfcColorParam;  // offset: 0xc
    static MyDTI DTI;
};

class rWeatherEffectParam : public cResource
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
    rWeatherEffectParam();
    virtual ~rWeatherEffectParam();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual const cEffectCorrectParam* getCorrectParam(u32 type, u32 index) const;  // vtable slot 16
    virtual u32 getCorrectParamNum(u32 type) const;  // vtable slot 17
    bool calcEffectColorParam(stEffectColorParam* pDst, u32 ctype, u32 wtTime);
protected:
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
protected:
    MtTypedArray<cEffectCorrectParam> mpParamList[7];  // offset: 0x70
public:
    static MyDTI DTI;
};
