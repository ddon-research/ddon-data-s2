#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollisionMath.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive3D.h"

// Forward declarations
class MtAABB;
class MtAABB4;
class MtAllocator;
namespace MtCollisionUtil { class MtVectorU4; }
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtGeometry;
class MtLineSegment;
class MtMatrix;
class MtRay;
class MtRayY;
namespace nCollisionUtil { struct LoadBuffer; }

// Declarations
class cBVHCollision;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using JOBHANDLE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cBVHCollision : public MtObject
{
public:
    enum
    {
        CHILD_ID_LEFT = 0,
        CHILD_ID_RIGHT = 1,
        CHILD_ID_NUM = 2,
        CHILD_ID_OPT_LEFT_L = 0,
        CHILD_ID_OPT_LEFT_R = 1,
        CHILD_ID_OPT_RIGHT_L = 2,
        CHILD_ID_OPT_RIGHT_R = 3,
        CHILD_ID_OPT_NUM = 4,
    };
public:
    class MyDTI;
    struct TraverseStack;
    class NodeBinaryBasic;
    class NodeBinaryCommon;
    struct NodeQuad;
    struct NodeQuadBase;
    struct Header;
    struct NodeBinaryOptimize;
    class cWorkBuildOnlineFast;
    struct JobParamOfLine;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct alignas(16) TraverseStack
    {
    public:
        enum EREGIST_NODE_ID
        {
            eNODE_ID_COMMON = 0,
            eNODE_ID_NUM = 1,
        };
    public:
        void initializeBinary(cBVHCollision::NodeBinaryBasic*);
        void initializeQuad(cBVHCollision::NodeQuad*);
        cBVHCollision::TraverseStack& copy(cBVHCollision::TraverseStack& src);
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
        MtCollisionUtil::MtVectorU4 aFlgHitAll;  // offset: 0x0
        union
        {
        public:
            struct
            {
            public:
                u8 aFlgNode[4];  // offset: 0x0
            };  // offset: 0x0
            u32 aFlgNodeAll;  // offset: 0x0
        };  // offset: 0x10
        union
        {
        public:
            struct
            {
            public:
                u8 aFlgLeaf[4];  // offset: 0x0
            };  // offset: 0x0
            u32 aFlgLeafAll;  // offset: 0x0
        };  // offset: 0x14
        void* pRegistNodePtr[1];  // offset: 0x18
        u8 aFlgHit[4];  // offset: 0x20
    };
public:
    class NodeBinaryCommon
    {
    public:
        NodeBinaryCommon();
        void registNode(u16 NodeIndex, u32 cid);
        u8 isRegistedNode(u32 cid) const;
        void registLeaf(u16 LeafIndex, u32 cid);
        u8 isRegistedLeaf(u32 cid) const;
        u8 isRegistedAny(u32 cid) const;
        u16 getChildIndex(u32 cid) const;
        void setStatus(u8);
        u8 getStatus() const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(u32);
        void memFree(void*);
        size_t memSize(void*);
    public:
        u16 ChildIndex[2];  // offset: 0x0
        u8 Status;  // offset: 0x4
    };
public:
    struct NodeQuadBase
    {
    public:
        void setRegistNodeStatus(u32);
        void setRegistLeafStatus(u32);
        u8 isRegistNode(u32) const;
        u8 isRegistLeaf(u32) const;
        u8 isRegistAny(u32 cid) const;
        u32 isRegistNodeAll() const;
        u32 isRegistLeafAll() const;
        u16 isRegistedChild(u32) const;
        u16 getChildIndex(u32 cid) const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(u32);
        void memFree(void*);
        size_t memSize(void*);
    public:
        union
        {
        public:
            struct
            {
            public:
                u8 Status;  // offset: 0x0
                u8 Status0;  // offset: 0x1
                u8 Status1;  // offset: 0x2
                u8 Status2;  // offset: 0x3
            };  // offset: 0x0
            u32 StatusU32;  // offset: 0x0
        };  // offset: 0x0
        u16 ChildIndex[4];  // offset: 0x4
        u32 _padding;  // offset: 0xc
    };
public:
    struct Header
    {
    public:
        const MtAABB& getBoundingAABB() const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(u32);
        void memFree(void*);
        size_t memSize(void*);
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
        u32 type;  // offset: 0x8
        MtAABB aabb;  // offset: 0x10
        u32 NodeNum;  // offset: 0x30
        u32 LeafNum;  // offset: 0x34
        bool FlgBasicAllocedMultiple;  // offset: 0x38
        bool FlgNodeOutsideAllocateMemory;  // offset: 0x39
    };
public:
    struct NodeBinaryOptimize
    {
    public:
        const MtAABB& getChildAABB(u32) const;
        void setChildAABB(const MtAABB&, u32);
        void registNode(u16, u32);
        u8 isRegistedNode(u32 cid) const;
        void registLeaf(u16, u32);
        u8 isRegistedLeaf(u32 cid) const;
        u8 isRegistedAny(u32 cid) const;
        u16 getChildIndex(u32 cid) const;
        void setStatus(u8);
        u8 getStatus() const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(u32);
        void memFree(void*);
        size_t memSize(void*);
    public:
        MtAABB ChildAABB[2];  // offset: 0x0
        cBVHCollision::NodeBinaryCommon NodeCommon;  // offset: 0x40
    };
public:
    class cWorkBuildOnlineFast : public MtObject
    {
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
        cWorkBuildOnlineFast();
        virtual ~cWorkBuildOnlineFast();
        void allocateOnlineStack();
        void initializeBuildOnlineFastOutsideParam(MtAABB* aabbArray);
        void* memAlloc(size_t s);
        void memFree(void* padr);
        size_t memSize(void*);
    public:
        bool mFlgMyLocalAABB;  // offset: 0x8
        MtAABB* mpLocalAABB;  // offset: 0x10
        s32 mNowNodeUseID;  // offset: 0x18
        s32 mNowNodeMax;  // offset: 0x1c
        bool mFlgUsedBuildOnlineFast;  // offset: 0x20
        cBVHCollision::JobParamOfLine* mpStackOnlineBuildAll;  // offset: 0x28
        cBVHCollision::JobParamOfLine* mpStackOnlineBuild[19];  // offset: 0x30
        u32 mNestIndex[25];  // offset: 0xc8
        u32 mNestNum;  // offset: 0x12c
        static MyDTI DTI;
    };
public:
    struct JobParamOfLine
    {
    public:
        void initialize(cBVHCollision::NodeBinaryBasic*, u32, u32, u32);
    public:
        JOBHANDLE handle;  // offset: 0x0
        cBVHCollision::NodeBinaryBasic* pRootNode;  // offset: 0x8
        u32 LeafOffset;  // offset: 0x10
        u32 LeafNum;  // offset: 0x14
        u32 Nest;  // offset: 0x18
    };
public:
    class NodeBinaryBasic
    {
    public:
        NodeBinaryBasic();
        ~NodeBinaryBasic();
        void registNode(cBVHCollision::NodeBinaryBasic* pSet, u32 cid);
        cBVHCollision::NodeBinaryBasic* getNodePtr(u32 cid) const;
        void registNoDelete(u32 cid);
        void unregistNoDelete(u32);
        bool isRegistedNoDelete(u32 cid) const;
        const MtAABB& getAABB() const;
        void setAABB(const MtAABB& aabb);
        bool isIntersectRayY(const MtRayY&) const;
        bool isIntersectRay(const MtRay&) const;
        bool isIntersectLS(const MtLineSegment&) const;
        bool isIntersectAABB(const MtAABB&) const;
        bool isIntersectRayY(u32, const MtRayY&) const;
        bool isIntersectRay(u32, const MtRay&) const;
        bool isIntersectLS(u32, const MtLineSegment&) const;
        bool isIntersectAABB(u32, const MtAABB&) const;
        bool isIntersect(const MtGeometry&) const;
        bool isIntersect(u32, const MtGeometry&) const;
        void registNode(u16 NodeIndex, u32 cid);
        u8 isRegistedNode(u32 cid) const;
        void registLeaf(u16 LeafIndex, u32 cid);
        u8 isRegistedLeaf(u32 cid) const;
        u8 isRegistedAny(u32) const;
        u16 getChildIndex(u32 cid) const;
        void setStatus(u8);
        u8 getStatus() const;
        static void* operator new(size_t);
        static void* operator new[](size_t sz);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void* padr);
        static void operator delete[](void* padr);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    public:
        MtAABB ThisAABB;  // offset: 0x0
        cBVHCollision::NodeBinaryCommon NodeCommon;  // offset: 0x20
        bool aFlgDelete[2];  // offset: 0x26
        cBVHCollision::NodeBinaryBasic* pChild[2];  // offset: 0x28
    };
