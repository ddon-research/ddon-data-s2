#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Character.h"
#include "../shared/Common.h"
#include "../shared/Craft.h"
#include "../shared/Item.h"
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/MtTime.h"
#include "cCraftPlusItem.h"
#include "cCraftRecipe.h"
#include "cCraftSkill.h"
#include "../shared/cSystem.h"
#include "../shared/nCharacterData.h"
#include "rCraftRecipe.h"
#include "../shared/rItemList.h"
#include "../shared/sItemManager.h"

// Forward declarations
class CDataCommonU32;
class CDataCraftColorant;
class CDataCraftElement;
class CDataCraftMaterial;
class CDataCraftProductInfo;
class CDataCraftProgress;
class CDataCraftSupportPawnID;
class CDataEquipElementParam;
class CDataMDataCraftGradeupRecipe;
class CDataMDataCraftRecipe;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtTime;
class cCraftCapPassData;
class cCraftElementExpData;
class cCraftPlusItem;
class cCraftRecipe;
class cCraftSkill;
class cItemParam;
class cMenuGetCraftRecipeToServer;
class cPawnListParam;
class rCraftCapPass;
class rCraftElementExp;
class rCraftUpGradeExp;

// Declarations
class sCraftManager;

// Type aliases from DWARF
using CCraftProductInfo = CDataCraftProductInfo;
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using EquipElementParamVec = MtTypedArray<CDataEquipElementParam>;
using MDataCraftGradeupRecipeVec = MtTypedArray<CDataMDataCraftGradeupRecipe>;
using MDataCraftRecipeVec = MtTypedArray<CDataMDataCraftRecipe>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class sCraftManager : public cSystem
{
public:
    enum CRAFT_RESULT
    {
        RESULT_NONE = 0,
        RESULT_MOVE = 1,
        RESULT_EXIT = 2,
    };
    enum RESULT
    {
        RESULT_WAIT = 0,
        RESULT_SUCCESS = 1,
        RESULT_SERVER_ERROR = 2,
        RESULT_REQ_ERROR = 3,
    };
    enum MENU_TYPE
    {
        MENU_TYPE_NONE = 0,
        MENU_TYPE_CREATE = 1,
        MENU_TYPE_UPGRADE = 2,
        MENU_TYPE_ELEMENT = 3,
        MENU_TYPE_COLOR = 4,
        MENU_TYPE_POINT = 5,
        MENU_TYPE_TASK = 6,
        MENU_TYPE_NUM = 7,
    };
    enum COLOR_REGULATE_STATE
    {
        COLOR_REGULATE_STATE_NONE = 0,
        COLOR_REGULATE_STATE_REQUEST = 1,
        COLOR_REGULATE_STATE_COMPLETE = 2,
        COLOR_REGULATE_STATE_CANCEL = 3,
        COLOR_REGULATE_STATE_ERROR = 4,
        COLOR_REGULATE_NUM = 5,
    };
    enum IR_REDUCTION_DATA_STATE
    {
        IR_REDUCTION_DATA_STATE_NONE = 0,
        IR_REDUCTION_DATA_STATE_REQUEST = 1,
        IR_REDUCTION_DATA_STATE_COMPLETE = 2,
        IR_REDUCTION_DATA_STATE_CANCEL = 3,
        IR_REDUCTION_DATA_STATE_ERROR = 4,
        IR_REDUCTION_DATA_STATE_NUM = 5,
    };
    enum RECIPE_TYPE
    {
        RECIPE_TYPE_CREATE = 0,
        RECIPE_TYPE_UPGRADE = 1,
        RECIPE_TYPE_ELEMENT = 2,
        RECIPE_TYPE_COLOR = 3,
        RECIPE_TYPE_NUM = 4,
    };
    enum RECIPE_QUE_STATE
    {
        RECIPE_QUE_STATE_FAILED = -1,
        RECIPE_QUE_STATE_CONTINUE = 0,
        RECIPE_QUE_STATE_SUCCESS = 1,
        RECIPE_QUE_STATE_EXIT = 2,
    };
    enum RECIPE_REQ_STATE
    {
        RECIPE_REQ_STATE_NONE = 0,
        RECIPE_REQ_STATE_SUCCESS = 1,
        RECIPE_REQ_STATE_ERROR = 2,
        RECIPE_REQ_STATE_END = 3,
    };
    enum BAGGAGE_MATERIAL_STATE
    {
        BAGGAGE_MATERIAL_STATE_NONE = 0,
        BAGGAGE_MATERIAL_STATE_WAIT = 1,
        BAGGAGE_MATERIAL_STATE_SUCCESS = 2,
        BAGGAGE_MATERIAL_STATE_ERROR = 3,
        BAGGAGE_MATERIAL_STATE_NUM = 4,
    };
    enum ADD_EXP_RNO
    {
        ADD_EXP_RNO_INIT = 0,
    };
    enum
    {
        CRAFT_STATE_WAIT = 0,
        CRAFT_STATE_MOVE = 1,
        CRAFT_STATE_STOP = 2,
        CRAFT_STATE_END = 3,
        CRAFT_STATE_NUM = 4,
    };
    enum
    {
        CRAFT_TASK_STATE_NONE = 0,
        CRAFT_TASK_STATE_WAIT = 1,
        CRAFT_TASK_STATE_COMPLETE = 2,
        CRAFT_TASK_STATE_CREAT = 3,
        CRAFT_TASK_STATE_LOST = 4,
        CRAFT_TASK_STATE_PARTY = 5,
        CRAFT_TASK_STATE_EXPEDITION = 6,
        CRAFT_TASK_STATE_MAX = 7,
    };
    enum SORT_DIR
    {
        DEC_DIR = 0,
        INC_DIR = 1,
    };
    enum
    {
        PROCESS_ITEM_TYPE_ELEMENT = 0,
        PROCESS_ITEM_TYPE_COLOR = 1,
        PROCESS_ITEM_TYPE_NUM = 2,
    };
    enum
    {
        KICK_PARTY_RESULT_WAIT = 0,
        KICK_PARTY_RESULT_SUCCESS = 1,
        KICK_PARTY_RESULT_ERROR = 2,
    };
public:
    class MyDTI;
    class cCraftFinishNotice;
    class cAddExp;
    class RecordRecipe;
    class CreateItem;
    class cCraftPawnCtrl;
    class cCraftRankUp;
    class cCraftUpGrade;
    class cCraftUpGradeItemList;
    class cCraftIrReductionData;
    class cCraftRecipeControl;
    class stRecipeRequest;
    class PawnCost;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCraftFinishNotice : public MtObject
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
        cCraftFinishNotice();
        // Address: 0x01ac2640 - 0x01ac2641 (1 bytes)
        virtual ~cCraftFinishNotice() {}
        void setPawnId(u32 pawnId);
        u32 getPawnId();
    private:
        u32 mPawnId;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cAddExp : public MtObject
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
        cAddExp();
    private:
        u32 mRno;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class RecordRecipe : public MtObject
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
        RecordRecipe();
        u32 getRecipeNo();
        void setRecipeNo(u32 recipeNo);
    private:
        u32 mRecipeNo;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class CreateItem : public MtObject
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
        CreateItem();
        u32 getRecipeNo();
        void setRecipeNo(u32 recipeNo);
        MtTime getCreateStartTime();
        void setCreateStartTime(MtTime time);
        u32 getPawnNo();
        void setPawnNo(u32);
    private:
        u32 mRecipeNo;  // offset: 0x8
        u32 mPawnNo;  // offset: 0xc
        MtTime mCreateStartTime;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cCraftPawnCtrl : public MtObject
    {
        // inferred: sCraftManager::reset names sCraftManager::mCraftCtrl.mRecipeId
        friend class sCraftManager;
    public:
        enum RESULT
        {
            CRAFT_REQ_RESULT_WAIT = 0,
            CRAFT_REQ_RESULT_SUCCESS = 1,
            CRAFT_REQ_RESULT_ERROR = 2,
        };
        enum
        {
            CRAFT_SLOT_MAIN_PAWN = 0,
            CRAFT_SLOT_SUPPORT_PAWN_1 = 1,
            CRAFT_SLOT_SUPPORT_PAWN_2 = 2,
            CRAFT_SLOT_SUPPORT_PAWN_3 = 3,
            CRAFT_SLOT_NUM = 4,
        };
        enum
        {
            CRAFT_PROGRESS_STATE_NONE = 0,
            CRAFT_PROGRESS_STATE_WAIT = 1,
            CRAFT_PROGRESS_STATE_FINISH = 2,
            CRAFT_PROGRESS_STATE_NUM = 3,
        };
        enum
        {
            CRAFT_PAWN_TYPE_MY_PAWN = 0,
            CRAFT_PAWN_TYPE_RENTAL_PAWN = 1,
            CRAFT_PAWN_TYPE_NONE = 2,
        };
        enum
        {
            CRAFT_TASK_RNO_WAIT = 0,
            CRAFT_TASK_RNO_INIT = 1,
            CRAFT_TASK_RNO_MY_PAWN_REQ = 2,
            CRAFT_TASK_RNO_MY_PAWN_WAIT = 3,
            CRAFT_TASK_RNO_MY_PAWN_ERROR = 4,
            CRAFT_TASK_RNO_MY_PAWN_DATA_REQ = 5,
            CRAFT_TASK_RNO_MY_PAWN_DATA_WAIT = 6,
            CRAFT_TASK_RNO_MY_PAWN_DATA_ERROR = 7,
            CRAFT_TASK_RNO_RENTAL_PAWN_REQ = 8,
            CRAFT_TASK_RNO_RENTAL_PAWN_WAIT = 9,
            CRAFT_TASK_RNO_RENTAL_PAWN_ERROR = 10,
            CRAFT_TASK_RNO_PROGRESS_REQ = 11,
            CRAFT_TASK_RNO_PROGRESS_WAIT = 12,
            CRAFT_TASK_RNO_PROGRESS_ERROR = 13,
            CRAFT_TASK_RNO_FINISH = 14,
        };
        enum
        {
            ELEMENT_SLOT_1 = 0,
            ELEMENT_SLOT_2 = 1,
            ELEMENT_SLOT_3 = 2,
            ELEMENT_SLOT_4 = 3,
            ELEMENT_SLOT_NUM = 4,
        };
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
        cCraftPawnCtrl();
        virtual ~cCraftPawnCtrl();
        void init();
        void resetCraftPawn();
        void resetSelectedCraftPawn();
        void keepCraftPawn(u32 slotNo);
        void returnKeepCraftPawn();
        void returnKeepCraftMainPawn();
        void returnKeepCraftSupportPawn();
        void setCraftPawnId(u32 pawnId, u32 type);
        void setCraftPawnSlotNo(u32 slotNo, u32 type);
        void setCraftSupportPawnId(u32 pawnId);
        void releaseCraftSupportPawnId();
        s32 getCraftPawnId(u32 type);
        s32 getKeepCraftPawnId(u32 type);
        s32 getCraftPawnSlotNo(u32 type);
        u32 getCraftPawnType(u32 pawnId);
        bool isCraftPawn(u32 pawnId);
        u32 getProgressStatus(u32 pawnId);
        void setContinuePawn(s32 dec_count);
        void setCraftRecipeId(u32 recipeId);
        void resetCraftRecipeId();
        u32 getCraftRecipeId();
        MT_CTSTR getPawnName(u32 slotNo);
        MT_CTSTR getPawnNameToPawnId(u32 pawnId);
        u32 getPawnTypeToPawnId(u32 pawnId);
        u32 getPawnType(u32 slotNo);
        u32 getPawnRank(u32 slotNo);
        u32 getPawnRankToPawnId(u32 pawnId);
        bool isCreatePawn(u32 pawnId);
        u32 getPawnSkillLvSub(s32 pawnId, u32 skill, bool isZero);
        u32 getPawnSkillLv(u32 slotNo, u32 skill, bool isZero);
        u32 getPawnTotalSkillLv(u32 skill, bool isZero);
        u32 getPawnTotalSpdTime(u32 baseTime, u16 itemRank, bool isZero, u32 createCount);
        u32 getPawnTotalNum();
        u32 getCraftMoreTime(u32 slotNo);
        u32 getCraftMoreTimeSub(u32 pawnId);
        void setCraftCount(s32 pawnId, s32 count);
        void setCreateCount(u8 count);
        u8 getCreateCount();
        u8 getCreateCountMax();
        rCraftRecipe::cCraftRecipe* getRecipeData(u32 type);
        MT_CTSTR getCreateItemName(u32 type);
        void initCraftProgressList();
        void reqCraftProgressList();
        void moveCraftProgressList();
        bool isCraftProgressComplete();
        u32 getCraftTaskNum();
        s32 getCraftTaskInfoToIndex(u32 slotNo);
        u32 getCraftTaskInfoToPawnId(u32 slotNo);
        s32 getCraftTaskInfo(u32 pawnId);
        s32 getCraftSupportTaskInfo(u32 pawnId);
        u32 getPawnProgressRecipeId(s32 index);
        u32 getPawnProgressRecipeIdToPawnId(u32 pawnId);
        u32 getPawnProgressToppingId(s32 index);
        u32 getPawnProgressRemainTime(s32 index);
        u32 getPawnProgressRemainTimeToPawnId(u32 pawnId);
        u32 getPawnProgressMainPawnId(s32 index);
        u32 getSupportPawnId(u32 pawnId, u32 supportIdx);
        CDataCraftProgress* getCraftTaskToPawnId(u32 pawnId);
        cPawnListParam* getCraftTaskToIndex(u32 index);
        bool isParty();
        bool kickPawn(u32 pawnId);
        bool isCreateMaterial(u32 type);
        bool isCreateMaterialSub(rCraftRecipe::cCraftRecipe* pRecipe, u8 createCount, bool isListUp);
        bool createCraftMaterialList(u32 type);
        MtTypedArray<CDataCraftMaterial>& getCreateMaterialList();
        bool isCreateSupportPawn();
        bool createSupportPawnList();
        MtTypedArray<CDataCraftSupportPawnID>& getCraftSupportPawnList();
        bool createCraftElementList();
        void createCraftDetachElementList(u32 slotNo);
        MtTypedArray<CDataCraftElement>& getCraftElementList();
        void setCraftResultElementList(EquipElementParamVec& list);
        EquipElementParamVec* getCraftResultElementList();
        void setCraftResultColor(u8 colorNo);
        u8 getCraftResultColor();
        void setCraftColorNo(u32 colorNo);
        u32 getCraftColorNo();
        bool createCraftColorList(bool isEffect);
        MtTypedArray<CDataCraftColorant>& getCraftColorList();
        bool isCreateGold(u32 type);
        u32 getCreateGoldSub(u32 type, u32 recipeId, CommonU32Vec& pawnList);
        u32 getCreateGold(u32 type);
        void startCraftCallBack(void* param);
        bool startCraftReq();
        void setCraftStartLog();
        bool timeSavingReq(s32 select);
        u32 getTimeSavingCost(nCharacter::E_WALLET_POINT_TYPE walletType);
        void getCraftItemCallBack(void* param);
        bool getCraftItemReq(s32 index, u32 storageType);
        bool getCraftProductInfoReq(s32 index);
        RESULT getCraftProductInfoReqResult();
        void setCraftProductInfoPacket(const CDataCraftProductInfo& Info);
        const CDataCraftProductInfo* getCraftProudctInfo();
        bool isMakeGreatSuccess();
        void setMakeGreatSuccess(bool isGreatSuccess);
        RESULT getCraftReqResult();
        bool cancelCraftReq(s32 index);
        RESULT cancelCraftReqResult();
        u32 getCraftProgressListNum();
        MT_CTSTR getCraftProgressListItemName(u32 index);
        u32 getCraftProgressListItemId(u32 index);
        u32 getCraftProgressListItemNum(u32 index);
        u32 getCraftProgressListItemStorageType(u32 index);
        void startUpGradeCallBack(void* param);
        bool startUpGradeReq();
        void setUpGradeStartLog();
        bool isTopping();
        MT_CTSTR getToppingItemName();
        void setToppingUID(MT_CTSTR UID, u32 analizeItemID);
        MT_CTSTR getToppingUID();
        void setUpGradeUID(MT_CTSTR UID, u32 analizeItemID);
        MT_CTSTR getUpGradeUID();
        void resetElement();
        bool isElementSlot(u32 type, bool isArmItem);
        u32 getElementItemId(u32 type);
        MT_CTSTR getElementEfcName(u32 type);
        void keepCraftElement(u32 slotNo);
        void setCraftElementUID(u32 slotNo, MT_CTSTR UID);
        MT_CTSTR getCraftElementUID(u32 slotNo);
        void initElement();
        bool isElementGoldSub(sCraftManager::MENU_TYPE type);
        bool isElementGold();
        void startElementAttachCallBack(void* param);
        bool startElementAttachReq();
        void startElementDetachCallBack(void* param);
        bool startElementDetachReq();
        void resetColor();
        bool isColor();
        MT_CTSTR getColorEfcName();
        void keepCraftColor();
        void setCraftColorUID(MT_CTSTR UID);
        bool isColorGold();
        void startColorChangeCallBack(void* param);
        bool startColorChangeReq();
        void setExpLog();
        void setUpGradeDataUID(MT_CTSTR str);
        MT_CTSTR getUpGradeDataUID();
        void setColorChangeDataUID(MT_CTSTR);
        MT_CTSTR getColorChangeDataUID();
        s32 getCraftSkillCorrection(u32 itemRank);
        bool startCraftSkillAnalyzeReq(nCraft::E_CRAFT_TYPE craftType);
    public:
        bool mIsMakeGreatSuccess;  // offset: 0x8
    private:
        s32 mSelectSlotNo;  // offset: 0xc
        u32 mMainPawnId;  // offset: 0x10
        u32 mSupportPawnId1;  // offset: 0x14
        u32 mSupportPawnId2;  // offset: 0x18
        u32 mSupportPawnId3;  // offset: 0x1c
        u32 mMainPawnSlotNo;  // offset: 0x20
        u32 mSupportPawnSlotNo1;  // offset: 0x24
        u32 mSupportPawnSlotNo2;  // offset: 0x28
        u32 mSupportPawnSlotNo3;  // offset: 0x2c
        u32 mKeepMainPawnId;  // offset: 0x30
        u32 mKeepSupportPawnId1;  // offset: 0x34
        u32 mKeepSupportPawnId2;  // offset: 0x38
        u32 mKeepSupportPawnId3;  // offset: 0x3c
        u32 mRecipeId;  // offset: 0x40
        u32 mAnalizeItemId;  // offset: 0x44
        MtString mToppingUID;  // offset: 0x48
        MtString mUpGradeUID;  // offset: 0x50
        u8 mCreateCount;  // offset: 0x58
        s32 mElelemtSlotSelectNo;  // offset: 0x5c
        MtString mElementSlotNo1;  // offset: 0x60
        MtString mElementSlotNo2;  // offset: 0x68
        MtString mElementSlotNo3;  // offset: 0x70
        MtString mElementSlotNo4;  // offset: 0x78
        MtString mKeppElementSlotNo1;  // offset: 0x80
        MtString mKeepElementSlotNo2;  // offset: 0x88
        MtString mKeepElementSlotNo3;  // offset: 0x90
        MtString mKeepElementSlotNo4;  // offset: 0x98
        u32 mColorNo;  // offset: 0xa0
        MtString mColorSlotNo1;  // offset: 0xa8
        MtString mKeepColorSlotNo1;  // offset: 0xb0
        MtTypedArray<CDataCraftMaterial> mMaterialList;  // offset: 0xb8
        MtTypedArray<CDataCraftSupportPawnID> mSupportPawnList;  // offset: 0xd8
        MtTypedArray<CDataCraftElement> mElementList;  // offset: 0xf8
        EquipElementParamVec mResultElementList;  // offset: 0x118
        MtTypedArray<CDataCraftColorant> mColorList;  // offset: 0x138
        u8 mResultColorNo;  // offset: 0x158
        sItemManager::cItemBag::cCraftStartData mCraftStartData;  // offset: 0x160
        sItemManager::cItemBag::cCraftUpGradeData mCraftUpGradeData;  // offset: 0x180
        sItemManager::cItemBag::cCraftColorChange mCraftColorChangeData;  // offset: 0x198
        RESULT mCraftReqResult;  // offset: 0x1b0
        u32 mCraftTaskRno;  // offset: 0x1b4
        u32 mMyPawnDataReqNo;  // offset: 0x1b8
        bool mIsCraftProgressComplete;  // offset: 0x1bc
        bool mIsNoticeReq;  // offset: 0x1bd
        CCraftProductInfo mCraftProductInfo;  // offset: 0x1c0
    public:
        static MyDTI DTI;
        static const u32 WORK_SPD_MIN = 30;
    };
public:
    class cCraftRankUp : public MtObject
    {
    public:
        enum RESULT
        {
            CRAFT_REQ_RESULT_WAIT = 0,
            CRAFT_REQ_RESULT_SUCCESS = 1,
            CRAFT_REQ_RESULT_ERROR = 2,
        };
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
        cCraftRankUp();
        // Address: 0x01ac2020 - 0x01ac2021 (1 bytes)
        virtual ~cCraftRankUp() {}
        void init();
        void setPawnId(u32 pawnId);
        u32 getPawnId();
        void setAddExp(u32 num);
        u32 getAddExp();
        void setBonusExp(u32 num);
        u32 getBonusExp();
        void setTotalExp(u32 num);
        void setRankUp(bool isRankUp);
        bool isRankUp();
        void setCraftRank(u32 rank);
        u32 getCraftRank();
        void setAddCraftPoint(u32 num);
        u32 getAddCraftPoint();
        void setTotalCraftPoint(u32 num);
        bool craftPointReq(u32 pawnId, u32 Type, u32 level);
        RESULT craftPointReqWait();
    private:
        u32 mPawnId;  // offset: 0x8
        u32 mAddExp;  // offset: 0xc
        u32 mBonusExp;  // offset: 0x10
        u32 mTotalExp;  // offset: 0x14
        bool mIsRankUp;  // offset: 0x18
        u32 mCraftRank;  // offset: 0x1c
        u32 mAddCraftPoint;  // offset: 0x20
        u32 mTotalCraftPoint;  // offset: 0x24
        RESULT mCraftReqResult;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
public:
    class cCraftUpGrade : public MtObject
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
        cCraftUpGrade();
        virtual ~cCraftUpGrade();
        void init();
        void setAddPoint(u32 num);
        u32 getAddPoint();
        void setTotalPoint(u32 num);
        u32 getTotalPoint();
        void setUpGradeItem(u32 itemNo);
        u32 getUpGradeItem();
        void setUpGradeHistory(CommonU32Vec& list);
        const CommonU32Vec& getUpGradeHistory();
        void setUpGradeBeforeItem(u32 itemNo);
        u32 getUpGradeBeforeItem();
        void setCharacterId(u32 characterId);
        u32 getCharacterId();
        void setPawnId(u32 pawnId);
        u32 getPawnId();
        void setEquipType(nCharacterData::EQUIP_TYPE equipType);
        nCharacterData::EQUIP_TYPE getEquipType();
        void setEquipSlot(nCharacterData::EQUIP_SLOT_TYPE equipSlot);
        nCharacterData::EQUIP_SLOT_TYPE getEquipSlot();
    private:
        u32 mAddPoint;  // offset: 0x8
        u32 mTotalPoint;  // offset: 0xc
        u32 mItemNo;  // offset: 0x10
        u32 mBeforeItemNo;  // offset: 0x14
        MtString mUID;  // offset: 0x18
        CommonU32Vec mUpGradeHistory;  // offset: 0x20
        u32 mCharacterId;  // offset: 0x40
        u32 mPawnId;  // offset: 0x44
        nCharacterData::EQUIP_TYPE mEquipType;  // offset: 0x48
        nCharacterData::EQUIP_SLOT_TYPE mEquipSlot;  // offset: 0x4c
    public:
        static MyDTI DTI;
    };
public:
    class cCraftUpGradeItemList : public MtObject
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
        cCraftUpGradeItemList();
        virtual ~cCraftUpGradeItemList();
        void setUID(MT_CTSTR UID);
        MT_CTSTR getUID() const;
        void setBagType(u32 type);
        u32 getBagType() const;
        void setItemID(u32 itemId);
        u32 getItemID() const;
        void setSortNo(u32 sort);
        u32 getSortNo() const;
        void setItemNum(u32 num);
        u32 getItemNum() const;
        void setQuality(u32 quality);
        u32 getQuality() const;
        void setElementNum(u32 num);
        u32 getElementNum() const;
        void setEquipPoint(u32 point);
        u32 getEquipPoint() const;
        void setCustomSortNo(u8 no);
        u32 getCustomSortNo() const;
    private:
        MtString mWstrUID;  // offset: 0x8
        u32 mItemId;  // offset: 0x10
        u32 mBagType;  // offset: 0x14
        u32 mSortNo;  // offset: 0x18
        u32 mItemNum;  // offset: 0x1c
        u32 mQuality;  // offset: 0x20
        u32 mElementNum;  // offset: 0x24
        u32 mEquipPoint;  // offset: 0x28
        u8 mCustomSortNo;  // offset: 0x2c
    public:
        static MyDTI DTI;
    };
