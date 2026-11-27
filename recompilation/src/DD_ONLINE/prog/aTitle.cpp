// Reconstructed from the game's DWARF debug information.
#include <new>
#include "aTitle.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtFile.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "aBase.h"
#include "aMenu.h"
#include "../../XFramework/cArea.h"
#include "cAreaExt.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "cNetLoginServer.h"
#include "cNetSessionManager.h"
#include "../../XFramework/cResource.h"
#include "cStageEpvCtrl.h"
#include "nNet.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rScheduler.h"
#include "rWeatherInfo.h"
#include "res_ptr.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sBrowser.h"
#include "../../XFramework/sCamera.h"
#include "sDDOMain.h"
#include "sDialogBase.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sHttpPatch.h"
#include "../../XFramework/sMain.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sPlayerManager.h"
#include "../../XFramework/sResource.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sWeatherManager.h"
#include "uGUITitle.h"
#include "../../XFramework/uScheduler.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& aTitle::getDTI() const {
    return aTitle::DTI;
}

aTitle::aTitle() {
    DDON_STUB("aTitle::aTitle")
    /* stub */
}

__attribute__((noinline)) aTitle::~aTitle() {
    DDON_STUB("aTitle::~aTitle")
    /* stub */
}

__attribute__((weak)) bool aTitle::load() {
    DDON_STUB("aTitle::load")
    return {};
}

__attribute__((weak)) void aTitle::init() {
    DDON_STUB("aTitle::init")
    /* stub */
}

__attribute__((weak)) void aTitle::move() {
    DDON_STUB("aTitle::move")
    /* stub */
}

__attribute__((weak)) void aTitle::final() {
    DDON_STUB("aTitle::final")
    /* stub */
}

const MtDTI& aTitle::getParentType() {
    return aBase::DTI;
}

MT_CTSTR aTitle::getShaderSegment() {
    return "root";
}

__attribute__((weak)) s32 aTitle::moveVerCheck() {
    DDON_STUB("aTitle::moveVerCheck")
    return {};
}

__attribute__((weak)) s32 aTitle::moveConnectLoginServer() {
    DDON_STUB("aTitle::moveConnectLoginServer")
    return {};
}

__attribute__((weak)) s32 aTitle::moveGetGameSetting() {
    DDON_STUB("aTitle::moveGetGameSetting")
    return {};
}

