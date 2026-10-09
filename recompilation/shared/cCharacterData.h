#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Community.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "nAbility.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "nHuman.h"
#include "nJobParam.h"
#include "nNet.h"

// Forward declarations
class BitReader;
class BitWriter;
class CDataCharacterItemSlotInfo;
class CDataCharacterMsgSet;
class CDataCommonU8;
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class aStage;
class cEquipData;
class cGUIUtility;
class cpJob02;
namespace nCharacterData { struct stCharacterName; }
namespace nCharacterData { struct stChatCstmCh; }
namespace nCharacterData { struct stEquipData; }
namespace nCharacterData { struct stMessageSet; }
namespace nJobParam { class cHumanBaseInfo; }
namespace nJobParam { class cJobInfo; }
namespace nNet { struct stClanEmblem; }
namespace nSessionManager { class cNetSessionManager; }
class sNetworkExt;

// Declarations
class cCharacterData;

// Type aliases from DWARF
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CHAR_NAME = nCharacterData::stCharacterName;
using CharacterMsgSetVec = MtTypedArray<CDataCharacterMsgSet>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using cAIPawnTalkMotSituationArray = nDDOUtility::cArray<unsigned short, 10>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cCharacterData : public MtObject
{
    // inferred: aStage::resetTutorialEquip names sGame::mCharData.mCharData.mEquipData
    friend class aStage;
    // inferred: cGUIUtility::IsChargeAttributeEnable names sGame::mCharData.mCharData.mOption.mIsDispCharges
    friend class cGUIUtility;
    // inferred: cpJob02::update names sGame::mCharData.mCharData.mOption.mIsCamDrama
    friend class cpJob02;
    // inferred: nSessionManager::cNetSessionManager::createFlow names sGame::mCharData.mCharData.mMatchProfile.mInviteWait
    friend class nSessionManager::cNetSessionManager;
    // inferred: sNetworkExt::isClanLeader names sGame::mCharData.mCharData.mCardClan.mMyPost
    friend class sNetworkExt;
public:
    enum
    {
        PERSONAL_TYPE_NONE = 0,
        PERSONAL_TYPE_PLAYER = 1,
        PERSONAL_TYPE_MAIN_PAWN = 2,
        PERSONAL_TYPE_SUPPORT_PAWN = 3,
        PERSONAL_TYPE_MAX = 4,
    };
public:
    class MyDTI;
    struct stCharacterData;
    struct stOptionData;
    struct stCharacterEdit;
    struct SCM;
    struct stSearchFilterSetting;
    struct stMatchProfile;
    struct stCardClan;
    struct stCardHistory;
    struct stCardAchievement;
    struct stCardDogmaOrb;
    struct stCardJobOrbTree;
    struct stCardArisenInfo;
    struct stItemSlotData;
    struct stCheckPawnHistoryData;
    struct stTutorialGuide;
    struct stJobMasterInfo;
    struct stAreaMasterInfo;
    struct stEnteredLandInfo;
    struct stPawnData;
    struct stCardPawnRental;
    struct stCardPawnOwner;
    struct stCardPawnValue;
    struct stCardPawnTotalValue;
public:
    using cCardPawnRentalList = nDDOUtility::cArray<cCharacterData::stCardPawnRental, 20>;
    using cCardPawnTotalValueList = nDDOUtility::cArray<cCharacterData::stCardPawnValue, 3>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stOptionData
    {
    public:
        struct stNameDisp;
    public:
        struct stNameDisp
        {
        public:
            static u8 GetNameType(u8 nameDispType);
            u8 getNameType() const;
            bool serialize(BitWriter& w) const;
            bool deserialize(BitReader& r, u32 version);
        public:
            u8 mType;  // offset: 0x0
            bool mClanName;  // offset: 0x1
        };
    public:
        void setDefaultData();
        bool serialize(BitWriter& w) const;
        bool deserialize(BitReader& r, u32 version, u32 releaseVersion);
        void copyData(const cCharacterData::stOptionData& src);
        nNet::PAWN_SHARE_RANGE getHeaderShareRange() const;
    public:
        u8 mOnlineStatus;  // offset: 0x0
        bool mIsCamHRevPad;  // offset: 0x1
        bool mIsCamVRevKeyboard;  // offset: 0x2
        bool mIsCamHRevKeyboard;  // offset: 0x3
        bool mIsCamRevise;  // offset: 0x4
        bool mIsCamDrama;  // offset: 0x5
        u8 mCamRangeMagic;  // offset: 0x6
        u8 mCamRangeBow;  // offset: 0x7
        u8 mCamPosType;  // offset: 0x8
        u8 mCamSpdPad;  // offset: 0x9
        u8 mCamSpdKeyboard;  // offset: 0xa
        bool mIsMenuWindowOffAuto;  // offset: 0xb
        u8 mDefaultRimWarpTabPos;  // offset: 0xc
        u8 mDefaultMenuWindowSize;  // offset: 0xd
        bool mIsEnableChgMenuWindowSize;  // offset: 0xe
        bool mIsDirectChat;  // offset: 0xf
        bool mIsDispTelop;  // offset: 0x10
        bool mIsPartyBattleBGM;  // offset: 0x11
        bool mIsDispHeadArmorPl;  // offset: 0x12
        bool mIsDispHeadArmorPawn;  // offset: 0x13
        bool mIsDispLanternPl;  // offset: 0x14
        bool mIsDispLanternPawn;  // offset: 0x15
        u32 mPlayerIdlingEmotion;  // offset: 0x18
        u8 mPlayerIdlingEmotionTime;  // offset: 0x1c
        bool mIsDialogSell;  // offset: 0x1d
        bool mIsDialogSellCraftItem;  // offset: 0x1e
        bool mIsRotMiniMap;  // offset: 0x1f
        u8 mAlphaMiniMap;  // offset: 0x20
        bool mIsMapVRev;  // offset: 0x21
        bool mIsMapHRev;  // offset: 0x22
        bool mIsMapDispName;  // offset: 0x23
        bool mIsMiniMapAutoScale;  // offset: 0x24
        bool mIsDispCharges;  // offset: 0x25
        bool mIsTutorialAnnounce;  // offset: 0x26
        bool mIsMatchingAnnounce;  // offset: 0x27
        u8 mAlphaHUDCmn;  // offset: 0x28
        bool mIsQuestActiveAuto;  // offset: 0x29
        bool mIsDispQuestGuide;  // offset: 0x2a
        bool mIsQuestGuideAuto;  // offset: 0x2b
        u8 mQuestGuidePrio;  // offset: 0x2c
        bool mIsDyingFilterDisp;  // offset: 0x2d
        bool mIsMailBoxDispWarning;  // offset: 0x2e
        u8 mHeaderDispType;  // offset: 0x2f
        stNameDisp mHeaderNameDispMine;  // offset: 0x30
        stNameDisp mHeaderNameDispParty;  // offset: 0x32
        stNameDisp mHeaderNameDispOther;  // offset: 0x34
        bool mIsHeaderNameNpcName;  // offset: 0x36
        bool mIsHeaderNameNpcClass;  // offset: 0x37
        bool mIsHeaderNameOmName;  // offset: 0x38
        stNameDisp mChatLogNameDisp;  // offset: 0x39
        bool mIsChatLogTimeStamp;  // offset: 0x3b
        u8 mAlphaChat;  // offset: 0x3c
        u8 mChatChFilterColor[12];  // offset: 0x3d
        u8 mChatChFilterSE[12];  // offset: 0x49
        bool mIsClockDispPing;  // offset: 0x55
        bool mIsClockDispTime;  // offset: 0x56
        u8 mClockDispType;  // offset: 0x57
        bool mIsClockDispCh;  // offset: 0x58
        bool mIsEngageDisp;  // offset: 0x59
        bool mIsAchievementDispAnnounce;  // offset: 0x5a
        bool mIsRewardBoxDispWarning;  // offset: 0x5b
        u8 mPlCardOnView;  // offset: 0x5c
        u8 mPawnCardOnView;  // offset: 0x5d
        bool mIsClanNtc;  // offset: 0x5e
    };
public:
    struct stCharacterEdit
    {
    public:
        void init();
        void copyData(const cCharacterData::stCharacterEdit& src);
    public:
        u32 mVersion;  // offset: 0x0
        CHAR_NAME mName;  // offset: 0x4
        u8 mSex;  // offset: 0x1a
        u8 mBodyType;  // offset: 0x1b
        u32 mFlag;  // offset: 0x1c
        s32 mHair;  // offset: 0x20
        s32 mBeard;  // offset: 0x24
        s32 mMakeup;  // offset: 0x28
        s32 mScar;  // offset: 0x2c
        s32 mVoice;  // offset: 0x30
        s32 mVoicePitch;  // offset: 0x34
        s32 mRace;  // offset: 0x38
        s32 mPersonality;  // offset: 0x3c
        s32 mSpeechFreq;  // offset: 0x40
        s32 mEyePresetNo;  // offset: 0x44
        s32 mNosePresetNo;  // offset: 0x48
        s32 mMouthPresetNo;  // offset: 0x4c
        s32 mEyebrowTexNo;  // offset: 0x50
        s32 mColorSkin;  // offset: 0x54
        s32 mColorHair;  // offset: 0x58
        s32 mColorBeard;  // offset: 0x5c
        s32 mColorEyebrow;  // offset: 0x60
        s32 mColorREye;  // offset: 0x64
        s32 mColorLEye;  // offset: 0x68
        s32 mColorMakeup;  // offset: 0x6c
        f32 mSokutoubu;  // offset: 0x70
        f32 mHitai;  // offset: 0x74
        f32 mMimijyouge;  // offset: 0x78
        f32 mKannkaku;  // offset: 0x7c
        f32 mMabisasijyouge;  // offset: 0x80
        f32 mHanakuchijyouge;  // offset: 0x84
        f32 mAgosakihaba;  // offset: 0x88
        f32 mAgozengo;  // offset: 0x8c
        f32 mAgosakijyouge;  // offset: 0x90
        f32 mHitomiookisa;  // offset: 0x94
        f32 mMeookisa;  // offset: 0x98
        f32 mMekaiten;  // offset: 0x9c
        f32 mMayukaiten;  // offset: 0xa0
        f32 mMimiookisa;  // offset: 0xa4
        f32 mMimimuki;  // offset: 0xa8
        f32 mElfmimi;  // offset: 0xac
        f32 mMikentakasa;  // offset: 0xb0
        f32 mMikenhaba;  // offset: 0xb4
        f32 mHohoboneryou;  // offset: 0xb8
        f32 mHohobonejyouge;  // offset: 0xbc
        f32 mHohoniku;  // offset: 0xc0
        f32 mErahonejyouge;  // offset: 0xc4
        f32 mErahonehaba;  // offset: 0xc8
        f32 mHanajyouge;  // offset: 0xcc
        f32 mHanahaba;  // offset: 0xd0
        f32 mHanatakasa;  // offset: 0xd4
        f32 mHanakakudo;  // offset: 0xd8
        f32 mKuchihaba;  // offset: 0xdc
        f32 mKuchiatsusa;  // offset: 0xe0
        f32 mEyebrowUVOffsetX;  // offset: 0xe4
        f32 mEyebrowUVOffsetY;  // offset: 0xe8
        f32 mWrinkle;  // offset: 0xec
        f32 mWrinkleAlbedoBlendRate;  // offset: 0xf0
        f32 mWrinkleDetailNormalPower;  // offset: 0xf4
        f32 mMuscleAlbedoBlendRate;  // offset: 0xf8
        f32 mMuscleDetailNormalPower;  // offset: 0xfc
        f32 mHeight;  // offset: 0x100
        f32 mHeadSize;  // offset: 0x104
        f32 mNeckOffset;  // offset: 0x108
        f32 mNeckScale;  // offset: 0x10c
        f32 mUpperBodyScaleX;  // offset: 0x110
        f32 mBellySize;  // offset: 0x114
        f32 mTeatScale;  // offset: 0x118
        f32 mTekubiSize;  // offset: 0x11c
        f32 mKoshiOffset;  // offset: 0x120
        f32 mKoshiSize;  // offset: 0x124
        f32 mAnkleOffset;  // offset: 0x128
        f32 mFat;  // offset: 0x12c
        f32 mMuscle;  // offset: 0x130
        f32 mMotionFilter;  // offset: 0x134
    };
public:
    struct SCM
    {
    public:
        enum EXECTYPE
        {
            EXECTYPE_NONE = 0,
            EXECTYPE_MENU = 1,
            EXECTYPE_USEITEM = 2,
            EXECTYPE_MYPHRASE = 3,
            EXECTYPE_TMPPHRASE = 4,
            EXECTYPE_EMOTION = 5,
            EXECTYPE_PAWNORDER = 6,
            EXECTYPE_MAX = 7,
        };
        enum PLTBTN
        {
            PLTBTN_SCM_RU = 0,
            PLTBTN_SCM_RD = 1,
            PLTBTN_SCM_RL = 2,
            PLTBTN_SCM_RR = 3,
            PLTBTN_SCM_MAX = 4,
        };
        enum PLTBTN_SCC
        {
            PLTBTN_SCC_LU = 0,
            PLTBTN_SCC_LD = 1,
            PLTBTN_SCC_LL = 2,
            PLTBTN_SCC_LR = 3,
            PLTBTN_SCC_RU = 4,
            PLTBTN_SCC_RD = 5,
            PLTBTN_SCC_RL = 6,
            PLTBTN_SCC_RR = 7,
            PLTBTN_SCC_MAX = 8,
        };
    public:
        struct stSCMPlt;
        struct stSCCPlt;
    public:
        using stScmPltArrayList = nDDOUtility::cArray<nDDOUtility::cArray<cCharacterData::SCM::stSCMPlt, 4>, 3>;
        using stSccPltArrayList = nDDOUtility::cArray<nDDOUtility::cArray<cCharacterData::SCM::stSCCPlt, 8>, 3>;
    public:
        struct stSCMPlt
        {
        public:
            stSCMPlt();
            void init();
            void copyData(const cCharacterData::SCM::stSCMPlt& src);
        public:
            u32 mMenuId;  // offset: 0x0
            union
            {
            public:
                struct
                {
                public:
                    u8 mU8Data0;  // offset: 0x0
                    u8 mU8Data1;  // offset: 0x1
                    u8 mU8Data2;  // offset: 0x2
                    u8 mU8Data3;  // offset: 0x3
                };  // offset: 0x0
                u32 mU32Data;  // offset: 0x0
            };  // offset: 0x4
            f32 mF32Data;  // offset: 0x8
            u8 mExecType;  // offset: 0xc
            static const u32 PLTNAMEBUF_MAX = 256;
        };
    public:
        struct stSCCPlt
        {
        public:
            stSCCPlt();
            void init();
            void copyData(const cCharacterData::SCM::stSCCPlt& src);
        public:
            u8 mType;  // offset: 0x0
            u8 mCtgr;  // offset: 0x1
            u32 mId;  // offset: 0x4
        };
    public:
        static const u32 PAGE_MAX = 3;
    };
public:
    struct stSearchFilterSetting
    {
    public:
        enum
        {
            SEX_MALE = 1,
            SEX_FEMALE = 2,
            SEX_ALL = 3,
            SEX_START = 1,
        };
        enum
        {
            JOB_ALL = -1,
        };
        enum
        {
            SKILL_ATTR_NONE = 0,
            SKILL_ATTR_HEAL = 1,
            SKILL_ATTR_FIRE = 2,
            SKILL_ATTR_ICE = 4,
            SKILL_ATTR_THUNDER = 8,
            SKILL_ATTR_HOLY = 16,
            SKILL_ATTR_DARK = 32,
            SKILL_ATTR_ALL = 63,
        };
        enum
        {
            COMMUNITY_NONE = 0,
            COMMUNITY_FRIEND = 1,
            COMMUNITY_CLAN = 2,
            COMMUNITY_PARTY = 4,
            COMMUNITY_GROUP = 8,
            COMMUNITY_ALL = 15,
        };
        enum
        {
            ACHIVEMENT_NONE = 0,
            ACHIVEMENT_STORY_FAST = 1,
            ACHIVEMENT_SAME_SET_Q = 2,
            ACHIVEMENT_ALL = 3,
        };
        enum
        {
            CLAN_NAME_TYPE_NONE = 0,
            CLAN_NAME_TYPE_FULL = 1,
            CLAN_NAME_TYPE_SHORT = 2,
        };
        enum
        {
            FILTER_TYPE_PARTY = 0,
            FILTER_TYPE_CHAR = 1,
            FILTER_TYPE_QUICK = 2,
            FILTER_TYPE_PAWN = 3,
            FILTER_TYPE_CLAN = 4,
            FILTER_TYPE_ENTRY_BOARD = 5,
        };
    public:
        void setDefaultData();
        void setSearchFilter(s32 filterType);
        void initSearchFilter(s32 filterType);
        void addSearchType(MtTypedArray<CDataCommonU8>& List, u8 type);
        void copyData(const cCharacterData::stSearchFilterSetting& src, u32 version);
        bool getJobSetting(s32 job) const;
        void setJobSetting(s32 job);
        void clearJobSetting(s32 job);
        void setJobSetting(s32 job, bool b);
        void reverseJobSetting(s32 job);
    public:
        MT_CHAR mSettingName[49];  // offset: 0x0
        u8 mSex;  // offset: 0x31
        bool mJobSetting;  // offset: 0x32
        u32 mJob;  // offset: 0x34
        bool mRankSetting;  // offset: 0x38
        u32 mRankMin;  // offset: 0x3c
        u32 mRankMax;  // offset: 0x40
        bool mSkillSetting;  // offset: 0x44
        u32 mSkillBit;  // offset: 0x48
        bool mOrbSetting;  // offset: 0x4c
        u32 mOrbMin;  // offset: 0x50
        u32 mOrbMax;  // offset: 0x54
        u8 mCommunity;  // offset: 0x58
        u8 mPlayPurpose1;  // offset: 0x59
        u8 mPlayPurpose2;  // offset: 0x5a
        u8 mPlayStyle;  // offset: 0x5b
        u8 mPartyNum;  // offset: 0x5c
        u8 mPawnNum;  // offset: 0x5d
        u8 mAchivement;  // offset: 0x5e
        u8 mPersona;  // offset: 0x5f
        bool mCraftRankSetting;  // offset: 0x60
        u32 mCraftRankMin;  // offset: 0x64
        u32 mCraftRankMax;  // offset: 0x68
        bool mCraftSkillSetting[10];  // offset: 0x6c
        u32 mCraftSkillMin[10];  // offset: 0x78
        u32 mCraftSkillMax[10];  // offset: 0xa0
        u8 mQuickPartyNum;  // offset: 0xc8
        bool mQuickPawnJoin;  // offset: 0xc9
        bool mQuickPartyBalance;  // offset: 0xca
        bool mQuickLevelBalance;  // offset: 0xcb
        u8 mClanNameType;  // offset: 0xcc
        MT_CHAR mClanName[13];  // offset: 0xcd
        u32 mClanMotto;  // offset: 0xdc
        u32 mClanDay;  // offset: 0xe0
        u32 mClanHour;  // offset: 0xe4
        u32 mClanFeature;  // offset: 0xe8
        bool mMemberNumSetting;  // offset: 0xec
        u32 mMemberNumMin;  // offset: 0xf0
        u32 mMemberNumMax;  // offset: 0xf4
        bool mItemRankSetting;  // offset: 0xf8
        u32 mItemRankMin;  // offset: 0xfc
        u32 mItemRankMax;  // offset: 0x100
        nCharacterData::stCharacterName mCharacterName;  // offset: 0x104
        MT_CHAR mPawnName[13];  // offset: 0x11a
        bool mPasswordNG;  // offset: 0x127
        bool mIgnoreName;  // offset: 0x128
    };
public:
    struct stMatchProfile
    {
    public:
        void setDefaultData();
        void setServer();
        void copyData(const cCharacterData::stMatchProfile& src, u32 version);
    public:
        u8 mPlayPurposeMain;  // offset: 0x0
        u8 mPlayPurposeSub;  // offset: 0x1
        u8 mPlayStyle;  // offset: 0x2
        bool mInviteWait;  // offset: 0x3
        u32 mEntryJob;  // offset: 0x4
        MT_CHAR mComment[217];  // offset: 0x8
    };
public:
    struct stCardClan
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardClan& src, u32 version);
    public:
        bool mIsJoin;  // offset: 0x0
        nNet::stClanEmblem mEmblem;  // offset: 0x1
        MT_CHAR mName[13];  // offset: 0x5
        u16 mMemberNum;  // offset: 0x12
        u8 mRank;  // offset: 0x14
        u8 mMyPost;  // offset: 0x15
    };
