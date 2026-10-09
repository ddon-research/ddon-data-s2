#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtNetSession.h"
#include "MtObject.h"
#include "MtStlAllocator.h"
#include "MtStlCustom.h"
#include "MtString.h"
#include "nNetworkSessionListener.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMap;
class MtMemoryStream;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
namespace nNetwork { namespace nSharedMemory2 { class CListener; } }
namespace nNetwork { namespace nSharedMemory2 { class CNode; } }
namespace nNetwork { namespace nSharedMemory2 { class CRecord; } }

// Declarations
namespace nNetwork { namespace nSharedMemory2 { class CConsistentHash; } }
namespace nNetwork { namespace nSharedMemory2 { class CProtocol; } }
namespace nNetwork { namespace nSharedMemory2 { class CSessionListener; } }
namespace nNetwork { namespace nSharedMemory2 { class Object; } }
namespace nNetwork { namespace nSharedMemory2 { struct THREAD_INFO; } }

// Type aliases from DWARF
using DWORD = unsigned int;
using HANDLE = void*;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using MT_MFUNC32 = void(MtObject::*)(u32);
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;

namespace nNetwork {
    namespace nSharedMemory2 {
        class CConsistentHash : public ::MtObject
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
            CConsistentHash();
            virtual ~CConsistentHash();
            void init(u32 replica_num);
            void final();
            void add(nNetwork::nSharedMemory2::CNode*);
            void remove(nNetwork::nSharedMemory2::CNode* node);
            void clear();
            nNetwork::nSharedMemory2::CNode* get(MtString str);
            nNetwork::nSharedMemory2::CNode* search(u32 crc);
            size_t size();
        private:
            MtMap mCircle;  // offset: 0x8
            u32 mNumberOfReplicas;  // offset: 0x4820
            bool mInit;  // offset: 0x4824
        public:
            static MyDTI DTI;
        };
    }  // namespace nSharedMemory2
}  // namespace nNetwork

namespace nNetwork {
    namespace nSharedMemory2 {
        class CProtocol : public ::MtObject
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
            CProtocol();
            CProtocol(nNetwork::nSharedMemory2::Object* parent);
            bool init();
            void final();
            void put(char* buff, s32 size, s32 dst_index, bool reliable);
            void get(s32 src_index, const void* data, u32 data_size);
        private:
            nNetwork::nSharedMemory2::Object* mpParent;  // offset: 0x8
            u32 mCallbackIndex;  // offset: 0x10
            bool mInit;  // offset: 0x14
        public:
            static MyDTI DTI;
        };
    }  // namespace nSharedMemory2
}  // namespace nNetwork

namespace nNetwork {
    namespace nSharedMemory2 {
        class CSessionListener : public nNetwork::SessionListener
        {
        public:
            virtual void onLeaveMember(s32 index, MtNetSession::Member* member);  // vtable slot 9
            virtual void onHostMemberChange(s32 index, MtNetSession::Member* member);  // vtable slot 11
            void setParent(nNetwork::nSharedMemory2::Object* parent);
        private:
            nNetwork::nSharedMemory2::Object* mpParent;  // offset: 0x8
        };
    }  // namespace nSharedMemory2
}  // namespace nNetwork

namespace nNetwork {
    namespace nSharedMemory2 {
        struct THREAD_INFO
        {
        public:
            u32 Index;  // offset: 0x0
            MT_MFUNC32 Function;  // offset: 0x8
            DWORD ID;  // offset: 0x18
            HANDLE Handle;  // offset: 0x20
        };
    }  // namespace nSharedMemory2
}  // namespace nNetwork

namespace nNetwork {
    namespace nSharedMemory2 {
        class Object : public ::MtObject
        {
            // inferred: nNetwork::nSharedMemory2::CProtocol::get calls nNetwork::nSharedMemory2::Object::receive
            friend class nNetwork::nSharedMemory2::CProtocol;
        public:
            enum
            {
                MSG_KIND_REQ_LOCK = 0,
                MSG_KIND_REQ_UNLOCK = 1,
                MSG_KIND_REQ_READ = 2,
                MSG_KIND_REQ_WRITE = 3,
                MSG_KIND_REQ_MIRROR = 4,
                MSG_KIND_REQ_SUCCESS = 5,
                MSG_KIND_REQ_FAILD = 6,
                MSG_KIND_RES_READ = 7,
                MSG_KIND_NUM = 8,
            };
            enum
            {
                TYPE_STAR = 0,
                TYPE_MESH = 1,
                TYPE_NUM = 2,
            };
            enum
            {
                LOCK_ATTR_NORMAL = 0,
                LOCK_ATTR_LIGHT = 1,
                LOCK_ATTR_FORCE = 2,
                LOCK_ATTR_NUM = 3,
            };
        public:
            class MyDTI;
            struct ReqLock;
        public:
            class MyDTI : public ::MtDTI
            {
            public:
                MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                virtual MtObject* newInstance() const;  // vtable slot 2
            };
        public:
            struct ReqLock
            {
            public:
                MtString mKey;  // offset: 0x0
                s32 mSrc;  // offset: 0x8
                u32 mReqSeq;  // offset: 0xc
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
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            void move();
            bool init(s32 type);
            void final();
            bool isInit();
            void addListener(nNetwork::nSharedMemory2::CListener*);
            void removeListener(nNetwork::nSharedMemory2::CListener*);
            void addNode(nNetwork::nSharedMemory2::CNode*);
            void removeNode(nNetwork::nSharedMemory2::CNode*);
            void removeNode(s32 node_index);
            s32 flashNode();
            nNetwork::nSharedMemory2::CNode* getNode(MtString str);
            void addRecord(MtString key, nNetwork::nSharedMemory2::CRecord* pRecord);
            void removeRecord(MtString key);
            nNetwork::nSharedMemory2::CRecord* getRecord(MtString key);
            size_t getRecordSize();
            bool lock(u32* req_seq, MtString key, s32 attr);
            bool unlock(u32* req_seq, MtString key);
            bool write(u32* req_seq, MtString key, nNetwork::nSharedMemory2::CRecord* pRecord, s32 attr);
            nNetwork::nSharedMemory2::CRecord* read(MtString key);
            static u32 findThreadFunction(void*);
        private:
            nNetwork::nSharedMemory2::CNode* findTargetNode(u32 record_id);
            void mirror(s32 dst_index, MtString key, nNetwork::nSharedMemory2::CRecord* record);
            void convert(MtMemoryStream& stream, MtString key, u32 req_seq, s32 msg_kind);
            void receive(s32 src_index, const void* data, u32 data_size);
            void checkReqLockList();
        private:
            nNetwork::nSharedMemory2::THREAD_INFO mThreadInfo;  // offset: 0x8
            nNetwork::nSharedMemory2::CConsistentHash mCHash;  // offset: 0x30
            nNetwork::nSharedMemory2::CSessionListener mSessionListener;  // offset: 0x4858
            nNetwork::nSharedMemory2::CProtocol* mpProtocol;  // offset: 0x4868
            nNetwork::nSharedMemory2::CListener* mpListener;  // offset: 0x4870
            MtMap mRecordMap;  // offset: 0x4878
            s32 mType;  // offset: 0x9090
            u32 mRequestSeq;  // offset: 0x9094
            bool mInit;  // offset: 0x9098
            MtStlList<ReqLock, MtStlAllocator<ReqLock> > mLockReqList;  // offset: 0x90a0
        public:
            static MyDTI DTI;
        private:
            static nNetwork::nSharedMemory2::CNode sNode;
        };
    }  // namespace nSharedMemory2
}  // namespace nNetwork
