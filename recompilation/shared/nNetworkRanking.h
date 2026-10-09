#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetObject.h"
#include "MtNetRanking.h"
#include "cStateMachine.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtNetError;
class MtNetRanking;
class MtNetUniqueId;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
namespace nNetwork { namespace nRanking { class Listener; } }
namespace nNetwork { namespace nRanking { class Object; } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    namespace nRanking {
        class Listener
        {
        public:
            virtual ~Listener() {}
            virtual void onFinalize();  // vtable slot 2
            virtual void onDrop(MtNetError*);  // vtable slot 3
            virtual void onUploadComplete(MtNetError*);  // vtable slot 4
            virtual void onGetScoreComplete(MtNetRanking::ScoreList*, MtNetError*);  // vtable slot 5
            virtual void onGetAttachComplete(MtNetRanking::Attach*, MtNetError*);  // vtable slot 6
        };
    }  // namespace nRanking
}  // namespace nNetwork

namespace nNetwork {
    namespace nRanking {
        class Object : public ::MtNetObject, public ::TStateMachine<nNetwork::nRanking::Object>
        {
        public:
            enum
            {
                STATE_DEAD = 0,
                STATE_WAIT = 1,
                STATE_UPLOAD = 2,
                STATE_RANGE = 3,
                STATE_UNIQ_ID = 4,
                STATE_FRIEND_LIST = 5,
                STATE_ATTACH = 6,
            };
        public:
            class MyDTI;
            class DriverListener;
            class StateBase;
        public:
            class MyDTI : public ::MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
            };
        public:
            class DriverListener : public MtNetRanking::Listener
            {
            public:
                DriverListener();
                // Address: 0x01bd83b0 - 0x01bd83b1 (1 bytes)
                virtual ~DriverListener() {}
                virtual void onNtcDestruct();  // vtable slot 2
                virtual void onNtcFinalize();  // vtable slot 3
                virtual void onNtcDrop(MtNetError* err);  // vtable slot 4
                virtual void onAnsUpdateSucceed(u32 req_seq);  // vtable slot 5
                virtual void onAnsUpdateFail(u32 req_seq, MtNetError* err);  // vtable slot 6
                virtual void onAnsGetScoreListSucceed(u32 req_seq, MtNetRanking::ScoreList* plist);  // vtable slot 7
                virtual void onAnsGetScoreListFail(u32 req_seq, MtNetError* err);  // vtable slot 8
                virtual void onAnsGetAttachSucceed(u32 req_seq, MtNetRanking::Attach* pattach);  // vtable slot 9
                virtual void onAnsGetAttachFail(u32 req_seq, MtNetError* err);  // vtable slot 10
                void setParent(nNetwork::nRanking::Object* pParent);
            private:
                nNetwork::nRanking::Object* mpParent;  // offset: 0x8
            };
        public:
            class StateBase : public TStateMachine<nNetwork::nRanking::Object>::TState
            {
            public:
                enum
                {
                    STATE_GET = 0,
                    STATE_GET_WAIT = 1,
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
                u32 getRequestSeq();
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
                MtNetRanking* getDriver();
                void setState(u32 state);
            public:
                u32 mRequestSeq;  // offset: 0x40
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
            Object();
            virtual ~Object();
            void setup();
            void move();
            void sync();
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            bool init();
            bool init(u32 user_index);
            void initForProperty();
            void kill();
            bool isInit();
            u32 getUserIndex() const;
            virtual void clearFatal();  // vtable slot 8
            virtual void setFatal(const MtNetError* err);  // vtable slot 9
            virtual void setFatal(s32 no, s32 cause, s32 native);  // vtable slot 10
            void notifyUploadFaild();
            bool upload(MtNetRanking::Updater* pUpdaterTbl, s32 size);
            bool getScoreByRange(u32 boardId, u32 top, u32 offset);
            bool getScoreByUniqId(u32 boardId, MtNetUniqueId* pUniqIdTbl, s32 size);
            bool getScoreByFriendList(u32 boardId, bool self, u32 offset, u32 max_num);
            bool getAttach(u32 boardId, MtNetUniqueId* pUniqId, void* pBuf, s32 buf_size);
            bool abortRequest();
            MtNetRanking::ScoreList* getScoreList();
            bool addListener(nNetwork::nRanking::Listener* p);
            void removeListener(nNetwork::nRanking::Listener* p);
            s32 getState();
            void setCurrentState(s32 state);
        private:
            void createDriver();
            void removeDriver();
            void onFinalize();
            void onDrop(MtNetError* err);
            void onUploadComplete(MtNetError* err);
            void onGetScoreComplete(MtNetRanking::ScoreList* plist, MtNetError* err);
            void onGetAttachComplete(MtNetRanking::Attach* pattach, MtNetError* err);
        private:
            MtNetRanking* mpDriver;  // offset: 0x48c8
            DriverListener mDriveListener;  // offset: 0x48d0
            u32 mUserIndex;  // offset: 0x48e0
            s32 mState;  // offset: 0x48e4
            s32 mListenerNum;  // offset: 0x48e8
            nNetwork::nRanking::Listener* mpListener[16];  // offset: 0x48f0
            bool mListenerUse[16];  // offset: 0x4970
            bool mbFinal;  // offset: 0x4980
        public:
            static const s32 MAX_NUM_LISTENER = 16;
            static const s32 MAX_NUM_FRIEND = 2000;
            static MyDTI DTI;
        };
    }  // namespace nRanking
}  // namespace nNetwork
