// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rStageInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "nStage.h"
#include "../../generated/shared/nZoneUnitCtrl.h"
#include "../../XFramework/rAIPathConsecutive.h"
#include "rCameraParamList.h"
#include "../../XFramework/rCollision.h"
#include "rEffectProvider.h"
#include "rLocationData.h"
#include "../../XFramework/rNavigationMesh.h"
#include "rOccluderExt.h"
#include "../../XFramework/rScheduler.h"
#include "rSoundAreaInfo.h"
#include "rStartPos.h"
#include "rWeatherEffectParam.h"
#include "rWeatherInfo.h"
#include "../../XFramework/rZone.h"
#include "res_ptr.h"
#include "../../XFramework/sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rStageInfo::getDTI() const {
    return rStageInfo::DTI;
}

inline void rStageInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rStageInfo::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rStageInfo::~rStageInfo() {
    clear();
}

MT_CTSTR rStageInfo::getExt() const {
    return "sti";
}

void rStageInfo::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mprModel", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getScrScheduler), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setScrScheduler), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mprFilter", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getFltScheduler), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setFltScheduler), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mprScrSbc", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getScrSbc), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setScrSbc), 32u, reinterpret_cast<MT_MFUNC>(&::rStageInfo::getScrSbcNum), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setScrSbcNum));
    s << MtProperty(static_cast<MtObject*>(this), "mprEffSbc", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getEffSbc), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setEffSbc), 32u, reinterpret_cast<MT_MFUNC>(&::rStageInfo::getEffSbcNum), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setEffSbcNum));
    s << MtProperty(static_cast<MtObject*>(this), "mprNaviMesh", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getNaviMesh), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setNaviMesh), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mprWayPoint", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getWayPoint), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setWayPoint), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mprOCC", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getOCC), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setOCC), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mprStartPos", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getStartPos), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setStartPos), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mprCmrPrmLstFld", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getCmrPrmLstFld), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setCmrPrmLstFld), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mprCmrPrmLstEvt", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getCmrPrmLstEvt), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setCmrPrmLstEvt), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "LocationData", "resource", static_cast<void*>(&mprLocation), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAng", &mAng, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSceLoadFlag", &mSceLoadFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlag", &mFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPerformanceFlag", &mPerformanceFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGrassVisiblePercentMulValue", &mGrassVisiblePercentMulValue, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGrassFadeBeginDistance", &mGrassFadeBeginDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGrassFadeEndDistance", &mGrassFadeEndDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "WeatherStageInfo", "resource", static_cast<void*>(&mpWeatherStageInfo), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "WeatherParamInfoTbl", "resource", static_cast<void*>(&mpWeatherParamInfoTbl), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SkyWep", "resource", static_cast<void*>(&mpWeatherParamEfcInfo), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "RoomWep", "resource", static_cast<void*>(&mpWep), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSkyInfiniteLightGroupType", &mSkyInfiniteLightGroupType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "StageLightSchdl", "resource", static_cast<void*>(&mpStageLightSchdl), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Epv", "resource", static_cast<void*>(&mprEpv), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexAlways", &mEpvIndexAlways, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexDay", &mEpvIndexDay, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvIndexNight", &mEpvIndexNight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "EffectSchdl", "resource", static_cast<void*>(&mprEffectSchdl), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "LanternSchdl", "resource", static_cast<void*>(&mprLanternSchdl), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneColor", "resource", static_cast<void*>(&mpZoneList[0]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneWind", "resource", static_cast<void*>(&mpZoneList[1]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneGene", "resource", static_cast<void*>(&mpZoneList[2]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneLight", "resource", static_cast<void*>(&mpZoneList[3]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneIndoor", "resource", static_cast<void*>(&mpZoneIndoorScr), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneIndoor+ZoneSky", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getZoneIndoorScr), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setZoneIndoorScr), 8194u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "ZoneIndoorEfc", "resource", static_cast<void*>(&mpZoneIndoorEfc), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDayNightLightChgFrame", &mDayNightLightChgFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDayNightFogChgFrame", &mDayNightFogChgFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneCtrlScrl", "resource", static_cast<void*>(&mpZoneUnitCtrl[2]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneCtrlOM", "resource", static_cast<void*>(&mpZoneUnitCtrl[0]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneCtrlLight", "resource", static_cast<void*>(&mpZoneUnitCtrl[1]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ZoneWet", "resource", static_cast<void*>(&mpZoneStatus), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SndZoneOcclusion", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getSndZoneOcclusion), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setSndZoneOcclusion), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "SndZoneGenerator", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getSndZoneGenerator), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setSndZoneGenerator), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "SndZoneTrigger", "resource", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getSndZoneTrigger), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setSndZoneTrigger), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "EQLength", &mEqLength[0], 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "SoundAreaInfo", "resource", static_cast<void*>(&mprSoundInfo), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsCraftStage", &mIsCraftStage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mAnotherMapName", reinterpret_cast<MT_MFUNC>(&::rStageInfo::getAnotherMapName), reinterpret_cast<MT_MFUNC>(&::rStageInfo::setAnotherMapName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "SystemFlag", &mFlag, 2u, 0u);
}

