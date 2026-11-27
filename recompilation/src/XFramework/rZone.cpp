// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rZone.h"
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

inline void cGridCollisionRegistInfo::operator delete[](void* padr) {
    MtMemoryAllocator::getAllocator(cGridCollision::DTI)->memFree(padr);
}

inline void* rZone::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rZone::DTI)->memAlloc(sz, align, rZone::DTI.mID);
}

const MtDTI& rZone::getDTI() const {
    return rZone::DTI;
}

__attribute__((noinline)) rZone::~rZone() {
    clear();
}

MT_CTSTR rZone::getExt() const {
    return "zon";
}

__attribute__((weak)) bool rZone::load(MtStream& in) {
    if (!in.isReadable()) {
        return false;
    }
    clear();
    MtDataReader r(in, 4096);
    const u32 magic = r.readU32();
    if (magic != DATA_MAGIC) {
        return false;
    }
    const u32 version = r.readU32();
    if (version != DATA_VERSION) {
        return false;
    }
    mBroadPhaseMode = r.readU32();
    MT_CHAR CategoryName[512];
    const u32 CategoryNameLen = r.readU32();
    r.read(CategoryName, CategoryNameLen);
    CategoryName[CategoryNameLen] = 0;
    mCategoryName = CategoryName;
    r.read(&mCategoryDtiID, sizeof(mCategoryDtiID));
    mCategoryAttribute = r.readU32();
    rZone::cMemoryHeader MemoryInfo;
    MemoryInfo.load(r, *this);
    nCollisionUtil::LoadBuffer buffer;
    bulkMemoryAllocate(MemoryInfo, buffer);
    divideMemory(MemoryInfo, buffer);
    mContentsPool.load(r);
    for (u32 i = 0; i < mLayoutElementsNum; i++) {
        if (!mpLayoutElements[i].loadBinary(r)) {
            clear();
            return false;
        }
    }
    for (u32 i = 0; i < mGroupManagerArrayNum; i++) {
        mpGroupManagerArray[i].loadBinary(r, buffer);
    }
    if (mBroadPhaseMode == 2) {
        if (mpGrid != nullptr) {
            mpGrid->load(r, &buffer);
        }
        if (mpGridRegisterInfo != nullptr) {
            for (u32 i = 0; i < mLayoutElementsNum; i++) {
                mpGridRegisterInfo[i].load(r);
            }
        }
    }
    if (mpGlobalLayoutIndexArray != nullptr) {
        r.read(mpGlobalLayoutIndexArray, mGlobalLayoutIndexArrayNum * sizeof(u32));
    }
    if (mpUniqueIDTable != nullptr) {
        r.read(mpUniqueIDTable, mUniqueIDTableNum * sizeof(u32));
    }
    return true;
}

