#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cSystem.h"
#include "cWeatherScript.h"
#include "cZoneIndoor.h"
#include "cZoneListenerLight.h"
#include "cZoneListenerMulti.h"
#include "nDDOUtility.h"
#include "rFreeF32Tbl.h"
#include "rSoundRequest.h"
#include "rWeatherEffectParam.h"
#include "rWeatherInfo.h"
#include "rZone.h"
#include "res_ptr.h"
#include "sEnvMapManager.h"
#include "uSkyCloud.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtVector3;
class MtVector4;
class cCommonSkyFogData;
class cDayNightColorFogParam;
class cDayNightLightParam;
class cEffectCorrectParam;
class cIndoorSkyFogParam;
class cUnit;
class cWeatherCloudModel;
class cWeatherFogInfo;
class cWeatherInfo;
class cWeatherParam;
class cWeatherParamEfcInfo;
class cWeatherParamInfo;
class cWeatherScript;
class cZoneContents;
class cZoneIndoorHandle;
class cZoneListenerLight;
class cZoneListenerMulti;
namespace nZone { class cLayoutElement; }
class rFreeF32Tbl;
class rModel;
class rScheduler;
class rSky;
class rSoundRequest;
class rWeatherEffectParam;
class rWeatherInfoTbl;
class rWeatherParamEfcInfo;
class rWeatherParamInfoTbl;
class rWeatherStageInfo;
class rZone;
struct stEffectColorParam;
class uBaseModel;
class uScheduler;
class uSkyCloudModel;
class uSkyExt;
class uSkyGrassWind;
class uSkyInfiniteLight;
class uSkySpotLight;
class uSkyStableShadow;

// Declarations
class cCustomWeatherParam;
class sWeatherManager;

