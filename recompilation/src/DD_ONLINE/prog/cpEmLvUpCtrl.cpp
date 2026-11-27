// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEmLvUpCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpEmParamCtrl.h"
#include "../../generated/shared/nEnemy.h"
#include "rEmLvUpParam.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEmLvUpCtrl::getDTI() const {
    return cpEmLvUpCtrl::DTI;
}

void* cpEmLvUpCtrl::operator new(size_t sz, u32 align) {
    return cpEmLvUpCtrl::getAllocator()->memAlloc(sz, align, cpEmLvUpCtrl::DTI.getID());
}

cpEmLvUpCtrl::cpEmLvUpCtrl() {
    mpModel = nullptr;
    mpResource = nullptr;
    mpLvUpParam = nullptr;
    mpLvUpParam = new (16u) cEmLvUpParam;
}

cpEmLvUpCtrl::~cpEmLvUpCtrl() {
    if (mpLvUpParam != nullptr) {
        delete mpLvUpParam;
        mpLvUpParam = nullptr;
    }
    if (mpResource == nullptr) {
        return;
    }
    mpResource->release();
    mpResource = nullptr;
}

void cpEmLvUpCtrl::setup() {
    this->cpComponent::setup();
}

void cpEmLvUpCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
}

void cpEmLvUpCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        return;
    }
    mpModel = nullptr;
}

__attribute__((weak)) void cpEmLvUpCtrl::setResource(rEmLvUpParam* pRes) {
    DDON_STUB("cpEmLvUpCtrl::setResource")
    /* stub */
}

__attribute__((weak)) void cpEmLvUpCtrl::changeLv(u32 Lv, nEnemy::PARAM_RESET_TYPE resetType) {
    DDON_STUB("cpEmLvUpCtrl::changeLv")
    /* stub */
}

__attribute__((weak)) void cpEmLvUpCtrl::calcEmLvUpParam(u32 Lv) {
    DDON_STUB("cpEmLvUpCtrl::calcEmLvUpParam")
    /* stub */
}

inline cpEmLvUpCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEmLvUpCtrl::MyDTI cpEmLvUpCtrl::DTI("cpEmLvUpCtrl", &::cpComponent::DTI, 104ul, 0u, 0u);

MtObject* cpEmLvUpCtrl::MyDTI::newInstance() const {
    return new (16u) cpEmLvUpCtrl;
}

