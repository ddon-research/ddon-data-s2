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
class rDDOModelMontageEm;

// Declarations
class cpEmMontageCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpEmMontageCtrl : public cpComponent
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
    cpEmMontageCtrl();
    virtual ~cpEmMontageCtrl();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    void seqPartsOff();
    void setEmMontage(rDDOModelMontageEm* pRes);
    rDDOModelMontageEm* getEmMontage();
    void setDisableMotSeq(bool flag);
    bool isDisableMotSeq();
private:
    rDDOModelMontageEm* mpEmMontage;  // offset: 0x50
    bool mDisableMotSeq;  // offset: 0x58
public:
    static MyDTI DTI;
};

inline void* cpEmMontageCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rDDOModelMontageEm* cpEmMontageCtrl::getEmMontage() {
    return this->mpEmMontage;
}
