#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtEaseCurve.h"
#include "nDDOUtility.h"
#include "sCamera.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtHermiteCurve;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtUI;
class MtVector3;
class cCamExParam;
class rCameraParamList;
class rCameraQuakeList;
class rLargeCameraParam;
class uCamera;
class uCameraGame;
class uDDOModel;
class uFreeCamera;

// Declarations
class sCameraExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sCameraExt : public sCamera
{
public:
    enum FREE_CAMERA_TYPE
    {
        FREE_CAMERA_DEFAULT = 0,
        FREE_CAMERA_GAME = 1,
    };
    enum GAME_CAMERA_FLAG
    {
        GCF_NEXT = 0,
        GCF_CANCEL = 1,
        GCF_PAUSE = 2,
        GCF_NO_CTRL_UI = 3,
        GCF_NO_CTRL_EDIT = 4,
        GCF_NUM = 5,
    };
    enum
    {
        CAM_CMN_ACT_PHOTO_MODE = 120,
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
    sCameraExt();
    virtual ~sCameraExt();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    virtual void clear();  // vtable slot 11
    void init();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    uFreeCamera* createFreeCamera();
    void initGameViewport();
    void updateGameViewport();
    MtRect getGameScreenRect();
    void setGameCamera(u32 id);
    void setMotionCamera(uCamera* pCam);
    uCamera* getMotionCamera();
    void cancelMotionCamera(f32 interFrame);
    uFreeCamera* setGameFreeCamera(FREE_CAMERA_TYPE type);
    void cancelGameFreeCamera();
    void setOutsideCamera(uCamera* pCam);
    void cancelOutsideCamera(f32 interFrame);
    uCameraGame* getGameCamera();
    uCameraGame* getPlayerCamera();
    uCamera* getMainCamera();
    bool isPlayerTargetCamera();
    void gcfOn(GAME_CAMERA_FLAG flag);
    void gcfOff(GAME_CAMERA_FLAG flag);
    bool gcfCk(GAME_CAMERA_FLAG flag);
    void createParamList();
    const cCamExParam* getCameraParamCmnAct(u32 no);
    const cCamExParam* getCameraParamCmnEvt(u32 no);
    const cCamExParam* getCameraParamTemplate(u32 no);
    void setParamListJob(rCameraParamList* pRes);
    const cCamExParam* getCameraParamJob(u32 no);
    void createQuakeList();
    void setQuake(u32 resIndex, uintptr task);
    void setQuakePos(u32 resIndex, uintptr task, const MtVector3& pos);
    void cancelQuake(u32 resIndex, uintptr task);
    void cancelQuakeTask(uintptr task);
    void cancelQuakeAll();
    void forceAdjustPlayerCamera();
    void resetGameCamera();
    bool requestExGameCamera(const cCamExParam* pParam, const uDDOModel* pRsrcOwner, const uDDOModel* pReqOwner, bool isForceSet);
    bool requestExGameCameraCmnActResource(u32 no, const uDDOModel* pReqOwner, bool isForceSet);
    bool requestExGameCameraCmnEvtResource(u32 no, const uDDOModel* pReqOwner, bool isForceSet);
    bool requestExGameCameraJobResource(u32 no, const uDDOModel* pReqOwner, bool isForceSet);
    void stopRequest(u32);
    void requestPushDist(f32 dist);
    f32 getPushDist() const;
    f32 getGameCameraFov();
    void requestRecoil(f32 scaleX, f32 frameX, f32 scaleY, f32 frameY);
    f32 getRecoilScaleX() const;
    f32 getRecoilFrameX() const;
    f32 getRecoilScaleY() const;
    f32 getRecoilFrameY() const;
    const MtHermiteCurve getRecoilCurve() const;
    u8 getDefaultPreset();
    void setDefaultPreset(u8 preset);
    f32 getExtendAnimationTime() const;
    void setExtendAnimationTime(f32 deltaTime);
    void addExtendAnimationTime(f32);
    void clearExtendAnimationTimeForSS();
    s32 getCut();
    void setBehindPlayer();
    void resetBehindPlayer();
    bool isBehindPlayer();
    u32 getLargeCameraRange(u32 emid, f32& range1, f32& range2, bool& isGroup);
    void requestCtrlLStick();
    bool isCtrlLStick() const;
    void setPhotoMode();
    void resetPhotoMode();
    bool isPhotoMode() const;
    void setPhotoModeException();
    void resetPhotoModeException();
    bool isPhotoModeException() const;
    void resetPhotoParam();
    void setRateFix();
    void resetRateFix();
    bool isRateFix() const;
    void setWallAdjust(bool flag);
    bool isWallAdjust() const;
    f32 getCameraOffsetX() const;
    void resetFallinstantdeath();
    bool isCtrlCameraPhotoMode();
    bool isUseblePhotoMode();
    bool isDispPoint4AndLength(f32 length, MtVector3* pCkPos);
    f32 getGameScreenRectVRatio() const;
    void setGameScreenRectVRatio(f32);
private:
    uCameraGame* mpGameCamera;  // offset: 0xd68
    uCamera* mpOldCamera;  // offset: 0xd70
    uFreeCamera* mpGameFreeCamera;  // offset: 0xd78
    uCameraGame* mpPlayerCamera;  // offset: 0xd80
    rCameraParamList* mprParamListTemplate;  // offset: 0xd88
    rCameraQuakeList* mprQuakeList;  // offset: 0xd90
    rCameraParamList* mprParamListJob;  // offset: 0xd98
    rCameraParamList* mprParamListCmnAct;  // offset: 0xda0
    rCameraParamList* mprParamListCmnEvt;  // offset: 0xda8
    rLargeCameraParam* mprLargeCameraParam;  // offset: 0xdb0
    f32 mGameScreenRectVRatio;  // offset: 0xdb8
    nDDOUtility::cBitSet<5> mGcf;  // offset: 0xdbc
    u32 mRequestStop;  // offset: 0xdc0
    f32 mPushDist;  // offset: 0xdc4
    f32 mRecoilFrameX;  // offset: 0xdc8
    f32 mRecoilScaleX;  // offset: 0xdcc
    f32 mRecoilFrameY;  // offset: 0xdd0
    f32 mRecoilScaleY;  // offset: 0xdd4
    MtHermiteCurve mRecoilCurve;  // offset: 0xdd8
    f32 mExtendAnimationTime;  // offset: 0xe18
    u8 mDefaultPreset;  // offset: 0xe1c
    bool mSetBehindPlayer;  // offset: 0xe1d
    bool mPhotoMode;  // offset: 0xe1e
    bool mPhotoModeException;  // offset: 0xe1f
    bool mIsWallAdjust;  // offset: 0xe20
    bool mRateFix;  // offset: 0xe21
    f32 mCameraOffsetX;  // offset: 0xe24
    bool mIsCtrlLStick;  // offset: 0xe28
public:
    static MyDTI DTI;
    static const f32 BASE_GAME_SCREEN_RECT_V_RATIO;
    static const f32 CINESCO_SCREEN_RECT_V_RATIO;
    static const f32 CINESCO_SCREEN_RECT_V_RATIO_2;
private:
    static const f32 DEF_GAME_SCREEN_RECT_V_RATIO;
};
