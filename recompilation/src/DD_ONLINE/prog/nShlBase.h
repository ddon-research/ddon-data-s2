#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class uShlAlchemyObj;
class uShlSpeed;

namespace nShlBase {
    enum LIMIT_FOLLOW
    {
        LIMIT_FOLLOW_NONE = -1,
        LIMIT_FOLLOW_JOB08_CS01 = 0,
        LIMIT_FOLLOW_JOB08_CS01_SUB = 1,
        LIMIT_FOLLOW_JOB08_CS02 = 2,
        LIMIT_FOLLOW_JOB08_CS01_CORE = 3,
        LIMIT_FOLLOW_JOB08_CS09 = 4,
        LIMIT_FOLLOW_JOB08_CS02_SUB = 5,
        LIMIT_FOLLOW_JOB08_CS09_SUB = 6,
        LIMIT_FOLLOW_JOB10_CS_SUPPORT_HEAL = 7,
        LIMIT_FOLLOW_JOB10_CS_SUPPORT_HEAL_CORE = 8,
        LIMIT_FOLLOW_JOB10_CS_SUPPORT_HEAL_UNDEAD = 9,
        LIMIT_FOLLOW_JOB10_CS_SUPPORT_CONDITION = 10,
        LIMIT_FOLLOW_JOB10_CS_SUPPORT_CONDITION_BOOST = 11,
        LIMIT_FOLLOW_NUM = 12,
    };
}  // namespace nShlBase

namespace nShlBase {
    enum LIMIT_ID
    {
        LIMIT_ID_NONE = -1,
        LIMIT_ID_JOB04_CS03 = 0,
        LIMIT_ID_JOB04_CS04 = 1,
        LIMIT_ID_JOB03_UP_SHOT = 2,
        LIMIT_ID_JOB08_CS01 = 3,
        LIMIT_ID_JOB08_CS02 = 4,
        LIMIT_ID_JOB08_CS05 = 5,
        LIMIT_ID_JOB08_CS06 = 6,
        LIMIT_ID_JOB08_CLIMB_ATK = 7,
        LIMIT_ID_JOB04_CS07_1 = 8,
        LIMIT_ID_JOB04_CS07_2 = 9,
        LIMIT_ID_JOB04_CS07_3 = 10,
        LIMIT_ID_JOB04_CS07_4 = 11,
        LIMIT_ID_JOB04_CS07_5 = 12,
        LIMIT_ID_JOB06_ATK_L = 13,
        LIMIT_ID_JOB06_CLIMB_ATK = 14,
        LIMIT_ID_JOB08_CS09 = 15,
        LIMIT_ID_JOB04_CS10 = 16,
        LIMIT_ID_JOB09_ALCHEMY = 17,
        LIMIT_ID_JOB09_CS03 = 18,
        LIMIT_ID_JOB09_CS04 = 19,
        LIMIT_ID_JOB09_CS05 = 20,
        LIMIT_ID_JOB09_CS06 = 21,
        LIMIT_ID_JOB09_CS06_AIR = 22,
        LIMIT_ID_JOB09_CS07 = 23,
        LIMIT_ID_JOB06_CS14 = 24,
        LIMIT_ID_JOB04_CS14 = 25,
        LIMIT_ID_JOB09_CS10 = 26,
        LIMIT_ID_JOB04_CS14_2 = 27,
        LIMIT_ID_JOB08_CS14 = 28,
        LIMIT_ID_JOB10_SUPPORT = 29,
        LIMIT_ID_JOB10_CS08 = 30,
        LIMIT_ID_JOB10_CS05 = 31,
        LIMIT_ID_JOB10_CS06 = 32,
        LIMIT_ID_JOB10_CS07 = 33,
        LIMIT_ID_NUM = 34,
    };
}  // namespace nShlBase

namespace nShlBase {
    enum NOTICE_SHL_ID
    {
        SHL_NOTICE_ID_NONE = 0,
        SHL_NOTICE_ID_SPHERE_S = 12,
        SHL_NOTICE_ID_SPHERE_M = 13,
        SHL_NOTICE_ID_SPHERE_L = 14,
        SHL_NOTICE_ID_CAPSULE_S = 15,
        SHL_NOTICE_ID_CAPSULE_M = 16,
        SHL_NOTICE_ID_CAPSULE_L = 17,
        SHL_NOTICE2_ID_SPHERE_S = 18,
        SHL_NOTICE2_ID_SPHERE_M = 19,
        SHL_NOTICE2_ID_SPHERE_L = 20,
        SHL_NOTICE2_ID_CAPSULE_S = 21,
        SHL_NOTICE2_ID_CAPSULE_M = 22,
        SHL_NOTICE2_ID_CAPSULE_L = 23,
    };
}  // namespace nShlBase

