#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nTalk.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;

// Declarations
class cTalkState;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cTalkState : public MtObject
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
    u8 getRno0() const;
    u8 getRno1() const;
    u8 getNextRno0() const;
    nTalk::TALK_STATE getNextState() const;
    virtual nTalk::TALK_STATE getState() const;  // vtable slot 6
    bool shouldTransition() const;
protected:
    void setRno0(u8 r0, u8 r1);
    void setRno1(u8 r1);
    void setNextRno0(u8 r0);
    void setNextState(nTalk::TALK_STATE talkState);
public:
    virtual void initialize();  // vtable slot 7
    virtual void finalize();  // vtable slot 8
    virtual void update();  // vtable slot 9
    virtual void updateUnitPtr();  // vtable slot 10
protected:
    void talkEnd();
public:
    cTalkState();
    cTalkState(u8 r0);
    cTalkState(u8 r0, u8 r1);
    virtual ~cTalkState();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    nTalk::TALK_STATE mNextState;  // offset: 0x8
    u8 mRno0;  // offset: 0xc
    u8 mRno1;  // offset: 0xd
    u8 mNextRno0;  // offset: 0xe
public:
    static MyDTI DTI;
};
