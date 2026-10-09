#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Enemy.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "MtString.h"
#include "Stage.h"
#include "cAreaHit.h"
#include "cResource.h"
#include "nDDOUtility.h"
#include "nLayout.h"
#include "rLayout.h"

// Forward declarations
class AreaHitShape;
class CDataDropItemSetInfo;
class CDataLayoutEnemyData;
class CDataLayoutItemData;
class CDataNamedEnemyParamClient;
class CDataStageLayoutEnemyPresetEnemyInfoClient;
class CDataStageLayoutID;
class MtAllocator;
class MtArray;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtSphere;
class MtStream;
class MtString;
class MtVector3;
class cAreaHit;
class cLayoutSetEnemy;
class cLayoutSetOm;
class cOmControl;
namespace nLayout { struct stLayoutID; }
namespace nLayout { struct stSplitID; }
namespace nLayoutGroupParam { struct NeedAllocCountInfo; }

// Declarations
class cGroupParam;
namespace nLayoutGroupParam { struct NativeAllocInfo; }
class rLayoutGroupParamList;

// Type aliases from DWARF
using CLayoutEnemyData = CDataLayoutEnemyData;
using DropItemSetInfoVec = MtTypedArray<CDataDropItemSetInfo>;
using LayoutEnemyDataVec = MtTypedArray<CDataLayoutEnemyData>;
using LayoutItemDataVec = MtTypedArray<CDataLayoutItemData>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cGroupParam : public MtObject
{
    // inferred: cLayoutSetEnemy::moveSetUnit names cGroupParam::mKillAreaType
    friend class cLayoutSetEnemy;
    // inferred: cLayoutSetOm::moveSetUnit names cGroupParam::mKillAreaType
    friend class cLayoutSetOm;
public:
    enum KILL_AREA_TYPE
    {
        KILL_AREA_ALL = 0,
        KILL_AREA_SHAPE = 1,
    };
    enum
    {
        INVALID_NONE = 0,
        INVALID_DEMO_LOT = 1,
        INVALID_KILL_AREA = 2,
        INVALID_SIMPLE_EV = 4,
        INVALID_RESET = 8,
        INVALID_LAYOUT = 16,
        INVALID_RAND = 32,
        INVALID_STAGE = 64,
        INVALID_VERSION = 128,
        INVALID_OMIT = 256,
    };
    enum
    {
        OM_DRIFT_NONE = 0,
        OM_DRIFT_EXIST = 1,
        OM_DRIFT_NOT_EXIST = 2,
    };
    enum DROP_TYPE
    {
        SET_TYPE_DROP = 0,
        SET_TYPE_AREA = 1,
    };
public:
    class MyDTI;
    struct stLoadCondition;
    struct GuardData;
    struct stSetCondition;
    struct stDeleteCondition;
    class cLifeArea;
    class cID;
    class EmSetInfo;
    class OmSetInfo;
    class DropItemInfo;
    class cUnitData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stLoadCondition
    {
    public:
        stLoadCondition();
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mLotFlag : 1;  // offset: 0x0
                u32 mLayoutFlag : 1;  // offset: 0x0
                u32 mRandomOnly : 1;  // offset: 0x0
                u32 mStage : 1;  // offset: 0x0
                u32 mVersion : 1;  // offset: 0x0
                u32 mOmit : 1;  // offset: 0x0
            };  // offset: 0x0
            u32 mLoadCondition;  // offset: 0x0
        };  // offset: 0x0
    };
public:
    struct GuardData
    {
    public:
        u32 mQuestNo;  // offset: 0x0
        u32 mLayoutFlagNo;  // offset: 0x4
    };
public:
    struct stSetCondition
    {
    public:
        stSetCondition();
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mAreaHit : 1;  // offset: 0x0
                u32 mSimpleEv : 1;  // offset: 0x0
                u32 mSetMax : 8;  // offset: 0x0
            };  // offset: 0x0
            u32 mSetCondition;  // offset: 0x0
        };  // offset: 0x0
    };
