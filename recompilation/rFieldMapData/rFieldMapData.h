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
struct MtFloat2;
class MtObject;
class MtPropertyList;
class MtStream;
class MtVector3;

// Declarations
class rFieldMapData;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rFieldMapData : public cResource
{
public:
    enum
    {
        TYPE_NONE = 0,
        TYPE_DUMMY1 = 1,
        TYPE_DUMMY2 = 2,
        TYPE_OM_ETC = 3,
        TYPE_SCE_DOOR = 4,
        TYPE_MAP = 5,
        TYPE_MAP_ICON = 6,
        TYPE_TEXT = 7,
        TYPE_BASE = 8,
        TYPE_WELL = 9,
        TYPE_CATACOMB = 10,
        TYPE_CAVE = 11,
        TYPE_WATER_LINE = 12,
        TYPE_ELF_RUIN = 13,
        TYPE_SHRINE = 14,
        TYPE_BASEMENT = 15,
        TYPE_OUTPOST = 16,
        TYPE_DDOR = 17,
        TYPE_AREA_WARP = 18,
        TYPE_MAX = 19,
    };
public:
    class MyDTI;
    class Data;
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
        // Address: 0x01a90d10 - 0x01a90d11 (1 bytes)
        virtual ~Data() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rFieldMapData::Data* src);
        bool load(MtDataReader& r);
        void clear();
    public:
        u32 mType;  // offset: 0x8
        s32 mMessId;  // offset: 0xc
        u32 mSpotMessId;  // offset: 0x10
        u32 mID;  // offset: 0x14
        s32 mStageNo;  // offset: 0x18
        MtFloat2 mPoint;  // offset: 0x1c
        MtVector3 mWorldPos;  // offset: 0x30
        bool mDispWideMap;  // offset: 0x40
        u32 mVersion;  // offset: 0x44
        u32 mQuestId;  // offset: 0x48
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
    rFieldMapData();
    virtual ~rFieldMapData();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual Data* getData(u32 index) const;  // vtable slot 16
    virtual u32 getDataNum() const;  // vtable slot 17
    void setupSpotMsgId();
protected:
    Data* mpArrayData;  // offset: 0x70
    u32 mArrayDataNum;  // offset: 0x78
public:
    static const u8 DATA_VERSION = 18;
    static MyDTI DTI;
};
