// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cScenarioElement.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cAreaHit.h"
#include "cFSMRelate.h"
#include "cNetSessionManager.h"
#include "cScenario.h"
#include "cpActionManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sFlag.h"
#include "sGame.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sPlayerManager.h"
#include "sScenario.h"
#include "sSoundManager.h"
#include "uDDOModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cScenarioArg_AreaJump::getDTI() const {
    return cScenarioArg_AreaJump::DTI;
}

void* cScenarioArg_AreaJump::operator new(size_t sz, u32 align) {
    return cScenarioArg_AreaJump::getAllocator()->memAlloc(sz, align, cScenarioArg_AreaJump::DTI.getID());
}

cScenarioArg_AreaJump::cScenarioArg_AreaJump(cScenario* pSce) : cScenarioArg(pSce) {
    mStageNo = 100;
    mPosNo = 0;
}

cScenarioArg_AreaJump::~cScenarioArg_AreaJump() {
    sScenario::getInstance()->deleteSystemMsg();
}

cScenarioArg& cScenarioArg_AreaJump::operator=(const cScenarioArg& s) {
    mStageNo = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(&s) + 56);
    mPosNo = static_cast<s32>(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(&s) + 60));
    return *this;
}

void cScenarioArg_AreaJump::createProperty(MtPropertyList& s) {
    this->cScenarioArg::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPosNo", &mPosNo, 0u, 0u);
}

MtUI* cScenarioArg_AreaJump::createUI(MtProperty& prop) {
    return this->cScenarioArg::createUI(prop);
}

__attribute__((weak)) void cScenarioArg_AreaJump::callback(MtObject* pOwner, s32 pl_no, u32, s32, f32) {
    DDON_STUB("cScenarioArg_AreaJump::callback")
    /* stub */
}

__attribute__((weak)) SCENARIO_ACTION_RETURN cScenarioArg_AreaJump::actionMain(cScenarioArg* _pArg) {
    DDON_STUB("cScenarioArg_AreaJump::actionMain")
    return {};
}

inline cScenarioArg_AreaJump::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cScenarioArg_AreaJump::MyDTI cScenarioArg_AreaJump::DTI("cScenarioArg_AreaJump", &::cScenarioArg::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* cScenarioArg_AreaJump::MyDTI::newInstance() const {
    return new (16u) cScenarioArg_AreaJump(nullptr);
}

const MtDTI& cScenarioArg_BootFSM::getDTI() const {
    return cScenarioArg_BootFSM::DTI;
}

void* cScenarioArg_BootFSM::operator new(size_t sz, u32 align) {
    return cScenarioArg_BootFSM::getAllocator()->memAlloc(sz, align, cScenarioArg_BootFSM::DTI.getID());
}

cScenarioArg_BootFSM::cScenarioArg_BootFSM(cScenario* pSce) : cScenarioArg(static_cast<cScenario*>(nullptr)) {
    mTouchType = 0;
}

__attribute__((weak)) cScenarioArg& cScenarioArg_BootFSM::operator=(const cScenarioArg& s) {
    DDON_STUB("cScenarioArg_BootFSM::operator=")
    __builtin_unreachable();
}

cScenarioArg_BootFSM::~cScenarioArg_BootFSM() {
    if (mFSMList.mLength != 0) {
        u32 v0_0 = mFSMList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mFSMList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mFSMList.mpArray[i0_3];
                v1_0 = mFSMList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mFSMList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mFSMList.mpArray));
    }
    mFSMList.mpArray = nullptr;
    mFSMList.mBufsiz = 0;
    mFSMList.mLength = 0;
}

void cScenarioArg_BootFSM::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTouchType", &mTouchType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFSMList", static_cast<MtObject*>(&mFSMList), 0u, 0u);
}

MtUI* cScenarioArg_BootFSM::createUI(MtProperty& prop) {
    return this->cScenarioArg::createUI(prop);
}

__attribute__((weak)) void cScenarioArg_BootFSM::callback(MtObject* pOwner, s32 pl_no, u32 starter, s32, f32) {
    DDON_STUB("cScenarioArg_BootFSM::callback")
    /* stub */
}

__attribute__((weak)) SCENARIO_ACTION_RETURN cScenarioArg_BootFSM::actionMain(cScenarioArg* _pArg) {
    DDON_STUB("cScenarioArg_BootFSM::actionMain")
    return {};
}

inline cScenarioArg_BootFSM::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cScenarioArg_BootFSM::MyDTI cScenarioArg_BootFSM::DTI("cScenarioArg_BootFSM", &::cScenarioArg::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cScenarioArg_BootFSM::MyDTI::newInstance() const {
    return new (16u) cScenarioArg_BootFSM(nullptr);
}

__attribute__((weak)) SCENARIO_ACTION_FUNC_MAIN cScenarioElement::getActionMain(SCENARIO_TASK_ENUM task) {
    DDON_STUB("cScenarioElement::getActionMain")
    return {};
}

SCENARIO_ACTION_FUNC_END cScenarioElement::getActionEnd(SCENARIO_TASK_ENUM task) {
    return nullptr;
}

