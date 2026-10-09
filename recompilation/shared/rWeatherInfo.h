#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"
#include "nDDOUtility.h"
#include "nWeather.h"
#include "rModel.h"
#include "rScheduler.h"
#include "rSky.h"
#include "rSoundRequest.h"
#include "rTbl2.h"
#include "rTexture.h"
#include "rWeatherEffectParam.h"
#include "rWeatherScript.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
class MtVector3;
class cWeatherScriptCmds;
class rModel;
class rScheduler;
class rSky;
class rSoundRequest;
class rStarCatalog;
class rTexture;
class rWeatherEffectParam;

// Declarations
class cWeatherCloudModel;
class cWeatherFogInfo;
class cWeatherInfo;
class cWeatherParam;
class cWeatherParamEfcInfo;
class cWeatherParamInfo;
class rWeatherFogInfo;
class rWeatherInfoTbl;
class rWeatherParamEfcInfo;
class rWeatherParamInfoTbl;
class rWeatherStageInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cWeatherAttrFlag = nDDOUtility::cBitSet<32>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cWeatherCloudModel : public cWeatherObjectRes
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
    cWeatherCloudModel();
    virtual ~cWeatherCloudModel();
    void load(MtDataReader& r);
    void save(MtDataWriter& w);
public:
    res_ptr<rModel> mpModel;  // offset: 0x8
    u32 mColorType;  // offset: 0x10
    f32 mSunColorScale;  // offset: 0x14
    f32 mSaturationScale;  // offset: 0x18
    f32 mIntensityScale;  // offset: 0x1c
    f32 mFogMulRate;  // offset: 0x20
    f32 mFogAddRate;  // offset: 0x24
    u32 mViewType;  // offset: 0x28
    static MyDTI DTI;
};

