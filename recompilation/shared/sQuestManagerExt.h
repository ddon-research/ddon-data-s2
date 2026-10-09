#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtString.h"
#include "MtTime.h"
#include "Quest.h"
#include "Warp.h"
#include "cCharacterData.h"
#include "cSystem.h"
#include "nDDOUtility.h"
#include "nLayout.h"
#include "nNet.h"
#include "nQuest.h"
#include "sGUIExt.h"

// Forward declarations
class CDataCycleContentsRewardRecord;
class CDataDeliveredItem;
class CDataEndContentsGroup;
class CDataFavoriteWarpPoint;
class CDataItemUIDList;
class CDataMainQuestList;
class CDataOrderConditionInfo;
class CDataPriorityQuest;
class CDataQuestOrderList;
class CDataRewardBoxRecord;
class CDataSetQuestInfoList;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtTime;
class MtVector3;
class cActiveQuestManager;
class cAreaReleaseManager;
class cCycleQuestManagerBase;
class cCycleQuestSubCategoryManager;
class cJobMasterCtrl;
class cNamedParam;
class cNetGameServer;
class cPRTManager;
class cQuestDeliverManager;
class cQuestEventArg;
class cQuestEventManager;
class cQuestFunctionManagerBase;
class cQuestManagerBase;
class cQuestMarkerManager;
class cQuestMemoryPool;
class cQuestPartyManager;
class cQuestPhaseManager;
class cQuestResourceLoadManager;
class cQuestResourceManager;
class cQuestSvNoticeManager;
class cQuestSvRequestManager;
class cQuestTask;
class cTalkMsgData;
namespace nLayout { struct stLayoutID; }
namespace nNet { struct stEntryBoardItemInfo; }
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cCycleContentsBorderRewardInfo; }
namespace nQuest { class cCycleContentsInfo; }
namespace nQuest { class cCycleContentsRankingInfo; }
namespace nQuest { class cCycleContentsRankingRewardInfo; }
namespace nQuest { class cCycleContentsResultInfo; }
namespace nQuest { class cCycleContentsSituationInfo; }
namespace nQuest { class cGUIActiveData; }
namespace nQuest { class cGUIAreaMasterData; }
namespace nQuest { class cGUIBoardData; }
namespace nQuest { class cGUIDeliveryData; }
namespace nQuest { class cGUIListData; }
namespace nQuest { class cGUINewspaperRecommededQuestInfo; }
namespace nQuest { class cGUINewspaperSetQuestInfo; }
namespace nQuest { class cGUINewspaperSetQuestInfoList; }
namespace nQuest { class cGUINewspaperSetQuestOpenDateInfo; }
namespace nQuest { class cPartyBonusInfo; }
namespace nQuest { class cQuestDeliverRequestInfo; }
namespace nQuest { class cQuestDeliveredInfo; }
namespace nQuest { class cQuestMarker; }
namespace nQuest { class cTalkData; }
class uCharacter;
class uControl;
class uGUIPopTopSel;
class uOmModel;

// Declarations
class sQuestManagerExt;

// Type aliases from DWARF
using CEndContentsGroup = CDataEndContentsGroup;
using CMainQuestList = CDataMainQuestList;
using CQuestOrderList = CDataQuestOrderList;
using CSetQuestInfoList = CDataSetQuestInfoList;
using CycleContentsRewardRecordVec = MtTypedArray<CDataCycleContentsRewardRecord>;
using ItemUIDListVec = MtTypedArray<CDataItemUIDList>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using OrderConditionInfoVec = MtTypedArray<CDataOrderConditionInfo>;
using PriorityQuestVec = MtTypedArray<CDataPriorityQuest>;
using RewardBoxRecordVec = MtTypedArray<CDataRewardBoxRecord>;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
namespace nQuest { using CycleContentsBorderRewardList = MtTypedArray<nQuest::cCycleContentsBorderRewardInfo>; }
namespace nQuest { using CycleContentsInfoArray = MtTypedArray<nQuest::cCycleContentsInfo>; }
namespace nQuest { using CycleContentsRankingList = MtTypedArray<nQuest::cCycleContentsRankingInfo>; }
namespace nQuest { using CycleContentsRankingRewardList = MtTypedArray<nQuest::cCycleContentsRankingRewardInfo>; }
namespace nQuest { using GUIActiveDataArray = MtTypedArray<nQuest::cGUIActiveData>; }
namespace nQuest { using GUIAreaMasterDataArray = MtTypedArray<nQuest::cGUIAreaMasterData>; }
namespace nQuest { using GUIBoardDataArray = MtTypedArray<nQuest::cGUIBoardData>; }
namespace nQuest { using GUIDeliveryDataArraay = MtTypedArray<nQuest::cGUIDeliveryData>; }
namespace nQuest { using GUIEventBoardDataArray = MtTypedArray<nQuest::cGUIEventBoardData>; }
namespace nQuest { using GUIListDataArray = MtTypedArray<nQuest::cGUIListData>; }
namespace nQuest { using GUINewspaperRecommededQuestInfoArray = MtTypedArray<nQuest::cGUINewspaperRecommededQuestInfo>; }
namespace nQuest { using GUINewspaperSetQuestOpenDateInfoArray = MtTypedArray<nQuest::cGUINewspaperSetQuestOpenDateInfo>; }
namespace nQuest { using PartyBonusInfoArray = MtTypedArray<nQuest::cPartyBonusInfo>; }
namespace nQuest { using QuestIdArray = MtTypedArray<nQuest::QUEST_ID>; }
namespace nQuest { using QuestMarkerArray = MtTypedArray<nQuest::cQuestMarker>; }
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sQuestManagerExt : public cSystem
{
    // inferred: cNetGameServer::getCycleContentsSituationInfoList names sQuestManagerExt::mIsGetCycleContentsInfoList
    friend class cNetGameServer;
    // inferred: uGUIPopTopSel::evCtrlChkout names sQuestManagerExt::mNowCallEntryBoardContentsType
    friend class uGUIPopTopSel;
public:
    enum QUEST_RET
    {
        RET_NONE = 0,
        RET_SUCCEEDED = 1,
        RET_FAILED = 2,
        RET_REQUEST = 3,
    };
    enum QUEST_UI_RESULT
    {
        RESULT_NONE = 0,
        RESULT_YES = 1,
        RESULT_NO = 2,
        RESULT_FAILED = 3,
    };
    enum
    {
        CLEAR_BUFFER_NUM = 4,
    };
    enum
    {
        AREA_NUM = 17,
    };
    enum R0
    {
        R0_NONE = 0,
        R0_REQUEST = 1,
        R0_WAIT_RESULT = 2,
        R0_END = 3,
    };
    enum
    {
        RNO_BARRICADE_NONE = 0,
        RNO_BARRICADE_CHECK = 1,
        RNO_BARRICADE_FADE_OUT = 2,
        RNO_BARRICADE_EX_CHECK_IN = 3,
        RNO_BARRICADE_EX_CHECK_OUT = 4,
        RNO_BARRICADE_EX_FADE_OUT = 5,
    };
    enum
    {
        BGM_TYPE_FIELD = 0,
        BGM_TYPE_BATTLE = 1,
        BGM_TYPE_EVENT = 2,
        BGM_TYPE_NUM = 3,
    };
public:
    class MyDTI;
    struct stEndContentsInfo;
    class cQstFunctionCheck;
    class cKilledEnemy;
    class cManagerInfo;
    class cTouchOmInfo;
    class cFunctionInfo;
    class cSystemLogNode;
    class cClearedQuestInfo;
    class cTimer;
    class cCallQuestAnnounce;
    class cUnreleasedArea;
    class cSayInfo;
    struct stAreaBonusInfo;
public:
    using KilledEnemyArray = MtTypedArray<sQuestManagerExt::cKilledEnemy>;
    using ManagerInfoArray = MtTypedArray<sQuestManagerExt::cManagerInfo>;
    using FunctionInfoArray = MtTypedArray<sQuestManagerExt::cFunctionInfo>;
    using SystemLogNodeQueue = MtTypedArray<sQuestManagerExt::cSystemLogNode>;
    using ClearedQuestInfoArray = MtTypedArray<sQuestManagerExt::cClearedQuestInfo>;
    using CallQuestAnnounceArray = MtTypedArray<sQuestManagerExt::cCallQuestAnnounce>;
    using UnreleasedAreaArray = MtTypedArray<sQuestManagerExt::cUnreleasedArea>;
    using SayInfoArray = MtTypedArray<sQuestManagerExt::cSayInfo>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stEndContentsInfo
    {
    public:
        stEndContentsInfo();
    public:
        nQuest::QUEST_ID mQuestId;  // offset: 0x0
        bool mIsClear;  // offset: 0x10
        u32 mPlayTimeMillSec;  // offset: 0x14
    };
public:
    class cQstFunctionCheck : public MtObject
    {
    public:
        cQstFunctionCheck(u32 FunctionId, nQuest::SCHEDULE_ID ScheduleId, s32 Param);
    public:
        u32 mFunctionId;  // offset: 0x8
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x10
        s32 mParam;  // offset: 0x20
    };
public:
    class cKilledEnemy : public MtObject
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
        u32 getStageNo() const;
        u32 getEnemyId() const;
        u32 getKilledNum() const;
        void incrKilledNum();
        cKilledEnemy();
        cKilledEnemy(u32 stageNo, u32 enemyId);
        virtual ~cKilledEnemy();
    protected:
        u32 mStageNo;  // offset: 0x8
        u32 mEnemyId;  // offset: 0xc
        u32 mKilledNum;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cManagerInfo : public MtObject
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
        bool isSameType(nQuest::QUEST_TYPE type) const;
        nQuest::QUEST_TYPE getQuestType() const;
        cQuestManagerBase* getQuestManager();
        const cQuestManagerBase* getQuestManager() const;
        cManagerInfo();
        cManagerInfo(nQuest::QUEST_TYPE type, cQuestManagerBase* pMgr);
        virtual ~cManagerInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::QUEST_TYPE mType;  // offset: 0x8
        cQuestManagerBase* mpMgr;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cTouchOmInfo : public MtObject
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
        const nLayout::stLayoutID& getLayoutId() const;
        u32 getSetNo() const;
        u32 getQuestSequence() const;
        bool isQuestSet() const;
        u32 getUniqueId() const;
        cTouchOmInfo();
        cTouchOmInfo(const nLayout::stLayoutID& layoutId, u32 setNo, u32 questSeq);
        virtual ~cTouchOmInfo();
    protected:
        nLayout::stLayoutID mLayoutId;  // offset: 0x8
        u32 mSetNo;  // offset: 0xc
        u32 mQuestSeq;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cFunctionInfo : public MtObject
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
        bool isSameType(nQuest::FUNCTION_TYPE type) const;
        nQuest::FUNCTION_TYPE getFunctionType() const;
        cQuestFunctionManagerBase* getFunctionManager();
        const cQuestFunctionManagerBase* getFunctionManager() const;
        cFunctionInfo();
        cFunctionInfo(nQuest::FUNCTION_TYPE type, cQuestFunctionManagerBase* pMgr);
        virtual ~cFunctionInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::FUNCTION_TYPE mType;  // offset: 0x8
        cQuestFunctionManagerBase* mpFuncMgr;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cSystemLogNode : public MtObject
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
        bool isDelete() const;
        void update();
        cSystemLogNode();
        cSystemLogNode(MT_CTSTR message, nQuest::QUEST_ID questId, MT_CTSTR analizeMsg0, MT_CTSTR analizeMsg1, bool withAnnounce, u32 filter, bool isWarning);
        virtual ~cSystemLogNode();
    protected:
        MtString mMessage;  // offset: 0x8
        MtString mAnalizeMsg0;  // offset: 0x10
        MtString mAnalizeMsg1;  // offset: 0x18
        nQuest::QUEST_ID mQuestId;  // offset: 0x20
        u32 mFilter;  // offset: 0x30
        bool mIsDelete;  // offset: 0x34
        bool mWithAnnounce;  // offset: 0x35
        bool mIsWarning;  // offset: 0x36
    public:
        static MyDTI DTI;
    };
