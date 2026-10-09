#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetObject.h"
#include "MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
struct MtNetError;
class MtObject;
namespace nNetwork { class Member; }
class sNetwork;

// Declarations
struct MtNetAddress;
class MtNetByteOrder;
struct MtNetIpAddress;
class MtNetLog;
struct MtNetPhysicalAddress;
struct MtNetPort;
class MtNetServiceError;
class MtNetTime;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class MtNetByteOrder
{
public:
    static u16 netToHost16(u16 net_u16);
    static u16 hostToNet16(u16 host_u16);
    static u32 netToHost32(u32 net_u32);
    static u32 hostToNet32(u32 host_u32);
    static u64 netToHost64(u64 net_u64);
    static u64 hostToNet64(u64 host_u64);
    static void setBitField32(u32* val, u32 op, u32 sb, u32 bits);
    static u32 getBitField32(u32 val, u32 sb, u32 bits);
};

struct MtNetIpAddress
{
public:
    u8 mData[4];  // offset: 0x0
};

class MtNetLog
{
    // inferred: sNetwork::setLogLevel names MtNetLog::mInstance
    friend class sNetwork;
public:
    enum
    {
        LEVEL_REQUIRED = 0,
        LEVEL_HIGH = 1,
        LEVEL_LOW = 2,
        LEVEL_VERBOSE = 3,
    };
public:
    static MtNetLog* getInstance();
    void setLevel(s32 level);
    s32 getLevel();
    void record(s32 channel, s32 level, MT_CTSTR genre, MT_CTSTR clsname, MT_CTSTR funcname, MT_CTSTR format, ...);
    void clear(s32 channel);
    s32 getNum(s32 channel);
    void resetDraw();
    bool getDrawNext(MT_STR buf_ptr, s32 buf_size, s32 channel);
    void dbgTrace(s32 level, MT_CTSTR format, ...);
    void dbgTraceError(MT_CTSTR format, ...);
    void dbgTraceWarning(MT_CTSTR format, ...);
    MT_CTSTR dbgAddressToString(const MtNetAddress* address);
    MT_CTSTR dbgIpAddressToString(const MtNetIpAddress* ip_address);
    MT_CTSTR dbgBinaryToString(const void* binary, s32 size);
private:
    MtNetLog();
    virtual ~MtNetLog();
private:
    s32 mLevel;  // offset: 0x8
    MT_CHAR mDbgStringTemp[512];  // offset: 0xc
public:
    static const s32 MAX_SIZE_BUF_LOG_GENRE = 16;
    static const s32 MAX_SIZE_BUF_LOG_BODY = 1024;
    static const u32 MAX_NUM_LOG = 512;
private:
    static MtNetLog mInstance;
};

struct MtNetPhysicalAddress
{
public:
    u8 mData[8];  // offset: 0x0
};

struct MtNetPort
{
public:
    u16 mData;  // offset: 0x0
};

class MtNetServiceError : public MtNetObject
{
public:
    enum
    {
        LEVEL_NONE = 0,
        LEVEL_REQUEST = 1,
        LEVEL_SERVICE = 2,
        LEVEL_CONTEXT = 3,
        LEVEL_APP = 4,
    };
    enum
    {
        SERVICE_CONTEXT = 1,
        SERVICE_SESSION = 2,
        SERVICE_RANKING = 4,
    };
public:
    class MyDTI;
    struct Info;
    struct Target;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Info
    {
    public:
        bool mIsGot;  // offset: 0x0
        s32 mLevel;  // offset: 0x4
        MtNetError mError;  // offset: 0x8
        s32 mIndex;  // offset: 0x14
    };
public:
    struct Target
    {
    public:
        const void* mpObject;  // offset: 0x0
        s32 mIndex;  // offset: 0x8
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
    static MtNetServiceError* getInstance();
    MtNetServiceError();
    virtual ~MtNetServiceError();
    void setSupportService(u32 flag);
    void add(s32 level, MtNetError* err, const void* obj);
    bool isExist();
    s32 get(MtNetError* err, s32* index);
    void clear();
    void addTarget(const void* obj);
    void setIndex(const void* obj, s32 index);
    void removeTarget(const void* obj);
    void getInternalError(MtNetError* err);
    void clearInternalError();
    void setInternalError(const MtNetError* err);
    void setInternalError(s32 no, s32 cause, s32 native);
private:
    u32 mSupportService;  // offset: 0x24
    Info mInfo[2];  // offset: 0x28
    Target mTarget[16];  // offset: 0x58
    MtNetError mInternalError;  // offset: 0x158
public:
    static MyDTI DTI;
    static const s32 MAX_NUM_INFO = 2;
    static const s32 MAX_NUM_TARGET = 16;
    static const void* TARGET_ANYBODY;
private:
    static MtNetServiceError* mpInstance;
};

class MtNetTime
{
    // inferred: nNetwork::Member::setNewbie names MtNetTime::mInstance
    friend class nNetwork::Member;
public:
    using Total = u64;
public:
    static MtNetTime* getInstance();
    void updateTime();
    Total getTotalTime() const;
private:
    MtNetTime();
    virtual ~MtNetTime();
private:
    MtCriticalSection mCS;  // offset: 0x8
    Total mTotalTime;  // offset: 0x10
    t64 mBaseMsecs;  // offset: 0x18
    static MtNetTime mInstance;
};

struct MtNetAddress
{
public:
    MtNetIpAddress mIpAddress;  // offset: 0x0
    MtNetPort mPort;  // offset: 0x4
};

// Inline, no code of its own: checked where it is inlined.
inline MtNetServiceError* MtNetServiceError::getInstance() {
    return ::MtNetServiceError::mpInstance;
}
