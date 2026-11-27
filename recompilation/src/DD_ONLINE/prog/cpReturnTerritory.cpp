// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpReturnTerritory.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "../../XFramework/sMain.h"
#include "uControl.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpReturnTerritory::getDTI() const {
    return cpReturnTerritory::DTI;
}

void* cpReturnTerritory::operator new(size_t sz, u32 align) {
    return cpReturnTerritory::getAllocator()->memAlloc(sz, align, cpReturnTerritory::DTI.getID());
}

cpReturnTerritory::cpReturnTerritory() {
    mpModel = nullptr;
    mIsIntoReturn = false;
    mReturnTerritoryLimitTime = 1200.0f;
    mReturnTerritoryTimer = 0.0f;
    mHomePoint.x = MtVector3::Zero.x;
    mHomePoint.y = MtVector3::Zero.y;
    mHomePoint.z = MtVector3::Zero.z;
    mHomePoint.pad_ = 0.0f;
    mHomeRange = 700.0f;
}

cpReturnTerritory::~cpReturnTerritory() {
}

void cpReturnTerritory::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

void cpReturnTerritory::setup() {
    this->cpComponent::setup();
    mpModel = static_cast<uDDOModel*>(getOwner());
}

void cpReturnTerritory::move() {
    if (!mIsIntoReturn) {
        return;
    }
    mReturnTerritoryTimer = sMain::getInstance()->mDeltaTime + mReturnTerritoryTimer;
    if (mReturnTerritoryTimer > mReturnTerritoryLimitTime) {
        mReturnTerritoryTimer = mReturnTerritoryLimitTime;
        mIsIntoReturn = false;
    }
}

void cpReturnTerritory::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

void cpReturnTerritory::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mHomePoint.x = offset.x + mHomePoint.x;
    mHomePoint.y = offset.y + mHomePoint.y;
    mHomePoint.z = offset.z + mHomePoint.z;
}

void cpReturnTerritory::setHomePoint() {
    uDDOModel* t0 = mpModel;
    uControl* pCtrl = t0->getCtrl();
    if (pCtrl != nullptr) {
        unsigned int t1 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pCtrl) + 16);
        if (pCtrl->isEnable()) {
            MtVector3 frame56(pCtrl->getSetPos());
            f32 t2 = frame56.x;
            f32 t3 = frame56.y;
            f32 t4 = frame56.z;
            mHomePoint.x = t2;
            mHomePoint.y = t3;
            mHomePoint.z = t4;
            mHomePoint.pad_ = 0.0f;
        } else {
            f32 t5 = t0->mPos.x;
            f32 t6 = t0->mPos.y;
            f32 t7 = t0->mPos.z;
            mHomePoint.x = t5;
            mHomePoint.y = t6;
            mHomePoint.z = t7;
            mHomePoint.pad_ = 0.0f;
        }
    } else {
        f32 t5 = t0->mPos.x;
        f32 t6 = t0->mPos.y;
        f32 t7 = t0->mPos.z;
        mHomePoint.x = t5;
        mHomePoint.y = t6;
        mHomePoint.z = t7;
        mHomePoint.pad_ = 0.0f;
    }
}

f32 cpReturnTerritory::referenceLimitTimer() {
    return 1200.0f;
}

__attribute__((weak)) bool cpReturnTerritory::isArrivalHomePoint() {
    DDON_STUB("cpReturnTerritory::isArrivalHomePoint")
    return {};
}

inline cpReturnTerritory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpReturnTerritory::MyDTI cpReturnTerritory::DTI("cpReturnTerritory", &::cpComponent::DTI, 144ul, 0u, 0u);

MtObject* cpReturnTerritory::MyDTI::newInstance() const {
    return new (16u) cpReturnTerritory;
}

