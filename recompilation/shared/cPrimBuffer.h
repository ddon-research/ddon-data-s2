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
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cPrimBuffer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPrimBuffer : public cPrimObj
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
    cPrimBuffer();
    virtual ~cPrimBuffer();
    void* getBuffer(u32);
    s32 writeToBuffer(void*, u32);
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
    u32 getVertexBufferSize() const;
    void resetBuffer();
    void* beginWrite(u32 size);
    s32 endWrite(bool commit);
private:
    void reserveBuffer(u32 size);
private:
    u32 mWriteSize;  // offset: 0x8
    u32 mVBSize;  // offset: 0xc
    u32 mUsedVBSize;  // offset: 0x10
    void* mpAllocVB;  // offset: 0x18
    void* mpCurrentVB;  // offset: 0x20
public:
    static MyDTI DTI;
};
