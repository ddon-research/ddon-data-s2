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
class cpEquip;
class uModel;

// Declarations
class rPlPartsInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rPlPartsInfo : public cResource
{
public:
    enum
    {
        PARTS_ARISEN_SCAR = 13,
        PARTS_PAWN_SCAR = 14,
    };
public:
    class MyDTI;
    struct HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
        u32 parts_num;  // offset: 0x8
        s16* parts;  // offset: 0x10
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
    rPlPartsInfo();
    virtual ~rPlPartsInfo();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    s16 getPartsID(s32 parts, s32 index);
    s32 getPartsNum();
    void setParts(uModel* pModel, s32 parts, bool flag, cpEquip* pEquip);
    void setScar(uModel* pModel, s32 parts, bool flag, cpEquip* pEquip);
protected:
    HEADER* mpHeader;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u32 DATA_VERSION = 1;
};
