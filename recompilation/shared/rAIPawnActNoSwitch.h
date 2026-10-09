#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nDDOUtility.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cAIPawnActNoSwitch;
class rAIPawnActNoSwitch;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cPwActSwTypeFlag = nDDOUtility::cBitSet<6>;
using size_t = _Sizet;
using u32 = unsigned int;

class cAIPawnActNoSwitch : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 5,
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
    cAIPawnActNoSwitch();
    virtual ~cAIPawnActNoSwitch();
public:
    u32 mEmActNo;  // offset: 0x8
    u32 mPwActNo;  // offset: 0xc
    cPwActSwTypeFlag mTypeFlag;  // offset: 0x10
    static MyDTI DTI;
};

class rAIPawnActNoSwitch : public rTbl2<cAIPawnActNoSwitch>
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
    rAIPawnActNoSwitch();
    virtual ~rAIPawnActNoSwitch();
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
    virtual bool loadData(MtDataReader& r, cAIPawnActNoSwitch* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    const cAIPawnActNoSwitch* searchAIPawnActNoSwitch(u32 thkActNo) const;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rAIPawnActNoSwitch::rAIPawnActNoSwitch() {
}
