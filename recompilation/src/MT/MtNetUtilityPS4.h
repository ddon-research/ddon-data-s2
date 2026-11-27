#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtNetCom.h"
#include "MtNetObject.h"
#include "MtString.h"
#include "MtThread.h"
#include "../generated/shared/_rtc.h"
#include "../generated/shared/json2.h"
#include "../generated/shared/np_matching2.h"
#include "../generated/shared/np_npid.h"
#include "../generated/shared/np_webapi.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
struct SceNpId;
struct SceNpMatching2CreateContextParam;
struct SceNpOnlineId;
struct SceNpSessionId;
struct SceNpTitleId;
struct SceNpWebApiContentParameter;
struct SceRtcTick;
namespace sce { namespace Json { class InitParameter; } }
namespace sce { namespace Json { class Initializer; } }
namespace sce { namespace Json { class Value; } }

// Declarations
namespace MtNet { namespace Utility { namespace PS4 { class BlockList; } } }
namespace MtNet { namespace Utility { namespace PS4 { class Json; } } }
namespace MtNet { namespace Utility { namespace PS4 { class Match; } } }
namespace MtNet { namespace Utility { namespace PS4 { class MtNetString; } } }
namespace MtNet { namespace Utility { namespace PS4 { class MtNetThread; } } }
namespace MtNet { namespace Utility { namespace PS4 { class ReqCtx; } } }
namespace MtNet { namespace Utility { namespace PS4 { class WebApi; } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
namespace MtNet { namespace Utility { namespace PS4 { using ReqCtxPtr = MtNet::Utility::PS4::ReqCtx*; } } }
using __uint16_t = unsigned short;
using uint16_t = __uint16_t;
using SceNpMatching2ContextId = uint16_t;
using SceNpMatching2Event = uint16_t;
using SceNpMatching2EventCause = unsigned char;
using SceNpMatching2ServerId = uint16_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpServiceLabel = uint32_t;
using __int32_t = int;
using int32_t = __int32_t;
using SceUserServiceUserId = int32_t;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using int64_t = __int64_t;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class BlockList : public ::MtNetObject
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
                explicit BlockList();
                virtual ~BlockList() {}
                void clear();
                MtNet::Utility::PS4::BlockList& operator=(const MtNet::Utility::PS4::BlockList& src);
                s32 getNum() const;
                const SceNpId& getNpId(s32 i) const;
                void add(SceNpId& np_id);
            private:
                s32 mValidNum;  // offset: 0x24
                SceNpId mNpId[100];  // offset: 0x28
            public:
                static MyDTI DTI;
                static const s32 MAX_NUM_BLOCK = 100;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class Json : public ::MtNetObject, public sce::Json::MemAllocator
            {
                friend class MtNet::Utility::PS4::WebApi;
            public:
                class MyDTI;
                struct FriendList;
                struct BlockList;
                struct Presence;
                struct EntitlementList;
                struct EntitlementInfo;
                struct EntitlementUseResult;
            public:
                using EntitlementType = MtStringEx<32>;
                using EntitlementId = MtStringEx<64>;
            public:
                class MyDTI : public ::MtDTI
                {
                public:
                    MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                    virtual MtObject* newInstance() const;  // vtable slot 2
                };
            public:
                struct FriendList
                {
                public:
                    s32 total;  // offset: 0x0
                    s32 offset;  // offset: 0x4
                    s32 rsize;  // offset: 0x8
                    s32 num;  // offset: 0xc
                    SceNpId npIdTbl[500];  // offset: 0x10
                    static const s32 MaxNum = 500;
                };
            public:
                struct BlockList
                {
                public:
                    s32 total;  // offset: 0x0
                    s32 offset;  // offset: 0x4
                    s32 rsize;  // offset: 0x8
                    s32 num;  // offset: 0xc
                    SceNpId npIdTbl[500];  // offset: 0x10
                    static const s32 MaxNum = 500;
                };
            public:
                struct Presence
                {
                public:
                    SceNpId npId;  // offset: 0x0
                    u8 dataBuf[128];  // offset: 0x24
                    s32 dataSize;  // offset: 0xa4
                };
            public:
                struct EntitlementInfo
                {
                public:
                    MtNet::Utility::PS4::Json::EntitlementType type;  // offset: 0x0
                    bool isConsumable;  // offset: 0x24
                    MtNet::Utility::PS4::Json::EntitlementId id;  // offset: 0x28
                    SceRtcTick activeDate;  // offset: 0x70
                    SceRtcTick inactiveDate;  // offset: 0x78
                    u32 useCount;  // offset: 0x80
                    u32 useLimit;  // offset: 0x84
                };
            public:
                struct EntitlementUseResult
                {
                public:
                    u32 useLimit;  // offset: 0x0
                };
            public:
                struct EntitlementList
                {
                public:
                    s32 total;  // offset: 0x0
                    s32 offset;  // offset: 0x4
                    s32 rsize;  // offset: 0x8
                    s32 num;  // offset: 0xc
                    MtNet::Utility::PS4::Json::EntitlementInfo infoTbl[100];  // offset: 0x10
                    static const s32 MaxNum = 100;
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
                static void createInstance();
                static void deleteInstance();
                static MtNet::Utility::PS4::Json* instancePtr();
                explicit Json();
                virtual ~Json();
                s32 parseFriendList(FriendList& list, MT_CTSTR str_ptr);
                s32 parseBlockList(BlockList& list, MT_CTSTR str_ptr);
                s32 parsePresence(Presence& presence, MT_CTSTR str_ptr);
                s32 parseNpSessionId(SceNpSessionId& np_session_id, MT_CTSTR str_ptr);
                s32 parseEntitlementList(EntitlementList& list, MT_CTSTR str_ptr);
                s32 parseEntitlementInfo(EntitlementInfo& info, MT_CTSTR str_ptr);
                s32 parseEntitlementUseResult(EntitlementUseResult& use_result, MT_CTSTR str_ptr);
                s32 constructSession(MtStringEx<4096>& ret_str, int64_t join_max, MtNetCom::IInvitePS4::SessionParam* invite_param_ptr);
                s32 constructPlayedWith(MtNet::Utility::PS4::MtNetString& ret_str, SceNpOnlineId* self_id_ptr, SceNpTitleId* title_id_ptr, SceNpOnlineId* online_id_tbl, size_t online_id_num, MtStringEx<1024>* explain_str_ptr);
            private:
                virtual void* allocate(size_t size, void* arg_ptr);  // vtable slot 11
                virtual void deallocate(void* ptr, void* arg_ptr);  // vtable slot 12
                virtual void notifyError(int32_t err_no, size_t size, void* arg_ptr) {}  // vtable slot 13
                static const sce::Json::Value& nullAccessCallback(sce::Json::ValueType accesstype, const sce::Json::Value* parent_ptr, void* context_ptr);
                s32 commonInit(sce::Json::InitParameter& initparam, sce::Json::Initializer& initializer, sce::Json::Value& rootval, MT_CTSTR& str_ptr);
            private:
                sce::Json::Value mNull;  // offset: 0x30
            public:
                static MyDTI DTI;
            private:
                static MtNet::Utility::PS4::Json* mInstancePtr;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class Match : public ::MtNetObject
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
                explicit Match(SceUserServiceUserId user_id, SceNpMatching2CreateContextParam& context_param);
                virtual ~Match();
                SceNpMatching2ContextId getContextId() const;
                SceNpMatching2ServerId getServerId() const;
                s32 getContextError() const;
                s32 startContext(const MtNetObject& owner_obj);
                s32 termContext(const MtNetObject& owner_obj);
                void setContextEvent(SceNpMatching2ContextId context_id, SceNpMatching2Event event_id, SceNpMatching2EventCause event_cause, int error_code);
            private:
                Match();
            private:
                SceUserServiceUserId mSceUserId;  // offset: 0x24
                SceNpMatching2CreateContextParam mContextParam;  // offset: 0x28
                const MtNetObject* mContextOwnerPtr;  // offset: 0x50
                SceNpMatching2ContextId mContextId;  // offset: 0x58
                SceNpMatching2ServerId mServerId;  // offset: 0x5a
                bool mIsContextStarted;  // offset: 0x5c
                bool mIsContextStartOver;  // offset: 0x5d
                bool mIsContextStopped;  // offset: 0x5e
                s32 mContextError;  // offset: 0x60
                s32 mContextAsyncResult;  // offset: 0x64
                s32 mContextStartResult;  // offset: 0x68
                s32 mContextStartPhase;  // offset: 0x6c
                s32 mContextTermPhase;  // offset: 0x70
            public:
                static MyDTI DTI;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class MtNetString : public ::MtNetObject
            {
                friend class MtNet::Utility::PS4::WebApi;
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
                explicit MtNetString(size_t size);
                virtual ~MtNetString();
                size_t size();
                size_t length();
                void clear();
                MT_STR buf();
                const MtNet::Utility::PS4::MtNetString& operator=(MT_CTSTR s);
                MT_CTSTR cstr();
            private:
                MtNetString();
            private:
                size_t mBufSize;  // offset: 0x28
                MT_STR mBufPtr;  // offset: 0x30
            public:
                static MyDTI DTI;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class MtNetThread : public ::MtThread
            {
            public:
                class MyDTI;
                class ScopedLock;
            public:
                class MyDTI : public ::MtDTI
                {
                public:
                    MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                    virtual MtObject* newInstance() const;  // vtable slot 2
                };
            public:
                class ScopedLock
                {
                public:
                    ScopedLock(MtNet::Utility::PS4::MtNetThread* objPtr);
                    ~ScopedLock();
                private:
                    MtNet::Utility::PS4::MtNetThread* mObjPtr;  // offset: 0x0
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
                MtNetThread(u32 stack_size, void* context, MT_CTSTR name);
                virtual ~MtNetThread() {}
            public:
                static MyDTI DTI;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class ReqCtx : public ::MtNetObject
            {
                friend class MtNet::Utility::PS4::WebApi;
            public:
                enum ReqType
                {
                    ReqType_None = 0,
                    ReqType_WebApiInitialize = 1,
                    ReqType_WebApiGetFriendList = 2,
                    ReqType_WebApiGetBlockList = 3,
                    ReqType_WebApiSetPresenceGameStatus = 4,
                    ReqType_WebApiSetPresenceGameData = 5,
                    ReqType_WebApiGetPresenceGameData = 6,
                    ReqType_WebApiCreateWebSession = 7,
                    ReqType_WebApiJoinWebSession = 8,
                    ReqType_WebApiLeaveWebSession = 9,
                    ReqType_WebApiGetWebSessionRoot = 10,
                    ReqType_WebApiGetWebSessionData = 11,
                    ReqType_WebApiSetPlayedWith = 12,
                    ReqType_WebApiGetEntitlementByRange = 13,
                    ReqType_WebApiGetEntitlementById = 14,
                    ReqType_WebApiSetEntitlement = 15,
                    ReqType_Max = 16,
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
                explicit ReqCtx(const void* owner_ptr, ReqType req_type, size_t send_size, size_t recv_size);
                virtual ~ReqCtx();
                MtNet::Utility::PS4::MtNetString& getSendStr();
                MtNet::Utility::PS4::MtNetString& getRecvStr();
                size_t& getRecvSize();
                const void* getOwnerPtr();
                ReqType getReqType() const;
                void setArg(s32 index, void* ptr);
                void* getArg(s32 index);
                void setError(int error_no);
                bool isError() const;
                s32 getError() const;
                void setReady();
                bool isReady() const;
                void setComplete();
                bool isComplete() const;
                void setRequestId(s64 req_id);
                s64 getRequestId() const;
            private:
                ReqCtx();
            private:
                MtNet::Utility::PS4::MtNetString mSendStr;  // offset: 0x28
                MtNet::Utility::PS4::MtNetString mRecvStr;  // offset: 0x60
                size_t mRecvSize;  // offset: 0x98
                const void* mOwnerPtr;  // offset: 0xa0
                ReqType mReqType;  // offset: 0xa8
                void* mArgPtrTbl[8];  // offset: 0xb0
                s32 mErrorNo;  // offset: 0xf0
                bool mIsReady;  // offset: 0xf4
                bool mIsComplete;  // offset: 0xf5
                s64 mRequestId;  // offset: 0xf8
            public:
                static MyDTI DTI;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class WebApi : public MtNet::Utility::PS4::MtNetThread
            {
            public:
                class MyDTI;
                struct ReqDeny;
            public:
                class MyDTI : public ::MtDTI
                {
                public:
                    MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                    virtual MtObject* newInstance() const;  // vtable slot 2
                };
            public:
                struct ReqDeny
                {
                public:
                    u64 mTime;  // offset: 0x0
                    s32 mReason;  // offset: 0x8
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
                static void createInstance();
                static void deleteInstance();
                static MtNet::Utility::PS4::WebApi* instancePtr();
                explicit WebApi();
                virtual ~WebApi();
                MtNet::Utility::PS4::ReqCtxPtr reqInitialize(const void* owner_ptr, int32_t lib_ctx_id, SceNpServiceLabel service_label, bool disuse_friend, bool disuse_presence, bool disuse_match, bool disuse_entitlement);
                bool pollInitialize(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, int32_t& normal_filter_id, int32_t& service_handle_id, int32_t& service_filter_id);
                MtNet::Utility::PS4::ReqCtxPtr reqGetFriendList(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr, s32 offset);
                bool pollGetFriendList(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, MtNet::Utility::PS4::Json::FriendList& list);
                MtNet::Utility::PS4::ReqCtxPtr reqGetBlockList(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr, s32 offset);
                bool pollGetBlockList(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, MtNet::Utility::PS4::Json::BlockList& list);
                MtNet::Utility::PS4::ReqCtxPtr reqSetPresenceGameStatus(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr, MtStringEx<256>* status_str_ptr);
                bool pollSetPresenceGameStatus(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result);
                MtNet::Utility::PS4::ReqCtxPtr reqSetPresenceGameData(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr, void* data_ptr, s32 data_size);
                bool pollSetPresenceGameData(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result);
                MtNet::Utility::PS4::ReqCtxPtr reqGetPresenceGameData(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr);
                bool pollGetPresenceGameData(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, MtNet::Utility::PS4::Json::Presence& presence);
                MtNet::Utility::PS4::ReqCtxPtr reqCreateWebSession(const void* owner_ptr, int32_t usr_ctx_id, int64_t join_max, void* sdata_ptr, s32 sdata_size, MtNetCom::IInvitePS4::SessionParam& invite_param);
                bool pollCreateWebSession(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, SceNpSessionId& np_session_id);
                MtNet::Utility::PS4::ReqCtxPtr reqJoinWebSession(const void* owner_ptr, int32_t usr_ctx_id, SceNpSessionId* np_session_id);
                bool pollJoinWebSession(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result);
                MtNet::Utility::PS4::ReqCtxPtr reqLeaveWebSession(const void* owner_ptr, int32_t usr_ctx_id, SceNpSessionId* np_session_id, SceNpOnlineId* online_id_ptr);
                bool pollLeaveWebSession(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result);
                MtNet::Utility::PS4::ReqCtxPtr reqGetWebSessionRoot(const void* owner_ptr, int32_t usr_ctx_id, SceNpSessionId* np_session_id, MT_STR languages);
                bool pollGetWebSessionRoot(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result);
                MtNet::Utility::PS4::ReqCtxPtr reqGetWebSessionData(const void* owner_ptr, int32_t usr_ctx_id, SceNpSessionId* np_session_id);
                bool pollGetWebSessionData(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, void* buf_ptr, size_t buf_size, size_t& copy_size);
                MtNet::Utility::PS4::ReqCtxPtr reqSetPlayedWith(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* self_id_ptr, SceNpTitleId* title_id_ptr, SceNpOnlineId* online_id_tbl, size_t online_id_num, MtStringEx<1024>* explain_str_ptr);
                bool pollSetPlayedWith(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result);
                MtNet::Utility::PS4::ReqCtxPtr reqGetEntitlementByRange(const void* owner_ptr, int32_t usr_ctx_id, s32 offset, s32 max_count, SceNpServiceLabel service_label);
                bool pollGetEntitlementByRange(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, MtNet::Utility::PS4::Json::EntitlementList& list);
                MtNet::Utility::PS4::ReqCtxPtr reqGetEntitlementById(const void* owner_ptr, int32_t usr_ctx_id, MtNet::Utility::PS4::Json::EntitlementId* ent_id_ptr, SceNpServiceLabel service_label);
                bool pollGetEntitlementById(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, MtNet::Utility::PS4::Json::EntitlementInfo& info);
                MtNet::Utility::PS4::ReqCtxPtr reqSetEntitlement(const void* owner_ptr, int32_t usr_ctx_id, s32 count, MtNet::Utility::PS4::Json::EntitlementId* ent_id_ptr, SceNpServiceLabel service_label);
                bool pollSetEntitlement(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, MtNet::Utility::PS4::Json::EntitlementUseResult& use_result);
            private:
                MtNet::Utility::PS4::ReqCtxPtr reqNew(const void* owner_ptr, MtNet::Utility::PS4::ReqCtx::ReqType req_type, size_t send_size, size_t recv_size);
                void reqDelete(const MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void elapsedTimerInit();
                u64 elapsedTime();
                virtual void execute(void* param_ptr);  // vtable slot 6
                bool pollCommon(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result);
                void initialize(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void getFriendList(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void getBlockList(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void setPresenceGameStatus(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void setPresenceGameData(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void getPresenceGameData(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void createWebSession(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void joinWebSession(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void leaveWebSession(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void getWebSessionRoot(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void getWebSessionData(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void setPlayedWith(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void getEntitlementByRange(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void getEntitlementById(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void setEntitlement(MtNet::Utility::PS4::ReqCtxPtr req_ptr);
                void sendRequest(MtNet::Utility::PS4::ReqCtxPtr req_ptr, int32_t usr_ctx_id, MT_CTSTR api_group_ptr, MT_CTSTR req_path, SceNpWebApiHttpMethod req_method, const SceNpWebApiContentParameter* cont_param_ptr, const void* req_data_ptr, size_t req_data_size, void* res_buf_ptr, size_t res_buf_size, size_t& read_size);
                s32 readResponse(MtNet::Utility::PS4::ReqCtxPtr req_ptr, int64_t request_id, size_t& read_size, void* res_buf_ptr, size_t res_buf_size);
            private:
                MtTypedArray<MtNet::Utility::PS4::ReqCtx> mReqCtxPtrArray;  // offset: 0x70
                ReqDeny mReqDenyTbl[16];  // offset: 0x90
                u64 mLastTime;  // offset: 0x190
                bool mIsProcess;  // offset: 0x198
            public:
                static MyDTI DTI;
            private:
                static const s32 MAX_NUM_REQ_CTX = 256;
                static MtNet::Utility::PS4::WebApi* mInstancePtr;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet

inline void* MtNet::Utility::PS4::BlockList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* MtNet::Utility::PS4::Json::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* MtNet::Utility::PS4::Match::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* MtNet::Utility::PS4::MtNetString::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* MtNet::Utility::PS4::MtNetThread::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* MtNet::Utility::PS4::ReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* MtNet::Utility::PS4::WebApi::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "MtAllocator.h"
#include "MtMemoryAllocator.h"

inline void* MtNet::Utility::PS4::BlockList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::BlockList::DTI)->memAlloc(sz, align, ::MtNet::Utility::PS4::BlockList::DTI.::MtDTI::mID);
}

inline void MtNet::Utility::PS4::Match::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::Match::DTI)->memFree(p_addr);
}

inline void MtNet::Utility::PS4::MtNetString::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::MtNetString::DTI)->memFree(p_addr);
}

inline void MtNet::Utility::PS4::MtNetThread::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::MtNetThread::DTI)->memFree(p_addr);
}

inline void MtNet::Utility::PS4::ReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::ReqCtx::DTI)->memFree(p_addr);
}

inline void MtNet::Utility::PS4::WebApi::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::WebApi::DTI)->memFree(p_addr);
}
