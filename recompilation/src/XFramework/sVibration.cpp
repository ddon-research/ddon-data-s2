// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sVibration.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cSystem.h"
#include "rVibration.h"
#include "sCamera.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sVibration::getDTI() const {
    return sVibration::DTI;
}

inline void sVibration::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(sVibration::DTI)->memFree(p_addr);
}

sVibration::sVibration() {
    DDON_STUB("sVibration::sVibration")
    /* stub */
}

__attribute__((noinline)) sVibration::~sVibration() {
    DDON_STUB("sVibration::~sVibration")
    /* stub */
}

__attribute__((weak)) void sVibration::reset() {
    DDON_STUB("sVibration::reset")
    /* stub */
}

__attribute__((weak)) void sVibration::move() {
    DDON_STUB("sVibration::move")
    /* stub */
}

void sVibration::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPadVibrationEnable", &mPadVibrationEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraVibrationEnable", &mCameraVibrationEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpVibration", "resource", reinterpret_cast<MT_MFUNC>(&::sVibration::getVibration), reinterpret_cast<MT_MFUNC>(&::sVibration::setVibration), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mVibrationId", &mVibrationId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mPadVibrationNum", reinterpret_cast<MT_MFUNC>(&::sVibration::getPadVibrationNum), reinterpret_cast<MT_MFUNC>(&::sVibration::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mCameraVibrationNum", reinterpret_cast<MT_MFUNC>(&::sVibration::getCameraVibrationNum), reinterpret_cast<MT_MFUNC>(&::sVibration::setDummyU32), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDeltaTime", &mDeltaTime, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDeltaTimeScale", &mDeltaTimeScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mPadViewportNo", reinterpret_cast<MT_MFUNC>(&::sVibration::getPadViewportNo), reinterpret_cast<MT_MFUNC>(&::sVibration::setPadViewportNo), 160u, reinterpret_cast<MT_MFUNC>(&::sVibration::getPadNum), reinterpret_cast<MT_MFUNC>(&::sVibration::setDummyU32));
    s << MtProperty(static_cast<MtObject*>(this), "mVibReqType", &mVibReqType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVibListNo", &mVibListNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVibPriority", &mVibPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVibPad", &mVibPad, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVibCamera", &mVibCamera, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVibPos", &mVibPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpVibUnit", reinterpret_cast<MtObject* *>(&mpVibUnit), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVibUnitParentNo", &mVibUnitParentNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVibFinishTime", &mVibFinishTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Request", static_cast<MT_MFUNC>(&::sVibration::doRequest), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Stop", static_cast<MT_MFUNC>(&::sVibration::stopVibAll), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Finish", static_cast<MT_MFUNC>(&::sVibration::doFinish), 10u);
}

MtUI* sVibration::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

static auto ddon_emit_0x01ba9540 __attribute__((used)) = &sVibration::getVibration;

__attribute__((weak)) void sVibration::setVibration(rVibration* pVibration) {
    DDON_STUB("sVibration::setVibration")
    /* stub */
}

u32 sVibration::getPadVibrationNum() const {
    return static_cast<unsigned int>(((((((static_cast<unsigned long>((*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 158)) & 1) + static_cast<unsigned long>((*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 350)) & 1)) + static_cast<unsigned long>((*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 542)) & 1)) + static_cast<unsigned long>((*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 734)) & 1)) + static_cast<unsigned long>((*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 926)) & 1)) + static_cast<unsigned long>((*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 1118)) & 1)) + static_cast<unsigned long>((*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 1310)) & 1)) + static_cast<unsigned long>((*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 1502)) & 1));
}

u32 sVibration::getCameraVibrationNum() const {
    return (((((((((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 156)) >> 17) & 1u) + (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 348)) >> 17) & 1u)) + (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 540)) >> 17) & 1u)) + (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 732)) >> 17) & 1u)) + (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 924)) >> 17) & 1u)) + (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 1116)) >> 17) & 1u)) + (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 1308)) >> 17) & 1u)) + (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 1500)) >> 17) & 1u);
}

__attribute__((weak)) void sVibration::setDummyU32(u32) {
}

__attribute__((weak)) s32 sVibration::reqVib(u32 ListNo, u32 Priority, sVibration::VibFlag Flag, rVibration* pExtVibration) {
    DDON_STUB("sVibration::reqVib")
    return {};
}

__attribute__((weak)) s32 sVibration::reqVib(u32 ListNo, u32 Priority, const MtVector3& VibPos, sVibration::VibFlag Flag, rVibration* pExtVibration) {
    DDON_STUB("sVibration::reqVib")
    return {};
}

__attribute__((weak)) s32 sVibration::reqVib(u32 ListNo, u32 Priority, uCoord* pVibUnit, s32 VibUnitParentNo, sVibration::VibFlag Flag, rVibration* pExtVibration) {
    DDON_STUB("sVibration::reqVib")
    return {};
}

