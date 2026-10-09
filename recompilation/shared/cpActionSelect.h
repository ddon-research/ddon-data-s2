#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cDelegate.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cpEnemyThink;
class cpKeyCommand;
class cpSlave;
class uDDOModel;

// Declarations
class cpActionSelect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpActionSelect : public cpComponent
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
    cpActionSelect();
    virtual ~cpActionSelect();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void setupComponentPtr();  // vtable slot 12
    void setId(u32 id);
    s32 getId();
    u32 getDamageAction();
    u32 getCatchAction();
    u32 getTouchAction();
    u32 getAutoAction();
    u32 getEndAction();
    u32 getRequestAction();
    u32 getHighPriorityAction();
    u32 getAction();
    void update();
    void clearLocalRequestAction();
    void clearReserveAction();
    f32 getAngleY();
    f32 getAngleYActBegin(u32 actNo);
    f32 getMoveSpeed();
    u32 getMoveType();
    f32 getMoveLvLX();
    const MtVector3& getTargetPos();
    u32 getTargetUID();
    void setTargetPos(const MtVector3& pos);
    void setTargetUID(u32 uid);
public:
    cDelegate_0<unsigned int> callbackGetDamageAction;  // offset: 0x50
    cDelegate_0<unsigned int> callbackGetCatchAction;  // offset: 0x68
    cDelegate_0<unsigned int> callbackGetTouchAction;  // offset: 0x80
    cDelegate_0<unsigned int> callbackGetAutoAction;  // offset: 0x98
    cDelegate_0<unsigned int> callbackGetEndAction;  // offset: 0xb0
    cDelegate_0<unsigned int> callbackGetRequestAction;  // offset: 0xc8
    cDelegate_0<unsigned int> callbackGetHighPriorityAction;  // offset: 0xe0
    cDelegate_0<unsigned int> callbackGetAction;  // offset: 0xf8
    cDelegate_0<void> callbackUpdate;  // offset: 0x110
    cDelegate_0<void> callbackClearReserveAct;  // offset: 0x128
    cpKeyCommand* mpKeyCommand;  // offset: 0x140
    cpEnemyThink* mpEnemy;  // offset: 0x148
    cpSlave* mpSlave;  // offset: 0x150
protected:
    uDDOModel* mpModel;  // offset: 0x158
    s32 mId;  // offset: 0x160
public:
    static MyDTI DTI;
};