MtUI* rStageInfo::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

__attribute__((weak)) bool rStageInfo::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if (r.readU32() != 0x697473) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != DATA_VERSION) {
        return false;
    }
    
    mStageNo = r.readS32();
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprModel));
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprFilter));
    for (u32 i = 0; i < 3; i++) {
        nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprScrSbc[i]));
        nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprEffSbc[i]));
    }
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprNaviMesh));
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprWayPoint));
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprOCC));
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprStartPos));
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprCmrPrmLstFld));
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprCmrPrmLstEvt));
    
    nDDOIO::readData(r, mPos);
    nDDOIO::readData(r, mAng);
    nDDOIO::readData(r, mSceLoadFlag);
    nDDOIO::readData(r, mFlag);
    
    nDDOIO::readData(r, mpWeatherStageInfo);
    nDDOIO::readData(r, mpWeatherParamInfoTbl);
    nDDOIO::readData(r, mpWeatherParamEfcInfo);
    nDDOIO::readData(r, mpWep);
    nDDOIO::readData(r, mpStageLightSchdl);
    nDDOIO::readData(r, mprEpv);
    nDDOIO::readData(r, mEpvIndexAlways);
    nDDOIO::readData(r, mEpvIndexDay);
    nDDOIO::readData(r, mEpvIndexNight);
    for (u32 i = 0; i < 4; i++) {
        nDDOIO::readData(r, mpZoneList[i]);
    }
    nDDOIO::readData(r, mpZoneIndoorScr);
    nDDOIO::readData(r, mpZoneIndoorEfc);
    
    nDDOIO::readData(r, mDayNightLightChgFrame);
    nDDOIO::readData(r, mDayNightFogChgFrame);
    nDDOIO::readData(r, mSkyInfiniteLightGroupType);
    for (u32 i = 0; i < 3; i++) {
        nDDOIO::readData(r, mpZoneUnitCtrl[i]);
    }
    nDDOIO::readData(r, mpZoneStatus);
    
    for (u32 i = 0; i < 3; i++) {
        nDDOIO::readData(r, reinterpret_cast<cResource*&>(mprSoundZone[i]));
    }
    for (u32 i = 0; i < 4; i++) {
        nDDOIO::readData(r, mEqLength[i]);
    }
    nDDOIO::readData(r, mprSoundInfo);
    nDDOIO::readData(r, mprEffectSchdl);
    nDDOIO::readData(r, mprLanternSchdl);
    nDDOIO::readData(r, mIsCraftStage);
    nDDOIO::readData(r, mprLocation);
    
    nDDOIO::readData(r, mGrassVisiblePercentMulValue);
    nDDOIO::readData(r, mGrassFadeBeginDistance);
    nDDOIO::readData(r, mGrassFadeEndDistance);
    nDDOIO::readData(r, mPerformanceFlag);
    nDDOIO::readData(r, mAnotherMapName, 16u);
    return true;
}