public:
    struct stCardHistory
    {
    public:
        struct _stCardHistory1;
    public:
        struct _stCardHistory1
        {
        public:
            u16 Type;  // offset: 0x0
            u16 LocalType;  // offset: 0x2
            u32 Value0;  // offset: 0x4
            u32 Value1;  // offset: 0x8
            u64 Time;  // offset: 0x10
        };
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardHistory& src, u32 Version);
    public:
        _stCardHistory1 mData[20];  // offset: 0x0
        u32 mDataNum;  // offset: 0x1e0
    };
public:
    struct stCardAchievement
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardAchievement& src, u32 Version);
    public:
        u16 mCategoryNum[6];  // offset: 0x0
        u16 mCategoryMaxNum[6];  // offset: 0xc
    };
public:
    struct stCardDogmaOrb
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardDogmaOrb& src, u32 Version);
    public:
        u16 mReleaseNum[4][5];  // offset: 0x0
    };
public:
    struct stCardJobOrbTree
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardJobOrbTree&, u32);
    public:
        f32 mRate[10];  // offset: 0x0
    };
public:
    struct stCardArisenInfo
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardArisenInfo& src, u32 Version);
    public:
        u16 mBgNo;  // offset: 0x0
        u16 mTitleNo;  // offset: 0x2
        u16 mTitleUId;  // offset: 0x4
        u16 mMotNo;  // offset: 0x6
        u32 mMotFrame;  // offset: 0x8
    };
