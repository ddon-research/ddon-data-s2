#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;

// Declarations
class rLoadingParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rLoadingParam : public cResource
{
public:
    class MyDTI;
    class cDataList;
    class cData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cData : public MtObject
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
        cData();
        virtual ~cData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r);  // vtable slot 6
        virtual bool save(MtDataWriter& w);  // vtable slot 7
        virtual void copy(rLoadingParam::cData* pSrc, bool isXml);  // vtable slot 8
    public:
        u32 mMsgIdx;  // offset: 0x8
        u32 mImgId;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cDataList : public MtObject
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
        cDataList();
        virtual ~cDataList();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual bool load(MtDataReader& r);  // vtable slot 6
        virtual bool save(MtDataWriter& w);  // vtable slot 7
    public:
        u32 mAreaNo;  // offset: 0x8
        MtTypedArray<rLoadingParam::cData> mList;  // offset: 0x10
        static MyDTI DTI;
        static const u32 LIST_MAX = 5;
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
    rLoadingParam();
    virtual ~rLoadingParam();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MT_CTSTR getName() const;  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
public:
    MtTypedArray<cDataList> mArray;  // offset: 0x70
    static MyDTI DTI;
    static const u32 DATA_VERSION = 4;
    static const u32 DATA_MAGIC = 5260364;
};

inline void* rLoadingParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rLoadingParam::cDataList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rLoadingParam::cData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rLoadingParam::cData::cData() {
    this->mMsgIdx = 0;
    this->mImgId = 0;
}

#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* rLoadingParam::cDataList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rLoadingParam::cDataList::DTI)->memAlloc(sz, align, rLoadingParam::cDataList::DTI.getID());
}

inline rLoadingParam::cDataList::cDataList() {
    mAreaNo = 0;
    mList.setAutoDelete(true);
    mList.reserve(5u);
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* rLoadingParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rLoadingParam::DTI)->memAlloc(sz, align, ::rLoadingParam::DTI.::MtDTI::getID());
}

inline void rLoadingParam::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rLoadingParam::DTI)->memFree(p_addr);
}

inline rLoadingParam::rLoadingParam() {
    this->::cResource::setAttribute(18u);
    this->mArray.::MtArray::mAutoDelete = true;
}

inline void rLoadingParam::cDataList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rLoadingParam::cDataList::DTI)->memFree(p_addr);
}

inline void* rLoadingParam::cData::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rLoadingParam::cData::DTI)->memAlloc(sz, align, ::rLoadingParam::cData::DTI.::MtDTI::getID());
}

inline void rLoadingParam::cData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rLoadingParam::cData::DTI)->memFree(p_addr);
}
