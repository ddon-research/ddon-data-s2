#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive3D.h"
#include "cUnit.h"
#include "sScene.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
struct MtFloat3x4;
struct MtFloat4;
struct MtFloat4x4;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
class cLightVolume;
class rTexture;

// Declarations
class uLight;

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

class uLight : public cUnit
{
public:
    enum MODE
    {
        MODE_DEFAULT = 0,
        MODE_DIFFUSE = 1,
        MODE_SPECULAR = 2,
        MODE_BALANCE = 3,
        __MODE__U32 = -1,
    };
    enum GROUP
    {
        GROUP_0 = 1,
        GROUP_1 = 2,
        GROUP_2 = 4,
        GROUP_3 = 8,
        GROUP_4 = 16,
        GROUP_5 = 32,
        GROUP_6 = 64,
        GROUP_7 = 128,
        GROUP_8 = 256,
        GROUP_9 = 512,
        GROUP_10 = 1024,
        GROUP_11 = 2048,
        GROUP_12 = 4096,
        GROUP_13 = 8192,
        GROUP_14 = 16384,
        GROUP_15 = 32768,
        GROUP_16 = 65536,
        GROUP_17 = 131072,
        GROUP_18 = 262144,
        GROUP_19 = 524288,
        GROUP_20 = 1048576,
        GROUP_21 = 2097152,
        GROUP_22 = 4194304,
        GROUP_23 = 8388608,
        GROUP_24 = 16777216,
        GROUP_25 = 33554432,
        GROUP_26 = 67108864,
        GROUP_27 = 134217728,
        GROUP_28 = 268435456,
        GROUP_29 = 536870912,
        GROUP_30 = 1073741824,
        GROUP_31 = -2147483648,
        GROUP_ALL = -1,
    };
    enum TYPE
    {
        TYPE_NONE = 0,
        TYPE_INFINITE = 1,
        TYPE_POINT = 2,
        TYPE_SPOT = 3,
        TYPE_AMBIENT = 4,
        TYPE_CAPSULE = 5,
        TYPE_CUBOID = 6,
        MAX_TYPE = 7,
    };
    enum ATTR
    {
        ATTR_FADEOUT = 1,
        ATTR_SH = 2,
        ATTR_SUBTRACT = 4,
        ATTR_PERPIXEL = 8,
        ATTR_VIEWCOORD = 16,
        ATTR_DISP = 32,
        ATTR_RANGE = 64,
        ATTR_OBB_RANGE = 128,
    };
public:
    class MyDTI;
    struct DYNAMIC_LIGHT_PARAM;
    struct KEY;
    struct SHFACTOR;
    class cHardwareDispCtrlLight;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DYNAMIC_LIGHT_PARAM
    {
    public:
        MtFloat3 LightPos;  // offset: 0x0
        f32 LightMask0;  // offset: 0xc
        MtFloat3 LightDir;  // offset: 0x10
        f32 LightMask1;  // offset: 0x1c
        MtFloat3 LightColor;  // offset: 0x20
        f32 LightBalance;  // offset: 0x2c
        MtFloat4 LightAttn;  // offset: 0x30
        MtFloat4 LightAttn2;  // offset: 0x40
        MtFloat3x4 RangeMat;  // offset: 0x50
        MtFloat4x4 ProjMat;  // offset: 0x80
    };
public:
    struct KEY
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 texture_type : 8;  // offset: 0x0
                u32 decode_type : 8;  // offset: 0x0
                u32 shader_index : 16;  // offset: 0x0
            };  // offset: 0x0
            u32 key;  // offset: 0x0
        };  // offset: 0x0
    };
public:
    struct SHFACTOR
    {
    public:
        MtVector4 r[3];  // offset: 0x0
        MtVector4 g[3];  // offset: 0x30
        MtVector4 b[3];  // offset: 0x60
    };
