#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "sSavedata.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class cEditParam;

// Declarations
class cStorageData;
class cStorageDataBase;
class cStorageDataEdit;
class sSavedataExt;

enum SAVEDATA_TYPE
{
    SAVEDATA_TYPE_MAIN = 0,
    SAVEDATA_TYPE_EDIT = 1,
    SAVEDATA_TYPE_NUM = 2,
};

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;
using u8 = unsigned char;

class cStorageDataBase : public MtObject
{
public:
    class MyDTI;
    struct UserHeader;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct UserHeader
    {
    public:
        UserHeader();
    public:
        MT_CHAR playerName[64];  // offset: 0x0
        MT_CHAR comment[128];  // offset: 0x40
        t64 createTime;  // offset: 0xc0
        u8 bodyType;  // offset: 0xc8
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
    cStorageDataBase();
    // Address: 0x01aca950 - 0x01aca951 (1 bytes)
    virtual ~cStorageDataBase() {}
    // Address: 0x01aca9a0 - 0x01aca9a1 (1 bytes)
    virtual void save(MtDataWriter& w, u32 SaveVersion) {}  // vtable slot 6
    // Address: 0x01aca9b0 - 0x01aca9b1 (1 bytes)
    virtual void load(MtDataReader& r, u32 CurrentVersion, u32 LoadVersion) {}  // vtable slot 7
    virtual bool isWriteUserHeader() const;  // vtable slot 8
    virtual bool saveUserHeader(MtDataWriter& w);  // vtable slot 9
    virtual bool loadUserHeader(MtDataReader& r);  // vtable slot 10
    virtual u32 getUserHeaderSize() const;  // vtable slot 11
public:
    static const u8 PLAYER_NAME_SIZE = 64;
    static const u8 COMENT_SIZE = 64;
    static const u8 SEXSTR_SIZE = 32;
    static const u32 USER_HEADER_SAVEDATA_VERSION = 1;
    static const u8 USER_HEADER_PLAYER_NAME_SIZE = 64;
    static const u8 USER_HEADER_COMENT_SIZE = 128;
    static MyDTI DTI;
};

class cStorageDataEdit : public cStorageDataBase
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
    cStorageDataEdit();
    virtual ~cStorageDataEdit();
    virtual void save(MtDataWriter& w, u32 SaveVersion);  // vtable slot 6
    virtual void load(MtDataReader& r, u32 CurrentVersion, u32 LoadVererion);  // vtable slot 7
    virtual bool isWriteUserHeader() const;  // vtable slot 8
    virtual bool saveUserHeader(MtDataWriter& w);  // vtable slot 9
    virtual bool loadUserHeader(MtDataReader& r);  // vtable slot 10
    virtual u32 getUserHeaderSize() const;  // vtable slot 11
    MT_CTSTR getPlayerName() const;
    MT_CTSTR getComment() const;
    void setPlayerName(MT_CTSTR name);
    void setComment(MT_CTSTR comment);
public:
    cStorageDataBase::UserHeader mUserHeader;  // offset: 0x8
    MT_CHAR mPlayerName[64];  // offset: 0xd8
    MT_CHAR mComment[64];  // offset: 0x118
    MT_CHAR mSexStr[32];  // offset: 0x158
    u8 mBodyType;  // offset: 0x178
    s32 mHair;  // offset: 0x17c
    s32 mBeard;  // offset: 0x180
    s32 mMakeup;  // offset: 0x184
    s32 mScar;  // offset: 0x188
    f32 mWrinkleValue;  // offset: 0x18c
    s32 mEyePresetNo;  // offset: 0x190
    s32 mEyebrowTexNo;  // offset: 0x194
    s32 mNosePresetNo;  // offset: 0x198
    s32 mMouthPresetNo;  // offset: 0x19c
    f32 mSokutoubuValue;  // offset: 0x1a0
    f32 mHitaiValue;  // offset: 0x1a4
    f32 mMimijyougeValue;  // offset: 0x1a8
    f32 mMabisasijyougeValue;  // offset: 0x1ac
    f32 mHitomiookisaValue;  // offset: 0x1b0
    f32 mMeookisaValue;  // offset: 0x1b4
    f32 mMekaitenValue;  // offset: 0x1b8
    f32 mKannkakuValue;  // offset: 0x1bc
    f32 mEyebrowUVOffsetYValue;  // offset: 0x1c0
    f32 mEyebrowUVOffsetXValue;  // offset: 0x1c4
    f32 mMayukaitenValue;  // offset: 0x1c8
    f32 mMikentakasaValue;  // offset: 0x1cc
    f32 mMikenhabaValue;  // offset: 0x1d0
    f32 mHanajyougeValue;  // offset: 0x1d4
    f32 mHanahabaValue;  // offset: 0x1d8
    f32 mHanatakasaValue;  // offset: 0x1dc
    f32 mHanakakudoValue;  // offset: 0x1e0
    f32 mHohobonejyougeValue;  // offset: 0x1e4
    f32 mHohoboneryouValue;  // offset: 0x1e8
    f32 mMimiookisaValue;  // offset: 0x1ec
    f32 mMimimukiValue;  // offset: 0x1f0
    f32 mElfmimi;  // offset: 0x1f4
    f32 mHanakuchijyougeValue;  // offset: 0x1f8
    f32 mAgozengoValue;  // offset: 0x1fc
    f32 mKuchihabaValue;  // offset: 0x200
    f32 mKuchiatsusaValue;  // offset: 0x204
    f32 mHohonikuValue;  // offset: 0x208
    f32 mAgosakijyougeValue;  // offset: 0x20c
    f32 mAgosakihabaValue;  // offset: 0x210
    f32 mErahonejyougeValue;  // offset: 0x214
    f32 mErahonehabaValue;  // offset: 0x218
    f32 mHeightValue;  // offset: 0x21c
    f32 mHeadSizeValue;  // offset: 0x220
    f32 mNeckOffsetValue;  // offset: 0x224
    f32 mNeckScaleValue;  // offset: 0x228
    f32 mUpperBodyScaleXValue;  // offset: 0x22c
    f32 mBellySizeValue;  // offset: 0x230
    f32 mTeatScaleValue;  // offset: 0x234
    f32 mTekubiSizeValue;  // offset: 0x238
    f32 mKoshiOffsetValue;  // offset: 0x23c
    f32 mKoshiSizeValue;  // offset: 0x240
    f32 mAnkleOffsetValue;  // offset: 0x244
    f32 mFatValue;  // offset: 0x248
    f32 mMuscleValue;  // offset: 0x24c
    f32 mMotionFilterValue;  // offset: 0x250
    s32 mColorSkin;  // offset: 0x254
    s32 mColorHair;  // offset: 0x258
    s32 mColorBeard;  // offset: 0x25c
    s32 mColorEyebrow;  // offset: 0x260
    s32 mColorREye;  // offset: 0x264
    s32 mColorLEye;  // offset: 0x268
    s32 mColorMakeup;  // offset: 0x26c
    static MyDTI DTI;
};

