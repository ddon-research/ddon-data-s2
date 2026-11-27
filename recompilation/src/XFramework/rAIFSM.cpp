// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rAIFSM.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "../MT/MtString.h"
#include "cAIObject.h"
#include "cAIUserProcess.h"
#include "cResource.h"
#include "nAI.h"
#include "rAIConditionTree.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAIFSMCluster::getDTI() const {
    return cAIFSMCluster::DTI;
}

cAIFSMCluster::~cAIFSMCluster() {
    if (mpNodeList != nullptr) {
        if (mNodeNum != 0) {
            u32 v0_0 = mNodeNum;
            cAIFSMNode* * v0_1 = mpNodeList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpNodeList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mNodeNum) {
                            break;
                        }
                        v0_0 = mNodeNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpNodeList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMCluster::DTI)->memFree(static_cast<void*>(mpNodeList));
    }
    mpNodeList = nullptr;
    mNodeNum = 0;
}

void cAIFSMCluster::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOwnerNodeUniqueId", &mOwnerNodeUniqueId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInitialStateId", &mInitialStateId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpNodeList", reinterpret_cast<MT_MFUNC>(&::cAIFSMCluster::getNode), reinterpret_cast<MT_MFUNC>(&::cAIFSMCluster::setNode), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSMCluster::getNodeNum), reinterpret_cast<MT_MFUNC>(&::cAIFSMCluster::setNodeNum));
}

void cAIFSMCluster::setup() {
    u32 i = 0;
    if (mNodeNum != 0) {
        do {
            mpNodeList[i]->setup();
            i += 1u;
        } while (i < mNodeNum);
    }
}

__attribute__((weak)) void cAIFSMCluster::copy(cAIFSMCluster* pSource) {
    DDON_STUB("cAIFSMCluster::copy")
    /* stub */
}

__attribute__((weak)) bool cAIFSMCluster::createNodeList(u32 num) {
    if (mpNodeList != nullptr) {
        if (mNodeNum != 0) {
            u32 v0_0 = mNodeNum;
            cAIFSMNode* * v0_1 = mpNodeList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpNodeList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mNodeNum) {
                            break;
                        }
                        v0_0 = mNodeNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpNodeList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMCluster::DTI)->memFree(static_cast<void*>(mpNodeList));
    }
    mpNodeList = nullptr;
    mNodeNum = 0;
    void* t0 = MtMemoryAllocator::getAllocator(cAIFSMCluster::DTI)->memAlloc(static_cast<size_t>(num) * 8, 16u);
    if ((mpNodeList = static_cast<cAIFSMNode* *>(t0)) != nullptr) {
        mNodeNum = num;
        memset(t0, 0, static_cast<size_t>(num) * 8);
        return true;
    } else {
        return false;
    }
}

static auto ddon_emit_0x01b93740 __attribute__((used)) = &cAIFSMCluster::setNodeNum;

static auto ddon_emit_0x01b93730 __attribute__((used)) = &cAIFSMCluster::getNodeNum;

__attribute__((weak)) u32 cAIFSMCluster::getNodeNumWithSetting(u32 setting) {
    DDON_STUB("cAIFSMCluster::getNodeNumWithSetting")
    return {};
}

void cAIFSMCluster::setNode(cAIFSMNode* pNode, u32 index) {
    if (mpNodeList == nullptr) {
        return;
    }
    if (index < mNodeNum) {
        mpNodeList[index] = pNode;
    }
}

cAIFSMNode* cAIFSMCluster::getNode(u32 index) {
    if (mpNodeList != nullptr) {
        if (index < mNodeNum) {
            return mpNodeList[index];
        }
    }
    return nullptr;
}

cAIFSMNode* cAIFSMCluster::searchNode(u32 id) {
    if (mNodeNum != 0) {
        u32 i = 0;
        do {
            if (mpNodeList[i]->mId == id) {
                return mpNodeList[i];
            }
            i += 1u;
        } while (i < mNodeNum);
    }
    return nullptr;
}

inline cAIFSMCluster::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMCluster::MyDTI cAIFSMCluster::DTI("cAIFSMCluster", &::cAIResource::DTI, 32ul, 0u, 0u);

MtObject* cAIFSMCluster::MyDTI::newInstance() const {
    return new (16u) cAIFSMCluster;
}

const MtDTI& cAIFSMLink::getDTI() const {
    return cAIFSMLink::DTI;
}

