#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtEaseCurve.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "MtPrimitive3D.h"
#include "cResource.h"
#include "nEffect.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtColor;
class MtDTI;
class MtEaseCurve;
struct MtFloat2;
struct MtFloat3;
class MtMatrix;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtRange;
class MtRangeF;
class MtRangeU16;
class MtStream;
class MtString;
class MtUI;
class MtVector3;
class MtVector4;
class cParticleManager;
namespace nEffect { struct KEYFRAME_INDEX; }
namespace nEffect { class SimpleCurve; }
class rEffectAnim;
class rEffectStrip;
class rModel;
class rSoundRequest;
class rTexture;
class rVibration;

// Declarations
class rEffectList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rEffectList : public cResource
{
public:
    enum CULLING_OPTION_FLAG
    {
        CULLING_OPTION_FLAG_BOTH_DIR = 1,
        CULLING_OPTION_FLAG_ANGLE_OVERLAP = 4096,
        CULLING_OPTION_FLAG_DIST = 8192,
        CULLING_OPTION_FLAG_NEAR_CLIP = 16384,
        CULLING_OPTION_FLAG_FAR_CLIP = 32768,
    };
    enum CULLING_FLAG
    {
        CULLING_FLAG_ON = 1,
        CULLING_FLAG_OCCLUSION = 2,
        CULLING_FLAG_PARTICLE = 4,
        CULLING_FLAG_GENERATOR = 64,
        CULLING_FLAG_ANGLE = 128,
    };
    enum CHAIN_OPTION_FLAG
    {
        CHAIN_OPTION_FLAG_NO_MAT_DIR = 1,
        CHAIN_OPTION_FLAG_NO_MAT_BDIR = 2,
        CHAIN_OPTION_FLAG_REF_RANGE_DIR = 4,
        CHAIN_OPTION_FLAG_REF_RANGE_BDIR = 8,
        CHAIN_OPTION_FLAG_FORCE_BLEND = 16,
        CHAIN_OPTION_FLAG_MUL_MAT_BDIR = 32,
        CHAIN_OPTION_FLAG_STRETCH = 64,
        CHAIN_OPTION_FLAG_CLOTH_EXCL_MASK = 64,
    };
    enum CLOTH_WAVE_FLAG
    {
        CLOTH_WAVE_FLAG_CHAIN = 1,
        CLOTH_WAVE_FLAG_VERTEX = 2,
        CLOTH_WAVE_FLAG_ACTIVE = 3,
    };
    enum MODEL_PAT_ANIM_FLAG
    {
        MODEL_PAT_ANIM_TEX0 = 1,
        MODEL_PAT_ANIM_TEX1 = 2,
        MODEL_PAT_ANIM_TEX2 = 4,
        MODEL_PAT_ANIM_TEX3 = 8,
        MODEL_PAT_ANIM_KEYFRAME = 16,
        MODEL_PAT_ANIM_TEX_ALL = 15,
    };
    enum FILTER_OPTION_FLAG
    {
        FILTER_OPTION_FLAG_RATE_COLOR = 1,
        FILTER_OPTION_FLAG_RATE_ALPHA = 2,
        FILTER_OPTION_FLAG_RATE_WIDTH = 4,
    };
    enum LIGHT_ATTR
    {
        LIGHT_ATTR_SH = 2,
        LIGHT_ATTR_PERPIXEL = 8,
        LIGHT_ATTR_SIMPLE = 16,
        LIGHT_ATTR_ALL = 26,
    };
    enum CLOTH_CURVE_OPTION_FLAG
    {
        CLOTH_CURVE_OPTION_FLAG_LENGTH_RATIO = 1,
        CLOTH_CURVE_OPTION_FLAG_VAMP_CURVE = 256,
        CLOTH_CURVE_OPTION_FLAG_VAMP_CORRECT = 512,
        CLOTH_CURVE_OPTION_FLAG_VAMP_INIT = 1024,
    };
    enum GENERATOR_OPTION_FLAG
    {
        GENERATOR_OPTION_FLAG_SYNCHRO_VANISH = 1,
        GENERATOR_OPTION_FLAG_REVIVAL = 2,
        GENERATOR_OPTION_FLAG_VOLUME_FIX = 4,
        GENERATOR_OPTION_FLAG_DIR_BLEND = 8,
        GENERATOR_OPTION_FLAG_KF_SET_NUM_RESET = 512,
        GENERATOR_OPTION_FLAG_LIMITED_RESTART = 4096,
        GENERATOR_OPTION_FLAG_LIFE_CURVE = 134217728,
    };
    enum PARTICLE_OPTION_FLAG
    {
        PARTICLE_OPTION_FLAG_OT_DEPTH = 1,
        PARTICLE_OPTION_FLAG_OT_FIX = 2,
        PARTICLE_OPTION_FLAG_DEPTH_BLEND = 4,
        PARTICLE_OPTION_FLAG_INV_VOLUME = 8,
        PARTICLE_OPTION_FLAG_ALPHA_BLUR = 16,
        PARTICLE_OPTION_FLAG_NO_REDUCTION = 32,
        PARTICLE_OPTION_FLAG_NO_CLIP = 64,
        PARTICLE_OPTION_FLAG_NO_ZTEST = 128,
        PARTICLE_OPTION_FLAG_OT_UNIT = 256,
        PARTICLE_OPTION_FLAG_WMAT_SCALE = 512,
        PARTICLE_OPTION_FLAG_PARALLAX = 1024,
        PARTICLE_OPTION_FLAG_DEPTH_VOLUME = 2048,
        PARTICLE_OPTION_FLAG_NO_FOG = 4096,
        PARTICLE_OPTION_FLAG_NO_TONEMAP = 8192,
        PARTICLE_OPTION_FLAG_BLUR = 16384,
        PARTICLE_OPTION_FLAG_MODEL_ALPHATEST = 32768,
        PARTICLE_OPTION_FLAG_PAT_CENTER = 65536,
        PARTICLE_OPTION_FLAG_EXT_LINE_POS = 131072,
        PARTICLE_OPTION_FLAG_MDLSCL_AFTER = 262144,
        PARTICLE_OPTION_FLAG_EDGE_ALPHA_OFF = 524288,
        PARTICLE_OPTION_FLAG_ROT_LOCAL = 1048576,
        PARTICLE_OPTION_FLAG_ROT_INIT = 2097152,
        PARTICLE_OPTION_FLAG_BACKFACE_CULLING = 4194304,
        PARTICLE_OPTION_FLAG_BOTHFACE_DRAW = 8388608,
        PARTICLE_OPTION_FLAG_MODEL_REFRACT = 16777216,
        PARTICLE_OPTION_FLAG_MODEL_UV_REFRACT = 33554432,
        PARTICLE_OPTION_FLAG_ZWRITE = 67108864,
        PARTICLE_OPTION_FLAG_DEPTH_COMPARE = 134217728,
        PARTICLE_OPTION_FLAG_DISTORTION = 268435456,
        PARTICLE_OPTION_FLAG_ZBLUR = 536870912,
        PARTICLE_OPTION_FLAG_SECTION_ZBLUR = 1073741824,
        PARTICLE_OPTION_FLAG_POINT_FILTER = -2147483648,
        PARTICLE_OPTION_FLAG_STANDARD_MASK = -67076097,
        PARTICLE_OPTION_FLAG_ADDITIONAL_MASK = 67076096,
        PARTICLE_OPTION_FLAG_ROT_MASK = 3407872,
        PARTICLE_OPTION_FLAG_BILLBOARD_MASK = 65536,
        PARTICLE_OPTION_FLAG_LINE_MASK = 131072,
        PARTICLE_OPTION_FLAG_POLYGON_MASK = 15990784,
        PARTICLE_OPTION_FLAG_MODEL_MASK = 53772288,
        PARTICLE_OPTION_FLAG_PRIM_MODEL_MASK = 16515072,
        PARTICLE_OPTION_FLAG_MODEL_UNIT_MASK = 3408384,
        PARTICLE_OPTION_FLAG_MODEL_EXCL_MASK = 1879049216,
        PARTICLE_OPTION_FLAG_NOTEX_EXCL_MASK = 268454928,
        PARTICLE_OPTION_FLAG_GPU_EXCL_MASK = 402672665,
        PARTICLE_OPTION_FLAG_OT_EXCL_MASK = 259,
        PARTICLE_OPTION_FLAG_VL_EXCL_MASK = 1929399320,
        PARTICLE_OPTION_FLAG_LITE_EXCL_MASK = 2064403500,
    };
    enum MOVE_OPTION_FLAG
    {
        MOVE_OPTION_FLAG_COLLISION = 1,
        MOVE_OPTION_FLAG_GRAVITY_NO_SCALE = 2,
        MOVE_OPTION_FLAG_HIGH_ACCRACY = 4,
        MOVE_OPTION_FLAG_ALWAYS_CORRECT = 8,
        MOVE_OPTION_FLAG_ROT_LOCAL = 16,
        MOVE_OPTION_FLAG_ALWAYS_CORRECT_RELEASE = 32,
        MOVE_OPTION_FLAG_LITE_COLLISION = 64,
        MOVE_OPTION_FLAG_FAST = 16777216,
        MOVE_OPTION_FLAG_COLL_EXCL_MASK = 65,
        MOVE_OPTION_FLAG_AC_EXCL_MASK = 40,
        MOVE_OPTION_FLAG_NONE_EXCL_MASK = 62,
        MOVE_OPTION_FLAG_PATH_EXCL_MASK = 40,
        MOVE_OPTION_FLAG_CONST_UPDATE = 44,
    };
    enum RANGE_OPTION_FLAG
    {
        RANGE_OPTION_FLAG_EACH_FRAME = 1,
        RANGE_OPTION_FLAG_COLLISION = 16,
        RANGE_OPTION_FLAG_COLL_NORM = 32,
    };
    enum RELATION_SCALE_TYPE
    {
        RELATION_SCALE_TYPE_FULL = 0,
        RELATION_SCALE_TYPE_OFS = 1,
        RELATION_SCALE_TYPE_NONE = 2,
        RELATION_SCALE_TYPE_NUM = 3,
    };
    enum GENERATOR_TYPE
    {
        GENERATOR_TYPE_NONE = 0,
        GENERATOR_TYPE_SINGLE = 1,
        GENERATOR_TYPE_LOOP = 2,
        GENERATOR_TYPE_NUM = 3,
    };
    enum MOVE_TYPE
    {
        MOVE_TYPE_NONE = 0,
        MOVE_TYPE_ADD = 1,
        MOVE_TYPE_MUL = 2,
        MOVE_TYPE_PATH_STRIP = 3,
        MOVE_TYPE_PATH_CHAIN = 4,
        MOVE_TYPE_PATH_KEYFRAME = 5,
        MOVE_TYPE_PATH_LINE = 6,
        MOVE_TYPE_CUSTOM = 7,
        MOVE_TYPE_SPIN = 8,
        MOVE_TYPE_NUM = 9,
        MOVE_TYPE_ADD_FAST = 9,
        MOVE_TYPE_MUL_FAST = 10,
        MOVE_TYPE_SPIN_FAST = 11,
    };
    enum RANGE_TYPE
    {
        RANGE_TYPE_NONE = 0,
        RANGE_TYPE_X_BOX = 1,
        RANGE_TYPE_Y_BOX = 2,
        RANGE_TYPE_Z_BOX = 3,
        RANGE_TYPE_X_CYLINDER = 4,
        RANGE_TYPE_Y_CYLINDER = 5,
        RANGE_TYPE_Z_CYLINDER = 6,
        RANGE_TYPE_SPHERE = 7,
        RANGE_TYPE_HEMISPHERE = 8,
        RANGE_TYPE_NUM = 9,
    };
    enum RANGE_DISPERSE_TYPE
    {
        RANGE_DISPERSE_TYPE_NONE = 0,
        RANGE_DISPERSE_TYPE_OLD = 1,
        RANGE_DISPERSE_TYPE_SUB = 2,
        RANGE_DISPERSE_TYPE_NUM = 3,
    };
    enum RANGE_DIR_TYPE
    {
        RANGE_DIR_TYPE_NONE = 0,
        RANGE_DIR_TYPE_DIFFUSE = 1,
        RANGE_DIR_TYPE_CONVERGE = 2,
        RANGE_DIR_TYPE_UNIT = 3,
        RANGE_DIR_TYPE_NUM = 4,
    };
    enum BOUNDARY_FLAG
    {
        BOUNDARY_SPHERE = 1,
        BOUNDARY_AABB = 2,
        BOUNDARY_DIST = 4,
    };
    enum PRIM_ROT_OPTION_FLAG
    {
        PRIM_ROT_OPTION_FLAG_ADD_RANDOM_REVERSE = 1,
        PRIM_ROT_OPTION_FLAG_TURN_SUBPOS = 2,
        PRIM_ROT_OPTION_FLAG_ADJUST_SUBPOS_DIST = 4,
        PRIM_ROT_OPTION_FLAG_ADD = 128,
        PRIM_ROT_OPTION_FLAG_MODEL_EXCL_MASK = 4,
    };
    enum CLOTH_OPTION_FLAG
    {
        CLOTH_OPTION_FLAG_ORD_CONST_OFF = 1,
        CLOTH_OPTION_FLAG_REV_CONST_OFF = 2,
        CLOTH_OPTION_FLAG_DIST_CONV = 4,
        CLOTH_OPTION_FLAG_CURVE_RATIO_MODE = 8,
        CLOTH_OPTION_FLAG_CONST_OFF = 3,
    };
    enum COLL_FLAG
    {
        COLL_FLAG_FIN_ANIM_STOP = 1,
        COLL_FLAG_FIN_ROT_STOP = 2,
        COLL_FLAG_FIN_KEEP_HOLD_OFF = 4,
        COLL_FLAG_PATH_CANCEL = 8,
        COLL_FLAG_SPHERE_CORRECT = 16,
        COLL_FLAG_ROT_ATTENUATE = 32,
        COLL_FLAG_LITE = 64,
    };
    enum REACTION_TYPE
    {
        REACTION_TYPE_NONE = 0,
        REACTION_TYPE_CUSTOM_01 = 1,
        REACTION_TYPE_CUSTOM_02 = 2,
        REACTION_TYPE_CUSTOM_03 = 3,
        REACTION_TYPE_CUSTOM_04 = 4,
        REACTION_TYPE_CUSTOM_05 = 5,
        REACTION_TYPE_CUSTOM_06 = 6,
        REACTION_TYPE_CUSTOM_07 = 7,
        REACTION_TYPE_CUSTOM_08 = 8,
        REACTION_TYPE_CUSTOM_09 = 9,
        REACTION_TYPE_CUSTOM_0A = 10,
        REACTION_TYPE_CUSTOM_0B = 11,
        REACTION_TYPE_CUSTOM_0C = 12,
        REACTION_TYPE_CUSTOM_0D = 13,
        REACTION_TYPE_CUSTOM_0E = 14,
        REACTION_TYPE_CUSTOM_0F = 15,
        REACTION_TYPE_NUM = 16,
    };
    enum PATH_RELEASE_TYPE
    {
        PATH_RELEASE_TYPE_NONE = 0,
        PATH_RELEASE_TYPE_WORK_SPEED = 1,
        PATH_RELEASE_TYPE_PATH_SPEED = 2,
        PATH_RELEASE_TYPE_NUM = 3,
    };
    enum PATH_OPTION_FLAG
    {
        PATH_OPTION_FLAG_RELEASE_PATH_END = 1,
        PATH_OPTION_FLAG_KILL_PATH_END = 2,
        PATH_OPTION_FLAG_KEEP_HOLD_OFF_PATH_END = 4,
        PATH_OPTION_FLAG_REACH = 8,
        PATH_OPTION_FLAG_REACH_REVERSE = 16,
        PATH_OPTION_FLAG_REACH_CONTROL = 24,
        PATH_OPTION_FLAG_PATH_END_EXCL_MASK = 3,
        PATH_OPTION_FLAG_REACH_EXCL_MASK = 24,
    };
    enum FORCE_TYPE
    {
        FORCE_TYPE_NONE = 0,
        FORCE_TYPE_BLEND = 1,
        FORCE_TYPE_CUSTOM_02 = 2,
        FORCE_TYPE_CUSTOM_03 = 3,
        FORCE_TYPE_CUSTOM_04 = 4,
        FORCE_TYPE_CUSTOM_05 = 5,
        FORCE_TYPE_CUSTOM_06 = 6,
        FORCE_TYPE_CUSTOM_07 = 7,
        FORCE_TYPE_CUSTOM_08 = 8,
        FORCE_TYPE_CUSTOM_09 = 9,
        FORCE_TYPE_CUSTOM_0A = 10,
        FORCE_TYPE_CUSTOM_0B = 11,
        FORCE_TYPE_CUSTOM_0C = 12,
        FORCE_TYPE_CUSTOM_0D = 13,
        FORCE_TYPE_CUSTOM_0E = 14,
        FORCE_TYPE_CUSTOM_0F = 15,
        FORCE_TYPE_CUSTOM_10 = 16,
        FORCE_TYPE_CUSTOM_11 = 17,
        FORCE_TYPE_CUSTOM_12 = 18,
        FORCE_TYPE_CUSTOM_13 = 19,
        FORCE_TYPE_CUSTOM_14 = 20,
        FORCE_TYPE_CUSTOM_15 = 21,
        FORCE_TYPE_CUSTOM_16 = 22,
        FORCE_TYPE_CUSTOM_17 = 23,
        FORCE_TYPE_CUSTOM_18 = 24,
        FORCE_TYPE_CUSTOM_19 = 25,
        FORCE_TYPE_CUSTOM_1A = 26,
        FORCE_TYPE_CUSTOM_1B = 27,
        FORCE_TYPE_CUSTOM_1C = 28,
        FORCE_TYPE_CUSTOM_1D = 29,
        FORCE_TYPE_CUSTOM_1E = 30,
        FORCE_TYPE_CUSTOM_1F = 31,
        FORCE_TYPE_NUM = 32,
    };
    enum GR_FILTER_OPTION_FLAG
    {
        GR_FILTER_OPTION_FLAG_POS = 1,
        GR_FILTER_OPTION_FLAG_CUTOFF = 2,
        GR_FILTER_OPTION_FLAG_RATE_DECAY = 4,
        GR_FILTER_OPTION_FLAG_AFTER_GAMMA = 8,
        GR_FILTER_OPTION_FLAG_SHADOW = 16,
        GR_FILTER_OPTION_FLAG_GRAY = 32,
    };
    enum CLOTH_TYPE
    {
        CLOTH_TYPE_CHAIN = 0,
        CLOTH_TYPE_CURVE = 1,
        CLOTH_TYPE_ZIGZAG = 2,
        CLOTH_TYPE_STRAIGHT = 3,
        CLOTH_TYPE_NUM = 4,
    };
    enum LINE_TYPE
    {
        LINE_TYPE_FOLLOW = 0,
        LINE_TYPE_FIX = 1,
        LINE_TYPE_FIX_END = 2,
        LINE_TYPE_CHAIN = 3,
        LINE_TYPE_LENGTH = 4,
        LINE_TYPE_CLOTH = 5,
        LINE_TYPE_ZIGZAG = 6,
        LINE_TYPE_COMMON_07 = 7,
        LINE_TYPE_CUSTOM_08 = 8,
        LINE_TYPE_CUSTOM_09 = 9,
        LINE_TYPE_CUSTOM_0A = 10,
        LINE_TYPE_CUSTOM_0B = 11,
        LINE_TYPE_CUSTOM_0C = 12,
        LINE_TYPE_CUSTOM_0D = 13,
        LINE_TYPE_CUSTOM_0E = 14,
        LINE_TYPE_CUSTOM_0F = 15,
        LINE_TYPE_NUM = 16,
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
    enum ADHESION_TYPE
    {
        ADHESION_TYPE_EXTEND = 0,
        ADHESION_TYPE_BEND = 1,
        ADHESION_TYPE_NUM = 2,
    };
    enum ADHESION_OPTION_FLAG
    {
        ADHESION_OPTION_FLAG_ALWAYS_UPDATE = 1,
    };
    enum SERIAL_EFC_TYPE
    {
        SERIAL_EFC_TYPE_NONE = 0,
        SERIAL_EFC_TYPE_FINISH = 1,
        SERIAL_EFC_TYPE_KEEP_HOLD_OFF = 2,
        SERIAL_EFC_TYPE_WAIT_FRAME = 3,
        SERIAL_EFC_TYPE_NUM = 4,
    };
    enum PARTICLE_TYPE
    {
        PARTICLE_TYPE_BILLBOARD = 0,
        PARTICLE_TYPE_POLYLINE = 1,
        PARTICLE_TYPE_POLYGON = 2,
        PARTICLE_TYPE_TEXLINE = 3,
        PARTICLE_TYPE_LINE = 4,
        PARTICLE_TYPE_MODEL = 5,
        PARTICLE_TYPE_PRIM_MODEL = 6,
        PARTICLE_TYPE_LENS_FLARE = 7,
        PARTICLE_TYPE_MASS_BILLBOARD = 8,
        PARTICLE_TYPE_FILTER = 9,
        PARTICLE_TYPE_LIGHT = 10,
        PARTICLE_TYPE_HIT = 11,
        PARTICLE_TYPE_CLOTH_POLYLINE = 12,
        PARTICLE_TYPE_CLOTH_TEXLINE = 13,
        PARTICLE_TYPE_CLOTH_LINE = 14,
        PARTICLE_TYPE_POLYGON_STRIP = 15,
        PARTICLE_TYPE_CUSTOM = 16,
        PARTICLE_TYPE_CLOTH_POLYGON = 17,
        PARTICLE_TYPE_ADHESION = 18,
        PARTICLE_TYPE_BILLBOARD_STRIP = 19,
        PARTICLE_TYPE_SIZE_BILLBOARD = 20,
        PARTICLE_TYPE_LIGHT_SHAFT = 21,
        PARTICLE_TYPE_POINT = 22,
        PARTICLE_TYPE_AXIS_POLYGON = 23,
        PARTICLE_TYPE_FORCE = 24,
        PARTICLE_TYPE_NODE_BILLBOARD = 25,
        PARTICLE_TYPE_TRAIL = 26,
        PARTICLE_TYPE_NUM = 27,
    };
    enum RELATION_TYPE
    {
        RELATION_TYPE_FULL = 0,
        RELATION_TYPE_ROT = 1,
        RELATION_TYPE_POS = 2,
        RELATION_TYPE_NONE = 3,
        RELATION_TYPE_FULL_NO_WMAT_SCALE = 4,
        RELATION_TYPE_ROT_NO_WMAT_SCALE = 5,
        RELATION_TYPE_POS_NO_WMAT_SCALE = 6,
        RELATION_TYPE_INVALID = 7,
        RELATION_TYPE_NUM = 8,
    };
    enum SE_OPTION_FLAG
    {
        SE_OPTION_FLAG_FOLLOW_OFF = 1,
        SE_OPTION_FLAG_SYNCHRO_KEY_OFF = 2,
    };
    enum UNIT_OPTION_FLAG
    {
        UNIT_OPTION_FLAG_DRAW_VIEW = 1,
        UNIT_OPTION_FLAG_BOUNDARY_TYPE = 2,
        UNIT_OPTION_FLAG_BOUNDARY = 4,
        UNIT_OPTION_FLAG_JOINT_FIX = 8,
        UNIT_OPTION_FLAG_COLOR_CONTROL = 16,
        UNIT_OPTION_FLAG_BOUNDARY_LOCAL_SCALE = 32,
        UNIT_OPTION_FLAG_PARAM_ENABLE = 63,
    };
    enum SERIAL_EFC_OPTION_FLAG
    {
        SERIAL_EFC_OPTION_FLAG_PARENT_CANCEL = 1,
    };
    enum GRASS_WIND_TYPE
    {
        GRASS_WIND_TYPE_POINT = 0,
        GRASS_WIND_TYPE_DIR = 1,
        GRASS_WIND_TYPE_LINE = 2,
        GRASS_WIND_TYPE_NUM = 3,
    };
    enum JOINT_OPTION_FLAG
    {
        JOINT_OPTION_FLAG_NONE = 0,
        JOINT_OPTION_FLAG_BILLBOARD = 1,
        JOINT_OPTION_FLAG_BILLBOARD_LOOK = 2,
    };
    enum VIB_REQ_TYPE
    {
        VIB_REQ_TYPE_NONE = 0,
        VIB_REQ_TYPE_DEFAULT = 1,
        VIB_REQ_TYPE_VIEWPORT_POS = 2,
        VIB_REQ_TYPE_VIEWPORT_PARENT = 3,
        VIB_REQ_TYPE_NUM = 4,
    };
    enum VIB_OPTION_FLAG
    {
        VIB_OPTION_FLAG_SYNCHRO_STOP = 1,
    };
    enum LIGHT_TYPE
    {
        LIGHT_TYPE_POINT = 0,
        LIGHT_TYPE_SPOT = 1,
        LIGHT_TYPE_NUM = 2,
    };
    enum NODE_RANGE_TYPE
    {
        NODE_RANGE_TYPE_BOX = 0,
        NODE_RANGE_TYPE_SPHERE = 1,
        NODE_RANGE_TYPE_NUM = 2,
    };
    enum NODE_OPTION_FLAG
    {
        NODE_OPTION_FLAG_LOOP_START = 1,
        NODE_OPTION_FLAG_PAT_NO_INP = 2,
    };
    enum NODE_INP_TYPE
    {
        NODE_INP_TYPE_BEZIER = 0,
        NODE_INP_TYPE_SPLINE = 1,
        NODE_INP_TYPE_NUM = 2,
    };
    enum PRIM_MODEL_TYPE
    {
        PRIM_MODEL_TYPE_RING = 0,
        PRIM_MODEL_TYPE_TEX_RING = 1,
        PRIM_MODEL_TYPE_SPHERE = 2,
        PRIM_MODEL_TYPE_TEX_SPHERE = 3,
        PRIM_MODEL_TYPE_GRID = 4,
        PRIM_MODEL_TYPE_TEX_GRID = 5,
        PRIM_MODEL_TYPE_NUM = 6,
    };
    enum SPHERE_PROJ_TYPE
    {
        SPHERE_PROJ_TYPE_SPHERE = 0,
        SPHERE_PROJ_TYPE_XZ_PLANE = 1,
        SPHERE_PROJ_TYPE_NUM = 2,
    };
    enum NORM_ATTENUATE_FLAG
    {
        NORM_ATTENUATE_FLAG_ON = 1,
        NORM_ATTENUATE_FLAG_HIDDEN = 2,
        NORM_ATTENUATE_FLAG_REVERSE = 4,
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
    struct EFL_INDEX;
    struct EFL_GENERATOR;
    struct EFL_PARAM_RPATH;
    struct EFL_PARAM_BOUNDARY;
    struct EFL_PARTICLE_COMMON;
    struct EFL_PARAM_CULLING;
    struct EFL_PARAM_LEVEL_CORRECTION;
    struct EFL_LIFE_FRAME;
    struct EFL_MOVE_COMMON;
    struct EFL_PARAM_COLL;
    struct EFL_PARAM_SUB_EFFECT;
    struct EFL_JOINT_INDEX;
    struct EFL_JOINT;
    struct EFL_PARAM_ANGLE_RANGE;
    struct EFL_UNIT;
    struct EFL_PARAM_CHAIN;
    struct EFL_PARAM_CLOTH_CURVE;
    struct EFL_PARAM_CLOTH_STRAIGHT;
    struct EFL_PARAM_CLOTH_ZIGZAG;
    struct EFL_PARTICLE_POLYLINE;
    struct EFL_PARTICLE_PRIM_COMMON;
    struct EFL_PARTICLE_PAT_COMMON;
    struct EFL_PARTICLE_DRAW_COMMON;
    struct EFL_PARAM_CLOTH_CHAIN;
    struct EFL_PARAM_LINE_FIX;
    struct EFL_PARAM_LINE_FIX_END;
    struct EFL_PARAM_LINE_LENGTH;
    struct EFL_PARAM_LINE_ZIGZAG;
    struct EFL_PARAM_TEX_SCROLL;
    struct EFL_PARAM_TEX_SCROLL_BASE;
    struct EFL_PARTICLE_CLOTH_POLYGON;
    struct EFL_PARTICLE_TEXLINE;
    struct EFL_PARTICLE_PRIM_MODEL;
    struct EFL_PARTICLE_RADIAL_BLUR_FILTER;
    struct EFL_PARTICLE_FILTER;
    struct EFL_PARTICLE_COLOR_CORRECT_FILTER;
    struct EFL_PARTICLE_GOD_RAYS_FILTER;
    struct EFL_PARTICLE_BLOOM_FILTER;
    struct EFL_PARTICLE_LIGHT;
    struct EFL_PARTICLE_POLYGON_STRIP;
    struct EFL_PARTICLE_BILLBOARD_STRIP;
    struct EFL_PARTICLE_BILLBOARD;
    struct EFL_PARAM_SHADE_LIGHT;
    struct EFL_PARTICLE_TRAIL;
    struct EFL_PARTICLE_CUSTOM;
    struct EFL_MOVE_PATH_STRIP;
    struct EFL_MOVE_PATH_COMMON;
    struct EFL_MOVE_BASE;
    struct EFL_MOVE_PATH_CHAIN;
    struct EFL_MOVE_PATH_KEYFRAME;
    struct EFL_MOVE_PATH_LINE;
    struct EFL_MOVE_ADD;
    struct EFL_MOVE_MUL;
    struct EFL_MOVE_SPIN;
    struct EFL_PARTICLE_SIZE_BILLBOARD;
    struct EFL_PARTICLE_POLYGON;
    struct EFL_PARTICLE_ADHESION;
    struct EFL_PARTICLE_AXIS_POLYGON;
    struct EFL_PARTICLE_FORCE;
    struct EFL_PARTICLE_FORCE_COMMON;
    struct EFL_PARTICLE_DIR_FORCE;
    struct EFL_LIFE_KEYFRAME;
    struct EFL_LIFE_HIDEFRAME;
    struct EFL_LIFE_CURVEFRAME;
    struct EFL_PARTICLE_MODEL;
    struct EFL_PARAM_PAT_ANIM;
    struct EFL_PARTICLE_LENS_FLARE;
    struct EFL_PARAM_LENS_FLARE;
    struct EFL_PARTICLE_SPOT_LIGHT;
    struct EFL_PARTICLE_NODE_BILLBOARD;
    struct EFL_PARTICLE_MASS_BILLBOARD;
    struct EFL_PARTICLE_HIT;
    struct EFL_PARTICLE_LIGHT_SHAFT;
    struct EFL_PARTICLE_LINE;
    struct EFL_PARTICLE_POINT;
    struct EFL_HEADER;
public:
    using EFL_INDEX = rEffectList::EFL_INDEX;
    using EFL_GENERATOR = rEffectList::EFL_GENERATOR;
    using EFL_PARAM_RPATH = rEffectList::EFL_PARAM_RPATH;
    using EFL_PARAM_BOUNDARY = rEffectList::EFL_PARAM_BOUNDARY;
    using EFL_PARTICLE_COMMON = rEffectList::EFL_PARTICLE_COMMON;
    using EFL_PARAM_CULLING = rEffectList::EFL_PARAM_CULLING;
    using EFL_PARAM_LEVEL_CORRECTION = rEffectList::EFL_PARAM_LEVEL_CORRECTION;
    using EFL_LIFE_FRAME = rEffectList::EFL_LIFE_FRAME;
    using EFL_MOVE_COMMON = rEffectList::EFL_MOVE_COMMON;
    using EFL_PARAM_COLL = rEffectList::EFL_PARAM_COLL;
    using EFL_PARAM_SUB_EFFECT = rEffectList::EFL_PARAM_SUB_EFFECT;
    using EFL_JOINT_INDEX = rEffectList::EFL_JOINT_INDEX;
    using EFL_JOINT = rEffectList::EFL_JOINT;
    using EFL_PARAM_ANGLE_RANGE = rEffectList::EFL_PARAM_ANGLE_RANGE;
    using EFL_UNIT = rEffectList::EFL_UNIT;
    using EFL_PARAM_CHAIN = rEffectList::EFL_PARAM_CHAIN;
    using EFL_PARAM_CLOTH_CURVE = rEffectList::EFL_PARAM_CLOTH_CURVE;
    using EFL_PARAM_CLOTH_STRAIGHT = rEffectList::EFL_PARAM_CLOTH_STRAIGHT;
    using EFL_PARAM_CLOTH_ZIGZAG = rEffectList::EFL_PARAM_CLOTH_ZIGZAG;
    using EFL_PARTICLE_POLYLINE = rEffectList::EFL_PARTICLE_POLYLINE;
    using EFL_PARTICLE_PRIM_COMMON = rEffectList::EFL_PARTICLE_PRIM_COMMON;
    using EFL_PARTICLE_PAT_COMMON = rEffectList::EFL_PARTICLE_PAT_COMMON;
    using EFL_PARTICLE_DRAW_COMMON = rEffectList::EFL_PARTICLE_DRAW_COMMON;
    using EFL_PARAM_CLOTH_CHAIN = rEffectList::EFL_PARAM_CLOTH_CHAIN;
    using EFL_PARAM_LINE_FIX = rEffectList::EFL_PARAM_LINE_FIX;
    using EFL_PARAM_LINE_FIX_END = rEffectList::EFL_PARAM_LINE_FIX_END;
    using EFL_PARAM_LINE_LENGTH = rEffectList::EFL_PARAM_LINE_LENGTH;
    using EFL_PARAM_LINE_ZIGZAG = rEffectList::EFL_PARAM_LINE_ZIGZAG;
    using EFL_PARAM_TEX_SCROLL = rEffectList::EFL_PARAM_TEX_SCROLL;
    using EFL_PARAM_TEX_SCROLL_BASE = rEffectList::EFL_PARAM_TEX_SCROLL_BASE;
    using EFL_PARTICLE_CLOTH_POLYGON = rEffectList::EFL_PARTICLE_CLOTH_POLYGON;
    using EFL_PARTICLE_TEXLINE = rEffectList::EFL_PARTICLE_TEXLINE;
    using EFL_PARTICLE_PRIM_MODEL = rEffectList::EFL_PARTICLE_PRIM_MODEL;
    using EFL_PARTICLE_RADIAL_BLUR_FILTER = rEffectList::EFL_PARTICLE_RADIAL_BLUR_FILTER;
    using EFL_PARTICLE_FILTER = rEffectList::EFL_PARTICLE_FILTER;
    using EFL_PARTICLE_COLOR_CORRECT_FILTER = rEffectList::EFL_PARTICLE_COLOR_CORRECT_FILTER;
    using EFL_PARTICLE_GOD_RAYS_FILTER = rEffectList::EFL_PARTICLE_GOD_RAYS_FILTER;
    using EFL_PARTICLE_BLOOM_FILTER = rEffectList::EFL_PARTICLE_BLOOM_FILTER;
    using EFL_PARTICLE_LIGHT = rEffectList::EFL_PARTICLE_LIGHT;
    using EFL_PARTICLE_POLYGON_STRIP = rEffectList::EFL_PARTICLE_POLYGON_STRIP;
    using EFL_PARTICLE_BILLBOARD_STRIP = rEffectList::EFL_PARTICLE_BILLBOARD_STRIP;
    using EFL_PARTICLE_BILLBOARD = rEffectList::EFL_PARTICLE_BILLBOARD;
    using EFL_PARAM_SHADE_LIGHT = rEffectList::EFL_PARAM_SHADE_LIGHT;
    using EFL_PARTICLE_TRAIL = rEffectList::EFL_PARTICLE_TRAIL;
    using EFL_PARTICLE_CUSTOM = rEffectList::EFL_PARTICLE_CUSTOM;
    using EFL_MOVE_PATH_COMMON = rEffectList::EFL_MOVE_PATH_COMMON;
    using EFL_MOVE_BASE = rEffectList::EFL_MOVE_BASE;
    using EFL_MOVE_MUL = rEffectList::EFL_MOVE_MUL;
    using EFL_MOVE_PATH_STRIP = rEffectList::EFL_MOVE_PATH_STRIP;
    using EFL_MOVE_PATH_CHAIN = rEffectList::EFL_MOVE_PATH_CHAIN;
    using EFL_MOVE_PATH_KEYFRAME = rEffectList::EFL_MOVE_PATH_KEYFRAME;
    using EFL_MOVE_ADD = rEffectList::EFL_MOVE_ADD;
    using EFL_MOVE_PATH_LINE = rEffectList::EFL_MOVE_PATH_LINE;
    using EFL_MOVE_SPIN = rEffectList::EFL_MOVE_SPIN;
    using EFL_PARTICLE_SIZE_BILLBOARD = rEffectList::EFL_PARTICLE_SIZE_BILLBOARD;
    using EFL_PARTICLE_POLYGON = rEffectList::EFL_PARTICLE_POLYGON;
    using EFL_PARTICLE_ADHESION = rEffectList::EFL_PARTICLE_ADHESION;
    using EFL_PARTICLE_AXIS_POLYGON = rEffectList::EFL_PARTICLE_AXIS_POLYGON;
    using EFL_PARTICLE_FORCE_COMMON = rEffectList::EFL_PARTICLE_FORCE_COMMON;
    using EFL_PARTICLE_FORCE = rEffectList::EFL_PARTICLE_FORCE;
    using EFL_PARTICLE_DIR_FORCE = rEffectList::EFL_PARTICLE_DIR_FORCE;
    using EFL_LIFE_KEYFRAME = rEffectList::EFL_LIFE_KEYFRAME;
    using EFL_LIFE_HIDEFRAME = rEffectList::EFL_LIFE_HIDEFRAME;
    using EFL_LIFE_CURVEFRAME = rEffectList::EFL_LIFE_CURVEFRAME;
    using EFL_PARAM_PAT_ANIM = rEffectList::EFL_PARAM_PAT_ANIM;
    using EFL_PARTICLE_MODEL = rEffectList::EFL_PARTICLE_MODEL;
    using EFL_PARAM_LENS_FLARE = rEffectList::EFL_PARAM_LENS_FLARE;
    using EFL_PARTICLE_LENS_FLARE = rEffectList::EFL_PARTICLE_LENS_FLARE;
    using EFL_PARTICLE_SPOT_LIGHT = rEffectList::EFL_PARTICLE_SPOT_LIGHT;
    using EFL_PARTICLE_MASS_BILLBOARD = rEffectList::EFL_PARTICLE_MASS_BILLBOARD;
    using EFL_PARTICLE_NODE_BILLBOARD = rEffectList::EFL_PARTICLE_NODE_BILLBOARD;
    using EFL_PARTICLE_HIT = rEffectList::EFL_PARTICLE_HIT;
    using EFL_PARTICLE_LIGHT_SHAFT = rEffectList::EFL_PARTICLE_LIGHT_SHAFT;
    using EFL_PARTICLE_LINE = rEffectList::EFL_PARTICLE_LINE;
    using EFL_PARTICLE_POINT = rEffectList::EFL_PARTICLE_POINT;
    using EFL_HEADER = rEffectList::EFL_HEADER;
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
        // inferred: cParticleManager::getSoundRequest names rEffectList::ResourceInfo::mpSoundRequest
        friend class cParticleManager;
    public:
        enum STATUS
        {
            STATUS_TEX_CREATE_FAILED = 1,
            STATUS_TEX0_CREATE_FAILED = 1,
            STATUS_TEX1_CREATE_FAILED = 2,
            STATUS_TEX2_CREATE_FAILED = 4,
            STATUS_EAN_CREATE_FAILED = 8,
            STATUS_MOD_CREATE_FAILED = 16,
            STATUS_R_EFS_CREATE_FAILED = 32,
            STATUS_P_EFS_CREATE_FAILED = 64,
            STATUS_B_EFL_CREATE_FAILED = 128,
            STATUS_F_EFL_CREATE_FAILED = 256,
            STATUS_E_VIB_CREATE_FAILED = 512,
            STATUS_SRQ_CREATE_FAILED = 1024,
            STATUS_FRC_CREATE_FAILED = 2048,
            STATUS_NO_EAN_CREATE = 4096,
            STATUS_NO_MOD_CREATE = 8192,
            STATUS_NO_P_EFS_CREATE = 16384,
            STATUS_NO_FRC_CREATE = 32768,
            STATUS_NO_TEX_CREATE = 65536,
            STATUS_ERROR = 1048575,
            STATUS_RTX_CREATE = 16777216,
            STATUS_RTX0_CREATE = 16777216,
            STATUS_RTX1_CREATE = 33554432,
            STATUS_RTX2_CREATE = 67108864,
            STATUS_PTX_CREATE = 268435456,
            STATUS_PTX0_CREATE = 268435456,
            STATUS_PTX1_CREATE = 536870912,
            STATUS_PTX2_CREATE = 1073741824,
        };
    public:
        ResourceInfo();
        ~ResourceInfo();
        static void* operator new(size_t);
        static void* operator new[](size_t s);
        static void operator delete(void*);
        static void operator delete[](void* pObj);
        void releaseResources();
        void createGeneratorResources(rEffectList::EFL_GENERATOR* pGeneratorParam);
        void createParticleResources(rEffectList::EFL_PARTICLE_COMMON* pParticleParam, u32 ParticleType);
        void createMoveResources(rEffectList::EFL_MOVE_COMMON* pMoveParam, u32 MoveType);
        f32 getTextureInvW() const;
        f32 getTextureInvH() const;
        rEffectAnim* getAnim();
        rModel* getModel();
        rTexture* getTexture(u32 No);
        rEffectStrip* getRangeStrip();
        rEffectStrip* getPathStrip();
        rEffectList* getBounceEffect();
        rEffectList* getFinishEffect();
        rVibration* getExtVibration();
        rSoundRequest* getSoundRequest();
        cResource* getForce();
        f32 getFresnelFactor() const;
        f32 getFresnelBias() const;
        f32 getFresnelExponent() const;
        bool checkCreate();
        u32 getTrait() const;
    private:
        void createTexture(MT_CHAR* pPath, u32 No);
        void createAnim(MT_CHAR* pPath);
        void createModel(MT_CHAR* pPath);
        void createRangeStrip(MT_CHAR* pPath);
        void createPathStrip(MT_CHAR* pPath);
        void createBounceEffect(MT_CHAR* pPath);
        void createFinishEffect(MT_CHAR* pPath);
        void createExtVibration(MT_CHAR* pPath);
        void createSoundRequest(MT_CHAR* pPath);
        void createForce(MT_CHAR* pPath);
    private:
        u32 mStatus;  // offset: 0x0
        u32 mTrait;  // offset: 0x4
        rTexture* mpTexture[3];  // offset: 0x8
        rEffectAnim* mpAnim;  // offset: 0x20
        rModel* mpModel;  // offset: 0x28
        rEffectStrip* mpRangeStrip;  // offset: 0x30
        rEffectStrip* mpPathStrip;  // offset: 0x38
        rEffectList* mpBounceEffect;  // offset: 0x40
        rEffectList* mpFinishEffect;  // offset: 0x48
        rVibration* mpExtVibration;  // offset: 0x50
        rSoundRequest* mpSoundRequest;  // offset: 0x58
        cResource* mpForce;  // offset: 0x60
        f32 mFresnelFactor;  // offset: 0x68
        f32 mFresnelBias;  // offset: 0x6c
        f32 mFresnelExponent;  // offset: 0x70
    };
public:
    struct EFL_INDEX
    {
    public:
        u32 JointIndex : 8;  // offset: 0x0
        u32 GeneratorParamOffset : 24;  // offset: 0x0
        u32 ParticleType : 8;  // offset: 0x4
        u32 ParticleParamOffset : 24;  // offset: 0x4
        u32 GeneratorType : 4;  // offset: 0x8
        u32 LifeType : 4;  // offset: 0x8
        u32 LifeParamOffset : 24;  // offset: 0x8
        u32 MoveType : 4;  // offset: 0xc
        u32 ParticleAlternativeFlag : 4;  // offset: 0xc
        u32 MoveParamOffset : 24;  // offset: 0xc
    };
public:
    struct EFL_GENERATOR
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeSetNumParam();
        nEffect::KEYFRAME_INDEX* getKeyframeRangeParam();
        rEffectList::EFL_PARAM_RPATH* getRangeStripPathParam();
        rEffectList::EFL_PARAM_RPATH* getExtVibrationPathParam();
        rEffectList::EFL_PARAM_RPATH* getSoundRequestPathParam();
        rEffectList::EFL_PARAM_BOUNDARY* getBoundaryParam();
    public:
        u32 GroupFlag;  // offset: 0x0
        u32 MaterialFlag;  // offset: 0x4
        u32 GeneratorOptionFlag;  // offset: 0x8
        u32 ParticleNum : 16;  // offset: 0xc
        u32 UnitEndType : 8;  // offset: 0xc
        u32 RandomNoNum : 8;  // offset: 0xc
        s32 RandomNo[8];  // offset: 0x10
        u32 AxisType : 4;  // offset: 0x30
        u32 LODType : 4;  // offset: 0x30
        u32 VibReqType : 8;  // offset: 0x30
        u32 VibPad : 8;  // offset: 0x30
        u32 VibCamera : 8;  // offset: 0x30
        u32 VibPriority;  // offset: 0x34
        u32 VibListNo : 16;  // offset: 0x38
        u32 VibOptionFlag : 16;  // offset: 0x38
        u32 SeReqNo : 16;  // offset: 0x3c
        u32 SeOptionFlag : 16;  // offset: 0x3c
        MtRangeF ParticleScale;  // offset: 0x40
        MtRangeU16 SetNum;  // offset: 0x48
        MtRangeU16 LoopNum;  // offset: 0x4c
        MtRangeU16 SetFrame;  // offset: 0x50
        MtRangeU16 IntervalFrame;  // offset: 0x54
        f32 SetFrameDist;  // offset: 0x58
        f32 IntervalFrameDist;  // offset: 0x5c
        MtRangeF Range[3];  // offset: 0x60
        u32 RangeType : 8;  // offset: 0x78
        u32 RangeDirType : 8;  // offset: 0x78
        u32 RangeOptionFlag : 8;  // offset: 0x78
        u32 RangeDisperseType : 8;  // offset: 0x78
        u32 RangeStripType : 8;  // offset: 0x7c
        u32 RangeStripFlag : 8;  // offset: 0x7c
        u32 RangeStripPartsNo : 16;  // offset: 0x7c
        MtRangeF RangeDirBlendRate;  // offset: 0x80
        MtRangeF RangeScaleX;  // offset: 0x88
        MtRangeF RangeScaleY;  // offset: 0x90
        MtRangeF RangeScaleZ;  // offset: 0x98
        u32 RangeDivideNum : 16;  // offset: 0xa0
        u32 BoundaryFlag : 4;  // offset: 0xa0
        u32 Generator04a2 : 4;  // offset: 0xa0
        u32 Generator08a3 : 8;  // offset: 0xa0
        f32 RangeCollisionDist;  // offset: 0xa4
        f32 RangeCollCorrectDist;  // offset: 0xa8
        MtRangeU16 RevivalFrame;  // offset: 0xac
        f32 SetNumCorrectCoef;  // offset: 0xb0
        u32 KeyframeSetNumParamOffset : 16;  // offset: 0xb4
        u32 KeyframeRangeParamOffset : 16;  // offset: 0xb4
        u32 RangeStripPathOffset : 16;  // offset: 0xb8
        u32 ExtVibrationPathOffset : 16;  // offset: 0xb8
        u32 SoundRequestPathOffset : 16;  // offset: 0xbc
        u32 BoundaryParamOffset : 16;  // offset: 0xbc
    };
public:
    struct EFL_PARAM_RPATH
    {
    public:
        MT_CHAR ResourcePath[64];  // offset: 0x0
    };
public:
    struct EFL_PARAM_BOUNDARY
    {
    public:
        MtAABB BoundingBox;  // offset: 0x0
        f32 BoundingRadius;  // offset: 0x20
        f32 BoundingDistanceSQ;  // offset: 0x24
        f32 Boundary;  // offset: 0x28
        u32 ParamBoundary322c;  // offset: 0x2c
    };
public:
    struct EFL_PARTICLE_COMMON
    {
    public:
        rEffectList::EFL_PARAM_CULLING* getCullingParam();
        nEffect::KEYFRAME_INDEX* getKeyframeParam(u32 ParamOffset);
        nEffect::KEYFRAME_INDEX* getKeyframeIntensityParam();
        nEffect::KEYFRAME_INDEX* getKeyframeScaleParam();
        u32 getVolumeBlendRateMax() const;
        rEffectList::EFL_PARAM_LEVEL_CORRECTION* getLevelCorrectionParam();
    public:
        u32 DrawMode : 8;  // offset: 0x0
        u32 EntryType : 8;  // offset: 0x0
        u32 CullingFlag : 8;  // offset: 0x0
        u32 BlendState : 8;  // offset: 0x0
        u32 ParticleOptionFlag;  // offset: 0x4
        u32 LightGroupFlag;  // offset: 0x8
        s32 Zofs;  // offset: 0xc
        f32 OtDepthBias;  // offset: 0x10
        u32 FixOtDepth : 16;  // offset: 0x14
        u32 VolumeBlendRate : 8;  // offset: 0x14
        u32 VolumeBlendRateRange : 8;  // offset: 0x14
        u32 ColorCorrectType : 4;  // offset: 0x18
        u32 GpuParticleType : 4;  // offset: 0x18
        u32 ShadeLightType : 4;  // offset: 0x18
        u32 ShaderType : 4;  // offset: 0x18
        u32 SynchroUnitFlag : 1;  // offset: 0x18
        u32 OtDepthBiasFlag : 1;  // offset: 0x18
        u32 SynchroUnitLimitFlag : 1;  // offset: 0x18
        u32 PScaleAdaptedFlag : 1;  // offset: 0x18
        u32 PCommon041a : 4;  // offset: 0x18
        u32 RotOptionFlag : 8;  // offset: 0x18
        f32 ScaleAddCoef;  // offset: 0x1c
        MtRangeF Intensity;  // offset: 0x20
        MtRangeF Scale;  // offset: 0x28
        MtRangeF ScaleAdd;  // offset: 0x30
        u32 KeyframeIntensityParamOffset : 16;  // offset: 0x38
        u32 KeyframeScaleParamOffset : 16;  // offset: 0x38
        u32 LevelCorrectionParamOffset : 16;  // offset: 0x3c
        u32 CullingParamOffset : 16;  // offset: 0x3c
    };
public:
    struct EFL_PARAM_CULLING
    {
    public:
        u32 CullingFlag : 8;  // offset: 0x0
        u32 CullingRotAxisType : 4;  // offset: 0x0
        u32 CullingRotOrder : 4;  // offset: 0x0
        u32 CullingOptionFlag : 16;  // offset: 0x0
        MtFloat3 CullingRot;  // offset: 0x4
        f32 CullingDistNearStart;  // offset: 0x10
        f32 CullingDistNearEnd;  // offset: 0x14
        f32 CullingDistFarStart;  // offset: 0x18
        f32 CullingDistFarEnd;  // offset: 0x1c
        f32 CullingAngleStart;  // offset: 0x20
        f32 CullingAngleEnd;  // offset: 0x24
        f32 CullingRate;  // offset: 0x28
        f32 OcclusionRadius;  // offset: 0x2c
    };
public:
    struct EFL_PARAM_LEVEL_CORRECTION
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
    struct EFL_LIFE_FRAME
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
    struct EFL_MOVE_COMMON
    {
    public:
        rEffectList::EFL_PARAM_COLL* getCollParam();
    public:
        u32 MoveOptionFlag;  // offset: 0x0
        u32 ForceType : 8;  // offset: 0x4
        u32 RotAxisType : 4;  // offset: 0x4
        u32 RotOrder : 4;  // offset: 0x4
        u32 CollParamOffset : 16;  // offset: 0x4
        MtRangeF ForceRate;  // offset: 0x8
    };
public:
    struct EFL_PARAM_COLL
    {
    public:
        rEffectList::EFL_PARAM_SUB_EFFECT* getBounceEffectParam();
        rEffectList::EFL_PARAM_SUB_EFFECT* getFinishEffectParam();
    public:
        u32 CollType : 8;  // offset: 0x0
        u32 CollFlag : 8;  // offset: 0x0
        u32 CollCancelFrame : 8;  // offset: 0x0
        u32 BounceReactionType : 4;  // offset: 0x0
        u32 FinishReactionType : 4;  // offset: 0x0
        f32 CollRadiusAdd;  // offset: 0x4
        MtRangeF CollRadius;  // offset: 0x8
        MtRangeF BounceRate;  // offset: 0x10
        MtRangeU16 BounceNum;  // offset: 0x18
        u32 BounceEffectParamOffset : 16;  // offset: 0x1c
        u32 FinishEffectParamOffset : 16;  // offset: 0x1c
        f32 HeightOffset;  // offset: 0x20
        u32 ParamColl3224;  // offset: 0x24
        u32 ParamColl3228;  // offset: 0x28
        u32 ParamColl322c;  // offset: 0x2c
    };
public:
    struct EFL_PARAM_SUB_EFFECT
    {
    public:
        MT_CHAR EffectPath[64];  // offset: 0x0
        u32 GroupFlag;  // offset: 0x40
        u32 MaterialFlag;  // offset: 0x44
        u32 AxisType : 4;  // offset: 0x48
        u32 Order : 4;  // offset: 0x48
        u32 SerialEffectType : 4;  // offset: 0x48
        u32 SerialEffectOptionFlag : 4;  // offset: 0x48
        u32 SerialEffectWaitFrame : 16;  // offset: 0x48
        s32 SerialEffectParentListNo;  // offset: 0x4c
    };
public:
    struct EFL_JOINT_INDEX
    {
    public:
        u32 JointParamOffset;  // offset: 0x0
    };
public:
    struct EFL_JOINT
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeScaleParam();
        nEffect::KEYFRAME_INDEX* getKeyframeOfsParam();
        nEffect::KEYFRAME_INDEX* getKeyframeAngleParam();
        rEffectList::EFL_PARAM_ANGLE_RANGE* getAngleRangeParam();
    public:
        u32 JointIndex : 8;  // offset: 0x0
        u32 Order : 4;  // offset: 0x0
        u32 RelationType : 4;  // offset: 0x0
        u32 RelationScaleType : 4;  // offset: 0x0
        u32 SubOrder : 4;  // offset: 0x0
        u32 SubRelationType : 4;  // offset: 0x0
        u32 SubRelationScaleType : 4;  // offset: 0x0
        u32 ParentSymmetry : 1;  // offset: 0x4
        u32 ParentSymmetryScale : 1;  // offset: 0x4
        u32 ConstUpdateFlag : 1;  // offset: 0x4
        u32 MoveConstUpdateFlag : 1;  // offset: 0x4
        u32 SubWmatFlag : 1;  // offset: 0x4
        u32 OfsScaleFlag : 1;  // offset: 0x4
        u32 Joint0204 : 2;  // offset: 0x4
        u32 Joint0805 : 8;  // offset: 0x4
        u32 JointOptionFlag : 16;  // offset: 0x4
        MtRangeF Scale[3];  // offset: 0x8
        MtFloat3 Ofs;  // offset: 0x20
        s32 ParentNo;  // offset: 0x2c
        MtQuaternion Quat;  // offset: 0x30
        MtFloat3 SubOfs;  // offset: 0x40
        s32 SubParentNo;  // offset: 0x4c
        MtQuaternion SubQuat;  // offset: 0x50
        s32 RandomNo;  // offset: 0x60
        MtRangeU16 WaitFrame;  // offset: 0x64
        u32 KeyframeScaleParamOffset : 16;  // offset: 0x68
        u32 KeyframeOfsParamOffset : 16;  // offset: 0x68
        u32 KeyframeAngleParamOffset : 16;  // offset: 0x6c
        u32 AngleRangeParamOffset : 16;  // offset: 0x6c
    };
