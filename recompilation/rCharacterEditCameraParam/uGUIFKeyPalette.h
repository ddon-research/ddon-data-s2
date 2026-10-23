#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/nKeyCustom.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjTexture;
class cGUIObject;
class rGUI;
class sGUIExt;
class uHuman;

// Declarations
class uGUIFKeyPalette;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIFKeyPalette : public uGUIBase
{
    // inferred: sGUIExt::updateFKeyPaletteGuide names uGUIFKeyPalette::mIsUpdateKeyGuideSCM
    friend class sGUIExt;
public:
    enum GMD_ID
    {
        GMD_ID_BUTTON_GUIDE = 0,
        GMD_ID_SHORTCUT_SETTING = 1,
    };
public:
    class MyDTI;
    struct stSCMBtn;
    struct stSCCBtn;
    struct stKeyGuide;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stSCMBtn
    {
    public:
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x0
        uGUIBase::cReferenceUIIconGameMenu mIconMenu;  // offset: 0x180
        cGUIObjMessage* mpObjMsgFKey;  // offset: 0x1d0
        cGUIInstAnimation* mpInstIconDcd;  // offset: 0x1d8
        cGUIInstAnimation* mpInstIconDisable;  // offset: 0x1e0
        cGUIInstNull* mpInstParent;  // offset: 0x1e8
    };
public:
    struct stSCCBtn
    {
    public:
        uGUIBase::cReferenceUIIconComm mIconComm;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x50
        cGUIInstAnimation* mpInstVoice;  // offset: 0x58
        cGUIObjMessage* mpOBJ_msg_command_m_btn;  // offset: 0x60
    };
public:
    struct stKeyGuide
    {
    public:
        stKeyGuide();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgKey00;  // offset: 0x8
        cGUIObjMessage* mpObjMsgKey01;  // offset: 0x10
        cGUIObjMessage* mpObjMsgAction;  // offset: 0x18
        cGUIObjTexture* mpObjTexPlus;  // offset: 0x20
        cGUIObjTexture* mpObjTexSealRight;  // offset: 0x28
        cGUIObjTexture* mpObjTexSealCenter;  // offset: 0x30
        cGUIObjTexture* mpObjTexSealLeft;  // offset: 0x38
        bool mIsLeft;  // offset: 0x40
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
    uGUIFKeyPalette();
    virtual ~uGUIFKeyPalette();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void adjustScale();  // vtable slot 84
    virtual bool isForceSamplerLinear(cGUIObject* pObj) const;  // vtable slot 46
    void setSCMEditMode(u32 uMode);
    void setUpdateKeyGuide();
private:
    void setPlayFlow(u32 flow_id);
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
    void updateDispSCM();
    void updateDispSCC();
    void setupKeyGuide(stKeyGuide& guide, u32 inst_id, bool isLeft);
    void updateKeyGuide();
    void clearKeyGuideMsg(stKeyGuide& guide);
    void setKeyGuideMsgNormalSkill(stKeyGuide& guide, nKeyCustom::KB_CUSTOM keyCustom, u32 job_id, u32 msg_index);
    void setKeyGuideMsg(stKeyGuide& guide, nKeyCustom::KB_CUSTOM keyCustom, MT_CTSTR pAct);
    void setKeyGuideMsg(stKeyGuide& guide, MT_CTSTR pKey00, MT_CTSTR pKey01, MT_CTSTR pAct);
    void setKeyGuideSeal(stKeyGuide& guide, bool isSeal);
    void setKeyGuideVisible(stKeyGuide& guide, bool isVisible);
    MT_CTSTR getGuideMsg(u32 index);
    u32 getMsgIdxNormalSkill(const uHuman* pPlayer, u32 uMsgIdx);
    virtual void replacePriority(u32 uPrioGrp);  // vtable slot 80
    void updateButtonIconSCM();
    void updateButtonIconSCC();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    stSCMBtn mSCMBtn[12];  // offset: 0x8d0
    stSCCBtn mSCCBtn[8];  // offset: 0x2010
    stKeyGuide mNormalGuide[6];  // offset: 0x2350
    stKeyGuide mCustomGuide[4];  // offset: 0x2500
    stKeyGuide mCustomSkillPalletChangeGuide;  // offset: 0x2620
    cGUIInstNull* mpInstNullGuideRoot;  // offset: 0x2668
    cGUIInstNull* mpInstNullSCMRoot;  // offset: 0x2670
    cGUIInstNull* mpInstNullSCCRoot;  // offset: 0x2678
    cGUIInstNull* mpInstNullGuide;  // offset: 0x2680
    cGUIInstNull* mpInstNullSCM;  // offset: 0x2688
    cGUIInstNull* mpInstNullSCC;  // offset: 0x2690
    cGUIInstance* mpInst_msg_commu;  // offset: 0x2698
    cGUIInstance* mpInst_msg_command;  // offset: 0x26a0
    cGUIInstance* mpInst_Null_listall;  // offset: 0x26a8
    cGUIInstAnimation* mpInstSCMTitle;  // offset: 0x26b0
    cGUIObjMessage* mpObjMsgSCMTitle;  // offset: 0x26b8
    cGUIObjTexture* mpObjMsgSCMTitleBackL;  // offset: 0x26c0
    cGUIObjTexture* mpObjMsgSCMTitleBackR;  // offset: 0x26c8
    cGUIObjTexture* mpObjMsgSCMTitleBackC;  // offset: 0x26d0
    uGUIBase::cReferenceUIPageDot mPageDotSCC;  // offset: 0x26d8
    u32 mEditMode;  // offset: 0x2760
    u32 mPrioGroup;  // offset: 0x2764
    f32 mPosYInitSCC;  // offset: 0x2768
    f32 mMoveYSCCEdit;  // offset: 0x276c
    f32 mPosYTargetSCC;  // offset: 0x2770
    f32 mScaleDefault;  // offset: 0x2774
    f32 mScaleFocus;  // offset: 0x2778
    f32 mKeyGuideDefaultPosLeft;  // offset: 0x277c
    f32 mKeyGuideDefaultPosRight;  // offset: 0x2780
    bool mIsEditSCCGuide;  // offset: 0x2784
    bool mIsUpdateKeyGuideSCM;  // offset: 0x2785
    bool mIsUpdateKeyGuideSCC;  // offset: 0x2786
    cGUIObjMessage* mpOBJ_msg_commu_m_btn00;  // offset: 0x2788
    cGUIObjMessage* mpOBJ_msg_commu_m_btn10;  // offset: 0x2790
    cGUIObjMessage* mpOBJ_msg_header_m_setkey;  // offset: 0x2798
public:
    static MyDTI DTI;
    static const u32 KEY_MAX = 12;
    static const u32 NORMAL_NUM = 6;
    static const u32 CUSTOM_NUM = 4;
};
