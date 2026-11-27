// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cRemoteProcedure.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStlAllocator.h"
#include "../MT/MtStlCustom.h"
#include "../MT/MtString.h"
#include "../MT/MtSynchronize.h"
#include "sRemoteProcedure.h"
#include "sUnit.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cRemoteProcedure::getDTI() const {
    return cRemoteProcedure::DTI;
}

cRemoteProcedure::cRemoteProcedure() {
    DDON_STUB("cRemoteProcedure::cRemoteProcedure")
    /* stub */
}

__attribute__((noinline)) cRemoteProcedure::~cRemoteProcedure() {
    DDON_STUB("cRemoteProcedure::~cRemoteProcedure")
    /* stub */
}

void cRemoteProcedure::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mID", &mID, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mValid", &mValid, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mKill", &mKill, 0u, 0u);
}

MtUI* cRemoteProcedure::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cRemoteProcedure::setup(RPC_ID id, const MtString& group) {
    DDON_STUB("cRemoteProcedure::setup")
    /* stub */
}

void cRemoteProcedure::remove() {
    if ((sRemoteProcedure::mpInstance) == nullptr) {
        return;
    }
    (sRemoteProcedure::mpInstance)->sRemoteProcedure::removeObject(this);
}

__attribute__((weak)) void cRemoteProcedure::addGroup(const MtString& group) {
    DDON_STUB("cRemoteProcedure::addGroup")
    /* stub */
}

bool cRemoteProcedure::process(cRemoteCall& call, s32 member) {
    if (mpParent != nullptr) {
        if (mpCallback != static_cast<cRemoteProcedure::PROCESS_CALLBACK>(0)) {
            (mpParent->*mpCallback)(call, member);
            return true;
        }
    }
    return false;
}

bool cRemoteProcedure::processRemoteCallDefault(cRemoteCall& call, bool isParallel, s32 member_id) {
    return false;
}

__attribute__((weak)) bool cRemoteProcedure::processRemoteCallBoth(cRemoteCall& call, s32 member_id) {
    bool result = false;
    IStateMachineRpcReceiver* t1 = getRpcReceiveStateMachine();
    if (t1 != nullptr && t1->processRemoteCallInStateMachine(call, true)) {
        result = true;
    } else {
        result = processRemoteCall(call, true, member_id);
    }
    t1 = getRpcReceiveStateMachine();
    if (t1 != nullptr && t1->processRemoteCallInStateMachine(call, false)) {
        result = true;
    } else {
        result = processRemoteCall(call, false, member_id) | result;
    }
    return result;
}

bool cRemoteProcedure::processRemoteCall(cRemoteCall& call, bool issParallel, s32 member_id) {
    return false;
}

IStateMachineRpcReceiver* cRemoteProcedure::getRpcReceiveStateMachine() {
    return nullptr;
}

inline cRemoteProcedure::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cRemoteProcedure::MyDTI cRemoteProcedure::DTI("cRemoteProcedure", &::MtObject::DTI, 96ul, 0u, 1u);

MtObject* cRemoteProcedure::MyDTI::newInstance() const {
    return nullptr;
}

