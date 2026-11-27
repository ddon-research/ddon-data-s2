// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sDDOMain.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemory.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSynchronize.h"
#include "../../MT/MtThread.h"
#include "aInit.h"
#include "../../XFramework/cPlatformUtilCommon.h"
#include "../../XFramework/nPhysicsMaterial.h"
#include "../../XFramework/nPhysicsStruct.h"
#include "../../XFramework/nPhysicsSystem.h"
#include "../../XFramework/rArchive.h"
#include "../../XFramework/rCnsIK.h"
#include "../../XFramework/rDeformWeightMap.h"
#include "../../XFramework/rFullbodyIKHuman2.h"
#include "../../XFramework/rModel.h"
#include "../../XFramework/rMotionList.h"
#include "../../XFramework/rMovie.h"
#include "../../XFramework/rOccluder.h"
#include "../../XFramework/rScheduler.h"
#include "../../XFramework/rShader2.h"
#include "../../XFramework/rSky.h"
#include "../../XFramework/rSoundBank.h"
#include "../../XFramework/rSoundDirectionalCurve.h"
#include "../../XFramework/rSoundDirectionalSet.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/rSoundStreamRequest.h"
#include "../../XFramework/rSwingModel.h"
#include "../../XFramework/sAI.h"
#include "sAIExt.h"
#include "sAIPawnNotice.h"
#include "sAIPawnSys.h"
#include "sAIPawnTalkMgr.h"
#include "../../XFramework/sApp.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sAreaHit.h"
#include "sBakingJointOrder.h"
#include "sBazaarManager.h"
#include "../../XFramework/sBenchmark.h"
#include "sBrowser.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sCaplinkManager.h"
#include "../../XFramework/sCapture.h"
#include "sChat.h"
#include "sClanKyoten.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sCommonDialog.h"
#include "sContextManager.h"
#include "sControlManager.h"
#include "../../XFramework/sCoprocessor.h"
#include "sCraftManager.h"
#include "sDialogBase.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sEnemyManager.h"
#include "sEnvMapManager.h"
#include "sEventManager.h"
#include "../../XFramework/sFile.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sGeneralPoint.h"
#include "../../XFramework/sGpuParticle.h"
#include "../../XFramework/sGrass.h"
#include "sGuideExt.h"
#include "sHttpClient.h"
#include "sHttpPatch.h"
#include "sIME.h"
#include "sInputManager.h"
#include "sInputText.h"
#include "sItemManager.h"
#include "sKeyboardExt.h"
#include "sKeyboardInterface.h"
#include "sLightExt.h"
#include "sLockOnManager.h"
#include "../../XFramework/sMain.h"
#include "sMarker.h"
#include "sMenu.h"
#include "sMouseExt.h"
#include "../../XFramework/sMovie.h"
#include "sMyRoom.h"
#include "sNetworkExt.h"
#include "sNpcManager.h"
#include "sObjCollision.h"
#include "sObjCondition.h"
#include "sOccluderExt.h"
#include "sOmManager.h"
#include "sPadExt.h"
#include "sPhysicsExt.h"
#include "../../XFramework/sPlatformUtil.h"
#include "sPlayerManager.h"
#include "../../XFramework/sPrimitive.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sRemoteProcedure.h"
#include "sRemoteProcedureExt.h"
#include "../../XFramework/sRender.h"
#include "sRenderExt.h"
#include "../../XFramework/sResource.h"
#include "sResourceExt.h"
#include "sReward.h"
#include "sSavedataExt.h"
#include "sScenario.h"
#include "sSceneExt.h"
#include "sScreenShot.h"
#include "sSetManager.h"
#include "../../XFramework/sShader2.h"
#include "../../XFramework/sShadow.h"
#include "sShlManager.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sSoundManager.h"
#include "../../XFramework/sSyncPoint.h"
#include "sTalkManager.h"
#include "../../XFramework/sTool.h"
#include "../../XFramework/sToolBase.h"
#include "sToolExt.h"
#include "sTutorialGuide.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "../../XFramework/sUserManager.h"
#include "sVibrationExt.h"
#include "sWeatherManager.h"
#include "sWorkRate.h"
#include "sWorldOffset.h"
#include "../../XFramework/sZone.h"
#include "sZoneStatus.h"
#include "sZoneUnitCtrl.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCnsIK.h"
#include "../../XFramework/uCnsJointOffset.h"
#include "../../XFramework/uCnsLookAt.h"
#include "../../XFramework/uCnsMatrix.h"
#include "../../XFramework/uCnsTinyChain.h"
#include "../../XFramework/uFog.h"
#include "../../XFramework/uFreeCamera.h"
#include "../../XFramework/uFullbodyIKHuman2.h"
#include "../../XFramework/uGUI.h"
#include "../../XFramework/uGrassWind.h"
#include "../../XFramework/uLight.h"
#include "../../XFramework/uModelEx.h"
#include "../../XFramework/uMotionCamera.h"
#include "../../XFramework/uMovie.h"
#include "../../XFramework/uScheduler.h"
#include "../../XFramework/uScreenSpace.h"
#include "../../XFramework/uShadow.h"
#include "../../XFramework/uSimSoftBody.h"
#include "../../XFramework/uSky.h"
#include "../../XFramework/uSwingModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static MT_CTSTR download_path[1] = {
    "nativePS4\\ps4_rom",
};

