// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <ymath.h>
#include "uSoundSubMixer.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rSoundSimpleCurve.h"
#include "rSoundSubMixer.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uSoundSubMixer::getDTI() const {
    return uSoundSubMixer::DTI;
}

inline MtAllocator* uSoundSubMixer::getAllocator() {
    return MtMemoryAllocator::getAllocator(uSoundSubMixer::DTI);
}

void* uSoundSubMixer::operator new(size_t sz, u32 align) {
    return uSoundSubMixer::getAllocator()->memAlloc(sz, align, uSoundSubMixer::DTI.getID());
}

inline void uSoundSubMixer::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundSubMixer::DTI)->memFree(p_addr);
}

uSoundSubMixer::uSoundSubMixer() {
    DDON_STUB("uSoundSubMixer::uSoundSubMixer")
    /* stub */
}

__attribute__((noinline)) uSoundSubMixer::~uSoundSubMixer() {
    DDON_STUB("uSoundSubMixer::~uSoundSubMixer")
    /* stub */
}

MtUI* uSoundSubMixer::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

__attribute__((weak)) void uSoundSubMixer::createProperty(MtPropertyList& s) {
    DDON_STUB("uSoundSubMixer::createProperty")
    /* stub */
}

void uSoundSubMixer::clear() {
    if (mFaderParam.mLength != 0) {
        u32 v0_0 = mFaderParam.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFaderParam.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFaderParam.mpArray[i0_3];
                v1_0 = mFaderParam.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFaderParam.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mFaderParam.mpArray));
    }
    mFaderParam.mpArray = nullptr;
    mFaderParam.mBufsiz = 0;
    mFaderParam.mLength = 0;
    if (mCalcFaderSubMixers.mLength != 0) {
        u32 v4_0 = mCalcFaderSubMixers.mLength;
        unsigned int i4_3 = 0;
        u32 v5_0;
        for (;;) {
            if (mCalcFaderSubMixers.mpArray[i4_3] == nullptr) {
                v5_0 = v4_0;
            } else {
                delete mCalcFaderSubMixers.mpArray[i4_3];
                v5_0 = mCalcFaderSubMixers.mLength;
            }
            if ((i4_3 + 1u) < v5_0) {
                v4_0 = v5_0;
                i4_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCalcFaderSubMixers.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCalcFaderSubMixers.mpArray));
    }
    mCalcFaderSubMixers.mpArray = nullptr;
    mCalcFaderSubMixers.mBufsiz = 0;
    mCalcFaderSubMixers.mLength = 0;
    if (mCurrentSubMixers.mLength != 0) {
        u32 v8_0 = mCurrentSubMixers.mLength;
        unsigned int i8_3 = 0;
        u32 v9_0;
        for (;;) {
            if (mCurrentSubMixers.mpArray[i8_3] == nullptr) {
                v9_0 = v8_0;
            } else {
                delete mCurrentSubMixers.mpArray[i8_3];
                v9_0 = mCurrentSubMixers.mLength;
            }
            if ((i8_3 + 1u) < v9_0) {
                v8_0 = v9_0;
                i8_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mCurrentSubMixers.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCurrentSubMixers.mpArray));
    }
    mCurrentSubMixers.mpArray = nullptr;
    mCurrentSubMixers.mBufsiz = 0;
    mCurrentSubMixers.mLength = 0;
    mCalcSendSubMixer.rSoundSubMixer::clear();
    if (mpSimpleCurveResource[0] != nullptr) {
        mpSimpleCurveResource[0]->cResource::release();
        mpSimpleCurveResource[0] = nullptr;
    }
    if (mpSimpleCurveResource[1] != nullptr) {
        mpSimpleCurveResource[1]->cResource::release();
        mpSimpleCurveResource[1] = nullptr;
    }
    if (mpSimpleCurveResource[2] != nullptr) {
        mpSimpleCurveResource[2]->cResource::release();
        mpSimpleCurveResource[2] = nullptr;
    }
    if (mpSimpleCurveResource[3] != nullptr) {
        mpSimpleCurveResource[3]->cResource::release();
        mpSimpleCurveResource[3] = nullptr;
    }
    if (mpSubMixerResource[0] != nullptr) {
        mpSubMixerResource[0]->cResource::release();
        mpSubMixerResource[0] = nullptr;
    }
    if (mpSubMixerResource[1] != nullptr) {
        mpSubMixerResource[1]->cResource::release();
        mpSubMixerResource[1] = nullptr;
    }
    if (mpSubMixerResource[2] != nullptr) {
        mpSubMixerResource[2]->cResource::release();
        mpSubMixerResource[2] = nullptr;
    }
    if (mpSubMixerResource[3] != nullptr) {
        mpSubMixerResource[3]->cResource::release();
        mpSubMixerResource[3] = nullptr;
    }
    if (mpSubMixerResource[4] != nullptr) {
        mpSubMixerResource[4]->cResource::release();
        mpSubMixerResource[4] = nullptr;
    }
    if (mpSubMixerResource[5] != nullptr) {
        mpSubMixerResource[5]->cResource::release();
        mpSubMixerResource[5] = nullptr;
    }
    if (mpSubMixerResource[6] != nullptr) {
        mpSubMixerResource[6]->cResource::release();
        mpSubMixerResource[6] = nullptr;
    }
    if (mpSubMixerResource[7] != nullptr) {
        mpSubMixerResource[7]->cResource::release();
        mpSubMixerResource[7] = nullptr;
    }
    if (mpInitSubMixerResource != nullptr) {
        mpInitSubMixerResource->release();
        mpInitSubMixerResource = nullptr;
    }
    mCalcFaderNum = 0;
    mCurrentSubMixerNum = 0;
    mCalcFaderSubMixerNum = 0;
    mFaderNum = 0;
}

