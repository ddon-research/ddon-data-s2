#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetObject.h"
#include "MtNetStorage2.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtNetContext;
struct MtNetError;
class MtNetStorage2;
class MtNetStorageInfo;
class MtNetStorageList;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
namespace nNetwork { class Storage; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    class Storage : public ::MtObject, public MtNetStorage2::Listener
    {
    public:
        enum
        {
            STATE_CLOSED = 0,
            STATE_OPEN = 1,
            STATE_WRITE = 2,
            STATE_READ = 3,
            STATE_LIST = 4,
            STATE_UNLINK = 5,
            STATE_NUM = 6,
        };
    public:
        class MyDTI;
        class Closer;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Closer : public MtNetStorage2::Listener
        {
        private:
            virtual void onAnsFinalize(u32 req_seq);  // vtable slot 11
            virtual void onNtcFinalize();  // vtable slot 3
            virtual void onNtcDrop(MtNetError* net_err);  // vtable slot 4
        public:
            bool mFinal;  // offset: 0x8
            bool mDrop;  // offset: 0x9
            MtNetStorage2* mpStorage;  // offset: 0x10
            MtNetContext* mpContext;  // offset: 0x18
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
        Storage();
        virtual ~Storage();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void move();
        void init(u32 user_index, s32 service, s32 option);
        bool list(MtNetStorageList* list, u32 max_num);
        bool unlink(const MtNetStorageInfo* info);
        bool open(const MtNetStorageInfo* info);
        void close();
        bool read(void* pbuf, s32 size);
        bool write(void* pbuf, s32 size);
        void abort();
        s32 getState() const;
        u32 getDataLength() const;
        bool isError() const;
        void getLastError(MtNetError&) const;
        bool isUnlinkComplete() const;
        bool isListComplete() const;
        bool isReadComplete() const;
        bool isWriteComplete() const;
        bool isCloseComplete() const;
        bool autoFinal(MtNetContext* pcon);
    private:
        void createDriver();
        void removeDriver();
        virtual void onNtcDestruct();  // vtable slot 6
        virtual void onNtcFinalize();  // vtable slot 7
        virtual void onNtcDrop(MtNetError* net_err);  // vtable slot 8
        virtual void onAnsGetListSucceed(u32 req_seq, MtNetStorageList* storage_list);  // vtable slot 9
        virtual void onAnsGetListFail(u32 req_seq, MtNetError* net_err);  // vtable slot 10
        virtual void onAnsUnlinkSucceed(u32 req_seq);  // vtable slot 11
        virtual void onAnsUnlinkFail(u32 req_seq, MtNetError* net_err);  // vtable slot 12
        virtual void onAnsOpenSucceed(u32 req_seq);  // vtable slot 13
        virtual void onAnsOpenFail(u32 req_seq, MtNetError* net_err);  // vtable slot 14
        virtual void onAnsFinalize(u32 req_seq);  // vtable slot 15
        virtual void onAnsWriteSucceed(u32 req_seq);  // vtable slot 16
        virtual void onAnsWriteFail(u32 req_seq, MtNetError* net_err);  // vtable slot 17
        virtual void onAnsReadSucceed(u32 req_seq, s32 data_size);  // vtable slot 18
        virtual void onAnsReadFail(u32 req_seq, MtNetError* net_err);  // vtable slot 19
    private:
        bool mUnlinkComplete;  // offset: 0x10
        bool mListComplete;  // offset: 0x11
        bool mReadComplete;  // offset: 0x12
        bool mWriteComplete;  // offset: 0x13
        bool mCloseComplete;  // offset: 0x14
        bool mDrop;  // offset: 0x15
        bool mFinal;  // offset: 0x16
        bool mClose;  // offset: 0x17
        u32 mUserIndex;  // offset: 0x18
        s32 mService;  // offset: 0x1c
        s32 mOption;  // offset: 0x20
        MtNetContext* mpContext;  // offset: 0x28
        s32 mState;  // offset: 0x30
        u32 mDataLength;  // offset: 0x34
        u32 mReqOpen;  // offset: 0x38
        u32 mReqSeq;  // offset: 0x3c
        MtNetStorage2* mpStorage;  // offset: 0x40
        MtNetStorageList* mpList;  // offset: 0x48
        MtNetError mLastError;  // offset: 0x50
        Closer mCloser[8];  // offset: 0x60
    public:
        static MyDTI DTI;
    private:
        static const u32 FINAL_SIZE = 8;
    };
}  // namespace nNetwork
