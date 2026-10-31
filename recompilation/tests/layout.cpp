// Each root class's size, and each size a wchar_t's width moves, as DWARF records it (DW_AT_byte_size).
#include "../src/DD_ONLINE/prog/cContextPlayerInfo.h"
#include "../src/DD_ONLINE/prog/cpEnemyThink.h"
#include "../src/DD_ONLINE/prog/nInputText.h"
#include "../src/DD_ONLINE/prog/rAIPawnActNoSwitch.h"
#include "../src/DD_ONLINE/prog/rAIPawnAutoWordTbl.h"
#include "../src/DD_ONLINE/prog/rAIPawnEmParam.h"
#include "../src/DD_ONLINE/prog/rAIPawnOrder.h"
#include "../src/DD_ONLINE/prog/rAIPawnSkillParam.h"
#include "../src/DD_ONLINE/prog/rAISensor.h"
#include "../src/DD_ONLINE/prog/rAbilityList.h"
#include "../src/DD_ONLINE/prog/rAchievement.h"
#include "../src/DD_ONLINE/prog/rAdjustParam.h"
#include "../src/DD_ONLINE/prog/rAnimalData.h"
#include "../src/DD_ONLINE/prog/rArchiveListArray.h"
#include "../src/DD_ONLINE/prog/rAreaInfo.h"
#include "../src/DD_ONLINE/prog/rAreaInfoJointArea.h"
#include "../src/DD_ONLINE/prog/rAreaInfoStage.h"
#include "../src/DD_ONLINE/prog/rAreaMasterSpotData.h"
#include "../src/DD_ONLINE/prog/rAttackParam.h"
#include "../src/DD_ONLINE/prog/rBakeJoint.h"
#include "../src/DD_ONLINE/prog/rBitTable.h"
#include "../src/DD_ONLINE/prog/rBowActParamList.h"
#include "../src/DD_ONLINE/prog/rBrowserFont.h"
#include "../src/DD_ONLINE/prog/rCalcDamage.h"
#include "../src/DD_ONLINE/prog/rCameraParamList.h"
#include "../src/DD_ONLINE/prog/rCameraQuakeList.h"
#include "../src/DD_ONLINE/prog/rCatchInfoParam.h"
#include "../src/DD_ONLINE/prog/rCaughtDamageRateRefTbl.h"
#include "../src/DD_ONLINE/prog/rCaughtDamageRateTbl.h"
#include "../src/DD_ONLINE/prog/rCaughtInfoParam.h"
#include "../src/DD_ONLINE/prog/rCharParamEnemy.h"
#include "../src/DD_ONLINE/prog/rCharacterEdit.h"
#include "../src/DD_ONLINE/prog/rCharacterEditCameraParam.h"
#include "../src/DD_ONLINE/prog/rCharacterEditColorDef.h"
#include "../src/DD_ONLINE/prog/rCharacterEditModelPalette.h"
#include "../src/DD_ONLINE/prog/rCharacterEditMuscle.h"
#include "../src/DD_ONLINE/prog/rCharacterEditPresetPalette.h"
#include "../src/DD_ONLINE/prog/rCharacterEditTexturePalette.h"
#include "../src/DD_ONLINE/prog/rCharacterEditVoicePalette.h"
#include "../src/DD_ONLINE/prog/rCraftCapPass.h"
#include "../src/DD_ONLINE/prog/rCraftElementExp.h"
#include "../src/DD_ONLINE/prog/rCraftQuality.h"
#include "../src/DD_ONLINE/prog/rCraftSkillCost.h"
#include "../src/DD_ONLINE/prog/rCraftSkillSpd.h"
#include "../src/DD_ONLINE/prog/rCraftUpGradeExp.h"
#include "../src/DD_ONLINE/prog/rCycleQuestInfo.h"
#include "../src/DD_ONLINE/prog/rDDOModelMontage.h"
#include "../src/DD_ONLINE/prog/rDDOModelMontageEm.h"
#include "../src/DD_ONLINE/prog/rDmVecWeightParam.h"
#include "../src/DD_ONLINE/prog/rDungeonMarker.h"
#include "../src/DD_ONLINE/prog/rEditStageParam.h"
#include "../src/DD_ONLINE/prog/rEffectProvider.h"
#include "../src/DD_ONLINE/prog/rEmBaseInfoSv.h"
#include "../src/DD_ONLINE/prog/rEmDamageDirInfo.h"
#include "../src/DD_ONLINE/prog/rEmDmgTimerTbl.h"
#include "../src/DD_ONLINE/prog/rEmEffectTable.h"
#include "../src/DD_ONLINE/prog/rEmLvUpParam.h"
#include "../src/DD_ONLINE/prog/rEmScaleTable.h"
#include "../src/DD_ONLINE/prog/rEmScrAdjust.h"
#include "../src/DD_ONLINE/prog/rEmSoundTable.h"
#include "../src/DD_ONLINE/prog/rEmStatusAdj.h"
#include "../src/DD_ONLINE/prog/rEmWarpParam.h"
#include "../src/DD_ONLINE/prog/rEmWeakSafe.h"
#include "../src/DD_ONLINE/prog/rEmWorkRateTable.h"
#include "../src/DD_ONLINE/prog/rEmblemColorTable.h"
#include "../src/DD_ONLINE/prog/rEmoteGroup.h"
#include "../src/DD_ONLINE/prog/rEnemyBloodStain.h"
#include "../src/DD_ONLINE/prog/rEnemyGroup.h"
#include "../src/DD_ONLINE/prog/rEnemyLocalEst.h"
#include "../src/DD_ONLINE/prog/rEnemyLocalShelTable.h"
#include "../src/DD_ONLINE/prog/rEnemyMaterialTable.h"
#include "../src/DD_ONLINE/prog/rEnemyReactResEx.h"
#include "../src/DD_ONLINE/prog/rEnemyStatusChange.h"
#include "../src/DD_ONLINE/prog/rEquipPartsInfo.h"
#include "../src/DD_ONLINE/prog/rEquipPreset.h"
#include "../src/DD_ONLINE/prog/rEquipPresetPalette.h"
#include "../src/DD_ONLINE/prog/rErosionRegion.h"
#include "../src/DD_ONLINE/prog/rErosionRegionScaleChange.h"
#include "../src/DD_ONLINE/prog/rEvaluationTable.h"
#include "../src/DD_ONLINE/prog/rEventParam.h"
#include "../src/DD_ONLINE/prog/rFacialEditJointPreset.h"
#include "../src/DD_ONLINE/prog/rFatAdjust.h"
#include "../src/DD_ONLINE/prog/rFieldAreaAdjoinList.h"
#include "../src/DD_ONLINE/prog/rFieldAreaList.h"
#include "../src/DD_ONLINE/prog/rFieldAreaMarkerInfo.h"
#include "../src/DD_ONLINE/prog/rFieldMapData.h"
#include "../src/DD_ONLINE/prog/rFreeF32Tbl.h"
#include "../src/DD_ONLINE/prog/rFurnitureData.h"
#include "../src/DD_ONLINE/prog/rFurnitureItem.h"
#include "../src/DD_ONLINE/prog/rGUIDogmaOrb.h"
#include "../src/DD_ONLINE/prog/rGUIMapSetting.h"
#include "../src/DD_ONLINE/prog/rGatheringItem.h"
#include "../src/DD_ONLINE/prog/rHeadCtrl.h"
#include "../src/DD_ONLINE/prog/rHumanEnemyCustomSkill.h"
#include "../src/DD_ONLINE/prog/rHumanEnemyEquip.h"
#include "../src/DD_ONLINE/prog/rHumanEnemyParam.h"
#include "../src/DD_ONLINE/prog/rHumanEnemyPreset.h"
#include "../src/DD_ONLINE/prog/rIKCtrl.h"
#include "../src/DD_ONLINE/prog/rItemList.h"
#include "../src/DD_ONLINE/prog/rJobLevelUpTbl.h"
#include "../src/DD_ONLINE/prog/rJobMasterCtrl.h"
#include "../src/DD_ONLINE/prog/rJobTutorialQuestList.h"
#include "../src/DD_ONLINE/prog/rJointEx2.h"
#include "../src/DD_ONLINE/prog/rJointInfo.h"
#include "../src/DD_ONLINE/prog/rJointOrder.h"
#include "../src/DD_ONLINE/prog/rJumpParamTbl.h"
#include "../src/DD_ONLINE/prog/rKeyConfigTextTable.h"
#include "../src/DD_ONLINE/prog/rKeyCustomParam.h"
#include "../src/DD_ONLINE/prog/rLandInfo.h"
#include "../src/DD_ONLINE/prog/rLanguageResIDConverter.h"
#include "../src/DD_ONLINE/prog/rLargeCameraParam.h"
#include "../src/DD_ONLINE/prog/rLayout.h"
#include "../src/DD_ONLINE/prog/rLayoutGroupParam.h"
#include "../src/DD_ONLINE/prog/rLayoutPreset.h"
#include "../src/DD_ONLINE/prog/rLegCtrl.h"
#include "../src/DD_ONLINE/prog/rLoadingParam.h"
#include "../src/DD_ONLINE/prog/rLocationData.h"
#include "../src/DD_ONLINE/prog/rMagicChantParam.h"
#include "../src/DD_ONLINE/prog/rMagicCommand.h"
#include "../src/DD_ONLINE/prog/rMagicCommandWord.h"
#include "../src/DD_ONLINE/prog/rMapSpotData.h"
#include "../src/DD_ONLINE/prog/rMapSpotStageList.h"
#include "../src/DD_ONLINE/prog/rMotionFilter.h"
#include "../src/DD_ONLINE/prog/rMotionParam.h"
#include "../src/DD_ONLINE/prog/rMsgSet.h"
#include "../src/DD_ONLINE/prog/rMyRoomActParam.h"
#include "../src/DD_ONLINE/prog/rNPCEmoMyRoom.h"
#include "../src/DD_ONLINE/prog/rNPCMotMyRoom.h"
#include "../src/DD_ONLINE/prog/rNPCMotionSet.h"
#include "../src/DD_ONLINE/prog/rNamedParam.h"
#include "../src/DD_ONLINE/prog/rNpcConstItem.h"
#include "../src/DD_ONLINE/prog/rNpcCustomSkill.h"
#include "../src/DD_ONLINE/prog/rNpcEditData.h"
#include "../src/DD_ONLINE/prog/rNpcIsNoSetPS3.h"
#include "../src/DD_ONLINE/prog/rNpcIsUseJobParamEx.h"
#include "../src/DD_ONLINE/prog/rNpcLedgerList.h"
#include "../src/DD_ONLINE/prog/rNpcMeetingPlace.h"
#include "../src/DD_ONLINE/prog/rObjCollision.h"
#include "../src/DD_ONLINE/prog/rOccluderExt.h"
#include "../src/DD_ONLINE/prog/rOcdElectricParam.h"
#include "../src/DD_ONLINE/prog/rOcdIrAdj.h"
#include "../src/DD_ONLINE/prog/rOcdParam.h"
#include "../src/DD_ONLINE/prog/rOcdPriority.h"
#include "../src/DD_ONLINE/prog/rOmKey.h"
#include "../src/DD_ONLINE/prog/rOmParam.h"
#include "../src/DD_ONLINE/prog/rOutlineParamList.h"
#include "../src/DD_ONLINE/prog/rPartnerPawnTalk.h"
#include "../src/DD_ONLINE/prog/rPartnerReactParam.h"
#include "../src/DD_ONLINE/prog/rPartsCtrlTable.h"
#include "../src/DD_ONLINE/prog/rPawnAI.h"
#include "../src/DD_ONLINE/prog/rPawnQuestTalk.h"
#include "../src/DD_ONLINE/prog/rPlPartsInfo.h"
#include "../src/DD_ONLINE/prog/rPlantTree.h"
#include "../src/DD_ONLINE/prog/rPriorityThink.h"
#include "../src/DD_ONLINE/prog/rPrologueHmStatus.h"
#include "../src/DD_ONLINE/prog/rPushRate.h"
#include "../src/DD_ONLINE/prog/rQuestHistoryData.h"
#include "../src/DD_ONLINE/prog/rQuestList.h"
#include "../src/DD_ONLINE/prog/rQuestMarkerInfo.h"
#include "../src/DD_ONLINE/prog/rQuestSequenceList.h"
#include "../src/DD_ONLINE/prog/rQuestTextData.h"
#include "../src/DD_ONLINE/prog/rReaction.h"
#include "../src/DD_ONLINE/prog/rRegionStatusParam.h"
#include "../src/DD_ONLINE/prog/rReplaceWardGmdList.h"
#include "../src/DD_ONLINE/prog/rRoomWearParam.h"
#include "../src/DD_ONLINE/prog/rScenario.h"
#include "../src/DD_ONLINE/prog/rShakeCtrl.h"
#include "../src/DD_ONLINE/prog/rShlLimit.h"
#include "../src/DD_ONLINE/prog/rShlParamList.h"
#include "../src/DD_ONLINE/prog/rShopGoods.h"
#include "../src/DD_ONLINE/prog/rShotReqInfo.h"
#include "../src/DD_ONLINE/prog/rShotReqInfo2.h"
#include "../src/DD_ONLINE/prog/rSituationMsgCtrl.h"
#include "../src/DD_ONLINE/prog/rSndPitchLimit.h"
#include "../src/DD_ONLINE/prog/rSoundAreaInfo.h"
#include "../src/DD_ONLINE/prog/rSoundAttributeSe.h"
#include "../src/DD_ONLINE/prog/rSoundBossBgm.h"
#include "../src/DD_ONLINE/prog/rSoundHitInfo.h"
#include "../src/DD_ONLINE/prog/rSoundMotionSe.h"
#include "../src/DD_ONLINE/prog/rSoundOptData.h"
#include "../src/DD_ONLINE/prog/rSoundParamOfs.h"
#include "../src/DD_ONLINE/prog/rSoundSequenceSe.h"
#include "../src/DD_ONLINE/prog/rSoundSubMixer.h"
#include "../src/DD_ONLINE/prog/rSoundSubMixerSet.h"
#include "../src/DD_ONLINE/prog/rStageAdjoinList.h"
#include "../src/DD_ONLINE/prog/rStageConnect.h"
#include "../src/DD_ONLINE/prog/rStageCustom.h"
#include "../src/DD_ONLINE/prog/rStageCustomParts.h"
#include "../src/DD_ONLINE/prog/rStageCustomPartsEx.h"
#include "../src/DD_ONLINE/prog/rStageInfo.h"
#include "../src/DD_ONLINE/prog/rStageJoint.h"
#include "../src/DD_ONLINE/prog/rStageList.h"
#include "../src/DD_ONLINE/prog/rStageMap.h"
#include "../src/DD_ONLINE/prog/rStageToSpot.h"
#include "../src/DD_ONLINE/prog/rStaminaDecTbl.h"
#include "../src/DD_ONLINE/prog/rStartPos.h"
#include "../src/DD_ONLINE/prog/rStartPosArea.h"
#include "../src/DD_ONLINE/prog/rStatusCheck.h"
#include "../src/DD_ONLINE/prog/rStatusGainTable.h"
#include "../src/DD_ONLINE/prog/rTargetCursorOffset.h"
#include "../src/DD_ONLINE/prog/rTbl2ChatMacro.h"
#include "../src/DD_ONLINE/prog/rTblMenuComm.h"
#include "../src/DD_ONLINE/prog/rTblMenuOption.h"
#include "../src/DD_ONLINE/prog/rTexDetailEdit.h"
#include "../src/DD_ONLINE/prog/rTutorialDialogMessage.h"
#include "../src/DD_ONLINE/prog/rTutorialList.h"
#include "../src/DD_ONLINE/prog/rTutorialQuestGroup.h"
#include "../src/DD_ONLINE/prog/rWarpLocation.h"
#include "../src/DD_ONLINE/prog/rWaypoint.h"
#include "../src/DD_ONLINE/prog/rWaypoint2.h"
#include "../src/DD_ONLINE/prog/rWeaponOffset.h"
#include "../src/DD_ONLINE/prog/rWeaponResTable.h"
#include "../src/DD_ONLINE/prog/rWeatherEffectParam.h"
#include "../src/DD_ONLINE/prog/rWeatherInfo.h"
#include "../src/DD_ONLINE/prog/rWepCateResTbl.h"
#include "../src/DD_ONLINE/prog/sEffectExt.h"
#include "../src/DD_ONLINE/prog/sIMEPS4.h"
#include "../src/DD_ONLINE/prog/sKeyboardInterface.h"
#include "../src/DD_ONLINE/prog/sLightExt.h"
#include "../src/DD_ONLINE/prog/uGUIInputText.h"
#include "../src/DD_ONLINE/prog/uGUIPopCnvWnd.h"
#include "../src/XFramework/rAIFSM.h"
#include "../src/XFramework/rArchive.h"
#include "../src/XFramework/rCameraList.h"
#include "../src/XFramework/rCnsIK.h"
#include "../src/XFramework/rCnsTinyChain.h"
#include "../src/XFramework/rCollision.h"
#include "../src/XFramework/rDeformWeightMap.h"
#include "../src/XFramework/rEffect2D.h"
#include "../src/XFramework/rEffectAnim.h"
#include "../src/XFramework/rEffectList.h"
#include "../src/XFramework/rEffectStrip.h"
#include "../src/XFramework/rFullbodyIKHuman2.h"
#include "../src/XFramework/rGUI.h"
#include "../src/XFramework/rGUIFont.h"
#include "../src/XFramework/rGUIIconInfo.h"
#include "../src/XFramework/rGUIMessage.h"
#include "../src/XFramework/rGrass.h"
#include "../src/XFramework/rGrassWind.h"
#include "../src/XFramework/rMaterial.h"
#include "../src/XFramework/rModel.h"
#include "../src/XFramework/rMotionList.h"
#include "../src/XFramework/rNavigationMesh.h"
#include "../src/XFramework/rOccluder.h"
#include "../src/XFramework/rRenderTargetTexture.h"
#include "../src/XFramework/rRigidBody.h"
#include "../src/XFramework/rScheduler.h"
#include "../src/XFramework/rSky.h"
#include "../src/XFramework/rSoundBank.h"
#include "../src/XFramework/rSoundCurveSet.h"
#include "../src/XFramework/rSoundDirectionalSet.h"
#include "../src/XFramework/rSoundEQ.h"
#include "../src/XFramework/rSoundRequest.h"
#include "../src/XFramework/rSoundReverb.h"
#include "../src/XFramework/rSoundStreamRequest.h"
#include "../src/XFramework/rSwingModel.h"
#include "../src/XFramework/rTexture.h"
#include "../src/XFramework/rVibration.h"
#include "../src/XFramework/rZone.h"

