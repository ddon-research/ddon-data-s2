// Reconstructed from the game's DWARF debug information.
#include <new>
#include "httpPatchFileCtrl.h"
#include "HttpPatchManager.h"
#include "../../../../../MT/MtAllocator.h"
#include "../../../../../MT/MtCollisionUtil.h"
#include "../../../../../MT/MtDTI.h"
#include "../../../../../MT/MtFile.h"
#include "../../../../../MT/MtMemory.h"
#include "../../../../../MT/MtMemoryAllocator.h"
#include "../../../../../MT/MtObject.h"
#include "../../../../../MT/MtStream.h"
#include "../../../../../MT/MtString.h"
#include "../../../../../MT/MtSynchronize.h"
#include "../../../../../MT/MtThread.h"
#include "../../xvia/atomic.h"
#include "../../../../../generated/shared/directory.h"
#include "utility/hash.h"
#include "httpPatch.h"
#include "../network/networkHttpDownloadManager.h"
#include "../../xvia/path.h"
#include "utility/requestQueue.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

via::module::http_patch::FileControlManager::~FileControlManager() {
    DDON_STUB("via::module::http_patch::FileControlManager::~FileControlManager")
    /* stub */
}

__attribute__((weak)) via::module::http_patch::FileController* via::module::http_patch::FileControlManager::getFileControlPtr(size_t task_index) {
    DDON_STUB("via::module::http_patch::FileControlManager::getFileControlPtr")
    return nullptr;
}

const MtDTI& via::module::http_patch::FileController::getDTI() const {
    return via::module::http_patch::FileController::DTI;
}

