// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sCaplinkManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCharSet.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtJsonReader.h"
#include "../../MT/MtMemory.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtStream.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "../../MT/MtTime.h"
#include "Protocol/PacketData/Server.h"
#include "../../XFramework/cCaplink.h"
#include "../../XFramework/cCaplinkChatGroupCreate.h"
#include "../../XFramework/cCaplinkChatGroupListGet.h"
#include "../../XFramework/cCaplinkChatGroupMemberAdd.h"
#include "../../XFramework/cCaplinkChatGroupMemberLeave.h"
#include "../../XFramework/cCaplinkChatGroupMemberListGet.h"
#include "../../XFramework/cCaplinkChatGroupMemberReject.h"
#include "../../XFramework/cCaplinkChatGroupModify.h"
#include "../../XFramework/cCaplinkChatGroupRemove.h"
#include "../../XFramework/cCaplinkChatGroupResign.h"
#include "../../XFramework/cCaplinkChatLastId.h"
#include "../../XFramework/cCaplinkChatListGet.h"
#include "../../XFramework/cCaplinkChatRead.h"
#include "../../XFramework/cCaplinkChatSend.h"
#include "../../XFramework/cCaplinkContentAchievementGet.h"
#include "../../XFramework/cCaplinkContentAchievementListGet.h"
#include "../../XFramework/cCaplinkContentAchievementRelationGet.h"
#include "../../XFramework/cCaplinkContentInvite.h"
#include "../../XFramework/cCaplinkContentInviteAvailableListGet.h"
#include "../../XFramework/cCaplinkContentInviteListGet.h"
#include "../../XFramework/cCaplinkContentInviteRemove.h"
#include "../../XFramework/cCaplinkContentInviteTotalGet.h"
#include "../../XFramework/cCaplinkContentListGet.h"
#include "../../XFramework/cCaplinkContentTotalGet.h"
#include "../../XFramework/cCaplinkContext.h"
#include "../../XFramework/cCaplinkDataDef.h"
#include "../../XFramework/cCaplinkFriendAttribute.h"
#include "../../XFramework/cCaplinkFriendEntryCancel.h"
#include "../../XFramework/cCaplinkFriendEntryRecvListGet.h"
#include "../../XFramework/cCaplinkFriendEntryReply.h"
#include "../../XFramework/cCaplinkFriendEntrySend.h"
#include "../../XFramework/cCaplinkFriendEntrySendListGet.h"
#include "../../XFramework/cCaplinkFriendListGet.h"
#include "../../XFramework/cCaplinkFriendModify.h"
#include "../../XFramework/cCaplinkFriendRelease.h"
#include "../../XFramework/cCaplinkFriendTagContentListGet.h"
#include "../../XFramework/cCaplinkFriendTagContentTotalGet.h"
#include "../../XFramework/cCaplinkFriendTagFree.h"
#include "../../XFramework/cCaplinkFriendTagFreeListGet.h"
#include "../../XFramework/cCaplinkFriendTagFreeTotalGet.h"
#include "../../XFramework/cCaplinkLogin.h"
#include "../../XFramework/cCaplinkLoginCogKey.h"
#include "../../XFramework/cCaplinkNotify.h"
#include "../../XFramework/cCaplinkNotifyAppListGet.h"
#include "../../XFramework/cCaplinkNotifyAppRead.h"
#include "../../XFramework/cCaplinkNotifyDeviceSetting.h"
#include "../../XFramework/cCaplinkNotifyDeviceSettingModify.h"
#include "../../XFramework/cCaplinkNotifyTimeGet.h"
#include "../../XFramework/cCaplinkNotifyTimeModify.h"
#include "cCaplinkObject.h"
#include "../../XFramework/cCaplinkReauth.h"
#include "../../XFramework/cCaplinkReport.h"
#include "../../XFramework/cCaplinkResourcePresetListGet.h"
#include "../../XFramework/cCaplinkResourcePresetTotalGet.h"
#include "../../XFramework/cCaplinkTagListGet.h"
#include "../../XFramework/cCaplinkTagModify.h"
#include "../../XFramework/cCaplinkTagTotalGet.h"
#include "../../XFramework/cCaplinkTagVisibleListGet.h"
#include "../../XFramework/cCaplinkTagVisibleModify.h"
#include "../../XFramework/cCaplinkUserIgnoreListGet.h"
#include "../../XFramework/cCaplinkUserIgnoreRemove.h"
#include "../../XFramework/cCaplinkUserIgnoreTotalGet.h"
#include "../../XFramework/cCaplinkUserProfileContentListGet.h"
#include "../../XFramework/cCaplinkUserProfileContentModify.h"
#include "../../XFramework/cCaplinkUserProfileGet.h"
#include "../../XFramework/cCaplinkUserProfileModify.h"
#include "../../XFramework/cCaplinkUserSearch.h"
#include "../../XFramework/cCaplinkWebsocketServerListGet.h"
#include "cCharacterData.h"
#include "cNetGameServer.h"
#include "cNetLoginServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cWebsocketClient.h"
#include "../../XFramework/nAutomation.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "../../XFramework/rGUIMessage.h"
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

const MtDTI& sCaplinkManager::getDTI() const {
    return sCaplinkManager::DTI;
}

void* sCaplinkManager::operator new(size_t sz, u32 align) {
    return sCaplinkManager::getAllocator()->memAlloc(sz, align, sCaplinkManager::DTI.getID());
}

sCaplinkManager::sCaplinkManager() {
    DDON_STUB("sCaplinkManager::sCaplinkManager")
    /* stub */
}

__attribute__((noinline)) sCaplinkManager::~sCaplinkManager() {
    DDON_STUB("sCaplinkManager::~sCaplinkManager")
    /* stub */
}

MtUI* sCaplinkManager::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sCaplinkManager::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

__attribute__((weak)) void sCaplinkManager::reset() {
}

