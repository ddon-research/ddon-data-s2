#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cResource.h"
#include "../shared/nStage.h"
#include "../shared/nZoneUnitCtrl.h"
#include "../shared/rEffectProvider.h"
#include "../shared/rLocationData.h"
#include "../shared/rScheduler.h"
#include "../shared/rSoundAreaInfo.h"
#include "../shared/rWeatherEffectParam.h"
#include "../shared/rWeatherInfo.h"
#include "../shared/rZone.h"
#include "../shared/res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class MtVector3;
class rAIPathConsecutive;
class rCameraParamList;
class rCollision;
class rEffectProvider;
class rLocationData;
class rNavigationMesh;
class rOccluderEx;
class rScheduler;
class rSoundAreaInfo;
class rStartPos;
class rWeatherEffectParam;
class rWeatherParamEfcInfo;
class rWeatherParamInfoTbl;
class rWeatherStageInfo;
class rZone;

// Declarations
class rStageInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rStageInfo : public cResource
{
public:
    enum LOAD_FLAG
    {
        LOAD_FLAG_SCE_DOOR = 1,
        LOAD_FLAG_SCE_FSM = 2,
        LOAD_FLAG_TREE = 4,
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
    rStageInfo();
    virtual ~rStageInfo();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    rScheduler* getScrScheduler() const;
    void setScrScheduler(rScheduler* pRes);
    rScheduler* getFltScheduler() const;
    void setFltScheduler(rScheduler* pRes);
    rCollision* getScrSbc(u32 idx) const;
    void setScrSbc(rCollision* pRes, u32 idx);
    void setScrSbcNum(u32);
    u32 getScrSbcNum() const;
    rCollision* getEffSbc(u32 idx) const;
    void setEffSbc(rCollision* pRes, u32 idx);
    void setEffSbcNum(u32);
    u32 getEffSbcNum() const;
    rNavigationMesh* getNaviMesh() const;
    void setNaviMesh(rNavigationMesh* pRes);
    rAIPathConsecutive* getWayPoint() const;
    void setWayPoint(rAIPathConsecutive* pRes);
    rOccluderEx* getOCC() const;
    void setOCC(rOccluderEx* pRes);
    rStartPos* getStartPos() const;
    void setStartPos(rStartPos* pRes);
    rCameraParamList* getCmrPrmLstFld() const;
    void setCmrPrmLstFld(rCameraParamList* pRes);
    rCameraParamList* getCmrPrmLstEvt() const;
    void setCmrPrmLstEvt(rCameraParamList* pRes);
    MtVector3 getPos() const;
    f32 getAng() const;
    bool isSplit() const;
    bool isJoint() const;
    bool isRand() const;
    bool isCustom() const;
    bool isLargeParty() const;
    bool isWrdOfs() const;
    bool isRevivalPawn() const;
    bool isSolo() const;
    bool isPawnDugeon() const;
    bool isCraft() const;
    bool isWindOff() const;
    bool isDark() const;
    bool isEnvMapSky() const;
    bool isMergoda() const;
    bool isMyRoom() const;
    bool isPartyOnly() const;
    bool isDisableCreateChar() const;
    bool isDisableFadeIn() const;
    u32 getSceLoadFlag() const;
    void setSceLoadFlag(u32);
    f32 getGrassVisiblePercentMulValue() const;
    f32 getGrassFadeBeginDistance() const;
    f32 getGrassFadeEndDistance() const;
    void setSndZoneOcclusion(rZone* p);
    void setSndZoneGenerator(rZone* p);
    void setSndZoneTrigger(rZone* p);
    rZone* getSndZoneOcclusion();
    rZone* getSndZoneGenerator();
    rZone* getSndZoneTrigger();
    f32* getSoundEqLength();
    f32 getSoundEqLengthNo(u32);
    rSoundAreaInfo* getSoundAreaInfo();
    rScheduler* getEffectSchdl();
    rScheduler* getLanternSchdl();
    bool isCraftStage() const;
    rLocationData* getLocation();
    bool isPerformanceFlag(u32 flag);
    void setZoneIndoorScr(rZone* p);
    void setAnotherMapName(const MtString& inputName);
    MT_CTSTR getAnotherMapName() const;
    rWeatherStageInfo* getWeatherStageInfo();
    rWeatherParamInfoTbl* getWeatherParamInfoTbl();
    rWeatherParamEfcInfo* getWeatherParamEfcInfo();
    rWeatherEffectParam* getWep();
    rScheduler* getStageLightSchdl();
    rZone* getZone(nStage::STG_ZONE type);
    rZone* getZoneIndoorScr();
    rZone* getZoneIndoorEfc();
    rZone* getZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type);
    rZone* getZoneStatus();
    rEffectProvider* getEpv();
    s32 getEpvIndexAlways() const;
    s32 getEpvIndexDay() const;
    s32 getEpvIndexNight() const;
    f32 getDayNightLightChgFrame() const;
    f32 getDayNightFogChgFrame() const;
    s32 getSkyInfiniteLightGroupType() const;
private:
    rZone* getZoneColor();
    rZone* getZoneWind();
    rZone* getZoneGene();
    rZone* getZoneLight();
public:
    s32 mStageNo;  // offset: 0x70
    rScheduler* mprModel;  // offset: 0x78
    rScheduler* mprFilter;  // offset: 0x80
    rCollision* mprScrSbc[3];  // offset: 0x88
    rCollision* mprEffSbc[3];  // offset: 0xa0
    rNavigationMesh* mprNaviMesh;  // offset: 0xb8
    rAIPathConsecutive* mprWayPoint;  // offset: 0xc0
    rOccluderEx* mprOCC;  // offset: 0xc8
    rStartPos* mprStartPos;  // offset: 0xd0
    rCameraParamList* mprCmrPrmLstFld;  // offset: 0xd8
    rCameraParamList* mprCmrPrmLstEvt;  // offset: 0xe0
    MtVector3 mPos;  // offset: 0xf0
    f32 mAng;  // offset: 0x100
    u32 mFlag;  // offset: 0x104
    f32 mDayNightLightChgFrame;  // offset: 0x108
    f32 mDayNightFogChgFrame;  // offset: 0x10c
    u32 mSceLoadFlag;  // offset: 0x110
    f32 mGrassVisiblePercentMulValue;  // offset: 0x114
    f32 mGrassFadeBeginDistance;  // offset: 0x118
    f32 mGrassFadeEndDistance;  // offset: 0x11c
    rZone* mprSoundZone[3];  // offset: 0x120
    f32 mEqLength[4];  // offset: 0x138
    res_ptr<rSoundAreaInfo> mprSoundInfo;  // offset: 0x148
    bool mIsCraftStage;  // offset: 0x150
    MT_CHAR mAnotherMapName[16];  // offset: 0x151
    u16 mPerformanceFlag;  // offset: 0x162
    res_ptr<rScheduler> mprEffectSchdl;  // offset: 0x168
    res_ptr<rScheduler> mprLanternSchdl;  // offset: 0x170
    res_ptr<rLocationData> mprLocation;  // offset: 0x178
    res_ptr<rWeatherStageInfo> mpWeatherStageInfo;  // offset: 0x180
    res_ptr<rWeatherParamInfoTbl> mpWeatherParamInfoTbl;  // offset: 0x188
    res_ptr<rScheduler> mpStageLightSchdl;  // offset: 0x190
    res_ptr<rZone> mpZoneList[4];  // offset: 0x198
    res_ptr<rZone> mpZoneIndoorScr;  // offset: 0x1b8
    res_ptr<rZone> mpZoneIndoorEfc;  // offset: 0x1c0
    res_ptr<rWeatherParamEfcInfo> mpWeatherParamEfcInfo;  // offset: 0x1c8
    res_ptr<rWeatherEffectParam> mpWep;  // offset: 0x1d0
    res_ptr<rEffectProvider> mprEpv;  // offset: 0x1d8
    s32 mEpvIndexAlways;  // offset: 0x1e0
    s32 mEpvIndexDay;  // offset: 0x1e4
    s32 mEpvIndexNight;  // offset: 0x1e8
    s32 mSkyInfiniteLightGroupType;  // offset: 0x1ec
    res_ptr<rZone> mpZoneUnitCtrl[3];  // offset: 0x1f0
    res_ptr<rZone> mpZoneStatus;  // offset: 0x208
    static MyDTI DTI;
    static const u8 DATA_VERSION = 81;
private:
    static const u32 mAnotherMapNameMaxLength = 16;
};
