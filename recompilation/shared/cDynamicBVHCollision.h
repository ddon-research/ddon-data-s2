#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollisionUtil.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "nCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
namespace MtCollisionUtil { class MtArrayEx; }
class MtDTI;
class MtGeometry;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;

// Declarations
class cDynamicBVHCollision;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cDynamicBVHCollision : public nCollision::cAllocaterIntermediate
{
public:
    enum UPDATE_LEVEL
    {
        UPDATE_LV0 = 0,
        UPDATE_LV1 = 1,
        UPDATE_LV2 = 2,
    };
public:
    class MyDTI;
    class Node;
public:
    using cNodeStackArray = MtCollisionUtil::MtArrayTemplate<cDynamicBVHCollision::Node*, false, 2>;
    using TRAVERSE_CALLBACK = u32(MtObject::*)(MtGeometry&, MtObject*, void*);
    using TRAVERSE_CALLBACK_CONST = u32(MtObject::*)(const MtGeometry&, MtObject*, const void*);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Node : public MtObject
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
        Node(const MtAABB& aabb, MtObject* pLeaf);
        Node(cDynamicBVHCollision::Node* pParent, cDynamicBVHCollision::Node* pChild0, cDynamicBVHCollision::Node* pChild1);
        virtual ~Node();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void initialize(const MtAABB& aabb, MtObject* pLeaf);
        void initialize(cDynamicBVHCollision::Node* pParent, cDynamicBVHCollision::Node* pChild0, cDynamicBVHCollision::Node* pChild1);
        bool isLeaf();
        const MtAABB& getAABB() const;
    protected:
        void registAABB(const MtAABB& aabb);
    protected:
        cDynamicBVHCollision::Node* mpParent;  // offset: 0x8
        union
        {
        public:
            struct
            {
            public:
                cDynamicBVHCollision::Node* mpChild[2];  // offset: 0x0
            };  // offset: 0x0
            MtObject* mpLeaf;  // offset: 0x0
        };  // offset: 0x10
        MtAABB mAABB;  // offset: 0x20
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
    cDynamicBVHCollision();
    virtual ~cDynamicBVHCollision();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    MtAABB getBoundingAABB() const;
    bool isEnableRoot() const;
    Node* insertLeaf(const MtAABB& aabb, MtObject* pLeafObject);
    void updateLeaf(const MtAABB& aabb, Node* pNode, UPDATE_LEVEL UpdateLV);
    void removeLeaf(Node* pRemoveNode);
    void removeAll();
    void removeWorkBuffer();
    bool reserveNode(u32 ReserveNum);
    void unregistAll();
    u32 getInsertLeafNum() const;
    u32 traverseByRecursive(MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, TRAVERSE_CALLBACK pCallbackFunc, void* pUserPtr, bool FlgOneHitEnd);
    u32 traverseByRecursiveConst(const MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, TRAVERSE_CALLBACK_CONST pCallbackFunc, const void* pUserPtr, bool FlgOneHitEnd);
    u32 traverse(const MtAABB& TraverseAABB, MtObject* pCallbackOwner, TRAVERSE_CALLBACK pCallbackFunc, void* pUserPtr, bool FlgOneHitEnd, u32 ThreadIndex);
    u32 traverse(MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, TRAVERSE_CALLBACK pCallbackFunc, void* pUserPtr, bool FlgOneHitEnd, u32 ThreadIndex);
    u32 traverseConst(const MtGeometry& TraverseGeometry, MtObject* pCallbackOwner, TRAVERSE_CALLBACK_CONST pCallbackFunc, const void* pUserPtr, bool FlgOneHitEnd, u32 ThreadIndex);
    void setUpdateLeafBackNum(s32 BackNum);
    s32 getUpdateLeafBackNum() const;
    u32 getNoUseNodeArrayNum() const;
    bool isEnableSplitAndStock() const;
    void setDeleteSbcOnRemove(bool);
    void applyWorldOffset(const MtVector3& offset);
    void drawWireFrame();
protected:
    void applyWorldOffsetCore(const MtVector3& offset, Node* pNowNode);
    void insertLeaf(Node* pStartNode, Node* pInsertLeafNode);
    void removeLeaf(Node* pRemoveNode, bool FlgSplitStock);
    Node* createNewNodeForLeaf(const MtAABB& aabb, MtObject* pLeaf);
    Node* createNewNodeForNode(Node* pParent, Node* pChild0, Node* pChild1);
    Node* createNewNodeForNode();
    void splitAndStockNode(Node* pNode);
    u32 getNodeParentChildIndex(Node* pNode);
    f32 getManhattanDistance(const MtAABB& aabbA, const MtAABB& aabbB);
    MtVector3 getManhattanDistanceBySIMD(const MtAABB&, const MtAABB&);
    bool isInside(const MtAABB& aabbA, const MtAABB& aabbB);
    void drawWireFrameCore(Node* pNowNode, u32 NestNum);
    void unregistAllCore(Node* pNowNode);
    void deleteTreeAll();
    void deleteTreeAllCore(Node* pNowNode);
    bool isReservedNode(Node* pNowNode);
    void setDummyU32(u32);
private:
    bool isIntersectXZ(const MtAABB& aabb0, const MtAABB& aabb1);
    void* memAlloc(size_t s);
    void memFree(void* padr);
    size_t memSize(void*);
    static void initializeDBVTSystemBuffer();
    static void releaseDBVTSystemBuffer();
    static void releaseDBVTSystemWorkBuffer();
protected:
    Node* mpRoot;  // offset: 0x8
    s32 mUpdateBackNum;  // offset: 0x10
    u32 mLeafNum;  // offset: 0x14
    Node* mpReservedNodeArray;  // offset: 0x18
    Node* * mppReservedNodeNoUseArray;  // offset: 0x20
    u32 mReservedNodeNoUseNum;  // offset: 0x28
    u32 mReservedNodeNoUseMax;  // offset: 0x2c
    MtCollisionUtil::MtArrayEx mNoUseNodeArray;  // offset: 0x30
    bool mIsEnableSplitAndStock;  // offset: 0x68
public:
    static MyDTI DTI;
    static const u32 MAX_TRAVERSE_NEST = 3;
protected:
    static u32 mTraverseStackNest[19];
    static cNodeStackArray* mpTraverseStackArrayRoot;
    static cNodeStackArray* mpTraverseStackArray[3][19];
};
