#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class AHShapeBox;
class AHShapeCone;
class AHShapeCylinder;
class AHShapeSphere;
class MtAABB;
class MtCollision;
namespace MtCollisionUtil { class MtLinerTree; }
struct MtFloat2A;
class MtGeomAABB;
class MtGeomCapsule;
class MtGeomCylinder;
class MtGeomLine;
class MtGeomLineSegment;
class MtGeomOBB;
class MtGeomRay;
class MtGeomSphere;
class MtGeomTriangle;
class MtGeometry;
struct MtHalf2;
struct MtInt3;
class MtMatrix33;
class MtTriangle;
class cAIGrid;
class cAIPathTrace;
class cAISvDynamicPathFinding;
class cAISvPathFinding;
class cAnimalData;
class cAreaHit;
class cBVHCollision;
class cCamImpMot;
class cCamImpPhoto;
class cCamImpTarget;
class cCamInterAll;
class cCamInterporateAng3Time;
class cCameraInfo;
class cCaughtInfoParam;
class cCharacterEditCameraParam;
class cCharacterEditMuscle;
class cChildRegionStatus;
class cCollGeom;
class cCommonSkyFogData;
class cContextInterface;
class cDDMaterialCtrl;
class cDamageEffInfo;
class cDamageMsg;
class cDamageSeInfo;
class cDayNightColorFogParam;
class cEffectCulling;
class cEmEffectTable;
class cEmScaleTable;
class cEmSoundTable;
class cErosionRegionScaleChange;
class cFSMOrderParamJumpPos;
class cFSMOrderParamSetCallSe;
class cFSMOrderParamSetEffect;
class cFSMOrderParamStartQuake;
class cFSMUnit;
class cFacialEditJointPreset;
class cFatAdjust;
class cFurniture;
class cFurnitureData;
class cGroundAttrInfo;
class cGroupParam;
class cHitInfo;
class cHitInfoAfter;
class cHitInfoAfterLocal;
class cHumanActEnemyClimb;
class cIKHandle;
class cJumpParamCtrl;
class cMenuEntryBoardItemList;
class cPRTManager;
class cParticleGenerator;
class cPawnActInterWarp;
class cPlActWpnBow;
class cPrioThkCmdRetGoto;
class cQuakeParam;
class cSetInfoCoord;
class cSetInfoOmBadStatus;
class cSetInfoOmDoor;
class cSetInfoOmNav;
class cSetInfoOmOneWay;
class cSetInfoOmWall;
class cShlLogNode;
class cShlNotifyInfo;
class cShlParamBase;
class cShlParamFollowMove;
class cShlParamGeneTarget;
class cShlParamGenerator;
class cShlParamRenmadanCtrl;
class cShlParamSpline;
class cShotReqInfo;
class cSoundTriggerLayoutInfo;
class cStageMap;
class cStartPos;
namespace cThinkMgrName { class cThinkMgrTargetData; }
class cWeaponOffset;
class cWeatherFogInfo;
class cWeatherParam;
class cZoneListenerEffectEFL;
class cZoneListenerLight;
class cpCatchCtrl;
class cpCheckWallCliff;
class cpHeadCtrl;
class cpHugeble;
class cpHumanWarpCtrl;
class cpJob02;
class cpJob06;
class cpJob09;
class cpObjCollisionBase;
class cpReturnTerritory;
class cpShakeCtrl;
class cpShlShotCtrl;
class cpSlave;
class cpWallMaria;
class cpWaypoint;
namespace nCollision { class cCollisionNodeGroup; }
namespace nMarker { class cMarkerInfo; }
namespace nPhysics { class Material; }
namespace nPhysics { class System; }
namespace nShlBase { class cShlFuwaMove; }
namespace nShlBase { class cShlStickContextInfo; }
namespace nShlStick { class cStickObjectCtrl; }
namespace nZone { class ShapeInfoAABB; }
namespace nZone { class ShapeInfoArea; }
namespace nZone { class ShapeInfoBase; }
namespace nZone { class ShapeInfoCylinder; }
namespace nZone { class ShapeInfoGlobal; }
namespace nZone { class ShapeInfoLine; }
namespace nZone { class ShapeInfoOBB; }
namespace nZone { class ShapeInfoPanel; }
namespace nZone { class ShapeInfoPoint; }
namespace nZone { class ShapeInfoSphere; }
class rDeformWeightMap;
class rDungeonMarker;
class rFieldAreaMarkerInfo;
class rFullbodyIKHuman2;
class rGeometry2;
class rLocationData;
class rMapSpotData;
class rNavigationMesh;
class rOccluder;
class rPlantTree;
class rQuestMarkerInfo;
class rSky;
class rStageConnect;
class rStageCustomPartsEx;
class rStartPos;
class rWaypoint;
class sCollision;
class sEffect;
class sEffectExt;
class sGUIExt;
class sGame;
class sOmManager;
class sSoundManager;
class sWeatherManager;
class sWorldOffset;
class uAnimal;
class uBaseEffect;
class uBloomFilter;
class uCamera;
class uCharacter;
class uCnsBowUpper;
class uCnsIK;
class uCnsLookAt;
class uCnsShakeCtrl;
class uCnsTurnUpper;
class uCorePointSearch;
class uCustomSimSoftBody;
class uDDOModel;
class uEfCam;
class uEffect;
class uEffectExt;
class uFreeCamera;
class uFullbodyIKHuman2;
class uFullbodyIKHumanDDO;
class uGUIAim;
class uGUIArisenCard;
class uGUIBase;
class uGUIBazaar;
class uGUIBoughtBox;
class uGUICraft;
class uGUIPopCmd01;
class uGUIQuestInfo;
class uGUISkill;
class uGodRaysFilter;
class uGrassWindDirection;
class uGrassWindPoint;
class uHuman;
class uLight;
class uModel;
class uMotionCamera;
class uOmModel;
class uPointLight;
class uPointLightExt;
class uPointShadow;
class uShlArrowInc;
class uShlBase;
class uShlFollowMove;
class uShlGeneAlongGround;
class uShlGenerator;
class uShlHoming;
class uShlMeteo;
class uShlMeteoCtrl;
class uShlRenmadanCtrl;
class uShlSpeed;
class uSimSoftBody;
class uSky;
class uSoundSequenceSe;
class uWeapon;

