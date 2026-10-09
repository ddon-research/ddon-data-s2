#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
struct pthread;

// Declarations
class MtThread;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __uint64_t = long unsigned int;
using uint64_t = __uint64_t;
using SceKernelCpumask = uint64_t;
using pthread_t = pthread*;
using ScePthread = pthread_t;
using SceUID = int;
using _Sizet = long unsigned int;
using __uintptr_t = __uint64_t;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using uintptr = __uintptr_t;

class MtThread : public MtObject
{
public:
    enum STATUS
    {
        SUSPENDED = 0,
        EXECUTING = 1,
        TERMINATED = 2,
    };
public:
    class MyDTI;
public:
    using ID = SceUID;
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
    MtThread(u32 stack_size, void* pcontext, MT_CTSTR name);
    virtual ~MtThread();
    void suspend();
    void resume();
    void sleep(u32 time);
    void terminate();
    void setPriority(s32 prio);
    void setProcessor(u32 p);
    void interval();
    STATUS getStatus() const;
    void lock();
    void unlock();
    static uintptr getCurrentId();
protected:
    virtual void execute(void*);  // vtable slot 6
    bool isRequestedTermination() const;
private:
    static void* innerFunction(void* pthis);
private:
    MtCriticalSection mCS;  // offset: 0x8
    void* mpContext;  // offset: 0x10
    bool mTerminate;  // offset: 0x18
    MT_CHAR mName[64];  // offset: 0x19
    STATUS mStatus;  // offset: 0x5c
    ScePthread mThreadID;  // offset: 0x60
    MtCriticalSection mSuspendSection;  // offset: 0x68
public:
    static MyDTI DTI;
    static const SceKernelCpumask AffinityMaskCore0 = 1;
    static const SceKernelCpumask AffinityMaskCore1 = 2;
    static const SceKernelCpumask AffinityMaskCore2 = 4;
    static const SceKernelCpumask AffinityMaskCore3 = 8;
    static const SceKernelCpumask AffinityMaskCore4 = 16;
    static const SceKernelCpumask AffinityMaskCore5 = 32;
    static const SceKernelCpumask AffinityMaskSegment0 = 15;
    static const SceKernelCpumask AffinityMaskSegment1 = 48;
    static const SceKernelCpumask AffinityMaskCoreAll = 63;
private:
    static const u32 MAX_THREAD_NAME = 64;
    static const s32 DEFAULT_THREAD_PRIO = 700;
};
