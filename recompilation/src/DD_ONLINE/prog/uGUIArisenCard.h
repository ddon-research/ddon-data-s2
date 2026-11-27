#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/CharacterCommon.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "cCharacterData.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "nGUIExt.h"
#include "uGUIBase.h"

// Forward declarations
class CDataArisenProfile;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtTime;
class MtVector2;
class cCharacterData;
class cContextInstHm;
class cContextPlayerInfo;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjTexture;
namespace nGUIExt { struct stNormalSkill; }
namespace nJobParam { class cJobInfo; }
class rAchievementHeader;
class rGUI;
class rGUIMessage;
class uGUIArisenCardPop;
class uGUIArisenCardPopPawn;
class uGUIPopCmd01;
class uGUIPopDetail01;
class uGUIPopSkillInfo;
class uUIMockUp;

// Declarations
class uGUIArisenCard;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class uGUIArisenCard : public uGUIBase
{
public:
    enum
    {
        MOCKUP_ST_WAIT = 0,
        MOCKUP_ST_SETMOT = 1,
    };
    enum
    {
        TAB_PROFILE = 0,
        TAB_STATUS = 1,
        TAB_SKILL = 2,
        TAB_HISTORY = 3,
        TAB_ACHIEVEMENT = 4,
        TAB_NUM = 5,
    };
    enum
    {
        EQUIP_CURSOR_L = 0,
        EQUIP_CURSOR_R = 1,
        EQUIP_CURSOR_NUM = 2,
    };
    enum AC_GUIDE_BIT
    {
        AC_EDIT = 1,
        AC_ITEM_DETAIL = 2,
        AC_GUIDE_NUM = 2,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_TABCHANGE = 67,
        INPUTEVENT_UPDATEABILITY = 68,
        INPUTEVENT_CHANGESKILLMODE = 69,
        INPUTEVENT_CHANGEWATCHEQUIP = 70,
        INPUTEVENT_HISTORYCURSORMOVE = 71,
        INPUTEVENT_CHANGEPAWNPROFILE = 72,
        INPUTEVENT_STARTSUBMENU = 73,
        INPUTEVENT_ORB_PAGE = 74,
    };
    enum
    {
        MGR_ID_EQUIP_H = 0,
        MGR_ID_EQUIP_L = 1,
        MGR_ID_EQUIP_R = 2,
        MGR_ID_SKAB_LR = 0,
        MGR_ID_SKILL = 1,
        MGR_ID_ABILITY_L = 2,
        MGR_ID_ABILITY_R = 3,
    };
    enum
    {
        SKAB_CURSOR_SKILL = 0,
        SKAB_CURSOR_ABILITY_L = 1,
        SKAB_CURSOR_ABILITY_R = 2,
        SKAB_CURSOR_NUM = 3,
        SKAB_CURSOR_ABILITY_START = 1,
    };
    enum
    {
        ABILITY_LINE_START = 0,
        ABILITY_LINE_L = 0,
        ABILITY_LINE_R = 1,
        ABILITY_LINE_NUM = 2,
    };
    enum
    {
        SKILL_LIST_NUM = 10,
        SKILL_MAX = 20,
        NORMAL_SKILL_DISP_MAX = 7,
        NORMAL_SKILL_MAX = 9,
        ABILITY_DISP_X = 2,
        ABILITY_DISP_Y = 5,
        ABILITY_DISP_Y_MAX = 7,
        ABILITY_DISP_MAX = 10,
        ABILITY_LIST_MAX = 14,
        VALUE_STAR_NUM = 5,
        ORB_FULLANIM_FRAME = 9,
        HISTORY_LIST_DISP_MAX = 15,
        HISTORY_LIST_MAX = 17,
        HISTORYPAWN_LIST_DISP_MAX = 5,
        HISTORYPAWN_LIST_MAX = 7,
    };
    enum
    {
        EQICON_L_TOP = 0,
        EQICON_L0 = 0,
        EQICON_L1 = 1,
        EQICON_L2 = 2,
        EQICON_L3 = 3,
        EQICON_L4 = 4,
        EQICON_L5 = 5,
        EQICON_L6 = 6,
        EQICON_L7 = 7,
        EQICON_L_NUM = 8,
        EQICON_RTOP = 8,
        EQICON_R0 = 8,
        EQICON_R1 = 9,
        EQICON_R2 = 10,
        EQICON_R3 = 11,
        EQICON_R4 = 12,
        EQICON_R5 = 13,
        EQICON_R6 = 14,
        EQICON_R7 = 15,
        EQICON_R8 = 16,
        EQICON_NUM = 17,
        EQICON_R_NUM = 9,
    };
    enum
    {
        CONTROL_CATEGORY_EQUIP = 0,
        CONTROL_CATEGORY_SKAB = 0,
    };
    enum
    {
        ORB_NORMAL = 0,
        ORB_JOB = 1,
        ORB_NUM = 2,
    };
    enum
    {
        RENTAL_REVIEW_LOOKS = 0,
        RENTAL_REVIEW_BATTLE = 1,
        RENTAL_REVIEW_CRAFT = 2,
        RENTAL_REVIEW_NUM = 3,
    };
public:
    class MyDTI;
    class cScrollHistoryDispList;
    class cScrollDispSkillList;
    class cScrollDispAbilityList;
    class cScrollSkillList;
    class cScrollAbilityList;
    class cScrollHistoryInfoList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cScrollHistoryDispList : public uGUIBase::cScrollListItemBase
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
        cScrollHistoryDispList();
        virtual ~cScrollHistoryDispList() {}
        cGUIInstAnimation* getInstance();
        void setInstance(cGUIInstAnimation* pInst);
    public:
        cGUIObjMessage* mpName;  // offset: 0x58
        cGUIObjMessage* mpTime;  // offset: 0x60
        cGUIObjTexture* mpEmblem;  // offset: 0x68
        cGUIInstAnimation* mpIcon;  // offset: 0x70
        cGUIObjMessage* mpText;  // offset: 0x78
        cGUIObjTexture* mpStar[5];  // offset: 0x80
        static MyDTI DTI;
    };
