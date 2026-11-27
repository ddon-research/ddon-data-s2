#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "../MT/MtString.h"
#include "cHttpClient.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMemoryStream;
class MtObject;
class MtString;
class cHttpClient;
class cWebsocketClient;
namespace nCaplink { class ChatGroupCreateReqCtx; }
namespace nCaplink { class ChatGroupListGetReqCtx; }
namespace nCaplink { class ChatGroupMemberAddReqCtx; }
namespace nCaplink { class ChatGroupMemberLeaveReqCtx; }
namespace nCaplink { class ChatGroupMemberListGetReqCtx; }
namespace nCaplink { class ChatGroupMemberRejectReqCtx; }
namespace nCaplink { class ChatGroupModifyReqCtx; }
namespace nCaplink { class ChatGroupRemoveReqCtx; }
namespace nCaplink { class ChatGroupResignReqCtx; }
namespace nCaplink { class ChatLastIdReqCtx; }
namespace nCaplink { class ChatListGetReqCtx; }
namespace nCaplink { class ChatReadReqCtx; }
namespace nCaplink { class ChatSendReqCtx; }
namespace nCaplink { class ContentAchievementGetReqCtx; }
namespace nCaplink { class ContentAchievementListGetReqCtx; }
namespace nCaplink { class ContentAchievementRelationGetReqCtx; }
namespace nCaplink { class ContentInviteAvailableListGetReqCtx; }
namespace nCaplink { class ContentInviteListGetReqCtx; }
namespace nCaplink { class ContentInviteRemoveReqCtx; }
namespace nCaplink { class ContentInviteReqCtx; }
namespace nCaplink { class ContentInviteTotalGetReqCtx; }
namespace nCaplink { class ContentListGetReqCtx; }
namespace nCaplink { class FriendAttributeReqCtx; }
namespace nCaplink { class FriendEntryCancelReqCtx; }
namespace nCaplink { class FriendEntryRecvListGetReqCtx; }
namespace nCaplink { class FriendEntryReplyReqCtx; }
namespace nCaplink { class FriendEntrySendListGetReqCtx; }
namespace nCaplink { class FriendEntrySendReqCtx; }
namespace nCaplink { class FriendListGetReqCtx; }
namespace nCaplink { class FriendReleaseReqCtx; }
namespace nCaplink { class FriendTagContentListGetReqCtx; }
namespace nCaplink { class FriendTagFreeListGetReqCtx; }
namespace nCaplink { class FriendTagFreeReqCtx; }
namespace nCaplink { class LoginCogKeyReqCtx; }
namespace nCaplink { class NotifyAppListGetReqCtx; }
namespace nCaplink { class NotifyAppReadReqCtx; }
namespace nCaplink { class NotifyDeviceSettingModifyReqCtx; }
namespace nCaplink { class NotifyDeviceSettingReqCtx; }
namespace nCaplink { class NotifyTimeGetReqCtx; }
namespace nCaplink { class NotifyTimeModifyReqCtx; }
namespace nCaplink { class ReportReqCtx; }
namespace nCaplink { class ResourcePresetListGetReqCtx; }
namespace nCaplink { class TagListGetReqCtx; }
namespace nCaplink { class TagModifyReqCtx; }
namespace nCaplink { class UserIgnoreListGetReqCtx; }
namespace nCaplink { class UserIgnoreRemoveReqCtx; }
namespace nCaplink { class UserProfileContentListGetReqCtx; }
namespace nCaplink { class UserProfileContentModifyReqCtx; }
namespace nCaplink { class UserProfileGetReqCtx; }
namespace nCaplink { class UserProfileModifyReqCtx; }
namespace nCaplink { class UserSearchReqCtx; }
namespace nCaplink { class WebsocketServerListGetReqCtx; }
class sCaplinkManager;