// Declarations
struct MtFloat2;
struct MtFloat3;
struct MtFloat3A;
struct MtFloat3x3;
struct MtFloat3x4;
struct MtFloat4;
struct MtFloat4A;
struct MtFloat4x3;
struct MtFloat4x4;
struct MtHalf4;
struct MtInt2;
class MtMath;
class MtMatrix;
class MtQuaternion;
class MtVector2;
class MtVector3;
class MtVector4;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using u32 = unsigned int;
using u64 = __uint64_t;

struct MtFloat2
{
public:
    MtFloat2();
    MtFloat2(f32 _x, f32 _y);
    MtFloat2(const MtVector3& v);
    MtFloat2(const MtVector4& v);
    const MtFloat2& operator=(const MtVector3&);
    const MtFloat2& operator=(const MtVector4& v);
    operator float *();
    operator float *() const;
    bool operator==(const MtFloat2& s) const;
    bool operator!=(const MtFloat2& s) const;
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    static const MtFloat2 Zero;
    static const MtFloat2 One;
};

struct MtFloat3
{
public:
    MtFloat3();
    MtFloat3(f32 _x, f32 _y, f32 _z);
    MtFloat3(const MtVector3& v);
    MtFloat3(const MtVector4& v);
    const MtFloat3& operator=(const MtVector3& v);
    const MtFloat3& operator=(const MtVector4& v);
    operator float *();
    operator float *() const;
    bool operator==(const MtFloat3&) const;
    bool operator!=(const MtFloat3&) const;
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    f32 z;  // offset: 0x8
    static const MtFloat3 Zero;
    static const MtFloat3 One;
};

struct MtFloat3A
{
public:
    MtFloat3A();
    MtFloat3A(f32 _x, f32 _y, f32 _z);
    MtFloat3A(const MtVector3& v);
    MtFloat3A(const MtVector4&);
    const MtFloat3A& operator=(const MtVector3& v);
    const MtFloat3A& operator=(const MtVector4& v);
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    f32 z;  // offset: 0x8
    static const MtFloat3A Zero;
    static const MtFloat3A One;
};

struct MtFloat3x3
{
public:
    MtFloat3x3();
    MtFloat3x3(const MtMatrix& v);
    const MtFloat3x3& operator=(const MtMatrix& v);
public:
    f32 m[3][3];  // offset: 0x0
};

struct MtFloat3x4
{
public:
    MtFloat3x4();
    MtFloat3x4(const MtMatrix& v);
    const MtFloat3x4& operator=(const MtMatrix& v);
public:
    f32 m[3][4];  // offset: 0x0
};

struct MtFloat4
{
public:
    MtFloat4();
    MtFloat4(f32 _x, f32 _y, f32 _z, f32 _w);
    MtFloat4(const MtVector4& v);
    MtFloat4(const MtQuaternion& v);
    const MtFloat4& operator=(const MtVector4& v);
    const MtFloat4& operator=(const MtQuaternion&);
    operator float *();
    operator float *() const;
    bool operator==(const MtFloat4&) const;
    bool operator!=(const MtFloat4& s) const;
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    f32 z;  // offset: 0x8
    f32 w;  // offset: 0xc
    static const MtFloat4 Zero;
    static const MtFloat4 One;
};

struct MtFloat4A
{
public:
    MtFloat4A();
    MtFloat4A(f32 _x, f32 _y, f32 _z, f32 _w);
    MtFloat4A(const MtVector4&);
    MtFloat4A(const MtQuaternion&);
    const MtFloat4A& operator=(const MtVector4&);
    const MtFloat4A& operator=(const MtQuaternion&);
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    f32 z;  // offset: 0x8
    f32 w;  // offset: 0xc
    static const MtFloat4A Zero;
    static const MtFloat4A One;
};

struct MtFloat4x3
{
public:
    MtFloat4x3();
    MtFloat4x3(const MtMatrix& v);
    const MtFloat4x3& operator=(const MtMatrix& v);
public:
    f32 m[4][3];  // offset: 0x0
};

struct MtFloat4x4
{
public:
    MtFloat4x4();
    MtFloat4x4(const MtMatrix& v);
    const MtFloat4x4& operator=(const MtMatrix& v);
public:
    f32 m[4][4];  // offset: 0x0
};

struct MtHalf4
{
public:
    MtHalf4();
    MtHalf4(f32, f32, f32, f32);
    MtHalf4(const MtHalf4&);
    MtHalf4(const MtVector4& v);
    const MtHalf4& operator=(const MtVector4&);
public:
    s16 x;  // offset: 0x0
    s16 y;  // offset: 0x2
    s16 z;  // offset: 0x4
    s16 w;  // offset: 0x6
};

struct MtInt2
{
public:
    MtInt2();
    MtInt2(s32 _x, s32 _y);
    operator int *();
    operator int *() const;
    bool operator==(const MtInt3&) const;
    bool operator!=(const MtInt3&) const;
public:
    s32 x;  // offset: 0x0
    s32 y;  // offset: 0x4
};

class MtMath
{
public:
    static f32 sinT(f32 t);
    static f32 cosT(f32 t);
    static f32 sinI(u32 i);
    static f32 cosI(u32 i);
    static f32 sqrtT(f32);
    static u32 randomT(u32 s);
    static f32 randomTF(u32 s);
    static u32 U32(f32);
    static s32 S32(f32);
    static s32 absi(s32 i);
    static f32 absf(f32 f);
    static s32 mini(s32 a, s32 b);
    static s32 maxi(s32 a, s32 b);
    static f32 clampGT1(f32 f);
    static f32 clampLT0(f32 f);
    static f32 clampGT0(f32);
    static f32 clamp0_1(f32 f);
    static f32 limitAngle(f32 r, f32 min, f32 max, bool* pIsOver);
    static f32 lerp(f32 a, f32 b, f32 t);
private:
    MtMath();
public:
    static MtMath mInstance;
private:
    static f32 mTfsin[4096];
    static s32 mTfsqrt[4096];
    static u32 mTrandom[4096];
    static f32 mTrandomF[4096];
};

