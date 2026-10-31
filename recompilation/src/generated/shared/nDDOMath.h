#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtCapsule;
class MtMatrix;
class MtQuaternion;
class MtRay;
class MtSphere;
class MtVector2;
class MtVector3;
class uCoord;

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using u32 = unsigned int;

namespace nDDOMath {

    bool checkFloat(f32 value);
    bool checkFloat(const MtVector3& v);
    bool checkFloat(const MtQuaternion& q);
    bool checkFloat(const MtMatrix& mat);
    f32 getLength(const MtVector3& v0, const MtVector3& v1);
    f32 getLengthXZ(const MtVector3& v0, const MtVector3& v1);
    f32 clampRadian(f32 rad);
    f32 getTargetRadianY(const MtVector3& v0, const MtVector3& v1);
    f32 getRadianDifference(f32 rad1, f32 rad2);
    MtVector3 calcVelocityXZ(f32 speed, f32 rotY);
    MtVector3 calcVelocityXZ(f32 speed, const MtMatrix& m);
    f32 calcAngLimit(f32 ang);
    f32 calcXZAngle(const MtVector3& v0, const MtVector3& v1);
    f32 calcYZAngle(const MtVector3& v0, const MtVector3& v1);
    f32 calcAngle(const MtVector3& v0, const MtVector3& v1);
    f32 calcAngleSign(const MtVector3& v0, const MtVector3& v1, const MtVector3& Axis);
    bool isFront(const MtVector3& Pos0, const MtVector3& Pos1, const MtMatrix& MyWorldMatrix, f32 rangeAngY);
    bool isFront(const MtVector3& Pos0, const MtVector3& Pos1, f32 myAngY, f32 rangeAngY);
    bool isRange(const MtVector3& Pos0, const MtVector3& Pos1, f32 myAngY, f32 rangeAngY0, f32 rangeAngY1);
    const MtQuaternion calcQuaternionFromRotationXYZ(const MtVector3& rot);
    const MtQuaternion getQuatAngleY(f32 AngleY);
    bool calcRotateVectorXY(MtMatrix& mat, const MtVector3& DirX, const MtVector3& UpY);
    bool calcRotateVectorYZ(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpZ);
    bool calcRotateVectorYX(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpX);
    bool isRange(const MtVector3& Pos0, const MtVector3& Pos1, const MtMatrix& MyWorldMatrix, f32 rangeAngY0, f32 rangeAngY1);
    bool isInSide(const MtVector3& Pos0, const MtVector3& Pos1, f32 range, f32 min);
    bool isInSideXZ(const MtVector3& Pos0, const MtVector3& Pos1, f32 range, f32 min);
    const MtQuaternion lerpConstant(const MtQuaternion& q0, const MtQuaternion& q1, f32 rad);
    const MtVector3 lerpConstant(const MtVector3& v0, const MtVector3& v1, f32 diff);
    f32 lerpConstant(f32 a, f32 b, f32 diff);
    f32 getDifference(f32 ang1, f32 ang2);
    f32 lerpAngleConstant(f32 CurrentAngle, f32 TargetAngle, f32 max);
    u32 lerp(u32 a, u32 b, f32 rate);
    f32 lerp(f32 a, f32 b, f32 rate);
    MtVector3 lerp(MtVector3& v0, MtVector3& v2, f32 rate);
    const MtQuaternion calcQuaternionFromRotationX(f32 AngleX);
    const MtQuaternion calcQuaternionFromRotationY(f32 AngleY);
    const MtQuaternion calcQuaternionFromRotationZ(f32 AngleZ);
    const MtQuaternion calcQuaternionFromRotationXYZ(f32 rotx, f32 roty, f32 rotz);
    f32 accelerate(f32 speed, f32 acc);
    const MtVector3 accelerate(const MtVector3& vel, f32 acc);
    const MtVector3 accelerateXZ(const MtVector3& vel, f32 acc);
    f32 random(f32 min, f32 max);
    bool calcRotateVectorXY(MtMatrix& mat, const MtVector3& DirX, const MtVector3& UpY, const MtVector3& UpY2, const MtVector3& Pos);
    bool calcRotateVectorXZ(MtMatrix& mat, const MtVector3& DirX, const MtVector3& UpZ, const MtVector3& UpZ2, const MtVector3& Pos);
    bool calcRotateVectorYX(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpX, const MtVector3& UpX2, const MtVector3& Pos);
    bool calcRotateVectorYZ(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpZ, const MtVector3& UpZ2, const MtVector3& Pos);
    bool calcRotateVectorZX(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpX, const MtVector3& UpX2, const MtVector3& Pos);
    bool calcRotateVectorZY(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpY, const MtVector3& UpY2, const MtVector3& Pos);
    bool calcRotateVectorXY(MtQuaternion& q, const MtVector3& DirX, const MtVector3& UpY);
    bool calcRotateVectorXZ(MtQuaternion& q, const MtVector3& DirX, const MtVector3& UpZ);
    bool calcRotateVectorYX(MtQuaternion& q, const MtVector3& DirY, const MtVector3& UpX);
    bool calcRotateVectorYZ(MtQuaternion& q, const MtVector3& DirY, const MtVector3& UpZ);
    bool calcRotateVectorZX(MtQuaternion& q, const MtVector3& DirZ, const MtVector3& UpX);
    bool calcRotateVectorZY(MtQuaternion& q, const MtVector3& DirZ, const MtVector3& UpY);
    bool isOppositeVec(const MtVector3& vec1, const MtVector3& vec2, f32 angle);
    bool isOpposite(const MtMatrix& mat1, const MtMatrix& mat2, f32 angle);
    MtMatrix setMatrixAngle(const MtVector3& angle, u32 order);
    MtVector3 getMatrixAngle(MtMatrix& mat, u32 order);
    f32 getAngleFromVector(const MtVector3& v);
    MtVector3 getVectorFromAngle(f32 rad);
    MtVector3 calcReflectVector(const MtVector3& normal, const MtVector3& vec);
    MtVector3 alignVectorXZ(const MtVector3& OrgVec, const MtVector3& Dir);
    f32 dd_acos(f32 cs);
    double dd_acos(double cs);
    f32 dd_asin(f32 sn);
    double dd_asin(double sn);
    void closest(const MtVector3& pos, const MtSphere& sphere, MtVector3& ResultHitPos, MtVector3& ResultHitNormal);
    void closest(const MtVector3& pos, const MtCapsule& capsule, MtVector3& ResultHitPos, MtVector3& ResultHitNormal);
    MtVector3 calcAimScr(const MtVector3& pos, MtRay& ray);
    MtRay calcCameraRay();
    MtVector3 calcAimScrNormal(MtRay& ray, u32 coltype);
    MtVector2 calcRotateVec2(const MtVector2& v2Dir, f32 fRot);
    s32 getSumPOD(s32 sValue, s32 sSub, u32 uNum);
    MtVector3 normalizeOwnerXZ(const MtVector3& vec, uCoord& owner);
    f32 getLengthSqXZ(const MtVector3& pos1, const MtVector3& pos2);
    bool calcRotateVectorZX(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpX);
    bool calcRotateVectorZY(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpY);
    bool calcRotateVectorXYPos(MtMatrix& mat, const MtVector3& DirX, const MtVector3& UpY, const MtVector3& Pos);
    bool calcRotateVectorYXPos(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpX, const MtVector3& Pos);
    bool calcRotateVectorYZPos(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpZ, const MtVector3& Pos);
    bool calcRotateVectorZYPos(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpY, const MtVector3& Pos);
    MtVector3 deg2rad(const MtVector3& deg_vector);

}  // namespace nDDOMath
