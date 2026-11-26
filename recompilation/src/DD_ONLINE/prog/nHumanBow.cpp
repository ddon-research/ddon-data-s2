// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nHumanBow.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOGame.h"
#include "../../generated/shared/nDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nHumanBow::cShootCtrlParam::getDTI() const {
    return nHumanBow::cShootCtrlParam::DTI;
}

inline void* nHumanBow::cShootCtrlParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nHumanBow::cShootCtrlParam::DTI)->memAlloc(sz, align, ::nHumanBow::cShootCtrlParam::DTI.getID());
}

inline void nHumanBow::cShootCtrlParam::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nHumanBow::cShootCtrlParam::DTI)->memFree(p_addr);
}

void nHumanBow::cShootCtrlParam::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "waitFrame", &waitFrame, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "chargeLv", &chargeLv, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "shlGroup", &shlGroup, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "shlNo", &shlNo, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "just", &just, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isFinish", &isFinish, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "degX", &degX, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "degY", &degY, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "degRndX", &degRndX, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "degRndY", &degRndY, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "shlWait", &shlWait, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "recoilPowX", &recoilPowX, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "recoilPowY", &recoilPowY, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "recoilPowRndX", &recoilPowRndX, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "recoilPowRndY", &recoilPowRndY, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "recoilFrameX", &recoilFrameX, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "recoilFrameY", &recoilFrameY, 0u, 0u);
}

inline nHumanBow::cShootCtrlParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nHumanBow::cShootCtrlParam::MyDTI nHumanBow::cShootCtrlParam::DTI("cShootCtrlParam", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* nHumanBow::cShootCtrlParam::MyDTI::newInstance() const {
    return new (16u) ::nHumanBow::cShootCtrlParam;
}

const MtDTI& nHumanBow::cBowActParam::getDTI() const {
    return nHumanBow::cBowActParam::DTI;
}

inline void* nHumanBow::cBowActParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nHumanBow::cBowActParam::DTI)->memAlloc(sz, align, ::nHumanBow::cBowActParam::DTI.getID());
}

inline void nHumanBow::cBowActParam::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nHumanBow::cBowActParam::DTI)->memFree(p_addr);
}

