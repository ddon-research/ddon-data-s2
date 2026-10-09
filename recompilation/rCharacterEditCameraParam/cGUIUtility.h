#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtString.h"
#include "../shared/nCharacterData.h"
#include "../shared/nGUIExt.h"
#include "../shared/nHuman.h"
#include "../shared/nKeyCustom.h"
#include "../shared/nQuest.h"
#include "../shared/rItemList.h"
#include "../shared/sItemManager.h"
#include "sKeyboard.h"
#include "../shared/sPadExt.h"
#include "../shared/sUnit.h"

// Forward declarations
class CDataCharacterName;
class CDataJobChangeInfo;
class CDataNormalSkillParam;
class MtColor;
class MtString;
class MtTime;
class MtVector2;
class MtVector3;
class MtVector4;
class cContextInstHm;
class cContextPlayerInfo;
class cEquipData;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObj2D;
class cGUIObjChildAnimationRoot;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObject;
class cHitInfoAfter;
class cItemParam;
class cUnit;
namespace nGUIExt { struct HeadUiInfo; }
namespace nGUIExt { struct JobParam; }
namespace nGUIExt { class OcdIconInterface; }
namespace nGUIExt { struct stLearnNormalSkill; }
namespace nGUIExt { struct stNormalSkill; }
namespace rAcquirement { class cNormalSkillData; }
class rGUIMessage;
class uCharacter;
class uCoord;
class uDDOModel;
class uGUIBase;
class uGUIPopCmd01;
class uGUISystemMsg;
class uHuman;
class uPlayer;

// Declarations
class cGUIUtility;

