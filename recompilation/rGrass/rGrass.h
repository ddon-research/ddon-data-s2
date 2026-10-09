#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtEaseCurve.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "cBVHGrass.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtColor;
class MtDTI;
class MtDataReader;
class MtHermiteCurve;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
namespace nDraw { class VertexBuffer; }
class rTexture;

// Declarations
class rGrass;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rGrass : public cResource
{
public:
    enum GRASSTYPE
    {
        GT_QUAD = 0,
        GT_CHAIN = 1,
        GT_MAX = 2,
    };
public:
    class MyDTI;
    struct HEADER;
    class cCluster;
    class cSetting;
    class cChainGrass;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 dummy;  // offset: 0x6
    };
public:
    class cCluster : public MtObject
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
        cCluster();
        virtual ~cCluster();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& in);
        virtual bool load(MtStream& in);  // vtable slot 6
        virtual bool save(MtStream& out);  // vtable slot 7
        void draw(cDraw* pdraw, u32 index, const u32 max_index, const u32 verte_offset, const u32 max_vertex);
        bool isNoProblem() const;
        void updateGlobalWind();
        MtVector4* getPreviousGlobalWind();
        MtVector4* getGlobalWind();
    public:
        u32 mIndexCount;  // offset: 0x8
        u32 mVertexCount;  // offset: 0xc
        f32 mDistance;  // offset: 0x10
        MtVector4 mDequantizationCoordScale;  // offset: 0x20
        MtVector4 mDequantizationCoordOffset;  // offset: 0x30
    protected:
        MtVector4 mWindDirection[2][8];  // offset: 0x40
        u8 mGlobalRing;  // offset: 0x140
    public:
        s32 mVertexBase;  // offset: 0x144
        u32 mVertexStride;  // offset: 0x148
        static MyDTI DTI;
        static const u8 MAX_HISTORY = 2;
        static const u8 MAX_LOCAL_WIND = 8;
    };
public:
    class cChainGrass : public MtObject
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
        cChainGrass();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        MtVector3 getVelocity();
        f32 getTheta();
    protected:
        f32 mPower;  // offset: 0x8
        f32 mTheta;  // offset: 0xc
        MtVector3 mDirection;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cSetting : public MtObject
    {
    public:
        class MyDTI;
        struct CBGrassChain;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct CBGrassChain
        {
        public:
            MtVector4 chain[16];  // offset: 0x0
            MtVector3 normal[16];  // offset: 0x100
            MtVector3 tangent[16];  // offset: 0x200
            MtVector4 uv[16];  // offset: 0x300
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
        cSetting();
        virtual ~cSetting();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool load(MtDataReader& in);
        virtual bool load(MtStream& in);  // vtable slot 6
        virtual bool save(MtStream& out);  // vtable slot 7
        void update();
        void setBegin(f32 begin);
        void setWidth(f32 width);
        f32 getBegin();
        f32 getWidth();
        f32 getRatio() const;
        void setRatio(f32 ratio);
        CBGrassChain* getChain();
        MtVector4* getChainPosition();
        MtVector3* getChainNormal();
        MtVector3* getChainTangent();
        MtVector4* getGlobalWindParam();
        rTexture* getTexture() const;
        void setTexture(rTexture* ptex);
        rTexture* getAlbedoTexture() const;
        void setAlbedoTexture(rTexture* ptex);
        rTexture* getMaskTexture() const;
        void setMaskTexture(rTexture* ptex);
        rTexture* getNormalTexture() const;
        void setNormalTexture(rTexture* ptex);
        void setScale(f32 scale);
        f32 getScale();
        void setAspect(f32 aspect);
        f32 getAspect();
        f32 getSpecularPower();
        f32 getTranslucent();
        MtVector4* getColorOffset();
        MtVector4* getColorScale();
        MtVector4 getColorOffsetR();
        MtVector4 getColorScaleR();
        f32 getCurveBeginValue() const;
        f32 getCurveEndValue() const;
        rGrass::cChainGrass* getChainGrassParam(u32);
    private:
        f32 mRatio;  // offset: 0x8
        f32 mCurveBeginValue;  // offset: 0xc
        f32 mCurveEndValue;  // offset: 0x10
        rGrass::cChainGrass mChainGrassParams[2];  // offset: 0x20
        MtVector4 mGlobalWindParam;  // offset: 0x60
        MtVector4 mColorOffset;  // offset: 0x70
        MtVector4 mColorScale;  // offset: 0x80
        CBGrassChain mChain;  // offset: 0x90
        MtVector4* mChainGrass;  // offset: 0x490
        MtVector3* mChainGrassNormal;  // offset: 0x498
        MtVector3* mChainGrassTangent;  // offset: 0x4a0
        MtHermiteCurve mWeightCurve;  // offset: 0x4a8
        rTexture* mpAlbedoMap;  // offset: 0x4e8
        rTexture* mpMaskMap;  // offset: 0x4f0
        rTexture* mpNormalMap;  // offset: 0x4f8
        f32 mSpecularPower;  // offset: 0x500
        f32 mTranslucent;  // offset: 0x504
        f32 mScale;  // offset: 0x508
        f32 mAspect;  // offset: 0x50c
        f32 mBegin;  // offset: 0x510
        f32 mWidth;  // offset: 0x514
        MtColor mColorOne;  // offset: 0x518
        MtColor mColorTwo;  // offset: 0x51c
    public:
        static MyDTI DTI;
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
    rGrass();
    virtual ~rGrass();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& stream);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    cTree<cCluster>* getTree();
    virtual MtArray* getParams();  // vtable slot 16
    MtArray* getClusters();
    bool isCompressed() const;
    f32 getMaxLength() const;
    u32 getGrassType() const;
    cSetting* getSettingList();
    HEADER* getHeader();
    nDraw::VertexBuffer* getVertexBuffer();
    u32 getVertexStride() const;
    u32 getVertexNum() const;
    void setVertexBuffer(cDraw* pdraw);
protected:
    void buildTree();
protected:
    HEADER mHeader;  // offset: 0x70
    cTree<cCluster> mCluster;  // offset: 0x78
    MtArray mParams;  // offset: 0xb0
    MtArray mClusters;  // offset: 0xd0
    cCluster* mpNativeClusters;  // offset: 0xf0
    bool mUseComp;  // offset: 0xf8
    u32 mVertexCount;  // offset: 0xfc
    u32 mVertexStride;  // offset: 0x100
    u32 mGrassType;  // offset: 0x104
    f32 mMaxLength;  // offset: 0x108
    nDraw::VertexBuffer* mpVertexBuffer;  // offset: 0x110
    cSetting mSettingList[8];  // offset: 0x120
public:
    static const u32 MAX_SETTING = 8;
    static const u32 MAX_LOCAL_WIND = 8;
    static MyDTI DTI;
protected:
    static const u16 DATA_VERSION = 4048;
};
