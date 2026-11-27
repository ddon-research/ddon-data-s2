// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sAI.h"
#include "../MT/MtCRC.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "../MT/MtSynchronize.h"
#include "cAIService.h"
#include "cAITask.h"
#include "cSystem.h"
#include "nAITaskPerformance.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sAI::getDTI() const {
    return sAI::DTI;
}

sAI::sAI() {
    DDON_STUB("sAI::sAI")
    /* stub */
}

__attribute__((noinline)) sAI::~sAI() {
    DDON_STUB("sAI::~sAI")
    /* stub */
}

void sAI::reset() {
    for (cAIService* v0_3 = mpServiceTop;;) {
        if (v0_3 == nullptr) {
            break;
        } else {
            v0_3->reset();
            v0_3 = v0_3->mpNextService;
        }
    }
    mFrameId = 0;
}

__attribute__((weak)) void sAI::move() {
    DDON_STUB("sAI::move")
    /* stub */
}

void sAI::moveAfter() {
    if (mpServiceTop != nullptr) {
        for (cAIService* v0_3 = mpServiceTop;;) {
            if ((v0_3->mAttribute & 1u) != 0) {
                if ((sMain::mpInstance)->mSkip == 0) {
                    if ((sMain::mpInstance)->mPause) {
                        if ((v0_3->mAttribute & 2u) == 0) {
                            v0_3->move();
                        }
                    } else {
                        v0_3->move();
                    }
                } else {
                    v0_3->move();
                }
            }
            if (v0_3->mpNextService != nullptr) {
                v0_3 = v0_3->mpNextService;
            } else {
                break;
            }
        }
    }
}

void sAI::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    for (cAIService* pSrv = mpServiceTop;;) {
        if (pSrv == nullptr) {
            break;
        } else {
            pSrv->applyWorldOffset(offset, absolute_offset);
            pSrv = pSrv->mpNextService;
        }
    }
}

void sAI::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "ServiceList", reinterpret_cast<MT_MFUNC>(&::sAI::getServiceByIndex), reinterpret_cast<MT_MFUNC>(&::sAI::setServiceByIndex), 162u, reinterpret_cast<MT_MFUNC>(&::sAI::getServiceNum), reinterpret_cast<MT_MFUNC>(&::sAI::setServiceNum));
    s << MtProperty(static_cast<MtObject*>(this), "PerformanceIndicator", &mTaskPerformanceIndicator, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "TaskPerformanceInfoList", reinterpret_cast<MT_MFUNC>(&::sAI::getTaskPerformanceInfo), reinterpret_cast<MT_MFUNC>(&::sAI::setTaskPerformanceInfo), 162u, reinterpret_cast<MT_MFUNC>(&::sAI::getTaskPerformanceInfoNum), reinterpret_cast<MT_MFUNC>(&::sAI::setTaskPerformanceInfoNum));
}

MtUI* sAI::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sAI::addService(cAIService* pService, MT_CTSTR entryName) {
    DDON_STUB("sAI::addService")
    /* stub */
}

void sAI::addService(MT_CTSTR dtiName, MT_CTSTR entryName) {
    const MtDTI* t0 = MtDTI::from(dtiName, MtDTI::mDTI);
    const MtDTI* v0_0;
    MT_CTSTR v0_1;
    MtObject* pobj;
    if (t0 != nullptr) {
        pobj = t0->newInstance();
        if (pobj == nullptr) {
            return;
        } else {
            const MtDTI& t2 = pobj->getDTI();
            v0_1 = cAIService::DTI.mName;
            v0_0 = &t2;
        }
    } else {
        return;
    }
    for (;;) {
        if (v0_1 == v0_0->mName) {
            addService(static_cast<cAIService*>(pobj), entryName);
            return;
        } else {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                break;
            }
        }
    }
    delete pobj;
}

u32 sAI::getServiceNum() {
    unsigned int i0_0 = 0;
    for (cAIService* pSrv = mpServiceTop;;) {
        if (pSrv == nullptr) {
            break;
        } else {
            i0_0 += 1u;
            pSrv = pSrv->mpNextService;
        }
    }
    return i0_0;
}

