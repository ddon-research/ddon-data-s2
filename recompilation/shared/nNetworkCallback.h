#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtObject.h"
#include "MtSynchronize.h"
#include "nNetworkQueue.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nNetwork { class Session; }

// Declarations
namespace nNetwork { class Callback; }
namespace nNetwork { class ReceiverBase; }
namespace nNetwork { template <typename T> class Receiver; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetwork {
    class Callback : public ::MtObject
    {
    public:
        class MyDTI;
        class Entry;
        class Queue;
        struct Header;
        class SelfQueue;
        struct SelfHeader;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Entry : public ::MtObject
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
            Entry();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void clear();
            MtObject* getClass();
            void setClass(MtObject* pobj);
        public:
            nNetwork::ReceiverBase* mpReceiver;  // offset: 0x8
            bool mBuffering;  // offset: 0x10
            bool mRoute;  // offset: 0x11
            static MyDTI DTI;
        };
    public:
        struct Header
        {
        public:
            u8 mCallback;  // offset: 0x0
            s32 mSrcIndex;  // offset: 0x4
        };
    public:
        struct SelfHeader
        {
        public:
            u8 mCallback;  // offset: 0x0
            u32 mSrcIndex;  // offset: 0x4
            MtNetTime::Total mPushTime;  // offset: 0x8
        };
    public:
        class Queue : public nNetwork::TransportQueue<nNetwork::Callback::Header, 32>
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
            Queue();
            virtual ~Queue();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void move();
        public:
            u32 mTotal;  // offset: 0x140
            f32 mRate;  // offset: 0x144
            f32 mCall;  // offset: 0x148
            static MyDTI DTI;
        };
    public:
        class SelfQueue : public nNetwork::TransportQueue<nNetwork::Callback::SelfHeader, 32>
        {
        public:
            bool push(const void* data_ptr, u32 data_size, const nNetwork::Callback::SelfHeader& header);
        public:
            MtCriticalSection mCS;  // offset: 0x140
        };
    public:
        Callback();
        virtual ~Callback();
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
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setup(nNetwork::Session* ps);
        bool receive(u32 callback_index, s32 route_index, s32 member_index, const void* data_ptr, u32 data_size);
        void set(s32 index, nNetwork::ReceiverBase* r, bool buffering, bool route);
        void clear(s32 index);
        void removeRoute(s32 route_index);
        void begin();
        void move();
        void flush();
        void smooth();
        void setBuffering(bool);
        bool isBuffering() const;
        void setSmoothing(bool);
        bool isSmoothing() const;
        void setSelfBuffering(bool);
        bool isSelfBuffering() const;
        void startSelfDelay(u32, u32);
        void stopSelfDelay();
    private:
        bool shift(Queue& queue);
        void callback(u32 callback_index, s32 src_index, const void* data_ptr, u32 data_size);
        void smooth(s32 index);
        void flush(s32 index);
    private:
        bool mBuffering;  // offset: 0x8
        bool mSmoothing;  // offset: 0x9
        bool mSelfBuffering;  // offset: 0xa
        u32 mSelfDelay;  // offset: 0xc
        u32 mSelfBufferSize;  // offset: 0x10
        nNetwork::Session* mpSession;  // offset: 0x18
        Entry mEntry[16];  // offset: 0x20
        Queue mQueue[16];  // offset: 0x1a0
        SelfQueue mSelfQueue;  // offset: 0x16a0
    public:
        static const u32 MAX_NUM_CALLBACK = 16;
        static const u32 BUFFERING_SIZE = 32;
        static const u32 SELF_BUFFER_MIN = 512;
        static const u32 SELF_BUFFER_MAX = 30000;
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class ReceiverBase
    {
    public:
        ReceiverBase();
        virtual ~ReceiverBase() {}
        virtual void receive(s32, const void*, u32) = 0;  // vtable slot 2
        MtObject* getClass();
        s32 getRefCount() const;
    protected:
        MtObject* mpObject;  // offset: 0x8
        s32 mRefCount;  // offset: 0x10
    };
}  // namespace nNetwork

namespace nNetwork {
    template <typename T>
    class Receiver : public nNetwork::ReceiverBase
    {
    public:
        using RECEIVE_CALLBACK = void(T::*)(s32, const void*, u32);
    public:
        void setup(T* object, RECEIVE_CALLBACK callback);
        virtual void receive(s32 src_index, const void* data_ptr, u32 data_size);  // vtable slot 2
        void clear();
    private:
        RECEIVE_CALLBACK mpCallback;  // offset: 0x18
    };
}  // namespace nNetwork
