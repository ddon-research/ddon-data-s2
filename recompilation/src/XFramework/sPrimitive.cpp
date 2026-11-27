// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "sPrimitive.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSynchronize.h"
#include "cBlendState.h"
#include "cDraw.h"
#include "cPrim.h"
#include "cPrimBufferManager.h"
#include "cPrimTagList.h"
#include "cPrimTagManager.h"
#include "cPrimTexHandleManager.h"
#include "cSystem.h"
#include "nDraw.h"
#include "nDrawResource.h"
#include "nPrim.h"
#include "sMain.h"
#include "sScene.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sPrimitive::getDTI() const {
    return sPrimitive::DTI;
}

void* sPrimitive::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sPrimitive::DTI)->memAlloc(sz, align, sPrimitive::DTI.mID);
}

__attribute__((weak)) cPrim* sPrimitive::getCPrim(cDraw* p_draw, sPrimitive::ePrimType type, cUnit* p_unit) {
    DDON_STUB("sPrimitive::getCPrim")
    return nullptr;
}

__attribute__((weak)) cPrim* sPrimitive::getCPrim(cDraw* p_draw, nDraw::PASS_TYPE pass, cUnit* p_unit) {
    DDON_STUB("sPrimitive::getCPrim")
    return nullptr;
}

void sPrimitive::begin() {
    u32 job_num = (sMain::mpInstance)->mJobThreadNum;
    mpTagManager->assignTags(&mpPrim[0], job_num);
    u32 ui;
    if (job_num == 0) {
        ui = job_num;
    } else {
        u32 v0_3 = job_num;
        for (cPrim* * p0_10 = &mpPrim[0];;) {
            (*p0_10)->cPrim::clear();
            if ((v0_3 - 1u) != 0) {
                v0_3 += 0xFFFFFFFFu;
                p0_10 += 1;
            } else {
                break;
            }
        }
        ui = job_num;
    }
    for (;;) {
        if (ui >= mNumOfPrim) {
            break;
        } else {
            cPrimTagList* t0 = mpPrim[ui]->mpPrimTagList;
            t0->mTagSize = 0;
            t0->mpSorted = nullptr;
            t0->mpTags = nullptr;
            t0->clearTag();
            mpPrim[ui]->cPrim::clear();
            ui += 1u;
        }
    }
    mpTexHandleMgr->mUsedTex = 1;
    cPrimBufferManager* t1 = mpBufferMgr;
    t1->mpCurrentPtr = t1->mpBuffer;
    t1->mCurrentSize = 0;
}

__attribute__((weak)) void sPrimitive::end() {
}

__attribute__((weak)) s32 sPrimitive::beginBranch(cDraw* p_draw, cDraw* sub_draw, u32 nsub_draw, bool use_vscr) {
    DDON_STUB("sPrimitive::beginBranch")
    return {};
}

__attribute__((weak)) s32 sPrimitive::endBranch(cDraw* p_draw, cDraw* sub_draw, u32 nsub_draw) {
    DDON_STUB("sPrimitive::endBranch")
    return {};
}

void sPrimitive::initPrimitiveSys(u32 vb_size, u32 tag_size) {
    if (mState != 1) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
        mpTexHandleMgr = new (16u) cPrimTexHandleManager(1025u);
        mNumOfPrim = 6;
        mpBufferMgr = new (16u) cPrimBufferManager(vb_size);
        mpTagManager = new (16u) cPrimTagManager(tag_size);
        if (mNumOfPrim != 0) {
            for (unsigned int i0_3 = 0;;) {
                if ((mpPrim[i0_3] = new (16u) cPrim) == nullptr) {
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                            abort();
                            return;
                        }
                    }
                    return;
                } else {
                    if ((i0_3 + 1u) < mNumOfPrim) {
                        i0_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    } else {
        return;
    }
    clearTag();
    mState = 1;
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

void sPrimitive::termPrimitiveSys() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    if (mpPrim[0] != nullptr) {
        delete mpPrim[0];
        mpPrim[0] = nullptr;
    }
    if (mpPrim[1] != nullptr) {
        delete mpPrim[1];
        mpPrim[1] = nullptr;
    }
    if (mpPrim[2] != nullptr) {
        delete mpPrim[2];
        mpPrim[2] = nullptr;
    }
    if (mpPrim[3] != nullptr) {
        delete mpPrim[3];
        mpPrim[3] = nullptr;
    }
    if (mpPrim[4] != nullptr) {
        delete mpPrim[4];
        mpPrim[4] = nullptr;
    }
    if (mpPrim[5] != nullptr) {
        delete mpPrim[5];
        mpPrim[5] = nullptr;
    }
    if (mpTexHandleMgr != nullptr) {
        delete mpTexHandleMgr;
        mpTexHandleMgr = nullptr;
    }
    if (mpBufferMgr != nullptr) {
        delete mpBufferMgr;
        mpBufferMgr = nullptr;
    }
    if (mpTagManager != nullptr) {
        delete mpTagManager;
        mpTagManager = nullptr;
    }
    mState = 2;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) == 0) {
        return;
    }
    abort();
}

