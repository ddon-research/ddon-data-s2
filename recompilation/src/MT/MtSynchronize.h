#pragma once

#include <cstdint>
#include <cstddef>

#include <_pthread.h>
#include <stdlib.h>

// Forward declarations
class HttpClient;
namespace MtNet { namespace PS4Psn { class Context; } }
class MtNetAchievement;
class MtNetContext;
class MtNetCore;
class MtNetFriendList;
class MtNetMediator;
class MtNetObject;
class MtNetRanking;
class MtNetRequestController;
class MtNetServiceError;
class MtNetStorage2;
class MtThread;
struct _SceKernelEventFlag;
struct _SceKernelSema;
class aStage;
class cAIService;
class cAISvDynamicPathFinding;
namespace cAcquirement { class cSkillDataBase; }
namespace cEvaluationName { class cEvaluation; }
class cNetGameServer;
class cSoundLimitter;
class cZoneMultiStack;
namespace nNetwork { class VoiceChat; }
namespace nPhysics { class System; }
struct pthread_mutex;
class rSoundSourceStreamAT9;
class sAI;
class sAIExt;
class sAIPawnSys;
class sArchiveManager;
class sAreaHit;
class sBakingJointOrder;
class sBrowser;
class sCamera;
class sCameraExt;
class sCaplinkManager;
class sChat;
class sCollision;
class sContextManager;
class sControlManager;
class sCoprocessor;
class sEffect;
class sEffectExt;
class sGUI;
class sGUIExt;
class sGrass;
class sInputManager;
class sItemManager;
class sLightExt;
class sLockOnManager;
class sMain;
class sNetwork;
class sObjCollision;
class sOccluder;
class sOmManager;
class sPrimitive;
class sQuestManagerExt;
class sRender;
class sResource;
class sResourceExt;
class sReward;
class sScene;
class sSceneExt;
class sSetManager;
class sShadow;
class sSound;
class sSoundExt;
class sSoundManager;
class sUnit;
class sUnitManager;
class sWeatherManager;
class sZone;
class sZoneUnitCtrl;
class uGUIMenuComm;
class uOmSwingInstancing;
class uSoundSubMixer;
namespace via { class Request; }
namespace via { namespace module { namespace http_patch { class ParallelsListenerManager; } } }
namespace via { namespace module { namespace network { namespace utility { class HttpDownloadManager; } } } }

// Declarations
class MtAutoCriticalSection;
class MtCriticalSection;
class MtSemaphore;
namespace nWin32Detour { class eventFlag; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SceKernelEventFlag = _SceKernelEventFlag*;
using SceKernelSema = _SceKernelSema*;
using pthread_mutex_t = pthread_mutex*;
using ScePthreadMutex = pthread_mutex_t;
using u32 = unsigned int;

// Functions the classes below befriend, declared first
namespace nWin32Detour { void setEvent(eventFlag& cs); }
namespace nWin32Detour { void waitForSingleObject(eventFlag& cs); }

namespace nWin32Detour {

    // Forward declarations
    class eventFlag;

    class eventFlag
    {
        friend void nWin32Detour::setEvent(nWin32Detour::eventFlag& cs);
        friend void nWin32Detour::waitForSingleObject(nWin32Detour::eventFlag& cs);
    public:
        enum eStatus
        {
            STATUS_FREE = 0,
            STATUS_NOTIFIED = 1,
            STATUS_RECEIVED = 2,
        };
    public:
        eventFlag();
        ~eventFlag();
        void wait();
        void set();
        void reset();
    private:
        SceKernelEventFlag mEventFlag;  // offset: 0x0
    };

    void waitForSingleObject(eventFlag& cs);
    void setEvent(eventFlag& cs);
    void resetEvent(eventFlag& cs);

}  // namespace nWin32Detour

class MtAutoCriticalSection
{
public:
    MtAutoCriticalSection(MtCriticalSection* pcs);
    ~MtAutoCriticalSection();
private:
    MtCriticalSection* mpCSection;  // offset: 0x0
};

class MtCriticalSection
{
    friend class HttpClient;
    friend class MtNet::PS4Psn::Context;
    friend class MtNetAchievement;
    friend class MtNetContext;
    friend class MtNetCore;
    friend class MtNetFriendList;
    friend class MtNetMediator;
    friend class MtNetObject;
    friend class MtNetRanking;
    friend class MtNetRequestController;
    friend class MtNetServiceError;
    friend class MtNetStorage2;
    friend class MtThread;
    friend class aStage;
    friend class cAIService;
    friend class cAISvDynamicPathFinding;
    friend class cAcquirement::cSkillDataBase;
    friend class cEvaluationName::cEvaluation;
    friend class cNetGameServer;
    friend class cSoundLimitter;
    friend class cZoneMultiStack;
    friend class nNetwork::VoiceChat;
    friend class nPhysics::System;
    friend class rSoundSourceStreamAT9;
    friend class sAI;
    friend class sAIExt;
    friend class sAIPawnSys;
    friend class sArchiveManager;
    friend class sAreaHit;
    friend class sBakingJointOrder;
    friend class sBrowser;
    friend class sCamera;
    friend class sCameraExt;
    friend class sCaplinkManager;
    friend class sChat;
    friend class sCollision;
    friend class sContextManager;
    friend class sControlManager;
    friend class sCoprocessor;
    friend class sEffect;
    friend class sEffectExt;
    friend class sGUI;
    friend class sGUIExt;
    friend class sGrass;
    friend class sInputManager;
    friend class sItemManager;
    friend class sLightExt;
    friend class sLockOnManager;
    friend class sMain;
    friend class sNetwork;
    friend class sObjCollision;
    friend class sOccluder;
    friend class sOmManager;
    friend class sPrimitive;
    friend class sQuestManagerExt;
    friend class sRender;
    friend class sResource;
    friend class sResourceExt;
    friend class sReward;
    friend class sScene;
    friend class sSceneExt;
    friend class sSetManager;
    friend class sShadow;
    friend class sSound;
    friend class sSoundExt;
    friend class sSoundManager;
    friend class sUnit;
    friend class sUnitManager;
    friend class sWeatherManager;
    friend class sZone;
    friend class sZoneUnitCtrl;
    friend class uGUIMenuComm;
    friend class uOmSwingInstancing;
    friend class uSoundSubMixer;
    friend class via::module::http_patch::ParallelsListenerManager;
    friend class via::module::network::utility::HttpDownloadManager;
public:
    MtCriticalSection();
    ~MtCriticalSection();
    void lock();
    bool tryLock();
    void unlock();
private:
    ScePthreadMutex mCSection;  // offset: 0x0
};

class MtSemaphore
{
    friend class HttpClient;
    friend class sBakingJointOrder;
    friend class sMain;
    friend class via::Request;
public:
    MtSemaphore(const u32 initial_count, const u32 maximum_count, MT_CTSTR name);
    ~MtSemaphore();
    void release(const u32 count);
    void wait(const u32 time_out);
private:
    SceKernelSema mHandle;  // offset: 0x0
};

inline void MtCriticalSection::lock() {
    if (scePthreadMutexLock(&mCSection) != 0) {
        abort();
    }
}

inline void MtCriticalSection::unlock() {
    if (scePthreadMutexUnlock(&mCSection) != 0) {
        abort();
    }
}
