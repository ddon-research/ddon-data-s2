#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtEaseCurve.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtString.h"
#include "cCamInterporate.h"
#include "nCameraGame.h"
#include "nDDOUtility.h"
#include "sCamera.h"
#include "uCameraBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtHermiteCurve;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;
class cCamExParamNml;
class cCamImpNml;
class cCamInterAll;
class cCamInterporateAng3Time;
class cCamInterporateRange;
class cCamInterporateVec3;
class rCameraParamList;
class sCameraExt;
class uBaseModel;
class uCamera;
class uCoord;
class uDDOModel;
class uDOFFilter;
class uMotionBlurFilter;

// Declarations
class cCamExParam;
class cCamImpBase;
class cCamInterPreset;
namespace nCameraGame { class cTemplateParam; }
class uCameraGame;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using cCamInterporateF32 = cCamInterporate<float>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class cCamInterPreset
{
public:
    enum FRAME_TYPE
    {
        FRAME_NORMAL = 0,
        FRAME_CAMERA_DIST_SPEED = 1,
        FRAME_TARGET_DIST_SPEED = 2,
    };
    enum INTER_TYPE
    {
        INTER_TYPE_PL_LINER = 0,
        INTER_TYPE_PL_ROTATE = 1,
        INTER_TYPE_WORLD_LINER = 2,
        INTER_TYPE_WORLD_ROTATE = 3,
    };
public:
    cCamInterPreset();
    ~cCamInterPreset();
    bool isEnd() const;
    f32 getInterRate() const;
    void end();
    cCamInterPreset& operator=(const cCamInterPreset& r);
    void copy(const cCamInterPreset* pParam);
    void initialize(const MtVector3& cameraPos, const MtVector3& targetPos, f32 roll, f32 fov, const MtVector3& playerPos, const MtHermiteCurve& curve, f32 time, INTER_TYPE type, FRAME_TYPE fType);
    void interporate(MtVector3& cameraPos, MtVector3& targetPos, f32& roll, f32& fov, const MtVector3& playerPos, f32 time);
    void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
private:
    FRAME_TYPE mFType;  // offset: 0x0
    u32 mInitializeCnt;  // offset: 0x4
    f32 mTimer;  // offset: 0x8
    f32 mTimeMax;  // offset: 0xc
    MtVector3 mInitTargetOffset;  // offset: 0x10
    f32 mInitAngX;  // offset: 0x20
    f32 mInitAngY;  // offset: 0x24
    f32 mInitDist;  // offset: 0x28
    f32 mInitFov;  // offset: 0x2c
    f32 mInitRoll;  // offset: 0x30
    MtVector3 mInitCameraPos;  // offset: 0x40
    MtVector3 mInitTargetPos;  // offset: 0x50
    MtHermiteCurve mInterCurve;  // offset: 0x60
    INTER_TYPE mInterType;  // offset: 0xa0
};

