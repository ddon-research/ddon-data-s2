// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cEmWorkRateCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
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

inline void* cEmWorkRateCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cEmWorkRateCtrl::DTI)->memAlloc(sz, align, cEmWorkRateCtrl::DTI.getID());
}

inline void cEmWorkRateCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cEmWorkRateCtrl::DTI)->memFree(p_addr);
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
    s << MtProperty(static_cast<MtObject*>(this), "\347\217\276\345\234\250\343\201\256\347\212\266\346\205\213\347\225\252\345\217\267", &mStatusNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\217\276\345\234\250\343\201\256\347\212\266\346\205\213\345\204\252\345\205\210\345\272\246", &mStatusPriority, 0u, 0u);
}

void cEmWorkRateCtrl::setOwner(uEnemy* pEnemy) {
    mpEnemy = pEnemy;
}

__attribute__((weak)) void cEmWorkRateCtrl::changeWorkRateNo(u32 statusNo, nStatusEnemy::WORKRATE_CHANGE_TYPE changeType) {
    DDON_STUB("cEmWorkRateCtrl::changeWorkRateNo")
    /* stub */
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

