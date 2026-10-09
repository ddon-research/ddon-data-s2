#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;

// Declarations
class kTHINKDATA;
class rkThinkData;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class kTHINKDATA : public MtObject
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
    kTHINKDATA();
    kTHINKDATA(u32 ltbltype, u64 lflg, u64 luserflg, f32 llengA, f32 llengB, f32 langleA, f32 langleB, f32 lheightA, f32 lheightB, s32 lactionNo, s32 lthintblListIdx, u32 lfunctype, u32 lfuncno, u32 lvalue, u32 lexectype, u32 lexecfuncno, u32 lexevalue, u32 lfunctype2, u32 lfuncno2, u32 lvalue2, u32 lfunctype3, u32 lfuncno3, u32 lvalue3, u64 lbitOnce, u64 lbit, u64 lfreework, f32 lfsys_param0, f32 lfsys_param1, f32 lfsys_param2, f32 lfusr_param0, f32 lfusr_param1, f32 lfusr_param2, f32 lfusr_param3, f32 lfusr_param4);
    // Address: 0x01a6d580 - 0x01a6d581 (1 bytes)
    virtual void createProperty(MtPropertyList& s) {}  // vtable slot 4
    void copy(kTHINKDATA*);
    void load(MtDataReader& r);
    void save(MtDataWriter& w);
public:
    u32 tbltype;  // offset: 0x8
    u64 flg;  // offset: 0x10
    u64 userflg;  // offset: 0x18
    f32 lengA;  // offset: 0x20
    f32 lengB;  // offset: 0x24
    f32 angleA;  // offset: 0x28
    f32 angleB;  // offset: 0x2c
    f32 heightA;  // offset: 0x30
    f32 heightB;  // offset: 0x34
    s32 actionNo;  // offset: 0x38
    s32 thintblListIdx;  // offset: 0x3c
    u32 functype;  // offset: 0x40
    u32 funcno;  // offset: 0x44
    u32 value;  // offset: 0x48
    u32 exectype;  // offset: 0x4c
    u32 execfuncno;  // offset: 0x50
    u32 exevalue;  // offset: 0x54
    u32 functype2;  // offset: 0x58
    u32 funcno2;  // offset: 0x5c
    u32 value2;  // offset: 0x60
    u32 functype3;  // offset: 0x64
    u32 funcno3;  // offset: 0x68
    u32 value3;  // offset: 0x6c
    u64 bitOnce;  // offset: 0x70
    u64 bit;  // offset: 0x78
    u64 freework;  // offset: 0x80
    f32 fsys_param[3];  // offset: 0x88
    f32 fusr_param[5];  // offset: 0x94
    static MyDTI DTI;
};

class rkThinkData : public cResource
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
    rkThinkData();
    virtual ~rkThinkData();
    void destruct();
    // Address: 0x01a98e90 - 0x01a98e91 (1 bytes)
    virtual void clear() {}  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual u32 getInfoNum(s32 type) const;  // vtable slot 16
    virtual kTHINKDATA* getInfo(s32 type, u32 index) const;  // vtable slot 17
public:
    kTHINKDATA* mpArray[128];  // offset: 0x70
    u32 mArrayNum[128];  // offset: 0x470
    u32 mArrayListNum;  // offset: 0x670
    static MyDTI DTI;
    static const u8 DATA_VERSION = 20;
};
