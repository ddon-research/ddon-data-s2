#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetDevice.h"
#include "MtNetObject.h"

// Forward declarations
struct MtNetError;
class MtPropertyList;

// Declarations
class MtNetRequest;
class MtNetRequestController;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using s32 = int;
using u32 = unsigned int;
using u64 = __uint64_t;
using uintptr = __uintptr_t;

class MtNetRequest : public MtNetObject
{
public:
    enum
    {
        STATUS_NONE = 0,
        STATUS_START = 1,
        STATUS_MOVE = 2,
        STATUS_END = 3,
        STATUS_START_FAIL = 4,
    };
public:
    MtNetRequest(s32 id);
    virtual ~MtNetRequest();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void reset();
    void abort();
    void setStatus(s32 status);
    void setArgument(uintptr* arg, s32 num);
    s32 getStatus() const;
    s32 getId() const;
    u32 getSequence() const;
    bool compareSequence(u32 seq) const;
    void setPhase(s32 phase);
    s32 getPhase() const;
    void resetTime();
    MtNetTime::Total getPastTime() const;
    bool isTimeout();
    void resetLimitTime(MtNetTime::Total limit_time);
    bool isAbort(u32 abortPoint) const;
    void setNeedAnswer();
    bool isNeedAnswer() const;
    void setFinalize();
    bool isFinalize() const;
    void setReentrant();
    bool isReentrant() const;
    void setMove();
    bool isMove() const;
    virtual void clearFatal();  // vtable slot 8
    virtual void setFatal(const MtNetError* err);  // vtable slot 9
    virtual void setFatal(s32 no, s32 cause, s32 native);  // vtable slot 10
    s32 setPointer(s32 idx, void* ptr);
private:
    s32 mId;  // offset: 0x24
    u32 mSequence;  // offset: 0x28
    s32 mStatus;  // offset: 0x2c
    s32 mArgumentNum;  // offset: 0x30
    uintptr mpArgument[8];  // offset: 0x38
    s32 mPointerNum;  // offset: 0x78
    void* mpPointer[8];  // offset: 0x80
    s32 mPhase;  // offset: 0xc0
    MtNetTime::Total mStartTime;  // offset: 0xc8
    MtNetTime::Total mLimitTime;  // offset: 0xd0
    bool mIsAbort;  // offset: 0xd8
    bool mIsNeedAnswer;  // offset: 0xd9
    bool mIsFinalize;  // offset: 0xda
    bool mIsReentrant;  // offset: 0xdb
    bool mIsMove;  // offset: 0xdc
public:
    static const s32 MAX_NUM_ARGUMENT = 8;
    static const s32 MAX_NUM_POINTER = 8;
private:
    static u32 mSequenceValue;
};

class MtNetRequestController : public MtNetObject
{
public:
    class Listener;
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual bool canMoveRequest(MtNetRequest*) = 0;  // vtable slot 2
        virtual s32 startRequest(MtNetRequest*) = 0;  // vtable slot 3
        virtual s32 moveRequest(MtNetRequest*) = 0;  // vtable slot 4
        virtual void endRequest(MtNetRequest*) = 0;  // vtable slot 5
        virtual void startFailRequest(MtNetRequest*) = 0;  // vtable slot 6
    };
public:
    MtNetRequestController();
    virtual ~MtNetRequestController();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void addListener(Listener* listener);
    void move();
    void add(u32* req_seq, s32 req_id, u32 attribute, s32 argc, ...);
    bool isMove(s32 req_id);
    void end(MtNetRequest* req);
    bool isExist();
    bool isNeedFinalize();
    void abort(u32 req_seq);
    void abortAll();
private:
    Listener* mpListener;  // offset: 0x28
    MtNetRequest* mpReqQueue[8];  // offset: 0x30
    bool mIsNeedFinalize;  // offset: 0x70
public:
    static const s32 MAX_NUM_REQUEST = 8;
    static const u32 ATTR_NEED_ANSWER = 1;
    static const u32 ATTR_IS_FINALIZE = 2;
    static const u32 ATTR_IS_REENTRANT = 4;
    static const u32 TMPL_ATTR_NORMAL = 1;
    static const u32 TMPL_ATTR_FINALIZE = 3;
    static const u32 TMPL_ATTR_REENTRANT = 5;
};
