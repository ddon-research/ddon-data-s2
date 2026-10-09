#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtObject.h"
#include "MtSynchronize.h"
#include "nNetworkCallback.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;

// Declarations
namespace nNetwork { class VoiceChat; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __int32_t = int;
using int32_t = __int32_t;
using SceUserServiceUserId = int32_t;
using SceVoiceQoSConnectionId = int;
using SceVoiceQoSLocalId = int;
using SceVoiceQoSRemoteId = int;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetwork {
    class VoiceChat : public ::MtObject
    {
    public:
        class MyDTI;
        class Talker;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Talker : public ::MtObject
        {
        public:
            enum
            {
                TASK_INIT = 1,
                TASK_FINAL = 2,
                TASK_LOOPBACK = 4,
            };
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
            Talker();
            // Address: 0x01bd8730 - 0x01bd8731 (1 bytes)
            virtual ~Talker() {}
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
            void init();
            void final();
            void loopback();
            bool isInit() const;
            bool isLoopback() const;
            void setDst(s32);
            s32 getDst() const;
        private:
            bool mInit;  // offset: 0x8
            bool mLoopback;  // offset: 0x9
            s32 mDst;  // offset: 0xc
            u32 mTask;  // offset: 0x10
            MtNetTime::Total mUpdateTime;  // offset: 0x18
        public:
            static MyDTI DTI;
        };
    public:
        VoiceChat();
        virtual ~VoiceChat();
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
        void init();
        void move();
        bool isInit();
        Talker* getTalker(u32);
        bool isAutoAdd() const;
        void setAutoAdd(bool);
        bool addVoiceMember(s32 member_index);
        void removeVoiceMember(s32 member_index);
        static bool checkParentalLock(u32 user_index);
        void setProtocol(u32 protocol, u32 priority, bool route);
        void setSessionIndex(u32 index);
        u32 getSessionIndex() const;
        void dbgGetSummary(MtString& sum) const;
        bool isMicAttached() const;
        void setBitrate(s32 bitrate);
        s32 getBitrate();
        void setMicMute(bool f);
        bool isMicMute();
        void setSpeakerVolume(f32 vol);
        f32 getSpeakerVolume();
    private:
        void nativeInit();
        void nativeFinal();
        void nativeProcess(s32 member_index, const void* data_ptr, u32 data_size);
        bool nativeRegisterTalker(u32 talker_index);
        void nativeUnregisterTalker(u32 talker_index);
        bool nativeAddVoiceMember(s32 member_index);
        void nativeRemoveVoiceMember(s32 member_index);
        bool nativeStartLoopback(u32 talker_index);
        void nativeStopLoopback(u32 talker_index);
        void nativeMoveTalker(u32 talker_index, bool update);
        void moveTalker(u32 i, bool update);
        void process(s32 src_index, const void* data_ptr, u32 data_size);
        void putVoiceData(u8* pbuf, u32 len, s32 dst, bool rel);
        void setProtocol(u32 p);
        u32 getProtocol() const;
        void setPriority(u32 p);
        u32 getPriority() const;
    private:
        MtCriticalSection mCS;  // offset: 0x8
        bool mInit;  // offset: 0x10
        bool mRoute;  // offset: 0x11
        bool mAutoAdd;  // offset: 0x12
        bool mRestrict;  // offset: 0x13
        u32 mProtocol;  // offset: 0x14
        u32 mPriority;  // offset: 0x18
        u32 mSessionIndex;  // offset: 0x1c
        Talker mTalker[1];  // offset: 0x20
        u32 mMemberId[16];  // offset: 0x40
        nNetwork::Receiver<nNetwork::VoiceChat> mReceiver;  // offset: 0x80
        SceUserServiceUserId mNativeUserId;  // offset: 0xa8
        bool mMicAttached;  // offset: 0xac
        bool mMicMute;  // offset: 0xad
        s32 mBitrate;  // offset: 0xb0
        f32 mSpeakerVolume;  // offset: 0xb4
        SceVoiceQoSLocalId mLocalId;  // offset: 0xb8
        SceVoiceQoSRemoteId mRemoteId[16];  // offset: 0xbc
        SceVoiceQoSConnectionId mConnectionId[16];  // offset: 0xfc
        MtNetTime::Total mRegLastTime;  // offset: 0x140
        alignas(32) u8 mVoiceMemBlock[262144];  // offset: 0x160
    public:
        static MyDTI DTI;
        static const u32 MAX_NUM_TALKER = 1;
        static const u32 UPDATE_INTERVAL = 100;
    };
}  // namespace nNetwork