__attribute__((weak)) void uSoundSubMixer::move() {
    DDON_STUB("uSoundSubMixer::move")
    /* stub */
}

__attribute__((weak)) bool uSoundSubMixer::initSubMixer(u8 subMixerNum, rSoundSubMixer* pPostSubMixer) {
    DDON_STUB("uSoundSubMixer::initSubMixer")
    return {};
}

void uSoundSubMixer::mergeSubMixer(u8 subMixerIndex, rSoundSubMixer* pSubMixer) {
    setResourceSubMixer(subMixerIndex, pSubMixer);
    executeMergeSubMixer(subMixerIndex, pSubMixer);
}

void uSoundSubMixer::setUseFreeAreaNo(s8 freeAreaNo) {
    if (freeAreaNo <= 15) {
        mUseFreeAreaNo = freeAreaNo;
    }
}

f32 uSoundSubMixer::getSeMasterVolume() {
    if (sSound::getInstance()->mSeMasterVolume == 0.0f) {
        return -96.0f;
    } else {
        return 20.0f * _FLog(sSound::getInstance()->mSeMasterVolume, 1);
    }
}

f32 uSoundSubMixer::getBgmMasterVolume() {
    if (sSound::getInstance()->mBgmMasterVolume == 0.0f) {
        return -96.0f;
    } else {
        return 20.0f * _FLog(sSound::getInstance()->mBgmMasterVolume, 1);
    }
}

f32 uSoundSubMixer::getEnvMasterVolume() {
    if (sSound::getInstance()->mEnvMasterVolume == 0.0f) {
        return -96.0f;
    } else {
        return 20.0f * _FLog(sSound::getInstance()->mEnvMasterVolume, 1);
    }
}

f32 uSoundSubMixer::getVoiceMasterVolume() {
    if (sSound::getInstance()->mVoiceMasterVolume == 0.0f) {
        return -96.0f;
    } else {
        return 20.0f * _FLog(sSound::getInstance()->mVoiceMasterVolume, 1);
    }
}

f32 uSoundSubMixer::getSystemMasterVolume() {
    if (sSound::getInstance()->mSystemMasterVolume == 0.0f) {
        return -96.0f;
    } else {
        return 20.0f * _FLog(sSound::getInstance()->mSystemMasterVolume, 1);
    }
}

f32 uSoundSubMixer::getEventMasterVolume() {
    if (sSound::getInstance()->mEventMasterVolume == 0.0f) {
        return -96.0f;
    } else {
        return 20.0f * _FLog(sSound::getInstance()->mEventMasterVolume, 1);
    }
}

b8 uSoundSubMixer::getIsActiveSubMixer0() {
    if (mCurrentSubMixerNum != 0) {
        return static_cast<rSoundSubMixer*>(*mCurrentSubMixers.getBuffer())->getActive();
    } else {
        return false;
    }
}

__attribute__((weak)) b8 uSoundSubMixer::getIsActiveSubMixer1() {
    DDON_STUB("uSoundSubMixer::getIsActiveSubMixer1")
    return {};
}

__attribute__((weak)) b8 uSoundSubMixer::getIsActiveSubMixer2() {
    DDON_STUB("uSoundSubMixer::getIsActiveSubMixer2")
    return {};
}

__attribute__((weak)) b8 uSoundSubMixer::getIsActiveSubMixer3() {
    DDON_STUB("uSoundSubMixer::getIsActiveSubMixer3")
    return {};
}

__attribute__((weak)) b8 uSoundSubMixer::getIsActiveSubMixer4() {
    DDON_STUB("uSoundSubMixer::getIsActiveSubMixer4")
    return {};
}

__attribute__((weak)) b8 uSoundSubMixer::getIsActiveSubMixer5() {
    DDON_STUB("uSoundSubMixer::getIsActiveSubMixer5")
    return {};
}

__attribute__((weak)) b8 uSoundSubMixer::getIsActiveSubMixer6() {
    DDON_STUB("uSoundSubMixer::getIsActiveSubMixer6")
    return {};
}

__attribute__((weak)) b8 uSoundSubMixer::getIsActiveSubMixer7() {
    DDON_STUB("uSoundSubMixer::getIsActiveSubMixer7")
    return {};
}

