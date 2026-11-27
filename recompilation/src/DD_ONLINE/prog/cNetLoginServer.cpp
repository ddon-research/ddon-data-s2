// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cNetLoginServer.h"
#include "Protocol/LoginSession/C2L.h"
#include "Protocol/PacketData/Character.h"
#include "Protocol/PacketData/CharacterParam.h"
#include "../../generated/shared/Error.h"
#include "Protocol/PacketData/Item.h"
#include "Protocol/LoginSession/L2C.h"
#include "Protocol/PacketData/Message.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtBigInt.h"
#include "../../MT/MtCipher.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemory.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtNetDevice.h"
#include "../../MT/MtNetObject.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Server.h"
#include "Protocol/PacketData/ServerSetting.h"
#include "cCharacterData.h"
#include "cEquipData.h"
#include "cNetGameServer.h"
#include "cPacket.h"
#include "cSeedServerConnection.h"
#include "nCharacterData.h"
#include "nDialog.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "nNet.h"
#include "sDDOMain.h"
#include "sDialogBase.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sHttpClient.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cNetLoginServer::getDTI() const {
    return cNetLoginServer::DTI;
}

void* cNetLoginServer::operator new(size_t sz, u32 align) {
    return cNetLoginServer::getAllocator()->memAlloc(sz, align, cNetLoginServer::DTI.getID());
}

cNetLoginServer::cNetLoginServer() {
    DDON_STUB("cNetLoginServer::cNetLoginServer")
    /* stub */
}

cNetLoginServer::~cNetLoginServer() {
    if (mpConnection == nullptr) {
        return;
    }
    delete mpConnection;
    mpConnection = nullptr;
}

void cNetLoginServer::clearAll() {
    mLoginWaitNum = 0;
    mDecideCharReqHandle = 0;
    mIsWaitCreateCharacter = false;
    mIsWaitDecideCharacter = false;
    mMaxRTT = 0;
    mAverageRTT = 0;
    mLastSendPingTime = 0;
    mCharacterInfoForCreate.m_CharacterJobDataList.mAutoDelete = true;
    mCharacterInfoForCreate.m_CharacterEquipDataList.mAutoDelete = true;
    mCharacterInfoForCreate.m_CharacterEquipViewDataList.mAutoDelete = true;
    mCharacterInfoForCreate.m_MsgSetList.mAutoDelete = true;
    mCharacterInfoForCreate.m_ShortCutList.mAutoDelete = true;
    mCharacterInfoForCreate.m_CommunicationShortCutList.mAutoDelete = true;
    mCreateCharacterUpdateTime = 0;
}

void cNetLoginServer::move() {
    if (mpConnection != nullptr) {
        mpConnection->move();
    }
    updateRTT();
    updateComTimer();
}

void cNetLoginServer::reqErrorDialog(u32 comId, s32 errNo) {
    if (!mIsNgErrorDialog[comId]) {
        static_cast<sNetworkExt*>(sNetwork::getInstance())->requestNetworkErrorDialog(errNo);
    }
}

