// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cAI.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cAIObject.h"
#include "cAITask.h"

inline cAITreeBase::Node::Node() {
    mpObjectList = nullptr;
    mNumberOfObject = 0;
}

inline void* cAITreeBase::Node::operator new[](size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(DTI)->memAlloc(sz, align, DTI.getID());
}

inline void cAITreeBase::Node::operator delete[](void* p_addr) {
    MtMemoryAllocator::getAllocator(DTI)->memFree(p_addr);
}

inline void cAIQuadTree::deleteTempRegion() {
    if (mpTempRegion) {
        MtMemoryAllocator::getAllocator(cAIQuadTree::DTI)->memFree(mpTempRegion);
        mpTempRegion = nullptr;
    }
}

inline void cAITreeBase::Node::ObjectList::operator delete[](void* padr) {
    MtMemoryAllocator::getAllocator(cAITreeBase::DTI)->memFree(padr);
}

inline void cAITreeBase::Node::removeAll() {
    if (mpObjectList) {
        for (u32 t1 = 0; t1 < mNumberOfObject; ++t1) {
            mpObjectList[t1].mpObj = nullptr;
        }
        delete[] mpObjectList;
        mNumberOfObject = 0;
    }
}
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAIAStar::getDTI() const {
    return cAIAStar::DTI;
}

inline void cAIAStar::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIAStar::DTI)->memFree(p_addr);
}

cAIAStar::cAIAStar() {
    DDON_STUB("cAIAStar::cAIAStar")
    /* stub */
}

__attribute__((noinline)) cAIAStar::~cAIAStar() {
    DDON_STUB("cAIAStar::~cAIAStar")
    /* stub */
}

void cAIAStar::createProperty(MtPropertyList& s) {
    this->cAITask::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mSecurityCost", &mSecurityCost, 0u, 0u);
}

MtUI* cAIAStar::createUI(MtProperty& prop) {
    return this->cAITask::createUI(prop);
}

__attribute__((weak)) void cAIAStar::createJobList(cAITaskJobPrimList& list) {
    DDON_STUB("cAIAStar::createJobList")
    /* stub */
}

MtObject* cAIAStar::getResult(u32 index, bool f) {
    if (index < mNumberOfAStar) {
        if (mpResult[index].mpNode != nullptr) {
            if (f) {
                return mpResult[index].mpNode->mpCurrent;
            } else {
                return mpResult[index].mpNode;
            }
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

cAIAStar::AStarResult* cAIAStar::getResult_Address() {
    return mpResult;
}

__attribute__((weak)) bool cAIAStar::areaInitialize(cAIGraph::Node* startNode, cAIGraph::Node* endNode, cAIGraph::Area* root) {
    DDON_STUB("cAIAStar::areaInitialize")
    return {};
}

__attribute__((weak)) bool cAIAStar::nodeInitialize(cAIGraph::Node* startNode, cAIGraph::Node* endNode, u32 state, bool callback) {
    DDON_STUB("cAIAStar::nodeInitialize")
    return {};
}

__attribute__((weak)) u32 cAIAStar::search() {
    DDON_STUB("cAIAStar::search")
    return {};
}

void cAIAStar::searchJob() {
    u32 state = search();
    if (state != 16) {
        if (state == 2) {
            doneTask();
        }
    } else {
        doneTask();
    }
}

__attribute__((weak)) bool cAIAStar::AreaDecision(cAIGraph::Node* startNode, cAIGraph::Node* endNode) {
    DDON_STUB("cAIAStar::AreaDecision")
    return {};
}

inline cAIAStar::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIAStar::MyDTI cAIAStar::DTI("cAIAStar", &::cAIGraph::DTI, 464ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIAStar::MyDTI::newInstance() const {
    DDON_STUB("cAIAStar::MyDTI::newInstance")
    return nullptr;
}

cAIAStar::AStarResult::~AStarResult() {
}

cAIAStar::OpenList::~OpenList() {
    if (mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(cAIGraph::DTI)->memFree(static_cast<void*>(mpArray));
    }
    mBufsiz = 0;
    mLength = 0;
    mpArray = nullptr;
}

const MtDTI& cAIGraph::getDTI() const {
    return cAIGraph::DTI;
}

void* cAIGraph::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAIGraph::DTI)->memAlloc(sz, align, cAIGraph::DTI.mID);
}

inline void cAIGraph::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIGraph::DTI)->memFree(p_addr);
}

cAIGraph::cAIGraph() {
    mDeleteNode = false;
    mDeleteArea = false;
    mNumberOfArea = 0;
    mNumberOfAreaChild = 0;
    mNumberOfAreaLink = 0;
    mAddID = 0;
    mNumberOfNode = 0;
    mNumberOfLink = 0;
    mpNode = nullptr;
    mpAreaLink = nullptr;
    mpAreaChild = nullptr;
    mpArea = nullptr;
    mpLink = nullptr;
}