__attribute__((weak)) void uSoundSubMixer::setIsActiveSubMixer0(b8 isActiveSubMixer) {
    DDON_STUB("uSoundSubMixer::setIsActiveSubMixer0")
    /* stub */
}

__attribute__((weak)) void uSoundSubMixer::setIsActiveSubMixer1(b8 isActiveSubMixer) {
    DDON_STUB("uSoundSubMixer::setIsActiveSubMixer1")
    /* stub */
}

__attribute__((weak)) void uSoundSubMixer::setIsActiveSubMixer2(b8 isActiveSubMixer) {
    DDON_STUB("uSoundSubMixer::setIsActiveSubMixer2")
    /* stub */
}

__attribute__((weak)) void uSoundSubMixer::setIsActiveSubMixer3(b8 isActiveSubMixer) {
    DDON_STUB("uSoundSubMixer::setIsActiveSubMixer3")
    /* stub */
}

__attribute__((weak)) void uSoundSubMixer::setIsActiveSubMixer4(b8 isActiveSubMixer) {
    DDON_STUB("uSoundSubMixer::setIsActiveSubMixer4")
    /* stub */
}

__attribute__((weak)) void uSoundSubMixer::setIsActiveSubMixer5(b8 isActiveSubMixer) {
    DDON_STUB("uSoundSubMixer::setIsActiveSubMixer5")
    /* stub */
}

__attribute__((weak)) void uSoundSubMixer::setIsActiveSubMixer6(b8 isActiveSubMixer) {
    DDON_STUB("uSoundSubMixer::setIsActiveSubMixer6")
    /* stub */
}

__attribute__((weak)) void uSoundSubMixer::setIsActiveSubMixer7(b8 isActiveSubMixer) {
    DDON_STUB("uSoundSubMixer::setIsActiveSubMixer7")
    /* stub */
}

rSoundSubMixer* uSoundSubMixer::getResourceSubMixer0() {
    if (mCurrentSubMixerNum != 0) {
        return mpSubMixerResource[0];
    } else {
        return nullptr;
    }
}

rSoundSubMixer* uSoundSubMixer::getResourceSubMixer1() {
    if (mCurrentSubMixerNum > 1) {
        return mpSubMixerResource[1];
    } else {
        return nullptr;
    }
}

rSoundSubMixer* uSoundSubMixer::getResourceSubMixer2() {
    if (mCurrentSubMixerNum > 2) {
        return mpSubMixerResource[2];
    } else {
        return nullptr;
    }
}

rSoundSubMixer* uSoundSubMixer::getResourceSubMixer3() {
    if (mCurrentSubMixerNum > 3) {
        return mpSubMixerResource[3];
    } else {
        return nullptr;
    }
}

rSoundSubMixer* uSoundSubMixer::getResourceSubMixer4() {
    if (mCurrentSubMixerNum > 4) {
        return mpSubMixerResource[4];
    } else {
        return nullptr;
    }
}

rSoundSubMixer* uSoundSubMixer::getResourceSubMixer5() {
    if (mCurrentSubMixerNum > 5) {
        return mpSubMixerResource[5];
    } else {
        return nullptr;
    }
}

rSoundSubMixer* uSoundSubMixer::getResourceSubMixer6() {
    if (mCurrentSubMixerNum > 6) {
        return mpSubMixerResource[6];
    } else {
        return nullptr;
    }
}

