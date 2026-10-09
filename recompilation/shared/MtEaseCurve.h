#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtMatrix;

// Declarations
class MtEaseCurve;
class MtHermiteCurve;

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

class MtEaseCurve
{
public:
    MtEaseCurve();
    MtEaseCurve(f32 _p1, f32 _p2);
    f32 easeIn(f32 t) const;
    f32 easeOut(f32) const;
    bool operator==(const MtEaseCurve&) const;
    bool operator!=(const MtEaseCurve&) const;
public:
    f32 p1;  // offset: 0x0
    f32 p2;  // offset: 0x4
    static const MtEaseCurve Smooth;
    static const MtEaseCurve Linear;
    static const MtEaseCurve Exponent;
private:
    static const MtMatrix BezierFactor;
};

class MtHermiteCurve
{
public:
    MtHermiteCurve();
    MtHermiteCurve(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2, f32 x3, f32 y3, f32 x4, f32 y4, f32 x5, f32 y5, f32 x6, f32 y6, f32 x7, f32 y7);
    bool operator==(const MtHermiteCurve&) const;
    bool operator!=(const MtHermiteCurve& e) const;
    f32 getValue(f32 xx) const;
    u32 getIndex(f32 xx, f32 yy);
    u32 getCount();
    void sort();
public:
    f32 x[8];  // offset: 0x0
    f32 y[8];  // offset: 0x20
    static const u32 MAX_COUNT = 8;
    static const MtHermiteCurve Zero;
    static const MtHermiteCurve One;
    static const MtHermiteCurve Linear;
};
