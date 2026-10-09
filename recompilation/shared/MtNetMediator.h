#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetCom.h"
#include "MtNetCore.h"
#include "MtNetObject.h"
#include "MtNetSession.h"
#include "MtNetUtilityPS4.h"
#include "MtString.h"
#include "_rtc.h"
#include "np_auth.h"
#include "np_common.h"
#include "np_npid.h"

// Forward declarations
namespace MtNet { namespace PS4Psn { class Context; } }
namespace MtNet { namespace Utility { namespace PS4 { class BlockList; } } }
namespace MtNet { namespace Utility { namespace PS4 { class Match; } } }
namespace MtNet { namespace Utility { namespace PS4 { class PsPlus; } } }
namespace MtNet { namespace Utility { namespace PS4 { class ReqCtx; } } }
class MtNetCore;
struct MtNetSessionInfo;
class MtNetUniqueId;
class MtPropertyList;
class MtString;
struct SceNpAuthGetAuthorizationCodeParameter;
struct SceNpAuthorizationCode;
struct SceNpId;
struct SceNpOnlineId;
struct SceNpPartyJoinedInfo;
struct SceNpPartyMemberInfo;
struct SceNpPartyRoomLeftInfo;
struct SceNpSessionInvitationEventParam;
struct SceRtcTick;
struct _SceKernelSema;

// Declarations
class MtNetMediator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
namespace MtNet { namespace Utility { namespace PS4 { using ReqCtxPtr = MtNet::Utility::PS4::ReqCtx*; } } }
using SceKernelSema = _SceKernelSema*;
using __uint16_t = unsigned short;
using uint16_t = __uint16_t;
using SceNpMatching2ContextId = uint16_t;
using SceNpMatching2Event = uint16_t;
using SceNpMatching2EventCause = unsigned char;
using SceNpMatching2ServerId = uint16_t;
using SceNpPartyRoomMemberId = uint16_t;
using __int32_t = int;
using int32_t = __int32_t;
using SceNpPlusEventType = int32_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpServiceLabel = uint32_t;
using SceUserServiceUserId = int32_t;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

