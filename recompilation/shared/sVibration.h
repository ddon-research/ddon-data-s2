#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cParticleManager;
class rVibration;
class uCamera;
class uCoord;

// Declarations
class sVibration;

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

class sVibration : public cSystem
{
    // inferred: cParticleManager::~cParticleManager names sVibration::mpInstance
    friend class cParticleManager;
public:
    enum VIB_REQ_TYPE
    {
        VIB_REQ_TYPE_DEFAULT = 0,
        VIB_REQ_TYPE_POS = 1,
        VIB_REQ_TYPE_UNIT = 2,
    };
    enum FADE_TYPE
    {
        FADE_TYPE_NONE = 0,
        FADE_TYPE_VIEWPORT = 1,
        FADE_TYPE_POS = 2,
        FADE_TYPE_UNIT = 3,
    };
public:
    class MyDTI;
    class VibControl;
    class VibFlag;
    class PadVibration;
    class CameraVibration;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class VibControl
    {
    public:
        enum VIB_RNO
        {
            VIB_RNO_WAIT = 0,
            VIB_RNO_MOVE = 1,
            VIB_RNO_KILL = 2,
        };
        enum ENABLE_FLAG
        {
            ENABLE_FLAG_PADVIB = 1,
            ENABLE_FLAG_CAMVIB = 2,
        };
    public:
        VibControl();
        virtual ~VibControl();
        void start(rVibration* pVibration, u32 ListNo, u32 Priority, sVibration::VibFlag Flag, u32 VibrationId);
        void kill();
        void finish(f32 Time);
        bool move(u32 DeltaTime);
        bool isEnable() const;
        bool isPadVibEnable() const;
        bool isCamVibEnable() const;
        u32 getPriority() const;
        u32 getPadVibPriority() const;
        u32 getCamVibPriority() const;
        u32 getVibrationId() const;
        u32 getPadVibFlag() const;
        u32 getCamVibFlag() const;
        s32 setFadeParam(const MtVector3& VibPos);
        s32 setFadeParam(uCoord* pVibUnit, s32 VibUnitParentNo);
        s32 setFadeParam(const MtVector3& ViewPos, const MtVector3& VibPos);
        s32 setFadeParam(const MtVector3& ViewPos, uCoord* pVibUnit, s32 VibUnitParentNo);
        s32 setFadeParam(uCoord* pViewUnit, s32 ViewUnitParentNo, const MtVector3& VibPos);
        s32 setFadeParam(uCoord* pViewUnit, s32 ViewUnitParentNo, uCoord* pVibUnit, s32 VibUnitParentNo);
        f32 getPadHighVibRate(u32 No) const;
        f32 getPadLowVibRate(u32 No) const;
        MtVector3 getCamVibVec(u32 No) const;
        MtVector3 getCamVibTargetVec(u32 No) const;
    private:
        void movePadVibSingle(f32 Rate);
        void moveCamVibSingle(f32 Rate);
        void updateFadeParam();
        MtVector3 getViewportPos(u32 No) const;
    private:
        rVibration* mpVibration;  // offset: 0x8
        u32 mListNo;  // offset: 0x10
        u32 mPriority;  // offset: 0x14
        u32 mVibrationId;  // offset: 0x18
        u32 mPadVibFlag : 8;  // offset: 0x1c
        u32 mCamVibFlag : 8;  // offset: 0x1c
        u32 mEnableFlag : 8;  // offset: 0x1c
        u32 mViewFadeType : 4;  // offset: 0x1c
        u32 mVibFadeType : 4;  // offset: 0x1c
        u32 mVibTimer;  // offset: 0x20
        u32 mFinishTime : 16;  // offset: 0x24
        u32 mFinishTimer : 16;  // offset: 0x24
        u32 mPadHighVibRno : 4;  // offset: 0x28
        u32 mPadLowVibRno : 4;  // offset: 0x28
        u32 mCamVibRno : 4;  // offset: 0x28
        u32 mFinishRno : 4;  // offset: 0x28
        u32 mVibControl161e : 16;  // offset: 0x28
        f32 mPadVibFadeRate[4];  // offset: 0x2c
        f32 mCamVibFadeRate[8];  // offset: 0x3c
        f32 mPadHighVibRate;  // offset: 0x5c
        f32 mPadLowVibRate;  // offset: 0x60
        f32 mCamVibTargetScale;  // offset: 0x64
        u32 mVibControl325c;  // offset: 0x68
        MtVector3 mCamVibVec;  // offset: 0x70
        MtVector3 mViewPos;  // offset: 0x80
        MtVector3 mVibPos;  // offset: 0x90
        uCoord* mpViewUnit;  // offset: 0xa0
        s32 mViewUnitParentNo;  // offset: 0xa8
        uCoord* mpVibUnit;  // offset: 0xb0
        s32 mVibUnitParentNo;  // offset: 0xb8
    };
public:
    class VibFlag
    {
    public:
        VibFlag();
        VibFlag(u32 Pad1P, u32 Pad2P, u32 Pad3P, u32 Pad4P);
        VibFlag(u32 Pad1P, u32 Pad2P, u32 Pad3P, u32 Pad4P, u32 View0, u32 View1, u32 View2, u32 View3, u32 View4, u32 View5, u32 View6, u32 View7);
        VibFlag(u32 PadFlag, u32 ViewFlag);
        virtual ~VibFlag();
        u32 getPadVibFlag() const;
        u32 getCamVibFlag() const;
        void setPadVibFlag(u32, u32, u32, u32);
        void setCamVibFlag(u32, u32, u32, u32, u32, u32, u32, u32);
    private:
        u32 mFlag;  // offset: 0x8
    public:
        static const sVibration::VibFlag Pad1;
        static const sVibration::VibFlag Pad2;
        static const sVibration::VibFlag Pad3;
        static const sVibration::VibFlag Pad4;
        static const sVibration::VibFlag All;
    };
public:
    class PadVibration
    {
    public:
        PadVibration();
        virtual ~PadVibration();
        void clear();
        void update(sVibration::VibControl* pVibControl, u32 No);
        bool isEnable() const;
        f32 getHighVibRate() const;
        f32 getLowVibRate() const;
    private:
        bool mEnableFlag;  // offset: 0x8
        f32 mHighVibRate;  // offset: 0xc
        f32 mLowVibRate;  // offset: 0x10
    };
public:
    class CameraVibration
    {
    public:
        CameraVibration();
        virtual ~CameraVibration();
        void clear();
        void update(sVibration::VibControl* pVibControl, u32 No);
        bool isEnable() const;
        MtVector3 getVibVec() const;
        MtVector3 getVibTargetVec() const;
    private:
        MtVector3 mVibVec;  // offset: 0x10
        MtVector3 mVibTargetVec;  // offset: 0x20
        bool mEnableFlag;  // offset: 0x30
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
    sVibration();
    virtual ~sVibration();
    static sVibration* getInstance();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    rVibration* getVibration();
    void setVibration(rVibration* pVibration);
    u32 getPadVibrationNum() const;
    u32 getCameraVibrationNum() const;
    void setDummyU32(u32);
    s32 reqVib(u32 ListNo, u32 Priority, VibFlag Flag, rVibration* pExtVibration);
    s32 reqVib(u32 ListNo, u32 Priority, const MtVector3& VibPos, VibFlag Flag, rVibration* pExtVibration);
    s32 reqVib(u32 ListNo, u32 Priority, uCoord* pVibUnit, s32 VibUnitParentNo, VibFlag Flag, rVibration* pExtVibration);
    s32 reqVib(u32 ListNo, u32 Priority, const MtVector3& ViewPos, const MtVector3& VibPos, VibFlag Flag, rVibration* pExtVibration);
    s32 reqVib(u32 ListNo, u32 Priority, const MtVector3& ViewPos, uCoord* pVibUnit, s32 VibUnitParentNo, VibFlag Flag, rVibration* pExtVibration);
    s32 reqVib(u32 ListNo, u32 Priority, uCoord* pViewUnit, s32 ViewUnitParentNo, const MtVector3& VibPos, VibFlag Flag, rVibration* pExtVibration);
    s32 reqVib(u32 ListNo, u32 Priority, uCoord* pViewUnit, s32 ViewUnitParentNo, uCoord* pVibUnit, s32 VibUnitParentNo, VibFlag Flag, rVibration* pExtVibration);
    void finishVib(s32 Id, f32 Time);
    void finishVibAll(f32 Time);
    void stopVib(s32 Id);
    void stopVibAll();
    bool isPadVibration(u32 PadNo) const;
    u32 getPadHighVibration(u32 PadNo, u32 VibValue) const;
    u32 getPadLowVibration(u32 PadNo, u32 VibValue) const;
    bool isCameraVibration(u32 ViewportNo) const;
    virtual MtMatrix getCameraVibrationViewMatrix(u32 ViewportNo, uCamera* pCamera) const;  // vtable slot 10
    MtVector3 getCameraVibVec(u32 ViewportNo) const;
    MtVector3 getCameraTargetVibVec(u32 ViewportNo) const;
    u32 getPadViewportNo(u32 No) const;
    void setPadViewportNo(u32 ViewportNo, u32 No);
    u32 getPadNum() const;
    virtual u32 getDefaultVibPad() const;  // vtable slot 11
    virtual u32 getDefaultVibCamera() const;  // vtable slot 12
    void doRequest();
    void doFinish();
    bool isPadVibrationEnable() const;
    void setPadVibrationEnable(bool Flag);
    bool isCameraVibrationEnable() const;
    void setCameraVibrationEnable(bool Flag);
protected:
    virtual u64 getTimer() const;  // vtable slot 13
    void initVibRequestParam();
private:
    VibControl* openVibControl(u32 ListNo, u32 Priority, VibFlag Flag, rVibration* pExtVibration);
    void clearVibParam();
protected:
    u32 mPadViewportNo[4];  // offset: 0x14
    u32 mVibReqType;  // offset: 0x24
    u32 mVibPad;  // offset: 0x28
    u32 mVibCamera;  // offset: 0x2c
    u32 mVibListNo;  // offset: 0x30
    u32 mVibPriority;  // offset: 0x34
    MtVector3 mVibPos;  // offset: 0x40
    uCoord* mpVibUnit;  // offset: 0x50
    s32 mVibUnitParentNo;  // offset: 0x58
    f32 mVibFinishTime;  // offset: 0x5c
    bool mPadVibrationEnable;  // offset: 0x60
    bool mCameraVibrationEnable;  // offset: 0x61
private:
    rVibration* mpVibration;  // offset: 0x68
    u32 mVibrationId;  // offset: 0x70
    VibControl mVibControl[8];  // offset: 0x80
    u64 mPrevTimer;  // offset: 0x680
    u32 mDeltaTime;  // offset: 0x688
    f32 mDeltaTimeScale;  // offset: 0x68c
    PadVibration mPadVibration[4];  // offset: 0x690
    CameraVibration mCameraVibration[8];  // offset: 0x6f0
public:
    static const u32 PAD_VIB_NUM = 4;
    static const u32 CAM_VIB_NUM = 8;
    static const u32 HIGHEST_PRIORITY = 4294967295;
    static const u32 LOWEST_PRIORITY = 0;
    static MyDTI DTI;
protected:
    static sVibration* mpInstance;
private:
    static const u32 VIB_CONTROL_NUM = 8;
};

// Inline, no code of its own: checked where it is inlined.
inline sVibration* sVibration::getInstance() {
    return ::sVibration::mpInstance;
}