__attribute__((noinline)) via::module::http_patch::FileController::~FileController() {
    DDON_STUB("via::module::http_patch::FileController::~FileController")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::reauestCommand() {
    DDON_STUB("via::module::http_patch::FileController::reauestCommand")
    /* stub */
}

__attribute__((weak)) via::module::http_patch::FileController::controller_t* via::module::http_patch::FileController::createCommand(const via::module::http_patch::FileController::controller_t* link_ptr) {
    DDON_STUB("via::module::http_patch::FileController::createCommand")
    return nullptr;
}

__attribute__((weak)) void via::module::http_patch::FileController::reauestCommand(MT_CTSTR path, size_t max_filesize, const u32 fileoptionalattr) {
    DDON_STUB("via::module::http_patch::FileController::reauestCommand")
    /* stub */
}

__attribute__((weak)) via::module::http_patch::FileController::controller_t* via::module::http_patch::FileController::createCommand(MT_CTSTR path, size_t max_filesize, const u32 fileoptionalattr, const via::module::http_patch::FileController::controller_t* link_ptr) {
    DDON_STUB("via::module::http_patch::FileController::createCommand")
    return nullptr;
}

__attribute__((weak)) void via::module::http_patch::FileController::reauestCommand(const void* src_buffer, size_t src_size) {
    DDON_STUB("via::module::http_patch::FileController::reauestCommand")
    /* stub */
}

__attribute__((weak)) via::module::http_patch::FileController::controller_t* via::module::http_patch::FileController::createCommand(const void* src_buffer, size_t src_size, const via::module::http_patch::FileController::controller_t* link_ptr) {
    DDON_STUB("via::module::http_patch::FileController::createCommand")
    return nullptr;
}

__attribute__((weak)) void via::module::http_patch::FileController::reauestCommand(MT_CTSTR src_path, MT_CTSTR dest_path, const size_t copy_size, bool append, bool gdata) {
    DDON_STUB("via::module::http_patch::FileController::reauestCommand")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::reauestCommand(MT_CTSTR remove_name) {
    DDON_STUB("via::module::http_patch::FileController::reauestCommand")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::reauestCommand(via::module::http_patch::FileController::UserCommandValueCallback function, void* this_ptr, const s64 value) {
    DDON_STUB("via::module::http_patch::FileController::reauestCommand")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::getTempBlockBuffer(void* & ptr, size_t& size) {
    DDON_STUB("via::module::http_patch::FileController::getTempBlockBuffer")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::returnTempBlockBuffer(const void* ptr) {
    DDON_STUB("via::module::http_patch::FileController::returnTempBlockBuffer")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::getPathBlockBuffer(MT_STR& ptr) {
    DDON_STUB("via::module::http_patch::FileController::getPathBlockBuffer")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::returnPathBlockBuffer(MT_CTSTR ptr) {
    DDON_STUB("via::module::http_patch::FileController::returnPathBlockBuffer")
    /* stub */
}

__attribute__((weak)) bool via::module::http_patch::FileController::fileOpen(const via::module::http_patch::FileController::CmdOpen& cmd) {
    DDON_STUB("via::module::http_patch::FileController::fileOpen")
    return {};
}

__attribute__((weak)) void via::module::http_patch::FileController::fileWrite(const via::module::http_patch::FileController::CmdWrite& cmd) {
    DDON_STUB("via::module::http_patch::FileController::fileWrite")
    /* stub */
}

__attribute__((weak)) bool via::module::http_patch::FileController::fileCopy(const via::module::http_patch::FileController::CmdCopy& cmd) {
    DDON_STUB("via::module::http_patch::FileController::fileCopy")
    return {};
}

__attribute__((weak)) bool via::module::http_patch::FileController::fileRename(const via::module::http_patch::FileController::CmdRename& cmd) {
    DDON_STUB("via::module::http_patch::FileController::fileRename")
    return {};
}

__attribute__((weak)) bool via::module::http_patch::FileController::fileHash(const via::module::http_patch::FileController::CmdHash& cmd) {
    DDON_STUB("via::module::http_patch::FileController::fileHash")
    return {};
}

__attribute__((weak)) bool via::module::http_patch::FileController::fileExtract(const via::module::http_patch::FileController::CmdExtract& cmd) {
    DDON_STUB("via::module::http_patch::FileController::fileExtract")
    return {};
}

__attribute__((weak)) bool via::module::http_patch::FileController::_fileExtract_addnew(MtFileStream& rfs, via::module::http_patch::FileController::FILE_ARCHIVE* pfa, MtString src_file, MtString dst_folder) {
    DDON_STUB("via::module::http_patch::FileController::_fileExtract_addnew")
    return {};
}

__attribute__((weak)) bool via::module::http_patch::FileController::_fileExtract_patch_type_00(MtFileStream& rfs, via::module::http_patch::FileController::FILE_ARCHIVE* pfa, MtString src_file, MtString dst_folder) {
    DDON_STUB("via::module::http_patch::FileController::_fileExtract_patch_type_00")
    return {};
}

__attribute__((weak)) bool via::module::http_patch::FileController::_fileExtract_patch_type_SLDIC(MtFileStream& rfs, via::module::http_patch::FileController::FILE_ARCHIVE* pfa, MtString src_file, MtString dst_folder) {
    DDON_STUB("via::module::http_patch::FileController::_fileExtract_patch_type_SLDIC")
    return {};
}

__attribute__((weak)) void via::module::http_patch::FileController::fileCopy(MT_CTSTR src_path, MT_CTSTR file_name, const size_t file_size, bool gdata) {
    DDON_STUB("via::module::http_patch::FileController::fileCopy")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::fileAppend(MT_CTSTR src_path, MT_CTSTR file_name, const size_t append_size) {
    DDON_STUB("via::module::http_patch::FileController::fileAppend")
    /* stub */
}

__attribute__((weak)) void via::module::http_patch::FileController::executeCommand(void* param) {
    DDON_STUB("via::module::http_patch::FileController::executeCommand")
    /* stub */
}

__attribute__((weak)) via::module::http_patch::FileController::controller_t& via::module::http_patch::FileController::getRequestLink() {
    DDON_STUB("via::module::http_patch::FileController::getRequestLink")
    __builtin_unreachable();
}

__attribute__((weak)) void via::module::http_patch::FileController::setRequestLinkNext(const via::module::http_patch::FileController::controller_t& controller_ptr) {
    DDON_STUB("via::module::http_patch::FileController::setRequestLinkNext")
    /* stub */
}

inline via::module::http_patch::FileController::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

via::module::http_patch::FileController::MyDTI via::module::http_patch::FileController::DTI("FileController", &::MtObject::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* via::module::http_patch::FileController::MyDTI::newInstance() const {
    DDON_STUB("via::module::http_patch::FileController::MyDTI::newInstance")
    return nullptr;
}

