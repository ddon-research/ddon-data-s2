#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cEfcHandle.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cEfcHandle;
class cpSequenceCtrl;

// Declarations
class cpEfcSequenceGeneral;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cpEfcSequenceGeneral : public cpComponent
{
public:
    struct SEQ_LINK_TBL;
    class MyDTI;
public:
    struct SEQ_LINK_TBL
    {
    public:
        u32 SeqGeneralBit;  // offset: 0x0
        u32 EfcType;  // offset: 0x4
    };
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
    cpEfcSequenceGeneral();
    virtual ~cpEfcSequenceGeneral();
    virtual void updateEfcHandle();  // vtable slot 10
    void callbackSequenceTrigger(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work);
    void callbackSequenceRelease(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work);
    void callbackSetMotion(u32 blend, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);
private:
    MtTypedArray<cEfcHandle> mEfcHandle[2];  // offset: 0x50
public:
    static const u32 EFC_SEQ_GENERAL_NUM = 2;
    static const SEQ_LINK_TBL LINK_TBL[2];
    static MyDTI DTI;
};

inline void* cpEfcSequenceGeneral::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpEfcSequenceGeneral::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpEfcSequenceGeneral::DTI);
}

inline void cpEfcSequenceGeneral::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpEfcSequenceGeneral::DTI)->memFree(p_addr);
}