public:
    struct EFL_PARAM_ANGLE_RANGE
    {
    public:
        MtRangeF Angle[3];  // offset: 0x0
        MtRangeF AngleAdd[3];  // offset: 0x18
        f32 AngleAddCoef;  // offset: 0x30
        s32 AngleRandomNo;  // offset: 0x34
        u32 ParamAngle3238;  // offset: 0x38
        u32 ParamAngle323c;  // offset: 0x3c
    };
public:
    struct EFL_UNIT
    {
    public:
        rEffectList::EFL_PARAM_BOUNDARY* getBoundaryParam();
        rEffectList::EFL_PARAM_SUB_EFFECT* getSerialEffectParam();
    public:
        u32 UnitOptionFlag;  // offset: 0x0
        u32 DrawView : 16;  // offset: 0x4
        u32 BoundaryType : 4;  // offset: 0x4
        u32 BoundaryFlag : 4;  // offset: 0x4
        u32 Unit0807 : 8;  // offset: 0x4
        u32 BoundaryParamOffset : 16;  // offset: 0x8
        u32 SerialEffectParamOffset : 16;  // offset: 0x8
        u32 ColorBlendRate : 16;  // offset: 0xc
        u32 ColorID : 8;  // offset: 0xc
        u32 Unit080f : 8;  // offset: 0xc
    };