public:
    struct NodeQuad : public cBVHCollision::NodeQuadBase
    {
    public:
        void initialize(const MtAABB& aabb);
        void initialize(const MtAABB4& aabb4);
        MtCollisionUtil::MtVectorU4 isIntersectRayYAll(const MtRayY& rayY) const;
        MtCollisionUtil::MtVectorU4 isIntersectRayAll(const MtRay& ray) const;
        MtCollisionUtil::MtVectorU4 isIntersectLSAll(const MtLineSegment& ls) const;
        MtCollisionUtil::MtVectorU4 isIntersectAABBAll(const MtAABB& aabb) const;
        MtCollisionUtil::MtVectorU4 isIntersectAABB4All(const MtAABB4& aabb) const;
        MtAABB getChildAABB(u32 ChildIdx) const;
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t);
        static void operator delete[](void*);
        void* memAlloc(u32);
        void memFree(void*);
        size_t memSize(void*);
    public:
        MtAABB4 NodeAABB;  // offset: 0x10
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
    cBVHCollision();
    virtual ~cBVHCollision();
    bool load(MtDataReader& fin, nCollisionUtil::LoadBuffer* pBuffer);
    bool save(MtDataWriter& fout);
    bool loadCore(MtDataReader& fin, bool FlgEndianChenge, nCollisionUtil::LoadBuffer* pBuffer);
    bool saveCore(MtDataWriter& fout, bool FlgEndianChange);
    void clear();
    void allocateOnlineStack();
    u32 getInsideWorkSize() const;
    void buildOnlineFast(const MtAABB& TotalAABB, MtAABB* aabbArray, bool FlgForceRebuild);
    bool copy(cBVHCollision& src, const MtMatrix& mat);
    void registOwnerOnlineFastOnly(MtObject* pOwner, u32 LeafNum);
    const MtAABB& getRootAABB() const;
    u32 getLeafNum() const;
