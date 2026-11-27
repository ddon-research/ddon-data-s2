// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Lobby.h"
#include "Community.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../../../MT/MtString.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataLobbyInfo::getDTI() const {
    return CDataLobbyInfo::DTI;
}

__attribute__((weak)) void CDataLobbyInfo::operator delete(void* p_addr) {
    CDataLobbyInfo::getAllocator()->memFree(p_addr);
}

inline CDataLobbyInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLobbyInfo::MyDTI CDataLobbyInfo::DTI("CDataLobbyInfo", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataLobbyInfo::MyDTI::newInstance() const {
    return new (16u) CDataLobbyInfo;
}

const MtDTI& CDataLobbyMemberInfo::getDTI() const {
    return CDataLobbyMemberInfo::DTI;
}

void* CDataLobbyMemberInfo::operator new(size_t sz, u32 align) {
    return CDataLobbyMemberInfo::getAllocator()->memAlloc(sz, align, CDataLobbyMemberInfo::DTI.getID());
}

__attribute__((weak)) void CDataLobbyMemberInfo::operator delete(void* p_addr) {
    CDataLobbyMemberInfo::getAllocator()->memFree(p_addr);
}

inline CDataLobbyMemberInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLobbyMemberInfo::MyDTI CDataLobbyMemberInfo::DTI("CDataLobbyMemberInfo", &::CPacketDataBase::DTI, 64ul, 0u, 0u);

MtObject* CDataLobbyMemberInfo::MyDTI::newInstance() const {
    return new (16u) CDataLobbyMemberInfo;
}

