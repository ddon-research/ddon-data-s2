#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "nDrawTexture.h"
#include "rTexture.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;

// Declarations
class rRenderTargetTexture;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rRenderTargetTexture : public rTexture
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
    rRenderTargetTexture();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool createRenderTarget(u32 type, u32 width, u32 height, u32 level_count, nDraw::FORMAT_TYPE format, bool auto_resize);
protected:
    virtual ~rRenderTargetTexture();
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK20rRenderTargetTexture5MyDTI11newInstanceEv at 0x011dd700-0x011dd725, code DWARF attributes to no inlined copy
inline rRenderTargetTexture::rRenderTargetTexture() {
    this->::cResource::mAttr = static_cast<u32>(16);
}
