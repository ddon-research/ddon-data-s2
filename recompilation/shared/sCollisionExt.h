#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "rCollision.h"
#include "sCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class rCollision;

// Declarations
class sCollisionExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using u32 = unsigned int;
namespace nCollision { using SBC_HANDLE = u32; }
using size_t = _Sizet;
using u8 = unsigned char;

class sCollisionExt : public sCollision
{
public:
    enum
    {
        SCR_FILTER_PLTHROUGH = 1,
        SCR_FILTER_PAWNTHROUGH = 2,
        SCR_FILTER_NPCTHROUGH = 4,
        SCR_FILTER_ENEMYTHROUGH = 8,
        SCR_FILTER_BIGENEMYTHROUGH = 16,
        SCR_FILTER_CAMERATHROUGH = 32,
        SCR_FILTER_HUGEENEMYTHROUGH = 64,
        SCR_FILTER_PLSTOP = 256,
        SCR_FILTER_PAWNSTOP = 512,
        SCR_FILTER_NPCSTOP = 1024,
        SCR_FILTER_ENEMYSTOP = 2048,
        SCR_FILTER_BIGENEMYSTOP = 4096,
        SCR_FILTER_CAMERASTOP = 8192,
        SCR_FILTER_HUGEENEMYSTOP = 16384,
        SCR_FILTER_PL = 257,
        SCR_FILTER_PAWN = 514,
        SCR_FILTER_NPC = 1028,
        SCR_FILTER_ENEMY = 2056,
        SCR_FILTER_BIGENEMY = 4112,
        SCR_FILTER_CAMERA = 8224,
        SCR_FILTER_HUGEENEMY = 16448,
        SCR_FILTER_GROUND = 65536,
        SCR_FILTER_WALL = 131072,
        SCR_FILTER_AUTO = 262144,
        SCR_FILTER_SLOPE = 524288,
        SCR_FILTER_SLIDER = 1048576,
        SCR_FILTER_CLIMB = 2097152,
        SCR_FILTER_CLIMB_IGNORE = 4194304,
        SCR_FILTER_WATER = 8388608,
        SCR_FILTER_HUGEBLUE = 16777216,
        SCR_FILTER_NO_HUGEBLUE = 33554432,
        SCR_FILTER_FORCE_HUGEBLUE = 67108864,
        SCR_FILTER_ADULTWALL = 268435456,
        SCR_FILTER_DEFAULT = 536870912,
        SCR_FILTER_THROUGH_MASK = 255,
        SCR_FILTER_HIT_ALL = -256,
        SCR_FILTER_ALL_ENEMYSTOP = 30720,
        EFF_FILTER_SHL_THROUGH = 1,
        EFF_FILTER_PHY_THROUGH = 2,
        EFF_FILTER_SHADOW_THROUGH = 4,
        EFF_FILTER_ADHESION_THROUGH = 8,
        EFF_FILTER_SCR_HIT_EFF_THROUGH = 16,
        EFF_FILTER_SHL_STOP = 256,
        EFF_FILTER_PHY_STOP = 512,
        EFF_FILTER_SHADOW_STOP = 1024,
        EFF_FILTER_ADHESION_STOP = 2048,
        EFF_FILTER_SCR_HIT_EFF_STOP = 4096,
        EFF_FILTER_SHL = 257,
        EFF_FILTER_PHY = 514,
        EFF_FILTER_SHADOW = 1028,
        EFF_FILTER_ADHESION = 2056,
        EFF_FILTER_SCR_HIT_EFF = 4112,
        EFF_FILTER_WATER = 65536,
        EFF_FILTER_NO_SPLASH = 131072,
        EFF_FILTER_ADULTWALL = 268435456,
        EFF_FILTER_DEFAULT = 536870912,
        EFF_FILTER_HIT_ALL = -256,
    };
    enum
    {
        COLLISION_TYPE_NORMAL = -1,
        COLLISION_TYPE_SCR = 1,
        COLLISION_TYPE_EFF = 2,
        COLLISION_TYPE_DUMMY_SCR = 4,
        COLLISION_TYPE_DUMMY_EFF = 8,
        COLLISION_TYPE_NUM = 3,
    };
    enum
    {
        SCR_ATTR_0_INSTANTDEATH = 1,
        SCR_ATTR_0_FALLINSTANTDEATH = 2,
        SCR_ATTR_0_NARROW = 4,
    };
    enum
    {
        EFF_ATTR_0_SOIL = 1,
        EFF_ATTR_0_SAND = 2,
        EFF_ATTR_0_STONE = 4,
        EFF_ATTR_0_WOOD = 8,
        EFF_ATTR_0_METAL = 16,
        EFF_ATTR_0_GRASS = 32,
        EFF_ATTR_0_CARPET = 64,
        EFF_ATTR_0_ROCK = 128,
        EFF_ATTR_0_GRAVE = 256,
        EFF_ATTR_0_CLOTH = 512,
        EFF_ATTR_0_TREE = 1024,
        EFF_ATTR_0_DEADLEAF = 2048,
        EFF_ATTR_0_BONE = 4096,
        EFF_ATTR_0_MUD = 8192,
        EFF_ATTR_0_STRAW = 16384,
        EFF_ATTR_0_ROOFTILE = 32768,
        EFF_ATTR_0_WATER = 65536,
        EFF_ATTR_0_MAGICSPA = 131072,
        EFF_ATTR_0_BOG = 262144,
        EFF_ATTR_0_POISONBOG = 524288,
        EFF_ATTR_0_TAR = 1048576,
        EFF_ATTR_0_DUMMY21 = 2097152,
        EFF_ATTR_0_DUMMY22 = 4194304,
        EFF_ATTR_0_DUMMY23 = 8388608,
        EFF_ATTR_0_DUMMY24 = 16777216,
        EFF_ATTR_0_DUMMY25 = 33554432,
        EFF_ATTR_0_DUMMY26 = 67108864,
        EFF_ATTR_0_DUMMY27 = 134217728,
        EFF_ATTR_0_DUMMY28 = 268435456,
        EFF_ATTR_0_DUMMY29 = 536870912,
        EFF_ATTR_0_DUMMY30 = 1073741824,
        EFF_ATTR_0_DUMMY31 = -2147483648,
        EFF_ATTR_0_MAX_NUM = 32,
    };
    enum
    {
        SCR_TARGET_FILTER_OBJ = 537329664,
        SCR_TARGET_FILTER_PL = 537329921,
        SCR_TARGET_FILTER_PAWN = 537330178,
        SCR_TARGET_FILTER_NPC = 537330692,
        SCR_TARGET_FILTER_EM = 537331720,
        SCR_TARGET_FILTER_EM_BIG = 537333776,
        SCR_TARGET_FILTER_EM_HUGE = 537346112,
        SCR_TARGET_FILTER_CAMERA = 545726496,
        SCR_TARGET_FILTER_WATER_DEPTH_CHECK = 629604352,
        SCR_TARGET_FILTER_WATER_DEPTH_CHECK2 = 92274688,
        SCR_TARGET_FILTER_OBJ_HIT = 537329664,
        EFF_TARGET_FILTER_OBJ = 536871430,
        EFF_TARGET_FILTER_OBJ_PHYSICS = 536871430,
        EFF_TARGET_FILTER_EFFECT = -252,
        EFF_TARGET_FILTER_EFFECT_ADHESION = 536872972,
        EFF_TARGET_FILTER_DAMAGE_EFFECT = 536875028,
        EFF_TARGET_FILTER_SHADOW_JUDGE = 536871936,
        EFF_TARGET_FILTER_SHL = 536871169,
        EFF_TARGET_FILTER_SOUND = -256,
    };
    enum
    {
        SCR_FILTER_KIND_PL = 0,
        SCR_FILTER_KIND_PAWN = 1,
        SCR_FILTER_KIND_NPC = 2,
        SCR_FILTER_KIND_ENEMY = 3,
        SCR_FILTER_KIND_BIGENEMY = 4,
        SCR_FILTER_KIND_CAMERA = 5,
        SCR_FILTER_KIND_HUGEENEMY = 6,
        SCR_FILTER_KIND_RESERVED7 = 7,
        EFF_FILTER_KIND_SHL = 0,
        EFF_FILTER_KIND_PHY = 1,
        EFF_FILTER_KIND_SHADOW = 2,
        EFF_FILTER_KIND_ADHESION = 3,
        EFF_FILTER_KIND_SCR_HIT_EFF = 4,
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
    sCollisionExt(sCollision::cSystemInitializeParam* pInitializeParam);
    virtual ~sCollisionExt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    sCollision::SBC_HANDLE registResourceSafe(rCollision* pResource, u32 type, u8 group, bool FlgForceRegist, bool FlgEnableMove);
    f32 checkHeight(const MtVector3& Pos, u32 CheckType, u32 CheckFilter, f32 CheckHeight);
    u32 findIntersectionEx(const MtLineSegment& ls, const bool both_sides, sCollision::TriangleInfo* pTriInfo, const sCollision::Param& param);
    bool isIntersectEx(const MtLineSegment& ls, const sCollision::Param& param);
    virtual bool isTargetPolygon(u32 TargetPolygonAttribute, const rCollision::MaterialInfo& RSbcPolygonMaterial, u32 type);  // vtable slot 11
    virtual void replaceAttribute(rCollision::MaterialInfo& material);  // vtable slot 12
    u32 enumEffectAttr(rCollision* pSbc, u32* buff);
public:
    static MyDTI DTI;
};
