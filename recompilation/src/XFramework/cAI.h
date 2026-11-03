#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
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
class MtUI;
class MtVector3;
class cAITaskJobPrimList;

// Declarations
class cAIAStar;
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
using s32 = int;
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

class cAIAStar : public cAIGraph
{
public:
    enum SEARCH_STATE
    {
        STATE_WAIT = 1,
        STATE_SUCCSES = 2,
        STATE_AREA_SUCCSES = 4,
        STATE_CONTINUE = 8,
        STATE_FAILED = 16,
        STATE_FAILED_HEURISTIC = 48,
        STATE_FAILED_SAME_NODE = 80,
        STATE_FAILED_NONE_NODE = 144,
        STATE_FAILED_MEMORY = 272,
        STATE_AREA_FAILED = 528,
    };
    enum AStar_Status
    {
        STATE_CLEAR = 0,
        STATE_OPEN = 1,
        STATE_CLOSE = 2,
    };
public:
    class MyDTI;
    class AStarResult;
    struct AStarNode;
    class OpenList;
public:
    using NODE_COST_FUNC = void(MtObject::*)(MtObject*, f32&);
    using LINK_FUNC = bool(MtObject::*)(MtObject*, MtObject*);
    using HEURISTIC_COST_FUNC = f32(MtObject::*)(MtObject*, MtObject*);
    using ASTAR_FUNC = bool(MtObject::*)(MtObject*);
    using SIZE_FUNC = bool(MtObject::*)(MtObject*, u32);
    using AREA_FUNC = bool(MtObject::*)(MtObject*, MtObject*, bool&, bool&, MtObject*);
    using NODE_STATUS_FUNC = void(MtObject::*)(u8*, MtObject*, u32);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class AStarResult : public MtObject
    {
    public:
        AStarResult();
        virtual ~AStarResult();
    public:
        u8 mLinkIndex;  // offset: 0x8
        cAIGraph::Node* mpNode;  // offset: 0x10
        u32* mpData;  // offset: 0x18
    };
public:
    struct AStarNode
    {
    public:
        cAIAStar::AStarNode* mpNextNode;  // offset: 0x0
        u32* mpData;  // offset: 0x8
        cAIGraph::Node* mpAStar;  // offset: 0x10
        f32 mTotalCost;  // offset: 0x18
        f32 mHeuristic;  // offset: 0x1c
        u32 mUTotal;  // offset: 0x20
    };
public:
    class OpenList : public MtObject
    {
    public:
        OpenList();
        virtual ~OpenList();
        cAIAStar::AStarNode* at(u32 index);
        void add(cAIAStar::AStarNode* pobj);
        void addSort(cAIAStar::AStarNode* pobj);
        void replace(u32, cAIAStar::AStarNode*);
        void erase(u32 index);
        u32 length();
        bool extendBuffer(s32 siz);
        void clear();
    protected:
        cAIAStar::AStarNode* * mpArray;  // offset: 0x8
        u32 mBufsiz;  // offset: 0x10
        u32 mLength;  // offset: 0x14
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
    cAIAStar();
    virtual ~cAIAStar();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createJobList(cAITaskJobPrimList& list);  // vtable slot 6
    u32 getNumberOfResult();
    MtObject* getResult(u32 index, bool f);
    AStarResult* getResult_Address();
    MtObject* getResult_A(u32 index, u32& param);
    void setEvaluateFunc(NODE_COST_FUNC func, MtObject* owner);
    void setLinkFunc(LINK_FUNC func, MtObject* owner);
    void setHeuristicFunc(HEURISTIC_COST_FUNC func, MtObject* owner);
    void setAreaFunc(AREA_FUNC func, MtObject* owner);
    void setNodeStatusFunc(NODE_STATUS_FUNC func, MtObject* owner);
    void setFinishConditionFunc(ASTAR_FUNC, MtObject*);
    void setSizeFunc(SIZE_FUNC func, MtObject* owner);
    f32 getHeuristicSecurity();
    void setHeuristicSecurity(f32 security);
    f32 getCost();
    bool areaInitialize(cAIGraph::Node* startNode, cAIGraph::Node* endNode, cAIGraph::Area* root);
    bool nodeInitialize(cAIGraph::Node* startNode, cAIGraph::Node* endNode, u32 state, bool callback);
    u32 AStar(cAIGraph::Node* startNode, cAIGraph::Node* endNode, f32* cost);
    u32 search();
    u32 search_callback();
    void searchJob();
protected:
    bool AreaDecision(cAIGraph::Node* startNode, cAIGraph::Node* endNode);
    cAIGraph::Node* searchNode(MtObject* node);
protected:
    f32 mSecurityCost;  // offset: 0xd0
    AStarResult* mpResult;  // offset: 0xd8
    u32 mNumberOfAStar;  // offset: 0xe0
    MtObject* mpCOwner;  // offset: 0xe8
    NODE_COST_FUNC mpCostFunction;  // offset: 0xf0
    MtObject* mpLOwner;  // offset: 0x100
    LINK_FUNC mpLinkFunction;  // offset: 0x108
    MtObject* mpHOwner;  // offset: 0x118
    HEURISTIC_COST_FUNC mpHeuristicFunction;  // offset: 0x120
    MtObject* mpFOwner;  // offset: 0x130
    ASTAR_FUNC mpFinishFunction;  // offset: 0x138
    SIZE_FUNC mpSizeFunction;  // offset: 0x148
    MtObject* mpLSOwner;  // offset: 0x158
    cAIGraph::Area* mpRoot;  // offset: 0x160
    MtObject* mpAOwner;  // offset: 0x168
    AREA_FUNC mpAreaFunction;  // offset: 0x170
    MtObject* mpSOwner;  // offset: 0x180
    NODE_STATUS_FUNC mpStatusFunction;  // offset: 0x188
    cAIGraph::Node* mpENode;  // offset: 0x198
    AStarNode* mpHashTable;  // offset: 0x1a0
    u8* mpStateFlag;  // offset: 0x1a8
    u16 mIndex;  // offset: 0x1b0
    f32 mCost;  // offset: 0x1b4
    OpenList mOpenList;  // offset: 0x1b8
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

inline void* cAIAStar::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAIGraph::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAIGraph::Node::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAIGraph::Area::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAIQuadTree::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAITreeBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cAITreeBase::cAITreeBase() {
    this->mNest = 0;
    this->mNumberOfNode = 0;
    this->mAxisPartition = 0;
    this->mpNode = nullptr;
    this->mDelete = true;
}

inline void* cAITreeBase::Node::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
