#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtColor;
class MtColorF;
class MtColorHLS;

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class MtColor
{
public:
    MtColor();
    MtColor(u32 _r, u32 _g, u32 _b, u32 _a);
    MtColor(u32 _r, u32 _g, u32 _b);
    MtColor(u32 _rgba);
    MtColor(const MtColor& c);
    explicit MtColor(const MtColorF& c);
    static MtColor fromB5G5R5(u16);
    static MtColor fromB5G6R5(u16);
    static MtColor fromB5G5R5A1(u16);
    static MtColor fromB4G4R4A4(u16);
    static MtColor fromB4G4R4(u16);
    static MtColor fromB8G8R8A8(u32 c);
    static MtColor fromB8G8R8(u32);
    static u16 toB5G5R5(MtColor);
    static u16 toB5G6R5(MtColor);
    static u16 toB5G5R5A1(MtColor);
    static u16 toA1B5G5R5(MtColor);
    static u16 toB4G4R4A4(MtColor);
    static u16 toA4B4G4R4(MtColor);
    static u16 toB4G4R4(MtColor);
    static u32 toB8G8R8A8(MtColor);
    static u32 toB8G8R8(MtColor);
    operator unsigned int() const;
    operator MtColorF() const;
    operator unsigned char *() const;
    const MtColor& operator=(const MtColorF& c);
    void operator+=(const MtColor);
    MtColor operator+(const MtColor);
    void operator-=(const MtColor);
    MtColor operator-(const MtColor);
    void operator*=(const MtColor);
    MtColor operator*(const MtColor);
    void operator*=(f32);
    MtColor operator*(f32);
    MtColor operator~();
    bool operator==(const MtColor& c) const;
    bool operator!=(const MtColor& c) const;
    static const MtColor lerp(const MtColor a, const MtColor b, f32 t);
    static const MtColor lerp(const MtColor a, const MtColor b, s32 t);
    static const MtColor lerp(const MtColor a, const MtColor b, const f32* t);
public:
    union
    {
    public:
        struct
        {
        public:
            u32 r : 8;  // offset: 0x0
            u32 g : 8;  // offset: 0x0
            u32 b : 8;  // offset: 0x0
            u32 a : 8;  // offset: 0x0
        };  // offset: 0x0
        u32 rgba;  // offset: 0x0
    };  // offset: 0x0
    static MtColor Red;
    static MtColor Green;
    static MtColor Blue;
    static MtColor Yellow;
    static MtColor Cyan;
    static MtColor Pink;
    static MtColor Magenta;
    static MtColor White;
    static MtColor Black;
    static MtColor Gray;
    static MtColor LtGray;
    static MtColor DkGray;
    static MtColor LightGreen;
    static MtColor LightBlue;
    static MtColor LightRed;
    static MtColor DarkGreen;
    static MtColor DarkBlue;
    static MtColor DarkRed;
    static MtColor DarkOrange;
    static MtColor DarkCyan;
    static MtColor Orange;
    static MtColor DeepPink;
    static MtColor SkyBlue;
    static MtColor RoyalBlue;
    static MtColor MidnightBlue;
    static MtColor Indigo;
    static MtColor Navy;
    static MtColor Brown;
    static MtColor Crimson;
    static MtColor ForestGreen;
    static MtColor SeaGreen;
    static MtColor SysWindow;
    static MtColor Sys3DFace;
    static MtColor Sys3DHiLight;
    static MtColor Sys3DDkShadow;
    static MtColor Sys3DLight;
    static MtColor Sys3DShadow;
    static MtColor SysHighLight;
    static MtColor SysHighLightText;
    static MtColor SysWindowFrame;
    static MtColor SysWindowText;
    static MtColor SysWorkSpace;
    static MtColor SysBtnText;
    static MtColor SysGrayText;
    static MtColor SysActiveCaptionLT;
    static MtColor SysActiveCaptionRT;
    static MtColor SysActiveCaptionLB;
    static MtColor SysActiveCaptionRB;
    static MtColor SysInActiveCaptionLT;
    static MtColor SysInActiveCaptionRT;
    static MtColor SysInActiveCaptionLB;
    static MtColor SysInActiveCaptionRB;
    static MtColor SysToolTip;
    static MtColor SysToolTipText;
    static MtColor SysBody;
};

class alignas(16) MtColorF
{
public:
    MtColorF();
    MtColorF(f32 _r, f32 _g, f32 _b, f32 _a);
    MtColorF(f32 _r, f32 _g, f32 _b);
    explicit MtColorF(const MtColor& c);
    MtColorF(const MtColorF& c);
    operator float *() const;
    operator MtColor() const;
    void operator*=(const f32);
    MtColorF operator*(const f32 s);
    void operator+=(const MtColorF&);
    MtColorF operator+(const MtColorF&);
    bool operator==(const MtColorF&) const;
    bool operator!=(const MtColorF&) const;
public:
    f32 r;  // offset: 0x0
    f32 g;  // offset: 0x4
    f32 b;  // offset: 0x8
    f32 a;  // offset: 0xc
    static MtColorF Zero;
    static MtColorF One;
    static MtColorF Red;
    static MtColorF Green;
    static MtColorF Blue;
    static MtColorF Yellow;
    static MtColorF Cyan;
    static MtColorF Pink;
    static MtColorF Magenta;
    static MtColorF White;
    static MtColorF Black;
    static MtColorF Gray;
    static MtColorF LtGray;
    static MtColorF DkGray;
};

class MtColorHLS
{
public:
    MtColorHLS();
    MtColorHLS(f32 _h, f32 _l, f32 _s, f32 _a);
    MtColorHLS(f32 _h, f32 _l, f32 _s);
    MtColorHLS(const MtColorHLS&);
    MtColorHLS(const MtColorF& c);
    operator float *() const;
    operator MtColorF() const;
    static MtColorHLS fromRGB(const MtColorF& c);
    MtColorF toRGB() const;
public:
    f32 h;  // offset: 0x0
    f32 l;  // offset: 0x4
    f32 s;  // offset: 0x8
    f32 a;  // offset: 0xc
};
