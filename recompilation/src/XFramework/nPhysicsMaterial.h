#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;

// Declarations
namespace nPhysics { class Material; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nPhysics {
    class Material : public ::MtObject
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
        Material();
        virtual ~Material();
        f32 getStaticFriction() const;
        void setStaticFriction(const f32 friction);
        f32 getKineticFriction() const;
        void setKineticFriction(const f32 friction);
        f32 getRestitution() const;
        void setRestitution(const f32 restitution);
    private:
        f32 mStaticFriction;  // offset: 0x8
        f32 mKineticFriction;  // offset: 0xc
        f32 mRestitution;  // offset: 0x10
        MtVector3 mDirection;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nPhysics

inline void* nPhysics::Material::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nPhysics::Material::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nPhysics::Material::DTI)->memFree(p_addr);
}
