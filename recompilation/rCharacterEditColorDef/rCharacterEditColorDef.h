#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cCharacterEditPaletteBase.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtDataReader;
class MtObject;
class MtVector4;

// Declarations
class cCharacterEditColorDef;
class rCharacterEditColorDef;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCharacterEditColorDef : public cCharacterEditPaletteBase
{
public:
    enum
    {
        DATA_VERSION = 34,
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
    cCharacterEditColorDef();
    // Address: 0x01a7d6b0 - 0x01a7d6b1 (1 bytes)
    virtual ~cCharacterEditColorDef() {}
public:
    bool mUse;  // offset: 0x14
    MtVector4 mColor;  // offset: 0x20
    MtColor mUIColor;  // offset: 0x30
    static MyDTI DTI;
};

class rCharacterEditColorDef : public rTbl2<cCharacterEditColorDef>
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
    virtual bool loadData(MtDataReader& r, cCharacterEditColorDef* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
