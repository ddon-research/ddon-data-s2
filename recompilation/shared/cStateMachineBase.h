#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cRemoteProcedure.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtMap;
class MtObject;
class cRemoteCall;

// Declarations
class cStateMachineBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cStateMachineBase : public IStateMachineRpcReceiver
{
public:
    class StateBase;
public:
    using StateKey = s32;
public:
    class StateBase : public MtObject, public IRemoteProcess
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
    protected:
        virtual bool processRemoteCallBoth(cRemoteCall& call, s32 member_id);  // vtable slot 6
        virtual bool processRemoteCall(cRemoteCall& call, bool isParallel, s32 member_id);  // vtable slot 7
        IStateMachineRpcReceiver* getRpcReceiveStateMachine();
        bool IsKilledMessageActor();
        virtual bool processRemoteCallDefault(cRemoteCall& call, bool isParallel, s32 member_id);  // vtable slot 8
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
        StateBase();
        virtual ~StateBase();
        virtual void move();  // vtable slot 9
        virtual void sync();  // vtable slot 10
        virtual bool onEnter();  // vtable slot 11
        virtual void onLeave();  // vtable slot 12
        virtual void onSuspend();  // vtable slot 13
        virtual void onResume();  // vtable slot 14
        void next();
        void end();
        bool isEnd();
        cStateMachineBase::StateBase* change(cStateMachineBase::StateKey key, f32 easeTime);
        cStateMachineBase::StateBase* change(cStateMachineBase::StateBase* state, f32 easeTime);
        cStateMachineBase::StateBase* push(cStateMachineBase::StateKey key, f32 easeTime);
        cStateMachineBase::StateBase* push(cStateMachineBase::StateBase* state, f32 easeTime);
        void pop(f32 easeTime);
        void pop(cStateMachineBase::StateKey key, f32 easeTime);
        void pop(cStateMachineBase::StateBase* state, f32 easeTime);
        void popAll();
        void setId(s32 id);
        virtual s32 getId() const;  // vtable slot 15
        void setNext(cStateMachineBase::StateBase* state);
        void setPrev(cStateMachineBase::StateBase* state);
        void resetNext();
        void resetPrev();
        void setTime(f32 time);
        f32 getTime() const;
        void setContextBase(void* context);
        void setStateMachine(cStateMachineBase* stateMachine);
        void reset();
        f32 getRate() const;
        void setRate(f32 rate);
    protected:
        void* getContextBase() const;
        cStateMachineBase* getStateMachine() const;
    private:
        void* mpContext;  // offset: 0x8
        cStateMachineBase* mpStateMachine;  // offset: 0x10
        s32 mId;  // offset: 0x18
        bool mIsEnd;  // offset: 0x1c
        f32 mTime;  // offset: 0x20
        f32 mNowRate;  // offset: 0x24
        u32 mFrameIndex;  // offset: 0x28
        cStateMachineBase::StateBase* mpPrev;  // offset: 0x30
        cStateMachineBase::StateBase* mpNext;  // offset: 0x38
    public:
        static MyDTI DTI;
    };
public:
    cStateMachineBase();
    virtual ~cStateMachineBase();
    void registerStateFactory(StateKey key, StateBase* state);
    void clearStateFactories();
    void updateParallel();
    void updateSerial();
    bool isEnd();
    bool isEmptyStack() const;
    s32 getStackNumber();
    StateBase* addNextState(StateKey key);
    StateBase* addNextState(StateBase* state);
    StateBase* getCurrentState();
    s32 getCurrentStateId();
    StateBase* changeState(StateKey key, f32 easeTime);
    StateBase* changeState(StateBase* state, f32 easeTime);
    StateBase* pushState(StateKey key, f32 easeTime);
    StateBase* pushState(StateBase* state, f32 easeTime);
    void popState(f32 easeTime);
    void popState(StateKey key, f32 easeTime);
    void popState(StateBase* state, f32 easeTime);
    void popStateAll();
    void popStateAllExceptCurrent();
    virtual bool processRemoteCallInStateMachine(cRemoteCall& message, bool isParallel);  // vtable slot 2
    StateBase* makeStateFromKey(StateKey key);
    void clearTrash();
protected:
    void* getContextBase();
    void initializeStateMachineBase(void* context);
    void clearStateFactory();
private:
    void popState(MtArray* pArray, StateBase* state, f32 easeTime);
private:
    MtMap mStateFactoryMap;  // offset: 0x8
    MtArray mNextStateList;  // offset: 0x4820
    void* mpContext;  // offset: 0x4840
    f32 mStateTime;  // offset: 0x4848
    MtArray mStateStackArray;  // offset: 0x4850
    s32 mStateStackNum;  // offset: 0x4870
    MtArray mStateTrash;  // offset: 0x4878
    bool mIsStateInterrupt;  // offset: 0x4898
};
