#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "np_common.h"

// Forward declarations
class MtCriticalSection;
namespace MtNet { namespace PS4Psn { class Context; } }
class MtNetAchievement;
class MtNetContext;
struct MtNetIpAddress;
class MtNetP2p;
struct MtNetPhysicalAddress;
class MtNetRanking;
class MtNetSession;
class MtNetSocket;
class MtNetStorage;
class MtNetStorage2;
class MtNetUniqueId;
class MtPropertyList;
struct SceNpClientId;
struct SceNpContentRestriction;
struct SceNpId;
struct SceNpOnlineId;
struct SceNpPartyMemberVoiceInfo;
struct SceNpTitleId;
struct SceNpTitleSecret;

// Declarations
class MtNetCore;

// Type aliases from DWARF
using MT_CHAR = char;
using __uint16_t = unsigned short;
using uint16_t = __uint16_t;
using SceNpMatching2ContextId = uint16_t;
using SceNpMatching2Event = uint16_t;
using SceNpMatching2EventCause = unsigned char;
using __uint8_t = unsigned char;
using uint8_t = __uint8_t;
using SceNpPartyBinaryMessageEvent = uint8_t;
using SceNpPartyRoomEventType = uint16_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpServiceLabel = uint32_t;
using __int32_t = int;
using int32_t = __int32_t;
using SceUserServiceUserId = int32_t;
using __uint64_t = long unsigned int;
using s32 = int;
using u32 = unsigned int;
using u64 = __uint64_t;

