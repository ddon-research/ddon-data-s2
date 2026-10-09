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
class MtObject;
class MtPropertyList;

// Declarations
class cPartsCtrlTable;
class rPartsCtrlTable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cPartsCtrlTable : public MtObject
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
    cPartsCtrlTable();
    // Address: 0x01aaaef0 - 0x01aaaef1 (1 bytes)
    virtual ~cPartsCtrlTable() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool isPartsDisp(u32 no) const;
    void setPartsDisp(bool disp, u32 no);
    u32 getPartsNum();
    void setPartsNum(u32);
public:
    s32 mPartsKeyNo;  // offset: 0x8
    u32 mPartsDisp[16];  // offset: 0xc
    static MyDTI DTI;
    static const u16 DATA_VERSION = 256;
};

class rPartsCtrlTable : public rTbl2<cPartsCtrlTable>
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
    virtual bool loadData(MtDataReader& in, cPartsCtrlTable* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cPartsCtrlTable::cPartsCtrlTable() {
    this->mPartsDisp[14] = static_cast<unsigned int>(0);
    this->mPartsDisp[15] = static_cast<unsigned int>(0);
    this->mPartsDisp[12] = static_cast<unsigned int>(0);
    this->mPartsDisp[13] = static_cast<unsigned int>(0);
    this->mPartsDisp[10] = static_cast<unsigned int>(0);
    this->mPartsDisp[11] = static_cast<unsigned int>(0);
    this->mPartsDisp[8] = static_cast<unsigned int>(0);
    this->mPartsDisp[9] = static_cast<unsigned int>(0);
    this->mPartsDisp[6] = static_cast<unsigned int>(0);
    this->mPartsDisp[7] = static_cast<unsigned int>(0);
    this->mPartsDisp[4] = static_cast<unsigned int>(0);
    this->mPartsDisp[5] = static_cast<unsigned int>(0);
    this->mPartsDisp[2] = static_cast<unsigned int>(0);
    this->mPartsDisp[3] = static_cast<unsigned int>(0);
    this->mPartsDisp[0] = static_cast<unsigned int>(0);
    this->mPartsDisp[1] = static_cast<unsigned int>(0);
    this->mPartsKeyNo = static_cast<s32>(-1);
}
