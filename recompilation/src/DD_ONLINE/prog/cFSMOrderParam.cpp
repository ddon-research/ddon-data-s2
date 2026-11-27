// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cFSMOrderParam.h"
#include "Protocol/PacketData/Enemy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cAIObject.h"
#include "../../XFramework/cAIUserProcess.h"
#include "cFSMRelate.h"
#include "sScenario.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cFSMOrderParam::getDTI() const {
    return cFSMOrderParam::DTI;
}

inline cFSMOrderParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParam::MyDTI cFSMOrderParam::DTI("cFSMOrderParam", &::cAICopiableParameter::DTI, 8ul, 0u, 0u);

MtObject* cFSMOrderParam::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParam;
}

const MtDTI& cFSMOrderParamAreaHit::getDTI() const {
    return cFSMOrderParamAreaHit::DTI;
}

cScenario* cFSMOrderParamAreaHit::getScenario() const {
    SCE_AH_LIST* pList = sScenario::getInstance()->getAreaHitList(static_cast<SCENARIO_TASK_ENUM>(mTaskType));
    if (pList != nullptr) {
        return pList->getScenario(mSceNo);
    } else {
        return nullptr;
    }
}

cFSMOrderParamAreaHit::~cFSMOrderParamAreaHit() {
}

void cFSMOrderParamAreaHit::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAct", &mAct, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTaskType", &mTaskType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSceNo", &mSceNo, 0u, 0u);
}

MtUI* cFSMOrderParamAreaHit::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamAreaHit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamAreaHit::MyDTI cFSMOrderParamAreaHit::DTI("cFSMOrderParamAreaHit", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamAreaHit::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamAreaHit;
}

const MtDTI& cFSMOrderParamBGMCommon::getDTI() const {
    return cFSMOrderParamBGMCommon::DTI;
}

void cFSMOrderParamBGMCommon::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mRequestNo", &mRequestNo, 0u, 0u);
}

inline cFSMOrderParamBGMCommon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamBGMCommon::MyDTI cFSMOrderParamBGMCommon::DTI("cFSMOrderParamBGMCommon", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamBGMCommon::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamBGMCommon;
}

const MtDTI& cFSMOrderParamBGMRequest::getDTI() const {
    return cFSMOrderParamBGMRequest::DTI;
}

void cFSMOrderParamBGMRequest::setRequestEditType(u32 editType) {
    mBgmRequestEditType = editType;
    if (editType == 31) {
        mBgmRequestType = 6;
        return;
    }
    if (editType > 2u) {
        mBgmRequestType = 2;
    } else {
        mBgmRequestNo = 0;
    }
    switch (editType) {
        case 0:
        {
            mBgmRequestType = 0;
            return;
        }
        case 1:
        {
            mBgmRequestType = 1;
            return;
        }
        case 2:
        {
            mBgmRequestType = 3;
            return;
        }
        case 3:
        {
            mBgmRequestNo = 20;
            return;
        }
        case 4:
        {
            mBgmRequestNo = 25;
            return;
        }
        case 5:
        {
            mBgmRequestNo = 30;
            return;
        }
        case 6:
        {
            mBgmRequestNo = 35;
            return;
        }
        case 7:
        {
            mBgmRequestNo = 40;
            return;
        }
        case 8:
        {
            mBgmRequestNo = 45;
            return;
        }
        case 9:
        {
            mBgmRequestNo = 50;
            return;
        }
        case 10:
        {
            mBgmRequestNo = 55;
            return;
        }
        case 11:
        {
            mBgmRequestNo = 60;
            return;
        }
        case 12:
        {
            mBgmRequestNo = 65;
            return;
        }
        case 13:
        {
            mBgmRequestNo = 66;
            return;
        }
        case 14:
        {
            mBgmRequestNo = 67;
            return;
        }
        case 15:
        {
            mBgmRequestNo = 68;
            return;
        }
        case 16:
        {
            mBgmRequestNo = 70;
            return;
        }
        case 17:
        {
            mBgmRequestNo = 71;
            return;
        }
        case 18:
        {
            mBgmRequestNo = 72;
            return;
        }
        case 19:
        {
            mBgmRequestNo = 73;
            return;
        }
        case 20:
        {
            mBgmRequestNo = 75;
            return;
        }
        case 21:
        {
            mBgmRequestNo = 31;
            return;
        }
        case 22:
        {
            mBgmRequestNo = 56;
            return;
        }
        case 24:
        {
            mBgmRequestNo = 80;
            return;
        }
        case 25:
        {
            mBgmRequestNo = 85;
            return;
        }
        case 26:
        {
            mBgmRequestType = 4;
            return;
        }
        case 27:
        {
            mBgmRequestType = 5;
            return;
        }
        case 28:
        {
            mBgmRequestNo = 81;
            return;
        }
        case 29:
        {
            mBgmRequestNo = 76;
            return;
        }
        case 30:
        {
            mBgmRequestNo = 82;
            break;
        }
        case 32:
        {
            mBgmRequestType = 7;
            return;
        }
        default:
        {
            break;
        }
    }
}

