// Reconstructed from the game's DWARF debug information.
#include <new>
#include "BoxGacha.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtMemoryAllocator.h"
#include "../../../../MT/MtObject.h"
#include "../../../../MT/MtString.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataBoxGachaInfo::getDTI() const {
    return CDataBoxGachaInfo::DTI;
}

void* CDataBoxGachaInfo::operator new(size_t sz, u32 align) {
    return CDataBoxGachaInfo::getAllocator()->memAlloc(sz, align, CDataBoxGachaInfo::DTI.getID());
}

__attribute__((weak)) void CDataBoxGachaInfo::operator delete(void* p_addr) {
    CDataBoxGachaInfo::getAllocator()->memFree(p_addr);
}

inline CDataBoxGachaInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBoxGachaInfo::MyDTI CDataBoxGachaInfo::DTI("CDataBoxGachaInfo", &::CPacketDataBase::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataBoxGachaInfo::MyDTI::newInstance() const {
    DDON_STUB("CDataBoxGachaInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataBoxGachaItemInfo::getDTI() const {
    return CDataBoxGachaItemInfo::DTI;
}

void* CDataBoxGachaItemInfo::operator new(size_t sz, u32 align) {
    return CDataBoxGachaItemInfo::getAllocator()->memAlloc(sz, align, CDataBoxGachaItemInfo::DTI.getID());
}

__attribute__((weak)) void CDataBoxGachaItemInfo::operator delete(void* p_addr) {
    CDataBoxGachaItemInfo::getAllocator()->memFree(p_addr);
}

inline CDataBoxGachaItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBoxGachaItemInfo::MyDTI CDataBoxGachaItemInfo::DTI("CDataBoxGachaItemInfo", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataBoxGachaItemInfo::MyDTI::newInstance() const {
    return new (16u) CDataBoxGachaItemInfo;
}

const MtDTI& CDataBoxGachaSettlementInfo::getDTI() const {
    return CDataBoxGachaSettlementInfo::DTI;
}

void* CDataBoxGachaSettlementInfo::operator new(size_t sz, u32 align) {
    return CDataBoxGachaSettlementInfo::getAllocator()->memAlloc(sz, align, CDataBoxGachaSettlementInfo::DTI.getID());
}

__attribute__((weak)) void CDataBoxGachaSettlementInfo::operator delete(void* p_addr) {
    CDataBoxGachaSettlementInfo::getAllocator()->memFree(p_addr);
}

inline CDataBoxGachaSettlementInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBoxGachaSettlementInfo::MyDTI CDataBoxGachaSettlementInfo::DTI("CDataBoxGachaSettlementInfo", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataBoxGachaSettlementInfo::MyDTI::newInstance() const {
    return new (16u) CDataBoxGachaSettlementInfo;
}

