// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEnemyMaterial.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "cpDDMrlMgr.h"
#include "rEnemyMaterialTable.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEnemyMaterial::getDTI() const {
    return cpEnemyMaterial::DTI;
}

void* cpEnemyMaterial::operator new(size_t sz, u32 align) {
    return cpEnemyMaterial::getAllocator()->memAlloc(sz, align, cpEnemyMaterial::DTI.getID());
}

cpEnemyMaterial::cpEnemyMaterial() {
    mpEnemyMaterialTableRes = nullptr;
}

cpEnemyMaterial::~cpEnemyMaterial() {
    if (mpEnemyMaterialTableRes == nullptr) {
        return;
    }
    mpEnemyMaterialTableRes->release();
    mpEnemyMaterialTableRes = nullptr;
}

void cpEnemyMaterial::setup() {
    this->cpComponent::setup();
}

void cpEnemyMaterial::updatePtr() {
    this->cpComponent::updatePtr();
}

__attribute__((weak)) void cpEnemyMaterial::setResource(rEnemyMaterialTable* pRes) {
    DDON_STUB("cpEnemyMaterial::setResource")
    /* stub */
}

__attribute__((weak)) void cpEnemyMaterial::playResTableIdx(u32 idx) {
    DDON_STUB("cpEnemyMaterial::playResTableIdx")
    /* stub */
}

inline cpEnemyMaterial::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEnemyMaterial::MyDTI cpEnemyMaterial::DTI("cpEnemyMaterial", &::cpComponent::DTI, 88ul, 0u, 0u);

MtObject* cpEnemyMaterial::MyDTI::newInstance() const {
    return new (16u) cpEnemyMaterial;
}