public:
    class cScrollDispSkillList : public uGUIBase::cScrollListItemBase
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
        cScrollDispSkillList();
        virtual ~cScrollDispSkillList();
    public:
        cGUIInstAnimation* mpPlate;  // offset: 0x58
        uGUIBase::cReferenceUIIconSkill mIcon;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    class cScrollDispAbilityList : public uGUIBase::cScrollListItemBase
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
        cScrollDispAbilityList();
        virtual ~cScrollDispAbilityList();
    public:
        cGUIInstAnimation* mpPlate;  // offset: 0x58
        uGUIBase::cReferenceUIIconSkill mIcon;  // offset: 0x60
        static MyDTI DTI;
    };
public:
    class cScrollSkillList : public uGUIBase::cScrollListInfoBase
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
        cScrollSkillList();
        cScrollSkillList(f32 Top, f32 MouseTop, f32 Bottom, bool IsCustom, u32 JobId, u32 SkillNo, u32 IconNo, u32 Lv);
        virtual ~cScrollSkillList() {}
    public:
        bool mIsCustomSkill;  // offset: 0x25
        u32 mJobId;  // offset: 0x28
        u32 mSkillNo;  // offset: 0x2c
        u32 mIconNo;  // offset: 0x30
        u32 mLv;  // offset: 0x34
        static MyDTI DTI;
    };
public:
    class cScrollAbilityList : public uGUIBase::cScrollListInfoBase
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
        cScrollAbilityList();
        cScrollAbilityList(f32 Top, f32 Bottom, u32 SkillNo, u32 Lv, u32 Cost, u32 IconNo);
        virtual ~cScrollAbilityList() {}
    public:
        u32 mSkillNo;  // offset: 0x28
        u32 mLv;  // offset: 0x2c
        u32 mCost;  // offset: 0x30
        u32 mIconNo;  // offset: 0x34
        static MyDTI DTI;
    };