// Type aliases from DWARF
using CCharacterName = CDataCharacterName;
using CJobChangeInfo = CDataJobChangeInfo;
using JobChangeInfoVec = MtTypedArray<CDataJobChangeInfo>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using NormalSkillParamVec = MtTypedArray<CDataNormalSkillParam>;
using __uint64_t = long unsigned int;
using f32 = float;
namespace nGUIExt { using StringItemCategoryName = MtStringEx<128>; }
namespace nGUIExt { using StringKeyCustomIconTag = MtStringEx<128>; }
namespace nGUIExt { using StringKeyName = MtStringEx<128>; }
using s32 = int;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cGUIUtility
{
public:
    enum ICON_TAG_JOINT_TYPE
    {
        ICON_TAG_JOINT_TYPE_NONE = 0,
        ICON_TAG_JOINT_TYPE_PLUS = 1,
    };
    enum ICON_TAG_OUT_TYPE
    {
        ICON_TAG_OUT_TYPE_ALL = 0,
        ICON_TAG_OUT_TYPE_BASE = 1,
        ICON_TAG_OUT_TYPE_MODIFIER = 2,
    };
    enum
    {
        MTSTYPE_BIT_YEAR = 32,
        MTSTYPE_BIT_MONTH = 16,
        MTSTYPE_BIT_DAY = 8,
        MTSTYPE_BIT_HOUR = 4,
        MTSTYPE_BIT_MINUTE = 2,
        MTSTYPE_BIT_SEC = 1,
    };
    enum
    {
        MTSTYPE_ALL = 62,
        MTSTYPE_MONTH = 30,
        MTSTYPE_DAY = 14,
        MTSTYPE_HOUR = 6,
        MTSTYPE_MINUTE = 2,
        MTSTYPE_DATE = 56,
    };
public:
    struct stJobItemEquipInfo;
public:
    struct stJobItemEquipInfo
    {
    public:
        rItemList::rItemParam* param;  // offset: 0x0
        u32 num;  // offset: 0x8
        u32 dispNum;  // offset: 0xc
    };
public:
    static void makeDateString(u64 time, MtString& rStr);
    static void makeDateString(MtTime& rTime, MtString& rStr);
    static void makeDateTimeString(u64 time, MtString& rStr, u8 uType);
    static void makeDateTimeString(MtTime& rTime, MtString& rStr, u8 uType);
    static void makeMinuteAndSecondString(s32 frame, MtString& rStr);
    static void makeTimeUnitString(MtStringEx<32>& rStr, u64 seconds, bool isRoundUp);
    static void makePastTime(u64 time, MtString& rStr);
    static void makeFutureTimeAfter(u64 time, MtString& rStr);
    static void makeFutureTimeLimit(u64 time, MtString& rStr);
    static void makeNumberString(MtString& rStr, s32 num, bool bSigned);
    static void makeExpString(s32 sExp, MtString& rStr, bool bSigned);
    static void makeMoneyString(s32 sMoney, MtString& rStr, bool bSigned);
    static void makeRimString(s32 sRim, MtString& rStr, bool bSigned);
    static void makeJpString(s32 sJp, MtString& rStr, bool bSigned);
    static void makeGpString(s32 sGp, MtString& rStr, bool bSigned);
    static void makeDogmaString(s32 sDogma, MtString& rStr, bool bSigned);
    static void makePointString(s32 num, u32 type, MtString& rStr, bool bSigned);
    static void makeItemName(MtString& rStr, cItemParam* pParam);
    static void makeItemName(MtString& rStr, u32 item_id, u32 plus_value);
    static void makeItemName(MtString& rStr, MT_CTSTR name, u32 plus_value);
    static MT_CTSTR getItemName(u32 item_id);
    static void makeItemNameWithGrade(MtString& Str, u32 ItemId);
    static void makeItemParamAbilityName(MtStringEx<128>& rStr, rItemList::rParam* param);
    static MT_CTSTR toLowerString(MT_CHAR* pSrc);
    static MT_CTSTR toUpperString(MT_CHAR* pSrc);
    static MT_CTSTR toEnd3Dots(MT_CHAR* pSrc, u32 uLen);
    static u32 getCharNum(MT_CTSTR pSrc);
    static void getStrFromCharNum(MT_STR pDst, MT_CTSTR pSrc, u32 uCharNum, u32 uLenMax);
    static void TruncateStr(MtString& rStr, MT_CTSTR pSrc, u32 num, u32 truncateNum, MT_CHAR truncateChar);
    static void convSJIStoUTF8(const MT_CHAR* pSrcSjis, MT_CHAR* pDstUtf8, u32 bufSizeUtf8);
    static void convUTF8toSJIS(MT_CTSTR pSrcUtf8, MT_CHAR* pDstSjis, u32 bufSizeSjis);
    static void makeCharName(MtString& rStr, nGUIExt::NAME_TYPE type, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanShortName);
    static void makeCharName(MtString& rStr, const CCharacterName& name);
    static void makeCharName(MtString& rStr, const cContextInstHm* pContext, nGUIExt::NAME_TYPE type);
    static nGUIExt::NAME_TYPE ConvertNameDispToNameType(u8 nameDispType, bool isClanName);
    static void TruncateCharName(MtString& rStr, nGUIExt::NAME_TYPE type, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanShortName);
    static void convertEditNameString(MtString& str, MT_CTSTR name);
    static void makeColorTag(MtString& rStr, const MtColor& col);
    static bool SetFitString(MT_STR buffer, u32 bufferSize, MT_CTSTR str, const cGUIObjMessage* targetObjMessage, MT_CTSTR ellipsis);
    static f32 GetStringWidth(MT_CTSTR str, const cGUIObjMessage* targetObjMessage);
    static void GetItemEquipCategoryName(nGUIExt::StringItemCategoryName& itemCategoryName, const rItemList::rItemParam* itemParam, const rGUIMessage* resGmdParameter, const rGUIMessage* resGmdJewelryCategory);
    static void GetItemEquipCategoryName(nGUIExt::StringItemCategoryName& itemCategoryName, u32 itemId, const rGUIMessage* resGmdParameter, const rGUIMessage* resGmdJewelryCategory);
    static bool getCrestElementParamMsg(rItemList::rItemParam* pItemParam, u32 element_index, const rGUIMessage* pMsgParam, MtStringEx<128>& ret_str);
    static bool isSalon(nGUIExt::CHARA_EDIT edit);
    static void convertMtColorFromIntensityColor(MtVector4& src, MtColor& dest);
    static s32 getOnBitIndex(u32 bit, u32 index);
    static s32 getKetaNum(s32 val);
    static f32 getScaleForDefaultResolution(f32 fScaleRate);
    static void AdjustMouseCollisionSize(cGUIObjPolygon* objMouseCollision, f32 height);
    static cContextInstHm* getContext(nGUIExt::TARGET who, u32 charaId);
    static u32 getJobId(nGUIExt::TARGET who, u32 charaId);
    static void getEquipData(nGUIExt::TARGET who, u32 charaId, cEquipData* pData);
    static cItemParam* getItemParamFromUID(MT_CTSTR uid, sItemManager::STORAGE_FILLTER_TYPE filter_type);
    static u32 getCrestItemId(cItemParam* pParam, u32 index);
    static f32 getCrestIconFrame(rItemList::rItemParam* pItemParam);
    static f32 getCrestIconFrame(u32 item_id);
    static f32 getCrestIconFrame(cItemParam* pParam, u32 index);
    static const MtColor& getColorFromCraftColorNo(u32 color_no);
    static bool isEnableEquipIcon(u32 SlotNo, u32 JobId, u32 EquipJewelryNum);
    static s32 getItemParamPhysicalTypeFixFrame(u32 itemParamPhysicalType);
    static s32 getPhysicalTypeFixFrame(const rItemList::rItemParam* pParam);
    static s32 getPhysicalTypeFixFrame(const cEquipData& equipData, bool isMain);
    static s32 getItemParamElementTypeFixFrame(u32 itemParamElementType);
    static s32 getElementTypeFixFrame(const rItemList::rItemParam* pParam);
    static s32 getGameElementTypeFixFrame(u32 gameElementType);
    static s32 getElementTypeFixFrame(const cEquipData& equipData, bool isMain);
    static f32 getQuestFrame(nQuest::QUEST_TYPE quest_type);
    static void copyParameter(cGUIInstance* pDest, cGUIInstance* pOrg, s32 flag);
    static bool isEquipLantern();
    static void convertNormalSkillList(const cContextPlayerInfo* pPlinfo, nHuman::JOB_ENUM JobId, nGUIExt::stNormalSkill(&OutBuff)[20]);
    static void convertNormalSkillLearnList(const NormalSkillParamVec& LearnedList, nHuman::JOB_ENUM JobId, nGUIExt::stLearnNormalSkill(&OutBuff)[20]);
    static const rAcquirement::cNormalSkillData* getNormalSkillData(nHuman::JOB_ENUM JobId, u32 SkillNo);
    static nHuman::HM_SKILL_LV getNormalSkillLevel(nHuman::JOB_ENUM JobId, u32 Index, u32 SlotNo);
    static nHuman::HM_SKILL_LV getNormalSkillMaxLevel(nHuman::JOB_ENUM JobId, u32 SlotNo);
    static void setGUIUnitEnable(uGUIBase* pBase, bool b);
    static void setVisible(cGUIInstance* p, bool b);
    static void setVisible(cGUIObject* p, bool b);
    static void setVisible(cUnit* p, bool b);
    static bool isVisible(const cGUIInstance* p);
    static bool isVisible(const cGUIObject* p);
    static void setExecute(cGUIInstance* p, bool b);
    static void setExecuteTree(cGUIInstance* p, bool b);
    static bool isExecute(cGUIInstance* p);
    static MtVector4 getPos(const cGUIInstNull* p);
    static MtVector4 getPos(const cGUIObj2D* p);
    static MtVector3 getPos(const uCoord*);
    static void setPos(cGUIInstNull* p, const MtVector4& pos);
    static void setPos(cGUIObj2D* p, const MtVector4& pos);
    static void setPos(uCoord*, const MtVector3&);
    static f32 getPosX(const cGUIInstNull* p);
    static f32 getPosX(const cGUIObj2D* p);
    static f32 getPosY(const cGUIInstNull* p);
    static f32 getPosY(const cGUIObj2D* p);
    static void setPosX(cGUIInstNull* p, f32 v);
    static void setPosX(cGUIObj2D* p, f32 v);
    static void setPosY(cGUIInstNull* p, f32 v);
    static void setPosY(cGUIObj2D* p, f32 v);
    static void setScaleX(cGUIInstNull* p, f32 v);
    static void setScaleY(cGUIInstNull* p, f32 v);
    static void setMessage(cGUIObjMessage* p, MT_CTSTR msg);
    static void setMessage(cGUIObjMessage* p, MT_CTSTR msg, u32 length);
    static f32 getMsgWidth(const cGUIObjMessage* p);
    static f32 getMsgHeight(const cGUIObjMessage* p);
    static u32 getMsgLineNum(const cGUIObjMessage* p);
    static void setAnalyzeTag(cGUIObjMessage* p, bool b);
    static void clearMessage(cGUIObjMessage* p);
    static MtVector2 getScreenPos(const cGUIInstance* p);
    static MtVector2 getScreenPos(const cGUIObject* p);
    static void setCurrentFrame(cGUIInstAnimation* pInst, f32 frame, bool fix);
    static void setCurrentFrame(cGUIObject* pObj, f32 frame, bool fix);
    static void setCurrentFrame(cGUIObjChildAnimationRoot* pObj, f32 frame);
    static void setCurrentFrameTree(cGUIObject* pObj, f32 frame, bool fix);
    static void setCurrentFrameTree(cGUIInstAnimation* pInstAnim, f32 frame, bool fix);
    static f32 getCurrentFrame(const cGUIInstAnimation* pInst);
    static f32 getCurrentFrame(const cGUIObjChildAnimationRoot* pObjChildAnimRoot);
    static f32 getCurrentFrame(const cGUIObject* pObj);
    static void setSequenceId(cGUIInstAnimation* pInst, u32 id, bool reset);
    static void setSequenceId(cGUIObjChildAnimationRoot* pObjChildAnimRoot, u32 id, bool reset);
    static u32 getSequenceId(const cGUIInstAnimation* pInst);
    static u32 getSequenceId(const cGUIObjChildAnimationRoot* pObjChildAnimRoot);
    static f32 getStopFrame(const cGUIInstAnimation*);
    static f32 getFrameCount(const cGUIInstAnimation* pInst);
    static f32 getFrameCount(const cGUIObject* pObj);
    static MtVector3 toVector3(const MtVector2& v);
    static MtVector2 toVector2(const MtVector3&);
    static void setAmbientColor(cGUIInstAnimation* pInst, const MtColor& color);
    static void setAmbientColor(cGUIObjColorAdjust* pObj, const MtColor& color);
    static void setColor(cGUIObjPolygon* pObj, const MtColor& color);
    static void setColor(cGUIObjMessage* pObj, const MtColor& color);
    static void setAlpha(cGUIObjMessage* pObj, u8 alpha);
    static MtVector4 getColorScale(const cGUIInstNull*);
    static MtVector4 getColorScale(const cGUIObjColorAdjust*);
    static void setColorScale(cGUIInstNull* pInst, const MtVector4& colorScale);
    static void setColorScale(cGUIObjColorAdjust* obj, const MtVector4& colorScale);
    static void addChildUnit(uGUIBase* pParent, uGUIBase* pChild);
    static MT_CTSTR GetStageName(s32 stageNo);
    static MT_CTSTR GetSpotName(s32 spotId);
    static MT_CTSTR GetMsgFromIndexName(const rGUIMessage* pGmd, MT_CTSTR index_name);
    static MT_CTSTR GetMsgFromIndexName(const rGUIMessage* pGmd, MT_CTSTR index_seed, u32 id);
    static MT_CTSTR GetFuncClassName(u32 funcClassId);
    static MT_CTSTR GetOmMapIconName(u32 omMapIcon);
    static MT_CTSTR GetOmFuncClassName(u32 omId);
    static MT_CTSTR GetOcdName(u32 ocdId);
    static MT_CTSTR getPawnStatusStr(uGUIBase* pGUI, u32 status);
    static MT_CTSTR getPawnShareRangeStr(uGUIBase* pGUI, u32 shareRange);
    static MT_CTSTR getWeightRankMsg(rGUIMessage* pMsgData, u32 rank);
    static MT_CTSTR GetPawnPersonalityStr(uGUIBase* pGUI, u32 pawnPersonality);
    static MT_CTSTR getPlayPurposeMainStr(uGUIBase* pGUI, u32 index);
    static MT_CTSTR getPlayPurposeSubStr(uGUIBase* pGUI, u32 index);
    static MT_CTSTR getPlayStyleStr(uGUIBase* pGUI, u32 index);
    static MT_CTSTR getClanMottoStr(uGUIBase* pGUI, u32 index);
    static MT_CTSTR getClanDayStr(uGUIBase* pGUI, u32 index);
    static MT_CTSTR getClanHourStr(uGUIBase* pGUI, u32 index);
    static MT_CTSTR getClanFeatureStr(uGUIBase* pGUI, u32 index);
    static f32 getClanRankAnimFrame(u32 Rank);
    static MT_CTSTR GetChargeCourseName(u32 courseId);
    static void GetChargeEffectMessage(MtString& ret_str, u32 effect, bool isAdd);
    static bool IsChargeAttributeEnable(u32 attr);
    static void GetChargeEffectFromAttribute(MtString& ret_str, u32 attr);
    static MT_CTSTR getEquipPartsName(rGUIMessage* pGMDRes, u32 Slot);
    static MT_CTSTR getEquipPartsNameFromCategory(rGUIMessage* pGMDRes, u32 category);
    static MT_CTSTR getEquipPartsNameFromItemParam(rGUIMessage* pGMDRes, rItemList::rItemParam* pItemParam);
    static void getCustomSkillIconTagForTrgBtn(nGUIExt::StringKeyCustomIconTag& outIconTag, nGUIExt::CUSTOM_SKILL_PALLET PalletId);
    static void getCustomSkillIconTagForBtn(nGUIExt::StringKeyCustomIconTag& outIconTag, nGUIExt::CUSTOM_SKILL_PALLET PalletId);
    static MT_CTSTR getIconRCFromBtn(sPadExt::PAD_BTN_TYPE btn, bool bKeyAll);
    static MT_CTSTR getIconRCFromKB(sKeyboard::KB_TYPE key);
    static MT_CTSTR getRawPadIconTag(u32 pad);
    static MT_CTSTR getRawKeyIconTag(u32 key);
    static MT_CTSTR getRawMouseIconTag(u32 mouse);
    static void getPadIconTag(nGUIExt::StringKeyCustomIconTag* outBaseIconTag, nGUIExt::StringKeyCustomIconTag* outModifierIconTag, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlankTag, bool isModifierBlankTag);
    static void getKeyIconTag(nGUIExt::StringKeyCustomIconTag* outBaseIconTag, nGUIExt::StringKeyCustomIconTag* outModifierIconTag, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlankTag, bool isModifierBlankTag);
    static void getIconTag(nGUIExt::StringKeyCustomIconTag* outBaseIconTag, nGUIExt::StringKeyCustomIconTag* outModifierIconTag, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlankTag, bool isModifierBlankTag);
    static void joinIconTag(nGUIExt::StringKeyCustomIconTag& outIconTag, MT_CTSTR baseIconTag, MT_CTSTR modifierIconTag, ICON_TAG_JOINT_TYPE jointType, bool isInvert);
    static void getPadIconTag(nGUIExt::StringKeyCustomIconTag& outIconTag, nKeyCustom::KB_CUSTOM keyCustom, ICON_TAG_OUT_TYPE outType, ICON_TAG_JOINT_TYPE jointType, u32 flags);
    static void getKeyIconTag(nGUIExt::StringKeyCustomIconTag& outIconTag, nKeyCustom::KB_CUSTOM keyCustom, ICON_TAG_OUT_TYPE outType, ICON_TAG_JOINT_TYPE jointType, u32 flags);
    static void getIconTag(nGUIExt::StringKeyCustomIconTag& outIconTag, nKeyCustom::KB_CUSTOM keyCustom, ICON_TAG_OUT_TYPE outType, ICON_TAG_JOINT_TYPE jointType, u32 flags);
    static void getRawPadText(nGUIExt::StringKeyName& keyName, u32 pad);
    static void getRawKeyText(nGUIExt::StringKeyName& keyName, u32 key);
    static void getPadText(nGUIExt::StringKeyName* outBaseText, nGUIExt::StringKeyName* outModifierText, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlank, bool isModifierBlank);
    static void getKeyText(nGUIExt::StringKeyName* outBaseText, nGUIExt::StringKeyName* outModifierText, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlank, bool isModifierBlank);
    static void getKeyCustomText(nGUIExt::StringKeyName* outBaseText, nGUIExt::StringKeyName* outModifierText, nKeyCustom::KB_CUSTOM keyCustom, bool isBaseBlank, bool isModifierBlank);
    static void joinKeyCustomText(nGUIExt::StringKeyName& outText, MT_CTSTR baseText, MT_CTSTR modifierText, ICON_TAG_JOINT_TYPE jointType, bool isInvert);
    static void getPadText(nGUIExt::StringKeyName& outText, nKeyCustom::KB_CUSTOM keyCustom, ICON_TAG_OUT_TYPE outType, ICON_TAG_JOINT_TYPE jointType, u32 flags);
    static void getKeyText(nGUIExt::StringKeyName& outText, nKeyCustom::KB_CUSTOM keyCustom, ICON_TAG_OUT_TYPE outType, ICON_TAG_JOINT_TYPE jointType, u32 flags);
    static void getKeyCustomText(nGUIExt::StringKeyName& outText, nKeyCustom::KB_CUSTOM keyCustom, ICON_TAG_OUT_TYPE outType, ICON_TAG_JOINT_TYPE jointType, u32 flags);
    static s32 GetJobParamNum();
    static const nGUIExt::JobParam* GetJobParam(s32 dispIndex);
    static const nGUIExt::JobParam* GetJobParamFromJobId(u32 jobId);
    static s32 GetValidJobNum();
    static nHuman::JOB_ENUM GetValidJobId(s32 dispIndex);
    static s32 GetValidJobIndex(nHuman::JOB_ENUM jobId);
    static MT_CTSTR GetJobInfoMsg(rGUIMessage* pGMDRes, u32 jobId);
    static const CJobChangeInfo* GetJobChangeInfo(const JobChangeInfoVec& jobChangeList, s32 dispIndex);
    static void setupGradeIcon(cGUIInstAnimation* (&grade_icon)[4], rItemList::rItemParam* pItemParam);
    static u32 getPlayerTotalJobLevel();
    static u32 getMyPawnTotalJobLevel(u32 PawnId);
    static u32 getTotalJobLevel(const cContextInstHm* pContext);
    static bool IsDirectChat();
    static s32 CalcPageNum(s32 itemNum, s32 itemNumPerPage);
    static s32 CalcDispNum(s32 itemNum, s32 itemNumPerPage, s32 pageIndex);
    static const nGUIExt::HeadUiInfo* GetHeadUiInfoPtr(nGUIExt::HEAD_UI_TYPE headUiType);
    static void GetHeadUiInfo(nGUIExt::HeadUiInfo& headUiInfo, nGUIExt::HEAD_UI_TYPE headUiType);
    static f32 CalcHeadUiAlpha(const nGUIExt::HeadUiInfo& headUiInfo, const MtVector3& targetPos, const MtVector3& uiPos, uPlayer* player, f32 sizeRate);
    static bool IsPartyEntry(const cContextInstHm* contextInstHm);
    static f32 GetCurseHpRate(const uCharacter* character);
    static void SetCurseGaugeObj(cGUIObject* curseGaugeObj, f32 hpRate);
    static bool IsValidOcdId(u32 ocdId);
    static bool IsValidAccumulationOcdId(u32 ocdId);
    static u32 GetDispOcdId(u32 ocdId);
    static u32 UpdateOcdIcon(nGUIExt::OcdIconInterface& ocdIconInterface, f32 deltaTime);
    static nGUIExt::DAMAGE_UI_MODEL_TYPE GetDamageUiModelType(uDDOModel* model);
    static uDDOModel* GetDamageUiAttackerModel(cHitInfoAfter& hitInfo);
    static bool GetJobItemEquipInfo(stJobItemEquipInfo& jobItemEquipInfo, uHuman* human, nCharacterData::EQUIP_SLOT_TYPE equipSlotType);
    static bool GetJobItemEquipInfo(stJobItemEquipInfo& jobItemEquipInfo, uHuman* human, nCharacterData::ARROW_EQUIP arrowEquip);
    static bool IsItemEnableSeal(const rItemList::rItemParam* itemParam);
    static MT_CTSTR GetPawnFeedbackComment(uGUIBase* pGUI, u8 feedbackType, u8 starNum, u8 commentNo);
    static uGUISystemMsg* reqDialog(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4, bool isChatSubMenu);
    static uGUISystemMsg* reqDialog(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, bool isCancelOff, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4, bool isChatSubMenu);
    static uGUISystemMsg* createPawnSelectDialog(MT_CTSTR title, u32 select_pawn_id);
    static uGUIPopCmd01* createPopCmd01(MOVE_LINE moveLine, u32 pointerPriority, u64 unitGroup, bool isChatSubMenu, bool isSingleton);
    static u64 getPastTime(u64 time);
    static u64 getFutureTime(u64 time);
    static void setURL(MtString& Str, u32 Type, MT_CTSTR pAddStr);
    static void setItemAddURL(MtString& Str, u32 Type, u32 LineupID, u32 ItemID);
    static bool replaceNGWord(MtString& DestStr, MT_CTSTR pSrcStr, u32 Length);
    static bool replaceNGWord(MtString& DestStr, const MtString& SrcStr);
    static u32 getCaplinkFriendAttrMsgIndex(u32 attr);
private:
    static bool copyParameterlValueSet(cGUIInstance* pDest, cGUIInstance* pOrg, s32 flag);
    static bool copyParameterCheck(cGUIInstance* pDest, cGUIInstance* pOrg, s32 flag);
    static bool copyParameterLoop(cGUIInstance* pDest, cGUIInstance* pOrg, s32 flag);
    static f32 adjustResolutionScaleNum(f32 OrgScale);
public:
    static const MT_CTSTR DefaultEllipsis;
    static const u32 FLAG_COPY_PRM_SEQ = 1;
    static const u32 FLAG_COPY_PRM_POS_X = 2;
    static const u32 FLAG_COPY_PRM_POS_Y = 4;
    static const u32 FLAG_COPY_PRM_POS = 8;
    static const u32 FLAG_COPY_PRM_DEFAULT = 1;
    static const u32 ICON_TAG_FLAG_NONE = 0;
    static const u32 ICON_TAG_FLAG_INVERT = 1;
    static const u32 ICON_TAG_FLAG_BLANK_OFF = 2;
};
