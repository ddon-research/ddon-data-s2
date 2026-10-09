#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtPerformance.h"
#include "MtProfiler.h"
#include "MtSynchronize.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPerformance;
class MtProfiler;
class MtProperty;
class MtPropertyList;
class MtSemaphore;
class MtStream;
class MtUI;
struct _SceKernelEventFlag;
class cSplitLot;
class cpCatchCtrl;
class cpJob01;
class cpSlave;
struct pthread;
class sApp;
class sContextManager;
class sEffect;
class sItemManager;
class sNetwork;
class sVibration;
class uCameraBase;
class uEffectExt;
class uGUI;
class uHuman;

// Declarations
class sMain;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using JOBHANDLE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using u32 = unsigned int;
using MT_MFUNC32 = void(MtObject::*)(u32);
using MT_MFUNC32X2 = void(MtObject::*)(u32, u32);
using MT_MFUNC64 = void(MtObject::*)(u64);
using MT_MFUNC64X2 = void(MtObject::*)(u64, u64);
using MT_MFUNCPTR = MT_MFUNC64;
using MT_MFUNCPTRX2 = MT_MFUNC64X2;
using SceKernelEventFlag = _SceKernelEventFlag*;
using pthread_t = pthread*;
using ScePthread = pthread_t;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using uintptr = __uintptr_t;