public:
    struct EFL_PARAM_CHAIN
    {
    public:
        u32 OptionFlag : 16;  // offset: 0x0
        u32 PreUpdateLoopNum : 16;  // offset: 0x0
        u32 RotAxisType : 4;  // offset: 0x4
        u32 RotOrder : 4;  // offset: 0x4
        u32 BlendRotAxisType : 4;  // offset: 0x4
        u32 BlendRotOrder : 4;  // offset: 0x4
        u32 HoldPosNum : 8;  // offset: 0x4
        u32 ParamChain0807 : 8;  // offset: 0x4
        MtRangeF Length;  // offset: 0x8
        MtRangeF LengthAdd;  // offset: 0x10
        MtRangeF BlendRate;  // offset: 0x18
        MtRangeF Acceleration;  // offset: 0x20
        MtRangeF FrameInf;  // offset: 0x28
        MtRangeF VertexInf;  // offset: 0x30
        MtRangeF Rot[3];  // offset: 0x38
        MtRangeF BlendRot[3];  // offset: 0x50
        MtRangeF ForceRate;  // offset: 0x68
        MtRangeF ForceVertexAttenuateRate;  // offset: 0x70
        f32 StretchScale;  // offset: 0x78
        f32 ShrinkCoef;  // offset: 0x7c
        f32 LengthAddCoef;  // offset: 0x80
        u32 KeyframeLengthParamOffset : 16;  // offset: 0x84
        u32 KeyframeBlendRateParamOffset : 16;  // offset: 0x84
        u32 KeyframeRotParamOffset;  // offset: 0x88
        u32 KeyframeBlendRotParamOffset;  // offset: 0x8c
    };
