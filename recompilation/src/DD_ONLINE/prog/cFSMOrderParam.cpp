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

inline void* cFSMOrderParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMOrderParam::DTI)->memAlloc(sz, align, cFSMOrderParam::DTI.getID());
}

inline void cFSMOrderParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParam::DTI)->memFree(p_addr);
}

inline cFSMOrderParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParam::MyDTI cFSMOrderParam::DTI("cFSMOrderParam", &::cAICopiableParameter::DTI, 8ul, 0u, 0u);

MtObject* cFSMOrderParam::MyDTI::newInstance() const {
    return new (16u) cFSMOrderParam;
}

const MtDTI& cFSMOrderParamAreaHit::getDTI() const {
    return cFSMOrderParamAreaHit::DTI;
}

inline void cFSMOrderParamAreaHit::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamAreaHit::DTI)->memFree(p_addr);
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

inline cFSMOrderParamAreaHit::cFSMOrderParamAreaHit() {
    mAct = 1;
    mTaskType = 0;
    mSceNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamAreaHit::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamAreaHit::DTI)->memAlloc(sizeof(cFSMOrderParamAreaHit), 16u, cFSMOrderParamAreaHit::DTI.getID())) cFSMOrderParamAreaHit;
}

const MtDTI& cFSMOrderParamBGMCommon::getDTI() const {
    return cFSMOrderParamBGMCommon::DTI;
}

inline void cFSMOrderParamBGMCommon::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamBGMCommon::DTI)->memFree(p_addr);
}

void cFSMOrderParamBGMCommon::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mRequestNo", &mRequestNo, 0u, 0u);
}

inline cFSMOrderParamBGMCommon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamBGMCommon::MyDTI cFSMOrderParamBGMCommon::DTI("cFSMOrderParamBGMCommon", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMOrderParamBGMCommon::MyDTI::newInstance() const {
    DDON_STUB("cFSMOrderParamBGMCommon::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cFSMOrderParamBGMRequest::getDTI() const {
    return cFSMOrderParamBGMRequest::DTI;
}

inline void cFSMOrderParamBGMRequest::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamBGMRequest::DTI)->memFree(p_addr);
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

inline cFSMOrderParamBGMRequest::cFSMOrderParamBGMRequest() {
    mBgmRequestType = 0;
    mBgmRequestNo = 0;
    mBgmRequestEditType = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamBGMRequest::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamBGMRequest::DTI)->memAlloc(sizeof(cFSMOrderParamBGMRequest), 16u, cFSMOrderParamBGMRequest::DTI.getID())) cFSMOrderParamBGMRequest;
}

const MtDTI& cFSMOrderParamBGMStop::getDTI() const {
    return cFSMOrderParamBGMStop::DTI;
}

inline void cFSMOrderParamBGMStop::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamBGMStop::DTI)->memFree(p_addr);
}

inline cFSMOrderParamBGMStop::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamBGMStop::MyDTI cFSMOrderParamBGMStop::DTI("cFSMOrderParamBGMStop", &::cFSMOrderParam::DTI, 8ul, 0u, 0u);

inline cFSMOrderParamBGMStop::cFSMOrderParamBGMStop() {
}

__attribute__((weak)) MtObject* cFSMOrderParamBGMStop::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamBGMStop::DTI)->memAlloc(sizeof(cFSMOrderParamBGMStop), 16u, cFSMOrderParamBGMStop::DTI.getID())) cFSMOrderParamBGMStop;
}

const MtDTI& cFSMOrderParamCallAnnounce::getDTI() const {
    return cFSMOrderParamCallAnnounce::DTI;
}

inline void cFSMOrderParamCallAnnounce::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamCallAnnounce::DTI)->memFree(p_addr);
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

inline cFSMOrderParamCallAnnounce::cFSMOrderParamCallAnnounce() {
    mType = 1;
    mQuestId = 0;
    mMsgNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamCallAnnounce::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamCallAnnounce::DTI)->memAlloc(sizeof(cFSMOrderParamCallAnnounce), 16u, cFSMOrderParamCallAnnounce::DTI.getID())) cFSMOrderParamCallAnnounce;
}