public:
    class cScrollHistoryInfoList : public uGUIBase::cScrollListInfoBase
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
    private:
        cScrollHistoryInfoList();
    public:
        cScrollHistoryInfoList(f32 Top, f32 Bottom);
        virtual ~cScrollHistoryInfoList() {}
    public:
        u32 mType;  // offset: 0x28
        u32 mIndex;  // offset: 0x2c
        MtTime mTime;  // offset: 0x30
        static MyDTI DTI;
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
    u32 getMotionMaxFrame(u32 MotNo);
    void setMotion(u32 MotNo, u32 FrameNo, f32 Hokan);
    void setChangeBG(u32 BgNo);
    void startHistoryPage();
    void resetEmotionDisp();
    void setAchievement(u32 Uid, u32 Index);
    uGUIArisenCard(bool isChatSubMenu);
    virtual ~uGUIArisenCard();
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    bool manageEnv();
    void updateMenuDispWait();
    void updateServerWait();
    void updateWait1st();
    void updateWait();
    void updateMatching();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlDecide(cControl::Message* pMsg);
    u32 evCtrlTabLR(cControl::Message* pMsg);
    u32 evCtrlEquipMoveUD(cControl::Message* pMsg);
    u32 evCtrlEquipMouseClick(cControl::Message* pMsg);
    u32 evCtrlEquipMoveLR(cControl::Message* pMsg);
    u32 evCtrlStartSubMenu(cControl::Message* pMsg);
    u32 evCtrlSKABMoveLR(cControl::Message* pMsg);
    u32 evCtrlOrbPage(cControl::Message* pMsg);
    void initMockup();
    void initItemDetail();
    void initDisp();
    void initHeader(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo, u32 ValidInfo);
    void initHeaderPawn(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo, const cCharacterData::stPawnData* pPawn, u32 ValidInfo);
    void initEquip(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo);
    void initProfile(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo, const cCharacterData* pData);
    void initMatchingProfile(const cContextPlayerInfo* pPlInfo, const cCharacterData* pData);
    void initPawnInfo(const cCharacterData::stPawnData* pPawn, u32 PawnType);
    void initHpStamina(const cContextInstHm* pContext);
    const cContextInstHm* getPartyContext(const cContextInstHm* pContext);
    void initStatus(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo, const nJobParam::cJobInfo* pJobInfo, bool IsExpDisp);
    void initSkillAbility();
    void initSkill(const cContextInstHm* pContext, const cContextPlayerInfo* pPlInfo);
    void initAbility(const cContextPlayerInfo* pPlInfo, u32 AbilityMaxCost);
    void initAchievement(const cCharacterData* pData);
    void initHistory(const cCharacterData* pData);
    void initHistoryPawn(const cCharacterData::stPawnData* pPawn);
    void initDevoteOrb(const cCharacterData::stCardDogmaOrb& Orb, const cCharacterData::stCardJobOrbTree& jobOrb, bool isDispJobOrb);
    void initRentalInfo(const cCharacterData::stCardPawnTotalValue& PawnValue);
    void setJobIcon(u32 JobId, u32 JobLv, cGUIInstAnimation* pIcon, cGUIObjMessage* pLv);
    void initTabInfo(u32 ValidInfo);
    void initTabInfoPawn(u32 ValidInfo);
    void updatePageDisp();
    void updateSkillAbility();
    void setElementIcon(cGUIInstAnimation* pIcon, f32 PosX, const cContextPlayerInfo* pPlInfo, s32 Id);
    void setupCustomSkillIcon(u32 Index, cGUIInstance* pInst);
    void updateCustomSkillIcon(u32 Index, cScrollDispSkillList* pDispInfo, cScrollSkillList* pItemInfo);
    void updateNormalSkillIcon(u32 Index, cScrollDispSkillList* pDispInfo, cScrollSkillList* pItemInfo);
    void setupAbilityIcon(cScrollDispAbilityList& List, cGUIInstNull* pInst, f32 PosX, bool IsOrg);
    void updateSkillDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateSkillHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateAbilityDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateAbilityHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateHistoryDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateHistoryHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateHistoryPawnDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateHistoryPawnHide(uGUIBase::cScrollListItemBase* pDispItem);
    s32 getAbilityListXMax(s32 PosY);
    u32 startEditProfile(MtObject* pDummy, MtObject* pUnit);
    u32 startEditPawnProfile(MtObject* pDummy, MtObject* pUnit);
    u32 startEditBG(MtObject* pDummy, MtObject* pUnit);
    u32 startEditPose(MtObject* pDummy, MtObject* pUnit);
    u32 startEditTitle(MtObject* pDummy, MtObject* pUnit);
    void initOrb(cGUIInstAnimation* pInst, f32 PosY, const u16* pOrbRelease);
    void updateOrbPage();
    void changeEquipColumn();
    void updateEquipCursor();
    void initRentalReview(cGUIInstNull* pNull, u32 Idx, f32 PosY, const cCharacterData::stCardPawnTotalValue& PawnValue);
    void setExit();
    s32 getPawnValueFromType(const cCharacterData::stCardPawnTotalValue& PawnValue, u32 Type);
    void initHistoryList(cGUIInstAnimation* pInst, cGUIInstAnimation* pIcon, u32 Index);
    void initHistoryPawnList(cGUIInstAnimation* pInst, cGUIInstAnimation* pIcon, u32 Index);
    void updateBGDisp(u16 BgNo, bool IsSave, bool IsInit);
    void updateAchievementDisp(u32 Uid, u32 Index, bool IsSave, bool IsInit);
    void updateEmotionDisp(u16 EmotionNo, u32 FrameNo, bool IsSave, bool IsInit);
    void initCardEdit(const cCharacterData::stCardArisenInfo* pEditInfo);
    void changeOperateSkillMode(bool IsSkillMode);
    u32 getJobIdForJobList(u32 Index, const cContextPlayerInfo* pPlInfo);
    void updateEquipIcon();
    void offDispItemDetail();
    u32 getIconPos();
    void initSkillDetail();
    void offDispSkillDetail();
    void updateSkillDetail();
    void mgrMockup();
    void startSubMenu();
    bool isEffectiveSkill(u32 SkillId);
    void initHistoryCtrl();
    void reactiveWindowCallBack();
    void updateBtnGuide();
    f32 getPentagonAdjustRate(u32 Num, u32 Total);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rGUIMessage* mpParamGMDRes;  // offset: 0x8d8
    rAchievementHeader* mpAchieveRes;  // offset: 0x8e0
    rGUIMessage* mpMenuCmnGMDRes;  // offset: 0x8e8
    uUIMockUp* mpMockup;  // offset: 0x8f0
    uGUIPopCmd01* mpSubMenu;  // offset: 0x8f8
    uGUIArisenCardPop* mpCardPop;  // offset: 0x900
    uGUIArisenCardPopPawn* mpPawnProfile;  // offset: 0x908
    uGUIPopDetail01* mpItemDetail;  // offset: 0x910
    uGUIPopSkillInfo* mpSkillDetail;  // offset: 0x918
    uGUIBase::cHorizontalList* mpCtrl;  // offset: 0x920
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0x928
    cGUIControlMgr mControls;  // offset: 0x930
    cGUIControlMgr mSKABControls;  // offset: 0xde0
    CDataArisenProfile mEditData;  // offset: 0x1290
    MtString mPawnComment;  // offset: 0x12b8
    u32 mPawnId;  // offset: 0x12c0
    u32 mMockupState;  // offset: 0x12c4
    nGUIExt::stNormalSkill mNormalSkillList[20];  // offset: 0x12c8
    u32 mInitPage;  // offset: 0x1368
    bool mIsPlayer;  // offset: 0x136c
    bool mIsMyData;  // offset: 0x136d
    bool mIsMan;  // offset: 0x136e
    bool mIsMoveInitFunc;  // offset: 0x136f
    u32 mNowPage;  // offset: 0x1370
    s32 mScrollMoveDir;  // offset: 0x1374
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x1378
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x1410
    MtVector2 mEquipPos;  // offset: 0x1468
    uGUIBase::cReferenceUITab mTab;  // offset: 0x1470
    s32 mExecTabNum;  // offset: 0x1520
    s32 mExecTabPage[5];  // offset: 0x1524
    uGUIBase::cReferenceUIIconEquip mIcon[17];  // offset: 0x1540
    u32 mEquipCursorMode;  // offset: 0x2fd0
    uGUIBase::cTexArcLoader mEquipBG;  // offset: 0x2fd8
    uGUIBase::cReferenceUIClanEmblem mClanEmblem;  // offset: 0x3060
    bool mIsMoveMatchingProfile;  // offset: 0x3168
    bool mIsUpdateEditData;  // offset: 0x3169
    uGUIBase::cScrollList mHistoryScrollbar;  // offset: 0x3170
    cScrollHistoryDispList mHistoryList[17];  // offset: 0x3420
    s32 mHistoryListNum;  // offset: 0x3f48
    s32 mHistoryDispNum;  // offset: 0x3f4c
    f32 mHistoryBaseY;  // offset: 0x3f50
    f32 mHistoryOfsY;  // offset: 0x3f54
    bool mIsOperateSkill;  // offset: 0x3f58
    uGUIBase::cScrollList mSkillScrollbar;  // offset: 0x3f60
    cScrollDispSkillList mSkillDispList[10];  // offset: 0x4210
    s32 mCustomSkillNum;  // offset: 0x4d50
    uGUIBase::cScrollList mAbilityScrollbar[2];  // offset: 0x4d60
    cScrollDispAbilityList mAbilityDispList[2][7];  // offset: 0x52c0
    f32 mAbilityBasePosX;  // offset: 0x6280
    f32 mAbilityBasePosY;  // offset: 0x6284
    f32 mAbilityOfsX;  // offset: 0x6288
    f32 mAbilityOfsY;  // offset: 0x628c
    s32 mAbilityNum;  // offset: 0x6290
    s32 mAbilityCursorPosX;  // offset: 0x6294
    s32 mAbilityCursorPosY;  // offset: 0x6298
    bool mIsEditEnable;  // offset: 0x629c
    uGUIBase::cReferenceUIIconJob mOrbJobIcon[10];  // offset: 0x62a0
    uGUIBase::cReferenceUINumPager mPager;  // offset: 0x6610
    cGUIInstNull* mpCustomSkillInst[4];  // offset: 0x66b8
    cGUIInstAnimation* mpLoadIcon;  // offset: 0x66d8
    cGUIInstAnimation* mpMockupBG;  // offset: 0x66e0
    cGUIInstNull* mpItemDetailNull;  // offset: 0x66e8
    cGUIInstNull* mpSubMenuNull;  // offset: 0x66f0
    cGUIInstNull* mpEquipIcon[17];  // offset: 0x66f8
    cGUIInstAnimation* mpEquipLockIcon[17];  // offset: 0x6780
    cGUIInstAnimation* mpHistoryNoList;  // offset: 0x6808
    cGUIInstAnimation* mpHistoryPawnNoList;  // offset: 0x6810
    cGUIObjMessage* mpAchieveName;  // offset: 0x6818
    cGUIObjMessage* mpPawnComment;  // offset: 0x6820
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[2];  // offset: 0x6828
public:
    static MyDTI DTI;
