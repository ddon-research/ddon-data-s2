#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/nDrawScene.h"
#include "../../XFramework/sRender.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtSize;
class cDraw;

// Declarations
class sRenderExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class sRenderExt : public sRender
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
    sRenderExt(u32 rendermode_flags, u32 cmdbufsize, u32 ringbufsize, u32 tempvertexbufsize, u32 tempindexbufsize, nDraw::HDR_TYPE temphdrtype);
    virtual ~sRenderExt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    void endProtect();
    MtSize getDisplaySize() const;
private:
    virtual void rsxSyncBackEnd(cDraw* pDraw);  // vtable slot 13
public:
    bool isEnablePrioAttrExpand();
    void setupEnablePrioAttrExpand();
    virtual bool isPossibleDrawFromDrawBuffer();  // vtable slot 12
public:
    bool mIsEnablePrioAttrExpand;  // offset: 0x112ccec
private:
    f32 mBorderDrawBufferParcentage;  // offset: 0x112ccf0
public:
    static MyDTI DTI;
};

inline void* sRenderExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* sRenderExt::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sRenderExt::DTI);
}

inline void sRenderExt::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sRenderExt::DTI)->memFree(p_addr);
}
