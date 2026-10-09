#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "rEffectList.h"
#include "sCollision.h"
#include "uBaseEffect.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtLineSegment;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtSphere;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
class cEffectJoint;
class cEffectStrip;
class cEffectUnitGenerator;
class cLineParticle;
class cParticle;
class cParticleGenerator;
class cParticleManager;
class cParticleMoveCustom;
class cParticleNode;
class rEffectList;
class uCoord;

// Declarations
class uEffect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uEffect : public uBaseEffect
{
    // inferred: cParticleManager::~cParticleManager calls uEffect::stopSoundSe
    friend class cParticleManager;
public:
    enum STATUS
    {
        STATUS_RESERVED_0 = 4096,
        STATUS_RESERVED_1 = 8192,
        STATUS_JOINT_FIX = 16384,
        STATUS_JOINT_UPDATE = 32768,
        STATUS_CHAIN_RESET = 65536,
        STATUS_UG_INVALID = 131072,
        STATUS_CONST_UPDATE = 262144,
        STATUS_UNIT_GENERATOR = 524288,
        STATUS_CHILD_UNIT_INIT = 1048576,
        STATUS_CHILD_UNIT_MOVE = 2097152,
        STATUS_SE_STOP = 4194304,
        STATUS_PARENT_SYMMETRY = 8388608,
        STATUS_CLEAR_MOVE_AFTER = 98304,
        STATUS_CLEAR_RESOURCE_SET = 16384,
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
    uEffect();
    virtual ~uEffect();
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void setParent(uCoord* pParent, s32 ParentNo);  // vtable slot 24
    virtual bool getBoundary(MtSphere* pdst);  // vtable slot 13
    virtual const MtMatrix& getWorldMatrix(s32 ParentNo) const;  // vtable slot 27
    virtual void setEffectParent(uCoord* pParent);  // vtable slot 28
    virtual void setEffectList(rEffectList* pEffectList);  // vtable slot 33
    virtual void doFinish();  // vtable slot 34
    virtual void doRestart();  // vtable slot 35
    virtual void doClear();  // vtable slot 36
    virtual void doKeepHoldOff();  // vtable slot 37
    void doReset();
    void addStatus(u32 Status);
    bool getUGInvalidMode() const;
    void setUGInvalidMode(bool Mode);
    bool getConstUpdateMode() const;
    void setConstUpdateMode(bool Mode);
    bool getSeStopMode() const;
    void setSeStopMode(bool Mode);
    bool getParentSymmetryMode() const;
    void setParentSymmetryMode(bool Mode);
    bool getJointFixMode() const;
    void setJointFixMode(bool Mode);
    bool getChainResetFlag() const;
    void setChainResetFlag(bool Flag);
    bool getJointUpdateFlag() const;
    void setJointUpdateFlag(bool Flag);
    f32 getParticleScale() const;
    void setParticleScale(f32 ParticleScale);
    MtVector3 getParticle3DScale() const;
    void setParticle3DScale(const MtVector3& Particle3DScale);
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
    u32 getLightPriority() const;
    void setLightPriority(u32 LightPriority);
    f32 getGravityCoef() const;
    void setGravityCoef(f32);
    f32 getWaitFrameCoef() const;
    void setWaitFrameCoef(f32 WaitFrameCoef);
    u32 getFlagBitNum() const;
    bool getGroupFlagBit(u32 No) const;
    void setGroupFlagBit(bool Flag, u32 No);
    u32 getGroupFlag() const;
    bool getMaterialFlagBit(u32 No) const;
    void setMaterialFlagBit(bool Flag, u32 No);
    u32 getMaterialFlag() const;
    u32 getGeneratorBuffSize() const;
    u32 getGeneratorNum() const;
    u32 getGeneratorMoveNum() const;
    u32 getJointNum() const;
    u32 getJointMoveNum() const;
    void setResourceParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag);
    void setResourceParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, uEffect* pParentGenerator, s32 SetNo, f32 SetRate);
    void setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtQuaternion& Quat, uCoord* pParent, s32 ParentNo, const MtVector3& Ofs, u32 Order);
    void setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtQuaternion& Quat, const MtVector3& Pos, u32 Order);
    void setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtMatrix& Wmat, const MtVector3& Ofs, u32 Order);
    void setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtVector3& Dir, uCoord* pParent, s32 ParentNo, const MtVector3& Ofs, u32 Order, u32 AxisType);
    void setParam(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtVector3& Dir, const MtVector3& Pos, u32 Order, u32 AxisType);
    u32 getUnitNo() const;
    u32 getChildUnitMoveNum() const;
    void addChildUnitMoveNum();
    u32 getParentGeneratorId() const;
    bool isChild(uEffect*) const;
    u32 getChildUnitLevel() const;
    void setChildUnitLevel(uEffect* pEffect);
    u32 getEntryType() const;
    u32 getGeneratorEntryType(u32 ListNo) const;
    bool isUnitGenerator() const;
    cEffectUnitGenerator* getEffectUnitGenerator();
    u32 getParentGeneratorTimer() const;
    u32 getParticleHitList(MtVector4* pHitList, u32 HitListNum, u32 SkipNum) const;
    void setParticleAdhesionDivideMax(u32 Max);
    void setParticleTrailTailOffset(const MtVector3& Offset);
    void unconstParticleLineClothChain(u32 Mode);
    void unconstParticleLineClothChain(u32 Mode, u32 ListNo);
    void setAllDrawVolume(f32 Volume);
    void setAllDrawVolume(f32 Volume, u32 ViewportNo);
    void setDrawVolume(f32 Volume, u32 ListNo);
    void setDrawVolume(f32 Volume, u32 ViewportNo, u32 ListNo);
    void setAllGeneratorRangeScale(const MtVector3& Scale);
    s32 getDrawDepthBias() const;
    void setDrawDepthBias(s32);
    u32 getLoopCtr() const;
    u32 getRand();
    f32 getRandF();
    void setRandCtr(u32 RandCtr);
    bool updateDrawBuffSize(u32 DrawBuffSize);
    virtual void correctColorIntensity(cParticleGenerator* pGenerator, MtColor* pColor, u32 ColorNum, u32* pIntensity);  // vtable slot 41
    virtual f32 correctModelEnvMapPower(cParticleGenerator* pGenerator, const MtVector3& Pos, f32 OrgEnvMapPower);  // vtable slot 42
    virtual MtVector4 correctFilterColor(cParticleGenerator* pGenerator, const MtVector3& Pos, const MtVector4& OrgColor);  // vtable slot 43
    virtual MtVector3 correctLightColor(cParticleGenerator* pGenerator, const MtVector3& Pos, const MtVector3& OrgColor);  // vtable slot 44
    virtual u32 getSynchroFilterDrawView() const;  // vtable slot 45
    virtual u32 getSynchroLightDrawView() const;  // vtable slot 46
    virtual u32 getParticleCustomPosSize(rEffectList::EFL_PARTICLE_CUSTOM* pCustomParam) const;  // vtable slot 47
    virtual u32 getParticleCustomDrawBuffSize(rEffectList::EFL_PARTICLE_CUSTOM* pCustomParam) const;  // vtable slot 48
    // Address: 0x01b65910 - 0x01b65911 (1 bytes)
    virtual void initParticleCustom(cParticleGenerator* pGenerator, cParticle* pParticle, f32 LifeRate) {}  // vtable slot 49
    virtual bool moveParticleCustom(cParticleGenerator* pGenerator, cParticle* pParticle);  // vtable slot 50
    // Address: 0x01ad5f00 - 0x01ad5f01 (1 bytes)
    virtual void initParticleLineCustomOfs(cParticleGenerator* pGenerator, cLineParticle* pLineParticle) {}  // vtable slot 51
    // Address: 0x01ad5f10 - 0x01ad5f11 (1 bytes)
    virtual void moveParticleLineCustomOfs(cParticleGenerator* pGenerator, cLineParticle* pLineParticle) {}  // vtable slot 52
    // Address: 0x01ad5f20 - 0x01ad5f21 (1 bytes)
    virtual void initParticleMoveCustom(cParticleGenerator* pGenerator, cParticle* pParticle, cParticleMoveCustom* pParticleMove, cEffectStrip& Strip, f32 LifeRate) {}  // vtable slot 53
    virtual bool moveParticleMoveCustom(cParticleGenerator* pGenerator, cParticle* pParticle, cParticleMoveCustom* pParticleMove, bool ConstUpdateMode);  // vtable slot 54
    // Address: 0x01ad5f40 - 0x01ad5f41 (1 bytes)
    virtual void updateParticleCustomLoop(cParticleGenerator* pGenerator) {}  // vtable slot 55
    // Address: 0x01ad5f50 - 0x01ad5f51 (1 bytes)
    virtual void drawParticleCustomLoop(cParticleGenerator* pGenerator, cDraw* pDraw, s32 Transparency, u8* pDrawBuff) {}  // vtable slot 56
    bool isCreateChildUnit() const;
    MT_CTSTR getEffectListPath() const;
    static MtVector3 calcDir(const MtVector3& Rot, u32 Order, u32 AxisType);
