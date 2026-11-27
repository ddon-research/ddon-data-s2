#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nPhysicsList.h"
#include "nPhysicsShape.h"
#include "nPhysicsStruct.h"

// Forward declarations
class MtGeometry;
class MtObject;
namespace nPhysics { struct AABB; }
namespace nPhysics { struct COLLISION_INFORMATION; }
namespace nPhysics { struct CONTACT_INFO; }
namespace nPhysics { class RigidBody; }
namespace nPhysics { class SHAPE; }
namespace nPhysics { class SHAPES; }

// Declarations
namespace nPhysics { class Phantom; }

// Type aliases from DWARF
using u32 = unsigned int;

namespace nPhysics {
    class Phantom
    {
    public:
        enum STATE
        {
            STATE_AUTO_DISABLE = 0,
            STATE_MAX = 1,
        };
    public:
        using EVENT_CALLBACK = void(MtObject::*)();
        using COLLIDE_CALLBACK = void(MtObject::*)(nPhysics::RigidBody&, const nPhysics::CONTACT_INFO&);
    private:
        nPhysics::AABB get_circumscribed_aabb() const;
        const nPhysics::COLLISION_INFORMATION& get_collision_information() const;
        void update();
        nPhysics::CONTACT_INFO closest(const nPhysics::SHAPES& shapes) const;
        void disable();
        bool is_enable_collide_callback() const;
        void execute_begin_callback() const;
        void execute_collide_callback(nPhysics::RigidBody& rigid_body, const nPhysics::CONTACT_INFO& contact_info) const;
        void end();
    public:
        Phantom();
        ~Phantom();
        bool isEnable() const;
        void setShape(const MtGeometry& shape);
        void clearShape();
        void setOnlyOneFrame(const bool);
        void setKeepAliveTime(const u32 time);
        void setSelfObject(MtObject* self);
        void setBeginCallback(EVENT_CALLBACK function);
        void setCollideCallback(COLLIDE_CALLBACK function);
        void setEndCallback(EVENT_CALLBACK function);
        u32 getCollisionGroup() const;
        u32 getCollisionID() const;
        u32 getCollisionBit() const;
        u32 getCollisionPrimaryFilter() const;
        u32 getCollisionPrimaryAttribute() const;
        u32 getCollisionSecondaryFilter() const;
        u32 getCollisionSecondaryAttribute() const;
        void setCollisionGroup(const u32);
        void setCollisionID(const u32);
        void setCollisionBit(const u32);
        void setCollisionPrimaryFilter(const u32);
        void setCollisionPrimaryAttribute(const u32);
        void setCollisionSecondaryFilter(const u32);
        void setCollisionSecondaryAttribute(const u32);
    private:
        nPhysics::COLLISION_INFORMATION mCollisionInformation;  // offset: 0x0
        nPhysics::SHAPE mShape;  // offset: 0x20
        nPhysics::SHAPE mUpdateShape;  // offset: 0x70
        MtObject* mSelfObject;  // offset: 0xc0
        EVENT_CALLBACK mBeginCallbackFunction;  // offset: 0xc8
        COLLIDE_CALLBACK mCollideCallbackFunction;  // offset: 0xd8
        EVENT_CALLBACK mEndCallbackFunction;  // offset: 0xe8
        u32 mKeepAliveTime;  // offset: 0xf8
        u32 mStatus;  // offset: 0xfc
        bool mUpdate;  // offset: 0x100
        bool mEnable;  // offset: 0x101
    public:
        nPhysics::ListComponent<nPhysics::Phantom, 2> mListComponent;  // offset: 0x108
    private:
        static u32 PHANTOM_UNIQUE_ID;
    };
}  // namespace nPhysics