namespace nCameraGame {
    class cTemplateParam : public ::MtObject
    {
    public:
        enum UNIT_TYPE
        {
            UNIT_TYPE_NPC = 0,
            UNIT_TYPE_EM = 1,
            UNIT_TYPE_OM = 2,
        };
        enum
        {
            CH_NONE = 0,
            CH_TIME = 1,
            CH_ANIM_END = 2,
            CH_NEXT = 4,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cTemplateParam();
        // Address: 0x0195cf20 - 0x0195cf21 (1 bytes)
        virtual ~cTemplateParam() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        const uCoord* getTempTargetA() const;
        const uCoord* getTempTargetB() const;
    private:
        const uCoord* getTempTarget(UNIT_TYPE type, u32 group, u32 id) const;
    public:
        u32 mIndex;  // offset: 0x8
        u32 mChFlag;  // offset: 0xc
        f32 mFrame;  // offset: 0x10
        nCameraGame::TEMP_TYPE mTargetTypeA;  // offset: 0x14
        MtMatrix mOffsetA;  // offset: 0x20
        UNIT_TYPE mUnitTypeA;  // offset: 0x60
        s32 mTargetJoint_A;  // offset: 0x64
        u32 mTargetGroup_A;  // offset: 0x68
        u32 mTargetID_A;  // offset: 0x6c
        nCameraGame::TEMP_TYPE mTargetTypeB;  // offset: 0x70
        MtMatrix mOffsetB;  // offset: 0x80
        UNIT_TYPE mUnitTypeB;  // offset: 0xc0
        s32 mTargetJoint_B;  // offset: 0xc4
        u32 mTargetGroup_B;  // offset: 0xc8
        u32 mTargetID_B;  // offset: 0xcc
        f32 mAnimSpeed;  // offset: 0xd0
        f32 mAnimStartFrame;  // offset: 0xd4
        f32 mAnimDistScale;  // offset: 0xd8
        bool mIsUseCustomInter;  // offset: 0xdc
        cCamInterPreset::INTER_TYPE mInterType;  // offset: 0xe0
        cCamInterPreset::FRAME_TYPE mInterFrameType;  // offset: 0xe4
        f32 mInterFrame;  // offset: 0xe8
        MtHermiteCurve mInterCurve;  // offset: 0xec
        static MyDTI DTI;
    };
}  // namespace nCameraGame

class uCameraGame : public uCameraBase
{
    // inferred: cCamImpNml::finalSub names uCameraGame::mAngX
    friend class cCamImpNml;
    // inferred: sCameraExt::createParamList names uCameraGame::mIsResetReq
    friend class sCameraExt;
public:
    enum FOV_TYPE
    {
        FOV_V = 0,
        FOV_H = 1,
    };
    enum CHANGE_MODE
    {
        CHANGE_LINER = 0,
        CHANGE_ROT = 1,
    };
    enum
    {
        PRESET_NONE = 0,
        PRESET_0 = 1,
        PRESET_1 = 2,
        PRESET_2 = 3,
        DEF_CAM_NUM = 4,
    };
public:
    class MyDTI;
    struct stReqHistory;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stReqHistory
    {
    public:
        stReqHistory();
    public:
        uintptr thisid;  // offset: 0x0
        f32 frame;  // offset: 0x8
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
    uCameraGame();
    virtual ~uCameraGame();
    virtual void init();  // vtable slot 27
    virtual void update(const f32 deltaTime, const f32 deltaSec);  // vtable slot 28
    virtual void updatePtr();  // vtable slot 17
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void kill();  // vtable slot 16
    uCameraGame& operator=(const uCameraGame&);
    void copy(const uCameraGame* pParam);
    const cCamImpBase* getCamImp() const;
    bool isStageCamera(u32 no) const;
    bool isCmnCamera(u32 no) const;
    bool isEventCamera(u32 no) const;
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual MtMatrix getViewMat();  // vtable slot 25
    virtual MtMatrix getProjMat();  // vtable slot 26
    bool requestExCamera(const cCamExParam* pParam, const uDDOModel* pResourceOwner, const uDDOModel* pOwner, bool isForceSet);
    bool canChangeExCamera(const cCamExParam* pParam, const uDDOModel* pOwner) const;
    void setInter(f32 frame, CHANGE_MODE mode, f32 startSpring);
    void setInter(uCamera* pCamera, f32 frame, CHANGE_MODE mode, f32 startSpring);
    bool isInter() const;
    f32 getInterRate() const;
    void setInterporate(const MtHermiteCurve& curve, f32 frame, cCamInterPreset::INTER_TYPE type, cCamInterPreset::FRAME_TYPE fType);
    void endInterporate();
    bool isActEnd() const;
    bool isAnmEnd() const;
    s32 getCut() const;
    void requestReset();
    void setNoCtrl();
    void forceAdjust();
    void addPhotoFov(f32 fov);
    void addPhotoOffsetX(f32 offsetX);
    void addPhotoHeight(f32 height);
    f32 getPhotoFov() const;
    f32 getPhotoOffsetX() const;
    f32 getPhotoHeight() const;
    void resetPhotoParam();
    bool finalPhotoMode();
    void setCamLength(f32 len);
    f32 getCamLength() const;
    void setPushVec(const MtVector3& vec);
    MtVector3 getPushVec() const;
    bool isUseOldAdjustFlag() const;
    u32 getOldAdjustFlag() const;
    s32 getOldAdjustType() const;
    f32 getOldAdjustHeight() const;
    void initDOFFilterParam();
    void setDOFFilterParam(f32 Near, f32 NearBlurLimit);
    void setDOFFilterNear(f32 val);
    void setDOFFilterNearBlurLimit(f32 nearBlurLimit);
    void setDOFFilterFarBlurLimit(f32 farBlurLimit);
    void setDOFFilterFar(f32 val);
    void setDOFFilterFocal(f32 focal);
    void setDOFFilterGradateColor(const MtVector3& col);
    void resetDOFFilterParam();
    void createMotionBlurFilter();
    void killMotionBlurFilter();
    const cCamExParam* getCamExParam() const;
protected:
    void resetPos();
public:
    void setCameraPreset(s32 no);
    void camCtrl(bool isRStick);
    void initInterParam(f32 camSpring, f32 tarSpring);
    void initInterSpring(f32 camSpring, f32 tarSpring);
    void exeInterporate();
    void behindPlayer(f32& angX, f32& angY);
    void lookTarget(f32& angX, f32& angY);
    void dodgeScroll();
    f32 getCameraWorkRate() const;
    nCameraGame::CAMERA_TYPE getCamType() const;
    void setCamType(u32);
    nCameraGame::TARGET_TYPE getCameraTargetType() const;
    u32 getPresetNo() const;
    const uDDOModel* getCameraReqOwner() const;
    const MtVector3& getCameraPosOld() const;
    const MtVector3& getTargetPosOld() const;
    const MtVector3& getIdealPosCam() const;
    const MtVector3& getIdealPosTar() const;
    const MtVector3& getIdealPosCamOld() const;
    const MtVector3& getIdealPosTarOld() const;
    f32 getRotationSpeed() const;
    f32 getAngX() const;
    void setAngX(f32 ang);
    f32 getAngY() const;
    void setAngY(f32 ang);
    bool isCtrlX() const;
    bool isCtrlY() const;
    f32 getCtrlXValue() const;
    f32 getCtrlYValue() const;
    void setMovCam();
    bool isMovCam() const;
    bool isCancelCamRevise() const;
    void setCancelCamRevise(bool flag);
    bool isAngInterEnd();
    bool isPresetInterEnd();
    void setRotSpeedSclX(f32 x);
    void setRotSpeedSclY(f32 y);
    f32 getRotSpeedSclX() const;
    f32 getRotSpeedSclY() const;
    bool isCtrlRevX() const;
    bool isCtrlRevY() const;
    f32 getObjPushDist() const;
    nCameraGame::CAMERA_TYPE getOldCameraType() const;
    void setOldCameraType(nCameraGame::CAMERA_TYPE type);
    bool isPlTarCamOldCamera() const;
    void setIsPlTarCamOldCamera(bool b);
    void setTemplateParam(const nCameraGame::cTemplateParam* pParam);
    const nCameraGame::cTemplateParam* getTemplateParam();
    void lookAtTarget(const MtVector3& pos, f32 offsetH, f32 offsetV, f32 marginH, f32 marginV);
    void setSleep(bool);
    bool isSleep();
    void setFallinstantdeathOld(bool flag);
    bool isFallinstantdeathOld();
    void setInvalidPresetInter();
private:
    void callbackCameraImpFinal(cCamImpBase* pImp);
    void updateChangeCamera();
private:
    nDDOUtility::cArray<stReqHistory, 20> mReqHistory;  // offset: 0xa90
    sCamera::VIEWPORT_NO mViewportNo;  // offset: 0xbd0
    const uDDOModel* mpCameraReqOwner;  // offset: 0xbd8
    cCamImpBase* mpImple;  // offset: 0xbe0
    cCamImpNml* mpImpNml;  // offset: 0xbe8
    cCamExParamNml* mpParamNml;  // offset: 0xbf0
    const cCamExParam* mpRequestParam;  // offset: 0xbf8
    const uDDOModel* mpRequestOwner;  // offset: 0xc00
    const uDDOModel* mpRequestResourceOwner;  // offset: 0xc08
    cCamImpBase* mpImpEx;  // offset: 0xc10
    nCameraGame::CAMERA_TYPE mOldCameraType;  // offset: 0xc18
    bool mIsPlTarCamOldCamera;  // offset: 0xc1c
    s32 mId;  // offset: 0xc20
    u32 mPresetNo;  // offset: 0xc24
    FOV_TYPE mFovType;  // offset: 0xc28
    MtVector3 mCameraPosOld;  // offset: 0xc30
    MtVector3 mTargetPosOld;  // offset: 0xc40
    f32 mAngX;  // offset: 0xc50
    f32 mAngY;  // offset: 0xc54
    MtVector3 mMargin;  // offset: 0xc60
    bool mIsRevX;  // offset: 0xc70
    bool mIsRevY;  // offset: 0xc71
    f32 mRotSpeed;  // offset: 0xc74
    f32 mRotSpeedSclX;  // offset: 0xc78
    f32 mRotSpeedSclY;  // offset: 0xc7c
    bool mIsCtrlX;  // offset: 0xc80
    bool mIsCtrlY;  // offset: 0xc81
    bool mIsMoveCam;  // offset: 0xc82
    f32 mCtrlXValue;  // offset: 0xc84
    f32 mCtrlYValue;  // offset: 0xc88
    bool mIsFallinstantdeathOld;  // offset: 0xc8c
    bool mIsCancelCamRevise;  // offset: 0xc8d
    MtVector3 mIdealPosCam;  // offset: 0xc90
    MtVector3 mIdealPosTar;  // offset: 0xca0
    MtVector3 mIdealPosCamOld;  // offset: 0xcb0
    MtVector3 mIdealPosTarOld;  // offset: 0xcc0
    cCamInterporateVec3 mPushVecInter;  // offset: 0xcd0
    CHANGE_MODE mChMode;  // offset: 0xd10
    cCamInterAll mChInter;  // offset: 0xd20
    cCamInterPreset mInterPreset;  // offset: 0xe60
    cCamInterporateAng3Time mInterAng;  // offset: 0xf10
    f32 mResetAngX;  // offset: 0xf70
    f32 mResetAngY;  // offset: 0xf74
    cCamInterporateAng3Time mInterCamAng;  // offset: 0xf80
    cCamInterporateF32 mInterCamDist;  // offset: 0xfe0
    cCamInterporateRange mInterRange;  // offset: 0x1000
    MtVector3 mLastPlPos;  // offset: 0x1040
    bool mIsNoCtrlReq;  // offset: 0x1050
    bool mIsResetReq;  // offset: 0x1051
    bool mIsUseOldAdjustFlag;  // offset: 0x1052
    u32 mOldAdjustFlag;  // offset: 0x1054
    s32 mOldAdjustType;  // offset: 0x1058
    f32 mOldAdjustHeight;  // offset: 0x105c
    f32 mCamLength;  // offset: 0x1060
    cCamInterporateF32 mObjPushDistInter;  // offset: 0x1068
    const nCameraGame::cTemplateParam* mpTemplateParam;  // offset: 0x1080
    bool mInvalidPresetInter;  // offset: 0x1088
    bool mbSleep;  // offset: 0x1089
    uDOFFilter* mpDOFFilter;  // offset: 0x1090
    f32 mDOFFiltterNearBlurLimit;  // offset: 0x1098
    f32 mDOFFiltterFarBlurLimit;  // offset: 0x109c
    f32 mDOFFiltterNear;  // offset: 0x10a0
    f32 mDOFFiltterFar;  // offset: 0x10a4
    f32 mDOFFiltterFocal;  // offset: 0x10a8
    MtVector3 mDOFFiltterGradateColor;  // offset: 0x10b0
    uMotionBlurFilter* mpMotionBlurFilter;  // offset: 0x10c0
    f32 mPhotoAddFov;  // offset: 0x10c8
    f32 mPhotoAddOffsetX;  // offset: 0x10cc
    f32 mPhotoAddHeight;  // offset: 0x10d0
    f32 mChangeCameraTimer;  // offset: 0x10d4
    u8 mStatusChangeCamera;  // offset: 0x10d8
public:
    static MyDTI DTI;
private:
    static const u32 REQ_HISTORY_NUM = 20;
    static const u32 REQ_HISTORY_NO_GROUP = 5;
};

class cCamExParam : public MtObject
{
public:
    enum SCR_ADJST_TYPE
    {
        SCR_ADJUST_NORMAL = 0,
        SCR_ADJUST_T2C = 1,
        SCR_ADJUST_CAUGHT = 2,
    };
    enum KEEP_ANGLE_TYPE
    {
        KEEP_ANGLE_NOW_CAM = 0,
        KEEP_ANGLE_PL2LOOK = 1,
        KEEP_ANGLE_PL2POS = 2,
        KEEP_ANGLE_RESET = 3,
        KEEP_ANGLE_RESET_X = 4,
    };
    enum
    {
        SYS_NONE = 0,
        SYS_OWNER_WORK_RATE = 2,
        SYS_RELATION_POS = 4,
        SYS_NO_ADJUST_END_INTER = 16,
        SYS_USE_JOINT_OFFSET = 128,
    };
    enum
    {
        CONDITION_PL_DIST = 1,
        CONDITION_PL_RAY = 2,
        CONDITION_CAM_DIST = 4,
        CONDITION_CAM_RAY = 8,
    };
    enum
    {
        DOF_NEAR_BLUR_LIMIT = 1,
        DOF_NEAR = 2,
        DOF_FAR = 4,
        DOF_FOCAL = 8,
        DOF_GRADATE_COLOR = 16,
        DOF_FAR_BLUR_LIMIT = 32,
    };
    enum
    {
        SCR_ADJUST_NML = 1,
        SCR_ADJUST_EX_0 = 2,
        SCR_ADJUST_HEIGHT_TAR = 4,
        SCR_ADJUST_WATER = 8,
    };
    enum
    {
        CO_NONE = 0,
        CO_CANT_CTRL = 1,
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void createPropertyCommon(MtPropertyList& s);
    void createPropertyCameraTarget(MtPropertyList& s);
    void createPropertyCoord(MtPropertyList& s);
    void createPropertyInterporate(MtPropertyList& s);
    void createPropertyCtrl(MtPropertyList& s);
    void createPropertyChangeInterporate(MtPropertyList& s);
    void createPropertyAdjust(MtPropertyList& s);
    void createPropertyEx(MtPropertyList& s);
    cCamExParam();
    virtual ~cCamExParam();
    virtual cCamImpBase* createCamImpInstance(uCameraGame*) const = 0;  // vtable slot 6
    virtual cCamExParam* createParamInstanceFromType();  // vtable slot 7
    cCamExParam& operator=(const cCamExParam&);
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
public:
    nCameraGame::CAMERA_TYPE mType;  // offset: 0x8
    MtString mComment;  // offset: 0x10
    u16 mRelVer;  // offset: 0x18
    s32 mPriority;  // offset: 0x1c
    u32 mConditionFlag;  // offset: 0x20
    f32 mConditionPlDist;  // offset: 0x24
    f32 mConditionCamDist;  // offset: 0x28
    s32 mQuakeNo;  // offset: 0x2c
    bool mIsWaitCameraEnd;  // offset: 0x30
    f32 mEnableFrame;  // offset: 0x34
    f32 mCantReqFrame;  // offset: 0x38
    s32 mRequestGroup;  // offset: 0x3c
    u32 mCantReqGroupBit;  // offset: 0x40
    f32 mCangReqFrameGroup;  // offset: 0x44
    nCameraGame::TARGET_TYPE mCameraTarget;  // offset: 0x48
    u32 mGroup;  // offset: 0x4c
    u32 mId;  // offset: 0x50
    s32 mTargetJoint;  // offset: 0x54
    f32 mDistance;  // offset: 0x58
    f32 mHeight;  // offset: 0x5c
    f32 mOffsetX;  // offset: 0x60
    f32 mOffsetZ;  // offset: 0x64
    f32 mFov;  // offset: 0x68
    f32 mRoll;  // offset: 0x6c
    u32 mCtrlOption;  // offset: 0x70
    f32 mAngLimitXMin;  // offset: 0x74
    f32 mAngLimitXMax;  // offset: 0x78
    MtHermiteCurve mCtrlCurve;  // offset: 0x7c
    f32 mInterCamRate;  // offset: 0xbc
    MtVector3 mMargin;  // offset: 0xc0
    f32 mMarginAdjPow;  // offset: 0xd0
    cCamInterPreset::INTER_TYPE mStartInterType;  // offset: 0xd4
    cCamInterPreset::FRAME_TYPE mStartFrameType;  // offset: 0xd8
    f32 mStartInterFrame;  // offset: 0xdc
    MtHermiteCurve mStartInterCurve;  // offset: 0xe0
    cCamInterPreset::INTER_TYPE mEndInterType;  // offset: 0x120
    cCamInterPreset::FRAME_TYPE mEndFrameType;  // offset: 0x124
    MtHermiteCurve mEndInterCurve;  // offset: 0x128
    f32 mEndInterFrame;  // offset: 0x168
    u32 mDofFilterFlag;  // offset: 0x16c
    f32 mDOFFilterNearBlurLimit;  // offset: 0x170
    f32 mDOFFilterFarBlurLimit;  // offset: 0x174
    f32 mDOFFilterNear;  // offset: 0x178
    f32 mDOFFilterFar;  // offset: 0x17c
    f32 mDOFFilterFocal;  // offset: 0x180
    MtVector3 mDOFFilterGradateColor;  // offset: 0x190
    rCameraParamList* mprCameraParamList;  // offset: 0x1a0
    u32 mCameraParamListIndex;  // offset: 0x1a8
    SCR_ADJST_TYPE mScrAdjustType;  // offset: 0x1ac
    u32 mScrAdjustFlag;  // offset: 0x1b0
    f32 mScrAdjustHeight;  // offset: 0x1b4
    bool mIsKeepAngle;  // offset: 0x1b8
    KEEP_ANGLE_TYPE mKeepAngleType;  // offset: 0x1bc
    MtVector3 mKeepTargetPos;  // offset: 0x1c0
    u32 mSysFlag;  // offset: 0x1d0
    static MyDTI DTI;
};

class cCamImpBase : public MtObject
{
    // inferred: cCamImpNml::finalSub names cCamImpBase::mIsKeepAngle
    friend class cCamImpNml;
    // inferred: uCameraGame::isStageCamera names cCamImpBase::mpParam
    friend class uCameraGame;
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
    cCamImpBase();
    virtual ~cCamImpBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x0195cf00 - 0x0195cf01 (1 bytes)
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 6
    void setParam(const cCamExParam* pParam);
    const cCamExParam* getParam() const;
    virtual nCameraGame::CAMERA_TYPE getType() const = 0;  // vtable slot 7
    void setUp(uCameraGame* pCam);
    void init(const uDDOModel* pOwner, MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY, bool isInterporate);
    void ctrl(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);
    void move(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);
    void interporate(MtVector3& cameraPos, MtVector3& targetPos);
    void adjust(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);
    void final(bool isInterporate);
    void setEndInterporate(const cCamExParam* pParam);
    const uDDOModel* getOwner();
    void updatePtr();
    bool isActEnd() const;
    bool isAnmEnd() const;
    bool canFinish() const;
    bool isEndWithAnm() const;
    u32 getPriority() const;
    u32 getScrAdjustFlag() const;
    s32 getScrAdjustType() const;
    f32 getScrAdjustHeight() const;
    u32 getSysFlag() const;
    const uCoord* getCameraTarget() const;
    MtVector3 getCameraTargetPos() const;
    static const uBaseModel* getCameraTarget(const uCameraGame* pCam, const cCamExParam* pParam, nCameraGame::TARGET_TYPE type, u32 group, u32 id);
    static void calcTargetPos(uCameraGame* pCam, nCameraGame::TARGET_TYPE targetType, MtVector3& pos, const MtVector3& ofs, s32 joint, u32 group, u32 id, u32 sysFlag);
    virtual f32 adjustAddPlayerHeight(f32 addHeight);  // vtable slot 8
    f32 adjustAddPlayerDistance(f32 addHeight);
    s32 getCut() const;
protected:
    void cameraCtrl(bool isRStick);
    void initInterParam(f32 camSpring, f32 tarSpring);
    void initInterSpring(f32 camSpring, f32 tarSpring);
    void dodgeScroll();
    bool isWallAdjust() const;
    bool isKeepAngle() const;
    f32 getCameraWorkRate() const;
    bool checkCameraReset() const;
private:
    virtual void initSub(MtVector3&, MtVector3&, f32&, f32&) = 0;  // vtable slot 9
    virtual void ctrlSub(MtVector3&, MtVector3&, f32&, f32&) = 0;  // vtable slot 10
    virtual void moveSub(MtVector3&, MtVector3&, f32&, f32&) = 0;  // vtable slot 11
    virtual void interporateSub(MtVector3&, MtVector3&) = 0;  // vtable slot 12
    virtual void adjustSub(MtVector3&, MtVector3&, MtVector3&, MtVector3&) = 0;  // vtable slot 13
    virtual void finalSub() = 0;  // vtable slot 14
protected:
    uCameraGame* mpC;  // offset: 0x8
    const uDDOModel* mpOwner;  // offset: 0x10
    bool mIsActEnd;  // offset: 0x18
    bool mIsFinal;  // offset: 0x19
    bool mIsInterporate;  // offset: 0x1a
    bool mIsEndWithAnm;  // offset: 0x1b
private:
    const cCamExParam* mpParam;  // offset: 0x20
    bool mIsFinalEnd;  // offset: 0x28
    f32 mCameraFrame;  // offset: 0x2c
    bool mIsWallAdjust;  // offset: 0x30
    s32 mAdjustCnt;  // offset: 0x34
    u32 mPriority;  // offset: 0x38
    f32 mEndInterFrame;  // offset: 0x3c
    cCamInterPreset::INTER_TYPE mEndInterType;  // offset: 0x40
    cCamInterPreset::FRAME_TYPE mEndFrameType;  // offset: 0x44
    MtHermiteCurve mEndInterCurve;  // offset: 0x48
    s32 mQuakeNo;  // offset: 0x88
    u32 mSysFlag;  // offset: 0x8c
    u32 mDofFilterFlag;  // offset: 0x90
    s32 mScrAdjustType;  // offset: 0x94
    u32 mScrAdjustFlag;  // offset: 0x98
    f32 mScrAdjustHeight;  // offset: 0x9c
    bool mIsKeepAngle;  // offset: 0xa0
    u32 mKeepAngleType;  // offset: 0xa4
    nCameraGame::TARGET_TYPE mCameraTarget;  // offset: 0xa8
protected:
    s32 mCut;  // offset: 0xac
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline const cCamExParam* cCamImpBase::getParam() const {
    return this->mpParam;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cCamImpBase::isAnmEnd() const {
    return this->mIsFinal;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 cCamImpBase::getCut() const {
    return this->mCut;
}
