// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Community.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtMemoryAllocator.h"
#include "../../../../MT/MtObject.h"
#include "../../../../MT/MtString.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataCharacterListElement::getDTI() const {
    return CDataCharacterListElement::DTI;
}

void* CDataCharacterListElement::operator new(size_t sz, u32 align) {
    return CDataCharacterListElement::getAllocator()->memAlloc(sz, align, CDataCharacterListElement::DTI.getID());
}

__attribute__((weak)) void CDataCharacterListElement::operator delete(void* p_addr) {
    CDataCharacterListElement::getAllocator()->memFree(p_addr);
}

inline CDataCharacterListElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCharacterListElement::MyDTI CDataCharacterListElement::DTI("CDataCharacterListElement", &::CPacketDataBase::DTI, 104ul, 0u, 0u);

MtObject* CDataCharacterListElement::MyDTI::newInstance() const {
    return new (16u) CDataCharacterListElement;
}

const MtDTI& CDataCharacterName::getDTI() const {
    return CDataCharacterName::DTI;
}

__attribute__((weak)) void CDataCharacterName::operator delete(void* p_addr) {
    CDataCharacterName::getAllocator()->memFree(p_addr);
}

CDataCharacterName::CDataCharacterName(const char* in_strFirstName, const char* in_strLastName) {
    DDON_STUB("CDataCharacterName::CDataCharacterName")
    /* stub */
}

inline CDataCharacterName::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCharacterName::MyDTI CDataCharacterName::DTI("CDataCharacterName", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCharacterName::MyDTI::newInstance() const {
    return new (16u) CDataCharacterName;
}

const MtDTI& CDataCommunityCharacterBaseInfo::getDTI() const {
    return CDataCommunityCharacterBaseInfo::DTI;
}

void* CDataCommunityCharacterBaseInfo::operator new(size_t sz, u32 align) {
    return CDataCommunityCharacterBaseInfo::getAllocator()->memAlloc(sz, align, CDataCommunityCharacterBaseInfo::DTI.getID());
}

__attribute__((weak)) void CDataCommunityCharacterBaseInfo::operator delete(void* p_addr) {
    CDataCommunityCharacterBaseInfo::getAllocator()->memFree(p_addr);
}

inline CDataCommunityCharacterBaseInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCommunityCharacterBaseInfo::MyDTI CDataCommunityCharacterBaseInfo::DTI("CDataCommunityCharacterBaseInfo", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataCommunityCharacterBaseInfo::MyDTI::newInstance() const {
    return new (16u) CDataCommunityCharacterBaseInfo;
}

const MtDTI& CDataFriendInfo::getDTI() const {
    return CDataFriendInfo::DTI;
}

void* CDataFriendInfo::operator new(size_t sz, u32 align) {
    return CDataFriendInfo::getAllocator()->memAlloc(sz, align, CDataFriendInfo::DTI.getID());
}

__attribute__((weak)) void CDataFriendInfo::operator delete(void* p_addr) {
    CDataFriendInfo::getAllocator()->memFree(p_addr);
}

inline CDataFriendInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataFriendInfo::MyDTI CDataFriendInfo::DTI("CDataFriendInfo", &::CPacketDataBase::DTI, 128ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataFriendInfo::MyDTI::newInstance() const {
    DDON_STUB("CDataFriendInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataJobBaseInfo::getDTI() const {
    return CDataJobBaseInfo::DTI;
}

void* CDataJobBaseInfo::operator new(size_t sz, u32 align) {
    return CDataJobBaseInfo::getAllocator()->memAlloc(sz, align, CDataJobBaseInfo::DTI.getID());
}

__attribute__((weak)) void CDataJobBaseInfo::operator delete(void* p_addr) {
    CDataJobBaseInfo::getAllocator()->memFree(p_addr);
}

inline CDataJobBaseInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataJobBaseInfo::MyDTI CDataJobBaseInfo::DTI("CDataJobBaseInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataJobBaseInfo::MyDTI::newInstance() const {
    return new (16u) CDataJobBaseInfo;
}

const MtDTI& CDataUpdateMatchingProfileInfo::getDTI() const {
    return CDataUpdateMatchingProfileInfo::DTI;
}

void* CDataUpdateMatchingProfileInfo::operator new(size_t sz, u32 align) {
    return CDataUpdateMatchingProfileInfo::getAllocator()->memAlloc(sz, align, CDataUpdateMatchingProfileInfo::DTI.getID());
}

__attribute__((weak)) void CDataUpdateMatchingProfileInfo::operator delete(void* p_addr) {
    CDataUpdateMatchingProfileInfo::getAllocator()->memFree(p_addr);
}

inline CDataUpdateMatchingProfileInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataUpdateMatchingProfileInfo::MyDTI CDataUpdateMatchingProfileInfo::DTI("CDataUpdateMatchingProfileInfo", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataUpdateMatchingProfileInfo::MyDTI::newInstance() const {
    return new (16u) CDataUpdateMatchingProfileInfo;
}

