#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/sTool.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCapsule;
class MtColor;
class MtCone;
class MtCylinder;
class MtDTI;
class MtMatrix;
class MtOBB;
class MtObject;
class MtPoint;
class MtRect;
class MtSize;
class MtSphere;
class MtVector3;
class cDraw;

// Declarations
class sToolExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sToolExt : public sTool
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
    sToolExt(u32 buf_size);
    void drawLineT(const MtVector3&, const MtVector3&, MtColor, bool, u32, s32, bool);
    void drawArrowT(const MtVector3&, const MtVector3&, MtColor, bool, u32, s32);
    void drawArrowAngleT(const MtVector3&, const MtVector3&, const f32&, MtColor, bool, u32, s32);
    void drawArrowAngleT(const MtVector3&, const f32&, const f32&, MtColor, bool, u32, s32);
    void drawSphereT(const MtVector3&, f32, MtColor, bool, u32, u32, s32);
    void drawSphereT(const MtSphere&, MtColor, bool, u32, u32, s32);
    void drawCapsuleT(const MtCapsule&, MtColor, bool, u32, u32, s32);
    void drawCapsuleT(const MtCapsule&, const MtVector3&, MtColor, bool, u32, u32, s32);
    void drawConeT(const MtVector3&, const MtVector3&, const f32, const MtColor, bool, const u32, u32, s32);
    void drawConeT(const MtCone&, const MtColor, bool, const u32, u32, s32);
    void drawMatrixT(const MtMatrix&, f32, bool, bool, u32);
    void drawAABBT(const MtAABB&, const MtColor, u32);
    void drawOBBT(const MtOBB&, const MtColor, u32);
    void drawFanT(const MtMatrix&, f32, f32, f32, MtColor, bool, u32, u32, s32);
    void printfT(u32, s32, const MtPoint&, const MtSize&, MtColor, MT_CTSTR, ...);
    void printfT(u32, s32, const MtVector3&, const MtSize&, MtColor, MT_CTSTR, ...);
    void printfExT(u32, s32, const MtPoint&, const MtSize&, MtColor, MtColor, MT_CTSTR, ...);
    void printfRect(u32, s32, const MtPoint&, const MtSize&, const MtRect&, MtColor, MT_CTSTR, ...);
    void printf(const MtPoint&, MT_CTSTR, ...);
    void printf(const MtPoint&, const MtColor&, MT_CTSTR, ...);
    void printf(const MtPoint&, const MtSize&, const MtColor&, MT_CTSTR, ...);
    void printf(const MtPoint&, const MtSize&, MT_CTSTR, ...);
    void printf(const MtVector3&, MT_CTSTR, ...);
    void printf(const MtVector3&, const MtColor&, MT_CTSTR, ...);
    void printf(const MtVector3&, const MtSize&, const MtColor&, MT_CTSTR, ...);
    void printf(const MtVector3&, const MtSize&, MT_CTSTR, ...);
    void drawCylinderEx(const MtCylinder&, MtColor, u32, u32);
    void drawSphereEx(const MtVector3&, f32, MtColor, u32, u32);
    void drawArrow(const MtVector3&, const MtVector3&, MtColor, f32, f32, u32);
    void drawArrow(const MtMatrix&, f32, f32, u32);
    void fillLine(const MtVector3&, const MtVector3&, f32, MtColor, u32);
private:
    void initDbgString();
    void clearDbgString();
    void addDbgString(const MtPoint&, const MtSize&, const MtColor&, MT_CTSTR);
    void addDbgString(const MtVector3&, const MtSize&, const MtColor&, MT_CTSTR);
    void drawDbgString(cDraw*);
public:
    static MyDTI DTI;
};

inline void* sToolExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* sToolExt::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sToolExt::DTI);
}
