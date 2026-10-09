#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "sPad.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class uCamera;

// Declarations
class sPadExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class sPadExt : public sPad
{
public:
    enum PAD_BTN_TYPE
    {
        UI_DECIDE = 0,
        UI_CANCEL = 1,
        UI_START = 2,
        UI_SELECT = 3,
        UI_CHKOUT = 4,
        UI_RT = 5,
        UI_LT = 6,
        UI_RB = 7,
        UI_LB = 8,
        UI_X = 9,
        UI_Y = 10,
        UI_AL_UP = 11,
        UI_AL_DOWN = 12,
        UI_AL_LEFT = 13,
        UI_AL_RIGHT = 14,
        UI_AR_UP = 15,
        UI_AR_DOWN = 16,
        UI_AR_LEFT = 17,
        UI_AR_RIGHT = 18,
        UI_TAB_R = 19,
        UI_TAB_L = 20,
        UI_LS_CRAM = 21,
        UI_RS_CRAM = 22,
        UI_RU = 23,
        UI_RD = 24,
        UI_RL = 25,
        UI_RR = 26,
        STG_JUMP = 27,
        STG_ATTACK_0 = 28,
        STG_ATTACK_1 = 29,
        STG_ATTACK_2 = 30,
        STG_ATTACK_3 = 31,
        STG_TOUCH = 32,
        STG_MAIN_WEP = 33,
        STG_SUB_WEP = 34,
        STG_LOCK_ON = 35,
        STG_LIFT = 36,
        STG_THROWING = 37,
        STG_THROWING_AWAY = 38,
        STG_DASH = 39,
        STG_CAM_RESET = 40,
        STG_STAT_CHANGE = 41,
        STG_SHOT = 42,
        STG_CHG_MODE = 43,
        STG_ORDER_CMC_UP = 44,
        STG_ORDER_CMC_DOWN = 45,
        STG_ORDER_CMC_LEFT = 46,
        STG_ORDER_CMC_RIGHT = 47,
        STG_KEY_UP = 48,
        STG_KEY_DOWN = 49,
        STG_KEY_LEFT = 50,
        STG_KEY_RIGHT = 51,
        STG_CS_CHANGE = 52,
        UI_SCM = 53,
        UI_SCC = 54,
        UI_GAMEMENU = 55,
        UI_CHAT = 56,
        PAD_BTN_TYPE_MAX = 57,
        UI_UP = 58,
        UI_DOWN = 59,
        UI_LEFT = 60,
        UI_RIGHT = 61,
        UI_WHL_FB = 62,
        PAD_BTN_TYPE_INVALID = 63,
    };
    enum PAD_TIMING
    {
        PAD_TRG = 0,
        PAD_ON = 1,
        PAD_REP = 2,
        PAD_ACL = 3,
        PAD_REL = 4,
        PAD_TIMING_MAX = 5,
    };
    enum
    {
        GAME_PAD = 0,
        PAD_INFO_NUM = 1,
        INVALID_PAD_ID = 65535,
    };
    enum
    {
        OPTION_CONTROLER_TYPE_A = 0,
        OPTION_CONTROLER_TYPE_B = 1,
        OPTION_CONTROLER_TYPE_C = 2,
        OPTION_CONTROLER_TYPE_D = 3,
        OPTION_CONTROLER_TYPE_E = 4,
        OPTION_CONTROLER_TYPE_F = 5,
        OPTION_CONTROLER_TYPE_NUM = 6,
    };
public:
    class MyDTI;
    class cPadInfo;
public:
    typedef struct
    {
    public:
        sPadExt::PAD_BTN_TYPE mPadBtnType;  // offset: 0x0
        u32 mPadCode;  // offset: 0x4
    } PAD_TYPE_DATA;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cPadInfo : public MtObject
    {
        // inferred: sPadExt::setGamePad names sPadExt::mPadInfo[0].mPadId
        friend class sPadExt;
    public:
        enum
        {
            LEFT = 0,
            RIGHT = 1,
            ANLG_STICK_NUM = 2,
        };
        enum
        {
            VIB_INFO_NUM = 16,
        };
    public:
        class MyDTI;
        struct stBtnInfo;
        struct stUDRLBtnInfo;
        struct stAnlgInfo;
        struct stPressInfo;
        struct stSensorInfo;
        struct stVibInfo;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stBtnInfo
        {
        public:
            u32 on;  // offset: 0x0
            u32 trg;  // offset: 0x4
            u32 rel;  // offset: 0x8
            u32 rep;  // offset: 0xc
            u32 acl;  // offset: 0x10
            u32 old;  // offset: 0x14
        };
    public:
        struct stUDRLBtnInfo
        {
        public:
            u32 on;  // offset: 0x0
            u32 trg;  // offset: 0x4
            u32 rel;  // offset: 0x8
            u32 rep;  // offset: 0xc
            u32 acl;  // offset: 0x10
        };
    public:
        struct stAnlgInfo
        {
        public:
            f32 x;  // offset: 0x0
            f32 y;  // offset: 0x4
        };
    public:
        struct stPressInfo
        {
        public:
            f32 Lup;  // offset: 0x0
            f32 Lright;  // offset: 0x4
            f32 Ldown;  // offset: 0x8
            f32 Lleft;  // offset: 0xc
            f32 Rup;  // offset: 0x10
            f32 Rright;  // offset: 0x14
            f32 Rdown;  // offset: 0x18
            f32 Rleft;  // offset: 0x1c
            f32 L1;  // offset: 0x20
            f32 L2;  // offset: 0x24
            f32 R1;  // offset: 0x28
            f32 R2;  // offset: 0x2c
            f32 Select;  // offset: 0x30
            f32 L3;  // offset: 0x34
            f32 R3;  // offset: 0x38
        };
    public:
        struct stSensorInfo
        {
        public:
            f32 x;  // offset: 0x0
            f32 y;  // offset: 0x4
            f32 z;  // offset: 0x8
            f32 g;  // offset: 0xc
        };
    public:
        struct stVibInfo
        {
        public:
            bool mIsMove;  // offset: 0x0
            bool mIsPause;  // offset: 0x1
            s32 mType;  // offset: 0x4
            s32 mTimeLeft;  // offset: 0x8
            s32 mVib;  // offset: 0xc
            s32 mEndVib;  // offset: 0x10
            s32 mAdd;  // offset: 0x14
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
        cPadInfo();
        virtual ~cPadInfo();
        bool isVibration();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void clear(bool flag);
        void update();
        void setFakeData(u32 on, u32 trg, u32 rel, u32 rep);
        void initVibration();
        void initVibration(stVibInfo* vp);
        void updateVibration(u32 deltaTime);
        void setVibrationPause();
        void setVibrationRestart();
        void setVibrationEnable(bool flag);
        void setVibrationLow(f32 startVal, f32 endVal, f32 frm);
        void setVibrationHigh(f32 startVal, f32 endVal, f32 frm);
        void setVibrationLow(u32 startVal, u32 endVal, f32 frm);
        void setVibrationHigh(u32 startVal, u32 endVal, f32 frm);
        void stopVibration();
        void setOptionPadSetting(u32 Type);
        const sPadExt::PAD_TYPE_DATA* getOptionPadTypeTbl(u32 Type);
        s32 getOptionPadTypeTblSize();
    private:
        void setVibrationInfo(s32 type, u16 startVal, u16 endVal, f32 frm);
    public:
        u32 getPadSetting(sPadExt::PAD_BTN_TYPE button);
        void setPadSetting(sPadExt::PAD_BTN_TYPE button, u32 padCode);
    private:
        bool checkPad(sPadExt::PAD_BTN_TYPE button, sPadExt::PAD_TIMING check);
        bool checkPadUDRL(sPadExt::PAD_BTN_TYPE button, sPadExt::PAD_TIMING check);
        bool checkPadSys(sPadExt::PAD_BTN_TYPE button, sPadExt::PAD_TIMING check);
        bool checkPadUDRLSys(sPadExt::PAD_BTN_TYPE button, sPadExt::PAD_TIMING check);
        bool checkPadAuto(sPadExt::PAD_BTN_TYPE button, sPadExt::PAD_TIMING check);
        bool checkPadAutoSys(sPadExt::PAD_BTN_TYPE button, sPadExt::PAD_TIMING check);
    public:
        u32 getPadId();
        void setPadId(u32 padId);
        void setEnable(bool flag);
        bool isEnable();
        bool isDecide();
        bool isCancel();
        f32 getRepeatFrame();
        u32 getBtnInfoOn() const;
        u32 getBtnInfoTrg() const;
        u32 getBtnInfoRel() const;
        u32 getBtnInfoRep() const;
        u32 getBtnInfoAcl() const;
        f32 getAnlgInfoLx() const;
        f32 getAnlgInfoLy() const;
        f32 getAnlgInfoRx() const;
        f32 getAnlgInfoRy() const;
        f32 getPressInfoR2() const;
        f32 getPressInfoL2() const;
        void setBtnInfoTrg(u32);
        void setAnlgInfoR(f32, f32);
    private:
        const stBtnInfo& getBtnInfo() const;
        const stUDRLBtnInfo& getBtnUDRLInfo() const;
        const stAnlgInfo& getAnlgInfoL() const;
        void setAnlgInfoL(f32, f32);
        const stAnlgInfo& getAnlgInfoR() const;
        const stPressInfo& getPressInfo();
        const stSensorInfo& getSensorInfo();
        bool isDisableInputGamePadInfo() const;
    private:
        u32 mPadId;  // offset: 0x8
        u32 mPadEnableId;  // offset: 0xc
        bool mIsEnable;  // offset: 0x10
        bool mIsVibEnable;  // offset: 0x11
        bool mIsFake;  // offset: 0x12
        stBtnInfo mBtn;  // offset: 0x14
        stUDRLBtnInfo mBtnUDRL;  // offset: 0x2c
        stAnlgInfo mAnlg[2];  // offset: 0x40
        stPressInfo mPress;  // offset: 0x50
        stSensorInfo mSensor;  // offset: 0x8c
        stVibInfo mVibInfo[16];  // offset: 0x9c
        u32 mPadSetting[57];  // offset: 0x21c
        f32 mRepTimer;  // offset: 0x300
        f32 mAclTimer;  // offset: 0x304
    public:
        static MyDTI DTI;
    private:
        static const f32 mRepStart;
        static const f32 mRepNext;
        static const f32 mAclStart;
        static const f32 mAclNext;
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
    sPadExt();
    virtual ~sPadExt();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void initRepeat();
    bool isRemotePlay();
    bool isSystemIntercepted(u32);
    void setIgnore(f32 frm);
    void setIgnore();
    void resetIgnore();
    bool isIgnore();
    bool checkGameStart();
    void setGamePad(u32 id);
    void getAnalogLevel(s32 id, s32 lr, s16& vX, s16& vY, s16 level);
    void getAnalogLevel(s32 id, s32 lr, f32& vX, f32& vY, f32 levelX, f32 levelY, f32 aveX, f32 aveY);
    MtVector3 getCameraAnalogLevel(s32 id, s32 lr, uCamera* pCamera);
    void setVibrationEnable(bool flag);
    bool isAppActive() const;
    virtual u32 getDecideButton() const;  // vtable slot 11
    virtual u32 getCancelButton() const;  // vtable slot 12
    bool isEnableReplaceDC();
    void setEnableReplaceDC(bool);
private:
    void updateIgnore();
    void initDeltaTime();
    void updateDeltaTime();
public:
    s32 getGamePadId();
    cPadInfo* getGamePad(s32 id);
    bool isTrgCheck(PAD_BTN_TYPE button, u32 pad_id);
    bool isOnCheck(PAD_BTN_TYPE button, u32 pad_id);
    bool isRepCheck(PAD_BTN_TYPE button, u32 pad_id);
    bool isAclCheck(PAD_BTN_TYPE button, u32 pad_id);
    bool isPadCheck(PAD_BTN_TYPE button, PAD_TIMING btn, u32 pad_id);
    f32 getRepeatFrame(u32 pad_id);
    virtual void clearInputData();  // vtable slot 10
    void onAutoRunButtonHold();
    bool isAutoRunButtonHold() const;
private:
    cPadInfo mPadInfo[1];  // offset: 0x12c8
    s32 mGamePadId;  // offset: 0x15d0
    u64 mPrevTimer;  // offset: 0x15d8
    u32 mDeltaTime;  // offset: 0x15e0
    bool mIsIgnore;  // offset: 0x15e4
    s32 mIgnoreTimer;  // offset: 0x15e8
    bool mOldActive;  // offset: 0x15ec
    bool mIsEnableActiveWindow;  // offset: 0x15ed
    bool mIsEnableWindowPadNo;  // offset: 0x15ee
    bool mIsEnableReplaceDC;  // offset: 0x15ef
    bool mIsRemotePlay;  // offset: 0x15f0
    bool mIsAutoRunButtonHold;  // offset: 0x15f1
public:
    static MyDTI DTI;
private:
    static const f32 mAnlgErrorMargin;
};
