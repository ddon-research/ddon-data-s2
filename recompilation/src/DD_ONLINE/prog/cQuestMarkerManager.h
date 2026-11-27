#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cQuestFunctionManagerBAse.h"
#include "nQuest.h"
#include "rFieldAreaList.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cQuestEventArg;
class cResource;
namespace nQuest { class QUEST_ID; }
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cQuestMarker; }
class rFieldAreaMarkerInfo;
class rQuestMarkerInfo;
class uCharacter;

// Declarations
class cQuestMarkerManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
namespace nQuest { using QuestIdArray = MtTypedArray<nQuest::QUEST_ID>; }
namespace nQuest { using QuestMarkerArray = MtTypedArray<nQuest::cQuestMarker>; }
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cQuestMarkerManager : public cQuestFunctionManagerBase
{
public:
    enum DATA_TYPE
    {
        DATA_TYPE_MINIMAP = 0,
        DATA_TYPE_MAP = 1,
        DATA_TYPE_NUM = 2,
    };
public:
    class MyDTI;
    class cMarkerTask;
    class cQuestSetMarkerInfoBase;
    class cMarkerData;
    class cMarkerInfo;
    class cQuestSetMarkerInfoStage;
    class cQuestSetMarkerInfoFieldArea;
public:
    using MarkerTaskArray = MtTypedArray<cQuestMarkerManager::cMarkerTask>;
    using QuestSetMarkerInfoArray = MtTypedArray<cQuestMarkerManager::cQuestSetMarkerInfoBase>;
    using MarkerDataArray = MtTypedArray<cQuestMarkerManager::cMarkerData>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMarkerTask : public MtObject
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
        static cQuestMarkerManager* getManager();
        static void setManager(cQuestMarkerManager* pMgr);
        nQuest::QUEST_TYPE getQuestType() const;
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        nQuest::QUEST_ID getTargetQuestId() const;
        u32 getTargetQuestIdU32() const;
        nQuest::SCHEDULE_ID getScheduleId() const;
        u32 getScheduleIdU32() const;
        u32 getProcessNo() const;
        cQuestMarkerManager::cMarkerTask& setProcessNo(u32 processNo);
        u32 getStageNo() const;
        cQuestMarkerManager::cMarkerTask& setStageNo(u32 stageNo);
        u32 getGroupNo() const;
        cQuestMarkerManager::cMarkerTask& setGroupNo(u32 groupNo);
        s32 getMapGroupNo() const;
        cQuestMarkerManager::cMarkerTask& setMapGroupNo(s32 mapGroupNo);
        u32 getSetNo() const;
        cQuestMarkerManager::cMarkerTask& setSetNo(u32 setNo);
        u32 getUniqueId() const;
        cQuestMarkerManager::cMarkerTask& setUniqueId(u32 uniqueId);
        const MtVector3& getPos() const;
        cQuestMarkerManager::cMarkerTask& setPos(const MtVector3& pos);
        u32 getPriority() const;
        nQuest::MARKER_DISP_TYPE getTargetType() const;
        cQuestMarkerManager::cMarkerTask& setTargetType(nQuest::MARKER_DISP_TYPE targetType);
        bool isOrder() const;
        bool isClearedQuest() const;
        bool buysHint() const;
    protected:
        bool disableOrder() const;
        u32 calcPriority() const;
    public:
        void move();
        cMarkerTask();
        cMarkerTask(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId);
        virtual ~cMarkerTask();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    protected:
        MtVector3 mPos;  // offset: 0x10
        nQuest::QUEST_ID mQuestId;  // offset: 0x20
        nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x30
        u32 mProcessNo;  // offset: 0x40
        u32 mStageNo;  // offset: 0x44
        u32 mGroupNo;  // offset: 0x48
        u32 mSetNo;  // offset: 0x4c
        u32 mUniqueId;  // offset: 0x50
        u32 mQuestType;  // offset: 0x54
        u32 mPriority;  // offset: 0x58
        s16 mMapGroupNo;  // offset: 0x5c
        u8 mTargetType;  // offset: 0x5e
    public:
        static MyDTI DTI;
    protected:
        static cQuestMarkerManager* mpParent;
    };