void sPrimitive::createProperty(MtPropertyList& prop_list) {
    this->cSystem::createProperty(prop_list);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mOcclusionVTF", &mOcclusionVTF, 3u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mDrawPrimitive", &mDrawPrimitive, 2u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mDepthDiv", &mDepthDiv, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mIntensityScale", &mIntensityScale, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mSceneClampType", &mSceneClampType, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mSceneClampRange", &mSceneClampRange, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mPrimModelLtNum", &mPrimModelLtNum, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mPrimAlphaClip", &mPrimAlphaClip, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mDepthCmpLimit", &mDepthCmpLimit, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mPrimStencilFunc", reinterpret_cast<s32*>(&mPrimStencilFunc), 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mPrimStencilRef", &mPrimStencilRef, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mScreenPassLayer", &mScreenPassLayer, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mVolumeScale", &mVolumeScale, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mVolumeEnable", &mVolumeEnable, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mParallaxScale", &mParallaxScale, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mParallaxMinLoop", &mParallaxMinLoop, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mParallaxMaxLoop", &mParallaxMaxLoop, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mParallaxFadeStart", &mParallaxFadeStart, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mParallaxFadeEnd", &mParallaxFadeEnd, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mParallaxEnable", &mParallaxEnable, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mNearStart", &mNearStart, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mNearEnd", &mNearEnd, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mFarStart", &mFarStart, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mFarEnd", &mFarEnd, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mRefractZThreshold", &mRefractZThreshold, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mRefractZBlur", &mRefractZBlur, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mReductionDist", &mReductionDist, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mAutoReduction", &mAutoReduction, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mScreenLayout", &mScreenLayout, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mVirtualScrW", &mVirtualScrW, 0u, 0u);
    prop_list << MtProperty(static_cast<MtObject*>(this), "mVirtualScrH", &mVirtualScrH, 0u, 0u);
}

MtUI* sPrimitive::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

u32 sPrimitive::reserveTex(nPrim::Texture* * p_tex, u32* idx, u32 num_tex) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        cPrimTexHandleManager* t0 = mpTexHandleMgr;
        u32 t1 = t0->mTextureMax;
        u32 t2 = t0->mUsedTex;
        if (t2 < t1) {
            *p_tex = &t0->mpTexture[t2];
            *idx = t2;
            t0->mUsedTex = num_tex + t0->mUsedTex;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return (t1 < (num_tex + t2)) ? (t1 - t2) : num_tex;
        } else {
            *p_tex = nullptr;
            *idx = 0;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return 0;
        }
    } else {
        cPrimTexHandleManager* t0 = mpTexHandleMgr;
        u32 t1 = t0->mTextureMax;
        u32 t2 = t0->mUsedTex;
        if (t2 < t1) {
            *p_tex = &t0->mpTexture[t2];
            *idx = t2;
            t0->mUsedTex = num_tex + t0->mUsedTex;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return (t1 < (num_tex + t2)) ? (t1 - t2) : num_tex;
        } else {
            *p_tex = nullptr;
            *idx = 0;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return 0;
        }
    }
}

u32 sPrimitive::reserveBuffer(void* * ptr, u32 size) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        cPrimBufferManager* t0 = mpBufferMgr;
        *ptr = nullptr;
        if (t0->mpBuffer != nullptr) {
            u32 t1 = t0->mCurrentSize;
            u32 t2 = t0->mTotalSize;
            *ptr = t0->mpCurrentPtr;
            t0->mpCurrentPtr = static_cast<void*>(static_cast<char*>(t0->mpCurrentPtr) + ((t2 < (size + t1)) ? (t2 - t1) : size));
            t0->mCurrentSize = t1 + ((t2 < (size + t1)) ? (t2 - t1) : size);
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return (t2 < (size + t1)) ? (t2 - t1) : size;
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return 0;
        }
    } else {
        cPrimBufferManager* t0 = mpBufferMgr;
        *ptr = nullptr;
        if (t0->mpBuffer != nullptr) {
            u32 t1 = t0->mCurrentSize;
            u32 t2 = t0->mTotalSize;
            *ptr = t0->mpCurrentPtr;
            t0->mpCurrentPtr = static_cast<void*>(static_cast<char*>(t0->mpCurrentPtr) + ((t2 < (size + t1)) ? (t2 - t1) : size));
            t0->mCurrentSize = t1 + ((t2 < (size + t1)) ? (t2 - t1) : size);
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return (t2 < (size + t1)) ? (t2 - t1) : size;
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            return 0;
        }
    }
}

