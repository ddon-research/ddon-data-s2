#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtFile.h"
#include "../MT/MtString.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class rHDDPrefetchList;

// Declarations
class sFile;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class sFile : public cSystem
{
public:
    enum PREFETCH_FLAG
    {
        PREFETCH_NUM = 0,
    };
public:
    class MyDTI;
    struct PREFETCH_LIST;
    class RealPath;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PREFETCH_LIST
    {
    public:
        MT_CHAR path[80];  // offset: 0x0
        sFile::PREFETCH_LIST* next;  // offset: 0x50
        u32 flag;  // offset: 0x58
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
    sFile(MT_CTSTR titlecode);
    virtual ~sFile();
    void setData(rHDDPrefetchList* res);
    rHDDPrefetchList* getData() const;
private:
    bool mountTemp();
    bool mountDownload();
public:
    void formatTemp();
    size_t getTempFreeSize();
    bool isTempMount() const;
    const MtString& getTempPath() const;
    void formatDownload();
    size_t getDownloadFreeSize();
    bool isDownloadMount() const;
    const MtString& getDownloadPath() const;
    MT_CTSTR getTitleCode();
    static void getDriveType(MT_CTSTR path, MtFile::DRIVETYPE& dst_dtype, u32& dst_srcprefixoffset, MT_STR dest_nativemountprefix);
    static sFile* getInstance();
    void addPrefetchFile(MT_CTSTR path, PREFETCH_FLAG flag);
    void startPrefetch();
    bool isFlgStopPrefetchRegisterFunction() const;
    void setFlgStopPrefetchRegisterFunction(bool);
    bool isFlgEndPrefetchRegisterFunction() const;
    void setFlgEndPrefetchRegisterFunction(bool);
protected:
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void exportLogs();
    void addPrefetchList(MT_CTSTR path, u32 flag);
    PREFETCH_LIST* getCurrentPrefetchList();
    PREFETCH_LIST* removeCurrentPrefetchFile();
public:
    void setSwitchDownloadDrive(bool isEnable);
    bool isSwitchDownloadDrive();
    void initSwitchDownloadDrive(MT_CTSTR* FolderName, u32 FolderNum, MT_CTSTR* ExtractFolderName, u32 ExtractFolderNum);
protected:
    static bool isDownloadFile(MT_CTSTR path);
public:
    void setDownloadAreaFilePriority(bool isEnable);
    bool isDownloadAreaFilePriority();
protected:
    static bool isExistDownloadArea(MT_CTSTR path);
protected:
    MtString mTitleCode;  // offset: 0x18
    bool mFlgStopPrefetchRegisterFunction;  // offset: 0x20
    bool mFlgEndPrefetchRegisterFunction;  // offset: 0x21
    rHDDPrefetchList* mpPrefetchResource;  // offset: 0x28
    PREFETCH_LIST* mpPrefetchList;  // offset: 0x30
    PREFETCH_LIST* mpPrefetchWritePt;  // offset: 0x38
    bool mTempMount;  // offset: 0x40
    bool mDownloadMount;  // offset: 0x41
    MtString mTempMountPath;  // offset: 0x48
    MtString mDownloadMountPath;  // offset: 0x50
public:
    bool mIsSwitchDownloadDrive;  // offset: 0x58
    MT_CTSTR* mpDownloadDriveFolder;  // offset: 0x60
    u32 mDownloadDriveFolderNum;  // offset: 0x68
    MT_CTSTR* mpDownloadDriveExtractFolder;  // offset: 0x70
    u32 mDownloadDriveExtractFolderNum;  // offset: 0x78
    bool mIsDownloadAreaFilePriority;  // offset: 0x7c
    static MyDTI DTI;
protected:
    static const u32 PREFETCH_PATH_MAX = 80;
    static sFile* mpInstance;
};

inline void* sFile::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sFile::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sFile::DTI)->memFree(p_addr);
}
