// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uEffectExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollision.h"
#include "../../MT/MtCollisionDefine.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cEffect.h"
#include "../../XFramework/cParticleGenerator.h"
#include "../../XFramework/cParticleManager.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/cZoneListener.h"
#include "cZoneListenerEffect.h"
#include "cZoneListenerMulti.h"
#include "cpOcdCtrl.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "../../XFramework/rEffectList.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sEnemyManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sWeatherManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/sZone.h"
#include "../../XFramework/uBaseEffect.h"
#include "../../XFramework/uBaseModel.h"
#include "uCameraBase.h"
#include "uCameraGame.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uEffect.h"
#include "../../XFramework/uLight.h"
#include "../../XFramework/uModel.h"
#include "../../XFramework/uSky.h"
#include "uSkyExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uEffectExt::getDTI() const {
    return uEffectExt::DTI;
}

void* uEffectExt::operator new(size_t sz, u32 align) {
    return uEffectExt::getAllocator()->memAlloc(sz, align, uEffectExt::DTI.getID());
}

uEffectExt::uEffectExt() {
    DDON_STUB("uEffectExt::uEffectExt")
    /* stub */
}

__attribute__((noinline)) uEffectExt::~uEffectExt() {
    DDON_STUB("uEffectExt::~uEffectExt")
    /* stub */
}

void uEffectExt::setup() {
    this->cUnit::setup();
    mParentBaseModelFlag = 0;
    if (mpParent != nullptr) {
        const MtDTI& t0 = mpParent->getDTI();
        MT_CTSTR v0_1 = uBaseModel::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                mParentBaseModelFlag = 1;
                break;
            }
        }
    }
    if ((mUnitGroup & 0x100008000000000ul) == 0) {
        sUnit::getInstance()->setUnitGroupBit(static_cast<cUnit*>(this), getUnitGroup() | (sUnitExt::GPT_EFFECT));
    }
    buildCorrectColorFromZone();
    setupLightInf();
    setCameraQuake();
    resetEffectKind();
}

__attribute__((weak)) void uEffectExt::move() {
    DDON_STUB("uEffectExt::move")
    /* stub */
}

void uEffectExt::sync() {
    this->uEffect::sync();
}

__attribute__((weak)) void uEffectExt::moveAfter() {
    DDON_STUB("uEffectExt::moveAfter")
    /* stub */
}

__attribute__((weak)) void uEffectExt::draw(cDraw* pDraw) {
    DDON_STUB("uEffectExt::draw")
    /* stub */
}

void uEffectExt::kill() {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) != 0) {
        return;
    }
    if ((mBeFlag - 1u) <= 1u) {
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) & 0xFFFFFFF8u) | 3u;
    }
}

void uEffectExt::createProperty(MtPropertyList& s) {
    this->uEffect::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpParentActor", reinterpret_cast<MtObject* *>(&mpParentActor), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mHitStopMode", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getHitStopMode), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setHitStopMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mWorkRateMode", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getWorkRateMode), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setWorkRateMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mCustomWorkRateType", &mCustomWorkRateType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDeltaTimeCoefEx", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getDeltaTimeCoefEx), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setDeltaTimeCoefEx), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "CCTransparency", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getCCTransparency), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setCCTransparency), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "CorrectColorRate", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getCorrectColorRate), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setCorrectColorRate), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "CorrectColorAlpha", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getCorrectColorAlpha), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setCorrectColorAlpha), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "CorrectColor", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getCorrectColor), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setCorrectColor), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Follow Sun", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getFollowSunFlag), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setFollowSunFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mFollowSunDist", &mFollowSunDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Follow Moon", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getFollowMoon), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setFollowMoon), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "FineWeatherOff", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getFineWeatherOffFlag), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setFineWeatherOffFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "CloudyWeatherOff", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getCloudyWeatherOffFlag), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setCloudyWeatherOffFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "RainWeatherOff", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getRainWeatherOffFlag), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setRainWeatherOffFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Zone Check Generator", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getZoneCheckGeneratorFlag), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setZoneCheckGeneratorFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Color Update", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getColorUpdateFlag), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setColorUpdateFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Color Update Dist Cancel", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getColorUpdateDistCancelFlag), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setColorUpdateDistCancelFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mColorUpdateTime", &mColorUpdateTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mParentBaseModelFlag", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getParentBaseModelFlag), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setParentBaseModelFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mParentTransparency", reinterpret_cast<MT_MFUNC>(&::uEffectExt::getParentTransparency), reinterpret_cast<MT_MFUNC>(&::uEffectExt::setParentTransparency), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mRDCFC.mDispCtrlFlag", &mRDCFC.mDispCtrlFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRDCFC.mApplicationRate", &mRDCFC.mApplicationRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEpvPos", &mEpvPos, 0u, 0u);
}