class MtNetMediator : public MtNetObject
{
    // inferred: MtNet::PS4Psn::Context::moveFinalize names MtNetMediator::mpInstance
    friend class MtNet::PS4Psn::Context;
    // inferred: MtNetCore::npStateCallback names MtNetMediator::mpInstance
    friend class MtNetCore;
public:
    enum PresenceFlag
    {
        PresenceFlag_Str = 1,
        PresenceFlag_Data = 2,
    };
public:
    struct PsnUsrInfo;
public:
    struct PsnUsrInfo
    {
    public:
        bool mIsValid;  // offset: 0x0
        SceUserServiceUserId mSceUserId;  // offset: 0x4
        s32 mXfUserNo;  // offset: 0x8
        SceNpState mNpState;  // offset: 0xc
        SceNpId mNpId;  // offset: 0x10
        SceNpAuthorizationCode mNpAuthCode;  // offset: 0x34
        int mNpAuthIssuer;  // offset: 0xbc
        s32 mNpAuthAsyncPhase;  // offset: 0xc0
        s32 mNpAuthAsyncResult;  // offset: 0xc4
        int mNpAuthAsyncRequestId;  // offset: 0xc8
        SceNpAuthGetAuthorizationCodeParameter mNpAuthGetParam;  // offset: 0xd0
        bool mIsChatRestriction;  // offset: 0xf0
        bool mIsUgcRestriction;  // offset: 0xf1
        int32_t mWebApiNormalPushFilterId;  // offset: 0xf4
        int32_t mWebApiServicePushFilterId;  // offset: 0xf8
        int32_t mWebApiUsrContextId;  // offset: 0xfc
        int mNpScoreContextId;  // offset: 0x100
        int mNpTssContextId;  // offset: 0x104
        int mNpTusContextId;  // offset: 0x108
        SceRtcTick mNpTusLastChangedDate;  // offset: 0x110
        SceRtcTick mNpTusCompChangedDate;  // offset: 0x118
        bool mPresenceCanUse;  // offset: 0x120
        MtStringEx<256> mPresenceStatusStr;  // offset: 0x124
        u8 mPresenceDataTbl[128];  // offset: 0x228
        s32 mPresenceDataSize;  // offset: 0x2a8
        u32 mPresenceUpdateFlag;  // offset: 0x2ac
        MtNet::Utility::PS4::ReqCtxPtr mPresenceReqCtxPtr;  // offset: 0x2b0
        bool mBrowserIsParamPos;  // offset: 0x2b8
        u32 mBrowserParamPosX;  // offset: 0x2bc
        u32 mBrowserParamPosY;  // offset: 0x2c0
        u32 mBrowserParamWidth;  // offset: 0x2c4
        u32 mBrowserParamHeight;  // offset: 0x2c8
        u32 mBrowserParamParts;  // offset: 0x2cc
        bool mBrowserIsParamCb;  // offset: 0x2d0
        MtStringEx<1024> mBrowserParamCbStr;  // offset: 0x2d4
        MtString mBrowserResultCbStr;  // offset: 0x6d8
        bool mBrowserIsRestrict;  // offset: 0x6e0
        MtStringEx<256> mBrowserParamRestrictTbl[20];  // offset: 0x6e4
        s32 mBrowserResultValue;  // offset: 0x1b34
        bool mBrowserIsOpen;  // offset: 0x1b38
        bool mErrorDialogIsOpen;  // offset: 0x1b39
        bool mProfileDialogIsOpen;  // offset: 0x1b3a
        bool mInviteDialogIsOpen;  // offset: 0x1b3b
        s32 mPlayedWithPhase;  // offset: 0x1b3c
        SceNpOnlineId mPlayedWithIdTbl[16];  // offset: 0x1b40
        s32 mPlayedWithIdNum;  // offset: 0x1c80
        MtStringEx<1024> mPlayedWithExplain;  // offset: 0x1c84
        MtNet::Utility::PS4::ReqCtxPtr mPlayedWithReqCtxPtr;  // offset: 0x2088
        MtNet::Utility::PS4::BlockList mBlockList;  // offset: 0x2090
        bool mIsInviteAccept;  // offset: 0x2ec8
        MtNetSessionInfo mInviteSessionInfo;  // offset: 0x2ed0
        MtNetCom::IInvitePS4::SessionParam mInviteSessionParam;  // offset: 0x30d8
        MtNetCom::IInnerStringPS4::MessageParam mInnerMessageParam;  // offset: 0x3400
        MtNet::Utility::PS4::ReqCtxPtr mEntitlementReqCtxPtr;  // offset: 0x3410
        MtNet::Utility::PS4::Json::EntitlementId mEntitlementId;  // offset: 0x3418
        MtNet::Utility::PS4::PsPlus* mPsPlusPtr;  // offset: 0x3460
        MtNet::Utility::PS4::Match* mMatchPtr;  // offset: 0x3468
    };
public:
    static MtNetMediator* getInstance();
    MtNetMediator();
    virtual ~MtNetMediator();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void move();
    void reset();
    void setInitParam(const MtNetCore::InitParam& init_param);
    const MtNetCore::InitParam& getInitParam() const;
    bool isPsnSignInDisuse() const;
    bool isPsnWebApiDisuse() const;
    bool isPsnCommerceDisuse() const;
    void setLibsslContextId(int id);
    int getLibsslContextId();
    void setLibhttpContextId(int id);
    int getLibhttpContextId();
    s32 getPartyMemberIndex(SceNpPartyRoomMemberId member_id);
    void setPartyInit();
    void addPartyLocalUser(const SceNpPartyJoinedInfo& info);
    void removePartyLocalUser(const SceNpPartyRoomLeftInfo& info);
    void addPartyRemoteUser(const SceNpPartyMemberInfo& info);
    void removePartyRemoteUser(const SceNpPartyMemberInfo& info);
    void changePartyLeader(const SceNpPartyMemberInfo& info);
    const MtNetCom::IPartyPS4::PartyInfo& getPartyInfo() const;
    void addPsnUsrInfo(SceUserServiceUserId user_id, s32 xf_user_no, SceNpState np_state, const SceNpId& np_id);
    bool isPsnUsrInfo(SceUserServiceUserId user_id);
    void removePsnUsrInfo(SceUserServiceUserId user_id);
    void setPsnUsrInfo(SceUserServiceUserId user_id, SceNpState np_state, const SceNpId* np_id);
    SceNpState getPsnUsrNpState(SceUserServiceUserId user_id);
    const SceNpId& getPsnUsrNpId(SceUserServiceUserId user_id);
    bool isPsnUsrTask(SceUserServiceUserId user_id);
    SceNpAuthorizationCode& getNpAuthCode(SceUserServiceUserId user_id);
    s32& getNpAuthIssuer(SceUserServiceUserId user_id);
    bool reqNpAuthCodeAsync(SceUserServiceUserId user_id);
    s32 waitNpAuthCodeAsync(SceUserServiceUserId user_id);
    void setChatRestriction(SceUserServiceUserId user_id, bool is_restict);
    bool isChatRestriction(SceUserServiceUserId user_id);
    void setUgcRestriction(SceUserServiceUserId user_id, bool is_restict);
    bool isUgcRestriction(SceUserServiceUserId user_id);
    void setBlockList(SceUserServiceUserId user_id, MtNet::Utility::PS4::BlockList& blk_list);
    const MtNet::Utility::PS4::BlockList& getBlockList(SceUserServiceUserId user_id);
    void setWebApiLibContextId(int32_t id);
    int32_t getWebApiLibContextId();
    void setWebApiNormalPushFilterId(SceUserServiceUserId user_id, int32_t id);
    int32_t getWebApiNormalPushFilterId(SceUserServiceUserId user_id);
    void setWebApiServicePushFilterId(SceUserServiceUserId user_id, int32_t id);
    int32_t getWebApiServicePushFilterId(SceUserServiceUserId user_id);
    void setWebApiUsrContextId(SceUserServiceUserId user_id, int32_t id);
    int32_t getWebApiUsrContextId(SceUserServiceUserId user_id);
    void setPresenceCanUse(const SceNpOnlineId& np_online_id, bool can_use);
    void setPresenceStr(SceUserServiceUserId user_id, MT_CTSTR status_str);
    void setPresenceData(SceUserServiceUserId user_id, const void* data_ptr, s32 data_size);
    void addPlayedWith(SceUserServiceUserId user_id, MtNetUniqueId* id_list, s32 id_num, MT_CTSTR explain);
    void checkPsPlus(SceUserServiceUserId user_id, u32 features);
    bool getPsPlus(SceUserServiceUserId user_id, bool& is_auth);
    void stopPsPlus(SceUserServiceUserId user_id);
    void webBrowserSetSize(SceUserServiceUserId user_id, u32 posx, u32 posy, u32 width, u32 height, u32 parts);
    void webBrowserSetCb(SceUserServiceUserId user_id, MT_CTSTR url_ptr);
    MT_CTSTR webBrowserGetCb(SceUserServiceUserId user_id);
    void webBrowserAddRestrict(SceUserServiceUserId user_id, MT_CTSTR url_ptr);
    s32 webBrowserGetResult(SceUserServiceUserId user_id);
    bool webBrowserOpen(SceUserServiceUserId user_id, MT_CTSTR url_ptr);
    bool webBrowserIsOpen(SceUserServiceUserId user_id);
    void webBrowserClose(SceUserServiceUserId user_id);
    bool errorDialogOpen(SceUserServiceUserId user_id, MT_CTSTR err_ptr);
    bool errorDialogIsOpen(SceUserServiceUserId user_id);
    void errorDialogClose(SceUserServiceUserId user_id);
    void setInviteSessionParam(SceUserServiceUserId user_id, const MtNetCom::IInvitePS4::SessionParam& param);
    MtNetCom::IInvitePS4::SessionParam& getInviteSessionParam(SceUserServiceUserId user_id);
    void acceptNpInvitation(SceNpSessionInvitationEventParam* param);
    bool isInviteAccept(SceUserServiceUserId user_id, MtNetSessionInfo& info);
    bool openInviteDialog(SceUserServiceUserId user_id);
    bool isInviteDialogOpen(SceUserServiceUserId user_id);
    void closeInviteDialog(SceUserServiceUserId user_id);
    void setInnerMessageParam(SceUserServiceUserId user_id, const MtNetCom::IInnerStringPS4::MessageParam& param);
    const MtNetCom::IInnerStringPS4::MessageParam& getInnerMessageParam(SceUserServiceUserId user_id);
    bool reqGetEntitlementByRange(SceUserServiceUserId user_id, s32 offset, s32 max_count, SceNpServiceLabel label);
    s32 pollGetEntitlementByRange(SceUserServiceUserId user_id, MtNetCom::IEntitlementPS4::EntitlementList* list);
    bool reqGetEntitlementById(SceUserServiceUserId user_id, MT_CTSTR ent_id, SceNpServiceLabel label);
    s32 pollGetEntitlementById(SceUserServiceUserId user_id, MtNetCom::IEntitlementPS4::EntitlementInfo* info);
    bool reqSetEntitlement(SceUserServiceUserId user_id, s32 count, MT_CTSTR ent_id, SceNpServiceLabel label);
    s32 pollSetEntitlement(SceUserServiceUserId user_id, MtNetCom::IEntitlementPS4::EntitlementUseResult* use_result);
    bool openProfileDialog(SceUserServiceUserId user_id, SceNpOnlineId& id);
    bool isProfileDialogOpen(SceUserServiceUserId user_id);
    void closeProfileDialog(SceUserServiceUserId user_id);
    s32 createNpScoreContextId(SceUserServiceUserId user_id, SceNpServiceLabel label);
    void deleteNpScoreContextId(SceUserServiceUserId user_id);
    int getNpScoreContextId(SceUserServiceUserId user_id);
    s32 getNpScoreGameDataRankThreashold(s32 board_id);
    s32 createNpTssContextId(SceUserServiceUserId user_id, SceNpServiceLabel label);
    void deleteNpTssContextId(SceUserServiceUserId user_id);
    int getNpTssContextId(SceUserServiceUserId user_id);
    s32 createNpTusContextId(SceUserServiceUserId user_id, SceNpServiceLabel label);
    void deleteNpTusContextId(SceUserServiceUserId user_id);
    int getNpTusContextId(SceUserServiceUserId user_id);
    void setNpTusLastChangedDate(SceUserServiceUserId user_id, const SceRtcTick& date);
    const SceRtcTick& getNpTusLastChangedDate(SceUserServiceUserId user_id);
    void setNpTusCompChangedDate(SceUserServiceUserId user_id, const SceRtcTick& date);
    const SceRtcTick& getNpTusCompChangedDate(SceUserServiceUserId user_id);
    SceNpMatching2ContextId getNpMatchContextId(SceUserServiceUserId user_id);
    SceNpMatching2ServerId getNpMatchServerId(SceUserServiceUserId user_id);
    s32 getNpMatchContextError(SceUserServiceUserId user_id);
    s32 startNpMatchContext(SceUserServiceUserId user_id, const MtNetObject& owner_obj);
    s32 termNpMatchContext(SceUserServiceUserId user_id, const MtNetObject& owner_obj);
    void setNpMatchContextEvent(SceNpMatching2ContextId context_id, SceNpMatching2Event event_id, SceNpMatching2EventCause event_cause, int error_code);
    s32 waitNpMatchSema();
    s32 signalNpMatchSema();
    bool isSceUserId(s32 xf_user_no);
    SceUserServiceUserId getSceUserId(s32 xf_user_no);
private:
    void clearPsnUsrInfo(PsnUsrInfo& usr_info);
    PsnUsrInfo& getPsnUsrInfo(SceUserServiceUserId user_id);
    PsnUsrInfo& getPsnUsrInfo(const SceNpOnlineId& np_online_id);
    void updatePsnUsrPresence(PsnUsrInfo& usr_info);
    void updatePsnUsrBrowser(PsnUsrInfo& usr_info);
    void updatePsnUsrErrorDialog(PsnUsrInfo& usr_info);
    void updatePsnUsrProfileDialog(PsnUsrInfo& usr_info);
    void updatePsnUsrInviteDialog(PsnUsrInfo& usr_info);
    void updatePsnUsrAuthAsync(PsnUsrInfo& usr_info);
    void updatePsnUsrPlayedWith(PsnUsrInfo& usr_info);
    static void psPlusCallback(SceUserServiceUserId user_id, SceNpPlusEventType event_id, void* arg_ptr);
    void setPsPlusEvent(SceUserServiceUserId user_id, SceNpPlusEventType event_id);
private:
    MtNetCore::InitParam mInitParam;  // offset: 0x28
    PsnUsrInfo mPsnUsrInfoTbl[5];  // offset: 0x178
    int mLibsslContextId;  // offset: 0x107a8
    int mLibhttpContextId;  // offset: 0x107ac
    MtNetCom::IPartyPS4::PartyInfo mPartyInfo;  // offset: 0x107b0
    int32_t mWebApiLibContextId;  // offset: 0x10bb8
    SceKernelSema mNpMatchSema;  // offset: 0x10bc0
    static MtNetMediator* mpInstance;
    static const s32 MAX_NUM_PSN_USER_INFO = 5;
    static const s32 MAX_NUM_PLAYER_HISTORY = 16;
};