public:
    struct stItemSlotData
    {
    public:
        void setDefaultData();
        void copyData(const MtTypedArray<CDataCharacterItemSlotInfo>& list);
        void copyData(const cCharacterData::stItemSlotData& src, u32 version);
    public:
        u16 mItemBagCategorySlot[33];  // offset: 0x0
    };
public:
    struct stCheckPawnHistoryData
    {
    public:
        bool serialize(BitWriter& w) const;
        bool deserialize(BitReader& r, u32 version);
        void setDefaultData();
    public:
        u32 mPawnId;  // offset: 0x0
        u64 mCheckDate;  // offset: 0x8
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
            TUTORIAL_GUIDE_INIT_VERSION = 5,
        };
    public:
        void setDefault();
        void copyData(const cCharacterData::stTutorialGuide& Src);
        bool writeData(BitWriter& w, u32 SaveVersion) const;
        void readData(BitReader& r, u32 CurrentVersion, u32 LoadVersion);
    public:
        u32 mFinishTutorial[16];  // offset: 0x0
        u32 mLatestTutorial[5];  // offset: 0x40
    };
public:
    struct stJobMasterInfo
    {
    public:
        enum
        {
            JOBMASTER_TALK_NUM = 9,
            JOBMASTER_SKILL_TALK_NUM = 9,
            JOBMASTER_TALK_WORK_NUM = 1,
            JOBMASTER_SKILL_TALK_WORK_NUM = 1,
            JOBMASTER_INIT_VERSION = 6,
            JOBMASTER_SKILL_TALK_INIT_VERSION = 13,
        };
    public:
        void setDefault();
        void copyData(const cCharacterData::stJobMasterInfo& Src);
        bool writeData(BitWriter& w, u32 SaveVersion) const;
        void readData(BitReader& r, u32 CurrentVersion, u32 LoadVersion);
        void onJobMasterTalked(u32 JobId);
        bool isJobMasterTalked(u32 JobId);
        void onJobMasterSkillTalked(u32 JobId);
        bool isJobMasterSkillTalked(u32 JobId);
    public:
        u32 mJobMasterTalked[1];  // offset: 0x0
        u32 mJobMasterSkillTalked[1];  // offset: 0x4
    };
