#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;

// Declarations
class cJobMasterCtrl;
class rJobMasterCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cJobMasterCtrl : public MtObject
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
    cJobMasterCtrl();
    // Address: 0x01a95f20 - 0x01a95f21 (1 bytes)
    virtual ~cJobMasterCtrl() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mJobId;  // offset: 0x8
    u32 mStartJobLevel;  // offset: 0xc
    u32 mFirstTalkGrpSerial;  // offset: 0x10
    u32 mTraningTalkGrpSerial;  // offset: 0x14
    u32 mFirstOrderTalkGrpSerial;  // offset: 0x18
    u32 mJobTutorialQuestId;  // offset: 0x1c
    u32 mJobMasterTutorialQuestId;  // offset: 0x20
    u32 mAreaId;  // offset: 0x24
    u32 mAreaRank;  // offset: 0x28
    static MyDTI DTI;
};

class rJobMasterCtrl : public rTbl2<cJobMasterCtrl>
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
    rJobMasterCtrl();
    virtual ~rJobMasterCtrl();
    virtual bool loadData(MtDataReader& r, cJobMasterCtrl* pData);  // vtable slot 16
    virtual bool saveData(MtDataWriter& w, cJobMasterCtrl* pData);  // vtable slot 22
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
private:
    static const u32 DATA_VERSION;
};

// Inline, no code of its own: checked where it is inlined.
inline cJobMasterCtrl::cJobMasterCtrl() {
    this->mAreaRank = static_cast<u32>(0);
    this->mJobMasterTutorialQuestId = static_cast<u32>(0);
    this->mAreaId = static_cast<u32>(0);
    this->mFirstOrderTalkGrpSerial = static_cast<u32>(0);
    this->mJobTutorialQuestId = static_cast<u32>(0);
    this->mFirstTalkGrpSerial = static_cast<u32>(0);
    this->mTraningTalkGrpSerial = static_cast<u32>(0);
    this->mJobId = static_cast<u32>(0);
    this->mStartJobLevel = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rJobMasterCtrl::rJobMasterCtrl() {
}