public:
    class cTimer : public MtObject
    {
    public:
        class MyDTI;
        class cCallbackElapsedTime;
    public:
        using CallbackElapsedTimeArray = MtTypedArray<sQuestManagerExt::cTimer::cCallbackElapsedTime>;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cCallbackElapsedTime : public MtObject
        {
        public:
            cCallbackElapsedTime(u32 time, MtObject* pClass, void(MtObject::*pCallback)());
            void callback();
            u32 getTime() const;
        protected:
            MtObject* mpCalss;  // offset: 0x8
            void(MtObject::*mpCallback)();  // offset: 0x10
            u32 mTime;  // offset: 0x20
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
        t64 getStartTime() const;
        t64 getFinishTime() const;
        f32 getMeasuringTime() const;
        f32 getElapsedTime() const;
        f32 getRemainingTime() const;
        bool hasStarted() const;
        bool hasStoped() const;
        void setCallbackFinish(MtObject* pClass, void(MtObject::*pCallback)());
        void zeroClear();
    protected:
        t64 getCurrentTime() const;
        f32 getDeltaSec() const;
    public:
        bool start(t64 startTime, t64 finishTime);
        bool start(t64 finishTime);
        bool startMeasuringTime(u32 measuringTime);
        void finish(bool isCallbackFinish);
        void finish();
        void update();
        bool updateFinishTimer(t64 finishTime, f32& outAddTime);
        void addCallbackElapsedTime(u32 time, MtObject* pClass, void(MtObject::*pCallback)());
        void deleteAllCallbackElapsedTime();
        void stopTimer();
        void restartTimer(t64 finishTime);
    protected:
        f32 correctTimer(f32 timer) const;
    public:
        cTimer();
        virtual ~cTimer();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        CallbackElapsedTimeArray mElapsedTimeArray;  // offset: 0x8
        t64 mStartTime;  // offset: 0x28
        t64 mFinishTime;  // offset: 0x30
        t64 mStopTime;  // offset: 0x38
        MtObject* mpCalssCallbackFinish;  // offset: 0x40
        void(MtObject::*mpCallbackFinish)();  // offset: 0x48
        f32 mMeasuringTime;  // offset: 0x58
        f32 mRemainingTime;  // offset: 0x5c
        bool mHasStarted;  // offset: 0x60
    public:
        static MyDTI DTI;
    };
public:
    class cCallQuestAnnounce : public MtObject
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
        bool isDelete() const;
        void setParam(const cQuestTask* pTask, s32 announceType, s32 purposeNo, bool isDiscovered, s32 num);
        void update();
        cCallQuestAnnounce();
        virtual ~cCallQuestAnnounce();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        sGUIExt::stQueueAnnounce mInfo;  // offset: 0x8
        nQuest::QUEST_ID mQuestId;  // offset: 0x78
        s32 mPurposeNo;  // offset: 0x88
        bool mIsDelete;  // offset: 0x8c
    public:
        static MyDTI DTI;
    };
public:
    class cUnreleasedArea : public MtObject
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
        u32 getAreaId() const;
        cUnreleasedArea();
        cUnreleasedArea(u32 areaId);
        virtual ~cUnreleasedArea();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mAreaId;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cSayInfo : public MtObject
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
        nQuest::QUEST_ID getQuestId() const;
        u32 getMsgIdx() const;
        cSayInfo();
        cSayInfo(nQuest::QUEST_ID questId, u32 msgIdx);
        virtual ~cSayInfo();
    protected:
        nQuest::QUEST_ID mQuestId;  // offset: 0x8
        u32 mMsgIdx;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    struct stAreaBonusInfo
    {
    public:
        u32 mAreaId;  // offset: 0x0
        u32 mMaxRate;  // offset: 0x4
    };