__attribute__((weak)) bool rZone::save(MtStream& out) {
    if (!out.isWritable()) {
        return false;
    }
    MtDataWriter w(out, 4096, 4096);
    w.writeU32(DATA_MAGIC);
    w.writeU32(DATA_VERSION);
    w.writeU32(mBroadPhaseMode);
    MT_CTSTR CategoryName = mCategoryName.ptr();
    const u32 CategoryNameLen = static_cast<u32>(strlen(CategoryName));
    w.writeU32(CategoryNameLen);
    w.write(CategoryName, CategoryNameLen);
    w.write(&mCategoryDtiID, sizeof(mCategoryDtiID));
    w.writeU32(mCategoryAttribute);
    {
        rZone::cMemoryHeader MemoryInfo;
        MemoryInfo.importMemoryInfo(*this);
        MemoryInfo.save(w, *this);
    }
    mContentsPool.save(w);
    const u32 LayoutNum = mLayoutElementsNum;
    for (u32 i = 0; i < LayoutNum; i++) {
        nZone::cLayoutElement* pNowElement = getLayoutElement(i);
        if (!pNowElement->saveBinary(w)) {
            return false;
        }
    }
    const u32 GroupManagerNum = mGroupManagerArrayNum;
    for (u32 i = 0; i < GroupManagerNum; i++) {
        rZone::cGroupManager* pNowGroup = i < mGroupManagerArrayNum ? &mpGroupManagerArray[i] : nullptr;
        pNowGroup->saveBinary(w);
    }
    if (mBroadPhaseMode == 2) {
        if (mpGrid != nullptr) {
            mpGrid->save(w);
        }
        if (mpGridRegisterInfo != nullptr) {
            for (u32 i = 0; i < LayoutNum; i++) {
                mpGridRegisterInfo[i].save(w);
            }
        }
    }
    if (mpGlobalLayoutIndexArray != nullptr) {
        w.write(mpGlobalLayoutIndexArray, mGlobalLayoutIndexArrayNum * sizeof(u32));
    }
    if (mpUniqueIDTable != nullptr) {
        w.write(mpUniqueIDTable, mUniqueIDTableNum * sizeof(u32));
    }
    return true;
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
    u32 TotalSize = 0;
    const u32 LayoutNum = MemoryInfo.getLayoutNum();
    const u32 GlobalShapeNum = MemoryInfo.getGlobalLayoutIndexArrayNum();
    const u32 GroupNum = MemoryInfo.getGroupNum();
    const u32 UniqueIDNum = MemoryInfo.getUniqueIDTableNum();
    TotalSize += LayoutNum * sizeof(nZone::cLayoutElement);
    TotalSize += GroupNum * sizeof(rZone::cGroupManager);
    for (u32 i = 0; i < GroupNum; i++) {
        TotalSize += MemoryInfo.mpGroupInfoArray[i].calculateRequiredMemoryAlign4();
    }
    TotalSize += MemoryInfo.mContentsPoolInfo.calculateRequiredMemoryAlign4();
    TotalSize += GlobalShapeNum * sizeof(u32);
    TotalSize += UniqueIDNum * sizeof(u32);
    TotalSize = (TotalSize + 15) & ~15;
    for (u32 i = 0; i < LayoutNum; i++) {
        TotalSize += MemoryInfo.mpLayoutInfoArray[i].calculateRequiredMemoryAlign16();
    }
    if (mBroadPhaseMode == 2) {
        TotalSize += sizeof(cGridCollision);
        TotalSize += LayoutNum * sizeof(cGridCollisionRegistInfo);
        TotalSize += MemoryInfo.mAllGridInfo.calculateRequiredMemoryAlign4();
    } else if (mBroadPhaseMode == 1) {
        for (u32 i = 0; i < GroupNum; i++) {
            TotalSize += sizeof(cGridCollision);
            TotalSize += MemoryInfo.mpGroupInfoArray[i].getRegisterLayoutNum() * sizeof(cGridCollisionRegistInfo);
        }
        for (u32 i = 0; i < GroupNum; i++) {
            TotalSize += MemoryInfo.mpGroupInfoArray[i].calculateRequiredGridMemoryAlign4();
        }
    }
    return buffer.initialize(*MtMemoryAllocator::getAllocator(rZone::DTI), TotalSize);
}

__attribute__((weak)) bool rZone::divideMemory(rZone::cMemoryHeader& MemoryInfo, nCollisionUtil::LoadBuffer& buffer) {
    const u32 LayoutNum = MemoryInfo.getLayoutNum();
    const u32 GlobalShapeNum = MemoryInfo.getGlobalLayoutIndexArrayNum();
    const u32 GroupNum = MemoryInfo.getGroupNum();
    const u32 ContentsNum = MemoryInfo.mContentsPoolInfo.getContentsListNum();
    const u32 UniqueIDNum = MemoryInfo.getUniqueIDTableNum();
    mpLayoutElements = buffer.allocateNewBy<nZone::cLayoutElement>(LayoutNum);
    if (mpLayoutElements == nullptr) {
        return false;
    }
    mLayoutElementsNum = LayoutNum;
    mpGroupManagerArray = buffer.allocateNewBy<rZone::cGroupManager>(GroupNum);
    if (mpGroupManagerArray == nullptr) {
        return false;
    }
    for (u32 i = 0; i < GroupNum; i++) {
        rZone::cMemoryHeader::cGroupInfo* pNowGroupInfo = MemoryInfo.getGroupInfo(i);
        mpGroupManagerArray[i].loadBeforeAllocateAlign4(buffer, *pNowGroupInfo, *this);
    }
    mGroupManagerArrayNum = GroupNum;
    mContentsPool.loadBeforeAllocateAlign4(buffer, ContentsNum);
    mpGlobalLayoutIndexArray = GlobalShapeNum != 0 ? static_cast<u32*>(buffer.allocate(GlobalShapeNum * sizeof(u32))) : nullptr;
    mGlobalLayoutIndexArrayNum = GlobalShapeNum;
    mpUniqueIDTable = UniqueIDNum != 0 ? static_cast<u32*>(buffer.allocate(UniqueIDNum * sizeof(u32))) : nullptr;
    mUniqueIDTableNum = UniqueIDNum;
    buffer.adjustmentAlignment(16);
    for (u32 i = 0; i < LayoutNum; i++) {
        rZone::cMemoryHeader::cLayoutInfo* pNowLayoutInfo = &MemoryInfo.mpLayoutInfoArray[i];
        mpLayoutElements[i].loadBeforeAllocateAlign16(buffer, pNowLayoutInfo->getShapeType());
    }
    if (mBroadPhaseMode == 2) {
        mpGrid = buffer.allocateNewBy<cGridCollision>(1);
        mpGridRegisterInfo = buffer.allocateNewBy<cGridCollisionRegistInfo>(mLayoutElementsNum);
    } else if (mBroadPhaseMode == 1) {
        for (u32 i = 0; i < GroupNum; i++) {
            rZone::cMemoryHeader::cGroupInfo* pNowGroupInfo = MemoryInfo.getGroupInfo(i);
            mpGroupManagerArray[i].loadBeforeAllocateAlign16(buffer, *pNowGroupInfo, *this);
        }
    }
    return true;
}

