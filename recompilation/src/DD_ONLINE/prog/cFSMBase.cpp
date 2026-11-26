// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cFSMBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "aStage.h"
#include "../../XFramework/cAIObject.h"
#include "../../XFramework/cAIUserProcess.h"
#include "../../XFramework/cArea.h"
#include "cFSMCore.h"
#include "cFSMOrderParam.h"
#include "cQuestTask.h"
#include "cTalkMsgData.h"
#include "nDDOUtility.h"
#include "nQuest.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sChat.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sQuestManagerExt.h"
#include "sTalkManager.h"
#include "uCameraBase.h"
#include "uCameraGame.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cFSMBase::getDTI() const {
    return cFSMBase::DTI;
}

inline void* cFSMBase::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMBase::DTI)->memAlloc(sz, align, cFSMBase::DTI.getID());
}

inline void cFSMBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMBase::DTI)->memFree(p_addr);
}

void cFSMBase::callbackUpdate() {
    mRno = 0;
    mIsMyQuestFlag = false;
}

u32 cFSMBase::stateCallMessage(MtObject* pParam, MtObject* pCaller) {
    if (!mIsDispMsg) {
        if (!static_cast<sGUIExt*>(sGUI::getInstance())->isTelopFSMEnd()) {
            mIsDispMsg = true;
        }
        if (sArea::getInstance()->mpArea[2] != nullptr) {
            if (!static_cast<aStage*>(sArea::getInstance()->mpArea[2])->mbFsmEventPlay) {
                mIsDispMsg = true;
            }
        }
    }
    return 0;
}

u32 cFSMBase::stateUpdateCallMessage(MtObject* pParam, MtObject* pCaller) {
    cParamCallMessage* pMsgParam = static_cast<cParamCallMessage*>(pParam);
    sTalkManager::getInstance()->callFSMEventMsg(pMsgParam->mMsgType, pMsgParam->mQstNo, pMsgParam->mMsgNo, pMsgParam->mMsgDispTime, pMsgParam->mMsgWaitTime, pMsgParam->mIsUseSerial, pMsgParam->mIsHideMessage);
    mIsDispMsg = false;
    mFsmMesWaitTime = 0.16666667f + (pMsgParam->mMsgDispTime + pMsgParam->mMsgWaitTime);
    mChangeCountState = mFsmMesWaitTime;
    return 0;
}

u32 cFSMBase::stateCallMessageFortDef_Common(MtObject* pParam, MtObject* pCaller) {
    if (!mIsDispMsg) {
        if (!static_cast<sGUIExt*>(sGUI::getInstance())->isTelopFSMEnd()) {
            mIsDispMsg = true;
        }
        if (sArea::getInstance()->mpArea[2] != nullptr) {
            if (!static_cast<aStage*>(sArea::getInstance()->mpArea[2])->mbFsmEventPlay) {
                mIsDispMsg = true;
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 cFSMBase::stateUpdateCallMessageFortDef_Common(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMBase::stateUpdateCallMessageFortDef_Common")
    return {};
}

u32 cFSMBase::stateCallMessageFortDef_BattleStart(MtObject* pParam, MtObject* pCaller) {
    if (!mIsDispMsg) {
        if (!static_cast<sGUIExt*>(sGUI::getInstance())->isTelopFSMEnd()) {
            mIsDispMsg = true;
        }
        if (sArea::getInstance()->mpArea[2] != nullptr) {
            if (!static_cast<aStage*>(sArea::getInstance()->mpArea[2])->mbFsmEventPlay) {
                mIsDispMsg = true;
            }
        }
    }
    return 0;
}

__attribute__((weak)) u32 cFSMBase::stateUpdateCallMessageFortDef_BattleStart(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMBase::stateUpdateCallMessageFortDef_BattleStart")
    return {};
}

u32 cFSMBase::stateUpdateGameGlobalFlagOn(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        cFSMOrderParamFlagCommon* pParamFlag = static_cast<cFSMOrderParamFlagCommon*>(pParam);
        sFlag::getInstance()->setFlag(3u, static_cast<u32>(pParamFlag->mFlagNo), true, true, false);
        return 0;
    } else {
        return 0;
    }
}

u32 cFSMBase::stateUpdateGameGlobalFlagOff(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        cFSMOrderParamFlagCommon* pParamFlag = static_cast<cFSMOrderParamFlagCommon*>(pParam);
        sFlag::getInstance()->setFlag(3u, static_cast<u32>(pParamFlag->mFlagNo), false, true, false);
        return 0;
    } else {
        return 0;
    }
}

__attribute__((weak)) u32 cFSMBase::stateUpdateMainQuestFlagOn(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMBase::stateUpdateMainQuestFlagOn")
    return {};
}

u32 cFSMBase::stateUpdateSceFlagOn(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        cFSMOrderParamFlagCommon* pParamFlag = static_cast<cFSMOrderParamFlagCommon*>(pParam);
        sFlag::getInstance()->setFlag(8u, static_cast<u32>(pParamFlag->mFlagNo), true, true, false);
        return 0;
    } else {
        return 0;
    }
}

u32 cFSMBase::stateUpdateSceFlagOff(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        cFSMOrderParamFlagCommon* pParamFlag = static_cast<cFSMOrderParamFlagCommon*>(pParam);
        sFlag::getInstance()->setFlag(8u, static_cast<u32>(pParamFlag->mFlagNo), false, true, false);
        return 0;
    } else {
        return 0;
    }
}

