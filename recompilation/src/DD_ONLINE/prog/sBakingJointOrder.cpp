// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <kernel.h>
#include <stdlib.h>
#include "sBakingJointOrder.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSynchronize.h"
#include "../../MT/MtThread.h"
#include "cBakeModel.h"
#include "../../XFramework/cDraw.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "cpBakeJoint.h"
#include "cpCharacterEdit.h"
#include "nDDOUtility.h"
#include "../../XFramework/nDrawCommandCache.h"
#include "../../XFramework/nDrawConstantTable.h"
#include "../../XFramework/nDrawResource.h"
#include "rCharacterEdit.h"
#include "../../XFramework/rModel.h"
#include "sFlag.h"
#include "../../XFramework/sRender.h"
#include "../../XFramework/sScene.h"
#include "../../XFramework/sUnit.h"
#include "sUnitManager.h"
#include "../../XFramework/uBaseModel.h"
#include "uDDOActorModelPl.h"
#include "uHuman.h"
#include "uMockUpModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

BakedQueue::BakedQueue() {
    DDON_STUB("BakedQueue::BakedQueue")
    /* stub */
}

BakedQueue::~BakedQueue() {
    DDON_STUB("BakedQueue::~BakedQueue")
    /* stub */
}

__attribute__((weak)) void sBakingJointOrder::asyncBakeJointOrder() {
    DDON_STUB("sBakingJointOrder::asyncBakeJointOrder")
    /* stub */
}

void sBakingJointOrder::syncBakeJointOrder() {
    unsigned int i0_0 = 0;
    for (BakedQueue* p0_2 = &mBakeModelQueue[0]; i0_0 <= 159u; i0_0 = i0_0 + 1u, p0_2 += 1) {
        if (p0_2->getState() == BakedQueue::BAKED_STATE::SYNC) {
            mBakeModelQueue[i0_0].mpInfoCallBack->setRenewalEnvelope();
            p0_2->mBakeState = static_cast<volatile BakedQueue::BAKED_STATE::DECL>(8);
            mBakeModelQueue[i0_0].mpOrderUnit->resetAllMaterial();
            return;
        }
    }
}

const MtDTI& sBakingJointOrder::getDTI() const {
    return sBakingJointOrder::DTI;
}

void* sBakingJointOrder::operator new(size_t sz, u32 align) {
    return sBakingJointOrder::getAllocator()->memAlloc(sz, align, sBakingJointOrder::DTI.getID());
}

sBakingJointOrder::sBakingJointOrder() {
    DDON_STUB("sBakingJointOrder::sBakingJointOrder")
    /* stub */
}

__attribute__((noinline)) sBakingJointOrder::~sBakingJointOrder() {
    DDON_STUB("sBakingJointOrder::~sBakingJointOrder")
    /* stub */
}

void sBakingJointOrder::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsEnableBakingJoint", &mIsEnableBakingJoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "maDeleteUnits", reinterpret_cast<MtObject* *>(&maDeleteUnits[0]), 32u, 320u);
}

MtUI* sBakingJointOrder::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sBakingJointOrder::reset() {
}

__attribute__((weak)) void sBakingJointOrder::move() {
}

__attribute__((weak)) void sBakingJointOrder::createMenu(MtPropertyList& s) {
}

__attribute__((weak)) bool sBakingJointOrder::addBakeQueue(sBakingJointOrder::BAKE_HANDLE& handle, uModel* powner, cpBakeJoint* pcallback) {
    DDON_STUB("sBakingJointOrder::addBakeQueue")
    return {};
}

__attribute__((weak)) void sBakingJointOrder::returnBakeQueue(const sBakingJointOrder::BAKE_HANDLE index) {
    DDON_STUB("sBakingJointOrder::returnBakeQueue")
    /* stub */
}

__attribute__((weak)) bool sBakingJointOrder::setBakeModel(const sBakingJointOrder::BAKE_HANDLE handle, rModel* pBaseModel) {
    DDON_STUB("sBakingJointOrder::setBakeModel")
    return {};
}

__attribute__((weak)) bool sBakingJointOrder::setBakeSolidModels(const sBakingJointOrder::BAKE_HANDLE handle, uModel* pCallerUnit, rModel* * mpaSolidModels, const u32 models_num) {
    DDON_STUB("sBakingJointOrder::setBakeSolidModels")
    return {};
}

__attribute__((weak)) bool sBakingJointOrder::setBakeSoftModels(const sBakingJointOrder::BAKE_HANDLE handle, uModel* pCallerUnit, rModel* * mpaSoftModels, const u32 models_num) {
    DDON_STUB("sBakingJointOrder::setBakeSoftModels")
    return {};
}

