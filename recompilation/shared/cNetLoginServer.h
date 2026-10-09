#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "CharacterParam.h"
#include "Error.h"
#include "MtCipher.h"
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtNetObject.h"
#include "MtObject.h"
#include "cSeedServerConnection.h"
#include "sNetworkExt.h"

// Forward declarations
class CDataCharacterInfo;
class CDataGameServerListInfo;
class CPacket;
class MtAllocator;
class MtCipher;
class MtDTI;
struct MtNetError;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cCharacterData;
namespace nLoginSession { class CPacket_L2C_GET_CHARACTER_LIST_RES; }
namespace nLoginSession { class CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC; }
namespace nLoginSession { class CPacket_L2C_GET_GAME_SERVER_LIST_RES; }
namespace nLoginSession { class CPacket_L2C_GET_LOGIN_SETTING_RES; }
namespace nLoginSession { class CPacket_L2C_NEXT_CONNECT_SERVER_NTC; }
namespace nLoginSession { class CPacket_L2C_PING_RES; }

// Declarations
class cNetLoginServer;
class cSeedLoginSvConnection;

// Type aliases from DWARF
using BOOL = int;
using CCharacterInfo = CDataCharacterInfo;
using CGameServerListInfo = CDataGameServerListInfo;
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

class cNetLoginServer : public MtObject
{
public:
    enum
    {
        COM_DUMMY = 0,
        COM_DROP = 1,
        COM_GET_CHAR_INFO = 2,
        COM_PING = 3,
        COM_LOGIN = 4,
        COM_LOGOUT = 5,
        COM_CLIENT_CHALLENGE = 6,
        COM_GET_GAME_SERVER_LIST = 7,
        COM_GET_GAME_SESSION_KEY = 8,
        COM_GET_ERROR_MESSAGE_LIST = 9,
        COM_GET_GAME_SETTING = 10,
        COM_GP_GET_COURSE_INFO = 11,
        COM_GET_CHAR_LIST = 12,
        COM_DECIDE_CHAR_ID = 13,
        COM_DECIDE_CHAR_WAIT = 14,
        COM_DECIDE_CANCEL_CHAR = 15,
        COM_DELETE_CHAR = 16,
        COM_CREATE_CHAR = 17,
        COM_NUM = 18,
    };
    enum
    {
        FLOW_NOTHING = 0,
        FLOW_CONNECT_SERVER = 1,
        FLOW_NUM = 2,
    };
public:
    class MyDTI;
    class cCtrlFlow;
    struct cGuardData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCtrlFlow : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
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
        cCtrlFlow();
        // Address: 0x01a3c1e0 - 0x01a3c1e1 (1 bytes)
        virtual ~cCtrlFlow() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void clear(bool isCallback);
        s32 getCommand();
        void setCommand(s32);
        MtNetError* getError();
        s32 getErrCode();
        void setErrCode(s32);
        bool isError();
        bool isSuccess();
        bool isCallback();
    public:
        s32 mRno0;  // offset: 0x8
        s32 mRno1;  // offset: 0xc
        s32 mCommand;  // offset: 0x10
        MtNetError mError;  // offset: 0x14
        f32 mFTimer;  // offset: 0x20
        bool mIsCallback;  // offset: 0x24
        static MyDTI DTI;
    };
