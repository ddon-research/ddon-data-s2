// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "sCamera.h"
#include "../MT/MtCRC.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#include "cDraw.h"
#include "cResource.h"
#include "cSystem.h"
#include "sMain.h"
#include "sOccluder.h"
#include "sRender.h"
#include "sScene.h"
#include "sShadow.h"
#include "sUnit.h"
#include "sVibration.h"
#include "uCamera.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sCamera::getDTI() const {
    return sCamera::DTI;
}

sCamera::sCamera() {
    DDON_STUB("sCamera::sCamera")
    /* stub */
}

__attribute__((noinline)) sCamera::~sCamera() {
    DDON_STUB("sCamera::~sCamera")
    /* stub */
}

__attribute__((weak)) void sCamera::reset() {
    DDON_STUB("sCamera::reset")
    /* stub */
}

__attribute__((weak)) void sCamera::move() {
    DDON_STUB("sCamera::move")
    /* stub */
}

__attribute__((weak)) void sCamera::draw(cDraw* pdraw, nDraw::Scene* pscene, u32 display_no) {
    DDON_STUB("sCamera::draw")
    /* stub */
}

void sCamera::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mViewport", static_cast<MtObject*>(&mViewport[0]), 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), "mBGColor", &mBGColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlankColor", &mBlankColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVirtualRect", &mVirtualRect, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPause", &mPause, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstancingDissolveStartDistance", &mInstancingDissolveStartDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstancingDissolveEndDistance", &mInstancingDissolveEndDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstancingDissolveAlpha", &mInstancingDissolveAlpha, 0u, 0u);
}

MtUI* sCamera::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sCamera::clearBlank(cDraw* pdraw, const MtRect& srect) {
    DDON_STUB("sCamera::clearBlank")
    /* stub */
}