namespace nShlBase {
    enum SHL_AXIS
    {
        SHL_AXIS_XY = 513,
        SHL_AXIS_XZ = 258,
        SHL_AXIS_YX = 528,
        SHL_AXIS_YZ = 18,
        SHL_AXIS_ZX = 288,
        SHL_AXIS_ZY = 33,
        SHL_AXIS_XY_M = 4609,
        SHL_AXIS_XZ_M = 4354,
        SHL_AXIS_YX_M = 4624,
        SHL_AXIS_YZ_M = 4114,
        SHL_AXIS_ZX_M = 4384,
        SHL_AXIS_ZY_M = 4129,
    };
}  // namespace nShlBase

namespace nShlBase {
    enum SHL_ID
    {
        SHL_ID_NONE = 0,
        SHL_ID_JOB04_CS03 = 1,
        SHL_ID_JOB04_CS04 = 2,
        SHL_ID_JOB08_CS01 = 3,
        SHL_ID_JOB08_CS02 = 4,
        SHL_ID_JOB08_CS05 = 5,
        SHL_ID_JOB08_CS06 = 6,
        SHL_ID_JOB06_CLIMEB_AT = 7,
        SHL_ID_JOB03_NML_01 = 8,
        SHL_ID_JOB03_NML_02 = 9,
        SHL_ID_JOB08_NML_01 = 10,
        SHL_ID_JOB08_NML_02 = 11,
        SHL_ID_JOB08_NML_03 = 12,
        SHL_ID_JOB05_NML_01 = 13,
        SHL_ID_JOB04_AT_S = 14,
        SHL_ID_JOB06_AT_S = 15,
        SHL_ID_JOB06_AT_L = 16,
        SHL_ID_JOB04_HEAL_CIRCLE = 17,
        SHL_ID_JOB04_CS07_1 = 18,
        SHL_ID_JOB04_CS07_2 = 19,
        SHL_ID_JOB04_CS07_3 = 20,
        SHL_ID_JOB04_CS07_4 = 21,
        SHL_ID_JOB04_CS07_5 = 22,
        SHL_ID_JOB08_CS09 = 23,
        SHL_ID_JOB04_CIRCLE_SHIFT_HEAL = 24,
        SHL_ID_JOB04_CIRCLE_SHIFT_SAINT = 25,
        SHL_ID_JOB04_CIRCLE_SHIFT_ATTACK = 26,
        SHL_ID_JOB04_CIRCLE_SHIFT_DEFENCE = 27,
        SHL_ID_JOB04_CIRCLE_SHIFT_IRON = 28,
        SHL_ID_JOB04_SHIFT_BIT_HEAL = 29,
        SHL_ID_JOB04_SHIFT_BIT_SAINT = 30,
        SHL_ID_JOB04_SHIFT_BIT_ATTACK = 31,
        SHL_ID_JOB04_SHIFT_BIT_DEFENCE = 32,
        SHL_ID_JOB04_SHIFT_BIT_IRON = 33,
        SHL_ID_JOB04_SHIFT_BIT_RANGE = 34,
        SHL_ID_JOB04_ENEGY_SPOT = 35,
        SHL_ID_JOB04_SAINT_CIRCLE = 36,
        SHL_ID_JOB08_CS12 = 37,
        SHL_ID_JOB03_NML2_HIBANA = 38,
        SHL_ID_JOB08_CS11_SHOT = 39,
        SHL_ID_JOB08_CS11_CONST = 40,
        SHL_ID_JOB09_AVOID_ALCHEMY = 41,
        SHL_ID_JOB09_CS03 = 42,
        SHL_ID_JOB09_CS04 = 43,
        SHL_ID_JOB09_CS07 = 44,
        SHL_ID_JOB09_CS05 = 45,
        SHL_ID_JOB09_CS06_LAND = 46,
        SHL_ID_JOB09_CS06_AIR = 47,
        SHL_ID_JOB04_CIRCLE_SHIFT_SOLACE = 48,
        SHL_ID_JOB04_SHIFT_BIT_SOLACE = 49,
        SHL_ID_BLOOD_ORB = 50,
        SHL_ID_JOB06_CS14 = 51,
        SHL_ID_JOB04_CS14 = 52,
        SHL_ID_JOB04_CS14_BIG = 53,
        SHL_ID_JOB06_CS13 = 54,
        SHL_ID_JOB04_CS14_BIG_SECOND = 55,
        SHL_ID_JOB09_CS10 = 56,
        SHL_ID_JOB04_CS12 = 57,
        SHL_ID_JOB05_CS12 = 58,
        SHL_ID_JOB08_CS05_HOMING = 59,
        SHL_ID_JOB05_CS11 = 60,
        SHL_ID_JOB06_CS13_OBJ_HIT = 61,
        SHL_ID_JOB10_ATTACK_BOOST = 62,
        SHL_ID_JOB10_CS07_SET = 63,
        SHL_ID_JOB10_CS05 = 64,
        SHL_ID_JOB10_CS05_LV2 = 65,
        SHL_ID_JOB10_CS06 = 66,
        SHL_ID_JOB10_CS07_CONST = 67,
        SHL_ID_JOB10_CS07_CONST_BOOST = 68,
        SHL_ID_JOB10_CS06_SE = 69,
        SHL_ID_JOB10_CS06_LV2 = 70,
        SHL_ID_NOT_USE_03 = 71,
        SHL_ID_JOB10_SHIFT_BIT_STAMINA = 72,
        SHL_ID_JOB10_SUP_LIMIT_BREAK = 73,
        SHL_ID_JOB10_SUP_LIMIT_BREAK_EFECT = 74,
        SHL_ID_JOB10_CS08_ITEM_SPHERE = 75,
        SHL_ID_JOB10_NORMAL_SUPPORT = 76,
        SHL_ID_JOB10_NORMAL_SUPPORT_BOOST = 77,
        SHL_ID_JOB10_CS06_AULA = 78,
        SHL_ID_JOB10_CS08 = 79,
        SHL_ID_JOB10_CS08_BOOST = 80,
        SHL_ID_JOB10_CS07_SET_BOOST = 81,
        SHL_ID_JOB10_OCD_REDIST_AURA = 82,
        SHL_ID_NOT_USE_05 = 83,
        SHL_ID_SPIRIT_DRAGON_ATK_OM_SHL = 84,
    };
}  // namespace nShlBase

