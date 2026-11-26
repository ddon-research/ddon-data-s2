#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "../MT/MtString.h"
#include "cResource.h"
#include "nZone.h"

#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMemory.h"
#include "cGridCollision.h"
#include "nCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtStream;
class MtString;
class cGridCollision;
class cGridCollisionRegistInfo;
class cZoneLayout;
namespace nCollisionUtil { struct LoadBuffer; }
namespace nZone { class cContentsPool; }
namespace nZone { class cLayoutElement; }
class uSoundGenerator;

// Declarations
class rZone;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rZone : public cResource
{
    friend class cZoneLayout;
    friend class nZone::cLayoutElement;
public:
    class MyDTI;
    class cGroupManager;
    class cMemoryHeader;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMemoryHeader
    {
    public:
        class cLayoutInfo;
        class cGroupInfo;
        class cGridInfo;
        class cContentsPoolInfo;
    public:
        class cLayoutInfo
        {
            friend class rZone;
        public:
            cLayoutInfo();
            ~cLayoutInfo();
            void importLayoutInfo(rZone& owner, u32 LayoutIndex);
            void load(MtDataReader& r);
            void save(MtDataWriter& w);
            u32 getShapeType() const;
            u32 calculateRequiredMemoryAlign16() const;
            static void* operator new(size_t);
            static void* operator new[](size_t sz);
            static void* operator new(size_t, void*);
            static void* operator new[](size_t, void*);
            static void operator delete(void*);
            static void operator delete[](void* padr);
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
            static MtAllocator* getAllocator();
        private:
            u32 mShapeType;  // offset: 0x0
        };
    public:
        class cGridInfo
        {
            friend class rZone;
        public:
            cGridInfo();
            ~cGridInfo();
            void importGridInfo(cGridCollision& owner);
            void load(MtDataReader& r);
            void save(MtDataWriter& w);
            u32 getGroupGridRegisterNum() const;
            u32 getGridCellNum() const;
            u32 calculateRequiredMemoryAlign4() const;
            static void* operator new(size_t);
            static void* operator new[](size_t);
            static void* operator new(size_t, void*);
            static void* operator new[](size_t, void*);
            static void operator delete(void*);
            static void operator delete[](void*);
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
            static MtAllocator* getAllocator();
        private:
            u32 mGridRegisterNum;  // offset: 0x0
            u32 mGridCellNum;  // offset: 0x4
        };
    public:
        class cContentsPoolInfo
        {
            friend class rZone;
        public:
            cContentsPoolInfo();
            ~cContentsPoolInfo();
            void importContentsPoolInfo(rZone& owner);
            void load(MtDataReader& r);
            void save(MtDataWriter& w);
            u32 getContentsListNum() const;
            u32 calculateRequiredMemoryAlign4() const;
            static void* operator new(size_t);
            static void* operator new[](size_t);
            static void* operator new(size_t, void*);
            static void* operator new[](size_t, void*);
            static void operator delete(void*);
            static void operator delete[](void*);
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
            static MtAllocator* getAllocator();
        private:
            u32 mContentsListNum;  // offset: 0x0
        };
    public:
        class cGroupInfo
        {
            friend class rZone;
        public:
            cGroupInfo();
            ~cGroupInfo();
            void importGroupInfo(rZone& owner, u32 GroupIndex);
            void load(MtDataReader& r, rZone& owner);
            void save(MtDataWriter& w, rZone& owner);
            u32 getRegisterLayoutNum() const;
            u32 getGlobalShapeNum() const;
            rZone::cMemoryHeader::cGridInfo getGroupGridInfo() const;
            u32 calculateRequiredMemoryAlign4() const;
            u32 calculateRequiredGridMemoryAlign4() const;
            static void* operator new(size_t);
            static void* operator new[](size_t sz);
            static void* operator new(size_t, void*);
            static void* operator new[](size_t, void*);
            static void operator delete(void*);
            static void operator delete[](void* padr);
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
            static MtAllocator* getAllocator();
        private:
            u32 mRegisterLayoutNum;  // offset: 0x0
            u32 mGlobalShapeNum;  // offset: 0x4
            rZone::cMemoryHeader::cGridInfo mGroupGridInfo;  // offset: 0x8
        };
    public:
        cMemoryHeader();
        ~cMemoryHeader();
        void importMemoryInfo(rZone& owner);

