// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cDynamicBVHCollision.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtCollisionUtil.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "nCollision.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cDynamicBVHCollision::getDTI() const {
    return cDynamicBVHCollision::DTI;
}

void* cDynamicBVHCollision::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cDynamicBVHCollision::DTI)->memAlloc(sz, align, cDynamicBVHCollision::DTI.mID);
}

cDynamicBVHCollision::cDynamicBVHCollision() {
    DDON_STUB("cDynamicBVHCollision::cDynamicBVHCollision")
    /* stub */
}

__attribute__((noinline)) cDynamicBVHCollision::~cDynamicBVHCollision() {
    DDON_STUB("cDynamicBVHCollision::~cDynamicBVHCollision")
    /* stub */
}

MtUI* cDynamicBVHCollision::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cDynamicBVHCollision::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpRoot", reinterpret_cast<MtObject* *>(&mpRoot), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLeafNum", &mLeafNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpdateBackNum", &mUpdateBackNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNoUseNodeArray", static_cast<MtObject*>(&mNoUseNodeArray), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReservedNodeNoUseNum", &mReservedNodeNoUseNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReservedNodeNoUseMax", &mReservedNodeNoUseMax, 3u, 0u);
}

bool cDynamicBVHCollision::isEnableRoot() const {
    return mpRoot != nullptr;
}

__attribute__((weak)) cDynamicBVHCollision::Node* cDynamicBVHCollision::insertLeaf(const MtAABB& aabb, MtObject* pLeafObject) {
    DDON_STUB("cDynamicBVHCollision::insertLeaf")
    return nullptr;
}

__attribute__((weak)) void cDynamicBVHCollision::updateLeaf(const MtAABB& aabb, cDynamicBVHCollision::Node* pNode, cDynamicBVHCollision::UPDATE_LEVEL UpdateLV) {
    DDON_STUB("cDynamicBVHCollision::updateLeaf")
    /* stub */
}

void cDynamicBVHCollision::removeLeaf(cDynamicBVHCollision::Node* pRemoveNode) {
    removeLeaf(pRemoveNode, true);
}

void cDynamicBVHCollision::removeAll() {
    if (mReservedNodeNoUseNum == mReservedNodeNoUseMax) {
        if (mpRoot != nullptr) {
            delete mpRoot;
            mpRoot = nullptr;
        }
    } else {
        if (mpRoot != nullptr) {
            deleteTreeAllCore(mpRoot);
            mpRoot = nullptr;
        }
    }
    if (mNoUseNodeArray.mLength != 0) {
        u32 v0_0 = mNoUseNodeArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mNoUseNodeArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mNoUseNodeArray.mpArray[i0_3];
                v1_0 = mNoUseNodeArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNoUseNodeArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNoUseNodeArray.mpArray));
    }
    mNoUseNodeArray.mpArray = nullptr;
    mNoUseNodeArray.mBufsiz = 0;
    mNoUseNodeArray.mLength = 0;
    mLeafNum = 0;
}

void cDynamicBVHCollision::removeWorkBuffer() {
    if (mNoUseNodeArray.mLength != 0) {
        u32 v0_0 = mNoUseNodeArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mNoUseNodeArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mNoUseNodeArray.mpArray[i0_3];
                v1_0 = mNoUseNodeArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNoUseNodeArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNoUseNodeArray.mpArray));
    }
    mNoUseNodeArray.mpArray = nullptr;
    mNoUseNodeArray.mBufsiz = 0;
    mNoUseNodeArray.mLength = 0;
}

__attribute__((weak)) bool cDynamicBVHCollision::reserveNode(u32 ReserveNum) {
    DDON_STUB("cDynamicBVHCollision::reserveNode")
    return {};
}

void cDynamicBVHCollision::unregistAll() {
    unregistAllCore(mpRoot);
    mpRoot = nullptr;
}

u32 cDynamicBVHCollision::getInsertLeafNum() const {
    return mLeafNum;
}