__attribute__((weak)) cAIService* sAI::getService(const MtDTI& dti, MT_CTSTR n) {
    for (cAIService* pSrv = mpServiceTop; pSrv != nullptr; pSrv = pSrv->mpNextService) {
        if (pSrv->getDTI() == dti) {
            if (n == nullptr || strcmp(n, pSrv->mName.ptr()) == 0) {
                return pSrv;
            }
        }
    }
    return nullptr;
}

cAIService* sAI::getService(MT_CTSTR n) {
    cAIService* v2_8;
    if (mpServiceTop == nullptr) {
        v2_8 = nullptr;
    } else {
        for (cAIService* pSrv = mpServiceTop;;) {
            if (pSrv->mName.value != nullptr) {
                if (strcmp(n, reinterpret_cast<const char*>(pSrv->mName.value->str)) != 0) {
                    if (pSrv->mpNextService != nullptr) {
                        pSrv = pSrv->mpNextService;
                    } else {
                        break;
                    }
                } else {
                    v2_8 = pSrv;
                    return v2_8;
                }
            } else {
                if ((*n) != '\0') {
                    if (pSrv->mpNextService != nullptr) {
                        pSrv = pSrv->mpNextService;
                    } else {
                        break;
                    }
                } else {
                    v2_8 = pSrv;
                    return v2_8;
                }
            }
        }
        v2_8 = nullptr;
    }
    return v2_8;
}

cAIService* sAI::getServiceByIndex(u32 index) {
    if (mpServiceTop != nullptr) {
        cAIService* pSrv = mpServiceTop;
        for (u32 v0_1 = index + 1u;;) {
            if ((v0_1 - 1u) == 0) {
                return pSrv;
            } else {
                if (pSrv->mpNextService != nullptr) {
                    pSrv = pSrv->mpNextService;
                    v0_1 += 0xFFFFFFFFu;
                } else {
                    break;
                }
            }
        }
    }
    return nullptr;
}

void sAI::deleteService(MT_CTSTR n) {
    if (mpServiceTop != nullptr) {
        for (cAIService* pTarget = mpServiceTop;;) {
            MtString::STRING* t0 = pTarget->mName.value;
            cAIService* pSrv = pTarget->mpNextService;
            if (t0 != nullptr) {
                if (strcmp(n, reinterpret_cast<const char*>(t0->str)) == 0) {
                    cAIService* t2 = pTarget->mpPrevService;
                    if (t2 != nullptr) {
                        t2->mpNextService = pSrv;
                        if (pSrv != nullptr) {
                            pSrv->mpPrevService = t2;
                        } else {
                            mpServiceBottom = t2;
                        }
                    } else {
                        mpServiceTop = pSrv;
                        if (mpServiceTop != nullptr) {
                            pSrv->mpPrevService = t2;
                        } else {
                            mpServiceBottom = t2;
                        }
                    }
                    pTarget->mpNextService = nullptr;
                    pTarget->mpPrevService = nullptr;
                    delete pTarget;
                }
            } else {
                if ((*n) == '\0') {
                    cAIService* t2 = pTarget->mpPrevService;
                    if (t2 != nullptr) {
                        t2->mpNextService = pSrv;
                        if (pSrv != nullptr) {
                            pSrv->mpPrevService = t2;
                        } else {
                            mpServiceBottom = t2;
                        }
                    } else {
                        mpServiceTop = pSrv;
                        if (mpServiceTop != nullptr) {
                            pSrv->mpPrevService = t2;
                        } else {
                            mpServiceBottom = t2;
                        }
                    }
                    pTarget->mpNextService = nullptr;
                    pTarget->mpPrevService = nullptr;
                    delete pTarget;
                }
            }
            if (pSrv != nullptr) {
                pTarget = pSrv;
            } else {
                break;
            }
        }
    }
}

nAI::TaskPerformanceInfo* sAI::searchTaskPerformanceInfo(const MtDTI* pDTI) {
    nAI::TaskPerformanceInfo* v0_3 = mTaskPerformanceInfoList;
    nAI::TaskPerformanceInfo* v2_0;
    if (v0_3 == nullptr) {
        v2_0 = nullptr;
    } else {
        u32 v0_1 = mTaskPerformanceInfoNum;
        if (v0_1 == 0) {
            v2_0 = nullptr;
        } else {
            unsigned int i0_0 = 0;
            for (nAI::TaskPerformanceInfo* p0_2 = v0_3;;) {
                if (pDTI != p0_2->mpDTI) {
                    if ((i0_0 + 1u) < v0_1) {
                        i0_0 = i0_0 + 1u;
                        p0_2 += 1;
                    } else {
                        break;
                    }
                } else {
                    v2_0 = &v0_3[i0_0];
                    return v2_0;
                }
            }
            v2_0 = nullptr;
        }
    }
    return v2_0;
}

