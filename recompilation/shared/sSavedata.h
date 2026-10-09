#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "MtThread.h"
#include "cSystem.h"
#include "save_data.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMemoryStream;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
struct SceSaveDataDialogResult;
struct SceSaveDataDirName;
struct SceSaveDataDirNameSearchResult;
struct SceSaveDataFingerprint;
struct SceSaveDataIcon;
struct SceSaveDataTitleId;
struct _SceKernelSema;

// Declarations
class sSavedata;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using SceKernelSema = _SceKernelSema*;
using __int32_t = int;
using int32_t = __int32_t;
using SceSaveDataDialogSystemMessageType = int32_t;
using SceSaveDataDialogType = int32_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceSaveDataSortKey = uint32_t;
using SceSaveDataSortOrder = uint32_t;
using SceUserServiceUserId = int32_t;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class sSavedata : public cSystem
{
public:
    enum
    {
        OPMODE_NONE = 0,
        OPMODE_DELETE = 1,
        OPMODE_SAVE = 2,
        OPMODE_LOAD = 3,
        OPMODE_BASE = 4,
    };
    enum
    {
        STATE_IDLE = 0,
        STATE_EXECUTING = 1,
        STATE_BASE = 2,
    };
    enum
    {
        RESULT_OK = 0,
        RESULT_CANCEL = 1,
        RESULT_NOSPACE = 2,
        RESULT_NODATA = 3,
        RESULT_BROKEN = 4,
        RESULT_ANYONE = 5,
        RESULT_MISSMATCH_SYSVER = 6,
        RESULT_MISSMATCH_APPVER = 7,
        RESULT_INVALID = 8,
        RESULT_ERR = 9,
        RESULT_BASE = 10,
    };
    enum TYPE
    {
        TYPE_UNDEFINED = 0,
        TYPE_BOOLEAN = 1,
        TYPE_U8 = 2,
        TYPE_U16 = 3,
        TYPE_U32 = 4,
        TYPE_U64 = 5,
        TYPE_S8 = 6,
        TYPE_S16 = 7,
        TYPE_S32 = 8,
        TYPE_S64 = 9,
        TYPE_F32 = 10,
        TYPE_F64 = 11,
        TYPE_BINARY = 12,
    };
public:
    class MyDTI;
    struct HEADER;
    struct KEYTABLE;
    class cStorageThread;
    struct DATA_HEADER;
    class LessKey;
public:
    using OPMODE = u32;
    using STATE = u32;
    using RESULT = s32;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 systemVersion;  // offset: 0x0
        u32 appVersion;  // offset: 0x4
        u32 labelSize;  // offset: 0x8
        u32 reserved;  // offset: 0xc
    };
public:
    struct KEYTABLE
    {
    public:
        void* buf;  // offset: 0x0
        size_t size;  // offset: 0x8
        s32 type;  // offset: 0x10
        u32 hash;  // offset: 0x14
    };
public:
    class cStorageThread : public MtThread
    {
    public:
        enum PROCESS_TASK
        {
            T_WAIT = 0,
            T_LOAD = 1,
            T_SAVE = 2,
            T_DELETE = 3,
            T_LLOAD = 4,
            T_LSAVE = 5,
            T_LDELETE = 6,
            T_EXIST = 7,
            T_TERMINATE = 8,
        };
    public:
        cStorageThread();
        virtual ~cStorageThread();
        void setTask(PROCESS_TASK task);
    protected:
        virtual void execute(void* pcontext);  // vtable slot 6
    protected:
        u32 mTask;  // offset: 0x70
        SceKernelSema mEvent;  // offset: 0x78
    };
public:
    struct DATA_HEADER
    {
    public:
        u32 hash;  // offset: 0x0
        s32 type;  // offset: 0x4
        union
        {
        public:
            u32 size;  // offset: 0x0
            bool bdata;  // offset: 0x0
            u8 u8data;  // offset: 0x0
            s8 s8data;  // offset: 0x0
            u16 u16data;  // offset: 0x0
            s16 s16data;  // offset: 0x0
            u32 u32data;  // offset: 0x0
            s32 s32data;  // offset: 0x0
            u64 u64data;  // offset: 0x0
            s64 s64data;  // offset: 0x0
            f32 f32data;  // offset: 0x0
            f64 f64data;  // offset: 0x0
        };  // offset: 0x8
    };