MtUI* uEffectExt::createUI(MtProperty& prop) {
    return this->uEffect::createUI(prop);
}

__attribute__((weak)) void uEffectExt::updateDeltaTimeRate() {
    DDON_STUB("uEffectExt::updateDeltaTimeRate")
    /* stub */
}

void uEffectExt::updateParentPtr() {
    if (mpParent != nullptr) {
        if (!mpParent->isEnable()) {
            mpParent = nullptr;
        }
    }
    if (mpParentActor == nullptr) {
        return;
    }
    if (mpParentActor->isEnable()) {
        return;
    }
    mpParentActor = nullptr;
}

static auto ddon_emit_0x01ad6170 __attribute__((used)) = &uEffectExt::setHitStopMode;

static auto ddon_emit_0x01ad6160 __attribute__((used)) = &uEffectExt::getHitStopMode;

static auto ddon_emit_0x01ad6190 __attribute__((used)) = &uEffectExt::setWorkRateMode;

static auto ddon_emit_0x01ad6130 __attribute__((used)) = &uEffectExt::getWorkRateMode;

void uEffectExt::setParentActor(uDDOModel* pParent, bool Flg0, bool Flg1) {
    mpParentActor = pParent;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 652) = static_cast<unsigned int>((static_cast<unsigned long>(static_cast<long>(Flg1) * 2) | static_cast<unsigned long>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 652)) & 0xFFFFFFFCu)) | static_cast<unsigned long>(Flg0));
}

static auto ddon_emit_0x01ad6610 __attribute__((used)) = &uEffectExt::setParentBaseModelFlag;

static auto ddon_emit_0x01ad6600 __attribute__((used)) = &uEffectExt::getParentBaseModelFlag;

static auto ddon_emit_0x01ad6640 __attribute__((used)) = &uEffectExt::setParentTransparency;

static auto ddon_emit_0x01ad6630 __attribute__((used)) = &uEffectExt::getParentTransparency;

__attribute__((weak)) void uEffectExt::setGeneralCorrectColor(const MtColor& color, f32 rate, f32 alpha_rate, u32 mode) {
    DDON_STUB("uEffectExt::setGeneralCorrectColor")
    /* stub */
}

static auto ddon_emit_0x01ad61b0 __attribute__((used)) = &uEffectExt::getDeltaTimeCoefEx;

static auto ddon_emit_0x01ad61c0 __attribute__((used)) = &uEffectExt::setDeltaTimeCoefEx;

static auto ddon_emit_0x01ad61f0 __attribute__((used)) = &uEffectExt::setCCTransparency;

static auto ddon_emit_0x01ad61d0 __attribute__((used)) = &uEffectExt::getCCTransparency;

void uEffectExt::setLanternCancel() {
    mLanternCancel = false;
}

static auto ddon_emit_0x01ad64a0 __attribute__((used)) = &uEffectExt::setFollowSunFlag;

static auto ddon_emit_0x01ad6140 __attribute__((used)) = &uEffectExt::getFollowSunFlag;

static auto ddon_emit_0x01ad64c0 __attribute__((used)) = &uEffectExt::setFollowMoon;

