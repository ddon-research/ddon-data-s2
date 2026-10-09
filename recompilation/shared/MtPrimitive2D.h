#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct MtFloat2;
struct MtFloat4;
class MtVector2;
class MtVector4;

// Declarations
class MtPoint;
class MtPointF;
class MtRange;
class MtRangeF;
class MtRangeU16;
class MtRect;
class MtRectF;
class MtSize;
class MtSizeF;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using u32 = unsigned int;
using u64 = __uint64_t;

class MtPoint
{
public:
    MtPoint();
    MtPoint(s32 sx, s32 sy);
    MtPoint(const MtPoint& p);
    MtPoint(const MtPointF& p);
    const MtPoint& operator=(const MtPoint& p);
    const MtPoint& operator=(const MtPointF&);
    bool operator==(const MtPoint& p) const;
    bool operator!=(const MtPoint&) const;
    void operator+=(const MtPoint&);
    void operator-=(const MtPoint& p);
    void operator*=(const f32);
    const MtPoint operator+(const MtPoint&) const;
    const MtPoint operator-(const MtPoint&) const;
    const MtPoint operator*(const f32) const;
    const MtPoint operator-() const;
public:
    union
    {
    public:
        struct
        {
        public:
            s32 x;  // offset: 0x0
            s32 y;  // offset: 0x4
        };  // offset: 0x0
        u64 xy;  // offset: 0x0
    };  // offset: 0x0
    static const MtPoint Zero;
};

class MtPointF
{
public:
    MtPointF();
    MtPointF(f32 sx, f32 sy);
    MtPointF(const MtPointF& p);
    MtPointF(const MtFloat2& v);
    MtPointF(const MtVector2& v);
    MtPointF(const MtPoint& p);
    const MtPointF& operator=(const MtPointF& p);
    const MtPointF& operator=(const MtVector2&);
    const MtPointF& operator=(const MtPoint&);
    operator float *();
    operator const float *() const;
    operator MtVector2() const;
    bool operator==(const MtPointF&) const;
    bool operator!=(const MtPointF&) const;
    void operator+=(const MtPointF&);
    void operator-=(const MtPointF& p);
    void operator*=(const f32);
    const MtPointF operator+(const MtPointF&) const;
    const MtPointF operator-(const MtPointF&) const;
    const MtPointF operator*(const f32) const;
    const MtPointF operator-() const;
public:
    f32 x;  // offset: 0x0
    f32 y;  // offset: 0x4
    static const MtPointF Zero;
};

class MtRange
{
public:
    MtRange();
    MtRange(s32 value);
    MtRange(s32 value0, s32 value1);
    MtRange(const MtRange& range);
    MtRange(const MtRangeF&);
    MtRange(const MtRangeU16&);
    bool operator==(const MtRange&) const;
    bool operator!=(const MtRange&) const;
    MtRange operator+(s32) const;
    MtRange operator-(s32) const;
    MtRange operator*(s32) const;
    void setMinMax(s32 value0, s32 value1);
    void setBaseAmp(s32, s32);
    s32 getMin() const;
    s32 getMax() const;
    s32 getBase() const;
    s32 getAmp() const;
    s32 calcRange(u32 random) const;
    s32 calcRange(f32) const;
    bool isInside(s32) const;
public:
    s32 s;  // offset: 0x0
    u32 r;  // offset: 0x4
    static const MtRange Zero;
};

class MtRangeF
{
public:
    MtRangeF();
    MtRangeF(f32 value);
    MtRangeF(f32 value0, f32 value1);
    MtRangeF(const MtRange&);
    MtRangeF(const MtRangeF& range);
    MtRangeF(const MtRangeU16&);
    bool operator==(const MtRangeF&) const;
    bool operator!=(const MtRangeF&) const;
    MtRangeF operator+(f32) const;
    MtRangeF operator-(f32) const;
    MtRangeF operator*(f32 value) const;
    void setMinMax(f32 value0, f32 value1);
    void setBaseAmp(f32 base, f32 amp);
    f32 getMin() const;
    f32 getMax() const;
    f32 getBase() const;
    f32 getAmp() const;
    f32 calcRange(f32 rate) const;
    bool isInside(f32) const;
public:
    f32 s;  // offset: 0x0
    f32 r;  // offset: 0x4
    static const MtRangeF Zero;
};

