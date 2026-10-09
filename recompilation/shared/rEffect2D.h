#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "cResource.h"
#include "nEffect.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtRangeF;
class MtRangeU16;
class MtStream;
class MtUI;
namespace nEffect { struct KEYFRAME_INDEX; }
namespace nEffect { class SimpleCurve; }
class rEffectAnim;
class rModel;
class rRenderTargetTexture;
class rTexture;

// Declarations
class rEffect2D;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rEffect2D : public cResource
{
public:
    enum GENERATOR_TYPE
    {
        GENERATOR_TYPE_SINGLE = 0,
        GENERATOR_TYPE_LOOP = 1,
        GENERATOR_TYPE_NUM = 2,
    };
    enum PARTICLE_TYPE
    {
        PARTICLE_TYPE_SPRITE = 0,
        PARTICLE_TYPE_POLYLINE = 1,
        PARTICLE_TYPE_TEXLINE = 2,
        PARTICLE_TYPE_LINE = 3,
        PARTICLE_TYPE_MODEL = 4,
        PARTICLE_TYPE_NUM = 5,
    };
    enum LIFE_TYPE
    {
        LIFE_TYPE_NONE = 0,
        LIFE_TYPE_FRAME_ALPHA = 1,
        LIFE_TYPE_FRAME_COLOR = 2,
        LIFE_TYPE_KEYFRAME_ALPHA = 3,
        LIFE_TYPE_KEYFRAME_COLOR = 4,
        LIFE_TYPE_HIDEFRAME_ALPHA = 5,
        LIFE_TYPE_HIDEFRAME_COLOR = 6,
        LIFE_TYPE_CURVEFRAME_ALPHA = 7,
        LIFE_TYPE_CURVEFRAME_COLOR = 8,
        LIFE_TYPE_NUM = 9,
    };
    enum MOVE_TYPE
    {
        MOVE_TYPE_NONE = 0,
        MOVE_TYPE_ADD = 1,
        MOVE_TYPE_MUL = 2,
        MOVE_TYPE_CUSTOM = 3,
        MOVE_TYPE_NUM = 4,
    };
    enum RANGE_OPTION_FLAG
    {
        RANGE_OPTION_FLAG_EACH_FRAME = 1,
    };
    enum PARTICLE_OPTION_FLAG
    {
        PARTICLE_OPTION_FLAG_ALPHA_WRITE = 1,
        PARTICLE_OPTION_FLAG_ALPHA_BLUR = 2,
        PARTICLE_OPTION_FLAG_NO_REDUCTION = 4,
        PARTICLE_OPTION_FLAG_NO_ZTEST = 8,
        PARTICLE_OPTION_FLAG_DISTORTION = 16,
        PARTICLE_OPTION_FLAG_LV_CORRECTION = 32,
        PARTICLE_OPTION_FLAG_POINT_FILTER = 64,
    };
    enum RANGE_TYPE
    {
        RANGE_TYPE_NONE = 0,
        RANGE_TYPE_X_RECT = 1,
        RANGE_TYPE_Y_RECT = 2,
        RANGE_TYPE_CIRCLE = 3,
        RANGE_TYPE_NUM = 4,
    };
    enum RANGE_DIR_TYPE
    {
        RANGE_DIR_TYPE_NONE = 0,
        RANGE_DIR_TYPE_DIFFUSE = 1,
        RANGE_DIR_TYPE_CONVERGE = 2,
        RANGE_DIR_TYPE_COMMON_03 = 3,
        RANGE_DIR_TYPE_COMMON_04 = 4,
        RANGE_DIR_TYPE_COMMON_05 = 5,
        RANGE_DIR_TYPE_COMMON_06 = 6,
        RANGE_DIR_TYPE_COMMON_07 = 7,
        RANGE_DIR_TYPE_CUSTOM_08 = 8,
        RANGE_DIR_TYPE_CUSTOM_09 = 9,
        RANGE_DIR_TYPE_CUSTOM_0A = 10,
        RANGE_DIR_TYPE_CUSTOM_0B = 11,
        RANGE_DIR_TYPE_CUSTOM_0C = 12,
        RANGE_DIR_TYPE_CUSTOM_0D = 13,
        RANGE_DIR_TYPE_CUSTOM_0E = 14,
        RANGE_DIR_TYPE_CUSTOM_0F = 15,
        RANGE_DIR_TYPE_NUM = 16,
    };
    enum GENERATOR_OPTION_FLAG
    {
        GENERATOR_OPTION_FLAG_X_REPEAT = 1,
        GENERATOR_OPTION_FLAG_Y_REPEAT = 2,
        GENERATOR_OPTION_FLAG_REPEAT = 3,
    };
    enum UNIT_OPTION_FLAG
    {
        UNIT_OPTION_FLAG_CULLING = 1,
        UNIT_OPTION_FLAG_DRAW_VIEW = 2,
        UNIT_OPTION_FLAG_COLOR_CONTROL = 4,
        UNIT_OPTION_FLAG_CULLING_NEAR_CLIP = 1024,
        UNIT_OPTION_FLAG_CULLING_FAR_CLIP = 2048,
    };
    enum RT_NM_CONVERT
    {
        RT_NM_CONVERT_NONE = 0,
        RT_NM_CONVERT_HM_TO_NM = 1,
        RT_NM_CONVERT_HM_TO_PM = 2,
        RT_NM_CONVERT_RHM_TO_NM = 3,
        RT_NM_CONVERT_RHM_TO_PM = 4,
        RT_NM_CONVERT_BM_TO_NM = 5,
    };
    enum LINE_TYPE
    {
        LINE_TYPE_FOLLOW = 0,
        LINE_TYPE_FIX = 1,
        LINE_TYPE_LENGTH = 2,
        LINE_TYPE_NUM = 3,
    };
    enum TEX
    {
        TEX_BM = 0,
        TEX_NM = 1,
        TEX_MM = 2,
        MAX_TEX = 3,
    };
public:
    class MyDTI;
    class ResourceInfo;
    struct E2D_UNIT;
    struct E2D_INDEX;
    struct E2D_GENERATOR;
    struct E2D_PARTICLE_COMMON;
    struct E2D_PARAM_DRAW;
    struct E2D_PARAM_LEVEL_CORRECTION;
    struct E2D_LIFE_FRAME;
    struct E2D_MOVE_COMMON;
    struct E2D_PARAM_LINE_FIX;
    struct E2D_PARAM_LINE_LENGTH;
    struct E2D_PARTICLE_MODEL;
    struct E2D_PARAM_TEX_SCROLL;
    struct E2D_PARTICLE_POLYLINE;
    struct E2D_PARTICLE_PRIM_COMMON;
    struct E2D_PARTICLE_PAT_COMMON;
    struct E2D_PARTICLE_TEXLINE;
    struct E2D_PARTICLE_LINE;
    struct E2D_LIFE_KEYFRAME;
    struct E2D_LIFE_HIDEFRAME;
    struct E2D_LIFE_CURVEFRAME;
    struct E2D_MOVE_ADD;
    struct E2D_MOVE_MUL;
    struct E2D_PARTICLE_SPRITE;
    struct E2D_HEADER;
public:
    using E2D_UNIT = rEffect2D::E2D_UNIT;
    using E2D_INDEX = rEffect2D::E2D_INDEX;
    using E2D_GENERATOR = rEffect2D::E2D_GENERATOR;
    using E2D_PARTICLE_COMMON = rEffect2D::E2D_PARTICLE_COMMON;
    using E2D_PARAM_DRAW = rEffect2D::E2D_PARAM_DRAW;
    using E2D_PARAM_LEVEL_CORRECTION = rEffect2D::E2D_PARAM_LEVEL_CORRECTION;
    using E2D_LIFE_FRAME = rEffect2D::E2D_LIFE_FRAME;
    using E2D_MOVE_COMMON = rEffect2D::E2D_MOVE_COMMON;
    using E2D_PARAM_LINE_FIX = rEffect2D::E2D_PARAM_LINE_FIX;
    using E2D_PARAM_LINE_LENGTH = rEffect2D::E2D_PARAM_LINE_LENGTH;
    using E2D_PARTICLE_MODEL = rEffect2D::E2D_PARTICLE_MODEL;
    using E2D_PARAM_TEX_SCROLL = rEffect2D::E2D_PARAM_TEX_SCROLL;
    using E2D_PARTICLE_POLYLINE = rEffect2D::E2D_PARTICLE_POLYLINE;
    using E2D_PARTICLE_PRIM_COMMON = rEffect2D::E2D_PARTICLE_PRIM_COMMON;
    using E2D_PARTICLE_PAT_COMMON = rEffect2D::E2D_PARTICLE_PAT_COMMON;
    using E2D_PARTICLE_TEXLINE = rEffect2D::E2D_PARTICLE_TEXLINE;
    using E2D_PARTICLE_LINE = rEffect2D::E2D_PARTICLE_LINE;
    using E2D_PARTICLE_SPRITE = rEffect2D::E2D_PARTICLE_SPRITE;
    using E2D_LIFE_KEYFRAME = rEffect2D::E2D_LIFE_KEYFRAME;
    using E2D_LIFE_HIDEFRAME = rEffect2D::E2D_LIFE_HIDEFRAME;
    using E2D_LIFE_CURVEFRAME = rEffect2D::E2D_LIFE_CURVEFRAME;
    using E2D_MOVE_ADD = rEffect2D::E2D_MOVE_ADD;
    using E2D_MOVE_MUL = rEffect2D::E2D_MOVE_MUL;
    using E2D_HEADER = rEffect2D::E2D_HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class ResourceInfo
    {
    public:
        enum STATUS
        {
            STATUS_TEX_CREATE_FAILED = 1,
            STATUS_TEX0_CREATE_FAILED = 1,
            STATUS_TEX1_CREATE_FAILED = 2,
            STATUS_TEX2_CREATE_FAILED = 4,
            STATUS_EAN_CREATE_FAILED = 8,
            STATUS_MOD_CREATE_FAILED = 16,
            STATUS_NO_EAN_CREATE = 4096,
            STATUS_NO_MOD_CREATE = 8192,
            STATUS_NO_TEX_CREATE = 16384,
            STATUS_ERROR = 65535,
        };
    public:
        ResourceInfo();
        ~ResourceInfo();
        static void* operator new(size_t);
        static void* operator new[](size_t s);
        static void operator delete(void*);
        static void operator delete[](void* pObj);
        void releaseResources();
        void createParticleResources(rEffect2D::E2D_PARTICLE_COMMON* pParticleParam, u32 ParticleType);
        rEffectAnim* getAnim();
        rModel* getModel();
        f32 getTextureInvW() const;
        f32 getTextureInvH() const;
        cResource* getChar();
        rTexture* getTexture(u32 No);
        bool checkCreate();
    private:
        bool createTexture(MT_CHAR* pPath, u32 No);
        void createAnim(MT_CHAR* pPath);
        void createModel(MT_CHAR* pPath);
    private:
        u32 mStatus;  // offset: 0x0
        rTexture* mpTexture[3];  // offset: 0x8
        cResource* mpChar;  // offset: 0x20
        f32 mTextureInvW;  // offset: 0x28
        f32 mTextureInvH;  // offset: 0x2c
    };
public:
    struct E2D_UNIT
    {
    public:
        u32 DrawMode : 8;  // offset: 0x0
        u32 EntryType : 8;  // offset: 0x0
        u32 UnitOptionFlag : 16;  // offset: 0x0
        u32 DrawPriority;  // offset: 0x4
        MtColor RTBaseMapColor;  // offset: 0x8
        MtColor RTNormalMapColor;  // offset: 0xc
        f32 RTNormalSlope;  // offset: 0x10
        f32 RTNormalMipMapScale;  // offset: 0x14
        u32 SceneW : 16;  // offset: 0x18
        u32 SceneH : 16;  // offset: 0x18
        u32 RTNormalMapConvert : 8;  // offset: 0x1c
        u32 RTMaskMapAlpha : 8;  // offset: 0x1c
        u32 DrawView : 16;  // offset: 0x1c
        u32 ColorBlendRate : 16;  // offset: 0x20
        u32 ColorID : 8;  // offset: 0x20
        u32 UScreenAdaptedFlag : 1;  // offset: 0x20
        u32 Unit0723 : 7;  // offset: 0x20
        u32 RTBaseMapPathOffset : 16;  // offset: 0x24
        u32 RTNormalMapPathOffset : 16;  // offset: 0x24
        u32 RTMaskMapPathOffset : 16;  // offset: 0x28
        u32 BackBaseMapPathOffset : 16;  // offset: 0x28
        u32 BackNormalMapPathOffset : 16;  // offset: 0x2c
        u32 BackMaskMapPathOffset : 16;  // offset: 0x2c
        f32 CullingDistNearStart;  // offset: 0x30
        f32 CullingDistNearEnd;  // offset: 0x34
        f32 CullingDistFarStart;  // offset: 0x38
        f32 CullingDistFarEnd;  // offset: 0x3c
        MT_CHAR RTBaseMapPath[64];  // offset: 0x40
        MT_CHAR RTNormalMapPath[64];  // offset: 0x80
        MT_CHAR RTMaskMapPath[64];  // offset: 0xc0
        MT_CHAR BackBaseMapPath[64];  // offset: 0x100
        MT_CHAR BackNormalMapPath[64];  // offset: 0x140
        MT_CHAR BackMaskMapPath[64];  // offset: 0x180
    };
public:
    struct E2D_INDEX
    {
    public:
        u32 GeneratorType : 8;  // offset: 0x0
        u32 GeneratorParamOffset : 24;  // offset: 0x0
        u32 ParticleType : 8;  // offset: 0x4
        u32 ParticleParamOffset : 24;  // offset: 0x4
        u32 LifeType : 8;  // offset: 0x8
        u32 LifeParamOffset : 24;  // offset: 0x8
        u32 MoveType : 8;  // offset: 0xc
        u32 MoveParamOffset : 24;  // offset: 0xc
    };
public:
    struct E2D_GENERATOR
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeSetNumParam();
        nEffect::KEYFRAME_INDEX* getKeyframeRangeParam();
    public:
        u32 GroupFlag;  // offset: 0x0
        u32 MaterialFlag;  // offset: 0x4
        u32 ParticleNum;  // offset: 0x8
        s32 RandomNo;  // offset: 0xc
        MtFloat3 Ofs;  // offset: 0x10
        MtRangeU16 WaitFrame;  // offset: 0x1c
        MtRangeU16 SetNum;  // offset: 0x20
        MtRangeU16 LoopNum;  // offset: 0x24
        MtRangeU16 SetFrame;  // offset: 0x28
        MtRangeU16 IntervalFrame;  // offset: 0x2c
        f32 SetFrameDist;  // offset: 0x30
        f32 IntervalFrameDist;  // offset: 0x34
        u32 GeneratorOptionFlag;  // offset: 0x38
        s32 ParentNo;  // offset: 0x3c
        MtRangeF Range[2];  // offset: 0x40
        u32 RangeType : 8;  // offset: 0x50
        u32 RangeDirType : 8;  // offset: 0x50
        u32 RangeOptionFlag : 8;  // offset: 0x50
        u32 Generator0853 : 8;  // offset: 0x50
        u32 RangeDivideNum;  // offset: 0x54
        MtRangeF RangeDirBlendRate;  // offset: 0x58
        u32 KeyframeSetNumParamOffset;  // offset: 0x60
        u32 KeyframeRangeParamOffset;  // offset: 0x64
        MtRangeF Angle;  // offset: 0x68
    };
