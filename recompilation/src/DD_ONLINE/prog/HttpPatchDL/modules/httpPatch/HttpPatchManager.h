#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../MT/MtNetObject.h"
#include "../../../../../MT/MtString.h"
#include "../../../../../MT/MtSynchronize.h"
#include "httpPatch.h"
#include "httpPatchClient.h"
#include "httpPatchTypes.h"
#include "utility/requestQueue.h"

// Forward declarations
class MtCriticalSection;
class MtString;
namespace via { namespace module { namespace http_patch { class ClientManager; } } }
namespace via { namespace module { namespace http_patch { struct ExeFileInfo; } } }
namespace via { namespace module { namespace http_patch { class ExeVersionResult; } } }
namespace via { namespace module { namespace http_patch { class FileControlManager; } } }
namespace via { namespace module { namespace http_patch { class ParallelsFileData; } } }
namespace via { namespace module { namespace http_patch { class ParallelsFileListenerManager; } } }
namespace via { namespace module { namespace http_patch { class RequestParam; } } }
namespace via { namespace module { namespace http_patch { class RequestParamCore; } } }
namespace via { namespace module { namespace http_patch { class ResultBase; } } }
namespace via { namespace module { namespace http_patch { struct SucceedFileInfo; } } }
namespace via { namespace module { namespace http_patch { struct VersionInfo; } } }
namespace via { namespace module { namespace http_patch { class VersionResult; } } }