public:
    struct EFL_PARAM_CLOTH_STRAIGHT
    {
    public:
        MtRangeF SubRange[3];  // offset: 0x0
        u32 SubRangeType;  // offset: 0x18
        u32 SubRangeDivideNum : 16;  // offset: 0x1c
        u32 ClothStraight161e : 16;  // offset: 0x1c
    };
public:
    struct EFL_PARTICLE_DRAW_COMMON : public rEffectList::EFL_PARTICLE_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeColorParam();
        nEffect::KEYFRAME_INDEX* getKeyframePatNoParam();
    public:
        u32 ColorFlag : 8;  // offset: 0x40
        u32 KeyframePatSpeedParamFlag : 1;  // offset: 0x40
        u32 PDrawCommon0741 : 7;  // offset: 0x40
        u32 KeyframeColorParamOffset : 16;  // offset: 0x40
        u32 KeyframePatNoParamOffset : 16;  // offset: 0x44
        u32 PDrawCommon1646 : 16;  // offset: 0x44
        MtColor Color[2];  // offset: 0x48
    };
public:
    struct EFL_PARAM_CLOTH_CHAIN : public rEffectList::EFL_PARAM_CHAIN
    {
    public:
        MtRangeU16 ConstOffFrame;  // offset: 0x90
        MtRangeU16 DistConvFrame;  // offset: 0x94
        MtRangeF DistExpansion;  // offset: 0x98
        MtRangeF SubRange[3];  // offset: 0xa0
        u32 SubRangeType;  // offset: 0xb8
        u32 SubRangeDivideNum : 16;  // offset: 0xbc
        u32 ClothOptionFlag : 8;  // offset: 0xbc
        u32 ClothChain08cf : 8;  // offset: 0xbc
    };
