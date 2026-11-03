#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../generated/shared/nCameraGame.h"
#include "uCameraGame.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtHermiteCurve;
class MtObject;
class MtPropertyList;
class MtVector3;
class cCamExParam;
class cCamImpBase;
class uCameraGame;

// Declarations
class cCamExParamTps;
class cCamExParamTps2;
class cCamImpTps;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cCamExParamTps : public cCamExParam
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamExParamTps();
    virtual ~cCamExParamTps();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
public:
    bool mIsResetAngle;  // offset: 0x1d4
    bool mIsResetAngleDetail;  // offset: 0x1d5
    bool mEnableLargeCorrect;  // offset: 0x1d6
    f32 mResetDetailAngX;  // offset: 0x1d8
    f32 mResetDetailAngY;  // offset: 0x1dc
    f32 ctrlSpeed;  // offset: 0x1e0
    bool isUseLimit;  // offset: 0x1e4
    f32 limitDeg;  // offset: 0x1e8
    bool isFollowAngle;  // offset: 0x1ec
    bool isNoHeightCorrect;  // offset: 0x1ed
    static MyDTI DTI;
};

class cCamExParamTps2 : public cCamExParamTps
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamExParamTps2();
    virtual ~cCamExParamTps2();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
public:
    static MyDTI DTI;
};

class cCamImpTps : public cCamImpBase
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
    cCamImpTps();
    virtual ~cCamImpTps();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    void recoilMove(f32& ang, f32& value, bool& isMove, f32& scale, f32& frame, f32 frameMax);
    f32 getDistance();
protected:
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
protected:
    const cCamExParamTps* mpParamTps;  // offset: 0xb0
    bool mIsResetAngle;  // offset: 0xb8
    bool mIsResetAngleDetail;  // offset: 0xb9
    f32 mResetDetailAngX;  // offset: 0xbc
    f32 mResetDetailAngY;  // offset: 0xc0
    f32 mMaxSpeedFrameX;  // offset: 0xc4
    f32 mMaxSpeedFrameY;  // offset: 0xc8
    bool mIsRecoilMoveX;  // offset: 0xcc
    f32 mRecoilScaleX;  // offset: 0xd0
    f32 mRecoilFrameX;  // offset: 0xd4
    f32 mRecoilFrameMaxX;  // offset: 0xd8
    bool mIsRecoilMoveY;  // offset: 0xdc
    f32 mRecoilScaleY;  // offset: 0xe0
    f32 mRecoilFrameY;  // offset: 0xe4
    f32 mRecoilFrameMaxY;  // offset: 0xe8
    f32 mRecoilValueX;  // offset: 0xec
    f32 mRecoilValueY;  // offset: 0xf0
    f32 mInitAngY;  // offset: 0xf4
    f32 mResetAngX;  // offset: 0xf8
    f32 mResetAngY;  // offset: 0xfc
    bool mFirstInter;  // offset: 0x100
    bool mIsLargeCamera;  // offset: 0x101
public:
    static MyDTI DTI;
private:
    static const f32 mBaseRotSpeedScale;
    static const f32 maxSpeedScaleX;
    static const f32 maxSpeedFrameX;
    static const MtHermiteCurve maxSpeedCurveX;
    static const f32 maxSpeedScaleY;
    static const f32 maxSpeedFrameY;
    static const MtHermiteCurve maxSpeedCurveY;
};

inline void* cCamExParamTps::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCamExParamTps2::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCamImpTps::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
