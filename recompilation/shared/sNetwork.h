#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetCore.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtObject.h"
#include "cSystem.h"
#include "nNetworkCallback.h"
#include "nNetworkQueue.h"
#include "nNetworkService.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtNetContext;
class MtNetCore;
struct MtNetError;
class MtNetFriendList;
struct MtNetSessionInfo;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class cNetGameServer;
namespace nNetwork { class BlockPool; }
namespace nNetwork { class Context; }
namespace nNetwork { class Session; }
namespace nNetwork { class SessionDatabase; }
namespace nNetwork { class Storage; }
namespace nNetwork { class Transport; }
namespace nNetwork { class VoiceChat; }
namespace nNetwork { namespace nAchievement { class Object; } }
namespace nNetwork { namespace nRanking { class Object; } }
namespace nNetwork { namespace nSharedMemory2 { class Object; } }
namespace nSessionManager { class cNetSessionManager; }
class sEventManager;
class sGame;

// Declarations
class sNetwork;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class sNetwork : public cSystem
{
    // inferred: cNetGameServer::startEquipGradeUp names sNetwork::mpInstance
    friend class cNetGameServer;
    // inferred: nNetwork::Context::reset calls sNetwork::notifyServiceStateChange
    friend class nNetwork::Context;
    // inferred: nNetwork::Session::~Session names sNetwork::mpInstance
    friend class nNetwork::Session;
    // inferred: nSessionManager::cNetSessionManager::setup names sNetwork::mpSession[0]
    friend class nSessionManager::cNetSessionManager;
    // inferred: sEventManager::setSyncReadyEvent names sNetwork::mpInstance
    friend class sEventManager;
    // inferred: sGame::isMySelfPartyMemberIndex names sNetwork::mpInstance
    friend class sGame;
public:
    enum
    {
        SERVICE_STATE_NULL = 0,
        SERVICE_STATE_BOOTUP = 1,
        SERVICE_STATE_NONE = 2,
        SERVICE_STATE_USER = 3,
        SERVICE_STATE_AUTH = 4,
        SERVICE_STATE_SHUTDOWN = 5,
        SERVICE_STATE_ERROR = 6,
        SERVICE_STATE_FATAL = 7,
        SERVICE_STATE_NUM = 8,
    };
    enum
    {
        INVITE_NOT_ACCEPT = 0,
        INVITE_IN_PROGRESS = 1,
        INVITE_SUCCESS = 2,
        INVITE_FAILURE = 3,
    };
    enum
    {
        CALLBACK_MESSAGE = 0,
        CALLBACK_CORE = 1,
        CALLBACK_CONNECT = 2,
        CALLBACK_SESSION = 3,
        CALLBACK_VOICE = 4,
        CALLBACK_SHM_STAR = 5,
        CALLBACK_SHM_MESH = 6,
        CALLBACK_USER = 7,
    };
public:
    class MyDTI;
public:
    using RECEIVE_CALLBACK = void(MtObject::*)(s32, const void*, u32);
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
    sNetwork(MtNetCore::InitParam* param);
    virtual ~sNetwork();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01b9ff40 - 0x01b9ff41 (1 bytes)
    virtual void createMenu(MtPropertyList&) {}  // vtable slot 8
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    static sNetwork* getInstance();
    void dbgGetSummary(MtString& sum, u32 option) const;
    void dbgSetShowSummary(bool f);
    bool dbgGetShowSummary() const;
    void setUnresponsiveLimit(u32);
    u32 getUnresponsiveLimit() const;
    void setService(s32);
    s32 getService() const;
    void setServiceOption(s32);
    s32 getServiceOption() const;
    u32 getServiceUserIndex() const;
    s32 getServiceState() const;
    void getServiceError(MtNetError* err) const;
    bool isServiceStart() const;
    bool isMultiContext() const;
    s32 getServiceOption(u32 user_index, s32 service) const;
    s32 getServiceState(u32 user_index, s32 service) const;
    void getServiceError(u32 user_index, MtNetError* err, s32 service) const;
    bool isServiceStart(u32 user_index, s32 service) const;
    bool isFatal() const;
    void getFatal(MtNetError* err) const;
    void suspend();
    void resume();
    bool isReadyForSuspend();
    bool isSuspend() const;
    void procError(const MtNetError* err);
    void bootupContext(u32 user_index, s32 sign_in_level, s32 service, s32 option);
    void shutdownContext(u32 user_index, s32 service);
    void shutdownContextAll(s32 service);
    MtNetContext* getContext();
    const MtNetContext* getContext() const;
    MtNetFriendList* getFriendList();
    bool isFriendListChange() const;
    MtNetContext* getContext(u32 user_index, s32 service);
    const MtNetContext* getContext(u32 user_index, s32 service) const;
    MtNetFriendList* getFriendList(u32 user_index, s32 service);
    bool isFriendListChange(u32 user_index, s32 service) const;
    s32 getSignInLevel(u32 user_index, s32 service) const;
    bool isSignInChange(u32 user_index, s32 service) const;
    bool isContextBoot() const;
    void shutdownContext();
    bool isInviteAccept(u32) const;
    s32 getInviteState(u32 user_index) const;
    void getInviteError(u32 user_index, MtNetError& err) const;
    void getInviteSessionInfo(u32 user_index, MtNetSessionInfo& info) const;
    void clearInvitation(u32 user_index);
    nNetwork::BlockPool& getTransportPool();
    const nNetwork::BlockPool& getTransportPool() const;
    virtual void bootupSession();  // vtable slot 10
    virtual void shutdownSession();  // vtable slot 11
    nNetwork::Session* getSession();
    const nNetwork::Session* getSession() const;
    nNetwork::Transport* getTransport();
    const nNetwork::Transport* getTransport() const;
    const nNetwork::SessionDatabase* getSessionDatabase() const;
    bool isMuteListChange() const;
    void notifyMuteListChange();
    bool isSessionBoot() const;
    void setReceiveCallback(u32 callback_index, MtObject* pobj, RECEIVE_CALLBACK callback);
    void clearReceiveCallback(u32 callback_index);
    bool isMultiSession() const;
    void bootupSessionEx(u32 session_num, const MtDTI& dti);
    nNetwork::Session* getSession(u32 session_index);
    nNetwork::Session* getSessionEx(u32 user_index, const MtDTI& dti);
    const nNetwork::Session* getSessionEx(u32 user_index, const MtDTI& dti) const;
    nNetwork::Session* getSessionEx(u32 user_index, s32 service);
    const nNetwork::Session* getSessionEx(u32 user_index, s32 service) const;
    void bootupSession(u32);
    void bootupSession(const MtDTI&);
    virtual void bootupRanking();  // vtable slot 12
    virtual void shutdownRanking();  // vtable slot 13
    bool isRankingBoot() const;
    nNetwork::nRanking::Object* getRanking();
    virtual void bootupAchievement();  // vtable slot 14
    void shutdownAchievement();
    bool isAchievementBoot() const;
    nNetwork::nAchievement::Object* getAchievement();
    virtual void bootupStorage();  // vtable slot 15
    virtual void shutdownStorage();  // vtable slot 16
    bool isStorageBoot() const;
    nNetwork::Storage* getStorage();
    virtual void bootupVoiceChat();  // vtable slot 17
    virtual void shutdownVoiceChat();  // vtable slot 18
    nNetwork::VoiceChat* getVoiceChat();
    bool isVoiceChatBoot() const;
    virtual void bootupSharedMemory(s32 type);  // vtable slot 19
    virtual void shutdownSharedMemory(s32 type);  // vtable slot 20
    nNetwork::nSharedMemory2::Object* getSharedMemory(s32 type);
    bool isSharedMemory(s32 type) const;
protected:
    virtual void onServiceStateChange(u32 user_index, s32 state, const MtNetError* err);  // vtable slot 21
    virtual void handleErrorMessage(const MtNetError& err);  // vtable slot 22
private:
    s32 getLogLevel() const;
    void setLogLevel(s32 level);
    void forceSingleService(s32 service, s32 option);
    u32 getServiceIndex() const;
    s32 getServiceIndex(u32 user_index, s32 service) const;
    s32 getSessionIndex(u32 user_index, s32 service) const;
    s32 getSessionIndex(u32 user_index, const MtDTI& dti) const;
    void notifyServiceStateChange(u32 user_index, s32 state, const MtNetError* err);
private:
    MtNetError mFatal;  // offset: 0x14
    MtNetCore* mpCore;  // offset: 0x20
    nNetwork::Context mContext[4];  // offset: 0x28
    nNetwork::Session* mpSession[4];  // offset: 0xa08
    nNetwork::nRanking::Object* mpRanking;  // offset: 0xa28
    nNetwork::VoiceChat* mpVoiceChat;  // offset: 0xa30
    nNetwork::nSharedMemory2::Object* mpSharedMemory[2];  // offset: 0xa38
    nNetwork::nAchievement::Object* mpAchievement;  // offset: 0xa48
    nNetwork::Storage* mpStorage;  // offset: 0xa50
    nNetwork::BlockPool mTransportPool;  // offset: 0xa58
    nNetwork::Receiver<MtObject> mCallbackEntry[16];  // offset: 0xaa0
    u32 mUnresponsiveLimit;  // offset: 0xd20
    MtNetTime::Total mLogTimer;  // offset: 0xd28
    bool mMuteListChange;  // offset: 0xd30
    bool mSuspend;  // offset: 0xd31
public:
    static MyDTI DTI;
    static const u32 MAX_NUM_CONTEXT = 4;
    static const u32 MAX_NUM_SESSION = 4;
    static const u32 MAX_NUM_CALLBACK = 16;
    static const u32 TRANSPORT_BUFFER_SIZE = 256;
    static const u32 MASK_PARAM = 65535;
    static const u32 UNRELIABLE_MIN = 0;
    static const u32 UNRELIABLE_MAX = 15;
    static const u32 UNRELIABLE = 4;
    static const u32 RELIABLE = 16;
    static const u32 ROUTE = 32;
    static const u32 VOICE = 64;
    static const u32 RPC = 128;
    static const u32 TAG = 256;
    static const u32 OFS_PROTOCOL = 16;
    static const u32 PROTOCOL_INDEX_0 = 0;
    static const u32 PROTOCOL_INDEX_1 = 65536;
    static const u32 PROTOCOL_INDEX_2 = 131072;
    static const u32 PROTOCOL_INDEX_3 = 196608;
    static const u32 PROTOCOL_COMMON = 0;
    static const u32 PROTOCOL_SYSTEM = 196608;
    static const u32 PROTOCOL_COMMON_UNREL = 4;
    static const u32 PROTOCOL_COMMON_RELIABLE = 16;
    static const u32 SUMMARY_SYSTEM = 1;
    static const u32 SUMMARY_ERROR = 2;
    static const u32 SUMMARY_TRAFFIC = 4;
    static const u32 SUMMARY_VOICE_CHAT = 8;
    static const u32 SUMMARY_TAG_CHECKER = 16;
    static const u32 SUMMARY_DEFAULT = 5;
    static const u32 SUMMARY_ALL = 31;
private:
    static sNetwork* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sNetwork* sNetwork::getInstance() {
    return ::sNetwork::mpInstance;
}
