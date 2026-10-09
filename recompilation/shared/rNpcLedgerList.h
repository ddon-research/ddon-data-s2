#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
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

// Declarations
class rNpcLedgerList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rNpcLedgerList : public cResource
{
public:
    class MyDTI;
    class cItem;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cItem : public MtObject
    {
    public:
        class MyDTI;
        class cInstitution;
        class cInstitutionOpenData;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cInstitutionOpenData : public MtObject
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
            bool load(MtDataReader& r);
            bool save(MtDataWriter& w);
        public:
            u32 mType;  // offset: 0x8
            u32 mFlagNo;  // offset: 0xc
            static MyDTI DTI;
        };
    public:
        class cInstitution : public MtObject
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
            virtual ~cInstitution();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            bool load(MtDataReader& r);
            bool save(MtDataWriter& w);
        public:
            MtTypedArray<rNpcLedgerList::cItem::cInstitutionOpenData> mInstitutionOpenList;  // offset: 0x8
            u32 mInstitutionId;  // offset: 0x28
            u32 mInstitutionParam;  // offset: 0x2c
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
        u32 getNpcId() const;
        u8 getSex() const;
        u32 getNameId() const;
        u32 getClassNameId() const;
        u8 getJobId() const;
        u8 getFinger() const;
        u8 getVoiceType() const;
        u8 getUnitType() const;
        u32 getUnitTypeParam() const;
        const MtTypedArray<cInstitution>& getInstitutionList() const;
        cItem(u32 npcId, u8 sex);
        virtual ~cItem();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    protected:
        cItem();
    protected:
        MtTypedArray<cInstitution> mInstitutionList;  // offset: 0x8
        u32 mNpcId;  // offset: 0x28
        u32 mClassNameId;  // offset: 0x2c
        u32 mNameId;  // offset: 0x30
        u32 mUnitTypeParam;  // offset: 0x34
        u8 mSex;  // offset: 0x38
        u8 mJobId;  // offset: 0x39
        u8 mFinger;  // offset: 0x3a
        u8 mVoiceType;  // offset: 0x3b
        u8 mUnitType;  // offset: 0x3c
    public:
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
    u32 getLedgerSize() const;
    const cItem* getNpcInfo(u32 index) const;
    const cItem* searchNpcInfo(u32 npcId) const;
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rNpcLedgerList();
    virtual ~rNpcLedgerList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
protected:
    MtTypedArray<cItem> mArray;  // offset: 0x70
public:
    static MyDTI DTI;
};
