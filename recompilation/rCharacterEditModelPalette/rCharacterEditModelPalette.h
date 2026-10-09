#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cCharacterEditPaletteBase.h"
#include "../shared/cResPath.h"
#include "../shared/rModel.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class rModel;

// Declarations
class cCharacterEditModelPalette;
class rCharacterEditModelPalette;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCharacterEditModelPalette : public cCharacterEditPaletteBase
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
    cCharacterEditModelPalette();
    // Address: 0x01a7dbc0 - 0x01a7dbc1 (1 bytes)
    virtual ~cCharacterEditModelPalette() {}
public:
    u32 mUID;  // offset: 0x14
    cResPath<rModel> mPath;  // offset: 0x18
    u32 mRandom;  // offset: 0x20
    static MyDTI DTI;
};

class rCharacterEditModelPalette : public rTbl2<cCharacterEditModelPalette>
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
    rCharacterEditModelPalette();
    virtual ~rCharacterEditModelPalette();
    virtual bool loadData(MtDataReader& r, cCharacterEditModelPalette* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCharacterEditModelPalette::cCharacterEditModelPalette() {
    this->mUID = static_cast<u32>(9999);
    this->mRandom = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rCharacterEditModelPalette::rCharacterEditModelPalette() {
}