__attribute__((weak)) u32 cDynamicBVHCollision::traverseByRecursive(MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, cDynamicBVHCollision::TRAVERSE_CALLBACK pCallbackFunc, void* pUserPtr, bool FlgOneHitEnd) {
    DDON_STUB("cDynamicBVHCollision::traverseByRecursive")
    return {};
}

__attribute__((weak)) u32 cDynamicBVHCollision::traverseByRecursiveConst(const MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, cDynamicBVHCollision::TRAVERSE_CALLBACK_CONST pCallbackFunc, const void* pUserPtr, bool FlgOneHitEnd) {
    DDON_STUB("cDynamicBVHCollision::traverseByRecursiveConst")
    return {};
}

__attribute__((weak)) u32 cDynamicBVHCollision::traverse(MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, cDynamicBVHCollision::TRAVERSE_CALLBACK pCallbackFunc, void* pUserPtr, bool FlgOneHitEnd, u32 ThreadIndex) {
    DDON_STUB("cDynamicBVHCollision::traverse")
    return {};
}

__attribute__((weak)) u32 cDynamicBVHCollision::traverseConst(const MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, cDynamicBVHCollision::TRAVERSE_CALLBACK_CONST pCallbackFunc, const void* pUserPtr, bool FlgOneHitEnd, u32 ThreadIndex) {
    DDON_STUB("cDynamicBVHCollision::traverseConst")
    return {};
}

void cDynamicBVHCollision::applyWorldOffset(const MtVector3& offset) {
    applyWorldOffsetCore(offset, mpRoot);
}

__attribute__((weak)) void cDynamicBVHCollision::applyWorldOffsetCore(const MtVector3& offset, cDynamicBVHCollision::Node* pNowNode) {
    for (Node* v0_3 = pNowNode;;) {
        if (v0_3 == nullptr) {
            break;
        } else {
            v0_3->mAABB.minpos.x = offset.x + v0_3->mAABB.minpos.x;
            v0_3->mAABB.minpos.y = offset.y + v0_3->mAABB.minpos.y;
            v0_3->mAABB.minpos.z = offset.z + v0_3->mAABB.minpos.z;
            v0_3->mAABB.maxpos.x = offset.x + v0_3->mAABB.maxpos.x;
            v0_3->mAABB.maxpos.y = offset.y + v0_3->mAABB.maxpos.y;
            v0_3->mAABB.maxpos.z = offset.z + v0_3->mAABB.maxpos.z;
            if (v0_3->mpChild[1] == nullptr) {
                break;
            } else {
                applyWorldOffsetCore(offset, reinterpret_cast<Node*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_3) + 16)));
                v0_3 = v0_3->mpChild[1];
            }
        }
    }
}

__attribute__((weak)) void cDynamicBVHCollision::insertLeaf(cDynamicBVHCollision::Node* pStartNode, cDynamicBVHCollision::Node* pInsertLeafNode) {
    DDON_STUB("cDynamicBVHCollision::insertLeaf")
    /* stub */
}

__attribute__((weak)) void cDynamicBVHCollision::removeLeaf(cDynamicBVHCollision::Node* pRemoveNode, bool FlgSplitStock) {
    DDON_STUB("cDynamicBVHCollision::removeLeaf")
    /* stub */
}

__attribute__((weak)) cDynamicBVHCollision::Node* cDynamicBVHCollision::createNewNodeForNode() {
    DDON_STUB("cDynamicBVHCollision::createNewNodeForNode")
    return nullptr;
}

