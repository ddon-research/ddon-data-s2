// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpStateManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cDelegate.h"
#include "cState.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpStateManager::getDTI() const {
    return cpStateManager::DTI;
}

void* cpStateManager::operator new(size_t sz, u32 align) {
    return cpStateManager::getAllocator()->memAlloc(sz, align, cpStateManager::DTI.getID());
}

cpStateManager::cpStateManager() {
    mpCurrentState = nullptr;
    mpModel = nullptr;
}

__attribute__((noinline)) cpStateManager::~cpStateManager() {
    if (mArray.mLength != 0) {
        u32 v0_0 = mArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mArray.mpArray[i0_3];
                v1_0 = mArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mArray.mpArray));
    }
    mArray.mpArray = nullptr;
    mArray.mBufsiz = 0;
    mArray.mLength = 0;
    if (mpCurrentState != nullptr) {
        delete mpCurrentState;
        mpCurrentState = nullptr;
    }
}

void cpStateManager::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

__attribute__((weak)) void cpStateManager::addState(s32 state, const MtDTI* pDti) {
    DDON_STUB("cpStateManager::addState")
    /* stub */
}

__attribute__((weak)) void cpStateManager::setup() {
    DDON_STUB("cpStateManager::setup")
    /* stub */
}

void cpStateManager::update() {
    if (mpCurrentState == nullptr) {
        return;
    }
    mpCurrentState->move();
}

void cpStateManager::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

void cpStateManager::kill() {
    if (mpCurrentState == nullptr) {
        return;
    }
    mpCurrentState->final();
    if (mpCurrentState == nullptr) {
        return;
    }
    delete mpCurrentState;
    mpCurrentState = nullptr;
}

__attribute__((weak)) void cpStateManager::setState(s32 state) {
    DDON_STUB("cpStateManager::setState")
    /* stub */
}

s32 cpStateManager::getStateNo() {
    if (mpCurrentState != nullptr) {
        return mpCurrentState->getStateNo();
    } else {
        return -1;
    }
}

const cState* cpStateManager::getCurrentState() {
    return mpCurrentState;
}

inline cpStateManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpStateManager::MyDTI cpStateManager::DTI("cpStateManager", &::cpComponent::DTI, 128ul, 0u, 0u);

MtObject* cpStateManager::MyDTI::newInstance() const {
    return new (16u) cpStateManager;
}

template MtTypedArray<cStateInfo>::~MtTypedArray();

