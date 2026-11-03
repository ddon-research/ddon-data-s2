#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtMath.h"

// Forward declarations
struct MtFloat2;
class MtMatrix;
class MtVector3;
class MtVector4;

// Declarations
class MtSpline;

// Type aliases from DWARF
using f32 = float;

class MtSpline
{
public:
    MtSpline();
    MtSpline(const MtVector3* pv);
    MtSpline(const MtVector3& v0, const MtVector3& v1, const MtVector3& v2, const MtVector3& v3);
    MtSpline(const MtVector4* pv);
    MtSpline(const MtVector4& v0, const MtVector4& v1, const MtVector4& v2, const MtVector4& v3);
    MtSpline(const f32* pv);
    MtSpline(f32 v0, f32 v1, f32 v2, f32 v3);
    MtSpline(const MtVector4& v);
    MtSpline(const MtFloat2* pv);
    MtSpline(const MtFloat2& v0, const MtFloat2& v1, const MtFloat2& v2, const MtFloat2& v3);
    virtual ~MtSpline();
    void setVector3(const MtVector3* pv);
    void setVector3(const MtVector3& v0, const MtVector3& v1, const MtVector3& v2, const MtVector3& v3);
    MtVector3 calcVector3(f32 Ratio);
    void setVector4(const MtVector4* pv);
    void setVector4(const MtVector4& v0, const MtVector4& v1, const MtVector4& v2, const MtVector4& v3);
    MtVector4 calcVector4(f32 Ratio);
    void setF32(const f32* pv);
    void setF32(f32 v0, f32 v1, f32 v2, f32 v3);
    void setF32(const MtVector4& v);
    f32 calcF32(f32 Ratio);
    void setFloat2(const MtFloat2* pv);
    void setFloat2(const MtFloat2& v0, const MtFloat2& v1, const MtFloat2& v2, const MtFloat2& v3);
    MtFloat2 calcFloat2(f32 Ratio);
private:
    MtVector4 mParam[4];  // offset: 0x10
    static const MtMatrix SplineMatrix;
};
