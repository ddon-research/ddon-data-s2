#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
namespace nLayout { class cGameDataCache; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nLayout {
    class cGameDataCache : public ::MtObject
    {
    public:
        enum FLAG_TYPE
        {
            FLAG_FLAG = 0,
            FLAG_QUEST = 1,
            FLAG_DUMMY = 2,
        };
    public:
        class MyDTI;
        struct stFlagData;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stFlagData
        {
        public:
            stFlagData();
            stFlagData(u32 data);
            void setQuest(u32, u32, bool);
            void setFlagCommon(nLayout::cGameDataCache::FLAG_TYPE, bool);
            bool isOn() const;
        public:
            union
            {
            public:
                struct
                {
                public:
                    u32 mType : 4;  // offset: 0x0
                    u32 mOnOff : 1;  // offset: 0x0
                    u32 mFlag_No : 24;  // offset: 0x0
                };  // offset: 0x0
                struct
                {
                public:
                    u32 mType_ : 4;  // offset: 0x0
                    u32 mOnOff_ : 1;  // offset: 0x0
                    u32 mQuest_No : 12;  // offset: 0x0
                    u32 mQF_No : 12;  // offset: 0x0
                };  // offset: 0x0
                u32 mData;  // offset: 0x0
            };  // offset: 0x0
            static const u32 TYPE_BIT_NUM = 4;
            static const u32 ONOFF_BIT_NUM = 1;
            static const u32 PAD_BIT_NUM = 3;
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
        cGameDataCache();
        u32 getNum() const;
        void addQuest(u32, u32, bool);
        void clear();
        u32* getFrontPtr();
        u32 getU32Data(u32 index) const;
        stFlagData getFlagData(u32) const;
        static void setGameData(u32 data, bool isSend);
    private:
        nDDOUtility::cArray<unsigned int, 64> mBuff;  // offset: 0x8
        u32 mNum;  // offset: 0x108
    public:
        static MyDTI DTI;
        static const u32 MAX_CACHE_SIZE = 64;
    };
}  // namespace nLayout
