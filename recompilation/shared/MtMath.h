#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtAABB;
class MtCollision;
struct MtFloat2A;
struct MtFloat4A;
class MtGeomAABB;
class MtGeomCapsule;
class MtGeomCylinder;
class MtGeomLineSegment;
class MtGeomOBB;
class MtGeomSphere;
class MtGeomTriangle;
struct MtHalf2;
struct MtInt3;
class MtMatrix33;
class MtTriangle;
class cBVHCollision;
class cChildRegionStatus;
class cCommonSkyFogData;
class cContextInterface;
class cCustomWeatherParam;
class cGroupParam;
class cJumpParamCtrl;
class cPlActWpnBow;
class cSetInfoOmBadStatus;
class cSetInfoOmDoor;
class cSetInfoOmNav;
class cShlLogNode;
class cSoundZoneListener;
class cStageEpvCtrl;
class cpCatchCtrl;
class cpHeadCtrl;
class cpHugeble;
class cpHumanWarpCtrl;
class cpJob02;
class cpJob09;
class cpObjCollisionBase;
class cpShakeCtrl;
class cpSlave;
namespace nShlStick { class cStickObjectCtrl; }
namespace nZone { class ShapeInfoPanel; }
class rNavigationMesh;
class sCollision;
class sEffect;
class sEffectExt;
class sGUIExt;
class sGame;
class sSoundManager;
class sWorldOffset;
class uBaseEffect;
class uCharacter;
class uCnsDDOIK;
class uCorePointSearch;
class uCustomSimSoftBody;
class uDDOModel;
class uEffect;
class uEnemy;
class uGUIAim;
class uGUIGaugeEnemy;
class uGUIGaugeNpcBase;
class uHuman;
class uLight;
class uShlBase;
class uSimSoftBody;
class uSky;