rSoundSubMixer* uSoundSubMixer::getResourceSubMixer7() {
    if (mCurrentSubMixerNum > 7) {
        return mpSubMixerResource[7];
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void uSoundSubMixer::setResourceSubMixer(u8 index, rSoundSubMixer* res) {
    if (scePthreadMutexLock(&mSoundSubMixerSection.mCSection) != 0) {
        abort();
    }
    if (index < mCurrentSubMixerNum) {
        if (mpSubMixerResource[index] != nullptr) {
            mpSubMixerResource[index]->cResource::release();
            mpSubMixerResource[index] = nullptr;
        }
        if (res != nullptr) {
            mpSubMixerResource[index] = res;
            res->addRef();
            if (scePthreadMutexUnlock(&mSoundSubMixerSection.mCSection) != 0) {
                abort();
            }
        } else {
            rSoundSubMixer* t0 = mpInitSubMixerResource;
            mpSubMixerResource[index] = t0;
            if (mpSubMixerResource[index] != nullptr) {
                t0->addRef();
            }
            if (scePthreadMutexUnlock(&mSoundSubMixerSection.mCSection) != 0) {
                abort();
            }
        }
    } else {
        if (scePthreadMutexUnlock(&mSoundSubMixerSection.mCSection) != 0) {
            abort();
        }
    }
}

void uSoundSubMixer::setResourceSubMixer0(rSoundSubMixer* res) {
    setResourceSubMixer(static_cast<u8>(0), res);
}

void uSoundSubMixer::setResourceSubMixer1(rSoundSubMixer* res) {
    setResourceSubMixer(static_cast<u8>(1), res);
}

void uSoundSubMixer::setResourceSubMixer2(rSoundSubMixer* res) {
    setResourceSubMixer(static_cast<u8>(2), res);
}

void uSoundSubMixer::setResourceSubMixer3(rSoundSubMixer* res) {
    setResourceSubMixer(static_cast<u8>(3), res);
}

void uSoundSubMixer::setResourceSubMixer4(rSoundSubMixer* res) {
    setResourceSubMixer(static_cast<u8>(4), res);
}

void uSoundSubMixer::setResourceSubMixer5(rSoundSubMixer* res) {
    setResourceSubMixer(static_cast<u8>(5), res);
}

void uSoundSubMixer::setResourceSubMixer6(rSoundSubMixer* res) {
    setResourceSubMixer(static_cast<u8>(6), res);
}

void uSoundSubMixer::setResourceSubMixer7(rSoundSubMixer* res) {
    setResourceSubMixer(static_cast<u8>(7), res);
}

void uSoundSubMixer::mergeSubMixer0() {
    executeMergeSubMixer(static_cast<u8>(0), mpSubMixerResource[0]);
}

void uSoundSubMixer::mergeSubMixer1() {
    executeMergeSubMixer(static_cast<u8>(1), mpSubMixerResource[1]);
}

void uSoundSubMixer::mergeSubMixer2() {
    executeMergeSubMixer(static_cast<u8>(2), mpSubMixerResource[2]);
}

void uSoundSubMixer::mergeSubMixer3() {
    executeMergeSubMixer(static_cast<u8>(3), mpSubMixerResource[3]);
}

void uSoundSubMixer::mergeSubMixer4() {
    executeMergeSubMixer(static_cast<u8>(4), mpSubMixerResource[4]);
}

void uSoundSubMixer::mergeSubMixer5() {
    executeMergeSubMixer(static_cast<u8>(5), mpSubMixerResource[5]);
}

void uSoundSubMixer::mergeSubMixer6() {
    executeMergeSubMixer(static_cast<u8>(6), mpSubMixerResource[6]);
}

void uSoundSubMixer::mergeSubMixer7() {
    executeMergeSubMixer(static_cast<u8>(7), mpSubMixerResource[7]);
}

void uSoundSubMixer::mergeSubMixerAll() {
    u32 i = 0;
    if (mCurrentSubMixerNum != 0) {
        do {
            executeMergeSubMixer(static_cast<unsigned char>(i), mpSubMixerResource[i]);
            i += 1u;
        } while (i < mCurrentSubMixerNum);
    }
}

void uSoundSubMixer::setResourceSimpleCurve0(rSoundSimpleCurve* res) {
    if (scePthreadMutexLock(&mSoundSimpleCurveSection.mCSection) != 0) {
        abort();
    }
    if (mpSimpleCurveResource[0] != nullptr) {
        mpSimpleCurveResource[0]->cResource::release();
        mpSimpleCurveResource[0] = nullptr;
    }
    if (res != nullptr) {
        mpSimpleCurveResource[0] = res;
        res->addRef();
    }
    if (scePthreadMutexUnlock(&mSoundSimpleCurveSection.mCSection) != 0) {
        abort();
    }
}

void uSoundSubMixer::setResourceSimpleCurve1(rSoundSimpleCurve* res) {
    if (scePthreadMutexLock(&mSoundSimpleCurveSection.mCSection) != 0) {
        abort();
    }
    if (mpSimpleCurveResource[1] != nullptr) {
        mpSimpleCurveResource[1]->cResource::release();
        mpSimpleCurveResource[1] = nullptr;
    }
    if (res != nullptr) {
        mpSimpleCurveResource[1] = res;
        res->addRef();
    }
    if (scePthreadMutexUnlock(&mSoundSimpleCurveSection.mCSection) != 0) {
        abort();
    }
}

void uSoundSubMixer::setResourceSimpleCurve2(rSoundSimpleCurve* res) {
    if (scePthreadMutexLock(&mSoundSimpleCurveSection.mCSection) != 0) {
        abort();
    }
    if (mpSimpleCurveResource[2] != nullptr) {
        mpSimpleCurveResource[2]->cResource::release();
        mpSimpleCurveResource[2] = nullptr;
    }
    if (res != nullptr) {
        mpSimpleCurveResource[2] = res;
        res->addRef();
    }
    if (scePthreadMutexUnlock(&mSoundSimpleCurveSection.mCSection) != 0) {
        abort();
    }
}

void uSoundSubMixer::setResourceSimpleCurve3(rSoundSimpleCurve* res) {
    if (scePthreadMutexLock(&mSoundSimpleCurveSection.mCSection) != 0) {
        abort();
    }
    if (mpSimpleCurveResource[3] != nullptr) {
        mpSimpleCurveResource[3]->cResource::release();
        mpSimpleCurveResource[3] = nullptr;
    }
    if (res != nullptr) {
        mpSimpleCurveResource[3] = res;
        res->addRef();
    }
    if (scePthreadMutexUnlock(&mSoundSimpleCurveSection.mCSection) != 0) {
        abort();
    }
}

rSoundSimpleCurve* uSoundSubMixer::getResourceSimpleCurve0() {
    return mpSimpleCurveResource[0];
}

rSoundSimpleCurve* uSoundSubMixer::getResourceSimpleCurve1() {
    return mpSimpleCurveResource[1];
}

rSoundSimpleCurve* uSoundSubMixer::getResourceSimpleCurve2() {
    return mpSimpleCurveResource[2];
}

rSoundSimpleCurve* uSoundSubMixer::getResourceSimpleCurve3() {
    return mpSimpleCurveResource[3];
}

void uSoundSubMixer::mergeSimpleCurve0() {
    rSoundSimpleCurve* v0_10 = mpSimpleCurveResource[0];
    if (scePthreadMutexLock(&mSoundSimpleCurveSection.mCSection) == 0) {
        if (mCalcFaderSubMixerNum != 0) {
            for (unsigned int i0_3 = 0;;) {
                static_cast<rSoundSubMixer*>(mCalcFaderSubMixers.getBuffer()[static_cast<int>(i0_3)])->setResourceSimpleCurve(static_cast<u8>(0), v0_10);
                if ((i0_3 + 1u) < mCalcFaderSubMixerNum) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (scePthreadMutexUnlock(&mSoundSimpleCurveSection.mCSection) == 0) {
            return;
        }
    }
    abort();
}

void uSoundSubMixer::mergeSimpleCurve1() {
    rSoundSimpleCurve* v0_10 = mpSimpleCurveResource[1];
    if (scePthreadMutexLock(&mSoundSimpleCurveSection.mCSection) == 0) {
        if (mCalcFaderSubMixerNum != 0) {
            for (unsigned int i0_3 = 0;;) {
                static_cast<rSoundSubMixer*>(mCalcFaderSubMixers.getBuffer()[static_cast<int>(i0_3)])->setResourceSimpleCurve(static_cast<u8>(1), v0_10);
                if ((i0_3 + 1u) < mCalcFaderSubMixerNum) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (scePthreadMutexUnlock(&mSoundSimpleCurveSection.mCSection) == 0) {
            return;
        }
    }
    abort();
}

void uSoundSubMixer::mergeSimpleCurve2() {
    rSoundSimpleCurve* v0_10 = mpSimpleCurveResource[2];
    if (scePthreadMutexLock(&mSoundSimpleCurveSection.mCSection) == 0) {
        if (mCalcFaderSubMixerNum != 0) {
            for (unsigned int i0_3 = 0;;) {
                static_cast<rSoundSubMixer*>(mCalcFaderSubMixers.getBuffer()[static_cast<int>(i0_3)])->setResourceSimpleCurve(static_cast<u8>(2), v0_10);
                if ((i0_3 + 1u) < mCalcFaderSubMixerNum) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (scePthreadMutexUnlock(&mSoundSimpleCurveSection.mCSection) == 0) {
            return;
        }
    }
    abort();
}

void uSoundSubMixer::mergeSimpleCurve3() {
    rSoundSimpleCurve* v0_10 = mpSimpleCurveResource[3];
    if (scePthreadMutexLock(&mSoundSimpleCurveSection.mCSection) == 0) {
        if (mCalcFaderSubMixerNum != 0) {
            for (unsigned int i0_3 = 0;;) {
                static_cast<rSoundSubMixer*>(mCalcFaderSubMixers.getBuffer()[static_cast<int>(i0_3)])->setResourceSimpleCurve(static_cast<u8>(3), v0_10);
                if ((i0_3 + 1u) < mCalcFaderSubMixerNum) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (scePthreadMutexUnlock(&mSoundSimpleCurveSection.mCSection) == 0) {
            return;
        }
    }
    abort();
}

__attribute__((weak)) void uSoundSubMixer::executeMergeSubMixer(u8 subMixerIndex, rSoundSubMixer* pSubMixer) {
    DDON_STUB("uSoundSubMixer::executeMergeSubMixer")
    /* stub */
}

void uSoundSubMixer::setPreset() {
    if (mEQPreset[0] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[0]), 0u);
    }
    if (mEQPreset[1] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[1]), 0u);
    }
    if (mEQPreset[2] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[2]), 0u);
    }
    if (mEQPreset[3] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[3]), 0u);
    }
    if (mEQPreset[4] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[4]), 0u);
    }
    if (mEQPreset[5] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[5]), 0u);
    }
    if (mEQPreset[6] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[6]), 0u);
    }
    if (mEQPreset[7] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[7]), 0u);
    }
    if (mEQPreset[8] > -1) {
        sSound::getInstance()->setEQId(static_cast<u32>(mEQPreset[8]), 0u);
    }
    if (mReverbPreset[0] > -1) {
        sSound::getInstance()->setReverbId(static_cast<u32>(mReverbPreset[0]), 0u, 0u);
    }
    if (mReverbPreset[1] > -1) {
        sSound::getInstance()->setReverbId(static_cast<u32>(mReverbPreset[1]), 1u, 0u);
    }
    if (mReverbPreset[2] > -1) {
        sSound::getInstance()->setReverbId(static_cast<u32>(mReverbPreset[2]), 2u, 0u);
    }
    if (mReverbPreset[3] > -1) {
        sSound::getInstance()->setReverbId(static_cast<u32>(mReverbPreset[3]), 3u, 0u);
        return;
    }
}

