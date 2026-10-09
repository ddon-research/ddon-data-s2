#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtStream.h"
#include "../shared/rSoundSource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;

// Declarations
class rSoundStreamSourcePackage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundStreamSourcePackage : public rSoundSource
{
public:
    class MyDTI;
    class PackageFile;
    struct HEADER;
    struct OFFSET_TABLE;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class PackageFile : public rSoundSource::SoundFile
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
        PackageFile();
        virtual ~PackageFile();
        virtual u32 getLength();  // vtable slot 19
        virtual u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin);  // vtable slot 20
        void setSourceInfo(u32 length, u32 offset);
        void clearSourceInfo();
    private:
        u32 mLength;  // offset: 0x458
        u32 mOffset;  // offset: 0x45c
    public:
        static MyDTI DTI;
    };
public:
    struct HEADER
    {
    public:
        u32 tag;  // offset: 0x0
        u32 ver;  // offset: 0x4
        u32 sourceNum;  // offset: 0x8
        u32 padding;  // offset: 0xc
    };
public:
    struct OFFSET_TABLE
    {
    public:
        u32 filePathOffset;  // offset: 0x0
        u32 sourceOffset;  // offset: 0x4
        u32 filePathLength;  // offset: 0x8
        u32 sourceLength;  // offset: 0xc
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
    rSoundStreamSourcePackage();
    virtual ~rSoundStreamSourcePackage();
    virtual bool load(MtStream& in);  // vtable slot 11
    bool open();
    u32 read(void* pdest, u32 size, u32* pid, u32 sourceOffset);
    rSoundSource* setSourceParamFromPackage(u32 index, rSoundSource* pSource);
    virtual MT_CTSTR getExt() const;  // vtable slot 7
public:
    static MyDTI DTI;
private:
    static const s32 NativeFileMagic = 1380995923;
    static const s32 NativeFileVersion = 1;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK25rSoundStreamSourcePackage5MyDTI11newInstanceEv at 0x012f7f70-0x012f7f8e, code DWARF attributes to no inlined copy
inline rSoundStreamSourcePackage::rSoundStreamSourcePackage() {
}
