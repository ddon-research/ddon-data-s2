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
class rSoundCurveSet;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundCurveSet : public cResource
{
public:
    class MyDTI;
    struct List;
    struct Curve;
    struct NATIVE_FILE_HEADER;
    struct Element;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct List
    {
    public:
        s16 mID;  // offset: 0x0
        s16 mVolumeCurve;  // offset: 0x2
        s16 mEffectSendCurve;  // offset: 0x4
        s16 mLFECurve;  // offset: 0x6
    };
public:
    struct Curve
    {
    public:
        u32 mElementNum;  // offset: 0x0
        f32 mMaxDistance;  // offset: 0x4
        f32 mZeroDistValue;  // offset: 0x8
        f32 mMaxDistValue;  // offset: 0xc
    };
public:
    struct NATIVE_FILE_HEADER
    {
    public:
        s32 Magic;  // offset: 0x0
        s32 Version;  // offset: 0x4
        u32 ListNum;  // offset: 0x8
        u32 CurveNum;  // offset: 0xc
    };
public:
    struct Element
    {
    public:
        f32 mDistance;  // offset: 0x0
        f32 mValue;  // offset: 0x4
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
    rSoundCurveSet();
    virtual ~rSoundCurveSet();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    Curve* getVolumeCurve(u32 index) const;
    Curve* getEffectSendCurve(u32 index) const;
    Curve* getLFECurve(u32 index) const;
    f32 getVolume(u32 index, f32 dist) const;
    f32 getEffectSend(u32 index, f32 dist) const;
    f32 getLFE(u32 index, f32 dist) const;
private:
    f32 getIntensity(const Curve* pCurve, f32 dist) const;
protected:
    void* memAlloc(u32 sz, u32 align);
    void memFree(void* p_addr);
protected:
    u32 mListNum;  // offset: 0x70
    u32 mCurveNum;  // offset: 0x74
    List* mpLists;  // offset: 0x78
    Curve* mpCurves;  // offset: 0x80
    Curve* * mpCurveRefs;  // offset: 0x88
    void* mpRawData;  // offset: 0x90
    u32 mCurveDataSize;  // offset: 0x98
public:
    static MyDTI DTI;
private:
    static const s32 NativeFileMagic = 1381188435;
    static const s32 NativeFileVersion = 2;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK14rSoundCurveSet5MyDTI11newInstanceEv at 0x01370710-0x01370770, code DWARF attributes to no inlined copy
inline rSoundCurveSet::rSoundCurveSet() {
    this->::cResource::mAttr = static_cast<u32>(18);
    this->mCurveDataSize = static_cast<u32>(0);
    this->mpRawData = static_cast<void*>(nullptr);
    this->mpCurveRefs = static_cast<rSoundCurveSet::Curve* *>(nullptr);
    this->mpCurves = static_cast<rSoundCurveSet::Curve*>(nullptr);
    this->mpLists = static_cast<rSoundCurveSet::List*>(nullptr);
    this->mListNum = static_cast<u32>(0);
    this->mCurveNum = static_cast<u32>(0);
}