u32 cFSMBase::stateUpdateEvtFlagOn(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        cFSMOrderParamFlagCommon* pParamFlag = static_cast<cFSMOrderParamFlagCommon*>(pParam);
        sFlag::getInstance()->setFlag(9u, static_cast<u32>(pParamFlag->mFlagNo), true, true, false);
        return 0;
    } else {
        return 0;
    }
}

u32 cFSMBase::stateUpdateEvtFlagOff(MtObject* pParam, MtObject* pCaller) {
    if (pParam != nullptr) {
        cFSMOrderParamFlagCommon* pParamFlag = static_cast<cFSMOrderParamFlagCommon*>(pParam);
        sFlag::getInstance()->setFlag(9u, static_cast<u32>(pParamFlag->mFlagNo), false, true, false);
        return 0;
    } else {
        return 0;
    }
}

u32 cFSMBase::stateUpdateQuestInfo(MtObject* pParam, MtObject* pCaller) {
    const MtDTI& t0 = pParam->getDTI();
    MT_CTSTR v0_1 = cFSMOrderParamQuestInfo::DTI.mName;
    if (v0_1 != t0.mName) {
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_0->mpParent == nullptr) {
                return 0;
            } else {
                if (v0_1 != v0_0->mpParent->mName) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
        if (pParam == nullptr) {
            return 0;
        }
    }
    cFSMOrderParamQuestInfo* pQstInfo = static_cast<cFSMOrderParamQuestInfo*>(pParam);
    mQuestType = pQstInfo->mQuestType;
    mQuestId = pQstInfo->mQuestId;
    return 0;
}

__attribute__((weak)) u32 cFSMBase::stateIsMyQuestFlag(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMBase::stateIsMyQuestFlag")
    return {};
}

__attribute__((weak)) u32 cFSMBase::stateUpdateCallAnnounce(MtObject* pParam, MtObject* pCaller) {
    DDON_STUB("cFSMBase::stateUpdateCallAnnounce")
    return {};
}

bool cFSMBase::isEndCameraCut(u32 cutNo) const {
    uCameraGame* pCam = static_cast<sCameraExt*>(sCamera::getInstance())->getGameCamera();
    if (pCam != nullptr) {
        if (pCam->isInitial()) {
            s32 t0 = pCam->getCut();
            return static_cast<int>(cutNo) < t0;
        }
    }
    return false;
}

u32 cFSMBase::getCameraCutNum() const {
    return 64;
}

