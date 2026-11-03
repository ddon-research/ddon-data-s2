#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "cUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtUI;
class MtVector3;
class rEffectList;
class uCamera;
class uCoord;
class uEffect;

// Declarations
class uEffectEmitter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uEffectEmitter : public cUnit
{
public:
    enum PARENT_CONST_TYPE
    {
        PARENT_CONST_TYPE_RELATE = 0,
        PARENT_CONST_TYPE_MAT = 1,
        PARENT_CONST_TYPE_POS = 2,
    };
    enum CAMERA_CONST_TYPE
    {
        CAMERA_CONST_TYPE_NONE = 0,
        CAMERA_CONST_TYPE_ROT_XZ = 1,
        CAMERA_CONST_TYPE_FULL = 2,
    };
    enum CONTROL_FLAG
    {
        CONTROL_FLAG_FINISH = 1,
        CONTROL_FLAG_CHAIN_RESET = 2,
        CONTROL_FLAG_TRANS = 4,
        CONTROL_FLAG_TRANS_MODE = 8,
        CONTROL_FLAG_PARENT_NO = 16,
        CONTROL_FLAG_CHILD_LOOP_FRAME = 32,
        CONTROL_FLAG_CHILD_LIFE_FRAME = 64,
        CONTROL_FLAG_CHILD_WAIT_FRAME = 128,
        CONTROL_FLAG_PLAY_SPEED = 256,
        CONTROL_FLAG_TIMER = 512,
        CONTROL_FLAG_PARTICLE_SCALE = 1024,
        CONTROL_FLAG_GENERATOR_SCALE = 2048,
        CONTROL_FLAG_MATRIX = 4096,
    };
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
    uEffectEmitter();
    virtual ~uEffectEmitter();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void kill();  // vtable slot 16
private:
    u32 getEffectMoveLine() const;
    void setEffectMoveLine(u32 EffectMoveLine);
    u32 getKillNo() const;
    void setKillNo(u32 KillNo);
    rEffectList* getEffectList();
    void setEffectList(rEffectList* pEffectList);
    u32 getFlagBitNum() const;
    bool getGroupFlagBit(u32 No) const;
    void setGroupFlagBit(bool Flag, u32 No);
    bool getMaterialFlagBit(u32 No) const;
    void setMaterialFlagBit(bool Flag, u32 No);
    u32 getParentConstType() const;
    void setParentConstType(u32 ParentConstType);
    u32 getCameraConstType() const;
    void setCameraConstType(u32 CameraConstType);
    u32 getEffectDrawMode() const;
    void setEffectDrawMode(u32 EffectDrawMode);
    u32 getOrder() const;
    void setOrder(u32 Order);
    u32 getAxisType() const;
    void setAxisType(u32 AxisType);
    u32 getRelationType() const;
    void setRelationType(u32 RelationType);
    u32 getEndType() const;
    void setEndType(u32 EndType);
    u32 getLoopFrame() const;
    void setLoopFrame(u32 LoopFrame);
    u32 getLifeFrame() const;
    void setLifeFrame(u32 LifeFrame);
    u32 getWaitFrame() const;
    void setWaitFrame(u32 WaitFrame);
    u32 getChildLoopFrame() const;
    void setChildLoopFrame(u32 ChildLoopFrame);
    u32 getChildLifeFrame() const;
    void setChildLifeFrame(u32 ChildLifeFrame);
    u32 getChildWaitFrame() const;
    void setChildWaitFrame(u32 ChildWaitFrame);
    MtVector3 getAngle() const;
    void setAngle(const MtVector3& Angle);
    void setDummyU32(u32);
    void finish();
    MtMatrix calcParentMatrix(s32 ParentNo);
    MtMatrix calcCameraMatrix();
    void clear();
private:
    bool mEmitFlag;  // offset: 0x48
    bool mEventMode;  // offset: 0x49
    bool mSyncUpdateMode;  // offset: 0x4a
    bool mTimerControlMode;  // offset: 0x4b
    bool mUGInvalidMode;  // offset: 0x4c
    bool mEffectTrans;  // offset: 0x4d
    bool mChainResetFlag;  // offset: 0x4e
    bool mShowMatrix;  // offset: 0x4f
    u32 mControlFlag;  // offset: 0x50
    u32 mKillNo : 16;  // offset: 0x54
    u32 mEffectMoveLine : 16;  // offset: 0x54
    rEffectList* mpEffectList;  // offset: 0x58
    u32 mGroupFlag;  // offset: 0x60
    u32 mMaterialFlag;  // offset: 0x64
    uCoord* mpParent;  // offset: 0x68
    uCamera* mpCamera;  // offset: 0x70
    u32 mParentConstType : 8;  // offset: 0x78
    u32 mCameraConstType : 8;  // offset: 0x78
    u32 mEffectDrawMode : 8;  // offset: 0x78
    u32 mEffectEmitter0827 : 8;  // offset: 0x78
    uEffect* mpEffect;  // offset: 0x80
    f32 mShowSize;  // offset: 0x88
    s32 mParentNo;  // offset: 0x8c
    u32 mOrder : 8;  // offset: 0x90
    u32 mAxisType : 8;  // offset: 0x90
    u32 mRelationType : 8;  // offset: 0x90
    u32 mEndType : 8;  // offset: 0x90
    u32 mLoopFrame : 16;  // offset: 0x94
    u32 mLifeFrame : 16;  // offset: 0x94
    u32 mWaitFrame : 16;  // offset: 0x98
    u32 mChildLoopFrame : 16;  // offset: 0x98
    u32 mChildLifeFrame : 16;  // offset: 0x9c
    u32 mChildWaitFrame : 16;  // offset: 0x9c
    f32 mPlaySpeed;  // offset: 0xa0
    u32 mTimer;  // offset: 0xa4
    f32 mParticleScale;  // offset: 0xa8
    MtVector3 mParticle3DScale;  // offset: 0xb0
    MtVector3 mGeneratorScale;  // offset: 0xc0
    MtVector3 mPos;  // offset: 0xd0
    MtVector3 mOfs;  // offset: 0xe0
    MtQuaternion mQuat;  // offset: 0xf0
    MtVector3 mDir;  // offset: 0x100
public:
    static MyDTI DTI;
};

inline void* uEffectEmitter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
