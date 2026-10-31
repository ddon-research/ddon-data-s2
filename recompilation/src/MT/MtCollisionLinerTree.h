#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;

// Declarations
namespace MtCollisionUtil { class MtLinerTree; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
namespace MtCollisionUtil { using MT_FUNC_PTR_32 = void(MtObject::*)(void*, u32); }
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using uintptr = __uintptr_t;

namespace MtCollisionUtil {
    class MtLinerTree : public ::MtObject
    {
    public:
        enum ETreeMode
        {
            eMODE_QUADTREE = 0,
            eMODE_OCTREE = 1,
            eMODE_MAX = 2,
        };
    public:
        class MyDTI;
        class cGridInfo;
        class cRegistInfo;
        class cRegistReserveInfo;
        struct CollisionCheckFunc;
    public:
        using FUNC_LOAD_NATIVE = bool(MtObject::*)(MtDataReader&, void*);
        using FUNC_SAVE_NATIVE = bool(MtObject::*)(MtDataWriter&, void*);
        using COLLISION_CHECK_FUNC = u32(MtObject::*)(const MtAABB&, void*, uintptr);
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cGridInfo
        {
        public:
            cGridInfo();
            ~cGridInfo();
            void add(void* pobj);
            void addChildElemNum(u32 ChildID);
            void subChildElemNum(u32 ChildID);
            u32 getChildElemNum(u32 ChildID);
            u32 getChildElemNumTotal();
            void set(void* pObj, u32 index);
            void erase(void* pObj);
            void erase(u32 index);
            void extendBuffer(u32 ElemNum);
            void* getElem(s32 index);
            u32 getElemNum();
            void resetData();
            static void* operator new(size_t);
            static void* operator new[](size_t sz);
            static void* operator new(size_t, void*);
            static void* operator new[](size_t, void*);
            static void operator delete(void*);
            static void operator delete[](void* padr);
            void* memAlloc(size_t s);
            void memFree(void* padr);
            size_t memSize(void*);
            static MtAllocator* getAllocator();
        protected:
            void* * mppArray;  // offset: 0x0
            u16 mLength;  // offset: 0x8
            u16 mBufSize;  // offset: 0xa
            u16 mChildElemNum[8];  // offset: 0xc
            u32 mChildElemNumTotal;  // offset: 0x1c
        };
    public:
        class cRegistInfo
        {
        public:
            cRegistInfo();
            ~cRegistInfo();
            bool isRegist();
            bool isReRegist(MtCollisionUtil::MtLinerTree::cRegistReserveInfo&);
            bool isReRegist(u32 NextMortonID);
            u32 getRegistID();
        public:
            u32 RegistID;  // offset: 0x0
            void* pRegistAddr;  // offset: 0x8
            bool FlgRegist;  // offset: 0x10
        };
    public:
        class cRegistReserveInfo : public ::MtObject
        {
        public:
            class MyDTI;
        public:
            class MyDTI : public ::MtDTI
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
            cRegistReserveInfo();
            virtual ~cRegistReserveInfo();
            const MtCollisionUtil::MtLinerTree::cRegistReserveInfo& operator=(const MtCollisionUtil::MtLinerTree::cRegistReserveInfo& src);
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
        public:
            u32 mTreeRootMortonID;  // offset: 0x8
            u32 mTreeRootIndex;  // offset: 0xc
            u32 mTreeCommonLevel;  // offset: 0x10
            u32 mTreeChildID;  // offset: 0x14
            MtCollisionUtil::MtLinerTree::cGridInfo* mpTreeTargetElemArray;  // offset: 0x18
            static MyDTI DTI;
        };
    public:
        struct CollisionCheckFunc
        {
        public:
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
        public:
            MtObject* pOwnerObj;  // offset: 0x0
            MtCollisionUtil::MtLinerTree::COLLISION_CHECK_FUNC pFunc;  // offset: 0x8
            void* pHitAddr;  // offset: 0x18
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
        MtLinerTree();
        virtual ~MtLinerTree();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void reRegistDataForChangeStatus(cGridInfo* OldTreeArray, u32 OldElemNumTotal);  // vtable slot 6
        void clear();
        bool loadNative(MtDataReader& fin);
        bool saveNative(MtDataWriter& fout);
        void registerCallbackOwner(MtObject* pNewOwner);
        void registCallbackStatusChange(MtCollisionUtil::MT_FUNC_PTR_32 pCallbackStatusChange);
        u32 registObject(void* pObj, const MtAABB& areaAABB, cRegistInfo& RegInfo);
        u32 registObject(void* pObj, cRegistReserveInfo& ReserveInfo, cRegistInfo& RegInfo);
        u32 registObjectCore(void* pObj, cRegistInfo& RegInfo, cGridInfo& ElemArray, u32 RootMortonID, u32 RootIndex, u32 CommonLevel, u32 ChildID);
        void unregistObject(cRegistInfo& cRegistInfo);
        bool setTreeStatus(const MtAABB& _areaAABB, u32 _Level, ETreeMode _TreeMode, bool FlgAnalizeMode);
        void resetDataAll();
        u32 traverse(const MtAABB& aabb, CollisionCheckFunc& ColInfo, uintptr param);
        u32 traverseParent(const MtAABB& aabb, u32 mid, CollisionCheckFunc& ColInfo, uintptr param);
        u32 traverseChild(const MtAABB& aabb, u32 mid, CollisionCheckFunc& ColInfo, uintptr param);
        cGridInfo& getAreaArray(const MtAABB& areaAABB, u32& RegistIDOut, u32& RootIndex, u32& CommonLevel, u32& ChildID);
        bool isRegistArea(const MtAABB& areaAABB);
        cRegistReserveInfo createRegistReserveInfo(const MtAABB& areaAABB);
        u32 getRegistTreeElemNum();
        size_t getUseMemory();
        MtAABB& getBoundingAABB();
        const MtAABB& getBoundingAABBConst() const;
        u32 getLevel() const;
        cGridInfo* getElementFromIndex(u32 index);
        cGridInfo* getElementFromLevelMorton(u32);
        cGridInfo* getElementFromLevelMorton(u32, u32);
        u32 getRootIDFromLevel(u32) const;
        u32 getElementArrayNum(u32) const;
        u32 getElementArrayNumTotal() const;
        u32 getAxisSplitNum(u32) const;
        const MtVector3& getAreaSize(u32 Level) const;
        void* memAlloc(size_t s);
        void memFree(void* padr);
        size_t memSize(void*);
    protected:
        u32 bitSeparate(u32 AxisElemID) const;
        u32 bitSeparate2D(u32 AxisElemID) const;
        u32 bitSeparate3D(u32 AxisElemID) const;
        u32 searchCommonLevel(u32& LevelOut, u32& ChildIDOut, u32 MortonA, u32 MortonB);
        cGridInfo* getCommonLevelElement(const MtVector3&, const MtVector3&);
        void convertPos2Number(const MtVector3& pos, u32& x, u32& y, u32& z) const;
        u32 convertPos2Morton(const MtVector3& pos) const;
        u32 convertNumber2Morton(u32 x, u32 y, u32 z) const;
        void convertMorton2Number(u32 MortonID, u32& Level, u32& x, u32& y, u32& z) const;
        u32 convertNumber2Morton2D(u32 x, u32 z) const;
        void convertMorton2Number2D(u32 MortonID, u32& Level, u32& x, u32& z) const;
        u32 convertNumber2Morton3D(u32 x, u32 y, u32 z) const;
        void convertMorton2Number3D(u32 MortonID, u32& Level, u32& x, u32& y, u32& z) const;
        u32 convertMortonChild2Parent(u32 BaseMortonID) const;
        u32 convertMortonParent2Child(u32 BaseMortonID) const;
        u32 convertMortonChild2Parent2D(u32 BaseMortonID) const;
        u32 convertMortonParent2Child2D(u32 BaseMortonID) const;
        u32 convertMortonChild2Parent3D(u32 BaseMortonID) const;
        u32 convertMortonParent2Child3D(u32 BaseMortonID) const;
        u32 createMorton(u32, u32, u32) const;
        u32 createMorton2D(u32 x, u32 z) const;
        u32 createMorton3D(u32 x, u32 y, u32 z) const;
        void calcUseMemory();
        u32 getMortonIDLevel(u32) const;
        u32 calcAxisSplitNum(u32 Level) const;
        f32 calcAxisSplitNumF(u32) const;
    protected:
        u32* mpAxisSplitNum;  // offset: 0x8
        u32* mpAxisSplitAreaNum;  // offset: 0x10
        u32* mpLevelRootIndex;  // offset: 0x18
        MtVector3 mAreaAABBMinPos;  // offset: 0x20
        MtVector3 mAreaAABBMaxPos;  // offset: 0x30
        MtVector3 mAreaAABBSize;  // offset: 0x40
        ETreeMode mTreeMode;  // offset: 0x50
        MtVector3* mpAreaSize;  // offset: 0x58
        MtVector3* mpAreaSizeR;  // offset: 0x60
        cGridInfo* mpTreeArray;  // offset: 0x68
        bool* mpFlgAnalizeTreeArray;  // offset: 0x70
        u32 mRegistElemNum;  // offset: 0x78
        u32 mTreeLevel;  // offset: 0x7c
        u32 mElemNumTotal;  // offset: 0x80
        MtObject* mpCallbackOwner;  // offset: 0x88
        MtCollisionUtil::MT_FUNC_PTR_32 mpCallbackStatusChange;  // offset: 0x90
        FUNC_LOAD_NATIVE mpCallbackLoadNative;  // offset: 0xa0
        FUNC_SAVE_NATIVE mpCallbackSaveNative;  // offset: 0xb0
        bool mFlgAnalizeMode;  // offset: 0xc0
    public:
        static MyDTI DTI;
        static const u32 SHIFT_SIZE_ARRAY[2];
        static const u32 SHIFT_PARAM_ARRAY[2];
        static const u32 TREE_CHILD_NUM_ARRAY[2];
        static const u32 TREE_CHILD_NUM_MAX = 8;
        static const u32 DEFAULT_LEVEL;
    };
}  // namespace MtCollisionUtil
