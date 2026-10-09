#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetBuffer.h"
#include "MtNetObject.h"
#include "MtNetSession.h"
#include "MtObject.h"
#include "MtRandom.h"
#include "nNetworkCallback.h"
#include "nNetworkSessionDriver.h"
#include "nNetworkTagChecker.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtNetError;
class MtNetSession;
struct MtNetSessionInfo;
class MtNetUniqueId;
class MtProperty;
class MtPropertyList;
class MtRandom;
class MtString;
class MtUI;
class cRemoteCall;
namespace nNetwork { class BlockPool; }
namespace nNetwork { class Callback; }
namespace nNetwork { class Connect; }
namespace nNetwork { class Match; }
namespace nNetwork { class Route; }
namespace nNetwork { class RpcNetSystem_Leave; }
namespace nNetwork { class SessionDatabase; }
namespace nNetwork { class SessionDriver; }
namespace nNetwork { class SessionListener; }
namespace nNetwork { class TagChecker; }
namespace nNetwork { class Transport; }
class sNetwork;

// Declarations
namespace nNetwork { class Session; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nNetwork {
    class Session : public ::MtObject
    {
        // inferred: nNetwork::Connect::onNtcDrop names nNetwork::Session::mDriver.mpDriver
        friend class nNetwork::Connect;
        // inferred: nNetwork::SessionDriver::onNtcDrop names nNetwork::Session::mpDatabase
        friend class nNetwork::SessionDriver;
        // inferred: nNetwork::TagChecker::~TagChecker names nNetwork::Session::mpPool
        friend class nNetwork::TagChecker;
        // inferred: sNetwork::getSessionDatabase names nNetwork::Session::mpDatabase
        friend class ::sNetwork;
    public:
        enum
        {
            STATE_DEAD = 0,
            STATE_OFFLINE = 1,
            STATE_ONLINE = 2,
            STATE_CREATE = 3,
            STATE_SEARCH = 4,
            STATE_JOIN = 5,
            STATE_FINAL = 6,
            STATE_START = 7,
            STATE_END = 8,
            STATE_LOCK = 9,
            STATE_UNLOCK = 10,
            STATE_INVITE = 11,
            STATE_NUM = 12,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        Session();
        virtual ~Session();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void setup();  // vtable slot 6
        virtual void move();  // vtable slot 7
        virtual void send();  // vtable slot 8
        virtual void recv();  // vtable slot 9
        nNetwork::Connect* getConnect();
        const nNetwork::Connect* getConnect() const;
        nNetwork::Transport* getTransport();
        const nNetwork::Transport* getTransprot() const;
        nNetwork::BlockPool* getPool();
        const nNetwork::BlockPool* getPool() const;
        virtual void dbgGetSummary(MtString& sum);  // vtable slot 10
        virtual void dbgPrintLog();  // vtable slot 11
        void setAttr(u32 attr);
        u32 getAttr() const;
        void getLastError(MtNetError&) const;
        void drop(MtNetError* pe);
        void dbgDrop(MtNetError* pe);
        void dbgRouteDrop(s32 route_index);
        void dbgRouteFail(s32 route_index, s32 time);
        u32 getUserIndex() const;
        s32 getService() const;
        s32 getState() const;
        const nNetwork::SessionDatabase* getSessionDatabase() const;
        MtNetSession* getDriver();
        const nNetwork::SessionDriver* getSessionDriver();
        bool isInit() const;
        s32 checkTag(s32, u32) const;
        s32 checkTag(u32) const;
        const nNetwork::TagChecker* getTagChecker() const;
        const MtNetUniqueId& getUniqueId() const;
        bool callback(u32 callback_index, s32 route_index, const void* data_ptr, u32 data_size);
        nNetwork::Callback& getCallback();
        const nNetwork::Callback& getCallback() const;
        void setBuffering(bool);
        bool isBuffering() const;
        void setSmoothing(bool);
        bool isSmoothing() const;
        void flushBuffer();
        void smoothBuffer();
        void setSelfBuffering(bool);
        bool isSelfBuffering() const;
        void startSelfDelay(u32);
        void stopSelfDelay();
        bool init();
        bool init(u32 user_index, s32 service);
        bool create();
        bool search();
        bool join();
        bool join(const MtNetSessionInfo*);
        bool join(u32);
        bool final();
        bool lock();
        bool unlock();
        bool start();
        bool end();
        bool invite();
        void abortRequest();
        void kill();
        bool unentry();
        bool entry();
        bool cancel();
        bool match();
        bool terminate();
        void setSearchKeyList(const MtNetSessionInfo::SearchKeyList*);
        const MtNetSessionInfo::SearchKeyList& getSearchKeyList() const;
        void setBinary(const MtNetSessionInfo::Binary*);
        const MtNetSessionInfo::Binary& getBinary() const;
        s32 getPrivateNumMax() const;
        void setPrivateNumMax(s32);
        s32 getJoinNumMax() const;
        void setJoinNumMax(s32);
        void setSearchKeyFilterList(const MtNetSession::SearchKeyFilterList* filter);
        const MtNetSession::SearchKeyFilterList& getSearchKeyFilterList() const;
        s32 getSearchOption() const;
        void setSearchOption(s32);
        s32 getSearchNumMax() const;
        void setSearchNumMax(s32);
        void clearSearchResult();
        void setSelfConfig(const u8* conf);
        void selectJoinSession(u32 index);
        void setJoinSession(const MtNetSessionInfo* info);
        void setCanHost(bool);
        bool isCanHost() const;
        bool addListener(nNetwork::SessionListener* p);
        void removeListener(nNetwork::SessionListener* p);
        void put(const void* buf, s32 size, s32 dst, u32 option, u32 callback_index);
        void setGroup(s32, u32);
        void setGroupMember(s32, u32, bool);
        void setGroupMemberList(u32, s32*, u32);
        bool checkDst(s32 member_index, s32 dst) const;
        void setMute(s32 member_index, bool f);
        void updateMute(s32 member_index);
        void setRestrict(s32 member_index, bool f);
        nNetwork::Route& getRoute(s32 route_index);
    protected:
        virtual void sendMessage(s32 index, cRemoteCall& call);  // vtable slot 12
        virtual void recvMessage(s32 index, const void* data_ptr, u32 data_size);  // vtable slot 13
        void process(s32 src, cRemoteCall* prpc);
    private:
        void createDriver();
        void removeDriver();
        void updateUniqueId();
        void procLeave(nNetwork::RpcNetSystem_Leave& message, s32 member_index);
        void onCreateComplete(bool flag, MtNetError* err);
        void onSearchComplete(bool flag, MtNetError* err);
        void onJoinComplete(bool flag, MtNetError* err);
        void onLockComplete(bool flag, bool lock, MtNetError* err);
        void onJoinMember(s32 index, MtNetSession::Member* member);
        void onEntryMember(s32 index, bool entry);
        void onLeaveMember(s32 index, MtNetSession::Member* member);
        void onHostMemberChange(s32 index, MtNetSession::Member* member);
        void onSearchResult(MtNetSession::SearchResultList* list);
        void onInviteComplete();
        void onDrop(MtNetError* err);
        void onMatch();
        void onTerminate();
        void onGameStart();
        void onGameEnd();
        void onFinalize();
    protected:
        nNetwork::BlockPool* mpPool;  // offset: 0x8
        nNetwork::SessionDatabase* mpDatabase;  // offset: 0x10
        nNetwork::Transport* mpTransport;  // offset: 0x18
        nNetwork::Connect* mpConnect;  // offset: 0x20
        nNetwork::Match* mpMatch;  // offset: 0x28
        nNetwork::SessionListener* mpListener[16];  // offset: 0x30
    private:
        u32 mAttr;  // offset: 0xb0
        u32 mUserIndex;  // offset: 0xb4
        u32 mService;  // offset: 0xb8
        MtNetUniqueId mUniqueId;  // offset: 0xc0
        nNetwork::SessionDriver mDriver;  // offset: 0x138
        nNetwork::Callback mCallback;  // offset: 0x808
        nNetwork::TagChecker mTagChecker;  // offset: 0x1ff0
        MtRandom mRandom;  // offset: 0x2060
        nNetwork::Receiver<nNetwork::Session> mReceiver;  // offset: 0x2070
        MtNetError mLastError;  // offset: 0x2098
    public:
        static const u32 ATTR_NONE = 0;
        static const u32 ATTR_FAIL_BEFORE_DROP = 1;
        static const u32 ATTR_CHECK_ID_ALL = 2;
        static const u32 ATTR_CHECK_TAG_ALL = 4;
        static const s32 SEND_LOCAL = 64;
        static const s32 SEND_ALL = 128;
        static const s32 SEND_GROUP_0 = 256;
        static const s32 SEND_GROUP_1 = 512;
        static const s32 SEND_GROUP_2 = 1024;
        static const s32 SEND_GROUP_3 = 2048;
        static const s32 SEND_GROUP_4 = 4096;
        static const s32 SEND_GROUP_5 = 8192;
        static const s32 SEND_GROUP_6 = 16384;
        static const s32 SEND_GROUP_7 = 32768;
        static const s32 SEND_X_MUTE = 65536;
        static const s32 SEND_X_REST = 131072;
        static const s32 SEND_X_SELF = 64;
        static const s32 SEND_OTHERS = 192;
        static const s32 SEND_OTHERS_GROUP_0 = 320;
        static const s32 SEND_OTHERS_GROUP_1 = 576;
        static const s32 SEND_OTHERS_GROUP_2 = 1088;
        static const s32 SEND_OTHERS_GROUP_3 = 2112;
        static const s32 SEND_OTHERS_GROUP_4 = 4160;
        static const s32 SEND_OTHERS_GROUP_5 = 8256;
        static const s32 SEND_OTHERS_GROUP_6 = 16448;
        static const s32 SEND_OTHERS_GROUP_7 = 32832;
        static const s32 SEND_MEMBER_MASK = 63;
        static const s32 SEND_MEMBER_SHIFT = 0;
        static const s32 SEND_GROUP_MASK = 65280;
        static const s32 SEND_GROUP_SHIFT = 8;
        static const u32 MAX_NUM_LISTENER = 16;
        static MyDTI DTI;
    };
}  // namespace nNetwork