__attribute__((weak)) void sCaplinkManager::move() {
    DDON_STUB("sCaplinkManager::move")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::init() {
    DDON_STUB("sCaplinkManager::init")
    /* stub */
}

void sCaplinkManager::end(bool isForce) {
    mIsConnection = false;
    if (!isForce) {
        if (mListener.mLength == 0) {
            if (mProfIconLoader.mLength == 0) {
                mUpdateFlag = 0;
                if (mpCaplink != nullptr) {
                    mpCaplink->wsClose();
                    mWebsocketListener.mIsConnected = false;
                    mWebsocketListener.mIsError = false;
                    mWebsocketListener.mIsRegistDevice = false;
                    mpCaplink->final();
                    if (mpCaplink != nullptr) {
                        delete mpCaplink;
                        mpCaplink = nullptr;
                    }
                }
                mIsLogin = false;
                mMyProfile.mUniqueId.mStr[0] = 0;
                mMyProfile.mUniqueId.mLength = 0;
                mNextNotifyTime.mTime = 0;
                mIsNoDispCOGError = false;
                mIsFirstBoot = true;
                mRnoMain = 0;
                mTimeCountRno = 0;
                mTimeoutTimer = 0.0f;
                mIsMaintenanceNow = false;
                mIsInfoFriendOnline = false;
                mIsInfoFriendRequest = false;
                mIsInfoFriendConsent = false;
                mIsInfoFriendModify = false;
                mIsInfoInvite = false;
                mIsInfoNewChat = false;
                mIsInfoMessage = false;
                mIsMaintenance = false;
            }
        }
    } else {
        mUpdateFlag = 0;
        if (mpCaplink != nullptr) {
            mpCaplink->wsClose();
            mWebsocketListener.mIsConnected = false;
            mWebsocketListener.mIsError = false;
            mWebsocketListener.mIsRegistDevice = false;
            mpCaplink->final();
            if (mpCaplink != nullptr) {
                delete mpCaplink;
                mpCaplink = nullptr;
            }
        }
        mIsLogin = false;
        mMyProfile.mUniqueId.mStr[0] = 0;
        mMyProfile.mUniqueId.mLength = 0;
        mNextNotifyTime.mTime = 0;
        mIsNoDispCOGError = false;
        mIsFirstBoot = true;
        mRnoMain = 0;
        mTimeCountRno = 0;
        mTimeoutTimer = 0.0f;
        mIsMaintenanceNow = false;
        mIsInfoFriendOnline = false;
        mIsInfoFriendRequest = false;
        mIsInfoFriendConsent = false;
        mIsInfoFriendModify = false;
        mIsInfoInvite = false;
        mIsInfoNewChat = false;
        mIsInfoMessage = false;
        mIsMaintenance = false;
    }
}

MT_CTSTR sCaplinkManager::getContentId() {
    return "DDO";
}

__attribute__((weak)) MT_CTSTR sCaplinkManager::getHpUrl() {
    DDON_STUB("sCaplinkManager::getHpUrl")
    return {};
}

__attribute__((weak)) void sCaplinkManager::addListener(nCaplink::ContextListener* pListener, sCaplinkManager::CALLBACK_FUNC pCallback) {
    DDON_STUB("sCaplinkManager::addListener")
    /* stub */
}

void sCaplinkManager::updateListener() {
    if (mListener.mLength != 0) {
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            static_cast<sCaplinkManager::cCaplinkListenerQueue*>(mListener.getBuffer()[static_cast<int>(i0_3)])->update();
            v1_0 = mListener.mLength;
            if ((i0_3 + 1u) < v1_0) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
        if (static_cast<int>(v1_0 - 1u) > -1) {
            u32 v2_0 = v1_0;
            int v2_10 = static_cast<int>(v1_0 - 1u);
            u32 v2_11 = v1_0;
            u32 v3_0;
            u32 v3_1;
            int v3_2;
            int v3_4;
            u32 v4_0;
            u32 v5_0;
            for (;;) {
                if (!static_cast<sCaplinkManager::cCaplinkListenerQueue*>(mListener.getBuffer()[v2_10])->isEnd()) {
                    v5_0 = v2_0;
                } else {
                    if (mListener.mAutoDelete) {
                        if (mListener.getBuffer()[v2_10] != nullptr) {
                            delete mListener.getBuffer()[v2_10];
                            if (static_cast<int>(v2_11) >= static_cast<int>(mListener.mLength)) {
                                v4_0 = mListener.mLength;
                                goto region_7383fb;
                            } else {
                                v3_0 = mListener.mLength;
                                v3_1 = mListener.mLength;
                                v3_2 = v2_10;
                                v3_4 = static_cast<int>(v2_11);
                            }
                        } else {
                            if (static_cast<int>(v2_11) >= static_cast<int>(v2_0)) {
                                v4_0 = v2_0;
                                goto region_7383fb;
                            } else {
                                v3_0 = v2_0;
                                v3_1 = v2_0;
                                v3_2 = v2_10;
                                v3_4 = static_cast<int>(v2_11);
                            }
                        }
                    } else {
                        if (static_cast<int>(v2_11) >= static_cast<int>(v2_0)) {
                            v4_0 = v2_0;
                            goto region_7383fb;
                        } else {
                            v3_0 = v2_0;
                            v3_1 = v2_0;
                            v3_2 = v2_10;
                            v3_4 = static_cast<int>(v2_11);
                        }
                    }
                    for (;;) {
                        mListener.mpArray[v3_2] = mListener.mpArray[v3_4];
                        if (v3_1 != static_cast<unsigned int>(v3_4 + 1)) {
                            v3_2 = v3_4;
                            v3_4 = v3_4 + 1;
                        } else {
                            v4_0 = v3_0;
                            break;
                        }
                    }
                    region_7383fb:;
                    mListener.mLength = v4_0 - 1u;
                    v5_0 = v4_0 - 1u;
                }
                if ((v2_10 - 1) > -1) {
                    v2_0 = v5_0;
                    v2_11 = v2_10;
                    v2_10 = v2_10 - 1;
                } else {
                    break;
                }
            }
        }
    }
}

bool sCaplinkManager::isDispErrorDialog() {
    if (mListener.mLength != 0) {
        u32 i = 0;
        do {
            if (!static_cast<sCaplinkManager::cCaplinkListenerQueue*>(mListener.getBuffer()[static_cast<int>(i)])->isDispError()) {
                return true;
            }
            i += 1u;
        } while (i < mListener.mLength);
    }
    return false;
}

__attribute__((weak)) void sCaplinkManager::loginCogKey(MT_CTSTR session_key, MT_CTSTR content_user_id, bool isNoDispCOGError) {
    DDON_STUB("sCaplinkManager::loginCogKey")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::loginCogKeyCallback() {
    const nCaplink::cUserBaseInfo* pInfo = reinterpret_cast<const nCaplink::cUserBaseInfo*>(reinterpret_cast<const char*>(&mLoginCogKeyAns) + 0x28);
    const char* t1 = reinterpret_cast<const char*>(pInfo) + 0x8;
    char* t2 = reinterpret_cast<char*>(&mMyProfile.mUniqueId) + 0x4;
    s32 t3 = static_cast<s32>(strlen(t1));
    if (t3 > 32) {
        t3 = 32;
    }
    *reinterpret_cast<u32*>(&mMyProfile.mUniqueId) = static_cast<u32>(t3);
    if (static_cast<u32>(t3) != 0u) {
        memcpy(t2, t1, static_cast<u32>(t3));
        t2[static_cast<u32>(t3)] = '\0';
    } else {
        t2[0] = '\0';
    }
    t1 = reinterpret_cast<const char*>(pInfo) + 0x29;
    t2 = reinterpret_cast<char*>(&mMyProfile.mNickname) + 0x4;
    t3 = static_cast<s32>(strlen(t1));
    if (t3 > 80) {
        t3 = 80;
    }
    *reinterpret_cast<u32*>(&mMyProfile.mNickname) = static_cast<u32>(t3);
    if (static_cast<u32>(t3) != 0u) {
        memcpy(t2, t1, static_cast<u32>(t3));
        t2[static_cast<u32>(t3)] = '\0';
    } else {
        t2[0] = '\0';
    }
    if (*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(&mLoginCogKeyAns) + 0x20)) {
        mIsLogin = true;
        mRnoMain = RNO_MAIN_INIT;
    }
}

__attribute__((weak)) void sCaplinkManager::userSearch(s32 searchType, MT_CTSTR keyword, s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::userSearch")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::userSearchCallback() {
}

__attribute__((weak)) void sCaplinkManager::userProfileContentListGet(MT_CTSTR unique_id, s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::userProfileContentListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::userProfileContentListGetCallback() {
}

void sCaplinkManager::userProfileContentModify(MT_CTSTR content_id, MT_CTSTR character_name, MT_CTSTR comment, s8 online_privacy, s8 visible) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mUserProfileContentModifyAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (content_id != nullptr) {
                    if (character_name != nullptr) {
                        if (comment != nullptr) {
                            if (mpCaplink->reqUserProfileContentModify(static_cast<nCaplink::ContextListener*>(&mUserProfileContentModifyAns), content_id, character_name, comment, online_privacy, visible)) {
                                addListener(static_cast<nCaplink::ContextListener*>(&mUserProfileContentModifyAns), &::sCaplinkManager::userProfileContentModifyCallback);
                            }
                        }
                    }
                }
            }
        } else {
            mUserProfileContentModifyAns.nCaplink::ContextListener::init();
            mUserProfileContentModifyAns.mStatus = 3;
        }
    } else {
        mUserProfileContentModifyAns.nCaplink::ContextListener::init();
        mUserProfileContentModifyAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::userProfileContentModifyCallback() {
}

void sCaplinkManager::userProfileGet(MT_CTSTR unique_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            memset(static_cast<void*>(&mUserProfileGetAns.mUserProfile), 0, 1704ul);
            mUserProfileGetAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (unique_id != nullptr) {
                    if (mpCaplink->reqUserProfileGet(static_cast<nCaplink::ContextListener*>(&mUserProfileGetAns), unique_id)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mUserProfileGetAns), &::sCaplinkManager::userProfileGetCallback);
                        if (unique_id != (&mMyProfile.mUniqueId.mStr[0])) {
                            mIsReqMyProfile = strcmp(&mMyProfile.mUniqueId.mStr[0], unique_id) == 0;
                        } else {
                            mIsReqMyProfile = true;
                        }
                    }
                }
            }
        } else {
            memset(static_cast<void*>(&mUserProfileGetAns.mUserProfile), 0, 1704ul);
            mUserProfileGetAns.nCaplink::ContextListener::init();
            mUserProfileGetAns.mStatus = 3;
        }
    } else {
        memset(static_cast<void*>(&mUserProfileGetAns.mUserProfile), 0, 1704ul);
        mUserProfileGetAns.nCaplink::ContextListener::init();
        mUserProfileGetAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::userProfileGetCallback() {
    DDON_STUB("sCaplinkManager::userProfileGetCallback")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::userProfileModify(MT_CTSTR nickname, s32 icon_id, MT_CTSTR comment, s32 timeline_skin_id, s32 profile_skin_id, s8 timeline_privacy, s8 profile_privacy, s8 captalk_privacy, s8 find_search) {
    DDON_STUB("sCaplinkManager::userProfileModify")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::userProfileModifyCallback() {
}

__attribute__((weak)) void sCaplinkManager::userIgnoreListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::userIgnoreListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::userIgnoreListGetCallback() {
}

void sCaplinkManager::userIgnoreRemove(MT_CTSTR unique_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mUserIgnoreRemoveAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (mpCaplink->reqUserIgnoreRemove(static_cast<nCaplink::ContextListener*>(&mUserIgnoreRemoveAns), unique_id)) {
                    addListener(static_cast<nCaplink::ContextListener*>(&mUserIgnoreRemoveAns), &::sCaplinkManager::userIgnoreRemoveCallback);
                }
            }
        } else {
            mUserIgnoreRemoveAns.nCaplink::ContextListener::init();
            mUserIgnoreRemoveAns.mStatus = 3;
        }
    } else {
        mUserIgnoreRemoveAns.nCaplink::ContextListener::init();
        mUserIgnoreRemoveAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::userIgnoreRemoveCallback() {
}

__attribute__((weak)) void sCaplinkManager::friendEntrySend(MT_CTSTR unique_id, MT_CTSTR message, s32 cause) {
    DDON_STUB("sCaplinkManager::friendEntrySend")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::friendEntrySendCallback() {
}

void sCaplinkManager::friendEntryCancel(MT_CTSTR unique_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mFriendEntryCancelAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (unique_id != nullptr) {
                    if (mpCaplink->reqFriendEntryCancel(static_cast<nCaplink::ContextListener*>(&mFriendEntryCancelAns), unique_id)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mFriendEntryCancelAns), &::sCaplinkManager::friendEntryCancelCallback);
                    }
                }
            }
        } else {
            mFriendEntryCancelAns.nCaplink::ContextListener::init();
            mFriendEntryCancelAns.mStatus = 3;
        }
    } else {
        mFriendEntryCancelAns.nCaplink::ContextListener::init();
        mFriendEntryCancelAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::friendEntryCancelCallback() {
}

__attribute__((weak)) void sCaplinkManager::friendEntryRecvListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::friendEntryRecvListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::friendEntryRecvListGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::friendEntrySendListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::friendEntrySendListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::friendEntrySendListGetCallback() {
}

void sCaplinkManager::friendEntryReply(MT_CTSTR unique_id, s32 reply) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mFriendEntryReplyAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (unique_id != nullptr) {
                    if (mpCaplink->reqFriendEntryReply(static_cast<nCaplink::ContextListener*>(&mFriendEntryReplyAns), unique_id, reply)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mFriendEntryReplyAns), &::sCaplinkManager::friendEntryReplyCallback);
                    }
                }
            }
        } else {
            mFriendEntryReplyAns.nCaplink::ContextListener::init();
            mFriendEntryReplyAns.mStatus = 3;
        }
    } else {
        mFriendEntryReplyAns.nCaplink::ContextListener::init();
        mFriendEntryReplyAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::friendEntryReplyCallback() {
}

__attribute__((weak)) void sCaplinkManager::friendListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::friendListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::friendListGetCallback() {
}

void sCaplinkManager::friendAttribute(MT_CTSTR unique_id, s8 attribute) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mFriendAttributeAns.mFriendTotal = 0;
            mFriendAttributeAns.mFriendLimmit = 0;
            mFriendAttributeAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (unique_id != nullptr) {
                    if (mpCaplink->reqFriendAttribute(static_cast<nCaplink::ContextListener*>(&mFriendAttributeAns), unique_id, attribute)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mFriendAttributeAns), &::sCaplinkManager::friendAttributeCallback);
                    }
                }
            }
        } else {
            mFriendAttributeAns.mFriendTotal = 0;
            mFriendAttributeAns.mFriendLimmit = 0;
            mFriendAttributeAns.nCaplink::ContextListener::init();
            mFriendAttributeAns.mStatus = 3;
        }
    } else {
        mFriendAttributeAns.mFriendTotal = 0;
        mFriendAttributeAns.mFriendLimmit = 0;
        mFriendAttributeAns.nCaplink::ContextListener::init();
        mFriendAttributeAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::friendAttributeCallback() {
}

__attribute__((weak)) void sCaplinkManager::friendTagContentListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::friendTagContentListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::friendTagContentListGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::friendTagFreeListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::friendTagFreeListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::friendTagFreeListGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::friendTagFree(MT_CTSTR unique_id, MtArray* free_tag_alive_info_list) {
    DDON_STUB("sCaplinkManager::friendTagFree")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::friendTagFreeCallback() {
}

void sCaplinkManager::friendRelease(MT_CTSTR unique_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mFriendReleaseAns.nCaplink::ContextListener::init();
            mFriendReleaseAns.mTotal = 0;
            mFriendReleaseAns.mLimmit = 0;
            if (mpCaplink != nullptr) {
                if (unique_id != nullptr) {
                    if (mpCaplink->reqFriendRelease(static_cast<nCaplink::ContextListener*>(&mFriendReleaseAns), unique_id)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mFriendReleaseAns), &::sCaplinkManager::friendReleaseCallback);
                    }
                }
            }
        } else {
            mFriendReleaseAns.nCaplink::ContextListener::init();
            mFriendReleaseAns.mTotal = 0;
            mFriendReleaseAns.mLimmit = 0;
            mFriendReleaseAns.mStatus = 3;
        }
    } else {
        mFriendReleaseAns.nCaplink::ContextListener::init();
        mFriendReleaseAns.mTotal = 0;
        mFriendReleaseAns.mLimmit = 0;
        mFriendReleaseAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::friendReleaseCallback() {
}

__attribute__((weak)) void sCaplinkManager::tagListGet() {
    DDON_STUB("sCaplinkManager::tagListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::tagListGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::tagModify(MtArray* tag_info_list) {
    DDON_STUB("sCaplinkManager::tagModify")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::tagModifyCallback() {
}

__attribute__((weak)) void sCaplinkManager::contentListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::contentListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::contentListGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::contentInviteAvailableListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::contentInviteAvailableListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::contentInviteAvailableListGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::contentInvite(MT_CTSTR unique_id, MT_CTSTR message) {
    DDON_STUB("sCaplinkManager::contentInvite")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::contentInviteCallback() {
}

void sCaplinkManager::contentInviteTotalGet() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mContentInviteTotalGetAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (mpCaplink->reqContentInviteTotalGet(static_cast<nCaplink::ContextListener*>(&mContentInviteTotalGetAns), &mDateContentInvite.mStr[0])) {
                    addListener(static_cast<nCaplink::ContextListener*>(&mContentInviteTotalGetAns), &::sCaplinkManager::contentInviteTotalGetCallback);
                }
            }
        } else {
            mContentInviteTotalGetAns.nCaplink::ContextListener::init();
            mContentInviteTotalGetAns.mStatus = 3;
        }
    } else {
        mContentInviteTotalGetAns.nCaplink::ContextListener::init();
        mContentInviteTotalGetAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::contentInviteTotalGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::contentInviteListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::contentInviteListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::contentInviteListGetCallback() {
}

void sCaplinkManager::contentInviteRemove(MT_CTSTR unique_id, MT_CTSTR content_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mContentInviteRemoveAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (unique_id != nullptr) {
                    if (content_id != nullptr) {
                        if (mpCaplink->reqContentInviteRemove(static_cast<nCaplink::ContextListener*>(&mContentInviteRemoveAns), unique_id, content_id)) {
                            addListener(static_cast<nCaplink::ContextListener*>(&mContentInviteRemoveAns), &::sCaplinkManager::contentInviteRemoveCallback);
                        }
                    }
                }
            }
        } else {
            mContentInviteRemoveAns.nCaplink::ContextListener::init();
            mContentInviteRemoveAns.mStatus = 3;
        }
    } else {
        mContentInviteRemoveAns.nCaplink::ContextListener::init();
        mContentInviteRemoveAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::contentInviteRemoveCallback() {
}

__attribute__((weak)) void sCaplinkManager::contentAchievementGet(MT_CTSTR content_id) {
    DDON_STUB("sCaplinkManager::contentAchievementGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::contentAchievementGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::contentAchievementListGet(MT_CTSTR content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::contentAchievementListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::contentAchievementListGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::contentAchievementRelationGet(MT_CTSTR filtering_content_id, s32 category, s32 alive, s32 orderby, s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::contentAchievementRelationGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::contentAchievementRelationGetCallback() {
}

__attribute__((weak)) void sCaplinkManager::chatListGet(s32 id_type, MT_CTSTR unique_id, s32 offset_id, s32 count) {
    DDON_STUB("sCaplinkManager::chatListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::chatListGetCallback() {
}

void sCaplinkManager::chatLastId(s8 id_type, MT_CTSTR unique_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatLastIdAns.nCaplink::ContextListener::init();
            mChatLastIdAns.mLastChatId = 0;
            if (mpCaplink != nullptr) {
                if (unique_id != nullptr) {
                    if (mpCaplink->reqChatLastId(static_cast<nCaplink::ContextListener*>(&mChatLastIdAns), id_type, unique_id)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mChatLastIdAns), &::sCaplinkManager::chatLastIdCallback);
                    }
                }
            }
        } else {
            mChatLastIdAns.nCaplink::ContextListener::init();
            mChatLastIdAns.mLastChatId = 0;
            mChatLastIdAns.mStatus = 3;
        }
    } else {
        mChatLastIdAns.nCaplink::ContextListener::init();
        mChatLastIdAns.mLastChatId = 0;
        mChatLastIdAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatLastIdCallback() {
}

__attribute__((weak)) void sCaplinkManager::chatSend(s32 chat_type, MT_CTSTR unique_id, MT_CTSTR message, s32 stamp_id, MT_CTSTR image, MT_CTSTR position) {
    DDON_STUB("sCaplinkManager::chatSend")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::chatSendCallback() {
}

void sCaplinkManager::chatRead(s32 chat_type, MT_CTSTR unique_id, s32 chat_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatReadAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (unique_id != nullptr) {
                    if (mpCaplink->reqChatRead(static_cast<nCaplink::ContextListener*>(&mChatReadAns), chat_type, unique_id, chat_id)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mChatReadAns), &::sCaplinkManager::chatReadCallback);
                    }
                }
            }
        } else {
            mChatReadAns.nCaplink::ContextListener::init();
            mChatReadAns.mStatus = 3;
        }
    } else {
        mChatReadAns.nCaplink::ContextListener::init();
        mChatReadAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatReadCallback() {
}

__attribute__((weak)) void sCaplinkManager::chatGroupCreate(MT_CTSTR group_name, s32 group_skin_id, MT_CTSTR group_message) {
    DDON_STUB("sCaplinkManager::chatGroupCreate")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::chatGroupCreateCallback() {
}

void sCaplinkManager::chatGroupResign(MT_CTSTR group_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatGroupResignAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (group_id != nullptr) {
                    if (mpCaplink->reqChatGroupResign(static_cast<nCaplink::ContextListener*>(&mChatGroupResignAns), group_id)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mChatGroupResignAns), &::sCaplinkManager::chatGroupResignCallback);
                    }
                }
            }
        } else {
            mChatGroupResignAns.nCaplink::ContextListener::init();
            mChatGroupResignAns.mStatus = 3;
        }
    } else {
        mChatGroupResignAns.nCaplink::ContextListener::init();
        mChatGroupResignAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatGroupResignCallback() {
}

void sCaplinkManager::chatGroupRemove(s32 chat_type, MT_CTSTR group_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatGroupRemoveAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (group_id != nullptr) {
                    if (mpCaplink->reqChatGroupRemove(static_cast<nCaplink::ContextListener*>(&mChatGroupRemoveAns), chat_type, group_id)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mChatGroupRemoveAns), &::sCaplinkManager::chatGroupRemoveCallback);
                    }
                }
            }
        } else {
            mChatGroupRemoveAns.nCaplink::ContextListener::init();
            mChatGroupRemoveAns.mStatus = 3;
        }
    } else {
        mChatGroupRemoveAns.nCaplink::ContextListener::init();
        mChatGroupRemoveAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatGroupRemoveCallback() {
}

void sCaplinkManager::chatGroupMemberAdd(MT_CTSTR group_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatGroupMemberAddAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (group_id != nullptr) {
                    if (mpCaplink->reqChatGroupMemberAdd(static_cast<nCaplink::ContextListener*>(&mChatGroupMemberAddAns), group_id, static_cast<MtArray*>(&mChatMember))) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mChatGroupMemberAddAns), &::sCaplinkManager::chatGroupMemberAddCallback);
                    }
                }
            }
        } else {
            mChatGroupMemberAddAns.nCaplink::ContextListener::init();
            mChatGroupMemberAddAns.mStatus = 3;
        }
    } else {
        mChatGroupMemberAddAns.nCaplink::ContextListener::init();
        mChatGroupMemberAddAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatGroupMemberAddCallback() {
}

void sCaplinkManager::chatGroupMemberListGet(MT_CTSTR group_id, s32 offset, s32 count) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatGroupMemberListGetAns.nCaplink::ChatGroupMemberListGetAns::init();
            if (mpCaplink != nullptr) {
                if (group_id != nullptr) {
                    if (mpCaplink->reqChatGroupMemberListGet(static_cast<nCaplink::ContextListener*>(&mChatGroupMemberListGetAns), group_id, offset, count)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mChatGroupMemberListGetAns), &::sCaplinkManager::chatGroupMemberListGetCallback);
                    }
                }
            }
        } else {
            mChatGroupMemberListGetAns.nCaplink::ChatGroupMemberListGetAns::init();
            mChatGroupMemberListGetAns.mStatus = 3;
        }
    } else {
        mChatGroupMemberListGetAns.nCaplink::ChatGroupMemberListGetAns::init();
        mChatGroupMemberListGetAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatGroupMemberListGetCallback() {
}

void sCaplinkManager::chatGroupMemberReject(MT_CTSTR group_id, MT_CTSTR unique_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatGroupMemberRejectAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (group_id != nullptr) {
                    if (unique_id != nullptr) {
                        if (mpCaplink->reqChatGroupMemberReject(static_cast<nCaplink::ContextListener*>(&mChatGroupMemberRejectAns), group_id, unique_id)) {
                            addListener(static_cast<nCaplink::ContextListener*>(&mChatGroupMemberRejectAns), &::sCaplinkManager::chatGroupMemberRejectCallback);
                        }
                    }
                }
            }
        } else {
            mChatGroupMemberRejectAns.nCaplink::ContextListener::init();
            mChatGroupMemberRejectAns.mStatus = 3;
        }
    } else {
        mChatGroupMemberRejectAns.nCaplink::ContextListener::init();
        mChatGroupMemberRejectAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatGroupMemberRejectCallback() {
}

void sCaplinkManager::chatGroupMemberLeave(MT_CTSTR group_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatGroupMemberLeaveAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (group_id != nullptr) {
                    if (mpCaplink->reqChatGroupMemberLeave(static_cast<nCaplink::ContextListener*>(&mChatGroupMemberLeaveAns), group_id)) {
                        addListener(static_cast<nCaplink::ContextListener*>(&mChatGroupMemberLeaveAns), &::sCaplinkManager::chatGroupMemberLeaveCallback);
                    }
                }
            }
        } else {
            mChatGroupMemberLeaveAns.nCaplink::ContextListener::init();
            mChatGroupMemberLeaveAns.mStatus = 3;
        }
    } else {
        mChatGroupMemberLeaveAns.nCaplink::ContextListener::init();
        mChatGroupMemberLeaveAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatGroupMemberLeaveCallback() {
}

__attribute__((weak)) void sCaplinkManager::chatGroupListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::chatGroupListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::chatGroupListGetCallback() {
}

void sCaplinkManager::chatGroupModify(MT_CTSTR group_id, MT_CTSTR group_name, s32 group_skin_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mChatGroupModifyAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (group_id != nullptr) {
                    if (group_name != nullptr) {
                        if (mpCaplink->reqChatGroupModify(static_cast<nCaplink::ContextListener*>(&mChatGroupModifyAns), group_id, group_name, group_skin_id)) {
                            addListener(static_cast<nCaplink::ContextListener*>(&mChatGroupModifyAns), &::sCaplinkManager::chatGroupModifyCallback);
                        }
                    }
                }
            }
        } else {
            mChatGroupModifyAns.nCaplink::ContextListener::init();
            mChatGroupModifyAns.mStatus = 3;
        }
    } else {
        mChatGroupModifyAns.nCaplink::ContextListener::init();
        mChatGroupModifyAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::chatGroupModifyCallback() {
}

__attribute__((weak)) void sCaplinkManager::resourcePresetListGet(s8 resource_type, s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::resourcePresetListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::resourcePresetListGetCallback() {
}

void sCaplinkManager::notify() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mNotifyAns.nCaplink::ContextListener::init();
            mNotifyAns.mContentTotal = 0;
            mNotifyAns.mContentUpdate = 0;
            mNotifyAns.mResourcePresetTotal = 0;
            mNotifyAns.mResourcePresetUpdate = 0;
            mNotifyAns.mProfileUpdate = 0;
            mNotifyAns.mStampUpdate = 0;
            mNotifyAns.mStampTotal = 0;
            mNotifyAns.mLastPostId = 0;
            mNotifyAns.mAppNotifyTotal = 0;
            mNotifyAns.mTagTotal = 0;
            mNotifyAns.mContentInviteTotal = 0;
            mNotifyAns.mFriendTagFreeTotal = 0;
            mNotifyAns.mFriendRequestReceiveTotal = 0;
            mNotifyAns.mFriendTotal = 0;
            mNotifyAns.mFriendTagContentTotal = 0;
            if (mpCaplink != nullptr) {
                if (mpCaplink->reqNotify(static_cast<nCaplink::ContextListener*>(&mNotifyAns), &mDateFriendList.mStr[0], &mDateFriendContentTagList.mStr[0], &mDateFriendFreeTag.mStr[0], &mDateFriendRecv.mStr[0], &mDateTag.mStr[0], &mDateContentInvite.mStr[0], &mDateStamp.mStr[0], &mDateContentList.mStr[0], &mDatePresetResource.mStr[0], &mDateChatGroupList.mStr[0])) {
                    mIsNoDispError = true;
                    addListener(static_cast<nCaplink::ContextListener*>(&mNotifyAns), &::sCaplinkManager::notifyCallback);
                    mRnoMain = 17;
                }
            }
        } else {
            mNotifyAns.nCaplink::ContextListener::init();
            mNotifyAns.mContentTotal = 0;
            mNotifyAns.mContentUpdate = 0;
            mNotifyAns.mResourcePresetTotal = 0;
            mNotifyAns.mResourcePresetUpdate = 0;
            mNotifyAns.mProfileUpdate = 0;
            mNotifyAns.mStampUpdate = 0;
            mNotifyAns.mStampTotal = 0;
            mNotifyAns.mLastPostId = 0;
            mNotifyAns.mAppNotifyTotal = 0;
            mNotifyAns.mTagTotal = 0;
            mNotifyAns.mContentInviteTotal = 0;
            mNotifyAns.mFriendTagFreeTotal = 0;
            mNotifyAns.mFriendRequestReceiveTotal = 0;
            mNotifyAns.mFriendTotal = 0;
            mNotifyAns.mFriendTagContentTotal = 0;
            mNotifyAns.mStatus = 3;
        }
    } else {
        mNotifyAns.nCaplink::ContextListener::init();
        mNotifyAns.mContentTotal = 0;
        mNotifyAns.mContentUpdate = 0;
        mNotifyAns.mResourcePresetTotal = 0;
        mNotifyAns.mResourcePresetUpdate = 0;
        mNotifyAns.mProfileUpdate = 0;
        mNotifyAns.mStampUpdate = 0;
        mNotifyAns.mStampTotal = 0;
        mNotifyAns.mLastPostId = 0;
        mNotifyAns.mAppNotifyTotal = 0;
        mNotifyAns.mTagTotal = 0;
        mNotifyAns.mContentInviteTotal = 0;
        mNotifyAns.mFriendTagFreeTotal = 0;
        mNotifyAns.mFriendRequestReceiveTotal = 0;
        mNotifyAns.mFriendTotal = 0;
        mNotifyAns.mFriendTagContentTotal = 0;
        mNotifyAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::notifyCallback() {
    DDON_STUB("sCaplinkManager::notifyCallback")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::notifyAppListGet(s32 offset, s32 count) {
    DDON_STUB("sCaplinkManager::notifyAppListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::notifyAppListGetCallback() {
}

void sCaplinkManager::notifyAppRead(s32 notify_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mNotifyAppReadAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (mpCaplink->reqNotifyAppRead(static_cast<nCaplink::ContextListener*>(&mNotifyAppReadAns), notify_id)) {
                    addListener(static_cast<nCaplink::ContextListener*>(&mNotifyAppReadAns), &::sCaplinkManager::notifyAppReadCallback);
                }
            }
        } else {
            mNotifyAppReadAns.nCaplink::ContextListener::init();
            mNotifyAppReadAns.mStatus = 3;
        }
    } else {
        mNotifyAppReadAns.nCaplink::ContextListener::init();
        mNotifyAppReadAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::notifyAppReadCallback() {
}

void sCaplinkManager::notifyDeviceSetting() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mNotifyDeviceSettingAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (mpCaplink->reqNotifyDeviceSetting(static_cast<nCaplink::ContextListener*>(&mNotifyDeviceSettingAns))) {
                    addListener(static_cast<nCaplink::ContextListener*>(&mNotifyDeviceSettingAns), &::sCaplinkManager::notifyDeviceSettingCallback);
                }
            }
        } else {
            mNotifyDeviceSettingAns.nCaplink::ContextListener::init();
            mNotifyDeviceSettingAns.mStatus = 3;
        }
    } else {
        mNotifyDeviceSettingAns.nCaplink::ContextListener::init();
        mNotifyDeviceSettingAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::notifyDeviceSettingCallback() {
}

void sCaplinkManager::notifyDeviceSettingModify(s8 all, s8 profile, s8 fri, s8 timeline, s8 chat, s8 game) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mNotifyDeviceSettingModifyAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (mpCaplink->reqNotifyDeviceSettingModify(static_cast<nCaplink::ContextListener*>(&mNotifyDeviceSettingModifyAns), all, profile, fri, timeline, chat, game)) {
                    addListener(static_cast<nCaplink::ContextListener*>(&mNotifyDeviceSettingModifyAns), &::sCaplinkManager::notifyDeviceSettingModifyCallback);
                }
            }
        } else {
            mNotifyDeviceSettingModifyAns.nCaplink::ContextListener::init();
            mNotifyDeviceSettingModifyAns.mStatus = 3;
        }
    } else {
        mNotifyDeviceSettingModifyAns.nCaplink::ContextListener::init();
        mNotifyDeviceSettingModifyAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::notifyDeviceSettingModifyCallback() {
}

void sCaplinkManager::notifyTimeGet() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mNotifyTimeGetAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (mpCaplink->reqNotifyTimeGet(static_cast<nCaplink::ContextListener*>(&mNotifyTimeGetAns))) {
                    addListener(static_cast<nCaplink::ContextListener*>(&mNotifyTimeGetAns), &::sCaplinkManager::notifyTimeGetCallback);
                }
            }
        } else {
            mNotifyTimeGetAns.nCaplink::ContextListener::init();
            mNotifyTimeGetAns.mStatus = 3;
        }
    } else {
        mNotifyTimeGetAns.nCaplink::ContextListener::init();
        mNotifyTimeGetAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::notifyTimeGetCallback() {
}

void sCaplinkManager::notifyTimeModify(s8 morning, s8 afternoon, s8 evening, s8 midnight) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
        if (mIsConnection) {
            init();
            mNotifyTimeModifyAns.nCaplink::ContextListener::init();
            if (mpCaplink != nullptr) {
                if (mpCaplink->reqNotifyTimeModify(static_cast<nCaplink::ContextListener*>(&mNotifyTimeModifyAns), morning, afternoon, midnight, evening)) {
                    addListener(static_cast<nCaplink::ContextListener*>(&mNotifyTimeModifyAns), &::sCaplinkManager::notifyTimeModifyCallback);
                }
            }
        } else {
            mNotifyTimeModifyAns.nCaplink::ContextListener::init();
            mNotifyTimeModifyAns.mStatus = 3;
        }
    } else {
        mNotifyTimeModifyAns.nCaplink::ContextListener::init();
        mNotifyTimeModifyAns.mStatus = 3;
    }
}

