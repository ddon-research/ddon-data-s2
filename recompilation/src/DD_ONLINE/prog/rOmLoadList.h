#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;

// Declarations
class cOmLoadList;
class rOmLoadList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cOmLoadList : public MtObject
{
public:
    class MyDTI;
    class cOmList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cOmList : public MtObject
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
        cOmList();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(cOmLoadList::cOmList* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mOmId;  // offset: 0x8
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
    cOmLoadList();
    virtual ~cOmLoadList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cOmList* getOmList(u32 index) const;
    u32 getOmListNum() const;
    void addOmId(u32 omId);
    void addOmList(cOmList* p);
    void clearOmList();
public:
    s32 mStageNo;  // offset: 0x8
    s32 mStartPos;  // offset: 0xc
    MtTypedArray<cOmList> mOmList;  // offset: 0x10
    static MyDTI DTI;
    static const u16 DATA_VERSION = 2;
};

class rOmLoadList : public rTbl2<cOmLoadList>
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
    rOmLoadList();
    virtual ~rOmLoadList();
    virtual bool loadData(MtDataReader& in, cOmLoadList* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    cOmLoadList* searchData(s32 stageNo, s32 startPos);
public:
    static MyDTI DTI;
};

inline void* cOmLoadList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cOmLoadList::cOmLoadList() {
    this->mStageNo = -1;
    this->mStartPos = -1;
}

inline void* cOmLoadList::cOmList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cOmLoadList::cOmList::cOmList() {
    this->mOmId = 0;
}

inline void* rOmLoadList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rOmLoadList::rOmLoadList() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cOmLoadList::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cOmLoadList::DTI)->memFree(p_addr);
}

inline void* cOmLoadList::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cOmLoadList::DTI)->memAlloc(sz, align, ::cOmLoadList::DTI.::MtDTI::getID());
}

inline void* cOmLoadList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cOmLoadList::DTI)->memAlloc(sz, align, ::cOmLoadList::DTI.::MtDTI::getID());
}

inline void cOmLoadList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cOmLoadList::DTI)->memFree(p_addr);
}

inline void* cOmLoadList::cOmList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cOmLoadList::cOmList::DTI)->memAlloc(sz, align, ::cOmLoadList::cOmList::DTI.::MtDTI::getID());
}

inline void cOmLoadList::cOmList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cOmLoadList::cOmList::DTI)->memFree(p_addr);
}

inline void* rOmLoadList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rOmLoadList::DTI)->memAlloc(sz, align, ::rOmLoadList::DTI.::MtDTI::getID());
}

inline void rOmLoadList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rOmLoadList::DTI)->memFree(p_addr);
}