const MtDTI& cFSMOrderParamCallEvent::getDTI() const {
    return cFSMOrderParamCallEvent::DTI;
}

inline void cFSMOrderParamCallEvent::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamCallEvent::DTI)->memFree(p_addr);
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

inline cFSMOrderParamCallEvent::cFSMOrderParamCallEvent() {
    mStageNo = 0;
    mEventNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamCallEvent::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamCallEvent::DTI)->memAlloc(sizeof(cFSMOrderParamCallEvent), 16u, cFSMOrderParamCallEvent::DTI.getID())) cFSMOrderParamCallEvent;
}

const MtDTI& cFSMOrderParamCallEvent::cNpcId::getDTI() const {
    return cFSMOrderParamCallEvent::cNpcId::DTI;
}

inline void* cFSMOrderParamCallEvent::cNpcId::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cFSMOrderParamCallEvent::cNpcId::DTI)->memAlloc(sz, align, cFSMOrderParamCallEvent::cNpcId::DTI.getID());
}

inline void cFSMOrderParamCallEvent::cNpcId::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamCallEvent::cNpcId::DTI)->memFree(p_addr);
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

inline void cFSMOrderParamCamera::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamCamera::DTI)->memFree(p_addr);
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

inline cFSMOrderParamCamera::cFSMOrderParamCamera() {
    mCamId = 0;
    mCamType = 0;
    mActType = 0;
    mCamRes = 0;
    mCantActPl = false;
    mIsFsmEvent = true;
    mStartPosNo = 0;
    mPlStopTime = 0.0f;
    mSetPosType = 0;
    mIsSelfDisplayed = false;
    mIsEnemyAndNpcDisplayed = false;
    mIsMessageCleared = false;
    mIsSelfStopped = false;
}

__attribute__((weak)) MtObject* cFSMOrderParamCamera::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamCamera::DTI)->memAlloc(sizeof(cFSMOrderParamCamera), 16u, cFSMOrderParamCamera::DTI.getID())) cFSMOrderParamCamera;
}

const MtDTI& cFSMOrderParamChangeBattleThink::getDTI() const {
    return cFSMOrderParamChangeBattleThink::DTI;
}

inline void cFSMOrderParamChangeBattleThink::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamChangeBattleThink::DTI)->memFree(p_addr);
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

__attribute__((weak)) MtObject* cFSMOrderParamChangeBattleThink::MyDTI::newInstance() const {
    DDON_STUB("cFSMOrderParamChangeBattleThink::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cFSMOrderParamCheckLayout::getDTI() const {
    return cFSMOrderParamCheckLayout::DTI;
}

inline void cFSMOrderParamCheckLayout::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamCheckLayout::DTI)->memFree(p_addr);
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

__attribute__((weak)) MtObject* cFSMOrderParamCheckLayout::MyDTI::newInstance() const {
    DDON_STUB("cFSMOrderParamCheckLayout::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cFSMOrderParamCtrlSubSdl::getDTI() const {
    return cFSMOrderParamCtrlSubSdl::DTI;
}

inline void cFSMOrderParamCtrlSubSdl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamCtrlSubSdl::DTI)->memFree(p_addr);
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

__attribute__((weak)) MtObject* cFSMOrderParamCtrlSubSdl::MyDTI::newInstance() const {
    DDON_STUB("cFSMOrderParamCtrlSubSdl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cFSMOrderParamFlagCommon::getDTI() const {
    return cFSMOrderParamFlagCommon::DTI;
}

inline void cFSMOrderParamFlagCommon::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamFlagCommon::DTI)->memFree(p_addr);
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

inline cFSMOrderParamFlagCommon::cFSMOrderParamFlagCommon() {
    mFlagNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamFlagCommon::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamFlagCommon::DTI)->memAlloc(sizeof(cFSMOrderParamFlagCommon), 16u, cFSMOrderParamFlagCommon::DTI.getID())) cFSMOrderParamFlagCommon;
}

const MtDTI& cFSMOrderParamFlagQuest::getDTI() const {
    return cFSMOrderParamFlagQuest::DTI;
}

inline void cFSMOrderParamFlagQuest::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamFlagQuest::DTI)->memFree(p_addr);
}

void cFSMOrderParamFlagQuest::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mQuestNo", &mQuestNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlagNo", &mFlagNo, 0u, 0u);
}