bool sBakingJointOrder::orderBakeQueue(const sBakingJointOrder::BAKE_HANDLE handle, uModel* pOriginModel, sBakingJointOrder::ORDER_PRIORITY::DECL priority) {
    if (handle != 0xFFFFFFFFu) {
        if (mBakeModelQueue[handle].mLock == 1) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
            if (mBakeModelQueue[handle].mBakeState != static_cast<volatile BakedQueue::BAKED_STATE::DECL>(0)) {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return false;
            } else {
                mBakeModelQueue[handle].mpOrderUnit = pOriginModel;
                mBakeModelQueue[handle].mPriority = static_cast<u32>(priority);
                mBakeModelQueue[handle].mBakeState = static_cast<volatile BakedQueue::BAKED_STATE::DECL>(1);
                sceKernelSignalSema(mpSemaphore->mHandle, 1);
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                }
                return true;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) bool sBakingJointOrder::execBakeQueue(const sBakingJointOrder::BAKE_HANDLE handle, uModel* pOriginModel, sBakingJointOrder::ORDER_PRIORITY::DECL priority) {
    DDON_STUB("sBakingJointOrder::execBakeQueue")
    return {};
}

__attribute__((weak)) bool sBakingJointOrder::releaseBakeQueue(const sBakingJointOrder::BAKE_HANDLE index) {
    DDON_STUB("sBakingJointOrder::releaseBakeQueue")
    return {};
}

__attribute__((weak)) void sBakingJointOrder::setCommonStateModelOrder(cDraw* pdraw, uModel* punit, cpBakeJoint* pcallback) {
    DDON_STUB("sBakingJointOrder::setCommonStateModelOrder")
    /* stub */
}

__attribute__((weak)) void sBakingJointOrder::drawBakingModelOrder(cDraw* pdraw, uModel* punit, const sBakingJointOrder::BAKE_HANDLE handle) {
    DDON_STUB("sBakingJointOrder::drawBakingModelOrder")
    /* stub */
}

bool sBakingJointOrder::isBaked(const sBakingJointOrder::BAKE_HANDLE index) {
    if (index != 0xFFFFFFFFu) {
        return mBakeModelQueue[index].mBakeState == static_cast<volatile BakedQueue::BAKED_STATE::DECL>(8);
    } else {
        return false;
    }
}

__attribute__((weak)) void sBakingJointOrder::buildInverseMatrix(BakedQueue* pbq) {
    DDON_STUB("sBakingJointOrder::buildInverseMatrix")
    /* stub */
}

void sBakingJointOrder::removeProtectUnits(cUnit* punit) {
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        abort();
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

__attribute__((weak)) void sBakingJointOrder::checkProtectUnits() {
    DDON_STUB("sBakingJointOrder::checkProtectUnits")
    /* stub */
}

void sBakingJointOrder::addDeleteUnitsQueue(cUnit* punit) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    cUnit* * p0_0 = &maDeleteUnits[0];
    for (unsigned int i0_1 = 0; i0_1 <= 319u; p0_0 += 1, i0_1 += 1u) {
        if ((*p0_0) == nullptr) {
            *p0_0 = punit;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                    return;
                }
            }
            return;
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

__attribute__((weak)) void sBakingJointOrder::checkDeleteUnits() {
    DDON_STUB("sBakingJointOrder::checkDeleteUnits")
    /* stub */
}

__attribute__((weak)) void sBakingJointOrder::terminateThread() {
    DDON_STUB("sBakingJointOrder::terminateThread")
    /* stub */
}

void sBakingJointOrder::flushAllCache() {
    u32 i;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        i = 0;
    } else {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        } else {
            i = 0;
        }
    }
    for (;;) {
        if (mBakeModelQueue[i].mpCache[0] != nullptr) {
            mBakeModelQueue[i].mpCache[0]->release();
            mBakeModelQueue[i].mpCache[0] = nullptr;
        }
        if (mBakeModelQueue[i].mpCache[1] != nullptr) {
            mBakeModelQueue[i].mpCache[1]->release();
            mBakeModelQueue[i].mpCache[1] = nullptr;
        }
        if (mBakeModelQueue[i].mpCache[2] != nullptr) {
            mBakeModelQueue[i].mpCache[2]->release();
            mBakeModelQueue[i].mpCache[2] = nullptr;
        }
        if (mBakeModelQueue[i].mpCache[3] != nullptr) {
            mBakeModelQueue[i].mpCache[3]->release();
            mBakeModelQueue[i].mpCache[3] = nullptr;
        }
        if (mBakeModelQueue[i].mpCache[4] != nullptr) {
            mBakeModelQueue[i].mpCache[4]->release();
            mBakeModelQueue[i].mpCache[4] = nullptr;
        }
        if (mBakeModelQueue[i].mpCache[5] != nullptr) {
            mBakeModelQueue[i].mpCache[5]->release();
            mBakeModelQueue[i].mpCache[5] = nullptr;
        }
        if (i != 159) {
            i = i + 1u;
        } else {
            break;
        }
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
    return;
    abort();
}

sBakingJointOrder* sBakingJointOrder::mpInstance;

inline sBakingJointOrder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sBakingJointOrder::MyDTI sBakingJointOrder::DTI("sBakingJointOrder", &::cSystem::DTI, 0x8B9240ul, 0u, 0u);

__attribute__((weak)) MtObject* sBakingJointOrder::MyDTI::newInstance() const {
    DDON_STUB("sBakingJointOrder::MyDTI::newInstance")
    return nullptr;
}

void sBakingJointOrder::BakeJointThread::execute(void* pcontext) {
    mpBJSystem->asyncBakeJointOrder();
}

