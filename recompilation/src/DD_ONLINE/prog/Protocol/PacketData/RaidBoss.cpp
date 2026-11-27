// Reconstructed from the game's DWARF debug information.
#include <new>
#include "RaidBoss.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataRaidBossRegionInfo::getDTI() const {
    return CDataRaidBossRegionInfo::DTI;
}

void* CDataRaidBossRegionInfo::operator new(size_t sz, u32 align) {
    return CDataRaidBossRegionInfo::getAllocator()->memAlloc(sz, align, CDataRaidBossRegionInfo::DTI.getID());
}

__attribute__((weak)) void CDataRaidBossRegionInfo::operator delete(void* p_addr) {
    CDataRaidBossRegionInfo::getAllocator()->memFree(p_addr);
}

inline CDataRaidBossRegionInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataRaidBossRegionInfo::MyDTI CDataRaidBossRegionInfo::DTI("CDataRaidBossRegionInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataRaidBossRegionInfo::MyDTI::newInstance() const {
    return new (16u) CDataRaidBossRegionInfo;
}

const MtDTI& CDataRaidBossUnitInfo::getDTI() const {
    return CDataRaidBossUnitInfo::DTI;
}

__attribute__((weak)) void CDataRaidBossUnitInfo::operator delete(void* p_addr) {
    CDataRaidBossUnitInfo::getAllocator()->memFree(p_addr);
}

inline CDataRaidBossUnitInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataRaidBossUnitInfo::MyDTI CDataRaidBossUnitInfo::DTI("CDataRaidBossUnitInfo", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataRaidBossUnitInfo::MyDTI::newInstance() const {
    return new (16u) CDataRaidBossUnitInfo;
}