class sMain : public cSystem
{
    // inferred: cSplitLot::eraseWait names sMain::mDeltaTime
    friend class cSplitLot;
    // inferred: cpCatchCtrl::updateBeardownEffectiveTimer names sMain::mDeltaTime
    friend class cpCatchCtrl;
    // inferred: cpJob01::update names sMain::mDeltaTime
    friend class cpJob01;
    // inferred: cpSlave::interpolatePos names sMain::mDeltaTime
    friend class cpSlave;
    // inferred: sApp::execute names sMain::mExit
    friend class sApp;
    // inferred: sContextManager::move names sMain::mpInstance
    friend class sContextManager;
    // inferred: sEffect::getFps names sMain::mpInstance
    friend class sEffect;
    // inferred: sItemManager::move names sMain::mDeltaTime
    friend class sItemManager;
    // inferred: sNetwork::reset names sMain::mpInstance
    friend class sNetwork;
    // inferred: sVibration::getTimer names sMain::mpInstance
    friend class sVibration;
    // inferred: uCameraBase::getDeltaTime names sMain::mDeltaTime
    friend class uCameraBase;
    // inferred: uEffectExt::doFinish names sMain::mDeltaTime
    friend class uEffectExt;
    // inferred: uGUI::moveAfter names sMain::mpInstance
    friend class uGUI;
    // inferred: uHuman::updateCsChangeSubGUI names sMain::mDeltaTime
    friend class uHuman;
public:
    enum JOB_MODE
    {
        JOB_DYNAMIC = 0,
        JOB_DYNAMICID = 1,
        JOB_DYNAMIC32 = 2,
        JOB_DYNAMIC64 = 3,
        JOB_DYNAMICPTR = 4,
        JOB_DYNAMICIDPTR = 5,
    };
    enum JOBTHREAD_EVENTLAG_USEBIT
    {
        JOBTHREAD_EVENTLAG_WAKEUP = 0,
        JOBTHREAD_EVENTLAG_SLEEP = 1,
        EVENTFLAG_USEBIT_NUM = 2,
    };
    enum JOB_FUNCTYPE
    {
        JOB_FUNCTYPE_32 = 0,
        JOB_FUNCTYPE_32X2 = 1,
        JOB_FUNCTYPE_64 = 2,
        JOB_FUNCTYPE_64X2 = 3,
    };
    enum JOB_PS4
    {
        JOB_PRIORITY = 700,
        JOB_STACK_SIZE = 1048576,
        DELAY_JOB_PRIORITY = 730,
        DELAY_JOB_STACK_SIZE = 1048576,
    };
public:
    class MyDTI;
    struct JOB_WORK;
    struct JOB_WORK_PARAM;
    struct JOB_THREAD;
    struct PROCESS;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct JOB_WORK
    {
    public:
        MtObject* pobject;  // offset: 0x0
        union
        {
        public:
            MT_MFUNC pfunc;  // offset: 0x0
            MT_MFUNCPTR pfuncptr;  // offset: 0x0
        };  // offset: 0x8
    };
public:
    struct JOB_WORK_PARAM
    {
    public:
        MtObject* pobject;  // offset: 0x0
        union
        {
        public:
            MT_MFUNC32 pfunc32;  // offset: 0x0
            MT_MFUNC32X2 pfunc32x2;  // offset: 0x0
            MT_MFUNC64 pfunc64;  // offset: 0x0
            MT_MFUNC64X2 pfunc64x2;  // offset: 0x0
            MT_MFUNCPTRX2 pfuncptrx2;  // offset: 0x0
        };  // offset: 0x8
        union
        {
        public:
            u32 param32;  // offset: 0x0
            u64 param64;  // offset: 0x0
        };  // offset: 0x18
        u32 functype;  // offset: 0x20
    };
public:
    struct JOB_THREAD
    {
    public:
        JOB_THREAD();
    public:
        ScePthread thread_id;  // offset: 0x0
        u32 job_wait;  // offset: 0x8
        uintptr job_id;  // offset: 0x10
        u32 job_index;  // offset: 0x18
        bool active;  // offset: 0x1c
        bool exit;  // offset: 0x1d
    };
public:
    struct PROCESS
    {
    public:
        f32 mftime;  // offset: 0x0
        f32 mltime;  // offset: 0x4
        f32 mffps;  // offset: 0x8
        u32 mfrm_ctr;  // offset: 0xc
        MtPerformance perf;  // offset: 0x10
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
    sMain();
    virtual ~sMain();
    virtual void move();  // vtable slot 7
    bool isExit();
    virtual bool close();  // vtable slot 10
    void exit();
    virtual void final();  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    static MT_CTSTR getBuildVersion();
    static sMain* getInstance();
    u32 getCPUCaps();
    u32 getCPULogicalProcesserNum();
    u32 getCPUCoreNum();
    bool isCPUHTEnable();
    MT_CTSTR getCPUName();
    void setJobID(u32 thread_no, uintptr id);
    void addJob(MtObject* pthis, MT_MFUNC pfunc);
    void addJob(MtObject* pthis, MT_MFUNC32 pfunc, u32 param);
    void addJob(MtObject* pthis, MT_MFUNC64 pfunc, u64 param);
    void addJob(MtObject*, MT_MFUNC32X2, u32);
    void addJob(MtObject* pthis, MT_MFUNC64X2 pfunc, u64 param);
    JOBHANDLE addDelayJob(MtObject* pthis, MT_MFUNC32 pfunc, u32 param);
    JOBHANDLE addDelayJob(MtObject* pthis, MT_MFUNC64 pfunc, u64 param);
    void blockJob(JOBHANDLE jobhandle);
    void breakJob(JOBHANDLE jobhandle);
    bool checkJob(JOBHANDLE jobhandle);
    void executeJob(JOB_MODE mode);
    u32 getMaxJob(JOB_MODE);
    u32 getJobThreadNum();
    uintptr getJobThreadID(u32);
    u32 getJobThreadIndex();
    void setJobThreadNum(u32 n);
    bool checkJobThread();
    u32 getDelayJobThreadIndex();
    void setProfile(bool);
    bool isProfile();
    void setFrameWait(bool f);
    bool isFrameWait() const;
    void setFps(f32 fps);
    f32 getFps() const;
    void setMaxFps(f32 fps);
    f32 getMaxFps() const;
    f32 getActualFps() const;
    u64 getTimer() const;
    u32 getFrameTimer() const;
    f32 getDeltaTime() const;
    void setDeltaTime(f32 NewValue);
    f32 getDeltaTimeLimite() const;
    void setDeltaTimeLimite(f32);
    f32 getDeltaTimeBorder() const;
    void setDeltaTimeBorder(f32);
    f32 getDelayFrame() const;
    void resetFrame();
    void resetTimer();
    void setPause(bool pause);
    bool isPause() const;
private:
    bool isPausePrivate() const;
    void setPausePrivate(bool NewValue);
public:
    bool isUpdatePause() const;
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 13
    virtual bool saveConfig(MtStream& out);  // vtable slot 14
    virtual bool loadConfig(MtStream& in);  // vtable slot 15
protected:
    u32 getNextJobThreadNum();
    void createThread();
    void createDelayJobThread(u32 thread_num);
    void loadConfigDefault(MT_CTSTR name);
    void saveConfigDefault(MT_CTSTR name);
    void freeDefaultMemory();
    void initMemory();
    void skip();
    virtual u32 jobLoop(JOB_THREAD* ph);  // vtable slot 16
    virtual u32 delayJobLoop(JOB_THREAD* ph);  // vtable slot 17
    static void* jobHandler(void* pthis);
    static void* delayJobHandler(void* pthis);
    static void jobProc(const JOB_THREAD* ph);
    JOB_WORK_PARAM* getDelayJob(JOBHANDLE* phandle);
    void checkCPUCaps();
    void getPerfomance();
protected:
    u64 mTimer;  // offset: 0x18
    s64 mStartTime;  // offset: 0x20
    u32 mFrameTimer;  // offset: 0x28
    bool mExit;  // offset: 0x2c
    f32 mFps;  // offset: 0x30
    f32 mMaxFps;  // offset: 0x34
    bool mFrameWait;  // offset: 0x38
    f32 mActualFps;  // offset: 0x3c
    s64 mRealCounter;  // offset: 0x40
    s64 mIdealCounter;  // offset: 0x48
    s64 mPrevCounter;  // offset: 0x50
    u32 mSkip;  // offset: 0x58
    bool mPause;  // offset: 0x5c
    bool mPauseBefore;  // offset: 0x5d
    bool mInitJobThread;  // offset: 0x5e
    bool mFinalize;  // offset: 0x5f
    f32 mDeltaTime;  // offset: 0x60
    f32 mDeltaTimeBorder;  // offset: 0x64
    f32 mDeltaTimeLimite;  // offset: 0x68
    f32 mDelayFrame;  // offset: 0x6c
    ScePthread mMainThreadID;  // offset: 0x70
    SceKernelEventFlag mJobThreadEventFlag;  // offset: 0x78
    u32 mJobNum;  // offset: 0x80
    s32 mJobPt;  // offset: 0x84
    JOB_MODE mJobMode;  // offset: 0x88
    u32 mJobThreadNum;  // offset: 0x8c
    u32 mNextJobThreadNum;  // offset: 0x90
    u32 mDelayJobThreadNum;  // offset: 0x94
    u64 mDelayJobWritePt;  // offset: 0x98
    u64 mDelayJobReadPt;  // offset: 0xa0
    MtSemaphore mDelayJobSemaphore;  // offset: 0xa8
    JOB_WORK mJob[8096];  // offset: 0xb0
    JOB_WORK_PARAM mDelayJob[4096];  // offset: 0x2f7b0
    JOB_THREAD mJobThread[6];  // offset: 0x577b0
    JOB_THREAD mDelayJobThread[6];  // offset: 0x57870
    MtProfiler mProfiler;  // offset: 0x57930
    PROCESS mProcess;  // offset: 0x57938
    u32 mCPUCaps;  // offset: 0x579a8
    u32 mCPUCoreNum;  // offset: 0x579ac
    u32 mCPULogicalProcessorNum;  // offset: 0x579b0
    bool mCPUHTEnable;  // offset: 0x579b4
    MT_CHAR mCPUName[256];  // offset: 0x579b5
public:
    static MyDTI DTI;
    static const u32 MAX_DELAYJOBTHREAD = 6;
protected:
    static sMain* mpInstance;
    static const s32 MAX_JOB = 8096;
    static const s32 MAX_DELAY_JOB = 4096;
    static MT_CTSTR mBuildVersion;
};

// Inline, no code of its own: checked where it is inlined.
inline sMain* sMain::getInstance() {
    return ::sMain::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 sMain::getFps() const {
    return this->mFps;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 sMain::getFrameTimer() const {
    return this->mFrameTimer;
}