public:
    struct stDeleteCondition
    {
    public:
        stDeleteCondition();
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mLotFlag : 1;  // offset: 0x0
                u32 mLayoutFlag : 1;  // offset: 0x0
            };  // offset: 0x0
            u32 mDeleteCondition;  // offset: 0x0
        };  // offset: 0x0
    };
public:
    class cLifeArea : public MtObject
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
        void copy(const cGroupParam::cLifeArea* pParam);
        cLifeArea();
        virtual ~cLifeArea();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r, nLayoutGroupParam::NativeAllocInfo& buffer);  // vtable slot 6
        virtual bool save(MtDataWriter& w);  // vtable slot 7
        void traceForIOCheck();
        void registerNeedElemntNum(nLayoutGroupParam::NeedAllocCountInfo& info);
        void setAutoDeleteInternalArray(bool IsNewAutoDelete);
        const AreaHitShape* getNode(u32 index) const;
        u32 getNodeNum() const;
        AreaHitShape* getShape(u32 index) const;
    private:
        MtTypedArray<AreaHitShape> mShapeList;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cID : public MtObject
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
        cID();
        cID(const nLayout::stLayoutID&, const nLayout::stSplitID&);
        // Address: 0x01a9a400 - 0x01a9a401 (1 bytes)
        virtual ~cID() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r);  // vtable slot 6
        virtual bool save(MtDataWriter& w);  // vtable slot 7
        void traceForIOCheck();
        void copy(const cGroupParam::cID& id);
        const nLayout::stLayoutID& getLayoutID() const;
        u32 getArea() const;
        u32 getGroup() const;
        void setLayoutID(const nLayout::stLayoutID&);
        void setArea(u32 area);
        void setGroup(u32 group);
        const nLayout::stSplitID& getSplitID() const;
        s32 getSplitX() const;
        s32 getSplitZ() const;
        void setSplitID(const nLayout::stSplitID&);
        void setSplitX(u32 x);
        void setSplitZ(u32 z);
    private:
        nLayout::stLayoutID mLayoutID;  // offset: 0x8
        nLayout::stSplitID mSplitID;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
public:
    class EmSetInfo : public MtObject
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
        EmSetInfo();
        u32 getUnitID() const;
    public:
        u32 mID;  // offset: 0x8
        CDataStageLayoutEnemyPresetEnemyInfoClient mPresetInfo;  // offset: 0x10
        u32 mHmRandom;  // offset: 0x38
        u32 mMontageRandom;  // offset: 0x3c
        f32 mRepopTimer;  // offset: 0x40
        u32 mSubGroupId;  // offset: 0x44
        u32 mLayerNo;  // offset: 0x48
        s32 mTblIndex;  // offset: 0x4c
        bool mIsWaitGather;  // offset: 0x50
        u32 mOmUID;  // offset: 0x54
        static MyDTI DTI;
    };
