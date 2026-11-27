// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Achievement.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataAchieveCategoryStatus::getDTI() const {
    return CDataAchieveCategoryStatus::DTI;
}

void* CDataAchieveCategoryStatus::operator new(size_t sz, u32 align) {
    return CDataAchieveCategoryStatus::getAllocator()->memAlloc(sz, align, CDataAchieveCategoryStatus::DTI.getID());
}

__attribute__((weak)) void CDataAchieveCategoryStatus::operator delete(void* p_addr) {
    CDataAchieveCategoryStatus::getAllocator()->memFree(p_addr);
}

inline CDataAchieveCategoryStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAchieveCategoryStatus::MyDTI CDataAchieveCategoryStatus::DTI("CDataAchieveCategoryStatus", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataAchieveCategoryStatus::MyDTI::newInstance() const {
    return new (16u) CDataAchieveCategoryStatus;
}

const MtDTI& CDataAchieveRewardCommon::getDTI() const {
    return CDataAchieveRewardCommon::DTI;
}

void* CDataAchieveRewardCommon::operator new(size_t sz, u32 align) {
    return CDataAchieveRewardCommon::getAllocator()->memAlloc(sz, align, CDataAchieveRewardCommon::DTI.getID());
}

__attribute__((weak)) void CDataAchieveRewardCommon::operator delete(void* p_addr) {
    CDataAchieveRewardCommon::getAllocator()->memFree(p_addr);
}

inline CDataAchieveRewardCommon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAchieveRewardCommon::MyDTI CDataAchieveRewardCommon::DTI("CDataAchieveRewardCommon", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataAchieveRewardCommon::MyDTI::newInstance() const {
    return new (16u) CDataAchieveRewardCommon;
}

const MtDTI& CDataAchievementFurnitureReward::getDTI() const {
    return CDataAchievementFurnitureReward::DTI;
}

void* CDataAchievementFurnitureReward::operator new(size_t sz, u32 align) {
    return CDataAchievementFurnitureReward::getAllocator()->memAlloc(sz, align, CDataAchievementFurnitureReward::DTI.getID());
}

__attribute__((weak)) void CDataAchievementFurnitureReward::operator delete(void* p_addr) {
    CDataAchievementFurnitureReward::getAllocator()->memFree(p_addr);
}

inline CDataAchievementFurnitureReward::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAchievementFurnitureReward::MyDTI CDataAchievementFurnitureReward::DTI("CDataAchievementFurnitureReward", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataAchievementFurnitureReward::MyDTI::newInstance() const {
    return new (16u) CDataAchievementFurnitureReward;
}

const MtDTI& CDataAchievementIdentifier::getDTI() const {
    return CDataAchievementIdentifier::DTI;
}

__attribute__((weak)) void CDataAchievementIdentifier::operator delete(void* p_addr) {
    CDataAchievementIdentifier::getAllocator()->memFree(p_addr);
}

inline CDataAchievementIdentifier::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAchievementIdentifier::MyDTI CDataAchievementIdentifier::DTI("CDataAchievementIdentifier", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataAchievementIdentifier::MyDTI::newInstance() const {
    return new (16u) CDataAchievementIdentifier;
}

const MtDTI& CDataAchievementProgress::getDTI() const {
    return CDataAchievementProgress::DTI;
}

void* CDataAchievementProgress::operator new(size_t sz, u32 align) {
    return CDataAchievementProgress::getAllocator()->memAlloc(sz, align, CDataAchievementProgress::DTI.getID());
}

__attribute__((weak)) void CDataAchievementProgress::operator delete(void* p_addr) {
    CDataAchievementProgress::getAllocator()->memFree(p_addr);
}

inline CDataAchievementProgress::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAchievementProgress::MyDTI CDataAchievementProgress::DTI("CDataAchievementProgress", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataAchievementProgress::MyDTI::newInstance() const {
    return new (16u) CDataAchievementProgress;
}

const MtDTI& CDataAchievementRewardProgress::getDTI() const {
    return CDataAchievementRewardProgress::DTI;
}

void* CDataAchievementRewardProgress::operator new(size_t sz, u32 align) {
    return CDataAchievementRewardProgress::getAllocator()->memAlloc(sz, align, CDataAchievementRewardProgress::DTI.getID());
}

__attribute__((weak)) void CDataAchievementRewardProgress::operator delete(void* p_addr) {
    CDataAchievementRewardProgress::getAllocator()->memFree(p_addr);
}

inline CDataAchievementRewardProgress::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAchievementRewardProgress::MyDTI CDataAchievementRewardProgress::DTI("CDataAchievementRewardProgress", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataAchievementRewardProgress::MyDTI::newInstance() const {
    return new (16u) CDataAchievementRewardProgress;
}