protected:
    void constructEffect();
    void destructEffect();
    virtual uEffect* openEffect();  // vtable slot 57
    virtual void restart();  // vtable slot 38
    virtual bool createGenerator();  // vtable slot 58
    virtual void releaseGenerator();  // vtable slot 59
    virtual bool updateParentEnable();  // vtable slot 60
    virtual bool checkEffectList(u32 ListNo);  // vtable slot 61
    void initJointParam(cEffectJoint* pJoint);
    void initParticleManagerParam(cParticleManager* pManager);
    void updateConstUpdateFlag();
    void addGeneratorBuffSize(u32 Size);
    bool checkParentGenerator();
    virtual void setupUnitGenerator();  // vtable slot 62
    virtual void setupUnit();  // vtable slot 63
    void moveParticleManager();
    void moveEffectUnitGenerator();
    void moveChildUnit();
    void moveJointBefore();
    void moveJointAfter();
    virtual void updateJointWorldMatrix(cEffectJoint* pJoint);  // vtable slot 64
    virtual const MtMatrix& getGeneratorParentWorldMatrix(s32 ParentNo, bool ParentSymmetry) const;  // vtable slot 65
    virtual const MtMatrix& getGeneratorSubParentWorldMatrix(s32 ParentNo, bool ParentSymmetry) const;  // vtable slot 66
    void applyBillboardMatrix(cEffectJoint* pJoint);
    void updateConstJoint();
    void updateConstParticleManager();
    void updateParticleManager();
    virtual void setupGenerator(cParticleGenerator* pGenerator);  // vtable slot 67
    virtual void setupNode(cParticleNode* pNode);  // vtable slot 68
    virtual void applyGeneratorWorldMatrix(cParticleGenerator* pGenerator);  // vtable slot 69
    virtual void applyNodeWorldMatrix(cParticleNode* pNode);  // vtable slot 70
    virtual u32 updateParticlePosForce(u32 ForceType, f32 ForceRate, const MtVector3& ForceVec, MtVector3& Pos);  // vtable slot 71
    virtual u32 checkCollisionLine(sCollision::TriangleInfo* pTriangleInfo, u32* pPtclFlag, const MtLineSegment& LineSegment, rEffectList::EFL_PARAM_COLL* pCollParam);  // vtable slot 72
    virtual u32 checkCollsionSphere(sCollision::TriangleInfo* pTriangleInfo, u32* pPtclFlag, MtVector3& Pos, const MtVector3& OldPos, f32 Radius, rEffectList::EFL_PARAM_COLL* pCollParam);  // vtable slot 73
    virtual u32 setCollBounceReaction(rEffectList::EFL_PARAM_COLL* pCollParam, sCollision::TriangleInfo* pInfo, u32 Attribute);  // vtable slot 74
    virtual u32 setCollFinishReaction(rEffectList::EFL_PARAM_COLL* pCollParam, sCollision::TriangleInfo* pInfo, u32 Attribute);  // vtable slot 75
    virtual u32 getCollBounceMaterialFlag(sCollision::TriangleInfo* pTriangleInfo) const;  // vtable slot 76
    virtual u32 getCollFinishMaterialFlag(sCollision::TriangleInfo* pTriangleInfo) const;  // vtable slot 77
    virtual void requestSoundSe(cParticleManager* pManager);  // vtable slot 78
    virtual void stopSoundSe(cParticleManager* pManager);  // vtable slot 79