class MtRangeU16
{
public:
    MtRangeU16();
    MtRangeU16(u32 value);
    MtRangeU16(u32 value0, u32 value1);
    MtRangeU16(const MtRange&);
    MtRangeU16(const MtRangeF&);
    MtRangeU16(const MtRangeU16& range);
    bool operator==(const MtRangeU16&) const;
    bool operator!=(const MtRangeU16&) const;
    MtRangeU16 operator+(u32) const;
    MtRangeU16 operator*(u32) const;
    void setMinMax(u32 value0, u32 value1);
    void setBaseAmp(u32, u32);
    u32 getMin() const;
    u32 getMax() const;
    u32 getBase() const;
    u32 getAmp() const;
    u32 calcRange(u32 random) const;
    u32 calcRange(f32 rate) const;
    bool isInside(u32) const;
public:
    u32 s : 16;  // offset: 0x0
    u32 r : 16;  // offset: 0x0
    static const MtRangeU16 Zero;
};

class MtRect
{
public:
    MtRect();
    MtRect(s32 w, s32 h);
    MtRect(s32 sl, s32 st, s32 sr, s32 sb);
    MtRect(const MtRect& rt);
    MtRect(const MtSize& sz);
    MtRect(const MtPoint& pt, const MtSize& sz);
    MtRect(const MtRectF&);
    MtRect(const MtSizeF&);
    MtRect(const MtPointF&, const MtSizeF&);
    const MtRect& operator=(const MtRect& p);
    const MtRect& operator=(const MtSize& p);
    const MtRect& operator=(const MtRectF&);
    const MtRect& operator=(const MtSizeF&);
    bool operator==(const MtRect& s) const;
    bool operator!=(const MtRect& s) const;
    void operator+=(const MtPoint& s);
    void operator-=(const MtPoint&);
    void operator*=(const f32);
    MtRect operator+(const MtPoint& s) const;
    MtRect operator-(const MtPoint&) const;
    MtRect operator*(const f32 scale) const;
    void operator&=(const MtRect& s);
    MtRect operator&(const MtRect&) const;
    void operator|=(const MtRect&);
    MtRect operator|(const MtRect&) const;
    s32 w() const;
    s32 h() const;
    MtPoint lt() const;
    MtPoint rb() const;
    MtPoint rt() const;
    MtPoint lb() const;
    MtPoint center() const;
    MtSize size() const;
    bool isEmpty() const;
    bool isNull() const;
    void setEmpty();
    void resize(s32, s32);
    void resize(const MtPoint&);
    void resize(const MtSize&);
    void move(s32, s32);
    void move(const MtPoint& p);
    void offset(s32, s32);
    void offset(const MtPoint& p);
    bool intersect(const MtRect& rt) const;
    bool intersect(const MtPoint& p) const;
    void normalize();
    void align(u32);
    void inflate(s32 x, s32 y);
    void deflate(s32, s32);
    u32 tessellate(const MtRect& src, MtRect* dest_rects);
private:
    s32 getMin(s32 a, s32 b) const;
    s32 getMax(s32 a, s32 b) const;
    void swap(s32&, s32&);
public:
    s32 l;  // offset: 0x0
    s32 t;  // offset: 0x4
    s32 r;  // offset: 0x8
    s32 b;  // offset: 0xc
    static const MtRect Zero;
};

