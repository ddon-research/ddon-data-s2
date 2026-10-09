#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cAI.h"
#include "cAIService.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
class MtCapsule;
class MtDTI;
class MtGeometry;
class MtMatrix;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class cAIGraph;
class cAIQuadTree;

// Declarations
class cAISvPathFinding;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cAISvPathFinding : public cAIService
{
public:
    enum BOOLEAN
    {
        AND = 0,
        OR = 1,
        XOR = 2,
        NOT = 3,
    };
public:
    class MyDTI;
    class Node;
    struct Link;
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
        void removeData();
    public:
        u8 mNumberOfAttr;  // offset: 0x8
        u8 mNumberOfLink;  // offset: 0x9
        u16 mNodeIndex;  // offset: 0xa
        u32* mpNodeAttr;  // offset: 0x10
        cAISvPathFinding::Link* mpLink;  // offset: 0x18
        MtGeometry* mpGeometry;  // offset: 0x20
        bool mConnect;  // offset: 0x28
        f32 mLength;  // offset: 0x2c
        u32 mNumberOfExpData;  // offset: 0x30
        u32* mpExpData;  // offset: 0x38
        MtVector3 mPos;  // offset: 0x40
        MtVector3 mDir;  // offset: 0x50
        static MyDTI DTI;
    };
public:
    struct Link
    {
    public:
        void init();
    public:
        s32 mNodeIndex;  // offset: 0x0
        f32 mCost;  // offset: 0x4
        s32 mLowNode;  // offset: 0x8
        u32* mpAttr;  // offset: 0x10
        u32 mNumberOfAttribute;  // offset: 0x18
        f32 mSize;  // offset: 0x1c
        f32 mHeight;  // offset: 0x20
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
    cAISvPathFinding();
    virtual ~cAISvPathFinding();
    virtual void reset();  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute);  // vtable slot 9
    u32 getNumberOfNode();
    cAIGraph::Node* getNodeToIndex(u32 index);
    u32 getNumberOfLink();
    MtVector3 getNodePos(u32 index, bool useWorldOffset);
    MtVector3 getNodePos(cAIGraph::Node* pNode, bool useWorldOffset);
    cAIGraph::Node* getNode(bool useWorldOffset, const MtVector3& pos, bool f);
    cAIGraph::Node* getNode(bool, const MtVector3&, u32, u32, u32, u32, bool);
    void getNodeToArray(bool useWorldOffset, MtArray& ar, MtGeometry* pGeom, bool f);
    void getNodeToArray(bool useWorldOffset, MtArray& ar, MtGeometry* pGeom, u32 attr, u32 index, bool f);
    bool isMovement();
    void setMovement(bool f);
    void setMatrix(const MtMatrix& mat);
    void setMatrix(const MtMatrix& mat, u32 index);
    void setMatrixIndex(u32 index);
    u32 getMatrixIndex();
    void addMatrix(const MtMatrix& mat);
    void removeMatrix(u32 index);
    void removeMatrixAll();
    u32 getNumberOfMatrix();
    MtMatrix getMatrix();
    MtMatrix getMatrix(u32 index);
    u32 getNumberOfArea();
    cAIGraph::Area* getAreaToIndex(u32 index);
    cAIGraph::Area* getRootArea();
    u32 getNodeAttribute(cAIGraph::Node*, u32);
    MtAABB getRegion();
    void setLink(cAIGraph::Node* pNode, bool f);
    void setLink(bool useWorldOffset, const MtSphere& sphere, bool f, const MtMatrix& mat);
    void setLink(bool useWorldOffset, const MtCapsule& capsule, bool f, const MtMatrix& mat);
    void setLink(bool useWorldOffset, const MtAABB& aabb, bool f, const MtMatrix& mat);
    void setLink(bool useWorldOffset, const MtOBB& obb, bool f, const MtMatrix& mat);
    void setAttribute(cAIGraph::Node* pNode, u32 index, u32 attr, bool f);
    void setAttribute(cAIGraph::Node* pNode, u32 index, u32 attr, u32 battr, u32 boolean, bool f);
    void setAttribute(bool useWorldOffset, const MtSphere& sphere, u32 index, u32 attr, bool f, const MtMatrix& mat);
    void setAttribute(bool useWorldOffset, const MtCapsule& capsule, u32 index, u32 attr, bool f, const MtMatrix& mat);
    void setAttribute(bool useWorldOffset, const MtAABB& aabb, u32 index, u32 attr, bool f, const MtMatrix& mat);
    void setAttribute(bool useWorldOffset, const MtOBB& obb, u32 index, u32 attr, bool f, const MtMatrix& mat);
    void setAttribute(bool useWorldOffset, const MtSphere& sphere, u32 index, u32 attr, u32 battr, u32 boolean, bool f, const MtMatrix& mat);
    void setAttribute(bool useWorldOffset, const MtCapsule& capsule, u32 index, u32 attr, u32 battr, u32 boolean, bool f, const MtMatrix& mat);
    void setAttribute(bool useWorldOffset, const MtAABB& aabb, u32 index, u32 attr, u32 battr, u32 boolean, bool f, const MtMatrix& mat);
    void setAttribute(bool useWorldOffset, const MtOBB& obb, u32 index, u32 attr, u32 battr, u32 boolean, bool f, const MtMatrix& mat);
    void setExclusionNode(u32, u32);
    u32 getAddID();
    void setAddID(u32 add);
    u32 getData();
    void setData(u32 data);
    void setOverLength(f32);
    void setUnderLength(f32);
    bool isReferenceCounter();
    void setReferenceCounter(bool);
    bool isEnableWorldOffset();
    void setEnableWorldOffset(bool);
    MtVector3 getWorldOffset();
    void resetWorldOffset();
    void setLinkEx(const MtOBB& obb, bool f);
    void setAttributeEx(const MtOBB& obb, u32 index, u32 attr, bool f);
    virtual bool GraphFunc(MtObject* adr1, u32& num, u32& index, f32& cost, u32& param);  // vtable slot 10
    virtual bool AreaFunc(MtObject* adr1, u32& num, u32& index, f32& cost, u32& param, bool f);  // vtable slot 11
    void insertOuterLink(cAIGraph::Node* pNode, cAIGraph::Link* pLink);
    void removeOuterLink(cAIGraph::Node* pNode, cAIGraph::Link* pLink);