static auto ddon_emit_0x01ad6150 __attribute__((used)) = &uEffectExt::getFollowMoon;

static auto ddon_emit_0x01ad6580 __attribute__((used)) = &uEffectExt::setZoneCheckGeneratorFlag;

static auto ddon_emit_0x01ad6570 __attribute__((used)) = &uEffectExt::getZoneCheckGeneratorFlag;

__attribute__((weak)) void uEffectExt::setZoneUnitColorFlag() {
    DDON_STUB("uEffectExt::setZoneUnitColorFlag")
    /* stub */
}

static auto ddon_emit_0x01ad65b0 __attribute__((used)) = &uEffectExt::setColorUpdateFlag;

static auto ddon_emit_0x01ad65a0 __attribute__((used)) = &uEffectExt::getColorUpdateFlag;

static auto ddon_emit_0x01ad65e0 __attribute__((used)) = &uEffectExt::setColorUpdateDistCancelFlag;

static auto ddon_emit_0x01ad65d0 __attribute__((used)) = &uEffectExt::getColorUpdateDistCancelFlag;

static auto ddon_emit_0x01ad64f0 __attribute__((used)) = &uEffectExt::setFineWeatherOffFlag;

static auto ddon_emit_0x01ad64e0 __attribute__((used)) = &uEffectExt::getFineWeatherOffFlag;

static auto ddon_emit_0x01ad6520 __attribute__((used)) = &uEffectExt::setCloudyWeatherOffFlag;

static auto ddon_emit_0x01ad6510 __attribute__((used)) = &uEffectExt::getCloudyWeatherOffFlag;

static auto ddon_emit_0x01ad6550 __attribute__((used)) = &uEffectExt::setRainWeatherOffFlag;

static auto ddon_emit_0x01ad6540 __attribute__((used)) = &uEffectExt::getRainWeatherOffFlag;

__attribute__((weak)) void uEffectExt::setWeatherOnFlag(const cWeatherFlag& flag) {
    DDON_STUB("uEffectExt::setWeatherOnFlag")
    /* stub */
}

__attribute__((weak)) void uEffectExt::setCameraQuake() {
    DDON_STUB("uEffectExt::setCameraQuake")
    /* stub */
}

__attribute__((weak)) void uEffectExt::buildCorrectColorFromZone() {
    DDON_STUB("uEffectExt::buildCorrectColorFromZone")
    /* stub */
}

__attribute__((weak)) void uEffectExt::updateCorrectColor() {
    DDON_STUB("uEffectExt::updateCorrectColor")
    /* stub */
}

__attribute__((weak)) void uEffectExt::buildWindParamFromZone() {
    DDON_STUB("uEffectExt::buildWindParamFromZone")
    /* stub */
}

__attribute__((weak)) uEffect* uEffectExt::openEffect() {
    DDON_STUB("uEffectExt::openEffect")
    return nullptr;
}

bool uEffectExt::createGenerator() {
    mZoneUpdateFlag = 1;
    return this->uEffect::createGenerator();
}

__attribute__((weak)) void uEffectExt::initParticleCustom(cParticleGenerator* pGenerator, cParticle* pParticle, f32 LifeRate) {
    DDON_STUB("uEffectExt::initParticleCustom")
    /* stub */
}

bool uEffectExt::moveParticleCustom(cParticleGenerator* pGenerator, cParticle* pParticle) {
    return false;
}

__attribute__((weak)) void uEffectExt::correctColorIntensity(cParticleGenerator* pGenerator, MtColor* pColor, u32 ColorNum, u32* pIntensity) {
    DDON_STUB("uEffectExt::correctColorIntensity")
    /* stub */
}

