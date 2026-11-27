// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sGrass.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "../MT/MtSynchronize.h"
#include "cBVHGrass.h"
#include "cDraw.h"
#include "cSystem.h"
#include "cUnit.h"
#include "nDrawIndexBuffer.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "nDrawVertexBuffer.h"
#include "sCamera.h"
#include "sUnit.h"
#include "uGrassEffect.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sGrass::getDTI() const {
    return sGrass::DTI;
}

void* sGrass::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sGrass::DTI)->memAlloc(sz, align, sGrass::DTI.mID);
}

sGrass::~sGrass() {
    DDON_STUB("sGrass::~sGrass")
    /* stub */
}

void sGrass::addGrass(MtObject* pgrass) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        u32 t0 = mGrass.mLength;
        u32 t1 = mGrass.mBufsiz;
        if (t0 < t1) {
            mGrass.mLength = t0 + 1u;
            mGrass.mpArray[t0] = pgrass;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
            memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
            memcpy(t2, static_cast<const void*>(mGrass.mpArray), static_cast<size_t>(mGrass.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGrass.mpArray));
            mGrass.mpArray = static_cast<MtObject* *>(t2);
            mGrass.mBufsiz = t1 + 32u;
            u32 t3 = mGrass.mLength;
            mGrass.mLength = t3 + 1u;
            mGrass.mpArray[t3] = pgrass;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    } else {
        u32 t0 = mGrass.mLength;
        u32 t1 = mGrass.mBufsiz;
        if (t0 < t1) {
            mGrass.mLength = t0 + 1u;
            mGrass.mpArray[t0] = pgrass;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
            memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
            memcpy(t2, static_cast<const void*>(mGrass.mpArray), static_cast<size_t>(mGrass.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGrass.mpArray));
            mGrass.mpArray = static_cast<MtObject* *>(t2);
            mGrass.mBufsiz = t1 + 32u;
            u32 t3 = mGrass.mLength;
            mGrass.mLength = t3 + 1u;
            mGrass.mpArray[t3] = pgrass;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    }
}

