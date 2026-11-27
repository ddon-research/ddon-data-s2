// Reconstructed from the game's DWARF debug information.
#include <new>
#include "GP.h"
#include "Common.h"
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

const MtDTI& CDataCAPtoGPChangeElement::getDTI() const {
    return CDataCAPtoGPChangeElement::DTI;
}

void* CDataCAPtoGPChangeElement::operator new(size_t sz, u32 align) {
    return CDataCAPtoGPChangeElement::getAllocator()->memAlloc(sz, align, CDataCAPtoGPChangeElement::DTI.getID());
}

__attribute__((weak)) void CDataCAPtoGPChangeElement::operator delete(void* p_addr) {
    CDataCAPtoGPChangeElement::getAllocator()->memFree(p_addr);
}

inline CDataCAPtoGPChangeElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCAPtoGPChangeElement::MyDTI CDataCAPtoGPChangeElement::DTI("CDataCAPtoGPChangeElement", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataCAPtoGPChangeElement::MyDTI::newInstance() const {
    return new (16u) CDataCAPtoGPChangeElement;
}

const MtDTI& CDataGPCourseAvailable::getDTI() const {
    return CDataGPCourseAvailable::DTI;
}

void* CDataGPCourseAvailable::operator new(size_t sz, u32 align) {
    return CDataGPCourseAvailable::getAllocator()->memAlloc(sz, align, CDataGPCourseAvailable::DTI.getID());
}

__attribute__((weak)) void CDataGPCourseAvailable::operator delete(void* p_addr) {
    CDataGPCourseAvailable::getAllocator()->memFree(p_addr);
}

inline CDataGPCourseAvailable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPCourseAvailable::MyDTI CDataGPCourseAvailable::DTI("CDataGPCourseAvailable", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataGPCourseAvailable::MyDTI::newInstance() const {
    return new (16u) CDataGPCourseAvailable;
}

const MtDTI& CDataGPCourseEffectParam::getDTI() const {
    return CDataGPCourseEffectParam::DTI;
}

void* CDataGPCourseEffectParam::operator new(size_t sz, u32 align) {
    return CDataGPCourseEffectParam::getAllocator()->memAlloc(sz, align, CDataGPCourseEffectParam::DTI.getID());
}

__attribute__((weak)) void CDataGPCourseEffectParam::operator delete(void* p_addr) {
    CDataGPCourseEffectParam::getAllocator()->memFree(p_addr);
}

inline CDataGPCourseEffectParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPCourseEffectParam::MyDTI CDataGPCourseEffectParam::DTI("CDataGPCourseEffectParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataGPCourseEffectParam::MyDTI::newInstance() const {
    return new (16u) CDataGPCourseEffectParam;
}

const MtDTI& CDataGPCourseInfo::getDTI() const {
    return CDataGPCourseInfo::DTI;
}

void* CDataGPCourseInfo::operator new(size_t sz, u32 align) {
    return CDataGPCourseInfo::getAllocator()->memAlloc(sz, align, CDataGPCourseInfo::DTI.getID());
}

__attribute__((weak)) void CDataGPCourseInfo::operator delete(void* p_addr) {
    CDataGPCourseInfo::getAllocator()->memFree(p_addr);
}

inline CDataGPCourseInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPCourseInfo::MyDTI CDataGPCourseInfo::DTI("CDataGPCourseInfo", &::CPacketDataBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataGPCourseInfo::MyDTI::newInstance() const {
    DDON_STUB("CDataGPCourseInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataGPCourseValid::getDTI() const {
    return CDataGPCourseValid::DTI;
}

void* CDataGPCourseValid::operator new(size_t sz, u32 align) {
    return CDataGPCourseValid::getAllocator()->memAlloc(sz, align, CDataGPCourseValid::DTI.getID());
}

__attribute__((weak)) void CDataGPCourseValid::operator delete(void* p_addr) {
    CDataGPCourseValid::getAllocator()->memFree(p_addr);
}

inline CDataGPCourseValid::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPCourseValid::MyDTI CDataGPCourseValid::DTI("CDataGPCourseValid", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataGPCourseValid::MyDTI::newInstance() const {
    return new (16u) CDataGPCourseValid;
}

const MtDTI& CDataGPDetail::getDTI() const {
    return CDataGPDetail::DTI;
}

void* CDataGPDetail::operator new(size_t sz, u32 align) {
    return CDataGPDetail::getAllocator()->memAlloc(sz, align, CDataGPDetail::DTI.getID());
}

__attribute__((weak)) void CDataGPDetail::operator delete(void* p_addr) {
    CDataGPDetail::getAllocator()->memFree(p_addr);
}

inline CDataGPDetail::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPDetail::MyDTI CDataGPDetail::DTI("CDataGPDetail", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataGPDetail::MyDTI::newInstance() const {
    DDON_STUB("CDataGPDetail::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataGPEditVoiceBuyHistory::getDTI() const {
    return CDataGPEditVoiceBuyHistory::DTI;
}

void* CDataGPEditVoiceBuyHistory::operator new(size_t sz, u32 align) {
    return CDataGPEditVoiceBuyHistory::getAllocator()->memAlloc(sz, align, CDataGPEditVoiceBuyHistory::DTI.getID());
}

__attribute__((weak)) void CDataGPEditVoiceBuyHistory::operator delete(void* p_addr) {
    CDataGPEditVoiceBuyHistory::getAllocator()->memFree(p_addr);
}

inline CDataGPEditVoiceBuyHistory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPEditVoiceBuyHistory::MyDTI CDataGPEditVoiceBuyHistory::DTI("CDataGPEditVoiceBuyHistory", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataGPEditVoiceBuyHistory::MyDTI::newInstance() const {
    return new (16u) CDataGPEditVoiceBuyHistory;
}

const MtDTI& CDataGPPeriod::getDTI() const {
    return CDataGPPeriod::DTI;
}

void* CDataGPPeriod::operator new(size_t sz, u32 align) {
    return CDataGPPeriod::getAllocator()->memAlloc(sz, align, CDataGPPeriod::DTI.getID());
}

__attribute__((weak)) void CDataGPPeriod::operator delete(void* p_addr) {
    CDataGPPeriod::getAllocator()->memFree(p_addr);
}

inline CDataGPPeriod::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPPeriod::MyDTI CDataGPPeriod::DTI("CDataGPPeriod", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataGPPeriod::MyDTI::newInstance() const {
    return new (16u) CDataGPPeriod;
}

const MtDTI& CDataGPShopBuyHistoryElement::getDTI() const {
    return CDataGPShopBuyHistoryElement::DTI;
}

void* CDataGPShopBuyHistoryElement::operator new(size_t sz, u32 align) {
    return CDataGPShopBuyHistoryElement::getAllocator()->memAlloc(sz, align, CDataGPShopBuyHistoryElement::DTI.getID());
}

__attribute__((weak)) void CDataGPShopBuyHistoryElement::operator delete(void* p_addr) {
    CDataGPShopBuyHistoryElement::getAllocator()->memFree(p_addr);
}

inline CDataGPShopBuyHistoryElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPShopBuyHistoryElement::MyDTI CDataGPShopBuyHistoryElement::DTI("CDataGPShopBuyHistoryElement", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataGPShopBuyHistoryElement::MyDTI::newInstance() const {
    return new (16u) CDataGPShopBuyHistoryElement;
}

const MtDTI& CDataGPShopDisplayLineup::getDTI() const {
    return CDataGPShopDisplayLineup::DTI;
}

void* CDataGPShopDisplayLineup::operator new(size_t sz, u32 align) {
    return CDataGPShopDisplayLineup::getAllocator()->memAlloc(sz, align, CDataGPShopDisplayLineup::DTI.getID());
}

__attribute__((weak)) void CDataGPShopDisplayLineup::operator delete(void* p_addr) {
    CDataGPShopDisplayLineup::getAllocator()->memFree(p_addr);
}

CDataGPShopDisplayLineup::CDataGPShopDisplayLineup(u32 in_ID, u32 in_Category, u8 in_IconId, u32 in_GP, u32 in_DiscountType, u32 in_DiscountGP, const char* in_strName, const char* in_strComment, u32 in_LineupID, u32 in_BackIconID, u32 in_FrameIconID, u32 in_BehaviorAfterBuyingType) {
    DDON_STUB("CDataGPShopDisplayLineup::CDataGPShopDisplayLineup")
    /* stub */
}

inline CDataGPShopDisplayLineup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPShopDisplayLineup::MyDTI CDataGPShopDisplayLineup::DTI("CDataGPShopDisplayLineup", &::CPacketDataBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataGPShopDisplayLineup::MyDTI::newInstance() const {
    DDON_STUB("CDataGPShopDisplayLineup::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataGPShopDisplayType::getDTI() const {
    return CDataGPShopDisplayType::DTI;
}

void* CDataGPShopDisplayType::operator new(size_t sz, u32 align) {
    return CDataGPShopDisplayType::getAllocator()->memAlloc(sz, align, CDataGPShopDisplayType::DTI.getID());
}

__attribute__((weak)) void CDataGPShopDisplayType::operator delete(void* p_addr) {
    CDataGPShopDisplayType::getAllocator()->memFree(p_addr);
}

inline CDataGPShopDisplayType::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPShopDisplayType::MyDTI CDataGPShopDisplayType::DTI("CDataGPShopDisplayType", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataGPShopDisplayType::MyDTI::newInstance() const {
    return new (16u) CDataGPShopDisplayType;
}

const MtDTI& CDataGPShopLineupElementBase::getDTI() const {
    return CDataGPShopLineupElementBase::DTI;
}

__attribute__((weak)) void CDataGPShopLineupElementBase::operator delete(void* p_addr) {
    CDataGPShopLineupElementBase::getAllocator()->memFree(p_addr);
}

inline CDataGPShopLineupElementBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPShopLineupElementBase::MyDTI CDataGPShopLineupElementBase::DTI("CDataGPShopLineupElementBase", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

MtObject* CDataGPShopLineupElementBase::MyDTI::newInstance() const {
    return new (16u) CDataGPShopLineupElementBase;
}

const MtDTI& CDataGPShopLineupElementCourse::getDTI() const {
    return CDataGPShopLineupElementCourse::DTI;
}

void* CDataGPShopLineupElementCourse::operator new(size_t sz, u32 align) {
    return CDataGPShopLineupElementCourse::getAllocator()->memAlloc(sz, align, CDataGPShopLineupElementCourse::DTI.getID());
}

__attribute__((weak)) void CDataGPShopLineupElementCourse::operator delete(void* p_addr) {
    CDataGPShopLineupElementCourse::getAllocator()->memFree(p_addr);
}

inline CDataGPShopLineupElementCourse::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPShopLineupElementCourse::MyDTI CDataGPShopLineupElementCourse::DTI("CDataGPShopLineupElementCourse", &::CPacketDataBase::DTI, 64ul, 0u, 0u);

MtObject* CDataGPShopLineupElementCourse::MyDTI::newInstance() const {
    return new (16u) CDataGPShopLineupElementCourse;
}

const MtDTI& CDataGPShopLineupElementItem::getDTI() const {
    return CDataGPShopLineupElementItem::DTI;
}

void* CDataGPShopLineupElementItem::operator new(size_t sz, u32 align) {
    return CDataGPShopLineupElementItem::getAllocator()->memAlloc(sz, align, CDataGPShopLineupElementItem::DTI.getID());
}

__attribute__((weak)) void CDataGPShopLineupElementItem::operator delete(void* p_addr) {
    CDataGPShopLineupElementItem::getAllocator()->memFree(p_addr);
}

inline CDataGPShopLineupElementItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPShopLineupElementItem::MyDTI CDataGPShopLineupElementItem::DTI("CDataGPShopLineupElementItem", &::CPacketDataBase::DTI, 64ul, 0u, 0u);

MtObject* CDataGPShopLineupElementItem::MyDTI::newInstance() const {
    return new (16u) CDataGPShopLineupElementItem;
}

const MtDTI& CDataGPShopLineupElementPawn::getDTI() const {
    return CDataGPShopLineupElementPawn::DTI;
}

void* CDataGPShopLineupElementPawn::operator new(size_t sz, u32 align) {
    return CDataGPShopLineupElementPawn::getAllocator()->memAlloc(sz, align, CDataGPShopLineupElementPawn::DTI.getID());
}

__attribute__((weak)) void CDataGPShopLineupElementPawn::operator delete(void* p_addr) {
    CDataGPShopLineupElementPawn::getAllocator()->memFree(p_addr);
}

inline CDataGPShopLineupElementPawn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGPShopLineupElementPawn::MyDTI CDataGPShopLineupElementPawn::DTI("CDataGPShopLineupElementPawn", &::CPacketDataBase::DTI, 64ul, 0u, 0u);

MtObject* CDataGPShopLineupElementPawn::MyDTI::newInstance() const {
    return new (16u) CDataGPShopLineupElementPawn;
}

