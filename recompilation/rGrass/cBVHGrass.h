#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive3D.h"

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
#include "../shared/MtAllocator.h"

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else cBVHGrass.cpp, instantiates it for the body oracle.
template <typename _NODE_>
cNodeParam<_NODE_>::~cNodeParam() {
    if (this->mMode == static_cast<u8>(2)) {
        (::cNodeParam<_NODE_>::mpAllocator)->memFree(static_cast<void*>(this->mpData));
        this->mpData = static_cast<_NODE_*>(nullptr);
    } else {
        if (this->mMode == static_cast<u8>(1)) {
            if (this->mpData != static_cast<_NODE_*>(nullptr)) {
                delete this->mpData;
                this->mpData = static_cast<_NODE_*>(nullptr);
            }
        }
    }
}
