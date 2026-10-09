#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;

// Declarations
class cCharacterEditPaletteBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCharacterEditPaletteBase : public MtObject
{
public:
    enum
    {
        FLAG_IS_AVAILABLE_PLAYER_FIRST_EDIT = 1,
        FLAG_IS_AVAILABLE_PLAYER_HAIR_SALOON = 2,
        FLAG_IS_AVAILABLE_PAWN_FIRST_EDIT = 4,
        FLAG_IS_AVAILABLE_PAWN_HAIR_SALOON = 8,
        FLAG_IS_AVAILABLE_REWARD = 16,
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
    cCharacterEditPaletteBase();
    virtual ~cCharacterEditPaletteBase() {}
    bool loadData(MtDataReader& r);
    bool saveData(MtDataWriter& w);
public:
    u32 mIconNo;  // offset: 0x8
    u32 mReleaseVersion;  // offset: 0xc
    u32 mFlag;  // offset: 0x10
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCharacterEditPaletteBase::cCharacterEditPaletteBase() {
    this->mIconNo = static_cast<u32>(0);
    this->mReleaseVersion = static_cast<u32>(0);
    this->mFlag = static_cast<u32>(0);
}
