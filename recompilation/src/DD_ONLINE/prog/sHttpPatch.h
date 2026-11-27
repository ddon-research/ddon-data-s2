#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cSystem.h"
#include "HttpPatchDL/modules/httpPatch/httpPatch.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
namespace via { class HttpPatchModule; }
namespace via { namespace module { namespace http_patch { class ExeVersionResult; } } }
namespace via { namespace module { namespace http_patch { class HttpPatchManager; } } }
namespace via { namespace module { namespace http_patch { class RequestParam; } } }
namespace via { namespace module { namespace http_patch { class ResultBase; } } }
namespace via { namespace module { namespace http_patch { class UpdateResult; } } }
namespace via { namespace module { namespace http_patch { class VersionResult; } } }

// Declarations
class sHttpPatch;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;

class sHttpPatch : public cSystem
{
public:
    enum Phase
    {
        ServerSelect = 0,
        ExeVerCheck = 1,
        ExeVerCheck_Running = 2,
        ExeVerCheck_Finish = 3,
        ExeVerCheck_NextWait = 4,
        NormalVerCheck = 5,
        NormalVerCheck_Running = 6,
        NormalVerCheck_Finish = 7,
        NormalVerCheck_NextWait = 8,
        UpdateFileReq = 9,
        UpdateFileReq_Running = 10,
        UpdateFileReq_Finish = 11,
        UpdateFileReq_NextWait = 12,
        Finish = 13,
        Error = 14,
        Abort = 15,
        Phase_MAX = 16,
    };
    enum ServerType
    {
        Local_VersionUp_010001 = 0,
        Local_VersionUp_010002 = 1,
        Local_VersionUp_010003 = 2,
        Local_VersionUp_010004 = 3,
        Local_VersionUp_010005 = 4,
        Local_VersionUp_010006 = 5,
        MaxCursor = 6,
        Local_Begin = 0,
        Local_End = 5,
    };
    enum
    {
        FLOW_EXE_VER_CHECK_INIT = 0,
        FLOW_EXE_VER_CHECK_REQ = 1,
        FLOW_EXE_VER_CHECK_WAIT = 2,
        FLOW_EXE_VER_CHECK_MATCH = 3,
        FLOW_EXE_VER_CHECK_ERROR = 4,
        FLOW_EXE_VER_CHECK_EXIT = 5,
        FLOW_EXE_VER_CHECK_SUSPEND = 99,
    };
    enum
    {
        FLOW_NORMAL_VER_CHECK_INIT = 0,
        FLOW_NORMAL_VER_CHECK_REQ = 1,
        FLOW_NORMAL_VER_CHECK_WAIT = 2,
        FLOW_NORMAL_VER_CHECK_ERROR = 3,
        FLOW_NORMAL_VER_CHECK_EXIT = 4,
        FLOW_NORMAL_VER_CHECK_SUSPEND = 99,
    };
public:
    class MyDTI;
public:
    typedef struct
    {
    public:
        MtString name_FileList;  // offset: 0x0
        MtString name_VersionList;  // offset: 0x8
    } FILE_LIST_ITEM;
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
    sHttpPatch();
    virtual ~sHttpPatch();
    static sHttpPatch* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void easyCleaning();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    bool isAbort();
    void setIsAbort(bool flag);
    bool isError();
    s32 getErrorCode();
    void setErrorCode(s32 errorCode);
    u32 convErrorCode(via::module::http_patch::ResultBase* pResult);
    void clearResult();
    bool getTestFileListItem(int ix, FILE_LIST_ITEM* item);
    bool checkSetupEnable();
    virtual void move();  // vtable slot 7
    MT_CTSTR getCurrentVer();
    MT_CTSTR getLatestVer();
    s64 getDownloadSize();
    s64 getDownloadTotalSize();
    f64 getDownloadSpeed();
    s64 getDownloadRemain();
    void abortUpdate();
    void registDLServer();
    bool isExecExeVerCheckFlow();
    void reqExeVerCheck();
    void moveExeVerCheck();
    bool isUpdateExe();
    bool isUpdateExeLauncher();
    bool isUpdateExeGameApp();
    bool isExecNormalVerCheckFlow();
    void reqNormalVerCheck();
    void moveNormalVerCheck();
    bool isUpdate();
private:
    u32 mExeVerCheckRno;  // offset: 0x14
    u32 mNormalVerCheckRno;  // offset: 0x18
    HTTPDL_RETRY_PARAMS mDLParam;  // offset: 0x1c
    via::module::http_patch::HttpPatchManager* mpHPManager;  // offset: 0x30
    via::HttpPatchModule* mpHPModule;  // offset: 0x38
    bool mSetuped;  // offset: 0x40
    Phase phase;  // offset: 0x44
    Phase phaseNext;  // offset: 0x48
    bool abort;  // offset: 0x4c
    bool abortLock;  // offset: 0x4d
    bool detailedMode;  // offset: 0x4e
    bool forceMatchedMode;  // offset: 0x4f
    s32 selectServer;  // offset: 0x50
    s32 threadNum;  // offset: 0x54
    s32 forceMatchedVersionNo;  // offset: 0x58
    ServerType _SelectServer;  // offset: 0x5c
    via::module::http_patch::RequestParam* _Param;  // offset: 0x60
    via::module::http_patch::ResultBase* _ResultCtrl;  // offset: 0x68
    via::module::http_patch::ExeVersionResult* _ExeVersionResultCtrl;  // offset: 0x70
    via::module::http_patch::VersionResult* _VersionResultCtrl;  // offset: 0x78
    via::module::http_patch::UpdateResult* _UpdateResultCtrl;  // offset: 0x80
    MtString mStrAppVersion;  // offset: 0x88
    MtString mStrServerVersion;  // offset: 0x90
    bool mModuleLoaded;  // offset: 0x98
    u32 mRnoCSE;  // offset: 0x9c
    s32 mErrorCode;  // offset: 0xa0
    bool mIsError;  // offset: 0xa4
    bool mIsAbort;  // offset: 0xa5
public:
    static MyDTI DTI;
private:
    static sHttpPatch* mpInstance;
};

inline void* sHttpPatch::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline s32 sHttpPatch::getErrorCode() {
    return this->mErrorCode;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* sHttpPatch::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sHttpPatch::DTI);
}

inline void sHttpPatch::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sHttpPatch::DTI)->memFree(p_addr);
}
