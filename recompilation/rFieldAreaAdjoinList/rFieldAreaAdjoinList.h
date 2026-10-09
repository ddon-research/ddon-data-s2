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
class rFieldAreaAdjoinList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rFieldAreaAdjoinList : public cResource
{
public:
    class MyDTI;
    class cAdjoinInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAdjoinInfo : public MtObject
    {
    public:
        class MyDTI;
        class cVector3;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cVector3 : public MtObject
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
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void load(MtDataReader& r);
            void save(MtDataWriter& w);
        public:
            MtVector3 mPos;  // offset: 0x10
            u32 mQuestId;  // offset: 0x20
            u32 mFlagId;  // offset: 0x24
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
        cAdjoinInfo();
        virtual ~cAdjoinInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        MtTypedArray<cVector3> mPositions;  // offset: 0x8
        s16 mDestinationStageNo;  // offset: 0x28
        s16 mNextStageNo;  // offset: 0x2a
        u8 mPriority;  // offset: 0x2c
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
    s16 getFieldAreaId() const;
    cAdjoinInfo* getNextStageAdjoinInfo(s32 destinationStageNo) const;
    cAdjoinInfo* getNextStageAdjoinInfo(s32 destinationStageNo, u8 priority) const;
    u32 getNextStageAdjoinInfoNum(s32 destinationStageNo) const;
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rFieldAreaAdjoinList();
    virtual ~rFieldAreaAdjoinList();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
protected:
    void destruct();
protected:
    cAdjoinInfo* mpArray;  // offset: 0x70
    u32 mArrayNum;  // offset: 0x78
    s16 mFieldAreaId;  // offset: 0x7c
public:
    static MyDTI DTI;
};
