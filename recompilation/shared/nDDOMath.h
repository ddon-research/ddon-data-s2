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
    bool checkFloat(const MtVector3& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:48
    bool checkFloat(const MtQuaternion& q);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:63
    bool checkFloat(const MtMatrix& mat);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:81
    f32 getLength(const MtVector3& v0, const MtVector3& v1);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:136
    f32 getLengthXZ(const MtVector3& v0, const MtVector3& v1);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:151
    f32 clampRadian(f32 rad);
    f32 getTargetRadianY(const MtVector3& v0, const MtVector3& v1);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:170
    f32 getRadianDifference(f32 rad1, f32 rad2);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:186
    MtVector3 calcVelocityXZ(f32 speed, f32 rotY);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:228
    MtVector3 calcVelocityXZ(f32 speed, const MtMatrix& m);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:241
    f32 calcAngLimit(f32 ang);
    f32 calcXZAngle(const MtVector3& v0, const MtVector3& v1);
    f32 calcYZAngle(const MtVector3& v0, const MtVector3& v1);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:305
    f32 calcAngle(const MtVector3& v0, const MtVector3& v1);
    f32 calcAngleSign(const MtVector3& v0, const MtVector3& v1, const MtVector3& Axis);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:345
    bool isFront(const MtVector3& Pos0, const MtVector3& Pos1, const MtMatrix& MyWorldMatrix, f32 rangeAngY);
    bool isFront(const MtVector3& Pos0, const MtVector3& Pos1, f32 myAngY, f32 rangeAngY);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:366
    bool isRange(const MtVector3& Pos0, const MtVector3& Pos1, f32 myAngY, f32 rangeAngY0, f32 rangeAngY1);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:415
    const MtQuaternion calcQuaternionFromRotationXYZ(const MtVector3& rot);
    const MtQuaternion getQuatAngleY(f32 AngleY);
    bool calcRotateVectorXY(MtMatrix& mat, const MtVector3& DirX, const MtVector3& UpY);
    bool calcRotateVectorYZ(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpZ);
    bool calcRotateVectorYX(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpX);
    bool isRange(const MtVector3& Pos0, const MtVector3& Pos1, const MtMatrix& MyWorldMatrix, f32 rangeAngY0, f32 rangeAngY1);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:436
    bool isInSide(const MtVector3& Pos0, const MtVector3& Pos1, f32 range, f32 min);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:510
    bool isInSideXZ(const MtVector3& Pos0, const MtVector3& Pos1, f32 range, f32 min);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:549
    const MtQuaternion lerpConstant(const MtQuaternion& q0, const MtQuaternion& q1, f32 rad);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:599
    const MtVector3 lerpConstant(const MtVector3& v0, const MtVector3& v1, f32 diff);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:672
    f32 lerpConstant(f32 a, f32 b, f32 diff);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:703
    f32 getDifference(f32 ang1, f32 ang2);
    f32 lerpAngleConstant(f32 CurrentAngle, f32 TargetAngle, f32 max);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:747
    u32 lerp(u32 a, u32 b, f32 rate);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:778
    f32 lerp(f32 a, f32 b, f32 rate);
    MtVector3 lerp(MtVector3& v0, MtVector3& v2, f32 rate);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:795
    const MtQuaternion calcQuaternionFromRotationX(f32 AngleX);
    const MtQuaternion calcQuaternionFromRotationY(f32 AngleY);
    const MtQuaternion calcQuaternionFromRotationZ(f32 AngleZ);
    const MtQuaternion calcQuaternionFromRotationXYZ(f32 rotx, f32 roty, f32 rotz);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:857
    f32 accelerate(f32 speed, f32 acc);
    const MtVector3 accelerate(const MtVector3& vel, f32 acc);
    const MtVector3 accelerateXZ(const MtVector3& vel, f32 acc);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:974
    f32 random(f32 min, f32 max);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:996
    bool calcRotateVectorXY(MtMatrix& mat, const MtVector3& DirX, const MtVector3& UpY, const MtVector3& UpY2, const MtVector3& Pos);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1020
    bool calcRotateVectorXZ(MtMatrix& mat, const MtVector3& DirX, const MtVector3& UpZ, const MtVector3& UpZ2, const MtVector3& Pos);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1034
    bool calcRotateVectorYX(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpX, const MtVector3& UpX2, const MtVector3& Pos);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1048
    bool calcRotateVectorYZ(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpZ, const MtVector3& UpZ2, const MtVector3& Pos);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1062
    bool calcRotateVectorZX(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpX, const MtVector3& UpX2, const MtVector3& Pos);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1077
    bool calcRotateVectorZY(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpY, const MtVector3& UpY2, const MtVector3& Pos);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1092
    bool calcRotateVectorXY(MtQuaternion& q, const MtVector3& DirX, const MtVector3& UpY);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1107
    bool calcRotateVectorXZ(MtQuaternion& q, const MtVector3& DirX, const MtVector3& UpZ);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1120
    bool calcRotateVectorYX(MtQuaternion& q, const MtVector3& DirY, const MtVector3& UpX);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1133
    bool calcRotateVectorYZ(MtQuaternion& q, const MtVector3& DirY, const MtVector3& UpZ);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1146
    bool calcRotateVectorZX(MtQuaternion& q, const MtVector3& DirZ, const MtVector3& UpX);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1159
    bool calcRotateVectorZY(MtQuaternion& q, const MtVector3& DirZ, const MtVector3& UpY);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1172
    bool isOppositeVec(const MtVector3& vec1, const MtVector3& vec2, f32 angle);
    bool isOpposite(const MtMatrix& mat1, const MtMatrix& mat2, f32 angle);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1227
    MtMatrix setMatrixAngle(const MtVector3& angle, u32 order);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1249
    MtVector3 getMatrixAngle(MtMatrix& mat, u32 order);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1274
    f32 getAngleFromVector(const MtVector3& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1295
    MtVector3 getVectorFromAngle(f32 rad);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1318
    MtVector3 calcReflectVector(const MtVector3& normal, const MtVector3& vec);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1338
    MtVector3 alignVectorXZ(const MtVector3& OrgVec, const MtVector3& Dir);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1351
    f32 dd_acos(f32 cs);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1381
    double dd_acos(double cs);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1394
    f32 dd_asin(f32 sn);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1414
    double dd_asin(double sn);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1427
    void closest(const MtVector3& pos, const MtSphere& sphere, MtVector3& ResultHitPos, MtVector3& ResultHitNormal);
    void closest(const MtVector3& pos, const MtCapsule& capsule, MtVector3& ResultHitPos, MtVector3& ResultHitNormal);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1464
    MtVector3 calcAimScr(const MtVector3& pos, MtRay& ray);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1519
    MtRay calcCameraRay();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1618
    MtVector3 calcAimScrNormal(MtRay& ray, u32 coltype);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1633
    MtVector2 calcRotateVec2(const MtVector2& v2Dir, f32 fRot);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1717
    s32 getSumPOD(s32 sValue, s32 sSub, u32 uNum);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1736
    MtVector3 normalizeOwnerXZ(const MtVector3& vec, uCoord& owner);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1754
    f32 getLengthSqXZ(const MtVector3& pos1, const MtVector3& pos2);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOMath.cpp:1771
    bool calcRotateVectorZX(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpX);
    bool calcRotateVectorZY(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpY);
    bool calcRotateVectorXYPos(MtMatrix& mat, const MtVector3& DirX, const MtVector3& UpY, const MtVector3& Pos);
    bool calcRotateVectorYXPos(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpX, const MtVector3& Pos);
    bool calcRotateVectorYZPos(MtMatrix& mat, const MtVector3& DirY, const MtVector3& UpZ, const MtVector3& Pos);
    bool calcRotateVectorZYPos(MtMatrix& mat, const MtVector3& DirZ, const MtVector3& UpY, const MtVector3& Pos);
    MtVector3 deg2rad(const MtVector3& deg_vector);

}  // namespace nDDOMath