public:
    struct E2D_PARAM_DRAW
    {
    public:
        u32 ParticleOptionFlag;  // offset: 0x0
        u32 BlendState;  // offset: 0x4
    };
public:
    struct E2D_PARAM_LEVEL_CORRECTION
    {
    public:
        u32 Type;  // offset: 0x0
        s32 Attenuation;  // offset: 0x4
        f32 LevelMin;  // offset: 0x8
        f32 LevelMax;  // offset: 0xc
        MtFloat3 Color;  // offset: 0x10
        u32 KeyframeRangeParamOffset;  // offset: 0x1c
    };
public:
    struct E2D_LIFE_FRAME
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeKeepFrameParam();
    public:
        MtRangeU16 AppearFrame;  // offset: 0x0
        MtRangeU16 KeepFrame;  // offset: 0x4
        MtRangeU16 VanishFrame;  // offset: 0x8
        u32 KeepHoldFlag : 1;  // offset: 0xc
        u32 KeyframeKeepFrameParamOffset : 15;  // offset: 0xc
        u32 KeepHoldFrame : 16;  // offset: 0xc
    };
public:
    struct E2D_MOVE_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
        nEffect::KEYFRAME_INDEX* getKeyframeSpeedParam();
        nEffect::KEYFRAME_INDEX* getKeyframeFallSpeedParam();
    public:
        MtRangeF Rot;  // offset: 0x0
        MtRangeF Speed;  // offset: 0x8
        MtRangeF GravityX;  // offset: 0x10
        MtRangeF GravityY;  // offset: 0x18
        u32 KeyframeRotParamOffset;  // offset: 0x20
        u32 KeyframeSpeedParamOffset;  // offset: 0x24
        u32 KeyframeFallSpeedParamOffset;  // offset: 0x28
        u32 MCommon322c;  // offset: 0x2c
    };
