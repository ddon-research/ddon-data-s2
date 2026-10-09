#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cResource.h"

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
class rQuestMarkerInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rQuestMarkerInfo : public cResource
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
    class cInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cInfo : public MtObject
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
        cInfo();
        virtual ~cInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void load(MtDataReader& r);  // vtable slot 6
        virtual void save(MtDataWriter& w);  // vtable slot 7
    public:
        u32 mGroupNo;  // offset: 0x8
        u32 mUniqueId;  // offset: 0xc
        MtVector3 mPos;  // offset: 0x10
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
    static MT_CTSTR getFileTitleSuffix(u32);
    static MT_CTSTR getFileResId(u32 type);
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rQuestMarkerInfo();
    virtual ~rQuestMarkerInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
public:
    u32 mStageNo;  // offset: 0x70
    MtTypedArray<cInfo> mInfoList;  // offset: 0x78
    static MyDTI DTI;
};
