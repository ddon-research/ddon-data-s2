#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetAchievement.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtNetError;
class sNetworkExt;

// Declarations
namespace nNetwork { namespace nAchievement { class Listener; } }
namespace nNetwork { namespace nAchievement { class Object; } }

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

namespace nNetwork {
    namespace nAchievement {
        class Listener
        {
        public:
            virtual ~Listener() {}
            virtual void onInitComplete(u64 option, MtNetError* err);  // vtable slot 2
            virtual void onStartComplete(MtNetError* err);  // vtable slot 3
            virtual void onGetInfoComplete(s32 user_index, s32 id, bool is_award, MtNetError* err);  // vtable slot 4
            virtual void onAwardComplete(s32 user_index, s32 id, MtNetError* err);  // vtable slot 5
            virtual void onGetInfoListResult(s32 user_index, s32 id, bool is_award, MtNetError* err);  // vtable slot 6
            virtual void onGetInfoListComplete(s32 user_index);  // vtable slot 7
            virtual void onAwardListResult(s32 user_index, s32 id, MtNetError* err);  // vtable slot 8
            virtual void onAwardListComplete(s32 user_index);  // vtable slot 9
        };
    }  // namespace nAchievement
}  // namespace nNetwork

namespace nNetwork {
    namespace nAchievement {
        class Object : public ::MtObject, public nNetwork::nAchievement::Listener
        {
            // inferred: sNetworkExt::setTrophyVolume names nNetwork::nAchievement::Object::mState
            friend class ::sNetworkExt;
        public:
            enum
            {
                STATE_SYSTEM_WAIT = 0,
                STATE_COMMAND_WAIT = 1,
                STATE_NUM = 2,
            };
        public:
            class MyDTI;
            class DriverListener;
        public:
            class MyDTI : public ::MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
            };
        public:
            class DriverListener : public MtNetAchievement::Listener
            {
            public:
                virtual void onNtcDestruct();  // vtable slot 2
                virtual void onAnsInitSucceed(u32 req_seq, u64 option);  // vtable slot 3
                virtual void onAnsInitFail(u32 req_seq, MtNetError* net_err);  // vtable slot 4
                virtual void onAnsStartSucceed(u32 req_seq);  // vtable slot 5
                virtual void onAnsStartFail(u32 req_seq, MtNetError* net_err);  // vtable slot 6
                virtual void onAnsGetInfoSucceed(u32 req_seq, s32 user_index, s32 id, bool is_award);  // vtable slot 7
                virtual void onAnsGetInfoFail(u32 req_seq, MtNetError* net_err, s32 user_index, s32 id);  // vtable slot 8
                virtual void onAnsAwardSucceed(u32 req_seq, s32 user_index, s32 id);  // vtable slot 9
                virtual void onAnsAwardFail(u32 req_seq, MtNetError* net_err, s32 user_index, s32 id);  // vtable slot 10
                virtual void onNtcGetInfoListSucceed(s32 user_index, s32 id, bool is_award);  // vtable slot 11
                virtual void onNtcGetInfoListFail(MtNetError* net_err, s32 user_index, s32 id);  // vtable slot 12
                virtual void onAnsGetInfoList(u32 req_seq, s32 user_index);  // vtable slot 13
                virtual void onNtcAwardListSucceed(s32 user_index, s32 id);  // vtable slot 14
                virtual void onNtcAwardListFail(MtNetError* net_err, s32 user_index, s32 id);  // vtable slot 15
                virtual void onAnsAwardList(u32 req_seq, s32 user_index);  // vtable slot 16
                void setParent(nNetwork::nAchievement::Object* pParent);
            private:
                nNetwork::nAchievement::Object* mpParent;  // offset: 0x8
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
            Object();
            virtual ~Object();
            virtual void move();  // vtable slot 6
            void start();
            bool getInfo(s32 user_index, s32 id);
            bool getInfoList(s32 user_index, MtNetAchievement::IdList* list);
            bool award(s32 user_index, s32 id);
            bool awardList(s32 user_index, MtNetAchievement::IdList* list);
            bool setVolume(f32 level);
            bool getInstallProgress(f32* progress);
            s32 getState() const;
            bool addListener(nNetwork::nAchievement::Listener* p);
            void removeListener(nNetwork::nAchievement::Listener* p);
            virtual void onInitComplete(u64 option, MtNetError* err);  // vtable slot 7
            virtual void onStartComplete(MtNetError* err);  // vtable slot 8
            virtual void onGetInfoComplete(s32 user_index, s32 id, bool is_award, MtNetError* err);  // vtable slot 9
            virtual void onAwardComplete(s32 user_index, s32 id, MtNetError* err);  // vtable slot 10
            virtual void onGetInfoListResult(s32 user_index, s32 id, bool is_award, MtNetError* err);  // vtable slot 11
            virtual void onGetInfoListComplete(s32 user_index);  // vtable slot 12
            virtual void onAwardListResult(s32 user_index, s32 id, MtNetError* err);  // vtable slot 13
            virtual void onAwardListComplete(s32 user_index);  // vtable slot 14
        private:
            DriverListener mDriverListener;  // offset: 0x10
            nNetwork::nAchievement::Listener* mpListener[16];  // offset: 0x20
            bool mListenerUse[16];  // offset: 0xa0
            s32 mListenerNum;  // offset: 0xb0
            s32 mState;  // offset: 0xb4
        public:
            static const s32 MAX_NUM_LISTENER = 16;
            static MyDTI DTI;
        };
    }  // namespace nAchievement
}  // namespace nNetwork
