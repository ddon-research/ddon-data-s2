#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtMath.h"

// Forward declarations
struct MtFloat3;

// Declarations
namespace nPhysics { class Command; }

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

namespace nPhysics {
    class Command
    {
    public:
        enum
        {
            TYPE_ADD_STATE = 0,
            TYPE_REMOVE_STATE = 1,
            TYPE_SET_STATUS = 2,
            TYPE_SET_POSITION = 3,
            TYPE_SET_ROTATION = 4,
            TYPE_SET_LINEAR_VELOCITY = 5,
            TYPE_SET_ANGULAR_VELOCITY = 6,
            TYPE_SET_POSTURE = 7,
            TYPE_ADD_FORCE = 8,
            TYPE_ADD_TORQUE = 9,
            TYPE_ADD_POSITION_FORCE = 10,
            TYPE_SET_MAXIMUM_MOTOR_TORQUE = 11,
            TYPE_SET_MINIMUM_MOTOR_TORQUE = 12,
            TYPE_SET_MOTOR_SPEED = 13,
            TYPE_SET_MOTOR_AXIS = 14,
            TYPE_SET_ADDITIONAL_SPRING_POWER = 15,
            TYPE_APPLY_WORLD_OFFSET = 16,
        };
    public:
        struct SET_POSITION;
        struct BASE_COMMAND;
        struct SET_ROTATION;
        struct SET_LINEAR_VELOCITY;
        struct SET_ANGULAR_VELOCITY;
        struct SET_POSTURE;
        struct ADD_FORCE;
        struct ADD_TORQUE;
        struct ADD_POSITION_FORCE;
        struct SET_MAXIMUM_MOTOR_TORQUE;
        struct SET_MINIMUM_MOTOR_TORQUE;
        struct SET_MOTOR_SPEED;
        struct SET_MOTOR_AXIS;
        struct APPLY_WORLD_OFFSET;
        struct SET_ADDITIONAL_SPRING_POWER;
    public:
        struct BASE_COMMAND
        {
        protected:
            u32 Type;  // offset: 0x0
        public:
            u32 ID;  // offset: 0x4
        };
    public:
        struct SET_ROTATION : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_ROTATION();
        };
    public:
        struct SET_LINEAR_VELOCITY : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_LINEAR_VELOCITY();
        };
    public:
        struct SET_ANGULAR_VELOCITY : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_ANGULAR_VELOCITY();
        };
    public:
        struct SET_POSTURE : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_POSTURE();
        };
    public:
        struct ADD_FORCE : public nPhysics::Command::BASE_COMMAND
        {
        public:
            ADD_FORCE();
        public:
            MtFloat3 Force;  // offset: 0x8
            f32 Time;  // offset: 0x14
        };
    public:
        struct ADD_TORQUE : public nPhysics::Command::BASE_COMMAND
        {
        public:
            ADD_TORQUE();
        public:
            MtFloat3 Torque;  // offset: 0x8
            f32 Time;  // offset: 0x14
        };
    public:
        struct ADD_POSITION_FORCE : public nPhysics::Command::ADD_FORCE
        {
        public:
            ADD_POSITION_FORCE();
        public:
            MtFloat3 Position;  // offset: 0x18
        };
    public:
        struct SET_MAXIMUM_MOTOR_TORQUE : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_MAXIMUM_MOTOR_TORQUE();
        public:
            f32 Torque;  // offset: 0x8
        };
    public:
        struct SET_MINIMUM_MOTOR_TORQUE : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_MINIMUM_MOTOR_TORQUE();
        public:
            f32 Torque;  // offset: 0x8
        };
    public:
        struct SET_MOTOR_SPEED : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_MOTOR_SPEED();
        public:
            f32 Speed;  // offset: 0x8
        };
    public:
        struct SET_MOTOR_AXIS : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_MOTOR_AXIS();
        public:
            MtFloat3 Axis;  // offset: 0x8
        };
    public:
        struct APPLY_WORLD_OFFSET : public nPhysics::Command::BASE_COMMAND
        {
        public:
            APPLY_WORLD_OFFSET();
        public:
            MtFloat3 Offset;  // offset: 0x8
            MtFloat3 AbsoluteOffset;  // offset: 0x14
        };
    public:
        struct SET_ADDITIONAL_SPRING_POWER : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_ADDITIONAL_SPRING_POWER();
        public:
            f32 Power;  // offset: 0x8
        };
    public:
        struct SET_POSITION : public nPhysics::Command::BASE_COMMAND
        {
        public:
            SET_POSITION();
        };
    };
}  // namespace nPhysics

inline nPhysics::Command::SET_ADDITIONAL_SPRING_POWER::SET_ADDITIONAL_SPRING_POWER() {
}
