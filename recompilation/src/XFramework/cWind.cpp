// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cWind.h"
#include "../MT/MtDTI.h"
#include "../MT/MtLogisticMap.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cWind::getDTI() const {
    return cWind::DTI;
}

cWind::cWind() {
    DDON_STUB("cWind::cWind")
    /* stub */
}

cWind::~cWind() {
}

void cWind::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mBaseDir", &mBaseDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "mWindDir", reinterpret_cast<MT_MFUNC>(&::cWind::getWindDir), reinterpret_cast<MT_MFUNC>(&::cWind::setDummyVec), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDirPitchCycle", reinterpret_cast<MT_MFUNC>(&::cWind::getDirPitchCycle), reinterpret_cast<MT_MFUNC>(&::cWind::setDirPitchCycle), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDirPitchCycleAdd", reinterpret_cast<MT_MFUNC>(&::cWind::getDirPitchCycleAdd), reinterpret_cast<MT_MFUNC>(&::cWind::setDirPitchCycleAdd), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDirPitchAmpValue", reinterpret_cast<MT_MFUNC>(&::cWind::getDirPitchAmpValue), reinterpret_cast<MT_MFUNC>(&::cWind::setDirPitchAmpValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDirPitchAmpRate", reinterpret_cast<MT_MFUNC>(&::cWind::getDirPitchAmpRate), reinterpret_cast<MT_MFUNC>(&::cWind::setDirPitchAmpRate), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_RANGEF, "mDirPitchParam", reinterpret_cast<MT_MFUNC>(&::cWind::getDirPitchParam), reinterpret_cast<MT_MFUNC>(&::cWind::setDirPitchParam), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDirYawCycle", reinterpret_cast<MT_MFUNC>(&::cWind::getDirYawCycle), reinterpret_cast<MT_MFUNC>(&::cWind::setDirYawCycle), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDirYawCycleAdd", reinterpret_cast<MT_MFUNC>(&::cWind::getDirYawCycleAdd), reinterpret_cast<MT_MFUNC>(&::cWind::setDirYawCycleAdd), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDirYawAmpValue", reinterpret_cast<MT_MFUNC>(&::cWind::getDirYawAmpValue), reinterpret_cast<MT_MFUNC>(&::cWind::setDirYawAmpValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mDirYawAmpRate", reinterpret_cast<MT_MFUNC>(&::cWind::getDirYawAmpRate), reinterpret_cast<MT_MFUNC>(&::cWind::setDirYawAmpRate), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_RANGEF, "mDirYawParam", reinterpret_cast<MT_MFUNC>(&::cWind::getDirYawParam), reinterpret_cast<MT_MFUNC>(&::cWind::setDirYawParam), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mSpeedCycle", reinterpret_cast<MT_MFUNC>(&::cWind::getSpeedCycle), reinterpret_cast<MT_MFUNC>(&::cWind::setSpeedCycle), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mSpeedCycleAdd", reinterpret_cast<MT_MFUNC>(&::cWind::getSpeedCycleAdd), reinterpret_cast<MT_MFUNC>(&::cWind::setSpeedCycleAdd), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mSpeedAmpValue", reinterpret_cast<MT_MFUNC>(&::cWind::getSpeedAmpValue), reinterpret_cast<MT_MFUNC>(&::cWind::setSpeedAmpValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mSpeedAmpRate", reinterpret_cast<MT_MFUNC>(&::cWind::getSpeedAmpRate), reinterpret_cast<MT_MFUNC>(&::cWind::setSpeedAmpRate), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_RANGEF, "mSpeedParam", reinterpret_cast<MT_MFUNC>(&::cWind::getSpeedParam), reinterpret_cast<MT_MFUNC>(&::cWind::setSpeedParam), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* cWind::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) MtVector3 cWind::move(f32 DeltaTime) {
    DDON_STUB("cWind::move")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 cWind::getWindDir() const {
    DDON_STUB("cWind::getWindDir")
    __builtin_unreachable();
}

__attribute__((weak)) void cWind::setDummyVec(const MtVector3&) {
}

static auto ddon_emit_0x01bc6bf0 __attribute__((used)) = &cWind::getDirPitchCycle;

static auto ddon_emit_0x01bc6c10 __attribute__((used)) = &cWind::getDirPitchCycleAdd;

static auto ddon_emit_0x01bc6c30 __attribute__((used)) = &cWind::getDirPitchAmpValue;

static auto ddon_emit_0x01bc6c70 __attribute__((used)) = &cWind::getDirPitchAmpRate;

MtRangeF cWind::getDirPitchParam() const {
    MtRangeF param;
    const f32 t0 = mDirPitchParamAmp;
    if (0.0f > t0) {
        param.s = mDirPitchParamBase + t0;
        param.r = t0 * -2.0f;
    } else {
        param.s = mDirPitchParamBase - t0;
        param.r = t0 + t0;
    }
    return param;
}

static auto ddon_emit_0x01bc6c00 __attribute__((used)) = &cWind::setDirPitchCycle;

static auto ddon_emit_0x01bc6c20 __attribute__((used)) = &cWind::setDirPitchCycleAdd;

static auto ddon_emit_0x01bc6c40 __attribute__((used)) = &cWind::setDirPitchAmpValue;

static auto ddon_emit_0x01bc6c80 __attribute__((used)) = &cWind::setDirPitchAmpRate;

void cWind::setDirPitchParam(const MtRangeF& Param) {
    const f32 t0 = Param.r;
    mDirPitchParamBase = Param.s + (t0 * 0.5f);
    mDirPitchParamAmp = t0 * 0.5f;
}

static auto ddon_emit_0x01bc6d10 __attribute__((used)) = &cWind::getDirYawCycle;

static auto ddon_emit_0x01bc6d30 __attribute__((used)) = &cWind::getDirYawCycleAdd;

static auto ddon_emit_0x01bc6d50 __attribute__((used)) = &cWind::getDirYawAmpValue;

static auto ddon_emit_0x01bc6d90 __attribute__((used)) = &cWind::getDirYawAmpRate;

MtRangeF cWind::getDirYawParam() const {
    MtRangeF param;
    const f32 t0 = mDirYawParamAmp;
    if (0.0f > t0) {
        param.s = mDirYawParamBase + t0;
        param.r = t0 * -2.0f;
    } else {
        param.s = mDirYawParamBase - t0;
        param.r = t0 + t0;
    }
    return param;
}

static auto ddon_emit_0x01bc6d20 __attribute__((used)) = &cWind::setDirYawCycle;

static auto ddon_emit_0x01bc6d40 __attribute__((used)) = &cWind::setDirYawCycleAdd;

static auto ddon_emit_0x01bc6d60 __attribute__((used)) = &cWind::setDirYawAmpValue;

static auto ddon_emit_0x01bc6da0 __attribute__((used)) = &cWind::setDirYawAmpRate;

void cWind::setDirYawParam(const MtRangeF& Param) {
    const f32 t0 = Param.r;
    mDirYawParamBase = Param.s + (t0 * 0.5f);
    mDirYawParamAmp = t0 * 0.5f;
}

static auto ddon_emit_0x01bc6e30 __attribute__((used)) = &cWind::getSpeedCycle;

static auto ddon_emit_0x01bc6e50 __attribute__((used)) = &cWind::getSpeedCycleAdd;

static auto ddon_emit_0x01bc6e70 __attribute__((used)) = &cWind::getSpeedAmpValue;

static auto ddon_emit_0x01bc6eb0 __attribute__((used)) = &cWind::getSpeedAmpRate;

MtRangeF cWind::getSpeedParam() const {
    MtRangeF param;
    const f32 t0 = mSpeedParamAmp;
    if (0.0f > t0) {
        param.s = mSpeedParamBase + t0;
        param.r = t0 * -2.0f;
    } else {
        param.s = mSpeedParamBase - t0;
        param.r = t0 + t0;
    }
    return param;
}

static auto ddon_emit_0x01bc6e40 __attribute__((used)) = &cWind::setSpeedCycle;

static auto ddon_emit_0x01bc6e60 __attribute__((used)) = &cWind::setSpeedCycleAdd;

static auto ddon_emit_0x01bc6e80 __attribute__((used)) = &cWind::setSpeedAmpValue;

static auto ddon_emit_0x01bc6ec0 __attribute__((used)) = &cWind::setSpeedAmpRate;

void cWind::setSpeedParam(const MtRangeF& Param) {
    const f32 t0 = Param.r;
    mSpeedParamBase = Param.s + (t0 * 0.5f);
    mSpeedParamAmp = t0 * 0.5f;
}

inline cWind::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWind::MyDTI cWind::DTI("cWind", &::MtObject::DTI, 128ul, 0u, 0u);

__attribute__((weak)) MtObject* cWind::MyDTI::newInstance() const {
    DDON_STUB("cWind::MyDTI::newInstance")
    return nullptr;
}

