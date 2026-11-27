// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Craft.h"
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

const MtDTI& CDataCraftColorant::getDTI() const {
    return CDataCraftColorant::DTI;
}

void* CDataCraftColorant::operator new(size_t sz, u32 align) {
    return CDataCraftColorant::getAllocator()->memAlloc(sz, align, CDataCraftColorant::DTI.getID());
}

inline CDataCraftColorant::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftColorant::MyDTI CDataCraftColorant::DTI("CDataCraftColorant", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCraftColorant::MyDTI::newInstance() const {
    return new (16u) CDataCraftColorant;
}

const MtDTI& CDataCraftElement::getDTI() const {
    return CDataCraftElement::DTI;
}

void* CDataCraftElement::operator new(size_t sz, u32 align) {
    return CDataCraftElement::getAllocator()->memAlloc(sz, align, CDataCraftElement::DTI.getID());
}

inline CDataCraftElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftElement::MyDTI CDataCraftElement::DTI("CDataCraftElement", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCraftElement::MyDTI::newInstance() const {
    return new (16u) CDataCraftElement;
}

const MtDTI& CDataCraftMaterial::getDTI() const {
    return CDataCraftMaterial::DTI;
}

void* CDataCraftMaterial::operator new(size_t sz, u32 align) {
    return CDataCraftMaterial::getAllocator()->memAlloc(sz, align, CDataCraftMaterial::DTI.getID());
}

inline CDataCraftMaterial::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftMaterial::MyDTI CDataCraftMaterial::DTI("CDataCraftMaterial", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCraftMaterial::MyDTI::newInstance() const {
    return new (16u) CDataCraftMaterial;
}

const MtDTI& CDataCraftPawnInfo::getDTI() const {
    return CDataCraftPawnInfo::DTI;
}

void* CDataCraftPawnInfo::operator new(size_t sz, u32 align) {
    return CDataCraftPawnInfo::getAllocator()->memAlloc(sz, align, CDataCraftPawnInfo::DTI.getID());
}

__attribute__((weak)) void CDataCraftPawnInfo::operator delete(void* p_addr) {
    CDataCraftPawnInfo::getAllocator()->memFree(p_addr);
}

inline CDataCraftPawnInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftPawnInfo::MyDTI CDataCraftPawnInfo::DTI("CDataCraftPawnInfo", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCraftPawnInfo::MyDTI::newInstance() const {
    return new (16u) CDataCraftPawnInfo;
}

const MtDTI& CDataCraftPawnList::getDTI() const {
    return CDataCraftPawnList::DTI;
}

void* CDataCraftPawnList::operator new(size_t sz, u32 align) {
    return CDataCraftPawnList::getAllocator()->memAlloc(sz, align, CDataCraftPawnList::DTI.getID());
}

__attribute__((weak)) void CDataCraftPawnList::operator delete(void* p_addr) {
    CDataCraftPawnList::getAllocator()->memFree(p_addr);
}

inline CDataCraftPawnList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftPawnList::MyDTI CDataCraftPawnList::DTI("CDataCraftPawnList", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCraftPawnList::MyDTI::newInstance() const {
    return new (16u) CDataCraftPawnList;
}

const MtDTI& CDataCraftProduct::getDTI() const {
    return CDataCraftProduct::DTI;
}

__attribute__((weak)) void CDataCraftProduct::operator delete(void* p_addr) {
    CDataCraftProduct::getAllocator()->memFree(p_addr);
}

inline CDataCraftProduct::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftProduct::MyDTI CDataCraftProduct::DTI("CDataCraftProduct", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCraftProduct::MyDTI::newInstance() const {
    return new (16u) CDataCraftProduct;
}

const MtDTI& CDataCraftProductInfo::getDTI() const {
    return CDataCraftProductInfo::DTI;
}

__attribute__((weak)) void CDataCraftProductInfo::operator delete(void* p_addr) {
    CDataCraftProductInfo::getAllocator()->memFree(p_addr);
}

inline CDataCraftProductInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftProductInfo::MyDTI CDataCraftProductInfo::DTI("CDataCraftProductInfo", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataCraftProductInfo::MyDTI::newInstance() const {
    return new (16u) CDataCraftProductInfo;
}

const MtDTI& CDataCraftProgress::getDTI() const {
    return CDataCraftProgress::DTI;
}

void* CDataCraftProgress::operator new(size_t sz, u32 align) {
    return CDataCraftProgress::getAllocator()->memAlloc(sz, align, CDataCraftProgress::DTI.getID());
}

__attribute__((weak)) void CDataCraftProgress::operator delete(void* p_addr) {
    CDataCraftProgress::getAllocator()->memFree(p_addr);
}

inline CDataCraftProgress::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftProgress::MyDTI CDataCraftProgress::DTI("CDataCraftProgress", &::CPacketDataBase::DTI, 96ul, 0u, 0u);

MtObject* CDataCraftProgress::MyDTI::newInstance() const {
    return new (16u) CDataCraftProgress;
}

const MtDTI& CDataCraftSkillAnalyzeResult::getDTI() const {
    return CDataCraftSkillAnalyzeResult::DTI;
}

void* CDataCraftSkillAnalyzeResult::operator new(size_t sz, u32 align) {
    return CDataCraftSkillAnalyzeResult::getAllocator()->memAlloc(sz, align, CDataCraftSkillAnalyzeResult::DTI.getID());
}

__attribute__((weak)) void CDataCraftSkillAnalyzeResult::operator delete(void* p_addr) {
    CDataCraftSkillAnalyzeResult::getAllocator()->memFree(p_addr);
}

inline CDataCraftSkillAnalyzeResult::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftSkillAnalyzeResult::MyDTI CDataCraftSkillAnalyzeResult::DTI("CDataCraftSkillAnalyzeResult", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCraftSkillAnalyzeResult::MyDTI::newInstance() const {
    return new (16u) CDataCraftSkillAnalyzeResult;
}

const MtDTI& CDataCraftSkillRate::getDTI() const {
    return CDataCraftSkillRate::DTI;
}

void* CDataCraftSkillRate::operator new(size_t sz, u32 align) {
    return CDataCraftSkillRate::getAllocator()->memAlloc(sz, align, CDataCraftSkillRate::DTI.getID());
}

__attribute__((weak)) void CDataCraftSkillRate::operator delete(void* p_addr) {
    CDataCraftSkillRate::getAllocator()->memFree(p_addr);
}

inline CDataCraftSkillRate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftSkillRate::MyDTI CDataCraftSkillRate::DTI("CDataCraftSkillRate", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataCraftSkillRate::MyDTI::newInstance() const {
    return new (16u) CDataCraftSkillRate;
}

const MtDTI& CDataCraftSupportPawnID::getDTI() const {
    return CDataCraftSupportPawnID::DTI;
}

void* CDataCraftSupportPawnID::operator new(size_t sz, u32 align) {
    return CDataCraftSupportPawnID::getAllocator()->memAlloc(sz, align, CDataCraftSupportPawnID::DTI.getID());
}

inline CDataCraftSupportPawnID::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftSupportPawnID::MyDTI CDataCraftSupportPawnID::DTI("CDataCraftSupportPawnID", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataCraftSupportPawnID::MyDTI::newInstance() const {
    return new (16u) CDataCraftSupportPawnID;
}

const MtDTI& CDataCraftTimeSaveCost::getDTI() const {
    return CDataCraftTimeSaveCost::DTI;
}

void* CDataCraftTimeSaveCost::operator new(size_t sz, u32 align) {
    return CDataCraftTimeSaveCost::getAllocator()->memAlloc(sz, align, CDataCraftTimeSaveCost::DTI.getID());
}

__attribute__((weak)) void CDataCraftTimeSaveCost::operator delete(void* p_addr) {
    CDataCraftTimeSaveCost::getAllocator()->memFree(p_addr);
}

inline CDataCraftTimeSaveCost::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCraftTimeSaveCost::MyDTI CDataCraftTimeSaveCost::DTI("CDataCraftTimeSaveCost", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataCraftTimeSaveCost::MyDTI::newInstance() const {
    return new (16u) CDataCraftTimeSaveCost;
}

const MtDTI& CDataCurrentEquipInfo::getDTI() const {
    return CDataCurrentEquipInfo::DTI;
}

__attribute__((weak)) void CDataCurrentEquipInfo::operator delete(void* p_addr) {
    CDataCurrentEquipInfo::getAllocator()->memFree(p_addr);
}

inline CDataCurrentEquipInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataCurrentEquipInfo::MyDTI CDataCurrentEquipInfo::DTI("CDataCurrentEquipInfo", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataCurrentEquipInfo::MyDTI::newInstance() const {
    return new (16u) CDataCurrentEquipInfo;
}

const MtDTI& CDataEquipSlot::getDTI() const {
    return CDataEquipSlot::DTI;
}

__attribute__((weak)) void CDataEquipSlot::operator delete(void* p_addr) {
    CDataEquipSlot::getAllocator()->memFree(p_addr);
}

inline CDataEquipSlot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataEquipSlot::MyDTI CDataEquipSlot::DTI("CDataEquipSlot", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataEquipSlot::MyDTI::newInstance() const {
    return new (16u) CDataEquipSlot;
}

const MtDTI& CDataMDataCraftGradeupRecipe::getDTI() const {
    return CDataMDataCraftGradeupRecipe::DTI;
}

void* CDataMDataCraftGradeupRecipe::operator new(size_t sz, u32 align) {
    return CDataMDataCraftGradeupRecipe::getAllocator()->memAlloc(sz, align, CDataMDataCraftGradeupRecipe::DTI.getID());
}

__attribute__((weak)) void CDataMDataCraftGradeupRecipe::operator delete(void* p_addr) {
    CDataMDataCraftGradeupRecipe::getAllocator()->memFree(p_addr);
}

inline CDataMDataCraftGradeupRecipe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataMDataCraftGradeupRecipe::MyDTI CDataMDataCraftGradeupRecipe::DTI("CDataMDataCraftGradeupRecipe", &::CPacketDataBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataMDataCraftGradeupRecipe::MyDTI::newInstance() const {
    DDON_STUB("CDataMDataCraftGradeupRecipe::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataMDataCraftMaterial::getDTI() const {
    return CDataMDataCraftMaterial::DTI;
}

void* CDataMDataCraftMaterial::operator new(size_t sz, u32 align) {
    return CDataMDataCraftMaterial::getAllocator()->memAlloc(sz, align, CDataMDataCraftMaterial::DTI.getID());
}

__attribute__((weak)) void CDataMDataCraftMaterial::operator delete(void* p_addr) {
    CDataMDataCraftMaterial::getAllocator()->memFree(p_addr);
}

inline CDataMDataCraftMaterial::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataMDataCraftMaterial::MyDTI CDataMDataCraftMaterial::DTI("CDataMDataCraftMaterial", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataMDataCraftMaterial::MyDTI::newInstance() const {
    return new (16u) CDataMDataCraftMaterial;
}

const MtDTI& CDataMDataCraftRecipe::getDTI() const {
    return CDataMDataCraftRecipe::DTI;
}

void* CDataMDataCraftRecipe::operator new(size_t sz, u32 align) {
    return CDataMDataCraftRecipe::getAllocator()->memAlloc(sz, align, CDataMDataCraftRecipe::DTI.getID());
}

__attribute__((weak)) void CDataMDataCraftRecipe::operator delete(void* p_addr) {
    CDataMDataCraftRecipe::getAllocator()->memFree(p_addr);
}

inline CDataMDataCraftRecipe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataMDataCraftRecipe::MyDTI CDataMDataCraftRecipe::DTI("CDataMDataCraftRecipe", &::CPacketDataBase::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataMDataCraftRecipe::MyDTI::newInstance() const {
    DDON_STUB("CDataMDataCraftRecipe::MyDTI::newInstance")
    return nullptr;
}