class cStorageData : public cStorageDataBase
{
public:
    class MyDTI;
    struct stOptionDataSystem;
    struct stTitle;
    struct stTutorialGuide;
    struct stAreaMasterTalk;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stOptionDataSystem
    {
    public:
        void setDefault();
        void writeData(MtDataWriter& w, u32 SaveVersion);
        void readData(MtDataReader& r, u32 CurrentVersion, u32 LoadVersion);
        bool reflectSavedGraphicOptionToGame() const;
    public:
        u8 mGamma;  // offset: 0x0
        u8 mVolChatRcv;  // offset: 0x1
        u8 mVolSysSE;  // offset: 0x2
        u8 mVolVoiceNpc;  // offset: 0x3
        u8 mVolVoicePawn;  // offset: 0x4
        u8 mVolVoicePl;  // offset: 0x5
        u8 mVolVoicePt;  // offset: 0x6
        u8 mVolVoiceEm;  // offset: 0x7
        u8 mVolVoiceSCC;  // offset: 0x8
        u8 mVolBGMBattle;  // offset: 0x9
        u8 mVolBGMOther;  // offset: 0xa
        u8 mVolSEEnv;  // offset: 0xb
        u8 mVolSEEm;  // offset: 0xc
        u8 mVolSEPl;  // offset: 0xd
        u8 mVolSEPt;  // offset: 0xe
        u8 mVolSEOther;  // offset: 0xf
        bool mPadVibration;  // offset: 0x10
        u8 mActPltType;  // offset: 0x11
        bool mIsDirectChat;  // offset: 0x12
        bool mIsCamVRevPad;  // offset: 0x13
        bool mIsCamHRevPad;  // offset: 0x14
        bool mIsCamVRevKeyboard;  // offset: 0x15
        bool mIsCamHRevKeyboard;  // offset: 0x16
        u8 mCamSpdPad;  // offset: 0x17
        u8 mCamSpdMouse;  // offset: 0x18
        u8 mMouseCursorSpd;  // offset: 0x19
        u8 mOthersEffTrans;  // offset: 0x1a
        u8 mFrameRate;  // offset: 0x1b
        u8 mTexResolution;  // offset: 0x1c
        u8 mAntiAliasing;  // offset: 0x1d
        u8 mLightHardwareMode;  // offset: 0x1e
        u8 mShadowQuality;  // offset: 0x1f
        u8 mShadowResolution;  // offset: 0x20
        u8 mShadowDistance;  // offset: 0x21
        u8 mShadow00;  // offset: 0x22
        u8 mShadow01;  // offset: 0x23
        u8 mShadow02;  // offset: 0x24
        u8 mShadowVtxSmoother;  // offset: 0x25
        u8 mShadowLantern;  // offset: 0x26
        u8 mGrassVolume;  // offset: 0x27
        u8 mGrassQuality;  // offset: 0x28
        u8 mGrassDistance;  // offset: 0x29
        u8 mOmDistance;  // offset: 0x2a
        u8 mOmLOD;  // offset: 0x2b
        u8 mChrDispNum;  // offset: 0x2c
        u8 mChrDispDistance;  // offset: 0x2d
        u8 mEftBGQuality;  // offset: 0x2e
        u8 mEftBattleTarget;  // offset: 0x2f
        u8 mEftResponse;  // offset: 0x30
        bool mUILarge;  // offset: 0x31
        u8 mKeyJobLinks[10];  // offset: 0x32
    };
public:
    struct stTitle
    {
    public:
        void setDefault();
        void writeData(MtDataWriter& w, u32 SaveVersion);
        void readData(MtDataReader& r, u32 CurrentVersion, u32 LoadVersion);
    public:
        u8 mLookOpMovie;  // offset: 0x0
        bool mIsFirstOption;  // offset: 0x1
    };
public:
    struct stTutorialGuide
    {
    public:
        enum
        {
            LATEST_TUTORIAL_GUIDE_NUM = 5,
            TUTORIAL_GUIDE_NUM = 512,
            TUTORIAL_GUIDE_WORK_NUM = 16,
            TUTORIAL_GUIDE_NUM_OLD = 256,
            TUTORIAL_GUIDE_WORK_NUM_OLD = 8,
        };
    public:
        void setDefault();
        void writeData(MtDataWriter& w, u32 SaveVersion);
        void readData(MtDataReader& r, u32 CurrentVersion, u32 LoadVersion);
    public:
        u32 mFinishTutorial[16];  // offset: 0x0
        u32 mLatestTutorial[5];  // offset: 0x40
    };
public:
    struct stAreaMasterTalk
    {
    public:
        enum
        {
            AREA_NUM_LATEST = 16,
            AREA_WORK_NUM = 1,
        };
    public:
        void setDefault();
        void writeData(MtDataWriter& w, u32 SaveVersion);
        void readData(MtDataReader& r, u32 CurrentVersion, u32 LoadVersion);
        bool isOn(u32 No);
        void setOn(u32);
    public:
        u32 mIsFirstTalkEnd[1];  // offset: 0x0
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
    cStorageData();
    // Address: 0x01ac9400 - 0x01ac9401 (1 bytes)
    virtual ~cStorageData() {}
    virtual void save(MtDataWriter& w, u32 SaveVersion);  // vtable slot 6
    virtual void load(MtDataReader& r, u32 CurrentVersion, u32 LoadVersion);  // vtable slot 7
public:
    u32 mDataU8;  // offset: 0x8
    u32 mDataU16;  // offset: 0xc
    u32 mDataU32;  // offset: 0x10
    stOptionDataSystem mOptionSys;  // offset: 0x14
    stTitle mTitle;  // offset: 0x50
    stTutorialGuide mTutorialGuide;  // offset: 0x54
    stAreaMasterTalk mAreaMasterTalk;  // offset: 0xa8
    static MyDTI DTI;
};

class sSavedataExt : public sSavedata
{
public:
    class MyDTI;
    struct stSaveDataInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stSaveDataInfo
    {
    public:
        MT_CTSTR mDirectoryPostfixName;  // offset: 0x0
        MT_CTSTR mDataPath;  // offset: 0x8
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
    sSavedataExt();
    virtual ~sSavedataExt();
    virtual void move();  // vtable slot 7
    sSavedata::RESULT saveData(SAVEDATA_TYPE Type);
    sSavedata::RESULT saveDataOverwrite(SAVEDATA_TYPE Type);
    sSavedata::RESULT saveDataNewData(SAVEDATA_TYPE Type);
    sSavedata::RESULT saveDataList(SAVEDATA_TYPE Type);
    sSavedata::RESULT saveEditData(const cEditParam& EditParam, MT_CTSTR name, MT_CTSTR comment, MT_CTSTR sex);
    sSavedata::RESULT loadData(SAVEDATA_TYPE Type);
    sSavedata::RESULT loadDataList(SAVEDATA_TYPE Type);
    void settingSaveDataConfig();
    void setLoadData(SAVEDATA_TYPE Type);
    bool isBusy();
    bool setSaveUtilContent();
    bool beginExistCheck();
    u32 getSavedataSize();
    u32 getRequestSavedataSize();
    u32 getRequireSaveDataHDDSizeKB(MT_CTSTR DirName);
    bool beginHddSpaceCheck(u32 SaveDataSize);
    bool isHddSpaceCheckBusy();
    void setCheckTrophySize(bool);
    bool isCheckTrophySize();
    u32 getNeedHddSizeKB();
    cStorageData& getStorageData();
    cStorageDataEdit& getStorageDataEdit();
    bool setSaveInfo(SAVEDATA_TYPE Type);
    MT_CTSTR getDirectoryPostfixName(SAVEDATA_TYPE Type);
    MT_CTSTR getDataPath(SAVEDATA_TYPE Type);
    void copySaveHeader(cStorageDataBase::UserHeader& dstHeader, const cStorageDataBase::UserHeader& srcheader);
protected:
    cStorageDataBase* getStorageDataBase(SAVEDATA_TYPE Type);
    sSavedata::RESULT saveData(MT_CTSTR DirName, cStorageDataBase* pStorageData, bool isNewData);
    void setSaveData(cStorageDataBase& StorageData, u32 SaveVersion);
    bool setSaveUserHeaderData(cStorageDataBase& StorageData);
    void setLoadData(cStorageDataBase* pStorageData, u32 CurrentVersion, u32 LoadVersion);
    bool setLoadUserHeaderData(cStorageDataBase& StorageData);
    sSavedata::RESULT saveDataList(MT_CTSTR DirName, cStorageDataBase* pStorageData);
    sSavedata::RESULT loadDataList(MT_CTSTR DirName, cStorageDataBase* pStorageData);
    sSavedata::RESULT deleteDataList(MT_CTSTR DirName);
    void setGameTitle();
protected:
    u32 mSaveVersion;  // offset: 0x14bc
    u32 mLoadVersion;  // offset: 0x14c0
    u32 mCurrentVersion;  // offset: 0x14c4
    cStorageData mStorageData;  // offset: 0x14c8
    cStorageDataEdit mStorageDataEdit;  // offset: 0x1578
    void* mpSaveBuff;  // offset: 0x17e8
    void* mpSaveUserHeaderBuff;  // offset: 0x17f0
    u32 mLauncherSaveVersion;  // offset: 0x17f8
    u32 mLauncherLoadVersion;  // offset: 0x17fc
    u32 mLauncherCurrentVersion;  // offset: 0x1800
    void* mpLauncherSaveBuff;  // offset: 0x1808
    bool mIsCheckTrophySize;  // offset: 0x1810
    u32 mNeedHddSizeKB;  // offset: 0x1814
public:
    static MyDTI DTI;
    static const u32 DATA_VERSION_NODATA = 0;
    static const u32 DATA_VERSION = 16777242;
    static const u32 SAVE_DATA_SIZE = 10240;
    static const u32 SAVE_DATA_USER_HEADER_SIZE = 1024;
    static const u32 LAUNCHER_DATA_VERSION = 16777216;
    static const u32 LAUNCHER_SAVE_DATA_SIZE = 1024;
    static const u32 REQUEST_SAVE_DATA_SIZE = 102400;
    static const u32 SAVE_STILL_ICON_SIZE = 122880;
    static const u32 SAVE_BG_IMAGE_SIZE = 1228800;
protected:
    static const stSaveDataInfo mSaveDataInfo[];
};

// Inline, no code of its own: checked where it is inlined.
inline cStorageDataBase::cStorageDataBase() {
}
