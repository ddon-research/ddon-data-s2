// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpSequenceCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cDelegate.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "../../generated/rPawnAIAction/nSequence.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpSequenceCtrl::getDTI() const {
    return cpSequenceCtrl::DTI;
}

void* cpSequenceCtrl::operator new(size_t sz, u32 align) {
    return cpSequenceCtrl::getAllocator()->memAlloc(sz, align, cpSequenceCtrl::DTI.getID());
}

cpSequenceCtrl::cpSequenceCtrl() {
    DDON_STUB("cpSequenceCtrl::cpSequenceCtrl")
    /* stub */
}

cpSequenceCtrl::~cpSequenceCtrl() {
    DDON_STUB("cpSequenceCtrl::~cpSequenceCtrl")
    /* stub */
}

void cpSequenceCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

__attribute__((weak)) void cpSequenceCtrl::setup() {
    DDON_STUB("cpSequenceCtrl::setup")
    /* stub */
}

void cpSequenceCtrl::move() {
    if (mActive) {
        if (mpModel != nullptr) {
            unsigned int i0_1 = 0;
            uDDOModel* v1_0;
            u32 v1_1;
            s32 v1_2;
            unsigned int v1_7;
            for (;;) {
                if (mSeqCnt[i0_1].mActive) {
                    if (static_cast<int>(mpModel->mMotion[mSeqCnt[i0_1].mBlend].mFrame) >= mSeqCnt[i0_1].mFrame) {
                        v1_0 = mpModel;
                        v1_1 = mSeqCnt[i0_1].mBlend;
                        v1_2 = mSeqCnt[i0_1].mFrame;
                        v1_7 = static_cast<int>(mpModel->mMotion[mSeqCnt[i0_1].mBlend].mFrame);
                        for (;;) {
                            u32 t0 = v1_0->mMotion[v1_1].calcSequence(mSeqCnt[i0_1].mPage, v1_2, v1_2);
                            if (((static_cast<unsigned long>(t0) >> static_cast<unsigned long>(mSeqCnt[i0_1].mBit & 31u)) & 1ul) != 0) {
                                mSeqCnt[i0_1].mCount = mSeqCnt[i0_1].mCount + 1;
                            }
                            s32 t1 = mSeqCnt[i0_1].mFrame;
                            mSeqCnt[i0_1].mFrame = t1 + 1;
                            if (t1 >= static_cast<int>(v1_7)) {
                                break;
                            } else {
                                v1_0 = mpModel;
                                v1_1 = mSeqCnt[i0_1].mBlend;
                                v1_2 = t1 + 1;
                            }
                        }
                    }
                }
                if ((i0_1 + 1u) != 10) {
                    i0_1 = i0_1 + 1u;
                } else {
                    break;
                }
            }
        }
    }
}

void cpSequenceCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

__attribute__((weak)) void cpSequenceCtrl::callbackSetMotion(u32 blend, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr) {
    DDON_STUB("cpSequenceCtrl::callbackSetMotion")
    /* stub */
}

void cpSequenceCtrl::callbackAfterUpdateMotion() {
    updateSequence();
}

void cpSequenceCtrl::createProperty(MtPropertyList& s) {
    this->cpComponent::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "callbackSequenceTrigger", &callbackSequenceTrigger, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "callbackSequenceRelease", &callbackSequenceRelease, 0u, 0u);
}

__attribute__((weak)) u32 cpSequenceCtrl::getSequence(u32 page, MOT_TYPE s) {
    DDON_STUB("cpSequenceCtrl::getSequence")
    return {};
}

__attribute__((weak)) u32 cpSequenceCtrl::getSequenceTrg(u32 page, MOT_TYPE s) {
    DDON_STUB("cpSequenceCtrl::getSequenceTrg")
    return {};
}

__attribute__((weak)) u32 cpSequenceCtrl::getSequenceRel(u32 page, MOT_TYPE s) {
    DDON_STUB("cpSequenceCtrl::getSequenceRel")
    return {};
}

__attribute__((weak)) bool cpSequenceCtrl::checkSequence(u32 bit, u32 page, MOT_TYPE s) {
        if (page <= 3 && static_cast<u32>(s) <= 7) {
            return (mMotSeqNew[static_cast<u32>(s)][page] & (1 << bit)) != 0;
        }
        return false;
}

void cpSequenceCtrl::setupSequenceCallback(nSequence::SEQ_CALLBACK_NO no, cpSequenceCtrl::CHECK_TYPE check_type, MOT_TYPE blend, u32 page, u32 top, u32 bottom) {
    if (static_cast<unsigned int>(no) <= 9) {
        mTrgRange[no].mCheckType = check_type;
        mTrgRange[no].mBlend = static_cast<u32>(blend);
        mTrgRange[no].mPage = page;
        mTrgRange[no].mTop = top;
        mTrgRange[no].mBottom = bottom;
    }
}

void cpSequenceCtrl::setupSequenceCount(s32 no, bool active, MOT_TYPE blend, u32 page, u32 bit) {
    if (static_cast<unsigned int>(no) <= 9) {
        mSeqCnt[no].mActive = active;
        mSeqCnt[no].mBlend = static_cast<u32>(blend);
        mSeqCnt[no].mPage = page;
        mSeqCnt[no].mBit = bit;
    }
}

s32 cpSequenceCtrl::getSequenceCount(s32 no) {
    if (static_cast<unsigned int>(no) <= 9) {
        if (mSeqCnt[no].mActive) {
            return mSeqCnt[no].mCount;
        }
    }
    return 0;
}

__attribute__((weak)) void cpSequenceCtrl::updateSequence() {
    DDON_STUB("cpSequenceCtrl::updateSequence")
    /* stub */
}

__attribute__((weak)) void cpSequenceCtrl::updateMotion() {
    DDON_STUB("cpSequenceCtrl::updateMotion")
    /* stub */
}

inline cpSequenceCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpSequenceCtrl::MyDTI cpSequenceCtrl::DTI("cpSequenceCtrl", &::cpComponent::DTI, 1120ul, 0u, 0u);

__attribute__((weak)) MtObject* cpSequenceCtrl::MyDTI::newInstance() const {
    DDON_STUB("cpSequenceCtrl::MyDTI::newInstance")
    return nullptr;
}

