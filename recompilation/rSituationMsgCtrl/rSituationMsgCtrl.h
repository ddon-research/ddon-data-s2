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
class rSituationMsgCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSituationMsgCtrl : public cResource
{
public:
    class MyDTI;
    class cSituationData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSituationData : public MtObject
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
        cSituationData(u32 GroupSerial, u32 StartQuestId, bool IsStartQuestIdStart, u32 EndQuestId, bool IsEndQuestIdStart);
        virtual ~cSituationData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mGroupSerial;  // offset: 0x8
        u32 mStartQuestId;  // offset: 0xc
        bool mIsStartQuestIdStart;  // offset: 0x10
        u32 mEndQuestId;  // offset: 0x14
        bool mIsEndQuestIdStart;  // offset: 0x18
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
    rSituationMsgCtrl();
    virtual ~rSituationMsgCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
public:
    MtTypedArray<cSituationData> mArray;  // offset: 0x70
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: specialized to the arguments every copy passes (DW_AT_const_value; 023 T608, 2.7.0 specialized-constant constructors); approximate: no recompile checks its other arguments
inline rSituationMsgCtrl::cSituationData::cSituationData(u32 GroupSerial, u32 StartQuestId, bool IsStartQuestIdStart, u32 EndQuestId, bool IsEndQuestIdStart) {
    this->mGroupSerial = static_cast<u32>(0);
    this->mStartQuestId = static_cast<u32>(0);
    this->mIsStartQuestIdStart = false;
    this->mEndQuestId = static_cast<u32>(0);
    this->mIsEndQuestIdStart = false;
}
