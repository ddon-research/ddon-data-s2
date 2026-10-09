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
class rTblMenuComm;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rTblMenuComm : public cResource
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
        virtual void copy(rTblMenuComm::cData* pSrc, bool isXml);  // vtable slot 8
    public:
        u32 mId;  // offset: 0x8
        u32 mId2;  // offset: 0xc
        u32 mVoiceId;  // offset: 0x10
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
        u32 mCtgrId;  // offset: 0x8
        MtTypedArray<rTblMenuComm::cData> mList;  // offset: 0x10
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
    rTblMenuComm();
    virtual ~rTblMenuComm();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MT_CTSTR getName() const;  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    u32 getCtgrId(u32 uIdx);
    u32 getMsgId(u32 uCtgrIdx, u32 uIdx, bool bUseId2);
    u32 getVoiceId(u32 uCtgrIdx, u32 uIdx);
    u32 searchVoiceIdFromMsgId(u32 uMsgId);
    u32 searchCtgrIdxFromVoiceId(u32 uVoiceId);
    u32 searchMsgIdxFromVoiceId(u32 uVoiceId);
    u32 searchMsgIdFromVoiceId(u32 uVoiceId, bool bId2);
    u32 getCtgrNum();
    u32 getMsgNum(u32 uCtgrIdx);
public:
    u32 mResourceType;  // offset: 0x70
    MtTypedArray<cDataList> mArray;  // offset: 0x78
    static MyDTI DTI;
    static const u32 DATA_VERSION = 3;
    static const u32 DATA_MAGIC = 4410708;
    static const u32 INVALID_ID = 4294967295;
};

// Inline, no code of its own: checked where it is inlined.
inline rTblMenuComm::cData::cData() {
    this->mId = static_cast<u32>(0);
    this->mId2 = static_cast<u32>(4294967295);
    this->mVoiceId = static_cast<u32>(4294967295);
}
