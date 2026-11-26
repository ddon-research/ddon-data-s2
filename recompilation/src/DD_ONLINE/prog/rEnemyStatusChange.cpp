// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEnemyStatusChange.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEnemyStatusChange::getDTI() const {
    return cEnemyStatusChange::DTI;
}

inline void* cEnemyStatusChange::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cEnemyStatusChange::DTI)->memAlloc(sz, align, cEnemyStatusChange::DTI.getID());
}

inline void cEnemyStatusChange::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cEnemyStatusChange::DTI)->memFree(p_addr);
}

bool cEnemyStatusChange::IsTypeCheckMaster(u32 type, u32 changeStatus) {
    if (type == 13) {
        return false;
    } else {
        if ((changeStatus - 1u) <= 8u) {
            return static_cast<bool>((94ul >> static_cast<unsigned long>(static_cast<unsigned char>(changeStatus + 255u) & 31)) & 1ul);
        } else {
            return true;
        }
    }
}

void cEnemyStatusChange::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupSubNo", &mGroupSubNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNextGroupSubNo", &mNextGroupSubNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNextGroupSubOneGo", &mNextGroupSubOneGo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "TypeSettingStatusChange", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "TypeReverse", &mTypeReverse, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSystemParam[0]", &mSystemParam[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSystemParam[1]", &mSystemParam[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSystemParam[2]", &mSystemParam[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRepeatSetting", &mRepeatSetting, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mChangeStatus", &mChangeStatus, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSelectNo", &mSelectNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBitContrlCommand", &mBitContrlCommand, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParam[0]", &mParam[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParam[1]", &mParam[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSystemParamWait", &mSystemParamWait, 0u, 0u);
}

inline cEnemyStatusChange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEnemyStatusChange::MyDTI cEnemyStatusChange::DTI("cEnemyStatusChange", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* cEnemyStatusChange::MyDTI::newInstance() const {
    return new (16u) cEnemyStatusChange;
}

const MtDTI& rEnemyStatusChange::getDTI() const {
    return rEnemyStatusChange::DTI;
}

inline void* rEnemyStatusChange::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rEnemyStatusChange::DTI)->memAlloc(sz, align, rEnemyStatusChange::DTI.getID());
}

inline void rEnemyStatusChange::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEnemyStatusChange::DTI)->memFree(p_addr);
}

bool rEnemyStatusChange::loadData(MtDataReader& in, cEnemyStatusChange* pData) {
    nDDOIO::readData(in, pData->mGroupNo);
    nDDOIO::readData(in, pData->mGroupSubNo);
    nDDOIO::readData(in, pData->mNextGroupSubNo);
    nDDOIO::readData(in, pData->mNextGroupSubOneGo);
    pData->mSelectNo = in.readU32();
    pData->mType = in.readU32();
    pData->mRepeatSetting = in.readU32();
    pData->mChangeStatus = in.readU32();
    pData->mSystemParamWait = in.readF32();
    pData->mParam[0] = in.readF32();
    pData->mParam[1] = in.readF32();
    pData->mSystemParam[0] = in.readF32();
    pData->mSystemParam[1] = in.readF32();
    pData->mSystemParam[2] = in.readF32();
    nDDOIO::readData(in, pData->mBitContrlCommand);
    nDDOIO::readData(in, pData->mTypeReverse);
    return true;
}

MT_CTSTR rEnemyStatusChange::getExt() const {
    return "est";
}

u32 rEnemyStatusChange::getDataVersion() const {
    return 9;
}

inline rEnemyStatusChange::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEnemyStatusChange::MyDTI rEnemyStatusChange::DTI("rEnemyStatusChange", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEnemyStatusChange::MyDTI::newInstance() const {
    return new (16u) rEnemyStatusChange;
}

template cEnemyStatusChange* rTbl2<cEnemyStatusChange>::getData(unsigned int);

template bool rTbl2<cEnemyStatusChange>::load(MtStream&);

template bool rTbl2<cEnemyStatusChange>::loadCore(MtDataReader&);

template const cEnemyStatusChange* rTbl2<cEnemyStatusChange>::getData(unsigned int) const;

template unsigned int rTbl2<cEnemyStatusChange>::getDataNum() const;

template rTbl2<cEnemyStatusChange>::~rTbl2();