public:
    class cClearedQuestInfo : public MtObject
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
        void update();
    protected:
        void callbackFinish();
    public:
        cClearedQuestInfo();
        cClearedQuestInfo(nQuest::SCHEDULE_ID scheduleId);
        virtual ~cClearedQuestInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x8
        sQuestManagerExt::cTimer mTimer;  // offset: 0x18
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
    bool isReqDeliverItem() const;
    const nQuest::cQuestDeliverRequestInfo* getQuestDeliverRequestInfo(const nQuest::SCHEDULE_ID& scheduleId) const;
    const nQuest::cQuestDeliveredInfo* getQuestDeliveredInfo(const nQuest::SCHEDULE_ID& scheduleId) const;
    bool fulfillDeliver(const nQuest::SCHEDULE_ID& scheduleId) const;
    void decideDeliverItem(const nQuest::SCHEDULE_ID& scheduleId);
    void deliverItem(const nQuest::SCHEDULE_ID& scheduleId, ItemUIDListVec& itemUIDList);
    void updateDeliveredInfo(nQuest::SCHEDULE_ID scheduleId, u32 charcterId, const MtTypedArray<CDataDeliveredItem>& deliveredList);
    nQuest::SCHEDULE_ID getEventBoardQuestAcceptedScheduleId() const;
    bool isTouchOm(u32 stageNo, u32 groupNo, s32 setNo) const;
    bool isTouchOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq) const;
    bool isTouchOm(u32 uniqueId) const;
    bool isTouchOm(u32 uniqueId, u32 questSeq) const;
    bool isReleaseOm(u32 stageNo, u32 groupNo, s32 setNo) const;
    bool isReleaseOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq) const;
    bool isDogmaOrb() const;
    bool isEndTextOm(u32 stageNo, u32 groupNo, s32 setNo) const;
    bool isEndTextOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq) const;
    u32 getTalkEndNpcId() const;
protected:
    bool isNoticeType(nQuest::NOTICE_TYPE noticeType) const;
    void onNoticeType(nQuest::NOTICE_TYPE noticeType);
public:
    void notifyTalkEnd(u32 npcId);
    void notifyReloadMasterData();
    void notifyAddItem(u8 itemType);
    void notifySetTouchOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq);
    void notifyReleaseTouchOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq);
    void notifyClearSetQuest(u32 areaId);
    void notifyEntryParty();
    void notifyLeaveParty();
    void notifyDogmaOrb();
    void notifyEventBoardQuestAccepted(const nQuest::SCHEDULE_ID& scheduleId);
    void notifyTouchEventBoard();
    void notifyOpenEntryRaidBoss();
    void notifyOpenEntryFortDefense();
    void notifyOpenJobMaster();
    void notifyTouchRimStone();
    void notifyGetAchievement();
    void notifyEndTalkSpecial();
    void notifyClearQuest(const nQuest::SCHEDULE_ID& scheduleId);
    void notifyClearPartyQuest(const nQuest::SCHEDULE_ID& scheduleId);
    void notifyEndTextOm(u32 stageNo, u32 groupNo, s32 setNo, u32 questSeq);
    void notifySetSkill();
    void notifyOpenAreaMaster();
    void notifyOpenNewspaper();
    void notifyOpenQuestBoard();
    void notifyOrderLightQuest();
    void notifyOrderWorldQuest();
    void notifyLostMainPawn();
    void notifyHugeble();
    void notifyOpenAreaMasterSupplies();
    void notifyOpenEntryBoard();
    void notifyNoticeInterruptContents();
    void notifyOpenRetrySelect();
    void notifyNoticePartyInvite();
    void notifyPartyReward();
    void notifyOpenCraftExam();
    void notifyLevelUpCraft();
    void notifyClearLightQuest();
    void notifyOpenJobMasterReward();
    void notifyKilledAreaBoss();
    void notifyOpenWarehouse();
    void notifyOpneRewardBox();
    void notifySearchClan();
    void notifyOpenAreaList();
    void notifyPresentPartnerPawn();
    void notifyReleasePortal();
    void notifyHasAppraiseItem();
    void notifyDivideWarpPlayer(bool isSuccess, u32 characterId);
    void notifyOrderPawnQuest();
    void notifyOpenPPShop();
    void notifyTouchClanBoard();
    void notifyOneOffGather();
    void addCheckSayMessage(nQuest::QUEST_ID questId, u32 msgIdx);
    void removeCheckSayMessage(nQuest::QUEST_ID questId);
    void checkSayMessage(MT_CTSTR message);
protected:
    bool matchMessage(MT_CTSTR message, cSayInfo* pInfo);
    MT_CTSTR matchPattern(MT_CTSTR message, MT_CTSTR pattern);
public:
    void killedEnemy(u32 stageNo, u32 enemyId);
    u32 getKilledEnemyNum(u32 stageNo, u32 enemyId);
protected:
    cKilledEnemy* findKilledEnemy(u32 stageNo, u32 enemyId);
    void resetParam();
public:
    void callQuestAnnounce(const cQuestTask* pTask, s32 announceType, s32 purposeNo, bool isDiscovered, s32 num);
    void callFailedQuestAnnounce(nQuest::QUEST_TYPE questType, nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, u32 commonDialog);
    void requestOverWriteBgm(s32 bgmType, s32 bgmId, s32 callType);
    void requestOverWriteBgmFix(s32 bgmType, s32 bgmId);
    void requestStopBgm();
    void requestRestoreBgm(bool IsRequestEvent);
protected:
    void updateQuestAnnounce();
public:
    bool isEnteredLobby() const;
    void setStageInfo(s32 stageNo, bool isLobby);
    void loadStage();
    void initStage();
    void initLobby();
    void initGame();
    void finalGame();
    bool isResetInstanceArea() const;
    void setResetInstanceArea();
protected:
    void updateResetInstanceArea();
