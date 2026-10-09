#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtMath.h"

// Forward declarations
class MtMatrix;
class MtVector3;
class MtVector4;

// Declarations
namespace MtCollisionUtil { class MtSoaVector1; }
namespace MtCollisionUtil { class MtSoaVector3; }
namespace MtCollisionUtil { class MtVectorU4; }
namespace MtCollisionUtil { class MtVectorU43; }

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;
using u8 = unsigned char;

namespace MtCollisionUtil {
    class MtSoaVector1
    {
    public:
        MtSoaVector1();
        MtSoaVector1(const MtCollisionUtil::MtSoaVector1& src);
        MtSoaVector1(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&);
        MtSoaVector1(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&);
        MtSoaVector1(const MtVector3&);
        MtSoaVector1(const MtVector4& src);
        MtSoaVector1(const f32 src);
        MtSoaVector1(f32, f32, f32);
        MtSoaVector1(f32 x, f32 y, f32 z, f32 w);
        void initialize(const MtCollisionUtil::MtSoaVector1& src);
        void initialize(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&);
        void initialize(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&);
        void initialize(const MtVector3&);
        void initialize(const MtVector4& src);
        void initialize(const f32 src);
        void initialize(f32, f32, f32);
        void initialize(f32 x, f32 y, f32 z, f32 w);
        MtCollisionUtil::MtSoaVector1 operator=(const MtCollisionUtil::MtSoaVector1& _v);
        operator float *();
        operator const float *() const;
        MtCollisionUtil::MtSoaVector1 operator+(const MtCollisionUtil::MtSoaVector1& _v) const;
        MtCollisionUtil::MtSoaVector1 operator-(const MtCollisionUtil::MtSoaVector1& _v) const;
        MtCollisionUtil::MtSoaVector1 operator*(const MtCollisionUtil::MtSoaVector1& _v) const;
        MtCollisionUtil::MtSoaVector1 operator/(const MtCollisionUtil::MtSoaVector1& _v) const;
        void operator+=(const MtCollisionUtil::MtSoaVector1&);
        void operator-=(const MtCollisionUtil::MtSoaVector1&);
        void operator*=(const MtCollisionUtil::MtSoaVector1&);
        void operator/=(const MtCollisionUtil::MtSoaVector1&);
        MtCollisionUtil::MtVectorU4 operator==(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtVectorU4 operator!=(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtVectorU4 operator>(const MtCollisionUtil::MtSoaVector1& src) const;
        MtCollisionUtil::MtVectorU4 operator>=(const MtCollisionUtil::MtSoaVector1& src) const;
        MtCollisionUtil::MtVectorU4 operator<(const MtCollisionUtil::MtSoaVector1& src) const;
        MtCollisionUtil::MtVectorU4 operator<=(const MtCollisionUtil::MtSoaVector1& src) const;
        bool isAllEQ(const MtCollisionUtil::MtSoaVector1&) const;
        bool isAllNE(const MtCollisionUtil::MtSoaVector1&) const;
        bool isAllGT(const MtCollisionUtil::MtSoaVector1&) const;
        bool isAllGE(const MtCollisionUtil::MtSoaVector1&) const;
        bool isAllLT(const MtCollisionUtil::MtSoaVector1&) const;
        bool isAllLE(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtVectorU4 convertU32() const;
        MtCollisionUtil::MtSoaVector1 abs() const;
        MtCollisionUtil::MtSoaVector1 splat(u32 id) const;
        MtCollisionUtil::MtSoaVector1 permute(const MtCollisionUtil::MtSoaVector1&, u32, u32, u32, u32, u32) const;
        MtCollisionUtil::MtSoaVector1 permute(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtSoaVector1 select(const MtCollisionUtil::MtSoaVector1& _v, const MtCollisionUtil::MtVectorU4& pattern) const;
        MtCollisionUtil::MtSoaVector1 getMinElementNative() const;
        MtCollisionUtil::MtSoaVector1 getMaxElementNative() const;
        f32 getMinElement() const;
        f32 getMaxElement() const;
        u32 getMinElementID() const;
        u32 getMaxElementID() const;
        MtCollisionUtil::MtSoaVector1 loadV3Elem0(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&);
        MtCollisionUtil::MtSoaVector1 loadV4Elem0(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&);
        MtCollisionUtil::MtSoaVector1 copyVElem(const MtCollisionUtil::MtSoaVector1&, u32, u32);
        MtCollisionUtil::MtSoaVector1 copyV3Elem(const MtVector3& _v, u32 src_idx, u32 dest_idx);
        MtCollisionUtil::MtSoaVector1 copyV4Elem(const MtVector4&, u32, u32);
        MtCollisionUtil::MtSoaVector1 getSqrtf4() const;
        MtCollisionUtil::MtSoaVector1 getRSqrtf4() const;
        MtCollisionUtil::MtSoaVector1 safeDiv(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector1 mulAdd(const MtCollisionUtil::MtSoaVector1& _mul, const MtCollisionUtil::MtSoaVector1& _add) const;
        MtCollisionUtil::MtSoaVector1 negativeMulSub(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector1 minimize(const MtCollisionUtil::MtSoaVector1& s) const;
        MtCollisionUtil::MtSoaVector1 maximize(const MtCollisionUtil::MtSoaVector1& s) const;
        static MtCollisionUtil::MtSoaVector1 select(const MtCollisionUtil::MtSoaVector1& _v0, const MtCollisionUtil::MtSoaVector1& _v1, const MtCollisionUtil::MtVectorU4& pattern);
    public:
        MtVector4 v;  // offset: 0x0
        static const MtCollisionUtil::MtSoaVector1 ZERO;
        static const MtCollisionUtil::MtSoaVector1 ONE;
        static const MtCollisionUtil::MtSoaVector1 ONE_MINUS;
        static const MtCollisionUtil::MtSoaVector1 HALF;
        static const MtCollisionUtil::MtSoaVector1 EPSILON_LOOSELY;
        static const MtCollisionUtil::MtSoaVector1 EPSILON_LOOSELY_MINUS;
        static const MtCollisionUtil::MtSoaVector1 EPSILON;
        static const MtCollisionUtil::MtSoaVector1 EPSILON_COLLISION;
        static const MtCollisionUtil::MtSoaVector1 EPSILON_INVERSE;
        static const MtCollisionUtil::MtSoaVector1 WORD_MAX;
        static const MtCollisionUtil::MtSoaVector1 WORD_MAX_INVERSE;
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    class MtSoaVector3
    {
    public:
        MtSoaVector3();
        MtSoaVector3(const MtCollisionUtil::MtSoaVector1& _x, const MtCollisionUtil::MtSoaVector1& _y, const MtCollisionUtil::MtSoaVector1& _z);
        MtSoaVector3(const MtCollisionUtil::MtSoaVector3& src);
        MtSoaVector3(const MtVector3&, const MtVector3&, const MtVector3&, const MtVector3&);
        MtSoaVector3(f32);
        MtSoaVector3(const MtCollisionUtil::MtSoaVector1& _v);
        MtSoaVector3(const MtVector3& _v);
        MtSoaVector3(const MtVector4&);
        MtSoaVector3(const MtVector4&, const MtVector4&, const MtVector4&);
        void initialize(const MtCollisionUtil::MtSoaVector1& _x, const MtCollisionUtil::MtSoaVector1& _y, const MtCollisionUtil::MtSoaVector1& _z);
        void initialize(const MtCollisionUtil::MtSoaVector3& _v);
        void initialize(const MtVector3&, const MtVector3&, const MtVector3&, const MtVector3&);
        void initialize(f32);
        void initialize(const MtCollisionUtil::MtSoaVector1& _v);
        void initialize(const MtVector3& _v);
        void initialize(const MtVector4&);
        void initialize(const MtVector4&, const MtVector4&, const MtVector4&);
        operator MtVector4 *();
        operator MtCollisionUtil::MtSoaVector1 *();
        operator const MtCollisionUtil::MtSoaVector1 *() const;
        MtCollisionUtil::MtSoaVector3 abs() const;
        MtCollisionUtil::MtSoaVector3 operator=(const MtVector3&);
        MtCollisionUtil::MtSoaVector3 operator+(f32) const;
        MtCollisionUtil::MtSoaVector3 operator-(f32) const;
        MtCollisionUtil::MtSoaVector3 operator*(f32) const;
        MtCollisionUtil::MtSoaVector3 operator/(f32) const;
        MtCollisionUtil::MtSoaVector3 operator+(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 operator-(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 operator*(const MtCollisionUtil::MtSoaVector1& v) const;
        MtCollisionUtil::MtSoaVector3 operator/(const MtCollisionUtil::MtSoaVector1& v) const;
        MtCollisionUtil::MtSoaVector3 operator+(const MtCollisionUtil::MtSoaVector3& v) const;
        MtCollisionUtil::MtSoaVector3 operator-(const MtCollisionUtil::MtSoaVector3& v) const;
        MtCollisionUtil::MtSoaVector3 operator*(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtSoaVector3 operator/(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtVectorU43 operator==(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtVectorU43 operator!=(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtVectorU43 operator>=(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtVectorU43 operator<(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtVectorU43 operator<=(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtVectorU43 operator==(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtVectorU43 operator!=(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtVectorU43 operator>(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtVectorU43 operator>=(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtVectorU43 operator<(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtVectorU43 operator<=(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtSoaVector1 innerProduct(const MtCollisionUtil::MtSoaVector3& s) const;
        MtCollisionUtil::MtSoaVector3 outerProduct(const MtCollisionUtil::MtSoaVector3& s) const;
        MtCollisionUtil::MtSoaVector3 transform(const MtMatrix& m) const;
        MtCollisionUtil::MtSoaVector1 lengthSq() const;
        MtCollisionUtil::MtSoaVector1 length() const;
        MtCollisionUtil::MtSoaVector3 normalize() const;
        MtCollisionUtil::MtSoaVector3 abs(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 safeDiv(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 safeDiv(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtSoaVector3 mulAdd(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 mulAdd(const MtCollisionUtil::MtSoaVector1& _mul, const MtCollisionUtil::MtSoaVector3& _add) const;
        MtCollisionUtil::MtSoaVector3 mulAdd(const MtCollisionUtil::MtSoaVector3&, const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 mulAdd(const MtCollisionUtil::MtSoaVector3&, const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtSoaVector3 negativeMulSub(const MtCollisionUtil::MtSoaVector1&, const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 negativeMulSub(const MtCollisionUtil::MtSoaVector3&, const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 negativeMulSub(const MtCollisionUtil::MtSoaVector3&, const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtSoaVector3 minimize(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 maximize(const MtCollisionUtil::MtSoaVector1&) const;
        MtCollisionUtil::MtSoaVector3 minimize(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtSoaVector3 maximize(const MtCollisionUtil::MtSoaVector3&) const;
        MtCollisionUtil::MtSoaVector3 splat(u32) const;
        MtCollisionUtil::MtVectorU43 convertU32() const;
        static MtCollisionUtil::MtSoaVector3 select(const MtCollisionUtil::MtSoaVector3& v0, const MtCollisionUtil::MtSoaVector3& v1, const MtCollisionUtil::MtVectorU4& pattern);
        void initColumn(const MtVector3& _v, u32 idx);
        void initColumn(const MtCollisionUtil::MtSoaVector1&, u32);
        void initColumn(const MtCollisionUtil::MtSoaVector3&, u32);
        void initColumn(const MtCollisionUtil::MtSoaVector3&, u32, u32);
        MtVector3 getColumn(u32 idx) const;
        void operator+=(const MtVector4&);
        void operator-=(const MtVector4&);
        void operator*=(const MtVector4&);
        MtCollisionUtil::MtSoaVector3 operator+(const MtVector4&);
        MtCollisionUtil::MtSoaVector3 operator-(const MtVector4&);
        MtCollisionUtil::MtSoaVector3 operator*(const MtVector4&);
        static MtCollisionUtil::MtSoaVector3 makeSoaVecFromVec3(const MtVector3& v0, const MtVector3& v1, const MtVector3& v2, const MtVector3& v3);
    public:
        MtCollisionUtil::MtSoaVector1 x;  // offset: 0x0
        MtCollisionUtil::MtSoaVector1 y;  // offset: 0x10
        MtCollisionUtil::MtSoaVector1 z;  // offset: 0x20
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    class MtVectorU4
    {
    public:
        operator unsigned int *();
        operator const unsigned int *() const;
        MtVectorU4();
        MtVectorU4(u32 a);
        MtVectorU4(u8*);
        MtVectorU4(const MtCollisionUtil::MtVectorU4& v);
        MtVectorU4(u32, u32, u32);
        MtVectorU4(u32 a, u32 b, u32 c, u32 d);
        MtVectorU4(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&);
        MtVectorU4(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&);
        void initialize(const MtCollisionUtil::MtVectorU4& v);
        void initialize(u8*);
        void initialize(u32 a);
        void initialize(u32, u32, u32);
        void initialize(u32 a, u32 b, u32 c, u32 d);
        void initialize(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&);
        void initialize(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&);
        u32 getElem(u32 index) const;
        void setElem(u32, u32);
        MtCollisionUtil::MtVectorU4 operator&(const MtCollisionUtil::MtVectorU4& src) const;
        MtCollisionUtil::MtVectorU4 operator|(const MtCollisionUtil::MtVectorU4& src) const;
        MtCollisionUtil::MtVectorU4 operator!() const;
        bool operator==(const MtCollisionUtil::MtVectorU4&) const;
        bool operator!=(const MtCollisionUtil::MtVectorU4&) const;
        bool operator>(const MtCollisionUtil::MtVectorU4&) const;
        bool operator>=(const MtCollisionUtil::MtVectorU4&) const;
        bool operator<(const MtCollisionUtil::MtVectorU4&) const;
        bool operator<=(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4& operator=(const MtCollisionUtil::MtVectorU4& src);
        MtCollisionUtil::MtVectorU4& operator=(const MtVector3&);
        MtCollisionUtil::MtVectorU4& operator=(const MtVector4&);
        MtCollisionUtil::MtVectorU4 operator+(const MtCollisionUtil::MtVectorU4& v) const;
        MtCollisionUtil::MtVectorU4 operator-(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 operator<<(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 operator>>(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 shiftLeft(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 shiftRight(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 splat(u32) const;
        MtCollisionUtil::MtVectorU4 permute(const MtCollisionUtil::MtVectorU4&, u32, u32, u32, u32, u32) const;
        MtCollisionUtil::MtVectorU4 permute(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 select(const MtCollisionUtil::MtVectorU4& _v, const MtCollisionUtil::MtVectorU4& pattern) const;
        MtCollisionUtil::MtVectorU4 minimize(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 maximize(const MtCollisionUtil::MtVectorU4&) const;
        MtVector4 convertMtVector4() const;
        MtCollisionUtil::MtSoaVector1 convertF32() const;
        MtCollisionUtil::MtVectorU4 loadV3Elem0(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&);
        MtCollisionUtil::MtVectorU4 loadV4Elem0(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&);
        u32 isAllTrue() const;
        u32 isAllFalse() const;
        u32 isAnyTrue() const;
        u32 isAnyFalse() const;
        MtCollisionUtil::MtVectorU4 cmpEQ(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 cmpNE(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 cmpGT(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 cmpGE(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 cmpLT(const MtCollisionUtil::MtVectorU4&) const;
        MtCollisionUtil::MtVectorU4 cmpLE(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAllEQ(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAllNE(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAllGT(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAllGE(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAllLT(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAllLE(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAnyEQ(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAnyNE(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAnyGT(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAnyGE(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAnyLT(const MtCollisionUtil::MtVectorU4&) const;
        bool cmpAnyLE(const MtCollisionUtil::MtVectorU4&) const;
    public:
        u32 u4[4];  // offset: 0x0
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0100;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0145;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_4123;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_5123;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_6123;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_7123;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0423;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0523;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0623;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0723;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0143;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0153;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0163;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0173;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0124;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0125;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0126;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0127;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0400;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_1500;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_2600;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0140;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0150;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0160;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0170;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_0527;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_3700;
        static const MtCollisionUtil::MtVectorU4* PERMUTE_PATTERN_COPYPTR_ARRAY[4][4];
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_WORD2DWORD_LOW;
        static const MtCollisionUtil::MtVectorU4 PERMUTE_PATTERN_WORD2DWORD_HIGH;
        static const MtCollisionUtil::MtVectorU4 SELECT_PATTERN_LLLR;
        static const MtCollisionUtil::MtVectorU4 CMP_OFFSET;
        static const MtCollisionUtil::MtVectorU4 ZERO;
        static const MtCollisionUtil::MtVectorU4 U32_MAX;
        static const u32 VMX128_CMP_ALL = 7;
        static const u32 VMX128_CMP_ANY = 5;
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    class MtVectorU43
    {
    public:
        MtVectorU43();
        MtVectorU43(const MtCollisionUtil::MtVectorU4&);
        MtVectorU43(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&);
        void initialize(const MtCollisionUtil::MtVectorU4&);
        void initialize(const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&, const MtCollisionUtil::MtVectorU4&);
        operator MtCollisionUtil::MtVectorU4 *();
        MtCollisionUtil::MtVectorU43 operator&(const MtCollisionUtil::MtVectorU43&) const;
        MtCollisionUtil::MtVectorU43 operator|(const MtCollisionUtil::MtVectorU43&) const;
        MtCollisionUtil::MtVectorU43 minimize(const MtCollisionUtil::MtVectorU43&) const;
        MtCollisionUtil::MtVectorU43 maximize(const MtCollisionUtil::MtVectorU43&) const;
        u32 getRowAnd(u32) const;
        u32 getRowOr(u32) const;
        MtCollisionUtil::MtVectorU4 getRowAndNative(u32) const;
        MtCollisionUtil::MtVectorU4 getRowOrNative(u32) const;
        MtCollisionUtil::MtVectorU4 getRowAndAll() const;
        MtCollisionUtil::MtVectorU4 getRowOrAll() const;
    public:
        MtCollisionUtil::MtVectorU4 x;  // offset: 0x0
        MtCollisionUtil::MtVectorU4 y;  // offset: 0x10
        MtCollisionUtil::MtVectorU4 z;  // offset: 0x20
    };
}  // namespace MtCollisionUtil
