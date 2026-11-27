// Reconstructed from the game's DWARF debug information.
#include <new>
#include "CharacterItem.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataSwitchStorage::getDTI() const {
    return CDataSwitchStorage::DTI;
}

void* CDataSwitchStorage::operator new(size_t sz, u32 align) {
    return CDataSwitchStorage::getAllocator()->memAlloc(sz, align, CDataSwitchStorage::DTI.getID());
}

__attribute__((weak)) void CDataSwitchStorage::operator delete(void* p_addr) {
    CDataSwitchStorage::getAllocator()->memFree(p_addr);
}

inline CDataSwitchStorage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSwitchStorage::MyDTI CDataSwitchStorage::DTI("CDataSwitchStorage", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataSwitchStorage::MyDTI::newInstance() const {
    return new (16u) CDataSwitchStorage;
}