class MtNetCore : public MtNetObject
{
    // inferred: MtNet::PS4Psn::Context::isIpObtained names MtNetCore::mpInstance
    friend class MtNet::PS4Psn::Context;
public:
    enum
    {
        SERVICE_OPTION_DEFAULT = 0,
        SERVICE_OPTION_LAMM = 1,
        SERVICE_OPTION_STORAGE_LOCAL = 2,
        SERVICE_OPTION_STORAGE_COMMON = 4,
        SERVICE_OPTION_STORAGE_TYPE_TITLE = 8,
        SERVICE_OPTION_STORAGE_TYPE_USER = 16,
        SERVICE_OPTION_TICKET = 32,
    };
    enum
    {
        SOCKET_LIB_NONE = 0,
        SOCKET_LIB_BSD = 1,
        SOCKET_LIB_WINSOCK = 2,
        SOCKET_LIB_SNL = 3,
        SOCKET_LIB_PSN = 4,
        SOCKET_LIB_VITA_PSN = 5,
        SOCKET_LIB_VITA_ADHOC = 6,
        SOCKET_LIB_WXN = 7,
        SOCKET_LIB_PS4_PSN = 8,
    };
    enum
    {
        SERVICE_NONE = 0,
        SERVICE_LIVE = 1,
        SERVICE_PSN = 2,
        SERVICE_UDS = 3,
        SERVICE_NEX = 4,
        SERVICE_5 = 5,
        SERVICE_WINSOCK = 6,
        SERVICE_CID = 7,
        SERVICE_8 = 8,
        SERVICE_VITA_PSN = 9,
        SERVICE_VITA_ADHOC = 10,
        SERVICE_11 = 11,
        SERVICE_12 = 12,
        SERVICE_NNAC = 13,
        SERVICE_14 = 14,
        SERVICE_15 = 15,
        SERVICE_16 = 16,
        SERVICE_17 = 17,
        SERVICE_18 = 18,
        SERVICE_19 = 19,
        SERVICE_XBOXONE_LIVE = 20,
        SERVICE_PS4_PSN = 21,
        SERVICE_STEAM = 22,
    };
public:
    struct InitParam;
public:
    struct InitParam
    {
    public:
        SceNpTitleId mNpTitleId;  // offset: 0x0
        SceNpTitleSecret mNpTitleSecret;  // offset: 0x10
        SceNpServiceLabel mNpServiceLabel;  // offset: 0x90
        SceNpClientId mNpClientId;  // offset: 0x94
        SceNpContentRestriction mNpContentRestriction;  // offset: 0x120
        bool mIsShowErrorDisuse;  // offset: 0x138
        bool mIsPrgContextDisuse;  // offset: 0x139
        bool mIsErrorContextDisuse;  // offset: 0x13a
        bool mIsAvailContextDisuse;  // offset: 0x13b
        bool mIsAutoTicketDisuse;  // offset: 0x13c
        bool mIsTrophyDisuse;  // offset: 0x13d
        bool mIsChatDisuse;  // offset: 0x13e
        bool mIsUgcDisuse;  // offset: 0x13f
        bool mIsHttpClientDisuse;  // offset: 0x140
        bool mIsPsPlusDisuse;  // offset: 0x141
        bool mIsPsnTicketDisuse;  // offset: 0x142
        bool mIsPsnFriendDisuse;  // offset: 0x143
        bool mIsPsnProfileDisuse;  // offset: 0x144
        bool mIsPsnPresenceDisuse;  // offset: 0x145
        bool mIsPsnMatchingDisuse;  // offset: 0x146
        bool mIsPsnRankingDisuse;  // offset: 0x147
        bool mIsPsnTitleStorageDisuse;  // offset: 0x148
        bool mIsPsnUserStorageDisuse;  // offset: 0x149
        bool mIsPsnPartyDisuse;  // offset: 0x14a
        bool mIsPsnEntitlementDisuse;  // offset: 0x14b
    };
public:
    static MtNetCore* getInstance();
    static void onGuideOpen(bool is_open);
    static void onGuideSignInChanged(s32 state);
    static void onGuideConnectionChanged(void* data_ptr);
    static void onGuideInviteAccepted(s32 user_index, void* data_ptr);
    static void onGuidePhysicalLinkChanged(bool is_link);
    static void onGuideFriendListChanged(s32 user_index, s32 action);
    static void onGuideAppSuspend();
    static void onGuideAppShutdown();
    MtNetCore(void* param);
    virtual ~MtNetCore();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void addDependency(MtNetObject* obj);
    void removeDependency(MtNetObject* obj);
    void addContext(MtNetContext* context);
    void removeContext(MtNetContext* context);
    void move();
    void reset();
    MtNetContext* newContext(s32 user_index, s32 service, u32 service_option);
    MtNetSession* newSession(MtNetContext* context, s32 service, u32 service_option);
    MtNetP2p* newP2p(MtNetContext* context, s32 service, u32 service_option);
    MtNetSocket* newSocket(s32 socket_lib, s32 socket_type, u32 socket_option);
    MtNetRanking* newRanking(MtNetContext* context);
    MtNetStorage* newStorage(MtNetContext* context, s32 type, s32 access_to, MT_CHAR* filename, MtNetUniqueId* uniq_id);
    MtNetStorage2* newStorage2(MtNetContext* context, s32 service, u32 service_option);
    MtNetAchievement* newAchievement();
private:
    static void staticLock();
    static void staticUnlock();
    static s32 getStaticLockCount();
    void nativeConstructor(void* param);
    void nativeDestructor();
    void nativeCreateProperty(MtPropertyList& s);
    void nativeMove();
    void nativeReset();
public:
    bool isIpObtained();
    bool isPhysicalLink();
    void getIpAddress(MtNetIpAddress* address);
    void getPhysicalAddress(MtNetPhysicalAddress* address);
    MtNetContext* getContext(s32 index);
private:
    static void netCtlCallback(int event_type, void* arg_ptr);
    static void npStateCallback(SceUserServiceUserId user_id, SceNpState np_state, SceNpId* np_id_ptr, void* arg_ptr);
    static void npPresenceCallback(const SceNpOnlineId* online_id_ptr, SceNpGamePresenceStatus status, void* arg_ptr);
    static void npMatchContextCallback(SceNpMatching2ContextId context_id, SceNpMatching2Event event_id, SceNpMatching2EventCause event_cause, int error_code, void* arg_ptr);
    static void npPartyRoomCallback(SceNpPartyRoomEventType event_type, const void* data_ptr, void* arg_ptr);
    static void npPartyVoiceCallback(const SceNpPartyMemberVoiceInfo* member_voice_info, void* arg_ptr);
    static void npPartyBinaryMessageCallback(SceNpPartyBinaryMessageEvent event_type, const void* data_ptr, void* arg_ptr);
private:
    MtNetObject* mpDependObject[4];  // offset: 0x28
    int mNetCtlCallbackId;  // offset: 0x48
    MtNetIpAddress mIpAddress;  // offset: 0x4c
    MtNetPhysicalAddress mPhysicalAddress;  // offset: 0x50
    MtNetTime::Total mPhysicalCheckLastTime;  // offset: 0x58
    bool mIsPhysicalLink;  // offset: 0x60
    int mHttpNetMemId;  // offset: 0x64
    bool mIsIpObtained;  // offset: 0x68
public:
    static const s32 MAX_NUM_CONTEXT = 4;
private:
    static const s32 MAX_NUM_DEPEND_OBJECT = 4;
    static MtCriticalSection mStaticCS;
    static s32 mStaticLockCount;
    static MtNetCore* mpInstance;
    static MtNetContext* mpContext[4];
public:
    static const u64 TICK_OF_EPOCH_ORIGINS = 62135596800000000;
};
