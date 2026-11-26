// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cGUIUtility.h"
#include "Protocol/PacketData/Common.h"
#include "Protocol/PacketData/GP.h"
#include "Protocol/PacketData/JobMaster.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCharset.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemory.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "../../MT/MtTime.h"
#include "Protocol/PacketData/Server.h"
#include "aStage.h"
#include "cAcquirementData.h"
#include "../../XFramework/cArea.h"
#include "cCharacterData.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cEquipData.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cHitInfoAfter.h"
#include "cHitInfoAfterLocal.h"
#include "cItemParam.h"
#include "cNetGameServer.h"
#include "cNetLoginServer.h"
#include "cOcdBase.h"
#include "../../XFramework/cUnit.h"
#include "cpOcdCtrl.h"
#include "nCharacterData.h"
#include "nGUIExt.h"
#include "../../generated/shared/nHuman.h"
#include "nHumanMsg.h"
#include "../../generated/shared/nKeyCustom.h"
#include "nQuest.h"
#include "../../XFramework/rGUIFont.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "rStageInfo.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sInputManager.h"
#include "sItemManager.h"
#include "../../XFramework/sKeyboard.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sRender.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sWeatherManager.h"
#include "uControlNpc.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uGUIBase.h"
#include "uGUIPopCmd01.h"
#include "uGUISystemMsg.h"
#include "uPlayer.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const CrestElementParam CrestElementParams[89] = {
    {static_cast<CrestElementParam::TYPE>(0), 4294967295},
    {static_cast<CrestElementParam::TYPE>(2), 18},
    {static_cast<CrestElementParam::TYPE>(1), 54},
    {static_cast<CrestElementParam::TYPE>(1), 55},
    {static_cast<CrestElementParam::TYPE>(1), 56},
    {static_cast<CrestElementParam::TYPE>(1), 57},
    {static_cast<CrestElementParam::TYPE>(1), 58},
    {static_cast<CrestElementParam::TYPE>(1), 21},
    {static_cast<CrestElementParam::TYPE>(1), 22},
    {static_cast<CrestElementParam::TYPE>(1), 25},
    {static_cast<CrestElementParam::TYPE>(1), 26},
    {static_cast<CrestElementParam::TYPE>(1), 45},
    {static_cast<CrestElementParam::TYPE>(1), 46},
    {static_cast<CrestElementParam::TYPE>(1), 47},
    {static_cast<CrestElementParam::TYPE>(1), 48},
    {static_cast<CrestElementParam::TYPE>(1), 49},
    {static_cast<CrestElementParam::TYPE>(1), 50},
    {static_cast<CrestElementParam::TYPE>(1), 51},
    {static_cast<CrestElementParam::TYPE>(1), 52},
    {static_cast<CrestElementParam::TYPE>(1), 53},
    {static_cast<CrestElementParam::TYPE>(1), 59},
    {static_cast<CrestElementParam::TYPE>(1), 60},
    {static_cast<CrestElementParam::TYPE>(1), 61},
    {static_cast<CrestElementParam::TYPE>(1), 62},
    {static_cast<CrestElementParam::TYPE>(1), 63},
    {static_cast<CrestElementParam::TYPE>(1), 64},
    {static_cast<CrestElementParam::TYPE>(1), 65},
    {static_cast<CrestElementParam::TYPE>(1), 66},
    {static_cast<CrestElementParam::TYPE>(1), 67},
    {static_cast<CrestElementParam::TYPE>(1), 68},
    {static_cast<CrestElementParam::TYPE>(1), 69},
    {static_cast<CrestElementParam::TYPE>(1), 70},
    {static_cast<CrestElementParam::TYPE>(1), 71},
    {static_cast<CrestElementParam::TYPE>(1), 72},
    {static_cast<CrestElementParam::TYPE>(1), 73},
    {static_cast<CrestElementParam::TYPE>(1), 4294967295},
    {static_cast<CrestElementParam::TYPE>(1), 74},
    {static_cast<CrestElementParam::TYPE>(1), 75},
    {static_cast<CrestElementParam::TYPE>(1), 76},
    {static_cast<CrestElementParam::TYPE>(1), 77},
    {static_cast<CrestElementParam::TYPE>(1), 78},
    {static_cast<CrestElementParam::TYPE>(1), 79},
    {static_cast<CrestElementParam::TYPE>(1), 80},
    {static_cast<CrestElementParam::TYPE>(1), 81},
    {static_cast<CrestElementParam::TYPE>(1), 82},
    {static_cast<CrestElementParam::TYPE>(1), 83},
    {static_cast<CrestElementParam::TYPE>(1), 84},
    {static_cast<CrestElementParam::TYPE>(1), 85},
    {static_cast<CrestElementParam::TYPE>(1), 86},
    {static_cast<CrestElementParam::TYPE>(1), 87},
    {static_cast<CrestElementParam::TYPE>(1), 88},
    {static_cast<CrestElementParam::TYPE>(1), 89},
    {static_cast<CrestElementParam::TYPE>(1), 90},
    {static_cast<CrestElementParam::TYPE>(1), 91},
    {static_cast<CrestElementParam::TYPE>(1), 92},
    {static_cast<CrestElementParam::TYPE>(1), 93},
    {static_cast<CrestElementParam::TYPE>(1), 94},
    {static_cast<CrestElementParam::TYPE>(1), 95},
    {static_cast<CrestElementParam::TYPE>(1), 96},
    {static_cast<CrestElementParam::TYPE>(1), 97},
    {static_cast<CrestElementParam::TYPE>(1), 98},
    {static_cast<CrestElementParam::TYPE>(1), 99},
    {static_cast<CrestElementParam::TYPE>(1), 100},
    {static_cast<CrestElementParam::TYPE>(1), 101},
    {static_cast<CrestElementParam::TYPE>(1), 102},
    {static_cast<CrestElementParam::TYPE>(1), 103},
    {static_cast<CrestElementParam::TYPE>(1), 30},
    {static_cast<CrestElementParam::TYPE>(1), 31},
    {static_cast<CrestElementParam::TYPE>(1), 32},
    {static_cast<CrestElementParam::TYPE>(1), 33},
    {static_cast<CrestElementParam::TYPE>(1), 34},
    {static_cast<CrestElementParam::TYPE>(1), 35},
    {static_cast<CrestElementParam::TYPE>(1), 36},
    {static_cast<CrestElementParam::TYPE>(1), 37},
    {static_cast<CrestElementParam::TYPE>(1), 38},
    {static_cast<CrestElementParam::TYPE>(1), 39},
    {static_cast<CrestElementParam::TYPE>(1), 40},
    {static_cast<CrestElementParam::TYPE>(1), 41},
    {static_cast<CrestElementParam::TYPE>(1), 42},
    {static_cast<CrestElementParam::TYPE>(1), 43},
    {static_cast<CrestElementParam::TYPE>(1), 44},
    {static_cast<CrestElementParam::TYPE>(0), 4294967295},
    {static_cast<CrestElementParam::TYPE>(0), 4294967295},
    {static_cast<CrestElementParam::TYPE>(0), 4294967295},
    {static_cast<CrestElementParam::TYPE>(0), 4294967295},
    {static_cast<CrestElementParam::TYPE>(0), 4294967295},
    {static_cast<CrestElementParam::TYPE>(0), 4294967295},
    {static_cast<CrestElementParam::TYPE>(3), 4294967295},
    {static_cast<CrestElementParam::TYPE>(1), 215},
};

