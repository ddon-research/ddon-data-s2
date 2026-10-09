#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class uDynamicSbc;
class uScrollCollisionGeometry;

// Declarations
namespace nCollision { struct ScrMaterialInfo; }
namespace nCollision { class cAllocaterIntermediate; }
namespace nCollision { class cScrCollisionMoveMatrix; }
namespace nCollision { class cScrCommonFilter; }
namespace nCollisionUtil { struct LoadBuffer; }
namespace nCollisionUtil { class cOwnerSystem; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nCollision {
    struct ScrMaterialInfo
    {
    public:
        bool operator==(const nCollision::ScrMaterialInfo& src) const;
        bool operator!=(const nCollision::ScrMaterialInfo& src) const;
        bool isEnableAttributeByAnd(const nCollision::ScrMaterialInfo& src) const;
        bool isTarget(u32 TargetAttribute, u32 scr_type);
        void setDefaultParam();
        MtUI* createUISupport(MtProperty& prop, MT_CTSTR AttributeName, MT_CTSTR* UserAttrName, u32 UIType);
        MtUI* createUISupport(MtProperty& prop, MT_CTSTR AttributeName, MT_CTSTR UserAttrName0, MT_CTSTR UserAttrName1, MT_CTSTR UserAttrName2, MT_CTSTR UserAttrName3, u32 TypeUI);
        void createPropertySupport(MtPropertyList& s, MtObject* pOwner, MT_CTSTR AttributeName, MT_CTSTR* UserAttrName, u32 AddAttribute);
        void createPropertySupport(MtPropertyList& s, MtObject* pOwner, MT_CTSTR AttributeName, MT_CTSTR UserAttrName0, MT_CTSTR UserAttrName1, MT_CTSTR UserAttrName2, MT_CTSTR UserAttrName3, u32 AddAttribute);
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
    public:
        u32 attribute;  // offset: 0x0
        u32 attr[4];  // offset: 0x4
        u32 pading[3];  // offset: 0x14
        static const u32 USER_ATTRIBUTE_NUM = 4;
    };
}  // namespace nCollision

namespace nCollision {
    class cAllocaterIntermediate : public ::MtObject
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
        cAllocaterIntermediate();
        virtual ~cAllocaterIntermediate();
    public:
        static MyDTI DTI;
    };
}  // namespace nCollision

namespace nCollision {
    class cScrCollisionMoveMatrix : public ::MtObject
    {
        // inferred: uScrollCollisionGeometry::isMoveByScrMatrix names uScrollCollisionGeometry::mScrMatrix.mFlgMoveEnable
        friend class ::uScrollCollisionGeometry;
    public:
        enum SCROLL_MOVE_MAT_ID
        {
            MAT_ID_NOW = 0,
            MAT_ID_HALF = 1,
            MAT_ID_OLD = 2,
            MAT_ID_NUM = 3,
        };
        enum MOVING_SCR_PARAM
        {
            MOVING_SCR_ID_NONE = 0,
            MOVING_SCR_ID_NONE_REGIST = 1,
            MOVING_SCR_ID_NONE_UNREGIST = 2,
            MOVING_SCR_ID_NUM_ADD_REGIST = 3,
            MOVING_SCR_ID_NUM_SUB_UNREGIST = 4,
            MOVING_SCR_ID_NUM_ADD_NOREGIST = 5,
            MOVING_SCR_ID_NUM_SUB_NOUNREGIST = 6,
            MOVING_SCR_ID_NOT_ACTIVE = 7,
        };
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
        cScrCollisionMoveMatrix();
        virtual ~cScrCollisionMoveMatrix();
        const MtMatrix& getMatrix() const;
        const MtMatrix& getHalfMatrix() const;
        const MtMatrix& getOldMatrix() const;
        const MtMatrix& getMatrixInverse() const;
        const MtMatrix& getHalfMatrixInverse() const;
        const MtMatrix& getOldMatrixInverse() const;
        MtMatrix getRelativeMatrix() const;
        MtMatrix& getMatrixByID(u32 id);
        const MtMatrix& getMatrixByIDConst(u32 id) const;
        MtMatrix& getMatrixInverseByID(u32 id);
        const MtMatrix& getMatrixInverseByIDConst(u32 id) const;
        u32 setMatrixForGame(const MtMatrix* pIntputMatrix, bool FlgResetSet, bool FlgAutoResetControl);
        void setMatrix(const MtMatrix&);
        void setOldMatrix(const MtMatrix&);
        void setHalfMatrix(const MtMatrix&);
        void setMatrixByID(const MtMatrix& InputMatrix, u32 id);
        bool isMatResetSet() const;
        void setMatResetSet(bool set);
        bool isMove() const;
        void setMove(bool set);
        bool isSupportScale() const;
        void setSupportScale(bool FlgEnableScale);
        const nCollision::cScrCollisionMoveMatrix& operator=(const nCollision::cScrCollisionMoveMatrix& src);
        bool allocMatrixByID(u32 id);
        void freeMatrixByID(u32 id);
        void* memAlloc(size_t s);
        void memFree(void* padr);
        size_t memSize(void*);
    protected:
        void initMatrixAll();
        MtMatrix getMatrixForTool();
        MtMatrix getHalfMatrixForTool();
        MtMatrix getOldMatrixForTool();
        void setDummyU32(u32);
        void setDummyMatrix(MtMatrix&);
    protected:
        bool maFlgAllocateMatrix[3];  // offset: 0x8
        bool mFlgMoveEnable;  // offset: 0xb
        bool mFlgMatResetSet;  // offset: 0xc
        MtMatrix* mpaMatrix[3];  // offset: 0x10
        MtMatrix* mpaMatrixInverse[3];  // offset: 0x28
        bool mFlgFirstSet;  // offset: 0x40
        bool mFlgScaleSupport;  // offset: 0x41
    public:
        static MyDTI DTI;
        static MtMatrix msMatIdentity;
    };
}  // namespace nCollision