bool cNetLoginServer::isDispErrorDialog() {
    if (sDialogBase::getInstance() != nullptr) {
        nDialog::stInfo* t0 = sDialogBase::getInstance()->getInfo(mErrorDialogHandle);
        if (t0 != nullptr) {
            if (t0->state != nDialog::STATE_NONE) {
                if (t0->state == nDialog::STATE_END) {
                    if (t0->result != nDialog::RLT_CONTINUE) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

__attribute__((weak)) void cNetLoginServer::updateComTimer() {
    DDON_STUB("cNetLoginServer::updateComTimer")
    /* stub */
}

bool cNetLoginServer::reqConnectServer() {
    mFlow[1].mFTimer = 0.0f;
    mFlow[1].mError.mCause = 0;
    mFlow[1].mError.mNative = 0;
    mFlow[1].mCommand = 0;
    mFlow[1].mError.mNo = 0;
    mFlow[1].mRno0 = 0;
    mFlow[1].mRno1 = 0;
    mFlow[1].mIsCallback = true;
    mFlow[1].mRno0 = 0;
    return true;
}

__attribute__((weak)) s32 cNetLoginServer::connectServerFlow() {
    DDON_STUB("cNetLoginServer::connectServerFlow")
    return {};
}

__attribute__((weak)) void cNetLoginServer::disconnect(bool isAbort) {
    DDON_STUB("cNetLoginServer::disconnect")
    /* stub */
}

__attribute__((weak)) bool cNetLoginServer::logout() {
    DDON_STUB("cNetLoginServer::logout")
    return {};
}

__attribute__((weak)) bool cNetLoginServer::clientChallenge() {
    DDON_STUB("cNetLoginServer::clientChallenge")
    return {};
}

bool cNetLoginServer::isConnectServer() {
    if (mpConnection != nullptr) {
        return mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED;
    } else {
        return false;
    }
}

bool cNetLoginServer::isLogin() {
    if (mpConnection != nullptr) {
        if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
            return mpConnection->isLoginSuccess();
        }
    }
    return false;
}

bool cNetLoginServer::getGameSessionKey() {
    mStatus[8] = sNetworkExt::NET_STAT_ERROR;
    static_cast<sNetworkExt*>(sNetwork::getInstance())->reserveNetworkErrorDialog(8);
    mErrorCode[8] = nError::ERROR_CODE_CLIENT_REQ_ERROR;
    if (mpConnection != nullptr) {
        if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
            if (mpConnection->isLoginSuccess()) {
                if (mpConnection->Send_C2L_GET_GAME_SESSION_KEY_REQ() != 0) {
                    mStatus[8] = sNetworkExt::NET_STAT_REQ;
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->cancelReserveNetworkErrorDialog(8);
                    mComTimer[8] = 0.0f;
                    return true;
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) bool cNetLoginServer::getErrorMessageList() {
    DDON_STUB("cNetLoginServer::getErrorMessageList")
    return {};
}

bool cNetLoginServer::getGameSetting() {
    mStatus[10] = sNetworkExt::NET_STAT_ERROR;
    static_cast<sNetworkExt*>(sNetwork::getInstance())->reserveNetworkErrorDialog(10);
    mErrorCode[10] = nError::ERROR_CODE_CLIENT_REQ_ERROR;
    if (mpConnection != nullptr) {
        if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
            if (mpConnection->isLoginSuccess()) {
                if (mpConnection->Send_C2L_GET_LOGIN_SETTING_REQ() != 0) {
                    mStatus[10] = sNetworkExt::NET_STAT_REQ;
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->cancelReserveNetworkErrorDialog(10);
                    mComTimer[10] = 0.0f;
                    return true;
                }
            }
        }
    }
    return false;
}

bool cNetLoginServer::getGPCourseInfo() {
    mStatus[11] = sNetworkExt::NET_STAT_ERROR;
    static_cast<sNetworkExt*>(sNetwork::getInstance())->reserveNetworkErrorDialog(11);
    mErrorCode[11] = nError::ERROR_CODE_CLIENT_REQ_ERROR;
    if (mpConnection != nullptr) {
        if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
            if (mpConnection->isLoginSuccess()) {
                if (mpConnection->Send_C2L_GP_COURSE_GET_INFO_REQ() != 0) {
                    mStatus[11] = sNetworkExt::NET_STAT_REQ;
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->cancelReserveNetworkErrorDialog(11);
                    mComTimer[11] = 0.0f;
                    return true;
                }
            }
        }
    }
    return false;
}

bool cNetLoginServer::getCharacterList() {
    mStatus[12] = sNetworkExt::NET_STAT_ERROR;
    static_cast<sNetworkExt*>(sNetwork::getInstance())->reserveNetworkErrorDialog(12);
    mErrorCode[12] = nError::ERROR_CODE_CLIENT_REQ_ERROR;
    if (mpConnection != nullptr) {
        if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
            if (mpConnection->isLoginSuccess()) {
                if (mpConnection->Send_C2L_GET_CHARACTER_LIST_REQ() != 0) {
                    mStatus[12] = sNetworkExt::NET_STAT_REQ;
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->cancelReserveNetworkErrorDialog(12);
                    mComTimer[12] = 0.0f;
                    return true;
                }
            }
        }
    }
    return false;
}

bool cNetLoginServer::sendGetCharacterInfo(cCharacterData* pCharData, s32 id) {
    return true;
}

__attribute__((weak)) bool cNetLoginServer::decideCharacterId(u32 characterId) {
    DDON_STUB("cNetLoginServer::decideCharacterId")
    return {};
}

bool cNetLoginServer::cancelDecideCharacterId() {
    mStatus[15] = sNetworkExt::NET_STAT_ERROR;
    static_cast<sNetworkExt*>(sNetwork::getInstance())->reserveNetworkErrorDialog(15);
    mErrorCode[15] = nError::ERROR_CODE_CLIENT_REQ_ERROR;
    if (mpConnection != nullptr) {
        if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
            if (mpConnection->isLoginSuccess()) {
                if (mpConnection->Send_C2L_DECIDE_CANCEL_CHARACTER_REQ() != 0) {
                    mStatus[15] = sNetworkExt::NET_STAT_REQ;
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->cancelReserveNetworkErrorDialog(15);
                    mComTimer[15] = 0.0f;
                    return true;
                }
            }
        }
    }
    return false;
}

bool cNetLoginServer::deleteCharacter(s32 id) {
    mStatus[16] = sNetworkExt::NET_STAT_ERROR;
    static_cast<sNetworkExt*>(sNetwork::getInstance())->reserveNetworkErrorDialog(16);
    mErrorCode[16] = nError::ERROR_CODE_CLIENT_REQ_ERROR;
    if (mpConnection != nullptr) {
        if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
            if (mpConnection->mGuardData.mIsLoginSuccess) {
                if (id > -1) {
                    if (mpConnection->Send_C2L_DELETE_CHARACTER_INFO_REQ(static_cast<u32>(id)) != 0) {
                        mStatus[16] = sNetworkExt::NET_STAT_REQ;
                        static_cast<sNetworkExt*>(sNetwork::getInstance())->cancelReserveNetworkErrorDialog(16);
                        mComTimer[16] = 0.0f;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) bool cNetLoginServer::createCharacter(cCharacterData* pCharData) {
    DDON_STUB("cNetLoginServer::createCharacter")
    return {};
}

bool cNetLoginServer::isPrologueCharacter(u32 characterId) {
    u32 num = getGetCharacterListPacket()->m_CharacterList.mLength;
    bool b3_0;
    if (num == 0) {
        b3_0 = false;
    } else {
        MtObject* * v0_3 = getGetCharacterListPacket()->m_CharacterList.mpArray;
        for (unsigned int i0_2 = 0;;) {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_2)]) + 24)) == characterId) {
                if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_3[static_cast<int>(i0_2)]) + 368)) == 2) {
                    b3_0 = true;
                    return b3_0;
                }
            }
            if ((i0_2 + 1u) < num) {
                i0_2 += 1u;
            } else {
                break;
            }
        }
        b3_0 = false;
    }
    return b3_0;
}

