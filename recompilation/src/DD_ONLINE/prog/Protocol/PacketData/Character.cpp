// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Character.h"
#include "CharacterEdit.h"
#include "Common.h"
#include "Community.h"
#include "GP.h"
#include "Item.h"
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

const MtDTI& CDataCharacterLevelParam::getDTI() const {
    return CDataCharacterLevelParam::DTI;
}

__attribute__((weak)) void CDataCharacterLevelParam::operator delete(void* p_addr) {
    CDataCharacterLevelParam::getAllocator()->memFree(p_addr);
}

inline CDataCharacterLevelParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCharacterLevelParam::MyDTI CDataCharacterLevelParam::DTI("CDataCharacterLevelParam", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataCharacterLevelParam::MyDTI::newInstance() const {
    return new (16u) CDataCharacterLevelParam;
}

const MtDTI& CDataCharacterListInfo::getDTI() const {
    return CDataCharacterListInfo::DTI;
}

void* CDataCharacterListInfo::operator new(size_t sz, u32 align) {
    return CDataCharacterListInfo::getAllocator()->memAlloc(sz, align, CDataCharacterListInfo::DTI.getID());
}

__attribute__((weak)) void CDataCharacterListInfo::operator delete(void* p_addr) {
    CDataCharacterListInfo::getAllocator()->memFree(p_addr);
}

inline CDataCharacterListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCharacterListInfo::MyDTI CDataCharacterListInfo::DTI("CDataCharacterListInfo", &::CPacketDataBase::DTI, 400ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataCharacterListInfo::MyDTI::newInstance() const {
    DDON_STUB("CDataCharacterListInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataCharacterMessage::getDTI() const {
    return CDataCharacterMessage::DTI;
}

void* CDataCharacterMessage::operator new(size_t sz, u32 align) {
    return CDataCharacterMessage::getAllocator()->memAlloc(sz, align, CDataCharacterMessage::DTI.getID());
}

__attribute__((weak)) void CDataCharacterMessage::operator delete(void* p_addr) {
    CDataCharacterMessage::getAllocator()->memFree(p_addr);
}

inline CDataCharacterMessage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCharacterMessage::MyDTI CDataCharacterMessage::DTI("CDataCharacterMessage", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataCharacterMessage::MyDTI::newInstance() const {
    return new (16u) CDataCharacterMessage;
}

const MtDTI& CDataCharacterMsgSet::getDTI() const {
    return CDataCharacterMsgSet::DTI;
}

void* CDataCharacterMsgSet::operator new(size_t sz, u32 align) {
    return CDataCharacterMsgSet::getAllocator()->memAlloc(sz, align, CDataCharacterMsgSet::DTI.getID());
}

__attribute__((weak)) void CDataCharacterMsgSet::operator delete(void* p_addr) {
    CDataCharacterMsgSet::getAllocator()->memFree(p_addr);
}

inline CDataCharacterMsgSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCharacterMsgSet::MyDTI CDataCharacterMsgSet::DTI("CDataCharacterMsgSet", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

MtObject* CDataCharacterMsgSet::MyDTI::newInstance() const {
    return new (16u) CDataCharacterMsgSet;
}

const MtDTI& CDataCharacterReleaseElement::getDTI() const {
    return CDataCharacterReleaseElement::DTI;
}

void* CDataCharacterReleaseElement::operator new(size_t sz, u32 align) {
    return CDataCharacterReleaseElement::getAllocator()->memAlloc(sz, align, CDataCharacterReleaseElement::DTI.getID());
}

__attribute__((weak)) void CDataCharacterReleaseElement::operator delete(void* p_addr) {
    CDataCharacterReleaseElement::getAllocator()->memFree(p_addr);
}

inline CDataCharacterReleaseElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCharacterReleaseElement::MyDTI CDataCharacterReleaseElement::DTI("CDataCharacterReleaseElement", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataCharacterReleaseElement::MyDTI::newInstance() const {
    return new (16u) CDataCharacterReleaseElement;
}

const MtDTI& CDataCharacterSearchParam::getDTI() const {
    return CDataCharacterSearchParam::DTI;
}

__attribute__((weak)) void CDataCharacterSearchParam::operator delete(void* p_addr) {
    CDataCharacterSearchParam::getAllocator()->memFree(p_addr);
}

inline CDataCharacterSearchParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCharacterSearchParam::MyDTI CDataCharacterSearchParam::DTI("CDataCharacterSearchParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCharacterSearchParam::MyDTI::newInstance() const {
    return new (16u) CDataCharacterSearchParam;
}

const MtDTI& CDataCommunicationShortCut::getDTI() const {
    return CDataCommunicationShortCut::DTI;
}

void* CDataCommunicationShortCut::operator new(size_t sz, u32 align) {
    return CDataCommunicationShortCut::getAllocator()->memAlloc(sz, align, CDataCommunicationShortCut::DTI.getID());
}

__attribute__((weak)) void CDataCommunicationShortCut::operator delete(void* p_addr) {
    CDataCommunicationShortCut::getAllocator()->memFree(p_addr);
}

inline CDataCommunicationShortCut::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCommunicationShortCut::MyDTI CDataCommunicationShortCut::DTI("CDataCommunicationShortCut", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCommunicationShortCut::MyDTI::newInstance() const {
    return new (16u) CDataCommunicationShortCut;
}

const MtDTI& CDataEditParts::getDTI() const {
    return CDataEditParts::DTI;
}

void* CDataEditParts::operator new(size_t sz, u32 align) {
    return CDataEditParts::getAllocator()->memAlloc(sz, align, CDataEditParts::DTI.getID());
}

__attribute__((weak)) void CDataEditParts::operator delete(void* p_addr) {
    CDataEditParts::getAllocator()->memFree(p_addr);
}

inline CDataEditParts::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataEditParts::MyDTI CDataEditParts::DTI("CDataEditParts", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataEditParts::MyDTI::newInstance() const {
    return new (16u) CDataEditParts;
}

const MtDTI& CDataHistoryElement::getDTI() const {
    return CDataHistoryElement::DTI;
}

void* CDataHistoryElement::operator new(size_t sz, u32 align) {
    return CDataHistoryElement::getAllocator()->memAlloc(sz, align, CDataHistoryElement::DTI.getID());
}

__attribute__((weak)) void CDataHistoryElement::operator delete(void* p_addr) {
    CDataHistoryElement::getAllocator()->memFree(p_addr);
}

inline CDataHistoryElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataHistoryElement::MyDTI CDataHistoryElement::DTI("CDataHistoryElement", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataHistoryElement::MyDTI::newInstance() const {
    return new (16u) CDataHistoryElement;
}

const MtDTI& CDataItemStorageIndicateNum::getDTI() const {
    return CDataItemStorageIndicateNum::DTI;
}

void* CDataItemStorageIndicateNum::operator new(size_t sz, u32 align) {
    return CDataItemStorageIndicateNum::getAllocator()->memAlloc(sz, align, CDataItemStorageIndicateNum::DTI.getID());
}

inline CDataItemStorageIndicateNum::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataItemStorageIndicateNum::MyDTI CDataItemStorageIndicateNum::DTI("CDataItemStorageIndicateNum", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataItemStorageIndicateNum::MyDTI::newInstance() const {
    return new (16u) CDataItemStorageIndicateNum;
}

const MtDTI& CDataMasterInfo::getDTI() const {
    return CDataMasterInfo::DTI;
}

void* CDataMasterInfo::operator new(size_t sz, u32 align) {
    return CDataMasterInfo::getAllocator()->memAlloc(sz, align, CDataMasterInfo::DTI.getID());
}

__attribute__((weak)) void CDataMasterInfo::operator delete(void* p_addr) {
    CDataMasterInfo::getAllocator()->memFree(p_addr);
}

inline CDataMasterInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataMasterInfo::MyDTI CDataMasterInfo::DTI("CDataMasterInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataMasterInfo::MyDTI::newInstance() const {
    return new (16u) CDataMasterInfo;
}

const MtDTI& CDataMatchingProfile::getDTI() const {
    return CDataMatchingProfile::DTI;
}

__attribute__((weak)) void CDataMatchingProfile::operator delete(void* p_addr) {
    CDataMatchingProfile::getAllocator()->memFree(p_addr);
}

inline CDataMatchingProfile::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataMatchingProfile::MyDTI CDataMatchingProfile::DTI("CDataMatchingProfile", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

MtObject* CDataMatchingProfile::MyDTI::newInstance() const {
    return new (16u) CDataMatchingProfile;
}

const MtDTI& CDataMyRoomOption::getDTI() const {
    return CDataMyRoomOption::DTI;
}

__attribute__((weak)) void CDataMyRoomOption::operator delete(void* p_addr) {
    CDataMyRoomOption::getAllocator()->memFree(p_addr);
}

inline CDataMyRoomOption::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataMyRoomOption::MyDTI CDataMyRoomOption::DTI("CDataMyRoomOption", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataMyRoomOption::MyDTI::newInstance() const {
    return new (16u) CDataMyRoomOption;
}

const MtDTI& CDataShortCut::getDTI() const {
    return CDataShortCut::DTI;
}

void* CDataShortCut::operator new(size_t sz, u32 align) {
    return CDataShortCut::getAllocator()->memAlloc(sz, align, CDataShortCut::DTI.getID());
}

__attribute__((weak)) void CDataShortCut::operator delete(void* p_addr) {
    CDataShortCut::getAllocator()->memFree(p_addr);
}

inline CDataShortCut::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataShortCut::MyDTI CDataShortCut::DTI("CDataShortCut", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataShortCut::MyDTI::newInstance() const {
    return new (16u) CDataShortCut;
}

const MtDTI& CDataUnlockEmotion::getDTI() const {
    return CDataUnlockEmotion::DTI;
}

void* CDataUnlockEmotion::operator new(size_t sz, u32 align) {
    return CDataUnlockEmotion::getAllocator()->memAlloc(sz, align, CDataUnlockEmotion::DTI.getID());
}

__attribute__((weak)) void CDataUnlockEmotion::operator delete(void* p_addr) {
    CDataUnlockEmotion::getAllocator()->memFree(p_addr);
}

inline CDataUnlockEmotion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataUnlockEmotion::MyDTI CDataUnlockEmotion::DTI("CDataUnlockEmotion", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataUnlockEmotion::MyDTI::newInstance() const {
    return new (16u) CDataUnlockEmotion;
}

const MtDTI& CDataUpdateWalletPoint::getDTI() const {
    return CDataUpdateWalletPoint::DTI;
}

void* CDataUpdateWalletPoint::operator new(size_t sz, u32 align) {
    return CDataUpdateWalletPoint::getAllocator()->memAlloc(sz, align, CDataUpdateWalletPoint::DTI.getID());
}

__attribute__((weak)) void CDataUpdateWalletPoint::operator delete(void* p_addr) {
    CDataUpdateWalletPoint::getAllocator()->memFree(p_addr);
}

inline CDataUpdateWalletPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataUpdateWalletPoint::MyDTI CDataUpdateWalletPoint::DTI("CDataUpdateWalletPoint", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataUpdateWalletPoint::MyDTI::newInstance() const {
    DDON_STUB("CDataUpdateWalletPoint::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataWalletPoint::getDTI() const {
    return CDataWalletPoint::DTI;
}

void* CDataWalletPoint::operator new(size_t sz, u32 align) {
    return CDataWalletPoint::getAllocator()->memAlloc(sz, align, CDataWalletPoint::DTI.getID());
}

__attribute__((weak)) void CDataWalletPoint::operator delete(void* p_addr) {
    CDataWalletPoint::getAllocator()->memFree(p_addr);
}

inline CDataWalletPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataWalletPoint::MyDTI CDataWalletPoint::DTI("CDataWalletPoint", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataWalletPoint::MyDTI::newInstance() const {
    return new (16u) CDataWalletPoint;
}