public:
    struct cGuardData
    {
    public:
        MT_CHAR mSvAddr[32];  // offset: 0x0
        u32 mSvPort;  // offset: 0x20
        MT_CHAR mReqLogin_OneTimeToken[32];  // offset: 0x24
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
    cNetLoginServer();
    virtual ~cNetLoginServer();
    bool isConnectedSvUIHide();
    bool isAfterLoginUIHide();
    void clear();
    void clearAll();
    void move();
    sNetworkExt::NET_STAT getStatus(u32 comId);
    nError::ERROR_CODE getErrorCode(u32 comId);
    void setForceError(u32, nError::ERROR_CODE);
    bool sendStart(u32 commandId);
    bool sendStartBeforeLogin(u32 commandId);
    bool sendEnd(u32 commandId);
    bool sendEndNoTimeOut(u32 commandId);
    void recvResult(u32 commandId, MT_CTSTR funcStr, MT_CTSTR logStr, s32 error, bool isSuccessLog, bool isErrorDialog);
    void reqErrorDialog(u32 comId, s32 errNo);
    void setErrorDialogHandle(u32);
    u32 getErrorDialogHandle();
    bool isDispErrorDialog();
    void setIsNgErrorDialog(u32 comId, bool flag);
    bool isNgErrorDialog(u32 comId);
    void setCommnadStatusReqToError();
    void debugErrorCheck(s32& err, u32 comId);
    void updateComTimer();
    f32 getComTimer(u32 comId);
    void startComTimer(u32 comId);
    void clearComTimer(u32 comId);
    void clearComTimerAll();
    void clearFlow(s32 flowId, bool isCallback);
    void allClearFlow();
    cCtrlFlow* getFlow(s32 flowId);
    cCtrlFlow& getFlowRef(s32);
    bool reqConnectServer();
    s32 connectServerFlow();
    void connectServer();
    void disconnect(bool isAbort);
    bool login();
    bool login(MT_CTSTR oneTimeToken);
    bool logout();
    bool clientChallenge();
    MT_CTSTR getConnectionStatusStr();
    sNetworkExt::NET_STAT getConnectionStatus();
    bool isConnectServer();
    bool isLogin();
    sNetworkExt::NET_STAT getLoginStatus();
    void setSvAddr(MT_CTSTR strAddr);
    void setSvPort(u32 port);
    CGameServerListInfo* getServerListInfo(u32);
    void getLoginOnetimeToken(MT_CHAR* output);
    void setLoginOnetimeToken(MT_CTSTR str);
private:
    void getSvAddrPrivate(MT_CHAR* output) const;
    void setSvAddrPrivate(const MT_CHAR* NewValue);
    u32 getSvPortPrivate() const;
    void setSvPortPrivate(u32 NewValue);
    void getLoginOnetimeTokenPrivate(MT_CHAR* output) const;
    void setLoginOnetimeTokenPrivate(const MT_CHAR* NewValue);
public:
    MtCipher* getCipher();
    void getCommonKey(char* output);
    void clearCommonKey();
    bool isReceivedOpenKey();
    void setIsReceivedOpenKey(bool flag);
    bool getGameServerList();
    bool getGameSessionKey();
    bool getErrorMessageList();
    bool getGameSetting();
    bool getGPCourseInfo();
    bool getCharacterList();
    bool sendGetCharacterInfo(cCharacterData* pCharData, s32 id);
    bool decideCharacterId(u32 characterId);
    bool cancelDecideCharacterId();
    bool deleteCharacter(s32 id);
    bool createCharacter(cCharacterData* pCharData);
    nLoginSession::CPacket_L2C_GET_GAME_SERVER_LIST_RES* getGameServerListPacket();
    bool isWaitCreateCharacter();
    void setIsWaitCreateCharacter(bool flag);
    bool isWaitDecideCharacter();
    void setIsWaitDecideCharacter(bool flag);
    u32 getLoginWaitNum();
    void setLoginWaitNum(u32 num);
    bool isPrologueCharacter(u32 characterId);
    void copyRecvCharacterDataFromList(cCharacterData& dst, u32 index);
    u32 getNewCharacterId();
    void setNewCharacterId(u32 id);
    u32 getDecideCharacterId();
    void setDecideCharacterId(u32 id);
    u32 getDecideCharReqHandle();
    void setDecideCharReqHandle(u32);
    MtNetTime::Total getCreateCharacterUpdateTime();
    void setCreateCharacterUpdateTime(MtNetTime::Total time);
    void setCreateCharacterUpdateTime();
    bool isCreateCharacterTimeOut();
    bool ping();
    void updateRTT();
    s32 getAverageRTT();
    s32 getMaxRTT();
    s32 getSendBps();
    s32 getRecvBps();
    void reqSpecialError(s32 errCode, s32 msgNo, bool isDisconnect, bool isReturnLauncher);
    void reqSpecialFreeMsg(MT_CTSTR pMsg, bool isLogout, bool isReturnLauncher);
private:
    void reqSpecialErrorCore(s32 msgNo, MT_CTSTR pMsg, MtNetError* pErr, bool isLogout, bool isReturnLauncher);
public:
    void onConnectionClosed(s32 errCode);
    void propOnConnectionClosed();
    void OnPacket_L2C_PING_RES(nLoginSession::CPacket_L2C_PING_RES& packet);
    nLoginSession::CPacket_L2C_GET_LOGIN_SETTING_RES* getGetGameSettingPacket();
    nLoginSession::CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC* getGetErrorMessageListPacket();
    nLoginSession::CPacket_L2C_GET_CHARACTER_LIST_RES* getGetCharacterListPacket();
    nLoginSession::CPacket_L2C_NEXT_CONNECT_SERVER_NTC* getNextConnectServerPacket();
private:
    sNetworkExt::NET_STAT mStatus[18];  // offset: 0x8
    nError::ERROR_CODE mErrorCode[18];  // offset: 0x50
    f32 mComTimer[18];  // offset: 0x98
    u32 mErrorDialogHandle;  // offset: 0xe0
    bool mIsNgErrorDialog[18];  // offset: 0xe4
    cCtrlFlow mFlow[2];  // offset: 0xf8
    cSeedLoginSvConnection* mpConnection;  // offset: 0x148
    cGuardData mGuardData;  // offset: 0x150
    MtCipher mCipher;  // offset: 0x198
    bool mIsReceivedOpenKey;  // offset: 0x1f00
    MtNetTime::Total mCreateCharacterUpdateTime;  // offset: 0x1f08
    CCharacterInfo mCharacterInfoForCreate;  // offset: 0x1f10
    u32 mLoginWaitNum;  // offset: 0x21d8
    u32 mNewCharacterId;  // offset: 0x21dc
    u32 mDecideCharacterId;  // offset: 0x21e0
    u8 mDecideCharReqHandle;  // offset: 0x21e4
    bool mIsWaitCreateCharacter;  // offset: 0x21e5
    bool mIsWaitDecideCharacter;  // offset: 0x21e6
    MtNetTime::Total mLastSendPingTime;  // offset: 0x21e8
    MtNetTime::Total mAverageRTT;  // offset: 0x21f0
    MtNetTime::Total mMaxRTT;  // offset: 0x21f8
public:
    static MyDTI DTI;
    static const u64 CREATE_CHARACTER_TIME_OUT = 60000;
};

