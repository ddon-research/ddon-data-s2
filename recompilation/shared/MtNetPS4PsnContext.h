#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetBuffer.h"
#include "MtNetContext.h"
#include "MtNetDevice.h"
#include "MtNetUtilityPS4.h"
#include "np_common.h"
#include "np_npid.h"

// Forward declarations
namespace MtNet { namespace Utility { namespace PS4 { class BlockList; } } }
namespace MtNet { namespace Utility { namespace PS4 { class ReqCtx; } } }
class MtNetFriendList;
struct MtNetIpAddress;
struct MtNetPhysicalAddress;
class MtNetRequest;
class MtNetUniqueId;
class MtPropertyList;
class MtTime;
struct SceNpCountryCode;
struct SceNpId;
struct SceNpParentalControlInfo;
struct SceNpPeerAddress;
struct SceNpWebApiPushEventDataType;

// Declarations
namespace MtNet { namespace PS4Psn { class Context; } }

// Type aliases from DWARF
namespace MtNet { namespace Utility { namespace PS4 { using ReqCtxPtr = MtNet::Utility::PS4::ReqCtx*; } } }
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpServiceLabel = uint32_t;
using __int32_t = int;
using int32_t = __int32_t;
using SceUserServiceUserId = int32_t;
using _Sizet = long unsigned int;
using __int8_t = signed char;
using __uint64_t = long unsigned int;
using int8_t = __int8_t;
using s32 = int;
using size_t = _Sizet;
using u64 = __uint64_t;

namespace MtNet {
    namespace PS4Psn {
        class Context : public ::MtNetContext
        {
        public:
            virtual ~Context();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual void move();  // vtable slot 11
            virtual void getUniqueId(MtNetUniqueId* uniq_id);  // vtable slot 12
            virtual s32 getSignInLevel() const;  // vtable slot 13
            virtual bool isAllowedMultiplay() const;  // vtable slot 14
            virtual bool isIpObtained() const;  // vtable slot 15
            virtual bool isPhysicalLink() const;  // vtable slot 16
            virtual s32 getIpAddressSelfNum() const;  // vtable slot 17
            virtual void getIpAddressSelf(s32 index, MtNetIpAddress* address) const;  // vtable slot 18
            virtual s32 getPhysicalAddressSelfNum() const;  // vtable slot 19
            virtual void getPhysicalAddressSelf(s32 index, MtNetPhysicalAddress* address) const;  // vtable slot 20
            virtual void setAddressIndex(s32 index);  // vtable slot 21
            virtual s32 getAddressIndex() const;  // vtable slot 22
            virtual s32 getCountry() const;  // vtable slot 23
            virtual MtNetFriendList* getFriendList();  // vtable slot 24
            virtual bool getTime(MtTime* ntime);  // vtable slot 25
            // Address: 0x01b4f1b0 - 0x01b4f1b1 (1 bytes)
            virtual void onGuideOpen(bool is_open) {}  // vtable slot 26
            // Address: 0x01b4f1c0 - 0x01b4f1c1 (1 bytes)
            virtual void onGuideSignInChanged(s32 state) {}  // vtable slot 27
            // Address: 0x01b4f1d0 - 0x01b4f1d1 (1 bytes)
            virtual void onGuideConnectionChanged(void* data_ptr) {}  // vtable slot 28
            // Address: 0x01b4f1e0 - 0x01b4f1e1 (1 bytes)
            virtual void onGuideInviteAccepted(s32 user_index) {}  // vtable slot 29
            // Address: 0x01b4f1f0 - 0x01b4f1f1 (1 bytes)
            virtual void onGuidePhysicalLinkChanged(bool is_link) {}  // vtable slot 30
            // Address: 0x01b4f200 - 0x01b4f201 (1 bytes)
            virtual void onGuideFriendListChanged(s32 user_index, s32 action) {}  // vtable slot 31
            // Address: 0x01b4f210 - 0x01b4f211 (1 bytes)
            virtual void onGuideAppSuspend() {}  // vtable slot 32
            // Address: 0x01b4f220 - 0x01b4f221 (1 bytes)
            virtual void onGuideAppShutdown() {}  // vtable slot 33
        private:
            Context(s32 user_index);
            virtual s32 moveStart(MtNetRequest* req);  // vtable slot 34
            virtual s32 moveFinalize(MtNetRequest* req);  // vtable slot 35
            void updateFriendList();
            void updateBlockList();
            void releaseNp();
            s32 npCountryCode2MtNetCountry(const SceNpCountryCode& cc);
            static void webApiNormalPushCallback(int32_t user_ctx_id, int32_t callback_id, const SceNpPeerAddress* to_ptr, const SceNpPeerAddress* from_ptr, const SceNpWebApiPushEventDataType* normal_push_type_ptr, const char* data_ptr, size_t data_size, void* arg_ptr);
            static void webApiServicePushCallback(int32_t user_ctx_id, int32_t callback_id, const char* np_service_name_ptr, SceNpServiceLabel np_service_label, const SceNpPeerAddress* to_ptr, const SceNpPeerAddress* from_ptr, const SceNpWebApiPushEventDataType* service_push_type_ptr, const char* data_ptr, size_t data_size, void* arg_ptr);
        private:
            s32 mXfUserNo;  // offset: 0xe0
            SceUserServiceUserId mStartSceUserId;  // offset: 0xe4
            bool mIsStartSucceed;  // offset: 0xe8
            s32 mCountry;  // offset: 0xec
            MtNetFriendList mFriendList;  // offset: 0xf0
            s32 mSignInLevel;  // offset: 0x3aaa0
            int mNpAsyncRequestId;  // offset: 0x3aaa4
            SceNpId mNpSelfId;  // offset: 0x3aaa8
            int8_t mNpParentalControlAge;  // offset: 0x3aacc
            SceNpParentalControlInfo mNpParentalControlInfo;  // offset: 0x3aacd
            MtNetUniqueId mUniqueId;  // offset: 0x3aad0
            MtNetTime::Total mStartTimer;  // offset: 0x3ab48
            s32 mStartProgress;  // offset: 0x3ab50
            s32 mStartProgressShow;  // offset: 0x3ab54
            MtNet::Utility::PS4::ReqCtxPtr mWebApiReqCtxPtr;  // offset: 0x3ab58
            int32_t mWebApiServicePushHandleId;  // offset: 0x3ab60
            int32_t mWebApiNormalPushCallbackId;  // offset: 0x3ab64
            int32_t mWebApiServicePushCallbackId;  // offset: 0x3ab68
            bool mFriendUpdateFlag;  // offset: 0x3ab6c
            s32 mFriendUpdatePhase;  // offset: 0x3ab70
            MtNetFriendList mFriendUpdateTemp;  // offset: 0x3ab78
            MtNet::Utility::PS4::ReqCtxPtr mFriendReqCtxPtr;  // offset: 0x75528
            bool mBlockUpdateFlag;  // offset: 0x75530
            s32 mBlockUpdatePhase;  // offset: 0x75534
            MtNet::Utility::PS4::BlockList mBlockUpdateTemp;  // offset: 0x75538
            MtNet::Utility::PS4::ReqCtxPtr mBlockReqCtxPtr;  // offset: 0x76370
        };
    }  // namespace PS4Psn
}  // namespace MtNet
