#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtThread.h"
#include "../../XFramework/cPlatformUtilCommon.h"
#include "../../XFramework/sMain.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSemaphore;
class MtUI;
class MtVector3;
struct pthread;
struct pthread_attr;
class sAIExt;
class sAIPawnNotice;
class sAIPawnSys;
class sAIPawnTalkMgr;
class sArchiveManager;
class sAreaExt;
class sAreaHit;
class sBakingJointOrder;
class sBazaarManager;
class sBenchmark;
class sBrowser;
class sCameraExt;
class sCaplinkManager;
class sCapture;
class sChat;
class sClanKyoten;
class sCollision;
class sCommonDialog;
class sContextManager;
class sControlManager;
class sCoprocessor;
class sCraftManager;
class sDemo;
class sDialogBase;
class sEffectExt;
class sEnemyManager;
class sEnvMapManager;
class sEventManager;
class sExceptionHandler;
class sFile;
class sFlag;
class sGUIExt;
class sGame;
class sGeneralPoint;
class sGpuParticle;
class sGrass;
class sGuideExt;
class sHID;
class sHttpClient;
class sHttpPatch;
class sIME;
class sInputManager;
class sInputText;
class sItemManager;
class sKeyboardExt;
class sKeyboardInterface;
class sLayout;
class sLightExt;
class sLockOnManager;
class sMarker;
class sMenu;
class sMouseExt;
class sMovie;
class sMyRoom;
class sNetworkExt;
class sNpcControlManager;
class sNpcManager;
class sObjCollision;
class sObjCondition;
class sOccluderEx;
class sOmManager;
class sPadExt;
class sPhysicsExt;
class sPlatformUtil;
class sPlayerManager;
class sPrimitive;
class sQuestManagerExt;
class sRemoteProcedure;
class sRender;
class sResourceExt;
class sReward;
class sSavedataExt;
class sScenario;
class sSceneExt;
class sScreenShot;
class sSetManager;
class sShader2;
class sShadow;
class sShlManager;
class sSound;
class sSoundManager;
class sSyncPoint;
class sSystemFont;
class sTalkManager;
class sToolExt;
class sTutorialGuide;
class sUnitExt;
class sUserManager;
class sVibrationExt;
class sWeatherManager;
class sWorkRate;
class sWorldOffset;
class sZone;
class sZoneStatus;
class sZoneUnitCtrl;

// Declarations
class cCmdLineLoginInfo;
class sDDOMain;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using pthread_t = pthread*;
using ScePthread = pthread_t;
using pthread_attr_t = pthread_attr*;
using ScePthreadAttr = pthread_attr_t;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cCmdLineLoginInfo
{
    friend class sDDOMain;
public:
    static void getLoginServerAddr(MT_CHAR* output);
    static void setLoginServerAddr(const MT_CHAR* NewValue);
    static u32 getLoginServerPort();
    static void setLoginServerPort(u32 NewValue);
    static void getOneTimeToken(MT_CHAR* output);
    static void setOneTimeToken(const MT_CHAR* NewValue);
    static void getDownloadServerURL(MT_CHAR* output);
    static void setDownloadServerURL(const MT_CHAR* NewValue);
public:
    static const u32 LOGIN_SERVER_ADDR_SIZE = 128;
    static const u32 ONETIME_TOKEN_SIZE = 64;
    static const u32 DL_SERVER_URL_SIZE = 256;
private:
    static MT_CHAR loginServerAddr[128];
    static u32 loginServerPort;
    static MT_CHAR oneTimeToken[64];
    static MT_CHAR downloadServerURL[256];
};

