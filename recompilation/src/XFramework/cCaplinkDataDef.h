#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class uGUICaplinkProfile;
class uGUICaplinkTalk;

// Declarations
namespace nCaplink { class cAchievementExtendedInfo; }
namespace nCaplink { class cAchievementListInfo; }
namespace nCaplink { class cAchievementRelationInfo; }
namespace nCaplink { class cAchievementRewardInfo; }
namespace nCaplink { class cChatGroupInfo; }
namespace nCaplink { class cChatUserInfo; }
namespace nCaplink { class cContentInfo; }
namespace nCaplink { class cContentInviteAvailableUserInfo; }
namespace nCaplink { class cContentInviteUserInfo; }
namespace nCaplink { class cContentTagInfo; }
namespace nCaplink { class cFreeTagInfo; }
namespace nCaplink { class cFriendEntryInfo; }
namespace nCaplink { class cFriendInfo; }
namespace nCaplink { class cIgnoreUserInfo; }
namespace nCaplink { class cNotifyAppInfo; }
namespace nCaplink { class cResourceInfo; }
namespace nCaplink { class cTagInfo; }
namespace nCaplink { class cUserBaseInfo; }
namespace nCaplink { class cUserContentInfo; }
namespace nCaplink { class cUserProfile; }
namespace nCaplink { class cWebsocketServerInfo; }

