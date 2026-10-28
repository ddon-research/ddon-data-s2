#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class AreaHitShape;
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
class cAreaHit;
class cScenarioData;
class uDDOModel;

// Declarations
class cScenario;
class cScenarioArg;
class cScenarioParam;

enum SCENARIO_ACTION_RETURN
{
    SCENARIO_ACTION_RETURN_CONTINUE = 0,
    SCENARIO_ACTION_RETURN_SLEEP = 1,
    SCENARIO_ACTION_RETURN_FINISH = 2,
};

enum SCENARIO_BOOT_ENUM
{
    SCENARIO_BOOT_NO_AREA = 0,
    SCENARIO_BOOT_LATER = 1,
    SCENARIO_BOOT_DURING = 2,
    SCENARIO_BOOT_ONCE = 3,
    SCENARIO_BOOT_TRIGGER = 4,
    SCENARIO_BOOT_BTN = 5,
    SCENARIO_BOOT_BTN_ONCE = 6,
    SCENARIO_BOOT_MAX = 7,
};

enum SCENARIO_PRIO_ENUM
{
    SCENARIO_PRIO_00_MAX = 0,
    SCENARIO_PRIO_01 = 1,
    SCENARIO_PRIO_02 = 2,
    SCENARIO_PRIO_03 = 3,
    SCENARIO_PRIO_04_DEF = 4,
    SCENARIO_PRIO_05 = 5,
    SCENARIO_PRIO_06 = 6,
    SCENARIO_PRIO_07 = 7,
    SCENARIO_PRIO_08_MIN = 8,
    SCENARIO_PRIO_NUM = 9,
};