public:
    class cHardwareDispCtrlLight : public cUnit::cHardwareDispCtrl
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
        cHardwareDispCtrlLight();
        cHardwareDispCtrlLight(cUnit* pOwner);
        virtual void update();  // vtable slot 7
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
    uLight();
    virtual ~uLight();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual u64 getSystemUnitGroup() const;  // vtable slot 8
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    MtVector3 getColor() const;
    void setColor(const MtVector3& v);
    f32 getBalance() const;
    void setBalance(f32 v);
    virtual bool getSHFactor(cDraw* pdraw, const MtSphere& sphere, SHFACTOR* pfactor) const;  // vtable slot 24
    virtual void setState(cDraw* pdraw, u32 slot, bool approx_enable);  // vtable slot 25
    SO_HANDLE getFunction();
    SO_HANDLE getApproxFunction();
    rTexture* getProjectionTexture();
    void setProjectionTexture(rTexture* ptex);
    u32 getGroup() const;
    void setGroup(u32 group);
    bool getApproximateDisable();
    void setApproximateDisable(bool diable);
    u32 getAttr() const;
    void setAttr(u32 attr);
    u32 getPriority() const;
    void setPriority(u32 v);
    u32 getType() const;
    void setShadowAtten(const MtFloat2& se);
    MtFloat2 getShadowAtten() const;
    bool isLighted(const MtSphere& sphere) const;
    bool isLighted(const MtAABB&) const;
    bool isBound() const;
    bool isSH() const;
    const MtSphere& getBoundingSphere() const;
    const MtAABB& getBoundingBox() const;
    virtual bool getBoundary(MtSphere* pdst);  // vtable slot 13
    bool isLimitRangeEnable() const;
    void setLimitRangeEnable(bool enable);
    virtual bool getLimitRangeOBB(MtOBB* obb) const;  // vtable slot 26
    // Address: 0x01b08fb0 - 0x01b08fb1 (1 bytes)
    virtual void setLimitRangeOBB(const MtOBB& obb) {}  // vtable slot 27
    bool isFadeOut() const;
    sScene::Node* getSceneNode();
    virtual void getDrawUnitState(u32& type, u32& priority) const;  // vtable slot 18
    void setMode(MODE mode);
    u32 getMode();
    u32 getSortingKey() const;
    u32 getApproxSortingKey() const;
protected:
    void setBalanceSimulatedLightParam(DYNAMIC_LIGHT_PARAM* pparam);
public:
    virtual cUnit::cHardwareDispCtrl* createHardwareDispCtrl();  // vtable slot 23
    void setPS3DisableMode(bool set);
    void setPS4DisableMode(bool set);
    void setPCDisableMode(bool set);
    bool getPS3DisableMode();
    bool getPS4DisableMode();
    bool getPCDisableMode();
protected:
    u32 mAttr : 8;  // offset: 0x48
    u32 mType : 6;  // offset: 0x48
    u32 mBound : 1;  // offset: 0x48
    u32 mWbFlag : 1;  // offset: 0x48
    u32 mApproximateDisable : 1;  // offset: 0x48
    u32 mPriority : 15;  // offset: 0x48
    u32 mGroup;  // offset: 0x4c
    f32 mBalance;  // offset: 0x50
    MtFloat2 mShadowAtten;  // offset: 0x54
    u32 mMode;  // offset: 0x5c
    MtVector3 mColor;  // offset: 0x60
    DYNAMIC_LIGHT_PARAM mLightParam[2];  // offset: 0x70
    DYNAMIC_LIGHT_PARAM mApproxLightParam[2];  // offset: 0x1f0
    SO_HANDLE mLightFunction;  // offset: 0x370
    SO_HANDLE mApproxLightFunction;  // offset: 0x374
    MtAABB mBoundingBox;  // offset: 0x380
    MtSphere mBoundingSphere;  // offset: 0x3a0
    rTexture* mpProjectionTexture;  // offset: 0x3b0
    cLightVolume* mplightVolume;  // offset: 0x3b8
    KEY mDefault;  // offset: 0x3c0
    KEY mApproximate;  // offset: 0x3c4
private:
    sScene::Node mNode;  // offset: 0x3c8
    bool mIsPS3Disable;  // offset: 0x3d8
    bool mIsPS4Disable;  // offset: 0x3d9
    bool mIsPCDisable;  // offset: 0x3da
public:
    static MyDTI DTI;
};