private:
    static const u32 mCTEquipCategoryTable[17];
    static const u32 mCTTabMsgTable[5];
    static const u32 mCTPawnTabMsgTable[5];
    static const u32 mCTAcvPosCnvTbl[6];
    static const u32 mCTAcvNameTbl[6];
    static const u32 mCTAcvObjIdTbl[5][2];
};

inline void* uGUIArisenCard::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIArisenCard::cScrollHistoryDispList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIArisenCard::cScrollHistoryDispList::cScrollHistoryDispList() {
    this->mpStar[4] = nullptr;
    this->mpStar[3] = nullptr;
    this->mpStar[2] = nullptr;
    this->mpStar[1] = nullptr;
    this->mpStar[0] = nullptr;
    this->mpText = nullptr;
    this->mpIcon = nullptr;
    this->mpEmblem = nullptr;
    this->mpTime = nullptr;
    this->mpName = nullptr;
}

inline void* uGUIArisenCard::cScrollDispSkillList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIArisenCard::cScrollDispSkillList::cScrollDispSkillList() : mpPlate(static_cast<cGUIInstAnimation*>(nullptr)) {
}

inline uGUIArisenCard::cScrollDispSkillList::~cScrollDispSkillList() {
}

inline void* uGUIArisenCard::cScrollDispAbilityList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIArisenCard::cScrollDispAbilityList::cScrollDispAbilityList() : mpPlate(static_cast<cGUIInstAnimation*>(nullptr)) {
}