__attribute__((weak)) void uSoundSubMixer::applyVoiceCallback(sSound::VoiceAccessor& va, void* p) {
    DDON_STUB("uSoundSubMixer::applyVoiceCallback")
    /* stub */
}

__attribute__((weak)) void uSoundSubMixer::applyExtractCallback(sSound::VoiceAccessor& va, void* p) {
    DDON_STUB("uSoundSubMixer::applyExtractCallback")
    /* stub */
}

void uSoundSubMixer::createPropertyGroupSystemMasterVolume(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Se:", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getSeMasterVolume), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "BGM:", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getBgmMasterVolume), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Vo:", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getVoiceMasterVolume), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Env:", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getEnvMasterVolume), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Sys:", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getSystemMasterVolume), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Event:", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getEventMasterVolume), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

void uSoundSubMixer::createPropertyGroupSubMixerCurveResource(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Curve0", "resource", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getResourceSimpleCurve0), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::setResourceSimpleCurve0), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Set Resource", static_cast<MT_MFUNC>(&::uSoundSubMixer::mergeSimpleCurve0), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Curve1", "resource", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getResourceSimpleCurve1), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::setResourceSimpleCurve1), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Set Resource", static_cast<MT_MFUNC>(&::uSoundSubMixer::mergeSimpleCurve1), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Curve2", "resource", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getResourceSimpleCurve2), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::setResourceSimpleCurve2), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Set Resource", static_cast<MT_MFUNC>(&::uSoundSubMixer::mergeSimpleCurve2), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Curve3", "resource", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::getResourceSimpleCurve3), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::setResourceSimpleCurve3), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Set Resource", static_cast<MT_MFUNC>(&::uSoundSubMixer::mergeSimpleCurve3), 10u);
}

