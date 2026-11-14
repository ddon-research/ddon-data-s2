#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
class MtPropertyList;

// Declarations
template <typename _NODE_> class cNodeParam;
template <typename _NODE_> class cTree;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

template <typename _NODE_>
class cNodeParam : public MtObject
{
public:
    enum MODE
    {
        MODE_NONE = 0,
        MODE_NODE_ALLOCATOR = 1,
        MODE_CLASS_ALLOCATOR = 2,
    };
public:
    cNodeParam();
    cNodeParam(_NODE_* pData, const MtAABB& aabb, u8 mode);
    virtual ~cNodeParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    f32 getX() const;
    f32 getY() const;
    f32 getZ() const;
    void Surround(cNodeParam<_NODE_>* pChild);
    static void setAllocator(MtAllocator* pa);
    static void* operator new(size_t s);
    static void operator delete(void* padr);
public:
    _NODE_* mpData;  // offset: 0x8
    MtAABB mAABB;  // offset: 0x10
private:
    u8 mMode;  // offset: 0x30
    static MtAllocator* mpAllocator;
};

template <typename _NODE_>
class cTree
{
public:
    enum AXIS
    {
        AXIS_X = 0,
        AXIS_Z = 1,
        AXIS_Y = 2,
        AXIS_NUM = 3,
    };
public:
    class cNode;
public:
    class cNode
    {
    public:
        class getAxisZ;
        class getAxisY;
        class getAxisX;
    public:
        class getAxisZ
        {
        public:
            f32 operator()(const cNodeParam<_NODE_>* node);
        };
    public:
        class getAxisY
        {
        public:
            f32 operator()(const cNodeParam<_NODE_>* node);
        };
    public:
        class getAxisX
        {
        public:
            f32 operator()(const cNodeParam<_NODE_>* node);
        };
    public:
        cNode(cNodeParam<_NODE_>* * param, s32 param_num, s32 axis, s32 diable_axis);
        virtual ~cNode();
        cNodeParam<_NODE_>* getNodeParam() const;
        static void* operator new(size_t s);
        static void operator delete(void* padr);
    private:
        cNodeParam<_NODE_>* mpParam;  // offset: 0x8
        cTree::cNode* mpRight;  // offset: 0x10
        cTree::cNode* mpLeft;  // offset: 0x18
        static MtAllocator* mpAllocator;
    };
public:
    cTree();
    virtual ~cTree();
    void addParam(cNodeParam<_NODE_>* pobj);
    void deleteAll();
    virtual void build(s32 diable_axis);  // vtable slot 2
    bool isReady();
    void getAABB(MtAABB& aabb);
    static void setAllocator(MtAllocator* pa);
private:
    u32 mParamNum;  // offset: 0x8
    cNode* mpRoot;  // offset: 0x10
    MtArray mParams;  // offset: 0x18
};

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"

template <typename _NODE_>
cNodeParam<_NODE_>::~cNodeParam() {
    if (this->mMode == 2) {
        (::cNodeParam<_NODE_>::mpAllocator)->memFree(static_cast<void*>(this->mpData));
        this->mpData = nullptr;
    } else {
        if (this->mMode == 1) {
            if (this->mpData != nullptr) {
                delete this->mpData;
                this->mpData = nullptr;
            }
        }
    }
}

#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"

// Static template data members.
template <typename _NODE_>
MtAllocator* cNodeParam<_NODE_>::mpAllocator = nullptr;

template <typename _NODE_>
MtAllocator* cTree<_NODE_>::cNode::mpAllocator = nullptr;

template <typename _NODE_>
inline cTree<_NODE_>::cTree() : mpRoot(nullptr) {
}

template <typename _NODE_>
inline cTree<_NODE_>::~cTree() {
    this->deleteAll();
}

template <typename _NODE_>
inline void cTree<_NODE_>::addParam(cNodeParam<_NODE_>* pobj) {
    this->mParams.add(pobj);
}

template <typename _NODE_>
inline void cTree<_NODE_>::deleteAll() {
    if (this->mpRoot != nullptr) {
        delete this->mpRoot;
        this->mpRoot = nullptr;
    }
    this->mParams.deleteAll(true);
}

template <typename _NODE_>
inline void cTree<_NODE_>::build(s32 diable_axis) {
    if (this->mpRoot != nullptr) {
        delete this->mpRoot;
        this->mpRoot = nullptr;
    }
    if (this->mParams.length() != 0) {
        this->mpRoot = new cNode(reinterpret_cast<cNodeParam<_NODE_>**>(this->mParams.getBuffer()), static_cast<s32>(this->mParams.length()), 0, diable_axis);
        this->mParamNum = this->mParams.length();
    } else {
        this->mParamNum = 0;
    }
    this->mParams.clear(true);
}

template <typename _NODE_>
inline cTree<_NODE_>::cNode::~cNode() {
    if (this->mpParam != nullptr) {
        delete this->mpParam;
        this->mpParam = nullptr;
    }
    if (this->mpRight != nullptr) {
        delete this->mpRight;
        this->mpRight = nullptr;
    }
    if (this->mpLeft != nullptr) {
        delete this->mpLeft;
        this->mpLeft = nullptr;
    }
}

template <typename _NODE_>
inline void* cTree<_NODE_>::cNode::operator new(size_t s) {
    if (::cTree<_NODE_>::cNode::mpAllocator == nullptr) {
        ::cTree<_NODE_>::cNode::mpAllocator = MtMemory::getAllocator(MtMemoryAllocator::DEFAULT);
    }
    return ::cTree<_NODE_>::cNode::mpAllocator->memAlloc(s, 16);
}

template <typename _NODE_>
inline void cTree<_NODE_>::cNode::operator delete(void* padr) {
    ::cTree<_NODE_>::cNode::mpAllocator->memFree(padr);
}

template <typename _NODE_>
inline cNodeParam<_NODE_>::cNodeParam(_NODE_* pData, const MtAABB& aabb, u8 mode)
    : mpData(pData), mAABB(aabb), mMode(mode) {
}

template <typename _NODE_>
inline void* cNodeParam<_NODE_>::operator new(size_t s) {
    if (::cNodeParam<_NODE_>::mpAllocator == nullptr) {
        ::cNodeParam<_NODE_>::mpAllocator = MtMemory::getAllocator(MtMemoryAllocator::DEFAULT);
    }
    return ::cNodeParam<_NODE_>::mpAllocator->memAlloc(s, 16);
}

template <typename _NODE_>
inline void cNodeParam<_NODE_>::operator delete(void* padr) {
    ::cNodeParam<_NODE_>::mpAllocator->memFree(padr);
}

template <typename _NODE_>
cTree<_NODE_>::cNode::cNode(cNodeParam<_NODE_>** param, s32 param_num, s32 axis, s32 diable_axis)
    : mpParam(nullptr), mpRight(nullptr), mpLeft(nullptr) {
    if (param_num == 1) {
        this->mpParam = param[0];
    } else if (param_num > 1) {
        s32 t1 = param_num / 2;
        s32 t2 = (axis + 1) % AXIS_NUM;
        this->mpLeft = new cNode(param, t1, t2, diable_axis);
        this->mpRight = new cNode(param + t1, param_num - t1, t2, diable_axis);
    }
}