void cAIFSMLink::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mDestinationNodeId", &mDestinationNodeId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mExistCondition", &mExistCondition, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConditionId", &mConditionId, 0u, 0u);
}

void cAIFSMLink::copy(cAIFSMLink* pSource) {
    mDestinationNodeId = pSource->mDestinationNodeId;
    mExistCondition = pSource->mExistCondition;
    mConditionId = pSource->mConditionId;
}

inline cAIFSMLink::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMLink::MyDTI cAIFSMLink::DTI("cAIFSMLink", &::cAIResource::DTI, 24ul, 0u, 0u);

MtObject* cAIFSMLink::MyDTI::newInstance() const {
    return new (16u) cAIFSMLink;
}

const MtDTI& cAIFSMNode::getDTI() const {
    return cAIFSMNode::DTI;
}

__attribute__((noinline)) cAIFSMNode::~cAIFSMNode() {
    if (mpLinkList != nullptr) {
        if (mLinkNum != 0) {
            u32 v0_0 = mLinkNum;
            cAIFSMLink* * v0_1 = mpLinkList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpLinkList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mLinkNum) {
                            break;
                        }
                        v0_0 = mLinkNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpLinkList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMNode::DTI)->memFree(static_cast<void*>(mpLinkList));
    }
    mLinkNum = 0;
    mpLinkList = nullptr;
    if (mpSubCluster != nullptr) {
        delete mpSubCluster;
    }
    mpSubCluster = nullptr;
    if (mpProcessList != nullptr) {
        if (mProcessNum != 0) {
            u32 v3_0 = mProcessNum;
            cAIFSMNodeProcess* * v3_1 = mpProcessList;
            for (unsigned int i3_3 = 1;;) {
                if (v3_1 != nullptr) {
                    if (v3_1[i3_3 - 1u] != nullptr) {
                        delete v3_1[i3_3 - 1u];
                        mpProcessList[i3_3 - 1u] = nullptr;
                        if (i3_3 >= mProcessNum) {
                            break;
                        }
                        v3_0 = mProcessNum;
                    } else {
                        if (i3_3 >= v3_0) {
                            break;
                        }
                    }
                } else {
                    if (i3_3 >= v3_0) {
                        break;
                    }
                }
                v3_1 = mpProcessList;
                i3_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMNode::DTI)->memFree(static_cast<void*>(mpProcessList));
    }
    mProcessNum = 0;
    mpProcessList = nullptr;
}