class alignas(16) MtQuaternion
{
public:
    MtQuaternion();
    explicit MtQuaternion(const f32* p);
    MtQuaternion(f32, f32, f32);
    MtQuaternion(f32 _x, f32 _y, f32 _z, f32 _w);
    MtQuaternion(const MtVector4& v);
    MtQuaternion(const MtQuaternion& v);
    MtQuaternion(const MtFloat4& v);
    MtQuaternion(const MtFloat3&);
    MtQuaternion(const MtFloat4A&);
    MtQuaternion(const MtFloat3A&);
    MtQuaternion(const MtVector3& base_direction, const MtVector3& target_direction);
    MtQuaternion(const MtMatrix& rotation);
    const MtQuaternion& operator=(const MtQuaternion& v);
    const MtQuaternion& operator=(const MtFloat4& v);
    const MtQuaternion& operator=(const MtFloat3&);
    const MtQuaternion& operator=(const MtFloat4A&);
    const MtQuaternion& operator=(const MtFloat3A&);
    operator float *();
    operator const float *() const;
    MtQuaternion operator+() const;
    MtQuaternion operator-() const;
    MtQuaternion& operator+=(const MtQuaternion& s);
    MtQuaternion& operator+=(f32);
    MtQuaternion& operator-=(const MtQuaternion&);
    MtQuaternion& operator-=(f32);
    MtQuaternion& operator*=(const MtQuaternion& q);
    MtQuaternion& operator*=(f32 s);
    MtQuaternion operator+(const MtQuaternion&) const;
    MtQuaternion operator+(f32) const;
    MtQuaternion operator-(const MtQuaternion& s) const;
    MtQuaternion operator-(f32) const;
    MtQuaternion operator*(const MtQuaternion& t) const;
    MtQuaternion operator*(f32 s) const;
    bool operator==(const MtQuaternion& q) const;
    bool operator!=(const MtQuaternion&) const;
    const MtQuaternion inverse() const;
    f32 dot(const MtQuaternion& q) const;
    const MtQuaternion conjugate() const;
    f32 length() const;
    f32 lengthSq() const;
    const MtQuaternion normalize() const;
    void setRotationAxis(const MtVector3& v, f32 angle);
    void setRotationArc(const MtVector3& v0, const MtVector3& v1);
    void setRotationRollPitchYaw(f32 pitch, f32 yaw, f32 roll);
    void setRotationRollPitchYawFromVector(const MtVector3& r);
    void setRotationMatrix(const MtMatrix& mat);
    const MtQuaternion exp() const;
    const MtQuaternion log() const;
    static const MtQuaternion lerp(const MtQuaternion& q0, const MtQuaternion& q1, f32 t);
    static const MtQuaternion slerp(const MtQuaternion& q0, const MtQuaternion& q1, f32 t);
    static const MtQuaternion slerpFast(const MtQuaternion& q0, const MtQuaternion& q1, f32 t);
    static const MtQuaternion squad(const MtQuaternion&, const MtQuaternion&, const MtQuaternion&, const MtQuaternion&, f32);
    static const MtQuaternion squadFast(const MtQuaternion&, const MtQuaternion&, const MtQuaternion&, const MtQuaternion&, f32);
    static void squadSetup(MtQuaternion&, MtQuaternion&, MtQuaternion&, const MtQuaternion&, const MtQuaternion&, const MtQuaternion&, const MtQuaternion&);
    const MtQuaternion angleConstraint(const MtQuaternion&, const MtVector3&, const MtVector3&);
    static MtQuaternion fromPolar32(u32);
    static MtQuaternion fromPolar56(u64);
    static MtQuaternion fromInteger56(u64 v);
    MtVector3 getDirection() const;
    MtQuaternion multiply(const MtVector3&);
    MtQuaternion multiply(const MtVector3&, const f32);
    void getRotationAxis(MtVector3& axis, f32& angle) const;
    static u32 toPolar32(const MtQuaternion& _q);
    static u64 toPolar56(const MtQuaternion& _q);
    static u64 toInteger56(const MtQuaternion& _q);
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    f32 z;  // offset: 0x8
    f32 w;  // offset: 0xc
    static const MtQuaternion Identity;
    static const MtQuaternion Zero;
};

class alignas(8) MtVector2
{
public:
    MtVector2();
    explicit MtVector2(const f32*);
    MtVector2(f32 _x, f32 _y);
    MtVector2(const MtVector4& v);
    MtVector2(const MtVector3& v);
    MtVector2(const MtVector2& v);
    MtVector2(const MtFloat4&);
    MtVector2(const MtFloat3&);
    MtVector2(const MtFloat2& v);
    MtVector2(const MtFloat4A&);
    MtVector2(const MtFloat3A&);
    MtVector2(const MtFloat2A&);
    MtVector2(const MtHalf4&);
    MtVector2(const MtHalf2& v);
    explicit MtVector2(f32 v);
    const MtVector2& operator=(const MtVector4& v);
    const MtVector2& operator=(const MtVector3& v);
    const MtVector2& operator=(const MtVector2& v);
    const MtVector2& operator=(const MtFloat4&);
    const MtVector2& operator=(const MtFloat3&);
    const MtVector2& operator=(const MtFloat2& v);
    const MtVector2& operator=(const MtFloat4A&);
    const MtVector2& operator=(const MtFloat3A&);
    const MtVector2& operator=(const MtFloat2A&);
    const MtVector2& operator=(const MtHalf4&);
    const MtVector2& operator=(const MtHalf2&);
    const MtVector2& operator=(f32);
    operator float *();
    operator const float *() const;
    MtVector2 operator+() const;
    MtVector2 operator-() const;
    MtVector2& operator+=(const MtVector2& s);
    MtVector2& operator+=(f32);
    MtVector2& operator-=(const MtVector2& s);
    MtVector2& operator-=(f32 s);
    MtVector2& operator*=(const MtVector2&);
    MtVector2& operator*=(f32 s);
    MtVector2 operator+(const MtVector2& s) const;
    MtVector2 operator+(f32) const;
    MtVector2 operator-(const MtVector2& s) const;
    MtVector2 operator-(f32) const;
    MtVector2 operator*(const MtVector2&) const;
    MtVector2 operator*(f32 s) const;
    bool operator==(const MtVector2& s) const;
    bool operator!=(const MtVector2& s) const;
    const MtVector2 abs() const;
    const MtVector2 minimize(const MtVector2&) const;
    const MtVector2 maximize(const MtVector2&) const;
    static const MtVector2 lerp(const MtVector2& a, const MtVector2& b, f32 t);
    static const MtVector2 hermite(const MtVector2&, const MtVector2&, const MtVector2&, const MtVector2&, f32);
    static const MtVector2 catmullrom(const MtVector2&, const MtVector2&, const MtVector2&, const MtVector2&, f32);
    f32 innerProduct(const MtVector2& s) const;
    MtVector4 innerProductBq(const MtVector2&) const;
    f32 outerProduct(const MtVector2& s) const;
    const MtVector2 normalize() const;
    const MtVector2 normalizeFast() const;
    const MtVector2 normalizeEst() const;
    f32 length() const;
    MtVector4 lengthBq() const;
    f32 lengthSq() const;
    MtVector3 transform(const MtMatrix&) const;
    MtVector2 transformCoord(const MtMatrix&) const;
    MtVector2 transformNormal(const MtMatrix&) const;
    MtVector3 transform(const MtMatrix33&) const;
    MtVector2 transformCoord(const MtMatrix33&) const;
    MtVector2 transformNormal(const MtMatrix33&) const;
    void setLength(f32);
    MtVector2 sin() const;
    MtVector2 cos() const;
    MtVector2 tan() const;
    MtVector2 asin() const;
    MtVector2 atan() const;
    void sincos(MtVector2*, MtVector2*) const;
    u32 closestAxis() const;
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    static const MtVector2 Zero;
    static const MtVector2 One;
    static const MtVector2 AxisX;
    static const MtVector2 AxisY;
    static const MtVector2 Min;
    static const MtVector2 Max;
};