// Declarations
namespace nCaplink { class Context; }
namespace nCaplink { class ContextListener; }
namespace nCaplink { class HttpRequestContext; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nCaplink {
    class Context : public ::MtObject
    {
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
        Context();
        bool IsInProgress();
    protected:
        virtual void start(nCaplink::ContextListener* pListener, cWebsocketClient* pWsc);  // vtable slot 6
        virtual void end();  // vtable slot 7
        virtual void update() {}  // vtable slot 8
        virtual void request() {}  // vtable slot 9
    protected:
        nCaplink::ContextListener* mpListener;  // offset: 0x8
        cWebsocketClient* mpWsc;  // offset: 0x10
        s32 mPhase;  // offset: 0x18
        s32 mResultCode;  // offset: 0x1c
        bool mIsInProgress;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class ContextListener : public ::MtObject
    {
        friend class ::sCaplinkManager;
    public:
        enum
        {
            STATUS_NONE = 0,
            STATUS_POOL = 1,
            STATUS_FINISH = 2,
            STATUS_ERROR = 3,
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
        ContextListener();
        virtual ~ContextListener();
        virtual void init();  // vtable slot 6
        s32 getStatus() const;
        s32 getErrorType() const;
        s32 getErrorCode() const;
        MT_CTSTR getDetailMessage() const;
        void setStatus(s32 status);
        void setError(s32 error_type, s32 error_code, MT_CTSTR detail_message);
    protected:
        s32 mStatus;  // offset: 0x8
        s32 mErrorType;  // offset: 0xc
        s32 mErrorCode;  // offset: 0x10
        MtString mDetailMessage;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class HttpRequestContext : public nCaplink::Context
    {
        friend class nCaplink::ChatGroupCreateReqCtx;
        friend class nCaplink::ChatGroupListGetReqCtx;
        friend class nCaplink::ChatGroupMemberAddReqCtx;
        friend class nCaplink::ChatGroupMemberLeaveReqCtx;
        friend class nCaplink::ChatGroupMemberListGetReqCtx;
        friend class nCaplink::ChatGroupMemberRejectReqCtx;
        friend class nCaplink::ChatGroupModifyReqCtx;
        friend class nCaplink::ChatGroupRemoveReqCtx;
        friend class nCaplink::ChatGroupResignReqCtx;
        friend class nCaplink::ChatLastIdReqCtx;
        friend class nCaplink::ChatListGetReqCtx;
        friend class nCaplink::ChatReadReqCtx;
        friend class nCaplink::ChatSendReqCtx;
        friend class nCaplink::ContentAchievementGetReqCtx;
        friend class nCaplink::ContentAchievementListGetReqCtx;
        friend class nCaplink::ContentAchievementRelationGetReqCtx;
        friend class nCaplink::ContentInviteAvailableListGetReqCtx;
        friend class nCaplink::ContentInviteListGetReqCtx;
        friend class nCaplink::ContentInviteRemoveReqCtx;
        friend class nCaplink::ContentInviteReqCtx;
        friend class nCaplink::ContentInviteTotalGetReqCtx;
        friend class nCaplink::ContentListGetReqCtx;
        friend class nCaplink::FriendAttributeReqCtx;
        friend class nCaplink::FriendEntryCancelReqCtx;
        friend class nCaplink::FriendEntryRecvListGetReqCtx;
        friend class nCaplink::FriendEntryReplyReqCtx;
        friend class nCaplink::FriendEntrySendListGetReqCtx;
        friend class nCaplink::FriendEntrySendReqCtx;
        friend class nCaplink::FriendListGetReqCtx;
        friend class nCaplink::FriendReleaseReqCtx;
        friend class nCaplink::FriendTagContentListGetReqCtx;
        friend class nCaplink::FriendTagFreeListGetReqCtx;
        friend class nCaplink::FriendTagFreeReqCtx;
        friend class nCaplink::LoginCogKeyReqCtx;
        friend class nCaplink::NotifyAppListGetReqCtx;
        friend class nCaplink::NotifyAppReadReqCtx;
        friend class nCaplink::NotifyDeviceSettingModifyReqCtx;
        friend class nCaplink::NotifyDeviceSettingReqCtx;
        friend class nCaplink::NotifyTimeGetReqCtx;
        friend class nCaplink::NotifyTimeModifyReqCtx;
        friend class nCaplink::ReportReqCtx;
        friend class nCaplink::ResourcePresetListGetReqCtx;
        friend class nCaplink::TagListGetReqCtx;
        friend class nCaplink::TagModifyReqCtx;
        friend class nCaplink::UserIgnoreListGetReqCtx;
        friend class nCaplink::UserIgnoreRemoveReqCtx;
        friend class nCaplink::UserProfileContentListGetReqCtx;
        friend class nCaplink::UserProfileContentModifyReqCtx;
        friend class nCaplink::UserProfileGetReqCtx;
        friend class nCaplink::UserProfileModifyReqCtx;
        friend class nCaplink::UserSearchReqCtx;
        friend class nCaplink::WebsocketServerListGetReqCtx;
    public:
        class MyDTI;
        class HttpClientListener;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class HttpClientListener : public cHttpClient::Listener
        {
            friend class nCaplink::HttpRequestContext;
        public:
            enum
            {
                STATUS_NONE = 0,
                STATUS_START = 1,
                STATUS_FIN = 2,
                STATUS_ERROR = 3,
                STATUS_MAINTENANCE = 4,
            };
        public:
            HttpClientListener();
            void init();
            void end();
            void reset();
            virtual void onReceiveHeader(const cHttpClient::ResponseHeader* pHeader);  // vtable slot 2
            virtual void onReceiveData(void* pData, s32 cData);  // vtable slot 3
            virtual void onErrorEncounterd(s32 error);  // vtable slot 4
            s32 getStatus() const;
            MT_CTSTR getRecieveStr();
            u32 getRecieveSize();
            s32 getError() const;
        private:
            s32 mStatus;  // offset: 0x8
            s32 mCode;  // offset: 0xc
            s32 mError;  // offset: 0x10
            MtMemoryStream* mpStream;  // offset: 0x18
            s32 mSeekPt;  // offset: 0x20
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
        HttpRequestContext();
        HttpRequestContext(s32 type);
        virtual ~HttpRequestContext();
        virtual void start(nCaplink::ContextListener* pListener, cWebsocketClient* pWsc);  // vtable slot 6
        virtual void end();  // vtable slot 7
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setCode(s32 code);
        void setDetailMessage(MT_CTSTR message);
    protected:
        void initHttpClient();
        void finalHttpClient();
        MtString makeRequestBody(MtString path, MtString data);
        MtString makeRequestApi(MtString path, MtString data);
    protected:
        cHttpClient* mpHttpClient;  // offset: 0x28
        HttpClientListener mHttpClientListener;  // offset: 0x30
        s32 mCode;  // offset: 0x58
        s32 mType;  // offset: 0x5c
        MtString mDetailMessage;  // offset: 0x60
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::Context::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::Context::Context() {
    this->mpListener = nullptr;
}

inline void* nCaplink::ContextListener::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline s32 nCaplink::ContextListener::getStatus() const {
    return this->mStatus;
}

inline s32 nCaplink::ContextListener::getErrorType() const {
    return this->mErrorType;
}

inline void* nCaplink::HttpRequestContext::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void* nCaplink::Context::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::Context::DTI)->memAlloc(sz, align, ::nCaplink::Context::DTI.::MtDTI::mID);
}

inline void nCaplink::Context::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::Context::DTI)->memFree(p_addr);
}

inline void* nCaplink::ContextListener::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nCaplink::ContextListener::DTI)->memAlloc(sz, align, ::nCaplink::ContextListener::DTI.::MtDTI::mID);
}