static_assert(sizeof(::rAIFSM) == 144, "rAIFSM: DWARF's byte_size is 144");
static_assert(sizeof(::rAIPawnActNoSwitch) == 128, "rAIPawnActNoSwitch: DWARF's byte_size is 128");
static_assert(sizeof(::rAIPawnAutoMotionTbl) == 144, "rAIPawnAutoMotionTbl: DWARF's byte_size is 144");
static_assert(sizeof(::rAIPawnAutoWordTbl) == 128, "rAIPawnAutoWordTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rAIPawnEmParam) == 136, "rAIPawnEmParam: DWARF's byte_size is 136");
static_assert(sizeof(::rAIPawnOrder) == 128, "rAIPawnOrder: DWARF's byte_size is 128");
static_assert(sizeof(::rAIPawnSkillParamTbl) == 128, "rAIPawnSkillParamTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rAISensor) == 152, "rAISensor: DWARF's byte_size is 152");
static_assert(sizeof(::rAbilityList) == 144, "rAbilityList: DWARF's byte_size is 144");
static_assert(sizeof(::rAchievement) == 128, "rAchievement: DWARF's byte_size is 128");
static_assert(sizeof(::rAchievementHeader) == 128, "rAchievementHeader: DWARF's byte_size is 128");
static_assert(sizeof(::rActorLight) == 176, "rActorLight: DWARF's byte_size is 176");
static_assert(sizeof(::rAdjLimitParam) == 128, "rAdjLimitParam: DWARF's byte_size is 128");
static_assert(sizeof(::rAdjustParam) == 128, "rAdjustParam: DWARF's byte_size is 128");
static_assert(sizeof(::rAnimalData) == 128, "rAnimalData: DWARF's byte_size is 128");
static_assert(sizeof(::rArchive) == 152, "rArchive: DWARF's byte_size is 152");
static_assert(sizeof(::rArchiveListArray) == 128, "rArchiveListArray: DWARF's byte_size is 128");
static_assert(sizeof(::rAreaInfo) == 144, "rAreaInfo: DWARF's byte_size is 144");
static_assert(sizeof(::rAreaInfoJointArea) == 144, "rAreaInfoJointArea: DWARF's byte_size is 144");
static_assert(sizeof(::rAreaInfoStage) == 144, "rAreaInfoStage: DWARF's byte_size is 144");
static_assert(sizeof(::rAreaMasterRankData) == 128, "rAreaMasterRankData: DWARF's byte_size is 128");
static_assert(sizeof(::rAreaMasterSpotData) == 128, "rAreaMasterSpotData: DWARF's byte_size is 128");
static_assert(sizeof(::rAreaMasterSpotDetailData) == 128, "rAreaMasterSpotDetailData: DWARF's byte_size is 128");
static_assert(sizeof(::rAttackParam) == 160, "rAttackParam: DWARF's byte_size is 160");
static_assert(sizeof(::rBakeJoint) == 128, "rBakeJoint: DWARF's byte_size is 128");
static_assert(sizeof(::rBitTable) == 128, "rBitTable: DWARF's byte_size is 128");
static_assert(sizeof(::rBlowSaveEmLvParam) == 128, "rBlowSaveEmLvParam: DWARF's byte_size is 128");
static_assert(sizeof(::rBowActParamList) == 144, "rBowActParamList: DWARF's byte_size is 144");
static_assert(sizeof(::rBrowserFont) == 128, "rBrowserFont: DWARF's byte_size is 128");
static_assert(sizeof(::rCalcDamageAtdmAdj) == 128, "rCalcDamageAtdmAdj: DWARF's byte_size is 128");
static_assert(sizeof(::rCalcDamageAtdmAdjRate) == 128, "rCalcDamageAtdmAdjRate: DWARF's byte_size is 128");
static_assert(sizeof(::rCalcDamageLvAdj) == 128, "rCalcDamageLvAdj: DWARF's byte_size is 128");
static_assert(sizeof(::rCameraList) == 120, "rCameraList: DWARF's byte_size is 120");
static_assert(sizeof(::rCameraParamList) == 160, "rCameraParamList: DWARF's byte_size is 160");
static_assert(sizeof(::rCameraQuakeList) == 144, "rCameraQuakeList: DWARF's byte_size is 144");
static_assert(sizeof(::rCatchInfoParam) == 128, "rCatchInfoParam: DWARF's byte_size is 128");
static_assert(sizeof(::rCaughtDamageRateRefTbl) == 128, "rCaughtDamageRateRefTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rCaughtDamageRateTbl) == 128, "rCaughtDamageRateTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rCaughtInfoParam) == 128, "rCaughtInfoParam: DWARF's byte_size is 128");
static_assert(sizeof(::rCharParamEnemy) == 128, "rCharParamEnemy: DWARF's byte_size is 128");
static_assert(sizeof(::rCharacterEdit) == 120, "rCharacterEdit: DWARF's byte_size is 120");
static_assert(sizeof(::rCharacterEditCameraParam) == 128, "rCharacterEditCameraParam: DWARF's byte_size is 128");
static_assert(sizeof(::rCharacterEditColorDef) == 128, "rCharacterEditColorDef: DWARF's byte_size is 128");
static_assert(sizeof(::rCharacterEditModelPalette) == 128, "rCharacterEditModelPalette: DWARF's byte_size is 128");
static_assert(sizeof(::rCharacterEditMuscle) == 128, "rCharacterEditMuscle: DWARF's byte_size is 128");
static_assert(sizeof(::rCharacterEditPresetPalette) == 128, "rCharacterEditPresetPalette: DWARF's byte_size is 128");
static_assert(sizeof(::rCharacterEditTexturePalette) == 128, "rCharacterEditTexturePalette: DWARF's byte_size is 128");
static_assert(sizeof(::rCharacterEditVoicePalette) == 128, "rCharacterEditVoicePalette: DWARF's byte_size is 128");
static_assert(sizeof(::rChildRegionStatusParam) == 128, "rChildRegionStatusParam: DWARF's byte_size is 128");
static_assert(sizeof(::rChildRegionStatusParamList) == 128, "rChildRegionStatusParamList: DWARF's byte_size is 128");
static_assert(sizeof(::rCnsIK) == 896, "rCnsIK: DWARF's byte_size is 896");
static_assert(sizeof(::rCnsTinyChain) == 192, "rCnsTinyChain: DWARF's byte_size is 192");
static_assert(sizeof(::rCollision) == 272, "rCollision: DWARF's byte_size is 272");
static_assert(sizeof(::rCraftCapPass) == 128, "rCraftCapPass: DWARF's byte_size is 128");
static_assert(sizeof(::rCraftElementExp) == 128, "rCraftElementExp: DWARF's byte_size is 128");
static_assert(sizeof(::rCraftQuality) == 128, "rCraftQuality: DWARF's byte_size is 128");
static_assert(sizeof(::rCraftSkillCost) == 128, "rCraftSkillCost: DWARF's byte_size is 128");
static_assert(sizeof(::rCraftSkillSpd) == 128, "rCraftSkillSpd: DWARF's byte_size is 128");
static_assert(sizeof(::rCraftUpGradeExp) == 128, "rCraftUpGradeExp: DWARF's byte_size is 128");
static_assert(sizeof(::rCustimShlLimit) == 128, "rCustimShlLimit: DWARF's byte_size is 128");
static_assert(sizeof(::rCycleQuestInfo) == 144, "rCycleQuestInfo: DWARF's byte_size is 144");
static_assert(sizeof(::rDDOModelMontage) == 120, "rDDOModelMontage: DWARF's byte_size is 120");
static_assert(sizeof(::rDDOModelMontageEm) == 120, "rDDOModelMontageEm: DWARF's byte_size is 120");
static_assert(sizeof(::rDamageSaveEmLvParam) == 128, "rDamageSaveEmLvParam: DWARF's byte_size is 128");
static_assert(sizeof(::rDamageSpecialAdj) == 128, "rDamageSpecialAdj: DWARF's byte_size is 128");
static_assert(sizeof(::rDeformWeightMap) == 304, "rDeformWeightMap: DWARF's byte_size is 304");
static_assert(sizeof(::rDmJobAdjParam) == 128, "rDmJobAdjParam: DWARF's byte_size is 128");
static_assert(sizeof(::rDmJobPawnAdjParam) == 128, "rDmJobPawnAdjParam: DWARF's byte_size is 128");
static_assert(sizeof(::rDmLvPawnAdjParam) == 128, "rDmLvPawnAdjParam: DWARF's byte_size is 128");
static_assert(sizeof(::rDmVecWeightParam) == 128, "rDmVecWeightParam: DWARF's byte_size is 128");
static_assert(sizeof(::rDungeonMarker) == 184, "rDungeonMarker: DWARF's byte_size is 184");
static_assert(sizeof(::rEditStageParam) == 144, "rEditStageParam: DWARF's byte_size is 144");
static_assert(sizeof(::rEffect2D) == 208, "rEffect2D: DWARF's byte_size is 208");
static_assert(sizeof(::rEffectAnim) == 128, "rEffectAnim: DWARF's byte_size is 128");
static_assert(sizeof(::rEffectList) == 184, "rEffectList: DWARF's byte_size is 184");
static_assert(sizeof(::rEffectProvider) == 176, "rEffectProvider: DWARF's byte_size is 176");
static_assert(sizeof(::rEffectStrip) == 144, "rEffectStrip: DWARF's byte_size is 144");
static_assert(sizeof(::rEmBaseInfoSv) == 128, "rEmBaseInfoSv: DWARF's byte_size is 128");
static_assert(sizeof(::rEmDamageDirInfo) == 128, "rEmDamageDirInfo: DWARF's byte_size is 128");
static_assert(sizeof(::rEmDmgTimerTbl) == 128, "rEmDmgTimerTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rEmEffectTable) == 176, "rEmEffectTable: DWARF's byte_size is 176");
static_assert(sizeof(::rEmLvUpParam) == 128, "rEmLvUpParam: DWARF's byte_size is 128");
static_assert(sizeof(::rEmScaleTable) == 128, "rEmScaleTable: DWARF's byte_size is 128");
static_assert(sizeof(::rEmScrAdjust) == 128, "rEmScrAdjust: DWARF's byte_size is 128");
static_assert(sizeof(::rEmSoundTable) == 128, "rEmSoundTable: DWARF's byte_size is 128");
static_assert(sizeof(::rEmStatusAdj) == 128, "rEmStatusAdj: DWARF's byte_size is 128");
static_assert(sizeof(::rEmWarpParam) == 128, "rEmWarpParam: DWARF's byte_size is 128");
static_assert(sizeof(::rEmWeakSafe) == 128, "rEmWeakSafe: DWARF's byte_size is 128");
static_assert(sizeof(::rEmWorkRateTable) == 128, "rEmWorkRateTable: DWARF's byte_size is 128");
static_assert(sizeof(::rEmblemColorTable) == 128, "rEmblemColorTable: DWARF's byte_size is 128");
static_assert(sizeof(::rEmoteGroup) == 128, "rEmoteGroup: DWARF's byte_size is 128");
static_assert(sizeof(::rEnemyBloodStain) == 128, "rEnemyBloodStain: DWARF's byte_size is 128");
static_assert(sizeof(::rEnemyGroup) == 128, "rEnemyGroup: DWARF's byte_size is 128");
static_assert(sizeof(::rEnemyLocalEst) == 128, "rEnemyLocalEst: DWARF's byte_size is 128");
static_assert(sizeof(::rEnemyLocalShelTable) == 128, "rEnemyLocalShelTable: DWARF's byte_size is 128");
static_assert(sizeof(::rEnemyMaterialTable) == 128, "rEnemyMaterialTable: DWARF's byte_size is 128");
static_assert(sizeof(::rEnemyReactResEx) == 328, "rEnemyReactResEx: DWARF's byte_size is 328");
static_assert(sizeof(::rEnemyStatusChange) == 128, "rEnemyStatusChange: DWARF's byte_size is 128");
static_assert(sizeof(::rEquipPartsInfo) == 120, "rEquipPartsInfo: DWARF's byte_size is 120");
static_assert(sizeof(::rEquipPreset) == 128, "rEquipPreset: DWARF's byte_size is 128");
static_assert(sizeof(::rEquipPresetPalette) == 128, "rEquipPresetPalette: DWARF's byte_size is 128");
static_assert(sizeof(::rErosionInfoRes) == 128, "rErosionInfoRes: DWARF's byte_size is 128");
static_assert(sizeof(::rErosionRegion) == 128, "rErosionRegion: DWARF's byte_size is 128");
static_assert(sizeof(::rErosionRegionScaleChange) == 128, "rErosionRegionScaleChange: DWARF's byte_size is 128");
static_assert(sizeof(::rErosionShakeConvert) == 128, "rErosionShakeConvert: DWARF's byte_size is 128");
static_assert(sizeof(::rErosionSmallInfoRes) == 128, "rErosionSmallInfoRes: DWARF's byte_size is 128");
static_assert(sizeof(::rErosionSuperInfoRes) == 128, "rErosionSuperInfoRes: DWARF's byte_size is 128");
static_assert(sizeof(::rEvaluationTable) == 128, "rEvaluationTable: DWARF's byte_size is 128");
static_assert(sizeof(::rEventParam) == 128, "rEventParam: DWARF's byte_size is 128");
static_assert(sizeof(::rFacialEditJointPreset) == 128, "rFacialEditJointPreset: DWARF's byte_size is 128");
static_assert(sizeof(::rFatAdjust) == 128, "rFatAdjust: DWARF's byte_size is 128");
static_assert(sizeof(::rFieldAreaAdjoinList) == 128, "rFieldAreaAdjoinList: DWARF's byte_size is 128");
static_assert(sizeof(::rFieldAreaList) == 128, "rFieldAreaList: DWARF's byte_size is 128");
static_assert(sizeof(::rFieldAreaMarkerInfo) == 152, "rFieldAreaMarkerInfo: DWARF's byte_size is 152");
static_assert(sizeof(::rFieldMapData) == 128, "rFieldMapData: DWARF's byte_size is 128");
static_assert(sizeof(::rFreeF32Tbl) == 120, "rFreeF32Tbl: DWARF's byte_size is 120");
static_assert(sizeof(::rFullbodyIKHuman2) == 1520, "rFullbodyIKHuman2: DWARF's byte_size is 1520");
static_assert(sizeof(::rFurnitureData) == 128, "rFurnitureData: DWARF's byte_size is 128");
static_assert(sizeof(::rFurnitureGroup) == 128, "rFurnitureGroup: DWARF's byte_size is 128");
static_assert(sizeof(::rFurnitureItem) == 128, "rFurnitureItem: DWARF's byte_size is 128");
static_assert(sizeof(::rFurnitureLayout) == 128, "rFurnitureLayout: DWARF's byte_size is 128");
static_assert(sizeof(::rGUI) == 248, "rGUI: DWARF's byte_size is 248");
static_assert(sizeof(::rGUIDogmaOrb) == 128, "rGUIDogmaOrb: DWARF's byte_size is 128");
static_assert(sizeof(::rGUIFont) == 256, "rGUIFont: DWARF's byte_size is 256");
static_assert(sizeof(::rGUIIconInfo) == 136, "rGUIIconInfo: DWARF's byte_size is 136");
static_assert(sizeof(::rGUIMapSetting) == 200, "rGUIMapSetting: DWARF's byte_size is 200");
static_assert(sizeof(::rGUIMessage) == 2248, "rGUIMessage: DWARF's byte_size is 2248");
static_assert(sizeof(::rGatheringItem) == 128, "rGatheringItem: DWARF's byte_size is 128");
static_assert(sizeof(::rGrass) == 10784, "rGrass: DWARF's byte_size is 10784");
static_assert(sizeof(::rGrassWind) == 160, "rGrassWind: DWARF's byte_size is 160");
static_assert(sizeof(::rHeadCtrl) == 184, "rHeadCtrl: DWARF's byte_size is 184");
static_assert(sizeof(::rHumanEnemyCustomSkill) == 128, "rHumanEnemyCustomSkill: DWARF's byte_size is 128");
static_assert(sizeof(::rHumanEnemyEquip) == 128, "rHumanEnemyEquip: DWARF's byte_size is 128");
static_assert(sizeof(::rHumanEnemyParam) == 128, "rHumanEnemyParam: DWARF's byte_size is 128");
static_assert(sizeof(::rHumanEnemyPreset) == 128, "rHumanEnemyPreset: DWARF's byte_size is 128");
static_assert(sizeof(::rIKCtrl) == 184, "rIKCtrl: DWARF's byte_size is 184");
static_assert(sizeof(::rItemList) == 224, "rItemList: DWARF's byte_size is 224");
static_assert(sizeof(::rJobBaseParam) == 128, "rJobBaseParam: DWARF's byte_size is 128");
static_assert(sizeof(::rJobLevelUpTbl2) == 128, "rJobLevelUpTbl2: DWARF's byte_size is 128");
static_assert(sizeof(::rJobMasterCtrl) == 128, "rJobMasterCtrl: DWARF's byte_size is 128");
static_assert(sizeof(::rJobTutorialQuestList) == 144, "rJobTutorialQuestList: DWARF's byte_size is 144");
static_assert(sizeof(::rJointEx2) == 128, "rJointEx2: DWARF's byte_size is 128");
static_assert(sizeof(::rJointInfo) == 128, "rJointInfo: DWARF's byte_size is 128");
static_assert(sizeof(::rJointOrder) == 128, "rJointOrder: DWARF's byte_size is 128");
static_assert(sizeof(::rJumpParamTbl) == 128, "rJumpParamTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rKeyConfigTextTable) == 160, "rKeyConfigTextTable: DWARF's byte_size is 160");
static_assert(sizeof(::rKeyCustomParam) == 128, "rKeyCustomParam: DWARF's byte_size is 128");
static_assert(sizeof(::rLandInfo) == 144, "rLandInfo: DWARF's byte_size is 144");
static_assert(sizeof(::rLanguageResIDConverter) == 120, "rLanguageResIDConverter: DWARF's byte_size is 120");
static_assert(sizeof(::rLargeCameraParam) == 128, "rLargeCameraParam: DWARF's byte_size is 128");
static_assert(sizeof(::rLayout) == 528, "rLayout: DWARF's byte_size is 528");
static_assert(sizeof(::rLayoutGroupParamList) == 2320, "rLayoutGroupParamList: DWARF's byte_size is 2320");
static_assert(sizeof(::rLayoutPreset) == 128, "rLayoutPreset: DWARF's byte_size is 128");
static_assert(sizeof(::rLegCtrl) == 208, "rLegCtrl: DWARF's byte_size is 208");
static_assert(sizeof(::rLoadingParam) == 144, "rLoadingParam: DWARF's byte_size is 144");
static_assert(sizeof(::rLocationData) == 128, "rLocationData: DWARF's byte_size is 128");
static_assert(sizeof(::rMagicChantParam) == 128, "rMagicChantParam: DWARF's byte_size is 128");
static_assert(sizeof(::rMagicCommandList) == 144, "rMagicCommandList: DWARF's byte_size is 144");
static_assert(sizeof(::rMagicCommandWord) == 128, "rMagicCommandWord: DWARF's byte_size is 128");
static_assert(sizeof(::rMapSpotData) == 128, "rMapSpotData: DWARF's byte_size is 128");
static_assert(sizeof(::rMapSpotStageList) == 128, "rMapSpotStageList: DWARF's byte_size is 128");
static_assert(sizeof(::rMaterial) == 128, "rMaterial: DWARF's byte_size is 128");
static_assert(sizeof(::rModel) == 672, "rModel: DWARF's byte_size is 672");
static_assert(sizeof(::rMotionFilter) == 128, "rMotionFilter: DWARF's byte_size is 128");
static_assert(sizeof(::rMotionList) == 120, "rMotionList: DWARF's byte_size is 120");
static_assert(sizeof(::rMotionParam) == 128, "rMotionParam: DWARF's byte_size is 128");
static_assert(sizeof(::rMsgSet) == 176, "rMsgSet: DWARF's byte_size is 176");
static_assert(sizeof(::rMyRoomActParam) == 128, "rMyRoomActParam: DWARF's byte_size is 128");
static_assert(sizeof(::rNPCEmoMyRoom) == 128, "rNPCEmoMyRoom: DWARF's byte_size is 128");
static_assert(sizeof(::rNPCMotMyRoom) == 128, "rNPCMotMyRoom: DWARF's byte_size is 128");
static_assert(sizeof(::rNPCMotionSet) == 208, "rNPCMotionSet: DWARF's byte_size is 208");
static_assert(sizeof(::rNamedParam) == 128, "rNamedParam: DWARF's byte_size is 128");
static_assert(sizeof(::rNavigationMesh) == 240, "rNavigationMesh: DWARF's byte_size is 240");
static_assert(sizeof(::rNpcConstItem) == 128, "rNpcConstItem: DWARF's byte_size is 128");
static_assert(sizeof(::rNpcCustomSkill) == 128, "rNpcCustomSkill: DWARF's byte_size is 128");
static_assert(sizeof(::rNpcEditData) == 184, "rNpcEditData: DWARF's byte_size is 184");
static_assert(sizeof(::rNpcIsNoSetPS3) == 128, "rNpcIsNoSetPS3: DWARF's byte_size is 128");
static_assert(sizeof(::rNpcIsUseJobParamEx) == 128, "rNpcIsUseJobParamEx: DWARF's byte_size is 128");
static_assert(sizeof(::rNpcLedgerList) == 144, "rNpcLedgerList: DWARF's byte_size is 144");
static_assert(sizeof(::rNpcMeetingPlace) == 128, "rNpcMeetingPlace: DWARF's byte_size is 128");
static_assert(sizeof(::rObjCollision) == 136, "rObjCollision: DWARF's byte_size is 136");
static_assert(sizeof(::rOccluder) == 128, "rOccluder: DWARF's byte_size is 128");
static_assert(sizeof(::rOccluderEx) == 144, "rOccluderEx: DWARF's byte_size is 144");
static_assert(sizeof(::rOcdElectricParam) == 128, "rOcdElectricParam: DWARF's byte_size is 128");
static_assert(sizeof(::rOcdImmuneParamRes) == 128, "rOcdImmuneParamRes: DWARF's byte_size is 128");
static_assert(sizeof(::rOcdIrAdj) == 128, "rOcdIrAdj: DWARF's byte_size is 128");
static_assert(sizeof(::rOcdIrAdjPL) == 128, "rOcdIrAdjPL: DWARF's byte_size is 128");
static_assert(sizeof(::rOcdPriorityParam) == 128, "rOcdPriorityParam: DWARF's byte_size is 128");
static_assert(sizeof(::rOcdStatusParamRes) == 128, "rOcdStatusParamRes: DWARF's byte_size is 128");
static_assert(sizeof(::rOmKey) == 176, "rOmKey: DWARF's byte_size is 176");
static_assert(sizeof(::rOmParam) == 176, "rOmParam: DWARF's byte_size is 176");
static_assert(sizeof(::rOutlineParamList) == 144, "rOutlineParamList: DWARF's byte_size is 144");
static_assert(sizeof(::rParentRegionStatusParam) == 128, "rParentRegionStatusParam: DWARF's byte_size is 128");
static_assert(sizeof(::rPartnerPawnTalk) == 128, "rPartnerPawnTalk: DWARF's byte_size is 128");
static_assert(sizeof(::rPartnerReactParam) == 128, "rPartnerReactParam: DWARF's byte_size is 128");
static_assert(sizeof(::rPartsCtrlTable) == 128, "rPartsCtrlTable: DWARF's byte_size is 128");
static_assert(sizeof(::rPawnAIAction) == 128, "rPawnAIAction: DWARF's byte_size is 128");
static_assert(sizeof(::rPawnQuestTalk) == 144, "rPawnQuestTalk: DWARF's byte_size is 144");
static_assert(sizeof(::rPlPartsInfo) == 120, "rPlPartsInfo: DWARF's byte_size is 120");
static_assert(sizeof(::rPlantTree) == 128, "rPlantTree: DWARF's byte_size is 128");
static_assert(sizeof(::rPriorityThink) == 128, "rPriorityThink: DWARF's byte_size is 128");
static_assert(sizeof(::rPrologueHmStatus) == 128, "rPrologueHmStatus: DWARF's byte_size is 128");
static_assert(sizeof(::rPushRate) == 128, "rPushRate: DWARF's byte_size is 128");
static_assert(sizeof(::rQuestHistoryData) == 128, "rQuestHistoryData: DWARF's byte_size is 128");
static_assert(sizeof(::rQuestList) == 152, "rQuestList: DWARF's byte_size is 152");
static_assert(sizeof(::rQuestMarkerInfo) == 152, "rQuestMarkerInfo: DWARF's byte_size is 152");
static_assert(sizeof(::rQuestSequenceList) == 128, "rQuestSequenceList: DWARF's byte_size is 128");
static_assert(sizeof(::rQuestTextData) == 144, "rQuestTextData: DWARF's byte_size is 144");
static_assert(sizeof(::rRageTable) == 128, "rRageTable: DWARF's byte_size is 128");
static_assert(sizeof(::rReaction) == 128, "rReaction: DWARF's byte_size is 128");
static_assert(sizeof(::rRenderTargetTexture) == 264, "rRenderTargetTexture: DWARF's byte_size is 264");
static_assert(sizeof(::rReplaceWardGmdList) == 128, "rReplaceWardGmdList: DWARF's byte_size is 128");
static_assert(sizeof(::rRigidBody) == 176, "rRigidBody: DWARF's byte_size is 176");
static_assert(sizeof(::rRoomWearParam) == 128, "rRoomWearParam: DWARF's byte_size is 128");
static_assert(sizeof(::rScenario) == 144, "rScenario: DWARF's byte_size is 144");
static_assert(sizeof(::rScheduler) == 120, "rScheduler: DWARF's byte_size is 120");
static_assert(sizeof(::rShakeCtrl) == 136, "rShakeCtrl: DWARF's byte_size is 136");
static_assert(sizeof(::rShlLimit) == 128, "rShlLimit: DWARF's byte_size is 128");
static_assert(sizeof(::rShlParamList) == 160, "rShlParamList: DWARF's byte_size is 160");
static_assert(sizeof(::rShopGoods) == 176, "rShopGoods: DWARF's byte_size is 176");
static_assert(sizeof(::rShotReqInfo) == 128, "rShotReqInfo: DWARF's byte_size is 128");
static_assert(sizeof(::rShotReqInfo2) == 128, "rShotReqInfo2: DWARF's byte_size is 128");
static_assert(sizeof(::rShrinkBlowValue) == 128, "rShrinkBlowValue: DWARF's byte_size is 128");
static_assert(sizeof(::rSituationMsgCtrl) == 144, "rSituationMsgCtrl: DWARF's byte_size is 144");
static_assert(sizeof(::rSky) == 384, "rSky: DWARF's byte_size is 384");
static_assert(sizeof(::rSndPitchLimit) == 128, "rSndPitchLimit: DWARF's byte_size is 128");
static_assert(sizeof(::rSoundAreaInfo) == 528, "rSoundAreaInfo: DWARF's byte_size is 528");
static_assert(sizeof(::rSoundAttributeSe) == 128, "rSoundAttributeSe: DWARF's byte_size is 128");
static_assert(sizeof(::rSoundBank) == 160, "rSoundBank: DWARF's byte_size is 160");
static_assert(sizeof(::rSoundBossBgm) == 128, "rSoundBossBgm: DWARF's byte_size is 128");
static_assert(sizeof(::rSoundCurveSet) == 160, "rSoundCurveSet: DWARF's byte_size is 160");
static_assert(sizeof(::rSoundDirectionalSet) == 160, "rSoundDirectionalSet: DWARF's byte_size is 160");
static_assert(sizeof(::rSoundEQ) == 176, "rSoundEQ: DWARF's byte_size is 176");
static_assert(sizeof(::rSoundHitInfo) == 128, "rSoundHitInfo: DWARF's byte_size is 128");
static_assert(sizeof(::rSoundMotionSe) == 168, "rSoundMotionSe: DWARF's byte_size is 168");
static_assert(sizeof(::rSoundOptData) == 128, "rSoundOptData: DWARF's byte_size is 128");
static_assert(sizeof(::rSoundParamOfs) == 128, "rSoundParamOfs: DWARF's byte_size is 128");
static_assert(sizeof(::rSoundRequest) == 232, "rSoundRequest: DWARF's byte_size is 232");
static_assert(sizeof(::rSoundReverb) == 176, "rSoundReverb: DWARF's byte_size is 176");
static_assert(sizeof(::rSoundSequenceSe) == 168, "rSoundSequenceSe: DWARF's byte_size is 168");
static_assert(sizeof(::rSoundStreamRequest) == 264, "rSoundStreamRequest: DWARF's byte_size is 264");
static_assert(sizeof(::rSoundSubMixer) == 488, "rSoundSubMixer: DWARF's byte_size is 488");
static_assert(sizeof(::rSoundSubMixerSet) == 144, "rSoundSubMixerSet: DWARF's byte_size is 144");
static_assert(sizeof(::rStageAdjoinList) == 184, "rStageAdjoinList: DWARF's byte_size is 184");
static_assert(sizeof(::rStageConnect) == 144, "rStageConnect: DWARF's byte_size is 144");
static_assert(sizeof(::rStageCustom) == 136, "rStageCustom: DWARF's byte_size is 136");
static_assert(sizeof(::rStageCustomParts) == 160, "rStageCustomParts: DWARF's byte_size is 160");
static_assert(sizeof(::rStageCustomPartsEx) == 224, "rStageCustomPartsEx: DWARF's byte_size is 224");
static_assert(sizeof(::rStageInfo) == 528, "rStageInfo: DWARF's byte_size is 528");
static_assert(sizeof(::rStageJoint) == 1064, "rStageJoint: DWARF's byte_size is 1064");
static_assert(sizeof(::rStageList) == 128, "rStageList: DWARF's byte_size is 128");
static_assert(sizeof(::rStageMap) == 128, "rStageMap: DWARF's byte_size is 128");
static_assert(sizeof(::rStageToSpot) == 128, "rStageToSpot: DWARF's byte_size is 128");
static_assert(sizeof(::rStaminaDecTbl) == 144, "rStaminaDecTbl: DWARF's byte_size is 144");
static_assert(sizeof(::rStarCatalog) == 128, "rStarCatalog: DWARF's byte_size is 128");
static_assert(sizeof(::rStartPos) == 144, "rStartPos: DWARF's byte_size is 144");
static_assert(sizeof(::rStartPosArea) == 128, "rStartPosArea: DWARF's byte_size is 128");
static_assert(sizeof(::rStatusCheck) == 128, "rStatusCheck: DWARF's byte_size is 128");
static_assert(sizeof(::rStatusGainTable) == 128, "rStatusGainTable: DWARF's byte_size is 128");
static_assert(sizeof(::rSwingModel) == 144, "rSwingModel: DWARF's byte_size is 144");
static_assert(sizeof(::rTargetCursorOffset) == 128, "rTargetCursorOffset: DWARF's byte_size is 128");
static_assert(sizeof(::rTbl2ChatMacro) == 128, "rTbl2ChatMacro: DWARF's byte_size is 128");
static_assert(sizeof(::rTblMenuComm) == 152, "rTblMenuComm: DWARF's byte_size is 152");
static_assert(sizeof(::rTblMenuOption) == 144, "rTblMenuOption: DWARF's byte_size is 144");
static_assert(sizeof(::rTexDetailEdit) == 144, "rTexDetailEdit: DWARF's byte_size is 144");
static_assert(sizeof(::rTexture) == 264, "rTexture: DWARF's byte_size is 264");
static_assert(sizeof(::rTutorialDialogMessage) == 152, "rTutorialDialogMessage: DWARF's byte_size is 152");
static_assert(sizeof(::rTutorialList) == 144, "rTutorialList: DWARF's byte_size is 144");
static_assert(sizeof(::rTutorialQuestGroup) == 144, "rTutorialQuestGroup: DWARF's byte_size is 144");
static_assert(sizeof(::rVfxLightInfluence) == 128, "rVfxLightInfluence: DWARF's byte_size is 128");
static_assert(sizeof(::rVibration) == 136, "rVibration: DWARF's byte_size is 136");
static_assert(sizeof(::rWarpLocation) == 128, "rWarpLocation: DWARF's byte_size is 128");
static_assert(sizeof(::rWaypoint) == 176, "rWaypoint: DWARF's byte_size is 176");
static_assert(sizeof(::rWaypoint2) == 208, "rWaypoint2: DWARF's byte_size is 208");
static_assert(sizeof(::rWeaponOffset) == 128, "rWeaponOffset: DWARF's byte_size is 128");
static_assert(sizeof(::rWeaponResTable) == 128, "rWeaponResTable: DWARF's byte_size is 128");
static_assert(sizeof(::rWeatherEffectParam) == 336, "rWeatherEffectParam: DWARF's byte_size is 336");
static_assert(sizeof(::rWeatherFogInfo) == 128, "rWeatherFogInfo: DWARF's byte_size is 128");
static_assert(sizeof(::rWeatherInfoTbl) == 128, "rWeatherInfoTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rWeatherParamEfcInfo) == 128, "rWeatherParamEfcInfo: DWARF's byte_size is 128");
static_assert(sizeof(::rWeatherParamInfoTbl) == 128, "rWeatherParamInfoTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rWeatherStageInfo) == 224, "rWeatherStageInfo: DWARF's byte_size is 224");
static_assert(sizeof(::rWepCateResTbl) == 128, "rWepCateResTbl: DWARF's byte_size is 128");
static_assert(sizeof(::rZone) == 256, "rZone: DWARF's byte_size is 256");
static_assert(sizeof(::nIMEPS4::CandidateDispInfo) == 1136, "nIMEPS4::CandidateDispInfo: DWARF's byte_size is 1136");
static_assert(sizeof(::nInputText::CandidateList) == 1136, "nInputText::CandidateList: DWARF's byte_size is 1136");
static_assert(sizeof(::nInputText::ConvertInfo) == 10312, "nInputText::ConvertInfo: DWARF's byte_size is 10312");
static_assert(sizeof(::nInputText::cUnicodeString) == 10248, "nInputText::cUnicodeString: DWARF's byte_size is 10248");
static_assert(sizeof(::sKeyboardInterface) == 18744, "sKeyboardInterface: DWARF's byte_size is 18744");
static_assert(sizeof(::uGUIInputText) == 39344, "uGUIInputText: DWARF's byte_size is 39344");
static_assert(sizeof(::uGUIPopCnvWnd) == 27136, "uGUIPopCnvWnd: DWARF's byte_size is 27136");

int main() { return 0; }
