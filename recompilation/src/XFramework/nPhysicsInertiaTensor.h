#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCapsule;
class MtCylinder;
class MtDTI;
class MtMatrix;
class MtOBB;
class MtQuaternion;
class MtSphere;
class MtTriangle;
class MtVector3;

// Declarations
namespace nPhysics { class InertiaTensor; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nPhysics {
    class InertiaTensor : public ::MtObject
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
        InertiaTensor();
        virtual ~InertiaTensor() {}
        void setInertiaTensor(const MtMatrix& inertia_tensor);
        void update(const MtQuaternion& rotation);
        void clear();
        void add(const MtOBB& obb, const f32 mass);
        void add(const MtSphere& sphere, const f32 mass);
        void add(const MtCapsule& capsule, const f32 mass);
        void add(const MtCylinder& cylinder, const f32 mass);
        void add(const MtTriangle& triangle, const MtVector3& origin, const f32 mass);
        void add(const MtMatrix& inertia_tensor);
        static MtMatrix calculate(const MtAABB& aabb, const f32 mass);
        static MtMatrix calculate(const MtOBB& obb, const f32 mass);
        static MtMatrix calculate(const MtSphere& sphere, const f32 mass);
        static MtMatrix calculate(const MtCapsule& capsule, const f32 mass);
        static MtMatrix calculate(const MtCylinder& cylinder, const f32 mass);
        static MtMatrix calculate(const MtTriangle& triangle, const MtVector3& origin, const f32 mass);
        static MtMatrix calculate(const MtTriangle& triangle, const f32 mass);
        const MtMatrix& getCurrent() const;
        const MtMatrix& getCurrentInverse() const;
        const MtMatrix& getBasic() const;
        const MtMatrix& getBasicInverse() const;
        static void Translation(MtMatrix& base, const f32 mass, const MtVector3& vector);
        static void Rotation(MtMatrix& base, const MtMatrix& matrix);
    private:
        MtMatrix mBasic;  // offset: 0x10
        MtMatrix mBasicInverse;  // offset: 0x50
        MtMatrix mCurrent;  // offset: 0x90
        MtMatrix mCurrentInverse;  // offset: 0xd0
    public:
        static MyDTI DTI;
    };
}  // namespace nPhysics

inline void* nPhysics::InertiaTensor::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void* nPhysics::InertiaTensor::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nPhysics::InertiaTensor::DTI)->memAlloc(sz, align, ::nPhysics::InertiaTensor::DTI.::MtDTI::mID);
}

inline void nPhysics::InertiaTensor::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nPhysics::InertiaTensor::DTI)->memFree(p_addr);
}
