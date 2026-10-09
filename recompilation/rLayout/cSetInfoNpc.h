#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "cFSMRelate.h"
#include "cSetInfoCharacter.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtString;
class cFSMRelate;
class cSetInfo;
class cUnit;

// Declarations
class cSetInfoNpc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cSetInfoNpc : public cSetInfoCharacter
{
public:
    class MyDTI;
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
    cSetInfoNpc();
    virtual ~cSetInfoNpc();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual void copy(cSetInfo* p);  // vtable slot 11
    s32 getNpcId() const;
    void setNpcId(s32);
public:
    s32 mNpcId;  // offset: 0x44
    MtString mFilePath;  // offset: 0x48
    cFSMRelate mFsmResource;  // offset: 0x50
    bool mIsCommunicate;  // offset: 0x68
    u8 mClothType;  // offset: 0x69
    s8 mDefNPCMotCategory;  // offset: 0x6a
    s8 mDefNPCMotNo;  // offset: 0x6b
    u8 mLantern;  // offset: 0x6c
    u16 mThinkIndex;  // offset: 0x6e
    u16 mJobLv;  // offset: 0x70
    bool mDisableScrAdj;  // offset: 0x72
    bool mDisableLedgerFinger;  // offset: 0x73
    bool mIsForceListTalk;  // offset: 0x74
    bool mIsAttand;  // offset: 0x75
    bool mDisableTouchAction;  // offset: 0x76
    bool mDispElseQuestTalk;  // offset: 0x77
    static MyDTI DTI;
};
