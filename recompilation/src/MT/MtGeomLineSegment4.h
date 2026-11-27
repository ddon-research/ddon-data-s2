#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtGeometry3D.h"
#include "MtPrimitive3D.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtLineSegment;
class MtLineSegment4;
class MtObject;
class MtPropertyList;
class MtSphere;

// Declarations
class MtGeomLineSegment4;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class MtGeomLineSegment4 : public MtGeometry
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
    MtGeomLineSegment4();
    MtGeomLineSegment4(const MtLineSegment4& ls4);
    MtGeomLineSegment4(const MtLineSegment&, const MtLineSegment&, const MtLineSegment&, const MtLineSegment&);
    virtual ~MtGeomLineSegment4() {}
    virtual void load(MtDataReader& fin);  // vtable slot 6
    virtual void save(MtDataWriter& fout);  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void getBoundingAABB(MtAABB& aabb) const;  // vtable slot 8
    virtual void getBoundingSphere(MtSphere& sphere) const;  // vtable slot 9
    virtual void copy(const MtGeometry& input);  // vtable slot 12
public:
    MtLineSegment4 mLineSegment4;  // offset: 0x10
    static MyDTI DTI;
};

inline void* MtGeomLineSegment4::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "MtAllocator.h"
#include "MtMemoryAllocator.h"

inline void MtGeomLineSegment4::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtGeomLineSegment4::DTI)->memFree(p_addr);
}