__attribute__((weak)) void sCaplinkManager::notifyTimeModifyCallback() {
}

__attribute__((weak)) void sCaplinkManager::report(MT_CTSTR unique_id, s8 place, MT_CTSTR detail) {
    DDON_STUB("sCaplinkManager::report")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::reportCallback() {
}

__attribute__((weak)) void sCaplinkManager::websocketServerListGet() {
    DDON_STUB("sCaplinkManager::websocketServerListGet")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::websocketServerListGetCallback() {
}

bool sCaplinkManager::isMyUniqueId(MT_CTSTR unique_id) {
    if (unique_id != nullptr) {
        if (unique_id != (&mMyProfile.mUniqueId.mStr[0])) {
            return strcmp(&mMyProfile.mUniqueId.mStr[0], unique_id) == 0;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) void sCaplinkManager::updateMyProfile(const sCaplinkManager::cProfile& prof) {
    DDON_STUB("sCaplinkManager::updateMyProfile")
    /* stub */
}

__attribute__((weak)) bool sCaplinkManager::setupWebsocket() {
    DDON_STUB("sCaplinkManager::setupWebsocket")
    return {};
}

const sCaplinkManager::cIconUrl* sCaplinkManager::getIconUrlFromIndex(u32 index) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (index < mIconUrl.mLength) {
        return static_cast<const cIconUrl*>(mIconUrl.getBuffer()[static_cast<int>(index)]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void sCaplinkManager::addIconUrl(s32 id, s16 category, s16 type, MT_CTSTR url) {
    DDON_STUB("sCaplinkManager::addIconUrl")
    /* stub */
}

__attribute__((weak)) u32 sCaplinkManager::getIconIndex(MT_CTSTR url) {
    DDON_STUB("sCaplinkManager::getIconIndex")
    return {};
}

__attribute__((weak)) void sCaplinkManager::loadProfIcon(s32 id, MT_CTSTR url) {
    DDON_STUB("sCaplinkManager::loadProfIcon")
    /* stub */
}

bool sCaplinkManager::isLoadingProfIcon(s32 id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (mProfIconLoader.mLength == 0) {
        return false;
    }
    u32 i = 0;
    do {
        if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mProfIconLoader.getBuffer()[static_cast<int>(i)]) + 288)) == static_cast<unsigned int>(id)) {
            return true;
        }
        i += 1u;
    } while (i < mProfIconLoader.mLength);
    return false;
}

bool sCaplinkManager::setupProfIcon() {
    if (mRnoProfIcon != 2) {
        if (mRnoProfIcon == 1) {
            sCaplinkManager::getInstance()->resourcePresetListGet(static_cast<s8>(0), static_cast<s32>(mUpdateOffset), static_cast<s32>(mUpdateCount));
            mRnoProfIcon = 2;
            return false;
        } else {
            if (mRnoProfIcon == 0) {
                mUpdateOffset = 0;
                mUpdateCount = 100;
                mRnoProfIcon = 1;
                return false;
            } else {
                mResourcePresetListGetAns.nCaplink::ContextListener::init();
                mResourcePresetListGetAns.mResourceInfoTbl.mAutoDelete = true;
                if (mResourcePresetListGetAns.mResourceInfoTbl.mLength == 0) {
                    if (mResourcePresetListGetAns.mResourceInfoTbl.mpArray != nullptr) {
                        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mResourcePresetListGetAns.mResourceInfoTbl.mpArray));
                    }
                    mResourcePresetListGetAns.mResourceInfoTbl.mpArray = nullptr;
                    mResourcePresetListGetAns.mResourceInfoTbl.mBufsiz = 0;
                    mResourcePresetListGetAns.mResourceInfoTbl.mLength = 0;
                    return true;
                } else {
                    u32 v0_0 = mResourcePresetListGetAns.mResourceInfoTbl.mLength;
                    unsigned int i0_3 = 0;
                    u32 v1_0;
                    for (;;) {
                        if (mResourcePresetListGetAns.mResourceInfoTbl.mpArray[i0_3] == nullptr) {
                            v1_0 = v0_0;
                        } else {
                            delete mResourcePresetListGetAns.mResourceInfoTbl.mpArray[i0_3];
                            v1_0 = mResourcePresetListGetAns.mResourceInfoTbl.mLength;
                        }
                        if ((i0_3 + 1u) < v1_0) {
                            v0_0 = v1_0;
                            i0_3 += 1u;
                        } else {
                            break;
                        }
                    }
                    if (mResourcePresetListGetAns.mResourceInfoTbl.mpArray != nullptr) {
                        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mResourcePresetListGetAns.mResourceInfoTbl.mpArray));
                    }
                    mResourcePresetListGetAns.mResourceInfoTbl.mpArray = nullptr;
                    mResourcePresetListGetAns.mResourceInfoTbl.mBufsiz = 0;
                    mResourcePresetListGetAns.mResourceInfoTbl.mLength = 0;
                    return true;
                }
            }
        }
    } else {
        if (mResourcePresetListGetAns.getStatus() != 0) {
            if (mResourcePresetListGetAns.getStatus() == 3) {
                mRnoProfIcon = 3;
                return false;
            } else {
                if (mResourcePresetListGetAns.getStatus() != 2) {
                    return false;
                } else {
                    mRnoProfIcon = 3;
                    u32 v3_8 = mResourcePresetListGetAns.mResourceInfoTbl.mLength;
                    if (v3_8 != 0) {
                        for (u32 i = 0;;) {
                            MtObject* t0 = mResourcePresetListGetAns.mResourceInfoTbl.mpArray[i];
                            if (t0 != nullptr) {
                                if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 355)) != 0) {
                                    s32 t1 = static_cast<nCaplink::cResourceInfo*>(t0)->getResourceId();
                                    if (static_cast<nCaplink::cResourceInfo*>(t0)->getResourceCategoryId() == 6) {
                                        if (static_cast<nCaplink::cResourceInfo*>(t0)->getResourceType() == 11) {
                                            mProfIconNum = mProfIconNum + 1u;
                                            addIconUrl(t1, static_cast<s16>(6), static_cast<s16>(11), reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 98))));
                                        } else {
                                            if (static_cast<nCaplink::cResourceInfo*>(t0)->getResourceType() == 81) {
                                                addIconUrl(t1, static_cast<short>(static_cast<nCaplink::cResourceInfo*>(t0)->getResourceCategoryId()), static_cast<s16>(81), reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 98))));
                                            }
                                        }
                                    } else {
                                        if (static_cast<nCaplink::cResourceInfo*>(t0)->getResourceType() == 81) {
                                            addIconUrl(t1, static_cast<short>(static_cast<nCaplink::cResourceInfo*>(t0)->getResourceCategoryId()), static_cast<s16>(81), reinterpret_cast<MT_CTSTR>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 98))));
                                        }
                                    }
                                }
                            }
                            if (v3_8 != (i + 1u)) {
                                i = i + 1u;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        } else {
            mRnoProfIcon = 3;
            return false;
        }
        if (static_cast<unsigned int>(mResourcePresetListGetAns.mTotal) < (mUpdateCount + mUpdateOffset)) {
            return false;
        } else {
            mUpdateOffset = mUpdateCount + mUpdateOffset;
        }
        mRnoProfIcon = 1;
        return false;
    }
}

__attribute__((weak)) u32 sCaplinkManager::getFriendIndex(MT_CTSTR unique_id) {
    DDON_STUB("sCaplinkManager::getFriendIndex")
    return {};
}

