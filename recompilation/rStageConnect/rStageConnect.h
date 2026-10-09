#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class MtStream;
class MtVector3;
namespace nMarker { class cMarkerInfo; }

// Declarations
class rStageConnect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rStageConnect : public cResource
{
public:
    class MyDTI;
    class Data;
    class Connect;
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
        // Address: 0x01aa7550 - 0x01aa7551 (1 bytes)
        virtual ~Data() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        void copy(rStageConnect::Data* src);
    public:
        u32 mType;  // offset: 0x8
        MtVector3 mPos;  // offset: 0x10
        u32 mPartsNo;  // offset: 0x20
        u32 mMapGroup;  // offset: 0x24
        static MyDTI DTI;
    };
public:
    class Connect : public MtObject
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
        Connect();
        // Address: 0x01aa75a0 - 0x01aa75a1 (1 bytes)
        virtual ~Connect() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        void copy(rStageConnect::Connect* src);
    public:
        s16 mStart;  // offset: 0x8
        s16 mGoal;  // offset: 0xa
        s16 mIndex[6];  // offset: 0xc
        u32 mIndexNum;  // offset: 0x18
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
    rStageConnect();
    virtual ~rStageConnect();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MT_CTSTR getName() const;  // vtable slot 16
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual Data* getConnector(u32 index);  // vtable slot 17
    virtual u32 getConnectorNum() const;  // vtable slot 18
    virtual Connect* getConnection(u32 index);  // vtable slot 19
    virtual u32 getConnectionNum() const;  // vtable slot 20
    u32 getMarKerPos(MtVector3& currentPos, MtVector3& targetPos, nMarker::cMarkerInfo& outputMarkersInfo);
    u32 getMarKerPos(MtVector3& currentPos, u32 targetPartNo, nMarker::cMarkerInfo& outputMarkersInfo);
private:
    u32 getMarKerPosSub(u32 currentPartNo, u32 targetPartNo, nMarker::cMarkerInfo& outputMarkersInfo);
protected:
    Data* mpConnectorArray;  // offset: 0x70
    u32 mConnectorNum;  // offset: 0x78
    Connect* mpConnectionArray;  // offset: 0x80
    u32 mConnectionNum;  // offset: 0x88
public:
    static const u8 DATA_VERSION = 1;
    static const u32 CONNECT_NUM = 6;
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rStageConnect::Connect::Connect() {
    this->mStart = static_cast<s16>(-1);
    this->mGoal = static_cast<s16>(-1);
    this->mIndexNum = static_cast<u32>(0);
    this->mIndex[4] = static_cast<short>(-1);
    this->mIndex[5] = static_cast<short>(-1);
    this->mIndex[0] = static_cast<short>(-1);
    this->mIndex[1] = static_cast<short>(-1);
    this->mIndex[2] = static_cast<short>(-1);
    this->mIndex[3] = static_cast<short>(-1);
}