protected:
    void buildOnlineFast_MemoryAllocate();
    void buildOnlineFastCore(bool FlgForceRebuild);
    void registOwnerCore(MtObject* pOwner, u32 LeafNum, bool FlgUseOnline, bool FlgUseOnlineFastOnly);
    void countNodeAndLeaf(NodeBinaryBasic& NowNode, u32& NodeCount, u32& LeafCount);
    void deleteNodeBinaryBase();
    void deleteNodeBinaryBaseCore(NodeBinaryBasic* pNowNode);
    static void initializeBVHSystemBuffer();
    static void releaseBVHSystemBuffer();
public:
    void* memAlloc(u32 size);
    void memFree(void* p_addr);
protected:
    Header mHeader;  // offset: 0x10
    NodeBinaryBasic* mpRootNodeBinary;  // offset: 0x50
    NodeBinaryOptimize* mpRootNodeBinaryOptimize;  // offset: 0x58
    NodeQuad* mpRootNodeQuad;  // offset: 0x60
    u16* mpLeafIndexArray;  // offset: 0x68
    cWorkBuildOnlineFast* mpBuildOnlineWork;  // offset: 0x70
public:
    static MyDTI DTI;
    static const u32 CBVHCOLLISION_VERSION;
    static const u16 INVALID_INDEX = 65535;
    static const u32 MAX_JOBNUM = 32;
    static const u32 MAX_NEST = 25;
    static const u8 TRAVERSE_STACK_NUM = 255;
    static const u32 BUILD_ONLINE_MAX_STACK = 19;
    static const u8 TRAVERSE_MAX_NEST = 2;
protected:
    static TraverseStack* mpTraverseStack[2][19];
    static u32 mTraverseStackNest[19];
};
