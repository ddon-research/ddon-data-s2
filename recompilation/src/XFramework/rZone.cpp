// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rZone.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtString.h"
#include "cGridCollision.h"
#include "cResource.h"
#include "nZone.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* rZone::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rZone::DTI)->memAlloc(sz, align, rZone::DTI.mID);
}

const MtDTI& rZone::getDTI() const {
    return rZone::DTI;
}

inline void rZone::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rZone::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rZone::~rZone() {
    clear();
}

MT_CTSTR rZone::getExt() const {
    return "zon";
}

__attribute__((weak)) bool rZone::load(MtStream& in) {
    DDON_STUB("rZone::load")
    return {};
}

__attribute__((weak)) bool rZone::save(MtStream& out) {
    DDON_STUB("rZone::save")
    return {};
}

__attribute__((weak)) void rZone::clear() {
    if (getDTI().mID == rZone::DTI.mID) {
        void* pMemoryTop = mpLayoutElements;
        if (pMemoryTop == nullptr) {
            return;
        }
        for (u32 i = 0; i < mLayoutElementsNum; i++) {
            mpLayoutElements[i].~cLayoutElement();
        }
        if (mpGroupManagerArray != nullptr) {
            for (u32 i = 0; i < mGroupManagerArrayNum; i++) {
                mpGroupManagerArray[i].~cGroupManager();
            }
        }
        if (mpGrid != nullptr) {
            mpGrid->~cGridCollision();
        }
        if (mpGridRegisterInfo != nullptr) {
            for (u32 i = 0; i < mLayoutElementsNum; i++) {
                mpGridRegisterInfo[i].~cGridCollisionRegistInfo();
            }
        }
        mpUniqueIDTable = nullptr;
        mUniqueIDTableNum = 0;
        mpGroupManagerArray = nullptr;
        mGroupManagerArrayNum = 0;
        mLayoutElementsNum = 0;
        mGlobalLayoutIndexArrayNum = 0;
        mpLayoutElements = nullptr;
        mpGridRegisterInfo = nullptr;
        mpGrid = nullptr;
        mContentsPool.clearContents();
        MtMemoryAllocator::getAllocator(rZone::DTI)->memFree(pMemoryTop);
        return;
    }
    if (mpLayoutElements != nullptr) {
        delete[] mpLayoutElements;
        mpLayoutElements = nullptr;
    }
    mLayoutElementsNum = 0;
    if (mpUniqueIDTable != nullptr) {
        MtMemoryAllocator::getAllocator(rZone::DTI)->memFree(mpUniqueIDTable);
        mpUniqueIDTable = nullptr;
    }
    mUniqueIDTableNum = 0;
    if (mpGroupManagerArray != nullptr) {
        delete[] mpGroupManagerArray;
        mpGroupManagerArray = nullptr;
    }
    mGroupManagerArrayNum = 0;
    if (mpGrid != nullptr) {
        delete mpGrid;
        mpGrid = nullptr;
    }
    if (mpGridRegisterInfo != nullptr) {
        delete[] mpGridRegisterInfo;
        mpGridRegisterInfo = nullptr;
    }
    mContentsPool.clearContents();
}

u32 rZone::getLayoutIndexFromUniqueID(u32 UniqueID) const {
    if (UniqueID < mUniqueIDTableNum) {
        if (mpUniqueIDTable != nullptr) {
            return mpUniqueIDTable[UniqueID];
        }
    }
    return 0xFFFFFFFF;
}

u32 rZone::getGlobalLayoutIndex(u32 GlobalLayoutIndex) const {
    if (GlobalLayoutIndex < mGlobalLayoutIndexArrayNum) {
        return mpGlobalLayoutIndexArray[GlobalLayoutIndex];
    } else {
        return 0xFFFFFFFF;
    }
}

__attribute__((weak)) bool rZone::bulkMemoryAllocate(rZone::cMemoryHeader& MemoryInfo, nCollisionUtil::LoadBuffer& buffer) {
    DDON_STUB("rZone::bulkMemoryAllocate")
    return {};
}

__attribute__((weak)) bool rZone::divideMemory(rZone::cMemoryHeader& MemoryInfo, nCollisionUtil::LoadBuffer& buffer) {
    DDON_STUB("rZone::divideMemory")
    return {};
}

inline rZone::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rZone::MyDTI rZone::DTI("rZone", &::cResource::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* rZone::MyDTI::newInstance() const {
    return new (16u) rZone;
}

const MtDTI& rZone::cGroupManager::getDTI() const {
    return rZone::cGroupManager::DTI;
}

inline void rZone::cGroupManager::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rZone::cGroupManager::DTI)->memFree(p_addr);
}

rZone::cGroupManager::~cGroupManager() {
    deleteWorkMember();
}

__attribute__((weak)) bool rZone::cGroupManager::loadBeforeAllocateAlign16(nCollisionUtil::LoadBuffer& buffer, const rZone::cMemoryHeader::cGroupInfo& AllocateInfo, rZone& owner) {
    DDON_STUB("rZone::cGroupManager::loadBeforeAllocateAlign16")
    return {};
}

__attribute__((weak)) bool rZone::cGroupManager::loadBinary(MtDataReader& r, nCollisionUtil::LoadBuffer& buffer) {
    DDON_STUB("rZone::cGroupManager::loadBinary")
    return {};
}

__attribute__((weak)) bool rZone::cGroupManager::saveBinary(MtDataWriter& w) {
    DDON_STUB("rZone::cGroupManager::saveBinary")
    return {};
}

s32 rZone::cGroupManager::getGroupID() const {
    return mGroupID;
}

u32 rZone::cGroupManager::getGroupLayoutIndex(u32 GroupLayoutIndex) const {
    if (GroupLayoutIndex < mLayoutIndexArrayNum) {
        return mpLayoutIndexArray[GroupLayoutIndex];
    } else {
        return 0xFFFFFFFF;
    }
}

u32 rZone::cGroupManager::getGroupLayoutIndexNum() const {
    return mLayoutIndexArrayNum;
}

u32 rZone::cGroupManager::getGroupGlobalLayoutIndex(u32 GroupGlobalLayoutIndex) const {
    if (GroupGlobalLayoutIndex < mGlobalLayoutIndexArrayNum) {
        return mpGlobalLayoutIndexArray[GroupGlobalLayoutIndex];
    } else {
        return 0xFFFFFFFF;
    }
}

u32 rZone::cGroupManager::getGroupGlobalLayoutIndexNum() const {
    return mGlobalLayoutIndexArrayNum;
}

__attribute__((weak)) void rZone::cGroupManager::deleteWorkMember() {
    DDON_STUB("rZone::cGroupManager::deleteWorkMember")
    /* stub */
}

inline rZone::cGroupManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rZone::cGroupManager::MyDTI rZone::cGroupManager::DTI("rZone::cGroupManager", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* rZone::cGroupManager::MyDTI::newInstance() const {
    DDON_STUB("rZone::cGroupManager::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void rZone::cMemoryHeader::importMemoryInfo(rZone& owner) {
    DDON_STUB("rZone::cMemoryHeader::importMemoryInfo")
    /* stub */
}

__attribute__((weak)) void rZone::cMemoryHeader::load(MtDataReader& r, rZone& owner) {
    DDON_STUB("rZone::cMemoryHeader::load")
    /* stub */
}

__attribute__((weak)) void rZone::cMemoryHeader::save(MtDataWriter& w, rZone& owner) {
    DDON_STUB("rZone::cMemoryHeader::save")
    /* stub */
}

