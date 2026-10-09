#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtJsonReader.h"
#include "MtObject.h"
#include "MtString.h"
#include "cWebsocketClient.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtCriticalSection;
class MtDTI;
class MtString;
class cWebsocketClient;
namespace nCaplink { class ContextListener; }
namespace nCaplink { class HttpRequestContext; }

// Declarations
namespace nCaplink { class Object; }
namespace nCaplink { class WebsocketListener; }
namespace nCaplink { struct WebsocketNotifyChat; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nCaplink {
    class WebsocketListener
    {
    public:
        virtual ~WebsocketListener() {}
        virtual void onOpen();  // vtable slot 2
        virtual void onNotifyChat(nCaplink::WebsocketNotifyChat* notify);  // vtable slot 3
        virtual void onError(s32 error_code);  // vtable slot 4
        virtual void onClose();  // vtable slot 5
        void setErrorType(s32 error_type);
    protected:
        s32 mErrorType;  // offset: 0x8
    };
}  // namespace nCaplink

namespace nCaplink {
    struct WebsocketNotifyChat
    {
    public:
        s32 mChatId;  // offset: 0x0
        s8 mIdType;  // offset: 0x4
        char mId[33];  // offset: 0x5
        s32 mChatType;  // offset: 0x28
        char mUniqueId[33];  // offset: 0x2c
        char mNickname[257];  // offset: 0x4d
        char mIcon[257];  // offset: 0x14e
        char mMessage[2049];  // offset: 0x24f
        s32 mStampId;  // offset: 0xa50
        char mStamp[257];  // offset: 0xa54
        char mStampComment[1025];  // offset: 0xb55
        char mImage[257];  // offset: 0xf56
        char mImagePixelSize[17];  // offset: 0x1057
        char mPosition[65];  // offset: 0x1068
        s32 mPlatformId;  // offset: 0x10ac
        char mContentId[33];  // offset: 0x10b0
        char mCreatedAt[20];  // offset: 0x10d1
    };
}  // namespace nCaplink

namespace nCaplink {
    class Object : public ::MtObject
    {
    public:
        class MyDTI;
        class cWebsocketClientListener;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cWebsocketClientListener : public cWebsocketClient::cListener
        {
        public:
            class JsonParser;
        public:
            class JsonParser : public MtJsonReader::Handler
            {
            public:
                JsonParser();
                void init(nCaplink::Object::cWebsocketClientListener* parent);
                virtual void beginArray();  // vtable slot 2
                virtual void endArray();  // vtable slot 3
                virtual void endObject();  // vtable slot 5
                virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
                virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
                virtual void number(u64 value);  // vtable slot 8
                virtual void number(s64 value);  // vtable slot 9
                virtual void number(f64 value);  // vtable slot 10
                s32 getIndexNum() const;
            private:
                bool mbArray;  // offset: 0x9
                bool mbApi;  // offset: 0xa
                bool mbCount;  // offset: 0xb
                bool mbChatId;  // offset: 0xc
                bool mbIdType;  // offset: 0xd
                bool mbId;  // offset: 0xe
                bool mbChatType;  // offset: 0xf
                bool mbUniqueId;  // offset: 0x10
                bool mbNickname;  // offset: 0x11
                bool mbIcon;  // offset: 0x12
                bool mbMessage;  // offset: 0x13
                bool mbStampId;  // offset: 0x14
                bool mbStamp;  // offset: 0x15
                bool mbStampComment;  // offset: 0x16
                bool mbImage;  // offset: 0x17
                bool mbImagePixelSize;  // offset: 0x18
                bool mbPosition;  // offset: 0x19
                bool mbPlatformId;  // offset: 0x1a
                bool mbContentId;  // offset: 0x1b
                bool mbCreatedAt;  // offset: 0x1c
                bool mbCode;  // offset: 0x1d
                bool mbDetailMessage;  // offset: 0x1e
                bool mbDeviceRegister;  // offset: 0x1f
                bool mbHeartbeat;  // offset: 0x20
                bool mbNotifyChat;  // offset: 0x21
                nCaplink::Object::cWebsocketClientListener* mpParent;  // offset: 0x28
                nCaplink::WebsocketNotifyChat mNotify;  // offset: 0x30
                s32 mIndexNum;  // offset: 0x1118
            };
        public:
            cWebsocketClientListener();
            void init(cWebsocketClient* wsClient, nCaplink::Object* parent);
            void setReqName(MT_CTSTR req_name);
            void setCode(s32 code);
            void setDetailMessage(MT_CTSTR);
            virtual void onOpen(cWebsocketClient::Handshake handshake);  // vtable slot 6
            virtual void onMessage(MtString result);  // vtable slot 7
            virtual void onError(s32 code);  // vtable slot 8
            virtual void onClose();  // vtable slot 9
        private:
            nCaplink::Object* mpParent;  // offset: 0x8
            cWebsocketClient* mpWsClient;  // offset: 0x10
            MtString mReqName;  // offset: 0x18
            s32 mCode;  // offset: 0x20
            MtString mDetailMessage;  // offset: 0x28
            bool mbNotifyChat;  // offset: 0x30
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
        Object();
        virtual ~Object();
        void init(MT_CTSTR content_id, MT_CTSTR server_version, MT_CTSTR client_version, MT_CTSTR url_s, MT_CTSTR url, MT_CTSTR path);
        void final();
        void update();
        void wsInit();
        bool wsSetup(MT_CTSTR pUrl, nCaplink::WebsocketListener* listener);
        bool wsRegistDevice();
        cWebsocketClient::wsState wsGetState();
        void wsClose();
        void sendHeartbeat();
        void setHeatbeat(bool flag);
        bool getRetry();
        void setRetry(bool);
        bool reqLogin(nCaplink::ContextListener* listener, MT_CTSTR login_id, MT_CTSTR password, MT_CTSTR content_user_id, s32 platform_id);
        bool reqLoginCogKey(nCaplink::ContextListener* listener, MT_CTSTR content_user_id, s32 platform_id);
        bool reqReauth(nCaplink::ContextListener* listener, MT_CTSTR content_user_id);
        bool reqUserProfileGet(nCaplink::ContextListener* listener, MT_CTSTR unique_id);
        bool reqUserProfileModify(nCaplink::ContextListener* listener, MT_CTSTR nickname, s32 icon_id, MT_CTSTR comment, s32 timeline_skin_id, s32 profile_skin_id, s8 timeline_privacy, s8 profile_privacy, s8 captalk_privacy, s8 find_search);
        bool reqUserProfileContentTotalGet(nCaplink::ContextListener* listener, MT_CTSTR unique_id);
        bool reqUserProfileContentListGet(nCaplink::ContextListener* listener, MT_CTSTR unique_id, s32 offset, s32 count);
        bool reqUserProfileContentModify(nCaplink::ContextListener* listener, MT_CTSTR content_id, MT_CTSTR character_name, MT_CTSTR comment, s8 online_privacy, s8 visible);
        bool reqUserSearch(nCaplink::ContextListener* listener, s32 searchType, MT_CTSTR keyword, s32 offset, s32 count);
        bool reqUserIgnoreTotalGet(nCaplink::ContextListener* listener);
        bool reqUserIgnoreListGet(nCaplink::ContextListener* listener, s32 offset, s32 count);
        bool reqUserIgnoreRemove(nCaplink::ContextListener* listener, MT_CTSTR unique_id);
        bool reqFriendEntrySend(nCaplink::ContextListener* listener, MT_CTSTR uniqueId, MT_CTSTR message, s32 cause);
        bool reqFriendEntryCancel(nCaplink::ContextListener* listener, MT_CTSTR uniqueId);
        bool reqFriendEntryRecvListGet(nCaplink::ContextListener* listener, MT_CTSTR datetime, s32 offset, s32 count);
        bool reqFriendEntrySendListGet(nCaplink::ContextListener* listener, s32 offset, s32 count);
        bool reqFriendEntryReply(nCaplink::ContextListener* listener, MT_CTSTR uniqueId, s32 reply);
        bool reqFriendListGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime, s32 offset, s32 count);
        bool reqFriendAttribute(nCaplink::ContextListener* listener, MT_CTSTR unique_id, s8 attribute);
        bool reqFriendTagContentTotalGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime);
        bool reqFriendTagContentListGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime, s32 offset, s32 count);
        bool reqFriendTagFreeTotalGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime);
        bool reqFriendTagFreeListGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime, s32 offset, s32 count);
        bool reqFriendTagFree(nCaplink::ContextListener* listener, MT_CTSTR unique_id, MtArray free_tag_alive_info_list);
        bool reqFriendRelease(nCaplink::ContextListener* listener, MT_CTSTR unique_id);
        bool reqFriendModify(nCaplink::ContextListener* listener, MT_CTSTR unique_id, MT_CTSTR labelname, MT_CTSTR memo);
        bool reqTagTotalGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime);
        bool reqTagListGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime);
        bool reqTagModify(nCaplink::ContextListener* listener, MtArray tag_info_list);
        bool reqTagVisibleModify(nCaplink::ContextListener* listener, s32 tag_id, s8 visible);
        bool reqTagVisibleListGet(nCaplink::ContextListener* listener);
        bool reqContentTotalGet(nCaplink::ContextListener* listener);
        bool reqContentListGet(nCaplink::ContextListener* listener, s32 offset, s32 count);
        bool reqContentInviteAvailableListGet(nCaplink::ContextListener* listener, s32 offset, s32 count);
        bool reqContentInvite(nCaplink::ContextListener* listener, MT_CTSTR unique_id, MT_CTSTR content_id, MT_CTSTR message);
        bool reqContentInviteTotalGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime);
        bool reqContentInviteListGet(nCaplink::ContextListener* listener, MT_CTSTR from_datetime, s32 offset, s32 count);
        bool reqContentInviteRemove(nCaplink::ContextListener* listener, MT_CTSTR unique_id, MT_CTSTR content_id);
        bool reqContentAchievementGet(nCaplink::ContextListener* listener, MT_CTSTR content_id);
        bool reqContentAchievementListGet(nCaplink::ContextListener* listener, MT_CTSTR content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count);
        bool reqContentAchievementRelationGet(nCaplink::ContextListener* listener, MT_CTSTR filtering_content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count);
        bool reqChatListGet(nCaplink::ContextListener* listener, s32 id_type, MT_CTSTR id, s32 offset_id, s32 count);
        bool reqChatRead(nCaplink::ContextListener* listener, s32 chat_type, MT_CTSTR id, s32 chat_id);
        bool reqChatLastId(nCaplink::ContextListener* listener, s8 id_type, MT_CTSTR id);
        bool reqChatSend(nCaplink::ContextListener* listener, s32 chat_type, MT_CTSTR id, MT_CTSTR message, s32 stamp_id, MT_CTSTR image, MT_CTSTR position);
        bool reqChatGroupCreate(nCaplink::ContextListener* listener, MT_CTSTR group_name, s32 group_skin_id, MT_CTSTR group_message, const MtArray* user_info_list);
        bool reqChatGroupResign(nCaplink::ContextListener* listener, MT_CTSTR group_id);
        bool reqChatGroupRemove(nCaplink::ContextListener* listener, s32 chat_type, MT_CTSTR group_id);
        bool reqChatGroupMemberAdd(nCaplink::ContextListener* listener, MT_CTSTR group_id, MtArray* user_info_list);
        bool reqChatGroupMemberListGet(nCaplink::ContextListener* listener, MT_CTSTR group_id, s32 offset, s32 count);
        bool reqChatGroupMemberReject(nCaplink::ContextListener* listener, MT_CTSTR group_id, MT_CTSTR unique_id);
        bool reqChatGroupMemberLeave(nCaplink::ContextListener* listener, MT_CTSTR group_id);
        bool reqChatGroupListGet(nCaplink::ContextListener* listener, MT_CTSTR datetime, s32 offset, s32 count);
        bool reqChatGroupModify(nCaplink::ContextListener* listener, MT_CTSTR group_id, MT_CTSTR group_name, s32 group_skin_id);
        bool reqResourcePresetTotalGet(nCaplink::ContextListener* listener, s8 resource_type);
        bool reqResourcePresetListGet(nCaplink::ContextListener* listener, s8 resource_type, s32 offset, s32 count);
        bool reqResourceUserUpload(nCaplink::ContextListener* listener, s8 resource_type, MT_CTSTR data);
        bool reqResourceUserIconUpload(nCaplink::ContextListener* listener, MT_CTSTR data, MT_CTSTR data_s);
        bool reqNotify(nCaplink::ContextListener* listener, MT_CTSTR friend_from_datetime, MT_CTSTR friend_tag_content_from_datetime, MT_CTSTR friend_tag_free_from_datetime, MT_CTSTR friend_request_receive_from_datetime, MT_CTSTR tag_from_datetime, MT_CTSTR content_invite_from_datetime, MT_CTSTR stamp_from_datetime, MT_CTSTR content_from_datetime, MT_CTSTR resource_preset_from_datetime, MT_CTSTR profile_from_datetime);
        bool reqNotifyAppListGet(nCaplink::ContextListener* listener, s32 offset, s32 count);
        bool reqNotifyAppRead(nCaplink::ContextListener* listener, s32 notify_id);
        bool reqNotifyDeviceSetting(nCaplink::ContextListener* listener);
        bool reqNotifyDeviceSettingModify(nCaplink::ContextListener* listener, s8 all, s8 profile, s8 fri, s8 timeline, s8 chat, s8 game);
        bool reqNotifyTimeGet(nCaplink::ContextListener* listener);
        bool reqNotifyTimeModify(nCaplink::ContextListener* listener, s8 morning, s8 afternoon, s8 midnight, s8 evening);
        bool reqReport(nCaplink::ContextListener* listener, MT_CTSTR unique_id, s8 place, MT_CTSTR detail);
        bool reqWebsocketServerListGet(nCaplink::ContextListener* listener);
        static s32 encryptString(MtString& outStr, MtString dataStr, MtString commonKeyStr);
        static s32 decryptString(MtString& outStr, MtString dataStr, MtString commonKeyStr);
        static MT_CTSTR getUrls();
        static MT_CTSTR getUrl();
        static MT_CTSTR getPath();
        static s32 getPlatformId();
        static MT_CTSTR getContentId();
        static MT_CTSTR getServerVersion();
        static MT_CTSTR getClientVersion();
        static MT_CTSTR getDeviceId();
        static void setPlatformId(s32 platform_id);
        static void setContentId(MT_CTSTR);
        static void setServerVersion(MT_CTSTR);
        static void setClientVersion(MT_CTSTR);
        static void setBaseURLs(MT_CTSTR);
        static void setBaseURL(MT_CTSTR);
        static void setBasePath(MT_CTSTR);
        static MtString getTempKey();
        static void setTempKey(MT_CTSTR NewValue);
        static u32 getTempKeyLength();
        static u32 getTempKeyCapacity();
        static void initializeTempKey();
        static void releaseTempKey();
        static MtString getCommonKey();
        static void setCommonKey(MT_CTSTR NewValue);
        static u32 getCommonKeyLength();
        static u32 getCommonKeyCapacity();
        static void initializeCommonKey();
        static void releaseCommonKey();
        static MtString getAccessKey();
        static void setAccessKey(MT_CTSTR NewValue);
        static u32 getAccessKeyLength();
        static u32 getAccessKeyCapacity();
        static void initializeAccessKey();
        static void releaseAccessKey();
        static MtString getCogKey();
        static void setCogKey(MT_CTSTR NewValue);
        static u32 getCogKeyLength();
        static u32 getCogKeyCapacity();
        static void initializeCogKey();
        static void releaseCogKey();
    private:
        bool registeCtx(nCaplink::HttpRequestContext* ctx, nCaplink::ContextListener* listener);
        void generateDeviceId();
        void setupRetry();
    private:
        bool mHeartbeat;  // offset: 0x8
        bool mRetry;  // offset: 0x9
        u8 mRetryTime;  // offset: 0xa
        f32 mElapsedTime;  // offset: 0xc
        MtString mUrl;  // offset: 0x10
        cWebsocketClientListener mWscListener;  // offset: 0x18
        cWebsocketClient* mpWsClient;  // offset: 0x50
        nCaplink::WebsocketListener* mpWebsocketListener;  // offset: 0x58
    public:
        static MyDTI DTI;
    private:
        static nCaplink::HttpRequestContext* sReqCtxList[16];
        static s32 sPlatformId;
        static MtString sContentId;
        static MtString sServerVersion;
        static MtString sClientVersion;
        static MtString sCaplinkUrls;
        static MtString sCaplinkUrl;
        static MtString sCaplinkPath;
        static MtString sDeviceId;
        static MtString sTempKey;
        static MtString sCommonKey;
        static MtString sAccessKey;
        static MtString sCogKey;
        static MtCriticalSection mCs;
    };
}  // namespace nCaplink

// Inline, no code of its own: checked where it is inlined.
inline bool nCaplink::Object::getRetry() {
    return this->mRetry;
}
