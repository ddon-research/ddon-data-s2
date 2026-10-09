#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtThread.h"
#include "cBakeModel.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSemaphore;
class MtThread;
class MtUI;
class cBakeModel;
class cBakeModelEx;
class cDDMaterialCtrl;
class cDraw;
class cUnit;
class cpBakeJoint;
namespace nDraw { class CommandCache; }
class rModel;
class uModel;

// Declarations
class BakedQueue;
class sBakingJointOrder;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class BakedQueue
{
public:
    struct BAKED_STATE;
    struct LOCK_FLAG;
public:
    struct BAKED_STATE
    {
    public:
        enum DECL
        {
            NONE = 0,
            ORDER = 1,
            BUILD = 2,
            SYNC = 4,
            BAKED = 8,
        };
    };
public:
    struct LOCK_FLAG
    {
    public:
        enum DECL
        {
            UNLOCK = 0,
            LOCK = 1,
            SINGNED = -1,
        };
    };
public:
    BakedQueue();
    ~BakedQueue();
    bool lock();
    bool unlock();
    bool isLock();
    BAKED_STATE::DECL getState();
public:
    volatile BAKED_STATE::DECL mBakeState;  // offset: 0x0
    uModel* mpOrderUnit;  // offset: 0x8
    cpBakeJoint* mpInfoCallBack;  // offset: 0x10
    cBakeModel mBakingBaseModel;  // offset: 0x20
    cBakeModel mSolidModels[12];  // offset: 0xbd0
    cBakeModelEx mSoftModels[6];  // offset: 0x9810
    u32 mSolidModelNum;  // offset: 0xdef0
    u32 mSoftModelNum;  // offset: 0xdef4
    volatile s32 mLock;  // offset: 0xdef8
    volatile s32 mCacheLock;  // offset: 0xdefc
    u32 mPriority;  // offset: 0xdf00
    cUnit* mpOwnerProtectUnit;  // offset: 0xdf08
    nDraw::CommandCache* mpCache[6];  // offset: 0xdf10
    static const u32 MAX_SOLID_MODELS_NUM = 12;
    static const u32 MAX_SOFT_MODELS_NUM = 6;
};

class sBakingJointOrder : public cSystem
{
public:
    class MyDTI;
    struct ORDER_PRIORITY;
    class BakeJointThread;
public:
    using BAKE_HANDLE = u32;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct ORDER_PRIORITY
    {
    public:
        enum DECL
        {
            TOP_MOST = 0,
            VERY_HIGH = 1,
            HIGH = 2,
            ABOVE_NORMAL = 3,
            NORMAL = 4,
            BELOW_NORMAL = 5,
            LOW = 6,
            VERY_LOW = 7,
            LOWEST = 8,
        };
    };
public:
    class BakeJointThread : public MtThread
    {
    public:
        BakeJointThread(sBakingJointOrder* p);
        virtual ~BakeJointThread();
        virtual void execute(void* pcontext);  // vtable slot 6
    private:
        sBakingJointOrder* mpBJSystem;  // offset: 0x70
    };
private:
    void setBusy(bool isBusy);
public:
    void asyncBakeJointOrder();
    void syncBakeJointOrder();
    bool isBusy();
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
    sBakingJointOrder();
    virtual ~sBakingJointOrder();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    static sBakingJointOrder* getInstance();
private:
    sBakingJointOrder(const sBakingJointOrder&);
public:
    bool addBakeQueue(BAKE_HANDLE& handle, uModel* powner, cpBakeJoint* pcallback);
    void returnBakeQueue(const BAKE_HANDLE index);
    bool setBakeModel(const BAKE_HANDLE handle, rModel* pBaseModel);
    bool setBakeSolidModels(const BAKE_HANDLE handle, uModel* pCallerUnit, rModel* * mpaSolidModels, const u32 models_num);
    bool setBakeSoftModels(const BAKE_HANDLE handle, uModel* pCallerUnit, rModel* * mpaSoftModels, const u32 models_num);
    bool orderBakeQueue(const BAKE_HANDLE handle, uModel* pOriginModel, ORDER_PRIORITY::DECL priority);
    bool execBakeQueue(const BAKE_HANDLE handle, uModel* pOriginModel, ORDER_PRIORITY::DECL priority);
    bool releaseBakeQueue(const BAKE_HANDLE index);
    void setCommonStateModelOrder(cDraw* pdraw, uModel* punit, cpBakeJoint* pcallback);
    void drawBakingModelOrder(cDraw* pdraw, uModel* punit, const BAKE_HANDLE handle);
    bool isBaked(const BAKE_HANDLE index);
private:
    void buildInverseMatrix(BakedQueue* pbq);
public:
    void removeProtectUnits(cUnit* punit);
    void checkProtectUnits();
    void addDeleteUnitsQueue(cUnit* punit);
    void checkDeleteUnits();
    bool isBakingJoint();
    void terminateThread();
    bool setMaterialState(const BAKE_HANDLE handle, cDDMaterialCtrl* pmctrl);
    void flushAllCache();
private:
    MtSemaphore* mpSemaphore;  // offset: 0x18
    MtThread* mpBakeJointThread;  // offset: 0x20
    bool mIsEnableBakingJoint;  // offset: 0x28
    bool mTerminateBakeJointThread;  // offset: 0x29
    bool mIsBusy;  // offset: 0x2a
public:
    BakedQueue mBakeModelQueue[160];  // offset: 0x30
    void* mpConvertAllocator;  // offset: 0x8b8830
    void* mpBakeModelAllocator;  // offset: 0x8b8838
private:
    cUnit* maDeleteUnits[320];  // offset: 0x8b8840
    static sBakingJointOrder* mpInstance;
public:
    static MyDTI DTI;
    static const u32 MAX_BAKE_MODELS_NUM = 160;
    static const BAKE_HANDLE INVALID_BAKE_HANDLE = 4294967295;
private:
    static const u32 MAX_PROTECT_UNITS_NUM = 320;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline BakedQueue::BAKED_STATE::DECL BakedQueue::getState() {
    return this->mBakeState;
}

// Inline, no code of its own: checked where it is inlined.
inline sBakingJointOrder* sBakingJointOrder::getInstance() {
    return ::sBakingJointOrder::mpInstance;
}