__attribute__((weak)) void sCaplinkManager::setFriendData(const sCaplinkManager::cFriendData& in_data) {
    DDON_STUB("sCaplinkManager::setFriendData")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::deleteFriendData(MT_CTSTR unique_id) {
    DDON_STUB("sCaplinkManager::deleteFriendData")
    /* stub */
}

u32 sCaplinkManager::getContentIndex(MT_CTSTR content_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    u32 v0_8 = mContentData.mLength;
    if (content_id != nullptr) {
        if (v0_8 == 0) {
            return 0;
        } else {
            MtObject* * v0_9 = mContentData.getBuffer();
            for (unsigned int i0_3 = 0;;) {
                if (v0_9[static_cast<int>(i0_3)] != nullptr) {
                    if (strcmp(reinterpret_cast<const char*>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_9[static_cast<int>(i0_3)]) + 8))), content_id) == 0) {
                        return i0_3;
                    }
                }
                if ((i0_3 + 1u) < v0_8) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    return v0_8;
}

__attribute__((weak)) bool sCaplinkManager::isContentDisp(const sCaplinkManager::ContentBit& bit) {
    DDON_STUB("sCaplinkManager::isContentDisp")
    return {};
}

__attribute__((weak)) u32 sCaplinkManager::getFriendRecvIndex(MT_CTSTR unique_id) {
    DDON_STUB("sCaplinkManager::getFriendRecvIndex")
    return {};
}

__attribute__((weak)) void sCaplinkManager::deleteFriendRecvData(MT_CTSTR unique_id) {
    DDON_STUB("sCaplinkManager::deleteFriendRecvData")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::setGroupChatData(const sCaplinkManager::cGroupChatData& in_data) {
    DDON_STUB("sCaplinkManager::setGroupChatData")
    /* stub */
}

u32 sCaplinkManager::getGroupChatIndex(s8 id_type, MT_CTSTR unique_id) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    u32 v0_9 = mGroupChatData.mLength;
    if (unique_id != nullptr) {
        if (v0_9 == 0) {
            return 0;
        } else {
            MtObject* * v0_8 = mGroupChatData.getBuffer();
            for (unsigned int i0_3 = 0;;) {
                if (v0_8[static_cast<int>(i0_3)] != nullptr) {
                    if (static_cast<unsigned int>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_8[static_cast<int>(i0_3)]) + 265)) == static_cast<unsigned int>(id_type)) {
                        if (strcmp(reinterpret_cast<const char*>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_8[static_cast<int>(i0_3)]) + 8))), unique_id) == 0) {
                            return i0_3;
                        }
                    }
                }
                if ((i0_3 + 1u) < v0_9) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    return v0_9;
}

__attribute__((weak)) void sCaplinkManager::addChatMember(MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon) {
    DDON_STUB("sCaplinkManager::addChatMember")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::deleteChatMember(MT_CTSTR unique_id) {
    DDON_STUB("sCaplinkManager::deleteChatMember")
    /* stub */
}

bool sCaplinkManager::isChatMember(MT_CTSTR unique_id) {
    if (unique_id != nullptr) {
        u32 v0_9 = mChatMember.mLength;
        if (v0_9 == 0) {
            return false;
        } else {
            MtObject* * v0_8 = mChatMember.getBuffer();
            for (unsigned int i0_3 = 0;;) {
                if (v0_8[static_cast<int>(i0_3)] != nullptr) {
                    if (strcmp(reinterpret_cast<const char*>(&(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_8[static_cast<int>(i0_3)]) + 8))), unique_id) == 0) {
                        return true;
                    }
                }
                if ((i0_3 + 1u) < v0_9) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) void sCaplinkManager::sortChatList() {
    DDON_STUB("sCaplinkManager::sortChatList")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::clearChatList() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
    }
    mChatList.mId.mStr[0] = 0;
    mChatList.mId.mLength = 0;
    mChatList.mChatGroupName.mStr[0] = 0;
    mChatList.mChatGroupName.mLength = 0;
    mChatList.mIdType = 0;
    mChatList.mChatStatus = 0;
    mChatList.mLastChatId = 0;
    mChatList.mTopId = 0;
    mChatList.mBottomId = 0;
    mChatList.mIsForward = false;
    mChatList.mIsFirst = false;
    if (mChatList.mUser.mLength != 0) {
        u32 v0_0 = mChatList.mUser.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mChatList.mUser.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mChatList.mUser.mpArray[i0_3];
                v1_0 = mChatList.mUser.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mChatList.mUser.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mChatList.mUser.mpArray));
    }
    mChatList.mUser.mpArray = nullptr;
    mChatList.mUser.mBufsiz = 0;
    mChatList.mUser.mLength = 0;
    if (mChatList.mChat.mLength != 0) {
        u32 v3_0 = mChatList.mChat.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mChatList.mChat.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mChatList.mChat.mpArray[i3_3];
                v4_0 = mChatList.mChat.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mChatList.mChat.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mChatList.mChat.mpArray));
    }
    mChatList.mChat.mpArray = nullptr;
    mChatList.mChat.mBufsiz = 0;
    mChatList.mChat.mLength = 0;
    if (mChatList.mJoin.mLength != 0) {
        u32 v6_0 = mChatList.mJoin.mLength;
        unsigned int i6_3 = 0;
        u32 v7_0;
        for (;;) {
            if (mChatList.mJoin.mpArray[i6_3] == nullptr) {
                v7_0 = v6_0;
            } else {
                delete mChatList.mJoin.mpArray[i6_3];
                v7_0 = mChatList.mJoin.mLength;
            }
            if ((i6_3 + 1u) < v7_0) {
                v6_0 = v7_0;
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mChatList.mJoin.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mChatList.mJoin.mpArray));
    }
    mChatList.mJoin.mpArray = nullptr;
    mChatList.mJoin.mBufsiz = 0;
    mChatList.mJoin.mLength = 0;
}

__attribute__((weak)) void sCaplinkManager::addChatList(const nCaplink::WebsocketNotifyChat* notify) {
    if (notify == nullptr) {
        return;
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (mChatList.mIdType == static_cast<int>(notify->mIdType)) {
        if ((&mChatList.mId.mStr[0]) != (&notify->mId[0])) {
            if (strcmp(&mChatList.mId.mStr[0], &notify->mId[0]) == 0) {
                mChatList.mIsForward = true;
                addChatList(notify->mChatId, &notify->mUniqueId[0], &notify->mNickname[0], &notify->mIcon[0], &notify->mMessage[0], &notify->mCreatedAt[0]);
                compactionChatList();
            }
        } else {
            mChatList.mIsForward = true;
            addChatList(notify->mChatId, &notify->mUniqueId[0], &notify->mNickname[0], &notify->mIcon[0], &notify->mMessage[0], &notify->mCreatedAt[0]);
            compactionChatList();
        }
    }
    if ((&mMyProfile.mUniqueId.mStr[0]) != (&notify->mUniqueId[0])) {
        if (strcmp(&mMyProfile.mUniqueId.mStr[0], &notify->mUniqueId[0]) != 0) {
            if (notify->mIdType != 3) {
                if (static_cast<unsigned int>(notify->mIdType - 1) <= 1) {
                    if (!mIsInfoNewChat) {
                        static_cast<sGUIExt*>(sGUI::getInstance())->requestInfomation(sGUIExt::INFO_FLAG_CAPLINK_NEW_CHAT, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr));
                        mIsInfoNewChat = true;
                    }
                }
            } else {
                if (!mIsInfoMessage) {
                    static_cast<sGUIExt*>(sGUI::getInstance())->requestInfomation(sGUIExt::INFO_FLAG_CAPLINK_MESSAGE, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr));
                    mIsInfoMessage = true;
                }
            }
        }
    }
}

__attribute__((weak)) void sCaplinkManager::addChatList(s32 chat_id, MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR message, MT_CTSTR date) {
    DDON_STUB("sCaplinkManager::addChatList")
    /* stub */
}

__attribute__((weak)) sCaplinkManager::cChatInfo* sCaplinkManager::createChatInfo(s32 chat_id, MT_CTSTR unique_id, MT_CTSTR nickname, MT_CTSTR icon, MT_CTSTR message, MT_CTSTR date) {
    DDON_STUB("sCaplinkManager::createChatInfo")
    return nullptr;
}

