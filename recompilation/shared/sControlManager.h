#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cSystem.h"
#include "uControl.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cContextInstance;
namespace nLayout { struct stLayoutID; }
class uControl;
class uControlEnemy;
class uControlNpc;
class uDDOModel;

// Declarations
class sControlManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class sControlManager : public cSystem
{
public:
    enum
    {
        ADD_TYPE_TOP = 0,
        ADD_TYPE_BOTTOM = 1,
    };
    enum
    {
        DISP_CAMERA_LENGTH_TYPE_NEAR = 0,
        DISP_CAMERA_LENGTH_TYPE_FAR = 1,
        DISP_CAMERA_LENGTH_TYPE_NUM = 2,
    };
    enum
    {
        MY_PLAYER = 0,
        FORCE_DISP = 1,
        LOAD_CTRL = 2,
        PT_PLAYER = 3,
        PT_PAWN = 4,
        ELSE_PLAYER = 5,
        QUEST_NPC = 6,
        FUNC_NPC = 7,
        ELSE_NPC = 8,
    };
    enum
    {
        UNIT_TYPE_PLAYER = 0,
        UNIT_TYPE_NPC = 1,
        UNIT_TYPE_ENEMY = 2,
        UNIT_TYPE_OM = 3,
    };
public:
    class MyDTI;
    class cDispPriorityData;
    class CtrlDispParam;
    struct PARALLEL_PARAMETERS;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cDispPriorityData : public MtObject
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
        cDispPriorityData();
        // Address: 0x01ac1cb0 - 0x01ac1cb1 (1 bytes)
        virtual ~cDispPriorityData() {}
    public:
        u8 mPriorityType;  // offset: 0x8
        u8 mCameraLengthType;  // offset: 0x9
        u16 mPriority;  // offset: 0xa
        static MyDTI DTI;
    };
public:
    class CtrlDispParam : public MtObject
    {
    public:
        uControl* pCtrl;  // offset: 0x8
        f32 distCamToNpc;  // offset: 0x10
        u8 Priority;  // offset: 0x14
        u8 PriorityType;  // offset: 0x15
    };