bool cFSMBase::isEndCameraSdr(u32 idx) const {
    return idx < mNowCamSdrIdx;
}

u32 cFSMBase::getCameraSdrNum() const {
    return 16;
}

bool cFSMBase::isNowCameraSdr(u32 idx) const {
    return mNowCamSdrIdx == idx;
}

uCameraGame* cFSMBase::getTargetCamera() const {
    uCameraGame* pCam = static_cast<sCameraExt*>(sCamera::getInstance())->getGameCamera();
    if ((pCam != nullptr) && pCam->isInitial()) {
        return pCam;
    }
    return nullptr;
}

__attribute__((weak)) bool cFSMBase::getGGFlag(u32 flagNo) const {
    DDON_STUB("cFSMBase::getGGFlag")
    return {};
}

u32 cFSMBase::getGGFlagNum() const {
    return 512;
}

__attribute__((weak)) bool cFSMBase::getMyQuestFlag(u32 flagNo) const {
    DDON_STUB("cFSMBase::getMyQuestFlag")
    return {};
}

u32 cFSMBase::getMyQuestFlagNum() {
    if (mQuestType != 0) {
        if (mQuestType == 1) {
            return 32;
        } else {
            return 0;
        }
    } else {
        return 64;
    }
}

__attribute__((weak)) bool cFSMBase::getSceFlag(u32 flagNo) const {
    DDON_STUB("cFSMBase::getSceFlag")
    return {};
}

u32 cFSMBase::getSceFlagNum() const {
    return 256;
}

__attribute__((weak)) bool cFSMBase::getEvtFlag(u32 flagNo) const {
    DDON_STUB("cFSMBase::getEvtFlag")
    return {};
}

u32 cFSMBase::getEvtFlagNum() const {
    return 64;
}

bool cFSMBase::isMyQuestFlag() const {
    return mIsMyQuestFlag;
}

u32 cFSMBase::getMyQuestFlagArrayNum() const {
    return 4;
}

bool cFSMBase::isMyQuestFlagArray(u32 idx) const {
    return mIsMyQuestFlagArray[idx];
}

bool cFSMBase::isFadeEnded() const {
    return sGame::getInstance()->isFadeEnd();
}

bool cFSMBase::isFadeOut() const {
    return sGame::getInstance()->isFadeOut();
}

bool cFSMBase::isMessageEnded() const {
    if ((sArea::getInstance()->mpArea[2] != nullptr) && static_cast<aStage*>(sArea::getInstance()->mpArea[2])->isFsmEventPlay()) {
        return mCountState >= mFsmMesWaitTime;
    }
    if (mIsDispMsg) {
        return sTalkManager::getInstance()->isEndTellMsg();
    } else {
        return false;
    }
}

