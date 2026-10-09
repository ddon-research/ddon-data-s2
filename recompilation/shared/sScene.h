#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cSystem.h"
#include "nDraw.h"

// Forward declarations
struct MT_ENUM;
class MtAABB;
class MtAllocator;
class MtDTI;
class MtGeometry;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
class cDynamicBVHCollision;
class cSwing;
class cUnit;
namespace nDraw { class InputLayout; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
class rTexture;
class uGrassWind;
class uLight;
class uShadow;

// Declarations
class sScene;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sScene : public cSystem
{
    // inferred: cSwing::applyWind names sScene::mpInstance
    friend class cSwing;
    // inferred: uLight::~uLight names sScene::mpInstance
    friend class uLight;
public:
    enum GEOM
    {
        GEOM_SPHERE = 0,
        GEOM_2DPLANE = 1,
        GEOM_I2GLINE = 2,
        GEOM_CUBE = 3,
        GEOM_SPHERE_D2 = 4,
        GEOM_CONE_D2 = 5,
        GEOM_NUM = 6,
    };
    enum TEXDETAIL_TYPE
    {
        TEXDETAIL_HIGHEST = 0,
        TEXDETAIL_HIGH = 1,
        TEXDETAIL_MEDIUM = 2,
        TEXDETAIL_LOW = 3,
        TEXDETAIL_LOWEST = 4,
    };
    enum TEX
    {
        TEX_NULLWHITE = 0,
        TEX_NULLNORMAL = 1,
        TEX_NULLBLACK = 2,
        TEX_FONT = 3,
        TEX_NOISE = 4,
        TEX_NULLCUBE = 5,
        TEX_COMPARE = 6,
        TEX_SPHEREMAP = 7,
        TEX_DITHER = 8,
        TEX_CUBE_FACE_SELECT = 9,
        TEX_CUBE_FACE_OFFSET = 10,
        TEX_CUBE_INDIRECTION = 11,
        TEX_HIGH_DETAIL_FONT = 12,
        TEX_NUM = 13,
    };
    enum DEVICE_TEX
    {
        DEVTEX_HARDWARE = 0,
        DEVTEX_NUM = 1,
    };
    enum BVH_TYPE
    {
        BVH_RANGE_LIGHT = 0,
        BVH_RANGE_WIND = 1,
        MAX_BVH_TYPE = 2,
    };
    enum AMBIENT_TYPE
    {
        AMBIENT_SH = 1,
        AMBIENT_SHADOW_REGION = 2,
        AMBIENT_ENVCUBE = 4,
    };
public:
    class MyDTI;
    struct UNIT_MAP;
    class TextureInfo;
    class Node;
    struct ENVELOPE_HANDLE;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct UNIT_MAP
    {
    public:
        u32 offset;  // offset: 0x0
        u32 count;  // offset: 0x4
    };
public:
    class TextureInfo : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        TextureInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        bool mEnable;  // offset: 0x8
        MT_CTSTR mName;  // offset: 0x10
        u32 mIndex;  // offset: 0x18
        static MyDTI DTI;
    };
public:
    class Node
    {
    public:
        Node();
        bool isAttached() const;
    private:
        u32 getType() const;
    private:
        u32 attr;  // offset: 0x0
        void* handle;  // offset: 0x8
    };
public:
    struct ENVELOPE_HANDLE
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 line : 12;  // offset: 0x0
                u32 ofs : 12;  // offset: 0x0
                u32 block : 8;  // offset: 0x0
            };  // offset: 0x0
            u32 handle;  // offset: 0x0
        };  // offset: 0x0
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
    sScene(u32 max_pool);
    virtual ~sScene();
    virtual void reset();  // vtable slot 6
    static sScene* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    virtual void move();  // vtable slot 7
    virtual void resetEnvelopeFlag();  // vtable slot 10
    virtual void begin();  // vtable slot 11
    virtual void end();  // vtable slot 12
    virtual void setup(cDraw* pdraw);  // vtable slot 13
    void setLightState(cDraw* pdraw, u32 light_group, u32 max_dynamic_light, const MtSphere& boundary);
    u32 getDynamicLightNum(nDraw::DRAW_VIEW view, u32 light_group, u32 max_dynamic_light, const MtSphere& sphere);
    void setTestLightState(cDraw* pdraw, const MtVector3& ambient_, const MtVector3& light_color_, const MtVector3& light_dir);
    void setAmbientState(cDraw* pdraw, u32 light_group, u32 ambient_type, const MtSphere& boundary);
    void setFogState(cDraw* pdraw, u32 group);
    bool setShadowState(cDraw* pdraw, u32 shadow_group);
    void setWindState(cDraw* pdraw, u32 max_wind, const MtAABB& boundary, const u32 wind_type_mask, const u32 wind_group_mask, const f32 freq_factor, const f32 dir_power_scale, const f32 point_power_scale);
    u32 getWind(u32 max_wind, const MtAABB& boundary, cUnit* * ppwinds, const u32 wind_type_mask, const u32 wind_group_mask);
    void setToneMapState(cDraw* pdraw);
    void attach(cUnit* punit);
    void detach(cUnit* punit);
    virtual const MT_ENUM* getLightGroupType();  // vtable slot 14
    virtual const MT_CTSTR* getLightGroupTips();  // vtable slot 15
    virtual const MT_ENUM* getWindGroupType();  // vtable slot 16
    virtual const MT_CTSTR* getWindGroupTips();  // vtable slot 17
    void setMultiShadowState(cDraw* pdraw, u32 shadowGroupMask, u32 maxNumGroup0, u32 maxNumGroup1, const MtSphere& boundary) const;
    void resetMultiShadowState(cDraw* pdraw) const;
    nDraw::Texture* getSysTextureHandle(u32 tex);
    nDraw::Texture* getDeviceTextureHandle(u32);
    rTexture* getFontTexture();
    rTexture* getHDFontTexture();
    u32 createEnvelope(u32 num);
    void releaseEnvelope(u32 handle);
    void* lockEnvelope(u32 handle);
    void unlockEnvelope(u32 handle);
    void setEnvelope(cDraw* pdraw, u32 handle);
    nDraw::VertexBuffer* getSysGeometry(GEOM geom);
    s32 getDebugView();
    void setDebugView(u32);
    bool isWireFrame();
    void setWireFrame(bool);
    virtual u32 getTextureDetail(MT_CTSTR path);  // vtable slot 18
    virtual u32 getTextureMipLimite(MT_CTSTR path);  // vtable slot 19
    void setTextureDetail(u32);
    void setTextureMipLimite(u32);
    void setUberWindThreshold(s32 num);
    s32 getUberWindThreshold() const;
    void setApproximateLightingEnable(bool enable);
    bool getApproximateLightingEnable() const;
    void setBruteForceLightingEnable(bool);
    bool getBruteForceLightingEnable() const;
    MtVector4 getDummyColor() const;
    void setDummyColor(const MtVector4&);
    void setupLightGroup(cDraw* pdraw, u32 light_group);
    void detachNode(Node& node);
