#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;

// Declarations
class rScheduler;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class rScheduler : public cResource
{
public:
    class MyDTI;
    struct HEADER;
    struct TRACK;
    struct KEY;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct TRACK
    {
    public:
        enum TYPE
        {
            TYPE_UNKNOWN = 0,
            TYPE_ROOT = 1,
            TYPE_UNIT = 2,
            TYPE_SYSTEM = 3,
            TYPE_SCHEDULER = 4,
            TYPE_OBJECT = 5,
            TYPE_INT = 6,
            TYPE_INT64 = 7,
            TYPE_VECTOR = 8,
            TYPE_FLOAT = 9,
            TYPE_FLOAT64 = 10,
            TYPE_BOOL = 11,
            TYPE_REF = 12,
            TYPE_RESOURCE = 13,
            TYPE_STRING = 14,
            TYPE_EVENT = 15,
            TYPE_MATRIX = 16,
        };
    public:
        u32 track_type : 8;  // offset: 0x0
        u32 prop_type : 8;  // offset: 0x0
        u32 key_num : 16;  // offset: 0x0
        union
        {
        public:
            u32 parent_index;  // offset: 0x0
            s32 move_line;  // offset: 0x0
        };  // offset: 0x4
        union
        {
        public:
            MT_CTSTR prop_name;  // offset: 0x0
            MT_CTSTR track_name;  // offset: 0x0
        };  // offset: 0x8
        union
        {
        public:
            u32 prop_index;  // offset: 0x0
            u32 dti_id;  // offset: 0x0
            const MtDTI* pdti;  // offset: 0x0
        };  // offset: 0x10
        u64 unit_group;  // offset: 0x18
        rScheduler::KEY* key_frame;  // offset: 0x20
        u8* key_value;  // offset: 0x28
    };
public:
    struct KEY
    {
    public:
        enum MODE
        {
            MODE_CONSTANT = 0,
            MODE_OFFSET = 1,
            MODE_TRIGGER = 2,
            MODE_LINEAR = 3,
            MODE_OFFSET_F = 4,
            MODE_HERMITE = 5,
        };
    public:
        u32 frame : 24;  // offset: 0x0
        u32 mode : 8;  // offset: 0x0
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 track_num;  // offset: 0x6
        u32 crc;  // offset: 0x8
        u32 frame_max : 24;  // offset: 0xc
        u32 floor_frame : 1;  // offset: 0xc
        u32 reserved : 7;  // offset: 0xc
        u32 base_track;  // offset: 0x10
        u8* meta_data;  // offset: 0x18
        rScheduler::TRACK track[1];  // offset: 0x20
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
    rScheduler();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getTrackNum() const;  // vtable slot 16
    virtual u32 getFrameMax() const;  // vtable slot 17
    TRACK* getBaseTrack() const;
    TRACK* getTracks() const;
    virtual bool isFloorFrame() const;  // vtable slot 18
protected:
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual ~rScheduler();
    void* memAlloc(u32 size);
    void memFree(void* p_addr);
protected:
    HEADER* mpHeader;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u16 DATA_VERSION = 22;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK10rScheduler5MyDTI11newInstanceEv at 0x011deca0-0x011deccd, code DWARF attributes to no inlined copy
inline rScheduler::rScheduler() {
    this->::cResource::mAttr = static_cast<u32>(16);
    this->mpHeader = static_cast<rScheduler::HEADER*>(nullptr);
}
