// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rCharacterEditModelPalette.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cCharacterEditPaletteBase.h"
#include "cResPath.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../XFramework/rModel.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cCharacterEditModelPalette>::allocData(unsigned int);
#endif

const MtDTI& cCharacterEditModelPalette::getDTI() const {
    return cCharacterEditModelPalette::DTI;
}

inline cCharacterEditModelPalette::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCharacterEditModelPalette::MyDTI cCharacterEditModelPalette::DTI("cCharacterEditModelPalette", &::cCharacterEditPaletteBase::DTI, 40ul, 0u, 0u);

MtObject* cCharacterEditModelPalette::MyDTI::newInstance() const {
    return new (16u) cCharacterEditModelPalette;
}

const MtDTI& rCharacterEditModelPalette::getDTI() const {
    return rCharacterEditModelPalette::DTI;
}

rCharacterEditModelPalette::~rCharacterEditModelPalette() {
}

bool rCharacterEditModelPalette::loadData(MtDataReader& r, cCharacterEditModelPalette* pData) {
    pData->loadData(r);
    nDDOIO::readData(r, pData->mUID);
    nDDOIO::readData(r, pData->mPath);
    nDDOIO::readData(r, pData->mRandom);
    return true;
}

MT_CTSTR rCharacterEditModelPalette::getExt() const {
    return "edt_mod_pal";
}

u32 rCharacterEditModelPalette::getDataVersion() const {
    return 34;
}

__attribute__((weak)) bool rCharacterEditModelPalette::loadCore(MtDataReader& r) {
    u32 t1;
    this->readDataValue(r, t1);
    {
        u32 t4 = t1;
        if (this->mpData != nullptr) {
            delete[] this->mpData;
            this->mpData = nullptr;
        }
        this->mDataNum = 0;
        if (t4 != 0) {
            this->mpData = new (16u) cCharacterEditModelPalette[t4];
            this->mDataNum = t4;
        }
    }
    if (t1 != 0) {
        u32 t2 = 0;
        cCharacterEditModelPalette* t3 = this->mpData;
        do {
            if (!this->loadData(r, &t3[t2])) {
                return false;
            }
            t2 += 1u;
        } while (t2 < t1);
    }
    return true;
}

inline rCharacterEditModelPalette::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rCharacterEditModelPalette::MyDTI rCharacterEditModelPalette::DTI("rCharacterEditModelPalette", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rCharacterEditModelPalette::MyDTI::newInstance() const {
    return new (16u) rCharacterEditModelPalette;
}

template cCharacterEditModelPalette* rTbl2<cCharacterEditModelPalette>::getData(unsigned int);

template bool rTbl2<cCharacterEditModelPalette>::load(MtStream&);

template bool rTbl2<cCharacterEditModelPalette>::loadCore(MtDataReader&);

template const cCharacterEditModelPalette* rTbl2<cCharacterEditModelPalette>::getData(unsigned int) const;

template unsigned int rTbl2<cCharacterEditModelPalette>::getDataNum() const;

template rTbl2<cCharacterEditModelPalette>::~rTbl2();