nCaplink::cUserBaseInfo* sCaplinkManager::getChatListUser(u32 index) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
            }
        }
    }
    if (index < mChatList.mUser.mLength) {
        return static_cast<nCaplink::cUserBaseInfo*>(mChatList.mUser.getBuffer()[static_cast<int>(index)]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void sCaplinkManager::compactionChatList() {
    DDON_STUB("sCaplinkManager::compactionChatList")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::addChatJoin(s32 chat_id, bool is_join) {
    DDON_STUB("sCaplinkManager::addChatJoin")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::resetDate() {
    DDON_STUB("sCaplinkManager::resetDate")
    /* stub */
}

void sCaplinkManager::resetList() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
    }
    static_cast<sGUIExt*>(sGUI::getInstance())->deleteCaplinkIcon();
    mRnoProfIcon = 0;
    for (unsigned int i0_0 = 0;;) {
        cFriendData* t0 = mFriendData;
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&t0[i0_0]) + 140) = 0;
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&t0[i0_0]) + 132) = 0;
        t0[i0_0].mFreeTag = 0;
        t0[i0_0].mFlag = 0;
        t0[i0_0].mIconIndex = 0xFF;
        t0[i0_0].mPrivacy = -1;
        t0[i0_0].mAttribute = -1;
        t0[i0_0].mName[79] = 0;
        t0[i0_0].mName[80] = 0;
        t0[i0_0].mName[71] = 0;
        t0[i0_0].mName[72] = 0;
        t0[i0_0].mName[73] = 0;
        t0[i0_0].mName[74] = 0;
        t0[i0_0].mName[75] = 0;
        t0[i0_0].mName[76] = 0;
        t0[i0_0].mName[77] = 0;
        t0[i0_0].mName[78] = 0;
        t0[i0_0].mName[63] = 0;
        t0[i0_0].mName[64] = 0;
        t0[i0_0].mName[65] = 0;
        t0[i0_0].mName[66] = 0;
        t0[i0_0].mName[67] = 0;
        t0[i0_0].mName[68] = 0;
        t0[i0_0].mName[69] = 0;
        t0[i0_0].mName[70] = 0;
        t0[i0_0].mName[55] = 0;
        t0[i0_0].mName[56] = 0;
        t0[i0_0].mName[57] = 0;
        t0[i0_0].mName[58] = 0;
        t0[i0_0].mName[59] = 0;
        t0[i0_0].mName[60] = 0;
        t0[i0_0].mName[61] = 0;
        t0[i0_0].mName[62] = 0;
        t0[i0_0].mName[47] = 0;
        t0[i0_0].mName[48] = 0;
        t0[i0_0].mName[49] = 0;
        t0[i0_0].mName[50] = 0;
        t0[i0_0].mName[51] = 0;
        t0[i0_0].mName[52] = 0;
        t0[i0_0].mName[53] = 0;
        t0[i0_0].mName[54] = 0;
        t0[i0_0].mName[39] = 0;
        t0[i0_0].mName[40] = 0;
        t0[i0_0].mName[41] = 0;
        t0[i0_0].mName[42] = 0;
        t0[i0_0].mName[43] = 0;
        t0[i0_0].mName[44] = 0;
        t0[i0_0].mName[45] = 0;
        t0[i0_0].mName[46] = 0;
        t0[i0_0].mName[31] = 0;
        t0[i0_0].mName[32] = 0;
        t0[i0_0].mName[33] = 0;
        t0[i0_0].mName[34] = 0;
        t0[i0_0].mName[35] = 0;
        t0[i0_0].mName[36] = 0;
        t0[i0_0].mName[37] = 0;
        t0[i0_0].mName[38] = 0;
        t0[i0_0].mName[23] = 0;
        t0[i0_0].mName[24] = 0;
        t0[i0_0].mName[25] = 0;
        t0[i0_0].mName[26] = 0;
        t0[i0_0].mName[27] = 0;
        t0[i0_0].mName[28] = 0;
        t0[i0_0].mName[29] = 0;
        t0[i0_0].mName[30] = 0;
        t0[i0_0].mName[15] = 0;
        t0[i0_0].mName[16] = 0;
        t0[i0_0].mName[17] = 0;
        t0[i0_0].mName[18] = 0;
        t0[i0_0].mName[19] = 0;
        t0[i0_0].mName[20] = 0;
        t0[i0_0].mName[21] = 0;
        t0[i0_0].mName[22] = 0;
        t0[i0_0].mName[7] = 0;
        t0[i0_0].mName[8] = 0;
        t0[i0_0].mName[9] = 0;
        t0[i0_0].mName[10] = 0;
        t0[i0_0].mName[11] = 0;
        t0[i0_0].mName[12] = 0;
        t0[i0_0].mName[13] = 0;
        t0[i0_0].mName[14] = 0;
        t0[i0_0].mUniqueId[32] = 0;
        t0[i0_0].mName[0] = 0;
        t0[i0_0].mName[1] = 0;
        t0[i0_0].mName[2] = 0;
        t0[i0_0].mName[3] = 0;
        t0[i0_0].mName[4] = 0;
        t0[i0_0].mName[5] = 0;
        t0[i0_0].mName[6] = 0;
        t0[i0_0].mUniqueId[24] = 0;
        t0[i0_0].mUniqueId[25] = 0;
        t0[i0_0].mUniqueId[26] = 0;
        t0[i0_0].mUniqueId[27] = 0;
        t0[i0_0].mUniqueId[28] = 0;
        t0[i0_0].mUniqueId[29] = 0;
        t0[i0_0].mUniqueId[30] = 0;
        t0[i0_0].mUniqueId[31] = 0;
        t0[i0_0].mUniqueId[16] = 0;
        t0[i0_0].mUniqueId[17] = 0;
        t0[i0_0].mUniqueId[18] = 0;
        t0[i0_0].mUniqueId[19] = 0;
        t0[i0_0].mUniqueId[20] = 0;
        t0[i0_0].mUniqueId[21] = 0;
        t0[i0_0].mUniqueId[22] = 0;
        t0[i0_0].mUniqueId[23] = 0;
        t0[i0_0].mUniqueId[8] = 0;
        t0[i0_0].mUniqueId[9] = 0;
        t0[i0_0].mUniqueId[10] = 0;
        t0[i0_0].mUniqueId[11] = 0;
        t0[i0_0].mUniqueId[12] = 0;
        t0[i0_0].mUniqueId[13] = 0;
        t0[i0_0].mUniqueId[14] = 0;
        t0[i0_0].mUniqueId[15] = 0;
        t0[i0_0].mUniqueId[0] = 0;
        t0[i0_0].mUniqueId[1] = 0;
        t0[i0_0].mUniqueId[2] = 0;
        t0[i0_0].mUniqueId[3] = 0;
        t0[i0_0].mUniqueId[4] = 0;
        t0[i0_0].mUniqueId[5] = 0;
        t0[i0_0].mUniqueId[6] = 0;
        t0[i0_0].mUniqueId[7] = 0;
        if (i0_0 != 999) {
            i0_0 = i0_0 + 1u;
        } else {
            break;
        }
    }
    mFreeTag[0].mTagName[80] = 0;
    mFreeTag[0].mTagName[72] = 0;
    mFreeTag[0].mTagName[73] = 0;
    mFreeTag[0].mTagName[74] = 0;
    mFreeTag[0].mTagName[75] = 0;
    mFreeTag[0].mTagName[76] = 0;
    mFreeTag[0].mTagName[77] = 0;
    mFreeTag[0].mTagName[78] = 0;
    mFreeTag[0].mTagName[79] = 0;
    mFreeTag[0].mTagName[64] = 0;
    mFreeTag[0].mTagName[65] = 0;
    mFreeTag[0].mTagName[66] = 0;
    mFreeTag[0].mTagName[67] = 0;
    mFreeTag[0].mTagName[68] = 0;
    mFreeTag[0].mTagName[69] = 0;
    mFreeTag[0].mTagName[70] = 0;
    mFreeTag[0].mTagName[71] = 0;
    mFreeTag[0].mTagName[56] = 0;
    mFreeTag[0].mTagName[57] = 0;
    mFreeTag[0].mTagName[58] = 0;
    mFreeTag[0].mTagName[59] = 0;
    mFreeTag[0].mTagName[60] = 0;
    mFreeTag[0].mTagName[61] = 0;
    mFreeTag[0].mTagName[62] = 0;
    mFreeTag[0].mTagName[63] = 0;
    mFreeTag[0].mTagName[48] = 0;
    mFreeTag[0].mTagName[49] = 0;
    mFreeTag[0].mTagName[50] = 0;
    mFreeTag[0].mTagName[51] = 0;
    mFreeTag[0].mTagName[52] = 0;
    mFreeTag[0].mTagName[53] = 0;
    mFreeTag[0].mTagName[54] = 0;
    mFreeTag[0].mTagName[55] = 0;
    mFreeTag[0].mTagName[40] = 0;
    mFreeTag[0].mTagName[41] = 0;
    mFreeTag[0].mTagName[42] = 0;
    mFreeTag[0].mTagName[43] = 0;
    mFreeTag[0].mTagName[44] = 0;
    mFreeTag[0].mTagName[45] = 0;
    mFreeTag[0].mTagName[46] = 0;
    mFreeTag[0].mTagName[47] = 0;
    mFreeTag[0].mTagName[32] = 0;
    mFreeTag[0].mTagName[33] = 0;
    mFreeTag[0].mTagName[34] = 0;
    mFreeTag[0].mTagName[35] = 0;
    mFreeTag[0].mTagName[36] = 0;
    mFreeTag[0].mTagName[37] = 0;
    mFreeTag[0].mTagName[38] = 0;
    mFreeTag[0].mTagName[39] = 0;
    mFreeTag[0].mTagName[24] = 0;
    mFreeTag[0].mTagName[25] = 0;
    mFreeTag[0].mTagName[26] = 0;
    mFreeTag[0].mTagName[27] = 0;
    mFreeTag[0].mTagName[28] = 0;
    mFreeTag[0].mTagName[29] = 0;
    mFreeTag[0].mTagName[30] = 0;
    mFreeTag[0].mTagName[31] = 0;
    mFreeTag[0].mTagName[16] = 0;
    mFreeTag[0].mTagName[17] = 0;
    mFreeTag[0].mTagName[18] = 0;
    mFreeTag[0].mTagName[19] = 0;
    mFreeTag[0].mTagName[20] = 0;
    mFreeTag[0].mTagName[21] = 0;
    mFreeTag[0].mTagName[22] = 0;
    mFreeTag[0].mTagName[23] = 0;
    mFreeTag[0].mTagName[8] = 0;
    mFreeTag[0].mTagName[9] = 0;
    mFreeTag[0].mTagName[10] = 0;
    mFreeTag[0].mTagName[11] = 0;
    mFreeTag[0].mTagName[12] = 0;
    mFreeTag[0].mTagName[13] = 0;
    mFreeTag[0].mTagName[14] = 0;
    mFreeTag[0].mTagName[15] = 0;
    mFreeTag[0].mTagName[0] = 0;
    mFreeTag[0].mTagName[1] = 0;
    mFreeTag[0].mTagName[2] = 0;
    mFreeTag[0].mTagName[3] = 0;
    mFreeTag[0].mTagName[4] = 0;
    mFreeTag[0].mTagName[5] = 0;
    mFreeTag[0].mTagName[6] = 0;
    mFreeTag[0].mTagName[7] = 0;
    mFreeTag[9].mTagId = 0;
    mFreeTag[1].mTagName[80] = 0;
    mFreeTag[1].mTagName[76] = 0;
    mFreeTag[1].mTagName[77] = 0;
    mFreeTag[1].mTagName[78] = 0;
    mFreeTag[1].mTagName[79] = 0;
    mFreeTag[1].mTagName[68] = 0;
    mFreeTag[1].mTagName[69] = 0;
    mFreeTag[1].mTagName[70] = 0;
    mFreeTag[1].mTagName[71] = 0;
    mFreeTag[1].mTagName[72] = 0;
    mFreeTag[1].mTagName[73] = 0;
    mFreeTag[1].mTagName[74] = 0;
    mFreeTag[1].mTagName[75] = 0;
    mFreeTag[1].mTagName[60] = 0;
    mFreeTag[1].mTagName[61] = 0;
    mFreeTag[1].mTagName[62] = 0;
    mFreeTag[1].mTagName[63] = 0;
    mFreeTag[1].mTagName[64] = 0;
    mFreeTag[1].mTagName[65] = 0;
    mFreeTag[1].mTagName[66] = 0;
    mFreeTag[1].mTagName[67] = 0;
    mFreeTag[1].mTagName[52] = 0;
    mFreeTag[1].mTagName[53] = 0;
    mFreeTag[1].mTagName[54] = 0;
    mFreeTag[1].mTagName[55] = 0;
    mFreeTag[1].mTagName[56] = 0;
    mFreeTag[1].mTagName[57] = 0;
    mFreeTag[1].mTagName[58] = 0;
    mFreeTag[1].mTagName[59] = 0;
    mFreeTag[1].mTagName[44] = 0;
    mFreeTag[1].mTagName[45] = 0;
    mFreeTag[1].mTagName[46] = 0;
    mFreeTag[1].mTagName[47] = 0;
    mFreeTag[1].mTagName[48] = 0;
    mFreeTag[1].mTagName[49] = 0;
    mFreeTag[1].mTagName[50] = 0;
    mFreeTag[1].mTagName[51] = 0;
    mFreeTag[1].mTagName[36] = 0;
    mFreeTag[1].mTagName[37] = 0;
    mFreeTag[1].mTagName[38] = 0;
    mFreeTag[1].mTagName[39] = 0;
    mFreeTag[1].mTagName[40] = 0;
    mFreeTag[1].mTagName[41] = 0;
    mFreeTag[1].mTagName[42] = 0;
    mFreeTag[1].mTagName[43] = 0;
    mFreeTag[1].mTagName[28] = 0;
    mFreeTag[1].mTagName[29] = 0;
    mFreeTag[1].mTagName[30] = 0;
    mFreeTag[1].mTagName[31] = 0;
    mFreeTag[1].mTagName[32] = 0;
    mFreeTag[1].mTagName[33] = 0;
    mFreeTag[1].mTagName[34] = 0;
    mFreeTag[1].mTagName[35] = 0;
    mFreeTag[1].mTagName[20] = 0;
    mFreeTag[1].mTagName[21] = 0;
    mFreeTag[1].mTagName[22] = 0;
    mFreeTag[1].mTagName[23] = 0;
    mFreeTag[1].mTagName[24] = 0;
    mFreeTag[1].mTagName[25] = 0;
    mFreeTag[1].mTagName[26] = 0;
    mFreeTag[1].mTagName[27] = 0;
    mFreeTag[1].mTagName[12] = 0;
    mFreeTag[1].mTagName[13] = 0;
    mFreeTag[1].mTagName[14] = 0;
    mFreeTag[1].mTagName[15] = 0;
    mFreeTag[1].mTagName[16] = 0;
    mFreeTag[1].mTagName[17] = 0;
    mFreeTag[1].mTagName[18] = 0;
    mFreeTag[1].mTagName[19] = 0;
    mFreeTag[1].mTagName[4] = 0;
    mFreeTag[1].mTagName[5] = 0;
    mFreeTag[1].mTagName[6] = 0;
    mFreeTag[1].mTagName[7] = 0;
    mFreeTag[1].mTagName[8] = 0;
    mFreeTag[1].mTagName[9] = 0;
    mFreeTag[1].mTagName[10] = 0;
    mFreeTag[1].mTagName[11] = 0;
    mFreeTag[0].mTagId = 0;
    mFreeTag[1].mTagName[0] = 0;
    mFreeTag[1].mTagName[1] = 0;
    mFreeTag[1].mTagName[2] = 0;
    mFreeTag[1].mTagName[3] = 0;
    mFreeTag[2].mTagName[80] = 0;
    mFreeTag[2].mTagName[76] = 0;
    mFreeTag[2].mTagName[77] = 0;
    mFreeTag[2].mTagName[78] = 0;
    mFreeTag[2].mTagName[79] = 0;
    mFreeTag[2].mTagName[68] = 0;
    mFreeTag[2].mTagName[69] = 0;
    mFreeTag[2].mTagName[70] = 0;
    mFreeTag[2].mTagName[71] = 0;
    mFreeTag[2].mTagName[72] = 0;
    mFreeTag[2].mTagName[73] = 0;
    mFreeTag[2].mTagName[74] = 0;
    mFreeTag[2].mTagName[75] = 0;
    mFreeTag[2].mTagName[60] = 0;
    mFreeTag[2].mTagName[61] = 0;
    mFreeTag[2].mTagName[62] = 0;
    mFreeTag[2].mTagName[63] = 0;
    mFreeTag[2].mTagName[64] = 0;
    mFreeTag[2].mTagName[65] = 0;
    mFreeTag[2].mTagName[66] = 0;
    mFreeTag[2].mTagName[67] = 0;
    mFreeTag[2].mTagName[52] = 0;
    mFreeTag[2].mTagName[53] = 0;
    mFreeTag[2].mTagName[54] = 0;
    mFreeTag[2].mTagName[55] = 0;
    mFreeTag[2].mTagName[56] = 0;
    mFreeTag[2].mTagName[57] = 0;
    mFreeTag[2].mTagName[58] = 0;
    mFreeTag[2].mTagName[59] = 0;
    mFreeTag[2].mTagName[44] = 0;
    mFreeTag[2].mTagName[45] = 0;
    mFreeTag[2].mTagName[46] = 0;
    mFreeTag[2].mTagName[47] = 0;
    mFreeTag[2].mTagName[48] = 0;
    mFreeTag[2].mTagName[49] = 0;
    mFreeTag[2].mTagName[50] = 0;
    mFreeTag[2].mTagName[51] = 0;
    mFreeTag[2].mTagName[36] = 0;
    mFreeTag[2].mTagName[37] = 0;
    mFreeTag[2].mTagName[38] = 0;
    mFreeTag[2].mTagName[39] = 0;
    mFreeTag[2].mTagName[40] = 0;
    mFreeTag[2].mTagName[41] = 0;
    mFreeTag[2].mTagName[42] = 0;
    mFreeTag[2].mTagName[43] = 0;
    mFreeTag[2].mTagName[28] = 0;
    mFreeTag[2].mTagName[29] = 0;
    mFreeTag[2].mTagName[30] = 0;
    mFreeTag[2].mTagName[31] = 0;
    mFreeTag[2].mTagName[32] = 0;
    mFreeTag[2].mTagName[33] = 0;
    mFreeTag[2].mTagName[34] = 0;
    mFreeTag[2].mTagName[35] = 0;
    mFreeTag[2].mTagName[20] = 0;
    mFreeTag[2].mTagName[21] = 0;
    mFreeTag[2].mTagName[22] = 0;
    mFreeTag[2].mTagName[23] = 0;
    mFreeTag[2].mTagName[24] = 0;
    mFreeTag[2].mTagName[25] = 0;
    mFreeTag[2].mTagName[26] = 0;
    mFreeTag[2].mTagName[27] = 0;
    mFreeTag[2].mTagName[12] = 0;
    mFreeTag[2].mTagName[13] = 0;
    mFreeTag[2].mTagName[14] = 0;
    mFreeTag[2].mTagName[15] = 0;
    mFreeTag[2].mTagName[16] = 0;
    mFreeTag[2].mTagName[17] = 0;
    mFreeTag[2].mTagName[18] = 0;
    mFreeTag[2].mTagName[19] = 0;
    mFreeTag[2].mTagName[4] = 0;
    mFreeTag[2].mTagName[5] = 0;
    mFreeTag[2].mTagName[6] = 0;
    mFreeTag[2].mTagName[7] = 0;
    mFreeTag[2].mTagName[8] = 0;
    mFreeTag[2].mTagName[9] = 0;
    mFreeTag[2].mTagName[10] = 0;
    mFreeTag[2].mTagName[11] = 0;
    mFreeTag[1].mTagId = 0;
    mFreeTag[2].mTagName[0] = 0;
    mFreeTag[2].mTagName[1] = 0;
    mFreeTag[2].mTagName[2] = 0;
    mFreeTag[2].mTagName[3] = 0;
    mFreeTag[3].mTagName[80] = 0;
    mFreeTag[3].mTagName[76] = 0;
    mFreeTag[3].mTagName[77] = 0;
    mFreeTag[3].mTagName[78] = 0;
    mFreeTag[3].mTagName[79] = 0;
    mFreeTag[3].mTagName[68] = 0;
    mFreeTag[3].mTagName[69] = 0;
    mFreeTag[3].mTagName[70] = 0;
    mFreeTag[3].mTagName[71] = 0;
    mFreeTag[3].mTagName[72] = 0;
    mFreeTag[3].mTagName[73] = 0;
    mFreeTag[3].mTagName[74] = 0;
    mFreeTag[3].mTagName[75] = 0;
    mFreeTag[3].mTagName[60] = 0;
    mFreeTag[3].mTagName[61] = 0;
    mFreeTag[3].mTagName[62] = 0;
    mFreeTag[3].mTagName[63] = 0;
    mFreeTag[3].mTagName[64] = 0;
    mFreeTag[3].mTagName[65] = 0;
    mFreeTag[3].mTagName[66] = 0;
    mFreeTag[3].mTagName[67] = 0;
    mFreeTag[3].mTagName[52] = 0;
    mFreeTag[3].mTagName[53] = 0;
    mFreeTag[3].mTagName[54] = 0;
    mFreeTag[3].mTagName[55] = 0;
    mFreeTag[3].mTagName[56] = 0;
    mFreeTag[3].mTagName[57] = 0;
    mFreeTag[3].mTagName[58] = 0;
    mFreeTag[3].mTagName[59] = 0;
    mFreeTag[3].mTagName[44] = 0;
    mFreeTag[3].mTagName[45] = 0;
    mFreeTag[3].mTagName[46] = 0;
    mFreeTag[3].mTagName[47] = 0;
    mFreeTag[3].mTagName[48] = 0;
    mFreeTag[3].mTagName[49] = 0;
    mFreeTag[3].mTagName[50] = 0;
    mFreeTag[3].mTagName[51] = 0;
    mFreeTag[3].mTagName[36] = 0;
    mFreeTag[3].mTagName[37] = 0;
    mFreeTag[3].mTagName[38] = 0;
    mFreeTag[3].mTagName[39] = 0;
    mFreeTag[3].mTagName[40] = 0;
    mFreeTag[3].mTagName[41] = 0;
    mFreeTag[3].mTagName[42] = 0;
    mFreeTag[3].mTagName[43] = 0;
    mFreeTag[3].mTagName[28] = 0;
    mFreeTag[3].mTagName[29] = 0;
    mFreeTag[3].mTagName[30] = 0;
    mFreeTag[3].mTagName[31] = 0;
    mFreeTag[3].mTagName[32] = 0;
    mFreeTag[3].mTagName[33] = 0;
    mFreeTag[3].mTagName[34] = 0;
    mFreeTag[3].mTagName[35] = 0;
    mFreeTag[3].mTagName[20] = 0;
    mFreeTag[3].mTagName[21] = 0;
    mFreeTag[3].mTagName[22] = 0;
    mFreeTag[3].mTagName[23] = 0;
    mFreeTag[3].mTagName[24] = 0;
    mFreeTag[3].mTagName[25] = 0;
    mFreeTag[3].mTagName[26] = 0;
    mFreeTag[3].mTagName[27] = 0;
    mFreeTag[3].mTagName[12] = 0;
    mFreeTag[3].mTagName[13] = 0;
    mFreeTag[3].mTagName[14] = 0;
    mFreeTag[3].mTagName[15] = 0;
    mFreeTag[3].mTagName[16] = 0;
    mFreeTag[3].mTagName[17] = 0;
    mFreeTag[3].mTagName[18] = 0;
    mFreeTag[3].mTagName[19] = 0;
    mFreeTag[3].mTagName[4] = 0;
    mFreeTag[3].mTagName[5] = 0;
    mFreeTag[3].mTagName[6] = 0;
    mFreeTag[3].mTagName[7] = 0;
    mFreeTag[3].mTagName[8] = 0;
    mFreeTag[3].mTagName[9] = 0;
    mFreeTag[3].mTagName[10] = 0;
    mFreeTag[3].mTagName[11] = 0;
    mFreeTag[2].mTagId = 0;
    mFreeTag[3].mTagName[0] = 0;
    mFreeTag[3].mTagName[1] = 0;
    mFreeTag[3].mTagName[2] = 0;
    mFreeTag[3].mTagName[3] = 0;
    mFreeTag[4].mTagName[80] = 0;
    mFreeTag[4].mTagName[76] = 0;
    mFreeTag[4].mTagName[77] = 0;
    mFreeTag[4].mTagName[78] = 0;
    mFreeTag[4].mTagName[79] = 0;
    mFreeTag[4].mTagName[68] = 0;
    mFreeTag[4].mTagName[69] = 0;
    mFreeTag[4].mTagName[70] = 0;
    mFreeTag[4].mTagName[71] = 0;
    mFreeTag[4].mTagName[72] = 0;
    mFreeTag[4].mTagName[73] = 0;
    mFreeTag[4].mTagName[74] = 0;
    mFreeTag[4].mTagName[75] = 0;
    mFreeTag[4].mTagName[60] = 0;
    mFreeTag[4].mTagName[61] = 0;
    mFreeTag[4].mTagName[62] = 0;
    mFreeTag[4].mTagName[63] = 0;
    mFreeTag[4].mTagName[64] = 0;
    mFreeTag[4].mTagName[65] = 0;
    mFreeTag[4].mTagName[66] = 0;
    mFreeTag[4].mTagName[67] = 0;
    mFreeTag[4].mTagName[52] = 0;
    mFreeTag[4].mTagName[53] = 0;
    mFreeTag[4].mTagName[54] = 0;
    mFreeTag[4].mTagName[55] = 0;
    mFreeTag[4].mTagName[56] = 0;
    mFreeTag[4].mTagName[57] = 0;
    mFreeTag[4].mTagName[58] = 0;
    mFreeTag[4].mTagName[59] = 0;
    mFreeTag[4].mTagName[44] = 0;
    mFreeTag[4].mTagName[45] = 0;
    mFreeTag[4].mTagName[46] = 0;
    mFreeTag[4].mTagName[47] = 0;
    mFreeTag[4].mTagName[48] = 0;
    mFreeTag[4].mTagName[49] = 0;
    mFreeTag[4].mTagName[50] = 0;
    mFreeTag[4].mTagName[51] = 0;
    mFreeTag[4].mTagName[36] = 0;
    mFreeTag[4].mTagName[37] = 0;
    mFreeTag[4].mTagName[38] = 0;
    mFreeTag[4].mTagName[39] = 0;
    mFreeTag[4].mTagName[40] = 0;
    mFreeTag[4].mTagName[41] = 0;
    mFreeTag[4].mTagName[42] = 0;
    mFreeTag[4].mTagName[43] = 0;
    mFreeTag[4].mTagName[28] = 0;
    mFreeTag[4].mTagName[29] = 0;
    mFreeTag[4].mTagName[30] = 0;
    mFreeTag[4].mTagName[31] = 0;
    mFreeTag[4].mTagName[32] = 0;
    mFreeTag[4].mTagName[33] = 0;
    mFreeTag[4].mTagName[34] = 0;
    mFreeTag[4].mTagName[35] = 0;
    mFreeTag[4].mTagName[20] = 0;
    mFreeTag[4].mTagName[21] = 0;
    mFreeTag[4].mTagName[22] = 0;
    mFreeTag[4].mTagName[23] = 0;
    mFreeTag[4].mTagName[24] = 0;
    mFreeTag[4].mTagName[25] = 0;
    mFreeTag[4].mTagName[26] = 0;
    mFreeTag[4].mTagName[27] = 0;
    mFreeTag[4].mTagName[12] = 0;
    mFreeTag[4].mTagName[13] = 0;
    mFreeTag[4].mTagName[14] = 0;
    mFreeTag[4].mTagName[15] = 0;
    mFreeTag[4].mTagName[16] = 0;
    mFreeTag[4].mTagName[17] = 0;
    mFreeTag[4].mTagName[18] = 0;
    mFreeTag[4].mTagName[19] = 0;
    mFreeTag[4].mTagName[4] = 0;
    mFreeTag[4].mTagName[5] = 0;
    mFreeTag[4].mTagName[6] = 0;
    mFreeTag[4].mTagName[7] = 0;
    mFreeTag[4].mTagName[8] = 0;
    mFreeTag[4].mTagName[9] = 0;
    mFreeTag[4].mTagName[10] = 0;
    mFreeTag[4].mTagName[11] = 0;
    mFreeTag[3].mTagId = 0;
    mFreeTag[4].mTagName[0] = 0;
    mFreeTag[4].mTagName[1] = 0;
    mFreeTag[4].mTagName[2] = 0;
    mFreeTag[4].mTagName[3] = 0;
    mFreeTag[5].mTagName[80] = 0;
    mFreeTag[5].mTagName[76] = 0;
    mFreeTag[5].mTagName[77] = 0;
    mFreeTag[5].mTagName[78] = 0;
    mFreeTag[5].mTagName[79] = 0;
    mFreeTag[5].mTagName[68] = 0;
    mFreeTag[5].mTagName[69] = 0;
    mFreeTag[5].mTagName[70] = 0;
    mFreeTag[5].mTagName[71] = 0;
    mFreeTag[5].mTagName[72] = 0;
    mFreeTag[5].mTagName[73] = 0;
    mFreeTag[5].mTagName[74] = 0;
    mFreeTag[5].mTagName[75] = 0;
    mFreeTag[5].mTagName[60] = 0;
    mFreeTag[5].mTagName[61] = 0;
    mFreeTag[5].mTagName[62] = 0;
    mFreeTag[5].mTagName[63] = 0;
    mFreeTag[5].mTagName[64] = 0;
    mFreeTag[5].mTagName[65] = 0;
    mFreeTag[5].mTagName[66] = 0;
    mFreeTag[5].mTagName[67] = 0;
    mFreeTag[5].mTagName[52] = 0;
    mFreeTag[5].mTagName[53] = 0;
    mFreeTag[5].mTagName[54] = 0;
    mFreeTag[5].mTagName[55] = 0;
    mFreeTag[5].mTagName[56] = 0;
    mFreeTag[5].mTagName[57] = 0;
    mFreeTag[5].mTagName[58] = 0;
    mFreeTag[5].mTagName[59] = 0;
    mFreeTag[5].mTagName[44] = 0;
    mFreeTag[5].mTagName[45] = 0;
    mFreeTag[5].mTagName[46] = 0;
    mFreeTag[5].mTagName[47] = 0;
    mFreeTag[5].mTagName[48] = 0;
    mFreeTag[5].mTagName[49] = 0;
    mFreeTag[5].mTagName[50] = 0;
    mFreeTag[5].mTagName[51] = 0;
    mFreeTag[5].mTagName[36] = 0;
    mFreeTag[5].mTagName[37] = 0;
    mFreeTag[5].mTagName[38] = 0;
    mFreeTag[5].mTagName[39] = 0;
    mFreeTag[5].mTagName[40] = 0;
    mFreeTag[5].mTagName[41] = 0;
    mFreeTag[5].mTagName[42] = 0;
    mFreeTag[5].mTagName[43] = 0;
    mFreeTag[5].mTagName[28] = 0;
    mFreeTag[5].mTagName[29] = 0;
    mFreeTag[5].mTagName[30] = 0;
    mFreeTag[5].mTagName[31] = 0;
    mFreeTag[5].mTagName[32] = 0;
    mFreeTag[5].mTagName[33] = 0;
    mFreeTag[5].mTagName[34] = 0;
    mFreeTag[5].mTagName[35] = 0;
    mFreeTag[5].mTagName[20] = 0;
    mFreeTag[5].mTagName[21] = 0;
    mFreeTag[5].mTagName[22] = 0;
    mFreeTag[5].mTagName[23] = 0;
    mFreeTag[5].mTagName[24] = 0;
    mFreeTag[5].mTagName[25] = 0;
    mFreeTag[5].mTagName[26] = 0;
    mFreeTag[5].mTagName[27] = 0;
    mFreeTag[5].mTagName[12] = 0;
    mFreeTag[5].mTagName[13] = 0;
    mFreeTag[5].mTagName[14] = 0;
    mFreeTag[5].mTagName[15] = 0;
    mFreeTag[5].mTagName[16] = 0;
    mFreeTag[5].mTagName[17] = 0;
    mFreeTag[5].mTagName[18] = 0;
    mFreeTag[5].mTagName[19] = 0;
    mFreeTag[5].mTagName[4] = 0;
    mFreeTag[5].mTagName[5] = 0;
    mFreeTag[5].mTagName[6] = 0;
    mFreeTag[5].mTagName[7] = 0;
    mFreeTag[5].mTagName[8] = 0;
    mFreeTag[5].mTagName[9] = 0;
    mFreeTag[5].mTagName[10] = 0;
    mFreeTag[5].mTagName[11] = 0;
    mFreeTag[4].mTagId = 0;
    mFreeTag[5].mTagName[0] = 0;
    mFreeTag[5].mTagName[1] = 0;
    mFreeTag[5].mTagName[2] = 0;
    mFreeTag[5].mTagName[3] = 0;
    mFreeTag[6].mTagName[80] = 0;
    mFreeTag[6].mTagName[76] = 0;
    mFreeTag[6].mTagName[77] = 0;
    mFreeTag[6].mTagName[78] = 0;
    mFreeTag[6].mTagName[79] = 0;
    mFreeTag[6].mTagName[68] = 0;
    mFreeTag[6].mTagName[69] = 0;
    mFreeTag[6].mTagName[70] = 0;
    mFreeTag[6].mTagName[71] = 0;
    mFreeTag[6].mTagName[72] = 0;
    mFreeTag[6].mTagName[73] = 0;
    mFreeTag[6].mTagName[74] = 0;
    mFreeTag[6].mTagName[75] = 0;
    mFreeTag[6].mTagName[60] = 0;
    mFreeTag[6].mTagName[61] = 0;
    mFreeTag[6].mTagName[62] = 0;
    mFreeTag[6].mTagName[63] = 0;
    mFreeTag[6].mTagName[64] = 0;
    mFreeTag[6].mTagName[65] = 0;
    mFreeTag[6].mTagName[66] = 0;
    mFreeTag[6].mTagName[67] = 0;
    mFreeTag[6].mTagName[52] = 0;
    mFreeTag[6].mTagName[53] = 0;
    mFreeTag[6].mTagName[54] = 0;
    mFreeTag[6].mTagName[55] = 0;
    mFreeTag[6].mTagName[56] = 0;
    mFreeTag[6].mTagName[57] = 0;
    mFreeTag[6].mTagName[58] = 0;
    mFreeTag[6].mTagName[59] = 0;
    mFreeTag[6].mTagName[44] = 0;
    mFreeTag[6].mTagName[45] = 0;
    mFreeTag[6].mTagName[46] = 0;
    mFreeTag[6].mTagName[47] = 0;
    mFreeTag[6].mTagName[48] = 0;
    mFreeTag[6].mTagName[49] = 0;
    mFreeTag[6].mTagName[50] = 0;
    mFreeTag[6].mTagName[51] = 0;
    mFreeTag[6].mTagName[36] = 0;
    mFreeTag[6].mTagName[37] = 0;
    mFreeTag[6].mTagName[38] = 0;
    mFreeTag[6].mTagName[39] = 0;
    mFreeTag[6].mTagName[40] = 0;
    mFreeTag[6].mTagName[41] = 0;
    mFreeTag[6].mTagName[42] = 0;
    mFreeTag[6].mTagName[43] = 0;
    mFreeTag[6].mTagName[28] = 0;
    mFreeTag[6].mTagName[29] = 0;
    mFreeTag[6].mTagName[30] = 0;
    mFreeTag[6].mTagName[31] = 0;
    mFreeTag[6].mTagName[32] = 0;
    mFreeTag[6].mTagName[33] = 0;
    mFreeTag[6].mTagName[34] = 0;
    mFreeTag[6].mTagName[35] = 0;
    mFreeTag[6].mTagName[20] = 0;
    mFreeTag[6].mTagName[21] = 0;
    mFreeTag[6].mTagName[22] = 0;
    mFreeTag[6].mTagName[23] = 0;
    mFreeTag[6].mTagName[24] = 0;
    mFreeTag[6].mTagName[25] = 0;
    mFreeTag[6].mTagName[26] = 0;
    mFreeTag[6].mTagName[27] = 0;
    mFreeTag[6].mTagName[12] = 0;
    mFreeTag[6].mTagName[13] = 0;
    mFreeTag[6].mTagName[14] = 0;
    mFreeTag[6].mTagName[15] = 0;
    mFreeTag[6].mTagName[16] = 0;
    mFreeTag[6].mTagName[17] = 0;
    mFreeTag[6].mTagName[18] = 0;
    mFreeTag[6].mTagName[19] = 0;
    mFreeTag[6].mTagName[4] = 0;
    mFreeTag[6].mTagName[5] = 0;
    mFreeTag[6].mTagName[6] = 0;
    mFreeTag[6].mTagName[7] = 0;
    mFreeTag[6].mTagName[8] = 0;
    mFreeTag[6].mTagName[9] = 0;
    mFreeTag[6].mTagName[10] = 0;
    mFreeTag[6].mTagName[11] = 0;
    mFreeTag[5].mTagId = 0;
    mFreeTag[6].mTagName[0] = 0;
    mFreeTag[6].mTagName[1] = 0;
    mFreeTag[6].mTagName[2] = 0;
    mFreeTag[6].mTagName[3] = 0;
    mFreeTag[7].mTagName[80] = 0;
    mFreeTag[7].mTagName[76] = 0;
    mFreeTag[7].mTagName[77] = 0;
    mFreeTag[7].mTagName[78] = 0;
    mFreeTag[7].mTagName[79] = 0;
    mFreeTag[7].mTagName[68] = 0;
    mFreeTag[7].mTagName[69] = 0;
    mFreeTag[7].mTagName[70] = 0;
    mFreeTag[7].mTagName[71] = 0;
    mFreeTag[7].mTagName[72] = 0;
    mFreeTag[7].mTagName[73] = 0;
    mFreeTag[7].mTagName[74] = 0;
    mFreeTag[7].mTagName[75] = 0;
    mFreeTag[7].mTagName[60] = 0;
    mFreeTag[7].mTagName[61] = 0;
    mFreeTag[7].mTagName[62] = 0;
    mFreeTag[7].mTagName[63] = 0;
    mFreeTag[7].mTagName[64] = 0;
    mFreeTag[7].mTagName[65] = 0;
    mFreeTag[7].mTagName[66] = 0;
    mFreeTag[7].mTagName[67] = 0;
    mFreeTag[7].mTagName[52] = 0;
    mFreeTag[7].mTagName[53] = 0;
    mFreeTag[7].mTagName[54] = 0;
    mFreeTag[7].mTagName[55] = 0;
    mFreeTag[7].mTagName[56] = 0;
    mFreeTag[7].mTagName[57] = 0;
    mFreeTag[7].mTagName[58] = 0;
    mFreeTag[7].mTagName[59] = 0;
    mFreeTag[7].mTagName[44] = 0;
    mFreeTag[7].mTagName[45] = 0;
    mFreeTag[7].mTagName[46] = 0;
    mFreeTag[7].mTagName[47] = 0;
    mFreeTag[7].mTagName[48] = 0;
    mFreeTag[7].mTagName[49] = 0;
    mFreeTag[7].mTagName[50] = 0;
    mFreeTag[7].mTagName[51] = 0;
    mFreeTag[7].mTagName[36] = 0;
    mFreeTag[7].mTagName[37] = 0;
    mFreeTag[7].mTagName[38] = 0;
    mFreeTag[7].mTagName[39] = 0;
    mFreeTag[7].mTagName[40] = 0;
    mFreeTag[7].mTagName[41] = 0;
    mFreeTag[7].mTagName[42] = 0;
    mFreeTag[7].mTagName[43] = 0;
    mFreeTag[7].mTagName[28] = 0;
    mFreeTag[7].mTagName[29] = 0;
    mFreeTag[7].mTagName[30] = 0;
    mFreeTag[7].mTagName[31] = 0;
    mFreeTag[7].mTagName[32] = 0;
    mFreeTag[7].mTagName[33] = 0;
    mFreeTag[7].mTagName[34] = 0;
    mFreeTag[7].mTagName[35] = 0;
    mFreeTag[7].mTagName[20] = 0;
    mFreeTag[7].mTagName[21] = 0;
    mFreeTag[7].mTagName[22] = 0;
    mFreeTag[7].mTagName[23] = 0;
    mFreeTag[7].mTagName[24] = 0;
    mFreeTag[7].mTagName[25] = 0;
    mFreeTag[7].mTagName[26] = 0;
    mFreeTag[7].mTagName[27] = 0;
    mFreeTag[7].mTagName[12] = 0;
    mFreeTag[7].mTagName[13] = 0;
    mFreeTag[7].mTagName[14] = 0;
    mFreeTag[7].mTagName[15] = 0;
    mFreeTag[7].mTagName[16] = 0;
    mFreeTag[7].mTagName[17] = 0;
    mFreeTag[7].mTagName[18] = 0;
    mFreeTag[7].mTagName[19] = 0;
    mFreeTag[7].mTagName[4] = 0;
    mFreeTag[7].mTagName[5] = 0;
    mFreeTag[7].mTagName[6] = 0;
    mFreeTag[7].mTagName[7] = 0;
    mFreeTag[7].mTagName[8] = 0;
    mFreeTag[7].mTagName[9] = 0;
    mFreeTag[7].mTagName[10] = 0;
    mFreeTag[7].mTagName[11] = 0;
    mFreeTag[6].mTagId = 0;
    mFreeTag[7].mTagName[0] = 0;
    mFreeTag[7].mTagName[1] = 0;
    mFreeTag[7].mTagName[2] = 0;
    mFreeTag[7].mTagName[3] = 0;
    mFreeTag[8].mTagName[80] = 0;
    mFreeTag[8].mTagName[76] = 0;
    mFreeTag[8].mTagName[77] = 0;
    mFreeTag[8].mTagName[78] = 0;
    mFreeTag[8].mTagName[79] = 0;
    mFreeTag[8].mTagName[68] = 0;
    mFreeTag[8].mTagName[69] = 0;
    mFreeTag[8].mTagName[70] = 0;
    mFreeTag[8].mTagName[71] = 0;
    mFreeTag[8].mTagName[72] = 0;
    mFreeTag[8].mTagName[73] = 0;
    mFreeTag[8].mTagName[74] = 0;
    mFreeTag[8].mTagName[75] = 0;
    mFreeTag[8].mTagName[60] = 0;
    mFreeTag[8].mTagName[61] = 0;
    mFreeTag[8].mTagName[62] = 0;
    mFreeTag[8].mTagName[63] = 0;
    mFreeTag[8].mTagName[64] = 0;
    mFreeTag[8].mTagName[65] = 0;
    mFreeTag[8].mTagName[66] = 0;
    mFreeTag[8].mTagName[67] = 0;
    mFreeTag[8].mTagName[52] = 0;
    mFreeTag[8].mTagName[53] = 0;
    mFreeTag[8].mTagName[54] = 0;
    mFreeTag[8].mTagName[55] = 0;
    mFreeTag[8].mTagName[56] = 0;
    mFreeTag[8].mTagName[57] = 0;
    mFreeTag[8].mTagName[58] = 0;
    mFreeTag[8].mTagName[59] = 0;
    mFreeTag[8].mTagName[44] = 0;
    mFreeTag[8].mTagName[45] = 0;
    mFreeTag[8].mTagName[46] = 0;
    mFreeTag[8].mTagName[47] = 0;
    mFreeTag[8].mTagName[48] = 0;
    mFreeTag[8].mTagName[49] = 0;
    mFreeTag[8].mTagName[50] = 0;
    mFreeTag[8].mTagName[51] = 0;
    mFreeTag[8].mTagName[36] = 0;
    mFreeTag[8].mTagName[37] = 0;
    mFreeTag[8].mTagName[38] = 0;
    mFreeTag[8].mTagName[39] = 0;
    mFreeTag[8].mTagName[40] = 0;
    mFreeTag[8].mTagName[41] = 0;
    mFreeTag[8].mTagName[42] = 0;
    mFreeTag[8].mTagName[43] = 0;
    mFreeTag[8].mTagName[28] = 0;
    mFreeTag[8].mTagName[29] = 0;
    mFreeTag[8].mTagName[30] = 0;
    mFreeTag[8].mTagName[31] = 0;
    mFreeTag[8].mTagName[32] = 0;
    mFreeTag[8].mTagName[33] = 0;
    mFreeTag[8].mTagName[34] = 0;
    mFreeTag[8].mTagName[35] = 0;
    mFreeTag[8].mTagName[20] = 0;
    mFreeTag[8].mTagName[21] = 0;
    mFreeTag[8].mTagName[22] = 0;
    mFreeTag[8].mTagName[23] = 0;
    mFreeTag[8].mTagName[24] = 0;
    mFreeTag[8].mTagName[25] = 0;
    mFreeTag[8].mTagName[26] = 0;
    mFreeTag[8].mTagName[27] = 0;
    mFreeTag[8].mTagName[12] = 0;
    mFreeTag[8].mTagName[13] = 0;
    mFreeTag[8].mTagName[14] = 0;
    mFreeTag[8].mTagName[15] = 0;
    mFreeTag[8].mTagName[16] = 0;
    mFreeTag[8].mTagName[17] = 0;
    mFreeTag[8].mTagName[18] = 0;
    mFreeTag[8].mTagName[19] = 0;
    mFreeTag[8].mTagName[4] = 0;
    mFreeTag[8].mTagName[5] = 0;
    mFreeTag[8].mTagName[6] = 0;
    mFreeTag[8].mTagName[7] = 0;
    mFreeTag[8].mTagName[8] = 0;
    mFreeTag[8].mTagName[9] = 0;
    mFreeTag[8].mTagName[10] = 0;
    mFreeTag[8].mTagName[11] = 0;
    mFreeTag[7].mTagId = 0;
    mFreeTag[8].mTagName[0] = 0;
    mFreeTag[8].mTagName[1] = 0;
    mFreeTag[8].mTagName[2] = 0;
    mFreeTag[8].mTagName[3] = 0;
    mFreeTag[9].mTagName[80] = 0;
    mFreeTag[9].mTagName[76] = 0;
    mFreeTag[9].mTagName[77] = 0;
    mFreeTag[9].mTagName[78] = 0;
    mFreeTag[9].mTagName[79] = 0;
    mFreeTag[9].mTagName[68] = 0;
    mFreeTag[9].mTagName[69] = 0;
    mFreeTag[9].mTagName[70] = 0;
    mFreeTag[9].mTagName[71] = 0;
    mFreeTag[9].mTagName[72] = 0;
    mFreeTag[9].mTagName[73] = 0;
    mFreeTag[9].mTagName[74] = 0;
    mFreeTag[9].mTagName[75] = 0;
    mFreeTag[9].mTagName[60] = 0;
    mFreeTag[9].mTagName[61] = 0;
    mFreeTag[9].mTagName[62] = 0;
    mFreeTag[9].mTagName[63] = 0;
    mFreeTag[9].mTagName[64] = 0;
    mFreeTag[9].mTagName[65] = 0;
    mFreeTag[9].mTagName[66] = 0;
    mFreeTag[9].mTagName[67] = 0;
    mFreeTag[9].mTagName[52] = 0;
    mFreeTag[9].mTagName[53] = 0;
    mFreeTag[9].mTagName[54] = 0;
    mFreeTag[9].mTagName[55] = 0;
    mFreeTag[9].mTagName[56] = 0;
    mFreeTag[9].mTagName[57] = 0;
    mFreeTag[9].mTagName[58] = 0;
    mFreeTag[9].mTagName[59] = 0;
    mFreeTag[9].mTagName[44] = 0;
    mFreeTag[9].mTagName[45] = 0;
    mFreeTag[9].mTagName[46] = 0;
    mFreeTag[9].mTagName[47] = 0;
    mFreeTag[9].mTagName[48] = 0;
    mFreeTag[9].mTagName[49] = 0;
    mFreeTag[9].mTagName[50] = 0;
    mFreeTag[9].mTagName[51] = 0;
    mFreeTag[9].mTagName[36] = 0;
    mFreeTag[9].mTagName[37] = 0;
    mFreeTag[9].mTagName[38] = 0;
    mFreeTag[9].mTagName[39] = 0;
    mFreeTag[9].mTagName[40] = 0;
    mFreeTag[9].mTagName[41] = 0;
    mFreeTag[9].mTagName[42] = 0;
    mFreeTag[9].mTagName[43] = 0;
    mFreeTag[9].mTagName[28] = 0;
    mFreeTag[9].mTagName[29] = 0;
    mFreeTag[9].mTagName[30] = 0;
    mFreeTag[9].mTagName[31] = 0;
    mFreeTag[9].mTagName[32] = 0;
    mFreeTag[9].mTagName[33] = 0;
    mFreeTag[9].mTagName[34] = 0;
    mFreeTag[9].mTagName[35] = 0;
    mFreeTag[9].mTagName[20] = 0;
    mFreeTag[9].mTagName[21] = 0;
    mFreeTag[9].mTagName[22] = 0;
    mFreeTag[9].mTagName[23] = 0;
    mFreeTag[9].mTagName[24] = 0;
    mFreeTag[9].mTagName[25] = 0;
    mFreeTag[9].mTagName[26] = 0;
    mFreeTag[9].mTagName[27] = 0;
    mFreeTag[9].mTagName[12] = 0;
    mFreeTag[9].mTagName[13] = 0;
    mFreeTag[9].mTagName[14] = 0;
    mFreeTag[9].mTagName[15] = 0;
    mFreeTag[9].mTagName[16] = 0;
    mFreeTag[9].mTagName[17] = 0;
    mFreeTag[9].mTagName[18] = 0;
    mFreeTag[9].mTagName[19] = 0;
    mFreeTag[9].mTagName[4] = 0;
    mFreeTag[9].mTagName[5] = 0;
    mFreeTag[9].mTagName[6] = 0;
    mFreeTag[9].mTagName[7] = 0;
    mFreeTag[9].mTagName[8] = 0;
    mFreeTag[9].mTagName[9] = 0;
    mFreeTag[9].mTagName[10] = 0;
    mFreeTag[9].mTagName[11] = 0;
    mFreeTag[8].mTagId = 0;
    mFreeTag[9].mTagName[0] = 0;
    mFreeTag[9].mTagName[1] = 0;
    mFreeTag[9].mTagName[2] = 0;
    mFreeTag[9].mTagName[3] = 0;
    for (unsigned int i2_3 = 0;;) {
        cFriendRecvData* t1 = mFriendRecv;
        t1[i2_3].mIconIndex = 0xFF;
        memset(static_cast<void*>(&t1[i2_3].mUniqueId[0]), 0, 627ul);
        if (i2_3 != 999) {
            i2_3 = i2_3 + 1u;
        } else {
            break;
        }
    }
    if (mContentData.mLength != 0) {
        u32 v4_0 = mContentData.mLength;
        unsigned int i4_3 = 0;
        u32 v5_0;
        for (;;) {
            if (mContentData.mpArray[i4_3] == nullptr) {
                v5_0 = v4_0;
            } else {
                delete mContentData.mpArray[i4_3];
                v5_0 = mContentData.mLength;
            }
            if ((i4_3 + 1u) < v5_0) {
                v4_0 = v5_0;
                i4_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mContentData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mContentData.mpArray));
    }
    mContentData.mpArray = nullptr;
    mContentData.mBufsiz = 0;
    mContentData.mLength = 0;
    if (mGroupChatData.mLength != 0) {
        u32 v7_0 = mGroupChatData.mLength;
        unsigned int i7_3 = 0;
        u32 v8_0;
        for (;;) {
            if (mGroupChatData.mpArray[i7_3] == nullptr) {
                v8_0 = v7_0;
            } else {
                delete mGroupChatData.mpArray[i7_3];
                v8_0 = mGroupChatData.mLength;
            }
            if ((i7_3 + 1u) < v8_0) {
                v7_0 = v8_0;
                i7_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mGroupChatData.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mGroupChatData.mpArray));
    }
    mGroupChatData.mpArray = nullptr;
    mGroupChatData.mBufsiz = 0;
    mGroupChatData.mLength = 0;
    mFriendNum = 0;
    mFreeTagNum = 0;
    mIsDispNoneTag = true;
    mFriendRecvNum = 0;
    mIsDispNoneContent = true;
    mFreeTagDisp = mFreeTagDisp | 1023u;
    mFriendAttrDisp = 6;
    mRnoUpdate = 0;
}

