#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "rModel.h"
#include "uBaseModel.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCriticalSection;
class MtDTI;
struct MtFloat3x4;
class MtMatrix;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector2;
class MtVector3;
class MtVector4;
class cDraw;
namespace nDraw { class Material; }
namespace nDraw { class VertexBuffer; }
class rTexture;

// Declarations
class cInstancing;
class cInstancingCulling;
class cInstancingDynamic;
class cInstancingFromMatrices;
template <typename _T, typename _I> class uInstancing;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cInstancing : public MtObject
{
public:
    cInstancing();
    virtual ~cInstancing() {}
    virtual void release() = 0;  // vtable slot 6
    virtual void setup();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void setVisible(u32, bool) = 0;  // vtable slot 9
    void setOwner(MtObject* p_owner);
    MtObject* getOwner() const;
    void setLightParam(u32 max_light_num, u32 light_group);
    void setLocalWindEnable(bool);
    u32 getSlot() const;
    void setSlot(u32);
    virtual bool setupInstancing(const MtOBB&, const MtMatrix&, const MtMatrix&) = 0;  // vtable slot 10
    virtual void updateLODParam(rModel::MODEL_INFO*) = 0;  // vtable slot 11
    virtual bool begin(cDraw*, uBaseModel::LOD_TYPE, bool) = 0;  // vtable slot 12
    virtual void end(cDraw*) = 0;  // vtable slot 13
    virtual void beginRecord(cDraw*) = 0;  // vtable slot 14
    virtual void endRecord(cDraw*) = 0;  // vtable slot 15
    virtual void drawBillboard(cDraw*) = 0;  // vtable slot 16
    virtual void drawInstance(cDraw*, const rModel::PRIMITIVE_INFO*, const nDraw::Material*) = 0;  // vtable slot 17
    virtual const MtMatrix& getWorldMatrix() const = 0;  // vtable slot 18
    bool getLODFadeEnable() const;
    void setLODFadeEnable(bool);
    bool getCamFadeEnable() const;
    void setCamFadeEnable(bool enable);
    bool getBillboardEnable() const;
    void setBillboardEnable(bool);
    void drawDebug();
    virtual u32 getInstanceNum() = 0;  // vtable slot 19
    virtual MtMatrix getInstanceMatrix(u32) = 0;  // vtable slot 20
protected:
    virtual MtFloat3x4& getInstanceMatrix3x4(u32) = 0;  // vtable slot 21
    virtual void entryInstance(u32, bool) = 0;  // vtable slot 22
    virtual void exitInstance(u32) = 0;  // vtable slot 23
    virtual void exitInstaceFilter(u32, u32) = 0;  // vtable slot 24
protected:
    MtObject* mpOwner;  // offset: 0x8
public:
    f32 mLODDistance[4];  // offset: 0x10
    u32 mSlot;  // offset: 0x20
    u32 mMaxLightNum;  // offset: 0x24
    u32 mLightGroup;  // offset: 0x28
    bool mUseBillboard;  // offset: 0x2c
    bool mUseLocalWind;  // offset: 0x2d
    bool mUseLodFade;  // offset: 0x2e
    bool mUseCamFade;  // offset: 0x2f
    bool mDebug;  // offset: 0x30
    static const u32 LOD_HIGH = 0;
    static const u32 LOD_MID = 1;
    static const u32 LOD_LOW = 2;
    static const u32 LOD_LOWEST = 3;
    static const u32 MAX_LOD = 4;
};

class cInstancingCulling : public cInstancing
{
public:
    class MyDTI;
    struct VisibleList;
    struct LOD;
    struct InstanceInfo;
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
        u32 count : 16;  // offset: 0x0
        u32 offset : 16;  // offset: 0x0
    };
public:
    struct InstanceInfo
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mIndex : 16;  // offset: 0x0
                u32 mFade : 6;  // offset: 0x0
                u32 mPriority : 8;  // offset: 0x0
                u32 mLOD : 2;  // offset: 0x0
            };  // offset: 0x0
            u32 mKey;  // offset: 0x0
        };  // offset: 0x0
    };
