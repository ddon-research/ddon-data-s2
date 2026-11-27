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
class rLandInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rLandInfo : public cResource
{
public:
    class MyDTI;
    class cLandInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLandInfo : public MtObject
    {
    public:
        class MyDTI;
        class cLandAreaInfo;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cLandAreaInfo : public MtObject
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
            cLandAreaInfo();
            virtual ~cLandAreaInfo();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            bool load(MtDataReader& r);
            bool save(MtDataWriter& w);
        public:
            u32 mAreaId;  // offset: 0x8
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
        cLandInfo();
        virtual ~cLandInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mLandId;  // offset: 0x8
        MtTypedArray<cLandAreaInfo> mAreaArray;  // offset: 0x10
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
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rLandInfo();
    virtual ~rLandInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
public:
    MtTypedArray<cLandInfo> mLandInfo;  // offset: 0x70
    static MyDTI DTI;
};

inline void* rLandInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rLandInfo::cLandInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rLandInfo::cLandInfo::cLandInfo() {
    this->mLandId = 0;
}

inline void* rLandInfo::cLandInfo::cLandAreaInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rLandInfo::cLandInfo::cLandAreaInfo::cLandAreaInfo() {
    this->mAreaId = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../generated/shared/nDDOIO.h"

inline bool rLandInfo::cLandInfo::load(MtDataReader& r) {
    mLandId = r.readU32();
    nDDOIO::readMtArray(r, mAreaArray);
    return true;
}

inline bool rLandInfo::cLandInfo::cLandAreaInfo::load(MtDataReader& r) {
    mAreaId = r.readU32();
    return true;
}

inline void* rLandInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rLandInfo::DTI)->memAlloc(sz, align, ::rLandInfo::DTI.::MtDTI::getID());
}

inline void rLandInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rLandInfo::DTI)->memFree(p_addr);
}

inline rLandInfo::rLandInfo() {
    this->::cResource::setAttribute(22u);
}

inline void* rLandInfo::cLandInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rLandInfo::cLandInfo::DTI)->memAlloc(sz, align, ::rLandInfo::cLandInfo::DTI.::MtDTI::getID());
}

inline void rLandInfo::cLandInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rLandInfo::cLandInfo::DTI)->memFree(p_addr);
}

inline void* rLandInfo::cLandInfo::cLandAreaInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rLandInfo::cLandInfo::cLandAreaInfo::DTI)->memAlloc(sz, align, ::rLandInfo::cLandInfo::cLandAreaInfo::DTI.::MtDTI::getID());
}

inline void rLandInfo::cLandInfo::cLandAreaInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rLandInfo::cLandInfo::cLandAreaInfo::DTI)->memFree(p_addr);
}