public:
    class cCraftIrReductionData : public MtObject
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
        cCraftIrReductionData();
        // Address: 0x01ac25f0 - 0x01ac25f1 (1 bytes)
        virtual ~cCraftIrReductionData() {}
        void setRate(u8 Rate);
        u8 getRate();
    private:
        u8 mRate;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cCraftRecipeControl : public MtObject
    {
        // inferred: cMenuGetCraftRecipeToServer::moveGetCraftRecipeToServer names sCraftManager::cCraftRecipeControl::mState
        friend class cMenuGetCraftRecipeToServer;
    public:
        enum RECIPE_STATE
        {
            RECIPE_STATE_NONE = 0,
            RECIPE_STATE_LOADING = 1,
            RECIPE_STATE_LOAD_END = 2,
            RECIPE_STATE_END = 3,
        };
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
        cCraftRecipeControl();
        virtual ~cCraftRecipeControl();
        void init();
        void end();
        void setLoadStatus(RECIPE_STATE state);
        RECIPE_STATE getLoadStatus();
        void setRecipe(sCraftManager::RECIPE_TYPE type, void* packet);
        void setRecipeDesignate(sCraftManager::RECIPE_TYPE type, void* packet);
        u32 getOffsetNum();
        void createRecipeList(u32 rankCap);
        MtTypedArray<rCraftRecipe::cCraftRecipe>* getMasterRecipeList();
        rCraftRecipe::cCraftRecipe* getRecipeDataToRecipeId(u32 recipeId);
        rCraftRecipe::cCraftRecipe* getRecipeDataToItemId(u32 itemId);
    private:
        u32 setCreateRecipeSub(nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category, MDataCraftRecipeVec& list);
        void setCreateRecipe(void* packet);
        void setCreateRecipeDesignate(void* packet);
        void setGradeupRecipe(void* packet);
        void setGradeupRecipeDesignate(void* packet);
    private:
        u32 mRecipeOffsetNum;  // offset: 0x8
        RECIPE_STATE mState;  // offset: 0xc
        MtTypedArray<rCraftRecipe::cCraftRecipe> mMasterRecipeList;  // offset: 0x10
        MtTypedArray<cCraftRecipe::cCraftRecipeList> mRecipeList;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
public:
    class stRecipeRequest : public MtObject
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
        stRecipeRequest();
        // Address: 0x01ac2300 - 0x01ac2301 (1 bytes)
        virtual ~stRecipeRequest() {}
    public:
        sCraftManager::RECIPE_TYPE mType;  // offset: 0x8
        nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE mCategory;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class PawnCost : public MtObject
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
        PawnCost();
        // Address: 0x01ac2180 - 0x01ac2181 (1 bytes)
        virtual ~PawnCost() {}
        void setPawnId(u32 pawnId);
        void setPawnCost(u32 costLv);
        void setPawnCraftCount(u32 count);
        void setPawnRank(u32 rank);
        void setPawnState(u8 state);
        void setNoLimitCostSkill(bool isSet);
        u32 getPawnCost();
        u32 getPawnId();
        u32 getPawnCraftCount();
        u32 getPawnRank();
        u8 getPawnState();
        bool isNoLimitCostSkill();
    private:
        u32 mPawnId;  // offset: 0x8
        u32 mCostLv;  // offset: 0xc
        u32 mCraftCount;  // offset: 0x10
        u32 mRank;  // offset: 0x14
        bool mIsNoLimitCostSkill;  // offset: 0x18
        u8 mState;  // offset: 0x19
    public:
        static MyDTI DTI;
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
    static sCraftManager* getInstance();
    sCraftManager();
    virtual ~sCraftManager();
    void init();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    void setRno(u32 Rno);
    u32 getRno();
    void setRno0(u8);
    u8 getRno0();
    void setRno1(u8);
    u8 getRno1();
    void setRno2(u8);
    u8 getRno2();
    void setRno3(u8);
    u8 getRno3();
    bool setCraftSystem();
    void stopCraftSystem();
    CRAFT_RESULT getResult();
    RESULT resultCreateRecipeItem();
    cItemParam* getRecipeItem(u32 targetNo, u32 selectNo);
    bool reqAddRecordRecipeData(cItemParam* pItemParam, u32 targetNo);
    RESULT resultAddRecordRecipe();
    bool addRecordRecipeData(u32 recipeNo);
    RecordRecipe* getRecordRecipeData(u32 index);
    u32 getRecipeNum();
    bool addCreateCraftItem(CreateItem& cratItem);
    MtTypedArray<CDataCommonU32>& getCraftCreateRecipeList();
    void loadCommonCraftResource();
    void releaseCommonCraftResource();
    void loadCraftResource();
    void releaseCraftResource();
    cCraftRecipe* getCraftRecipe(u32 type);
    u32 getItemNum(u32 target, u32 itemNo);
    u32 getSupportNum(u32 pawnId);
    u32 getSupportNumMax();
    u32 getSupportNumFromPassNum(u32 passNum);
    cCraftPawnCtrl* getCraftCtrl();
    cCraftRankUp* getCraftRankUp();
    cCraftUpGrade* getCraftUpGrade();
    cCraftSkill* getCraftSkill();
    cCraftPlusItem* getCraftPlusParam();
    cCraftRecipeControl* getCraftRecipeCtrl(RECIPE_TYPE type, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    u32 getPawnSkillLv(u32 pawnId, u32 skill);
    u32 getPawnSkillLv(cPawnListParam* pPawnParam, u32 SkillID);
    u32 getMyPawnTotalSkillLv(u32 PawnId);
    MT_CTSTR getPawnName(u32 pawnId);
    u32 getPawnRank(u32 pawnId);
    u32 getPawnRankLimit(u32 pawnId);
    u32 getCraftRankLimit(u32 myLimit);
    u32 getPawnCraftExp(u32 pawnId);
    u32 getPawnCraftNextExp(u32 rank);
    u32 getPawnCraftNextExp(rCraftElementExp* pCraftExp, u32 rank);
    bool isCraftMoneyToMyPawnId(u32 recipeId, u32 pawnId, u32 type);
    bool sortByCost(const PawnCost* src, const PawnCost* dst, u32 param);
    u32 getMyPawnCraftState(u32 pawnId);
    s32 getMyPawnNum();
    MT_CTSTR getMyPawnName(u32 index);
    u8 getMyPawnState(u32 index);
    u8 getMyPawnStateToPawnId(u32 pawnId);
    CDataCraftProgress* getMyPawnCraftTaskInfo(u32 pawnId);
    u32 getMyPawnRankAll();
    u32 getMyPawnRank(u32 index);
    u32 getMyPawnSkillLv(u32 index, u32 skill);
    u32 getMyPawnCraftMoreTime(u32 index);
    u32 getMyPawnCraftPoint(u32 index);
    u32 getMyPawnCraftExp(u32 index);
    u32 getMyPawnCraftNextExp(u32 index);
    u32 getMyPawnId(u32 index);
    bool isMyPawn(u32 pawnId);
    s32 getRentalPawnNum();
    MT_CTSTR getRentalPawnName(u32 index);
    u32 getRentalPawnRank(u32 index);
    u32 getRentalPawnSkillLv(u32 index, u32 skill);
    u32 getRentalPawnCraftMoreTime(u32 index);
    u32 getRentalPawnId(u32 index);
    u8 getRentalPawnStateToPawnId(u32 pawnId);
    bool isRentalPawn(u32 pawnId);
    void setCraftMenuType(u32 type);
    u32 getCraftMenuType();
    void resetCraftMenuType();
    void setSupportSelectting(bool isSelect);
    bool isSupportSelectting();
    bool isSupportSelectPawnId(u32 pawnId);
    bool isSupportSelectPawn(u32 select);
    bool isSupportSelectRentalPawn(u32 select);
    void initCraftRegulate();
    void setCraftColorRegulateState(COLOR_REGULATE_STATE state);
    COLOR_REGULATE_STATE getCraftColorRegulateState();
    void reqCraftColorRegulateItemList();
    void setCraftColorRegulateItemList(void* packet);
    void releaseCraftColorRegulateItemList();
    bool isEnableCraftColorChange(u32 itemId);
    void initCraftIrReductionData();
    void setCraftIrReductionDataState(IR_REDUCTION_DATA_STATE state);
    IR_REDUCTION_DATA_STATE getCraftIrReductionDataState();
    void reqCraftIrReductionDataList();
    void setCraftIrReductionDataList(void* packet);
    u8 getCraftIrReductionData(u8 pawnType, u8 skillType);
    void releaseCraftIrReductionDataList();
    void initCraftRecipeAll();
    void initCraftRecipe(RECIPE_TYPE recipeType, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    RECIPE_QUE_STATE moveCraftRecipeQue();
    bool reqCraftRecipeQue(RECIPE_TYPE recipeType, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    RECIPE_REQ_STATE reqCraftRecipe(RECIPE_TYPE recipeType, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    RECIPE_REQ_STATE reqCraftRecipeDesignate(RECIPE_TYPE recipeType, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE convRecipeCategory(u32 itemId);
    u32 convCategoryToIndex(nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    void noticeRecipeUpData(void* packet);
    CommonU32Vec* getDesignateList();
    bool isDesignateListToCategory(RECIPE_TYPE recipeType, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category, CommonU32Vec& list);
    void eraseCreateDesignateList(CommonU32Vec& list);
    void eraseGradeupDesignateList(MDataCraftGradeupRecipeVec& list);
    bool isCraftRecipeLoadEnd();
    bool reqCreateRecipeToBaggage(CommonU32Vec& list);
    BAGGAGE_MATERIAL_STATE waitCreateRecipeToBaggage();
    void clearCreateRecipeToBaggage();
    bool reqUpGradeRecipeToBaggage(CommonU32Vec& list);
    BAGGAGE_MATERIAL_STATE waitUpGradeRecipeToBaggage();
    void clearGradeRecipeToBaggage();
private:
    bool isCraftRecipeLoadEnd(RECIPE_TYPE recipeType, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    void createPlusItemListSub(rItemList::MATERIAL_CATEGORY materialType, u32 rank);
public:
    void reqBaggageMaterialInfo(rItemList::MATERIAL_CATEGORY category);
    BAGGAGE_MATERIAL_STATE waitBaggageMaterialInfo();
    void clearPlusItemList();
    void createPlusItemList(u32 type, u32 rank);
    void createElementItemList(u32 type);
    void createColorItemList();
    u32 getPlusItemListNum();
    cCraftUpGradeItemList* getPlusItemList(u32 index);
    rItemList::rItemParam* getPlusItemListToItemParam(u32 index);
    void clearProcessItemList(u32 category);
    void clearProcessItemListAll();
    void createProcessItemList(u32 listType);
    u32 convEquipCategoryToIndex(nCharacterData::EQUIP_CATEGORY category);
    u32 getProcessItemCategoryNum();
    u32 getProcessItemCategoryNum(nCharacterData::EQUIP_CATEGORY category);
    cCraftUpGradeItemList* getProcessItemList(u32 itemCate, u32 index);
    rItemList::rItemParam* getProcessItemListToItemParam(nCharacterData::EQUIP_CATEGORY category, u32 index);
    cItemParam* getProcessItemListToSlotParam(nCharacterData::EQUIP_CATEGORY category, u32 index);
    cItemParam* getProcessItemToSlotParam(MT_CTSTR UID);
    u32 getCapPassNum(u32 cap, rCraftCapPass* pRes);
    rCraftCapPass* getCraftCapRes();
    cCraftCapPassData* getCraftCapDataFromStartLv(rCraftCapPass* pCapRes, u32 startLv);
    cCraftCapPassData* getCraftCapDataFromCapLv(rCraftCapPass* pCapRes, u32 capLv);
    bool isCappingToPawnId(u32 pawnId);
    u32 getCapRecipeToPawnId(u32 pawnId);
    bool isNowCapRecipe(u32 recipeId);
    void addCraftNotice(u32 pawnId);
    void eraceCraftNotice();
    u32 getCraftNoticeListNum();
    void setItemGradeMax(u32 max);
    u32 getItemGradeMax() const;
private:
    void createRecipeItemCallBack(void* param);
    void addRecordRecipeCallBack(void* param);
public:
    u64 getCraftUpGradeExpMax(u32 rank);
    u64 getCraftUpGradeExpMax(u32 rank, rCraftUpGradeExp* pRes);
    u32 getCraftElementGold(u16 rank);
    cCraftElementExpData* getCraftElementExpData(u16 rank);
    u32 getCraftColorGold(u16 rank);
    cCraftElementExpData* getCraftColorExpData(u16 rank);
    MtTypedArray<CDataEquipElementParam>* isCraftElementRelease(cItemParam* pItemParam);
    void resetKickParty();
    void initKickParty();
    void moveKickParty();
    u8 getKickPartyResult() const;
private:
    void initCategoryCraftPlusMaterial();
public:
    bool getCategoryCraftPlusMaterial(nCharacterData::EQUIP_CATEGORY category);
    void setCategoryCraftPlusMaterial(MtTypedArray<CDataCommonU32>& list);
    void setSupportNumList(MtTypedArray<CDataCommonU32>& list);
private:
    f32 mBaggageReqTimer;  // offset: 0x14
    u8 mMaterialCache;  // offset: 0x18
    MtTypedArray<cCraftFinishNotice> mNoticeList;  // offset: 0x20
    u32 mGradeMax;  // offset: 0x40
    u32 mKickPartyPawnId[8];  // offset: 0x44
    u8 mKickPartyCtr;  // offset: 0x64
    u8 mKickPartyRno;  // offset: 0x65
    u8 mKickPartyResult;  // offset: 0x66
    u8 mMasterPlusCategory[13];  // offset: 0x67
    u8 mMasterSupportNumData[3];  // offset: 0x74
    union
    {
    public:
        struct
        {
        public:
            u8 mRno0;  // offset: 0x0
            u8 mRno1;  // offset: 0x1
            u8 mRno2;  // offset: 0x2
            u8 mRno3;  // offset: 0x3
        };  // offset: 0x0
        u32 mRno;  // offset: 0x0
    };  // offset: 0x78
    CRAFT_RESULT mResult;  // offset: 0x7c
    u32 mState;  // offset: 0x80
    bool mIsCreateRecipeItem;  // offset: 0x84
    RESULT mResultCreateRecipeItem;  // offset: 0x88
    bool mIsRecordRecipe;  // offset: 0x8c
    RESULT mResultRecordRecipe;  // offset: 0x90
    u32 mRecipeNo;  // offset: 0x94
    bool mIsCreateItem;  // offset: 0x98
    cAddExp mAddExp;  // offset: 0xa0
    MtTypedArray<RecordRecipe> mRecordRecipeList;  // offset: 0xb0
    MtTypedArray<CreateItem> mCreateItemList;  // offset: 0xd0
    cCraftSkill mCraftSkill;  // offset: 0xf0
    cCraftRecipe mCraftRecipe;  // offset: 0x108
    cCraftRecipe mCraftRecipeUpGrade;  // offset: 0x238
    cCraftPlusItem mCraftPlusItem;  // offset: 0x368
    cCraftPawnCtrl mCraftCtrl;  // offset: 0x378
    cCraftRankUp mCraftRankUp;  // offset: 0x558
    cCraftUpGrade mCraftUpGrade;  // offset: 0x588
    u32 mCraftMenuType;  // offset: 0x5d8
    bool mIsSupportSelectting;  // offset: 0x5dc
    MtTypedArray<cCraftUpGradeItemList> mAddItemList;  // offset: 0x5e0
    MtTypedArray<cCraftUpGradeItemList> mProcessItemList[10];  // offset: 0x600
    rCraftCapPass* mpCraftCap;  // offset: 0x740
    rCraftUpGradeExp* mpCraftupGradeExp;  // offset: 0x748
    rCraftElementExp* mpCraftElementExp;  // offset: 0x750
    rCraftElementExp* mpCraftColorExp;  // offset: 0x758
    rCraftElementExp* mpCraftExp;  // offset: 0x760
    COLOR_REGULATE_STATE mCraftColorRegulateState;  // offset: 0x768
    IR_REDUCTION_DATA_STATE mCraftIrReductionDataState;  // offset: 0x76c
    MtTypedArray<cCraftIrReductionData> mCraftMainPawnIrReductionDataList[11];  // offset: 0x770
    MtTypedArray<cCraftIrReductionData> mCraftSupportPawnIrReductionDataList[11];  // offset: 0x8d0
    cCraftRecipeControl mRecipeControl[27];  // offset: 0xa30
    cCraftRecipeControl mGradeupRecipeControl[27];  // offset: 0x12a0
    CommonU32Vec mDesignateList;  // offset: 0x1b10
    MtTypedArray<stRecipeRequest> mRequest;  // offset: 0x1b30
public:
    static MyDTI DTI;
    static const u32 ColorChangeGrade = 1;
    static const u32 RecordRecipeMax = 10;
private:
    static sCraftManager* mpInstance;
    static const nCharacterData::EQUIP_CATEGORY mEquipCategoryTbl[];
public:
    static const u32 CREATE_PROCESS_ITEM_CATEGORY_NUM = 10;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline sCraftManager* sCraftManager::getInstance() {
    return ::sCraftManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sCraftManager::cCraftFinishNotice::cCraftFinishNotice() {
    this->mPawnId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sCraftManager::cAddExp::cAddExp() {
    this->mRno = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sCraftManager::RecordRecipe::RecordRecipe() {
    this->mRecipeNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sCraftManager::cCraftRankUp::cCraftRankUp() {
    this->mIsRankUp = false;
    this->mBonusExp = static_cast<u32>(0);
    this->mTotalExp = static_cast<u32>(0);
    this->mPawnId = static_cast<u32>(0);
    this->mAddExp = static_cast<u32>(0);
    this->mTotalCraftPoint = static_cast<u32>(0);
    this->mCraftReqResult = static_cast<sCraftManager::cCraftRankUp::RESULT>(0);
    this->mCraftRank = static_cast<u32>(0);
    this->mAddCraftPoint = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sCraftManager::cCraftIrReductionData::cCraftIrReductionData() {
    this->mRate = static_cast<u8>(100);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline sCraftManager::cCraftRecipeControl::RECIPE_STATE sCraftManager::cCraftRecipeControl::getLoadStatus() {
    return this->mState;
}

// Inline, no code of its own: checked where it is inlined.
inline sCraftManager::stRecipeRequest::stRecipeRequest() {
    this->mType = static_cast<sCraftManager::RECIPE_TYPE>(4);
    this->mCategory = static_cast<nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline sCraftManager::PawnCost::PawnCost() {
    this->mIsNoLimitCostSkill = false;
    this->mState = static_cast<u8>(0);
    this->mCraftCount = static_cast<u32>(0);
    this->mRank = static_cast<u32>(0);
    this->mPawnId = static_cast<u32>(0);
    this->mCostLv = static_cast<u32>(0);
}