inline cFSMOrderParamFlagQuest::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamFlagQuest::MyDTI cFSMOrderParamFlagQuest::DTI("cFSMOrderParamFlagQuest", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

inline cFSMOrderParamFlagQuest::cFSMOrderParamFlagQuest() {
    mQuestNo = 0;
    mFlagNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamFlagQuest::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamFlagQuest::DTI)->memAlloc(sizeof(cFSMOrderParamFlagQuest), 16u, cFSMOrderParamFlagQuest::DTI.getID())) cFSMOrderParamFlagQuest;
}

const MtDTI& cFSMOrderParamIsMyQuestFlag::getDTI() const {
    return cFSMOrderParamIsMyQuestFlag::DTI;
}

inline void cFSMOrderParamIsMyQuestFlag::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamIsMyQuestFlag::DTI)->memFree(p_addr);
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

inline cFSMOrderParamIsMyQuestFlag::cFSMOrderParamIsMyQuestFlag() {
    mArrayIdx = 0;
    mQuestId = 0;
    mFlagNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamIsMyQuestFlag::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamIsMyQuestFlag::DTI)->memAlloc(sizeof(cFSMOrderParamIsMyQuestFlag), 16u, cFSMOrderParamIsMyQuestFlag::DTI.getID())) cFSMOrderParamIsMyQuestFlag;
}

const MtDTI& cFSMOrderParamJumpArea::getDTI() const {
    return cFSMOrderParamJumpArea::DTI;
}

inline void cFSMOrderParamJumpArea::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamJumpArea::DTI)->memFree(p_addr);
}

void cFSMOrderParamJumpArea::createProperty(MtPropertyList& s) {
    this->cAIResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mJumpStageNo", &mJumpStageNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJumpStagePosNo", &mJumpStagePosNo, 0u, 0u);
}

inline cFSMOrderParamJumpArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamJumpArea::MyDTI cFSMOrderParamJumpArea::DTI("cFSMOrderParamJumpArea", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMOrderParamJumpArea::MyDTI::newInstance() const {
    DDON_STUB("cFSMOrderParamJumpArea::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cFSMOrderParamJumpPos::getDTI() const {
    return cFSMOrderParamJumpPos::DTI;
}

inline void cFSMOrderParamJumpPos::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamJumpPos::DTI)->memFree(p_addr);
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

inline cFSMOrderParamJumpPos::cFSMOrderParamJumpPos() {
    mJumpType = 1;
    mJumpStagePosNo = 0;
    mPos = MtVector3::Zero;
    mFadeOutTime = 15.0f;
    mFadeInTime = 15.0f;
}

__attribute__((weak)) MtObject* cFSMOrderParamJumpPos::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamJumpPos::DTI)->memAlloc(sizeof(cFSMOrderParamJumpPos), 16u, cFSMOrderParamJumpPos::DTI.getID())) cFSMOrderParamJumpPos;
}

const MtDTI& cFSMOrderParamQuestInfo::getDTI() const {
    return cFSMOrderParamQuestInfo::DTI;
}

inline void cFSMOrderParamQuestInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamQuestInfo::DTI)->memFree(p_addr);
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

inline cFSMOrderParamQuestInfo::cFSMOrderParamQuestInfo() {
    mQuestType = 0;
    mQuestId = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamQuestInfo::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamQuestInfo::DTI)->memAlloc(sizeof(cFSMOrderParamQuestInfo), 16u, cFSMOrderParamQuestInfo::DTI.getID())) cFSMOrderParamQuestInfo;
}

const MtDTI& cFSMOrderParamSetCallSe::getDTI() const {
    return cFSMOrderParamSetCallSe::DTI;
}

inline void cFSMOrderParamSetCallSe::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetCallSe::DTI)->memFree(p_addr);
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

inline cFSMOrderParamSetCallSe::cFSMOrderParamSetCallSe() {
    mSeId = 0;
    mTarget = 0;
    mGroup = -1;
    mId = -1;
    mJointNo = -1;
    mDelayFrame = 0;
    mPos = MtVector3::Zero;
}