public:
    struct PARALLEL_PARAMETERS
    {
    public:
        uintptr param0;  // offset: 0x0
        uintptr param1;  // offset: 0x8
        uintptr param2;  // offset: 0x10
        uintptr param3;  // offset: 0x18
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
    sControlManager();
    virtual ~sControlManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void init();  // vtable slot 10
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void clear();  // vtable slot 11
    virtual bool update();  // vtable slot 12
    void addUnit(uControl* p, u32 unique_id, u32 line, u64 unit_group, u32 add_type);
    void addUnit(uControl* pUnit);
    uControl* createUnit(const MtDTI& dti, u32 unique_id, u32 line, u64 unit_group, u32 add_type);
    uControl* createControl(u8 ctrlType, u32 gitk, u32 uniqId, u32 unitId, cContextInstance* pContext);
    void killUnit(uDDOModel* pModel);
    virtual void releaseUnit(uControl* p);  // vtable slot 13
    virtual void releaseUnitAllFromType(s32 Type, bool IsDeleteContext);  // vtable slot 14
    void releaseUnitAll();
    void releaseLayoutUnitGroup(nLayout::stLayoutID lot);
    static sControlManager* getInstance();
    MtObject* getUnitDTI(MtDTI&, u32);
    uControl* getLayoutUnit(nLayout::stLayoutID lot, u32 no);
    uControl* getUnitDirect(u32 index);
    uControl* getUnitFromUniqueId(u32 UniqueId);
    uControl* getUnitFromRaidBossId(u32 RaidBossId);
    uControl* getUnitFromNpcId(s32 NpcId);
    bool isExistEnemyFromGroup(u32 group);
    s32 getUnitNumAll();
    u32 getUnitNum();
    void parallelUpdateDispCtrlList(uintptr params);
    void moveCtrlDispEnable();
    void setPlDispInit(uControl* pCtrl);
    void setPawnDispInit(uControl* pCtrl);
    void setDispOffAll();
    void updateDispCtrlList(MtTypedArray<CtrlDispParam>& List, CtrlDispParam* pBuff);
    u8 getDispPriorityType(uControl* pCtrl);
    void dispOnList(MtTypedArray<CtrlDispParam>& List);
    bool checkForceDispOff(CtrlDispParam* pParam);
    void setDispEnableAll();
    uControl* getUnit(const cContextInstance* pContextInst);
    uDDOModel* getUnitFSMDemo(u32 type, u32 group, u32 id);
    u32 getTotalDispUnitNum() const;
    void setTotalDispUnitNum(u32 num);
    f32 getDispMaxDist() const;
    void setDispMaxDist(f32 dist);
    void setNpcLoadArcDist(f32 Dist);
    f32 getNpcLoadArcDist();
    void setNpcReleaseArcDist(f32 Dist);
    f32 getNpcReleaseArcDist();
protected:
    bool isExist(uControl* pMdl);
    bool isMySelfCtrl(uControl* pCtrl);
    virtual bool isEnableUnit(uControl* pUnit);  // vtable slot 15
    // Address: 0x01ac1c40 - 0x01ac1c41 (1 bytes)
    virtual void returnTicket(u32 uniqId) {}  // vtable slot 16
    bool compareLayoutID(nLayout::stLayoutID l, nLayout::stLayoutID r);
    bool dispObjModel(uControl* pCtrl);
    void dispPlayerModel(uControl* pCtrl);
    bool dispNpcModel(uControl* pCtrl);
    void dispEnemyModel(uControl* pCtrl);
    void createPlayerModel(uControl* pCtrl);
    void createNpcModel(uControlNpc* pCtrlNpc);
    void createEnemyModel(uControlEnemy* pCtrlEm);
    void applyPlayerInfo(uDDOModel* pModel, uControl* pCtrl);
    void applyNpcInfo(uDDOModel* pModel, uControlNpc* pCtrlNpc);
    void applyNpcEnemyInfo(uDDOModel* pModel, uControlNpc* pCtrlNpc);
    void applyEnemyInfo(uDDOModel* pModel, uControlEnemy* pCtrlEm);
    void applyHumanEnemyInfo(uDDOModel* pModel, uControlEnemy* pCtrlEm);
    void deleteObjModel(uControl* pCtrl);
    void checkNpcExMotionLoad(MtTypedArray<CtrlDispParam>& dispList);
    bool isCreateBakingHuman();
public:
    bool isLoadCtrl(uControl* pCtrl);
    void resetClanBaseManager();
protected:
    void initDispPriorityData();
protected:
    MtTypedArray<uControl> mRefArray;  // offset: 0x18
    MtTypedArray<uControl> mAddArray;  // offset: 0x38
    MtTypedArray<uControl> mDelArray;  // offset: 0x58
    MtTypedArray<uControl> mDispArray;  // offset: 0x78
    bool mbModify;  // offset: 0x98
    u32 mGetPawnNpcUniqueId;  // offset: 0x9c
    f32 mFarDist;  // offset: 0xa0
    f32 mDispMaxDist;  // offset: 0xa4
    u32 mTotalDispUnitNum;  // offset: 0xa8
    f32 mNpcLoadArcDist;  // offset: 0xac
    f32 mNpcReleaseArcDist;  // offset: 0xb0
    bool mEmCreateFlg;  // offset: 0xb4
    u32 mNoBakedUnit;  // offset: 0xb8
    f32 mDisableDispTime;  // offset: 0xbc
    f32 mForceDispTime;  // offset: 0xc0
    u32 mFadeUnitNum;  // offset: 0xc4
    u32 mFadeUnitMaxNum;  // offset: 0xc8
    u32 mDispObjModelNum;  // offset: 0xcc
    bool mMemoryLimit;  // offset: 0xd0
    MtTypedArray<cDispPriorityData> mDispPriorityData;  // offset: 0xd8
    u32 mLoadHighPrioriryNo;  // offset: 0xf8
    u32 mLoadCtrlNum;  // offset: 0xfc
    u32 mLoadCtrlMaxNum;  // offset: 0x100
    u32 mRealDispUnitNum;  // offset: 0x104
    u32 mRealDispUnitMaxNum;  // offset: 0x108
    bool mAQC;  // offset: 0x10c
    f32 mAQCmsec;  // offset: 0x110
    u32 mAQCUnitMinNum;  // offset: 0x114
    u32 mAQCUnitMaxNum;  // offset: 0x118
private:
    static sControlManager* mpInstance;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sControlManager::cDispPriorityData::cDispPriorityData() {
    this->mPriorityType = static_cast<u8>(0);
    this->mCameraLengthType = static_cast<u8>(0);
    this->mPriority = static_cast<u16>(65535);
}
