#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cResPath.h"
#include "../shared/rCaughtInfoParam.h"
#include "../shared/rCollision.h"
#include "../shared/rDeformWeightMap.h"
#include "../shared/rEffectProvider.h"
#include "../shared/rJointInfo.h"
#include "../shared/rModel.h"
#include "../shared/rMotionList.h"
#include "../shared/rObjCollision.h"
#include "../shared/rRigidBody.h"
#include "../shared/rSoundMotionSe.h"
#include "../shared/rSoundRequest.h"
#include "../shared/rSwingModel.h"
#include "../shared/rTable.h"
#include "../shared/rZone.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
class MtString;
class MtVector3;
class rCaughtInfoParam;
class rCollision;
class rDeformWeightMap;
class rEffectProvider;
class rJointInfo;
class rModel;
class rMotionList;
class rObjCollision;
class rRigidBody;
class rSoundMotionSe;
class rSoundRequest;
class rSwingModel;
class rZone;

// Declarations
class cOmParam;
class rOmParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cOmParam : public MtObject
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
    MT_CTSTR getModelPath();
    void setModelPath(const MtString& path);
    cOmParam();
    virtual ~cOmParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getOmUnitID() const;
    u32 getOmFlag() const;
    bool isOmFlag(u32 flag) const;
    bool isOmStatus(u32 flag) const;
    bool isReqSeFlag(u32 flag) const;
    bool chkVersion() const;
    bool chkVersion(u32 targetVersion) const;
public:
    s32 mOmID;  // offset: 0x8
    u32 mUnitDTIID;  // offset: 0xc
    u32 mUseComponent;  // offset: 0x10
    u32 mOmSetType;  // offset: 0x14
    u32 mDetailBehavior;  // offset: 0x18
    u32 mReqSeFlag;  // offset: 0x1c
    MtString mOmComment;  // offset: 0x20
    u32 mColliOffFrame;  // offset: 0x28
    s32 mJointNum;  // offset: 0x2c
    s32 mTargetJntNo;  // offset: 0x30
    u32 padding0;  // offset: 0x34
    MtVector3 mTargetOfs;  // offset: 0x40
    u32 mMapIcon;  // offset: 0x50
    f32 mKillLength;  // offset: 0x54
    u32 mVersion;  // offset: 0x58
    bool mbUseNightColor;  // offset: 0x5c
    MtVector3 mNightColor;  // offset: 0x60
    f32 mRigidTime;  // offset: 0x70
    f32 mRigidForce;  // offset: 0x74
    f32 mRigidOfsY;  // offset: 0x78
    f32 mRigidVelocity;  // offset: 0x7c
    f32 mThrowVelocity;  // offset: 0x80
    f32 mThrowVectorY;  // offset: 0x84
    f32 mRigidWorldOfsY;  // offset: 0x88
    f32 mRigid1Frame;  // offset: 0x8c
    u32 mBlinkType;  // offset: 0x90
    u32 mArcTagID;  // offset: 0x94
    f32 mOffSeLength;  // offset: 0x98
    u32 padding1;  // offset: 0x9c
    MtVector3 mKeyOfs;  // offset: 0xa0
    bool mbAtk;  // offset: 0xb0
    u32 mShotGroup;  // offset: 0xb4
    s32 mWepType;  // offset: 0xb8
    bool mbNav;  // offset: 0xbc
    MtVector3 mNavOBBPos;  // offset: 0xc0
    MtVector3 mNavOBBExtent;  // offset: 0xd0
    cResPath<rModel> mrModel;  // offset: 0xe0
    cResPath<rObjCollision> mrObjCollision;  // offset: 0xe8
    cResPath<rMotionList> mrMotionList;  // offset: 0xf0
    cResPath<rSoundMotionSe> mrSoundMotionSe;  // offset: 0xf8
    cResPath<rSoundRequest> mrSoundRequest;  // offset: 0x100
    cResPath<rEffectProvider> mrEffectProvider;  // offset: 0x108
    cResPath<rSwingModel> mrSwingModel;  // offset: 0x110
    cResPath<rDeformWeightMap> mrSoftBody;  // offset: 0x118
    cResPath<rRigidBody> mrRigidBody;  // offset: 0x120
    cResPath<rModel> mrBrModel;  // offset: 0x128
    cResPath<rRigidBody> mrBrRigidBody;  // offset: 0x130
    cResPath<rDeformWeightMap> mrBrSoftBody;  // offset: 0x138
    cResPath<rCollision> mrCollision[2][2];  // offset: 0x140
    cResPath<rCaughtInfoParam> mrCaught;  // offset: 0x160
    cResPath<rZone> mrZone;  // offset: 0x168
    cResPath<rZone> mrOmZone;  // offset: 0x170
    cResPath<rJointInfo> mrJointInfo;  // offset: 0x178
    s32 mFxIndex[4];  // offset: 0x180
    s32 mSeIndex[4];  // offset: 0x190
    static MyDTI DTI;
    static const u32 DATA_VERSION = 56;
    static const u32 FxSndNum = 4;
};

class rOmParam : public rTable
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
    rOmParam();
    virtual const MtDTI& getDataDTI();  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u16 getDataVersion();  // vtable slot 18
    virtual bool load(MtStream& in);  // vtable slot 11
    bool loadData(MtDataReader& in);
    virtual bool save(MtStream& out);  // vtable slot 12
    bool saveData(MtDataWriter& out);
    bool loadData(MtDataReader& in, cOmParam* pData);
    bool saveData(MtDataWriter& out, cOmParam* pData);
    cOmParam* getData(u32 Idx);
    void setData(MtObject*, u32);
public:
    static MyDTI DTI;
};