__attribute__((weak)) MtObject* cFSMOrderParamSetCallSe::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetCallSe::DTI)->memAlloc(sizeof(cFSMOrderParamSetCallSe), 16u, cFSMOrderParamSetCallSe::DTI.getID())) cFSMOrderParamSetCallSe;
}

const MtDTI& cFSMOrderParamSetDispUnit::getDTI() const {
    return cFSMOrderParamSetDispUnit::DTI;
}

inline MtAllocator* cFSMOrderParamSetDispUnit::getAllocator() {
    return MtMemoryAllocator::getAllocator(cFSMOrderParamSetDispUnit::DTI);
}

void* cFSMOrderParamSetDispUnit::operator new(size_t sz, u32 align) {
    return cFSMOrderParamSetDispUnit::getAllocator()->memAlloc(sz, align, cFSMOrderParamSetDispUnit::DTI.getID());
}

inline void cFSMOrderParamSetDispUnit::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetDispUnit::DTI)->memFree(p_addr);
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

__attribute__((weak)) MtObject* cFSMOrderParamSetDispUnit::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetDispUnit::DTI)->memAlloc(sizeof(cFSMOrderParamSetDispUnit), 16u, cFSMOrderParamSetDispUnit::DTI.getID())) cFSMOrderParamSetDispUnit;
}

const MtDTI& cFSMOrderParamSetEffect::getDTI() const {
    return cFSMOrderParamSetEffect::DTI;
}

inline void cFSMOrderParamSetEffect::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetEffect::DTI)->memFree(p_addr);
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

inline cFSMOrderParamSetEffect::cFSMOrderParamSetEffect() {
    mEfcId = 0;
    mTarget = 0;
    mGroup = -1;
    mId = -1;
    mHaveItem = false;
    mOmId = 0;
    mAct = 0;
    mType = 0;
    mIndex = 0;
    mElement = 0;
    mPos = MtVector3::Zero;
    mAng = MtVector3::Zero;
    mScl = MtVector3::One;
}

__attribute__((weak)) MtObject* cFSMOrderParamSetEffect::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetEffect::DTI)->memAlloc(sizeof(cFSMOrderParamSetEffect), 16u, cFSMOrderParamSetEffect::DTI.getID())) cFSMOrderParamSetEffect;
}

const MtDTI& cFSMOrderParamSetEnemy::getDTI() const {
    return cFSMOrderParamSetEnemy::DTI;
}

inline void cFSMOrderParamSetEnemy::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetEnemy::DTI)->memFree(p_addr);
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

inline cFSMOrderParamSetEnemy::cFSMOrderParamSetEnemy() {
    mGroupId = 257;
    mLayoutId = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamSetEnemy::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetEnemy::DTI)->memAlloc(sizeof(cFSMOrderParamSetEnemy), 16u, cFSMOrderParamSetEnemy::DTI.getID())) cFSMOrderParamSetEnemy;
}

const MtDTI& cFSMOrderParamSetEnemy::cSetEmInfo::getDTI() const {
    return cFSMOrderParamSetEnemy::cSetEmInfo::DTI;
}

inline void cFSMOrderParamSetEnemy::cSetEmInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetEnemy::cSetEmInfo::DTI)->memFree(p_addr);
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

inline void cFSMOrderParamSetFade::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetFade::DTI)->memFree(p_addr);
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

inline cFSMOrderParamSetFade::cFSMOrderParamSetFade() {
    mFadeType = 0;
    mFadeTime = 1.0f;
}

__attribute__((weak)) MtObject* cFSMOrderParamSetFade::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetFade::DTI)->memAlloc(sizeof(cFSMOrderParamSetFade), 16u, cFSMOrderParamSetFade::DTI.getID())) cFSMOrderParamSetFade;
}

const MtDTI& cFSMOrderParamSetLayout::getDTI() const {
    return cFSMOrderParamSetLayout::DTI;
}

inline void cFSMOrderParamSetLayout::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetLayout::DTI)->memFree(p_addr);
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

inline cFSMOrderParamSetLayout::cFSMOrderParamSetLayout() {
    mActType = 0;
    mStageNo = 0;
    mFlagNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamSetLayout::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetLayout::DTI)->memAlloc(sizeof(cFSMOrderParamSetLayout), 16u, cFSMOrderParamSetLayout::DTI.getID())) cFSMOrderParamSetLayout;
}

