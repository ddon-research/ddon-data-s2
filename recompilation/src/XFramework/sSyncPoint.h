#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "cSystem.h"
#include "nSyncPoint.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nSyncPoint { class cSyncPointDefinition; }

// Declarations
class sSyncPoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f64 = double;
namespace nSyncPoint { using SYNC_CB_PROC = void(*)(void*); }
namespace nSyncPoint { using SYNC_CB_PROC_MT = void(MtObject::*)(void*); }
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sSyncPoint : public cSystem
{
    friend class nSyncPoint::cSyncPointDefinition;
public:
    class MyDTI;
    class syncPointElement;
    struct callbackInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class syncPointElement : public MtObject
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
        syncPointElement();
        virtual ~syncPointElement();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        sSyncPoint::callbackInfo* mpCallbackPool;  // offset: 0x8
        u32 mCallbackWPtr;  // offset: 0x10
        u32 mCallbackRPtr;  // offset: 0x14
        static MyDTI DTI;
    };
public:
    struct callbackInfo
    {
    public:
        callbackInfo();
        bool isNaked() const;
        void callFunction() const;
        void clear();
    public:
        MtObject* pOwner;  // offset: 0x0
        union
        {
        public:
            void* pProc;  // offset: 0x0
            nSyncPoint::SYNC_CB_PROC pProcC;  // offset: 0x0
            nSyncPoint::SYNC_CB_PROC_MT pProcMT;  // offset: 0x0
        };  // offset: 0x8
        void* pParam;  // offset: 0x18
        u8 padding0;  // offset: 0x20
        u8 padding1;  // offset: 0x21
        u8 padding2;  // offset: 0x22
        u8 padding3;  // offset: 0x23
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
private:
    sSyncPoint();
public:
    static sSyncPoint* createInstance(u32 sizeBuffer);
    static void deleteInstance();
    virtual ~sSyncPoint();
    static sSyncPoint* getInstance();
    void addReceiver(nSyncPoint::eSyncPoint sp, nSyncPoint::SYNC_CB_PROC pCallback, void* pParam);
    void addReceiver(nSyncPoint::eSyncPoint sp, MtObject* pOwner, nSyncPoint::SYNC_CB_PROC_MT pCallback, void* pParam);
    nSyncPoint::eSyncPoint getStatus() const;
protected:
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    bool init(u32 sizeBuffer);
    void final();
    void updateStatus(nSyncPoint::eSyncPoint sp);
    static f64 calcLog2(f64 v);
    static u32 calcLowerPOT(u32 value);
    void flushBuffer(nSyncPoint::eSyncPoint sp);
    callbackInfo* allocateBuffer(nSyncPoint::eSyncPoint sp);
private:
    nSyncPoint::eSyncPoint mStatus;  // offset: 0x14
    syncPointElement mCallbackInfo[6];  // offset: 0x18
public:
    static MyDTI DTI;
private:
    static u32 MAX_CALLBACK_POOL;
    static sSyncPoint* mpInstance;
};

inline void* sSyncPoint::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* sSyncPoint::syncPointElement::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sSyncPoint::syncPointElement::syncPointElement() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sSyncPoint::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sSyncPoint::DTI)->memFree(p_addr);
}

inline void* sSyncPoint::syncPointElement::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::sSyncPoint::syncPointElement::DTI)->memAlloc(sz, align, ::sSyncPoint::syncPointElement::DTI.::MtDTI::mID);
}

inline void sSyncPoint::syncPointElement::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sSyncPoint::syncPointElement::DTI)->memFree(p_addr);
}