u32 uEffectExt::updateParticlePosForce(u32 ForceType, f32 ForceRate, const MtVector3& ForceVec, MtVector3& Pos) {
    if (ForceType == 1) {
        CORRECT_WIND_PARAM::ZONE_WIND_PARAM* pZoneParam = mCorrectWindParam.mpZoneWindParam;
        if (pZoneParam != nullptr) {
            if ((pZoneParam->mFlag & 1u) != 0) {
                const f32 t0 = ForceVec.y;
                const f32 t1 = ForceVec.z;
                f32 t2 = pZoneParam->mDirection.y;
                f32 t3 = pZoneParam->mDirection.z;
                Pos.x = Pos.x + (ForceRate * (ForceVec.x + pZoneParam->mDirection.x));
                Pos.y = Pos.y + (ForceRate * (t0 + t2));
                Pos.z = Pos.z + (ForceRate * (t1 + t3));
                Pos.pad_ = 0.0f;
                return 0;
            } else {
                const f32 t4 = ForceVec.y;
                const f32 t5 = ForceVec.z;
                Pos.x = Pos.x + (ForceVec.x * ForceRate);
                Pos.y = Pos.y + (t4 * ForceRate);
                Pos.z = Pos.z + (t5 * ForceRate);
                Pos.pad_ = 0.0f;
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

__attribute__((weak)) u32 uEffectExt::checkCollisionLine(sCollision::TriangleInfo* pTriangleInfo, u32* pPtclFlag, const MtLineSegment& LineSegment, rEffectList::EFL_PARAM_COLL* pCollParam) {
    DDON_STUB("uEffectExt::checkCollisionLine")
    return {};
}

__attribute__((weak)) u32 uEffectExt::checkCollsionSphere(sCollision::TriangleInfo* pTriangleInfo, u32* pPtclFlag, MtVector3& Pos, const MtVector3& OldPos, f32 Radius, rEffectList::EFL_PARAM_COLL* pCollParam) {
    DDON_STUB("uEffectExt::checkCollsionSphere")
    return {};
}

u32 uEffectExt::setCollBounceReaction(rEffectList::EFL_PARAM_COLL* pCollParam, sCollision::TriangleInfo* pInfo, u32 Attribute) {
    return 0;
}

u32 uEffectExt::setCollFinishReaction(rEffectList::EFL_PARAM_COLL* pCollParam, sCollision::TriangleInfo* pInfo, u32 Attribute) {
    return 0;
}

__attribute__((weak)) u32 uEffectExt::getCollBounceMaterialFlag(sCollision::TriangleInfo* pTriangleInfo) const {
    DDON_STUB("uEffectExt::getCollBounceMaterialFlag")
    return {};
}

__attribute__((weak)) u32 uEffectExt::getCollFinishMaterialFlag(sCollision::TriangleInfo* pTriangleInfo) const {
    DDON_STUB("uEffectExt::getCollFinishMaterialFlag")
    return {};
}

f32 uEffectExt::correctModelEnvMapPower(cParticleGenerator* pGenerator, const MtVector3& Pos, f32 OrgEnvMapPower) {
    if (mCorrectColorParam.mpZoneParam != nullptr) {
        if ((&mCorrectColorParam.mpZoneParam[pGenerator->mManagerNo]) != nullptr) {
            if ((mCorrectColorParam.mpZoneParam[pGenerator->mManagerNo].mFlag & 1u) != 0) {
                return mCorrectColorParam.mpZoneParam[pGenerator->mManagerNo].mEnvMapPowerScale * OrgEnvMapPower;
            }
        }
    }
    return OrgEnvMapPower;
}

__attribute__((weak)) MtVector4 uEffectExt::correctFilterColor(cParticleGenerator* pGenerator, const MtVector3& Pos, const MtVector4& OrgColor) {
    DDON_STUB("uEffectExt::correctFilterColor")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 uEffectExt::correctLightColor(cParticleGenerator* pGenerator, const MtVector3& Pos, const MtVector3& OrgColor) {
    DDON_STUB("uEffectExt::correctLightColor")
    __builtin_unreachable();
}

__attribute__((weak)) void uEffectExt::requestSoundSe(cParticleManager* pManager) {
    DDON_STUB("uEffectExt::requestSoundSe")
    /* stub */
}

__attribute__((weak)) void uEffectExt::stopSoundSe(cParticleManager* pManager) {
    rSoundRequest* pSoundRequest = pManager->getSoundRequest();
    if (pSoundRequest != nullptr) {
        if ((mStatus & STATUS_SE_STOP) != 0) {
            sSound::getInstance()->stopSe(pSoundRequest, pManager->mSeReqNo, reinterpret_cast<uintptr>(pManager), false);
        } else if (((pManager->mSeOptionFlag & rEffectList::SE_OPTION_FLAG_SYNCHRO_KEY_OFF) != 0) || sSound::getInstance()->getSeIsLoop(pSoundRequest, pManager->mSeReqNo)) {
            static_cast<sSoundExt*>(sSound::getInstance())->keyOffSe(pSoundRequest, pManager->mSeReqNo, reinterpret_cast<uintptr>(pManager), sSoundExt::SE_SEARCH_KEY_ALL);
        }
    }
}

__attribute__((weak)) bool uEffectExt::checkEffectList(u32 ListNo) {
    DDON_STUB("uEffectExt::checkEffectList")
    return {};
}

__attribute__((weak)) void uEffectExt::storeColorParamFromZone(u32 no, const MtVector3& ckPos, u32 correctType) {
    DDON_STUB("uEffectExt::storeColorParamFromZone")
    /* stub */
}

__attribute__((weak)) void uEffectExt::updateCorrectColorParam(u32 no, const MtVector3& ckPos) {
    DDON_STUB("uEffectExt::updateCorrectColorParam")
    /* stub */
}

__attribute__((weak)) void uEffectExt::correctColorIntensitySub(const uEffectExt::stColor16& color, const uEffectExt::stColorAttr& attr, const uEffectExt::stColor16& mixColor, const uEffectExt::stColorAttr& mixAttr, uEffectExt::CORRECT_COLOR_PARAM::ZONE_PARAM* pZoneParam, bool useLantan, MtColor* pColor, u32 colorNum, u32* pIntensity) {
    DDON_STUB("uEffectExt::correctColorIntensitySub")
    /* stub */
}

__attribute__((weak)) f32 uEffectExt::getShadowRate(const MtVector3& ckPos) const {
    DDON_STUB("uEffectExt::getShadowRate")
    return {};
}

__attribute__((weak)) void uEffectExt::setCorrectColor(const MtVector3& color) {
    DDON_STUB("uEffectExt::setCorrectColor")
    /* stub */
}

__attribute__((weak)) MtVector3 uEffectExt::getCorrectColor() const {
    DDON_STUB("uEffectExt::getCorrectColor")
    __builtin_unreachable();
}

__attribute__((weak)) void uEffectExt::setCorrectColorRate(f32 rate) {
    DDON_STUB("uEffectExt::setCorrectColorRate")
    /* stub */
}

f32 uEffectExt::getCorrectColorRate() const {
    return 0.00390625f * static_cast<float>(*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 708));
}

__attribute__((weak)) void uEffectExt::setCorrectColorAlpha(f32 alpha) {
    DDON_STUB("uEffectExt::setCorrectColorAlpha")
    /* stub */
}

f32 uEffectExt::getCorrectColorAlpha() const {
    return 0.00390625f * static_cast<float>(*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 706));
}

__attribute__((weak)) void uEffectExt::setupLightInf() {
    DDON_STUB("uEffectExt::setupLightInf")
    /* stub */
}

__attribute__((weak)) void uEffectExt::resetEffectKind() {
    DDON_STUB("uEffectExt::resetEffectKind")
    /* stub */
}

bool uEffectExt::isEffectSt() {
    return static_cast<bool>(mEffectKind & 1u);
}

void uEffectExt::doFinish() {
    if (mFinishFadeOutFrame > 0.0f) {
        mFinishFadeOutPassage = sMain::getInstance()->mDeltaTime + mFinishFadeOutPassage;
    } else {
        this->uEffect::doFinish();
    }
}

__attribute__((weak)) bool uEffectExt::getWorldOffsetDifference(MtVector3* WorldOffsetDifference) {
    DDON_STUB("uEffectExt::getWorldOffsetDifference")
    return {};
}

inline uEffectExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uEffectExt::MyDTI uEffectExt::DTI("uEffectExt", &::uEffect::DTI, 880ul, 0u, 0u);

__attribute__((weak)) MtObject* uEffectExt::MyDTI::newInstance() const {
    DDON_STUB("uEffectExt::MyDTI::newInstance")
    return nullptr;
}

bool uEffectExt::cRequestDispCtrlFlagCtrl::isProgressDispOff() {
    if ((mDispCtrlFlag & 1u) == 0) {
        if ((mDispCtrlFlag & 2u) != 0) {
            if (mpOwner->mpParent != nullptr) {
                cpOcdCtrl* pOcdCtrl = static_cast<uDDOModel*>(mpOwner->mpParent)->getOcdCtrlPtr();
                if (pOcdCtrl != nullptr) {
                    if (!pOcdCtrl->isOcdActive(4106u)) {
                        if (!pOcdCtrl->isOcdActive(4107u)) {
                            if (!pOcdCtrl->isOcdActive(4109u)) {
                                if (((mDispCtrlFlag & 4u) != 0) && (sEnemyManager::getInstance()->mEnemyDistanceInfo.getNearestDistanceSuperErosion() > static_cast<sEffectExt*>(sEffect::getInstance())->mSuperErosionDispOffDistance)) {
                                    return true;
                                }
                                if ((mDispCtrlFlag & 8u) != 0) {
                                    bool t0 = static_cast<sEffectExt*>(sEffect::getInstance())->isDrawOnceRequestEffectTypeSuperErosionCamData(mpOwner);
                                    return !t0;
                                } else {
                                    return false;
                                }
                            } else {
                                return true;
                            }
                        } else {
                            return true;
                        }
                    } else {
                        return true;
                    }
                } else {
                    if (((mDispCtrlFlag & 4u) != 0) && (sEnemyManager::getInstance()->mEnemyDistanceInfo.getNearestDistanceSuperErosion() > static_cast<sEffectExt*>(sEffect::getInstance())->mSuperErosionDispOffDistance)) {
                        return true;
                    }
                    if ((mDispCtrlFlag & 8u) != 0) {
                        bool t0 = static_cast<sEffectExt*>(sEffect::getInstance())->isDrawOnceRequestEffectTypeSuperErosionCamData(mpOwner);
                        return !t0;
                    } else {
                        return false;
                    }
                }
            } else {
                if (((mDispCtrlFlag & 4u) != 0) && (sEnemyManager::getInstance()->mEnemyDistanceInfo.getNearestDistanceSuperErosion() > static_cast<sEffectExt*>(sEffect::getInstance())->mSuperErosionDispOffDistance)) {
                    return true;
                }
                if ((mDispCtrlFlag & 8u) != 0) {
                    bool t0 = static_cast<sEffectExt*>(sEffect::getInstance())->isDrawOnceRequestEffectTypeSuperErosionCamData(mpOwner);
                    return !t0;
                } else {
                    return false;
                }
            }
        } else {
            if (((mDispCtrlFlag & 4u) != 0) && (sEnemyManager::getInstance()->mEnemyDistanceInfo.getNearestDistanceSuperErosion() > static_cast<sEffectExt*>(sEffect::getInstance())->mSuperErosionDispOffDistance)) {
                return true;
            }
            if ((mDispCtrlFlag & 8u) != 0) {
                bool t0 = static_cast<sEffectExt*>(sEffect::getInstance())->isDrawOnceRequestEffectTypeSuperErosionCamData(mpOwner);
                return !t0;
            } else {
                return false;
            }
        }
    } else {
        return true;
    }
}

