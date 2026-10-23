#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/nDDOUtility.h"
#include "../shared/sGUIExt.h"
#include "../shared/sPadExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector4;
class cCharacterData;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjChildAnimationRoot;
class cGUIObjMessage;
class cGUIObjTexture;
class cGUIObject;
class rGUI;

// Declarations
class uGUIActionPalette;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIActionPalette : public uGUIBase
{
public:
    enum GMD_ID
    {
        GMD_ID_BUTTON_GUIDE = 0,
        GMD_ID_SHORTCUT_SETTING = 1,
    };
    enum
    {
        BTNID_RU = 0,
        BTNID_RD = 1,
        BTNID_RL = 2,
        BTNID_RR = 3,
        BTNID_L1 = 4,
        BTNID_R1 = 5,
        BTNID_L2 = 6,
        BTNID_R2 = 7,
        BTNID_R3 = 8,
        BTNID_MAX = 9,
    };
public:
    class MyDTI;
    struct stGuideBtn;
    struct stSeal;
    struct stSCMBtn;
    struct stSCMBtnMsg;
    struct stSCCBtn;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stGuideBtn
    {
    public:
        cGUIObjMessage* mpObjBtn;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
        cGUIObjChildAnimationRoot* mpObjChild;  // offset: 0x10
        cGUIObjTexture* mpObjTexBack;  // offset: 0x18
        cGUIObjTexture* mpObjTexBackHead;  // offset: 0x20
        cGUIObjTexture* mpObjTexBackTail;  // offset: 0x28
        cGUIObjTexture* mpObjTexIconSCM;  // offset: 0x30
    };
public:
    struct stSeal
    {
    public:
        cGUIObjTexture* mpObjTexRight;  // offset: 0x0
        cGUIObjTexture* mpObjTexCenter;  // offset: 0x8
        cGUIObjTexture* mpObjTexLeft;  // offset: 0x10
    };
public:
    struct stSCMBtnMsg
    {
    public:
        cGUIObjMessage* mpObjMsg;  // offset: 0x0
        cGUIObjTexture* mpObjTexL;  // offset: 0x8
        cGUIObjTexture* mpObjTexC;  // offset: 0x10
        cGUIObjTexture* mpObjTexR;  // offset: 0x18
    };
public:
    struct stSCCBtn
    {
    public:
        uGUIBase::cReferenceUIIconComm mIconComm;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x50
    };
public:
    struct stSCMBtn
    {
    public:
        cGUIInstNull* mpInstParent;  // offset: 0x0
        cGUIInstAnimation* mpInstIconDisable;  // offset: 0x8
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x10
        uGUIActionPalette::stSCMBtnMsg mMsg;  // offset: 0x190
        uGUIBase::cReferenceUIIconGameMenu mIconMenu;  // offset: 0x1b0
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
    uGUIActionPalette();
    virtual ~uGUIActionPalette();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void adjustScale();  // vtable slot 84
    virtual bool isForceSamplerLinear(cGUIObject* pObj) const;  // vtable slot 46
    void setSCMEditMode(u32 uMode);
    static MT_CTSTR getMsgSCC(const sGUIExt::cSCM::stSCCEditData* pEditData, cCharacterData* pData);
private:
    void updateInit();
    void updateWaitGuide();
    void updateWaitSCM();
    void updateWaitSCC();
    void updateWaitSCMEdit();
    void updateWaitSCCEdit();
    void updateExit();
    void setPlayFlow(u32 flow_id);
    void setGuideToSCM(u32 uMode);
    void setSCMEditActive(bool bActive);
    void setSCCEditActive(bool bActive);
    void updateGuideToSCM();
    void updateDispGuide();
    void updateDispSCM();
    void updateDispSCC();
    u32 getBtnIdFromPadBtn(sPadExt::PAD_BTN_TYPE btn, u32 uBitSkip);
    void setSeal(u32 index, bool isSeal);
    void setupKeyIcon();
    void setBtnVisible(u32 btnId, bool isVisible);
    void setBtnVisible(stGuideBtn& guideBtn, bool isVisible);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpInstNullAll;  // offset: 0x8d0
    cGUIInstNull* mpInstNullGuideRoot;  // offset: 0x8d8
    cGUIInstNull* mpInstNullSCMRoot;  // offset: 0x8e0
    cGUIInstNull* mpInstNullSCCRoot;  // offset: 0x8e8
    cGUIInstNull* mpInstNullGuide;  // offset: 0x8f0
    cGUIInstNull* mpInstNullSCM;  // offset: 0x8f8
    cGUIInstNull* mpInstNullSCC;  // offset: 0x900
    cGUIInstNull* mpInstNullCommuRight;  // offset: 0x908
    cGUIInstNull* mpInstNullCommuCenter;  // offset: 0x910
    cGUIInstAnimation* mpInst_msg_multi;  // offset: 0x918
    cGUIInstance* mpInst_msg_commu;  // offset: 0x920
    cGUIInstance* mpInst_msg_command;  // offset: 0x928
    cGUIInstance* mpInst_Null_listall;  // offset: 0x930
    cGUIInstAnimation* mpInstIconDcd;  // offset: 0x938
    cGUIObjChildAnimationRoot* mpObjKeyIconSCC;  // offset: 0x940
    cGUIObjChildAnimationRoot* mpObjKeyIconSCM;  // offset: 0x948
    uGUIBase::cReferenceUIPageDot mPageDotSCC;  // offset: 0x950
    MtVector4 mPosGuideInit;  // offset: 0x9e0
    MtVector4 mPosGuideTarget;  // offset: 0x9f0
    MtVector4 mPosSCMInit;  // offset: 0xa00
    MtVector4 mPosSCMTarget;  // offset: 0xa10
    MtVector4 mPosSCMEditInit;  // offset: 0xa20
    MtVector4 mPosSCCInit;  // offset: 0xa30
    MtVector4 mPosSCCTarget;  // offset: 0xa40
    MtVector4 mTblPosSCMCurrentPage[3];  // offset: 0xa50
    f32 mAlphaGuideTarget;  // offset: 0xa80
    f32 mAlphaSCMTarget;  // offset: 0xa84
    f32 mAlphaSCCTarget;  // offset: 0xa88
    f32 mFrmGuideToSCM;  // offset: 0xa8c
    f32 mMoveYSCMEdit;  // offset: 0xa90
    f32 mMoveYSCCEdit;  // offset: 0xa94
    f32 mWidthSCMIcon;  // offset: 0xa98
    stGuideBtn mGuideBtn[9];  // offset: 0xaa0
    stSeal mSealRU;  // offset: 0xc98
    stSeal mSealRL;  // offset: 0xcb0
    stSCMBtn mSCMBtn[3][4];  // offset: 0xcd0
    stSCCBtn mSCCBtn[8];  // offset: 0x24d0
    MT_CTSTR mpTblMsgGuide[34];  // offset: 0x2790
    bool mIsVisible;  // offset: 0x28a0
    bool mIsExecSCM;  // offset: 0x28a1
    nDDOUtility::cArray<cGUIInstNull*, 3> mINST_Null_itemall;  // offset: 0x28a8
public:
    static MyDTI DTI;
    static const u32 MSGID_MAX = 18;
    static const u32 PLTNAMELEN_MAX = 20;
    static const u32 FRM_GUIDETOSCM = 1;
    static const u32 FRM_EDITACTIVE = 2;
};