const MtDTI& cFSMOrderParamSetLocationName::getDTI() const {
    return cFSMOrderParamSetLocationName::DTI;
}

inline void cFSMOrderParamSetLocationName::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetLocationName::DTI)->memFree(p_addr);
}

void cFSMOrderParamSetLocationName::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
}

inline cFSMOrderParamSetLocationName::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetLocationName::MyDTI cFSMOrderParamSetLocationName::DTI("cFSMOrderParamSetLocationName", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

inline cFSMOrderParamSetLocationName::cFSMOrderParamSetLocationName() {
    mStageNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamSetLocationName::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetLocationName::DTI)->memAlloc(sizeof(cFSMOrderParamSetLocationName), 16u, cFSMOrderParamSetLocationName::DTI.getID())) cFSMOrderParamSetLocationName;
}

const MtDTI& cFSMOrderParamSetOpenDoor::getDTI() const {
    return cFSMOrderParamSetOpenDoor::DTI;
}

inline void cFSMOrderParamSetOpenDoor::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetOpenDoor::DTI)->memFree(p_addr);
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

inline cFSMOrderParamSetOpenDoor::cFSMOrderParamSetOpenDoor() {
    mIsQuestSet = false;
    mQuestId = 0;
    mGroupNo = 0;
    mSetNo = 0;
}

__attribute__((weak)) MtObject* cFSMOrderParamSetOpenDoor::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetOpenDoor::DTI)->memAlloc(sizeof(cFSMOrderParamSetOpenDoor), 16u, cFSMOrderParamSetOpenDoor::DTI.getID())) cFSMOrderParamSetOpenDoor;
}

const MtDTI& cFSMOrderParamSetVib::getDTI() const {
    return cFSMOrderParamSetVib::DTI;
}

inline void cFSMOrderParamSetVib::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamSetVib::DTI)->memFree(p_addr);
}

void cFSMOrderParamSetVib::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mVib", &mVib, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNum", &mNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaitSec", &mWaitSec, 0u, 0u);
}

inline cFSMOrderParamSetVib::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamSetVib::MyDTI cFSMOrderParamSetVib::DTI("cFSMOrderParamSetVib", &::cFSMOrderParam::DTI, 24ul, 0u, 0u);

inline cFSMOrderParamSetVib::cFSMOrderParamSetVib() {
    mVib = 0;
    mNum = 1;
    mWaitSec = 0.0f;
}

__attribute__((weak)) MtObject* cFSMOrderParamSetVib::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cFSMOrderParamSetVib::DTI)->memAlloc(sizeof(cFSMOrderParamSetVib), 16u, cFSMOrderParamSetVib::DTI.getID())) cFSMOrderParamSetVib;
}

const MtDTI& cFSMOrderParamStartQuake::getDTI() const {
    return cFSMOrderParamStartQuake::DTI;
}

inline void cFSMOrderParamStartQuake::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamStartQuake::DTI)->memFree(p_addr);
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

__attribute__((weak)) MtObject* cFSMOrderParamStartQuake::MyDTI::newInstance() const {
    DDON_STUB("cFSMOrderParamStartQuake::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cFSMOrderParamStopQuake::getDTI() const {
    return cFSMOrderParamStopQuake::DTI;
}

inline void cFSMOrderParamStopQuake::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cFSMOrderParamStopQuake::DTI)->memFree(p_addr);
}

cFSMOrderParamStopQuake::~cFSMOrderParamStopQuake() {
}

void cFSMOrderParamStopQuake::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsForceStop", &mIsForceStop, 0u, 0u);
}

inline cFSMOrderParamStopQuake::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cFSMOrderParamStopQuake::MyDTI cFSMOrderParamStopQuake::DTI("cFSMOrderParamStopQuake", &::cFSMOrderParam::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cFSMOrderParamStopQuake::MyDTI::newInstance() const {
    DDON_STUB("cFSMOrderParamStopQuake::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cFSMOrderParamCallEvent::cNpcId>::~MtTypedArray();

template MtTypedArray<cFSMOrderParamSetEnemy::cSetEmInfo>::~MtTypedArray();