public:
    class cQuestSetMarkerInfoBase : public MtObject
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
        u32 getQuestIdU32() const;
        virtual cResource* getMarkerInfoForNpc() const;  // vtable slot 6
        virtual cResource* getMarkerInfoForOm() const;  // vtable slot 7
        bool isFinishedLoading() const;
        virtual void move();  // vtable slot 8
        cQuestSetMarkerInfoBase();
        cQuestSetMarkerInfoBase(nQuest::QUEST_ID questId);
        virtual ~cQuestSetMarkerInfoBase();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::QUEST_ID mQuestId;  // offset: 0x8
        bool mIsFinishedLoading;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    class cMarkerData : public MtObject
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
        const nQuest::QuestMarkerArray& getMarker() const;
        const cQuestMarkerManager::cMarkerTask* getTask() const;
        cQuestMarkerManager::DATA_TYPE getDataType() const;
        bool isSetup() const;
        bool isDiscovery() const;
        bool isValidQuest() const;
        void setMapGroupNo(s32 mapGroupNo);
        void move();
        void updateDisp();
        bool isDispSameStage();
        void setup();
    protected:
        void setupSameStage(nQuest::QuestMarkerArray& marker);
        void setupOtherStage(nQuest::QuestMarkerArray& marker, u32 goalStage) const;
        bool setupMarkerAtDirect(MtVector3& pos) const;
        bool setupMarkerAtLayoutNpc(MtVector3& pos) const;
        bool setupMarkerAtQuestNpc(MtVector3& pos) const;
        bool setupMarkerAtNpcUnit(MtVector3& pos) const;
        bool setupMarkerAtEnemyEncountArea(MtVector3& pos) const;
        bool setupMarkerAtScenario(MtVector3& pos) const;
        bool setupMarkerAtQuestOm(MtVector3& pos) const;
        bool setupMarkerAtLayoutOm(MtVector3& pos) const;
    public:
        cMarkerData();
        cMarkerData(cQuestMarkerManager::cMarkerTask* pTask, u8 dataType);
        virtual ~cMarkerData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nQuest::QuestMarkerArray mMarker;  // offset: 0x8
        cQuestMarkerManager::cMarkerTask* mpParent;  // offset: 0x28
        u8 mDataType;  // offset: 0x30
        bool mIsSetup;  // offset: 0x31
    public:
        static MyDTI DTI;
    };
public:
    class cMarkerInfo
    {
    public:
        cMarkerInfo(cQuestMarkerManager::cMarkerTask* pTask);
    public:
        nQuest::MARKER_DISP_TYPE mType;  // offset: 0x0
    };
public:
    class cQuestSetMarkerInfoStage : public cQuestMarkerManager::cQuestSetMarkerInfoBase
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
        virtual cResource* getMarkerInfoForNpc() const;  // vtable slot 6
        virtual cResource* getMarkerInfoForOm() const;  // vtable slot 7
        virtual void move();  // vtable slot 8
        cQuestSetMarkerInfoStage();
        cQuestSetMarkerInfoStage(nQuest::QUEST_ID questId, u32 stageNo);
        virtual ~cQuestSetMarkerInfoStage();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        rQuestMarkerInfo* mpMarkerInfoNpc;  // offset: 0x20
        rQuestMarkerInfo* mpMarkerInfoOm;  // offset: 0x28
        u32 mStageNo;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
public:
    class cQuestSetMarkerInfoFieldArea : public cQuestMarkerManager::cQuestSetMarkerInfoBase
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
        virtual cResource* getMarkerInfoForNpc() const;  // vtable slot 6
        virtual cResource* getMarkerInfoForOm() const;  // vtable slot 7
        virtual void move();  // vtable slot 8
        cQuestSetMarkerInfoFieldArea();
        cQuestSetMarkerInfoFieldArea(nQuest::QUEST_ID questId, u32 fieldAreaId);
        virtual ~cQuestSetMarkerInfoFieldArea();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        rFieldAreaMarkerInfo* mpMarkerInfoNpc;  // offset: 0x20
        rFieldAreaMarkerInfo* mpMarkerInfoOm;  // offset: 0x28
        u32 mFieldAreaId;  // offset: 0x30
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
    void callbackChangeFieldArea(const rFieldAreaList::cFieldAreaInfo* pFieldAreaInfo);
    void callbackChangeStage(s32 stageNo);
protected:
    void callbackChangeResourceCore(DATA_TYPE dataType, u32 stageNo);
public:
    u32 getCurrentStageNo() const;
