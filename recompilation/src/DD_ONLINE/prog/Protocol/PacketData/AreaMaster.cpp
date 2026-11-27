// Reconstructed from the game's DWARF debug information.
#include <new>
#include "AreaMaster.h"
#include "Common.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtMemoryAllocator.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataAreaBaseInfo::getDTI() const {
    return CDataAreaBaseInfo::DTI;
}

void* CDataAreaBaseInfo::operator new(size_t sz, u32 align) {
    return CDataAreaBaseInfo::getAllocator()->memAlloc(sz, align, CDataAreaBaseInfo::DTI.getID());
}

__attribute__((weak)) void CDataAreaBaseInfo::operator delete(void* p_addr) {
    CDataAreaBaseInfo::getAllocator()->memFree(p_addr);
}

inline CDataAreaBaseInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAreaBaseInfo::MyDTI CDataAreaBaseInfo::DTI("CDataAreaBaseInfo", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataAreaBaseInfo::MyDTI::newInstance() const {
    return new (16u) CDataAreaBaseInfo;
}

const MtDTI& CDataAreaQuestHint::getDTI() const {
    return CDataAreaQuestHint::DTI;
}

void* CDataAreaQuestHint::operator new(size_t sz, u32 align) {
    return CDataAreaQuestHint::getAllocator()->memAlloc(sz, align, CDataAreaQuestHint::DTI.getID());
}

__attribute__((weak)) void CDataAreaQuestHint::operator delete(void* p_addr) {
    CDataAreaQuestHint::getAllocator()->memFree(p_addr);
}

inline CDataAreaQuestHint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAreaQuestHint::MyDTI CDataAreaQuestHint::DTI("CDataAreaQuestHint", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataAreaQuestHint::MyDTI::newInstance() const {
    return new (16u) CDataAreaQuestHint;
}

const MtDTI& CDataAreaRank::getDTI() const {
    return CDataAreaRank::DTI;
}

void* CDataAreaRank::operator new(size_t sz, u32 align) {
    return CDataAreaRank::getAllocator()->memAlloc(sz, align, CDataAreaRank::DTI.getID());
}

__attribute__((weak)) void CDataAreaRank::operator delete(void* p_addr) {
    CDataAreaRank::getAllocator()->memFree(p_addr);
}

inline CDataAreaRank::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAreaRank::MyDTI CDataAreaRank::DTI("CDataAreaRank", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataAreaRank::MyDTI::newInstance() const {
    return new (16u) CDataAreaRank;
}

const MtDTI& CDataAreaRankUpQuestInfo::getDTI() const {
    return CDataAreaRankUpQuestInfo::DTI;
}

void* CDataAreaRankUpQuestInfo::operator new(size_t sz, u32 align) {
    return CDataAreaRankUpQuestInfo::getAllocator()->memAlloc(sz, align, CDataAreaRankUpQuestInfo::DTI.getID());
}

__attribute__((weak)) void CDataAreaRankUpQuestInfo::operator delete(void* p_addr) {
    CDataAreaRankUpQuestInfo::getAllocator()->memFree(p_addr);
}

inline CDataAreaRankUpQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAreaRankUpQuestInfo::MyDTI CDataAreaRankUpQuestInfo::DTI("CDataAreaRankUpQuestInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataAreaRankUpQuestInfo::MyDTI::newInstance() const {
    return new (16u) CDataAreaRankUpQuestInfo;
}

const MtDTI& CDataAreaSpotSet::getDTI() const {
    return CDataAreaSpotSet::DTI;
}

void* CDataAreaSpotSet::operator new(size_t sz, u32 align) {
    return CDataAreaSpotSet::getAllocator()->memAlloc(sz, align, CDataAreaSpotSet::DTI.getID());
}

__attribute__((weak)) void CDataAreaSpotSet::operator delete(void* p_addr) {
    CDataAreaSpotSet::getAllocator()->memFree(p_addr);
}

inline CDataAreaSpotSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAreaSpotSet::MyDTI CDataAreaSpotSet::DTI("CDataAreaSpotSet", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataAreaSpotSet::MyDTI::newInstance() const {
    return new (16u) CDataAreaSpotSet;
}

const MtDTI& CDataBorderSupplyItem::getDTI() const {
    return CDataBorderSupplyItem::DTI;
}

void* CDataBorderSupplyItem::operator new(size_t sz, u32 align) {
    return CDataBorderSupplyItem::getAllocator()->memAlloc(sz, align, CDataBorderSupplyItem::DTI.getID());
}

__attribute__((weak)) void CDataBorderSupplyItem::operator delete(void* p_addr) {
    CDataBorderSupplyItem::getAllocator()->memFree(p_addr);
}

inline CDataBorderSupplyItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataBorderSupplyItem::MyDTI CDataBorderSupplyItem::DTI("CDataBorderSupplyItem", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataBorderSupplyItem::MyDTI::newInstance() const {
    return new (16u) CDataBorderSupplyItem;
}

const MtDTI& CDataReleaseAreaInfoSet::getDTI() const {
    return CDataReleaseAreaInfoSet::DTI;
}

void* CDataReleaseAreaInfoSet::operator new(size_t sz, u32 align) {
    return CDataReleaseAreaInfoSet::getAllocator()->memAlloc(sz, align, CDataReleaseAreaInfoSet::DTI.getID());
}

__attribute__((weak)) void CDataReleaseAreaInfoSet::operator delete(void* p_addr) {
    CDataReleaseAreaInfoSet::getAllocator()->memFree(p_addr);
}

inline CDataReleaseAreaInfoSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataReleaseAreaInfoSet::MyDTI CDataReleaseAreaInfoSet::DTI("CDataReleaseAreaInfoSet", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataReleaseAreaInfoSet::MyDTI::newInstance() const {
    return new (16u) CDataReleaseAreaInfoSet;
}

const MtDTI& CDataRewardItemInfo::getDTI() const {
    return CDataRewardItemInfo::DTI;
}

void* CDataRewardItemInfo::operator new(size_t sz, u32 align) {
    return CDataRewardItemInfo::getAllocator()->memAlloc(sz, align, CDataRewardItemInfo::DTI.getID());
}

__attribute__((weak)) void CDataRewardItemInfo::operator delete(void* p_addr) {
    CDataRewardItemInfo::getAllocator()->memFree(p_addr);
}

inline CDataRewardItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataRewardItemInfo::MyDTI CDataRewardItemInfo::DTI("CDataRewardItemInfo", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataRewardItemInfo::MyDTI::newInstance() const {
    return new (16u) CDataRewardItemInfo;
}

const MtDTI& CDataSelectItemInfo::getDTI() const {
    return CDataSelectItemInfo::DTI;
}

void* CDataSelectItemInfo::operator new(size_t sz, u32 align) {
    return CDataSelectItemInfo::getAllocator()->memAlloc(sz, align, CDataSelectItemInfo::DTI.getID());
}

__attribute__((weak)) void CDataSelectItemInfo::operator delete(void* p_addr) {
    CDataSelectItemInfo::getAllocator()->memFree(p_addr);
}

inline CDataSelectItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSelectItemInfo::MyDTI CDataSelectItemInfo::DTI("CDataSelectItemInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataSelectItemInfo::MyDTI::newInstance() const {
    return new (16u) CDataSelectItemInfo;
}

const MtDTI& CDataSpotEnemyInfo::getDTI() const {
    return CDataSpotEnemyInfo::DTI;
}

void* CDataSpotEnemyInfo::operator new(size_t sz, u32 align) {
    return CDataSpotEnemyInfo::getAllocator()->memAlloc(sz, align, CDataSpotEnemyInfo::DTI.getID());
}

__attribute__((weak)) void CDataSpotEnemyInfo::operator delete(void* p_addr) {
    CDataSpotEnemyInfo::getAllocator()->memFree(p_addr);
}

inline CDataSpotEnemyInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSpotEnemyInfo::MyDTI CDataSpotEnemyInfo::DTI("CDataSpotEnemyInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataSpotEnemyInfo::MyDTI::newInstance() const {
    return new (16u) CDataSpotEnemyInfo;
}

const MtDTI& CDataSpotInfo::getDTI() const {
    return CDataSpotInfo::DTI;
}

void* CDataSpotInfo::operator new(size_t sz, u32 align) {
    return CDataSpotInfo::getAllocator()->memAlloc(sz, align, CDataSpotInfo::DTI.getID());
}

__attribute__((weak)) void CDataSpotInfo::operator delete(void* p_addr) {
    CDataSpotInfo::getAllocator()->memFree(p_addr);
}

inline CDataSpotInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSpotInfo::MyDTI CDataSpotInfo::DTI("CDataSpotInfo", &::CPacketDataBase::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataSpotInfo::MyDTI::newInstance() const {
    DDON_STUB("CDataSpotInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataSpotItemInfo::getDTI() const {
    return CDataSpotItemInfo::DTI;
}

void* CDataSpotItemInfo::operator new(size_t sz, u32 align) {
    return CDataSpotItemInfo::getAllocator()->memAlloc(sz, align, CDataSpotItemInfo::DTI.getID());
}

__attribute__((weak)) void CDataSpotItemInfo::operator delete(void* p_addr) {
    CDataSpotItemInfo::getAllocator()->memFree(p_addr);
}

inline CDataSpotItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSpotItemInfo::MyDTI CDataSpotItemInfo::DTI("CDataSpotItemInfo", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataSpotItemInfo::MyDTI::newInstance() const {
    return new (16u) CDataSpotItemInfo;
}

const MtDTI& CDataSupplyItem::getDTI() const {
    return CDataSupplyItem::DTI;
}

void* CDataSupplyItem::operator new(size_t sz, u32 align) {
    return CDataSupplyItem::getAllocator()->memAlloc(sz, align, CDataSupplyItem::DTI.getID());
}

__attribute__((weak)) void CDataSupplyItem::operator delete(void* p_addr) {
    CDataSupplyItem::getAllocator()->memFree(p_addr);
}

inline CDataSupplyItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSupplyItem::MyDTI CDataSupplyItem::DTI("CDataSupplyItem", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataSupplyItem::MyDTI::newInstance() const {
    return new (16u) CDataSupplyItem;
}

