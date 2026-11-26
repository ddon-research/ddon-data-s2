// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cAITask.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPerformance.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cAIObject.h"
#include "nAITaskPerformance.h"
#include "sAI.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAITask::getDTI() const {
    return cAITask::DTI;
}

inline void cAITask::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAITask::DTI)->memFree(p_addr);
}

__attribute__((noinline)) cAITask::cAITask() {
        mBackgroundJobType = BG_JOB_LOOP;
        mQuitTaskLoop = false;
        mEnablePerformanceManage = false;
        mTaskStatus = TASK_ST_IDLE;
        mpCurrentJobPrimitive = nullptr;
        mIsBackgroundTask = false;
        mpBackgroundNextTask = nullptr;
        mpBackgroundPrevTask = nullptr;
        mTaskAllowTime = 3.402823466e+38f;
        mPerformanceIndicator = 1.0f;
        mOverloadManageType = 0;
        mpDoneCallback = nullptr;
        mpDoneCallbackOwner = nullptr;
        mLODLevel = -1;
        mpPerformanceInfo = nullptr;
}

__attribute__((noinline)) cAITask::~cAITask() {
    if (sAI::getInstance() != nullptr) {
        sAI::getInstance()->removeBackgroundTask(this);
    }
}

MtUI* cAITask::createUI(MtProperty& prop) {
    return nullptr;
}

void cAITask::createProperty(MtPropertyList& s) {
    this->cAIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mTaskStatus", &mTaskStatus, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnablePerformanceManage", &mEnablePerformanceManage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOverloadManageType", &mOverloadManageType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPerformanceIndicator", &mPerformanceIndicator, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLODLevel", &mLODLevel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTaskAllowTime", &mTaskAllowTime, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpPerformanceInfo", reinterpret_cast<MtObject* *>(&mpPerformanceInfo), 1u, 0u);
}

__attribute__((weak)) bool cAITask::moveTask() {
    DDON_STUB("cAITask::moveTask")
    return {};
}

void cAITask::doneTask() {
    mQuitTaskLoop = true;
}

void cAITask::nextJob() {
    mpCurrentJobPrimitive = mpCurrentJobPrimitive->mpNext;
    if (mpCurrentJobPrimitive != nullptr) {
        return;
    }
    mQuitTaskLoop = true;
}

__attribute__((weak)) void cAITask::moveTaskBackground() {
    DDON_STUB("cAITask::moveTaskBackground")
    /* stub */
}

void cAITask::moveJobOnDelayJob(u32 param) {
    if (mpCurrentJobPrimitive != nullptr) {
        if (mpCurrentJobPrimitive->mpOwner != nullptr) {
            if (mpCurrentJobPrimitive->mJobFunc != static_cast<cAITaskJobPrim::JOB_FUNC>(0)) {
                (mpCurrentJobPrimitive->mpOwner->*mpCurrentJobPrimitive->mJobFunc)();
            }
        }
    }
    if (!mQuitTaskLoop) {
        (sMain::mpInstance)->sMain::addDelayJob(static_cast<MtObject*>(this), static_cast<MT_MFUNC32>(&::cAITask::moveJobOnDelayJob), param);
    }
}

inline cAITask::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAITask::MyDTI cAITask::DTI("cAITask", &::cAIObject::DTI, 136ul, 0u, 0u);

__attribute__((weak)) MtObject* cAITask::MyDTI::newInstance() const {
    DDON_STUB("cAITask::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAITaskJobPrim::getDTI() const {
    return cAITaskJobPrim::DTI;
}

void* cAITaskJobPrim::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAITaskJobPrim::DTI)->memAlloc(sz, align, cAITaskJobPrim::DTI.mID);
}

__attribute__((weak)) void cAITaskJobPrim::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAITaskJobPrim::DTI)->memFree(p_addr);
}

inline cAITaskJobPrim::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAITaskJobPrim::MyDTI cAITaskJobPrim::DTI("cAITaskJobPrim", &::cAIObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cAITaskJobPrim::MyDTI::newInstance() const {
    DDON_STUB("cAITaskJobPrim::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAITaskJobPrimList::getDTI() const {
    return cAITaskJobPrimList::DTI;
}

inline void* cAITaskJobPrimList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAITaskJobPrimList::DTI)->memAlloc(sz, align, cAITaskJobPrimList::DTI.mID);
}

inline void cAITaskJobPrimList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAITaskJobPrimList::DTI)->memFree(p_addr);
}

cAITaskJobPrimList::~cAITaskJobPrimList() {
    if (mpList != nullptr) {
        for (cAITaskJobPrim* v0_5 = mpList;;) {
            cAITaskJobPrim* t0 = v0_5->mpNext;
            delete v0_5;
            if (t0 != nullptr) {
                v0_5 = t0;
            } else {
                break;
            }
        }
    }
    mpList = nullptr;
}

void cAITaskJobPrimList::add(cAITaskJobPrim* pPrim) {
    if (pPrim == nullptr) {
        return;
    }
    if (pPrim->mpNext != nullptr) {
        return;
    }
    if (mpList != nullptr) {
        mpListBottom->mpNext = pPrim;
    } else {
        mpList = pPrim;
    }
    pPrim->mpNext = nullptr;
    mpListBottom = pPrim;
}

inline cAITaskJobPrimList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAITaskJobPrimList::MyDTI cAITaskJobPrimList::DTI("cAITaskJobPrimList", &::cAIObject::DTI, 24ul, 0u, 0u);

MtObject* cAITaskJobPrimList::MyDTI::newInstance() const {
    return new (16u) cAITaskJobPrimList;
}