protected:
    static uintptr getUnitID(const cUnit* punit);
    static s32 compare(const void* p1, const void* p2);
    void initSysGeom();
    void initSysTexture();
    nDraw::VertexBuffer* createSphere(u32 div, nDraw::InputLayout* pvdecl);
    nDraw::VertexBuffer* createCube(u32 div, nDraw::InputLayout* pvdecl);
    nDraw::VertexBuffer* create2DPlane();
    nDraw::VertexBuffer* createI2GLine();
    nDraw::VertexBuffer* createCone(u32 div, nDraw::InputLayout* pvdecl);
public:
    bool isMultiShadowUnit();
    uShadow* getShadowUnit(uLight* light);
private:
    bool attachNode(uLight* light, Node& node);
    bool attachNode(uGrassWind* wind, Node& node);
    void updateNode(const MtAABB& bound, const Node& node);
    u32 callbackLightEnumeration(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
    u32 callbackSHLightEnumeration(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
    u32 callbackWindEnumeration(MtGeometry& TraverseConvex, MtObject* pLeaf, void* pUserPtr);
    u32 pickDynamicLightFromScene(uLight* * outputLightTbl, nDraw::DRAW_VIEW dview, u32 light_group, u32 max_dynamic_light, const MtSphere& boundary);
    u32 calcLightWeight(uLight* pLight) const;
public:
    void addCorrectBloomPassageFrame(f32 add);
    f32 getCorrectBloomRate();
    f32 getCorrectBloomPassageFrame();
    f32 getCorrectBloomUseFrame();
    f32 getCorrectBloomNearestDistance();
    f32 getCorrectBloomMaxThreshold();
    void setLightRestrictPS3(bool);
    void setLightRestrictPS4(bool set);
    void setLightRestrictPC(bool);
    bool isLightRestrictPS3();
    bool isLightRestrictPS4();
    bool isLightRestrictPC();
    bool getUberFogFlag();
    bool getUberFogFlag2();
    f32 getInstanceFadeSwitchStartParcent();
protected:
    cUnit* * mpUnitPool;  // offset: 0x18
    u32 mUnitNum;  // offset: 0x20
    u32 mUnitPoolMax;  // offset: 0x24
    UNIT_MAP mUnitMap[10];  // offset: 0x28
    bool mShowLightTree;  // offset: 0x78
    bool mShowWindTree;  // offset: 0x79
    u32 mTextureDetail;  // offset: 0x7c
    u32 mTextureMipLimite;  // offset: 0x80
    nDraw::Texture* mpEnvelopeTex[3];  // offset: 0x88
    s32 mEnvelopeFlag[64];  // offset: 0xa0
    s32 mDebugView;  // offset: 0x1a0
    bool mWireFrame;  // offset: 0x1a4
    u32 mEnvelope[64];  // offset: 0x1a8
    u8* mpEnvelopeBase;  // offset: 0x2a8
    u8* mpEnvelopeBasePrev;  // offset: 0x2b0
    u32 mEnvelopePitch;  // offset: 0x2b8
    nDraw::Texture* mpSysTexture[13];  // offset: 0x2c0
    nDraw::Texture* mpDeviceTexture[1];  // offset: 0x328
    rTexture* mpFontTexture;  // offset: 0x330
    rTexture* mpEnvCubeTexture;  // offset: 0x338
    rTexture* mpCompareTexture;  // offset: 0x340
    rTexture* mpHDFontTexture;  // offset: 0x348
    nDraw::VertexBuffer* mpSysGeometry[6];  // offset: 0x350
    s32 mUberWindThreshold;  // offset: 0x380
    bool mUseApproximateLighting;  // offset: 0x384
    bool mUseBruteForceLighting;  // offset: 0x385
public:
    MtVector4 mTestParam;  // offset: 0x390
    MtVector3 mTestPosition;  // offset: 0x3a0
    MtVector3 mTestDirection;  // offset: 0x3b0
    MtVector4 mTestColor;  // offset: 0x3c0
    MtVector4 mDummyColor;  // offset: 0x3d0
    f32 mTestType;  // offset: 0x3e0
    rTexture* mpTestTexture;  // offset: 0x3e8
    TextureInfo mTextureInfos[128];  // offset: 0x3f0
    u32 mTextureInfoNum;  // offset: 0x13f0
private:
    bool mUseBVH;  // offset: 0x13f4
    cDynamicBVHCollision* mpTree[2];  // offset: 0x13f8
    f32 mCorrectBloomPassageFrame;  // offset: 0x1408
    f32 mCorrectBloomUseFrame;  // offset: 0x140c
    f32 mCorrectBloomNearestDistance;  // offset: 0x1410
    f32 mCorrectBloomMaxThreshold;  // offset: 0x1414
    bool mLightRestrictPS3;  // offset: 0x1418
    bool mLightRestrictPS4;  // offset: 0x1419
    bool mLightRestrictPC;  // offset: 0x141a
    bool mIsUberFog;  // offset: 0x141b
    bool mIsUberFog2;  // offset: 0x141c
    f32 mInstanceFadeSwitchStartParcent;  // offset: 0x1420
public:
    static MyDTI DTI;
    static const u32 DEFAULT_WIND_PRIORITY = 127;
    static const u32 DEFAULT_LIGHT_PRIORITY = 127;
    static const u32 DEFAULT_AMBIENT_SHADOW_PRIORITY = 4096;
    static const u32 UNIT_TYPE_POS = 60;
    static const u32 UNIT_PRI_POS = 52;
    static const u64 UNIT_ADDR = 4503599627370495;
protected:
    static sScene* mpInstance;
    static const u32 MAX_VDECL = 256;
    static const s32 ENVELOPE_W = 768;
    static const s32 ENVELOPE_H = 64;
    static const s32 ENVELOPE_BLOCK = 8;
    static const u32 ENVELOPE_TEX_NUM = 3;
public:
    static const u32 MAX_TEXTURE_INFOS = 128;
};

// Inline, no code of its own: checked where it is inlined.
inline sScene* sScene::getInstance() {
    return ::sScene::mpInstance;
}