public:
    struct EFL_PARAM_LINE_FIX
    {
    public:
        MtVector3* getLineOfs();
    public:
        MtRangeF ModelScale[3];  // offset: 0x0
        MtRangeF ModelScaleAdd[3];  // offset: 0x18
        MtRangeF Rot[3];  // offset: 0x30
        MtRangeF RotAdd[3];  // offset: 0x48
        u32 RotAxisType : 4;  // offset: 0x60
        u32 RotOrder : 4;  // offset: 0x60
        u32 DirAxisType : 4;  // offset: 0x60
        u32 ParamLineFix0461 : 4;  // offset: 0x60
        u32 ParamLineFix1662 : 16;  // offset: 0x60
        f32 RotAddCoef;  // offset: 0x64
        u32 KeyframeModelScaleParamOffset;  // offset: 0x68
        u32 KeyframeRotParamOffset;  // offset: 0x6c
    };
public:
    struct EFL_PARAM_LINE_FIX_END
    {
    public:
        MtRangeF ReleaseDist;  // offset: 0x0
        u32 ParamLineFixEnd3208;  // offset: 0x8
        u32 ParamLineFixEnd320c;  // offset: 0xc
    };
public:
    struct EFL_PARAM_LINE_LENGTH
    {
    public:
        MtRangeF Rot[3];  // offset: 0x0
        MtRangeF RotAdd[3];  // offset: 0x18
        u32 RotAxisType : 4;  // offset: 0x30
        u32 RotOrder : 4;  // offset: 0x30
        u32 DirAxisType : 4;  // offset: 0x30
        u32 ParamLineFix0431 : 4;  // offset: 0x30
        u32 KeyframeLengthParamOffset : 16;  // offset: 0x30
        f32 RotAddCoef;  // offset: 0x34
        MtRangeF Length;  // offset: 0x38
        MtRangeF LengthAdd;  // offset: 0x40
        f32 LengthAddCoef;  // offset: 0x48
        u32 KeyframeRotParamOffset;  // offset: 0x4c
    };
public:
    struct EFL_PARAM_LINE_ZIGZAG : public rEffectList::EFL_PARAM_LINE_LENGTH
    {
    public:
        MtRangeF VertexAmplitudeX;  // offset: 0x50
        MtRangeF VertexAmplitudeY;  // offset: 0x58
        MtRangeF VertexAmplitudeZ;  // offset: 0x60
        MtRangeU16 VertexUpdateFrame;  // offset: 0x68
        u32 KeyframeModelScaleParamOffset;  // offset: 0x6c
        MtEaseCurve VertexAmpCurve;  // offset: 0x70
        u32 CurveOptionFlag : 16;  // offset: 0x78
        u32 ParamLineZigzag167a : 16;  // offset: 0x78
        u32 ParamLineZigzag327c;  // offset: 0x7c
        MtRangeF ModelScale[3];  // offset: 0x80
        MtRangeF ModelScaleAdd[3];  // offset: 0x98
    };
public:
    struct EFL_PARAM_TEX_SCROLL_BASE
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
    };
public:
    struct EFL_PARTICLE_FILTER : public rEffectList::EFL_PARTICLE_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeColorParam();
    public:
        u32 FilterType : 8;  // offset: 0x40
        u32 ScreenAttenuateFlag : 1;  // offset: 0x40
        u32 DistZAddFlag : 1;  // offset: 0x40
        u32 OcclusionEnable : 1;  // offset: 0x40
        u32 OcclusionWidthEnable : 1;  // offset: 0x40
        u32 PFilter0741 : 4;  // offset: 0x40
        u32 LocalPriority : 16;  // offset: 0x40
        u32 KeyframeColorParamOffset : 16;  // offset: 0x44
        u32 ScreenAttenuateDist : 16;  // offset: 0x44
        f32 ScreenAttenuateRate;  // offset: 0x48
        f32 OcclusionRadius;  // offset: 0x4c
        f32 StartZ;  // offset: 0x50
        f32 EndZ;  // offset: 0x54
        f32 StartZAdd;  // offset: 0x58
        f32 EndZAdd;  // offset: 0x5c
    };
public:
    struct EFL_PARTICLE_COLOR_CORRECT_FILTER : public rEffectList::EFL_PARTICLE_FILTER
    {
    public:
        MtVector3 Factor;  // offset: 0x60
        MtVector3 Gamma;  // offset: 0x70
        u32 CCFColorCorrectType : 8;  // offset: 0x80
        u32 CCFColorCorrectScaleAlpha : 8;  // offset: 0x80
        u32 PColorCorrectFilter0882 : 8;  // offset: 0x80
        u32 PColorCorrectFilter0883 : 8;  // offset: 0x80
        u32 PColorCorrectFilter3284;  // offset: 0x84
        u32 PColorCorrectFilter3288;  // offset: 0x88
        u32 PColorCorrectFilter328c;  // offset: 0x8c
    };
public:
    struct EFL_PARTICLE_GOD_RAYS_FILTER : public rEffectList::EFL_PARTICLE_FILTER
    {
    public:
        f32 MaskRadius;  // offset: 0x60
        f32 MaskWeight;  // offset: 0x64
        f32 Decay;  // offset: 0x68
        f32 Threshold;  // offset: 0x6c
        f32 Gammma;  // offset: 0x70
        f32 ShadowFactor;  // offset: 0x74
        f32 ShadowThreshold;  // offset: 0x78
        f32 DirectionLength;  // offset: 0x7c
        MtVector3 Direction;  // offset: 0x80
        MtVector4 FilterColor;  // offset: 0x90
        u32 GRFilterMode : 4;  // offset: 0xa0
        u32 GRFilterQuality : 4;  // offset: 0xa0
        u32 GRFilterOptionFlag : 8;  // offset: 0xa0
        u32 GRFilterIterativeNum : 8;  // offset: 0xa0
        u32 PGodRaysFilter0893 : 8;  // offset: 0xa0
        u32 PGodRaysFilter3294;  // offset: 0xa4
        f32 OcclusionOffset;  // offset: 0xa8
        f32 OcclusionScale;  // offset: 0xac
    };
public:
    struct EFL_PARTICLE_BLOOM_FILTER : public rEffectList::EFL_PARTICLE_FILTER
    {
    public:
        MtVector4 FilterColor;  // offset: 0x60
        f32 BloomDispersion;  // offset: 0x70
        f32 BloomThreshold;  // offset: 0x74
        u32 BloomConeFilter : 1;  // offset: 0x78
        u32 PBloomFilter0758 : 7;  // offset: 0x78
        u32 PBloomFilter2459 : 24;  // offset: 0x78
        u32 PBloomFilter325c;  // offset: 0x7c
    };
public:
    struct EFL_PARTICLE_LIGHT : public rEffectList::EFL_PARTICLE_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeColorParam();
    public:
        u32 LightAttribute;  // offset: 0x40
        u32 ColorFlag : 8;  // offset: 0x44
        u32 LightType : 4;  // offset: 0x44
        u32 PLight0445 : 4;  // offset: 0x44
        u32 KeyframeColorParamOffset : 16;  // offset: 0x44
        MtColor Color[2];  // offset: 0x48
        MtRangeF AttenuateStart;  // offset: 0x50
        MtRangeF AttenuateStartAdd;  // offset: 0x58
        MtRangeF AttenuateEnd;  // offset: 0x60
        MtRangeF AttenuateEndAdd;  // offset: 0x68
        MtFloat2 LightMask;  // offset: 0x70
        f32 DiffuseFactor;  // offset: 0x78
        u32 RotAxisType : 4;  // offset: 0x7c
        u32 RotOrder : 4;  // offset: 0x7c
        u32 DirAxisType : 4;  // offset: 0x7c
        u32 PLight047d : 4;  // offset: 0x7c
        u32 KeyframeRotParamOffset : 16;  // offset: 0x7c
    };
public:
    struct EFL_PARAM_SHADE_LIGHT
    {
    public:
        MtFloat3 Ofs;  // offset: 0x0
        MtColor Color;  // offset: 0xc
        f32 Range;  // offset: 0x10
        f32 Attenuation;  // offset: 0x14
        u32 KeyframeOfsParamOffset;  // offset: 0x18
        u32 KeyframeColorParamOffset : 16;  // offset: 0x1c
        u32 KeyframeRangeParamOffset : 16;  // offset: 0x1c
    };
public:
    struct EFL_MOVE_BASE : public rEffectList::EFL_MOVE_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
        nEffect::KEYFRAME_INDEX* getKeyframeSpeedParam();
        nEffect::KEYFRAME_INDEX* getKeyframeFallSpeedParam();
    public:
        MtRangeF Rot[3];  // offset: 0x10
        MtRangeF Speed;  // offset: 0x28
        MtRangeF Gravity;  // offset: 0x30
        u32 KeyframeRotParamOffset : 16;  // offset: 0x38
        u32 KeyframeSpeedParamOffset : 16;  // offset: 0x38
        u32 KeyframeFallSpeedParamOffset : 16;  // offset: 0x3c
        u32 MBase163e : 16;  // offset: 0x3c
    };
public:
    struct EFL_MOVE_ADD : public rEffectList::EFL_MOVE_BASE
    {
    public:
        MtRangeF Acceleration;  // offset: 0x40
        MtRangeU16 AlwaysCorrectReleaseFrame;  // offset: 0x48
        u32 MAdd324c;  // offset: 0x4c
    };
public:
    struct EFL_MOVE_MUL : public rEffectList::EFL_MOVE_BASE
    {
    public:
        MtRangeF SpeedCoef;  // offset: 0x40
        MtRangeU16 AlwaysCorrectReleaseFrame;  // offset: 0x48
        u32 MMul324c;  // offset: 0x4c
    };
public:
    struct EFL_MOVE_SPIN : public rEffectList::EFL_MOVE_MUL
    {
    public:
        MtRangeF CircleRot[3];  // offset: 0x50
        MtRangeF CircleRotAdd[3];  // offset: 0x68
        MtVector3 CircleRotAddCoef;  // offset: 0x80
        MtRangeF CircleRadius;  // offset: 0x90
        MtRangeF CircleRadiusAdd;  // offset: 0x98
        f32 CircleRadiusAddCoef;  // offset: 0xa0
        u32 CircleRotAddRandomReverse : 1;  // offset: 0xa4
        u32 CircleRadiusAddRandomReverse : 1;  // offset: 0xa4
        u32 CircleAngleAddRandomReverse : 1;  // offset: 0xa4
        u32 ApplyGeneratorRotation : 1;  // offset: 0xa4
        u32 MSpin04a4 : 4;  // offset: 0xa4
        u32 MSpin08a5 : 8;  // offset: 0xa4
        u32 MSpin08a6 : 8;  // offset: 0xa4
        u32 MSpin08a7 : 8;  // offset: 0xa4
        MtRangeF CircleAngle;  // offset: 0xa8
        MtRangeF CircleAngleAdd;  // offset: 0xb0
        f32 CircleAngleAddCoef;  // offset: 0xb8
        u32 MSpin32bc;  // offset: 0xbc
    };
public:
    struct EFL_PARTICLE_FORCE_COMMON : public rEffectList::EFL_PARTICLE_COMMON
    {
    public:
        MT_CHAR ForcePath[64];  // offset: 0x40
        u32 GrassWindType : 8;  // offset: 0x80
        u32 DelayOfsNum : 8;  // offset: 0x80
        u32 PForceCommon08a2 : 8;  // offset: 0x80
        u32 PForceCommon08a3 : 8;  // offset: 0x80
        u32 GrassWindGroup;  // offset: 0x84
    };
public:
    struct EFL_PARTICLE_DIR_FORCE : public rEffectList::EFL_PARTICLE_FORCE_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
    public:
        u32 RotAxisType : 4;  // offset: 0x88
        u32 RotOrder : 4;  // offset: 0x88
        u32 DirAxisType : 4;  // offset: 0x88
        u32 PDirForce04a9 : 4;  // offset: 0x88
        u32 PDirForce16aa : 16;  // offset: 0x88
        u32 KeyframeRotParamOffset;  // offset: 0x8c
        MtRangeF Rot[3];  // offset: 0x90
        MtRangeF RotAdd[3];  // offset: 0xa8
    };
public:
    struct EFL_LIFE_KEYFRAME
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
    struct EFL_LIFE_HIDEFRAME : public rEffectList::EFL_LIFE_FRAME
    {
    public:
        MtRangeU16 HideFrame;  // offset: 0x10
        u32 LHideFrame3214;  // offset: 0x14
        u32 LHideFrame3218;  // offset: 0x18
        u32 LHideFrame321c;  // offset: 0x1c
    };
