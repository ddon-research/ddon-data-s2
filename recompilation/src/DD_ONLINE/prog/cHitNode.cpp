// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cHitNode.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cHitGeom.h"
#include "../../XFramework/cResource.h"
#include "cpObjCollision.h"
#include "../../XFramework/nCollisionNode.h"
#include "rAttackParam.h"
#include "rCollNode.h"
#include "../../XFramework/sCollision.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

u32 VsGroupAttr[12] = {
    1,
    2,
    3,
    8,
    0,
    32,
    32,
    128,
    1152,
    3,
    1024,
    2048,
};

const MtDTI& cHitNode::getDTI() const {
    return cHitNode::DTI;
}

void* cHitNode::operator new(size_t sz, u32 align) {
    return cHitNode::getAllocator()->memAlloc(sz, align, cHitNode::DTI.getID());
}

cHitNode::cHitNode() {
    mpCollNode = nullptr;
    mpCollIndex = nullptr;
    mpAttackParamRes = nullptr;
    mpCollNodeRes = nullptr;
    mpNode = nullptr;
    mpObjCollision = nullptr;
    mpAttackParam = new (16u) cAttackParam;
    mpOrgAttackParam = nullptr;
    mSeqNo = -1;
    mKillReq = false;
    mMotionSync = false;
    mIsActive = true;
    mUID = 0;
    mWmat.m[0].x = MtMatrix::Identity.m[0].x;
    mWmat.m[0].y = MtMatrix::Identity.m[0].y;
    mWmat.m[0].z = MtMatrix::Identity.m[0].z;
    mWmat.m[0].w = MtMatrix::Identity.m[0].w;
    mWmat.m[1].x = MtMatrix::Identity.m[1].x;
    mWmat.m[1].y = MtMatrix::Identity.m[1].y;
    mWmat.m[1].z = MtMatrix::Identity.m[1].z;
    mWmat.m[1].w = MtMatrix::Identity.m[1].w;
    mWmat.m[2].x = MtMatrix::Identity.m[2].x;
    mWmat.m[2].y = MtMatrix::Identity.m[2].y;
    mWmat.m[2].z = MtMatrix::Identity.m[2].z;
    mWmat.m[2].w = MtMatrix::Identity.m[2].w;
    mWmat.m[3].x = MtMatrix::Identity.m[3].x;
    mWmat.m[3].y = MtMatrix::Identity.m[3].y;
    mWmat.m[3].z = MtMatrix::Identity.m[3].z;
    mWmat.m[3].w = MtMatrix::Identity.m[3].w;
}

__attribute__((noinline)) cHitNode::~cHitNode() {
    if (mpCollNodeRes != nullptr) {
        mpCollNodeRes->release();
        mpCollNodeRes = nullptr;
    }
    if (mpAttackParamRes != nullptr) {
        mpAttackParamRes->release();
        mpAttackParamRes = nullptr;
    }
    if (mpNode != nullptr) {
        delete mpNode;
        mpNode = nullptr;
    }
    if (mpAttackParam != nullptr) {
        delete mpAttackParam;
        mpAttackParam = nullptr;
    }
    if (mGeomArray.mLength != 0) {
        u32 v0_0 = mGeomArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mGeomArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mGeomArray.mpArray[i0_3];
                v1_0 = mGeomArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mGeomArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGeomArray.mpArray));
    }
    mGeomArray.mpArray = nullptr;
    mGeomArray.mBufsiz = 0;
    mGeomArray.mLength = 0;
}

void cHitNode::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsActive", &mIsActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGeomArray", static_cast<MtObject*>(&mGeomArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCollIndex", reinterpret_cast<MtObject* *>(&mpCollIndex), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpCollNode", reinterpret_cast<MtObject* *>(&mpCollNode), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpAttackParam", reinterpret_cast<MtObject* *>(&mpAttackParam), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMotionSync", &mMotionSync, 0u, 0u);
}

