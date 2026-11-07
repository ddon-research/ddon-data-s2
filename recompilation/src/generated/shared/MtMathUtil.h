#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtMatrix;
class MtVector3;

namespace MtMathUtil {

    void setRotateVectorXY(MtMatrix& mtx, const MtVector3& DirX, const MtVector3& UpY, const MtVector3& Pos);
    void setRotateVectorXZ(MtMatrix& mtx, const MtVector3& DirX, const MtVector3& UpZ, const MtVector3& Pos);
    void setRotateVectorYX(MtMatrix& mtx, const MtVector3& DirY, const MtVector3& UpX, const MtVector3& Pos);
    void setRotateVectorYZ(MtMatrix& mtx, const MtVector3& DirY, const MtVector3& UpZ, const MtVector3& Pos);
    void setRotateVectorZX(MtMatrix& mtx, const MtVector3& DirZ, const MtVector3& UpX, const MtVector3& Pos);
    void setRotateVectorZY(MtMatrix& mtx, const MtVector3& DirZ, const MtVector3& UpY, const MtVector3& Pos);

}  // namespace MtMathUtil
