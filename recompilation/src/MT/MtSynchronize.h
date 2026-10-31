#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtNetContext;
class MtNetCore;
class MtNetMediator;
class MtNetObject;
class MtThread;
struct _SceKernelEventFlag;
struct _SceKernelSema;
class aStage;
namespace cAcquirement { class cSkillDataBase; }
class cNetGameServer;
class cSoundLimitter;
class cZoneMultiStack;
namespace nNetwork { class VoiceChat; }
struct pthread_mutex;
class rSoundSourceStreamAT9;
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
class sEffect;
class sEffectExt;
class sGUI;
class sGUIExt;
class sInputManager;
class sItemManager;
class sNetwork;
class sObjCollision;
class sOccluder;
class sOmManager;
class sPrimitive;
class sQuestManagerExt;
class sRender;
class sResource;
class sScene;
class sSetManager;
class sShadow;
class sSound;
class sSoundExt;
class sSoundManager;
class sUnit;
class sUnitManager;
class sZone;
class uGUIMenuComm;
class uOmSwingInstancing;
class uSoundSubMixer;

// Declarations
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

class MtCriticalSection
{
    friend class MtNetContext;
    friend class MtNetCore;
    friend class MtNetMediator;
    friend class MtNetObject;
    friend class MtThread;
    friend class aStage;
    friend class cAcquirement::cSkillDataBase;
    friend class cNetGameServer;
    friend class cSoundLimitter;
    friend class cZoneMultiStack;
    friend class nNetwork::VoiceChat;
    friend class rSoundSourceStreamAT9;
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
    friend class sEffect;
    friend class sEffectExt;
    friend class sGUI;
    friend class sGUIExt;
    friend class sInputManager;
    friend class sItemManager;
    friend class sNetwork;
    friend class sObjCollision;
    friend class sOccluder;
    friend class sOmManager;
    friend class sPrimitive;
    friend class sQuestManagerExt;
    friend class sRender;
    friend class sResource;
    friend class sScene;
    friend class sSetManager;
    friend class sShadow;
    friend class sSound;
    friend class sSoundExt;
    friend class sSoundManager;
    friend class sUnit;
    friend class sUnitManager;
    friend class sZone;
    friend class uGUIMenuComm;
    friend class uOmSwingInstancing;
    friend class uSoundSubMixer;
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
public:
    MtSemaphore(const u32 initial_count, const u32 maximum_count, MT_CTSTR name);
    ~MtSemaphore();
    void release(const u32 count);
    void wait(const u32 time_out);
private:
    SceKernelSema mHandle;  // offset: 0x0
};

namespace nWin32Detour {
    class eventFlag
    {
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
}  // namespace nWin32Detour
