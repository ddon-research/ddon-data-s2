#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtMath.h"

// Forward declarations
struct MtFloat4;
class MtQuaternion;
class MtVector3;
namespace nMotion { struct KEYFRAME_INFO; }

// Declarations
namespace nMotion { struct CURVE_PARAM; }
namespace nMotion { struct MOTION_INFO; }
namespace nMotion { struct MOTION_PARAM; }
namespace nMotion { struct MPARAM_WORK; }
namespace nMotion { struct SEQUENCE_INFO; }

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;

namespace nMotion {
    struct CURVE_PARAM
    {
    public:
        enum TYPE
        {
            T_UNKNOWN = 0,
            T_FLOAT = 1,
            T_FLOAT_CONST = 2,
            T_FLOATKEY = 3,
            T_FLOATKEY_16 = 4,
            T_FLOATKEY_8 = 5,
            T_PARAM_TYPE_NUM = 6,
        };
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 type : 8;  // offset: 0x0
                u32 usage : 8;  // offset: 0x0
                u32 curve_type : 8;  // offset: 0x0
                u32 curve_no : 8;  // offset: 0x0
            };  // offset: 0x0
            u32 header;  // offset: 0x0
        };  // offset: 0x0
        u32 param_size;  // offset: 0x4
        f32 fbottom;  // offset: 0x8
        f32 frange;  // offset: 0xc
        void* pparam;  // offset: 0x10
    };
}  // namespace nMotion

namespace nMotion {
    struct MOTION_INFO
    {
    public:
        enum MOTION_ATTRIBUTE
        {
            A_SCALE_GLOBAL = 1,
            A_SCALE_INHERIT_WDIR = 2,
            A_DIFF_MOTION = 4,
            A_NON_COMPRESS = 128,
        };
        enum DUPLICATE_FLAG
        {
            D_MOTION = 1,
            D_SEQUENCE = 2,
            D_KEYFRAME = 4,
        };
    public:
        nMotion::MOTION_PARAM* param;  // offset: 0x0
        u32 param_num;  // offset: 0x8
        u32 frame_num;  // offset: 0xc
        s32 loop_frame;  // offset: 0x10
        MtVector3 base_trans;  // offset: 0x20
        MtQuaternion base_quat;  // offset: 0x30
        union
        {
        public:
            struct
            {
            public:
                u32 attr : 16;  // offset: 0x0
                u32 kf_num : 5;  // offset: 0x0
                u32 seq_num : 3;  // offset: 0x0
                u32 duplicate : 3;  // offset: 0x0
                u32 reserved : 5;  // offset: 0x0
            };  // offset: 0x0
            u32 info;  // offset: 0x0
        };  // offset: 0x40
        u32 padding;  // offset: 0x44
        nMotion::SEQUENCE_INFO* seq_info;  // offset: 0x48
        nMotion::KEYFRAME_INFO* kf_info;  // offset: 0x50
    };
}  // namespace nMotion

namespace nMotion {
    struct MOTION_PARAM
    {
    public:
        enum TYPE
        {
            T_UNKNOWN = 0,
            T_VECTOR3_CONST = 1,
            T_QUATERNION3_CONST = 2,
            T_LINEARKEY = 3,
            T_LINEARKEY_16 = 4,
            T_LINEARKEY_8 = 5,
            T_POLAR3KEY = 6,
            T_POLAR3KEY_32 = 7,
            T_VECTOR3 = 8,
            T_QUATERNION4 = 9,
            T_POLAR3 = 10,
            T_QAXIS_X_32 = 11,
            T_QAXIS_Y_32 = 12,
            T_QAXIS_Z_32 = 13,
            T_QUATKEY_48 = 14,
            T_QUATKEY_40 = 15,
            T_HERMITE3 = 16,
            T_SMALLEST3 = 17,
            T_PARAM_TYPE_NUM = 18,
        };
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 type : 8;  // offset: 0x0
                u32 usage : 8;  // offset: 0x0
                u32 jnt_type : 8;  // offset: 0x0
                u32 jnt_no : 8;  // offset: 0x0
            };  // offset: 0x0
            u32 header;  // offset: 0x0
        };  // offset: 0x0
        f32 weight;  // offset: 0x4
        u32 param_size;  // offset: 0x8
        u32 padding;  // offset: 0xc
        void* pparam;  // offset: 0x10
        MtFloat4 value;  // offset: 0x18
        void* pparamex;  // offset: 0x28
    };
}  // namespace nMotion

namespace nMotion {
    struct MPARAM_WORK
    {
    public:
        const nMotion::MOTION_PARAM* pparam;  // offset: 0x0
        f32 cur_frame;  // offset: 0x8
        void* pcur_param;  // offset: 0x10
        f32 weight;  // offset: 0x18
    };
}  // namespace nMotion

namespace nMotion {
    struct SEQUENCE_INFO
    {
    public:
        u16 work[32];  // offset: 0x0
        u32 seq_num;  // offset: 0x40
        u32 padding;  // offset: 0x44
        u32* seq;  // offset: 0x48
    };
}  // namespace nMotion
