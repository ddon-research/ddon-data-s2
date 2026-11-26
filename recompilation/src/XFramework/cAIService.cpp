// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "cAIService.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "../MT/MtSynchronize.h"
#include "cAIObject.h"
#include "cSystem.h"
#include "sAI.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cAIService::getDTI() const {
    return cAIService::DTI;
}

cAIService::cAIService() {
    DDON_STUB("cAIService::cAIService")
    /* stub */
}

cAIService::~cAIService() {
    DDON_STUB("cAIService::~cAIService")
    /* stub */
}

MtUI* cAIService::createUI(MtProperty& prop) {
    return nullptr;
}

void cAIService::createProperty(MtPropertyList& s) {
    this->cAIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CSTRING, "mDTI", reinterpret_cast<MT_MFUNC>(&::cAIService::getDTIName), reinterpret_cast<MT_MFUNC>(&::cAIService::setDTIName), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mID", &mID, 1u, 0u);
}

void cAIService::lock() {
    if (!((sAI::mpInstance)->::cSystem::mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexLock(&mCS.mCSection) != 0) {
        abort();
    }
}

void cAIService::unlock() {
    if (!((sAI::mpInstance)->::cSystem::mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

MT_CTSTR cAIService::getDTIName() {
    return getDTI().mName;
}

__attribute__((weak)) void cAIService::setDTIName(MT_CTSTR) {
}

inline cAIService::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cAIService::MyDTI cAIService::DTI("cAIService", &::cAIObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cAIService::MyDTI::newInstance() const {
    DDON_STUB("cAIService::MyDTI::newInstance")
    return nullptr;
}