inline uGUIArisenCard::cScrollDispAbilityList::~cScrollDispAbilityList() {
}

inline void* uGUIArisenCard::cScrollSkillList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIArisenCard::cScrollAbilityList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIArisenCard::cScrollHistoryInfoList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uGUIPopDetail01.h"

inline MtAllocator* uGUIArisenCard::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::DTI);
}

inline void uGUIArisenCard::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::DTI)->memFree(p_addr);
}

inline void uGUIArisenCard::offDispItemDetail() {
    if (this->mpItemDetail == nullptr) {
        return;
    }
    this->mpItemDetail->mIsDraw = false;
}

inline void uGUIArisenCard::initHistoryCtrl() {
    if (this->mHistoryScrollbar.mpVCtrl == nullptr) {
        return;
    }
    this->mHistoryScrollbar.mIsAutoSetVisibleSize = false;
    this->mHistoryScrollbar.mpVCtrl->mVisibleSize = this->mHistoryDispNum;
}

inline void* uGUIArisenCard::cScrollHistoryDispList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::cScrollHistoryDispList::DTI)->memAlloc(sz, align, ::uGUIArisenCard::cScrollHistoryDispList::DTI.::MtDTI::getID());
}

inline void uGUIArisenCard::cScrollHistoryDispList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::cScrollHistoryDispList::DTI)->memFree(p_addr);
}

inline void* uGUIArisenCard::cScrollDispSkillList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::cScrollDispSkillList::DTI)->memAlloc(sz, align, ::uGUIArisenCard::cScrollDispSkillList::DTI.::MtDTI::getID());
}

inline void uGUIArisenCard::cScrollDispSkillList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::cScrollDispSkillList::DTI)->memFree(p_addr);
}

inline void* uGUIArisenCard::cScrollDispAbilityList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::cScrollDispAbilityList::DTI)->memAlloc(sz, align, ::uGUIArisenCard::cScrollDispAbilityList::DTI.::MtDTI::getID());
}

inline void uGUIArisenCard::cScrollDispAbilityList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::cScrollDispAbilityList::DTI)->memFree(p_addr);
}

inline void uGUIArisenCard::cScrollSkillList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::cScrollSkillList::DTI)->memFree(p_addr);
}

inline void uGUIArisenCard::cScrollAbilityList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCard::cScrollAbilityList::DTI)->memFree(p_addr);
}