cFSMBase::cFSMBase() {
    mIsDispMsg = false;
    mQuestType = 0;
    mQuestId = 0;
    mIsMyQuestFlag = false;
    mNowCamSdrIdx = 0;
    mOldCamCutNo = 0;
    mRno = 0;
    mFsmMesWaitTime = 0.0f;
    addFSMAction("CallMessage", static_cast<const MtDTI*>(&cFSMBase::DTI), static_cast<const MtDTI*>(&cFSMBase::cParamCallMessage::DTI), static_cast<PROCESS_FUNC>(&::cFSMBase::stateUpdateCallMessage), static_cast<PROCESS_FUNC>(&::cFSMBase::stateCallMessage));
    addFSMAction("CallMessageFortDef_Common", static_cast<const MtDTI*>(&cFSMBase::DTI), static_cast<const MtDTI*>(&cFSMBase::cParamCallMessageFortDef_Common::DTI), static_cast<PROCESS_FUNC>(&::cFSMBase::stateUpdateCallMessageFortDef_Common), static_cast<PROCESS_FUNC>(&::cFSMBase::stateCallMessageFortDef_Common));
    addFSMAction("CallMessageFortDef_BattleStart", static_cast<const MtDTI*>(&cFSMBase::DTI), static_cast<const MtDTI*>(&cFSMBase::cParamCallMessageFortDef_Common::DTI), static_cast<PROCESS_FUNC>(&::cFSMBase::stateUpdateCallMessageFortDef_BattleStart), static_cast<PROCESS_FUNC>(&::cFSMBase::stateCallMessageFortDef_BattleStart));
    addFSMAction("MainQstFlagOn", static_cast<const MtDTI*>(&cFSMBase::DTI), static_cast<const MtDTI*>(&cFSMOrderParamFlagQuest::DTI), static_cast<PROCESS_FUNC>(&::cFSMBase::stateUpdateMainQuestFlagOn), static_cast<cFSMCore::PROCESS_FUNC>(0));
    addFSMAction("EventFlagOn", static_cast<const MtDTI*>(&cFSMBase::DTI), static_cast<const MtDTI*>(&cFSMOrderParamFlagCommon::DTI), static_cast<PROCESS_FUNC>(&::cFSMBase::stateUpdateEvtFlagOn), static_cast<cFSMCore::PROCESS_FUNC>(0));
    addFSMAction("SetQuestInfo", static_cast<const MtDTI*>(&cFSMBase::DTI), static_cast<const MtDTI*>(&cFSMOrderParamQuestInfo::DTI), static_cast<PROCESS_FUNC>(&::cFSMBase::stateUpdateQuestInfo), static_cast<cFSMCore::PROCESS_FUNC>(0));
    addFSMAction("checkMyQuestFlag", static_cast<const MtDTI*>(&cFSMBase::DTI), static_cast<const MtDTI*>(&cFSMOrderParamIsMyQuestFlag::DTI), static_cast<cFSMCore::PROCESS_FUNC>(0), static_cast<PROCESS_FUNC>(&::cFSMBase::stateIsMyQuestFlag));
    addFSMAction("callAnnounce", static_cast<const MtDTI*>(&cFSMBase::DTI), static_cast<const MtDTI*>(&cFSMOrderParamCallAnnounce::DTI), static_cast<PROCESS_FUNC>(&::cFSMBase::stateUpdateCallAnnounce), static_cast<cFSMCore::PROCESS_FUNC>(0));
}

cFSMBase::~cFSMBase() {
}

void cFSMBase::createProperty(MtPropertyList& s) {
    this->cFSMCore::createProperty(s);
}

void cFSMBase::move() {
    this->cFSMCore::move();
    uCameraGame* pCam = static_cast<sCameraExt*>(sCamera::getInstance())->getGameCamera();
    if (pCam == nullptr) {
        return;
    }
    if (!pCam->isInitial()) {
        return;
    }
    const u32 cutNo = pCam->getCut();
    if (cutNo == 0) {
        if (mOldCamCutNo != 0) {
            mNowCamSdrIdx = mNowCamSdrIdx + 1u;
        }
    }
    mOldCamCutNo = cutNo;
}

