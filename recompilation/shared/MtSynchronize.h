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
class sBakingJointOrder;
class sBrowser;
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
class sShlManager;
class sSound;
class sSoundManager;
class sUnit;
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
    // inferred: MtNetContext::addDependency names MtCriticalSection::mCSection
    friend class MtNetContext;
    // inferred: MtNetCore::addDependency names MtCriticalSection::mCSection
    friend class MtNetCore;
    // inferred: MtNetMediator::setLibsslContextId names MtCriticalSection::mCSection
    friend class MtNetMediator;
    // inferred: MtNetObject::setFatal names MtCriticalSection::mCSection
    friend class MtNetObject;
    // inferred: MtThread::lock names MtCriticalSection::mCSection
    friend class MtThread;
    // inferred: aStage::setFsmEvent names MtCriticalSection::mCSection
    friend class aStage;
    // inferred: cAcquirement::cSkillDataBase::updateLoad names MtCriticalSection::mCSection
    friend class cAcquirement::cSkillDataBase;
    // inferred: cNetGameServer::getReportCheatQueue names MtCriticalSection::mCSection
    friend class cNetGameServer;
    // inferred: cSoundLimitter::setEnable names MtCriticalSection::mCSection
    friend class cSoundLimitter;
    // inferred: cZoneMultiStack::releaseZoneAll names MtCriticalSection::mCSection
    friend class cZoneMultiStack;
    // inferred: nNetwork::VoiceChat::init names MtCriticalSection::mCSection
    friend class nNetwork::VoiceChat;
    // inferred: rSoundSourceStreamAT9::close names MtCriticalSection::mCSection
    friend class rSoundSourceStreamAT9;
    // inferred: sAIPawnSys::releaseAIPawnRotateNo names MtCriticalSection::mCSection
    friend class sAIPawnSys;
    // inferred: sArchiveManager::move names MtCriticalSection::mCSection
    friend class sArchiveManager;
    // inferred: sBakingJointOrder::removeProtectUnits names MtCriticalSection::mCSection
    friend class sBakingJointOrder;
    // inferred: sBrowser::resetJSCallback_jumpSetPosSize names MtCriticalSection::mCSection
    friend class sBrowser;
    // inferred: sCameraExt::setMotionCamera names MtCriticalSection::mCSection
    friend class sCameraExt;
    // inferred: sCaplinkManager::getIconUrlFromIndex names MtCriticalSection::mCSection
    friend class sCaplinkManager;
    // inferred: sChat::setTellChat names MtCriticalSection::mCSection
    friend class sChat;
    // inferred: sCollision::lockSystem names MtCriticalSection::mCSection
    friend class sCollision;
    // inferred: sContextManager::removeAllContextPartyPlayer names MtCriticalSection::mCSection
    friend class sContextManager;
    // inferred: sEffect::getAdhesionLimitMax names MtCriticalSection::mCSection
    friend class sEffect;
    // inferred: sEffectExt::addInvalidHandle names MtCriticalSection::mCSection
    friend class sEffectExt;
    // inferred: sGUI::releaseAlphaMap names MtCriticalSection::mCSection
    friend class sGUI;
    // inferred: sGUIExt::movePointer names MtCriticalSection::mCSection
    friend class sGUIExt;
    // inferred: sInputManager::writeData names MtCriticalSection::mCSection
    friend class sInputManager;
    // inferred: sItemManager::getGp names MtCriticalSection::mCSection
    friend class sItemManager;
    // inferred: sNetwork::forceSingleService names MtCriticalSection::mCSection
    friend class sNetwork;
    // inferred: sObjCollision::createUID names MtCriticalSection::mCSection
    friend class sObjCollision;
    // inferred: sOccluder::add names MtCriticalSection::mCSection
    friend class sOccluder;
    // inferred: sOmManager::releaseTreeInsCtrl names MtCriticalSection::mCSection
    friend class sOmManager;
    // inferred: sPrimitive::reserveBuffer names MtCriticalSection::mCSection
    friend class sPrimitive;
    // inferred: sQuestManagerExt::notifyReloadMasterData names MtCriticalSection::mCSection
    friend class sQuestManagerExt;
    // inferred: sRender::addProtectResource names MtCriticalSection::mCSection
    friend class sRender;
    // inferred: sResource::isLoading names MtCriticalSection::mCSection
    friend class sResource;
    // inferred: sScene::attach names MtCriticalSection::mCSection
    friend class sScene;
    // inferred: sSetManager::clearQuestList names MtCriticalSection::mCSection
    friend class sSetManager;
    // inferred: sShadow::reset names MtCriticalSection::mCSection
    friend class sShadow;
    // inferred: sShlManager::getShlUniqueId names MtCriticalSection::mCSection
    friend class sShlManager;
    // inferred: sSound::NativeSystem::updateVoice names MtCriticalSection::mCSection, through its enclosing class sSound
    friend class sSound;
    // inferred: sSoundManager::setCycleZone names MtCriticalSection::mCSection
    friend class sSoundManager;
    // inferred: sUnit::addBottom names MtCriticalSection::mCSection
    friend class sUnit;
    // inferred: sZone::addZoneLayout names MtCriticalSection::mCSection
    friend class sZone;
    // inferred: uGUIMenuComm::updateWaitTmpPhrase names MtCriticalSection::mCSection
    friend class uGUIMenuComm;
    // inferred: uOmSwingInstancing::delInstance names MtCriticalSection::mCSection
    friend class uOmSwingInstancing;
    // inferred: uSoundSubMixer::setResourceSubMixer names MtCriticalSection::mCSection
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