cAttackParam* cHitNode::getAttackParamFromAttackNo(u32 no) const {
    if (mpAttackParamRes != nullptr) {
        if (no < mpAttackParamRes->getDataNum()) {
            return mpAttackParamRes->getData(no);
        }
    }
    return nullptr;
}

__attribute__((weak)) void cHitNode::setSCollisionNodeAttr(u32 attr) {
    DDON_STUB("cHitNode::setSCollisionNodeAttr")
    /* stub */
}

void cHitNode::setAttackParam(const cAttackParam* pAttackParam) {
    if (mpAttackParam == nullptr) {
        return;
    }
    if (pAttackParam == nullptr) {
        return;
    }
    mpAttackParam->copy(*pAttackParam);
}

void cHitNode::setAttackParamFromAttackNo(u32 no) {
    if (mpAttackParamRes == nullptr) {
        return;
    }
    if (mpAttackParam == nullptr) {
        return;
    }
    if (mpAttackParamRes->getDataNum() == 0) {
        return;
    }
    if (no < mpAttackParamRes->getDataNum()) {
        cAttackParam* pParam = mpAttackParamRes->getData(no);
        if (pParam != nullptr) {
            mpAttackParam->copy(*pParam);
        }
    }
}

__attribute__((weak)) void cHitNode::setAttackParamRes(rAttackParam* mpr) {
    DDON_STUB("cHitNode::setAttackParamRes")
    /* stub */
}

const MtSphere* cHitNode::getSphere(u32 index) const {
    if (mGeomArray.mpArray[index] != nullptr) {
        return static_cast<cHitGeom*>(mGeomArray.mpArray[index])->getSphere();
    } else {
        return nullptr;
    }
}

void cHitNode::setSphere(u32 index, const MtSphere& sphere) {
    if (mGeomArray.mpArray[index] == nullptr) {
        return;
    }
    static_cast<cHitGeom*>(mGeomArray.mpArray[index])->setSphere(sphere);
}

const MtCapsule* cHitNode::getCapsule(u32 index) const {
    if (mGeomArray.mpArray[index] != nullptr) {
        return static_cast<cHitGeom*>(mGeomArray.mpArray[index])->getCapsule();
    } else {
        return nullptr;
    }
}

void cHitNode::setCapsule(u32 index, const MtCapsule& capsule) {
    if (mGeomArray.mpArray[index] == nullptr) {
        return;
    }
    static_cast<cHitGeom*>(mGeomArray.mpArray[index])->setCapsule(capsule);
}

void cHitNode::updateNode() {
    if (mpObjCollision->getModel() != nullptr) {
        if (mpCollNode != nullptr) {
            setSCollisionNodeAttr(mpObjCollision->getModel()->replaceCollisionAttr(mpCollNode->getAttr(), mpCollNode));
            u32 v0_10 = mGeomArray.mLength;
            if (v0_10 != 0) {
                for (u32 i = 0;;) {
                    if (mGeomArray.mpArray[i] != nullptr) {
                        static_cast<cHitGeom*>(mGeomArray.mpArray[i])->updateGeom();
                    }
                    if (v0_10 != (i + 1u)) {
                        i = i + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

void cHitNode::resetHitNode() {
    if (mpAttackParam == nullptr) {
        return;
    }
    if (mpOrgAttackParam == nullptr) {
        return;
    }
    mpAttackParam->copy(*mpOrgAttackParam);
}

uDDOModel* cHitNode::getOwnerUnit() const {
    if (mpObjCollision != nullptr) {
        return mpObjCollision->getModel();
    } else {
        return nullptr;
    }
}

inline cHitNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cHitNode::MyDTI cHitNode::DTI("cHitNode", &::MtObject::DTI, 192ul, 0u, 0u);

MtObject* cHitNode::MyDTI::newInstance() const {
    return new (16u) cHitNode;
}

