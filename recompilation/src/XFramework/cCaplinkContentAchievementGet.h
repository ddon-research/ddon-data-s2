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
namespace nCaplink { class cAchievementExtendedInfo; }

// Declarations
namespace nCaplink { class ContentAchievementGetAns; }
namespace nCaplink { class ContentAchievementGetReqCtx; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nCaplink {
    class ContentAchievementGetAns : public nCaplink::ContextListener
    {
        friend class nCaplink::ContentAchievementGetReqCtx;
    public:
        ContentAchievementGetAns();
        virtual void init();  // vtable slot 6
        void setAchievement(MT_CTSTR achievement);
        void addExtended(nCaplink::cAchievementExtendedInfo* pAddInfo);
        MT_CTSTR getAchievement() const;
        const MtTypedArray<nCaplink::cAchievementExtendedInfo>& getExtended() const;
    private:
        char mAchievement[2732];  // offset: 0x20
        MtTypedArray<nCaplink::cAchievementExtendedInfo> mExtended;  // offset: 0xad0
    };
}  // namespace nCaplink

namespace nCaplink {
    class ContentAchievementGetReqCtx : public nCaplink::HttpRequestContext
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
            JsonParser();
            virtual ~JsonParser();
            void setParent(nCaplink::ContentAchievementGetReqCtx* parent);
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
            bool mbCode;  // offset: 0x9
            bool mbDetailMessage;  // offset: 0xa
            bool mbAchievement;  // offset: 0xb
            bool mbId;  // offset: 0xc
            bool mbCount;  // offset: 0xd
            bool mbArray;  // offset: 0xe
            nCaplink::ContentAchievementGetReqCtx* mpParent;  // offset: 0x10
            nCaplink::ContentAchievementGetAns* mpListener;  // offset: 0x18
            nCaplink::cAchievementExtendedInfo* mpAddInfo;  // offset: 0x20
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
        ContentAchievementGetReqCtx();
        ContentAchievementGetReqCtx(MT_CTSTR content_id);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
    private:
        MtString mContentId;  // offset: 0x68
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::ContentAchievementGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::ContentAchievementGetReqCtx::ContentAchievementGetReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::ContentAchievementGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ContentAchievementGetReqCtx::DTI)->memFree(p_addr);
}
