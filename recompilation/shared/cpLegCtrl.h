#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class cpIKCtrl;
class rLegCtrl;
class uCharacter;
class uCnsLegCtrl;

// Declarations
class cpLegCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpLegCtrl : public cpComponent
{
public:
    enum LEG_IK_QUALITY
    {
        QUALITY_HIGH = 0,
        QUALITY_MIDDLE = 1,
        QUALITY_LOW = 2,
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
    cpLegCtrl();
    virtual ~cpLegCtrl();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setActive(bool active);  // vtable slot 13
    void setResource(rLegCtrl* pRes);
    void setIKCtrl(cpIKCtrl* pIKCtrl);
    void initLegCtrl();
    bool updateLegCtrl();
    void enableConstraint(bool enable);
private:
    void adjustFoot(MtMatrix& wmat, f32& current_diff, f32& ground_rate, bool IsHand);
    void adjustCenter(f32& current_diff, f32 r_diff, f32 l_diff, f32 pitch_diff);
    f32 adjustPitch();
    f32 adjustPitchLight();
    void removeConstraint();
    rLegCtrl* getResource() const;
    LEG_IK_QUALITY calcLegIkQuality() const;
private:
    LEG_IK_QUALITY mQuality;  // offset: 0x50
    f32 mDiff;  // offset: 0x54
    f32 mPitch;  // offset: 0x58
    f32 mRFootDiff;  // offset: 0x5c
    f32 mLFootDiff;  // offset: 0x60
    f32 mRArmDiff;  // offset: 0x64
    f32 mLArmDiff;  // offset: 0x68
    f32 mDiffMax;  // offset: 0x6c
    f32 mDiffMin;  // offset: 0x70
    f32 mCOGMin;  // offset: 0x74
    f32 mFootDiffMax;  // offset: 0x78
    f32 mFootDiffMin;  // offset: 0x7c
    f32 mDiffSpeed;  // offset: 0x80
    f32 mPitchSpeed;  // offset: 0x84
    f32 mFootDiffSpeed;  // offset: 0x88
    f32 mResetDiffSpeed;  // offset: 0x8c
    f32 mResetFootDiffSpeed;  // offset: 0x90
    f32 mHandBlend;  // offset: 0x94
    f32 mHandHeight;  // offset: 0x98
    f32 mHandToe;  // offset: 0x9c
    f32 mHandHeel;  // offset: 0xa0
    f32 mFootBlend;  // offset: 0xa4
    f32 mFootHeight;  // offset: 0xa8
    f32 mFootToe;  // offset: 0xac
    f32 mFootHeel;  // offset: 0xb0
    f32 mCheckHeight;  // offset: 0xb4
    f32 mCheckHeightHand;  // offset: 0xb8
    f32 mEnableRate;  // offset: 0xbc
    u32 mLegType;  // offset: 0xc0
    bool mIsLand;  // offset: 0xc4
    f32 mCheckHeightPitchT;  // offset: 0xc8
    f32 mCheckHeightPitchU;  // offset: 0xcc
    MtMatrix mOrgMat[5];  // offset: 0xd0
    MtMatrix mFinalMat[5];  // offset: 0x210
    f32 mGroundRate[5];  // offset: 0x350
    rLegCtrl* mpResource;  // offset: 0x368
    uCnsLegCtrl* mpCnsLegCtrlCenter;  // offset: 0x370
    uCharacter* mpModel;  // offset: 0x378
    cpIKCtrl* mpIKCtrl;  // offset: 0x380
public:
    static MyDTI DTI;
};