// Declarations
namespace via { namespace module { namespace http_patch { class HttpPatchManager; } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __uint64_t = long unsigned int;
using f32 = float;
using httpdl_array_MtString = MtCollisionUtil::MtArrayTemplateEx<MtString, true, 1>;
using s32 = int;
using u32 = unsigned int;
using u64 = __uint64_t;
namespace via { namespace module { namespace http_patch { using exefileinfo_array_t = MtCollisionUtil::MtArrayTemplateEx<via::module::http_patch::ExeFileInfo, true, 1>; } } }
namespace via { namespace module { namespace http_patch { using findfile_array_t = httpdl_array_MtString; } } }
namespace via { namespace module { namespace http_patch { using httpdl_array_SucceedFileInfo = MtCollisionUtil::MtArrayTemplateEx<via::module::http_patch::SucceedFileInfo, true, 1>; } } }
namespace via { namespace module { namespace http_patch { using parallelfiledata_array_t = MtCollisionUtil::MtArrayTemplateEx<via::module::http_patch::ParallelsFileData, true, 1>; } } }
namespace via { namespace module { namespace http_patch { using versioninfo_array_t = MtCollisionUtil::MtArrayTemplateEx<via::module::http_patch::VersionInfo, true, 1>; } } }

namespace via {
    namespace module {
        namespace http_patch {
            class HttpPatchManager : public ::MtNetObject
            {
            public:
                enum DownloadFolderType
                {
                    DownloadFolder_NULL = 0,
                    DownloadFolder_RECOVER = 1,
                    DownloadFolder_REPLACE = 2,
                    DownloadFolder_PATCH = 3,
                };
            public:
                struct RequestProcParam;
            public:
                using requestparamhandle_t = via::RequestList<via::module::http_patch::HttpPatchManager::RequestProcParam>;
                using parallelsfilelistenermanager_t = via::module::http_patch::ParallelsFileListenerManager*;
            public:
                struct RequestProcParam
                {
                public:
                    RequestProcParam();
                    RequestProcParam(via::module::http_patch::RequestType, via::module::http_patch::ResultBase*);
                    RequestProcParam(via::module::http_patch::RequestType _type, via::module::http_patch::ResultBase* _result_ptr, const via::module::http_patch::RequestParamCore& rpc);
                    RequestProcParam(const via::module::http_patch::HttpPatchManager::RequestProcParam& rp_param);
                public:
                    via::module::http_patch::RequestType type;  // offset: 0x0
                    via::module::http_patch::ResultBase* result_ptr;  // offset: 0x8
                    via::module::http_patch::RequestParamCore param;  // offset: 0x10
                };
            public:
                static via::module::http_patch::HttpPatchManager* createInstance();
                static void deleteInstance();
                static void terminateModule();
                static via::module::http_patch::HttpPatchManager* instance();
                bool abort();
                via::module::http_patch::RequestParam* createRequestParam();
                void deleteRequestParam(via::module::http_patch::RequestParam* result);
                void deleteResult(via::module::http_patch::ResultBase* result);
                void setDebugSaveVersionFile(bool enable);
                bool isDebugSaveVersionFile();
                static const MtString& getTempDirectory();
                static const MtString& getDownloadDirectory();
                u32 getDebugOffsetX() const;
                u32 getDebugOffsetY() const;
                u32 getDebugFontW() const;
                u32 getDebugFontH() const;
                u32 getDebugRectH() const;
                bool isDebugPadMoveOffset() const;
                void setDebugOffsetX(u32 value);
                void setDebugOffsetY(u32 value);
                void setDebugFontW(u32 value);
                void setDebugFontH(u32 value);
                void setDebugRectH(u32 value);
                void setDebugPadMoveOffset(bool enable);
                void update();
                void addFailedFileInfo(const via::module::http_patch::ParallelsFileData& info);
                bool isAbortFlag() const;
                bool isDebugDraw() const;
                void setDebugDraw(bool enable);
                HttpPatchManager();
                virtual ~HttpPatchManager();
                void finalize();
                void deleteResultOnly(via::module::http_patch::ResultBase* result);
                void requestPopEvent(RequestProcParam& info);
                void requestPushEvent(RequestProcParam& info);
                void updateProc(void* param, RequestProcParam& info);
                void setupRequest(const RequestProcParam& info);
                void finalizeRequest();
                void resetupFileControlManager(const RequestProcParam& info);
                void saveDownloadFileInfo(const via::module::http_patch::httpdl_array_SucceedFileInfo& sfi_list);
                u32 loadNormalVersionFile();
                void saveNormalVersionFile(u32 normal_version);
                void calcNormalVersionProc(void* param);
                via::module::http_patch::ExeVersionResult* exeVersionCheck(const via::module::http_patch::RequestParam* param_ptr, const u32 version_launcher, const u32 version_gameapp);
                via::module::http_patch::Result exeVersionCheck(const RequestProcParam& info);
                via::module::http_patch::Result exeVersionCheck(MT_CTSTR versionlist_name, u32& version_launcher, u32& version_gameapp, via::module::http_patch::exefileinfo_array_t& exefileinfo);
                via::module::http_patch::VersionResult* nomalVersionCheck(const via::module::http_patch::RequestParam* param_ptr);
                via::module::http_patch::Result normalCheck(const RequestProcParam& info);
                via::module::http_patch::Result normalCheck(MT_CTSTR versionlist_name, s32& app_version, via::module::http_patch::versioninfo_array_t& version_list);
                bool isUpdateLauncher(via::module::http_patch::ExeVersionResult* exe_version_result_ptr);
                void setPhase(via::module::http_patch::Phase phase);
                void setResult(via::module::http_patch::Result result);
                void setResultDetail(HPDErrCategory ecType, s32 errCode);
                void setErrFilePath(MT_CHAR* fn);
                void setDLFilePath(MT_CHAR* fn);
                void setInsFilePath(MT_CHAR* fn);
                void setProgressDL1File(f32 per);
                void setProgressFarExtract(f32 per);
                f32 getDLSpeedMbps(f32 spdLimit);
                void getDLRetryParams(HTTPDL_RETRY_PARAMS* buff);
                void getDLRetryStatus(HTTPDL_RETRY_STATUS* buff);
                void storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff);
                void waitFileIO(parallelsfilelistenermanager_t& pl);
                void resetAppVersion();
                bool findFile(MT_CTSTR path, via::module::http_patch::findfile_array_t& paths, bool not_exclude_files);
                bool findFileCalcFileNum(MT_CTSTR path, u64& count);
                u32 getRetryCount() const;
                void debugLock();
                void debugUnlock();
                void setAbortFlag(bool enable);
                void setupResultPtr(via::module::http_patch::ResultBase* ptr);
                void makeStringU64toDecimal(u64 num, char* buff, s32 bufferSize);
                void _waring_remove();
                const via::module::http_patch::HttpPatchManager& operator=(const via::module::http_patch::HttpPatchManager&);
                template <typename T> T* createResult();
                template <typename T> void deleteResult(T* ptr);
            public:
                MtCriticalSection mMutex_Period_HttpClientInit;  // offset: 0x28
                s32 mHttpClientInit_Count;  // offset: 0x30
                MtCriticalSection mMutex_Download_Size;  // offset: 0x38
            private:
                MtString mTempDirectory;  // offset: 0x40
                MtString mDownloadDirectory;  // offset: 0x48
                via::module::http_patch::ClientManager mClient;  // offset: 0x50
                via::module::http_patch::ResultBase* mResultPtr;  // offset: 0xb80
                via::module::http_patch::VersionResult* mVersionResultPtr;  // offset: 0xb88
                via::module::http_patch::ExeVersionResult* mExeVersionResultPtr;  // offset: 0xb90
                requestparamhandle_t mhDownloadRequest;  // offset: 0xb98
            public:
                via::module::http_patch::FileControlManager* mFileControlMngPtr;  // offset: 0xc50
            private:
                struct
                {
                public:
                    via::module::http_patch::VersionInfo info;  // offset: 0x0
                    via::module::http_patch::RequestType type;  // offset: 0x4
                } mAppVersion;  // offset: 0xc58
                MtCriticalSection mFaildListMutex;  // offset: 0xc60
                via::module::http_patch::parallelfiledata_array_t mFaildList;  // offset: 0xc68
                via::module::http_patch::parallelfiledata_array_t mFullList;  // offset: 0xc88
                via::module::http_patch::parallelfiledata_array_t mPurgeList;  // offset: 0xca8
                u32 mRetryCount;  // offset: 0xcc8
                bool mAbortFlag;  // offset: 0xccc
            public:
                static via::module::http_patch::HttpPatchManager* mpInstance;
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

inline via::module::http_patch::HttpPatchManager* via::module::http_patch::HttpPatchManager::instance() {
    return ::via::module::http_patch::HttpPatchManager::mpInstance;
}

inline bool via::module::http_patch::HttpPatchManager::isAbortFlag() const {
    return this->mAbortFlag;
}