public:
    struct E2D_PARAM_LINE_FIX
    {
    public:
        MtFloat2* getLineOfs();
    public:
        MtRangeF ScaleX;  // offset: 0x0
        MtRangeF ScaleAddX;  // offset: 0x8
        MtRangeF ScaleY;  // offset: 0x10
        MtRangeF ScaleAddY;  // offset: 0x18
        MtRangeF Angle;  // offset: 0x20
        MtRangeF AngleAdd;  // offset: 0x28
        f32 AngleAddCoef;  // offset: 0x30
        u32 AngleAddRandomReverse;  // offset: 0x34
        u32 KeyframeScaleXYParamOffset;  // offset: 0x38
        u32 KeyframeAngleParamOffset;  // offset: 0x3c
    };
public:
    struct E2D_PARAM_LINE_LENGTH
    {
    public:
        MtRangeF Angle;  // offset: 0x0
        MtRangeF AngleAdd;  // offset: 0x8
        MtRangeF Length;  // offset: 0x10
        MtRangeF LengthAdd;  // offset: 0x18
        f32 AngleAddCoef;  // offset: 0x20
        u32 AngleAddRandomReverse;  // offset: 0x24
        u32 KeyframeAngleParamOffset;  // offset: 0x28
        u32 KeyframeLengthParamOffset;  // offset: 0x2c
    };
public:
    struct E2D_PARAM_TEX_SCROLL
    {
    public:
        MtRangeF TexScrollOffsetU;  // offset: 0x0
        MtRangeF TexScrollOffsetV;  // offset: 0x8
        MtRangeF TexScrollSpeedU;  // offset: 0x10
        MtRangeF TexScrollSpeedV;  // offset: 0x18
        f32 TexScrollSpeedCoef;  // offset: 0x20
        f32 ParamTexScroll3224;  // offset: 0x24
        f32 ParamTexScroll3228;  // offset: 0x28
        f32 ParamTexScroll322c;  // offset: 0x2c
        u32 KeyframeTexScrollUParamOffset;  // offset: 0x30
        u32 KeyframeTexScrollVParamOffset;  // offset: 0x34
        u32 KeyframeTexScrollSpeedUParamFlag;  // offset: 0x38
        u32 KeyframeTexScrollSpeedVParamFlag;  // offset: 0x3c
    };
public:
    struct E2D_LIFE_KEYFRAME
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeLifeRateParam();
    public:
        MtRangeU16 VanishFrame;  // offset: 0x0
        u32 KeyframeLifeRateParamOffset;  // offset: 0x4
        u32 LKeyframe3208;  // offset: 0x8
        u32 LKeyframe320c;  // offset: 0xc
    };