nHumanBow::cBowActParam::cBowActParam() {
    cameraNoCharge = -1;
    cameraShotA = -1;
    cameraShotB = -1;
    cameraNoA = -1;
    cameraNoB = -1;
    shootDirType = SHOOT_DIR_CAMERA;
    shootDelayTime = 0.0f;
    camShotEndFrame = 0.0f;
    shootType = SHOOT_BOW;
    criticalDisNear = 500.0f;
    criticalDisFar = 1500.0f;
    maxChargeLv = 0;
    usableLv = 0;
    customId = 0;
    staminaId = -1;
    staminaWaitId = -1;
    isOcdAdjust = false;
    isStaminaRecoverDisable = false;
    isFastReload = false;
    isFastExplosionReload = false;
    isRestArrowAllUse = false;
    changeSpeed = 1.0f;
    shotWait = -1.0f;
    chargeBgnFrameShot = 15.0f;
    chargeBgnFrameChange = 4.0f;
    checkLength = 3000.0f;
    lockOnType = ::nDDOModel::TYPE_COMMON;
    lockOnNum = 1;
    isClacMatrix = false;
    isArrowNumScale = false;
    lockOnFlag = 0;
    isLockOnContinue = false;
    isSlaveNoCreateShl = false;
    isNetWorkShl = false;
    isJustShot = false;
    fallCircleRadius = 270.0f;
    mgcChargeSpeed = 0.5f;
    mgcBonusRate = 0.07f;
    mgcCharge1 = 30.0f;
    mgcCharge2 = 45.0f;
    mgcChargeNearRate = 0.5f;
    mgcChargeFarRate = 0.1f;
    mgcChargeJustFrame = 10.0f;
    mgcChargeRateHumanEnemy = 1.0f;
    addHealHate = 0.0f;
    mgcNoUseDamageAdjust = false;
    isCoreSearch = false;
    coreSearchRadius = 50;
    coreSearchNodeNo = 0;
    accurateWait = 0.25f;
    accurateWalk = 0.43f;
    accurateRun = 0.61f;
    accurateJump = 0.86f;
    accurateFall = 0.67f;
    asjParamType = ASJ_PARAM_NONE;
    asjOption = 0;
    abilityFlag = 0;
    isShotRetNml = false;
    isShootingJump = true;
    isMovingShot = true;
    isAirShot = true;
    isWalk = true;
    isRun = true;
    isMovingJump = true;
    isVJump = true;
    isChangeMot = false;
    isDispAimSight = true;
    motBgn_Up = 0;
    isUpperRotXFix = false;
    isArrowCamera = false;
    isAITactics = false;
    isCmcPosUse = false;
    isEndStamina0Wait = false;
    isParabolaLine = false;
    isFallCircle = false;
    isNoAir = false;
    motBgn_Low = 1;
    motEnd_Up = 4;
    motEnd_Low = 5;
    motTurnL = 60;
    motTurnR = 61;
    motFall = 68;
    motWait_Low = 7;
    motWait_Up = 6;
    motWaitShot_Up = 2;
    motWaitShot_Low = 3;
    epvIndex = 0;
    epvNoCharge = -1;
    epvNoChargeComp = -1;
    epvNoChargeStart = -1;
    epvIndexSkill = 0;
    epvNoShot = -1;
    epvNoFilter = -1;
    epvNoScope = -1;
    epvNoJustShot = -1;
    cmnCSFilter = CS_FILTER_NONE;
    efOption = 0;
    seType = SE_SKILL;
    seNoShot = -1;
    seNoChargeBgn = -1;
    seNoScopeBgn = -1;
    seNoScopeEnd = -1;
    seNoChargeEnd = -1;
    seNoSkillBgn = -1;
    seNoSkillEnd = -1;
    seNoLockOn = -1;
    seOption = 0;
    castType = ::nDDOGame::ELEMENT_TYPE_INIT;
    chargeFrames[0] = 0.0f;
    chargeJustFrames[0] = 0.0f;
    chargeArrowUseNum[0] = -1;
    epvNoChargeShotCs[0] = -1;
    epvNoChargeCompCs[0] = -1;
    seNoChargeCmp[0] = -1;
    chargeFrames[1] = 0.0f;
    chargeJustFrames[1] = 0.0f;
    chargeArrowUseNum[1] = -1;
    epvNoChargeShotCs[1] = -1;
    epvNoChargeCompCs[1] = -1;
    seNoChargeCmp[1] = -1;
    chargeFrames[2] = 0.0f;
    chargeJustFrames[2] = 0.0f;
    chargeArrowUseNum[2] = -1;
    epvNoChargeShotCs[2] = -1;
    epvNoChargeCompCs[2] = -1;
    seNoChargeCmp[2] = -1;
    chargeFrames[3] = 0.0f;
    chargeJustFrames[3] = 0.0f;
    chargeArrowUseNum[3] = -1;
    epvNoChargeShotCs[3] = -1;
    epvNoChargeCompCs[3] = -1;
    seNoChargeCmp[3] = -1;
    chargeFrames[4] = 0.0f;
    chargeJustFrames[4] = 0.0f;
    chargeArrowUseNum[4] = -1;
    epvNoChargeShotCs[4] = -1;
    epvNoChargeCompCs[4] = -1;
    seNoChargeCmp[4] = -1;
    defaultOceArrowUseNum = -1;
    motJumpBgn[0] = 65;
    motJumpNow[0] = 66;
    motJumpEnd[0] = 67;
    motJumpBgn[1] = 62;
    motJumpNow[1] = 63;
    motJumpEnd[1] = 64;
    motWalk_Low[0] = 11;
    motWalk_Low[1] = 15;
    motWalk_Low[2] = 19;
    motWalk_Low[3] = 23;
    motRun_Low[0] = 27;
    motRun_Low[1] = 31;
    motRun_Low[2] = 35;
    motRun_Low[3] = 39;
    motWalk_Up[0] = 10;
    motWalk_Up[1] = 14;
    motWalk_Up[2] = 18;
    motWalk_Up[3] = 18;
    motRun_Up[0] = 26;
    motRun_Up[1] = 30;
    motRun_Up[2] = 34;
    motRun_Up[3] = 34;
    motWalkShot[0] = 12;
    motWalkShot[1] = 16;
    motWalkShot[2] = 20;
    motWalkShot[3] = 20;
    motRunShot[0] = 12;
    motRunShot[1] = 16;
    motRunShot[2] = 20;
    motRunShot[3] = 20;
    motFinishShot_Up = 0;
    motFinishShot_Low = 0;
    motRunShotL = 0;
    motChange_UpWait = 74;
    motChange_Up[0] = 76;
    motChange_Up[1] = 77;
    motChange_Up[2] = 78;
    motChange_Up[3] = 78;
    motChange_Low = 75;
    shootCtrlList.mAutoDelete = true;
}

