#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtSize;
class cControl;
class cGUIClanExecutor;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObject;
class cMenuBase;
class rGUI;
class sGUIExt;
class uGUICaplinkTopMenu;
class uGUISystemMsg;

// Declarations
class uGUIGameMenu;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class uGUIGameMenu : public uGUIBase
{
    // inferred: sGUIExt::initGameMenuEndSelect names uGUIGameMenu::mEndSelect
    friend class sGUIExt;
public:
    enum SELECT
    {
        SELECT_NONE = 0,
        SELECT_LOBBY = 1,
        SELECT_EXITGAME = 2,
        SELECT_TITLE = 3,
        SELECT_LAUNCHER = 4,
        SELECT_WARP = 5,
    };
    enum VISIBLE
    {
        VISIBLE_ALL = 1,
        VISIBLE_LOBBY = 2,
        VISIBLE_STAGE = 4,
        VISIBLE_CLAN = 8,
        VISIBLE_MAIN01 = 16,
        VISIBLE_AREA_MASTER = 32,
        VISIBLE_JOB_MASTER = 64,
        VISIBLE_PAWN = 128,
        VISIBLE_NEWSPAPER = 256,
        VISIBLE_WARP = 512,
        VISIBLE_PARTY = 1024,
        VISIBLE_QUICK_PARTY = 2048,
        VISIBLE_ENTRYBOARD = 4096,
        VISIBLE_PROFILE = 8192,
        VISIBLE_CLAN_MANAGER = 16384,
        VISIBLE_CAPLINK = 32768,
        VISIBLE_SUPPORT = 65536,
    };
    enum SOCIAL_CONTENTS
    {
        SOCIAL_PARTY = 0,
        SOCIAL_QUICK_PARTY = 1,
        SOCIAL_COMMUNITY_LIST = 2,
        SOCIAL_SEARCH_PLAYER = 3,
        SOCIAL_CLAN = 4,
        SOCIAL_CLAN_MANAGER = 5,
        SOCIAL_LINK_SHELL = 6,
        SOCIAL_ENTRY_BOARD = 7,
        SOCIAL_NUM = 8,
    };
    enum CATEGORY
    {
        CATEGORY_PARSONAL = 0,
        CATEGORY_JOUNAL = 1,
        CATEGORY_WORLD = 2,
        CATEGORY_SOCIAL = 3,
        CATEGORY_COMMUNICATION = 4,
        CATEGORY_SYSTEM = 5,
        CATEGORY_SHOP = 6,
        CATEGORY_NUM = 7,
    };
    enum
    {
        SUBMODE_NONE = 0,
        SUBMODE_INFO = 1,
    };
    enum WORLD_CONTENTS
    {
        WORLD_MAP = 0,
        WORLD_AREAINFO = 1,
        WORLD_WARP = 2,
        WORLD_TUTORIAL = 3,
        WORLD_NUM = 4,
    };
    enum COMMUNICATION_CONTENTS
    {
        COMMUNICATION_MYPHRASE = 0,
        COMMUNICATION_PHRASE = 1,
        COMMUNICATION_EMOTION = 2,
        COMMUNICATION_MAIL = 3,
        COMMUNICATION_PHOTO = 4,
        COMMUNICATION_ALBUM = 5,
        COMMUNICATION_CAPLINK = 6,
        COMMUNICATION_NUM = 7,
    };
    enum JOUNAL_CONTENTS
    {
        JOUNAL_NEWS = 0,
        JOUNAL_QUEST = 1,
        JOUNAL_KEY = 2,
        JOUNAL_TIME_EVENT = 3,
        JOUNAL_MASTER = 4,
        JOUNAL_EXITCONTENTS = 5,
        JOUNAL_NUM = 6,
    };
    enum SYSTEM_CONTENTS
    {
        SYSTEM_CONFIG_SYS = 0,
        SYSTEM_CONFIG_CHR = 1,
        SYSTEM_MANUAL = 2,
        SYSTEM_SUPPORT = 3,
        SYSTEM_CHANGE_SERVER = 4,
        SYSTEM_EXITGAME = 5,
        SYSTEM_NUM = 6,
    };
    enum
    {
        MONEY_GOLD = 0,
        MONEY_RIM = 1,
        MONEY_BO = 2,
        MONEY_NUM = 3,
    };
    enum PARSONAL_CONTENTS
    {
        PARSONAL_ITEM = 0,
        PARSONAL_DELIVER_BOX = 1,
        PARSONAL_STATUS = 2,
        PARSONAL_PAWN = 3,
        PARSONAL_PAWNORD = 4,
        PARSONAL_ACHIEVE = 5,
        PARSONAL_ARISENCARD = 6,
        PARSONAL_PROFILE = 7,
        PARSONAL_NUM = 8,
    };
    enum GP_CONTENTS
    {
        GP_SHOP = 0,
        GP_STATUS = 1,
        GP_CHARGE = 2,
        GP_GACHA = 3,
        GP_LOGIN_BONUS = 4,
        GP_PSSTORE = 5,
        GP_CODE_INPUT = 6,
        GP_NUM = 7,
    };
public:
    class MyDTI;
    class PARAM;
    struct stContentsItem;
    struct stCategoryItem;
    struct stMoney;
    class cGameMenuUnitWatcher;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class PARAM
    {
    public:
        PARAM();
        void clear();
    public:
        u32 msgIndex;  // offset: 0x0
        MT_MFUNC pFunc;  // offset: 0x8
        const MtDTI* pDti;  // offset: 0x18
        u32 visibleFlag;  // offset: 0x20
        u32 arg;  // offset: 0x24
    };
public:
    struct stContentsItem
    {
    public:
        stContentsItem();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        uGUIBase::cReferenceUIIconSCM mIconSCM;  // offset: 0x8
        const uGUIGameMenu::PARAM* mpParam;  // offset: 0x58
        u32 mInvisibleFlag;  // offset: 0x60
        bool mIsEnable;  // offset: 0x64
        bool mIsEnableRT;  // offset: 0x65
    };
public:
    struct stCategoryItem
    {
    public:
        stCategoryItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimHit;  // offset: 0x8
        cGUIInstAnimation* mpInstAnim;  // offset: 0x10
        cGUIObjTexture* mpObjTexIcon;  // offset: 0x18
        cGUIObjTexture* mpObjTexName;  // offset: 0x20
        cGUIObjPolygon* mpObjPolyHit;  // offset: 0x28
        cGUIObjPolygon* mpObjPolyHitDummy;  // offset: 0x30
        uGUIGameMenu::stContentsItem mContents[8];  // offset: 0x38
        uGUIBase::cCalcMovePos mPosCtrl;  // offset: 0x378
    };
public:
    struct stMoney
    {
    public:
        stMoney();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgVal;  // offset: 0x8
        cGUIObjMessage* mpObjMsgUnit;  // offset: 0x10
        cGUIObjTexture* mpObjTexCenter;  // offset: 0x18
        cGUIObjTexture* mpObjTexLeft;  // offset: 0x20
        u64 mVal;  // offset: 0x28
    };
public:
    class cGameMenuUnitWatcher : public uGUIBase::cUnitWatcher
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
        cGameMenuUnitWatcher();
        // Address: 0x01afb1e0 - 0x01afb1e1 (1 bytes)
        virtual ~cGameMenuUnitWatcher() {}
        virtual void update();  // vtable slot 6
    public:
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
    uGUIGameMenu();
    virtual ~uGUIGameMenu();
    static f32 getMenuIconFixFrameFromMsgIdx(u32 uMsgIdx);
    static s32 getMsgIdxFromSCMMenuId(u32 uSCMMenuId);
    static u32 getSCMMenuIdFromMsgIdx(u32 uMsgIdx);
    static bool searchCtgrAndCnoFromSCMMenuId(u32 uSCMMenuId, u32& uCtgr, u32& uCno);
    virtual void move();  // vtable slot 9
    void evSelectPawnOrder();
    void evSelectOptionSys();
    void evSelectOptionChr();
    void evSelectMap();
    void evSelectAreaInfo();
    void evSelectItemBag();
    void evSelectNewsPaper();
    void evSelectQuest();
    void evSelectExitContents();
    void evSelectRimWarp();
    void evSelectReturnLobby();
    void evSelectReturnExitGame();
    void evSelectTutorial();
    void evSelectManual();
    void evSelectSupport();
    void evSelectPhoto();
    void evSelectPhotoAlbum();
    void evSelectShopGP();
    void evSelectShopStatus();
    void evSelectShopCharge();
    void evSelectInputCode();
    void evSelectPSStore();
    void evSelectMenuCommMyPhrase();
    void evSelectMenuCommTmpPhrase();
    void evSelectMenuCommEmotion();
    void evSelectMenuBoughtBox();
    void evSelectLoginBonus();
    void evSelectTimeEvent();
    void evSelectUnitCreate();
    void evSelectMenuSystem();
    void evGacha();
    void evEntryBoard();
    void wakeup(u32 uMenuId, bool changeFunc, s32 infoFlag, u32 infoId);
    void sleep();
    SELECT getEndSelect();
    void initEndSelect();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    bool isEnableExtraMenu();
    bool isGameMenuCreate(uGUIBase* pGUI);
    bool isGachaActive();
private:
    void wakeupPrivate(bool changeFunc);
    void updateInit();
    void updateWait();
    void updateExit();
    void updateInfo();
    bool startMenuFromInfo(u32 info_flag, u32 info_id);
    void updateJoinPartyWait();
    void updateQuickReadyWait();
    void updateEntryBoardReadyWait();
    void updateInviteEntry();
    void updateMoney();
    void setupMoney(stMoney& money, u64 val);
    void drawBasic();
    void updateSelect();
    void updateMenuSystem();
    void updateRimWarp();
    void updateBrowser();
    void updateBanner();
    void wakeupBanner();
    void sleepBanner();
    void startBrowser(MT_CTSTR URL, s32 WebSizeW, s32 WebSizeH);
    MtFloat2 getBrowserPos(f32 scale);
    void jumpSetPosSizeCallback(s32& PosX, s32& PosY, s32& Width, s32& Height, MT_CTSTR Url);
    void updateGacha();
    void updateEntryBoard();
    void updateWakeup();
    void evSelectClanManager();
    void updateClanManager();
    void updateServerUI();
    u32 getCategoryNo();
    u32 getContentsNo(u32 categoryNo);
    u32 getContentsNo();
    stCategoryItem& getCategory(u32 categoryNo);
    stContentsItem& getContents(u32 categoryNo, u32 contentsNo);
    void setContentsVisible(u32 categoryNo, bool isVisible);
    void setAllContentsVisible();
    void adjustCategoryPos(s32 center_category);
    void adjustContentsPos(u32 category_no, bool isImmediate);
    void setFocusCategory();
    void updateMoveContents(f32 delta_time);
    void updateCategoryFocus();
    void updateContentsFocus(u32 categoryNo);
    void updateContentsFocus(stContentsItem& Contents, bool IsFocus);
    void initInfoWindow();
    void endInfoWindow();
    void initInfoList();
    bool isClickedInfo();
    void initList();
    void updateEnableRealTime();
    bool isEnableAreaRank();
    bool isEnableJobMaster();
    bool isArea(const MtDTI& dti);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlCheck(cControl::Message* msg);
    u32 evCtrlTop(cControl::Message* msg);
    u32 evCtrlBanner(cControl::Message* msg);
    u32 evCtrlMove(cControl::Message* msg);
    void checkMouseToPad();
    void setObjFrame(cGUIObject* pObj, f32 frame);
    MT_CTSTR getGameMenuMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    MT_CTSTR getDlgMsg(u32 index);
    void createDialogLogOut(u32 uReqType);
    bool reportUrlRequestServer();
    void reportUrlCallBack();
    bool isEndWith(uGUIBase* pChildUnit);
    bool isImmediateMenu();
protected:
    virtual void adjustScale();  // vtable slot 84
public:
    stContentsItem DUMMY_CONTENTS;  // offset: 0x8c8
    stCategoryItem DUMMY_CATEGORY;  // offset: 0x930
private:
    rGUI* mpGUIRes;  // offset: 0xcc8
    u32 mSubMenuRno;  // offset: 0xcd0
    cGUIInstNull* mpInstNullAll;  // offset: 0xcd8
    stCategoryItem mCategoryItem[7];  // offset: 0xce0
    stMoney mMoney[3];  // offset: 0x2608
    cGUIInstAnimation* mpInstAnimCursorBack;  // offset: 0x2698
    cGUIObjPolygon* mpObjPolyBannerMouseCollision;  // offset: 0x26a0
    uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x26b0
    f32 mCategoryPos;  // offset: 0x2760
    f32 mContentsPos;  // offset: 0x2764
    bool mForceEnd;  // offset: 0x2768
    bool mIsMouseMode;  // offset: 0x2769
    bool mIsEnableExtraMenu;  // offset: 0x276a
    bool mIsRimWarp;  // offset: 0x276b
    bool mIsMenuSystem;  // offset: 0x276c
    bool mIsBrowser;  // offset: 0x276d
    bool mIsInitBrowser;  // offset: 0x276e
    bool mIsGacha;  // offset: 0x276f
    bool mIsEntryBoard;  // offset: 0x2770
    bool mIsClanManager;  // offset: 0x2771
    bool mIsCaplink;  // offset: 0x2772
    bool mIsServerUI;  // offset: 0x2773
    u32 mReqMenuIdSCM;  // offset: 0x2774
    s32 mReqMenuInfoFlag;  // offset: 0x2778
    u32 mReqMenuInfoId;  // offset: 0x277c
    uGUIBase::cVerticalList* mpVerticalCtrl[7];  // offset: 0x2780
    uGUIBase::cHorizontalList* mpHorizonCtrl;  // offset: 0x27b8
    uGUIBase::cHorizontalList* mpLRCtrl;  // offset: 0x27c0
    cControl* mpBannerOpenCtrl;  // offset: 0x27c8
    cControl* mpBannerCloseCtrl;  // offset: 0x27d0
    cGameMenuUnitWatcher mUnitWatcher;  // offset: 0x27d8
    cMenuBase* mpMoveSMenu;  // offset: 0x2810
    SELECT mEndSelect;  // offset: 0x2818
    SELECT mEndSelectReq;  // offset: 0x281c
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x2820
    uGUICaplinkTopMenu* mpGUICaplinkMenu;  // offset: 0x2828
    u32 mSubMode;  // offset: 0x2830
    s32 mFlowNo;  // offset: 0x2834
    bool mIsGachaInit;  // offset: 0x2838
    cGUIClanExecutor* mpGUIClanExecutor;  // offset: 0x2840
    MtStringEx<256> mBrowserUrl;  // offset: 0x2848
    MtSize mBrowserSize;  // offset: 0x2950
    bool mIsEnableBanner;  // offset: 0x2958
    bool mIsDispBanner;  // offset: 0x2959
public:
    static MyDTI DTI;
    static const u32 CONTENTS_NUM_MAX = 8;
    static const PARAM* mpParamList[];
    static const PARAM param_parsonal[];
    static const PARAM param_jounal[];
    static const PARAM param_world[];
    static const PARAM param_social[];
    static const PARAM param_communication[];
    static const PARAM param_system[];
    static const PARAM param_shop[];
};

// Inline, no code of its own: checked where it is inlined.
inline uGUIGameMenu::SELECT uGUIGameMenu::getEndSelect() {
    return this->mEndSelect;
}

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIGameMenu::isGachaActive() {
    return this->mIsGacha;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIGameMenu::cGameMenuUnitWatcher::cGameMenuUnitWatcher() {
}
