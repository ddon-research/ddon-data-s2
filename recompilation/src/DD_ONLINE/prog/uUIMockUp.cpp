// Reconstructed from the game's DWARF debug information.
#include <new>
#include <stdio.h>
#include "uUIMockUp.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "cCharacterData.h"
#include "cContextInterface.h"
#include "cEditParam.h"
#include "cEquipData.h"
#include "cItemParam.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpCharacterEdit.h"
#include "nCharacterData.h"
#include "../../XFramework/nPrim.h"
#include "rCharacterEdit.h"
#include "rItemList.h"
#include "../../XFramework/rMotionList.h"
#include "../../XFramework/rRenderTargetTexture.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sInputManager.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sPlayerManager.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sUnitManager.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uLight.h"
#include "uMockUpModel.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#include "../../XFramework/uScreenSpace.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uUIMockUp::getDTI() const {
    return uUIMockUp::DTI;
}

void* uUIMockUp::operator new(size_t sz, u32 align) {
    return uUIMockUp::getAllocator()->memAlloc(sz, align, uUIMockUp::DTI.getID());
}

__attribute__((noinline)) uUIMockUp::~uUIMockUp() {
    delList();
    if (mpEdit == nullptr) {
        return;
    }
    mpEdit->release();
    mpEdit = nullptr;
}

void uUIMockUp::createProperty(MtPropertyList& s) {
    this->uScreenSpace::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPosDisp", &mPosDisp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWHDisp", &mWHDisp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamDist", &mCamDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCamYOfs", &mCamYOfs, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsHideEnable", &mIsHideEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNo", &mJointNo, 0u, 0u);
}

