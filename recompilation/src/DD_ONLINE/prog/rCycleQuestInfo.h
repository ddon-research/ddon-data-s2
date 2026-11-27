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
class rCycleQuestInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rCycleQuestInfo : public cResource
{
public:
    class MyDTI;
    class cCycleQuestInfo;
    class cCycleQuestSituationInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCycleQuestSituationInfo : public MtObject
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
        cCycleQuestSituationInfo();
        virtual ~cCycleQuestSituationInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mSituationNo;  // offset: 0x8
        u32 mSituationNameIdx;  // offset: 0xc
        u32 mSituationStateIdx;  // offset: 0x10
        u32 mSituationDetailIdx;  // offset: 0x14
        static MyDTI DTI;
    };
public:
    class cCycleQuestInfo : public MtObject
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
        cCycleQuestInfo();
        virtual ~cCycleQuestInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mCycleNo;  // offset: 0x8
        u32 mCycleSubNo;  // offset: 0xc
        u32 mContentNameIdx;  // offset: 0x10
        u32 mContentInfoIdx;  // offset: 0x14
        u32 mGatherInfoIdx;  // offset: 0x18
        MtTypedArray<rCycleQuestInfo::cCycleQuestSituationInfo> mSituationInfo;  // offset: 0x20
        u32 mGatherNpcId;  // offset: 0x40
        u32 mGatherStageNo;  // offset: 0x44
        u32 mGatherStartPos;  // offset: 0x48
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
    rCycleQuestInfo();
    virtual ~rCycleQuestInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
public:
    MtTypedArray<cCycleQuestInfo> mCycleQuestInfo;  // offset: 0x70
    static MyDTI DTI;
};

inline void* rCycleQuestInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rCycleQuestInfo::cCycleQuestInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rCycleQuestInfo::cCycleQuestSituationInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rCycleQuestInfo::cCycleQuestSituationInfo::cCycleQuestSituationInfo() {
    this->mSituationStateIdx = 0;
    this->mSituationDetailIdx = 0;
    this->mSituationNo = 0;
    this->mSituationNameIdx = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../generated/shared/nDDOIO.h"

inline rCycleQuestInfo::cCycleQuestInfo::cCycleQuestInfo() {
    mCycleNo = 0u;
    mCycleSubNo = 0u;
    mContentNameIdx = 0u;
    mContentInfoIdx = 0u;
    mGatherInfoIdx = 0u;
    mGatherNpcId = 0u;
    mGatherStageNo = 0u;
    mGatherStartPos = 0u;
}

inline bool rCycleQuestInfo::cCycleQuestInfo::load(MtDataReader& r) {
    mCycleNo = r.readU32();
    mCycleSubNo = r.readU32();
    mContentNameIdx = r.readU32();
    mContentInfoIdx = r.readU32();
    mGatherInfoIdx = r.readU32();
    nDDOIO::readMtArray(r, mSituationInfo);
    mGatherNpcId = r.readU32();
    mGatherStageNo = r.readU32();
    mGatherStartPos = r.readU32();
    return true;
}

inline void* rCycleQuestInfo::cCycleQuestInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rCycleQuestInfo::cCycleQuestInfo::DTI)->memAlloc(sz, align, rCycleQuestInfo::cCycleQuestInfo::DTI.getID());
}

inline bool rCycleQuestInfo::cCycleQuestSituationInfo::load(MtDataReader& r) {
    mSituationNo = r.readU32();
    mSituationNameIdx = r.readU32();
    mSituationStateIdx = r.readU32();
    mSituationDetailIdx = r.readU32();
    return true;
}

inline void* rCycleQuestInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rCycleQuestInfo::DTI)->memAlloc(sz, align, ::rCycleQuestInfo::DTI.::MtDTI::getID());
}

inline void rCycleQuestInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rCycleQuestInfo::DTI)->memFree(p_addr);
}

inline rCycleQuestInfo::rCycleQuestInfo() {
    this->::cResource::setAttribute(22u);
}

inline void rCycleQuestInfo::cCycleQuestInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rCycleQuestInfo::cCycleQuestInfo::DTI)->memFree(p_addr);
}

inline void* rCycleQuestInfo::cCycleQuestSituationInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rCycleQuestInfo::cCycleQuestSituationInfo::DTI)->memAlloc(sz, align, ::rCycleQuestInfo::cCycleQuestSituationInfo::DTI.::MtDTI::getID());
}

inline void rCycleQuestInfo::cCycleQuestSituationInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rCycleQuestInfo::cCycleQuestSituationInfo::DTI)->memFree(p_addr);
}
