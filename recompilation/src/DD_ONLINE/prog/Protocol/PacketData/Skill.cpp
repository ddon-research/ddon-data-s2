// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Skill.h"
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

const MtDTI& CDataAbilityLevelBaseParam::getDTI() const {
    return CDataAbilityLevelBaseParam::DTI;
}

void* CDataAbilityLevelBaseParam::operator new(size_t sz, u32 align) {
    return CDataAbilityLevelBaseParam::getAllocator()->memAlloc(sz, align, CDataAbilityLevelBaseParam::DTI.getID());
}

__attribute__((weak)) void CDataAbilityLevelBaseParam::operator delete(void* p_addr) {
    CDataAbilityLevelBaseParam::getAllocator()->memFree(p_addr);
}

inline CDataAbilityLevelBaseParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAbilityLevelBaseParam::MyDTI CDataAbilityLevelBaseParam::DTI("CDataAbilityLevelBaseParam", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataAbilityLevelBaseParam::MyDTI::newInstance() const {
    return new (16u) CDataAbilityLevelBaseParam;
}

const MtDTI& CDataAbilityLevelParam::getDTI() const {
    return CDataAbilityLevelParam::DTI;
}

void* CDataAbilityLevelParam::operator new(size_t sz, u32 align) {
    return CDataAbilityLevelParam::getAllocator()->memAlloc(sz, align, CDataAbilityLevelParam::DTI.getID());
}

__attribute__((weak)) void CDataAbilityLevelParam::operator delete(void* p_addr) {
    CDataAbilityLevelParam::getAllocator()->memFree(p_addr);
}

inline CDataAbilityLevelParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAbilityLevelParam::MyDTI CDataAbilityLevelParam::DTI("CDataAbilityLevelParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataAbilityLevelParam::MyDTI::newInstance() const {
    return new (16u) CDataAbilityLevelParam;
}

const MtDTI& CDataAbilityParam::getDTI() const {
    return CDataAbilityParam::DTI;
}

void* CDataAbilityParam::operator new(size_t sz, u32 align) {
    return CDataAbilityParam::getAllocator()->memAlloc(sz, align, CDataAbilityParam::DTI.getID());
}

__attribute__((weak)) void CDataAbilityParam::operator delete(void* p_addr) {
    CDataAbilityParam::getAllocator()->memFree(p_addr);
}

inline CDataAbilityParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAbilityParam::MyDTI CDataAbilityParam::DTI("CDataAbilityParam", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataAbilityParam::MyDTI::newInstance() const {
    DDON_STUB("CDataAbilityParam::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataLearnNormalSkillParam::getDTI() const {
    return CDataLearnNormalSkillParam::DTI;
}

void* CDataLearnNormalSkillParam::operator new(size_t sz, u32 align) {
    return CDataLearnNormalSkillParam::getAllocator()->memAlloc(sz, align, CDataLearnNormalSkillParam::DTI.getID());
}

__attribute__((weak)) void CDataLearnNormalSkillParam::operator delete(void* p_addr) {
    CDataLearnNormalSkillParam::getAllocator()->memFree(p_addr);
}

inline CDataLearnNormalSkillParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLearnNormalSkillParam::MyDTI CDataLearnNormalSkillParam::DTI("CDataLearnNormalSkillParam", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataLearnNormalSkillParam::MyDTI::newInstance() const {
    return new (16u) CDataLearnNormalSkillParam;
}

const MtDTI& CDataLearnedAcquirementParam::getDTI() const {
    return CDataLearnedAcquirementParam::DTI;
}

void* CDataLearnedAcquirementParam::operator new(size_t sz, u32 align) {
    return CDataLearnedAcquirementParam::getAllocator()->memAlloc(sz, align, CDataLearnedAcquirementParam::DTI.getID());
}

__attribute__((weak)) void CDataLearnedAcquirementParam::operator delete(void* p_addr) {
    CDataLearnedAcquirementParam::getAllocator()->memFree(p_addr);
}

inline CDataLearnedAcquirementParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLearnedAcquirementParam::MyDTI CDataLearnedAcquirementParam::DTI("CDataLearnedAcquirementParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataLearnedAcquirementParam::MyDTI::newInstance() const {
    return new (16u) CDataLearnedAcquirementParam;
}

const MtDTI& CDataNormalSkillParam::getDTI() const {
    return CDataNormalSkillParam::DTI;
}

void* CDataNormalSkillParam::operator new(size_t sz, u32 align) {
    return CDataNormalSkillParam::getAllocator()->memAlloc(sz, align, CDataNormalSkillParam::DTI.getID());
}

__attribute__((weak)) void CDataNormalSkillParam::operator delete(void* p_addr) {
    CDataNormalSkillParam::getAllocator()->memFree(p_addr);
}

inline CDataNormalSkillParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataNormalSkillParam::MyDTI CDataNormalSkillParam::DTI("CDataNormalSkillParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataNormalSkillParam::MyDTI::newInstance() const {
    return new (16u) CDataNormalSkillParam;
}

const MtDTI& CDataPresetAbilityParam::getDTI() const {
    return CDataPresetAbilityParam::DTI;
}

void* CDataPresetAbilityParam::operator new(size_t sz, u32 align) {
    return CDataPresetAbilityParam::getAllocator()->memAlloc(sz, align, CDataPresetAbilityParam::DTI.getID());
}

__attribute__((weak)) void CDataPresetAbilityParam::operator delete(void* p_addr) {
    CDataPresetAbilityParam::getAllocator()->memFree(p_addr);
}

inline CDataPresetAbilityParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataPresetAbilityParam::MyDTI CDataPresetAbilityParam::DTI("CDataPresetAbilityParam", &::CPacketDataBase::DTI, 56ul, 0u, 0u);

MtObject* CDataPresetAbilityParam::MyDTI::newInstance() const {
    return new (16u) CDataPresetAbilityParam;
}

const MtDTI& CDataReleaseAcquirementParam::getDTI() const {
    return CDataReleaseAcquirementParam::DTI;
}

void* CDataReleaseAcquirementParam::operator new(size_t sz, u32 align) {
    return CDataReleaseAcquirementParam::getAllocator()->memAlloc(sz, align, CDataReleaseAcquirementParam::DTI.getID());
}

__attribute__((weak)) void CDataReleaseAcquirementParam::operator delete(void* p_addr) {
    CDataReleaseAcquirementParam::getAllocator()->memFree(p_addr);
}

inline CDataReleaseAcquirementParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataReleaseAcquirementParam::MyDTI CDataReleaseAcquirementParam::DTI("CDataReleaseAcquirementParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataReleaseAcquirementParam::MyDTI::newInstance() const {
    return new (16u) CDataReleaseAcquirementParam;
}

const MtDTI& CDataSetAcquirementParam::getDTI() const {
    return CDataSetAcquirementParam::DTI;
}

void* CDataSetAcquirementParam::operator new(size_t sz, u32 align) {
    return CDataSetAcquirementParam::getAllocator()->memAlloc(sz, align, CDataSetAcquirementParam::DTI.getID());
}

__attribute__((weak)) void CDataSetAcquirementParam::operator delete(void* p_addr) {
    CDataSetAcquirementParam::getAllocator()->memFree(p_addr);
}

inline CDataSetAcquirementParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSetAcquirementParam::MyDTI CDataSetAcquirementParam::DTI("CDataSetAcquirementParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataSetAcquirementParam::MyDTI::newInstance() const {
    return new (16u) CDataSetAcquirementParam;
}

const MtDTI& CDataSkillLevelBaseParam::getDTI() const {
    return CDataSkillLevelBaseParam::DTI;
}

void* CDataSkillLevelBaseParam::operator new(size_t sz, u32 align) {
    return CDataSkillLevelBaseParam::getAllocator()->memAlloc(sz, align, CDataSkillLevelBaseParam::DTI.getID());
}

__attribute__((weak)) void CDataSkillLevelBaseParam::operator delete(void* p_addr) {
    CDataSkillLevelBaseParam::getAllocator()->memFree(p_addr);
}

inline CDataSkillLevelBaseParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSkillLevelBaseParam::MyDTI CDataSkillLevelBaseParam::DTI("CDataSkillLevelBaseParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataSkillLevelBaseParam::MyDTI::newInstance() const {
    return new (16u) CDataSkillLevelBaseParam;
}

const MtDTI& CDataSkillLevelParam::getDTI() const {
    return CDataSkillLevelParam::DTI;
}

void* CDataSkillLevelParam::operator new(size_t sz, u32 align) {
    return CDataSkillLevelParam::getAllocator()->memAlloc(sz, align, CDataSkillLevelParam::DTI.getID());
}

__attribute__((weak)) void CDataSkillLevelParam::operator delete(void* p_addr) {
    CDataSkillLevelParam::getAllocator()->memFree(p_addr);
}

inline CDataSkillLevelParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSkillLevelParam::MyDTI CDataSkillLevelParam::DTI("CDataSkillLevelParam", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataSkillLevelParam::MyDTI::newInstance() const {
    return new (16u) CDataSkillLevelParam;
}

const MtDTI& CDataSkillParam::getDTI() const {
    return CDataSkillParam::DTI;
}

void* CDataSkillParam::operator new(size_t sz, u32 align) {
    return CDataSkillParam::getAllocator()->memAlloc(sz, align, CDataSkillParam::DTI.getID());
}

__attribute__((weak)) void CDataSkillParam::operator delete(void* p_addr) {
    CDataSkillParam::getAllocator()->memFree(p_addr);
}

inline CDataSkillParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSkillParam::MyDTI CDataSkillParam::DTI("CDataSkillParam", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

MtObject* CDataSkillParam::MyDTI::newInstance() const {
    return new (16u) CDataSkillParam;
}

