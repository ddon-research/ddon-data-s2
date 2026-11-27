// Reconstructed from the game's DWARF debug information.
#include <new>
#include "QuickParty.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataQuickPartyMatching::getDTI() const {
    return CDataQuickPartyMatching::DTI;
}

__attribute__((weak)) void CDataQuickPartyMatching::operator delete(void* p_addr) {
    CDataQuickPartyMatching::getAllocator()->memFree(p_addr);
}

inline CDataQuickPartyMatching::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataQuickPartyMatching::MyDTI CDataQuickPartyMatching::DTI("CDataQuickPartyMatching", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataQuickPartyMatching::MyDTI::newInstance() const {
    return new (16u) CDataQuickPartyMatching;
}

