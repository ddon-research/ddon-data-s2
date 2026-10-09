#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uFilter.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector4;
class cDraw;
namespace nEffect { class FilterParam; }

// Declarations
class uMultiFilter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uMultiFilter : public uFilter
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
    uMultiFilter();
    virtual ~uMultiFilter();
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getDrawNum() const;
    void setDrawNum(u32 DrawNum);
    u32 getDrawMax() const;
    void setDrawMax(u32 DrawMax);
    u32 getEntry() const;
    void clearEntry();
protected:
    virtual u32 allocFilterParam(u32 DrawNum);  // vtable slot 24
    virtual void freeFilterParam();  // vtable slot 25
    virtual nEffect::FilterParam* getFilterParam(u32) = 0;  // vtable slot 26
    virtual f32 calcTransparency(cDraw*, nEffect::FilterParam*) = 0;  // vtable slot 27
    virtual s32 getFilterOrder(const MtVector4&, u32) = 0;  // vtable slot 28
    virtual void drawFilter(cDraw*, u32, f32) = 0;  // vtable slot 29
protected:
    u32 mDrawNum;  // offset: 0x54
    u32 mDrawMax;  // offset: 0x58
    u32 mEntry;  // offset: 0x5c
    nEffect::FilterParam* mpFilterParam;  // offset: 0x60
    bool mClearFlag;  // offset: 0x68
public:
    static MyDTI DTI;
};