namespace nCollision {
    class cScrCommonFilter : public ::MtObject
    {
        // inferred: uDynamicSbc::getSbcType names uDynamicSbc::mScrFilter.mScrType
        friend class ::uDynamicSbc;
        // inferred: uScrollCollisionGeometry::getScrType names uScrollCollisionGeometry::mScrFilter.mScrType
        friend class ::uScrollCollisionGeometry;
    public:
        enum GROUP_REGIST
        {
            GROUP_REGIST_00 = 0,
            GROUP_REGIST_01 = 1,
            GROUP_REGIST_02 = 2,
            GROUP_REGIST_03 = 3,
            GROUP_REGIST_04 = 4,
            GROUP_REGIST_05 = 5,
            GROUP_REGIST_06 = 6,
            GROUP_REGIST_07 = 7,
            GROUP_REGIST_08 = 8,
            GROUP_REGIST_09 = 9,
            GROUP_REGIST_10 = 10,
            GROUP_REGIST_11 = 11,
            GROUP_REGIST_12 = 12,
            GROUP_REGIST_13 = 13,
            GROUP_REGIST_14 = 14,
            GROUP_REGIST_15 = 15,
            GROUP_REGIST_16 = 16,
            GROUP_REGIST_17 = 17,
            GROUP_REGIST_18 = 18,
            GROUP_REGIST_19 = 19,
            GROUP_REGIST_20 = 20,
            GROUP_REGIST_21 = 21,
            GROUP_REGIST_22 = 22,
            GROUP_REGIST_23 = 23,
            GROUP_REGIST_24 = 24,
            GROUP_REGIST_25 = 25,
            GROUP_REGIST_26 = 26,
            GROUP_REGIST_27 = 27,
            GROUP_REGIST_28 = 28,
            GROUP_REGIST_29 = 29,
            GROUP_REGIST_30 = 30,
            GROUP_REGIST_31 = 31,
        };
        enum TYPE
        {
            TYPE_00 = 1,
            TYPE_01 = 2,
            TYPE_02 = 4,
            TYPE_03 = 8,
            TYPE_04 = 16,
            TYPE_05 = 32,
            TYPE_06 = 64,
            TYPE_07 = 128,
            TYPE_08 = 256,
            TYPE_09 = 512,
            TYPE_10 = 1024,
            TYPE_11 = 2048,
            TYPE_12 = 4096,
            TYPE_13 = 8192,
            TYPE_14 = 16384,
            TYPE_15 = 32768,
            TYPE_16 = 65536,
            TYPE_17 = 131072,
            TYPE_18 = 262144,
            TYPE_19 = 524288,
            TYPE_20 = 1048576,
            TYPE_21 = 2097152,
            TYPE_22 = 4194304,
            TYPE_23 = 8388608,
            TYPE_24 = 16777216,
            TYPE_25 = 33554432,
            TYPE_26 = 67108864,
            TYPE_27 = 134217728,
            TYPE_28 = 268435456,
            TYPE_29 = 536870912,
            TYPE_30 = 1073741824,
            TYPE_31 = -2147483648,
            TYPE_ALL = 2147483647,
        };
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
        cScrCommonFilter();
        virtual ~cScrCommonFilter();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void createPropertySupport(MtPropertyList& s, MtObject* pOwner, MT_CTSTR TypeName, MT_CTSTR GroupName, MT_CTSTR GroupNameIndex);
        u32 getScrType() const;
        void setScrType(u32 NewType);
        u32 getScrGroup() const;
        u8 getScrGroupIndex() const;
        void setScrGroup(u8 NewGroupIndex);
        void setScrGroupByBit(u32 GroupBit);
        bool isTarget(const nCollision::cScrCommonFilter&) const;
        bool isTarget(u32 TargetType, u32 TargetGroup) const;
        bool isTargetType(u32 TargetType) const;
        bool isTargetGroup(u32 TargetGroup) const;
        static bool isTargetGroupStatic_IndexBit(u32 ScrGroupIndex, u32 TargetGroupBit);
        nCollision::cScrCommonFilter& operator=(const nCollision::cScrCommonFilter& src);
    protected:
        u32 mScrType;  // offset: 0x8
        u32 mScrGroup;  // offset: 0xc
        u8 mScrGroupIndex;  // offset: 0x10
    public:
        static MyDTI DTI;
        static const u32 GROUP_MAX_NUM = 32;
    };
}  // namespace nCollision

namespace nCollisionUtil {
    struct LoadBuffer
    {
    public:
        bool initialize(MtAllocator& allocator, u32 BufferSize);
        void* allocate(u32 RequestSize);
        void adjustmentAlignment(u32 align);
    public:
        u8* pBuffer;  // offset: 0x0
        u32 Position;  // offset: 0x8
        u32 Size;  // offset: 0xc
    };
}  // namespace nCollisionUtil

namespace nCollisionUtil {
    class cOwnerSystem : public ::MtObject
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
        cOwnerSystem();
        virtual ~cOwnerSystem();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool isEnableOwner() const;
        void registOwner(MtObject* pOwner);
        void unregistOwner();
        MtObject* getRegistOwner() const;
    protected:
        MtObject* mpOwner;  // offset: 0x8
        bool mFlgRegistedOwner;  // offset: 0x10
        bool mFlgOwnerIsUnit;  // offset: 0x11
    public:
        static MyDTI DTI;
    };
}  // namespace nCollisionUtil