protected:
    virtual cAIGraph::Node* getNodeCore(bool useWorldOffset, const MtVector3& pos, bool f, f32 low, f32 high, u32 attr, u32 index, u32 boolean, u32 exception);  // vtable slot 12
    // Address: 0x01b6bc60 - 0x01b6bc61 (1 bytes)
    virtual void getNodeToAABB(MtArray& a, const MtAABB& aabb, bool useWorldOffset) {}  // vtable slot 13
    virtual bool intersectNode(cAIGraph::Node* pNode, const MtSphere& s, bool useWorldOffset);  // vtable slot 14
    virtual bool intersectNode(cAIGraph::Node* pNode, const MtCapsule& c, bool useWorldOffset);  // vtable slot 15
    virtual bool intersectNode(cAIGraph::Node* pNode, const MtAABB& a, bool useWorldOffset);  // vtable slot 16
    virtual bool intersectNode(cAIGraph::Node* pNode, const MtOBB& o, bool useWorldOffset);  // vtable slot 17
    void setHashNode(u32 size);
    void setHashLink(u32 size);
    void setHashAttribute(u32 size);
    void setHashLinkAttribute(u32 size);
    void setHashExpData(u32 size);
protected:
    Node* mpNode;  // offset: 0x30
    Link* mpLink;  // offset: 0x38
    u32* mpAttribute;  // offset: 0x40
    u32* mpLinkAttribute;  // offset: 0x48
    cAIGraph* mpGraph;  // offset: 0x50
    cAIQuadTree* mpTree;  // offset: 0x58
    u32* mpExpData;  // offset: 0x60
    bool mMovement;  // offset: 0x68
    bool mEnableReferenceCounter;  // offset: 0x69
    bool mEnableWorldOffset;  // offset: 0x6a
    u16 mMatrixIndex;  // offset: 0x6c
    u16 mNumberOfMatrix;  // offset: 0x6e
    MtMatrix* mpMatrix;  // offset: 0x70
    u32 mExclusionIndex;  // offset: 0x78
    u32 mExclusionAttr;  // offset: 0x7c
    f32 mOver;  // offset: 0x80
    f32 mUnder;  // offset: 0x84
    MtVector3 mWorldOffset;  // offset: 0x90
public:
    static MyDTI DTI;
};
