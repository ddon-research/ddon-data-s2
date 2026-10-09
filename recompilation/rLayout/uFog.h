#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtRect;
class MtSize;
class MtUI;
class MtVector3;
class cDraw;
namespace nDraw { class Texture; }
class rImplicitSurface;
class rModel;
class rTexture;

// Declarations
class uFog;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u64 = __uint64_t;

class uFog : public cUnit
{
public:
    enum RENDER_TYPE
    {
        RENDER_INTEGRATE = 0,
        RENDER_HYBRID = 1,
        RENDER_POSTPROCESS = 2,
        __RENDER_TYPE__U32 = -1,
    };
    enum HEIGHT_TYPE
    {
        HEIGHT_NONE = 0,
        HEIGHT_WORLD_Y = 1,
        HEIGHT_DISTANCE = 2,
        HEIGHT_VOLUME = 3,
        __HEIGHT_TYPE__U32 = -1,
    };
    enum GROUP_TYPE
    {
        GROUP_0 = 1,
    };
public:
    class MyDTI;
    struct FOG_PARAM;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct alignas(8) FOG_PARAM
    {
    public:
        MtFloat3 FogColor;  // offset: 0x0
        f32 FogDensity;  // offset: 0xc
        f32 FogHStart;  // offset: 0x10
        f32 FogHInvRange;  // offset: 0x14
        f32 FogStart;  // offset: 0x18
        f32 FogInvRange;  // offset: 0x1c
        MtFloat3 FogHColor;  // offset: 0x20
        f32 FogHDensity;  // offset: 0x2c
        f32 FogUVScale;  // offset: 0x30
        f32 FogHSlopeBias;  // offset: 0x34
        MtFloat2 FogUVOffset;  // offset: 0x38
        f32 FogDiffuseBlend;  // offset: 0x40
        f32 FogLinearRate;  // offset: 0x44
        f32 FogWorldYRate;  // offset: 0x48
        f32 FogDistanceRate;  // offset: 0x4c
        f32 FogDistanceEstRate;  // offset: 0x50
        f32 FogDistanceNmlRate;  // offset: 0x54
        f32 FogDistanceTblRate;  // offset: 0x58
        f32 FogDistanceColTblRate;  // offset: 0x5c
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    uFog();
    virtual ~uFog();
    RENDER_TYPE getRenderType() const;
    void setRenderType(RENDER_TYPE);
    u32 getGroup();
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void sync();  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual u64 getSystemUnitGroup() const;  // vtable slot 8
    // Address: 0x01b5f2d0 - 0x01b5f2d1 (1 bytes)
    virtual void setState(cDraw* pdraw) {}  // vtable slot 24
    virtual bool isValidDrawBySystem() const;  // vtable slot 25
    void setHeightType(HEIGHT_TYPE);
    HEIGHT_TYPE getHeightType() const;
    void setHeightMap(rTexture* ptex);
    rTexture* getHeightMap();
    void setUVScale(f32);
    f32 getUVScale() const;
    void setUVOffset(const MtFloat2&);
    MtFloat2 getUVOffset() const;
    f32 getHeightStart();
    void setHeightStart(f32 v);
    f32 getHeightEnd();
    void setHeightEnd(f32 v);
    f32 getHeightDensity();
    void setHeightDensity(f32 v);
    MtVector3 getHeightColor();
    void setHeightColor(const MtVector3& v);
    f32 getHeightSlopeBias();
    void setHeightSlopeBias(f32);
    virtual void getDrawUnitState(u32& type, u32& priority) const;  // vtable slot 18
    void setLegacyMode(bool);
    bool getLegacyMode() const;
    bool hideHeightFog();
    bool hideVolumeFog();
    void copyRegion(cDraw* pdraw, const MtRect& dst_rect, const MtRect& src_rect, const MtSize& src_size);
    void drawDepth(cDraw* pdraw);
    void drawModel(cDraw* pdraw);
    void drawImplicitSurface(cDraw* pdraw);
public:
    RENDER_TYPE mRenderType;  // offset: 0x48
    SO_HANDLE mFogFunction;  // offset: 0x4c
    SO_HANDLE mFogVTFFunction;  // offset: 0x50
    SO_HANDLE mHeightFunction;  // offset: 0x54
    SO_HANDLE mHeightVTFFunction;  // offset: 0x58
    FOG_PARAM mFogParam;  // offset: 0x60
    HEIGHT_TYPE mHeightType;  // offset: 0xc0
    u32 mGroup;  // offset: 0xc4
    f32 mHeightStart;  // offset: 0xc8
    f32 mHeightEnd;  // offset: 0xcc
    f32 mHeightDensity;  // offset: 0xd0
    MtVector3 mHeightColor;  // offset: 0xe0
    MtFloat2 mUVOffset;  // offset: 0xf0
    f32 mUVScale;  // offset: 0xf8
    f32 mHeightSlopeBias;  // offset: 0xfc
    rTexture* mpHeightMap;  // offset: 0x100
    MtVector3 mPos;  // offset: 0x110
    MtQuaternion mQuat;  // offset: 0x120
    MtVector3 mScale;  // offset: 0x130
    MtMatrix mWmat;  // offset: 0x140
    rModel* mpModel;  // offset: 0x180
    rImplicitSurface* mpImplicitSurface;  // offset: 0x188
    nDraw::Texture* mpFogFrontDepth;  // offset: 0x190
    nDraw::Texture* mpFogBackDepth;  // offset: 0x198
    nDraw::Texture* mpDummy;  // offset: 0x1a0
    nDraw::Texture* mpFogFrontDepthSmall;  // offset: 0x1a8
    nDraw::Texture* mpFogBackDepthSmall;  // offset: 0x1b0
    bool mUseHighPrecisionModel;  // offset: 0x1b8
    bool mLegacyMode;  // offset: 0x1b9
    static MyDTI DTI;
};
