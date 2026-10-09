#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;

// Declarations
class rLanguageResIDConverter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class rLanguageResIDConverter : public cResource
{
public:
    enum
    {
        HEADER_SIZE = 1032,
    };
    enum
    {
        DATA_VERSION = 1,
        TBL_BIT_NUM = 8,
        TBL_NUM = 256,
        TBL_MASK = 255,
    };
public:
    class MyDTI;
    struct stHeader;
    struct stResList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stResList
    {
    public:
        u32 dtiId;  // offset: 0x0
        u32 hashBase;  // offset: 0x4
        u32 hashLng;  // offset: 0x8
    };
public:
    struct stHeader
    {
    public:
        u32 version;  // offset: 0x0
        u32 num;  // offset: 0x4
        u16 topOfs[256];  // offset: 0x8
        u16 nodeNum[256];  // offset: 0x208
        rLanguageResIDConverter::stResList dat[1];  // offset: 0x408
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
    rLanguageResIDConverter();
    virtual ~rLanguageResIDConverter();
    u64 convLangResId(u64 resId);
private:
    void allocMem(u32 size);
    void freeMem();
public:
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
private:
    stHeader* mpHeader;  // offset: 0x70
public:
    static MyDTI DTI;
};
