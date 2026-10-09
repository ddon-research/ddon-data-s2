#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cResource.h"
#include "sOccluderExt.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rOccluderEx;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rOccluderEx : public cResource
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
    rOccluderEx();
    virtual ~rOccluderEx();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    sOccluderEx::Area* getArea(u32 index);
    void setArea(sOccluderEx::Area* pArea, u32 index);
    u32 getAreaNum();
    sOccluderEx::Shape* getAreaShape(u32 areaIdx, u32 shapeIdx);
    void setAreaShape(sOccluderEx::Shape* pShape, u32 areaIdx, u32 shapeIdx);
    u32 getAreaShapeNum(u32 areaIdx);
public:
    MtArray mAreaList;  // offset: 0x70
    static MyDTI DTI;
    static const u32 DATA_VERSION = 1;
};