static auto ddon_emit_0x01988c20 __attribute__((used)) = &cFSMOrderParamBGMRequest::getRequestEditType;

cFSMOrderParamBGMRequest::~cFSMOrderParamBGMRequest() {
}

void cFSMOrderParamBGMRequest::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "BgmRequestEditType", reinterpret_cast<MT_MFUNC>(&::cFSMOrderParamBGMRequest::getRequestEditType), reinterpret_cast<MT_MFUNC>(&::cFSMOrderParamBGMRequest::setRequestEditType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mBgmRequestType", &mBgmRequestType, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBgmRequestNo", &mBgmRequestNo, 0u, 0u);
}

MtUI* cFSMOrderParamBGMRequest::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamBGMRequest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamBGMRequest::MyDTI cFSMOrderParamBGMRequest::DTI("cFSMOrderParamBGMRequest", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamBGMRequest::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamBGMRequest;
}

const MtDTI& cFSMOrderParamBGMStop::getDTI() const {
    return cFSMOrderParamBGMStop::DTI;
}

inline cFSMOrderParamBGMStop::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamBGMStop::MyDTI cFSMOrderParamBGMStop::DTI("cFSMOrderParamBGMStop", &::cFSMOrderParam::DTI, 8ul, 0u, 0u);

MtObject* cFSMOrderParamBGMStop::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamBGMStop;
}

const MtDTI& cFSMOrderParamCallAnnounce::getDTI() const {
    return cFSMOrderParamCallAnnounce::DTI;
}

cFSMOrderParamCallAnnounce::~cFSMOrderParamCallAnnounce() {
}

void cFSMOrderParamCallAnnounce::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestId", &mQuestId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgNo", &mMsgNo, 0u, 0u);
}

MtUI* cFSMOrderParamCallAnnounce::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamCallAnnounce::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamCallAnnounce::MyDTI cFSMOrderParamCallAnnounce::DTI("cFSMOrderParamCallAnnounce", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamCallAnnounce::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamCallAnnounce;
}

const MtDTI& cFSMOrderParamCallEvent::getDTI() const {
    return cFSMOrderParamCallEvent::DTI;
}

cFSMOrderParamCallEvent::~cFSMOrderParamCallEvent() {
    if (mNpcArray.mLength != 0) {
        u32 v0_0 = mNpcArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mNpcArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mNpcArray.mpArray[i0_3];
                v1_0 = mNpcArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNpcArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNpcArray.mpArray));
    }
    mNpcArray.mpArray = nullptr;
    mNpcArray.mBufsiz = 0;
    mNpcArray.mLength = 0;
}

void cFSMOrderParamCallEvent::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEventNo", &mEventNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNpcArray", static_cast<MtObject*>(&mNpcArray), 0u, 0u);
}

MtUI* cFSMOrderParamCallEvent::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

__attribute__((weak)) void cFSMOrderParamCallEvent::copy(cAICopiableParameter* pParam) {
    DDON_STUB("cFSMOrderParamCallEvent::copy")
    /* stub */
}

inline cFSMOrderParamCallEvent::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamCallEvent::MyDTI cFSMOrderParamCallEvent::DTI("cFSMOrderParamCallEvent", &::cFSMOrderParam::DTI, 48ul, 0u, 0u);

MtObject* cFSMOrderParamCallEvent::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamCallEvent;
}

const MtDTI& cFSMOrderParamCallEvent::cNpcId::getDTI() const {
    return cFSMOrderParamCallEvent::cNpcId::DTI;
}

void cFSMOrderParamCallEvent::cNpcId::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mNpcId", &mNpcId, 0u, 0u);
}

MtUI* cFSMOrderParamCallEvent::cNpcId::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cFSMOrderParamCallEvent::cNpcId::copy(cFSMOrderParamCallEvent::cNpcId* pSrc) {
    mNpcId = pSrc->mNpcId;
}