__attribute__((weak)) bool rStageInfo::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    w.writeU32(0x697473);
    w.writeU32(DATA_VERSION);
    
    w.writeS32(mStageNo);
    nDDOIO::writeData(w, static_cast<cResource*>(mprModel));
    nDDOIO::writeData(w, static_cast<cResource*>(mprFilter));
    for (u32 i = 0; i < 3; i++) {
        nDDOIO::writeData(w, static_cast<cResource*>(mprScrSbc[i]));
        nDDOIO::writeData(w, static_cast<cResource*>(mprEffSbc[i]));
    }
    nDDOIO::writeData(w, static_cast<cResource*>(mprNaviMesh));
    nDDOIO::writeData(w, static_cast<cResource*>(mprWayPoint));
    nDDOIO::writeData(w, static_cast<cResource*>(mprOCC));
    nDDOIO::writeData(w, static_cast<cResource*>(mprStartPos));
    nDDOIO::writeData(w, static_cast<cResource*>(mprCmrPrmLstFld));
    nDDOIO::writeData(w, static_cast<cResource*>(mprCmrPrmLstEvt));
    
    nDDOIO::writeData(w, mPos);
    nDDOIO::writeData(w, mAng);
    nDDOIO::writeData(w, mSceLoadFlag);
    nDDOIO::writeData(w, mFlag);
    
    nDDOIO::writeData(w, mpWeatherStageInfo);
    nDDOIO::writeData(w, mpWeatherParamInfoTbl);
    nDDOIO::writeData(w, mpWeatherParamEfcInfo);
    nDDOIO::writeData(w, mpWep);
    nDDOIO::writeData(w, mpStageLightSchdl);
    nDDOIO::writeData(w, mprEpv);
    nDDOIO::writeData(w, mEpvIndexAlways);
    nDDOIO::writeData(w, mEpvIndexDay);
    nDDOIO::writeData(w, mEpvIndexNight);
    for (u32 i = 0; i < 4; i++) {
        nDDOIO::writeData(w, mpZoneList[i]);
    }
    nDDOIO::writeData(w, mpZoneIndoorScr);
    nDDOIO::writeData(w, mpZoneIndoorEfc);
    
    nDDOIO::writeData(w, mDayNightLightChgFrame);
    nDDOIO::writeData(w, mDayNightFogChgFrame);
    nDDOIO::writeData(w, mSkyInfiniteLightGroupType);
    for (u32 i = 0; i < 3; i++) {
        nDDOIO::writeData(w, mpZoneUnitCtrl[i]);
    }
    nDDOIO::writeData(w, mpZoneStatus);
    
    for (u32 i = 0; i < 3; i++) {
        nDDOIO::writeData(w, static_cast<cResource*>(mprSoundZone[i]));
    }
    for (u32 i = 0; i < 4; i++) {
        nDDOIO::writeData(w, mEqLength[i]);
    }
    nDDOIO::writeData(w, mprSoundInfo);
    nDDOIO::writeData(w, mprEffectSchdl);
    nDDOIO::writeData(w, mprLanternSchdl);
    nDDOIO::writeData(w, mIsCraftStage);
    nDDOIO::writeData(w, mprLocation);
    
    nDDOIO::writeData(w, mGrassVisiblePercentMulValue);
    nDDOIO::writeData(w, mGrassFadeBeginDistance);
    nDDOIO::writeData(w, mGrassFadeEndDistance);
    nDDOIO::writeData(w, mPerformanceFlag);
    nDDOIO::writeData(w, mAnotherMapName);
    return true;
}

