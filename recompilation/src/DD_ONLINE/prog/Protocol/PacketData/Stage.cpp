// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Stage.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataDropItemSetInfo::getDTI() const {
    return CDataDropItemSetInfo::DTI;
}

void* CDataDropItemSetInfo::operator new(size_t sz, u32 align) {
    return CDataDropItemSetInfo::getAllocator()->memAlloc(sz, align, CDataDropItemSetInfo::DTI.getID());
}

__attribute__((weak)) void CDataDropItemSetInfo::operator delete(void* p_addr) {
    CDataDropItemSetInfo::getAllocator()->memFree(p_addr);
}

inline CDataDropItemSetInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDropItemSetInfo::MyDTI CDataDropItemSetInfo::DTI("CDataDropItemSetInfo", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataDropItemSetInfo::MyDTI::newInstance() const {
    return new (16u) CDataDropItemSetInfo;
}

const MtDTI& CDataEncounterPawnInfo::getDTI() const {
    return CDataEncounterPawnInfo::DTI;
}

__attribute__((weak)) void CDataEncounterPawnInfo::operator delete(void* p_addr) {
    CDataEncounterPawnInfo::getAllocator()->memFree(p_addr);
}

inline CDataEncounterPawnInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataEncounterPawnInfo::MyDTI CDataEncounterPawnInfo::DTI("CDataEncounterPawnInfo", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataEncounterPawnInfo::MyDTI::newInstance() const {
    return new (16u) CDataEncounterPawnInfo;
}

const MtDTI& CDataGatheringItemElement::getDTI() const {
    return CDataGatheringItemElement::DTI;
}

void* CDataGatheringItemElement::operator new(size_t sz, u32 align) {
    return CDataGatheringItemElement::getAllocator()->memAlloc(sz, align, CDataGatheringItemElement::DTI.getID());
}

__attribute__((weak)) void CDataGatheringItemElement::operator delete(void* p_addr) {
    CDataGatheringItemElement::getAllocator()->memFree(p_addr);
}

inline CDataGatheringItemElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGatheringItemElement::MyDTI CDataGatheringItemElement::DTI("CDataGatheringItemElement", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataGatheringItemElement::MyDTI::newInstance() const {
    return new (16u) CDataGatheringItemElement;
}

const MtDTI& CDataGatheringItemGetRequest::getDTI() const {
    return CDataGatheringItemGetRequest::DTI;
}

void* CDataGatheringItemGetRequest::operator new(size_t sz, u32 align) {
    return CDataGatheringItemGetRequest::getAllocator()->memAlloc(sz, align, CDataGatheringItemGetRequest::DTI.getID());
}

__attribute__((weak)) void CDataGatheringItemGetRequest::operator delete(void* p_addr) {
    CDataGatheringItemGetRequest::getAllocator()->memFree(p_addr);
}

inline CDataGatheringItemGetRequest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGatheringItemGetRequest::MyDTI CDataGatheringItemGetRequest::DTI("CDataGatheringItemGetRequest", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataGatheringItemGetRequest::MyDTI::newInstance() const {
    return new (16u) CDataGatheringItemGetRequest;
}

const MtDTI& CDataLayoutEnemyData::getDTI() const {
    return CDataLayoutEnemyData::DTI;
}

void* CDataLayoutEnemyData::operator new(size_t sz, u32 align) {
    return CDataLayoutEnemyData::getAllocator()->memAlloc(sz, align, CDataLayoutEnemyData::DTI.getID());
}

__attribute__((weak)) void CDataLayoutEnemyData::operator delete(void* p_addr) {
    CDataLayoutEnemyData::getAllocator()->memFree(p_addr);
}

inline CDataLayoutEnemyData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLayoutEnemyData::MyDTI CDataLayoutEnemyData::DTI("CDataLayoutEnemyData", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

MtObject* CDataLayoutEnemyData::MyDTI::newInstance() const {
    return new (16u) CDataLayoutEnemyData;
}

const MtDTI& CDataLayoutItemData::getDTI() const {
    return CDataLayoutItemData::DTI;
}

void* CDataLayoutItemData::operator new(size_t sz, u32 align) {
    return CDataLayoutItemData::getAllocator()->memAlloc(sz, align, CDataLayoutItemData::DTI.getID());
}

__attribute__((weak)) void CDataLayoutItemData::operator delete(void* p_addr) {
    CDataLayoutItemData::getAllocator()->memFree(p_addr);
}

inline CDataLayoutItemData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLayoutItemData::MyDTI CDataLayoutItemData::DTI("CDataLayoutItemData", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataLayoutItemData::MyDTI::newInstance() const {
    return new (16u) CDataLayoutItemData;
}

const MtDTI& CDataOmData::getDTI() const {
    return CDataOmData::DTI;
}

void* CDataOmData::operator new(size_t sz, u32 align) {
    return CDataOmData::getAllocator()->memAlloc(sz, align, CDataOmData::DTI.getID());
}

__attribute__((weak)) void CDataOmData::operator delete(void* p_addr) {
    CDataOmData::getAllocator()->memFree(p_addr);
}

inline CDataOmData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataOmData::MyDTI CDataOmData::DTI("CDataOmData", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataOmData::MyDTI::newInstance() const {
    return new (16u) CDataOmData;
}

const MtDTI& CDataRandomStageInfo::getDTI() const {
    return CDataRandomStageInfo::DTI;
}

void* CDataRandomStageInfo::operator new(size_t sz, u32 align) {
    return CDataRandomStageInfo::getAllocator()->memAlloc(sz, align, CDataRandomStageInfo::DTI.getID());
}

__attribute__((weak)) void CDataRandomStageInfo::operator delete(void* p_addr) {
    CDataRandomStageInfo::getAllocator()->memFree(p_addr);
}

inline CDataRandomStageInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataRandomStageInfo::MyDTI CDataRandomStageInfo::DTI("CDataRandomStageInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataRandomStageInfo::MyDTI::newInstance() const {
    return new (16u) CDataRandomStageInfo;
}

const MtDTI& CDataStageAttribute::getDTI() const {
    return CDataStageAttribute::DTI;
}

__attribute__((weak)) void CDataStageAttribute::operator delete(void* p_addr) {
    CDataStageAttribute::getAllocator()->memFree(p_addr);
}

inline CDataStageAttribute::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataStageAttribute::MyDTI CDataStageAttribute::DTI("CDataStageAttribute", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataStageAttribute::MyDTI::newInstance() const {
    return new (16u) CDataStageAttribute;
}

const MtDTI& CDataStageInfo::getDTI() const {
    return CDataStageInfo::DTI;
}

void* CDataStageInfo::operator new(size_t sz, u32 align) {
    return CDataStageInfo::getAllocator()->memAlloc(sz, align, CDataStageInfo::DTI.getID());
}

__attribute__((weak)) void CDataStageInfo::operator delete(void* p_addr) {
    CDataStageInfo::getAllocator()->memFree(p_addr);
}

inline CDataStageInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataStageInfo::MyDTI CDataStageInfo::DTI("CDataStageInfo", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

MtObject* CDataStageInfo::MyDTI::newInstance() const {
    return new (16u) CDataStageInfo;
}

const MtDTI& CDataStageLayoutEnemyPresetEnemyInfoClient::getDTI() const {
    return CDataStageLayoutEnemyPresetEnemyInfoClient::DTI;
}

__attribute__((weak)) void CDataStageLayoutEnemyPresetEnemyInfoClient::operator delete(void* p_addr) {
    CDataStageLayoutEnemyPresetEnemyInfoClient::getAllocator()->memFree(p_addr);
}

inline CDataStageLayoutEnemyPresetEnemyInfoClient::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataStageLayoutEnemyPresetEnemyInfoClient::MyDTI CDataStageLayoutEnemyPresetEnemyInfoClient::DTI("CDataStageLayoutEnemyPresetEnemyInfoClient", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataStageLayoutEnemyPresetEnemyInfoClient::MyDTI::newInstance() const {
    return new (16u) CDataStageLayoutEnemyPresetEnemyInfoClient;
}

const MtDTI& CDataStageLayoutID::getDTI() const {
    return CDataStageLayoutID::DTI;
}

__attribute__((weak)) void CDataStageLayoutID::operator delete(void* p_addr) {
    CDataStageLayoutID::getAllocator()->memFree(p_addr);
}

inline CDataStageLayoutID::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataStageLayoutID::MyDTI CDataStageLayoutID::DTI("CDataStageLayoutID", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataStageLayoutID::MyDTI::newInstance() const {
    return new (16u) CDataStageLayoutID;
}