protected:
    cQuestSetMarkerInfoBase* getMarkerInfoForQuest(DATA_TYPE dataType, nQuest::QUEST_ID questId) const;
    bool hasQuest(nQuest::QUEST_ID questId);
public:
    void loadQuestSetMarker(nQuest::QUEST_ID questId);
    void releaseQuestSetMarker(nQuest::QUEST_ID questId);
    const MtTypedArray<nQuest::cQuestMarker>& getQuestMarker() const;
    const MtTypedArray<nQuest::cQuestMarker>& getQuestMarkerForMap() const;
    void removeMarker(nQuest::SCHEDULE_ID scheduleId);
    void removeMarker(nQuest::SCHEDULE_ID scheduleId, s32 processNo);
    void removeMarkerAtReturnAreaPos(nQuest::SCHEDULE_ID scheduleId, s32 processNo, u32 stageNo, u32 groupNo);
    void addMarkerAtNpcPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 npcNo);
    void addMarkerAtNpcPosQuestSet(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 setNo, u32 setQuestId);
    void addMarkerAtNpcUnit(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 setNo, u32 setQuestId);
    void addMarkerAtScenarioPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 sceNo);
    void addMarkerAtReturnAreaPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 markerDispType);
    void addMarkerAtQuestOmPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 setNo, u32 questId);
    void addMarkerAtLayoutOmPos(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, u32 groupNo, u32 setNo);
    void addMarkerAtStage(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo);
    void addMarkerAtPrt(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, const MtVector3& pos);
    void addMarkerAtWhiteDragon(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo);
    void addMarkerAtQuestBoard(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo);
    void addMarkerAtWarpPoint(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 warpPointId);
    void addMarkerAtArchibald(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo);
    void addMarkerAtWarehouse(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo);
    void addMarkerAtMyRoomRimStone(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo);
    void addMarkerAtMyRoomPartner(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo);
    void addMarkerAtClanQuestBoard(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo);
    void addMarkerAtPhoto(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo, u32 stageNo, const MtVector3& pos);
    void addMarkerAtRenten(nQuest::QUEST_TYPE questType, nQuest::SCHEDULE_ID scheduleId, u32 processNo);
    bool hasMarkerNpc(nQuest::SCHEDULE_ID scheduleId, u32 npcId, nQuest::QUEST_ID setQuestId) const;
    nQuest::SCHEDULE_ID getScheduleIdMarkerHakuryuu() const;
    nQuest::SCHEDULE_ID getScheduleIdFromMarkerType(nQuest::MARKER_DISP_TYPE type) const;
    nQuest::SCHEDULE_ID getScheduleIdFromMarkerWarpPoint(u32 warpPointId) const;
    nQuest::SCHEDULE_ID getScheduleIdFromFunc(bool(*pFunc)(cMarkerInfo*)) const;
    nQuest::SCHEDULE_ID getScheduleIdFromFunc(MtObject* pClass, bool(MtObject::*pFunc)(cMarkerInfo*)) const;
    nQuest::cQuestMarker* getQuestMarkerEm(nQuest::SCHEDULE_ID scheduleId, uCharacter* pEm) const;
protected:
    void addMarkerTask(cMarkerTask* pTask);
    void addDispMarkerList(nQuest::QuestMarkerArray& dispMarkerList, const MarkerDataArray& src, bool enableQuestMarker) const;
    cMarkerTask* getMarkerTask(nQuest::SCHEDULE_ID scheduleId, u32 processNo) const;
    bool isModifiedPriority() const;
    void modifyPriority();
public:
    void move();
protected:
    void requestLoadResource();
    void calcPriority();
    void updateDisp();
    void callbackActiveQuest(cQuestEventArg* pArg);
    void callbackOrderQuest(cQuestEventArg* pArg);
    void callbackBuyHint(cQuestEventArg* pArg);
    void callbackKilledEnemy(cQuestEventArg* pArg);
    void callbackContentsPlayStart(cQuestEventArg* pArg);
    void callbackUpdateCache(cQuestEventArg* pArg);
    void sortMarkerDataList();
public:
    cQuestMarkerManager();
    virtual ~cQuestMarkerManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void release();  // vtable slot 6
