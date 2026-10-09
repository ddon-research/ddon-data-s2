#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
class MtPerformance;
class MtPerformanceCounter;
class MtPerformanceTimer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using f32 = float;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;

class MtPerformanceCounter : public MtObject
{
public:
    class MyDTI;
    struct PerfTime;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PerfTime
    {
    public:
        s64 last_ticks;  // offset: 0x0
        s64 app_ticks;  // offset: 0x8
        s32 app_d_ticks;  // offset: 0x10
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
    MtPerformanceCounter();
    // Address: 0x01b32120 - 0x01b32121 (1 bytes)
    virtual ~MtPerformanceCounter() {}
    void initialize(bool auto_start);
    void sample();
    void sample(s64);
    void start();
    void peek();
    void end();
    s64 getStartTicks() const;
    s64 getEndTicks() const;
    s64 getLastTicks() const;
    s64 getAppTicks() const;
    s32 getElapsedTicks() const;
    static s64 getCurrent();
    static s64 getFrequency();
private:
    void measurePerf(PerfTime* p_perf);
private:
    PerfTime mPerfTime;  // offset: 0x8
    s64 mStartTicks;  // offset: 0x20
    s64 mEndTicks;  // offset: 0x28
public:
    static MyDTI DTI;
private:
    static s64 mFrequency;
};

class MtPerformanceTimer : public MtObject
{
public:
    class MyDTI;
    struct PerfTime;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PerfTime
    {
    public:
        u32 last_ticks;  // offset: 0x0
        u32 app_ticks;  // offset: 0x4
        s32 app_d_ticks;  // offset: 0x8
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
    MtPerformanceTimer();
    // Address: 0x01a69fa0 - 0x01a69fa1 (1 bytes)
    virtual ~MtPerformanceTimer() {}
    void initialize(bool auto_start);
    void sample();
    void start();
    void peek();
    void end();
    u32 getStartTime() const;
    u32 getEndTime() const;
    u32 getLastTime() const;
    u32 getAppTime() const;
    s32 getElapsedTime() const;
private:
    void measurePerf(PerfTime* p_perf);
    void updateTicks();
private:
    PerfTime mPerfTime;  // offset: 0x8
    u32 mStartTicks;  // offset: 0x14
    u32 mEndTicks;  // offset: 0x18
public:
    static MyDTI DTI;
};

class MtPerformance : public MtObject
{
public:
    class MyDTI;
    struct PerfTime;
    struct PerfInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PerfTime
    {
    public:
        f64 last_time;  // offset: 0x0
        f64 app_time;  // offset: 0x8
        f32 app_d_time;  // offset: 0x10
    };
public:
    struct PerfInfo
    {
    public:
        f64 secs_per_tick;  // offset: 0x0
        s64 ticks_per_sec;  // offset: 0x8
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
    MtPerformance();
    // Address: 0x01b320d0 - 0x01b320d1 (1 bytes)
    virtual ~MtPerformance() {}
    void initialize(bool auto_start);
    void sample(bool update_info);
    void sample(s64, bool);
    void start();
    void peek();
    void end();
    f32 getElapsedTimeSec() const;
    f32 getElapsedTimeMilliSec() const;
    f32 getElapsedTimeMicroSec() const;
    const PerfInfo& getPerformanceInfo() const;
    const MtPerformanceCounter& getPerformanceCounter() const;
    f64 getAppTime() const;
    f64 getLastTime() const;
    void updateInfo();
private:
    void updateInfo(PerfInfo* p_info);
    void measurePerf(PerfTime* p_perf);
private:
    PerfTime mPerfTime;  // offset: 0x8
    MtPerformanceCounter mPerfCtr;  // offset: 0x20
    PerfInfo mPerfInfo;  // offset: 0x50
public:
    static MyDTI DTI;
};
