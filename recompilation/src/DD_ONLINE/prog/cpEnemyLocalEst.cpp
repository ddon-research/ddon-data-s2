// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEnemyLocalEst.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "cpEnemyEffect.h"
#include "cpEnemyLocalShel.h"
#include "cpEnemyMaterial.h"
#include "cpEnemySound.h"
#include "cpStatusChange.h"
#include "rEnemyLocalEst.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEnemyLocalEst::getDTI() const {
    return cpEnemyLocalEst::DTI;
}

void* cpEnemyLocalEst::operator new(size_t sz, u32 align) {
    return cpEnemyLocalEst::getAllocator()->memAlloc(sz, align, cpEnemyLocalEst::DTI.getID());
}

cpEnemyLocalEst::cpEnemyLocalEst() {
    mpEnemyLocalEstTableRes = nullptr;
}

cpEnemyLocalEst::~cpEnemyLocalEst() {
    if (mpEnemyLocalEstTableRes == nullptr) {
        return;
    }
    mpEnemyLocalEstTableRes->release();
    mpEnemyLocalEstTableRes = nullptr;
}

void cpEnemyLocalEst::setup() {
    this->cpComponent::setup();
}

void cpEnemyLocalEst::updatePtr() {
    this->cpComponent::updatePtr();
}

__attribute__((weak)) void cpEnemyLocalEst::setResource(rEnemyLocalEst* pRes) {
    DDON_STUB("cpEnemyLocalEst::setResource")
    /* stub */
}

__attribute__((weak)) void cpEnemyLocalEst::checkStatusBit(u32 checkStatus, BitData nowBit, BitData oldBit, bool setUp) {
    DDON_STUB("cpEnemyLocalEst::checkStatusBit")
    /* stub */
}

void cpEnemyLocalEst::checkStatusPartsNo(uDDOModel* pDDoModel, bool setUp) {
    if (pDDoModel != nullptr) {
        if (mpEnemyLocalEstTableRes != nullptr) {
            if (mpEnemyLocalEstTableRes->getDataNum() != 0) {
                if (!setUp) {
                    for (unsigned int i3_3 = 0;;) {
                        cEnemyLocalEstTable* t1 = mpEnemyLocalEstTableRes->getData(i3_3);
                        if (t1 != nullptr) {
                            if (t1->mStatus == 10) {
                                if (!(!t1->mCheckBit && (((static_cast<unsigned long>(pDDoModel->mPartsDisp[t1->mBitNo >> 5]) >> static_cast<unsigned long>(t1->mBitNo & 31u)) & 1ul) == 0))) {
                                    if ((!t1->mCheckBit || (((static_cast<unsigned long>(pDDoModel->mPartsDisp[t1->mBitNo >> 5]) >> static_cast<unsigned long>(t1->mBitNo & 31u)) & 1ul) == 0)) == false) {
                                        setPlay(t1, false);
                                    }
                                } else {
                                    setPlay(t1, false);
                                }
                            }
                        }
                        if ((i3_3 + 1u) < mpEnemyLocalEstTableRes->getDataNum()) {
                            i3_3 += 1u;
                        } else {
                            break;
                        }
                    }
                } else {
                    for (unsigned int i0_3 = 0;;) {
                        cEnemyLocalEstTable* t0 = mpEnemyLocalEstTableRes->getData(i0_3);
                        if (t0 != nullptr) {
                            if (!t0->mSetUpOff) {
                                if (t0->mStatus == 10) {
                                    if (!(!t0->mCheckBit && (((static_cast<unsigned long>(pDDoModel->mPartsDisp[t0->mBitNo >> 5]) >> static_cast<unsigned long>(t0->mBitNo & 31u)) & 1ul) == 0))) {
                                        if ((!t0->mCheckBit || (((static_cast<unsigned long>(pDDoModel->mPartsDisp[t0->mBitNo >> 5]) >> static_cast<unsigned long>(t0->mBitNo & 31u)) & 1ul) == 0)) == false) {
                                            setPlay(t0, true);
                                        }
                                    } else {
                                        setPlay(t0, true);
                                    }
                                }
                            }
                        }
                        if ((i0_3 + 1u) < mpEnemyLocalEstTableRes->getDataNum()) {
                            i0_3 += 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void cpEnemyLocalEst::setPlay(cEnemyLocalEstTable* pResData, bool setUp) {
    DDON_STUB("cpEnemyLocalEst::setPlay")
    /* stub */
}

inline cpEnemyLocalEst::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEnemyLocalEst::MyDTI cpEnemyLocalEst::DTI("cpEnemyLocalEst", &::cpComponent::DTI, 88ul, 0u, 0u);

MtObject* cpEnemyLocalEst::MyDTI::newInstance() const {
    return new (16u) cpEnemyLocalEst;
}