void sAI::entryBackgroundTask(cAITask* pTask) {
    if (pTask->mIsBackgroundTask) {
        return;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (mpBackgroundTaskTop != nullptr) {
        cAITask* t0 = mpBackgroundTaskBottom;
        t0->mpBackgroundNextTask = pTask;
        pTask->mpBackgroundPrevTask = t0;
        pTask->mpBackgroundNextTask = nullptr;
        mpBackgroundTaskBottom = pTask;
        pTask->mIsBackgroundTask = true;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    } else {
        mpBackgroundTaskTop = pTask;
        pTask->mpBackgroundPrevTask = nullptr;
        pTask->mpBackgroundNextTask = nullptr;
        mpBackgroundTaskBottom = pTask;
        pTask->mIsBackgroundTask = true;
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
}

void sAI::removeBackgroundTask(cAITask* pTask) {
    if (!pTask->mIsBackgroundTask) {
        return;
    }
    cAITask* pPrev = pTask->mpBackgroundPrevTask;
    cAITask* pNext = pTask->mpBackgroundNextTask;
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (pPrev != nullptr) {
        pPrev->mpBackgroundNextTask = pNext;
        if (pNext != nullptr) {
            pNext->mpBackgroundPrevTask = pPrev;
        } else {
            mpBackgroundTaskBottom = pPrev;
        }
    } else {
        mpBackgroundTaskTop = pNext;
        if (mpBackgroundTaskTop != nullptr) {
            pNext->mpBackgroundPrevTask = pPrev;
        } else {
            mpBackgroundTaskBottom = pPrev;
        }
    }
    pTask->mIsBackgroundTask = false;
    pTask->mpBackgroundNextTask = nullptr;
    pTask->mpBackgroundPrevTask = nullptr;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

__attribute__((weak)) void sAI::setServiceNum(u32 num) {
}

__attribute__((weak)) void sAI::setServiceByIndex(cAIService* ps, u32 index) {
}

__attribute__((weak)) bool sAI::createTaskPerformanceInfoList() {
    DDON_STUB("sAI::createTaskPerformanceInfoList")
    return {};
}

void sAI::countTaskClassChild(u32& num, const MtDTI* pDTI) {
    for (const MtDTI* pChild = pDTI->mpChild;;) {
        if (pChild == nullptr) {
            break;
        } else {
            if ((pChild->mAttr & 1u) == 0) {
                num = (num) + 1u;
            }
        }
        countTaskClassChild(num, pChild);
        pChild = pChild->mpNext;
    }
}

void sAI::setDTIToTaskPerformanceInfo(u32& index, const MtDTI* pDTI) {
    for (const MtDTI* pChild = pDTI->mpChild;;) {
        if (pChild == nullptr) {
            break;
        } else {
            if ((pChild->mAttr & 1u) == 0) {
                mTaskPerformanceInfoList[index].mpDTI = pChild;
                index = (index) + 1u;
            }
        }
        setDTIToTaskPerformanceInfo(index, pChild);
        pChild = pChild->mpNext;
    }
}

nAI::TaskPerformanceInfo* sAI::getTaskPerformanceInfo(u32 index) {
    if (mTaskPerformanceInfoList != nullptr) {
        if (index < mTaskPerformanceInfoNum) {
            return &mTaskPerformanceInfoList[index];
        }
    }
    return nullptr;
}

__attribute__((weak)) void sAI::setTaskPerformanceInfo(nAI::TaskPerformanceInfo* pi, u32 index) {
}

u32 sAI::getTaskPerformanceInfoNum() {
    return mTaskPerformanceInfoNum;
}

__attribute__((weak)) void sAI::setTaskPerformanceInfoNum(u32 num) {
}

inline sAI::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sAI::MyDTI sAI::DTI("sAI", &::cSystem::DTI, 96ul, 0u, 0u);

sAI* sAI::mpInstance;

__attribute__((weak)) MtObject* sAI::MyDTI::newInstance() const {
    DDON_STUB("sAI::MyDTI::newInstance")
    return nullptr;
}

