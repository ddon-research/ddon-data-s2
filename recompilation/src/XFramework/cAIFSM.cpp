// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cAIFSM.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "cAIConditionTree.h"
#include "cAIObject.h"
#include "cAIService.h"
#include "cAISvFSM.h"
#include "cAIUserProcess.h"
#include "cResource.h"
#include "rAIFSM.h"
#include "sAI.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAIFSM::getDTI() const {
    return cAIFSM::DTI;
}

cAIFSM::cAIFSM() {
    mpOwner = nullptr;
    mCoreNum = 0;
    mpCurrentCore = nullptr;
    mCoreList = nullptr;
    mConditionWaitTime = -1.0f;
    mFFree[7] = 0.0f;
    mFFree[5] = 0.0f;
    mFFree[6] = 0.0f;
    mFFree[3] = 0.0f;
    mFFree[4] = 0.0f;
    mFFree[1] = 0.0f;
    mFFree[2] = 0.0f;
    mIFree[7] = 0;
    mFFree[0] = 0.0f;
    mIFree[5] = 0;
    mIFree[6] = 0;
    mIFree[3] = 0;
    mIFree[4] = 0;
    mIFree[1] = 0;
    mIFree[2] = 0;
    mStatus = 0;
    mIFree[0] = 0;
    createCore(1u);
    if ((sAI::mpInstance) == nullptr) {
        return;
    }
    cAISvFSM* pSvFSM = static_cast<cAISvFSM*>((sAI::mpInstance)->sAI::getService(cAISvFSM::DTI, static_cast<MT_CTSTR>(nullptr)));
    if (pSvFSM == nullptr) {
        return;
    }
    pSvFSM->entryFSM(this);
}

__attribute__((noinline)) cAIFSM::~cAIFSM() {
    DDON_STUB("cAIFSM::~cAIFSM")
    /* stub */
}

MtUI* cAIFSM::createUI(MtProperty& prop) {
    return nullptr;
}

void cAIFSM::createProperty(MtPropertyList& s) {
    this->cAIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mStatus", &mStatus, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mCoreList", reinterpret_cast<MT_MFUNC>(&::cAIFSM::getCore), reinterpret_cast<MT_MFUNC>(&::cAIFSM::setCore), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSM::getCoreNum), reinterpret_cast<MT_MFUNC>(&::cAIFSM::setCoreNum));
    s << MtProperty(static_cast<MtObject*>(this), "mIFree", &mIFree[0], 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), "mFFree", &mFFree[0], 32u, 8u);
}

__attribute__((weak)) bool cAIFSM::createCore(u32 num) {
    DDON_STUB("cAIFSM::createCore")
    return {};
}

bool cAIFSM::setResource(rAIFSM* pRes, u32 index) {
    Core* t0 = mCoreList;
    if (t0 != nullptr) {
        if (index < mCoreNum) {
            if (t0[index].mpResource != nullptr) {
                t0[index].mpResource->release();
                t0[index].mpResource = nullptr;
            }
            if (pRes != nullptr) {
                pRes->addRef();
            }
            t0[index].mpResource = pRes;
            t0[index].createInfoFromResource(pRes);
            return true;
        }
    }
    return false;
}

rAIFSM* cAIFSM::getResource(u32 index) {
    if (mCoreList != nullptr) {
        if (index < mCoreNum) {
            return mCoreList[index].mpResource;
        }
    }
    return nullptr;
}

static auto ddon_emit_0x01b6a720 __attribute__((used)) = &cAIFSM::getCoreNum;

cAIFSM::Core* cAIFSM::getCore(u32 index) {
    if (mCoreList != nullptr) {
        if (index < mCoreNum) {
            return &mCoreList[index];
        }
    }
    return nullptr;
}

__attribute__((weak)) void cAIFSM::setDefaultUpdateFunc(cAIUserProcessCallback::CALLBACK_FUNC func, u32 index) {
    DDON_STUB("cAIFSM::setDefaultUpdateFunc")
    /* stub */
}