__attribute__((weak)) void sCaplinkManager::resetFriendList() {
    DDON_STUB("sCaplinkManager::resetFriendList")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::setReqFlag(u32 flag, bool isDispError) {
    if (flag <= 10u) {
        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->isConnectServer()) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                    abort();
                }
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                        abort();
                    }
                    u32 t0 = mUpdateFlag;
                    mUpdateFlag = static_cast<unsigned int>(static_cast<unsigned long>(t0) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(flag) & 31)));
                    if (isDispError) {
                        mUpdateDispError = static_cast<unsigned int>(static_cast<unsigned long>(mUpdateDispError) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(flag) & 31)));
                    }
                    if (t0 == 0) {
                        reqNextUpdate();
                    }
                } else {
                    u32 t0 = mUpdateFlag;
                    mUpdateFlag = static_cast<unsigned int>(static_cast<unsigned long>(t0) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(flag) & 31)));
                    if (isDispError) {
                        mUpdateDispError = static_cast<unsigned int>(static_cast<unsigned long>(mUpdateDispError) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(flag) & 31)));
                    }
                    if (t0 == 0) {
                        reqNextUpdate();
                    }
                }
            } else {
                u32 t0 = mUpdateFlag;
                mUpdateFlag = static_cast<unsigned int>(static_cast<unsigned long>(t0) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(flag) & 31)));
                if (isDispError) {
                    mUpdateDispError = static_cast<unsigned int>(static_cast<unsigned long>(mUpdateDispError) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(flag) & 31)));
                }
                if (t0 == 0) {
                    reqNextUpdate();
                }
            }
        }
    }
}

