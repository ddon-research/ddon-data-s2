// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpMotionHistory.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpMotionHistory::getDTI() const {
    return cpMotionHistory::DTI;
}

void* cpMotionHistory::operator new(size_t sz, u32 align) {
    return cpMotionHistory::getAllocator()->memAlloc(sz, align, cpMotionHistory::DTI.getID());
}

cpMotionHistory::cpMotionHistory() {
    mpParentUnit = nullptr;
    mIsSetHistory = false;
    mBaseMotTypeStartNo = 0;
    mBlendCalcSpeed[2] = 0.0f;
    mBlendCalcSpeed[3] = 0.0f;
    mBlendCalcSpeed[0] = 0.0f;
    mBlendCalcSpeed[1] = 0.0f;
    mHistoryMotTypeStartNo = 4;
    mHistoryMotTypeNum = 4;
    mKeyFrameMax = 1.0f;
    u32 ix = 0;
    do {
        mBlendStartRate[ix] = 0.0f;
        mHistoryMotData[ix].motNo = 0xFFFF;
        ix += 1u;
    } while (ix < mHistoryMotTypeNum);
}

cpMotionHistory::~cpMotionHistory() {
}

void cpMotionHistory::setup() {
    this->cpComponent::setup();
}

MtUI* cpMotionHistory::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cpMotionHistory::move() {
    if (!mIsSetHistory) {
        return;
    }
    calcHistoryBlend();
}

__attribute__((weak)) void cpMotionHistory::calcHistoryBlend() {
    DDON_STUB("cpMotionHistory::calcHistoryBlend")
    /* stub */
}

void cpMotionHistory::setMotionHistory() {
    if (mpParentUnit != nullptr) {
        if (mIsSetHistory) {
            if (mpParentUnit->mBlendNum < (mHistoryMotTypeNum + mBaseMotTypeStartNo)) {
            } else {
                if (mpParentUnit->mBlendNum < (mHistoryMotTypeNum + mHistoryMotTypeStartNo)) {
                } else {
                    if (mHistoryMotTypeNum != 0) {
                        for (u32 ix = 0; ix <= 3u; ix += 1u) {
                            mHistoryMotData[ix].motNo = 0xFFFF;
                            u32 t0 = mBaseMotTypeStartNo;
                            if ((ix + t0) > 7u) {
                                break;
                            } else {
                                uDDOModel* t1 = mpParentUnit;
                                if (t1->mMotion[ix + t0].mMotionNo != 0xFFFF) {
                                    mHistoryMotData[ix].motNo = t1->mMotion[ix + t0].mMotionNo;
                                    mHistoryMotData[ix].frame = t1->mMotion[ix + t0].getFrame();
                                    mHistoryMotData[ix].frameMax = t1->mMotion[ix + t0].getFrameMax();
                                    mHistoryMotData[ix].speed = t1->mMotion[ix + t0].mSpeed;
                                    mHistoryMotData[ix].attr = t1->mMotion[ix + t0].getAttr();
                                    mHistoryMotData[ix].blendRate = t1->mMotion[ix + t0].getBlendRate();
                                }
                                if ((ix + 1u) >= mHistoryMotTypeNum) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void cpMotionHistory::setHistoryBlendMotion() {
    DDON_STUB("cpMotionHistory::setHistoryBlendMotion")
    /* stub */
}

void cpMotionHistory::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpParentUnit == nullptr) {
        return;
    }
    if (mpParentUnit->isEnable()) {
        return;
    }
    mpParentUnit = nullptr;
}

void cpMotionHistory::setHistoryMotType(u32 baseStart, u32 historyStart, u32 typeNum) {
    mBaseMotTypeStartNo = baseStart;
    mHistoryMotTypeStartNo = historyStart;
    mHistoryMotTypeNum = (typeNum <= 4u) ? typeNum : 4u;
}

inline cpMotionHistory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpMotionHistory::MyDTI cpMotionHistory::DTI("cpMotionHistory", &::cpComponent::DTI, 240ul, 0u, 0u);

__attribute__((weak)) MtObject* cpMotionHistory::MyDTI::newInstance() const {
    DDON_STUB("cpMotionHistory::MyDTI::newInstance")
    return nullptr;
}