nHumanBow::cBowActParam::~cBowActParam() {
    if (shootCtrlList.mLength != 0) {
        u32 v0_0 = shootCtrlList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (shootCtrlList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete shootCtrlList.mpArray[i0_3];
                v1_0 = shootCtrlList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (shootCtrlList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(shootCtrlList.mpArray));
    }
    shootCtrlList.mpArray = nullptr;
    shootCtrlList.mBufsiz = 0;
    shootCtrlList.mLength = 0;
}

void nHumanBow::cBowActParam::createProperty(MtPropertyList& s) {
    createPropertyCmn(s);
    createPropertyAct(s);
    createPropertyMotion(s);
    createPropertyEffect(s);
}

void nHumanBow::cBowActParam::createPropertyCmn(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "cameraNoA", &cameraNoA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "cameraNoB", &cameraNoB, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "cameraShotA", &cameraShotA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "cameraShotB", &cameraShotB, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "cameraNoCharge", &cameraNoCharge, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "camShotEndFrame", &camShotEndFrame, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "shootType", reinterpret_cast<s32*>(&shootType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "shootDirType", reinterpret_cast<s32*>(&shootDirType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "shootDelayTime", &shootDelayTime, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "criticalDisNear", &criticalDisNear, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "criticalDisFar", &criticalDisFar, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "chargeFrames", &chargeFrames[0], 32u, 5u);
    s << ::MtProperty(static_cast<MtObject*>(this), "chargeJustFrames", &chargeJustFrames[0], 32u, 5u);
    s << ::MtProperty(static_cast<MtObject*>(this), "chargeArrowUseNum", &chargeArrowUseNum[0], 32u, 5u);
    s << ::MtProperty(static_cast<MtObject*>(this), "defaultOceArrowUseNum", &defaultOceArrowUseNum, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "maxChargeLv", &maxChargeLv, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "usableLv", &usableLv, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "customId", &customId, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "staminaId", &staminaId, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "staminaWaitId", &staminaWaitId, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isStaminaRecoverDisable", &isStaminaRecoverDisable, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isFastReload", &isFastReload, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isFastExplosionReload", &isFastExplosionReload, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isRestArrowAllUse", &isRestArrowAllUse, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isOcdAdjust", &isOcdAdjust, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "changeSpeed", &changeSpeed, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "shotWait", &shotWait, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "chargeBgnFrameShot", &chargeBgnFrameShot, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "chargeBgnFrameChange", &chargeBgnFrameChange, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "checkLength", &checkLength, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "lockOnType", reinterpret_cast<s32*>(&lockOnType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "lockOnNum", &lockOnNum, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "lockOnFlag", &lockOnFlag, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isLockOnContinue", &isLockOnContinue, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isSlaveNoCreateShl", &isSlaveNoCreateShl, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "castType", reinterpret_cast<s32*>(&castType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "shootCtrlList", static_cast<MtObject*>(&shootCtrlList), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "accurateWait", &accurateWait, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "accurateWalk", &accurateWalk, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "accurateRun", &accurateRun, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "accurateJump", &accurateJump, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "accurateFall", &accurateFall, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "asjParamType", reinterpret_cast<s32*>(&asjParamType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "asjOption", &asjOption, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "abilityFlag", &abilityFlag, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isArrowNumScale", &isArrowNumScale, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "fallCircleRadius", &fallCircleRadius, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcChargeSpeed", &mgcChargeSpeed, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcBonusRate", &mgcBonusRate, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcCharge1", &mgcCharge1, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcCharge2", &mgcCharge2, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcChargeNearRate", &mgcChargeNearRate, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcChargeFarRate", &mgcChargeFarRate, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcChargeJustFrame", &mgcChargeJustFrame, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcChargeRateHumanEnemy", &mgcChargeRateHumanEnemy, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "addHealHate", &addHealHate, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mgcNoUseDamageAdjust", &mgcNoUseDamageAdjust, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isCoreSearch", &isCoreSearch, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "coreSearchRadius", &coreSearchRadius, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "coreSearchNodeNo", &coreSearchNodeNo, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isJustShot", &isJustShot, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isNetWorkShl", &isNetWorkShl, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isClacMatrix", &isClacMatrix, 0u, 0u);
}

void nHumanBow::cBowActParam::createPropertyAct(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "isShotRetNml", &isShotRetNml, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isWalk", &isWalk, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isRun", &isRun, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isMovingJump", &isMovingJump, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isVJump", &isVJump, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isMovingShot", &isMovingShot, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isAirShot", &isAirShot, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isShootingJump", &isShootingJump, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isChangeMot", &isChangeMot, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isDispAimSight", &isDispAimSight, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isUpperRotXFix", &isUpperRotXFix, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isArrowCamera", &isArrowCamera, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isAITactics", &isAITactics, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isCmcPosUse", &isCmcPosUse, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isEndStamina0Wait", &isEndStamina0Wait, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isParabolaLine", &isParabolaLine, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isFallCircle", &isFallCircle, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "isNoAir", &isNoAir, 0u, 0u);
}

void nHumanBow::cBowActParam::createPropertyMotion(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "motBgn_Up", &motBgn_Up, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motBgn_Low", &motBgn_Low, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motEnd_Up", &motEnd_Up, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motEnd_Low", &motEnd_Low, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motTurnL", &motTurnL, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motTurnR", &motTurnR, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motJumpBgn", &motJumpBgn[0], 32u, 2u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motJumpNow", &motJumpNow[0], 32u, 2u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motJumpEnd", &motJumpEnd[0], 32u, 2u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motFall", &motFall, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motWait_Low", &motWait_Low, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motWait_Up", &motWait_Up, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motWaitShot_Up", &motWaitShot_Up, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motWaitShot_Low", &motWaitShot_Low, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motFinishShot_Up", &motFinishShot_Up, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motFinishShot_Low", &motFinishShot_Low, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motWalk_Low", &motWalk_Low[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motRun_Low", &motRun_Low[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motWalk_Up", &motWalk_Up[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motRun_Up", &motRun_Up[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motWalkShot", &motWalkShot[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motRunShot", &motRunShot[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motChange_UpWait", &motChange_UpWait, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motChange_Up", &motChange_Up[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "motChange_Low", &motChange_Low, 0u, 0u);
}

void nHumanBow::cBowActParam::createPropertyEffect(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "epvIndex", &epvIndex, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoCharge", &epvNoCharge, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoChargeComp", &epvNoChargeComp, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoChargeStart", &epvNoChargeStart, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvIndexSkill", &epvIndexSkill, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoShot", &epvNoShot, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoChargeShotCs", &epvNoChargeShotCs[0], 32u, 5u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoChargeCompCs", &epvNoChargeCompCs[0], 32u, 5u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoFilter", &epvNoFilter, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoScope", &epvNoScope, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "epvNoJustShot", &epvNoJustShot, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "cmnCSFilter", reinterpret_cast<s32*>(&cmnCSFilter), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "efOption", &efOption, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seType", reinterpret_cast<s32*>(&seType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoShot", &seNoShot, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoChargeBgn", &seNoChargeBgn, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoChargeCmp", &seNoChargeCmp[0], 32u, 5u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoChargeEnd", &seNoChargeEnd, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoSkillBgn", &seNoSkillBgn, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoSkillEnd", &seNoSkillEnd, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoLockOn", &seNoLockOn, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoScopeBgn", &seNoScopeBgn, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seNoScopeEnd", &seNoScopeEnd, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "seOption", &seOption, 0u, 0u);
}

inline nHumanBow::cBowActParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nHumanBow::cBowActParam::MyDTI nHumanBow::cBowActParam::DTI("cBowActParam", &::MtObject::DTI, 424ul, 0u, 0u);

MtObject* nHumanBow::cBowActParam::MyDTI::newInstance() const {
    return new (16u) ::nHumanBow::cBowActParam;
}

