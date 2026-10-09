#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nEffect { struct KEYFRAME_INDEX; }
namespace nEffect { class SimpleCurve; }

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nEffect {
    struct KEYFRAME_INDEX
    {
    public:
        u8* getKeyframeParam() const;
        u32 getKeyframeFrame(u32 DataSize, u32 DataNo) const;
    public:
        u32 KeyframeNum : 8;  // offset: 0x0
        u32 FixAngleFlag : 1;  // offset: 0x0
        u32 SingleParamFlag : 1;  // offset: 0x0
        u32 Reserved0601 : 6;  // offset: 0x0
        u32 Reserved0802 : 8;  // offset: 0x0
        u32 RefType : 3;  // offset: 0x0
        u32 InpType : 3;  // offset: 0x0
        u32 LoopFlag : 1;  // offset: 0x0
        u32 InitOnlyFlag : 1;  // offset: 0x0
    };
}  // namespace nEffect

namespace nEffect {
    class SimpleCurve
    {
    public:
        SimpleCurve();
        SimpleCurve(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2, f32 x3, f32 y3);
        bool operator==(const nEffect::SimpleCurve&) const;
        bool operator!=(const nEffect::SimpleCurve&) const;
        f32 getValue(f32 x) const;
        u32 getIndex(f32 x, f32 y);
        void sort();
        f32 getX(u32) const;
        void setX(f32, u32);
        f32 getY(u32) const;
        void setY(f32, u32);
        bool getLoopFlag() const;
        void setLoopFlag(bool);
    private:
        f32 mX[3];  // offset: 0x0
        u32 mLoopFlag;  // offset: 0xc
        f32 mY[4];  // offset: 0x10
    public:
        static const u32 MAX_COUNT = 4;
        static const nEffect::SimpleCurve Zero;
        static const nEffect::SimpleCurve One;
        static const nEffect::SimpleCurve Linear;
    };
}  // namespace nEffect