public:
    struct E2D_LIFE_HIDEFRAME : public rEffect2D::E2D_LIFE_FRAME
    {
    public:
        MtRangeU16 HideFrame;  // offset: 0x10
        u32 LHideFrame3214;  // offset: 0x14
        u32 LHideFrame3218;  // offset: 0x18
        u32 LHideFrame321c;  // offset: 0x1c
    };
public:
    struct E2D_LIFE_CURVEFRAME
    {
    public:
        nEffect::SimpleCurve LifeRateCurve;  // offset: 0x0
        MtRangeU16 LifeRateFrame;  // offset: 0x20
        MtRangeU16 VanishFrame;  // offset: 0x24
        u32 LCurveFrame3228;  // offset: 0x28
        u32 LCurveFrame322c;  // offset: 0x2c
    };
public:
    struct E2D_MOVE_ADD : public rEffect2D::E2D_MOVE_COMMON
    {
    public:
        MtRangeF Acceleration;  // offset: 0x30
        u32 MoveAdd3238;  // offset: 0x38
        u32 MoveAdd323c;  // offset: 0x3c
    };
public:
    struct E2D_MOVE_MUL : public rEffect2D::E2D_MOVE_COMMON
    {
    public:
        MtRangeF SpeedCoef;  // offset: 0x30
        u32 MoveMul3238;  // offset: 0x38
        u32 MoveMul323c;  // offset: 0x3c
    };