public:
    struct stAreaMasterInfo
    {
    public:
        enum
        {
            AREAMASTER_TALK_NUM = 16,
            AREAMASTER_TALK_WORK_NUM = 1,
            AREAMASTER_TALK_INIT_VERSION = 14,
        };
    public:
        void setDefault();
        void copyData(const cCharacterData::stAreaMasterInfo& Src);
        bool writeData(BitWriter& w, u32 SaveVersion) const;
        void readData(BitReader& r, u32 CurrentVersion, u32 LoadVersion);
        void onAreaMasterTalked(u32 AreaId);
        bool isAreaMasterTalked(u32 AreaId);
    public:
        u32 mAreaMasterTalked[1];  // offset: 0x0
    };
public:
    struct stEnteredLandInfo
    {
    public:
        enum
        {
            LAND_ENTERED_NUM = 16,
            LAND_ENTERED_WORK_NUM = 1,
            LAND_ENTERED_INIT_VERSION = 16,
        };
    public:
        void setDefault();
        void copyData(const cCharacterData::stEnteredLandInfo& Src);
        bool writeData(BitWriter& w, u32 SaveVersion) const;
        void readData(BitReader& r, u32 CurrentVersion, u32 LoadVersion);
        void enterLand(u32 LandId);
        bool isEnteredLand(u32 LandId);
    public:
        u32 mEnteredLand[1];  // offset: 0x0
    };
