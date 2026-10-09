#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct _SceKernelEventFlag;
struct _SceKernelSema;
struct pthread_mutex;

// Declarations
class MtCriticalSection;
class MtSemaphore;
namespace nWin32Detour { class eventFlag; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SceKernelEventFlag = _SceKernelEventFlag*;
using SceKernelSema = _SceKernelSema*;
using pthread_mutex_t = pthread_mutex*;
using ScePthreadMutex = pthread_mutex_t;
using u32 = unsigned int;

class MtCriticalSection
{
public:
    MtCriticalSection();
    ~MtCriticalSection();
    void lock();
    bool tryLock();
    void unlock();
private:
    ScePthreadMutex mCSection;  // offset: 0x0
};

class MtSemaphore
{
public:
    MtSemaphore(const u32 initial_count, const u32 maximum_count, MT_CTSTR name);
    ~MtSemaphore();
    void release(const u32 count);
    void wait(const u32 time_out);
private:
    SceKernelSema mHandle;  // offset: 0x0
};

namespace nWin32Detour {
    class eventFlag
    {
    public:
        enum eStatus
        {
            STATUS_FREE = 0,
            STATUS_NOTIFIED = 1,
            STATUS_RECEIVED = 2,
        };
    public:
        eventFlag();
        ~eventFlag();
        void wait();
        void set();
        void reset();
    private:
        SceKernelEventFlag mEventFlag;  // offset: 0x0
    };
}  // namespace nWin32Detour
