#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtJsonReader.h"
#include "MtString.h"
#include "MtTime.h"
#include "cCaplink.h"
#include "cCaplinkChatGroupCreate.h"
#include "cCaplinkChatGroupListGet.h"
#include "cCaplinkChatGroupMemberAdd.h"
#include "cCaplinkChatGroupMemberLeave.h"
#include "cCaplinkChatGroupMemberListGet.h"
#include "cCaplinkChatGroupMemberReject.h"
#include "cCaplinkChatGroupModify.h"
#include "cCaplinkChatGroupRemove.h"
#include "cCaplinkChatGroupResign.h"
#include "cCaplinkChatLastId.h"
#include "cCaplinkChatListGet.h"
#include "cCaplinkChatRead.h"
#include "cCaplinkChatSend.h"
#include "cCaplinkContentAchievementGet.h"
#include "cCaplinkContentAchievementListGet.h"
#include "cCaplinkContentAchievementRelationGet.h"
#include "cCaplinkContentInvite.h"
#include "cCaplinkContentInviteAvailableListGet.h"
#include "cCaplinkContentInviteListGet.h"
#include "cCaplinkContentInviteRemove.h"
#include "cCaplinkContentInviteTotalGet.h"
#include "cCaplinkContentListGet.h"
#include "cCaplinkContentTotalGet.h"
#include "cCaplinkDataDef.h"
#include "cCaplinkFriendAttribute.h"
#include "cCaplinkFriendEntryCancel.h"
#include "cCaplinkFriendEntryRecvListGet.h"
#include "cCaplinkFriendEntryReply.h"
#include "cCaplinkFriendEntrySend.h"
#include "cCaplinkFriendEntrySendListGet.h"
#include "cCaplinkFriendListGet.h"
#include "cCaplinkFriendModify.h"
#include "cCaplinkFriendRelease.h"
#include "cCaplinkFriendTagContentListGet.h"
#include "cCaplinkFriendTagContentTotalGet.h"
#include "cCaplinkFriendTagFree.h"
#include "cCaplinkFriendTagFreeListGet.h"
#include "cCaplinkFriendTagFreeTotalGet.h"
#include "cCaplinkLogin.h"
#include "cCaplinkLoginCogKey.h"
#include "cCaplinkNotify.h"
#include "cCaplinkNotifyAppListGet.h"
#include "cCaplinkNotifyAppRead.h"
#include "cCaplinkNotifyDeviceSetting.h"
#include "cCaplinkNotifyDeviceSettingModify.h"
#include "cCaplinkNotifyTimeGet.h"
#include "cCaplinkNotifyTimeModify.h"
#include "cCaplinkObject.h"
#include "cCaplinkReauth.h"
#include "cCaplinkReport.h"
#include "cCaplinkResourcePresetListGet.h"
#include "cCaplinkResourcePresetTotalGet.h"
#include "cCaplinkTagListGet.h"
#include "cCaplinkTagModify.h"
#include "cCaplinkTagTotalGet.h"
#include "cCaplinkTagVisibleListGet.h"
#include "cCaplinkTagVisibleModify.h"
#include "cCaplinkUserIgnoreListGet.h"
#include "cCaplinkUserIgnoreRemove.h"
#include "cCaplinkUserIgnoreTotalGet.h"
#include "cCaplinkUserProfileContentListGet.h"
#include "cCaplinkUserProfileContentModify.h"
#include "cCaplinkUserProfileGet.h"
#include "cCaplinkUserProfileModify.h"
#include "cCaplinkUserSearch.h"
#include "cCaplinkWebsocketServerListGet.h"
#include "cSystem.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
struct MtNetError;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtTime;
class MtUI;
namespace nCaplink { class ChatGroupCreateAns; }
namespace nCaplink { class ChatGroupListGetAns; }
namespace nCaplink { class ChatGroupMemberAddAns; }
namespace nCaplink { class ChatGroupMemberLeaveAns; }
namespace nCaplink { class ChatGroupMemberListGetAns; }
namespace nCaplink { class ChatGroupMemberRejectAns; }
namespace nCaplink { class ChatGroupModifyAns; }
namespace nCaplink { class ChatGroupRemoveAns; }
namespace nCaplink { class ChatGroupResignAns; }
namespace nCaplink { class ChatLastIdAns; }
namespace nCaplink { class ChatListGetAns; }
namespace nCaplink { class ChatReadAns; }
namespace nCaplink { class ChatSendAns; }
namespace nCaplink { class ContentAchievementGetAns; }
namespace nCaplink { class ContentAchievementListGetAns; }
namespace nCaplink { class ContentAchievementRelationGetAns; }
namespace nCaplink { class ContentInviteAns; }
namespace nCaplink { class ContentInviteAvailableListGetAns; }
namespace nCaplink { class ContentInviteListGetAns; }
namespace nCaplink { class ContentInviteRemoveAns; }
namespace nCaplink { class ContentInviteTotalGetAns; }
namespace nCaplink { class ContentListGetAns; }
namespace nCaplink { class ContentTotalGetAns; }
namespace nCaplink { class ContextListener; }
namespace nCaplink { class FriendAttributeAns; }
namespace nCaplink { class FriendEntryCancelAns; }
namespace nCaplink { class FriendEntryRecvListGetAns; }
namespace nCaplink { class FriendEntryReplyAns; }
namespace nCaplink { class FriendEntrySendAns; }
namespace nCaplink { class FriendEntrySendListGetAns; }
namespace nCaplink { class FriendListGetAns; }
namespace nCaplink { class FriendModifyAns; }
namespace nCaplink { class FriendReleaseAns; }
namespace nCaplink { class FriendTagContentListGetAns; }
namespace nCaplink { class FriendTagContentTotalGetAns; }
namespace nCaplink { class FriendTagFreeAns; }
namespace nCaplink { class FriendTagFreeListGetAns; }
namespace nCaplink { class FriendTagFreeTotalGetAns; }
namespace nCaplink { class LoginAns; }
namespace nCaplink { class LoginCogKeyAns; }
namespace nCaplink { class NotifyAns; }
namespace nCaplink { class NotifyAppListGetAns; }
namespace nCaplink { class NotifyAppReadAns; }
namespace nCaplink { class NotifyDeviceSettingAns; }
namespace nCaplink { class NotifyDeviceSettingModifyAns; }
namespace nCaplink { class NotifyTimeGetAns; }
namespace nCaplink { class NotifyTimeModifyAns; }
namespace nCaplink { class Object; }
namespace nCaplink { class ReauthAns; }
namespace nCaplink { class ReportAns; }
namespace nCaplink { class ResourcePresetListGetAns; }
namespace nCaplink { class ResourcePresetTotalGetAns; }
namespace nCaplink { class TagListGetAns; }
namespace nCaplink { class TagModifyAns; }
namespace nCaplink { class TagTotalGetAns; }
namespace nCaplink { class TagVisibleListGetAns; }
namespace nCaplink { class TagVisibleModifyAns; }
namespace nCaplink { class UserIgnoreListGetAns; }
namespace nCaplink { class UserIgnoreRemoveAns; }
namespace nCaplink { class UserIgnoreTotalGetAns; }
namespace nCaplink { class UserProfileContentListGetAns; }
namespace nCaplink { class UserProfileContentModifyAns; }
namespace nCaplink { class UserProfileGetAns; }
namespace nCaplink { class UserProfileModifyAns; }
namespace nCaplink { class UserSearchAns; }
namespace nCaplink { struct WebsocketNotifyChat; }
namespace nCaplink { class WebsocketServerListGetAns; }
namespace nCaplink { class cChatUserInfo; }
namespace nCaplink { class cUserBaseInfo; }
namespace nCaplink { class cWebsocketServerInfo; }

