// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uEfCam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cParticle.h"
#include "../../XFramework/cParticleGenerator.h"
#include "../../XFramework/cParticleManager.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/rEffectList.h"
#include "../../XFramework/sCamera.h"
#include "../../XFramework/uCamera.h"
#include "../../XFramework/uEffect.h"
#include "uEffectExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uEfCam::getDTI() const {
    return uEfCam::DTI;
}

void* uEfCam::operator new(size_t sz, u32 align) {
    return uEfCam::getAllocator()->memAlloc(sz, align, uEfCam::DTI.getID());
}

uEfCam::uEfCam() {
    mRepeatFlag = false;
    mYAngleFlag = false;
    setConstUpdateMode(true);
    mOfs.z = 0.0f;
    mOfs.pad_ = 0.0f;
    mOfs.x = 0.0f;
    mOfs.y = 0.0f;
    mCamOfs.z = 0.0f;
    mCamOfs.pad_ = 0.0f;
    mCamOfs.x = 0.0f;
    mCamOfs.y = 0.0f;
}

uEfCam::~uEfCam() {
}

void uEfCam::move() {
    this->uEffectExt::move();
    if (!mRepeatFlag) {
        return;
    }
    if ((mStatus & 0x80000u) == 0) {
        repeatParticlePos();
    }
}

void uEfCam::sync() {
    this->uEffectExt::sync();
}

void uEfCam::draw(cDraw* pDraw) {
    if (!isPossibleDrawFromDrawBuffer()) {
        return;
    }
    this->uEffect::draw(pDraw);
}

void uEfCam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mRepeatFlag", &mRepeatFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mYAngleFlag", &mYAngleFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamOfs", &mCamOfs, 0u, 0u);
    this->uEffectExt::createProperty(s);
}

MtUI* uEfCam::createUI(MtProperty& prop) {
    return this->uEffectExt::createUI(prop);
}

__attribute__((weak)) void uEfCam::updateWorldMatrix() {
    DDON_STUB("uEfCam::updateWorldMatrix")
    /* stub */
}

__attribute__((weak)) uEffect* uEfCam::openEffect() {
    DDON_STUB("uEfCam::openEffect")
    return nullptr;
}

__attribute__((weak)) void uEfCam::repeatParticlePos() {
    DDON_STUB("uEfCam::repeatParticlePos")
    /* stub */
}

inline uEfCam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uEfCam::MyDTI uEfCam::DTI("uEfCam", &::uEffectExt::DTI, 912ul, 0u, 0u);

MtObject* uEfCam::MyDTI::newInstance() const {
    return new (16u) uEfCam;
}