public:
    class OmSetInfo : public MtObject
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
        OmSetInfo();
    public:
        u32 mID;  // offset: 0x8
        u32 mStatus;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class DropItemInfo : public MtObject
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
        DropItemInfo();
        virtual ~DropItemInfo();
    public:
        u16 mSetType;  // offset: 0x8
        u16 mID;  // offset: 0xa
        u32 mStatus;  // offset: 0xc
        u32 mDropId;  // offset: 0x10
        u8 mMdlType;  // offset: 0x14
        MtVector3 mDropPos;  // offset: 0x20
        cOmControl* mpOmControl;  // offset: 0x30
        static MyDTI DTI;
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
        virtual ~cUnitData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r);  // vtable slot 6
        virtual bool save(MtDataWriter& w);  // vtable slot 7
        void traceForIOCheck();
    public:
        MtString name;  // offset: 0x8
        bool isBelong;  // offset: 0x10
        const MtDTI* pDti;  // offset: 0x18
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
    cGroupParam();
    virtual ~cGroupParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyCmn(MtPropertyList& s);  // vtable slot 6
    virtual void createPropertySet(MtPropertyList& s);  // vtable slot 7
    virtual void createPropertyLife(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertyKill(MtPropertyList& s);  // vtable slot 9
    void final();
    virtual bool load(MtDataReader& r, nLayoutGroupParam::NativeAllocInfo& buffer);  // vtable slot 10
private:
    u32 getDataCommon() const;
    void setDataCommon(u32 data);
    u32 getDataLotFlag() const;
    void setDataLotFlag(u32 data);
    u32 getQuestNoPrivate() const;
    void setQuestNoPrivate(u32 NewValue);
    u32 getLayoutFlagNoPrivate() const;
    void setLayoutFlagNoPrivate(u32 NewValue);
    u32 getDataPriority() const;
    void setDataPriority(u32);
public:
    void clearWork();
    void setAreaOffset(MtVector3& ofs);
    void copy(const cGroupParam& r);
    cGroupParam& operator=(const cGroupParam&);
    u32 getGroup() const;
    u32 getPriority() const;
    bool isDisableSplit() const;
    bool isParts() const;
    bool hasMarkerPos() const;
    bool isLoadLotFlag() const;
    bool isLoadLayoutFlag() const;
    bool isLoadRandomOnly() const;
    u32 getLotFlagNo() const;
    u32 getQuestNo() const;
    u32 getLayoutFlagNo() const;
    bool isLoadStage() const;
    u32 getLoadStageNo() const;
    bool isLoadVersion() const;
    u32 getLoadVersionNo() const;
    bool isLoadOmit() const;
    bool isSetAreaHit() const;
    bool isSetSimpleEv() const;
    s32 getSetMax() const;
    bool isDeleteLotFlag() const;
    bool isDeleteLayoutFlag() const;
    u32 getDataNum() const;
    void setGroup(u32 group);
    void setDummy(u32 d);
    void setIsDisableSplit(bool b);
    void setIsParts(bool b);
    void setSetMax(s32 no);
    void setHasMarkerPos(bool b);
    void initAreaHit();
    u32 getDetectedAreaHit();
    void deleteAreaHit();
    MtVector3 getMarkerPos() const;
    void setMarkerPos(MtVector3& pos);
    MtVector3 getPartsOffset() const;
    void setPartsOffset(MtVector3& ofs);
    u32 getLayer() const;
    void setLayer(u32);
    bool getIsLoadLotRes() const;
    void setIsLoadLotRes(const bool load);
    u32 getAlivePriority() const;
    void setAlivePriority(u32);
    u32 getAlivePriorityCnt() const;
    void setAlivePriorityCnt(u32);
    const cLifeArea* getLifeArea(u32 index) const;
    KILL_AREA_TYPE getKillAreaType() const;
    void setKillAreaType(KILL_AREA_TYPE);
    const MtTypedArray<AreaHitShape>& getKillArea() const;
    bool isKillAreaInside(const MtVector3& pos) const;
    MtVector3 getKillAreaCenter() const;
    bool isLifeAreaInside(const MtVector3& pos) const;
    u32 getLifeAreaNum() const;
    f32 distNearLifeAreaCenter(const MtVector3& pos) const;
    bool isLoadAreaInside(const MtVector3& pos);
    void clearID();
    void addID(const nLayout::stLayoutID&, const nLayout::stSplitID&);
    u32 getLayoutIDNum() const;
    const nLayout::stLayoutID& getLayoutID(u32);
    const nLayout::stSplitID& getSplitID(u32);
    u32 getSplitX(u32) const;
    u32 getSplitZ(u32) const;
    const nLayout::stLayoutID* searchLayoutID(u32 splitX, u32 splitZ) const;
    u32 update(bool isCheckKillArea);
    void updatePtr();
    bool isValidGroup() const;
    bool isWaitRepop(u32 posId) const;
    u32 getInvalidFlag() const;
    void setAutoDeleteInternalArray(bool IsNewAutoDelete);
    bool isQuestLayoutFlag() const;
    bool isDieStageBoss() const;
    void setIsDieStageBossFlag();
private:
    void setLoadLotFlag(bool b);
    void setLoadLayoutFlag(bool b);
    void setLoadRandomOnly(bool b);
    void setLoadStage(bool b);
    void setLoadVersion(bool b);
    void setLoadOmit(bool b);
    void setLotFlagNo(u32 no);
    void setQuestNo(u32 no);
    void setLayoutFlagNo(u32 no);
    void setLoadStageNo(u32 no);
    void setLoadVersionNo(u32 no);
    void setPriority(u32 prio);
    void setSetAreaHit(bool b);
    void setSetSimpleEv(bool b);
    void setDeleteLotFlag(bool b);
    void setDeleteLayoutFlag(bool b);
public:
    EmSetInfo* getEmSetInfo(u32 posId);
    EmSetInfo* addEmSetInfo(u32 posID, CDataStageLayoutEnemyPresetEnemyInfoClient data);
    void deleteEmSetInfo(u32 posID);
    void setEnemySetList(const u32 subGroupId, const u32 layerNo, u32 seed, u32 questId, const LayoutEnemyDataVec& list);
    void repopEnemySet(const CLayoutEnemyData data, u32 wait_sec);
    void setGatherEnemyList(const u32 posId, CDataStageLayoutID GatheringLayoutId, const u32 GatheringPosId);
    OmSetInfo* getOmSetInfo(u32 id);
    OmSetInfo* addOmSetInfo(u32 id, u32 stat);
    void setOmSetList(const LayoutItemDataVec& list);
    DropItemInfo* getDropItemSetInfo(u32 id);
    DropItemInfo* addDropItemSetInfo(u32 id, u8 mdlType, MtVector3& pos, u32 setType);
    void setDropItemSetList(const DropItemSetInfoVec& list);
    bool deleteDropItemSetInfo(u32 id);
    void clearSetInfo();
    u32 getSetInfoNum() const;
    u32 getSetGatherNum() const;
    void setRequestList(bool f);
    bool isRequestList() const;
    void setSetupList(bool);
    bool isSetupList() const;
    void setResetList(bool f);
    bool isResetList() const;
    void setRequestSubList(u32 no, bool f);
    bool isRequestSubList(u32 no) const;
    void setSetupSubList(u32 no, bool f);
    bool isSetupSubList(u32 no) const;
    void setDriftType(u8 type);
    u8 getDriftType() const;
    MtArray& getResetContextList();
    void clearResetContextList();
    void clearDropItem();
    u32 getDropItemNum() const;
    DropItemInfo* getDropItem(u32) const;
    MtArray& getDropItem();
    void setRequestDrop(bool);
    bool isRequestDrop() const;
    void setSetupDrop(bool);
    bool isSetupDrop() const;
    void resetEnemySetList(f32 frame);
    f32 getTransparency() const;
    bool isDestroy() const;
    void destroyEnemySetList();
    u32 getGroupQuestId() const;
public:
    MtArray mLayoutDataList;  // offset: 0x8
    rLayout::TYPE mLotType;  // offset: 0x28
    union
    {
    public:
        struct
        {
        public:
            u32 mGroup : 9;  // offset: 0x0
            u32 mPriority : 18;  // offset: 0x0
            u32 mIsDisableSplit : 1;  // offset: 0x0
            u32 mIsParts : 1;  // offset: 0x0
            u32 mHasMarkerPos : 1;  // offset: 0x0
        };  // offset: 0x0
        u32 mDataCommon;  // offset: 0x0
    };  // offset: 0x2c
private:
    stLoadCondition mLoadCondition;  // offset: 0x30
    union
    {
    public:
        struct
        {
        public:
            u32 mLotFlagNo : 16;  // offset: 0x0
        };  // offset: 0x0
        u32 mDataLotFlag;  // offset: 0x0
    };  // offset: 0x34
    GuardData mGuardData;  // offset: 0x38
    u32 mLoadStageNo;  // offset: 0x40
    u32 mLoadVersionNo;  // offset: 0x44
    stSetCondition mSetCondition;  // offset: 0x48
    MtTypedArray<AreaHitShape> mAreaHitShapeList;  // offset: 0x50
    MtVector3 mMarkerPos;  // offset: 0x70
    MtVector3 mPartsOffset;  // offset: 0x80
    u32 mLayer;  // offset: 0x90
    MtSphere mLoadArea;  // offset: 0xa0
    bool mIsLoadLotRes;  // offset: 0xb0
    bool mIsKillAreaInside;  // offset: 0xb1
    stDeleteCondition mDeleteCondition;  // offset: 0xb4
    MtTypedArray<cLifeArea> mLifeAreaArray;  // offset: 0xb8
    KILL_AREA_TYPE mKillAreaType;  // offset: 0xd8
    MtTypedArray<AreaHitShape> mKillAreaList;  // offset: 0xe0
    MtTypedArray<cAreaHit> mAreaHitList;  // offset: 0x100
    union
    {
    public:
        struct
        {
        public:
            u32 mInvalidFlag : 16;  // offset: 0x0
            u32 mAlivePriority : 8;  // offset: 0x0
        };  // offset: 0x0
        u32 mDataPriority;  // offset: 0x0
    };  // offset: 0x120
    u32 mAlivePriorityCnt;  // offset: 0x124
    u32 mAreaHitUseCount;  // offset: 0x128
    bool mIsDieStageBoss;  // offset: 0x12c
    MtTypedArray<cID> mLayoutIDArray;  // offset: 0x130
protected:
    MtArray mSetInfoList;  // offset: 0x150
    u32 mRandomSeed;  // offset: 0x170
    bool mIsRequestList;  // offset: 0x174
    bool mIsSetupList;  // offset: 0x175
    bool mIsResetList;  // offset: 0x176
    MtArray mResetContextList;  // offset: 0x178
    u8 mDriftType;  // offset: 0x198
    u32 mSubGroupRequestBit;  // offset: 0x19c
    u32 mSubGroupSetupBit;  // offset: 0x1a0
    MtArray mDropItemList;  // offset: 0x1a8
    bool mIsRequestDrop;  // offset: 0x1c8
    bool mIsSetupDrop;  // offset: 0x1c9
    nDDOUtility::cArray<CDataNamedEnemyParamClient, 5> mNameEnemyParams;  // offset: 0x1d0
    f32 mResetTimer;  // offset: 0x310
    bool mIsDestroy;  // offset: 0x314
    u32 mGroupQuestId;  // offset: 0x318
public:
    static MyDTI DTI;
protected:
    static const u32 MAX_NAMED_ENEMY_PARAM_NUM = 5;
public:
    static const f32 SET_RESET_TIMER;
};