__attribute__((weak)) void cNetLoginServer::copyRecvCharacterDataFromList(cCharacterData& dst, u32 index) {
    DDON_STUB("cNetLoginServer::copyRecvCharacterDataFromList")
    /* stub */
}

bool cNetLoginServer::isCreateCharacterTimeOut() {
    if (mpConnection != nullptr) {
        if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
            if (mpConnection->isLoginSuccess()) {
                MtNetTime::Total now_time = MtNetTime::mInstance.getTotalTime();
                return (mCreateCharacterUpdateTime + 60000ul) < now_time;
            }
        }
    }
    return true;
}

__attribute__((weak)) void cNetLoginServer::updateRTT() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getLoginServer()->mpConnection == nullptr) {
        return;
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getLoginServer()->mpConnection->mConnStatus != cSeedServerConnection::CONN_CONNECTED) {
        return;
    }
    if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->getLoginServer()->mpConnection->isLoginSuccess()) {
        return;
    }
    MtNetTime::Total total_time = MtNetTime::mInstance.getTotalTime();
    if ((mLastSendPingTime + 10000ul) < total_time) {
        mStatus[3] = sNetworkExt::NET_STAT_ERROR;
        static_cast<sNetworkExt*>(sNetwork::getInstance())->reserveNetworkErrorDialog(3);
        mErrorCode[3] = nError::ERROR_CODE_CLIENT_REQ_ERROR;
        if (mpConnection != nullptr) {
            if (mpConnection->mConnStatus == cSeedServerConnection::CONN_CONNECTED) {
                if (mpConnection->isLoginSuccess()) {
                    if (mpConnection->Send_C2L_PING_REQ() != 0) {
                        mStatus[3] = sNetworkExt::NET_STAT_REQ;
                        static_cast<sNetworkExt*>(sNetwork::getInstance())->cancelReserveNetworkErrorDialog(3);
                        mComTimer[3] = -1.0f;
                        mLastSendPingTime = MtNetTime::mInstance.getTotalTime();
                    }
                }
            }
        }
    }
}