public:
    struct EFL_LIFE_CURVEFRAME
    {
    public:
        nEffect::SimpleCurve LifeRateCurve;  // offset: 0x0
        MtRangeU16 LifeRateFrame;  // offset: 0x20
        MtRangeU16 VanishFrame;  // offset: 0x24
        u32 LCurveFrame3228;  // offset: 0x28
        u32 LCurveFrame322c;  // offset: 0x2c
    };
public:
    struct EFL_PARTICLE_MODEL : public rEffectList::EFL_PARTICLE_DRAW_COMMON
    {
    public:
        u32 getPartsNo(u32 Random) const;
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
        nEffect::KEYFRAME_INDEX* getKeyframeModelScaleParam();
        rEffectList::EFL_PARAM_TEX_SCROLL* getTexScrollParam();
        rEffectList::EFL_PARAM_TEX_SCROLL_BASE* getSubTexScrollParam();
        rEffectList::EFL_PARAM_PAT_ANIM* getPatAnimParam();
    public:
        MT_CHAR ModelPath[64];  // offset: 0x50
        MtRangeF ModelScale[3];  // offset: 0x90
        MtRangeF ModelScaleAdd[3];  // offset: 0xa8
        MtVector3 ModelScaleAddCoef;  // offset: 0xc0
        MtRangeF Rot[3];  // offset: 0xd0
        MtRangeF RotAdd[3];  // offset: 0xe8
        u32 RotOrder : 4;  // offset: 0x100
        u32 DirAxisType : 4;  // offset: 0x100
        u32 ModelBillboardType : 4;  // offset: 0x100
        u32 PartsNoMin : 10;  // offset: 0x100
        u32 PartsNoRange : 10;  // offset: 0x100
        f32 PartsNoMax;  // offset: 0x104
        f32 AnimSpeed;  // offset: 0x108
        u32 AnimFlag : 16;  // offset: 0x10c
        u32 RotResetFlag : 4;  // offset: 0x10c
        u32 ShadowCastGroup : 4;  // offset: 0x10c
        u32 ShadowReceiveGroup : 4;  // offset: 0x10c
        u32 ModelZofsFlag : 1;  // offset: 0x10c
        u32 ModelBillboardOrder : 1;  // offset: 0x10c
        u32 ModelBillboardLookAt : 1;  // offset: 0x10c
        u32 ModelScaleAddCoefFlag : 1;  // offset: 0x10c
        f32 ModelZofs;  // offset: 0x110
        f32 EnvMapPower;  // offset: 0x114
        f32 RotAddCoef;  // offset: 0x118
        f32 SubPosDistCoef;  // offset: 0x11c
        s32 TransparentPriorityBias;  // offset: 0x120
        f32 ModelLightBoundaryRadius;  // offset: 0x124
        f32 EdgeSmoothingCoefStart;  // offset: 0x128
        f32 EdgeSmoothingCoefEnd;  // offset: 0x12c
        u32 KeyframeRotParamOffset : 16;  // offset: 0x130
        u32 KeyframeModelScaleParamOffset : 16;  // offset: 0x130
        u32 TexScrollParamOffset : 16;  // offset: 0x134
        u32 SubTexScrollParamOffset : 16;  // offset: 0x134
        u32 PatAnimParamOffset : 16;  // offset: 0x138
        u32 ModelPatAnimFlag : 8;  // offset: 0x138
        u32 SubTexScrollNum : 4;  // offset: 0x138
        u32 TexScrollKeyframe : 4;  // offset: 0x138
        u32 EdgeSmoothingType : 4;  // offset: 0x13c
        u32 PModel0413c : 4;  // offset: 0x13c
        u32 PModel0813d : 8;  // offset: 0x13c
        u32 PModel0813e : 8;  // offset: 0x13c
        u32 PModel0813f : 8;  // offset: 0x13c
    };
public:
    struct EFL_PARAM_PAT_ANIM
    {
    public:
        u32 getSeqNo(u32 Random) const;
        u32 getPatNo(u32 Random) const;
    public:
        MT_CHAR AnimPath[64];  // offset: 0x0
        u32 AnimFlag : 16;  // offset: 0x40
        u32 SeqNoMin : 8;  // offset: 0x40
        u32 SeqNoRange : 8;  // offset: 0x40
        u32 PatNoMin : 16;  // offset: 0x44
        u32 PatNoRange : 16;  // offset: 0x44
        f32 PatSpeed;  // offset: 0x48
        f32 PatNoMax;  // offset: 0x4c
    };
public:
    struct EFL_PARTICLE_LENS_FLARE : public rEffectList::EFL_PARTICLE_COMMON
    {
    public:
        rEffectList::EFL_PARAM_LENS_FLARE* getLensFlareIndex();
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
    public:
        u32 LensFlareNum : 8;  // offset: 0x40
        u32 RotAxisType : 4;  // offset: 0x40
        u32 RotOrder : 4;  // offset: 0x40
        u32 ScreenAttenuateDist : 16;  // offset: 0x40
        u32 KeyframeRotParamOffset : 16;  // offset: 0x44
        u32 PLensFlare0846 : 8;  // offset: 0x44
        u32 PLensFlare0847 : 8;  // offset: 0x44
        MtRangeF Rot[3];  // offset: 0x48
        f32 OcclusionScale;  // offset: 0x60
        f32 IntensityScaleDist;  // offset: 0x64
        f32 IntensityScaleMin;  // offset: 0x68
        f32 IntensityScaleMax;  // offset: 0x6c
        rEffectList::EFL_PARAM_CULLING CullingParam;  // offset: 0x70
        MT_CHAR AnimPath[64];  // offset: 0xa0
        MT_CHAR BaseMapPath[64];  // offset: 0xe0
    };
public:
    struct EFL_PARAM_LENS_FLARE
    {
    public:
        MtPoint getPatCenter() const;
    public:
        u32 SeqNo : 8;  // offset: 0x0
        u32 PatNo : 8;  // offset: 0x0
        u32 AnimFlag : 16;  // offset: 0x0
        MtColor Color;  // offset: 0x4
        u32 PatCenterX : 16;  // offset: 0x8
        u32 PatCenterY : 16;  // offset: 0x8
        u32 OcclusionFactor : 8;  // offset: 0xc
        u32 ParamLensFlare080d : 8;  // offset: 0xc
        u32 ParamLensFlare080e : 8;  // offset: 0xc
        u32 ParamLensFlare080f : 8;  // offset: 0xc
        f32 Scale;  // offset: 0x10
        f32 PlaceRate;  // offset: 0x14
        f32 Angle;  // offset: 0x18
        f32 AngleCoef;  // offset: 0x1c
    };
public:
    struct EFL_PARTICLE_SPOT_LIGHT : public rEffectList::EFL_PARTICLE_LIGHT
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
    public:
        MtRangeF Rot[3];  // offset: 0x80
        MtRangeF RotAdd[3];  // offset: 0x98
        MtRangeF AttenuateCone;  // offset: 0xb0
        MtRangeF AttenuateConeAdd;  // offset: 0xb8
        MtRangeF AttenuateSpread;  // offset: 0xc0
        MtRangeF AttenuateSpreadAdd;  // offset: 0xc8
    };
public:
    struct EFL_PARTICLE_HIT : public rEffectList::EFL_PARTICLE_COMMON
    {
    public:
        MtRangeF HitRadius;  // offset: 0x40
        f32 HitRadiusAdd;  // offset: 0x48
        u32 PHit323c;  // offset: 0x4c
    };
public:
    struct EFL_PARTICLE_LINE : public rEffectList::EFL_PARTICLE_DRAW_COMMON
    {
    public:
        void* getParam();
        rEffectList::EFL_PARAM_CHAIN* getChainParam();
        rEffectList::EFL_PARAM_CLOTH_CHAIN* getClothChainParam();
        rEffectList::EFL_PARAM_LINE_FIX* getLineFixParam();
        rEffectList::EFL_PARAM_LINE_FIX_END* getLineFixEndParam();
        rEffectList::EFL_PARAM_LINE_LENGTH* getLineLengthParam();
        rEffectList::EFL_PARAM_LINE_ZIGZAG* getLineZigzagParam();
        rEffectList::EFL_PARAM_CLOTH_CURVE* getClothCurveParam();
        rEffectList::EFL_PARAM_CLOTH_ZIGZAG* getClothZigzagParam();
        rEffectList::EFL_PARAM_CLOTH_STRAIGHT* getClothStraightParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
    public:
        u32 LineType : 8;  // offset: 0x50
        u32 LineOfsNum : 8;  // offset: 0x50
        u32 ColorPlaceNo : 8;  // offset: 0x50
        u32 ColorPlaceType : 4;  // offset: 0x50
        u32 ClothType : 4;  // offset: 0x50
        u32 LineDivideNum : 4;  // offset: 0x54
        u32 PLine0454 : 4;  // offset: 0x54
        u32 PLine0855 : 8;  // offset: 0x54
        u32 KeyframePlaceColorParamOffset : 16;  // offset: 0x54
        MtColor PlaceColor[2];  // offset: 0x58
    };
public:
    struct EFL_PARTICLE_POINT : public rEffectList::EFL_PARTICLE_DRAW_COMMON
    {
    };
public:
    struct EFL_HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u32 Version;  // offset: 0x4
        u32 ParamBuffSize;  // offset: 0x8
        f32 BaseFps;  // offset: 0xc
        u32 ListNum : 16;  // offset: 0x10
        u32 JointNum : 16;  // offset: 0x10
        u32 UnitGeneratorType : 4;  // offset: 0x14
        u32 UnitMoveType : 4;  // offset: 0x14
        u32 JointShare : 4;  // offset: 0x14
        u32 EFLHeader0415 : 4;  // offset: 0x14
        u32 EFLHeader1616 : 16;  // offset: 0x14
        u32 EFLHeader3218;  // offset: 0x18
        u32 EFLHeader321c;  // offset: 0x1c
        u32 UnitGeneratorParamOffset;  // offset: 0x20
        u32 UnitMoveParamOffset;  // offset: 0x24
        u32 UnitJointParamOffset;  // offset: 0x28
        u32 UnitParamOffset;  // offset: 0x2c
    };
public:
    struct EFL_PARAM_CLOTH_CURVE : public rEffectList::EFL_PARAM_CLOTH_STRAIGHT
    {
    public:
        MtRangeF Rot[3];  // offset: 0x20
        MtRangeF RotAdd[3];  // offset: 0x38
        u32 RotAxisType : 4;  // offset: 0x50
        u32 RotOrder : 4;  // offset: 0x50
        u32 DirAxisType : 4;  // offset: 0x50
        u32 CurveType : 4;  // offset: 0x50
        u32 CurveOptionFlag : 16;  // offset: 0x50
        u32 KeyframeRotParamOffset;  // offset: 0x54
        MtRangeF CurveCoef;  // offset: 0x58
        MtEaseCurve VertexAmpCurve;  // offset: 0x60
        f32 RotAddCoef;  // offset: 0x68
        u32 ParamLineFix326c;  // offset: 0x6c
    };
public:
    struct EFL_PARAM_CLOTH_ZIGZAG : public rEffectList::EFL_PARAM_CLOTH_CURVE
    {
    public:
        MtRangeF VertexAmplitudeX;  // offset: 0x70
        MtRangeF VertexAmplitudeY;  // offset: 0x78
        MtRangeF VertexAmplitudeZ;  // offset: 0x80
        MtRangeU16 VertexUpdateFrame;  // offset: 0x88
        u32 KeyframeModelScaleParamOffset;  // offset: 0x8c
        MtRangeF ModelScale[3];  // offset: 0x90
        MtRangeF ModelScaleAdd[3];  // offset: 0xa8
    };
public:
    struct EFL_PARTICLE_PAT_COMMON : public rEffectList::EFL_PARTICLE_DRAW_COMMON
    {
    public:
        u32 getSeqNo(u32 Random) const;
        u32 getPatNo(u32 Random) const;
    public:
        u32 AnimFlag : 16;  // offset: 0x50
        u32 SeqNoMin : 8;  // offset: 0x50
        u32 SeqNoRange : 8;  // offset: 0x50
        u32 PatNoMin : 16;  // offset: 0x54
        u32 PatNoRange : 16;  // offset: 0x54
        f32 PatSpeed;  // offset: 0x58
        f32 PatNoMax;  // offset: 0x5c
    };
public:
    struct EFL_PARAM_TEX_SCROLL : public rEffectList::EFL_PARAM_TEX_SCROLL_BASE
    {
    public:
        u32 KeyframeTexScrollUParamOffset;  // offset: 0x30
        u32 KeyframeTexScrollVParamOffset;  // offset: 0x34
        u32 KeyframeTexScrollSpeedUParamFlag;  // offset: 0x38
        u32 KeyframeTexScrollSpeedVParamFlag;  // offset: 0x3c
    };
public:
    struct EFL_PARTICLE_RADIAL_BLUR_FILTER : public rEffectList::EFL_PARTICLE_FILTER
    {
    public:
        u32 BlendStateType : 8;  // offset: 0x60
        u32 Samples : 8;  // offset: 0x60
        u32 FilterMode : 8;  // offset: 0x60
        u32 FilterOptionFlag : 8;  // offset: 0x60
        f32 BrightThreshold;  // offset: 0x64
        f32 BlurStart;  // offset: 0x68
        f32 BlurWidth;  // offset: 0x6c
        f32 StartW;  // offset: 0x70
        f32 EndW;  // offset: 0x74
        f32 StartH;  // offset: 0x78
        f32 EndH;  // offset: 0x7c
        MtVector4 FilterColor;  // offset: 0x80
        MtFloat2 FilterCenter;  // offset: 0x90
        f32 OcclusionOffset;  // offset: 0x98
        f32 OcclusionScale;  // offset: 0x9c
        MT_CHAR AlphaMapPath[64];  // offset: 0xa0
    };
public:
    struct EFL_MOVE_PATH_COMMON : public rEffectList::EFL_MOVE_BASE
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeReleaseFrameParam();
    public:
        u32 ReleaseType : 8;  // offset: 0x40
        u32 OptionFlag : 8;  // offset: 0x40
        u32 KeyframeReleaseFrameParamOffset : 16;  // offset: 0x40
        MtRangeU16 ReleaseFrame;  // offset: 0x44
        MtRangeF Acceleration;  // offset: 0x48
        MtRangeF Path3DScaleX;  // offset: 0x50
        MtRangeF Path3DScaleY;  // offset: 0x58
        MtRangeF Path3DScaleZ;  // offset: 0x60
        MtRangeF PathLengthScale;  // offset: 0x68
    };