class alignas(16) MtVector3
{
    friend class AHShapeBox;
    friend class AHShapeCone;
    friend class AHShapeCylinder;
    friend class AHShapeSphere;
    friend class MtAABB;
    friend class MtCollision;
    friend class MtCollisionUtil::MtLinerTree;
    friend class MtGeomAABB;
    friend class MtGeomCapsule;
    friend class MtGeomCylinder;
    friend class MtGeomLine;
    friend class MtGeomLineSegment;
    friend class MtGeomOBB;
    friend class MtGeomRay;
    friend class MtGeomSphere;
    friend class MtGeomTriangle;
    friend class MtGeometry;
    friend class MtTriangle;
    friend class cAIGrid;
    friend class cAIPathTrace;
    friend class cAISvDynamicPathFinding;
    friend class cAISvPathFinding;
    friend class cAnimalData;
    friend class cAreaHit;
    friend class cBVHCollision;
    friend class cCamImpMot;
    friend class cCamImpPhoto;
    friend class cCamImpTarget;
    friend class cCamInterAll;
    friend class cCamInterporateAng3Time;
    friend class cCameraInfo;
    friend class cCaughtInfoParam;
    friend class cCharacterEditCameraParam;
    friend class cCharacterEditMuscle;
    friend class cChildRegionStatus;
    friend class cCollGeom;
    friend class cCommonSkyFogData;
    friend class cContextInterface;
    friend class cDDMaterialCtrl;
    friend class cDamageEffInfo;
    friend class cDamageMsg;
    friend class cDamageSeInfo;
    friend class cDayNightColorFogParam;
    friend class cEffectCulling;
    friend class cEmEffectTable;
    friend class cEmScaleTable;
    friend class cEmSoundTable;
    friend class cErosionRegionScaleChange;
    friend class cFSMOrderParamJumpPos;
    friend class cFSMOrderParamSetCallSe;
    friend class cFSMOrderParamSetEffect;
    friend class cFSMOrderParamStartQuake;
    friend class cFSMUnit;
    friend class cFacialEditJointPreset;
    friend class cFatAdjust;
    friend class cFurniture;
    friend class cFurnitureData;
    friend class cGroundAttrInfo;
    friend class cGroupParam;
    friend class cHitInfo;
    friend class cHitInfoAfter;
    friend class cHitInfoAfterLocal;
    friend class cHumanActEnemyClimb;
    friend class cIKHandle;
    friend class cJumpParamCtrl;
    friend class cMenuEntryBoardItemList;
    friend class cPRTManager;
    friend class cParticleGenerator;
    friend class cPawnActInterWarp;
    friend class cPlActWpnBow;
    friend class cPrioThkCmdRetGoto;
    friend class cQuakeParam;
    friend class cSetInfoCoord;
    friend class cSetInfoOmBadStatus;
    friend class cSetInfoOmDoor;
    friend class cSetInfoOmNav;
    friend class cSetInfoOmOneWay;
    friend class cSetInfoOmWall;
    friend class cShlLogNode;
    friend class cShlNotifyInfo;
    friend class cShlParamBase;
    friend class cShlParamFollowMove;
    friend class cShlParamGeneTarget;
    friend class cShlParamGenerator;
    friend class cShlParamRenmadanCtrl;
    friend class cShlParamSpline;
    friend class cShotReqInfo;
    friend class cSoundTriggerLayoutInfo;
    friend class cStageMap;
    friend class cStartPos;
    friend class cThinkMgrName::cThinkMgrTargetData;
    friend class cWeaponOffset;
    friend class cWeatherFogInfo;
    friend class cWeatherParam;
    friend class cZoneListenerEffectEFL;
    friend class cZoneListenerLight;
    friend class cpCatchCtrl;
    friend class cpCheckWallCliff;
    friend class cpHeadCtrl;
    friend class cpHugeble;
    friend class cpHumanWarpCtrl;
    friend class cpJob02;
    friend class cpJob06;
    friend class cpJob09;
    friend class cpObjCollisionBase;
    friend class cpReturnTerritory;
    friend class cpShakeCtrl;
    friend class cpShlShotCtrl;
    friend class cpSlave;
    friend class cpWallMaria;
    friend class cpWaypoint;
    friend class nCollision::cCollisionNodeGroup;
    friend class nMarker::cMarkerInfo;
    friend class nPhysics::Material;
    friend class nPhysics::System;
    friend class nShlBase::cShlFuwaMove;
    friend class nShlBase::cShlStickContextInfo;
    friend class nShlStick::cStickObjectCtrl;
    friend class nZone::ShapeInfoAABB;
    friend class nZone::ShapeInfoArea;
    friend class nZone::ShapeInfoBase;
    friend class nZone::ShapeInfoCylinder;
    friend class nZone::ShapeInfoGlobal;
    friend class nZone::ShapeInfoLine;
    friend class nZone::ShapeInfoOBB;
    friend class nZone::ShapeInfoPanel;
    friend class nZone::ShapeInfoPoint;
    friend class nZone::ShapeInfoSphere;
    friend class rDeformWeightMap;
    friend class rDungeonMarker;
    friend class rFieldAreaMarkerInfo;
    friend class rFullbodyIKHuman2;
    friend class rGeometry2;
    friend class rLocationData;
    friend class rMapSpotData;
    friend class rNavigationMesh;
    friend class rOccluder;
    friend class rPlantTree;
    friend class rQuestMarkerInfo;
    friend class rSky;
    friend class rStageConnect;
    friend class rStageCustomPartsEx;
    friend class rStartPos;
    friend class rWaypoint;
    friend class sCollision;
    friend class sEffect;
    friend class sEffectExt;
    friend class sGUIExt;
    friend class sGame;
    friend class sOmManager;
    friend class sSoundManager;
    friend class sWeatherManager;
    friend class sWorldOffset;
    friend class uAnimal;
    friend class uBaseEffect;
    friend class uBloomFilter;
    friend class uCamera;
    friend class uCharacter;
    friend class uCnsBowUpper;
    friend class uCnsIK;
    friend class uCnsLookAt;
    friend class uCnsShakeCtrl;
    friend class uCnsTurnUpper;
    friend class uCorePointSearch;
    friend class uCustomSimSoftBody;
    friend class uDDOModel;
    friend class uEfCam;
    friend class uEffect;
    friend class uEffectExt;
    friend class uFreeCamera;
    friend class uFullbodyIKHuman2;
    friend class uFullbodyIKHumanDDO;
    friend class uGUIAim;
    friend class uGUIArisenCard;
    friend class uGUIBase;
    friend class uGUIBazaar;
    friend class uGUIBoughtBox;
    friend class uGUICraft;
    friend class uGUIPopCmd01;
    friend class uGUIQuestInfo;
    friend class uGUISkill;
    friend class uGodRaysFilter;
    friend class uGrassWindDirection;
    friend class uGrassWindPoint;
    friend class uHuman;
    friend class uLight;
    friend class uModel;
    friend class uMotionCamera;
    friend class uOmModel;
    friend class uPointLight;
    friend class uPointLightExt;
    friend class uPointShadow;
    friend class uShlArrowInc;
    friend class uShlBase;
    friend class uShlFollowMove;
    friend class uShlGeneAlongGround;
    friend class uShlGenerator;
    friend class uShlHoming;
    friend class uShlMeteo;
    friend class uShlMeteoCtrl;
    friend class uShlRenmadanCtrl;
    friend class uShlSpeed;
    friend class uSimSoftBody;
    friend class uSky;
    friend class uSoundSequenceSe;
    friend class uWeapon;
public:
    MtVector3();
    explicit MtVector3(const f32* f);
    MtVector3(f32 _x, f32 _y, f32 _z);
    MtVector3(const MtVector4& v);
    MtVector3(const MtVector3& v);
    MtVector3(const MtVector2& v, f32 _z);
    MtVector3(const MtFloat4& v);
    MtVector3(const MtFloat3& v);
    MtVector3(const MtFloat2& v, f32 _z);
    MtVector3(const MtFloat4A&);
    MtVector3(const MtFloat3A& v);
    MtVector3(const MtFloat2A&, f32);
    MtVector3(const MtHalf4&);
    explicit MtVector3(f32 v);
    const MtVector3& operator=(const MtVector4& v);
    const MtVector3& operator=(const MtVector3& v);
    const MtVector3& operator=(const MtFloat4& v);
    const MtVector3& operator=(const MtFloat3& v);
    const MtVector3& operator=(const MtFloat4A&);
    const MtVector3& operator=(const MtFloat3A& v);
    const MtVector3& operator=(const MtHalf4&);
    const MtVector3& operator=(f32 v);
    operator float *();
    operator const float *() const;
    MtVector3 operator+() const;
    MtVector3 operator-() const;
    MtVector3& operator+=(const MtVector3& s);
    MtVector3& operator+=(f32 s);
    MtVector3& operator-=(const MtVector3& s);
    MtVector3& operator-=(f32 s);
    MtVector3& operator*=(const MtVector3& s);
    MtVector3& operator*=(f32 s);
    MtVector3 operator+(const MtVector3& s) const;
    MtVector3 operator+(f32 s) const;
    MtVector3 operator-(const MtVector3& s) const;
    MtVector3 operator-(f32 s) const;
    MtVector3 operator*(const MtVector3& s) const;
    MtVector3 operator*(f32 s) const;
    bool operator==(const MtVector3& s) const;
    bool operator!=(const MtVector3& s) const;
    bool isNearEqual(const MtVector3& s, const MtVector3& epsilon) const;
    const MtVector3 abs() const;
    const MtVector3 minimize(const MtVector3& v) const;
    const MtVector3 maximize(const MtVector3& v) const;
    static const MtVector3 lerp(const MtVector3& a, const MtVector3& b, f32 t);
    static const MtVector3 hermite(const MtVector3& v0, const MtVector3& v1, const MtVector3& d0, const MtVector3& d1, f32 t);
    static const MtVector3 catmullrom(const MtVector3&, const MtVector3&, const MtVector3&, const MtVector3&, f32);
    f32 innerProduct(const MtVector3& s) const;
    MtVector4 innerProductBq(const MtVector3& s) const;
    MtVector3 outerProduct(const MtVector3& t) const;
    const MtVector3 normalize() const;
    const MtVector3 normalizeFast() const;
    const MtVector3 normalizeEst() const;
    f32 length() const;
    MtVector4 lengthBq() const;
    f32 lengthSq() const;
    MtVector4 transform(const MtMatrix& m) const;
    MtVector3 transformCoord(const MtMatrix& m) const;
    MtVector3 transformNormal(const MtMatrix& m) const;
    void setLength(f32 len);
    MtVector3 sin() const;
    MtVector3 cos() const;
    MtVector3 tan() const;
    MtVector3 asin() const;
    MtVector3 atan() const;
    void sincos(MtVector3* psin, MtVector3* pcos) const;
    u32 closestAxis() const;
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    f32 z;  // offset: 0x8
private:
    f32 pad_;  // offset: 0xc
public:
    static const MtVector3 Zero;
    static const MtVector3 One;
    static const MtVector3 NegativeOne;
    static const MtVector3 AxisX;
    static const MtVector3 AxisY;
    static const MtVector3 AxisZ;
    static const MtVector3 Min;
    static const MtVector3 Max;
    static const MtVector3 Epsilon;
};

