#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cGameDataCache.h"
#include "cLayoutSet.h"
#include "cLayoutSetEnemy.h"
#include "cLayoutSetGeneralPoint.h"
#include "cLayoutSetNpc.h"
#include "cLayoutSetOm.h"
#include "cQuestUnitManager.h"
#include "cSystem.h"
#include "ctl_localArray.h"
#include "nDDOUtility.h"
#include "nLayout.h"
#include "rLayout.h"
#include "rLayoutGroupParam.h"

// Forward declarations
class CDataDropItemSetInfo;
class CDataGatheringItemElement;
class CDataLayoutEnemyData;
class CDataLayoutItemData;
class CDataStageLayoutID;
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cContextInstance;
class cGroupParam;
class cLayoutSet;
class cLayoutSetEnemy;
class cLayoutSetGeneralPoint;
class cLayoutSetNpc;
class cLayoutSetOm;
class cNamedParam;
class cOmControl;
class cQuestUnitManager;
class cUnit;
namespace nLayout { class cGameDataCache; }
namespace nLayout { struct stLayoutID; }
namespace nLayout { struct stReserveID; }
namespace nLayout { struct stSplitID; }
namespace nNetBase { class cNetBase; }
class rLayoutGroupParamList;
class rLayoutPreset;
class rNamedParam;
class uBaseModel;
class uControl;
class uControlEnemy;
class uDDOModel;

// Declarations
class sSetManager;

