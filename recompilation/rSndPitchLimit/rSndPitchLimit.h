#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;

// Declarations
class cSndPitchLimitData;
class rSndPitchLimit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSndPitchLimitData : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 1,
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
    cSndPitchLimitData();
    // Address: 0x01aa6b80 - 0x01aa6b81 (1 bytes)
    virtual ~cSndPitchLimitData() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getVoiceType();
    u32 getSex();
    s32 getLimitUpper();
    s32 getLimitDowner();
public:
    u32 mVoiceType;  // offset: 0x8
    u32 mSex;  // offset: 0xc
    s32 mLimitUpper;  // offset: 0x10
    s32 mLimitDowner;  // offset: 0x14
    static MyDTI DTI;
};

class rSndPitchLimit : public rTbl2<cSndPitchLimitData>
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
    virtual bool loadData(MtDataReader& in, cSndPitchLimitData* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cSndPitchLimitData::cSndPitchLimitData() {
    this->mVoiceType = 1;
    this->mSex = 0;
    this->mLimitUpper = 0;
    this->mLimitDowner = 0;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: parameters bound at each inlined copy's entry: the body its copies' regions agree on (026 P6b1); approximate: no recompile checks it
inline s32 cSndPitchLimitData::getLimitUpper() {
    return this->mLimitUpper;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: parameters bound at each inlined copy's entry: the body its copies' regions agree on (026 P6b1); approximate: no recompile checks it
inline s32 cSndPitchLimitData::getLimitDowner() {
    return this->mLimitDowner;
}