__attribute__((noinline)) cAIGraph::~cAIGraph() {
    DDON_STUB("cAIGraph::~cAIGraph")
    /* stub */
}

void cAIGraph::createProperty(MtPropertyList& s) {
    this->cAITask::createProperty(s);
}

__attribute__((weak)) void cAIGraph::createGraph(cAIGraph::NODE_LINK_FUNC func, MtObject* obj) {
    DDON_STUB("cAIGraph::createGraph")
    /* stub */
}

__attribute__((weak)) void cAIGraph::createGraph(cAIGraph::NODE_LINK_FUNC func, cAIGraph::NODE_AREA_FUNC afunc, MtObject* obj, MtObject* aobj) {
    DDON_STUB("cAIGraph::createGraph")
    /* stub */
}

__attribute__((weak)) void cAIGraph::setSize(u32 num) {
    DDON_STUB("cAIGraph::setSize")
    /* stub */
}

void cAIGraph::setData(MtObject* obj, u32 index) {
    if (mDeleteNode) {
        if (mpNode[index].mpCurrent != nullptr) {
            delete mpNode[index].mpCurrent;
            Node* t0 = mpNode;
            t0[index].mpCurrent = obj;
            t0[index].mID = static_cast<unsigned short>(index);
            t0[index].mpParent = this;
        } else {
            Node* t0 = mpNode;
            t0[index].mpCurrent = obj;
            t0[index].mID = static_cast<unsigned short>(index);
            t0[index].mpParent = this;
        }
    } else {
        Node* t0 = mpNode;
        t0[index].mpCurrent = obj;
        t0[index].mID = static_cast<unsigned short>(index);
        t0[index].mpParent = this;
    }
}

__attribute__((weak)) void cAIGraph::setLinkSize(u32 num) {
    DDON_STUB("cAIGraph::setLinkSize")
    /* stub */
}

__attribute__((weak)) void cAIGraph::setAreaSize(u32 num) {
    DDON_STUB("cAIGraph::setAreaSize")
    /* stub */
}

void cAIGraph::setAreaData(MtObject* obj, u32 index) {
    if (mDeleteArea) {
        if (mpArea[index].mpCurrent != nullptr) {
            delete mpArea[index].mpCurrent;
            Area* t0 = mpArea;
            t0[index].mpCurrent = obj;
            t0[index].mID = static_cast<unsigned short>(index);
            t0[index].mpParent = this;
        } else {
            Area* t0 = mpArea;
            t0[index].mpCurrent = obj;
            t0[index].mID = static_cast<unsigned short>(index);
            t0[index].mpParent = this;
        }
    } else {
        Area* t0 = mpArea;
        t0[index].mpCurrent = obj;
        t0[index].mID = static_cast<unsigned short>(index);
        t0[index].mpParent = this;
    }
}

__attribute__((weak)) void cAIGraph::setAreaChildSize(u32 size) {
    DDON_STUB("cAIGraph::setAreaChildSize")
    /* stub */
}

__attribute__((weak)) void cAIGraph::setAreaLinkSize(u32 size) {
    DDON_STUB("cAIGraph::setAreaLinkSize")
    /* stub */
}

void cAIGraph::insert(cAIGraph::Node* pNode, cAIGraph::Link* addLink) {
    Link* v0_0;
    if (pNode->mpLink == nullptr) {
        pNode->mpLink = addLink;
        pNode->mNumberOfLink = static_cast<unsigned char>(pNode->mNumberOfLink + 1);
        return;
    } else {
        v0_0 = pNode->mpLink;
    }
    for (;;) {
        if (v0_0->mpNext != nullptr) {
            v0_0 = v0_0->mpNext;
        } else {
            break;
        }
    }
    v0_0->mpNext = addLink;
    pNode->mNumberOfLink = static_cast<unsigned char>(pNode->mNumberOfLink + 1);
}

void cAIGraph::remove(cAIGraph::Node* pNode, cAIGraph::Link* removeLink) {
    if (removeLink != pNode->mpLink) {
        Link* v0_1 = pNode->mpLink;
        for (;;) {
            if (v0_1 == nullptr) {
                return;
            } else {
                if (removeLink != v0_1->mpNext) {
                    v0_1 = v0_1->mpNext;
                } else {
                    break;
                }
            }
        }
        v0_1->mpNext = removeLink->mpNext;
    } else {
        pNode->mpLink = removeLink->mpNext;
    }
    removeLink->mpNext = nullptr;
    pNode->mNumberOfLink = static_cast<unsigned char>(pNode->mNumberOfLink + 255);
}

inline cAIGraph::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIGraph::MyDTI cAIGraph::DTI("cAIGraph", &::cAITask::DTI, 208ul, 0u, 0u);

MtObject* cAIGraph::MyDTI::newInstance() const {
    return new (16u) cAIGraph;
}

const MtDTI& cAIGraph::Node::getDTI() const {
    return cAIGraph::Node::DTI;
}

