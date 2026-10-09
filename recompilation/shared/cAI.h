#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cAITask.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
class MtDTI;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtTriangle;
class MtVector3;

// Declarations
class cAIGraph;
class cAIQuadTree;
class cAITreeBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using MT_MFUNC32 = void(MtObject::*)(u32);
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;

class cAIGraph : public cAITask
{
public:
    class MyDTI;
    class Node;
    class Link;
    class Area;
public:
    using NODE_COMPARE_FUNC = bool(MtObject::*)(MtObject*, MtObject*, f32&, u32&);
    using NODE_LINK_FUNC = bool(MtObject::*)(MtObject*, u32&, u32&, f32&, u32&);
    using NODE_AREA_FUNC = bool(MtObject::*)(MtObject*, u32&, u32&, f32&, u32&, bool);
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
        Node();
        virtual ~Node();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        cAIGraph::Node* getLink(u32 index);
    public:
        cAIGraph* mpParent;  // offset: 0x8
        MtObject* mpCurrent;  // offset: 0x10
        cAIGraph::Link* mpLink;  // offset: 0x18
        u16 mID;  // offset: 0x20
        u8 mNumberOfLink;  // offset: 0x22
        bool mAutoDeleteLink;  // offset: 0x23
        static MyDTI DTI;
    };
public:
    class Link
    {
    public:
        Link();
        static void* operator new(size_t s);
        static void* operator new[](size_t s);
        static void operator delete(void* padr);
        static void operator delete[](void* padr);
    public:
        cAIGraph::Node* mpCurrent;  // offset: 0x0
        f32 mCost;  // offset: 0x8
        cAIGraph::Link* mpNext;  // offset: 0x10
        u32 mData;  // offset: 0x18
        bool mEnable;  // offset: 0x1c
        s16 mReferenceCounter;  // offset: 0x1e
    };
public:
    class Area : public cAIGraph::Node
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
        Area();
        virtual ~Area();
    public:
        cAIGraph::Link* mpChild;  // offset: 0x28
        u8 mNumberOfChild;  // offset: 0x30
        bool mAutoDeleteChild;  // offset: 0x31
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
    cAIGraph();
    virtual ~cAIGraph();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void createGraph(NODE_COMPARE_FUNC func, MtObject* obj);
    void createGraph(NODE_LINK_FUNC func, MtObject* obj);
    void createGraph(MtProperty prop, u32 mNum, NODE_COMPARE_FUNC func, MtObject* obj);
    void createGraph(MtObject* prop, u32 mNum, u32 stride, NODE_COMPARE_FUNC func, MtObject* obj);
    void createGraph(MtObject* prop, MT_MFUNC32 func1, u32 mNum, NODE_COMPARE_FUNC func2, MtObject* obj);
    void createGraph(NODE_LINK_FUNC func, NODE_AREA_FUNC afunc, MtObject* obj, MtObject* aobj);
    Node* getNode(u32 index);
    Node* getNode(MtObject* obj);
    u32 getNumberOfNode();
    void setNumberOfNode(u32 num);
    void setAutoDeleteNode(bool f);
    void setAutoDeleteArea(bool f);
    void setSize(u32 num);
    void setData(MtObject* obj, u32 index);
    void setLinkSize(u32 num);
    u32 getNumberOfLink();
    Area* getArea(u32 index);
    u32 getNumberOfArea();
    void setNumberOfArea(u32 num);
    void setAreaSize(u32 num);
    void setAreaData(MtObject* obj, u32 index);
    void setAreaChildSize(u32 size);
    void setAreaLinkSize(u32 size);
    void insert(Node* pNode, Link* addLink);
    void remove(Node* pNode, Link* removeLink);
    u32 getAddID();
    void setAddID(u16 id);
    u32 getData();
    void setData(u32 data);
