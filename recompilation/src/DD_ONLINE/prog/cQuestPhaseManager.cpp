// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestPhaseManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "Protocol/PacketData/Quest.h"
#include "Protocol/UserSession/S2C.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestPhaseComponent.h"
#include "cQuestPhaseEvent.h"
#include "cQuestPhaseState.h"
#include "cQuestPhaseState002.h"
#include "cQuestSvNotice.h"
#include "cQuestSvNoticeManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestPhaseManager::getDTI() const {
    return cQuestPhaseManager::DTI;
}

inline MtAllocator* cQuestPhaseManager::getAllocator() {
    return MtMemoryAllocator::getAllocator(cQuestPhaseManager::DTI);
}

void* cQuestPhaseManager::operator new(size_t sz, u32 align) {
    return cQuestPhaseManager::getAllocator()->memAlloc(sz, align, cQuestPhaseManager::DTI.getID());
}

inline void cQuestPhaseManager::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cQuestPhaseManager::DTI)->memFree(p_addr);
}

cQuestPhaseState* cQuestPhaseManager::getQuestPhaseState() const {
    return mpState;
}

__attribute__((weak)) void cQuestPhaseManager::move() {
    DDON_STUB("cQuestPhaseManager::move")
    /* stub */
}

__attribute__((weak)) void cQuestPhaseManager::callbackQuestPhaseNotice(void* pPacket) {
    DDON_STUB("cQuestPhaseManager::callbackQuestPhaseNotice")
    /* stub */
}

void cQuestPhaseManager::release() {
    if (mpState != nullptr) {
        delete mpState;
        mpState = nullptr;
    }
    mPhaseId = 0;
    if (mEventList.mLength != 0) {
        u32 v0_0 = mEventList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mEventList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mEventList.mpArray[i0_3];
                v1_0 = mEventList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mEventList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mEventList.mpArray));
    }
    mEventList.mpArray = nullptr;
    mEventList.mBufsiz = 0;
    mEventList.mLength = 0;
}

cQuestPhaseManager::cQuestPhaseManager() {
    mpState = nullptr;
    mPhaseId = 0;
    cQuestSvNoticeManager::addCallbackFunc(cQuestSvNoticeCallback::DTI, cQuestSvNotQuestPhase::DTI)->cQuestSvNoticeCallback::setFromClass(static_cast<MtObject*>(this)).setCallbackFunc(static_cast<cQuestSvNoticeCallback::PCallbackFunc>(&::cQuestPhaseManager::callbackQuestPhaseNotice));
}

__attribute__((noinline)) cQuestPhaseManager::~cQuestPhaseManager() {
    if (mpState != nullptr) {
        delete mpState;
        mpState = nullptr;
    }
    if (mEventList.mLength != 0) {
        u32 v0_0 = mEventList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mEventList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mEventList.mpArray[i0_3];
                v1_0 = mEventList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mEventList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mEventList.mpArray));
    }
    mEventList.mpArray = nullptr;
    mEventList.mBufsiz = 0;
    mEventList.mLength = 0;
}

void cQuestPhaseManager::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpState", reinterpret_cast<MtObject* *>(&mpState), 0u, 0u);
}

MtUI* cQuestPhaseManager::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cQuestPhaseManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestPhaseManager::MyDTI cQuestPhaseManager::DTI("cQuestPhaseManager", &::cQuestFunctionManagerBase::DTI, 56ul, 0u, 0u);

MtObject* cQuestPhaseManager::MyDTI::newInstance() const {
    return new (16u) cQuestPhaseManager;
}

template MtTypedArray<cQuestPhaseEvent>::~MtTypedArray();

