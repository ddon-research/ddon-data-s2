// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cEmWorkRateCtrl.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "cpWorkRate.h"
#include "../../generated/shared/nStatusEnemy.h"
#include "rEmWorkRateTable.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmWorkRateCtrl::getDTI() const {
    return cEmWorkRateCtrl::DTI;
}

cEmWorkRateCtrl::cEmWorkRateCtrl() {
    mpEmWorkRateTableRes = nullptr;
    mpEnemy = nullptr;
    mStatusNo = 0xFFFFFFFF;
    mStatusType = nStatusEnemy::WORKRATE_STATUS_NONE;
    mStatusPriority = 1;
}

cEmWorkRateCtrl::~cEmWorkRateCtrl() {
    if (mpEmWorkRateTableRes == nullptr) {
        return;
    }
    mpEmWorkRateTableRes->release();
    mpEmWorkRateTableRes = nullptr;
}

void cEmWorkRateCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "現在の状態番号", &mStatusNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "現在の状態優先度", &mStatusPriority, 0u, 0u);
}

void cEmWorkRateCtrl::setOwner(uEnemy* pEnemy) {
    mpEnemy = pEnemy;
}

void cEmWorkRateCtrl::changeWorkRateNo(u32 statusNo, nStatusEnemy::WORKRATE_CHANGE_TYPE changeType) {
    if (mStatusNo == statusNo) {
        return;
    }
    if (mpEnemy == nullptr) {
        return;
    }
    if (mpEmWorkRateTableRes == nullptr) {
        return;
    }
    if (mpEnemy->mGuardComponent.mpHpDamageCtrl == nullptr) {
        return;
    }
    if (statusNo < mpEmWorkRateTableRes->getDataNum()) {
        const cEmWorkRateTable* pWorkRateData = mpEmWorkRateTableRes->getData(statusNo);
        if (pWorkRateData != nullptr) {
            if (changeType != nStatusEnemy::WORKRATE_CHANGE_TYPE_SETUP) {
                if (static_cast<unsigned int>(changeType - 1) <= 2) {
                    nStatusEnemy::WORKRATE_STATUS_TYPE statusType = static_cast<nStatusEnemy::WORKRATE_STATUS_TYPE>(pWorkRateData->getWorkRateStatus());
                    if (statusType != nStatusEnemy::WORKRATE_STATUS_INVALID) {
                        mStatusNo = statusNo;
                        mStatusType = statusType;
                        cpWorkRate* pCpWorkRate = mpEnemy->getWorkRatePtr();
                        if (pCpWorkRate != nullptr) {
                            if (mpEmWorkRateTableRes != nullptr) {
                                if (statusNo < mpEmWorkRateTableRes->getDataNum()) {
                                    cEmWorkRateTable* pResDataWRate = mpEmWorkRateTableRes->getData(statusNo);
                                    if (pResDataWRate != nullptr) {
                                        pCpWorkRate->setSpeed(pResDataWRate->getWorkRate(), cpWorkRate::STATUS_CHEANGE);
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                mStatusNo = statusNo;
                mStatusType = nStatusEnemy::WORKRATE_STATUS_SETUP;
                cpWorkRate* pCpWorkRate = mpEnemy->getWorkRatePtr();
                if (pCpWorkRate != nullptr) {
                    if (mpEmWorkRateTableRes != nullptr) {
                        if (statusNo < mpEmWorkRateTableRes->getDataNum()) {
                            cEmWorkRateTable* pResDataWRate = mpEmWorkRateTableRes->getData(statusNo);
                            if (pResDataWRate != nullptr) {
                                pCpWorkRate->setSpeed(pResDataWRate->getWorkRate(), cpWorkRate::STATUS_CHEANGE);
                            }
                        }
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void cEmWorkRateCtrl::setEmWorkRateRes(rEmWorkRateTable* pRes) {
    DDON_STUB("cEmWorkRateCtrl::setEmWorkRateRes")
    /* stub */
}

__attribute__((weak)) void cEmWorkRateCtrl::updateEmWorkRate() {
    DDON_STUB("cEmWorkRateCtrl::updateEmWorkRate")
    /* stub */
}

inline cEmWorkRateCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmWorkRateCtrl::MyDTI cEmWorkRateCtrl::DTI("cEmWorkRateCtrl", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cEmWorkRateCtrl::MyDTI::newInstance() const {
    return new (16u) cEmWorkRateCtrl;
}

