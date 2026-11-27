// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpHeadCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "../../generated/shared/nDDOMath.h"
#include "rHeadCtrl.h"
#include "uCnsHeadCtrl.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpHeadCtrl::getDTI() const {
    return cpHeadCtrl::DTI;
}

void* cpHeadCtrl::operator new(size_t sz, u32 align) {
    return cpHeadCtrl::getAllocator()->memAlloc(sz, align, cpHeadCtrl::DTI.getID());
}

cpHeadCtrl::cpHeadCtrl() {
    mTargetPos.pad_ = 0.0f;
    mTargetPos.x = MtVector3::Zero.x;
    mTargetPos.y = MtVector3::Zero.y;
    mTargetPos.z = MtVector3::Zero.z;
    mpResource = nullptr;
    mAngleYOld = 0.0f;
    mPitch = 0.0f;
    mPitchOld = 0.0f;
    mTgtPitch = 0.0f;
    mAngleY = 0.0f;
    mTgtAngleY = 0.0f;
    mTargetPos.pad_ = 0.0f;
    mFlag = 0;
    mIsSleep = true;
    mAngleSpeedRate = 1.0f;
    mPitchSpeedRate = 1.0f;
    mpModel = nullptr;
    mAngleYMin = 0.0f;
    mAngleYMax = 0.0f;
    mAngleYDiff = 0.0f;
    mPitchMin = 0.0f;
    mPitchMax = 0.0f;
    mEnable = false;
}

__attribute__((noinline)) cpHeadCtrl::~cpHeadCtrl() {
    if (mCnsHeadCtrlArray.mLength != 0) {
        u32 v0_0 = mCnsHeadCtrlArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mCnsHeadCtrlArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                static_cast<uCnsHeadCtrl*>(mCnsHeadCtrlArray.mpArray[i0_3])->remove();
                v1_0 = mCnsHeadCtrlArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
        if (v1_0 != 0) {
            u32 v3_0 = v1_0;
            unsigned int i3_3 = 0;
            u32 v4_0;
            for (;;) {
                if (mCnsHeadCtrlArray.mpArray[i3_3] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    delete mCnsHeadCtrlArray.mpArray[i3_3];
                    v4_0 = mCnsHeadCtrlArray.mLength;
                }
                if ((i3_3 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mCnsHeadCtrlArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mCnsHeadCtrlArray.mpArray));
    }
    mCnsHeadCtrlArray.mpArray = nullptr;
    mCnsHeadCtrlArray.mBufsiz = 0;
    mCnsHeadCtrlArray.mLength = 0;
    if (mpResource != nullptr) {
        mpResource->release();
        mpResource = nullptr;
    }
}

void cpHeadCtrl::setup() {
    this->cpComponent::setup();
}

void cpHeadCtrl::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mTargetPos.x = offset.x + mTargetPos.x;
    mTargetPos.y = offset.y + mTargetPos.y;
    mTargetPos.z = offset.z + mTargetPos.z;
}

void cpHeadCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

__attribute__((weak)) void cpHeadCtrl::setupComponentPtr() {
}

__attribute__((weak)) void cpHeadCtrl::initHeadCtrl() {
    DDON_STUB("cpHeadCtrl::initHeadCtrl")
    /* stub */
}

__attribute__((weak)) void cpHeadCtrl::updateHeadCtrl() {
    DDON_STUB("cpHeadCtrl::updateHeadCtrl")
    /* stub */
}

__attribute__((weak)) void cpHeadCtrl::adjustYaw() {
    DDON_STUB("cpHeadCtrl::adjustYaw")
    /* stub */
}

__attribute__((weak)) void cpHeadCtrl::adjustPitch() {
    DDON_STUB("cpHeadCtrl::adjustPitch")
    /* stub */
}

void cpHeadCtrl::setResource(rHeadCtrl* pRes) {
    if (mpResource != nullptr) {
        mpResource->release();
        mpResource = nullptr;
    }
    if (pRes != nullptr) {
        mpResource = pRes;
        pRes->addRef();
    }
    initHeadCtrl();
}

void cpHeadCtrl::setTargetPos(const MtVector3& pos) {
    mTargetPos = pos;
}

inline cpHeadCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpHeadCtrl::MyDTI cpHeadCtrl::DTI("cpHeadCtrl", &::cpComponent::DTI, 208ul, 0u, 0u);

MtObject* cpHeadCtrl::MyDTI::newInstance() const {
    return new (16u) cpHeadCtrl;
}

template MtTypedArray<uCnsHeadCtrl>::~MtTypedArray();