namespace nLayoutGroupParam {
    struct NativeAllocInfo
    {
    public:
        cGroupParam::cID* pIdArray;  // offset: 0x0
        u32 IdUseNum;  // offset: 0x8
        u32 IdMaxNum;  // offset: 0xc
        cGroupParam::cLifeArea* pLifeAreaArray;  // offset: 0x10
        u32 LifeAreaUseNum;  // offset: 0x18
        u32 LifeAreaMaxNum;  // offset: 0x1c
        AreaHitShape* pAreaHitShapeArray;  // offset: 0x20
        u32 AreaHitShapeUseNum;  // offset: 0x28
        u32 AreaHitShapeMaxNum;  // offset: 0x2c
        AreaHitShape::NativeAllocInfo ShapeAllocInfo;  // offset: 0x30
    };
}  // namespace nLayoutGroupParam

class rLayoutGroupParamList : public cResource
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
    rLayoutGroupParamList();
    virtual ~rLayoutGroupParamList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void destruct();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getGroupListData(u32 index);
    void setGroupListData(u32, u32);
    cGroupParam* getGroupParam(u32 index);
    u32 getGroupParamNum();
protected:
    u32 getDataVersion() const;
    u32 getMagicHeader() const;
protected:
    u32 mGroupList[512];  // offset: 0x70
    u32 mGroupNum;  // offset: 0x870
    cGroupParam* mpGroupParamBuff;  // offset: 0x878
    nLayoutGroupParam::NativeAllocInfo mAllocInfo;  // offset: 0x880
public:
    static MyDTI DTI;
    static const u32 GROUP_NUM = 512;
protected:
    static const u8 DATA_VERSION;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cGroupParam::getIsLoadLotRes() const {
    return this->mIsLoadLotRes;
}

// Inline, no code of its own: checked where it is inlined.
inline cGroupParam::OmSetInfo::OmSetInfo() {
    this->mID = static_cast<u32>(0);
    this->mStatus = static_cast<u32>(0);
}
