// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cFSMCore.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cAIFSM.h"
#include "../../XFramework/cAIObject.h"
#include "../../XFramework/cAIService.h"
#include "../../XFramework/cAISvUserProcess.h"
#include "../../XFramework/cAIUserProcess.h"
#include "../../XFramework/cResource.h"
#include "nFsm.h"
#include "../../XFramework/rAIFSM.h"
#include "../../XFramework/sAI.h"
#include "sArchiveManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cFSMCore::getDTI() const {
    return cFSMCore::DTI;
}

inline void cFSMCore::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMCore::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cFSMCore::move() {
    DDON_STUB("cFSMCore::move")
    /* stub */
}

bool cFSMCore::setupFSM(MT_CTSTR resourcePath) {
    mFSM.mpOwner = static_cast<MtObject*>(this);
    if (resourcePath != nullptr) {
        rAIFSM* pFSMRes = static_cast<rAIFSM*>(sArchiveManager::getInstance()->createRes(rAIFSM::DTI, resourcePath, 128u, false));
        if (pFSMRes != nullptr) {
            mFSM.setResource(pFSMRes, 0u);
            mFSM.cAIFSM::reset();
            pFSMRes->release();
            mIsEnable = true;
            mChangeCountState = -1.0f;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

u32 cFSMCore::stateDefUpdate(MtObject* pParam, MtObject* pCaller) {
    if (mChangeCountState > 0.0f) {
        mCountState = mCountState - mChangeCountState;
    } else {
        mCountState = 0.0f;
    }
    mChangeCountState = -1.0f;
    callbackUpdate();
    return 0;
}

u32 cFSMCore::stateUpdateFinish(MtObject* pParam, MtObject* pCaller) {
    mIsEnable = false;
    callbackFinish();
    return 0;
}

__attribute__((weak)) void cFSMCore::addFSMAction(MT_CTSTR toolName, MT_CTSTR name, const MtDTI* pOwner, const MtDTI* pParam, cFSMCore::PROCESS_FUNC updateFunc, cFSMCore::PROCESS_FUNC stateFunc) {
    DDON_STUB("cFSMCore::addFSMAction")
    /* stub */
}

__attribute__((weak)) void cFSMCore::addFSMAction(MT_CTSTR name, const MtDTI* pOwner, const MtDTI* pParam, cFSMCore::PROCESS_FUNC updateFunc, cFSMCore::PROCESS_FUNC stateFunc) {
    DDON_STUB("cFSMCore::addFSMAction")
    /* stub */
}

__attribute__((weak)) void cFSMCore::addFSMAction(MT_CTSTR name, const MtDTI* pOwner, const MtDTI* pParam, cFSMCore::PROCESS_FUNC updateFunc, cFSMCore::PROCESS_FUNC stateFunc, cFSMCore::PROCESS_FUNC exitFunc) {
    DDON_STUB("cFSMCore::addFSMAction")
    /* stub */
}

f32 cFSMCore::getCountState() {
    mChangeCountState = mCountState;
    return mChangeCountState;
}

cFSMCore::cFSMCore() {
    mpOwner = nullptr;
    mIsEnable = false;
    mCountState = 0.0f;
    mCountFSM = 0.0f;
    mChangeCountState = -1.0f;
    mFSM.cAIFSM::reset();
    mFSM.setDefaultUpdateFunc(static_cast<cAIUserProcessCallback::CALLBACK_FUNC>(&::cFSMCore::stateDefUpdate), 0u);
    cAIService* t0 = (sAI::mpInstance)->sAI::getService(cAISvUserProcess::DTI, static_cast<MT_CTSTR>(nullptr));
    static_cast<cAISvUserProcess*>(t0)->addContainer(static_cast<cAIUserProcessContainer*>(new (16u) cAIFSMProcessContainer("Finish", static_cast<const MtDTI*>(&cFSMCore::DTI), static_cast<cAIUserProcessCallback::CALLBACK_FUNC>(&::cFSMCore::stateUpdateFinish), static_cast<cAIUserProcessCallback::CALLBACK_FUNC>(0), static_cast<const MtDTI*>(&cAICopiableParameter::DTI), static_cast<MT_CTSTR>(nullptr))));
}

cFSMCore::~cFSMCore() {
    mFSM.cAIFSM::reset();
}

void cFSMCore::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mFSM", static_cast<MtObject*>(&mFSM), 0u, 0u);
    createPropertyFSM(s);
    this->cAIObject::createProperty(s);
}

void cFSMCore::createPropertyFSM(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "CountState", reinterpret_cast<MT_MFUNC>(&::cFSMCore::getCountState), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "CountFSM", &mCountFSM, 0u, 0u);
}

inline cFSMCore::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMCore::MyDTI cFSMCore::DTI("cFSMCore", &::cAIObject::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMCore::MyDTI::newInstance() const {
    DDON_STUB("cFSMCore::MyDTI::newInstance")
    return nullptr;
}

