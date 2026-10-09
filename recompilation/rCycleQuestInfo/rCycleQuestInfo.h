#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

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

// Inline, no code of its own: checked where it is inlined.
inline rCycleQuestInfo::cCycleQuestSituationInfo::cCycleQuestSituationInfo() {
    this->mSituationStateIdx = static_cast<u32>(0);
    this->mSituationDetailIdx = static_cast<u32>(0);
    this->mSituationNo = static_cast<u32>(0);
    this->mSituationNameIdx = static_cast<u32>(0);
}