void cNetLoginServer::reqSpecialError(s32 errCode, s32 msgNo, bool isDisconnect, bool isReturnLauncher) {
        MtNetError error;
        error.mNo = errCode;
        error.mNative = 0;
        error.mCause = 0;
        if (msgNo < 0) {
            msgNo = 9;
        }
        reqSpecialErrorCore(msgNo, 0, &error, isDisconnect, isReturnLauncher);
        mErrorCode[COM_DROP] = (nError::ERROR_CODE)errCode;
}

__attribute__((weak)) void cNetLoginServer::reqSpecialErrorCore(s32 msgNo, MT_CTSTR pMsg, MtNetError* pErr, bool isLogout, bool isReturnLauncher) {
    DDON_STUB("cNetLoginServer::reqSpecialErrorCore")
    /* stub */
}

__attribute__((weak)) void cNetLoginServer::onConnectionClosed(s32 errCode) {
    DDON_STUB("cNetLoginServer::onConnectionClosed")
    /* stub */
}

nLoginSession::CPacket_L2C_GET_LOGIN_SETTING_RES* cNetLoginServer::getGetGameSettingPacket() {
    return mpConnection->mpGetGameSettingPacket;
}

nLoginSession::CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC* cNetLoginServer::getGetErrorMessageListPacket() {
    return mpConnection->mpGetErrorMessageListPacket;
}

nLoginSession::CPacket_L2C_NEXT_CONNECT_SERVER_NTC* cNetLoginServer::getNextConnectServerPacket() {
    return mpConnection->mpNextConnectServerPacket;
}

inline cNetLoginServer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cNetLoginServer::MyDTI cNetLoginServer::DTI("cNetLoginServer", &::MtObject::DTI, 8704ul, 0u, 0u);

__attribute__((weak)) MtObject* cNetLoginServer::MyDTI::newInstance() const {
    DDON_STUB("cNetLoginServer::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cNetLoginServer::cCtrlFlow::getDTI() const {
    return cNetLoginServer::cCtrlFlow::DTI;
}

void cNetLoginServer::cCtrlFlow::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mRno0", &mRno0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRno1", &mRno1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mError.mNo", &mError.mNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFTimer", &mFTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsCallback", &mIsCallback, 0u, 0u);
}