void aTitle::loadResTitleWeather() {
    if ((sWeatherManager::mpInstance) == nullptr) {
        return;
    }
    releaseTitleWeather();
    rWeatherParamInfoTbl* p_weather_param = static_cast<rWeatherParamInfoTbl*>(sArchiveManager::getInstance()->createRes("title", "RES_ID_WEATHER_PRM", 1u, false));
    sWeatherManager::getInstance()->setWeatherParamInfoTbl(p_weather_param);
    if (p_weather_param != nullptr) {
        p_weather_param->release();
        rWeatherStageInfo* p_weather_stage = static_cast<rWeatherStageInfo*>(sArchiveManager::getInstance()->createRes("title", "RES_ID_WEATHER_STAGE", 1u, false));
        sWeatherManager::getInstance()->setWeatherStageInfo(p_weather_stage);
        if (p_weather_stage != nullptr) {
            p_weather_stage->release();
            rWeatherParamEfcInfo* p_efc_info = static_cast<rWeatherParamEfcInfo*>(sArchiveManager::getInstance()->createRes("title", "RES_ID_WEATHER_EFC_INF", 1u, false));
            sWeatherManager::getInstance()->setWeatherParamEfcInfo(p_efc_info);
            if (p_efc_info != nullptr) {
                p_efc_info->release();
            }
            sWeatherManager::getInstance()->setSyncGame(false);
            sWeatherManager::getInstance()->clearEventParams();
            sWeatherManager::getInstance()->clearQuestWeatherParams();
        } else {
            rWeatherParamEfcInfo* p_efc_info = static_cast<rWeatherParamEfcInfo*>(sArchiveManager::getInstance()->createRes("title", "RES_ID_WEATHER_EFC_INF", 1u, false));
            sWeatherManager::getInstance()->setWeatherParamEfcInfo(p_efc_info);
            if (p_efc_info != nullptr) {
                p_efc_info->release();
            }
            sWeatherManager::getInstance()->setSyncGame(false);
            sWeatherManager::getInstance()->clearEventParams();
            sWeatherManager::getInstance()->clearQuestWeatherParams();
        }
    } else {
        rWeatherStageInfo* p_weather_stage = static_cast<rWeatherStageInfo*>(sArchiveManager::getInstance()->createRes("title", "RES_ID_WEATHER_STAGE", 1u, false));
        sWeatherManager::getInstance()->setWeatherStageInfo(p_weather_stage);
        if (p_weather_stage != nullptr) {
            p_weather_stage->release();
            rWeatherParamEfcInfo* p_efc_info = static_cast<rWeatherParamEfcInfo*>(sArchiveManager::getInstance()->createRes("title", "RES_ID_WEATHER_EFC_INF", 1u, false));
            sWeatherManager::getInstance()->setWeatherParamEfcInfo(p_efc_info);
            if (p_efc_info != nullptr) {
                p_efc_info->release();
            }
            sWeatherManager::getInstance()->setSyncGame(false);
            sWeatherManager::getInstance()->clearEventParams();
            sWeatherManager::getInstance()->clearQuestWeatherParams();
        } else {
            rWeatherParamEfcInfo* p_efc_info = static_cast<rWeatherParamEfcInfo*>(sArchiveManager::getInstance()->createRes("title", "RES_ID_WEATHER_EFC_INF", 1u, false));
            sWeatherManager::getInstance()->setWeatherParamEfcInfo(p_efc_info);
            if (p_efc_info != nullptr) {
                p_efc_info->release();
            }
            sWeatherManager::getInstance()->setSyncGame(false);
            sWeatherManager::getInstance()->clearEventParams();
            sWeatherManager::getInstance()->clearQuestWeatherParams();
        }
    }
}

__attribute__((weak)) void aTitle::releaseTitleWeather() {
    if (sWeatherManager::getInstance() == nullptr) {
        return;
    }
    sWeatherManager::getInstance()->endEventWeather();
    sWeatherManager::getInstance()->clearWeatherStageUnit();
    sWeatherManager::getInstance()->releaseWeatherEffectParam();
    sWeatherManager::getInstance()->releaseWeatherParamEfcInfo();
    sWeatherManager::getInstance()->releaseWeatherStageInfo();
    sWeatherManager::getInstance()->releaseWeatherParamInfoTbl();
    sWeatherManager::getInstance()->clearEventParams();
    sWeatherManager::getInstance()->clearQuestWeatherParams();
}

void aTitle::updateTitleWeatherReturnMovie() {
    if (mpGUITitle == nullptr) {
        return;
    }
    bool t0 = mpGUITitle->mIsEffectOff;
    if (t0 == mIsEffectOffOld) {
        return;
    }
    uScheduler* p_schr = mpBackScheduler;
    if (t0) {
        sWeatherManager::getInstance()->clearWeatherStageUnit();
        sWeatherManager::getInstance()->resetEffectColorUpdateTime();
        mStageEpvCtrl.deleteEffect();
        if (p_schr != nullptr) {
            p_schr->setPause(true);
        }
    } else {
        sWeatherManager::getInstance()->setEffectColorUpdateTime(2.0f);
        sWeatherManager::getInstance()->setupWeatherStageUnit();
        sWeatherManager::getInstance()->setWeatherMoonEnable(false);
        sWeatherManager::getInstance()->resetWeather();
        if (p_schr != nullptr) {
            p_schr->setPause(false);
        }
    }
    mIsEffectOffOld = t0;
}

inline aTitle::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

aTitle::MyDTI aTitle::DTI("aTitle", &::cAreaExt::DTI, 528ul, 0u, 0u);

__attribute__((weak)) MtObject* aTitle::MyDTI::newInstance() const {
    DDON_STUB("aTitle::MyDTI::newInstance")
    return nullptr;
}

