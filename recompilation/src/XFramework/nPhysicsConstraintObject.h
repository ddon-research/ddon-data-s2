#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "nPhysicsBase.h"
#include "nPhysicsList.h"
#include "nPhysicsStruct.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
namespace nPhysics { struct CONSTRAINT; }
namespace nPhysics { class RigidBody; }

// Declarations
namespace nPhysics { namespace Constraint { class Object; } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nPhysics {
    namespace Constraint {
        class Object : public nPhysics::Base
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
            Object();
            Object(const nPhysics::CONSTRAINT::TYPE type);
            virtual ~Object();
            void setError();
            bool isError() const;
            void setEnable(const bool);
            bool isEnable() const;
            void enable();
            void disable();
            virtual void setStatus(const u32) = 0;  // vtable slot 6
            virtual u32 getStatus() const = 0;  // vtable slot 7
            const nPhysics::RigidBody* getRigidBody(const u32 index);
        private:
            u32 getType();
            void setType(const u32);
        protected:
            static nPhysics::CONSTRAINT* CreateConstraintInstance();
            static void RemoveConstraintInstance(nPhysics::CONSTRAINT* constraint);
        private:
            nPhysics::CONSTRAINT::TYPE mType;  // offset: 0x8
        protected:
            nPhysics::RigidBody* mRigidBody[2];  // offset: 0x10
        public:
            nPhysics::ListComponent<nPhysics::Constraint::Object, 4> mListComponent;  // offset: 0x20
            static MyDTI DTI;
        };
    }  // namespace Constraint
}  // namespace nPhysics

inline void* nPhysics::Constraint::Object::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nPhysics::Constraint::Object::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nPhysics::Constraint::Object::DTI)->memFree(p_addr);
}