class alignas(16) MtVector4
{
public:
    MtVector4();
    explicit MtVector4(const f32* f);
    MtVector4(f32 _x, f32 _y, f32 _z);
    MtVector4(f32 _x, f32 _y, f32 _z, f32 _w);
    explicit MtVector4(f32 v);
    MtVector4(const MtQuaternion& v);
    MtVector4(const MtVector4& v);
    MtVector4(const MtVector3& v, f32 _w);
    MtVector4(const MtVector2& v, f32 _z, f32 _w);
    MtVector4(const MtFloat4& v);
    MtVector4(const MtFloat3& v, f32 _w);
    MtVector4(const MtFloat2& v, f32 _z, f32 _w);
    MtVector4(const MtFloat4A&);
    MtVector4(const MtFloat3A& v, f32 _w);
    MtVector4(const MtFloat2A&, f32, f32);
    MtVector4(const MtHalf4& v);
    const MtVector4& operator=(const MtQuaternion& v);
    const MtVector4& operator=(const MtVector4& v);
    const MtVector4& operator=(const MtFloat4& v);
    const MtVector4& operator=(const MtFloat4A&);
    const MtVector4& operator=(const MtHalf4&);
    const MtVector4& operator=(f32 v);
    operator float *();
    operator const float *() const;
    MtVector4 operator+() const;
    MtVector4 operator-() const;
    MtVector4& operator+=(const MtVector4& s);
    MtVector4& operator+=(f32);
    MtVector4& operator-=(const MtVector4& s);
    MtVector4& operator-=(f32);
    MtVector4& operator*=(const MtVector4& s);
    MtVector4& operator*=(f32 s);
    MtVector4 operator+(const MtVector4& s) const;
    MtVector4 operator+(f32 s) const;
    MtVector4 operator-(const MtVector4& s) const;
    MtVector4 operator-(f32) const;
    MtVector4 operator*(const MtVector4& s) const;
    MtVector4 operator*(f32 s) const;
    bool operator==(const MtVector4& s) const;
    bool operator!=(const MtVector4& s) const;
    bool isNearEqual(const MtVector4&, const MtVector4&) const;
    const MtVector4 abs() const;
    const MtVector4 minimize(const MtVector4& v) const;
    const MtVector4 maximize(const MtVector4& v) const;
    static const MtVector4 lerp(const MtVector4& a, const MtVector4& b, f32 t);
    static const MtVector4 hermite(const MtVector4& v0, const MtVector4& v1, const MtVector4& d0, const MtVector4& d1, f32 t);
    static const MtVector4 catmullrom(const MtVector4&, const MtVector4&, const MtVector4&, const MtVector4&, f32);
    f32 innerProduct(const MtVector4& s) const;
    f32 innerProduct(const MtVector3& s) const;
    MtVector4 innerProductBq(const MtVector4&) const;
    MtVector3 outerProduct(const MtVector3& t) const;
    const MtVector4 normalize() const;
    const MtVector4 normalizeFast() const;
    const MtVector4 normalizeEst() const;
    f32 length() const;
    MtVector4 lengthBq() const;
    f32 lengthSq() const;
    MtVector4 transform(const MtMatrix& m) const;
    MtVector4 transformPos(const MtMatrix& m) const;
    MtVector4 transformNormal(const MtMatrix& m) const;
    void setLength(f32 len);
    MtVector4 sin() const;
    MtVector4 cos() const;
    MtVector4 asin() const;
    MtVector4 acos() const;
    MtVector4 atan() const;
    void sincos(MtVector4*, MtVector4*) const;
    MtVector4 pow(const MtVector4&) const;
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    f32 z;  // offset: 0x8
    f32 w;  // offset: 0xc
    static const MtVector4 Zero;
    static const MtVector4 One;
    static const MtVector4 NegativeOne;
    static const MtVector4 Identity;
    static const MtVector4 AxisX;
    static const MtVector4 AxisY;
    static const MtVector4 AxisZ;
    static const MtVector4 AxisW;
    static const MtVector4 Min;
    static const MtVector4 Max;
    static const MtVector4 Epsilon;
};