enum CUSTOM_WEATHER_FLAG
{
    CUSTOM_WEATHER_FLAG_ENABLE = 0,
    CUSTOM_WEATHER_FLAG_ID = 1,
    CUSTOM_WEATHER_FLAG_TIME = 2,
    CUSTOM_WEATHER_FLAG_SHADOW_PARAM = 3,
    CUSTOM_WEATHER_FLAG_SHADOW_GROUP = 4,
    CUSTOM_WEATHER_FLAG_SHADOW_DIRECTION = 5,
    CUSTOM_WEATHER_FLAG_LENSFLARE_OFF = 6,
    CUSTOM_WEATHER_FLAG_LIGHT_DIRECTION = 7,
    CUSTOM_WEATHER_FLAG_LIGHT_HEMI_COLOR = 8,
    CUSTOM_WEATHER_FLAG_GRASSWIND_PARAM = 9,
    CUSTOM_WEATHER_FLAG_FOG = 10,
    CUSTOM_WEATHER_FLAG_SUN_OFF = 11,
    CUSTOM_WEATHER_FLAG_GRASS_FADE = 12,
    CUSTOM_WEATHER_FLAG_DISABLE_SCRL_ZONE = 13,
    CUSTOM_WEATHER_FLAG_NUM = 14,
};

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cCustomWeatherFlag = nDDOUtility::cBitSet<14>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCustomWeatherParam : public MtObject
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
    cCustomWeatherParam();
    void setCustomWeatherID(u32 val);
    void setCustomTime(u32 val);
    void setCustomTimeHour(u32 val);
    void setCustomTimeMinite(u32 val);
    void setCustomShadowViewDistance(f32 val);
    void setCustomShadowDepthBias(f32 val);
    void setCustomShadowSlopeScaledDepthBias(f32 val);
    void setCustomShadowDistanceScaledDepthBias(f32 val);
    void setCustomShadowGroup0(f32 val);
    void setCustomShadowGroup1(f32 val);
    void setCustomShadowDir(const MtVector3& val);
    void setCustomSunDir(const MtVector3& val);
    void setCustomHemiLightColor(const MtVector3& val);
    void setCustomHemiLightRevColor(const MtVector3& val);
    void setCustomGrassWindDir(const MtVector3& val);
    void setCustomFogStart(f32 val);
    void setCustomFogEnd(f32 val);
    void setCustomFogExponentDensity(f32 val);
    void setCustomFogColor(const MtVector3& val);
    void setCustomGrassFadeBeginDistance(f32 val);
    void setCustomGrassFadeEndDistance(f32 val);
    void resetCustomWeatherParam();
    const cCustomWeatherFlag& getCustomFlag() const;
    u32 getCustomWeatherID() const;
    u32 getCustomTime() const;
    u32 getCustomTimeHour() const;
    u32 getCustomTimeMinite() const;
    f32 getCustomShadowViewDistance() const;
    f32 getCustomShadowDepthBias() const;
    f32 getCustomShadowSlopeScaledDepthBias() const;
    f32 getCustomShadowDistanceScaledDepthBias() const;
    f32 getCustomShadowGroup0() const;
    f32 getCustomShadowGroup1() const;
    MtVector3 getCustomShadowDir() const;
    MtVector3 getCustomSunDir() const;
    MtVector3 getCustomHemiLightColor() const;
    MtVector3 getCustomHemiLightRevColor() const;
    MtVector3 getCustomGrassWindDir() const;
    f32 getCustomGrassFadeBeginDistance() const;
    f32 getCustomGrassFadeEndDistance() const;
    f32 getCustomFogStart() const;
    f32 getCustomFogEnd() const;
    f32 getCustomFogExponentDensity() const;
    MtVector3 getCustomFogColor() const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    cCustomWeatherFlag mCustomFlag;  // offset: 0x8
    u32 mCustomWeatherID;  // offset: 0xc
    u32 mCustomWeatherTime;  // offset: 0x10
    f32 mCustomShadowViewDistance;  // offset: 0x14
    f32 mCustomShadowDepthBias;  // offset: 0x18
    f32 mCustomShadowSlopeScaledDepthBias;  // offset: 0x1c
    f32 mCustomShadowDistanceScaledDepthBias;  // offset: 0x20
    f32 mCustomFogStart;  // offset: 0x24
    f32 mCustomFogEnd;  // offset: 0x28
    f32 mCustomFogExponentDensity;  // offset: 0x2c
    f32 mCustomGrassFadeBeginDistance;  // offset: 0x30
    f32 mCustomGrassFadeEndDistance;  // offset: 0x34
    MtFloat2 mCustomShadowAtten;  // offset: 0x38
    MtVector3 mCustomShadowDir;  // offset: 0x40
    MtVector3 mCustomSunDir;  // offset: 0x50
    MtVector3 mCustomHemiLightColor;  // offset: 0x60
    MtVector3 mCustomHemiLightRevColor;  // offset: 0x70
    MtVector3 mCustomGrassWindDir;  // offset: 0x80
    MtVector3 mCustomFogColor;  // offset: 0x90
    static MyDTI DTI;
};