__attribute__((weak)) void rStageInfo::clear() {
    mStageNo = -1;
    mPos = MtVector3::Zero;
    mAng = 0.0f;
    mFlag = 0;
    mSceLoadFlag = 0;
    
    if (mprModel != nullptr) {
        mprModel->release();
        mprModel = nullptr;
    }
    if (mprFilter != nullptr) {
        mprFilter->release();
        mprFilter = nullptr;
    }
    for (u32 i = 0; i < 3; i++) {
        if (mprScrSbc[i] != nullptr) {
            mprScrSbc[i]->cResource::release();
            mprScrSbc[i] = nullptr;
        }
        if (mprEffSbc[i] != nullptr) {
            mprEffSbc[i]->cResource::release();
            mprEffSbc[i] = nullptr;
        }
    }
    if (mprNaviMesh != nullptr) {
        mprNaviMesh->release();
        mprNaviMesh = nullptr;
    }
    if (mprWayPoint != nullptr) {
        mprWayPoint->release();
        mprWayPoint = nullptr;
    }
    if (mprOCC != nullptr) {
        mprOCC->release();
        mprOCC = nullptr;
    }
    if (mprStartPos != nullptr) {
        mprStartPos->release();
        mprStartPos = nullptr;
    }
    if (mprCmrPrmLstFld != nullptr) {
        mprCmrPrmLstFld->release();
        mprCmrPrmLstFld = nullptr;
    }
    if (mprCmrPrmLstEvt != nullptr) {
        mprCmrPrmLstEvt->release();
        mprCmrPrmLstEvt = nullptr;
    }
    
    mpWeatherStageInfo.releasePtr();
    mpWeatherParamInfoTbl.releasePtr();
    mpWeatherParamEfcInfo.releasePtr();
    mpWep.releasePtr();
    mpStageLightSchdl.releasePtr();
    mprEpv.releasePtr();
    mEpvIndexAlways = -1;
    mEpvIndexDay = -1;
    mEpvIndexNight = -1;
    for (u32 i = 0; i < 4; i++) {
        mpZoneList[i].releasePtr();
    }
    mpZoneIndoorScr.releasePtr();
    mpZoneIndoorEfc.releasePtr();
    
    mDayNightLightChgFrame = 20.0f;
    mDayNightFogChgFrame = 20.0f;
    mSkyInfiniteLightGroupType = 1;
    
    for (u32 i = 0; i < 3; i++) {
        if (mprSoundZone[i] != nullptr) {
            mprSoundZone[i]->cResource::release();
            mprSoundZone[i] = nullptr;
        }
    }
    
    const f32 eq_default[4] = { 1200.0f, 2000.0f, 2800.0f, 4000.0f };
    for (u32 i = 0; i < 4; i++) {
        mEqLength[i] = eq_default[i];
    }
    
    mprSoundInfo.releasePtr();
    mprEffectSchdl.releasePtr();
    mprLanternSchdl.releasePtr();
    mIsCraftStage = false;
    mprLocation.releasePtr();
    
    mGrassVisiblePercentMulValue = 1.0f;
    mGrassFadeBeginDistance = 3000.0f;
    mGrassFadeEndDistance = 5000.0f;
    mPerformanceFlag = 0xffffu;
    memset(mAnotherMapName, 0, sizeof(mAnotherMapName));
}

static auto ddon_emit_0x01ab38c0 __attribute__((used)) = &rStageInfo::getScrScheduler;

void rStageInfo::setScrScheduler(rScheduler* pRes) {
    if (mprModel != nullptr) {
        mprModel->release();
        mprModel = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        mprModel = static_cast<rScheduler*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u));
    } else {
        mprModel = pRes;
        pRes->addRef();
    }
}

static auto ddon_emit_0x01ab38d0 __attribute__((used)) = &rStageInfo::getFltScheduler;

void rStageInfo::setFltScheduler(rScheduler* pRes) {
    if (mprFilter != nullptr) {
        mprFilter->release();
        mprFilter = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        mprFilter = static_cast<rScheduler*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u));
    } else {
        mprFilter = pRes;
        pRes->addRef();
    }
}

static auto ddon_emit_0x01ab38e0 __attribute__((used)) = &rStageInfo::getScrSbc;

void rStageInfo::setScrSbc(rCollision* pRes, u32 idx) {
    if (mprScrSbc[idx] != nullptr) {
        mprScrSbc[idx]->cResource::release();
        mprScrSbc[idx] = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        mprScrSbc[idx] = static_cast<rCollision*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u));
    } else {
        mprScrSbc[idx] = pRes;
        pRes->addRef();
    }
}

__attribute__((weak)) void rStageInfo::setScrSbcNum(u32) {
}

static auto ddon_emit_0x01ab38f0 __attribute__((used)) = &rStageInfo::getScrSbcNum;