class MtRectF
{
public:
    MtRectF();
    MtRectF(f32 w, f32 h);
    MtRectF(f32 sl, f32 st, f32 sr, f32 sb);
    MtRectF(const MtRectF& rt);
    MtRectF(const MtSizeF& sz);
    MtRectF(const MtPointF& pt, const MtSizeF& sz);
    MtRectF(const MtFloat4& v);
    MtRectF(const MtVector4&);
    MtRectF(const MtRect& rt);
    MtRectF(const MtSize&);
    MtRectF(const MtPoint&, const MtSize&);
    const MtRectF& operator=(const MtRectF& p);
    const MtRectF& operator=(const MtSizeF&);
    const MtRectF& operator=(const MtFloat4& v);
    const MtRectF& operator=(const MtVector4&);
    const MtRectF& operator=(const MtRect& p);
    const MtRectF& operator=(const MtSize&);
    operator float *();
    operator const float *() const;
    operator MtVector4() const;
    bool operator==(const MtRectF&) const;
    bool operator!=(const MtRectF&) const;
    void operator+=(const MtPointF& s);
    void operator-=(const MtPointF&);
    void operator*=(const f32 scale);
    MtRectF operator+(const MtPointF&) const;
    MtRectF operator-(const MtPointF&) const;
    MtRectF operator*(const f32) const;
    void operator&=(const MtRectF&);
    void operator|=(const MtRectF&);
    MtRectF operator&(const MtRectF&) const;
    MtRectF operator|(const MtRectF&) const;
    f32 w() const;
    f32 h() const;
    MtPointF lt() const;
    MtPointF rb() const;
    MtPointF rt() const;
    MtPointF lb() const;
    MtPointF center() const;
    MtSizeF size() const;
    bool isEmpty() const;
    bool isNull() const;
    void setEmpty();
    void resize(f32, f32);
    void resize(const MtPointF&);
    void resize(const MtSizeF&);
    void move(f32 x, f32 y);
    void move(const MtPointF& p);
    void offset(f32, f32);
    void offset(const MtPointF& p);
    bool intersect(const MtRectF& rt) const;
    bool intersect(const MtPointF& p) const;
    void normalize();
    void align(u32);
    void inflate(f32 x, f32 y);
    void deflate(f32 x, f32 y);
    u32 tessellate(const MtRectF& src, MtRectF* dest_rects);
private:
    f32 getMin(f32, f32) const;
    f32 getMax(f32, f32) const;
    void swap(f32& a, f32& b);
public:
    f32 l;  // offset: 0x0
    f32 t;  // offset: 0x4
    f32 r;  // offset: 0x8
    f32 b;  // offset: 0xc
    static const MtRectF Zero;
};

class MtSize
{
public:
    MtSize();
    MtSize(s32 sw, s32 sh);
    MtSize(const MtSize& p);
    MtSize(const MtSizeF& p);
    const MtSize& operator=(const MtSize& p);
    const MtSize& operator=(const MtSizeF& p);
    bool operator==(const MtSize&) const;
    bool operator!=(const MtSize& p) const;
    void operator+=(const MtSize&);
    void operator-=(const MtSize&);
    void operator*=(const f32 scale);
    const MtSize operator+(const MtSize& p) const;
    const MtSize operator-(const MtSize& p) const;
    const MtSize operator*(const f32 scale) const;
    const MtSize operator-() const;
    static u32 pack(u32, u32);
    static u32 pack(MtSize);
    static MtSize unpack(u32);
public:
    union
    {
    public:
        struct
        {
        public:
            s32 w;  // offset: 0x0
            s32 h;  // offset: 0x4
        };  // offset: 0x0
        u64 wh;  // offset: 0x0
    };  // offset: 0x0
    static const MtSize Zero;
};

class MtSizeF
{
public:
    MtSizeF();
    MtSizeF(f32 sw, f32 sh);
    MtSizeF(const MtSizeF& p);
    MtSizeF(const MtFloat2& v);
    MtSizeF(const MtVector2&);
    MtSizeF(const MtSize& p);
    const MtSizeF& operator=(const MtSizeF& p);
    const MtSizeF& operator=(const MtVector2&);
    const MtSizeF& operator=(const MtSize& p);
    operator float *();
    operator const float *() const;
    operator MtVector2() const;
    bool operator==(const MtSizeF&) const;
    bool operator!=(const MtSizeF&) const;
    void operator+=(const MtSizeF&);
    void operator-=(const MtSizeF& p);
    void operator*=(const f32 scale);
    const MtSizeF operator+(const MtSizeF&) const;
    const MtSizeF operator-(const MtSizeF&) const;
    const MtSizeF operator*(const f32 scale) const;
    const MtSizeF operator-() const;
public:
    f32 w;  // offset: 0x0
    f32 h;  // offset: 0x4
    static const MtSizeF Zero;
};