inline void* cAIGraph::Node::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAIGraph::Node::DTI)->memAlloc(sz, align, cAIGraph::Node::DTI.mID);
}

inline void cAIGraph::Node::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIGraph::Node::DTI)->memFree(p_addr);
}

cAIGraph::Node::~Node() {
    if (!mAutoDeleteLink) {
        return;
    }
    if (mpLink == nullptr) {
        return;
    }
    Link* e = mpLink;
    do {
        mpLink = e->mpNext;
        e->mpNext = nullptr;
        e->mpCurrent = nullptr;
        MtMemoryAllocator::getAllocator(cAIGraph::DTI)->memFree(static_cast<void*>(e));
        e = mpLink;
    } while (e != nullptr);
}

void cAIGraph::Node::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mID", &mID, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNumberOfLink", &mNumberOfLink, 1u, 0u);
}

inline cAIGraph::Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIGraph::Node::MyDTI cAIGraph::Node::DTI("cAIGraph::Node", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cAIGraph::Node::MyDTI::newInstance() const {
    return new (16u) cAIGraph::Node;
}

const MtDTI& cAIGraph::Area::getDTI() const {
    return cAIGraph::Area::DTI;
}

inline void cAIGraph::Area::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIGraph::Area::DTI)->memFree(p_addr);
}

cAIGraph::Area::~Area() {
    DDON_STUB("cAIGraph::Area::~Area")
    /* stub */
}

inline cAIGraph::Area::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIGraph::Area::MyDTI cAIGraph::Area::DTI("cAIGraph::Area", &::cAIGraph::Node::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIGraph::Area::MyDTI::newInstance() const {
    DDON_STUB("cAIGraph::Area::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAIQuadTree::getDTI() const {
    return cAIQuadTree::DTI;
}

void* cAIQuadTree::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAIQuadTree::DTI)->memAlloc(sz, align, cAIQuadTree::DTI.mID);
}

inline void cAIQuadTree::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAIQuadTree::DTI)->memFree(p_addr);
}

__attribute__((noinline)) cAIQuadTree::cAIQuadTree() {
        mPos = MtVector3::Zero;
        mXZ = MtVector3::Zero;
        mMultiple = false;
        mpTempRegion = nullptr;
}

__attribute__((noinline)) cAIQuadTree::~cAIQuadTree() {
    deleteTempRegion();
}

__attribute__((weak)) void cAIQuadTree::createNode(const MtAABB& aabb, u32 nest, bool multiple) {
    DDON_STUB("cAIQuadTree::createNode")
    /* stub */
}

__attribute__((weak)) void cAIQuadTree::createNode(const MtAABB& aabb, u32 nest, u32 num, bool multiple) {
    mpNode = new (16) Node[num];
    mNumberOfNode = num;
    mNest = static_cast<u8>(nest);
    mAxisPartition = 1;
    for (u32 i = 0; i < nest - 1; ++i) {
        mAxisPartition *= 2;
    }
    mPos = aabb.minpos;
    mXZ = aabb.maxpos - aabb.minpos;
    mMultiple = multiple;
}

__attribute__((weak)) cAITreeBase::Node* cAIQuadTree::getNode(const MtVector3& pos, u32 nest) {
    DDON_STUB("cAIQuadTree::getNode")
    return nullptr;
}

__attribute__((weak)) MtAABB cAIQuadTree::getRegion() {
        MtAABB aabb;
        aabb.minpos = mPos;
        aabb.maxpos = mPos + mXZ;
        return aabb;
}

inline cAIQuadTree::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIQuadTree::MyDTI cAIQuadTree::DTI("cAIQuadTree", &::cAITreeBase::DTI, 208ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIQuadTree::MyDTI::newInstance() const {
    DDON_STUB("cAIQuadTree::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cAITreeBase::getDTI() const {
    return cAITreeBase::DTI;
}

inline void* cAITreeBase::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cAITreeBase::DTI)->memAlloc(sz, align, cAITreeBase::DTI.mID);
}

cAITreeBase::~cAITreeBase() {
    if (mpNode) delete[] mpNode;
}

inline cAITreeBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAITreeBase::MyDTI cAITreeBase::DTI("cAITreeBase", &::cAITask::DTI, 160ul, 0u, 0u);

MtObject* cAITreeBase::MyDTI::newInstance() const {
    return new (16u) cAITreeBase;
}

const MtDTI& cAITreeBase::Node::getDTI() const {
    return cAITreeBase::Node::DTI;
}

inline void cAITreeBase::Node::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cAITreeBase::Node::DTI)->memFree(p_addr);
}

cAITreeBase::Node::~Node() {
    removeAll();
}

inline cAITreeBase::Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAITreeBase::Node::MyDTI cAITreeBase::Node::DTI("cAITreeBase::Node", &::MtObject::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cAITreeBase::Node::MyDTI::newInstance() const {
    DDON_STUB("cAITreeBase::Node::MyDTI::newInstance")
    return nullptr;
}