static const nGUIExt::JobParam JobParams[10] = {
    {static_cast<nHuman::JOB_ENUM>(1), 1, 1, 1, 2},
    {static_cast<nHuman::JOB_ENUM>(3), 3, 3, 7, 0},
    {static_cast<nHuman::JOB_ENUM>(4), 4, 4, 11, 0},
    {static_cast<nHuman::JOB_ENUM>(5), 5, 5, 4, 5},
    {static_cast<nHuman::JOB_ENUM>(2), 2, 2, 6, 0},
    {static_cast<nHuman::JOB_ENUM>(6), 6, 6, 12, 0},
    {static_cast<nHuman::JOB_ENUM>(8), 8, 8, 9, 0},
    {static_cast<nHuman::JOB_ENUM>(7), 7, 7, 3, 0},
    {static_cast<nHuman::JOB_ENUM>(9), 9, 9, 8, 0},
    {static_cast<nHuman::JOB_ENUM>(10), 10, 10, 13, 0},
};

namespace nGUIExt {
static const nKeyCustom::KB_CUSTOM KEY_CUSTOM_SKILL[4] = {
    static_cast<const nKeyCustom::KB_CUSTOM>(16),
    static_cast<const nKeyCustom::KB_CUSTOM>(17),
    static_cast<const nKeyCustom::KB_CUSTOM>(14),
    static_cast<const nKeyCustom::KB_CUSTOM>(15),
};
}