__attribute__((weak)) void uSoundSubMixer::createPropertyGroupSubMixer(MtPropertyList& s) {
    DDON_STUB("uSoundSubMixer::createPropertyGroupSubMixer")
    /* stub */
}

__attribute__((weak)) s32 uSoundSubMixer::getFaderID(sSound::VoiceAccessor& va) {
    DDON_STUB("uSoundSubMixer::getFaderID")
    return {};
}

void uSoundSubMixer::applyVol(sSound::VoiceAccessor& va, f32 volume) {
    va.setExternalVolume(volume, 1u);
}

void uSoundSubMixer::applyEfcSend(sSound::VoiceAccessor& va, f32 efcSend) {
    va.setExternalEffectVolume(efcSend, 1u);
}

inline uSoundSubMixer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundSubMixer::MyDTI uSoundSubMixer::DTI("uSoundSubMixer", &::cUnit::DTI, 904ul, 0u, 0u);

__attribute__((weak)) MtObject* uSoundSubMixer::MyDTI::newInstance() const {
    DDON_STUB("uSoundSubMixer::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uSoundSubMixer::CurrentSubMixer::getDTI() const {
    return uSoundSubMixer::CurrentSubMixer::DTI;
}

inline void* uSoundSubMixer::CurrentSubMixer::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uSoundSubMixer::CurrentSubMixer::DTI)->memAlloc(sz, align, uSoundSubMixer::CurrentSubMixer::DTI.getID());
}

inline void uSoundSubMixer::CurrentSubMixer::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundSubMixer::CurrentSubMixer::DTI)->memFree(p_addr);
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::add(rSoundSubMixer::Fader* pFader) {
    DDON_STUB("uSoundSubMixer::CurrentSubMixer::add")
    /* stub */
}

inline uSoundSubMixer::CurrentSubMixer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundSubMixer::CurrentSubMixer::MyDTI uSoundSubMixer::CurrentSubMixer::DTI("uSoundSubMixer::CurrentSubMixer", &::rSoundSubMixer::DTI, 488ul, 0u, 0u);

MtObject* uSoundSubMixer::CurrentSubMixer::MyDTI::newInstance() const {
    return new (16u) uSoundSubMixer::CurrentSubMixer;
}

const MtDTI& uSoundSubMixer::CurrentSubMixer::CurrentFader::getDTI() const {
    return uSoundSubMixer::CurrentSubMixer::CurrentFader::DTI;
}

inline void* uSoundSubMixer::CurrentSubMixer::CurrentFader::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uSoundSubMixer::CurrentSubMixer::CurrentFader::DTI)->memAlloc(sz, align, uSoundSubMixer::CurrentSubMixer::CurrentFader::DTI.getID());
}

