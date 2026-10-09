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
class MtPropertyList;
class MtStream;
class cEditParam;

// Declarations
class rCharacterEdit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rCharacterEdit : public cResource
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
    rCharacterEdit();
    virtual ~rCharacterEdit();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    void copy(const rCharacterEdit* pSrc);
    static u16 toU16(f32 x, f32 place);
    static f32 toF32(u16 x, f32 place);
    static u32 toSlider(f32 x, f32 min, f32 max, u32 div);
    static f32 fromSlider(u32 x, f32 min, f32 max, u32 div);
    static f32 fromSliderEx(u32 x, f32 min, f32 max, u32 div);
    static s32 getPlaceNo(f32 min, f32 max, u32 div);
    static f32 getPlace(f32 min, f32 max, u32 div);
public:
    cEditParam* mpEditParam;  // offset: 0x70
    static MyDTI DTI;
    static const u32 mMagic = 5522501;
};