class MtMatrix
{
public:
    MtMatrix();
    explicit MtMatrix(const f32*);
    MtMatrix(f32 m00, f32 m01, f32 m02, f32 m03, f32 m10, f32 m11, f32 m12, f32 m13, f32 m20, f32 m21, f32 m22, f32 m23, f32 m30, f32 m31, f32 m32, f32 m33);
    MtMatrix(const MtMatrix& s);
    MtMatrix(const MtMatrix33& v);
    MtMatrix(const MtFloat3x3& v);
    MtMatrix(const MtFloat4x3& v);
    MtMatrix(const MtFloat3x4& v);
    MtMatrix(const MtFloat4x4& v);
    MtMatrix(const MtQuaternion& rotation);
    MtMatrix(const MtQuaternion& rotation, const MtVector3& translation);
    void identity();
    MtMatrix& operator=(const MtMatrix& s);
    MtMatrix& operator=(const MtMatrix33&);
    MtMatrix& operator=(const MtFloat3x3&);
    MtMatrix& operator=(const MtFloat4x3&);
    MtMatrix& operator=(const MtFloat3x4&);
    MtMatrix& operator=(const MtFloat4x4& v);
    MtMatrix operator*(const MtMatrix& s) const;
    void operator*=(const MtMatrix& s);
    MtMatrix operator*(f32 s) const;
    MtMatrix operator+(const MtMatrix& s) const;
    void operator+=(const MtMatrix& s);
    bool operator==(const MtMatrix& s) const;
    bool operator!=(const MtMatrix& s) const;
    operator float *() const;
    void setRotateX(f32 a);
    void setRotateXFast(f32 a);
    void setRotateXSinCos(f32, f32);
    void setRotateY(f32 a);
    void setRotateYFast(f32 a);
    void setRotateYSinCos(f32 siny, f32 cosy);
    void setRotateZ(f32 a);
    void setRotateZFast(f32);
    void setRotateZSinCos(f32 sinz, f32 cosz);
    void setRotateXYZ(const MtVector3& v);
    void setRotateXZY(const MtVector3& v);
    void setRotateYXZ(const MtVector3& v);
    void setRotateYZX(const MtVector3& v);
    void setRotateZXY(const MtVector3& v);
    void setRotateZYX(const MtVector3& v);
    void setRotateAxis(const MtVector3& v, f32 a);
    void setRotateQuaternion(const MtQuaternion& q);
    void setRotTransQuaternion(const MtQuaternion& q, const MtVector3& t);
    void setRotateVectorXY(const MtVector3&, const MtVector3&, const MtVector3&);
    void setRotateVectorXZ(const MtVector3&, const MtVector3&, const MtVector3&);
    void setRotateVectorYX(const MtVector3&, const MtVector3&, const MtVector3&);
    void setRotateVectorYZ(const MtVector3&, const MtVector3&, const MtVector3&);
    void setRotateVectorZX(const MtVector3&, const MtVector3&, const MtVector3&);
    void setRotateVectorZY(const MtVector3&, const MtVector3&, const MtVector3&);
    void setTranslate(const MtVector3& v);
    void setScale(const MtVector3& v);
    void setRotTransXYZ(const MtVector3& v, const MtVector3& trans);
    void setMulMatrix(const MtMatrix& a, const MtMatrix& b);
    void setMulTransposeMatrix(const MtMatrix& a, const MtMatrix& b);
    void mulScale(const MtVector3& v);
    void mulRotateX(f32 a);
    void mulRotateY(f32 a);
    void mulRotateZ(f32 a);
    void setRotateAxisFast(const MtVector3&, f32);
    void mulRotateXFast(f32);
    void mulRotateYFast(f32 a);
    void mulRotateZFast(f32);
    void mulTranslate(const MtVector3& v);
    void mulRotTransXYZ(const MtVector3& rot, const MtVector3& trans);
    void mulMatrix(const MtMatrix& s);
    void setLookAtRH(const MtVector3& eye, const MtVector3& at, const MtVector3& up);
    void setLookAtLH(const MtVector3& eye, const MtVector3& at, const MtVector3& up);
    void setPerspectiveFovRH(f32 near_plane, f32 far_plane, f32 fov, f32 aspect);
    void setPerspectiveFovLH(f32 near_plane, f32 far_plane, f32 fov, f32 aspect);
    void setPerspectiveRH(f32 w, f32 h, f32 near_plane, f32 far_plane);
    void setPerspectiveLH(f32 w, f32 h, f32 near_plane, f32 far_plane);
    void setOrthoRH(f32 w, f32 h, f32 zn, f32 zf);
    void setOrthoLH(f32 w, f32 h, f32 zn, f32 zf);
    void setFrustum(f32 left, f32 right, f32 bottom, f32 top, f32 nearval, f32 farval);
    void setAxisZ(const MtVector3& pos, const MtVector3& dir);
    void setTranspose3x4(const MtFloat3x4& t);
    MtMatrix inverseFast() const;
    MtMatrix inverse() const;
    MtMatrix transpose() const;
    MtFloat3x4 transpose3x4() const;
    MtMatrix orthogonalize() const;
    const MtVector3 eulerAngleXYZ() const;
    const MtVector3 eulerAngleXZY() const;
    const MtVector3 eulerAngleYXZ() const;
    const MtVector3 eulerAngleYZX() const;
    const MtVector3 eulerAngleZXY() const;
    const MtVector3 eulerAngleZYX() const;
    void setInterpolationXY(const MtMatrix& _a, const MtMatrix& _s, f32 rate);
    void setProjection(const MtVector4& _plane, const MtVector4& _dir);
    void setReflection(const MtVector4& _plane);
    void setAxisX(const MtVector3&);
    void setAxisY(const MtVector3&);
    void setAxisZ(const MtVector3&);
    void setPos(const MtVector3& pos);
    MtVector3 axisX() const;
    MtVector3 axisY() const;
    MtVector3 axisZ() const;
    MtVector3 pos() const;
public:
    MtVector4 m[4];  // offset: 0x0
    static const MtMatrix Zero;
    static const MtMatrix Identity;
    static const MtMatrix RGB2YCbCr;
    static const MtMatrix YCbCr2RGB;
};

