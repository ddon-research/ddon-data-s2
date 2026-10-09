#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;
class MtVector3;
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }

// Declarations
class rDeformWeightMap;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rDeformWeightMap : public cResource
{
public:
    class MyDTI;
    struct LOD;
    struct HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct LOD
    {
    public:
        LOD();
        ~LOD();
        static void* memAlloc(size_t sz);
        static void memFree(void* p_addr);
        static void* operator new(size_t);
        static void operator delete(void*);
        static void* operator new[](size_t s);
        static void operator delete[](void* padr);
    public:
        u32 mNumParticles;  // offset: 0x0
        u32 mVtxTexH;  // offset: 0x4
        u32 mWindBarycentricIdx;  // offset: 0x8
        nDraw::Texture* mpTexInit;  // offset: 0x10
        nDraw::Texture* mpTexBatchVtx[8];  // offset: 0x18
        nDraw::Texture* mpTexFixPrimVtx;  // offset: 0x58
        nDraw::Texture* mpTexFixJoint;  // offset: 0x60
        nDraw::Texture* mpTexFixWeight;  // offset: 0x68
        nDraw::Texture* mpTexFixNormal;  // offset: 0x70
        nDraw::Texture* mpTexWindNormal;  // offset: 0x78
        nDraw::Texture* mpTexPseudoWind;  // offset: 0x80
        nDraw::VertexBuffer* mpSoftBodyVB;  // offset: 0x88
        u32* mVbByteIdx;  // offset: 0x90
        u32* mVbPrimIdx;  // offset: 0x98
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u8 version;  // offset: 0x4
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
    rDeformWeightMap();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void clear();  // vtable slot 15
protected:
    virtual ~rDeformWeightMap();
    HEADER* getHeader();
    void transferCpu2Gpu(nDraw::Texture* dst, void* src, s32 xPixel, s32 yLine, s32 pixelByte);
    void transferGpu2Cpu(void* dst, nDraw::Texture* src, s32 xPixel, s32 yLine, s32 pixelByte);
private:
    void* memAlloc(u32 sz);
    void memFree(void* p_addr);
public:
    LOD* mpLOD;  // offset: 0x70
    nDraw::VertexBuffer* mpQuadVB;  // offset: 0x78
    u32 mNumLOD;  // offset: 0x80
    u32* mpVertexBase;  // offset: 0x88
    u32 mVertexBaseNum;  // offset: 0x90
    u32 mSoftBodyVBstride;  // offset: 0x94
    s32* mpIsSimPerPrim;  // offset: 0x98
    u32* mpReductionVertexBase;  // offset: 0xa0
    u32 mPrimNum;  // offset: 0xa8
    HEADER mHeader;  // offset: 0xac
    bool mGrassWind;  // offset: 0xb4
    bool mDetailedWind;  // offset: 0xb5
    bool mPseudoWind;  // offset: 0xb6
    f32 mWindScalePoint;  // offset: 0xb8
    f32 mWindScaleDirection;  // offset: 0xbc
    bool mNCollision;  // offset: 0xc0
    f32 mNCGlobalWeight;  // offset: 0xc4
    bool mImageSpaceCollision;  // offset: 0xc8
    bool mApproxScrCollision;  // offset: 0xc9
    bool mScrCollision;  // offset: 0xca
    u32 mSbcType;  // offset: 0xcc
    u32 mSbcFilter;  // offset: 0xd0
    bool mColliderCollision;  // offset: 0xd4
    u32 mColliderType;  // offset: 0xd8
    u32 mColliderFilter;  // offset: 0xdc
    f32 mVtxColSize;  // offset: 0xe0
    f32 mAvoidZFight;  // offset: 0xe4
    bool mResetRestart;  // offset: 0xe8
    bool mSimCulling;  // offset: 0xe9
    f32 mAlpha;  // offset: 0xec
    u32 mMaxIterate;  // offset: 0xf0
    MtVector3 mGravity;  // offset: 0x100
    f32 mWeightOffset;  // offset: 0x110
    f32 mWorldCoeffTrans;  // offset: 0x114
    f32 mWorldCoeffRot;  // offset: 0x118
    s32 mBaseJointNo;  // offset: 0x11c
    u32 mWindGroupMask;  // offset: 0x120
    f32 mSoundThreashold;  // offset: 0x124
    bool mLocalOnly;  // offset: 0x128
    static MyDTI DTI;
    static const u32 TEX_W = 32;
    static const s32 DATA_VERSION = 53;
};
