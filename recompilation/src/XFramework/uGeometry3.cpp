// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGeometry3.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "nCollisionNode.h"
#include "rGeometry3.h"
#include "sCollision.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uGeometry3::usage() {
}

const MtDTI& uGeometry3::getDTI() const {
    return uGeometry3::DTI;
}

uGeometry3::~uGeometry3() {
    if (mpRGeometry != nullptr) {
        mpRGeometry->release();
        mpRGeometry = nullptr;
    }
    if (mpColliderNode == nullptr) {
        return;
    }
    delete mpColliderNode;
    mpColliderNode = nullptr;
}

void uGeometry3::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASS, "AttachModel", reinterpret_cast<MT_MFUNC>(&::uGeometry3::getAttachModel), reinterpret_cast<MT_MFUNC>(&::uGeometry3::registAttachModel), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpRGeometry", "resource", reinterpret_cast<MT_MFUNC>(&::uGeometry3::getResourceForUI), reinterpret_cast<MT_MFUNC>(&::uGeometry3::setResourceForUI), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mGeometryGroup", static_cast<MtObject*>(&mGeometryGroup), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpColliderNode", reinterpret_cast<MtObject* *>(&mpColliderNode), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlgUseGroupID", &mFlgUseGroupID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUserPtrUseMode", &mUserPtrUseMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mUseGroupID", reinterpret_cast<MT_MFUNC>(&::uGeometry3::getUseGroupID), reinterpret_cast<MT_MFUNC>(&::uGeometry3::setUseGroupID), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mUseGroupIndex", reinterpret_cast<MT_MFUNC>(&::uGeometry3::getUseGroupIndex), reinterpret_cast<MT_MFUNC>(&::uGeometry3::setUseGroupIndex), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "RestoreGeometry", static_cast<MT_MFUNC>(&::uGeometry3::restoreGeometryFromResource), 10u);
}

__attribute__((weak)) void uGeometry3::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uGeometry3::applyWorldOffset")
    /* stub */
}

MT_CTSTR uGeometry3::getName() {
    return "uGeometry3";
}

void uGeometry3::setup() {
    this->cUnit::setup();
}

void uGeometry3::move() {
    mGeometryGroup.nCollision::cGeometryJointGroup::move();
    setGeometryToColliderNode(mpColliderNode);
}

__attribute__((weak)) void uGeometry3::sync() {
}

__attribute__((weak)) void uGeometry3::moveAfter() {
}

__attribute__((weak)) void uGeometry3::draw(cDraw* pdraw) {
}

void uGeometry3::registAttachModel(uModel* pAttachModel) {
    mGeometryGroup.setAttachModel(pAttachModel);
}

uModel* uGeometry3::getAttachModel() const {
    return static_cast<const nCollision::cGeometryJointGroup&>(mGeometryGroup).getAttachModel();
}

__attribute__((weak)) bool uGeometry3::loadResource(rGeometry3* pRGeometry) {
    DDON_STUB("uGeometry3::loadResource")
    return {};
}

void uGeometry3::restoreGeometryFromResource() {
    if (mpRGeometry == nullptr) {
        return;
    }
    if (mFlgUseGroupID) {
        nCollision::cGeometryJointGroup* t0 = mpRGeometry->getGeometryGroupFromID(mUseGroupID);
        if (t0 != nullptr) {
            uModel* pAttachModel = mGeometryGroup.getAttachModel();
            mGeometryGroup.nCollision::cGeometryJointGroup::copyEx(*t0, true, true, true);
            mGeometryGroup.setAttachModel(pAttachModel);
        }
    } else {
        nCollision::cGeometryJointGroup* t1 = mpRGeometry->getGeometryGroupFromIndex(mUseGroupIndex);
        if (t1 != nullptr) {
            uModel* pAttachModel = mGeometryGroup.getAttachModel();
            mGeometryGroup.nCollision::cGeometryJointGroup::copyEx(*t1, true, true, true);
            mGeometryGroup.setAttachModel(pAttachModel);
        }
    }
}

u32 uGeometry3::getUseGroupID() const {
    return mUseGroupID;
}