public:
    struct EFL_MOVE_PATH_CHAIN : public rEffectList::EFL_MOVE_PATH_COMMON
    {
    public:
        MtRangeF Distance;  // offset: 0x70
        u32 ChainPosNum : 8;  // offset: 0x78
        u32 MPathChain0879 : 8;  // offset: 0x78
        u32 MPathChain087a : 8;  // offset: 0x78
        u32 MPathChain087b : 8;  // offset: 0x78
        u32 MPathChain327c;  // offset: 0x7c
        rEffectList::EFL_PARAM_CHAIN ChainParam;  // offset: 0x80
    };
public:
    struct EFL_MOVE_PATH_KEYFRAME : public rEffectList::EFL_MOVE_PATH_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeOfsParam();
    public:
        u32 KeyframeOfsParamOffset;  // offset: 0x70
        u32 MPathKeyframe3274;  // offset: 0x74
        u32 MPathKeyframe3278;  // offset: 0x78
        u32 MPathKeyframe327c;  // offset: 0x7c
    };
public:
    struct EFL_MOVE_PATH_LINE : public rEffectList::EFL_MOVE_PATH_COMMON
    {
    public:
        MtRangeF Distance;  // offset: 0x70
        f32 PathLength;  // offset: 0x78
        u32 MPathLine327c;  // offset: 0x7c
    };
public:
    struct EFL_PARTICLE_FORCE : public rEffectList::EFL_PARTICLE_FORCE_COMMON
    {
    public:
        u32 PForce32a8;  // offset: 0x88
        u32 PForce32ac;  // offset: 0x8c
    };
public:
    struct EFL_PARTICLE_MASS_BILLBOARD : public rEffectList::EFL_PARTICLE_PAT_COMMON
    {
    public:
        MT_CHAR AnimPath[64];  // offset: 0x60
        MT_CHAR BaseMapPath[64];  // offset: 0xa0
    };
public:
    struct EFL_PARTICLE_PRIM_COMMON : public rEffectList::EFL_PARTICLE_PAT_COMMON
    {
    public:
        MtPoint PatCenter;  // offset: 0x60
        u32 FresnelFactorFix : 16;  // offset: 0x68
        u32 FresnelBiasFix : 16;  // offset: 0x68
        f32 FresnelExponent;  // offset: 0x6c
        MT_CHAR TexturePath[3][64];  // offset: 0x70
        MT_CHAR AnimPath[64];  // offset: 0x130
    };
public:
    struct EFL_PARTICLE_CLOTH_POLYGON : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
        nEffect::KEYFRAME_INDEX* getKeyframeWidthParam();
    public:
        MtRangeF Rot[3];  // offset: 0x170
        MtRangeF RotAdd[3];  // offset: 0x188
        u32 RotAxisType : 4;  // offset: 0x1a0
        u32 RotOrder : 4;  // offset: 0x1a0
        u32 DirAxisType : 4;  // offset: 0x1a0
        u32 ClothPolygon041a1 : 4;  // offset: 0x1a0
        u32 ChainNum : 8;  // offset: 0x1a0
        u32 ChainVertexNum : 8;  // offset: 0x1a0
        f32 ChainForceAttenuateRate;  // offset: 0x1a4
        u32 WaveFlag : 8;  // offset: 0x1a8
        u32 FoldInterval : 8;  // offset: 0x1a8
        u32 ClothPolygon081aa : 8;  // offset: 0x1a8
        u32 ClothPolygon081ab : 8;  // offset: 0x1a8
        f32 RotAddCoef;  // offset: 0x1ac
        MtRangeF ChainWaveForce;  // offset: 0x1b0
        MtRangeF ChainWaveSpeed;  // offset: 0x1b8
        MtRangeF VertexWaveForce;  // offset: 0x1c0
        MtRangeF VertexWaveSpeed;  // offset: 0x1c8
        MtRangeF FoldDist;  // offset: 0x1d0
        u32 KeyframeRotParamOffset;  // offset: 0x1d8
        u32 KeyframeWidthParamOffset;  // offset: 0x1dc
        MtRangeF Width;  // offset: 0x1e0
        MtRangeF WidthAdd;  // offset: 0x1e8
        rEffectList::EFL_PARAM_CHAIN ChainParam;  // offset: 0x1f0
    };
public:
    struct EFL_PARTICLE_TEXLINE : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        void* getParam();
        rEffectList::EFL_PARAM_CHAIN* getChainParam();
        rEffectList::EFL_PARAM_CLOTH_CHAIN* getClothChainParam();
        rEffectList::EFL_PARAM_LINE_FIX* getLineFixParam();
        rEffectList::EFL_PARAM_LINE_FIX_END* getLineFixEndParam();
        rEffectList::EFL_PARAM_LINE_LENGTH* getLineLengthParam();
        rEffectList::EFL_PARAM_LINE_ZIGZAG* getLineZigzagParam();
        rEffectList::EFL_PARAM_CLOTH_CURVE* getClothCurveParam();
        rEffectList::EFL_PARAM_CLOTH_ZIGZAG* getClothZigzagParam();
        rEffectList::EFL_PARAM_CLOTH_STRAIGHT* getClothStraightParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
    public:
        u32 LineType : 8;  // offset: 0x170
        u32 LineOfsNum : 8;  // offset: 0x170
        u32 ColorPlaceNo : 8;  // offset: 0x170
        u32 ColorPlaceType : 4;  // offset: 0x170
        u32 ClothType : 4;  // offset: 0x170
        u32 LineDivideNum : 4;  // offset: 0x174
        u32 PTexline04174 : 4;  // offset: 0x174
        u32 PTexline08175 : 8;  // offset: 0x174
        u32 KeyframePlaceColorParamOffset : 16;  // offset: 0x174
        MtColor PlaceColor[2];  // offset: 0x178
    };
public:
    struct EFL_PARTICLE_PRIM_MODEL : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
        nEffect::KEYFRAME_INDEX* getKeyframeModelScaleParam();
        nEffect::KEYFRAME_INDEX* getKeyframeUpperRadiusParam();
        nEffect::KEYFRAME_INDEX* getKeyframeLowerRadiusParam();
        nEffect::KEYFRAME_INDEX* getKeyframeUpperHeightParam();
        nEffect::KEYFRAME_INDEX* getKeyframeLowerHeightParam();
        rEffectList::EFL_PARAM_TEX_SCROLL* getTexScrollParam();
    public:
        u32 PrimModelType : 4;  // offset: 0x170
        u32 PrimModelAxis : 4;  // offset: 0x170
        u32 RotOrder : 4;  // offset: 0x170
        u32 DirAxisType : 4;  // offset: 0x170
        u32 ColorPlaceType : 4;  // offset: 0x170
        u32 PPrimModel04172 : 4;  // offset: 0x170
        u32 ModelBillboardType : 4;  // offset: 0x170
        u32 NormAttenuateFlag : 4;  // offset: 0x170
        u32 HoriColorPlaceNo : 16;  // offset: 0x174
        u32 RotResetFlag : 4;  // offset: 0x174
        u32 ModelBillboardOrder : 1;  // offset: 0x174
        u32 ModelBillboardLookAt : 1;  // offset: 0x174
        u32 PPrimModel02176 : 2;  // offset: 0x174
        u32 ProjectionType : 8;  // offset: 0x174
        MtColor PlaceColor[2];  // offset: 0x178
        u32 RotDivNum : 16;  // offset: 0x180
        u32 RotTexDivNum : 16;  // offset: 0x180
        u32 RotDrawStart : 16;  // offset: 0x184
        u32 RotDrawEnd : 16;  // offset: 0x184
        u32 HoriDivNum : 16;  // offset: 0x188
        u32 HoriTexDivNum : 16;  // offset: 0x188
        u32 HoriDrawStart : 16;  // offset: 0x18c
        u32 HoriDrawEnd : 16;  // offset: 0x18c
        MtRangeF ModelScale[3];  // offset: 0x190
        MtRangeF ModelScaleAdd[3];  // offset: 0x1a8
        MtRangeF Rot[3];  // offset: 0x1c0
        MtRangeF RotAdd[3];  // offset: 0x1d8
        MtRangeF Radius[2];  // offset: 0x1f0
        MtRangeF RadiusAdd[2];  // offset: 0x200
        MtRangeF Height[2];  // offset: 0x210
        MtRangeF HeightAdd[2];  // offset: 0x220
        f32 NormAttenuateAngleStart;  // offset: 0x230
        f32 NormAttenuateAngleEnd;  // offset: 0x234
        MtEaseCurve NormAttenuateCurve;  // offset: 0x238
        u32 TexScrollParamOffset;  // offset: 0x240
        u32 KeyframePlaceColorParamOffset;  // offset: 0x244
        u32 KeyframeRotParamOffset;  // offset: 0x248
        u32 KeyframeModelScaleParamOffset;  // offset: 0x24c
        u32 KeyframeUpperRadiusParamOffset : 16;  // offset: 0x250
        u32 KeyframeLowerRadiusParamOffset : 16;  // offset: 0x250
        u32 KeyframeUpperHeightParamOffset : 16;  // offset: 0x254
        u32 KeyframeLowerHeightParamOffset : 16;  // offset: 0x254
        f32 RotAddCoef;  // offset: 0x258
        f32 SubPosDistCoef;  // offset: 0x25c
    };
public:
    struct EFL_PARTICLE_POLYGON_STRIP : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
        nEffect::KEYFRAME_INDEX* getKeyframeWidthParam();
        u32 getBaseDrawBuffSize() const;
    public:
        u32 LineOfsNum : 8;  // offset: 0x170
        u32 ColorPlaceType : 4;  // offset: 0x170
        u32 LayerDivideNum : 4;  // offset: 0x170
        u32 ColorPlaceNo : 8;  // offset: 0x170
        u32 SplineDivideNum : 8;  // offset: 0x170
        u32 RotAxisType : 4;  // offset: 0x174
        u32 RotOrder : 4;  // offset: 0x174
        u32 DirAxisType : 4;  // offset: 0x174
        u32 PPolygonStrip04175 : 4;  // offset: 0x174
        u32 KeyframePlaceColorParamOffset : 16;  // offset: 0x174
        u32 KeyframeRotParamOffset : 16;  // offset: 0x178
        u32 KeyframeWidthParamOffset : 16;  // offset: 0x178
        f32 WidthPlaceRate;  // offset: 0x17c
        MtColor PlaceColor[2];  // offset: 0x180
        f32 RotAddCoef;  // offset: 0x188
        MtRangeU16 FollowFrame;  // offset: 0x18c
        MtRangeF Rot[3];  // offset: 0x190
        MtRangeF RotAdd[3];  // offset: 0x1a8
        MtRangeF Width;  // offset: 0x1c0
        MtRangeF WidthAdd;  // offset: 0x1c8
    };
public:
    struct EFL_PARTICLE_BILLBOARD : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        rEffectList::EFL_PARAM_SHADE_LIGHT* getShadeLightParam();
        nEffect::KEYFRAME_INDEX* getKeyframeAngleParam();
    public:
        MtRangeF Angle;  // offset: 0x170
        MtRangeF AngleAdd;  // offset: 0x178
        MtRangeF AspectRatio;  // offset: 0x180
        MtRangeF AspectRatioAdd;  // offset: 0x188
        f32 AngleAddCoef;  // offset: 0x190
        u32 AngleAddRandomReverse;  // offset: 0x194
        u32 KeyframeAngleParamOffset;  // offset: 0x198
        u32 ShadeLightParamOffset;  // offset: 0x19c
    };
public:
    struct EFL_PARTICLE_TRAIL : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        rEffectList::EFL_PARAM_TEX_SCROLL* getTexScrollParam();
    public:
        u32 TrailMaxOfsNum : 16;  // offset: 0x170
        u32 TrailDivideNum : 4;  // offset: 0x170
        u32 TrailExtensionNum : 4;  // offset: 0x170
        u32 TrailVtxEnableFlag : 1;  // offset: 0x170
        u32 TrailVtxSizeStopFlag : 1;  // offset: 0x170
        u32 TrailVtxLifeStopFlag : 1;  // offset: 0x170
        u32 TrailFollowTailPosFlag : 1;  // offset: 0x170
        u32 PTrail04173 : 4;  // offset: 0x170
        u32 SamplingInterval : 16;  // offset: 0x174
        u32 TexScrollParamOffset : 16;  // offset: 0x174
        u32 PTrail32178;  // offset: 0x178
        u32 PTrail3217c;  // offset: 0x17c
        u32 PTrail32180;  // offset: 0x180
        f32 TrailZigzagScale;  // offset: 0x184
        MtRangeF PatRepeatCoef;  // offset: 0x188
        MtRangeF TrailSize;  // offset: 0x190
        MtRangeF TrailVtxSizeAdd;  // offset: 0x198
        MtRangeU16 TrailVtxSizeWaitFrame;  // offset: 0x1a0
        MtRangeU16 TrailVtxAppearFrame;  // offset: 0x1a4
        MtRangeU16 TrailVtxKeepFrame;  // offset: 0x1a8
        MtRangeU16 TrailVtxVanishFrame;  // offset: 0x1ac
    };
public:
    struct EFL_PARTICLE_CUSTOM : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        u32 CustomType : 8;  // offset: 0x170
        u32 PCustom08161 : 8;  // offset: 0x170
        u32 PCustom16162 : 16;  // offset: 0x170
        u32 CustomFlag;  // offset: 0x174
        MtEaseCurve CustomCurve;  // offset: 0x178
        s32 CustomParamS[8];  // offset: 0x180
        f32 CustomParamF[8];  // offset: 0x1a0
        MtRange CustomRangeParamS[4];  // offset: 0x1c0
        MtRangeF CustomRangeParamF[4];  // offset: 0x1e0
    };
public:
    struct EFL_MOVE_PATH_STRIP : public rEffectList::EFL_MOVE_PATH_COMMON
    {
    public:
        MtRangeF Distance;  // offset: 0x70
        u32 PathStripType : 8;  // offset: 0x78
        u32 PathStripFlag : 8;  // offset: 0x78
        u32 PathStripPartsNo : 16;  // offset: 0x78
        u32 PathCurveDivideNum;  // offset: 0x7c
        MT_CHAR PathStripPath[64];  // offset: 0x80
        MtEaseCurve ReachCurve;  // offset: 0xc0
        MtRangeU16 ReachFrame;  // offset: 0xc8
        u32 MPathStrip32cc;  // offset: 0xcc
    };