void cAIFSMNode::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUniqueId", &mUniqueId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOwnerId", &mOwnerId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpSubCluster", reinterpret_cast<MtObject* *>(&mpSubCluster), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpLinkList", reinterpret_cast<MT_MFUNC>(&::cAIFSMNode::getLink), reinterpret_cast<MT_MFUNC>(&::cAIFSMNode::setLink), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSMNode::getLinkNum), reinterpret_cast<MT_MFUNC>(&::cAIFSMNode::setLinkNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpProcessList", reinterpret_cast<MT_MFUNC>(&::cAIFSMNode::getProcess), reinterpret_cast<MT_MFUNC>(&::cAIFSMNode::setProcess), 160u, reinterpret_cast<MT_MFUNC>(&::cAIFSMNode::getProcessNum), reinterpret_cast<MT_MFUNC>(&::cAIFSMNode::setProcessNum));
    s << MtProperty(static_cast<MtObject*>(this), "mUIPos", &this->mUIPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColorType", &mColorType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSetting", &mSetting, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUserAttribute", &mUserAttribute, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mExistConditionTrainsitionFromAll", &mExistConditionTrainsitionFromAll, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConditionTrainsitionFromAllId", &mConditionTrainsitionFromAllId, 0u, 0u);
}

void cAIFSMNode::setup() {
    if (mProcessNum == 0) {
        if (mpSubCluster != nullptr) {
            mpSubCluster->setup();
        }
        return;
    }
    u32 i = 0;
    do {
        mpProcessList[i]->cAIFSMNodeProcess::setup();
        i += 1u;
    } while (i < mProcessNum);
    if (mpSubCluster != nullptr) {
        mpSubCluster->setup();
    }
}

__attribute__((weak)) void cAIFSMNode::copy(cAIFSMNode* pSource) {
    DDON_STUB("cAIFSMNode::copy")
    /* stub */
}

__attribute__((weak)) bool cAIFSMNode::createLinkList(u32 num) {
    if (mpLinkList != nullptr) {
        if (mLinkNum != 0) {
            u32 v0_0 = mLinkNum;
            cAIFSMLink* * v0_1 = mpLinkList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpLinkList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mLinkNum) {
                            break;
                        }
                        v0_0 = mLinkNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpLinkList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMNode::DTI)->memFree(static_cast<void*>(mpLinkList));
    }
    mLinkNum = 0;
    mpLinkList = nullptr;
    if (num != 0) {
        void* t0 = MtMemoryAllocator::getAllocator(cAIFSMNode::DTI)->memAlloc(static_cast<size_t>(num) * 8, 16u);
        if ((mpLinkList = static_cast<cAIFSMLink* *>(t0)) != nullptr) {
            mLinkNum = num;
            memset(t0, 0, static_cast<size_t>(num) * 8);
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

static auto ddon_emit_0x01b936f0 __attribute__((used)) = &cAIFSMNode::setLinkNum;

static auto ddon_emit_0x01b936e0 __attribute__((used)) = &cAIFSMNode::getLinkNum;

void cAIFSMNode::setLink(cAIFSMLink* pLink, u32 index) {
    if (mpLinkList == nullptr) {
        return;
    }
    if (index < mLinkNum) {
        mpLinkList[index] = pLink;
    }
}

cAIFSMLink* cAIFSMNode::getLink(u32 index) {
    if (mpLinkList != nullptr) {
        if (index < mLinkNum) {
            return mpLinkList[index];
        }
    }
    return nullptr;
}

__attribute__((weak)) bool cAIFSMNode::createProcessList(u32 num) {
    if (mpProcessList != nullptr) {
        if (mProcessNum != 0) {
            u32 v0_0 = mProcessNum;
            cAIFSMNodeProcess* * v0_1 = mpProcessList;
            for (unsigned int i0_3 = 1;;) {
                if (v0_1 != nullptr) {
                    if (v0_1[i0_3 - 1u] != nullptr) {
                        delete v0_1[i0_3 - 1u];
                        mpProcessList[i0_3 - 1u] = nullptr;
                        if (i0_3 >= mProcessNum) {
                            break;
                        }
                        v0_0 = mProcessNum;
                    } else {
                        if (i0_3 >= v0_0) {
                            break;
                        }
                    }
                } else {
                    if (i0_3 >= v0_0) {
                        break;
                    }
                }
                v0_1 = mpProcessList;
                i0_3 += 1u;
            }
        }
        MtMemoryAllocator::getAllocator(cAIFSMNode::DTI)->memFree(static_cast<void*>(mpProcessList));
    }
    mProcessNum = 0;
    mpProcessList = nullptr;
    if (num != 0) {
        void* t0 = MtMemoryAllocator::getAllocator(cAIFSMNode::DTI)->memAlloc(static_cast<size_t>(num) * 8, 16u);
        if ((mpProcessList = static_cast<cAIFSMNodeProcess* *>(t0)) != nullptr) {
            mProcessNum = num;
            memset(t0, 0, static_cast<size_t>(num) * 8);
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

static auto ddon_emit_0x01b93710 __attribute__((used)) = &cAIFSMNode::setProcessNum;

static auto ddon_emit_0x01b93700 __attribute__((used)) = &cAIFSMNode::getProcessNum;

void cAIFSMNode::setProcess(cAIFSMNodeProcess* pProcess, u32 index) {
    if (mpProcessList == nullptr) {
        return;
    }
    if (index < mProcessNum) {
        mpProcessList[index] = pProcess;
    }
}

cAIFSMNodeProcess* cAIFSMNode::getProcess(u32 index) {
    if (mpProcessList != nullptr) {
        if (index < mProcessNum) {
            return mpProcessList[index];
        }
    }
    return nullptr;
}

inline cAIFSMNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMNode::MyDTI cAIFSMNode::DTI("cAIFSMNode", &::cAIResource::DTI, 80ul, 0u, 0u);

MtObject* cAIFSMNode::MyDTI::newInstance() const {
    return new (16u) cAIFSMNode;
}

const MtDTI& cAIFSMNodeProcess::getDTI() const {
    return cAIFSMNodeProcess::DTI;
}

__attribute__((noinline)) cAIFSMNodeProcess::~cAIFSMNodeProcess() {
    delete mpParameter;
    mpParameter = nullptr;
}

void cAIFSMNodeProcess::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mContainerName", &mContainerName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCategoryName", &mCategoryName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpParameter", reinterpret_cast<MtObject* *>(&mpParameter), 0u, 0u);
}

__attribute__((weak)) void cAIFSMNodeProcess::setup() {
    cAIUserProcessContainer* pContainer = getProcessContainer();
    if (pContainer != nullptr) {
        mpUpdateProcess = pContainer->searchProcess("update");
        mpStateProcess = pContainer->searchProcess("state");
        mpExitProcess = pContainer->searchProcess("exit");
        mpStatusChangeProcess = pContainer->searchProcess("statuschange");
        mpExportProcess = pContainer->searchProcess("export");
        mpImportProcess = pContainer->searchProcess("import");
    }
    if (mpParameter != nullptr) {
        MtPropertyList s;
        mpParameter->createProperty(s);
        for (MtProperty* pp = s.begin(); pp != nullptr; pp = pp->getNext()) {
            if (pp->getType() == MtProperty::TYPE_CLASS || pp->getType() == MtProperty::TYPE_CLASSREF) {
                MtObject* pClass = pp->getClass();
                if (pClass != nullptr && pClass->getDTI().getID() == nAI::EnumProp::DTI.getID()) {
                    nAI::EnumProp* pEnum = static_cast<nAI::EnumProp*>(pClass);
                    pEnum->open();
                }
            }
        }
    }
}

__attribute__((weak)) void cAIFSMNodeProcess::copy(cAIFSMNodeProcess* pProcess) {
    DDON_STUB("cAIFSMNodeProcess::copy")
    /* stub */
}

inline cAIFSMNodeProcess::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIFSMNodeProcess::MyDTI cAIFSMNodeProcess::DTI("cAIFSMNodeProcess", &::cAIUserProcessReference::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIFSMNodeProcess::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cAIFSMNodeProcess::DTI)->memAlloc(sizeof(cAIFSMNodeProcess), 16u, cAIFSMNodeProcess::DTI.getID())) cAIFSMNodeProcess(nullptr);
}

const MtDTI& rAIFSM::getDTI() const {
    return rAIFSM::DTI;
}

__attribute__((noinline)) rAIFSM::~rAIFSM() {
        delete mpRootCluster;
        mpRootCluster = nullptr;
        if (mpConditionTree) {
            mpConditionTree->release();
            mpConditionTree = nullptr;
        }
}

MT_CTSTR rAIFSM::getExt() const {
    return "fsm";
}

bool rAIFSM::load(MtStream& in) {
    MtSerializer sz(65536);
    if (sz.deserializeBinary(in, static_cast<u16>(2), static_cast<MtObject*>(this), MtSerializer::MODE_STATE) != nullptr) {
        setup();
        return true;
    } else {
        return false;
    }
}

void rAIFSM::clear() {
    if (mpRootCluster != nullptr) {
        delete mpRootCluster;
    }
    mpRootCluster = nullptr;
    if (mpConditionTree == nullptr) {
        return;
    }
    mpConditionTree->release();
    mpConditionTree = nullptr;
}

void rAIFSM::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mOwnerObjectName", &mOwnerObjectName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRootCluster", reinterpret_cast<MtObject* *>(&mpRootCluster), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpConditionTree", reinterpret_cast<MtObject* *>(&mpConditionTree), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFSMAttribute", &mFSMAttribute, 0u, 0u);
}

void rAIFSM::setup() {
    if (mpRootCluster == nullptr) {
        return;
    }
    mpRootCluster->setup();
}

__attribute__((weak)) MT_CTSTR rAIFSM::getName() {
    DDON_STUB("rAIFSM::getName")
    return {};
}

u32 rAIFSM::getHierarchyDepth(MtArray* pClusterList) {
    u32 level = 0;
    getHierarchyDepth(mpRootCluster, level, pClusterList);
    return level;
}

__attribute__((weak)) void rAIFSM::getHierarchyDepth(cAIFSMCluster* pCluster, u32& level, MtArray* pClusterList) {
    DDON_STUB("rAIFSM::getHierarchyDepth")
    /* stub */
}

inline rAIFSM::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIFSM::MyDTI rAIFSM::DTI("rAIFSM", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rAIFSM::MyDTI::newInstance() const {
    return new (16u) rAIFSM;
}