void uGeometry3::setUseGroupID(u32 NewTargetGroupID) {
    if (mUseGroupID == NewTargetGroupID) {
        return;
    }
    if (mpRGeometry == nullptr) {
        return;
    }
    if (mpRGeometry->getGeometryGroupFromID(NewTargetGroupID) == nullptr) {
        return;
    }
    mUseGroupID = NewTargetGroupID;
    if (!mFlgUseGroupID) {
        return;
    }
    if (mpRGeometry == nullptr) {
        return;
    }
    nCollision::cGeometryJointGroup* t0 = mpRGeometry->getGeometryGroupFromID(NewTargetGroupID);
    if (t0 == nullptr) {
        return;
    }
    uModel* t1 = mGeometryGroup.getAttachModel();
    mGeometryGroup.nCollision::cGeometryJointGroup::copyEx(*t0, true, true, true);
    mGeometryGroup.setAttachModel(t1);
}

u32 uGeometry3::getUseGroupIndex() const {
    return mUseGroupIndex;
}

void uGeometry3::setUseGroupIndex(u32 NewGroupIndex) {
    if (mUseGroupIndex == NewGroupIndex) {
        return;
    }
    if (mpRGeometry == nullptr) {
        return;
    }
    if (mpRGeometry->getGeometryGroupFromIndex(NewGroupIndex) == nullptr) {
        return;
    }
    mUseGroupIndex = NewGroupIndex;
    if (mFlgUseGroupID) {
        return;
    }
    if (mpRGeometry == nullptr) {
        return;
    }
    nCollision::cGeometryJointGroup* t0 = mpRGeometry->getGeometryGroupFromIndex(NewGroupIndex);
    if (t0 == nullptr) {
        return;
    }
    uModel* t1 = mGeometryGroup.getAttachModel();
    mGeometryGroup.nCollision::cGeometryJointGroup::copyEx(*t0, true, true, true);
    mGeometryGroup.setAttachModel(t1);
}

__attribute__((weak)) void uGeometry3::setGeometryToColliderNode(sCollision::Node* pTargetNode) {
    if (pTargetNode == nullptr) {
        return;
    } else {
        const u32 SrcGeometryNum = mGeometryGroup.mGeometryArray.mLength;
        if (SrcGeometryNum < pTargetNode->mGeometryArray.mLength) {
            u32 v0_3 = pTargetNode->mGeometryArray.mLength - SrcGeometryNum;
            for (u32 v0_4 = pTargetNode->mGeometryArray.mLength;;) {
                pTargetNode->eraseGeometry(v0_4 - 1u, true);
                if ((v0_3 - 1u) == 0) {
                    break;
                } else {
                    v0_3 += 0xFFFFFFFFu;
                    v0_4 = pTargetNode->mGeometryArray.mLength;
                }
            }
        }
    }
    if (mGeometryGroup.mGeometryArray.mLength != 0) {
        for (unsigned int i2_3 = 0;;) {
            nCollision::cGeometry* t0 = mGeometryGroup.getGeometryClass(i2_3);
            if (t0 != nullptr) {
                MtGeomConvex* t1 = mGeometryGroup.getAttachGeometryFromIndex(i2_3);
                if (t1 != nullptr) {
                    if (pTargetNode->setGeometry(t1, i2_3, false) != 0xFFFFFFFFu) {
                        nCollision::cGeometry* t2 = pTargetNode->getGeometryClass(i2_3);
                        if (t2 != nullptr) {
                            if (mUserPtrUseMode == 2) {
                                static_cast<nCollision::cGeometryExpansion*>(t2)->setUserPtr(mGeometryGroup.getGeometryFreeObject(i2_3));
                            } else {
                                if (mUserPtrUseMode == 0) {
                                    static_cast<nCollision::cGeometryExpansion*>(t2)->setUserPtr(static_cast<MtObject*>(t0));
                                }
                            }
                        }
                    }
                }
            }
            if (mGeometryGroup.mGeometryArray.mLength != (i2_3 + 1u)) {
                i2_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mUserPtrUseMode == 2) {
        pTargetNode->setUserDataPtr(mGeometryGroup.getFreeObject());
    } else {
        if (mUserPtrUseMode == 0) {
            pTargetNode->setUserDataPtr(static_cast<MtObject*>(&mGeometryGroup));
        }
    }
}

void uGeometry3::setResourceForUI(cResource* pRGeometry) {
    loadResource(static_cast<rGeometry3*>(pRGeometry));
}

cResource* uGeometry3::getResourceForUI() {
    return mpRGeometry;
}

inline uGeometry3::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGeometry3::MyDTI uGeometry3::DTI("uGeometry3", &::cUnit::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* uGeometry3::MyDTI::newInstance() const {
    DDON_STUB("uGeometry3::MyDTI::newInstance")
    return nullptr;
}