void cAIFSM::reset() {
    mStatus = 0;
    if (mCoreNum != 0) {
        u32 v0_0 = mCoreNum;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            Core* v1_7 = mCoreList;
            v1_7[i0_3].mClusterStackBottom = 0;
            if (v1_7[i0_3].mpResource == nullptr) {
                v1_0 = v0_0;
            } else {
                v1_7[i0_3].pushCluster(v1_7[i0_3].mpResource->mpRootCluster);
                v1_0 = mCoreNum;
            }
            v1_7[i0_3].mIsReset = true;
            v1_7[i0_3].mIsImported = false;
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

void cAIFSM::reset(u32 index) {
    mStatus = 0;
    Core* t0 = mCoreList;
    t0[index].mClusterStackBottom = 0;
    if (t0[index].mpResource != nullptr) {
        t0[index].pushCluster(t0[index].mpResource->mpRootCluster);
    }
    t0[index].mIsReset = true;
    t0[index].mIsImported = false;
}

void cAIFSM::move() {
    unsigned int i7 = 0;
    if (mCoreNum != 0) {
        do {
            mpCurrentCore = &mCoreList[i7];
            beginCore(&mCoreList[i7]);
            mpCurrentCore->move();
            endCore(mpCurrentCore);
            i7 += 1u;
        } while (i7 < mCoreNum);
    }
}

__attribute__((weak)) void cAIFSM::setCoreNum(u32 num) {
}

__attribute__((weak)) void cAIFSM::setCore(cAIFSM::Core* pc, u32 index) {
}

inline cAIFSM::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSM::MyDTI cAIFSM::DTI("cAIFSM", &::cAIObject::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIFSM::MyDTI::newInstance() const {
    DDON_STUB("cAIFSM::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAIFSM::Core::getDTI() const {
    return cAIFSM::Core::DTI;
}

__attribute__((noinline)) cAIFSM::Core::~Core() {
    DDON_STUB("cAIFSM::Core::~Core")
    /* stub */
}

void cAIFSM::Core::createProperty(MtPropertyList& s) {
    createCoreProperty(s, false);
}

__attribute__((weak)) void cAIFSM::Core::createCoreProperty(MtPropertyList& s, bool withViewer) {
    s << MtProperty(static_cast<MtObject*>(this), "mpResource", "resource", static_cast<void*>(&mpResource), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mStatus", reinterpret_cast<MT_MFUNC>(&::cAIFSM::Core::getStatus), reinterpret_cast<MT_MFUNC>(&::cAIFSM::Core::setStatus), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAttribute", &mAttribute, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIFree", &mIFree[0], 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), "mFFree", &mFFree[0], 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mClusterWorkList", reinterpret_cast<MT_MFUNC>(&::cAIFSM::Core::getClusterWork), reinterpret_cast<MT_MFUNC>(&::cAIFSM::Core::setClusterWork), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSM::Core::getClusterWorkNum), reinterpret_cast<MT_MFUNC>(&::cAIFSM::Core::setClusterWorkNum));
}

MtUI* cAIFSM::Core::createUI(MtProperty& prop) {
    return nullptr;
}

__attribute__((weak)) void cAIFSM::Core::move() {
    DDON_STUB("cAIFSM::Core::move")
    /* stub */
}

__attribute__((weak)) bool cAIFSM::Core::createClusterStack(u32 size) {
    DDON_STUB("cAIFSM::Core::createClusterStack")
    return {};
}

void cAIFSM::Core::setStatus(u32 st) {
    u32 t0 = mStatus;
    mStatus = st;
    if (t0 != st) {
        if (mClusterStackBottom != 0) {
            u32 v0_0 = mClusterStackBottom;
            unsigned int i0_8 = 0;
            unsigned int i1_3;
            u32* v1_8;
            u32 v4_0;
            for (;;) {
                mpCurrentClusterStack = &mClusterStack[i0_8];
                cAIFSMNode* v1_9 = mClusterStack[i0_8].mpNode;
                if (v1_9->mProcessNum == 0) {
                    v4_0 = v0_0;
                } else {
                    i1_3 = 0;
                    v1_8 = &mClusterStack[i0_8].mCurrentProcessNo;
                    for (;;) {
                        *v1_8 = i1_3;
                        cAIFSMNodeProcess* t1 = v1_9->getProcess(i1_3);
                        if (t1->mpStatusChangeProcess != nullptr) {
                            t1->mpStatusChangeProcess->callProcessWithExamine(mpOwner->mpOwner, static_cast<MtObject*>(t1->mpParameter), static_cast<MtObject*>(this), true);
                        }
                        if ((i1_3 + 1u) < v1_9->mProcessNum) {
                            i1_3 += 1u;
                        } else {
                            break;
                        }
                    }
                    v4_0 = mClusterStackBottom;
                }
                if ((i0_8 + 1u) < v4_0) {
                    v0_0 = v4_0;
                    i0_8 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

static auto ddon_emit_0x01b6a810 __attribute__((used)) = &cAIFSM::Core::getStatus;

__attribute__((weak)) bool cAIFSM::Core::createClusterWorkList(u32 num) {
    DDON_STUB("cAIFSM::Core::createClusterWorkList")
    return {};
}

__attribute__((weak)) void cAIFSM::Core::createInfoFromResource(rAIFSM* pRes) {
    DDON_STUB("cAIFSM::Core::createInfoFromResource")
    /* stub */
}

__attribute__((weak)) bool cAIFSM::Core::checkTransition(cAIFSM::Core::ClusterDriveInfo* pInfo) {
    DDON_STUB("cAIFSM::Core::checkTransition")
    return {};
}

__attribute__((weak)) bool cAIFSM::Core::pushCluster(cAIFSMCluster* pCluster) {
    DDON_STUB("cAIFSM::Core::pushCluster")
    return {};
}

u32 cAIFSM::Core::getClusterWorkNum() {
    return mClusterWorkNum;
}

__attribute__((weak)) void cAIFSM::Core::setClusterWorkNum(u32) {
}

cAIFSM::Core::ClusterWork* cAIFSM::Core::getClusterWork(u32 index) {
    return &mClusterWorkList[index];
}

__attribute__((weak)) void cAIFSM::Core::setClusterWork(cAIFSM::Core::ClusterWork*, u32) {
}

inline cAIFSM::Core::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSM::Core::MyDTI cAIFSM::Core::DTI("cAIFSM::Core", &::MtObject::DTI, 280ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIFSM::Core::MyDTI::newInstance() const {
    DDON_STUB("cAIFSM::Core::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAIFSM::Core::ClusterDriveInfo::getDTI() const {
    return cAIFSM::Core::ClusterDriveInfo::DTI;
}

inline cAIFSM::Core::ClusterDriveInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSM::Core::ClusterDriveInfo::MyDTI cAIFSM::Core::ClusterDriveInfo::DTI("cAIFSM::Core::ClusterDriveInfo", &::cAIObject::DTI, 64ul, 0u, 0u);

MtObject* cAIFSM::Core::ClusterDriveInfo::MyDTI::newInstance() const {
    return new (16u) cAIFSM::Core::ClusterDriveInfo;
}

const MtDTI& cAIFSM::Core::ClusterWork::getDTI() const {
    return cAIFSM::Core::ClusterWork::DTI;
}

cAIFSM::Core::ClusterWork::~ClusterWork() {
    if (mTransitionOnceStateList != nullptr) {
        MtMemoryAllocator::getAllocator(cAIFSM::Core::ClusterWork::DTI)->memFree(static_cast<void*>(mTransitionOnceStateList));
    }
    mTransitionOnceStateList = nullptr;
    mTransitionOnceStateListLength = 0;
    mTransitionOnceStateNum = 0;
}

void cAIFSM::Core::ClusterWork::createProperty(MtPropertyList& s) {
    this->cAIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mTransitionOnceStateList", mTransitionOnceStateList, 33u, mTransitionOnceStateListLength);
    s << MtProperty(static_cast<MtObject*>(this), "mTransitionOnceStateNum", &mTransitionOnceStateNum, 1u, 0u);
}

MtUI* cAIFSM::Core::ClusterWork::createUI(MtProperty& prop) {
    return nullptr;
}

bool cAIFSM::Core::ClusterWork::setCluster(cAIFSMCluster* pCluster) {
    mpCluster = pCluster;
    if (pCluster != nullptr) {
        if (mTransitionOnceStateList != nullptr) {
            MtMemoryAllocator::getAllocator(cAIFSM::Core::ClusterWork::DTI)->memFree(static_cast<void*>(mTransitionOnceStateList));
            mTransitionOnceStateList = nullptr;
            mTransitionOnceStateListLength = 0;
            mTransitionOnceStateNum = 0;
            u32 onceNodeNum = pCluster->getNodeNumWithSetting(8u);
            if (onceNodeNum != 0) {
                if (mTransitionOnceStateList != nullptr) {
                    MtMemoryAllocator::getAllocator(cAIFSM::Core::ClusterWork::DTI)->memFree(static_cast<void*>(mTransitionOnceStateList));
                    mTransitionOnceStateList = nullptr;
                    mTransitionOnceStateListLength = 0;
                    mTransitionOnceStateNum = 0;
                    void* t0 = MtMemoryAllocator::getAllocator(cAIFSM::Core::ClusterWork::DTI)->memAlloc(static_cast<size_t>(onceNodeNum) * 4, 16u);
                    if ((mTransitionOnceStateList = static_cast<u32*>(t0)) != nullptr) {
                        memset(t0, 0, static_cast<size_t>(onceNodeNum) * 4);
                        mTransitionOnceStateListLength = onceNodeNum;
                        mTransitionOnceStateNum = 0;
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    mTransitionOnceStateList = nullptr;
                    mTransitionOnceStateListLength = 0;
                    mTransitionOnceStateNum = 0;
                    void* t0 = MtMemoryAllocator::getAllocator(cAIFSM::Core::ClusterWork::DTI)->memAlloc(static_cast<size_t>(onceNodeNum) * 4, 16u);
                    if ((mTransitionOnceStateList = static_cast<u32*>(t0)) != nullptr) {
                        memset(t0, 0, static_cast<size_t>(onceNodeNum) * 4);
                        mTransitionOnceStateListLength = onceNodeNum;
                        mTransitionOnceStateNum = 0;
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                return true;
            }
        } else {
            mTransitionOnceStateList = nullptr;
            mTransitionOnceStateListLength = 0;
            mTransitionOnceStateNum = 0;
            u32 onceNodeNum = pCluster->getNodeNumWithSetting(8u);
            if (onceNodeNum != 0) {
                if (mTransitionOnceStateList != nullptr) {
                    MtMemoryAllocator::getAllocator(cAIFSM::Core::ClusterWork::DTI)->memFree(static_cast<void*>(mTransitionOnceStateList));
                    mTransitionOnceStateList = nullptr;
                    mTransitionOnceStateListLength = 0;
                    mTransitionOnceStateNum = 0;
                    void* t0 = MtMemoryAllocator::getAllocator(cAIFSM::Core::ClusterWork::DTI)->memAlloc(static_cast<size_t>(onceNodeNum) * 4, 16u);
                    if ((mTransitionOnceStateList = static_cast<u32*>(t0)) != nullptr) {
                        memset(t0, 0, static_cast<size_t>(onceNodeNum) * 4);
                        mTransitionOnceStateListLength = onceNodeNum;
                        mTransitionOnceStateNum = 0;
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    mTransitionOnceStateList = nullptr;
                    mTransitionOnceStateListLength = 0;
                    mTransitionOnceStateNum = 0;
                    void* t0 = MtMemoryAllocator::getAllocator(cAIFSM::Core::ClusterWork::DTI)->memAlloc(static_cast<size_t>(onceNodeNum) * 4, 16u);
                    if ((mTransitionOnceStateList = static_cast<u32*>(t0)) != nullptr) {
                        memset(t0, 0, static_cast<size_t>(onceNodeNum) * 4);
                        mTransitionOnceStateListLength = onceNodeNum;
                        mTransitionOnceStateNum = 0;
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                return true;
            }
        }
    } else {
        return false;
    }
}

inline cAIFSM::Core::ClusterWork::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSM::Core::ClusterWork::MyDTI cAIFSM::Core::ClusterWork::DTI("cAIFSM::Core::ClusterWork", &::cAIObject::DTI, 32ul, 0u, 0u);

MtObject* cAIFSM::Core::ClusterWork::MyDTI::newInstance() const {
    return new (16u) cAIFSM::Core::ClusterWork;
}

const MtDTI& cAIFSM::Core::ClearTransitionFromAllOnceParam::getDTI() const {
    return cAIFSM::Core::ClearTransitionFromAllOnceParam::DTI;
}

void cAIFSM::Core::ClearTransitionFromAllOnceParam::copy(cAICopiableParameter* pParam) {
    mType = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pParam) + 8);
    mStateID = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pParam) + 12);
}

MtUI* cAIFSM::Core::ClearTransitionFromAllOnceParam::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

void cAIFSM::Core::ClearTransitionFromAllOnceParam::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStateID", &mStateID, 1u, 0u);
}

inline cAIFSM::Core::ClearTransitionFromAllOnceParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSM::Core::ClearTransitionFromAllOnceParam::MyDTI cAIFSM::Core::ClearTransitionFromAllOnceParam::DTI("cAIFSM::Core::ClearTransitionFromAllOnceParam", &::cAICopiableParameter::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIFSM::Core::ClearTransitionFromAllOnceParam::MyDTI::newInstance() const {
    void* t1 = MtMemoryAllocator::getAllocator(cAIFSM::Core::ClearTransitionFromAllOnceParam::DTI)->memAlloc(sizeof(cAIFSM::Core::ClearTransitionFromAllOnceParam), 16u, cAIFSM::Core::ClearTransitionFromAllOnceParam::DTI.mID);
    // workaround
    new (t1) cAIResource();
    cAIFSM::Core::ClearTransitionFromAllOnceParam* t2 = new (t1) cAIFSM::Core::ClearTransitionFromAllOnceParam(*static_cast<cAIFSM::Core::ClearTransitionFromAllOnceParam*>(t1));
    t2->mType = 0;
    t2->mStateID = 0;
    return t2;
}

const MtDTI& cAIFSMData::getDTI() const {
    return cAIFSMData::DTI;
}

__attribute__((noinline)) cAIFSMData::~cAIFSMData() {
    if (mpCore != nullptr) {
        if (mCoreNum != 0) {
            u32 v0_0 = mCoreNum;
            Core* * v0_1 = mpCore;
            for (unsigned int i0_3 = 0;;) {
                if (v0_1[i0_3] != nullptr) {
                    delete v0_1[i0_3];
                    if ((i0_3 + 1u) >= mCoreNum) {
                        break;
                    }
                    v0_0 = mCoreNum;
                } else {
                    if ((i0_3 + 1u) >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpCore;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMData::DTI)->memFree(static_cast<void*>(mpCore));
    }
    mCoreNum = 0;
    mpCore = nullptr;
    if (mStreamData != nullptr) {
        MtMemoryAllocator::getAllocator(cAIFSMData::DTI)->memFree(static_cast<void*>(mStreamData));
    }
    mStreamDataSize = 0;
    mStreamData = nullptr;
}

void cAIFSMData::createProperty(MtPropertyList& s) {
    this->cAIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIFree", &mIFree[0], 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), "mFFree", &mFFree[0], 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpCore", reinterpret_cast<MT_MFUNC>(&::cAIFSMData::getCore), reinterpret_cast<MT_MFUNC>(&::cAIFSMData::setCore), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSMData::getCoreNum), reinterpret_cast<MT_MFUNC>(&::cAIFSMData::setCoreNum));
}

cAIFSMData::Core* cAIFSMData::getCore(u32 index) const {
    if (mpCore != nullptr) {
        if (index < mCoreNum) {
            return mpCore[index];
        }
    }
    return nullptr;
}

static auto ddon_emit_0x01b6a820 __attribute__((used)) = &cAIFSMData::getCoreNum;

void cAIFSMData::setCoreNum(u32 num) {
    if (mpCore != nullptr) {
        if (mCoreNum != 0) {
            u32 v0_0 = mCoreNum;
            Core* * v0_1 = mpCore;
            for (unsigned int i0_3 = 0;;) {
                if (v0_1[i0_3] != nullptr) {
                    delete v0_1[i0_3];
                    if ((i0_3 + 1u) >= mCoreNum) {
                        break;
                    }
                    v0_0 = mCoreNum;
                } else {
                    if ((i0_3 + 1u) >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpCore;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMData::DTI)->memFree(static_cast<void*>(mpCore));
    }
    mCoreNum = 0;
    mpCore = nullptr;
    void* t0 = MtMemoryAllocator::getAllocator(cAIFSMData::DTI)->memAlloc(static_cast<size_t>(num) * 8, 16u);
    if ((mpCore = static_cast<Core* *>(t0)) != nullptr) {
        mCoreNum = num;
        memset(t0, 0, static_cast<size_t>(num) * 8);
    }
}

void cAIFSMData::setCore(cAIFSMData::Core* pCore, u32 index) {
    if (mpCore == nullptr) {
        return;
    }
    if (index < mCoreNum) {
        mpCore[index] = pCore;
    }
}

inline cAIFSMData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMData::MyDTI cAIFSMData::DTI("cAIFSMData", &::cAIObject::DTI, 104ul, 0u, 0u);

MtObject* cAIFSMData::MyDTI::newInstance() const {
    return new (16u) cAIFSMData;
}

const MtDTI& cAIFSMData::Core::getDTI() const {
    return cAIFSMData::Core::DTI;
}

__attribute__((noinline)) cAIFSMData::Core::~Core() {
    if (mpCluster != nullptr) {
        if (mClusterNum != 0) {
            u32 v0_0 = mClusterNum;
            Cluster* * v0_1 = mpCluster;
            for (unsigned int i0_3 = 0;;) {
                if (v0_1[i0_3] != nullptr) {
                    delete v0_1[i0_3];
                    if ((i0_3 + 1u) >= mClusterNum) {
                        break;
                    }
                    v0_0 = mClusterNum;
                } else {
                    if ((i0_3 + 1u) >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpCluster;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMData::Core::DTI)->memFree(static_cast<void*>(mpCluster));
    }
    mClusterNum = 0;
    mpCluster = nullptr;
    if (mpClusterLog != nullptr) {
        if (mClusterLogNum != 0) {
            u32 v3_0 = mClusterLogNum;
            ClusterLog* * v3_1 = mpClusterLog;
            for (unsigned int i3_3 = 0;;) {
                if (v3_1[i3_3] != nullptr) {
                    delete v3_1[i3_3];
                    if ((i3_3 + 1u) >= mClusterLogNum) {
                        break;
                    }
                    v3_0 = mClusterLogNum;
                } else {
                    if ((i3_3 + 1u) >= v3_0) {
                        break;
                    }
                }
                v3_1 = mpClusterLog;
                i3_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMData::Core::DTI)->memFree(static_cast<void*>(mpClusterLog));
    }
    mClusterLogNum = 0;
    mpClusterLog = nullptr;
}

void cAIFSMData::Core::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mResourceId", &mResourceId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIFree", &mIFree[0], 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), "mFFree", &mFFree[0], 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpCluster", reinterpret_cast<MT_MFUNC>(&::cAIFSMData::Core::getCluster), reinterpret_cast<MT_MFUNC>(&::cAIFSMData::Core::setCluster), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSMData::Core::getClusterNum), reinterpret_cast<MT_MFUNC>(&::cAIFSMData::Core::setClusterNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpClusterLog", reinterpret_cast<MT_MFUNC>(&::cAIFSMData::Core::getClusterLog), reinterpret_cast<MT_MFUNC>(&::cAIFSMData::Core::setClusterLog), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSMData::Core::getClusterLogNum), reinterpret_cast<MT_MFUNC>(&::cAIFSMData::Core::setClusterLogNum));
}

static auto ddon_emit_0x01b6a880 __attribute__((used)) = &cAIFSMData::Core::getClusterNum;

void cAIFSMData::Core::setClusterNum(u32 num) {
    if (mpCluster != nullptr) {
        if (mClusterNum != 0) {
            u32 v0_0 = mClusterNum;
            Cluster* * v0_1 = mpCluster;
            for (unsigned int i0_3 = 0;;) {
                if (v0_1[i0_3] != nullptr) {
                    delete v0_1[i0_3];
                    if ((i0_3 + 1u) >= mClusterNum) {
                        break;
                    }
                    v0_0 = mClusterNum;
                } else {
                    if ((i0_3 + 1u) >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpCluster;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMData::Core::DTI)->memFree(static_cast<void*>(mpCluster));
    }
    mClusterNum = 0;
    mpCluster = nullptr;
    void* t0 = MtMemoryAllocator::getAllocator(cAIFSMData::Core::DTI)->memAlloc(static_cast<size_t>(num) * 8, 16u);
    if ((mpCluster = static_cast<Cluster* *>(t0)) != nullptr) {
        mClusterNum = num;
        memset(t0, 0, static_cast<size_t>(num) * 8);
    }
}

cAIFSMData::Cluster* cAIFSMData::Core::getCluster(u32 index) const {
    if (mpCluster != nullptr) {
        if (index < mClusterNum) {
            return mpCluster[index];
        }
    }
    return nullptr;
}

void cAIFSMData::Core::setCluster(cAIFSMData::Cluster* pCluster, u32 index) {
    if (mpCluster == nullptr) {
        return;
    }
    if (index < mClusterNum) {
        mpCluster[index] = pCluster;
    }
}

__attribute__((weak)) bool cAIFSMData::Core::createClusterLogList(u32 num) {
    if (mpClusterLog != nullptr) {
        if (mClusterLogNum != 0) {
            u32 v0_0 = mClusterLogNum;
            ClusterLog* * v0_1 = mpClusterLog;
            for (unsigned int i0_3 = 0;;) {
                if (v0_1[i0_3] != nullptr) {
                    delete v0_1[i0_3];
                    if ((i0_3 + 1u) >= mClusterLogNum) {
                        break;
                    }
                    v0_0 = mClusterLogNum;
                } else {
                    if ((i0_3 + 1u) >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpClusterLog;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMData::Core::DTI)->memFree(static_cast<void*>(mpClusterLog));
    }
    mClusterLogNum = 0;
    mpClusterLog = nullptr;
    if (num != 0) {
        void* t0 = MtMemoryAllocator::getAllocator(cAIFSMData::Core::DTI)->memAlloc(static_cast<size_t>(num) * 8, 16u);
        if ((mpClusterLog = static_cast<ClusterLog* *>(t0)) != nullptr) {
            mClusterLogNum = num;
            memset(t0, 0, static_cast<size_t>(num) * 8);
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

static auto ddon_emit_0x01b6a890 __attribute__((used)) = &cAIFSMData::Core::getClusterLogNum;

static auto ddon_emit_0x01b6abc0 __attribute__((used)) = &cAIFSMData::Core::setClusterLogNum;

cAIFSMData::ClusterLog* cAIFSMData::Core::getClusterLog(u32 index) const {
    if (mpClusterLog != nullptr) {
        if (index < mClusterLogNum) {
            return mpClusterLog[index];
        }
    }
    return nullptr;
}

void cAIFSMData::Core::setClusterLog(cAIFSMData::ClusterLog* pCluster, u32 index) {
    if (mpClusterLog == nullptr) {
        return;
    }
    if (index < mClusterLogNum) {
        mpClusterLog[index] = pCluster;
    }
}

inline cAIFSMData::Core::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMData::Core::MyDTI cAIFSMData::Core::DTI("cAIFSMData::Core", &::MtObject::DTI, 112ul, 0u, 0u);

MtObject* cAIFSMData::Core::MyDTI::newInstance() const {
    return new (16u) cAIFSMData::Core;
}

const MtDTI& cAIFSMData::Cluster::getDTI() const {
    return cAIFSMData::Cluster::DTI;
}

void cAIFSMData::Cluster::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNextId", &mNextId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStatus", &mStatus, 0u, 0u);
}

MtUI* cAIFSMData::Cluster::createUI(MtProperty& prop) {
    return nullptr;
}

inline cAIFSMData::Cluster::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMData::Cluster::MyDTI cAIFSMData::Cluster::DTI("cAIFSMData::Cluster", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cAIFSMData::Cluster::MyDTI::newInstance() const {
    return new (16u) cAIFSMData::Cluster;
}

const MtDTI& cAIFSMData::ClusterLog::getDTI() const {
    return cAIFSMData::ClusterLog::DTI;
}

cAIFSMData::ClusterLog::~ClusterLog() {
    if (mTransitionOnceStateList != nullptr) {
        MtMemoryAllocator::getAllocator(cAIFSMData::ClusterLog::DTI)->memFree(static_cast<void*>(mTransitionOnceStateList));
    }
    mTransitionOnceStateNum = 0;
    mTransitionOnceStateList = nullptr;
}

void cAIFSMData::ClusterLog::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mClusterId", &mClusterId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mTransitionOnceStateList", reinterpret_cast<MT_MFUNC>(&::cAIFSMData::ClusterLog::getTransitionOnceState), reinterpret_cast<MT_MFUNC>(&::cAIFSMData::ClusterLog::setTransitionOnceState), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSMData::ClusterLog::getTransitionOnceStateNum), reinterpret_cast<MT_MFUNC>(&::cAIFSMData::ClusterLog::setTransitionOnceStateNum));
}

u32 cAIFSMData::ClusterLog::getTransitionOnceState(u32 index) {
    if (mTransitionOnceStateList != nullptr) {
        if (index < mTransitionOnceStateNum) {
            return mTransitionOnceStateList[index];
        }
    }
    return 0;
}

void cAIFSMData::ClusterLog::setTransitionOnceState(u32 id, u32 index) {
    if (mTransitionOnceStateList == nullptr) {
        return;
    }
    if (index < mTransitionOnceStateNum) {
        mTransitionOnceStateList[index] = id;
    }
}

static auto ddon_emit_0x01b6a8a0 __attribute__((used)) = &cAIFSMData::ClusterLog::getTransitionOnceStateNum;

void cAIFSMData::ClusterLog::setTransitionOnceStateNum(u32 num) {
    if (mTransitionOnceStateList != nullptr) {
        MtMemoryAllocator::getAllocator(cAIFSMData::ClusterLog::DTI)->memFree(static_cast<void*>(mTransitionOnceStateList));
    }
    mTransitionOnceStateNum = 0;
    mTransitionOnceStateList = nullptr;
    if (num == 0) {
        return;
    }
    void* t0 = MtMemoryAllocator::getAllocator(cAIFSMData::ClusterLog::DTI)->memAlloc(static_cast<size_t>(num) * 4, 16u);
    if ((mTransitionOnceStateList = static_cast<u32*>(t0)) == nullptr) {
        return;
    }
    mTransitionOnceStateNum = num;
    memset(t0, 0, static_cast<size_t>(num) * 4);
}

inline cAIFSMData::ClusterLog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMData::ClusterLog::MyDTI cAIFSMData::ClusterLog::DTI("cAIFSMData::ClusterLog", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cAIFSMData::ClusterLog::MyDTI::newInstance() const {
    return new (16u) cAIFSMData::ClusterLog;
}

const MtDTI& cAIFSMProcessContainer::getDTI() const {
    return cAIFSMProcessContainer::DTI;
}

void* cAIFSMProcessContainer::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAIFSMProcessContainer::DTI)->memAlloc(sz, align, cAIFSMProcessContainer::DTI.mID);
}

cAIFSMProcessContainer::~cAIFSMProcessContainer() {
    DDON_STUB("cAIFSMProcessContainer::~cAIFSMProcessContainer")
    /* stub */
}

__attribute__((weak)) void cAIFSMProcessContainer::setProcessFunc(const MtDTI* pFuncDTI, MT_CTSTR funcOwnerName, const MtDTI* pParamDTI, cAIUserProcessCallback::CALLBACK_FUNC pUpdateFunc, cAIUserProcessCallback::CALLBACK_FUNC pStateFunc, cAIUserProcessCallback::CALLBACK_FUNC pExitFunc, cAIUserProcessCallback::CALLBACK_FUNC pChangeFunc, cAIUserProcessCallback::CALLBACK_FUNC pExportFunc, cAIUserProcessCallback::CALLBACK_FUNC pImportFunc) {
    DDON_STUB("cAIFSMProcessContainer::setProcessFunc")
    /* stub */
}

inline cAIFSMProcessContainer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMProcessContainer::MyDTI cAIFSMProcessContainer::DTI("cAIFSMProcessContainer", &::cAIUserProcessContainer::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIFSMProcessContainer::MyDTI::newInstance() const {
    DDON_STUB("cAIFSMProcessContainer::MyDTI::newInstance")
    return nullptr;
}