inline MtFloat2::MtFloat2() {
}

inline MtFloat3::MtFloat3() {
}

inline MtFloat3A::MtFloat3A() {
}

inline MtFloat3x3::MtFloat3x3() {
}

inline MtFloat3x4::MtFloat3x4() {
}

inline MtFloat4::MtFloat4() {
}

inline MtFloat4::MtFloat4(f32 _x, f32 _y, f32 _z, f32 _w) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
    this->w = _w;
}

inline MtFloat4A::MtFloat4A() {
}

inline MtFloat4x3::MtFloat4x3() {
}

inline MtFloat4x4::MtFloat4x4() {
}

inline MtHalf4::MtHalf4() {
}

inline MtInt2::MtInt2() {
}

inline s32 MtMath::absi(s32 i) {
    return (i ^ (i >> 31)) - (i >> 31);
}

inline MtMatrix::MtMatrix() {
}

inline MtMatrix::MtMatrix(const MtMatrix& s) {
    this->m[0] = s.m[0];
    this->m[1] = s.m[1];
    this->m[2] = s.m[2];
    this->m[3] = s.m[3];
}

inline MtMatrix::MtMatrix(const MtFloat3x3& v) {
    this->m[0] = MtVector4(v.m[0][0], v.m[0][1], v.m[0][2], 0.0f);
    this->m[1] = MtVector4(v.m[1][0], v.m[1][1], v.m[1][2], 0.0f);
    this->m[2] = MtVector4(v.m[2][0], v.m[2][1], v.m[2][2], 0.0f);
    this->m[3] = MtVector4(0.0f, 0.0f, 0.0f, 1.0f);
}

