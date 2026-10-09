#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cPrimObj.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
namespace nPrim { struct Texture; }

// Declarations
class cPrimTexHandle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPrimTexHandle : public cPrimObj
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
    cPrimTexHandle();
    virtual ~cPrimTexHandle();
    u32 searchForTexHandle(const nPrim::Texture& tex);
    u32 addTexHandle(const nPrim::Texture& tex);
    u32 registerTexHandle(const nPrim::Texture& tex);
    void clear();
    nPrim::Texture* getTexture(u32) const;
protected:
    void reserveTexture();
protected:
    nPrim::Texture* mpTexture;  // offset: 0x8
    u32 mTextureNum;  // offset: 0x10
    u32 mTextureSize;  // offset: 0x14
    u32 mCurrentIdx;  // offset: 0x18
public:
    static MyDTI DTI;
};