__attribute__((weak)) void sPrimitive::drawJob(cDraw* p_draw, sPrimitive::DrawInfo* p_info) {
    DDON_STUB("sPrimitive::drawJob")
    /* stub */
}

__attribute__((weak)) u32 sPrimitive::changeMaterial(cDraw* p_draw, const nPrim::Material& new_mat, nPrim::MetaDataHeader* old_header, nPrim::MetaDataHeader* new_header) {
    DDON_STUB("sPrimitive::changeMaterial")
    return {};
}

__attribute__((weak)) u32 sPrimitive::drawPrimitive(cDraw* p_draw, cPrimTagList::IndexTag* p_tag, u32 num, u32 v_num, u32 i_num) {
    DDON_STUB("sPrimitive::drawPrimitive")
    return {};
}

__attribute__((weak)) void sPrimitive::setDrawState(cDraw* p_draw, const nPrim::Material& material) {
    DDON_STUB("sPrimitive::setDrawState")
    /* stub */
}

__attribute__((weak)) void sPrimitive::setBlendState(cDraw* p_draw, const nPrim::Material& material, u32 fog) {
    DDON_STUB("sPrimitive::setBlendState")
    /* stub */
}

__attribute__((weak)) void sPrimitive::setMetaData(cDraw* p_draw, const nPrim::Material& material, nPrim::MetaDataHeader* old_header, nPrim::MetaDataHeader* new_header) {
    DDON_STUB("sPrimitive::setMetaData")
    /* stub */
}

void sPrimitive::clearTag() {
    mpPrim[0]->cPrim::clear();
    mpPrim[1]->cPrim::clear();
    mpPrim[2]->cPrim::clear();
    mpPrim[3]->cPrim::clear();
    mpPrim[4]->cPrim::clear();
    mpPrim[5]->cPrim::clear();
}

__attribute__((weak)) u32 sPrimitive::drawTags(cDraw* p_draw, u32 disp_lv, const nPrim::Material& mat, cPrimTagList::IndexTag* p_tag, u32 num, u32 vnum, u32 inum, u32 base_priority, nPrim::MetaDataHeader* old_header, nPrim::MetaDataHeader* curr_header, bool reduction, u32 r_dist) {
    DDON_STUB("sPrimitive::drawTags")
    return {};
}

__attribute__((weak)) u32 sPrimitive::setPrimitiveExtFunc(cDraw* p_draw, const nPrim::Material& mat) {
    DDON_STUB("sPrimitive::setPrimitiveExtFunc")
    return {};
}

__attribute__((weak)) u32 sPrimitive::setPrimitiveFogFunc(cDraw* p_draw, const nPrim::Material& mat, u32 ex) {
    DDON_STUB("sPrimitive::setPrimitiveFogFunc")
    return {};
}

__attribute__((weak)) u32 sPrimitive::setPrimitiveTexFunc(cDraw* p_draw, const nPrim::Material& mat, u32 ex) {
    DDON_STUB("sPrimitive::setPrimitiveTexFunc")
    return {};
}

sPrimitive::sPrimitive(u32 vb_size, u32 tag_size) {
    DDON_STUB("sPrimitive::sPrimitive")
    /* stub */
}

__attribute__((noinline)) sPrimitive::~sPrimitive() {
    DDON_STUB("sPrimitive::~sPrimitive")
    /* stub */
}

inline sPrimitive::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sPrimitive::MyDTI sPrimitive::DTI("sPrimitive", &::cSystem::DTI, 528ul, 0u, 0u);

sPrimitive* sPrimitive::mpInstance;

__attribute__((weak)) MtObject* sPrimitive::MyDTI::newInstance() const {
    DDON_STUB("sPrimitive::MyDTI::newInstance")
    return nullptr;
}