inline MtMatrix::MtMatrix(const MtFloat4x3& v) {
    this->m[0] = MtVector4(v.m[0][0], v.m[0][1], v.m[0][2], 0.0f);
    this->m[1] = MtVector4(v.m[1][0], v.m[1][1], v.m[1][2], 0.0f);
    this->m[2] = MtVector4(v.m[2][0], v.m[2][1], v.m[2][2], 0.0f);
    this->m[3] = MtVector4(v.m[3][0], v.m[3][1], v.m[3][2], 1.0f);
}

inline MtMatrix::MtMatrix(const MtFloat3x4& v) {
    this->m[0] = MtVector4(v.m[0][0], v.m[0][1], v.m[0][2], v.m[0][3]);
    this->m[1] = MtVector4(v.m[1][0], v.m[1][1], v.m[1][2], v.m[1][3]);
    this->m[2] = MtVector4(v.m[2][0], v.m[2][1], v.m[2][2], v.m[2][3]);
    this->m[3] = MtVector4(0.0f, 0.0f, 0.0f, 1.0f);
}

inline MtMatrix::MtMatrix(const MtFloat4x4& v) {
    this->m[0] = MtVector4(v.m[0][0], v.m[0][1], v.m[0][2], v.m[0][3]);
    this->m[1] = MtVector4(v.m[1][0], v.m[1][1], v.m[1][2], v.m[1][3]);
    this->m[2] = MtVector4(v.m[2][0], v.m[2][1], v.m[2][2], v.m[2][3]);
    this->m[3] = MtVector4(v.m[3][0], v.m[3][1], v.m[3][2], v.m[3][3]);
}

inline MtQuaternion::MtQuaternion() {
}

inline MtQuaternion::MtQuaternion(const MtQuaternion& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
}

inline const MtQuaternion& MtQuaternion::operator=(const MtQuaternion& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
    return *this;
}

inline MtVector2::MtVector2() {
}

inline MtVector2::MtVector2(const MtVector2& v) {
    this->x = v.x;
    this->y = v.y;
}

inline const MtVector2& MtVector2::operator=(const MtVector2& v) {
    this->x = v.x;
    this->y = v.y;
    return *this;
}

inline MtVector3::MtVector3() {
    this->pad_ = 0.0f;
}

inline const MtVector3& MtVector3::operator=(const MtVector3& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->pad_ = 0.0f;
    return *this;
}

inline const MtVector3& MtVector3::operator=(const MtFloat3& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->pad_ = 0.0f;
    return *this;
}

inline MtVector4::MtVector4() {
}

inline MtVector4::MtVector4(const MtVector4& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
}

inline MtVector3::MtVector3(const MtVector3& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->pad_ = 0.0f;
}

inline bool MtVector3::operator==(const MtVector3& s) const {
    return x == s.x && y == s.y && z == s.z;
}

inline const MtVector4& MtVector4::operator=(const MtFloat4& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
    return *this;
}

inline MtFloat3A::MtFloat3A(f32 _x, f32 _y, f32 _z) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
}

inline const MtFloat3A& MtFloat3A::operator=(const MtVector3& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
}

inline MtVector3::MtVector3(f32 _x, f32 _y, f32 _z) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
    this->pad_ = 0.0f;
}

inline MtVector3::MtVector3(f32 v) {
    this->x = v;
    this->y = v;
    this->z = v;
    this->pad_ = 0.0f;
}

inline MtVector3 MtVector3::operator+(const MtVector3& s) const {
    return MtVector3(this->x + s.x, this->y + s.y, this->z + s.z);
}

inline MtVector3 MtVector3::operator+(f32 s) const {
    return MtVector3(this->x + s, this->y + s, this->z + s);
}

inline MtVector3 MtVector3::operator-(const MtVector3& s) const {
    return MtVector3(this->x - s.x, this->y - s.y, this->z - s.z);
}

inline f32 MtVector3::innerProduct(const MtVector3& s) const {
    return (x * s.x + y * s.y) + z * s.z;
}

inline f32 MtVector3::lengthSq() const {
    return innerProduct(*this);
}

inline const MtVector3 MtVector3::normalizeFast() const {
    return *this * (1.0f / __builtin_sqrtf(lengthSq()));
}

inline MtVector3 MtVector3::operator-(f32 s) const {
    return MtVector3(this->x - s, this->y - s, this->z - s);
}

inline const MtVector3 MtVector3::minimize(const MtVector3& v) const {
    return MtVector3(
        this->x < v.x ? this->x : v.x,
        this->y < v.y ? this->y : v.y,
        this->z < v.z ? this->z : v.z
    );
}

inline const MtVector3 MtVector3::maximize(const MtVector3& v) const {
    return MtVector3(
        this->x > v.x ? this->x : v.x,
        this->y > v.y ? this->y : v.y,
        this->z > v.z ? this->z : v.z
    );
}

inline MtVector4::MtVector4(f32 _x, f32 _y, f32 _z, f32 _w) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
    this->w = _w;
}

inline MtVector4::MtVector4(const MtVector3& v, f32 _w) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = _w;
}

inline const MtVector4& MtVector4::operator=(const MtVector4& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
    return *this;
}

inline void MtMatrix::identity() {
    this->m[0] = MtVector4(1.0f, 0.0f, 0.0f, 0.0f);
    this->m[1] = MtVector4(0.0f, 1.0f, 0.0f, 0.0f);
    this->m[2] = MtVector4(0.0f, 0.0f, 1.0f, 0.0f);
    this->m[3] = MtVector4(0.0f, 0.0f, 0.0f, 1.0f);
}

inline void MtMatrix::setTranslate(const MtVector3& v) {
    this->m[0] = MtVector4(1.0f, 0.0f, 0.0f, 0.0f);
    this->m[1] = MtVector4(0.0f, 1.0f, 0.0f, 0.0f);
    this->m[2] = MtVector4(0.0f, 0.0f, 1.0f, 0.0f);
    this->m[3] = MtVector4(v, 1.0f);
}

inline MtMatrix& MtMatrix::operator=(const MtMatrix& s) {
    this->m[0] = s.m[0];
    this->m[1] = s.m[1];
    this->m[2] = s.m[2];
    this->m[3] = s.m[3];
    return *this;
}
