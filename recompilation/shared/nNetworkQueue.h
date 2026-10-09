#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;

// Declarations
namespace nNetwork { class BlockBuffer; }
namespace nNetwork { class BlockPool; }
namespace nNetwork { class BlockQueue; }
namespace nNetwork { template <typename T, unsigned int MAX_BLOCK> class TransportQueue; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    class BlockBuffer : public ::MtObject
    {
        // inferred: nNetwork::BlockQueue::clear names nNetwork::BlockBuffer::mHead
        friend class nNetwork::BlockQueue;
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
        BlockBuffer();
        virtual ~BlockBuffer();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void init(nNetwork::BlockPool* pool, u32 block_max, void* * block_list);
        bool isInit() const;
        bool push(const void* data_ptr, u32 data_size);
        bool shift(void* data_ptr, u32 data_size);
        u32 length() const;
        bool empty() const;
        u32 head() const;
        u32 tail() const;
        bool adjust(u32 data_size);
        void clear();
    protected:
        void write(const void* data_ptr, u32 data_size, u32 seek);
        void read(void* data_ptr, u32 data_size, u32 seek) const;
        void read(MtStream& stream, u32 data_size, u32 seek) const;
    private:
        nNetwork::BlockPool* mpPool;  // offset: 0x8
        void* * mBlockList;  // offset: 0x10
        u32 mBlockMax;  // offset: 0x18
        u32 mBlockHead;  // offset: 0x1c
        u32 mBlockTail;  // offset: 0x20
        u32 mHead;  // offset: 0x24
        u32 mTail;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class BlockPool : public ::MtObject
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
        BlockPool();
        virtual ~BlockPool();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void init(void* pool_ptr, u32 pool_size);
        void init(MtAllocator* alloc, u32 pool_size);
        bool isInit() const;
        void final();
        void* allocate();
        void free(void* pblock);
        u32 avail() const;
    private:
        void* mpPool;  // offset: 0x8
        void* mpBlock;  // offset: 0x10
        u32 mPoolSize;  // offset: 0x18
        u32 mPoolCount;  // offset: 0x1c
        u32 mHead;  // offset: 0x20
        u32 mTail;  // offset: 0x24
        bool mAutoFree;  // offset: 0x28
        MtAllocator* mpPoolAllocator;  // offset: 0x30
        MtCriticalSection mCSAlloc;  // offset: 0x38
        MtCriticalSection mCSFree;  // offset: 0x40
    public:
        static MyDTI DTI;
        static const u32 BLOCK_SIZE = 1024;
        static const u32 BLOCK_ALIGN = 16;
    };
}  // namespace nNetwork

namespace nNetwork {
    class BlockQueue : public nNetwork::BlockBuffer
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
        BlockQueue();
        virtual ~BlockQueue();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool push(const void* data_ptr, u32 data_size);
        bool shift(void* data_ptr, u32& data_size);
        bool shift();
        u32 count() const;
        s32 seek(u32 index);
        bool peek(void* data_ptr, u32& data_size) const;
        bool peek(MtStream& stream) const;
        bool overwrite(const void* data_ptr, u32& data_size);
        void setSeek(u32);
        u32 getSeek() const;
        bool adjust(u32 total, u32 num);
        void clear();
    private:
        s32 mCount;  // offset: 0x2c
        s32 mIndex;  // offset: 0x30
        u32 mSeek;  // offset: 0x34
        s32 mSeekLength;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    // Layout verified against DWARF for TransportQueue<nNetwork::Callback::Header, 32>, TransportQueue<nNetwork::Callback::SelfHeader, 32>
    template <typename T, unsigned int MAX_BLOCK>
    class TransportQueue : public nNetwork::BlockQueue
    {
    public:
        void init(nNetwork::BlockPool* pool);
        bool push(const void* data_ptr, u32 data_size, const T& header);
        bool shift(void* data_ptr, u32& data_size, T& header);
        bool shift();
        bool seek(u32 index, T& header, u32& data_size);
        bool peek(u32 index, void* data_ptr, u32& data_size);
    private:
        void* mBlockList[32];  // offset: 0x40
    };
}  // namespace nNetwork