enum SCENARIO_TASK_ENUM
{
    SCENARIO_TASK_SCE = 0,
    SCENARIO_TASK_DOOR = 1,
    SCENARIO_TASK_FSM = 2,
    SCENARIO_TASK_CUSTOM = 3,
    SCENARIO_TASK_MAX = 4,
    SCENARIO_TASK_ERROR = 5,
};

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SCENARIO_ACTION_FUNC_END = void(*)(cScenarioArg*);
using SCENARIO_ACTION_FUNC_INIT = void(*)(cScenarioArg*);
using SCENARIO_ACTION_FUNC_MAIN = SCENARIO_ACTION_RETURN(*)(cScenarioArg*);
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cScenario : public MtObject
{
public:
    enum SYS_STATUS_FLAG
    {
        SYS_STATUS_SET_AREA = 1,
        SYS_STATUS_FINISHED = 4,
        SYS_STATUS_SET_ACTBTN = 8,
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
    cScenario(SCENARIO_PRIO_ENUM prio);
    virtual ~cScenario();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void init(SCENARIO_TASK_ENUM task);
    void setup();
    void move();
    void action();
    void reqActionEnd();
    void reqActionInit();
    cScenarioParam* getParam();
    void setParam(cScenarioParam* pParam);
    cAreaHit* getArea();
    virtual cAreaHit* createArea();  // vtable slot 6
    virtual void releaseArea();  // vtable slot 7
    void setAreaShape(AreaHitShape* pShape);
    AreaHitShape* getAreaShape();
    void setAreaShapeType(u32 shape);
    u32 getAreaShapeType();
    void setName(const MtString& name);
    MT_CTSTR getName();
    void setArg(cScenarioArg* pArg);
    cScenarioArg* getArg();
    void setActionInit(SCENARIO_ACTION_FUNC_END pAction);
    SCENARIO_ACTION_FUNC_INIT getActionInit();
    void setActionMain(SCENARIO_ACTION_FUNC_MAIN pAction);
    SCENARIO_ACTION_FUNC_MAIN getActionMain();
    void setActionEnd(SCENARIO_ACTION_FUNC_END pAction);
    SCENARIO_ACTION_FUNC_END getActionEnd();
    SCENARIO_TASK_ENUM getTaskType();
    void setBootType(SCENARIO_BOOT_ENUM boot);
    SCENARIO_BOOT_ENUM getBootType();
    bool isInstantBoot();
    bool isEnable();
    bool isHit();
    void setHit(bool f);
    bool isSleep();
    void setSleep(bool f);
    bool isDead();
    void kill();
    bool isDone();
    void setDone();
    bool isDo();
    bool checkStatus(u32 st);
    void setStatus(u32 st, bool b);
    bool isDetect();
    bool isDetectOld();
    bool isDetectPl(u8 plNo);
    bool isDetectPlOld(u8 plNo);
    bool isIn(uDDOModel* pChara);
    bool isIn(const MtVector3& pos, f32 ang);
    u32 getDetectAttr();
    void setDetectAttr(u32 d);
    u32 getCheckType();
    void setCheckType(u32 check);
    SCENARIO_PRIO_ENUM getPriority();
    void setDummyU32(u32);
    void copyData(cScenarioData* pSrc);
protected:
    bool getSysStatus(SYS_STATUS_FLAG f);
    void setSysStatus(SYS_STATUS_FLAG f, bool b);
protected:
    cScenarioParam* mpParam;  // offset: 0x8
    cAreaHit* mpArea;  // offset: 0x10
    cScenarioArg* mpArg;  // offset: 0x18
    SCENARIO_ACTION_FUNC_INIT mpActionInit;  // offset: 0x20
    SCENARIO_ACTION_FUNC_MAIN mpActionMain;  // offset: 0x28
    SCENARIO_ACTION_FUNC_END mpActionEnd;  // offset: 0x30
    u32 mStatus;  // offset: 0x38
    u32 mDetectOld;  // offset: 0x3c
    u32 mSysStatus;  // offset: 0x40
public:
    static MyDTI DTI;
};

class cScenarioArg : public MtObject
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
    cScenarioArg(cScenario* pSce);
    virtual ~cScenarioArg();
    virtual cScenarioArg& operator=(const cScenarioArg& s);  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setScenario(cScenario* p);
    cScenario* getScenario();
    bool isEnableScenario();
    static bool chkAction_Scenario(MtObject* pOwner, s32 pl_no, u32 uarg);
public:
    u8 mRno0;  // offset: 0x8
    u8 mRno1;  // offset: 0x9
    u8 mRno2;  // offset: 0xa
    u8 mRno3;  // offset: 0xb
    s32 mSFree0;  // offset: 0xc
    s32 mSFree1;  // offset: 0x10
    s32 mSFree2;  // offset: 0x14
    s32 mSFree3;  // offset: 0x18
    f32 mFFree0;  // offset: 0x1c
    f32 mFFree1;  // offset: 0x20
    f32 mFFree2;  // offset: 0x24
    f32 mFFree3;  // offset: 0x28
protected:
    cScenario* mpScenario;  // offset: 0x30
public:
    static MyDTI DTI;
};

class cScenarioParam : public MtObject
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
    cScenarioParam();
    virtual ~cScenarioParam();
    cScenarioParam(const cScenarioParam&);
    virtual cScenarioParam& operator=(const cScenarioParam& s);  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getDetectAttr();
    void setDetectAttr(u32 d);
public:
    u32 mTaskType;  // offset: 0x8
    u32 mBootType;  // offset: 0xc
    u32 mCheckType;  // offset: 0x10
    u32 mPriority;  // offset: 0x14
    u32 mStatus;  // offset: 0x18
protected:
    u32 mDetectAttr;  // offset: 0x1c
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cAreaHit* cScenario::getArea() {
    return this->mpArea;
}

// Inline, no code of its own: checked where it is inlined.
inline cScenarioParam::cScenarioParam() {
    this->mTaskType = 0;
    this->mBootType = 0;
    this->mDetectAttr = 16;
    this->mCheckType = 0;
    this->mPriority = 4;
    this->mStatus = 0;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cScenarioParam::getDetectAttr() {
    return this->mDetectAttr;
}
