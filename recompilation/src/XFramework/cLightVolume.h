#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtMath.h"
#include "../MT/MtPrimitive3D.h"

// Forward declarations
class MtMatrix;
class MtOBB;
class MtSphere;
class MtVector3;
class cDraw;
class uLight;

// Declarations
class cConvexBoundingVolume;
class cLightVolume;
class cSphereVolume;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;

class cConvexBoundingVolume
{
public:
    virtual const MtMatrix& getMatrix() const = 0;  // vtable slot 0
    virtual void draw(cDraw*) const = 0;  // vtable slot 1
    virtual bool isIntersect(const MtOBB&) const = 0;  // vtable slot 2
protected:
    virtual ~cConvexBoundingVolume() {}
};

class cLightVolume
{
public:
    cLightVolume();
    virtual ~cLightVolume() {}
    virtual void update(uLight*) = 0;  // vtable slot 2
    void draw(cDraw* pdraw, uLight* light);
    static cLightVolume* CreateLightVolume(uLight* light);
    void beginCBLightVolumeReduce(cDraw* pdraw, f32 Disable);
    static void* operator new(size_t s);
    static void operator delete(void* padr);
    static void* operator new[](size_t s);
    static void operator delete[](void* padr);
private:
    virtual bool isCulling(cDraw* pdraw, uLight* light);  // vtable slot 3
    virtual void drawVolume(cDraw*, uLight*, bool) = 0;  // vtable slot 4
};

class cSphereVolume : public cConvexBoundingVolume
{
public:
    cSphereVolume();
    virtual ~cSphereVolume() {}
    virtual const MtMatrix& getMatrix() const;  // vtable slot 0
    virtual void draw(cDraw* pdraw) const;  // vtable slot 1
    virtual bool isIntersect(const MtOBB& obb) const;  // vtable slot 2
    void updateMatrix(const MtVector3& pos, f32 radius);
    static void* operator new(size_t s);
    static void operator delete(void* padr);
    static void* operator new[](size_t s);
    static void operator delete[](void* padr);
private:
    MtMatrix mMat;  // offset: 0x10
    MtSphere mSphere;  // offset: 0x50
};

inline cLightVolume::cLightVolume() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "cUnit.h"

inline void cSphereVolume::operator delete(void* padr) {
    ::MtMemoryAllocator::getAllocator(::cUnit::DTI)->memFree(padr);
}