static MT_CTSTR extract_download_path[3] = {
    "nativePS4\\ps4_rom\\stage",
    "nativePS4\\ps4_rom\\launcher",
    "nativePS4\\ps4_rom\\om",
};

MT_CHAR cCmdLineLoginInfo::loginServerAddr[128];

u32 cCmdLineLoginInfo::loginServerPort;

MT_CHAR cCmdLineLoginInfo::oneTimeToken[64];

MT_CHAR cCmdLineLoginInfo::downloadServerURL[256];

const MtDTI& sDDOMain::getDTI() const {
    return sDDOMain::DTI;
}

sDDOMain::sDDOMain() {
    DDON_STUB("sDDOMain::sDDOMain")
    /* stub */
}

__attribute__((noinline)) sDDOMain::~sDDOMain() {
    DDON_STUB("sDDOMain::~sDDOMain")
    /* stub */
}

void sDDOMain::createProperty(MtPropertyList& s) {
    this->sMain::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mSystemTimer", &mSystemTimer, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRender", reinterpret_cast<MtObject* *>(&mpRender), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpShader2", reinterpret_cast<MtObject* *>(&mpShader2), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpObjCollision", reinterpret_cast<MtObject* *>(&mpObjCollision), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpObjCondition", reinterpret_cast<MtObject* *>(&mpObjCondition), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpUnit", reinterpret_cast<MtObject* *>(&mpUnit), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpLight", reinterpret_cast<MtObject* *>(&mpLight), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpLockOnManager", reinterpret_cast<MtObject* *>(&mpLockOnManager), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTool", reinterpret_cast<MtObject* *>(&mpTool), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpArea", reinterpret_cast<MtObject* *>(&mpArea), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpResource", reinterpret_cast<MtObject* *>(&mpResource), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCamera", reinterpret_cast<MtObject* *>(&mpCamera), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPad", reinterpret_cast<MtObject* *>(&mpPad), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMouse", reinterpret_cast<MtObject* *>(&mpMouse), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpKeyboard", reinterpret_cast<MtObject* *>(&mpKeyboard), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpInputManager", reinterpret_cast<MtObject* *>(&mpInputManager), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpEffect", reinterpret_cast<MtObject* *>(&mpEffect), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCollision", reinterpret_cast<MtObject* *>(&mpCollision), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpGpuParticle", reinterpret_cast<MtObject* *>(&mpGpuParticle), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSound", reinterpret_cast<MtObject* *>(&mpSound), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCapture", reinterpret_cast<MtObject* *>(&mpCapture), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpVibration", reinterpret_cast<MtObject* *>(&mpVibration), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpBenchmark", reinterpret_cast<MtObject* *>(&mpBenchmark), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPhysics2", reinterpret_cast<MtObject* *>(&mpPhysics2), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpAI", reinterpret_cast<MtObject* *>(&mpAI), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpScene", reinterpret_cast<MtObject* *>(&mpScene), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpAreaHit", reinterpret_cast<MtObject* *>(&mpAreaHit), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpZone", reinterpret_cast<MtObject* *>(&mpZone), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpHttpClient", reinterpret_cast<MtObject* *>(&mpHttpClient), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpHttpPatch", reinterpret_cast<MtObject* *>(&mpHttpPatch), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRPC", reinterpret_cast<MtObject* *>(&mpRPC), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpNetwork", reinterpret_cast<MtObject* *>(&mpNetwork), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCaplink", reinterpret_cast<MtObject* *>(&mpCaplink), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpInputText", reinterpret_cast<MtObject* *>(&mpInputText), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSavedata", reinterpret_cast<MtObject* *>(&mpSavedata), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPrimitive", reinterpret_cast<MtObject* *>(&mpPrimitive), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpGrass", reinterpret_cast<MtObject* *>(&mpGrass), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpOccluder", reinterpret_cast<MtObject* *>(&mpOccluder), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpGUI", reinterpret_cast<MtObject* *>(&mpGUI), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpIME", reinterpret_cast<MtObject* *>(&mpIME), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSyncPoint", reinterpret_cast<MtObject* *>(&mpSyncPoint), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpShadow", reinterpret_cast<MtObject* *>(&mpShadow), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpWeatherManager", reinterpret_cast<MtObject* *>(&mpWeatherManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpEnvmap", reinterpret_cast<MtObject* *>(&mpEnvmap), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPlatformUtil", reinterpret_cast<MtObject* *>(&mpPlatformUtil), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpArchiveManager", reinterpret_cast<MtObject* *>(&mpArchiveManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSetManager", reinterpret_cast<MtObject* *>(&mpSetManager), 1280u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpContextManager", reinterpret_cast<MtObject* *>(&mpContextManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpChat", reinterpret_cast<MtObject* *>(&mpChat), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDialog", reinterpret_cast<MtObject* *>(&mpDialog), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpGame", reinterpret_cast<MtObject* *>(&mpGame), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpScenario", reinterpret_cast<MtObject* *>(&mpScenario), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpWorldOffset", reinterpret_cast<MtObject* *>(&mpWorldOffset), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPlayerManager", reinterpret_cast<MtObject* *>(&mpPlayerManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpEnemyManager", reinterpret_cast<MtObject* *>(&mpEnemyManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCtrlManager", reinterpret_cast<MtObject* *>(&mpCtrlManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpNpcManager", reinterpret_cast<MtObject* *>(&mpNpcManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpFlag", reinterpret_cast<MtObject* *>(&mpFlag), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpOmManager", reinterpret_cast<MtObject* *>(&mpOmManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpClanKyoten", reinterpret_cast<MtObject* *>(&mpClanKyoten), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpGeneralPoint", reinterpret_cast<MtObject* *>(&mpGeneralPoint), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpItemManager", reinterpret_cast<MtObject* *>(&mpItemManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpShlManager", reinterpret_cast<MtObject* *>(&mpShlManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSoundManager", reinterpret_cast<MtObject* *>(&mpSoundManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpEventManager", reinterpret_cast<MtObject* *>(&mpEventManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTalkManager", reinterpret_cast<MtObject* *>(&mpTalkManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpAIPawnTalkMgr", reinterpret_cast<MtObject* *>(&mpAIPawnTalkMgr), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCraftManager", reinterpret_cast<MtObject* *>(&mpCraftManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpBazaarManager", reinterpret_cast<MtObject* *>(&mpBazaarManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMenu", reinterpret_cast<MtObject* *>(&mpMenu), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpQuestManagerExt", reinterpret_cast<MtObject* *>(&mpQuestManagerExt), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTutorialGuide", reinterpret_cast<MtObject* *>(&mpTutorialGuide), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMarker", reinterpret_cast<MtObject* *>(&mpMarker), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpReward", reinterpret_cast<MtObject* *>(&mpReward), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMyRoom", reinterpret_cast<MtObject* *>(&mpMyRoom), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpZoneUnitCtrl", reinterpret_cast<MtObject* *>(&mpZoneUnitCtrl), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpZoneStatus", reinterpret_cast<MtObject* *>(&mpZoneStatus), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpBJOrder", reinterpret_cast<MtObject* *>(&mpBJOrder), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpAIPawnNotice", reinterpret_cast<MtObject* *>(&mpAIPawnNotice), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpAIPawnSys", reinterpret_cast<MtObject* *>(&mpAIPawnSys), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpScreenShot", reinterpret_cast<MtObject* *>(&mpScreenShot), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMovie", reinterpret_cast<MtObject* *>(&mpMovie), 0u, 0u);
}

MtUI* sDDOMain::createUI(MtProperty& prop) {
    return this->sMain::createUI(prop);
}

void sDDOMain::reset() {
    mSystemTimer = static_cast<float>(sMain::getInstance()->mFrameTimer);
    mpPlatformUtil->reset();
    mpGpuParticle->reset();
    mpArea->reset();
    mpCapture->reset();
    mpRender->reset();
    mpCaplink->reset();
    mpHttpPatch->reset();
    mpHttpClient->reset();
    mpRPC->reset();
    mpNetwork->reset();
    mpGuide->reset();
    mpTool->reset();
    mpCamera->reset();
    mpPad->reset();
    mpMouse->reset();
    mpKeyboard->reset();
    mpInputManager->reset();
    mpEffect->reset();
    mpCollision->reset();
    mpResource->reset();
    mpShader2->reset();
    mpScene->reset();
    mpSound->reset();
    mpGUI->reset();
    mpIME->reset();
    mpGrass->reset();
    mpOccluder->reset();
    mpVibration->reset();
    mpBenchmark->reset();
    mpAI->reset();
    mpZone->reset();
    mpObjCollision->reset();
    mpObjCondition->reset();
    mpLockOnManager->reset();
    mpUnit->reset();
    mpLight->reset();
    mpPhysics2->reset();
    mpZoneUnitCtrl->reset();
    mpZoneStatus->reset();
    mpShadow->reset();
    mpKbInterface->reset();
    mpChat->reset();
    mpArchiveManager->reset();
    mpSetManager->reset();
    mpContextManager->reset();
    mpGame->reset();
    mpDialog->reset();
    mpAreaHit->reset();
    mpScenario->reset();
    mpWeatherManager->reset();
    mpWorldOffset->reset();
    mpPlayerManager->reset();
    mpEnemyManager->reset();
    mpCtrlManager->reset();
    mpNpcManager->reset();
    mpFlag->reset();
    mpOmManager->reset();
    mpClanKyoten->reset();
    mpItemManager->reset();
    mpShlManager->reset();
    mpGeneralPoint->reset();
    mpSoundManager->reset();
    mpEventManager->reset();
    mpTalkManager->reset();
    mpAIPawnTalkMgr->reset();
    mpCraftManager->reset();
    mpBazaarManager->reset();
    mpMenu->reset();
    mpAIPawnNotice->reset();
    mpAIPawnSys->reset();
    mpInputText->reset();
    mpMovie->reset();
    mpBrowser->reset();
    mpScreenShot->reset();
}

__attribute__((weak)) void sDDOMain::move() {
    DDON_STUB("sDDOMain::move")
    /* stub */
}

bool sDDOMain::close() {
    return this->sMain::close();
}

void sDDOMain::createMenu(MtPropertyList& s) {
    mpGpuParticle->createMenu(s);
    mpTool->createMenu(s);
    mpArea->createMenu(s);
    mpResource->createMenu(s);
    mpRender->createMenu(s);
    this->sMain::createMenu(s);
    mpPlatformUtil->createMenu(s);
    mpBenchmark->createMenu(s);
    mpObjCollision->createMenu(s);
    mpObjCondition->createMenu(s);
    mpUnit->createMenu(s);
    mpLight->createMenu(s);
    mpLockOnManager->createMenu(s);
    mpZoneUnitCtrl->createMenu(s);
    mpZoneStatus->createMenu(s);
    mpCamera->createMenu(s);
    mpPad->createMenu(s);
    mpMouse->createMenu(s);
    mpKeyboard->createMenu(s);
    mpInputManager->createMenu(s);
    mpEffect->createMenu(s);
    mpCollision->createMenu(s);
    mpShader2->createMenu(s);
    mpSound->createMenu(s);
    mpCapture->createMenu(s);
    mpVibration->createMenu(s);
    mpPhysics2->createMenu(s);
    mpAI->createMenu(s);
    mpAreaHit->createMenu(s);
    mpZone->createMenu(s);
    mpHttpClient->createMenu(s);
    mpHttpPatch->createMenu(s);
    mpRPC->createMenu(s);
    mpNetwork->createMenu(s);
    mpCaplink->createMenu(s);
    mpFile->createMenu(s);
    mpPrimitive->createMenu(s);
    sGrass::getInstance()->createMenu(s);
    mpOccluder->createMenu(s);
    mpSyncPoint->createMenu(s);
    mpShadow->createMenu(s);
    mpWeatherManager->createMenu(s);
    mpEnvmap->createMenu(s);
    mpArchiveManager->createMenu(s);
    mpSetManager->createMenu(s);
    mpContextManager->createMenu(s);
    mpKbInterface->createMenu(s);
    mpChat->createMenu(s);
    mpScenario->createMenu(s);
    mpWorldOffset->createMenu(s);
    mpPlayerManager->createMenu(s);
    mpEnemyManager->createMenu(s);
    mpCtrlManager->createMenu(s);
    mpNpcManager->createMenu(s);
    mpFlag->createMenu(s);
    mpOmManager->createMenu(s);
    mpClanKyoten->createMenu(s);
    mpGeneralPoint->createMenu(s);
    mpItemManager->createMenu(s);
    mpShlManager->createMenu(s);
    mpSoundManager->createMenu(s);
    mpEventManager->createMenu(s);
    mpCraftManager->createMenu(s);
    mpBazaarManager->createMenu(s);
    mpMenu->createMenu(s);
    mpAIPawnNotice->createMenu(s);
    mpAIPawnSys->createMenu(s);
    mpBJOrder->createMenu(s);
    mpScreenShot->createMenu(s);
}

void sDDOMain::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mpGpuParticle->applyWorldOffset(offset, MtVector3::Zero);
    mpArea->applyWorldOffset(offset, MtVector3::Zero);
    mpCapture->applyWorldOffset(offset, MtVector3::Zero);
    mpRender->applyWorldOffset(offset, MtVector3::Zero);
    mpTool->applyWorldOffset(offset, MtVector3::Zero);
    mpCamera->applyWorldOffset(offset, MtVector3::Zero);
    mpPad->applyWorldOffset(offset, MtVector3::Zero);
    mpMouse->applyWorldOffset(offset, MtVector3::Zero);
    mpKeyboard->applyWorldOffset(offset, MtVector3::Zero);
    mpEffect->applyWorldOffset(offset, MtVector3::Zero);
    mpCollision->applyWorldOffset(offset, MtVector3::Zero);
    mpResource->applyWorldOffset(offset, MtVector3::Zero);
    mpShader2->applyWorldOffset(offset, MtVector3::Zero);
    mpScene->applyWorldOffset(offset, MtVector3::Zero);
    mpSound->applyWorldOffset(offset, MtVector3::Zero);
    mpGUI->applyWorldOffset(offset, MtVector3::Zero);
    mpIME->applyWorldOffset(offset, MtVector3::Zero);
    mpGrass->applyWorldOffset(offset, absolute_offset);
    mpOccluder->applyWorldOffset(offset, absolute_offset);
    mpVibration->applyWorldOffset(offset, MtVector3::Zero);
    mpBenchmark->applyWorldOffset(offset, MtVector3::Zero);
    mpAI->applyWorldOffset(offset, absolute_offset);
    mpAreaHit->applyWorldOffset(offset, MtVector3::Zero);
    mpZone->applyWorldOffset(offset, MtVector3::Zero);
    mpObjCollision->applyWorldOffset(offset, MtVector3::Zero);
    mpObjCondition->applyWorldOffset(offset, MtVector3::Zero);
    mpUnit->applyWorldOffset(offset, absolute_offset);
    mpLight->applyWorldOffset(offset, absolute_offset);
    mpOmManager->applyWorldOffset(offset, MtVector3::Zero);
    mpClanKyoten->applyWorldOffset(offset, MtVector3::Zero);
    mpLockOnManager->applyWorldOffset(offset, MtVector3::Zero);
    mpPhysics2->applyWorldOffset(offset, MtVector3::Zero);
    mpGeneralPoint->applyWorldOffset(offset, absolute_offset);
}

void sDDOMain::inBackGroundCallback(const char* pparam, const u32 size, const u8* parg, nPlatformUtil::nSystemService::CALL_TYPE::TYPE call_type) {
    if (call_type == nPlatformUtil::nSystemService::CALL_TYPE::END) {
        mIsExecDynamicMenu = false;
    } else {
        if (call_type == nPlatformUtil::nSystemService::CALL_TYPE::BEGIN) {
            mIsExecDynamicMenu = true;
        }
    }
}

__attribute__((weak)) void sDDOMain::resumeCallback(const char* pparam, const u32 size, const u8* parg, nPlatformUtil::nSystemService::CALL_TYPE::TYPE call_type) {
}

bool sDDOMain::isFromLauncher() {
    return (cCmdLineLoginInfo::loginServerPort) != 0;
}

inline sDDOMain::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sDDOMain::MyDTI sDDOMain::DTI("sDDOMain", &::sMain::DTI, 0x57FB0ul, 0u, 0u);

__attribute__((weak)) MtObject* sDDOMain::MyDTI::newInstance() const {
    DDON_STUB("sDDOMain::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void sDDOMain::AsyncThread::execute(void* pcontext) {
    DDON_STUB("sDDOMain::AsyncThread::execute")
    /* stub */
}

