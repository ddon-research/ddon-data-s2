#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "rEffect2D.h"
#include "uCoord.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class cDraw;
class cEffectValueU32;
class cParticle2D;
class cParticle2DGenerator;
class cParticle2DMoveCustom;
namespace nDraw { class Texture; }
class rEffect2D;

// Declarations
class uEffect2D;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class uEffect2D : public uCoord
{
public:
    enum STATUS
    {
        STATUS_INIT = 1,
        STATUS_SLEEP = 2,
        STATUS_SCHEDULER = 4,
        STATUS_EVENT = 8,
        STATUS_RESTART = 16,
        STATUS_FINISH = 32,
        STATUS_TIMER_CONTROL = 256,
        STATUS_WORLD_POS = 512,
        STATUS_NO_RESOURCE = 4096,
        STATUS_MALLOC_ERROR = 8192,
        STATUS_IMPROPER_RESOURCE = 16384,
        STATUS_ERROR = 28672,
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
    uEffect2D();
    virtual ~uEffect2D();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual u64 getSystemUnitGroup() const;  // vtable slot 8
    virtual bool getBoundary(MtSphere* pdst);  // vtable slot 13
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void updateWorldMatrix();  // vtable slot 26
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void setEffectParent(uCoord* pParent);  // vtable slot 28
    virtual bool getSleepMode() const;  // vtable slot 29
    virtual void setSleepMode(bool Mode);  // vtable slot 30
    bool getSchedulerMode() const;
    void setSchedulerMode(bool Mode);
    bool getEventMode() const;
    void setEventMode(bool Mode);
    bool getTimerControlMode() const;
    void setTimerControlMode(bool Mode);
    bool getWorldPosMode() const;
    void setWorldPosMode(bool Mode);
    virtual bool getRestartFlag() const;  // vtable slot 31
    virtual void setRestartFlag(bool Flag);  // vtable slot 32
    const MtFloat2& getScreenPos() const;
    void setScreenPos(const MtFloat2& ScreenPos);
    u32 getLoopFrame() const;
    void setLoopFrame(u32 LoopFrame);
    u32 getLifeFrame() const;
    void setLifeFrame(u32 LifeFrame);
    u32 getWaitFrame() const;
    void setWaitFrame(u32 WaitFrame);
    u32 getTimer() const;
    void setTimer(u32 Timer);
    f32 getDeltaTimeCoef() const;
    void setDeltaTimeCoef(f32 DeltaTimeCoef);
    u32 getKillNo() const;
    void setKillNo(u32 KillNo);
    u32 getDrawPriority() const;
    void setDrawPriority(u32 DrawPriority);
    f32 getAlphaRate() const;
    void setAlphaRate(f32 AlphaRate);
    u32 getEndType() const;
    void setEndType(u32 EndType);
    u32 getSizeAdjustType() const;
    void setSizeAdjustType(u32 SizeAdjustType);
    f32 getEffectScale() const;
    void setEffectScale(f32 EffectScale);
    rEffect2D* getEffect2D();
    void setEffect2D(rEffect2D* pEffect2D);
    u32 getFlagBitNum() const;
    bool getGroupFlagBit(u32 No) const;
    void setGroupFlagBit(bool Flag, u32 No);
    u32 getGroupFlag() const;
    bool getMaterialFlagBit(u32 No) const;
    void setMaterialFlagBit(bool Flag, u32 No);
    u32 getMaterialFlag() const;
    const MtColor& getRTBaseMapColor() const;
    void setRTBaseMapColor(const MtColor&);
    const MtColor& getRTNormalMapColor() const;
    void setRTNormalMapColor(const MtColor&);
    u32 getRTMaskMapAlpha() const;
    void setRTMaskMapAlpha(u32 RTMaskMapAlpha);
    u32 getGeneratorBuffSize() const;
    u32 getGeneratorNum() const;
    u32 getGeneratorMoveNum() const;
    f32 getTimeInterpolationRate() const;
    void setDummyU32(u32);
    void setResourceParam(rEffect2D* pEffect2D, u32 GroupFlag, u32 MaterialFlag);
    void doFinish();
    void doRestart();
    void doClear();
    void doKeepHoldOff();
    u32 getStatus() const;
    u32 getEntryType() const;
    s32 getGeneratorRandomNo(u32 ListNo) const;
    void setGeneratorRandomNo(u32 ListNo, s32 RandomNo);
    bool isColorControlEnable() const;
    MtColor calcBlendColor(const MtColor& Color, const MtColor& OrgColor);
    u32 getColorID() const;
    MT_CTSTR getEffect2DPath() const;
protected:
    u32 calcRand();
    void restart();
    bool finish();
    virtual bool checkRelation();  // vtable slot 33
    bool checkEnd();
    bool initUnitParam();
    virtual bool createGenerator();  // vtable slot 34
    virtual void releaseGenerator();  // vtable slot 35
    bool checkEffectList(u32 ListNo);
    virtual void correctColorIntensity(cParticle2DGenerator* pGenerator, MtColor* pColor, u32 ColorNum, u32* pIntensity, const MtFloat2& Pos);  // vtable slot 36
    virtual void initParticleMoveCustom(cParticle2DGenerator* pGenerator, cParticle2D* pParticle, cParticle2DMoveCustom* pParticleMove, const MtFloat2& Ofs, const MtFloat2& Dir);  // vtable slot 37
    virtual bool moveParticleMoveCustom(cParticle2DGenerator* pGenerator, cParticle2D* pParticle, cParticle2DMoveCustom* pParticleMove);  // vtable slot 38
    void drawScene(cDraw* pDraw);
    virtual bool isSubSceneDraw(cDraw* pDraw) const;  // vtable slot 39
    void drawSubScene(cDraw* pDraw);
    s32 getDrawAlphaRate(cDraw* pDraw) const;
private:
    bool getParticleTotalSize(u32 ListNo, cEffectValueU32& Value);
    static u32 getParticleSize(u32 ParticleType);
    static u32 getParticlePosSize(u32 ParticleType, rEffect2D::E2D_PARTICLE_COMMON* pParticleParam);
    static u32 getParticleLifeSize(u32 LifeType);
    static u32 getParticleMoveSize(u32 MoveType);
    f32 convertAlphaToF32(u32 Alpha);
protected:
    u32 mStatus : 16;  // offset: 0x110
    u32 mDrawPass : 8;  // offset: 0x110
    u32 mLoopNum : 8;  // offset: 0x110
    f32 mBaseFps;  // offset: 0x114
    f32 mDeltaTimeCoef;  // offset: 0x118
    u32 mTimer;  // offset: 0x11c
    f32 mTimeInterpolationRate;  // offset: 0x120
    s32 mIntTimeInterpolationRate;  // offset: 0x124
    u32 mDrawBuffSize;  // offset: 0x128
    u32 mDrawPriority;  // offset: 0x12c
    u32 mLifeTimer : 16;  // offset: 0x130
    u32 mLoopFrame : 16;  // offset: 0x130
    u32 mLifeFrame : 16;  // offset: 0x134
    u32 mWaitFrame : 16;  // offset: 0x134
    u32 mGeneratorNum : 16;  // offset: 0x138
    u32 mGeneratorMoveNum : 16;  // offset: 0x138
    u32 mGeneratorBuffSize;  // offset: 0x13c
    cParticle2DGenerator* mGenerator;  // offset: 0x140
    rEffect2D* mpEffect2D;  // offset: 0x148
    u32 mGroupFlag;  // offset: 0x150
    u32 mMaterialFlag;  // offset: 0x154
    MtFloat2 mScreenPos;  // offset: 0x158
    u32 mKillNo : 16;  // offset: 0x160
    u32 mDrawTargetNum : 4;  // offset: 0x160
    u32 mEndType : 4;  // offset: 0x160
    u32 mSizeAdjustType : 4;  // offset: 0x160
    u32 mCreateFlag : 1;  // offset: 0x160
    u32 mRTFlag : 1;  // offset: 0x160
    u32 mEffect2D024b : 2;  // offset: 0x160
    f32 mEffectScale;  // offset: 0x164
    MtColor mRTBaseMapColor;  // offset: 0x168
    MtColor mRTNormalMapColor;  // offset: 0x16c
    u32 mRTMaskMapAlpha;  // offset: 0x170
    f32 mAlphaRate;  // offset: 0x174
    nDraw::Texture* mpTempTexture[4];  // offset: 0x178
    nDraw::Texture* mpDepthStencil[4];  // offset: 0x198
public:
    static MyDTI DTI;
};