static auto ddon_emit_0x01ab3910 __attribute__((used)) = &rStageInfo::getEffSbc;

void rStageInfo::setEffSbc(rCollision* pRes, u32 idx) {
    if (mprEffSbc[idx] != nullptr) {
        mprEffSbc[idx]->cResource::release();
        mprEffSbc[idx] = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        mprEffSbc[idx] = static_cast<rCollision*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u));
    } else {
        mprEffSbc[idx] = pRes;
        pRes->addRef();
    }
}

__attribute__((weak)) void rStageInfo::setEffSbcNum(u32) {
}

static auto ddon_emit_0x01ab3920 __attribute__((used)) = &rStageInfo::getEffSbcNum;

static auto ddon_emit_0x01ab3940 __attribute__((used)) = &rStageInfo::getNaviMesh;

void rStageInfo::setNaviMesh(rNavigationMesh* pRes) {
    if (mprNaviMesh != nullptr) {
        mprNaviMesh->release();
        mprNaviMesh = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        mprNaviMesh = static_cast<rNavigationMesh*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u));
    } else {
        mprNaviMesh = pRes;
        pRes->addRef();
    }
}

static auto ddon_emit_0x01ab3950 __attribute__((used)) = &rStageInfo::getWayPoint;

void rStageInfo::setWayPoint(rAIPathConsecutive* pRes) {
    if (mprWayPoint != nullptr) {
        mprWayPoint->release();
        mprWayPoint = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        mprWayPoint = static_cast<rAIPathConsecutive*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u));
    } else {
        mprWayPoint = pRes;
        pRes->addRef();
    }
}

static auto ddon_emit_0x01ab3960 __attribute__((used)) = &rStageInfo::getOCC;

void rStageInfo::setOCC(rOccluderEx* pRes) {
    if (mprOCC != nullptr) {
        mprOCC->release();
        mprOCC = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        mprOCC = static_cast<rOccluderEx*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u));
    } else {
        mprOCC = pRes;
        pRes->addRef();
    }
}

static auto ddon_emit_0x01ab3970 __attribute__((used)) = &rStageInfo::getStartPos;

void rStageInfo::setStartPos(rStartPos* pRes) {
    if (mprStartPos != nullptr) {
        mprStartPos->release();
        mprStartPos = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        mprStartPos = static_cast<rStartPos*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u));
    } else {
        mprStartPos = pRes;
        pRes->addRef();
    }
}

static auto ddon_emit_0x01ab3980 __attribute__((used)) = &rStageInfo::getCmrPrmLstFld;

void rStageInfo::setCmrPrmLstFld(rCameraParamList* pRes) {
    if (mprCmrPrmLstFld != nullptr) {
        mprCmrPrmLstFld->release();
        mprCmrPrmLstFld = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        if ((mprCmrPrmLstFld = static_cast<rCameraParamList*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u))) != nullptr) {
            mprCmrPrmLstFld->addPriority(1000u);
        }
    } else {
        mprCmrPrmLstFld = pRes;
        pRes->addRef();
        if (mprCmrPrmLstFld != nullptr) {
            mprCmrPrmLstFld->addPriority(1000u);
        }
    }
}

static auto ddon_emit_0x01ab3990 __attribute__((used)) = &rStageInfo::getCmrPrmLstEvt;

void rStageInfo::setCmrPrmLstEvt(rCameraParamList* pRes) {
    if (mprCmrPrmLstEvt != nullptr) {
        mprCmrPrmLstEvt->release();
        mprCmrPrmLstEvt = nullptr;
    }
    if (pRes == nullptr) {
        return;
    }
    if (pRes->isIntermediate()) {
        if ((mprCmrPrmLstEvt = static_cast<rCameraParamList*>(sResource::getInstance()->createNative(static_cast<cResource*>(pRes), 1u))) != nullptr) {
            mprCmrPrmLstEvt->addPriority(1000u);
        }
    } else {
        mprCmrPrmLstEvt = pRes;
        pRes->addRef();
        if (mprCmrPrmLstEvt != nullptr) {
            mprCmrPrmLstEvt->addPriority(1000u);
        }
    }
}

