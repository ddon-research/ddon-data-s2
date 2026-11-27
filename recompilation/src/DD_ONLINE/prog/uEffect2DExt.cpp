// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uEffect2DExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cParticle2D.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/cZoneListener.h"
#include "cZoneListenerEffect.h"
#include "cZoneListenerMulti.h"
#include "cpWorkRate.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sWeatherManager.h"
#include "sWorkRate.h"
#include "../../XFramework/sZone.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uEffect2D.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uEffect2DExt::getDTI() const {
    return uEffect2DExt::DTI;
}

void* uEffect2DExt::operator new(size_t sz, u32 align) {
    return uEffect2DExt::getAllocator()->memAlloc(sz, align, uEffect2DExt::DTI.getID());
}

uEffect2DExt::uEffect2DExt() {
    DDON_STUB("uEffect2DExt::uEffect2DExt")
    /* stub */
}

uEffect2DExt::~uEffect2DExt() {
    if (sEffect::getInstance() != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->removeEffect2D(mpHandle, mGroupNo, 2u);
    }
    if (mCorrectColorParam.mpZoneParam != nullptr) {
        delete[] mCorrectColorParam.mpZoneParam;
        mCorrectColorParam.mpZoneParam = nullptr;
    }
    mCorrectColorParam.mZoneParamNum = 0;
}

void uEffect2DExt::setup() {
    this->uEffect2D::setup();
    if ((mUnitGroup & 0x100008000000000ul) == 0) {
        sUnit::getInstance()->setUnitGroupBit(static_cast<cUnit*>(this), getUnitGroup() | (sUnitExt::GPT_EFFECT));
    }
}

void uEffect2DExt::move() {
    if (mpParentActor != nullptr) {
        if (!mpParentActor->isEnable()) {
            mpParentActor = nullptr;
        }
    }
    if ((mStatus & 8u) == 0) {
        f32 t0 = sWorkRate::getInstance()->calcRaw(mCustomWorkRateType);
        if (mpParentActor != nullptr) {
            if (getWorkRateMode()) {
                if (mpParentActor->getWorkRatePtr() != nullptr) {
                    u32 t1 = mpParentActor->getWorkRatePtr()->getTypeBit();
                    f32 t2 = sWorkRate::getInstance()->calcRaw(t1);
                    f32 t3 = mpParentActor->getWorkRatePtr()->getSpeedAll();
                    mDeltaTimeCoef = mDeltaTimeCoefEx * (t2 * t3);
                } else {
                    mDeltaTimeCoef = mDeltaTimeCoefEx * t0;
                }
            } else {
                mDeltaTimeCoef = mDeltaTimeCoefEx * t0;
            }
        } else {
            mDeltaTimeCoef = mDeltaTimeCoefEx * t0;
        }
    }
    this->uEffect2D::move();
}

__attribute__((weak)) void uEffect2DExt::sync() {
}

void uEffect2DExt::moveAfter() {
    if (mZoneUpdateFlag) {
        buildCorrectColorFromZone();
        mZoneUpdateFlag = false;
    } else {
        if (mColorUpdate) {
            if (mCorrectColorParam.mpZoneParam != nullptr) {
                f32 t0 = mColorUpdateTimer;
                if (sWeatherManager::getInstance()->getEffectColorUpdateTime() > t0) {
                    mColorUpdateTimer = sMain::getInstance()->mDeltaTime + mColorUpdateTimer;
                } else {
                    if (static_cast<sEffectExt*>(sEffect::getInstance())->updateColorUpdateCount()) {
                        mColorUpdateTimer = 0.0f;
                        u32 v0_10 = mCorrectColorParam.mZoneParamNum;
                        if (v0_10 != 0) {
                            for (unsigned int i0_3 = 0;;) {
                                updateCorrectColorParam(i0_3);
                                if (v0_10 != (i0_3 + 1u)) {
                                    i0_3 += 1u;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    this->uEffect2D::moveAfter();
}

void uEffect2DExt::draw(cDraw* pDraw) {
    if (!isPossibleDrawFromDrawBuffer()) {
        return;
    }
    this->uEffect2D::draw(pDraw);
}

void uEffect2DExt::createProperty(MtPropertyList& s) {
    this->uEffect2D::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpParentActor", reinterpret_cast<MtObject* *>(&mpParentActor), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHitStopMode", &mHitStopMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWorkRateMode", &mWorkRateMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCustomWorkRateType", &mCustomWorkRateType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDeltaTimeCoefEx", reinterpret_cast<MT_MFUNC>(&::uEffect2DExt::getDeltaTimeCoefEx), reinterpret_cast<MT_MFUNC>(&::uEffect2DExt::setDeltaTimeCoefEx), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Color Update", reinterpret_cast<MT_MFUNC>(&::uEffect2DExt::getColorUpdateFlag), reinterpret_cast<MT_MFUNC>(&::uEffect2DExt::setColorUpdateFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mColorUpdateTimer", &mColorUpdateTimer, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColorUpdateTime", &mColorUpdateTime, 0u, 0u);
}

MtUI* uEffect2DExt::createUI(MtProperty& prop) {
    return this->uEffect2D::createUI(prop);
}

void uEffect2DExt::updateParentPtr() {
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

static auto ddon_emit_0x01ad6030 __attribute__((used)) = &uEffect2DExt::getDeltaTimeCoefEx;

static auto ddon_emit_0x01ad6040 __attribute__((used)) = &uEffect2DExt::setDeltaTimeCoefEx;

static auto ddon_emit_0x01ad6060 __attribute__((used)) = &uEffect2DExt::setColorUpdateFlag;

static auto ddon_emit_0x01ad6050 __attribute__((used)) = &uEffect2DExt::getColorUpdateFlag;

__attribute__((weak)) void uEffect2DExt::buildCorrectColorFromZone() {
    DDON_STUB("uEffect2DExt::buildCorrectColorFromZone")
    /* stub */
}

bool uEffect2DExt::createGenerator() {
    mZoneUpdateFlag = true;
    return this->uEffect2D::createGenerator();
}

__attribute__((weak)) void uEffect2DExt::correctColorIntensity(cParticle2DGenerator* pGenerator, MtColor* pColor, u32 ColorNum, u32* pIntensity, const MtFloat2& Pos) {
    DDON_STUB("uEffect2DExt::correctColorIntensity")
    /* stub */
}

__attribute__((weak)) void uEffect2DExt::storeColorParamFromZone(u32 no, const MtVector3& ckPos, u32 correctType) {
    DDON_STUB("uEffect2DExt::storeColorParamFromZone")
    /* stub */
}

__attribute__((weak)) void uEffect2DExt::updateCorrectColorParam(u32 no) {
    DDON_STUB("uEffect2DExt::updateCorrectColorParam")
    /* stub */
}

inline uEffect2DExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uEffect2DExt::MyDTI uEffect2DExt::DTI("uEffect2DExt", &::uEffect2D::DTI, 560ul, 0u, 0u);

__attribute__((weak)) MtObject* uEffect2DExt::MyDTI::newInstance() const {
    DDON_STUB("uEffect2DExt::MyDTI::newInstance")
    return nullptr;
}

