#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../MT/MtDTI.h"
#include "../../../../../MT/MtObject.h"
#include "../../../../../MT/MtSynchronize.h"
#include "../../../../../MT/MtThread.h"
#include "utility/hash.h"
#include "httpPatch.h"
#include "utility/requestQueue.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtFile;
class MtFileStream;
class MtString;
namespace via { class Request; }
namespace via { namespace module { namespace http_patch { class ParallelsFileData; } } }

// Declarations
namespace via { namespace module { namespace http_patch { class FileControlManager; } } }
namespace via { namespace module { namespace http_patch { class FileController; } } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using SceUID = int;
using _Sizet = long unsigned int;
using __int64_t = long int;
using httpdl_array_pc8 = MtCollisionUtil::MtArrayTemplateEx<char*, false, 1>;
using httpdl_array_pvoid = MtCollisionUtil::MtArrayTemplateEx<void*, false, 1>;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;
namespace via { using sha256hash_t = via::hash<via::HashType_SHA256>::value_type; }

namespace via {
    namespace module {
        namespace http_patch {
            class FileControlManager
            {
            public:
                FileControlManager(u32 access_thread_count, u32 controller_num, u32 requestqueue_size, u32 block_size);
                ~FileControlManager();
                via::module::http_patch::FileController* getFileControlPtr(size_t task_index);
                size_t getRequestCount();
                bool isBlockFileIOQueue();
                u32 getFileControlCount();
            private:
                via::module::http_patch::FileController& getFileControl(size_t task_index);
            public:
                const via::module::http_patch::FileControlManager& operator=(const via::module::http_patch::FileControlManager&);
            private:
                const s32 MaxAccessThreadCount;  // offset: 0x0
                const u32 MaxFileController;  // offset: 0x4
                const u32 FileIORequestQueueSize;  // offset: 0x8
                const u32 FileIOBlockSize;  // offset: 0xc
                via::module::http_patch::FileController* * mFileControlPtr;  // offset: 0x10
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

namespace via {
    namespace module {
        namespace http_patch {
            class FileController : public ::MtObject
            {
            public:
                enum Command
                {
                    Command_None = 0,
                    Command_Open = 1,
                    Command_Close = 2,
                    Command_Write = 3,
                    Command_Copy = 4,
                    Command_Rename = 5,
                    Command_Remove = 6,
                    Command_UserCmdPtr = 7,
                    Command_UserCmdStr = 8,
                    Command_UserCmdValue = 9,
                    Command_User = 10,
                    Command_Hash = 11,
                    Command_Extract = 12,
                };
                enum PatchCommand
                {
                    PatchCommand_None = 0,
                    PatchCommand_Size = 1,
                    PatchCommand_Data_s2s = 2,
                    PatchCommand_Data_p2s = 3,
                    PatchCommand_Max = -1,
                };
            public:
                template <typename T> struct LinkList;
                class MyDTI;
                struct Controller;
                struct Failed;
                struct CmdOpen;
                struct CmdWrite;
                struct CmdClose;
                struct CmdCopy;
                struct CmdRename;
                struct CmdRemove;
                struct CmdUser;
                struct CmdHash;
                struct CmdExtract;
                struct FILE_ARCHIVE;
                struct PATCH_ARCHIVE_HDR;
                struct PATCH_ARCHIVE_PATH;
                struct PATCH_COMMAND;
                struct PatchCmdSize;
                struct PatchCmdHead;
                struct ARCHIVE_HDR;
                struct PatchCmdInfo;
                struct PatchCmdData;
                struct FILE_ARCHIVE_HEADER;
            public:
                using controller_t = via::module::http_patch::FileController::LinkList<via::module::http_patch::FileController::Controller>;
                using UserCommandValueCallback = void(*)(void*, const s64);
                using UserCommandStrCallback = void(*)(void*, MT_CTSTR);
                using UserCommandPtrCallback = void(*)(void*, const void*);
                using UserCommandCallback = void(*)(void*);
                using blockbuffer_t = httpdl_array_pvoid;
                using pathbuffer_t = httpdl_array_pc8;
                using failed_t = via::module::http_patch::FileController::Failed;
            public:
                class MyDTI : public ::MtDTI
                {
                public:
                    MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
                    virtual MtObject* newInstance() const;  // vtable slot 2
                };
            public:
                struct Failed
                {
                public:
                    via::module::http_patch::FileController::UserCommandValueCallback function;  // offset: 0x0
                    s64 size;  // offset: 0x8
                    void* this_ptr;  // offset: 0x10
                    const via::module::http_patch::ParallelsFileData* data_ptr;  // offset: 0x18
                };
            public:
                struct CmdOpen
                {
                public:
                    MtFile* hfile_ptr;  // offset: 0x0
                    MtFileStream* hfilestream_ptr;  // offset: 0x8
                    MT_STR path;  // offset: 0x10
                    size_t file_size;  // offset: 0x18
                    u32 fileoptionalattr;  // offset: 0x20
                };
            public:
                struct CmdWrite
                {
                public:
                    MtFile* hfile_ptr;  // offset: 0x0
                    MtFileStream* hfilestream_ptr;  // offset: 0x8
                    const void* buffer_ptr;  // offset: 0x10
                    size_t write_size;  // offset: 0x18
                };
            public:
                struct CmdClose
                {
                public:
                    MtFile* hfile_ptr;  // offset: 0x0
                    MtFileStream* hfilestream_ptr;  // offset: 0x8
                };
            public:
                struct CmdCopy
                {
                public:
                    MT_STR src_path;  // offset: 0x0
                    MT_STR dest_path;  // offset: 0x8
                    size_t copy_size;  // offset: 0x10
                    bool append;  // offset: 0x18
                    bool gdata;  // offset: 0x19
                };
            public:
                struct CmdRename
                {
                public:
                    MT_STR src_path;  // offset: 0x0
                    MT_STR dest_path;  // offset: 0x8
                };
            public:
                struct CmdRemove
                {
                public:
                    MT_STR src_path;  // offset: 0x0
                };
            public:
                struct CmdUser
                {
                public:
                    void* this_ptr;  // offset: 0x0
                    union
                    {
                    public:
                        struct
                        {
                        public:
                            via::module::http_patch::FileController::UserCommandStrCallback function;  // offset: 0x0
                            MT_STR path;  // offset: 0x8
                        } str;  // offset: 0x0
                        struct
                        {
                        public:
                            via::module::http_patch::FileController::UserCommandPtrCallback function;  // offset: 0x0
                            const void* data_ptr;  // offset: 0x8
                        } ptr;  // offset: 0x0
                        struct
                        {
                        public:
                            via::module::http_patch::FileController::UserCommandValueCallback function;  // offset: 0x0
                            size_t value;  // offset: 0x8
                        } value;  // offset: 0x0
                        struct
                        {
                        public:
                            via::module::http_patch::FileController::UserCommandCallback function;  // offset: 0x0
                        } none;  // offset: 0x0
                    };  // offset: 0x8
                };
            public:
                struct CmdHash
                {
                public:
                    MT_STR src_path;  // offset: 0x0
                    size_t file_size;  // offset: 0x8
                    via::sha256hash_t serverhash;  // offset: 0x10
                    bool direct;  // offset: 0x30
                    via::sha256hash_t directhash;  // offset: 0x31
                };
            public:
                struct CmdExtract
                {
                public:
                    MT_STR src_path;  // offset: 0x0
                };
            public:
                struct FILE_ARCHIVE
                {
                public:
                    MT_CHAR path[128];  // offset: 0x0
                    u32 type;  // offset: 0x80
                    u32 datasize;  // offset: 0x84
                    u32 orgsize : 29;  // offset: 0x88
                    u32 quality : 3;  // offset: 0x88
                    u32 offset;  // offset: 0x8c
                };
            public:
                struct PATCH_ARCHIVE_HDR
                {
                public:
                    union
                    {
                    public:
                        u32 magic;  // offset: 0x0
                        u8 mg[4];  // offset: 0x0
                    };  // offset: 0x0
                    u16 version;  // offset: 0x4
                    u16 command_num;  // offset: 0x6
                };
            public:
                struct PATCH_ARCHIVE_PATH
                {
                public:
                    MT_CHAR path[128];  // offset: 0x0
                };
            public:
                struct PatchCmdSize
                {
                public:
                    u32 size;  // offset: 0x0
                    u32 dmy[2];  // offset: 0x4
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
                struct PatchCmdInfo
                {
                public:
                    u32 num;  // offset: 0x0
                    u32 dmy[2];  // offset: 0x4
                };
            public:
                struct PatchCmdData
                {
                public:
                    u32 offset_src;  // offset: 0x0
                    u32 offset_dst;  // offset: 0x4
                    u32 size;  // offset: 0x8
                };
            public:
                struct FILE_ARCHIVE_HEADER
                {
                public:
                    u32 magic;  // offset: 0x0
                    u16 version;  // offset: 0x4
                    u16 resource_num;  // offset: 0x6
                };
            public:
                template <typename T>
                struct LinkList
                {
                public:
                    via::module::http_patch::FileController::LinkList<T>* next_ptr;  // offset: 0x0
                    T value;  // offset: 0x8
                };
            public:
                struct Controller
                {
                public:
                    via::module::http_patch::FileController::Command cmd;  // offset: 0x0
                    via::module::http_patch::FileController::Failed failed;  // offset: 0x8
                    union
                    {
                    public:
                        via::module::http_patch::FileController::CmdOpen open;  // offset: 0x0
                        via::module::http_patch::FileController::CmdWrite write;  // offset: 0x0
                        via::module::http_patch::FileController::CmdClose close;  // offset: 0x0
                        via::module::http_patch::FileController::CmdCopy copy;  // offset: 0x0
                        via::module::http_patch::FileController::CmdRename rename;  // offset: 0x0
                        via::module::http_patch::FileController::CmdRemove remove;  // offset: 0x0
                        via::module::http_patch::FileController::CmdUser user;  // offset: 0x0
                        via::module::http_patch::FileController::CmdHash hash;  // offset: 0x0
                        via::module::http_patch::FileController::CmdExtract extract;  // offset: 0x0
                    };  // offset: 0x28
                    const via::module::http_patch::FileController::LinkList<via::module::http_patch::FileController::Controller>* link_ptr;  // offset: 0x80
                };
            public:
                struct PatchCmdHead
                {
                public:
                    via::module::http_patch::FileController::ARCHIVE_HDR ah;  // offset: 0x0
                    u32 dmy[1];  // offset: 0x8
                };
            public:
                struct PATCH_COMMAND
                {
                public:
                    via::module::http_patch::FileController::PatchCommand cmd;  // offset: 0x0
                    union
                    {
                    public:
                        via::module::http_patch::FileController::PatchCmdSize size;  // offset: 0x0
                        via::module::http_patch::FileController::PatchCmdHead head;  // offset: 0x0
                        via::module::http_patch::FileController::PatchCmdInfo info;  // offset: 0x0
                        via::module::http_patch::FileController::PatchCmdData data;  // offset: 0x0
                    };  // offset: 0x4
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
                FileController(u32 access_thread_count, u32 requestqueue_size, u32 block_size, MT_CTSTR semaphore_name);
                virtual ~FileController();
                u32 getRequestCount() const;
                void reauestCommand();
                controller_t* createCommand(const controller_t* link_ptr);
                void reauestCommand(MT_CTSTR path, size_t max_filesize, const u32 fileoptionalattr);
                controller_t* createCommand(MT_CTSTR path, size_t max_filesize, const u32 fileoptionalattr, const controller_t* link_ptr);
                void reauestCommand(const void* src_buffer, size_t src_size);
                controller_t* createCommand(const void* src_buffer, size_t src_size, const controller_t* link_ptr);
                void reauestCommand(MT_CTSTR src_path, MT_CTSTR dest_path, const size_t copy_size, bool append, bool gdata);
                controller_t* createCommand(MT_CTSTR src_path, MT_CTSTR dest_path, const size_t copy_size, bool append, bool gdata, const controller_t* link_ptr);
                void reauestCommand(MT_CTSTR old_name, MT_CTSTR new_name);
                controller_t* createCommand(MT_CTSTR old_name, MT_CTSTR new_name, const controller_t* link_ptr);
                void reauestCommand(MT_CTSTR remove_name);
                controller_t* createCommand(MT_CTSTR remove_name, const controller_t* link_ptr);
                void reauestCommand(MT_CTSTR src_path, const via::sha256hash_t& server_hash, const size_t file_size, bool direct, const via::sha256hash_t& direct_hash);
                controller_t* createCommand(MT_CTSTR src_path, const via::sha256hash_t& server_hash, const size_t file_size, bool direct, const via::sha256hash_t& direct_hash, const controller_t* link_ptr);
                void reauestCommandExtract(MT_CTSTR src_path);
                controller_t* createCommandExtract(MT_CTSTR src_path, const controller_t* link_ptr);
                void reauestCommand(UserCommandStrCallback function, void* this_ptr, MT_CTSTR str_ptr);
                void reauestCommand(UserCommandPtrCallback function, void* this_ptr, const void* data_ptr);
                void reauestCommand(UserCommandValueCallback function, void* this_ptr, const s64 value);
                void reauestCommand(UserCommandCallback function, void* this_ptr);
                controller_t* createCommand(UserCommandStrCallback function, void* this_ptr, MT_CTSTR str_ptr, const controller_t* link_ptr);
                controller_t* createCommand(UserCommandPtrCallback function, void* this_ptr, const void* data_ptr, const controller_t* link_ptr);
                controller_t* createCommand(UserCommandValueCallback function, void* this_ptr, const s64 value, const controller_t* link_ptr);
                controller_t* createCommand(UserCommandCallback function, void* this_ptr, const controller_t* link_ptr);
                void reauestCommand(const controller_t* link_ptr);
                void immediateCloseAndRemoveCommand(MT_CTSTR path);
                void getTempBlockBuffer(void* & ptr, size_t& size);
                void returnTempBlockBuffer(const void* ptr);
                void getPathBlockBuffer(MT_STR& ptr);
                void returnPathBlockBuffer(MT_CTSTR ptr);
                bool isBlockFileIOQueue() const;
            private:
                bool fileOpen(const CmdOpen& cmd);
                void fileWrite(const CmdWrite& cmd);
                void fileClose(const CmdClose& cmd);
                bool fileCopy(const CmdCopy& cmd);
                bool fileRename(const CmdRename& cmd);
                void fileRemove(const CmdRemove& cmd);
                bool fileHash(const CmdHash& cmd);
                bool fileExtract(const CmdExtract& cmd);
                void fileUser(const Command cmd_type, const CmdUser& cmd);
                bool _fileExtract_addnew(MtFileStream& rfs, FILE_ARCHIVE* pfa, MtString src_file, MtString dst_folder);
                bool _fileExtract_patch_type_00(MtFileStream& rfs, FILE_ARCHIVE* pfa, MtString src_file, MtString dst_folder);
                bool _fileExtract_patch_type_SLDIC(MtFileStream& rfs, FILE_ARCHIVE* pfa, MtString src_file, MtString dst_folder);
                void fileCopy(MT_CTSTR src_path, MT_CTSTR file_name, const size_t file_size, bool gdata);
                void fileAppend(MT_CTSTR src_path, MT_CTSTR file_name, const size_t append_size);
                void executeCommand(void* param);
                s32 getIndex();
                MtFile* getFileHandle();
                MtFileStream* getFileStreamHandle();
                controller_t& getRequestLink();
                void setRequestLink(const controller_t& controller_ptr);
                void setRequestLinkNext(const controller_t& controller_ptr);
                const controller_t& getExecuteLink();
                void setExecuteLink(const controller_t& controller_ptr);
                const via::module::http_patch::FileController& operator=(const via::module::http_patch::FileController&);
            private:
                const u32 MaxAccessThreadCount;  // offset: 0x8
                const u32 FileIORequestQueueSize;  // offset: 0xc
                const u32 FileIOBlockSize;  // offset: 0x10
                u8* mBufferPtr;  // offset: 0x18
                MT_STR mPathBufferPtr;  // offset: 0x20
                s32 mRequestCount;  // offset: 0x28
                s32 mExecuteCount;  // offset: 0x2c
                controller_t* mReqestLinkListTop;  // offset: 0x30
                controller_t* mReqestLinkListBottom;  // offset: 0x38
                controller_t* mExecuteLinkListTop;  // offset: 0x40
                controller_t* mExecuteLinkListBottom;  // offset: 0x48
                controller_t* mQueuePtr;  // offset: 0x50
                MtFile* mhFilePtr;  // offset: 0x58
                MtFileStream* mhFileStreamPtr;  // offset: 0x60
                MtThread::ID* mThreadIDS;  // offset: 0x68
            public:
                s32 mAccessThreadCount;  // offset: 0x70
            private:
                via::Request mRequestCtrl;  // offset: 0x78
                MtCriticalSection mGetRequestMutex;  // offset: 0xe0
                MtCriticalSection mRequestMutex;  // offset: 0xe8
                MtCriticalSection mExecuteMutex;  // offset: 0xf0
                MtCriticalSection mTempBlockBufferMutex;  // offset: 0xf8
                MtCriticalSection mPathBlockBufferMutex;  // offset: 0x100
                bool mBlockFileIOQueue;  // offset: 0x108
                blockbuffer_t mTempBlockBufferList;  // offset: 0x110
                pathbuffer_t mPathBlockBufferList;  // offset: 0x130
            public:
                static MyDTI DTI;
                static const size_t VariableLengthFile = 0;
            };
        }  // namespace http_patch
    }  // namespace module
}  // namespace via

inline void* via::module::http_patch::FileController::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../../../../MT/MtAllocator.h"
#include "../../../../../MT/MtMemoryAllocator.h"

inline void via::module::http_patch::FileController::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::via::module::http_patch::FileController::DTI)->memFree(p_addr);
}
