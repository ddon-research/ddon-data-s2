#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtStlAllocator.h"
#include "MtStlCustom.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "sUnit.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class cRemoteCall;
class sRemoteProcedure;

// Declarations
class IRemoteProcess;
class IStateMachineRpcReceiver;
class cRemoteProcedure;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using RPC_ID = u32;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

class IRemoteProcess
{
public:
    template <typename YType, typename YRpc> class RemoteProcedureCall;
};

class IStateMachineRpcReceiver
{
public:
    IStateMachineRpcReceiver();
    virtual ~IStateMachineRpcReceiver() {}
    virtual bool processRemoteCallInStateMachine(cRemoteCall&, bool) = 0;  // vtable slot 2
};

class cRemoteProcedure : public MtObject, public IRemoteProcess
{
    // inferred: sRemoteProcedure::sFuncUpdateParallel names cRemoteProcedure::mKill
    friend class sRemoteProcedure;
public:
    class MyDTI;
public:
    using DGroupList = MtStlSet<MtString, MtStlAllocator<MtString> >;
    using PROCESS_CALLBACK = void(MtObject::*)(cRemoteCall&, s32);
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
    static void beginParallel(MOVE_LINE line);
    static void endParallel();
    cRemoteProcedure();
    virtual ~cRemoteProcedure();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setup(const MtString& group);
    void setup(RPC_ID id, const MtString& group);
    bool addObject(RPC_ID id, const MtString& group);
    void remove();
    void addCategory(const MtString& group);
    void addGroup(const MtString& group);
    void removeCategory(const MtString& group);
    void removeGroup(const MtString& group);
    bool isRemovedFromCategory(const MtString& group);
    bool isRemovedFromGroup(const MtString& group);
    void setValid(bool);
    bool isValid() const;
    void setKill(bool);
    bool isKill() const;
    void setID(RPC_ID id);
    RPC_ID getID() const;
    MtString getCategory() const;
    MtString getGroup() const;
    void setParallelLine(MOVE_LINE index);
    MOVE_LINE getParallelLine() const;
    bool sendLocal(RPC_ID receiver_id, cRemoteCall& call);
    void sendOthers(RPC_ID receiver_id, cRemoteCall& call, s32 protocol);
    void sendAll(RPC_ID receiver_id, cRemoteCall& call, s32 protocol);
    void sendPeer(RPC_ID receiver_id, cRemoteCall& call, s32 protocol, s32 member_id);
    void sendCategory(const MtString& group, cRemoteCall& call);
    void sendGroup(const MtString& group, cRemoteCall& call);
    virtual bool process(cRemoteCall& call, s32 member);  // vtable slot 6
    virtual bool processRemoteCallDefault(cRemoteCall& call, bool isParallel, s32 member_id);  // vtable slot 7
    virtual bool processRemoteCallBoth(cRemoteCall& call, s32 member_id);  // vtable slot 8
    virtual bool processRemoteCall(cRemoteCall& call, bool issParallel, s32 member_id);  // vtable slot 9
    virtual IStateMachineRpcReceiver* getRpcReceiveStateMachine();  // vtable slot 10
    void registCallback(MtObject*, PROCESS_CALLBACK);
    void clearCallback();
protected:
    bool processRemoteCallComplete(cRemoteCall& call, bool isParallel, s32 member_id);
    bool isParallel() const;
    MOVE_LINE getCurrentParallelLine() const;
    void lock();
    void unlock();
private:
    bool sendRpcNowDirect(cRemoteProcedure* receiver, u8* call) const;
    bool isSendEnable(cRemoteProcedure* object) const;
public:
    DGroupList mRpcGroupList;  // offset: 0x8
protected:
    bool mValid;  // offset: 0x20
    bool mKill;  // offset: 0x21
public:
    MOVE_LINE mCurrentParallelLineLocal;  // offset: 0x24
    MOVE_LINE mParallelLine;  // offset: 0x28
    u32 mLastUpdateIndex;  // offset: 0x2c
    bool mIsParallelLocal;  // offset: 0x30
private:
    RPC_ID mID;  // offset: 0x34
    MtString mGroup;  // offset: 0x38
    MtCriticalSection mCS;  // offset: 0x40
    PROCESS_CALLBACK mpCallback;  // offset: 0x48
    MtObject* mpParent;  // offset: 0x58
public:
    static MyDTI DTI;
    static bool msIsParallel;
    static MOVE_LINE msCurrentParallelLine;
};
