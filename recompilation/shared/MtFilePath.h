#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtFilePath;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using u32 = unsigned int;

class MtFilePath
{
public:
    MtFilePath(MT_CTSTR path);
    MtFilePath(MT_CTSTR current, MT_CTSTR path);
    ~MtFilePath();
    MT_CTSTR getFullPath();
    MT_CTSTR getDir();
    MT_CTSTR getDrive();
    MT_CTSTR getFileTitle();
    MT_CTSTR getFileName();
    MT_CTSTR getExt();
    MT_CTSTR getRelative(MT_CTSTR current);
    static bool isRelativePath(MT_CTSTR path);
    static void normalize(MT_STR path);
protected:
    void splitPath(MT_CTSTR path);
protected:
    MT_CHAR mFullPath[1024];  // offset: 0x0
    MT_CHAR mDir[1024];  // offset: 0x400
    MT_CHAR mDrive[32];  // offset: 0x800
    MT_CHAR mFileName[256];  // offset: 0x820
    MT_CHAR mFileTitle[256];  // offset: 0x920
    MT_CHAR mExt[256];  // offset: 0xa20
public:
    static const u32 MAX_DIR = 1024;
    static const u32 MAX_EXT = 256;
    static const u32 MAX_FNAME = 256;
    static const u32 MAX_DRIVE = 32;
};
