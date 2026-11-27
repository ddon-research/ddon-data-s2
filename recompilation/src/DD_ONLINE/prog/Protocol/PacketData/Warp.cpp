// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Warp.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataAreaWarpPoint::getDTI() const {
    return CDataAreaWarpPoint::DTI;
}

void* CDataAreaWarpPoint::operator new(size_t sz, u32 align) {
    return CDataAreaWarpPoint::getAllocator()->memAlloc(sz, align, CDataAreaWarpPoint::DTI.getID());
}

__attribute__((weak)) void CDataAreaWarpPoint::operator delete(void* p_addr) {
    CDataAreaWarpPoint::getAllocator()->memFree(p_addr);
}

inline CDataAreaWarpPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAreaWarpPoint::MyDTI CDataAreaWarpPoint::DTI("CDataAreaWarpPoint", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataAreaWarpPoint::MyDTI::newInstance() const {
    return new (16u) CDataAreaWarpPoint;
}

const MtDTI& CDataFavoriteWarpPoint::getDTI() const {
    return CDataFavoriteWarpPoint::DTI;
}

void* CDataFavoriteWarpPoint::operator new(size_t sz, u32 align) {
    return CDataFavoriteWarpPoint::getAllocator()->memAlloc(sz, align, CDataFavoriteWarpPoint::DTI.getID());
}

__attribute__((weak)) void CDataFavoriteWarpPoint::operator delete(void* p_addr) {
    CDataFavoriteWarpPoint::getAllocator()->memFree(p_addr);
}

inline CDataFavoriteWarpPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataFavoriteWarpPoint::MyDTI CDataFavoriteWarpPoint::DTI("CDataFavoriteWarpPoint", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataFavoriteWarpPoint::MyDTI::newInstance() const {
    return new (16u) CDataFavoriteWarpPoint;
}

const MtDTI& CDataJumpLocation::getDTI() const {
    return CDataJumpLocation::DTI;
}

__attribute__((weak)) void CDataJumpLocation::operator delete(void* p_addr) {
    CDataJumpLocation::getAllocator()->memFree(p_addr);
}

inline CDataJumpLocation::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataJumpLocation::MyDTI CDataJumpLocation::DTI("CDataJumpLocation", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataJumpLocation::MyDTI::newInstance() const {
    return new (16u) CDataJumpLocation;
}

const MtDTI& CDataWarpPoint::getDTI() const {
    return CDataWarpPoint::DTI;
}

void* CDataWarpPoint::operator new(size_t sz, u32 align) {
    return CDataWarpPoint::getAllocator()->memAlloc(sz, align, CDataWarpPoint::DTI.getID());
}

__attribute__((weak)) void CDataWarpPoint::operator delete(void* p_addr) {
    CDataWarpPoint::getAllocator()->memFree(p_addr);
}

inline CDataWarpPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataWarpPoint::MyDTI CDataWarpPoint::DTI("CDataWarpPoint", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataWarpPoint::MyDTI::newInstance() const {
    return new (16u) CDataWarpPoint;
}