inline rZone::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rZone::MyDTI rZone::DTI("rZone", &::cResource::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* rZone::MyDTI::newInstance() const {
    return new (16u) rZone;
}

const MtDTI& rZone::cGroupManager::getDTI() const {
    return rZone::cGroupManager::DTI;
}

rZone::cGroupManager::~cGroupManager() {
    deleteWorkMember();
}

__attribute__((weak)) bool rZone::cGroupManager::loadBeforeAllocateAlign16(nCollisionUtil::LoadBuffer& buffer, const rZone::cMemoryHeader::cGroupInfo& AllocateInfo, rZone& owner) {
    if (mBroadPhaseMode == 1 && AllocateInfo.getGroupGridInfo().getGridCellNum() != 0) {
        const u32 LayoutNum = AllocateInfo.getRegisterLayoutNum();
        mpGrid = buffer.allocateNewBy<cGridCollision>(1);
        mpGridRegisterInfo = buffer.allocateNewBy<cGridCollisionRegistInfo>(LayoutNum);
    }
    return true;
}

__attribute__((weak)) bool rZone::cGroupManager::loadBinary(MtDataReader& r, nCollisionUtil::LoadBuffer& buffer) {
    mIndex = r.readU32();
    mGroupID = r.readS32();
    if (mpLayoutIndexArray != nullptr) {
        r.read(mpLayoutIndexArray, mLayoutIndexArrayNum * sizeof(u32));
    }
    if (mpGlobalLayoutIndexArray != nullptr) {
        r.read(mpGlobalLayoutIndexArray, mGlobalLayoutIndexArrayNum * sizeof(u32));
    }
    if (mBroadPhaseMode == 1) {
        if (mpGrid != nullptr) {
            mpGrid->load(r, &buffer);
        }
        if (mpGridRegisterInfo != nullptr) {
            for (u32 i = 0; i < mLayoutIndexArrayNum; i++) {
                mpGridRegisterInfo[i].load(r);
            }
        }
    }
    return true;
}

__attribute__((weak)) bool rZone::cGroupManager::saveBinary(MtDataWriter& w) {
    w.writeU32(mIndex);
    w.writeS32(mGroupID);
    if (mpLayoutIndexArray != nullptr && mLayoutIndexArrayNum != 0) {
        w.write(mpLayoutIndexArray, mLayoutIndexArrayNum * sizeof(u32));
    }
    if (mpGlobalLayoutIndexArray != nullptr && mGlobalLayoutIndexArrayNum != 0) {
        w.write(mpGlobalLayoutIndexArray, mGlobalLayoutIndexArrayNum * sizeof(u32));
    }
    if (mBroadPhaseMode == 1) {
        if (mpGrid != nullptr) {
            mpGrid->save(w);
        }
        if (mpGridRegisterInfo != nullptr) {
            for (u32 i = 0; i < mLayoutIndexArrayNum; i++) {
                mpGridRegisterInfo[i].save(w);
            }
        }
    }
    return true;
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
    if (mpOwner != nullptr && mpOwner->getDTI().mID == rZone::DTI.mID) {
        mpLayoutIndexArray = nullptr;
        mpGlobalLayoutIndexArray = nullptr;
        if (mpGrid != nullptr) {
            mpGrid->~cGridCollision();
            mpGrid = nullptr;
        }
        if (mpGridRegisterInfo != nullptr) {
            for (u32 i = 0; i < mLayoutIndexArrayNum; i++) {
                mpGridRegisterInfo[i].~cGridCollisionRegistInfo();
            }
            mpGridRegisterInfo = nullptr;
        }
    } else {
        if (mpLayoutIndexArray != nullptr) {
            MtMemoryAllocator::getAllocator(rZone::cGroupManager::DTI)->memFree(mpLayoutIndexArray);
            mpLayoutIndexArray = nullptr;
        }
        if (mpGlobalLayoutIndexArray != nullptr) {
            MtMemoryAllocator::getAllocator(rZone::cGroupManager::DTI)->memFree(mpGlobalLayoutIndexArray);
            mpGlobalLayoutIndexArray = nullptr;
        }
        if (mpGrid != nullptr) {
            delete mpGrid;
            mpGrid = nullptr;
        }
        if (mpGridRegisterInfo != nullptr) {
            delete[] mpGridRegisterInfo;
            mpGridRegisterInfo = nullptr;
        }
    }
}

inline rZone::cGroupManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rZone::cGroupManager::MyDTI rZone::cGroupManager::DTI("rZone::cGroupManager", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* rZone::cGroupManager::MyDTI::newInstance() const {
    return new (16u) rZone::cGroupManager;
}

__attribute__((weak)) void rZone::cMemoryHeader::importMemoryInfo(rZone& owner) {
    clear();
    mLayoutInfoNum = owner.mLayoutElementsNum;
    mpLayoutInfoArray = new cLayoutInfo[mLayoutInfoNum];
    for (u32 i = 0; i < mLayoutInfoNum; i++) {
        mpLayoutInfoArray[i].importLayoutInfo(owner, i);
    }
    mGroupInfoNum = owner.mGroupManagerArrayNum;
    mpGroupInfoArray = new cGroupInfo[mGroupInfoNum];
    for (u32 i = 0; i < mGroupInfoNum; i++) {
        mpGroupInfoArray[i].importGroupInfo(owner, i);
    }
    mContentsPoolInfo.importContentsPoolInfo(owner);
    mGlobalLayoutIndexArrayNum = owner.mGlobalLayoutIndexArrayNum;
    mUniqueIDTableNum = owner.mUniqueIDTableNum;
    if (owner.mBroadPhaseMode == 2) {
        cGridCollision* pGrid = owner.mpGrid;
        if (pGrid != nullptr) {
            mAllGridInfo.importGridInfo(*pGrid);
        }
    }
}

__attribute__((weak)) void rZone::cMemoryHeader::load(MtDataReader& r, rZone& owner) {
    clear();
    mLayoutInfoNum = r.readU32();
    mpLayoutInfoArray = new cLayoutInfo[mLayoutInfoNum];
    for (u32 i = 0; i < mLayoutInfoNum; i++) {
        mpLayoutInfoArray[i].load(r);
    }
    mGroupInfoNum = r.readU32();
    mpGroupInfoArray = new cGroupInfo[mGroupInfoNum];
    for (u32 i = 0; i < mGroupInfoNum; i++) {
        mpGroupInfoArray[i].load(r, owner);
    }
    mContentsPoolInfo.load(r);
    mGlobalLayoutIndexArrayNum = r.readU32();
    mUniqueIDTableNum = r.readU32();
    if (owner.mBroadPhaseMode == 2) {
        mAllGridInfo.load(r);
    }
}

__attribute__((weak)) void rZone::cMemoryHeader::save(MtDataWriter& w, rZone& owner) {
    w.writeU32(mLayoutInfoNum);
    for (u32 i = 0; i < mLayoutInfoNum; i++) {
        mpLayoutInfoArray[i].save(w);
    }
    w.writeU32(mGroupInfoNum);
    for (u32 i = 0; i < mGroupInfoNum; i++) {
        mpGroupInfoArray[i].save(w, owner);
    }
    mContentsPoolInfo.save(w);
    w.writeU32(mGlobalLayoutIndexArrayNum);
    w.writeU32(mUniqueIDTableNum);
    if (owner.mBroadPhaseMode == 2) {
        mAllGridInfo.save(w);
    }
}