public:
    class LessKey
    {
    public:
        bool operator()(const sSavedata::KEYTABLE& pkey0, const sSavedata::KEYTABLE& pkey1);
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
    sSavedata();
    virtual ~sSavedata();
    static sSavedata* getInstance();
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    RESULT beginDelete();
    RESULT beginSave();
    RESULT beginLoad();
    RESULT beginGetVersion();
    RESULT setDataBool(bool* data, MT_CTSTR key);
    RESULT setDataS8(s8* data, MT_CTSTR key);
    RESULT setDataU8(u8* data, MT_CTSTR key);
    RESULT setDataS16(s16* data, MT_CTSTR key);
    RESULT setDataU16(u16* data, MT_CTSTR key);
    RESULT setDataS32(s32* data, MT_CTSTR key);
    RESULT setDataU32(u32* data, MT_CTSTR key);
    RESULT setDataS64(s64* data, MT_CTSTR key);
    RESULT setDataU64(u64* data, MT_CTSTR key);
    RESULT setDataF32(f32* data, MT_CTSTR key);
    RESULT setDataF64(f64* data, MT_CTSTR key);
    RESULT setDataBinary(void* data, size_t size, MT_CTSTR key);
    void setVersion(u32);
    RESULT setUserHeader(void* data, size_t size);
    void clearData();
    STATE getState() const;
    RESULT getResult() const;
    u32 getSavedataVersion() const;
    u32 calcDataSize();
    void setThroughRunning(bool);
    bool isThroughRunning();
    void setOverWrite(bool flag);
    bool isOverWrite();
protected:
    RESULT setData(void* data, size_t size, s32 type, MT_CTSTR key);
    bool setKeyTableData(void* data, size_t size, u32 hash);
    KEYTABLE* findKeyTable(u32 hash, bool IsFindFailedToNULL);
public:
    void setEncrypt(bool isEncrypt);
    bool isEncrypt() const;
    void setCipherKey(MT_CTSTR key);
    void setCipherKey(u8* key);
private:
    bool isSetCipherKey() const;
public:
    void init();
    void final();
    s32 loadIcon(const MT_CTSTR iconPath, const MT_CTSTR newItemIconPath);
    void setSaveDataUserID(const SceUserServiceUserId);
    void setSaveDataDir(const MT_CTSTR saveDataName);
    void setSaveDataFileName(const MT_CTSTR);
    void setTitle(const MT_CTSTR title);
    void setSubTitle(const MT_CTSTR subTitle);
    void setDetail(const MT_CTSTR detail);
    void setNewItemTitle(const MT_CTSTR newItemTitle);
    void setSaveDataSearchCond(const MT_CTSTR searchName, SceSaveDataSortKey sortKey, SceSaveDataSortOrder sortOrder);
    void setUseSearchCond(const bool flag);
    void setTitleId(const MT_CTSTR titleID);
    void setFingerprint(const MT_CTSTR fingerprint);
    void resetFingerprint();
    MT_CTSTR getIconPath() const;
    MT_CTSTR getNewItemIconPath() const;
    MT_CTSTR getSaveDataDir() const;
    MT_CTSTR getSaveDataFileName() const;
    MT_CTSTR getTitle() const;
    MT_CTSTR getSubTitle() const;
    MT_CTSTR getDetail() const;
    MT_CTSTR getNewItemTitle() const;
    SceUserServiceUserId getUserId() const;
    const SceSaveDataTitleId* getTitleId() const;
    const SceSaveDataFingerprint* getFingerprint() const;
    void setListSaveCanCreateNum(u32 Num);
    RESULT beginListLoad();
    RESULT beginListSave();
    RESULT beginListDelete();
    RESULT beginExistCheck();
protected:
    void unloadIcon();
    void initUserId();
    void processLoad();
    void processSave();
    void processDelete();
    void processListLoad();
    void processListSave();
    void processListDelete();
    void processExistCheck();
private:
    s32 readFile(MT_CTSTR path, void* buf, u32 bufSize);
    bool isExistDir(MT_CTSTR name) const;
    s32 getExistDirNames(SceSaveDataDirNameSearchResult* pOutResult, bool useSearchCond);
    void getNewDirName(SceSaveDataDirName* pOutDirName, const SceSaveDataDirName* pDirNames, u32 dirNamesNum);
    void saveCore(const SceSaveDataDirName* pDirName, bool isExist, bool isUpdateProgress);
    void writeData(MtMemoryStream& out);
    void loadCore(const SceSaveDataDirName* pDirName, bool isUpdateProgress);
    RESULT readData(MtMemoryStream& in);
    void deleteCore(const SceSaveDataDirName* pDirName, bool isUpdateProgress);
    s32 openDialogList(SceSaveDataDialogType type, const SceSaveDataDirName* pDirNames, u32 namesNum, bool showNewItem);
    s32 openDialogSystemMessage(SceSaveDataDialogType type, const SceSaveDataDirName* pDirName, SceSaveDataDialogSystemMessageType mesType, u64 mesValue);
    s32 openDialogProgress(SceSaveDataDialogType type, const SceSaveDataDirName* pDirName, bool showNewItem);
    s32 waitDialog(SceSaveDataDialogResult* pDialogResult);
    RESULT beginSaveMain(cStorageThread::PROCESS_TASK task);
    RESULT beginLoadMain(cStorageThread::PROCESS_TASK task);
    RESULT beginDeleteMain(cStorageThread::PROCESS_TASK task);
protected:
    OPMODE mOpMode;  // offset: 0x14
    STATE mState;  // offset: 0x18
    RESULT mResult;  // offset: 0x1c
    void* mpData;  // offset: 0x20
    size_t mDataSize;  // offset: 0x28
    HEADER mHdr;  // offset: 0x30
    u32 mSavedataVersion;  // offset: 0x40
    KEYTABLE mKeyTable[200];  // offset: 0x48
    s32 mKeyTableNum;  // offset: 0x1308
    bool mThroughRunning;  // offset: 0x130c
    bool mOverWrite;  // offset: 0x130d
private:
    bool mIsEncrypt;  // offset: 0x130e
    u8 mCipherKey[64];  // offset: 0x130f
protected:
    cStorageThread mStorageThread;  // offset: 0x1350
private:
    SceUserServiceUserId mUserId;  // offset: 0x13d0
    SceSaveDataTitleId* mTitleId;  // offset: 0x13d8
    MtString mNewItemIconPath;  // offset: 0x13e0
    MtString mIconPath;  // offset: 0x13e8
    MtString mSaveDataDirName;  // offset: 0x13f0
    MtString mSaveDataFileName;  // offset: 0x13f8
    MtString mParamTitle;  // offset: 0x1400
    MtString mParamSubTitle;  // offset: 0x1408
    MtString mParamDetail;  // offset: 0x1410
    MtString mNewItemTitle;  // offset: 0x1418
    SceSaveDataIcon mIcon;  // offset: 0x1420
    SceSaveDataIcon mNewItemIcon;  // offset: 0x1458
    u32 mRequireBlocks;  // offset: 0x1490
    SceSaveDataFingerprint* mFingerprint;  // offset: 0x1498
    bool mUseSearchCond;  // offset: 0x14a0
    MtString mSaveDataDirSearchCond;  // offset: 0x14a8
    SceSaveDataSortKey mSortKey;  // offset: 0x14b0
    SceSaveDataSortOrder mSortOrder;  // offset: 0x14b4
    u32 mListSaveCanCreateNum;  // offset: 0x14b8
public:
    static const u32 INVALID_VERSION = 4294967295;
    static MyDTI DTI;
protected:
    static const u32 SYSTEM_VERSION = 0;
    static const u32 KEY_SIZE_MAX = 16;
    static const u32 KEYTABLE_SIZE = 200;
    static sSavedata* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sSavedata* sSavedata::getInstance() {
    return ::sSavedata::mpInstance;
}