class sDDOMain : public sMain
{
public:
    enum MOVE_PROFILE
    {
        MOVE_PROFILE_000_MOVE_SMAIN = 0,
        MOVE_PROFILE_005_SETUPS = 1,
        MOVE_PROFILE_010_MOVE_NETWORKS = 2,
        MOVE_PROFILE_020_BEGINS = 3,
        MOVE_PROFILE_030_MOVE_INPUTDEVICES = 4,
        MOVE_PROFILE_040_MOVE_AREA = 5,
        MOVE_PROFILE_050_MOVE_GAME = 6,
        MOVE_PROFILE_060_MOVE_DIALOG = 7,
        MOVE_PROFILE_070_MOVE_MENU = 8,
        MOVE_PROFILE_080_MOVE_SHADER = 9,
        MOVE_PROFILE_090_MOVE_AI = 10,
        MOVE_PROFILE_100_MOVE_KBINTERFACE = 11,
        MOVE_PROFILE_110_MOVE_CHAT = 12,
        MOVE_PROFILE_120_MOVE_QUESTMANAGER = 13,
        MOVE_PROFILE_130_MOVE_TALKMANAGER = 14,
        MOVE_PROFILE_140_MOVE_AIPAWNTALKMANAGER = 15,
        MOVE_PROFILE_150_MOVE_WORKRATE = 16,
        MOVE_PROFILE_160_MOVE_OBJCOLLISION = 17,
        MOVE_PROFILE_170_MOVE_OBJCONDITION = 18,
        MOVE_PROFILE_180_MOVE_CRAFTMANAGER = 19,
        MOVE_PROFILE_190_MOVE_BUTTLESTATE = 20,
        MOVE_PROFILE_200_MOVE_ZONEUNITCTRL = 21,
        MOVE_PROFILE_210_MOVE_ZONESTATUS = 22,
        MOVE_PROFILE_220_MOVE_BJORDER = 23,
        MOVE_PROFILE_230_MOVE_LIGHT = 24,
        MOVE_PROFILE_240_MOVE_UNIT = 25,
        MOVE_PROFILE_250_MOVE_AIPAWNNOTICE = 26,
        MOVE_PROFILE_260_MOVE_AIPAWNSYSTEM = 27,
        MOVE_PROFILE_270_MOVE_COLLISION = 28,
        MOVE_PROFILE_280_MOVE_LOCKONMANAGER = 29,
        MOVE_PROFILE_290_MOVE_GUI = 30,
        MOVE_PROFILE_300_MOVE_GENERALPOINT = 31,
        MOVE_PROFILE_310_SYNC_LOCKONMANAGER = 32,
        MOVE_PROFILE_320_SYNC_UNIT = 33,
        MOVE_PROFILE_330_MOVEAFTER_UNIT = 34,
        MOVE_PROFILE_340_MOVEAFTER_AI = 35,
        MOVE_PROFILE_350_MOVE_EFFECT = 36,
        MOVE_PROFILE_360_MOVE_GPUPARTICLE = 37,
        MOVE_PROFILE_370_MOVE_CAMERA = 38,
        MOVE_PROFILE_380_MOVE_PHYSICS = 39,
        MOVE_PROFILE_390_MOVE_AREAHIT = 40,
        MOVE_PROFILE_400_MOVE_ZONE = 41,
        MOVE_PROFILE_410_MOVE_BROWSER = 42,
        MOVE_PROFILE_420_MOVE_SOUND = 43,
        MOVE_PROFILE_430_MOVE_WEATHERMANAGER = 44,
        MOVE_PROFILE_440_MOVE_ITEMMANAGER = 45,
        MOVE_PROFILE_450_END_GRASS = 46,
        MOVE_PROFILE_460_MOVE_SCENE = 47,
        MOVE_PROFILE_470_MOVE_SHADOW = 48,
        MOVE_PROFILE_480_MOVE_TOOL = 49,
        MOVE_PROFILE_490_MOVE_PRIMITIVE = 50,
        MOVE_PROFILE_500_MOVE_COPRECESSOR = 51,
        MOVE_PROFILE_510_SYNC_COLLISION = 52,
        MOVE_PROFILE_520_MOVE_CONTEXTMANAGER = 53,
        MOVE_PROFILE_530_MOVE_RENDER = 54,
        MOVE_PROFILE_540_END_RENDER = 55,
        MOVE_PROFILE_550_END_GUI = 56,
        MOVE_PROFILE_560_END_GPUPARTICLE = 57,
        MOVE_PROFILE_570_UPDATEDYNAMICFONT_GUI = 58,
        MOVE_PROFILE_580_END_PRIMITIVE = 59,
        MOVE_PROFILE_590_END_PHYSICS = 60,
        MOVE_PROFILE_600_END_COPROCESSOR = 61,
        MOVE_PROFILE_610_MOVE_ARCHIVEMANAGER = 62,
        MOVE_PROFILE_620_MOVE_ENVMAP = 63,
        MOVE_PROFILE_630_MOVE_CAPTURE = 64,
        MOVE_PROFILE_640_MOVE_DDEXCEPTION = 65,
        MOVE_PROFILE_650_UPDATEPTR_UNIT = 66,
        MOVE_PROFILE_660_CHECKBROKENMEMORY = 67,
        MOVE_PROFILE_NUM = 68,
    };
public:
    class MyDTI;
    class AsyncThread;
    struct ASYNCHRONOUS_CHAIN;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class AsyncThread : public MtThread
    {
    public:
        AsyncThread();
        virtual ~AsyncThread() {}
        virtual void execute(void* pcontext);  // vtable slot 6
    };
public:
    struct ASYNCHRONOUS_CHAIN
    {
    public:
        MtObject* object;  // offset: 0x0
        MT_MFUNC func;  // offset: 0x8
        volatile bool sync_point;  // offset: 0x18
        MT_CTSTR profile_name;  // offset: 0x20
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
    sDDOMain();
    virtual ~sDDOMain();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual bool close();  // vtable slot 10
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    f32 getSystemTimer();
    s32 getGameRegion();
private:
    void setupProfile();
    void beginProfile(MOVE_PROFILE phase);
    void endProfile();
    void updatePtrProc();
    void initAsyncFunctionChain();
    void terminateAsyncFunctionChain();
    void waitAsyncThread();
    void kickThreadAsync();
    u32 setASyncFunction(MtObject* pobj, MT_MFUNC func, MT_CTSTR name);
    bool runAsyncFunction();
    bool checkSynchronousPoint(u32);
    void inBackGroundCallback(const char* pparam, const u32 size, const u8* parg, nPlatformUtil::nSystemService::CALL_TYPE::TYPE call_type);
    void resumeCallback(const char* pparam, const u32 size, const u8* parg, nPlatformUtil::nSystemService::CALL_TYPE::TYPE call_type);
public:
    bool isFromLauncher();
    void initBrowserThread();
    void finalizeBrowserThread();
    void threadOrder(MtObject* object, MT_MFUNC func);
    void threadWait();
    void threadOrderAndWait(MtObject* object, MT_MFUNC func);
    bool isExecDynamicMenu();
private:
    f32 mSystemTimer;  // offset: 0x57ab8
    sRender* mpRender;  // offset: 0x57ac0
    sToolExt* mpTool;  // offset: 0x57ac8
    sUnitExt* mpUnit;  // offset: 0x57ad0
    sObjCollision* mpObjCollision;  // offset: 0x57ad8
    sObjCondition* mpObjCondition;  // offset: 0x57ae0
    sLockOnManager* mpLockOnManager;  // offset: 0x57ae8
    sResourceExt* mpResource;  // offset: 0x57af0
    sCameraExt* mpCamera;  // offset: 0x57af8
    sPadExt* mpPad;  // offset: 0x57b00
    sEffectExt* mpEffect;  // offset: 0x57b08
    sCollision* mpCollision;  // offset: 0x57b10
    sShader2* mpShader2;  // offset: 0x57b18
    sSound* mpSound;  // offset: 0x57b20
    sCapture* mpCapture;  // offset: 0x57b28
    sAreaExt* mpArea;  // offset: 0x57b30
    sGpuParticle* mpGpuParticle;  // offset: 0x57b38
    sMouseExt* mpMouse;  // offset: 0x57b40
    sKeyboardExt* mpKeyboard;  // offset: 0x57b48
    sInputManager* mpInputManager;  // offset: 0x57b50
    sVibrationExt* mpVibration;  // offset: 0x57b58
    sBenchmark* mpBenchmark;  // offset: 0x57b60
    sPhysicsExt* mpPhysics2;  // offset: 0x57b68
    sAIExt* mpAI;  // offset: 0x57b70
    sZone* mpZone;  // offset: 0x57b78
    sRemoteProcedure* mpRPC;  // offset: 0x57b80
    sNetworkExt* mpNetwork;  // offset: 0x57b88
    sGuideExt* mpGuide;  // offset: 0x57b90
    sHttpClient* mpHttpClient;  // offset: 0x57b98
    sHttpPatch* mpHttpPatch;  // offset: 0x57ba0
    sCaplinkManager* mpCaplink;  // offset: 0x57ba8
    sDialogBase* mpDialog;  // offset: 0x57bb0
    sArchiveManager* mpArchiveManager;  // offset: 0x57bb8
    sSetManager* mpSetManager;  // offset: 0x57bc0
    sContextManager* mpContextManager;  // offset: 0x57bc8
    sZoneStatus* mpZoneStatus;  // offset: 0x57bd0
    sGUIExt* mpGUI;  // offset: 0x57bd8
    sLightExt* mpLight;  // offset: 0x57be0
    sAIPawnNotice* mpAIPawnNotice;  // offset: 0x57be8
    sAIPawnSys* mpAIPawnSys;  // offset: 0x57bf0
    sGrass* mpGrass;  // offset: 0x57bf8
    sSceneExt* mpScene;  // offset: 0x57c00
    sOccluderEx* mpOccluder;  // offset: 0x57c08
    sShadow* mpShadow;  // offset: 0x57c10
    sDemo* mpDemo;  // offset: 0x57c18
    sPlatformUtil* mpPlatformUtil;  // offset: 0x57c20
    sSavedataExt* mpSavedata;  // offset: 0x57c28
    sFile* mpFile;  // offset: 0x57c30
    sSystemFont* mpSystemFont;  // offset: 0x57c38
    sCommonDialog* mpCommonDialog;  // offset: 0x57c40
    sUserManager* mpUserManager;  // offset: 0x57c48
    sInputText* mpInputText;  // offset: 0x57c50
    sExceptionHandler* mpExceptionHandler;  // offset: 0x57c58
    sPrimitive* mpPrimitive;  // offset: 0x57c60
    sSyncPoint* mpSyncPoint;  // offset: 0x57c68
    sHID* mpHID;  // offset: 0x57c70
    sCoprocessor* mpCoprocessor;  // offset: 0x57c78
    sLayout* mpLayout;  // offset: 0x57c80
    sGame* mpGame;  // offset: 0x57c88
    sKeyboardInterface* mpKbInterface;  // offset: 0x57c90
    sChat* mpChat;  // offset: 0x57c98
    sAreaHit* mpAreaHit;  // offset: 0x57ca0
    sScenario* mpScenario;  // offset: 0x57ca8
    sWeatherManager* mpWeatherManager;  // offset: 0x57cb0
    sEnvMapManager* mpEnvmap;  // offset: 0x57cb8
    sWorkRate* mpWorkRate;  // offset: 0x57cc0
    sWorldOffset* mpWorldOffset;  // offset: 0x57cc8
    sPlayerManager* mpPlayerManager;  // offset: 0x57cd0
    sEnemyManager* mpEnemyManager;  // offset: 0x57cd8
    sNpcControlManager* mpNpcCtrlManager;  // offset: 0x57ce0
    sControlManager* mpCtrlManager;  // offset: 0x57ce8
    sNpcManager* mpNpcManager;  // offset: 0x57cf0
    sFlag* mpFlag;  // offset: 0x57cf8
    sOmManager* mpOmManager;  // offset: 0x57d00
    sClanKyoten* mpClanKyoten;  // offset: 0x57d08
    sGeneralPoint* mpGeneralPoint;  // offset: 0x57d10
    sItemManager* mpItemManager;  // offset: 0x57d18
    sShlManager* mpShlManager;  // offset: 0x57d20
    sSoundManager* mpSoundManager;  // offset: 0x57d28
    sEventManager* mpEventManager;  // offset: 0x57d30
    sTalkManager* mpTalkManager;  // offset: 0x57d38
    sAIPawnTalkMgr* mpAIPawnTalkMgr;  // offset: 0x57d40
    sQuestManagerExt* mpQuestManagerExt;  // offset: 0x57d48
    sTutorialGuide* mpTutorialGuide;  // offset: 0x57d50
    sMarker* mpMarker;  // offset: 0x57d58
    sReward* mpReward;  // offset: 0x57d60
    sMyRoom* mpMyRoom;  // offset: 0x57d68
    sCraftManager* mpCraftManager;  // offset: 0x57d70
    sBazaarManager* mpBazaarManager;  // offset: 0x57d78
    sZoneUnitCtrl* mpZoneUnitCtrl;  // offset: 0x57d80
    sMenu* mpMenu;  // offset: 0x57d88
    sBrowser* mpBrowser;  // offset: 0x57d90
    sScreenShot* mpScreenShot;  // offset: 0x57d98
    sMovie* mpMovie;  // offset: 0x57da0
    sIME* mpIME;  // offset: 0x57da8
    sBakingJointOrder* mpBJOrder;  // offset: 0x57db0
    MtSemaphore* mpAsyncSemaphore;  // offset: 0x57db8
    AsyncThread mAsyncThread;  // offset: 0x57dc0
    bool isAsyncThreadExit;  // offset: 0x57e30
    volatile bool mIsThreadRunning;  // offset: 0x57e31
    ASYNCHRONOUS_CHAIN mASynchronousFunction[8];  // offset: 0x57e38
public:
    MtSemaphore* mpBrowserSemaphore;  // offset: 0x57f78
    ScePthread mBrowserThread;  // offset: 0x57f80
    ScePthreadAttr mBrowserThreadAttr;  // offset: 0x57f88
    MtObject* mpBrowserObject;  // offset: 0x57f90
    MT_MFUNC mBrowserFunction;  // offset: 0x57f98
    volatile bool mbWait;  // offset: 0x57fa8
    volatile bool mBrowserThreadAlive;  // offset: 0x57fa9
private:
    bool mIsExecDynamicMenu;  // offset: 0x57faa
public:
    static MyDTI DTI;
private:
    static const u32 MAX_ASYNC_FUNCTION_CHAIN = 8;
    static const u32 INVALID_ASYNC_ID = 8;
};

inline void* sDDOMain::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void sDDOMain::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sDDOMain::DTI)->memFree(p_addr);
}
