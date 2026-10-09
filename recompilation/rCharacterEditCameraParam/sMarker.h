#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cSystem.h"
#include "../shared/nMarker.h"
#include "../shared/rFieldAreaList.h"
#include "../shared/rQuestMarkerInfo.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cArcLoaderBase;
namespace nMarker { class cMarkerInfo; }
namespace nMarker { class cWarpMarkerInfo; }
namespace nMarker { class cWarpMarkerInfoStage; }
namespace nQuest { class cQuestMarker; }
class rDungeonMarker;
class rFieldAreaAdjoinList;
class rFieldAreaList;
class rFieldAreaMarkerInfo;
class rGUIMessage;
class rQuestMarkerInfo;
class rStageAdjoinList;

// Declarations
class sMarker;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
namespace nMarker { using MarkerInfoArray = MtTypedArray<nMarker::cMarkerInfo>; }
namespace nMarker { using WarpMarkerInfoArray = MtTypedArray<nMarker::cWarpMarkerInfo>; }
namespace nMarker { using WarpMarkerInfoStageArray = MtTypedArray<nMarker::cWarpMarkerInfoStage>; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sMarker : public cSystem
{
public:
    enum DATA_TYPE
    {
        DATA_TYPE_STAGE = 0,
        DATA_TYPE_FIELD_AREA = 1,
        DATA_TYPE_NUM = 2,
    };
public:
    class MyDTI;
    class cLoadResource;
public:
    using LoadResourceArray = MtTypedArray<sMarker::cLoadResource>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLoadResource : public MtObject
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
        sMarker::DATA_TYPE getDataType() const;
        cLoadResource();
        cLoadResource(sMarker::DATA_TYPE dataType);
    protected:
        sMarker::DATA_TYPE mDataType;  // offset: 0x8
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
    const nMarker::cMarkerInfo* getMarkerInfoStage(const nQuest::cQuestMarker* pMarker);
    const nMarker::cMarkerInfo* getMarkerInfoFieldArea(const nQuest::cQuestMarker* pMarker);
    void getStageWarpAdjoinMarkerInfo(const MtVector3& targetPos, nMarker::cMarkerInfo& markerInfo);
    void getStageWarpAdjoinMarkerInfo(u32 targetParts, nMarker::cMarkerInfo& markerInfo);
    const nMarker::cMarkerInfo* getStageAdjoinMarkerInfo(s32 stageNo);
    const nMarker::cMarkerInfo* getFieldAreaAdjoinMarkerInfo(s32 stageNo);
    const nMarker::cMarkerInfo* getFieldAreaAdjoinMarkerInfoFromCache(s32 stageNo);
    s32 getStageNo() const;
    s32 getLoadFieldAreaId() const;
    u32 getDispFieldAreaNum() const;
    u32 getDispFieldAreaNumFromFieldId(u32 fieldId) const;
    u32 getDispFieldAreaNumFromStageNo(u32 stageNo) const;
    u32 getDispFieldAreaId(u32 idx) const;
    u32 getDispFieldAreaIdFromLandId(u32 landId) const;
    u32 getDispLandFieldAreaId() const;
    u32 getFieldAreaIdFromBelongStage(s32 stageNo) const;
    u32 getFieldAreaIdFromStageList(s32 stageNo) const;
    s32 getStageNoFromFieldAreaId(u32 idx, u32 stageNo) const;
    s32 getStageNoFromDispFieldAreaIdx(u32 dispStageNo, u32 idx) const;
    const rFieldAreaList::cFieldAreaInfo* getFieldAreaInfo(u32 landId) const;
    MT_CTSTR getFieldAreaName(u32 fieldAreaId) const;
protected:
    const nMarker::cMarkerInfo* getMarkerInfoStageWarp(const nQuest::cQuestMarker* pMarker);
    void updateMarkerInfoStageWarpCache();
    bool hasCachedFieldAreaAdjoinMarkerInfo(s32 stageNo);
    nMarker::cWarpMarkerInfo* getWarpAdjoinMarkerinfo(const nQuest::cQuestMarker* pMarker) const;
    nMarker::cWarpMarkerInfoStage* getWarpAdjoinMarkerinfoStageList(const nQuest::cQuestMarker* pMarker) const;
    nMarker::cWarpMarkerInfo* cacheWarpAdjoinMarkerInfo(const nQuest::cQuestMarker* pMarker);
    nMarker::cWarpMarkerInfoStage* cacheWarpAdjoinMarkerInfoStageList(const nQuest::cQuestMarker* pMarker);
    bool getConnectPos(const MtVector3& currentPos, const MtVector3& targetPos, nMarker::cMarkerInfo& outputMarkersInfo);
public:
    void initStage();
    void initGame();
    void finalGame();
    bool hasChangedFieldAreaResource() const;
    bool isLoadFieldAreaResource(s32 stageNo) const;
    const rQuestMarkerInfo* getStageMarkerInfo(rQuestMarkerInfo::RES_TYPE resType) const;
    const rFieldAreaMarkerInfo* getFieldAreaMarkerInfo(rQuestMarkerInfo::RES_TYPE resType) const;
protected:
    bool isFinishedLoadingArchive(DATA_TYPE dataType) const;
    bool isFinishedLoadingResource(DATA_TYPE dataType) const;
    void loadResourceStage();
    void loadResourceFieldArea();
public:
    bool changeFieldAreaResource(s32 fieldAreaId);
    bool changeFieldAreaResourceFromStageNo(s32 stageNo);
    static sMarker* getInstance();
    sMarker();
    virtual ~sMarker();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
protected:
    nMarker::MarkerInfoArray mDungeonAdjoinMarkerInfoList;  // offset: 0x18
    nMarker::MarkerInfoArray mStageAdjoinMarkerInfoList;  // offset: 0x38
    nMarker::MarkerInfoArray mFieldAreaAdjoinMarkerInfoList;  // offset: 0x58
    nMarker::WarpMarkerInfoArray mWarpAdjoinMarkerInfoList;  // offset: 0x78
    nMarker::WarpMarkerInfoStageArray mWarpAdjoinMarkerInfoStageList;  // offset: 0x98
    LoadResourceArray mLoadResourceList;  // offset: 0xb8
    TICKET mTicket[2];  // offset: 0xd8
    rFieldAreaList* mpFieldAreaList;  // offset: 0xe8
    rStageAdjoinList* mpStageAdjoinListRes;  // offset: 0xf0
    rFieldAreaAdjoinList* mpFieldAreaAdjoinListRes;  // offset: 0xf8
    rQuestMarkerInfo* mpStageMarkerInfo[4];  // offset: 0x100
    rFieldAreaMarkerInfo* mpFieldAreaMarkerInfo[4];  // offset: 0x120
    rGUIMessage* mpFieldAreaName;  // offset: 0x140
    rDungeonMarker* mpDungeonMarker;  // offset: 0x148
    s32 mStageNo;  // offset: 0x150
    s32 mFieldAreaId;  // offset: 0x154
    s32 mMapFloorGroupNo;  // offset: 0x158
    bool mIsFinishLoad[2];  // offset: 0x15c
public:
    static MyDTI DTI;
protected:
    static sMarker* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sMarker::cLoadResource::cLoadResource() {
    this->mDataType = static_cast<sMarker::DATA_TYPE>(0);
}
