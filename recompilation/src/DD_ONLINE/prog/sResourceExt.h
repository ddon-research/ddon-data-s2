#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/sResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class cResource;

// Declarations
class sResourceExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class sResourceExt : public sResource
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
    sResourceExt(u32 ringbufsize);
    virtual ~sResourceExt();
private:
    virtual cResource* create(MT_CTSTR path, const MtDTI* pbase, u32 mode);  // vtable slot 11
    virtual cResource* create(const MtDTI& dti, MT_CTSTR path, u32 mode);  // vtable slot 12
    virtual cResource* create(MtStream& in, const MtDTI& dti, MT_CTSTR path, cResource::QUALITY quality);  // vtable slot 13
    virtual cResource* create(u64 id);  // vtable slot 14
public:
    cResource* findResource(const MtDTI& dti, MT_CTSTR path);
    cResource* findResourceTbl(const MtDTI& dti, MT_CTSTR path);
    virtual void addRef(cResource* pr);  // vtable slot 15
    virtual void release(cResource* pr);  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    bool setupFileCache();
    void setStartCacheRegisterThread(bool);
    bool isStartCacheRegisterThread();
    u32 getResourceCRC(cResource*);
    u32 getAsyncLoadNum() const;
protected:
    virtual void onLoadListAppend();  // vtable slot 17
    static int cbLoadListSort(const void* a, const void* b);
private:
    bool isLoaderThread() const;
    bool isDecoderThread() const;
    void blockOnUnsafeRequest(cResource* rsrc, u32 mode);
    bool validatePath(MT_CTSTR path);
private:
    bool mIsStartCacheRegisterThread;  // offset: 0x4a1cd
public:
    static MyDTI DTI;
};

inline void* sResourceExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