public:
    struct stCardPawnOwner
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardPawnOwner&, u32);
    public:
        u32 mOwnerId;  // offset: 0x0
        MT_CHAR mFirstName[13];  // offset: 0x4
        MT_CHAR mLastName[9];  // offset: 0x11
        MT_CHAR mClanName[4];  // offset: 0x1a
    };
public:
    struct stCardPawnValue
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardPawnValue&, u32);
    public:
        u8 mType;  // offset: 0x0
        u8 mValue;  // offset: 0x1
        u8 mCommentNo;  // offset: 0x2
    };
public:
    struct stCardPawnTotalValue
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardPawnTotalValue&, u32);
    public:
        u32 mRentalNum;  // offset: 0x0
        u32 mBattleNum;  // offset: 0x4
        u32 mCraftNum;  // offset: 0x8
        cCharacterData::cCardPawnTotalValueList mValues;  // offset: 0xc
    };
public:
    struct stCharacterData
    {
    public:
        enum VALID_INFO
        {
            VALID_INFO_NONE = 0,
            VALID_INFO_BASE = 1,
            VALID_INFO_STATUS = 2,
            VALID_INFO_SKILL = 4,
            VALID_INFO_HISTORY = 8,
            VALID_INFO_ACHIVEMENT = 16,
            VALID_INFO_ORB = 32,
            VALID_INFO_ALL = -1,
        };
        enum QSTETCF
        {
            QSTETCF_NONE = 1,
            QSTETCF_AMMERGODA = 2,
        };
    public:
        u32 mVersion;  // offset: 0x0
        u32 mReleaseVersion;  // offset: 0x4
        nCharacterData::stMessageSet mMessageSet[6];  // offset: 0x8
        nCharacterData::stEquipData mEquipData;  // offset: 0x1a48
        cEquipData* mpEquipData;  // offset: 0x2270
        cCharacterData::stOptionData mOption;  // offset: 0x2278
        cCharacterData::stCharacterEdit mCharacterEdit;  // offset: 0x22d8
        nJobParam::cJobInfo mJobInfo[10];  // offset: 0x2410
        nJobParam::cHumanBaseInfo mBaseInfo;  // offset: 0x2870
        cCharacterData::SCM::stScmPltArrayList mPltSCMWork;  // offset: 0x28c8
        cCharacterData::SCM::stSccPltArrayList mPltSCCWork;  // offset: 0x2988
        cCharacterData::stSearchFilterSetting mQuickSetting[3];  // offset: 0x2a48
        cCharacterData::stMatchProfile mMatchProfile;  // offset: 0x2dcc
        u32 mQuestEtcF;  // offset: 0x2eb0
        nCharacterData::stChatCstmCh mChatCstmCh[2];  // offset: 0x2eb4
        u8 mCurrentJob;  // offset: 0x2ee4
        u8 mReviveStock;  // offset: 0x2ee5
        u32 mMaxAbilityCost;  // offset: 0x2ee8
        cCharacterData::stCardClan mCardClan;  // offset: 0x2eec
        cCharacterData::stCardHistory mCardHistory;  // offset: 0x2f08
        cCharacterData::stCardAchievement mCardAchievement;  // offset: 0x30f0
        cCharacterData::stCardDogmaOrb mCardDogmaOrb;  // offset: 0x3108
        cCharacterData::stCardJobOrbTree mCardJobOrbTree;  // offset: 0x3130
        cCharacterData::stCardArisenInfo mCardInfo;  // offset: 0x3158
        u32 mValidInfoBit;  // offset: 0x3164
        cCharacterData::stItemSlotData mItemSlotData;  // offset: 0x3168
        cCharacterData::stCheckPawnHistoryData mCheckPawnHistory[16];  // offset: 0x31b0
        cCharacterData::stTutorialGuide mTutorialGuide;  // offset: 0x32b0
        cCharacterData::stJobMasterInfo mJobMasterInfo;  // offset: 0x3304
        cCharacterData::stAreaMasterInfo mAreaMasterInfo;  // offset: 0x330c
        cCharacterData::stEnteredLandInfo mEnteredLandInfo;  // offset: 0x3310
        bool mIsAppraiseTalked;  // offset: 0x3314
        MtStringEx<24> mOnlineID;  // offset: 0x3318
    };