public:
    struct VisibleList
    {
    public:
        void init();
        void calcOffset();
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void operator delete(void*);
        static void operator delete[](void*);
    public:
        cInstancingCulling::LOD lod[4][2];  // offset: 0x0
        u32 lodPriority[4];  // offset: 0x20
        MtSphere sphere[3];  // offset: 0x30
        nDraw::VertexBuffer* vb_buf;  // offset: 0x60
        u32 vb_offset;  // offset: 0x68
        bool active;  // offset: 0x6c
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
    cInstancingCulling();
    virtual ~cInstancingCulling();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void updateLODParam(rModel::MODEL_INFO* pmi);  // vtable slot 11
    virtual bool begin(cDraw* pdraw, uBaseModel::LOD_TYPE lod, bool use_record);  // vtable slot 12
    virtual void end(cDraw* pdraw);  // vtable slot 13
    virtual void beginRecord(cDraw* pdraw);  // vtable slot 14
    virtual void endRecord(cDraw* pdraw);  // vtable slot 15
    virtual void drawInstance(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, const nDraw::Material* p_material);  // vtable slot 17
    virtual void drawBillboard(cDraw* pdraw);  // vtable slot 16
    void setFastCulling(bool);
    virtual const MtMatrix& getWorldMatrix() const;  // vtable slot 18
    static void setInstancingAllocator(MtAllocator* p_allocator);
    static MtAllocator* getInstancingAllocator();
    void setBillboardTexture(rTexture* p_texture);
    rTexture* getBillboardTexture() const;
    void setLodBillboardDistance(f32 dist);
    f32 getLodBillboardDistance() const;
    void setBillboardSize(const MtVector2& size);
    const MtVector2& getBillboardSize() const;
    void setUVSwitchEnable(bool);
    bool getUVSwitchEnable() const;
    void setBillboardPattern(const u32 pattern);
    u32 getBillboardPattern() const;
    s32 getPrevFrameDrawInstanceNum() const;
    static u32 entryList();
    static void releaseList(u32 index);
    static VisibleList* getVisibleList(u32);
protected:
    static s32 compare(const void* p_src1, const void* p_src2);
    u32 getVisiblity(f32 distance);
    u32 getVisiblity(uBaseModel::LOD_TYPE lod);
    void sort(InstanceInfo* p_list, u32 list_num);
    void sort(InstanceInfo* p_list, u32 list_num, u32 level_mask, VisibleList* p_vlist);
    bool culling(cDraw* pdraw, VisibleList* p_list, uBaseModel::LOD_TYPE lod);
    virtual void culling(cDraw*, u32&, VisibleList*, uBaseModel::LOD_TYPE, InstanceInfo*) = 0;  // vtable slot 25
    virtual u32 getInstancingSize(cDraw*) = 0;  // vtable slot 26
    virtual MtVector4 getInstanceColor(u32, f32) = 0;  // vtable slot 27
protected:
    rTexture* mpBillboardTexture;  // offset: 0x38
    f32 mLodBillboardDistance;  // offset: 0x40
    u32 mBillboardPattern;  // offset: 0x44
    MtVector2 mBillboardSize;  // offset: 0x48
    bool mUVSwitchEnable;  // offset: 0x50
    bool mUseFastCulling;  // offset: 0x51
    MtOBB mReferenceOBB;  // offset: 0x60
    MtMatrix mReferenceWorldMatrix;  // offset: 0xb0
    VisibleList mRecord[6];  // offset: 0xf0
public:
    static const u32 FADEING = 1;
    static const u32 SOLID = 0;
    static const u32 FADE_LEVEL = 15;
    static const u32 MAX_LIST = 32;
    static MyDTI DTI;
protected:
    static MtCriticalSection mCS;
    static s32 mListCount;
    static VisibleList mList[32];
private:
    static MtAllocator* mpAllocator;
};

class cInstancingDynamic : public cInstancingCulling
{
public:
    class MyDTI;
    struct Cluster;
    struct Instance;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Cluster
    {
    public:
        Cluster();
        ~Cluster();
        void setArea(const MtVector3& pos, f32 cluster);
        void resize(u32 request_size);
        void add(u32 index, const MtAABB& aabb, bool fadein);
        bool del(u32 index);
        bool delFilter(u32 filter, u32 mask);
        void fadeFilter(u32 filter, u32 mask, u8 fade_limit);
        bool intersect(const MtVector3& pos);
        bool visible(u32 index, bool enable);
        void fit();
        void setNext(cInstancingDynamic::Cluster* p_cluster);
        cInstancingDynamic::Cluster* getNext() const;
        u32 getInstanceNum() const;
        static void* operator new(size_t s);
        static void* operator new[](size_t);
        static void operator delete(void* pObj);
        static void operator delete[](void*);
    public:
        MtAABB mUsefulArea;  // offset: 0x0
        MtAABB mAABB;  // offset: 0x20
        u32 mInstanceNum : 16;  // offset: 0x40
        u32 mInstanceReserve : 16;  // offset: 0x40
        cInstancingDynamic::Instance* mpInstances;  // offset: 0x48
        cInstancingDynamic::Cluster* mpNext;  // offset: 0x50
    };
public:
    struct Instance
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t s);
        static void operator delete(void*);
        static void operator delete[](void* pObj);
    public:
        MtAABB aabb;  // offset: 0x0
        u32 index : 16;  // offset: 0x20
        u32 visiblity : 1;  // offset: 0x20
        u32 initialized : 1;  // offset: 0x20
        u32 cur_lod : 6;  // offset: 0x20
        u32 fade_limit : 8;  // offset: 0x20
        u32 fade_high : 8;  // offset: 0x24
        u32 fade_mid : 8;  // offset: 0x24
        u32 fade_low : 8;  // offset: 0x24
        u32 fade_lowest : 8;  // offset: 0x24
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
    cInstancingDynamic();
    virtual ~cInstancingDynamic();
    virtual void release();  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool setupInstancing(const MtOBB& obb, const MtMatrix& world_matrix, const MtMatrix& quant_matrix);  // vtable slot 10
    void setClusterSize(f32);
    void setPartsLevelCulling(bool);
