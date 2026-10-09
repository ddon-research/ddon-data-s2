#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtCollision.h"
#include "MtCollisionAllocator.h"
#include "MtCollisionMath.h"
#include "MtCollisionUtil.h"
#include "MtDTI.h"
#include "MtGeomAABB.h"
#include "MtGeomCapsule.h"
#include "MtGeomLineSegment.h"
#include "MtGeomOBB.h"
#include "MtGeomSphere.h"
#include "MtGeomTriangle.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "MtSynchronize.h"
#include "cDynamicBVHCollision.h"
#include "cSystem.h"
#include "nCollision.h"
#include "nCollisionNode.h"
#include "rCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtArray;
class MtCapsule;
namespace MtCollisionUtil { class MtLocalBlockAllocator; }
namespace MtCollisionUtil { class MtSoaVector1; }
namespace MtCollisionUtil { class MtSoaVector3; }
namespace MtCollisionUtil { class MtVectorU4; }
class MtColor;
struct MtContact;
class MtCriticalSection;
class MtDTI;
struct MtFloat3;
class MtGeomAABB;
class MtGeomCapsule;
class MtGeomConvex;
class MtGeomLineSegment;
class MtGeomLineSegment4;
class MtGeomOBB;
class MtGeomSphere;
class MtGeomTriangle;
class MtGeometry;
class MtLineSegment;
class MtLineSegment4;
class MtMatrix;
class MtOBB;
class MtObject;
class MtPlane;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtRangeF;
class MtRay;
class MtRayY;
class MtSphere;
class MtString;
class MtTriangle;
class MtVector3;
class MtVector4;
class cDynamicBVHCollision;
class cOmControl;
namespace nCollision { class cCollisionNode; }
namespace nCollision { class cCollisionNodeGroup; }
namespace nCollision { class cObjectBase; }
namespace nCollision { class cScrCommonFilter; }
class rCollision;
class rCollisionHeightField;
class uDynamicSbc;
class uScrollCollisionGeometry;

// Declarations
class sCollision;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using u32 = unsigned int;
namespace nCollision { using OBJ_FILTER_FUNC_GEOMETRY_PASSIVE = bool(MtObject::*)(nCollision::cCollisionNode&, u32, void*); }
namespace nCollision { using OBJ_FILTER_FUNC_NODE_PASSIVE = bool(MtObject::*)(nCollision::cCollisionNode&, void*); }
namespace nCollision { using SBC_HANDLE = u32; }
using u16 = unsigned short;
namespace nCollision { using SBC_HANDLE_HALF = u16; }
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sCollision : public cSystem
{
    // inferred: cOmControl::setActiveAllSbcParts names sCollision::mSbcArray.::MtArray::mpArray
    friend class cOmControl;
    // inferred: uScrollCollisionGeometry::setup names sCollision::mpInstance
    friend class uScrollCollisionGeometry;
public:
    enum CALLBACK_MODE
    {
        PHASE_ENUM = 0,
        PHASE_ENUM_INVERSE = 1,
        PHASE_END = 2,
        PHASE_MOVE = 3,
        PHASE_ENUM_END = 4,
    };
    enum PROFILE_ID
    {
        PROFILE_ID_INTERSECT_LS = 0,
        PROFILE_ID_INTERSECT_SPHERE = 1,
        PROFILE_ID_INTERSECT_CAPSULE = 2,
        PROFILE_ID_INTERSECT_AABB = 3,
        PROFILE_ID_INTERSECT_OBB = 4,
        PROFILE_ID_FIND_LS = 5,
        PROFILE_ID_FIND_LS4 = 6,
        PROFILE_ID_FIND_RAY_Y = 7,
        PROFILE_ID_CAST_SPHERE = 8,
        PROFILE_ID_CAST_CAPSULE = 9,
        PROFILE_ID_CAST_AABB = 10,
        PROFILE_ID_ADJPOS_SPHERE = 11,
        PROFILE_ID_ADJPOS_CAPSULE = 12,
        PROFILE_ID_ADJPOS_SPHERE_CACHED = 13,
        PROFILE_ID_ADJPOS_CAPSULE_CACHED = 14,
        PROFILE_ID_ADJPOS_SPHERE_CAM2 = 15,
        PROFILE_ID_ADJPOS_CAPSULE_CAM2 = 16,
        PROFILE_ID_ADJPOS_SPHERE_CHARA = 17,
        PROFILE_ID_ADJPOS_CAPSULE_CHARA = 18,
        PROFILE_ID_ADJPOS_AABB = 19,
        PROFILE_ID_INTERSECT_LS_MV = 20,
        PROFILE_ID_INTERSECT_SPHERE_MV = 21,
        PROFILE_ID_INTERSECT_CAPSULE_MV = 22,
        PROFILE_ID_INTERSECT_AABB_MV = 23,
        PROFILE_ID_INTERSECT_OBB_MV = 24,
        PROFILE_ID_FIND_LS_MV = 25,
        PROFILE_ID_CAST_SPHERE_MV = 26,
        PROFILE_ID_CAST_CAPSULE_MV = 27,
        PROFILE_ID_ADJPOS_SPHERE_MV = 28,
        PROFILE_ID_ADJPOS_CAPSULE_MV = 29,
        PROFILE_ID_ADJPOS_SPHERE_CAM_MV = 30,
        PROFILE_ID_ADJPOS_SPHERE_CAM2_MV = 31,
        PROFILE_ID_ADJPOS_CAPSULE_CAM2_MV = 32,
        PROFILE_ID_ADJPOS_SPHERE_CHARA_MV = 33,
        PROFILE_ID_ADJPOS_CAPSULE_CHARA_MV = 34,
        PROFILE_ID_ADJUST_CONVEX_SHERE = 35,
        PROFILE_ID_ADJUST_CONVEX_CAPSULE = 36,
        PROFILE_ID_GETAREAPOLY_LS = 37,
        PROFILE_ID_GETAREAPOLY_SPHERE = 38,
        PROFILE_ID_GETAREAPOLY_CAPSULE = 39,
        PROFILE_ID_GETAREAPOLY_AABB = 40,
        PROFILE_ID_GETAREAPOLY_OBB = 41,
        PROFILE_ID_CORRECT_TRAVERSE_LS = 42,
        PROFILE_ID_CORRECT_TRAVERSE_SPHERE = 43,
        PROFILE_ID_CORRECT_TRAVERSE_CAPSULE = 44,
        PROFILE_ID_CORRECT_TRAVERSE_AABB = 45,
        PROFILE_ID_CORRECT_TRAVERSE_OBB = 46,
        PROFILE_ID_FIND_LS_CACHED = 47,
        PROFILE_ID_CAST_SPHERE_CACHED = 48,
        PROFILE_ID_CAST_CAPSULE_CACHED = 49,
        PROFILE_ID_CAST_AABB_CACHED = 50,
        PROFILE_ID_FIND_LS_CACHED_MV = 51,
        PROFILE_ID_CAST_SPHERE_CACHED_MV = 52,
        PROFILE_ID_CAST_CAPSULE_CACHED_MV = 53,
        PROFILE_ID_FIND_LS_ONE_CACHED = 54,
        PROFILE_ID_ORIGINAL = 55,
        PROFILE_ID_ORIGINAL_CACHED = 56,
        PROFILE_ID_ORIGINAL_FIND = 57,
        PROFILE_ID_ORIGINAL_FIND_CACHED = 58,
        PROFILE_GET_SBC_LOCK_INFO_LS = 59,
        PROFILE_GET_SBC_LOCK_INFO_LS_ROTATE = 60,
        PROFILE_GET_SBC_LOCK_INFO_SPHERE = 61,
        PROFILE_GET_SBC_LOCK_INFO_SPHERE_ROTATE = 62,
        PROFILE_REPAIR_SBC_MOVE = 63,
        PROFILE_REPAIR_SBC_MOVE_ROTATE = 64,
        PROFILE_ID_NUM = 65,
    };
    enum COLLIDER_CONTACT_TYPE
    {
        COLLIDER_INTERSECT = 0,
        COLLIDER_CLOSEST = 1,
        COLLIDER_CLOSEST_XZ = 2,
        COLLIDER_FIND = 3,
        COLLIDER_CONTACT = 4,
        COLLIDER_TYPE_MAX = 5,
    };
    enum INFO_WORK_USE_ID
    {
        WORK_ID_LS_VEC_DIR_ORG = 0,
        WORK_ID_LS_VEC_DIR_TRANS = 1,
        WORK_ID_LS_VEC_DIR_NORMALIZE_ORG = 2,
        WORK_ID_LS_VEC_DIR_NORMALIZE_TRANS = 3,
        WORK_ID_LS_VEC_DIR_LEN_ORG = 4,
        WORK_ID_LS_VEC_DIR_LEN_TRANS = 5,
        WORK_ID_LS_VEC_USE_DIR = 0,
        WORK_ID_LS_VEC_USE_DIR_NORMALIZE = 1,
        WORK_ID_LS_VEC_USE_DIR_LEN = 2,
        WORK_ID_SPHERE_VEC_MOVEDPOS = 0,
        WORK_ID_SPHERE_VEC_FIXOFFSET_AABB_MIN = 1,
        WORK_ID_SPHERE_VEC_FIXOFFSET_AABB_MAX = 2,
        WORK_ID_SPHERE_VEC_R4 = 3,
        SCR_INFO_WORK_BUF_NUM = 6,
    };
    enum CONTACT_TYPE
    {
        CONTACT_NONE = 0,
        CONTACT_GROUND = 1,
        CONTACT_SLOPE = 2,
        CONTACT_WALL = 4,
        CONTACT_CEILING = 8,
        CONTACT_EMULATEOFF = 16,
        CONTACT_OBJECT = 32,
        CONTACT_RESERVED = 64,
        CONTACT_FORCEGROUND = 128,
        CONTACT_FORCESLOPE = 256,
        CONTACT_FORCEWALL = 512,
        CONTACT_RE_AXIS_LS_NOT_HIT = 1024,
        CONTACT_AXIS_GROUND = 1048576,
        CONTACT_AXIS_SLOPE = 2097152,
        CONTACT_AXIS_WALL = 4194304,
        CONTACT_AXIS_CEILING = 8388608,
        CONTACT_AXIS_SHIFT = 20,
        CONTACT_AXIS_ALL = 15728640,
        CONTACT_SYSTEM_AXIS_GROUND = 16777216,
        CONTACT_SYSTEM_AXIS_SLOPE = 33554432,
        CONTACT_SYSTEM_AXIS_WALL = 67108864,
        CONTACT_SYSTEM_AXIS_CEILING = 134217728,
        CONTACT_SYSTEM_AXIS_SHIFT = 24,
        CONTACT_SYSTEM_AXIS_ALL = 251658240,
        CONTACT_REPAIR_SBC_LOCK_ENABLE = -2147483648,
        CONTACT_ALL = -2147482689,
    };
    enum CONTACT_MODE
    {
        MODE_AUTO = 0,
        MODE_FORCEGROUND = 1,
        MODE_FORCESLOPE = 2,
        MODE_FORCEWALL = 3,
        MODE_EMULATEOFF = 4,
        MODE_SLOPEFORCEWALL = 5,
        MODE_MASK = 65535,
        MODE_ADJPOS_FALL_SPD_KEEP = 268435456,
        MODE_ANTI_VIBRATE = 536870912,
        MODE_CHARA_JUMP = 1073741824,
        MODE_CHARA = -2147483648,
    };
    enum FILTER
    {
        FILTER_EXTRA_0 = 1,
        FILTER_EXTRA_1 = 2,
        FILTER_EXTRA_2 = 4,
        FILTER_EXTRA_3 = 8,
        FILTER_EXTRA_4 = 16,
        FILTER_EXTRA_5 = 32,
        FILTER_EXTRA_6 = 64,
        FILTER_EXTRA_7 = 128,
        FILTER_00 = 256,
        FILTER_01 = 512,
        FILTER_02 = 1024,
        FILTER_03 = 2048,
        FILTER_04 = 4096,
        FILTER_05 = 8192,
        FILTER_06 = 16384,
        FILTER_07 = 32768,
        FILTER_08 = 65536,
        FILTER_09 = 131072,
        FILTER_10 = 262144,
        FILTER_11 = 524288,
        FILTER_12 = 1048576,
        FILTER_13 = 2097152,
        FILTER_14 = 4194304,
        FILTER_15 = 8388608,
        FILTER_16 = 16777216,
        FILTER_17 = 33554432,
        FILTER_18 = 67108864,
        FILTER_19 = 134217728,
        FILTER_20 = 268435456,
        FILTER_21 = 536870912,
        FILTER_SLOPE = -2147483648,
        FILTER_CANCEL = 1073741824,
        FILTER_ALL = 1073741823,
    };
    enum DEBUG_DISP_TYPE
    {
        DEBUG_DISP_INTERSECT = 0,
        DEBUG_DISP_FIND_INTERSECTION = 1,
        DEBUG_DISP_CAST_CONVEX = 2,
        DEBUG_DISP_ADJUST_POSITION = 3,
        DEBUG_DISP_ADJUST_CONVEX = 4,
        DEBUG_DISP_GET_AREA_POLYGON = 5,
        DEBUG_DISP_CORRECT_TRAVERSE = 6,
        DEBUG_DISP_ORIGINAL_COLLISION = 7,
        DEBUG_DISP_NUM = 8,
    };
    enum UPDATE_SPD_ADJPOS_RET_ID
    {
        UPDATE_SPD_ADJPOS_RET_ID_CONTINUE = 0,
        UPDATE_SPD_ADJPOS_RET_ID_END = 1,
        UPDATE_SPD_ADJPOS_RET_ID_END_UNDO = 2,
        UPDATE_SPD_ADJPOS_RET_ID_END_UNDO_Y = 3,
        UPDATE_SPD_ADJPOS_RET_ID_CONTINUE_UNDO = 4,
        UPDATE_SPD_ADJPOS_RET_ID_NEXT_END = 5,
    };
    enum HIT_TARGET
    {
        HIT_TARGET_ID_MOVE = 1,
        HIT_TARGET_ID_STOP = 2,
        HIT_TARGET_ID_SCR = 4,
        HIT_TARGET_ID_OBJ = 8,
        HIT_TARGET_ID_STOPONLY = 14,
        HIT_TARGET_ID_MOVEONLY = 13,
        HIT_TARGET_ID_ALL = 15,
    };
    enum GEOM_BUF_ID
    {
        GEOM_BUF_ID_ENUMCONTACTPOLYGON_CORE = 0,
        GEOM_BUF_ID_RAY_WITH_CONVEX = 1,
        GEOM_BUF_ID_TEMP = 1,
        GEOM_BUF_ID_GET_AREA_POLYGONS = 2,
        GEOM_BUF_ID_OBJ_CONTACT_MAIN = 3,
        GEOM_BUF_ID_OBJ_CONTACT_TARGET = 4,
        GEOM_BUF_ID_ENUMPARTSCONTACT = 5,
        GEOM_BUF_ID_NUM = 6,
    };
    enum LEAF_CONTACTBIT
    {
        LEAF_CONTACTBIT_NONE = 0,
        LEAF_CONTACTBIT_ONE = 1,
        LEAF_CONTACTBIT_TWO = 2,
        LEAF_CONTACTBIT_ALL = 3,
        LEAF_CONTACTBIT_DUMMY = -1,
    };
    enum
    {
        ORIGINAL_SCR_FIND_WORKVEC_SPEED_ORIGINAL_NORMALIZE = 0,
        ORIGINAL_SCR_FIND_WORKVEC_SPEED_NORMALIZE = 1,
    };
    enum COLLIDER_NODE_ATTR
    {
        COLLIDER_NODE_ATTR_00 = 1,
        COLLIDER_NODE_ATTR_01 = 2,
        COLLIDER_NODE_ATTR_02 = 4,
        COLLIDER_NODE_ATTR_03 = 8,
        COLLIDER_NODE_ATTR_04 = 16,
        COLLIDER_NODE_ATTR_05 = 32,
        COLLIDER_NODE_ATTR_06 = 64,
        COLLIDER_NODE_ATTR_07 = 128,
        COLLIDER_NODE_ATTR_08 = 256,
        COLLIDER_NODE_ATTR_09 = 512,
        COLLIDER_NODE_ATTR_10 = 1024,
        COLLIDER_NODE_ATTR_11 = 2048,
        COLLIDER_NODE_ATTR_12 = 4096,
        COLLIDER_NODE_ATTR_13 = 8192,
        COLLIDER_NODE_ATTR_14 = 16384,
        COLLIDER_NODE_ATTR_15 = 32768,
        COLLIDER_NODE_ATTR_16 = 65536,
        COLLIDER_NODE_ATTR_17 = 131072,
        COLLIDER_NODE_ATTR_18 = 262144,
        COLLIDER_NODE_ATTR_19 = 524288,
        COLLIDER_NODE_ATTR_20 = 1048576,
        COLLIDER_NODE_ATTR_21 = 2097152,
        COLLIDER_NODE_ATTR_22 = 4194304,
        COLLIDER_NODE_ATTR_23 = 8388608,
        COLLIDER_NODE_ATTR_24 = 16777216,
        COLLIDER_NODE_ATTR_25 = 33554432,
        COLLIDER_NODE_ATTR_26 = 67108864,
        COLLIDER_NODE_ATTR_27 = 134217728,
        COLLIDER_NODE_ATTR_28 = 268435456,
        COLLIDER_NODE_ATTR_29 = 536870912,
        COLLIDER_NODE_ATTR_30 = 1073741824,
        COLLIDER_NODE_ATTR_31 = -2147483648,
        COLLIDER_NODE_ATTR_ALL = -1,
    };
    enum COLLIDER_NODE_GROUP
    {
        COLLIDER_NODE_GROUP_00 = 1,
        COLLIDER_NODE_GROUP_01 = 2,
        COLLIDER_NODE_GROUP_02 = 4,
        COLLIDER_NODE_GROUP_03 = 8,
        COLLIDER_NODE_GROUP_04 = 16,
        COLLIDER_NODE_GROUP_05 = 32,
        COLLIDER_NODE_GROUP_06 = 64,
        COLLIDER_NODE_GROUP_07 = 128,
        COLLIDER_NODE_GROUP_08 = 256,
        COLLIDER_NODE_GROUP_09 = 512,
        COLLIDER_NODE_GROUP_10 = 1024,
        COLLIDER_NODE_GROUP_11 = 2048,
        COLLIDER_NODE_GROUP_12 = 4096,
        COLLIDER_NODE_GROUP_13 = 8192,
        COLLIDER_NODE_GROUP_14 = 16384,
        COLLIDER_NODE_GROUP_15 = 32768,
        COLLIDER_NODE_GROUP_16 = 65536,
        COLLIDER_NODE_GROUP_17 = 131072,
        COLLIDER_NODE_GROUP_18 = 262144,
        COLLIDER_NODE_GROUP_19 = 524288,
        COLLIDER_NODE_GROUP_20 = 1048576,
        COLLIDER_NODE_GROUP_21 = 2097152,
        COLLIDER_NODE_GROUP_22 = 4194304,
        COLLIDER_NODE_GROUP_23 = 8388608,
        COLLIDER_NODE_GROUP_24 = 16777216,
        COLLIDER_NODE_GROUP_25 = 33554432,
        COLLIDER_NODE_GROUP_26 = 67108864,
        COLLIDER_NODE_GROUP_27 = 134217728,
        COLLIDER_NODE_GROUP_28 = 268435456,
        COLLIDER_NODE_GROUP_29 = 536870912,
        COLLIDER_NODE_GROUP_30 = 1073741824,
        COLLIDER_NODE_GROUP_31 = -2147483648,
        COLLIDER_NODE_GROUP_ALL = -1,
    };
    enum TYPE
    {
        TYPE_00 = 1,
        TYPE_01 = 2,
        TYPE_02 = 4,
        TYPE_03 = 8,
        TYPE_04 = 16,
        TYPE_05 = 32,
        TYPE_06 = 64,
        TYPE_07 = 128,
        TYPE_08 = 256,
        TYPE_09 = 512,
        TYPE_10 = 1024,
        TYPE_11 = 2048,
        TYPE_12 = 4096,
        TYPE_13 = 8192,
        TYPE_14 = 16384,
        TYPE_15 = 32768,
        TYPE_16 = 65536,
        TYPE_17 = 131072,
        TYPE_18 = 262144,
        TYPE_19 = 524288,
        TYPE_20 = 1048576,
        TYPE_21 = 2097152,
        TYPE_22 = 4194304,
        TYPE_23 = 8388608,
        TYPE_24 = 16777216,
        TYPE_25 = 33554432,
        TYPE_26 = 67108864,
        TYPE_27 = 134217728,
        TYPE_28 = 268435456,
        TYPE_29 = 536870912,
        TYPE_30 = 1073741824,
        TYPE_PHYSICS = 1073741824,
        TYPE_SCR = -2147483648,
        TYPE_DEFAULT = 1,
        TYPE_ALL = 2147483647,
    };
    enum HIT_TYPE
    {
        HIT_NONE = 0,
        HIT_GROUND = 1,
        HIT_SLOPE = 2,
        HIT_WALL = 4,
        HIT_CEILING = 8,
    };
public:
    class MyDTI;
    class cSbcArrayBP;
    class cColArray;
    class cSbcMoveReserveInfo;
    class Sbc;
    class cSbcMoveMatrix;
    class cSbcMoveResetReserveInfo;
    class cSbcRegistReserveInfo;
    class cSbcMoveReserveInfoAll;
    class cSbcMoveResetReserveInfoAll;
    class SbcObject;
    class cSbcSkinMesh;
    class cSbcHeightField;
    class Collider;
    class Node;
    class TriangleInfo;
    class SbcInfo;
    class SbcInfoBase;
    class ColliderPassiveNodeInfo;
    class ColliderActiveNodeInfo;
    class ActiveNodeInfo;
    class NodeList;
    class Param;
    class ScrCollisionInfo;
    class ScrCollisionInfoBase;
    class TraverseInfo;
    struct CallbackInfoQueue;
    class PreTraverseInfo;
    class ScrCollisionInfoFind;
    class ScrCollisionInfoCastConvex;
    class ScrCollisionInfoAdjustPosition;
    class ScrCollisionInfoGetAreaPoly;
    struct GetTriangleInfo;
    class ScrCollisionInfoOriginal;
    class ScrCollisionInfoPreTraverse;
    class ScrCollisionInfoFind4;
    class cSystemInitializeParam;
    class SbcLockInfo;
    class ParamGetPolygons;
    struct PartsContactParam;
    class SbcLockInfoLight;
    struct ColliderEnumContactDirectInfo;
public:
    using SBC_HANDLE = nCollision::SBC_HANDLE;
    using SBC_HANDLE_HALF = nCollision::SBC_HANDLE_HALF;
    using OBJ_FUNC = void(MtObject::*)(sCollision::CALLBACK_MODE, sCollision::Node*, sCollision::Node*, MtContact*, uintptr, sCollision::TriangleInfo*, u32, u32, bool);
    using SBC_HANDLE_HF = nCollision::SBC_HANDLE;
    using OBJ_FILTER_FUNC_NODE = bool(MtObject::*)(sCollision::Node&, sCollision::Node&, uintptr);
    using OBJ_FILTER_FUNC_GEOMETRY = bool(MtObject::*)(sCollision::Node&, sCollision::Node&, u32, u32, uintptr);
    using OBJ_FUNC_OUTSIDE = void(MtObject::*)(const MtGeomConvex&, const MtGeomConvex&, const MtContact&, sCollision::Node&, u32, void*);
    using cSbcMoveReserveArray = MtCollisionUtil::MtArrayTemplate<sCollision::cSbcMoveReserveInfo, true, 1>;
    using cSbcMoveResetReserveArray = MtCollisionUtil::MtArrayTemplate<sCollision::cSbcMoveResetReserveInfo, false, 1>;
    using cSbcRegistReserveArray = MtCollisionUtil::MtArrayTemplate<sCollision::cSbcRegistReserveInfo, true, 1>;
    using cUnregistSbcHandleArray = MtCollisionUtil::MtArrayTemplate<unsigned int, false, 1>;
    using cSbcMoveReserveAllArray = MtCollisionUtil::MtArrayTemplate<sCollision::cSbcMoveReserveInfoAll, true, 1>;
    using cSbcMoveResetReserveAllArray = MtCollisionUtil::MtArrayTemplate<sCollision::cSbcMoveResetReserveInfoAll, false, 1>;
    using CONTACT_CALLBACK = u32(MtObject::*)(const sCollision::SbcInfo&, uintptr);
    using CONTACT_CALLBACK_EX = u32(MtObject::*)(const sCollision::ScrCollisionInfo&, const sCollision::SbcInfo&, uintptr);
    using CONTACT_CALLBACK_HIT_PAIR_POLYGON = u32(MtObject::*)(sCollision::SbcInfo&, sCollision::ScrCollisionInfoBase&);
    using CONTACT_CALLBACK_HIT = u32(MtObject::*)(const sCollision::SbcInfo&, sCollision::ScrCollisionInfoBase&);
    using CONTACT_CALLBACK_MV = u32(MtObject::*)(MtGeometry*, const sCollision::SbcInfo&, sCollision::ScrCollisionInfoBase&);
    using CONTACT_CALLBACK_RESET = u32(MtObject::*)(MtGeometry*, const sCollision::SbcInfo&, sCollision::ScrCollisionInfoBase&);
    using CONTACT_CALLBACK_BASIC_SCR = bool(MtObject::*)(const MtGeometry*, sCollision::TraverseInfo*, uScrollCollisionGeometry&, sCollision::ScrCollisionInfoBase&);
    using CONTACT_CALLBACK_HEIGHTFIELD_SCR = u32(MtObject::*)(sCollision::TraverseInfo*, sCollision::ScrCollisionInfoBase&);
    using SCRCOLLISION_FILTERING_CALLBACK = bool(MtObject::*)(const sCollision::SbcInfo&, void*);
    using CONTACT_CALLBACK_ORGFUNC = u32(MtObject::*)(const sCollision::SbcInfo&, uintptr, u32);
    using CONTACT_CALLBACK_ORGFUNC_FIND = u32(MtObject::*)(const sCollision::SbcInfo&, const MtContact&, uintptr, u32);
    using CONTACT_CALLBACK_ORGFUNC_PARTS = void(MtObject::*)(const sCollision::SbcInfo&, uintptr);
    using ENUMNODECONTACTCOMMON_CALLBACK = bool(MtObject::*)(sCollision::TraverseInfo&, sCollision::SbcInfo&, const MtGeomConvex&, sCollision::ScrCollisionInfoBase&, uScrollCollisionGeometry&, u32);
    using CONTACT_CALLBACK_ENUM = u32(MtObject::*)(MtGeometry*, sCollision::TraverseInfo&);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cColArray : public MtCollisionUtil::MtArrayEx
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        cColArray();
        virtual ~cColArray();
    public:
        static MyDTI DTI;
    };