inline cFSMOrderParamCallEvent::cNpcId::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamCallEvent::cNpcId::MyDTI cFSMOrderParamCallEvent::cNpcId::DTI("cFSMOrderParamCallEvent::cNpcId", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamCallEvent::cNpcId::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamCallEvent::cNpcId;
}

const MtDTI& cFSMOrderParamCamera::getDTI() const {
    return cFSMOrderParamCamera::DTI;
}

void cFSMOrderParamCamera::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Camera:ActType", &mActType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Camera:CamRes", &mCamRes, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamId", &mCamId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamId", &mCamId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CameraEnemy:ActType", &mActType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCantActPl", &mCantActPl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamId", &mCamId, 0u, 0u);
}

MtUI* cFSMOrderParamCamera::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamCamera::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamCamera::MyDTI cFSMOrderParamCamera::DTI("cFSMOrderParamCamera", &::cFSMOrderParam::DTI, 32ul, 0u, 0u);

MtObject* cFSMOrderParamCamera::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamCamera;
}

const MtDTI& cFSMOrderParamChangeBattleThink::getDTI() const {
    return cFSMOrderParamChangeBattleThink::DTI;
}

void cFSMOrderParamChangeBattleThink::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBattleThink", &mBattleThink, 0u, 0u);
}

MtUI* cFSMOrderParamChangeBattleThink::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamChangeBattleThink::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamChangeBattleThink::MyDTI cFSMOrderParamChangeBattleThink::DTI("cFSMOrderParamChangeBattleThink", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamChangeBattleThink::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamChangeBattleThink;
}

const MtDTI& cFSMOrderParamCheckLayout::getDTI() const {
    return cFSMOrderParamCheckLayout::DTI;
}

cFSMOrderParamCheckLayout::~cFSMOrderParamCheckLayout() {
}

void cFSMOrderParamCheckLayout::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mActType", &mActType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLotNo", &mLotNo, 0u, 0u);
}

MtUI* cFSMOrderParamCheckLayout::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamCheckLayout::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamCheckLayout::MyDTI cFSMOrderParamCheckLayout::DTI("cFSMOrderParamCheckLayout", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamCheckLayout::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamCheckLayout;
}

const MtDTI& cFSMOrderParamCtrlSubSdl::getDTI() const {
    return cFSMOrderParamCtrlSubSdl::DTI;
}

void cFSMOrderParamCtrlSubSdl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCtrl", &mCtrl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSdlNo", &mSdlNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsLoop", &mIsLoop, 0u, 0u);
}

MtUI* cFSMOrderParamCtrlSubSdl::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamCtrlSubSdl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamCtrlSubSdl::MyDTI cFSMOrderParamCtrlSubSdl::DTI("cFSMOrderParamCtrlSubSdl", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamCtrlSubSdl::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamCtrlSubSdl;
}

const MtDTI& cFSMOrderParamFlagCommon::getDTI() const {
    return cFSMOrderParamFlagCommon::DTI;
}

void cFSMOrderParamFlagCommon::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mFlagNo", &mFlagNo, 0u, 0u);
}

MtUI* cFSMOrderParamFlagCommon::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamFlagCommon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamFlagCommon::MyDTI cFSMOrderParamFlagCommon::DTI("cFSMOrderParamFlagCommon", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamFlagCommon::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamFlagCommon;
}

const MtDTI& cFSMOrderParamFlagQuest::getDTI() const {
    return cFSMOrderParamFlagQuest::DTI;
}

void cFSMOrderParamFlagQuest::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestNo", &mQuestNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlagNo", &mFlagNo, 0u, 0u);
}

inline cFSMOrderParamFlagQuest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamFlagQuest::MyDTI cFSMOrderParamFlagQuest::DTI("cFSMOrderParamFlagQuest", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamFlagQuest::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamFlagQuest;
}

const MtDTI& cFSMOrderParamIsMyQuestFlag::getDTI() const {
    return cFSMOrderParamIsMyQuestFlag::DTI;
}

cFSMOrderParamIsMyQuestFlag::~cFSMOrderParamIsMyQuestFlag() {
}

void cFSMOrderParamIsMyQuestFlag::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mQuestId", &mQuestId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlagNo", &mFlagNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mArrayIdx", &mArrayIdx, 0u, 0u);
}

MtUI* cFSMOrderParamIsMyQuestFlag::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamIsMyQuestFlag::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamIsMyQuestFlag::MyDTI cFSMOrderParamIsMyQuestFlag::DTI("cFSMOrderParamIsMyQuestFlag", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamIsMyQuestFlag::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamIsMyQuestFlag;
}

