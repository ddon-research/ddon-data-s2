#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
namespace nCaplink { class cAchievementExtendedInfo; }
namespace nCaplink { class cAchievementListInfo; }
namespace nCaplink { class cAchievementRelationInfo; }
namespace nCaplink { class cAchievementRewardInfo; }
namespace nCaplink { class cUserBaseInfo; }
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
    class cUserBaseInfo : public ::MtObject
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
    class cUserProfile : public nCaplink::cUserBaseInfo
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