__attribute__((weak)) void sCaplinkManager::reqNextUpdate() {
    DDON_STUB("sCaplinkManager::reqNextUpdate")
    /* stub */
}

void sCaplinkManager::reqFreeTagListUpdate(bool isDispError) {
    setReqFlag(2u, isDispError);
}

void sCaplinkManager::reqFriendListUpdate(bool isDispError) {
    setReqFlag(3u, isDispError);
}

void sCaplinkManager::reqFriendContentUpdate(bool isDispError) {
    setReqFlag(4u, isDispError);
}

void sCaplinkManager::reqFriendFreeTagListUpdate(bool isDispError) {
    setReqFlag(5u, isDispError);
}

void sCaplinkManager::reqFriendRecvUpdate(bool isDispError) {
    setReqFlag(6u, isDispError);
}

void sCaplinkManager::reqFriendInviteEnableUpdate(bool isDispError) {
    setReqFlag(7u, isDispError);
}

void sCaplinkManager::reqGroupChatListUpdate(bool isDispError) {
    setReqFlag(8u, isDispError);
}

void sCaplinkManager::reqChatListUpdate(s32 id_type, MT_CTSTR id, bool is_forward) {
    if (id == nullptr) {
        return;
    }
    if (id_type == 0) {
        return;
    }
    if ((mUpdateFlag & 1024u) == 0) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
            }
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                }
            }
        }
        if (mChatList.mIdType == id_type) {
            if (id != (&mChatList.mId.mStr[0])) {
                if (strcmp(&mChatList.mId.mStr[0], id) != 0) {
                    clearChatList();
                    mChatList.mIdType = id_type;
                    size_t t0 = strlen(id);
                    mChatList.mId.mLength = (static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u;
                    if (((static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u) != 0) {
                        memcpy(static_cast<void*>(&mChatList.mId.mStr[0]), static_cast<const void*>(id), static_cast<size_t>((static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u));
                        mChatList.mId.mStr[(static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u] = '\0';
                    } else {
                        mChatList.mId.mStr[0] = '\0';
                    }
                    mChatList.mIsFirst = false;
                    mChatList.mIsForward = is_forward;
                    setReqFlag(10u, static_cast<bool>((mUpdateDispError & 1024u) >> 10));
                } else {
                    mChatList.mIsFirst = false;
                    mChatList.mIsForward = is_forward;
                    setReqFlag(10u, static_cast<bool>((mUpdateDispError & 1024u) >> 10));
                }
            } else {
                mChatList.mIsFirst = false;
                mChatList.mIsForward = is_forward;
                setReqFlag(10u, static_cast<bool>((mUpdateDispError & 1024u) >> 10));
            }
        } else {
            clearChatList();
            mChatList.mIdType = id_type;
            if (id != (&mChatList.mId.mStr[0])) {
                size_t t0 = strlen(id);
                mChatList.mId.mLength = (static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u;
                if (((static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u) != 0) {
                    memcpy(static_cast<void*>(&mChatList.mId.mStr[0]), static_cast<const void*>(id), static_cast<size_t>((static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u));
                    mChatList.mId.mStr[(static_cast<int>(t0) <= 32) ? static_cast<unsigned int>(t0) : 32u] = '\0';
                } else {
                    mChatList.mId.mStr[0] = '\0';
                }
                mChatList.mIsFirst = false;
                mChatList.mIsForward = is_forward;
                setReqFlag(10u, static_cast<bool>((mUpdateDispError & 1024u) >> 10));
            } else {
                mChatList.mIsFirst = false;
                mChatList.mIsForward = is_forward;
                setReqFlag(10u, static_cast<bool>((mUpdateDispError & 1024u) >> 10));
            }
        }
    }
}

__attribute__((weak)) void sCaplinkManager::updateMyProf() {
    DDON_STUB("sCaplinkManager::updateMyProf")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateContentList() {
    DDON_STUB("sCaplinkManager::updateContentList")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateFreeTagList() {
    DDON_STUB("sCaplinkManager::updateFreeTagList")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateFriendList() {
    DDON_STUB("sCaplinkManager::updateFriendList")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateFriendContent() {
    DDON_STUB("sCaplinkManager::updateFriendContent")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateFriendFreeTagList() {
    DDON_STUB("sCaplinkManager::updateFriendFreeTagList")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateFriendRecv() {
    DDON_STUB("sCaplinkManager::updateFriendRecv")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateFriendInviteEnable() {
    DDON_STUB("sCaplinkManager::updateFriendInviteEnable")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateGroupChatList() {
    DDON_STUB("sCaplinkManager::updateGroupChatList")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateNotifyDetail() {
    DDON_STUB("sCaplinkManager::updateNotifyDetail")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::updateChatList() {
    DDON_STUB("sCaplinkManager::updateChatList")
    /* stub */
}

__attribute__((weak)) bool sCaplinkManager::isEnableMessage(MT_CTSTR pMsg) {
    DDON_STUB("sCaplinkManager::isEnableMessage")
    return {};
}

inline sCaplinkManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::MyDTI sCaplinkManager::DTI("sCaplinkManager", &::cSystem::DTI, 12472ul, 0u, 0u);

sCaplinkManager* sCaplinkManager::mpInstance;

__attribute__((weak)) MtObject* sCaplinkManager::MyDTI::newInstance() const {
    DDON_STUB("sCaplinkManager::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sCaplinkManager::cCaplinkListenerQueue::getDTI() const {
    return sCaplinkManager::cCaplinkListenerQueue::DTI;
}

sCaplinkManager::cCaplinkListenerQueue::~cCaplinkListenerQueue() {
    DDON_STUB("sCaplinkManager::cCaplinkListenerQueue::~cCaplinkListenerQueue")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::cCaplinkListenerQueue::update() {
    DDON_STUB("sCaplinkManager::cCaplinkListenerQueue::update")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::cCaplinkListenerQueue::setErrorMsg() {
    DDON_STUB("sCaplinkManager::cCaplinkListenerQueue::setErrorMsg")
    /* stub */
}

inline sCaplinkManager::cCaplinkListenerQueue::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::cCaplinkListenerQueue::MyDTI sCaplinkManager::cCaplinkListenerQueue::DTI("sCaplinkManager::cCaplinkListenerQueue", &::cCaplinkObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* sCaplinkManager::cCaplinkListenerQueue::MyDTI::newInstance() const {
    DDON_STUB("sCaplinkManager::cCaplinkListenerQueue::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sCaplinkManager::cProfile::getDTI() const {
    return sCaplinkManager::cProfile::DTI;
}

inline sCaplinkManager::cProfile::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::cProfile::MyDTI sCaplinkManager::cProfile::DTI("sCaplinkManager::cProfile", &::cCaplinkObject::DTI, 936ul, 0u, 0u);

MtObject* sCaplinkManager::cProfile::MyDTI::newInstance() const {
    return new (16u) sCaplinkManager::cProfile;
}

const MtDTI& sCaplinkManager::cIconUrl::getDTI() const {
    return sCaplinkManager::cIconUrl::DTI;
}

MT_CTSTR sCaplinkManager::cIconUrl::getUrl() const {
    return &mUrl.mStr[0];
}

inline sCaplinkManager::cIconUrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::cIconUrl::MyDTI sCaplinkManager::cIconUrl::DTI("sCaplinkManager::cIconUrl", &::cCaplinkObject::DTI, 280ul, 0u, 0u);

__attribute__((weak)) MtObject* sCaplinkManager::cIconUrl::MyDTI::newInstance() const {
    DDON_STUB("sCaplinkManager::cIconUrl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sCaplinkManager::cProfIconLoader::getDTI() const {
    return sCaplinkManager::cProfIconLoader::DTI;
}

sCaplinkManager::cProfIconLoader::~cProfIconLoader() {
    if (mHandle <= 8u) {
        if (sHttpClient::getInstance()->mClientList[mHandle].mpHttp != nullptr) {
            if (!sHttpClient::getInstance()->mClientList[mHandle].mpHttp->isExecOpeningServerFlow()) {
                sHttpClient::getInstance()->mClientList[mHandle].mpHttp->abort();
            }
        }
    }
    if (mpImage != nullptr) {
        MtMemoryAllocator::getAllocator(cResource::DTI)->memFree(mpImage);
        mpImage = nullptr;
    }
    mURL.mStr[0] = 0;
    mURL.mLength = 0;
    mImageSize = 0;
    mHandle = 0;
}

bool sCaplinkManager::cProfIconLoader::update() {
    if (sCaplinkManager::getInstance()->mIsConnection) {
        if (mHandle != 0) {
            if (mHandle <= 8u) {
                if ((sHttpClient::getInstance()->mClientList[mHandle].mpHttp != nullptr) && (sHttpClient::getInstance()->mClientList[mHandle].mpHttp->mRno != 8)) {
                    return false;
                }
                if (sHttpClient::getInstance()->mClientList[mHandle].mErrorCode == 0) {
                    static_cast<sGUIExt*>(sGUI::getInstance())->setCaplinkIcon(mpImage, mImageSize, mId);
                }
            }
            mHandle = 0;
            return true;
        } else {
            if (sCaplinkManager::getInstance()->mListener.mLength == 0) {
                if (sCaplinkManager::getInstance()->mUpdateFlag == 0) {
                    if (sCaplinkManager::getInstance()->mRnoMain == 16) {
                        mHandle = sHttpClient::getInstance()->reqDownloadPic(&mURL.mStr[0], &mpImage, &mImageSize);
                    }
                }
            }
            return false;
        }
    } else {
        if (mHandle <= 8u) {
            if (sHttpClient::getInstance()->mClientList[mHandle].mpHttp != nullptr) {
                if (!sHttpClient::getInstance()->mClientList[mHandle].mpHttp->isExecOpeningServerFlow()) {
                    sHttpClient::getInstance()->mClientList[mHandle].mpHttp->abort();
                }
            }
        }
        if (mpImage != nullptr) {
            MtMemoryAllocator::getAllocator(cResource::DTI)->memFree(mpImage);
            mpImage = nullptr;
        }
        mURL.mStr[0] = 0;
        mURL.mLength = 0;
        mImageSize = 0;
        mHandle = 0;
        return true;
    }
}

inline sCaplinkManager::cProfIconLoader::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::cProfIconLoader::MyDTI sCaplinkManager::cProfIconLoader::DTI("sCaplinkManager::cProfIconLoader", &::cCaplinkObject::DTI, 296ul, 0u, 0u);

__attribute__((weak)) MtObject* sCaplinkManager::cProfIconLoader::MyDTI::newInstance() const {
    DDON_STUB("sCaplinkManager::cProfIconLoader::MyDTI::newInstance")
    return nullptr;
}

void sCaplinkManager::cDate::copy(MtTime& t) {
    if (t.mTime == (MtTime::mTmTime)) {
        mYear = static_cast<unsigned short>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&MtTime::mTm) + 20)) + 1900u);
        mMonth = static_cast<unsigned char>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&MtTime::mTm) + 16)) + 1u);
        mDay = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 12);
        mHour = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 8);
        mMin = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 4);
        mSec = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 0);
    } else {
        t.updateDate(t.mTime);
        t64 t0 = MtTime::mTmTime;
        t64 t1 = t.mTime;
        mYear = static_cast<unsigned short>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&MtTime::mTm) + 20)) + 1900u);
        if (t0 == t1) {
            mMonth = static_cast<unsigned char>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&MtTime::mTm) + 16)) + 1u);
            mDay = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 12);
            mHour = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 8);
            mMin = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 4);
            mSec = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 0);
        } else {
            t.updateDate(t1);
            t64 t2 = MtTime::mTmTime;
            t64 t3 = t.mTime;
            mMonth = static_cast<unsigned char>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&MtTime::mTm) + 16)) + 1u);
            if (t2 != t3) {
                t.updateDate(t3);
                t64 t4 = MtTime::mTmTime;
                t64 t5 = t.mTime;
                mDay = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 12);
                if (t4 != t5) {
                    t.updateDate(t5);
                    t64 t6 = MtTime::mTmTime;
                    t64 t7 = t.mTime;
                    mHour = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 8);
                    if (t6 != t7) {
                        t.updateDate(t7);
                        t64 t8 = MtTime::mTmTime;
                        t64 t9 = t.mTime;
                        mMin = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 4);
                        if (t8 != t9) {
                            t.updateDate(t9);
                        }
                        mSec = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 0);
                    } else {
                        mMin = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 4);
                        mSec = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 0);
                    }
                } else {
                    mHour = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 8);
                    mMin = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 4);
                    mSec = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 0);
                }
            } else {
                mDay = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 12);
                mHour = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 8);
                mMin = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 4);
                mSec = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&MtTime::mTm) + 0);
            }
        }
    }
}