class cSeedLoginSvConnection : public cSeedServerConnection
{
    // inferred: cNetLoginServer::deleteCharacter names cSeedLoginSvConnection::mGuardData.mIsLoginSuccess
    friend class cNetLoginServer;
public:
    class MyDTI;
    struct cGuardData;
public:
    using THISCLASS = cSeedLoginSvConnection;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct cGuardData
    {
    public:
        MT_CHAR mSessionKey[64];  // offset: 0x0
        bool mIsLoginWithSessionKey;  // offset: 0x40
        bool mIsLoginSuccess;  // offset: 0x41
    };
private:
    cSeedLoginSvConnection();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
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
    cSeedLoginSvConnection(cNetLoginServer* psvt);
    cSeedLoginSvConnection(cNetLoginServer*, MT_CTSTR);
    void init();
    virtual ~cSeedLoginSvConnection();
    virtual void initialize();  // vtable slot 6
    bool isLoginSuccess() const;
    virtual void disconnect(cSeedServerConnection::eConnStatus aNextStatus);  // vtable slot 7
private:
    cNetLoginServer* getManager();
    virtual void onConnected(bool result);  // vtable slot 20
    virtual void onDisconnectedByPeer(s32 aMtNetError);  // vtable slot 21
    virtual void onSocketError(s32 aMtNetError);  // vtable slot 22
    virtual void onHandshakeDone(bool result);  // vtable slot 23
public:
    void setLoginSuccess(bool isSuccess, MT_CTSTR sessionKey);
    void reqLoginError(s32 errCode);
protected:
    virtual u32 getHandShakeSendCommandNo();  // vtable slot 25
    virtual u32 getHandShakeRecvCommandNo();  // vtable slot 26
private:
    void getSessionKeyPrivate(MT_CHAR*) const;
    void setSessionKeyPrivate(const MT_CHAR* NewValue);
    bool isLoginWithSessionKeyPrivate() const;
    void setLoginWithSessionKeyPrivate(bool NewValue);
    bool isLoginSuccessPrivate() const;
    void setLoginSuccessPrivate(bool NewValue);
public:
    void clearGetErrorMessageListPacket();
protected:
    BOOL OnPacket_L2C_NONE(CPacket* pPacket);
    BOOL OnPacket_L2C_PING_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_LOGIN_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_LOGOUT_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_GET_GAME_SERVER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_GET_GAME_SESSION_KEY_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_LOGIN_SERVER_CERT_NOTICE(CPacket* pPacket);
    BOOL OnPacket_L2C_CLIENT_CHALLENGE_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_GET_ERROR_MESSAGE_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC(CPacket* pPacket);
    BOOL OnPacket_L2C_GET_LOGIN_SETTING_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_GP_COURSE_GET_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_GET_CHARACTER_LIST_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_DECIDE_CHARACTER_ID_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_DECIDE_CANCEL_CHARACTER_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_LOGIN_WAIT_NUM_NTC(CPacket* pPacket);
    BOOL OnPacket_L2C_CREATE_CHARACTER_DATA_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_CREATE_CHARACTER_DATA_NTC(CPacket* pPacket);
    BOOL OnPacket_L2C_DELETE_CHARACTER_INFO_RES(CPacket* pPacket);
    BOOL OnPacket_L2C_NEXT_CONNECT_SERVER_NTC(CPacket* pPacket);
    BOOL OnPacket_L2C_EJECTION_NTC(CPacket* pPacket);
    virtual BOOL callOnPacketFunc(u32 index, CPacket* pPacket);  // vtable slot 18
    virtual u32 getOnPacketFuncNum();  // vtable slot 19
public:
    s32 Send_C2L_NONE();
    s32 Send_C2L_PING_REQ();
    s32 Send_C2L_LOGIN_REQ(const char* in_strOnetimeToken, u8 in_Platform);
    s32 Send_C2L_LOGOUT_REQ();
    s32 Send_C2L_GET_GAME_SERVER_LIST_REQ();
    s32 Send_C2L_GET_GAME_SESSION_KEY_REQ();
    s32 Send_C2L_CLIENT_CHALLENGE_REQ(u8 in_CommonKeySrcSize, const u8(&in_CommonKeyEnc)[259], u8 in_PasswordSrcSize, u8 in_PasswordEncSize, const u8(&in_PasswordEnc)[62]);
    s32 Send_C2L_GET_ERROR_MESSAGE_LIST_REQ();
    s32 Send_C2L_GET_LOGIN_SETTING_REQ();
    s32 Send_C2L_GP_COURSE_GET_INFO_REQ();
    s32 Send_C2L_GET_CHARACTER_LIST_REQ();
    s32 Send_C2L_DECIDE_CHARACTER_ID_REQ(u32 in_CharacterID, u32 in_ClientVersion, u8 in_Type, u8 in_RotationServerID, u32 in_WaitNum, u8 in_Counter);
    s32 Send_C2L_DECIDE_CANCEL_CHARACTER_REQ();
    s32 Send_C2L_CREATE_CHARACTER_DATA_REQ(const CCharacterInfo& in_CharacterInfo, u32 in_WaitNum, u8 in_RotationServerID);
    s32 Send_C2L_DELETE_CHARACTER_INFO_REQ(u32 in_CharacterID);
private:
    cNetLoginServer* mpManager;  // offset: 0x118
    cGuardData mGuardData;  // offset: 0x120
public:
    nLoginSession::CPacket_L2C_GET_GAME_SERVER_LIST_RES* mpGetGameServerListPacket;  // offset: 0x168
    nLoginSession::CPacket_L2C_GET_LOGIN_SETTING_RES* mpGetGameSettingPacket;  // offset: 0x170
    nLoginSession::CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC* mpGetErrorMessageListPacket;  // offset: 0x178
    nLoginSession::CPacket_L2C_GET_CHARACTER_LIST_RES* mpGetCharacterListPacket;  // offset: 0x180
    nLoginSession::CPacket_L2C_NEXT_CONNECT_SERVER_NTC* mpNextConnectServerPacket;  // offset: 0x188
    static MyDTI DTI;
protected:
    static BOOL(THISCLASS::*L2C_OnPacketFuncTbl[])(CPacket*);
    static const u32 mL2C_OnPacketFuncNum;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cNetLoginServer::getDecideCharacterId() {
    return this->mDecideCharacterId;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cSeedLoginSvConnection::isLoginSuccess() const {
    return this->mGuardData.mIsLoginSuccess;
}