public:
    class cSbcMoveMatrix : public nCollision::cScrCollisionMoveMatrix
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        cSbcMoveMatrix();
        virtual ~cSbcMoveMatrix();
    public:
        static MyDTI DTI;
    };
public:
    class cSbcRegistReserveInfo : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new[](size_t sz, u32 align);
        static void operator delete[](void* p_addr);
        static void usage();
        static void* operator new(size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cSbcRegistReserveInfo();
        virtual ~cSbcRegistReserveInfo();
        bool registReserveInfo(rCollision* pRSbc, sCollision::SBC_HANDLE* pOutputHandle, u32 RegistType, u8 RegistGroup);
        const sCollision::cSbcRegistReserveInfo& operator=(const sCollision::cSbcRegistReserveInfo& src);
        rCollision* getRegistResource() const;
        void releaseResource();
        sCollision::SBC_HANDLE* getOutputHandle() const;
        u32 getRegistType() const;
        u8 getRegistGroup() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        rCollision* mpRSbc;  // offset: 0x8
        sCollision::SBC_HANDLE* mpOutputHandle;  // offset: 0x10
        u32 mRegistType;  // offset: 0x18
        u8 mRegistGroup;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
public:
    class cSbcMoveReserveInfoAll : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new[](size_t sz, u32 align);
        static void operator delete[](void* p_addr);
        static void usage();
        static void* operator new(size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cSbcMoveReserveInfoAll();
        virtual ~cSbcMoveReserveInfoAll();
        bool registReserveInfo(sCollision::Sbc& TargetSbc, const MtMatrix& MoveMatrix, bool FlgResetSet);
        const sCollision::cSbcMoveReserveInfoAll& operator=(const sCollision::cSbcMoveReserveInfoAll& src);
        sCollision::Sbc* getTargetSbc() const;
        bool isMoveScrResetSet() const;
        const MtMatrix& getRegistMatrix() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        sCollision::Sbc* mpTargetSbc;  // offset: 0x8
        bool mFlgResetSet;  // offset: 0x10
        MtMatrix mRegistMatrix;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class cSbcMoveResetReserveInfoAll : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new[](size_t sz, u32 align);
        static void operator delete[](void* p_addr);
        static void usage();
        static void* operator new(size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cSbcMoveResetReserveInfoAll();
        virtual ~cSbcMoveResetReserveInfoAll();
        bool registReserveInfo(sCollision::Sbc& TargetSbc);
        const sCollision::cSbcMoveResetReserveInfoAll& operator=(const sCollision::cSbcMoveResetReserveInfoAll& src);
        sCollision::Sbc* getResetTargetSbc() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        sCollision::Sbc* mpTargetSbc;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class SbcObject : public MtObject
    {
    public:
        enum DBVT_TYPE
        {
            DBVT_TYPE_STOP = 0,
            DBVT_TYPE_MOVE = 1,
            DBVT_TYPE_NUM = 2,
            DBVT_TYPE_NONE = -1,
        };
    public:
        class MyDTI;
        class cRegisterInfo;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cRegisterInfo : public MtObject
        {
        public:
            class MyDTI;
        public:
            class MyDTI : public MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
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
            cRegisterInfo();
            virtual ~cRegisterInfo();
            bool isEnable() const;
            void setEnable(bool FlgEnable);
            uScrollCollisionGeometry* getRegisterGeometryUnit() const;
            void setRegisterGeometryUnit(uScrollCollisionGeometry* pUnit);
            void initDBVTData(cDynamicBVHCollision::Node* pDBVTNode, sCollision::SbcObject::DBVT_TYPE DBVTType);
            cDynamicBVHCollision::Node* getDBVTNode();
            sCollision::SbcObject::DBVT_TYPE getDBVTType();
            u32 getUnregisterGroupIndex() const;
            const sCollision::SbcObject::cRegisterInfo& operator=(const sCollision::SbcObject::cRegisterInfo& src);
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
        protected:
            bool mFlgEnable;  // offset: 0x8
            uScrollCollisionGeometry* mpRegistGeometry;  // offset: 0x10
            cDynamicBVHCollision::Node* mpDBVTNode;  // offset: 0x18
            sCollision::SbcObject::DBVT_TYPE mDBVTType;  // offset: 0x20
            u32 mUnregisterGroupIndex;  // offset: 0x24
        public:
            static MyDTI DTI;
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
        SbcObject();
        virtual ~SbcObject();
        void initialize();
        void setup();
        void move();
        void runReserveunregisterPG();
        void debugDraw();
        void applyWorldOffset(const MtVector3& absolute_offset);
        cDynamicBVHCollision& getBroadPhaseDBVTForStop(u32 GroupIndex);
        cDynamicBVHCollision& getBroadPhaseDBVTForMove(u32 GroupIndex);
        void removeBroadPhaseDBVTNoUseBuffer();
        void setAutoRemoveNoUseBuffer_NextRegist(bool FlgAutoRemoveNoUseBuffer);
        bool isAutoRemoveNoUseBuffer_NextRegist() const;
        cRegisterInfo* reserveRegisterNode(uScrollCollisionGeometry& ScrGeometry);
        void reserveUnregisterNode(cRegisterInfo& RegisterInfo);
        void registerNodeAll();
        void unregisterNodeAll();
        void updateScrCollisionGeometry(cRegisterInfo& RegisterInfo, u32 MoveCode);
        uScrollCollisionGeometry* getNode(u32 ArrayIndex);
        u32 getNodeNum();
        bool isActive();
        void setActive(bool);
        void createPropertyForDBVTDrawUI(MtPropertyList& s);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        u32 countStopSbcObject() const;
        u32 countMoveSbcObject() const;
        void setDummyU32(u32);
    protected:
        bool mFlgActive;  // offset: 0x8
        MtCriticalSection mCS;  // offset: 0x10
        bool mFlgAutoRemoveDBVTNoUseBuffer;  // offset: 0x18
        MtTypedArray<cRegisterInfo> mRegisterArray;  // offset: 0x20
        s32 mReserveRegisterNum;  // offset: 0x40
        s32 mReserveUnregisterNum;  // offset: 0x44
        MtTypedArray<cRegisterInfo> mReserveRegisterArray[19];  // offset: 0x48
        MtTypedArray<cRegisterInfo> mReserveUnregisterArray[19];  // offset: 0x2a8
        cDynamicBVHCollision mDBVTStopBasicSCR[32];  // offset: 0x508
        cDynamicBVHCollision mDBVTMoveBasicSCR[32];  // offset: 0x1308
    public:
        static MyDTI DTI;
    };
public:
    class cSbcSkinMesh : public MtObject
    {
    public:
        class MyDTI;
        class cRegisterInfo;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cRegisterInfo : public MtObject
        {
        public:
            class MyDTI;
        public:
            class MyDTI : public MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
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
            cRegisterInfo();
            virtual ~cRegisterInfo();
            bool isEnable() const;
            void setEnable(bool FlgEnable);
            uDynamicSbc* getRegisterUnit() const;
            void setRegisterUnit(uDynamicSbc* pUnit);
            void initDBVTData(cDynamicBVHCollision::Node* pDBVTNode);
            cDynamicBVHCollision::Node* getDBVTNode();
            const sCollision::cSbcSkinMesh::cRegisterInfo& operator=(const sCollision::cSbcSkinMesh::cRegisterInfo& src);
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
        protected:
            bool mFlgEnable;  // offset: 0x8
            uDynamicSbc* mpRegisterUnit;  // offset: 0x10
            cDynamicBVHCollision::Node* mpDBVTNode;  // offset: 0x18
        public:
            static MyDTI DTI;
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
        cSbcSkinMesh();
        virtual ~cSbcSkinMesh();
        void initialize();
        void setup();
        void move();
        void runReserveunregisterPG();
        void debugDraw();
        bool isActive() const;
        void setActive(bool);
        cRegisterInfo* registerUnit(uDynamicSbc& RegisterDynamicSbc);
        void unregisterUnit(cRegisterInfo& UnregisterInfo);
        uDynamicSbc* getUnit(u32 TargetIndex);
        u32 getArrayLength() const;
        cDynamicBVHCollision& getDBVTDynamicSbc();
        void removeBroadPhaseDBVTNoUseBuffer();
        void setAutoRemoveNoUseBuffer_NextRegist(bool FlgAutoRemoveNoUseBuffer);
        bool isAutoRemoveNoUseBuffer_NextRegist() const;
        void createPropertyForDBVTDrawUI(MtPropertyList& s);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        cRegisterInfo& getRegisterInfo(u32);
        cDynamicBVHCollision::Node* getUnitDBVTNode(u32 TargetIndex);
        void setUnitDBVTNode(cDynamicBVHCollision::Node* pNode, u32 TargetIndex);
        void runRegisterUnitReserveAll();
        void runUnregisterUnitReserveAll();
        void setDummyU32(u32);
    protected:
        bool mFlgActive;  // offset: 0x8
        bool mFlgAutoRemoveDBVTNoUseBuffer;  // offset: 0x9
        MtTypedArray<cRegisterInfo> mDynamicSbcArray;  // offset: 0x10
        s32 mReserveRegisterNum;  // offset: 0x30
        s32 mReserveUnregisterNum;  // offset: 0x34
        MtTypedArray<cRegisterInfo> mReserveRegisterArray[19];  // offset: 0x38
        MtTypedArray<cRegisterInfo> mReserveUnregisterArray[19];  // offset: 0x298
        cDynamicBVHCollision mDBVTDynamicSbc;  // offset: 0x4f8
    public:
        static MyDTI DTI;
    };
public:
    class cSbcHeightField : public MtObject
    {
    public:
        class MyDTI;
        class cHeightField;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cHeightField : public MtObject
        {
        public:
            class MyDTI;
        public:
            class MyDTI : public MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
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
            cHeightField();
            virtual ~cHeightField();
            void initialize();
            void move();
            void debugDraw();
            bool isActive() const;
            void registHeightField(rCollisionHeightField* pRCollisionHeightField, u32 type, u8 group);
            void unregistHeightField();
            rCollisionHeightField* getHeightFieldResource();
            nCollision::cScrCommonFilter& getScrFilter();
        protected:
            void registHeightFieldFromUI(rCollisionHeightField* pRCollisionHeightField);
        protected:
            bool mFlgActive;  // offset: 0x8
            nCollision::cScrCommonFilter mScrFilter;  // offset: 0x10
            rCollisionHeightField* mpHeightField;  // offset: 0x28
        public:
            static MyDTI DTI;
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
        cSbcHeightField();
        virtual ~cSbcHeightField();
        void initialize();
        void move();
        void debugDraw();
        sCollision::SBC_HANDLE_HF registHeightField(rCollisionHeightField* pRegistHeightField, u32 type, u8 group);
        void unregistHeightField(sCollision::SBC_HANDLE_HF UnregistHeightFieldHandle);
        cHeightField* getArrayElementByHandle(sCollision::SBC_HANDLE_HF TargetHandle);
        cHeightField* getArrayElementByIndex(u32 TargetIndex);
        u32 getArrayLength() const;
        void setDraw(bool FlgDraw);
        void clear();
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        MtArray mHeightFieldArray;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class Collider : public MtObject
    {
        // inferred: sCollision::sync calls sCollision::Collider::sync
        friend class sCollision;
    public:
        enum
        {
            MULTITHREAD_STAGE_SETUP = 0,
            MULTITHREAD_STAGE_CONTACT = 1,
            MULTITHREAD_STAGE_CONTACT_END = 2,
            MULTITHREAD_STAGE_NUM = 3,
        };
    public:
        class MyDTI;
        class cNodeListArray;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cNodeListArray : public MtArray
        {
        public:
            class MyDTI;
        public:
            class MyDTI : public MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
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
            cNodeListArray();
            virtual ~cNodeListArray();
            bool isEnableActive(u32 NodeListIndex);
            void setEnableActive(u32 NodeListIndex, bool FlgNextActiveSetting);
            bool isEnableActiveAll();
            void setEnableActiveAll(bool FlgNextActiveSetting);
            bool isEnableDraw(u32 NodeListIndex);
            void setEnableDraw(u32 NodeListIndex, bool FlgNextDrawSetting);
            bool isEnableDrawZTest(u32 NodeListIndex);
            void setEnableDrawZTest(u32 NodeListIndex, bool FlgNextZTestSetting);
            bool isEnableDrawAll();
            void setEnableDrawAll(bool FlgNextDrawSetting);
            bool isEnableDrawZTestAll();
            void setEnableDrawZTestAll(bool FlgNextZTestSetting);
            bool isDispColorActiveAllEQ();
            u32 getDispColorActiveAllByU32();
            void setDispColorActiveAllByU32(u32 NewColor);
            MtColor getDispColorActiveAll();
            void setDispColorActiveAll(MtColor NewColor);
            MtColor getDispColorActive(u32 PhaseIndex);
            void setDispColorActive(MtColor NewColor, u32 PhaseIndex);
            bool isDispColorPassiveAllEQ();
            u32 getDispColorPassiveAllByU32();
            void setDispColorPassiveAllByU32(u32 NewColor);
            MtColor getDispColorPassiveAll();
            void setDispColorPassiveAll(MtColor NewColor);
            MtColor getDispColorPassive(u32 PhaseIndex);
            void setDispColorPassive(MtColor NewColor, u32 PhaseIndex);
            sCollision::NodeList* getNodeList(u32 index);
        protected:
            void clearCorrectData();
            void correctCollisionInfo();
        public:
            static MyDTI DTI;
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
        Collider();
        virtual ~Collider();
        void initialize(u32 NodeListNum);
        void initializeNodeListNum(s32 NewNodeListNum);
        void allocateNodeListInArray(s32 NextArrayNum);
        void setNodeListBufSize(u32 TargetTypeBits, u32 EntrySize, u32 RequestSize);
        void removeWorkBuffer();
        void setUnregistResourceAllMode(bool FlgEnable);
        void entryNode(sCollision::Node* pRegistNode, u32 TargetNodeListType);
        void enumContact(sCollision::Node* pRegistActiveNode, u32 TargetNodeListType, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, u32 UserParam, u32 ContactType);
        void enumContact(sCollision::Node* pRegistActiveNode, u32 TargetNodeListType, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, sCollision::OBJ_FILTER_FUNC_NODE pNodeFilteringCallback, sCollision::OBJ_FILTER_FUNC_GEOMETRY pGeometryFilteringCallback, u32 UserParam, u32 ContactType);
        sCollision::ColliderPassiveNodeInfo* addContinuousEntryNode(sCollision::Node* pRegistPassiveNode, u32 TargetNodeListIndex, u32 TargetNodeListPhaseIndex);
        sCollision::ColliderActiveNodeInfo* addContinuousEnumContact(sCollision::Node* pRegistActiveNode, u32 TargetNodeListIndex, u32 TargetNodeListPhaseIndex, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, u32 UserParam, u32 ContactType);
        sCollision::ColliderActiveNodeInfo* addContinuousEnumContact(sCollision::Node* pRegistActiveNode, u32 TargetNodeListIndex, u32 TargetNodeListPhaseIndex, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, sCollision::OBJ_FILTER_FUNC_NODE pNodeFilteringCallback, sCollision::OBJ_FILTER_FUNC_GEOMETRY pGeometryFilteringCallback, u32 UserParam, u32 ContactType);
        void removeContinuousEntryNode(sCollision::ColliderPassiveNodeInfo* pRemovePassiveInfo);
        void removeContinuousEnumContact(sCollision::ColliderActiveNodeInfo* pRemoveRequestRegistInfo);
        void enumContactDirect(sCollision::Node& HitCheckNode, u32 TargetNodeListType, s32 TargetColliderPhaseIndex, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, u32 UserParam, u32 ContactType);
        void enumContactDirect(sCollision::Node& HitCheckNode, u32 TargetNodeListType, s32 TargetColliderPhaseIndex, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, sCollision::OBJ_FILTER_FUNC_NODE pNodeFilteringCallback, sCollision::OBJ_FILTER_FUNC_GEOMETRY pGeometryFilteringCallback, u32 UserParam, u32 ContactType);
        bool enumContactDirect(const MtGeomConvex& HitCheckConvex, u32 TargetNodeListType, s32 TargetColliderPhaseIndex, MtObject* pCallbackOwner, sCollision::OBJ_FUNC_OUTSIDE pContactCallback, void* pUserParam, u32 TargetGroup, u32 TargetAttribute, u32 ContactType, const MtVector3& MoveVector);
        bool enumContactDirect(const MtGeomConvex& HitCheckConvex, u32 TargetNodeListType, s32 TargetColliderPhaseIndex, MtObject* pCallbackOwner, sCollision::OBJ_FUNC_OUTSIDE pContactCallback, nCollision::OBJ_FILTER_FUNC_NODE_PASSIVE pNodeFilteringCallback, nCollision::OBJ_FILTER_FUNC_GEOMETRY_PASSIVE pGeometryFilteringCallback, void* pUserParam, u32 TargetGroup, u32 TargetAttribute, u32 ContactType, const MtVector3& MoveVector);
        void setMultiThread(bool set);
        void setMultiThread(bool set, u32 idx);
        bool isMultiThread(u32 idx);
        bool isEnableActiveTargetPhase(u32 NodeListTypeIndex, u32 TargetPhaseIndex);
        void setEnableActiveTargetPhase(u32 NodeListTypeIndex, u32 TargetPhaseIndex, bool FlgNextActiveSetting);
        bool isEnableActive(u32 NodeListTypeIndex);
        void setEnableActive(u32 NodeListTypeIndex, bool FlgNextActiveSetting);
        bool isEnableActiveAll();
        void setEnableActiveAll(bool FlgNextActiveSetting);
        u32 getUsingTypeID() const;
        u32 getRunCount() const;
        u32 getRunCountMax() const;
        u32 getNodeListNum();
        u32 getNodeListInArrayLength(u32 TargetNodeListIndex);
        sCollision::NodeList* getNodeList(u32 TargetNodeListIndex, u32 TargetNodeListInArrayIndex);
        cNodeListArray* getNodeListArray(u32 TargetNodeListIndex);
    protected:
        void setup();
        void move();
        void movePhase0_runNodeListMove();
        void movePhase1_runSetupObjectCollisionSystem();
        void movePhase2_runContactJob();
        void movePhase3_runContactEnd();
        void sync();
        void draw();
        bool isTargetTypeNodeList(u32 TargetType, u32 TargetListIndex);
        sCollision::NodeList* getNodeListNow(u32 TargetNodeListIndex);
        void setDummy(sCollision::NodeList&, u32);
        void setDummyU32(u32);
    protected:
        MtArray mNodeListArray;  // offset: 0x8
        s32 mRunCountInOneFrame;  // offset: 0x28
        s32 mRunCountInOneFrameMax;  // offset: 0x2c
        u32 mRunningTypeID;  // offset: 0x30
        u32 mReserveBufferNumPassiveNode;  // offset: 0x34
        u32 mReserveBufferNumActiveNode;  // offset: 0x38
        bool mFlgMultiThread[3];  // offset: 0x3c
        bool mFlgUnregistResourceAllMode;  // offset: 0x3f
    public:
        static MyDTI DTI;
    };
public:
    class Node : public nCollision::cCollisionNodeObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void operator delete(void* p_addr);
        static void usage();
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        Node(MtGeomConvex* pGeometry, u32 GeometryAttribute, u32 GeometryUserID, MtObject* pGeometryUserPtr);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void copy(const nCollision::cObjectBase& src);  // vtable slot 9
        bool isGeometryEnable(u32);
        bool isGeometryEnableByUserID(u32);
        void setGeometryEnable(bool, u32);
        void setGeometryEnableByUserID(bool, u32);
        void registCallbackObjectCollisionInverse(sCollision::OBJ_FUNC pCallbackFunc);
        sCollision::OBJ_FUNC getCallbackObjectCollisionInverse() const;
        void startCallback(sCollision::CALLBACK_MODE mode, sCollision::Node* pActiveNode, u32 param, MtContact* pContact, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool Hited);
        const MtVector3& getVelocity() const;
        void setVelocity(const MtVector3& _setvec);
        u32 getData() const;
        void setData(u32);
        MtObject* getDataPtr() const;
        void setDataPtr(MtObject* ptr);
        void buildBoundingAABB();
        const MtAABB& getBBox() const;
        sCollision::Node& operator=(const sCollision::Node&);
        virtual ~Node();
        void registOwner(MtObject* pOwner, sCollision::OBJ_FUNC pCallbackFunc);
    protected:
        sCollision::OBJ_FUNC mpCallbackFromRequest;  // offset: 0xc8
    public:
        static MyDTI DTI;
    };
public:
    class SbcInfoBase : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        SbcInfoBase();
        virtual ~SbcInfoBase();
        virtual void clearHitInfo();  // vtable slot 6
        sCollision::SbcInfoBase& operator=(const sCollision::SbcInfo& info);
        void copy(const sCollision::SbcInfoBase& src);
        void convertSbcInfo(sCollision::SbcInfo& info);
    public:
        sCollision::SBC_HANDLE SbcHandle;  // offset: 0x8
        u32 SbcNo;  // offset: 0xc
        u32 PartsNo;  // offset: 0x10
        u32 HitLeafIndex;  // offset: 0x14
        u32 RTriNo;  // offset: 0x18
        uScrollCollisionGeometry* pHitScrGeometry;  // offset: 0x20
        sCollision::SBC_HANDLE_HF HitHeightFieldHandle;  // offset: 0x28
        s32 HitHeightFieldU;  // offset: 0x2c
        s32 HitHeightFieldV;  // offset: 0x30
        u32 HitHeightFieldTriID;  // offset: 0x34
        uDynamicSbc* pHitDSbc;  // offset: 0x38
        u16 DSbcBvhID;  // offset: 0x40
        bool FlgHitDynamicSbc;  // offset: 0x42
        static MyDTI DTI;
    };
public:
    class ColliderPassiveNodeInfo : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        ColliderPassiveNodeInfo();
        virtual ~ColliderPassiveNodeInfo();
        void setFrameUpdate(bool FlgSet);
        bool isFrameUpdate() const;
        u32 getNodeListPhaseIndex() const;
        u32 getNodeListIndex() const;
    protected:
        sCollision::Node* getNode() const;
        void setNode(sCollision::Node* pNode);
        void setNodeListPhaseIndex(u32 NodeListPhaseIndex);
        void setNodeListIndex(u32 NodeListIndex);
        cDynamicBVHCollision::Node* getDBVTNode() const;
        void setDBVTNode(cDynamicBVHCollision::Node* pNode);
    protected:
        u32 mNodeListPhaseIndex;  // offset: 0x8
        u32 mNodeListIndex;  // offset: 0xc
        sCollision::Node* mpNode;  // offset: 0x10
        bool mFlgFrameUpdate;  // offset: 0x18
        cDynamicBVHCollision::Node* mpDBVTNode;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class ActiveNodeInfo : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        ActiveNodeInfo();
        virtual ~ActiveNodeInfo();
        void initialize(sCollision::Node* pUseNode, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, sCollision::OBJ_FILTER_FUNC_NODE pFilteringFuncNode, sCollision::OBJ_FILTER_FUNC_GEOMETRY pFilteringFuncGeometry, u32 UserParam, u32 UseContactType);
        void registerFilteringCallbackAll(sCollision::OBJ_FILTER_FUNC_NODE pFilteringFuncNode, sCollision::OBJ_FILTER_FUNC_GEOMETRY pFilteringFuncGeometry);
        void registerFilteringCallbackNode(sCollision::OBJ_FILTER_FUNC_NODE pFilteringFuncNode);
        void registerFilteringCallbackGeometry(sCollision::OBJ_FILTER_FUNC_GEOMETRY pFilteringFuncGeometry);
        sCollision::COLLIDER_CONTACT_TYPE getContactType() const;
        bool isRegistFilteringFuncNode() const;
        bool isRegistFilteringFuncGeometry() const;
        bool isTargetNodeByCallbackFunc(sCollision::Node& PassiveNode) const;
        bool isTargetGeometryByCallbackFunc(sCollision::Node& PassiveNode, u32 ActiveNodeGeometryIndex, u32 PassiveNodeGeometryIndex);
        void startCallback(sCollision::CALLBACK_MODE mode, sCollision::Node* pNode, MtContact* pContact, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool Hited);
        sCollision::Node* getNode() const;
        u32 getTargetAttribute() const;
        u32 getTargetGroup() const;
        void setDummyU32(u32);
        size_t getOwnerPtrAddr();
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        sCollision::Node* mpActiveNode;  // offset: 0x8
        MtObject* mpCallbackOwner;  // offset: 0x10
        sCollision::OBJ_FUNC mpCallbackFunc;  // offset: 0x18
        sCollision::OBJ_FILTER_FUNC_NODE mpNodeFilteringCallback;  // offset: 0x28
        sCollision::OBJ_FILTER_FUNC_GEOMETRY mpGeometryFilteringCallback;  // offset: 0x38
        u32 mCallbackParam;  // offset: 0x48
        u32 mContactFunctionType;  // offset: 0x4c
        static MyDTI DTI;
    };
public:
    class Param : public MtObject
    {
    public:
        enum SKIP_TARGET
        {
            SKIP_TARGET_NONE = 0,
            SKIP_TARGET_SBC = 1,
            SKIP_TARGET_BASIC_SCR = 2,
            SKIP_TARGET_DYNAMIC_SBC = 3,
            SKIP_TARGET_HEIGHT_FIELD = 4,
            SKIP_TARGET_NUM = 5,
        };
        enum ADJPOS_AXIS_CHECK_MODE
        {
            ADJPOS_AXIS_CHECK_NONE = 0,
            ADJPOS_AXIS_CHECK_LINESEGMENT = 1,
            ADJPOS_AXIS_CHECK_MOVESPERE = 2,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void operator delete(void* p_addr);
        static void usage();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        Param(const u32 _type, const u32 _filter, const sCollision::CONTACT_CALLBACK pf, const u32 iparam, u32 icorrectionNum, MtObject* ipobj, bool iadjmvRelSetEnable, u32 _checkGroupBit, u32 icontact_mode, bool iadjAntiStopEnable);
        virtual ~Param();
        void setCollisionTargetObj(bool _FlgObjHitEnable);
        void setOwnerModelPtr(MtObject* _pOwnerModel);
        u32 getContactMode() const;
        u32 getTargetType() const;
        u32 getTargetGroup() const;
        u32 getTargetAttribute() const;
        bool isTargetBasicSCR() const;
        bool isTargetSkinMeshSCR() const;
        void startCallback(const sCollision::ScrCollisionInfo& NowScrCollisionInfo, const sCollision::SbcInfo& sbc) const;
        void setAdjustConvexStatus(f32 iadjConvexLimitP0, f32 iadjConvexLimitP1, f32 iadjConvexLimitR);
        void registScrCollisionFilteringCallback(MtObject* pCallbackOwner, sCollision::SCRCOLLISION_FILTERING_CALLBACK pCalbackFunction, void* pCallbackFunctionParam);
        bool isRegistTargetScrByScrCollisionFilteringCallback() const;
        bool isTargetScrByScrCollisionFilteringCallback(const sCollision::SbcInfo& info) const;
        void setSkinMeshEnable(bool);
        void setHitSkipType(u32 SkipType, MtObject* pSkipTargetPhase0, MtObject* pSkipTargetPhase1);
        MtObject* getHitSkipObject0(u32 TargetSkipType) const;
        MtObject* getHitSkipObject1(u32 TargetSkipType) const;
        bool isScrollAutoMode() const;
        bool isEnableFlatEdgeCheck() const;
        void setEnableFlatEdgeCheck(bool);
        void setEnableBackSinkInSetting(bool);
        bool isEnablePathBackSinkIn() const;
        void setAdjustPositionContactMode(u32 icontact_mode, bool FlgContinuationCharaMode);
        void setAdjustPositionStatus(u32 icontact_mode, u32 icorrectionNum, bool iadjAntiStopEnable, bool FlgBasicScrThroughCheckPowerd);
        void setAdjustPositionAntiVibrateParam(f32 VibrationStopDotArea, f32 VibrationStopCheckMoveLen);
        void setAdjustPositionCharaSetting(bool FlgJumpMode, f32 VibrationStopDotArea);
        void setAdjustPositionCameraSetting();
        void setAdjustPositionDefaultSetting();
        void setAdjustPositionWallStop(bool EnableWallStop, bool EnableWallStopForceWallOnly, f32 DownLen);
        void registAdjPosCheckAxisLS(const MtLineSegment& _ls, bool _FlgWallEdgeStop, bool FlgAdjPosLsNoHitFallSpeedKeepEnable);
        void registAdjPosCheckAxisLS(MtLineSegment& ls, const MtVector3& BasePos, const MtVector3& Axis, f32 CheckLength, f32 ConvexSize, bool _FlgWallEdgeStop, bool FlgAdjPosLsNoHitFallSpeedKeepEnable);
        void unregistAdjPosCheckAxisLS();
        const MtLineSegment& getAdjPosCheckAxisLS() const;
        bool isRegistAdjPosAxisLSCheck() const;
        void registAdjPosCheckAxisMoveSphere(const MtSphere& sphere, const MtVector3& SphereMoveVector, bool _FlgWallEdgeStop, bool _FlgFallPowerd);
        void registAdjPosCheckAxisMoveSphere(const MtVector3& BasePos, const MtVector3& Axis, f32 CheckLength, f32 ConvexSize, f32 CheckSphereRadius, bool _FlgWallEdgeStop, bool _FlgAdjPosLsNoHitFallSpeedKeepEnable);
        void unregistAdjPosCheckAxisMoveSphere();
        const MtSphere& getAdjPosCheckAxisSphere() const;
        const MtVector3& getAdjPosCheckAxisSphereMoveVector() const;
        bool isRegistAdjPosAxisSphereCheck() const;
        bool isEnableAdjPosForceWallFlick() const;
        void setEnableAdjPosForceWallFlick(bool);
        sCollision::Param& operator=(const sCollision::Param& src);
        void setCollisionTarget(u32 _type, u32 _filter, u32 _checkGroupBit, bool _FlgObjHitEnable);
        void setCallback(MtObject* pobj, const sCollision::CONTACT_CALLBACK pf, const uintptr iparam);
        void setCallbackEx(MtObject* pCallbackFunctionOwner, const sCollision::CONTACT_CALLBACK_EX pCallbackFuncEx, const uintptr FunctionParam);
    public:
        u32 type;  // offset: 0x8
        u32 checkGroupBit;  // offset: 0xc
        u32 filter;  // offset: 0x10
        MtObject* mpOwnerModel;  // offset: 0x18
        u32 hitTarget;  // offset: 0x20
        MtObject* pObject;  // offset: 0x28
        sCollision::CONTACT_CALLBACK pFunc;  // offset: 0x30
        sCollision::CONTACT_CALLBACK_EX pCallbackFunctionEx;  // offset: 0x40
        uintptr param;  // offset: 0x50
        MtObject* mpScrFilteringCallbackOwnerObject;  // offset: 0x58
        sCollision::SCRCOLLISION_FILTERING_CALLBACK mpScrFilteringCallbackFunction;  // offset: 0x60
        void* mpScrFilteringCallbackFunctionParam;  // offset: 0x70
        u32 mSkipTarget;  // offset: 0x78
        MtObject* mpSkipTargetPhase0;  // offset: 0x80
        MtObject* mpSkipTargetPhase1;  // offset: 0x88
        bool FlgEnableFlatEdgeCheck;  // offset: 0x90
        u32 contact_mode;  // offset: 0x94
        u32 correctionNum;  // offset: 0x98
        u32 adjPosRepairSinkInAvailNum;  // offset: 0x9c
        f32 adjPosEpsilon;  // offset: 0xa0
        f32 adjConvexLimitP0;  // offset: 0xa4
        f32 adjConvexLimitP1;  // offset: 0xa8
        f32 adjConvexLimitR;  // offset: 0xac
        f32 adjPosWallHitDownLen;  // offset: 0xb0
        f32 adjPosVibrationStopDotArea;  // offset: 0xb4
        f32 adjPosVibrationStopCheckMoveLenSq;  // offset: 0xb8
        f32 adjPosCharaVibrationStopDotArea;  // offset: 0xbc
        u32 AdjPosRegistAxisCollisionCheckMode;  // offset: 0xc0
        MtLineSegment AdjPosAxisCheckLS;  // offset: 0xd0
        MtSphere AdjPosAxisCheckSphere;  // offset: 0xf0
        MtVector3 AdjPosAxisCheckConvexMoveVec;  // offset: 0x100
        bool FlgAdjPosWallEdgeStop;  // offset: 0x110
        bool FlgAdjPosLsNoHitFallFlickEnable;  // offset: 0x111
        bool FlgAdjPosForceWallFlick;  // offset: 0x112
        bool FlgAdjPosAntiStopEnable;  // offset: 0x113
        bool FlgAdjPosWallStop;  // offset: 0x114
        bool FlgAdjPosWallStopForceAttrOnly;  // offset: 0x115
        bool FlgAdjPosBasicScrThroughCheckPowerd;  // offset: 0x116
        bool FlgPathBackSinkIn;  // offset: 0x117
        bool FlgObjHitEnable;  // offset: 0x118
        bool FlgSkinMeshEnable;  // offset: 0x119
    protected:
        bool adjPosMvMode;  // offset: 0x11a
        bool FlgInsideAdjustPositionOK;  // offset: 0x11b
    public:
        static MyDTI DTI;
        static const sCollision::Param Default;
    };
public:
    struct CallbackInfoQueue
    {
    public:
        sCollision::CONTACT_CALLBACK_HIT_PAIR_POLYGON mpFuncPairPolygonN;  // offset: 0x0
        sCollision::CONTACT_CALLBACK_HIT mpFuncN;  // offset: 0x10
        sCollision::CONTACT_CALLBACK_MV mpMoveFuncN;  // offset: 0x20
        sCollision::CONTACT_CALLBACK_RESET mpResetFuncN;  // offset: 0x30
        sCollision::CONTACT_CALLBACK_BASIC_SCR mpNodeFunc;  // offset: 0x40
        sCollision::CONTACT_CALLBACK_HEIGHTFIELD_SCR mpHeightFieldFunc;  // offset: 0x50
    };
public:
    class PreTraverseInfo
    {
    public:
        struct PreTraverseData;
    public:
        struct PreTraverseData
        {
        public:
            sCollision::SbcInfoBase info;  // offset: 0x0
        };
    public:
        PreTraverseInfo();
        ~PreTraverseInfo();
    private:
        PreTraverseData* pData;  // offset: 0x0
        u32 DataNum;  // offset: 0x8
        bool FlgFailed;  // offset: 0xc
    };
public:
    class cSystemInitializeParam : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        cSystemInitializeParam();
        virtual ~cSystemInitializeParam();
        u32 getSbcMaxNum() const;
        void setSbcMaxNum(u32 SbcNum);
        u32 getDBVTReserveBufferNum_SbcNoMoveAll(u32 SbcGroupIndex) const;
        void setDBVTReserveBufferNum_SbcNoMoveAll(u32 ReserveBufferNum, u32 SbcGroupIndex);
        u32 getDBVTReserveBufferNum_SbcStopAll(u32 SbcGroupIndex) const;
        void setDBVTReserveBufferNum_SbcStopAll(u32 ReserveBufferNum, u32 SbcGroupIndex);
        u32 getDBVTReserveBufferNum_SbcMoveAll(u32 SbcGroupIndex) const;
        void setDBVTReserveBufferNum_SbcMoveAll(u32 ReserveBufferNum, u32 SbcGroupIndex);
        u32 getDBVTReserveBufferNum_SbcStopParts(u32 SbcGroupIndex) const;
        void setDBVTReserveBufferNum_SbcStopParts(u32 ReserveBufferNum, u32 SbcGroupIndex);
        u32 getDBVTReserveBufferNum_SbcMoveParts(u32 SbcGroupIndex) const;
        void setDBVTReserveBufferNum_SbcMoveParts(u32 ReserveBufferNum, u32 SbcGroupIndex);
        u32 getSbcMoveReserveArrayReserveNum() const;
        void setSbcMoveReserveArrayReserveNum(u32 ArrayReserveNum);
        u32 getSbcMoveResetReserveArrayReserveNum() const;
        void setSbcMoveResetReserveArrayReserveNum(u32 ArrayReserveNum);
        u32 getSbcRegistReserveArrayReserveNum() const;
        void setSbcRegistReserveArrayReserveNum(u32 ArrayReserveNum);
        u32 getSbcUnregistArrayReserveNum() const;
        void setSbcUnregistArrayReserveNum(u32 ArrayReserveNum);
        u32 getSbcMoveAllReserveArrayReserveNum() const;
        void setSbcMoveAllReserveArrayReserveNum(u32 ArrayReserveNum);
        u32 getSbcMoveResetAllReserveArrayReserveNum() const;
        void setSbcMoveResetAllReserveArrayReserveNum(u32 ArrayReserveNum);
        u32 getColliderNodeListMaxNum() const;
        void setColliderNodeListMaxNum(u32 ColliderNodeListNum);
    protected:
        u32 mSbcMaxNum;  // offset: 0x8
        u32 mDBVTReserveBufferNum_SbcNoMoveAll[32];  // offset: 0xc
        u32 mDBVTReserveBufferNum_SbcStopAll[32];  // offset: 0x8c
        u32 mDBVTReserveBufferNum_SbcMoveAll[32];  // offset: 0x10c
        u32 mDBVTReserveBufferNum_SbcStopParts[32];  // offset: 0x18c
        u32 mDBVTReserveBufferNum_SbcMoveParts[32];  // offset: 0x20c
        u32 mSbcMoveReserveArrayReserveNum;  // offset: 0x28c
        u32 mSbcMoveResetReserveArrayReserveNum;  // offset: 0x290
        u32 mSbcRegistReserveArrayReserveNum;  // offset: 0x294
        u32 mSbcUnregistArrayReserveNum;  // offset: 0x298
        u32 mSbcMoveAllReserveArrayReserveNum;  // offset: 0x29c
        u32 mSbcMoveResetAllReserveArrayReserveNum;  // offset: 0x2a0
        u32 mColliderNodeListMaxNum;  // offset: 0x2a4
    public:
        static MyDTI DTI;
        static const u32 DEFAULT_SBCMAXNUM = 256;
        static const u32 DEFAULT_DBVTRESERVEBUFFERNUM_SBCNOMOVEALL = 0;
        static const u32 DEFAULT_DBVTRESERVEBUFFERNUM_SBCSTOPALL = 0;
        static const u32 DEFAULT_DBVTRESERVEBUFFERNUM_SBCMOVEALL = 0;
        static const u32 DEFAULT_DBVTRESERVEBUFFERNUM_SBCSTOPPARTS = 0;
        static const u32 DEFAULT_DBVTRESERVEBUFFERNUM_SBCMOVEPARTS = 0;
        static const u32 DEFAULT_COLLIDERNODELISTMAXNUM = 8;
    };
public:
    class ParamGetPolygons : public sCollision::Param
    {
    public:
        ParamGetPolygons();
        void setGetPolygonsParam(bool _FlgCullingEnable, const MtVector3& _CullingNormal, f32 _CullingArea);
    public:
        bool FlgCullingEnable;  // offset: 0x11c
        MtVector3 CullingNormal;  // offset: 0x120
        f32 CullingArea;  // offset: 0x130
        static sCollision::ParamGetPolygons Default;
    };
public:
    struct PartsContactParam
    {
    public:
        MtGeometry* pGeom;  // offset: 0x0
        sCollision::TraverseInfo* pCallback;  // offset: 0x8
        u32 ThreadIndex;  // offset: 0x10
    };
public:
    class SbcLockInfoLight
    {
    public:
        SbcLockInfoLight();
        bool initialize(const sCollision::TriangleInfo& info, const MtQuaternion& qt);
        bool calcNowPos(MtVector3& OutNowPos);
        bool calcNowPos(MtVector3& OutNowPos, MtQuaternion& OutNowQt);
    public:
        MtFloat3 mOffset;  // offset: 0x0
        sCollision::SBC_HANDLE_HALF mHitSbcHandle;  // offset: 0xc
        u16 mHitSbcPartsNo;  // offset: 0xe
        MtQuaternion mOffsetQt;  // offset: 0x10
        uScrollCollisionGeometry* mpHitBasicConvexScr;  // offset: 0x20
        const uDynamicSbc* mpHitDynamicSbc;  // offset: 0x28
        u16 mHitBasicConvexScrGeomIndex;  // offset: 0x30
        u16 mHitDynamicSbcBvhID;  // offset: 0x32
        u16 mHitDynamicSbcTriIndex;  // offset: 0x34
        bool mFlgEnable;  // offset: 0x36
    };
public:
    struct ColliderEnumContactDirectInfo
    {
    public:
        const MtGeomConvex* pHitCheckConvex;  // offset: 0x0
        MtObject* pCallbackOwner;  // offset: 0x8
        sCollision::OBJ_FUNC_OUTSIDE pContactCallback;  // offset: 0x10
        nCollision::OBJ_FILTER_FUNC_NODE_PASSIVE pNodeFilteringCallback;  // offset: 0x20
        nCollision::OBJ_FILTER_FUNC_GEOMETRY_PASSIVE pGeometryFilteringCallback;  // offset: 0x30
        void* pUserParam;  // offset: 0x40
        u32 TargetGroup;  // offset: 0x48
        u32 TargetAttribute;  // offset: 0x4c
        u32 ContactType;  // offset: 0x50
        const MtVector3* pMoveVector;  // offset: 0x58
    };
public:
    class cSbcArrayBP : public sCollision::cColArray
    {
    public:
        class MyDTI;
        class cDBVTMaster;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cDBVTMaster : public MtObject
        {
        public:
            class MyDTI;
        public:
            class MyDTI : public MtDTI
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
            cDBVTMaster();
            virtual ~cDBVTMaster();
            cDynamicBVHCollision& getBroadPhaseDBVTStopForSbc();
            cDynamicBVHCollision& getBroadPhaseDBVTStopForAllSbc();
            cDynamicBVHCollision& getBroadPhaseDBVTMoveForAllSbc();
            cDynamicBVHCollision& getBroadPhaseDBVTStopForSbcParts();
            cDynamicBVHCollision& getBroadPhaseDBVTMoveForSbcParts();
            bool isTargetSbc(u32, u32) const;
            bool isTargetType(u32) const;
            void setType(u32);
            u32 getType() const;
            bool isTargetGroup(u32);
            u32 getGroupByBit() const;
            u8 getGroupByIndex() const;
            void setGroupByIndex(u8);
            void setGroupByBit(u32);
            const nCollision::cScrCommonFilter& getScrFilter() const;
        protected:
            nCollision::cScrCommonFilter mScrFilter;  // offset: 0x8
            cDynamicBVHCollision mDBVTStopSbc;  // offset: 0x20
            cDynamicBVHCollision mDBVTMoveAllSbc;  // offset: 0x90
            cDynamicBVHCollision mDBVTStopAllSbc;  // offset: 0x100
            cDynamicBVHCollision mDBVTStopSbcParts;  // offset: 0x170
            cDynamicBVHCollision mDBVTMoveSbcParts;  // offset: 0x1e0
        public:
            static MyDTI DTI;
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
        cSbcArrayBP();
        virtual ~cSbcArrayBP();
        virtual void setClass(MtObject* pObj, u32 i);  // vtable slot 6
        void initialize(sCollision::cSystemInitializeParam& InitializeParam);
        sCollision::SBC_HANDLE registResource(rCollision* pRSbc, u32 type, u8 group, bool FlgForceRegist, bool FlgEnableMove);
        void removeBroadPhaseDBVTAll();
        cDynamicBVHCollision& getBroadPhaseDBVTStopForSbc(u32 GroupIndex);
        cDynamicBVHCollision& getBroadPhaseDBVTStopForAllSbc(u32 GroupIndex);
        cDynamicBVHCollision& getBroadPhaseDBVTMoveForAllSbc(u32 GroupIndex);
        cDynamicBVHCollision& getBroadPhaseDBVTStopForSbcParts(u32 GroupIndex);
        cDynamicBVHCollision& getBroadPhaseDBVTMoveForSbcParts(u32 GroupIndex);
        void runReserveInfoRCollisionMatrix(const sCollision::cSbcMoveReserveInfo& RegistMoveMatrixInfo);
        void runReserveInfoRCollisionMatrixIdentity(const sCollision::cSbcMoveResetReserveInfo& RegistResetMatrixInfo);
        void runReserveInfoRegistRCollisionResource(sCollision::cSbcRegistReserveInfo& RegistResourceInfo);
        void runReserveInfoRCollisionMatrixAll(const sCollision::cSbcMoveReserveInfoAll& RegistMoveMatrixInfoAll);
        void runReserveInfoRCollisionMatrixIdentityAll(const sCollision::cSbcMoveResetReserveInfoAll& RegistResetMatrixInfo);
        void registDBVTSbc(sCollision::Sbc& TargetSbc, u32 DBVTCode);
        void unregistDBVTSbc(sCollision::Sbc& TargetSbc);
        void moveSbcGroupDBVT(sCollision::Sbc& TargetSbc, u32 NowGroupIndex, u32 NextGroupIndex);
        void updateSbcPartsMoveNum(sCollision::Sbc& TargetSbc, u32 DBVTTypeNow, u32 DBVTTypeOld);
    protected:
        u32 countStopSbc();
        u32 countMoveAllSbc();
        u32 countStopAllSbc();
        u32 countStopSbcParts();
        u32 countMoveSbcParts();
        void setDummyU32(u32);
    protected:
        cDynamicBVHCollision mDBVTStopSbc[32];  // offset: 0x38
        cDynamicBVHCollision mDBVTMoveAllSbc[32];  // offset: 0xe38
        cDynamicBVHCollision mDBVTStopAllSbc[32];  // offset: 0x1c38
        cDynamicBVHCollision mDBVTStopSbcParts[32];  // offset: 0x2a38
        cDynamicBVHCollision mDBVTMoveSbcParts[32];  // offset: 0x3838
    public:
        static MyDTI DTI;
    };
public:
    class Sbc : public MtObject
    {
    public:
        class MyDTI;
        class Parts;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Parts : public MtObject
        {
        public:
            class MyDTI;
        public:
            class MyDTI : public MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
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
            Parts(sCollision::Sbc* pSbc, u32 PartsIndex);
            virtual ~Parts();
            void initialize(sCollision::Sbc* pSbc, u32 PartsIndex);
            u32 getPartsIndex();
            bool isActive() const;
            void setActive(bool set);
            sCollision::Sbc* getOwnerSbc();
            bool getRPartsAABB(MtAABB& aabb) const;
            bool getPartsWorldAABB(MtAABB& aabb) const;
            u32 getRPartsID();
            bool getBoundingAABB(MtAABB& OutputAABB) const;
            const MtMatrix& getMatrix() const;
            const MtMatrix& getHalfMatrix() const;
            const MtMatrix& getOldMatrix() const;
            const MtMatrix& getMatrixInverse() const;
            const MtMatrix& getHalfMatrixInverse() const;
            const MtMatrix& getOldMatrixInverse() const;
            MtMatrix getRelativeMatrix() const;
            bool isMove() const;
            bool isMatResetSet() const;
            void setMatResetSet(bool);
            u32 setMatrixForGame(const MtMatrix* pSetMatrix, bool FlgResetSet);
            void* memAlloc(size_t);
            void memFree(void*);
            size_t memSize(void*);
        protected:
            void setPartsIndex(u32);
            MtMatrix& getMatrixFromID(u32 id);
            MtMatrix& getMatrixInverseFromID(u32 id);
            void setMatrix(const MtMatrix&);
            void setHalfMatrix(const MtMatrix&);
            void setOldMatrix(const MtMatrix&);
            void setMatrixByID(const MtMatrix&, u32);
            void setMove(bool);
            cDynamicBVHCollision::Node* getDBVTNode();
            void setDBVTNode(cDynamicBVHCollision::Node* pNewNode, u32 DBvtType);
            void clearDBVTNode();
            u32 getRegistDBVTType() const;
            bool isRegistedTree() const;
            void setDummyU32(u32);
            void setDummyBool(bool);
            void setDummyMatrix(MtMatrix&);
        protected:
            u32 mPartsIndex;  // offset: 0x8
            sCollision::Sbc* mpOwnerSbc;  // offset: 0x10
            bool mFlgActive;  // offset: 0x18
            cDynamicBVHCollision::Node* mpDBVTNode;  // offset: 0x20
            u32 mDBVTType;  // offset: 0x28
            sCollision::cSbcMoveMatrix mMatrixInfo;  // offset: 0x30
        public:
            static MyDTI DTI;
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void operator delete(void* p_addr);
        static void usage();
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        Sbc();
        virtual ~Sbc();
        void setActive(bool bActive);
        bool isActive() const;
        void setDisp(bool bDisp);
        bool isDisp() const;
        bool isTargetSbc(u32 type, u32 group, const MtObject* pNonTargetOwnerObj, const sCollision::Sbc* pPathSbc);
        bool isTargetType(u32);
        void setType(u32 type);
        u32 getType() const;
        bool isTargetGroup(u32);
        u32 getGroupByBit() const;
        u8 getGroupByIndex() const;
        void setGroupByIndex(u8 group);
        void setGroupByBit(u32 GroupBit);
        const nCollision::cScrCommonFilter& getScrFilter() const;
        u32 getGroup() const;
        void setGroup(u8);
        u32 getSbcArrayIndex() const;
        void setSbcArrayIndex(u32 _set);
        Parts* getParts(u32 index);
        const Parts* getPartsConst(u32 index) const;
        Parts* getPartsFromID(u32);
        Parts* getPartsFast(u32 index);
        Parts* getPartsFastFromID(u32);
        u32 getPartsNum() const;
        bool getPartsActive(u32 parts);
        void setPartsActive(u32 parts, bool bActive);
        bool getPartsActiveID(u32 id);
        void setPartsActiveID(u32 id, bool bActive);
        void setPartsActiveAll(bool);
        void setOwner(MtObject* pOwner);
        MtObject* getOwner();
        bool isRegistedResource();
        rCollision* getResourceSbc();
        const rCollision* getResourceSbcConst() const;
        void setResourceSbc(rCollision* pResource);
        void setResource(rCollision* pResource);
        void setCreateAllMove(bool set);
        bool isCreateAllMove();
        bool incrementMovePartsNum();
        bool decrementMovePartsNum();
        MtObject* registUserData(MtObject* pUserDataPtr, bool FlgAutoDelete);
        MtObject* registUserData(const MtDTI& UserDataDTI, bool FlgAutoDelete);
        void unregistUserData();
        MtObject* getUserData();
        bool isAutoDeleteUserData();
        void setAutoDeleteUserData(bool FlgNextAutoDelete);
        bool getLocalAABB(MtAABB& aabb) const;
        bool getWorldAABB(MtAABB& aabb, bool FlgCheckMoveParts) const;
        MtMatrix& getSbcMatrixFromID(u32 id);
        MtMatrix& getSbcMatrixInverseFromID(u32 id);
        const MtMatrix& getSbcMatrix() const;
        const MtMatrix& getSbcHalfMatrix() const;
        const MtMatrix& getSbcOldMatrix() const;
        const MtMatrix& getSbcMatrixInverse() const;
        const MtMatrix& getSbcHalfMatrixInverse() const;
        const MtMatrix& getSbcOldMatrixInverse() const;
        MtMatrix getSbcRelativeMatrix() const;
        bool isSbcMove() const;
        bool isSbcMatResetSet() const;
        void setSbcMatResetSet(bool);
        u32 registSbcMatrixAll(const MtMatrix* pSetMatrix, bool FlgResetSet);
        u32 registSbcPartsMatrix(u32 PartsIndex, const MtMatrix& PartsMatrixNew, bool FlgResetset);
        u32 registSbcPartsMatrix(Parts* pTargetParts, const MtMatrix& PartsMatrixNew, bool FlgResetset);
        u32 unregistSbcPartsMatrix(u32 PartsIndex);
        u32 unregistSbcPartsMatrix(Parts* pTargetParts);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        u32 getRef();
        void addRef();
        bool diffRef();
        void setResourceSbcForProperty(rCollision* pRSbc);
        void setDummyU32(u32);
        void setDummyParts(Parts*, u32);
        cDynamicBVHCollision::Node* getDBVTNode();
        void setDBVTNode(cDynamicBVHCollision::Node* pNewNode, u32 DBvtType);
        void clearDBVTNode();
        u32 getRegistDBVTType();
        bool isRegistedTree();
        void setPartsForIO(Parts* pParts, u32 TargetPartsIndex);
        void setPartsNumForIO(u32 NewPartsNum);
        void setPartsNum(u32 NewPartsNum);
        void releaseAllDynamicData();
        bool isStopAllParts() const;
        void setDummy(u32);
    protected:
        bool mDisp;  // offset: 0x8
        bool mActive;  // offset: 0x9
        u32 mSbcArrayIndex;  // offset: 0xc
        nCollision::cScrCommonFilter mScrFilter;  // offset: 0x10
        MtObject* mpOwner;  // offset: 0x28
        u32 mRefCount;  // offset: 0x30
        u32 mDBVTType;  // offset: 0x34
        cDynamicBVHCollision::Node* mpDBVTNode;  // offset: 0x38
        sCollision::cSbcMoveMatrix mMatrixInfo;  // offset: 0x40
        rCollision* mpRSbc;  // offset: 0x88
        Parts* mpPartsArray;  // offset: 0x90
        u32 mPartsArrayNum;  // offset: 0x98
        bool mFlgCreateAllMove;  // offset: 0x9c
        u32 mMovePartsNum;  // offset: 0xa0
        MtObject* mpUserPtr;  // offset: 0xa8
        bool mFlgUserPtrAutoDelete;  // offset: 0xb0
    public:
        static MyDTI DTI;
        static const u32 DBVT_TYPE_STOP = 0;
        static const u32 DBVT_TYPE_MOVE = 1;
        static const u32 DBVT_TYPE_NUM = 2;
        static const u32 DBVT_TYPE_DEFAULT = 4294967295;
        static const u32 DBVT_TYPE_NONE = 4294967295;
    };
public:
    class cSbcMoveResetReserveInfo : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new[](size_t sz, u32 align);
        static void operator delete[](void* p_addr);
        static void usage();
        static void* operator new(size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cSbcMoveResetReserveInfo();
        virtual ~cSbcMoveResetReserveInfo();
        bool registReserveInfo(sCollision::Sbc& TargetSbc, sCollision::Sbc::Parts& TargetParts);
        const sCollision::cSbcMoveResetReserveInfo& operator=(const sCollision::cSbcMoveResetReserveInfo& src);
        sCollision::Sbc* getResetTargetSbc() const;
        sCollision::Sbc::Parts* getResetTargetParts() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        sCollision::Sbc* mpTargetSbc;  // offset: 0x8
        sCollision::Sbc::Parts* mpTargetParts;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class SbcInfo : public sCollision::SbcInfoBase
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        SbcInfo();
        virtual ~SbcInfo();
        virtual void clearHitInfo();  // vtable slot 6
        void setHitScrSbcID(u32 HitSbcNo);
        void setHitScrInfoSbc(u32 HitSbcNo, u32 HitPartsID, u32 GetMatrixIDNow, u32 GetmatrixIDOld);
        void setHitScrInfoSbcForAllMove(u32 HitSbcNo, u32 GetMatrixIDNow, u32 GetmatrixIDOld);
        void setHitScrInfoSbcPartsIndexForAllMove(u32 HitPartsIndex);
        void setHitScrInfoSbcPolygon(u32 HitTriangleID);
        void setHitScrInfoObject(uScrollCollisionGeometry* _pHitScrGeometry, u32 MatIDNow, u32 MatIDOld);
        void setHitScrInfoObjectGeomID(u32 HitGeometryID);
        void setHitScrInfoHeightField(u32 HitHeightFieldNo, u32 HitTriangleID, u32 u, u32 v);
        void setHitScrInfoDyamicSbc(uDynamicSbc& HitDynamicSbc, u32 PartsID, u32 BvhID, u32 TriID);
        sCollision::SbcInfo& operator=(const sCollision::SbcInfo& info);
        void copy(const sCollision::SbcInfo& src);
        bool isHitSbc() const;
        bool isHitObject() const;
        bool isHitHeightField() const;
        bool isHitDynamicSbc() const;
        bool isHitAny() const;
        u32 getAttribute() const;
        u32 getUserAttribute(u32 AttributeID) const;
        u32* getAttributePtr() const;
        u32* getUserAttributePtr(u32) const;
        MtVector3 getNormal() const;
        MtVector3 getNormalW() const;
        void getTriangle(MtTriangle& tri) const;
        void getTriangle(MtVector3& p0, MtVector3& p1, MtVector3& p2) const;
        void getTriangleW(MtTriangle& tri) const;
        void getTriangleW(MtVector3& p0, MtVector3& p1, MtVector3& p2) const;
        void getTriangleLocal(MtTriangle&) const;
        void getTriangleLocal(MtVector3&, MtVector3&, MtVector3&) const;
        void getTriangleWorld(MtTriangle&) const;
        void getTriangleWorld(MtVector3&, MtVector3&, MtVector3&) const;
        u32 getTriangleAttribute(u32) const;
        u32* getTriangleAttributePtr(u32);
        sCollision::Sbc* getSbc() const;
        sCollision::SBC_HANDLE getHitSbcHandle() const;
        u32 getHitSbcNo() const;
        u32 getHitPartsNo() const;
        u32 getSbcHitTriangleNo() const;
        bool isSbcMove() const;
        rCollision* getRSbc() const;
        const rCollision::Leaf* getSbcHitLeaf() const;
        void getSbcTriangle(MtTriangle&) const;
        void getSbcTriangle(MtVector3& p0, MtVector3& p1, MtVector3& p2) const;
        void getSbcTriangleW(MtTriangle& tri) const;
        void getSbcTriangleW(MtVector3& p0, MtVector3& p1, MtVector3& p2) const;
        void getSbcTriangleFromLeaf(MtTriangle&, u32) const;
        void getSbcTriangleFromLeaf(MtVector3&, MtVector3&, MtVector3&, u32) const;
        void getSbcTriangleWFromLeaf(MtTriangle&, u32) const;
        void getSbcTriangleWFromLeaf(MtVector3&, MtVector3&, MtVector3&, u32) const;
        const MtVector3& getSbcTriangleNormal() const;
        const MtVector3 getSbcTriangleNormalW() const;
        u32 getSbcTriangleOriginalAttribute(u32) const;
        u32* getSbcTriangleOriginalAttributePtr(u32);
        rCollision::Triangle* getSbcResourceTrianglePtr() const;
        u32 getSbcAttribute() const;
        u32 getSbcUserAttribute(u32 AttributeID) const;
        u32* getSbcAttributePtr() const;
        u32* getSbcUserAttributePtr(u32) const;
        rCollision::MaterialInfo* getSbcHitMaterialInfoPtr();
        rCollisionHeightField* getHeightFieldResource() const;
        void getHeightFieldTriangle(MtTriangle& tri) const;
        void getHeightFieldTriangle(MtVector3& p0, MtVector3& p1, MtVector3& p2) const;
        MtVector3 getHeightFieldNormal() const;
        u32 getHeightFieldTriangleOriginalAttribute(u32) const;
        u32* getHeightFieldTriangleOriginalAttributePtr(u32);
        u32 getHeightFieldAttribute() const;
        u32 getHeightFieldUserAttribute(u32 AttributeID) const;
        u32* getHeightFieldAttributePtr() const;
        u32* getHeightFieldUserAttributePtr(u32) const;
        rCollision::MaterialInfo* getHeightFieldHitMaterialInfoPtr();
        uDynamicSbc* getDynamicSbcClass() const;
        void getDynamicSbcTriangle(MtTriangle& tri) const;
        void getDynamicSbcTriangle(MtVector3& p0, MtVector3& p1, MtVector3& p2) const;
        MtVector3 getDynamicSbcNormal() const;
        u32 getDynamicSbcAttribute() const;
        u32 getDynamicSbcUserAttribute(u32 AttributeID) const;
        u32* getDynamicSbcAttributePtr() const;
        u32* getDynamicSbcUserAttributePtr(u32 AttributeID) const;
        uScrollCollisionGeometry* getBasicCollisionClass();
        const uScrollCollisionGeometry* getBasicCollisionClassConst();
        const MtGeomConvex* getBasicCollisionHitConvex() const;
        const MtGeomConvex* getBasicCollisionConvex(u32 ConvexID) const;
        u32 getBasicCollisionConvexNum() const;
        u32 getBasicCollisionAttribute() const;
        u32 getBasicCollisionUserAttribute(u32 AttributeID) const;
        u32* getBasicCollisionAttributePtr() const;
        u32* getBasicCollisionUserAttributePtr(u32 AttributeID) const;
        MtObject* getHitTargetOwner();
        bool isCheckEdge(u32 EdgeID) const;
        MtMatrix getRelativeMatrix() const;
        MtQuaternion getRelativeRotaion();
        bool isMove() const;
        bool isResetSet() const;
        const MtMatrix& getMatrix() const;
        const MtMatrix& getOldMatrix() const;
        const MtMatrix& getMatrixInverse() const;
        const MtMatrix& getOldMatrixInverse() const;
    public:
        rCollision::PartsInfo* pPartsInfo;  // offset: 0x48
        rCollision::Triangle* pTriangle;  // offset: 0x50
        rCollision::Vertex* pVertex;  // offset: 0x58
        rCollision::MaterialInfo* pMaterialInfo;  // offset: 0x60
        u32 HitNodeGeomID;  // offset: 0x68
        bool FlgMove;  // offset: 0x6c
        bool FlgResetSet;  // offset: 0x6d
        const MtMatrix* pMoveMatrix;  // offset: 0x70
        const MtMatrix* pMoveMatrixInverse;  // offset: 0x78
        const MtMatrix* pMoveMatrixO;  // offset: 0x80
        const MtMatrix* pMoveMatrixOInverse;  // offset: 0x88
        static MyDTI DTI;
    };
public:
    class ColliderActiveNodeInfo : public sCollision::ActiveNodeInfo
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        ColliderActiveNodeInfo();
        virtual ~ColliderActiveNodeInfo();
        void setFrameUpdate(bool FlgSet);
        bool isFrameUpdate() const;
        u32 getNodeListPhaseIndex() const;
        u32 getNodeListIndex() const;
        void setContactFunctionType(u32);
    protected:
        void setNodeListPhaseIndex(u32 NodeListPhaseIndex);
        void setNodeListIndex(u32 NodeListIndex);
    protected:
        u32 mNodeListPhaseIndex;  // offset: 0x50
        u32 mNodeListIndex;  // offset: 0x54
        bool mFlgFrameUpdate;  // offset: 0x58
    public:
        static MyDTI DTI;
    };
public:
    class NodeList : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        NodeList();
        virtual ~NodeList();
        void setup();
        void move();
        void sync();
        void draw();
        void entryNode(sCollision::Node* pRegistNode);
        void enumContact(sCollision::Node* pRegistNode, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, sCollision::OBJ_FILTER_FUNC_NODE pNodeFilteringCallback, sCollision::OBJ_FILTER_FUNC_GEOMETRY pGeometryFilteringCallback, u32 UserParam, u32 ContactType);
        sCollision::ColliderPassiveNodeInfo* addContinuousEntryNode(sCollision::Node* pRegistNode);
        sCollision::ColliderActiveNodeInfo* addContinuousEnumContact(sCollision::Node* pRegistActiveNode, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, sCollision::OBJ_FILTER_FUNC_NODE pNodeFilteringCallback, sCollision::OBJ_FILTER_FUNC_GEOMETRY pGeometryFilteringCallback, u32 UserParam, u32 ContactType);
        void removeContinuousEntryNode(sCollision::ColliderPassiveNodeInfo* pRemovePassiveInfo);
        void removeContinuousEnumContact(sCollision::ColliderActiveNodeInfo* pRemoveRequestRegistInfo);
        void setupForSingleThread();
        void addJobSetupRegistNodeJob();
        void setupRegistNodeJob(u32 ThreadID);
        void addJobSetupRegistActiveNodeInfoJob();
        void setRegistActiveNodeInfoJob(u32 ThreadID);
        void addJobSetupRegistDataNumTotal();
        void setupRegistDataNumTotal(u32 DummyU32);
        void addJobSetupNodeGroup();
        void setupNodeGroup(u32 DummyU32);
        void setupContinuousDataAll(u32 DummyU32);
        void setupContinuousData_Remove();
        void setupContinuousData_Initialize();
        void setupContinuousData_Update();
        void setupContinuousData_Add();
        void executeContact(bool FlgMultiThread);
        void executeContactEnd(bool FlgMultiThread);
        void enumContactDirect(sCollision::Node& HitCheckNode, MtObject* pCallbackOwner, sCollision::OBJ_FUNC pContactCallback, sCollision::OBJ_FILTER_FUNC_NODE pNodeFilteringCallback, sCollision::OBJ_FILTER_FUNC_GEOMETRY pGeometryFilteringCallback, u32 UserParam, u32 ContactType);
        bool enumContactDirect(const MtAABB& HitCheckConvexAABB, const MtGeomConvex& HitCheckConvex, MtObject* pCallbackOwner, sCollision::OBJ_FUNC_OUTSIDE pContactCallback, nCollision::OBJ_FILTER_FUNC_NODE_PASSIVE pNodeFilteringCallback, nCollision::OBJ_FILTER_FUNC_GEOMETRY_PASSIVE pGeometryFilteringCallback, void* pUserParam, u32 TargetGroup, u32 TargetAttribute, u32 ContactType, const MtVector3& MoveVector);
        bool isActive();
        void setActive(bool FlgNextActive);
        bool isEnableDraw();
        void setEnableDraw(bool FlgNextDraw);
        bool isEnableDrawZTest();
        void setEnableDrawZTest(bool FlgNextZTest);
        void setDispColorActive(MtColor color);
        MtColor getDispColorActive();
        void setDispColorPassive(MtColor color);
        MtColor getDispColorPassive();
        u32 getTotalNodeNum();
        u32 getTotalRequestNum();
        bool setNodeListBufSize(u32 entrySize, u32 requestSize);
        void removeWorkBuffer();
        bool isEnableNode();
        bool isEnableActiveNodeInfo();
        void setNodeListIndex(u32 idx);
        u32 getNodeListIndex();
        void setUseDBVT(bool FlgUse);
        bool isUseDBVT() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    protected:
        sCollision::ActiveNodeInfo* createNewActiveNodeBuffer(u32 ThreadID);
        sCollision::ActiveNodeInfo* getActiveNodeInfo(u32 ThreadID, u32 RequestIndex);
        sCollision::Node* getPassiveNode(u32 ThreadID, u32 NodeIndex);
        nCollision::cCollisionNodeGroup* createNewCollisionNodeGroupForPassive();
        void clearCollisionNodeGroupForPassive();
        void executeTargetActiveNodeContact(uintptr TargetActiveNodePtrData);
        u32 executeTargetRequestNodeContact_BvhCallback(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
        u32 executeTargetRequestNodeContact_ContiuousBvhCallback(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
        bool executeTargetActiveNodeContactCore(sCollision::ActiveNodeInfo& ActiveNodeInfo, sCollision::Node& TargetNode, u32 ThreadID);
        u32 callbackEnumContactDirect(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
        u32 callbackEnumContactDirect_Continuous(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
        void hitCheckCallback(nCollision::cCollisionNode& ActiveNode, nCollision::cCollisionNode& PassiveNode, u32 HitActiveNodeGeometryIndex, u32 HitPassiveNodeGeometryIndex, MtContact& Contact, void* pSendParam);
        void hitCheckCallbackDirect(nCollision::cCollisionNode& PassiveNode, u32 HitPassiveNodeGeometryIndex, MtContact& Contact, void* pUserPtr);
        bool filteringCheckCallbackNode(nCollision::cCollisionNode& ActiveNode, nCollision::cCollisionNode& PassiveNode, void* pUserPtr);
        bool filteringCheckCallbackGeometry(nCollision::cCollisionNode& ActiveNode, nCollision::cCollisionNode& PassiveNode, u32 HitActiveNodeGeometryIndex, u32 HitPassiveNodeGeometryIndex, void* pUserPtr);
        void executeTargetRequestNodeContactEnd(uintptr TargetActiveNodePtrData);
    protected:
        bool mFlgActive;  // offset: 0x8
        u32 mNodeListIndex;  // offset: 0xc
        bool mFlgEnablePassiveNodeBVH;  // offset: 0x10
        bool mFlgForceUpdatePassiveNodeBVH;  // offset: 0x11
        MtArray mNodePtrArray[19];  // offset: 0x18
        MtArray mActiveNodeArray[19];  // offset: 0x278
        MtArray mActiveNodeNoUseArray[19];  // offset: 0x4d8
        MtArray mNodeGroupArray;  // offset: 0x738
        MtArray mNodeGroupNoUseArray;  // offset: 0x758
        u32 mTotalNodeNum;  // offset: 0x778
        u32 mTotalRequestNum;  // offset: 0x77c
        cDynamicBVHCollision mPassiveNodeBVH;  // offset: 0x780
        MtTypedArray<sCollision::ColliderActiveNodeInfo> mReserveRegistArrayActive[19];  // offset: 0x7f0
        MtTypedArray<sCollision::ColliderPassiveNodeInfo> mReserveRegistArrayPassive[19];  // offset: 0xa50
        MtTypedArray<sCollision::ColliderActiveNodeInfo> mReserveUnRegistArrayActive[19];  // offset: 0xcb0
        MtTypedArray<sCollision::ColliderPassiveNodeInfo> mReserveUnRegistArrayPassive[19];  // offset: 0xf10
        MtArray mContinuousActiveNodeArray;  // offset: 0x1170
        MtArray mContinuousPassiveNodeArray;  // offset: 0x1190
        cDynamicBVHCollision mContinuousPassiveNodeBVH;  // offset: 0x11b0
    public:
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfoBase : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfoBase();
        ScrCollisionInfoBase(const MtVector3& _cpos, const MtVector3& _cspeed);
        virtual ~ScrCollisionInfoBase();
        const sCollision::Param& getCollisionParam();
        sCollision::TraverseInfo* getTraverseInfo() const;
        const sCollision::SbcInfo& getSbcInfo() const;
        MtVector3& getPosOriginalReference();
        MtVector3& getPosTransformReference();
        const MtVector3* getPosUse() const;
        MtVector3& getSpeedOriginalReference();
        MtVector3& getSpeedTransformReference();
        const MtVector3* getSpeedUse() const;
    protected:
        void registTraverseInfo(sCollision::TraverseInfo& MyTraverseInfo);
        void setPosUse(MtVector3*);
        void setPosUseByFlag(bool FlgUseOriginal);
        void setSpeedUse(MtVector3* pUseSpeed);
        void setSpeedUseByFlag(bool FlgUseOriginal);
    protected:
        MtVector3 cpos;  // offset: 0x10
        MtVector3 cposTrans;  // offset: 0x20
        MtVector3 cposHited;  // offset: 0x30
        MtVector3* pcposUse;  // offset: 0x40
        MtVector3 cspeed;  // offset: 0x50
        MtVector3 cspeedTrans;  // offset: 0x60
        MtVector3 cspeedHited;  // offset: 0x70
        MtVector3* pcspeedUse;  // offset: 0x80
        sCollision::SbcInfo info;  // offset: 0x88
        bool FlgFind;  // offset: 0x118
        const sCollision::Param* pCollisionParam;  // offset: 0x120
        bool FlgObjHited;  // offset: 0x128
        sCollision::TraverseInfo* pTraverseInfo;  // offset: 0x130
    public:
        static MyDTI DTI;
    };
public:
    class TraverseInfo
    {
    public:
        TraverseInfo();
        ~TraverseInfo();
        void initialize(MtObject* _pOwnerObj, const sCollision::Param& _CollisionParam, bool _basenormal);
        void initializeTraverseData(MtGeometry* _pTraverseConvex, sCollision::Sbc* _pSbc, sCollision::SbcInfo* _pSbcInfo, u32 _ThreadID);
        void initializeTraverseDataDSbc(MtGeometry* _pTraverseConvex, uDynamicSbc* _pDSbc, sCollision::SbcInfo* _pSbcInfo, u32 _ThreadID);
        void registTraverseConvexDefault(MtGeometry* _pTraverseConvex);
        void registTargetSbc(sCollision::Sbc* pTargetSbc);
        bool isUseCallbackForPairPolygon();
        bool isUseCallback();
        bool isUseCallbackMv();
        bool isUseCallbackReset();
        bool isUseCallbackNode();
        bool isUseCallbackHeightField();
        u32 runCallbackFuncForPairPolygon(sCollision::SbcInfo& info);
        u32 runCallbackFunc(const sCollision::SbcInfo& info);
        u32 runCallbackFuncMv(MtGeometry* pGeom, const sCollision::SbcInfo& info);
        u32 runCallbackFuncReset(MtGeometry* pGeom, const sCollision::SbcInfo& info);
        bool runCallbackFuncBasicScr(const MtGeometry* pTraverseGeometry, uScrollCollisionGeometry& ScrGeometry);
        u32 runCallbackFunc_HeightField();
        void runCallbackFuncCollisionHitEnd(const sCollision::ScrCollisionInfo& NowScrCollisionInfo, const sCollision::SbcInfo& info);
        void registCollisionInfo(sCollision::ScrCollisionInfoBase& _ScrColInfo);
        void registCollisionParam(const sCollision::Param& _CollisionParam);
        void registCollisionParam_ScrCollisionInfo();
        void setNextCallbackRegist();
        void setNextCallbackUse();
        bool isAvailCallbackUse();
        bool isUseBaseNormal();
        MtObject* getOwnerObject();
        sCollision::CONTACT_CALLBACK_HIT getCallbackHit();
        sCollision::CONTACT_CALLBACK_MV getCallbackMove();
        sCollision::CONTACT_CALLBACK_RESET getCallbackReset();
        sCollision::CONTACT_CALLBACK_BASIC_SCR getCallbackHitNode();
        sCollision::CONTACT_CALLBACK_HIT getCallbackHit(u32);
        sCollision::CONTACT_CALLBACK_MV getCallbackMove(u32);
        sCollision::CONTACT_CALLBACK_RESET getCallbackReset(u32);
        sCollision::CONTACT_CALLBACK_BASIC_SCR getCallbackHitNode(u32);
        sCollision::ScrCollisionInfoBase& getCollisionInfo();
        const sCollision::Param& getCollisionParam();
        u32 getCollisionHitTarget();
        MtAABB& getTraverseConvexAABB();
        MtGeomAABB& getTraverseConvexAABBByGeometry();
        MtGeometry& getTraverseConvexDefault();
        sCollision::Sbc& getSbc();
        uDynamicSbc& getDynamicSbc();
        bool isRegistSbcInfo() const;
        void clearSbcInfo();
        sCollision::SbcInfo& getSbcInfo();
        void setSbcInfo(sCollision::SbcInfo& NewSbcInfo);
        void setHitCheckDynamicSbcPartsIndex(u32 NewPartsIndex);
        u32 getHitCheckDynamicSbcPartsIndex();
        void setHitCheckDynamicSbcPartsBvhIndex(u32 NewBVHIndex);
        u32 getHitCheckDynamicSbcPartsBvhIndex();
        u32 getThreadID();
        void setThreadID(u32 ThreadIndex);
        void setEnableExtendTraverseGeometry(MtGeometry* pTraverseGeometryOriginal, MtGeometry* pTraverseGeometryTransform);
        bool isEnableExtendTraverseGeometry() const;
        MtGeometry* getExtendTraverseGeometryOriginal() const;
        MtGeometry* getExtendTraverseGeometryTransform() const;
        MtGeometry* getExtendTraverseGeometryLocalSearch() const;
        void setExtendTraverseGeometryLocalSearch(MtGeometry* pLocalSearchTraverseGeomertry);
        void registPreTraverseInfo(sCollision::PreTraverseInfo& TraverseCached);
        sCollision::PreTraverseInfo* getRegistPreTraverseInfo();
        void registPreHitInfo(sCollision::TriangleInfo* pTraverseCached);
        sCollision::TriangleInfo* getRegistPreHitInfo();
        bool isOneHitEnd() const;
        void setOneHitEnd(bool FlgOneHitEnd);
        u32 getWorkU32(u32 WorkBufferIndex);
        void setWorkU32(u32 param, u32 WorkBufferIndex);
        MtObject* getWorkPtr(u32 WorkBufferIndex);
        void setWorkPtr(MtObject* ptr, u32 WorkBufferIndex);
    protected:
        MtObject* mpOwnerObj;  // offset: 0x0
        sCollision::CallbackInfoQueue mCallbackStack[3];  // offset: 0x8
        u32 mRegistCallbackNum;  // offset: 0x128
        u32 mCallbackUseIndex;  // offset: 0x12c
        MtGeomAABB mTraverseConvexAABB;  // offset: 0x130
        MtGeometry* mpTraverseConvex;  // offset: 0x160
        sCollision::ScrCollisionInfoBase* mpCollisionInfo;  // offset: 0x168
        const sCollision::Param* mpCollisionParam;  // offset: 0x170
        bool mFlgBaseNormal;  // offset: 0x178
        sCollision::Sbc* mpSbc;  // offset: 0x180
        uDynamicSbc* mpDSbc;  // offset: 0x188
        sCollision::SbcInfo* mpSbcInfo;  // offset: 0x190
        u32 mDSbcPartsIndex;  // offset: 0x198
        u32 mDSbcBvhID;  // offset: 0x19c
        bool mFlgExtendTraverseGeometry;  // offset: 0x1a0
        MtGeometry* mpExtendTraverseGeometryOriginal;  // offset: 0x1a8
        MtGeometry* mpExtendTraverseGeometryTransform;  // offset: 0x1b0
        MtGeometry* mpExtendTraverseGeometryLocalSearch;  // offset: 0x1b8
        sCollision::PreTraverseInfo* mpPreTraverseInfo;  // offset: 0x1c0
        sCollision::TriangleInfo* mpPreHitTriangleInfo;  // offset: 0x1c8
        bool mFlgOneHitEnd;  // offset: 0x1d0
        u32 mWorkU32[3];  // offset: 0x1d4
        MtObject* mWorkPtr[3];  // offset: 0x1e0
        u32 mThreadID;  // offset: 0x1f8
    public:
        static const u32 MAX_CALLBACK_QUEUE = 3;
        static const u32 WORK_BUFFER_NUM = 3;
    };
public:
    struct GetTriangleInfo
    {
    public:
        u32 id;  // offset: 0x0
        MtTriangle tri;  // offset: 0x10
        sCollision::SbcInfo sbc_info;  // offset: 0x40
    };
public:
    class SbcLockInfo : public sCollision::SbcInfo
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        SbcLockInfo();
        virtual ~SbcLockInfo();
        void initialize(const sCollision::TriangleInfo& info, const MtQuaternion& qt);
        MtVector3 calcNowFixPos();
        bool calcNextPos(MtVector3& NextPos, MtQuaternion& NextQt, MtVector3& HitConvexNormal, MtObject* & pHitOwner, const MtVector3& OffsetPos);
    public:
        f32 mHitOffsetAxisPos;  // offset: 0x90
        u32 mHitVid;  // offset: 0x94
        u32 mHitBoxPlaneTriID;  // offset: 0x98
        MtVector3 mHitPos;  // offset: 0xa0
        MtVector3 mHitGravityPos;  // offset: 0xb0
        MtVector3 mHitOffsetNormal;  // offset: 0xc0
        MtQuaternion mHitQt;  // offset: 0xd0
        MtQuaternion mHitBasicScrQt;  // offset: 0xe0
        MtFloat3 mHitDyanmicSbcNormal;  // offset: 0xf0
        uDynamicSbc* mpHitDynamicSbc;  // offset: 0x100
        static MyDTI DTI;
    };
public:
    class cSbcMoveReserveInfo : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new[](size_t sz, u32 align);
        static void operator delete[](void* p_addr);
        static void usage();
        static void* operator new(size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cSbcMoveReserveInfo();
        virtual ~cSbcMoveReserveInfo();
        bool registReserveInfo(sCollision::Sbc& TargetSbc, sCollision::Sbc::Parts& TargetParts, const MtMatrix& MoveMatrix, bool FlgResetSet);
        const sCollision::cSbcMoveReserveInfo& operator=(const sCollision::cSbcMoveReserveInfo& src);
        sCollision::Sbc* getTargetSbc() const;
        sCollision::Sbc::Parts* getTargetParts() const;
        bool isMoveScrResetSet() const;
        const MtMatrix& getRegistMatrix() const;
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
    public:
        sCollision::Sbc* mpTargetSbc;  // offset: 0x8
        sCollision::Sbc::Parts* mpTargetParts;  // offset: 0x10
        bool mFlgResetSet;  // offset: 0x18
        MtMatrix mRegistMatrix;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class TriangleInfo : public sCollision::SbcInfo
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        TriangleInfo();
        virtual ~TriangleInfo();
        sCollision::TriangleInfo& operator=(const sCollision::SbcInfo& info);
        const MtPlane& getHitPlane();
        const MtVector3& getHitPos();
        const MtVector3& getHitNormal();
        f32 getHitToi();
        f32 getHitDepth();
    public:
        MtPlane hit_plane;  // offset: 0x90
        MtVector3 hit_pos;  // offset: 0xa0
        MtVector3 hit_normal;  // offset: 0xb0
        f32 t;  // offset: 0xc0
        f32 depth;  // offset: 0xc4
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfo : public sCollision::ScrCollisionInfoBase
    {
        // inferred: sCollision::enumSphereTriBeforeFunc names sCollision::ScrCollisionInfo::workVec[3].z
        friend class sCollision;
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfo();
        ScrCollisionInfo(const MtVector3& _cpos, const MtVector3& _cspeed, MtGeometry* _pGeomOrg, MtGeometry* _pGeomTrans);
        virtual ~ScrCollisionInfo();
        const MtMatrix getSbcMatrix();
        MtGeometry* getGeometryOriginal() const;
        MtGeometry* getGeometryTransform() const;
        MtGeometry* getGeometryUse() const;
        void getBoundingAABBByOrg(MtAABB& aabb_out);
        void getBoundingAABBByTrans(MtAABB& aabb_out);
        f32 getRadius();
    protected:
        void updateMoveParam(const MtVector3& pos, const MtVector3& speed);
        void setConvex(MtGeometry* _pGeomOrg, MtGeometry* _pGeomTrans);
        void setGeometryUse(MtGeometry* pUseGeometry);
        void setGeometryUseByFlag(bool FlgUseOriginal);
        void getBoundingAABBByOrg(MtAABB& aabb_out, const MtSphere& sphere);
        void getBoundingAABBByTrans(MtAABB& aabb_out, const MtSphere& sphere);
        void getBoundingAABBByOrg(MtAABB& aabb_out, const MtCapsule& capsule);
        void getBoundingAABBByTrans(MtAABB& aabb_out, const MtCapsule& capsule);
    protected:
        MtGeometry* pGeomOrg;  // offset: 0x138
        MtGeometry* pGeomTrans;  // offset: 0x140
        MtGeometry* pGeomUse;  // offset: 0x148
        MtVector3 workVec[6];  // offset: 0x150
        MtVector3* pworkVecUse[6];  // offset: 0x1b0
    public:
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfoFind : public sCollision::ScrCollisionInfo
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfoFind();
        ScrCollisionInfoFind(const MtVector3& _cpos, const MtVector3& _cspeed, MtGeometry* _pGeomOrg, MtGeometry* _pGeomTrans, sCollision::TriangleInfo* _pTriangleInfo);
        virtual ~ScrCollisionInfoFind();
        MtVector3 getHitPosLocal() const;
        MtVector3 getHitPosWorld(const sCollision::SbcInfo& info) const;
        MtVector3 getHitNormalLocal() const;
        MtVector3 getHitNormalWorld(const sCollision::SbcInfo& info) const;
        f32 getHitTime() const;
        f32 getHitDeepestDistance() const;
    protected:
        MtVector3 hitPos;  // offset: 0x1e0
        MtVector3 hitNormal;  // offset: 0x1f0
        MtVector4 hitPlane;  // offset: 0x200
        bool FlgBothSide;  // offset: 0x210
        f32 NearestToi;  // offset: 0x214
        f32 deepestDistance;  // offset: 0x218
        sCollision::TriangleInfo* pTriangleInfo;  // offset: 0x220
        f32 work;  // offset: 0x228
    public:
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfoCastConvex : public sCollision::ScrCollisionInfoFind
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfoCastConvex();
        ScrCollisionInfoCastConvex(const MtVector3& _cpos, const MtVector3& _cspeed, MtGeometry* _pGeomOrg, MtGeometry* _pGeomTrans, sCollision::TriangleInfo* _pTriangleInfo, f32 _HitEpsilon);
        virtual ~ScrCollisionInfoCastConvex();
        void initCastConvexCollisionParam();
        void debugDraw(const MtVector3& pos, MtColor color, bool ztest, bool bOffsetEnable, const MtVector3& offset, const MtMatrix* pMatToWorld);
    protected:
        MtContact contact;  // offset: 0x230
        f32 HitEpsilon;  // offset: 0x260
        bool FlgEdgeHit;  // offset: 0x264
        bool FlgScrHit;  // offset: 0x265
        bool FlgBackHit;  // offset: 0x266
        bool FlgWorldMode;  // offset: 0x267
    public:
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfoAdjustPosition : public sCollision::ScrCollisionInfoCastConvex
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfoAdjustPosition();
        ScrCollisionInfoAdjustPosition(const MtVector3& _cpos, const MtVector3& _cspeed, MtGeometry* _pGeomOrg, MtGeometry* _pGeomTrans, sCollision::TriangleInfo* _pTriangleInfo, f32 _HitEpsilon, f32 _HitRetValue, bool _FlgAntiStopEnable);
        virtual ~ScrCollisionInfoAdjustPosition();
        bool isHitAxisConvex() const;
        bool isHitAxisConvexGround() const;
        bool isHitAxisConvexSlope() const;
        bool isHitAxisConvexWall() const;
        void registHitAxisConvex(u32);
        bool isRegistAxisCheckLS() const;
        const MtLineSegment& getAxisCheckLS();
        MtLineSegment& getAxisCheckLSWork();
        void setUseAxisCheckLS(const MtLineSegment& ls);
        const MtLineSegment* getUseAxisCheckLS() const;
        const MtLineSegment* getUseAxisCheckLSWithCheckAllStatus() const;
        u32 runAxisLSHitCheckProgramForPairPolygon(sCollision::SbcInfo& info);
        u32 runAxisLSHitCheckProgram(const sCollision::SbcInfo& info);
        u32 runAxisLSHitCheckBeforeMoveFunc(MtGeometry* pTraverseGeom, const sCollision::SbcInfo& info);
        u32 runAxisLSHitCheckBeforeMoveFuncMv(MtGeometry* pTraverseGeom, const sCollision::SbcInfo& info);
        u32 runAxisLSHitCheckBeforeResetFunc(MtGeometry* pTraverseGeom, const sCollision::SbcInfo& info);
        bool isRegistAxisCheckSphere() const;
        const MtSphere& getAxisCheckSphere();
        MtSphere& getAxisCheckSphereWork();
        void setUseAxisCheckSphere(const MtSphere& ls);
        const MtSphere* getUseAxisCheckSphere() const;
        const MtVector3& getAxisCheckSphereMoveVector();
        MtVector3& getAxisCheckSphereMoveVectorWork();
        void setUseAxisCheckSphereMoveVector(const MtVector3& v);
        const MtVector3* getUseAxisCheckSphereMoveVector() const;
        const MtSphere* getUseAxisCheckSphereWithCheckAllStatus() const;
        u32 runAxisSphereHitCheckProgramForPairPolygon(sCollision::SbcInfo& info);
        u32 runAxisSphereHitCheckProgram(const sCollision::SbcInfo& info);
        u32 runAxisSphereHitCheckBeforeMoveFunc(MtGeometry* pTraverseGeom, const sCollision::SbcInfo& info);
        u32 runAxisSphereHitCheckBeforeMoveFuncMv(MtGeometry* pTraverseGeom, const sCollision::SbcInfo& info);
        u32 runAxisSphereHitCheckBeforeResetFunc(MtGeometry* pTraverseGeom, const sCollision::SbcInfo& info);
        u32 runAxisHitCheckForBasicSCR(const MtGeometry& TargetGeometry);
        bool getSystemAxisHitLS(MtLineSegment& retLS);
        u32 runSystemAxisLSHitCheckProgramForPairPolygon(sCollision::SbcInfo& info);
        u32 runSystemAxisLSHitCheckProgram(const sCollision::SbcInfo& info);
        void clearAxisHitFlag();
        void adjustmentAxisHitResult();
    protected:
        f32 HitRetValue;  // offset: 0x268
        bool FlgAntiStopEnable;  // offset: 0x26c
        MtLineSegment AxisCheckLSMv;  // offset: 0x270
        const MtLineSegment* pAxisCheckLSUse;  // offset: 0x290
        MtSphere AxisCheckSphereMv;  // offset: 0x2a0
        MtVector3 AxisCheckSphereMoveVectorMv;  // offset: 0x2b0
        const MtSphere* pAxisCheckSphereUse;  // offset: 0x2c0
        const MtVector3* pAxisCheckSphereMoveVectorUse;  // offset: 0x2c8
        u32 HitAxisConvexResult;  // offset: 0x2d0
        MtPlane HitAxisContactPlane;  // offset: 0x2e0
        f32 HitAxisNearestToi;  // offset: 0x2f0
        bool FlgUpdateAxisConvexResult;  // offset: 0x2f4
        u32 HitAxisConvexResultLS;  // offset: 0x2f8
        MtPlane HitAxisContactPlaneLS;  // offset: 0x300
        f32 HitAxisNearestToiLS;  // offset: 0x310
        bool FlgUpdateAxisConvexResultSystem;  // offset: 0x314
        bool FlgJumpModeBeforeHitWall;  // offset: 0x315
        MtPlane HitPlaneJumpModeBeforeHitWall;  // offset: 0x320
        bool FlgNextGroundEnd;  // offset: 0x330
        bool FlgNextGroundDirFix;  // offset: 0x331
        MtVector3 NextGroundMoveVectorDir;  // offset: 0x340
        sCollision::SbcInfo infoAxis;  // offset: 0x350
        sCollision::SbcInfo infoAxisSystem;  // offset: 0x3e0
    public:
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfoGetAreaPoly : public sCollision::ScrCollisionInfo
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfoGetAreaPoly();
        ScrCollisionInfoGetAreaPoly(const MtVector3& _cpos, const MtVector3& _cspeed, MtGeometry* _pGeomOrg, MtGeometry* _pGeomTrans, u32 _ArraySize, bool _FlgCullingEnable, const MtVector3& _CullingNormal, f32 _CullingArea);
        virtual ~ScrCollisionInfoGetAreaPoly();
    protected:
        sCollision::GetTriangleInfo* TriArrayInfo;  // offset: 0x1e0
        MtTriangle* TriArray;  // offset: 0x1e8
        u32 ArraySize;  // offset: 0x1f0
        u32 NextSetId;  // offset: 0x1f4
        bool FlgCullingEnable;  // offset: 0x1f8
        MtVector3 CullingNormal;  // offset: 0x200
        f32 CullingArea;  // offset: 0x210
        MtGeomOBB ObbForCaseAABB;  // offset: 0x220
    public:
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfoOriginal : public sCollision::ScrCollisionInfo
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfoOriginal();
        ScrCollisionInfoOriginal(MtObject* _pCallbackOwnerObj, sCollision::CONTACT_CALLBACK_ORGFUNC _pScrHitCallback, uintptr _CallbackParam);
        ScrCollisionInfoOriginal(MtObject* _pCallbackOwnerObj, sCollision::CONTACT_CALLBACK_ORGFUNC _pScrHitCallback, sCollision::CONTACT_CALLBACK_ORGFUNC_PARTS _pScrPartsHitCallback, uintptr _CallbackParam);
        ScrCollisionInfoOriginal(MtObject* _pCallbackOwnerObj, sCollision::CONTACT_CALLBACK_ORGFUNC_FIND _pScrHitCallback, const MtVector3& _cspeed, uintptr _CallbackParam);
        ScrCollisionInfoOriginal(MtObject* _pCallbackOwnerObj, sCollision::CONTACT_CALLBACK_ORGFUNC_FIND _pScrHitCallback, sCollision::CONTACT_CALLBACK_ORGFUNC_PARTS _pScrPartsHitCallback, const MtVector3& _cspeed, uintptr _CallbackParam);
        virtual ~ScrCollisionInfoOriginal();
        u32 runCallback(const sCollision::SbcInfo& info, u32 GeometryIndex);
        u32 runCallback(const sCollision::SbcInfo& info, MtContact& HitResult, u32 GeometryIndex);
        void runCallbackParts(const sCollision::SbcInfo& info);
    protected:
        MtObject* pCallbackOwnerObj;  // offset: 0x1e0
        union
        {
        public:
            sCollision::CONTACT_CALLBACK_ORGFUNC pScrHitCallback;  // offset: 0x0
            sCollision::CONTACT_CALLBACK_ORGFUNC_FIND pScrHitCallbackFind;  // offset: 0x0
        };  // offset: 0x1e8
        sCollision::CONTACT_CALLBACK_ORGFUNC_PARTS pScrPartsHitCallback;  // offset: 0x1f8
        uintptr CallbackParam;  // offset: 0x208
    public:
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfoPreTraverse : public sCollision::ScrCollisionInfo
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfoPreTraverse();
        ScrCollisionInfoPreTraverse(const MtVector3& _cpos, const MtVector3& _cspeed, MtGeometry* _pGeomOrg, MtGeometry* _pGeomTrans);
        virtual ~ScrCollisionInfoPreTraverse();
    protected:
        sCollision::PreTraverseInfo* pTraverseInfo;  // offset: 0x1e0
        u32 TraverseInfoNum;  // offset: 0x1e8
    public:
        static MyDTI DTI;
    };
public:
    class ScrCollisionInfoFind4 : public sCollision::ScrCollisionInfo
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        ScrCollisionInfoFind4();
        ScrCollisionInfoFind4(MtGeomLineSegment4* pLs4Org, MtGeomLineSegment4* pLs4Trans, sCollision::TriangleInfo* _aTriangleInfo);
        virtual ~ScrCollisionInfoFind4();
    protected:
        MtCollisionUtil::MtSoaVector3 lsDir4;  // offset: 0x1e0
        MtCollisionUtil::MtSoaVector3 lsDirN4;  // offset: 0x210
        MtCollisionUtil::MtSoaVector1 lsLen4;  // offset: 0x240
        MtCollisionUtil::MtSoaVector1 NearestToi4;  // offset: 0x250
        sCollision::TriangleInfo* aTriangleInfo;  // offset: 0x260
    public:
        static MyDTI DTI;
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
    void setDummySCollision(u32);
    void setDummyU32(u32);
    sCollision(bool FlgSetDefaultMaterialEnum, cSystemInitializeParam* pInitializeParam);
    virtual ~sCollision();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void sync();  // vtable slot 10
    void setup();
    bool isSetuped();
    bool isMoved();
    void setEnableMoveLock();
    bool isEnableMoveLock() const;
    void lockSystem();
    bool tryLockSystem();
    void unlockSystem();
    void createPropertyShowModelSetting(MtPropertyList& s);
    void createPropertyShowModelFilter(MtPropertyList& s);
    void createPropertyMtCollisionDebugSetting(MtPropertyList& s);
    void createPropertyScrollCollisionnDebugSetting(MtPropertyList& s);
    bool isIntersect(const MtSphere& sphere, const Param& param);
    bool isIntersect(const MtLineSegment& ls, const Param& param);
    bool isIntersect(const MtCapsule& capsule, const Param& param);
    bool isIntersect(const MtAABB& aabb, const Param& param);
    bool isIntersect(const MtOBB& obb, const Param& param);
    bool isIntersect_mv(const MtSphere& sphere, const Param& param);
    bool isIntersect_mv(const MtLineSegment& ls, const Param& param);
    bool isIntersect_mv(const MtCapsule& capsule, const Param& param);
    bool isIntersect_mv(const MtAABB& aabb, const Param& param);
    bool isIntersect_mv(const MtOBB& obb, const Param& param);
    u32 findIntersection(const MtLineSegment& ls, const bool both_sides, TriangleInfo* pTriInfo, const Param& param);
    u32 findIntersectionCached(const MtLineSegment& ls, PreTraverseInfo& TraverseCached, const bool both_sides, TriangleInfo* pTriInfo, const Param& param);
    u32 findIntersectionCached(const MtLineSegment& ls, TriangleInfo* pHitCache, const bool both_sides, TriangleInfo* pTriInfo, const Param& param);
    MtCollisionUtil::MtVectorU4 findIntersection4(const MtLineSegment4& ls4, TriangleInfo* TriInfoArray4, const Param& param);
    u32 findIntersection_mv(const MtLineSegment& ls, const bool both_sides, TriangleInfo* pInfo, const Param& param);
    u32 findIntersectionCached_mv(const MtLineSegment& ls, PreTraverseInfo& TraverseCached, const bool both_sides, TriangleInfo* pInfo, const Param& param);
    u32 findIntersection(const MtRayY& rayY, TriangleInfo& HirResultOutput, const Param& param);
    u32 castConvex(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, const Param& param);
    u32 castConvex(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvexCached(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, PreTraverseInfo& TraverseInfo, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvex(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, const Param& param);
    u32 castConvex(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvexCached(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, PreTraverseInfo& TraverseInfo, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvex(MtVector3& pos, const MtVector3& old, const MtAABB& aabb, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvexCached(MtVector3& pos, const MtVector3& old, const MtAABB& aabb, PreTraverseInfo& TraverseInfo, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvex_mv(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, const Param& param);
    u32 castConvex_mv(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvexCached_mv(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, PreTraverseInfo& TraverseInfo, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvex_mv(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, const Param& param);
    u32 castConvex_mv(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, TriangleInfo* pTriInfo, const Param& param);
    u32 castConvexCached_mv(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, PreTraverseInfo& TraverseInfo, TriangleInfo* pTriInfo, const Param& param);
    u32 adjustPosition(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, const Param& param);
    u32 adjustPosition(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, const Param& param);
    u32 adjustPosition(MtVector3& pos, const MtVector3& old, const MtAABB& aabb, const Param& param);
    u32 adjustPositionCached(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, PreTraverseInfo& TraverseCache, const Param& param);
    u32 adjustPositionCached(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, PreTraverseInfo& TraverseCache, const Param& param);
    u32 adjustPosition_camera2(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, const Param& param);
    u32 adjustPosition_camera2(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, const Param& param);
    u32 adjustPosition_chara(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, const Param& param);
    u32 adjustPosition_chara(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, const Param& param);
    u32 adjustPosition_mv(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, const Param& param);
    u32 adjustPosition_mv(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, const Param& param);
    u32 adjustPosition_camera2_mv(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, const Param& param);
    u32 adjustPosition_camera2_mv(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, const Param& param);
    u32 adjustPosition_chara_mv(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, const Param& param);
    u32 adjustPosition_chara_mv(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, const Param& param);
    u32 getAdjPosCorrectedNum();
    u32 getAreaPolygons(MtAABB& GetAreaAABB, GetTriangleInfo* ResultArray, u32 ArrayNum, const Param& param);
    u32 getAreaPolygons(MtGeometry& CheckArea, GetTriangleInfo* ResultArray, u32 ArrayNum, const Param& param);
    u32 getAreaPolygons(MtGeometry& CheckArea, GetTriangleInfo* ResultArray, u32 ArrayNum, const ParamGetPolygons& param);
    u32 getAreaPolygons(MtGeometry& CheckArea, MtTriangle* ResultArray, u32 ArrayNum, const Param& param);
    u32 getAreaPolygons(MtGeometry& CheckArea, MtTriangle* ResultArray, u32 ArrayNum, const ParamGetPolygons& param);
    u32 correctTraverse(MtGeometry& PreTraverseConvex, PreTraverseInfo& PreTraverseInfoOut, const Param& param);
    u32 originalScrCollision(const MtGeometry& CheckArea, const Param& param, MtObject* pCallbackOwnerObj, CONTACT_CALLBACK_ORGFUNC ScrHitCallback, uintptr CallbackParam);
    u32 originalScrCollision(const MtGeometry& CheckArea, const Param& param, MtObject* pCallbackOwnerObj, CONTACT_CALLBACK_ORGFUNC ScrHitCallback, CONTACT_CALLBACK_ORGFUNC_PARTS ScrPartsHitCallback, uintptr CallbackParam);
    u32 originalScrCollisionCached(const MtGeometry& CheckArea, PreTraverseInfo& TraverseCached, const Param& param, MtObject* pCallbackOwnerObj, CONTACT_CALLBACK_ORGFUNC ScrHitCallback, uintptr CallbackParam);
    u32 originalScrCollisionCached(const MtGeometry& CheckArea, PreTraverseInfo& TraverseCached, const Param& param, MtObject* pCallbackOwnerObj, CONTACT_CALLBACK_ORGFUNC ScrHitCallback, CONTACT_CALLBACK_ORGFUNC_PARTS ScrPartsHitCallback, uintptr CallbackParam);
    u32 originalScrCollisionFind(const MtGeometry& CheckArea, const MtVector3& MoveVector, const Param& param, MtObject* pCallbackOwnerObj, CONTACT_CALLBACK_ORGFUNC_FIND ScrHitCallback, uintptr CallbackParam);
    u32 originalScrCollisionFind(const MtGeometry& CheckArea, const MtVector3& MoveVector, const Param& param, MtObject* pCallbackOwnerObj, CONTACT_CALLBACK_ORGFUNC_FIND ScrHitCallback, CONTACT_CALLBACK_ORGFUNC_PARTS ScrPartsHitCallback, uintptr CallbackParam);
    u32 originalScrCollisionFindCached(const MtGeometry& CheckArea, const MtVector3& MoveVector, PreTraverseInfo& TraverseCached, const Param& param, MtObject* pCallbackOwnerObj, CONTACT_CALLBACK_ORGFUNC_FIND ScrHitCallback, uintptr CallbackParam);
    u32 originalScrCollisionFindCached(const MtGeometry& CheckArea, const MtVector3& MoveVector, PreTraverseInfo& TraverseCached, const Param& param, MtObject* pCallbackOwnerObj, CONTACT_CALLBACK_ORGFUNC_FIND ScrHitCallback, CONTACT_CALLBACK_ORGFUNC_PARTS ScrPartsHitCallback, uintptr CallbackParam);
    u32 repairConvexSinkIn(MtVector3& pos, const MtSphere& sphere, const MtVector3& UnTargetPolygonDir, const Param& param);
    u32 repairConvexSinkIn(MtVector3& pos, const MtCapsule& capsule, const MtVector3& UnTargetPolygonDir, const Param& param);
    bool registResourceWithConvert(SBC_HANDLE& handle_output, rCollision* * ppResourceOutput, MT_CTSTR FileName, u32 type, u8 group, bool FlgForceRegist, bool FlgEnableMove);
    SBC_HANDLE registResource(rCollision* pResource, u32 type, u8 group, bool FlgForceRegist, bool FlgEnableMove);
    SBC_HANDLE_HF registResource(rCollisionHeightField* pResourceHF, u32 type, u8 group);
    cSbcSkinMesh::cRegisterInfo* registResource(uDynamicSbc& DynamicSbc);
    SbcObject::cRegisterInfo* registerScrollCollisionNode(uScrollCollisionGeometry& node);
    void reserveRegistResource(rCollision* pResource, SBC_HANDLE& OutputSbcHandle, u32 type, u8 group);
    void unregistResourceFromIndex(u32 index);
    void unregistResource(SBC_HANDLE SbcHandle);
    void unregistResourceHeightField(SBC_HANDLE_HF handle);
    void unregistResource(cSbcSkinMesh::cRegisterInfo& DynamicSbcRegisterInfo);
    void unregistResourceAll();
    void reserveUnregistResource(SBC_HANDLE handle);
    rCollision* getResource(u32 index);
    rCollision* getResourceFromHandle(SBC_HANDLE SbcHandle);
    rCollision* getData(u32 index);
    rCollision* getDataFromHandle(SBC_HANDLE SbcHandle);
    u32 getRegistResorceNum();
    void setSlopeDegree(f32 deg);
    f32 getSlopeDegree();
    f32 getSlopeSin();
    void setWallDegreeLegacy(f32 deg);
    void setWallDegree(f32 deg);
    f32 getWallDegree();
    f32 getWallSin();
    void setCeilingDegree(f32 deg);
    f32 getCeilingDegree();
    f32 getCeilingSin();
    void setGroundDegreeByRangeF(const MtRangeF& rangeF);
    MtRangeF getGroundDegreeByRangeF();
    void setSlopeDegreeByRangeF(const MtRangeF& rangeF);
    MtRangeF getSlopeDegreeByRangeF();
    void setWallDegreePlusByRangeF(const MtRangeF& rangeF);
    MtRangeF getWallDegreePlusByRangeF();
    void setWallDegreeMinusByRangeF(const MtRangeF& rangeF);
    MtRangeF getWallDegreeMinusByRangeF();
    void setCeilingDegreeByRangeF(const MtRangeF& rangeF);
    MtRangeF getCeilingDegreeByRangeF();
    void setDefaultAttributeForceGround(u32 attr);
    u32 getDefaultAttributeForceGround();
    void setDefaultAttributeForceSlope(u32);
    void setDefaultAttributeForceWall(u32 attr);
    u32 getDefaultAttributeForceSlope();
    u32 getDefaultAttributeForceWall();
    void setDisp(SBC_HANDLE SbcHandle, bool bDisp);
    bool isDisp(SBC_HANDLE SbcHandle);
    void setDispAll(bool bDisp);
    void setDispAllTrue();
    void setDispAllFalse();
    void setActive(SBC_HANDLE SbcHandle, bool bActive);
    bool getActive(SBC_HANDLE SbcHandle);
    void setActiveWithIndex(u32 SbcIndex, bool bActive);
    bool getActiveWithIndex(u32 SbcIndex);
    void setActiveAll(bool bActive);
    void setActiveAllTrue();
    void setActiveAllFalse();
    void setType(SBC_HANDLE SbcHandle, u32 NewType);
    u32 getType(SBC_HANDLE SbcHandle);
    void setTypeWithIndex(u32 SbcIndex, u32 NewType);
    u32 getTypeWithIndex(u32 SbcIndex);
    void setGroup(SBC_HANDLE, u8);
    u32 getGroup(SBC_HANDLE);
    u32 getGroupIndex(SBC_HANDLE);
    void setGroupWithIndex(u32, u8);
    u32 getGroupWithIndex(u32);
    bool getPartsActive(SBC_HANDLE TargetSbcHandle, u32 TargetPartsIndex);
    void setPartsActive(SBC_HANDLE TargetSbcHandle, u32 TargetPartsIndex, bool FlagNextActive);
    bool getPartsActiveID(SBC_HANDLE TargetSbcHandle, u32 TargetResourcePartsID);
    void setPartsActiveID(SBC_HANDLE TargetSbcHandle, u32 TargetResourcePartsID, bool FlagNextActive);
    bool getPartsActiveByIndex(u32 TargetSbcIndex, u32 TargetPartsIndex);
    void setPartsActiveByIndex(u32 TargetSbcIndex, u32 TargetPartsIndex, bool FlagNextActive);
    bool getPartsActiveByIndexWithID(u32 TargetSbcIndex, u32 TargetResourcePartsID);
    void setPartsActiveByIndexWithID(u32 TargetSbcIndex, u32 TargetResourcePartsID, bool FlagNextActive);
    bool getPartsActiveBySbcInfo(SbcInfo& TargetSbcInfo);
    void setPartsActiveBySbcInfo(SbcInfo& TargetSbcInfo, bool FlagNextActive);
    bool setMatrixById(SBC_HANDLE SbcHandle, u32 TargetRPartsID, MtMatrix* pSetMatrix, bool reset);
    bool setMatrixByIdRotTransQt(SBC_HANDLE SbcHandle, u32 TargetRPartsID, const MtVector3* pTrans, const MtQuaternion* pQt, bool reset);
    bool setMatrixByIdRotTransXYZ(SBC_HANDLE SbcHandle, u32 TargetRPartsID, const MtVector3* pTrans, const MtVector3* pRotateRadian, bool reset);
    bool setMatrixByIdWithIndex(u32 SbcIndex, u32 TargetRPartsID, MtMatrix* pSetMatrix, bool reset);
    bool setMatrixByIdWithIndexRotTransQt(u32 SbcIndex, u32 TargetRPartsID, const MtVector3* pTrans, const MtQuaternion* pQt, bool reset);
    bool setMatrixByIdWithIndexRotTransXYZ(u32 SbcIndex, u32 TargetRPartsID, const MtVector3* pTrans, const MtVector3* pRotateRadian, bool reset);
    bool setMatrixByIndex(SBC_HANDLE SbcHandle, u32 PartsIndex, MtMatrix* pSetMatrix, bool reset);
    bool setMatrixByIndexRotTransQt(SBC_HANDLE SbcHandle, u32 PartsIndex, const MtVector3* pTrans, const MtQuaternion* pQt, bool reset);
    bool setMatrixByIndexRotTransXYZ(SBC_HANDLE SbcHandle, u32 PartsIndex, const MtVector3* pTrans, const MtVector3* pRotateRadian, bool reset);
    bool setMatrixByIndexWithIndex(u32 SbcIndex, u32 PartsIndex, MtMatrix* pmat, bool reset);
    bool setMatrixByIndexWithIndexRotTransQt(u32 SbcIndex, u32 PartsIndex, const MtVector3* pTrans, const MtQuaternion* pQt, bool reset);
    bool setMatrixByIndexWithIndexRotTransXYZ(u32 SbcIndex, u32 PartsIndex, const MtVector3* pTrans, const MtVector3* pRotateRadian, bool reset);
    bool setMatrixAll(SBC_HANDLE SbcHandle, MtMatrix* pmat, bool reset);
    bool setMatrixAllRotTransQt(SBC_HANDLE SbcHandle, const MtVector3* pTrans, const MtQuaternion* pQt, bool reset);
    bool setMatrixAllRotTransXYZ(SBC_HANDLE SbcHandle, const MtVector3* pTrans, const MtVector3* pRotateRadian, bool reset);
    bool setMatrixAllByIndex(u32 SbcIndex, MtMatrix* pmat, bool reset);
    bool setMatrixAllByIndexRotTransQt(u32 SbcIndex, const MtVector3* pTrans, const MtQuaternion* pQt, bool reset);
    bool setMatrixAllByIndexRotTransXYZ(u32 SbcIndex, const MtVector3* pTrans, const MtVector3* pRotateRadian, bool reset);
    bool setMatrixBySbcInfo(SbcInfo& info, MtMatrix* pmat, bool reset);
    bool setMatrixBySbcInfoRotTransQt(SbcInfo& info, const MtVector3* pTrans, const MtQuaternion* pQt, bool reset);
    bool setMatrixBySbcInfoRotTransXYZ(SbcInfo& info, const MtVector3* pTrans, const MtVector3* pRotateRadian, bool reset);
    bool setMatrixByTriangleInfo(TriangleInfo& tri_info, MtMatrix* pmat, bool reset);
    bool setMatrixByTriangleInfoRotTransQt(TriangleInfo& tri_info, const MtVector3* pTrans, const MtQuaternion* pQt, bool reset);
    bool setMatrixByTriangleInfoRotTransXYZ(TriangleInfo& tri_info, const MtVector3* pTrans, const MtVector3* pRotateRadian, bool reset);
    bool reserveMatrixById(SBC_HANDLE SbcHandle, u32 PartsID, const MtMatrix& MoveMat, bool reset);
    bool reserveMatrixByIdRotTransQt(SBC_HANDLE SbcHandle, u32 PartsID, const MtVector3& trans, const MtQuaternion& qt, bool reset);
    bool reserveMatrixByIdWithIndex(u32 SbcIndex, u32 PartsID, const MtMatrix& MoveMat, bool reset);
    bool reserveMatrixByIdWithIndexRotTransQt(u32 SbcIndex, u32 PartsID, const MtVector3& trans, const MtQuaternion& qt, bool reset);
    bool reserveMatrixByIdWithIndexRotTransXYZ(u32 SbcIndex, u32 PartsID, const MtVector3& trans, const MtVector3& RotateRadian, bool reset);
    bool reserveMatrixByIndex(SBC_HANDLE handle, u32 PartsIndex, const MtMatrix& MoveMat, bool reset);
    bool reserveMatrixByIndexRotTransQt(SBC_HANDLE SbcHandle, u32 PartsIndex, const MtVector3& trans, const MtQuaternion& qt, bool reset);
    bool reserveMatrixByIndexRotTransXYZ(SBC_HANDLE SbcHandle, u32 PartsIndex, const MtVector3& trans, const MtVector3& RotateRadian, bool reset);
    bool reserveMatrixByIndexWithIndex(u32 SbcIndex, u32 PartsIndex, const MtMatrix& MoveMat, bool reset);
    bool reserveMatrixByIndexWithIndexRotTransQt(u32 SbcIndex, u32 PartsIndex, const MtVector3& trans, const MtQuaternion& qt, bool reset);
    bool reserveMatrixByIndexWithIndexRotTransXYZ(u32 SbcIndex, u32 PartsIndex, const MtVector3& trans, const MtVector3& RotateRadian, bool reset);
    bool reserveMatrixAll(SBC_HANDLE SbcHandle, const MtMatrix& MoveMat, bool reset);
    bool reserveMatrixAllRotTransQt(SBC_HANDLE SbcHandle, const MtVector3& trans, const MtQuaternion& qt, bool reset);
    bool reserveMatrixAllRotTransXYZ(SBC_HANDLE SbcHandle, const MtVector3& trans, const MtVector3& RotateRadian, bool reset);
    bool reserveMatrixAllByIndex(u32 SbcIndex, const MtMatrix& MoveMat, bool reset);
    bool reserveMatrixAllByIndexRotTransQt(u32 SbcIndex, const MtVector3& trans, const MtQuaternion& qt, bool reset);
    bool reserveMatrixAllByIndexRotTransXYZ(u32 SbcIndex, const MtVector3& trans, const MtVector3& RotateRadian, bool reset);
    bool reserveMatrixBySbcInfo(SbcInfo& info, const MtMatrix& MoveMat, bool reset);
    bool reserveMatrixBySbcInfoRotTransQt(SbcInfo& info, const MtVector3& trans, const MtQuaternion& qt, bool reset);
    bool reserveMatrixBySbcInfoRotTransXYZ(SbcInfo& info, const MtVector3& trans, const MtVector3& RotateRadian, bool reset);
    bool reserveMatrixByTriangleInfo(TriangleInfo& info, const MtMatrix& MoveMat, bool reset);
    bool reserveMatrixByTriangleInfoRotTransQt(TriangleInfo& info, const MtVector3& trans, const MtQuaternion& qt, bool reset);
    bool reserveMatrixByTriangleInfoRotTransXYZ(TriangleInfo& info, const MtVector3& trans, const MtVector3& RotateRadian, bool reset);
    bool reserveResetMatrixById(SBC_HANDLE handle, u32 PartsID);
    bool reserveResetMatrixByIndex(SBC_HANDLE SbcHandle, u32 PartsIndex);
    bool reserveResetMatrixByIdWithIndex(u32 SbcIndex, u32 PartsID);
    bool reserveResetMatrixByIndexWithIndex(u32 SbcIndex, u32 PartsIndex);
    bool reserveResetMatrixAll(SBC_HANDLE SbcHandle);
    bool reserveResetMatrixAllByIndex(u32 SbcIndex);
    bool reserveResetMatrixBySbcInfo(SbcInfo& info);
    bool reserveResetMatrixByTriangleInfo(TriangleInfo& tri_info);
    void updateSbc();
    bool isPartsMoveById(SBC_HANDLE SbcHandle, u32 TargetRPartsID);
    bool getMatrixById(SBC_HANDLE SbcHandle, u32 id, MtMatrix* pOutputMatrix);
    bool getMatrixByIndex(SBC_HANDLE SbcHandle, u32 PartsIndex, MtMatrix* pmat);
    bool getMatrixByIdWithIndex(u32 SbcIndex, u32 id, MtMatrix* pmat);
    bool getMatrixByIndexWithIndex(u32 SbcIndex, u32 PartsIndex, MtMatrix* pmat);
    bool getMatrixBySbcInfo(SbcInfo& info, MtMatrix* pmat);
    bool getMatrixByTriangleInfo(TriangleInfo& tri_info, MtMatrix* pmat);
    void getRelativeMatrixById(SBC_HANDLE SbcHandle, u32 TargetRPartsID, MtMatrix* pOutputMatrix);
    void getRelativeMatrixByIndex(SBC_HANDLE SbcHandle, u32 PartsIndex, MtMatrix* pOutputMatrix);
    void getRelativeMatrixByIndexWithIndex(u32 SbcIndex, u32 PartsIndex, MtMatrix* pmat);
    void getRelativeMatrixBySbcInfo(SbcInfo& info, MtMatrix* pmat);
    void getRelativeMatrixByTriangleInfo(TriangleInfo& tri_info, MtMatrix* pmat);
    cDynamicBVHCollision& getScrBroadPhaseDBVTStopForSbc(u32);
    cDynamicBVHCollision& getScrBroadPhaseDBVTStopForSbcParts(u32);
    cDynamicBVHCollision& getScrBroadPhaseDBVTMoveForSbcParts(u32 GroupIndex);
    cDynamicBVHCollision& getScrBroadPhaseDBVTStopForBasicSCR(u32);
    cDynamicBVHCollision& getScrBroadPhaseDBVTMoveForBasicSCR(u32 GroupIndex);
    Sbc* getSbc(u32 SbcIndex);
    Sbc* getSbcFromHandle(SBC_HANDLE SbcHandle);
    Sbc* getSbcFast(u32 SbcIndex);
    Sbc* getSbcFastFromHandle(SBC_HANDLE);
    u32 getSbcSize();
    u32 getSbcNum() const;
    u32 getSbcPartsNum(u32 SbcIndex);
    u32 getSbcPartsNumFromHandle(SBC_HANDLE SbcHandle);
    u32 getSbcPartsNumFast(u32);
    u32 getSbcPartsNumFastFromHandle(SBC_HANDLE);
    void setSbcOwner(MtObject* pOwnerObj, u32 index);
    void setSbcOwnerFromHandle(MtObject* pOwnerObj, SBC_HANDLE handle);
    MtObject* getSbcOwner(u32 index);
    MtObject* getSbcOwnerFromHandle(SBC_HANDLE handle);
    void setSbcDisp(bool FlgNextDispSetting, u32 TargetSbcIndex);
    bool isSbcDisp(u32 TargetSbcIndex);
    void setSbcDispFromHandle(bool FlgNextDispSetting, SBC_HANDLE TargetSbcHandle);
    bool isSbcDispFromHandle(SBC_HANDLE TargetSbcHandle);
    void setSbcActive(bool FlgNextActiveSetting, u32 TargetSbcIndex);
    bool isSbcActive(u32 TargetSbcIndex);
    void setSbcActiveFromHandle(bool FlgNextActiveSetting, SBC_HANDLE TargetSbcHandle);
    bool isSbcActiveFromHandle(SBC_HANDLE TargetSbcHandle);
    void setSbcType(nCollision::cScrCommonFilter::TYPE NewFilterType, u32 TargetSbcIndex);
    u32 getSbcType(u32 TargetSbcIndex);
    void setSbcTypeFromHandle(nCollision::cScrCommonFilter::TYPE NewFilterType, SBC_HANDLE TargetSbcHandle);
    u32 getSbcTypeFromHandle(SBC_HANDLE TargetSbcHandle);
    void setSbcGroupByBit(u32 NewFilterGroupBit, u32 TargetSbcIndex);
    u32 getSbcGroupByBit(u32 TargetSbcIndex);
    void setSbcGroupByIndex(nCollision::cScrCommonFilter::GROUP_REGIST NewFilterGroup, u32 TargetSbcIndex);
    u32 getSbcGroupByIndex(u32 TargetSbcIndex);
    void setSbcGroupByBitFromHandle(u32 NewFilterGroupBit, SBC_HANDLE TargetSbcHandle);
    u32 getSbcGroupByBitFromHandle(SBC_HANDLE TargetSbcHandle);
    void setSbcGroupByIndexFromHandle(nCollision::cScrCommonFilter::GROUP_REGIST NewFilterGroup, SBC_HANDLE TargetSbcHandle);
    u32 getSbcGroupByIndexFromHandle(SBC_HANDLE TargetSbcHandle);
    MtObject* registSbcUserData(MtObject* pUserDataPtr, u32 TargetSbcIndex, bool FlgAutoDelete);
    MtObject* registSbcUserData(const MtDTI& UserDataDTI, u32 TargetSbcIndex, bool FlgAutoDelete);
    MtObject* registSbcUserDataFromHandle(MtObject* pUserDataPtr, SBC_HANDLE TargetSbcHandle, bool FlgAutoDelete);
    MtObject* registSbcUserDataFromHandle(const MtDTI& UserDataDTI, SBC_HANDLE TargetSbcHandle, bool FlgAutoDelete);
    void unregistSbcUserData(u32 TargetSbcIndex);
    void unregistSbcUserDataFromHandle(SBC_HANDLE TargetSbcHandle);
    MtObject* getSbcUserData(u32 TargetSbcIndex);
    MtObject* getSbcUserDataFromHandle(SBC_HANDLE TargetSbcHandle);
    bool isAutoDeleteSbcUserData(u32 TargetSbcIndex);
    bool isAutoDeleteSbcUserDataFromHandle(SBC_HANDLE TargetSbcHandle);
    void setAutoDeleteSbcUserData(bool FlgNextAutoDelete, u32 TargetSbcIndex);
    void setAutoDeleteSbcUserDataFromHandle(SBC_HANDLE TargetSbcHandle, bool FlgNextAutoDelete);
    u32 getSbcObjectRegistNum();
    uScrollCollisionGeometry* getSbcObjectRegistNode(u32 NodeIndex, u32 TypeMask, u32 GroupMask);
    bool isTargetSbcObjectRegistNode(u32 NodeIndex, u32 TypeMask, u32 GroupMask);
    MtGeomConvex* getSbcObjectConvexFromRegistNode(u32 NodeIndex, u32 ConvexIndex, u32 TypeMask, u32 TargetAttribute, u32 GroupMask);
    u32 getSbcObjectConvexNumFromRegistNode(u32 NodeIndex, u32 TypeMask, u32 GroupMask);
    const MtMatrix& getSbcObjectConvexMatrixFromRegistNode(u32 NodeIndex, u32 TypeMask, u32 GroupMask);
    f32 getTraverseThresholdRayLengthSq();
    f32 getTraverseThresholdRayLength();
    void setTraverseThresholdRayLengthSq(f32);
    void setTraverseThresholdRayLength(f32);
    bool isDeleteSbc_OnUnregistResource() const;
    void setDeleteSbc_OnUnregistResource(bool IsNewEnable);
    u32 getAdjustContactType(u32 mode, f32 NormalY);
    u32 getAdjustContactType(u32, const MtVector3&);
    u32 getAdjustContactTypeWithForceAttribute(u32 mode, f32 NormalY, u32 ScrollAttribute);
    u32 getAdjustContactTypeWithForceAttribute(u32 mode, const MtVector3& normal, u32 ScrollAttribute);
    u32 getContactType(f32);
    bool isContactTypeGround(f32 NormalY);
    bool isContactTypeSlope(f32 NormalY);
    bool isContactTypeWall(f32 NormalY);
    virtual bool isTargetPolygon(u32 TargetPolygonAttribute, const rCollision::MaterialInfo& RSbcPolygonMaterial, u32 scr_type);  // vtable slot 11
    // Address: 0x01bac060 - 0x01bac061 (1 bytes)
    virtual void replaceAttribute(rCollision::MaterialInfo& material) {}  // vtable slot 12
    static u32 convertSbcHandle2SbcIndex(SBC_HANDLE handle);
    static u32 convertSbcIndex2SbcHandle(u32 SbcIndex);
    static f32 convertTOIZero2One(f32 toi, f32 len);
    static void getRSbcTriangleFromSbcInfo(MtTriangle& tri, const SbcInfo& info);
    static void getRSbcTriangleFromSbcInfoW(MtTriangle& tri, const SbcInfo& info);
    static void getRSbcTriangleFromSbcInfoNow(MtTriangle&, const SbcInfo&);
    static void getRSbcTriangleFromSbcInfo(MtVector3& p0, MtVector3& p1, MtVector3& p2, const SbcInfo& info);
    static void getRSbcTriangleFromSbcInfoW(MtVector3& p0, MtVector3& p1, MtVector3& p2, const SbcInfo& info);
    static void getRSbcTriangleFromSbcInfoNow(MtVector3&, MtVector3&, MtVector3&, const SbcInfo&);
    static void getRSbcTriangleFromSbcInfoOldW(MtVector3&, MtVector3&, MtVector3&, const SbcInfo&);
    static void getRSbcTriangleFromTriInfo(MtTriangle&, const TriangleInfo&);
    static void getRSbcTriangleFromTriInfoW(MtTriangle&, const TriangleInfo&);
    static void getRSbcTriangleFromTriInfoNow(MtTriangle&, const TriangleInfo&);
    static void getRSbcTriangleFromTriInfo(MtVector3&, MtVector3&, MtVector3&, const TriangleInfo&);
    static void getRSbcTriangleFromTriInfoW(MtVector3&, MtVector3&, MtVector3&, const TriangleInfo&);
    static void getRSbcTriangleFromTriInfoNow(MtVector3&, MtVector3&, MtVector3&, const TriangleInfo&);
    static u32 getRSbcTriangleAttributeFromResource(const rCollision*, const rCollision::Triangle*);
    static u32 getRSbcTriangleUserAttributeFromResource(const rCollision*, const rCollision::Triangle*, u32);
    static u32 getRSbcTriangleAttributeFromSbcInfo(const SbcInfo&);
    static u32 getRSbcTriangleUserAttributeFromSbcInfo(const SbcInfo&, u32);
    static u32 getRSbcTriangleOrgAttributeFromSbcInfo(const SbcInfo&, u32);
    static u32 getRSbcTriangleAttributeFromTriInfo(const TriangleInfo&);
    static u32 getRSbcTriangleUserAttributeFromTriInfo(const TriangleInfo&, u32);
    static u32 getRSbcTriangleOrgAttributeFromTriInfo(const TriangleInfo&, u32);
    static bool isCheckEdgeRSbcTriangleFromSbcInfo(u32, const SbcInfo&);
    static bool isCheckEdgeRSbcTriangleFromTriInfo(u32, const TriangleInfo&);
    static u32* getRSbcTriangleAttributePtrFromSbcInfo(SbcInfo&);
    static u32* getRSbcTriangleUserAttributePtrFromSbcInfo(SbcInfo&, u32);
    static u32* getRSbcTriangleAttributePtrFromTriInfo(TriangleInfo&);
    static u32* getRSbcTriangleUserAttributePtrFromTriInfo(TriangleInfo&, u32);
    static const MtVector3 getRSbcTriangleNormalFromSbcInfo(const SbcInfo& info);
    static MtVector3 getRSbcTriangleNormalFromSbcInfoW(const SbcInfo& info);
    static MtVector3 getRSbcTriangleNormalFromSbcInfoNow(const SbcInfo&);
    static const MtVector3 getRSbcTriangleNormalFromTriInfo(const TriangleInfo&);
    static const MtVector3 getRSbcTriangleNormalFromTriInfoW(const TriangleInfo&);
    static MtVector3 getRSbcTriangleNormalFromTriInfoNow(const TriangleInfo&);
    cSbcHeightField::cHeightField* getSbcHeightFieldByIndex(u32 SbcHeightFieldIndex);
    cSbcHeightField::cHeightField* getSbcHeightFieldByHandle(SBC_HANDLE_HF SbcHeightFieldHandle);
    u32 getSbcHeightFieldNum();
    Collider* getCollider();
    void moveObjectCollision();
    bool isRunObjectCollisionInSystem() const;
    void setRunObjectCollisionInSystem(bool);
    void entryColliderNode(Node* pRegistPassiveNode, u32 type);
    void enumColliderContact(Node* pRegistActiveNode, u32 TargetNodeListType, MtObject* pCallbackOwner, OBJ_FUNC pContactCallback, u32 UserParam, u32 ContactType);
    void enumColliderContact(Node*, u32, MtObject*, OBJ_FUNC, OBJ_FILTER_FUNC_NODE, OBJ_FILTER_FUNC_GEOMETRY, u32, u32);
    void enumColliderContactDirect(Node& HitCheckNode, u32 TargetNodeListType, u32 TargetColliderPhaseIndex, MtObject* pCallbackOwner, OBJ_FUNC pContactCallback, u32 UserParam, u32 ContactType);
    void enumColliderContactDirect(Node&, u32, u32, MtObject*, OBJ_FUNC, OBJ_FILTER_FUNC_NODE, OBJ_FILTER_FUNC_GEOMETRY, u32, u32);
    bool enumColliderContactDirect(const MtGeomConvex&, u32, u32, MtObject*, OBJ_FUNC_OUTSIDE, void*, u32, u32, u32, const MtVector3&);
    bool enumColliderContactDirect(const MtGeomConvex&, u32, u32, MtObject*, OBJ_FUNC_OUTSIDE, nCollision::OBJ_FILTER_FUNC_NODE_PASSIVE, nCollision::OBJ_FILTER_FUNC_GEOMETRY_PASSIVE, void*, u32, u32, u32, const MtVector3&);
    ColliderPassiveNodeInfo* addColliderContinuousEntryNode(Node*, u32, u32);
    ColliderActiveNodeInfo* addColliderContinuousEnumContact(Node*, u32, u32, MtObject*, OBJ_FUNC, u32, u32);
    ColliderActiveNodeInfo* addColliderContinuousEnumContact(Node*, u32, u32, MtObject*, OBJ_FUNC, OBJ_FILTER_FUNC_NODE, OBJ_FILTER_FUNC_GEOMETRY, u32, u32);
    void removeColliderContinuousEntryNode(ColliderPassiveNodeInfo*);
    void removeColliderContinuousEnumContact(ColliderActiveNodeInfo*);
    u32 getColliderUsingTypeID();
    u32 getNodeListNum();
    void setNodeSize(u32 type, u32 entrySize, u32 requestsize);
    void resetNodeSize();
    u32 getColliderRunCount() const;
    u32 getColliderRunCountMax() const;
    void setDefaultMaterial(u32 attr);
    u32 getDefaultMaterial();
    static void drawGeomConvex(MtGeometry& geom, MtColor color, const MtVector3& offset);
    virtual MtColor getDrawColorTriangleEdge(rCollision* pRSbc, const rCollision::PartsInfo* pRPartsInfo, const rCollision::Triangle* pTriangle);  // vtable slot 13
    virtual MtColor getDrawColorTriangleFill(rCollision* pRSbc, const rCollision::PartsInfo* pRPartsInfo, const rCollision::Triangle* pTriangle);  // vtable slot 14
    MtColor getDrawColorFromResource(rCollision* pRSbc, const rCollision::PartsInfo* pPartsInfo, const rCollision::Triangle* pTriangle);
    void setDebugDispTemplate(bool& dest, bool src);
    void getRegistResorceTotalAABB(MtAABB& bv, bool FlgCheckMove);
    void createModalDialogShowModelSetting();
    void createModalDialogShowModelFilterSetting();
    void createModalDialogMtCollisionDebugSetting();
    void createModalDialogDebugDrawScrollCollision();
    void outputCSVSbcMoveStatusForDDON();
    void debugDrawLineFunc(const MtVector3& v1, const MtVector3& v2, MtColor c, bool ztest);
    void debugDrawRectFunc(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2, const MtVector3& p3, MtColor c, bool ztest);
    void debugDrawFillTriangleFunc(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2, MtColor c, bool ztest);
    void debugDrawFillRectFunc(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2, const MtVector3& p3, MtColor ColorPlane, MtColor ColorEdge, bool ztest);
    void debugDrawFillRectFuncE(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2, const MtVector3& p3, MtColor ColorPlane, MtColor* ColorEdge, bool ztest);
    void debugDrawFillRectFuncP(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2, const MtVector3& p3, MtColor* ColorPlane, MtColor ColorEdge, bool ztest);
    void debugDrawFillRectFuncPE(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2, const MtVector3& p3, MtColor* ColorPlane, MtColor* ColorEdge, bool ztest);
    MtRay getMouseCursorPickRay();
    bool getListDrawCustomPropertyString(MtString& output, const MtProperty& prop, bool FlgShortPath);
    void drawSbcAll(uintptr param);
    void setDebugDisp(bool bDisp);
    void setDebugDispTriangle(bool bDisp);
    bool getDebugDisp();
    bool getDebugDispTriangle();
    bool getDebugDispTotalAABB();
    void setDebugDispTotalAABB(bool bDisp);
    bool getDebugDispDefaultColor() const;
    void setDebugDispDefaultColor(bool bDisp);
    bool isEnableShowModelColorFromResource() const;
    void setEnableShowModelColorFromResource(bool FlgEnable);
    void callbackPolygonColorEdit();
    u32 getDebugDispDrawMode();
    void setDebugDispDrawMode(u32 mode);
    bool isDebugDispIntersection();
    void setDebugDispIntersection(bool bDisp);
    bool isDebugDispIntersectionFunction(u32 index);
    void setDebugDispIntersectionFunction(bool FlagEnable, u32 index);
    bool isDebugDispIntersectionTriangle();
    void setDebugDispIntersectionTriangle(bool bDisp);
    bool isDebugDispHitTriangle();
    void setDebugDispHitTriangle(bool bDisp);
    bool isEnableDebugDrawZTest();
    bool setEnableDebugDrawZTest();
    bool isEnableDebugDrawAlpha();
    void setEnableDebugDrawAlpha(bool bAlpha);
    bool isDebugDispColliderIntersectionBase();
    void setDebugDispColliderIntersectionBase(bool bDisp);
    bool isDebugDispColliderIntersectionTarget();
    void setDebugDispColliderIntersectionTarget(bool bDisp);
    bool isDebugDispColliderIntersectionHit();
    void setDebugDispColliderIntersectionHit(bool bDisp);
    u32 getScrColGeomAttributeFixParam();
    void setScrColGeomAttributeFixParam(u32 param);
    u32 getScrColGeomUserAttr0FixParam();
    void setScrColGeomUserAttr0FixParam(u32 param);
    u32 getScrColGeomUserAttr1FixParam();
    void setScrColGeomUserAttr1FixParam(u32 param);
    u32 getScrColGeomUserAttr2FixParam();
    void setScrColGeomUserAttr2FixParam(u32 param);
    u32 getScrColGeomUserAttr3FixParam();
    void setScrColGeomUserAttr3FixParam(u32 param);
    MtArray* getScrColGeomAttributeFlagArrayPtr();
    MtArray* getScrColGeomUserAttr0FlagArrayPtr();
    MtArray* getScrColGeomUserAttr1FlagArrayPtr();
    MtArray* getScrColGeomUserAttr2FlagArrayPtr();
    MtArray* getScrColGeomUserAttr3FlagArrayPtr();
    void registDebugDispMaskElement_MaterialAttribute(MT_CTSTR name, u32 MaskBits);
    void registDebugDispMaskElement_MaterialUserAttr0(MT_CTSTR name, u32 MaskBits);
    void registDebugDispMaskElement_MaterialUserAttr1(MT_CTSTR name, u32 MaskBits);
    void registDebugDispMaskElement_MaterialUserAttr2(MT_CTSTR name, u32 MaskBits);
    void registDebugDispMaskElement_MaterialUserAttr3(MT_CTSTR name, u32 MaskBits);
    void registDebugDispMaskElement_TriangleAttribute0(MT_CTSTR name, u32 MaskBits);
    void registDebugDispMaskElement_TriangleAttribute1(MT_CTSTR name, u32 MaskBits);
    void startOutputAllScrCollision();
    bool isEnableScrSubProfiler() const;
    void setEnableScrSubProfiler(bool FlgEnable);
    void beginSubProfiler(bool FlgTimeCheckEnable);
    void endSubProfiler(bool FlgTraceResult);
    u32 getSubProfilerTimeAll() const;
    u32 getSubProfilerTime(PROFILE_ID TargetID) const;
    u32 getSubProfilerUseCount(PROFILE_ID TargetID) const;
    u32 getSubProfilerHitCount(PROFILE_ID TargetID) const;
    MT_CTSTR getProfilerName(PROFILE_ID TargetID) const;
    void* memAlloc(size_t s);
    void memFree(void* padr);
    size_t memSize(void*);
protected:
    bool isRegistMoveSCR(u32 TargetGroupBit);
    u32 isEnableMoveScr(const MtGeomAABB& CheckAreaAABB, const Param& param);
    u32 callbackDBVT_EnableAllMoveScrAABB(MtGeometry& TraverseGeometry, MtObject* pLeaf, const void* pUserPtr);
    u32 callbackDBVT_EnableMoveScrAABB(MtGeometry& TraverseGeometry, MtObject* pLeaf, const void* pUserPtr);
    u32 callbackDBVT_EnableBasicScrAABB(MtGeometry& TraverseGeometry, MtObject* pLeaf, const void* pUserPtr);
    MtGeomConvex* getCloneGeometry(const MtGeometry& SrcGeom, u32 CopyItemIndex, const MtVector3& Offset);
    MtGeomConvex* getTraverseGeometry(ScrCollisionInfo& SrcInfo, u32 CopyItemIndex, bool FlgAxisUse);
    u32 enumContactPolygon(MtAABB& aabb, TraverseInfo& MyTraverseInfo);
    u32 enumContactPolygonNormal(MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo);
    u32 enumContactPolygonHitEnd(MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo);
    u32 enumContactPolygonCached(MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo);
    u32 enumContactPolygonOneCached(MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo);
    u32 enumSbcContactCallbackNormal(MtGeometry* pTraverseGeometry, MtObject* pSbc, void* pUserPtr);
    u32 enumSbcContactCallbackOneHitEnd(MtGeometry* pTraverseGeometry, MtObject* pSbc, void* pUserPtr);
    u32 enumPartsContact2MovingCoreNormal(MtGeomConvex& geom, Sbc& sbc, u32 PartsID, TraverseInfo& MyTraverseInfo, u32 ThreadIndex);
    u32 enumPartsContact2MovingCoreOneHitEnd(MtGeomConvex& geom, Sbc& sbc, u32 PartsID, TraverseInfo& MyTraverseInfo, u32 ThreadIndex);
    u32 enumContactScrObject(MtGeometry& DefaultTraverseGeometry, TraverseInfo& MyTraverseInfo, u32 ThreadIndex);
    u32 callbackSbcObject(const MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
    u32 enumHeightFieldContact(MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, u32 ThreadIndex);
    u32 callbackHeightFieldContact(u32 x, u32 z, u32 LeafID, uintptr UserParam, uintptr SystemParam);
    u32 callbackHeightFieldContactCore(u32 x, u32 z, u32 LeafID, uintptr UserParam, uintptr SystemParam, bool FlgEnableRefCountCheck);
    u32 enumDynamicSbcContact(MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, u32 ThreadIndex);
    u32 enumDynamicSbcContactCallback(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
    u32 callbackBvhParts(uintptr SendDataPtr, u32 PartsIndex, uintptr SystemParam);
    u32 callbackBvhPartsOnce(uintptr SendDataPtr, u32 PartsIndex, uintptr SystemParam);
    u32 callbackBvhPartsCore(uintptr SendDataPtr, u32 PartsIndex, uintptr SystemParam, bool FlgOneHitEnd);
    u32 callbackSbcBvhTriangle(uintptr SendUPTR, u32 HitLeafIndex, uintptr SystemParam);
    u32 callbackSbcBvhTriangleCore(uintptr SendUPTR, u32 HitLeafIndex, uintptr SystemParam, bool FlgEnableSystemCheck);
    bool callbackSbcBvhTriangleCore_CommonAttributeCheck(uintptr SendUPTR, u32 HitLeafIndex, uintptr SystemParam, bool FlgEnableSystemCheck);
    u32 callbackSbcBvhTriangleCore_HitCheck(uintptr SendUPTR, u32 HitLeafIndex, uintptr SystemParam, bool FlgEnableSystemCheck);
    u32 callbackBvhDynamicSbc(uintptr SendDataPtr, u32 TriNo, uintptr SystemParam);
    u32 callbackDBVTMvScrAll(const MtGeometry& TraverseGeometry, Sbc* pTargetSbc, TraverseInfo* pMyTraverseInfo);
    u32 callbackDBVTMvScrParts(const MtGeometry& TraverseGeometry, Sbc::Parts* pSbcParts, PartsContactParam* pContactParam);
    u32 findLoosely(const MtLineSegment& ls, const MtTriangle& tri, const MtVector3& triNormal, f32& t, MtContact& contact);
    u32 findLoosely(const MtSphere&, const MtTriangle&, const MtVector3&, const MtVector3&, f32&, MtContact&);
    bool castLineSegmentForPairPolygon(const MtLineSegment& ls, const MtVector3& dir, const MtVector3& dirN, const bool FlgBothSide, const f32 BeforeNearestToi, const MtVector4& BeforeNearestToi4, SbcInfo& info, MtVector3& hpos, MtTriangle& HitTriangle, f32& t);
    bool castSphere(const MtSphere& s, const MtVector3& speed, const MtTriangle& tri, const MtVector3& triNormal, bool& EdgeHit, MtContact* pContact, const bool FlgEnableEdge0, const bool FlgEnableEdge1, const bool FlgEnableEdge2);
    bool castSphereForAdjConvex(const MtSphere&, const MtVector3&, MtTriangle&, bool&, MtContact*, f32);
    bool castSphereForPairPolygon(SbcInfo& info, const MtVector3& cpos, const MtVector3& cspeed, const MtSphere& sphere_local, const Param& param, MtContact& contact, bool& FlgEdgeHit, MtTriangle& HitTriangle_out, f32& distOut_SphereCenter_to_Plane);
    bool findLocal(const MtCapsule& capsule, const MtTriangle& Triangle, const MtVector3& triNormal, const MtVector3& v0, f32 NowToi, f32* pCap_t, MtContact* pContact, bool& EdgeHit, const bool FlgEdgeEnable0, const bool FlgEdgeEnable1, const bool FlgEdgeEnable2);
    bool isIntersectCore(const MtSphere& sphere, TraverseInfo& MyTraverseInfo);
    u32 testSphereFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testSphereFunc_mv(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testSphereMoveFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testSphereMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testSphereResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool isIntersectCore(const MtLineSegment& ls, TraverseInfo& MyTraverseInfo);
    u32 testLineFuncForPairPolygon(SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testLineSegmentFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testLineSegmentMoveFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testLineSegmentMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testLineSegmentResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testLineFuncHeightField(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    bool isIntersectCore(const MtCapsule& capsule, TraverseInfo& MyTraverseInfo);
    u32 testCapsuleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testCapsuleFunc_mv(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testCapsuleMoveFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testCapsuleMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testCapsuleResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool isIntersectCore(const MtAABB& aabb, TraverseInfo& MyTraverseInfo);
    u32 testAABBFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testAABBFuncMv(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testAABBMoveFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testAABBMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testAABBResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool isIntersectCore(const MtOBB& obb, TraverseInfo& MyTraverseInfo);
    u32 testOBBFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testOBBMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testOBBMoveFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testOBBFuncMv(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 testOBBResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactIntersect(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactIntersectCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    u32 findIntersectionCore(const MtLineSegment& ls, const bool both_sides, TriangleInfo* pInfo, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_ENUM pCheckFunc);
    void findIntersection_BeforeFunc(TraverseInfo& MyTraverseInfo, const Param& param, bool FlgBothSide);
    u32 enumLineFuncForPairPolygonBackCheck(SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineFuncForPairPolygonAllHit(SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineFuncBackCheck(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineFuncAllHit(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineFuncBackCheckWithEdge(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineFuncAllHitWithEdge(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineMoveFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactFind(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactFindCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    u32 enumLineFuncHeightField(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    void findIntersection_BeforeFuncRayY(TraverseInfo& MyTraverseInfo, const Param& param);
    u32 findIntersectionCore(const MtRayY& rayY, TriangleInfo& HirResultOutput, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_ENUM pCheckFunc);
    u32 enumRayYTriangleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumRayYMoveFunc(MtGeometry* pNoUseCallbackParam, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumRayYResetFunc(MtGeometry* pNoUseCallbackParam, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactFindRayY(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactFindRayYCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    MtCollisionUtil::MtVectorU4 findIntersection4Core(const MtLineSegment4& ls4, TriangleInfo* TriInfoArray4, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_ENUM pCheckFunc);
    u32 enumLineFunc4(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineMoveFunc4(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineMoveFunc4_mv(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumLineResetFunc4(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactFind4(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactFind4Core(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    void castConvexBeforeFunc_Sphere(TraverseInfo& MyTraverseInfo, const Param& param, bool FlgEnableMove);
    u32 castConvexCore(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, TriangleInfo* pTriInfo, const Param& param, TraverseInfo& MyTraverseInfo);
    u32 castConvexCoreCached(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, TriangleInfo* pTriInfo, const Param& param, TraverseInfo& MyTraverseInfo);
    void castConvexBeforeFunc_Capsule(TraverseInfo& MyTraverseInfo, const Param& param, bool FlgEnableMove);
    u32 castConvexCore(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, TriangleInfo* pTriInfo, const Param& param, TraverseInfo& MyTraverseInfo);
    u32 castConvexCoreCached(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, TriangleInfo* pTriInfo, const Param& param, TraverseInfo& MyTraverseInfo);
    void castConvexBeforeFunc_AABB(TraverseInfo& MyTraverseInfo, const Param& param, bool FlgEnableMove);
    u32 castConvexCore(MtVector3& pos, const MtVector3& old, const MtAABB& aabb, TriangleInfo* pTriInfo, const Param& param, TraverseInfo& MyTraverseInfo);
    u32 castConvexCoreCached(MtVector3& pos, const MtVector3& old, const MtAABB& aabb, TriangleInfo* pTriInfo, const Param& param, TraverseInfo& MyTraverseInfo);
    u32 castConvexCoreMain(MtVector3& pos, const MtVector3& old, TriangleInfo* pTriangleInfo, const Param& param, TraverseInfo& MyTraverseInfo, ScrCollisionInfoCastConvex& MyCollisionInfo, CONTACT_CALLBACK_ENUM pCheckFunc);
    u32 castConvexWithConvexCheck(MtVector3& pos, const MtVector3& old, const MtGeometry* pConvex, TriangleInfo& triInfo, const Param& param);
    void adjustPositionBeforeFunc_Sphere(TraverseInfo& MyTraverseInfo, const Param& param);
    void adjustPositionBeforeFunc_Capsule(TraverseInfo& MyTraverseInfo, const Param& param);
    u32 adjustPositionCore(MtVector3& pos, const MtVector3& old, const MtSphere& sphere, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_ENUM pCheckFunc, const MtMatrix& MatDbgDrawOffset);
    u32 adjustPositionCore(MtVector3& pos, const MtVector3& old, const MtCapsule& capsule, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_ENUM pCheckFunc, const MtMatrix& MatDbgDrawOffset);
    u32 adjustPositionCore(MtVector3& pos, const MtVector3& old, const MtAABB& aabb, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_ENUM pCheckFunc, const MtMatrix& MatDbgDrawOffset);
    u32 adjustPositionCoreMain(MtVector3& pos, const MtVector3& old, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_ENUM pCheckFunc, ScrCollisionInfoAdjustPosition* pColInfo, const MtMatrix& MatDbgDrawOffset);
    u32 adjustPositionWithConvexCheck(MtVector3& pos, const MtVector3& old, MtGeometry* pConvex, const Param& param);
    u32 adjustPositionCoreWithConvexCheck(MtVector3& pos, const MtVector3& old, MtGeometry* pConvex, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_ENUM pCheckFunc, const MtMatrix& MatDbgDrawOffset);
    void repairSinkConvexAdjustPosition(MtVector3& hpos, MtVector3& cpos, MtVector3& cspeed, const MtVector3& hnormal, const Param& param, const SbcInfo& info, const MtContact& contact, bool bFirst, ScrCollisionInfoAdjustPosition& adj_info);
    bool repairSinkConvexAdjustPositionObj(MtVector3& hpos, MtVector3& cpos, MtVector3& cspeed, const MtVector3& hnormal, const Param& param, const MtContact& contact, bool bFirst, ScrCollisionInfoAdjustPosition& adj_info);
    u32 updateSpeedAdjustPosition(MtVector3& cpos, const MtVector3& LoopStartPos, const MtVector3& BaseStartPos, const MtVector3& BaseEndPos, MtVector3& cspeed, const MtVector3& LoopStartSpeed, const MtVector3& BaseStartSpeed, const MtGeometry* pConvex, const MtVector3& hpos, const MtVector3& hnormal, const Param& param, const SbcInfo& info, ScrCollisionInfoAdjustPosition& MyCollisionInfo, u32 HitFlag);
    void repairUpdateSpeedResultStop(MtVector3& cpos, MtVector3& cspeed, const MtVector3& hnormal, const SbcInfo& info, ScrCollisionInfoAdjustPosition& adj_info);
    u32 adjustPosition_mvCommon(MtVector3& pos, const MtVector3& old, ScrCollisionInfoAdjustPosition& MyCollisionInfo, TraverseInfo& MyTraverseInfo, CONTACT_CALLBACK_MV pResetFuncMv);
    u32 enumContactObjectForAdjustMv(MtGeometry& GeomConvexTraverse, TraverseInfo& MyTraverseInfo);
    u32 enumContactPolygonForAdjustMv(MtGeomConvex& geom, TraverseInfo& MyTraverseInfo);
    u32 isSmallSpaceForAdjPos(MtVector3& pos, const MtVector3& old, TraverseInfo& MyTraverseInfo, ScrCollisionInfoAdjustPosition* pInfo);
    u32 enumSphereTriangleFuncForPairPolygon(SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereTriangleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereTriangleFuncCore(const SbcInfo& info, const MtVector3& cpos, const MtVector3& cspeed, const MtSphere& sphere, ScrCollisionInfoCastConvex& MyCollisionInfo);
    u32 enumSphereMoveFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& sbc, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereHeightFieldFunc(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    void enumSphereTriBeforeFunc(const MtSphere& s, ScrCollisionInfo& MyCollisionInfo);
    u32 enumCapsuleTriangleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleMoveFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleHeightFieldFunc(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    u32 enumAABBTriangleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumAABBMoveFunc(MtGeometry* pTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumAABBMoveFunc_mv(MtGeometry* pTraverseGeometry, const SbcInfo& sbc, ScrCollisionInfoBase& CollisionInfo);
    u32 enumAABBResetFunc(MtGeometry* pTraverseGeometry, const SbcInfo& sbc, ScrCollisionInfoBase& CollisionInfo);
    u32 enumAABBHeightFieldFunc(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactCast(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactCastCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    u32 enumSphereWithLS_TriangleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereWithLS_MoveFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereWithLS_MoveFunc_mv(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereWithLS_ResetFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereWithLS_HeightFieldFunc(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithLS_TriangleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithLS_MoveFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithLS_MoveFunc_mv(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithLS_ResetFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithLS_HeightFieldFunc(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactCastWithLS(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactCastWithLSCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    u32 enumSphereWithSphere_TriangleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereWithSphere_MoveFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereWithSphere_MoveFunc_mv(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereWithSphere_ResetFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumSphereWithSphere_HeightFieldFunc(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithSphere_TriangleFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithSphere_MoveFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithSphere_MoveFunc_mv(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithSphere_ResetFunc(MtGeometry* pGeom, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 enumCapsuleWithSphere_HeightFieldFunc(TraverseInfo* pCallback, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactCastWithSphere(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactCastWithSphereCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    u32 getAreaPolygonsConvexFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 getAreaPolygonsConvexFuncLight(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 getAreaPolygonsConvexMoveFunc(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 getAreaPolygonsConvexResetFunc(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactGetPoly(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactGetPolyCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    void originalScrCollisionBackTrace(const MtGeometry& CheckArea, const MtVector3& MoveVector, const Param& param, MT_CTSTR FuncName, bool FlgTypeFind);
    void originalScrCollisionBeforeFunc(const MtGeometry& CheckArea, TraverseInfo& MyTraverseInfo, ScrCollisionInfoOriginal& MyCollisionInfo, const Param& param);
    void originalScrCollisionFindBeforeFunc(const MtGeometry& CheckArea, TraverseInfo& MyTraverseInfo, ScrCollisionInfoOriginal& MyCollisionInfo, const Param& param);
    u32 originalScrCollisionCore(const MtGeometry& CheckArea, TraverseInfo& MyTraverseInfo, ScrCollisionInfoOriginal& MyCollisionInfo, const Param& param, CONTACT_CALLBACK_ENUM pEnumContactPolygonFunc, bool FlgUseSpeed);
    u32 originalScrCollisionConvexFuncForAABB(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexMoveFuncForAABB(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexMoveFunc(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexResetFunc(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexFuncFindForAABB(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexMoveFuncFindForAABB(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexFuncFind(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexMoveFuncFind(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 originalScrCollisionConvexResetFuncFind(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactOrgScrCollision(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool enumNodeContactOrgScrCollisionCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    u32 correctTraverseFunc(const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 correctTraverseMoveFunc(MtGeometry& DefaultTraverseGeometry, const SbcInfo& info, ScrCollisionInfoBase& CollisionInfo);
    u32 correctTraverseResetFunc(MtGeometry& DefaultTraverseGeometry, const SbcInfo& sbc, ScrCollisionInfoBase& CollisionInfo);
    bool correctTraverseNodeFunc(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo);
    bool correctTraverseNodeFuncCore(TraverseInfo& MyTraverseInfo, SbcInfo& info, const MtGeomConvex& TargetConvex, ScrCollisionInfoBase& CollisionInfo, uScrollCollisionGeometry& ScrGeometry, u32 GeometryIndex);
    u32 repairConvexSinkInHitFunc(const SbcInfo& info, uintptr param, u32 GeometryIndex);
    bool enumNodeContactCommon(const MtGeometry* pTraverseGeometry, TraverseInfo& MyTraverseInfo, uScrollCollisionGeometry& ScrGeometry, ScrCollisionInfoBase& CollisionInfo, MtObject* pObj, ENUMNODECONTACTCOMMON_CALLBACK func);
    bool isSetHitNodeResult(f32 HitInfoDeepestDistResult, f32 HitInfoNearestToiResult, f32 HitInfoDeepestDist, f32 HitInfoNearestToi);
    u32 createNewSbc(u32 type, u8 group, bool FlgEnableMove);
    u32 getSameSbc(rCollision* pResource);
    void runReserveInfoRegistRCollisionResource(cSbcRegistReserveInfo& RegistResourceInfo);
    void runReserveInfoRCollisionMatrix(const cSbcMoveReserveInfo& RegistMoveMatrixInfo);
    void runReserveInfoRCollisionMatrixIdentity(const cSbcMoveResetReserveInfo& RegistResetMatrixInfo);
    void runReserveInfoRCollisionMatrixAll(const cSbcMoveReserveInfoAll& RegistMoveMatrixInfoAll);
    void runReserveInfoRCollisionMatrixIdentityAll(const cSbcMoveResetReserveInfoAll& RegistResetMatrixInfo);
    void registDBVTSbc(Sbc& TargetSbc, u32 DBVTCode);
    void unregistDBVTSbc(Sbc& TargetSbc);
    void moveSbcGroupDBVT(Sbc& TargetSbc, u32 NowGroupIndex, u32 NextGroupIndex);
    void updateSbcPartsMoveNum(Sbc&, u32, u32);
    void setSbc(Sbc* psbc, u32 index);
    void setSbcSize(u32 size);
    void setSbcSizeTool(u32 size);
    bool setMatrixCore(Sbc& TargetSbc, u32 TargetPartsIndex, MtMatrix* pSetMatrix, bool FlgResetSet);
    void runReservedSbcProgram();
    bool isHitDynamicSbcAABB(const MtGeomConvex& convex);
    u32 isHitDynamicSbcAABBCallback(const MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr) const;
    void updateScrollCollisionNode(SbcObject::cRegisterInfo& RegisterInfo, u32 MoveCode);
    void unregisterScrollCollisionNode(SbcObject::cRegisterInfo& RegisterInfo);
    void allocatePreTraverseMemory(MtAllocator* pAllocator, u32 MemorySize, u32 BlockSize);
    void releasePreTraverseInfo(PreTraverseInfo& TraverseInfo);
    static rCollision::Header* getHeaderPtrFromSystem(rCollision*);
    static rCollision::PartsInfo* getPartsInfoPtrFromSystem(rCollision* pRSbc, u32 partsNo);
    static rCollision::Triangle* getTrianglePtrFromSystem(rCollision* pRSbc, u32 partsNo, u32 triNo);
    static rCollision::Vertex* getRootVertexPtrFromSystem(rCollision* pRSbc, u32 partsNo);
    static rCollision::MaterialInfo* getMaterialPtrFromSystem(rCollision* pRSbc, u32 partsNo, u32 triNo);
    NodeList* getNodeList(u32 index);
    void setNodeListDummy(NodeList*, u32);
    void initializeNodeListNum(u32 size);
    void allocDebugDispMemory();
    void drawDbgIntersectionInfo(const MtVector3& start, const MtVector3& end, MtColor colorLS, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtVector3& pos, const MtVector3& dir, f32 len, MtColor colorLS, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtLineSegment& ls, MtColor colorLS, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtLineSegment& ls, MtColor colorLS, MtColor colorAABB, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtVector3& center, f32 radius, MtColor colorSphere, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtSphere& sphere, MtColor colorSphere, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtSphere& sphere, MtColor colorSphere, MtColor colorAABB, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtCapsule& capsule, MtColor colorCapsule, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtCapsule& capsule, MtColor colorCapsule, MtColor colorAABB, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtAABB& aabb, MtColor colorAABB, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtOBB& obb, MtColor colorOBB, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtVector3& triP0, const MtVector3& triP1, const MtVector3& triP2, MtColor colorTri, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtTriangle& tri, MtColor colorTri, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtGeometry& geom, MtColor color, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtVector3& pos, const ScrCollisionInfoCastConvex* pMyColInfo, MtColor color, bool bOffsetEnable, u32 FunctionCode, const MtVector3& offset, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtVector3& MoveEnd, f32 Radius, bool FlgHit, const MtVector3& HitPos, f32 HRadius, const MtTriangle& tri, MtColor TriColor, u32 FunctionCode, bool FlgForceLocal);
    void drawDbgIntersectionInfo(const MtVector3& MoveEnd, f32 Radius, bool FlgHit, const MtVector3& HitPos, f32 HRadius, const MtVector3& TriP0, const MtVector3& TriP1, const MtVector3& TriP2, MtColor TriColor, u32 FunctionCode, bool FlgForceLocal);
    void setUseMvFuncForDebugDraw(bool set);
    bool isUseMvFuncForDebugDraw();
    void scrProfileSetup();
    void scrProfileBegin(MT_CTSTR name, PROFILE_ID id);
    void scrProfileEnd(MT_CTSTR name, PROFILE_ID id, u32 hit);
    void scrProfileSync();
    void scrProfileLeafBegin(MT_CTSTR);
    void scrProfileLeafEnd(MT_CTSTR, u32);
    u32 canSetCastConvexInfoCheckAttribute(f32 toi, MtVector3& ContactNormal, const SbcInfo& info, ScrCollisionInfoCastConvex& CollisionInfo, const MtVector3& triNormal, f32 epsilon, f32 diff);
    bool canSetCastConvexInfo(f32 toi, MtVector3& ContactNormal, const SbcInfo& info, ScrCollisionInfoCastConvex& CollisionInfo, const MtVector3& triNormal, f32 epsilon);
    u32 getCollisionVersion();
    u32 getRCollisionVersion();
    u32 getBVHVersion();
    u32 getGridVersion();
    u32 getRCollisionObjVersion();
    u32 getRCollisionHeightFieldVersion();
    void createModalDialogForSetting(MtPropertyList& s, MT_CTSTR DialogTitle, u32 FormWidth, u32 FormHeight);
    void callUsage();
public:
    static sCollision* getInstance();
protected:
    rCollision::MaterialList* mpMaterialList;  // offset: 0x18
    u32 mDefaultMaterial;  // offset: 0x20
    bool mbSetup;  // offset: 0x24
    bool mbMove;  // offset: 0x25
    bool mFlg1stAABBUpdate;  // offset: 0x26
    bool mFlgMoveLock;  // offset: 0x27
    f32 mSlopeDegree;  // offset: 0x28
    f32 mWallDegree;  // offset: 0x2c
    f32 mCeilingDegree;  // offset: 0x30
    f32 mSlopeSin;  // offset: 0x34
    f32 mWallSin;  // offset: 0x38
    f32 mCeilingSin;  // offset: 0x3c
    u32 mTriangleAttributeForceGround;  // offset: 0x40
    u32 mTriangleAttributeForceSlope;  // offset: 0x44
    u32 mTriangleAttributeForceWall;  // offset: 0x48
    f32 mAdjPosStopEpsilonForStopSCR;  // offset: 0x4c
    f32 mAdjPosStopEpsilonForMoveSCR;  // offset: 0x50
    f32 mAdjPosMvSkipEpsilon;  // offset: 0x54
    u32 mAdjPosCorrectedNum[19];  // offset: 0x58
    u32 mMatMoveMulStartID[19];  // offset: 0xa4
    u32 mMatMoveMulEndID[19];  // offset: 0xf0
    f32 mAdjPosThresholdLen;  // offset: 0x13c
    f32 mAdjPosThresholdEpsilonSq;  // offset: 0x140
    f32 mAdjPosStopEpsilonLT;  // offset: 0x144
    f32 mAdjPosStopEpsilonGE;  // offset: 0x148
    u32 mAdjPosSinkIn2AdjConvexNum;  // offset: 0x14c
    u32 mSbcArrayLimitNum;  // offset: 0x150
    cSbcArrayBP mSbcArray;  // offset: 0x158
    SbcObject mSbcObject;  // offset: 0x4790
    cSbcSkinMesh mSbcSkinMesh;  // offset: 0x6898
    cSbcHeightField mSbcHeightField;  // offset: 0x6e00
    Collider mCollider;  // offset: 0x6e28
    bool mFlgRunColliderInSystem;  // offset: 0x6e68
    MtGeomOBB mCloneGeomOBB[6][19];  // offset: 0x6e70
    MtGeomSphere mCloneGeomSphere[6][19];  // offset: 0x9930
    MtGeomCapsule mCloneGeomCapsule[6][19];  // offset: 0xa770
    MtGeomTriangle mCloneGeomTriangle[6][19];  // offset: 0xc3f0
    MtGeomLineSegment mCloneGeomLineSegment[6][19];  // offset: 0xe070
    MtGeomAABB mCloneGeomAABB[6][19];  // offset: 0xf5d0
    cSbcMoveReserveArray mSbcMoveReserveArray[19];  // offset: 0x10b30
    s32 mSbcMoveReserveArrayNowFrameRegistCount;  // offset: 0x10cf8
    cSbcMoveResetReserveArray mSbcMoveResetReserveArray[19];  // offset: 0x10d00
    s32 mSbcMoveResetReserveArrayNowFrameRegistCount;  // offset: 0x10ec8
    cSbcRegistReserveArray mSbcRegistReserveArray[19];  // offset: 0x10ed0
    s32 mSbcRegistReserveArrayNowFrameRegistCount;  // offset: 0x11098
    cUnregistSbcHandleArray mSbcUnregistArray[19];  // offset: 0x110a0
    s32 mSbcUnregistArrayNowFrameRegistCount;  // offset: 0x11268
    cSbcMoveReserveAllArray mSbcMoveAllReserveArray[19];  // offset: 0x11270
    s32 mSbcMoveAllReserveArrayNowFrameRegistCount;  // offset: 0x11438
    cSbcMoveResetReserveAllArray mSbcMoveResetAllReserveArray[19];  // offset: 0x11440
    s32 mSbcMoveResetAllReserveArrayNowFrameRegistCount;  // offset: 0x11608
    f32 mTraverseThresholdRayLengthSq;  // offset: 0x1160c
    bool mIsDeleteSbc_OnUnregistResource;  // offset: 0x11610
    MtCollisionUtil::MtLocalBlockAllocator mPreTraverseAllocator;  // offset: 0x11618
    MtVector3 mTotalApplyWorldOffset;  // offset: 0x11650
public:
    static MyDTI DTI;
    static const u32 SCOLLISION_VERSION;
    static const u32 SBC_MAX_NUM = 256;
    static const u32 MAX_NODELIST = 8;
    static const u32 ADJUSTPOSITION_CORRECT_NUM = 10;
    static const u32 DEFAULT_TYPE = 2147483647;
    static const u32 DEFAULT_GROUP = 1;
    static const f32 DEFAULT_TRAVERSE_THRESHOLD_RAY_LENGTH;
    static const f32 DEFAULT_SLOPE_DEGREE;
    static const f32 DEFAULT_WALL_DEGREE;
    static const f32 DEFAULT_CEILING_DEGREE;
    static const SBC_HANDLE INVALID_HANDLE = 4294967295;
    static const SBC_HANDLE_HALF INVALID_HANDLE_HALF = 65535;
    static const u32 INVALID_ID = 4294967295;
    static const bool FLAG_USE_ORIGINAL = 1;
    static const bool FLAG_USE_TRANSFORM = 0;
    static const f32 EPSILON_HI_LOOSELY;
    static const f32 EPSILON_LOOSELY;
    static const f32 EPSILON;
    static const f32 EPSILON_DETAILS;
    static const f32 EPSILON_HI_DETAILS;
protected:
    static sCollision* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sCollision* sCollision::getInstance() {
    return ::sCollision::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline u32 sCollision::Sbc::getPartsNum() const {
    return this->mPartsArrayNum;
}