void sCamera::updateViewportFrustum(uCamera* pCamera) {
    if (pCamera == nullptr) {
        return;
    }
    if ((pCamera->mBeFlag - 1u) > 1u) {
        return;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    if (pCamera == mViewport[0].mpCamera) {
        mViewport[0].updateFrustum();
    }
    if (pCamera == mViewport[1].mpCamera) {
        mViewport[1].updateFrustum();
    }
    if (pCamera == mViewport[2].mpCamera) {
        mViewport[2].updateFrustum();
    }
    if (pCamera == mViewport[3].mpCamera) {
        mViewport[3].updateFrustum();
    }
    if (pCamera == mViewport[4].mpCamera) {
        mViewport[4].updateFrustum();
    }
    if (pCamera == mViewport[5].mpCamera) {
        mViewport[5].updateFrustum();
    }
    if (pCamera == mViewport[6].mpCamera) {
        mViewport[6].updateFrustum();
    }
    if (pCamera == mViewport[7].mpCamera) {
        mViewport[7].updateFrustum();
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
        return;
    }
    abort();
}

__attribute__((weak)) bool sCamera::isDispAABB(sCamera::VIEWPORT_NO vp, const MtAABB& a) {
    DDON_STUB("sCamera::isDispAABB")
    return {};
}

bool sCamera::isDispSphere(sCamera::VIEWPORT_NO vp, const MtSphere& a) {
    if (mViewport[vp].mpCamera != nullptr) {
        if ((-a.r) > (mViewport[vp].mFrustum[0].w + (((a.pos.x * mViewport[vp].mFrustum[0].x) + (a.pos.y * mViewport[vp].mFrustum[0].y)) + (a.pos.z * mViewport[vp].mFrustum[0].z)))) {
            return false;
        } else {
            if ((-a.r) > (mViewport[vp].mFrustum[1].w + (((a.pos.x * mViewport[vp].mFrustum[1].x) + (a.pos.y * mViewport[vp].mFrustum[1].y)) + (a.pos.z * mViewport[vp].mFrustum[1].z)))) {
                return false;
            } else {
                if ((-a.r) > (mViewport[vp].mFrustum[2].w + (((a.pos.x * mViewport[vp].mFrustum[2].x) + (a.pos.y * mViewport[vp].mFrustum[2].y)) + (a.pos.z * mViewport[vp].mFrustum[2].z)))) {
                    return false;
                } else {
                    if ((-a.r) > (mViewport[vp].mFrustum[3].w + (((a.pos.x * mViewport[vp].mFrustum[3].x) + (a.pos.y * mViewport[vp].mFrustum[3].y)) + (a.pos.z * mViewport[vp].mFrustum[3].z)))) {
                        return false;
                    } else {
                        if ((-a.r) > (mViewport[vp].mFrustum[4].w + (((a.pos.x * mViewport[vp].mFrustum[4].x) + (a.pos.y * mViewport[vp].mFrustum[4].y)) + (a.pos.z * mViewport[vp].mFrustum[4].z)))) {
                            return false;
                        } else {
                            if ((-a.r) > (mViewport[vp].mFrustum[5].w + (((a.pos.x * mViewport[vp].mFrustum[5].x) + (a.pos.y * mViewport[vp].mFrustum[5].y)) + (a.pos.z * mViewport[vp].mFrustum[5].z)))) {
                                return false;
                            } else {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    } else {
        return false;
    }
}

void sCamera::setInstancingDissolveDefaultParam() {
    mInstancingDissolveStartDistance = 450.0f;
    mInstancingDissolveEndDistance = 300.0f;
    mInstancingDissolveAlpha = 0.5f;
}

void sCamera::setInstancingDissolveEmLargeParam() {
    mInstancingDissolveStartDistance = 1000.0f;
    mInstancingDissolveEndDistance = 500.0f;
    mInstancingDissolveAlpha = 0.3f;
}

void sCamera::setInstancingDissolveEventParam() {
    mInstancingDissolveStartDistance = 0.0f;
    mInstancingDissolveEndDistance = 0.0f;
    mInstancingDissolveAlpha = 1.0f;
}

inline sCamera::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCamera::MyDTI sCamera::DTI("sCamera", &::cSystem::DTI, 3440ul, 0u, 0u);

sCamera* sCamera::mpInstance;

__attribute__((weak)) MtObject* sCamera::MyDTI::newInstance() const {
    DDON_STUB("sCamera::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sCamera::Viewport::getDTI() const {
    return sCamera::Viewport::DTI;
}

sCamera::Viewport::~Viewport() {
    DDON_STUB("sCamera::Viewport::~Viewport")
    /* stub */
}

MtUI* sCamera::Viewport::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool sCamera::Viewport::setup(cDraw* pdraw) {
    DDON_STUB("sCamera::Viewport::setup")
    return {};
}

__attribute__((weak)) void sCamera::Viewport::updateRegion() {
    DDON_STUB("sCamera::Viewport::updateRegion")
    /* stub */
}

void sCamera::Viewport::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mNo", &mNo, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVisible", &mVisible, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisplay", &mDisplay, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMode", &mMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRegion", &mRegion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCamera", reinterpret_cast<MtObject* *>(&mpCamera), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSceneTexture", "resource", static_cast<void*>(&mpSceneTexture), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTestCamera", reinterpret_cast<MtObject* *>(&mpTestCamera), 16u, 0u);
}

__attribute__((weak)) void sCamera::Viewport::updateFrustum() {
    DDON_STUB("sCamera::Viewport::updateFrustum")
    /* stub */
}

inline sCamera::Viewport::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCamera::Viewport::MyDTI sCamera::Viewport::DTI("sCamera::Viewport", &::MtObject::DTI, 416ul, 0u, 0u);

__attribute__((weak)) MtObject* sCamera::Viewport::MyDTI::newInstance() const {
    DDON_STUB("sCamera::Viewport::MyDTI::newInstance")
    return nullptr;
}

