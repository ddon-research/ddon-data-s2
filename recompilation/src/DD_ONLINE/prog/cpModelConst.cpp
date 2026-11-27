// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpModelConst.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cConstModelParam.h"
#include "cDelegate.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpSequenceCtrl.h"
#include "nDDOUtility.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cModelConstInfo::getDTI() const {
    return cModelConstInfo::DTI;
}

inline cModelConstInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cModelConstInfo::MyDTI cModelConstInfo::DTI("cModelConstInfo", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* cModelConstInfo::MyDTI::newInstance() const {
    DDON_STUB("cModelConstInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cpModelConst::getDTI() const {
    return cpModelConst::DTI;
}

void* cpModelConst::operator new(size_t sz, u32 align) {
    return cpModelConst::getAllocator()->memAlloc(sz, align, cpModelConst::DTI.getID());
}

cpModelConst::cpModelConst() {
    DDON_STUB("cpModelConst::cpModelConst")
    /* stub */
}

cpModelConst::~cpModelConst() {
}

__attribute__((weak)) void cpModelConst::setup() {
    DDON_STUB("cpModelConst::setup")
    /* stub */
}

__attribute__((weak)) void cpModelConst::kill() {
    DDON_STUB("cpModelConst::kill")
    /* stub */
}

void cpModelConst::update() {
    updateVisibleSeqence();
}

void cpModelConst::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
    mConstInfoList.elems[0].mpModel = static_cast<uDDOModel*>(pOwner);
    mConstInfoList.elems[0].mpCpModelConst = this;
    mConstInfoList.elems[1].mpModel = static_cast<uDDOModel*>(pOwner);
    mConstInfoList.elems[1].mpCpModelConst = this;
}

void cpModelConst::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

__attribute__((weak)) void cpModelConst::updateEfcHandle() {
}

__attribute__((weak)) void cpModelConst::setConstModelRes(rConstModelParam* pRes) {
    DDON_STUB("cpModelConst::setConstModelRes")
    /* stub */
}

__attribute__((weak)) void cpModelConst::updateVisibleSeqence() {
    DDON_STUB("cpModelConst::updateVisibleSeqence")
    /* stub */
}

inline cpModelConst::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpModelConst::MyDTI cpModelConst::DTI("cpModelConst", &::cpComponent::DTI, 288ul, 0u, 0u);

__attribute__((weak)) MtObject* cpModelConst::MyDTI::newInstance() const {
    DDON_STUB("cpModelConst::MyDTI::newInstance")
    return nullptr;
}