        friend class rZone;
        void load(MtDataReader& r, rZone& owner);
        void save(MtDataWriter& w, rZone& owner);
        void clear();
        u32 getLayoutNum() const;
        cLayoutInfo* getLayoutInfo(u32 index);
        u32 getGroupNum() const;
        cGroupInfo* getGroupInfo(u32 index);
        cContentsPoolInfo& getContentsInfo();
        u32 getGlobalLayoutIndexArrayNum() const;
        u32 getUniqueIDTableNum() const;
        cGridInfo& getGridInfo();
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    private:
        u32 mLayoutInfoNum;  // offset: 0x0
        cLayoutInfo* mpLayoutInfoArray;  // offset: 0x8
        u32 mGlobalLayoutIndexArrayNum;  // offset: 0x10
        u32 mGroupInfoNum;  // offset: 0x14
        cGroupInfo* mpGroupInfoArray;  // offset: 0x18
        cContentsPoolInfo mContentsPoolInfo;  // offset: 0x20
        u32 mUniqueIDTableNum;  // offset: 0x24
        cGridInfo mAllGridInfo;  // offset: 0x28
    };
public:
    class cGroupManager : public MtObject
    {
        friend class uSoundGenerator;
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cGroupManager();
        virtual ~cGroupManager();
        bool loadBeforeAllocateAlign4(nCollisionUtil::LoadBuffer& buffer, const rZone::cMemoryHeader::cGroupInfo& AllocateInfo, rZone& owner);
        bool loadBeforeAllocateAlign16(nCollisionUtil::LoadBuffer& buffer, const rZone::cMemoryHeader::cGroupInfo& AllocateInfo, rZone& owner);
        bool loadBinary(MtDataReader& r, nCollisionUtil::LoadBuffer& buffer);
        bool saveBinary(MtDataWriter& w);
        rZone* getOwner() const;
        u32 getIndex() const;
        s32 getGroupID() const;
        bool isNoGroupLayoutManager() const;
        u32 getGroupLayoutIndex(u32 GroupLayoutIndex) const;
        void swapGroupLayoutIndex(u32 GroupLayoutIndex0, u32 GroupLayoutIndex1);
        u32 getGroupLayoutIndexNum() const;
        u32 getGroupGlobalLayoutIndex(u32 GroupGlobalLayoutIndex) const;
        u32 getGroupGlobalLayoutIndexNum() const;
        u32 getBroadPhaseMode() const;
        cGridCollision* getGrid() const;
        cGridCollisionRegistInfo* getGridRegisterInfo(u32 index);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        void setOwner(rZone* pOwner);
        void setIndex(u32 index);
        void setGroupID(s32 GroupID);
        void setGroupLayoutIndex(u32 LayoutIndex, u32 TargetIndex);
        void setGroupLayoutIndexNum(u32 LayoutNum);
        void setGroupGlobalLayoutIndex(u32 LayoutIndex, u32 TargetIndex);
        void setGroupGlobalLayoutIndexNum(u32 LayoutNum);
        void deleteWorkMember();
    protected:
        rZone* mpOwner;  // offset: 0x8
        u32 mIndex;  // offset: 0x10
        s32 mGroupID;  // offset: 0x14
        u32 mLayoutIndexArrayNum;  // offset: 0x18
        u32* mpLayoutIndexArray;  // offset: 0x20
        u32 mGlobalLayoutIndexArrayNum;  // offset: 0x28
        u32* mpGlobalLayoutIndexArray;  // offset: 0x30
        u32 mBroadPhaseMode;  // offset: 0x38
        cGridCollision* mpGrid;  // offset: 0x40
        cGridCollisionRegistInfo* mpGridRegisterInfo;  // offset: 0x48
    public:
        static MyDTI DTI;
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    rZone();
    virtual ~rZone();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    const nZone::cLayoutElement* getLayoutElementConst(u32 index) const;
    nZone::cLayoutElement* getLayoutElement(u32 index);
    u32 getLayoutElementNum() const;
    void reloadBlocking();
    const nZone::cLayoutElement* getLayoutElementFromUniqueIDConst(u32 UniqueID) const;
    u32 getContentsNum() const;
    nZone::cContentsPool& getContentsPool();
    const MtString& getCategoryName() const;
    u32 getCategoryClassDtiID() const;
    u32 getCategoryAttribute() const;
    u32 getLayoutIndexFromUniqueID(u32 UniqueID) const;
    u32 getUniqueIDToIndexTableNum() const;
    cGroupManager* getGroupManagerFromIndex(u32 index) const;
    cGroupManager* getGroupManagerFromID(s32 SearchGroupID) const;
    cGroupManager* getGroupManagerNoRegisterGroup() const;
    u32 getGroupManagerNum() const;
    u32 getGlobalLayoutIndex(u32 GlobalLayoutIndex) const;
    u32 getGlobalLayoutIndexNum() const;
    u32 getBroadPhaseMode() const;
    cGridCollision* getGrid() const;
    cGridCollisionRegistInfo* getGridRegisterInfo(u32 index);
protected:
    void loadMemoryAllocateInfo(MtDataReader& r, cMemoryHeader& MemoryInfo);
    bool bulkMemoryAllocate(cMemoryHeader& MemoryInfo, nCollisionUtil::LoadBuffer& buffer);
    bool divideMemory(cMemoryHeader& MemoryInfo, nCollisionUtil::LoadBuffer& buffer);
    void saveMemoryAllocateInfo(MtDataWriter& w);
    const nZone::cLayoutElement* getNativeLayoutElementConst(u32 index) const;
    nZone::cLayoutElement* getNativeLayoutElement(u32 index);
    u32 getNativeLayoutElementNum() const;
    void setUniqueID2IndexForIO(u32 Index, u32 TargetUniqueID);
    void setUniqueIDToIndexTableNumForIO(u32 TableElementNum);
protected:
    u32 mCategoryVersion;  // offset: 0x70
    u32 mCategoryAttribute;  // offset: 0x74
    MtString mCategoryName;  // offset: 0x78
    u32 mCategoryDtiID;  // offset: 0x80
    nZone::cLayoutElement* mpLayoutElements;  // offset: 0x88
    u32 mLayoutElementsNum;  // offset: 0x90
    u32 mGlobalLayoutIndexArrayNum;  // offset: 0x94
    u32* mpGlobalLayoutIndexArray;  // offset: 0x98
    nZone::cContentsPool mContentsPool;  // offset: 0xa0
    u32* mpUniqueIDTable;  // offset: 0xd0
    u32 mUniqueIDTableNum;  // offset: 0xd8
    cGroupManager* mpGroupManagerArray;  // offset: 0xe0
    u32 mGroupManagerArrayNum;  // offset: 0xe8
    u32 mBroadPhaseMode;  // offset: 0xec
    cGridCollision* mpGrid;  // offset: 0xf0
    cGridCollisionRegistInfo* mpGridRegisterInfo;  // offset: 0xf8
public:
    static MyDTI DTI;
    static const u32 DATA_MAGIC = 7237498;
    static const u32 DATA_VERSION = 2016020100;
    static const u32 INVALID_INDEX = 4294967295;
    static const u32 INVALID_UNIQUE_ID = 4294967295;
    static const s32 INVALID_GROUP_ID = -1;
};

inline void* rZone::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rZone::rZone() {
    mCategoryVersion = 0;
    mCategoryAttribute = 0x17FF;
    mCategoryName = "";
    mCategoryDtiID = 0;
    mpUniqueIDTable = nullptr;
    mUniqueIDTableNum = 0;
    mpGroupManagerArray = nullptr;
    mGroupManagerArrayNum = 0;
    mpGlobalLayoutIndexArray = nullptr;
    mLayoutElementsNum = 0;
    mGlobalLayoutIndexArrayNum = 0;
    mpLayoutElements = nullptr;
    mpGridRegisterInfo = nullptr;
    mpGrid = nullptr;
    this->::cResource::mAttr = 18;
}

inline void* rZone::cGroupManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rZone::cGroupManager::cGroupManager() {
    this->mpOwner = nullptr;
    this->mGroupID = -1;
    this->mpLayoutIndexArray = nullptr;
    this->mLayoutIndexArrayNum = 0;
    this->mpGlobalLayoutIndexArray = nullptr;
    this->mGlobalLayoutIndexArrayNum = 0;
    this->mpGridRegisterInfo = nullptr;
    this->mpGrid = nullptr;
}

inline rZone::cMemoryHeader::cGridInfo::cGridInfo() {
    mGridRegisterNum = 0;
    mGridCellNum = 0;
}

inline rZone::cMemoryHeader::cContentsPoolInfo::cContentsPoolInfo() {
    mContentsListNum = 0;
}

inline rZone::cMemoryHeader::cLayoutInfo::cLayoutInfo() : mShapeType(0) {
}
inline rZone::cMemoryHeader::cLayoutInfo::~cLayoutInfo() {
}
inline void* rZone::cMemoryHeader::cLayoutInfo::operator new[](size_t sz) {
    return MtMemory::mpAllocatorType[7]->memAlloc(sz, 16u);
}
inline void rZone::cMemoryHeader::cLayoutInfo::operator delete[](void* padr) {
    MtMemory::mpAllocatorType[7]->memFree(padr);
}
inline void rZone::cMemoryHeader::cLayoutInfo::load(MtDataReader& r) {
    mShapeType = r.readU32();
}
inline void rZone::cMemoryHeader::cLayoutInfo::save(MtDataWriter& w) {
    w.writeU32(mShapeType);
}
inline u32 rZone::cMemoryHeader::cLayoutInfo::getShapeType() const {
    return mShapeType;
}
inline u32 rZone::cMemoryHeader::cLayoutInfo::calculateRequiredMemoryAlign16() const {
    switch (static_cast<s32>(mShapeType)) {
    case 0:
        return sizeof(nZone::ShapeInfoBase);
    case 1:
        return sizeof(nZone::ShapeInfoArea);
    case 2:
        return sizeof(nZone::ShapeInfoAABB);
    case 3:
        return sizeof(nZone::ShapeInfoOBB);
    case 4:
        return sizeof(nZone::ShapeInfoSphere);
    case 5:
        return sizeof(nZone::ShapeInfoCapsule);
    case 6:
        return sizeof(nZone::ShapeInfoCylinder);
    case 7:
        return 0x20;
    case 8:
        return 0x30;
    case 9:
        return sizeof(nZone::ShapeInfoPanel);
    case 10:
        return sizeof(nZone::ShapeInfoCone);
    case 11:
        return sizeof(nZone::ShapeInfoGlobal);
    }
    return 0;
}

inline rZone::cMemoryHeader::cGridInfo::~cGridInfo() {
}
inline void rZone::cMemoryHeader::cGridInfo::load(MtDataReader& r) {
    mGridRegisterNum = r.readU32();
    mGridCellNum = r.readU32();
}
inline void rZone::cMemoryHeader::cGridInfo::save(MtDataWriter& w) {
    w.writeU32(mGridRegisterNum);
    w.writeU32(mGridCellNum);
}
inline u32 rZone::cMemoryHeader::cGridInfo::getGridCellNum() const {
    return mGridCellNum;
}
inline u32 rZone::cMemoryHeader::cGridInfo::calculateRequiredMemoryAlign4() const {
    return mGridRegisterNum * sizeof(u32) + mGridCellNum * 8;
}

inline rZone::cMemoryHeader::cContentsPoolInfo::~cContentsPoolInfo() {
}
inline void rZone::cMemoryHeader::cContentsPoolInfo::load(MtDataReader& r) {
    mContentsListNum = r.readU32();
}
inline void rZone::cMemoryHeader::cContentsPoolInfo::save(MtDataWriter& w) {
    w.writeU32(mContentsListNum);
}
inline u32 rZone::cMemoryHeader::cContentsPoolInfo::getContentsListNum() const {
    return mContentsListNum;
}
inline u32 rZone::cMemoryHeader::cContentsPoolInfo::calculateRequiredMemoryAlign4() const {
    return mContentsListNum * sizeof(nZone::cContentsPool::cContentsList);
}

inline rZone::cMemoryHeader::cGroupInfo::cGroupInfo() : mRegisterLayoutNum(0), mGlobalShapeNum(0) {
}
inline rZone::cMemoryHeader::cGroupInfo::~cGroupInfo() {
}
inline void* rZone::cMemoryHeader::cGroupInfo::operator new[](size_t sz) {
    return MtMemory::mpAllocatorType[7]->memAlloc(sz, 16u);
}
inline void rZone::cMemoryHeader::cGroupInfo::operator delete[](void* padr) {
    MtMemory::mpAllocatorType[7]->memFree(padr);
}
inline void rZone::cMemoryHeader::cGroupInfo::load(MtDataReader& r, rZone& owner) {
    mRegisterLayoutNum = r.readU32();
    mGlobalShapeNum = r.readU32();
    if (owner.mBroadPhaseMode == 1) {
        mGroupGridInfo.load(r);
    }
}
inline void rZone::cMemoryHeader::cGroupInfo::save(MtDataWriter& w, rZone& owner) {
    w.writeU32(mRegisterLayoutNum);
    w.writeU32(mGlobalShapeNum);
    if (owner.mBroadPhaseMode == 1) {
        mGroupGridInfo.save(w);
    }
}
inline u32 rZone::cMemoryHeader::cGroupInfo::getRegisterLayoutNum() const {
    return mRegisterLayoutNum;
}
inline u32 rZone::cMemoryHeader::cGroupInfo::getGlobalShapeNum() const {
    return mGlobalShapeNum;
}
inline rZone::cMemoryHeader::cGridInfo rZone::cMemoryHeader::cGroupInfo::getGroupGridInfo() const {
    return mGroupGridInfo;
}
inline u32 rZone::cMemoryHeader::cGroupInfo::calculateRequiredMemoryAlign4() const {
    return (mRegisterLayoutNum + mGlobalShapeNum) * sizeof(u32);
}
inline u32 rZone::cMemoryHeader::cGroupInfo::calculateRequiredGridMemoryAlign4() const {
    return mGroupGridInfo.calculateRequiredMemoryAlign4();
}

inline rZone::cMemoryHeader::cMemoryHeader()
    : mLayoutInfoNum(0), mpLayoutInfoArray(nullptr), mGlobalLayoutIndexArrayNum(0), mGroupInfoNum(0),
      mpGroupInfoArray(nullptr), mUniqueIDTableNum(0) {
}
inline void rZone::cMemoryHeader::clear() {
    mLayoutInfoNum = 0;
    if (mpLayoutInfoArray != nullptr) {
        delete[] mpLayoutInfoArray;
        mpLayoutInfoArray = nullptr;
    }
    mGroupInfoNum = 0;
    if (mpGroupInfoArray != nullptr) {
        delete[] mpGroupInfoArray;
        mpGroupInfoArray = nullptr;
    }
    mGlobalLayoutIndexArrayNum = 0;
    mUniqueIDTableNum = 0;
}
inline rZone::cMemoryHeader::~cMemoryHeader() {
    clear();
}
inline u32 rZone::cMemoryHeader::getLayoutNum() const {
    return mLayoutInfoNum;
}
inline rZone::cMemoryHeader::cLayoutInfo* rZone::cMemoryHeader::getLayoutInfo(u32 index) {
    return index < mLayoutInfoNum ? &mpLayoutInfoArray[index] : nullptr;
}
inline u32 rZone::cMemoryHeader::getGroupNum() const {
    return mGroupInfoNum;
}
inline rZone::cMemoryHeader::cGroupInfo* rZone::cMemoryHeader::getGroupInfo(u32 index) {
    return index < mGroupInfoNum ? &mpGroupInfoArray[index] : nullptr;
}
inline u32 rZone::cMemoryHeader::getGlobalLayoutIndexArrayNum() const {
    return mGlobalLayoutIndexArrayNum;
}
inline u32 rZone::cMemoryHeader::getUniqueIDTableNum() const {
    return mUniqueIDTableNum;
}

inline bool rZone::cGroupManager::loadBeforeAllocateAlign4(nCollisionUtil::LoadBuffer& buffer, const rZone::cMemoryHeader::cGroupInfo& AllocateInfo, rZone& owner) {
    deleteWorkMember();
    mpOwner = &owner;
    mLayoutIndexArrayNum = AllocateInfo.getRegisterLayoutNum();
    mpLayoutIndexArray = static_cast<u32*>(buffer.allocate(mLayoutIndexArrayNum * sizeof(u32)));
    mGlobalLayoutIndexArrayNum = AllocateInfo.getGlobalShapeNum();
    mpGlobalLayoutIndexArray = static_cast<u32*>(buffer.allocate(mGlobalLayoutIndexArrayNum * sizeof(u32)));
    mBroadPhaseMode = owner.mBroadPhaseMode;
    return true;
}

inline cGridCollision* rZone::cGroupManager::getGrid() const {
    return mpGrid;
}
inline nZone::cLayoutElement* rZone::getLayoutElement(u32 index) {
    return index < mLayoutElementsNum ? &mpLayoutElements[index] : nullptr;
}
inline void rZone::cMemoryHeader::cLayoutInfo::importLayoutInfo(rZone& owner, u32 LayoutIndex) {
    mShapeType = owner.getLayoutElement(LayoutIndex)->getShapeType();
}
inline void rZone::cMemoryHeader::cGridInfo::importGridInfo(cGridCollision& owner) {
    mGridRegisterNum = owner.mStaticGridRegistParamNum;
    mGridCellNum = owner.mGridNumX * owner.mGridNumZ;
}
inline void rZone::cMemoryHeader::cContentsPoolInfo::importContentsPoolInfo(rZone& owner) {
    mContentsListNum = owner.mContentsPool.mContentsListArray.length();
}
inline void rZone::cMemoryHeader::cGroupInfo::importGroupInfo(rZone& owner, u32 GroupIndex) {
    rZone::cGroupManager& Group = owner.mpGroupManagerArray[GroupIndex];
    mRegisterLayoutNum = Group.getGroupLayoutIndexNum();
    mGlobalShapeNum = Group.getGroupGlobalLayoutIndexNum();
    if (owner.mBroadPhaseMode == 1) {
        cGridCollision* pGrid = Group.getGrid();
        if (pGrid != nullptr) {
            mGroupGridInfo.importGridInfo(*pGrid);
        }
    }
}
