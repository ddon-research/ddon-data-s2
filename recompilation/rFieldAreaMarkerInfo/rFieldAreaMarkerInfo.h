#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
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
class MtVector3;

// Declarations
class rFieldAreaMarkerInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rFieldAreaMarkerInfo : public cResource
{
public:
    enum RES_TYPE
    {
        RES_TYPE_NPC = 0,
        RES_TYPE_SCE_HIT = 1,
        RES_TYPE_RETURNAREA = 2,
        RES_TYPE_OM = 3,
        RES_TYPE_NUM = 4,
    };
public:
    class MyDTI;
    class cMarkerInfo;
public:
    using MarkerInfoArray = MtTypedArray<rFieldAreaMarkerInfo::cMarkerInfo>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMarkerInfo : public MtObject
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
        cMarkerInfo();
        virtual ~cMarkerInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void load(MtDataReader& r);  // vtable slot 6
        virtual void save(MtDataWriter& w);  // vtable slot 7
    public:
        MtVector3 mPos;  // offset: 0x10
        s32 mStageNo;  // offset: 0x20
        u32 mGroupNo;  // offset: 0x24
        u32 mUniqueId;  // offset: 0x28
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
    static MT_CTSTR getFileTitleSuffix(u32 type);
    static MT_CTSTR getFileResId(u32 type);
    const MarkerInfoArray& getMarkerInfoList() const;
    u32 getFieldAreaId() const;
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rFieldAreaMarkerInfo();
    virtual ~rFieldAreaMarkerInfo();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
protected:
    MarkerInfoArray mMarkerInfoList;  // offset: 0x70
    u32 mFieldAreaId;  // offset: 0x90
public:
    static MyDTI DTI;
};