// Declarations
struct MtFloat2;
struct MtFloat3;
struct MtFloat3A;
struct MtFloat3x3;
struct MtFloat3x4;
struct MtFloat4;
struct MtFloat4x3;
struct MtFloat4x4;
struct MtHalf4;
struct MtInt2;
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
    // inferred: MtAABB::getSurfaceVertex names MtVector3::pad_
    friend class MtAABB;
    // inferred: MtCollision::getAABBVertex names MtVector3::pad_
    friend class MtCollision;
    // inferred: MtGeomAABB::load names MtGeomAABB::mAABB.minpos.pad_
    friend class MtGeomAABB;
    // inferred: MtGeomCapsule::load names MtGeomCapsule::mCapsule.p0.pad_
    friend class MtGeomCapsule;
    // inferred: MtGeomCylinder::load names MtGeomCylinder::mCylinder.p0.pad_
    friend class MtGeomCylinder;
    // inferred: MtGeomLineSegment::load names MtGeomLineSegment::mLineSegment.p0.pad_
    friend class MtGeomLineSegment;
    // inferred: MtGeomOBB::load names MtGeomOBB::mOBB.extent.pad_
    friend class MtGeomOBB;
    // inferred: MtGeomSphere::getBoundingAABB names MtAABB::minpos.pad_
    friend class MtGeomSphere;
    // inferred: MtGeomTriangle::load names MtGeomTriangle::mTriangle.p0.pad_
    friend class MtGeomTriangle;
    // inferred: MtTriangle::getNearestEdgeFromUVW names MtLineSegment::p0.pad_
    friend class MtTriangle;
    // inferred: cBVHCollision::buildOnlineFast names cBVHCollision::mHeader.aabb.minpos.pad_
    friend class cBVHCollision;
    // inferred: cChildRegionStatus::setParamFromRes names cChildRegionStatus::mCoreJointOffset.pad_
    friend class cChildRegionStatus;
    // inferred: cCommonSkyFogData::init names cCommonSkyFogData::mColor.pad_
    friend class cCommonSkyFogData;
    // inferred: cContextInterface::setCatchHitPos names cContextCharacter::mCatchHitPos.pad_
    friend class cContextInterface;
    // inferred: cCustomWeatherParam::setCustomShadowDir names cCustomWeatherParam::mCustomShadowDir.pad_
    friend class cCustomWeatherParam;
    // inferred: cGroupParam::setMarkerPos names cGroupParam::mMarkerPos.pad_
    friend class cGroupParam;
    // inferred: cJumpParamCtrl::updatePadAdjustPos names uCoord::mPos.pad_
    friend class cJumpParamCtrl;
    // inferred: cPlActWpnBow::initLow_Wait names uDDOModel::mVelocity.pad_
    friend class cPlActWpnBow;
    // inferred: cSetInfoOmBadStatus::applyParam names cOmControl::InputLot::mBadPos.pad_
    friend class cSetInfoOmBadStatus;
    // inferred: cSetInfoOmDoor::applyParam names cOmControl::InputLot::mPRTPos.pad_
    friend class cSetInfoOmDoor;
    // inferred: cSetInfoOmNav::applyParam names cOmControl::InputLot::mNavOBBExtent.pad_
    friend class cSetInfoOmNav;
    // inferred: cShlLogNode::keepLog names cShlLogNode::mPos.pad_
    friend class cShlLogNode;
    // inferred: cSoundZoneListener::setMyPos names cSoundZoneListener::mMyPos.pad_
    friend class cSoundZoneListener;
    // inferred: cStageEpvCtrl::setOfsPos names cStageEpvCtrl::mOfsPos.pad_
    friend class cStageEpvCtrl;
    // inferred: cpCatchCtrl::forceCancel names cpCatchCtrl::mCatchInfo.mHitPos.pad_
    friend class cpCatchCtrl;
    // inferred: cpHeadCtrl::setTargetPos names cpHeadCtrl::mTargetPos.pad_
    friend class cpHeadCtrl;
    // inferred: cpHugeble::resetHugebleOldPos names cpHugeble::mHugebleOldPos.pad_
    friend class cpHugeble;
    // inferred: cpHumanWarpCtrl::requestOneWayWarp names cpHumanWarpCtrl::mHumanWarpInfo.elems[0].mWarpWorldPos.pad_
    friend class cpHumanWarpCtrl;
    // inferred: cpJob02::update names uHuman::mCameraExPos.pad_
    friend class cpJob02;
    // inferred: cpJob09::resetEffectCtrlData names cpJob09::mAlchemyCoreOfset.pad_
    friend class cpJob09;
    // inferred: cpObjCollisionBase::objAdjust names MtVector3::pad_
    friend class cpObjCollisionBase;
    // inferred: cpShakeCtrl::shake names cpShakeCtrl::mDir.pad_
    friend class cpShakeCtrl;
    // inferred: cpSlave::interpolatePos names uCoord::mPos.pad_
    friend class cpSlave;
    // inferred: nShlStick::cStickObjectCtrl::storeStickInfo names nShlStick::cStickObjectCtrl::mCapsule.p0.pad_
    friend class nShlStick::cStickObjectCtrl;
    // inferred: nZone::ShapeInfoPanel::reversePanelDirection names nZone::ShapeInfoPanel::mVertex[1].pad_
    friend class nZone::ShapeInfoPanel;
    // inferred: rNavigationMesh::setNodeInfo names rNavigationMesh::nodeInfo::mAABB.minpos.pad_
    friend class rNavigationMesh;
    // inferred: sCollision::enumSphereTriBeforeFunc names sCollision::ScrCollisionInfo::workVec[3].pad_
    friend class sCollision;
    // inferred: sEffect::setForcePower names sEffect::mForceVec.pad_
    friend class sEffect;
    // inferred: sEffectExt::getZoneCheckPos names MtVector3::pad_
    friend class sEffectExt;
    // inferred: sGUIExt::setBrowserPos names uCoord::mPos.pad_
    friend class sGUIExt;
    // inferred: sGame::initPlayerUnit names uCoord::mPos.pad_
    friend class sGame;
    // inferred: sSoundManager::startBarReq names sSoundManager::mBarPos.pad_
    friend class sSoundManager;
    // inferred: sWorldOffset::clear names sWorldOffset::mWorldOffset.pad_
    friend class sWorldOffset;
    // inferred: uBaseEffect::setOfs names uBaseEffect::mOfs.pad_
    friend class uBaseEffect;
    // inferred: uCharacter::resetPos names uCharacter::mCheatCheckOldPos.pad_
    friend class uCharacter;
    // inferred: uCnsDDOIK::setEffectorPos names uCnsDDOIK::mEffectorPos.pad_
    friend class uCnsDDOIK;
    // inferred: uCorePointSearch::initCoreSearch names uCorePointSearch::mOffset0.pad_
    friend class uCorePointSearch;
    // inferred: uCustomSimSoftBody::getTargetBoundingAABB names MtAABB::minpos.pad_
    friend class uCustomSimSoftBody;
    // inferred: uDDOModel::setTargetPos names uDDOModel::mTargetPos.pad_
    friend class uDDOModel;
    // inferred: uEffect::setupUnitGenerator names cEffectJoint::mUpdateConstWorldOfs.pad_
    friend class uEffect;
    // inferred: uEnemy::setFsmTarget names uEnemy::mFsmTargetPos.pad_
    friend class uEnemy;
    // inferred: uGUIAim::setTargetMarkerPos names uGUIAim::cTargetMarker::mTargetPos.pad_
    friend class uGUIAim;
    // inferred: uGUIGaugeEnemy::move names uGUIGaugeEnemy::mWorldOffset.pad_
    friend class uGUIGaugeEnemy;
    // inferred: uGUIGaugeNpcBase::move names uGUIGaugeNpcBase::mWorldOffset.pad_
    friend class uGUIGaugeNpcBase;
    // inferred: uHuman::setupContextEnemyClimb names uHuman::mClimbJointOffset.pad_
    friend class uHuman;
    // inferred: uLight::setColor names uLight::mColor.pad_
    friend class uLight;
    // inferred: uShlBase::setShotCoord names uCoord::mPos.pad_
    friend class uShlBase;
    // inferred: uSimSoftBody::applyWorldOffset names uSimSoftBody::mWorldOffset.pad_
    friend class uSimSoftBody;
    // inferred: uSky::setMieScattering names uSky::mMieScattering.pad_
    friend class uSky;
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

// Inline, no code of its own: checked where it is inlined.
inline MtFloat3::MtFloat3() {
}

// Inline, no code of its own: checked where it is inlined.
inline MtFloat3A::MtFloat3A() {
}

// Inline, no code of its own: checked where it is inlined.
inline MtMatrix::MtMatrix() {
}

// Inline, no code of its own: checked where it is inlined.
inline MtQuaternion::MtQuaternion(const MtQuaternion& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
}

// Inline, no code of its own: checked where it is inlined.
inline MtVector2::MtVector2(const MtVector2& v) {
    this->x = v.x;
    this->y = v.y;
}

// Inline, no code of its own: checked where it is inlined.
inline MtVector3::MtVector3() {
    this->pad_ = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline const MtVector3& MtVector3::operator=(const MtFloat3& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->pad_ = 0.0f;
    // inferred: the conventional `return *this;` of an assignment operator whose copies never use its result
    return *this;
}

// Inline, no code of its own: checked where it is inlined.
inline MtVector4::MtVector4() {
}

// Inline, no code of its own: checked where it is inlined.
inline MtVector4::MtVector4(const MtVector4& v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
}
