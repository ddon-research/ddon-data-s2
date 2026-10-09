#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtPropertyList;

// Declarations
struct MtNetError;
class MtNetObject;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

struct MtNetError
{
public:
    enum
    {
        ECAUSE_NONE = 0,
        ECAUSE_XBOX = 16777216,
        ECAUSE_XBOX_XENUMERATE = 16842753,
        ECAUSE_XBOX_XFRIENDS_CREATE_ENUMERATOR = 16908289,
        ECAUSE_XBOX_XNET_CONNECT = 16973825,
        ECAUSE_XBOX_XNET_CREATE_KEY = 16973826,
        ECAUSE_XBOX_XNET_GET_BROADCAST_VERSION_STATUS = 16973827,
        ECAUSE_XBOX_XNET_GET_CONNECT_STATUS = 16973828,
        ECAUSE_XBOX_XNET_QOS_LOOKUP = 16973829,
        ECAUSE_XBOX_XNET_REGISTER_KEY = 16973830,
        ECAUSE_XBOX_XNET_REPLACE_KEY = 16973831,
        ECAUSE_XBOX_XNET_XNADDR_TO_INADDR = 16973832,
        ECAUSE_XBOX_XNET_DNS_LOOKUP = 16973833,
        ECAUSE_XBOX_XSESSION_ARBITRATION_REGSITER = 17039361,
        ECAUSE_XBOX_XSESSION_CREATE = 17039362,
        ECAUSE_XBOX_XSESSION_DELETE = 17039363,
        ECAUSE_XBOX_XSESSION_END = 17039364,
        ECAUSE_XBOX_XSESSION_JOIN_LOCAL = 17039365,
        ECAUSE_XBOX_XSESSION_JOIN_REMOTE = 17039366,
        ECAUSE_XBOX_XSESSION_LEAVE_LOCAL = 17039367,
        ECAUSE_XBOX_XSESSION_LEAVE_REMOTE = 17039368,
        ECAUSE_XBOX_XSESSION_MIGRATE_HOST = 17039369,
        ECAUSE_XBOX_XSESSION_MODIFY = 17039370,
        ECAUSE_XBOX_XSESSION_SEARCH_EX = 17039371,
        ECAUSE_XBOX_XSESSION_SEARCH_BY_ID = 17039372,
        ECAUSE_XBOX_XSESSION_START = 17039373,
        ECAUSE_XBOX_XSESSION_WRITE_STATS = 17039374,
        ECAUSE_XBOX_XSOCKET_BIND = 17104897,
        ECAUSE_XBOX_XSOCKET_CREATE = 17104898,
        ECAUSE_XBOX_XSOCKET_IOCTL_SOKCET = 17104899,
        ECAUSE_XBOX_XSOCKET_SET_SOCK_OPT = 17104900,
        ECAUSE_XBOX_XSTORAGE_BUILD_SERVER_PATH = 17170433,
        ECAUSE_XBOX_XSTORAGE_BUILD_SERVER_PATH_BY_XUID = 17170434,
        ECAUSE_XBOX_XSTORAGE_DELETE = 17170435,
        ECAUSE_XBOX_XSTORAGE_DOWNLOAD_TO_MEMORY = 17170436,
        ECAUSE_XBOX_XSTORAGE_ENUMERATE = 17170437,
        ECAUSE_XBOX_XSTORAGE_UPLOAD_FROM_MEMORY = 17170438,
        ECAUSE_XBOX_XSHOW_FRIENDS_UI = 17235969,
        ECAUSE_XBOX_XSHOW_GAME_INVITE_UI = 17235970,
        ECAUSE_XBOX_XSHOW_SIGNIN_UI = 17235971,
        ECAUSE_XBOX_XSTRING_VERIFY = 17301505,
        ECAUSE_XBOX_XUSER_CREATE_STATS_ENUMERATOR_BY_RANK = 17367041,
        ECAUSE_XBOX_XUSER_CREATE_STATS_ENUMERATOR_BY_XUID = 17367042,
        ECAUSE_XBOX_XUSER_ESTIMATE_RANK_FOR_RATING = 17367043,
        ECAUSE_XBOX_XUSER_READ_STATS = 17367044,
        ECAUSE_XBOX_XUSER_READ_PROFILE_SETTINGS = 17367045,
        ECAUSE_XBOX_XUSER_READ_PROFILE_SETTINGS_BY_XUID = 17367046,
        ECAUSE_XBOX_XUSER_WRITE_ACHIEVEMENTS = 17367047,
        ECAUSE_WINDOWS = 33554432,
        ECAUSE_PS3 = 50331648,
        ECAUSE_GFWL = 67108864,
        ECAUSE_GFWL_XLIVE_CREATE_PROTECTED_DATA_CONTEXT = 67174401,
        ECAUSE_GFWL_XLIVE_QUERY_PROTECTED_DATA_INFORMATION = 67174402,
        ECAUSE_5 = 83886080,
        ECAUSE_6 = 100663296,
        ECAUSE_VITA = 117440512,
        ECAUSE_XBOXONE = 218103808,
        ECAUSE_XBOXONE_MULTIPLAYER_WRITE_SESSION_ASYNC = 218169345,
        ECAUSE_XBOXONE_PARTY_REGISTER_GAME_SESSION_ASYNC = 218234881,
    };
public:
    s32 mNo;  // offset: 0x0
    s32 mCause;  // offset: 0x4
    s32 mNative;  // offset: 0x8
    static const s32 NONE = 0;
    static const s32 GENERAL = -2147483648;
    static const s32 CORE_NO_ENOUGH_MEMORY = -2130771967;
    static const s32 CORE_INVALID_ARGUMENT = -2130771966;
    static const s32 CORE_API_REQUEST = -2130771951;
    static const s32 CORE_API_RESULT = -2130771950;
    static const s32 CORE_APP_SUSPEND = -2130771919;
    static const s32 CORE_APP_SHUTDOWN = -2130771918;
    static const s32 SOCKET_GENERAL = -2147418112;
    static const s32 SOCKET_NO_ENOUGH_MEMORY = -2147418111;
    static const s32 SOCKET_INVALID_ARGUMENT = -2147418110;
    static const s32 SOCKET_NOT_PROVIDED = -2147418109;
    static const s32 SOCKET_ALREADY_INITIALIZED = -2147418108;
    static const s32 SOCKET_NOT_INITIALIZED = -2147418107;
    static const s32 SOCKET_EARLY_DESTRUCT = -2147418106;
    static const s32 SOCKET_NO_DEPENDENT_OBJECT = -2147418104;
    static const s32 SOCKET_API_RESULT = -2147418095;
    static const s32 SOCKET_CREATE_DESCRIPTOR = -2147418063;
    static const s32 SOCKET_SET_OPTION = -2147418062;
    static const s32 SOCKET_GET_OPTION = -2147418061;
    static const s32 SOCKET_CONNECT = -2147418060;
    static const s32 SOCKET_BIND = -2147418059;
    static const s32 SOCKET_LISTEN = -2147418058;
    static const s32 SOCKET_ACCEPT = -2147418057;
    static const s32 SOCKET_SEND_SELF = -2147418056;
    static const s32 SOCKET_SEND_PEER = -2147418055;
    static const s32 SOCKET_RECV_SELF = -2147418054;
    static const s32 SOCKET_RECV_PEER = -2147418053;
    static const s32 SOCKET_DISCONNECT_PEER = -2147418052;
    static const s32 RESOLVER_GENERAL = -2147352576;
    static const s32 RESOLVER_NO_ENOUGH_MEMORY = -2147352575;
    static const s32 RESOLVER_INVALID_ARGUMENT = -2147352574;
    static const s32 RESOLVER_NOT_PROVIDED = -2147352573;
    static const s32 RESOLVER_ALREADY_INITIALIZED = -2147352572;
    static const s32 RESOLVER_NOT_INITIALIZED = -2147352571;
    static const s32 RESOLVER_NO_DEPENDENT_OBJECT = -2147352568;
    static const s32 RESOLVER_API_RESULT = -2147352559;
    static const s32 RESOLVER_API_REQUEST = -2147352558;
    static const s32 RESOLVER_NO_RESULT = -2147352527;
    static const s32 P2P_GENERAL = -2147287040;
    static const s32 P2P_NO_ENOUGH_MEMORY = -2147287039;
    static const s32 P2P_INVALID_ARGUMENT = -2147287038;
    static const s32 P2P_NOT_PROVIDED = -2147287037;
    static const s32 P2P_ALREADY_INITIALIZED = -2147287036;
    static const s32 P2P_NOT_INITIALIZED = -2147287035;
    static const s32 P2P_EARLY_DESTRUCT = -2147287034;
    static const s32 P2P_NO_DEPENDENT_OBJECT = -2147287032;
    static const s32 P2P_DATA_BROKEN = -2147287030;
    static const s32 P2P_DATA_TOO_BIG = -2147287029;
    static const s32 P2P_ADDR_TOO_MANY = -2147287028;
    static const s32 P2P_CONNECT_API_RESULT = -2147287023;
    static const s32 P2P_CONNECT_TIMEOUT = -2147287022;
    static const s32 P2P_CONNECT_DNS = -2147287021;
    static const s32 P2P_STATUS_API_RESULT = -2147287020;
    static const s32 P2P_STATUS_DISCONNECT = -2147287019;
    static const s32 P2P_DBG_FORCE = -2147286991;
    static const s32 P2P_ERROR_NET = -2147286990;
    static const s32 P2P_NORECV_TIMEOUT = -2147286989;
    static const s32 P2P_SEND_SELF = -2147286988;
    static const s32 P2P_SEND_PEER = -2147286987;
    static const s32 P2P_RECV_SELF = -2147286986;
    static const s32 P2P_RECV_PEER = -2147286985;
    static const s32 P2P_ABORT_REQUEST = -2147286984;
    static const s32 STORAGE_GENERAL = -2146828288;
    static const s32 STORAGE_NO_ENOUGH_MEMORY = -2146828287;
    static const s32 STORAGE_INVALID_ARGUMENT = -2146828286;
    static const s32 STORAGE_NOT_PROVIDED = -2146828285;
    static const s32 STORAGE_ALREADY_INITIALIZED = -2146828284;
    static const s32 STORAGE_NOT_INITIALIZED = -2146828283;
    static const s32 STORAGE_EARLY_DESTRUCT = -2146828282;
    static const s32 STORAGE_EVENT_TOO_MANY = -2146828281;
    static const s32 STORAGE_NO_DEPENDENT_OBJECT = -2146828280;
    static const s32 STORAGE_FILE_NOT_FOUND = -2146828279;
    static const s32 STORAGE_API_REQUEST = -2146828271;
    static const s32 STORAGE_API_RESULT = -2146828270;
    static const s32 STORAGE_ALREADY_DISPLAY = -2146828269;
    static const s32 STORAGE_ERROR_NET = -2146828239;
    static const s32 STORAGE_ABORT_REQUEST = -2146828238;
    static const s32 STORAGE_ALREADY_REQUEST = -2146828237;
    static const s32 STORAGE_USER_CANCEL = -2146828236;
    static const s32 ACHIEVEMENT_GENERAL = -2146762752;
    static const s32 ACHIEVEMENT_NO_ENOUGH_MEMORY = -2146762751;
    static const s32 ACHIEVEMENT_INVALID_ARGUMENT = -2146762750;
    static const s32 ACHIEVEMENT_NOT_PROVIDED = -2146762749;
    static const s32 ACHIEVEMENT_ALREADY_INITIALIZED = -2146762748;
    static const s32 ACHIEVEMENT_NOT_INITIALIZED = -2146762747;
    static const s32 ACHIEVEMENT_EARLY_DESTRUCT = -2146762746;
    static const s32 ACHIEVEMENT_NO_DEPENDENT_OBJECT = -2146762744;
    static const s32 ACHIEVEMENT_API_REQUEST = -2146762735;
    static const s32 ACHIEVEMENT_API_RESULT = -2146762734;
    static const s32 ACHIEVEMENT_ALREADY_DISPLAY = -2146762733;
    static const s32 ACHIEVEMENT_ERROR_NET = -2146762703;
    static const s32 ACHIEVEMENT_USER_CANCEL = -2146762702;
    static const u32 MASK_METHOD = 4294967040;
    static const u32 MASK_CAUSE = 255;
    static const s32 CAUSE_COMMON_DEBUG = 1;
    static const s32 CAUSE_COMMON_NO_ENOUGH_MEMORY = 17;
    static const s32 CAUSE_COMMON_INVALID_ARGUMENT = 18;
    static const s32 CAUSE_COMMON_NOT_PROVIDED = 19;
    static const s32 CAUSE_COMMON_ALREADY_INITIALIZED = 20;
    static const s32 CAUSE_COMMON_NOT_INITIALIZED = 21;
    static const s32 CAUSE_COMMON_EARLY_DESTRUCT = 22;
    static const s32 CAUSE_COMMON_EVENT_TOO_MANY = 23;
    static const s32 CAUSE_COMMON_NO_DEPENDENT_OBJECT = 24;
    static const s32 CAUSE_COMMON_DATA_BROKEN = 25;
    static const s32 CAUSE_COMMON_DATA_TOO_BIG = 26;
    static const s32 CAUSE_COMMON_ADDR_TOO_MANY = 27;
    static const s32 CAUSE_COMMON_EVENT_LEFTOVER = 28;
    static const s32 CAUSE_COMMON_EVENT_DATA_TOO_BIG = 29;
    static const s32 CAUSE_COMMON_DATA_MISMATCH = 30;
    static const s32 CAUSE_COMMON_OUT_OF_RANGE = 31;
    static const s32 CAUSE_COMMON_ABORT = 49;
    static const s32 CAUSE_COMMON_TIMEOUT = 65;
    static const s32 CAUSE_COMMON_DNS_TIMEOUT = 66;
    static const s32 CAUSE_COMMON_LOW_LEVEL = 81;
    static const s32 CAUSE_COMMON_NATIVE_API = 82;
    static const s32 CAUSE_COMMON_APP_SUSPEND = 97;
    static const s32 CAUSE_COMMON_APP_SHUTDOWN = 98;
    static const s32 CAUSE_COMMON_ALREADY_DISPLAY = 113;
    static const s32 CAUSE_CONTEXT_IP_RELEASED = 129;
    static const s32 CAUSE_CONTEXT_LINK_STATE_INACTIVE = 130;
    static const s32 CAUSE_CONTEXT_LOST_AUTH = 131;
    static const s32 CAUSE_CONTEXT_NOT_AUTH = 132;
    static const s32 CAUSE_CONTEXT_BANNED = 133;
    static const s32 CAUSE_CONTEXT_EXPIRE = 134;
    static const s32 CAUSE_CONTEXT_SERVER_FULL = 135;
    static const s32 CAUSE_CONTEXT_SERVER_ACCESS_LIMITED = 136;
    static const s32 CAUSE_CONTEXT_USER_ACCESS_LIMITED = 137;
    static const s32 CAUSE_CONTEXT_USER_CHANGED = 138;
    static const s32 METHOD_CONTEXT_MOVE = -2147483648;
    static const s32 METHOD_CONTEXT_START = -2147483392;
    static const s32 CAUSE_SESSION_HOST_ONLY = 129;
    static const s32 CAUSE_SESSION_P2P_NOT_CONNECT = 130;
    static const s32 CAUSE_SESSION_NO_HOST = 131;
    static const s32 CAUSE_SESSION_FULL = 132;
    static const s32 CAUSE_SESSION_LOCKED = 133;
    static const s32 CAUSE_SESSION_IS_NOT_EXIST = 134;
    static const s32 CAUSE_SESSION_ALREADY_EXIST = 135;
    static const s32 CAUSE_SESSION_HOST_DENY = 136;
    static const s32 CAUSE_SESSION_DUPLICATE_JOIN = 137;
    static const s32 CAUSE_SESSION_PORT_NOT_OPEN = 138;
    static const s32 CAUSE_SESSION_DISALLOW = 139;
    static const s32 CAUSE_SESSION_INCOMPATIBLE = 140;
    static const s32 CAUSE_SESSION_IS_NOT_STARTED = 141;
    static const s32 CAUSE_SESSION_ALREADY_STARTED = 142;
    static const s32 CAUSE_SESSION_NO_RESPONSE = 143;
    static const s32 METHOD_SESSION_MOVE = -2147155968;
    static const s32 METHOD_SESSION_CREATE = -2147155712;
    static const s32 METHOD_SESSION_SEARCH = -2147155456;
    static const s32 METHOD_SESSION_JOIN = -2147155200;
    static const s32 METHOD_SESSION_LOCK = -2147154688;
    static const s32 METHOD_SESSION_INVITE = -2147154432;
    static const s32 METHOD_SESSION_START = -2147154176;
    static const s32 METHOD_SESSION_END = -2147153920;
    static const s32 METHOD_RANKING_MOVE = -2146893824;
    static const s32 METHOD_RANKING_UPDATE = -2146893568;
    static const s32 METHOD_RANKING_GET_SCORE_LIST_BY_RANGE = -2146893312;
    static const s32 METHOD_RANKING_GET_SCORE_LIST_BY_UNIQUE_ID = -2146893056;
    static const s32 METHOD_RANKING_GET_ATTACH = -2146892800;
};

class MtNetObject : public MtObject
{
public:
    class MyDTI;
    class ScopedLock;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class ScopedLock
    {
    public:
        ScopedLock(MtNetObject* objPtr);
        ~ScopedLock();
    private:
        MtNetObject* mObjPtr;  // offset: 0x0
    };
public:
    static MtDTI* getMyDTIPtr();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void operator delete(void* p_addr);
    static void usage();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    MtNetObject();
    virtual ~MtNetObject();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool isFatal() const;  // vtable slot 6
    virtual void getFatal(MtNetError* err);  // vtable slot 7
protected:
    void lock();
    void unlock();
    s32 getLockCount();
    virtual void clearFatal();  // vtable slot 8
    virtual void setFatal(const MtNetError* err);  // vtable slot 9
    virtual void setFatal(s32 no, s32 cause, s32 native);  // vtable slot 10
private:
    MtCriticalSection mCS;  // offset: 0x8
    bool mIsThreadSafe;  // offset: 0x10
    s32 mLockCount;  // offset: 0x14
    MtNetError mFatal;  // offset: 0x18
public:
    static MyDTI DTI;
};
