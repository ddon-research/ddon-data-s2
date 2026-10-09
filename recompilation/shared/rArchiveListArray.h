#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"
#include "rArchiveListTag.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
class cArchiveListNode;
class cArchiveListTag;

// Declarations
class rArchiveListArray;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_SEARCHID = u32;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;

class rArchiveListArray : public cResource
{
public:
    enum
    {
        DATA_VERSION = 11,
        SPLIT_NUM = 128,
        SPLIT_MASK = 127,
        HEADER_SIZE = 16,
    };
public:
    class MyDTI;
    struct stHeader;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stHeader
    {
    public:
        u32 Version;  // offset: 0x0
        u32 MagicNo;  // offset: 0x4
        u32 ConvHash;  // offset: 0x8
        u16 TagNum;  // offset: 0xc
        u16 TargetTagNo;  // offset: 0xe
        cArchiveListTag Tag[1];  // offset: 0x10
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
    rArchiveListArray();
    virtual ~rArchiveListArray();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    cArchiveListTag* searchListTag(u32 tagId);
    cArchiveListNode* searchListNode(u32 tagId, u32 searchId);
    static ARC_SEARCHID convSearchId(MT_CTSTR name);
    static ARC_TAGID convTagId(MT_CTSTR name);
    static ARC_TAGID convTagIdCore(MT_CTSTR name);
    static u32 convTargetTagtNo(u32 tagId);
    static u32 convTargetTagtNo(MT_CTSTR altFile);
    void allocMem(u32 size);
    void freeMem();
protected:
    stHeader* mpHeader;  // offset: 0x70
    cArchiveListNode::stDbgResData* mpDbgResDat;  // offset: 0x78
public:
    static MyDTI DTI;
};
