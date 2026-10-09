#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCipher.h"
#include "MtDTI.h"
#include "MtStream.h"
#include "cResource.h"
#include "zlib.h"

// Forward declarations
class MtAllocator;
class MtCipher;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
struct z_stream_s;

// Declarations
class rArchive;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;
using z_stream = z_stream_s;

class rArchive : public cResource
{
public:
    enum QUALITY
    {
        QUALITY_LOWEST = 0,
        QUALITY_LOW = 1,
        QUALITY_DEFAULT = 2,
        QUALITY_HIGH = 3,
        QUALITY_HIGHEST = 4,
    };
public:
    class MyDTI;
    struct ARCHIVE_HDR;
    class DecompressStream;
    class CipherStream;
    struct RESOURCE_INFO;
public:
    typedef struct
    {
    public:
        u8 key[56];  // offset: 0x0
    } CIPHER_KEY;
public:
    using PATH_FILTER = bool(MtObject::*)(MT_CTSTR, const MtDTI&, MT_CTSTR);
    using cipher_cb = bool(*)(rArchive::CIPHER_KEY&, rArchive*);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct ARCHIVE_HDR
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 resource_num;  // offset: 0x6
    };
public:
    class DecompressStream : public MtStream
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
        DecompressStream(MtStream* pin, rArchive* parc);
        virtual ~DecompressStream();
        void open(u32 offset, u32 datasize, u32 orgsize);
        virtual bool isReadable();  // vtable slot 6
        virtual u32 read(void* pbuf, u32 bufsize);  // vtable slot 13
        virtual u32 getPosition();  // vtable slot 10
        virtual u32 getLength();  // vtable slot 19
        virtual void close();  // vtable slot 11
    protected:
        MtStream* mpIn;  // offset: 0x8
        rArchive* mpArc;  // offset: 0x10
        u32 mCurOut;  // offset: 0x18
        u32 mCurIn;  // offset: 0x1c
        u32 mCurRead;  // offset: 0x20
        u32 mDataSize;  // offset: 0x24
        u32 mOrgSize;  // offset: 0x28
        void* mpInBuf[2];  // offset: 0x30
        u32 mInBufsize[2];  // offset: 0x40
        u32 mMaxLength;  // offset: 0x48
        u32 mWbFlag;  // offset: 0x4c
        u32 mInOffset;  // offset: 0x50
        z_stream mZStream;  // offset: 0x58
    public:
        static MyDTI DTI;
        static const s32 MAX_INBUF = 131072;
    };
public:
    class CipherStream : public MtStream
    {
    public:
        CipherStream(MtStream& st, rArchive::CIPHER_KEY& k);
        virtual ~CipherStream();
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
        virtual u32 write(const void* buf, u32 bufsiz);  // vtable slot 17
        virtual void setLength(u32 len);  // vtable slot 18
        virtual u32 getLength();  // vtable slot 19
        virtual u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin);  // vtable slot 20
        virtual void skip(u32 size);  // vtable slot 21
    private:
        MtCipher mCi;  // offset: 0x8
        MtStream* mpSt;  // offset: 0x1d70
    };
public:
    struct RESOURCE_INFO
    {
    public:
        MT_CHAR path[64];  // offset: 0x0
        u32 type;  // offset: 0x40
        u32 datasize;  // offset: 0x44
        u32 orgsize : 29;  // offset: 0x48
        u32 quality : 3;  // offset: 0x48
        u32 offset;  // offset: 0x4c
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
    rArchive();
    virtual bool load(MtStream& in);  // vtable slot 11
    bool streamgLoad(MtStream& in);
    virtual void clear();  // vtable slot 15
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getResourceNum();
    cResource* getResource(u32 index);
    u32 getTotalSize();
    u32 getCurrentSize();
    f32 getElapsedTime();
    static void setPathFilter(MtObject*, PATH_FILTER);
    static bool invokePathFilter(MT_CTSTR arcPath, const MtDTI& resDTI, MT_CTSTR resPath);
    static u32 getLZXWindowSize();
    static void setLZXWindowSize(u32);
    static u32 getLZXCompressionPartitionSize();
    static void setLZXCompressionPartitionSize(u32);
protected:
    virtual ~rArchive();
    void setResource(cResource*, u32);
    void setResourceNum(u32);
    void setResourceTotalSize(u32);
    u32 getResourceTotalSize();
public:
    static void* setCipherKey_cb(cipher_cb cb);
    bool isCrypted();
protected:
    ARCHIVE_HDR mStreamUseHdr;  // offset: 0x70
    cResource* * mpResource;  // offset: 0x78
    u32 mResourceNum;  // offset: 0x80
    u32 mTotalSize;  // offset: 0x84
    u32 mCurrentSize;  // offset: 0x88
    f32 mElapsedTime;  // offset: 0x8c
    u32 mbCrypted;  // offset: 0x90
public:
    static MyDTI DTI;
protected:
    static const s32 DATA_VERSION = 7;
    static MtObject* mpPathFilterOwner;
    static PATH_FILTER mpPathFilter;
    static cipher_cb mpGetCipherKey;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK8rArchive5MyDTI11newInstanceEv at 0x011c0d20-0x011c0d6d, code DWARF attributes to no inlined copy
inline rArchive::rArchive() {
    this->::cResource::mAttr = static_cast<u32>(16);
    this->mbCrypted = static_cast<u32>(0);
    this->mCurrentSize = static_cast<u32>(0);
    this->mElapsedTime = 0.0f;
    this->mResourceNum = static_cast<u32>(0);
    this->mTotalSize = static_cast<u32>(0);
    this->mpResource = static_cast<cResource* *>(nullptr);
}