__attribute__((weak)) void cGUIUtility::makeDateString(u64 time, MtString& rStr) {
    DDON_STUB("cGUIUtility::makeDateString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeDateString(MtTime& rTime, MtString& rStr) {
    DDON_STUB("cGUIUtility::makeDateString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeDateTimeString(u64 time, MtString& rStr, u8 uType) {
    DDON_STUB("cGUIUtility::makeDateTimeString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeDateTimeString(MtTime& rTime, MtString& rStr, u8 uType) {
    DDON_STUB("cGUIUtility::makeDateTimeString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeTimeUnitString(MtStringEx<32>& rStr, u64 seconds, bool isRoundUp) {
    DDON_STUB("cGUIUtility::makeTimeUnitString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makePastTime(u64 time, MtString& rStr) {
    DDON_STUB("cGUIUtility::makePastTime")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeFutureTimeLimit(u64 time, MtString& rStr) {
    DDON_STUB("cGUIUtility::makeFutureTimeLimit")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeNumberString(MtString& rStr, s32 num, bool bSigned) {
    DDON_STUB("cGUIUtility::makeNumberString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeExpString(s32 sExp, MtString& rStr, bool bSigned) {
    DDON_STUB("cGUIUtility::makeExpString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeMoneyString(s32 sMoney, MtString& rStr, bool bSigned) {
    DDON_STUB("cGUIUtility::makeMoneyString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeRimString(s32 sRim, MtString& rStr, bool bSigned) {
    DDON_STUB("cGUIUtility::makeRimString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeJpString(s32 sJp, MtString& rStr, bool bSigned) {
    DDON_STUB("cGUIUtility::makeJpString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeGpString(s32 sGp, MtString& rStr, bool bSigned) {
    DDON_STUB("cGUIUtility::makeGpString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeDogmaString(s32 sDogma, MtString& rStr, bool bSigned) {
    DDON_STUB("cGUIUtility::makeDogmaString")
    /* stub */
}

void cGUIUtility::makePointString(s32 num, u32 type, MtString& rStr, bool bSigned) {
    switch (type - 1u) {
        case 0:
        {
            cGUIUtility::makeMoneyString(num, rStr, bSigned);
            break;
        }
        case 1:
        {
            cGUIUtility::makeRimString(num, rStr, bSigned);
            break;
        }
        case 2:
        {
            cGUIUtility::makeDogmaString(num, rStr, bSigned);
            break;
        }
        case 4:
        {
            cGUIUtility::makeGpString(num, rStr, bSigned);
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void cGUIUtility::makeItemName(MtString& rStr, cItemParam* pParam) {
    DDON_STUB("cGUIUtility::makeItemName")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeItemName(MtString& rStr, u32 item_id, u32 plus_value) {
    DDON_STUB("cGUIUtility::makeItemName")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeItemName(MtString& rStr, MT_CTSTR name, u32 plus_value) {
    DDON_STUB("cGUIUtility::makeItemName")
    /* stub */
}

MT_CTSTR cGUIUtility::getItemName(u32 item_id) {
    rItemList::rItemParam* pParam = sItemManager::getInstance()->getItemParam(item_id);
    if (pParam != nullptr) {
        return pParam->getItemName();
    } else {
        return "";
    }
}

__attribute__((weak)) void cGUIUtility::makeItemNameWithGrade(MtString& Str, u32 ItemId) {
    DDON_STUB("cGUIUtility::makeItemNameWithGrade")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeItemParamAbilityName(MtStringEx<128>& rStr, rItemList::rParam* param) {
    DDON_STUB("cGUIUtility::makeItemParamAbilityName")
    /* stub */
}

__attribute__((weak)) MT_CTSTR cGUIUtility::toUpperString(MT_CHAR* pSrc) {
    DDON_STUB("cGUIUtility::toUpperString")
    return {};
}

__attribute__((weak)) u32 cGUIUtility::getCharNum(MT_CTSTR pSrc) {
    DDON_STUB("cGUIUtility::getCharNum")
    return {};
}

__attribute__((weak)) void cGUIUtility::getStrFromCharNum(MT_STR pDst, MT_CTSTR pSrc, u32 uCharNum, u32 uLenMax) {
    DDON_STUB("cGUIUtility::getStrFromCharNum")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::TruncateStr(MtString& rStr, MT_CTSTR pSrc, u32 num, u32 truncateNum, MT_CHAR truncateChar) {
    DDON_STUB("cGUIUtility::TruncateStr")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::convSJIStoUTF8(const MT_CHAR* pSrcSjis, MT_CHAR* pDstUtf8, u32 bufSizeUtf8) {
    DDON_STUB("cGUIUtility::convSJIStoUTF8")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::convUTF8toSJIS(MT_CTSTR pSrcUtf8, MT_CHAR* pDstSjis, u32 bufSizeSjis) {
    DDON_STUB("cGUIUtility::convUTF8toSJIS")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeCharName(MtString& rStr, nGUIExt::NAME_TYPE type, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanShortName) {
    DDON_STUB("cGUIUtility::makeCharName")
    /* stub */
}

void cGUIUtility::makeCharName(MtString& rStr, const cContextInstHm* pContext, nGUIExt::NAME_TYPE type) {
    MT_CTSTR t0 = cContextInterface::getFirstName(pContext);
    MT_CTSTR t1 = cContextInterface::getLastName(pContext);
    cGUIUtility::makeCharName(rStr, type, t0, t1, cContextInterface::getClanNickName(pContext));
}

__attribute__((weak)) nGUIExt::NAME_TYPE cGUIUtility::ConvertNameDispToNameType(u8 nameDispType, bool isClanName) {
    DDON_STUB("cGUIUtility::ConvertNameDispToNameType")
    return {};
}

__attribute__((weak)) void cGUIUtility::TruncateCharName(MtString& rStr, nGUIExt::NAME_TYPE type, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanShortName) {
    DDON_STUB("cGUIUtility::TruncateCharName")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::convertEditNameString(MtString& str, MT_CTSTR name) {
    DDON_STUB("cGUIUtility::convertEditNameString")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::makeColorTag(MtString& rStr, const MtColor& col) {
    DDON_STUB("cGUIUtility::makeColorTag")
    /* stub */
}

__attribute__((weak)) bool cGUIUtility::SetFitString(MT_STR buffer, u32 bufferSize, MT_CTSTR str, const cGUIObjMessage* targetObjMessage, MT_CTSTR ellipsis) {
    DDON_STUB("cGUIUtility::SetFitString")
    return {};
}

__attribute__((weak)) f32 cGUIUtility::GetStringWidth(MT_CTSTR str, const cGUIObjMessage* targetObjMessage) {
    DDON_STUB("cGUIUtility::GetStringWidth")
    return {};
}

__attribute__((weak)) void cGUIUtility::GetItemEquipCategoryName(nGUIExt::StringItemCategoryName& itemCategoryName, const rItemList::rItemParam* itemParam, const rGUIMessage* resGmdParameter, const rGUIMessage* resGmdJewelryCategory) {
    DDON_STUB("cGUIUtility::GetItemEquipCategoryName")
    /* stub */
}

__attribute__((weak)) bool cGUIUtility::getCrestElementParamMsg(rItemList::rItemParam* pItemParam, u32 element_index, const rGUIMessage* pMsgParam, MtStringEx<128>& ret_str) {
    DDON_STUB("cGUIUtility::getCrestElementParamMsg")
    return {};
}

__attribute__((weak)) bool cGUIUtility::isSalon(nGUIExt::CHARA_EDIT edit) {
    DDON_STUB("cGUIUtility::isSalon")
    return {};
}

__attribute__((weak)) s32 cGUIUtility::getOnBitIndex(u32 bit, u32 index) {
    DDON_STUB("cGUIUtility::getOnBitIndex")
    return {};
}

__attribute__((weak)) s32 cGUIUtility::getKetaNum(s32 val) {
    DDON_STUB("cGUIUtility::getKetaNum")
    return {};
}

__attribute__((weak)) f32 cGUIUtility::getScaleForDefaultResolution(f32 fScaleRate) {
    DDON_STUB("cGUIUtility::getScaleForDefaultResolution")
    return {};
}

__attribute__((weak)) void cGUIUtility::AdjustMouseCollisionSize(cGUIObjPolygon* objMouseCollision, f32 height) {
    DDON_STUB("cGUIUtility::AdjustMouseCollisionSize")
    /* stub */
}

__attribute__((weak)) cItemParam* cGUIUtility::getItemParamFromUID(MT_CTSTR uid, sItemManager::STORAGE_FILLTER_TYPE filter_type) {
    DDON_STUB("cGUIUtility::getItemParamFromUID")
    return nullptr;
}

u32 cGUIUtility::getCrestItemId(cItemParam* pParam, u32 index) {
    if (pParam != nullptr) {
        if (index <= 3u) {
            if (index < pParam->getElementSlot()) {
                return pParam->mCraftParam.getElementItemNo(index);
            }
        }
    }
    return 0;
}

__attribute__((weak)) f32 cGUIUtility::getCrestIconFrame(rItemList::rItemParam* pItemParam) {
    DDON_STUB("cGUIUtility::getCrestIconFrame")
    return {};
}

__attribute__((weak)) f32 cGUIUtility::getCrestIconFrame(u32 item_id) {
    DDON_STUB("cGUIUtility::getCrestIconFrame")
    return {};
}

__attribute__((weak)) const MtColor& cGUIUtility::getColorFromCraftColorNo(u32 color_no) {
    DDON_STUB("cGUIUtility::getColorFromCraftColorNo")
    __builtin_unreachable();
}

bool cGUIUtility::isEnableEquipIcon(u32 SlotNo, u32 JobId, u32 EquipJewelryNum) {
    if ((SlotNo - 10u) <= 4u) {
        if ((SlotNo - 10u) != 0) {
            if ((SlotNo - 10u) >= EquipJewelryNum) {
                return false;
            }
        }
        return true;
    } else {
        if ((SlotNo - 17u) <= 1u) {
            if (JobId != 3) {
                if (JobId == 9) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        } else {
            return true;
        }
    }
}

__attribute__((weak)) s32 cGUIUtility::getPhysicalTypeFixFrame(const cEquipData& equipData, bool isMain) {
    DDON_STUB("cGUIUtility::getPhysicalTypeFixFrame")
    return {};
}

__attribute__((weak)) s32 cGUIUtility::getElementTypeFixFrame(const cEquipData& equipData, bool isMain) {
    DDON_STUB("cGUIUtility::getElementTypeFixFrame")
    return {};
}

__attribute__((weak)) f32 cGUIUtility::getQuestFrame(nQuest::QUEST_TYPE quest_type) {
    DDON_STUB("cGUIUtility::getQuestFrame")
    return {};
}

void cGUIUtility::copyParameter(cGUIInstance* pDest, cGUIInstance* pOrg, s32 flag) {
    if (pOrg == nullptr) {
        return;
    }
    if (pDest == nullptr) {
        return;
    }
    cGUIUtility::copyParameterlValueSet(pDest, pOrg, flag);
    cGUIUtility::copyParameterLoop(pDest->getChild(), pOrg->getChild(), flag);
}

bool cGUIUtility::isEquipLantern() {
    if (sPlayerManager::getInstance()->getMyPlayer() != nullptr) {
        return cContextInterface::getContextEquip(sPlayerManager::getInstance()->getMyPlayer()->mContextInterface.mpContextInstance).getEquip(static_cast<u8>(15), static_cast<u8>(0), true) != 0;
    } else {
        return false;
    }
}

__attribute__((weak)) void cGUIUtility::convertNormalSkillList(const cContextPlayerInfo* pPlinfo, nHuman::JOB_ENUM JobId, nGUIExt::stNormalSkill(&OutBuff)[20]) {
    DDON_STUB("cGUIUtility::convertNormalSkillList")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::convertNormalSkillLearnList(const NormalSkillParamVec& LearnedList, nHuman::JOB_ENUM JobId, nGUIExt::stLearnNormalSkill(&OutBuff)[20]) {
    DDON_STUB("cGUIUtility::convertNormalSkillLearnList")
    /* stub */
}

const rAcquirement::cNormalSkillData* cGUIUtility::getNormalSkillData(nHuman::JOB_ENUM JobId, u32 SkillNo) {
    cAcquirement::cNormalSkillData* pskill = static_cast<sGUIExt*>(sGUI::getInstance())->getNormalSkillData(static_cast<u32>(JobId));
    if (pskill != nullptr) {
        return pskill->getData(SkillNo);
    } else {
        return nullptr;
    }
}

void cGUIUtility::setGUIUnitEnable(uGUIBase* pBase, bool b) {
    if (pBase == nullptr) {
        return;
    }
    unsigned int t0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pBase) + 16);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pBase) + 16) = !b ? ((!b ? (t0 & 0xFFFFFBFFu) : (t0 | 1024u)) & 0xFFFFBFFFu) : ((!b ? (t0 & 0xFFFFFBFFu) : (t0 | 1024u)) | 16384u);
    if (((!b ? (t0 & 0xFFFFFBFFu) : (t0 | 1024u)) & 18439u) != 18434) {
        return;
    }
    if (((!b ? ((!b ? (t0 & 0xFFFFFBFFu) : (t0 | 1024u)) & 0xFFFFBFFFu) : ((!b ? (t0 & 0xFFFFFBFFu) : (t0 | 1024u)) | 16384u)) & 18439u) == 18434) {
        return;
    }
    pBase->callbackChangeVisibleTrueToFalse();
}

__attribute__((weak)) void cGUIUtility::setExecuteTree(cGUIInstance* p, bool b) {
    DDON_STUB("cGUIUtility::setExecuteTree")
    /* stub */
}

f32 cGUIUtility::getPosY(const cGUIObj2D* p) {
    return p->mPosition.y;
}

__attribute__((weak)) void cGUIUtility::setCurrentFrameTree(cGUIObject* pObj, f32 frame, bool fix) {
    DDON_STUB("cGUIUtility::setCurrentFrameTree")
    /* stub */
}

void cGUIUtility::setCurrentFrameTree(cGUIInstAnimation* pInstAnim, f32 frame, bool fix) {
    if (pInstAnim != nullptr) {
        if (pInstAnim->getRootObject() != nullptr) {
            for (cGUIObject* child = pInstAnim->getRootObject();;) {
                cGUIUtility::setCurrentFrameTree(child, frame, fix);
                if (child->getNext() != nullptr) {
                    child = child->getNext();
                } else {
                    break;
                }
            }
        }
    }
}

void cGUIUtility::setColor(cGUIObjPolygon* pObj, const MtColor& color) {
    if (pObj == nullptr) {
        return;
    }
    pObj->setColor(color, 0u);
    pObj->setColor(color, 1u);
    pObj->setColor(color, 2u);
    pObj->setColor(color, 3u);
}

__attribute__((weak)) void cGUIUtility::addChildUnit(uGUIBase* pParent, uGUIBase* pChild) {
    DDON_STUB("cGUIUtility::addChildUnit")
    /* stub */
}

MT_CTSTR cGUIUtility::GetStageName(s32 stageNo) {
    if (sArea::getInstance() != nullptr) {
        const u32 stage_msg_id = static_cast<sAreaExt*>(sArea::getInstance())->getStageMsgId(stageNo);
        return static_cast<sGUIExt*>(sGUI::getInstance())->getStageName(stage_msg_id);
    } else {
        return "";
    }
}

__attribute__((weak)) MT_CTSTR cGUIUtility::GetSpotName(s32 spotId) {
    DDON_STUB("cGUIUtility::GetSpotName")
    return {};
}

__attribute__((weak)) MT_CTSTR cGUIUtility::GetMsgFromIndexName(const rGUIMessage* pGmd, MT_CTSTR index_seed, u32 id) {
    DDON_STUB("cGUIUtility::GetMsgFromIndexName")
    return {};
}

__attribute__((weak)) MT_CTSTR cGUIUtility::GetOmMapIconName(u32 omMapIcon) {
    DDON_STUB("cGUIUtility::GetOmMapIconName")
    return {};
}

__attribute__((weak)) MT_CTSTR cGUIUtility::GetOmFuncClassName(u32 omId) {
    DDON_STUB("cGUIUtility::GetOmFuncClassName")
    return {};
}

__attribute__((weak)) MT_CTSTR cGUIUtility::GetOcdName(u32 ocdId) {
    DDON_STUB("cGUIUtility::GetOcdName")
    return {};
}

MT_CTSTR cGUIUtility::getPawnStatusStr(uGUIBase* pGUI, u32 status) {
    static const u32 pawn_status_msg_ids[7] = {
        1,
        2,
        3,
        4,
        4,
        0,
        1,
    };
    if (pGUI != nullptr) {
        if (status <= 6u) {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgPawnStatus(), pawn_status_msg_ids[status]);
        }
    }
    return "";
}

MT_CTSTR cGUIUtility::getPawnShareRangeStr(uGUIBase* pGUI, u32 shareRange) {
    static const u32 pawn_share_range_msg_ids[6] = {
        0,
        0,
        1,
        2,
        3,
        4,
    };
    if (pGUI != nullptr) {
        if (shareRange != 0) {
            if (shareRange <= 5u) {
                return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgPawnShareRange(), pawn_share_range_msg_ids[shareRange]);
            }
        }
    }
    return "";
}

MT_CTSTR cGUIUtility::getWeightRankMsg(rGUIMessage* pMsgData, u32 rank) {
    static const u32 weight_msg[6] = {
        3,
        4,
        5,
        6,
        7,
        8,
    };
    if (rank <= 5u) {
        return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pMsgData, weight_msg[rank]);
    } else {
        return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pMsgData, 8u);
    }
}

MT_CTSTR cGUIUtility::GetPawnPersonalityStr(uGUIBase* pGUI, u32 pawnPersonality) {
    static const u32 pawn_personality_msg_ids[9] = {
        0,
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
    };
    if (pGUI != nullptr) {
        if (pawnPersonality != 0) {
            if (pawnPersonality <= 8u) {
                return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgPawnPersonality(), pawn_personality_msg_ids[pawnPersonality]);
            }
        }
    }
    return "";
}

__attribute__((weak)) MT_CTSTR cGUIUtility::getPlayPurposeMainStr(uGUIBase* pGUI, u32 index) {
    DDON_STUB("cGUIUtility::getPlayPurposeMainStr")
    return {};
}

MT_CTSTR cGUIUtility::getPlayPurposeSubStr(uGUIBase* pGUI, u32 index) {
    static const u32 mPlayPurposeSubName[13] = {
        11,
        12,
        13,
        14,
        15,
        16,
        17,
        18,
        19,
        20,
        21,
        22,
        0,
    };
    if (index != 0) {
        if (index <= 12u) {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgPlayStyleItem(), mPlayPurposeSubName[index - 1u]);
        }
    }
    return "";
}

MT_CTSTR cGUIUtility::getPlayStyleStr(uGUIBase* pGUI, u32 index) {
    static const u32 mPlayStyleName[29] = {
        23,
        24,
        25,
        26,
        27,
        28,
        29,
        30,
        31,
        32,
        33,
        34,
        35,
        36,
        37,
        38,
        39,
        40,
        41,
        42,
        43,
        44,
        45,
        46,
        47,
        48,
        49,
        50,
        0,
    };
    if (index != 0) {
        if (index <= 28u) {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgPlayStyleItem(), mPlayStyleName[index - 1u]);
        }
    }
    return "";
}

MT_CTSTR cGUIUtility::getClanMottoStr(uGUIBase* pGUI, u32 index) {
    static const u32 mClanMottoName[7] = {
        0,
        1,
        2,
        3,
        4,
        5,
        0,
    };
    if (index != 0) {
        if (index <= 6u) {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgClanProfileItem(), mClanMottoName[index - 1u]);
        }
    }
    return "";
}

MT_CTSTR cGUIUtility::getClanDayStr(uGUIBase* pGUI, u32 index) {
    static const u32 mClanDayName[5] = {
        10,
        11,
        12,
        13,
        0,
    };
    if (index != 0) {
        if (index <= 4u) {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgClanProfileItem(), mClanDayName[index - 1u]);
        }
    }
    return "";
}

MT_CTSTR cGUIUtility::getClanHourStr(uGUIBase* pGUI, u32 index) {
    static const u32 mClanHourName[5] = {
        14,
        15,
        16,
        17,
        0,
    };
    if (index != 0) {
        if (index <= 4u) {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgClanProfileItem(), mClanHourName[index - 1u]);
        }
    }
    return "";
}

MT_CTSTR cGUIUtility::getClanFeatureStr(uGUIBase* pGUI, u32 index) {
    static const u32 mClanFeatureName[23] = {
        18,
        19,
        20,
        21,
        22,
        23,
        24,
        25,
        26,
        27,
        28,
        29,
        30,
        31,
        32,
        33,
        34,
        35,
        36,
        37,
        38,
        39,
        0,
    };
    if (index != 0) {
        if (index <= 22u) {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGUI->getMsgClanProfileItem(), mClanFeatureName[index - 1u]);
        }
    }
    return "";
}

f32 cGUIUtility::getClanRankAnimFrame(u32 Rank) {
    static const f32 rank_frames[5] = {
        0x0p+0f,
        0x1p+0f,
        0x1p+1f,
        0x0p+0f,
        0x0p+0f,
    };
    if (Rank <= 4u) {
        return rank_frames[Rank];
    } else {
        return 0.0f;
    }
}

__attribute__((weak)) MT_CTSTR cGUIUtility::GetChargeCourseName(u32 courseId) {
    DDON_STUB("cGUIUtility::GetChargeCourseName")
    return {};
}

__attribute__((weak)) void cGUIUtility::GetChargeEffectMessage(MtString& ret_str, u32 effect, bool isAdd) {
    DDON_STUB("cGUIUtility::GetChargeEffectMessage")
    /* stub */
}

bool cGUIUtility::IsChargeAttributeEnable(u32 attr) {
    if (!sGame::getInstance()->mCharData.mCharData.mOption.mIsDispCharges) {
        return false;
    }
    if (attr == 0) {
        return false;
    }
    unsigned int i3 = 0;
    do {
        if (sGame::getInstance()->isChargeEffectAttr(static_cast<nGpCourse::E_GP_COURSE_EFFECT>(i3), attr)) {
            if (sGame::getInstance()->isChargeEffect(static_cast<nGpCourse::E_GP_COURSE_EFFECT>(i3))) {
                return true;
            }
        }
        i3 += 1u;
    } while (i3 <= 50u);
    return false;
}

__attribute__((weak)) void cGUIUtility::GetChargeEffectFromAttribute(MtString& ret_str, u32 attr) {
    DDON_STUB("cGUIUtility::GetChargeEffectFromAttribute")
    /* stub */
}

MT_CTSTR cGUIUtility::getEquipPartsName(rGUIMessage* pGMDRes, u32 Slot) {
    static const u32 equip_slot_gmdid_tbl[17] = {
        142,
        144,
        145,
        147,
        148,
        146,
        149,
        150,
        213,
        143,
        108,
        108,
        151,
        151,
        151,
        151,
        151,
    };
    if (Slot > 16u) {
        return "";
    } else {
        return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, equip_slot_gmdid_tbl[Slot]);
    }
}

MT_CTSTR cGUIUtility::getEquipPartsNameFromCategory(rGUIMessage* pGMDRes, u32 category) {
    switch (category - 1u) {
        case 0:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 142u);
        }
        case 1:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 143u);
        }
        case 2:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 144u);
        }
        case 3:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 145u);
        }
        case 4:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 146u);
        }
        case 5:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 147u);
        }
        case 6:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 148u);
        }
        case 7:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 149u);
        }
        case 8:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 150u);
        }
        case 9:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 151u);
        }
        case 10:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 213u);
        }
        case 11:
        {
            return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, 152u);
        }
        default:
        {
            return "";
        }
    }
}

