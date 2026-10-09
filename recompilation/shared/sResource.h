#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtProperty.h"
#include "MtStream.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "cResource.h"
#include "cSystem.h"
#include "zlib.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSemaphore;
class MtStream;
class MtString;
class MtUI;
class cResource;
namespace nWin32Detour { class eventFlag; }
struct pthread;
class rArchive;
class rCollision;
class rNavigationMesh;
class uSky;
struct z_stream_s;

// Declarations
class sResource;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using RESOURCE_PATH_FILTER = void(*)(MT_STR, void*);
using pthread_t = pthread*;
using ScePthread = pthread_t;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
using z_stream = z_stream_s;

class sResource : public cSystem
{
    // inferred: cResource::addRef names sResource::mpInstance
    friend class cResource;
    // inferred: rCollision::load names sResource::mpInstance
    friend class rCollision;
    // inferred: rNavigationMesh::load names sResource::mpInstance
    friend class rNavigationMesh;
    // inferred: uSky::setup names sResource::mpInstance
    friend class uSky;
public:
    enum MODE
    {
        MODE_BLOCKING = 1,
        MODE_ASYNC = 2,
        MODE_USECACHE = 4,
        MODE_USEGDATA = 8,
        MODE_BACKGROUND = 32,
        MODE_CREATE = 64,
        MODE_NOLOAD = 128,
        MODE_STREAM = 256,
        MODE_PRELOAD = 512,
        MODE_QUALITY_LOWEST = 4096,
        MODE_QUALITY_LOW = 8192,
        MODE_QUALITY_HIGH = 16384,
        MODE_QUALITY_HIGHEST = 32768,
    };
public:
    class MyDTI;
    class TypeInfo;
    class Property;
    struct LOADING_INFO;
    class RemoteInfo;
    struct DECODEWORK;
    struct RESOURCEWORK;
    class Iterator;
    struct ResourceInfo;
    class DecompressStream;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class TypeInfo : public MtObject
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
        TypeInfo();
        virtual ~TypeInfo();
        void setDTI(const MtDTI* pdti);
        const MtDTI* getDTI();
        bool isCreatable() const;
        bool isNative() const;
        bool isIntermediate() const;
        bool isSaveable() const;
        bool isXmlNode() const;
        bool isTemp() const;
        MT_CTSTR getExt() const;
        MT_CTSTR getName() const;
        MT_CTSTR getSuper() const;
        u32 getSize() const;
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        u32 getAttribute() const;
    private:
        void setSize(u32);
        void setName(MT_CTSTR);
        void setSuper(MT_CTSTR);
    private:
        u32 mAttr;  // offset: 0x8
        MT_CTSTR mExt;  // offset: 0x10
        const MtDTI* mpDTI;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    class Property : public MtProperty::Custom
    {
    public:
        virtual MT_CTSTR getName();  // vtable slot 2
        virtual u32 getParam(MtProperty* pp, MtProperty::Custom::PARAM* params);  // vtable slot 3
        virtual void setParam(MtProperty* pp, const MtProperty::Custom::PARAM* params, u32 num);  // vtable slot 4
    };
public:
    struct LOADING_INFO
    {
    public:
        MT_CHAR path[64];  // offset: 0x0
        u32 attr;  // offset: 0x40
        volatile bool active;  // offset: 0x44
    };
public:
    class RemoteInfo : public MtObject
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
        RemoteInfo();
        // Address: 0x01ba6da0 - 0x01ba6da1 (1 bytes)
        virtual ~RemoteInfo() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        MT_CTSTR getConfigName() const;
        void setConfigName(MT_CTSTR cfg_name);
        MT_CTSTR getPCName() const;
        void setPCName(MT_CTSTR pc_name);
        MT_CTSTR getFolderName() const;
        void setFolderName(MT_CTSTR folder_name);
        bool isEnable() const;
        void enable(bool en);
        u32 getConfigNameLen() const;
        u32 getPCNameLen() const;
        u32 getFolderNameLen() const;
    private:
        bool mEnable;  // offset: 0x8
        MT_CHAR mConfigName[64];  // offset: 0x9
        MT_CHAR mPCName[64];  // offset: 0x49
        MT_CHAR mFolderName[64];  // offset: 0x89
        u32 mConfigNameLen;  // offset: 0xcc
        u32 mPCNameLen;  // offset: 0xd0
        u32 mFolderNameLen;  // offset: 0xd4
    public:
        static MyDTI DTI;
    };