namespace nCaplink {
    enum PlatformID
    {
        Undefined = 0,
        Windows = 1,
        Android = 2,
        IOS = 3,
        Xbox360 = 4,
        PS3 = 5,
        WiiU = 6,
        Vita = 7,
        PS4 = 8,
        XboxOne = 9,
    };
}  // namespace nCaplink

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nCaplink {
    class cAchievementExtendedInfo : public ::MtObject
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
        cAchievementExtendedInfo();
        void setId(s8 id);
        void setCount(s8 count);
        s8 getId() const;
        s8 getCount() const;
    private:
        s32 mId;  // offset: 0x8
        s32 mCount;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cAchievementListInfo : public ::MtObject
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
        cAchievementListInfo();
        void setDetail(MT_CTSTR detail);
        void setText(MT_CTSTR text);
        void setIconUrl(MT_CTSTR icon_url);
        void setStartAt(MT_CTSTR start_at);
        void setEndAt(MT_CTSTR end_at);
        void setId(s32 id);
        void setExtended(s8 extended);
        void setCategory(s8 category);
        void setAlive(s8 alive);
        void setDifficulty(s8 difficulty);
        void setIndefinite(s8 indefinite);
        void setBit(s8 bit);
        void setCount(s8 count);
        MT_CTSTR getDetail() const;
        MT_CTSTR getText() const;
        MT_CTSTR getIconUrl() const;
        MT_CTSTR getStartAt() const;
        MT_CTSTR getEndAt() const;
        s32 getId() const;
        s8 getExtended() const;
        s8 getCategory() const;
        s8 getAlive() const;
        s8 getDifficulty() const;
        s8 getIndefinite() const;
        s8 getBit() const;
        s8 getCount() const;
    private:
        char mDetail[257];  // offset: 0x8
        char mText[513];  // offset: 0x109
        char mIconUrl[257];  // offset: 0x30a
        char mStartAt[21];  // offset: 0x40b
        char mEndAt[21];  // offset: 0x420
        s32 mId;  // offset: 0x438
        s8 mExtended;  // offset: 0x43c
        s8 mCategory;  // offset: 0x43d
        s8 mAlive;  // offset: 0x43e
        s8 mDifficulty;  // offset: 0x43f
        s8 mIndefinite;  // offset: 0x440
        s8 mBit;  // offset: 0x441
        s8 mCount;  // offset: 0x442
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cAchievementRewardInfo : public ::MtObject
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
        cAchievementRewardInfo();
        void setType(MT_CTSTR type);
        void setId(MT_CTSTR id);
        void setAmount(s32 amount);
        MT_CTSTR getType() const;
        MT_CTSTR getId() const;
        s32 getAmount() const;
    private:
        char mType[33];  // offset: 0x8
        char mId[33];  // offset: 0x29
        s32 mAmount;  // offset: 0x4c
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cChatGroupInfo : public ::MtObject
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
        cChatGroupInfo();
        cChatGroupInfo(s32 id_type, MT_CTSTR id, s32 status, s32 visible, MT_CTSTR group_name, s32 group_skin_id, MT_CTSTR owner_unique_id, MT_CTSTR owner_nickname, MT_CTSTR owner_icon, s32 last_chat_id, s32 read_chat_id, s32 member_total, s32 member_limmit, MT_CTSTR update_at);
        s32 getIdType() const;
        MT_CTSTR getId() const;
        s32 getStatus() const;
        s32 getVisible() const;
        MT_CTSTR getGroupName() const;
        s32 getGroupSkinId() const;
        MT_CTSTR getOwnerUniqueId() const;
        MT_CTSTR getOwnerNickname() const;
        MT_CTSTR getOwnerIcon() const;
        s32 getLastChatId() const;
        s32 getReadChatId() const;
        s32 getMemberTotal() const;
        s32 getMemberLimit() const;
        MT_CTSTR getUpdatedAt() const;
    private:
        s32 mIdType;  // offset: 0x8
        char mId[33];  // offset: 0xc
        s32 mStatus;  // offset: 0x30
        s32 mVisible;  // offset: 0x34
        char mGroupName[257];  // offset: 0x38
        s32 mGroupSkinId;  // offset: 0x13c
        char mOwnerUniqueId[33];  // offset: 0x140
        char mOwnerNickname[1021];  // offset: 0x161
        char mOwnerIcon[256];  // offset: 0x55e
        s32 mLastChatId;  // offset: 0x660
        s32 mReadChatId;  // offset: 0x664
        s32 mMemberTotal;  // offset: 0x668
        s32 mMemberLimit;  // offset: 0x66c
        char mUpdatedAt[21];  // offset: 0x670
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cChatUserInfo : public ::MtObject
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
        cChatUserInfo();
        cChatUserInfo(s32 chat_id, MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, s32 chat_type, MT_CTSTR message, s32 stamp_id, MT_CTSTR stamp, MT_CTSTR stamp_comment, MT_CTSTR image, MT_CTSTR image_pixel_size, MT_CTSTR position, s32 platform_id, MT_CTSTR content_id, MT_CTSTR create_at);
        s32 getChatId() const;
        MT_CTSTR getUniqueId() const;
        MT_CTSTR getNickname() const;
        MT_CTSTR getIcon() const;
        s32 getChatType() const;
        MT_CTSTR getMessage() const;
        s32 getStampId() const;
        MT_CTSTR getStamp() const;
        MT_CTSTR getStampComment() const;
        MT_CTSTR getImage() const;
        MT_CTSTR getImagePixelSize() const;
        MT_CTSTR getPosition() const;
        s32 getPlatform_id() const;
        MT_CTSTR getContentId() const;
        MT_CTSTR getCreatedAt() const;
    private:
        s32 mChatId;  // offset: 0x8
        char mUniqueId[33];  // offset: 0xc
        char mNickname[81];  // offset: 0x2d
        char mIcon[257];  // offset: 0x7e
        s32 mChatType;  // offset: 0x180
        char mMessage[2049];  // offset: 0x184
        s32 mStampId;  // offset: 0x988
        char mStamp[257];  // offset: 0x98c
        char mStampComment[1025];  // offset: 0xa8d
        char mImage[257];  // offset: 0xe8e
        char mImagePixelSize[17];  // offset: 0xf8f
        char mPosition[2049];  // offset: 0xfa0
        s32 mPlatform_id;  // offset: 0x17a4
        char mContentId[33];  // offset: 0x17a8
        char mCreatedAt[21];  // offset: 0x17c9
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cContentInfo : public ::MtObject
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
        cContentInfo();
        cContentInfo(MT_CTSTR content_id, MT_CTSTR content_name, s32 tag_id, MT_CTSTR tag_name, MT_CTSTR comment, MT_CTSTR appdata, s8 alive);
        MT_CTSTR getCotentId() const;
        MT_CTSTR getContentName() const;
        s32 getTagId() const;
        MT_CTSTR getTagName() const;
        MT_CTSTR getComment() const;
        MT_CTSTR getAppData() const;
        s8 getAlive() const;
    private:
        char mContentId[33];  // offset: 0x8
        char mContentName[257];  // offset: 0x29
        s32 mTagId;  // offset: 0x12c
        char mTagName[81];  // offset: 0x130
        char mComment[513];  // offset: 0x181
        char mAppData[1025];  // offset: 0x382
        s8 mAlive;  // offset: 0x783
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cContentInviteAvailableUserInfo : public ::MtObject
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
        cContentInviteAvailableUserInfo();
        cContentInviteAvailableUserInfo(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon);
        MT_CTSTR getUniqueId() const;
        MT_CTSTR getNickname() const;
        MT_CTSTR getIcon() const;
    private:
        char mUniqueId[33];  // offset: 0x8
        char mNickname[81];  // offset: 0x29
        char mIcon[257];  // offset: 0x7a
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cContentInviteUserInfo : public ::MtObject
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
        cContentInviteUserInfo();
        cContentInviteUserInfo(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR content_id, MT_CTSTR message, s8 alive, MT_CTSTR create_at);
        MT_CTSTR getUniqueId() const;
        MT_CTSTR getNickname() const;
        MT_CTSTR getIcon() const;
        MT_CTSTR getContentId() const;
        MT_CTSTR getMessage() const;
        s8 getAlive() const;
        MT_CTSTR getCreateAt() const;
    private:
        char mUniqueId[33];  // offset: 0x8
        char mNickname[81];  // offset: 0x29
        char mIcon[257];  // offset: 0x7a
        char mContentId[33];  // offset: 0x17b
        char mMessage[513];  // offset: 0x19c
        s8 mAlive;  // offset: 0x39d
        char mCreateAt[21];  // offset: 0x39e
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cContentTagInfo : public ::MtObject
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
        cContentTagInfo();
        cContentTagInfo(MT_CTSTR unique_id, s32 tag_id, MT_CTSTR character_name, s8 online, s8 visible, MT_CTSTR update_at);
        MT_CTSTR getUniqueId() const;
        s32 getTagId() const;
        MT_CTSTR getCharacterName() const;
        s8 getOnline() const;
        s8 getVisible() const;
        MT_CTSTR getUpdateAt() const;
    private:
        char mUniqueId[33];  // offset: 0x8
        s32 mTagId;  // offset: 0x2c
        char mCharacterName[513];  // offset: 0x30
        s8 mOnline;  // offset: 0x231
        s8 mVisible;  // offset: 0x232
        char mUpdateAt[21];  // offset: 0x233
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cFreeTagInfo : public ::MtObject
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
        cFreeTagInfo();
        cFreeTagInfo(MT_CTSTR unique_id, s32 tag_id, s8 alive, MT_CTSTR update_at);
        MT_CTSTR getUniqueId() const;
        s32 getTagId() const;
        s8 getAlive() const;
        MT_CTSTR getUpdateAt() const;
    private:
        char mUniqueId[33];  // offset: 0x8
        s32 mTagId;  // offset: 0x2c
        s8 mAlive;  // offset: 0x30
        char mUpdateAt[21];  // offset: 0x31
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cFriendEntryInfo : public ::MtObject
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
        cFriendEntryInfo();
        cFriendEntryInfo(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR message, s32 status, MT_CTSTR request_at, MT_CTSTR update_at);
        MT_CTSTR getUniqueId() const;
        MT_CTSTR getNickname() const;
        MT_CTSTR getIcon() const;
        MT_CTSTR getMessage() const;
        s32 getStatus() const;
        MT_CTSTR getRequestAt() const;
        MT_CTSTR getUpdateAt() const;
    private:
        char mUniqueId[33];  // offset: 0x8
        char mNickname[81];  // offset: 0x29
        char mIcon[257];  // offset: 0x7a
        char mMessage[513];  // offset: 0x17b
        s32 mStatus;  // offset: 0x37c
        char mRequestAt[21];  // offset: 0x380
        char mUpdatedAt[21];  // offset: 0x395
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cNotifyAppInfo : public ::MtObject
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
        cNotifyAppInfo();
        cNotifyAppInfo(s32 notify_id, MT_CTSTR content_id, MT_CTSTR message, MT_CTSTR param, MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, s32 notify_type, s32 view_type, MT_CTSTR update_at);
        s32 getNotifyId() const;
        MT_CTSTR getContentId() const;
        MT_CTSTR getMessage() const;
        MT_CTSTR getParam() const;
        MT_CTSTR getUniqueId() const;
        MT_CTSTR getNickname() const;
        MT_CTSTR getIcon() const;
        s32 getNotifyType() const;
        s32 getViewType() const;
        MT_CTSTR getUpdatedAt() const;
    private:
        s32 mNotifyId;  // offset: 0x8
        char mContentId[33];  // offset: 0xc
        char mMessage[513];  // offset: 0x2d
        char mParam[513];  // offset: 0x22e
        char mUniqueId[33];  // offset: 0x42f
        char mNickname[81];  // offset: 0x450
        char mIcon[257];  // offset: 0x4a1
        s32 mNotifyType;  // offset: 0x5a4
        s32 mViewType;  // offset: 0x5a8
        char mUpdatedAt[21];  // offset: 0x5ac
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cResourceInfo : public ::MtObject
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
        cResourceInfo();
        cResourceInfo(s32 resource_id, s32 resource_category_id, s8 resource_tye, MT_CTSTR resource_tag, MT_CTSTR resource_url, s8 alive);
        s32 getResourceId() const;
        s32 getResourceCategoryId() const;
        s8 getResourceType() const;
        MT_CTSTR getResourceTag() const;
        MT_CTSTR getResourceUrl() const;
        s8 getAlive() const;
    private:
        s32 mResourceId;  // offset: 0x8
        s32 mResourceCategoryId;  // offset: 0xc
        s8 mResourceType;  // offset: 0x10
        char mResourceTag[81];  // offset: 0x11
        char mResourceUrl[257];  // offset: 0x62
        s8 mAlive;  // offset: 0x163
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cTagInfo : public ::MtObject
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
        cTagInfo();
        cTagInfo(s32 tag_id, MT_CTSTR tag_name);
        s32 getTagId() const;
        MT_CTSTR getTagName() const;
    private:
        s32 mTagId;  // offset: 0x8
        char mTagName[81];  // offset: 0xc
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cUserBaseInfo : public ::MtObject
    {
        friend class ::uGUICaplinkProfile;
        friend class ::uGUICaplinkTalk;
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
        cUserBaseInfo();
        cUserBaseInfo(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR icon_s);
        MT_CTSTR getUniqueId() const;
        MT_CTSTR getNickname() const;
        MT_CTSTR getIconNormalUrl() const;
        MT_CTSTR getIconSmallUrl() const;
    protected:
        char mUniqueId[33];  // offset: 0x8
        char mNickname[81];  // offset: 0x29
        char mIconNormalUrl[257];  // offset: 0x7a
        char mIconSmallUrl[257];  // offset: 0x17b
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cUserContentInfo : public ::MtObject
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
        cUserContentInfo();
        cUserContentInfo(MT_CTSTR content_id, MT_CTSTR character_name, s8 online, MT_CTSTR comment, s8 online_privacy, s8 visible);
        MT_CTSTR getContentId() const;
        MT_CTSTR getCharacterName() const;
        s8 getOnline() const;
        MT_CTSTR getComment() const;
        s8 getOnlinePrivacy() const;
        s8 getVisible() const;
    private:
        char mContentId[33];  // offset: 0x8
        char mCharacterName[513];  // offset: 0x29
        s8 mOnline;  // offset: 0x22a
        char mComment[513];  // offset: 0x22b
        s8 mOnlinePrivacy;  // offset: 0x42c
        s8 mVisible;  // offset: 0x42d
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cUserProfile : public nCaplink::cUserBaseInfo
    {
        friend class ::uGUICaplinkProfile;
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
        cUserProfile();
        cUserProfile(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR icon_s, MT_CTSTR comment, s32 timeline_skin_id, MT_CTSTR timeline_skin_url, s32 profile_skin_id, MT_CTSTR profile_skin_url, s32 content_total, s8 timeline_privacy, s8 profile_privacy, s8 captalk_privacy, s8 find_srearch, s32 friends_total, s32 tags_total, s32 friend_tags_total, s32 ignores_total);
        MT_CTSTR getComment() const;
        s32 getTimelineSkinId() const;
        MT_CTSTR getTimelineSkinUrl() const;
        s32 getProfileSkinId() const;
        MT_CTSTR getProfileSkinUrl() const;
        s32 getContentTotal() const;
        s8 getTimelinePrivacy() const;
        s8 getProfilePrivacy() const;
        s8 getCaptalkPrivacy() const;
        s8 getFindSearch() const;
        s32 getFriendsTotal() const;
        s32 getTagsTotal() const;
        s32 getFriendTagsTotal() const;
        s32 getIgnoresTotal() const;
    private:
        char mComment[513];  // offset: 0x27c
        s32 mTimelineSkinId;  // offset: 0x480
        char mTimelineSkinUrl[257];  // offset: 0x484
        s32 mProfileSkinId;  // offset: 0x588
        char mProfileSkinUrl[257];  // offset: 0x58c
        s32 mContentTotal;  // offset: 0x690
        s8 mTimelinePrivacy;  // offset: 0x694
        s8 mProfilePrivacy;  // offset: 0x695
        s8 mCaptalkPrivacy;  // offset: 0x696
        s8 mFindSearch;  // offset: 0x697
        s32 mFriendsTotal;  // offset: 0x698
        s32 mTagsTotal;  // offset: 0x69c
        s32 mFriendTagsTotal;  // offset: 0x6a0
        s32 mIgnoresTotal;  // offset: 0x6a4
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cWebsocketServerInfo : public ::MtObject
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
        cWebsocketServerInfo();
        cWebsocketServerInfo(MT_CTSTR host_name, s32 port, MT_CTSTR path, s32 loadaverage, s32 connections, MT_CTSTR last_life_datetime);
        MT_CTSTR getHostname() const;
        s32 getPort() const;
        MT_CTSTR getPath() const;
        s32 getLoadaverage() const;
        s32 getConnections() const;
        MT_CTSTR getLastLifeDatetime() const;
    private:
        char mHostname[128];  // offset: 0x8
        s32 mPort;  // offset: 0x88
        char mPath[128];  // offset: 0x8c
        s32 mLoadaverage;  // offset: 0x10c
        s32 mConnections;  // offset: 0x110
        char mLastLifeDatetime[21];  // offset: 0x114
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cAchievementRelationInfo : public ::MtObject
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
        cAchievementRelationInfo();
        void addRewardData(nCaplink::cAchievementRewardInfo* pAddInfo);
        void setContentId(MT_CTSTR content_id);
        void setContentFullName(MT_CTSTR content_name);
        void setAchievementDetail(MT_CTSTR achievement_detail);
        void setAchievementText(MT_CTSTR achievement_text);
        void setIconUrl(MT_CTSTR icon_url);
        void setStartAt(MT_CTSTR start_at);
        void setEndAt(MT_CTSTR end_at);
        void setRewardName(MT_CTSTR reward_name);
        void setRewardDetail(MT_CTSTR reward_detail);
        void setAchievementId(s32 achievement_id);
        void setExtended(s8 extended);
        void setExtendedCount(s8 extended_count);
        void setCategory(s8 category);
        void setAlive(s8 alive);
        void setDifficulty(s8 difficulty);
        void setIndefinite(s8 indefinite);
        void setRewardCount(s8 reward_count);
        void setBit(s8 bit);
        void setAchievementCount(s8 achievement_count);
        const MtTypedArray<nCaplink::cAchievementRewardInfo>& getRewardData() const;
        MT_CTSTR getContentId() const;
        MT_CTSTR getContentFullName() const;
        MT_CTSTR getAchievementDetail() const;
        MT_CTSTR getAchievementText() const;
        MT_CTSTR getIconUrl() const;
        MT_CTSTR getStartAt() const;
        MT_CTSTR getEndAt() const;
        MT_CTSTR getRewardName() const;
        MT_CTSTR getRewardDetail() const;
        s32 getAchievementId() const;
        s8 getExtended() const;
        s8 getExtendedCount() const;
        s8 getCategory() const;
        s8 getAlive() const;
        s8 getDifficulty() const;
        s8 getIndefinite() const;
        s8 getRewardCount() const;
        s8 getBit() const;
        s8 getAchievementCount() const;
    private:
        MtTypedArray<nCaplink::cAchievementRewardInfo> mRewardData;  // offset: 0x8
        char mContentId[33];  // offset: 0x28
        char mContentFullName[257];  // offset: 0x49
        char mAchievementDetail[257];  // offset: 0x14a
        char mAchievementText[513];  // offset: 0x24b
        char mIconUrl[257];  // offset: 0x44c
        char mStartAt[21];  // offset: 0x54d
        char mEndAt[21];  // offset: 0x562
        char mRewardName[257];  // offset: 0x577
        char mRewardDetail[513];  // offset: 0x678
        s32 mAchievementId;  // offset: 0x87c
        s8 mExtended;  // offset: 0x880
        s8 mExtendedCount;  // offset: 0x881
        s8 mCategory;  // offset: 0x882
        s8 mAlive;  // offset: 0x883
        s8 mDifficulty;  // offset: 0x884
        s8 mIndefinite;  // offset: 0x885
        s8 mRewardCount;  // offset: 0x886
        s8 mBit;  // offset: 0x887
        s8 mAchievementCount;  // offset: 0x888
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cFriendInfo : public nCaplink::cUserBaseInfo
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
        cFriendInfo();
        cFriendInfo(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR labelname, MT_CTSTR memo, MT_CTSTR icon, MT_CTSTR comment, MT_CTSTR accordat, MT_CTSTR updateat, s8 privacy, s8 attribute, s8 alive);
        MT_CTSTR getLabelname() const;
        MT_CTSTR getMemo() const;
        MT_CTSTR getComment() const;
        MT_CTSTR getAccordAt() const;
        MT_CTSTR getUpdateAt() const;
        s8 getPrivacy() const;
        s8 getAttribute() const;
        s8 getAlive() const;
    private:
        char mLabelname[257];  // offset: 0x27c
        char mMemo[513];  // offset: 0x37d
        char mComment[513];  // offset: 0x57e
        char mAccordAt[21];  // offset: 0x77f
        char mUpdatedAt[21];  // offset: 0x794
        s8 mPrivacy;  // offset: 0x7a9
        s8 mAttribute;  // offset: 0x7aa
        s8 mAlive;  // offset: 0x7ab
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

namespace nCaplink {
    class cIgnoreUserInfo : public nCaplink::cUserBaseInfo
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
        cIgnoreUserInfo();
        cIgnoreUserInfo(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR message, MT_CTSTR ignore_at);
        MT_CTSTR getMessage() const;
        MT_CTSTR getIgnoreAt() const;
    private:
        char mMessage[513];  // offset: 0x27c
        char mIgnoreAt[21];  // offset: 0x47d
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::cAchievementExtendedInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cAchievementListInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cAchievementRelationInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cAchievementRewardInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cChatGroupInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cChatUserInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cContentInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cContentInviteAvailableUserInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cContentInviteUserInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cContentTagInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cFreeTagInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline s32 nCaplink::cFreeTagInfo::getTagId() const {
    return this->mTagId;
}

inline void* nCaplink::cFriendEntryInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cFriendInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cIgnoreUserInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cNotifyAppInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline s32 nCaplink::cNotifyAppInfo::getNotifyId() const {
    return this->mNotifyId;
}

inline s32 nCaplink::cNotifyAppInfo::getNotifyType() const {
    return this->mNotifyType;
}

inline void* nCaplink::cResourceInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline s32 nCaplink::cResourceInfo::getResourceId() const {
    return this->mResourceId;
}

inline s32 nCaplink::cResourceInfo::getResourceCategoryId() const {
    return this->mResourceCategoryId;
}

inline s8 nCaplink::cResourceInfo::getResourceType() const {
    return this->mResourceType;
}

inline void* nCaplink::cTagInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cUserBaseInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cUserContentInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cUserProfile::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nCaplink::cWebsocketServerInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline MT_CTSTR nCaplink::cWebsocketServerInfo::getHostname() const {
    return &this->mHostname[0];
}

inline s32 nCaplink::cWebsocketServerInfo::getPort() const {
    return this->mPort;
}

inline MT_CTSTR nCaplink::cWebsocketServerInfo::getPath() const {
    return &this->mPath[0];
}

inline s32 nCaplink::cWebsocketServerInfo::getLoadaverage() const {
    return this->mLoadaverage;
}

inline s32 nCaplink::cWebsocketServerInfo::getConnections() const {
    return this->mConnections;
}
