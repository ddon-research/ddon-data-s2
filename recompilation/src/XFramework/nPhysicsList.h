#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtObject.h"

// Forward declarations
namespace nPhysics { namespace Constraint { class Object; } }
namespace nPhysics { class Phantom; }
namespace nPhysics { class RigidBody; }
namespace nPhysics { class System; }

// Declarations
namespace nPhysics { template <typename, unsigned int> class List; }
namespace nPhysics { template <typename TYPE, unsigned int NUM> class ListComponent; }

// Type aliases from DWARF
using s32 = int;

namespace nPhysics {
    template <>
    class List<nPhysics::Constraint::Object, 0> : public ::MtObject
    {
        friend class nPhysics::System;
    public:
        List();
        virtual ~List();
        void add(nPhysics::Constraint::Object* type);
        void remove(nPhysics::Constraint::Object* type);
        void clear();
        void delete_all();
    private:
        nPhysics::Constraint::Object* mTop;  // offset: 0x8
        nPhysics::Constraint::Object* mBottom;  // offset: 0x10
        s32 mNum;  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class List<nPhysics::Constraint::Object, 3> : public ::MtObject
    {
        friend class nPhysics::System;
    public:
        List();
        virtual ~List();
        nPhysics::Constraint::Object* get_top();
        nPhysics::Constraint::Object* get_next(nPhysics::Constraint::Object* current);
        void add(nPhysics::Constraint::Object* type);
        void clear();
    private:
        nPhysics::Constraint::Object* mTop;  // offset: 0x8
        nPhysics::Constraint::Object* mBottom;  // offset: 0x10
        s32 mNum;  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class List<nPhysics::Phantom, 0> : public ::MtObject
    {
        friend class nPhysics::System;
    public:
        List();
        virtual ~List();
        nPhysics::Phantom* get_top();
        nPhysics::Phantom* get_next(nPhysics::Phantom* current);
        void add(nPhysics::Phantom* type);
        void remove(nPhysics::Phantom* type);
        void clear();
        s32 get_num() const;
    private:
        nPhysics::Phantom* mTop;  // offset: 0x8
        nPhysics::Phantom* mBottom;  // offset: 0x10
        s32 mNum;  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class List<nPhysics::Phantom, 1> : public ::MtObject
    {
        friend class nPhysics::System;
    public:
        List();
        virtual ~List();
        nPhysics::Phantom* get_top();
        void add(nPhysics::Phantom* type);
        void remove(nPhysics::Phantom* type);
        void clear();
    private:
        nPhysics::Phantom* mTop;  // offset: 0x8
        nPhysics::Phantom* mBottom;  // offset: 0x10
        s32 mNum;  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class List<nPhysics::RigidBody, 0> : public ::MtObject
    {
        friend class nPhysics::System;
    public:
        List();
        virtual ~List();
        void add(nPhysics::RigidBody* type);
        void remove(nPhysics::RigidBody* type);
        void clear();
    private:
        nPhysics::RigidBody* mTop;  // offset: 0x8
        nPhysics::RigidBody* mBottom;  // offset: 0x10
        s32 mNum;  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class List<nPhysics::RigidBody, 1> : public ::MtObject
    {
        friend class nPhysics::System;
    public:
        List();
        virtual ~List();
        nPhysics::RigidBody* get_top();
        nPhysics::RigidBody* get_next(nPhysics::RigidBody* current);
        void add(nPhysics::RigidBody* type);
        void clear();
    private:
        nPhysics::RigidBody* mTop;  // offset: 0x8
        nPhysics::RigidBody* mBottom;  // offset: 0x10
        s32 mNum;  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class List<nPhysics::RigidBody, 2> : public ::MtObject
    {
        friend class nPhysics::System;
    public:
        List();
        virtual ~List();
        nPhysics::RigidBody* get_top();
        nPhysics::RigidBody* get_next(nPhysics::RigidBody* current);
        void add(nPhysics::RigidBody* type);
        void clear();
    private:
        nPhysics::RigidBody* mTop;  // offset: 0x8
        nPhysics::RigidBody* mBottom;  // offset: 0x10
        s32 mNum;  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class List<nPhysics::RigidBody, 3> : public ::MtObject
    {
        friend class nPhysics::System;
    public:
        List();
        virtual ~List();
        nPhysics::RigidBody* get_top();
        nPhysics::RigidBody* get_next(nPhysics::RigidBody* current);
        void add(nPhysics::RigidBody* type);
        void clear();
    private:
        nPhysics::RigidBody* mTop;  // offset: 0x8
        nPhysics::RigidBody* mBottom;  // offset: 0x10
        s32 mNum;  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class ListComponent<nPhysics::Constraint::Object, 4>
    {
        friend class nPhysics::System;
    public:
        ListComponent();
        virtual ~ListComponent();
    private:
        nPhysics::Constraint::Object* mNext[4];  // offset: 0x8
        nPhysics::Constraint::Object* mPrevious[4];  // offset: 0x28
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class ListComponent<nPhysics::Phantom, 2>
    {
        friend class nPhysics::System;
    public:
        ListComponent();
        virtual ~ListComponent();
    private:
        nPhysics::Phantom* mNext[2];  // offset: 0x8
        nPhysics::Phantom* mPrevious[2];  // offset: 0x18
    };
}  // namespace nPhysics

namespace nPhysics {
    template <>
    class ListComponent<nPhysics::RigidBody, 4>
    {
        friend class nPhysics::System;
    public:
        ListComponent();
        virtual ~ListComponent();
    private:
        nPhysics::RigidBody* mNext[4];  // offset: 0x8
        nPhysics::RigidBody* mPrevious[4];  // offset: 0x28
    };
}  // namespace nPhysics
