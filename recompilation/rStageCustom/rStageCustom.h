#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"
#include "../shared/rStageCustomParts.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
class MtString;
class rStageCustomParts;

// Declarations
class rStageCustom;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rStageCustom : public cResource
{
public:
    class MyDTI;
    class Area;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Area : public MtObject
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
        Area();
        // Address: 0x01ab2c70 - 0x01ab2c71 (1 bytes)
        virtual ~Area() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rStageCustom::Area* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
    public:
        s8 mAreaNo;  // offset: 0x8
        u8 mFilterNo;  // offset: 0x9
        s32 mGroupNo;  // offset: 0xc
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
    rStageCustom();
    virtual ~rStageCustom();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual Area* getArea(u32 index) const;  // vtable slot 16
    virtual u32 getAreaNum() const;  // vtable slot 17
    rStageCustomParts* getParts() const;
    void setParts(rStageCustomParts* pRes);
    rStageCustomParts::Info* getAreaInfo(s32 areaNo) const;
    u32 getAreaInfoNum() const;
    rStageCustomParts::Info* getAreaInfoFromIndex(s32 index) const;
    s32 getAreaNo(s32 index) const;
    s32 getPartsDataNo() const;
    void getPartsName(MtString& fname) const;
protected:
    void setPartsResNumber();
protected:
    rStageCustomParts* mprParts;  // offset: 0x70
    Area* mpArrayArea;  // offset: 0x78
    u32 mArrayAreaNum;  // offset: 0x80
    s32 mPartsDataNo;  // offset: 0x84
    static const u8 DATA_VERSION = 9;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rStageCustom::Area::Area() {
    this->mAreaNo = static_cast<s8>(-1);
    this->mFilterNo = static_cast<u8>(0);
    this->mGroupNo = static_cast<s32>(-1);
}
