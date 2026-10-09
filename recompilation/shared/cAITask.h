#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cAIObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nAI { class TaskPerformanceInfo; }

// Declarations
class cAITask;
class cAITaskJobPrim;
class cAITaskJobPrimList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cAITaskJobPrim : public cAIObject
{
    // inferred: cAITask::nextJob names cAITaskJobPrim::mpNext
    friend class cAITask;
    // inferred: cAITaskJobPrimList::add names cAITaskJobPrim::mpNext
    friend class cAITaskJobPrimList;
public:
    enum TYPE
    {
        TYPE_JOB = 0,
        TYPE_STOP_JOB = 1,
    };
public:
    class MyDTI;
public:
    using JOB_FUNC = void(MtObject::*)();
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
    cAITaskJobPrim(u32 type, u32 id, cAITask* po, JOB_FUNC func);
    virtual ~cAITaskJobPrim();
    void callJobFunc();
    cAITaskJobPrim* getNext();
private:
    u32 mType;  // offset: 0x8
    u32 mJobId;  // offset: 0xc
    cAITask* mpOwner;  // offset: 0x10
    JOB_FUNC mJobFunc;  // offset: 0x18
    cAITaskJobPrim* mpNext;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cAITaskJobPrimList : public cAIObject
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
    cAITaskJobPrimList();
    virtual ~cAITaskJobPrimList();
    void destroyList();
    void add(cAITaskJobPrim* pPrim);
    void operator<<(cAITaskJobPrim* pPrim);
    bool existsList();
    cAITaskJobPrim* getList();
    cAITaskJobPrim* searchByJobId(u32 id);
    cAITaskJobPrim* searchByType(u32 type);
private:
    cAITaskJobPrim* mpList;  // offset: 0x8
    cAITaskJobPrim* mpListBottom;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cAITask : public cAIObject
{
public:
    enum TASK_STATUS
    {
        TASK_ST_IDLE = 0,
        TASK_ST_LAUNCH = 1,
        TASK_ST_WORKING = 2,
        TASK_ST_DONE = 3,
        TASK_ST_FAILED = 4,
    };
    enum BG_JOB_TYPE
    {
        BG_JOB_LOOP = 0,
        BG_JOB_DELAY_JOB_WATCH = 1,
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
    cAITask();
    virtual ~cAITask();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01b6a290 - 0x01b6a291 (1 bytes)
    virtual void createJobList(cAITaskJobPrimList& list) {}  // vtable slot 6
    bool isLaunch();
    bool isWorking();
    bool isDone();
    u32 getTaskResult();
    void setTaskStatus(u32);
    void setDoneCallback(MtObject*, MT_MFUNC);
    bool quitsTaskLoop();
    void setEnablePerformanceManage(bool);
    void setPerformanceIndicator(f32);
    void setOverloadManageType(u32);
    void setLODLevel(s32);
    void initJobList();
    void moveJob();
    void moveStopJob();
    bool moveTask();
    void doneTask();
    void nextJob();
    void jumpJob(u32 id);
protected:
    void setPerformanceInfo();
    f32 calcEffectivePerformanceIndicator();
    void moveTaskNoManage();
private:
    bool moveTaskLoop();
    void moveTaskBackground();
    void moveJobOnDelayJob(u32 param);
    void callTaskDoneCallback();
    void setTaskDone();
protected:
    u32 mTaskResult;  // offset: 0x8
private:
    cAITaskJobPrimList mJobList;  // offset: 0x10
    cAITaskJobPrim* mpCurrentJobPrimitive;  // offset: 0x28
    u32 mTaskStatus;  // offset: 0x30
    bool mQuitTaskLoop;  // offset: 0x34
    bool mEnablePerformanceManage;  // offset: 0x35
    u32 mOverloadManageType;  // offset: 0x38
    f32 mPerformanceIndicator;  // offset: 0x3c
    f32 mTaskAllowTime;  // offset: 0x40
    cAITask* mpBackgroundPrevTask;  // offset: 0x48
    cAITask* mpBackgroundNextTask;  // offset: 0x50
    bool mIsBackgroundTask;  // offset: 0x58
    u32 mBackgroundJobType;  // offset: 0x5c
    MtObject* mpDoneCallbackOwner;  // offset: 0x60
    MT_MFUNC mpDoneCallback;  // offset: 0x68
    s32 mLODLevel;  // offset: 0x78
    nAI::TaskPerformanceInfo* mpPerformanceInfo;  // offset: 0x80
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK18cAITaskJobPrimList5MyDTI11newInstanceEv at 0x0105fbb0-0x0105fbde, code DWARF attributes to no inlined copy
inline cAITaskJobPrimList::cAITaskJobPrimList() {
    this->mpListBottom = static_cast<cAITaskJobPrim*>(nullptr);
    this->mpList = static_cast<cAITaskJobPrim*>(nullptr);
}