__attribute__((weak)) void uUIMockUp::move() {
    DDON_STUB("uUIMockUp::move")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::kill() {
    mCS.lock();
    delList();
    if (mIsCreatedModel && mRefCount != 0 && --mRefCount == 0) {
        if (mpLight != nullptr) {
            reinterpret_cast<cUnit*>(mpLight)->kill();
            mpLight = nullptr;
        }
        if (mpModel != nullptr) {
            mpModel->kill();
            mpModel = nullptr;
        }
    }
    mCS.unlock();
    
    u32& t1 = reinterpret_cast<u32*>(this)[0x10 / sizeof(u32)];
    if ((t1 & (UATTR_FIX << 10)) == 0 && ((t1 & 7u) - BEFLAG_PRE_MOVE) <= 1u) {
        t1 = (t1 & ~7u) | BEFLAG_PRE_DELETE;
    }
}

__attribute__((weak)) void uUIMockUp::updatePtr() {
    DDON_STUB("uUIMockUp::updatePtr")
    /* stub */
}

void uUIMockUp::setup() {
    setupActive();
}

__attribute__((weak)) void uUIMockUp::setupMyPlayerModel() {
    DDON_STUB("uUIMockUp::setupMyPlayerModel")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setupPawnModel() {
    DDON_STUB("uUIMockUp::setupPawnModel")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setupFromSaveData(cCharacterData* pEdit, rMotionList* pmot) {
    DDON_STUB("uUIMockUp::setupFromSaveData")
    /* stub */
}

void uUIMockUp::setupPawnModelContext(const cContextInstHm* pPawnContext) {
    setupModelContext(pPawnContext, 1u);
}

void uUIMockUp::setupPlayerModelContext(const cContextInstHm* pContextHm) {
    setupModelContext(pContextHm, 2u);
}

void uUIMockUp::setRenderTargetTexture(rRenderTargetTexture* pRTT) {
    if (mpRenderTarget != nullptr) {
        mpRenderTarget->release();
        mpRenderTarget = nullptr;
        if (pRTT != nullptr) {
            releaseTexture();
            mpRenderTarget = pRTT;
            pRTT->addRef();
            createDepth(mpRenderTarget);
        } else {
            mpRenderTarget = nullptr;
            createTexture(mTextureSize);
        }
    } else {
        if (pRTT != nullptr) {
            releaseTexture();
            mpRenderTarget = pRTT;
            pRTT->addRef();
            createDepth(mpRenderTarget);
        } else {
            mpRenderTarget = nullptr;
        }
    }
}

void uUIMockUp::changeEquip(const cItemParam* pItemParam) {
    if (pItemParam == nullptr) {
        return;
    }
    changeEquip(pItemParam->getItemNo(), pItemParam->mColorNo, pItemParam);
}

__attribute__((weak)) void uUIMockUp::changeEquip(u32 itemId, s32 color, const cItemParam* pItemParam) {
    DDON_STUB("uUIMockUp::changeEquip")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::resetEquip() {
    DDON_STUB("uUIMockUp::resetEquip")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::resetEquip(const cEquipData& equip_data, bool isSetBaseEquip) {
    DDON_STUB("uUIMockUp::resetEquip")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::resetEquipSub(uMockUpModel::stItemData(&item_id_table)[15]) {
    DDON_STUB("uUIMockUp::resetEquipSub")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setupEquipFromEquipData(const cEquipData& equipData, uMockUpModel::stItemData(&item_id_table)[15]) {
    DDON_STUB("uUIMockUp::setupEquipFromEquipData")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setupEquipFromEquipStruct(const nCharacterData::stEquipData& stEquip, uMockUpModel::stItemData(&item_id_table)[15]) {
    DDON_STUB("uUIMockUp::setupEquipFromEquipStruct")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::removeEquip(u8 category) {
    DDON_STUB("uUIMockUp::removeEquip")
    /* stub */
}

__attribute__((weak)) bool uUIMockUp::isComplete() {
    DDON_STUB("uUIMockUp::isComplete")
    return {};
}

__attribute__((weak)) void uUIMockUp::setDisp(bool isDisp) {
    DDON_STUB("uUIMockUp::setDisp")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setMannequinEquip(u32 itemId, s32 color, cItemParam* pParam) {
    // workaround
    mCS.lock();
    setupActive();
    if (mpModel && mIsActive) {
        mpModel->setMannequinEquip(itemId, color, pParam);
        mModelInfo.setMannequineItem(itemId, color, pParam);
    }
    mLocalInfo.setMannequineItem(itemId, color, pParam);
    mCS.unlock();
}

void uUIMockUp::setMannequinEquip(const cContextInstHm* pContext, u32 itemId, s32 color, cItemParam* pParam) {
    if (pContext == nullptr) {
        u32 t0 = cContextInterface::getSex(sContextManager::getInstance()->getContextMyPlayer());
        const rItemList::rItemParam* pParamRes = sItemManager::getInstance()->getItemParam(itemId);
        if (pParamRes != nullptr) {
            if (pParamRes->getSex() != 1) {
                setupMannequineModel(pParamRes->getSex() == 2);
            } else {
                setupMannequineModel(t0 == 0);
            }
        } else {
            setupMannequineModel(t0 == 0);
        }
        setMannequinEquip(itemId, color, pParam);
    } else {
        u32 t0 = cContextInterface::getSex(pContext);
        const rItemList::rItemParam* pParamRes = sItemManager::getInstance()->getItemParam(itemId);
        if (pParamRes != nullptr) {
            if (pParamRes->getSex() != 1) {
                setupMannequineModel(pParamRes->getSex() == 2);
            } else {
                setupMannequineModel(t0 == 0);
            }
        } else {
            setupMannequineModel(t0 == 0);
        }
        setMannequinEquip(itemId, color, pParam);
    }
}

__attribute__((weak)) void uUIMockUp::setupMannequineModel(bool isMale) {
    DDON_STUB("uUIMockUp::setupMannequineModel")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::endMannequinMode() {
    DDON_STUB("uUIMockUp::endMannequinMode")
    /* stub */
}

bool uUIMockUp::isEquipEnable(const cContextInstHm* pContext, u32 itemId) {
    if (pContext == nullptr) {
        cContextInstHm* t0 = sContextManager::getInstance()->getContextMyPlayer();
        const rItemList::rItemParam* pParam = sItemManager::getInstance()->getItemParam(itemId);
        if (pParam != nullptr) {
            if (pParam->getUseJob(cContextInterface::getJob(t0))) {
                if (pParam->getSex() != 1) {
                    u8 t1 = pParam->getSex();
                    if ((static_cast<unsigned long>(t1 == 2) ^ static_cast<unsigned long>(cContextInterface::getSex(t0) == 0)) != 0) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    return true;
                }
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        const rItemList::rItemParam* pParam = sItemManager::getInstance()->getItemParam(itemId);
        if (pParam != nullptr) {
            if (pParam->getUseJob(cContextInterface::getJob(pContext))) {
                if (pParam->getSex() != 1) {
                    u8 t1 = pParam->getSex();
                    if ((static_cast<unsigned long>(t1 == 2) ^ static_cast<unsigned long>(cContextInterface::getSex(pContext) == 0)) != 0) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    return true;
                }
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
}

__attribute__((weak)) void uUIMockUp::resetModel() {
    DDON_STUB("uUIMockUp::resetModel")
    /* stub */
}

void uUIMockUp::setMotion(u32 MotNo, f32 Frame, f32 hokan) {
    if ((uUIMockUp::mpModel) == nullptr) {
        return;
    }
    if (!mIsActive) {
        return;
    }
    (uUIMockUp::mpModel)->uMockUpModel::setStopPauseAction(MotNo, Frame, hokan);
}

f32 uUIMockUp::getMotionMaxFrame(u32 MotNo) {
    if ((uUIMockUp::mpModel) != nullptr) {
        return (uUIMockUp::mpModel)->uMockUpModel::getMotionMaxFrame(MotNo);
    } else {
        return 1.0f;
    }
}

__attribute__((weak)) void uUIMockUp::createModel(bool isForceCreate) {
    DDON_STUB("uUIMockUp::createModel")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setupModelContext(const cContextInstHm* pContextHm, u32 Mode) {
    DDON_STUB("uUIMockUp::setupModelContext")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setupCostume(u32 item_id) {
    rItemList::rItemParam* pParam = sItemManager::getInstance()->getItemParam(item_id);
    if (pParam == nullptr) {
        return;
    }
    const u8 slot = static_cast<u8>(cEquipData::convEquipCateToSlotType(static_cast<nCharacterData::EQUIP_CATEGORY>(pParam->getEquipCategory())));
    switch (slot) {
    case nCharacterData::EQUIP_SLOT_ARMOR_BODY:
        if (pParam->isCostume()) {
            removeEquip(nCharacterData::EQUIP_SLOT_ARMOR_HELM);
            removeEquip(nCharacterData::EQUIP_SLOT_WEAR_BODY);
            removeEquip(nCharacterData::EQUIP_SLOT_ARMOR_ARM);
            removeEquip(nCharacterData::EQUIP_SLOT_ARMOR_LEG);
            removeEquip(nCharacterData::EQUIP_SLOT_WEAR_LEG);
            removeEquip(nCharacterData::EQUIP_SLOT_ACCESSORY);
        }
        break;
    case nCharacterData::EQUIP_SLOT_ARMOR_HELM:
    case nCharacterData::EQUIP_SLOT_WEAR_BODY:
    case nCharacterData::EQUIP_SLOT_ARMOR_ARM:
    case nCharacterData::EQUIP_SLOT_ARMOR_LEG:
    case nCharacterData::EQUIP_SLOT_WEAR_LEG:
    case nCharacterData::EQUIP_SLOT_ACCESSORY: {
        const u32 index = cEquipData::convEquipCateToIndex(nCharacterData::EQUIP_SLOT_ARMOR_BODY);
        item_id = mLocalInfo.mItemData[index].mId;
        pParam = sItemManager::getInstance()->getItemParam(item_id);
        if (pParam != nullptr &&
            static_cast<u8>(cEquipData::convEquipCateToSlotType(static_cast<nCharacterData::EQUIP_CATEGORY>(pParam->getEquipCategory()))) == nCharacterData::EQUIP_SLOT_ARMOR_BODY &&
            pParam->isCostume()) {
            removeEquip(nCharacterData::EQUIP_SLOT_ARMOR_BODY);
        }
        break;
    }
    default:
        break;
    }
}

__attribute__((weak)) void uUIMockUp::updateVertices() {
    DDON_STUB("uUIMockUp::updateVertices")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setActive(bool isActive) {
    DDON_STUB("uUIMockUp::setActive")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::setupActive() {
    DDON_STUB("uUIMockUp::setupActive")
    /* stub */
}

__attribute__((weak)) void uUIMockUp::delList() {
    DDON_STUB("uUIMockUp::delList")
    /* stub */
}

inline uUIMockUp::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uUIMockUp::MyDTI uUIMockUp::DTI("uUIMockUp", &::uScreenSpace::DTI, 7344ul, 0u, 0u);

uInfiniteLightExt* uUIMockUp::mpLight;

uMockUpModel* uUIMockUp::mpModel;

u32 uUIMockUp::mRefCount;

uUIMockUp* uUIMockUp::mMockUpList[5];

__attribute__((weak)) MtObject* uUIMockUp::MyDTI::newInstance() const {
    DDON_STUB("uUIMockUp::MyDTI::newInstance")
    return nullptr;
}

void uUIMockUp::DispInfo::setMannequineItem(u32 item_id, s32 color, const cItemParam* pItemParam) {
    mItemData[0].mId = 0;
    mItemData[0].mCraftElementItemNo[2] = 0;
    mItemData[0].mCraftElementItemNo[3] = 0;
    mItemData[0].mCraftElementItemNo[0] = 0;
    mItemData[0].mCraftElementItemNo[1] = 0;
    mItemData[0].mUID[56] = 0;
    mItemData[0].mUID[57] = 0;
    mItemData[0].mUID[58] = 0;
    mItemData[0].mUID[59] = 0;
    mItemData[0].mUID[60] = 0;
    mItemData[0].mUID[61] = 0;
    mItemData[0].mUID[62] = 0;
    mItemData[0].mUID[63] = 0;
    mItemData[0].mUID[48] = 0;
    mItemData[0].mUID[49] = 0;
    mItemData[0].mUID[50] = 0;
    mItemData[0].mUID[51] = 0;
    mItemData[0].mUID[52] = 0;
    mItemData[0].mUID[53] = 0;
    mItemData[0].mUID[54] = 0;
    mItemData[0].mUID[55] = 0;
    mItemData[0].mUID[40] = 0;
    mItemData[0].mUID[41] = 0;
    mItemData[0].mUID[42] = 0;
    mItemData[0].mUID[43] = 0;
    mItemData[0].mUID[44] = 0;
    mItemData[0].mUID[45] = 0;
    mItemData[0].mUID[46] = 0;
    mItemData[0].mUID[47] = 0;
    mItemData[0].mUID[32] = 0;
    mItemData[0].mUID[33] = 0;
    mItemData[0].mUID[34] = 0;
    mItemData[0].mUID[35] = 0;
    mItemData[0].mUID[36] = 0;
    mItemData[0].mUID[37] = 0;
    mItemData[0].mUID[38] = 0;
    mItemData[0].mUID[39] = 0;
    mItemData[0].mUID[24] = 0;
    mItemData[0].mUID[25] = 0;
    mItemData[0].mUID[26] = 0;
    mItemData[0].mUID[27] = 0;
    mItemData[0].mUID[28] = 0;
    mItemData[0].mUID[29] = 0;
    mItemData[0].mUID[30] = 0;
    mItemData[0].mUID[31] = 0;
    mItemData[0].mUID[16] = 0;
    mItemData[0].mUID[17] = 0;
    mItemData[0].mUID[18] = 0;
    mItemData[0].mUID[19] = 0;
    mItemData[0].mUID[20] = 0;
    mItemData[0].mUID[21] = 0;
    mItemData[0].mUID[22] = 0;
    mItemData[0].mUID[23] = 0;
    mItemData[0].mUID[8] = 0;
    mItemData[0].mUID[9] = 0;
    mItemData[0].mUID[10] = 0;
    mItemData[0].mUID[11] = 0;
    mItemData[0].mUID[12] = 0;
    mItemData[0].mUID[13] = 0;
    mItemData[0].mUID[14] = 0;
    mItemData[0].mUID[15] = 0;
    mItemData[0].mUID[0] = 0;
    mItemData[0].mUID[1] = 0;
    mItemData[0].mUID[2] = 0;
    mItemData[0].mUID[3] = 0;
    mItemData[0].mUID[4] = 0;
    mItemData[0].mUID[5] = 0;
    mItemData[0].mUID[6] = 0;
    mItemData[0].mUID[7] = 0;
    mItemData[0].mColor = -1;
    mItemData[0].mSex = 0xFF;
    mItemData[1].mId = 0;
    mItemData[1].mCraftElementItemNo[2] = 0;
    mItemData[1].mCraftElementItemNo[3] = 0;
    mItemData[1].mCraftElementItemNo[0] = 0;
    mItemData[1].mCraftElementItemNo[1] = 0;
    mItemData[1].mUID[56] = 0;
    mItemData[1].mUID[57] = 0;
    mItemData[1].mUID[58] = 0;
    mItemData[1].mUID[59] = 0;
    mItemData[1].mUID[60] = 0;
    mItemData[1].mUID[61] = 0;
    mItemData[1].mUID[62] = 0;
    mItemData[1].mUID[63] = 0;
    mItemData[1].mUID[48] = 0;
    mItemData[1].mUID[49] = 0;
    mItemData[1].mUID[50] = 0;
    mItemData[1].mUID[51] = 0;
    mItemData[1].mUID[52] = 0;
    mItemData[1].mUID[53] = 0;
    mItemData[1].mUID[54] = 0;
    mItemData[1].mUID[55] = 0;
    mItemData[1].mUID[40] = 0;
    mItemData[1].mUID[41] = 0;
    mItemData[1].mUID[42] = 0;
    mItemData[1].mUID[43] = 0;
    mItemData[1].mUID[44] = 0;
    mItemData[1].mUID[45] = 0;
    mItemData[1].mUID[46] = 0;
    mItemData[1].mUID[47] = 0;
    mItemData[1].mUID[32] = 0;
    mItemData[1].mUID[33] = 0;
    mItemData[1].mUID[34] = 0;
    mItemData[1].mUID[35] = 0;
    mItemData[1].mUID[36] = 0;
    mItemData[1].mUID[37] = 0;
    mItemData[1].mUID[38] = 0;
    mItemData[1].mUID[39] = 0;
    mItemData[1].mUID[24] = 0;
    mItemData[1].mUID[25] = 0;
    mItemData[1].mUID[26] = 0;
    mItemData[1].mUID[27] = 0;
    mItemData[1].mUID[28] = 0;
    mItemData[1].mUID[29] = 0;
    mItemData[1].mUID[30] = 0;
    mItemData[1].mUID[31] = 0;
    mItemData[1].mUID[16] = 0;
    mItemData[1].mUID[17] = 0;
    mItemData[1].mUID[18] = 0;
    mItemData[1].mUID[19] = 0;
    mItemData[1].mUID[20] = 0;
    mItemData[1].mUID[21] = 0;
    mItemData[1].mUID[22] = 0;
    mItemData[1].mUID[23] = 0;
    mItemData[1].mUID[8] = 0;
    mItemData[1].mUID[9] = 0;
    mItemData[1].mUID[10] = 0;
    mItemData[1].mUID[11] = 0;
    mItemData[1].mUID[12] = 0;
    mItemData[1].mUID[13] = 0;
    mItemData[1].mUID[14] = 0;
    mItemData[1].mUID[15] = 0;
    mItemData[1].mUID[0] = 0;
    mItemData[1].mUID[1] = 0;
    mItemData[1].mUID[2] = 0;
    mItemData[1].mUID[3] = 0;
    mItemData[1].mUID[4] = 0;
    mItemData[1].mUID[5] = 0;
    mItemData[1].mUID[6] = 0;
    mItemData[1].mUID[7] = 0;
    mItemData[1].mColor = -1;
    mItemData[1].mSex = 0xFF;
    mItemData[2].mId = 0;
    mItemData[2].mCraftElementItemNo[2] = 0;
    mItemData[2].mCraftElementItemNo[3] = 0;
    mItemData[2].mCraftElementItemNo[0] = 0;
    mItemData[2].mCraftElementItemNo[1] = 0;
    mItemData[2].mUID[56] = 0;
    mItemData[2].mUID[57] = 0;
    mItemData[2].mUID[58] = 0;
    mItemData[2].mUID[59] = 0;
    mItemData[2].mUID[60] = 0;
    mItemData[2].mUID[61] = 0;
    mItemData[2].mUID[62] = 0;
    mItemData[2].mUID[63] = 0;
    mItemData[2].mUID[48] = 0;
    mItemData[2].mUID[49] = 0;
    mItemData[2].mUID[50] = 0;
    mItemData[2].mUID[51] = 0;
    mItemData[2].mUID[52] = 0;
    mItemData[2].mUID[53] = 0;
    mItemData[2].mUID[54] = 0;
    mItemData[2].mUID[55] = 0;
    mItemData[2].mUID[40] = 0;
    mItemData[2].mUID[41] = 0;
    mItemData[2].mUID[42] = 0;
    mItemData[2].mUID[43] = 0;
    mItemData[2].mUID[44] = 0;
    mItemData[2].mUID[45] = 0;
    mItemData[2].mUID[46] = 0;
    mItemData[2].mUID[47] = 0;
    mItemData[2].mUID[32] = 0;
    mItemData[2].mUID[33] = 0;
    mItemData[2].mUID[34] = 0;
    mItemData[2].mUID[35] = 0;
    mItemData[2].mUID[36] = 0;
    mItemData[2].mUID[37] = 0;
    mItemData[2].mUID[38] = 0;
    mItemData[2].mUID[39] = 0;
    mItemData[2].mUID[24] = 0;
    mItemData[2].mUID[25] = 0;
    mItemData[2].mUID[26] = 0;
    mItemData[2].mUID[27] = 0;
    mItemData[2].mUID[28] = 0;
    mItemData[2].mUID[29] = 0;
    mItemData[2].mUID[30] = 0;
    mItemData[2].mUID[31] = 0;
    mItemData[2].mUID[16] = 0;
    mItemData[2].mUID[17] = 0;
    mItemData[2].mUID[18] = 0;
    mItemData[2].mUID[19] = 0;
    mItemData[2].mUID[20] = 0;
    mItemData[2].mUID[21] = 0;
    mItemData[2].mUID[22] = 0;
    mItemData[2].mUID[23] = 0;
    mItemData[2].mUID[8] = 0;
    mItemData[2].mUID[9] = 0;
    mItemData[2].mUID[10] = 0;
    mItemData[2].mUID[11] = 0;
    mItemData[2].mUID[12] = 0;
    mItemData[2].mUID[13] = 0;
    mItemData[2].mUID[14] = 0;
    mItemData[2].mUID[15] = 0;
    mItemData[2].mUID[0] = 0;
    mItemData[2].mUID[1] = 0;
    mItemData[2].mUID[2] = 0;
    mItemData[2].mUID[3] = 0;
    mItemData[2].mUID[4] = 0;
    mItemData[2].mUID[5] = 0;
    mItemData[2].mUID[6] = 0;
    mItemData[2].mUID[7] = 0;
    mItemData[2].mColor = -1;
    mItemData[2].mSex = 0xFF;
    mItemData[3].mId = 0;
    mItemData[3].mCraftElementItemNo[2] = 0;
    mItemData[3].mCraftElementItemNo[3] = 0;
    mItemData[3].mCraftElementItemNo[0] = 0;
    mItemData[3].mCraftElementItemNo[1] = 0;
    mItemData[3].mUID[56] = 0;
    mItemData[3].mUID[57] = 0;
    mItemData[3].mUID[58] = 0;
    mItemData[3].mUID[59] = 0;
    mItemData[3].mUID[60] = 0;
    mItemData[3].mUID[61] = 0;
    mItemData[3].mUID[62] = 0;
    mItemData[3].mUID[63] = 0;
    mItemData[3].mUID[48] = 0;
    mItemData[3].mUID[49] = 0;
    mItemData[3].mUID[50] = 0;
    mItemData[3].mUID[51] = 0;
    mItemData[3].mUID[52] = 0;
    mItemData[3].mUID[53] = 0;
    mItemData[3].mUID[54] = 0;
    mItemData[3].mUID[55] = 0;
    mItemData[3].mUID[40] = 0;
    mItemData[3].mUID[41] = 0;
    mItemData[3].mUID[42] = 0;
    mItemData[3].mUID[43] = 0;
    mItemData[3].mUID[44] = 0;
    mItemData[3].mUID[45] = 0;
    mItemData[3].mUID[46] = 0;
    mItemData[3].mUID[47] = 0;
    mItemData[3].mUID[32] = 0;
    mItemData[3].mUID[33] = 0;
    mItemData[3].mUID[34] = 0;
    mItemData[3].mUID[35] = 0;
    mItemData[3].mUID[36] = 0;
    mItemData[3].mUID[37] = 0;
    mItemData[3].mUID[38] = 0;
    mItemData[3].mUID[39] = 0;
    mItemData[3].mUID[24] = 0;
    mItemData[3].mUID[25] = 0;
    mItemData[3].mUID[26] = 0;
    mItemData[3].mUID[27] = 0;
    mItemData[3].mUID[28] = 0;
    mItemData[3].mUID[29] = 0;
    mItemData[3].mUID[30] = 0;
    mItemData[3].mUID[31] = 0;
    mItemData[3].mUID[16] = 0;
    mItemData[3].mUID[17] = 0;
    mItemData[3].mUID[18] = 0;
    mItemData[3].mUID[19] = 0;
    mItemData[3].mUID[20] = 0;
    mItemData[3].mUID[21] = 0;
    mItemData[3].mUID[22] = 0;
    mItemData[3].mUID[23] = 0;
    mItemData[3].mUID[8] = 0;
    mItemData[3].mUID[9] = 0;
    mItemData[3].mUID[10] = 0;
    mItemData[3].mUID[11] = 0;
    mItemData[3].mUID[12] = 0;
    mItemData[3].mUID[13] = 0;
    mItemData[3].mUID[14] = 0;
    mItemData[3].mUID[15] = 0;
    mItemData[3].mUID[0] = 0;
    mItemData[3].mUID[1] = 0;
    mItemData[3].mUID[2] = 0;
    mItemData[3].mUID[3] = 0;
    mItemData[3].mUID[4] = 0;
    mItemData[3].mUID[5] = 0;
    mItemData[3].mUID[6] = 0;
    mItemData[3].mUID[7] = 0;
    mItemData[3].mColor = -1;
    mItemData[3].mSex = 0xFF;
    mItemData[4].mId = 0;
    mItemData[4].mCraftElementItemNo[2] = 0;
    mItemData[4].mCraftElementItemNo[3] = 0;
    mItemData[4].mCraftElementItemNo[0] = 0;
    mItemData[4].mCraftElementItemNo[1] = 0;
    mItemData[4].mUID[56] = 0;
    mItemData[4].mUID[57] = 0;
    mItemData[4].mUID[58] = 0;
    mItemData[4].mUID[59] = 0;
    mItemData[4].mUID[60] = 0;
    mItemData[4].mUID[61] = 0;
    mItemData[4].mUID[62] = 0;
    mItemData[4].mUID[63] = 0;
    mItemData[4].mUID[48] = 0;
    mItemData[4].mUID[49] = 0;
    mItemData[4].mUID[50] = 0;
    mItemData[4].mUID[51] = 0;
    mItemData[4].mUID[52] = 0;
    mItemData[4].mUID[53] = 0;
    mItemData[4].mUID[54] = 0;
    mItemData[4].mUID[55] = 0;
    mItemData[4].mUID[40] = 0;
    mItemData[4].mUID[41] = 0;
    mItemData[4].mUID[42] = 0;
    mItemData[4].mUID[43] = 0;
    mItemData[4].mUID[44] = 0;
    mItemData[4].mUID[45] = 0;
    mItemData[4].mUID[46] = 0;
    mItemData[4].mUID[47] = 0;
    mItemData[4].mUID[32] = 0;
    mItemData[4].mUID[33] = 0;
    mItemData[4].mUID[34] = 0;
    mItemData[4].mUID[35] = 0;
    mItemData[4].mUID[36] = 0;
    mItemData[4].mUID[37] = 0;
    mItemData[4].mUID[38] = 0;
    mItemData[4].mUID[39] = 0;
    mItemData[4].mUID[24] = 0;
    mItemData[4].mUID[25] = 0;
    mItemData[4].mUID[26] = 0;
    mItemData[4].mUID[27] = 0;
    mItemData[4].mUID[28] = 0;
    mItemData[4].mUID[29] = 0;
    mItemData[4].mUID[30] = 0;
    mItemData[4].mUID[31] = 0;
    mItemData[4].mUID[16] = 0;
    mItemData[4].mUID[17] = 0;
    mItemData[4].mUID[18] = 0;
    mItemData[4].mUID[19] = 0;
    mItemData[4].mUID[20] = 0;
    mItemData[4].mUID[21] = 0;
    mItemData[4].mUID[22] = 0;
    mItemData[4].mUID[23] = 0;
    mItemData[4].mUID[8] = 0;
    mItemData[4].mUID[9] = 0;
    mItemData[4].mUID[10] = 0;
    mItemData[4].mUID[11] = 0;
    mItemData[4].mUID[12] = 0;
    mItemData[4].mUID[13] = 0;
    mItemData[4].mUID[14] = 0;
    mItemData[4].mUID[15] = 0;
    mItemData[4].mUID[0] = 0;
    mItemData[4].mUID[1] = 0;
    mItemData[4].mUID[2] = 0;
    mItemData[4].mUID[3] = 0;
    mItemData[4].mUID[4] = 0;
    mItemData[4].mUID[5] = 0;
    mItemData[4].mUID[6] = 0;
    mItemData[4].mUID[7] = 0;
    mItemData[4].mColor = -1;
    mItemData[4].mSex = 0xFF;
    mItemData[5].mId = 0;
    mItemData[5].mCraftElementItemNo[2] = 0;
    mItemData[5].mCraftElementItemNo[3] = 0;
    mItemData[5].mCraftElementItemNo[0] = 0;
    mItemData[5].mCraftElementItemNo[1] = 0;
    mItemData[5].mUID[56] = 0;
    mItemData[5].mUID[57] = 0;
    mItemData[5].mUID[58] = 0;
    mItemData[5].mUID[59] = 0;
    mItemData[5].mUID[60] = 0;
    mItemData[5].mUID[61] = 0;
    mItemData[5].mUID[62] = 0;
    mItemData[5].mUID[63] = 0;
    mItemData[5].mUID[48] = 0;
    mItemData[5].mUID[49] = 0;
    mItemData[5].mUID[50] = 0;
    mItemData[5].mUID[51] = 0;
    mItemData[5].mUID[52] = 0;
    mItemData[5].mUID[53] = 0;
    mItemData[5].mUID[54] = 0;
    mItemData[5].mUID[55] = 0;
    mItemData[5].mUID[40] = 0;
    mItemData[5].mUID[41] = 0;
    mItemData[5].mUID[42] = 0;
    mItemData[5].mUID[43] = 0;
    mItemData[5].mUID[44] = 0;
    mItemData[5].mUID[45] = 0;
    mItemData[5].mUID[46] = 0;
    mItemData[5].mUID[47] = 0;
    mItemData[5].mUID[32] = 0;
    mItemData[5].mUID[33] = 0;
    mItemData[5].mUID[34] = 0;
    mItemData[5].mUID[35] = 0;
    mItemData[5].mUID[36] = 0;
    mItemData[5].mUID[37] = 0;
    mItemData[5].mUID[38] = 0;
    mItemData[5].mUID[39] = 0;
    mItemData[5].mUID[24] = 0;
    mItemData[5].mUID[25] = 0;
    mItemData[5].mUID[26] = 0;
    mItemData[5].mUID[27] = 0;
    mItemData[5].mUID[28] = 0;
    mItemData[5].mUID[29] = 0;
    mItemData[5].mUID[30] = 0;
    mItemData[5].mUID[31] = 0;
    mItemData[5].mUID[16] = 0;
    mItemData[5].mUID[17] = 0;
    mItemData[5].mUID[18] = 0;
    mItemData[5].mUID[19] = 0;
    mItemData[5].mUID[20] = 0;
    mItemData[5].mUID[21] = 0;
    mItemData[5].mUID[22] = 0;
    mItemData[5].mUID[23] = 0;
    mItemData[5].mUID[8] = 0;
    mItemData[5].mUID[9] = 0;
    mItemData[5].mUID[10] = 0;
    mItemData[5].mUID[11] = 0;
    mItemData[5].mUID[12] = 0;
    mItemData[5].mUID[13] = 0;
    mItemData[5].mUID[14] = 0;
    mItemData[5].mUID[15] = 0;
    mItemData[5].mUID[0] = 0;
    mItemData[5].mUID[1] = 0;
    mItemData[5].mUID[2] = 0;
    mItemData[5].mUID[3] = 0;
    mItemData[5].mUID[4] = 0;
    mItemData[5].mUID[5] = 0;
    mItemData[5].mUID[6] = 0;
    mItemData[5].mUID[7] = 0;
    mItemData[5].mColor = -1;
    mItemData[5].mSex = 0xFF;
    mItemData[6].mId = 0;
    mItemData[6].mCraftElementItemNo[2] = 0;
    mItemData[6].mCraftElementItemNo[3] = 0;
    mItemData[6].mCraftElementItemNo[0] = 0;
    mItemData[6].mCraftElementItemNo[1] = 0;
    mItemData[6].mUID[56] = 0;
    mItemData[6].mUID[57] = 0;
    mItemData[6].mUID[58] = 0;
    mItemData[6].mUID[59] = 0;
    mItemData[6].mUID[60] = 0;
    mItemData[6].mUID[61] = 0;
    mItemData[6].mUID[62] = 0;
    mItemData[6].mUID[63] = 0;
    mItemData[6].mUID[48] = 0;
    mItemData[6].mUID[49] = 0;
    mItemData[6].mUID[50] = 0;
    mItemData[6].mUID[51] = 0;
    mItemData[6].mUID[52] = 0;
    mItemData[6].mUID[53] = 0;
    mItemData[6].mUID[54] = 0;
    mItemData[6].mUID[55] = 0;
    mItemData[6].mUID[40] = 0;
    mItemData[6].mUID[41] = 0;
    mItemData[6].mUID[42] = 0;
    mItemData[6].mUID[43] = 0;
    mItemData[6].mUID[44] = 0;
    mItemData[6].mUID[45] = 0;
    mItemData[6].mUID[46] = 0;
    mItemData[6].mUID[47] = 0;
    mItemData[6].mUID[32] = 0;
    mItemData[6].mUID[33] = 0;
    mItemData[6].mUID[34] = 0;
    mItemData[6].mUID[35] = 0;
    mItemData[6].mUID[36] = 0;
    mItemData[6].mUID[37] = 0;
    mItemData[6].mUID[38] = 0;
    mItemData[6].mUID[39] = 0;
    mItemData[6].mUID[24] = 0;
    mItemData[6].mUID[25] = 0;
    mItemData[6].mUID[26] = 0;
    mItemData[6].mUID[27] = 0;
    mItemData[6].mUID[28] = 0;
    mItemData[6].mUID[29] = 0;
    mItemData[6].mUID[30] = 0;
    mItemData[6].mUID[31] = 0;
    mItemData[6].mUID[16] = 0;
    mItemData[6].mUID[17] = 0;
    mItemData[6].mUID[18] = 0;
    mItemData[6].mUID[19] = 0;
    mItemData[6].mUID[20] = 0;
    mItemData[6].mUID[21] = 0;
    mItemData[6].mUID[22] = 0;
    mItemData[6].mUID[23] = 0;
    mItemData[6].mUID[8] = 0;
    mItemData[6].mUID[9] = 0;
    mItemData[6].mUID[10] = 0;
    mItemData[6].mUID[11] = 0;
    mItemData[6].mUID[12] = 0;
    mItemData[6].mUID[13] = 0;
    mItemData[6].mUID[14] = 0;
    mItemData[6].mUID[15] = 0;
    mItemData[6].mUID[0] = 0;
    mItemData[6].mUID[1] = 0;
    mItemData[6].mUID[2] = 0;
    mItemData[6].mUID[3] = 0;
    mItemData[6].mUID[4] = 0;
    mItemData[6].mUID[5] = 0;
    mItemData[6].mUID[6] = 0;
    mItemData[6].mUID[7] = 0;
    mItemData[6].mColor = -1;
    mItemData[6].mSex = 0xFF;
    mItemData[7].mId = 0;
    mItemData[7].mCraftElementItemNo[2] = 0;
    mItemData[7].mCraftElementItemNo[3] = 0;
    mItemData[7].mCraftElementItemNo[0] = 0;
    mItemData[7].mCraftElementItemNo[1] = 0;
    mItemData[7].mUID[56] = 0;
    mItemData[7].mUID[57] = 0;
    mItemData[7].mUID[58] = 0;
    mItemData[7].mUID[59] = 0;
    mItemData[7].mUID[60] = 0;
    mItemData[7].mUID[61] = 0;
    mItemData[7].mUID[62] = 0;
    mItemData[7].mUID[63] = 0;
    mItemData[7].mUID[48] = 0;
    mItemData[7].mUID[49] = 0;
    mItemData[7].mUID[50] = 0;
    mItemData[7].mUID[51] = 0;
    mItemData[7].mUID[52] = 0;
    mItemData[7].mUID[53] = 0;
    mItemData[7].mUID[54] = 0;
    mItemData[7].mUID[55] = 0;
    mItemData[7].mUID[40] = 0;
    mItemData[7].mUID[41] = 0;
    mItemData[7].mUID[42] = 0;
    mItemData[7].mUID[43] = 0;
    mItemData[7].mUID[44] = 0;
    mItemData[7].mUID[45] = 0;
    mItemData[7].mUID[46] = 0;
    mItemData[7].mUID[47] = 0;
    mItemData[7].mUID[32] = 0;
    mItemData[7].mUID[33] = 0;
    mItemData[7].mUID[34] = 0;
    mItemData[7].mUID[35] = 0;
    mItemData[7].mUID[36] = 0;
    mItemData[7].mUID[37] = 0;
    mItemData[7].mUID[38] = 0;
    mItemData[7].mUID[39] = 0;
    mItemData[7].mUID[24] = 0;
    mItemData[7].mUID[25] = 0;
    mItemData[7].mUID[26] = 0;
    mItemData[7].mUID[27] = 0;
    mItemData[7].mUID[28] = 0;
    mItemData[7].mUID[29] = 0;
    mItemData[7].mUID[30] = 0;
    mItemData[7].mUID[31] = 0;
    mItemData[7].mUID[16] = 0;
    mItemData[7].mUID[17] = 0;
    mItemData[7].mUID[18] = 0;
    mItemData[7].mUID[19] = 0;
    mItemData[7].mUID[20] = 0;
    mItemData[7].mUID[21] = 0;
    mItemData[7].mUID[22] = 0;
    mItemData[7].mUID[23] = 0;
    mItemData[7].mUID[8] = 0;
    mItemData[7].mUID[9] = 0;
    mItemData[7].mUID[10] = 0;
    mItemData[7].mUID[11] = 0;
    mItemData[7].mUID[12] = 0;
    mItemData[7].mUID[13] = 0;
    mItemData[7].mUID[14] = 0;
    mItemData[7].mUID[15] = 0;
    mItemData[7].mUID[0] = 0;
    mItemData[7].mUID[1] = 0;
    mItemData[7].mUID[2] = 0;
    mItemData[7].mUID[3] = 0;
    mItemData[7].mUID[4] = 0;
    mItemData[7].mUID[5] = 0;
    mItemData[7].mUID[6] = 0;
    mItemData[7].mUID[7] = 0;
    mItemData[7].mColor = -1;
    mItemData[7].mSex = 0xFF;
    mItemData[8].mId = 0;
    mItemData[8].mCraftElementItemNo[2] = 0;
    mItemData[8].mCraftElementItemNo[3] = 0;
    mItemData[8].mCraftElementItemNo[0] = 0;
    mItemData[8].mCraftElementItemNo[1] = 0;
    mItemData[8].mUID[56] = 0;
    mItemData[8].mUID[57] = 0;
    mItemData[8].mUID[58] = 0;
    mItemData[8].mUID[59] = 0;
    mItemData[8].mUID[60] = 0;
    mItemData[8].mUID[61] = 0;
    mItemData[8].mUID[62] = 0;
    mItemData[8].mUID[63] = 0;
    mItemData[8].mUID[48] = 0;
    mItemData[8].mUID[49] = 0;
    mItemData[8].mUID[50] = 0;
    mItemData[8].mUID[51] = 0;
    mItemData[8].mUID[52] = 0;
    mItemData[8].mUID[53] = 0;
    mItemData[8].mUID[54] = 0;
    mItemData[8].mUID[55] = 0;
    mItemData[8].mUID[40] = 0;
    mItemData[8].mUID[41] = 0;
    mItemData[8].mUID[42] = 0;
    mItemData[8].mUID[43] = 0;
    mItemData[8].mUID[44] = 0;
    mItemData[8].mUID[45] = 0;
    mItemData[8].mUID[46] = 0;
    mItemData[8].mUID[47] = 0;
    mItemData[8].mUID[32] = 0;
    mItemData[8].mUID[33] = 0;
    mItemData[8].mUID[34] = 0;
    mItemData[8].mUID[35] = 0;
    mItemData[8].mUID[36] = 0;
    mItemData[8].mUID[37] = 0;
    mItemData[8].mUID[38] = 0;
    mItemData[8].mUID[39] = 0;
    mItemData[8].mUID[24] = 0;
    mItemData[8].mUID[25] = 0;
    mItemData[8].mUID[26] = 0;
    mItemData[8].mUID[27] = 0;
    mItemData[8].mUID[28] = 0;
    mItemData[8].mUID[29] = 0;
    mItemData[8].mUID[30] = 0;
    mItemData[8].mUID[31] = 0;
    mItemData[8].mUID[16] = 0;
    mItemData[8].mUID[17] = 0;
    mItemData[8].mUID[18] = 0;
    mItemData[8].mUID[19] = 0;
    mItemData[8].mUID[20] = 0;
    mItemData[8].mUID[21] = 0;
    mItemData[8].mUID[22] = 0;
    mItemData[8].mUID[23] = 0;
    mItemData[8].mUID[8] = 0;
    mItemData[8].mUID[9] = 0;
    mItemData[8].mUID[10] = 0;
    mItemData[8].mUID[11] = 0;
    mItemData[8].mUID[12] = 0;
    mItemData[8].mUID[13] = 0;
    mItemData[8].mUID[14] = 0;
    mItemData[8].mUID[15] = 0;
    mItemData[8].mUID[0] = 0;
    mItemData[8].mUID[1] = 0;
    mItemData[8].mUID[2] = 0;
    mItemData[8].mUID[3] = 0;
    mItemData[8].mUID[4] = 0;
    mItemData[8].mUID[5] = 0;
    mItemData[8].mUID[6] = 0;
    mItemData[8].mUID[7] = 0;
    mItemData[8].mColor = -1;
    mItemData[8].mSex = 0xFF;
    mItemData[9].mId = 0;
    mItemData[9].mCraftElementItemNo[2] = 0;
    mItemData[9].mCraftElementItemNo[3] = 0;
    mItemData[9].mCraftElementItemNo[0] = 0;
    mItemData[9].mCraftElementItemNo[1] = 0;
    mItemData[9].mUID[56] = 0;
    mItemData[9].mUID[57] = 0;
    mItemData[9].mUID[58] = 0;
    mItemData[9].mUID[59] = 0;
    mItemData[9].mUID[60] = 0;
    mItemData[9].mUID[61] = 0;
    mItemData[9].mUID[62] = 0;
    mItemData[9].mUID[63] = 0;
    mItemData[9].mUID[48] = 0;
    mItemData[9].mUID[49] = 0;
    mItemData[9].mUID[50] = 0;
    mItemData[9].mUID[51] = 0;
    mItemData[9].mUID[52] = 0;
    mItemData[9].mUID[53] = 0;
    mItemData[9].mUID[54] = 0;
    mItemData[9].mUID[55] = 0;
    mItemData[9].mUID[40] = 0;
    mItemData[9].mUID[41] = 0;
    mItemData[9].mUID[42] = 0;
    mItemData[9].mUID[43] = 0;
    mItemData[9].mUID[44] = 0;
    mItemData[9].mUID[45] = 0;
    mItemData[9].mUID[46] = 0;
    mItemData[9].mUID[47] = 0;
    mItemData[9].mUID[32] = 0;
    mItemData[9].mUID[33] = 0;
    mItemData[9].mUID[34] = 0;
    mItemData[9].mUID[35] = 0;
    mItemData[9].mUID[36] = 0;
    mItemData[9].mUID[37] = 0;
    mItemData[9].mUID[38] = 0;
    mItemData[9].mUID[39] = 0;
    mItemData[9].mUID[24] = 0;
    mItemData[9].mUID[25] = 0;
    mItemData[9].mUID[26] = 0;
    mItemData[9].mUID[27] = 0;
    mItemData[9].mUID[28] = 0;
    mItemData[9].mUID[29] = 0;
    mItemData[9].mUID[30] = 0;
    mItemData[9].mUID[31] = 0;
    mItemData[9].mUID[16] = 0;
    mItemData[9].mUID[17] = 0;
    mItemData[9].mUID[18] = 0;
    mItemData[9].mUID[19] = 0;
    mItemData[9].mUID[20] = 0;
    mItemData[9].mUID[21] = 0;
    mItemData[9].mUID[22] = 0;
    mItemData[9].mUID[23] = 0;
    mItemData[9].mUID[8] = 0;
    mItemData[9].mUID[9] = 0;
    mItemData[9].mUID[10] = 0;
    mItemData[9].mUID[11] = 0;
    mItemData[9].mUID[12] = 0;
    mItemData[9].mUID[13] = 0;
    mItemData[9].mUID[14] = 0;
    mItemData[9].mUID[15] = 0;
    mItemData[9].mUID[0] = 0;
    mItemData[9].mUID[1] = 0;
    mItemData[9].mUID[2] = 0;
    mItemData[9].mUID[3] = 0;
    mItemData[9].mUID[4] = 0;
    mItemData[9].mUID[5] = 0;
    mItemData[9].mUID[6] = 0;
    mItemData[9].mUID[7] = 0;
    mItemData[9].mColor = -1;
    mItemData[9].mSex = 0xFF;
    mItemData[10].mId = 0;
    mItemData[10].mCraftElementItemNo[2] = 0;
    mItemData[10].mCraftElementItemNo[3] = 0;
    mItemData[10].mCraftElementItemNo[0] = 0;
    mItemData[10].mCraftElementItemNo[1] = 0;
    mItemData[10].mUID[56] = 0;
    mItemData[10].mUID[57] = 0;
    mItemData[10].mUID[58] = 0;
    mItemData[10].mUID[59] = 0;
    mItemData[10].mUID[60] = 0;
    mItemData[10].mUID[61] = 0;
    mItemData[10].mUID[62] = 0;
    mItemData[10].mUID[63] = 0;
    mItemData[10].mUID[48] = 0;
    mItemData[10].mUID[49] = 0;
    mItemData[10].mUID[50] = 0;
    mItemData[10].mUID[51] = 0;
    mItemData[10].mUID[52] = 0;
    mItemData[10].mUID[53] = 0;
    mItemData[10].mUID[54] = 0;
    mItemData[10].mUID[55] = 0;
    mItemData[10].mUID[40] = 0;
    mItemData[10].mUID[41] = 0;
    mItemData[10].mUID[42] = 0;
    mItemData[10].mUID[43] = 0;
    mItemData[10].mUID[44] = 0;
    mItemData[10].mUID[45] = 0;
    mItemData[10].mUID[46] = 0;
    mItemData[10].mUID[47] = 0;
    mItemData[10].mUID[32] = 0;
    mItemData[10].mUID[33] = 0;
    mItemData[10].mUID[34] = 0;
    mItemData[10].mUID[35] = 0;
    mItemData[10].mUID[36] = 0;
    mItemData[10].mUID[37] = 0;
    mItemData[10].mUID[38] = 0;
    mItemData[10].mUID[39] = 0;
    mItemData[10].mUID[24] = 0;
    mItemData[10].mUID[25] = 0;
    mItemData[10].mUID[26] = 0;
    mItemData[10].mUID[27] = 0;
    mItemData[10].mUID[28] = 0;
    mItemData[10].mUID[29] = 0;
    mItemData[10].mUID[30] = 0;
    mItemData[10].mUID[31] = 0;
    mItemData[10].mUID[16] = 0;
    mItemData[10].mUID[17] = 0;
    mItemData[10].mUID[18] = 0;
    mItemData[10].mUID[19] = 0;
    mItemData[10].mUID[20] = 0;
    mItemData[10].mUID[21] = 0;
    mItemData[10].mUID[22] = 0;
    mItemData[10].mUID[23] = 0;
    mItemData[10].mUID[8] = 0;
    mItemData[10].mUID[9] = 0;
    mItemData[10].mUID[10] = 0;
    mItemData[10].mUID[11] = 0;
    mItemData[10].mUID[12] = 0;
    mItemData[10].mUID[13] = 0;
    mItemData[10].mUID[14] = 0;
    mItemData[10].mUID[15] = 0;
    mItemData[10].mUID[0] = 0;
    mItemData[10].mUID[1] = 0;
    mItemData[10].mUID[2] = 0;
    mItemData[10].mUID[3] = 0;
    mItemData[10].mUID[4] = 0;
    mItemData[10].mUID[5] = 0;
    mItemData[10].mUID[6] = 0;
    mItemData[10].mUID[7] = 0;
    mItemData[10].mColor = -1;
    mItemData[10].mSex = 0xFF;
    mItemData[11].mId = 0;
    mItemData[11].mCraftElementItemNo[2] = 0;
    mItemData[11].mCraftElementItemNo[3] = 0;
    mItemData[11].mCraftElementItemNo[0] = 0;
    mItemData[11].mCraftElementItemNo[1] = 0;
    mItemData[11].mUID[56] = 0;
    mItemData[11].mUID[57] = 0;
    mItemData[11].mUID[58] = 0;
    mItemData[11].mUID[59] = 0;
    mItemData[11].mUID[60] = 0;
    mItemData[11].mUID[61] = 0;
    mItemData[11].mUID[62] = 0;
    mItemData[11].mUID[63] = 0;
    mItemData[11].mUID[48] = 0;
    mItemData[11].mUID[49] = 0;
    mItemData[11].mUID[50] = 0;
    mItemData[11].mUID[51] = 0;
    mItemData[11].mUID[52] = 0;
    mItemData[11].mUID[53] = 0;
    mItemData[11].mUID[54] = 0;
    mItemData[11].mUID[55] = 0;
    mItemData[11].mUID[40] = 0;
    mItemData[11].mUID[41] = 0;
    mItemData[11].mUID[42] = 0;
    mItemData[11].mUID[43] = 0;
    mItemData[11].mUID[44] = 0;
    mItemData[11].mUID[45] = 0;
    mItemData[11].mUID[46] = 0;
    mItemData[11].mUID[47] = 0;
    mItemData[11].mUID[32] = 0;
    mItemData[11].mUID[33] = 0;
    mItemData[11].mUID[34] = 0;
    mItemData[11].mUID[35] = 0;
    mItemData[11].mUID[36] = 0;
    mItemData[11].mUID[37] = 0;
    mItemData[11].mUID[38] = 0;
    mItemData[11].mUID[39] = 0;
    mItemData[11].mUID[24] = 0;
    mItemData[11].mUID[25] = 0;
    mItemData[11].mUID[26] = 0;
    mItemData[11].mUID[27] = 0;
    mItemData[11].mUID[28] = 0;
    mItemData[11].mUID[29] = 0;
    mItemData[11].mUID[30] = 0;
    mItemData[11].mUID[31] = 0;
    mItemData[11].mUID[16] = 0;
    mItemData[11].mUID[17] = 0;
    mItemData[11].mUID[18] = 0;
    mItemData[11].mUID[19] = 0;
    mItemData[11].mUID[20] = 0;
    mItemData[11].mUID[21] = 0;
    mItemData[11].mUID[22] = 0;
    mItemData[11].mUID[23] = 0;
    mItemData[11].mUID[8] = 0;
    mItemData[11].mUID[9] = 0;
    mItemData[11].mUID[10] = 0;
    mItemData[11].mUID[11] = 0;
    mItemData[11].mUID[12] = 0;
    mItemData[11].mUID[13] = 0;
    mItemData[11].mUID[14] = 0;
    mItemData[11].mUID[15] = 0;
    mItemData[11].mUID[0] = 0;
    mItemData[11].mUID[1] = 0;
    mItemData[11].mUID[2] = 0;
    mItemData[11].mUID[3] = 0;
    mItemData[11].mUID[4] = 0;
    mItemData[11].mUID[5] = 0;
    mItemData[11].mUID[6] = 0;
    mItemData[11].mUID[7] = 0;
    mItemData[11].mColor = -1;
    mItemData[11].mSex = 0xFF;
    mItemData[12].mId = 0;
    mItemData[12].mCraftElementItemNo[2] = 0;
    mItemData[12].mCraftElementItemNo[3] = 0;
    mItemData[12].mCraftElementItemNo[0] = 0;
    mItemData[12].mCraftElementItemNo[1] = 0;
    mItemData[12].mUID[56] = 0;
    mItemData[12].mUID[57] = 0;
    mItemData[12].mUID[58] = 0;
    mItemData[12].mUID[59] = 0;
    mItemData[12].mUID[60] = 0;
    mItemData[12].mUID[61] = 0;
    mItemData[12].mUID[62] = 0;
    mItemData[12].mUID[63] = 0;
    mItemData[12].mUID[48] = 0;
    mItemData[12].mUID[49] = 0;
    mItemData[12].mUID[50] = 0;
    mItemData[12].mUID[51] = 0;
    mItemData[12].mUID[52] = 0;
    mItemData[12].mUID[53] = 0;
    mItemData[12].mUID[54] = 0;
    mItemData[12].mUID[55] = 0;
    mItemData[12].mUID[40] = 0;
    mItemData[12].mUID[41] = 0;
    mItemData[12].mUID[42] = 0;
    mItemData[12].mUID[43] = 0;
    mItemData[12].mUID[44] = 0;
    mItemData[12].mUID[45] = 0;
    mItemData[12].mUID[46] = 0;
    mItemData[12].mUID[47] = 0;
    mItemData[12].mUID[32] = 0;
    mItemData[12].mUID[33] = 0;
    mItemData[12].mUID[34] = 0;
    mItemData[12].mUID[35] = 0;
    mItemData[12].mUID[36] = 0;
    mItemData[12].mUID[37] = 0;
    mItemData[12].mUID[38] = 0;
    mItemData[12].mUID[39] = 0;
    mItemData[12].mUID[24] = 0;
    mItemData[12].mUID[25] = 0;
    mItemData[12].mUID[26] = 0;
    mItemData[12].mUID[27] = 0;
    mItemData[12].mUID[28] = 0;
    mItemData[12].mUID[29] = 0;
    mItemData[12].mUID[30] = 0;
    mItemData[12].mUID[31] = 0;
    mItemData[12].mUID[16] = 0;
    mItemData[12].mUID[17] = 0;
    mItemData[12].mUID[18] = 0;
    mItemData[12].mUID[19] = 0;
    mItemData[12].mUID[20] = 0;
    mItemData[12].mUID[21] = 0;
    mItemData[12].mUID[22] = 0;
    mItemData[12].mUID[23] = 0;
    mItemData[12].mUID[8] = 0;
    mItemData[12].mUID[9] = 0;
    mItemData[12].mUID[10] = 0;
    mItemData[12].mUID[11] = 0;
    mItemData[12].mUID[12] = 0;
    mItemData[12].mUID[13] = 0;
    mItemData[12].mUID[14] = 0;
    mItemData[12].mUID[15] = 0;
    mItemData[12].mUID[0] = 0;
    mItemData[12].mUID[1] = 0;
    mItemData[12].mUID[2] = 0;
    mItemData[12].mUID[3] = 0;
    mItemData[12].mUID[4] = 0;
    mItemData[12].mUID[5] = 0;
    mItemData[12].mUID[6] = 0;
    mItemData[12].mUID[7] = 0;
    mItemData[12].mColor = -1;
    mItemData[12].mSex = 0xFF;
    mItemData[13].mId = 0;
    mItemData[13].mCraftElementItemNo[2] = 0;
    mItemData[13].mCraftElementItemNo[3] = 0;
    mItemData[13].mCraftElementItemNo[0] = 0;
    mItemData[13].mCraftElementItemNo[1] = 0;
    mItemData[13].mUID[56] = 0;
    mItemData[13].mUID[57] = 0;
    mItemData[13].mUID[58] = 0;
    mItemData[13].mUID[59] = 0;
    mItemData[13].mUID[60] = 0;
    mItemData[13].mUID[61] = 0;
    mItemData[13].mUID[62] = 0;
    mItemData[13].mUID[63] = 0;
    mItemData[13].mUID[48] = 0;
    mItemData[13].mUID[49] = 0;
    mItemData[13].mUID[50] = 0;
    mItemData[13].mUID[51] = 0;
    mItemData[13].mUID[52] = 0;
    mItemData[13].mUID[53] = 0;
    mItemData[13].mUID[54] = 0;
    mItemData[13].mUID[55] = 0;
    mItemData[13].mUID[40] = 0;
    mItemData[13].mUID[41] = 0;
    mItemData[13].mUID[42] = 0;
    mItemData[13].mUID[43] = 0;
    mItemData[13].mUID[44] = 0;
    mItemData[13].mUID[45] = 0;
    mItemData[13].mUID[46] = 0;
    mItemData[13].mUID[47] = 0;
    mItemData[13].mUID[32] = 0;
    mItemData[13].mUID[33] = 0;
    mItemData[13].mUID[34] = 0;
    mItemData[13].mUID[35] = 0;
    mItemData[13].mUID[36] = 0;
    mItemData[13].mUID[37] = 0;
    mItemData[13].mUID[38] = 0;
    mItemData[13].mUID[39] = 0;
    mItemData[13].mUID[24] = 0;
    mItemData[13].mUID[25] = 0;
    mItemData[13].mUID[26] = 0;
    mItemData[13].mUID[27] = 0;
    mItemData[13].mUID[28] = 0;
    mItemData[13].mUID[29] = 0;
    mItemData[13].mUID[30] = 0;
    mItemData[13].mUID[31] = 0;
    mItemData[13].mUID[16] = 0;
    mItemData[13].mUID[17] = 0;
    mItemData[13].mUID[18] = 0;
    mItemData[13].mUID[19] = 0;
    mItemData[13].mUID[20] = 0;
    mItemData[13].mUID[21] = 0;
    mItemData[13].mUID[22] = 0;
    mItemData[13].mUID[23] = 0;
    mItemData[13].mUID[8] = 0;
    mItemData[13].mUID[9] = 0;
    mItemData[13].mUID[10] = 0;
    mItemData[13].mUID[11] = 0;
    mItemData[13].mUID[12] = 0;
    mItemData[13].mUID[13] = 0;
    mItemData[13].mUID[14] = 0;
    mItemData[13].mUID[15] = 0;
    mItemData[13].mUID[0] = 0;
    mItemData[13].mUID[1] = 0;
    mItemData[13].mUID[2] = 0;
    mItemData[13].mUID[3] = 0;
    mItemData[13].mUID[4] = 0;
    mItemData[13].mUID[5] = 0;
    mItemData[13].mUID[6] = 0;
    mItemData[13].mUID[7] = 0;
    mItemData[13].mColor = -1;
    mItemData[13].mSex = 0xFF;
    mItemData[14].mId = 0;
    mItemData[14].mCraftElementItemNo[2] = 0;
    mItemData[14].mCraftElementItemNo[3] = 0;
    mItemData[14].mCraftElementItemNo[0] = 0;
    mItemData[14].mCraftElementItemNo[1] = 0;
    mItemData[14].mUID[56] = 0;
    mItemData[14].mUID[57] = 0;
    mItemData[14].mUID[58] = 0;
    mItemData[14].mUID[59] = 0;
    mItemData[14].mUID[60] = 0;
    mItemData[14].mUID[61] = 0;
    mItemData[14].mUID[62] = 0;
    mItemData[14].mUID[63] = 0;
    mItemData[14].mUID[48] = 0;
    mItemData[14].mUID[49] = 0;
    mItemData[14].mUID[50] = 0;
    mItemData[14].mUID[51] = 0;
    mItemData[14].mUID[52] = 0;
    mItemData[14].mUID[53] = 0;
    mItemData[14].mUID[54] = 0;
    mItemData[14].mUID[55] = 0;
    mItemData[14].mUID[40] = 0;
    mItemData[14].mUID[41] = 0;
    mItemData[14].mUID[42] = 0;
    mItemData[14].mUID[43] = 0;
    mItemData[14].mUID[44] = 0;
    mItemData[14].mUID[45] = 0;
    mItemData[14].mUID[46] = 0;
    mItemData[14].mUID[47] = 0;
    mItemData[14].mUID[32] = 0;
    mItemData[14].mUID[33] = 0;
    mItemData[14].mUID[34] = 0;
    mItemData[14].mUID[35] = 0;
    mItemData[14].mUID[36] = 0;
    mItemData[14].mUID[37] = 0;
    mItemData[14].mUID[38] = 0;
    mItemData[14].mUID[39] = 0;
    mItemData[14].mUID[24] = 0;
    mItemData[14].mUID[25] = 0;
    mItemData[14].mUID[26] = 0;
    mItemData[14].mUID[27] = 0;
    mItemData[14].mUID[28] = 0;
    mItemData[14].mUID[29] = 0;
    mItemData[14].mUID[30] = 0;
    mItemData[14].mUID[31] = 0;
    mItemData[14].mUID[16] = 0;
    mItemData[14].mUID[17] = 0;
    mItemData[14].mUID[18] = 0;
    mItemData[14].mUID[19] = 0;
    mItemData[14].mUID[20] = 0;
    mItemData[14].mUID[21] = 0;
    mItemData[14].mUID[22] = 0;
    mItemData[14].mUID[23] = 0;
    mItemData[14].mUID[8] = 0;
    mItemData[14].mUID[9] = 0;
    mItemData[14].mUID[10] = 0;
    mItemData[14].mUID[11] = 0;
    mItemData[14].mUID[12] = 0;
    mItemData[14].mUID[13] = 0;
    mItemData[14].mUID[14] = 0;
    mItemData[14].mUID[15] = 0;
    mItemData[14].mUID[0] = 0;
    mItemData[14].mUID[1] = 0;
    mItemData[14].mUID[2] = 0;
    mItemData[14].mUID[3] = 0;
    mItemData[14].mUID[4] = 0;
    mItemData[14].mUID[5] = 0;
    mItemData[14].mUID[6] = 0;
    mItemData[14].mUID[7] = 0;
    mItemData[14].mColor = -1;
    mItemData[14].mSex = 0xFF;
    mMannequineItemData.mCraftElementItemNo[2] = 0;
    mMannequineItemData.mCraftElementItemNo[3] = 0;
    mMannequineItemData.mCraftElementItemNo[0] = 0;
    mMannequineItemData.mCraftElementItemNo[1] = 0;
    mMannequineItemData.mUID[56] = '\0';
    mMannequineItemData.mUID[57] = '\0';
    mMannequineItemData.mUID[58] = '\0';
    mMannequineItemData.mUID[59] = '\0';
    mMannequineItemData.mUID[60] = '\0';
    mMannequineItemData.mUID[61] = '\0';
    mMannequineItemData.mUID[62] = '\0';
    mMannequineItemData.mUID[63] = '\0';
    mMannequineItemData.mUID[48] = '\0';
    mMannequineItemData.mUID[49] = '\0';
    mMannequineItemData.mUID[50] = '\0';
    mMannequineItemData.mUID[51] = '\0';
    mMannequineItemData.mUID[52] = '\0';
    mMannequineItemData.mUID[53] = '\0';
    mMannequineItemData.mUID[54] = '\0';
    mMannequineItemData.mUID[55] = '\0';
    mMannequineItemData.mUID[40] = '\0';
    mMannequineItemData.mUID[41] = '\0';
    mMannequineItemData.mUID[42] = '\0';
    mMannequineItemData.mUID[43] = '\0';
    mMannequineItemData.mUID[44] = '\0';
    mMannequineItemData.mUID[45] = '\0';
    mMannequineItemData.mUID[46] = '\0';
    mMannequineItemData.mUID[47] = '\0';
    mMannequineItemData.mUID[32] = '\0';
    mMannequineItemData.mUID[33] = '\0';
    mMannequineItemData.mUID[34] = '\0';
    mMannequineItemData.mUID[35] = '\0';
    mMannequineItemData.mUID[36] = '\0';
    mMannequineItemData.mUID[37] = '\0';
    mMannequineItemData.mUID[38] = '\0';
    mMannequineItemData.mUID[39] = '\0';
    mMannequineItemData.mUID[24] = '\0';
    mMannequineItemData.mUID[25] = '\0';
    mMannequineItemData.mUID[26] = '\0';
    mMannequineItemData.mUID[27] = '\0';
    mMannequineItemData.mUID[28] = '\0';
    mMannequineItemData.mUID[29] = '\0';
    mMannequineItemData.mUID[30] = '\0';
    mMannequineItemData.mUID[31] = '\0';
    mMannequineItemData.mUID[16] = '\0';
    mMannequineItemData.mUID[17] = '\0';
    mMannequineItemData.mUID[18] = '\0';
    mMannequineItemData.mUID[19] = '\0';
    mMannequineItemData.mUID[20] = '\0';
    mMannequineItemData.mUID[21] = '\0';
    mMannequineItemData.mUID[22] = '\0';
    mMannequineItemData.mUID[23] = '\0';
    mMannequineItemData.mUID[8] = '\0';
    mMannequineItemData.mUID[9] = '\0';
    mMannequineItemData.mUID[10] = '\0';
    mMannequineItemData.mUID[11] = '\0';
    mMannequineItemData.mUID[12] = '\0';
    mMannequineItemData.mUID[13] = '\0';
    mMannequineItemData.mUID[14] = '\0';
    mMannequineItemData.mUID[15] = '\0';
    mMannequineItemData.mUID[0] = '\0';
    mMannequineItemData.mUID[1] = '\0';
    mMannequineItemData.mUID[2] = '\0';
    mMannequineItemData.mUID[3] = '\0';
    mMannequineItemData.mUID[4] = '\0';
    mMannequineItemData.mUID[5] = '\0';
    mMannequineItemData.mUID[6] = '\0';
    mMannequineItemData.mUID[7] = '\0';
    mMannequineItemData.mSex = 0xFF;
    mMannequineItemData.mId = item_id;
    mMannequineItemData.mColor = color;
    if (pItemParam != nullptr) {
        snprintf(&mMannequineItemData.mUID[0], 64ul, "%s", pItemParam->mWstrUID.ptr());
        mMannequineItemData.mCraftElementItemNo[0] = pItemParam->mCraftParam.getElementItemNo(0u);
        mMannequineItemData.mCraftElementItemNo[1] = pItemParam->mCraftParam.getElementItemNo(1u);
        mMannequineItemData.mCraftElementItemNo[2] = pItemParam->mCraftParam.getElementItemNo(2u);
        mMannequineItemData.mCraftElementItemNo[3] = pItemParam->mCraftParam.getElementItemNo(3u);
    }
    mIsMannequine = true;
}

void uUIMockUp::DispInfo::setItem(u32 item_id, s32 color, const cItemParam* pItemParam) {
    sItemManager* t0 = sItemManager::getInstance();
    rItemList::rItemParam* pParam = t0->getItemParam(item_id);
    if (pParam == nullptr) {
        return;
    }
    u8 t2 = pParam->mCategory;
    if (t2 != 3) {
        return;
    }
    const nCharacterData::EQUIP_CATEGORY cate = static_cast<const nCharacterData::EQUIP_CATEGORY>(pParam->getEquipCategory());
    const nCharacterData::EQUIP_SLOT_TYPE slot = cEquipData::convEquipCateToSlotType(cate);
    const u32 index = cEquipData::convEquipCateToIndex(slot);
    mItemData[index].mCraftElementItemNo[2] = 0;
    mItemData[index].mCraftElementItemNo[3] = 0;
    mItemData[index].mCraftElementItemNo[0] = 0;
    mItemData[index].mCraftElementItemNo[1] = 0;
    mItemData[index].mUID[56] = '\0';
    mItemData[index].mUID[57] = '\0';
    mItemData[index].mUID[58] = '\0';
    mItemData[index].mUID[59] = '\0';
    mItemData[index].mUID[60] = '\0';
    mItemData[index].mUID[61] = '\0';
    mItemData[index].mUID[62] = '\0';
    mItemData[index].mUID[63] = '\0';
    mItemData[index].mUID[48] = '\0';
    mItemData[index].mUID[49] = '\0';
    mItemData[index].mUID[50] = '\0';
    mItemData[index].mUID[51] = '\0';
    mItemData[index].mUID[52] = '\0';
    mItemData[index].mUID[53] = '\0';
    mItemData[index].mUID[54] = '\0';
    mItemData[index].mUID[55] = '\0';
    mItemData[index].mUID[40] = '\0';
    mItemData[index].mUID[41] = '\0';
    mItemData[index].mUID[42] = '\0';
    mItemData[index].mUID[43] = '\0';
    mItemData[index].mUID[44] = '\0';
    mItemData[index].mUID[45] = '\0';
    mItemData[index].mUID[46] = '\0';
    mItemData[index].mUID[47] = '\0';
    mItemData[index].mUID[32] = '\0';
    mItemData[index].mUID[33] = '\0';
    mItemData[index].mUID[34] = '\0';
    mItemData[index].mUID[35] = '\0';
    mItemData[index].mUID[36] = '\0';
    mItemData[index].mUID[37] = '\0';
    mItemData[index].mUID[38] = '\0';
    mItemData[index].mUID[39] = '\0';
    mItemData[index].mUID[24] = '\0';
    mItemData[index].mUID[25] = '\0';
    mItemData[index].mUID[26] = '\0';
    mItemData[index].mUID[27] = '\0';
    mItemData[index].mUID[28] = '\0';
    mItemData[index].mUID[29] = '\0';
    mItemData[index].mUID[30] = '\0';
    mItemData[index].mUID[31] = '\0';
    mItemData[index].mUID[16] = '\0';
    mItemData[index].mUID[17] = '\0';
    mItemData[index].mUID[18] = '\0';
    mItemData[index].mUID[19] = '\0';
    mItemData[index].mUID[20] = '\0';
    mItemData[index].mUID[21] = '\0';
    mItemData[index].mUID[22] = '\0';
    mItemData[index].mUID[23] = '\0';
    mItemData[index].mUID[8] = '\0';
    mItemData[index].mUID[9] = '\0';
    mItemData[index].mUID[10] = '\0';
    mItemData[index].mUID[11] = '\0';
    mItemData[index].mUID[12] = '\0';
    mItemData[index].mUID[13] = '\0';
    mItemData[index].mUID[14] = '\0';
    mItemData[index].mUID[15] = '\0';
    mItemData[index].mUID[0] = '\0';
    mItemData[index].mUID[1] = '\0';
    mItemData[index].mUID[2] = '\0';
    mItemData[index].mUID[3] = '\0';
    mItemData[index].mUID[4] = '\0';
    mItemData[index].mUID[5] = '\0';
    mItemData[index].mUID[6] = '\0';
    mItemData[index].mUID[7] = '\0';
    mItemData[index].mSex = 0xFF;
    mItemData[index].mId = item_id;
    mItemData[index].mColor = color;
    if (pItemParam == nullptr) {
        return;
    }
    snprintf(&mItemData[index].mUID[0], 64ul, "%s", pItemParam->mWstrUID.ptr());
    u32 t8 = pItemParam->mCraftParam.getElementItemNo(0u);
    mItemData[index].mCraftElementItemNo[0] = t8;
    u32 t10 = pItemParam->mCraftParam.getElementItemNo(1u);
    mItemData[index].mCraftElementItemNo[1] = t10;
    u32 t12 = pItemParam->mCraftParam.getElementItemNo(2u);
    mItemData[index].mCraftElementItemNo[2] = t12;
    u32 t14 = pItemParam->mCraftParam.getElementItemNo(3u);
    mItemData[index].mCraftElementItemNo[3] = t14;
}

