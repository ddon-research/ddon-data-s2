#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "sRemoteProcedure.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class sRemoteProcedureExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using RPC_ID = u32;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

class sRemoteProcedureExt : public sRemoteProcedure
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
    sRemoteProcedureExt();
    virtual ~sRemoteProcedureExt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void init();  // vtable slot 11
    virtual void move();  // vtable slot 7
    void sendNetwork(MtObject* pobj, s32 sendMemberType, u32 characterId, u32 protocol, u32 rpc_id);
    void receiveNetwork(s32 sessionId, u32 characterId, u8* data_ptr, u32 data_size);
public:
    static MyDTI DTI;
private:
    static const RPC_ID USER_RPC_ID_TOP = 1000;
    static const RPC_ID USER_RPC_ID_NUM = 4294966295;
    static const RPC_ID USER_RPC_ID_END = 4294967295;
public:
    static const RPC_ID USER_RPC_ID_GAME = 1010;
    static const RPC_ID USER_RPC_ID_SET = 1030;
    static const RPC_ID USER_RPC_ID_ITEM = 1040;
    static const RPC_ID USER_RPC_ID_TOOL = 1100;
    static const RPC_ID USER_RPC_ID_CONTEXT = 2000;
    static const RPC_ID USER_RPC_ID_CTRL = 3000;
};