public:
    struct RESOURCEWORK
    {
    public:
        cResource* presource;  // offset: 0x0
        u32 offset;  // offset: 0x8
        u32 orgsize;  // offset: 0xc
        u32 datasize;  // offset: 0x10
        u32 readsize;  // offset: 0x14
        u32 complete : 1;  // offset: 0x18
        u32 loaded : 1;  // offset: 0x18
        u32 threadid : 30;  // offset: 0x18
    };
public:
    class Iterator
    {
    public:
        Iterator(s32 start);
        bool hasNext();
        cResource* next();
    private:
        Iterator();
    private:
        s32 mIndex;  // offset: 0x0
    };
public:
    struct ResourceInfo
    {
    public:
        enum FileType
        {
            FT_INTERMEDIATE = 0,
            FT_NATIVE = 1,
            FT_TEMP = 2,
        };
    public:
        MT_CTSTR fullpath;  // offset: 0x0
        MT_CHAR path[1024];  // offset: 0x8
        MT_CTSTR ext;  // offset: 0x408
        u32 type;  // offset: 0x410
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
        DecompressStream(sResource::DECODEWORK* pwk, sResource::RESOURCEWORK* prwk);
        virtual ~DecompressStream();
        virtual bool isReadable();  // vtable slot 6
        virtual u32 read(void* pbuf, u32 bufsize);  // vtable slot 13
        virtual u32 getPosition();  // vtable slot 10
        virtual u32 getLength();  // vtable slot 19
    protected:
        sResource::DECODEWORK* mpDecodeWork;  // offset: 0x8
        sResource::RESOURCEWORK* mpResourceWork;  // offset: 0x10
        u32 mCurOut;  // offset: 0x18
        u32 mOrgSize;  // offset: 0x1c
        z_stream mZStream;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    struct DECODEWORK
    {
    public:
        MtStream* pin;  // offset: 0x0
        MtCriticalSection cs;  // offset: 0x8
        cResource* parc;  // offset: 0x10
        u8* pbuf;  // offset: 0x18
        u32 bufsize;  // offset: 0x20
        u32 readpt;  // offset: 0x24
        u32 writept;  // offset: 0x28
        u32 rnum;  // offset: 0x2c
        u32 rrequest;  // offset: 0x30
        u32 rcomplete;  // offset: 0x34
        u32 cancel;  // offset: 0x38
        u32 datasize;  // offset: 0x3c
        u32 orgsize;  // offset: 0x40
        s64 start_time;  // offset: 0x48
        s64 end_time;  // offset: 0x50
        sResource::RESOURCEWORK rwork[4096];  // offset: 0x58
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
    sResource(u32 ringbufsize);
    virtual ~sResource();
    virtual void reset();  // vtable slot 6
    virtual void setup();  // vtable slot 10
    virtual void move();  // vtable slot 7
    static sResource* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setAutoUpdate(bool);
    bool isAutoUpdate();
    void buildArchive();
    bool isOptimize();
    void setOptimize(bool);
    void terminateAsync();
    virtual cResource* create(MT_CTSTR fullpath, const MtDTI* pbase, u32 mode);  // vtable slot 11
    virtual cResource* create(const MtDTI& dti, MT_CTSTR path, u32 mode);  // vtable slot 12
    virtual cResource* create(MtStream& in, const MtDTI& dti, MT_CTSTR path, cResource::QUALITY quality);  // vtable slot 13
    virtual cResource* create(u64 id);  // vtable slot 14
    cResource* createIntermediate(cResource* psrc, u32 mode);
    cResource* createNative(cResource* psrc, u32 mode);
    bool convert(cResource* psrc, cResource::CONVERT_TYPE type);
    bool isValid(cResource* pr);
    static bool isValidPath(MT_CTSTR path);
    bool isExist(const MtDTI& dti, MT_CTSTR path);
    u64 makeID(const MtDTI& dti, MT_CTSTR path);
    u64 makeID(u32 dtiID, MT_CTSTR path);
    void setupDecode(MtStream& in);
    cResource* entryDecode(MT_CTSTR path, const MtDTI& dti, u32 offset, u32 datasize, u32 orgsize, cResource::QUALITY quality);
    bool executeDecode(rArchive* parc);
    void getFullPath(MT_STR dst, cResource* pr);
    void getFullPath(MT_STR dst, const MtDTI& dti, MT_CTSTR path);
    MT_CTSTR getRootDirectory() const;
    void setRootDirectory(MT_CTSTR root_directory);
    MT_CTSTR getResourcePath() const;
    MT_CTSTR getNativePath() const;
    MT_CTSTR getNativeFolder();
    void setPathFilter(RESOURCE_PATH_FILTER, void*);
    MT_CTSTR getTempDirectory() const;
    void setTempDirectory(MT_CTSTR temp_directory);
    u32 getTypeNum();
    TypeInfo* getTypeFromIndex(u32);
    TypeInfo* getTypeFromDTI(const MtDTI& dti);
    const LOADING_INFO* getLoadingInfo();
    bool isLoading();
    Iterator getIterator();
    static void loadRemote(MT_CTSTR config_filename);
    static void unloadRemote();
    static bool isRemote();
    static MT_CTSTR getRemoteConfigurationName();
    static u32 getRemoteConfigurationNameLen();
    static MT_CTSTR getPCName();
    static u32 getPCNameLen();
    static MT_CTSTR getFolderName();
    static u32 getFolderNameLen();
    u32 getRModelDataReaderBufferSizeByte() const;
    u32 getRModelDataReaderBufferSizeKB() const;
    void setRModelDataReaderBufferSizeKB(u32);
    u32 getRTextureDataReaderBufferSizeByte() const;
    u32 getRTextureDataReaderBufferSizeKB() const;
    void setRTextureDataReaderBufferSizeKB(u32);
    u32 getRCollisionDataReaderBufferSizeByte() const;
    u32 getRCollisionDataReaderBufferSizeKB() const;
    void setRCollisionDataReaderBufferSizeKB(u32);
    u32 getRGrassDataReaderBufferSizeByte() const;
    u32 getRGrassDataReaderBufferSizeKB() const;
    void setRGrassDataReaderBufferSizeKB(u32);
    u32 getRNavigationMeshDataReaderBufferSizeByte() const;
    u32 getRNavigationMeshDataReaderBufferSizeKB() const;
    void setRNavigationMeshDataReaderBufferSizeKB(u32);
protected:
    const DECODEWORK* getDecodeWork();
    bool createFileCache(MT_STR dstpath, MT_CTSTR srcpath);
    void removeFileCache(cResource* pr);
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    cResource* loadBlocking(const MtDTI& dti, MT_CTSTR path, u64 id, u32 mode);
    cResource* loadAsync(const MtDTI& dti, MT_CTSTR path, u64 id, u32 mode);
    cResource* findTable(u64 id, u32 shift);
    void registTable(cResource* pr, u32 shift);
    void releaseTable(cResource* pr, u32 shift);
    void createTypeInfo(const MtDTI& dti);
    static void* loaderHandler(void* pArg);
    virtual void addRef(cResource* pr);  // vtable slot 15
    virtual void release(cResource* pr);  // vtable slot 16
    void makeShortPath(MT_STR path);
    void saveRemote();
    bool load(MtStream& in, cResource* pr);
    bool remoteConvert(TypeInfo* pinfo, const MtDTI& dti, MT_CTSTR path);
    cResource* precreate(const MtDTI& dti, MT_CTSTR path, u32 size, cResource::QUALITY quality);
    cResource* create(MtStream& in, cResource* pr);
    u32 getQualityByMode(u32 mode);
    ResourceInfo* createResourceInfo(MT_CTSTR fullpath);
    const MtDTI* getResourceDTI(MT_CTSTR ext, bool isNative, const MtDTI* pbase);
    void buildFolder(MtString path, MtString* folder_list, s32& folder_num, MtString* archive_list, s32& archive_num);
    void normalizePath(MT_CTSTR spath, MT_STR dpath, u32 length);
    bool isConflict(cResource* pr, const MtDTI& dti, MT_CTSTR path);
    static void* decodeProc(void* context);
public:
    void setLoaderThreadSuspend();
    void releaseLoaderThreadSuspend();
    void getFullPathVer(MT_STR dst, cResource* pr);
    void getFullPathVer(MT_STR dst_path, const MtDTI& dti, MT_CTSTR path);
    void getFullPathSave(MT_STR dst, cResource* pr);
    void getFullPathSave(MT_STR, const MtDTI&, MT_CTSTR);
    s32 getResourceNum() const;
    void setForceVramMemory(bool enable);
    bool isForceVramMemory();
    void setForceBackGround(const bool b);
protected:
    TypeInfo mTypeInfo[1024];  // offset: 0x18
    u32 mTypeInfoNum;  // offset: 0x8018
    MtString mRootDirectory;  // offset: 0x8020
    MtString mResourcePath;  // offset: 0x8028
    MtString mNativePath;  // offset: 0x8030
    MtString mResourceFolder;  // offset: 0x8038
    MtString mNativeFolder;  // offset: 0x8040
    cResource* mpTable[16384];  // offset: 0x8048
    Property mResourceProperty;  // offset: 0x28048
    bool mOptimizeEnable;  // offset: 0x28050
    bool mBuildComplete;  // offset: 0x28051
    bool mForceHDDCache;  // offset: 0x28052
    bool mForceBackGround;  // offset: 0x28053
    bool mLoadEnd;  // offset: 0x28054
    bool mAutoUpdate;  // offset: 0x28055
    bool mCacheEnable;  // offset: 0x28056
    RESOURCE_PATH_FILTER mpPathFilter;  // offset: 0x28058
    void* mpPathFilterAdr;  // offset: 0x28060
    ScePthread mLoaderThreadHandle;  // offset: 0x28068
    MtSemaphore* mpLoadSemaphore;  // offset: 0x28070
    cResource* mpLoadList[1024];  // offset: 0x28078
    u32 mLoadNum;  // offset: 0x2a078
    LOADING_INFO mLoadingInfo;  // offset: 0x2a07c
    u32 mDecodeThreadMask;  // offset: 0x2a0c4
    u32 mDecodeThreadNum;  // offset: 0x2a0c8
    ScePthread mDecodeThread[4];  // offset: 0x2a0d0
    nWin32Detour::eventFlag mDecodeEvent[4];  // offset: 0x2a0f0
    nWin32Detour::eventFlag mDecodeSync[4];  // offset: 0x2a110
    ScePthread mDecodeThreadID[4];  // offset: 0x2a130
    DECODEWORK mDecodeWork;  // offset: 0x2a150
    s32 mTagCount;  // offset: 0x4a1a8
    bool mRemoteConvert;  // offset: 0x4a1ac
    bool mDecoderActivation[4];  // offset: 0x4a1ad
public:
    volatile bool mLoaderThreadSuspend;  // offset: 0x4a1b1
private:
    s32 mResourceNum;  // offset: 0x4a1b4
public:
    u32 mRModelDataReaderBufferSizeKB;  // offset: 0x4a1b8
    u32 mRTextureDataReaderBufferSizeKB;  // offset: 0x4a1bc
    u32 mRCollisionDataReaderBufferSizeKB;  // offset: 0x4a1c0
    u32 mRGrassDataReaderBufferSizeKB;  // offset: 0x4a1c4
    u32 mRNavigationMeshDataReaderBufferSizeKB;  // offset: 0x4a1c8
private:
    bool mForceVramMemory;  // offset: 0x4a1cc
public:
    static MyDTI DTI;
protected:
    static const u32 MAX_DECODERESOURCE = 4096;
    static sResource* mpInstance;
    static const s32 MAX_REHASH = 16;
    static const s32 MAX_TABLE = 2048;
    static const s32 MAX_WAY = 8;
    static const u32 MAX_TYPEINFO = 1024;
    static const s32 LOADER_PROCESSOR = 2;
    static const s32 TABLE_SIZE = 16384;
    static const u32 MAX_LOADLIST = 1024;
    static const s32 LOADER_PRIORITY = 680;
    static const s32 DECODER_PRIORITY = 679;
    static const s32 LOADER_STACK_SIZE = 131072;
    static const s32 DECODER_STACK_SIZE = 131072;
    static const u32 MAX_READSIZE = 131072;
    static const u32 MAX_DECODETHREAD = 4;
    static RemoteInfo* mpRemoteInfo;
};

// Inline, no code of its own: checked where it is inlined.
inline sResource* sResource::getInstance() {
    return ::sResource::mpInstance;
}