public:
    struct E2D_HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u32 Version;  // offset: 0x4
        u32 ParamBuffSize;  // offset: 0x8
        u32 ListNum;  // offset: 0xc
        f32 BaseFps;  // offset: 0x10
        u32 E2DHeader3214;  // offset: 0x14
        u32 E2DHeader3218;  // offset: 0x18
        u32 E2DHeader321c;  // offset: 0x1c
    };
public:
    struct E2D_PARTICLE_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeIntensityParam();
        nEffect::KEYFRAME_INDEX* getKeyframeColorParam();
        nEffect::KEYFRAME_INDEX* getKeyframeScaleParam();
        nEffect::KEYFRAME_INDEX* getKeyframePatNoParam();
        rEffect2D::E2D_PARAM_LEVEL_CORRECTION* getLevelCorrectionParam();
    public:
        rEffect2D::E2D_PARAM_DRAW DrawTargetParam[3];  // offset: 0x0
        u32 ColorFlag : 8;  // offset: 0x18
        u32 ColorCorrectType : 4;  // offset: 0x18
        u32 ShaderType : 4;  // offset: 0x18
        u32 KeyframePatSpeedParamFlag : 1;  // offset: 0x18
        u32 ExtractLinePosFlag : 1;  // offset: 0x18
        u32 PScaleAdaptedFlag : 1;  // offset: 0x18
        u32 PCommon051a : 5;  // offset: 0x18
        u32 PCommon081b : 8;  // offset: 0x18
        f32 ScaleAddCoef;  // offset: 0x1c
        MtColor Color[2];  // offset: 0x20
        MtRangeF Intensity;  // offset: 0x28
        MtRangeF Scale;  // offset: 0x30
        MtRangeF ScaleAdd;  // offset: 0x38
        u32 KeyframeIntensityParamOffset : 16;  // offset: 0x40
        u32 KeyframeColorParamOffset : 16;  // offset: 0x40
        u32 KeyframeScaleParamOffset : 16;  // offset: 0x44
        u32 KeyframePatNoParamOffset : 16;  // offset: 0x44
        u32 LevelCorrectionParamOffset : 16;  // offset: 0x48
        u32 PCommon164a : 16;  // offset: 0x48
        u32 PCommon324c;  // offset: 0x4c
    };
public:
    struct E2D_PARTICLE_MODEL : public rEffect2D::E2D_PARTICLE_COMMON
    {
    public:
        u32 getPartsNo(u32 Random) const;
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
        nEffect::KEYFRAME_INDEX* getKeyframeModelScaleParam();
        rEffect2D::E2D_PARAM_TEX_SCROLL* getTexScrollParam();
    public:
        MT_CHAR ModelPath[64];  // offset: 0x50
        MtRangeF ModelScale[3];  // offset: 0x90
        MtRangeF ModelScaleAdd[3];  // offset: 0xa8
        MtRangeF Rot[3];  // offset: 0xc0
        MtRangeF RotAdd[3];  // offset: 0xd8
        u32 RotOrder : 4;  // offset: 0xf0
        u32 ZClearFlag : 1;  // offset: 0xf0
        u32 RotAddEnable : 1;  // offset: 0xf0
        u32 RotAddRandomReverse : 1;  // offset: 0xf0
        u32 PModel01f0 : 1;  // offset: 0xf0
        u32 PModel08f1 : 8;  // offset: 0xf0
        u32 AnimFlag : 16;  // offset: 0xf0
        f32 AnimSpeed;  // offset: 0xf4
        f32 PartsNoMax;  // offset: 0xf8
        u32 PartsNoMin : 16;  // offset: 0xfc
        u32 PartsNoRange : 16;  // offset: 0xfc
        u32 LightGroupFlag;  // offset: 0x100
        f32 EnvMapPower;  // offset: 0x104
        u32 KeyframeRotParamOffset;  // offset: 0x108
        u32 KeyframeModelScaleParamOffset;  // offset: 0x10c
        s32 DrawRectSize;  // offset: 0x110
        f32 RotAddCoef;  // offset: 0x114
        u32 TexScrollParamOffset;  // offset: 0x118
        u32 PModel3211c;  // offset: 0x11c
    };
public:
    struct E2D_PARTICLE_PAT_COMMON : public rEffect2D::E2D_PARTICLE_COMMON
    {
    public:
        u32 getSeqNo(u32 Random) const;
        u32 getPatNo(u32 Random) const;
    public:
        u32 SeqNoMin : 8;  // offset: 0x50
        u32 SeqNoRange : 8;  // offset: 0x50
        u32 PatNoMin : 8;  // offset: 0x50
        u32 PatNoRange : 8;  // offset: 0x50
        u32 AnimFlag : 16;  // offset: 0x54
        u32 PPatCommon1656 : 16;  // offset: 0x54
        f32 PatSpeed;  // offset: 0x58
        f32 PatNoMax;  // offset: 0x5c
    };