__attribute__((weak)) void cDynamicBVHCollision::splitAndStockNode(cDynamicBVHCollision::Node* pNode) {
    if (pNode == nullptr) {
        return;
    }
    pNode->mpChild[1] = nullptr;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pNode) + 16) = 0;
    pNode->mpParent = nullptr;
    if (mReservedNodeNoUseMax != 0) {
        if (pNode >= mpReservedNodeArray) {
            if ((&mpReservedNodeArray[mReservedNodeNoUseMax - 1u]) < pNode) {
                if (mIsEnableSplitAndStock) {
                    u32 t0 = mNoUseNodeArray.mLength;
                    u32 t1 = mNoUseNodeArray.mBufsiz;
                    if (t0 < t1) {
                        mNoUseNodeArray.mLength = t0 + 1u;
                        mNoUseNodeArray.mpArray[t0] = static_cast<MtObject*>(pNode);
                    } else {
                        void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
                        memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
                        memcpy(t2, static_cast<const void*>(mNoUseNodeArray.mpArray), static_cast<size_t>(mNoUseNodeArray.mLength) * 8);
                        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNoUseNodeArray.mpArray));
                        mNoUseNodeArray.mpArray = static_cast<MtObject* *>(t2);
                        mNoUseNodeArray.mBufsiz = t1 + 32u;
                        u32 t3 = mNoUseNodeArray.mLength;
                        mNoUseNodeArray.mLength = t3 + 1u;
                        mNoUseNodeArray.mpArray[t3] = static_cast<MtObject*>(pNode);
                    }
                } else {
                    delete pNode;
                }
            } else {
                mppReservedNodeNoUseArray[mReservedNodeNoUseNum] = pNode;
                mReservedNodeNoUseNum = mReservedNodeNoUseNum + 1u;
            }
        } else {
            if (mIsEnableSplitAndStock) {
                u32 t0 = mNoUseNodeArray.mLength;
                u32 t1 = mNoUseNodeArray.mBufsiz;
                if (t0 < t1) {
                    mNoUseNodeArray.mLength = t0 + 1u;
                    mNoUseNodeArray.mpArray[t0] = static_cast<MtObject*>(pNode);
                } else {
                    void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
                    memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
                    memcpy(t2, static_cast<const void*>(mNoUseNodeArray.mpArray), static_cast<size_t>(mNoUseNodeArray.mLength) * 8);
                    MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNoUseNodeArray.mpArray));
                    mNoUseNodeArray.mpArray = static_cast<MtObject* *>(t2);
                    mNoUseNodeArray.mBufsiz = t1 + 32u;
                    u32 t3 = mNoUseNodeArray.mLength;
                    mNoUseNodeArray.mLength = t3 + 1u;
                    mNoUseNodeArray.mpArray[t3] = static_cast<MtObject*>(pNode);
                }
            } else {
                delete pNode;
            }
        }
    } else {
        if (mIsEnableSplitAndStock) {
            u32 t0 = mNoUseNodeArray.mLength;
            u32 t1 = mNoUseNodeArray.mBufsiz;
            if (t0 < t1) {
                mNoUseNodeArray.mLength = t0 + 1u;
                mNoUseNodeArray.mpArray[t0] = static_cast<MtObject*>(pNode);
            } else {
                void* t2 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t1 + 32u) * 8, 16u);
                memset(t2, 0, static_cast<size_t>(t1 + 32u) * 8);
                memcpy(t2, static_cast<const void*>(mNoUseNodeArray.mpArray), static_cast<size_t>(mNoUseNodeArray.mLength) * 8);
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNoUseNodeArray.mpArray));
                mNoUseNodeArray.mpArray = static_cast<MtObject* *>(t2);
                mNoUseNodeArray.mBufsiz = t1 + 32u;
                u32 t3 = mNoUseNodeArray.mLength;
                mNoUseNodeArray.mLength = t3 + 1u;
                mNoUseNodeArray.mpArray[t3] = static_cast<MtObject*>(pNode);
            }
        } else {
            delete pNode;
        }
    }
}

__attribute__((weak)) void cDynamicBVHCollision::unregistAllCore(cDynamicBVHCollision::Node* pNowNode) {
    if (pNowNode == nullptr) {
        return;
    }
    if (pNowNode->mpChild[1] != nullptr) {
        unregistAllCore(reinterpret_cast<Node*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pNowNode) + 16)));
        unregistAllCore(pNowNode->mpChild[1]);
    }
    splitAndStockNode(pNowNode);
}

