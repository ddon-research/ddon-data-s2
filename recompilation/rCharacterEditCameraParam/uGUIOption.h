#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Character.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cCharacterData.h"
#include "../shared/cControl.h"
#include "cPCGraphicOption.h"
#include "nMenuKeyConfig.h"
#include "../shared/nNet.h"
#include "../shared/sEffectExt.h"
#include "../shared/sSavedataExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector4;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObject;
namespace nMenuKeyConfig { class KeyCustomManagers; }
class rGUI;
class rGUIMessage;
class rTblMenuOption;
class uGUISystemMsg;

// Declarations
class uGUIOption;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIOption : public uGUIBase
{
public:
    enum
    {
        TYPE_SYSTEM = 0,
        TYPE_SYSTEM_TITLE = 1,
        TYPE_CHAR = 2,
        TYPE_NUM = 3,
    };
    enum
    {
        RNO_SAVE_INIT = 0,
    };
    enum
    {
        INPUTEVENT_CTGR_END = 66,
        INPUTEVENT_CTGR_MOVE = 67,
        INPUTEVENT_CTGR_DECIDE = 68,
        INPUTEVENT_TAB_MOVE = 69,
        INPUTEVENT_DATA_CANCEL = 70,
        INPUTEVENT_DATA_MOVE = 71,
        INPUTEVENT_DATA_DECIDE = 72,
        INPUTEVENT_AOI_MOVE = 73,
        INPUTEVENT_AOI_DECIDE = 74,
        INPUTEVENT_APPLY_APPLY = 75,
    };
    enum
    {
        SWSN_INITIALIZE = 0,
        SWSN_EXIT = 1,
        SWSN_PADNONE = 2,
    };
    enum
    {
        AOI_APPLY = 0,
        AOI_INITIALIZE = 1,
        AOI_NUM = 2,
    };
    enum
    {
        GPTYPE_TMP = 0,
        GPTYPE_INIT = 1,
        GPTYPE_APPLY = 2,
    };
    enum
    {
        DATATYPE_NONE = 0,
        DATATYPE_RESOLUTION = 1,
        DATATYPE_CF00 = 2,
        DATATYPE_CFCOLOR = 3,
        DATATYPE_CF01 = 4,
        DATATYPE_CFSE = 5,
        DATATYPE_IDLEEMOTCTGR = 6,
        DATATYPE_IDLEEMOT = 7,
        DATATYPE_ONLINEST = 8,
        DATATYPE_INPUTMODE = 9,
        DATATYPE_DIRECTCHAT = 10,
        DATATYPE_KEY_SETTING = 11,
        DATATYPE_KEY_CONFIG = 12,
        DATATYPE_KEY_JOB_LINK = 13,
    };
public:
    class MyDTI;
    struct stCheckBox;
    struct stSlider;
    struct stPulldown;
    struct stButton;
    struct stGamma;
    struct stSpDataTypeWork;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stCheckBox
    {
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUIBase::cReferenceUICheckbox mChkBox;  // offset: 0x8
        cGUIObject* mpObjMsg;  // offset: 0x58
        bool* mpBool;  // offset: 0x60
    };
public:
    struct stSlider
    {
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUIBase::cReferenceUIEditSlider mSlider;  // offset: 0x8
        cGUIObject* mpObjMsg;  // offset: 0x138
        u8* mpU8;  // offset: 0x140
        u32 mPageIndex;  // offset: 0x148
    };
public:
    struct stPulldown
    {
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUIBase::cReferenceUIPullDown mPulldown;  // offset: 0x10
        cGUIObject* mpObjMsg;  // offset: 0x620
        u8* mpU8;  // offset: 0x628
    };
public:
    struct stButton
    {
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUIBase::cReferenceUIButton mButton;  // offset: 0x8
        cGUIObject* mpObjMsg;  // offset: 0x198
        u32 mDataId;  // offset: 0x1a0
    };
public:
    struct stGamma
    {
    public:
        void setVisible(bool bVisible);
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUIBase::cReferenceUIGammaBoard mGammaBoard;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTips;  // offset: 0x88
    };
public:
    struct stSpDataTypeWork
    {
    public:
        u8 mChatFilter00;  // offset: 0x0
        u8 mChatFilterColor;  // offset: 0x1
        u8 mChatFilter01;  // offset: 0x2
        u8 mChatFilterSE;  // offset: 0x3
        u8 mIdleEmotCtgr;  // offset: 0x4
        u8 mIdleEmot;  // offset: 0x5
        u8 mPlCardOnView;  // offset: 0x6
        u8 mLightHardwareMode;  // offset: 0x7
        u8 mOthersEffTrans;  // offset: 0x8
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
    uGUIOption();
    virtual ~uGUIOption();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setOptionType(u32 uType);
    u32 getOptionType();
    static u8 getOnlineStatusIndex(nCharacter::E_ONLINE_STATUS status);
    static nCharacter::E_ONLINE_STATUS getOnlineStatus(u32 uIdx);
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateInit();
    void updateWait();
    void updateWaitData();
    void updateWaitDataPulldown();
    void updateWaitCalibration();
    void updateWaitKeyConfig();
    void updateWaitKeyJobLink();
    void setIdxPulldown(u32 pulldownId);
    void updateSaveData();
    void updateExit();
    void evCtgrEnd();
    void evCtgrMove();
    void evCtgrDecide();
    void evTabMove();
    void evDataCancel();
    void evDataMove();
    void evDataDecide();
    void evAOIMove();
    void evAOIDecide();
    void evApplyApply();
    u32 evCtrlCtgrEnd(cControl::Message* msg);
    u32 evCtrlCtgrMove(cControl::Message* msg);
    u32 evCtrlCtgrDecide(cControl::Message* msg);
    u32 evCtrlTabMove(cControl::Message* msg);
    u32 evCtrlDataCancel(cControl::Message* msg);
    u32 evCtrlDataMove(cControl::Message* msg);
    u32 evCtrlDataDecide(cControl::Message* msg);
    u32 evCtrlAOIMove(cControl::Message* msg);
    u32 evCtrlApplyApply(cControl::Message* msg);
    void* getOptionParamHandle(u32 uIdx, u32 uType);
    void* getOptionParamInitHandle(u32 uIdx);
    void* getOptionParamApplyHandle(u32 uIdx);
    void updateTab();
    void updatePage(bool bInit, bool bResetCtrl);
    void saveOptionData();
    bool isDiffOptionData();
    void createInitializeDialog();
    void createExitDialog();
    void initializeCurrentCtgr();
    void scrollPageNull();
    bool execDialog();
    bool execSubWindow();
    u32 getDataType(u32 uCtgr, u32 uTab, u32 uCaption, u32 uData);
    void updateReflectionData(const cStorageData::stOptionDataSystem* pOptionSys, const cCharacterData::stOptionData* pOptionChr);
    u32 getMsgIdOnlineStatus(u32 uIdx);
    u8 getShareRangeIndex(nNet::PAWN_SHARE_RANGE range) const;
    nNet::PAWN_SHARE_RANGE getShareRangeFromIndex(u32 index) const;
    u8 getLightHardWareModeIndex(nPCGraphicOption::LIGHT_HARDWARE_MODE mode) const;
    nPCGraphicOption::LIGHT_HARDWARE_MODE getLightHardWareModeFromIndex(u32 index) const;
    u8 getOthersEfcTypeIndex(sEffectExt::OPTION_OTHERS_EFC_TYPE type) const;
    sEffectExt::OPTION_OTHERS_EFC_TYPE getOthersEfcTypeFromIndex(u32 index) const;
    void updateCurrentInputMode();
    bool checkInputMode();
    void execChangeInputMode();
    void updateDisp();
    void selectChatFilterColor(stSpDataTypeWork& work, const cCharacterData::stOptionData& optionData);
    void selectChatFilterSE(stSpDataTypeWork& work, const cCharacterData::stOptionData& optionData);
    bool isDecideCalibration(s32 sPosCtgr, s32 sPosTab, u32 uCaptionNum);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rTblMenuOption* mpTblMORes;  // offset: 0x8d0
    rGUIMessage* mpGUIMsg;  // offset: 0x8d8
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x8e0
    uGUIBase::cVerticalList* mpVLCtgr;  // offset: 0x938
    uGUIBase::cHorizontalList* mpHLTab;  // offset: 0x940
    uGUIBase::cVerticalList* mpVLData;  // offset: 0x948
    uGUIBase::cHorizontalList* mpHLAOI;  // offset: 0x950
    cControl* mpCtrlApply;  // offset: 0x958
    u32 mOptionType;  // offset: 0x960
    uGUIBase::cReferenceUIVlCursor mCsrCtgr;  // offset: 0x970
    cGUIInstAnimation* mpInstListCtgr[8];  // offset: 0xa20
    cGUIObject* mpObjMsgListCtgr[8];  // offset: 0xa60
    cGUIInstAnimation* mpInstListCaption[16];  // offset: 0xaa0
    cGUIObject* mpObjMsgListCaption[16];  // offset: 0xb20
    cGUIInstNull* mpInstNullPage;  // offset: 0xba0
    cGUIInstance* mpInstCtgrMask;  // offset: 0xba8
    cGUIInstance* mpInstPageMask;  // offset: 0xbb0
    cGUIObjPolygon* mpObjPolyCtgrMask;  // offset: 0xbb8
    cGUIObjPolygon* mpObjPolyPageMask;  // offset: 0xbc0
    stCheckBox mCheckBox[16];  // offset: 0xbc8
    stSlider mSlider[16];  // offset: 0x1248
    stPulldown mPulldown[16];  // offset: 0x2750
    stButton mButton[16];  // offset: 0x8a50
    stGamma mGammaWork;  // offset: 0xa4d0
    uGUIBase::cReferenceUIScrollBar mScrbarCtgr;  // offset: 0xa560
    uGUIBase::cReferenceUITab mTab;  // offset: 0xa610
    uGUIBase::cReferenceUIButton2 mBtnApply;  // offset: 0xa6c0
    uGUIBase::cReferenceUIButton mBtnInitialize;  // offset: 0xa850
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xa9e0
    uGUIBase::cReferenceUIScrollBar mScrbarPage;  // offset: 0xaa78
    MtVector4 mPosFocusInPage;  // offset: 0xab20
    f32 mDistYCaption;  // offset: 0xab30
    f32 mDistYData;  // offset: 0xab34
    f32 mSizeHMask;  // offset: 0xab38
    f32 mSizeHPulldownList;  // offset: 0xab3c
    f32 mWaitOnlineStatusSend;  // offset: 0xab40
    f32 mPosYScrBarStart;  // offset: 0xab44
    u32 mWakeupPulldown;  // offset: 0xab48
    u32 mRnoSave;  // offset: 0xab4c
    u32 mReqOnlineStatusOld;  // offset: 0xab50
    bool mIsEndSave;  // offset: 0xab54
    bool mReqOnlineStatusSend;  // offset: 0xab55
    cStorageData::stOptionDataSystem mOptionSysTmp;  // offset: 0xab56
    cCharacterData::stOptionData mOptionChrTmp;  // offset: 0xab94
    cStorageData::stOptionDataSystem mOptionSysInit;  // offset: 0xabf4
    cCharacterData::stOptionData mOptionChrInit;  // offset: 0xac30
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xac90
    uGUIBase* mpGUISubWindow;  // offset: 0xac98
    stSpDataTypeWork mSDTWork;  // offset: 0xaca0
    stSpDataTypeWork mSDTWorkInit;  // offset: 0xaca9
    bool mIsInputModePadOk;  // offset: 0xacb2
    bool mIsInputModeKeyboardOk;  // offset: 0xacb3
    bool mIsDirectChatOld;  // offset: 0xacb4
    u8 mActPltTypeOld;  // offset: 0xacb5
    u32 mMirrorParam_ScreenMode;  // offset: 0xacb8
    u32 mMirrorParam_ResolutionMode;  // offset: 0xacbc
    bool mMirrorParam_IsVSync;  // offset: 0xacc0
    nMenuKeyConfig::KeyCustomManagers mKeyCustomManagers;  // offset: 0xacc8
public:
    static MyDTI DTI;
    static const u32 CTGR_MAX = 8;
    static const u32 TAB_MAX = 4;
    static const u32 CAPTION_MAX = 16;
    static const u32 DATA_MAX = 32;
    static const u32 CHECKBOX_MAX = 16;
    static const u32 SLIDER_MAX = 16;
    static const u32 PULLDOWN_MAX = 16;
    static const u32 BUTTON_MAX = 16;
    static const u32 SEC_OSSENDWAIT = 10;
    static const u32 PULLDOWNVISIBLE_MAX = 8;
private:
    static const nCharacter::E_ONLINE_STATUS onlineStatusTblId[];
    static const nNet::PAWN_SHARE_RANGE shareRangeTblId[];
    static const nPCGraphicOption::LIGHT_HARDWARE_MODE lightHardwareModeTbl[];
    static const sEffectExt::OPTION_OTHERS_EFC_TYPE othersEfcTypeTbl[];
};
