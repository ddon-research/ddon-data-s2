#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtStlAllocator.h"
#include "MtStlCustom.h"
#include "MtString.h"
#include "cRemoteCall.h"
#include "cSystem.h"
#include "sUnit.h"

// Standard library
#include <utility>

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMap;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class cRemoteCall;
class cRemoteProcedure;
namespace nNetBase { class cNetBase; }

// Declarations
class sRemoteProcedure;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using RPC_ID = u32;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;

class sRemoteProcedure : public cSystem
{
    // inferred: cRemoteProcedure::remove names sRemoteProcedure::mpInstance
    friend class cRemoteProcedure;
    // inferred: nNetBase::cNetBase::castMsgAddress names sRemoteProcedure::mpInstance
    friend class nNetBase::cNetBase;
public:
    enum
    {
        ID_SYSTEM = 1,
        ID_SYSTEM_SESSION = 1,
        ID_SYSTEM_SHM = 11,
        ID_APPLICATION = 1000,
    };
public:
    class MyDTI;
    struct SParallelNode;
    struct SNode;
    class cTemporaryRemoteCall;
public:
    using DObjIDList = MtStlMap<unsigned int, cRemoteProcedure*, MtStlAllocator<std::pair<const unsigned int, cRemoteProcedure*> > >;
    using DGroupMap = MtStlMap<MtString, MtStlVector<sRemoteProcedure::SParallelNode, MtStlAllocator<sRemoteProcedure::SParallelNode> >, MtStlAllocator<std::pair<const MtString, MtStlVector<sRemoteProcedure::SParallelNode, MtStlAllocator<sRemoteProcedure::SParallelNode> > > > >;
    using DObjList = MtStlVector<sRemoteProcedure::SNode, MtStlAllocator<sRemoteProcedure::SNode> >;
    using DObjIndexMap = MtStlMap<unsigned int, unsigned int, MtStlAllocator<std::pair<const unsigned int, unsigned int> > >;
    using DParallelList = MtStlVector<sRemoteProcedure::SParallelNode, MtStlAllocator<sRemoteProcedure::SParallelNode> >;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SNode
    {
    public:
        SNode(cRemoteProcedure* object, u32 nextEmpty);
    public:
        cRemoteProcedure* mpObj;  // offset: 0x0
        u32 mNextEmpty;  // offset: 0x8
    };
public:
    class cTemporaryRemoteCall : public cRemoteCall
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
        cTemporaryRemoteCall();
        cTemporaryRemoteCall(MtObject* obj, s32 from_id);
        virtual ~cTemporaryRemoteCall();
        cRemoteCall* getRpc();
        s32 getFromId();
    private:
        MtObject* mpObject;  // offset: 0x10
        s32 mFromId;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    struct SParallelNode
    {
    public:
        SParallelNode();
    public:
        sRemoteProcedure::DObjList mObjList;  // offset: 0x0
        u32 mNextEmptyIndex;  // offset: 0x20
        sRemoteProcedure::DObjIndexMap mObjMap;  // offset: 0x28
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
    sRemoteProcedure();
    virtual ~sRemoteProcedure();
    virtual void move();  // vtable slot 7
    virtual void sync();  // vtable slot 10
    virtual void init();  // vtable slot 11
    virtual void final();  // vtable slot 12
    virtual void reset();  // vtable slot 6
    virtual void createPropertyProcedures(MtPropertyList& s);  // vtable slot 13
    virtual void createPropertyTrace(MtPropertyList& s);  // vtable slot 14
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void makeCategory(MT_CTSTR group_name);
    void makeGroup(MT_CTSTR group_name);
    bool addObject(cRemoteProcedure* object, RPC_ID proc_id, const MtString& group);
    void removeObject(cRemoteProcedure* object);
    void removeObjectFromCategory(const MtString& group, cRemoteProcedure* object);
    void removeObjectFromGroup(const MtString& group, cRemoteProcedure* object);
    void callbackFunctionEachReceiver(const MtString& group, cRemoteCall& call) const;
    bool changeObjectID(RPC_ID from, RPC_ID to);
    void changeParallelLine(cRemoteProcedure* object, MOVE_LINE index);
    void optimize();
    cRemoteProcedure* getObject(RPC_ID rpc_id);
    void setUserLocation(u32 range);
    void sendNetwork(MtObject* pobj, s32 member_id, u32 protocol, u32 rpc_id);
    void receiveNetwork(s32 member_id, u8* data_ptr, u32 data_size);
    void record(MT_CTSTR name, s32 src_id, s32 dst_id, s32 length, bool isSend);
    void initTrace(u32 size);
    static sRemoteProcedure* getInstance();
private:
    void addObjectToParallelNode(SParallelNode& parallelNode, cRemoteProcedure* object);
    void removeObjectInfo(cRemoteProcedure* object);
    void removeObjectFromParalleNode(SParallelNode& parallelNode, cRemoteProcedure* object);
    cRemoteProcedure* getElement(u32 index);
    u32 getElementNum();
    void setElement(cRemoteProcedure* proc, u32);
    void setElementNum(u32 num);
    static void sFuncResetObject(cRemoteProcedure* object);
    static void sFuncUpdateParallel(cRemoteProcedure* object);
    static void sFuncUpdateSerial(cRemoteProcedure* object);
    void addTemporary(RPC_ID id, cRemoteCall& call, s32 from_id);
public:
    void getTemporary(RPC_ID id);
    void clearTemporary(RPC_ID id);
    void clearTemporaryAll();
    void setUseTemporary(bool);
    bool isUseTemporary();
    bool isPoolTemprary(RPC_ID id);
private:
    RPC_ID mAutoAllocator;  // offset: 0x14
    u16 mSystemAllocator;  // offset: 0x18
    u16 mSynchronizerAllocator;  // offset: 0x1a
    u16 mHealthCheckerAllocator;  // offset: 0x1c
    DObjIDList mIdMap;  // offset: 0x20
    DGroupMap mGroupMap;  // offset: 0x38
    MtMap mDataTemporary;  // offset: 0x50
    bool mUseTemporary;  // offset: 0x4868
public:
    static MyDTI DTI;
    static RPC_ID sAutoAllocatorTop;
    static const RPC_ID sAliveID;
    static const RPC_ID sInvalidID;
    static const u32 DEFAULT_TRACE_SIZE = 32;
private:
    static sRemoteProcedure* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline sRemoteProcedure* sRemoteProcedure::getInstance() {
    return ::sRemoteProcedure::mpInstance;
}