void sGrass::removeGrass(MtObject* pgrass) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    u32 v1_0 = mGrass.mLength;
    if (v1_0 != 0) {
        MtObject* * v1_1 = mGrass.mpArray;
        unsigned int i1_3 = 0;
        u32 v4_0;
        unsigned int v5_1;
        u32 v5_2;
        unsigned int v5_3;
        for (;;) {
            if (pgrass == v1_1[i1_3]) {
                if (!mGrass.mAutoDelete) {
                    v4_0 = v1_0;
                } else {
                    if (pgrass == nullptr) {
                        v4_0 = v1_0;
                    } else {
                        delete pgrass;
                        v4_0 = mGrass.mLength;
                    }
                }
                if ((i1_3 + 1u) < v4_0) {
                    v5_1 = i1_3 + 1u;
                    v5_2 = v4_0;
                    v5_3 = i1_3;
                    for (;;) {
                        mGrass.mpArray[v5_3] = mGrass.mpArray[v5_1];
                        if (v5_2 != (v5_1 + 1u)) {
                            v5_3 = v5_1;
                            v5_1 = v5_1 + 1u;
                        } else {
                            break;
                        }
                    }
                }
                mGrass.mLength = v4_0 - 1u;
                break;
            } else {
                if ((i1_3 + 1u) < v1_0) {
                    i1_3 = i1_3 + 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
        return;
    }
    abort();
}

void sGrass::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFadeBeginDistance", &mFadeBeginDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFadeEndDistance", &mFadeEndDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mForcedFade", &mForcedFade, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFadeCurve", &mFadeCurve, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mForcedFadeCurve", &mForcedFadeCurve, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVisiblePercent", &mVisiblePercent, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mForcedVisiblePercent", &mForcedVisiblePercent, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoreSmoothFade", &mMoreSmoothFade, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLODBeginDistance", &mLODBeginDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLODEndDistance", &mLODEndDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLOD", &mLOD, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResourceOverrideVisiblePercent", &mResourceOverrideVisiblePercent, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResourceVisiblePercent", &mResourceVisiblePercent, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResourceOverrideClusterSize", &mResourceOverrideClusterSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResourceClusterSize", &mResourceClusterSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseAlphaToCoverage", &mUseAlphaToCoverage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindMask", &mWindMask, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightMaskMargine", &mLightMaskMargine, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightMaskBlendFactor", &mLightMaskBlendFactor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTarget", reinterpret_cast<MtObject* *>(&mpTarget), 19u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNoCulling", &mNoCulling, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOutputPath", &mOutputPath, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSBCOffset", &mSBCOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsActiveGrassMulValue", reinterpret_cast<MT_MFUNC>(&::sGrass::isActiveGrassMulValue), reinterpret_cast<MT_MFUNC>(&::sGrass::setActiveGrassMulValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mGrassVisiblePercentMulValue", reinterpret_cast<MT_MFUNC>(&::sGrass::getGrassVisiblePercentMulValue), reinterpret_cast<MT_MFUNC>(&::sGrass::setGrassVisiblePercentMulValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mGrassModeMinValue", reinterpret_cast<MT_MFUNC>(&::sGrass::getGrassModeMinValue), reinterpret_cast<MT_MFUNC>(&::sGrass::setGrassModeMinValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mGrassFadeBeginDistanceMulValue", reinterpret_cast<MT_MFUNC>(&::sGrass::getGrassFadeBeginDistanceMulValue), reinterpret_cast<MT_MFUNC>(&::sGrass::setGrassFadeBeginDistanceMulValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mGrassFadeEndDistanceMulValue", reinterpret_cast<MT_MFUNC>(&::sGrass::getGrassFadeEndDistanceMulValue), reinterpret_cast<MT_MFUNC>(&::sGrass::setGrassFadeEndDistanceMulValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mGrassNearClipDistanceMulValue", reinterpret_cast<MT_MFUNC>(&::sGrass::getGrassNearClipDistanceMulValue), reinterpret_cast<MT_MFUNC>(&::sGrass::setGrassNearClipDistanceMulValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* sGrass::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sGrass::begin() {
}

__attribute__((weak)) void sGrass::end() {
    DDON_STUB("sGrass::end")
    /* stub */
}

__attribute__((weak)) void sGrass::addMark(MtObject* p_obj) {
    DDON_STUB("sGrass::addMark")
    /* stub */
}

__attribute__((weak)) void sGrass::delMark(MtObject* p_obj) {
    DDON_STUB("sGrass::delMark")
    /* stub */
}

__attribute__((weak)) void sGrass::setMark(cDraw* pdraw, const MtAABB& boundary) {
    DDON_STUB("sGrass::setMark")
    /* stub */
}

__attribute__((weak)) void sGrass::initGeometry() {
    DDON_STUB("sGrass::initGeometry")
    /* stub */
}

void sGrass::releaseGeometry() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    if (mpIndexBuffer != nullptr) {
        mpIndexBuffer->release();
        mpIndexBuffer = nullptr;
    }
    if (mpPointIndexBuffer != nullptr) {
        mpPointIndexBuffer->release();
        mpPointIndexBuffer = nullptr;
    }
    if (mp6IndexBuffer != nullptr) {
        mp6IndexBuffer->release();
        mp6IndexBuffer = nullptr;
    }
    if (mp64IndexBuffer != nullptr) {
        mp64IndexBuffer->release();
        mp64IndexBuffer = nullptr;
    }
    if (mp62IndexBuffer != nullptr) {
        mp62IndexBuffer->release();
        mp62IndexBuffer = nullptr;
    }
    if (mp6PointIndexBuffer != nullptr) {
        mp6PointIndexBuffer->release();
        mp6PointIndexBuffer = nullptr;
    }
    if (mp4VertexBuffer != nullptr) {
        mp4VertexBuffer->release();
        mp4VertexBuffer = nullptr;
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
        return;
    }
    abort();
}

__attribute__((weak)) u32 sGrass::getLOD(f32 dist) {
    DDON_STUB("sGrass::getLOD")
    return {};
}

__attribute__((weak)) void sGrass::initLightMask() {
    DDON_STUB("sGrass::initLightMask")
    /* stub */
}

void sGrass::releaseLightMask() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (mpTarget != nullptr) {
        s32 t0 = mpTarget->mRefCount;
        mpTarget->release();
        if (t0 == 1) {
            mpTarget = nullptr;
        }
        if (mpDepth != nullptr) {
            s32 t1 = mpDepth->mRefCount;
            mpDepth->release();
            if (t1 == 1) {
                mpDepth = nullptr;
            }
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    } else {
        if (mpDepth != nullptr) {
            s32 t1 = mpDepth->mRefCount;
            mpDepth->release();
            if (t1 == 1) {
                mpDepth = nullptr;
            }
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
    }
}

bool sGrass::isActiveGrassMulValue() const {
    return mIsActiveGrassMulValue;
}

__attribute__((weak)) void sGrass::setActiveGrassMulValue(bool NewActiveGrassMulValue) {
    DDON_STUB("sGrass::setActiveGrassMulValue")
    /* stub */
}

f32 sGrass::getGrassVisiblePercentMulValue() const {
    if (mIsActiveGrassMulValue) {
        return mGrassVisiblePercentMulValue;
    } else {
        return 1.0f;
    }
}

__attribute__((weak)) void sGrass::setGrassVisiblePercentMulValue(f32 NewGrassVisiblePercentMulValue) {
    DDON_STUB("sGrass::setGrassVisiblePercentMulValue")
    /* stub */
}

u32 sGrass::getGrassModeMinValue() const {
    if (mIsActiveGrassMulValue) {
        return mGrassModeMinValue;
    } else {
        return 0;
    }
}

__attribute__((weak)) void sGrass::setGrassModeMinValue(u32 NewGrassModeMinValue) {
    DDON_STUB("sGrass::setGrassModeMinValue")
    /* stub */
}

f32 sGrass::getGrassFadeBeginDistanceMulValue() const {
    if (mIsActiveGrassMulValue) {
        return mGrassFadeBeginDistanceMulValue;
    } else {
        return 1.0f;
    }
}

__attribute__((weak)) void sGrass::setGrassFadeBeginDistanceMulValue(f32 NewFadeInDistanceMulValue) {
    DDON_STUB("sGrass::setGrassFadeBeginDistanceMulValue")
    /* stub */
}

f32 sGrass::getGrassFadeEndDistanceMulValue() const {
    if (mIsActiveGrassMulValue) {
        return mGrassFadeEndDistanceMulValue;
    } else {
        return 1.0f;
    }
}

__attribute__((weak)) void sGrass::setGrassFadeEndDistanceMulValue(f32 NewFadeOutDistanceMulValue) {
    DDON_STUB("sGrass::setGrassFadeEndDistanceMulValue")
    /* stub */
}

f32 sGrass::getGrassNearClipDistanceMulValue() const {
    if (mIsActiveGrassMulValue) {
        return mGrassNearClipDistanceMulValue;
    } else {
        return 1.0f;
    }
}

__attribute__((weak)) void sGrass::setGrassNearClipDistanceMulValue(f32 NewNearClipDistanceMulValue) {
    DDON_STUB("sGrass::setGrassNearClipDistanceMulValue")
    /* stub */
}

sGrass::sGrass() {
    DDON_STUB("sGrass::sGrass")
    /* stub */
}

inline sGrass::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sGrass::MyDTI sGrass::DTI("sGrass", &::cSystem::DTI, 928ul, 0u, 0u);

sGrass* sGrass::mpInstance;

__attribute__((weak)) MtObject* sGrass::MyDTI::newInstance() const {
    DDON_STUB("sGrass::MyDTI::newInstance")
    return nullptr;
}