public:
    u32 getQuestListSetNum() const;
    u32 getQuestListSetQuestId(u32 idx) const;
    cNamedParam* getRaidBossEnemyParam(u32 raidBossId) const;
    bool isCycleContentsHolding() const;
    bool isCycleContentsReceving() const;
    u32 getHoldingCycleContentsNum() const;
    nQuest::CYCLE_CONTENTS_PERIOD getHoldingContentsPeriod(nQuest::QUEST_ID questId) const;
    const nQuest::cCycleContentsInfo* getHoldingCycleContentsInfo(u32 idx) const;
    u32 getHoldingCycleContentsListIndex(nQuest::SCHEDULE_ID scheduleId) const;
    nQuest::QUEST_ID getCycleContentsPlayNowQuestId() const;
    bool isCycleContentsDemoNow() const;
    bool isCycleContentsPlayNow() const;
    bool isCycleContentsPlayNowAll() const;
    bool isCycleContentsPlayNowResult() const;
    bool isCycleContentsEndFlowNow();
    u32 getCycleContentsPoint() const;
    bool isDispCycleContentsTimer() const;
    f32 getCycleContentsTimer() const;
    void finishCycleContentsTimer();
    void stopCycleContentsTimer();
    bool hasStartedCycleContentsTimer() const;
    u32 getCycleContentsPurposeNum() const;
    MT_CTSTR getCycleContentsPurpose(u32 idx) const;
    MT_CTSTR getCycleContentsNamePlayNow() const;
    const nQuest::cCycleContentsResultInfo& getCycleContentsResultInfo() const;
    MT_CTSTR getCycleContentsExtraBonusMsg(u32 extraBonusNo) const;
    const nQuest::CycleContentsRankingList& getCycleContentsRankingList() const;
    const nQuest::CycleContentsRankingRewardList& getCycleContentsRankingRewardList() const;
    const nQuest::CycleContentsBorderRewardList& getCycleContentsBorderRewardList() const;
    bool isCycleContentsTimerZero() const;
    f32 getCycleContentsPlayTime() const;
    nQuest::SCHEDULE_ID getNowHoldingCycleContentsScheduleId();
    void setNowCallEntryBoardContentsType(nNetSv::E_CONTENT_TYPE type);
    nNetSv::E_CONTENT_TYPE getNowCallEntryBoardContentsType();
    bool isNowCallEndContents();
    bool isNowCallCycleContents();
    void setNowCallCycleContentsScheduleId(u32 id);
    u32 getNowCallCycleContentsScheduleId();
    void setNowCallEntryBoardScheduleID(u32 id);
    u32 getNowCallEntryBoardScheduleID();
    void setNowCallEntryBoardQuestID(u32 id);
    u32 getNowCallEntryBoardQuestID();
    void clearRequestEntryInfoSave();
    void saveRequestEntryInfo(const nNet::stEntryBoardItemInfo& info);
    void loadRequestEntryInfo(nNet::stEntryBoardItemInfo& info);
    bool isSaveRequestEntryInfoSave();
    void clearEntrySearchFilterSave();
    void saveEntrySearchFilter(const cCharacterData::stSearchFilterSetting& info);
    void loadEntrySearchFilter(cCharacterData::stSearchFilterSetting& info);
    bool isSaveEntrySearchFilterSave();
    MT_CTSTR getCycleContentsName(nQuest::CYCLE_CONTENTS_TYPE type) const;
    MT_CTSTR getCycleContentsName(nQuest::CYCLE_CONTENTS_CATEGORY category) const;
    MT_CTSTR getCycleContentsName(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    MT_CTSTR getCycleContentsInfo(nQuest::CYCLE_CONTENTS_TYPE type) const;
    MT_CTSTR getCycleContentsInfo(nQuest::CYCLE_CONTENTS_CATEGORY category) const;
    MT_CTSTR getCycleContentsInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    MT_CTSTR getCycleContentsSituationName(nQuest::CYCLE_CONTENTS_TYPE type, u32 period) const;
    MT_CTSTR getCycleContentsSituationName(nQuest::CYCLE_CONTENTS_TYPE type, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsSituationName(nQuest::CYCLE_CONTENTS_CATEGORY category, u32 period) const;
    MT_CTSTR getCycleContentsSituationName(nQuest::CYCLE_CONTENTS_CATEGORY category, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsSituationName(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period) const;
    MT_CTSTR getCycleContentsSituationName(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsSituationNamePlayNow() const;
    MT_CTSTR getCycleContentsSituationInfo(nQuest::CYCLE_CONTENTS_TYPE type, u32 period) const;
    MT_CTSTR getCycleContentsSituationInfo(nQuest::CYCLE_CONTENTS_TYPE type, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsSituationInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, u32 period) const;
    MT_CTSTR getCycleContentsSituationInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsSituationInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period) const;
    MT_CTSTR getCycleContentsSituationInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsSituationDetailedInfo(nQuest::CYCLE_CONTENTS_TYPE type, u32 period) const;
    MT_CTSTR getCycleContentsSituationDetailedInfo(nQuest::CYCLE_CONTENTS_TYPE type, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsSituationDetailedInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, u32 period) const;
    MT_CTSTR getCycleContentsSituationDetailedInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsSituationDetailedInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period) const;
    MT_CTSTR getCycleContentsSituationDetailedInfo(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory, u32 period, u32 situation) const;
    MT_CTSTR getCycleContentsOrderPlace(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    const nQuest::cCycleContentsSituationInfo* getCycleContentsSituationData(nQuest::SCHEDULE_ID scheduleId) const;
    nQuest::QUEST_ID getCycleQuestCtrlId(u32 ContentType, u32 ContentSubType);
    nQuest::QUEST_TYPE getCycleContentsQuestType(nQuest::SCHEDULE_ID scheduleId) const;
    void setEntryCycleContentCategory(u32 NpcId);
    void clearEntryCycleContentCategory();
    u32 getCycleContentEntryStage();
    u32 getCycleContentEntryStartPos();
    u32 getContentEntryNpcId();
    void setCycleContentEntryNpcId(nQuest::SCHEDULE_ID ScheduleId);
    void setCycleContentEntryNpcId(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory);
    cCycleQuestManagerBase* getCycleContentsMgr(nQuest::CYCLE_CONTENTS_CATEGORY category, nQuest::CYCLE_CONTENTS_SUB_CATEGORY subCategory) const;
    cCycleQuestManagerBase* getCycleContentsMgr(u32 npcId) const;
    cCycleQuestSubCategoryManager* getCycleContentsSubCategoryMgr(u32 npcId) const;
    nQuest::CYCLE_CONTENTS_PERIOD getCycleContentsPeriodFromNpcId(u32 npcId) const;
    bool hasUpdatedCycleContentsState() const;
    u32 getCycleContentsScheduleIdFromQuestScheduleId(nQuest::SCHEDULE_ID ScheduleId);
    bool isEnableEntryBoard();
    void releaseEntryBoardChangePhase(nQuest::SCHEDULE_ID ScheduleId);
    bool isDistEnableEntryBoard(u32 npcId);
    nQuest::SCHEDULE_ID getCycleContentsScheduleIdFromSituation(nQuest::SCHEDULE_ID SituationScheduleId);
    bool isDistributionSituation(nQuest::SCHEDULE_ID SituationScheduleId);
    bool isHoldingAnyCycleContents() const;
    u8 getRno() const;
    void setRno(u8 rno0);
protected:
    cCycleQuestManagerBase* getCycleContentsMgrDemoNow() const;
    cCycleQuestManagerBase* getCycleContentsMgrPlayNow() const;
    cCycleQuestManagerBase* getCycleContentsMgrPlayNowAll() const;
public:
    void requestGetCycleState();
    bool isActiveQuest(nQuest::SCHEDULE_ID scheduleId, u32* pIdx, s32 dispType) const;
    u32 getActiveQuestDispType() const;
    u32 getActiveQuestFromCharacterId(u32 characterId, u32 idx) const;
    nQuest::SCHEDULE_ID getActiveQuest(u32 idx) const;
    nQuest::SCHEDULE_ID getActiveQuest(u32 dispType, u32 idx) const;
    void setActiveQuest(nQuest::SCHEDULE_ID scheduleId);
    bool isEnableRequestActiveQuest();
    bool isEnableRequestAutoActiveQuest();
    void resetActiveQuest();
    bool isFinishedSetActiveQuest() const;
    bool isFinishedCancelActiveQuest() const;
    nQuest::SCHEDULE_ID getPartyQuestScheduleId(u32 idx);
    u32 getPartyQuestNum();
protected:
    nQuest::SCHEDULE_ID getActiveQuestScheduleIdMySelf(u32 idx) const;
public:
    void recvNoticeActiveQuest(u32 characterId, const PriorityQuestVec& priorityQuestList);
    void deleteActiveQuestList(u32 characterId);
    void reqGetActiveQuest();
    void cancelActiveQuest(nQuest::SCHEDULE_ID scheduleId);
    u32 getEndContentsPurposeNum() const;
    MT_CTSTR getEndContentsPurpose(u32 idx) const;
    MT_CTSTR getEndContentsName() const;
    MT_CTSTR getEndContentsName(nQuest::SCHEDULE_ID scheduleId) const;
    bool isLeftCycleTimer(f32 sec) const;
    void setEndContentsEntry(u32 npcId, bool solo);
    bool getEndContentsEntrySolo();
    void setEndContentsEntryClan(bool flag);
    bool getEndContentsEntryClan();
    u32 getEndContentEntryStage();
    u32 getEndContentEntryStartPos();
    u32 getEndContentsGroupNo(u32 NpcId) const;
    u32 getEndContentsGroupNo(nQuest::QUEST_ID QuestId) const;
    u32 getEndContentsEntryNpcId(u32 GroupNo) const;
    bool isEndContentsPlayNow() const;
    bool isContentsPlayNowEndFlow();
    void registEndContents(const CEndContentsGroup& group);
    cQuestManagerBase* getQuestManager(nQuest::QUEST_TYPE type) const;
    bool registQuestManager(nQuest::QUEST_TYPE type, cQuestManagerBase* pMgr);
    cQuestFunctionManagerBase* getFunctionManager(nQuest::FUNCTION_TYPE type) const;
    bool registFunctionManager(nQuest::FUNCTION_TYPE type, cQuestFunctionManagerBase* pMgr);
    cPRTManager* getPRTMgr() const;
    cQuestMemoryPool* getQuestMemoryPool() const;
    cQuestMarkerManager* getQuestMarkerMgr() const;
    cActiveQuestManager* getActiveQuestMgr() const;
    cQuestResourceManager* getQuestResourceMgr() const;
    cQuestResourceLoadManager* getQuestResourceLoadMgr() const;
    cQuestSvRequestManager* getQuestSvRequestMgr() const;
    cQuestSvNoticeManager* getQuestSvNoticeMgr() const;
    cQuestDeliverManager* getQuestDeliverMgr() const;
    cAreaReleaseManager* getAreaReleaseMgr() const;
    cQuestPartyManager* getQuestPartyMgr() const;
    cQuestEventManager* getQuestEventMgr() const;
    cQuestPhaseManager* getQuestPhaseMgr() const;
    bool isEmptyRequestQueue() const;
protected:
    void paralllelManagerMove(uintptr interlock);
    void moveManager();
    void moveManagerBefore();
    void moveManagerAfter();
public:
    bool isClearedMainQuest(nQuest::QUEST_ID questId) const;
    bool isClearedTutorialQuest(nQuest::QUEST_ID questId) const;
    bool isClearedEndContents(nQuest::QUEST_ID questId) const;
    bool isClearedQuest(nQuest::QUEST_ID questId) const;
    bool isClearedQuest(nQuest::SV_QUEST_TYPE questType, nQuest::QUEST_ID questId) const;
    bool isClearedQuest(nQuest::SCHEDULE_ID ScheduleId) const;
    const nQuest::QuestIdArray& getClearedMainQuesetList() const;
    void resetClearedMainQuestList();
    bool isMainQuestHelper();
    bool isOrderedSoloMainQuest();
    bool isGetMainQuestClearList();
    void requestGetQuestCompleteList(nQuest::SV_QUEST_TYPE questType);
protected:
    void moveGetQuestCompleteList();
    void callbackGetQuestCompleteList(u32 errorCode);
public:
    const nQuest::QuestMarkerArray& getQuestMarkerCurrentStage() const;
    const nQuest::QuestMarkerArray& getQuestMarkerForMap() const;
    u32 getMarkerDataStageNo() const;
    void requestGetRewardBoxList();
    bool isGetRewardBoxList() const;
    const RewardBoxRecordVec& getRewardBoxData() const;
    void completeRewardBoxList();
    void requestGetCycleContentsRewardList();
    bool isGetCycleContentsRewardList() const;
    const RewardBoxRecordVec& getCycleContentsRewardData() const;
    const CycleContentsRewardRecordVec& getCycleContentsRewardExData() const;
    void completeCycleContentsRewardList();
    MT_CTSTR getQuestName(nQuest::QUEST_ID questId) const;
    MT_CTSTR getRewardBoxQuestName(nQuest::QUEST_ID questId) const;
    MT_CTSTR getQuestNameMyMainQuest() const;
    MT_CTSTR getQuestDetail(nQuest::QUEST_ID questId) const;
    MT_CTSTR getQuestPurposeMsg(nQuest::QUEST_ID questId) const;
    MT_CTSTR getQuestPartyPurposeMsg(nQuest::QUEST_ID questId) const;
    MT_CTSTR getQuestPurposeMsg(nQuest::QUEST_ID questId, s32 idx) const;
    u32 getQuestPurposeNum(nQuest::QUEST_ID questId) const;
    MT_CTSTR getQuestFindInfo(nQuest::QUEST_ID questId) const;
    MT_CTSTR getQuestFindInfoDetail(nQuest::QUEST_ID questId) const;
    MT_CTSTR getQuestContentsDetail(nQuest::QUEST_ID questId) const;
    u32 getQuestBaseLevel(nQuest::SCHEDULE_ID scheduleId) const;
    bool isFinishedLoadingQuestResource(nQuest::QUEST_ID questId) const;
    bool isFinishedLoadingQuestResourceRewardBox(nQuest::QUEST_ID questId) const;
    cTalkMsgData* getQuestMessageData(nQuest::QUEST_ID questId) const;
    cTalkMsgData* getQuestExmineData(nQuest::QUEST_ID questId) const;
    u32 getQuestArea(nQuest::SCHEDULE_ID scheduleId) const;
    u32 getJobTutorialQuestOrderNum() const;
    bool isOrderJobTutorialQuest(nQuest::QUEST_ID jobTutoQuestId) const;
    void setIsOpenNewspaper(bool isOpen);
    void setReleaseContentResouce(u32 category, nQuest::SCHEDULE_ID shceduleId);
    void loadQuestResource(nQuest::QUEST_ID questId) const;
    void loadQuestResourceRewardBox(nQuest::QUEST_ID questId) const;
    void releaseRewardBox();
    bool isQuestFlag(u32 flagNo) const;
    bool isQuestFlag(u32 flagNo, nQuest::QUEST_ID questId) const;
    bool isMyQuestFlag(u32 flagNo) const;
    bool isMyQuestFlag(u32 flagNo, nQuest::QUEST_ID questId) const;
    bool isQuestLayoutFlag(u32 flagNo) const;
    bool isQuestLayoutFlag(u32 flagNo, nQuest::QUEST_ID questId) const;
    bool isEnablePartyPlay();
    bool isEnableParty_Invite();
    bool isEnableParty_Join();
    bool isEnableSetQuest() const;
    bool isEnableCycleQuest();
    bool isEnableEndQuest();
    bool isEnableRimWarp();
    bool isEnableClan();
    bool isEnableNewspaper();
    bool isEnableCraft();
    bool isEnableRimStone();
    bool isEnableLightQuest();
    bool isEnableEventQuest();
    bool isEnableQuickParty();
    bool isEnableAreaMaster();
    bool isEnableMenu_Option();
    bool isEnableMenu_VisualEquip();
    bool isEnableMenu_Pawn();
    bool isEnableMenu_ArisenProf();
    bool isEnableMenu_Newspaper();
    bool isEnableMenu_Master();
    bool isEnableMenu_RimWarp();
    bool isEnableMenu_Party();
    bool isEnableMenu_Clan();
    bool isEnableMenu_MatchingProf();
    bool isEnableCreatePawn();
    bool isEnableMyRoom();
    bool isChangeBgmIsland();
    bool isEnablePlayPoint();
    cQuestTask* getQuestTask(nQuest::SCHEDULE_ID scheduleId) const;
    cQuestTask* getQuestTask(nQuest::QUEST_ID questId) const;
    bool isPlayMainQuest(nQuest::QUEST_ID questId) const;
    bool isEnableOrder(nQuest::SCHEDULE_ID scheduleId) const;
    bool isEnableOrderMySelf(nQuest::SCHEDULE_ID scheduleId) const;
    nQuest::RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrder(nQuest::SCHEDULE_ID scheduleId, bool IsLeader) const;
    nQuest::RET_DISABLE_ORDER_CONDITION_TYPE getEnableOrderMySelf(nQuest::SCHEDULE_ID scheduleId) const;
    bool canProgress(nQuest::QUEST_ID questId) const;
    bool canProgress(nQuest::SCHEDULE_ID scheduleId) const;
    u32 getOfferedChaliceNum() const;
    nQuest::QUEST_ID getQuestId(nQuest::SCHEDULE_ID scheduleId) const;
    nQuest::QUEST_ID getQuestIdMyMainQuest() const;
    nQuest::SCHEDULE_ID getScheduleIdMyMainQuest() const;
    u32 getProgressMyMainQuest() const;
    bool isHelper(nQuest::SCHEDULE_ID scheduleId) const;
    void cancelQuest(const nQuest::cGUIListData* pIndex);
    bool isFinishedCancelQuest() const;
    u32 getBoardDataList(nQuest::GUIBoardDataArray& list) const;
    u32 getOrderQuestListDataList(nQuest::QUEST_TYPE type, nQuest::GUIListDataArray& list) const;
    u32 getWaitOrderQuestListDataList(nQuest::GUIListDataArray& list) const;
    u32 getWaitDeliverQuestDeliveryDataList(nQuest::QUEST_TYPE type, nQuest::GUIDeliveryDataArraay& list) const;
    u32 getMoveQuestEventBoardDataList(nQuest::QUEST_TYPE type, nQuest::GUIEventBoardDataArray& list) const;
    u32 getMoveQuestAreaMasterDataListNum(u32 areaId) const;
    u32 getMoveQuestAreaMasterDataList(u32 areaId, nQuest::GUIAreaMasterDataArray& list) const;
    u32 getOrderQuestActiveDataList(nQuest::QUEST_TYPE type, nQuest::GUIActiveDataArray& list) const;
    u32 getLeaderOrderQuestListDataList(nQuest::QUEST_TYPE type, nQuest::GUIListDataArray& list) const;
    nQuest::SCHEDULE_ID getQuestTargetEmScheduleId(uCharacter* pEm, nQuest::cQuestMarker* * ppMarker) const;
    nQuest::SCHEDULE_ID getQuestTargetEmScheduleId(uCharacter* pEm) const;
    u32 getQuestTargetOmScheduleId(uOmModel* pOm) const;
    bool isUpdateIndexList(nQuest::QUEST_TYPE type) const;
    bool isUpdateIndexListForSetQuest(u32 areaId) const;
    bool isUpdateIndexListForOrder() const;
    void requestOrderLightQuest(const nQuest::SCHEDULE_ID& scheduleId);
    bool isFinishedOrderLightQuest() const;
    void requestGpCompleteLightQuest();
    bool isFinishedGpCompleteLightQuest() const;
    u32 getGpCompleteLightQuestErrorCode() const;
    bool isGpCompleteLightQuest() const;
    u32 getNotCompleteLightQuestNum() const;
    u32 getGpCompleteLightQuestGp() const;
    QUEST_RET getQuestServerParam(const nQuest::SCHEDULE_ID& scheduleId);
    bool isBlankMyOrder() const;
    bool isBlankLeaderOrder() const;
    u32 getQuestOrderNowNum() const;
    u32 getQuestOrderNowNum(nQuest::QUEST_TYPE questType) const;
    u32 getQuestOrderMaxNum() const;
    u32 getQuestOrderMaxNumNormal() const;
    u32 getQuestOrderMaxNumCharge() const;
    u32 getQuestRewardBoxMaxNum() const;
    bool isEndDistributionQuestCancel() const;
    void offEndDistributionQuestCnacel();
    void setGetCycleContentsInfoList(bool flag);
    bool isGetCycleContentsInfoList() const;
    bool isClearedTutorialQuestGroup(u32 groupId) const;
    void interruptBarricade();
    bool isEnableInterruptBarricade();
    bool isEnableOrderButton(nQuest::SCHEDULE_ID ScheduleId);
    void setEndContentsInfo(nQuest::QUEST_ID QuestId, bool isClear);
    u32 getEndContentsClearTimeU32();
    bool getTargetEnemyGroupId(nQuest::SCHEDULE_ID scheduleId, u32& val) const;
    bool getTargetEnemyLevel(nQuest::SCHEDULE_ID scheduleId, u32& val) const;
    bool getTargetItemId(nQuest::SCHEDULE_ID scheduleId, u32& val) const;
    bool getTargetNum(nQuest::SCHEDULE_ID scheduleId, u32& val) const;
    virtual void move();  // vtable slot 7
    bool isOrderQuest(nQuest::SCHEDULE_ID ScheduleId) const;
    bool isOrderQuest(nQuest::QUEST_ID QuestId) const;
    bool isOrderMyMainQuest() const;
    bool isMyOrderQuest(nQuest::SCHEDULE_ID ScheduleId) const;
    bool isOrderPawnQuest() const;
    bool isDiscoverdQuest(nQuest::SCHEDULE_ID ScheduleId) const;
    bool isDiscoverdQuest(nQuest::QUEST_ID questId) const;
    bool isEnableDeliveryLightQuest() const;
    u32 getOnlyOneQuestTalkScheduleId(u32 NpcId) const;
    u32 getOnlyOneQuestTalkScheduleId(u32 NpcId, nQuest::QUEST_ID QuestId, bool IsChkQuestId) const;
    bool isHaveEnableQuestTalk(nQuest::QUEST_TYPE questType, u32 npcId, u32 questId, bool IsChkQuestId) const;
    bool hasQuestTalk(u32 npcId) const;
    bool hasQuestTalk(nQuest::QUEST_TYPE questType, u32 npcId) const;
    u32 getHaveQuestTalkNum(nQuest::QUEST_TYPE questType, u32 npcId) const;
    nQuest::SCHEDULE_ID getHaveQuestTalkScheduleId(u32 npcId) const;
    nQuest::SCHEDULE_ID getHaveQuestTalkScheduleId(nQuest::QUEST_TYPE questType, u32 npcId) const;
    nQuest::SCHEDULE_ID getHaveQuestTalkConnectMarkerScheduleId(u32 npcId, nQuest::QUEST_ID npcQuestId, bool isDispElseQuestTalk) const;
    void addQuestTalk(nQuest::QUEST_TYPE questType, u32 npcId, nQuest::QUEST_ID questId, MtObject* pClass, void(MtObject::*pCallback)(const cQuestTask*, const nQuest::cTalkData*));
    bool buysHint(nQuest::SCHEDULE_ID scheduleId);
    nQuest::QUEST_TYPE getQuestType(nQuest::QUEST_ID questId) const;
    nQuest::QUEST_TYPE getQuestType(nQuest::SCHEDULE_ID ScheduleId) const;
    void getWaypointGoto(u32 npcId, s32& waypoint0, s32& waypoint1, s32& waypoint2) const;
    void setWaypointGoto(u32 npcId, s32 gotoPointNo0, s32 gotoPointNo1, s32 gotoPointNo2);
    bool isUpdateWaypoint() const;
    bool getSetQuestList();
    void forceGetSetQuestList();
    const nQuest::cGUINewspaperSetQuestInfoList& getSetQuestInfoListRef() const;
    const nQuest::GUINewspaperRecommededQuestInfoArray& getRecommededQuestInfoListRef() const;
    const nQuest::GUINewspaperSetQuestOpenDateInfoArray& getSetQuestOpenDateInfoListRef() const;
    bool isFinishedLoadNewspaperSetQuestOpenDateListResource() const;
    u32 getQuestSeq(nQuest::QUEST_ID questId) const;
    cQuestTask* addHelperTask(const CQuestOrderList* pOrder);
    cQuestTask* addHelperTask(const CMainQuestList* pOrder);
    MT_CTSTR getOrderConditionText(u32 ConditionType);
    void requestRepairMyQuestInfo();
    void setTutorialInvincible(uCharacter* pCharacter);
    MT_CTSTR getLightQuestPurpose(u32 Idx) const;
    void endDistributionQuestCancel();
    void onMainQstSyncFlag();
    void offMainQstSyncFlag();
    void resetMainQstSyncFlag();
    void setMainQstSyncInfo(nQuest::SCHEDULE_ID ScheduleId, u32 ProcessNo, u32 BlockNo, u32 FlagNo);
    void resetMainQstSyncInfo();
    bool isMainQstSyncFlag(nQuest::SCHEDULE_ID ScheduleId);
    void reqQuestOrder(nQuest::SCHEDULE_ID ScheduleId);
    void cancelReqQuestOrder(nQuest::SCHEDULE_ID ScheduleId);
    bool isQuestOrderProgress(nQuest::SCHEDULE_ID ScheduleId);
    bool isAutoPartyProgress(nQuest::SCHEDULE_ID ScheduleId);
    void callbackInstanceAreaReset();
    void reqSendLeaderQuestOrderConditionInfo();
    void sendLeaderQuestOrderConditionInfo();
    void resetLeaderQuestOrderConditionInfo();
    void sendLeaderWaitOrderQuestList();
    void callbackCycleContentsPlayStart();
    bool hasCycleContentsPlayEndNotice() const;
    void reqCycleContentsPlayEnd();
    void resetHasCycleContentsPlayEndNotice();
    bool isEnableOrderMainQuest();
    bool isEnableProgressSoloQuest();
    void resetLoginInfo();
    bool isForceInBattleState();
    void resetEndContentsInfo();
protected:
    void callbackQuestProgress(void* pPacket);
    void callbackGetSetQuestList(void* pPacket);
    void callbackQuestTimer(void* pPacket);
    void callbackQuestComplete(void* pPacket);
    void callbackQuestProgressWorkSave(void* pPacket);
    void callbackCycleContentsPlayEnd(void* pPacket);
    void callbackPlayStartTimer(void* pPacket);
    void callbackPlayAddTimer(void* pPacket);
    void callbackPlayTimeup(void* pPacket);
    void callbackEndDistributionQuestCancel(u32 errorCode);
    void callbackLoadResourceListEndDistributionQuests(u32 arg, const nQuest::QuestIdArray& ids);
    void requestInformation();
    void callbackLeaderQuestProgress(void* pPacket);
    void callbackGetMainQuestList(void* pPacket);
    void callbackStopTimer(void* pPacket);
    void callbackRestartTimer(void* pPacket);
    void callbackEndContentsPlayEnd(void* pPacket);
    void callbackRepairMyQuestInfo(u32 errorCode);
    void callbackQuestCancel(void* pPacket);
    void callbackQuestOrder(void* pPacket);
    void callbackGetEndContentsGroup(u32 errorCode);
    void callbackGetCycleContentsStateList(u32 errorCode);
    void callbackQuestEnable(void* pPacket);
    void callbackCycleContentsEnable(void* pPacket);
    void callbackJoinLobbyQuestInfo(void* pPacket);
    void callbackRemainingTime30Sec();
    void callbackRemainingTime60Sec();
    void callbackFinishCycleContentsTimer();
    void callbackEntryParty(cQuestEventArg* pArg);
    void callbackLeaveParty(cQuestEventArg* pArg);
    void callbackSendLeaderQuestOrderConditionInfo(void* pPacket);
    void callbackSendLeaderWaitOrderQuestList(void* pPacket);
    void callbackGetAreaBonusList(u32 errorCode);
    void callbackSetQuestUnreleasedArea(void* pPacket);
    void callbackReleaseSetQuestArea(void* pPacket);
private:
    void setNewspaperQuestInfo(nQuest::cGUINewspaperSetQuestInfo* pInfo, CSetQuestInfoList* pSvInfo);
public:
    bool isOrderUIDecide(nQuest::SCHEDULE_ID ScheduleId) const;
    bool setOrderUI(nQuest::SCHEDULE_ID scheduleId, u32 npcId);
    QUEST_UI_RESULT moveOrderUI();
    bool setDeliverUI(nQuest::SCHEDULE_ID scheduleId, uControl* pCtrl);
    bool setCycleDeliverUI(u32 npcId);
    void callbackGetSetQuestInfoList();
    void callbackGetRecommendedQuestInfoList();
    void callbackGetSetQuestOpenDateList();
    void callbackGetCycleContentsNewsList();
    void callbackGetRankingDataRank();
    void callbackGetCycleContentsRankingRewardList();
    void callbackGetCycleContentsBorderRewardList();
    void callbackGetQuestPartyBonusList();
    void callbackGetRankingBoardListByScheduleId();
    bool canRequestOrderWaitOrderQuest(const nQuest::SCHEDULE_ID& scheduleId);
    bool requestOrderWaitOrderQuest(const nQuest::SCHEDULE_ID& scheduleId);
    bool isWaitOrderQuest(const nQuest::SCHEDULE_ID& scheduleId);
    bool isFinishedOrderWaitOrder() const;
    void addWaitOrder(nQuest::SCHEDULE_ID scheduleId);
    void removeWaitOrder(nQuest::SCHEDULE_ID scheduleId);
    u32 getAreaReleaseByRankUp(u32 index) const;
    void setAreaReleaseByRankUp(u32 data);
    u32 getAreaReleaseNumByRankUp() const;
    void setAreaRelease(u16 id);
    void setAreaId(u32 areaId);
    u32 getAreaId() const;
    bool isAreaRelease(u16 id);
    u32 getAreaMasterRank(u32 areaNo) const;
    void setAreaMasterRank(u32 areaNo, u32 rank);
    bool reqGetAreaReleaseInfo();
    bool getAreaReleaseInfo();
    void resetAreaRelease();
    void resetAreaReleaseByRankUp();
    void resetReleaseInfoRequest();
    void disableReleaseInfoRequest();
    bool isEnableReleaseInfoSendMsg();
    void csLock();
    void csUnlock();
    bool isLeaderReturn() const;
    void removeLeaderOrderedQuest(nQuest::SCHEDULE_ID scheduleId);
    void addLeaderOrderedQuest(nQuest::QUEST_ID questId, nQuest::SCHEDULE_ID scheduleId, bool hasOrdered);
    bool isPartyBonus(nQuest::SCHEDULE_ID scheduleId) const;
    bool isPartyBonusOrb() const;
    u32 getPartyBonusOrbNum() const;
    void requestGetQuestPartyBonusList(MtObject* pClass, void(MtObject::*pCallback)(u32));
    void requestGetQuestPartyBonusList(MtObject* pClass, void(MtObject::*pCallback)(u32), bool isForceReq);
    bool hasUpdatedGetQuestPartyBonusList();
    const nQuest::cPartyBonusInfo* getQuestPartyBonusInfo(nQuest::SCHEDULE_ID scheduleId) const;
    const nQuest::PartyBonusInfoArray& getQuestPartyBonusList() const;
    void recievePartyBonus(nQuest::SCHEDULE_ID scheduleId);
    bool isFavoriteWarpPoint(u32 warpPointId) const;
    void callbackGetFavoriteWarpPointList(const MtTypedArray<CDataFavoriteWarpPoint>& list);
    void callbackRegisterFavoriteWarp(u32 slotNo, u32 warpPointId);
    bool isJoinLeader() const;
    bool addSystemLog(MT_CTSTR message, nQuest::QUEST_ID quest_id, MT_CTSTR analizeMsg0, MT_CTSTR analizeMsg1, bool withAnnounce, u32 filter, bool isWarning);
    void dispHelperSystemLog();
    bool isAreaBonus(u32 areaId) const;
    u32 getAreaBonusRate(u32 areaId) const;
    void setBarricade(nQuest::SCHEDULE_ID scheduleId, s32 stageNo, s32 startPos, s32 sceHitNo, s32 inSceHitNo);
    void resetBarricade(nQuest::SCHEDULE_ID scheduleId);
    void updateBarricade();
    bool isEnableStageJump();
    cJobMasterCtrl* getJobMasterCtrlData(u32 JobId) const;
    void clearAreaBossCautionInfo();
    void addReleaseContents(u32 addContents);
    bool isEnableContents(u32 chkContents) const;
    void resetReleaseContents();
    bool isJoinPartyPawn_Create();
    void addFuncChkData(u32 FunctionId, nQuest::SCHEDULE_ID ScheduleId, s32 Param);
    void deleteFuncChkData(nQuest::SCHEDULE_ID ScheduleId);
    void clearFuncChkData();
    u32 getFuncChkScheduleId(u32 FunctionId);
    bool isWQUnreleasedArea(u32 areaId) const;
    bool isWaitDivide() const;
    bool isDivideSetup() const;
    bool isFinishDivide() const;
    bool isSucceededDevide() const;
    bool isWarpCharacter(u32 characterId) const;
    bool isReturnCharacter(u32 characterId) const;
    void getWarpPlayerStageNoStartPos(u32& stageNo, u32& startPos) const;
    u32 getPhase1BuffLevel() const;
    bool hasRequestedWarpPlayer(u32 characterId) const;
    void requestWarpPlayer(u32 characterId);
    bool isExistDividePlayer() const;
    bool isFinishedEnemyDivideAction() const;
    void finishEnemyDivideAction();
    static sQuestManagerExt* getInstance();
    sQuestManagerExt();
    virtual ~sQuestManagerExt();
protected:
    void createPropertyForDebug(MtPropertyList& s);
protected:
    u8 mRno0;  // offset: 0x11
    stEndContentsInfo mEndContentsInfo;  // offset: 0x18
private:
    nDDOUtility::cBitSet<59> mReleaseContents;  // offset: 0x30
    MtTypedArray<cQstFunctionCheck> mFuncChkArray;  // offset: 0x38
protected:
    MtTypedArray<CDataFavoriteWarpPoint> mFavoriteWarpPointList;  // offset: 0x58
    nQuest::QuestIdArray mClearedMainQuestList;  // offset: 0x78
    nQuest::QuestIdArray mClearedTutorialQuestList;  // offset: 0x98
    nQuest::QuestIdArray mClearedEndContentsQuestList;  // offset: 0xb8
    OrderConditionInfoVec mLeaderOrderConditionInfoList;  // offset: 0xd8
    nQuest::PartyBonusInfoArray mPartyBonusInfoList;  // offset: 0xf8
    KilledEnemyArray mKilledEnemy;  // offset: 0x118
    ManagerInfoArray mManagerInfo;  // offset: 0x138
    FunctionInfoArray mFunctionInfo;  // offset: 0x158
    SystemLogNodeQueue mSystemLogQueue;  // offset: 0x178
    ClearedQuestInfoArray mClearedQuestInfo;  // offset: 0x198
    CallQuestAnnounceArray mCallQuestAnnounce;  // offset: 0x1b8
    UnreleasedAreaArray mWQUnreleasedAreaList;  // offset: 0x1d8
    SayInfoArray mSayInfoList;  // offset: 0x1f8
    MtTime mPartyBonusNextReloadTime;  // offset: 0x218
    nQuest::cGUIDeliveryData* mpDeliveryData;  // offset: 0x220
    cTouchOmInfo* mpTouchOmInfo;  // offset: 0x228
    cTimer* mpCycleContentsTimer;  // offset: 0x230
    nQuest::SCHEDULE_ID mWaitOrderScheduleId[5];  // offset: 0x238
    nQuest::SCHEDULE_ID mBarricadeScheduleId;  // offset: 0x288
    nQuest::SCHEDULE_ID mReqCancelScheduleId;  // offset: 0x298
    nQuest::SCHEDULE_ID mReqOrderWaitOrderScheduleId;  // offset: 0x2a8
    stAreaBonusInfo mAreaBonusList[17];  // offset: 0x2b8
    u32 mClearSetQuestAreaId[4];  // offset: 0x340
    s32 mBarricadeStageNo;  // offset: 0x350
    s32 mBarricadeStartPos;  // offset: 0x354
    s32 mBarricadeSceHitNo;  // offset: 0x358
    s32 mBarricadeInSceHitNo;  // offset: 0x35c
    u32 mBarricadeRno;  // offset: 0x360
    u8 mOrderMaxNum;  // offset: 0x364
    u8 mGPOrderMaxNum;  // offset: 0x365
    u8 mRewardBoxMaxNum;  // offset: 0x366
    u8 mAreaMasterRank[17];  // offset: 0x367
    bool mIsReqEndDistQuestCancel;  // offset: 0x378
    bool mIsEndDistQuestCancel;  // offset: 0x379
    bool mIsGetQuestClearList;  // offset: 0x37a
    bool mHasRequestedGetCompleteListFromaMenu;  // offset: 0x37b
    bool mHasUpdatedPartyBonus;  // offset: 0x37c
    bool mReqSendLeaderQuestOrderConditionInfo;  // offset: 0x37d
    bool mHasCycleContentsPlayEndNotice;  // offset: 0x37e
    bool mIsFinishDivide;  // offset: 0x37f
    bool mOldIsWaitDivide;  // offset: 0x380
    bool mIsDispContentsTimer;  // offset: 0x381
    u32 mEntryNpcId;  // offset: 0x384
    u32 mEntryContentCategory;  // offset: 0x388
    u32 mEntryContentSubCategory;  // offset: 0x38c
    bool mEntrySolo;  // offset: 0x390
    bool mEntryClan;  // offset: 0x391
    nNetSv::E_CONTENT_TYPE mNowCallEntryBoardContentsType;  // offset: 0x394
    u32 mNowCallCycleContentsScheduleId;  // offset: 0x398
    u32 mNowCallEntryBoardScheduleID;  // offset: 0x39c
    u32 mNowCallEntryBoardQuestID;  // offset: 0x3a0
    nNet::stEntryBoardItemInfo mRequestEntryInfoSave;  // offset: 0x3a8
    cCharacterData::stSearchFilterSetting mEntrySearchFilterSave;  // offset: 0x488
    bool mIsSaveRequestEntryInfoSave;  // offset: 0x5b4
    bool mIsSaveEntrySearchFilterSave;  // offset: 0x5b5
    bool mIsResetInstanceArea;  // offset: 0x5b6
    s32 mResetStageNoPt[8];  // offset: 0x5b8
    nQuest::cGUINewspaperSetQuestInfoList mSetQuestInfoList;  // offset: 0x5d8
    nQuest::GUINewspaperRecommededQuestInfoArray mRecommendedQuestInfoList;  // offset: 0x608
    nQuest::GUINewspaperSetQuestOpenDateInfoArray mSetQuestOpenDateInfoList;  // offset: 0x628
    nQuest::CycleContentsInfoArray mCycleContentsInfoList;  // offset: 0x648
    nQuest::CycleContentsRankingList mCycleContentsRankingList;  // offset: 0x668
    nQuest::CycleContentsRankingRewardList mCycleContentsRankingRewardList;  // offset: 0x688
    nQuest::CycleContentsBorderRewardList mCycleContentsBorderRewardList;  // offset: 0x6a8
    nQuest::cCycleContentsResultInfo mCycleContentsResultInfo;  // offset: 0x6c8
    nQuest::SCHEDULE_ID mEventBoardAcceptedScheduleId;  // offset: 0x738
    nDDOUtility::cBitSet<64> mNoticeInfo;  // offset: 0x748
    nQuest::SCHEDULE_ID mOrderUIScheduleId;  // offset: 0x750
    s32 mWaypointGotoPointNo0;  // offset: 0x760
    s32 mWaypointGotoPointNo1;  // offset: 0x764
    s32 mWaypointGotoPointNo2;  // offset: 0x768
    u32 mWaypointNpc;  // offset: 0x76c
    u32 mNowSetQuestDistId;  // offset: 0x770
    u32 mTalkEndNpcId;  // offset: 0x774
    f32 mGetSetQuestTimer;  // offset: 0x778
    f32 mInterruptBarricadeTimer;  // offset: 0x77c
    bool mIsLobbyOld;  // offset: 0x780
    bool mIsEnteredLobby;  // offset: 0x781
    bool mIsCompleteGetRewardList;  // offset: 0x782
    bool mIsCompleteGetCycleContentsRewardList;  // offset: 0x783
    bool mIsUpdateWaypoint;  // offset: 0x784
    bool mIsOrderUIDecide;  // offset: 0x785
    bool mIsGetCycleContentsInfoList;  // offset: 0x786
    bool mIsInterruptBarricade;  // offset: 0x787
    bool mHasUpdatedCycleContentsState;  // offset: 0x788
    bool mIsContentsTimerTimeup;  // offset: 0x789
    bool mIsLeaderLost;  // offset: 0x78a
    s32 mAreaBossCautionStageNo;  // offset: 0x78c
    MtVector3 mAreaBossCautionPos;  // offset: 0x790
public:
    static MyDTI DTI;
protected:
    static sQuestManagerExt* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sQuestManagerExt* sQuestManagerExt::getInstance() {
    return ::sQuestManagerExt::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sQuestManagerExt::cKilledEnemy::cKilledEnemy() {
    this->mStageNo = static_cast<u32>(0);
    this->mEnemyId = static_cast<u32>(0);
    this->mKilledNum = static_cast<u32>(1);
}

// Inline, no code of its own: checked where it is inlined.
inline sQuestManagerExt::cManagerInfo::cManagerInfo() {
    this->mType = static_cast<nQuest::QUEST_TYPE>(12);
    this->mpMgr = static_cast<cQuestManagerBase*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline sQuestManagerExt::cFunctionInfo::cFunctionInfo() {
    this->mType = static_cast<nQuest::FUNCTION_TYPE>(13);
    this->mpFuncMgr = static_cast<cQuestFunctionManagerBase*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline void sQuestManagerExt::cTimer::finish() {
    this->mHasStarted = false;
    this->mRemainingTime = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline sQuestManagerExt::cUnreleasedArea::cUnreleasedArea() {
    this->mAreaId = static_cast<u32>(0);
}
