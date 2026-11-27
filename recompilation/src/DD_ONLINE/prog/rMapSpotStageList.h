#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rMapSpotStageList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rMapSpotStageList : public cResource
{
public:
    class MyDTI;
    class Data;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Data : public MtObject
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
        Data();
        virtual ~Data() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool load(MtDataReader& r);
        void copy(rMapSpotStageList::Data* src);
    public:
        s32 mStageNo;  // offset: 0x8
        static MyDTI DTI;
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
    rMapSpotStageList();
    virtual ~rMapSpotStageList();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MT_CTSTR getName() const;  // vtable slot 16
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual Data* getData(u32 index) const;  // vtable slot 17
    virtual u32 getDataNum() const;  // vtable slot 18
public:
    Data* mpArray;  // offset: 0x70
    u32 mArrayNum;  // offset: 0x78
    static const u8 DATA_VERSION = 0;
    static MyDTI DTI;
};

inline void* rMapSpotStageList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rMapSpotStageList::Data::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rMapSpotStageList::Data::Data() {
    this->mStageNo = 0;
}

#include "../../MT/MtDataReader.h"

inline bool rMapSpotStageList::Data::load(MtDataReader& r) {
    mStageNo = r.readS32();
    return true;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* rMapSpotStageList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rMapSpotStageList::DTI)->memAlloc(sz, align, ::rMapSpotStageList::DTI.::MtDTI::getID());
}

inline void rMapSpotStageList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rMapSpotStageList::DTI)->memFree(p_addr);
}

inline rMapSpotStageList::rMapSpotStageList() {
    this->::cResource::setAttribute(22u);
    this->mpArray = nullptr;
    this->mArrayNum = 0;
}

inline void rMapSpotStageList::destruct() {
    unsigned int i0 = 0;
    if (this->mArrayNum != 0) {
        do {
            this->mpArray[i0].~Data();
            i0 += 1u;
        } while (i0 < this->mArrayNum);
    }
    ::MtMemoryAllocator::getAllocator(::rMapSpotStageList::DTI)->memFree(static_cast<void*>(this->mpArray));
    this->mpArray = nullptr;
    this->mArrayNum = 0;
}

inline void* rMapSpotStageList::Data::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rMapSpotStageList::Data::DTI)->memAlloc(sz, align, ::rMapSpotStageList::Data::DTI.::MtDTI::getID());
}

inline void rMapSpotStageList::Data::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rMapSpotStageList::Data::DTI)->memFree(p_addr);
}
