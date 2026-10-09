#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class rBitTable;

// Declarations
class cBitCtrl;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using BitData = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cBitCtrl : public MtObject
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
    cBitCtrl();
    virtual ~cBitCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    BitData getBitDataFromRes(u32 index) const;
    u32 getBitCommandFromRes(u32 index) const;
    BitData getBitDataOrFromRes(u32 indexA, u32 indexB) const;
    BitData getBitDataAndFromRes(u32 indexA, u32 indexB) const;
    BitData getBitDataFromResMaskOr(u32 index, BitData mask) const;
    BitData getBitDataFromResMaskAnd(u32 index, BitData mask) const;
    BitData getBitData() const;
    void setBitData(BitData data);
    BitData setBitDataWithRes(u32 index);
    BitData changeBitDataMaskOr(BitData mask);
    BitData changeBitDataMaskAnd(BitData mask);
    BitData changeBitDataMaskCut(BitData mask);
    BitData changeBitDataWithResOr(u32 index);
    BitData changeBitDataWithResAnd(u32 index);
    BitData changeBitDataWithResCut(u32 index);
    u32 bitToIdx(BitData bdat);
    BitData doBitCommand(u32 index, u32 commandSet);
    void copyCurrentBitDataToOld();
    BitData getBitDataOld();
    void setResource(rBitTable* pRes);
    rBitTable* getResource() const;
private:
    BitData mCurrentBitData;  // offset: 0x8
    BitData mOldBitData;  // offset: 0x10
    rBitTable* mpBitTableRes;  // offset: 0x18
public:
    static MyDTI DTI;
};
