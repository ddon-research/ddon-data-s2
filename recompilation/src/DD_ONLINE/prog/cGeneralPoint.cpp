// Reconstructed from the game's DWARF debug information.
#include <new>
#include <sce_atomic.h>
#include "cGeneralPoint.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/uBaseModel.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static s32 mUniqueIDCounter;

const MtDTI& cGeneralPoint::getDTI() const {
    return cGeneralPoint::DTI;
}

inline void cGeneralPoint::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGeneralPoint::DTI)->memFree(p_addr);
}

cGeneralPoint::cGeneralPoint() {
    mUniqueID = sceAtomicAdd32Relaxed(&mUniqueIDCounter, 1) + 1;
    mPos = MtVector3::Zero;
    mAngle = MtVector3::AxisZ;
    mRadius = 0.0f;
    mJntNo = 255;
    mCategory = 0;
    mCategoryReq = 0;
    mObjectID = 0;
    mpOwner = nullptr;
    mKillReq = false;
    mIsRefEnable = true;
    mIsActive = true;
}

uBaseModel* cGeneralPoint::getBaseModelOwner() {
    MtObject* p_owner = mpOwner;
    MtObject* v2_0;
    if (p_owner == nullptr) {
        v2_0 = nullptr;
    } else {
        const MtDTI& t0 = p_owner->getDTI();
        MT_CTSTR v0_1 = uBaseModel::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = nullptr;
                    return static_cast<uBaseModel*>(v2_0);
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = p_owner;
    }
    return static_cast<uBaseModel*>(v2_0);
}

uDDOModel* cGeneralPoint::getDDOModelOwner() {
    MtObject* p_owner = mpOwner;
    MtObject* v2_0;
    if (p_owner == nullptr) {
        v2_0 = nullptr;
    } else {
        const MtDTI& t0 = p_owner->getDTI();
        MT_CTSTR v0_1 = uDDOModel::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = nullptr;
                    return static_cast<uDDOModel*>(v2_0);
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = p_owner;
    }
    return static_cast<uDDOModel*>(v2_0);
}

const uDDOModel* cGeneralPoint::getDDOModelOwner() const {
    MtObject* v0_2 = mpOwner;
    const MtDTI& t0 = v0_2->getDTI();
    MT_CTSTR v0_1 = uDDOModel::DTI.mName;
    if (v0_1 != t0.mName) {
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_0->mpParent == nullptr) {
                return nullptr;
            } else {
                if (v0_1 != v0_0->mpParent->mName) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return static_cast<const uDDOModel*>(v0_2);
}

void cGeneralPoint::updatePoint() {
    mCategory = mCategoryReq;
}

__attribute__((weak)) void cGeneralPoint::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("cGeneralPoint::applyWorldOffset")
    /* stub */
}

inline cGeneralPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGeneralPoint::MyDTI cGeneralPoint::DTI("cGeneralPoint", &::MtObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cGeneralPoint::MyDTI::newInstance() const {
    DDON_STUB("cGeneralPoint::MyDTI::newInstance")
    return nullptr;
}

