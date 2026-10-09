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
class cSoundParamOfs;
class rSoundParamOfs;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;

class cSoundParamOfs : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 2,
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
    cSoundParamOfs();
    // Address: 0x01ab19d0 - 0x01ab19d1 (1 bytes)
    virtual ~cSoundParamOfs() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    f32 getVolume();
    s16 getPitch();
    s32 getProgramNo();
    s8 getPriority();
    s8 getGlobal();
    s8 getID1();
    s8 getID2();
    s8 getID3();
    s8 getLimit();
    s8 getCenterVol();
    s16 getVolCurvId();
    s16 getEffCurvId();
    s16 getLfeCurvId();
    s16 getDirCurvId();
    s8 getSubmixer();
public:
    f32 mVolume;  // offset: 0x8
    s16 mPitchShift;  // offset: 0xc
    s32 mProgramNo;  // offset: 0x10
    s8 mPriority;  // offset: 0x14
    s8 mGlobal;  // offset: 0x15
    s8 mID1;  // offset: 0x16
    s8 mID2;  // offset: 0x17
    s8 mID3;  // offset: 0x18
    s8 mLimit;  // offset: 0x19
    s8 mCenterVol;  // offset: 0x1a
    s16 mVolCurveId;  // offset: 0x1c
    s16 mEffectCurveId;  // offset: 0x1e
    s16 mLfeCurveId;  // offset: 0x20
    s16 mDirectionalCurveId;  // offset: 0x22
    s8 mSubmixer;  // offset: 0x24
    static MyDTI DTI;
};

class rSoundParamOfs : public rTbl2<cSoundParamOfs>
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
    virtual bool loadData(MtDataReader& in, cSoundParamOfs* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cSoundParamOfs::cSoundParamOfs() {
    this->mVolume = 0.0f;
    this->mPitchShift = static_cast<s16>(0);
    this->mCenterVol = static_cast<s8>(0);
    this->mID3 = static_cast<s8>(0);
    this->mLimit = static_cast<s8>(0);
    this->mProgramNo = static_cast<s32>(0);
    this->mPriority = static_cast<s8>(0);
    this->mGlobal = static_cast<s8>(0);
    this->mID1 = static_cast<s8>(0);
    this->mID2 = static_cast<s8>(0);
    this->mSubmixer = static_cast<s8>(0);
    this->mVolCurveId = static_cast<s16>(0);
    this->mEffectCurveId = static_cast<s16>(0);
    this->mLfeCurveId = static_cast<s16>(0);
    this->mDirectionalCurveId = static_cast<s16>(0);
}
