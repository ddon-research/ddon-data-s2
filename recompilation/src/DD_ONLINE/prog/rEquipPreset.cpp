// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEquipPreset.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cEquipPreset>::allocData(unsigned int);
#endif

const MtDTI& cEquipPreset::getDTI() const {
    return cEquipPreset::DTI;
}

inline cEquipPreset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEquipPreset::MyDTI cEquipPreset::DTI("cEquipPreset", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cEquipPreset::MyDTI::newInstance() const {
    return new (16u) cEquipPreset;
}

const MtDTI& rEquipPreset::getDTI() const {
    return rEquipPreset::DTI;
}

rEquipPreset::~rEquipPreset() {
}

bool rEquipPreset::loadData(MtDataReader& r, cEquipPreset* pData) {
    nDDOIO::readData(r, pData->mItemId);
    return true;
}

MT_CTSTR rEquipPreset::getExt() const {
    return "equip_preset";
}

u32 rEquipPreset::getDataVersion() const {
    return 7;
}

__attribute__((weak)) bool rEquipPreset::loadCore(MtDataReader& r) {
    u32 t1;
    this->::rTbl2Base::readDataValue(r, t1);
    // workaround
    {
        u32 t2 = t1;
        if (this->mpData != nullptr) {
            delete[] this->mpData;
            this->mpData = nullptr;
        }
        this->mDataNum = 0;
        if (t2 != 0) {
            this->mpData = new (16u) cEquipPreset[t2];
            this->mDataNum = t2;
        }
    }
    if (t1 != 0) {
        u32 t3 = 0;
        cEquipPreset* t4 = this->mpData;
        do {
            if (!this->loadData(r, &t4[t3])) {
                return false;
            }
            t3 += 1u;
        } while (t3 < t1);
    }
    return true;
}

inline rEquipPreset::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEquipPreset::MyDTI rEquipPreset::DTI("rEquipPreset", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEquipPreset::MyDTI::newInstance() const {
    return new (16u) rEquipPreset;
}

template cEquipPreset* rTbl2<cEquipPreset>::getData(unsigned int);

template bool rTbl2<cEquipPreset>::load(MtStream&);

template bool rTbl2<cEquipPreset>::loadCore(MtDataReader&);

template const cEquipPreset* rTbl2<cEquipPreset>::getData(unsigned int) const;

template unsigned int rTbl2<cEquipPreset>::getDataNum() const;

template rTbl2<cEquipPreset>::~rTbl2();