void rStageInfo::setSndZoneOcclusion(rZone* p) {
    if (mprSoundZone[0] != nullptr) {
        mprSoundZone[0]->cResource::release();
        mprSoundZone[0] = nullptr;
    }
    if (p == nullptr) {
        return;
    }
    if (p->isIntermediate()) {
        mprSoundZone[0] = static_cast<rZone*>(sResource::getInstance()->createNative(static_cast<cResource*>(p), 1u));
    } else {
        mprSoundZone[0] = p;
        p->addRef();
    }
}

void rStageInfo::setSndZoneGenerator(rZone* p) {
    if (mprSoundZone[1] != nullptr) {
        mprSoundZone[1]->cResource::release();
        mprSoundZone[1] = nullptr;
    }
    if (p == nullptr) {
        return;
    }
    if (p->isIntermediate()) {
        mprSoundZone[1] = static_cast<rZone*>(sResource::getInstance()->createNative(static_cast<cResource*>(p), 1u));
    } else {
        mprSoundZone[1] = p;
        p->addRef();
    }
}

void rStageInfo::setSndZoneTrigger(rZone* p) {
    if (mprSoundZone[2] != nullptr) {
        mprSoundZone[2]->cResource::release();
        mprSoundZone[2] = nullptr;
    }
    if (p == nullptr) {
        return;
    }
    if (p->isIntermediate()) {
        mprSoundZone[2] = static_cast<rZone*>(sResource::getInstance()->createNative(static_cast<cResource*>(p), 1u));
    } else {
        mprSoundZone[2] = p;
        p->addRef();
    }
}

static auto ddon_emit_0x01ab39d0 __attribute__((used)) = &rStageInfo::getSndZoneOcclusion;

static auto ddon_emit_0x01ab3a50 __attribute__((used)) = &rStageInfo::getSndZoneGenerator;

static auto ddon_emit_0x01ab3ad0 __attribute__((used)) = &rStageInfo::getSndZoneTrigger;

rScheduler* rStageInfo::getEffectSchdl() {
    return mprEffectSchdl.mpPtr;
}

rScheduler* rStageInfo::getLanternSchdl() {
    return mprLanternSchdl.mpPtr;
}

__attribute__((weak)) void rStageInfo::setZoneIndoorScr(rZone* p) {
    DDON_STUB("rStageInfo::setZoneIndoorScr")
    /* stub */
}

void rStageInfo::setAnotherMapName(const MtString& inputName) {
    strncpy(&mAnotherMapName[0], inputName.ptr(), 16ul);
    mAnotherMapName[15] = '\0';
}

MT_CTSTR rStageInfo::getAnotherMapName() const {
    return &mAnotherMapName[0];
}

rWeatherStageInfo* rStageInfo::getWeatherStageInfo() {
    return mpWeatherStageInfo.mpPtr;
}

rWeatherParamInfoTbl* rStageInfo::getWeatherParamInfoTbl() {
    return mpWeatherParamInfoTbl.mpPtr;
}

rWeatherParamEfcInfo* rStageInfo::getWeatherParamEfcInfo() {
    return mpWeatherParamEfcInfo.mpPtr;
}

rWeatherEffectParam* rStageInfo::getWep() {
    return mpWep.mpPtr;
}

rZone* rStageInfo::getZone(nStage::STG_ZONE type) {
    if (type <= 3) {
        return mpZoneList[type].mpPtr;
    } else {
        return nullptr;
    }
}

rZone* rStageInfo::getZoneIndoorScr() {
    return mpZoneIndoorScr.mpPtr;
}

rZone* rStageInfo::getZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type) {
    if (type <= 2) {
        return mpZoneUnitCtrl[type].mpPtr;
    } else {
        return nullptr;
    }
}

rZone* rStageInfo::getZoneStatus() {
    return mpZoneStatus.mpPtr;
}

inline rStageInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageInfo::MyDTI rStageInfo::DTI("rStageInfo", &::cResource::DTI, 528ul, 0u, 0u);

__attribute__((weak)) MtObject* rStageInfo::MyDTI::newInstance() const {
    return new(16u) rStageInfo();
}