protected:
    bool mDeleteNode;  // offset: 0x88
    bool mDeleteArea;  // offset: 0x89
    Node* mpNode;  // offset: 0x90
    u32 mNumberOfNode;  // offset: 0x98
    u32 mNumberOfLink;  // offset: 0x9c
    u16 mNumberOfArea;  // offset: 0xa0
    u16 mNumberOfAreaChild;  // offset: 0xa2
    u16 mNumberOfAreaLink;  // offset: 0xa4
    u16 mAddID;  // offset: 0xa6
    u32 mData;  // offset: 0xa8
    Link* mpLink;  // offset: 0xb0
    Area* mpArea;  // offset: 0xb8
    Link* mpAreaChild;  // offset: 0xc0
    Link* mpAreaLink;  // offset: 0xc8
public:
    static MyDTI DTI;
};

class cAITreeBase : public cAITask
{
public:
    class MyDTI;
    class Node;
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
        class ObjectList;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class ObjectList
        {
        public:
            ObjectList();
            static void* operator new(size_t);
            static void* operator new[](size_t s);
            static void operator delete(void*);
            static void operator delete[](void* padr);
        public:
            u32 mParam;  // offset: 0x0
            MtObject* mpObj;  // offset: 0x8
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
        Node();
        virtual ~Node();
        void setNumberOfObject(u32 num);
        u32 getNumberOfObject();
        MtObject* getObject(u32 index);
        MtObject* getObject(u32 index, u32& param);
        void addObject(MtObject* obj, u32 param);
        void addObject(MtObject* obj, u32 index, u32 param);
        void setParam(u32, u32);
        bool remove(u32 index);
        void removeAll();
    protected:
        u32 mNumberOfObject;  // offset: 0x8
        ObjectList* mpObjectList;  // offset: 0x10
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
    cAITreeBase();
    virtual ~cAITreeBase();
    u8 getNest();
    u32 getNumberOfNode();
    u8 getAxisPartition();
    void setDelete(bool f);
    bool isDelete();
protected:
    u8 mNest;  // offset: 0x88
    u8 mAxisPartition;  // offset: 0x89
    Node* mpNode;  // offset: 0x90
    u32 mNumberOfNode;  // offset: 0x98
    bool mDelete;  // offset: 0x9c
public:
    static MyDTI DTI;
};

class cAIQuadTree : public cAITreeBase
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
    cAIQuadTree();
    virtual ~cAIQuadTree();
    void createNode(const MtVector3& pos, const MtVector3& xyz, u32 nest, bool multiple);
    void createNode(const MtAABB& aabb, u32 nest, bool multiple);
    void createNode(const MtAABB& aabb, u32 nest, u32 num, bool multiple);
    void setObject(MtObject* pObj, const MtTriangle& tri, u32 param);
    void setObject(MtObject* pObj, const MtSphere& sphere, u32 param);
    void setObject(MtObject* pObj, const MtAABB& aabb, u32 param);
    void setObject(MtObject* pObj, const MtOBB& obb, u32 param);
    void setObject(MtObject* pObj, const MtVector3& pos, u32 param);
    cAITreeBase::Node* getNode(const MtVector3& pos, u32 nest);
    cAITreeBase::Node* getNode(const MtVector3& pos);
    cAITreeBase::Node* getNode(u32 index);
    void getNode(const MtTriangle& tri, MtArray* a);
    void getNode(const MtAABB& aabb, MtArray* a);
    MtAABB getRegion();
    void createTempRegion();
    void deleteTempRegion();
protected:
    u32 convertMortonToPos2D(const MtVector3& pos);
    MtAABB convertPos2DtoMorton(u32 mot, u32 area);
    u32 bitSeparate2D(u32 bit);
protected:
    bool mMultiple;  // offset: 0x9d
    MtVector3 mPos;  // offset: 0xa0
    MtVector3 mXZ;  // offset: 0xb0
    MtAABB* mpTempRegion;  // offset: 0xc0
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK11cAITreeBase5MyDTI11newInstanceEv at 0x0102cb90-0x0102cbd8, code DWARF attributes to no inlined copy
inline cAITreeBase::cAITreeBase() {
    this->mNest = static_cast<u8>(0);
    this->mNumberOfNode = static_cast<u32>(0);
    this->mAxisPartition = static_cast<u8>(0);
    this->mpNode = static_cast<cAITreeBase::Node*>(nullptr);
    this->mDelete = true;
}
