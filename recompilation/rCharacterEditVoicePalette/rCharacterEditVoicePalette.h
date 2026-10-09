#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cCharacterEditPaletteBase.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cCharacterEditVoicePalette;
class rCharacterEditVoicePalette;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cCharacterEditVoicePalette : public cCharacterEditPaletteBase
{
public:
    enum
    {
        DATA_VERSION = 34,
    };
    enum
    {
        VOICE_FLAG_DISABLE_PITCH_CHANGE = 1,
        VOICE_FLAG_CHARGE_VOICE = 2,
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
    cCharacterEditVoicePalette();
    // Address: 0x01a7f9c0 - 0x01a7f9c1 (1 bytes)
    virtual ~cCharacterEditVoicePalette() {}
public:
    u32 mUID;  // offset: 0x14
    u32 mVoiceFlag;  // offset: 0x18
    u16 mNameIndex;  // offset: 0x1c
    static MyDTI DTI;
};

class rCharacterEditVoicePalette : public rTbl2<cCharacterEditVoicePalette>
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
    rCharacterEditVoicePalette();
    virtual ~rCharacterEditVoicePalette();
    virtual bool loadData(MtDataReader& r, cCharacterEditVoicePalette* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
    static u32 getUIDFromVoiceNo(u32 voiceNo);
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCharacterEditVoicePalette::cCharacterEditVoicePalette() {
    this->mUID = static_cast<u32>(9999);
    this->mVoiceFlag = static_cast<u32>(0);
    this->mNameIndex = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rCharacterEditVoicePalette::rCharacterEditVoicePalette() {
}