inline void uSoundSubMixer::CurrentSubMixer::CurrentFader::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundSubMixer::CurrentSubMixer::CurrentFader::DTI)->memFree(p_addr);
}

void uSoundSubMixer::CurrentSubMixer::CurrentFader::createProperty(MtPropertyList& s) {
    this->rSoundSubMixer::Fader::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFaderID", &mFaderID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSendID", &mSendID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mVol", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::getVol), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::setVol), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mAbs", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::getAbs), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::setAbs), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S16, "mCurve", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::getCurve), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::setCurve), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mTransitionTime", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::getTransitionTime), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::setTransitionTime), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mSustainTime", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::getSustainTime), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::setSustainTime), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U16, "mReleaseTime", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::getReleaseTime), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::setReleaseTime), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S8, "mEqNo", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::getEqNo), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::setEqNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S8, "mEffectNo", reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::getEffectNo), reinterpret_cast<MT_MFUNC>(&::uSoundSubMixer::CurrentSubMixer::CurrentFader::setEffectNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uSoundSubMixer::CurrentSubMixer::CurrentFader::createUI(MtProperty& prop) {
    return this->rSoundSubMixer::Fader::createUI(prop);
}

__attribute__((weak)) f32 uSoundSubMixer::CurrentSubMixer::CurrentFader::getVol() {
    DDON_STUB("uSoundSubMixer::CurrentSubMixer::CurrentFader::getVol")
    return {};
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::CurrentFader::setVol(f32 vol) {
    DDON_STUB("uSoundSubMixer::CurrentSubMixer::CurrentFader::setVol")
    /* stub */
}

bool uSoundSubMixer::CurrentSubMixer::CurrentFader::getAbs() {
    if (mpSoundSubMixer != nullptr) {
        if (mSubMixerIndex < mpSoundSubMixer->mCurrentSubMixerNum) {
            if (static_cast<unsigned int>(mFaderIndex) < static_cast<unsigned int>(mpSoundSubMixer->mFaderNum)) {
                return (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpSoundSubMixer->mCalcFaderSubMixers.getBuffer()[static_cast<unsigned long>(mFaderIndex) >> 5]) + 360)) + static_cast<unsigned long>(static_cast<unsigned char>(mSubMixerIndex + (mFaderIndex * 8)) * 8)) + 0)) + 0)) != 0;
            }
        }
    }
    return false;
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::CurrentFader::setAbs(bool abs) {
    DDON_STUB("uSoundSubMixer::CurrentSubMixer::CurrentFader::setAbs")
    /* stub */
}

s16 uSoundSubMixer::CurrentSubMixer::CurrentFader::getCurve() {
    if (mpSoundSubMixer != nullptr) {
        if (mSubMixerIndex < mpSoundSubMixer->mCurrentSubMixerNum) {
            if (static_cast<unsigned int>(mFaderIndex) < static_cast<unsigned int>(mpSoundSubMixer->mFaderNum)) {
                return static_cast<s16>(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpSoundSubMixer->mCalcFaderSubMixers.getBuffer()[static_cast<unsigned long>(mFaderIndex) >> 5]) + 392)) + static_cast<unsigned long>(static_cast<unsigned char>(mSubMixerIndex + (mFaderIndex * 8)) * 8)) + 0)) + 0));
            }
        }
    }
    return -1;
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::CurrentFader::setCurve(s16 curve) {
}

u16 uSoundSubMixer::CurrentSubMixer::CurrentFader::getTransitionTime() {
    if (mpSoundSubMixer != nullptr) {
        if (mSubMixerIndex < mpSoundSubMixer->mCurrentSubMixerNum) {
            if (static_cast<unsigned int>(mFaderIndex) < static_cast<unsigned int>(mpSoundSubMixer->mFaderNum)) {
                return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpSoundSubMixer->mCalcFaderSubMixers.getBuffer()[static_cast<unsigned long>(mFaderIndex) >> 5]) + 400)) + static_cast<unsigned long>(static_cast<unsigned char>(mSubMixerIndex + (mFaderIndex * 8)) * 8)) + 0)) + 0);
            }
        }
    }
    return 0;
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::CurrentFader::setTransitionTime(u16 transitionTime) {
}

u16 uSoundSubMixer::CurrentSubMixer::CurrentFader::getSustainTime() {
    if (mpSoundSubMixer != nullptr) {
        if (mSubMixerIndex < mpSoundSubMixer->mCurrentSubMixerNum) {
            if (static_cast<unsigned int>(mFaderIndex) < static_cast<unsigned int>(mpSoundSubMixer->mFaderNum)) {
                return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpSoundSubMixer->mCalcFaderSubMixers.getBuffer()[static_cast<unsigned long>(mFaderIndex) >> 5]) + 408)) + static_cast<unsigned long>(static_cast<unsigned char>(mSubMixerIndex + (mFaderIndex * 8)) * 8)) + 0)) + 0);
            }
        }
    }
    return 0;
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::CurrentFader::setSustainTime(u16 sustainTime) {
}