// Declarations
class sCaplinkManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class sCaplinkManager : public cSystem
{
public:
    enum
    {
        RNO_MAIN_NONE = 0,
        RNO_MAIN_INIT = 1,
        RNO_MAIN_WEBSOCKET = 2,
        RNO_MAIN_REQ_GET_IMAGE = 3,
        RNO_MAIN_REQ_GET_FIRST = 4,
        RNO_MAIN_GET_PROF = 5,
        RNO_MAIN_GET_CONTENT = 6,
        RNO_MAIN_GET_FREE_TAG = 7,
        RNO_MAIN_GET_FRIEND = 8,
        RNO_MAIN_GET_FRIEND_CONTENT = 9,
        RNO_MAIN_GET_FRIEND_FREE_TAG = 10,
        RNO_MAIN_GET_FRIEND_RECEIVE = 11,
        RNO_MAIN_GET_FRIEND_INVITE_ENABLE = 12,
        RNO_MAIN_GET_CHAT_GROUP = 13,
        RNO_MAIN_GET_NOTIFY_DETAIL = 14,
        RNO_MAIN_GET_CHAT_LIST = 15,
        RNO_MAIN_WAIT = 16,
        RNO_MAIN_NOTIFY_WAIT = 17,
    };
    enum
    {
        REQ_FLAG_GET_PROF = 0,
        REQ_FLAG_GET_CONTENT = 1,
        REQ_FLAG_GET_FREE_TAG = 2,
        REQ_FLAG_GET_FRIEND = 3,
        REQ_FLAG_GET_FRIEND_CONTENT = 4,
        REQ_FLAG_GET_FRIEND_FREE_TAG = 5,
        REQ_FLAG_GET_FRIEND_RECV = 6,
        REQ_FLAG_GET_FRIEND_INVITE_ENABLE = 7,
        REQ_FLAG_GET_CHAT_GROUP = 8,
        REQ_FLAG_GET_NOTIFY_DETAIL = 9,
        REQ_FLAG_GET_CHAT_LIST = 10,
        REQ_FLAG_NUM = 11,
    };
public:
    class MyDTI;
    class cCaplinkListenerQueue;
    class cProfile;
    class cIconUrl;
    class cProfIconLoader;
    class cTagData;
    class cFriendData;
    class cDate;
    class cFriendRecvData;
    class cContentData;
    class cGroupChatData;
    class cChatList;
    class cChatInfo;
    class cChatJoin;
    class cCaplinkWebsocketListener;
    class cChatMessageParser;
public:
    using CALLBACK_FUNC = void(sCaplinkManager::*)();
    using ContentBit = nDDOUtility::cBitSet<128>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCaplinkListenerQueue : public cCaplinkObject
    {
    public:
        enum
        {
            RNO_MAIN = 0,
            RNO_ERROR = 1,
            RNO_END = 2,
        };
    public:
        class MyDTI;
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
        cCaplinkListenerQueue(nCaplink::ContextListener* pListener, sCaplinkManager::CALLBACK_FUNC pCallback, bool isNoDispError);
        virtual ~cCaplinkListenerQueue();
        void update();
        void reqErrorDialog(MtNetError* pErrInfo);
        void setErrorCode(MtString& str, s32 code);
        void setErrorMsg();
        bool isFatalError();
        bool isEnd();
        bool isDispError();
    private:
        nCaplink::ContextListener* mpListener;  // offset: 0x8
        sCaplinkManager::CALLBACK_FUNC mpCallback;  // offset: 0x10
        u32 mErrorDialogHandle;  // offset: 0x20
        u8 mRno;  // offset: 0x24
        bool mIsNoDispError;  // offset: 0x25
    public:
        static MyDTI DTI;
    };
public:
    class cProfile : public cCaplinkObject
    {
    public:
        class MyDTI;
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
        cProfile();
        void operator=(const sCaplinkManager::cProfile& prof);
        void copy(const sCaplinkManager::cProfile& prof);
    public:
        MtStringEx<33> mUniqueId;  // offset: 0x8
        MtStringEx<81> mNickname;  // offset: 0x30
        MtStringEx<257> mIconUrl;  // offset: 0x88
        MtStringEx<513> mComment;  // offset: 0x190
        u8 mIconIndex;  // offset: 0x398
        s8 mProfilePrivacy;  // offset: 0x399
        s8 mCaptalkPrivacy;  // offset: 0x39a
        s8 mFindSearch;  // offset: 0x39b
        s8 mContentVisible;  // offset: 0x39c
        s8 mOnlinePrivacy;  // offset: 0x39d
        s8 mNotifyAll;  // offset: 0x39e
        s8 mNotifyProfile;  // offset: 0x39f
        s8 mNotifyFriend;  // offset: 0x3a0
        s8 mNotifyTimeline;  // offset: 0x3a1
        s8 mNotifyChat;  // offset: 0x3a2
        s8 mNotifyInvite;  // offset: 0x3a3
        s8 mNotifyMorning;  // offset: 0x3a4
        s8 mNotifyAfternoon;  // offset: 0x3a5
        s8 mNotifyEvening;  // offset: 0x3a6
        s8 mNotifyMidnight;  // offset: 0x3a7
        static MyDTI DTI;
    };
public:
    class cIconUrl : public cCaplinkObject
    {
    public:
        class MyDTI;
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
        cIconUrl(s32 id, s16 category, s16 type, MT_CTSTR url);
        void set(s32 id, s16 category, s16 type, MT_CTSTR url);
        MT_CTSTR getUrl() const;
        bool isSame(MT_CTSTR url) const;
        bool isEmpty() const;
    public:
        MtStringEx<257> mUrl;  // offset: 0x8
        s32 mId;  // offset: 0x110
        s16 mCategory;  // offset: 0x114
        s16 mType;  // offset: 0x116
        static MyDTI DTI;
    };
public:
    class cProfIconLoader : public cCaplinkObject
    {
    public:
        class MyDTI;
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
        cProfIconLoader(s32 id, MT_CTSTR url);
        virtual ~cProfIconLoader();
        bool update();
        s32 getId();
    private:
        void release();
    private:
        MtStringEx<257> mURL;  // offset: 0x8
        void* mpImage;  // offset: 0x110
        u32 mImageSize;  // offset: 0x118
        u32 mHandle;  // offset: 0x11c
        s32 mId;  // offset: 0x120
    public:
        static MyDTI DTI;
    };
public:
    class cTagData
    {
    public:
        cTagData();
        void reset();
        void copy(sCaplinkManager::cTagData&);
        void copy(s32, MT_CTSTR);
    public:
        MT_CHAR mTagName[81];  // offset: 0x0
        s32 mTagId;  // offset: 0x54
    };
public:
    class cDate
    {
    public:
        cDate();
        cDate(MT_CTSTR date);
        cDate(const sCaplinkManager::cDate& date);
        cDate(MtTime& t);
        void operator=(const sCaplinkManager::cDate& date);
        void operator=(MT_CTSTR date);
        void copy(const sCaplinkManager::cDate& date);
        void copy(MtTime& t);
        void set(MT_CTSTR date);
        u64 getSortVal() const;
    public:
        u16 mYear;  // offset: 0x0
        u8 mMonth;  // offset: 0x2
        u8 mDay;  // offset: 0x3
        u8 mHour;  // offset: 0x4
        u8 mMin;  // offset: 0x5
        u8 mSec;  // offset: 0x6
    };
public:
    class cFriendRecvData : public cCaplinkObject
    {
    public:
        cFriendRecvData();
        void reset();
    public:
        MT_CHAR mUniqueId[33];  // offset: 0x8
        MT_CHAR mNickname[81];  // offset: 0x29
        MT_CHAR mMessage[513];  // offset: 0x7a
        sCaplinkManager::cDate mRequestAt;  // offset: 0x27c
        u8 mIconIndex;  // offset: 0x284
    };
public:
    class cContentData : public cCaplinkObject
    {
    public:
        class MyDTI;
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
        cContentData();
    public:
        MT_CHAR mContentId[33];  // offset: 0x8
        MT_CHAR mContentName[81];  // offset: 0x29
        MT_CHAR mTagName[81];  // offset: 0x7a
        s32 mTagId;  // offset: 0xcc
        bool mIsDisp;  // offset: 0xd0
        static MyDTI DTI;
    };
public:
    class cGroupChatData : public cCaplinkObject
    {
    public:
        class MyDTI;
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
        cGroupChatData();
        void operator=(const sCaplinkManager::cGroupChatData& data);
        void copy(const sCaplinkManager::cGroupChatData& data);
    public:
        MT_CHAR mId[33];  // offset: 0x8
        MT_CHAR mGroupName[81];  // offset: 0x29
        MT_CHAR mOwnerUniqueId[33];  // offset: 0x7a
        MT_CHAR mOwnerNickname[81];  // offset: 0x9b
        sCaplinkManager::cDate mUpdatedAt;  // offset: 0xec
        s32 mGroupSkinId;  // offset: 0xf4
        s32 mLastChatId;  // offset: 0xf8
        s32 mReadChatId;  // offset: 0xfc
        s32 mMemberTotal;  // offset: 0x100
        s32 mMemberLimit;  // offset: 0x104
        u8 mOwnerIconIndex;  // offset: 0x108
        s8 mIdType;  // offset: 0x109
        s8 mStatus;  // offset: 0x10a
        static MyDTI DTI;
    };
public:
    class cChatInfo : public cCaplinkObject
    {
    public:
        class MyDTI;
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
        cChatInfo();
    public:
        s32 mChatId;  // offset: 0x8
        u32 mUserIndex;  // offset: 0xc
        sCaplinkManager::cDate mDate;  // offset: 0x10
        MtString mMessage;  // offset: 0x18
        bool mIsSystem;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class cChatJoin : public cCaplinkObject
    {
    public:
        class MyDTI;
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
        cChatJoin();
        cChatJoin(s32 id, bool join);
    public:
        s32 mChatId;  // offset: 0x8
        bool mIsJoin;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cCaplinkWebsocketListener : public nCaplink::WebsocketListener
    {
    public:
        cCaplinkWebsocketListener();
        // Address: 0x01abda00 - 0x01abda01 (1 bytes)
        virtual ~cCaplinkWebsocketListener() {}
        virtual void onOpen();  // vtable slot 2
        virtual void onNotifyChat(nCaplink::WebsocketNotifyChat* notify);  // vtable slot 3
        virtual void onError(s32 error_code);  // vtable slot 4
        virtual void onClose();  // vtable slot 5
        bool isConnected();
        bool isError();
        bool isRegistDevice();
        void offRegistDevice();
        void resetFlag();
    private:
        bool mIsConnected;  // offset: 0xc
        bool mIsError;  // offset: 0xd
        bool mIsRegistDevice;  // offset: 0xe
    };
public:
    class cChatMessageParser : public MtJsonReader::Handler
    {
    public:
        enum
        {
            GROUP_NAME = 0,
            GROUP_SKIN_ID = 1,
            OWNER_UNIQUE_ID = 2,
            ADD = 3,
            LEAVE = 4,
            KICK = 5,
            RESIGN = 6,
            MESSAGE = 7,
            FLAG_NUM = 8,
        };
    public:
        cChatMessageParser();
        cChatMessageParser(MT_CTSTR pMessage);
        // Address: 0x01abfd60 - 0x01abfd61 (1 bytes)
        virtual void beginArray() {}  // vtable slot 2
        // Address: 0x01abfd70 - 0x01abfd71 (1 bytes)
        virtual void endArray() {}  // vtable slot 3
        // Address: 0x01abfd80 - 0x01abfd81 (1 bytes)
        virtual void beginObject() {}  // vtable slot 4
        // Address: 0x01abfd90 - 0x01abfd91 (1 bytes)
        virtual void endObject() {}  // vtable slot 5
        virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
        virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
        // Address: 0x01abfda0 - 0x01abfda1 (1 bytes)
        virtual void number(u64 value) {}  // vtable slot 8
        virtual void number(s64 value);  // vtable slot 9
        // Address: 0x01abfdb0 - 0x01abfdb1 (1 bytes)
        virtual void number(f64 value) {}  // vtable slot 10
        virtual void booleanTrue();  // vtable slot 11
        virtual void booleanFalse();  // vtable slot 12
        void parse(MT_CTSTR pMessage);
    public:
        u32 mFlag;  // offset: 0xc
        bool mIsReceive[8];  // offset: 0x10
        MtString mGroupName;  // offset: 0x18
        MtString mUniqueId;  // offset: 0x20
        MtString mMessage;  // offset: 0x28
        s32 mGroupSkinId;  // offset: 0x30
        u8 mIsResign;  // offset: 0x34
    };
public:
    class cFriendData : public cCaplinkObject
    {
    public:
        enum
        {
            FLAG_INVITE_ENABLE = 0,
        };
    public:
        cFriendData();
        void reset();
        void operator=(const sCaplinkManager::cFriendData& data);
        void copy(const sCaplinkManager::cFriendData& data);
        void setFlag(u32 flag, bool isOn);
        bool isFlag(u32 flag) const;
    public:
        MT_CHAR mUniqueId[33];  // offset: 0x8
        MT_CHAR mName[81];  // offset: 0x29
        sCaplinkManager::cDate mAccordAt;  // offset: 0x7a
        sCaplinkManager::ContentBit mContent;  // offset: 0x84
        sCaplinkManager::ContentBit mContentOnline;  // offset: 0x94
        u16 mFreeTag;  // offset: 0xa4
        u8 mFlag;  // offset: 0xa6
        u8 mIconIndex;  // offset: 0xa7
        s8 mPrivacy;  // offset: 0xa8
        s8 mAttribute;  // offset: 0xa9
    };
public:
    class cChatList
    {
    public:
        cChatList();
    public:
        MtStringEx<33> mId;  // offset: 0x0
        MtStringEx<81> mChatGroupName;  // offset: 0x28
        s32 mIdType;  // offset: 0x80
        s32 mChatStatus;  // offset: 0x84
        s32 mLastChatId;  // offset: 0x88
        s32 mReadChatId;  // offset: 0x8c
        s32 mTopId;  // offset: 0x90
        s32 mBottomId;  // offset: 0x94
        s32 mAddCount;  // offset: 0x98
        bool mIsForward;  // offset: 0x9c
        bool mIsFirst;  // offset: 0x9d
        MtTypedArray<nCaplink::cUserBaseInfo> mUser;  // offset: 0xa0
        MtTypedArray<sCaplinkManager::cChatInfo> mChat;  // offset: 0xc0
        MtTypedArray<sCaplinkManager::cChatJoin> mJoin;  // offset: 0xe0
        static const u32 chat_max = 20;
        static const s32 req_num = 10;
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
    sCaplinkManager();
    virtual ~sCaplinkManager();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void init();
    void end(bool isForce);
    MT_CTSTR getContentId();
    MT_CTSTR getApiVersion();
    MT_CTSTR getClientVersion();
    MT_CTSTR getFrontUrls();
    MT_CTSTR getFrontUrl();
    MT_CTSTR getFrontPath();
    nCaplink::PlatformID getPlatformID();
    MT_CTSTR getHpUrl();
    MT_CTSTR getUrl(u32 type);
    void addListener(nCaplink::ContextListener* pListener, CALLBACK_FUNC pCallback);
    void updateListener();
    bool isDispErrorDialog();
    void login(MT_CTSTR login_id, MT_CTSTR password, MT_CTSTR content_user_id);
    void loginCallback();
    void loginCogKey(MT_CTSTR session_key, MT_CTSTR content_user_id, bool isNoDispCOGError);
    void loginCogKeyCallback();
    void reauth(MT_CTSTR session_key, MT_CTSTR content_user_id);
    void reauthCallback();
    void userSearch(s32 searchType, MT_CTSTR keyword, s32 offset, s32 count);
    void userSearchCallback();
    void userProfileContentListGet(MT_CTSTR unique_id, s32 offset, s32 count);
    void userProfileContentListGetCallback();
    void userProfileContentModify(MT_CTSTR content_id, MT_CTSTR character_name, MT_CTSTR comment, s8 online_privacy, s8 visible);
    void userProfileContentModifyCallback();
    void userProfileGet(MT_CTSTR unique_id);
    void userProfileGetCallback();
    void userProfileModify(MT_CTSTR nickname, s32 icon_id, MT_CTSTR comment, s32 timeline_skin_id, s32 profile_skin_id, s8 timeline_privacy, s8 profile_privacy, s8 captalk_privacy, s8 find_search);
    void userProfileModifyCallback();
    void userIgnoreTotalGet();
    void userIgnoreTotalGetCallback();
    void userIgnoreListGet(s32 offset, s32 count);
    void userIgnoreListGetCallback();
    void userIgnoreRemove(MT_CTSTR unique_id);
    void userIgnoreRemoveCallback();
    void friendEntrySend(MT_CTSTR unique_id, MT_CTSTR message, s32 cause);
    void friendEntrySendCallback();
    void friendEntryCancel(MT_CTSTR unique_id);
    void friendEntryCancelCallback();
private:
    void friendEntryRecvListGet(s32 offset, s32 count);
    void friendEntryRecvListGetCallback();
public:
    void friendEntrySendListGet(s32 offset, s32 count);
    void friendEntrySendListGetCallback();
    void friendEntryReply(MT_CTSTR unique_id, s32 reply);
    void friendEntryReplyCallback();
private:
    void friendListGet(s32 offset, s32 count);
    void friendListGetCallback();
public:
    void friendAttribute(MT_CTSTR unique_id, s8 attribute);
    void friendAttributeCallback();
private:
    void friendTagContentTotalGet();
    void friendTagContentTotalGetCallback();
    void friendTagContentListGet(s32 offset, s32 count);
    void friendTagContentListGetCallback();
    void friendTagFreeTotalGet();
    void friendTagFreeTotalGetCallback();
    void friendTagFreeListGet(s32 offset, s32 count);
    void friendTagFreeListGetCallback();
public:
    void friendTagFree(MT_CTSTR unique_id, MtArray* free_tag_alive_info_list);
    void friendTagFreeCallback();
    void friendRelease(MT_CTSTR unique_id);
    void friendReleaseCallback();
    void friendModify(MT_CTSTR unique_id, MT_CTSTR labelname, MT_CTSTR memo);
    void friendModifyCallback();
private:
    void tagTotalGet();
    void tagTotalGetCallback();
    void tagListGet();
    void tagListGetCallback();
public:
    void tagModify(MtArray* tag_info_list);
    void tagModifyCallback();
    void tagVisibleModify(s32 tag_id, s8 visible);
    void tagVisibleModifyCallback();
    void tagVisibleListGet();
    void tagVisibleListGetCallback();
private:
    void contentTotalGet();
    void contentTotalGetCallback();
    void contentListGet(s32 offset, s32 count);
    void contentListGetCallback();
public:
    void contentInviteAvailableListGet(s32 offset, s32 count);
    void contentInviteAvailableListGetCallback();
    void contentInvite(MT_CTSTR unique_id, MT_CTSTR message);
    void contentInviteCallback();
    void contentInviteTotalGet();
    void contentInviteTotalGetCallback();
    void contentInviteListGet(s32 offset, s32 count);
    void contentInviteListGetCallback();
    void contentInviteRemove(MT_CTSTR unique_id, MT_CTSTR content_id);
    void contentInviteRemoveCallback();
    void contentAchievementGet(MT_CTSTR content_id);
    void contentAchievementGetCallback();
    void contentAchievementListGet(MT_CTSTR content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count);
    void contentAchievementListGetCallback();
    void contentAchievementRelationGet(MT_CTSTR filtering_content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count);
    void contentAchievementRelationGetCallback();
    void chatListGet(s32 id_type, MT_CTSTR unique_id, s32 offset_id, s32 count);
    void chatListGetCallback();
    void chatLastId(s8 id_type, MT_CTSTR unique_id);
    void chatLastIdCallback();
    void chatSend(s32 chat_type, MT_CTSTR unique_id, MT_CTSTR message, s32 stamp_id, MT_CTSTR image, MT_CTSTR position);
    void chatSendCallback();
    void chatRead(s32 chat_type, MT_CTSTR unique_id, s32 chat_id);
    void chatReadCallback();
    void chatGroupCreate(MT_CTSTR group_name, s32 group_skin_id, MT_CTSTR group_message);
    void chatGroupCreateCallback();
    void chatGroupResign(MT_CTSTR group_id);
    void chatGroupResignCallback();
    void chatGroupRemove(s32 chat_type, MT_CTSTR group_id);
    void chatGroupRemoveCallback();
    void chatGroupMemberAdd(MT_CTSTR group_id);
    void chatGroupMemberAddCallback();
    void chatGroupMemberListGet(MT_CTSTR group_id, s32 offset, s32 count);
    void chatGroupMemberListGetCallback();
    void chatGroupMemberReject(MT_CTSTR group_id, MT_CTSTR unique_id);
    void chatGroupMemberRejectCallback();
    void chatGroupMemberLeave(MT_CTSTR group_id);
    void chatGroupMemberLeaveCallback();
private:
    void chatGroupListGet(s32 offset, s32 count);
    void chatGroupListGetCallback();
public:
    void chatGroupModify(MT_CTSTR group_id, MT_CTSTR group_name, s32 group_skin_id);
    void chatGroupModifyCallback();
    void resourcePresetTotalGet(s8 resource_type);
    void resourcePresetTotalGetCallback();
    void resourcePresetListGet(s8 resource_type, s32 offset, s32 count);
    void resourcePresetListGetCallback();
    void notify();
    void notifyCallback();
    void notifyAppListGet(s32 offset, s32 count);
    void notifyAppListGetCallback();
    void notifyAppRead(s32 notify_id);
    void notifyAppReadCallback();
    void notifyDeviceSetting();
    void notifyDeviceSettingCallback();
    void notifyDeviceSettingModify(s8 all, s8 profile, s8 fri, s8 timeline, s8 chat, s8 game);
    void notifyDeviceSettingModifyCallback();
    void notifyTimeGet();
    void notifyTimeGetCallback();
    void notifyTimeModify(s8 morning, s8 afternoon, s8 evening, s8 midnight);
    void notifyTimeModifyCallback();
    void report(MT_CTSTR unique_id, s8 place, MT_CTSTR detail);
    void reportCallback();
    void websocketServerListGet();
    void websocketServerListGetCallback();
    MT_CTSTR getMyUniqueId();
    bool isMyUniqueId(MT_CTSTR unique_id);
    const cProfile& getMyProfile();
    void updateMyProfile(const cProfile& prof);
    bool isLogin();
    bool isNoDispCOGError();
    bool setupWebsocket();
    void updateWebsocket();
    bool isWebsocketRetry();
    const MtTypedArray<cIconUrl>& getIconUrlList();
    const cIconUrl* getIconUrlFromIndex(u32 index);
    void addIconUrl(s32 id, s16 category, s16 type, MT_CTSTR url);
    u32 getIconIndex(MT_CTSTR url);
    u32 getProfIconNum();
    void loadProfIcon(s32 id, MT_CTSTR url);
    void updateProfIcon();
    bool isLoadingProfIcon(s32 id);
    bool isLoadingProfIcon();
    bool setupProfIcon();
    const cFriendData* getFriendData(u32 index);
    const cFriendData* getFriendData(MT_CTSTR unique_id);
    u32 getFriendIndex(MT_CTSTR unique_id);
    u32 getFriendNum();
    bool isFriendUniqueId(MT_CTSTR unique_id);
    void setFriendData(const cFriendData& in_data);
    void deleteFriendData(MT_CTSTR unique_id);
    void setFriendAttrDisp(u32 attr, bool isDisp);
    bool isFriendAttrDisp(u32 attr);
    const cContentData* getContentData(u32 index);
    const cContentData* getContentData(MT_CTSTR content_id);
    u32 getContentIndex(MT_CTSTR content_id);
    u32 getContentNum();
    void setContentDisp(u32 index, bool isDisp);
    bool isContentDisp(u32 index);
    bool isContentDisp(const ContentBit& bit);
    bool isDispNoneContent();
    void setDispNoneContent(bool isDisp);
    const cTagData* getFreeTagData(u32 index);
    u32 getFreeTagIndex(s32 tag_id);
    u32 getFreeTagNum();
    void setFreeTagDisp(u32 index, bool isDisp);
    u32 getFreeTagDisp();
    bool isFreeTagDisp(u32 index);
    bool isDispNoneTag();
    void setDispNoneTag(bool isDisp);
    const cFriendRecvData* getFriendRecvData(u32 index);
    u32 getFriendRecvIndex(MT_CTSTR unique_id);
    u32 getFriendRecvNum();
    void deleteFriendRecvData(MT_CTSTR unique_id);
    const cGroupChatData* getGroupChatData(u32 index);
    const cGroupChatData* getGroupChatData(s8 id_type, MT_CTSTR unique_id);
    void setGroupChatData(const cGroupChatData& in_data);
    u32 getGroupChatIndex(s8 id_type, MT_CTSTR unique_id);
    u32 getGroupChatNum();
    const MtTypedArray<nCaplink::cUserBaseInfo>& getChatMember();
    const nCaplink::cUserBaseInfo* getChatMember(u32 index);
    void addChatMember(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon);
    void deleteChatMember(MT_CTSTR unique_id);
    void clearChatMember();
    bool isChatMember(MT_CTSTR unique_id);
    u32 getChatMemberNum();
    void sortChatList();
    const cChatList& getChatList();
    const nCaplink::cUserBaseInfo* getChatListUserConst(u32 index);
    void clearChatList();
    void addChatList(const nCaplink::WebsocketNotifyChat* notify);
private:
    void addChatList(const nCaplink::cChatUserInfo* pInfo);
    void addChatList(s32 chat_id, MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR message, MT_CTSTR date);
    cChatInfo* createChatInfo(s32 chat_id, MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR message, MT_CTSTR date);
    u32 getChatListUserIndex(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon);
    nCaplink::cUserBaseInfo* getChatListUser(u32 index);
    void compactionChatList();
    void addChatJoin(s32 chat_id, bool is_join);
    bool isChatJoin(s32 chat_id);
public:
    void initData();
    void resetDate();
    void resetList();
    void resetFriendList();
    void saveDate();
    void applySavedDate(MtStringEx<21>& date);
    void setReqFlag(u32 flag, bool isDispError);
    bool isReqFlag(u32 flag);
    bool isReqDispError(u32 flag);
    void setReqDispError(u32 flag);
    void endReqFlag(u32 flag);
    void reqNextUpdate();
    void reqMyProf(bool isDispError);
    void reqContentListUpdate(bool isDispError);
    void reqFreeTagListUpdate(bool isDispError);
    void reqFriendListUpdate(bool isDispError);
    void reqFriendContentUpdate(bool isDispError);
    void reqFriendFreeTagListUpdate(bool isDispError);
    void reqFriendRecvUpdate(bool isDispError);
    void reqFriendInviteEnableUpdate(bool isDispError);
    void reqGroupChatListUpdate(bool isDispError);
    void reqNotifyDetailUpdate(bool isDispError);
    void reqChatListUpdate(s32 id_type, MT_CTSTR id, bool is_forward);
    void updateMyProf();
    void updateContentList();
    void updateFreeTagList();
    void updateFriendList();
    void updateFriendContent();
    void updateFriendFreeTagList();
    void updateFriendRecv();
    void updateFriendInviteEnable();
    void updateGroupChatList();
    void updateNotifyDetail();
    void updateChatList();
    void updateNotify();
    bool isCompleteRequest();
    void initUserSearch();
    void initChatGroupMemberList();
    void initFriendTagFree();
    void initContentAchievementList();
    void initContentAchievementRelation();
    bool isInfoFriendOnline();
    bool isInfoFriendRequest();
    bool isInfoFriendConsent();
    bool isInfoFriendModify();
    bool isInfoInvite();
    bool isInfoNewChat();
    bool isInfoMessage();
    bool isNoticeMaintenance();
    bool isMaintenanceNow();
    void setConfirmInformation();
    void setMaintenanceNow(bool flag);
    const cDate& getMaintenanceDate();
    void setConnection(bool flag);
    bool isConnection();
    bool isEnableMessage(MT_CTSTR pMsg);
private:
    void convSJIStoUTF8(const MT_CHAR* pSrcSjis, MT_CHAR* pDstUtf8, u32 bufSizeUtf8);
public:
    const nCaplink::LoginAns& getLoginAns();
    const nCaplink::LoginCogKeyAns& getLoginCogKeyAns();
    const nCaplink::ReauthAns& getReauthAns();
    const nCaplink::UserSearchAns& getUserSearchAns();
    const nCaplink::UserProfileGetAns& getUserProfileGetAns();
    const nCaplink::UserProfileContentListGetAns& getUserProfileContentListGetAns();
    const nCaplink::UserProfileContentModifyAns& getUserProfileContentModifyAns();
    const nCaplink::UserProfileModifyAns& getUserProfileModifyAns();
    const nCaplink::UserIgnoreTotalGetAns& getUserIgnoreTotalGetAns();
    const nCaplink::UserIgnoreListGetAns& getUserIgnoreListGetAns();
    const nCaplink::UserIgnoreRemoveAns& getUserIgnoreRemoveAns();
    const nCaplink::FriendEntrySendAns& getFriendEntrySendAns();
    const nCaplink::FriendEntryCancelAns& getFriendEntryCancelAns();
    const nCaplink::FriendEntryRecvListGetAns& getFriendEntryRecvListGetAns();
    const nCaplink::FriendEntrySendListGetAns& getFriendEntrySendListGetAns();
    const nCaplink::FriendEntryReplyAns& getFriendEntryReplyAns();
    const nCaplink::FriendListGetAns& getFriendListGetAns();
    const nCaplink::FriendAttributeAns& getFriendAttributeAns();
    const nCaplink::FriendTagContentTotalGetAns& getFriendTagContentTotalGetAns();
    const nCaplink::FriendTagContentListGetAns& getFriendTagContentListGetAns();
    const nCaplink::FriendTagFreeTotalGetAns& getFriendTagFreeTotalGetAns();
    const nCaplink::FriendTagFreeListGetAns& getFriendTagFreeListGetAns();
    const nCaplink::FriendTagFreeAns& getFriendTagFreeAns();
    const nCaplink::FriendReleaseAns& getFriendReleaseAns();
    const nCaplink::FriendModifyAns& getFriendModifyAns();
    const nCaplink::TagTotalGetAns& getTagTotalGetAns();
    const nCaplink::TagListGetAns& getTagListGetAns();
    const nCaplink::TagModifyAns& getTagModifyAns();
    const nCaplink::TagVisibleModifyAns& getTagVisibleModifyAns();
    const nCaplink::TagVisibleListGetAns& getTagVisibleListGetAns();
    const nCaplink::ContentTotalGetAns& getContentTotalGetAns();
    const nCaplink::ContentListGetAns& getContentListGetAns();
    const nCaplink::ContentInviteAvailableListGetAns& getContentInviteAvailableListGetAns();
    const nCaplink::ContentInviteAns& getContentInviteAns();
    const nCaplink::ContentInviteTotalGetAns& getContentInviteTotalGetAns();
    const nCaplink::ContentInviteListGetAns& getContentInviteListGetAns();
    const nCaplink::ContentInviteRemoveAns& getContentInviteRemoveAns();
    const nCaplink::ContentAchievementGetAns& getContentAchievementGetAns();
    const nCaplink::ContentAchievementListGetAns& getContentAchievementListGetAns();
    const nCaplink::ContentAchievementRelationGetAns& getContentAchievementRelationGetAns();
    const nCaplink::ChatListGetAns& getChatListGetAns();
    const nCaplink::ChatLastIdAns& getChatLastIdAns();
    const nCaplink::ChatReadAns& getChatReadAns();
    const nCaplink::ChatSendAns& getChatSendAns();
    const nCaplink::ChatGroupCreateAns& getChatGroupCreateAns();
    const nCaplink::ChatGroupResignAns& getChatGroupResignAns();
    const nCaplink::ChatGroupRemoveAns& getChatGroupRemoveAns();
    const nCaplink::ChatGroupMemberAddAns& getChatGroupMemberAddAns();
    const nCaplink::ChatGroupMemberListGetAns& getChatGroupMemberListGetAns();
    const nCaplink::ChatGroupMemberRejectAns& getChatGroupMemberRejectAns();
    const nCaplink::ChatGroupMemberLeaveAns& getChatGroupMemberLeaveAns();
    const nCaplink::ChatGroupListGetAns& getChatGroupListGetAns();
    const nCaplink::ChatGroupModifyAns& getChatGroupModifyAns();
    const nCaplink::ResourcePresetTotalGetAns& getResourcePresetTotalGetAns();
    const nCaplink::ResourcePresetListGetAns& getResourcePresetListGetAns();
    const nCaplink::NotifyAns& getNotifyAns();
    const nCaplink::NotifyAppListGetAns& getNotifyAppListGetAns();
    const nCaplink::NotifyAppReadAns& getNotifyAppReadAns();
    const nCaplink::NotifyDeviceSettingAns& getNotifyDeviceSettingAns();
    const nCaplink::NotifyDeviceSettingModifyAns& getNotifyDeviceSettingModifyAns();
    const nCaplink::NotifyTimeGetAns& getNotifyTimeGetAns();
    const nCaplink::NotifyTimeModifyAns& getNotifyTimeModifyAns();
    const nCaplink::ReportAns& getReportAns();
    const nCaplink::WebsocketServerListGetAns& getWebsocketServerListGetAns();
    static sCaplinkManager* getInstance();
private:
    nCaplink::Object* mpCaplink;  // offset: 0x18
    MtTypedArray<cCaplinkListenerQueue> mListener;  // offset: 0x20
    nCaplink::LoginAns mLoginAns;  // offset: 0x40
    nCaplink::LoginCogKeyAns mLoginCogKeyAns;  // offset: 0x2f8
    nCaplink::ReauthAns mReauthAns;  // offset: 0x5a8
    nCaplink::UserSearchAns mUserSearchAns;  // offset: 0x850
    nCaplink::UserProfileGetAns mUserProfileGetAns;  // offset: 0x890
    nCaplink::UserProfileContentListGetAns mUserProfileContentListGetAns;  // offset: 0xf58
    nCaplink::UserProfileContentModifyAns mUserProfileContentModifyAns;  // offset: 0xfa0
    nCaplink::UserProfileModifyAns mUserProfileModifyAns;  // offset: 0xfc0
    nCaplink::UserIgnoreTotalGetAns mUserIgnoreTotalGetAns;  // offset: 0xfe0
    nCaplink::UserIgnoreListGetAns mUserIgnoreListGetAns;  // offset: 0x1008
    nCaplink::UserIgnoreRemoveAns mUserIgnoreRemoveAns;  // offset: 0x1050
    nCaplink::FriendEntrySendAns mFriendEntrySendAns;  // offset: 0x1070
    nCaplink::FriendEntryCancelAns mFriendEntryCancelAns;  // offset: 0x1098
    nCaplink::FriendEntryRecvListGetAns mFriendEntryRecvListGetAns;  // offset: 0x10b8
    nCaplink::FriendEntrySendListGetAns mFriendEntrySendListGetAns;  // offset: 0x1100
    nCaplink::FriendEntryReplyAns mFriendEntryReplyAns;  // offset: 0x1148
    nCaplink::FriendListGetAns mFriendListGetAns;  // offset: 0x1168
    nCaplink::FriendAttributeAns mFriendAttributeAns;  // offset: 0x11b0
    nCaplink::FriendTagContentTotalGetAns mFriendTagContentTotalGetAns;  // offset: 0x11d8
    nCaplink::FriendTagContentListGetAns mFriendTagContentListGetAns;  // offset: 0x1200
    nCaplink::FriendTagFreeTotalGetAns mFriendTagFreeTotalGetAns;  // offset: 0x1248
    nCaplink::FriendTagFreeListGetAns mFriendTagFreeListGetAns;  // offset: 0x1270
    nCaplink::FriendTagFreeAns mFriendTagFreeAns;  // offset: 0x12b8
    nCaplink::FriendReleaseAns mFriendReleaseAns;  // offset: 0x12e0
    nCaplink::FriendModifyAns mFriendModifyAns;  // offset: 0x1308
    nCaplink::TagTotalGetAns mTagTotalGetAns;  // offset: 0x1328
    nCaplink::TagListGetAns mTagListGetAns;  // offset: 0x1350
    nCaplink::TagModifyAns mTagModifyAns;  // offset: 0x1398
    nCaplink::TagVisibleModifyAns mTagVisibleModifyAns;  // offset: 0x13b8
    nCaplink::TagVisibleListGetAns mTagVisibleListGetAns;  // offset: 0x13d8
    nCaplink::ContentTotalGetAns mContentTotalGetAns;  // offset: 0x1420
    nCaplink::ContentListGetAns mContentListGetAns;  // offset: 0x1448
    nCaplink::ContentInviteAvailableListGetAns mContentInviteAvailableListGetAns;  // offset: 0x1490
    nCaplink::ContentInviteAns mContentInviteAns;  // offset: 0x14d8
    nCaplink::ContentInviteTotalGetAns mContentInviteTotalGetAns;  // offset: 0x14f8
    nCaplink::ContentInviteListGetAns mContentInviteListGetAns;  // offset: 0x1520
    nCaplink::ContentInviteRemoveAns mContentInviteRemoveAns;  // offset: 0x1568
    nCaplink::ContentAchievementGetAns mContentAchievementGetAns;  // offset: 0x1588
    nCaplink::ContentAchievementListGetAns mContentAchievementListGetAns;  // offset: 0x2078
    nCaplink::ContentAchievementRelationGetAns mContentAchievementRelationGetAns;  // offset: 0x20c0
    nCaplink::ChatListGetAns mChatListGetAns;  // offset: 0x2108
    nCaplink::ChatLastIdAns mChatLastIdAns;  // offset: 0x2168
    nCaplink::ChatReadAns mChatReadAns;  // offset: 0x2190
    nCaplink::ChatSendAns mChatSendAns;  // offset: 0x21b0
    nCaplink::ChatGroupCreateAns mChatGroupCreateAns;  // offset: 0x21e0
    nCaplink::ChatGroupResignAns mChatGroupResignAns;  // offset: 0x2230
    nCaplink::ChatGroupRemoveAns mChatGroupRemoveAns;  // offset: 0x2250
    nCaplink::ChatGroupMemberAddAns mChatGroupMemberAddAns;  // offset: 0x2270
    nCaplink::ChatGroupMemberListGetAns mChatGroupMemberListGetAns;  // offset: 0x2290
    nCaplink::ChatGroupMemberRejectAns mChatGroupMemberRejectAns;  // offset: 0x2300
    nCaplink::ChatGroupMemberLeaveAns mChatGroupMemberLeaveAns;  // offset: 0x2320
    nCaplink::ChatGroupListGetAns mChatGroupListGetAns;  // offset: 0x2340
    nCaplink::ChatGroupModifyAns mChatGroupModifyAns;  // offset: 0x2388
    nCaplink::ResourcePresetTotalGetAns mResourcePresetTotalGetAns;  // offset: 0x23a8
    nCaplink::ResourcePresetListGetAns mResourcePresetListGetAns;  // offset: 0x23d0
    nCaplink::NotifyAns mNotifyAns;  // offset: 0x2418
    nCaplink::NotifyAppListGetAns mNotifyAppListGetAns;  // offset: 0x2488
    nCaplink::NotifyAppReadAns mNotifyAppReadAns;  // offset: 0x24d0
    nCaplink::NotifyDeviceSettingAns mNotifyDeviceSettingAns;  // offset: 0x24f0
    nCaplink::NotifyDeviceSettingModifyAns mNotifyDeviceSettingModifyAns;  // offset: 0x2518
    nCaplink::NotifyTimeGetAns mNotifyTimeGetAns;  // offset: 0x2538
    nCaplink::NotifyTimeModifyAns mNotifyTimeModifyAns;  // offset: 0x2560
    nCaplink::ReportAns mReportAns;  // offset: 0x2580
    nCaplink::WebsocketServerListGetAns mWebsocketServerListGetAns;  // offset: 0x25a0
    bool mIsLogin;  // offset: 0x25e8
    cProfile mMyProfile;  // offset: 0x25f0
    bool mIsReqMyProfile;  // offset: 0x2998
    MtTypedArray<cIconUrl> mIconUrl;  // offset: 0x29a0
    u32 mProfIconNum;  // offset: 0x29c0
    MtTypedArray<cProfIconLoader> mProfIconLoader;  // offset: 0x29c8
    u32 mRnoProfIcon;  // offset: 0x29e8
    cTagData mFreeTag[10];  // offset: 0x29ec
    u16 mFreeTagNum;  // offset: 0x2d5c
    u32 mFreeTagDisp;  // offset: 0x2d60
    bool mIsDispNoneTag;  // offset: 0x2d64
    cFriendData* mFriendData;  // offset: 0x2d68
    u16 mFriendNum;  // offset: 0x2d70
    u32 mFriendAttrDisp;  // offset: 0x2d74
    cFriendRecvData* mFriendRecv;  // offset: 0x2d78
    u16 mFriendRecvNum;  // offset: 0x2d80
    MtTypedArray<cContentData> mContentData;  // offset: 0x2d88
    bool mIsDispNoneContent;  // offset: 0x2da8
    MtTypedArray<cGroupChatData> mGroupChatData;  // offset: 0x2db0
    MtTypedArray<nCaplink::cUserBaseInfo> mChatMember;  // offset: 0x2dd0
    cChatList mChatList;  // offset: 0x2df0
    u8 mRnoMain;  // offset: 0x2ef0
    u8 mRnoWebsocket;  // offset: 0x2ef1
    u8 mConnectWebsocketServerNo;  // offset: 0x2ef2
    MtTypedArray<nCaplink::cWebsocketServerInfo> mWebsocketServerList;  // offset: 0x2ef8
    cCaplinkWebsocketListener mWebsocketListener;  // offset: 0x2f18
    MtTime mNextNotifyTime;  // offset: 0x2f28
    bool mIsFirstBoot;  // offset: 0x2f30
    bool mIsFirstUpdate;  // offset: 0x2f31
    bool mIsNoDispCOGError;  // offset: 0x2f32
    bool mIsNoDispError;  // offset: 0x2f33
    MtStringEx<21> mDateFriendList;  // offset: 0x2f34
    MtStringEx<21> mDateFriendContentTagList;  // offset: 0x2f50
    MtStringEx<21> mDateFriendRecv;  // offset: 0x2f6c
    MtStringEx<21> mDateFriendFreeTag;  // offset: 0x2f88
    MtStringEx<21> mDateTag;  // offset: 0x2fa4
    MtStringEx<21> mDateContentList;  // offset: 0x2fc0
    MtStringEx<21> mDateContentInvite;  // offset: 0x2fdc
    MtStringEx<21> mDateStamp;  // offset: 0x2ff8
    MtStringEx<21> mDatePresetResource;  // offset: 0x3014
    MtStringEx<21> mDateProfile;  // offset: 0x3030
    MtStringEx<21> mDateChatGroupList;  // offset: 0x304c
    MtStringEx<21> mDateTemp;  // offset: 0x3068
    u32 mRnoUpdate;  // offset: 0x3084
    u32 mUpdateOffset;  // offset: 0x3088
    u32 mUpdateCount;  // offset: 0x308c
    u32 mUpdateFlag;  // offset: 0x3090
    u32 mUpdateDispError;  // offset: 0x3094
    cDate mMaintenanceDate;  // offset: 0x3098
    bool mIsInfoFriendOnline;  // offset: 0x30a0
    bool mIsInfoFriendRequest;  // offset: 0x30a1
    bool mIsInfoFriendConsent;  // offset: 0x30a2
    bool mIsInfoFriendModify;  // offset: 0x30a3
    bool mIsInfoInvite;  // offset: 0x30a4
    bool mIsInfoNewChat;  // offset: 0x30a5
    bool mIsInfoMessage;  // offset: 0x30a6
    bool mIsMaintenance;  // offset: 0x30a7
    bool mIsMaintenanceNow;  // offset: 0x30a8
    bool mIsConnection;  // offset: 0x30a9
    u32 mTimeCountRno;  // offset: 0x30ac
    f32 mTimeoutTimer;  // offset: 0x30b0
public:
    static const u32 CAPLINK_FREE_TAG_MAX = 10;
    static const u32 CAPLINK_FRIEND_MAX = 1000;
    static const u32 CAPLINK_FRIEND_RECV_MAX = 1000;
    static const u32 DDO_NAME_LENGTH = 24;
    static const u32 INVALID_PROF_ICON_INDEX = 255;
    static MyDTI DTI;
private:
    static sCaplinkManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sCaplinkManager* sCaplinkManager::getInstance() {
    return ::sCaplinkManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a comparison accessor's polarity, the comparison the code makes (`==` over `!=`, `<` over `>=`, `<=` over `>`): none of its 6 DWARF copies materializes its result; approximate: only approximate callers check this inline body
inline bool sCaplinkManager::cCaplinkListenerQueue::isDispError() {
    return this->mErrorDialogHandle == static_cast<u32>(4294967295);
}
