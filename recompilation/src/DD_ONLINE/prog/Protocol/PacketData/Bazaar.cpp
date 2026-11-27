// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Bazaar.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataBazaarCharacterInfo::getDTI() const {
    return CDataBazaarCharacterInfo::DTI;
}

void* CDataBazaarCharacterInfo::operator new(size_t sz, u32 align) {
    return CDataBazaarCharacterInfo::getAllocator()->memAlloc(sz, align, CDataBazaarCharacterInfo::DTI.getID());
}

__attribute__((weak)) void CDataBazaarCharacterInfo::operator delete(void* p_addr) {
    CDataBazaarCharacterInfo::getAllocator()->memFree(p_addr);
}

inline CDataBazaarCharacterInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBazaarCharacterInfo::MyDTI CDataBazaarCharacterInfo::DTI("CDataBazaarCharacterInfo", &::CPacketDataBase::DTI, 80ul, 0u, 0u);

MtObject* CDataBazaarCharacterInfo::MyDTI::newInstance() const {
    return new (16u) CDataBazaarCharacterInfo;
}

const MtDTI& CDataBazaarItemBaseInfo::getDTI() const {
    return CDataBazaarItemBaseInfo::DTI;
}

__attribute__((weak)) void CDataBazaarItemBaseInfo::operator delete(void* p_addr) {
    CDataBazaarItemBaseInfo::getAllocator()->memFree(p_addr);
}

inline CDataBazaarItemBaseInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBazaarItemBaseInfo::MyDTI CDataBazaarItemBaseInfo::DTI("CDataBazaarItemBaseInfo", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataBazaarItemBaseInfo::MyDTI::newInstance() const {
    return new (16u) CDataBazaarItemBaseInfo;
}

const MtDTI& CDataBazaarItemHistoryInfo::getDTI() const {
    return CDataBazaarItemHistoryInfo::DTI;
}

void* CDataBazaarItemHistoryInfo::operator new(size_t sz, u32 align) {
    return CDataBazaarItemHistoryInfo::getAllocator()->memAlloc(sz, align, CDataBazaarItemHistoryInfo::DTI.getID());
}

__attribute__((weak)) void CDataBazaarItemHistoryInfo::operator delete(void* p_addr) {
    CDataBazaarItemHistoryInfo::getAllocator()->memFree(p_addr);
}

inline CDataBazaarItemHistoryInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBazaarItemHistoryInfo::MyDTI CDataBazaarItemHistoryInfo::DTI("CDataBazaarItemHistoryInfo", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataBazaarItemHistoryInfo::MyDTI::newInstance() const {
    return new (16u) CDataBazaarItemHistoryInfo;
}

const MtDTI& CDataBazaarItemInfo::getDTI() const {
    return CDataBazaarItemInfo::DTI;
}

void* CDataBazaarItemInfo::operator new(size_t sz, u32 align) {
    return CDataBazaarItemInfo::getAllocator()->memAlloc(sz, align, CDataBazaarItemInfo::DTI.getID());
}

__attribute__((weak)) void CDataBazaarItemInfo::operator delete(void* p_addr) {
    CDataBazaarItemInfo::getAllocator()->memFree(p_addr);
}

inline CDataBazaarItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBazaarItemInfo::MyDTI CDataBazaarItemInfo::DTI("CDataBazaarItemInfo", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

MtObject* CDataBazaarItemInfo::MyDTI::newInstance() const {
    return new (16u) CDataBazaarItemInfo;
}

const MtDTI& CDataBazaarItemNumOfExhibitionInfo::getDTI() const {
    return CDataBazaarItemNumOfExhibitionInfo::DTI;
}

void* CDataBazaarItemNumOfExhibitionInfo::operator new(size_t sz, u32 align) {
    return CDataBazaarItemNumOfExhibitionInfo::getAllocator()->memAlloc(sz, align, CDataBazaarItemNumOfExhibitionInfo::DTI.getID());
}

__attribute__((weak)) void CDataBazaarItemNumOfExhibitionInfo::operator delete(void* p_addr) {
    CDataBazaarItemNumOfExhibitionInfo::getAllocator()->memFree(p_addr);
}

inline CDataBazaarItemNumOfExhibitionInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBazaarItemNumOfExhibitionInfo::MyDTI CDataBazaarItemNumOfExhibitionInfo::DTI("CDataBazaarItemNumOfExhibitionInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataBazaarItemNumOfExhibitionInfo::MyDTI::newInstance() const {
    return new (16u) CDataBazaarItemNumOfExhibitionInfo;
}

