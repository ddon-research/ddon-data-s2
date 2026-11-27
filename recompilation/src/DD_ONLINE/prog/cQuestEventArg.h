#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class cQuestEventArg;
class cQuestEventArgEntryParty;
class cQuestEventArgLeaveParty;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestEventArg : public MtObject
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
    cQuestEventArg();
    virtual ~cQuestEventArg();
public:
    static MyDTI DTI;
};

class cQuestEventArgEntryParty : public cQuestEventArg
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
    u32 getCharacterId() const;
    void setCharacterId(u32 characterId);
    bool isPawn() const;
    cQuestEventArgEntryParty();
    cQuestEventArgEntryParty(u32 characterId, bool isPawn);
    virtual ~cQuestEventArgEntryParty();
protected:
    u32 mCharacterId;  // offset: 0x8
    bool mIsPawn;  // offset: 0xc
public:
    static MyDTI DTI;
};

class cQuestEventArgLeaveParty : public cQuestEventArg
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
    u32 getCharacterId() const;
    void setCharacterId(u32 characterId);
    bool isPawn() const;
    cQuestEventArgLeaveParty();
    cQuestEventArgLeaveParty(u32 characterId, bool isPawn);
    virtual ~cQuestEventArgLeaveParty();
protected:
    u32 mCharacterId;  // offset: 0x8
    bool mIsPawn;  // offset: 0xc
public:
    static MyDTI DTI;
};

inline void* cQuestEventArg::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestEventArgEntryParty::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestEventArgLeaveParty::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cQuestEventArg::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestEventArg::DTI)->memAlloc(sz, align, ::cQuestEventArg::DTI.::MtDTI::getID());
}

inline void cQuestEventArg::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestEventArg::DTI)->memFree(p_addr);
}

inline void cQuestEventArgEntryParty::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestEventArgEntryParty::DTI)->memFree(p_addr);
}

inline void cQuestEventArgLeaveParty::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestEventArgLeaveParty::DTI)->memFree(p_addr);
}