MtUI* cNetLoginServer::cCtrlFlow::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cNetLoginServer::cCtrlFlow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cNetLoginServer::cCtrlFlow::MyDTI cNetLoginServer::cCtrlFlow::DTI("cNetLoginServer::cCtrlFlow", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cNetLoginServer::cCtrlFlow::MyDTI::newInstance() const {
    return new (16u) cNetLoginServer::cCtrlFlow;
}

void cSeedLoginSvConnection::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpManager", reinterpret_cast<MtObject* *>(&mpManager), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsLoginWithSessionKey", reinterpret_cast<MT_MFUNC>(&::cSeedLoginSvConnection::isLoginWithSessionKeyPrivate), reinterpret_cast<MT_MFUNC>(&::cSeedLoginSvConnection::setLoginWithSessionKeyPrivate), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mIsLoginSuccess", reinterpret_cast<MT_MFUNC>(&::cSeedLoginSvConnection::isLoginSuccessPrivate), reinterpret_cast<MT_MFUNC>(&::cSeedLoginSvConnection::setLoginSuccessPrivate), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

const MtDTI& cSeedLoginSvConnection::getDTI() const {
    return cSeedLoginSvConnection::DTI;
}

__attribute__((weak)) void cSeedLoginSvConnection::init() {
    DDON_STUB("cSeedLoginSvConnection::init")
    /* stub */
}

cSeedLoginSvConnection::~cSeedLoginSvConnection() {
    if (mpGetGameServerListPacket != nullptr) {
        delete mpGetGameServerListPacket;
        mpGetGameServerListPacket = nullptr;
    }
    if (mpGetGameSettingPacket != nullptr) {
        delete mpGetGameSettingPacket;
        mpGetGameSettingPacket = nullptr;
    }
    if (mpGetErrorMessageListPacket != nullptr) {
        delete mpGetErrorMessageListPacket;
        mpGetErrorMessageListPacket = nullptr;
    }
    if (mpGetCharacterListPacket != nullptr) {
        delete mpGetCharacterListPacket;
        mpGetCharacterListPacket = nullptr;
    }
    if (mpNextConnectServerPacket == nullptr) {
        return;
    }
    delete mpNextConnectServerPacket;
    mpNextConnectServerPacket = nullptr;
}

void cSeedLoginSvConnection::initialize() {
    this->cSeedServerConnection::initialize();
}

void cSeedLoginSvConnection::disconnect(cSeedServerConnection::eConnStatus aNextStatus) {
    mGuardData.mIsLoginSuccess = false;
    mGuardData.mSessionKey[0] = 100;
    mGuardData.mSessionKey[1] = 117;
    mGuardData.mSessionKey[2] = 115;
    mGuardData.mSessionKey[3] = 116;
    mGuardData.mSessionKey[4] = 32;
    mGuardData.mSessionKey[5] = 107;
    mGuardData.mSessionKey[6] = 101;
    mGuardData.mSessionKey[7] = 121;
    mGuardData.mSessionKey[56] = 0;
    mGuardData.mSessionKey[57] = 0;
    mGuardData.mSessionKey[58] = 0;
    mGuardData.mSessionKey[59] = 0;
    mGuardData.mSessionKey[60] = 0;
    mGuardData.mSessionKey[61] = 0;
    mGuardData.mSessionKey[62] = 0;
    mGuardData.mSessionKey[63] = 0;
    mGuardData.mSessionKey[48] = 0;
    mGuardData.mSessionKey[49] = 0;
    mGuardData.mSessionKey[50] = 0;
    mGuardData.mSessionKey[51] = 0;
    mGuardData.mSessionKey[52] = 0;
    mGuardData.mSessionKey[53] = 0;
    mGuardData.mSessionKey[54] = 0;
    mGuardData.mSessionKey[55] = 0;
    mGuardData.mSessionKey[40] = 0;
    mGuardData.mSessionKey[41] = 0;
    mGuardData.mSessionKey[42] = 0;
    mGuardData.mSessionKey[43] = 0;
    mGuardData.mSessionKey[44] = 0;
    mGuardData.mSessionKey[45] = 0;
    mGuardData.mSessionKey[46] = 0;
    mGuardData.mSessionKey[47] = 0;
    mGuardData.mSessionKey[32] = 0;
    mGuardData.mSessionKey[33] = 0;
    mGuardData.mSessionKey[34] = 0;
    mGuardData.mSessionKey[35] = 0;
    mGuardData.mSessionKey[36] = 0;
    mGuardData.mSessionKey[37] = 0;
    mGuardData.mSessionKey[38] = 0;
    mGuardData.mSessionKey[39] = 0;
    mGuardData.mSessionKey[24] = 0;
    mGuardData.mSessionKey[25] = 0;
    mGuardData.mSessionKey[26] = 0;
    mGuardData.mSessionKey[27] = 0;
    mGuardData.mSessionKey[28] = 0;
    mGuardData.mSessionKey[29] = 0;
    mGuardData.mSessionKey[30] = 0;
    mGuardData.mSessionKey[31] = 0;
    mGuardData.mSessionKey[16] = 0;
    mGuardData.mSessionKey[17] = 0;
    mGuardData.mSessionKey[18] = 0;
    mGuardData.mSessionKey[19] = 0;
    mGuardData.mSessionKey[20] = 0;
    mGuardData.mSessionKey[21] = 0;
    mGuardData.mSessionKey[22] = 0;
    mGuardData.mSessionKey[23] = 0;
    mGuardData.mSessionKey[8] = 0;
    mGuardData.mSessionKey[9] = 0;
    mGuardData.mSessionKey[10] = 0;
    mGuardData.mSessionKey[11] = 0;
    mGuardData.mSessionKey[12] = 0;
    mGuardData.mSessionKey[13] = 0;
    mGuardData.mSessionKey[14] = 0;
    mGuardData.mSessionKey[15] = 0;
    this->cSeedServerConnection::disconnect(aNextStatus);
}

void cSeedLoginSvConnection::onConnected(bool result) {
    this->cSeedServerConnection::onConnected(result);
}

void cSeedLoginSvConnection::onDisconnectedByPeer(s32 aMtNetError) {
    mpManager->onConnectionClosed(aMtNetError);
}

void cSeedLoginSvConnection::onSocketError(s32 aMtNetError) {
    mpManager->onConnectionClosed(aMtNetError);
}

void cSeedLoginSvConnection::onHandshakeDone(bool result) {
    this->cSeedServerConnection::onHandshakeDone(result);
}

__attribute__((weak)) void cSeedLoginSvConnection::reqLoginError(s32 errCode) {
    DDON_STUB("cSeedLoginSvConnection::reqLoginError")
    /* stub */
}

u32 cSeedLoginSvConnection::getHandShakeSendCommandNo() {
    return 6;
}

u32 cSeedLoginSvConnection::getHandShakeRecvCommandNo() {
    return 6;
}

bool cSeedLoginSvConnection::isLoginWithSessionKeyPrivate() const {
    return mGuardData.mIsLoginWithSessionKey;
}

void cSeedLoginSvConnection::setLoginWithSessionKeyPrivate(bool NewValue) {
    mGuardData.mIsLoginWithSessionKey = NewValue;
}

bool cSeedLoginSvConnection::isLoginSuccessPrivate() const {
    return mGuardData.mIsLoginSuccess;
}

void cSeedLoginSvConnection::setLoginSuccessPrivate(bool NewValue) {
    mGuardData.mIsLoginSuccess = NewValue;
}

BOOL cSeedLoginSvConnection::OnPacket_L2C_NONE(CPacket* pPacket) {
    return 1;
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_PING_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_PING_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_LOGIN_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_LOGIN_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_LOGOUT_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_LOGOUT_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_GET_GAME_SERVER_LIST_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_GET_GAME_SERVER_LIST_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_GET_GAME_SESSION_KEY_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_GET_GAME_SESSION_KEY_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_LOGIN_SERVER_CERT_NOTICE(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_LOGIN_SERVER_CERT_NOTICE")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_CLIENT_CHALLENGE_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_CLIENT_CHALLENGE_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_GET_ERROR_MESSAGE_LIST_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_GET_ERROR_MESSAGE_LIST_RES")
    return {};
}

BOOL cSeedLoginSvConnection::OnPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC(CPacket* pPacket) {
    nLoginSession::CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC* t0 = mpGetErrorMessageListPacket;
    if (nPacket::Read(*pPacket, t0->m_usError) != 0) {
        if (nPacket::Read(*pPacket, t0->m_ErrorMessage) != 0) {
            t0->m_bIsReceived = true;
        }
    }
    return 1;
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_GET_LOGIN_SETTING_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_GET_LOGIN_SETTING_RES")
    return {};
}

BOOL cSeedLoginSvConnection::OnPacket_L2C_GP_COURSE_GET_INFO_RES(CPacket* pPacket) {
    sGame* t0 = sGame::getInstance();
    t0->clearChargeCourse();
    if (t0->mPacketGPCourseInfo.ReadPacket(pPacket) != 0) {
        if (t0->mPacketGPCourseInfo.m_usError == 0) {
            getManager()->mErrorCode[11] = static_cast<nError::ERROR_CODE>(t0->mPacketGPCourseInfo.m_unResult);
            if (t0->mPacketGPCourseInfo.m_unResult != 0) {
                getManager()->mStatus[11] = sNetworkExt::NET_STAT_ERROR;
                if (!getManager()->mIsNgErrorDialog[11]) {
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->requestNetworkErrorDialog(static_cast<s32>(t0->mPacketGPCourseInfo.m_unResult));
                }
            } else {
                getManager()->mStatus[11] = sNetworkExt::NET_STAT_SUCCESS;
            }
        } else {
            getManager()->mErrorCode[11] = static_cast<nError::ERROR_CODE>(t0->mPacketGPCourseInfo.m_usError);
            getManager()->mStatus[11] = sNetworkExt::NET_STAT_ERROR;
            if (!getManager()->mIsNgErrorDialog[11]) {
                static_cast<sNetworkExt*>(sNetwork::getInstance())->requestNetworkErrorDialog(t0->mPacketGPCourseInfo.m_usError);
            }
        }
        sGame::getInstance()->initChargeCourse();
        return 1;
    } else {
        return 0;
    }
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_GET_CHARACTER_LIST_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_GET_CHARACTER_LIST_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_DECIDE_CHARACTER_ID_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_DECIDE_CHARACTER_ID_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_DECIDE_CANCEL_CHARACTER_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_DECIDE_CANCEL_CHARACTER_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_LOGIN_WAIT_NUM_NTC(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_LOGIN_WAIT_NUM_NTC")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_CREATE_CHARACTER_DATA_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_CREATE_CHARACTER_DATA_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_CREATE_CHARACTER_DATA_NTC(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_CREATE_CHARACTER_DATA_NTC")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_DELETE_CHARACTER_INFO_RES(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_DELETE_CHARACTER_INFO_RES")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_NEXT_CONNECT_SERVER_NTC(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_NEXT_CONNECT_SERVER_NTC")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::OnPacket_L2C_EJECTION_NTC(CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::OnPacket_L2C_EJECTION_NTC")
    return {};
}

__attribute__((weak)) BOOL cSeedLoginSvConnection::callOnPacketFunc(u32 index, CPacket* pPacket) {
    DDON_STUB("cSeedLoginSvConnection::callOnPacketFunc")
    return {};
}

u32 cSeedLoginSvConnection::getOnPacketFuncNum() {
    return 21;
}

__attribute__((weak)) s32 cSeedLoginSvConnection::Send_C2L_PING_REQ() {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(1)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                return 1;
            }
        }
    }
    return 0;
}

