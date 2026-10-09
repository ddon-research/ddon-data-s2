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
class rSoundDirectionalSet;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rSoundDirectionalSet : public cResource
{
public:
    class MyDTI;
    struct List;
    struct DirectionalCurve;
    struct Element;
    struct NATIVE_FILE_HEADER;
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
        u32 mID;  // offset: 0x0
        u32 mPadding;  // offset: 0x4
        rSoundDirectionalSet::DirectionalCurve* mpCurve;  // offset: 0x8
    };
public:
    struct DirectionalCurve
    {
    public:
        u32 mElementNum;  // offset: 0x0
        f32 mZeroRadianValue;  // offset: 0x4
        f32 mPiRadianValue;  // offset: 0x8
        u32 mPadding;  // offset: 0xc
        rSoundDirectionalSet::Element* mpElementData;  // offset: 0x10
    };
public:
    struct Element
    {
    public:
        f32 mAngle;  // offset: 0x0
        f32 mValue;  // offset: 0x4
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
    rSoundDirectionalSet();
    virtual ~rSoundDirectionalSet();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    DirectionalCurve* getDirectionalCurve(u32 id) const;
    f32 getIntensity(u32 id, f32 ang) const;
private:
    bool createIdToIndexTbl();
protected:
    void* memAlloc(u32 size, u32 align);
    void memFree(void* p_addr);
protected:
    u32 mListNum;  // offset: 0x70
    u32 mCurveNum;  // offset: 0x74
    List* mpLists;  // offset: 0x78
    DirectionalCurve* mpCurves;  // offset: 0x80
    void* mpRawData;  // offset: 0x88
private:
    u16* mpIdToIndexTbl;  // offset: 0x90
    u16 mIdToIndexTblNum;  // offset: 0x98
public:
    static MyDTI DTI;
private:
    static const s32 NativeFileMagic = 1381188691;
    static const s32 NativeFileVersion = 2;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK20rSoundDirectionalSet5MyDTI11newInstanceEv at 0x011fa7b0-0x011fa80f, code DWARF attributes to no inlined copy
inline rSoundDirectionalSet::rSoundDirectionalSet() {
    this->mIdToIndexTblNum = static_cast<u16>(0);
    this->mpIdToIndexTbl = static_cast<u16*>(nullptr);
    this->mpRawData = static_cast<void*>(nullptr);
    this->mpCurves = static_cast<rSoundDirectionalSet::DirectionalCurve*>(nullptr);
    this->mpLists = static_cast<rSoundDirectionalSet::List*>(nullptr);
    this->mListNum = static_cast<u32>(0);
    this->mCurveNum = static_cast<u32>(0);
    this->::cResource::mAttr = static_cast<u32>(18);
}