__attribute__((weak)) void cGUIUtility::getCustomSkillIconTagForTrgBtn(nGUIExt::StringKeyCustomIconTag& outIconTag, nGUIExt::CUSTOM_SKILL_PALLET PalletId) {
    DDON_STUB("cGUIUtility::getCustomSkillIconTagForTrgBtn")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getCustomSkillIconTagForBtn(nGUIExt::StringKeyCustomIconTag& outIconTag, nGUIExt::CUSTOM_SKILL_PALLET PalletId) {
    DDON_STUB("cGUIUtility::getCustomSkillIconTagForBtn")
    /* stub */
}

__attribute__((weak)) MT_CTSTR cGUIUtility::getIconRCFromBtn(sPadExt::PAD_BTN_TYPE btn, bool bKeyAll) {
    DDON_STUB("cGUIUtility::getIconRCFromBtn")
    return {};
}

MT_CTSTR cGUIUtility::getIconRCFromKB(sKeyboard::KB_TYPE key) {
    if (key == sKeyboard::KB_PRIOR) {
        return "w";
    } else {
        if (key == sKeyboard::KB_NEXT) {
            return "z";
        } else {
            return "";
        }
    }
}

__attribute__((weak)) MT_CTSTR cGUIUtility::getRawPadIconTag(u32 pad) {
    DDON_STUB("cGUIUtility::getRawPadIconTag")
    return {};
}

__attribute__((weak)) MT_CTSTR cGUIUtility::getRawKeyIconTag(u32 key) {
    DDON_STUB("cGUIUtility::getRawKeyIconTag")
    return {};
}

MT_CTSTR cGUIUtility::getRawMouseIconTag(u32 mouse) {
    if (static_cast<int>(mouse) <= 12287) {
        if (static_cast<int>(mouse) <= 8191) {
            if (static_cast<int>(mouse) <= 4095) {
                if (mouse != 1) {
                    if (mouse == 2) {
                        return "<ICON MOUSE_CL_R>";
                    } else {
                        if (mouse == 4) {
                            return "<ICON MOUSE_WHL_1>";
                        } else {
                            return "";
                        }
                    }
                } else {
                    return "<ICON MOUSE_CL_L>";
                }
            } else {
                if (mouse == 4096) {
                    return "<ICON MOUSE_WHL_2>";
                } else {
                    return "";
                }
            }
        } else {
            if (mouse == 8192) {
                return "<ICON MOUSE_WHL_3>";
            } else {
                return "";
            }
        }
    } else {
        if (mouse == 12288) {
            return "<ICON MOUSE_WHL_4>";
        } else {
            return "";
        }
    }
}

__attribute__((weak)) void cGUIUtility::getPadIconTag(nGUIExt::StringKeyCustomIconTag* outBaseIconTag, nGUIExt::StringKeyCustomIconTag* outModifierIconTag, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlankTag, bool isModifierBlankTag) {
    DDON_STUB("cGUIUtility::getPadIconTag")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getKeyIconTag(nGUIExt::StringKeyCustomIconTag* outBaseIconTag, nGUIExt::StringKeyCustomIconTag* outModifierIconTag, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlankTag, bool isModifierBlankTag) {
    DDON_STUB("cGUIUtility::getKeyIconTag")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::joinIconTag(nGUIExt::StringKeyCustomIconTag& outIconTag, MT_CTSTR baseIconTag, MT_CTSTR modifierIconTag, cGUIUtility::ICON_TAG_JOINT_TYPE jointType, bool isInvert) {
    DDON_STUB("cGUIUtility::joinIconTag")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getPadIconTag(nGUIExt::StringKeyCustomIconTag& outIconTag, nKeyCustom::KB_CUSTOM keyCustom, cGUIUtility::ICON_TAG_OUT_TYPE outType, cGUIUtility::ICON_TAG_JOINT_TYPE jointType, u32 flags) {
    DDON_STUB("cGUIUtility::getPadIconTag")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getKeyIconTag(nGUIExt::StringKeyCustomIconTag& outIconTag, nKeyCustom::KB_CUSTOM keyCustom, cGUIUtility::ICON_TAG_OUT_TYPE outType, cGUIUtility::ICON_TAG_JOINT_TYPE jointType, u32 flags) {
    DDON_STUB("cGUIUtility::getKeyIconTag")
    /* stub */
}

void cGUIUtility::getIconTag(nGUIExt::StringKeyCustomIconTag& outIconTag, nKeyCustom::KB_CUSTOM keyCustom, cGUIUtility::ICON_TAG_OUT_TYPE outType, cGUIUtility::ICON_TAG_JOINT_TYPE jointType, u32 flags) {
    if (static_cast<sSavedataExt*>(sSavedata::getInstance())->getStorageData().mOptionSys.mActPltType == 1) {
        cGUIUtility::getKeyIconTag(outIconTag, keyCustom, outType, jointType, flags);
    } else {
        cGUIUtility::getPadIconTag(outIconTag, keyCustom, outType, jointType, flags);
    }
}

__attribute__((weak)) void cGUIUtility::getRawPadText(nGUIExt::StringKeyName& keyName, u32 pad) {
    DDON_STUB("cGUIUtility::getRawPadText")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getRawKeyText(nGUIExt::StringKeyName& keyName, u32 key) {
    DDON_STUB("cGUIUtility::getRawKeyText")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getPadText(nGUIExt::StringKeyName* outBaseText, nGUIExt::StringKeyName* outModifierText, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlank, bool isModifierBlank) {
    DDON_STUB("cGUIUtility::getPadText")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getKeyText(nGUIExt::StringKeyName* outBaseText, nGUIExt::StringKeyName* outModifierText, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlank, bool isModifierBlank) {
    DDON_STUB("cGUIUtility::getKeyText")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::joinKeyCustomText(nGUIExt::StringKeyName& outText, MT_CTSTR baseText, MT_CTSTR modifierText, cGUIUtility::ICON_TAG_JOINT_TYPE jointType, bool isInvert) {
    DDON_STUB("cGUIUtility::joinKeyCustomText")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getPadText(nGUIExt::StringKeyName& outText, nKeyCustom::KB_CUSTOM keyCustom, cGUIUtility::ICON_TAG_OUT_TYPE outType, cGUIUtility::ICON_TAG_JOINT_TYPE jointType, u32 flags) {
    DDON_STUB("cGUIUtility::getPadText")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::getKeyText(nGUIExt::StringKeyName& outText, nKeyCustom::KB_CUSTOM keyCustom, cGUIUtility::ICON_TAG_OUT_TYPE outType, cGUIUtility::ICON_TAG_JOINT_TYPE jointType, u32 flags) {
    DDON_STUB("cGUIUtility::getKeyText")
    /* stub */
}

s32 cGUIUtility::GetJobParamNum() {
    return 10;
}

const nGUIExt::JobParam* cGUIUtility::GetJobParam(s32 dispIndex) {
    if (dispIndex > -1) {
        if (static_cast<unsigned int>(dispIndex) <= 9) {
            return &JobParams[dispIndex];
        }
    }
    return nullptr;
}

const nGUIExt::JobParam* cGUIUtility::GetJobParamFromJobId(u32 jobId) {
    const nGUIExt::JobParam* p0_1 = JobParams;
    unsigned int i0_2 = 0;
    const nGUIExt::JobParam* v1_0;
    for (;;) {
        if (static_cast<unsigned int>(p0_1->mJobId) == jobId) {
            v1_0 = p0_1;
            break;
        } else {
            if ((i0_2 + 1u) <= 9u) {
                p0_1 += 1;
                i0_2 += 1u;
            } else {
                v1_0 = nullptr;
                break;
            }
        }
    }
    return v1_0;
}

s32 cGUIUtility::GetValidJobNum() {
    return 10;
}

nHuman::JOB_ENUM cGUIUtility::GetValidJobId(s32 dispIndex) {
    if (dispIndex > -1) {
        if (static_cast<unsigned int>(dispIndex) <= 9) {
            return JobParams[dispIndex].mJobId;
        }
    }
    return nHuman::JOB_ID_NONE;
}

s32 cGUIUtility::GetValidJobIndex(nHuman::JOB_ENUM jobId) {
    unsigned int i1 = 0;
    const nGUIExt::JobParam* p2 = JobParams;
    do {
        if (p2->mJobId == jobId) {
            return static_cast<s32>(i1);
        }
        i1 += 1u;
        p2 += static_cast<int>(1);
    } while (i1 <= 9u);
    return -1;
}

MT_CTSTR cGUIUtility::GetJobInfoMsg(rGUIMessage* pGMDRes, u32 jobId) {
    unsigned int i0_0 = 0;
    for (const nGUIExt::JobParam* p0_1 = JobParams; i0_0 <= 9u; i0_0 = i0_0 + 1u, p0_1 += 1) {
        if (static_cast<unsigned int>(p0_1->mJobId) == jobId) {
            if (p0_1 != nullptr) {
                return static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(pGMDRes, JobParams[i0_0].mJobInfoMsgId);
            } else {
                return "";
            }
        }
    }
    return "";
}

const CJobChangeInfo* cGUIUtility::GetJobChangeInfo(const JobChangeInfoVec& jobChangeList, s32 dispIndex) {
    if (dispIndex > -1) {
        if (static_cast<unsigned int>(dispIndex) <= 9) {
            if (jobChangeList.size() == 0) {
                return nullptr;
            }
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
    u32 i = 0;
    do {
        if (jobChangeList.mpArray[i] != nullptr) {
            if (static_cast<unsigned int>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(jobChangeList.mpArray[i]) + 8)) == static_cast<unsigned int>(JobParams[dispIndex].mJobId)) {
                return static_cast<const CJobChangeInfo*>(jobChangeList.mpArray[i]);
            }
        }
        i += 1u;
    } while (i < jobChangeList.size());
    return nullptr;
}

__attribute__((weak)) void cGUIUtility::setupGradeIcon(cGUIInstAnimation* (&grade_icon)[4], rItemList::rItemParam* pItemParam) {
    DDON_STUB("cGUIUtility::setupGradeIcon")
    /* stub */
}

__attribute__((weak)) u32 cGUIUtility::getPlayerTotalJobLevel() {
    DDON_STUB("cGUIUtility::getPlayerTotalJobLevel")
    return {};
}

__attribute__((weak)) u32 cGUIUtility::getMyPawnTotalJobLevel(u32 PawnId) {
    DDON_STUB("cGUIUtility::getMyPawnTotalJobLevel")
    return {};
}

bool cGUIUtility::IsDirectChat() {
    if (sSavedata::getInstance() != nullptr) {
        cStorageData& t0 = static_cast<sSavedataExt*>(sSavedata::getInstance())->getStorageData();
        if (t0.mOptionSys.mActPltType != 0) {
            return false;
        } else {
            return t0.mOptionSys.mIsDirectChat;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) s32 cGUIUtility::CalcPageNum(s32 itemNum, s32 itemNumPerPage) {
        s32 page_num = 1;
        if (itemNum > 0 && itemNumPerPage > 0) {
            if (itemNumPerPage == 1) {
                return itemNum;
            }
            page_num = (itemNum + itemNumPerPage - 1) / itemNumPerPage;
        }
        return page_num;
}

__attribute__((weak)) s32 cGUIUtility::CalcDispNum(s32 itemNum, s32 itemNumPerPage, s32 pageIndex) {
    DDON_STUB("cGUIUtility::CalcDispNum")
    return {};
}

__attribute__((weak)) void cGUIUtility::GetHeadUiInfo(nGUIExt::HeadUiInfo& headUiInfo, nGUIExt::HEAD_UI_TYPE headUiType) {
    DDON_STUB("cGUIUtility::GetHeadUiInfo")
    /* stub */
}

__attribute__((weak)) f32 cGUIUtility::CalcHeadUiAlpha(const nGUIExt::HeadUiInfo& headUiInfo, const MtVector3& targetPos, const MtVector3& uiPos, uPlayer* player, f32 sizeRate) {
    DDON_STUB("cGUIUtility::CalcHeadUiAlpha")
    return {};
}

bool cGUIUtility::IsPartyEntry(const cContextInstHm* contextInstHm) {
    sGame* t0 = sGame::getInstance();
    s32 t1 = cContextInterface::getMemberIndex(contextInstHm);
    if (t1 > -1) {
        if (t0->isParty(t1)) {
            cNetGameServer* t2 = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer();
            if (t2->isPlayEntry(cContextInterface::getMemberIndex(contextInstHm))) {
                bool t3 = sQuestManagerExt::getInstance()->isCycleContentsPlayNow();
                return !t3;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) f32 cGUIUtility::GetCurseHpRate(const uCharacter* character) {
    DDON_STUB("cGUIUtility::GetCurseHpRate")
    return {};
}

void cGUIUtility::SetCurseGaugeObj(cGUIObject* curseGaugeObj, f32 hpRate) {
    if (curseGaugeObj == nullptr) {
        return;
    }
    curseGaugeObj->setVisible(1.0f > hpRate);
}

bool cGUIUtility::IsValidOcdId(u32 ocdId) {
    return uGUIBase::cReferenceUIIconStatus::GetIconFrameFromOcdId(ocdId) > 0.0f;
}

bool cGUIUtility::IsValidAccumulationOcdId(u32 ocdId) {
    if ((ocdId - 4097u) <= 30u) {
        return ((0x5FF07F7ul >> static_cast<unsigned long>((ocdId - 4097u) & 63u)) & 1ul) != 0;
    } else {
        return false;
    }
}

u32 cGUIUtility::GetDispOcdId(u32 ocdId) {
    if (ocdId == 27) {
        return 19;
    } else {
        if (ocdId == 13) {
            return 18;
        } else {
            return ocdId;
        }
    }
}

__attribute__((weak)) u32 cGUIUtility::UpdateOcdIcon(nGUIExt::OcdIconInterface& ocdIconInterface, f32 deltaTime) {
    DDON_STUB("cGUIUtility::UpdateOcdIcon")
    return {};
}

__attribute__((weak)) nGUIExt::DAMAGE_UI_MODEL_TYPE cGUIUtility::GetDamageUiModelType(uDDOModel* model) {
    DDON_STUB("cGUIUtility::GetDamageUiModelType")
    return {};
}

__attribute__((weak)) uDDOModel* cGUIUtility::GetDamageUiAttackerModel(cHitInfoAfter& hitInfo) {
    DDON_STUB("cGUIUtility::GetDamageUiAttackerModel")
    return nullptr;
}

__attribute__((weak)) bool cGUIUtility::GetJobItemEquipInfo(cGUIUtility::stJobItemEquipInfo& jobItemEquipInfo, uHuman* human, nCharacterData::ARROW_EQUIP arrowEquip) {
    DDON_STUB("cGUIUtility::GetJobItemEquipInfo")
    return {};
}

__attribute__((weak)) bool cGUIUtility::IsItemEnableSeal(const rItemList::rItemParam* itemParam) {
    DDON_STUB("cGUIUtility::IsItemEnableSeal")
    return {};
}

__attribute__((weak)) MT_CTSTR cGUIUtility::GetPawnFeedbackComment(uGUIBase* pGUI, u8 feedbackType, u8 starNum, u8 commentNo) {
    DDON_STUB("cGUIUtility::GetPawnFeedbackComment")
    return {};
}

__attribute__((weak)) uGUISystemMsg* cGUIUtility::reqDialog(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4, bool isChatSubMenu) {
    DDON_STUB("cGUIUtility::reqDialog")
    return nullptr;
}

uGUISystemMsg* cGUIUtility::reqDialog(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, bool isCancelOff, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4, bool isChatSubMenu) {
    uGUISystemMsg* pGUI = cGUIUtility::reqDialog(dialogType, mainMsg, defPos, choice1, choice2, choice3, choice4, isChatSubMenu);
    if (pGUI != nullptr) {
        pGUI->mIsCancelChoiseOff = isCancelOff;
    }
    return pGUI;
}

__attribute__((weak)) uGUISystemMsg* cGUIUtility::createPawnSelectDialog(MT_CTSTR title, u32 select_pawn_id) {
    DDON_STUB("cGUIUtility::createPawnSelectDialog")
    return nullptr;
}

__attribute__((weak)) uGUIPopCmd01* cGUIUtility::createPopCmd01(MOVE_LINE moveLine, u32 pointerPriority, u64 unitGroup, bool isChatSubMenu, bool isSingleton) {
    DDON_STUB("cGUIUtility::createPopCmd01")
    return nullptr;
}

__attribute__((weak)) u64 cGUIUtility::getPastTime(u64 time) {
    DDON_STUB("cGUIUtility::getPastTime")
    return {};
}

__attribute__((weak)) u64 cGUIUtility::getFutureTime(u64 time) {
    DDON_STUB("cGUIUtility::getFutureTime")
    return {};
}

__attribute__((weak)) void cGUIUtility::setURL(MtString& Str, u32 Type, MT_CTSTR pAddStr) {
    DDON_STUB("cGUIUtility::setURL")
    /* stub */
}

__attribute__((weak)) void cGUIUtility::setItemAddURL(MtString& Str, u32 Type, u32 LineupID, u32 ItemID) {
    DDON_STUB("cGUIUtility::setItemAddURL")
    /* stub */
}

__attribute__((weak)) bool cGUIUtility::replaceNGWord(MtString& DestStr, MT_CTSTR pSrcStr, u32 Length) {
    DDON_STUB("cGUIUtility::replaceNGWord")
    return {};
}

bool cGUIUtility::replaceNGWord(MtString& DestStr, const MtString& SrcStr) {
    if (SrcStr.value != nullptr) {
        return cGUIUtility::replaceNGWord(DestStr, SrcStr.ptr(), SrcStr.value->length);
    } else {
        return cGUIUtility::replaceNGWord(DestStr, SrcStr.ptr(), 0u);
    }
}

u32 cGUIUtility::getCaplinkFriendAttrMsgIndex(u32 attr) {
    static const u32 msg_index[4] = {
        79,
        76,
        77,
        78,
    };
    if (attr <= 3u) {
        return msg_index[attr];
    } else {
        return 76;
    }
}

__attribute__((weak)) bool cGUIUtility::copyParameterlValueSet(cGUIInstance* pDest, cGUIInstance* pOrg, s32 flag) {
    if (pOrg != nullptr) {
        if (pDest != nullptr) {
            if (pDest->getDuplicateId() == pOrg->mId) {
                pDest->setExecute(static_cast<bool>((pOrg->mAttr & 8u) >> 3));
                if (pDest->getDTI().getID() == cGUIInstAnimation::DTI.mID) {
                    if ((flag & 1) != 0) {
                        static_cast<cGUIInstAnimation*>(pDest)->setSequenceId(static_cast<cGUIInstAnimation*>(pOrg)->getSequenceId());
                    }
                    if ((flag & 2) != 0) {
                        static_cast<cGUIInstNull*>(pDest)->setPositionX(static_cast<cGUIInstNull*>(pOrg)->mPosition.x);
                    }
                    if ((flag & 4) != 0) {
                        static_cast<cGUIInstNull*>(pDest)->setPositionY(static_cast<cGUIInstNull*>(pOrg)->mPosition.y);
                    }
                    if ((flag & 8) != 0) {
                        static_cast<cGUIInstNull*>(pDest)->setPosition(static_cast<cGUIInstNull*>(pOrg)->mPosition);
                    }
                } else {
                    if (pDest->getDTI().getID() == cGUIInstNull::DTI.mID) {
                        if ((flag & 2) != 0) {
                            static_cast<cGUIInstNull*>(pDest)->setPositionX(static_cast<cGUIInstNull*>(pOrg)->mPosition.x);
                        }
                        if ((flag & 4) != 0) {
                            static_cast<cGUIInstNull*>(pDest)->setPositionY(static_cast<cGUIInstNull*>(pOrg)->mPosition.y);
                        }
                        if ((flag & 8) != 0) {
                            static_cast<cGUIInstNull*>(pDest)->setPosition(static_cast<cGUIInstNull*>(pOrg)->mPosition);
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}

__attribute__((weak)) bool cGUIUtility::copyParameterCheck(cGUIInstance* pDest, cGUIInstance* pOrg, s32 flag) {
    DDON_STUB("cGUIUtility::copyParameterCheck")
    return {};
}

__attribute__((weak)) bool cGUIUtility::copyParameterLoop(cGUIInstance* pDest, cGUIInstance* pOrg, s32 flag) {
    bool b0_0;
    if (pOrg != nullptr) {
        b0_0 = false;
        for (cGUIInstance* v0_3 = pDest;;) {
            if (v0_3 == nullptr) {
                break;
            } else {
                cGUIUtility::copyParameterCheck(v0_3, pOrg, flag);
                cGUIUtility::copyParameterLoop(v0_3->getChild(), pOrg, flag);
                b0_0 = true;
                v0_3 = v0_3->getNext();
            }
        }
    } else {
        b0_0 = false;
    }
    return b0_0;
}