const MtDTI& cFSMOrderParamJumpArea::getDTI() const {
    return cFSMOrderParamJumpArea::DTI;
}

void cFSMOrderParamJumpArea::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mJumpStageNo", &mJumpStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJumpStagePosNo", &mJumpStagePosNo, 0u, 0u);
}

inline cFSMOrderParamJumpArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamJumpArea::MyDTI cFSMOrderParamJumpArea::DTI("cFSMOrderParamJumpArea", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamJumpArea::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamJumpArea;
}

const MtDTI& cFSMOrderParamJumpPos::getDTI() const {
    return cFSMOrderParamJumpPos::DTI;
}

cFSMOrderParamJumpPos::~cFSMOrderParamJumpPos() {
}

void cFSMOrderParamJumpPos::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mJumpType", &mJumpType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJumpStagePosNo", &mJumpStagePosNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFadeOutTime", &mFadeOutTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFadeInTime", &mFadeInTime, 0u, 0u);
}

MtUI* cFSMOrderParamJumpPos::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamJumpPos::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamJumpPos::MyDTI cFSMOrderParamJumpPos::DTI("cFSMOrderParamJumpPos", &::cFSMOrderParam::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMOrderParamJumpPos::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamJumpPos::DTI)->memAlloc(sizeof(cFSMOrderParamJumpPos), 16u, cFSMOrderParamJumpPos::DTI.getID())) cFSMOrderParamJumpPos;
}

const MtDTI& cFSMOrderParamQuestInfo::getDTI() const {
    return cFSMOrderParamQuestInfo::DTI;
}

cFSMOrderParamQuestInfo::~cFSMOrderParamQuestInfo() {
}

void cFSMOrderParamQuestInfo::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestType", &mQuestType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestId", &mQuestId, 0u, 0u);
}

MtUI* cFSMOrderParamQuestInfo::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamQuestInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamQuestInfo::MyDTI cFSMOrderParamQuestInfo::DTI("cFSMOrderParamQuestInfo", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamQuestInfo::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamQuestInfo;
}

const MtDTI& cFSMOrderParamSetCallSe::getDTI() const {
    return cFSMOrderParamSetCallSe::DTI;
}

void cFSMOrderParamSetCallSe::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSeId", &mSeId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTarget", &mTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNo", &mJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDelayFrame", &mDelayFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 1024u, 0u);
}

MtUI* cFSMOrderParamSetCallSe::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamSetCallSe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetCallSe::MyDTI cFSMOrderParamSetCallSe::DTI("cFSMOrderParamSetCallSe", &::cFSMOrderParam::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMOrderParamSetCallSe::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetCallSe::DTI)->memAlloc(sizeof(cFSMOrderParamSetCallSe), 16u, cFSMOrderParamSetCallSe::DTI.getID())) cFSMOrderParamSetCallSe;
}

const MtDTI& cFSMOrderParamSetDispUnit::getDTI() const {
    return cFSMOrderParamSetDispUnit::DTI;
}

void* cFSMOrderParamSetDispUnit::operator new(size_t sz, u32 align) {
    return cFSMOrderParamSetDispUnit::getAllocator()->memAlloc(sz, align, cFSMOrderParamSetDispUnit::DTI.getID());
}

cFSMOrderParamSetDispUnit::cFSMOrderParamSetDispUnit() {
    mAct = 1;
    mIsStopMove = false;
    mSetId = 0;
    mQstId = 0;
    mTarget = 0;
    mGroupNo = 0;
}

cFSMOrderParamSetDispUnit::~cFSMOrderParamSetDispUnit() {
}

void cFSMOrderParamSetDispUnit::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAct", &mAct, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTarget", &mTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSetId", &mSetId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQstId", &mQstId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsStopMove", &mIsStopMove, 0u, 0u);
}

MtUI* cFSMOrderParamSetDispUnit::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamSetDispUnit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetDispUnit::MyDTI cFSMOrderParamSetDispUnit::DTI("cFSMOrderParamSetDispUnit", &::cFSMOrderParam::DTI, 32ul, 0u, 0u);

MtObject* cFSMOrderParamSetDispUnit::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamSetDispUnit;
}

const MtDTI& cFSMOrderParamSetEffect::getDTI() const {
    return cFSMOrderParamSetEffect::DTI;
}

void cFSMOrderParamSetEffect::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEfcId", &mEfcId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTarget", &mTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHaveItem", &mHaveItem, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAct", &mAct, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOmId", &mOmId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mElement", &mElement, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 1024u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAng", &mAng, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScl", &mScl, 0u, 0u);
}

