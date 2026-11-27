// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cStageEpvCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cEfcHandle.h"
#include "rEffectProvider.h"
#include "res_ptr.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sWeatherManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cStageEpvCtrl::getDTI() const {
    return cStageEpvCtrl::DTI;
}

cStageEpvCtrl::cStageEpvCtrl() {
    DDON_STUB("cStageEpvCtrl::cStageEpvCtrl")
    /* stub */
}

cStageEpvCtrl::~cStageEpvCtrl() {
    DDON_STUB("cStageEpvCtrl::~cStageEpvCtrl")
    /* stub */
}

__attribute__((weak)) void cStageEpvCtrl::move() {
    DDON_STUB("cStageEpvCtrl::move")
    /* stub */
}

__attribute__((weak)) void cStageEpvCtrl::updatePtr() {
    DDON_STUB("cStageEpvCtrl::updatePtr")
    /* stub */
}

void cStageEpvCtrl::deleteEffect() {
    u32 i = 0;
    u32 v1_0;
    unsigned int i1_9;
    u32 v2_0;
    for (;;) {
        static_cast<sEffectExt*>(sEffect::mpInstance)->endEffect(&mStageEfcHandle[i], 2u);
        if (mStageEfcHandle[i].mLength != 0) {
            v1_0 = mStageEfcHandle[i].mLength;
            i1_9 = 0;
            for (;;) {
                if (mStageEfcHandle[i].mpArray[i1_9] == nullptr) {
                    v2_0 = v1_0;
                } else {
                    delete mStageEfcHandle[i].mpArray[i1_9];
                    v2_0 = mStageEfcHandle[i].mLength;
                }
                if ((i1_9 + 1u) < v2_0) {
                    v1_0 = v2_0;
                    i1_9 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mStageEfcHandle[i].mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mStageEfcHandle[i].mpArray));
        }
        mStageEfcHandle[i].mpArray = nullptr;
        mStageEfcHandle[i].mBufsiz = 0;
        mStageEfcHandle[i].mLength = 0;
        if ((i + 1u) != 4) {
            i = i + 1u;
        } else {
            break;
        }
    }
}

__attribute__((weak)) void cStageEpvCtrl::releaseEpvCtrl() {
    DDON_STUB("cStageEpvCtrl::releaseEpvCtrl")
    /* stub */
}

__attribute__((weak)) void cStageEpvCtrl::setEffectProvider(rEffectProvider* pRes) {
    DDON_STUB("cStageEpvCtrl::setEffectProvider")
    /* stub */
}

void cStageEpvCtrl::setEffectProviderIndex(s32 always, s32 day, s32 night) {
    mIndexAlways = always;
    mIndexDay = day;
    mIndexNight = night;
}

void cStageEpvCtrl::setOfsPos(const MtVector3& pos) {
    mOfsPos = pos;
}

inline cStageEpvCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStageEpvCtrl::MyDTI cStageEpvCtrl::DTI("cStageEpvCtrl", &::MtObject::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* cStageEpvCtrl::MyDTI::newInstance() const {
    DDON_STUB("cStageEpvCtrl::MyDTI::newInstance")
    return nullptr;
}