s32 cSeedLoginSvConnection::Send_C2L_LOGIN_REQ(const char* in_strOnetimeToken, u8 in_Platform) {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(2)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                if (nPacket::Write(sendPacket, in_strOnetimeToken) != 0) {
                    if (nPacket::Write(sendPacket, in_Platform) != 0) {
                        [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                        Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

s32 cSeedLoginSvConnection::Send_C2L_LOGOUT_REQ() {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(3)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((weak)) s32 cSeedLoginSvConnection::Send_C2L_GET_GAME_SESSION_KEY_REQ() {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(5)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                return 1;
            }
        }
    }
    return 0;
}

s32 cSeedLoginSvConnection::Send_C2L_GET_ERROR_MESSAGE_LIST_REQ() {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(7)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((weak)) s32 cSeedLoginSvConnection::Send_C2L_GET_LOGIN_SETTING_REQ() {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(8)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((weak)) s32 cSeedLoginSvConnection::Send_C2L_GP_COURSE_GET_INFO_REQ() {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(9)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((weak)) s32 cSeedLoginSvConnection::Send_C2L_GET_CHARACTER_LIST_REQ() {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(10)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((weak)) s32 cSeedLoginSvConnection::Send_C2L_DECIDE_CANCEL_CHARACTER_REQ() {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(12)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((weak)) s32 cSeedLoginSvConnection::Send_C2L_CREATE_CHARACTER_DATA_REQ(const CCharacterInfo& in_CharacterInfo, u32 in_WaitNum, u8 in_RotationServerID) {
    DDON_STUB("cSeedLoginSvConnection::Send_C2L_CREATE_CHARACTER_DATA_REQ")
    return {};
}

__attribute__((weak)) s32 cSeedLoginSvConnection::Send_C2L_DELETE_CHARACTER_INFO_REQ(u32 in_CharacterID) {
    CPacket sendPacket;
    if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
        if (nPacket::Write(sendPacket, static_cast<u16>(14)) != 0) {
            if (nPacket::Write(sendPacket, static_cast<u16>(0)) != 0) {
                if (nPacket::Write(sendPacket, in_CharacterID) != 0) {
                    [](unsigned short v, void* p) { typedef unsigned short t __attribute__((aligned(1))); *static_cast<t*>(p) = v; }(__builtin_bswap16(static_cast<unsigned short>(sendPacket.m_pWriter - sendPacket.m_pReader)), &(*sendPacket.m_pReader));
                    Send(reinterpret_cast<char*>(sendPacket.m_pReader), static_cast<DWORD>(sendPacket.m_pWriter - sendPacket.m_pReader));
                    return 1;
                }
            }
        }
    }
    return 0;
}

inline cSeedLoginSvConnection::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSeedLoginSvConnection::MyDTI cSeedLoginSvConnection::DTI("cSeedLoginSvConnection", &::cSeedServerConnection::DTI, 400ul, 0u, 0u);

__attribute__((weak)) MtObject* cSeedLoginSvConnection::MyDTI::newInstance() const {
    DDON_STUB("cSeedLoginSvConnection::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<CDataErrorMessage>::~MtTypedArray();