// Type aliases from DWARF
using CLayoutEnemyData = CDataLayoutEnemyData;
using DropItemSetInfoVec = MtTypedArray<CDataDropItemSetInfo>;
using GatheringItemElementVec = MtTypedArray<CDataGatheringItemElement>;
using LayoutEnemyDataVec = MtTypedArray<CDataLayoutEnemyData>;
using LayoutItemDataVec = MtTypedArray<CDataLayoutItemData>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using f64 = double;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sSetManager : public cSystem
{
public:
    enum UNIT_STATE
    {
        UNIT_STATE_EMPTY = 0,
        UNIT_STATE_MOVE = 1,
        UNIT_STATE_RESERVE = 2,
        UNIT_STATE_PRE_DELETE = 3,
        UNIT_STATE_DELETE = 4,
    };
    enum REG_RESULT
    {
        REG_SUCCESS = 0,
        REG_ALWAYS = 1,
        REG_KILLED = 2,
        REG_RESERVE = 3,
        REG_FAILED = 4,
    };
    enum
    {
        PAUSE_NONE = 0,
        PAUSE_ENEMY = 1,
        PAUSE_NPC = 2,
        PAUSE_OM = 4,
        PAUSE_SCR = 8,
        PAUSE_GP = 16,
        PAUSE_ALL = 65535,
    };
    enum
    {
        MANAGE_DATA_NUM_CUR = 512,
    };
public:
    template <typename Type> class cLotMgr;
    template <typename Mgr> struct DataPackageObject;
    class MyDTI;
    class cUnitData;
    class cOmGroupData;
    struct stNamedIndex;
    class cEnemyDie;
    class CreateContextParam;
    struct stEmRegisterData;
public:
    using cLotMgrGeneralPoint = sSetManager::cLotMgr<cLayoutSetGeneralPoint>;
    using ManageDataArrayCur = nDDOUtility::cArray<sSetManager::cOmGroupData, 512>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cUnitData : public MtObject
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
        cUnitData();
        // Address: 0x01acaf00 - 0x01acaf01 (1 bytes)
        virtual ~cUnitData() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void update();
        void empty();
        void set(cUnit* pUnit, u32 prio);
        nLayout::stReserveID reserve(u32 prio, const nLayout::stLayoutID& layoutID, u32 id, const cGroupParam* pGroupParam);
        bool isReserve(const nLayout::stLayoutID& layoutID, u32 id);
        void reserveCancel(const nLayout::stLayoutID& layoutID, u32 id);
        bool isEmpty() const;
        bool isDelete() const;
        u32 getPrio() const;
        void setPrio(u32 prio);
        void killAndEmpty();
        u32 getReserveIDGroup() const;
        u32 getReserveIDID() const;
        const cUnit* getUnitPtr() const;
        cUnit* getUnitPtr();
        const cGroupParam* getGroupParam() const;
    private:
        cUnit* mpUnit;  // offset: 0x8
        sSetManager::UNIT_STATE mState;  // offset: 0x10
        u32 mPrio;  // offset: 0x14
        nLayout::stReserveID mReserveID;  // offset: 0x18
        const cGroupParam* mpGroupParam;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class cOmGroupData : public MtObject
    {
    public:
        enum
        {
            TYPE_CH_AREA = 0,
            TYPE_LOT = 2,
            TYPE_NO_MANAGE = 3,
            TYPE_ONCE = 4,
            TYPE_MAX = -1,
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
        cOmGroupData();
        // Address: 0x01acdc20 - 0x01acdc21 (1 bytes)
        virtual ~cOmGroupData() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        sSetManager::cOmGroupData& operator=(const sSetManager::cOmGroupData&);
        void clear();
        void setStageSeq(u32 stage);
        void setGroup(u32 group);
        void setType(u32 type);
        void setPrio(u32 prio);
        u32 getStageSeq() const;
        u32 getGroup() const;
        u32 getType() const;
        u32 getPrio() const;
        u32 getLotFlag() const;
        void setLotFlag(u32 flag);
        bool isEmpty() const;
        void setEmpty();
        bool compareLot(const nLayout::stLayoutID&) const;
        const u32& getGroupData() const;
        void setGroupData(const u32&);
    private:
        union
        {
        public:
            struct
            {
            public:
                u32 mStageSeq : 9;  // offset: 0x0
                u32 mGroup : 9;  // offset: 0x0
                u32 mType : 3;  // offset: 0x0
                u32 mData : 8;  // offset: 0x0
                u32 mPrio : 1;  // offset: 0x0
                u32 mDummy : 2;  // offset: 0x0
            };  // offset: 0x0
            u32 mGroupData;  // offset: 0x0
        };  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    struct stNamedIndex
    {
    public:
        s16 param_idx;  // offset: 0x0
        s16 msg_idx;  // offset: 0x2
    };
public:
    class cEnemyDie : public MtObject
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
        cEnemyDie();
        nLayout::stLayoutID getLayoutId() const;
        void setLayoutId(nLayout::stLayoutID NewValue);
        s32 getSetNo() const;
        void setSetNo(s32 NewValue);
        u32 getEnemyId() const;
        void setEnemyId(u32 NewValue);
    private:
        nLayout::stLayoutID mLayoutId;  // offset: 0x8
        s32 mSetNo;  // offset: 0xc
        u32 mEnemyId;  // offset: 0x10
    public:
        MtVector3 mPos;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class CreateContextParam : public MtObject
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
        CreateContextParam();
    public:
        u32 Id;  // offset: 0x8
        u32 UniqueId;  // offset: 0xc
        s32 StageNo;  // offset: 0x10
        s32 EncountArea;  // offset: 0x14
        static MyDTI DTI;
    };
public:
    struct stEmRegisterData
    {
    public:
        stEmRegisterData();
    public:
        u32 mType;  // offset: 0x0
        u32 mRspnDay;  // offset: 0x4
        u32 mRspnProb;  // offset: 0x8
        u32 mRspnProbAdd;  // offset: 0xc
        u32 mLotFlag;  // offset: 0x10
    };
public:
    template <typename Type>
    class cLotMgr : public MtObject
    {
    public:
        class MyDTI;
        struct DataPackSimultaneous;
    public:
        using cLot = Type;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct DataPackSimultaneous
        {
        public:
            localArray<Type*, 2048, 16384>* mpArray;  // offset: 0x0
            volatile s32 synchronize;  // offset: 0x8
            volatile s32 interlock;  // offset: 0xc
            volatile s32 Arbitrator;  // offset: 0x10
            volatile bool Mediation;  // offset: 0x14
        };
    public:
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cLotMgr();
        virtual ~cLotMgr();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool isUsage(const nLayout::stLayoutID&);
        Type* getLot(const nLayout::stLayoutID& layoutID, const nLayout::stSplitID& SplitID) const;
        Type* getLotFromIndex(u32 index);
        void addLot(Type* p, const nLayout::stLayoutID& layoutID, const nLayout::stSplitID& splitID);
        void eraseLot(const nLayout::stLayoutID& layoutID);
        void eraseLot(const nLayout::stSplitID& splitID);
        void erasePartsLot(const nLayout::stSplitID& splitID);
        u32 getLength() const;
        void update(bool load_flag);
        void execSimultaneousUpdate(uintptr id, uintptr data_address);
        void updatePtr();
        void kill();
        void setRequestAll();
        void setupGroupParam(s32 stageNo, rLayout::TYPE lotType);
        void clearGroupList();
        void addGroupList(rLayoutGroupParamList* prGroupParamList, rLayout::TYPE lotType);
        void addGroup(cGroupParam* pGroupParam, rLayout::TYPE lotType);
        MtTypedArray<cGroupParam>& getGroupList();
        bool isUseGroupList() const;
        bool isSetupGroup() const;
        Type* getLot(const nLayout::stLayoutID& layoutID) const;
        Type* getLot(u32 stageNo, u32 group) const;
    private:
        MtTypedArray<cLayoutSet> mArray;  // offset: 0x8
        rLayoutGroupParamList* mprGroupParamList;  // offset: 0x28
        MtTypedArray<cGroupParam> mGroupList;  // offset: 0x30
        bool mIsSetupGroup;  // offset: 0x50
        MtTypedArray<rLayoutGroupParamList> mGroupParamArray;  // offset: 0x58
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
    sSetManager();
    virtual ~sSetManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void init();
    virtual void setup();  // vtable slot 10
    virtual void move();  // vtable slot 7
    virtual void clear();  // vtable slot 11
    virtual void reset();  // vtable slot 6
    virtual void final();  // vtable slot 12
    static sSetManager* getInstance();
    bool isSetup();
    void csLock();
    void csUnlock();
private:
    void updateUnitData(cUnitData* pUnitData, u32 num);
    void emptyUnitData(cUnitData* pUnitData, u32 num);
public:
    void setUnitDataEnemy(u32 unitID, cUnit* pUnit, u32 prio);
    bool isReserveUnitDataEnemy(u32, const nLayout::stLayoutID&, u32);
    void reserveCancelUnitDataEnemy(u32 unitID, const nLayout::stLayoutID& layoutID, u32 id);
private:
    bool setKilledMgrData(ManageDataArrayCur& ar, const nLayout::stLayoutID& layoutID, s32 setNo, cGroupParam* pGp);
    void clearMgrData(ManageDataArrayCur& arCur);
public:
    u32 getCurrentEnemyGroupDataNum() const;
    const cOmGroupData& getCurrentEnemyGroupData(u32);
    void setCurrentEnemyGroupData(u32, const cOmGroupData&);
    void clearGroupData();
    const cEnemyDie* addEnemyDie(const nLayout::stLayoutID& layoutID, s32 setNo, u32 enemyId, MtVector3& pos);
    MtTypedArray<cEnemyDie>* getEmDieArray();
    cEnemyDie* getEnemyDie(u32);
    u32 getEnemyDieNum();
    void clearEnemyDie();
    void createSet(s32 stageNo);
    void createSetScr(s32 stageNo);
    u32 getSetCount() const;
    MtArray& getGroupList(rLayout::TYPE lotType);
    cLayoutSet* createLotSub(rLayout::TYPE lotType, u32 x, u32 z, cGroupParam* pGP, bool isForceBlockLoad, bool isNoSetUnit);
    void createLotPartsSub(rLayout::TYPE lotType, u32 pd, u32 gr_ofs, u32 area, u32 z, cGroupParam* pGP, bool isForceBlockLoad, bool isNoSetUnit);
    const cGroupParam* getTopPrioGroup(u32 group, s32& index) const;
    bool isTopPrioGroup(u32 group) const;
    void createSplitUnitSet(rLayout::TYPE lotType, u32 x, u32 z, bool isForceBlockLoad);
    void releaseSplitUnitSet(rLayout::TYPE lotType, u32 x, u32 z);
    void createSplitPartsSet(rLayout::TYPE lotType, u32 pd, u32 gr_ofs, u32 area, u32 z, bool isForceBlockLoad);
    void releaseSplitPartsSet(rLayout::TYPE lotType, u32 z);
    bool isKilledEnemy(u32 group, u32 id) const;
    bool isKilledEnemyGroup(u32 group);
    void notifyEmKilled(nLayout::stLayoutID layoutID, s32 setNo, uControl* pObj, u32 enemyId);
    void notifyEmKilledRcv(nLayout::stLayoutID layoutID, s32 setNo, u32 enemyId);
    void callbackEmKilled(nLayout::stLayoutID layoutID, s32 setNo, u32 enemyId);
    void checkDropItemPos(uControlEnemy* pCtrl, MtVector3& em_pos) const;
    bool isRsrcUsageEnemy(u32);
    bool isRsrcUsageOm(u32);
    bool isRsrcUsageScr(u32);
    bool isRsrcUsageNpc(u32);
    REG_RESULT registerEmData(const nLayout::stLayoutID& layoutID, const nLayout::stSplitID& splitID, u32 id, stEmRegisterData omRegister, u32 prio, u32& unitID, const MtVector3& pos, const cGroupParam* pGroupParam);
    void pauseEnemyManage();
    void pauseNpcManage();
    void pauseAllManage();
    bool isMoveEnemy() const;
    bool isMoveNpc() const;
    bool isMoveOm() const;
    bool isMoveScr() const;
    bool isMoveGp() const;
    u32 getGroupPrioUpdateCnt() const;
    bool isEnemyKillAreaInside(u32 group);
    bool isEnemyLifeAreaInside(u32 group);
    void requestSetWaitOff();
    bool isSetWaitOff() const;
    bool isSetPersistentEvenIfNoSbc() const;
    void setSetPersistentEvenIfNoSbc(bool setPersistent);
    bool isLoadAreaUse(rLayout::TYPE lotType);
private:
    void moveEnemy();
    void moveNpc();
    void moveOm();
    void moveScr();
    void moveGp();
    void execMoveEm();
    void execMoveOm();
    void execMoveNpc();
    void execMoveScr();
    void execMoveGp();
    void parallelUpdateGroup(rLayout::TYPE lotType, uintptr interlock, bool isCheckKillArea);
    void execParallelUpdateGroupEm_AH(uintptr interlock);
    void execParallelUpdateGroupOm_AH(uintptr interlock);
    void execParallelUpdateGroupScr_AH(uintptr interlock);
    void execParallelUpdateGroupNpc_AH(uintptr interlock);
    void execParallelUpdateGroupEm(uintptr interlock);
    void execParallelUpdateGroupOm(uintptr interlock);
    void execParallelUpdateGroupScr(uintptr interlock);
    void execParallelUpdateGroupNpc(uintptr interlock);
    void updateGroup(rLayout::TYPE lotType, bool isCheckKillArea);
    void updateGroupPrio(rLayout::TYPE lotType);
    bool updateTopPrioGroup(cGroupParam* pGP, u32 index, nLayout::GROUP_CLASS gc);
    void releaseEmSetData();
    void releaseNpcSetData();
    void releaseOmSetData();
    void releaseScrSetData();
    void releaseGpSetData();
public:
    const cGroupParam* getEnemyGroupParam(u32 group);
    void addPartsGroup(cGroupParam* pParam, rLayout::TYPE lotType);
    uDDOModel* createCharacterInstance(u32 ctrl_type, u32 uid, u32 unit_id, bool ctxt);
    uDDOModel* createEnemyInstance(u32 uid, u32 unit_id, bool ctxt);
    uDDOModel* createNpcInstance(u32, u32, bool);
    uControl* createControlInstance(u32 ctrlType, u32 uid, u32 unit_id);
    uDDOModel* createCharacterInstance(uControl* pCtrl);
    uBaseModel* getLayoutUnit(u32 uid);
    uBaseModel* getLayoutUnitQuest(u32 uniqueId);
    void loadCmnResource();
    void releaseCmnResource();
    rLayoutPreset* getLotPreset() const;
    rNamedParam* getNamedParam() const;
    cNamedParam* getNamedData(u32 namedId);
    bool getNamedMessage(u32 namedId, u32& mesType, u32& mesId);
    s32 getEmNameMsgId(u32 enemyId);
    s32 getEncountAreaNo(u32 uid);
    u32 getEncountAreaNo(const MtVector3& pos, s32* buff, u32 buff_size);
    bool getUnitName(u32 uid, MT_CHAR* buff, u32 len);
    uDDOModel* createEmUnit(u32 uid, u32 enemyId);
private:
    uDDOModel* createUnit(u32 ctrlType, u32 uid, u32 unit_id);
public:
    void sendRequestMaster();
    void sendChangeMaster();
    void sendReleaseMaster();
    void sendThrowMaster(u32 uniqueId, s32 index);
private:
    void controlMaster();
public:
    nNetBase::cNetBase* getNetBase();
private:
    void clearSendMasterInfoAll();
public:
    cContextInstance* getContextMasterSequencial(cContextInstance* pInst);
    void clearMasterInfoAll();
    void clearSendMasterInfo(u32& info);
    void clearThrowMasterInfo();
    void setReleaseMaster(u32 uniqueId);
    u32 getSendMasterInfo(s32 index);
    s32 getSendMasterInfoNum();
    bool setSendMasterInfo(u32 uniqueId);
    u32 getThrowMasterUniqueId();
    s32 getThrowMasterIndex();
    bool checkEncountArea(s32 checkArea, const s32* areaBuff, u32 areaNum);
    MtTypedArray<CreateContextParam>& getCreateContextInfo();
    u32 getCreateContextInfoNum();
    void addCreateContextInfo(u32 Id, u32 UniqueId, s32 StageNo, s32 EncountArea);
    void clearCreateContextInfo();
    void sendCreateContext();
    u32 getSendCreateIndex();
    MtTypedArray<CreateContextParam>& getRequestCreateContextInfo();
    u32 getRequestCreateContextInfoNum();
    void addRequestCreateContextInfo(u32 Id, u32 UniqueId, s32 EncountArea);
    void clearRequestCreateContextInfo();
    void sendRequestCreateContext();
    nLayout::cGameDataCache& getGameDataCache();
    void setEnemySetList(CDataStageLayoutID SLID, const u32 subGroupId, const u32 seed, const u32 questId, const LayoutEnemyDataVec& list);
    void resetEnemySetList(CDataStageLayoutID SLID);
    void repopEnemySet(CDataStageLayoutID SLID, const CLayoutEnemyData data, u32 wait_sec);
    void setOmSetList(CDataStageLayoutID SLID, const LayoutItemDataVec& list);
    void setIsDieStageBossFlag(CDataStageLayoutID SLID);
    void setGatheringItemList(CDataStageLayoutID SLID, const u32 posId, const GatheringItemElementVec& list, bool isUseItemBreak);
    void setGatherItemStatus(const u32 groupId, const u32 posId, u32 status);
    u32 getGatherItemStatus(const u32 groupId, const u32 posId);
    void setDropItemSetList(CDataStageLayoutID SLID, const DropItemSetInfoVec& list);
    void popDropItemSetList(CDataStageLayoutID SLID, const u32 posId, const u8 mdlType, const f64 posX, const f32 posY, const f64 posZ);
    void setDropItemList(CDataStageLayoutID SLID, const u32 posId, const GatheringItemElementVec& list);
    void setDropItemStatus(const u32 groupId, const u32 posId, u32 status);
    void requestGatherAgain(CDataStageLayoutID SLID, const u32 posId);
    void requestSubGroupSetList(u32 groupId, u32 subGroupId);
    void appearEnemySubGroup(CDataStageLayoutID SLID, u32 subGroupId);
    void destroyEnemySetList(CDataStageLayoutID SLID);
    void setGatherEnemyList(CDataStageLayoutID GatheringLayoutId, const u32 GatheringPosId, CDataStageLayoutID EnemyLayoutId, const u32 EnemyPosId);
    void initQuestList();
    void moveQuestList();
    void clearQuestList();
    void addQuestList(u32 questId);
    void delQuestList(u32 questId);
    u32 getPawnExpeditionBoxId(const CDataStageLayoutID& SLID, const u32 posId);
    u32 getPawnExpeditionBoxId(const u32 groupId, const u32 posId);
    u32 getGroupUnitIdFromPawnExpeditionBoxId(const u32 boxId) const;
    void createPawnExpeditionRewardDrop(const u32 pawnRewardBoxId, const u8 mdlType);
    void clearPawnExpeditionAllRewardDrop();
    void clearPawnExpeditionAllRewardDropExcept(const u32 pawnRewardBoxId);
    void setPawnExpeditionRewardDropItemList(const u32 pawnRewardBoxId, const GatheringItemElementVec& itemList);
    bool isPawnExpeditionOmSet() const;
private:
    cOmControl* createPawnExpeditionRewardDropOm(const MtVector3& pos, const u32 pawnRewardBoxId, const u32 unitIdOfCreatedDrop, const u8 mdlType);
public:
    bool isLayoutBurst() const;
private:
    cUnitData mUnitDataEnemy[20];  // offset: 0x18
    bool mIsSetup;  // offset: 0x338
    bool mIsSetRequestEmLot;  // offset: 0x339
    bool mIsSetPersistentEvenIfNoSbc;  // offset: 0x33a
    u32 mSetCount;  // offset: 0x33c
    bool mIsSetWaitOffRequest;  // offset: 0x340
    f32 mGroupPrioUpdateWait;  // offset: 0x344
    u32 mGroupPrioUpdateCnt;  // offset: 0x348
    cGroupParam* mpTopPrioGroup[3];  // offset: 0x350
    u32 mPauseFlag;  // offset: 0x368
    cLotMgr<cLayoutSetEnemy> mEmLotMgr;  // offset: 0x370
    cLotMgr<cLayoutSetNpc> mNpcLotMgr;  // offset: 0x3e8
    cLotMgr<cLayoutSetOm> mQOmLotMgr;  // offset: 0x460
    cLotMgr<cLayoutSetOm> mScrLotMgr;  // offset: 0x4d8
    cLotMgrGeneralPoint mGpLotMgr;  // offset: 0x550
    ManageDataArrayCur mEmGroupDataCur;  // offset: 0x5c8
    rLayoutPreset* mpLotPreset;  // offset: 0x25c8
    rNamedParam* mpNamedParam;  // offset: 0x25d0
    stNamedIndex* mpNamed_ID2Idx;  // offset: 0x25d8
    u32 mNamed_ID2IdxMax;  // offset: 0x25e0
    MtTypedArray<cEnemyDie> mEnemyDie;  // offset: 0x25e8
public:
    nNetBase::cNetBase* mpNetRpc;  // offset: 0x2608
private:
    u32 mSendMasterUniqueId[32];  // offset: 0x2610
    u32 mThrowMasterUniqueId;  // offset: 0x2690
    s32 mThrowMasterIndex;  // offset: 0x2694
public:
    MtTypedArray<CreateContextParam> mRequestCreateContextInfo;  // offset: 0x2698
    MtTypedArray<CreateContextParam> mCreateContextInfo;  // offset: 0x26b8
    u32 mSendCreateIndex;  // offset: 0x26d8
private:
    nLayout::cGameDataCache mGameDataCache;  // offset: 0x26e0
    MtTypedArray<cQuestUnitManager> mQuestUnitMgr;  // offset: 0x27f0
    u32 mPawnExpeditionUnitIdToBoxIdAry[10];  // offset: 0x2810
    cOmControl* mPawnExpeditionOmControlAry[10];  // offset: 0x2838
    u32 mPawnExpeditionNoOfBoxes;  // offset: 0x2888
    bool mIsPawnExpeditionOmSet;  // offset: 0x288c
    bool mDebugClanUnlockClanFlagFlag;  // offset: 0x288d
    bool mDebugClanUnlockFirstFloorFlag;  // offset: 0x288e
    bool mDebugClanUnlockSecondFloorFlag;  // offset: 0x288f
    bool mDebugClanUnlockAkazunomaFlag;  // offset: 0x2890
    bool mEnableLayoutBurst;  // offset: 0x2891
public:
    static MyDTI DTI;
    static const u32 INVALID_STAGE_SEQ = 511;
    static const u32 UNIT_NUM_ENEMY = 20;
private:
    static sSetManager* mpInstance;
    static s32 EM_ARC_LOAD_WAIT;
public:
    static const s32 SEND_MASTER_INFO_MAX = 32;
    static const u32 PAWN_EXPEDITION_INVALID_ID = 99999;
    static const u32 PAWN_EXPEDITION_MAX_REWARDS = 10;
    static const u32 PAWN_EXPEDITION_GEN_POINT_GROUP = 77;
private:
    static const u32 CLAN_KYOTEN_UNLOCK_CLAN_FLAG_GROUP = 50;
    static const u32 CLAN_KYOTEN_UNLOCK_FIRST_FLOOR_GROUP = 51;
    static const u32 CLAN_KYOTEN_UNLOCK_SECOND_FLOOR_GROUP = 52;
    static const u32 CLAN_KYOTEN_UNLOCK_AKAZUNOMA_GROUP = 53;
};

// Inline, no code of its own: checked where it is inlined.
inline sSetManager* sSetManager::getInstance() {
    return ::sSetManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sSetManager::cOmGroupData::cOmGroupData() {
    this->mGroupData = static_cast<u32>(511);
}

// Inline, no code of its own: checked where it is inlined.
inline sSetManager::CreateContextParam::CreateContextParam() {
    this->StageNo = static_cast<s32>(0);
    this->EncountArea = static_cast<s32>(0);
    this->Id = static_cast<u32>(0);
    this->UniqueId = static_cast<u32>(0);
}
