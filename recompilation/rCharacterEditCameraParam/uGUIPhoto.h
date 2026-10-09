#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cControl.h"
#include "../shared/cGUIControlMgr.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjTextureRef;
class cGUIObject;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIPhoto;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPhoto : public uGUIBase
{
public:
    enum
    {
        MODE_PHOTO = 0,
        MODE_SHOT = 1,
        MODE_FRAME = 2,
        MODE_OVERWRITE = 3,
    };
    enum
    {
        MGR_ID_PHOTO = 0,
        MGR_ID_FRAME = 1,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_PHOTO = 67,
        INPUTEVENT_SHOT = 68,
        INPUTEVENT_FRAME = 69,
        INPUTEVENT_OVERWRITE = 70,
        INPUTEVENT_CHANGEFRAME = 71,
        INPUTEVENT_RETURNFRAME = 72,
        INPUTEVENT_ENDFRAME = 73,
        INPUTEVENT_STARTCOMM = 74,
        INPUTEVENT_DISPPLAYER = 75,
    };
    enum
    {
        FRAME_MAX = 20,
    };
    enum
    {
        CONTROL_CATEGORY_PHOTO = 0,
        CONTROL_CATEGORY_FRAME = 1,
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
    static bool isExitPhoto();
    static bool isNoStartPhoto();
    uGUIPhoto();
    virtual ~uGUIPhoto();
private:
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateWait();
    void updateShot();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlDecide(cControl::Message* pMsg);
    u32 evCtrlStart(cControl::Message* pMsg);
    u32 evCtrlStartBGChange(cControl::Message* pMsg);
    u32 evCtrlDispPlayer(cControl::Message* pMsg);
    u32 evCtrlStartComm(cControl::Message* pMsg);
    u32 evCtrlCancelFrame(cControl::Message* pMsg);
    u32 evCtrlDecideFrame(cControl::Message* pMsg);
    u32 evCtrlMoveUDFrame(cControl::Message* pMsg);
    u32 evCtrlMouseDecideFrame(cControl::Message* pMsg);
    u32 evCtrlMouseSelectFrame(cControl::Message* pMsg);
    void initCommon();
    void initPhoto();
    void initShot();
    void initFrame();
    void initOverwrite();
    void shot();
    bool isShot();
    void initList(u32 Index, cGUIInstAnimation* pInst);
    void setupCursor();
    void updateCursor();
    void setWait();
    void setExit();
    void moveCamera();
    void reCover(u32 framePos);
    bool isExitMyPhoto();
protected:
    virtual void adjustScale();  // vtable slot 84
public:
    virtual bool isForceSamplerLinear(cGUIObject* pObj) const;  // vtable slot 46
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rGUIMessage* mpFrameGMDRes;  // offset: 0x8d8
    cGUIControlMgr mControls;  // offset: 0x8e0
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0xd90
    uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0xdf0
    u32 mMode;  // offset: 0xea0
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0xea8
    uGUIBase::cReferenceUIBtnGuide mSubGuide;  // offset: 0xf40
    u32 mOldFrame;  // offset: 0xfd8
    u32 mFrameNum;  // offset: 0xfdc
    uGUIBase::cTexRefArcLoader mPhotoFrame;  // offset: 0xfe0
    f32 mCounter;  // offset: 0x1058
    bool mIsStopCameraOperation;  // offset: 0x105c
    bool mIsRenderDetailControl;  // offset: 0x105d
    u32 mSelectFrame;  // offset: 0x1060
    u32 mViewFrame;  // offset: 0x1064
    cGUIInstAnimation* mpFlash;  // offset: 0x1068
    cGUIInstAnimation* mpList[20];  // offset: 0x1070
    cGUIInstAnimation* mpFrame;  // offset: 0x1110
    cGUIObjTextureRef* mpFrameTex;  // offset: 0x1118
    cGUIInstAnimation* mpFinder;  // offset: 0x1120
    cGUIInstAnimation* mpScrbar;  // offset: 0x1128
    cGUIInstNull* mpInstNullRightBottom;  // offset: 0x1130
    cGUIInstNull* mpInstNullLeftTop;  // offset: 0x1138
    cGUIInstNull* mpInstNullOverWrite;  // offset: 0x1140
    cGUIInstNull* mpInstNullCopyRight;  // offset: 0x1148
public:
    static MyDTI DTI;
};