__attribute__((weak)) void sCaplinkManager::cDate::set(MT_CTSTR date) {
    DDON_STUB("sCaplinkManager::cDate::set")
    /* stub */
}

const MtDTI& sCaplinkManager::cContentData::getDTI() const {
    return sCaplinkManager::cContentData::DTI;
}

inline sCaplinkManager::cContentData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::cContentData::MyDTI sCaplinkManager::cContentData::DTI("sCaplinkManager::cContentData", &::cCaplinkObject::DTI, 216ul, 0u, 0u);

__attribute__((weak)) MtObject* sCaplinkManager::cContentData::MyDTI::newInstance() const {
    DDON_STUB("sCaplinkManager::cContentData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sCaplinkManager::cGroupChatData::getDTI() const {
    return sCaplinkManager::cGroupChatData::DTI;
}

inline sCaplinkManager::cGroupChatData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::cGroupChatData::MyDTI sCaplinkManager::cGroupChatData::DTI("sCaplinkManager::cGroupChatData", &::cCaplinkObject::DTI, 272ul, 0u, 0u);

__attribute__((weak)) MtObject* sCaplinkManager::cGroupChatData::MyDTI::newInstance() const {
    DDON_STUB("sCaplinkManager::cGroupChatData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sCaplinkManager::cChatInfo::getDTI() const {
    return sCaplinkManager::cChatInfo::DTI;
}

inline sCaplinkManager::cChatInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::cChatInfo::MyDTI sCaplinkManager::cChatInfo::DTI("sCaplinkManager::cChatInfo", &::cCaplinkObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* sCaplinkManager::cChatInfo::MyDTI::newInstance() const {
    DDON_STUB("sCaplinkManager::cChatInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sCaplinkManager::cChatJoin::getDTI() const {
    return sCaplinkManager::cChatJoin::DTI;
}

inline sCaplinkManager::cChatJoin::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sCaplinkManager::cChatJoin::MyDTI sCaplinkManager::cChatJoin::DTI("sCaplinkManager::cChatJoin", &::cCaplinkObject::DTI, 16ul, 0u, 0u);

MtObject* sCaplinkManager::cChatJoin::MyDTI::newInstance() const {
    return new (16u) sCaplinkManager::cChatJoin;
}

__attribute__((weak)) void sCaplinkManager::cCaplinkWebsocketListener::onOpen() {
    DDON_STUB("sCaplinkManager::cCaplinkWebsocketListener::onOpen")
    /* stub */
}

void sCaplinkManager::cCaplinkWebsocketListener::onNotifyChat(nCaplink::WebsocketNotifyChat* notify) {
    if (notify == nullptr) {
        return;
    }
    sCaplinkManager::getInstance()->addChatList(notify);
}

__attribute__((weak)) void sCaplinkManager::cCaplinkWebsocketListener::onError(s32 error_code) {
    DDON_STUB("sCaplinkManager::cCaplinkWebsocketListener::onError")
    /* stub */
}

void sCaplinkManager::cCaplinkWebsocketListener::onClose() {
    mIsConnected = false;
    mIsError = false;
    mIsRegistDevice = false;
    if (sCaplinkManager::getInstance()->mpCaplink == nullptr) {
        return;
    }
    if (!sCaplinkManager::getInstance()->mpCaplink->getRetry()) {
        return;
    }
    mIsRegistDevice = true;
}

__attribute__((weak)) void sCaplinkManager::cChatMessageParser::fieldName(MT_CTSTR chars, const u32 length) {
    DDON_STUB("sCaplinkManager::cChatMessageParser::fieldName")
    /* stub */
}

__attribute__((weak)) void sCaplinkManager::cChatMessageParser::string(MT_CTSTR chars, const u32 length) {
    DDON_STUB("sCaplinkManager::cChatMessageParser::string")
    /* stub */
}

void sCaplinkManager::cChatMessageParser::number(s64 value) {
    if (mFlag == 6) {
        mIsResign = static_cast<unsigned char>(value);
    } else {
        if (mFlag == 1) {
            mGroupSkinId = static_cast<s32>(static_cast<unsigned int>(value));
        }
    }
}

void sCaplinkManager::cChatMessageParser::booleanTrue() {
    if (mFlag != 6) {
        return;
    }
    mIsResign = 1;
}

void sCaplinkManager::cChatMessageParser::booleanFalse() {
    if (mFlag != 6) {
        return;
    }
    mIsResign = 0;
}

__attribute__((weak)) void sCaplinkManager::cChatMessageParser::parse(MT_CTSTR pMessage) {
    DDON_STUB("sCaplinkManager::cChatMessageParser::parse")
    /* stub */
}

template MtTypedArray<nCaplink::cAchievementExtendedInfo>::~MtTypedArray();

template MtTypedArray<nCaplink::cAchievementListInfo>::~MtTypedArray();

template MtTypedArray<nCaplink::cAchievementRelationInfo>::~MtTypedArray();

template MtTypedArray<nCaplink::cUserBaseInfo>::~MtTypedArray();

template MtTypedArray<nCaplink::cWebsocketServerInfo>::~MtTypedArray();

template MtTypedArray<sCaplinkManager::cCaplinkListenerQueue>::~MtTypedArray();

template MtTypedArray<sCaplinkManager::cChatInfo>::~MtTypedArray();

template MtTypedArray<sCaplinkManager::cChatJoin>::~MtTypedArray();

template MtTypedArray<sCaplinkManager::cContentData>::~MtTypedArray();

template MtTypedArray<sCaplinkManager::cGroupChatData>::~MtTypedArray();

template MtTypedArray<sCaplinkManager::cIconUrl>::~MtTypedArray();

template MtTypedArray<sCaplinkManager::cProfIconLoader>::~MtTypedArray();

