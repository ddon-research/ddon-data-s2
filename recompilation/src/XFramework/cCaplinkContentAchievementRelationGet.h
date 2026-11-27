#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtString.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
namespace nCaplink { class cAchievementRelationInfo; }
namespace nCaplink { class cAchievementRewardInfo; }

// Declarations
namespace nCaplink { class ContentAchievementRelationGetAns; }
namespace nCaplink { class ContentAchievementRelationGetReqCtx; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nCaplink {
    class ContentAchievementRelationGetAns : public nCaplink::ContextListener
    {
        friend class nCaplink::ContentAchievementRelationGetReqCtx;
    public:
        ContentAchievementRelationGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setCount(s32 count);
        void addAchievementList(nCaplink::cAchievementRelationInfo* pAddInfo);
        s32 getTotal() const;
        s32 getCount() const;
        const MtTypedArray<nCaplink::cAchievementRelationInfo>& getAchievementList() const;
    private:
        s32 mTotal;  // offset: 0x20
        s32 mCount;  // offset: 0x24
        MtTypedArray<nCaplink::cAchievementRelationInfo> mAchievementList;  // offset: 0x28
    };
}  // namespace nCaplink

namespace nCaplink {
    class ContentAchievementRelationGetReqCtx : public nCaplink::HttpRequestContext
    {
    public:
        class MyDTI;
        class JsonParser;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class JsonParser : public MtJsonReader::Handler
        {
        public:
            enum
            {
                CODE = 0,
                DETAIL_MESSAGE = 1,
                TOTAL = 2,
                COUNT = 3,
                CONTENT_ID = 4,
                CONTENT_FULLNAME = 5,
                ACHIEVEMENT_ID = 6,
                ACHIEVEMENT_DETAIL = 7,
                ACHIEVEMENT_TEXT = 8,
                EXTENDED = 9,
                EXTENDED_COUNT = 10,
                CATEGORY = 11,
                ALIVE = 12,
                DIFFICULTY = 13,
                ICON_URL = 14,
                INDEFINITE_FLAG = 15,
                START_AT = 16,
                END_AT = 17,
                REWARD_NAME = 18,
                REWARD_DETAIL = 19,
                REWARD_COUNT = 20,
                BIT = 21,
                ACHIEVEMENT_COUNT = 22,
                TYPE = 23,
                ID = 24,
                AMOUNT = 25,
                NAME_NUM = 26,
            };
        public:
            JsonParser();
            virtual ~JsonParser();
            void setParent(nCaplink::ContentAchievementRelationGetReqCtx* parent);
            virtual void beginArray();  // vtable slot 2
            virtual void endArray();  // vtable slot 3
            virtual void beginObject();  // vtable slot 4
            virtual void endObject();  // vtable slot 5
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            u32 mFieldName;  // offset: 0xc
            bool mbRelationArray;  // offset: 0x10
            bool mbRewardArray;  // offset: 0x11
            nCaplink::ContentAchievementRelationGetReqCtx* mpParent;  // offset: 0x18
            nCaplink::ContentAchievementRelationGetAns* mpListener;  // offset: 0x20
            nCaplink::cAchievementRelationInfo* mpRelationInfo;  // offset: 0x28
            nCaplink::cAchievementRewardInfo* mpRewardInfo;  // offset: 0x30
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
        ContentAchievementRelationGetReqCtx();
        ContentAchievementRelationGetReqCtx(MT_CTSTR filtering_content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
    private:
        MtString mFilteringContentId;  // offset: 0x68
        s32 mCategory;  // offset: 0x70
        s32 mAlive;  // offset: 0x74
        s32 mOrderby;  // offset: 0x78
        s32 mOffset;  // offset: 0x7c
        s32 mCount;  // offset: 0x80
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::ContentAchievementRelationGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::ContentAchievementRelationGetReqCtx::ContentAchievementRelationGetReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::ContentAchievementRelationGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ContentAchievementRelationGetReqCtx::DTI)->memFree(p_addr);
}
