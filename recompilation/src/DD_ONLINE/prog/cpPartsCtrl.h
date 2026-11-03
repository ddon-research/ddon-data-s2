#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cBitCtrl;
class cPartsCtrlTable;
class rBitTable;
class rPartsCtrlTable;
class uDDOModel;

// Declarations
class cpPartsCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cpPartsCtrl : public cpComponent
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
    cpPartsCtrl();
    virtual ~cpPartsCtrl();
    virtual void setup();  // vtable slot 6
    void before();
    void update();
    virtual void updatePtr();  // vtable slot 9
    uDDOModel* getDDOModel() const;
    void changePartsBit(u32 index, u32 commandSet);
    void setPartsBit(u64 data);
    void setBitTableRes(rBitTable* pRes);
    rBitTable* getBitTableRes() const;
    void setPartsCrtlTableRes(rPartsCtrlTable* pRes);
    rPartsCtrlTable* getPartsCrtlTableRes() const;
    cBitCtrl* getBitCtrl();
private:
    cPartsCtrlTable* findPartsDataFromKey(s32 key) const;
private:
    uDDOModel* mpModel;  // offset: 0x50
    cBitCtrl* mpBitCtrl;  // offset: 0x58
    rPartsCtrlTable* mpPartsCrtlTableRes;  // offset: 0x60
public:
    static MyDTI DTI;
};

inline void* cpPartsCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cBitCtrl* cpPartsCtrl::getBitCtrl() {
    return this->mpBitCtrl;
}
