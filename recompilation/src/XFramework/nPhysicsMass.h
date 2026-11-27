#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCapsule;
class MtCylinder;
class MtDTI;
class MtOBB;
class MtPropertyList;
class MtSphere;
class MtTriangle;
class MtVector3;

// Declarations
namespace nPhysics { class Mass; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nPhysics {
    class Mass : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        Mass();
        virtual ~Mass() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void clear();
        void add(const f32 mass);
        static f32 calculate(const MtAABB& aabb, const f32 density);
        static f32 calculate(const MtOBB& obb, const f32 density);
        static f32 calculate(const MtSphere& sphere, const f32 density);
        static f32 calculate(const MtCapsule& capsule, const f32 density);
        static f32 calculate(const MtCylinder& cylinder, const f32 density);
        static f32 calculate(const MtTriangle& triangle, const MtVector3& origin, const f32 density);
        static f32 calculate(const MtTriangle& triangle, const f32 density);
        f32 getMass() const;
        f32 getInverseMass() const;
        void set(f32, f32);
        void setMass(f32 mass);
        void setInverseMass(f32 mass);
    private:
        f32 mMass;  // offset: 0x8
        f32 mInverseMass;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
}  // namespace nPhysics

inline void* nPhysics::Mass::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nPhysics::Mass::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nPhysics::Mass::DTI)->memFree(p_addr);
}
