#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "MtTime.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtTime;
class MtUI;
struct _SceKernelSema;
struct pthread;

// Declarations
class MtFile;

// Type aliases from DWARF
using DIRECTORY_HANDLE = int;
using FILE_HANDLE = int;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using SceKernelSema = _SceKernelSema*;
using pthread_t = pthread*;
using ScePthread = pthread_t;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class MtFile : public MtObject
{
public:
    enum MODE
    {
        MODE_UNDEFINED = 16,
        MODE_READ = 17,
        MODE_READ_ASYNC = 18,
        MODE_WRITE = 19,
        MODE_WRITE_APPEND = 20,
        MODE_READ_WRITE = 21,
        MODE_READ_WRITE_APPEND = 22,
    };
    enum DRIVETYPE
    {
        DRIVETYPE_APP = 0,
        DRIVETYPE_SAVEDATA = 1,
        DRIVETYPE_ADDCONT = 2,
        DRIVETYPE_APPHOME = 3,
        DRIVETYPE_SD = 4,
        DRIVETYPE_UX = 5,
        DRIVETYPE_USB = 6,
        DRIVETYPE_DEVELOP = 7,
        DRIVETYPE_LAUNCH = 8,
        DRIVETYPE_TEMP = 9,
        DRIVETYPE_DOWNLOAD = 10,
        DRIVETYPE_ABS = 11,
        DRIVETYPE_AVCONTENTS = 12,
        DRIVETYPE_HOME = 13,
    };
    enum SEEKBASE
    {
        SEEKBASE_SET = 1,
        SEEKBASE_CUR = 2,
        SEEKBASE_END = 3,
    };
    enum TIME
    {
        TIME_CREATION = 0,
        TIME_LAST_ACESS = 1,
        TIME_LAST_WRITE = 2,
    };
public:
    class MyDTI;
    class AsyncThreadPool;
    class FileInfo;
    class RealPath;
public:
    using FileError = s32;
    using PATH_DRIVETYPE_FUNC = void(*)(MT_CTSTR, MtFile::DRIVETYPE&, u32&, MT_STR);
    using DLC_HANDLE = u32;
    using DLC_ISEXIST_FUNC = bool(*)(MT_CTSTR);
    using DLC_OPEN_FUNC = MtFile::DLC_HANDLE(*)(MT_CTSTR);
    using DLC_GET_SIZE_FUNC = u32(*)(MtFile::DLC_HANDLE);
    using DLC_READ_FUNC = u32(*)(MtFile::DLC_HANDLE, void*, u32);
    using DLC_SEEK_FUNC = u32(*)(MtFile::DLC_HANDLE, u32, MtFile::SEEKBASE);
    using DLC_CLOSE_FUNC = void(*)(MtFile::DLC_HANDLE);
    using DLC_READASYNC_FUNC = u32(*)(MtFile::DLC_HANDLE, void*, u32);
    using DLC_READWAIT_FUNC = u32(*)(MtFile::DLC_HANDLE);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class AsyncThreadPool
    {
    public:
        enum
        {
            PoolNum = 3,
        };
    public:
        struct Context;
    public:
        struct Context
        {
        public:
            ScePthread mThreadHandle;  // offset: 0x0
            SceKernelSema mWaitHandle;  // offset: 0x8
            SceKernelSema mDoneHandle;  // offset: 0x10
            MtFile* mpFile;  // offset: 0x18
            bool mbUsed;  // offset: 0x20
            bool mbExit;  // offset: 0x21
        };
    public:
        AsyncThreadPool();
        ~AsyncThreadPool();
        s32 requestReadAsync(MtFile* pfile);
        void waitReadAsync(s32 handle);
    private:
        static void* readAsyncProc(void* pArg);
    private:
        Context mContext[3];  // offset: 0x0
        MtCriticalSection mCS;  // offset: 0x78
    };
public:
    class FileInfo : public MtObject
    {
    public:
        enum ATTR
        {
            ATTR_DIRECTORY = 1,
            ATTR_ARCHIVABLE = 2,
            ATTR_HIDDEN = 4,
            ATTR_NORMAL = 8,
            ATTR_READONLY = 16,
            ATTR_SYSTEM = 32,
        };
    public:
        class MyDTI;
    public:
        using FileError = s32;
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
        FileInfo();
        virtual ~FileInfo();
        void close();
        bool isDirectory() const;
        bool isReadonly() const;
        MT_CTSTR getName() const;
        MT_CTSTR getFileType() const;
        MtTime getCreation() const;
        MtTime getLastAccess() const;
        MtTime getLastWrite() const;
        void setFileType(MT_CTSTR);
        u32 getAttr() const;
        u64 getSize() const;
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        const MtFile::FileInfo& operator=(const MtFile::FileInfo& lhs);
        FileError getLastErrorCode() const;
        void setLastErrorCode(FileError error);
    protected:
        u64 mSize;  // offset: 0x8
        MtString mName;  // offset: 0x10
        MtString mType;  // offset: 0x18
        u32 mAttr;  // offset: 0x20
        MtTime mCreation;  // offset: 0x28
        MtTime mLastAccess;  // offset: 0x30
        MtTime mLastWrite;  // offset: 0x38
        DIRECTORY_HANDLE mFindHandle;  // offset: 0x40
        FileError mLastErrorCode;  // offset: 0x44
        char* mpFindBuffer;  // offset: 0x48
        u32 mStatBlockSize;  // offset: 0x50
        u32 mFindReadSize;  // offset: 0x54
        u32 mFindReadPos;  // offset: 0x58
        MT_CHAR mFindPath[1024];  // offset: 0x5c
        MT_CHAR mFindName[1024];  // offset: 0x45c
    public:
        static MyDTI DTI;
    };
public:
    class RealPath
    {
    public:
        RealPath(MT_CTSTR path);
        ~RealPath();
        MT_CTSTR getPath();
        operator const char *() const;
        bool isEnablePath() const;
    private:
        MT_CHAR mPath[1024];  // offset: 0x0
        bool mNullPath;  // offset: 0x400
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
    static bool findFile(FileInfo& info, MT_CTSTR start);
    static bool createDirectory(MT_CTSTR path);
    static bool createDirectoryEx(MT_CTSTR dpath);
    static bool removeDirectory(MT_CTSTR path);
    static bool removeDirectoryEx(MT_CTSTR path);
    static bool move(MT_CTSTR srcpath, MT_CTSTR dstpath);
    static bool copy(MT_CTSTR src, MT_CTSTR dst);
    static bool remove(MT_CTSTR path);
    static bool rename(MT_CTSTR srcpath, MT_CTSTR dstpath);
    static bool isReadonly(MT_CTSTR path);
    static bool isExist(MT_CTSTR path);
    static MT_CTSTR getCurrentPath();
    static void setCurrentPath(MT_CTSTR path);
    static MT_CTSTR getCachePath();
    static void setCachePath(MT_CTSTR path);
    static bool setTime(MT_CTSTR path, u32 mode, MtTime time);
    static u32 getCRC(MT_CTSTR path);
    MtFile(MT_CTSTR path, MODE mode);
    virtual ~MtFile();
    virtual bool open(MT_CTSTR path, MODE mode, bool interrupt);  // vtable slot 6
    bool open(MODE);
    virtual void close();  // vtable slot 7
    virtual u32 read(void* out, u32 bytes);  // vtable slot 8
    virtual u32 readAsync(void* out, u32 bytes);  // vtable slot 9
    virtual void readWait();  // vtable slot 10
    virtual bool isAsyncReading() const;  // vtable slot 11
    virtual u32 write(const void* in, u32 bytes);  // vtable slot 12
    virtual u32 seek(s32 offset, SEEKBASE base);  // vtable slot 13
    virtual u32 getPosition();  // vtable slot 14
    virtual u32 length();  // vtable slot 15
    virtual void setLength(u32 len);  // vtable slot 16
    virtual bool isReadable();  // vtable slot 17
    virtual bool isWritable();  // vtable slot 18
    virtual bool isAsyncReadable();  // vtable slot 19
    MtTime getTime(TIME mode);
    bool setTime(TIME mode, MtTime time);
    MT_CTSTR getPath();
    void setPath(MT_CTSTR szPath);
    static u32 getDriveType(MT_CTSTR path);
    static void getDriveType(MT_CTSTR path, DRIVETYPE& dst_dtype, u32& dst_prefixoffset, MT_STR dest_nativemountprefix);
    static void setDriveTypeFunction(PATH_DRIVETYPE_FUNC pFunc);
    FileError getLastErrorCode() const;
    static FileError getLastError();
    void setLastErrorCode(FileError error);
    static void setLastError(FileError error);
protected:
    static bool checkAcceptableName(MT_CTSTR filename, MT_CTSTR findName);
    bool startReadAsync();
    virtual u32 getAsyncTransferredSize() const;  // vtable slot 20
    virtual bool isReadableMode(MODE mode);  // vtable slot 21
    virtual bool isWritableMode(MODE mode);  // vtable slot 22
    virtual bool isAsyncReadableMode(MODE mode);  // vtable slot 23
public:
    static void setDLCisExistFunction(DLC_ISEXIST_FUNC);
    static void setDLCopenFunction(DLC_OPEN_FUNC);
    static void setDLCgetSizeFunction(DLC_GET_SIZE_FUNC);
    static void setDLCreadFunction(DLC_READ_FUNC);
    static void setDLCseekFunction(DLC_SEEK_FUNC);
    static void setDLCcloseFunction(DLC_CLOSE_FUNC);
    static void setDLCreadAsyncFunction(DLC_READASYNC_FUNC);
    static void setDLCreadWaitFunction(DLC_READWAIT_FUNC);
private:
    bool isOpenedAsDLC() const;
private:
    FILE_HANDLE mHandle;  // offset: 0x8
    MODE mMode;  // offset: 0xc
    u32 mSize;  // offset: 0x10
    u32 mSeekPt;  // offset: 0x14
    MT_CHAR mPath[1024];  // offset: 0x18
    s32 mAsyncContextHandle;  // offset: 0x418
    void* mAsyncDist;  // offset: 0x420
    u32 mAsyncRequestedSize;  // offset: 0x428
    u32 mAsyncTransferredSize;  // offset: 0x42c
    u32 mAsyncSeekPt;  // offset: 0x430
    bool mAsyncExec;  // offset: 0x434
    u32 mAsyncThreadInfoIndex;  // offset: 0x438
    u32 mOwnerThread;  // offset: 0x43c
    FileError mLastErrorCode;  // offset: 0x440
    DLC_HANDLE mDLCHandle;  // offset: 0x444
public:
    static MyDTI DTI;
    static const s32 MAX_SECTORSIZE = 2048;
    static const s32 READ_ASYNC_STACK_SIZE = 65536;
    static const s32 COPY_BUFSIZE = 65536;
private:
    static MT_CHAR mCurrentPath[1024];
    static FileError mLastError;
    static MT_CHAR mCachePath[1024];
    static PATH_DRIVETYPE_FUNC mpPathDriveTypeFunc;
public:
    static const DLC_HANDLE INVALID_DLC_HANDLE = 4294967295;
    static DLC_ISEXIST_FUNC mpDLCisExistFunc;
    static DLC_OPEN_FUNC mpDLCopenFunc;
    static DLC_GET_SIZE_FUNC mpDLCgetSizeFunc;
    static DLC_READ_FUNC mpDLCreadFunc;
    static DLC_SEEK_FUNC mpDLCseekFunc;
    static DLC_CLOSE_FUNC mpDLCcloseFunc;
    static DLC_READASYNC_FUNC mpDLCreadAsyncFunc;
    static DLC_READWAIT_FUNC mpDLCreadWaitFunc;
private:
    static AsyncThreadPool mAsyncThreadPool;
};
