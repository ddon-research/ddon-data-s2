#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtGeometry3D.h"
#include "MtPrimitive3D.h"

// Forward declarations
class MtAllocator;
struct MtContact;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPlane;
class MtPlaneXZ;
class MtPropertyList;
class MtVector3;
class MtVector4;

// Declarations
class MtGeomPlane;
class MtGeomPlaneXZ;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class MtGeomPlane : public MtGeometry
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
    MtGeomPlane();
    MtGeomPlane(const MtPlane&);
    MtGeomPlane(const MtVector3&, const MtVector3&);
    virtual ~MtGeomPlane() {}
    virtual void load(MtDataReader& fin);  // vtable slot 6
    virtual void save(MtDataWriter& fout);  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const MtGeometry& input);  // vtable slot 12
    static f32 distance(const MtPlane&, const MtVector3&);
    static void distance3(const MtPlane&, const MtVector3&, const MtVector3&, const MtVector3&, MtVector3&);
    static void distance4(const MtPlane&, const MtVector3&, const MtVector3&, const MtVector3&, const MtVector3&, MtVector4&);
    static void distance3(const MtVector3*, const MtVector3&, const MtVector3&, MtVector3&);
    static void distance4(const MtVector3*, const MtVector4&, const MtVector3&, MtVector4&);
    static bool closest(const MtPlane&, const MtVector3&, MtContact*);
public:
    MtPlane mPlane;  // offset: 0x10
    static MyDTI DTI;
};

class MtGeomPlaneXZ : public MtGeometry
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
    MtGeomPlaneXZ();
    MtGeomPlaneXZ(const MtPlaneXZ&);
    MtGeomPlaneXZ(const MtVector3&);
    MtGeomPlaneXZ(f32);
    virtual ~MtGeomPlaneXZ() {}
    virtual void load(MtDataReader& fin);  // vtable slot 6
    virtual void save(MtDataWriter& fout);  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const MtGeometry& input);  // vtable slot 12
public:
    MtPlaneXZ mPlaneXZ;  // offset: 0xc
    static MyDTI DTI;
};

inline void* MtGeomPlane::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* MtGeomPlaneXZ::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