MtUI* cFSMOrderParamSetEffect::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamSetEffect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetEffect::MyDTI cFSMOrderParamSetEffect::DTI("cFSMOrderParamSetEffect", &::cFSMOrderParam::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMOrderParamSetEffect::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetEffect::DTI)->memAlloc(sizeof(cFSMOrderParamSetEffect), 16u, cFSMOrderParamSetEffect::DTI.getID())) cFSMOrderParamSetEffect;
}

const MtDTI& cFSMOrderParamSetEnemy::getDTI() const {
    return cFSMOrderParamSetEnemy::DTI;
}

cFSMOrderParamSetEnemy::~cFSMOrderParamSetEnemy() {
    if (mSetEnemyInfo.mLength != 0) {
        u32 v0_0 = mSetEnemyInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSetEnemyInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSetEnemyInfo.mpArray[i0_3];
                v1_0 = mSetEnemyInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSetEnemyInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSetEnemyInfo.mpArray));
    }
    mSetEnemyInfo.mpArray = nullptr;
    mSetEnemyInfo.mBufsiz = 0;
    mSetEnemyInfo.mLength = 0;
}

void cFSMOrderParamSetEnemy::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSetEnemyInfo", static_cast<MtObject*>(&mSetEnemyInfo), 0u, 0u);
}

MtUI* cFSMOrderParamSetEnemy::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

__attribute__((weak)) void cFSMOrderParamSetEnemy::copy(cAICopiableParameter* pParam) {
    DDON_STUB("cFSMOrderParamSetEnemy::copy")
    /* stub */
}

inline cFSMOrderParamSetEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetEnemy::MyDTI cFSMOrderParamSetEnemy::DTI("cFSMOrderParamSetEnemy", &::cFSMOrderParam::DTI, 48ul, 0u, 0u);

MtObject* cFSMOrderParamSetEnemy::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamSetEnemy;
}

const MtDTI& cFSMOrderParamSetEnemy::cSetEmInfo::getDTI() const {
    return cFSMOrderParamSetEnemy::cSetEmInfo::DTI;
}

u32 cFSMOrderParamSetEnemy::cSetEmInfo::getEnemyId() const {
    u32 enumEnemyId = nEnemy::findEnemyEnumID(mEnemyId);
    if (enumEnemyId == 0xFFFFFFFFu) {
        return mEnemyId;
    } else {
        return enumEnemyId;
    }
}

__attribute__((weak)) const MtVector3 cFSMOrderParamSetEnemy::cSetEmInfo::getPos() const {
    DDON_STUB("cFSMOrderParamSetEnemy::cSetEmInfo::getPos")
    __builtin_unreachable();
}

const MtVector3 cFSMOrderParamSetEnemy::cSetEmInfo::getAngleZXY() const {
    return mMat.eulerAngleZXY();
}

cFSMOrderParamSetEnemy::cSetEmInfo::~cSetEmInfo() {
}

void cFSMOrderParamSetEnemy::cSetEmInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEnemyId", &mEnemyId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMat", &mMat, 0u, 0u);
    mFsmPath.cFSMRelate::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mErosionLv", &mErosionLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupId", &mGroupId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSetId", &mSetId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "Pos", reinterpret_cast<MT_MFUNC>(&::cFSMOrderParamSetEnemy::cSetEmInfo::getPos), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "Angle", reinterpret_cast<MT_MFUNC>(&::cFSMOrderParamSetEnemy::cSetEmInfo::getAngleZXY), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* cFSMOrderParamSetEnemy::cSetEmInfo::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cFSMOrderParamSetEnemy::cSetEmInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetEnemy::cSetEmInfo::MyDTI cFSMOrderParamSetEnemy::cSetEmInfo::DTI("cFSMOrderParamSetEnemy::cSetEmInfo", &::MtObject::DTI, 128ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMOrderParamSetEnemy::cSetEmInfo::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetEnemy::cSetEmInfo::DTI)->memAlloc(sizeof(cFSMOrderParamSetEnemy::cSetEmInfo), 16u, cFSMOrderParamSetEnemy::cSetEmInfo::DTI.getID())) cFSMOrderParamSetEnemy::cSetEmInfo;
}

const MtDTI& cFSMOrderParamSetFade::getDTI() const {
    return cFSMOrderParamSetFade::DTI;
}

