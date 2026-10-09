#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "nPrim.h"
#include "rEffectAnim.h"
#include "rEffectList.h"
#include "uBaseEffect.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
class cEffectAnim;
class cPrim;
namespace nPrim { struct Material; }
namespace nPrim { struct Vertex; }
class rEffectAnim;
class rEffectList;
class rVertices;

// Declarations
class uSimpleEffect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uSimpleEffect : public uBaseEffect
{
public:
    enum DRAW_TYPE
    {
        DRAW_TYPE_BILLBOARD = 0,
        DRAW_TYPE_BILLBOARD_CENTER = 1,
        DRAW_TYPE_POLYGON = 2,
        DRAW_TYPE_POLYGON_FIX = 3,
        DRAW_TYPE_SIZE_BILLBOARD = 4,
        DRAW_TYPE_SIZE_BILLBOARD_CENTER = 5,
        DRAW_TYPE_CULLING_OFFSET = 6,
        DRAW_TYPE_CULLING_BILLBOARD = 6,
        DRAW_TYPE_CULLING_BILLBOARD_CENTER = 7,
        DRAW_TYPE_CULLING_POLYGON = 8,
        DRAW_TYPE_CULLING_POLYGON_FIX = 9,
        DRAW_TYPE_CULLING_SIZE_BILLBOARD = 10,
        DRAW_TYPE_CULLING_SIZE_BILLBOARD_CENTER = 11,
        DRAW_TYPE_NUM = 12,
    };
public:
    class MyDTI;
    class Particle;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Particle
    {
    public:
        Particle();
        virtual ~Particle();
        static void* operator new(size_t s);
        static void* operator new[](size_t);
        static void operator delete(void* pObj);
        static void operator delete[](void*);
        bool isEnable() const;
        void setEnable(bool Flag);
        void setAlphaRate(f32 AlphaRate);
        bool isDraw() const;
        f32 getScale() const;
        void setScale(f32);
        MtVector3 getRot() const;
        f32 getRotX() const;
        f32 getRotY() const;
        f32 getRotZ() const;
        void setRot(const MtVector3&);
        void setRotX(f32);
        void setRotY(f32);
        void setRotZ(f32);
        f32 getAngle() const;
        void setAngle(f32);
        f32 getWidth() const;
        f32 getHeight() const;
        void setWidth(f32);
        void setHeight(f32);
    private:
        rEffectAnim::SEQ_PAT* getSeqPat(rEffectAnim* pAnim) const;
        MtColor calcCullingColor(rEffectList::EFL_PARAM_CULLING* pCullingParam, f32 CameraDist);
        MtFloat2 getSize() const;
        MtFloat2 getPatCenter() const;
    private:
        MtVector3 mPos;  // offset: 0x10
        uSimpleEffect::Particle* mpPrev;  // offset: 0x20
        uSimpleEffect::Particle* mpNext;  // offset: 0x28
        u32 mParticleNo;  // offset: 0x30
        u32 mIntensity : 16;  // offset: 0x34
        u32 mVolumeBlendRate : 8;  // offset: 0x34
        u32 mEnableFlag : 1;  // offset: 0x34
        u32 mUpdateAlphaFlag : 1;  // offset: 0x34
        u32 mParticle061f : 6;  // offset: 0x34
        cEffectAnim mAnim;  // offset: 0x38
        nPrim::Material mMaterial;  // offset: 0x48
        f32 mPatNoRate;  // offset: 0x50
        MtColor mColor;  // offset: 0x54
        f32 mBaseAlpha;  // offset: 0x58
        f32 mAlphaRate;  // offset: 0x5c
        union
        {
        public:
            f32 mParamF32[6];  // offset: 0x0
            u32 mParamU32[6];  // offset: 0x0
        };  // offset: 0x60
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
    uSimpleEffect();
    virtual ~uSimpleEffect();
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void setEffectList(rEffectList* pEffectList);  // vtable slot 33
    // Address: 0x01bbd0d0 - 0x01bbd0d1 (1 bytes)
    virtual void doFinish() {}  // vtable slot 34
    // Address: 0x01bbd0e0 - 0x01bbd0e1 (1 bytes)
    virtual void doRestart() {}  // vtable slot 35
    // Address: 0x01bbd0f0 - 0x01bbd0f1 (1 bytes)
    virtual void doClear() {}  // vtable slot 36
    // Address: 0x01bbd100 - 0x01bbd101 (1 bytes)
    virtual void doKeepHoldOff() {}  // vtable slot 37
    u32 getListNo() const;
    void setListNo(u32 No);
    rVertices* getVertices();
    void setVertices(rVertices* pVertices);
    void setResourceParam(rEffectList* pEffectList, u32 ListNo);
    void setResourceParam(rEffectList* pEffectList, u32 ListNo, rVertices* pVertices);
    void setResourceParam(rEffectList* pEffectList, u32 ListNo, u32 ParticleNum, MtVector3* pPosArray);
    s32 addParticle();
    s32 addParticle(const MtVector3& Pos);
    s32 addScalingParticle(const MtVector3& Scale);
    s32 addScalingParticle(const MtVector3& Pos, const MtVector3& Scale);
    void addParticles(u32 ParticleNum, MtVector3* pPosArray);
    bool deleteParticle(u32 No);
    void releaseParticles();
    const MtVector3& getParticlePos(u32 No) const;
    bool setParticlePos(const MtVector3& Pos, u32 No);
    bool isParticleEnable(u32 No) const;
    bool setParticleEnable(bool Flag, u32 No);
    bool setParticleAlphaRate(f32 AlphaRate, u32 No);
    void setParticleEnableAll(bool Flag);
    void setParticleAlphaRateAll(f32 AlphaRate);
    bool getOfsInvalidMode() const;
    void setOfsInvalidMode(bool Mode);
    u32 getParticleNum() const;
    u32 getParticleBuffSize() const;
protected:
    virtual void moveParticle(Particle* pParticle);  // vtable slot 41
    u32 getParticleType() const;
    f32 getParticleDeltaTime() const;
    Particle* searchParticle(u32 No) const;
private:
    bool initEFLParam();
    void initDrawParam();
    void initParticles();
    void initParticle(Particle* pParticle);
    void initParticleBillboard(Particle* pParticle);
    void initParticlePolygon(Particle* pParticle);
    void initParticleSizeBillboard(Particle* pParticle);
    void moveParticles();
    void drawParticleBillboard(cDraw* pDraw, cPrim* pPrim);
    void drawParticleBillboardCenter(cDraw* pDraw, cPrim* pPrim);
    void drawParticlePolygon(cDraw* pDraw, cPrim* pPrim);
    void drawParticlePolygonFix(cDraw* pDraw, cPrim* pPrim);
    void drawParticleSizeBillboard(cDraw* pDraw, cPrim* pPrim);
    void drawParticleSizeBillboardCenter(cDraw* pDraw, cPrim* pPrim);
    void drawParticleCullingBillboard(cDraw* pDraw, cPrim* pPrim);
    void drawParticleCullingBillboardCenter(cDraw* pDraw, cPrim* pPrim);
    void drawParticleCullingPolygon(cDraw* pDraw, cPrim* pPrim);
    void drawParticleCullingPolygonFix(cDraw* pDraw, cPrim* pPrim);
    void drawParticleCullingSizeBillboard(cDraw* pDraw, cPrim* pPrim);
    void drawParticleCullingSizeBillboardCenter(cDraw* pDraw, cPrim* pPrim);
    bool isParticleDraw(cDraw* pDraw, Particle* pParticle, const MtVector3& Pos) const;
    void calcPolygonVertex(nPrim::Vertex* pVertex, Particle* pParticle, rEffectAnim::SEQ_PAT* pSeqPat, const MtMatrix& Wmat);
    Particle* allocateParticle();
    void clearEFLParam();
    bool isSimpleEffectDraw() const;
    void updateParticleBuffSize();
    MtVector3 getGeneratorOfs() const;
    u32 getRand();
    f32 getRandF();
private:
    Particle* mpParticle;  // offset: 0x1d0
    u32 mParticleNum;  // offset: 0x1d8
    u32 mParticleCreateNum;  // offset: 0x1dc
    rVertices* mpVertices;  // offset: 0x1e0
    rEffectList::ResourceInfo* mpResourceInfo;  // offset: 0x1e8
    rEffectList::EFL_GENERATOR* mpGeneratorParam;  // offset: 0x1f0
    rEffectList::EFL_PARTICLE_PRIM_COMMON* mpParticleParam;  // offset: 0x1f8
    rEffectList::EFL_JOINT* mpJointParam;  // offset: 0x200
    u32 mListNo : 16;  // offset: 0x208
    u32 mStartRandCtr : 16;  // offset: 0x208
    u32 mParticleType : 8;  // offset: 0x20c
    u32 mDrawPass : 8;  // offset: 0x20c
    u32 mDrawType : 8;  // offset: 0x20c
    u32 mShaderType : 4;  // offset: 0x20c
    u32 mInitFlag : 1;  // offset: 0x20c
    u32 mOfsInvalidMode : 1;  // offset: 0x20c
    u32 mSimpleEffect0227 : 2;  // offset: 0x20c
    f32 mParticleDeltaTime;  // offset: 0x210
    u32 mPrimAttribute;  // offset: 0x214
    u32 mParticleBuffSize;  // offset: 0x218
    u32 mLightGroupFlag;  // offset: 0x21c
    u32 mRandCtr;  // offset: 0x220
    u32 mSimpleEffect323c;  // offset: 0x224
public:
    static MyDTI DTI;
};
