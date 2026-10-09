#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/ChatMsgType.h"
#include "../shared/MtDTI.h"
#include "../shared/MtNetSession.h"
#include "../shared/MtObject.h"
#include "../shared/nNet.h"
#include "../shared/nNetworkSessionListener.h"

// Forward declarations
class BitReader;
class BitWriter;
class CDataClientPartyListInfo;
class CDataCommunityCharacterBaseInfo;
class CDataPartyListInfo;
class CDataPartyMember;
class CDataQuickPartyMatching;
class MtAllocator;
class MtDTI;
struct MtNetError;
class MtObject;
class cMenuEntryBoardItemList;
class cMenuPartyMemberList;
class cMenuQuickMatchCancel;
class cPartyMemberInfo;
namespace nNet { class cProgress; }
namespace nNet { class cResult; }
class uGUIAreaMaster;
class uGUINewspaper;

// Declarations
namespace nSessionManager { class MyListener; }
namespace nSessionManager { class cLobbyDataMessage; }
namespace nSessionManager { class cNetSessionManager; }

// Type aliases from DWARF
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CPartyMember = CDataPartyMember;
using CQuickPartyMatching = CDataQuickPartyMatching;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nSessionManager {
    class MyListener : public nNetwork::SessionListener
    {
        // inferred: nSessionManager::cNetSessionManager::setup names nSessionManager::cNetSessionManager::mListener[0].mSessionId
        friend class nSessionManager::cNetSessionManager;
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
        MyListener();
        virtual void onCreateComplete(bool flag, MtNetError* err);  // vtable slot 13
        virtual void onSearchComplete(bool flag, MtNetError* err);  // vtable slot 14
        virtual void onJoinComplete(bool flag, MtNetError* err);  // vtable slot 15
        virtual void onJoinMember(s32 index, MtNetSession::Member* member);  // vtable slot 8
        virtual void onEntryMember(s32 index, bool entry);  // vtable slot 10
        virtual void onLeaveMember(s32 index, MtNetSession::Member* member);  // vtable slot 9
        virtual void onDrop(MtNetError* err);  // vtable slot 7
        virtual void onFinalize();  // vtable slot 6
        // Address: 0x01a425b0 - 0x01a425b1 (1 bytes)
        virtual void onGameStart() {}  // vtable slot 19
        void onGameStart(bool flag, MtNetError* err);
        void onLobbyChatMsgNotice(u32 handleId, const CCommunityCharacterBaseInfo& charInfo, s32 type, MT_CTSTR str);
        void onLobbyInviteMsgNotice(bool isLeader);
        void onLobbyInviteCancelMsgNotice(s32 errCode);
        void onLobbyInviteDeclineMsgNotice(u32 serverId, u32 partyId, s32 errCode);
        void setSessionId(s32 session_id);
        s32 getSessionId();
    private:
        s32 mSessionId;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
}  // namespace nSessionManager

namespace nSessionManager {
    class cLobbyDataMessage : public ::MtObject
    {
    public:
        enum LOBBY_MSG_TYPE
        {
            LOBBY_MSG_TYPE_DUMMY = 0,
            LOBBY_MSG_TYPE_RPC = 1,
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
        cLobbyDataMessage();
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
        void serialize(BitWriter& w) const;
        void deserialize(BitReader& r);
        LOBBY_MSG_TYPE getMsgType();
        void setMsgType(LOBBY_MSG_TYPE type);
    private:
        LOBBY_MSG_TYPE mMsgType;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
}  // namespace nSessionManager

namespace nSessionManager {
    class cNetSessionManager : public ::MtObject
    {
        // inferred: cMenuEntryBoardItemList::checkMenuPartsParam names nSessionManager::cNetSessionManager::mQuickMatchRno
        friend class ::cMenuEntryBoardItemList;
        // inferred: cMenuPartyMemberList::checkMenuPartsParam names nSessionManager::cNetSessionManager::mQuickMatchRno
        friend class ::cMenuPartyMemberList;
        // inferred: cMenuQuickMatchCancel::moveQuickMatchCancel names nSessionManager::cNetSessionManager::mQuickMatchRno
        friend class ::cMenuQuickMatchCancel;
        // inferred: nSessionManager::MyListener::onDrop calls nSessionManager::cNetSessionManager::requestSessionCommand
        friend class nSessionManager::MyListener;
        // inferred: uGUIAreaMaster::eventDecide names nSessionManager::cNetSessionManager::mQuickMatchRno
        friend class ::uGUIAreaMaster;
        // inferred: uGUINewspaper::evCtrlNewsCmnClick names nSessionManager::cNetSessionManager::mQuickMatchRno
        friend class ::uGUINewspaper;
    public:
        enum
        {
            QUICK_MATCH_RNO_IDLE = 0,
            QUICK_MATCH_RNO_START = 1,
            QUICK_MATCH_RNO_READY_WAIT = 2,
            QUICK_MATCH_RNO_RETRY_INIT = 3,
            QUICK_MATCH_RNO_RETRY_MOVE = 4,
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
        cNetSessionManager();
        virtual ~cNetSessionManager();
        void clearJoinLobby();
        bool isPartyReqOk(s32 partyListIndex, bool onlyOne, bool large);
        void sendInvite(const CDataPartyListInfo& info);
        void sendInviteCancel(u32 serverNo, u32 partyID);
        void sendInviteCancelAll();
        void sendInviteDecline(u32 characterID);
        void sendRpc(s32 sessionId, u8* data_ptr, u32 data_size, s32 sendMemberType, u32 characterId, u32 protocol);
        bool isSessionOnline(s32 session_id);
        bool isGameSessionOnline();
        bool isLobbySessionOnline();
        bool isGameSessionMySelf(s32 memberIndex);
        bool isPartyLeader(u32 characterId);
        bool isPartyLeader();
        bool isPartyLarge(bool checkOnline);
        cPartyMemberInfo* getPartyMemberInfo(s32 memberIndex);
        u32 getPartyMemberCharId(s32 memberIndex);
        s32 getSelfIndex(s32 session_id);
        s32 getGameSelfIndex();
        s32 getPartyMemberMaxNum();
        void setPartyMemberMaxNum(s32);
        s32 getNormalPartyMemberMaxNum();
        void setNormalPartyMemberMaxNum(s32);
        s32 getLobbyMemberMaxNum();
        void setLobbyMemberMaxNum(s32 num);
        s32 getGameSessionMemberNum(bool isBeforeJoinMember);
        s32 getGameSessionPlayerMemberNum(bool isBeforeJoinMember);
        s32 getGameSessionPawnMemberNum(bool isBeforeJoinMember);
        s32 getSearchResultNum();
        void setup();
        void move();
        void remove();
    private:
        bool createFlow(nNet::cProgress& progress);
        bool searchFlow(nNet::cProgress& progress);
        bool joinFlow(nNet::cProgress& progress);
        bool entryFlow(nNet::cProgress& progress);
        bool startFlow(nNet::cProgress& progress);
        bool finalFlow(nNet::cProgress& progress);
        bool joinLobbyFlow(nNet::cProgress& progress);
        bool finalLobbyFlow(nNet::cProgress& progress);
    public:
        void initFinalFlow(s32 session_id, bool noAreaJump);
        void requestJumpLobbyNoParty();
        void clearEntryBit();
        bool isEntryBit(u32);
        void onEntryBit(u32);
        void offEntryBit(u32);
        bool isMemberEntry(s32 session_id, s32 index);
        bool isEnableQuickParty();
        void reqQuickPartyDisableAnnounce();
        void startQuickMatch(nNet::QUICK_MATCH_TYPE type, CQuickPartyMatching& matching);
        void cancelQuickMatch(bool isReqServer);
        void unreadyQuickMatch();
        void endQuickMatch();
        void moveQuickMatch();
        nSessionManager::MyListener* getListener(s32 session_id);
        u32 getInvitePartyLeaderId();
        bool isExistLeaderChangeArea();
        bool isEnableLeaderChange();
        bool isEnableReady(bool withPawn, bool pawnOnly);
        void setReadyAction(bool withPawn);
        bool isSetReadyAction();
        void endReadyAction();
        void clearPartyReqInfo(s32 index);
        void clearPartyReqInfo(CDataClientPartyListInfo& info);
        void clearPartyReqInfoAll();
        bool setPartyReqInfo(const CDataPartyListInfo& info);
        CDataClientPartyListInfo& getPartyReqInfo(s32 index);
        u32 getPartyReqCharId(s32 index);
        u32 getPartyReqPartyId(s32 index);
        u32 getPartyReqServerId(s32 index);
        CPartyMember* getPartyReqLeaderInfo(s32 index);
        s32 getPartySpaceNum();
        bool isNowPartyReq();
        bool isNowPartyReq(u32 characterId);
        CDataClientPartyListInfo& getInvitedPartyInfo();
        CPartyMember* getInvitedLeaderInfo();
        bool isPartyInvited();
        void setIsPartyInvited(bool flag);
        bool isPartyInvitedAnnounce();
        void setIsPartyInvitedAnnounce(bool flag);
        f32 getPartyInvitedTimer();
        void setPartyInvitedTimer(f32 timer);
        bool isNowQuickMatchReq();
        void setIsNowQuickMatchReq(bool flag);
        bool isNowQuickMatchFlow();
        bool isQuickMatchReadyWait();
        bool isQuickMatchReadyWaitAnnounce();
        void setIsQuickMatchReadyWaitAnnounce(bool flag);
        f32 getQuickMatchTimer();
        void setQuickMatchTimer(f32 timer);
        s32 getQuickMatchJob();
        void setQuickMatchJob(s32 job);
        void sendChatLobby(MT_CTSTR str, nChatMsgType::E_CHAT_MSG_TYPE type);
        void sendChatParty(MT_CTSTR str);
        void sendChatTell(CCommunityCharacterBaseInfo& charInfo, MT_CTSTR str);
        void sendChatGroup(MT_CTSTR str);
        void sendChatClan(MT_CTSTR str);
        void sendChatClanNtc(MT_CTSTR str);
        void sendChatEntryBoard(MT_CTSTR str);
        nSessionManager::cLobbyDataMessage* getLobbyDataMessagePtr();
        nSessionManager::cLobbyDataMessage& getLobbyDataMessageRef();
        void moveSessionManager();
        void createGameSessionRequest();
        void searchGameSessionRequest();
        void joinGameSessionRequest(u32 value);
        void joinLobbySessionRequest();
        void entryGameSessionRequest(bool entry);
        void startGameSessionRequest(u32 value);
        void finalGameSessionRequest(bool noAreaJump);
        void finalLobbySessionRequest();
        void finalAllSessionRequest();
        void abortSessionCommand(const nNet::cProgress::CTRL_IDX ctrlIdx);
        void abortAllSessionCommand();
        void waitSessionManager(const nNet::cProgress::CTRL_IDX ctrlIdx, nNet::cResult& result);
        bool checkSessionCommandRequest(s32 session_id, u32 order);
        s32 getSessionIdFromCommand(nNet::cProgress::CMD cmd);
        u32 getSessionCommandOrder(nNet::cProgress::CMD cmd);
        nNet::cProgress* getSessionManager_ProgExe();
        u32 getSessionChannel();
        void setSessionChannel(u32);
    private:
        s32 getSessionState(s32 session_id);
        bool initSession(s32 session_id);
        void abortRequest();
        void requestSessionCommand(const nNet::cProgress::CMD cmd, const nNet::cProgress::CTRL_IDX ctrlIdx, const bool flag, const u32 value);
        nNet::cProgress* getSessionManager_ProgCtrlIdx(const nNet::cProgress::CTRL_IDX ctrlIdx);
        nNet::cProgress* getSessionManager_ProgConnect(nNet::cProgress* pNext);
        nNet::cProgress* getSessionManager_ProgLast();
        nNet::cProgress* getSessionManager_ProgEmpty();
        bool isSameCommandContinue(nNet::cProgress::CMD cmd);
    private:
        u8 mEntryBit;  // offset: 0x8
        u8 mStartBit;  // offset: 0x9
        nSessionManager::MyListener mListener[2];  // offset: 0x10
        bool mIsPartyInvited;  // offset: 0x30
        bool mIsPartyInvitedAnnounce;  // offset: 0x31
        f32 mPartyInvitedTimer;  // offset: 0x34
        CDataClientPartyListInfo mPartyReqInfo[8];  // offset: 0x38
        bool mIsNowQuickMatch;  // offset: 0x3b8
        bool mIsQuickMatchReadyWaitAnnounce;  // offset: 0x3b9
        f32 mQuickMatchTimer;  // offset: 0x3bc
        s32 mQuickMatchJob;  // offset: 0x3c0
        s32 mQuickMatchRno;  // offset: 0x3c4
        f32 mQuickMatchWaitTimer;  // offset: 0x3c8
        s32 mPartyMemberMaxNum;  // offset: 0x3cc
        s32 mNormalPartyMemberMaxNum;  // offset: 0x3d0
        nSessionManager::cLobbyDataMessage mLobbyDataMessage;  // offset: 0x3d8
        s32 mLobbyMemberMaxNum;  // offset: 0x3e8
        u32 mSessionChannel;  // offset: 0x3ec
        bool mNetworkAbortReq;  // offset: 0x3f0
        nNet::cProgress* mpExeProgress;  // offset: 0x3f8
        nNet::cProgress mSesMngProgress[8];  // offset: 0x400
    public:
        static MyDTI DTI;
    };
}  // namespace nSessionManager

// Inline, no code of its own: checked where it is inlined.
inline nSessionManager::MyListener::MyListener() {
    this->mSessionId = static_cast<s32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline nSessionManager::cLobbyDataMessage::cLobbyDataMessage() {
    this->mMsgType = static_cast<nSessionManager::cLobbyDataMessage::LOBBY_MSG_TYPE>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool nSessionManager::cNetSessionManager::isNowQuickMatchReq() {
    return this->mIsNowQuickMatch;
}