public:
    struct stCardPawnRental
    {
    public:
        void setDefaultData();
        void copyData(const cCharacterData::stCardPawnRental&, u32);
    public:
        cCharacterData::stCardPawnOwner mSubject;  // offset: 0x0
        u64 mReturnDate;  // offset: 0x20
        u64 mAdvTime;  // offset: 0x28
        u8 mAdvNum;  // offset: 0x30
        u8 mCraftNum;  // offset: 0x31
        u32 mKillEmNum;  // offset: 0x34
        cCharacterData::stCardPawnValue mValue;  // offset: 0x38
    };
public:
    struct stPawnData
    {
    public:
        enum VALID_INFO
        {
            VALID_INFO_NONE = 0,
            VALID_INFO_BASE = 1,
            VALID_INFO_PROFILE = 2,
            VALID_INFO_HISTORY = 8,
            VALID_INFO_TOTALSCORE = 16,
            VALID_INFO_ORB = 32,
            VALID_INFO_ALL = -1,
        };
    public:
        struct Ability;
    public:
        using cSkillLvCustomArray = nDDOUtility::cArray<nDDOUtility::cArray<nHuman::HM_SKILL_LV, 20>, 10>;
        using cSkillLvNormalArray = nDDOUtility::cArray<nDDOUtility::cArray<nHuman::HM_SKILL_LV, 10>, 10>;
        using cSkillPallet = nDDOUtility::cArray<nHuman::CUSTOM_SKILL_ENUM, 2>;
        using cAbilityArray = nDDOUtility::cArray<cCharacterData::stPawnData::Ability, 10>;
        using cSkillLvNormal = nDDOUtility::cArray<nHuman::HM_SKILL_LV, 10>;
        using cSkillLvCustom = nDDOUtility::cArray<nHuman::HM_SKILL_LV, 20>;
    public:
        struct Ability
        {
        public:
            nAbility::ABILITY_ID mAbilityId;  // offset: 0x0
            s32 mLevel;  // offset: 0x4
        };
    public:
        bool isValid() const;
        void setValid(bool flag);
        u16 getLv() const;
        void addLv(u16);
        void setLv(u16 lv);
        u32 getCraftExt(u32);
        void addCraftExt(u32, u32);
        u16 getAutoMotion(u32 situation) const;
        void setAutoMotion(u32 situation, u16 val);
        const nJobParam::cJobInfo* getJobInfo(u32 JobId) const;
        bool serialize(BitWriter&, u32) const;
        bool deserialize(BitReader&);
        void setDefaultData();
        u8 getCurrentJob() const;
        void setCurrentJob(u8 job);
        CHAR_NAME& getName();
        const CHAR_NAME& getName() const;
        void setName(const CHAR_NAME& name);
        MT_CTSTR getFirstName() const;
        void setFirstName(MT_CTSTR name);
        MT_CTSTR getLastName() const;
        void setLastName(MT_CTSTR);
        u8 getSex() const;
        void setSex(u8 sex);
        void setShareRange(u8 range);
        cCharacterData::stCardArisenInfo& getCardArisenInfo();
        u32 getMaxAbilityCost() const;
        void setMaxAbilityCost(u32 cost);
        u32 getValidInfo() const;
        bool isValidInfo(VALID_INFO) const;
        void setValidInfo(VALID_INFO validBit);
    public:
        u32 mMaxAbilityCost;  // offset: 0x0
        u32 mVersion;  // offset: 0x4
        bool mValid;  // offset: 0x8
        nCharacterData::stEquipData mEquipData;  // offset: 0xc
        cEquipData* mpEquipData;  // offset: 0x838
        u16 mLv;  // offset: 0x840
        u8 mStatus;  // offset: 0x842
        u8 mCurrentJob;  // offset: 0x843
        nDDOUtility::cArray<nJobParam::cJobInfo, 10> mJobInfo;  // offset: 0x848
        nJobParam::cHumanBaseInfo mBaseInfo;  // offset: 0xca8
        cSkillLvCustomArray mCustomSkillLv;  // offset: 0xd00
        cSkillLvNormalArray mNormalSkillLv;  // offset: 0x1020
        cSkillPallet mCustomSkillPalletL;  // offset: 0x11b0
        cSkillPallet mCustomSkillPalletR;  // offset: 0x11b8
        cAbilityArray mAbilityInfoList;  // offset: 0x11c0
        u32 mCraftExt[10];  // offset: 0x1210
        u32 mCraftExp;  // offset: 0x1238
        u32 mCraftRank;  // offset: 0x123c
        u32 mCraftRankLimit;  // offset: 0x1240
        u32 mCraftPoint;  // offset: 0x1244
        u32 mAdventureCount;  // offset: 0x1248
        u32 mCraftCount;  // offset: 0x124c
        cCharacterData::stCharacterEdit mCharacterEdit;  // offset: 0x1250
        cAIPawnTalkMotSituationArray mAutoMotion;  // offset: 0x1388
        cCharacterData::cCardPawnRentalList mCardPawnRentalList;  // offset: 0x13a0
        u32 mCardPawnRentalListNum;  // offset: 0x18a0
        cCharacterData::stCardDogmaOrb mCardDogmaOrb;  // offset: 0x18a4
        cCharacterData::stCardJobOrbTree mCardJobOrbTree;  // offset: 0x18cc
        cCharacterData::stCardPawnTotalValue mCardPawnValue;  // offset: 0x18f4
        CCommunityCharacterBaseInfo mOwnerInfo;  // offset: 0x1910
        cCharacterData::stCardArisenInfo mCardInfo;  // offset: 0x1940
        MtString mComment;  // offset: 0x1950
        u32 mRentalCost;  // offset: 0x1958
        u32 mLikability;  // offset: 0x195c
        u8 mShareRange;  // offset: 0x1960
        u32 mValidInfoBit;  // offset: 0x1964
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
    cCharacterData();
    virtual ~cCharacterData();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    bool serialize(BitWriter& w) const;
    bool deserialize(BitReader& r);
private:
    void clearMessageSet(nCharacterData::stMessageSet& msgSet, s32 setIndex);
    void clearChatCstmCh();
public:
    u32 getVersion() const;
    void setVersion(u32 version);
    u32 getReleaseVersion() const;
    void setReleaseVersion(u32 version);
    u8 getSex() const;
    void setSex(u8 sex);
    u8 getCurrentJob() const;
    void setCurrentJob(u8 job);
    s32 getCurrentJobLv() const;
    void setCurrentJobLv(s32 lv);
    CHAR_NAME& getName();
    const CHAR_NAME& getName() const;
    void setName(const CHAR_NAME& name);
    MT_CTSTR getFirstName() const;
    void setFirstName(MT_CTSTR name);
    MT_CTSTR getLastName() const;
    void setLastName(MT_CTSTR name);
    nCharacterData::stMessageSet& getMessageSet(s32 setIndex);
    void setShaRangePlCard(u8 range);
    void setIsClanNtc(bool flag);
    bool isClanNtc();
    nCharacterData::stEquipData& getEquip();
    cEquipData* getEquipData();
    void setEquipData(cEquipData* pEquip);
    void setDefaultCharacterData(bool bAddItem);
    s32 getMessageLinkNum();
    void setServerMessageSet();
    void setMesseageSetPacket(CharacterMsgSetVec& list);
    void execMessageLink(nCharacterData::MESSAGE_LINK no);
    bool getInviteWait() const;
    void setInviteWait(bool flag, bool sendFlag);
    nCharacterData::stChatCstmCh& getChatCstmCh(u32 uIdx);
    void setChatCstmCh(u32, MtString&, u32);
    u8 getReviveStock() const;
    void setReviveStock(u8 stock);
    stOptionData& getOptionData();
    stCharacterEdit& getCharacterEdit();
    SCM::stScmPltArrayList& getPltScmWork();
    SCM::stSccPltArrayList& getPltSccWork();
    const nJobParam::cJobInfo& getJobInfo(u32 job) const;
    void setJobInfo(const nJobParam::cJobInfo& info, u32 job);
    void setJobLv(u32 job, s32 lv);
    const nJobParam::cHumanBaseInfo& getBaseInfo() const;
    void setBaseInfo(const nJobParam::cHumanBaseInfo& info);
    u8 getCurrentJob();
    void setBaseInfo(u8);
    u8 getPlayPurposeMain() const;
    void setPlayPurposeMain(u8 purposeMain);
    u8 getPlayPurposeSub() const;
    void setPlayPurposeSub(u8 purposeSub);
    u8 getPlayStyle() const;
    void setPlayStyle(u8 playStyle);
    u32 getEntryJob() const;
    void setEntryJob(u8 job);
    stSearchFilterSetting& getQuickSetting(u32);
    stMatchProfile& getMatchProfile();
    const stMatchProfile& getMatchProfileConst() const;
    u32 getLastQuickSettingNo() const;
    void setLastQuickSettingNo(u32);
    void setServerMatchProfile();
    void setQuestEtcF(u32);
    void orQuestEtcF(u32 uFlag);
    void xorQuestEtcF(u32);
    void clrQuestEtcF(u32);
    bool isQuestEtcF(u32 uFlag);
    void serializeQuestEtcF(BitWriter& w) const;
    void deserializeQuestEtcF(BitReader& r, u32 Version);
    stCardClan& getCardClan();
    stCardHistory& getCardHistory();
    stCardAchievement& getCardAchievement();
    stCardDogmaOrb& getCardDogmaOrb();
    stCardJobOrbTree& getCardJobOrbTree();
    stCardArisenInfo& getCardArisenInfo();
    const stCardClan& getCardClanConst() const;
    const stCardHistory& getCardHistoryConst() const;
    const stCardAchievement& getCardAchievementConst() const;
    const stCardDogmaOrb& getCardDogmaOrbConst() const;
    const stCardJobOrbTree& getCardJobOrbTreeConst() const;
    const stCardArisenInfo& getCardArisenInfoConst() const;
    stItemSlotData& getItemSlotData();
    stCheckPawnHistoryData* getPawnHistryData(u32 pawnId);
    void setRefPawnHistry(u32 pawnId, const stPawnData* pPawnData);
    void setRefPawnHistry(u32 pawnId, u64 date);
    bool existNewPawnHistry(u32 pawnId, u64 lastDate);
    bool marshalPawnHistry();
    MT_CTSTR getOnlineID() const;
    void setOnlineID(MT_CTSTR pSrc);
    u32 getMaxAbilityCost() const;
    void setMaxAbilityCost(u32 cost);
    u32 getValidInfo() const;
    bool isValidInfo(stCharacterData::VALID_INFO) const;
    void setValidInfo(stCharacterData::VALID_INFO validBit);
    stTutorialGuide* getTutorialGuide();
    stJobMasterInfo* getJobMasterInfo();
    stAreaMasterInfo* getAreaMasterInfo();
    stEnteredLandInfo* getEnteredLandInfo();
    bool isAppraiseTalked();
    void onAppraiseTalked();
    void copyData(const cCharacterData& src);
    cCharacterData(const cCharacterData&);
    cCharacterData& operator=(const cCharacterData&);
    static void setKeyboardSetting(MT_CTSTR titleStr, MT_CTSTR defStr, s32 size);
private:
    stCharacterData mCharData;  // offset: 0x8
    u32 mLastQuickSetting;  // offset: 0x3340
public:
    static MyDTI DTI;
    static const u32 CHARACTER_DATA_VERSION = 19;
};
