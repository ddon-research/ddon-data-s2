#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
namespace nNetwork { class RpcNetSystem_Match; }

// Declarations
class RpcTypeSet;
class cRemoteCall;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cRemoteCall : public MtObject
{
    // inferred: nNetwork::RpcNetSystem_Match::RpcNetSystem_Match names cRemoteCall::mAttribute
    friend class nNetwork::RpcNetSystem_Match;
public:
    enum
    {
        ATTR_NONE = 0,
        ATTR_USE_SEREALIZER = 1,
        ATTR_USE_DEADCOPY = 2,
        ATTR_USE_ENCODE = 4,
        SYS_ATTR_SEND = 65536,
        SYS_ATTR_ACK = 131072,
    };
public:
    class MyDTI;
    class MyType;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class MyType
    {
    public:
        MyType();
        ~MyType();
        u32 getID() const;
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
    cRemoteCall();
    cRemoteCall(s32 id);
    virtual ~cRemoteCall();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void serialize(MtStream& queue);  // vtable slot 6
    virtual void deserialize(MtStream& queue);  // vtable slot 7
    u32 getAttribute() const;
    void setAttribute(u32 attr);
    static void writeOut(MtStream& out, cRemoteCall& call);
    static cRemoteCall* newInstance(MtStream& in);
private:
    static void deadcopy(MtStream& dst, cRemoteCall& src);
    static void deadcopy(cRemoteCall& dst, MtStream& src);
private:
    u32 mAttribute;  // offset: 0x8
public:
    static MyDTI DTI;
protected:
    static MyType TYPE;
};

class RpcTypeSet : public cRemoteCall
{
public:
    RpcTypeSet();
    RpcTypeSet(s32);
};