public:
    struct E2D_PARTICLE_LINE : public rEffect2D::E2D_PARTICLE_COMMON
    {
    public:
        void* getParam();
        rEffect2D::E2D_PARAM_LINE_FIX* getLineFixParam();
        rEffect2D::E2D_PARAM_LINE_LENGTH* getLineLengthParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
    public:
        u32 LineType : 4;  // offset: 0x50
        u32 LineDivideNum : 4;  // offset: 0x50
        u32 LineOfsNum : 8;  // offset: 0x50
        u32 ColorPlaceType : 4;  // offset: 0x50
        u32 PLine0452 : 4;  // offset: 0x50
        u32 ColorPlaceNo : 8;  // offset: 0x50
        u32 KeyframePlaceColorParamOffset;  // offset: 0x54
        MtColor PlaceColor[2];  // offset: 0x58
    };
public:
    struct E2D_PARTICLE_PRIM_COMMON : public rEffect2D::E2D_PARTICLE_PAT_COMMON
    {
    public:
        MtPoint PatCenter;  // offset: 0x60
        f32 PPrimCommon3268;  // offset: 0x68
        f32 PPrimCommon326c;  // offset: 0x6c
        MT_CHAR TexturePath[3][64];  // offset: 0x70
        MT_CHAR AnimPath[64];  // offset: 0x130
    };
public:
    struct E2D_PARTICLE_TEXLINE : public rEffect2D::E2D_PARTICLE_PRIM_COMMON
    {
    public:
        void* getParam();
        rEffect2D::E2D_PARAM_LINE_FIX* getLineFixParam();
        rEffect2D::E2D_PARAM_LINE_LENGTH* getLineLengthParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
    public:
        u32 LineType : 4;  // offset: 0x170
        u32 LineDivideNum : 4;  // offset: 0x170
        u32 LineOfsNum : 8;  // offset: 0x170
        u32 ColorPlaceType : 4;  // offset: 0x170
        u32 PTexline04172 : 4;  // offset: 0x170
        u32 ColorPlaceNo : 8;  // offset: 0x170
        u32 KeyframePlaceColorParamOffset;  // offset: 0x174
        MtColor PlaceColor[2];  // offset: 0x178
    };
public:
    struct E2D_PARTICLE_SPRITE : public rEffect2D::E2D_PARTICLE_PRIM_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeScaleXYParam();
        nEffect::KEYFRAME_INDEX* getKeyframeAngleParam();
    public:
        MtRangeF ScaleX;  // offset: 0x170
        MtRangeF ScaleAddX;  // offset: 0x178
        MtRangeF ScaleY;  // offset: 0x180
        MtRangeF ScaleAddY;  // offset: 0x188
        MtRangeF Angle;  // offset: 0x190
        MtRangeF AngleAdd;  // offset: 0x198
        f32 AngleAddCoef;  // offset: 0x1a0
        u32 AngleAddRandomReverse;  // offset: 0x1a4
        u32 KeyframeScaleXYParamOffset;  // offset: 0x1a8
        u32 KeyframeAngleParamOffset;  // offset: 0x1ac
    };
public:
    struct E2D_PARTICLE_POLYLINE : public rEffect2D::E2D_PARTICLE_PRIM_COMMON
    {
    public:
        void* getParam();
        rEffect2D::E2D_PARAM_LINE_FIX* getLineFixParam();
        rEffect2D::E2D_PARAM_LINE_LENGTH* getLineLengthParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
        nEffect::KEYFRAME_INDEX* getKeyframeHeadSizeParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceSizeParam();
    public:
        u32 LineType : 4;  // offset: 0x170
        u32 LineDivideNum : 4;  // offset: 0x170
        u32 LineOfsNum : 8;  // offset: 0x170
        u32 PPolyline16172 : 16;  // offset: 0x170
        u32 ColorPlaceType : 4;  // offset: 0x174
        u32 PPolyline04174 : 4;  // offset: 0x174
        u32 ColorPlaceNo : 8;  // offset: 0x174
        u32 SizePlaceType : 4;  // offset: 0x174
        u32 PPolyline04176 : 4;  // offset: 0x174
        u32 SizePlaceNo : 8;  // offset: 0x174
        MtColor PlaceColor[2];  // offset: 0x178
        MtRangeF HeadSize;  // offset: 0x180
        MtRangeF HeadSizeAdd;  // offset: 0x188
        MtRangeF PlaceSize;  // offset: 0x190
        MtRangeF PlaceSizeAdd;  // offset: 0x198
        u32 KeyframePlaceColorParamOffset;  // offset: 0x1a0
        u32 KeyframeHeadSizeParamOffset;  // offset: 0x1a4
        u32 KeyframePlaceSizeParamOffset;  // offset: 0x1a8
        u32 PPolyline321ac;  // offset: 0x1ac
    };
