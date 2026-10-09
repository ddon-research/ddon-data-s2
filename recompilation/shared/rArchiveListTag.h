#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtDTI;

// Declarations
class cArchiveListNode;
class cArchiveListTag;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __uint64_t = long unsigned int;
using u32 = unsigned int;
using u64 = __uint64_t;

class cArchiveListNode
{
public:
    struct stDbgResData;
public:
    struct stDbgResData
    {
    public:
        const MtDTI* mpDTI;  // offset: 0x0
        MT_CHAR* mpPath;  // offset: 0x8
    };
public:
    void clear();
    u32 getTagId() const;
    const MtDTI* getDti() const;
    MT_CTSTR getPath() const;
public:
    u32 mSearchId;  // offset: 0x0
    u32 mTagId;  // offset: 0x4
    u64 mResId;  // offset: 0x8
    stDbgResData* mpDbgResData;  // offset: 0x10
};

class cArchiveListTag
{
public:
    void clear();
    cArchiveListNode* searchListNode(u32 searchId);
public:
    const MT_CHAR* mpArcPath;  // offset: 0x0
    u32 mTagId;  // offset: 0x8
    u32 mGroup;  // offset: 0xc
    u32 mType;  // offset: 0x10
    u32 mNodeNum;  // offset: 0x14
    cArchiveListNode* mpNodeArray;  // offset: 0x18
};
