#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtVector3;
class uCoord;

// Declarations
class cPawnEnableArea;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cPawnEnableArea : public MtObject
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
    cPawnEnableArea();
    cPawnEnableArea(const cPawnEnableArea&);
    bool isEnableArea(uCoord& owner, const uCoord& target) const;
    bool isEnableArea(uCoord& owner, const MtVector3& targetOfsPos, f32 angle) const;
    bool isEnableArea(const MtVector3& ownerPos, const MtVector3& targetOfsPos, f32 angle) const;
    bool isEnableAreaXZ(const MtVector3& ownerPos, const MtVector3& targetOfsPos, f32 angle) const;
    bool isEnableAreaY(const MtVector3& ownerPos, const f32 targetY) const;
    void load(MtDataReader& r);
    void save(MtDataWriter& w);
    void copy(const cPawnEnableArea& src);
    void resetArea();
public:
    f32 mMinXZ;  // offset: 0x8
    f32 mMaxXZ;  // offset: 0xc
    f32 mMinY;  // offset: 0x10
    f32 mMaxY;  // offset: 0x14
    f32 mRadius;  // offset: 0x18
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cPawnEnableArea::cPawnEnableArea() {
    this->mMinXZ = 0.0f;
    this->mMaxXZ = 300.0f;
    this->mMinY = -300.0f;
    this->mMaxY = 300.0f;
    this->mRadius = 0.0f;
}