__attribute__((weak)) void cDynamicBVHCollision::deleteTreeAllCore(cDynamicBVHCollision::Node* pNowNode) {
    if (pNowNode != nullptr) {
        for (Node* v0_0 = pNowNode;;) {
            unsigned long t0 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_0) + 16);
            Node* t1 = v0_0->mpChild[1];
            v0_0->mpChild[1] = nullptr;
            *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(v0_0) + 16) = 0;
            v0_0->mpParent = nullptr;
            if (mReservedNodeNoUseMax != 0) {
                if (v0_0 >= mpReservedNodeArray) {
                    if ((&mpReservedNodeArray[mReservedNodeNoUseMax - 1u]) < v0_0) {
                        delete v0_0;
                    }
                } else {
                    delete v0_0;
                }
            } else {
                delete v0_0;
            }
            if (t1 == nullptr) {
                break;
            } else {
                deleteTreeAllCore(reinterpret_cast<Node*>(t0));
                v0_0 = t1;
            }
        }
    }
}

__attribute__((weak)) void cDynamicBVHCollision::initializeDBVTSystemBuffer() {
    DDON_STUB("cDynamicBVHCollision::initializeDBVTSystemBuffer")
    /* stub */
}

__attribute__((weak)) void cDynamicBVHCollision::releaseDBVTSystemBuffer() {
    DDON_STUB("cDynamicBVHCollision::releaseDBVTSystemBuffer")
    /* stub */
}

__attribute__((weak)) void cDynamicBVHCollision::releaseDBVTSystemWorkBuffer() {
    DDON_STUB("cDynamicBVHCollision::releaseDBVTSystemWorkBuffer")
    /* stub */
}

inline cDynamicBVHCollision::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDynamicBVHCollision::MyDTI cDynamicBVHCollision::DTI("cDynamicBVHCollision", &::MtObject::DTI, 112ul, 0u, 0u);

u32 cDynamicBVHCollision::mTraverseStackNest[19];

cDynamicBVHCollision::cNodeStackArray* cDynamicBVHCollision::mpTraverseStackArrayRoot;

cDynamicBVHCollision::cNodeStackArray* cDynamicBVHCollision::mpTraverseStackArray[3][19];

__attribute__((weak)) MtObject* cDynamicBVHCollision::MyDTI::newInstance() const {
    DDON_STUB("cDynamicBVHCollision::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cDynamicBVHCollision::Node::getDTI() const {
    return cDynamicBVHCollision::Node::DTI;
}

cDynamicBVHCollision::Node::~Node() {
    DDON_STUB("cDynamicBVHCollision::Node::~Node")
    /* stub */
}

void cDynamicBVHCollision::Node::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpParent", reinterpret_cast<MtObject* *>(&mpParent), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpChild", reinterpret_cast<MtObject* *>(&(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 16))), 32u, 2u);
    s << MtProperty(static_cast<MtObject*>(this), "mAABB", &mAABB, 0u, 0u);
}

inline cDynamicBVHCollision::Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDynamicBVHCollision::Node::MyDTI cDynamicBVHCollision::Node::DTI("cDynamicBVHCollision::Node", &::nCollision::cAllocaterIntermediate::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cDynamicBVHCollision::Node::MyDTI::newInstance() const {
    cDynamicBVHCollision::Node* t1 = static_cast<cDynamicBVHCollision::Node*>(
        MtMemoryAllocator::getAllocator(cDynamicBVHCollision::Node::DTI)->memAlloc(sizeof(cDynamicBVHCollision::Node), 16u, cDynamicBVHCollision::Node::DTI.getID())
    );
    // workaround
    new (static_cast<void*>(t1)) cDynamicBVHCollision::Node(*t1);
    t1->mAABB = MtAABB::Empty;
    t1->mpChild[1] = nullptr;
    t1->mpChild[0] = nullptr;
    t1->mpParent = nullptr;
    return t1;
}

