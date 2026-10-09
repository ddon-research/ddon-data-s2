#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class uDDOModel;

// Declarations
class cPlDeadFlow;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPlDeadFlow : public MtObject
{
public:
    enum FlowState
    {
        STATE_ALIVE = 0,
        STATE_INJURED = 1,
        STATE_LOST = 2,
        STATE_GAMEOVER = 3,
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
    cPlDeadFlow();
    virtual ~cPlDeadFlow();
    bool move();
    void moveWait();
    void itemReqResult(void*);
    void setTouchPawn(uDDOModel* pPawn);
    void resetTouchPawn();
    bool isMovePwanReviveMenu();
    bool isMovePlDeadFlow();
private:
    void moveAlive();
    void moveInjured();
    void moveLost();
    void waitAlive();
    void waitInjured();
    void waitLost();
    void changeState(FlowState);
    bool checkPlInjured();
public:
    u32 getReviveType() const;
    void setReviveMenuWait();
private:
    FlowState mState;  // offset: 0x8
    u32 mRno;  // offset: 0xc
    f32 mLostWaitTimer;  // offset: 0x10
    s32 mItemResult;  // offset: 0x14
    s32 mReviveType;  // offset: 0x18
    uDDOModel* mpTouchPawn;  // offset: 0x20
    bool mReviveMenuWait;  // offset: 0x28
public:
    static MyDTI DTI;
private:
    static const u32 DEF_REVIVE_WAIT_TIME = 3;
};