public:
    static MtDTI* getMyDTIPtr();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void usage();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    rEffect2D();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    f32 getBaseFps() const;
    u32 getListNum() const;
    void setDummyU32(u32);
    void setDummyF32(f32);
    E2D_UNIT* getE2DUnit();
    E2D_INDEX* getE2DIndex(u32 No);
    E2D_INDEX* getE2DIndex(u8*, u32);
    E2D_GENERATOR* getGeneratorParam(E2D_INDEX* pIndex);
    E2D_PARTICLE_COMMON* getParticleParam(E2D_INDEX* pIndex);
    E2D_LIFE_FRAME* getLifeParam(E2D_INDEX* pIndex);
    E2D_MOVE_COMMON* getMoveParam(E2D_INDEX* pIndex);
    ResourceInfo* getResourceInfo(u32 ListNo);
    rRenderTargetTexture* getRTTexture(u32 No);
    rRenderTargetTexture* getRTBaseMap();
    rRenderTargetTexture* getRTNormalMap();
    rRenderTargetTexture* getRTMaskMap();
    u32 getRTTextureNum() const;
    rTexture* getBackTexture(u32 No);
    rTexture* getBackBaseMap();
    rTexture* getBackNormalMap();
    rTexture* getBackMaskMap();
    u32 getResourceSize() const;
protected:
    virtual ~rEffect2D();
    bool allocMemory(u32 ParamBuffSize);
    void setupResourceInfo();
private:
    void constructParam();
    void destructParam();
    void freeMemory();
protected:
    f32 mBaseFps;  // offset: 0x70
    u8* mpParamBuff;  // offset: 0x78
    u32 mParamBuffSize;  // offset: 0x80
    u32 mListNum;  // offset: 0x84
    ResourceInfo* mResourceInfo;  // offset: 0x88
    u32 mResourceInfoNum;  // offset: 0x90
    rRenderTargetTexture* mpRTTexture[3];  // offset: 0x98
    u32 mRTTextureNum;  // offset: 0xb0
    rTexture* mpBackTexture[3];  // offset: 0xb8
public:
    static const u32 DRAW_PRIO_STEP = 64;
    static const u32 DRAW_PRIO_MASK = 63;
    static const u32 DRAW_PRIO_MAX = 32704;
    static MyDTI DTI;
protected:
    static const u32 E2D_MAGIC = 4469317;
    static const u32 E2D_VERSION;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK9rEffect2D5MyDTI11newInstanceEv at 0x011f1b90-0x011f1c30, code DWARF attributes to no inlined copy
inline rEffect2D::rEffect2D() {
    this->mBaseFps = 0.0f;
    this->mResourceInfoNum = static_cast<u32>(0);
    this->mResourceInfo = static_cast<rEffect2D::ResourceInfo*>(nullptr);
    this->mParamBuffSize = static_cast<u32>(0);
    this->mListNum = static_cast<u32>(0);
    this->mpParamBuff = static_cast<u8*>(nullptr);
    this->mRTTextureNum = static_cast<u32>(0);
    this->mpRTTexture[2] = static_cast<rRenderTargetTexture*>(nullptr);
    this->mpRTTexture[1] = static_cast<rRenderTargetTexture*>(nullptr);
    this->mpRTTexture[0] = static_cast<rRenderTargetTexture*>(nullptr);
    this->mpBackTexture[2] = static_cast<rTexture*>(nullptr);
    this->mpBackTexture[1] = static_cast<rTexture*>(nullptr);
    this->mpBackTexture[0] = static_cast<rTexture*>(nullptr);
    this->::cResource::mAttr = static_cast<u32>(22);
}
