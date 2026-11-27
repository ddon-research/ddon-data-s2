#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cSystem.h"

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
class cPrim;
namespace nDraw { class Texture; }

// Declarations
class sToolBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sToolBase : public cSystem
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
    sToolBase(u32 buf_size);
    virtual ~sToolBase();
    static sToolBase* getInstance();
    virtual void move() {}  // vtable slot 7
    virtual void setup() {}  // vtable slot 10
    virtual void reset() {}  // vtable slot 6
    virtual void drawSysMenu(cDraw*) {}  // vtable slot 11
    bool isSysMenu();
    void setSysMenu(u32, s32, s32, s32);
    void setSysMenuPadState(u32, u32);
    u32 getSysMenuPadNo();
    void setSysMenuDisp(bool);
    bool isSysMenuDisp();
    void drawSysString(cPrim*, s32, s32, MT_CTSTR, MtColor, MtSize);
    bool isVisible();
    void setVisible(bool v);
    bool isShowFps();
    void setShowFps(bool);
    bool isShowBuildVersion();
    void setShowBuildVersion(bool);
    void printf(const MtPoint&, MT_CTSTR, ...);
    void printf(const MtPoint&, MtColor, MT_CTSTR, ...);
    void printf(const MtPoint&, const MtSize&, MtColor, MT_CTSTR, ...);
    void printfEx(const MtPoint&, MT_CTSTR, ...);
    void printfEx(const MtPoint&, MtColor, MtColor, MT_CTSTR, ...);
    void printfEx(const MtPoint&, const MtSize&, MtColor, MtColor, MT_CTSTR, ...);
    void printf(u32, const MtVector3&, MT_CTSTR, ...);
    void printf(u32, const MtVector3&, MtColor, MT_CTSTR, ...);
    void printf(u32, const MtVector3&, const MtSize&, MtColor, MT_CTSTR, ...);
    void drawLine(const MtPoint&, const MtPoint&, MtColor);
    void drawRect(const MtRect&, MtColor);
    void fillRect(const MtRect&, MtColor);
    void drawTriangle(const MtPoint&, const MtPoint&, const MtPoint&, MtColor);
    void fillTriangle(const MtPoint&, const MtPoint&, const MtPoint&, MtColor);
    void drawCircle(const MtPoint&, u32, MtColor);
    void printf(const MtVector3&, MT_CTSTR, ...);
    void printf(const MtVector3&, MtColor, MT_CTSTR, ...);
    void printf(const MtVector3&, const MtSize&, MtColor, MT_CTSTR, ...);
    void drawLine(const MtVector3& v1, const MtVector3& v2, MtColor c, u32 attr);
    void drawMatrix(const MtMatrix&, f32, u32, bool);
    void drawPosition(const MtVector3& m, f32 scale, u32 attr, bool text);
    void drawSphere(const MtVector3& v, f32 rad, MtColor c, u32 attr, u32 div);
    void drawSphere(const MtSphere&, MtColor, u32, u32);
    void drawAABB(const MtAABB& aabb, MtColor c, u32 attr);
    void drawOBB(const MtOBB& obb, MtColor c, u32 attr);
    void drawCylinder(MtCylinder&, MtColor, u32, u32);
    void drawCapsule(const MtCapsule&, MtColor, u32, u32);
    void drawCone(const MtVector3& top, const MtVector3& bottom, const f32 angle, const MtColor c, u32 attr, const u32 div);
    void fillCone(const MtVector3&, const MtVector3&, const f32, const MtColor, u32, const u32);
    void drawCone(const MtCone&, const MtColor, u32, const u32);
    void fillCone(const MtCone&, const MtColor, u32, const u32);
    void drawTriangle(const MtVector3&, const MtVector3&, const MtVector3&, MtColor, u32);
    void fillTriangle(const MtVector3&, const MtVector3&, const MtVector3&, MtColor, u32);
    void fillFan(const MtMatrix&, f32, s16, s16, MtColor, u32, u32);
    void drawNormal(const MtVector3&, const MtVector3&, const f32, const MtColor, u32, const u32);
    void drawImage(const MtRect&, MtColor, nDraw::Texture*);
    void drawImage(const MtRect&, const MtRect&, MtColor, nDraw::Texture*);
    void drawImage(MtPoint, MtPoint, MtPoint, MtPoint, const MtRect&, MtColor, nDraw::Texture*);
public:
    static MyDTI DTI;
protected:
    static sToolBase* mpInstance;
};

inline void* sToolBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sToolBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sToolBase::DTI)->memFree(p_addr);
}