public:
    struct EFL_PARTICLE_SIZE_BILLBOARD : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        rEffectList::EFL_PARAM_SHADE_LIGHT* getShadeLightParam();
        nEffect::KEYFRAME_INDEX* getKeyframeAngleParam();
        nEffect::KEYFRAME_INDEX* getKeyframeWidthParam();
        nEffect::KEYFRAME_INDEX* getKeyframeHeightParam();
    public:
        MtRangeF Angle;  // offset: 0x170
        MtRangeF AngleAdd;  // offset: 0x178
        MtRangeF Width;  // offset: 0x180
        MtRangeF WidthAdd;  // offset: 0x188
        MtRangeF Height;  // offset: 0x190
        MtRangeF HeightAdd;  // offset: 0x198
        MtFloat2 PatCenterCoef;  // offset: 0x1a0
        f32 AngleAddCoef;  // offset: 0x1a8
        u32 AngleAddRandomReverse : 1;  // offset: 0x1ac
        u32 PSizeBillboard071ac : 7;  // offset: 0x1ac
        u32 PSizeBillboard081ad : 8;  // offset: 0x1ac
        u32 PSizeBillboard161ae : 16;  // offset: 0x1ac
        u32 ShadeLightParamOffset;  // offset: 0x1b0
        u32 KeyframeAngleParamOffset;  // offset: 0x1b4
        u32 KeyframeWidthParamOffset;  // offset: 0x1b8
        u32 KeyframeHeightParamOffset;  // offset: 0x1bc
    };
public:
    struct EFL_PARTICLE_POLYGON : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
        nEffect::KEYFRAME_INDEX* getKeyframeWidthParam();
        nEffect::KEYFRAME_INDEX* getKeyframeHeightParam();
        nEffect::KEYFRAME_INDEX* getKeyframeModelScaleParam();
        rEffectList::EFL_PARAM_TEX_SCROLL* getTexScrollParam();
    public:
        MtRangeF Rot[3];  // offset: 0x170
        MtRangeF RotAdd[3];  // offset: 0x188
        u32 RotAxisType : 4;  // offset: 0x1a0
        u32 RotOrder : 4;  // offset: 0x1a0
        u32 DirAxisType : 4;  // offset: 0x1a0
        u32 RotResetFlag : 4;  // offset: 0x1a0
        u32 PolygonFixType : 4;  // offset: 0x1a0
        u32 PolygonBillboardType : 4;  // offset: 0x1a0
        u32 PolygonDivideNum : 4;  // offset: 0x1a0
        u32 PolygonBillboardOrder : 1;  // offset: 0x1a0
        u32 PolygonBillboardLookAt : 1;  // offset: 0x1a0
        u32 PPolygon021a3 : 2;  // offset: 0x1a0
        f32 RotAddCoef;  // offset: 0x1a4
        u32 TexScrollParamOffset;  // offset: 0x1a8
        u32 KeyframeRotParamOffset;  // offset: 0x1ac
        u32 KeyframeWidthParamOffset;  // offset: 0x1b0
        u32 KeyframeHeightParamOffset;  // offset: 0x1b4
        u32 PolygonDivideDist;  // offset: 0x1b8
        u32 KeyframeModelScaleParamOffset;  // offset: 0x1bc
        MtRangeF Width;  // offset: 0x1c0
        MtRangeF Height;  // offset: 0x1c8
        MtRangeF WidthAdd;  // offset: 0x1d0
        MtRangeF HeightAdd;  // offset: 0x1d8
        f32 DistortRate[4];  // offset: 0x1e0
    };
public:
    struct EFL_PARTICLE_ADHESION : public rEffectList::EFL_PARTICLE_POLYGON
    {
    public:
        u32 AdhesionType : 8;  // offset: 0x1f0
        u32 AdhesionOptionFlag : 8;  // offset: 0x1f0
        u32 AdhesionEnvMapFactor : 8;  // offset: 0x1f0
        u32 AdhesionSpecularPower : 8;  // offset: 0x1f0
        f32 AdhesionEnvMapIntensity;  // offset: 0x1f4
        MtRangeF AdhesionProjectionDist;  // offset: 0x1f8
    };
public:
    struct EFL_PARTICLE_AXIS_POLYGON : public rEffectList::EFL_PARTICLE_POLYGON
    {
    public:
        MtRangeF ModelScale[3];  // offset: 0x1f0
        MtRangeF ModelScaleAdd[3];  // offset: 0x208
    };
public:
    struct EFL_PARTICLE_NODE_BILLBOARD : public rEffectList::EFL_PARTICLE_MASS_BILLBOARD
    {
    public:
        MtMatrix Param[4];  // offset: 0xe0
        u32 NodeOptionFlag : 16;  // offset: 0x1e0
        u32 NodeLoopNum : 16;  // offset: 0x1e0
        MtRangeU16 NodeFrame;  // offset: 0x1e4
        u32 NodeInpType : 8;  // offset: 0x1e8
        u32 NodeRangeType : 8;  // offset: 0x1e8
        u32 PNodeBillboard081ea : 8;  // offset: 0x1e8
        u32 PNodeBillboard081eb : 8;  // offset: 0x1e8
        u32 PNodeBillboard321ec;  // offset: 0x1ec
        MtRangeF Angle;  // offset: 0x1f0
        u32 PNodeBillboard321f8;  // offset: 0x1f8
        u32 PNodeBillboard321fc;  // offset: 0x1fc
    };
public:
    struct EFL_PARTICLE_LIGHT_SHAFT : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        nEffect::KEYFRAME_INDEX* getKeyframeRotParam();
    public:
        MtRangeF Rot[3];  // offset: 0x170
        MtRangeF RotAdd[3];  // offset: 0x188
        u32 RotAxisType : 4;  // offset: 0x1a0
        u32 RotOrder : 4;  // offset: 0x1a0
        u32 DirAxisType : 4;  // offset: 0x1a0
        u32 RotResetFlag : 4;  // offset: 0x1a0
        u32 PrimNum : 8;  // offset: 0x1a0
        u32 PLightShaft081a3 : 8;  // offset: 0x1a0
        f32 RotAddCoef;  // offset: 0x1a4
        u32 KeyframeRotParamOffset;  // offset: 0x1a8
        f32 AlphaRate;  // offset: 0x1ac
        f32 Dist[2];  // offset: 0x1b0
        f32 Size[2];  // offset: 0x1b8
        MtEaseCurve PrimPlaceCurve;  // offset: 0x1c0
        u32 PLightShaft321c8;  // offset: 0x1c8
        u32 PLightShaft321cc;  // offset: 0x1cc
    };
public:
    struct EFL_PARTICLE_POLYLINE : public rEffectList::EFL_PARTICLE_PRIM_COMMON
    {
    public:
        void* getParam();
        rEffectList::EFL_PARAM_CHAIN* getChainParam();
        rEffectList::EFL_PARAM_CLOTH_CHAIN* getClothChainParam();
        rEffectList::EFL_PARAM_LINE_FIX* getLineFixParam();
        rEffectList::EFL_PARAM_LINE_FIX_END* getLineFixEndParam();
        rEffectList::EFL_PARAM_LINE_LENGTH* getLineLengthParam();
        rEffectList::EFL_PARAM_LINE_ZIGZAG* getLineZigzagParam();
        rEffectList::EFL_PARAM_CLOTH_CURVE* getClothCurveParam();
        rEffectList::EFL_PARAM_CLOTH_ZIGZAG* getClothZigzagParam();
        rEffectList::EFL_PARAM_CLOTH_STRAIGHT* getClothStraightParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
        nEffect::KEYFRAME_INDEX* getKeyframeHeadSizeParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceSizeParam();
        rEffectList::EFL_PARAM_TEX_SCROLL* getTexScrollParam();
    public:
        u32 LineType : 8;  // offset: 0x170
        u32 LineOfsNum : 8;  // offset: 0x170
        u32 ColorPlaceNo : 8;  // offset: 0x170
        u32 SizePlaceNo : 8;  // offset: 0x170
        u32 ColorPlaceType : 4;  // offset: 0x174
        u32 SizePlaceType : 4;  // offset: 0x174
        u32 ClothType : 4;  // offset: 0x174
        u32 LineDivideNum : 4;  // offset: 0x174
        u32 PPolyline16176 : 16;  // offset: 0x174
        MtColor PlaceColor[2];  // offset: 0x178
        MtRangeF HeadSize;  // offset: 0x180
        MtRangeF HeadSizeAdd;  // offset: 0x188
        MtRangeF PlaceSize;  // offset: 0x190
        MtRangeF PlaceSizeAdd;  // offset: 0x198
        MtRangeF PatRepeatCoef;  // offset: 0x1a0
        u32 KeyframePlaceColorParamOffset : 16;  // offset: 0x1a8
        u32 KeyframeHeadSizeParamOffset : 16;  // offset: 0x1a8
        u32 KeyframePlaceSizeParamOffset : 16;  // offset: 0x1ac
        u32 TexScrollParamOffset : 16;  // offset: 0x1ac
    };
public:
    struct EFL_PARTICLE_BILLBOARD_STRIP : public rEffectList::EFL_PARTICLE_BILLBOARD
    {
    public:
        void* getParam();
        rEffectList::EFL_PARAM_CHAIN* getChainParam();
        rEffectList::EFL_PARAM_LINE_FIX* getLineFixParam();
        rEffectList::EFL_PARAM_LINE_FIX_END* getLineFixEndParam();
        rEffectList::EFL_PARAM_LINE_LENGTH* getLineLengthParam();
        rEffectList::EFL_PARAM_LINE_ZIGZAG* getLineZigzagParam();
        nEffect::KEYFRAME_INDEX* getKeyframePlaceColorParam();
    public:
        u32 LineType : 8;  // offset: 0x1a0
        u32 LineOfsNum : 8;  // offset: 0x1a0
        u32 ColorPlaceType : 4;  // offset: 0x1a0
        u32 BillboardStrip041a2 : 4;  // offset: 0x1a0
        u32 ColorPlaceNo : 8;  // offset: 0x1a0
        u32 KeyframePlaceColorParamOffset;  // offset: 0x1a4
        MtColor PlaceColor[2];  // offset: 0x1a8
        u32 VertexInterpolateNum;  // offset: 0x1b0
        u32 BillboardStrip321b4;  // offset: 0x1b4
        u32 BillboardStrip321b8;  // offset: 0x1b8
        u32 BillboardStrip321bc;  // offset: 0x1bc
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
    rEffectList();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    f32 getBaseFps() const;
    u32 getListNum() const;
    u32 getJointNum() const;
    u32 getUnitGeneratorType() const;
    u32 getUnitMoveType() const;
    u32 getResourceInfoNum() const;
    void setDummyU32(u32);
    void setDummyF32(f32);
    void setDummyString(const MtString&);
    void setDummyBool(bool);
    EFL_INDEX* getEFLIndex(u32 No);
    EFL_INDEX* getEFLIndex(u8*, u32);
    EFL_GENERATOR* getGeneratorParam(EFL_INDEX* pIndex);
    EFL_PARTICLE_COMMON* getParticleParam(EFL_INDEX* pIndex);
    EFL_LIFE_FRAME* getLifeParam(EFL_INDEX* pIndex);
    EFL_MOVE_COMMON* getMoveParam(EFL_INDEX* pIndex);
    EFL_GENERATOR* getUnitGeneratorParam();
    EFL_MOVE_COMMON* getUnitMoveParam();
    EFL_JOINT_INDEX* getEFLJointIndex(u32 Index);
    EFL_JOINT* getJointParam(u32 Index);
    EFL_JOINT* getJointParam(EFL_INDEX* pIndex);
    EFL_JOINT* getUnitJointParam();
    bool isJointShare() const;
    EFL_UNIT* getUnitParam();
    ResourceInfo* getResourceInfo(u32 ListNo);
    ResourceInfo* getUnitResourceInfo();
    u32 getResourceSize() const;
    rEffectList* getSerialEffect();
    static bool isCullingParticle(u32 ParticleType);
    static bool isEnableTexScrollV(u32 ParticleType);
protected:
    virtual ~rEffectList();
    bool allocMemory(u32 ParamBuffSize);
    void setupResourceInfo();
    u32 getJointIndexOffset() const;
private:
    void constructParam();
    void destructParam();
    void freeMemory();
    void createSubResource();
    void releaseSubResource();
protected:
    f32 mBaseFps;  // offset: 0x70
    u8* mpParamBuff;  // offset: 0x78
    u32 mParamBuffSize;  // offset: 0x80
    ResourceInfo* mResourceInfo;  // offset: 0x88
    u32 mListNum : 16;  // offset: 0x90
    u32 mJointNum : 16;  // offset: 0x90
    u32 mResourceInfoNum : 16;  // offset: 0x94
    u32 mJointIndexOffset : 16;  // offset: 0x94
    u32 mUnitGeneratorType : 4;  // offset: 0x98
    u32 mUnitMoveType : 4;  // offset: 0x98
    u32 mJointShare : 4;  // offset: 0x98
    u32 mEffectList0419 : 4;  // offset: 0x98
    u32 mEffectList161a : 16;  // offset: 0x98
    rEffectList* mpSerialEffect;  // offset: 0xa0
    u32 mUnitGeneratorParamOffset;  // offset: 0xa8
    u32 mUnitMoveParamOffset;  // offset: 0xac
    u32 mUnitJointParamOffset;  // offset: 0xb0
    u32 mUnitParamOffset;  // offset: 0xb4
public:
    static const u32 CUSTOM_PARAM_NUM = 8;
    static const u32 CUSTOM_RANGE_PARAM_NUM = 4;
    static MyDTI DTI;
protected:
    static const u32 EFL_MAGIC = 4998725;
    static const u32 EFL_VERSION;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK11rEffectList5MyDTI11newInstanceEv at 0x011f3770-0x011f37ff, code DWARF attributes to no inlined copy
inline rEffectList::rEffectList() {
    this->mBaseFps = 0.0f;
    this->mpParamBuff = static_cast<u8*>(nullptr);
    this->mParamBuffSize = static_cast<u32>(0);
    this->mResourceInfo = static_cast<rEffectList::ResourceInfo*>(nullptr);
    this->mUnitGeneratorType = static_cast<u32>(0);
    this->mUnitMoveType = static_cast<u32>(0);
    this->mJointShare = static_cast<u32>(1);
    this->mListNum = static_cast<u32>(0);
    this->mJointNum = static_cast<u32>(0);
    this->mResourceInfoNum = static_cast<u32>(0);
    this->mJointIndexOffset = static_cast<u32>(0);
    this->mUnitJointParamOffset = static_cast<u32>(0);
    this->mUnitParamOffset = static_cast<u32>(0);
    this->mUnitGeneratorParamOffset = static_cast<u32>(0);
    this->mUnitMoveParamOffset = static_cast<u32>(0);
    this->mpSerialEffect = static_cast<rEffectList*>(nullptr);
    this->::cResource::mAttr = static_cast<u32>(22);
}