// Declarations
namespace nShlBase { class cShlFuwaMove; }
namespace nShlBase { class cShlStickContextInfo; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nShlBase {
    class cShlFuwaMove
    {
        friend class ::uShlAlchemyObj;
        friend class ::uShlSpeed;
    public:
        cShlFuwaMove();
        virtual ~cShlFuwaMove();
        void init(const MtVector3& period, const MtVector3& scale, const MtVector3& random);
        void update(f32 deltaTime);
        const MtVector3& getPos() const;
        const MtVector3& getDisplace() const;
        void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
    private:
        f32 updateFuwa(f32& timer, f32& period, f32& scale, f32 initPeriod, f32 initScale, f32 initRandom, f32 deltaTime);
    private:
        MtVector3 mPos;  // offset: 0x10
        MtVector3 mDisplace;  // offset: 0x20
        MtVector3 mTimer;  // offset: 0x30
        MtVector3 mPeriod;  // offset: 0x40
        MtVector3 mScale;  // offset: 0x50
        MtVector3 mInitPeriod;  // offset: 0x60
        MtVector3 mInitScale;  // offset: 0x70
        MtVector3 mInitRandom;  // offset: 0x80
    };
}  // namespace nShlBase

namespace nShlBase {
    class cShlStickContextInfo : public ::MtObject
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
        cShlStickContextInfo();
        virtual ~cShlStickContextInfo() {}
    public:
        bool mIsStickCreateControl;  // offset: 0x8
        u32 mStickShlUniqueId;  // offset: 0xc
        u32 mStickUniqueId;  // offset: 0x10
        u8 mStickJointNo;  // offset: 0x14
        u8 mStickShlGroup;  // offset: 0x15
        u8 mStickShlIndex;  // offset: 0x16
        MtVector3 mStickJointOffset;  // offset: 0x20
        MtVector3 mStickDirection;  // offset: 0x30
        static MyDTI DTI;
    };
}  // namespace nShlBase

inline void* nShlBase::cShlStickContextInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* nShlBase::cShlStickContextInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::nShlBase::cShlStickContextInfo::DTI);
}

inline nShlBase::cShlStickContextInfo::cShlStickContextInfo() {
    this->mIsStickCreateControl = false;
    this->mStickShlIndex = 0;
    this->mStickJointNo = 0;
    this->mStickShlGroup = 0;
    this->mStickShlUniqueId = 0;
    this->mStickUniqueId = 0;
    this->mStickJointOffset.x = ::MtVector3::Zero.x;
    this->mStickJointOffset.y = ::MtVector3::Zero.y;
    this->mStickJointOffset.z = ::MtVector3::Zero.z;
    this->mStickDirection.pad_ = 0.0f;
    this->mStickDirection.y = 0.0f;
    this->mStickDirection.z = 0.0f;
    this->mStickJointOffset.pad_ = 0.0f;
    this->mStickDirection.x = 0.0f;
}
