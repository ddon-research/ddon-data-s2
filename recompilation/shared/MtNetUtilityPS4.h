#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetCom.h"
#include "MtNetObject.h"
#include "MtString.h"
#include "_rtc.h"
#include "json2.h"
#include "np_npid.h"

// Forward declarations
class MtAllocator;
class MtDTI;
namespace MtNet { namespace Utility { namespace PS4 { class MtNetString; } } }
class MtObject;
struct SceNpId;
struct SceNpOnlineId;
struct SceNpSessionId;
struct SceNpTitleId;
struct SceRtcTick;
namespace sce { namespace Json { class InitParameter; } }
namespace sce { namespace Json { class Initializer; } }
namespace sce { namespace Json { class Value; } }

// Declarations
namespace MtNet { namespace Utility { namespace PS4 { class BlockList; } } }
namespace MtNet { namespace Utility { namespace PS4 { class Json; } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int32_t = int;
using __int64_t = long int;
using int32_t = __int32_t;
using int64_t = __int64_t;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class BlockList : public ::MtNetObject
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
                explicit BlockList();
                virtual ~BlockList();
                void clear();
                MtNet::Utility::PS4::BlockList& operator=(const MtNet::Utility::PS4::BlockList& src);
                s32 getNum() const;
                const SceNpId& getNpId(s32 i) const;
                void add(SceNpId& np_id);
            private:
                s32 mValidNum;  // offset: 0x24
                SceNpId mNpId[100];  // offset: 0x28
            public:
                static MyDTI DTI;
                static const s32 MAX_NUM_BLOCK = 100;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet

namespace MtNet {
    namespace Utility {
        namespace PS4 {
            class Json : public ::MtNetObject, public sce::Json::MemAllocator
            {
            public:
                class MyDTI;
                struct FriendList;
                struct BlockList;
                struct Presence;
                struct EntitlementList;
                struct EntitlementInfo;
                struct EntitlementUseResult;
            public:
                using EntitlementType = MtStringEx<32>;
                using EntitlementId = MtStringEx<64>;
            public:
                class MyDTI : public ::MtDTI
                {
                public:
                    MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                    virtual MtObject* newInstance() const;  // vtable slot 2
                };
            public:
                struct FriendList
                {
                public:
                    s32 total;  // offset: 0x0
                    s32 offset;  // offset: 0x4
                    s32 rsize;  // offset: 0x8
                    s32 num;  // offset: 0xc
                    SceNpId npIdTbl[500];  // offset: 0x10
                    static const s32 MaxNum = 500;
                };
            public:
                struct BlockList
                {
                public:
                    s32 total;  // offset: 0x0
                    s32 offset;  // offset: 0x4
                    s32 rsize;  // offset: 0x8
                    s32 num;  // offset: 0xc
                    SceNpId npIdTbl[500];  // offset: 0x10
                    static const s32 MaxNum = 500;
                };
            public:
                struct Presence
                {
                public:
                    SceNpId npId;  // offset: 0x0
                    u8 dataBuf[128];  // offset: 0x24
                    s32 dataSize;  // offset: 0xa4
                };
            public:
                struct EntitlementInfo
                {
                public:
                    MtNet::Utility::PS4::Json::EntitlementType type;  // offset: 0x0
                    bool isConsumable;  // offset: 0x24
                    MtNet::Utility::PS4::Json::EntitlementId id;  // offset: 0x28
                    SceRtcTick activeDate;  // offset: 0x70
                    SceRtcTick inactiveDate;  // offset: 0x78
                    u32 useCount;  // offset: 0x80
                    u32 useLimit;  // offset: 0x84
                };
            public:
                struct EntitlementUseResult
                {
                public:
                    u32 useLimit;  // offset: 0x0
                };
            public:
                struct EntitlementList
                {
                public:
                    s32 total;  // offset: 0x0
                    s32 offset;  // offset: 0x4
                    s32 rsize;  // offset: 0x8
                    s32 num;  // offset: 0xc
                    MtNet::Utility::PS4::Json::EntitlementInfo infoTbl[100];  // offset: 0x10
                    static const s32 MaxNum = 100;
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
                static void createInstance();
                static void deleteInstance();
                static MtNet::Utility::PS4::Json* instancePtr();
                explicit Json();
                virtual ~Json();
                s32 parseFriendList(FriendList& list, MT_CTSTR str_ptr);
                s32 parseBlockList(BlockList& list, MT_CTSTR str_ptr);
                s32 parsePresence(Presence& presence, MT_CTSTR str_ptr);
                s32 parseNpSessionId(SceNpSessionId& np_session_id, MT_CTSTR str_ptr);
                s32 parseEntitlementList(EntitlementList& list, MT_CTSTR str_ptr);
                s32 parseEntitlementInfo(EntitlementInfo& info, MT_CTSTR str_ptr);
                s32 parseEntitlementUseResult(EntitlementUseResult& use_result, MT_CTSTR str_ptr);
                s32 constructSession(MtStringEx<4096>& ret_str, int64_t join_max, MtNetCom::IInvitePS4::SessionParam* invite_param_ptr);
                s32 constructPlayedWith(MtNet::Utility::PS4::MtNetString& ret_str, SceNpOnlineId* self_id_ptr, SceNpTitleId* title_id_ptr, SceNpOnlineId* online_id_tbl, size_t online_id_num, MtStringEx<1024>* explain_str_ptr);
            private:
                virtual void* allocate(size_t size, void* arg_ptr);  // vtable slot 11
                virtual void deallocate(void* ptr, void* arg_ptr);  // vtable slot 12
                // Address: 0x01b4dc00 - 0x01b4dc01 (1 bytes)
                virtual void notifyError(int32_t err_no, size_t size, void* arg_ptr) {}  // vtable slot 13
                static const sce::Json::Value& nullAccessCallback(sce::Json::ValueType accesstype, const sce::Json::Value* parent_ptr, void* context_ptr);
                s32 commonInit(sce::Json::InitParameter& initparam, sce::Json::Initializer& initializer, sce::Json::Value& rootval, MT_CTSTR& str_ptr);
            private:
                sce::Json::Value mNull;  // offset: 0x30
            public:
                static MyDTI DTI;
            private:
                static MtNet::Utility::PS4::Json* mInstancePtr;
            };
        }  // namespace PS4
    }  // namespace Utility
}  // namespace MtNet
