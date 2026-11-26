#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtObject.h"
#include "nNetworkQueue.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
namespace nNetwork { class Decoder; }
namespace nNetwork { class PacketReader; }
namespace nNetwork { class PacketWriter; }
namespace nNetwork { class Route; }
namespace nNetwork { class Session; }

// Declarations
namespace nNetwork { class Protocol; }
namespace nNetwork { class ProtocolStandard; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetwork {
    class Protocol : public ::MtObject
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
        Protocol(MT_CTSTR name, bool system, bool broadcast);
        virtual ~Protocol() {}
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
        virtual void setup(nNetwork::Session* ps);  // vtable slot 6
        virtual void move();  // vtable slot 7
        virtual void create(s32 index);  // vtable slot 8
        virtual void remove(s32 index);  // vtable slot 9
        virtual bool put(const void*, u32, s32, u32, u32, s32) = 0;  // vtable slot 10
        virtual bool get(s32, nNetwork::PacketWriter&, u32, const nNetwork::Route*) = 0;  // vtable slot 11
        virtual void receive(s32, nNetwork::PacketReader&) = 0;  // vtable slot 12
        virtual void dbgGetSummary(s32 index, MtString& sum);  // vtable slot 13
        bool isSystem() const;
        bool isBroadcast() const;
    protected:
        u32 getRpc(const void* data_ptr, u32 param) const;
        void recTag(s32 route_index, u32 tag);
        void recRtt(s32 route_index, u32 rtt);
        void recQueueDelay(s32 route_index, u32 delay);
        void process(u32 callback, s32 index, const void* data_ptr, u32 data_size);
    protected:
        bool mSystem;  // offset: 0x8
        bool mBroadcast;  // offset: 0x9
        nNetwork::Session* mpSession;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class ProtocolStandard : public nNetwork::Protocol
    {
    public:
        class MyDTI;
        class Queue;
        struct QHeader;
        class Buffer;
        struct FHeader;
        struct UHeader;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct QHeader
        {
        public:
            u8 mFlag;  // offset: 0x0
            u8 mCtrl;  // offset: 0x1
            u8 mPrio;  // offset: 0x2
            u8 mSend;  // offset: 0x3
            u16 mGetElapse;  // offset: 0x4
            u16 m1stElapse;  // offset: 0x6
            u32 mPutTime;  // offset: 0x8
        };
    public:
        class Buffer
        {
        public:
            Buffer();
            ~Buffer();
            void clear();
            void write(nNetwork::Decoder* pdec, u32 data_size, u16 seq);
            const void* getBuffer() const;
            u32 getLength() const;
        public:
            bool mFatal;  // offset: 0x0
            u16 mSequence;  // offset: 0x2
            u8* mpBlock;  // offset: 0x8
            u8* mpExtra;  // offset: 0x10
            u32 mLength;  // offset: 0x18
            u32 mTag;  // offset: 0x1c
        };
    public:
        struct FHeader
        {
        public:
            u16 seq;  // offset: 0x0
            u16 ack;  // offset: 0x2
            u8 idle;  // offset: 0x4
            u8 unit;  // offset: 0x5
        };
    public:
        struct UHeader
        {
        public:
            u8 flag;  // offset: 0x0
            u8 length;  // offset: 0x1
        };
    public:
        class Queue : public nNetwork::TransportQueue<nNetwork::ProtocolStandard::QHeader, 128>
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
            virtual ~Queue() {}
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void move();
            void clear();
            void reset();
            u32 pos(u16 seq) const;
        public:
            u16 mHeadSequence;  // offset: 0x440
            u16 mTailSequence;  // offset: 0x442
            u16 mSendSequence;  // offset: 0x444
            u16 mRecvSequence;  // offset: 0x446
            MtNetTime::Total mAckTime;  // offset: 0x448
            u32 mCutoff;  // offset: 0x450
            u32 mSmoothedSpace;  // offset: 0x454
            u32 mSmoothedUnrel;  // offset: 0x458
            u32 mTotal[16];  // offset: 0x45c
            u32 mCutoffTime;  // offset: 0x49c
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
        ProtocolStandard(MT_CTSTR name, bool system);
        virtual ~ProtocolStandard();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void move();  // vtable slot 7
        virtual void create(s32 index);  // vtable slot 8
        virtual void remove(s32 index);  // vtable slot 9
        virtual bool put(const void* data_ptr, u32 data_size, s32 index, u32 param, u32 callback, s32 tag);  // vtable slot 10
        virtual bool get(s32 index, nNetwork::PacketWriter& packet, u32 target, const nNetwork::Route* route);  // vtable slot 11
        virtual void receive(s32 index, nNetwork::PacketReader& packet);  // vtable slot 12
        virtual void dbgGetSummary(s32 index, MtString& sum);  // vtable slot 13
        void setRedundancy(u32 r);
        u32 getRedundancy() const;
    protected:
        u32 mRedundancy;  // offset: 0x18
        Queue mQueue[16];  // offset: 0x20
        Buffer mBuffer[16];  // offset: 0x4a20
    public:
        static const u32 DATA_SIZE = 16384;
        static MyDTI DTI;
    protected:
        static const u32 SIZE_OF_FHEADER = 6;
        static const u32 SIZE_OF_UHEADER = 2;
        static const u32 UNRELIABLE_NUM = 16;
        static const u32 QUEUE_SIZE = 128;
        static const u32 DEVIDE_THR = 192;
        static const u32 MASK_CALLBACK = 15;
        static const u32 FLAG_RELIABLE = 16;
        static const u32 FLAG_1STSEND = 32;
        static const u32 FLAG_DEVIDE = 64;
        static const u32 FLAG_VOICE = 128;
        static const u32 CTRL_TAG = 255;
        static const u32 CTRL_TOTAL = 254;
    };
}  // namespace nNetwork

inline void* nNetwork::Protocol::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nNetwork::ProtocolStandard::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nNetwork::ProtocolStandard::Queue::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
