// Reconstructed from the game's DWARF debug information.
#include <new>
#include "DispelItem.h"
#include "Character.h"
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

const MtDTI& CDataDispelBaseItem::getDTI() const {
    return CDataDispelBaseItem::DTI;
}

void* CDataDispelBaseItem::operator new(size_t sz, u32 align) {
    return CDataDispelBaseItem::getAllocator()->memAlloc(sz, align, CDataDispelBaseItem::DTI.getID());
}

__attribute__((weak)) void CDataDispelBaseItem::operator delete(void* p_addr) {
    CDataDispelBaseItem::getAllocator()->memFree(p_addr);
}

inline CDataDispelBaseItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelBaseItem::MyDTI CDataDispelBaseItem::DTI("CDataDispelBaseItem", &::CPacketDataBase::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataDispelBaseItem::MyDTI::newInstance() const {
    DDON_STUB("CDataDispelBaseItem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataDispelBaseItemData::getDTI() const {
    return CDataDispelBaseItemData::DTI;
}

void* CDataDispelBaseItemData::operator new(size_t sz, u32 align) {
    return CDataDispelBaseItemData::getAllocator()->memAlloc(sz, align, CDataDispelBaseItemData::DTI.getID());
}

__attribute__((weak)) void CDataDispelBaseItemData::operator delete(void* p_addr) {
    CDataDispelBaseItemData::getAllocator()->memFree(p_addr);
}

inline CDataDispelBaseItemData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelBaseItemData::MyDTI CDataDispelBaseItemData::DTI("CDataDispelBaseItemData", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataDispelBaseItemData::MyDTI::newInstance() const {
    return new (16u) CDataDispelBaseItemData;
}

const MtDTI& CDataDispelCategoryInfo::getDTI() const {
    return CDataDispelCategoryInfo::DTI;
}

void* CDataDispelCategoryInfo::operator new(size_t sz, u32 align) {
    return CDataDispelCategoryInfo::getAllocator()->memAlloc(sz, align, CDataDispelCategoryInfo::DTI.getID());
}

__attribute__((weak)) void CDataDispelCategoryInfo::operator delete(void* p_addr) {
    CDataDispelCategoryInfo::getAllocator()->memFree(p_addr);
}

inline CDataDispelCategoryInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelCategoryInfo::MyDTI CDataDispelCategoryInfo::DTI("CDataDispelCategoryInfo", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataDispelCategoryInfo::MyDTI::newInstance() const {
    return new (16u) CDataDispelCategoryInfo;
}

const MtDTI& CDataDispelLotColor::getDTI() const {
    return CDataDispelLotColor::DTI;
}

void* CDataDispelLotColor::operator new(size_t sz, u32 align) {
    return CDataDispelLotColor::getAllocator()->memAlloc(sz, align, CDataDispelLotColor::DTI.getID());
}

__attribute__((weak)) void CDataDispelLotColor::operator delete(void* p_addr) {
    CDataDispelLotColor::getAllocator()->memFree(p_addr);
}

inline CDataDispelLotColor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelLotColor::MyDTI CDataDispelLotColor::DTI("CDataDispelLotColor", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataDispelLotColor::MyDTI::newInstance() const {
    return new (16u) CDataDispelLotColor;
}

const MtDTI& CDataDispelLotCrest::getDTI() const {
    return CDataDispelLotCrest::DTI;
}

void* CDataDispelLotCrest::operator new(size_t sz, u32 align) {
    return CDataDispelLotCrest::getAllocator()->memAlloc(sz, align, CDataDispelLotCrest::DTI.getID());
}

__attribute__((weak)) void CDataDispelLotCrest::operator delete(void* p_addr) {
    CDataDispelLotCrest::getAllocator()->memFree(p_addr);
}

inline CDataDispelLotCrest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelLotCrest::MyDTI CDataDispelLotCrest::DTI("CDataDispelLotCrest", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataDispelLotCrest::MyDTI::newInstance() const {
    return new (16u) CDataDispelLotCrest;
}

const MtDTI& CDataDispelLotData::getDTI() const {
    return CDataDispelLotData::DTI;
}

void* CDataDispelLotData::operator new(size_t sz, u32 align) {
    return CDataDispelLotData::getAllocator()->memAlloc(sz, align, CDataDispelLotData::DTI.getID());
}

__attribute__((weak)) void CDataDispelLotData::operator delete(void* p_addr) {
    CDataDispelLotData::getAllocator()->memFree(p_addr);
}

inline CDataDispelLotData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelLotData::MyDTI CDataDispelLotData::DTI("CDataDispelLotData", &::CPacketDataBase::DTI, 136ul, 0u, 0u);

MtObject* CDataDispelLotData::MyDTI::newInstance() const {
    return new (16u) CDataDispelLotData;
}

const MtDTI& CDataDispelLotItem::getDTI() const {
    return CDataDispelLotItem::DTI;
}

__attribute__((weak)) void CDataDispelLotItem::operator delete(void* p_addr) {
    CDataDispelLotItem::getAllocator()->memFree(p_addr);
}

inline CDataDispelLotItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelLotItem::MyDTI CDataDispelLotItem::DTI("CDataDispelLotItem", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataDispelLotItem::MyDTI::newInstance() const {
    return new (16u) CDataDispelLotItem;
}

const MtDTI& CDataDispelLotPlus::getDTI() const {
    return CDataDispelLotPlus::DTI;
}

void* CDataDispelLotPlus::operator new(size_t sz, u32 align) {
    return CDataDispelLotPlus::getAllocator()->memAlloc(sz, align, CDataDispelLotPlus::DTI.getID());
}

__attribute__((weak)) void CDataDispelLotPlus::operator delete(void* p_addr) {
    CDataDispelLotPlus::getAllocator()->memFree(p_addr);
}

inline CDataDispelLotPlus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelLotPlus::MyDTI CDataDispelLotPlus::DTI("CDataDispelLotPlus", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataDispelLotPlus::MyDTI::newInstance() const {
    return new (16u) CDataDispelLotPlus;
}

const MtDTI& CDataDispelResultInfo::getDTI() const {
    return CDataDispelResultInfo::DTI;
}

void* CDataDispelResultInfo::operator new(size_t sz, u32 align) {
    return CDataDispelResultInfo::getAllocator()->memAlloc(sz, align, CDataDispelResultInfo::DTI.getID());
}

__attribute__((weak)) void CDataDispelResultInfo::operator delete(void* p_addr) {
    CDataDispelResultInfo::getAllocator()->memFree(p_addr);
}

inline CDataDispelResultInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataDispelResultInfo::MyDTI CDataDispelResultInfo::DTI("CDataDispelResultInfo", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

MtObject* CDataDispelResultInfo::MyDTI::newInstance() const {
    return new (16u) CDataDispelResultInfo;
}

