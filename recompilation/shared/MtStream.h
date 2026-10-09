#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtFile;
class MtObject;

// Declarations
class MtFileStream;
class MtMemoryStream;
class MtStream;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class MtStream : public MtObject
{
public:
    enum SEEK_ORIGIN
    {
        ORG_BEGIN = 0,
        ORG_CURRENT = 1,
        ORG_END = 2,
    };
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
    MtStream();
    // Address: 0x01b4ee90 - 0x01b4ee91 (1 bytes)
    virtual ~MtStream() {}
    virtual bool isReadable();  // vtable slot 6
    virtual bool isWritable();  // vtable slot 7
    virtual bool isSeekable();  // vtable slot 8
    virtual bool isAsyncReadable();  // vtable slot 9
    virtual u32 getPosition();  // vtable slot 10
    // Address: 0x01b4ef20 - 0x01b4ef21 (1 bytes)
    virtual void close() {}  // vtable slot 11
    // Address: 0x01b4ef30 - 0x01b4ef31 (1 bytes)
    virtual void flush() {}  // vtable slot 12
    virtual u32 read(void*, u32);  // vtable slot 13
    virtual u32 readAsync(void* buf, u32 bufsize);  // vtable slot 14
    // Address: 0x01a60ac0 - 0x01a60ac1 (1 bytes)
    virtual void readWait() {}  // vtable slot 15
    virtual bool isAsyncReading() const;  // vtable slot 16
    virtual u32 write(const void*, u32);  // vtable slot 17
    // Address: 0x01b4ef70 - 0x01b4ef71 (1 bytes)
    virtual void setLength(u32) {}  // vtable slot 18
    virtual u32 getLength();  // vtable slot 19
    virtual u32 seek(s32, SEEK_ORIGIN);  // vtable slot 20
    virtual void skip(u32 size);  // vtable slot 21
    virtual bool isAsyncOperationSucceeded() const;  // vtable slot 22
public:
    static MyDTI DTI;
};

class MtFileStream : public MtStream
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
    MtFileStream();
    MtFileStream(MtFile& file);
    virtual ~MtFileStream();
    virtual void open(MtFile& file);  // vtable slot 23
    virtual bool isReadable();  // vtable slot 6
    virtual bool isWritable();  // vtable slot 7
    virtual bool isSeekable();  // vtable slot 8
    virtual bool isAsyncReadable();  // vtable slot 9
    virtual u32 getPosition();  // vtable slot 10
    virtual void close();  // vtable slot 11
    virtual void flush();  // vtable slot 12
    virtual u32 read(void* buf, u32 bufsiz);  // vtable slot 13
    virtual u32 readAsync(void* buf, u32 bufsize);  // vtable slot 14
    virtual void readWait();  // vtable slot 15
    virtual bool isAsyncReading() const;  // vtable slot 16
    virtual u32 write(const void* buf, u32 bufsiz);  // vtable slot 17
    virtual void setLength(u32);  // vtable slot 18
    virtual u32 getLength();  // vtable slot 19
    virtual u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin);  // vtable slot 20
    MT_CTSTR getPath();
    static bool copy(MT_CTSTR src, MT_CTSTR dst);
protected:
    MtFile* mpFile;  // offset: 0x8
public:
    static MyDTI DTI;
};

class MtMemoryStream : public MtStream
{
public:
    enum MODE
    {
        MODE_READ = 1,
        MODE_WRITE = 2,
        MODE_EXPAND = 4,
    };
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
    MtMemoryStream(u32 bufsiz, u32 mode, MtAllocator* pallocator);
    MtMemoryStream(void* pbuf, u32 bufsiz, u32 mode);
    virtual ~MtMemoryStream();
    virtual bool isReadable();  // vtable slot 6
    virtual bool isWritable();  // vtable slot 7
    virtual bool isSeekable();  // vtable slot 8
    virtual u32 getPosition();  // vtable slot 10
    virtual void close();  // vtable slot 11
    virtual void flush();  // vtable slot 12
    virtual u32 read(void* ptr, u32 bytes);  // vtable slot 13
    virtual u32 readAsync(void* ptr, u32 bytes);  // vtable slot 14
    virtual u32 write(const void* ptr, u32 bytes);  // vtable slot 17
    virtual void setLength(u32 length);  // vtable slot 18
    virtual u32 getLength();  // vtable slot 19
    virtual void* getBuffer();  // vtable slot 23
    virtual u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin);  // vtable slot 20
    virtual bool isBufferOverflowed() const;  // vtable slot 24
private:
    void extendBuffer(u32 bytes);
private:
    u8* mBuffer;  // offset: 0x8
    u32 mSeekPt;  // offset: 0x10
    u32 mLength;  // offset: 0x14
    u32 mMode;  // offset: 0x18
    u32 mBufferOverflow : 1;  // offset: 0x1c
    MtAllocator* mpAllocator;  // offset: 0x20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline MtStream::MtStream() {
}
