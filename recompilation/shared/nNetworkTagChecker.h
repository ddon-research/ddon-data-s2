#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetSession.h"
#include "MtObject.h"
#include "cRemoteCall.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtStream;
class MtString;
class cRemoteCall;
namespace nNetwork { class Session; }

// Declarations
namespace nNetwork { class TagChecker; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    class TagChecker : public ::MtObject
    {
    public:
        enum
        {
            CHECK_RESULT_UP_TO_DATE = 0,
            CHECK_RESULT_OUT_OF_DATE = 1,
            CHECK_RESULT_INCOMPLETE = 2,
            CHECK_RESULT_NOT_FOUND = 3,
        };
    public:
        class MyDTI;
        struct Record;
        class RpcSyncReq;
        class RpcSyncAns;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct Record
        {
        public:
            void clear();
            void clear(s32 member_index);
            bool isValid() const;
            bool isComp() const;
            bool isSync() const;
        public:
            s32 mMemberIndex;  // offset: 0x0
            u32 mMemberId;  // offset: 0x4
            u32 mLocal;  // offset: 0x8
            u32 mOther;  // offset: 0xc
            u32 mCheckList;  // offset: 0x10
            u32 mOtherList;  // offset: 0x14
        };
    public:
        class RpcSyncReq : public ::cRemoteCall
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
            RpcSyncReq();
            virtual void serialize(MtStream& stream);  // vtable slot 6
            virtual void deserialize(MtStream& stream);  // vtable slot 7
        public:
            s32 mMemberIndex;  // offset: 0xc
            u32 mMemberId;  // offset: 0x10
            u32 mTag;  // offset: 0x14
            static MyDTI DTI;
        };
    public:
        class RpcSyncAns : public nNetwork::TagChecker::RpcSyncReq
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
        public:
            static MyDTI DTI;
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
        TagChecker();
        virtual ~TagChecker();
        void setup(nNetwork::Session* session);
        void init();
        void final();
        bool isInit() const;
        s32 check(s32 member_index, u32 generation) const;
        s32 check(u32 member_id) const;
        u32 getLocalTag(s32 member_index, u32 generation) const;
        u32 getLocalTag(u32 member_id) const;
        u32 getOtherTag(s32 member_index, u32 generation) const;
        u32 getOtherTag(u32 member_id) const;
        void setDst(s32);
        s32 getDst() const;
        void onLeaveMember(s32 member_index, MtNetSession::Member* member);
        void process(s32 src, cRemoteCall* prpc);
        void dbgGetSummary(MtString& sum) const;
    private:
        void procSyncReq(RpcSyncReq& call, s32 member_index);
        void procSyncAns(RpcSyncAns& call, s32 member_index);
        Record* addRecord(s32 member_index, u32 member_id, u32 tag);
        const Record* findRecord(s32 member_index, u32 generation) const;
        const Record* findRecord(u32 member_id) const;
        Record* findRecord(u32 member_id);
    private:
        bool mInit;  // offset: 0x8
        s32 mDst;  // offset: 0xc
        u32 mTail;  // offset: 0x10
        nNetwork::Session* mpSession;  // offset: 0x18
        Record* mpRecordList;  // offset: 0x20
        u32 mRecordSize;  // offset: 0x28
        u32 mRequestList[16];  // offset: 0x2c
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork
