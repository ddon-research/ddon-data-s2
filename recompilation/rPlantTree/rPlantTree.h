#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;
class MtVector3;

// Declarations
class rPlantTree;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rPlantTree : public cResource
{
public:
    class MyDTI;
    class Tree;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Tree : public MtObject
    {
    public:
        class MyDTI;
        class Point;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Point : public MtObject
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
            Point();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        public:
            MtVector3 mPosition;  // offset: 0x10
            MtVector3 mAngle;  // offset: 0x20
            MtVector3 mScale;  // offset: 0x30
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
        Tree();
        virtual ~Tree();
        s32 getOmId();
        virtual Point* getPointList(u32 index);  // vtable slot 6
        virtual u32 getPointListNum();  // vtable slot 7
    public:
        u32 mOmId;  // offset: 0x8
        Point* mpPointList;  // offset: 0x10
        u32 mPointListNum;  // offset: 0x18
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
    rPlantTree();
    virtual ~rPlantTree();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getTreeNum();  // vtable slot 16
    virtual Tree* getTree(u32 idx);  // vtable slot 17
protected:
    u32 getMagicHeader();
    u32 getDataVersion();
    void destruct();
public:
    Tree* mpArray;  // offset: 0x70
    u32 mArrayNum;  // offset: 0x78
    static MyDTI DTI;
    static const u8 DATA_VERSION = 2;
};

// Inline, no code of its own: checked where it is inlined.
inline rPlantTree::Tree::Tree() {
    this->mOmId = static_cast<u32>(0);
    this->mpPointList = static_cast<rPlantTree::Tree::Point*>(nullptr);
    this->mPointListNum = static_cast<u32>(0);
}