void cFSMBase::createPropertyFSM(MtPropertyList& s) {
    this->cFSMCore::createPropertyFSM(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsEndFade", reinterpret_cast<MT_MFUNC>(&::cFSMBase::isFadeEnded), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsFadeOut", reinterpret_cast<MT_MFUNC>(&::cFSMBase::isFadeOut), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsEndMessage", reinterpret_cast<MT_MFUNC>(&::cFSMBase::isMessageEnded), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsEndCamCut", reinterpret_cast<MT_MFUNC>(&::cFSMBase::isEndCameraCut), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cFSMBase::getCameraCutNum), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsEndCamSdr", reinterpret_cast<MT_MFUNC>(&::cFSMBase::isEndCameraSdr), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cFSMBase::getCameraSdrNum), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsNowCamSdr", reinterpret_cast<MT_MFUNC>(&::cFSMBase::isNowCameraSdr), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cFSMBase::getCameraSdrNum), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "GGFlag", reinterpret_cast<MT_MFUNC>(&::cFSMBase::getGGFlag), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cFSMBase::getGGFlagNum), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "MyQstFlag", reinterpret_cast<MT_MFUNC>(&::cFSMBase::getMyQuestFlag), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cFSMBase::getMyQuestFlagNum), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsMyQuestFlag", reinterpret_cast<MT_MFUNC>(&::cFSMBase::isMyQuestFlag), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsMyQuestFlags", reinterpret_cast<MT_MFUNC>(&::cFSMBase::isMyQuestFlagArray), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cFSMBase::getMyQuestFlagArrayNum), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "SceFlag", reinterpret_cast<MT_MFUNC>(&::cFSMBase::getSceFlag), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cFSMBase::getSceFlagNum), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "EventFlag", reinterpret_cast<MT_MFUNC>(&::cFSMBase::getEvtFlag), static_cast<MT_MFUNC>(0), 163u, reinterpret_cast<MT_MFUNC>(&::cFSMBase::getEvtFlagNum), static_cast<MT_MFUNC>(0));
}

inline cFSMBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMBase::MyDTI cFSMBase::DTI("cFSMBase", &::cFSMCore::DTI, 184ul, 0u, 0u);

MtObject* cFSMBase::MyDTI::newInstance() const {
    return new (16u) cFSMBase;
}

const MtDTI& cFSMBase::cParamCallMessage::getDTI() const {
    return cFSMBase::cParamCallMessage::DTI;
}

inline void* cFSMBase::cParamCallMessage::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMBase::cParamCallMessage::DTI)->memAlloc(sz, align, cFSMBase::cParamCallMessage::DTI.getID());
}

inline void cFSMBase::cParamCallMessage::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMBase::cParamCallMessage::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cFSMBase::cParamCallMessage::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgType", &mMsgType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQstNo", &mQstNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgNo", &mMsgNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgDispTime", &mMsgDispTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgWaitTime", &mMsgWaitTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUseSerial", &mIsUseSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsHideMessage", &mIsHideMessage, 0u, 0u);
}

MtUI* cFSMBase::cParamCallMessage::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMBase::cParamCallMessage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMBase::cParamCallMessage::MyDTI cFSMBase::cParamCallMessage::DTI("cFSMBase::cParamCallMessage", &::cAICopiableParameter::DTI, 32ul, 0u, 0u);

MtObject* cFSMBase::cParamCallMessage::MyDTI::newInstance() const {
    return new (16u) cFSMBase::cParamCallMessage;
}

const MtDTI& cFSMBase::cParamCallMessageFortDef_Common::getDTI() const {
    return cFSMBase::cParamCallMessageFortDef_Common::DTI;
}

inline void* cFSMBase::cParamCallMessageFortDef_Common::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMBase::cParamCallMessageFortDef_Common::DTI)->memAlloc(sz, align, cFSMBase::cParamCallMessageFortDef_Common::DTI.getID());
}

inline void cFSMBase::cParamCallMessageFortDef_Common::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMBase::cParamCallMessageFortDef_Common::DTI)->memFree(p_addr);
}

void cFSMBase::cParamCallMessageFortDef_Common::createProperty(MtPropertyList& s) {
    this->cFSMBase::cParamCallMessage::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgNo1", &mMsgNo1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgNo2", &mMsgNo2, 0u, 0u);
}

MtUI* cFSMBase::cParamCallMessageFortDef_Common::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMBase::cParamCallMessageFortDef_Common::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMBase::cParamCallMessageFortDef_Common::MyDTI cFSMBase::cParamCallMessageFortDef_Common::DTI("cFSMBase::cParamCallMessageFortDef_Common", &::cFSMBase::cParamCallMessage::DTI, 40ul, 0u, 0u);

MtObject* cFSMBase::cParamCallMessageFortDef_Common::MyDTI::newInstance() const {
    return new (16u) cFSMBase::cParamCallMessageFortDef_Common;
}