protected:
    void updateAABB();
    virtual void entryInstance(u32 index, bool fadein);  // vtable slot 22
    virtual void exitInstance(u32 index);  // vtable slot 23
    virtual void exitInstaceFilter(u32 filter, u32 mask);  // vtable slot 24
    void fadeInstaceFilter(u32 filter, u32 mask, u8 fade_limit);
    virtual void setVisible(u32 index, bool enable);  // vtable slot 9
    virtual void culling(cDraw* pdraw, u32& list_num, cInstancingCulling::VisibleList* p_list, uBaseModel::LOD_TYPE lod, cInstancingCulling::InstanceInfo* p_instance);  // vtable slot 25
    virtual u32 getInstancingSize(cDraw* pdraw);  // vtable slot 26
    virtual MtVector4 getInstanceColor(u32 index, f32 fade);  // vtable slot 27
protected:
    Cluster* mpClusterRoot;  // offset: 0x390
    bool mPartsLevel;  // offset: 0x398
    f32 mClusterSize;  // offset: 0x39c
    u32 mCRC;  // offset: 0x3a0
public:
    static MyDTI DTI;
};

class cInstancingFromMatrices : public cInstancingDynamic
{
public:
    class MyDTI;
    struct Area;
    struct AreaInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Area
    {
    public:
        Area();
        ~Area();
        void create(const MtMatrix* instance_matrices, const u32& instance_num, u32& current_instance_num);
        s32 kill();
        bool isEmpty() const;
        bool isFadeIn() const;
        bool isFadeOut() const;
        void beginFadeIn();
        void endFadeIn();
        void beginFadeOut();
        void endFadeOut();
        void setFadeParam(f32 fade);
        f32 getFadeParam() const;
        void setInstanceOffset(const u32& offset);
        u32 getInstanceOffset() const;
        u32 getInstanceNum() const;
        MtFloat3x4& getMatrix3x4(const u32& index) const;
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void operator delete(void*);
        static void operator delete[](void*);
    public:
        u32 mEmpty : 1;  // offset: 0x0
        u32 mReserve : 5;  // offset: 0x0
        u32 mFadeIn : 1;  // offset: 0x0
        u32 mFadeOut : 1;  // offset: 0x0
        u32 mInstanceNum : 8;  // offset: 0x0
        u32 mInstanceIndexOffset : 16;  // offset: 0x0
        f32 mFade;  // offset: 0x4
        MtFloat3x4* mpInstanceMatrices;  // offset: 0x8
    };
public:
    struct AreaInfo
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mInstance : 8;  // offset: 0x0
                u32 mArea : 8;  // offset: 0x0
                u32 mNoUse : 16;  // offset: 0x0
            };  // offset: 0x0
            u32 mIndex;  // offset: 0x0
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
    cInstancingFromMatrices();
    virtual void release();  // vtable slot 6
    virtual void move();  // vtable slot 8
    s32 getId();
    void setFadeInFrame(f32 fadein_frame);
    void setFadeOutFrame(f32 fadeout_frame);
    void addInstance(u32 user_id, const MtMatrix* instance_matrices, const u32& instance_num, bool fadein);
    void delInstance(u32 user_id);
    void fadeInstace(u32 user_id);
    virtual u32 getInstanceNum();  // vtable slot 19
    virtual MtMatrix getInstanceMatrix(u32 index);  // vtable slot 20
    virtual MtFloat3x4& getInstanceMatrix3x4(u32 index);  // vtable slot 21
    void entry(u32 user_id);
    void exit(u32 user_id);
    void delInstanceProcess(u32 user_id);
public:
    Area mArea[256];  // offset: 0x3a8
    u8 mAreaHolder[256];  // offset: 0x13a8
    u32 mAreaCount;  // offset: 0x14a8
    f32 mFadeInFrame;  // offset: 0x14ac
    f32 mFadeOutFrame;  // offset: 0x14b0
    u32 mInstanceNum;  // offset: 0x14b4
    static MyDTI DTI;
    static const u32 MAX_AREA_NUM = 256;
};

template <typename _T, typename _I>
class uInstancing : public _T
{
public:
    uInstancing();
    virtual ~uInstancing();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    void drawInstance(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp, const nDraw::Material* p_material);
protected:
    _I mInstance;  // offset: 0x12e0
    bool mCache;  // offset: 0x27a0
};
