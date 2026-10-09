#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
namespace MtMemoryAllocator { class MemoryCfg; }
namespace MtMemoryAllocator { class Initializer; }
namespace MtMemoryAllocator { class AllocatorFactory; }

namespace MtMemoryAllocator {
    enum AllocatorType
    {
        DEFAULT = 0,
        GLOBAL = 1,
        STRING = 2,
        ARRAY = 3,
        COLLISION = 4,
        ONION = 5,
        GARLIC = 6,
        TEMPORARY = 7,
        DEVELOP = 8,
        UI = 9,
        COLLADA = 10,
        UNDEFINED = 11,
        USER_ALLOCATOR = 12,
        MAX_ALLOCATOR = 64,
        UNKNOWN_ALLOCATOR = 2147483647,
    };
}  // namespace MtMemoryAllocator

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace MtMemoryAllocator {

    // Forward declarations
    class MemoryCfg;
    class Initializer;
    class AllocatorFactory;

    class Initializer
    {
    public:
        struct Entry;
    public:
        struct Entry
        {
        public:
            Entry(MT_CTSTR name, u32 id);
            Entry(u32 length, u32 id);
            ~Entry();
            static void* operator new(size_t size);
            static void operator delete(void* p_addr);
        public:
            MT_STR obj_name;  // offset: 0x0
            size_t len;  // offset: 0x8
            u32 alloc_id;  // offset: 0x10
        };
    public:
        Initializer(u32 max_entry);
        virtual ~Initializer();
        virtual s32 createAllocatorInfo(u32 length, u32 alloc_id);  // vtable slot 2
        virtual s32 addAllocatorInfo(MT_CTSTR name, u32 alloc_id);  // vtable slot 3
        virtual u32 getAllocatorID(MT_CTSTR obj_name) const;  // vtable slot 4
        u32 getNumOfEntry() const;
        const Entry* operator[](u32 idx) const;
        static void* operator new(size_t size);
        static void operator delete(void* p_addr);
    protected:
        u32 mMaxEntryNum;  // offset: 0x8
        u32 mEntryNum;  // offset: 0xc
        Entry* * mAllocIdTable;  // offset: 0x10
    };

    class AllocatorFactory
    {
    public:
        AllocatorFactory();
        virtual ~AllocatorFactory() {}
        virtual MtAllocator* createFromString(MT_CTSTR str, void* p_work);  // vtable slot 2
    private:
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void operator delete(void*);
        static void operator delete[](void*);
        u32 getArgument(MT_STR* str, const u8* * i_str);
        size_t calcSize(MT_CTSTR sz);
        u16 calcAttr(MT_CTSTR attrib);
        u16 calcSclAllocAttr(MT_CTSTR attrib);
    private:
        void* mpWorkBuffer;  // offset: 0x8
    };

    class MemoryCfg
    {
    public:
        enum STATE
        {
            ST_ERR_CRITICAL = -8,
            ST_ERR_NO_ATTRIBUTE = -7,
            ST_ERR_TOO_MANY_SECTION = -6,
            ST_ERR_INVALID_STATE = -5,
            ST_ERR_EOF = -4,
            ST_ERR_EMPTY_SECTION = -3,
            ST_ERR_TOKEN = -2,
            ST_ERR_UNRECOGNIZED = -1,
            ST_UNKNOWN = 0,
            ST_COMMENT = 1,
            ST_SECTION = 2,
            ST_SECTION_END = 3,
            ST_INDEX = 4,
            ST_INDEX_ATTRIBUTE_BEGIN = 5,
            ST_INDEX_ATTRIBUTE = 6,
            ST_INDEX_ATTRIBUTE_END = 7,
            ST_ALLOCATOR = 8,
            ST_ALLOCATOR_ATTRIBUTE_BEGIN = 9,
            ST_ALLOCATOR_ATTRIBUTE = 10,
            ST_ALLOCATOR_ATTRIBUTE_END = 11,
            ST_LINE_BREAK = 12,
            ST_END = 13,
            ST_OK = 2147483647,
        };
        enum ERR_CODE
        {
            ERR_NONE = 0,
            ERR_UNRECOGNIZED = 1,
            ERR_TOKEN = 2,
            ERR_EMPTY_SECTION = 3,
            ERR_EOF = 4,
            ERR_INVALID_STATE = 5,
            ERR_TOO_MANY_SECTION = 6,
            ERR_NO_ATTRIBUTE = 7,
            ERR_CRITICAL = 8,
        };
    public:
        struct SectionAttrib;
    public:
        struct SectionAttrib
        {
        public:
            MT_CHAR platform[16];  // offset: 0x0
            MT_CHAR build_variant[32];  // offset: 0x10
            u32 line;  // offset: 0x30
            const void* p_section;  // offset: 0x38
        };
    public:
        MemoryCfg(u32 max_attr, u32 max_entry, u32 work_sz);
        ~MemoryCfg();
        static void* operator new(size_t size);
        static void operator delete(void* p_addr);
        s32 initConfiguration(const void* p_cfg, u32 sz, MT_CTSTR platform, MT_CTSTR build_variant, MtMemoryAllocator::AllocatorFactory alloc_factory);
        MT_CTSTR getErrorStr(s32);
        u32 getLineErr() const;
        const MtMemoryAllocator::Initializer& getInitializer() const;
    private:
        STATE parseUnknown(const u8* * p_io, u32* sz);
        STATE parseComment(const u8* * p_io, u32* sz);
        STATE parseSection(const u8* * p_io, u32* sz);
        STATE parseSectionEnd(const u8* * p_io, u32* sz);
        STATE parseIndex(const u8* * p_io, u32* sz);
        STATE parseIndexAttribBegin(const u8* * p_io, u32* sz);
        STATE parseIndexAttrib(const u8* * p_io, u32* sz, bool skip_parser);
        STATE parseAllocator(const u8* * p_io, u32* sz);
        STATE parseAllocatorAttribBegin(const u8* * p_io, u32* sz);
        STATE parseAllocatorAttrib(const u8* * p_io, u32* sz, bool skip_parser, MtMemoryAllocator::AllocatorFactory& alloc_factory);
        STATE interpretIndexSection(const u8* p_sec);
        STATE interpretAllocatorSection(const u8* p_sec);
        STATE interpretIndexAttrib(const u8* p_attr);
        STATE interpretAllocatorAttrib(const u8* p_attr, MtMemoryAllocator::AllocatorFactory& alloc_factory);
        SectionAttrib* chooseAppropriateIndex() const;
        SectionAttrib* chooseAppropriateAllocator() const;
    private:
        SectionAttrib* mpIndexAttrib;  // offset: 0x0
        u32 mIndexAttribNum;  // offset: 0x8
        SectionAttrib* mpAllocAttrib;  // offset: 0x10
        u32 mAllocAttribNum;  // offset: 0x18
        SectionAttrib* mpCurrentAttrib;  // offset: 0x20
        u32 mMaxAttribNum;  // offset: 0x28
        void* mpWorkBuffer;  // offset: 0x30
        u32 mWorkBufferSize;  // offset: 0x38
        void* mpCurrentWorkBuffer;  // offset: 0x40
        MT_CTSTR mPlatform;  // offset: 0x48
        MT_CTSTR mBuildVariant;  // offset: 0x50
        MtMemoryAllocator::Initializer mInitializer;  // offset: 0x58
    };

    MtAllocator* getAllocator(const MtDTI& dti);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\capdev200\MT/MtMemoryAllocator.cpp:225
    void setAllocator(MtDTI& dti, u32 idx);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\capdev200\MT/MtMemoryAllocator.cpp:231
    void setMtMemoryAllocator(const Initializer& init);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\capdev200\MT/MtMemoryAllocator.cpp:238
    MT_CTSTR getAllocatorTypeStr(u32 id);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\capdev200\MT/MtMemoryAllocator.cpp:326
    void registerAllocatorType(u32 id, MT_CTSTR name);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\capdev200\MT/MtMemoryAllocator.cpp:332
    u32 getAvailableAllocatorType();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\capdev200\MT/MtMemoryAllocator.cpp:338
    void setAvailableAllocatorType(u32 num);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\capdev200\MT/MtMemoryAllocator.cpp:344
    void checkBrokenMemory();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/DDOAllocator.cpp:117
    void setDefaultAppAllocator();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/DDOAllocator.cpp:138
    void initializeMemConfig();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/DDOAllocator.cpp:1481
    void allocateDefaultMemory();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/DDOAllocator.cpp:1582

}  // namespace MtMemoryAllocator
