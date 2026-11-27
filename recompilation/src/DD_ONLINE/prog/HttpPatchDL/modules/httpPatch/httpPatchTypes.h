#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../MT/MtDTI.h"
#include "../../../../../MT/MtObject.h"
#include "../../../../../MT/MtString.h"
#include "utility/hash.h"
#include "httpPatch.h"

// Forward declarations
class MtAllocator;
class MtDTI;

namespace via {
namespace module {
namespace http_patch {
    enum PacketSaveType
    {
        PacketSaveType_None = 0,
        PacketSaveType_Temp = 1,
        PacketSaveType_DownloadFromTemp = 2,
        PacketSaveType_Download = 3,
        PacketSaveType_Memory = 4,
        PacketSaveType_MAX = 5,
    };
}  // namespace http_patch
}  // namespace module
}  // namespace via

namespace via {
namespace module {
namespace http_patch {
    enum Phase
    {
        Phase_None = 0,
        Phase_PushRequest = 1,
        Phase_PopRequest = 2,
        Phase_Request_DL_VersionList = 3,
        Phase_Request_DL_FullList = 4,
        Phase_Request_DL_PurgeList = 5,
        Phase_Request_FileList = 6,
        Phase_Wait_DL_VersionList = 7,
        Phase_Wait_DL_FullList = 8,
        Phase_Wait_DL_PurgeList = 9,
        Phase_Wait_FileList = 10,
        Phase_Request_CalcVersion = 11,
        Phase_Wait_CalcVersion = 12,
        Phase_Cheack_Version = 13,
        Phase_DownLoadedFileInfoLoad = 14,
        Phase_Request_File = 15,
        Phase_Wait_File = 16,
        Phase_Wait_FileCommand = 17,
        Phase_Wait_SaveVersion = 18,
        Phase_DetailedCheck_FileSearch = 19,
        Phase_DetailedCheck_CalcVersion = 20,
        Phase_DetailedCheck_CalcVersionEnd = 21,
        Phase_DetailedCheck_MakeVersionFileList = 22,
        Phase_DetailedCheck_MakeDownloadFileList = 23,
        Phase_DetailedCheck_MakeDownloadFileListEnd = 24,
        Phase_DetailedCheck_RemoveFile = 25,
        Phase_DetailedCheck_RequestDownloadFile = 26,
        Phase_DetailedCheck_RequestDownloadFileEnd = 27,
        Phase_BootList_FileSearch = 28,
        Phase_BootList_CalcHash = 29,
        Phase_BootList_CheckHash = 30,
        Phase_Finish = 31,
        Phase_Failed = 32,
        Phase_MAX = 33,
    };
}  // namespace http_patch
}  // namespace module
}  // namespace via

namespace via {
namespace module {
namespace http_patch {
    enum RequestType
    {
        RequestType_None = 0,
        RequestType_ExeVersion = 1,
        RequestType_ResVersion = 2,
        RequestType_NormalCheck = 2,
        RequestType_MAX = 3,
    };
}  // namespace http_patch
}  // namespace module
}  // namespace via

namespace via {
namespace module {
namespace http_patch {
    enum Result
    {
        Result_None = 0,
        Result_Abort = 1,
        Result_SuccessFinish = 2,
        Result_SuccessUpdateFinish = 3,
        Result_RebootRequire = 4,
        Result_ErrorRequest = 5,
        Result_ErrorVersionCheck = 6,
        Result_ErrorHDDVersion = 7,
        Result_ErrorVersionListDL = 8,
        Result_ErrorVersionListSize = 9,
        Result_ErrorFileListDL = 10,
        Result_ErrorFileListSize = 11,
        Result_ErrorFileDL = 12,
        Result_ErrorFreeSpaceFull = 13,
        Result_ErrorRetryCountOver = 14,
        Result_ErrorForceMatchedVer = 15,
        Result_ErrorBootList = 16,
        Result_ErrorPurgeList = 17,
        Result_ErrorFormat = 18,
        Result_MAX = 19,
    };
}  // namespace http_patch
}  // namespace module
}  // namespace via

// Declarations
namespace via { namespace module { namespace http_patch { class CnvEnumToStr; } } }
namespace via { namespace module { namespace http_patch { struct ExeFileInfo; } } }
namespace via { namespace module { namespace http_patch { class ParallelsFileData; } } }
namespace via { namespace module { namespace http_patch { struct SucceedFileInfo; } } }
namespace via { namespace module { namespace http_patch { struct VersionInfo; } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
namespace via { using sha256hash_t = via::hash<via::HashType_SHA256>::value_type; }

namespace via {
    namespace module {
        namespace http_patch {
            class CnvEnumToStr
            {
            public:
                CnvEnumToStr();
                ~CnvEnumToStr();
                MT_CTSTR getPhaseString(via::module::http_patch::Phase ix);
                MT_CTSTR getResultString(via::module::http_patch::Result ix);
                MT_CTSTR getResultDetailErrorCategoryString(HPDErrCategory ix);
                MT_CTSTR getRequestTypeString(via::module::http_patch::RequestType ix);
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            struct ExeFileInfo
            {
            public:
                u32 ver;  // offset: 0x0
                MtStringEx<64> name;  // offset: 0x4
                size_t size;  // offset: 0x48
                u8 binary_hash[32];  // offset: 0x50
                u32 attr;  // offset: 0x70
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            class ParallelsFileData : public ::MtObject
            {
            public:
                class MyDTI;
            public:
                class MyDTI : public ::MtDTI
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
                ParallelsFileData();
                ParallelsFileData(const via::module::http_patch::ParallelsFileData&);
                const via::module::http_patch::ParallelsFileData& operator=(const via::module::http_patch::ParallelsFileData& param);
            private:
                void copy(const via::module::http_patch::ParallelsFileData& param);
            public:
                u32 no;  // offset: 0x8
                u32 file_version;  // offset: 0xc
                u64 hash;  // offset: 0x10
                size_t file_size;  // offset: 0x18
                via::sha256hash_t binary_hash;  // offset: 0x20
                u32 attribute;  // offset: 0x40
                MtStringEx<128> name;  // offset: 0x44
                MtStringEx<128> path;  // offset: 0xc8
                MtStringEx<32> split_file;  // offset: 0x14c
                bool redownload;  // offset: 0x170
                bool boot;  // offset: 0x171
                static MyDTI DTI;
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            struct SucceedFileInfo
            {
            public:
                u32 file_version;  // offset: 0x0
                u64 hash;  // offset: 0x8
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            struct VersionInfo
            {
            public:
                s32 normal_version;  // offset: 0x0
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

inline via::module::http_patch::CnvEnumToStr::CnvEnumToStr() {
}

inline void* via::module::http_patch::ParallelsFileData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../../../../MT/MtMemoryAllocator.h"

inline MtAllocator* via::module::http_patch::ParallelsFileData::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::via::module::http_patch::ParallelsFileData::DTI);
}