void cFSMOrderParamSetFade::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mFadeType", &mFadeType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFadeTime", &mFadeTime, 0u, 0u);
}

MtUI* cFSMOrderParamSetFade::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamSetFade::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetFade::MyDTI cFSMOrderParamSetFade::DTI("cFSMOrderParamSetFade", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamSetFade::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamSetFade;
}

const MtDTI& cFSMOrderParamSetLayout::getDTI() const {
    return cFSMOrderParamSetLayout::DTI;
}

void cFSMOrderParamSetLayout::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mActType", &mActType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlagNo", &mFlagNo, 0u, 0u);
}

MtUI* cFSMOrderParamSetLayout::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamSetLayout::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetLayout::MyDTI cFSMOrderParamSetLayout::DTI("cFSMOrderParamSetLayout", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamSetLayout::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamSetLayout;
}

const MtDTI& cFSMOrderParamSetLocationName::getDTI() const {
    return cFSMOrderParamSetLocationName::DTI;
}

void cFSMOrderParamSetLocationName::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
}

inline cFSMOrderParamSetLocationName::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetLocationName::MyDTI cFSMOrderParamSetLocationName::DTI("cFSMOrderParamSetLocationName", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamSetLocationName::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamSetLocationName;
}

const MtDTI& cFSMOrderParamSetOpenDoor::getDTI() const {
    return cFSMOrderParamSetOpenDoor::DTI;
}

void cFSMOrderParamSetOpenDoor::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSetNo", &mSetNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsQuestSet", &mIsQuestSet, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestId", &mQuestId, 0u, 0u);
}

MtUI* cFSMOrderParamSetOpenDoor::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamSetOpenDoor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetOpenDoor::MyDTI cFSMOrderParamSetOpenDoor::DTI("cFSMOrderParamSetOpenDoor", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamSetOpenDoor::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamSetOpenDoor;
}

const MtDTI& cFSMOrderParamSetVib::getDTI() const {
    return cFSMOrderParamSetVib::DTI;
}

void cFSMOrderParamSetVib::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mVib", &mVib, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNum", &mNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaitSec", &mWaitSec, 0u, 0u);
}

inline cFSMOrderParamSetVib::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetVib::MyDTI cFSMOrderParamSetVib::DTI("cFSMOrderParamSetVib", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

MtObject* cFSMOrderParamSetVib::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamSetVib;
}

const MtDTI& cFSMOrderParamStartQuake::getDTI() const {
    return cFSMOrderParamStartQuake::DTI;
}

cFSMOrderParamStartQuake::~cFSMOrderParamStartQuake() {
}

void cFSMOrderParamStartQuake::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTargetType", &mTargetType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetGroup", &mTargetGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetId", &mTargetId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeadTime", &mHeadTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMainTime", &mMainTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTailTime", &mTailTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMagnitude", &mMagnitude, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRadius", &mRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpread", &mSpread, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDamping", &mDamping, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPeriod", &mPeriod, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRoll", &mRoll, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBalance", &mBalance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsAsync", &mIsAsync, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamera1QuakeTime", &mCamera1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTarget1QuakeTime", &mTarget1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRoll1QuakeTime", &mRoll1QuakeTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRandDrop", &mRandDrop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeadCurve", &mHeadCurve, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTailCurve", &mTailCurve, 0u, 0u);
}

MtUI* cFSMOrderParamStartQuake::createUI(MtProperty& prop) {
    return this->cAIResource::createUI(prop);
}

inline cFSMOrderParamStartQuake::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamStartQuake::MyDTI cFSMOrderParamStartQuake::DTI("cFSMOrderParamStartQuake", &::cFSMOrderParam::DTI, 128ul, 0u, 0u);

MtObject* cFSMOrderParamStartQuake::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamStartQuake;
}

const MtDTI& cFSMOrderParamStopQuake::getDTI() const {
    return cFSMOrderParamStopQuake::DTI;
}

cFSMOrderParamStopQuake::~cFSMOrderParamStopQuake() {
}

void cFSMOrderParamStopQuake::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsForceStop", &mIsForceStop, 0u, 0u);
}

inline cFSMOrderParamStopQuake::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamStopQuake::MyDTI cFSMOrderParamStopQuake::DTI("cFSMOrderParamStopQuake", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

MtObject* cFSMOrderParamStopQuake::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParamStopQuake;
}

template MtTypedArray<cFSMOrderParamCallEvent::cNpcId>::~MtTypedArray();

template MtTypedArray<cFSMOrderParamSetEnemy::cSetEmInfo>::~MtTypedArray();

