// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEnemyLocalShelTable.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEnemyLocalShelTable::getDTI() const {
    return cEnemyLocalShelTable::DTI;
}

void cEnemyLocalShelTable::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIdx", &mIdx, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSyncFlagMax32", &mSyncFlagMax32, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDieIsNoCall", &mDieIsNoCall, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShellNo", &mShellNo, 0u, 0u);
}

inline cEnemyLocalShelTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEnemyLocalShelTable::MyDTI cEnemyLocalShelTable::DTI("cEnemyLocalShelTable", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cEnemyLocalShelTable::MyDTI::newInstance() const {
    return new (16u) cEnemyLocalShelTable;
}

const MtDTI& rEnemyLocalShelTable::getDTI() const {
    return rEnemyLocalShelTable::DTI;
}

bool rEnemyLocalShelTable::loadData(MtDataReader& in, cEnemyLocalShelTable* pData) {
    nDDOIO::readData(in, pData->mIdx);
    nDDOIO::readData(in, pData->mShellNo);
    nDDOIO::readData(in, pData->mDieIsNoCall);
    nDDOIO::readData(in, pData->mSyncFlagMax32);
    return true;
}

MT_CTSTR rEnemyLocalShelTable::getExt() const {
    return "esh";
}

u32 rEnemyLocalShelTable::getDataVersion() const {
    return 260;
}

inline rEnemyLocalShelTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEnemyLocalShelTable::MyDTI rEnemyLocalShelTable::DTI("rEnemyLocalShelTable", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEnemyLocalShelTable::MyDTI::newInstance() const {
    return new (16u) rEnemyLocalShelTable;
}

template cEnemyLocalShelTable* rTbl2<cEnemyLocalShelTable>::getData(unsigned int);

template bool rTbl2<cEnemyLocalShelTable>::load(MtStream&);

template bool rTbl2<cEnemyLocalShelTable>::loadCore(MtDataReader&);

template const cEnemyLocalShelTable* rTbl2<cEnemyLocalShelTable>::getData(unsigned int) const;

template unsigned int rTbl2<cEnemyLocalShelTable>::getDataNum() const;

template rTbl2<cEnemyLocalShelTable>::~rTbl2();

