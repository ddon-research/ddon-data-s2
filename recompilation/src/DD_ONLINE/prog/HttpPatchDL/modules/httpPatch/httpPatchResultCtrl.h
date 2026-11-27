#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../MT/MtPerformance.h"
#include "httpPatch.h"
#include "httpPatchTypes.h"

// Forward declarations
class MtPerformanceTimer;
namespace via { namespace module { namespace http_patch { class CnvEnumToStr; } } }
namespace via { namespace module { namespace http_patch { struct ExeFileInfo; } } }
namespace via { namespace module { namespace http_patch { class HttpPatchManager; } } }
namespace via { namespace module { namespace http_patch { struct VersionInfo; } } }

// Declarations
namespace via { namespace module { namespace http_patch { class ExeVersionResult; } } }
namespace via { namespace module { namespace http_patch { class ResultBase; } } }
namespace via { namespace module { namespace http_patch { class VersionResult; } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
namespace via { namespace module { namespace http_patch { using exefileinfo_array_t = MtCollisionUtil::MtArrayTemplateEx<via::module::http_patch::ExeFileInfo, true, 1>; } } }
namespace via { namespace module { namespace http_patch { using versioninfo_array_t = MtCollisionUtil::MtArrayTemplateEx<via::module::http_patch::VersionInfo, true, 1>; } } }

namespace via {
    namespace module {
        namespace http_patch {
            class ResultBase
            {
                friend class via::module::http_patch::HttpPatchManager;
            public:
                typedef struct
                {
                public:
                    s32 toName;  // offset: 0x0
                    MT_CHAR fnPath[124];  // offset: 0x4
                } RBPathData;
            public:
                ResultBase(MT_CTSTR name);
                virtual ~ResultBase() {}
                f64 getProgress();
                f64 getTotalTime();
                f64 getReadyTime();
                f64 getDownloadTime();
                via::module::http_patch::Phase getPhase() const;
                MT_CTSTR getPhaseString();
                via::module::http_patch::Result getResult() const;
                HPDErrCategory getResultDetailErrorCategory() const;
                s32 getResultDetailErrorCode() const;
                MT_CTSTR getResultString();
                MT_CTSTR getResultDetailErrorCategoryString();
                via::module::http_patch::RequestType getRequestType() const;
                MT_CTSTR getRequestTypeString();
                s64 getFailedCount() const;
                f32 getProgressDLTotal() const;
                f32 getProgressDL1File() const;
                f32 getProgressFarExtract() const;
                void setDLRetryParams(s32 Prm_LSR, s32 Prm_Time, f32 Prm_Mbps, s32 Prm_Count);
                void setDLRetryParams(HTTPDL_RETRY_PARAMS* buff);
                void getDLRetryParams(HTTPDL_RETRY_PARAMS* buff);
                void restoreIPAddressHistory(u32* ipal);
                void storeDLRetryStatus(HTTPDL_RETRY_STATUS* buff);
                void getDLRetryStatus(HTTPDL_RETRY_STATUS* buff);
                f32 getDLSpeedMbps();
                void setDLSpeedMbps(f32 spd);
                MT_CHAR* getDLFilePath();
                MT_CHAR* getDLFileName();
                void setDLFilePath(MT_CHAR* fn);
                MT_CHAR* getInsFilePath();
                MT_CHAR* getInsFileName();
                void setInsFilePath(MT_CHAR* fn);
                MT_CHAR* getErrFileURL();
                MT_CHAR* getErrFilePath();
                MT_CHAR* getErrFileName();
                void setErrFilePath(MT_CHAR* fn);
            private:
                void clearDLRetryStatus();
            protected:
                void startDownloadPerfCounter();
                void pauseDownloadPerfCounter();
                void resumeDownloadPerfCounter();
                void endDownloadPerfCounter();
                bool isDownloadPerfCounterRuning();
                void startReadyPerfCounter();
                void endReadyPerfCounter();
                void startTotalPerfCounter();
                void endTotalPerfCounter();
                void setPhase(via::module::http_patch::Phase phase);
                void setResult(via::module::http_patch::Result result);
                void setResultDetail(HPDErrCategory ecType, s32 errCode);
                void setProgressDLTotal(f32);
                void setProgressDL1File(f32 per);
                void setProgressFarExtract(f32 per);
                void setRequestType(via::module::http_patch::RequestType type);
                void setFailedCount(s64 num);
                void setFilePath(MT_CHAR* src, RBPathData* dst);
            public:
                via::module::http_patch::ResultBase& operator=(via::module::http_patch::ResultBase);
            private:
                via::module::http_patch::Phase mPhase;  // offset: 0x8
                via::module::http_patch::Result mResult;  // offset: 0xc
                HPDErrCategory mEcType;  // offset: 0x10
                s32 mErCode;  // offset: 0x14
                f32 mPerDLTotal;  // offset: 0x18
                f32 mPerDL1File;  // offset: 0x1c
                f32 mPerFarExtract;  // offset: 0x20
                f32 mDLSpeedUR;  // offset: 0x24
                HTTPDL_RETRY_INFO mRetryInfo;  // offset: 0x28
                via::module::http_patch::RequestType mRequestType;  // offset: 0x88
                s64 mFailedCount;  // offset: 0x90
                bool mDownloadPCRunning;  // offset: 0x98
                s32 mDownloadPCstack;  // offset: 0x9c
                MtPerformanceTimer mDownloadPC;  // offset: 0xa0
                MtPerformanceTimer mReadyPC;  // offset: 0xc0
                MtPerformanceTimer mTotalPC;  // offset: 0xe0
                via::module::http_patch::CnvEnumToStr toMoji;  // offset: 0x100
                RBPathData mErrFPath;  // offset: 0x104
                RBPathData mErrF_URL;  // offset: 0x184
                RBPathData mDwnFPath;  // offset: 0x204
                RBPathData mInsFPath;  // offset: 0x284
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            class VersionResult : public via::module::http_patch::ResultBase
            {
            public:
                VersionResult();
                virtual ~VersionResult();
                bool isUpdate() const;
                virtual f64 getProgress() const;  // vtable slot 2
                virtual u64 getCheckLength() const;  // vtable slot 3
                virtual u64 getCheckCount() const;  // vtable slot 4
                s32 getAppVersion() const;
                s32 getAppMajorVersion() const;
                s32 getAppMinorVersion() const;
                s32 getAppSubMinorVersion() const;
                s32 getServerVersion() const;
                s32 getServerVersionNo(u32) const;
                size_t getServerVersionCount() const;
                s32 getServerMajorVersion() const;
                s32 getServerMinorVersion() const;
                s32 getServerSubMinorVersion() const;
                static s32 calcMajor(const s32);
                static s32 calcMinor(const s32);
                static s32 calcSubMinor(const s32);
                static s32 calcVersion(const u32, const u32, const u32);
            private:
                void incCheckCount();
                void setCheckCount(u64);
                void setCheckLength(u64);
                void setAppVersion(s32 vi);
                void setVersionList(const via::module::http_patch::versioninfo_array_t& list);
                const via::module::http_patch::versioninfo_array_t& getVersionList() const;
                void remakeVersionList(const u32 force_matched_ver);
            private:
                via::module::http_patch::VersionInfo mAppVersion;  // offset: 0x304
                u64 mCheckLength;  // offset: 0x308
                u64 mCheckCount;  // offset: 0x310
                via::module::http_patch::versioninfo_array_t mVersionList;  // offset: 0x318
                static const u32 DIGIT_SUBMINOR_VERSION_MASK = 255;
                static const u32 DIGIT_MINOR_VERSION_MASK = 65535;
                static const u32 DIGIT_MAJOR_VERSION_MASK = 255;
                static const u32 DIGIT_SUBMINOR_VERSION_SHIFT = 0;
                static const u32 DIGIT_MINOR_VERSION_SHIFT = 8;
                static const u32 DIGIT_MAJOR_VERSION_SHIFT = 24;
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            class ExeVersionResult : public via::module::http_patch::ResultBase
            {
            public:
                ExeVersionResult();
                virtual ~ExeVersionResult();
                virtual f64 getProgress() const;  // vtable slot 2
                u32 getServerVersionLauncher() const;
                u32 getServerVersionGameApp() const;
                u32 getDefineVersionLauncher() const;
                u32 getDefineVersionGameApp() const;
                bool isMatch() const;
                bool isMatchLauncher() const;
                bool isMatchGameApp() const;
            private:
                void setServerVersionLauncher(u32 version);
                void setServerVersionGameApp(u32 version);
                void setDefineVersionLauncher(u32 version);
                void setDefineVersionGameApp(u32 version);
            public:
                const via::module::http_patch::exefileinfo_array_t& getExeFileInfo() const;
            private:
                void setExeFileInfo(const via::module::http_patch::exefileinfo_array_t& info);
            private:
                u32 mServerVersionLauncher;  // offset: 0x304
                u32 mServerVersionGameApp;  // offset: 0x308
                u32 mDefineVersionLauncher;  // offset: 0x30c
                u32 mDefineVersionGameApp;  // offset: 0x310
                via::module::http_patch::exefileinfo_array_t mExeFileInfo;  // offset: 0x318
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

inline u32 via::module::http_patch::ExeVersionResult::getServerVersionLauncher() const {
    return this->mServerVersionLauncher;
}

inline u32 via::module::http_patch::ExeVersionResult::getServerVersionGameApp() const {
    return this->mServerVersionGameApp;
}

inline void via::module::http_patch::ExeVersionResult::setServerVersionLauncher(u32 version) {
    this->mServerVersionLauncher = version;
}

inline void via::module::http_patch::ExeVersionResult::setServerVersionGameApp(u32 version) {
    this->mServerVersionGameApp = version;
}

inline void via::module::http_patch::ResultBase::setResultDetail(HPDErrCategory ecType, s32 errCode) {
    this->mEcType = ecType;
    this->mErCode = errCode;
}

inline void via::module::http_patch::ResultBase::setProgressDL1File(f32 per) {
    this->mPerDL1File = per;
}

inline void via::module::http_patch::ResultBase::setProgressFarExtract(f32 per) {
    this->mPerFarExtract = per;
}

inline void via::module::http_patch::ResultBase::setRequestType(via::module::http_patch::RequestType type) {
    this->mRequestType = type;
}

inline void via::module::http_patch::ResultBase::endTotalPerfCounter() {
    this->mTotalPC.::MtPerformanceTimer::end();
}

inline s32 via::module::http_patch::VersionResult::getAppVersion() const {
    return this->mAppVersion.normal_version;
}

inline void via::module::http_patch::VersionResult::setAppVersion(s32 vi) {
    this->mAppVersion.normal_version = vi;
}
