#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtMath.h"

// Forward declarations
struct MtFloat4;
class MtQuaternion;
class MtVector3;
class MtVector4;

// Declarations
namespace nMotion { struct CurveKeyFunction; }
namespace nMotion { struct MotionKeyFunction; }
namespace nMotion { struct MOTION_PARAM; }
namespace nMotion { struct CURVE_PARAM; }
namespace nMotion { struct MPARAM_WORK; }
namespace nMotion { struct CPARAM_WORK; }
namespace nMotion { struct MPARAM_LINEARKEY; }
namespace nMotion { struct MPARAM_LINEARKEY_16; }
namespace nMotion { struct MOTION_PARAM_EX; }
namespace nMotion { struct MPARAM_LINEARKEY_8; }
namespace nMotion { struct MPARAM_POLAR3KEY_32; }
namespace nMotion { struct MPARAM_POLAR3KEY; }
namespace nMotion { struct MPARAM_QUNIAXIAL_32; }
namespace nMotion { struct MPARAM_QUATKEY_48; }
namespace nMotion { struct MPARAM_QUATKEY_40; }
namespace nMotion { struct MPARAM_VECTOR3; }
namespace nMotion { struct MPARAM_QUATERNION4; }
namespace nMotion { struct CPARAM_FLOATKEY; }
namespace nMotion { struct CPARAM_FLOATKEY_16; }
namespace nMotion { struct CPARAM_FLOATKEY_8; }
namespace nMotion { struct SEQUENCE_INFO; }
namespace nMotion { struct KEYFRAME_INFO; }
namespace nMotion { struct KEYINFO_U32; }
namespace nMotion { struct MOTION_INFO; }

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using f32 = float;
namespace nMotion { using GetCurveFunction = f32(*)(f32, const void*, f32, f32); }
namespace nMotion { using GetFrameFunction = f32(*)(const void*); }
namespace nMotion { using GetParamFunction = MtFloat4(*)(f32, const void*, const void*); }
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nMotion {

    enum
    {
        SEQ_PAGE00 = 0,
        SEQ_PAGE01 = 1,
        SEQ_PAGE02 = 2,
        SEQ_PAGE03 = 3,
    };

    enum
    {
        SEQ_WORK00 = 0,
        SEQ_WORK01 = 1,
        SEQ_WORK02 = 2,
        SEQ_WORK03 = 3,
        SEQ_WORK04 = 4,
        SEQ_WORK05 = 5,
        SEQ_WORK06 = 6,
        SEQ_WORK07 = 7,
        SEQ_WORK08 = 8,
        SEQ_WORK09 = 9,
        SEQ_WORK10 = 10,
        SEQ_WORK11 = 11,
        SEQ_WORK12 = 12,
        SEQ_WORK13 = 13,
        SEQ_WORK14 = 14,
        SEQ_WORK15 = 15,
        SEQ_WORK16 = 16,
        SEQ_WORK17 = 17,
        SEQ_WORK18 = 18,
        SEQ_WORK19 = 19,
        SEQ_WORK20 = 20,
        SEQ_WORK21 = 21,
        SEQ_WORK22 = 22,
        SEQ_WORK23 = 23,
        SEQ_WORK24 = 24,
        SEQ_WORK25 = 25,
        SEQ_WORK26 = 26,
        SEQ_WORK27 = 27,
        SEQ_WORK28 = 28,
        SEQ_WORK29 = 29,
        SEQ_WORK30 = 30,
        SEQ_WORK31 = 31,
    };

    // Forward declarations
    struct CurveKeyFunction;
    struct MotionKeyFunction;
    struct MOTION_PARAM;
    struct CURVE_PARAM;
    struct MPARAM_WORK;
    struct CPARAM_WORK;
    struct MPARAM_LINEARKEY;
    struct MPARAM_LINEARKEY_16;
    struct MOTION_PARAM_EX;
    struct MPARAM_LINEARKEY_8;
    struct MPARAM_POLAR3KEY_32;
    struct MPARAM_POLAR3KEY;
    struct MPARAM_QUNIAXIAL_32;
    struct MPARAM_QUATKEY_48;
    struct MPARAM_QUATKEY_40;
    struct MPARAM_VECTOR3;
    struct MPARAM_QUATERNION4;
    struct CPARAM_FLOATKEY;
    struct CPARAM_FLOATKEY_16;
    struct CPARAM_FLOATKEY_8;
    struct SEQUENCE_INFO;
    struct KEYFRAME_INFO;
    struct KEYINFO_U32;
    struct MOTION_INFO;

    struct CurveKeyFunction
    {
    public:
        u32 paramSize;  // offset: 0x0
        nMotion::GetFrameFunction getFrame;  // offset: 0x8
        nMotion::GetCurveFunction getParam;  // offset: 0x10
    };

    struct MotionKeyFunction
    {
    public:
        u32 paramSize;  // offset: 0x0
        nMotion::GetFrameFunction getFrame;  // offset: 0x8
        nMotion::GetParamFunction getParam;  // offset: 0x10
    };

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

    struct MPARAM_WORK
    {
    public:
        const nMotion::MOTION_PARAM* pparam;  // offset: 0x0
        f32 cur_frame;  // offset: 0x8
        void* pcur_param;  // offset: 0x10
        f32 weight;  // offset: 0x18
    };

    struct CPARAM_WORK
    {
    public:
        const nMotion::CURVE_PARAM* pparam;  // offset: 0x0
        f32 cur_frame;  // offset: 0x8
        void* pcur_param;  // offset: 0x10
        f32 weight;  // offset: 0x18
    };

    struct MPARAM_LINEARKEY
    {
    public:
        f32 x;  // offset: 0x0
        f32 y;  // offset: 0x4
        f32 z;  // offset: 0x8
        u32 frame;  // offset: 0xc
    };

    struct MPARAM_LINEARKEY_16
    {
    public:
        u16 x;  // offset: 0x0
        u16 y;  // offset: 0x2
        u16 z;  // offset: 0x4
        u16 frame;  // offset: 0x6
    };

    struct MOTION_PARAM_EX
    {
    public:
        MtFloat4 vrange;  // offset: 0x0
        MtFloat4 vbottom;  // offset: 0x10
    };

    struct MPARAM_LINEARKEY_8
    {
    public:
        u8 x;  // offset: 0x0
        u8 y;  // offset: 0x1
        u8 z;  // offset: 0x2
        u8 frame;  // offset: 0x3
    };

    struct MPARAM_POLAR3KEY_32
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 polar28 : 28;  // offset: 0x0
                u32 frame : 4;  // offset: 0x0
            };  // offset: 0x0
            u32 v;  // offset: 0x0
        };  // offset: 0x0
    };

    struct MPARAM_POLAR3KEY
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u64 polar56 : 56;  // offset: 0x0
                u64 frame : 8;  // offset: 0x0
            };  // offset: 0x0
            u64 v;  // offset: 0x0
        };  // offset: 0x0
    };

    struct MPARAM_QUNIAXIAL_32
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 value : 14;  // offset: 0x0
                u32 w : 14;  // offset: 0x0
                u32 frame : 4;  // offset: 0x0
            };  // offset: 0x0
            u32 v;  // offset: 0x0
        };  // offset: 0x0
    };

    struct MPARAM_QUATKEY_48
    {
    public:
        union
        {
        public:
            u16 v[3];  // offset: 0x0
            struct
            {
            public:
                u16 x0 : 11;  // offset: 0x0
                u16 y0 : 5;  // offset: 0x0
                u16 y1 : 6;  // offset: 0x2
                u16 z0 : 10;  // offset: 0x2
                u16 z1 : 1;  // offset: 0x4
                u16 w0 : 11;  // offset: 0x4
                u16 frame : 4;  // offset: 0x4
            };  // offset: 0x0
        };  // offset: 0x0
    };

    struct MPARAM_QUATKEY_40
    {
    public:
        union
        {
        public:
            u8 v[5];  // offset: 0x0
            struct
            {
            public:
                u8 x0;  // offset: 0x0
                u8 x1 : 1;  // offset: 0x1
                u8 y0 : 7;  // offset: 0x1
                u8 y1 : 2;  // offset: 0x2
                u8 z0 : 6;  // offset: 0x2
                u8 z1 : 3;  // offset: 0x3
                u8 w0 : 5;  // offset: 0x3
                u8 w1 : 4;  // offset: 0x4
                u8 frame : 4;  // offset: 0x4
            };  // offset: 0x0
        };  // offset: 0x0
    };

    struct MPARAM_VECTOR3
    {
    public:
        f32 x;  // offset: 0x0
        f32 y;  // offset: 0x4
        f32 z;  // offset: 0x8
    };

    struct MPARAM_QUATERNION4
    {
    public:
        f32 x;  // offset: 0x0
        f32 y;  // offset: 0x4
        f32 z;  // offset: 0x8
        f32 w;  // offset: 0xc
    };

    struct CPARAM_FLOATKEY
    {
    public:
        f32 v;  // offset: 0x0
        u32 frame;  // offset: 0x4
    };

    struct CPARAM_FLOATKEY_16
    {
    public:
        u16 v;  // offset: 0x0
        u16 frame;  // offset: 0x2
    };

    struct CPARAM_FLOATKEY_8
    {
    public:
        u8 v;  // offset: 0x0
        u8 frame;  // offset: 0x1
    };

    struct SEQUENCE_INFO
    {
    public:
        u16 work[32];  // offset: 0x0
        u32 seq_num;  // offset: 0x40
        u32 padding;  // offset: 0x44
        u32* seq;  // offset: 0x48
    };

    struct KEYFRAME_INFO
    {
    public:
        union
        {
        public:
            u32 info;  // offset: 0x0
            struct
            {
            public:
                u32 type : 8;  // offset: 0x0
                u32 work : 16;  // offset: 0x0
                u32 attr : 8;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x0
        u32 key_num;  // offset: 0x4
        nMotion::KEYINFO_U32* key;  // offset: 0x8
    };

    struct KEYINFO_U32
    {
    public:
        union
        {
        public:
            u32 opt;  // offset: 0x0
            struct
            {
            public:
                u32 curve : 8;  // offset: 0x0
                u32 frame : 16;  // offset: 0x0
                u32 reserved : 8;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x0
        union
        {
        public:
            u32 value;  // offset: 0x0
            s32 valS32;  // offset: 0x0
            f32 valF32;  // offset: 0x0
        };  // offset: 0x4
        union
        {
        public:
            u32 paramU[2];  // offset: 0x0
            s32 paramS[2];  // offset: 0x0
            f32 paramF[2];  // offset: 0x0
        };  // offset: 0x8
    };

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

    f32 fromFloat16(f32 t, const void* pkey, f32 bottom, f32 range);
    f32 fromFloat8(f32 t, const void* pkey, f32 bottom, f32 range);
    void setupParam(MPARAM_WORK* pwk, const MOTION_PARAM* pparam);
    MtFloat4 calcMotionKey(MPARAM_WORK* pwork, f32 frame);
    s32 getMotParamKeyNum(const MOTION_PARAM* pmp);
    void setupCurveParam(CPARAM_WORK* pwk, const CURVE_PARAM* pparam);
    f32 calcCurveKey(CPARAM_WORK* pwork, f32 frame);
    s32 getCurveParamKeyNum(const CURVE_PARAM* pmp);
    f32 getFrame_Dummy(const void* pkey);
    f32 getFrame_UNCOMPRESSKEY(const void* pkey);
    MtFloat4 fromDummy(f32 t, const void* pkey, const void* pe);
    MtFloat4 fromLinear(f32 t, const void* pkey, const void* pe);
    MtFloat4 fromLinear16(f32 t, const void* pkey, const void* pe);
    MtFloat4 fromLinear8(f32 t, const void* pkey, const void* pe);
    MtQuaternion decQuatKey32(u32 v, const MtVector4& vrange, const MtVector4& vbottom);
    MtFloat4 fromQuat32(f32 t, const void* pkey, const void* pe);
    MtFloat4 fromQuat64(f32 t, const void* pkey, const void* pe);
    MtQuaternion decQAxisXKey32(const MPARAM_QUNIAXIAL_32& key, const MtVector4& vrange, const MtVector4& vbottom);
    MtFloat4 fromQAxisX32(f32 t, const void* pkey, const void* pe);
    MtQuaternion decQAxisYKey32(const MPARAM_QUNIAXIAL_32& key, const MtVector4& vrange, const MtVector4& vbottom);
    MtFloat4 fromQAxisY32(f32 t, const void* pkey, const void* pe);
    MtQuaternion decQAxisZKey32(const MPARAM_QUNIAXIAL_32& key, const MtVector4& vrange, const MtVector4& vbottom);
    MtFloat4 fromQAxisZ32(f32 t, const void* pkey, const void* pe);
    MtQuaternion decQuatKey48(const MPARAM_QUATKEY_48& key, const MtVector4& vrange, const MtVector4& vbottom);
    MtFloat4 fromQuat48(f32 t, const void* pkey, const void* pe);
    MtQuaternion decQuatKey40(const MPARAM_QUATKEY_40& key, const MtVector4& vrange, const MtVector4& vbottom);
    MtFloat4 fromQuat40(f32 t, const void* pkey, const void* pe);
    MtFloat4 fromLinear96(f32 t, const void* pkey, const void* pe);
    MtFloat4 fromQuat128(f32 t, const void* pkey, const void* pe);
    f32 fromCurveDummy(f32 t, const void* pkey, f32 bottom, f32 range);
    f32 lerp(f32 a, f32 b, f32 w);
    f32 fromFloat(f32 t, const void* pkey, f32 bottom, f32 range);
    template <typename T> f32 getFrame_KEY(const void* pkey);

}  // namespace nMotion