class sWeatherManager : public cSystem
{
public:
    enum WEATHER_PHASE
    {
        WEATHER_PHASE_DAY = 0,
        WEATHER_PHASE_NIGHT = 1,
        WEATHER_PHASE_NUM = 2,
    };
    enum
    {
        MOON_TYPE_NEW = 0,
        MOON_TYPE_FULL = 1,
        MOON_TYPE_OTHER = 2,
    };
    enum
    {
        OPT_SKY_SPOT_OFF = 0,
        OPT_SKY_INF_MAIN_OFF = 1,
        OPT_SKY_INF_SUB_OFF = 2,
        OPT_SKY_SHADOW_OFF = 3,
        OPT_SKY_CLOUD_OFF = 4,
        OPT_SKY_SHADOW_SMOOTH_OFF = 5,
        OPT_NUM = 6,
    };
public:
    class MyDTI;
    struct stZoneIndoorLightBlend;
public:
    using cOptFlag = nDDOUtility::cBitSet<6>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stZoneIndoorLightBlend
    {
    public:
        f32 now;  // offset: 0x0
        f32 to;  // offset: 0x4
        f32 toOld;  // offset: 0x8
        f32 rate;  // offset: 0xc
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
    sWeatherManager();
    virtual ~sWeatherManager();
    static sWeatherManager* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void callNewGame();
    void callLoadGame();
    void setSyncGame(bool sync);
private:
    void updatePtr();
public:
    void setupEnvMapTexture();
    void releaseEnvMapTexture();
    void setEnvMapSkyForce(bool on);
private:
    void settingWeatherDefault();
    void createGrassWind();
    void setEnvMapRenderTarget(u32 redId, sEnvMapManager::MANAGE_ENVMAP manageEnvMap);
    void setEnvMapTexture(u32 redId, sEnvMapManager::MANAGE_ENVMAP manageEnvMap);
public:
    void setPause(bool flag);
    u32 getWeatherTime() const;
    u32 getWeatherTimeHour() const;
    u32 getWeatherTimeMinute() const;
    u32 getWeatherTimeSecond() const;
    void setWeatherTimefromHMS(u32 hour, u32 min, u32 sec);
private:
    void updateWeatherTime();
    void updateWeatherTimeSync();
    void updateWeatherTimeNoSync();
    void reqWeatherTime(u32 time);
    void setWeatherTimeHour(u32 hour);
    void setWeatherTimeMinute(u32 min);
    void setWeatherTimeSecond(u32 sec);
    bool isWeatherPause() const;
    void updateSkyParam();
    void updateSkyParamNextWeather();
    void updateNextMoonAge();
    void updateSkyParamLightDirection();
    void updateSkyStar();
public:
    bool isEnableSky() const;
    MtVector3 getSunDirection() const;
    WEATHER_PHASE getWeatherPhase() const;
    f32 getDayNightBlendRate() const;
    MtVector3 getFollowSunDirection() const;
    MtVector3 getFollowMoonDirection() const;
private:
    f32 calcDayNightBlendRate(f32 range);
    f32 calcStarTransparency();
    f32 calcFollowSunTransparency();
    f32 calcFollowMoonTransparency();
public:
    void reqWeatherID(u32 id);
    void reqWeatherIDFix(u32 id);
    void reqWeatherIDEx(u32 id, f32 rate);
    f32 getWeatherBlend() const;
    f32 getOutLineCorrectAlpha() const;
    void reqWeatherMoonAge(s32 age);
    s32 getWeatherMoonAge() const;
    bool isWeatherMoonAgeNew() const;
    bool isWeatherMoonAgeFullMoon() const;
    bool isWeatherMoonAgeOther() const;
    f32 getWeatherMoonColorRate() const;
    void setWeatherMoonEnable(bool b);
    f32 getGrassAmbientOcclusionScale() const;
    f32 getGrassAmbientOcclusionOffset() const;
    f32 getGrassLightMapScale() const;
    f32 getGrassLightMapOffset() const;
    void setGrassFadeDistanceStage(f32 begin, f32 end);
    void resetGrassFadeDistanceStage();
    bool isGrassReqFadeDistance() const;
    f32 getGrassFadeBeginDistance() const;
    f32 getGrassFadeEndDistance() const;
    void initGrassWindParam();
    void setGrassWindOff(bool b);
    MtVector3 getGrassWindDirection() const;
    f32 getGrassWindAmp() const;
    f32 getGrassWindFreq() const;
    f32 getGrassWindPhase() const;
    const MtColor& getEffectColor(u32 correctType) const;
    f32 getEffectColorBlend(u32 correctType) const;
    f32 getEffectIntensity(u32 correctType) const;
    f32 getEffectIntensityBlend(u32 correctType) const;
    f32 getEffectEnvMapPowerScale(u32 correctType) const;
    const MtColor& getEffectShadowColor(u32 correctType) const;
    f32 getEffectShadowColorBlend(u32 correctType) const;
    f32 getEffectShadowIntensity(u32 correctType) const;
    f32 getEffectShadowIntensityBlend(u32 correctType) const;
    f32 getEffectColorUpdateTime() const;
    void setEffectColorUpdateTime(f32 val);
    void resetEffectColorUpdateTime();
private:
    void updateWeatherParam();
    void updateWindParam();
    void updateGrassParam();
public:
    s32 getWeatherID() const;
    s32 getWeatherIDOld() const;
    void resetWeather();
    bool isWeatherOnSky() const;
    void constructWeatherParam();
    bool isEnableWeatherID(s32 weatherID);
    bool isEnableWeatherIDOnStage(s32 weatherID);
    bool isWeatherAttrFlag(u32 attr);
    cWeatherInfo* getWeatherInfo(s32 weatherID);
    cWeatherParamInfo* getWeatherParamInfo(s32 weatherID);
    cWeatherParamEfcInfo* getWeatherParamEfcInfo(s32 weatherID);
    void updateWeatherParamNowOld();
private:
    void setWeatherID(s32 weatherID, f32 blend);
    void changeWeatherScript(bool flash);
    void initWeatherCloud();
    void initWeatherCloudSub(cWeatherParamInfo* pInfo);
    void updateWeatherScript();
public:
    f32 getWeatherSoundVolume() const;
    void setSkyInfiniteLightGroupType(s32 type);
    s32 getSkyInfiniteLightGroupType() const;
    void updateWeatherParamBlend();
    f32 calcShadowViewDistance(f32 val) const;
    f32 calcShadowDepthBias(f32 val) const;
    f32 calcShadowSlopeScaledDepthBias(f32 val) const;
    f32 calcShadowDistanceScaledDepthBias(f32 val) const;
    MtVector3 getShadowDirection() const;
    f32 getTransparencyLensFlare() const;
    f32 getTransparencyMoonEffect() const;
    void updateCustomWeather();
    void clearEventParams();
    void beginEventWeather();
    void endEventWeather();
    void clearQuestWeatherParams();
    void beginQuestWeather();
    void endQuestWeather();
    cCustomWeatherParam& questWeather();
    void copyActiveWeatherParam(cCustomWeatherParam& dst);
    bool isCustomWeatherDisableScrlZone();
private:
    const cCustomWeatherParam* getActCustomWeather() const;
    const cCustomWeatherParam* getActCustomWeather(CUSTOM_WEATHER_FLAG flag) const;
public:
    uSkyCloudModel* createWeatherSkyCloud(cWeatherParamInfo* pParamInfo, cWeatherCloudModel* pCloudInfo);
    void clearWeatherCloud();
    void loadResStageWeatherSkyStar(rWeatherStageInfo* pStInfo, uSkyExt* pSky);
    bool isEnableWeather() const;
    void loadWeatherInfoTbl();
    void setWeatherParamInfoTbl(rWeatherParamInfoTbl* pRes);
    void setWeatherStageInfo(rWeatherStageInfo* pRes);
    void setWeatherParamEfcInfo(rWeatherParamEfcInfo* pRes);
    void setWeatherEffectParam(rWeatherEffectParam* pRes);
    void setupWeatherStageUnit();
    void clearWeatherStageUnit();
    void releaseWeatherInfoTbl();
    void releaseWeatherParamInfoTbl();
    void releaseWeatherStageInfo();
    void releaseWeatherParamEfcInfo();
    void releaseWeatherEffectParam();
    uSkyExt* createSkyUnit(rSky* pRes, u32 drawMode, u32 depth_map_width, u32 depth_map_height);
    uScheduler* createLightScheduler(rScheduler* pRes);
    uBaseModel* createStageWeatherModel(rModel* pRes);
    void setSunScatteredColorLight(const MtVector3& color);
    void setSunScatteredColorCloud(const MtVector3& color);
    void setSunScatteredColorWater(const MtVector3& color);
    void setSunAmbientColorCloud(const MtVector3& color);
    void setSunAmbientColorWater(const MtVector3& color);
    const MtVector3& getSunScatteredColorLight() const;
    const MtVector3& getSunScatteredColorCloud() const;
    const MtVector3& getSunScatteredColorWater() const;
    const MtVector3& getSunAmbientColorCloud() const;
    const MtVector3& getSunAmbientColorWater() const;
    const cWeatherParam getWeatherParamResult() const;
    f32 isDisableSun() const;
private:
    MtVector3 calcDummySkySunDirection() const;
public:
    void updateWeatherParamMainLightBlend();
    void updateWeatherParamSubLightBlend();
    void updateWeatherParamHemiLightBlend();
    f32 getLightMainIntensityScale() const;
    f32 getLightMainSatuationScale() const;
    f32 getDayNightFogChgFrame() const;
    void setDayNightLightChgFrame(f32 frame);
    void setDayNightFogChgFrame(f32 frame);
    f32 getLightMainIntensityScale(s32 weatherID);
    f32 getLightMainSatuationScale(s32 weatherID);
    MtVector3 getLightSubDayColor(s32 weatherID);
    f32 getLightFogZoneChgFrame() const;
    void setLightFogZoneChgFrame(f32 frame);
    void calcMainLightColor(MtVector3* pDstColor, f32* pDstColorScale, const MtVector3& nightColor, f32 lightScale, f32 colorScale, bool enableNight);
    MtFloat2 calcMainLightShadowAtten(const MtFloat2& dayAtten, const MtFloat2& nightAtten, bool enableNight);
    MtVector3 calcMainLightDir(bool enableNight);
    MtVector3 calcSubLightColor(const MtVector3& nightColor);
    MtVector3 calcHemiLightColor(const MtVector3& nightColor);
    MtVector3 calcHemiLightRevColor(const MtVector3& nightColor);
    void setLightZoneRes(rZone* resource);
    void releaseLightZoneRes();
    u32 addLightZoneRes(rZone* pZone, const MtVector3& pos);
    void eraseLightZoneRes(u32 handle);
    void initLightZoneRes();
    void eraseLightZoneRes();
    void updateLightParam();
    s32 getCustomDayNightLightID() const;
    s32 getCustomDayNightColorFogID() const;
    const cDayNightLightParam& getCustomDayNightLight() const;
    const cDayNightColorFogParam& getCustomDayNightColorFog() const;
    void updateSkyParamEnvMap();
    f32 getEnvMapBaseScale(cWeatherParamInfo* pInfo, u32 i);
    void updateWeatherFogParamBlend();
    cCommonSkyFogData getWeatherFogInfoBlend();
    f32 getWeatherFogDensity() const;
    cCommonSkyFogData getIndoorSkyColorFogData();
    MtVector3 getSkyAmbientColor(f32 height, f32 scale);
    f32 getCloudHeightOffset() const;
    void updateWaterLRate();
    void updateWaterReflectionRate();
    f32 calcWaterReflectionRate(const MtVector3& sunColor) const;
    f32 getWaterLRate() const;
    f32 getWaterReflectionRate() const;
    void updateEffectColorParam();
    bool calcEffectColorParam(stEffectColorParam* pDst, rWeatherEffectParam* pRes, u32 ctype, u32 wtTime);
    bool isZoneIndoorEfcEpvOff() const;
    void constructorZoneIndoor();
    void initZoneIndoorParam();
    void eraseZoneIndoor();
    cZoneIndoorHandle addZoneIndoorRes(rZone* pComZone, rZone* pScrZone, rZone* pEfcZone, const MtVector3& pos);
    cZoneIndoorHandle addZoneIndoorRes(rZone* pComZone, rZone* pScrZone, rZone* pEfcZone, const MtVector3& pos, const MtQuaternion& quat);
    void eraseZoneIndoorRes(cZoneIndoorHandle& handle);
    void releaseZoneIndoorRes();
    void initZoneIndoorRes();
    void updateZoneIndoor();
    void updateZoneIndoorSoundChange();
    void setSoundAmbientRes(rSoundRequest* pRes);
    void releaseSoundAmbientRes();
    void callbackZoneIndoorNotifiedScr(const nZone::cLayoutElement& e);
    void callbackZoneIndoorNotifiedEfc(const nZone::cLayoutElement& e);
    void callbackZoneIndoorNotifiedSnd(const nZone::cLayoutElement& e);
    bool callbackZoneIndoorAnalyzeScr(cZoneContents& contents);
    bool callbackZoneIndoorAnalyzeEfc(cZoneContents& contents);
    bool callbackZoneIndoorAnalyzeSnd(cZoneContents& contents);
    void initZoneIndoorLightBlend(stZoneIndoorLightBlend* pDst);
    void updateZoneIndoorLightBlendBefore(stZoneIndoorLightBlend* pDst);
    void updateZoneIndoorLightBlendAfter(stZoneIndoorLightBlend* pDst);
    void updateOption();
    cUnit* updateOptionSubSkySchdlUnitOff(uScheduler& schlr, const MtDTI& dti, MT_CTSTR name);
    void setWeatherSkySpotLightOff(bool b);
    void setWeatherSkyInfiniteLightMainOff(bool b);
    void setWeatherSkyInfiniteLightSubOff(bool b);
    void setWeatherSkyStableShadow(bool b);
    void setWeatherSkyCloudOff(bool b);
    void setWeatherSkyStableShadowCascadeSmoothOff(bool b);
    void setWeatherSkyStableShadowCascade(s32 val);
    bool isWeatherSkySpotLightOff() const;
    bool isWeatherSkyInfiniteLightMainOff() const;
    bool isWeatherSkyInfiniteLightSubOff() const;
    bool isWeatherSkyStableShadow() const;
    bool isWeatherSkyCloudOff() const;
    bool isWeatherSkyStableShadowCascadeSmoothOff() const;
    s32 getWeatherSkyStableShadowCascade() const;
    void setWeatherSkyStableShadowBackforwardViewDistance(f32 val);
    f32 getWeatherSkyStableShadowBackforwardViewDistance() const;
protected:
    cWeatherInfo WeatherInfoNone;  // offset: 0x18
private:
    uScheduler* mpSkySchdl;  // offset: 0x148
    uBaseModel* mpStarModel;  // offset: 0x150
    uSkyGrassWind* mpGrassWindNml;  // offset: 0x158
    uSkyExt* mpWeatherSky;  // offset: 0x160
    uSkyExt* mpWeatherRefSky;  // offset: 0x168
    MtTypedArray<uSkyCloudModel> mSkyClouds;  // offset: 0x170
    uSkySpotLight* mpSkySpotLight;  // offset: 0x190
    uSkyInfiniteLight* mpSkyInfiniteLightMain;  // offset: 0x198
    uSkyInfiniteLight* mpSkyInfiniteLightSub;  // offset: 0x1a0
    uSkyStableShadow* mpSkyStableShadow;  // offset: 0x1a8
    res_ptr<rWeatherInfoTbl> mpWeatherInfoTbl;  // offset: 0x1b0
    res_ptr<rFreeF32Tbl> mpWeatherInfoParam;  // offset: 0x1b8
    res_ptr<rWeatherParamInfoTbl> mpWeatherParamInfoTbl;  // offset: 0x1c0
    res_ptr<rWeatherStageInfo> mpWeatherStageInfo;  // offset: 0x1c8
    res_ptr<rWeatherParamEfcInfo> mpWeatherParamEfcInfo;  // offset: 0x1d0
    res_ptr<rWeatherEffectParam> mpWeatherEffectParam;  // offset: 0x1d8
    bool mbSyncGameTime;  // offset: 0x1e0
    bool mbPause;  // offset: 0x1e1
    bool mIsReqWeatherTime;  // offset: 0x1e2
    u32 mWeatherTime;  // offset: 0x1e4
    u32 mReqWeatherTime;  // offset: 0x1e8
    f32 mTimeScale;  // offset: 0x1ec
    f32 mDayNightBlendRate;  // offset: 0x1f0
    f32 mFollowSunTransparency;  // offset: 0x1f4
    f32 mFollowMoonTransparency;  // offset: 0x1f8
    MtVector3 mLightDirection;  // offset: 0x200
    MtVector3 mShadowDirection;  // offset: 0x210
    f32 mShadowLimit;  // offset: 0x220
    f32 mOutLineCorrectAlpha;  // offset: 0x224
    bool mbSyncGameWeather;  // offset: 0x228
    bool mbWeatherChange;  // offset: 0x229
    bool mbSyncGameMoonAge;  // offset: 0x22a
    bool mGrassWindOff;  // offset: 0x22b
    f32 mWeatherBlend;  // offset: 0x22c
    f32 mWeatherChangeFrame;  // offset: 0x230
    s32 mWeatherMoonAge;  // offset: 0x234
    s32 mReqWeatherMoonAge;  // offset: 0x238
    f32 mWeatherSoundVolumeSub;  // offset: 0x23c
    cWeatherParam mWeatherParamResult;  // offset: 0x240
    cWeatherInfo* mpWeatherInfoNow;  // offset: 0x2a0
    cWeatherInfo* mpWeatherInfomOld;  // offset: 0x2a8
    s32 mReqWeatherID;  // offset: 0x2b0
    f32 mReqWeatherRate;  // offset: 0x2b4
    s32 mWeatherID;  // offset: 0x2b8
    s32 mWeatherIdRef;  // offset: 0x2bc
    s32 mWeatherIDOld;  // offset: 0x2c0
    cWeatherParamInfo* mpWeatherParamNow;  // offset: 0x2c8
    cWeatherParamInfo* mpWeatherParamOld;  // offset: 0x2d0
    cWeatherParamEfcInfo* mpWeatherParamEfcNow;  // offset: 0x2d8
    cWeatherParamEfcInfo* mpWeatherParamEfcOld;  // offset: 0x2e0
    cWeatherFogInfo mFogParamBlend;  // offset: 0x2f0
    s32 mSkyInfiniteLightGroupType;  // offset: 0x320
    f32 mWaterReflectionRate;  // offset: 0x324
    f32 mWaterLRate;  // offset: 0x328
    u32 mWeatherSetupRno;  // offset: 0x32c
    f32 mCloudHeightOffset;  // offset: 0x330
    bool mEnvMapSkyForce;  // offset: 0x334
    cWeatherScript mWeatherScript[4];  // offset: 0x338
    cWeatherScript* mpWeatherScriptEfcNow;  // offset: 0x698
    cWeatherScript* mpWeatherScriptEfcOld;  // offset: 0x6a0
    cWeatherScript* mpWeatherScriptSndNow;  // offset: 0x6a8
    cWeatherScript* mpWeatherScriptSndOld;  // offset: 0x6b0
    MtVector4 mGrassAmbientOcclusion;  // offset: 0x6c0
    MtVector4 mGrassDayAmbientOcclusion;  // offset: 0x6d0
    MtVector4 mGrassNightAmbientOcclusion;  // offset: 0x6e0
    f32 mGrassFadeBeginDistance;  // offset: 0x6f0
    f32 mGrassFadeEndDistance;  // offset: 0x6f4
    f32 mGrassFadeBeginDistanceStage;  // offset: 0x6f8
    f32 mGrassFadeEndDistancStage;  // offset: 0x6fc
    bool mGrassReqFadeDistance;  // offset: 0x700
    bool mGrassReqFadeDistanceStage;  // offset: 0x701
    MtVector3 mGrassWindDirection;  // offset: 0x710
    f32 mGrassWindAmp;  // offset: 0x720
    f32 mGrassWindFreq;  // offset: 0x724
    f32 mGrassWindPhase;  // offset: 0x728
    cEffectCorrectParam mEffectColorParam[7];  // offset: 0x730
    f32 mEffectColorUpdateTime;  // offset: 0x880
    cCustomWeatherParam mBlendWeather;  // offset: 0x890
    cCustomWeatherParam mEventWeather;  // offset: 0x930
    cCustomWeatherParam mQuestWeather;  // offset: 0x9d0
    u32 mEventWeatherTime;  // offset: 0xa70
    bool mOnEvent;  // offset: 0xa74
    bool mOnQuestWeather;  // offset: 0xa75
    cOptFlag mOptFlag;  // offset: 0xa78
    s32 mOptShadowCascade;  // offset: 0xa7c
    f32 mOptShadowBackforwardViewDistance;  // offset: 0xa80
    MtVector3 mSunScatteredColorLight;  // offset: 0xa90
    MtVector3 mSunScatteredColorCloud;  // offset: 0xaa0
    MtVector3 mSunScatteredColorWater;  // offset: 0xab0
    MtVector3 mSunAmbientColorCloud;  // offset: 0xac0
    MtVector3 mSunAmbientColorWater;  // offset: 0xad0
    MtVector3 mSunDirection;  // offset: 0xae0
    MtVector3 mInfiniteLightMainDayColor;  // offset: 0xaf0
    MtVector3 mInfiniteLightSubDayColor;  // offset: 0xb00
    MtVector3 mHemiLightDayColorBlend;  // offset: 0xb10
    MtVector3 mHemiLightDayRevColorBlend;  // offset: 0xb20
    f32 mLightMainIntensityScaleBlend;  // offset: 0xb30
    f32 mLightMainSatuationScaleBlend;  // offset: 0xb34
    f32 mDayNightLightChgFrame;  // offset: 0xb38
    f32 mDayNightFogChgFrame;  // offset: 0xb3c
    f32 mHemiMoonAgeRate;  // offset: 0xb40
    f32 mLightFogZoneChgFrame;  // offset: 0xb44
    u32 mOldWeatherMoonAgeType;  // offset: 0xb48
    f32 mHemiMoonAgeChgFrame;  // offset: 0xb4c
    f32 mHemiMoonAgeBlend;  // offset: 0xb50
    cZoneListenerMulti mZoneIndoorListenerScr;  // offset: 0xb60
    cZoneListenerMulti mZoneIndoorListenerEfc;  // offset: 0x1020
    cZoneListenerMulti mZoneIndoorListenerSnd;  // offset: 0x14e0
    f32 mZoneIndoorEfcBlend;  // offset: 0x19a0
    stZoneIndoorLightBlend mZoneIndoorInfiniteLightRate;  // offset: 0x19a4
    stZoneIndoorLightBlend mZoneIndoorHemiLightRate;  // offset: 0x19b4
    stZoneIndoorLightBlend mZoneIndoorHemiLightRevRate;  // offset: 0x19c4
    stZoneIndoorLightBlend mZoneIndoorSubLightRate;  // offset: 0x19d4
    bool mZoneIndoorEfcWeatherOff;  // offset: 0x19e4
    bool mZoneIndoorLightIn;  // offset: 0x19e5
    bool mZoneIndoorEfcEpvOff;  // offset: 0x19e6
    bool mZoneIndoorWindCtrlOff;  // offset: 0x19e7
    f32 mZoneIndoorPosIsCameraToPl;  // offset: 0x19e8
    f32 mZoneIndoorBlendFrame;  // offset: 0x19ec
    s32 mZoneIndoorSoundReqNo;  // offset: 0x19f0
    s32 mZoneIndoorSoundReqNoOld;  // offset: 0x19f4
    res_ptr<rSoundRequest> mpZoneIndoorSoundAmbientRes;  // offset: 0x19f8
    bool mZoneIsUseSkyColorFog;  // offset: 0x1a00
    bool mZoneIsUseSkyColorFogOld;  // offset: 0x1a01
    cIndoorSkyFogParam mZoneSkyColorFogDayParam;  // offset: 0x1a08
    cIndoorSkyFogParam mZoneSkyColorFogNightParam;  // offset: 0x1a28
    f32 mZoneSkyColorFogUseFrame;  // offset: 0x1a48
    res_ptr<rZone> mpLightAndFogZone;  // offset: 0x1a50
    cZoneListenerLight mLightAndFogZoneListener;  // offset: 0x1a60
    cZoneListenerMulti mLightAndFogZoneMultiListener;  // offset: 0x1b70
public:
    static MyDTI DTI;
protected:
    static sWeatherManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sWeatherManager* sWeatherManager::getInstance() {
    return ::sWeatherManager::mpInstance;
}