u16 uSoundSubMixer::CurrentSubMixer::CurrentFader::getReleaseTime() {
    if (mpSoundSubMixer != nullptr) {
        if (mSubMixerIndex < mpSoundSubMixer->mCurrentSubMixerNum) {
            if (static_cast<unsigned int>(mFaderIndex) < static_cast<unsigned int>(mpSoundSubMixer->mFaderNum)) {
                return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpSoundSubMixer->mCalcFaderSubMixers.getBuffer()[static_cast<unsigned long>(mFaderIndex) >> 5]) + 416)) + static_cast<unsigned long>(static_cast<unsigned char>(mSubMixerIndex + (mFaderIndex * 8)) * 8)) + 0)) + 0);
            }
        }
    }
    return 0;
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::CurrentFader::setReleaseTime(u16 releaseTime) {
}

s8 uSoundSubMixer::CurrentSubMixer::CurrentFader::getEqNo() {
    if (mpSoundSubMixer != nullptr) {
        if (mSubMixerIndex < mpSoundSubMixer->mCurrentSubMixerNum) {
            if (static_cast<unsigned int>(mFaderIndex) < static_cast<unsigned int>(mpSoundSubMixer->mFaderNum)) {
                return static_cast<s8>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpSoundSubMixer->mCalcFaderSubMixers.getBuffer()[static_cast<unsigned long>(mFaderIndex) >> 5]) + 344)) + static_cast<unsigned long>(static_cast<unsigned char>(mSubMixerIndex + (mFaderIndex * 8)) * 8)) + 0)) + 0));
            }
        }
    }
    return -2;
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::CurrentFader::setEqNo(s8 eqNo) {
    DDON_STUB("uSoundSubMixer::CurrentSubMixer::CurrentFader::setEqNo")
    /* stub */
}

s8 uSoundSubMixer::CurrentSubMixer::CurrentFader::getEffectNo() {
    if (mpSoundSubMixer != nullptr) {
        if (mSubMixerIndex < mpSoundSubMixer->mCurrentSubMixerNum) {
            if (static_cast<unsigned int>(mFaderIndex) < static_cast<unsigned int>(mpSoundSubMixer->mFaderNum)) {
                return static_cast<s8>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mpSoundSubMixer->mCalcFaderSubMixers.getBuffer()[static_cast<unsigned long>(mFaderIndex) >> 5]) + 352)) + static_cast<unsigned long>(static_cast<unsigned char>(mSubMixerIndex + (mFaderIndex * 8)) * 8)) + 0)) + 0));
            }
        }
    }
    return -2;
}

__attribute__((weak)) void uSoundSubMixer::CurrentSubMixer::CurrentFader::setEffectNo(s8 effectNo) {
    DDON_STUB("uSoundSubMixer::CurrentSubMixer::CurrentFader::setEffectNo")
    /* stub */
}

inline uSoundSubMixer::CurrentSubMixer::CurrentFader::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundSubMixer::CurrentSubMixer::CurrentFader::MyDTI uSoundSubMixer::CurrentSubMixer::CurrentFader::DTI("uSoundSubMixer::CurrentSubMixer::CurrentFader", &::rSoundSubMixer::Fader::DTI, 48ul, 0u, 0u);

MtObject* uSoundSubMixer::CurrentSubMixer::CurrentFader::MyDTI::newInstance() const {
    return new (16u) uSoundSubMixer::CurrentSubMixer::CurrentFader;
}

const MtDTI& uSoundSubMixer::FaderParam::getDTI() const {
    return uSoundSubMixer::FaderParam::DTI;
}

inline void* uSoundSubMixer::FaderParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uSoundSubMixer::FaderParam::DTI)->memAlloc(sz, align, uSoundSubMixer::FaderParam::DTI.getID());
}

inline void uSoundSubMixer::FaderParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uSoundSubMixer::FaderParam::DTI)->memFree(p_addr);
}

void uSoundSubMixer::FaderParam::createProperty(MtPropertyList& s) {
    this->rSoundSubMixer::Fader::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFaderID", &mFaderID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSendID", &mSendID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "OutputVol", &mVol, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEqNo", &mEqNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectNo", &mEffectNo, 0u, 0u);
}

MtUI* uSoundSubMixer::FaderParam::createUI(MtProperty& prop) {
    return this->rSoundSubMixer::Fader::createUI(prop);
}

inline uSoundSubMixer::FaderParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSoundSubMixer::FaderParam::MyDTI uSoundSubMixer::FaderParam::DTI("uSoundSubMixer::FaderParam", &::rSoundSubMixer::Fader::DTI, 40ul, 0u, 0u);

MtObject* uSoundSubMixer::FaderParam::MyDTI::newInstance() const {
    return new (16u) uSoundSubMixer::FaderParam;
}

template MtTypedArray<rSoundSubMixer>::~MtTypedArray();

template MtTypedArray<uSoundSubMixer::CurrentSubMixer>::~MtTypedArray();

template MtTypedArray<uSoundSubMixer::FaderParam>::~MtTypedArray();