class cWeatherFogInfo : public cWeatherObjectRes
{
public:
    enum ResStatus
    {
        DATA_VERSION = 3,
    };
    enum
    {
        CHG_MODE_LINEAR = 0,
        CHG_MODE_SMOOTH = 1,
        CHG_MODE_EXPONENT = 2,
        CHG_MODE_NUM = 3,
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
    cWeatherFogInfo();
    // Address: 0x01abb1c0 - 0x01abb1c1 (1 bytes)
    virtual ~cWeatherFogInfo() {}
    static void lerp(cWeatherFogInfo* pDst, const cWeatherFogInfo& a, const cWeatherFogInfo& b, f32 rate);
    void lerp(const cWeatherFogInfo& a, const cWeatherFogInfo& b, f32 rate);
    static void blend(cWeatherFogInfo* pDst, const cWeatherFogInfo& a, const cWeatherFogInfo& b, f32 rate, u32 mode);
    void blendModeA(const cWeatherFogInfo& a, const cWeatherFogInfo& b, f32 rate);
    static void copy(cWeatherFogInfo* pDst, const cWeatherFogInfo& src);
    void copy(const cWeatherFogInfo& src);
    void resetParam();
public:
    u32 mTime;  // offset: 0x8
    f32 mStart;  // offset: 0xc
    f32 mEnd;  // offset: 0x10
    f32 mExponentDensity;  // offset: 0x14
    u32 mChgMode;  // offset: 0x18
    MtVector3 mColor;  // offset: 0x20
    static MyDTI DTI;
};

class cWeatherInfo : public cWeatherObjectRes
{
public:
    enum ResStatus
    {
        DATA_VERSION = 16,
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
    cWeatherInfo();
    virtual ~cWeatherInfo();
public:
    u16 mID;  // offset: 0x8
    f32 mToFrame;  // offset: 0xc
    f32 mWaterLRate;  // offset: 0x10
    cWeatherScriptCmds mScriptsEfc;  // offset: 0x18
    cWeatherScriptCmds mScriptsSound;  // offset: 0xa0
    cWeatherAttrFlag mWeatherAttrFlag;  // offset: 0x128
    static MyDTI DTI;
};

class cWeatherParam : public cWeatherObjectRes
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
    cWeatherParam();
    static void copy(cWeatherParam* pDst, const cWeatherParam& src);
    static void lerp(cWeatherParam* pDst, const cWeatherParam& a, const cWeatherParam& b, f32 rate);
    static void setupDefault(cWeatherParam* pDst);
    void copy(const cWeatherParam&);
    void lerp(const cWeatherParam& a, const cWeatherParam& b, f32 rate);
    void setupDefault();
    void load(MtDataReader& r);
    void save(MtDataWriter& w);
public:
    MtVector3 mSunColor;  // offset: 0x10
    MtVector3 mMieScattering;  // offset: 0x20
    f32 mMieDensity;  // offset: 0x30
    f32 mCloudHeight;  // offset: 0x34
    f32 mCloudiness;  // offset: 0x38
    f32 mCloudThickness;  // offset: 0x3c
    f32 mCloudScattering;  // offset: 0x40
    f32 mCloudEccentricity;  // offset: 0x44
    f32 mMoonLRate;  // offset: 0x48
    f32 mSunIntensityRate;  // offset: 0x4c
    f32 mEnvMapBaseScale;  // offset: 0x50
    f32 mFogDensity;  // offset: 0x54
    static MyDTI DTI;
};

class cWeatherParamEfcInfo : public cWeatherObjectRes
{
public:
    enum
    {
        DATA_VERSION = 1,
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
    cWeatherParamEfcInfo();
    virtual ~cWeatherParamEfcInfo();
public:
    s32 mWeatherID;  // offset: 0x8
    res_ptr<rWeatherEffectParam> mpEfcParam;  // offset: 0x10
    static MyDTI DTI;
};

class rWeatherFogInfo : public rTbl2<cWeatherFogInfo>
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
    virtual bool loadData(MtDataReader& in, cWeatherFogInfo* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rWeatherInfoTbl : public rTbl2<cWeatherInfo>
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
    virtual bool loadData(MtDataReader& in, cWeatherInfo* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rWeatherParamEfcInfo : public rTbl2<cWeatherParamEfcInfo>
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
    virtual bool loadData(MtDataReader& in, cWeatherParamEfcInfo* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rWeatherStageInfo : public cResource
{
public:
    enum ResStatus
    {
        MAGIC_NUM = 1598640983,
        DATA_VERSION = 7,
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
    rWeatherStageInfo();
    virtual ~rWeatherStageInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    rSky* getSkyRes();
    rSky* getRefSkyRes();
    rScheduler* getModelScheduler();
    rModel* getStarModel();
    rTexture* getStarTexture();
    rStarCatalog* getStarCatalog();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
public:
    res_ptr<rSky> mpSkyRes;  // offset: 0x70
    res_ptr<rSky> mpRefSkyRes;  // offset: 0x78
    res_ptr<rScheduler> mpModelScheduler;  // offset: 0x80
    res_ptr<rModel> mpStarModel;  // offset: 0x88
    res_ptr<rTexture> mpStarTex;  // offset: 0x90
    res_ptr<rStarCatalog> mpStarCatalog;  // offset: 0x98
    f32 mStarSize;  // offset: 0xa0
    f32 mStarrySkyIntensity;  // offset: 0xa4
    f32 mStarTwinkleAmplitude;  // offset: 0xa8
    MtVector3 mEnvMapBaseColor[2];  // offset: 0xb0
    f32 mEnvMapBlendColorScale[2];  // offset: 0xd0
    static MyDTI DTI;
};

class cWeatherParamInfo : public cWeatherObjectRes
{
public:
    enum ResStatus
    {
        DATA_VERSION = 12,
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
    cWeatherParamInfo();
    virtual ~cWeatherParamInfo();
public:
    cWeatherParam mWeatherParam;  // offset: 0x10
    s32 mWeatherID;  // offset: 0x70
    f32 mWeatherSoundVolume;  // offset: 0x74
    f32 mWeatherStarIntensity;  // offset: 0x78
    f32 mLightMainIntensityScale;  // offset: 0x7c
    f32 mLightMainSatuationScale;  // offset: 0x80
    MtVector3 mLightSubDayColor;  // offset: 0x90
    MtVector3 mLightHemiDayColor;  // offset: 0xa0
    MtVector3 mLightHemiDayRevColor;  // offset: 0xb0
    res_ptr<rWeatherFogInfo> mpFogParam;  // offset: 0xc0
    res_ptr<rSoundRequest> mpSoundReq;  // offset: 0xc8
    MtTypedArray<cWeatherCloudModel> mClouds;  // offset: 0xd0
    static MyDTI DTI;
};

class rWeatherParamInfoTbl : public rTbl2<cWeatherParamInfo>
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
    virtual bool loadData(MtDataReader& in, cWeatherParamInfo* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