__attribute__((weak)) s32 sVibration::reqVib(u32 ListNo, u32 Priority, const MtVector3& ViewPos, uCoord* pVibUnit, s32 VibUnitParentNo, sVibration::VibFlag Flag, rVibration* pExtVibration) {
    DDON_STUB("sVibration::reqVib")
    return {};
}

__attribute__((weak)) void sVibration::finishVibAll(f32 Time) {
    DDON_STUB("sVibration::finishVibAll")
    /* stub */
}

void sVibration::stopVib(s32 Id) {
    if (Id > -1) {
        for (unsigned int i0_0 = 0; i0_0 <= 7u; i0_0 = i0_0 + 1u) {
            if ((mVibControl[i0_0].mEnableFlag & 255u) != 0) {
                if (mVibControl[i0_0].mVibrationId == static_cast<unsigned int>(Id)) {
                    if (mVibControl[i0_0].mpVibration != nullptr) {
                        mVibControl[i0_0].mpVibration->release();
                        mVibControl[i0_0].mpVibration = nullptr;
                    }
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&mVibControl[i0_0]) + 28) = (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&mVibControl[i0_0]) + 28)) & 0xFF00FFFFu;
                    return;
                }
            }
        }
    }
}

void sVibration::stopVibAll() {
    for (unsigned int i0_3 = 0;;) {
        if ((mVibControl[i0_3].mEnableFlag & 255u) != 0) {
            if (mVibControl[i0_3].mpVibration != nullptr) {
                mVibControl[i0_3].mpVibration->release();
                mVibControl[i0_3].mpVibration = nullptr;
            }
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&mVibControl[i0_3]) + 28) = (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&mVibControl[i0_3]) + 28)) & 0xFF00FFFFu;
        }
        if (i0_3 != 7) {
            i0_3 = i0_3 + 1u;
        } else {
            break;
        }
    }
}

__attribute__((weak)) u32 sVibration::getPadHighVibration(u32 PadNo, u32 VibValue) const {
    DDON_STUB("sVibration::getPadHighVibration")
    return {};
}

__attribute__((weak)) u32 sVibration::getPadLowVibration(u32 PadNo, u32 VibValue) const {
    DDON_STUB("sVibration::getPadLowVibration")
    return {};
}

__attribute__((weak)) MtMatrix sVibration::getCameraVibrationViewMatrix(u32 ViewportNo, uCamera* pCamera) const {
    DDON_STUB("sVibration::getCameraVibrationViewMatrix")
    __builtin_unreachable();
}

static auto ddon_emit_0x01ba9560 __attribute__((used)) = &sVibration::getPadViewportNo;

void sVibration::setPadViewportNo(u32 ViewportNo, u32 No) {
    if (ViewportNo <= 7u) {
        mPadViewportNo[No] = ViewportNo;
    } else {
        if (mPadViewportNo[No] != 0) {
            mPadViewportNo[No] = 0;
        } else {
            mPadViewportNo[No] = 7;
        }
    }
}

static auto ddon_emit_0x01ba9570 __attribute__((used)) = &sVibration::getPadNum;

u32 sVibration::getDefaultVibPad() const {
    return 1;
}

u32 sVibration::getDefaultVibCamera() const {
    return 1;
}

__attribute__((weak)) void sVibration::doRequest() {
    DDON_STUB("sVibration::doRequest")
    /* stub */
}

void sVibration::doFinish() {
    finishVibAll(mVibFinishTime);
}

u64 sVibration::getTimer() const {
    return (sMain::mpInstance)->mTimer;
}

inline sVibration::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sVibration::MyDTI sVibration::DTI("sVibration", &::cSystem::DTI, 2288ul, 0u, 0u);

sVibration* sVibration::mpInstance;

__attribute__((weak)) MtObject* sVibration::MyDTI::newInstance() const {
    DDON_STUB("sVibration::MyDTI::newInstance")
    return nullptr;
}

sVibration::VibControl::~VibControl() {
    if (mpVibration == nullptr) {
        return;
    }
    mpVibration->release();
    mpVibration = nullptr;
}

__attribute__((weak)) void sVibration::VibControl::start(rVibration* pVibration, u32 ListNo, u32 Priority, sVibration::VibFlag Flag, u32 VibrationId) {
    DDON_STUB("sVibration::VibControl::start")
    /* stub */
}

__attribute__((weak)) bool sVibration::VibControl::move(u32 DeltaTime) {
    DDON_STUB("sVibration::VibControl::move")
    return {};
}

__attribute__((weak)) void sVibration::VibControl::movePadVibSingle(f32 Rate) {
    DDON_STUB("sVibration::VibControl::movePadVibSingle")
    /* stub */
}

__attribute__((weak)) void sVibration::VibControl::moveCamVibSingle(f32 Rate) {
    DDON_STUB("sVibration::VibControl::moveCamVibSingle")
    /* stub */
}

__attribute__((weak)) void sVibration::VibControl::updateFadeParam() {
    DDON_STUB("sVibration::VibControl::updateFadeParam")
    /* stub */
}

sVibration::VibFlag::~VibFlag() {
}

sVibration::PadVibration::~PadVibration() {
}

sVibration::CameraVibration::~CameraVibration() {
}

