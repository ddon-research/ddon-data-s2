#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class sCoprocessor;

// Type aliases from DWARF
using u32 = unsigned int;
using CO_FUNC = void(*)(void*, u32);
using HANDLE = void*;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;

class sCoprocessor : public cSystem
{
public:
    enum QUEUE_KIND
    {
        QUEUE_INITIALIZE = 0,
        QUEUE_DRAW = 1,
        QUEUE_FRAME = 2,
        QUEUE_NUM = 3,
    };
public:
    struct COPROCESSOR_THREAD;
    struct QUEUE_WORK32;
    class MyDTI;
public:
    struct COPROCESSOR_THREAD
    {
    public:
        HANDLE handle;  // offset: 0x0
        u32 thread_id;  // offset: 0x8
        HANDLE event;  // offset: 0x10
        HANDLE sync;  // offset: 0x18
        u32 job_id;  // offset: 0x20
        u32 job_index;  // offset: 0x24
        u32 active;  // offset: 0x28
        u32 queue_id;  // offset: 0x2c
        bool exit;  // offset: 0x30
    };
public:
    struct QUEUE_WORK32
    {
    public:
        CO_FUNC pfunc;  // offset: 0x0
        u32 exit_code;  // offset: 0x8
        void* ptr;  // offset: 0x10
        u32 size;  // offset: 0x18
    };
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
private:
    void createCoprocessorJobThread(u32 thread_num);
    virtual u32 coprocessorLoop(COPROCESSOR_THREAD* ph);  // vtable slot 10
    QUEUE_WORK32* getCoprocessorJob(QUEUE_KIND kind);
    bool addCoprocessorJob(CO_FUNC pfunc, void* ptr, u32 size, QUEUE_KIND kind, u32 exit);
    static u32 coprocessorHandler(void* param);
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
    sCoprocessor();
    virtual ~sCoprocessor();
    static sCoprocessor* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void begin();
    virtual void move();  // vtable slot 7
    void end();
    bool addDrawEndQueue(CO_FUNC pfunc, void* ptr, u32 size);
    bool addFrameEndQueue(CO_FUNC pfunc, void* ptr, u32 size);
private:
    COPROCESSOR_THREAD mCoprocessorThread[5];  // offset: 0x18
    QUEUE_WORK32 mCoprocessorDrawQueue[256];  // offset: 0x130
    QUEUE_WORK32 mCoprocessorFrameQueue[256];  // offset: 0x2130
    u32 mCoprocessorQueueThreadNum;  // offset: 0x4130
    u32 mCoprocessorDrawQueueWritePt;  // offset: 0x4134
    u32 mCoprocessorDrawQueueReadPt;  // offset: 0x4138
    u32 mCoprocessorFrameQueueWritePt;  // offset: 0x413c
    u32 mCoprocessorFrameQueueReadPt;  // offset: 0x4140
    u32 mWaitSleepTime;  // offset: 0x4144
    volatile s32 mDrawSyncQueue;  // offset: 0x4148
    volatile s32 mFrameSyncQueue;  // offset: 0x414c
    u32 mRuntime;  // offset: 0x4150
    static const u32 MAX_COPROCESSOR_THREAD = 5;
    static const u32 MAX_COPROCESSOR_QUEUE = 256;
public:
    static MyDTI DTI;
    static sCoprocessor* mpInstance;
};

inline void* sCoprocessor::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sCoprocessor::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sCoprocessor::DTI)->memFree(p_addr);
}