protected:
    MarkerTaskArray mMarkerTask;  // offset: 0x8
    nQuest::QuestIdArray mQuestList;  // offset: 0x28
    QuestSetMarkerInfoArray mSetupQuestListMarker;  // offset: 0x48
    QuestSetMarkerInfoArray mQuestListMarker[2];  // offset: 0x68
    MarkerDataArray mSetupMarkerData;  // offset: 0xa8
    MarkerDataArray mSetupMapGroupNo;  // offset: 0xc8
    MarkerDataArray mMarkerData[2];  // offset: 0xe8
    nQuest::QuestMarkerArray mMarkerDispList[2];  // offset: 0x128
    cMarkerData* mpNpcUnitMarkerData[2];  // offset: 0x168
    u32 mCurrentStageNo;  // offset: 0x178
    bool mIsModifiedPriority;  // offset: 0x17c
public:
    static MyDTI DTI;
};

inline void* cQuestMarkerManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cQuestMarkerManager::getCurrentStageNo() const {
    return this->mCurrentStageNo;
}

inline void* cQuestMarkerManager::cMarkerTask::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cQuestMarkerManager::cMarkerTask::setManager(cQuestMarkerManager* pMgr) {
    ::cQuestMarkerManager::cMarkerTask::mpParent = pMgr;
}

inline nQuest::QUEST_TYPE cQuestMarkerManager::cMarkerTask::getQuestType() const {
    return static_cast<nQuest::QUEST_TYPE>(this->mQuestType);
}

inline u32 cQuestMarkerManager::cMarkerTask::getProcessNo() const {
    return this->mProcessNo;
}

inline u32 cQuestMarkerManager::cMarkerTask::getGroupNo() const {
    return this->mGroupNo;
}

inline u32 cQuestMarkerManager::cMarkerTask::getSetNo() const {
    return this->mSetNo;
}

inline void* cQuestMarkerManager::cQuestSetMarkerInfoBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestMarkerManager::cQuestSetMarkerInfoBase::cQuestSetMarkerInfoBase() {
    this->mIsFinishedLoading = false;
}

inline void* cQuestMarkerManager::cMarkerData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestMarkerManager::cMarkerData::cMarkerData() {
    this->mpParent = nullptr;
    this->mDataType = 0;
    this->mIsSetup = false;
}

inline void* cQuestMarkerManager::cQuestSetMarkerInfoStage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestMarkerManager::cQuestSetMarkerInfoStage::cQuestSetMarkerInfoStage() {
    this->mStageNo = 0;
    this->mpMarkerInfoOm = nullptr;
    this->mpMarkerInfoNpc = nullptr;
}

inline void* cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::cQuestSetMarkerInfoFieldArea() {
    this->mFieldAreaId = 0;
    this->mpMarkerInfoOm = nullptr;
    this->mpMarkerInfoNpc = nullptr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cQuestMarkerManager::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::DTI);
}

inline void cQuestMarkerManager::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::DTI)->memFree(p_addr);
}

inline void cQuestMarkerManager::cMarkerTask::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cMarkerTask::DTI)->memFree(p_addr);
}

inline void* cQuestMarkerManager::cQuestSetMarkerInfoBase::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cQuestSetMarkerInfoBase::DTI)->memAlloc(sz, align, ::cQuestMarkerManager::cQuestSetMarkerInfoBase::DTI.::MtDTI::getID());
}

inline void cQuestMarkerManager::cQuestSetMarkerInfoBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cQuestSetMarkerInfoBase::DTI)->memFree(p_addr);
}

inline void* cQuestMarkerManager::cMarkerData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cMarkerData::DTI)->memAlloc(sz, align, ::cQuestMarkerManager::cMarkerData::DTI.::MtDTI::getID());
}

inline void cQuestMarkerManager::cMarkerData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cMarkerData::DTI)->memFree(p_addr);
}

inline void* cQuestMarkerManager::cQuestSetMarkerInfoStage::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cQuestSetMarkerInfoStage::DTI)->memAlloc(sz, align, ::cQuestMarkerManager::cQuestSetMarkerInfoStage::DTI.::MtDTI::getID());
}

inline void cQuestMarkerManager::cQuestSetMarkerInfoStage::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cQuestSetMarkerInfoStage::DTI)->memFree(p_addr);
}

inline void* cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::DTI)->memAlloc(sz, align, ::cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::DTI.::MtDTI::getID());
}

inline void cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestMarkerManager::cQuestSetMarkerInfoFieldArea::DTI)->memFree(p_addr);
}