private:
    bool createParticleManager();
    bool allocGeneratorBuff();
    bool initJoint();
    bool initParticleManager();
    bool checkJointContinue(u32 JointNo);
    const MtMatrix& getParentWorldMatrix(s32 ParentNo, bool ParentSymmetry) const;
    void applyUnitParam();
    void setSerialEffect(u32 LoopFrame);
    bool isJointUpdate() const;
public:
    virtual bool isEffectSt();  // vtable slot 80
protected:
    MtVector3 mParticle3DScale;  // offset: 0x1d0
    f32 mParticleScale;  // offset: 0x1e0
    u32 mLifeTimer : 16;  // offset: 0x1e4
    u32 mLifeFrame : 16;  // offset: 0x1e4
    u32 mWaitFrame : 16;  // offset: 0x1e8
    u32 mLightPriority : 8;  // offset: 0x1e8
    u32 mChildUnitLevel : 8;  // offset: 0x1e8
    f32 mGravityCoef;  // offset: 0x1ec
    u32 mDrawBuffSize;  // offset: 0x1f0
    s32 mSetNo;  // offset: 0x1f4
    u32 mGroupFlag;  // offset: 0x1f8
    u32 mMaterialFlag;  // offset: 0x1fc
    uEffect* mpParentGenerator;  // offset: 0x200
    u32 mParentGeneratorId;  // offset: 0x208
    u32 mChildUnitMoveNum : 16;  // offset: 0x20c
    u32 mChildLoopFrame : 16;  // offset: 0x20c
    u32 mChildLifeFrame : 16;  // offset: 0x210
    u32 mChildWaitFrame : 16;  // offset: 0x210
    u32 mGeneratorNum : 16;  // offset: 0x214
    u32 mGeneratorMoveNum : 16;  // offset: 0x214
    u32 mJointNum : 16;  // offset: 0x218
    u32 mJointMoveNum : 16;  // offset: 0x218
    u32 mUnitNo;  // offset: 0x21c
    u32 mGeneratorBuffSize;  // offset: 0x220
    cParticleManager* mpManager;  // offset: 0x228
    cEffectJoint* mJoint;  // offset: 0x230
    u8* mpChildUnitBuff;  // offset: 0x238
    f32 mWaitFrameCoef;  // offset: 0x240
    f32 mBoundaryRadius;  // offset: 0x244
    u32 mChildSetRate : 12;  // offset: 0x248
    u32 mSerialEffectType : 4;  // offset: 0x248
    u32 mSerialEffectWaitTimer : 16;  // offset: 0x248
    s32 mDrawDepthBias;  // offset: 0x24c
    u32 mLoopCtr : 16;  // offset: 0x250
    u32 mRandCtr : 16;  // offset: 0x250
public:
    static MyDTI DTI;
};
